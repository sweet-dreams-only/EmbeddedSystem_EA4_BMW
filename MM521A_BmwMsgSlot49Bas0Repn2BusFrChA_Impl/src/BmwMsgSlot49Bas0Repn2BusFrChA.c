/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  BmwMsgSlot49Bas0Repn2BusFrChA.c
 *        Config:  C:/_PratikJadhav/_Synergy_Projects/Working/MM521A_BmwMsgSlot49Bas0Repn2BusFrChA_Impl/tools/Component.dpa
 *     SW-C Type:  BmwMsgSlot49Bas0Repn2BusFrChA
 *  Generated at:  Mon May  7 09:17:37 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <BmwMsgSlot49Bas0Repn2BusFrChA>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/***********************************************************************************************************************
* Copyright 2018 Nxtr
* Nxtr Confidential
*
* Module File Name:   BmwMsgSlot49Bas0Repn2BusFrChA.c
* Module Description: BMW Message Slot 49 Base 0 Repetition 2 Bus FlexRay Channel A Processing
* Project           : CBD
* Author            : Brendon Binder
************************************************************************************************************************
* Version Control:
* %version:         2 %
* %derived_by:      nzlf92 %
* ---------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author    Change Description                                                           SCR #
* --------  -------  --------  ---------------------------------------------------------------------------  ----------
* 04/27/18  1        BRB       Initial file creation                                                        EA4#22533
* 05/07/18  2        PHJ       Function name and calibrations name update                                   EA4#22533
***********************************************************************************************************************/
 
/* PRQA S 0777, 0779 EOF */ /* MD_MSR_5.1_777, MD_MSR_5.1_779 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************
 *
 * Data Types:
 * ===========
 * SigQlfr1
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 *********************************************************************************************************************/

#include "Rte_BmwMsgSlot49Bas0Repn2BusFrChA.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "NxtrMath.h"

#include "E2EPW_BmwMsgSlot49Bas0Repn2BusFrChA_sigGroup_AVL_FORC_GRD_sigGroup_AVL_FORC_GRD_tx.h"
#include "E2EPW_BmwMsgSlot49Bas0Repn2BusFrChA_sigGroup_AVL_STMOM_DV_ACT_sigGroup_AVL_STMOM_DV_ACT_tx.h"
 
/* MISRA-C:2004 Rule 19.1 [NXTRDEV 19.1.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */
/* MISRA-C:2004 Rule 16.10 [NXTRDEV 16.10.1]: There is no appropriate action to take on the return value of RTE reads and writes */

#define HWTQLOLIM_NWTMTR_F32                    (-10.0F)
#define HWTQHILIM_NWTMTR_F32                    (10.0F)
#define HWTQOFFS_NWTMTR_F32                     (10.0F)
#define HWTQSCA_NWTMTRPERCNT_F32                (0.005F)
#define RACKFESTIMDDIV_ULS_F32                  (1000.0F)
#define RACKFESTIMDLOLIM_KILONWT_F32            (-17.0F)
#define RACKFESTIMDHILIM_KILONWT_F32            (17.0F)
#define RACKFESTIMDOFFS_KILONWT_F32             (17.0F)
#define RACKFESTIMDSCA_KILONWTPERCNT_F32        (0.0084F)
#define ELECINPPWRESTIMDIV_ULS_F32              (1000.0F)
#define ELECINPPWRESTIMLOLIM_KILOWATT_F32       (-12.0F)
#define ELECINPPWRESTIMHILIM_KILOWATT_F32       (12.0F)
#define ELECINPPWRESTIMOFFS_KILOWATT_F32        (12.0F)
#define ELECINPPWRESTIMSCA_KILOWATTPERCNT_F32   (0.1F)
#define PERCNTRTHD_CNT_U08                      ((uint8)30U)

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * AVL_FORC_GRD1: Integer in interval [0...65535]
 *   Unit: [kN], Factor: 0.0084, Offset: -17
 * AVL_FORC_GRD_dummy_12_151: Integer in interval [0...255]
 * AVL_PWR_EL_EPS_COOD1: Integer in interval [0...255]
 *   Unit: [kW], Factor: 0.1, Offset: -12
 * AVL_STMOM_DV_ACT1: Integer in interval [0...65535]
 *   Factor: 0.005, Offset: -10
 * AVL_STMOM_DV_ACT_dummy_12_151: Integer in interval [0...255]
 * CRC_AVL_FORC_GRD1: Integer in interval [0...255]
 * CRC_AVL_STMOM_DV_ACT1: Integer in interval [0...255]
 * float32: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * sint8: Integer in interval [-128...127] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * ALIV_AVL_FORC_GRD1: Enumeration of integer in interval [0...255] with enumerators
 *   ALIV_COU_4_Zaehlerstand0DotDotE (0U)
 *   ALIV_COU_4_SignalUngueltig (15U)
 * ALIV_AVL_STMOM_DV_ACT1: Enumeration of integer in interval [0...255] with enumerators
 *   ALIV_COU_4_Zaehlerstand0DotDotE (0U)
 *   ALIV_COU_4_SignalUngueltig (15U)
 * QU_AVL_FORC_GRD1: Enumeration of integer in interval [0...255] with enumerators
 *   QU_AVL_FORC_GRD_Initialisierung (8U)
 *   QU_AVL_FORC_GRD_SignalwertIstGueltig (2U)
 *   QU_AVL_FORC_GRD_SignalwertIstUngueltigZustandSlashStatusTemporaer (14U)
 *   QU_AVL_FORC_GRD_SignalUngueltig (15U)
 * QU_AVL_STMOM_DV_ACT1: Enumeration of integer in interval [0...255] with enumerators
 *   QU_AVL_STMOM_DV_ACT_Initialisierung (8U)
 *   QU_AVL_STMOM_DV_ACT_SignalwertIstGueltigUndAbgesichertUndPlausibilisiert (1U)
 *   QU_AVL_STMOM_DV_ACT_SignalwertIstUngueltigZustandSlashStatusTemporaer (14U)
 *   QU_AVL_STMOM_DV_ACT_SignalwertIstUngueltig (6U)
 *   QU_AVL_STMOM_DV_ACT_SignalUngueltig (15U)
 * SigQlfr1: Enumeration of integer in interval [0...255] with enumerators
 *   SIGQLFR_NORES (0U)
 *   SIGQLFR_PASSD (1U)
 *   SIGQLFR_FAILD (2U)
 *
 * Record Types:
 * =============
 * sigGroup_AVL_FORC_GRD1: Record with elements
 *   AVL_FORC_GRD of type AVL_FORC_GRD1
 *   AVL_PWR_EL_EPS_COOD of type AVL_PWR_EL_EPS_COOD1
 *   ALIV_AVL_FORC_GRD of type ALIV_AVL_FORC_GRD1
 *   CRC_AVL_FORC_GRD of type CRC_AVL_FORC_GRD1
 *   QU_AVL_FORC_GRD of type QU_AVL_FORC_GRD1
 *   AVL_FORC_GRD_dummy_12_15 of type AVL_FORC_GRD_dummy_12_151
 * sigGroup_AVL_STMOM_DV_ACT1: Record with elements
 *   AVL_STMOM_DV_ACT of type AVL_STMOM_DV_ACT1
 *   ALIV_AVL_STMOM_DV_ACT of type ALIV_AVL_STMOM_DV_ACT1
 *   QU_AVL_STMOM_DV_ACT of type QU_AVL_STMOM_DV_ACT1
 *   CRC_AVL_STMOM_DV_ACT of type CRC_AVL_STMOM_DV_ACT1
 *   AVL_STMOM_DV_ACT_dummy_12_15 of type AVL_STMOM_DV_ACT_dummy_12_151
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   uint8 *Rte_Pim_PerCntr(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_BmwMsgSlot49Bas0Repn2BusFrChARackEstimnLowrLim_Val(void)
 *   float32 Rte_Prm_BmwMsgSlot49Bas0Repn2BusFrChARackEstimnUpprLim_Val(void)
 *   sint8 Rte_Prm_BmwMsgSlot49Bas0Repn2BusFrChABmwSteerPolarity_Val(void)
 *
 *********************************************************************************************************************/


#define BmwMsgSlot49Bas0Repn2BusFrChA_START_SEC_CODE
#include "BmwMsgSlot49Bas0Repn2BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwMsgSlot49Bas0Repn2BusFrChAInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwMsgSlot49Bas0Repn2BusFrChAInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwMsgSlot49Bas0Repn2BusFrChA_CODE) BmwMsgSlot49Bas0Repn2BusFrChAInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwMsgSlot49Bas0Repn2BusFrChAInit1
 *********************************************************************************************************************/

	/* Do nothing */
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwMsgSlot49Bas0Repn2BusFrChAPer1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_ElecInpPwrEstim_Val(float32 *data)
 *   Std_ReturnType Rte_Read_HwTq_Val(float32 *data)
 *   Std_ReturnType Rte_Read_HwTq4Qlfr_Val(SigQlfr1 *data)
 *   Std_ReturnType Rte_Read_HwTq5Qlfr_Val(SigQlfr1 *data)
 *   Std_ReturnType Rte_Read_RackFEstimd_Val(float32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_sigGroup_AVL_FORC_GRD_sigGroup_AVL_FORC_GRD(const sigGroup_AVL_FORC_GRD1 *data)
 *   Std_ReturnType Rte_Write_sigGroup_AVL_STMOM_DV_ACT_sigGroup_AVL_STMOM_DV_ACT(const sigGroup_AVL_STMOM_DV_ACT1 *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwMsgSlot49Bas0Repn2BusFrChAPer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwMsgSlot49Bas0Repn2BusFrChA_CODE) BmwMsgSlot49Bas0Repn2BusFrChAPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwMsgSlot49Bas0Repn2BusFrChAPer1
 *********************************************************************************************************************/

	/* Inputs */
    VAR(float32, AUTOMATIC) ElecInpPwrEstim_Watt_T_f32;
    VAR(float32, AUTOMATIC) ElecInpPwrEstim_KiloWatt_T_f32;
    VAR(float32, AUTOMATIC) ElecInpPwrEstim_Cnt_T_f32;
    VAR(float32, AUTOMATIC) HwTq_NwtMtr_T_f32;
    VAR(float32, AUTOMATIC) HwTq_Cnt_T_f32;
    VAR(SigQlfr1, AUTOMATIC) HwTq4Qlfr_Cnt_T_enum;
    VAR(SigQlfr1, AUTOMATIC) HwTq5Qlfr_Cnt_T_enum;
    VAR(float32, AUTOMATIC) RackFEstimd_Nwt_T_f32;
    VAR(float32, AUTOMATIC) RackFEstimd_KiloNwt_T_f32;
    VAR(float32, AUTOMATIC) RackFEstimd_Cnt_T_f32;
    
    /* Outputs */
    VAR(sigGroup_AVL_FORC_GRD1, AUTOMATIC) SigGroupAvlForcGrd_Cnt_T_rec;
    VAR(sigGroup_AVL_STMOM_DV_ACT1, AUTOMATIC) SigGroupAvlStmomDvAct_Cnt_T_rec;
    
    /* Read inputs */
    (void)Rte_Read_ElecInpPwrEstim_Val(&ElecInpPwrEstim_Watt_T_f32);
    (void)Rte_Read_HwTq_Val(&HwTq_NwtMtr_T_f32);
    (void)Rte_Read_HwTq4Qlfr_Val(&HwTq4Qlfr_Cnt_T_enum);
    (void)Rte_Read_HwTq5Qlfr_Val(&HwTq5Qlfr_Cnt_T_enum);
    (void)Rte_Read_RackFEstimd_Val(&RackFEstimd_Nwt_T_f32);
    
    /*** Start AVL_STMOM_DV_ACT processing ***/
    
    /* AVL_STMOM_DV_ACT */
    HwTq_NwtMtr_T_f32 = HwTq_NwtMtr_T_f32 * (float32)Rte_Prm_BmwMsgSlot49Bas0Repn2BusFrChABmwSteerPolarity_Val();
    HwTq_NwtMtr_T_f32 = Lim_f32(HwTq_NwtMtr_T_f32, HWTQLOLIM_NWTMTR_F32, HWTQHILIM_NWTMTR_F32) + HWTQOFFS_NWTMTR_F32;
    HwTq_Cnt_T_f32 = HwTq_NwtMtr_T_f32 / HWTQSCA_NWTMTRPERCNT_F32;
    SigGroupAvlStmomDvAct_Cnt_T_rec.AVL_STMOM_DV_ACT = (AVL_STMOM_DV_ACT1)HwTq_Cnt_T_f32;
    
    /* QU_AVL_STMOM_DV_ACT */    
    if ((HwTq4Qlfr_Cnt_T_enum == SIGQLFR_PASSD) && (HwTq5Qlfr_Cnt_T_enum == SIGQLFR_PASSD))
    {
       SigGroupAvlStmomDvAct_Cnt_T_rec.QU_AVL_STMOM_DV_ACT = QU_AVL_STMOM_DV_ACT_SignalwertIstGueltigUndAbgesichertUndPlausibilisiert;
       
       /* If valid signals are received, set PerCntr so Initialization can no longer be returned */
       *Rte_Pim_PerCntr() = PERCNTRTHD_CNT_U08 + 1U;
    }
    else if ((HwTq4Qlfr_Cnt_T_enum == SIGQLFR_FAILD) || (HwTq5Qlfr_Cnt_T_enum == SIGQLFR_FAILD))
    {
        SigGroupAvlStmomDvAct_Cnt_T_rec.QU_AVL_STMOM_DV_ACT = QU_AVL_STMOM_DV_ACT_SignalwertIstUngueltig;
        
        /* If valid signals are received, set PerCntr so Initialization can no longer be returned */
        *Rte_Pim_PerCntr() = PERCNTRTHD_CNT_U08 + 1U;
    }
    else if ((*Rte_Pim_PerCntr() <= PERCNTRTHD_CNT_U08) &&
             (HwTq4Qlfr_Cnt_T_enum == SIGQLFR_NORES) &&
             (HwTq5Qlfr_Cnt_T_enum == SIGQLFR_NORES))
    {
        SigGroupAvlStmomDvAct_Cnt_T_rec.QU_AVL_STMOM_DV_ACT = QU_AVL_STMOM_DV_ACT_Initialisierung;
    }
    else
    {
        SigGroupAvlStmomDvAct_Cnt_T_rec.QU_AVL_STMOM_DV_ACT = QU_AVL_STMOM_DV_ACT_SignalwertIstUngueltigZustandSlashStatusTemporaer;
        
        /* If valid signals are received, set PerCntr so Initialization can no longer be returned */
        *Rte_Pim_PerCntr() = PERCNTRTHD_CNT_U08 + 1U;
    }
    
    /*** End AVL_STMOM_DV_ACT processing ***/
    
    /*** Start AVL_FORC_GRD processing ***/
    
    /* QU_AVL_FORC_GRD */
    if ((RackFEstimd_Nwt_T_f32 >= Rte_Prm_BmwMsgSlot49Bas0Repn2BusFrChARackEstimnLowrLim_Val()) && (RackFEstimd_Nwt_T_f32 <= Rte_Prm_BmwMsgSlot49Bas0Repn2BusFrChARackEstimnUpprLim_Val()))
    {
        SigGroupAvlForcGrd_Cnt_T_rec.QU_AVL_FORC_GRD = QU_AVL_FORC_GRD_SignalwertIstGueltig;
    }
    else
    {
        SigGroupAvlForcGrd_Cnt_T_rec.QU_AVL_FORC_GRD = QU_AVL_FORC_GRD_SignalwertIstUngueltigZustandSlashStatusTemporaer;
    }
    
    /* AVL_FORC_GRD */
    RackFEstimd_Nwt_T_f32 = RackFEstimd_Nwt_T_f32 * (float32)Rte_Prm_BmwMsgSlot49Bas0Repn2BusFrChABmwSteerPolarity_Val();
    RackFEstimd_KiloNwt_T_f32 = RackFEstimd_Nwt_T_f32 / RACKFESTIMDDIV_ULS_F32;
    RackFEstimd_KiloNwt_T_f32 = Lim_f32(RackFEstimd_KiloNwt_T_f32, RACKFESTIMDLOLIM_KILONWT_F32, RACKFESTIMDHILIM_KILONWT_F32);
    RackFEstimd_KiloNwt_T_f32 = RackFEstimd_KiloNwt_T_f32 + RACKFESTIMDOFFS_KILONWT_F32;
    RackFEstimd_Cnt_T_f32 = RackFEstimd_KiloNwt_T_f32 / RACKFESTIMDSCA_KILONWTPERCNT_F32;
    SigGroupAvlForcGrd_Cnt_T_rec.AVL_FORC_GRD = (AVL_FORC_GRD1)RackFEstimd_Cnt_T_f32;
    
    /* AVL_PWR_EL_EPS_COOD */
    ElecInpPwrEstim_KiloWatt_T_f32 = ElecInpPwrEstim_Watt_T_f32 / ELECINPPWRESTIMDIV_ULS_F32;
    ElecInpPwrEstim_KiloWatt_T_f32 = Lim_f32(ElecInpPwrEstim_KiloWatt_T_f32, ELECINPPWRESTIMLOLIM_KILOWATT_F32, ELECINPPWRESTIMHILIM_KILOWATT_F32);
    ElecInpPwrEstim_KiloWatt_T_f32 = ElecInpPwrEstim_KiloWatt_T_f32 + ELECINPPWRESTIMOFFS_KILOWATT_F32;
    ElecInpPwrEstim_Cnt_T_f32 = ElecInpPwrEstim_KiloWatt_T_f32 / ELECINPPWRESTIMSCA_KILOWATTPERCNT_F32;
    SigGroupAvlForcGrd_Cnt_T_rec.AVL_PWR_EL_EPS_COOD = (AVL_PWR_EL_EPS_COOD1)ElecInpPwrEstim_Cnt_T_f32;
        
    /*** End AVL_FORC_GRD processing ***/

    /* Increment QuAvlStmomDvActCntr if not yet at 300ms threshold */
    if (*Rte_Pim_PerCntr() <= PERCNTRTHD_CNT_U08)
    {
        *Rte_Pim_PerCntr() = *Rte_Pim_PerCntr() + 1U;
    }
    
    /* Write outputs */
    (void)E2EPW_Write_sigGroup_AVL_FORC_GRD_sigGroup_AVL_FORC_GRD(&SigGroupAvlForcGrd_Cnt_T_rec);
    (void)E2EPW_Write_sigGroup_AVL_STMOM_DV_ACT_sigGroup_AVL_STMOM_DV_ACT(&SigGroupAvlStmomDvAct_Cnt_T_rec);
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define BmwMsgSlot49Bas0Repn2BusFrChA_STOP_SEC_CODE
#include "BmwMsgSlot49Bas0Repn2BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


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
