/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  BmwMsgSlot49Bas0Repn2BusFrChA.c
 *        Config:  EPS.dpa
 *     SW-C Type:  BmwMsgSlot49Bas0Repn2BusFrChA
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <BmwMsgSlot49Bas0Repn2BusFrChA>
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
 * SigQlfr1
 *   
 *
 *********************************************************************************************************************/

#include "Rte_BmwMsgSlot49Bas0Repn2BusFrChA.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_BmwMsgSlot49Bas0Repn2BusFrChA.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"
#include "float.h"

static void BmwMsgSlot49Bas0Repn2BusFrChA_TestDefines(void);


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

  uint8 PimPerCntr;

  float32 BmwMsgSlot49Bas0Repn2BusFrChARackEstimnLowrLim_Val_data;
  float32 BmwMsgSlot49Bas0Repn2BusFrChARackEstimnUpprLim_Val_data;
  sint8 BmwMsgSlot49Bas0Repn2BusFrChABmwSteerPolarity_Val_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimPerCntr = *TSC_BmwMsgSlot49Bas0Repn2BusFrChA_Rte_Pim_PerCntr();
  *TSC_BmwMsgSlot49Bas0Repn2BusFrChA_Rte_Pim_PerCntr() = PimPerCntr;

  BmwMsgSlot49Bas0Repn2BusFrChARackEstimnLowrLim_Val_data = TSC_BmwMsgSlot49Bas0Repn2BusFrChA_Rte_Prm_BmwMsgSlot49Bas0Repn2BusFrChARackEstimnLowrLim_Val();
  BmwMsgSlot49Bas0Repn2BusFrChARackEstimnUpprLim_Val_data = TSC_BmwMsgSlot49Bas0Repn2BusFrChA_Rte_Prm_BmwMsgSlot49Bas0Repn2BusFrChARackEstimnUpprLim_Val();
  BmwMsgSlot49Bas0Repn2BusFrChABmwSteerPolarity_Val_data = TSC_BmwMsgSlot49Bas0Repn2BusFrChA_Rte_Prm_BmwMsgSlot49Bas0Repn2BusFrChABmwSteerPolarity_Val();

  BmwMsgSlot49Bas0Repn2BusFrChA_TestDefines();


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
 *   E2E Protection Wrapper API:
 *   ---------------------------
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_sigGroup_AVL_FORC_GRD_sigGroup_AVL_FORC_GRD(const sigGroup_AVL_FORC_GRD1 *data)
 *   Std_ReturnType Rte_Write_sigGroup_AVL_STMOM_DV_ACT_sigGroup_AVL_STMOM_DV_ACT(const sigGroup_AVL_STMOM_DV_ACT1 *data)
 *
 *   E2E Protection Wrapper API:
 *   ---------------------------
 *   uint32 E2EPW_Write_sigGroup_AVL_FORC_GRD_sigGroup_AVL_FORC_GRD(sigGroup_AVL_FORC_GRD1 *data)
 *   uint32 E2EPW_Write_sigGroup_AVL_STMOM_DV_ACT_sigGroup_AVL_STMOM_DV_ACT(sigGroup_AVL_STMOM_DV_ACT1 *data)
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

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  float32 Read_ElecInpPwrEstim_Val;
  float32 Read_HwTq_Val;
  SigQlfr1 Read_HwTq4Qlfr_Val;
  SigQlfr1 Read_HwTq5Qlfr_Val;
  float32 Read_RackFEstimd_Val;

  uint8 PimPerCntr;

  float32 BmwMsgSlot49Bas0Repn2BusFrChARackEstimnLowrLim_Val_data;
  float32 BmwMsgSlot49Bas0Repn2BusFrChARackEstimnUpprLim_Val_data;
  sint8 BmwMsgSlot49Bas0Repn2BusFrChABmwSteerPolarity_Val_data;

  sigGroup_AVL_FORC_GRD1 Write_sigGroup_AVL_FORC_GRD_sigGroup_AVL_FORC_GRD;
  sigGroup_AVL_STMOM_DV_ACT1 Write_sigGroup_AVL_STMOM_DV_ACT_sigGroup_AVL_STMOM_DV_ACT;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimPerCntr = *TSC_BmwMsgSlot49Bas0Repn2BusFrChA_Rte_Pim_PerCntr();
  *TSC_BmwMsgSlot49Bas0Repn2BusFrChA_Rte_Pim_PerCntr() = PimPerCntr;

  BmwMsgSlot49Bas0Repn2BusFrChARackEstimnLowrLim_Val_data = TSC_BmwMsgSlot49Bas0Repn2BusFrChA_Rte_Prm_BmwMsgSlot49Bas0Repn2BusFrChARackEstimnLowrLim_Val();
  BmwMsgSlot49Bas0Repn2BusFrChARackEstimnUpprLim_Val_data = TSC_BmwMsgSlot49Bas0Repn2BusFrChA_Rte_Prm_BmwMsgSlot49Bas0Repn2BusFrChARackEstimnUpprLim_Val();
  BmwMsgSlot49Bas0Repn2BusFrChABmwSteerPolarity_Val_data = TSC_BmwMsgSlot49Bas0Repn2BusFrChA_Rte_Prm_BmwMsgSlot49Bas0Repn2BusFrChABmwSteerPolarity_Val();

  fct_status = TSC_BmwMsgSlot49Bas0Repn2BusFrChA_Rte_Read_ElecInpPwrEstim_Val(&Read_ElecInpPwrEstim_Val);
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

  fct_status = TSC_BmwMsgSlot49Bas0Repn2BusFrChA_Rte_Read_HwTq_Val(&Read_HwTq_Val);
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

  fct_status = TSC_BmwMsgSlot49Bas0Repn2BusFrChA_Rte_Read_HwTq4Qlfr_Val(&Read_HwTq4Qlfr_Val);
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

  fct_status = TSC_BmwMsgSlot49Bas0Repn2BusFrChA_Rte_Read_HwTq5Qlfr_Val(&Read_HwTq5Qlfr_Val);
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

  fct_status = TSC_BmwMsgSlot49Bas0Repn2BusFrChA_Rte_Read_RackFEstimd_Val(&Read_RackFEstimd_Val);
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

  (void)memset(&Write_sigGroup_AVL_FORC_GRD_sigGroup_AVL_FORC_GRD, 0, sizeof(Write_sigGroup_AVL_FORC_GRD_sigGroup_AVL_FORC_GRD));
  fct_status = TSC_BmwMsgSlot49Bas0Repn2BusFrChA_Rte_Write_sigGroup_AVL_FORC_GRD_sigGroup_AVL_FORC_GRD(&Write_sigGroup_AVL_FORC_GRD_sigGroup_AVL_FORC_GRD);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_sigGroup_AVL_STMOM_DV_ACT_sigGroup_AVL_STMOM_DV_ACT, 0, sizeof(Write_sigGroup_AVL_STMOM_DV_ACT_sigGroup_AVL_STMOM_DV_ACT));
  fct_status = TSC_BmwMsgSlot49Bas0Repn2BusFrChA_Rte_Write_sigGroup_AVL_STMOM_DV_ACT_sigGroup_AVL_STMOM_DV_ACT(&Write_sigGroup_AVL_STMOM_DV_ACT_sigGroup_AVL_STMOM_DV_ACT);
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


#define BmwMsgSlot49Bas0Repn2BusFrChA_STOP_SEC_CODE
#include "BmwMsgSlot49Bas0Repn2BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void BmwMsgSlot49Bas0Repn2BusFrChA_TestDefines(void)
{
  /* Enumeration Data Types */

  ALIV_AVL_FORC_GRD1 Test_ALIV_AVL_FORC_GRD1_V_1 = ALIV_COU_4_Zaehlerstand0DotDotE;
  ALIV_AVL_FORC_GRD1 Test_ALIV_AVL_FORC_GRD1_V_2 = ALIV_COU_4_SignalUngueltig;

  ALIV_AVL_STMOM_DV_ACT1 Test_ALIV_AVL_STMOM_DV_ACT1_V_1 = ALIV_COU_4_Zaehlerstand0DotDotE;
  ALIV_AVL_STMOM_DV_ACT1 Test_ALIV_AVL_STMOM_DV_ACT1_V_2 = ALIV_COU_4_SignalUngueltig;

  QU_AVL_FORC_GRD1 Test_QU_AVL_FORC_GRD1_V_1 = QU_AVL_FORC_GRD_Initialisierung;
  QU_AVL_FORC_GRD1 Test_QU_AVL_FORC_GRD1_V_2 = QU_AVL_FORC_GRD_SignalwertIstGueltig;
  QU_AVL_FORC_GRD1 Test_QU_AVL_FORC_GRD1_V_3 = QU_AVL_FORC_GRD_SignalwertIstUngueltigZustandSlashStatusTemporaer;
  QU_AVL_FORC_GRD1 Test_QU_AVL_FORC_GRD1_V_4 = QU_AVL_FORC_GRD_SignalUngueltig;

  QU_AVL_STMOM_DV_ACT1 Test_QU_AVL_STMOM_DV_ACT1_V_1 = QU_AVL_STMOM_DV_ACT_Initialisierung;
  QU_AVL_STMOM_DV_ACT1 Test_QU_AVL_STMOM_DV_ACT1_V_2 = QU_AVL_STMOM_DV_ACT_SignalwertIstGueltigUndAbgesichertUndPlausibilisiert;
  QU_AVL_STMOM_DV_ACT1 Test_QU_AVL_STMOM_DV_ACT1_V_3 = QU_AVL_STMOM_DV_ACT_SignalwertIstUngueltigZustandSlashStatusTemporaer;
  QU_AVL_STMOM_DV_ACT1 Test_QU_AVL_STMOM_DV_ACT1_V_4 = QU_AVL_STMOM_DV_ACT_SignalwertIstUngueltig;
  QU_AVL_STMOM_DV_ACT1 Test_QU_AVL_STMOM_DV_ACT1_V_5 = QU_AVL_STMOM_DV_ACT_SignalUngueltig;

  SigQlfr1 Test_SigQlfr1_V_1 = SIGQLFR_NORES;
  SigQlfr1 Test_SigQlfr1_V_2 = SIGQLFR_PASSD;
  SigQlfr1 Test_SigQlfr1_V_3 = SIGQLFR_FAILD;
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
