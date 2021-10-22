/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  CDD_Tauj0CfgAndUse.c
 *     SW-C Type:  CDD_Tauj0CfgAndUse
 *  Generated at:  Tue Aug 11 12:24:35 2015
 *
 *     Generator:  MICROSAR RTE Generator Version 4.3.0
 *                 RTE Core Version 1.3.0
 *       License:  Unlimited license CBD1400351 (THE ECU PRODUCT "STEERING SYSTEMS", THE ECU SUPPLIER "NXTR", THE VEHICLE MANUFACTURER "GENERAL MOTORS CORPORATION") for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <CDD_Tauj0CfgAndUse>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
* Copyright 2015,2016 Nxtr 
* Nxtr Confidential
*
* Module File Name  : CDD_Tauj0CfgAndUse.c
* Module Description: Implementation of Tauj0 Configuration and Use FDD CM455A
* Project           : CBD 
* Author            : Sankardu Varadapureddi
***********************************************************************************************************************
* Version Control:
* %version          : 2 %
* %derived_by       : pznywf %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     --------
* 08/11/15  1        SV        Initial Version                                                                 EA4#1277 
* 03/19/16  2        SV        updated for FDD ver1.1.0                                                        EA4#4640                                                                 
**********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_CDD_Tauj0CfgAndUse.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "tauj_regs.h"
#include "NxtrFixdPt.h"
#include "NxtrMath.h"

/* MISRA-C:2004 Rule 19.1 [NXTRDEV 19.1.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */
/* MISRA-C:2004 Rule 16.10 [NXTRDEV 16.10.1]: There is no appropriate action to take on the return value of RTE_write functions */ 

#define PHAONTIMEASDMAX_NANOSEC_U32 		4294967295U
#define PHAFBDELTACNTMAX_CNT_U32 			320000U
#define PHAFBDELTACNTMIN_CNT_U32 			0U
#define TAUJ0TIPERCNT_NANOSECPERCNT_U15P1	((uint16)(NXTRFIXDPT_FLOATTOP1_ULS_F32 * 12.5F))

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
 *   uint32 *Rte_Pim_PhaOnTiCntrAPrev(void)
 *   uint32 *Rte_Pim_PhaOnTiCntrBPrev(void)
 *   uint32 *Rte_Pim_PhaOnTiCntrCPrev(void)
 *
 *********************************************************************************************************************/


#define CDD_Tauj0CfgAndUse_START_SEC_CODE
#include "CDD_Tauj0CfgAndUse_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Tauj0CfgAndUseInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

FUNC(void, CDD_Tauj0CfgAndUse_CODE) Tauj0CfgAndUseInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Tauj0CfgAndUseInit1
 *********************************************************************************************************************/

	TAUJ0TPS = (uint16)((uint16)0x00U << 12U) |		/* PRS3 */
			   (uint16)((uint16)0x00U << 8U)  |		/* PRS2 */
			   (uint16)((uint16)0x00U << 4U)  |		/* PRS1 */
			   (uint16)((uint16)0x00U << 0U);		/* PRS0 */
	
	TAUJ0BRS = 0x00U;	/* CK3_PRE/1 */	
	
	TAUJ0CMUR0 = (uint8)((uint8)3U << 0U);		/* TIS */
	
	TAUJ0CMUR1 = (uint8)((uint8)3U << 0U);		/* TIS */
	
	TAUJ0CMUR3 = (uint8)((uint8)3U << 0U);		/* TIS */
	
	TAUJ0CMOR0 = (uint16)((uint16)0x00U << 14U)	|		/* CKS */
				 (uint16)((uint16)0x00U << 12U) |		/* CCS */
			     (uint16)((uint16)0x00U << 11U) |		/* MAS */
			     (uint16)((uint16)0x02U << 8U)  |		/* STS */
				 (uint16)((uint16)0x01U << 6U)  |		/* COS */
			     (uint16)((uint16)0x1AU << 0U);			/* MD */
	
	TAUJ0CMOR1 = (uint16)((uint16)0x00U << 14U)	|		/* CKS */
				 (uint16)((uint16)0x00U << 12U) |		/* CCS */
				 (uint16)((uint16)0x00U << 11U) |		/* MAS */
				 (uint16)((uint16)0x02U << 8U)  |		/* STS */
				 (uint16)((uint16)0x01U << 6U)  |		/* COS */
				 (uint16)((uint16)0x1AU << 0U);			/* MD */
	
	TAUJ0CMOR3 = (uint16)((uint16)0x00U << 14U)	|		/* CKS */
				 (uint16)((uint16)0x00U << 12U) |		/* CCS */
				 (uint16)((uint16)0x00U << 11U) |		/* MAS */
				 (uint16)((uint16)0x02U << 8U)  |		/* STS */
				 (uint16)((uint16)0x01U << 6U)  |		/* COS */
				 (uint16)((uint16)0x1AU << 0U);			/* MD */
	
	TAUJ0TS = (uint8)((uint8)0x01U << 3U) |		/* TS03 */
			  (uint8)((uint8)0x00U << 2U) |		/* TS02 */
			  (uint8)((uint8)0x01U << 1U) |		/* TS01 */
			  (uint8)((uint8)0x01U << 0U);		/* TS00 */
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Tauj0CfgAndUsePer1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_PhaOnTiMeasdA_Val(uint32 data)
 *   Std_ReturnType Rte_Write_PhaOnTiMeasdB_Val(uint32 data)
 *   Std_ReturnType Rte_Write_PhaOnTiMeasdC_Val(uint32 data)
 *
 *********************************************************************************************************************/

FUNC(void, CDD_Tauj0CfgAndUse_CODE) Tauj0CfgAndUsePer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Tauj0CfgAndUsePer1
 *********************************************************************************************************************/
	VAR(uint32, AUTOMATIC)  Tmr0_Cnt_T_u32;
	VAR(uint32, AUTOMATIC)  Tmr1_Cnt_T_u32;
	VAR(uint32, AUTOMATIC)  Tmr3_Cnt_T_u32;
	VAR(uint32, AUTOMATIC)  PhaOnTiMeasdA_Cnt_T_u32;
	VAR(uint32, AUTOMATIC)  PhaOnTiMeasdB_Cnt_T_u32;
	VAR(uint32, AUTOMATIC)  PhaOnTiMeasdC_Cnt_T_u32;
	VAR(uint32, AUTOMATIC) DeltaA_Cnt_T_u32;
	VAR(uint32, AUTOMATIC) DeltaB_Cnt_T_u32;
	VAR(uint32, AUTOMATIC) DeltaC_Cnt_T_u32;
		
	Tmr0_Cnt_T_u32 = TAUJ0CNT0;
	Tmr1_Cnt_T_u32 = TAUJ0CNT1;
	Tmr3_Cnt_T_u32 = TAUJ0CNT3;
	
	/* Phase A Time Measurement */
	/* REQ: CM455A #87 I */
	if(Tmr0_Cnt_T_u32 >= *Rte_Pim_PhaOnTiCntrAPrev())
	{
		/* Delta >= 0 */
		DeltaA_Cnt_T_u32 = Tmr0_Cnt_T_u32 - *Rte_Pim_PhaOnTiCntrAPrev();
	}
	else
	{
		/* Delta < 0 */
		DeltaA_Cnt_T_u32 = (PHAONTIMEASDMAX_NANOSEC_U32 - *Rte_Pim_PhaOnTiCntrAPrev()) + Tmr0_Cnt_T_u32;
	}
	
	DeltaA_Cnt_T_u32 = Lim_u32(DeltaA_Cnt_T_u32,PHAFBDELTACNTMIN_CNT_U32,PHAFBDELTACNTMAX_CNT_U32);
	
	PhaOnTiMeasdA_Cnt_T_u32 = ((uint32)TAUJ0TIPERCNT_NANOSECPERCNT_U15P1 * DeltaA_Cnt_T_u32);
	
	PhaOnTiMeasdA_Cnt_T_u32 = (uint32)(PhaOnTiMeasdA_Cnt_T_u32 >> 1u);
	
	*Rte_Pim_PhaOnTiCntrAPrev() = Tmr0_Cnt_T_u32;
	/* ENDREQ: CM455A #87 */
	
	/* Phase B Time Measurement */
	/* REQ: CM455A #95 I */
	if(Tmr1_Cnt_T_u32 >= *Rte_Pim_PhaOnTiCntrBPrev())
	{
		/* Delta >= 0 */
		DeltaB_Cnt_T_u32 = Tmr1_Cnt_T_u32 - *Rte_Pim_PhaOnTiCntrBPrev();
	}
	else
	{
		/* Delta < 0 */
		DeltaB_Cnt_T_u32 = (PHAONTIMEASDMAX_NANOSEC_U32 - *Rte_Pim_PhaOnTiCntrBPrev()) + Tmr1_Cnt_T_u32;
	}
	
	DeltaB_Cnt_T_u32 = Lim_u32(DeltaB_Cnt_T_u32,PHAFBDELTACNTMIN_CNT_U32,PHAFBDELTACNTMAX_CNT_U32);
	
	PhaOnTiMeasdB_Cnt_T_u32 = ((uint32)TAUJ0TIPERCNT_NANOSECPERCNT_U15P1 * DeltaB_Cnt_T_u32);
	
	PhaOnTiMeasdB_Cnt_T_u32 = (uint32)(PhaOnTiMeasdB_Cnt_T_u32 >> 1u);
	
	*Rte_Pim_PhaOnTiCntrBPrev() = Tmr1_Cnt_T_u32;
	/* ENDREQ: CM455A #95 */

	/* Phase C Time Measurement */
	/* REQ: CM455A #96 I */
	if(Tmr3_Cnt_T_u32 >= *Rte_Pim_PhaOnTiCntrCPrev())
	{
		/* Delta >= 0 */
		DeltaC_Cnt_T_u32 = Tmr3_Cnt_T_u32 - *Rte_Pim_PhaOnTiCntrCPrev();
	}
	else
	{
		/* Delta < 0 */
		DeltaC_Cnt_T_u32 = (PHAONTIMEASDMAX_NANOSEC_U32 - *Rte_Pim_PhaOnTiCntrCPrev()) + Tmr3_Cnt_T_u32;
	}
	
	DeltaC_Cnt_T_u32 = Lim_u32(DeltaC_Cnt_T_u32,PHAFBDELTACNTMIN_CNT_U32,PHAFBDELTACNTMAX_CNT_U32);
	
	PhaOnTiMeasdC_Cnt_T_u32 = ((uint32)TAUJ0TIPERCNT_NANOSECPERCNT_U15P1 * DeltaC_Cnt_T_u32);
	
	PhaOnTiMeasdC_Cnt_T_u32 = (uint32)(PhaOnTiMeasdC_Cnt_T_u32 >> 1u);

	*Rte_Pim_PhaOnTiCntrCPrev() = Tmr3_Cnt_T_u32;
	/* ENDREQ: CM455A #96 */
	
	(void)Rte_Write_PhaOnTiMeasdA_Val(PhaOnTiMeasdA_Cnt_T_u32);
	(void)Rte_Write_PhaOnTiMeasdB_Val(PhaOnTiMeasdB_Cnt_T_u32);
	(void)Rte_Write_PhaOnTiMeasdC_Val(PhaOnTiMeasdC_Cnt_T_u32);
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define CDD_Tauj0CfgAndUse_STOP_SEC_CODE
#include "CDD_Tauj0CfgAndUse_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


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
