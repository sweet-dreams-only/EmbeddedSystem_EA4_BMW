# ======================================================================================================================
#      File: services.py
#   Project: EA4 Manufacturing Services
#   Created: 2015-11-16
#  Modified: 2015-11-16
#    Author: Jared Julien
#     Email: jared.julien@nexteer.com
# Copyright: (c) 2015 Nxtr Automotive
#
# Description:
# ------------
# This shared resource is used when parsing services from an ODX file.  Invoking the service class and passing a
# service instance and base variant to the constructor is all that is needed to parse a service into handy Python
# objects.
#
# Date        Rev   Author    Change Description
# ==========  ====  ========  =========================================================================================
# 2015-11-16  1     Jared     Initial file creation
# 2017-07-27  2     Jared     Added support for type 0x2A services
# ----------------------------------------------------------------------------------------------------------------------
# ======================================================================================================================
# Import Statements
# ----------------------------------------------------------------------------------------------------------------------
import re

import markdown # https://pypi.python.org/pypi/Markdown

import bindings.odx


# ======================================================================================================================
# Constants
# ----------------------------------------------------------------------------------------------------------------------
TYPE_MAP = {
    0x10: {
        0x01: 'Dflt',
        0x7E: 'Nxtr',
    },
    0x11: {
        0x60: 'Soft',
        0x61: 'Hard',
    },
    0x27: {
        0x61: 'Seed',
        0x62: 'Key',
    },
    0x2A: {
        0x01: 'Fast',
        0x02: 'Med',
        0x03: 'Slow',
        0x04: 'Stop',
    },
    0x31: {
        0x01: 'Strt',
        0x02: 'Stop',
        0x03: 'Sts',
        0x81: 'StrtNoRsp',
        0x82: 'StopNoRsp',
        0x83: 'StsNoRsp',
    },
    0x2F: {
        0x00: 'Rtn',
        0x03: 'Adj',
    },
}

NRCS = {
    0x00: 'Positive response',
    0x11: 'Service not supported',
    0x12: 'Sub-function not supported',
    0x13: 'Invalid length or format',
    0x22: 'Conditions not correct',
    0x24: 'Request sequence error',
    0x31: 'Request out of range',
    0x33: 'Security access denied',
    0x35: 'Invalid key',
    0x36: 'Exceeded number of attempts',
    0x37: 'Time delay not expired',
    0x78: 'Request received, response pending',
    0x7E: 'Sub-function not supported in current session',
    0x7F: 'Service not supported in current session',
    0x81: 'RPM too high',
    0x82: 'RPM too low',
    0x83: 'Engine running',
    0x84: 'Engine not running',
    0x85: 'Engine run time too low',
    0x86: 'Temperature too high',
    0x87: 'Temperature too low',
    0x88: 'Vehicle speed too high',
    0x89: 'Vehicle speed too low',
    0x8A: 'Throttle too high',
    0x8B: 'Throttle too low',
    0x8C: 'Transmission not in neutral',
    0x8D: 'Transmission not in gear',
    0x8F: 'Brake not applied',
    0x90: 'Transmission not in park',
    0x92: 'Voltage too high',
    0x93: 'Voltage too low',
}


# ======================================================================================================================
# Service Class
# ----------------------------------------------------------------------------------------------------------------------
class Generic:
    def __init__(self, input):
        try:
            self.id = input.ID
        except AttributeError:
            self.id = None
        self.short = input.SHORT_NAME
        self.long = input.LONG_NAME.value() if input.LONG_NAME else None
        # Description seems to be nested inside of references, this mess seems to reliably extract it if it exists
        desc = input.DESC.orderedContent()[0].value.orderedContent()[0].value if input.DESC else ''
        self.desc = markdown.markdown(desc, extensions=['extra'])
    def lookup(self, id, input):
        for request in input:
            if request.ID == id:
                return request
        return None
    def lookupState(self, id, variant):
        for chart in variant.STATE_CHARTS.STATE_CHART:
            for state in chart.STATES.STATE:
                if state.ID == id:
                    return chart, state

# ----------------------------------------------------------------------------------------------------------------------
class Service(Generic):
    def __init__(self, service, variant):
        Generic.__init__(self, service)
        self.preReqs = []
        self.semantic = service.SEMANTIC
        if service.PRE_CONDITION_STATE_REFS is not None:
            for preReq in service.PRE_CONDITION_STATE_REFS.PRE_CONDITION_STATE_REF:
                chart, state = self.lookupState(preReq.ID_REF, variant)
                preCond = PreCondition(chart, state)
                self.preReqs.append(preCond)
        self.request = Request(self.lookup(service.REQUEST_REF.ID_REF, variant.REQUESTS.REQUEST), variant)
        self.positive = Response(self.lookup(service.POS_RESPONSE_REFS.POS_RESPONSE_REF[0].ID_REF, variant.POS_RESPONSES.POS_RESPONSE), variant)
        self.negative = []
        for ref in service.NEG_RESPONSE_REFS.NEG_RESPONSE_REF:
            negative = Response(self.lookup(ref.ID_REF, variant.NEG_RESPONSES.NEG_RESPONSE), variant)
            self.negative.append(negative)
        self.sdgs = []
        for group in service.SDGS.SDG:
            sdg = SDG(group)
            self.sdgs.append(sdg)
    def __repr__(self):
        type = self.getType()
        id = self.getId()
        sub = self.getSubFunction()
        txt = '<Service '
        if type is not None:
            txt += 'type=0x%02X ' % type
        if sub is not None:
            txt += 'sub=0x%02X ' % sub
        if id is not None:
            txt += 'id=0x%04X ' % id
        return txt.strip() + '>'
    # ------------------------------------------------------------------------------------------------------------------
    def getId(self):
        return self.request.getServiceId()
    def getType(self):
        return self.request.getServiceType()
    def getSubFunction(self):
        return self.request.getSubFunction()
    def getSubStr(self):
        type = self.getType()
        subInt = self.getSubFunction()
        if subInt is None:
            sub = ''
        else:
            mapping = TYPE_MAP.get(type, {})
            sub = mapping.get(subInt, re.sub('[^0-9a-zA-Z]+', '_', self.short))
        return sub
    def getTypeStr(self):
        mapping = {
            0x10: 'Session',
            0x11: 'Rst',
            0x22: 'Rd',
            0x27: 'Secu',
            0x2A: 'Per',
            0x2E: 'Wr',
            0x2F: 'Ctrl',
            0x31: 'Routine',
        }
        return mapping.get(self.getType(), '')
    # ------------------------------------------------------------------------------------------------------------------
    def title(self):
        id = self.getId()
        if id is None:
            id = ''
        else:
            id = '%04X' % id
        sub = self.getSubStr()
        type = self.getTypeStr()
        return 'Srv%s%s%s' % (id, type, sub)
    def type(self):
        mapping = {
            0x10: 'Session',
            0x11: 'Reset',
            0x22: 'Read',
            0x27: 'Security',
            0x2A: 'Periodic',
            0x2E: 'Write',
            0x2F: 'Control',
            0x31: 'Routine',
            0x3E: 'TesterPresent',
        }
        type = self.getType()
        text = mapping.get(type)
        return '%s - 0x%02X' % (text, type)
    def _formatLength(self, length):
        if length == 1:
            return '1 byte'
        return '%d bytes' % length
    def reqLen(self):
        return self.request.dataLength()
    def respLen(self):
        return self.positive.dataLength()
    def reqLenStr(self):
        return self._formatLength(self.reqLen())
    def respLenStr(self):
        return self._formatLength(self.respLen())
    def serviceId(self):
        return self.getId()
    def subFunction(self):
        return self.getSubFunction()
    def nexteerSession(self):
        for preReq in self.preReqs:
            if preReq.short == 'Nxtr':
                return True
        return False
    def securityAccess(self):
        for preReq in self.preReqs:
            if preReq.short == 'Unlocked':
                return True
        return False

# ----------------------------------------------------------------------------------------------------------------------
class PreCondition(Generic):
    def __init__(self, chart, state):
        Generic.__init__(self, state)
        self.chart = chart

# ----------------------------------------------------------------------------------------------------------------------
class GenericParams(Generic):
    def __init__(self, input, variant):
        Generic.__init__(self, input)
        self.params = []
        for param in input.PARAMS.PARAM:
            self.params.append(Param(param, variant))
    def dataLength(self):
        bytes = 0
        for param in self.params:
            bytes += int((param.dataLength() + 7) / 8)
        return bytes
    def nrc(self):
        for param in self.params:
            if param.type == 'NRC':
                return param.nrc
        return None
    def nrcStr(self):
        nrc = self.nrc()
        if nrc is not None:
            text = NRCS[nrc]
            nrc = '0x%02X: %s' % (nrc, text)
        return nrc

# ----------------------------------------------------------------------------------------------------------------------
class Request(GenericParams):
    def __init__(self, request, variant):
        GenericParams.__init__(self, request, variant)
    def getServiceId(self):
        id = 0
        type = self.getServiceType()
        for param in self.params:
            if param.semantic == 'ID':
                id <<= 8
                id |= int(param.value)
                if type == 0x2F:
                    # Special case for the I/O control services which provide the sub-function as an ID so we
                    # force a break from the loop after the first ID parameter is found.
                    break
        return id if id > 0 else None
    def getServiceType(self):
        for param in self.params:
            if param.semantic == 'SERVICE-ID':
                return int(param.value)
    def getSubFunction(self):
        if self.getServiceType() == 0x2F:
            # 0x2F services refer to their sub-function as an ID - but it is one of two (the first being the actual ID).
            # This special case looks for the last ID specified in the request and uses that as the sub-function for
            # type 0x2F services.
            for param in reversed(self.params):
                if param.semantic == 'ID':
                    return int(param.value)
        else:
            for param in self.params:
                if param.semantic in ['SUBFUNCTION', 'ACCESSMODE']:
                    return int(param.value)

# ----------------------------------------------------------------------------------------------------------------------
class Response(GenericParams):
    def __init__(self, response, variant):
        GenericParams.__init__(self, response, variant)

# ----------------------------------------------------------------------------------------------------------------------
class Param(Generic):
    def __init__(self, param, variant):
        Generic.__init__(self, param)
        self.semantic = param.SEMANTIC
        self.position = param.BYTE_POSITION
        try:
            self.bit = param.BIT_POSITION
        except AttributeError:
            self.bit = 0
        try:
            self.bits = param.BIT_LENGTH
        except AttributeError:
            self.bits = 1
        if isinstance(param, bindings.odx.CODED_CONST):
            self.type = 'CONST'
            self.value = int(param.CODED_VALUE)
            self.length = param.DIAG_CODED_TYPE.BIT_LENGTH
            self.baseType = param.DIAG_CODED_TYPE.BASE_DATA_TYPE
        elif isinstance(param, bindings.odx.NRC_CONST):
            self.type = 'NRC'
            self.value = int(param.CODED_VALUES.CODED_VALUE[0])
            self.nrc = self.value
            self.length = param.DIAG_CODED_TYPE.BIT_LENGTH
            self.baseType = param.DIAG_CODED_TYPE.BASE_DATA_TYPE
        elif isinstance(param, bindings.odx.RESERVED):
            self.type = 'RESERVED'
            self.bytePosition = param.BYTE_POSITION
            self.bitPosition = param.BIT_POSITION
            self.length = param.BIT_LENGTH
            self.value = None
        else:
            self.type = 'VALUE'
            ref = param.DOP_REF.ID_REF
            dop = self.lookup(ref, variant.DIAG_DATA_DICTIONARY_SPEC.DATA_OBJECT_PROPS.DATA_OBJECT_PROP)
            if dop is not None:
                self.dop = DOP(dop, variant)
            else:
                struct = self.lookup(ref, variant.DIAG_DATA_DICTIONARY_SPEC.STRUCTURES.STRUCTURE)
                if struct is None:
                    raise ReferenceError('Cannot find reference "%s"' % ref)
                self.dop = Structure(struct, variant)
    def dataLength(self):
        if self.type == 'VALUE':
            return self.dop.length
        else:
            return 0

# ----------------------------------------------------------------------------------------------------------------------
class DOP(Generic):
    def __init__(self, dop, variant):
        Generic.__init__(self, dop)
        self.length = dop.DIAG_CODED_TYPE.BIT_LENGTH
        self.bytes = int(self.length / 8)
        self.baseType = dop.DIAG_CODED_TYPE.BASE_DATA_TYPE
        try:
            scale = dop.COMPU_METHOD.COMPU_INTERNAL_TO_PHYS.COMPU_SCALES.COMPU_SCALE[0]
            self.lower = scale.LOWER_LIMIT.value()
            self.upper = scale.UPPER_LIMIT.value()
        except AttributeError:
            self.lower = None
            self.upper = None
        try:
            units = self.lookup(dop.UNIT_REF.ID_REF, variant.DIAG_DATA_DICTIONARY_SPEC.UNIT_SPEC.UNITS.UNIT)
            self.units = units.DISPLAY_NAME
        except AttributeError:
            self.units = None
        try:
            coeffs = dop.COMPU_METHOD.COMPU_INTERNAL_TO_PHYS.COMPU_SCALES.COMPU_SCALE[0].COMPU_RATIONAL_COEFFS
            self.numerator = coeffs.COMPU_NUMERATOR.V[1].value()
            # I can't explain the next line - sometimes the auto-generated schemas are really confusing...
            self.denominator = coeffs.COMPU_DENOMINATOR.orderedContent()[0].value.value()
            self.offset = None
        except AttributeError:
            self.numerator = None
            self.denominator = None
            self.offset = None
    def printFloat(self, value):
        if int(value) == float(value):
            return str(int(value))
        return str(value)
    def details(self):
        text = ''
        if self.units is not None:
            text += ' [%s]' % self.units
        if self.lower is not None and self.upper is not None:
            text += ' (%s, %s)' % (self.lower, self.upper)
        if self.numerator is not None or self.denominator is not None or self.offset is not None:
            text += ' {'
            if self.numerator is None and self.denominator is not None:
                text += '/%s' % self.printFloat(self.denominator)
            elif self.numerator is not None and self.denominator is None:
                text += '*%s' % self.printFloat(self.numerator)
            elif self.numerator is not None and self.denominator is not None:
                text += '*%s/%s' % (self.printFloat(self.numerator), self.printFloat(self.denominator))
            if self.offset is not None:
                text += ' +' if self.offset > 0 else ' '
                test += str(self.offset)
            text = text + '}'
        return text

# ----------------------------------------------------------------------------------------------------------------------
class Structure(GenericParams):
    def __init__(self, struct, variant):
        GenericParams.__init__(self, struct, variant)
        self.bytes = struct.BYTE_SIZE
        self.length = self.bytes * 8

# ----------------------------------------------------------------------------------------------------------------------
class SDG:
    def __init__(self, sdg):
        self.caption = sdg.SDG_CAPTION.SHORT_NAME
        self.attrs = {}
        for sd in sdg.SD:
            key = sd.SI
            value = sd.value()
            self.attrs[key] = value


# End of File: services.py