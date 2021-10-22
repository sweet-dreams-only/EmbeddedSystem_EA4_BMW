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
import argparse
import logging
import importlib
import hashlib
import json
from collections import OrderedDict
import sys
import traceback
import time
from .model import AR_Root, AR_EcucModuleDefinition, AR_EcucModuleConfiguration, ArxmlParser
from .exceptions import *
from .pgenfile import PgenFile, File


class Command(object):
    version = '1.1.0'
    filecache = {}
    xml_cache = OrderedDict()
    ar = None
    namespaces = {'AR':'http://autosar.org/schema/r4.0'}
    exec_namespace = {}

    def __init__(self):
        pass

    def readxmls(self, xmls):
        total_start = time.time()
        xmlParser = ArxmlParser()
        for xml in xmls:
            self.logger.info("Reading XML: {0}".format(xml))
            start = time.time()
            try:
                xmlParser.parse(xml)
                self.logger.info("Reading XML took: {0:.3} s".format(time.time()-start))
            except OSError:
                self.logger.error("Cannot Read XML: {0}".format(xml))
            except XMLParserError as e:
                self.logger.error("XML could not be parsed: {0}\n{1}".format(xml, e))
            except Exception as e:
                self.logger.error(e)
        if len(xmls) != 0:
            self.logger.info("Reading all XMLs took: {0:.3} s".format(time.time()-total_start))
        self.ar = xmlParser.ar

    def prepare_namespace(self):
        self.utils = importlib.import_module('page.utility')
        self.utils._set_generation_parameters(self.ar, self.namespaces, self.version)
        self.utils.logger = self.logger
        self.utils.set_debug(self.args.debug)
        self.make_definitions_available()

    def make_definitions_available(self):
        for arg in self.args.definitions:
            try:
                name, value = arg.split('=')
            except:
                name = arg
                value = True
            self.utils.param[name] = value

    def render(self, pgen, **namespace):
        '''Renders the template according to the given namespace.'''
        self.utils.reset()
        return pgen.render(self.utils)

    def setupLogger(self):
        verbosity_level = logging.ERROR - self.args.verbose*logging.DEBUG

        class MultilineIndentiation(logging.Filter):
            def filter(self, record):
                if type(record.msg) is str:
                    record.msg = record.msg.replace('\n','\n\t')
                return super().filter(record)

        class callcounted(object):
            """Decorator to determine number of calls for a method"""

            def __init__(self,method):
                self.method=method
                self.counter=0

            def __call__(self,*args,**kwargs):
                self.counter+=1
                return self.method(*args,**kwargs)

        self.logger = logging.getLogger('BMW PAGe')
        self.logger.setLevel(1)
        self.logger.addFilter(MultilineIndentiation())
        self.logger.error = callcounted(self.logger.error)
        self.logger.warning = callcounted(self.logger.warning)

        console = logging.StreamHandler()
        console.setLevel(verbosity_level)
        try:
            import coloredlogs
            styles = coloredlogs.DEFAULT_FIELD_STYLES
            styles['levelname'] = {'color':'white', 'bold':False}
            formatter = coloredlogs.ColoredFormatter('%(name)-12s: %(levelname)-8s %(message)s', field_styles=styles)
        except ImportError:
            formatter = logging.Formatter('%(name)-12s: %(levelname)-8s %(message)s')
        console.setFormatter(formatter)
        self.logger.addHandler(console)

        if self.args.logfile is not None:
            fh = logging.FileHandler(self.args.logfile, mode='w')
            fh.setLevel(min(logging.DEBUG, verbosity_level))
            file_log_formatter = logging.Formatter('%(asctime)s - %(name)s - %(levelname)s - %(message)s')
            fh.setFormatter(file_log_formatter)
            self.logger.addHandler(fh)

    def setupArgumentParser(self):
        self.parser = argparse.ArgumentParser(
            description='BMW Python AUTOSAR Generator V{0:s}'.format(self.version), prog='page')
        self.parser.add_argument('file', nargs='*',
                                 help='arxml or pgen files')
        self.parser.add_argument('-o', '--outdir', type=str,
                                 help='write output to specified folder', default='.')
        self.parser.add_argument('--stdout',  action='store_true',
                                 help='write output to stdout')
        self.parser.add_argument('-v', '--verbose', action='count',
                                 default=0,
                                 help='activate verbose output')
        self.parser.add_argument('-l', '--logfile',
                                 help='log to file')
        self.parser.add_argument('-d', '--debug', action='store_true',
                                 default=False,
                                 help='enable python debugging')
        self.parser.add_argument('-m', '--delimiter',
                                 help='custom delimiter')
        self.parser.add_argument('-V', '--verify', action='store_true',
                                 help='verify paramconfs against paramdef')
        self.parser.add_argument('-i', '--include',  action='append', default=[],
                                 help='include path')
        self.parser.add_argument('-D', '--definitions', action='append', default=[],
                                 help='add variables available for template (key=value)')
        self.parser.add_argument('-O', '--optimizedb', nargs='?', default=os.path.join(os.path.expanduser('~'), '.page_database'),
                                 help='specify database to store hashes of output and write file only if changed'),
        self.parser.add_argument('-f', '--force', action='store_true', default=False, help='always write files')

    def parseArguments(self):
        self.setupArgumentParser()
        self.args = self.parser.parse_args()

    def shouldWriteOutput(self, filename, content):
        if self.args.force:
            self.logger.info("Forced write")
            return True
        if len(content) == 0:
            self.logger.info("Empty content -> no file written")
            return False
        if not os.path.exists(filename):
            self.logger.info("File does not exist")
            return True
        if not filename in self.database or self.database[filename] != hashlib.sha1(content.encode('utf-8')).hexdigest():
            self.logger.info("Database entry did not match")
            return True
        if self._get_file_hash(filename) != hashlib.sha1(content.encode('utf-8')).hexdigest():
            self.logger.info("File on disk does not match")
            return True
        return False

    def _get_file_hash(self, filename):
        hasher = hashlib.sha1()
        with open(filename, 'r', encoding='utf-8') as afile:
            buf = afile.read()
            hasher.update(buf.encode('utf-8'))
        return hasher.hexdigest()

    def setupDatabase(self):
        try:
            if self.args.force:
                raise Exception()
            with open(self.args.optimizedb, 'r') as f:
                self.database = json.load(f)
        except:
            self.database = {}

    def shutdownDatabase(self):
        if self.args.force:
            return
        with open(self.args.optimizedb, 'w+') as f:
            json.dump(self.database, f)


    def process_files(self, files):
        File.add_include_path(*self.args.include)
        for file in files:
            try:
                self.logger.info("processing Pgen: {0}".format(file))
                start = time.time()
                path = os.path.splitext(file)[0]
                f = PgenFile(file, logger=self.logger, debug=self.args.debug, delimiter=self.args.delimiter)
                output = self.render(f)
                self.logger.info("Processing Pgen took: {0:.3} s".format(time.time()-start))
                if self.args.stdout:
                    print (output)
                filename = self.get_output_path(self.args.outdir, file)
                if self.shouldWriteOutput(filename, output):
                    self.logger.info("Write {file}".format(file=filename))
                    with open(filename, 'w', encoding='utf-8') as of:
                        of.write(output)
                    self.database[filename] = hashlib.sha1(output.encode('utf-8')).hexdigest()
                else:
                    self.logger.info("Skipping write of {file}, no changes detected".format(file=filename))

            except PageException as e:
                self.logger.error('Error while processing: {0} '.format(file))
                import traceback
                tb = traceback.format_exception(type(e), e, None)
                self.logger.debug(''.join(tb))
            except Exception as e:
                import traceback
                self.logger.fatal('Error while processing: {0}\n{1} '.format(file, traceback.format_exc()))

    def verify(self):
        for module in self.ar.get_all(AR_EcucModuleDefinition):
            module.verify(self.logger)

    def open_output(self, targetdir, filename, extension=''):
        return open(self.get_output_path(targetdir, filename, extension), 'w', encoding='utf-8')

    def get_output_path(self, targetdir, filename, extension=''):
        filename = os.path.splitext(filename)[0]
        if extension != '':
            filename += '.' + extension
        filename = os.path.split(filename)[1]
        outputpath = os.path.join(os.path.abspath(targetdir), filename)
        os.path.exists(os.path.dirname(outputpath)) or os.makedirs(os.path.dirname(outputpath))
        return outputpath

    def run(self):
        self.parseArguments()
        self.setupLogger()
        self.setupDatabase()
        self.readxmls(list(filter(re.compile('.*\.arxml$').match, self.args.file)))
        if self.logger.error.counter == 0:
            if self.args.verify:
                self.verify()
            else:
                self.prepare_namespace()
                self.process_files(filter(re.compile('.*{extension:s}$'.format(extension=re.escape(PgenFile.file_extension))).match, self.args.file))
        self.shutdownDatabase()
        return self.logger.error.counter != 0

