/**********************************************************************************************************************
* Copyright 2016 Nxtr 
* Nxtr Confidential
*
* Module File Name  : CDD_HwTq5Meas_MotCtrl_MemMap.h
* Module Description: HwTq5Meas component Motor Control MemMap
* Project           : CBD
* Author            : Krishna Anne
***********************************************************************************************************************
* Version Control:
* %version:          1 %
* %derived_by:       nz4qtt %
*----------------------------------------------------------------------------------------------------------------------
* Date       Rev      Author    Change Description                                                             SCR #
* --------  -------  --------  ---------------------------------------------------------------------------   ----------
* 06/09/16	 1   	  Krishna 	Initial version							                                  EA4#5646
**********************************************************************************************************************/

/******************************************** File Level Rule Deviations *********************************************/
/* MISRA-C:2004 Rule 19.6 [NXTRDEV 19.6.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */
/* MISRA-C:2004 Rule 19.15 [NXTRDEV 19.15.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */


#ifdef CDD_HwTq5Meas_MotCtrl_START_SEC_CODE
    # undef CDD_HwTq5Meas_MotCtrl_START_SEC_CODE
	#define MotCtrl_START_SEC_CODE
	#include "MemMap.h"	
#endif

#ifdef CDD_HwTq5Meas_MotCtrl_STOP_SEC_CODE
    # undef CDD_HwTq5Meas_MotCtrl_STOP_SEC_CODE
	#define MotCtrl_STOP_SEC_CODE
	#include "MemMap.h"
#endif


