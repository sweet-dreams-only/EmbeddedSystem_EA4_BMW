"""=====================================================================================================================
#      File: common.py
#   Project: EA4 Manufacturing Services
#    Author: Jared Julien <jared.julien@nexteer.com>
# Copyright: (c) 2018 Nxtr Automotive
#
# Description:
# ------------
# Common methods sharred with DcmArxmlGen.py, DcmSrcGen.py and DataDictGen.py.
#
# Date        Rev   Author    Change Description
# ==========  ====  ========  =========================================================================================
# 2018-02-02  1     Jared     Initial file creation
# -------------------------------------------------------------------------------------------------------------------"""

# ======================================================================================================================
# Routine Service Class
# ----------------------------------------------------------------------------------------------------------------------
class Routine(object):
    """Routine class provides a model that represents a routine (type 0x31) service."""
    # pylint: disable=R0903
    # This is a class that represents a data model.  Because it represents a routine service object with attributes we
    # do not with to remove it nor do we have any additional public methods that need to be supported for this
    # application.
    def __init__(self, sid):
        self.sid = sid
        self.start = None
        self.stop = None
        self.result = None

    def __repr__(self):
        parts = ['Routine']
        parts.append('ID=0x%04X' % self.sid)
        if self.start:
            if self.start.in_length > 0:
                parts.append('start_in=%d' % self.start.in_length)
            if self.start.out_length > 0:
                parts.append('start_out=%d' % self.start.out_length)
        if self.stop:
            if self.stop.in_length > 0:
                parts.append('stop_in=%d' % self.stop.in_length)
            if self.stop.out_length > 0:
                parts.append('stop_out=%d' % self.stop.out_length)
        if self.result:
            if self.result.in_length > 0:
                parts.append('result_in=%d' % self.result.in_length)
            if self.result.out_length > 0:
                parts.append('result_out=%d' % self.result.out_length)
        return '<' + ' '.join(parts) + '>'

# ----------------------------------------------------------------------------------------------------------------------
class GenericService(object):
    """Generic service is a parent class for PID (type 0x22 and 0x2E) and IOC (type 0x2F) services."""
    def __init__(self, sid):
        self.sid = sid
        self.take = None
        self.release = None
        self.read = None
        self.write = None

    @property
    def length(self):
        """Return the length of the service which will be the output length of the read, if present, or the input length
        of the write, if present, or the input length of the take control function, if present; whichever is found
        first.  The expectation is that the data is symmetrical for all generic services so it does not matter which of
        the lengths is returned, they should all be the same when present."""
        if self.read:
            return self.read.out_length
        elif self.write:
            return self.write.in_length
        elif self.take:
            return self.take.in_length
        raise ValueError('Unable to determine length for this service')

    @property
    def bytes(self):
        """Return the length of the service in bytes.  Same logic applies as in `length` property."""
        return (self.length + 7) // 8

# ----------------------------------------------------------------------------------------------------------------------
class IOC(GenericService):
    """A model for IOC (type 0x2F) services."""
    def __repr__(self):
        parts = ['IOC']
        parts.append('ID=0x%04X' % self.sid)
        if self.take:
            if self.take.in_length > 0:
                parts.append('take_in=%d' % self.take.in_length)
            if self.take.out_length > 0:
                parts.append('stake_out=%d' % self.take.out_length)
        if self.release:
            if self.release.in_length > 0:
                parts.append('release_in=%d' % self.release.in_length)
            if self.release.out_length > 0:
                parts.append('release_out=%d' % self.release.out_length)
        return '<' + ' '.join(parts) + '>'

# ----------------------------------------------------------------------------------------------------------------------
class PID(GenericService):
    """A model for PID (type 0x22 and 0x2E) services."""
    def __repr__(self):
        parts = ['PID']
        parts.append('ID=0x%04X' % self.sid)
        if self.read:
            if self.read.out_length > 0:
                parts.append('read_out=%d' % self.read.out_length)
        if self.write:
            if self.write.in_length > 0:
                parts.append('write_in=%d' % self.write.in_length)
        return '<' + ' '.join(parts) + '>'


# ----------------------------------------------------------------------------------------------------------------------
class Request(object):
    """A model for any request made to a controller via a service.  This could be a start or stop for a routine service
    or a read or write of a PID ot a take or return control for an IOC service."""
    def __init__(self):
        self.inputs = []
        self.outputs = []

    @property
    def in_length(self):
        """Return the total length (in bits) of the inputs associated with this request."""
        return sum([inp.length for inp in self.inputs])

    @property
    def out_length(self):
        """Return the total length (in bits) of all the outputs associated with this request."""
        return sum([output.length for output in self.outputs])

    @property
    def in_bytes(self):
        """Return the total length (in bytes) of the inputs associated with this request."""
        return (self.in_length + 7) // 8

    @property
    def out_bytes(self):
        """Return the total length (in bytes) of the outputs associated with this request."""
        return (self.out_length + 7) // 8


# ----------------------------------------------------------------------------------------------------------------------
class Parameter(object):
    """A model class that represents a single input or output parameter.  And given request may may zero or more
    parameters in either or both of it's input or output lists."""
    # pylint: disable=R0903
    # This class represents a data model for which cannot be removed nor are there any public methods to be added.
    def __init__(self, name='', length=0):
        self.name = name
        self.length = length


# ======================================================================================================================
# Helper Functions
# ----------------------------------------------------------------------------------------------------------------------
def parse_params(request):
    """Helper function used to parse a generic list of parameters for the input request."""
    params = []
    for param in request.params:
        params.append(Parameter(param.short, param.dataLength()))
    return params

# ----------------------------------------------------------------------------------------------------------------------
def parse_routines(services):
    """Given a list of services, parse and return a list of type 0x31 routine services only."""
    routines = {}
    for service in services:
        serviceType = service.request.getServiceType()
        if serviceType != 0x31:
            # Skip and service that is not a routine service.
            continue
        sid = service.request.getServiceId()
        if sid in routines:
            # Get the existing service to merge these details into.
            routine = routines[sid]
        else:
            # Create a new service and add it to the list of groups.
            routine = Routine(sid)
            routines[sid] = routine
        sub = service.request.getSubFunction()

        if sub == 0x01:
            routine.start = Request()
            routine.start.inputs = parse_params(service.request)
            routine.start.outputs = parse_params(service.positive)
        elif sub == 0x02:
            routine.stop = Request()
            routine.stop.inputs = parse_params(service.request)
            routine.stop.outputs = parse_params(service.positive)
        elif sub == 0x03:
            routine.result = Request()
            routine.result.inputs = parse_params(service.request)
            routine.result.outputs = parse_params(service.positive)
    # Convert the grouped services into a list sorted by service ID.
    return [routines[key] for key in sorted(routines.keys())]

# ----------------------------------------------------------------------------------------------------------------------
def parse_iocs(services):
    """Given a list of services, parse and return a list of type 0x2F input/output control service only."""
    iocs = {}
    for service in services:
        serviceType = service.request.getServiceType()
        if serviceType != 0x2F:
            # Skip and service that is not an I/O control service.
            continue
        sid = service.request.getServiceId()
        if sid in iocs:
            # Get the existing service to merge these details into.
            ioc = iocs[sid]
        else:
            # Create a new service and add it to the list of groups.
            ioc = IOC(sid)
            iocs[sid] = ioc
        sub = service.request.getSubFunction()
        if sub == 0x00:
            ioc.release = Request()
            ioc.release.inputs = parse_params(service.request)
            ioc.release.outputs = parse_params(service.positive)
        elif sub == 0x03:
            ioc.take = Request()
            ioc.take.inputs = parse_params(service.request)
            ioc.take.outputs = parse_params(service.positive)
    # Convert the grouped services into a list sorted by service ID.
    return [iocs[key] for key in sorted(iocs.keys())]

# ----------------------------------------------------------------------------------------------------------------------
def parse_pids(services):
    """Given a list of services, parse and return a list of type 0x22 and 0x2E read/write services only."""
    pids = {}
    for service in services:
        serviceType = service.request.getServiceType()
        if serviceType not in [0x22, 0x2E]:
            # Skip and service that is not an I/O control service.
            continue
        sid = service.request.getServiceId()
        if sid in pids:
            # Get the existing service to merge these details into.
            pid = pids[sid]
        else:
            # Create a new service and add it to the list of groups.
            pid = PID(sid)
            pids[sid] = pid
        if serviceType == 0x22:
            pid.read = Request()
            pid.read.inputs = parse_params(service.request)
            pid.read.outputs = parse_params(service.positive)
        elif serviceType == 0x2E:
            pid.write = Request()
            pid.write.inputs = parse_params(service.request)
            pid.write.outputs = parse_params(service.positive)
    # Convert the grouped services into a list sorted by service ID.
    return [pids[key] for key in sorted(pids.keys())]


# End of File: common.py
