/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  CDD_Tauj0CfgAndUse.c
 *        Config:  EPS.dpa
 *     SW-C Type:  CDD_Tauj0CfgAndUse
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <CDD_Tauj0CfgAndUse>
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

#include "Rte_CDD_Tauj0CfgAndUse.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_CDD_Tauj0CfgAndUse.h"


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
 * uint32: Integer in interval [0...4294967295] (standard type)
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
 *   uint32 *Rte_Pim_PhaOnTiCntrAPrev(void)
 *   uint32 *Rte_Pim_PhaOnTiCntrBPrev(void)
 *   uint32 *Rte_Pim_PhaOnTiCntrCPrev(void)
 *
 *********************************************************************************************************************/


#define CDD_Tauj0CfgAndUse_START_SEC_CODE
#include "CDD_Tauj0CfgAndUse_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Tauj0CfgAndUseInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Tauj0CfgAndUseInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CDD_Tauj0CfgAndUse_CODE) Tauj0CfgAndUseInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Tauj0CfgAndUseInit1
 *********************************************************************************************************************/

  uint32 PimPhaOnTiCntrAPrev;
  uint32 PimPhaOnTiCntrBPrev;
  uint32 PimPhaOnTiCntrCPrev;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimPhaOnTiCntrAPrev = *TSC_CDD_Tauj0CfgAndUse_Rte_Pim_PhaOnTiCntrAPrev();
  *TSC_CDD_Tauj0CfgAndUse_Rte_Pim_PhaOnTiCntrAPrev() = PimPhaOnTiCntrAPrev;
  PimPhaOnTiCntrBPrev = *TSC_CDD_Tauj0CfgAndUse_Rte_Pim_PhaOnTiCntrBPrev();
  *TSC_CDD_Tauj0CfgAndUse_Rte_Pim_PhaOnTiCntrBPrev() = PimPhaOnTiCntrBPrev;
  PimPhaOnTiCntrCPrev = *TSC_CDD_Tauj0CfgAndUse_Rte_Pim_PhaOnTiCntrCPrev();
  *TSC_CDD_Tauj0CfgAndUse_Rte_Pim_PhaOnTiCntrCPrev() = PimPhaOnTiCntrCPrev;


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Tauj0CfgAndUsePer1
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
 *   Std_ReturnType Rte_Write_PhaOnTiMeasdA_Val(uint32 data)
 *   Std_ReturnType Rte_Write_PhaOnTiMeasdB_Val(uint32 data)
 *   Std_ReturnType Rte_Write_PhaOnTiMeasdC_Val(uint32 data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Tauj0CfgAndUsePer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CDD_Tauj0CfgAndUse_CODE) Tauj0CfgAndUsePer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Tauj0CfgAndUsePer1
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  uint32 PimPhaOnTiCntrAPrev;
  uint32 PimPhaOnTiCntrBPrev;
  uint32 PimPhaOnTiCntrCPrev;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimPhaOnTiCntrAPrev = *TSC_CDD_Tauj0CfgAndUse_Rte_Pim_PhaOnTiCntrAPrev();
  *TSC_CDD_Tauj0CfgAndUse_Rte_Pim_PhaOnTiCntrAPrev() = PimPhaOnTiCntrAPrev;
  PimPhaOnTiCntrBPrev = *TSC_CDD_Tauj0CfgAndUse_Rte_Pim_PhaOnTiCntrBPrev();
  *TSC_CDD_Tauj0CfgAndUse_Rte_Pim_PhaOnTiCntrBPrev() = PimPhaOnTiCntrBPrev;
  PimPhaOnTiCntrCPrev = *TSC_CDD_Tauj0CfgAndUse_Rte_Pim_PhaOnTiCntrCPrev();
  *TSC_CDD_Tauj0CfgAndUse_Rte_Pim_PhaOnTiCntrCPrev() = PimPhaOnTiCntrCPrev;

  fct_status = TSC_CDD_Tauj0CfgAndUse_Rte_Write_PhaOnTiMeasdA_Val(Rte_InitValue_PhaOnTiMeasdA_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CDD_Tauj0CfgAndUse_Rte_Write_PhaOnTiMeasdB_Val(Rte_InitValue_PhaOnTiMeasdB_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CDD_Tauj0CfgAndUse_Rte_Write_PhaOnTiMeasdC_Val(Rte_InitValue_PhaOnTiMeasdC_Val);
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


#define CDD_Tauj0CfgAndUse_STOP_SEC_CODE
#include "CDD_Tauj0CfgAndUse_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


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
