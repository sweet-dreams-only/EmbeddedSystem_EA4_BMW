/**********************************************************************************************************************
* Copyright 2015 Nxtr 
* Nxtr Confidential
*
* Module File Name  : CDD_TSG31CfgAndUse_MotCtrl_MemMap.h
* Module Description: TSG31 Config and Use Motor Control MemMap
* Project           : CBD
* Author            : Kathleen Creager
***********************************************************************************************************************
* Version Control:
* %version:          1 %
* %derived_by:       nz63rn %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     --------
* 04/20/15	1   	 KMC			initial version							                                    EA4#337
**********************************************************************************************************************/

/******************************************** File Level Rule Deviations *********************************************/
/* MISRA-C:2004 Rule 19.6 [NXTRDEV 19.6.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */
/* MISRA-C:2004 Rule 19.15 [NXTRDEV 19.15.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */


#ifdef CDD_TSG31CfgAndUse_MotCtrl_START_SEC_CODE
    # undef CDD_TSG31CfgAndUse_MotCtrl_START_SEC_CODE
	#define MotCtrl_START_SEC_CODE
	#include "MemMap.h"	
#endif

#ifdef CDD_TSG31CfgAndUse_MotCtrl_STOP_SEC_CODE
    # undef CDD_TSG31CfgAndUse_MotCtrl_STOP_SEC_CODE
	#define MotCtrl_STOP_SEC_CODE
	#include "MemMap.h"
#endif


