/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  BmwMsgSlot234Bas1Repn2BusFrChA.c
 *        Config:  EPS.dpa
 *     SW-C Type:  BmwMsgSlot234Bas1Repn2BusFrChA
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <BmwMsgSlot234Bas1Repn2BusFrChA>
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
 * BmwEpsFctSts1
 *   
 *
 *********************************************************************************************************************/

#include "Rte_BmwMsgSlot234Bas1Repn2BusFrChA.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_BmwMsgSlot234Bas1Repn2BusFrChA.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"

static void BmwMsgSlot234Bas1Repn2BusFrChA_TestDefines(void);


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
 * CRC_ST_EST_FTAX1: Integer in interval [0...255]
 * ST_EST_dummy_16_231: Integer in interval [0...255]
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * ALIV_ST_EST_FTAX1: Enumeration of integer in interval [0...255] with enumerators
 *   ALIV_COU_4_Zaehlerstand0DotDotE (0U)
 *   ALIV_COU_4_SignalUngueltig (15U)
 * BmwEpsFctSts1: Enumeration of integer in interval [0...255] with enumerators
 *   BMWEPSFCTSTS_FCTINFALLBACK (49U)
 *   BMWEPSFCTSTS_FCTINFALLBACKEMGYFCNENVTLINFLSACTV (51U)
 *   BMWEPSFCTSTS_NOTAVIERR (96U)
 *   BMWEPSFCTSTS_ININ (128U)
 *   BMWEPSFCTSTS_FCTAVIACTV12VEPS (160U)
 *   BMWEPSFCTSTS_FCTAVIACTVEMGYFCNENVTLINFLSACTV (162U)
 *   BMWEPSFCTSTS_FCTAVIACTV12VEAS (164U)
 *   BMWEPSFCTSTS_FCTAVIACTV24VEAS (168U)
 *   BMWEPSFCTSTS_FCTTMPINFALLBACK (176U)
 *   BMWEPSFCTSTS_FCTTMPINFALLBACKEMGYFCNENVTLINFLSACT (178U)
 *   BMWEPSFCTSTS_NOTAVISWDOFF (224U)
 *   BMWEPSFCTSTS_INVLD (255U)
 * DrvgDynIfSt1: Enumeration of integer in interval [0...255] with enumerators
 *   DRVGDYNIFST_IFAVLRDYFOROPERWOADDLDAMPG (32U)
 *   DRVGDYNIFST_IFACTVADDLDAMPGNOTAVL (33U)
 *   DRVGDYNIFST_IFAVLRDYFOROPERADDLDAMPG (34U)
 *   DRVGDYNIFST_IFACTVADDLDAMPGAVL (35U)
 *   DRVGDYNIFST_SRVNOTAVLERR (96U)
 *   DRVGDYNIFST_IFINID (128U)
 *   DRVGDYNIFST_SRVNOTAVLSTBPMA (224U)
 *   DRVGDYNIFST_SRVNOTAVLSTBEPSSTS (225U)
 *   DRVGDYNIFST_INVLDSIG (255U)
 * HaptcFbSt1: Enumeration of integer in interval [0...255] with enumerators
 *   HAPTCFBST_FCTAVLNOTACTV (1U)
 *   HAPTCFBST_ERR (6U)
 *   HAPTCFBST_FCTAVLACTV (9U)
 *   HAPTCFBST_FCTNOTAVL (14U)
 *   HAPTCFBST_INVLDSIG (15U)
 * QU_FN_EST1: Enumeration of integer in interval [0...255] with enumerators
 *   QU_FN_EST_Initialisierung (128U)
 *   QU_FN_EST_FunktionVerfuegbar_Aktiv12VEPS (160U)
 *   QU_FN_EST_FunktionVerfuegbar_Aktiv12VEAS (164U)
 *   QU_FN_EST_FunktionVerfuegbar_Aktiv24VEAS (168U)
 *   QU_FN_EST_FunktionVerfuegbar_AktivNotfallfunktionUmwelteinfluesse_Aktiv (162U)
 *   QU_FN_EST_FunktionInRueckfallebene (49U)
 *   QU_FN_EST_FunktionInRueckfallebeneNotfallfunktionUmwelteinfluesse_Aktiv (51U)
 *   QU_FN_EST_FunktionTemporaerInRueckfallebene (176U)
 *   QU_FN_EST_FunktionTemporaerInRueckfallebeneNotfallfunktionUmwelteinfluesse_Aktiv (178U)
 *   QU_FN_EST_FunktionNichtVerfuegbar_Fehler (96U)
 *   QU_FN_EST_FunktionNichtVerfuegbar_Ausgeschaltet (224U)
 *   QU_FN_EST_SignalUngueltig (255U)
 * QU_FN_VIB_EPS1: Enumeration of integer in interval [0...255] with enumerators
 *   QU_FN_VIB_EPS_Funktion_verfuegbar_nicht_aktiv (1U)
 *   QU_FN_VIB_EPS_Funktion_verfuegbar_aktiv (9U)
 *   QU_FN_VIB_EPS_Funktion_nicht_verfuegbar (14U)
 *   QU_FN_VIB_EPS_Fehler (6U)
 *   QU_FN_VIB_EPS_Signal_unbefuellt (15U)
 * QU_SER_STMOM_DV_ACT1: Enumeration of integer in interval [0...255] with enumerators
 *   QU_SER_STMOM_STMOM_DV_ACT_SchnittstelleWirdInitialisiert (128U)
 *   QU_SER_STMOM_STMOM_DV_ACT_SchnittstelleVerfuegbarSlashFunktionsbereitOhneZusatzdaempfung (32U)
 *   QU_SER_STMOM_STMOM_DV_ACT_SchnittstelleVerfuegbarSlashFunktionsbereitMitZusatzdaempfung (34U)
 *   QU_SER_STMOM_STMOM_DV_ACT_SchnittstelleAktiv_ZusatzdaempfungNichtVerfuegbar (33U)
 *   QU_SER_STMOM_STMOM_DV_ACT_SchnittstelleAktiv_ZusatzdaempfungVerfuegbar (35U)
 *   QU_SER_STMOM_STMOM_DV_ACT_ServiceNichtVerfuegbar_Fehler (96U)
 *   QU_SER_STMOM_STMOM_DV_ACT_ServiceNichtVerfuegbar_Standby_PMA (224U)
 *   QU_SER_STMOM_STMOM_DV_ACT_ServiceNichtVerfuegbar_Standby_EPSStatus (225U)
 *   QU_SER_STMOM_STMOM_DV_ACT_SignalUngueltig (255U)
 *
 * Record Types:
 * =============
 * sigGroup_ST_EST1: Record with elements
 *   QU_SER_STMOM_DV_ACT of type QU_SER_STMOM_DV_ACT1
 *   QU_FN_VIB_EPS of type QU_FN_VIB_EPS1
 *   ST_EST_dummy_16_23 of type ST_EST_dummy_16_231
 *   ALIV_ST_EST_FTAX of type ALIV_ST_EST_FTAX1
 *   CRC_ST_EST_FTAX of type CRC_ST_EST_FTAX1
 *   QU_FN_EST of type QU_FN_EST1
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   BmwEpsFctSts1 *Rte_Pim_BmwEpsFctStsPrev(void)
 *   uint8 *Rte_Pim_BurstModCntr(void)
 *   uint8 *Rte_Pim_CycCntr(void)
 *   DrvgDynIfSt1 *Rte_Pim_DrvgDynIfStPrev(void)
 *   HaptcFbSt1 *Rte_Pim_HaptcFbStPrev(void)
 *   uint8 *Rte_Pim_PerdCntr(void)
 *
 *********************************************************************************************************************/


#define BmwMsgSlot234Bas1Repn2BusFrChA_START_SEC_CODE
#include "BmwMsgSlot234Bas1Repn2BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwMsgSlot234Bas1Repn2BusFrChAInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwMsgSlot234Bas1Repn2BusFrChAInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwMsgSlot234Bas1Repn2BusFrChA_CODE) BmwMsgSlot234Bas1Repn2BusFrChAInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwMsgSlot234Bas1Repn2BusFrChAInit1
 *********************************************************************************************************************/

  BmwEpsFctSts1 PimBmwEpsFctStsPrev;
  uint8 PimBurstModCntr;
  uint8 PimCycCntr;
  DrvgDynIfSt1 PimDrvgDynIfStPrev;
  HaptcFbSt1 PimHaptcFbStPrev;
  uint8 PimPerdCntr;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimBmwEpsFctStsPrev = *TSC_BmwMsgSlot234Bas1Repn2BusFrChA_Rte_Pim_BmwEpsFctStsPrev();
  *TSC_BmwMsgSlot234Bas1Repn2BusFrChA_Rte_Pim_BmwEpsFctStsPrev() = PimBmwEpsFctStsPrev;
  PimBurstModCntr = *TSC_BmwMsgSlot234Bas1Repn2BusFrChA_Rte_Pim_BurstModCntr();
  *TSC_BmwMsgSlot234Bas1Repn2BusFrChA_Rte_Pim_BurstModCntr() = PimBurstModCntr;
  PimCycCntr = *TSC_BmwMsgSlot234Bas1Repn2BusFrChA_Rte_Pim_CycCntr();
  *TSC_BmwMsgSlot234Bas1Repn2BusFrChA_Rte_Pim_CycCntr() = PimCycCntr;
  PimDrvgDynIfStPrev = *TSC_BmwMsgSlot234Bas1Repn2BusFrChA_Rte_Pim_DrvgDynIfStPrev();
  *TSC_BmwMsgSlot234Bas1Repn2BusFrChA_Rte_Pim_DrvgDynIfStPrev() = PimDrvgDynIfStPrev;
  PimHaptcFbStPrev = *TSC_BmwMsgSlot234Bas1Repn2BusFrChA_Rte_Pim_HaptcFbStPrev();
  *TSC_BmwMsgSlot234Bas1Repn2BusFrChA_Rte_Pim_HaptcFbStPrev() = PimHaptcFbStPrev;
  PimPerdCntr = *TSC_BmwMsgSlot234Bas1Repn2BusFrChA_Rte_Pim_PerdCntr();
  *TSC_BmwMsgSlot234Bas1Repn2BusFrChA_Rte_Pim_PerdCntr() = PimPerdCntr;

  BmwMsgSlot234Bas1Repn2BusFrChA_TestDefines();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwMsgSlot234Bas1Repn2BusFrChAPer1
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
 *   Std_ReturnType Rte_Read_BmwEpsFctSts_Val(BmwEpsFctSts1 *data)
 *   Std_ReturnType Rte_Read_DrvgDynIfSt_Val(DrvgDynIfSt1 *data)
 *   Std_ReturnType Rte_Read_HaptcFbSt_Val(HaptcFbSt1 *data)
 *
 *   E2E Protection Wrapper API:
 *   ---------------------------
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_sigGroup_ST_EST_sigGroup_ST_EST(const sigGroup_ST_EST1 *data)
 *
 *   E2E Protection Wrapper API:
 *   ---------------------------
 *   uint32 E2EPW_Write_sigGroup_ST_EST_sigGroup_ST_EST(sigGroup_ST_EST1 *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwMsgSlot234Bas1Repn2BusFrChAPer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwMsgSlot234Bas1Repn2BusFrChA_CODE) BmwMsgSlot234Bas1Repn2BusFrChAPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwMsgSlot234Bas1Repn2BusFrChAPer1
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  BmwEpsFctSts1 Read_BmwEpsFctSts_Val;
  DrvgDynIfSt1 Read_DrvgDynIfSt_Val;
  HaptcFbSt1 Read_HaptcFbSt_Val;

  BmwEpsFctSts1 PimBmwEpsFctStsPrev;
  uint8 PimBurstModCntr;
  uint8 PimCycCntr;
  DrvgDynIfSt1 PimDrvgDynIfStPrev;
  HaptcFbSt1 PimHaptcFbStPrev;
  uint8 PimPerdCntr;

  sigGroup_ST_EST1 Write_sigGroup_ST_EST_sigGroup_ST_EST;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimBmwEpsFctStsPrev = *TSC_BmwMsgSlot234Bas1Repn2BusFrChA_Rte_Pim_BmwEpsFctStsPrev();
  *TSC_BmwMsgSlot234Bas1Repn2BusFrChA_Rte_Pim_BmwEpsFctStsPrev() = PimBmwEpsFctStsPrev;
  PimBurstModCntr = *TSC_BmwMsgSlot234Bas1Repn2BusFrChA_Rte_Pim_BurstModCntr();
  *TSC_BmwMsgSlot234Bas1Repn2BusFrChA_Rte_Pim_BurstModCntr() = PimBurstModCntr;
  PimCycCntr = *TSC_BmwMsgSlot234Bas1Repn2BusFrChA_Rte_Pim_CycCntr();
  *TSC_BmwMsgSlot234Bas1Repn2BusFrChA_Rte_Pim_CycCntr() = PimCycCntr;
  PimDrvgDynIfStPrev = *TSC_BmwMsgSlot234Bas1Repn2BusFrChA_Rte_Pim_DrvgDynIfStPrev();
  *TSC_BmwMsgSlot234Bas1Repn2BusFrChA_Rte_Pim_DrvgDynIfStPrev() = PimDrvgDynIfStPrev;
  PimHaptcFbStPrev = *TSC_BmwMsgSlot234Bas1Repn2BusFrChA_Rte_Pim_HaptcFbStPrev();
  *TSC_BmwMsgSlot234Bas1Repn2BusFrChA_Rte_Pim_HaptcFbStPrev() = PimHaptcFbStPrev;
  PimPerdCntr = *TSC_BmwMsgSlot234Bas1Repn2BusFrChA_Rte_Pim_PerdCntr();
  *TSC_BmwMsgSlot234Bas1Repn2BusFrChA_Rte_Pim_PerdCntr() = PimPerdCntr;

  fct_status = TSC_BmwMsgSlot234Bas1Repn2BusFrChA_Rte_Read_BmwEpsFctSts_Val(&Read_BmwEpsFctSts_Val);
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

  fct_status = TSC_BmwMsgSlot234Bas1Repn2BusFrChA_Rte_Read_DrvgDynIfSt_Val(&Read_DrvgDynIfSt_Val);
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

  fct_status = TSC_BmwMsgSlot234Bas1Repn2BusFrChA_Rte_Read_HaptcFbSt_Val(&Read_HaptcFbSt_Val);
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

  (void)memset(&Write_sigGroup_ST_EST_sigGroup_ST_EST, 0, sizeof(Write_sigGroup_ST_EST_sigGroup_ST_EST));
  fct_status = TSC_BmwMsgSlot234Bas1Repn2BusFrChA_Rte_Write_sigGroup_ST_EST_sigGroup_ST_EST(&Write_sigGroup_ST_EST_sigGroup_ST_EST);
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


#define BmwMsgSlot234Bas1Repn2BusFrChA_STOP_SEC_CODE
#include "BmwMsgSlot234Bas1Repn2BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void BmwMsgSlot234Bas1Repn2BusFrChA_TestDefines(void)
{
  /* Enumeration Data Types */

  ALIV_ST_EST_FTAX1 Test_ALIV_ST_EST_FTAX1_V_1 = ALIV_COU_4_Zaehlerstand0DotDotE;
  ALIV_ST_EST_FTAX1 Test_ALIV_ST_EST_FTAX1_V_2 = ALIV_COU_4_SignalUngueltig;

  BmwEpsFctSts1 Test_BmwEpsFctSts1_V_1 = BMWEPSFCTSTS_FCTINFALLBACK;
  BmwEpsFctSts1 Test_BmwEpsFctSts1_V_2 = BMWEPSFCTSTS_FCTINFALLBACKEMGYFCNENVTLINFLSACTV;
  BmwEpsFctSts1 Test_BmwEpsFctSts1_V_3 = BMWEPSFCTSTS_NOTAVIERR;
  BmwEpsFctSts1 Test_BmwEpsFctSts1_V_4 = BMWEPSFCTSTS_ININ;
  BmwEpsFctSts1 Test_BmwEpsFctSts1_V_5 = BMWEPSFCTSTS_FCTAVIACTV12VEPS;
  BmwEpsFctSts1 Test_BmwEpsFctSts1_V_6 = BMWEPSFCTSTS_FCTAVIACTVEMGYFCNENVTLINFLSACTV;
  BmwEpsFctSts1 Test_BmwEpsFctSts1_V_7 = BMWEPSFCTSTS_FCTAVIACTV12VEAS;
  BmwEpsFctSts1 Test_BmwEpsFctSts1_V_8 = BMWEPSFCTSTS_FCTAVIACTV24VEAS;
  BmwEpsFctSts1 Test_BmwEpsFctSts1_V_9 = BMWEPSFCTSTS_FCTTMPINFALLBACK;
  BmwEpsFctSts1 Test_BmwEpsFctSts1_V_10 = BMWEPSFCTSTS_FCTTMPINFALLBACKEMGYFCNENVTLINFLSACT;
  BmwEpsFctSts1 Test_BmwEpsFctSts1_V_11 = BMWEPSFCTSTS_NOTAVISWDOFF;
  BmwEpsFctSts1 Test_BmwEpsFctSts1_V_12 = BMWEPSFCTSTS_INVLD;

  DrvgDynIfSt1 Test_DrvgDynIfSt1_V_1 = DRVGDYNIFST_IFAVLRDYFOROPERWOADDLDAMPG;
  DrvgDynIfSt1 Test_DrvgDynIfSt1_V_2 = DRVGDYNIFST_IFACTVADDLDAMPGNOTAVL;
  DrvgDynIfSt1 Test_DrvgDynIfSt1_V_3 = DRVGDYNIFST_IFAVLRDYFOROPERADDLDAMPG;
  DrvgDynIfSt1 Test_DrvgDynIfSt1_V_4 = DRVGDYNIFST_IFACTVADDLDAMPGAVL;
  DrvgDynIfSt1 Test_DrvgDynIfSt1_V_5 = DRVGDYNIFST_SRVNOTAVLERR;
  DrvgDynIfSt1 Test_DrvgDynIfSt1_V_6 = DRVGDYNIFST_IFINID;
  DrvgDynIfSt1 Test_DrvgDynIfSt1_V_7 = DRVGDYNIFST_SRVNOTAVLSTBPMA;
  DrvgDynIfSt1 Test_DrvgDynIfSt1_V_8 = DRVGDYNIFST_SRVNOTAVLSTBEPSSTS;
  DrvgDynIfSt1 Test_DrvgDynIfSt1_V_9 = DRVGDYNIFST_INVLDSIG;

  HaptcFbSt1 Test_HaptcFbSt1_V_1 = HAPTCFBST_FCTAVLNOTACTV;
  HaptcFbSt1 Test_HaptcFbSt1_V_2 = HAPTCFBST_ERR;
  HaptcFbSt1 Test_HaptcFbSt1_V_3 = HAPTCFBST_FCTAVLACTV;
  HaptcFbSt1 Test_HaptcFbSt1_V_4 = HAPTCFBST_FCTNOTAVL;
  HaptcFbSt1 Test_HaptcFbSt1_V_5 = HAPTCFBST_INVLDSIG;

  QU_FN_EST1 Test_QU_FN_EST1_V_1 = QU_FN_EST_Initialisierung;
  QU_FN_EST1 Test_QU_FN_EST1_V_2 = QU_FN_EST_FunktionVerfuegbar_Aktiv12VEPS;
  QU_FN_EST1 Test_QU_FN_EST1_V_3 = QU_FN_EST_FunktionVerfuegbar_Aktiv12VEAS;
  QU_FN_EST1 Test_QU_FN_EST1_V_4 = QU_FN_EST_FunktionVerfuegbar_Aktiv24VEAS;
  QU_FN_EST1 Test_QU_FN_EST1_V_5 = QU_FN_EST_FunktionVerfuegbar_AktivNotfallfunktionUmwelteinfluesse_Aktiv;
  QU_FN_EST1 Test_QU_FN_EST1_V_6 = QU_FN_EST_FunktionInRueckfallebene;
  QU_FN_EST1 Test_QU_FN_EST1_V_7 = QU_FN_EST_FunktionInRueckfallebeneNotfallfunktionUmwelteinfluesse_Aktiv;
  QU_FN_EST1 Test_QU_FN_EST1_V_8 = QU_FN_EST_FunktionTemporaerInRueckfallebene;
  QU_FN_EST1 Test_QU_FN_EST1_V_9 = QU_FN_EST_FunktionTemporaerInRueckfallebeneNotfallfunktionUmwelteinfluesse_Aktiv;
  QU_FN_EST1 Test_QU_FN_EST1_V_10 = QU_FN_EST_FunktionNichtVerfuegbar_Fehler;
  QU_FN_EST1 Test_QU_FN_EST1_V_11 = QU_FN_EST_FunktionNichtVerfuegbar_Ausgeschaltet;
  QU_FN_EST1 Test_QU_FN_EST1_V_12 = QU_FN_EST_SignalUngueltig;

  QU_FN_VIB_EPS1 Test_QU_FN_VIB_EPS1_V_1 = QU_FN_VIB_EPS_Funktion_verfuegbar_nicht_aktiv;
  QU_FN_VIB_EPS1 Test_QU_FN_VIB_EPS1_V_2 = QU_FN_VIB_EPS_Funktion_verfuegbar_aktiv;
  QU_FN_VIB_EPS1 Test_QU_FN_VIB_EPS1_V_3 = QU_FN_VIB_EPS_Funktion_nicht_verfuegbar;
  QU_FN_VIB_EPS1 Test_QU_FN_VIB_EPS1_V_4 = QU_FN_VIB_EPS_Fehler;
  QU_FN_VIB_EPS1 Test_QU_FN_VIB_EPS1_V_5 = QU_FN_VIB_EPS_Signal_unbefuellt;

  QU_SER_STMOM_DV_ACT1 Test_QU_SER_STMOM_DV_ACT1_V_1 = QU_SER_STMOM_STMOM_DV_ACT_SchnittstelleWirdInitialisiert;
  QU_SER_STMOM_DV_ACT1 Test_QU_SER_STMOM_DV_ACT1_V_2 = QU_SER_STMOM_STMOM_DV_ACT_SchnittstelleVerfuegbarSlashFunktionsbereitOhneZusatzdaempfung;
  QU_SER_STMOM_DV_ACT1 Test_QU_SER_STMOM_DV_ACT1_V_3 = QU_SER_STMOM_STMOM_DV_ACT_SchnittstelleVerfuegbarSlashFunktionsbereitMitZusatzdaempfung;
  QU_SER_STMOM_DV_ACT1 Test_QU_SER_STMOM_DV_ACT1_V_4 = QU_SER_STMOM_STMOM_DV_ACT_SchnittstelleAktiv_ZusatzdaempfungNichtVerfuegbar;
  QU_SER_STMOM_DV_ACT1 Test_QU_SER_STMOM_DV_ACT1_V_5 = QU_SER_STMOM_STMOM_DV_ACT_SchnittstelleAktiv_ZusatzdaempfungVerfuegbar;
  QU_SER_STMOM_DV_ACT1 Test_QU_SER_STMOM_DV_ACT1_V_6 = QU_SER_STMOM_STMOM_DV_ACT_ServiceNichtVerfuegbar_Fehler;
  QU_SER_STMOM_DV_ACT1 Test_QU_SER_STMOM_DV_ACT1_V_7 = QU_SER_STMOM_STMOM_DV_ACT_ServiceNichtVerfuegbar_Standby_PMA;
  QU_SER_STMOM_DV_ACT1 Test_QU_SER_STMOM_DV_ACT1_V_8 = QU_SER_STMOM_STMOM_DV_ACT_ServiceNichtVerfuegbar_Standby_EPSStatus;
  QU_SER_STMOM_DV_ACT1 Test_QU_SER_STMOM_DV_ACT1_V_9 = QU_SER_STMOM_STMOM_DV_ACT_SignalUngueltig;
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
