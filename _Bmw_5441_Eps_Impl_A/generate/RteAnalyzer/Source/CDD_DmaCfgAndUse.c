/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  CDD_DmaCfgAndUse.c
 *        Config:  EPS.dpa
 *     SW-C Type:  CDD_DmaCfgAndUse
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <CDD_DmaCfgAndUse>
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

#include "Rte_CDD_DmaCfgAndUse.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_CDD_DmaCfgAndUse.h"


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
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   uint32 *Rte_Pim_DmaCfgAndUse2MilliSecAdcMaxDmaTrfTi(void)
 *   uint32 *Rte_Pim_DmaCfgAndUse2MilliSecAdcStrtTi(void)
 *   uint32 *Rte_Pim_MotAg0ReadPtrRst(void)
 *   uint32 *Rte_Pim_MotAg0SnsrCfgAdrStord(void)
 *   uint32 *Rte_Pim_MotAg0TrsmStrt(void)
 *   uint32 *Rte_Pim_MotAg1ReadPtrRst(void)
 *   uint32 *Rte_Pim_MotAg1SnsrCfgAdrStord(void)
 *   uint32 *Rte_Pim_MotAg1TrsmStrt(void)
 *   uint32 *Rte_Pim_d2MilliSecAdcActDmaTrfTi(void)
 *
 *********************************************************************************************************************/


#define CDD_DmaCfgAndUse_START_SEC_CODE
#include "CDD_DmaCfgAndUse_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DmaCfgAndUseInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_MotAg0SnsrCfgAdr_Val(uint32 *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DmaCfgAndUseInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CDD_DmaCfgAndUse_CODE) DmaCfgAndUseInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DmaCfgAndUseInit1
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  uint32 Read_MotAg0SnsrCfgAdr_Val;

  uint32 PimDmaCfgAndUse2MilliSecAdcMaxDmaTrfTi;
  uint32 PimDmaCfgAndUse2MilliSecAdcStrtTi;
  uint32 PimMotAg0ReadPtrRst;
  uint32 PimMotAg0SnsrCfgAdrStord;
  uint32 PimMotAg0TrsmStrt;
  uint32 PimMotAg1ReadPtrRst;
  uint32 PimMotAg1SnsrCfgAdrStord;
  uint32 PimMotAg1TrsmStrt;
  uint32 Pimd2MilliSecAdcActDmaTrfTi;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimDmaCfgAndUse2MilliSecAdcMaxDmaTrfTi = *TSC_CDD_DmaCfgAndUse_Rte_Pim_DmaCfgAndUse2MilliSecAdcMaxDmaTrfTi();
  *TSC_CDD_DmaCfgAndUse_Rte_Pim_DmaCfgAndUse2MilliSecAdcMaxDmaTrfTi() = PimDmaCfgAndUse2MilliSecAdcMaxDmaTrfTi;
  PimDmaCfgAndUse2MilliSecAdcStrtTi = *TSC_CDD_DmaCfgAndUse_Rte_Pim_DmaCfgAndUse2MilliSecAdcStrtTi();
  *TSC_CDD_DmaCfgAndUse_Rte_Pim_DmaCfgAndUse2MilliSecAdcStrtTi() = PimDmaCfgAndUse2MilliSecAdcStrtTi;
  PimMotAg0ReadPtrRst = *TSC_CDD_DmaCfgAndUse_Rte_Pim_MotAg0ReadPtrRst();
  *TSC_CDD_DmaCfgAndUse_Rte_Pim_MotAg0ReadPtrRst() = PimMotAg0ReadPtrRst;
  PimMotAg0SnsrCfgAdrStord = *TSC_CDD_DmaCfgAndUse_Rte_Pim_MotAg0SnsrCfgAdrStord();
  *TSC_CDD_DmaCfgAndUse_Rte_Pim_MotAg0SnsrCfgAdrStord() = PimMotAg0SnsrCfgAdrStord;
  PimMotAg0TrsmStrt = *TSC_CDD_DmaCfgAndUse_Rte_Pim_MotAg0TrsmStrt();
  *TSC_CDD_DmaCfgAndUse_Rte_Pim_MotAg0TrsmStrt() = PimMotAg0TrsmStrt;
  PimMotAg1ReadPtrRst = *TSC_CDD_DmaCfgAndUse_Rte_Pim_MotAg1ReadPtrRst();
  *TSC_CDD_DmaCfgAndUse_Rte_Pim_MotAg1ReadPtrRst() = PimMotAg1ReadPtrRst;
  PimMotAg1SnsrCfgAdrStord = *TSC_CDD_DmaCfgAndUse_Rte_Pim_MotAg1SnsrCfgAdrStord();
  *TSC_CDD_DmaCfgAndUse_Rte_Pim_MotAg1SnsrCfgAdrStord() = PimMotAg1SnsrCfgAdrStord;
  PimMotAg1TrsmStrt = *TSC_CDD_DmaCfgAndUse_Rte_Pim_MotAg1TrsmStrt();
  *TSC_CDD_DmaCfgAndUse_Rte_Pim_MotAg1TrsmStrt() = PimMotAg1TrsmStrt;
  Pimd2MilliSecAdcActDmaTrfTi = *TSC_CDD_DmaCfgAndUse_Rte_Pim_d2MilliSecAdcActDmaTrfTi();
  *TSC_CDD_DmaCfgAndUse_Rte_Pim_d2MilliSecAdcActDmaTrfTi() = Pimd2MilliSecAdcActDmaTrfTi;

  fct_status = TSC_CDD_DmaCfgAndUse_Rte_Read_MotAg0SnsrCfgAdr_Val(&Read_MotAg0SnsrCfgAdr_Val);
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

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DmaCfgAndUsePer1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_Adc1CfgAndUseAdc1EnaCnvn_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_GetRefTmr1MicroSec32bit_Oper(uint32 *RefTmr_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DmaCfgAndUsePer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CDD_DmaCfgAndUse_CODE) DmaCfgAndUsePer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DmaCfgAndUsePer1
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  uint32 PimDmaCfgAndUse2MilliSecAdcMaxDmaTrfTi;
  uint32 PimDmaCfgAndUse2MilliSecAdcStrtTi;
  uint32 PimMotAg0ReadPtrRst;
  uint32 PimMotAg0SnsrCfgAdrStord;
  uint32 PimMotAg0TrsmStrt;
  uint32 PimMotAg1ReadPtrRst;
  uint32 PimMotAg1SnsrCfgAdrStord;
  uint32 PimMotAg1TrsmStrt;
  uint32 Pimd2MilliSecAdcActDmaTrfTi;

  uint32 Call_GetRefTmr1MicroSec32bit_Oper_RefTmr_Arg = 0U;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimDmaCfgAndUse2MilliSecAdcMaxDmaTrfTi = *TSC_CDD_DmaCfgAndUse_Rte_Pim_DmaCfgAndUse2MilliSecAdcMaxDmaTrfTi();
  *TSC_CDD_DmaCfgAndUse_Rte_Pim_DmaCfgAndUse2MilliSecAdcMaxDmaTrfTi() = PimDmaCfgAndUse2MilliSecAdcMaxDmaTrfTi;
  PimDmaCfgAndUse2MilliSecAdcStrtTi = *TSC_CDD_DmaCfgAndUse_Rte_Pim_DmaCfgAndUse2MilliSecAdcStrtTi();
  *TSC_CDD_DmaCfgAndUse_Rte_Pim_DmaCfgAndUse2MilliSecAdcStrtTi() = PimDmaCfgAndUse2MilliSecAdcStrtTi;
  PimMotAg0ReadPtrRst = *TSC_CDD_DmaCfgAndUse_Rte_Pim_MotAg0ReadPtrRst();
  *TSC_CDD_DmaCfgAndUse_Rte_Pim_MotAg0ReadPtrRst() = PimMotAg0ReadPtrRst;
  PimMotAg0SnsrCfgAdrStord = *TSC_CDD_DmaCfgAndUse_Rte_Pim_MotAg0SnsrCfgAdrStord();
  *TSC_CDD_DmaCfgAndUse_Rte_Pim_MotAg0SnsrCfgAdrStord() = PimMotAg0SnsrCfgAdrStord;
  PimMotAg0TrsmStrt = *TSC_CDD_DmaCfgAndUse_Rte_Pim_MotAg0TrsmStrt();
  *TSC_CDD_DmaCfgAndUse_Rte_Pim_MotAg0TrsmStrt() = PimMotAg0TrsmStrt;
  PimMotAg1ReadPtrRst = *TSC_CDD_DmaCfgAndUse_Rte_Pim_MotAg1ReadPtrRst();
  *TSC_CDD_DmaCfgAndUse_Rte_Pim_MotAg1ReadPtrRst() = PimMotAg1ReadPtrRst;
  PimMotAg1SnsrCfgAdrStord = *TSC_CDD_DmaCfgAndUse_Rte_Pim_MotAg1SnsrCfgAdrStord();
  *TSC_CDD_DmaCfgAndUse_Rte_Pim_MotAg1SnsrCfgAdrStord() = PimMotAg1SnsrCfgAdrStord;
  PimMotAg1TrsmStrt = *TSC_CDD_DmaCfgAndUse_Rte_Pim_MotAg1TrsmStrt();
  *TSC_CDD_DmaCfgAndUse_Rte_Pim_MotAg1TrsmStrt() = PimMotAg1TrsmStrt;
  Pimd2MilliSecAdcActDmaTrfTi = *TSC_CDD_DmaCfgAndUse_Rte_Pim_d2MilliSecAdcActDmaTrfTi();
  *TSC_CDD_DmaCfgAndUse_Rte_Pim_d2MilliSecAdcActDmaTrfTi() = Pimd2MilliSecAdcActDmaTrfTi;

  fct_status = TSC_CDD_DmaCfgAndUse_Rte_Call_Adc1CfgAndUseAdc1EnaCnvn_Oper();
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

  fct_status = TSC_CDD_DmaCfgAndUse_Rte_Call_GetRefTmr1MicroSec32bit_Oper(&Call_GetRefTmr1MicroSec32bit_Oper_RefTmr_Arg);
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
 * Runnable Entity Name: DmaEna2MilliSecToMotCtrlTrf_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <DmaEna2MilliSecToMotCtrlTrf>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_ReadErrInjReg_Oper(uint32 *ErrId_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_StrtErrInjCntr_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void DmaEna2MilliSecToMotCtrlTrf_Oper(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DmaEna2MilliSecToMotCtrlTrf_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CDD_DmaCfgAndUse_CODE) DmaEna2MilliSecToMotCtrlTrf_Oper(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DmaEna2MilliSecToMotCtrlTrf_Oper
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  uint32 PimDmaCfgAndUse2MilliSecAdcMaxDmaTrfTi;
  uint32 PimDmaCfgAndUse2MilliSecAdcStrtTi;
  uint32 PimMotAg0ReadPtrRst;
  uint32 PimMotAg0SnsrCfgAdrStord;
  uint32 PimMotAg0TrsmStrt;
  uint32 PimMotAg1ReadPtrRst;
  uint32 PimMotAg1SnsrCfgAdrStord;
  uint32 PimMotAg1TrsmStrt;
  uint32 Pimd2MilliSecAdcActDmaTrfTi;

  uint32 Call_ReadErrInjReg_Oper_ErrId_Arg = 0U;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimDmaCfgAndUse2MilliSecAdcMaxDmaTrfTi = *TSC_CDD_DmaCfgAndUse_Rte_Pim_DmaCfgAndUse2MilliSecAdcMaxDmaTrfTi();
  *TSC_CDD_DmaCfgAndUse_Rte_Pim_DmaCfgAndUse2MilliSecAdcMaxDmaTrfTi() = PimDmaCfgAndUse2MilliSecAdcMaxDmaTrfTi;
  PimDmaCfgAndUse2MilliSecAdcStrtTi = *TSC_CDD_DmaCfgAndUse_Rte_Pim_DmaCfgAndUse2MilliSecAdcStrtTi();
  *TSC_CDD_DmaCfgAndUse_Rte_Pim_DmaCfgAndUse2MilliSecAdcStrtTi() = PimDmaCfgAndUse2MilliSecAdcStrtTi;
  PimMotAg0ReadPtrRst = *TSC_CDD_DmaCfgAndUse_Rte_Pim_MotAg0ReadPtrRst();
  *TSC_CDD_DmaCfgAndUse_Rte_Pim_MotAg0ReadPtrRst() = PimMotAg0ReadPtrRst;
  PimMotAg0SnsrCfgAdrStord = *TSC_CDD_DmaCfgAndUse_Rte_Pim_MotAg0SnsrCfgAdrStord();
  *TSC_CDD_DmaCfgAndUse_Rte_Pim_MotAg0SnsrCfgAdrStord() = PimMotAg0SnsrCfgAdrStord;
  PimMotAg0TrsmStrt = *TSC_CDD_DmaCfgAndUse_Rte_Pim_MotAg0TrsmStrt();
  *TSC_CDD_DmaCfgAndUse_Rte_Pim_MotAg0TrsmStrt() = PimMotAg0TrsmStrt;
  PimMotAg1ReadPtrRst = *TSC_CDD_DmaCfgAndUse_Rte_Pim_MotAg1ReadPtrRst();
  *TSC_CDD_DmaCfgAndUse_Rte_Pim_MotAg1ReadPtrRst() = PimMotAg1ReadPtrRst;
  PimMotAg1SnsrCfgAdrStord = *TSC_CDD_DmaCfgAndUse_Rte_Pim_MotAg1SnsrCfgAdrStord();
  *TSC_CDD_DmaCfgAndUse_Rte_Pim_MotAg1SnsrCfgAdrStord() = PimMotAg1SnsrCfgAdrStord;
  PimMotAg1TrsmStrt = *TSC_CDD_DmaCfgAndUse_Rte_Pim_MotAg1TrsmStrt();
  *TSC_CDD_DmaCfgAndUse_Rte_Pim_MotAg1TrsmStrt() = PimMotAg1TrsmStrt;
  Pimd2MilliSecAdcActDmaTrfTi = *TSC_CDD_DmaCfgAndUse_Rte_Pim_d2MilliSecAdcActDmaTrfTi();
  *TSC_CDD_DmaCfgAndUse_Rte_Pim_d2MilliSecAdcActDmaTrfTi() = Pimd2MilliSecAdcActDmaTrfTi;

  fct_status = TSC_CDD_DmaCfgAndUse_Rte_Call_ReadErrInjReg_Oper(&Call_ReadErrInjReg_Oper_ErrId_Arg);
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

  fct_status = TSC_CDD_DmaCfgAndUse_Rte_Call_StrtErrInjCntr_Oper();
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
 * Runnable Entity Name: DmaWaitForMotCtrlTo2MilliSecTrf_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <DmaWaitForMotCtrlTo2MilliSecTrf>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_GetTiSpan1MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DmaWaitForMotCtrlTo2MilliSecTrf_Oper(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DmaWaitForMotCtrlTo2MilliSecTrf_PortIf1_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DmaWaitForMotCtrlTo2MilliSecTrf_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CDD_DmaCfgAndUse_CODE) DmaWaitForMotCtrlTo2MilliSecTrf_Oper(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DmaWaitForMotCtrlTo2MilliSecTrf_Oper (returns application error)
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  uint32 PimDmaCfgAndUse2MilliSecAdcMaxDmaTrfTi;
  uint32 PimDmaCfgAndUse2MilliSecAdcStrtTi;
  uint32 PimMotAg0ReadPtrRst;
  uint32 PimMotAg0SnsrCfgAdrStord;
  uint32 PimMotAg0TrsmStrt;
  uint32 PimMotAg1ReadPtrRst;
  uint32 PimMotAg1SnsrCfgAdrStord;
  uint32 PimMotAg1TrsmStrt;
  uint32 Pimd2MilliSecAdcActDmaTrfTi;

  uint32 Call_GetTiSpan1MicroSec32bit_Oper_TiSpan_Arg = 0U;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimDmaCfgAndUse2MilliSecAdcMaxDmaTrfTi = *TSC_CDD_DmaCfgAndUse_Rte_Pim_DmaCfgAndUse2MilliSecAdcMaxDmaTrfTi();
  *TSC_CDD_DmaCfgAndUse_Rte_Pim_DmaCfgAndUse2MilliSecAdcMaxDmaTrfTi() = PimDmaCfgAndUse2MilliSecAdcMaxDmaTrfTi;
  PimDmaCfgAndUse2MilliSecAdcStrtTi = *TSC_CDD_DmaCfgAndUse_Rte_Pim_DmaCfgAndUse2MilliSecAdcStrtTi();
  *TSC_CDD_DmaCfgAndUse_Rte_Pim_DmaCfgAndUse2MilliSecAdcStrtTi() = PimDmaCfgAndUse2MilliSecAdcStrtTi;
  PimMotAg0ReadPtrRst = *TSC_CDD_DmaCfgAndUse_Rte_Pim_MotAg0ReadPtrRst();
  *TSC_CDD_DmaCfgAndUse_Rte_Pim_MotAg0ReadPtrRst() = PimMotAg0ReadPtrRst;
  PimMotAg0SnsrCfgAdrStord = *TSC_CDD_DmaCfgAndUse_Rte_Pim_MotAg0SnsrCfgAdrStord();
  *TSC_CDD_DmaCfgAndUse_Rte_Pim_MotAg0SnsrCfgAdrStord() = PimMotAg0SnsrCfgAdrStord;
  PimMotAg0TrsmStrt = *TSC_CDD_DmaCfgAndUse_Rte_Pim_MotAg0TrsmStrt();
  *TSC_CDD_DmaCfgAndUse_Rte_Pim_MotAg0TrsmStrt() = PimMotAg0TrsmStrt;
  PimMotAg1ReadPtrRst = *TSC_CDD_DmaCfgAndUse_Rte_Pim_MotAg1ReadPtrRst();
  *TSC_CDD_DmaCfgAndUse_Rte_Pim_MotAg1ReadPtrRst() = PimMotAg1ReadPtrRst;
  PimMotAg1SnsrCfgAdrStord = *TSC_CDD_DmaCfgAndUse_Rte_Pim_MotAg1SnsrCfgAdrStord();
  *TSC_CDD_DmaCfgAndUse_Rte_Pim_MotAg1SnsrCfgAdrStord() = PimMotAg1SnsrCfgAdrStord;
  PimMotAg1TrsmStrt = *TSC_CDD_DmaCfgAndUse_Rte_Pim_MotAg1TrsmStrt();
  *TSC_CDD_DmaCfgAndUse_Rte_Pim_MotAg1TrsmStrt() = PimMotAg1TrsmStrt;
  Pimd2MilliSecAdcActDmaTrfTi = *TSC_CDD_DmaCfgAndUse_Rte_Pim_d2MilliSecAdcActDmaTrfTi();
  *TSC_CDD_DmaCfgAndUse_Rte_Pim_d2MilliSecAdcActDmaTrfTi() = Pimd2MilliSecAdcActDmaTrfTi;

  fct_status = TSC_CDD_DmaCfgAndUse_Rte_Call_GetTiSpan1MicroSec32bit_Oper(0U, &Call_GetTiSpan1MicroSec32bit_Oper_TiSpan_Arg);
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
    case RTE_E_DmaWaitForMotCtrlTo2MilliSecTrf_PortIf1_E_NOT_OK:
      fct_error = 1;
      break;
  }

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MotAg0SnsrCfgDmaStrt_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <MotAg0SnsrCfgDmaStrt>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MotAg0SnsrCfgDmaStrt_Oper(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_MotAg0SnsrCfgDmaStrt_PortIf2_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MotAg0SnsrCfgDmaStrt_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CDD_DmaCfgAndUse_CODE) MotAg0SnsrCfgDmaStrt_Oper(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MotAg0SnsrCfgDmaStrt_Oper (returns application error)
 *********************************************************************************************************************/

  uint32 PimDmaCfgAndUse2MilliSecAdcMaxDmaTrfTi;
  uint32 PimDmaCfgAndUse2MilliSecAdcStrtTi;
  uint32 PimMotAg0ReadPtrRst;
  uint32 PimMotAg0SnsrCfgAdrStord;
  uint32 PimMotAg0TrsmStrt;
  uint32 PimMotAg1ReadPtrRst;
  uint32 PimMotAg1SnsrCfgAdrStord;
  uint32 PimMotAg1TrsmStrt;
  uint32 Pimd2MilliSecAdcActDmaTrfTi;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimDmaCfgAndUse2MilliSecAdcMaxDmaTrfTi = *TSC_CDD_DmaCfgAndUse_Rte_Pim_DmaCfgAndUse2MilliSecAdcMaxDmaTrfTi();
  *TSC_CDD_DmaCfgAndUse_Rte_Pim_DmaCfgAndUse2MilliSecAdcMaxDmaTrfTi() = PimDmaCfgAndUse2MilliSecAdcMaxDmaTrfTi;
  PimDmaCfgAndUse2MilliSecAdcStrtTi = *TSC_CDD_DmaCfgAndUse_Rte_Pim_DmaCfgAndUse2MilliSecAdcStrtTi();
  *TSC_CDD_DmaCfgAndUse_Rte_Pim_DmaCfgAndUse2MilliSecAdcStrtTi() = PimDmaCfgAndUse2MilliSecAdcStrtTi;
  PimMotAg0ReadPtrRst = *TSC_CDD_DmaCfgAndUse_Rte_Pim_MotAg0ReadPtrRst();
  *TSC_CDD_DmaCfgAndUse_Rte_Pim_MotAg0ReadPtrRst() = PimMotAg0ReadPtrRst;
  PimMotAg0SnsrCfgAdrStord = *TSC_CDD_DmaCfgAndUse_Rte_Pim_MotAg0SnsrCfgAdrStord();
  *TSC_CDD_DmaCfgAndUse_Rte_Pim_MotAg0SnsrCfgAdrStord() = PimMotAg0SnsrCfgAdrStord;
  PimMotAg0TrsmStrt = *TSC_CDD_DmaCfgAndUse_Rte_Pim_MotAg0TrsmStrt();
  *TSC_CDD_DmaCfgAndUse_Rte_Pim_MotAg0TrsmStrt() = PimMotAg0TrsmStrt;
  PimMotAg1ReadPtrRst = *TSC_CDD_DmaCfgAndUse_Rte_Pim_MotAg1ReadPtrRst();
  *TSC_CDD_DmaCfgAndUse_Rte_Pim_MotAg1ReadPtrRst() = PimMotAg1ReadPtrRst;
  PimMotAg1SnsrCfgAdrStord = *TSC_CDD_DmaCfgAndUse_Rte_Pim_MotAg1SnsrCfgAdrStord();
  *TSC_CDD_DmaCfgAndUse_Rte_Pim_MotAg1SnsrCfgAdrStord() = PimMotAg1SnsrCfgAdrStord;
  PimMotAg1TrsmStrt = *TSC_CDD_DmaCfgAndUse_Rte_Pim_MotAg1TrsmStrt();
  *TSC_CDD_DmaCfgAndUse_Rte_Pim_MotAg1TrsmStrt() = PimMotAg1TrsmStrt;
  Pimd2MilliSecAdcActDmaTrfTi = *TSC_CDD_DmaCfgAndUse_Rte_Pim_d2MilliSecAdcActDmaTrfTi();
  *TSC_CDD_DmaCfgAndUse_Rte_Pim_d2MilliSecAdcActDmaTrfTi() = Pimd2MilliSecAdcActDmaTrfTi;

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define CDD_DmaCfgAndUse_STOP_SEC_CODE
#include "CDD_DmaCfgAndUse_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


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
