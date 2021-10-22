/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  BmwMotTqOvrlArbn.c
 *        Config:  EPS.dpa
 *     SW-C Type:  BmwMotTqOvrlArbn
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <BmwMotTqOvrlArbn>
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
 * BmwNearStillVehSpdSts1
 *   
 *
 * BmwTrfcJamAssiSt1
 *   
 *
 *********************************************************************************************************************/

#include "Rte_BmwMotTqOvrlArbn.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_BmwMotTqOvrlArbn.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"
#include "float.h"

static void BmwMotTqOvrlArbn_TestDefines(void);


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
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * BmwNearStillVehSpdSts1: Enumeration of integer in interval [0...255] with enumerators
 *   BMWNEARSTILLVEHSPDSTS_VEHREST (12U)
 *   BMWNEARSTILLVEHSPDSTS_VEHNOTREST (13U)
 *   BMWNEARSTILLVEHSPDSTS_INVLD (15U)
 * BmwTrfcJamAssiSt1: Enumeration of integer in interval [0...255] with enumerators
 *   BMWTRFCJAMASSIST_INACTV (1U)
 *   BMWTRFCJAMASSIST_ACTV (2U)
 *   BMWTRFCJAMASSIST_INVLD (15U)
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   uint32 *Rte_Pim_BmwNearStillVehSpdStsCdnRefTi(void)
 *   uint32 *Rte_Pim_MfgModCmdCdnRefTi(void)
 *   uint32 *Rte_Pim_VehSpdCdnRefTi(void)
 *   boolean *Rte_Pim_FctlErrStVari(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_BmwMotTqOvrlArbnMfgModCmdThd_Val(void)
 *   float32 Rte_Prm_BmwMotTqOvrlArbnMfgModVehSpdThd_Val(void)
 *   float32 Rte_Prm_BmwMotTqOvrlArbnPullCmpCmdLim_Val(void)
 *   uint16 Rte_Prm_BmwMotTqOvrlArbnBmwNearStillVehSpdStsRefTiThd_Val(void)
 *   uint16 Rte_Prm_BmwMotTqOvrlArbnMfgModCmdRefTiThd_Val(void)
 *   uint16 Rte_Prm_BmwMotTqOvrlArbnVehSpdRefTiThd_Val(void)
 *
 *********************************************************************************************************************/


#define BmwMotTqOvrlArbn_START_SEC_CODE
#include "BmwMotTqOvrlArbn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwMotTqOvrlArbnInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwMotTqOvrlArbnInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwMotTqOvrlArbn_CODE) BmwMotTqOvrlArbnInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwMotTqOvrlArbnInit1
 *********************************************************************************************************************/

  uint32 PimBmwNearStillVehSpdStsCdnRefTi;
  uint32 PimMfgModCmdCdnRefTi;
  uint32 PimVehSpdCdnRefTi;
  boolean PimFctlErrStVari;

  float32 BmwMotTqOvrlArbnMfgModCmdThd_Val_data;
  float32 BmwMotTqOvrlArbnMfgModVehSpdThd_Val_data;
  float32 BmwMotTqOvrlArbnPullCmpCmdLim_Val_data;
  uint16 BmwMotTqOvrlArbnBmwNearStillVehSpdStsRefTiThd_Val_data;
  uint16 BmwMotTqOvrlArbnMfgModCmdRefTiThd_Val_data;
  uint16 BmwMotTqOvrlArbnVehSpdRefTiThd_Val_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimBmwNearStillVehSpdStsCdnRefTi = *TSC_BmwMotTqOvrlArbn_Rte_Pim_BmwNearStillVehSpdStsCdnRefTi();
  *TSC_BmwMotTqOvrlArbn_Rte_Pim_BmwNearStillVehSpdStsCdnRefTi() = PimBmwNearStillVehSpdStsCdnRefTi;
  PimMfgModCmdCdnRefTi = *TSC_BmwMotTqOvrlArbn_Rte_Pim_MfgModCmdCdnRefTi();
  *TSC_BmwMotTqOvrlArbn_Rte_Pim_MfgModCmdCdnRefTi() = PimMfgModCmdCdnRefTi;
  PimVehSpdCdnRefTi = *TSC_BmwMotTqOvrlArbn_Rte_Pim_VehSpdCdnRefTi();
  *TSC_BmwMotTqOvrlArbn_Rte_Pim_VehSpdCdnRefTi() = PimVehSpdCdnRefTi;
  PimFctlErrStVari = *TSC_BmwMotTqOvrlArbn_Rte_Pim_FctlErrStVari();
  *TSC_BmwMotTqOvrlArbn_Rte_Pim_FctlErrStVari() = PimFctlErrStVari;

  BmwMotTqOvrlArbnMfgModCmdThd_Val_data = TSC_BmwMotTqOvrlArbn_Rte_Prm_BmwMotTqOvrlArbnMfgModCmdThd_Val();
  BmwMotTqOvrlArbnMfgModVehSpdThd_Val_data = TSC_BmwMotTqOvrlArbn_Rte_Prm_BmwMotTqOvrlArbnMfgModVehSpdThd_Val();
  BmwMotTqOvrlArbnPullCmpCmdLim_Val_data = TSC_BmwMotTqOvrlArbn_Rte_Prm_BmwMotTqOvrlArbnPullCmpCmdLim_Val();
  BmwMotTqOvrlArbnBmwNearStillVehSpdStsRefTiThd_Val_data = TSC_BmwMotTqOvrlArbn_Rte_Prm_BmwMotTqOvrlArbnBmwNearStillVehSpdStsRefTiThd_Val();
  BmwMotTqOvrlArbnMfgModCmdRefTiThd_Val_data = TSC_BmwMotTqOvrlArbn_Rte_Prm_BmwMotTqOvrlArbnMfgModCmdRefTiThd_Val();
  BmwMotTqOvrlArbnVehSpdRefTiThd_Val_data = TSC_BmwMotTqOvrlArbn_Rte_Prm_BmwMotTqOvrlArbnVehSpdRefTiThd_Val();

  BmwMotTqOvrlArbn_TestDefines();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwMotTqOvrlArbnPer1
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
 *   Std_ReturnType Rte_Read_BmwNearStillVehSpdSts_Val(BmwNearStillVehSpdSts1 *data)
 *   Std_ReturnType Rte_Read_BmwOutpTqOvrlCmd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_BmwTrfcJamAssiDampgSt_Val(BmwTrfcJamAssiSt1 *data)
 *   Std_ReturnType Rte_Read_DrvgDynActv_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_HwOscnActv_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_HwOscnCmd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_HwOscnDcThdExcdd_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_PinionCentrLrnCmd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_PinionCentrLrnEna_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_PosnServoCmd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_PosnServoEna_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_PullCmpCmd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_TrfcJamAssiCmd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_VehSpd_Val(float32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_MotTqOvrlCmd_Val(float32 data)
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
 * Symbol: BmwMotTqOvrlArbnPer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwMotTqOvrlArbn_CODE) BmwMotTqOvrlArbnPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwMotTqOvrlArbnPer1
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  BmwNearStillVehSpdSts1 Read_BmwNearStillVehSpdSts_Val;
  float32 Read_BmwOutpTqOvrlCmd_Val;
  BmwTrfcJamAssiSt1 Read_BmwTrfcJamAssiDampgSt_Val;
  boolean Read_DrvgDynActv_Logl;
  boolean Read_HwOscnActv_Logl;
  float32 Read_HwOscnCmd_Val;
  boolean Read_HwOscnDcThdExcdd_Logl;
  float32 Read_PinionCentrLrnCmd_Val;
  boolean Read_PinionCentrLrnEna_Logl;
  float32 Read_PosnServoCmd_Val;
  boolean Read_PosnServoEna_Logl;
  float32 Read_PullCmpCmd_Val;
  float32 Read_TrfcJamAssiCmd_Val;
  float32 Read_VehSpd_Val;

  uint32 PimBmwNearStillVehSpdStsCdnRefTi;
  uint32 PimMfgModCmdCdnRefTi;
  uint32 PimVehSpdCdnRefTi;
  boolean PimFctlErrStVari;

  float32 BmwMotTqOvrlArbnMfgModCmdThd_Val_data;
  float32 BmwMotTqOvrlArbnMfgModVehSpdThd_Val_data;
  float32 BmwMotTqOvrlArbnPullCmpCmdLim_Val_data;
  uint16 BmwMotTqOvrlArbnBmwNearStillVehSpdStsRefTiThd_Val_data;
  uint16 BmwMotTqOvrlArbnMfgModCmdRefTiThd_Val_data;
  uint16 BmwMotTqOvrlArbnVehSpdRefTiThd_Val_data;

  uint32 Call_GetRefTmr100MicroSec32bit_Oper_RefTmr_Arg = 0U;
  uint32 Call_GetTiSpan100MicroSec32bit_Oper_TiSpan_Arg = 0U;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimBmwNearStillVehSpdStsCdnRefTi = *TSC_BmwMotTqOvrlArbn_Rte_Pim_BmwNearStillVehSpdStsCdnRefTi();
  *TSC_BmwMotTqOvrlArbn_Rte_Pim_BmwNearStillVehSpdStsCdnRefTi() = PimBmwNearStillVehSpdStsCdnRefTi;
  PimMfgModCmdCdnRefTi = *TSC_BmwMotTqOvrlArbn_Rte_Pim_MfgModCmdCdnRefTi();
  *TSC_BmwMotTqOvrlArbn_Rte_Pim_MfgModCmdCdnRefTi() = PimMfgModCmdCdnRefTi;
  PimVehSpdCdnRefTi = *TSC_BmwMotTqOvrlArbn_Rte_Pim_VehSpdCdnRefTi();
  *TSC_BmwMotTqOvrlArbn_Rte_Pim_VehSpdCdnRefTi() = PimVehSpdCdnRefTi;
  PimFctlErrStVari = *TSC_BmwMotTqOvrlArbn_Rte_Pim_FctlErrStVari();
  *TSC_BmwMotTqOvrlArbn_Rte_Pim_FctlErrStVari() = PimFctlErrStVari;

  BmwMotTqOvrlArbnMfgModCmdThd_Val_data = TSC_BmwMotTqOvrlArbn_Rte_Prm_BmwMotTqOvrlArbnMfgModCmdThd_Val();
  BmwMotTqOvrlArbnMfgModVehSpdThd_Val_data = TSC_BmwMotTqOvrlArbn_Rte_Prm_BmwMotTqOvrlArbnMfgModVehSpdThd_Val();
  BmwMotTqOvrlArbnPullCmpCmdLim_Val_data = TSC_BmwMotTqOvrlArbn_Rte_Prm_BmwMotTqOvrlArbnPullCmpCmdLim_Val();
  BmwMotTqOvrlArbnBmwNearStillVehSpdStsRefTiThd_Val_data = TSC_BmwMotTqOvrlArbn_Rte_Prm_BmwMotTqOvrlArbnBmwNearStillVehSpdStsRefTiThd_Val();
  BmwMotTqOvrlArbnMfgModCmdRefTiThd_Val_data = TSC_BmwMotTqOvrlArbn_Rte_Prm_BmwMotTqOvrlArbnMfgModCmdRefTiThd_Val();
  BmwMotTqOvrlArbnVehSpdRefTiThd_Val_data = TSC_BmwMotTqOvrlArbn_Rte_Prm_BmwMotTqOvrlArbnVehSpdRefTiThd_Val();

  fct_status = TSC_BmwMotTqOvrlArbn_Rte_Read_BmwNearStillVehSpdSts_Val(&Read_BmwNearStillVehSpdSts_Val);
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

  fct_status = TSC_BmwMotTqOvrlArbn_Rte_Read_BmwOutpTqOvrlCmd_Val(&Read_BmwOutpTqOvrlCmd_Val);
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

  fct_status = TSC_BmwMotTqOvrlArbn_Rte_Read_BmwTrfcJamAssiDampgSt_Val(&Read_BmwTrfcJamAssiDampgSt_Val);
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

  fct_status = TSC_BmwMotTqOvrlArbn_Rte_Read_DrvgDynActv_Logl(&Read_DrvgDynActv_Logl);
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

  fct_status = TSC_BmwMotTqOvrlArbn_Rte_Read_HwOscnActv_Logl(&Read_HwOscnActv_Logl);
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

  fct_status = TSC_BmwMotTqOvrlArbn_Rte_Read_HwOscnCmd_Val(&Read_HwOscnCmd_Val);
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

  fct_status = TSC_BmwMotTqOvrlArbn_Rte_Read_HwOscnDcThdExcdd_Logl(&Read_HwOscnDcThdExcdd_Logl);
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

  fct_status = TSC_BmwMotTqOvrlArbn_Rte_Read_PinionCentrLrnCmd_Val(&Read_PinionCentrLrnCmd_Val);
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

  fct_status = TSC_BmwMotTqOvrlArbn_Rte_Read_PinionCentrLrnEna_Logl(&Read_PinionCentrLrnEna_Logl);
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

  fct_status = TSC_BmwMotTqOvrlArbn_Rte_Read_PosnServoCmd_Val(&Read_PosnServoCmd_Val);
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

  fct_status = TSC_BmwMotTqOvrlArbn_Rte_Read_PosnServoEna_Logl(&Read_PosnServoEna_Logl);
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

  fct_status = TSC_BmwMotTqOvrlArbn_Rte_Read_PullCmpCmd_Val(&Read_PullCmpCmd_Val);
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

  fct_status = TSC_BmwMotTqOvrlArbn_Rte_Read_TrfcJamAssiCmd_Val(&Read_TrfcJamAssiCmd_Val);
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

  fct_status = TSC_BmwMotTqOvrlArbn_Rte_Read_VehSpd_Val(&Read_VehSpd_Val);
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

  fct_status = TSC_BmwMotTqOvrlArbn_Rte_Write_MotTqOvrlCmd_Val(Rte_InitValue_MotTqOvrlCmd_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwMotTqOvrlArbn_Rte_Call_GetRefTmr100MicroSec32bit_Oper(&Call_GetRefTmr100MicroSec32bit_Oper_RefTmr_Arg);
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

  fct_status = TSC_BmwMotTqOvrlArbn_Rte_Call_GetTiSpan100MicroSec32bit_Oper(0U, &Call_GetTiSpan100MicroSec32bit_Oper_TiSpan_Arg);
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


#define BmwMotTqOvrlArbn_STOP_SEC_CODE
#include "BmwMotTqOvrlArbn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void BmwMotTqOvrlArbn_TestDefines(void)
{
  /* Enumeration Data Types */

  BmwNearStillVehSpdSts1 Test_BmwNearStillVehSpdSts1_V_1 = BMWNEARSTILLVEHSPDSTS_VEHREST;
  BmwNearStillVehSpdSts1 Test_BmwNearStillVehSpdSts1_V_2 = BMWNEARSTILLVEHSPDSTS_VEHNOTREST;
  BmwNearStillVehSpdSts1 Test_BmwNearStillVehSpdSts1_V_3 = BMWNEARSTILLVEHSPDSTS_INVLD;

  BmwTrfcJamAssiSt1 Test_BmwTrfcJamAssiSt1_V_1 = BMWTRFCJAMASSIST_INACTV;
  BmwTrfcJamAssiSt1 Test_BmwTrfcJamAssiSt1_V_2 = BMWTRFCJAMASSIST_ACTV;
  BmwTrfcJamAssiSt1 Test_BmwTrfcJamAssiSt1_V_3 = BMWTRFCJAMASSIST_INVLD;
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
