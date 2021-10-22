/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  CDD_Adc1CfgAndUse.c
 *        Config:  EPS.dpa
 *     SW-C Type:  CDD_Adc1CfgAndUse
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <CDD_Adc1CfgAndUse>
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

#include "Rte_CDD_Adc1CfgAndUse.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_CDD_Adc1CfgAndUse.h"


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
 * uint8: Integer in interval [0...255] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   uint8 *Rte_Pim_Adc1DiagcEndPtr(void)
 *   uint8 *Rte_Pim_Adc1DiagcStrtPtr(void)
 *
 *********************************************************************************************************************/


#define CDD_Adc1CfgAndUse_START_SEC_CODE
#include "CDD_Adc1CfgAndUse_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Adc1CfgAndUseAdc1EnaCnvn_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <Adc1CfgAndUseAdc1EnaCnvn>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void Adc1CfgAndUseAdc1EnaCnvn_Oper(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Adc1CfgAndUseAdc1EnaCnvn_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CDD_Adc1CfgAndUse_CODE) Adc1CfgAndUseAdc1EnaCnvn_Oper(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Adc1CfgAndUseAdc1EnaCnvn_Oper
 *********************************************************************************************************************/

  uint8 PimAdc1DiagcEndPtr;
  uint8 PimAdc1DiagcStrtPtr;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimAdc1DiagcEndPtr = *TSC_CDD_Adc1CfgAndUse_Rte_Pim_Adc1DiagcEndPtr();
  *TSC_CDD_Adc1CfgAndUse_Rte_Pim_Adc1DiagcEndPtr() = PimAdc1DiagcEndPtr;
  PimAdc1DiagcStrtPtr = *TSC_CDD_Adc1CfgAndUse_Rte_Pim_Adc1DiagcStrtPtr();
  *TSC_CDD_Adc1CfgAndUse_Rte_Pim_Adc1DiagcStrtPtr() = PimAdc1DiagcStrtPtr;


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Adc1CfgAndUseInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Adc1CfgAndUseInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CDD_Adc1CfgAndUse_CODE) Adc1CfgAndUseInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Adc1CfgAndUseInit1
 *********************************************************************************************************************/

  uint8 PimAdc1DiagcEndPtr;
  uint8 PimAdc1DiagcStrtPtr;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimAdc1DiagcEndPtr = *TSC_CDD_Adc1CfgAndUse_Rte_Pim_Adc1DiagcEndPtr();
  *TSC_CDD_Adc1CfgAndUse_Rte_Pim_Adc1DiagcEndPtr() = PimAdc1DiagcEndPtr;
  PimAdc1DiagcStrtPtr = *TSC_CDD_Adc1CfgAndUse_Rte_Pim_Adc1DiagcStrtPtr();
  *TSC_CDD_Adc1CfgAndUse_Rte_Pim_Adc1DiagcStrtPtr() = PimAdc1DiagcStrtPtr;


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Adc1CfgAndUsePer1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Adc1CfgAndUsePer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CDD_Adc1CfgAndUse_CODE) Adc1CfgAndUsePer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Adc1CfgAndUsePer1
 *********************************************************************************************************************/

  uint8 PimAdc1DiagcEndPtr;
  uint8 PimAdc1DiagcStrtPtr;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimAdc1DiagcEndPtr = *TSC_CDD_Adc1CfgAndUse_Rte_Pim_Adc1DiagcEndPtr();
  *TSC_CDD_Adc1CfgAndUse_Rte_Pim_Adc1DiagcEndPtr() = PimAdc1DiagcEndPtr;
  PimAdc1DiagcStrtPtr = *TSC_CDD_Adc1CfgAndUse_Rte_Pim_Adc1DiagcStrtPtr();
  *TSC_CDD_Adc1CfgAndUse_Rte_Pim_Adc1DiagcStrtPtr() = PimAdc1DiagcStrtPtr;


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Adc1CfgAndUsePer2
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
 *   Std_ReturnType Rte_Read_AdcDiagcEndPtrOutp_Val(uint8 *data)
 *   Std_ReturnType Rte_Read_AdcDiagcStrtPtrOutp_Val(uint8 *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Adc1CfgAndUsePer2_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CDD_Adc1CfgAndUse_CODE) Adc1CfgAndUsePer2(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Adc1CfgAndUsePer2
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  uint8 Read_AdcDiagcEndPtrOutp_Val;
  uint8 Read_AdcDiagcStrtPtrOutp_Val;

  uint8 PimAdc1DiagcEndPtr;
  uint8 PimAdc1DiagcStrtPtr;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimAdc1DiagcEndPtr = *TSC_CDD_Adc1CfgAndUse_Rte_Pim_Adc1DiagcEndPtr();
  *TSC_CDD_Adc1CfgAndUse_Rte_Pim_Adc1DiagcEndPtr() = PimAdc1DiagcEndPtr;
  PimAdc1DiagcStrtPtr = *TSC_CDD_Adc1CfgAndUse_Rte_Pim_Adc1DiagcStrtPtr();
  *TSC_CDD_Adc1CfgAndUse_Rte_Pim_Adc1DiagcStrtPtr() = PimAdc1DiagcStrtPtr;

  fct_status = TSC_CDD_Adc1CfgAndUse_Rte_Read_AdcDiagcEndPtrOutp_Val(&Read_AdcDiagcEndPtrOutp_Val);
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

  fct_status = TSC_CDD_Adc1CfgAndUse_Rte_Read_AdcDiagcStrtPtrOutp_Val(&Read_AdcDiagcStrtPtrOutp_Val);
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


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define CDD_Adc1CfgAndUse_STOP_SEC_CODE
#include "CDD_Adc1CfgAndUse_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


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
