/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  BmwMsgSlot49Bas1Repn2BusFrChA.c
 *        Config:  EPS.dpa
 *     SW-C Type:  BmwMsgSlot49Bas1Repn2BusFrChA
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <BmwMsgSlot49Bas1Repn2BusFrChA>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_5.1_777, MD_MSR_5.1_779 */
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
/* PRQA S 0614 EOF */ /* MD_Rte_TestCode */

/* PRQA S 3109 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3112 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3197 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3198 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3199 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3201 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3203 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3205 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3206 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3218 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3229 EOF */ /* MD_Rte_TestCode */
/* PRQA S 2002 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3334 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3417 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3426 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3453 EOF */ /* MD_Rte_TestCode */

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
 *   
 *
 * EpsCurrLimSts1
 *   
 *
 *********************************************************************************************************************/

#include "Rte_BmwMsgSlot49Bas1Repn2BusFrChA.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_BmwMsgSlot49Bas1Repn2BusFrChA.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"
#include "float.h"

static void BmwMsgSlot49Bas1Repn2BusFrChA_TestDefines(void);


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

  BmwMsgSlot49Bas1Repn2BusFrChA_TestDefines();


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
 *   E2E Protection Wrapper API:
 *   ---------------------------
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_sigGroup_DT_EST_sigGroup_DT_EST(const sigGroup_DT_EST1 *data)
 *
 *   E2E Protection Wrapper API:
 *   ---------------------------
 *   uint32 E2EPW_Write_sigGroup_DT_EST_sigGroup_DT_EST(sigGroup_DT_EST1 *data)
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

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  float32 Read_BattRtnCurrAmpr_Val;
  BattRtnCurrAmprQlfr1 Read_BattRtnCurrAmprQlfr_Val;
  EpsCurrLimSts1 Read_EpsCurrLimSts_Val;

  sigGroup_DT_EST1 Write_sigGroup_DT_EST_sigGroup_DT_EST;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_BmwMsgSlot49Bas1Repn2BusFrChA_Rte_Read_BattRtnCurrAmpr_Val(&Read_BattRtnCurrAmpr_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwMsgSlot49Bas1Repn2BusFrChA_Rte_Read_BattRtnCurrAmprQlfr_Val(&Read_BattRtnCurrAmprQlfr_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwMsgSlot49Bas1Repn2BusFrChA_Rte_Read_EpsCurrLimSts_Val(&Read_EpsCurrLimSts_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  (void)memset(&Write_sigGroup_DT_EST_sigGroup_DT_EST, 0, sizeof(Write_sigGroup_DT_EST_sigGroup_DT_EST));
  fct_status = TSC_BmwMsgSlot49Bas1Repn2BusFrChA_Rte_Write_sigGroup_DT_EST_sigGroup_DT_EST(&Write_sigGroup_DT_EST_sigGroup_DT_EST);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define BmwMsgSlot49Bas1Repn2BusFrChA_STOP_SEC_CODE
#include "BmwMsgSlot49Bas1Repn2BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void BmwMsgSlot49Bas1Repn2BusFrChA_TestDefines(void)
{
  /* Enumeration Data Types */

  AVL_I_ACT_EST1 Test_AVL_I_ACT_EST1_V_1 = I_SPEC_ARS_Funktionsschnittstelle_ist_nicht_verfuegbar;
  AVL_I_ACT_EST1 Test_AVL_I_ACT_EST1_V_2 = I_SPEC_ARS_Funktion_meldet_Fehler;
  AVL_I_ACT_EST1 Test_AVL_I_ACT_EST1_V_3 = I_SPEC_ARS_Signal_unbefuellt;

  BattRtnCurrAmprQlfr1 Test_BattRtnCurrAmprQlfr1_V_1 = BATTRTNCURRAMPRQLFR_FCTRPRTERR;
  BattRtnCurrAmprQlfr1 Test_BattRtnCurrAmprQlfr1_V_2 = BATTRTNCURRAMPRQLFR_FCTACTVSECUR;
  BattRtnCurrAmprQlfr1 Test_BattRtnCurrAmprQlfr1_V_3 = BATTRTNCURRAMPRQLFR_FCTNOTACTV;
  BattRtnCurrAmprQlfr1 Test_BattRtnCurrAmprQlfr1_V_4 = BATTRTNCURRAMPRQLFR_FCTIFNOTAVL;
  BattRtnCurrAmprQlfr1 Test_BattRtnCurrAmprQlfr1_V_5 = BATTRTNCURRAMPRQLFR_INVLD;

  EpsCurrLimSts1 Test_EpsCurrLimSts1_V_1 = EPSCURRLIMSTST_NOCURRLIMR;
  EpsCurrLimSts1 Test_EpsCurrLimSts1_V_2 = EPSCURRLIMSTST_CMFTCURRLIMR;
  EpsCurrLimSts1 Test_EpsCurrLimSts1_V_3 = EPSCURRLIMSTST_MAXCURRLIMN;
  EpsCurrLimSts1 Test_EpsCurrLimSts1_V_4 = EPSCURRLIMSTST_RESDNOTAVL;
  EpsCurrLimSts1 Test_EpsCurrLimSts1_V_5 = EPSCURRLIMSTST_RESDERR;
  EpsCurrLimSts1 Test_EpsCurrLimSts1_V_6 = EPSCURRLIMSTST_SIGUNFLD;

  QU_AVL_I_ACT_EST1 Test_QU_AVL_I_ACT_EST1_V_1 = QU_SUM_AVL_I_DRDY_SFY_Wert_gueltig_abgesichert;
  QU_AVL_I_ACT_EST1 Test_QU_AVL_I_ACT_EST1_V_2 = QU_SUM_AVL_I_DRDY_SFY_Wert_gueltig_eingeschraenkt;
  QU_AVL_I_ACT_EST1 Test_QU_AVL_I_ACT_EST1_V_3 = QU_SUM_AVL_I_DRDY_SFY_Wert_nicht_verfuegbar_Fehler;
  QU_AVL_I_ACT_EST1 Test_QU_AVL_I_ACT_EST1_V_4 = QU_SUM_AVL_I_DRDY_SFY_Wert_nicht_verfuegbar;
  QU_AVL_I_ACT_EST1 Test_QU_AVL_I_ACT_EST1_V_5 = QU_SUM_AVL_I_DRDY_SFY_Signal_unbefuellt;

  ST_CULI_EST1 Test_ST_CULI_EST1_V_1 = ST_CULI_EST_Keine_Strombegrenzung;
  ST_CULI_EST1 Test_ST_CULI_EST1_V_2 = ST_CULI_EST_Komfort_Strombegrenzung;
  ST_CULI_EST1 Test_ST_CULI_EST1_V_3 = ST_CULI_EST_Maximale_Strombegrenzung;
  ST_CULI_EST1 Test_ST_CULI_EST1_V_4 = ST_CULI_EST_Reserviert_nicht_verfuegbar;
  ST_CULI_EST1 Test_ST_CULI_EST1_V_5 = ST_CULI_EST_Reserviert_Fehler;
  ST_CULI_EST1 Test_ST_CULI_EST1_V_6 = ST_CULI_EST_Signal_unbefuellt;
}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_TestCode:
     Reason:     This justification is used within the generated test code by the Rte Analyzer.
     Risk:       No functional risk.
     Prevention: Not required.

*/
