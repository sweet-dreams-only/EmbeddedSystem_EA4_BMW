/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  CDD_Bmw5441McuCfg.c
 *        Config:  EPS.dpa
 *     SW-C Type:  CDD_Bmw5441McuCfg
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <CDD_Bmw5441McuCfg>
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

#include "Rte_CDD_Bmw5441McuCfg.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_CDD_Bmw5441McuCfg.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"


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
 * uint32: Integer in interval [0...4294967295] (standard type)
 *
 *********************************************************************************************************************/


#define CDD_Bmw5441McuCfg_START_SEC_CODE
#include "CDD_Bmw5441McuCfg_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Bmw5441McuCfgInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Bmw5441McuCfgInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CDD_Bmw5441McuCfg_CODE) Bmw5441McuCfgInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Bmw5441McuCfgInit1
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Bmw5441McuCfgInit2
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_GetRefTmr1MicroSec32bit_Oper(uint32 *RefTmr_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_GetTiSpan1MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Bmw5441McuCfgInit2_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CDD_Bmw5441McuCfg_CODE) Bmw5441McuCfgInit2(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Bmw5441McuCfgInit2
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  uint32 Call_GetRefTmr1MicroSec32bit_Oper_RefTmr_Arg = 0U;
  uint32 Call_GetTiSpan1MicroSec32bit_Oper_TiSpan_Arg = 0U;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_CDD_Bmw5441McuCfg_Rte_Call_GetRefTmr1MicroSec32bit_Oper(&Call_GetRefTmr1MicroSec32bit_Oper_RefTmr_Arg);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CDD_Bmw5441McuCfg_Rte_Call_GetTiSpan1MicroSec32bit_Oper(0U, &Call_GetTiSpan1MicroSec32bit_Oper_TiSpan_Arg);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Bmw5441McuCfgInit3
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_Adc1ScanGroup2Ref0_Val(float32 data)
 *   Std_ReturnType Rte_Write_Adc1ScanGroup2Ref1_Val(float32 data)
 *   Std_ReturnType Rte_Write_Adc1ScanGroup3Ref0_Val(float32 data)
 *   Std_ReturnType Rte_Write_Adc1ScanGroup3Ref1_Val(float32 data)
 *   Std_ReturnType Rte_Write_Adc1SelfDiag0_Val(float32 data)
 *   Std_ReturnType Rte_Write_Adc1SelfDiag2_Val(float32 data)
 *   Std_ReturnType Rte_Write_Adc1SelfDiag4_Val(float32 data)
 *   Std_ReturnType Rte_Write_BattVltg_Val(float32 data)
 *   Std_ReturnType Rte_Write_BattVltgSwd1_Val(float32 data)
 *   Std_ReturnType Rte_Write_EcuT_Val(float32 data)
 *   Std_ReturnType Rte_Write_RvsBattDiagcGndAdc_Val(float32 data)
 *   Std_ReturnType Rte_Write_RvsBattDiagcRtnAdc_Val(float32 data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Bmw5441McuCfgInit3_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CDD_Bmw5441McuCfg_CODE) Bmw5441McuCfgInit3(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Bmw5441McuCfgInit3
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_CDD_Bmw5441McuCfg_Rte_Write_Adc1ScanGroup2Ref0_Val(Rte_InitValue_Adc1ScanGroup2Ref0_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CDD_Bmw5441McuCfg_Rte_Write_Adc1ScanGroup2Ref1_Val(Rte_InitValue_Adc1ScanGroup2Ref1_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CDD_Bmw5441McuCfg_Rte_Write_Adc1ScanGroup3Ref0_Val(Rte_InitValue_Adc1ScanGroup3Ref0_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CDD_Bmw5441McuCfg_Rte_Write_Adc1ScanGroup3Ref1_Val(Rte_InitValue_Adc1ScanGroup3Ref1_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CDD_Bmw5441McuCfg_Rte_Write_Adc1SelfDiag0_Val(Rte_InitValue_Adc1SelfDiag0_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CDD_Bmw5441McuCfg_Rte_Write_Adc1SelfDiag2_Val(Rte_InitValue_Adc1SelfDiag2_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CDD_Bmw5441McuCfg_Rte_Write_Adc1SelfDiag4_Val(Rte_InitValue_Adc1SelfDiag4_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CDD_Bmw5441McuCfg_Rte_Write_BattVltg_Val(Rte_InitValue_BattVltg_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CDD_Bmw5441McuCfg_Rte_Write_BattVltgSwd1_Val(Rte_InitValue_BattVltgSwd1_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CDD_Bmw5441McuCfg_Rte_Write_EcuT_Val(Rte_InitValue_EcuT_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CDD_Bmw5441McuCfg_Rte_Write_RvsBattDiagcGndAdc_Val(Rte_InitValue_RvsBattDiagcGndAdc_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CDD_Bmw5441McuCfg_Rte_Write_RvsBattDiagcRtnAdc_Val(Rte_InitValue_RvsBattDiagcRtnAdc_Val);
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

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Bmw5441McuCfgPer2
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
 *   Std_ReturnType Rte_Write_Adc1ScanGroup2Ref0_Val(float32 data)
 *   Std_ReturnType Rte_Write_Adc1ScanGroup2Ref1_Val(float32 data)
 *   Std_ReturnType Rte_Write_Adc1ScanGroup3Ref0_Val(float32 data)
 *   Std_ReturnType Rte_Write_Adc1ScanGroup3Ref1_Val(float32 data)
 *   Std_ReturnType Rte_Write_Adc1SelfDiag0_Val(float32 data)
 *   Std_ReturnType Rte_Write_Adc1SelfDiag2_Val(float32 data)
 *   Std_ReturnType Rte_Write_Adc1SelfDiag4_Val(float32 data)
 *   Std_ReturnType Rte_Write_BattVltg_Val(float32 data)
 *   Std_ReturnType Rte_Write_BattVltgSwd1_Val(float32 data)
 *   Std_ReturnType Rte_Write_EcuT_Val(float32 data)
 *   Std_ReturnType Rte_Write_RvsBattDiagcGndAdc_Val(float32 data)
 *   Std_ReturnType Rte_Write_RvsBattDiagcRtnAdc_Val(float32 data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Bmw5441McuCfgPer2_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CDD_Bmw5441McuCfg_CODE) Bmw5441McuCfgPer2(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Bmw5441McuCfgPer2
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_CDD_Bmw5441McuCfg_Rte_Write_Adc1ScanGroup2Ref0_Val(Rte_InitValue_Adc1ScanGroup2Ref0_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CDD_Bmw5441McuCfg_Rte_Write_Adc1ScanGroup2Ref1_Val(Rte_InitValue_Adc1ScanGroup2Ref1_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CDD_Bmw5441McuCfg_Rte_Write_Adc1ScanGroup3Ref0_Val(Rte_InitValue_Adc1ScanGroup3Ref0_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CDD_Bmw5441McuCfg_Rte_Write_Adc1ScanGroup3Ref1_Val(Rte_InitValue_Adc1ScanGroup3Ref1_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CDD_Bmw5441McuCfg_Rte_Write_Adc1SelfDiag0_Val(Rte_InitValue_Adc1SelfDiag0_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CDD_Bmw5441McuCfg_Rte_Write_Adc1SelfDiag2_Val(Rte_InitValue_Adc1SelfDiag2_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CDD_Bmw5441McuCfg_Rte_Write_Adc1SelfDiag4_Val(Rte_InitValue_Adc1SelfDiag4_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CDD_Bmw5441McuCfg_Rte_Write_BattVltg_Val(Rte_InitValue_BattVltg_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CDD_Bmw5441McuCfg_Rte_Write_BattVltgSwd1_Val(Rte_InitValue_BattVltgSwd1_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CDD_Bmw5441McuCfg_Rte_Write_EcuT_Val(Rte_InitValue_EcuT_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CDD_Bmw5441McuCfg_Rte_Write_RvsBattDiagcGndAdc_Val(Rte_InitValue_RvsBattDiagcGndAdc_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CDD_Bmw5441McuCfg_Rte_Write_RvsBattDiagcRtnAdc_Val(Rte_InitValue_RvsBattDiagcRtnAdc_Val);
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

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Bmw5441McuCfgPer3
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
 *   Std_ReturnType Rte_Read_Adc0Faild_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_Adc1Faild_Logl(boolean *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_BattRtnCurrAdcFaild_Logl(boolean data)
 *   Std_ReturnType Rte_Write_BattVltgAdcFaild_Logl(boolean data)
 *   Std_ReturnType Rte_Write_BattVltgSwd1AdcFaild_Logl(boolean data)
 *   Std_ReturnType Rte_Write_EcuTAdcFaild_Logl(boolean data)
 *   Std_ReturnType Rte_Write_HwTq4RawAdcAdcFaild_Logl(boolean data)
 *   Std_ReturnType Rte_Write_HwTq5RawAdcAdcFaild_Logl(boolean data)
 *   Std_ReturnType Rte_Write_MotCurrAdcVlyAAdcFaild_Logl(boolean data)
 *   Std_ReturnType Rte_Write_MotCurrAdcVlyBAdcFaild_Logl(boolean data)
 *   Std_ReturnType Rte_Write_MotCurrAdcVlyCAdcFaild_Logl(boolean data)
 *   Std_ReturnType Rte_Write_MotDrvr1IninTestCmpl_Logl(boolean data)
 *   Std_ReturnType Rte_Write_RvsBattDiagcGndAdcFaild_Logl(boolean data)
 *   Std_ReturnType Rte_Write_RvsBattDiagcRtnAdcFaild_Logl(boolean data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Bmw5441McuCfgPer3_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CDD_Bmw5441McuCfg_CODE) Bmw5441McuCfgPer3(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Bmw5441McuCfgPer3
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  boolean Read_Adc0Faild_Logl;
  boolean Read_Adc1Faild_Logl;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_CDD_Bmw5441McuCfg_Rte_Read_Adc0Faild_Logl(&Read_Adc0Faild_Logl);
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

  fct_status = TSC_CDD_Bmw5441McuCfg_Rte_Read_Adc1Faild_Logl(&Read_Adc1Faild_Logl);
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

  fct_status = TSC_CDD_Bmw5441McuCfg_Rte_Write_BattRtnCurrAdcFaild_Logl(Rte_InitValue_BattRtnCurrAdcFaild_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CDD_Bmw5441McuCfg_Rte_Write_BattVltgAdcFaild_Logl(Rte_InitValue_BattVltgAdcFaild_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CDD_Bmw5441McuCfg_Rte_Write_BattVltgSwd1AdcFaild_Logl(Rte_InitValue_BattVltgSwd1AdcFaild_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CDD_Bmw5441McuCfg_Rte_Write_EcuTAdcFaild_Logl(Rte_InitValue_EcuTAdcFaild_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CDD_Bmw5441McuCfg_Rte_Write_HwTq4RawAdcAdcFaild_Logl(Rte_InitValue_HwTq4RawAdcAdcFaild_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CDD_Bmw5441McuCfg_Rte_Write_HwTq5RawAdcAdcFaild_Logl(Rte_InitValue_HwTq5RawAdcAdcFaild_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CDD_Bmw5441McuCfg_Rte_Write_MotCurrAdcVlyAAdcFaild_Logl(Rte_InitValue_MotCurrAdcVlyAAdcFaild_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CDD_Bmw5441McuCfg_Rte_Write_MotCurrAdcVlyBAdcFaild_Logl(Rte_InitValue_MotCurrAdcVlyBAdcFaild_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CDD_Bmw5441McuCfg_Rte_Write_MotCurrAdcVlyCAdcFaild_Logl(Rte_InitValue_MotCurrAdcVlyCAdcFaild_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CDD_Bmw5441McuCfg_Rte_Write_MotDrvr1IninTestCmpl_Logl(Rte_InitValue_MotDrvr1IninTestCmpl_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CDD_Bmw5441McuCfg_Rte_Write_RvsBattDiagcGndAdcFaild_Logl(Rte_InitValue_RvsBattDiagcGndAdcFaild_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CDD_Bmw5441McuCfg_Rte_Write_RvsBattDiagcRtnAdcFaild_Logl(Rte_InitValue_RvsBattDiagcRtnAdcFaild_Logl);
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


#define CDD_Bmw5441McuCfg_STOP_SEC_CODE
#include "CDD_Bmw5441McuCfg_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


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

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_TestCode:
     Reason:     This justification is used within the generated test code by the Rte Analyzer.
     Risk:       No functional risk.
     Prevention: Not required.

*/
