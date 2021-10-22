#
# BMW PAGe - Python AUTOSAR Generator
#
# \project     BMW Platform Software
#
# \copyright   BMW AG 2017
#
# \version     1.1.0
#
class PageException(Exception):
    def __init__(self, filename='', lineno=-1, text='', inner=None, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.filename = filename
        self.lineno = lineno
        self.text = text
        self.inner_exception = inner

    @property
    def inner(self):
        if self.inner_exception is None:
            return ''
        return '\n    caused by: {}'.format(str(self.inner_exception))

class NoResultException(PageException):
    def __init__(self, xpath, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.xpath = xpath

    def __str__(self):
        return 'No node found for xpath "{0}" from {1}:{2}\n{3}{4}'.format(self.xpath, self.filename, self.lineno, self.text, self.inner)

class MultipleResultException(PageException):
    def __init__(self, xpath, count, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.xpath = xpath
        self.count = count

    def __str__(self):
        info_inner = str(self.inner_exception)
        return 'Multiple ({4}) nodes found for xpath ({0}) from {1}:{2}\n{3}{5}'.format(self.xpath, self.filename, self.lineno, self.text, self.count, self.inner)

class IncludeFileNotFoundException(PageException):
    def __init__(self, incfile, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.incfile = incfile

    def __str__(self):
        info_inner = str(self.inner_exception)
        return 'Include file not found: {0} included from {1}:{2}{3}'.format(self.incfile, self.filename, self.lineno, self.inner)

class InvalidStatementException(PageException):
    def __init__(self, *args, **kwargs):
        self.info = kwargs.pop('info')
        super().__init__(*args, **kwargs)

    def __str__(self):
        info_inner = str(self.inner_exception)
        return 'Cannot process the statement: "{0}" at {1}:{2}\n    {3}{4}'.format(self.text, self.filename, self.lineno, self.text, self.inner)

class PageSyntaxException(PageException):
    def __init__(self, offset=0, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.offset = offset

    def __str__(self):
        info_inner = str(self.inner_exception)
        error = 'Invalid Syntax at {1}:{2}:\n    {0}\n    {3}{4}'
        return error.format(self.text, self.filename, self.lineno, ' '*(self.offset-1) + '^', self.inner)

class TemplateRuntimeError(PageException):
    def __init__(self, block, exception, stacktrace=[], *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.block = block
        self.exception = exception
        self.stacktrace = stacktrace

    def __str__(self):
        info_inner = str(self.inner_exception)
        formatstring = '{error} in Template happens at {blockname} starting at {file}:{line} ({text})\n{trace}{inner}'
        return formatstring.format(
            error=type(self.exception).__name__,
            file=self.filename,
            blockname=self.block,
            line=self.lineno,
            text=self.text,
            trace=''.join(self.stacktrace),
            inner=info_inner
        )


class XMLParserError(PageException):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)

    def __str__(self):
        return 'Failed parsing xml file {0}{1}'.format(self.filename, self.inner)

class XMLElementMissing(XMLParserError):
    def __init__(self, typ, element, shortname_path, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.typ = typ
        self.element = element
        self.shortname_path = shortname_path

    def __str__(self):
        return 'Element {0} at {2} is expecting {1}.'.format(self.typ, self.element, self.shortname_path)
