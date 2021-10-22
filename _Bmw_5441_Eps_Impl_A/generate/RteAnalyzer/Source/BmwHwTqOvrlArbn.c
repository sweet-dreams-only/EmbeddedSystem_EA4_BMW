/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  BmwHwTqOvrlArbn.c
 *        Config:  EPS.dpa
 *     SW-C Type:  BmwHwTqOvrlArbn
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <BmwHwTqOvrlArbn>
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
 * BmwOvrlCmdQlfr1
 *   
 *
 * DrvgDynIfSt1
 *   
 *
 * u4p12
 *   
 *
 * u9p7
 *   
 *
 *********************************************************************************************************************/

#include "Rte_BmwHwTqOvrlArbn.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_BmwHwTqOvrlArbn.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"
#include "float.h"

static void BmwHwTqOvrlArbn_TestDefines(void);


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
 * u4p12: Integer in interval [0...65535]
 * u9p7: Integer in interval [0...65535]
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * BmwOvrlCmdQlfr1: Enumeration of integer in interval [0...255] with enumerators
 *   BMWOVRLCMDQLFR_IMPLSP (2U)
 *   BMWOVRLCMDQLFR_SPNOTAVL (7U)
 *   BMWOVRLCMDQLFR_STBDONOTCNVSP (14U)
 *   BMWOVRLCMDQLFR_INVLDSIG (15U)
 * DrvgDynIfSt1: Enumeration of integer in interval [0...255] with enumerators
 *   DRVGDYNIFST_IFAVLRDYFOROPERWOADDLDAMPG (32U)
 *   DRVGDYNIFST_IFACTVADDLDAMPGNOTAVL (33U)
 *   DRVGDYNIFST_IFAVLRDYFOROPERADDLDAMPG (34U)
 *   DRVGDYNIFST_IFACTVADDLDAMPGAVL (35U)
 *   DRVGDYNIFST_SRVNOTAVLERR (96U)
 *   DRVGDYNIFST_IFINID (128U)
 *   DRVGDYNIFST_SRVNOTAVLSTBPMA (224U)
 *   DRVGDYNIFST_SRVNOTAVLSTBEPSSTS (225U)
 *   DRVGDYNIFST_INVLDSIG (255U)
 *
 * Array Types:
 * ============
 * Ary1D_u4p12_6: Array with 6 element(s) of type u4p12
 * Ary1D_u9p7_6: Array with 6 element(s) of type u9p7
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   float32 *Rte_Pim_ArbdHwTqOvrlLtch(void)
 *   float32 *Rte_Pim_HwTqOvrlScaFacStVari(void)
 *   float32 *Rte_Pim_PrevArbdHwTqOvrl(void)
 *   uint32 *Rte_Pim_FctlErrTmr(void)
 *   boolean *Rte_Pim_FctlErrActv(void)
 *   boolean *Rte_Pim_PrevFctlErr(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_BmwHwTqOvrlArbnCmdErrThd_Val(void)
 *   float32 Rte_Prm_BmwHwTqOvrlArbnOutpTqCmdLim_Val(void)
 *   float32 Rte_Prm_BmwHwTqOvrlArbnRampRate_Val(void)
 *   uint16 Rte_Prm_BmwHwTqOvrlArbnRefTiThd_Val(void)
 *   u4p12 *Rte_Prm_BmwHwTqOvrlArbnHwTqThdY_Ary1D(void)
 *     Returnvalue: u4p12* is of type Ary1D_u4p12_6
 *   u9p7 *Rte_Prm_BmwHwTqOvrlArbnVehSpdX_Ary1D(void)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_6
 *
 *********************************************************************************************************************/


#define BmwHwTqOvrlArbn_START_SEC_CODE
#include "BmwHwTqOvrlArbn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwHwTqOvrlArbnInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwHwTqOvrlArbnInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwHwTqOvrlArbn_CODE) BmwHwTqOvrlArbnInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwHwTqOvrlArbnInit1
 *********************************************************************************************************************/

  float32 PimArbdHwTqOvrlLtch;
  float32 PimHwTqOvrlScaFacStVari;
  float32 PimPrevArbdHwTqOvrl;
  uint32 PimFctlErrTmr;
  boolean PimFctlErrActv;
  boolean PimPrevFctlErr;

  float32 BmwHwTqOvrlArbnCmdErrThd_Val_data;
  float32 BmwHwTqOvrlArbnOutpTqCmdLim_Val_data;
  float32 BmwHwTqOvrlArbnRampRate_Val_data;
  uint16 BmwHwTqOvrlArbnRefTiThd_Val_data;
  Ary1D_u4p12_6 BmwHwTqOvrlArbnHwTqThdY_Ary1D_data;
  Ary1D_u9p7_6 BmwHwTqOvrlArbnVehSpdX_Ary1D_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimArbdHwTqOvrlLtch = *TSC_BmwHwTqOvrlArbn_Rte_Pim_ArbdHwTqOvrlLtch();
  *TSC_BmwHwTqOvrlArbn_Rte_Pim_ArbdHwTqOvrlLtch() = PimArbdHwTqOvrlLtch;
  PimHwTqOvrlScaFacStVari = *TSC_BmwHwTqOvrlArbn_Rte_Pim_HwTqOvrlScaFacStVari();
  *TSC_BmwHwTqOvrlArbn_Rte_Pim_HwTqOvrlScaFacStVari() = PimHwTqOvrlScaFacStVari;
  PimPrevArbdHwTqOvrl = *TSC_BmwHwTqOvrlArbn_Rte_Pim_PrevArbdHwTqOvrl();
  *TSC_BmwHwTqOvrlArbn_Rte_Pim_PrevArbdHwTqOvrl() = PimPrevArbdHwTqOvrl;
  PimFctlErrTmr = *TSC_BmwHwTqOvrlArbn_Rte_Pim_FctlErrTmr();
  *TSC_BmwHwTqOvrlArbn_Rte_Pim_FctlErrTmr() = PimFctlErrTmr;
  PimFctlErrActv = *TSC_BmwHwTqOvrlArbn_Rte_Pim_FctlErrActv();
  *TSC_BmwHwTqOvrlArbn_Rte_Pim_FctlErrActv() = PimFctlErrActv;
  PimPrevFctlErr = *TSC_BmwHwTqOvrlArbn_Rte_Pim_PrevFctlErr();
  *TSC_BmwHwTqOvrlArbn_Rte_Pim_PrevFctlErr() = PimPrevFctlErr;

  BmwHwTqOvrlArbnCmdErrThd_Val_data = TSC_BmwHwTqOvrlArbn_Rte_Prm_BmwHwTqOvrlArbnCmdErrThd_Val();
  BmwHwTqOvrlArbnOutpTqCmdLim_Val_data = TSC_BmwHwTqOvrlArbn_Rte_Prm_BmwHwTqOvrlArbnOutpTqCmdLim_Val();
  BmwHwTqOvrlArbnRampRate_Val_data = TSC_BmwHwTqOvrlArbn_Rte_Prm_BmwHwTqOvrlArbnRampRate_Val();
  BmwHwTqOvrlArbnRefTiThd_Val_data = TSC_BmwHwTqOvrlArbn_Rte_Prm_BmwHwTqOvrlArbnRefTiThd_Val();
  (void)memcpy(BmwHwTqOvrlArbnHwTqThdY_Ary1D_data, TSC_BmwHwTqOvrlArbn_Rte_Prm_BmwHwTqOvrlArbnHwTqThdY_Ary1D(), sizeof(Ary1D_u4p12_6));
  (void)memcpy(BmwHwTqOvrlArbnVehSpdX_Ary1D_data, TSC_BmwHwTqOvrlArbn_Rte_Prm_BmwHwTqOvrlArbnVehSpdX_Ary1D(), sizeof(Ary1D_u9p7_6));

  BmwHwTqOvrlArbn_TestDefines();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwHwTqOvrlArbnPer1
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
 *   Std_ReturnType Rte_Read_BmwDrvgDynErrIfActv_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_BmwTarHwTqOvrl_Val(float32 *data)
 *   Std_ReturnType Rte_Read_BmwTarHwTqOvrlQlfr_Val(BmwOvrlCmdQlfr1 *data)
 *   Std_ReturnType Rte_Read_DrvgDynIfSt_Val(DrvgDynIfSt1 *data)
 *   Std_ReturnType Rte_Read_HwTqOvrlCmdEna_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_VehSpd_Val(float32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_HwTqCmdOvrl_Val(float32 data)
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
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwHwTqOvrlArbnPer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwHwTqOvrlArbn_CODE) BmwHwTqOvrlArbnPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwHwTqOvrlArbnPer1
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  boolean Read_BmwDrvgDynErrIfActv_Logl;
  float32 Read_BmwTarHwTqOvrl_Val;
  BmwOvrlCmdQlfr1 Read_BmwTarHwTqOvrlQlfr_Val;
  DrvgDynIfSt1 Read_DrvgDynIfSt_Val;
  boolean Read_HwTqOvrlCmdEna_Logl;
  float32 Read_VehSpd_Val;

  float32 PimArbdHwTqOvrlLtch;
  float32 PimHwTqOvrlScaFacStVari;
  float32 PimPrevArbdHwTqOvrl;
  uint32 PimFctlErrTmr;
  boolean PimFctlErrActv;
  boolean PimPrevFctlErr;

  float32 BmwHwTqOvrlArbnCmdErrThd_Val_data;
  float32 BmwHwTqOvrlArbnOutpTqCmdLim_Val_data;
  float32 BmwHwTqOvrlArbnRampRate_Val_data;
  uint16 BmwHwTqOvrlArbnRefTiThd_Val_data;
  Ary1D_u4p12_6 BmwHwTqOvrlArbnHwTqThdY_Ary1D_data;
  Ary1D_u9p7_6 BmwHwTqOvrlArbnVehSpdX_Ary1D_data;

  uint32 Call_GetRefTmr100MicroSec32bit_Oper_RefTmr_Arg = 0U;
  uint32 Call_GetTiSpan100MicroSec32bit_Oper_TiSpan_Arg = 0U;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimArbdHwTqOvrlLtch = *TSC_BmwHwTqOvrlArbn_Rte_Pim_ArbdHwTqOvrlLtch();
  *TSC_BmwHwTqOvrlArbn_Rte_Pim_ArbdHwTqOvrlLtch() = PimArbdHwTqOvrlLtch;
  PimHwTqOvrlScaFacStVari = *TSC_BmwHwTqOvrlArbn_Rte_Pim_HwTqOvrlScaFacStVari();
  *TSC_BmwHwTqOvrlArbn_Rte_Pim_HwTqOvrlScaFacStVari() = PimHwTqOvrlScaFacStVari;
  PimPrevArbdHwTqOvrl = *TSC_BmwHwTqOvrlArbn_Rte_Pim_PrevArbdHwTqOvrl();
  *TSC_BmwHwTqOvrlArbn_Rte_Pim_PrevArbdHwTqOvrl() = PimPrevArbdHwTqOvrl;
  PimFctlErrTmr = *TSC_BmwHwTqOvrlArbn_Rte_Pim_FctlErrTmr();
  *TSC_BmwHwTqOvrlArbn_Rte_Pim_FctlErrTmr() = PimFctlErrTmr;
  PimFctlErrActv = *TSC_BmwHwTqOvrlArbn_Rte_Pim_FctlErrActv();
  *TSC_BmwHwTqOvrlArbn_Rte_Pim_FctlErrActv() = PimFctlErrActv;
  PimPrevFctlErr = *TSC_BmwHwTqOvrlArbn_Rte_Pim_PrevFctlErr();
  *TSC_BmwHwTqOvrlArbn_Rte_Pim_PrevFctlErr() = PimPrevFctlErr;

  BmwHwTqOvrlArbnCmdErrThd_Val_data = TSC_BmwHwTqOvrlArbn_Rte_Prm_BmwHwTqOvrlArbnCmdErrThd_Val();
  BmwHwTqOvrlArbnOutpTqCmdLim_Val_data = TSC_BmwHwTqOvrlArbn_Rte_Prm_BmwHwTqOvrlArbnOutpTqCmdLim_Val();
  BmwHwTqOvrlArbnRampRate_Val_data = TSC_BmwHwTqOvrlArbn_Rte_Prm_BmwHwTqOvrlArbnRampRate_Val();
  BmwHwTqOvrlArbnRefTiThd_Val_data = TSC_BmwHwTqOvrlArbn_Rte_Prm_BmwHwTqOvrlArbnRefTiThd_Val();
  (void)memcpy(BmwHwTqOvrlArbnHwTqThdY_Ary1D_data, TSC_BmwHwTqOvrlArbn_Rte_Prm_BmwHwTqOvrlArbnHwTqThdY_Ary1D(), sizeof(Ary1D_u4p12_6));
  (void)memcpy(BmwHwTqOvrlArbnVehSpdX_Ary1D_data, TSC_BmwHwTqOvrlArbn_Rte_Prm_BmwHwTqOvrlArbnVehSpdX_Ary1D(), sizeof(Ary1D_u9p7_6));

  fct_status = TSC_BmwHwTqOvrlArbn_Rte_Read_BmwDrvgDynErrIfActv_Logl(&Read_BmwDrvgDynErrIfActv_Logl);
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

  fct_status = TSC_BmwHwTqOvrlArbn_Rte_Read_BmwTarHwTqOvrl_Val(&Read_BmwTarHwTqOvrl_Val);
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

  fct_status = TSC_BmwHwTqOvrlArbn_Rte_Read_BmwTarHwTqOvrlQlfr_Val(&Read_BmwTarHwTqOvrlQlfr_Val);
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

  fct_status = TSC_BmwHwTqOvrlArbn_Rte_Read_DrvgDynIfSt_Val(&Read_DrvgDynIfSt_Val);
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

  fct_status = TSC_BmwHwTqOvrlArbn_Rte_Read_HwTqOvrlCmdEna_Logl(&Read_HwTqOvrlCmdEna_Logl);
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

  fct_status = TSC_BmwHwTqOvrlArbn_Rte_Read_VehSpd_Val(&Read_VehSpd_Val);
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

  fct_status = TSC_BmwHwTqOvrlArbn_Rte_Write_HwTqCmdOvrl_Val(Rte_InitValue_HwTqCmdOvrl_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwHwTqOvrlArbn_Rte_Call_GetRefTmr100MicroSec32bit_Oper(&Call_GetRefTmr100MicroSec32bit_Oper_RefTmr_Arg);
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

  fct_status = TSC_BmwHwTqOvrlArbn_Rte_Call_GetTiSpan100MicroSec32bit_Oper(0U, &Call_GetTiSpan100MicroSec32bit_Oper_TiSpan_Arg);
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


#define BmwHwTqOvrlArbn_STOP_SEC_CODE
#include "BmwHwTqOvrlArbn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void BmwHwTqOvrlArbn_TestDefines(void)
{
  /* Enumeration Data Types */

  BmwOvrlCmdQlfr1 Test_BmwOvrlCmdQlfr1_V_1 = BMWOVRLCMDQLFR_IMPLSP;
  BmwOvrlCmdQlfr1 Test_BmwOvrlCmdQlfr1_V_2 = BMWOVRLCMDQLFR_SPNOTAVL;
  BmwOvrlCmdQlfr1 Test_BmwOvrlCmdQlfr1_V_3 = BMWOVRLCMDQLFR_STBDONOTCNVSP;
  BmwOvrlCmdQlfr1 Test_BmwOvrlCmdQlfr1_V_4 = BMWOVRLCMDQLFR_INVLDSIG;

  DrvgDynIfSt1 Test_DrvgDynIfSt1_V_1 = DRVGDYNIFST_IFAVLRDYFOROPERWOADDLDAMPG;
  DrvgDynIfSt1 Test_DrvgDynIfSt1_V_2 = DRVGDYNIFST_IFACTVADDLDAMPGNOTAVL;
  DrvgDynIfSt1 Test_DrvgDynIfSt1_V_3 = DRVGDYNIFST_IFAVLRDYFOROPERADDLDAMPG;
  DrvgDynIfSt1 Test_DrvgDynIfSt1_V_4 = DRVGDYNIFST_IFACTVADDLDAMPGAVL;
  DrvgDynIfSt1 Test_DrvgDynIfSt1_V_5 = DRVGDYNIFST_SRVNOTAVLERR;
  DrvgDynIfSt1 Test_DrvgDynIfSt1_V_6 = DRVGDYNIFST_IFINID;
  DrvgDynIfSt1 Test_DrvgDynIfSt1_V_7 = DRVGDYNIFST_SRVNOTAVLSTBPMA;
  DrvgDynIfSt1 Test_DrvgDynIfSt1_V_8 = DRVGDYNIFST_SRVNOTAVLSTBEPSSTS;
  DrvgDynIfSt1 Test_DrvgDynIfSt1_V_9 = DRVGDYNIFST_INVLDSIG;
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
