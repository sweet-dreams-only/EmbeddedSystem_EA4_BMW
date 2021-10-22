/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  PolarityCfg.c
 *        Config:  EPS.dpa
 *     SW-C Type:  PolarityCfg
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <PolarityCfg>
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

#include "Rte_PolarityCfg.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_PolarityCfg.h"


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
 * sint8: Integer in interval [-128...127] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   uint32 *Rte_Pim_PolarityCfgSaved(void)
 *
 * Calibration Parameters:
 * =======================
 *   SW-C local Calibration Parameters:
 *   ----------------------------------
 *   uint32 Rte_CData_PolarityCfgSavedDft(void)
 *
 *********************************************************************************************************************/


#define PolarityCfg_START_SEC_CODE
#include "PolarityCfg_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PolarityCfgInit1
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
 *   Std_ReturnType Rte_Write_AssiMechPolarity_Val(sint8 data)
 *   Std_ReturnType Rte_Write_HwAg0Polarity_Val(sint8 data)
 *   Std_ReturnType Rte_Write_HwAg1Polarity_Val(sint8 data)
 *   Std_ReturnType Rte_Write_HwAg2Polarity_Val(sint8 data)
 *   Std_ReturnType Rte_Write_HwAg3Polarity_Val(sint8 data)
 *   Std_ReturnType Rte_Write_HwAg4Polarity_Val(sint8 data)
 *   Std_ReturnType Rte_Write_HwAg5Polarity_Val(sint8 data)
 *   Std_ReturnType Rte_Write_HwAg6Polarity_Val(sint8 data)
 *   Std_ReturnType Rte_Write_HwAg7Polarity_Val(sint8 data)
 *   Std_ReturnType Rte_Write_HwTq0Polarity_Val(sint8 data)
 *   Std_ReturnType Rte_Write_HwTq1Polarity_Val(sint8 data)
 *   Std_ReturnType Rte_Write_HwTq2Polarity_Val(sint8 data)
 *   Std_ReturnType Rte_Write_HwTq3Polarity_Val(sint8 data)
 *   Std_ReturnType Rte_Write_HwTq4Polarity_Val(sint8 data)
 *   Std_ReturnType Rte_Write_HwTq5Polarity_Val(sint8 data)
 *   Std_ReturnType Rte_Write_HwTq6Polarity_Val(sint8 data)
 *   Std_ReturnType Rte_Write_HwTq7Polarity_Val(sint8 data)
 *   Std_ReturnType Rte_Write_MotAgMecl0Polarity_Val(sint8 data)
 *   Std_ReturnType Rte_Write_MotAgMecl1Polarity_Val(sint8 data)
 *   Std_ReturnType Rte_Write_MotAgMecl2Polarity_Val(sint8 data)
 *   Std_ReturnType Rte_Write_MotAgMecl3Polarity_Val(sint8 data)
 *   Std_ReturnType Rte_Write_MotAgMecl4Polarity_Val(sint8 data)
 *   Std_ReturnType Rte_Write_MotAgMecl5Polarity_Val(sint8 data)
 *   Std_ReturnType Rte_Write_MotAgMecl6Polarity_Val(sint8 data)
 *   Std_ReturnType Rte_Write_MotAgMecl7Polarity_Val(sint8 data)
 *   Std_ReturnType Rte_Write_MotElecMeclPolarity_Val(sint8 data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: PolarityCfgInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, PolarityCfg_CODE) PolarityCfgInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: PolarityCfgInit1
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  uint32 PimPolarityCfgSaved;

  uint32 PolarityCfgSavedDft_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimPolarityCfgSaved = *TSC_PolarityCfg_Rte_Pim_PolarityCfgSaved();
  *TSC_PolarityCfg_Rte_Pim_PolarityCfgSaved() = PimPolarityCfgSaved;

  PolarityCfgSavedDft_data = TSC_PolarityCfg_Rte_CData_PolarityCfgSavedDft();

  fct_status = TSC_PolarityCfg_Rte_Write_AssiMechPolarity_Val(Rte_InitValue_AssiMechPolarity_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_PolarityCfg_Rte_Write_HwAg0Polarity_Val(Rte_InitValue_HwAg0Polarity_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_PolarityCfg_Rte_Write_HwAg1Polarity_Val(Rte_InitValue_HwAg1Polarity_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_PolarityCfg_Rte_Write_HwAg2Polarity_Val(Rte_InitValue_HwAg2Polarity_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_PolarityCfg_Rte_Write_HwAg3Polarity_Val(Rte_InitValue_HwAg3Polarity_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_PolarityCfg_Rte_Write_HwAg4Polarity_Val(Rte_InitValue_HwAg4Polarity_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_PolarityCfg_Rte_Write_HwAg5Polarity_Val(Rte_InitValue_HwAg5Polarity_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_PolarityCfg_Rte_Write_HwAg6Polarity_Val(Rte_InitValue_HwAg6Polarity_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_PolarityCfg_Rte_Write_HwAg7Polarity_Val(Rte_InitValue_HwAg7Polarity_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_PolarityCfg_Rte_Write_HwTq0Polarity_Val(Rte_InitValue_HwTq0Polarity_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_PolarityCfg_Rte_Write_HwTq1Polarity_Val(Rte_InitValue_HwTq1Polarity_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_PolarityCfg_Rte_Write_HwTq2Polarity_Val(Rte_InitValue_HwTq2Polarity_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_PolarityCfg_Rte_Write_HwTq3Polarity_Val(Rte_InitValue_HwTq3Polarity_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_PolarityCfg_Rte_Write_HwTq4Polarity_Val(Rte_InitValue_HwTq4Polarity_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_PolarityCfg_Rte_Write_HwTq5Polarity_Val(Rte_InitValue_HwTq5Polarity_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_PolarityCfg_Rte_Write_HwTq6Polarity_Val(Rte_InitValue_HwTq6Polarity_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_PolarityCfg_Rte_Write_HwTq7Polarity_Val(Rte_InitValue_HwTq7Polarity_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_PolarityCfg_Rte_Write_MotAgMecl0Polarity_Val(Rte_InitValue_MotAgMecl0Polarity_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_PolarityCfg_Rte_Write_MotAgMecl1Polarity_Val(Rte_InitValue_MotAgMecl1Polarity_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_PolarityCfg_Rte_Write_MotAgMecl2Polarity_Val(Rte_InitValue_MotAgMecl2Polarity_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_PolarityCfg_Rte_Write_MotAgMecl3Polarity_Val(Rte_InitValue_MotAgMecl3Polarity_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_PolarityCfg_Rte_Write_MotAgMecl4Polarity_Val(Rte_InitValue_MotAgMecl4Polarity_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_PolarityCfg_Rte_Write_MotAgMecl5Polarity_Val(Rte_InitValue_MotAgMecl5Polarity_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_PolarityCfg_Rte_Write_MotAgMecl6Polarity_Val(Rte_InitValue_MotAgMecl6Polarity_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_PolarityCfg_Rte_Write_MotAgMecl7Polarity_Val(Rte_InitValue_MotAgMecl7Polarity_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_PolarityCfg_Rte_Write_MotElecMeclPolarity_Val(Rte_InitValue_MotElecMeclPolarity_Val);
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
 * Runnable Entity Name: PolarityCfgRead_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <PolarityCfgRead>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType PolarityCfgRead_Oper(uint32 *PolarityCfgSaved_Arg)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_PolarityCfgRead_PortIf1_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: PolarityCfgRead_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, PolarityCfg_CODE) PolarityCfgRead_Oper(P2VAR(uint32, AUTOMATIC, RTE_POLARITYCFG_APPL_VAR) PolarityCfgSaved_Arg) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: PolarityCfgRead_Oper (returns application error)
 *********************************************************************************************************************/

  uint32 PimPolarityCfgSaved;

  uint32 PolarityCfgSavedDft_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimPolarityCfgSaved = *TSC_PolarityCfg_Rte_Pim_PolarityCfgSaved();
  *TSC_PolarityCfg_Rte_Pim_PolarityCfgSaved() = PimPolarityCfgSaved;

  PolarityCfgSavedDft_data = TSC_PolarityCfg_Rte_CData_PolarityCfgSavedDft();

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PolarityCfgWr_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <PolarityCfgWr>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_PolarityCfgSaved_SetRamBlockStatus(boolean RamBlockStatus_Arg)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType PolarityCfgWr_Oper(uint32 PolarityCfgSaved_Arg)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_PolarityCfgWr_PortIf1_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: PolarityCfgWr_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, PolarityCfg_CODE) PolarityCfgWr_Oper(uint32 PolarityCfgSaved_Arg) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: PolarityCfgWr_Oper (returns application error)
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  uint32 PimPolarityCfgSaved;

  uint32 PolarityCfgSavedDft_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimPolarityCfgSaved = *TSC_PolarityCfg_Rte_Pim_PolarityCfgSaved();
  *TSC_PolarityCfg_Rte_Pim_PolarityCfgSaved() = PimPolarityCfgSaved;

  PolarityCfgSavedDft_data = TSC_PolarityCfg_Rte_CData_PolarityCfgSavedDft();

  fct_status = TSC_PolarityCfg_Rte_Call_PolarityCfgSaved_SetRamBlockStatus(FALSE);
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
    case RTE_E_NvMService_AC3_SRBS_E_NOT_OK:
      fct_error = 1;
      break;
  }

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define PolarityCfg_STOP_SEC_CODE
#include "PolarityCfg_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


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
