/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  CDD_EcmOutpAndDiagc.c
 *     SW-C Type:  CDD_EcmOutpAndDiagc
 *  Generated at:  Mon Oct 19 13:59:31 2015
 *
 *     Generator:  MICROSAR RTE Generator Version 4.3.0
 *                 RTE Core Version 1.3.0
 *       License:  Unlimited license CBD1400351 (THE ECU PRODUCT "STEERING SYSTEMS", THE ECU SUPPLIER "NXTR", THE VEHICLE MANUFACTURER "GENERAL MOTORS CORPORATION") for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <CDD_EcmOutpAndDiagc>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/***********************************************************************************************************************
* Copyright 2015, 2017 Nxtr
* Nxtr Confidential
*
* Module File Name:   CDD_EcmOutpAndDiagc.c
* Module Description: Error Control Module Output and Diagnostics Complex Driver
* Project           : CBD
* Author            : Lucas Wendling
************************************************************************************************************************
* Version Control:
* %version:         2 %
* %derived_by:      rzk04c %
* ---------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author    Change Description                                                           SCR #
* --------  -------  --------  ---------------------------------------------------------------------------  ----------
* 10/06/15  1        LWW       Initial Version                                                              EA4#1847
* 07/14/17  2        AJM       Quality update- Removed unwanted comments                                    EA4#13346
***********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_CDD_EcmOutpAndDiagc.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "CDD_EcmOutpAndDiagc.h"
#include "ecm_regs.h"
#include "NxtrMcuSuprtLib.h"

/******************************************** File Level Rule Deviations *********************************************/
/* MISRA-C:2004 Rule 19.1 [NXTRDEV 19.1.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


#define CDD_EcmOutpAndDiagc_START_SEC_CODE
#include "CDD_EcmOutpAndDiagc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CtrlErrOut_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <CtrlErrOut>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void CtrlErrOut_Oper(boolean PinSt_Arg, TrigReg1 TrigReg_Arg)
 *
 *********************************************************************************************************************/

FUNC(void, CDD_EcmOutpAndDiagc_CODE) CtrlErrOut_Oper(boolean PinSt_Arg, TrigReg1 TrigReg_Arg) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CtrlErrOut_Oper
 *********************************************************************************************************************/
	VAR(uint32, AUTOMATIC) SavedECMEMK0_Cnt_T_u32;
	VAR(uint32, AUTOMATIC) SavedECMMICFG0_Cnt_T_u32;
	VAR(uint32, AUTOMATIC) SavedECMNMICFG0_Cnt_T_u32;
	VAR(uint32, AUTOMATIC) SavedECMIRCFG0_Cnt_T_u32;

	/* Save contents of ECMEMK0, EMCIRCFG0, ECMMICFG0 and ECMNMICFG0 */
	SavedECMEMK0_Cnt_T_u32 = ECMEMK0;
	SavedECMMICFG0_Cnt_T_u32 = ECMMICFG0;
	SavedECMNMICFG0_Cnt_T_u32 = ECMNMICFG0;
	SavedECMIRCFG0_Cnt_T_u32 = ECMIRCFG0;
	
	/* Set the bit 29 of the ECMEMK0 register to "masked" */
	WrProtdRegEcm_u32((SavedECMEMK0_Cnt_T_u32 | ((uint32)1U<<29U)), &ECMEMK0);
	/* Set the bit 29 of the ECMMICFG0 register to "prohibited" */
	WrProtdRegEcm_u32((SavedECMMICFG0_Cnt_T_u32 & ~((uint32)1U<<29U)), &ECMMICFG0);
	/* Set the bit 29 of the ECMNMICFG0 register to "prohibited" */
	WrProtdRegEcm_u32((SavedECMNMICFG0_Cnt_T_u32 & ~((uint32)1U<<29U)), &ECMNMICFG0);
	/* Set the bit 29 of the ECMIRCFG0 register to "prohibited" */
	WrProtdRegEcm_u32((SavedECMIRCFG0_Cnt_T_u32 & ~((uint32)1U<<29U)), &ECMIRCFG0);
	
	if (STD_LOW == PinSt_Arg)
	{
		if (TRIGREG_MST == TrigReg_Arg)
		{
			/* Drive the ERROROUT pin to Low Level */
			WrProtdRegEcmm_u08(0x01U, &ECMMESET);
		}
		else if (TRIGREG_CHKR == TrigReg_Arg)
		{
			/* Drive the ERROROUT pin to Low Level */
			WrProtdRegEcmc_u08(0x01U, &ECMCESET);
		}
		else
		{
			/* Drive the ERROROUT pin to Low Level */
			WrProtdRegEcmm_u08(0x01U, &ECMMESET);
			WrProtdRegEcmc_u08(0x01U, &ECMCESET);
		}
	}
	else
	{
		/* Clear error flags by setting the ECMCLSSE130 bit of the ECMESSTC1 register */
		WrProtdRegEcm_u32((uint32)1U<<30U, &ECMESSTC1);

		/* Drive the ERROROUT pin to High Level */
		/* Always write to master and checker when trying to de-assert the error pin */
		WrProtdRegEcmm_u08(0x01U, &ECMMECLR);
		WrProtdRegEcmc_u08(0x01U, &ECMCECLR);

	}
	
	/* Clear error flags by setting the ECMCLSSE029 bit of the ECMESSTC0 register */
	WrProtdRegEcm_u32((uint32)1U<<29U, &ECMESSTC0);
 
	/* Restore contents of ECMEMK0, EMCIRCFG0, ECMMICFG0 and ECMNMICFG0 */
	WrProtdRegEcm_u32(SavedECMEMK0_Cnt_T_u32, &ECMEMK0);
	WrProtdRegEcm_u32(SavedECMMICFG0_Cnt_T_u32, &ECMMICFG0);
	WrProtdRegEcm_u32(SavedECMNMICFG0_Cnt_T_u32, &ECMNMICFG0);
	WrProtdRegEcm_u32(SavedECMIRCFG0_Cnt_T_u32, &ECMIRCFG0);
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: EcmOutpAndDiagcInit2
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

FUNC(void, CDD_EcmOutpAndDiagc_CODE) EcmOutpAndDiagcInit2(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: EcmOutpAndDiagcInit2
 *********************************************************************************************************************/

	/* Empty initialization function to provide memory mapping capability of component */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define CDD_EcmOutpAndDiagc_STOP_SEC_CODE
#include "CDD_EcmOutpAndDiagc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
