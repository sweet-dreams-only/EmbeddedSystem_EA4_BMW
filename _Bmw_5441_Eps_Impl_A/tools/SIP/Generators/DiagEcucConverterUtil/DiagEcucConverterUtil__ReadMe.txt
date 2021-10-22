DiagEcucConverterUtil
=====================

Convert Project specific Standard Configuration files (EcuC module description)
from Autosar 4.2.1 format to the MICROSAR format for subsequent import in 
the DaVinci Configurator5.

Step 1: Convert the OEM-Export.arxml file with this tool (see below).
Step 2: Use the DaVinci Configurator5 import function (Input Files: Standard 
Configuration Files) and update your project with the converted file.


Precondition:
-------------
This conversion tool requires the Microsoft .NET Framework 4.0. Typically this 
installed on your computer, when you use the DaVinci Configurator5.
If missing, you can download/install it from the Microsoft Download Center 
(http://go.microsoft.com/fwlink/?LinkID=186913).


Step 1:
-------
From the command line, call:

DiagEcucConverterUtil.exe <Path_to_your_SIP> <OEM-Export.arxml>

<Path_to_your_SIP> is the absolute path of your local DaVinci Configurator5 
                   installation. In this directory you will find the sub-
                   directory \DaVinciConfigurator\Core and in Core the command 
                   line version "DVCfgCmd.exe" of the DaVinci Configurator5 
                   that is required for the conversion.
<OEM-Export.arxml> is a Project Standard Configuration file (EcuC module 
                   description) from OEM for an AUTOSAR module. This file will
                   be converted in-place, so it must be writeable.

This step will convert in-place the file <OEM-Export.arxml> from AUTOSAR 4.2.1 
to the MICROSAR format, so that it can be imported in Step 2.


Step 2:
-------
Open DaVinci Configurator5, navigate via menu Project > Input Files > Standard 
Configuration Files to the list of files to import.
Use the '+' button to add the converted file from Step 1.
Click "Update the configuration now to commit the project modifications" to 
start the import.
Be patient, the process step "updating the project" will take some time. 


FAQ:
----
Q: After importing a DEM configuration there are many validation messages.
   How to proceed?
A: AR-ECUC02067: "The choice-container DemDebounceAlgotithmClass must have 
   exactly one choice as child, but has 0 child containers."
   The imported file didn't contain info about the DebounceAlgorithm, so after
   the import no imported event has this mandatory choice. To fix:
   Open the Comfort Editor Diagnostics: Diagnostic Events, select all Events 
   there (click the first event and SHIFT-click the last event), in the right
   window open "Event Pre-Debouncing" and choose at "Algorithm" e.g.
   DemDebounceCounterBased.
A: DEM11152 "All DemDTCClassRef parameters must target a different DemDTCClass" 
 + DEM20002 "Inconsistent event combination configuration"
   The imported file contains event combination, i.e. different events reference
   the same DTC. Since the combination is intended here, do not solve DEM11152, 
   but instead solve the Message DEM20002.
A: DEM11206 "DemEnableConditionSupport is deactivated"
   The imported file contains enable condition configuration.
   Activate the support, use solution: "Set DemEnableConditionSupport to true"
A: DEM95100 "Invalid handle ID configuration"
   All imported events have assigned no valid EventID. To recalculate the IDs,
   use solution: "Recalculate all handle ID values."


With any problems:
contact the Vector Hotline: DaVinciSupport@de.vector.com

