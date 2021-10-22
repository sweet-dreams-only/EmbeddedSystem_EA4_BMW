#**********************************************************************************************************************
# Copyright 2017 Nxtr 
# Nxtr Confidential
#
# Module File Name:   BMW_5441_EPS.py
# Module Description: Python script to connect the debugger and set default option bytes.
# Project           : BMW
# Author            : Kevin Smith
#**********************************************************************************************************************
# Version Control:
# %version:          2 %
# %derived_by:       cz7lt6 %
#----------------------------------------------------------------------------------------------------------------------
# Date      Rev      Author         Change Description                                                           SCR #
# --------   -------  --------  ---------------------------------------------------------------------------     --------
# 09/06/17   1       KJS       Initial Version                                                                 EA4#14844
# 09/06/17   2       KJS       Updated default flash option bytes                                              EA4#14844
#***********************************************************************************************************************/

#---[Start of script]----------------------------------------------------------------------------------------------------
DeviceFilePath = os.path.abspath((os.chdir(os.path.join(os.path.dirname(sys.argv[0]) + \
                 '\\..\\..\\AR202A_MicroCtrlrSuprt_Impl\\tools\\P1M\\R7F701311'))))

self_dbw.RunCmd('connect 850eserv2  -df="DR7F701311.DVF" -e1lpd4=11000 -RH850 -dclock=16000,0,swoff -noiop -id ffffffffffffffffffffffffffffffff -ip='+DeviceFilePath)

# Prompt user to flash option bytes 
ret = winreg.GetProjectManagerWindow().YesNo("Do you want to flash option bytes?")
winreg.GetProjectManagerWindow().IconifyWindow(False,False)
if ret==True:
	self_dbw.RunCmd('target opbyte 0 0x7FCFFFFB')

#---[End of script]-------------------------------------------------------------------------------------------------------
