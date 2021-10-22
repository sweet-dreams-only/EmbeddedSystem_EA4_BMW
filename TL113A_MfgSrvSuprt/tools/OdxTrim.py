# ======================================================================================================================
#      File: OdxTrim.py
#   Project: EA4 Manufacturing Services
#   Created: 2016-01-26
#  Modified: 2016-01-26
#    Author: Jared Julien
#     Email: jared.julien@nexteer.com
# Copyright: (c) 2016 Nxtr Automotive
#
# Description:
# ------------
# OdxTrim takes two input files, an ODX listing common manufacturing files and an ECUC ARXML listing CMS configuration
# for an integration project.  The tool then removes all services from the ODX that are not Enabled in the ARXML file
# and writes the result to a new ODX file.  This tool is intended to be run during the configuration generation step
# in Configurator to generate an ODX listing services that are applicable to a given software configuration.
#
# Date        Rev   Author    Change Description
# ==========  ====  ========  =========================================================================================
# 2016-01-26  1     Jared     Initial file creation
# ----------------------------------------------------------------------------------------------------------------------
# ======================================================================================================================
# Import Statements
# ----------------------------------------------------------------------------------------------------------------------
from xml.dom import minidom
import argparse
import logging
import sys

import bindings.autosar4
import bindings.odx



# ======================================================================================================================
# Helper Classes
# ----------------------------------------------------------------------------------------------------------------------
class Service:
    def __init__(self, type=None, sub=None, id=None, request=None):
        self.type = type
        self.sub = sub
        self.id = id
        if request is not None:
            for param in request.PARAMS.PARAM:
                if param.SEMANTIC == 'SERVICE-ID':
                    self.type = int(param.CODED_VALUE)
                elif param.SEMANTIC == 'SUBFUNCTION':
                    self.sub = int(param.CODED_VALUE)
                elif param.SEMANTIC == 'ID':
                    self.id = int(param.CODED_VALUE)
    def __repr__(self):
        txt = '<Service '
        if self.type is not None:
            txt += 'type=0x%02X ' % self.type
        if self.sub is not None:
            txt += 'sub=0x%02X ' % self.sub
        if self.id is not None:
            txt += 'id=0x%04X ' % self.id
        return txt.strip() + '>'
    def __eq__(self, other):
        # Services are equal when all of their attributes are the same.
        if self.id != other.id:
            return False
        elif self.type != other.type:
            return False
        elif self.sub is None or other.sub is None:
            # if one sub function is None, equality would expect both to be None
            return self.sub == other.sub
        else:
            # Otherwise, ignore the "suppress positive response" bit
            return (self.sub & 0x7F) == (other.sub & 0x7F)


# ======================================================================================================================
# Helper Functions
# ----------------------------------------------------------------------------------------------------------------------
def lookup(id, group):
    """Lookup an item by id within a group of items."""
    for item in group:
        if item.ID == id:
            return item
    return None

# ----------------------------------------------------------------------------------------------------------------------
def parseService(variant, service):
    """Parse a service object from a specified DIAG-SERVICE entry in an ODX container."""
    request = lookup(service.REQUEST_REF.ID_REF, variant.REQUESTS.REQUEST)
    return Service(request=request)

# ----------------------------------------------------------------------------------------------------------------------
def getEnabledServices(ecuc):
    """Given an ARMXL ECUC configuration, determine a list of enabled services."""
    services = []
    for module in ecuc.AR_PACKAGES.AR_PACKAGE[0].ELEMENTS.ECUC_MODULE_CONFIGURATION_VALUES:
        if module.SHORT_NAME.value() == 'NxtrMfgSrv':
            logging.info('Found expected module: %s', module.SHORT_NAME.value())
            for container in module.CONTAINERS.ECUC_CONTAINER_VALUE:
                if container.DEFINITION_REF.value() in ['/Nxtr/NxtrMfgSrv/CommonService', '/Nxtr/NxtrMfgSrv/ProgramSpecificService']:
                    category = container.DEFINITION_REF.value().rsplit('/', 1)[1]
                    enabled = False
                    service = Service()
                    for parameter in container.PARAMETER_VALUES.ECUC_TEXTUAL_PARAM_VALUE:
                        if parameter.DEFINITION_REF.value() == '/Nxtr/NxtrMfgSrv/%s/ServiceType' % category:
                            service.type = int(parameter.VALUE.value()[-2:], 16)
                    for parameter in container.PARAMETER_VALUES.ECUC_NUMERICAL_PARAM_VALUE:
                        if parameter.DEFINITION_REF.value() == '/Nxtr/NxtrMfgSrv/%s/Enabled' % category:
                            enabled = parameter.VALUE.orderedContent()[0].value == 'true'
                        if parameter.DEFINITION_REF.value() == '/Nxtr/NxtrMfgSrv/%s/ServiceId' % category:
                            service.id = int(parameter.VALUE.orderedContent()[0].value)
                        if parameter.DEFINITION_REF.value() == '/Nxtr/NxtrMfgSrv/%s/SubFunction' % category:
                            service.sub = int(parameter.VALUE.orderedContent()[0].value)
                    if enabled:
                        logging.debug('Found Service: %s', service)
                        services.append(service)
    logging.info('Found %d enabled services', len(services))
    return services


# ======================================================================================================================
# Main Function
# ----------------------------------------------------------------------------------------------------------------------
if __name__ == "__main__":
    description = "Nxtr ODX Trimming Utility - EA4 Manufacturing Services"
    parser = argparse.ArgumentParser(description=description)
    parser.add_argument('-v', '--verbose', default=0, action='count', help='Output detailed information to console')
    parser.add_argument('input', help='Input merged ODX filename to be trimmed')
    parser.add_argument('ecuc', help='Input ECUC filename defining service configuration')
    parser.add_argument('output', help='Output trimmed ODX filename')
    args = parser.parse_args()

    # Setup logging
    levels = [logging.WARNING, logging.INFO, logging.DEBUG]
    logLevel = levels[min(args.verbose, 2)]
    logging.basicConfig(level=logLevel)

    # Read input file
    logging.info('Reading input file: %s', args.input)
    with open(args.input) as inFile:
        input = inFile.read()
    cms = bindings.odx.CreateFromDocument(input)

    # Read ECUC configuration
    logging.info('Reading configuration file: %s', args.ecuc)
    with open(args.ecuc) as inFile:
        input = inFile.read()
    ecuc = bindings.autosar4.CreateFromDocument(input)

    # Get list of enabled services
    enabledServices = getEnabledServices(ecuc)
    if len(enabledServices) == 0:
        logging.critical('Unable to locate enabled services, aborting')
        sys.exit(100)

    # Reduce input file to only those services enabled in the ECUC configuration
    variant = cms.DIAG_LAYER_CONTAINER.BASE_VARIANTS.BASE_VARIANT[0]
    # make a COPY of enabled services into missing container to keep track of those that are not found in the ODX
    missingServices = list(enabledServices)
    unusedServices = []
    for diagService in variant.DIAG_COMMS.DIAG_SERVICE:
        service = parseService(variant, diagService)
        if service not in enabledServices:
            # Aggregate a list to be removed - removing them during iteration of the list leads to problems
            unusedServices.append(diagService)
            logging.debug('Marking service for removal: %s', service)
        if service in missingServices:
            missingServices.remove(service)

    # Run through list and actually remove the services that were marked as unused
    for diagService in unusedServices:
        service = parseService(variant, diagService)
        logging.debug('Removing disabled service from ODX: %s', service)
        variant.DIAG_COMMS.DIAG_SERVICE.remove(diagService)
        # TODO: This only removes the DIAG-SERVICE and none of it's linked resources like requests and responses.  It
        # would be cleaner to determine if any of them were being used by other services and if not, remove them too.

    # Warn about services that are enabled in the ECUC configuration but not found in the ODX
    for service in missingServices:
        logging.warning('Service defined in ECUC but not found in ODX %s', service)

    # Write output file
    logging.info('Writing output file: %s', args.output)
    string = cms.toxml('utf-8', element_name='ODX')
    pretty = minidom.parseString(string).toprettyxml()
    with open(args.output, 'w+') as outFile:
        outFile.write(pretty.encode('utf-8'))


# End of File: OdxTrim.py