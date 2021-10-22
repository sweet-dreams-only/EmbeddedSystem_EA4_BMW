/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  LrndRackCentr.c
 *        Config:  EPS.dpa
 *     SW-C Type:  LrndRackCentr
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <LrndRackCentr>
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

#include "Rte_LrndRackCentr.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_LrndRackCentr.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"
#include "float.h"

static void LrndRackCentr_TestDefines(void);


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
 * sint16: Integer in interval [-32768...32767] (standard type)
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * NvM_RequestResultType: Enumeration of integer in interval [0...255] with enumerators
 *   NVM_REQ_OK (0U)
 *   NVM_REQ_NOT_OK (1U)
 *   NVM_REQ_PENDING (2U)
 *   NVM_REQ_INTEGRITY_FAILED (3U)
 *   NVM_REQ_BLOCK_SKIPPED (4U)
 *   NVM_REQ_NV_INVALIDATED (5U)
 *   NVM_REQ_CANCELED (6U)
 *   NVM_REQ_REDUNDANCY_FAILED (7U)
 *   NVM_REQ_RESTORED_FROM_ROM (8U)
 *
 * Record Types:
 * =============
 * FilLpRec1: Record with elements
 *   FilSt of type float32
 *   FilGain of type float32
 * LrndRackCentrNvmRec1: Record with elements
 *   TotRackTrvl of type float32
 *   RackCentrMotDeg of type float32
 *   RackCentrMotRev of type sint16
 *   LongTermRackCentrCmpl of type boolean
 *   MotAgVld of type boolean
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   float32 *Rte_Pim_ManLrndRackCentrNegEot(void)
 *   float32 *Rte_Pim_ManLrndRackCentrPosEot(void)
 *   float32 *Rte_Pim_RackCentrPinionAgPrev(void)
 *   uint32 *Rte_Pim_RackCentrMaxTmr(void)
 *   uint32 *Rte_Pim_RackCentrMinTmr(void)
 *   boolean *Rte_Pim_ManLrndRackCentrNegEotVld(void)
 *   boolean *Rte_Pim_ManLrndRackCentrPosEotVld(void)
 *   FilLpRec1 *Rte_Pim_HwAgFil(void)
 *   LrndRackCentrNvmRec1 *Rte_Pim_LrndRackCentr(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_LrndRackCentrConfTrvlThd_Val(void)
 *   float32 Rte_Prm_LrndRackCentrHwAgFilFrq_Val(void)
 *   float32 Rte_Prm_LrndRackCentrMinMaxAdjmtFac_Val(void)
 *   float32 Rte_Prm_LrndRackCentrMotTqThd_Val(void)
 *   float32 Rte_Prm_LrndRackCentrMotVelThd_Val(void)
 *   float32 Rte_Prm_LrndRackCentrRackCentrPosnChgAllwd_Val(void)
 *   float32 Rte_Prm_SysGlbPrmSysKineRat_Val(void)
 *   uint16 Rte_Prm_LrndRackCentrTiThd_Val(void)
 *   boolean Rte_Prm_LrndRackCentrAllwManIniLrng_Logl(void)
 *
 *********************************************************************************************************************/


#define LrndRackCentr_START_SEC_CODE
#include "LrndRackCentr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: LrndRackCentrInit1
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
 *   Std_ReturnType Rte_Read_HwAg_Val(float32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_LongTermRackCentrCmpl_Logl(boolean data)
 *   Std_ReturnType Rte_Write_RackCentrCmpl_Logl(boolean data)
 *   Std_ReturnType Rte_Write_RackCentrMotAgErrPrsnt_Logl(boolean data)
 *   Std_ReturnType Rte_Write_RackCentrMotAgVld_Logl(boolean data)
 *   Std_ReturnType Rte_Write_RackCentrPinionAg_Val(float32 data)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_LrndRackCentrNvm_GetErrorStatus(NvM_RequestResultType *ErrorStatus_Arg)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: LrndRackCentrInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, LrndRackCentr_CODE) LrndRackCentrInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: LrndRackCentrInit1
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  float32 Read_HwAg_Val;

  float32 PimManLrndRackCentrNegEot;
  float32 PimManLrndRackCentrPosEot;
  float32 PimRackCentrPinionAgPrev;
  uint32 PimRackCentrMaxTmr;
  uint32 PimRackCentrMinTmr;
  boolean PimManLrndRackCentrNegEotVld;
  boolean PimManLrndRackCentrPosEotVld;
  FilLpRec1 PimHwAgFil;
  LrndRackCentrNvmRec1 PimLrndRackCentr;

  float32 LrndRackCentrConfTrvlThd_Val_data;
  float32 LrndRackCentrHwAgFilFrq_Val_data;
  float32 LrndRackCentrMinMaxAdjmtFac_Val_data;
  float32 LrndRackCentrMotTqThd_Val_data;
  float32 LrndRackCentrMotVelThd_Val_data;
  float32 LrndRackCentrRackCentrPosnChgAllwd_Val_data;
  float32 SysGlbPrmSysKineRat_Val_data;
  uint16 LrndRackCentrTiThd_Val_data;
  boolean LrndRackCentrAllwManIniLrng_Logl_data;

  NvM_RequestResultType Call_LrndRackCentrNvm_GetErrorStatus_ErrorStatus_Arg = 0U;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimManLrndRackCentrNegEot = *TSC_LrndRackCentr_Rte_Pim_ManLrndRackCentrNegEot();
  *TSC_LrndRackCentr_Rte_Pim_ManLrndRackCentrNegEot() = PimManLrndRackCentrNegEot;
  PimManLrndRackCentrPosEot = *TSC_LrndRackCentr_Rte_Pim_ManLrndRackCentrPosEot();
  *TSC_LrndRackCentr_Rte_Pim_ManLrndRackCentrPosEot() = PimManLrndRackCentrPosEot;
  PimRackCentrPinionAgPrev = *TSC_LrndRackCentr_Rte_Pim_RackCentrPinionAgPrev();
  *TSC_LrndRackCentr_Rte_Pim_RackCentrPinionAgPrev() = PimRackCentrPinionAgPrev;
  PimRackCentrMaxTmr = *TSC_LrndRackCentr_Rte_Pim_RackCentrMaxTmr();
  *TSC_LrndRackCentr_Rte_Pim_RackCentrMaxTmr() = PimRackCentrMaxTmr;
  PimRackCentrMinTmr = *TSC_LrndRackCentr_Rte_Pim_RackCentrMinTmr();
  *TSC_LrndRackCentr_Rte_Pim_RackCentrMinTmr() = PimRackCentrMinTmr;
  PimManLrndRackCentrNegEotVld = *TSC_LrndRackCentr_Rte_Pim_ManLrndRackCentrNegEotVld();
  *TSC_LrndRackCentr_Rte_Pim_ManLrndRackCentrNegEotVld() = PimManLrndRackCentrNegEotVld;
  PimManLrndRackCentrPosEotVld = *TSC_LrndRackCentr_Rte_Pim_ManLrndRackCentrPosEotVld();
  *TSC_LrndRackCentr_Rte_Pim_ManLrndRackCentrPosEotVld() = PimManLrndRackCentrPosEotVld;
  PimHwAgFil = *TSC_LrndRackCentr_Rte_Pim_HwAgFil();
  *TSC_LrndRackCentr_Rte_Pim_HwAgFil() = PimHwAgFil;
  PimLrndRackCentr = *TSC_LrndRackCentr_Rte_Pim_LrndRackCentr();
  *TSC_LrndRackCentr_Rte_Pim_LrndRackCentr() = PimLrndRackCentr;

  LrndRackCentrConfTrvlThd_Val_data = TSC_LrndRackCentr_Rte_Prm_LrndRackCentrConfTrvlThd_Val();
  LrndRackCentrHwAgFilFrq_Val_data = TSC_LrndRackCentr_Rte_Prm_LrndRackCentrHwAgFilFrq_Val();
  LrndRackCentrMinMaxAdjmtFac_Val_data = TSC_LrndRackCentr_Rte_Prm_LrndRackCentrMinMaxAdjmtFac_Val();
  LrndRackCentrMotTqThd_Val_data = TSC_LrndRackCentr_Rte_Prm_LrndRackCentrMotTqThd_Val();
  LrndRackCentrMotVelThd_Val_data = TSC_LrndRackCentr_Rte_Prm_LrndRackCentrMotVelThd_Val();
  LrndRackCentrRackCentrPosnChgAllwd_Val_data = TSC_LrndRackCentr_Rte_Prm_LrndRackCentrRackCentrPosnChgAllwd_Val();
  SysGlbPrmSysKineRat_Val_data = TSC_LrndRackCentr_Rte_Prm_SysGlbPrmSysKineRat_Val();
  LrndRackCentrTiThd_Val_data = TSC_LrndRackCentr_Rte_Prm_LrndRackCentrTiThd_Val();
  LrndRackCentrAllwManIniLrng_Logl_data = TSC_LrndRackCentr_Rte_Prm_LrndRackCentrAllwManIniLrng_Logl();

  fct_status = TSC_LrndRackCentr_Rte_Read_HwAg_Val(&Read_HwAg_Val);
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

  fct_status = TSC_LrndRackCentr_Rte_Write_LongTermRackCentrCmpl_Logl(Rte_InitValue_LongTermRackCentrCmpl_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_LrndRackCentr_Rte_Write_RackCentrCmpl_Logl(Rte_InitValue_RackCentrCmpl_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_LrndRackCentr_Rte_Write_RackCentrMotAgErrPrsnt_Logl(Rte_InitValue_RackCentrMotAgErrPrsnt_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_LrndRackCentr_Rte_Write_RackCentrMotAgVld_Logl(Rte_InitValue_RackCentrMotAgVld_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_LrndRackCentr_Rte_Write_RackCentrPinionAg_Val(Rte_InitValue_RackCentrPinionAg_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_LrndRackCentr_Rte_Call_LrndRackCentrNvm_GetErrorStatus(&Call_LrndRackCentrNvm_GetErrorStatus_ErrorStatus_Arg);
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

  LrndRackCentr_TestDefines();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: LrndRackCentrPer1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 4ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_HwAg_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotTqCmd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotVelCrf_Val(float32 *data)
 *   Std_ReturnType Rte_Read_PinionCentrLrnEna_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_PinionCentrLrnHwCentr_Val(float32 *data)
 *   Std_ReturnType Rte_Read_PinionCentrLrnHwTrvl_Val(float32 *data)
 *   Std_ReturnType Rte_Read_PinionCentrLrnSt_Val(uint8 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_LongTermRackCentrCmpl_Logl(boolean data)
 *   Std_ReturnType Rte_Write_RackCentrCmpl_Logl(boolean data)
 *   Std_ReturnType Rte_Write_RackCentrMotAgVld_Logl(boolean data)
 *   Std_ReturnType Rte_Write_RackCentrPinionAg_Val(float32 data)
 *   Std_ReturnType Rte_Write_TotRackTrvl_Val(float32 data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_GetRefTmr100MicroSec32bit_Oper(uint32 *RefTmr_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_LrndRackCentrNvm_SetRamBlockStatus(boolean RamBlockStatus_Arg)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: LrndRackCentrPer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, LrndRackCentr_CODE) LrndRackCentrPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: LrndRackCentrPer1
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  float32 Read_HwAg_Val;
  float32 Read_MotTqCmd_Val;
  float32 Read_MotVelCrf_Val;
  boolean Read_PinionCentrLrnEna_Logl;
  float32 Read_PinionCentrLrnHwCentr_Val;
  float32 Read_PinionCentrLrnHwTrvl_Val;
  uint8 Read_PinionCentrLrnSt_Val;

  float32 PimManLrndRackCentrNegEot;
  float32 PimManLrndRackCentrPosEot;
  float32 PimRackCentrPinionAgPrev;
  uint32 PimRackCentrMaxTmr;
  uint32 PimRackCentrMinTmr;
  boolean PimManLrndRackCentrNegEotVld;
  boolean PimManLrndRackCentrPosEotVld;
  FilLpRec1 PimHwAgFil;
  LrndRackCentrNvmRec1 PimLrndRackCentr;

  float32 LrndRackCentrConfTrvlThd_Val_data;
  float32 LrndRackCentrHwAgFilFrq_Val_data;
  float32 LrndRackCentrMinMaxAdjmtFac_Val_data;
  float32 LrndRackCentrMotTqThd_Val_data;
  float32 LrndRackCentrMotVelThd_Val_data;
  float32 LrndRackCentrRackCentrPosnChgAllwd_Val_data;
  float32 SysGlbPrmSysKineRat_Val_data;
  uint16 LrndRackCentrTiThd_Val_data;
  boolean LrndRackCentrAllwManIniLrng_Logl_data;

  uint32 Call_GetRefTmr100MicroSec32bit_Oper_RefTmr_Arg = 0U;
  uint32 Call_GetTiSpan100MicroSec32bit_Oper_TiSpan_Arg = 0U;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimManLrndRackCentrNegEot = *TSC_LrndRackCentr_Rte_Pim_ManLrndRackCentrNegEot();
  *TSC_LrndRackCentr_Rte_Pim_ManLrndRackCentrNegEot() = PimManLrndRackCentrNegEot;
  PimManLrndRackCentrPosEot = *TSC_LrndRackCentr_Rte_Pim_ManLrndRackCentrPosEot();
  *TSC_LrndRackCentr_Rte_Pim_ManLrndRackCentrPosEot() = PimManLrndRackCentrPosEot;
  PimRackCentrPinionAgPrev = *TSC_LrndRackCentr_Rte_Pim_RackCentrPinionAgPrev();
  *TSC_LrndRackCentr_Rte_Pim_RackCentrPinionAgPrev() = PimRackCentrPinionAgPrev;
  PimRackCentrMaxTmr = *TSC_LrndRackCentr_Rte_Pim_RackCentrMaxTmr();
  *TSC_LrndRackCentr_Rte_Pim_RackCentrMaxTmr() = PimRackCentrMaxTmr;
  PimRackCentrMinTmr = *TSC_LrndRackCentr_Rte_Pim_RackCentrMinTmr();
  *TSC_LrndRackCentr_Rte_Pim_RackCentrMinTmr() = PimRackCentrMinTmr;
  PimManLrndRackCentrNegEotVld = *TSC_LrndRackCentr_Rte_Pim_ManLrndRackCentrNegEotVld();
  *TSC_LrndRackCentr_Rte_Pim_ManLrndRackCentrNegEotVld() = PimManLrndRackCentrNegEotVld;
  PimManLrndRackCentrPosEotVld = *TSC_LrndRackCentr_Rte_Pim_ManLrndRackCentrPosEotVld();
  *TSC_LrndRackCentr_Rte_Pim_ManLrndRackCentrPosEotVld() = PimManLrndRackCentrPosEotVld;
  PimHwAgFil = *TSC_LrndRackCentr_Rte_Pim_HwAgFil();
  *TSC_LrndRackCentr_Rte_Pim_HwAgFil() = PimHwAgFil;
  PimLrndRackCentr = *TSC_LrndRackCentr_Rte_Pim_LrndRackCentr();
  *TSC_LrndRackCentr_Rte_Pim_LrndRackCentr() = PimLrndRackCentr;

  LrndRackCentrConfTrvlThd_Val_data = TSC_LrndRackCentr_Rte_Prm_LrndRackCentrConfTrvlThd_Val();
  LrndRackCentrHwAgFilFrq_Val_data = TSC_LrndRackCentr_Rte_Prm_LrndRackCentrHwAgFilFrq_Val();
  LrndRackCentrMinMaxAdjmtFac_Val_data = TSC_LrndRackCentr_Rte_Prm_LrndRackCentrMinMaxAdjmtFac_Val();
  LrndRackCentrMotTqThd_Val_data = TSC_LrndRackCentr_Rte_Prm_LrndRackCentrMotTqThd_Val();
  LrndRackCentrMotVelThd_Val_data = TSC_LrndRackCentr_Rte_Prm_LrndRackCentrMotVelThd_Val();
  LrndRackCentrRackCentrPosnChgAllwd_Val_data = TSC_LrndRackCentr_Rte_Prm_LrndRackCentrRackCentrPosnChgAllwd_Val();
  SysGlbPrmSysKineRat_Val_data = TSC_LrndRackCentr_Rte_Prm_SysGlbPrmSysKineRat_Val();
  LrndRackCentrTiThd_Val_data = TSC_LrndRackCentr_Rte_Prm_LrndRackCentrTiThd_Val();
  LrndRackCentrAllwManIniLrng_Logl_data = TSC_LrndRackCentr_Rte_Prm_LrndRackCentrAllwManIniLrng_Logl();

  fct_status = TSC_LrndRackCentr_Rte_Read_HwAg_Val(&Read_HwAg_Val);
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

  fct_status = TSC_LrndRackCentr_Rte_Read_MotTqCmd_Val(&Read_MotTqCmd_Val);
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

  fct_status = TSC_LrndRackCentr_Rte_Read_MotVelCrf_Val(&Read_MotVelCrf_Val);
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

  fct_status = TSC_LrndRackCentr_Rte_Read_PinionCentrLrnEna_Logl(&Read_PinionCentrLrnEna_Logl);
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

  fct_status = TSC_LrndRackCentr_Rte_Read_PinionCentrLrnHwCentr_Val(&Read_PinionCentrLrnHwCentr_Val);
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

  fct_status = TSC_LrndRackCentr_Rte_Read_PinionCentrLrnHwTrvl_Val(&Read_PinionCentrLrnHwTrvl_Val);
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

  fct_status = TSC_LrndRackCentr_Rte_Read_PinionCentrLrnSt_Val(&Read_PinionCentrLrnSt_Val);
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

  fct_status = TSC_LrndRackCentr_Rte_Write_LongTermRackCentrCmpl_Logl(Rte_InitValue_LongTermRackCentrCmpl_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_LrndRackCentr_Rte_Write_RackCentrCmpl_Logl(Rte_InitValue_RackCentrCmpl_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_LrndRackCentr_Rte_Write_RackCentrMotAgVld_Logl(Rte_InitValue_RackCentrMotAgVld_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_LrndRackCentr_Rte_Write_RackCentrPinionAg_Val(Rte_InitValue_RackCentrPinionAg_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_LrndRackCentr_Rte_Write_TotRackTrvl_Val(Rte_InitValue_TotRackTrvl_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_LrndRackCentr_Rte_Call_GetRefTmr100MicroSec32bit_Oper(&Call_GetRefTmr100MicroSec32bit_Oper_RefTmr_Arg);
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

  fct_status = TSC_LrndRackCentr_Rte_Call_GetTiSpan100MicroSec32bit_Oper(0U, &Call_GetTiSpan100MicroSec32bit_Oper_TiSpan_Arg);
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

  fct_status = TSC_LrndRackCentr_Rte_Call_LrndRackCentrNvm_SetRamBlockStatus(FALSE);
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


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RstRackCentrMotAg_Oper
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <RstRackCentrMotAg>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_RackCentrMotAgVld_Logl(boolean data)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_LrndRackCentrNvm_SetRamBlockStatus(boolean RamBlockStatus_Arg)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void RstRackCentrMotAg_Oper(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RstRackCentrMotAg_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, LrndRackCentr_CODE) RstRackCentrMotAg_Oper(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RstRackCentrMotAg_Oper
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  float32 PimManLrndRackCentrNegEot;
  float32 PimManLrndRackCentrPosEot;
  float32 PimRackCentrPinionAgPrev;
  uint32 PimRackCentrMaxTmr;
  uint32 PimRackCentrMinTmr;
  boolean PimManLrndRackCentrNegEotVld;
  boolean PimManLrndRackCentrPosEotVld;
  FilLpRec1 PimHwAgFil;
  LrndRackCentrNvmRec1 PimLrndRackCentr;

  float32 LrndRackCentrConfTrvlThd_Val_data;
  float32 LrndRackCentrHwAgFilFrq_Val_data;
  float32 LrndRackCentrMinMaxAdjmtFac_Val_data;
  float32 LrndRackCentrMotTqThd_Val_data;
  float32 LrndRackCentrMotVelThd_Val_data;
  float32 LrndRackCentrRackCentrPosnChgAllwd_Val_data;
  float32 SysGlbPrmSysKineRat_Val_data;
  uint16 LrndRackCentrTiThd_Val_data;
  boolean LrndRackCentrAllwManIniLrng_Logl_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimManLrndRackCentrNegEot = *TSC_LrndRackCentr_Rte_Pim_ManLrndRackCentrNegEot();
  *TSC_LrndRackCentr_Rte_Pim_ManLrndRackCentrNegEot() = PimManLrndRackCentrNegEot;
  PimManLrndRackCentrPosEot = *TSC_LrndRackCentr_Rte_Pim_ManLrndRackCentrPosEot();
  *TSC_LrndRackCentr_Rte_Pim_ManLrndRackCentrPosEot() = PimManLrndRackCentrPosEot;
  PimRackCentrPinionAgPrev = *TSC_LrndRackCentr_Rte_Pim_RackCentrPinionAgPrev();
  *TSC_LrndRackCentr_Rte_Pim_RackCentrPinionAgPrev() = PimRackCentrPinionAgPrev;
  PimRackCentrMaxTmr = *TSC_LrndRackCentr_Rte_Pim_RackCentrMaxTmr();
  *TSC_LrndRackCentr_Rte_Pim_RackCentrMaxTmr() = PimRackCentrMaxTmr;
  PimRackCentrMinTmr = *TSC_LrndRackCentr_Rte_Pim_RackCentrMinTmr();
  *TSC_LrndRackCentr_Rte_Pim_RackCentrMinTmr() = PimRackCentrMinTmr;
  PimManLrndRackCentrNegEotVld = *TSC_LrndRackCentr_Rte_Pim_ManLrndRackCentrNegEotVld();
  *TSC_LrndRackCentr_Rte_Pim_ManLrndRackCentrNegEotVld() = PimManLrndRackCentrNegEotVld;
  PimManLrndRackCentrPosEotVld = *TSC_LrndRackCentr_Rte_Pim_ManLrndRackCentrPosEotVld();
  *TSC_LrndRackCentr_Rte_Pim_ManLrndRackCentrPosEotVld() = PimManLrndRackCentrPosEotVld;
  PimHwAgFil = *TSC_LrndRackCentr_Rte_Pim_HwAgFil();
  *TSC_LrndRackCentr_Rte_Pim_HwAgFil() = PimHwAgFil;
  PimLrndRackCentr = *TSC_LrndRackCentr_Rte_Pim_LrndRackCentr();
  *TSC_LrndRackCentr_Rte_Pim_LrndRackCentr() = PimLrndRackCentr;

  LrndRackCentrConfTrvlThd_Val_data = TSC_LrndRackCentr_Rte_Prm_LrndRackCentrConfTrvlThd_Val();
  LrndRackCentrHwAgFilFrq_Val_data = TSC_LrndRackCentr_Rte_Prm_LrndRackCentrHwAgFilFrq_Val();
  LrndRackCentrMinMaxAdjmtFac_Val_data = TSC_LrndRackCentr_Rte_Prm_LrndRackCentrMinMaxAdjmtFac_Val();
  LrndRackCentrMotTqThd_Val_data = TSC_LrndRackCentr_Rte_Prm_LrndRackCentrMotTqThd_Val();
  LrndRackCentrMotVelThd_Val_data = TSC_LrndRackCentr_Rte_Prm_LrndRackCentrMotVelThd_Val();
  LrndRackCentrRackCentrPosnChgAllwd_Val_data = TSC_LrndRackCentr_Rte_Prm_LrndRackCentrRackCentrPosnChgAllwd_Val();
  SysGlbPrmSysKineRat_Val_data = TSC_LrndRackCentr_Rte_Prm_SysGlbPrmSysKineRat_Val();
  LrndRackCentrTiThd_Val_data = TSC_LrndRackCentr_Rte_Prm_LrndRackCentrTiThd_Val();
  LrndRackCentrAllwManIniLrng_Logl_data = TSC_LrndRackCentr_Rte_Prm_LrndRackCentrAllwManIniLrng_Logl();

  fct_status = TSC_LrndRackCentr_Rte_Write_RackCentrMotAgVld_Logl(Rte_InitValue_RackCentrMotAgVld_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_LrndRackCentr_Rte_Call_LrndRackCentrNvm_SetRamBlockStatus(FALSE);
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


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RstRackCentrMotRev_Oper
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <RstRackCentrMotRev>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_HwAg_Val(float32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_LongTermRackCentrCmpl_Logl(boolean data)
 *   Std_ReturnType Rte_Write_RackCentrCmpl_Logl(boolean data)
 *   Std_ReturnType Rte_Write_RackCentrPinionAg_Val(float32 data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_GetRefTmr100MicroSec32bit_Oper(uint32 *RefTmr_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_LrndRackCentrNvm_SetRamBlockStatus(boolean RamBlockStatus_Arg)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void RstRackCentrMotRev_Oper(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RstRackCentrMotRev_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, LrndRackCentr_CODE) RstRackCentrMotRev_Oper(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RstRackCentrMotRev_Oper
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  float32 Read_HwAg_Val;

  float32 PimManLrndRackCentrNegEot;
  float32 PimManLrndRackCentrPosEot;
  float32 PimRackCentrPinionAgPrev;
  uint32 PimRackCentrMaxTmr;
  uint32 PimRackCentrMinTmr;
  boolean PimManLrndRackCentrNegEotVld;
  boolean PimManLrndRackCentrPosEotVld;
  FilLpRec1 PimHwAgFil;
  LrndRackCentrNvmRec1 PimLrndRackCentr;

  float32 LrndRackCentrConfTrvlThd_Val_data;
  float32 LrndRackCentrHwAgFilFrq_Val_data;
  float32 LrndRackCentrMinMaxAdjmtFac_Val_data;
  float32 LrndRackCentrMotTqThd_Val_data;
  float32 LrndRackCentrMotVelThd_Val_data;
  float32 LrndRackCentrRackCentrPosnChgAllwd_Val_data;
  float32 SysGlbPrmSysKineRat_Val_data;
  uint16 LrndRackCentrTiThd_Val_data;
  boolean LrndRackCentrAllwManIniLrng_Logl_data;

  uint32 Call_GetRefTmr100MicroSec32bit_Oper_RefTmr_Arg = 0U;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimManLrndRackCentrNegEot = *TSC_LrndRackCentr_Rte_Pim_ManLrndRackCentrNegEot();
  *TSC_LrndRackCentr_Rte_Pim_ManLrndRackCentrNegEot() = PimManLrndRackCentrNegEot;
  PimManLrndRackCentrPosEot = *TSC_LrndRackCentr_Rte_Pim_ManLrndRackCentrPosEot();
  *TSC_LrndRackCentr_Rte_Pim_ManLrndRackCentrPosEot() = PimManLrndRackCentrPosEot;
  PimRackCentrPinionAgPrev = *TSC_LrndRackCentr_Rte_Pim_RackCentrPinionAgPrev();
  *TSC_LrndRackCentr_Rte_Pim_RackCentrPinionAgPrev() = PimRackCentrPinionAgPrev;
  PimRackCentrMaxTmr = *TSC_LrndRackCentr_Rte_Pim_RackCentrMaxTmr();
  *TSC_LrndRackCentr_Rte_Pim_RackCentrMaxTmr() = PimRackCentrMaxTmr;
  PimRackCentrMinTmr = *TSC_LrndRackCentr_Rte_Pim_RackCentrMinTmr();
  *TSC_LrndRackCentr_Rte_Pim_RackCentrMinTmr() = PimRackCentrMinTmr;
  PimManLrndRackCentrNegEotVld = *TSC_LrndRackCentr_Rte_Pim_ManLrndRackCentrNegEotVld();
  *TSC_LrndRackCentr_Rte_Pim_ManLrndRackCentrNegEotVld() = PimManLrndRackCentrNegEotVld;
  PimManLrndRackCentrPosEotVld = *TSC_LrndRackCentr_Rte_Pim_ManLrndRackCentrPosEotVld();
  *TSC_LrndRackCentr_Rte_Pim_ManLrndRackCentrPosEotVld() = PimManLrndRackCentrPosEotVld;
  PimHwAgFil = *TSC_LrndRackCentr_Rte_Pim_HwAgFil();
  *TSC_LrndRackCentr_Rte_Pim_HwAgFil() = PimHwAgFil;
  PimLrndRackCentr = *TSC_LrndRackCentr_Rte_Pim_LrndRackCentr();
  *TSC_LrndRackCentr_Rte_Pim_LrndRackCentr() = PimLrndRackCentr;

  LrndRackCentrConfTrvlThd_Val_data = TSC_LrndRackCentr_Rte_Prm_LrndRackCentrConfTrvlThd_Val();
  LrndRackCentrHwAgFilFrq_Val_data = TSC_LrndRackCentr_Rte_Prm_LrndRackCentrHwAgFilFrq_Val();
  LrndRackCentrMinMaxAdjmtFac_Val_data = TSC_LrndRackCentr_Rte_Prm_LrndRackCentrMinMaxAdjmtFac_Val();
  LrndRackCentrMotTqThd_Val_data = TSC_LrndRackCentr_Rte_Prm_LrndRackCentrMotTqThd_Val();
  LrndRackCentrMotVelThd_Val_data = TSC_LrndRackCentr_Rte_Prm_LrndRackCentrMotVelThd_Val();
  LrndRackCentrRackCentrPosnChgAllwd_Val_data = TSC_LrndRackCentr_Rte_Prm_LrndRackCentrRackCentrPosnChgAllwd_Val();
  SysGlbPrmSysKineRat_Val_data = TSC_LrndRackCentr_Rte_Prm_SysGlbPrmSysKineRat_Val();
  LrndRackCentrTiThd_Val_data = TSC_LrndRackCentr_Rte_Prm_LrndRackCentrTiThd_Val();
  LrndRackCentrAllwManIniLrng_Logl_data = TSC_LrndRackCentr_Rte_Prm_LrndRackCentrAllwManIniLrng_Logl();

  fct_status = TSC_LrndRackCentr_Rte_Read_HwAg_Val(&Read_HwAg_Val);
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

  fct_status = TSC_LrndRackCentr_Rte_Write_LongTermRackCentrCmpl_Logl(Rte_InitValue_LongTermRackCentrCmpl_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_LrndRackCentr_Rte_Write_RackCentrCmpl_Logl(Rte_InitValue_RackCentrCmpl_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_LrndRackCentr_Rte_Write_RackCentrPinionAg_Val(Rte_InitValue_RackCentrPinionAg_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_LrndRackCentr_Rte_Call_GetRefTmr100MicroSec32bit_Oper(&Call_GetRefTmr100MicroSec32bit_Oper_RefTmr_Arg);
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

  fct_status = TSC_LrndRackCentr_Rte_Call_LrndRackCentrNvm_SetRamBlockStatus(FALSE);
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


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define LrndRackCentr_STOP_SEC_CODE
#include "LrndRackCentr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void LrndRackCentr_TestDefines(void)
{
  /* Enumeration Data Types */

  NvM_RequestResultType Test_NvM_RequestResultType_V_1 = NVM_REQ_OK;
  NvM_RequestResultType Test_NvM_RequestResultType_V_2 = NVM_REQ_NOT_OK;
  NvM_RequestResultType Test_NvM_RequestResultType_V_3 = NVM_REQ_PENDING;
  NvM_RequestResultType Test_NvM_RequestResultType_V_4 = NVM_REQ_INTEGRITY_FAILED;
  NvM_RequestResultType Test_NvM_RequestResultType_V_5 = NVM_REQ_BLOCK_SKIPPED;
  NvM_RequestResultType Test_NvM_RequestResultType_V_6 = NVM_REQ_NV_INVALIDATED;
  NvM_RequestResultType Test_NvM_RequestResultType_V_7 = NVM_REQ_CANCELED;
  NvM_RequestResultType Test_NvM_RequestResultType_V_8 = NVM_REQ_REDUNDANCY_FAILED;
  NvM_RequestResultType Test_NvM_RequestResultType_V_9 = NVM_REQ_RESTORED_FROM_ROM;
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
