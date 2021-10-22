/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  BmwMsgSlot49Bas1Repn2BusFrChA.c
 *        Config:  C:/_PratikJadhav/_Synergy_Projects/Working/MM522A_BmwMsgSlot49Bas1Repn2BusFrChA_Impl/tools/Component.dpa
 *     SW-C Type:  BmwMsgSlot49Bas1Repn2BusFrChA
 *  Generated at:  Mon May  7 10:19:48 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <BmwMsgSlot49Bas1Repn2BusFrChA>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/*****************************************************************************
* Copyright 2018 Nxtr 
* Nxtr Confidential
*
* Module File Name: BmwMsgSlot49Bas1Repn2BusFrChA.c
* Module Description: Implementation of BMW Message Slot 49 Base 1 Repetition 2 Bus FlexRay Channel A MM522A
* Project           : CBD  
* Author            : Brendon Binder
*****************************************************************************
* Version Control:
* %version:          2 %
* %derived_by:       nzlf92 %
*---------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     ----------
* 04/19/18  1        BRB       Initial Implementation                                                          EA4#22867
* 05/07/18  2        PHJ       Update function names.                                                          EA4#22867
******************************************************************************/

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
 * BattRtnCurrAmprQlfr1
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * EpsCurrLimSts1
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 *********************************************************************************************************************/

#include "Rte_BmwMsgSlot49Bas1Repn2BusFrChA.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "E2EPW_BmwMsgSlot49Bas1Repn2BusFrChA_sigGroup_DT_EST_sigGroup_DT_EST_tx.h"
#include "NxtrMath.h"
 
/* MISRA-C:2004 Rule 19.1 [NXTRDEV 19.1.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */
/* MISRA-C:2004 Rule 16.10 [NXTRDEV 16.10.1]: There is no appropriate action to take on the return value of:
                                              [Rte_Read, Rte_Read, E2EPW_Write]*/

#define BATTRTNCURRAMPRHILIM_AMP_F32    (255.0F)
#define BATTRTNCURRAMPRLOLIM_AMP_F32    (0.0F)
                                              
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
 * ALIV_DT_EST1: Integer in interval [0...255]
 * CRC_DT_EST1: Integer in interval [0...255]
 * DT_EST_dummy_12_151: Integer in interval [0...255]
 * DT_EST_dummy_16_471: Integer in interval [0...4294967295]
 * DT_EST_dummy_64_951: Integer in interval [0...4294967295]
 * DT_EST_dummy_96_1271: Integer in interval [0...4294967295]
 * float32: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * AVL_I_ACT_EST1: Enumeration of integer in interval [0...255] with enumerators
 *   I_SPEC_ARS_Funktionsschnittstelle_ist_nicht_verfuegbar (253U)
 *   I_SPEC_ARS_Funktion_meldet_Fehler (254U)
 *   I_SPEC_ARS_Signal_unbefuellt (255U)
 *   Unit: [A], Factor: 1, Offset: 0
 * BattRtnCurrAmprQlfr1: Enumeration of integer in interval [0...255] with enumerators
 *   BATTRTNCURRAMPRQLFR_FCTRPRTERR (6U)
 *   BATTRTNCURRAMPRQLFR_FCTACTVSECUR (9U)
 *   BATTRTNCURRAMPRQLFR_FCTNOTACTV (11U)
 *   BATTRTNCURRAMPRQLFR_FCTIFNOTAVL (14U)
 *   BATTRTNCURRAMPRQLFR_INVLD (15U)
 * EpsCurrLimSts1: Enumeration of integer in interval [0...255] with enumerators
 *   EPSCURRLIMSTST_NOCURRLIMR (0U)
 *   EPSCURRLIMSTST_CMFTCURRLIMR (1U)
 *   EPSCURRLIMSTST_MAXCURRLIMN (10U)
 *   EPSCURRLIMSTST_RESDNOTAVL (13U)
 *   EPSCURRLIMSTST_RESDERR (14U)
 *   EPSCURRLIMSTST_SIGUNFLD (15U)
 * QU_AVL_I_ACT_EST1: Enumeration of integer in interval [0...255] with enumerators
 *   QU_SUM_AVL_I_DRDY_SFY_Wert_gueltig_abgesichert (1U)
 *   QU_SUM_AVL_I_DRDY_SFY_Wert_gueltig_eingeschraenkt (3U)
 *   QU_SUM_AVL_I_DRDY_SFY_Wert_nicht_verfuegbar_Fehler (6U)
 *   QU_SUM_AVL_I_DRDY_SFY_Wert_nicht_verfuegbar (14U)
 *   QU_SUM_AVL_I_DRDY_SFY_Signal_unbefuellt (15U)
 * ST_CULI_EST1: Enumeration of integer in interval [0...255] with enumerators
 *   ST_CULI_EST_Keine_Strombegrenzung (0U)
 *   ST_CULI_EST_Komfort_Strombegrenzung (1U)
 *   ST_CULI_EST_Maximale_Strombegrenzung (10U)
 *   ST_CULI_EST_Reserviert_nicht_verfuegbar (13U)
 *   ST_CULI_EST_Reserviert_Fehler (14U)
 *   ST_CULI_EST_Signal_unbefuellt (15U)
 *
 * Record Types:
 * =============
 * sigGroup_DT_EST1: Record with elements
 *   ST_CULI_EST of type ST_CULI_EST1
 *   DT_EST_dummy_64_95 of type DT_EST_dummy_64_951
 *   QU_AVL_I_ACT_EST of type QU_AVL_I_ACT_EST1
 *   DT_EST_dummy_12_15 of type DT_EST_dummy_12_151
 *   AVL_I_ACT_EST of type AVL_I_ACT_EST1
 *   ALIV_DT_EST of type ALIV_DT_EST1
 *   CRC_DT_EST of type CRC_DT_EST1
 *   DT_EST_dummy_96_127 of type DT_EST_dummy_96_1271
 *   DT_EST_dummy_16_47 of type DT_EST_dummy_16_471
 *
 *********************************************************************************************************************/


#define BmwMsgSlot49Bas1Repn2BusFrChA_START_SEC_CODE
#include "BmwMsgSlot49Bas1Repn2BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwMsgSlot49Bas1Repn2BusFrChAInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwMsgSlot49Bas1Repn2BusFrChAInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwMsgSlot49Bas1Repn2BusFrChA_CODE) BmwMsgSlot49Bas1Repn2BusFrChAInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwMsgSlot49Bas1Repn2BusFrChAInit1
 *********************************************************************************************************************/
	/* Do Nothing */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwMsgSlot49Bas1Repn2BusFrChAPer1
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
 *   Std_ReturnType Rte_Read_BattRtnCurrAmpr_Val(float32 *data)
 *   Std_ReturnType Rte_Read_BattRtnCurrAmprQlfr_Val(BattRtnCurrAmprQlfr1 *data)
 *   Std_ReturnType Rte_Read_EpsCurrLimSts_Val(EpsCurrLimSts1 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_sigGroup_DT_EST_sigGroup_DT_EST(const sigGroup_DT_EST1 *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwMsgSlot49Bas1Repn2BusFrChAPer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwMsgSlot49Bas1Repn2BusFrChA_CODE) BmwMsgSlot49Bas1Repn2BusFrChAPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwMsgSlot49Bas1Repn2BusFrChAPer1
 *********************************************************************************************************************/
	/* Inputs */
    VAR(float32, AUTOMATIC) BattRtnCurrAmpr_Amp_T_f32;
    VAR(BattRtnCurrAmprQlfr1, AUTOMATIC) BattRtnCurrAmprQlfr_Cnt_T_enum;
    VAR(EpsCurrLimSts1, AUTOMATIC) EpsCurrLimSts_Cnt_T_enum;
    
    /* Output */
    VAR(sigGroup_DT_EST1, AUTOMATIC) SigGroup_Cnt_T_enum;
    
    /* Read Inputs */    
    (void)Rte_Read_BattRtnCurrAmpr_Val(&BattRtnCurrAmpr_Amp_T_f32);
    (void)Rte_Read_BattRtnCurrAmprQlfr_Val(&BattRtnCurrAmprQlfr_Cnt_T_enum);
    (void)Rte_Read_EpsCurrLimSts_Val(&EpsCurrLimSts_Cnt_T_enum);
    
    /* Populate Outputs */
    BattRtnCurrAmpr_Amp_T_f32 = Lim_f32(BattRtnCurrAmpr_Amp_T_f32, BATTRTNCURRAMPRLOLIM_AMP_F32, BATTRTNCURRAMPRHILIM_AMP_F32);
    SigGroup_Cnt_T_enum.AVL_I_ACT_EST = (AVL_I_ACT_EST1)BattRtnCurrAmpr_Amp_T_f32;
    SigGroup_Cnt_T_enum.ST_CULI_EST = EpsCurrLimSts_Cnt_T_enum;
    SigGroup_Cnt_T_enum.QU_AVL_I_ACT_EST = BattRtnCurrAmprQlfr_Cnt_T_enum;
    
    /* Write Output */
    (void)E2EPW_Write_sigGroup_DT_EST_sigGroup_DT_EST(&SigGroup_Cnt_T_enum);


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define BmwMsgSlot49Bas1Repn2BusFrChA_STOP_SEC_CODE
#include "BmwMsgSlot49Bas1Repn2BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


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
