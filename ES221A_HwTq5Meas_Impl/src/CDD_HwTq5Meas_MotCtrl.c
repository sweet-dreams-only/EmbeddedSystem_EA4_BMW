/**********************************************************************************************************************
* Copyright 2016, 2017 Nxtr 
* Nxtr Confidential
*
* Module File Name  : CDD_HwTq5Meas_MotCtrl.c 
* Module Description: Implements the MotCtrl functionality of ES221A
* Project           : CBD
* Author            : Krishna Anne
***********************************************************************************************************************
* Version Control:
* %version:          2 %
* %derived_by:       nz4qtt %
*-----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author    Change Description                                                                SCR #
* --------  -------  --------  -----------------------------------------------------------------------------  ----------
* 06/06/16    1      Krishna   Initial Version                                                                 EA4#5646
* 10/27/17    2      TATA	   Changes to match the design while SIL is being run 			                   EA4#15015
**********************************************************************************************************************/
 
/************************************************ Include Statements *************************************************/ 
#include "Rte_CDD_HwTq5Meas.h"
#include "CDD_HwTq5Meas.h"
#include "CDD_MotCtrlMgr_Data.h"

#define ELECGLBPRM_HWTQBUFSIZE_CNT_U08  			(8U)

/******************************************** File Level Rule Deviations *********************************************/
/* MISRA-C:2004 Rule 19.1 [NXTRDEV 19.1.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */


/********************************************* Embedded Local Constants **********************************************/

#define CDD_HwTq5Meas_MotCtrl_START_SEC_CODE 
#include "CDD_HwTq5Meas_MotCtrl_MemMap.h" 

/*****************************************************************************************************************
 * Name        :   HwTq5MeasPer1
 * Description :   HwTq5MeasPer1
 * Inputs      :   None
 * Outputs     :   None
 * Usage Notes :   NA
 ****************************************************************************************************************/
FUNC(void, CDD_HwTq5Meas_CODE) HwTq5MeasPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
 /* REQ: ES221A #84 I */
 
 if( *Rte_Pim_HwTq5RawFastAdcIdxCntr() > (ELECGLBPRM_HWTQBUFSIZE_CNT_U08 - 1U) )
	{
		/*** Resetting Index after reaching the Max size of ADC buffer ***/
		*Rte_Pim_HwTq5RawFastAdcIdxCntr() = 1U;
	}
	
 else
	{
		(*Rte_Pim_HwTq5RawFastAdcIdxCntr())++;
	}
		MOTCTRLMGR_MotCtrlHwTq5RawFastAdcBuf[((*Rte_Pim_HwTq5RawFastAdcIdxCntr())-1U)] = MOTCTRLMGR_MotCtrlHwTq5RawFastAdc;
 /* ENDREQ: ES221A #84 */
}

#define CDD_HwTq5Meas_MotCtrl_STOP_SEC_CODE 
#include "CDD_HwTq5Meas_MotCtrl_MemMap.h"
