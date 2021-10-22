#
# BMW PAGe - Python AUTOSAR Generator
#
# \project     BMW Platform Software
#
# \copyright   BMW AG 2017
#
# \version     1.1.0
#
import re
import logging
from .parts import *

import json

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
        self._prepare()

    def _prepare(self):
        self._loadfile()
        self.split_text()

    def _loadfile(self):
        self.logger.info('Open file {filename:s}'.format(filename=self.filename))
        self.parts=[]
        with open(self.filename, 'r', encoding='utf-8') as file:
             self.text = file.read()
        self.text = self.text.replace('\r\n', '\n')

    def parse_text(self):
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

    def __len__(self):
        return len(self.parts)

    def __getitem__(self, index):
        if index > len(self):
            return IndexError("End of file")
        return self.parts[index]
