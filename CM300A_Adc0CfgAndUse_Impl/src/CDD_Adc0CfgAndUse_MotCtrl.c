/*****************************************************************************
* Copyright 2016 Nxtr 
* Nxtr Confidential
*
* Module File Name  : CDD_Adc0CfgAndUse_MotCtrl.c
* Module Description: Motor Control Loop runnable(s) for ADC diagnostic start and end pointer update.  

* Project           : CBD   
* Author            : Avinash James
*****************************************************************************
* Version Control:
* %version:          1 %
* %derived_by:       rzk04c %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     --------
* 06/09/16  1        AJM       Implemented Adc0CfgAndUsePer1                                                   EA4#5915 
******************************************************************************/

#include "Rte_CDD_Adc0CfgAndUse.h"  
#include "CDD_Adc0CfgAndUse.h"
#include "CDD_MotCtrlMgr_Data.h"
#include "adcd_regs.h"

/* MISRA-C:2004 Rule 19.1 [NXTRDEV 19.1.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */

#define CDD_Adc0CfgAndUse_MotCtrl_START_SEC_CODE
#include "CDD_Adc0CfgAndUse_MotCtrl_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/******************************************************************************
  * Name:        Adc0CfgAndUsePer1
  * Description: Adc0CfgAndUse component periodic processing of start and end pointer 
  * Inputs:      see component's DataDict.m file     
  * Outputs:     see component's DataDict.m file 
  * Usage Notes: Called at Motor Control loop rate 
  ****************************************************************************/
FUNC (void, CDD_Adc0CfgAndUse_CODE) Adc0CfgAndUsePer1 (void)
{
	
	/* REQ: CM300A #77 I */ /* REQ: CM300A #75 I */ /* REQ: CM300A #94 I */
	if((MOTCTRLMGR_MotCtrlAdcDiagcStrtPtrOutp != *Rte_Pim_Adc0DiagcStrtPtr())||
		(MOTCTRLMGR_MotCtrlAdcDiagcEndPtrOutp != *Rte_Pim_Adc0DiagcEndPtr()))
	{
		/* Validity Check */
		if( (MOTCTRLMGR_MotCtrlAdcDiagcStrtPtrOutp >= ADC0CFGANDUSE_DIAGCSCANGROUPMIN_CNT_U08) && 
			(MOTCTRLMGR_MotCtrlAdcDiagcStrtPtrOutp <= ADC0CFGANDUSE_DIAGCSCANGROUPMAX_CNT_U08) && 
			(MOTCTRLMGR_MotCtrlAdcDiagcEndPtrOutp >= ADC0CFGANDUSE_DIAGCSCANGROUPMIN_CNT_U08)  && 
			(MOTCTRLMGR_MotCtrlAdcDiagcEndPtrOutp <= ADC0CFGANDUSE_DIAGCSCANGROUPMAX_CNT_U08)  && 
			(MOTCTRLMGR_MotCtrlAdcDiagcStrtPtrOutp <= MOTCTRLMGR_MotCtrlAdcDiagcEndPtrOutp)    &&
			(ADCD0SGSR1 == 0U))
		{
			/* Update Scan Group 1 Start and End Pointer */
			ADCD0SGVCSP1 = MOTCTRLMGR_MotCtrlAdcDiagcStrtPtrOutp; 
			ADCD0SGVCEP1 = MOTCTRLMGR_MotCtrlAdcDiagcEndPtrOutp; 
			
			/* Update the previous value data store with the current value fo the start and end pointer */
			*Rte_Pim_Adc0DiagcStrtPtr() = MOTCTRLMGR_MotCtrlAdcDiagcStrtPtrOutp;
			*Rte_Pim_Adc0DiagcEndPtr() = MOTCTRLMGR_MotCtrlAdcDiagcEndPtrOutp;
			
		}
	}


	/* ENDREQ: CM300A #77 */ /* ENDREQ: CM300A #75 */ /* ENDREQ: CM300A #94 */ 



}	
	
#define CDD_Adc0CfgAndUse_MotCtrl_STOP_SEC_CODE
#include "CDD_Adc0CfgAndUse_MotCtrl_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

