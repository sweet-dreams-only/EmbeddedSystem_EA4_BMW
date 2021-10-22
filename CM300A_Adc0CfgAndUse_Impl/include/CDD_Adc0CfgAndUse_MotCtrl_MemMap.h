/**********************************************************************************************************************
* Copyright 2016 Nxtr 
* Nxtr Confidential
*
* Module File Name  : CDD_Adc0CfgAndUse_MotCtrl_MemMap.h
* Module Description: Adc0CfgAndUse component Motor Control MemMap
* Project           : CBD
* Author            : Avinash James
***********************************************************************************************************************
* Version Control:
* %version:          1 %
* %derived_by:       rzk04c %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     --------
* 06/09/16	1   	 AJM	   Initial version							                                       EA4#5915
**********************************************************************************************************************/

/******************************************** File Level Rule Deviations *********************************************/
/* MISRA-C:2004 Rule 19.6 [NXTRDEV 19.6.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */
/* MISRA-C:2004 Rule 19.15 [NXTRDEV 19.15.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */


#ifdef CDD_Adc0CfgAndUse_MotCtrl_START_SEC_CODE
    # undef CDD_Adc0CfgAndUse_MotCtrl_START_SEC_CODE
	#define MotCtrl_START_SEC_CODE
	#include "MemMap.h"	
#endif

#ifdef CDD_Adc0CfgAndUse_MotCtrl_STOP_SEC_CODE
    # undef CDD_Adc0CfgAndUse_MotCtrl_STOP_SEC_CODE
	#define MotCtrl_STOP_SEC_CODE
	#include "MemMap.h"
#endif
