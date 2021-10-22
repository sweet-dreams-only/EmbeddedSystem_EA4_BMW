# ======================================================================================================================
#      File: services.py
#   Project: Nxtr Python Library
#   Created: 2013-05-01
#  Modified: 2015-12-01
#    Author: Jared Julien
#     Email: jared.julien@nexteer.com
# Copyright: (c) 2013-2015 Neexter Automotive
#
# This library implements ISO 1429 for unified diagnostic services.  It provides generic functions for invoking services
# on the target hardware.
#
# Date        Rev   Author    Change Description
# ==========  ====  ========  =========================================================================================
# 2013-05-01  1     Jared     Initial file creation
# 2013-05-06  2     Jared     Added function for reset service (0x11)
# ----------------------------------------------------------------------------------------------------------------------

# ======================================================================================================================
# Import Statements
# ----------------------------------------------------------------------------------------------------------------------
import iso15765 as transport


# ======================================================================================================================
# Constants
# ----------------------------------------------------------------------------------------------------------------------
NegativeResponseCodes = {
	0x00: 'Positive Response',
	0x11: 'Service Not Supported',
	0x12: 'Sub-Function Not Supported',
	0x13: 'Incorrect Length',
	0x22: 'Conditions Not Correct',
	0x24: 'Request Sequence Error',
	0x31: 'Request out of Range',
	0x33: 'Security Access Denied',
	0x35: 'Invalid Key',
	0x36: 'Exceeded Number of Attempts',
	0x37: 'Time Delay not Expired',
	0x78: 'Request Received - Response Pending',
	0x7E: 'Sub-Function not Supported in Current Session',
	0x7F: 'Service not Supported in Current Session',
	0x81: 'RPM Too High',
	0x82: 'RPM Too Low',
	0x83: 'Engine Running',
	0x84: 'Engine Not Running',
	0x85: 'Engine Run Time too Low',
	0x86: 'Temperature too High',
	0x87: 'Temperature too Low',
	0x88: 'Vehicle Speed too High',
	0x89: 'Vehicle Speed too Low',
	0x8A: 'Throttle too High',
	0x8B: 'Throttle too Low',
	0x8C: 'Transmission not in Neutral',
	0x8D: 'Transmission not in Gear',
	0x8F: 'Brake not Applied',
	0x90: 'Transmission not in Park',
	0x92: 'Voltage too High',
	0x93: 'Voltage too Low',
}


# ======================================================================================================================
# Response Object
# ----------------------------------------------------------------------------------------------------------------------
# Object used as response from all services.  Contains return data and/or negative response codes.
class Response(object):
    id = 0x0000
    data = []
    success = True
    nrc = 0
    def __init__(self, id):
        self.id = id
    def errorString(self):
        text = NegativeResponseCodes.get(self.nrc, 'unknown negative response code')
        return 'NRC $%X: %s' % (self.nrc, text)
    def __repr__(self):
        if self.success:
            if len(self.data) > 0:
                return '<OK: %s>' % ', '.join([('0x%02X' % s) for s in self.data])
            else:
                return '<OK>'
        else:
            return '<ERROR: %s>' % self.errorString()

# ======================================================================================================================
# Services Class
# ----------------------------------------------------------------------------------------------------------------------
class Services:
    def __init__(self, reqId, respId):
        self.transport = transport.Transport(reqId=reqId, respId=respId)
    def session(self, session):
        self.transport.request([0x10, session])
        data = self.transport.response()
        resp = Response(id)
        if len(data) >= 2 and data[0] == 0x50 and data[1] == session:
            resp.success = True
            if len(data) > 2:
                p2 = (data[2] << 8) | data[3]
                p2e = ((data[4] << 8) | data[5]) * 10
                resp.data = [p2, p2e]
        elif len(data) == 1 and data[0] == 0x50:
            # GM programs do not return anything more than 0x50 for positive response
            resp.success = True
        else:
            # print 'Length: %s' % len(data)
            resp.success = False
            if len(data) >= 3:
                resp.nrc = data[2]
        return resp
    def tester(self, sub=0x00):
        self.transport.request([0x3E, sub])
        data = self.transport.response()
        resp = Response(sub)
        if len(data) == 2 and data[0] == 0x7E and data[1] == sub:
            resp.success = True
        else:
            resp.success = False
            if len(data) >= 3:
                resp.nrc = data[2]
        return resp
    def seed(self, id):
        self.transport.request([0x27, id])
        data = self.transport.response()
        resp = Response(id)
        if len(data) == 7 and data[0] == 0x67 and data[1] == id:
            resp.success = True
            resp.data = data[2:]
        else:
            resp.success = False
            resp.nrc = data[2]
        return resp
    def key(self, id, key):
        self.transport.request([0x27, id] + key)
        data = self.transport.response()
        resp = Response(id)
        if len(data) == 2 and data[0] == 0x67 and data[1] == id:
            resp.success = True
        else:
            resp.success = False
            resp.nrc = data[2]
        return resp
    def reset(self, id):
        self.transport.request([0x11, id & 0xFF])
        data = self.transport.response()
        resp = Response(id)
        if data[0] == 0x51 and data[1] == (id & 0xFF):
            resp.success = True
            resp.data = data[2:]
        else:
            resp.success = False
            resp.nrc = data[2]
        return resp
    def rpid(self, id):
        self.transport.request([0x22, (id >> 8) & 0xFF, id & 0xFF])
        data = self.transport.response()
        resp = Response(id)
        if data[0] == 0x62 and ((data[1] << 8) | data[2]) == id:
            resp.success = True
            resp.data = data[3:]
        else:
            resp.success = False
            resp.nrc = data[2]
        return resp
    def wpid(self, id, data):
        buf = [0x2E, (id >> 8) & 0xFF, id & 0xFF]
        buf.extend(data)
        self.transport.request(buf)
        data = self.transport.response()
        resp = Response(id)
        if data[0] == 0x6E and ((data[1] << 8) | data[2]) == id:
            resp.success = True
        else:
            resp.success = False
            resp.nrc = data[2]
        return resp
    def ioc(self, id, control, data=[]):
        buf = [0x2F, (id >> 8) & 0xFF, id & 0xFF, control]
        buf.extend(data)
        self.transport.request(buf)
        data = self.transport.response()
        resp = Response(id)
        if data[0] == 0x6F and ((data[1] << 8) | data[2]) == id:
            resp.success = True
        else:
            resp.success = False
            resp.nrc = data[2]
        return resp
    def rid(self, id, subFunc, data=[]):
        buf = [0x31, subFunc, (id >> 8) & 0xFF, id & 0xFF]
        buf.extend(data)
        self.transport.request(buf)
        data = self.transport.response()
        resp = Response(id)
        if data[0] == 0x71 and data[1] == subFunc and ((data[2] << 8) | data[3]) == id:
            resp.success = True
            resp.data = data[4:]
        else:
            resp.success = False
            resp.nrc = data[2]
        return resp


# End of File: iso14229.py