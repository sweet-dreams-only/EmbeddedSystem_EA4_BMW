"""=====================================================================================================================
#      File: DcmSrcGen.py
#   Project: EA4 Manufacturing Services
#    Author: Jared Julien <jared.julien@nexteer.com>
# Copyright: (c) 2018 Nxtr Automotive
#
# Description:
# ------------
# Given an ODX file as input, generate the source file containing all of the non-RTE server runnables invoked by the
# DCM when services are requested.
#
# Date        Rev   Author    Change Description
# ==========  ====  ========  =========================================================================================
# 2018-02-02  1     Jared     Initial file creation
# -------------------------------------------------------------------------------------------------------------------"""
# ======================================================================================================================
# Import Statements
# ----------------------------------------------------------------------------------------------------------------------
import argparse
import logging
import os
import sys
import datetime

# Installed Dependencies
from mako.lookup import TemplateLookup  # https://pypi.python.org/pypi/Mako/

# Local imports
import common

# Imports from TL113A Component
# pylint: disable=F0401
# pylint: disable=C0413
# Pylint doesn't understand where to find them.
sys.path.insert(0, os.path.join('..', '..', '..', 'TL113A_MfgSrvSuprt', 'tools'))
import bindings.odx
import libraries.services
import libraries.files


# ======================================================================================================================
# Helper Functions
# ----------------------------------------------------------------------------------------------------------------------
def generate_source(**kwargs):
    """Generate the source code configuration file and return it.  This source code is the output from this script."""
    # Derive the path to template files as relative to this file.  Mako assumes that templates are relative to the
    # directory from which the script is called which is likely to be in a component folder where the batch files is
    # located rather than here.
    directory = os.path.dirname(os.path.realpath(__file__))
    lookup = TemplateLookup(directories=[directory])
    mytemplate = lookup.get_template('CmnMfgSrvIf_Cfg.c.tpl')
    kwargs['year'] = datetime.datetime.now().strftime('%Y')
    return mytemplate.render(**kwargs).replace('\r', '')


# ======================================================================================================================
# Main Function
# ----------------------------------------------------------------------------------------------------------------------
if __name__ == "__main__":
    description = "Nxtr ODX to DCM Interface Source Utility - EA4 Manufacturing Services"
    parser = argparse.ArgumentParser(description=description)
    parser.add_argument('-v', '--verbose', default=0, action='count', help='Output detailed information to console')
    parser.add_argument('input', help='Input ODX file containing all services to be generated')
    parser.add_argument('output', help='Output c source filename')
    args = parser.parse_args()

    # Setup logging
    levels = [logging.WARNING, logging.INFO, logging.DEBUG]
    logLevel = levels[min(args.verbose, 2)]
    logging.basicConfig(level=logLevel)

    # Read input file
    logging.info('Reading input file: %s', args.input)
    with open(args.input) as inFile:
        odxText = inFile.read()
    cms = bindings.odx.CreateFromDocument(odxText)

    # Convert ODX to list of services
    variant = cms.DIAG_LAYER_CONTAINER.BASE_VARIANTS.BASE_VARIANT[0]
    services = []
    for diag in variant.DIAG_COMMS.DIAG_SERVICE:
        if '_NoResponse' not in diag.SHORT_NAME:
            service = libraries.services.Service(diag, variant)
            services.append(service)

    # Convert services into objects specific to this template.
    routines = common.parse_routines(services)
    iocs = common.parse_iocs(services)
    pids = common.parse_pids(services)

    # Generate XML
    xml = generate_source(routines=routines, iocs=iocs, pids=pids)

    # Write output file
    libraries.files.backup(args.output)
    with open(args.output, 'w+') as outFile:
        outFile.write(xml)
    logging.info('Output written to: %s', args.output)


# End of File: DcmSrcGen.py
