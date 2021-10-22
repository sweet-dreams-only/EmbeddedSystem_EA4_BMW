#
# BMW PAGe - Python AUTOSAR Generator
#
# \project     BMW Platform Software
#
# \copyright   BMW AG 2017
#
# \version     1.1.0
#
import sys
import os
import logging
import functools
from collections import defaultdict
from .exceptions import NoResultException, MultipleResultException
from .model import ref, AR_Object, snpath, AR_ConfigValue, SearchExpression, container, module, AR_Identifyable, AR_EcucReference


# Here we tweak the SearchExpression class for an enter and exit function
def searchexpression_enter(self):
    into(self)
def generic_exit(self, type, value, traceback):
    leave()
setattr(SearchExpression, '__enter__', searchexpression_enter)
setattr(SearchExpression, '__exit__', generic_exit)

stack = []
xml_cache = {}
current_scope = [None]
scope = None
current_line = 0
page_current_file = ""
page_current_line = ""
include_stack = []
namespaces = []
param = defaultdict(lambda: False)
page_version = ''
debug_enabled = False
write_counter = 0

auto_comment_delimiters= {
    '.h':('/* ', ' */'),
    '.c':('/* ',' */'),
    '.arxml':('<!-- ', ' -->') }
comment_delimiter=None

class ShortnamePath(object):
    def __init__(self, value):
        self.path = value

    def __enter__(self):
        into(self)

    def __exit__(self, type, value, traceback):
        leave()

    def get_parent(self, index=1):
        return ShortnamePath(self.path.rsplit('/', index)[0])

    def get_shortname(self):
        return self.path.rsplit('/', 1)[1]

    def startswith(self, s):
        return self.path.startswith(s)

class DefinitionRef(ShortnamePath):
    def __enter__(self):
        into(self)

    def __exit__(self, type, value, traceback):
        leave()

def _set_generation_parameters(xmls, ns,  version):
    global xml_cache
    global namespaces
    global page_version
    xml_cache = xmls
    namespaces = ns
    page_version = version

def _get_code():
    global stack
    code = stack[:]
    stack = []
    return code

def _set_position_in_file(file, line):
    """Update the position of the sourcefile.

    This function is inserted automatically by PgenFile to get
    more relevat debug output
    """
    global page_current_file
    global page_current_line
    page_current_file=file
    page_current_line=line


def _push_include(file, source, line):
    global include_stack
    global page_current_file
    global page_current_line
    include_stack.append((file, source, line))

def _pop_include():
    global include_stack
    del include_stack[-1]

def _autoset_comment_delimiter():
    """Set the comment markers based on the file extension contained"""
    global comment_delimiter
    global auto_comment_delimiters
    if comment_delimiter is None:
        comment_delimiter = ('','')
        for (filetype, delimiter) in auto_comment_delimiters.items():
            if filetype in page_current_file:
                comment_delimiter = delimiter
                break


def set_comment_delimiter(start, end=''):
    """Set the comment markers"""
    comment_delimiter=(start, end)

# add write method
def write(*args):
    """Write arguments to the output"""
    global write_counter
    write_counter += 1
    for value in args:
        stack.append(str(value))

def rel(value):
    return snpath(value)

def current_shortname():
    """Get the AUTOSAR shortname of the current scope"""
    scope = 'ROOT'
    if current_scope[-1] is not None:
        scope = current_scope[-1].shortname
    if scope is None:
        scope = 'None'
    return "{scope:s}".format(scope=scope)

def current_shortname_path():
    """Get the AUTOSAR shortname of the current scope"""
    scope = 'ROOT'
    if current_scope[-1] is not None:
        scope = current_scope[-1].shortname_path
    return "{scope:s}".format(scope=scope)

def current_xmlfile():
    """Get the xml filename of the current context"""
    file = 'None'
    if current_scope[-1] is not None:
        file = current_scope[-1].xmlfile
    return "{xmlfile:s}".format(xmlfile=file)

def current_file():
    """Get the position from within the source file"""
    return "{0}:{1}".format(page_current_file, page_current_line)

def element_path(xpath):
    class EP(object):
        def __enter__(self):
            into(xpath)

        def __exit__(self, type, value, traceback):
            leave()

    return EP()


def _find_in_scope_or_elsewhere(search_expression, scope=None):
    """Finds an xpath in current scope, or globally if it is an xglobal path"""
    result = []
    if scope is None and not search_expression.is_absolute:
        scope = current_scope[-1]

    if scope is None:
        scope = xml_cache

    try:
        result = search_expression.execute(scope)
    except NoResultException:
        pass
    return result


def count(xpath):
    """Count elements found by xpath in current context"""
    test = _find_in_scope_or_elsewhere(xpath)
    return len(test)

def exists(xpath):
    """Checks existence of elements specified by xpath in current context.

    Will return 1 if exists and 0 else.
    """
    if xpath is None:
        return 0
    return 1 if count(xpath)>0 else 0

def _is_true(value):
    return '{0}'.format(value).lower() in ['true', '1']

def value(element=None):
    """Fetching the value or value-ref of an element"""
    if type(element) is list:
        if len(element) != 1:
            return [value(x) for x in element]
        else:
            return value(element[0])
    elif isinstance(element, SearchExpression):
        tmp = _find_in_scope_or_elsewhere(element)
        if len(tmp) == 0:
            return None
        elif len(tmp) == 1:
            return tmp[0].value
        else:
            return list(map(lambda x: x.value, tmp))
    elif element is None:
        if issubclass(type(current_scope[-1]), AR_ConfigValue):
            return current_scope[-1].value
        return []
    else:
        tmp = _find_in_scope_or_elsewhere(snpath(element))
        return value(tmp)

def join(xpath, separator=', '):
    """Join a set of values referenced by the xpath"""
    return separator.join(map(str, value(xpath)))

def get_elements(xpath):
    """Get unique xpaths of the elements that match the given xpath"""
    elem = _find_in_scope_or_elsewhere(xpath)
    if len(elem) == 0:
        return []
    return list(elem)

# To be backward compatible
get_xpaths = get_elements

def each(*args):
    """Get unique xpaths of the elements that match the given xpath"""
    result = []
    for searchexp in args:
        elems = _find_in_scope_or_elsewhere(searchexp)
        if len(elems) != 0:
            result.extend(elems)
    return result

def into(target = None):
    """change context to given target, resets if target is None"""
    if target is None:
        del current_scope[1:]
    elif isinstance(target, AR_EcucReference):
        into(snpath(target.value))
    elif isinstance(target, str):
        into(snpath(target))
    elif isinstance(target, AR_Object):
        current_scope.append(target)
    elif isinstance(target, SearchExpression):
        tmp = _find_in_scope_or_elsewhere(target)
        if tmp is None or len(tmp) == 0:
            raise NoResultException(target.expression)
        current_scope.append(tmp[0])
    else:
        raise NoResultException(target)
    scope =  current_scope[-1]


def reset():
    """Resets the context"""
    into()

def leave():
    """Leave the current scope"""
    if len(current_scope) == 1:
        logger.warning('Try to exit scope, but we are not in one')
        return
    current_scope.pop()
    scope = current_scope[-1]

def comment(text, delimiter=None):
    """Format a given string as a comment in the current context.

    If no delimiter are given, the functions calls the automatic
    delimiter resolution.
    The string is splitted into single lines and enclosed in the delimiter
    """
    global comment_delimiter
    if delimiter is None:
        autoset_comment_delimiter()
        delimiter = comment_delimiter
    if type(text) is str:
        data = text.split('\n')
    if type(text) is dict:
        data = list("{!s}: {!s}".format(key, val) for (key, val) in sorted(text.items()))

    return ''.join(list(delimiter[0]+entry+delimiter[1]+'\n' for entry in data))

def shortname(xpath='.'):
    """Get the shortname at the given xpath expression"""
    scope = ''
    with(snpath(xpath)):
        if current_scope[-1] is not None and hasattr(current_scope[-1], 'shortname'):
            scope = current_scope[-1].shortname
    return "{scope:s}".format(scope=scope)

def generation_info():
    """Info about the generation as dict"""
    return {
        'GenerationDate': generation_timestamp(),
        'BMW PAGe Version':generation_version_info(),
        'Last modified': generation_file_modification(),
        'Full path':generation_file_fullpath()
    }

def generation_timestamp():
    """Timestamp of generation"""
    from datetime import datetime
    return '{timestamp}'.format(version=page_version, timestamp=datetime.now())

def generation_tool():
    """name of the generation tool"""
    return 'BMW PAGe'

def generation_version_info():
    """Version of Generator"""
    from datetime import datetime
    return '{version}'.format(version=page_version, timestamp=datetime.now())

def generation_file_modification():
    """Date of modification of the source file"""
    from os.path import getmtime
    import time
    return '{mtime}'.format(mtime=time.ctime(os.path.getmtime(page_current_file)))

def generation_file_fullpath():
    """Full path of the source file"""
    from os.path import abspath
    return '{path}'.format(path=os.path.abspath(page_current_file))

def set_debug(debug):
    global debug_enabled
    debug_enabled = debug

def trap():
    global debug_enabled
    if debug_enabled:
        import pdb
        pdb.set_trace()

