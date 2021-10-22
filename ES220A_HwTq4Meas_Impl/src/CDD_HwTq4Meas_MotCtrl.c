/**********************************************************************************************************************
* Copyright 2016, 2017 Nxtr 
* Nxtr Confidential
*
* Module File Name  : CDD_HwTq4Meas_MotCtrl.c 
* Module Description: Implements the MotCtrl functionality of ES220A
* Project           : CBD
* Author            : Krishna Anne
***********************************************************************************************************************
* Version Control:
* %version:          2 %
* %derived_by:       nz4qtt %
*-----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author    Change Description                                                                SCR #
* --------  -------  --------  -----------------------------------------------------------------------------  ----------
* 06/06/16    1      Krishna   Initial Version                                                                 EA4#5645
* 10/27/17    2      TATA	   Changes to match the design while SIL is being run 			                   EA4#15018
**********************************************************************************************************************/
 
/************************************************ Include Statements *************************************************/ 
#include "Rte_CDD_HwTq4Meas.h"
#include "CDD_HwTq4Meas.h"
#include "CDD_MotCtrlMgr_Data.h"

#define ELECGLBPRM_HWTQBUFSIZE_CNT_U08  			(8U)

/******************************************** File Level Rule Deviations *********************************************/
/* MISRA-C:2004 Rule 19.1 [NXTRDEV 19.1.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */


/********************************************* Embedded Local Constants **********************************************/

#define CDD_HwTq4Meas_MotCtrl_START_SEC_CODE 
#include "CDD_HwTq4Meas_MotCtrl_MemMap.h" 

/*****************************************************************************************************************
 * Name        :   HwTq4MeasPer1
 * Description :   HwTq4MeasPer1
 * Inputs      :   None
 * Outputs     :   None
 * Usage Notes :   NA
 ****************************************************************************************************************/
/* REQ: ES220A #72 I */
FUNC(void, CDD_HwTq4Meas_CODE) HwTq4MeasPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
 
 if( *Rte_Pim_HwTq4RawFastAdcIdxCntr() > (ELECGLBPRM_HWTQBUFSIZE_CNT_U08 - 1U) )
	{
		/*** Resetting Index after reaching the Max size of ADC buffer ***/
		*Rte_Pim_HwTq4RawFastAdcIdxCntr() = 1U;
	}
	
 else
	{
		(*Rte_Pim_HwTq4RawFastAdcIdxCntr())++;
	}
		MOTCTRLMGR_MotCtrlHwTq4RawFastAdcBuf[((*Rte_Pim_HwTq4RawFastAdcIdxCntr()) - 1U)] = MOTCTRLMGR_MotCtrlHwTq4RawFastAdc;
}
/* ENDREQ: ES220A #72 */	
#define CDD_HwTq4Meas_MotCtrl_STOP_SEC_CODE 
#include "CDD_HwTq4Meas_MotCtrl_MemMap.h"
