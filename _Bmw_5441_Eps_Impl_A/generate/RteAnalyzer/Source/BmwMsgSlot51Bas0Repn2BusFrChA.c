/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  BmwMsgSlot51Bas0Repn2BusFrChA.c
 *        Config:  EPS.dpa
 *     SW-C Type:  BmwMsgSlot51Bas0Repn2BusFrChA
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <BmwMsgSlot51Bas0Repn2BusFrChA>
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
 * BmwPinionAgQlfr1
 *   
 *
 * BmwSeldPosnUnit1
 *   
 *
 * BmwTqSnsrIdx1
 *   
 *
 *********************************************************************************************************************/

#include "Rte_BmwMsgSlot51Bas0Repn2BusFrChA.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_BmwMsgSlot51Bas0Repn2BusFrChA.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"
#include "float.h"

static void BmwMsgSlot51Bas0Repn2BusFrChA_TestDefines(void);


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
 * AVL_PO_EPS1: Integer in interval [0...65535]
 * AVL_PO_IDX_EPS1: Integer in interval [0...65535]
 * CRC_AVL_PO_EPS1: Integer in interval [0...255]
 * OFFS_GRD_MID_EPS1: Integer in interval [0...65535]
 * boolean: Boolean (standard type)
 * float32: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * sint8: Integer in interval [-128...127] (standard type)
 * uint16: Integer in interval [0...65535] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * ALIV_AVL_PO_EPS1: Enumeration of integer in interval [0...255] with enumerators
 *   ALIV_COU_4_Zaehlerstand0DotDotE (0U)
 *   ALIV_COU_4_SignalUngueltig (15U)
 * BmwPinionAgQlfr1: Enumeration of integer in interval [0...255] with enumerators
 *   BMWPINIONAGQLFR_SIGVALVLDANDPLAUS (1U)
 *   BMWPINIONAGQLFR_SIGVALVLD (2U)
 *   BMWPINIONAGQLFR_SUBVALSETINUSRSIG (4U)
 *   BMWPINIONAGQLFR_INIT (8U)
 *   BMWPINIONAGQLFR_SIGVALVLDANDTMPOFAVRGQLY (9U)
 *   BMWPINIONAGQLFR_SIGVALVLDANDTMPOFLOQLY (10U)
 *   BMWPINIONAGQLFR_ADJMTVALSETINUSRSIG (12U)
 *   BMWPINIONAGQLFR_SIGVALINVLDBUTSTTMP (14U)
 *   BMWPINIONAGQLFR_INVLDSIG (15U)
 * BmwSeldPosnUnit1: Enumeration of integer in interval [0...255] with enumerators
 *   BMWSELDPOSNUNIT_PINIONIF (0U)
 *   BMWSELDPOSNUNIT_TOOTHEDRACKSTROKEIF (1U)
 *   BMWSELDPOSNUNIT_INVLDSIG (3U)
 * BmwTqSnsrIdx1: Enumeration of integer in interval [0...255] with enumerators
 *   BMWTQSNSRIDX_INIT (0U)
 *   BMWTQSNSRIDX_NOIDXEDGE (1U)
 *   BMWTQSNSRIDX_IDXEDGE (2U)
 *   BMWTQSNSRIDX_INVLDSIG (3U)
 * IDX_TORQ_SEN1: Enumeration of integer in interval [0...255] with enumerators
 *   IDX_TORQ_SEN_Initialisierung (0U)
 *   IDX_TORQ_SEN_KeineIndexFlanke (1U)
 *   IDX_TORQ_SEN_IndexFlanke (2U)
 *   IDX_TORQ_SEN_SignalUngueltig (3U)
 * QU_AVL_PO_EPS1: Enumeration of integer in interval [0...255] with enumerators
 *   QU_AVL_PINA_EPS_Initialisierung (8U)
 *   QU_AVL_PINA_EPS_SignalwertIstGueltigUndAbgesichertUndPlausibilisiert (1U)
 *   QU_AVL_PINA_EPS_SignalwertIstGueltig (2U)
 *   QU_AVL_PINA_EPS_ErsatzwertIstImNutzsignalGesetzt (4U)
 *   QU_AVL_PINA_EPS_SignalwertIstGueltigZustandSlashStatusTemporaer_mittlereSignalqualitaet_ (9U)
 *   QU_AVL_PINA_EPS_SignalwertIstGueltigZustandSlashStatusTemporaer_geringeSignalqualitaet_ (10U)
 *   QU_AVL_PINA_EPS_AbgleichwertIstImNutzsignalGesetztZustandSlashStatusTemporaer (12U)
 *   QU_AVL_PINA_EPS_SignalwertIstUngueltigZustandSlashStatusTemporaer (14U)
 *   QU_AVL_PINA_EPS_SignalUngueltig (15U)
 * UN_PO_EPS1: Enumeration of integer in interval [0...255] with enumerators
 *   UN_PO_EPS_Ritzelschnittstelle (0U)
 *   UN_PO_EPS_Zahnstangenhubschnittstelle (1U)
 *   UN_PO_EPS_SignalUngueltig (3U)
 *
 * Record Types:
 * =============
 * sigGroup_AVL_PO_EPS1: Record with elements
 *   AVL_PO_EPS of type AVL_PO_EPS1
 *   IDX_TORQ_SEN of type IDX_TORQ_SEN1
 *   OFFS_GRD_MID_EPS of type OFFS_GRD_MID_EPS1
 *   AVL_PO_IDX_EPS of type AVL_PO_IDX_EPS1
 *   CRC_AVL_PO_EPS of type CRC_AVL_PO_EPS1
 *   QU_AVL_PO_EPS of type QU_AVL_PO_EPS1
 *   ALIV_AVL_PO_EPS of type ALIV_AVL_PO_EPS1
 *   UN_PO_EPS of type UN_PO_EPS1
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   sint8 Rte_Prm_BmwSteerPolarity_Val(void)
 *
 *********************************************************************************************************************/


#define BmwMsgSlot51Bas0Repn2BusFrChA_START_SEC_CODE
#include "BmwMsgSlot51Bas0Repn2BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwMsgSlot51Bas0Repn2BusFrChAInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwMsgSlot51Bas0Repn2BusFrChAInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwMsgSlot51Bas0Repn2BusFrChA_CODE) BmwMsgSlot51Bas0Repn2BusFrChAInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwMsgSlot51Bas0Repn2BusFrChAInit1
 *********************************************************************************************************************/

  sint8 BmwSteerPolarity_Val_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  BmwSteerPolarity_Val_data = TSC_BmwMsgSlot51Bas0Repn2BusFrChA_Rte_Prm_BmwSteerPolarity_Val();

  BmwMsgSlot51Bas0Repn2BusFrChA_TestDefines();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwMsgSlot51Bas0Repn2BusFrChAPer1
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
 *   Std_ReturnType Rte_Read_BmwPinionAg_Val(float32 *data)
 *   Std_ReturnType Rte_Read_BmwPinionAgIdx_Val(float32 *data)
 *   Std_ReturnType Rte_Read_BmwPinionAgIdxVld_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_BmwPinionAgQlfr_Val(BmwPinionAgQlfr1 *data)
 *   Std_ReturnType Rte_Read_BmwRackCntrToVehCntrOffs_Val(float32 *data)
 *   Std_ReturnType Rte_Read_BmwRackCntrToVehCntrOffsVld_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_BmwSeldPosnUnit_Val(BmwSeldPosnUnit1 *data)
 *   Std_ReturnType Rte_Read_BmwTarMotTq_Val(float32 *data)
 *   Std_ReturnType Rte_Read_BmwTarMotTqVld_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_BmwTqSnsrIdx_Val(BmwTqSnsrIdx1 *data)
 *
 *   E2E Protection Wrapper API:
 *   ---------------------------
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_TRGG_ENGTORQ_EPS_Val(uint16 data)
 *   Std_ReturnType Rte_Write_sigGroup_AVL_PO_EPS_sigGroup_AVL_PO_EPS(const sigGroup_AVL_PO_EPS1 *data)
 *   Std_ReturnType Rte_Invalidate_sigGroup_AVL_PO_EPS_sigGroup_AVL_PO_EPS(void)
 *
 *   E2E Protection Wrapper API:
 *   ---------------------------
 *   uint32 E2EPW_Write_sigGroup_AVL_PO_EPS_sigGroup_AVL_PO_EPS(sigGroup_AVL_PO_EPS1 *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwMsgSlot51Bas0Repn2BusFrChAPer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwMsgSlot51Bas0Repn2BusFrChA_CODE) BmwMsgSlot51Bas0Repn2BusFrChAPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwMsgSlot51Bas0Repn2BusFrChAPer1
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  float32 Read_BmwPinionAg_Val;
  float32 Read_BmwPinionAgIdx_Val;
  boolean Read_BmwPinionAgIdxVld_Logl;
  BmwPinionAgQlfr1 Read_BmwPinionAgQlfr_Val;
  float32 Read_BmwRackCntrToVehCntrOffs_Val;
  boolean Read_BmwRackCntrToVehCntrOffsVld_Logl;
  BmwSeldPosnUnit1 Read_BmwSeldPosnUnit_Val;
  float32 Read_BmwTarMotTq_Val;
  boolean Read_BmwTarMotTqVld_Logl;
  BmwTqSnsrIdx1 Read_BmwTqSnsrIdx_Val;

  sint8 BmwSteerPolarity_Val_data;

  sigGroup_AVL_PO_EPS1 Write_sigGroup_AVL_PO_EPS_sigGroup_AVL_PO_EPS;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  BmwSteerPolarity_Val_data = TSC_BmwMsgSlot51Bas0Repn2BusFrChA_Rte_Prm_BmwSteerPolarity_Val();

  fct_status = TSC_BmwMsgSlot51Bas0Repn2BusFrChA_Rte_Read_BmwPinionAg_Val(&Read_BmwPinionAg_Val);
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

  fct_status = TSC_BmwMsgSlot51Bas0Repn2BusFrChA_Rte_Read_BmwPinionAgIdx_Val(&Read_BmwPinionAgIdx_Val);
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

  fct_status = TSC_BmwMsgSlot51Bas0Repn2BusFrChA_Rte_Read_BmwPinionAgIdxVld_Logl(&Read_BmwPinionAgIdxVld_Logl);
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

  fct_status = TSC_BmwMsgSlot51Bas0Repn2BusFrChA_Rte_Read_BmwPinionAgQlfr_Val(&Read_BmwPinionAgQlfr_Val);
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

  fct_status = TSC_BmwMsgSlot51Bas0Repn2BusFrChA_Rte_Read_BmwRackCntrToVehCntrOffs_Val(&Read_BmwRackCntrToVehCntrOffs_Val);
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

  fct_status = TSC_BmwMsgSlot51Bas0Repn2BusFrChA_Rte_Read_BmwRackCntrToVehCntrOffsVld_Logl(&Read_BmwRackCntrToVehCntrOffsVld_Logl);
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

  fct_status = TSC_BmwMsgSlot51Bas0Repn2BusFrChA_Rte_Read_BmwSeldPosnUnit_Val(&Read_BmwSeldPosnUnit_Val);
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

  fct_status = TSC_BmwMsgSlot51Bas0Repn2BusFrChA_Rte_Read_BmwTarMotTq_Val(&Read_BmwTarMotTq_Val);
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

  fct_status = TSC_BmwMsgSlot51Bas0Repn2BusFrChA_Rte_Read_BmwTarMotTqVld_Logl(&Read_BmwTarMotTqVld_Logl);
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

  fct_status = TSC_BmwMsgSlot51Bas0Repn2BusFrChA_Rte_Read_BmwTqSnsrIdx_Val(&Read_BmwTqSnsrIdx_Val);
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

  fct_status = TSC_BmwMsgSlot51Bas0Repn2BusFrChA_Rte_Write_TRGG_ENGTORQ_EPS_Val(Rte_InitValue_TRGG_ENGTORQ_EPS_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_sigGroup_AVL_PO_EPS_sigGroup_AVL_PO_EPS, 0, sizeof(Write_sigGroup_AVL_PO_EPS_sigGroup_AVL_PO_EPS));
  fct_status = TSC_BmwMsgSlot51Bas0Repn2BusFrChA_Rte_Write_sigGroup_AVL_PO_EPS_sigGroup_AVL_PO_EPS(&Write_sigGroup_AVL_PO_EPS_sigGroup_AVL_PO_EPS);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwMsgSlot51Bas0Repn2BusFrChA_Rte_Invalidate_sigGroup_AVL_PO_EPS_sigGroup_AVL_PO_EPS();
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


#define BmwMsgSlot51Bas0Repn2BusFrChA_STOP_SEC_CODE
#include "BmwMsgSlot51Bas0Repn2BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void BmwMsgSlot51Bas0Repn2BusFrChA_TestDefines(void)
{
  /* Enumeration Data Types */

  ALIV_AVL_PO_EPS1 Test_ALIV_AVL_PO_EPS1_V_1 = ALIV_COU_4_Zaehlerstand0DotDotE;
  ALIV_AVL_PO_EPS1 Test_ALIV_AVL_PO_EPS1_V_2 = ALIV_COU_4_SignalUngueltig;

  BmwPinionAgQlfr1 Test_BmwPinionAgQlfr1_V_1 = BMWPINIONAGQLFR_SIGVALVLDANDPLAUS;
  BmwPinionAgQlfr1 Test_BmwPinionAgQlfr1_V_2 = BMWPINIONAGQLFR_SIGVALVLD;
  BmwPinionAgQlfr1 Test_BmwPinionAgQlfr1_V_3 = BMWPINIONAGQLFR_SUBVALSETINUSRSIG;
  BmwPinionAgQlfr1 Test_BmwPinionAgQlfr1_V_4 = BMWPINIONAGQLFR_INIT;
  BmwPinionAgQlfr1 Test_BmwPinionAgQlfr1_V_5 = BMWPINIONAGQLFR_SIGVALVLDANDTMPOFAVRGQLY;
  BmwPinionAgQlfr1 Test_BmwPinionAgQlfr1_V_6 = BMWPINIONAGQLFR_SIGVALVLDANDTMPOFLOQLY;
  BmwPinionAgQlfr1 Test_BmwPinionAgQlfr1_V_7 = BMWPINIONAGQLFR_ADJMTVALSETINUSRSIG;
  BmwPinionAgQlfr1 Test_BmwPinionAgQlfr1_V_8 = BMWPINIONAGQLFR_SIGVALINVLDBUTSTTMP;
  BmwPinionAgQlfr1 Test_BmwPinionAgQlfr1_V_9 = BMWPINIONAGQLFR_INVLDSIG;

  BmwSeldPosnUnit1 Test_BmwSeldPosnUnit1_V_1 = BMWSELDPOSNUNIT_PINIONIF;
  BmwSeldPosnUnit1 Test_BmwSeldPosnUnit1_V_2 = BMWSELDPOSNUNIT_TOOTHEDRACKSTROKEIF;
  BmwSeldPosnUnit1 Test_BmwSeldPosnUnit1_V_3 = BMWSELDPOSNUNIT_INVLDSIG;

  BmwTqSnsrIdx1 Test_BmwTqSnsrIdx1_V_1 = BMWTQSNSRIDX_INIT;
  BmwTqSnsrIdx1 Test_BmwTqSnsrIdx1_V_2 = BMWTQSNSRIDX_NOIDXEDGE;
  BmwTqSnsrIdx1 Test_BmwTqSnsrIdx1_V_3 = BMWTQSNSRIDX_IDXEDGE;
  BmwTqSnsrIdx1 Test_BmwTqSnsrIdx1_V_4 = BMWTQSNSRIDX_INVLDSIG;

  IDX_TORQ_SEN1 Test_IDX_TORQ_SEN1_V_1 = IDX_TORQ_SEN_Initialisierung;
  IDX_TORQ_SEN1 Test_IDX_TORQ_SEN1_V_2 = IDX_TORQ_SEN_KeineIndexFlanke;
  IDX_TORQ_SEN1 Test_IDX_TORQ_SEN1_V_3 = IDX_TORQ_SEN_IndexFlanke;
  IDX_TORQ_SEN1 Test_IDX_TORQ_SEN1_V_4 = IDX_TORQ_SEN_SignalUngueltig;

  QU_AVL_PO_EPS1 Test_QU_AVL_PO_EPS1_V_1 = QU_AVL_PINA_EPS_Initialisierung;
  QU_AVL_PO_EPS1 Test_QU_AVL_PO_EPS1_V_2 = QU_AVL_PINA_EPS_SignalwertIstGueltigUndAbgesichertUndPlausibilisiert;
  QU_AVL_PO_EPS1 Test_QU_AVL_PO_EPS1_V_3 = QU_AVL_PINA_EPS_SignalwertIstGueltig;
  QU_AVL_PO_EPS1 Test_QU_AVL_PO_EPS1_V_4 = QU_AVL_PINA_EPS_ErsatzwertIstImNutzsignalGesetzt;
  QU_AVL_PO_EPS1 Test_QU_AVL_PO_EPS1_V_5 = QU_AVL_PINA_EPS_SignalwertIstGueltigZustandSlashStatusTemporaer_mittlereSignalqualitaet_;
  QU_AVL_PO_EPS1 Test_QU_AVL_PO_EPS1_V_6 = QU_AVL_PINA_EPS_SignalwertIstGueltigZustandSlashStatusTemporaer_geringeSignalqualitaet_;
  QU_AVL_PO_EPS1 Test_QU_AVL_PO_EPS1_V_7 = QU_AVL_PINA_EPS_AbgleichwertIstImNutzsignalGesetztZustandSlashStatusTemporaer;
  QU_AVL_PO_EPS1 Test_QU_AVL_PO_EPS1_V_8 = QU_AVL_PINA_EPS_SignalwertIstUngueltigZustandSlashStatusTemporaer;
  QU_AVL_PO_EPS1 Test_QU_AVL_PO_EPS1_V_9 = QU_AVL_PINA_EPS_SignalUngueltig;

  UN_PO_EPS1 Test_UN_PO_EPS1_V_1 = UN_PO_EPS_Ritzelschnittstelle;
  UN_PO_EPS1 Test_UN_PO_EPS1_V_2 = UN_PO_EPS_Zahnstangenhubschnittstelle;
  UN_PO_EPS1 Test_UN_PO_EPS1_V_3 = UN_PO_EPS_SignalUngueltig;
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
