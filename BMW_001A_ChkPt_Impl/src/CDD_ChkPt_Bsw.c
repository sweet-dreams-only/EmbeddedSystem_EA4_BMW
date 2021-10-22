/**********************************************************************************************************************
* Copyright 2016, 2017 Nxtr 
* Nxtr Confidential
*
* Module File Name:   CDD_ChkPt_Bsw.c
* Module Description: Check Point functions for BSW tasks
* Project           : BMW 5441
* Author            : Kevin Smith
************************************************************************************************************************
* Version Control:
* %version:          3 %
* %derived_by:       tzyksv %
*---------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     ----------
* 04/20/16  1        KJS       Initial Version                                                                 EA4#5284
* 09/26/17  2        KJS       Updates for FAAR_WE implementation. This is the first of a couple of updates
*                              as the MPU is divided into the various partitions.                              EA4#15594 
* 11/01/17  3        AR        Fixed polyspace warnings                                                        EA4#15593
**********************************************************************************************************************/

/************************************************ Include Statements *************************************************/
#include "Std_Types.h"
#include "CDD_ChkPt_Bsw.h"
#include "WdgM.h"
#include "WdgM_PBcfg.h"
/******************************************** File Level Rule Deviations *********************************************/

/* MISRA-C:2004 Rule 19.1 [NXTRDEV 19.1.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */

/********************************************* Embedded Local Constants **********************************************/

/******************************************** Module Specific Variables **********************************************/

/******************************************** Local Function Prototypes **********************************************/

/*********************************************** Function Definitions ************************************************/
#define CDD_ChkPtAppl10_START_SEC_CODE
#include "CDD_ChkPtAppl10_MemMap.h"/* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
  * Name:        ChkPt_10msBswAppl10Start
  * Description: Start checkpoint function for 10ms BSW Application 10 task
  * Inputs:      NONE
  * Outputs:     NONE
  * Usage Notes: To be called at the start of the 10ms BSW Application 10 task
  ********************************************************************************************************************/
FUNC(void, CDD_ChkPt_CODE) ChkPt_10msBswAppl10Strt(void)
{
	/* MISRA-C:2004 Rule 16.10 [NXTRDEV 16.10.1]: There is no appropriate action to take on the return value */ 
	(void)WdgM_CheckpointReached(WdgMConf_WdgMSupervisedEntity_SE_10msBsw_Appl10, WdgMConf_WdgMCheckpoint_ChkPt_10msBsw_Appl10_Strt);
}

/**********************************************************************************************************************
  * Name:        ChkPt_10msBswAppl10End
  * Description: End checkpoint function for 10ms BSW Application 10 task
  * Inputs:      NONE
  * Outputs:     NONE
  * Usage Notes: To be called at the end of the 10ms BSW Application 10 task
  ********************************************************************************************************************/
FUNC(void, CDD_ChkPt_CODE) ChkPt_10msBswAppl10End(void)
{
	/* MISRA-C:2004 Rule 16.10 [NXTRDEV 16.10.1]: There is no appropriate action to take on the return value */ 
	(void)WdgM_CheckpointReached(WdgMConf_WdgMSupervisedEntity_SE_10msBsw_Appl10, WdgMConf_WdgMCheckpoint_ChkPt_10msBsw_Appl10_End);
}

#define CDD_ChkPtAppl10_STOP_SEC_CODE
#include "CDD_ChkPtAppl10_MemMap.h"/* PRQA S 5087 */ /* MD_MSR_19.1 */
