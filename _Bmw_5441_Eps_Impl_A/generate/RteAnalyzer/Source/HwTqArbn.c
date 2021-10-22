/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  HwTqArbn.c
 *        Config:  EPS.dpa
 *     SW-C Type:  HwTqArbn
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <HwTqArbn>
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

#include "Rte_HwTqArbn.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_HwTqArbn.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"
#include "float.h"

static void HwTqArbn_TestDefines(void);


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
 * boolean: Boolean (standard type)
 * float32: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * float32: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * SigQlfr1: Enumeration of integer in interval [0...255] with enumerators
 *   SIGQLFR_NORES (0U)
 *   SIGQLFR_PASSD (1U)
 *   SIGQLFR_FAILD (2U)
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   float32 *Rte_Pim_HwTqPrevHwTq(void)
 *   uint8 *Rte_Pim_HwTqARollgCntrPrev(void)
 *   uint8 *Rte_Pim_HwTqAStallCntrPrev(void)
 *   uint8 *Rte_Pim_HwTqBRollgCntrPrev(void)
 *   uint8 *Rte_Pim_HwTqBStallCntrPrev(void)
 *   boolean *Rte_Pim_dHwTqArbnChAAvl(void)
 *
 *********************************************************************************************************************/


#define HwTqArbn_START_SEC_CODE
#include "HwTqArbn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTqArbnInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: HwTqArbnInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, HwTqArbn_CODE) HwTqArbnInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: HwTqArbnInit1
 *********************************************************************************************************************/

  float32 PimHwTqPrevHwTq;
  uint8 PimHwTqARollgCntrPrev;
  uint8 PimHwTqAStallCntrPrev;
  uint8 PimHwTqBRollgCntrPrev;
  uint8 PimHwTqBStallCntrPrev;
  boolean PimdHwTqArbnChAAvl;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimHwTqPrevHwTq = *TSC_HwTqArbn_Rte_Pim_HwTqPrevHwTq();
  *TSC_HwTqArbn_Rte_Pim_HwTqPrevHwTq() = PimHwTqPrevHwTq;
  PimHwTqARollgCntrPrev = *TSC_HwTqArbn_Rte_Pim_HwTqARollgCntrPrev();
  *TSC_HwTqArbn_Rte_Pim_HwTqARollgCntrPrev() = PimHwTqARollgCntrPrev;
  PimHwTqAStallCntrPrev = *TSC_HwTqArbn_Rte_Pim_HwTqAStallCntrPrev();
  *TSC_HwTqArbn_Rte_Pim_HwTqAStallCntrPrev() = PimHwTqAStallCntrPrev;
  PimHwTqBRollgCntrPrev = *TSC_HwTqArbn_Rte_Pim_HwTqBRollgCntrPrev();
  *TSC_HwTqArbn_Rte_Pim_HwTqBRollgCntrPrev() = PimHwTqBRollgCntrPrev;
  PimHwTqBStallCntrPrev = *TSC_HwTqArbn_Rte_Pim_HwTqBStallCntrPrev();
  *TSC_HwTqArbn_Rte_Pim_HwTqBStallCntrPrev() = PimHwTqBStallCntrPrev;
  PimdHwTqArbnChAAvl = *TSC_HwTqArbn_Rte_Pim_dHwTqArbnChAAvl();
  *TSC_HwTqArbn_Rte_Pim_dHwTqArbnChAAvl() = PimdHwTqArbnChAAvl;

  HwTqArbn_TestDefines();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTqArbnPer1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_HwTqA_Val(float32 *data)
 *   Std_ReturnType Rte_Read_HwTqAQlfr_Val(SigQlfr1 *data)
 *   Std_ReturnType Rte_Read_HwTqARollgCntr_Val(uint8 *data)
 *   Std_ReturnType Rte_Read_HwTqB_Val(float32 *data)
 *   Std_ReturnType Rte_Read_HwTqBQlfr_Val(SigQlfr1 *data)
 *   Std_ReturnType Rte_Read_HwTqBRollgCntr_Val(uint8 *data)
 *   Std_ReturnType Rte_Read_HwTqCorrlnSts_Val(uint8 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_HwTq_Val(float32 data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: HwTqArbnPer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, HwTqArbn_CODE) HwTqArbnPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: HwTqArbnPer1
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  float32 Read_HwTqA_Val;
  SigQlfr1 Read_HwTqAQlfr_Val;
  uint8 Read_HwTqARollgCntr_Val;
  float32 Read_HwTqB_Val;
  SigQlfr1 Read_HwTqBQlfr_Val;
  uint8 Read_HwTqBRollgCntr_Val;
  uint8 Read_HwTqCorrlnSts_Val;

  float32 PimHwTqPrevHwTq;
  uint8 PimHwTqARollgCntrPrev;
  uint8 PimHwTqAStallCntrPrev;
  uint8 PimHwTqBRollgCntrPrev;
  uint8 PimHwTqBStallCntrPrev;
  boolean PimdHwTqArbnChAAvl;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimHwTqPrevHwTq = *TSC_HwTqArbn_Rte_Pim_HwTqPrevHwTq();
  *TSC_HwTqArbn_Rte_Pim_HwTqPrevHwTq() = PimHwTqPrevHwTq;
  PimHwTqARollgCntrPrev = *TSC_HwTqArbn_Rte_Pim_HwTqARollgCntrPrev();
  *TSC_HwTqArbn_Rte_Pim_HwTqARollgCntrPrev() = PimHwTqARollgCntrPrev;
  PimHwTqAStallCntrPrev = *TSC_HwTqArbn_Rte_Pim_HwTqAStallCntrPrev();
  *TSC_HwTqArbn_Rte_Pim_HwTqAStallCntrPrev() = PimHwTqAStallCntrPrev;
  PimHwTqBRollgCntrPrev = *TSC_HwTqArbn_Rte_Pim_HwTqBRollgCntrPrev();
  *TSC_HwTqArbn_Rte_Pim_HwTqBRollgCntrPrev() = PimHwTqBRollgCntrPrev;
  PimHwTqBStallCntrPrev = *TSC_HwTqArbn_Rte_Pim_HwTqBStallCntrPrev();
  *TSC_HwTqArbn_Rte_Pim_HwTqBStallCntrPrev() = PimHwTqBStallCntrPrev;
  PimdHwTqArbnChAAvl = *TSC_HwTqArbn_Rte_Pim_dHwTqArbnChAAvl();
  *TSC_HwTqArbn_Rte_Pim_dHwTqArbnChAAvl() = PimdHwTqArbnChAAvl;

  fct_status = TSC_HwTqArbn_Rte_Read_HwTqA_Val(&Read_HwTqA_Val);
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

  fct_status = TSC_HwTqArbn_Rte_Read_HwTqAQlfr_Val(&Read_HwTqAQlfr_Val);
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

  fct_status = TSC_HwTqArbn_Rte_Read_HwTqARollgCntr_Val(&Read_HwTqARollgCntr_Val);
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

  fct_status = TSC_HwTqArbn_Rte_Read_HwTqB_Val(&Read_HwTqB_Val);
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

  fct_status = TSC_HwTqArbn_Rte_Read_HwTqBQlfr_Val(&Read_HwTqBQlfr_Val);
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

  fct_status = TSC_HwTqArbn_Rte_Read_HwTqBRollgCntr_Val(&Read_HwTqBRollgCntr_Val);
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

  fct_status = TSC_HwTqArbn_Rte_Read_HwTqCorrlnSts_Val(&Read_HwTqCorrlnSts_Val);
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

  fct_status = TSC_HwTqArbn_Rte_Write_HwTq_Val(Rte_InitValue_HwTq_Val);
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


#define HwTqArbn_STOP_SEC_CODE
#include "HwTqArbn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void HwTqArbn_TestDefines(void)
{
  /* Enumeration Data Types */

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
