#*********************************************************************************************************************
# Copyright 2016 Nxtr
# Nxtr Confidential
#
# Module File Name:   InpFileUpdSwt.py
# Module Description: Changes the DaVinci path from a relative path to an absolute path for integration of system
#                     description files.
# Project           : CBD
# Author            : Kevin Smith
#**********************************************************************************************************************
# Version Control:
# %version:          1 %
# %derived_by:       cz7lt6 %
#---------------------------------------------------------------------------------------------------------------------
# Date      Rev     Author  Change Description                                                              SCR #
# --------  ------- ------- ---------------------------------------------------------------------------     ----------
# 03/04/16  1       KJS     Initial version                                                                 EA4#
#*********************************************************************************************************************/

# ======================================================================================================================
# Import Statements
# ----------------------------------------------------------------------------------------------------------------------
import os
import shutil
import sys
import xml.etree.ElementTree as ET
from argparse import ArgumentParser
from argparse import RawDescriptionHelpFormatter

# ======================================================================================================================
# Constants
# ----------------------------------------------------------------------------------------------------------------------
SCRIPT_VERSION = "1" # Version number shall match synergy version.

# ======================================================================================================================
# Classes
# ----------------------------------------------------------------------------------------------------------------------
class cmdArgDataClass(object):
    def __init__(self):
        self.Import = None
        self.Restore = None
        self.Path = None
        self.PathBackup = None
        self.DaVinciPath = None

# ======================================================================================================================
# Helper Functions
# ----------------------------------------------------------------------------------------------------------------------
def processCmdARgs(argv=None):

    # Setup class
    cmdData = cmdArgDataClass()

    if argv is None:
        argv = sys.argv
    else:
        sys.argv.extend(argv)

    program_version = "Version: " + str(SCRIPT_VERSION)
    program_version_message = '%%(prog)s %s' % (program_version)
    program_shortdesc = 'This application modifies the DaVinci path from a relatvie to absolute path for importing of system description files.'
    program_license = '''%s

Version: %s

Created by Kevin Smith.
Copyright 2016 Nxtr Automotive. All rights reserved.

Usage
-----------------------
''' % (program_shortdesc, SCRIPT_VERSION)

    parser = ArgumentParser(description=program_license, formatter_class=RawDescriptionHelpFormatter)

    parser.add_argument('-p', '--Path', action='store', required=True, help='Path to project\'s DPA file')
    parser.add_argument('-d', '--DaVinci', action='store', required=True, help='Path to DaVinci executable')
    parser.add_argument('-r', '--Restore', action='store_true', required=False, help='Restores the DPA file to the original state')
    parser.add_argument('-i', '--Import', action='store_true', required=False, help='Modifies the DPS file for import')
    parser.add_argument('-v', '--version', action='version', version=program_version_message)
    args = parser.parse_args()

    # Check if the path to dpa file exists
    if os.path.isfile(args.Path):
        cmdData.Path = args.Path
        cmdData.PathBackup = args.Path + ".bak"
    else:
        sys.exit("Error: The file '" + args.Path + "' does not exist from the working path '" + os.path.abspath(os.path.curdir) + "'")

    # Check if DaVinci path exists
    if os.path.isfile(args.DaVinci):
        cmdData.DaVinciPath = args.DaVinci
    else:
        sys.exist("Error: The file '" + args.DaVinci + "' does not exist from the working path '" + os.path.abspath(os.path.curdir) + "'")

    # Check if the user selected one of the import or restore options
    if ( ((args.Restore == False) and (args.Import == False)) or ((args.Restore == True) and (args.Import == True)) ):
        sys.exit("Error: Please choose restore (-r --Restore) or import (-i --Import) when running this script.")
    else:
        # Assign values to class
        cmdData.Restore = args.Restore
        cmdData.Import = args.Import

        # Check to make sure a backup file isn't in the working directory. If so, assume the script was already performed and the
        # restore option should be used.
        if ( (cmdData.Import == True) and (os.path.isfile(cmdData.PathBackup)) ):
            sys.exit("Error: Patch appears to have been already applied. Please run the restore script before trying to import again")

    return cmdData


# ======================================================================================================================
# Main Function
# ----------------------------------------------------------------------------------------------------------------------
if (__name__ == "__main__"):

    # Process command arguments
    cmdData = cmdArgDataClass()
    cmdData = processCmdARgs()

    if cmdData.Import == True:
        # Make a backup of the Dpa file
        shutil.copy(os.path.realpath(cmdData.Path), os.path.realpath(cmdData.PathBackup))
        sys.stdout.write("Backup file location: " + os.path.abspath(cmdData.PathBackup) + "\r\n")

        # Read in Dpa contents
        DpaXmlFile = ET.ElementTree(file=cmdData.Path)
        root = DpaXmlFile.getroot()

        # Locate the Tool->Dev location and update the text with the absolute file path to DaVinci
        TargetFound = False
        for childOfRoot in root.iter("Tools"):
            for childOfParent in childOfRoot:
                if (childOfParent.tag == "DEV"):
                    TargetFound = True
                    childOfParent.text = os.path.abspath(cmdData.DaVinciPath)

        # Write new dpa file
        if TargetFound == True:
            # Write File
            DpaXmlFile.write(cmdData.Path, encoding='UTF-8', xml_declaration=True)
            sys.stdout.write("Patch successfully applied!\r\n")
        else:
            # Target wasn't found, abort script
            os.remove(os.path.realpath(cmdData.PathBackup))
            sys.exit("Error: Target XML path of Tools->DEV was not found in dpa file")
    else: # Restore path

        # Check if the backup file exists
        if os.path.isfile(cmdData.PathBackup):

            # Read in Dpa contents
            DpaXmlFile = ET.ElementTree(file=cmdData.Path)
            root = DpaXmlFile.getroot()

            # Locate the Tool->Dev location and update the text with the absolute file path to DaVinci
            TargetFound = False
            for childOfRoot in root.iter("Tools"):
                for childOfParent in childOfRoot:
                    if (childOfParent.tag == "DEV"):
                        TargetFound = True
                        # Restore the text back to the path provided by the argument
                        childOfParent.text = cmdData.DaVinciPath

            # Write new dpa file
            if TargetFound == True:
                # Write File
                DpaXmlFile.write(cmdData.Path, encoding='UTF-8', xml_declaration=True)
                sys.stdout.write("Patch successfully removed!\r\n")
            else:
                # Target wasn't found, abort script
                os.remove(os.path.realpath(cmdData.PathBackup))
                sys.exit("Error: Target XML path of Tools->DEV was not found in dpa file")

            # Remove back up
            os.remove(cmdData.PathBackup)
        else:
            sys.exit("Error: Backup file '" + os.path.abspath(cmdData.PathBackup) + "' does not exist. Cannot restore")

# End of File
