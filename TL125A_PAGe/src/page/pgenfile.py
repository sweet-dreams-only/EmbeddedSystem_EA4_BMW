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
import re
import logging
import tempfile
from .exceptions import *


class File(object):
    file_paths = ['.']

    def __init__(self, includedfrom=None):
        self.includedfrom=includedfrom

    @classmethod
    def create(cls, file, *args, **kwargs):
        for f in [PythonFile, PgenFile]:
            if file.endswith(f.file_extension):
                return f(file, *args, **kwargs)
        return PgenFile(file, *args, **kwargs)

    @classmethod
    def add_include_path(cls, *paths):
        for path in paths:
            cls.file_paths.append(path)

    def findfile(self, filename):
        filepath = filename
        if not filename.endswith(self.file_extension):
            filename += self.file_extension
        for path in self.file_paths:
            fpath = os.path.join(path, filename)
            if os.path.exists(fpath):
                filepath = os.path.abspath(fpath)
                break
        if not os.path.dirname(filepath) in self.file_paths:
            self.file_paths.append(os.path.dirname(filepath))
        return filepath


class PythonFile(File):
    file_extension = '.py'
    def __init__(self, filename, includedfrom=None):
        self.filename = self.findfile(filename)
        super().__init__(includedfrom=includedfrom)

    @property
    def text(self):
        if not hasattr(self, '_text'):
            with open(self.filename) as file:
                 self._text = file.read()
            self._text = self.text.replace('\r\n', '\n')
        return self._text


class PgenFile(File):
    file_extension = '.pgen'
    encoding = 'utf-8'
    indentstring = '    '

    def __init__(self, filename, logger=logging.getLogger('BMW PAGe'), debug=None, delimiter=None, includedfrom=None):
        self.filename = self.findfile(filename)
        self.logger = logger
        self.delimiter = delimiter or ('%{', '}%')
        self.debug = debug or False
        super().__init__(includedfrom=includedfrom)

    def parse(self):
        self.codeparts = InputText(self.filename, self.delimiter, logger=self.logger)

    def render(self, globals):
        self.parse()
        self.elements = []
        return self.codeparts.render(globals)


class InputText:
    '''
    Input class which performs the splitting of the text into the InpurParts
    '''

    def __init__(self, filename, delimiter, logger=None):
        self.filename = filename
        self.logger = logger or logging.getLogger(__name__)
        self.silent = False
        self.delimiter = delimiter
        self.delimiter_regex = tuple(map(re.escape, delimiter))
        self.prepare()

    def prepare(self):
        self.loadfile()
        self.split_text()

    def loadfile(self):
        self.logger.info('Open file {filename:s}'.format(filename=self.filename))
        self.parts=[]
        with open(self.filename, 'r', encoding='utf-8') as file:
             self.text = file.read()
        self.text = self.text.replace('\r\n', '\n')

    def parse_text(self):
        from .parts import TextPart, CodePart
        last = ''
        current_token = ''
        current_text = ''
        inCode = False
        stack = [self]
        linecounter = 1
        skip = 0
        max_token_length = max(map(len, self.delimiter))
        def addtp():
            '''helper to add textpart'''
            try:
                previous = stack[-1].parts[-1]
            except:
                try:
                    previous = stack[-1]
                except:
                    previous = None

            part = TextPart.create(current_text, startline=linecounter, filename=self.filename, previous=previous, logger=self.logger)
            stack[-1].parts.append(part)

        def match_start(index):
            return self.text[index+1:index+len(self.delimiter[0])] == self.delimiter[0][1:]

        def match_end(index):
            return self.text[index+1:index+len(self.delimiter[1])] == self.delimiter[1][1:]

        for index,c in enumerate(self.text):
            if c == '\n':
                linecounter += 1
            if skip > 0:
                skip -= 1
                continue

            if not inCode and c == self.delimiter[0][0] and self.text[index-1] != '\\' and match_start(index):
                if len(current_text):
                    addtp()
                inCode = True
                startline = linecounter
                current_text = ''
                skip = len(self.delimiter[0])-1
            elif inCode and c == self.delimiter[1][0] and self.text[index-1] != '\\' and match_end(index):
                part = CodePart.create(current_text, startline=startline, filename=self.filename, logger=self.logger)
                startelement=None
                if part.multipart:
                    stack[-1].add(part)
                if part.exit:
                    part.startpart = stack[-1]
                    stack=stack[:-1]
                stack[-1].parts.append(part)
                if part.nesting:
                    stack.append(part)
                inCode = False
                current_text = ''
                skip = len(self.delimiter[1])-1
            else:
                current_text += c
        addtp()

    def render(self, module):
        elements = []
        for part in self.parts:
             elements.append(part.render(module))
        return ''.join(elements)


    def split_text(self):
        self.parse_text()
        return

    def __len__(self):
        return len(self.parts)

    def __getitem__(self, index):
        if index > len(self):
            return IndexError("End of file")
        return self.parts[index]
