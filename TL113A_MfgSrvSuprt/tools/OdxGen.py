# ======================================================================================================================
#      File: OdxGen.py
#   Project: EA4 Manufacturing Services
#   Created: 2016-01-26
#  Modified: 2017-07-27
#    Author: Jared Julien
#     Email: jared.julien@nexteer.com
# Copyright: (c) 2016 Nxtr Automotive
#
# Description:
# ------------
# OdxGen takes in an ODX file describing services and generates source templates and contract header files.  This tool
# was developed for use with the Nxtr manufacturing services components, both common and program specific.
#
# Date        Rev   Author    Change Description
# ==========  ====  ========  =========================================================================================
# 2016-01-26  1     Jared     Initial file creation
# 2016-12-13  2     Jared     Corrected the ID value used in service function generation for services w/o ID
#                             Corrected the name of the reset services file to match Autosar 4 naming conventions
#                             Moved backup function to library to facilitate re-use with other scripts
#                             Removed my user name from the file generation template
#                             Added support for periodic read (type 0x2A) services
# ----------------------------------------------------------------------------------------------------------------------
# ======================================================================================================================
# Import Statements
# ----------------------------------------------------------------------------------------------------------------------
import argparse
import logging
import os
import re
import getpass
import datetime

# Installed Dependencies
from mako.lookup import TemplateLookup  # https://pypi.python.org/pypi/Mako/

# Local imports
import bindings.odx
import libraries.services
import libraries.files


# ======================================================================================================================
# Constants
# ----------------------------------------------------------------------------------------------------------------------
""" The following service types are the only types allowed in non-common manufacturing services.  Services like session
control and security access are expected to be defined in the common component but CANdelaStudio forces a Tester Present
service and a Default Session service because the template says that they are mandatory."""
PROG_SRVS_FILTER = [
    0x22,
    0x2E,
    0x2F,
    0x31,
]

SRV_FILE_NAME_TBL = {
    0x10: 'SrvSession.c',
    0x11: 'SrvRst.c',
    0x27: 'SrvSecu.c',
    0x22: False,
    0x2E: False,
    0x31: False,
    0x2F: False,
    0x3E: None,
}

TYPES = {
    0x10: 'Session',
    0x11: 'Reset',
    0x22: 'Read',
    0x27: 'Security',
    0x2E: 'Write',
    0x2F: 'Control',
    0x31: 'Routine',
    0x3E: 'Tester Present',
}

SUBS = {
    0x10: {
        0x01: 'Default',
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
    0x31: {
        0x01: 'Start',
        0x02: 'Stop',
        0x03: 'Status',
    },
    0x2F: {
        0x00: 'Return',
        0x03: 'Adjust',
    },
}


# ======================================================================================================================
# Classes
# ----------------------------------------------------------------------------------------------------------------------
class File:
    def __init__(self, filename):
        self.filename = filename
        self.functions = {}

# ----------------------------------------------------------------------------------------------------------------------
class Function:
    def __init__(self, name, service):
        self.name = name
        self.service = service
        self.description = service.long
        self.id = service.getId()
        self.idStr = '0x%04X' % self.id if self.id is not None else 'N/A'
        self.type = service.getType()
        self.typeStr = '0x%02X (%s)' % (self.type, TYPES.get(self.type))
        self.sub = service.getSubFunction()
        if self.sub is not None:
            self.subStr = '0x%02X (%s)' % (self.sub, SUBS.get(self.type).get(self.sub))
        else:
            self.subStr = 'N/A'
        self.reqLen = service.reqLen()
        self.reqLenS = 's' if service.reqLen() != 1 else ''
        self.respLen = service.respLen()
        self.respLenS = 's' if service.respLen() != 1 else ''


# ======================================================================================================================
# Helper Functions
# ----------------------------------------------------------------------------------------------------------------------
def replaceCommentBlock(input, function, comment):
    """This helper function is intended to be used to update a comment header block before a service."""
    # Here is where things get a little weird...
    # We reverse the inputs so that the regular expression dot operator does not match more than we want it to.
    # Without doing this wacky logic, the regular expression will match everything from the first comment through the
    # function we're trying to match which basically wipes out the entire file.
    input = input[::-1]
    # This means we must also reverse the replacement string.
    # Also, tack on the group 1 insert for the portion of the function name used for matching).
    replace = r'\1' + comment[::-1].strip()
    # The regular expression match string is messy, the text is reversed but the regular expression markup is not.
    # This is intended to find the function of interest, and because the input has been reversed, also find the comment
    # block that precedes the function (after the function name in this though)  The first, commented out, expression
    # is the non-reversed version.
    # match = r'/\*.+?\*/(.+?FUNC\(NegRespCodEnum, [a-zA-Z]{3,4}MfgSrv_CODE\) %s\(VAR)' % function
    match = r'(RAV\(%s \)EDOC_vrSgfM[a-zA-Z]{3,4} ,munEdoCpseRgeN\(CNUF.+?)/\*.+?\*/' % function[::-1]
    output = re.sub(match, replace, input, flags=re.DOTALL)
    # Now flip the result back around to make it normal again
    return output[::-1]

# ----------------------------------------------------------------------------------------------------------------------
def insertFunctionAtEof(input, function):
    """This helper will insert function three lines before the end of a file.  This assumes that the file contains
    a number of blank lines and an end of file (EOF) comment string."""
    lines = input.split('\n')
    top = '\n'.join(lines[:-4])
    bottom = '\n'.join(lines[-4:])
    return '\n'.join([top, function, bottom])


# ======================================================================================================================
# Main Function
# ----------------------------------------------------------------------------------------------------------------------
def main():
    description = "Nxtr ODX to AUTOSAR ARXML Utility - EA4 Manufacturing Services"
    parser = argparse.ArgumentParser(description=description)
    parser.add_argument('-v', '--verbose', default=0, action='count', help='Output detailed information to console')
    parser.add_argument('variant', help='Component variant - CmnMfgSrv or ProgMfgSrv')
    parser.add_argument('input', help='Input ODX filename')
    parser.add_argument('source', help='Output directory for source files')
    parser.add_argument('contract', help='Output filename for contract header file')
    args = parser.parse_args()

    # Setup logging (force markdown logging to warnings only, it emits a lot of garbage on debug)
    logging.getLogger("MARKDOWN").setLevel(logging.WARNING)
    levels = [logging.WARNING, logging.INFO, logging.DEBUG]
    logLevel = levels[min(args.verbose, 2)]
    logging.basicConfig(level=logLevel)

    # Read input file
    logging.info('Reading input file: %s', args.input)
    with open(args.input) as inFile:
        odxText = inFile.read()
    cms = bindings.odx.CreateFromDocument(odxText)

    # Parse services from ODX
    variant = cms.DIAG_LAYER_CONTAINER.BASE_VARIANTS.BASE_VARIANT[0]
    services = []
    for diag in variant.DIAG_COMMS.DIAG_SERVICE:
        if '_NoResponse' not in diag.SHORT_NAME:
            service = libraries.services.Service(diag, variant)
            if args.variant == 'CmnMfgSrv' or service.getType() in PROG_SRVS_FILTER:
                # If this is the common variant, add all services
                # If this is a program specific variant, only add the allowed services
                services.append(service)
            else:
                logging.debug('Ignoring service, did not pass filter: %s', service)

    # Generate list of source file objects from services in ODX
    files = {}
    for service in services:
        type = service.getType()
        id = service.getId()
        filename = SRV_FILE_NAME_TBL.get(type)
        if filename is None:
            # Don't proceed if the filename mapping is None, this would be for services that don't have handlers, like
            # tester present.
            continue
        if not filename:
            # If the filename is False, use the service ID to generate the file name.
            filename = 'Srv%04X.c' % id
        if filename in files:
            file = files[filename]
        else:
            file = File(filename)
            files[filename] = file
        funcName = '%s_%s' % (args.variant, service.title())
        if funcName in file.functions:
            function = file.functions[funcName]
            function.service = service
        else:
            function = Function(funcName, service)
            file.functions[funcName] = function

    # Process list off files into 
    for file in files.values():
        path = os.path.join(args.source, file.filename)
        if not os.path.exists(path):
            logging.info('Creating new source: %s', path)
            context = {
                'filename': file.filename,
                'zid': getpass.getuser(),
                'date': datetime.datetime.now().strftime('%m/%d/%y'),
                'scope': 'Cmn' if args.variant == 'CmnMfgSrv' else 'Prog',
                'scopeExt': 'Common' if args.variant == 'CmnMfgSrv' else 'Program Specific',
            }
            # there was no input file, so set the input text to be empty to force write to disk
            input = ''
            output = FILE_TMPL % context
        else:
            logging.info('Reading existing source: %s', path)
            with open(path) as inFile:
                input = inFile.read()
            output = input
        # Sorting the list of functions only really matters when creating the initial files, but it's nice...
        for function in sorted(file.functions.values(), key=lambda function: (function.type, function.sub)):
            # Create the function in the source file if it doesn't exist
            if function.name not in output:
                logging.info('Adding function: %s', function.name)
                context = function.__dict__
                context['scope'] = 'Cmn' if args.variant == 'CmnMfgSrv' else 'Prog'
                context['scopeUpper'] = context['scope'].upper()
                context['scopeExt'] = 'Common' if context['scope'] == 'cmn' else 'Program Specific'
                if context['id'] is None:
                    context['id'] = (function.type << 8) | function.sub
                func = SRV_TMPL % context
                output = insertFunctionAtEof(output, func)
            # Update the comment blocks for each function
            context = function.__dict__
            comment = COMMENT_TMPL % context
            output = replaceCommentBlock(output, function.name, comment)
        # If the updates didn't change anything, then don't bother writing the output
        if input == output:
            logging.debug('Not updating file, contents unchanged: %s', path)
        else:
            libraries.files.backup(path)
            with open(path, 'w+') as outFile:
                outFile.write(output)
            logging.info('Output written to: %s', path)

    # Generate contract header file
    if os.path.exists(args.contract):
        logging.debug('Reading existing contract header file: %s', args.contract)
        with open(args.contract) as inFile:
            input = inFile.read()
        output = input
    else:
        logging.info('Creating shiny new contract header file from template')
        filename = os.path.split(args.contract)[1]
        context = {
            'filename': filename,
            'guard': re.sub('[^A-Z_]+', '_', filename.upper()),
            'zid': getpass.getuser(),
            'date': datetime.datetime.now().strftime('%m/%d/%y'),
        }
        input = ''
        output = CONTACT_TMPL % context

    # Add list of enables to header
    enables = []
    for file in files.values():
        for function in file.functions.values():
            id = function.id
            if id is None:
                id = (function.type << 8) | function.sub
            context = {
                'id': id,
                'scope': 'CMN' if args.variant == 'CmnMfgSrv' else 'PROG',
            }
            enable = ENA_TMPL % context
            enable = enable.strip()
            if enable not in enables:
                enables.append(enable)
    find = r'/\* Service Enable/Disable \*/\n.*?\n\n'
    if re.search(find, output, flags=re.DOTALL):
        replace = r'/* Service Enable/Disable */\n%s\n\n' % '\n'.join(enables)
        output = re.sub(find, replace, output, flags=re.DOTALL)
    else:
        logging.error('Could not find matching section for Service Enable/Disable in existing contract header')

    # Add a list of function prototypes
    prototypes = []
    def add_prototype(**context):
        prototype = FUNC_TMPL % context
        prototypes.append(prototype.strip())
    for file in files.values():
        for function in file.functions.values():
            add_prototype(variant=('Cmn' if args.variant == 'CmnMfgSrv' else 'Prog'), name=function.name)
    add_prototype(variant='CMN', name='CmnMfgSrv_SrvPerRdFast')
    add_prototype(variant='CMN', name='CmnMfgSrv_SrvPerRdMed')
    add_prototype(variant='CMN', name='CmnMfgSrv_SrvPerRdSlow')
    add_prototype(variant='CMN', name='CmnMfgSrv_SrvPerRdStop')
    find = r'/\* Prototypes for enabled services \*/\n.*?\n\n'
    if re.search(find, output, flags=re.DOTALL):
        replace = r'/* Prototypes for enabled services */\n%s\n\n' % '\n'.join(prototypes)
        output = re.sub(find, replace, output, flags=re.DOTALL)
    else:
        logging.error('Could not find matching section for service prototypes in existing contract header')

    # Write output contract header file
    if input != output:
        libraries.files.backup(args.contract)
        with open(args.contract, 'w+') as outFile:
            outFile.write(output)
        logging.info('Contract header written to: %s', args.contract)


# ======================================================================================================================
# Source Templates
# ----------------------------------------------------------------------------------------------------------------------
FILE_TMPL = """/***********************************************************************************************************************
* Copyright 2015 Nxtr
* Nxtr Confidential
*
* Module File Name: %(filename)s
* Module Description: Service processing
* Project           : %(scopeExt)s Manufacturing Services
* Author            : %(zid)s
************************************************************************************************************************
* Version Control:
* %%version:         1 %%
* %%derived_by:      %(zid)s %%
* ---------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author    Change Description                                                           SCR #
* --------  -------  --------  ---------------------------------------------------------------------------  ----------
* %(date)s  1        %(zid)s    Initial file creation                                                        EA4#
***********************************************************************************************************************/

/* ================================================================================================================== */
/* Includes */
/* ------------------------------------------------------------------------------------------------------------------ */
#include "Rte_%(scope)sMfgSrv.h"
#include "CmnMfgSrv.h"
#include "CmnMfgSrvTyp.h"
#include "MfgSrvCfg.h"


/* ================================================================================================================== */
/* Service Function Definitions */
/* ------------------------------------------------------------------------------------------------------------------ */



/* End of File: %(filename)s */
"""



SRV_TMPL = """/* [Placeholder comment] */
#if (%(scopeUpper)sMFGSRV_%(id)04XENA_CNT_LGC == CMNMFGSRV_ENAD_CNT_LGC)
FUNC(NegRespCodEnum, %(scope)sMfgSrv_CODE) %(name)s(VAR(uint8, %(scope)sMfgSrv_VAR) DataBuf_Uls_T_u08[])
{
	VAR(NegRespCodEnum, AUTOMATIC) RespCod_Cnt_T_enum = MFGSRVNRCPOSRSP;

	/* -- Insert awesome here... -- */
#error  -- Unimplemented Service -- remove this line once this service has been implemented

	return RespCod_Cnt_T_enum;
}
#endif
"""



COMMENT_TMPL = """
/* ---------------------------------------------------------------------------------------------------------------------
 *        Name:  %(name)s
 * Description:  %(description)s
 *          ID:  %(idStr)s
 *        Type:  %(typeStr)s
 *    Sub-Func:  %(subStr)s
 *    Req. Len:  %(reqLen)d byte%(reqLenS)s
 *   Resp. Len:  %(respLen)d byte%(respLenS)s
 * ------------------------------------------------------------------------------------------------------------------ */
"""


# ======================================================================================================================
# Contract Header Templates
# ----------------------------------------------------------------------------------------------------------------------
CONTACT_TMPL = """/***********************************************************************************************************************
* Copyright 2015 Nxtr
* Nxtr Confidential
*
* Module File Name: %(filename)s
* Module Description: Manufacturing Services Configuration - Contract Header
* Project           : Common Manufacturing Services
* Author            : %(zid)s
************************************************************************************************************************
* Version Control:
* %%version:         1 %%
* %%derived_by:      %(zid)s %%
* ---------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author    Change Description                                                           SCR #
* --------  -------  --------  ---------------------------------------------------------------------------  ----------
* %(date)s  1        %(zid)s    Initial file creation                                                        EA4#
***********************************************************************************************************************/
#ifndef %(guard)s
#define %(guard)s

#include "CmnMfgSrvTyp.h"

extern CONST(uint32, CmnMfgSrv_CONST) CmnMfgSrv_PsrId_Cnt_u32;
extern CONST(uint8, CmnMfgSrv_CONST) CmnMfgSrv_PsrRev_Cnt_u08;
extern CONST(uint8, CmnMfgSrv_CONST) CmnMfgSrv_PsrAuthor_Cnt_u08[6U];
extern CONST(uint8, CmnMfgSrv_CONST) CmnMfgSrv_BuildDate_Cnt_str[11U];
extern CONST(uint8, CmnMfgSrv_CONST) CmnMfgSrv_BuildTi_Cnt_str[8U];

extern CONST(MfgSrvTblRec, AUTOMATIC) CmnMfgSrv_MfgSrvTbl_Cnt_str[100u];
extern CONSTP2VAR(boolean, AUTOMATIC, AUTOMATIC) CmnMfgSrv_DiTbl[64U];
extern CONST(uint16, AUTOMATIC) CmnMfgSrvCfg_NtFctPtrTbl[11U];

/* Service Enable/Disable */



/* Prototypes for enabled services */



#endif
/* End of File: %(filename)s */
"""


ENA_TMPL = """
#define %(scope)sMFGSRV_%(id)04XENA_CNT_LGC\tCMNMFGSRV_ENAD_CNT_LGC
"""



FUNC_TMPL = """
FUNC(NegRespCodEnum, %(variant)sMfgSrv_CODE) %(name)s(VAR(uint8, %(variant)sMfgSrv_VAR) DataBuf_Uls_T_u08[]);
"""



# ======================================================================================================================
# Main Function Call
# ----------------------------------------------------------------------------------------------------------------------
# Call main() when script is invoked directly.  This needs to be after templates to allow main function to find them.
# ----------------------------------------------------------------------------------------------------------------------
if __name__ == "__main__":
    main()

# End of File: OdxGen.py