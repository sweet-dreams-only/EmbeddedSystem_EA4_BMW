#
# BMW PAGe - Python AUTOSAR Generator
#
# \project     BMW Platform Software
#
# \copyright   BMW AG 2017
#
# \version     1.1.0
#
import xml.etree.ElementTree as ET
import functools
import sys
import itertools
import re
from collections import defaultdict, OrderedDict
from pprint import pprint
from .exceptions import NoResultException, PageException, XMLElementMissing, XMLParserError



class SearchExpression(object):
    '''Baseclass for searching for elements in the model.

    Each subclass represents a way to search for an element.'''

    def execute(self, root):
        '''Returns an array of the elements'''
        raise Exception('expression has no execute')

    @property
    def is_absolute(self):
        raise Exception('expression has no execute')

class SearchExpressionImpl(SearchExpression):
    '''Baseclass for searching for elements in the model.

    Each subclass represents a way to search for an element.'''

    def __init__(self, expression):
        self.expression = expression

    def is_global(self):
        self.expression = '/*/{}'.format(self.expression)
        return self

    @property
    def is_absolute(self):
        return self.expression.startswith('/')


class ref(SearchExpressionImpl):
    '''Get the elements in the model, which refere to the given shortnamepath as definition ref.'''

    def execute(self, root):
        return root.get_defref_to(self.expression)


class snpath(SearchExpressionImpl):
    '''Get the element at the given shortname path.'''

    def execute(self, root):
        try:
            return [root[self.expression]]
        except NoResultException:
            return []


class container(SearchExpressionImpl):
    '''Selects containers that refere to a given definition ref.'''

    def execute(self, root):
        return list(filter(lambda x: isinstance(x, AR_EcucContainerValue), root.get_defref_to(self.expression)))


class module(SearchExpressionImpl):
    '''Selects modules that refere to a given definition ref.'''

    def execute(self, root):
        return list(filter(lambda x: isinstance(x, AR_EcucModuleConfiguration), root.get_defref_to(self.expression)))

class AR_BaseRoot(object):
    '''Root element for a model instance'''

    def find(self, *args, **kwargs):
        pass


class AR_Condition(object):
    '''Condition for the variant handling'''

    def __init__(self, criterion, value):
        self.crit = criterion
        self.value = int(value)

    def __str__(self):
        return '{} == {}'.format(self.crit, self.value)

    __repr__ = __str__


class AR_Object(SearchExpression):
    '''Base for all objects representing an AUTOSAR model element.'''

    def __init__(self, element, parent=None, **kwargs):
        self.element = element
        self.parent = parent
        if parent is not None:
            self.root = parent.root
            self.is_root = False
        else:
            self.root = self
            self.is_root = True
        self.defref_index = OrderedDict()
        self.named_subs = OrderedDict()
        self.unnamed_subs = []
        self.sn_index = OrderedDict()
        for name, value in kwargs.items():
            if not hasattr(self, name):
                setattr(self, name, value)
        self._set_variation_points()
        self.definitionref = 'ROOT'
        self.shortname_path = '-'

    def _element_find(self, expr):
        return self.element.find(expr, self.namespaces)

    def _element_iterfind(self, expr):
        return self.element.iterfind(expr, self.namespaces)

    def _debug(self):
        print('\n'.join("{0}: {1}".format(*item)
                        for item in sorted(vars(self).items())))

    def _set_variation_points(self):
        '''configure the variation point for the parameter'''
        self._variation_conditions = {}
        variation_point = self._element_find('AR:VARIATION-POINT')
        if variation_point != None:
            for cond in variation_point.iterfind('AR:POST-BUILD-VARIANT-CONDITIONS/AR:POST-BUILD-VARIANT-CONDITION', namespaces=self.namespaces):
                crit = cond.find('AR:MATCHING-CRITERION-REF',
                                 namespaces=self.namespaces).text
                value = cond.find('AR:VALUE', namespaces=self.namespaces).text
                self._variation_conditions[crit] = AR_Condition(crit, value)

    def is_valid_for_variant(self):
        '''Check if this element is available at the active variant'''
        result = True
        for variant_crit in self.root.variant:
            if variant_crit.crit in self._variation_conditions:
                result = result and self._variation_conditions[
                    variant_crit.crit].value == variant_crit.value
        return result

    def has_variation_point(self):
        '''Check if this element has a variation point.'''
        return len(self._variation_conditions) > 0

    @property
    def is_absolute(self):
        return True

    def execute(self, root):
        '''Returns an array of the elements'''
        return [self]

    def add(self, elements):
        '''Adds subelements to the element.

        All elements added will be examined and kept either as a named subelement or unnamed.
        The definitionref is also kept as reference.
        '''
        if elements is None:
            return

        for p in elements:
            if hasattr(p, 'shortname'):
                if not p.shortname in self.named_subs:
                    self.named_subs[p.shortname] = p
                    self.root.sn_index[p.shortname_path] = p
                    relative_path = p.shortname_path[len(self.shortname_path):]
                    self.sn_index[relative_path] = p
                else:
                    self.named_subs[p.shortname].append(p)
            else:
                self.unnamed_subs.append(p)
            if hasattr(p, 'definitionref'):
                self._add_definitionref(p)

    def _add_definitionref(self, p):
        if not p.definitionref in self.defref_index:
            self.defref_index[p.definitionref] = []
        self.defref_index[p.definitionref].append(p)
        if not self.is_root:
            self.parent._add_definitionref(p)

    def append(self, container):
        self.add(container.named_subs.values())
        self.add(container.unnamed_subs)

    def get_all(self, etype=None):
        '''Get all elements in a flattened array.

        If etype is given it acts as filter for the element type.'''
        elements = []

        def by_type(x):
            if type(etype) is list:
                return type(x) in etype
            return etype == None or type(x) == etype
        if by_type(self):
            elements.append(self)
        if len(self.named_subs) > 0:
            elements.extend(filter(by_type, [item for sl in map(
                lambda x: x.get_all(etype), self.named_subs.values()) for item in sl]))
        if len(self.unnamed_subs) > 0:
            elements.extend(filter(by_type, [item for sl in map(
                lambda x: x.get_all(etype), self.unnamed_subs) for item in sl]))
        return elements

    @property
    def named_elements(self):
        '''All the named sub elements that are active in the current variant'''
        if self.root.variant is None:
            return self.named_subs
        else:
            return OrderedDict(filter(lambda x: x[1].is_valid_for_variant(), self.named_subs.items()))

    @property
    def unnamed_elements(self):
        '''All the unnamed sub elements that are active in the current variant'''
        if self.root.variant is None:
            return self.unnamed_subs
        else:
            return list(filter(lambda x: x.is_valid_for_variant(), self.unnamed_subs))

    @property
    def definitionref_index(self):
        '''All the definition refs that are active in the current variant'''
        if self.root.variant is None:
            return self.defref_index
        else:
            result = OrderedDict()
            for defref in self.defref_index:
                filtered_list = list(
                    filter(lambda x: x.is_valid_for_variant(), self.defref_index[defref]))
                if len(filtered_list) > 0:
                    result[defref] = filtered_list
            return result

    def __contains__(self, sn):
        '''Check if a certain shortname is contained in this element'''
        if sn.startswith('/'):
            if sn.startswith(self.shortname_path):
                sn = sn[len(self.shortname_path) + 1:]
            else:
                sn = sn[1:]
        if '/' in sn:
            current, rest = sn.split('/', 1)
            if current not in self.named_elements:
                return False
            return rest in self[current]
        if sn in self.named_elements:
            return True
        return False

    def __getitem__(self, sn):
        '''Get a sub elements by shortname'''
        if sn.endswith('/'):
            sn = sn[:-1]
        if '*' in sn:
            return self.search(sn)
        if '.' == sn:
            return self
        if '..' == sn:
            if self.root != self:
                return self.parent
            else:
                raise PageException('root node has no parent')
        if sn.startswith('/'):
            if sn.startswith(self.shortname_path):
                sn = sn[len(self.shortname_path) + 1:]
            elif self.root != self:
                return self.root[sn]
            else:
                sn = sn[1:]
        if '/' in sn:
            current, rest = sn.split('/', 1)
            return self[current][rest]
        if sn not in self.named_elements:
            raise NoResultException(sn)
        return self.named_elements[sn]

    def search(self, sn):
        '''Get a sub elements by search using a name'''
        if not sn.startswith('/'):
            sn = '*{}'.format(sn)
        sn = sn.replace('*', '.*')
        sn_re = re.compile(sn)

        def sn_match(p):
            return sn_re.match(p)
        result = list(filter(sn_match, self.named_elements))
        return result

    def get_defref_to(self, defref):
        '''Get a sub elements by definition ref'''
        if not defref.startswith('/'):
            defref = '*{}'.format(defref)
        # make a regex out of it
        defref = defref.replace('*', '.*')
        defref_re = re.compile(defref + '$')

        def defref_match(p):
            return defref_re.match(p[0])
        result = map(lambda x: x[1], filter(
            defref_match, self.definitionref_index.items()))
        return list(itertools.chain.from_iterable(result))

    def has_defref_to(self, defref):
        return len(self.get_defref_to(defref)) > 0

    def is_part_of(self, defref):
        return self.get_ancestor(defref) is not None

    def get_ancestor(self, defref):
        if self == self.root:
            return None
        match = re.match('^.*/{}$'.format(defref), self.definitionref)
        if match is not None:
            return self
        else:
            return self.parent.get_ancestor(defref)

    def get_ref(self, ref):
        '''Get all the items referenced'''
        result = []
        for e in self.unnamed_elements:
            if hasattr(e, 'definitionref'):
                if e.definitionref == ref:
                    result.append(e)
        for e in self.named_elements.values():
            result += e.get_ref(ref)
        return result


class AR_Root(AR_Object):
    '''The root of the model'''
    shortname = ''
    shortname_path = ''
    namespaces = {}

    def __init__(self, **kwargs):
        if not 'element' in kwargs:
            kwargs['element'] = AR_BaseRoot()
        super().__init__(**kwargs)
        self.variant = None
        self.variants = {}

    def apply_variant(self, configuration):
        self.variant = configuration

    def reset_variant(self):
        self.variant = None


class AR_Identifyable(AR_Object):
    '''Represents an AUTOSAR element which has a shortname assigned'''

    def __init__(self, **kwargs):
        super().__init__(**kwargs)
        self._resolve_shortname()
        self._set_shortname_path()

    def _resolve_shortname(self):
        shortname_element = self._element_find('AR:SHORT-NAME')
        self.shortname = shortname_element.text

    def __lt__(self, other):
        return self.shortname_path < other.shortname_path

    def __le__(self, other):
        return self.shortname_path <= other.shortname_path

    def __eq__(self, other):
        return self.shortname_path == other.shortname_path

    def __gt__(self, other):
        return self.shortname_path > other.shortname_path

    def __ge__(self, other):
        return self.shortname_path >= other.shortname_path

    def _set_shortname_path(self):
        path = []
        if not hasattr(self, '_shortname_path'):
            elem = self
            while elem is not None:
                path.append(elem.shortname)
                elem = elem.parent
        self.shortname_path = '/'.join(reversed(path))

    def __hash__(self):
        return hash(self.shortname_path)

    def __str__(self):
        return '{{{0}}} {1}'.format(type(self).__name__, self.shortname_path)


class AR_VariantCriterion(AR_Identifyable):
    '''Represents a criterion for post build variants'''

    def __init__(self, criterion, value, **kwargs):
        super().__init__(**kwargs)


class AR_VariantCriterionValueSet(AR_Identifyable):
    '''Represents a valueset for criterions'''

    def __init__(self, **kwargs):
        super().__init__(**kwargs)


class AR_VariantCriterionValue(AR_Object):
    '''Represents a value for a criterions'''

    def __init__(self, **kwargs):
        super().__init__(**kwargs)
        self._resolve_criterion()

    def __str__(self):
        return '{0} == {1}'.format(self.crit, self.value)

    __repr__ = __str__

    def _resolve_criterion(self):
        self.crit = self._element_find('AR:VARIANT-CRITERION-REF').text
        self.value = int(self._element_find('AR:VALUE').text)


class AR_PredefinedVariant(AR_Identifyable):
    '''A pre defined variant with specific values for criterions.

    It can be referenced by the ecuc configuration or other predefined variants as well.'''

    def __init__(self, **kwargs):
        super().__init__(**kwargs)
        self.variantsets = []
        self.includes = []
        self._getincludes()
        self._getsets()

    def _getsets(self):
        for element in self._element_iterfind('AR:POST-BUILD-VARIANT-CRITERION-VALUE-SET-REFS/AR:POST-BUILD-VARIANT-CRITERION-VALUE-SET-REF'):
            self.variantsets.append(element.text)

    def _getincludes(self):
        for inc in self._element_iterfind('AR:INCLUDED-VARIANT-REFS/AR:INCLUDED-VARIANT-REF'):
            self.includes.append(inc.text)

    @property
    def configuration(self):
        '''Generates a configuration of the variant to be used to set the variant'''
        configuration = []
        for vs in self.variantsets:
            pbvs = self.root[vs]
            for s in pbvs.unnamed_subs:
                configuration.append(s)
        for inc in self.includes:
            pdv = self.root[inc]
            configuration = configuration + pdv.configuration
        return configuration


class AR_ConfigValue(AR_Object):
    '''Base for configuration elements'''

    def __init__(self, **kwargs):
        super().__init__(**kwargs)
        self._resolve_definitionref()
        self.containers = {}
        self.shortname_path = self.parent.shortname_path

    def _resolve_definitionref(self):
        definitionref_element = self._element_find('AR:DEFINITION-REF')
        self.definitionref = definitionref_element.text
        self.destination = definitionref_element.attrib['DEST']

    def __lt__(self, other):
        return self.definitionref < other.definitionref

    def __le__(self, other):
        return self.definitionref <= other.definitionref

    def __eq__(self, other):
        return self.definitionref == other.definitionref

    def __gt__(self, other):
        return self.definitionref > other.definitionref

    def __ge__(self, other):
        return self.definitionref >= other.definitionref

    def __hash__(self):
        return hash(self.definitionref)

    def _get_child(self, name):
        child = self._element_find('AR:{}'.format(name))
        if child is  None:
            raise XMLElementMissing(self.__class__.__name__, name, self.shortname_path)
        return child


class AR_ConfigElement(AR_Identifyable, AR_ConfigValue):

    def __init__(self, **kwargs):
        AR_ConfigValue.__init__(self, **kwargs)
        AR_Identifyable.__init__(self, **kwargs)

    def __str__(self):
        return '{0} [>{1}]'.format(super().__str__(), self.definitionref)

    __repr__ = __str__


class AR_EcucModuleConfiguration(AR_ConfigElement):
    pass


class AR_DefinitionElement(AR_Object):
    pass


class AR_EcucConfig(AR_Object):
    pass


class CheckResult(object):
    '''Keeps a result and a set of messages which can be updated'''

    def __init__(self, result=True, info=None):
        self.result = result
        self.info = []
        if info is not None:
            self.info.extend(info)

    def update(self, check_result):
        '''Update the result with a boolean result or another result object'''
        if type(check_result) == bool:
            self.result = self.result and check_result
        else:
            self.result = self.result and check_result.result
            self.info.extend(check_result.info[:])

    def __bool__(self):
        return self.result


def _checkmessage(message):
    def _checkmessage_decorator(function):
        def wrapper(self, *args, **kwargs):
            result = function(self, *args, **kwargs)
            msg = []
            if not result:
                params = {'arg{}'.format(i): v for i, v in enumerate(args)}
                params.update(kwargs)
                params['self'] = self
                msg = [message.format(**params)]
            return CheckResult(result, msg)
        return wrapper
    return _checkmessage_decorator


class AR_EcucDefinition(AR_DefinitionElement, AR_Identifyable):
    '''Base of a definition of an EcucConfiguration element'''

    def __init__(self, **kwargs):
        AR_Identifyable.__init__(self, **kwargs)
        AR_DefinitionElement.__init__(self, **kwargs)
        self.post_build_variant = False
        self._set_multiplicity()
        self._set_valueconfig()

    def _set_multiplicity(self):
        l = self._element_find('AR:LOWER-MULTIPLICITY')
        self.lowerinfinite = self._element_find(
            'AR:LOWER-MULTIPLICITY-INFINITE') != None
        self.upperinfinite = self._element_find(
            'AR:UPPER-MULTIPLICITY-INFINITE') != None
        self.lower = None
        self.upper = None
        if l is not None:
            self.lower = int(l.text)
        else:
            self.lowerinfinite = True
        u = self._element_find('AR:UPPER-MULTIPLICITY')
        if u is not None:
            self.upper = int(u.text)
        else:
            self.upperinfinite = True

    def _set_valueconfig(self):
        self.value_config_classes = []
        for variant in self._element_iterfind('AR:ECUC-VALUE-CONFIGURATION-CLASS'):
            self.value_config_classes.append(variant.text)

    def _perform_check_all(self, functions, *args, **kwargs):
        result = CheckResult(True)
        for f in functions:
            result.update(f(*args, **kwargs))
        return result

    def _check(self, part=None):
        if part is None:
            part = self.root

        result = CheckResult(True)
        elements = part.get_defref_to(self.shortname_path)
        result.update(self._checkbounds(elements))
        result.update(self._checkvariation(elements))
        result.update(self._checkelements(elements))
        return result

    def _checkelements(self, elements):
        result = CheckResult(True)
        for element in elements:
            result.update(self._checkself(element))
            for n in self.named_elements.values():
                result.update(n._check(element))
        return result

    def _checkself(self, element):
        return CheckResult(True)

    @_checkmessage('{self.shortname} has variation point but is not a postbuild element')
    def _checkvariation(self, elements):
        return self.post_build_variant or not any(map(lambda x: x.has_variation_point(), elements))

    def _checkbounds(self, elements):
        count = len(elements) if type(elements) == list else 1
        result = CheckResult(True)
        result.update(self._checkbounds_lower(count))
        result.update(self._checkbounds_upper(count))
        return result

    @_checkmessage('{self.shortname} has lower count than {self.lower} < {arg0}')
    def _checkbounds_lower(self, count):
        return self.lowerinfinite or self.lower <= count

    @_checkmessage('{self.shortname} has higher count than {self.upper} < {arg0}')
    def _checkbounds_upper(self, count):
        return self.upperinfinite or self.upper >= count


class AR_EcucModuleDefinition(AR_EcucDefinition):
    '''Definition of a module configuration'''

    def __init__(self, **kwargs):
        super().__init__(**kwargs)
        self._set_postbuildsupport()

    def _set_postbuildsupport(self):
        pb_element = self._element_find('AR:POST-BUILD-VARIANT-SUPPORT')
        self.postbuild = pb_element is not None and pb_element.text.lower() in [
            '1', 'true']
        self.config_variants = []
        for variant in self._element_iterfind('AR:SUPPORTED-CONFIG-VARIANTS/AR:SUPPORTED-CONFIG-VARIANT'):
            self.config_variants.append(variant.text)

    def verify(self, logger):
        '''Verify a module'''
        logger.info('ModuleDefinition: {}'.format(self.shortname))
        variants = self.root.get_defref_to(
            'EcuC/EcucPostBuildVariants/EcucPostBuildVariantRef')
        result = CheckResult()
        if len(variants) > 0:
            for pb_variant in variants:
                var = self.root[pb_variant.value]
                logger.info("PB Variant: {}".format(var.shortname))
                self.root.apply_variant(var.configuration)
                partresult = self._check()
                if bool(partresult):
                    logger.info('PB Variant {} Result Successfull: {}'.format(
                        var.shortname, bool(partresult)))
                else:
                    logger.error('PB Variant {} Result Successfull: {}'.format(
                        var.shortname, bool(partresult)))
                for ve in partresult.info:
                    logger.error(ve)
                result.update(partresult)
        else:
            result = self._check()

        logger.info('Verification for {} completed.'.format(self.shortname))
        if bool(result):
            logger.info('Result Successfull: {}'.format(bool(result)))
        else:
            logger.error('Result Successfull: {}'.format(bool(result)))
        for ve in result.info:
            logger.error(ve)
        return bool(result)


class AR_EcucParameter(AR_EcucDefinition):
    '''Base for definition of a parameter definition'''

    def __init__(self, **kwargs):
        super().__init__(**kwargs)
        self._setdefault()
        self._set_pbinfo()

    def _setdefault(self):
        self.default = self._element_find('AR:DEFAULT-VALUE')

    def _set_pbinfo(self):
        pbvv = self._element_find('AR:POST-BUILD-VARIANT-VALUE')
        if pbvv is not None:
            self.post_build_variant = pbvv.text.lower() in ['1', 'true']

    def _checkself(self, element):
        return self._perform_check_all([
            self._checkself_range,
            self._checkself_length,
            self._checkself_regex], element)

    def _checkself_range(self, element):
        return True

    def _checkself_length(self, element):
        return True

    def _checkself_regex(self, element):
        return True


class AR_EcucParameterEnumeration(AR_EcucParameter):
    '''Definition of an enumeration parameter'''

    def __init__(self, **kwargs):
        super().__init__(**kwargs)
        self._setliterals()

    def _setliterals(self):
        self.literals = []
        for lit in self._element_iterfind('AR:LITERALS/AR:ECUC-ENUMERATION-LITERAL-DEF/AR:SHORT-NAME'):
            self.literals.append(lit.text)

    @_checkmessage('{self.shortname} has a value which is not part of the allowed literals')
    def _checkself_range(self, element):
        return element.value in self.literals


class AR_EcucParameterString(AR_EcucParameter):
    '''Definition of a string parameter'''

    def __init__(self, **kwargs):
        super().__init__(**kwargs)
        self._setrange()

    def _setrange(self):
        self.maxlength = self._element_find('AR:MAX-LENGTH')
        self.minlength = self._element_find('AR:MIN-LENGTH')
        self.regex = self._element_find('AR:REGULAR-EXPRESSION')

    @_checkmessage('{self.shortname} has lower not the correct length must be in {self.minlength} and {self.maxlength}')
    def _checkself_length(self, element):
        result = True
        if self.maxlength is not None:
            result = len(element.value) <= int(self.maxlength)
        if self.minlength is not None:
            result = result and len(element.value) >= int(self.minlength)
        return result

    @_checkmessage('{self.shortname} has does not match regex {self.regex}')
    def _checkself_regex(self, element):
        if self.regex is not None:
            return re.match(self.regex, element.value)
        return True


class AR_EcucParameterLinkerSymbol(AR_EcucParameterString):
    '''Definition of a linker symbol'''

    def __init__(self, **kwargs):
        super().__init__(**kwargs)
        self.regex = '[a-zA-Z_.$%][a-zA-Z_.$%0-9]*'


class AR_EcucParameterFunctionName(AR_EcucParameterString):
    '''Definition of a funciton name'''

    def __init__(self, **kwargs):
        super().__init__(**kwargs)


class AR_EcucParameterNumerical(AR_EcucParameter):
    '''Base of a numerical parameter'''

    def __init__(self, **kwargs):
        super().__init__(**kwargs)

    def _setrange(self):
        self.max = self._getbound(self._element_find('AR:MAX'))
        self.min = self._getbound(self._element_find('AR:MIN'))

    def _getbound(self, elem):
        if elem is None:
            return None
        return self.mytype(elem)

    @_checkmessage('{self.shortname} is not in range {self.min} and {self.max}')
    def _checkself_range(self, element):
        result = True
        if self.max is not None:
            result = self.type(element.value) <= self.max
        if self.min is not None:
            result = self.type(element.value) <= self.min and result
        return result


class AR_EcucParameterFloat(AR_EcucParameterNumerical):
    '''Definition of a float parameter'''

    def __init__(self, **kwargs):
        super().__init__(**kwargs)
        self.mytype = float
        self._setrange()


class AR_EcucParameterInteger(AR_EcucParameterNumerical):
    '''Definition of an integer parameter'''

    def __init__(self, **kwargs):
        super().__init__(**kwargs)
        self.mytype = int
        self._setrange()


class AR_EcucParameterBoolean(AR_EcucParameter):
    '''Definition of a boolean parameter'''

    def __init__(self, **kwargs):
        super().__init__(**kwargs)


class AR_EcucContainer(AR_EcucDefinition):
    '''Definition of a container'''

    def __init__(self, **kwargs):
        super().__init__(**kwargs)

    def _set_pbinfo(self):
        if self.min < self.max:
            pbvm = self._element_find('AR:POST-BUILD-VARIANT-MULTIPLICITY')
            if pbvm is not None:
                self.post_build_variant = pbvm.text.lower() in ['1', 'true']


class AR_EcucChoiceContainer(AR_EcucContainer):

    def __init__(self, **kwargs):
        super().__init__(**kwargs)

    def _checkself(self, element):
        result = CheckResult()
        result.update(self._checkcount(element))
        result.update(self._checkvalid(element))
        return CheckResult(len(element.named_elements))

    @_checkmessage('{self.shortname} (ChoiceContainer) has more than one subcontainer')
    def _checkcount(self, element):
        return len(element.named_elements) == 1

    @_checkmessage('{self.shortname} (ChoiceContainer) has invalid subcontainer')
    def _checkvalid(self, element):
        element = list(element.named_elements.values())[0]
        return element.definitionref in self


class AR_EcucContainerValue(AR_ConfigElement):

    def __init__(self, **kwargs):
        super().__init__(**kwargs)

    def append(self, container):
        self.add(container.named_subs.values())
        self.add(container.unnamed_subs)



class AR_EcucReference(AR_ConfigValue):

    def __init__(self, **kwargs):
        super().__init__(**kwargs)
        self._resolve_valueref()

    def _resolve_valueref(self):
        self.value = self._get_child('VALUE-REF').text

    def __str__(self):
        return '{}'.format(self.value)

    def __repr__(self):
        return '[>{0}] {1}'.format(self.definitionref, self.value)


class AR_EcucParameterValue(AR_ConfigValue):

    def __init__(self, **kwargs):
        super().__init__(**kwargs)
        self._resolve_value()

    def _resolve_value(self):
        self.value = self._get_child('VALUE').text
        self._cast()

    def _cast(self):
        destination = self.destination.lower()
        if 'boolean' in destination:
            self.value = '{0}'.format(self.value).lower() in ['true', '1']
        elif 'integer' in destination:
            self.value = int(self.value or 0)
        elif 'float' in destination:
            self.value = float(self.value or 0)
        else:
            self.value = str(self.value or '')

    def __str__(self):
        return '{}'.format(self.value)

    def __repr__(self):
        return '[>{0}] {1}'.format(self.definitionref, self.value)


class AR_Package(AR_Identifyable):

    def __init__(self, **kwargs):
        self.elements = {}
        super().__init__(**kwargs)

    __repr__ = AR_Identifyable.__str__


class ArxmlParser(object):

    def __init__(self, ar=None):
        if ar is None:
            ar = AR_Root()
        self.ar = ar
        pass

    def parse(self, filename):
        global namespaces
        try:
            tree = ET.parse(filename)
            root = tree.getroot()
            self.namespaces = {'AR': root.tag[1:root.tag.find('}')]}
            self.ar.namespaces = self.namespaces
            self._stack = [(root, self.ar)]
            self.current_filename = filename
            self.ar.add(self.parse_packages())
        except XMLParserError as e:
            raise XMLParserError(filename=filename, inner=e)

    def parse_x(self, path, etype, subparse=[]):
        elements = []
        if isinstance(path, str):
            path = [path]
        element, parent = self._stack[-1]
        for current in itertools.chain(*list(map(lambda x: element.iterfind(x, self.namespaces), path))):
            current_obj = etype(element=current, parent=parent,
                                filename=self.current_filename, namespaces=self.namespaces)
            self._stack.append((current, current_obj))
            for sub in subparse:
                current_obj.add(sub())
            elements.append(current_obj)
            self._stack.pop()
        return elements

    def parse_packages(self):
        return self.parse_x(
            'AR:AR-PACKAGES/AR:AR-PACKAGE',
            AR_Package,
            [self.parse_packages,
             self.parse_module_confs,
             self.parse_module_defs,
             self.parse_predefined_variants,
             self.parse_variant_criterion_value_set])

    def parse_parameters(self):
        return self.parse_x('AR:PARAMETER-VALUES/*', AR_EcucParameterValue)

    def parse_references(self):
        return self.parse_x('AR:REFERENCE-VALUES/AR:ECUC-REFERENCE-VALUE', AR_EcucReference)

    def parse_conf_containers(self):
        return self.parse_x(
            ['AR:CONTAINERS/AR:ECUC-CONTAINER-VALUE',
             'AR:SUB-CONTAINERS/AR:ECUC-CONTAINER-VALUE'],
            AR_EcucContainerValue,
            [self.parse_conf_containers,
             self.parse_parameters,
             self.parse_references])

    def parse_def_containers(self):
        return self.parse_x(
            ['AR:CONTAINERS/AR:ECUC-PARAM-CONF-CONTAINER-DEF',
             'AR:SUB-CONTAINERS/AR:ECUC-PARAM-CONF-CONTAINER-DEF',
             'AR:CHOICES/AR:ECUC-PARAM-CONF-CONTAINER-DEF'],
            AR_EcucContainer,
            [self.parse_def_containers,
             self.parse_def_parameters,
             self.parse_def_references])

    def parse_def_choice_containers(self):
        return self.parse_x(
            ['AR:CONTAINERS/AR:ECUC-CHOICE-CONTAINER-DEF',
             'AR:SUB-CONTAINERS/AR:ECUC-CHOICE-CONTAINER-DEF'],
            AR_EcucChoiceContainer,
            [self.parse_def_containers])

    def parse_def_parameters(self):
        params = []
        types = [
            ('ECUC-STRING-PARAM-DEF', AR_EcucParameterString),
            ('ECUC-FLOAT-PARAM-DEF', AR_EcucParameterFloat),
            ('ECUC-BOOLEAN-PARAM-DEF', AR_EcucParameterBoolean),
            ('ECUC-INTEGER-PARAM-DEF', AR_EcucParameterInteger),
            ('ECUC-ENUMERATION-PARAM-DEF', AR_EcucParameterEnumeration),
            ('ECUC-LINKER-SYMBOL-DEF', AR_EcucParameterLinkerSymbol),
            ('ECUC-FUNCTION-NAME-DEF', AR_EcucParameterFunctionName)
        ]
        for t in types:
            params.extend(self.parse_x( 'AR:PARAMETERS/AR:{}'.format(t[0]), t[1]))
        return params

    def parse_def_references(self):
        return self.parse_x('AR:REFERENCE-VALUES/AR:ECUC-REFERENCE-VALUE', AR_EcucReference)

    def parse_module_confs(self):
        return self.parse_x('AR:ELEMENTS/AR:ECUC-MODULE-CONFIGURATION-VALUES', AR_EcucModuleConfiguration, [self.parse_conf_containers])
        elements = []

    def parse_module_defs(self):
        return self.parse_x('AR:ELEMENTS/AR:ECUC-MODULE-DEF', AR_EcucModuleDefinition,
                            [self.parse_def_containers,
                             self.parse_def_choice_containers])

    def parse_variant_criterion_value(self):
        return self.parse_x('AR:POST-BUILD-VARIANT-CRITERION-VALUES/AR:POST-BUILD-VARIANT-CRITERION-VALUE', AR_VariantCriterionValue)

    def parse_variant_criterion_value_set(self):
        return self.parse_x('AR:ELEMENTS/AR:POST-BUILD-VARIANT-CRITERION-VALUE-SET', AR_VariantCriterionValueSet, [self.parse_variant_criterion_value])

    def parse_predefined_variants(self):
        return self.parse_x('AR:ELEMENTS/AR:PREDEFINED-VARIANT', AR_PredefinedVariant)
