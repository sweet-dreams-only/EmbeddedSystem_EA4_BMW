/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  PwrUpSeq.c
 *        Config:  EPS.dpa
 *     SW-C Type:  PwrUpSeq
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <PwrUpSeq>
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
 * SysSt1
 *   
 *
 *********************************************************************************************************************/

#include "Rte_PwrUpSeq.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_PwrUpSeq.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"

static void PwrUpSeq_TestDefines(void);


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
 * uint8: Integer in interval [0...255] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * SysSt1: Enumeration of integer in interval [0...255] with enumerators
 *   SYSST_DI (0U)
 *   SYSST_OFF (1U)
 *   SYSST_ENA (2U)
 *   SYSST_WRMININ (3U)
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   uint8 *Rte_Pim_PwrTurnOffCtrlPrev(void)
 *
 *********************************************************************************************************************/


#define PwrUpSeq_START_SEC_CODE
#include "PwrUpSeq_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PwrTurnOffCtrl_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <PwrTurnOffCtrl>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_IoHwAb_SetGpioPwrTurnOffCtrl_Oper(boolean PinSt_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetGpio_PortIf1_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void PwrTurnOffCtrl_Oper(boolean PinSt_Arg)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: PwrTurnOffCtrl_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, PwrUpSeq_CODE) PwrTurnOffCtrl_Oper(boolean PinSt_Arg) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: PwrTurnOffCtrl_Oper
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  uint8 PimPwrTurnOffCtrlPrev;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimPwrTurnOffCtrlPrev = *TSC_PwrUpSeq_Rte_Pim_PwrTurnOffCtrlPrev();
  *TSC_PwrUpSeq_Rte_Pim_PwrTurnOffCtrlPrev() = PimPwrTurnOffCtrlPrev;

  fct_status = TSC_PwrUpSeq_Rte_Call_IoHwAb_SetGpioPwrTurnOffCtrl_Oper(FALSE);
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
    case RTE_E_SetGpio_PortIf1_E_NOT_OK:
      fct_error = 1;
      break;
  }

  PwrUpSeq_TestDefines();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PwrUpSeqInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: PwrUpSeqInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, PwrUpSeq_CODE) PwrUpSeqInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: PwrUpSeqInit1
 *********************************************************************************************************************/

  uint8 PimPwrTurnOffCtrlPrev;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimPwrTurnOffCtrlPrev = *TSC_PwrUpSeq_Rte_Pim_PwrTurnOffCtrlPrev();
  *TSC_PwrUpSeq_Rte_Pim_PwrTurnOffCtrlPrev() = PimPwrTurnOffCtrlPrev;


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PwrUpSeqPer1
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
 *   Std_ReturnType Rte_Read_CodFlsCrcChkCmpl_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_CurrMeasWrmIninTestCmpl_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_MotDrvr0IninTestCmpl_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_MotDrvr1IninTestCmpl_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_PhaDiscnctWrmIninTestCmpl_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_PwrDiscnctATestCmpl_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_PwrDiscnctBTestCmpl_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_SysSt_Val(SysSt1 *data)
 *   Std_ReturnType Rte_Read_TmplMonIninTestCmpl_Logl(boolean *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_StrtUpSt_Val(uint8 data)
 *   Std_ReturnType Rte_Write_SysStWrmIninCmpl_Logl(boolean data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: PwrUpSeqPer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, PwrUpSeq_CODE) PwrUpSeqPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: PwrUpSeqPer1
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  boolean Read_CodFlsCrcChkCmpl_Logl;
  boolean Read_CurrMeasWrmIninTestCmpl_Logl;
  boolean Read_MotDrvr0IninTestCmpl_Logl;
  boolean Read_MotDrvr1IninTestCmpl_Logl;
  boolean Read_PhaDiscnctWrmIninTestCmpl_Logl;
  boolean Read_PwrDiscnctATestCmpl_Logl;
  boolean Read_PwrDiscnctBTestCmpl_Logl;
  SysSt1 Read_SysSt_Val;
  boolean Read_TmplMonIninTestCmpl_Logl;

  uint8 PimPwrTurnOffCtrlPrev;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimPwrTurnOffCtrlPrev = *TSC_PwrUpSeq_Rte_Pim_PwrTurnOffCtrlPrev();
  *TSC_PwrUpSeq_Rte_Pim_PwrTurnOffCtrlPrev() = PimPwrTurnOffCtrlPrev;

  fct_status = TSC_PwrUpSeq_Rte_Read_CodFlsCrcChkCmpl_Logl(&Read_CodFlsCrcChkCmpl_Logl);
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

  fct_status = TSC_PwrUpSeq_Rte_Read_CurrMeasWrmIninTestCmpl_Logl(&Read_CurrMeasWrmIninTestCmpl_Logl);
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

  fct_status = TSC_PwrUpSeq_Rte_Read_MotDrvr0IninTestCmpl_Logl(&Read_MotDrvr0IninTestCmpl_Logl);
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

  fct_status = TSC_PwrUpSeq_Rte_Read_MotDrvr1IninTestCmpl_Logl(&Read_MotDrvr1IninTestCmpl_Logl);
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

  fct_status = TSC_PwrUpSeq_Rte_Read_PhaDiscnctWrmIninTestCmpl_Logl(&Read_PhaDiscnctWrmIninTestCmpl_Logl);
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

  fct_status = TSC_PwrUpSeq_Rte_Read_PwrDiscnctATestCmpl_Logl(&Read_PwrDiscnctATestCmpl_Logl);
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

  fct_status = TSC_PwrUpSeq_Rte_Read_PwrDiscnctBTestCmpl_Logl(&Read_PwrDiscnctBTestCmpl_Logl);
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

  fct_status = TSC_PwrUpSeq_Rte_Read_SysSt_Val(&Read_SysSt_Val);
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

  fct_status = TSC_PwrUpSeq_Rte_Read_TmplMonIninTestCmpl_Logl(&Read_TmplMonIninTestCmpl_Logl);
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

  fct_status = TSC_PwrUpSeq_Rte_Write_StrtUpSt_Val(Rte_InitValue_StrtUpSt_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_PwrUpSeq_Rte_Write_SysStWrmIninCmpl_Logl(Rte_InitValue_SysStWrmIninCmpl_Logl);
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


#define PwrUpSeq_STOP_SEC_CODE
#include "PwrUpSeq_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void PwrUpSeq_TestDefines(void)
{
  /* Enumeration Data Types */

  SysSt1 Test_SysSt1_V_1 = SYSST_DI;
  SysSt1 Test_SysSt1_V_2 = SYSST_OFF;
  SysSt1 Test_SysSt1_V_3 = SYSST_ENA;
  SysSt1 Test_SysSt1_V_4 = SYSST_WRMININ;
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
