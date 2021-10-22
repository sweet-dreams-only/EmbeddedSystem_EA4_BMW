/**********************************************************************************************************************
* Copyright 2017 Nxtr 
* Nxtr Confidential
*
* Module File Name  : NxtrWdgM.c
* Module Description: This file contains a trusted function interface for WdgM_Init.  This is currently needed because
*                     an include order issue prevents the Os from visibility to the configuration structure passed into
*                     WdgM_Init, so the trusted function cannot be directly called.  To work around this, this interface 
*                     function was created to avoid the Os from needing visibility to this structure.  This file is
*                     only needed in a project if the WdgM_Init function is called from a non-trusted application context.
* Project           : CBD
* Author            : Lucas Wendling
***********************************************************************************************************************
* Version Control:
* %version:          1 %
* %derived_by:       tzyksv %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     --------
* 11/01/17  1        AR       Initial Version  copied from  AR001A_WdgM_Vector/Ar4.0.3                          EA4#16910                             
**********************************************************************************************************************/

/************************************************ Include Statements *************************************************/
#include "Std_Types.h"
#include "NxtrWdgM.h"
#include "WdgM.h"
#include "WdgM_PBcfg.h"

/******************************************** File Level Rule Deviations *********************************************/

/* MISRA-C:2004 Rule 19.1 [NXTRDEV 19.1.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */

/********************************************* Embedded Local Constants **********************************************/

/******************************************** Module Specific Variables **********************************************/

/******************************************** Local Function Prototypes **********************************************/

/*********************************************** Function Definitions ************************************************/

#define WDGM_START_SEC_CODE
#include "MemMap.h"

/**********************************************************************************************************************
  * Name:        NxtrWdgM_Init
  * Description: Trusted function interface for WdgM_Init
  * Inputs:      NONE
  * Outputs:     NONE
  * Usage Notes: To be called by the Os as a trusted function
  ********************************************************************************************************************/
FUNC(void, WDGM_CODE) NxtrWdgM_Init(void)
{
    WdgM_Init(&WdgMConfig_Mode0_core0);
}

#define WDGM_STOP_SEC_CODE
#include "MemMap.h" 
