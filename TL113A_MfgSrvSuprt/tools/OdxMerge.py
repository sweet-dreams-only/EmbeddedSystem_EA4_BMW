# ======================================================================================================================
#      File: OdxMerge.py
#   Project: EA4 Manufacturing Services
#   Created: 2016-01-26
#  Modified: 2016-01-26
#    Author: Jared Julien
#     Email: jared.julien@nexteer.com
# Copyright: (c) 2016 Nxtr Automotive
#
# Description:
# ------------
# OdxMerge takes in two ODX files and merges their contents into a single output ODX file.
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
import re

import bindings.odx


# ======================================================================================================================
# Constants
# ----------------------------------------------------------------------------------------------------------------------
MergeCandidates = [
    'FUNCT_CLASSS.FUNCT_CLASS',
    'DIAG_DATA_DICTIONARY_SPEC.DATA_OBJECT_PROPS.DATA_OBJECT_PROP',
    'DIAG_DATA_DICTIONARY_SPEC.STRUCTURES.STRUCTURE',
    'DIAG_DATA_DICTIONARY_SPEC.UNIT_SPEC.UNITS.UNIT',
    'DIAG_COMMS.DIAG_SERVICE',
    'REQUESTS.REQUEST',
    'POS_RESPONSES.POS_RESPONSE',
    'NEG_RESPONSES.NEG_RESPONSE',
    'GLOBAL_NEG_RESPONSES.GLOBAL_NEG_RESPONSE',
    'STATE_CHARTS.STATE_CHART',
]


# ======================================================================================================================
# Helper Functions
# ----------------------------------------------------------------------------------------------------------------------


# ======================================================================================================================
# Main Function
# ----------------------------------------------------------------------------------------------------------------------
if __name__ == "__main__":
    description = "Nxtr ODX Merging Utility - EA4 Manufacturing Services"
    parser = argparse.ArgumentParser(description=description)
    parser.add_argument('-v', '--verbose', default=0, action='count', help='Output detailed information to console')
    parser.add_argument('input', help='Input ODX filename to be merged', nargs='+')
    parser.add_argument('output', help='Output merged ODX filename')
    args = parser.parse_args()

    # Setup logging
    levels = [logging.WARNING, logging.INFO, logging.DEBUG]
    logLevel = levels[min(args.verbose, 2)]
    logging.basicConfig(level=logLevel)

    output = None
    idReMapping = []

    # Step through each input file
    for fileIdx, filename in enumerate(args.input):
        logging.info('Reading input file: %s', filename)
        with open(filename) as inFile:
            rawInput = inFile.read()

        # Update ID references to make unique within this file
        rawInput = re.sub(r'"_EPS_(\d+)"', r'"_EPS_%d_\1"' % fileIdx, rawInput)

        # Generate an ODX structure from the input data
        input = bindings.odx.CreateFromDocument(rawInput)

        if output is None:
            # on the first loop, just set the output equal to the input and move on
            output = input
            continue

        for candidate in MergeCandidates:
            inputCandidate = input.DIAG_LAYER_CONTAINER.BASE_VARIANTS.BASE_VARIANT[0]
            outputCandidate = output.DIAG_LAYER_CONTAINER.BASE_VARIANTS.BASE_VARIANT[0]
            try:
                for attr in candidate.split('.'):
                    inputCandidate = getattr(inputCandidate, attr)
                    outputCandidate = getattr(outputCandidate, attr)
            except AttributeError:
                # If an attribute error occurs, skip this merge
                # TODO: This assumes that the first input is more complete and skips the copy
                # It would be more robust to properly merge under all circumstances
                continue
            for inputItem in inputCandidate:
                foundId = None
                for outputItem in outputCandidate:
                    if inputItem.SHORT_NAME == outputItem.SHORT_NAME:
                        foundId = outputItem.ID
                if foundId is None:
                    outputCandidate.append(inputItem)
                    logging.debug('Appending item from %s: %s', filename, inputItem)
                else:
                    idReMapping.append((inputItem.ID, foundId))

        # Slight hack to handle nested state charts - these should be shared with Common, so we should
        # be able to look them up in the first input file rather than merge them.  This is a known limitation.
        for inputStateChart in input.DIAG_LAYER_CONTAINER.BASE_VARIANTS.BASE_VARIANT[0].STATE_CHARTS.STATE_CHART:
            for inputState in inputStateChart.STATES.STATE:
                for outputStateChart in output.DIAG_LAYER_CONTAINER.BASE_VARIANTS.BASE_VARIANT[0].STATE_CHARTS.STATE_CHART:
                    for outputState in outputStateChart.STATES.STATE:
                        if inputState.SHORT_NAME == outputState.SHORT_NAME:
                            idReMapping.append((inputState.ID, outputState.ID))
                            logging.debug('Added STATE re-mapping from %s to %s', inputState.ID, outputState.ID)

    # Compile output into raw text form
    logging.info('Writing output file: %s', args.output)
    rawOutput = output.toxml('utf-8', element_name='ODX')

    # Remap ID references from non-unique references
    rawOutput = rawOutput.decode('utf-8')
    for fromId, toId in idReMapping:
        rawOutput = rawOutput.replace('"%s"' % fromId, '"%s"' % toId)
        logging.debug('Re-mapped ID/REF %s to %s', fromId, toId)
    rawOutput = rawOutput.encode('utf-8')

    # Write text to output file
    pretty = minidom.parseString(rawOutput).toprettyxml()
    with open(args.output, 'w+') as outFile:
        outFile.write(pretty.encode('utf-8'))
    logging.info('Output written to: %s', args.output)


# End of File: OdxMerge.py