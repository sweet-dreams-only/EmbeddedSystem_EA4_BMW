# ======================================================================================================================
#      File: OdxDoc.py
#   Project: EA4 Manufacturing Services
#   Created: 2016-01-26
#  Modified: 2016-01-26
#    Author: Jared Julien
#     Email: jared.julien@nexteer.com
# Copyright: (c) 2016 Nxtr Automotive
#
# Description:
# ------------
# OdxArxml converts an ODX file into ARXML describing the services suitable for import into Configurator during CMS
# configuration.
#
# Date        Rev   Author    Change Description
# ==========  ====  ========  =========================================================================================
# 2016-01-26  1     Jared     Initial file creation
# ----------------------------------------------------------------------------------------------------------------------
# ======================================================================================================================
# Import Statements
# ----------------------------------------------------------------------------------------------------------------------
import argparse
import logging
import re
import os
import json
import datetime
import glob

# Installed Dependencies
from mako.lookup import TemplateLookup  # https://pypi.python.org/pypi/Mako/
import markdown                         # https://pypi.python.org/pypi/Markdown
import csscompressor                    # https://pypi.python.org/pypi/csscompressor/0.9.3

# Local imports
import bindings.odx
import bindings.autosar4
import libraries.services


# ======================================================================================================================
# Constants
# ----------------------------------------------------------------------------------------------------------------------
VERSION = "%version: 1 %"


# ======================================================================================================================
# Diagram Classes
# ----------------------------------------------------------------------------------------------------------------------
class Diagram(list):
    def assemble(self):
        # Create a row with each parameters representation shown
        text = ' '.join([entry.head() for entry in self]) + '\n'
        # Then a row with nothing by vertical bars under each of the parameters
        text += ' '.join([entry.body() for entry in self]) + '\n'
        # Then loop through each item and print it's description
        while len(self) > 0:
            last = self.pop()
            parts = [entry.body() for entry in self]
            parts.append(last.tail())
            text += ' '.join(parts) + '\n'
        return text.strip()

# ----------------------------------------------------------------------------------------------------------------------
class DiagramEntry:
    def __init__(self):
        self.repr = 'xx'
        self.count = 1
        self.desc = None
    def head(self):
        return ' '.join([self.repr] * self.count)
    def body(self):
        if self.desc is None:
            return ' ' * len(self.repr)
        spaces = ' ' * len(self.repr)
        pad = ' ' * (len(self.repr) - 1)
        return spaces.join(['|'] * self.count) + pad
    def tail(self):
        if self.desc is None:
            return ''
        dashes = '-' * len(self.repr)
        lead = dashes if self.count > 1 else ''
        return "'" + lead + (dashes.join(['o'] * (self.count - 1))) + '-- ' + self.desc


# ======================================================================================================================
# Category Classes
# ----------------------------------------------------------------------------------------------------------------------
class Pages(list):
    def toJSON(self):
        def dumper(obj):
            try:
                return obj.toJSON()
            except AttributeError:
                return obj.__dict__
        return json.dumps(self, default=dumper)

# ----------------------------------------------------------------------------------------------------------------------
class Page:
    def __init__(self, title):
        self.title = title
        self.link = re.sub(r'[^a-zA-Z0-9_]+', '', title)
        self.sections = []
        self.services = []
        self.html = None

# ----------------------------------------------------------------------------------------------------------------------
class Section:
    def __init__(self, heading):
        self.heading = heading
        self.link = re.sub(r'[^a-zA-Z0-9_]+', '', heading)
        self.services = []
        self.html = None


# ======================================================================================================================
# Service Class Extension
# ----------------------------------------------------------------------------------------------------------------------
# This class extends the service library Service class to add additional functionality for generating documentation
# diagrams for request and responses.  This is more efficient as a list of service can be passed into the HTML template
# and the template renderer can call the diagram generation functions on the fly.  These diagrams are only needed by
# this documentation generation tool.
class ServiceDiagram(libraries.services.Service):
    def _diagram(self, params):
        diagram = Diagram()
        for param in params:
            if param.type == 'VALUE':
                if isinstance(param.dop, libraries.services.DOP):
                    entry = DiagramEntry()
                    type = param.dop.baseType
                    if type == 'A_FLOAT32':
                        entry.repr = 'ff'
                        entry.count = 4
                    elif type == 'A_UINT32':
                        entry.count = param.dop.bytes
                    elif type == 'A_ASCIISTRING':
                        entry.repr = 'aa'
                        entry.count = param.dop.bytes
                    elif type == 'A_BYTEFIELD':
                        entry.count = param.dop.bytes
                    entry.desc = param.long + param.dop.details()
                    diagram.append(entry)
                else:
                    # Structure type
                    struct = []
                    for subParam in param.dop.params:
                        entry = DiagramEntry()
                        entry.repr = 'b' * subParam.bits
                        entry.desc = subParam.long if subParam.type != 'RESERVED' else 'Reserved'
                        struct.append(entry)
                    # Bit positions in structs are reverse order (right to left) to build the list and then reverse it
                    # before adding it into the diagram
                    diagram.extend(reversed(struct))
            else:
                if param.value is not None:
                    # use length to determine the number of bytes that should appear in the representation string
                    entry = DiagramEntry()
                    template = '%%0%dX' % (param.length / 4)
                    entry.repr = template % param.value
                    diagram.append(entry)
        return diagram.assemble()

    def requestDiagram(self):
        return self._diagram(self.request.params)

    def responseDiagram(self):
        return self._diagram(self.positive.params)

    def toJSON(self):
        attrs = {
            'long': self.long,
            'short': self.short,
            'desc': self.desc,
            'reqLen': self.reqLenStr(),
            'respLen': self.respLenStr(),
            'request': self.requestDiagram(),
            'response': self.responseDiagram(),
            'nrcs': [response.nrcStr() for response in self.negative],
            'access': {
                'nexteerSession': self.nexteerSession(),
                'nexteerSession': self.nexteerSession(),
            }
        }
        return attrs


# ======================================================================================================================
# Helper Functions
# ----------------------------------------------------------------------------------------------------------------------
def generateDocs(services, overview, attrs):
    directory = os.path.dirname(os.path.realpath(__file__))
    templateDir = os.path.join(directory, 'templates')
    assetDir = os.path.join(directory, 'assets')
    cssFiles = ['bootstrap.css']
    jsFiles = [
        'jquery.js',
        'bootstrap.js',
        'underscore.js',
        'backbone.js',
        'handlebars.js',
        'lunr.js',
        'app.js',
    ]
    def compressCss():
        css = ''
        for file in cssFiles:
            path = os.path.join(assetDir, file)
            with open(path) as file:
                css += file.read()
        return csscompressor.compress(css)
    def compressJs():
        js = ''
        for file in jsFiles:
            path = os.path.join(assetDir, file)
            with open(path) as file:
                js += file.read()
        return js.decode('utf-8')
    pages = sortBySemantic(services, overview)
    # Derive the path to template files as relative to this file.  Mako assumes that templates are relative to the
    # directory from which the script is called which is likely to be in a component folder where the batch files is
    # located rather than here.
    lookup = TemplateLookup(directories=[templateDir])
    mytemplate = lookup.get_template('OdxDoc.html.tpl')
    attrs['pages'] = pages
    attrs['timestamp'] = datetime.datetime.now().strftime('%d-%b-%y %H:%M %p')
    attrs['tool'] = os.path.basename(__file__)
    attrs['version'] = re.findall(r'(\d+)', VERSION)[0]
    attrs['css'] = compressCss()
    attrs['js'] = compressJs()
    return mytemplate.render(**attrs).replace('\r', '')

# ----------------------------------------------------------------------------------------------------------------------
def generateOverview(directory):
    def demoteHeadings(html):
        for level in range(5, 0, -1):
            fromTag = r'<(/?)h%d>' % level
            toTag = r'<\1h%d>' % (level + 1)
            html = re.sub(fromTag, toTag, html)
        return html
    overview = None
    if directory and os.path.exists(directory):
        overview = Page('Overview')
        path = directory.strip('/\\') + '\\*.md'
        for file in sorted(glob.glob(path)):
            heading = os.path.splitext(re.sub(r'^\d+\. ?', '', file.rsplit('\\', 1)[1]))[0]
            section = Section(heading)
            with open(file) as inFile:
                text = inFile.read()
            html = markdown.markdown(text, extensions=['extra'])
            section.html = demoteHeadings(html)
            overview.sections.append(section)
    return overview

# ----------------------------------------------------------------------------------------------------------------------
def sortBySemantic(services, overview):
    pages = Pages()
    def findPage(title):
        for page in pages:
            if page.title == title:
                return page
        return None
    def findSection(heading, sections):
        for section in sections:
            if section.heading == heading:
                return section
        return None
    for service in services:
        semantic = service.semantic
        parts = semantic.split('-', 1)
        if len(parts) == 2:
            title = parts[0]
            heading = parts[1]
        else:
            title = parts[0]
            heading = ''
        title = title.strip().title()
        heading = heading.strip()
        page = findPage(title)
        if page is None:
            page = Page(title)
            pages.append(page)
        if len(heading) == 0:
            page.services.append(service)
        else:
            section = findSection(heading, page.sections)
            if section is None:
                section = Section(heading)
                page.sections.append(section)
            section.services.append(service)
    # sort pages by services in them
    def pageSort(page):
        # Create a temporary list of service that is a copy of page services.  If a copy isn't made, the extend that
        # follows will destroy the services in the page creating all sorts of duplicate entries.
        services = list(page.services)
        for section in page.sections:
            services.extend(section.services)
        return min([service.request.getServiceId() for service in services])
    pages.sort(key=pageSort)
    # Sort services within each page
    for page in pages:
        page.services.sort(key=lambda service: service.request.getServiceId())
        for section in page.sections:
            section.services.sort(key=lambda service: service.request.getServiceId())
    overview = generateOverview(overview)
    if overview:
        pages.insert(0, overview)
    return pages

# ----------------------------------------------------------------------------------------------------------------------
def loadProgramAttributes(args):
    attrs = {}
    if args.ecuc:
        logging.info('Reading configuration file: %s', args.ecuc)
        with open(args.ecuc) as inFile:
            input = inFile.read()
        ecuc = bindings.autosar4.CreateFromDocument(input)
        for module in ecuc.AR_PACKAGES.AR_PACKAGE[0].ELEMENTS.ECUC_MODULE_CONFIGURATION_VALUES:
            if module.SHORT_NAME.value() == 'NxtrSwIds':
                logging.info('Found expected module: %s', module.SHORT_NAME.value())
                for container in module.CONTAINERS.ECUC_CONTAINER_VALUE:
                    if container.DEFINITION_REF.value() == '/Nxtr/NxtrSwIds/NxtrSwIdsGeneral':
                        for parameter in container.PARAMETER_VALUES.ECUC_TEXTUAL_PARAM_VALUE:
                            if parameter.DEFINITION_REF.value() == '/Nxtr/NxtrSwIds/NxtrSwIdsGeneral/SwRelNr':
                                attrs['program'] = parameter.VALUE.value()
                            elif parameter.DEFINITION_REF.value() == '/Nxtr/NxtrSwIds/NxtrSwIdsGeneral/SwRelVer':
                                attrs['revision'] = parameter.VALUE.value()
    else:
        attrs['program'] = 'CBD'
        attrs['revision'] = 'N/A'
    return attrs


# ======================================================================================================================
# Main Function
# ----------------------------------------------------------------------------------------------------------------------
if __name__ == "__main__":
    description = "Nxtr ODX Documentation Generation Utility - EA4 Manufacturing Services"
    parser = argparse.ArgumentParser(description=description)
    parser.add_argument('-v', '--verbose', default=0, action='count', help='Output detailed information to console')
    parser.add_argument('--overview', help='Directory containing *.md files to generate overview page')
    parser.add_argument('--ecuc', help='Path to EPS_NxtrMfgSrv_ecuc.arxml file from which program infomrmation can be parsed')
    parser.add_argument('input', help='Input merged and trimmed ODX filename used to generate documentation')
    parser.add_argument('output', help='Output HTML document filename')
    args = parser.parse_args()

    # Setup logging
    levels = [logging.WARNING, logging.INFO, logging.DEBUG]
    logLevel = levels[min(args.verbose, 2)]
    logging.basicConfig(level=logLevel)

    # Read input ODX file
    logging.info('Reading input file: %s', args.input)
    with open(args.input) as inFile:
        odxText = inFile.read()
    cms = bindings.odx.CreateFromDocument(odxText)

    # Read ECUC configuration if supplied
    attrs = loadProgramAttributes(args)

    # Generate HTML documentation
    variant = cms.DIAG_LAYER_CONTAINER.BASE_VARIANTS.BASE_VARIANT[0]
    services = []
    for diag in variant.DIAG_COMMS.DIAG_SERVICE:
        if '_NoResponse' not in diag.SHORT_NAME:
            service = ServiceDiagram(diag, variant)
            services.append(service)
    html = generateDocs(services, args.overview, attrs)

    # Write output file
    with open(args.output, 'w+') as outFile:
        outFile.write(html)
    logging.info('Output written to: %s', args.output)


# End of File: OdxDoc.py