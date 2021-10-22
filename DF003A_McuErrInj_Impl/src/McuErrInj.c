/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  McuErrInj.c
 *     SW-C Type:  McuErrInj
 *  Generated at:  Thu Mar 16 15:35:54 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 4.3.0
 *                 RTE Core Version 1.3.0
 *       License:  Unlimited license CBD1400351 (THE ECU PRODUCT "STEERING SYSTEMS", THE ECU SUPPLIER "NXTR", THE VEHICLE MANUFACTURER "GENERAL MOTORS CORPORATION") for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <McuErrInj>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
 /**********************************************************************************************************************
* Copyright 2017 Nxtr 
* Nxtr Confidential
*
* Module File Name  : McuErrInj.c
* Module Description: Micro Diagnostic Error Injection
* Project           : CBD
* Author            : Avinash James
***********************************************************************************************************************
* Version Control:
* %version:          2 %
* %derived_by:       rzk04c %
*---------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author    Change Description                                                             SCR #
* --------  -------  --------  -----------------------------------------------------------------------------  -------
* 01/06/17  1       AJM        Initial version                                                                EA4#6934
* 07/21/17  2        AJM       Added few more test functions and #defines for NTC0x39,0x3A,0x2A                EA4#13348
**********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_McuErrInj.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/******************************************** File Level Rule Deviations *********************************************/
#include "ram_regs.h"
#include "Os.h"
#include "McuErrInj.h"
#include "McuErrInjNonRte_MemMap.h"

#define McuErrInj_START_SEC_VAR_INIT_128
#include "McuErrInjNonRte_MemMap.h"

#if (MCUDIAGCERRINJ == STD_ON)
volatile VAR(uint32, AUTOMATIC) DmaWrDataVar_G[4] = {0U,0U,0U,0U};
#endif

#define McuErrInj_STOP_SEC_VAR_INIT_128
#include "McuErrInjNonRte_MemMap.h"



#define McuErrInjGlobalShared_START_SEC_VAR_CLEARED_32
#include "McuErrInjNonRte_MemMap.h"

#if (MCUDIAGCERRINJ == STD_ON)
volatile VAR(uint32, AUTOMATIC) McuDiagcTestVar1_G;
volatile VAR(uint32, AUTOMATIC) McuDiagcTestVar2_G;
volatile VAR(uint32, AUTOMATIC) McuDiagcTestAry_G[8U];
#endif

#define McuErrInjGlobalShared_STOP_SEC_VAR_CLEARED_32
#include "McuErrInjNonRte_MemMap.h"

/* MISRA-C:2004 Rule 19.1 [NXTRDEV 19.1.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */

#define ERRINJCNTRVAL_CNT_U08				10U
#define SHIFTBYWORD_CNT_U08					16U
#define SHIFTBYBYTE_CNT_U08					8U
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   uint8 *Rte_Pim_ErrInjActvCntr(void)
 *   boolean *Rte_Pim_StrtErrInj(void)
 *
 *********************************************************************************************************************/


#define McuErrInj_START_SEC_CODE
#include "McuErrInj_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ClrErrInjReg_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <ClrErrInjReg>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void ClrErrInjReg_Oper(void)
 *
 *********************************************************************************************************************/

FUNC(void, McuErrInj_CODE) ClrErrInjReg_Oper(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: ClrErrInjReg_Oper
 *********************************************************************************************************************/
	/* Clear the value of BRAMDAT2 */
	BRAMDAT2 = 0x0U;

	StrtErrInjCntr_Oper();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: McuErrInjInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

FUNC(void, McuErrInj_CODE) McuErrInjInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: McuErrInjInit1
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: McuErrInjPer1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 *********************************************************************************************************************/

FUNC(void, McuErrInj_CODE) McuErrInjPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: McuErrInjPer1
 *********************************************************************************************************************/
	#if (MCUDIAGCERRINJ == STD_ON)
	if (*Rte_Pim_ErrInjActvCntr() > 0U)
	{
		*Rte_Pim_ErrInjActvCntr()-= 1U;
		if (*Rte_Pim_ErrInjActvCntr() == 0U)
		{
			*Rte_Pim_StrtErrInj() = FALSE;
		}
	}

	switch(BRAMDAT2)
	{
		/* MPU Violation */
		case MCUERRINJ_NTC0025BIT01CASE01_CNT_U32:
			InjMemProtnErr (); /* CM101A */
		break;

		/* IPG Violation - */
		case MCUERRINJ_NTC002DBIT03CASE01_CNT_U32:
		case MCUERRINJ_NTC002DBIT03CASE02_CNT_U32:
		case MCUERRINJ_NTC002DBIT03CASE03_CNT_U32:
		case MCUERRINJ_NTC002DBIT03CASE04_CNT_U32:
		case MCUERRINJ_NTC002DBIT03CASE05_CNT_U32:
		case MCUERRINJ_NTC002DBIT03CASE06_CNT_U32:
			InjIpgRtErr (); /* CM107A */
		break;
		
		case MCUERRINJ_NTC0022BIT01CASE01_CNT_U32:
		/* Run time PBG error with user mode execution */
			InjPbgRtErr (); /* CM101A */
		break;

		case MCUERRINJ_NTC0039BIT00CASE01_CNT_U32:
		case MCUERRINJ_NTC0039BIT00CASE02_CNT_U32:
		case MCUERRINJ_NTC0039BIT00CASE03_CNT_U32:
		case MCUERRINJ_NTC0039BIT00CASE04_CNT_U32:
		/*/ AR102A  
		TAUJ1 and TAUJ2 registers can be modified in UM and are not blocked by PBG protection. 
		No server runnable is needed as the error injection code is present in the NxtrTiPer1 */
		break;

		default:
		break;
	}
	
	Call_McuDiagcTestTrustd();
	#endif
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ReadErrInjReg_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <ReadErrInjReg>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void ReadErrInjReg_Oper(uint32 *ErrId_Arg)
 *
 *********************************************************************************************************************/

FUNC(void, McuErrInj_CODE) ReadErrInjReg_Oper(P2VAR(uint32, AUTOMATIC, RTE_MCUERRINJ_APPL_VAR) ErrId_Arg) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: ReadErrInjReg_Oper
 *********************************************************************************************************************/
#if (MCUDIAGCERRINJ == STD_ON)
	*ErrId_Arg = BRAMDAT2;
#else
	*ErrId_Arg = 0U; /* Return 0 in all other cases. Added for static compliance */
#endif
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: StrtErrInjCntr_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <StrtErrInjCntr>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void StrtErrInjCntr_Oper(void)
 *
 *********************************************************************************************************************/

FUNC(void, McuErrInj_CODE) StrtErrInjCntr_Oper(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: StrtErrInjCntr_Oper
 *********************************************************************************************************************/
#if (MCUDIAGCERRINJ == STD_ON)
 /* Mark the starting of error injection by setting the PIM to 1 */
	*Rte_Pim_StrtErrInj() = TRUE;

	/* Set the counter value to 10 to reset the PIM variable after 20ms */
	*Rte_Pim_ErrInjActvCntr() = ERRINJCNTRVAL_CNT_U08;
#endif
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: UpdErrInjReg_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <UpdErrInjReg>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void UpdErrInjReg_Oper(uint16 NtcNr_Arg, uint8 NtcStInfo_Arg, uint8 ErrInjNr_Arg)
 *
 *********************************************************************************************************************/

FUNC(void, McuErrInj_CODE) UpdErrInjReg_Oper(uint16 NtcNr_Arg, uint8 NtcStInfo_Arg, uint8 ErrInjNr_Arg) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: UpdErrInjReg_Oper
 *********************************************************************************************************************/
#if (MCUDIAGCERRINJ == STD_ON)
	VAR(uint32, AUTOMATIC) ErrId_Cnt_T_u32; 
	
	ErrId_Cnt_T_u32 = ((uint32)NtcNr_Arg << SHIFTBYWORD_CNT_U08) | ((uint32)NtcStInfo_Arg << SHIFTBYBYTE_CNT_U08) | (uint32) ErrInjNr_Arg;
	BRAMDAT2 = ErrId_Cnt_T_u32;
#endif
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define McuErrInj_STOP_SEC_CODE
#include "McuErrInj_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
  * Name:        McuDiagcTestTrustd
  * Description: D
  * Inputs:      NONE
  * Outputs:     NONE
  * Usage Notes: 
  ********************************************************************************************************************/

#define McuFltInj_START_SEC_CODE
#include "McuErrInj_MemMap.h"

FUNC(void, McuErrInj_CODE) McuDiagcTestTrustd(void) 
{
	#if (MCUDIAGCERRINJ == STD_ON)
	switch(BRAMDAT2)
	{
		/* CM340A */
		/* Do Nothing as code exists in the FDD */
		case MCUERRINJ_NTC0032BIT03ANDBIT01CASE01_CNT_U32:
		case MCUERRINJ_NTC0032BIT03ANDBIT02ANDBIT01CASE01_CNT_U32:
		case MCUERRINJ_NTC0032BIT03ANDBIT02CASE01_CNT_U32:
		case MCUERRINJ_NTC0032BIT03CASE01_CNT_U32:
		case MCUERRINJ_NTC0032BIT04ANDBIT01CASE01_CNT_U32:
		case MCUERRINJ_NTC0032BIT04ANDBIT01CASE02_CNT_U32:
		case MCUERRINJ_NTC0032BIT04ANDBIT02ANDBIT01CASE01_CNT_U32:
		case MCUERRINJ_NTC0032BIT04ANDBIT02ANDBIT01CASE02_CNT_U32:
		case MCUERRINJ_NTC0032BIT04ANDBIT02CASE01_CNT_U32:
		case MCUERRINJ_NTC0032BIT04ANDBIT02CASE02_CNT_U32:
		case MCUERRINJ_NTC0032BIT04ANDBIT02CASE03_CNT_U32:
		case MCUERRINJ_NTC0032BIT04ANDBIT03ANDBIT01CASE01_CNT_U32:
		case MCUERRINJ_NTC0032BIT04ANDBIT03ANDBIT02ANDBIT01CASE01_CNT_U32:
		case MCUERRINJ_NTC0032BIT04ANDBIT03ANDBIT02CASE01_CNT_U32:
		break;
		case MCUERRINJ_NTC0032BIT05CASE01_CNT_U32:
		case MCUERRINJ_NTC0032BIT06CASE01_CNT_U32:
		case MCUERRINJ_NTC0033BIT05CASE01_CNT_U32:
		case MCUERRINJ_NTC0033BIT06CASE01_CNT_U32:
			InjAdcErr(); /* CM340A */
		break;
		
		/* Clock Monitor 0 and 2 Fault */
		case MCUERRINJ_NTC0023BIT02CASE01_CNT_U32:
		case MCUERRINJ_NTC0023BIT03CASE01_CNT_U32:
		case MCUERRINJ_NTC0023BIT06CASE01_CNT_U32:
		case MCUERRINJ_NTC0023BIT07CASE01_CNT_U32:
			InjClkMonrErr(); /* CM101A Because there is no implementation of CM109A. MCAL Config*/
		break;

		/* Mode Error */
		case MCUERRINJ_NTC0024BIT00CASE01_CNT_U32:
		case MCUERRINJ_NTC0024BIT01CASE01_CNT_U32:
		case MCUERRINJ_NTC0024BIT02CASE01_CNT_U32:
			InjModErr(); /* CM101A */
		break;

		/* MPU Violation */
		case MCUERRINJ_NTC0025BIT00CASE01_CNT_U32:
			InjMemProtnErr(); /* CM101A */
		break;
		
		/* Clock Monitor 1 and 3 Fault */
		case MCUERRINJ_NTC0027BIT02CASE01_CNT_U32:
		case MCUERRINJ_NTC0027BIT03CASE01_CNT_U32:
		case MCUERRINJ_NTC0027BIT06CASE01_CNT_U32:
		case MCUERRINJ_NTC0027BIT07CASE01_CNT_U32:
			InjClkMonrErr(); /* CM101A Because of implementation of CM109A. MCAL Config */
		break;

		/* Watchdog Fault */
		case MCUERRINJ_NTC002CBIT00CASE01_CNT_U32:
			InjWdgErr(); /* CM101A */
		break;
		/* Operating System Permanent Generic Fault */
		case MCUERRINJ_NTC0030BIT00CASE01_CNT_U32:
		case MCUERRINJ_NTC0030BIT01CASE01_CNT_U32:
			InjOsPrmntGenericRtErr(); /* CM101A */
		break;

		/* Operating System Temporary Generic Fault */
		case MCUERRINJ_NTC0031BIT00CASE01_CNT_U32:
			InjOsTmpGenericRtErr(); /* CM101A */
		break;

		/* MCU Core Voltage Monitor Fault */
		case MCUERRINJ_NTC0049BIT00CASE01_CNT_U32:
		case MCUERRINJ_NTC0049BIT01CASE01_CNT_U32:
			InjMcuVltgMonrErr();
		 /* CM101A because FDD for CM112A does not exist. Requirements in DOORS updated to show the same*/
		break;
		/* CRV Fault */
		case MCUERRINJ_NTC0020BIT00CASE01_CNT_U32:
		case MCUERRINJ_NTC0020BIT01CASE01_CNT_U32:
		/* Init CRV Test */
			NxtrSwRst (MCUDIAGC_MCUDIAGCTEST, 0x00000000U); /* CM111A */
		break;
		case MCUERRINJ_NTC0029BIT00CASE01_CNT_U32:
		case MCUERRINJ_NTC0029BIT03CASE01_CNT_U32:
		case MCUERRINJ_NTC0029BIT05CASE01_CNT_U32:
		case MCUERRINJ_NTC0029BIT07CASE01_CNT_U32:
			NxtrSwRst (MCUDIAGC_MCUDIAGCTEST, 0x00000000U); /* CM110A */
		break;
		case MCUERRINJ_NTC0020BIT00CASE02_CNT_U32:
		case MCUERRINJ_NTC0020BIT01CASE02_CNT_U32:
		/* Periodic CRV Test */
			InjVrfyCritRegErr(); /* CM111A */
		break;

		case MCUERRINJ_NTC002BBIT01CASE02_CNT_U32:
		/* ES002A */
		break;
		case MCUERRINJ_NTC002BBIT00CASE01_CNT_U32:
			InjMcuDiagcErr();
		break;
		case MCUERRINJ_NTC002BBIT01CASE01_CNT_U32:
		/* CM200A */
		break;
		
		case MCUERRINJ_NTC0036BIT00CASE01_CNT_U32:
		case MCUERRINJ_NTC0036BIT01CASE01_CNT_U32:
			InjDmaErr(); /* CM200A */
		break;
		
		/* MBIST */
		case MCUERRINJ_NTC0010BIT00CASE01_CNT_U32:
			NxtrSwRst (MCUDIAGC_MCUDIAGCTEST, 0x00000000U); /* CM106A */
		break;

		/* BIST, Lockstep or FACI Fault */
		case MCUERRINJ_NTC0029BIT06CASE01_CNT_U32:
		case MCUERRINJ_NTC0029BIT06CASE02_CNT_U32:
		case MCUERRINJ_NTC0029BIT06CASE03_CNT_U32:
		case MCUERRINJ_NTC0029BIT06CASE04_CNT_U32:
		case MCUERRINJ_NTC0021BIT00CASE01_CNT_U32:
		case MCUERRINJ_NTC0021BIT00CASE02_CNT_U32:
		case MCUERRINJ_NTC0021BIT02CASE01_CNT_U32:
		case MCUERRINJ_NTC0021BIT02CASE02_CNT_U32:
		case MCUERRINJ_NTC0021BIT04CASE01_CNT_U32:
		case MCUERRINJ_NTC0021BIT05CASE01_CNT_U32:
		case MCUERRINJ_NTC0021BIT06CASE01_CNT_U32:
		/* CM106A */
		case MCUERRINJ_NTC0021BIT07CASE01_CNT_U32:
		case MCUERRINJ_NTC0026BIT00CASE01_CNT_U32:
		case MCUERRINJ_NTC0026BIT01CASE01_CNT_U32:
		case MCUERRINJ_NTC0026BIT02CASE01_CNT_U32:
		case MCUERRINJ_NTC0026BIT03CASE01_CNT_U32:
		case MCUERRINJ_NTC0026BIT04CASE01_CNT_U32:
		case MCUERRINJ_NTC0026BIT04CASE02_CNT_U32:
		/* CM104A */
			NxtrSwRst (MCUDIAGC_MCUDIAGCTEST, 0x00000000U);
		break;
		case MCUERRINJ_NTC0026BIT07CASE01_CNT_U32:
		case MCUERRINJ_NTC0026BIT07CASE02_CNT_U32:
			InjEcmMstChkrRtErr (); /* CM104A */
		break;
		case MCUERRINJ_NTC0029BIT01CASE01_CNT_U32:
			/* Unknown ECM Rest */
			InjUkwnStrtUpDetdErr (); /* CM104A */
		break;
		case MCUERRINJ_NTC0037BIT07CASE01_CNT_U32:
		case MCUERRINJ_NTC0037BIT07CASE02_CNT_U32:
		case MCUERRINJ_NTC0037BIT07CASE03_CNT_U32:
		case MCUERRINJ_NTC0037BIT07CASE04_CNT_U32:
		case MCUERRINJ_NTC0037BIT07CASE05_CNT_U32:
		case MCUERRINJ_NTC0037BIT07CASE06_CNT_U32:
		case MCUERRINJ_NTC0037BIT07CASE07_CNT_U32:
		case MCUERRINJ_NTC0037BIT07CASE08_CNT_U32:
		case MCUERRINJ_NTC0037BIT07CASE09_CNT_U32:
		case MCUERRINJ_NTC0037BIT07CASE0A_CNT_U32:
		case MCUERRINJ_NTC0037BIT07CASE0B_CNT_U32:
		case MCUERRINJ_NTC0037BIT07CASE0C_CNT_U32:
				/* Unknown ECM Rest */
			InjDataParErr (); /* CM104A */
		break;

		case MCUERRINJ_NTC0029BIT04CASE01_CNT_U32:
			/* Unknown Software Reset */
            ClrErrInjReg_Oper();
			NxtrSwRst (MCUERRINJ_TESTRSTUKWN_CNT_U32, 0x00000000U);
		break;


		case MCUERRINJ_NTC0037BIT06CASE01_CNT_U32:
		case MCUERRINJ_NTC0037BIT06CASE02_CNT_U32:
		case MCUERRINJ_NTC0037BIT06CASE03_CNT_U32:
		case MCUERRINJ_NTC0037BIT06CASE04_CNT_U32:
		case MCUERRINJ_NTC0037BIT06CASE05_CNT_U32:
		case MCUERRINJ_NTC0037BIT06CASE06_CNT_U32:
				/* CM108A */
			NxtrSwRst (MCUDIAGC_MCUDIAGCTEST, 0x00000000U);

		break;
		
		case  MCUERRINJ_NTC0022BIT01CASE02_CNT_U32:
		case  MCUERRINJ_NTC0022BIT01CASE03_CNT_U32:
		case  MCUERRINJ_NTC0022BIT01CASE04_CNT_U32:
		case  MCUERRINJ_NTC0022BIT01CASE05_CNT_U32:
		case  MCUERRINJ_NTC0022BIT01CASE06_CNT_U32:
		case  MCUERRINJ_NTC002DBIT04CASE01_CNT_U32:
		case  MCUERRINJ_NTC002DBIT04CASE02_CNT_U32:
		case  MCUERRINJ_NTC002DBIT05CASE01_CNT_U32:
		case  MCUERRINJ_NTC002DBIT05CASE02_CNT_U32:
		case  MCUERRINJ_NTC002DBIT05CASE03_CNT_U32:
		case  MCUERRINJ_NTC002DBIT05CASE04_CNT_U32:
		case  MCUERRINJ_NTC002DBIT05CASE05_CNT_U32:
		case  MCUERRINJ_NTC002DBIT05CASE06_CNT_U32:
			NxtrSwRst (MCUDIAGC_MCUDIAGCTEST, 0x00000000U); /* CM107A */
		break;
		/* PEG Violation */
		case  MCUERRINJ_NTC002DBIT01CASE01_CNT_U32:
		case  MCUERRINJ_NTC002DBIT01CASE02_CNT_U32:
			InjRtPegErr(); /* CM107A */
		break;

		/* Run Time Fault */
		case MCUERRINJ_NTC0022BIT00CASE01_CNT_U32:
		case MCUERRINJ_NTC0022BIT00CASE02_CNT_U32:
		case MCUERRINJ_NTC0022BIT02CASE01_CNT_U32:
		case MCUERRINJ_NTC0022BIT03CASE01_CNT_U32:
		case MCUERRINJ_NTC0022BIT04CASE01_CNT_U32:
		case MCUERRINJ_NTC0022BIT05CASE01_CNT_U32:
		case MCUERRINJ_NTC0022BIT06CASE01_CNT_U32:
		case MCUERRINJ_NTC0022BIT06CASE02_CNT_U32:
		case MCUERRINJ_NTC0022BIT06CASE03_CNT_U32: 
		case MCUERRINJ_NTC0022BIT06CASE04_CNT_U32: 
		case MCUERRINJ_NTC0022BIT07CASE01_CNT_U32:
			InjMcuRtErr (); /* CM101A */
		break;

		/* Code Flash ECC Errors */
		case MCUERRINJ_NTC0002BIT00CASE01_CNT_U32:
		case MCUERRINJ_NTC0002BIT00CASE02_CNT_U32:
		case MCUERRINJ_NTC0003BIT00CASE01_CNT_U32:
		case MCUERRINJ_NTC0003BIT00CASE02_CNT_U32:
		case MCUERRINJ_NTC0003BIT01CASE01_CNT_U32:
		case MCUERRINJ_NTC0003BIT01CASE04_CNT_U32:
		case MCUERRINJ_NTC0003BIT01CASE03_CNT_U32:
		case MCUERRINJ_NTC0003BIT02CASE01_CNT_U32:
			InjCodFlsEccErr (); /* CM102A */
		break;
		
		/* FPU Violation  */
		case MCUERRINJ_NTC0028BIT01CASE01_CNT_U32:
		case MCUERRINJ_NTC0028BIT01CASE02_CNT_U32:
		case MCUERRINJ_NTC0028BIT01CASE03_CNT_U32:
		case MCUERRINJ_NTC0028BIT02CASE01_CNT_U32:
		case MCUERRINJ_NTC0028BIT03CASE01_CNT_U32:
			InjFpuErr(); /* CM101A */
		break;
		case MCUERRINJ_NTC0028BIT04CASE01_CNT_U32:
            /* Clear BRAMDAT2 and do a reset with reset reason as FPU Error Unknown */
			ClrErrInjReg_Oper();
			NxtrSwRst(MCUDIAGC_FPUERRUKWN, 0x00000000U); 
		break;

		/* CM103A */
		case MCUERRINJ_NTC0012BIT06CASE01_CNT_U32:
		case MCUERRINJ_NTC0012BIT06CASE02_CNT_U32:
		case MCUERRINJ_NTC0012BIT06CASE03_CNT_U32:
		case MCUERRINJ_NTC0012BIT06CASE04_CNT_U32:
		case MCUERRINJ_NTC0017BIT01CASE01_CNT_U32:
		case MCUERRINJ_NTC0018BIT01CASE01_CNT_U32:
		case MCUERRINJ_NTC0019BIT01CASE01_CNT_U32:
		case MCUERRINJ_NTC001ABIT01CASE01_CNT_U32:
		case MCUERRINJ_NTC0012BIT04CASE01_CNT_U32:
		case MCUERRINJ_NTC001BBIT01CASE01_CNT_U32:
		case MCUERRINJ_NTC0012BIT05CASE01_CNT_U32:
		case MCUERRINJ_NTC001DBIT01CASE01_CNT_U32:
		case MCUERRINJ_NTC0016BIT01CASE01_CNT_U32:
		case MCUERRINJ_NTC0012BIT03CASE01_CNT_U32:
		case MCUERRINJ_NTC0012BIT00CASE01_CNT_U32:
		case MCUERRINJ_NTC0012BIT00CASE02_CNT_U32:
		case MCUERRINJ_NTC0012BIT00CASE03_CNT_U32:
		case MCUERRINJ_NTC0012BIT00CASE04_CNT_U32:
		case MCUERRINJ_NTC0012BIT00CASE05_CNT_U32:
		case MCUERRINJ_NTC0012BIT00CASE06_CNT_U32:
		case MCUERRINJ_NTC0012BIT00CASE07_CNT_U32:
		case MCUERRINJ_NTC0012BIT00CASE08_CNT_U32:
		case MCUERRINJ_NTC0012BIT00CASE09_CNT_U32:
		case MCUERRINJ_NTC0012BIT00CASE0A_CNT_U32:
		case MCUERRINJ_NTC0013BIT01CASE01_CNT_U32:
		case MCUERRINJ_NTC0013BIT01CASE02_CNT_U32:
		case MCUERRINJ_NTC0013BIT00CASE01_CNT_U32:
		case MCUERRINJ_NTC0013BIT00CASE02_CNT_U32:
		case MCUERRINJ_NTC0013BIT02CASE01_CNT_U32:
		case MCUERRINJ_NTC0012BIT02CASE01_CNT_U32:
				InjRamErr();
		break;
        
		case MCUERRINJ_NTC002ABIT00CASE01_CNT_U32:
		case MCUERRINJ_NTC002ABIT02CASE01_CNT_U32:
				InjProgSeqErr();
		break;
		case MCUERRINJ_NTC003ABIT22CASE01_CNT_U32:
				InjSwFpuErr();
		break;
        
		default:
		break;
	}
	#endif
}
#define McuErrInj_STOP_SEC_CODE
#include "McuErrInj_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
