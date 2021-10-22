#
# BMW PAGe - Python AUTOSAR Generator
#
# \project     BMW Platform Software
#
# \copyright   BMW AG 2017
#
# \version     1.1.0
#
import logging
import re
import json
import sys
import traceback
import time
from collections import namedtuple
from copy import deepcopy
from .pgenfile import File
from .exceptions import *

Line = namedtuple('Line', ['text', 'indentchange', 'inhibitlinemarker', 'linenrincrement'])

class InputPart:
    '''
    Abstract description of an input piece.
    '''

    @classmethod
    def create(cls, input, logger=None, **kwargs):
        return cls(input, logger, **kwargs)

    @classmethod
    def split_text(cls, text):
        '''Split a line without consuming the splitting element(\\n)'''
        s = re.split('(\n)', text)
        return [ ''.join(s[i:i+2]) for i in range(0, len(s), 2) ]

    def __init__(self, string, logger=None, **kwargs):
        self.line = string
        self.logger = logger or logging.getLogger(__name__)
        self.startline = kwargs['startline']
        self.filename = kwargs['filename']
        self.lines = []

    def split_lines(self):
        return self.split_text(self.line)

    def __len__(self):
        return len(self.lines)

    def __getitem__(self, index):
        if index > len(self):
            return IndexError
        return self.lines[index]

    def contains(self, string):
        return string in self.__str__()

    @property
    def silent(self):
        '''This part will surely have no output if this propery is True'''
        return False

    def setpos(self, module):
        '''
        Update the position where this element is located
        '''
        module.page_current_file = self.filename
        module.page_current_line = self.startline

    def render(self, module):
        '''
        Interface for rendering function.
        Render must return the content which is effectivly contained in the part.
        '''
        raise NotImplementedError()



class CodePart(InputPart):
    ''' Generic code like part

    Use the class method 'create' to create a specific subclass dependent on the marker
    '''
    marker_regex = re.compile('^\s*(?P<marker>[#@:=+?~])[ \t]*(?P<content>.*)?',re.DOTALL)
    @classmethod
    def create(cls, input, logger=None, **kwargs):
        ''' Create a specific code part based on the first character of the input'''
        marker, part = cls.get_code_elements(input, kwargs['startline'])
        classes = {
            '=':CodePartOutput,
            '#':CodePartCode,
            ':':CodePartCondition,
            '@':CodePartLoop,
            '+':CodePartInclude,
            '?':CodePartShortIf,
            '~':CodePartVariantLoop
        }
        part = cls._fix_indentiation(part)
        return classes[marker](part, logger=logger, **kwargs)

    @classmethod
    def get_code_elements(cls, part, startline):
        '''Split the code in a marker and the real input part'''
        marker_match = cls.marker_regex.match(part)
        if not marker_match:
            raise ValueError('marker did not match ({0}) line: {1}'.format(part,startline))
        '''remove only spaces and tabs, no newlines to keep proper line counting'''
        return (marker_match.group('marker'), marker_match.group('content'))

    @classmethod
    def _fix_indentiation(cls, text):
        lines = InputPart.split_text(text)
        #strip spaces from all lines, use first real code line as baseline
        try:
            referenceline = 0
            if lines[0] == '\n':
                referenceline = 1
            indentlen = len(lines[referenceline]) - len(lines[referenceline].lstrip(' '))
        except:
            indentlen = 0
        code = []
        for number, partline in enumerate(lines):
            code.append(partline[indentlen:])
        return ''.join(code)

    def __init__(self, input, logger, **kwargs):
        super().__init__(input, logger, **kwargs)
        self.nesting = False
        self.exit = False
        self.multipart = False
        self.filename = kwargs['filename']
        self.lineno = kwargs['startline']
        self.parts = []

    def _do_eval(self, code, module):
        return self._do_render('write({0})'.format(code), module)

    def _do_render(self, code, module):
        '''This renders a generic code element, and handles the common exceptions that may occur here.
        '''
        try:
            exec (code, module.__dict__)
            return ''.join(module._get_code())

        except SyntaxError as se:
            filename = self.filename
            lineno = self._get_line_no()
            line = self._get_code_line(code, lineno)
            exc = PageSyntaxException(text=line, filename=filename,
                                      lineno=lineno, offset=se.offset, inner=se)
            exc.with_traceback(None)
            self.logger.fatal(exc)
            raise exc from se

        except NameError as ne:
            lineno = self._get_line_no()
            originalline = self._get_code_line(code, lineno)
            exc = InvalidStatementException(text=originalline, info=ne.args[0], filename=self.filename,lineno=self.startline, inner=ne)
            self.logger.fatal(exc)
            exc.with_traceback(None)
            raise exc from ne

        except NoResultException as nre:
            lineno = self._get_line_no()
            nre.filename = self.filename
            nre.lineno = self.startline+max(0,lineno-1)
            nre.text = self._get_code_line(code, lineno)
            nre.with_traceback(None)
            self.logger.fatal(nre)
            raise nre from nre

        except Exception as e:
            lineno = self._get_line_no()
            line = self._get_code_line(code, lineno)
            originalline = lineno + self.startline
            import traceback
            traceback.print_stack()
            traceback.print_exc()
            exception = TemplateRuntimeError(filename=self.filename,
                                             block=type(self).__name__,
                                             lineno=originalline,
                                             text=line, exception=e,
                                             stacktrace='', inner=e)
            self.logger.fatal(exception)
            raise exception from e

    def _get_line_no(self):
        _, _, tb = sys.exc_info()
        tb_list = traceback.extract_tb(tb)
        try:
            tb_element = next(x for x in tb_list if x.filename == '<string>')
            lineno = tb_element.lineno
        except AttributeError:
            """This is for python previous 3.5"""
            tb_element = next(x for x in tb_list if x[0] == '<string>')
            lineno = tb_element[1]
        except:
            lineno = 0
        return lineno

    def _get_code_line(self, code, line):
        try:
            return code.split('\n')[max(0,line-1)]
        except IndexError:
            return code
        except:
            return '<NOT AVAILABLE>'

    def render(self, module):
        self.setpos(module)
        return self._do_render(self.code, module)


class CodePartOutput(CodePart):
    '''Code part for direct output
    The expression given is wrapped into the write function which is responsilbe for writing things into the output file
    '''
    def __init__(self, input, logger=None, **kwargs):
        super().__init__(input, logger, **kwargs)
        self.code = 'write({0})'.format(input.strip())


class CodePartCode(CodePart):
    '''Code part for manual code.
    The code part can contain any valid python code which will be executed in the context of the page template.
    '''
    def __init__(self, input, logger=None, **kwargs):
        super().__init__(input, logger, **kwargs)
        self.code = self.line

    def render(self, module):
        self.setpos(module)
        wcount = module.write_counter
        result = self._do_render(self.code, module)
        self._silent = (module.write_counter - wcount == 0)
        return result

    @property
    def silent(self):
        return self._silent

class CodePartShortIf(CodePart):
    shortif_regex = re.compile('(?!<\\\\):')
    def __init__(self, input, logger=None, **kwargs):
        super().__init__(input, logger, **kwargs)
        self.input_data = self.shortif_regex.split(input)
        self.condition = self.input_data[0]
        self.truetext = self.input_data[1]
        self.code = 'write("{truetext}" if {condition} else "'.format(condition=self.input_data[0], truetext=self.input_data[1])
        if len(self.input_data) == 3:
            self.falsetext = self.input_data[2]
            self.code += '{falsetext}'.format(falsetext=self.input_data[2])
        self.code += '")'

class CodePartCondition(CodePart):
    '''Code part for conditions.
    This allows to handle coditions inside the code so the user can have text blocks between start and end of conditions
    '''
    def __init__(self, input, logger=None, **kwargs):
        super().__init__(input, logger, **kwargs)
        inhibitlinemarker = False
        self.conditions = []
        self.condition = ''
        self.nesting = True
        self.parent = None
        input = input.strip()
        self.lines = [Line(input, False, False, 0)]
        self.code = ''
        if input == '':
            self.exit = True
            self.nesting = False
            return
        if input == 'else':
            self.exit = True
        else:
            self.condition = re.sub('^(el)?if[ \t]*', '', input)

        if input.startswith('el'):
            self.multipart = True
            self.exit = True
        if input.startswith('if'):
            self.conditions.append(self)

    def add(self, part):
        if type(part) != type(self):
            raise PageSyntaxException('Expected a conditional part')
        if self.parent:
            reference = self.parent
        else:
            reference = self
        part.parent = reference
        reference.conditions.append(part)

    def render(self, module):
        self.setpos(module)
        for cond in self.conditions:
            if (self._do_render('write('+cond.condition+')', module).lower() in ['1', 'true']) or not len(cond.condition):
                return ''.join(map(lambda x: x.render(module), cond.parts))
        return ''

    @property
    def silent(self):
        return True


class CodePartLoop(CodePart):
    '''Code part for loops over variables or xpath expressions.
    '''
    def __init__(self, input, logger=None, **kwargs):
        super().__init__(input, logger, **kwargs)
        input = input.strip()
        forloop = re.match('([_a-zA-Z][a-zA-Z0-9_]*(?:, *[_a-zA-Z][a-zA-Z0-9_]*)*) *in (.*)', input)
        self.input = input
        if forloop:
            self.name = forloop.group(1)
            if ',' in self.name:
                self.name = list(map(str.strip, self.name.split(',')))
            self.iterateable = forloop.group(2)
        else:
            self.xpath = input

    @property
    def nesting(self):
        return self.input != ''

    @nesting.setter
    def nesting(self, value):
        pass

    @property
    def exit(self):
        return self.input == ''

    @exit.setter
    def exit(self,value):
        pass

    def render(self, module):
        """Rendering for loop is done in another way"""
        self.setpos(module)
        if self.input == '':
            return ''
        result = []
        # make a deep copy of the current scope
        scope = module.current_scope[:]
        if hasattr(self,'xpath'):
            exec ('eval_result = ' + self.xpath, module.__dict__)
            xpath = module.__dict__['eval_result']
            elements = module.get_elements(xpath)
            for element in elements:
                module.current_scope = scope[:]
                module.into(element)
                result.append (''.join(map(lambda x: x.render(module), self.parts)))
                module.leave()
        else:
            self._do_render('_values = {0}'.format(self.iterateable), module)
            values = module._values
            for element in values:
                if type(self.name) is list:
                    try:
                        for name,value in zip(self.name, element):
                            setattr(module, name, value)
                    except TypeError:
                        raise ValueError('Element in loop {0} is not iterateable'.format(self.input))
                else:
                    setattr(module, self.name, element)
                result.append (''.join(map(lambda x: x.render(module), self.parts)))
        module.current_scope = scope[:]
        return ''.join(result)

    @property
    def silent(self):
        return True #all(map(lambda x: x.silent, self.startpart.parts)) if self.exit else True


class CodePartInclude(CodePart):
    '''Code part for includes.

    This allows to include a separate file to be included in place. Included files can be PAGe or Python files.
    '''
    def __init__(self, input, logger=None, **kwargs):
        super().__init__(input, logger, **kwargs)
        self.includefile = input.rstrip()
        self.logger.debug('include %s', self.includefile)
        self.include = File.create(self.includefile, includedfrom=(kwargs['filename'], kwargs['startline']))

    def render(self, module):
        self.setpos(module)
        try:
            if self.ispy:
                exec (self.include.text, module.__dict__)
                return ''.join(module._get_code())
            else:
                return self.include.render(module)
        except FileNotFoundError as e:
            self.logger.fatal('Included file not found: %s @ {0[0]}:{0[1]}'.format(self.include.includedfrom), self.includefile)
            raise IncludeFileNotFoundException(incfile=self.includefile,
                                               filename=self.include.includedfrom) from None
        except PageException as e:
            raise TemplateRuntimeError(inner=e, filename=self.filename,
                                             block=type(self).__name__,
                                             lineno=self.startline,
                                             text='', exception=e,
                                             stacktrace='')

    @property
    def ispy(self):
        return self.includefile.endswith('.py')

    @property
    def silent(self):
        return True

class CodePartVariantLoop(CodePart):
    '''Code part for VariantLoops

    This allows to iterate over all variants
    '''
    active = False
    def __init__(self, input, logger=None, **kwargs):
        super().__init__(input, logger, **kwargs)
        self.is_active = not CodePartVariantLoop.active
        CodePartVariantLoop.active = self.is_active

    @property
    def nesting(self):
        return self.is_active

    @nesting.setter
    def nesting(self, value):
        pass

    @property
    def exit(self):
        return not self.is_active

    @exit.setter
    def exit(self,value):
        pass

    def render(self, module):
        """Rendering for loop is done in another way"""
        self.setpos(module)
        if not self.is_active:
            return ''
        result = []
        scope_backup = module.current_scope[:]
        module.current_scope = [None]
        # find all postbuild variants in EcuC
        self.logger.info("Looping over PostBuildVariants")
        post_build_variants = module.value(module.ref('EcuC/EcucPostBuildVariants/EcucPostBuildVariantRef'))
        if isinstance(post_build_variants, str): post_build_variants = [post_build_variants]
        if post_build_variants is not None and len(post_build_variants) > 0:
            for pb_variant in post_build_variants:
                pv_value_name = module.xml_cache[pb_variant].shortname
                self.logger.info("PB Variant: {}".format(pv_value_name))
                module.xml_cache.apply_variant(module.xml_cache[pb_variant].configuration)
                module.predefined_variant_name = pv_value_name
                module.predefined_variant_postfix = '_'+pv_value_name
                result.append (''.join(map(lambda x: x.render(module), self.parts)))
            module.xml_cache.reset_variant()
        else:
            module.predefined_variant_name = 'None'
            module.predefined_variant_postfix = ''
            result.append (''.join(map(lambda x: x.render(module), self.parts)))
        del module.predefined_variant_name

        module.current_scope = scope_backup[:]
        return ''.join(result)

    @property
    def silent(self):
        return self.is_active


class TextPart(InputPart):
    def __init__(self, input, logger, **kwargs):
        self.content = []
        try:
            self.previous =  kwargs['previous']
        except KeyError:
            self.previous = None
        super().__init__(input, logger, **kwargs)
        for line in self.split_lines():
            if line.startswith('\\\n'):
                line = line[2:]
            if line != '':
                self.content.append(line)

    def render(self, module):
        if len(self.content) == 0:
            return ''
        firstline = self.content[0]
        if self.previous is not None and self.previous.silent:
            if len(self.content) > 0 and self.content[0].startswith('\n'):
                firstline = self.content[0][1:]
        return firstline+''.join(self.content[1:])
