# ======================================================================================================================
#      File: OdxTest.py
#   Project: EA4 Manufacturing Services
#   Created: 2016-01-26
#  Modified: 2016-01-26
#    Author: Jared Julien
#     Email: jared.julien@nexteer.com
# Copyright: (c) 2016 Nxtr Automotive
#
# Description:
# ------------
# OdxTest accepts an ODX container as it's input and generates a round of very basic functionality tests to verify
# proper service operation over CAN.  This test is not intended to replace formal functional test but is intended to
# assist in determining if all services are properly configured.
#
# The test run using this tool are very basic and are restricted to the format as specified by ISO 14229 rather than to
# the common services ODX file.  In other words, this tool has no idea that an auto-trim for handwheel torque has a
# manual read service that can also be used to ensure that the auto-trim completed successfully.  The best it will do
# is run the service and ensure that it 1) gets a response and 2) that the response is as expected (positive or
# negative).
#
# TODO: Support check for session(s) to ensure service work/don't work as intended in various sessions.
# TODO: Include check for security access to ensure service work or don't work when configured.
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
import datetime
import os
import re
import uuid
import webbrowser
from ctypes import Union, c_float, c_uint32, c_uint8

# Installed Dependencies
from mako.lookup import TemplateLookup  # https://pypi.python.org/pypi/Mako/
import csscompressor                    # https://pypi.python.org/pypi/csscompressor/0.9.3


# Local imports
import bindings.odx
import bindings.autosar4
import libraries.services
import libraries.iso14229
from libraries.iso15765 import CANTimeout


# ======================================================================================================================
# Constants
# ----------------------------------------------------------------------------------------------------------------------
VERSION = "%version: 1 %"


# ======================================================================================================================
# Helper Classes
# ----------------------------------------------------------------------------------------------------------------------
class u32f32(Union):
    """This class is used to convert single-precision floats to byte arrays."""
    _fields_ = [('f32', c_float),
                ('u32', c_uint32),
                ('u08', c_uint8 * 4)]


# ======================================================================================================================
# Test Classes
# ----------------------------------------------------------------------------------------------------------------------
class Test:
    id = None
    sub = None
    request = []
    respLen = None
    echo = None
    data = None
    name = ''
    def __init__(self, type, id, sub=None, request=[], respLen=None, echo=None):
        self.type = type
        self.id = id
        self.sub = sub
        self.request = request
        self.respLen = respLen
        self.echo = echo
    def execute(self, interface):
        report = Report(self)
        self.run(interface, report)
        return report
    def title(self):
        return 'Service %s' % self.name
    def __repr__(self):
        txt = '<Test '
        if self.type is not None:
            txt += 'type=0x%02X ' % self.type
        if self.sub is not None:
            txt += 'sub=0x%02X ' % self.sub
        if self.id is not None:
            txt += 'id=0x%04X ' % self.id
        return txt.strip() + '>'

# ----------------------------------------------------------------------------------------------------------------------
class Session(Test):
    def __init__(self, sub):
        self.type = 0x10
        self.sub = sub
    def run(self, service, report):
        report.start('Session - 0x%02X' % self.sub)
        test = report.step('Request session 0x%02X' % self.sub)
        resp = service.session(self.sub)
        if resp.success:
            test.yay()
            test = report.step('Request return to default session')
            resp = service.session(0x01)
            if resp.success:
                test.yay()
                test = report.step('Request session w/ suppressed response')
                try:
                    resp = service.session(0x80 | self.sub)
                    test.nay('Expected to suppress positive response, got %s' % resp.errorString())
                except CANTimeout:
                    # Expect timeout before response
                    test.yay()
            else:
                test.nay(resp.errorString())
        else:
            test.nay(resp.errorString())
        report.complete()

# ----------------------------------------------------------------------------------------------------------------------
class Reset(Test):
    def __init__(self, sub):
        self.type = 0x11
        self.sub = sub
    def run(self, service, report):
        report.start('Reset - 0x%02X' % self.sub)
        test = report.step('Issuing reset 0x%02X' % self.sub)
        resp = service.reset(self.sub)
        if resp.success:
            test.yay()
            test = report.step('Issuing reset w/ suppressed response')
            try:
                resp = service.reset(0x80 | self.sub)
                test.nay('Expected to suppress positive response, got %s' % resp.errorString())
            except CANTimeout:
                # Expect timeout before response
                test.yay()
        else:
            test.nay(resp.errorString())
        report.complete()

# ----------------------------------------------------------------------------------------------------------------------
class Tester(Test):
    def __init__(self):
        self.type = 0x3E
        self.sub = 0x00
    def run(self, service, report):
        report.start('Tester Present')
        test = report.step('Issuing tester present request')
        resp = service.tester()
        if resp.success:
            test.yay()
            test = report.step('Issuing tester present w/ supressed response')
            try:
                resp = service.tester(0x80)
                test.nay('Expected to suppress positive response, got %s' % resp.errorString())
            except CANTimeout:
                # Expect timeout before response
                test.yay()
        else:
            test.nay(resp.errorString())
        report.complete()

# ----------------------------------------------------------------------------------------------------------------------
class Start(Test):
    def __init__(self, id):
        self.id = id
    def run(self, service, report):
        report.start('Start - 0x%04X 0x01' % self.id)
        test = report.step('Issue start request')
        resp = service.rid(self.id, 0x01)
        if resp.success:
            test.yay()
            self.data = resp.data
            test = report.step('Issue start request w/ supressed response')
            try:
                resp = service.rid(self.id, 0x81)
                test.nay('Expected to suppress positive response, got %s' % resp.errorString())
            except CANTimeout:
                # Expect timeout before response
                test.yay()
        else:
            test.nay(resp.errorString())
        report.complete()

# ----------------------------------------------------------------------------------------------------------------------
class Stop(Test):
    def __init__(self, id):
        self.id = id
    def run(self, service, report):
        report.start('Stop - 0x%04X 0x02' % self.id)
        test = report.step('Issue stop request')
        resp = service.rid(self.id, 0x02)
        if resp.success:
            test.yay()
            self.data = resp.data
            test = report.step('Issue stop request w/ supressed response')
            try:
                resp = service.rid(self.id, 0x82)
                test.nay('Expected to suppress positive response, got %s' % resp.errorString())
            except CANTimeout:
                # Expect timeout before response
                test.yay()
        else:
            test.nay(resp.errorString())
        report.complete()

# ----------------------------------------------------------------------------------------------------------------------
class Status(Test):
    def __init__(self, id, respLen):
        self.id = id
        self.respLen = respLen
    def run(self, service, report):
        report.start('Status - 0x%04X 0x03' % self.id)
        test = report.step('Request routine status')
        resp = service.rid(self.id, 0x03)
        if resp.success:
            test.yay()
            test = report.step('Verify response length')
            if self.respLen is None or len(resp.data) == self.respLen:
                test.yay()
                self.data = resp.data
            else:
                test.nay('Returned: %d, Expected: %d' %(len(resp.data), self.respLen))
        else:
            test.nay(resp.errorString())
        report.complete()

# ----------------------------------------------------------------------------------------------------------------------
class Read(Test):
    def __init__(self, id, respLen):
        self.type = 0x22
        self.id = id
        self.respLen = respLen
    def run(self, service, report):
        report.start('Read - 0x%04X' % self.id)
        test = report.step('Request read from controller')
        resp = service.rpid(self.id)
        if resp.success:
            test.yay()
            test = report.step('Verify response length')
            if self.respLen is None or len(resp.data) == self.respLen:
                test.yay()
                self.data = resp.data
            else:
                test.nay('Returned: %d, Expected: %d' % (len(resp.data), self.respLen))
        else:
            test.nay(resp.errorString())
        report.complete()

# ----------------------------------------------------------------------------------------------------------------------
class ReadWrite(Test):
    def __init__(self, id):
        self.type = 0x2E
        self.id = id
    def run(self, service, report):
        report.start('ReadWrite - 0x%04X' % self.id)
        test = report.step('Request initial read')
        resp = service.rpid(self.id)
        if resp.success:
            initial = resp.data
            test.yay()
            test = report.step('Write back initial data')
            resp = service.wpid(self.id, initial)
            if resp.success:
                test.yay()
                test = report.step('Read back data')
                resp = service.rpid(self.id)
                if resp.success:
                    test.yay()
                    test = report.step('Confirm data matches initial read')
                    if resp.data == initial:
                        test.yay()
                    else:
                        test.nay(resp.errorString())
                else:
                    test.nay(resp.errorString())
            else:
                test.nay(resp.errorString())
        else:
            test.nay(resp.errorString())
        report.complete()

# ----------------------------------------------------------------------------------------------------------------------
class Write(Test):
    def __init__(self, id, reqLen):
        self.type = 0x2E
        self.id = id
        self.reqLen = reqLen
    def run(self, service, report):
        report.start('Write - 0x%04X' % self.id)
        data = [0] * self.reqLen
        test = report.step('Write garbage data [%s]' % data)
        resp = service.wpid(self.id, data)
        if resp.success:
            test.yay()
        else:
            test.nay(resp.errorString())
        report.complete()

# ----------------------------------------------------------------------------------------------------------------------
class Control(Test):
    def __init__(self, id):
        self.id = id
    def run(self, service, report):
        report.start('Control - 0x%04X' % self.id)
        test = report.step('Request short term adjust')
        one = [0x3F, 0x80, 0x00, 0x00] # Byte-wise representation of an IEEE single-precision float with value of 1.0
        resp = service.ioc(self.id, 0x03, one)
        if resp.success:
            test.yay()
            test = report.step('Request return control')
            resp = service.ioc(self.id, 0x00)
            if resp.success:
                test.yay()
            else:
                test.nay(resp.errorString())
        else:
            test.nay(resp.errorString())
        report.complete()



# ======================================================================================================================
# Report Classes
# ----------------------------------------------------------------------------------------------------------------------
class ReportError(Exception):
    pass

# ----------------------------------------------------------------------------------------------------------------------
class Report:
    def __init__(self, test):
        self.uuid = uuid.uuid4()
        self.test = test
        self.opened = False
    def start(self, message):
        self.opened = True
        logging.info('Starting test: %s', message)
        self.steps = []
    def step(self, message):
        if not self.opened:
            raise ReportError('Attempt to write to closed report')
        logging.debug(message)
        step = Step(message)
        self.steps.append(step)
        return step
    def complete(self):
        self.opened = False
        self.passed = True
        for step in self.steps:
            if step.status == 'Pending':
                # Report any incomplete steps
                raise ReportError('Failed to complete step %s' % step.title)
            elif step.status == 'Failed':
                # Fail this report if any step failed
                self.passed = False
        logging.info('Test complete')

# ----------------------------------------------------------------------------------------------------------------------
class Step:
    def __init__(self, title):
        self.title = title
        self.status = 'Pending'
        self.reason = None
    def yay(self, info=None):
        self.status = 'Pass'
        self.reason = info
        logging.info('Test Passed: %s' % self.title)
    def nay(self, reason):
        self.status = 'Failed'
        self.reason = reason
        logging.error('Test Failed: %s (%s)', self.title, self.reason)
    def textClass(self):
        if self.status == 'Pending':
            return 'text-warning'
        elif self.status == 'Failed':
            return 'text-danger'
        else:
            return 'text-success'
    def __repr__(self):
        return '%s: [%s]%s' % (self.title, self.status, ' (%s)' % self.reason if self.reason else '')


# ======================================================================================================================
# Configuration Class
# ----------------------------------------------------------------------------------------------------------------------
class Config:
    def __init__(self, attrs):
        self.attrs = attrs
    def check(self, key, default=False):
        key = key.lower()
        if key not in self.attrs:
            return default
        value = self.attrs.get(key).lower()
        return value in ['yes', 'true', 'on', '1']


# ======================================================================================================================
# Helper Functions
# ----------------------------------------------------------------------------------------------------------------------
def loadProgramAttributes(ecuc):
    attrs = {}
    logging.info('Reading configuration file: %s', ecuc)
    with open(ecuc) as inFile:
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
    attrs['timestamp'] = datetime.datetime.now().strftime('%d-%b-%y %H:%M %p')
    attrs['tool'] = os.path.basename(__file__)
    attrs['version'] = re.findall(r'(\d+)', VERSION)[0]
    return attrs

# ----------------------------------------------------------------------------------------------------------------------
def lookupConfig(service):
    # Get the configuration SDGs from the service if they exist
    input = {}
    for sdg in service.sdgs:
        if sdg.caption == 'OdxTestConfiguration':
            input = sdg.attrs
            break
    # Standardize the text in the SDG items (i.e. make everything lowercase for future comparisons).
    attrs = {}
    for key, value in input.iteritems():
        attrs[key.lower()] = value.lower()
    # Generate Config object to assist in lookups
    return Config(attrs)


# ======================================================================================================================
# Main Function
# ----------------------------------------------------------------------------------------------------------------------
if __name__ == "__main__":
    description = "Nxtr ODX Test Utility - EA4 Manufacturing Services"
    parser = argparse.ArgumentParser(description=description)
    parser.add_argument('-v', '--verbose', default=0, action='count', help='Output detailed information to console')
    parser.add_argument('-s', '--show', default=False, action='store_true', help='Show generated report in browser once complete')
    parser.add_argument('odx', help='Input ODX filename to generate test plan from')
    parser.add_argument('ecuc', help='Input ECUC filename to gather program information from')
    parser.add_argument('output', help='Output report filename (unconditionally overwritten)')
    args = parser.parse_args()

    # Setup logging
    logging.getLogger("MARKDOWN").setLevel(logging.WARNING)
    levels = [logging.WARNING, logging.INFO, logging.DEBUG]
    logLevel = levels[min(args.verbose, 2)]
    logging.basicConfig(level=logLevel)

    # setup service interface
    interface = libraries.iso14229.Services(0x712, 0x710)

    # Read input file
    logging.info('Reading input file: %s', args.odx)
    with open(args.odx) as inFile:
        odxText = inFile.read()
    cms = bindings.odx.CreateFromDocument(odxText)

    # Generate list of services
    variant = cms.DIAG_LAYER_CONTAINER.BASE_VARIANTS.BASE_VARIANT[0]
    services = []
    for diag in variant.DIAG_COMMS.DIAG_SERVICE:
        if '_NoResponse' not in diag.SHORT_NAME:
            service = libraries.services.Service(diag, variant)
            services.append(service)

    # Generate test plan
    tests = []
    for service in services:
        type = service.getType()
        sub = service.getSubFunction()
        id = service.getId()
        config = lookupConfig(service)
        if config.check('Ignore'):
            # if OdxTestConfiguration:Ignore == yes in the ODX, ignore this service
            logging.info('Ignoring service as configured per ODX file: %s', service)
            continue
        if type == 0x3E:
            test = Tester()
        elif type == 0x10:
            test = Session(sub)
        elif type == 0x11:
            test = Reset(sub)
        elif type == 0x22:
            respLen = service.respLen()
            test = Read(id, respLen)
        elif type == 0x2E:
            if config.check('WriteOnly'):
                reqLen = service.reqLen()
                test = Write(id, reqLen)
            else:
                test = ReadWrite(id)
        elif type == 0x31:
            if sub == 0x01:
                test = Start(id)
            elif sub == 0x02:
                test = Stop(id)
            elif sub == 0x03:
                respLen = service.respLen()
                test = Status(id, respLen)
            else:
                logging.warning('Unsupported Routine Control sub-function: %s', sub)
                continue
        elif type == 0x2F:
            test = Control(id)
        else:
            logging.warning('Unknown service type "0x%02X", not generating test case', type)
            continue
        test.name = service.long
        tests.append(test)

    # Execute test plan
    reports = []
    for test in tests:
        report = test.execute(interface)
        reports.append(report)

    # Gather program information
    attrs = loadProgramAttributes(args.ecuc)

    # Generate some statistics
    attrs['passes'] = len([report for report in reports if report.passed])
    attrs['failures'] = len([report for report in reports if not report.passed])

    # Fetch assets
    directory = os.path.dirname(os.path.realpath(__file__))
    assetDir = os.path.join(directory, 'assets')
    cssPath = os.path.join(assetDir, 'bootstrap.css')
    with open(cssPath) as file:
        css = file.read()
    attrs['css'] = csscompressor.compress(css)
    jsPath = os.path.join(assetDir, 'chart.min.js')
    with open(jsPath) as file:
        js = file.read()
    attrs['js'] = js.decode('utf-8')

    # Generate Test report
    templateDir = os.path.join(directory, 'templates')
    lookup = TemplateLookup(directories=[templateDir])
    mytemplate = lookup.get_template('OdxTestReport.arxml.tpl')
    html = mytemplate.render(reports=reports, **attrs).replace('\r', '')

    # Write output report file
    with open(args.output, 'w+') as outFile:
        outFile.write(html)
    logging.info('Output written to: %s', args.output)

    # Launch report in browser
    if args.show:
        webbrowser.open(args.output)


# End of File: OdxTest.py