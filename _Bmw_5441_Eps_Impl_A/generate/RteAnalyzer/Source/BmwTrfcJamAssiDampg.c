/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  BmwTrfcJamAssiDampg.c
 *        Config:  EPS.dpa
 *     SW-C Type:  BmwTrfcJamAssiDampg
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <BmwTrfcJamAssiDampg>
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
 * BmwTrfcJamAssiDampgStReq1
 *   
 *
 * BmwTrfcJamAssiSt1
 *   
 *
 * u11p5
 *   
 *
 * u4p12
 *   
 *
 * u9p7
 *   
 *
 *********************************************************************************************************************/

#include "Rte_BmwTrfcJamAssiDampg.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_BmwTrfcJamAssiDampg.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"
#include "float.h"

static void BmwTrfcJamAssiDampg_TestDefines(void);


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
 * u11p5: Integer in interval [0...65535]
 * u4p12: Integer in interval [0...65535]
 * u9p7: Integer in interval [0...65535]
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * BmwTrfcJamAssiDampgStReq1: Enumeration of integer in interval [0...255] with enumerators
 *   BMWTRFCJAMASSIDAMPGSTREQ_DONOTCNVSPADDLDAMPG (1U)
 *   BMWTRFCJAMASSIDAMPGSTREQ_CNVSPADDLDAMPG (2U)
 *   BMWTRFCJAMASSIDAMPGSTREQ_INVLDSIG (15U)
 * BmwTrfcJamAssiSt1: Enumeration of integer in interval [0...255] with enumerators
 *   BMWTRFCJAMASSIST_INACTV (1U)
 *   BMWTRFCJAMASSIST_ACTV (2U)
 *   BMWTRFCJAMASSIST_INVLD (15U)
 *
 * Array Types:
 * ============
 * Ary1D_u11p5_10: Array with 10 element(s) of type u11p5
 * Ary1D_u11p5_12: Array with 12 element(s) of type u11p5
 * Ary1D_u4p12_10: Array with 10 element(s) of type u4p12
 * Ary1D_u4p12_12: Array with 12 element(s) of type u4p12
 * Ary1D_u9p7_12: Array with 12 element(s) of type u9p7
 * Ary2D_u4p12_12_12: Array with 12 element(s) of type Ary1D_u4p12_12
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   float32 *Rte_Pim_BmwTrfcJamAssiDampgScaStVari(void)
 *   uint32 *Rte_Pim_LimExcddFltRefTi(void)
 *   uint8 *Rte_Pim_TmpBmwTrfcJamAssiDampgSt(void)
 *   boolean *Rte_Pim_PrevLimExcddFlt(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_BmwTrfcJamAssiDampgRatThd_Val(void)
 *   float32 Rte_Prm_BmwTrfcJamAssiDampgSlewRateDwnActv_Val(void)
 *   float32 Rte_Prm_BmwTrfcJamAssiDampgSlewRateDwnInactv_Val(void)
 *   float32 Rte_Prm_BmwTrfcJamAssiDampgSlewRateDwnInvld_Val(void)
 *   float32 Rte_Prm_BmwTrfcJamAssiDampgSlewRateUp_Val(void)
 *   uint16 Rte_Prm_BmwTrfcJamAssiDampgLimExcddFltRefTiThd_Val(void)
 *   u11p5 *Rte_Prm_BmwTrfcJamAssiDampgBasDampgX_Ary1D(void)
 *     Returnvalue: u11p5* is of type Ary1D_u11p5_10
 *   u4p12 *Rte_Prm_BmwTrfcJamAssiDampgBasDampgY_Ary1D(void)
 *     Returnvalue: u4p12* is of type Ary1D_u4p12_10
 *   u11p5 *Rte_Prm_BmwTrfcJamAssiDampgLimdDampgX_Ary1D(void)
 *     Returnvalue: u11p5* is of type Ary1D_u11p5_12
 *   u4p12 *Rte_Prm_BmwTrfcJamAssiDampgLimdDampgY_Ary2D(void)
 *     Returnvalue: u4p12* is of type Ary2D_u4p12_12_12
 *   u9p7 *Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D(void)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_12
 *
 *********************************************************************************************************************/


#define BmwTrfcJamAssiDampg_START_SEC_CODE
#include "BmwTrfcJamAssiDampg_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwTrfcJamAssiDampgInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwTrfcJamAssiDampgInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwTrfcJamAssiDampg_CODE) BmwTrfcJamAssiDampgInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwTrfcJamAssiDampgInit1
 *********************************************************************************************************************/

  float32 PimBmwTrfcJamAssiDampgScaStVari;
  uint32 PimLimExcddFltRefTi;
  uint8 PimTmpBmwTrfcJamAssiDampgSt;
  boolean PimPrevLimExcddFlt;

  float32 BmwTrfcJamAssiDampgRatThd_Val_data;
  float32 BmwTrfcJamAssiDampgSlewRateDwnActv_Val_data;
  float32 BmwTrfcJamAssiDampgSlewRateDwnInactv_Val_data;
  float32 BmwTrfcJamAssiDampgSlewRateDwnInvld_Val_data;
  float32 BmwTrfcJamAssiDampgSlewRateUp_Val_data;
  uint16 BmwTrfcJamAssiDampgLimExcddFltRefTiThd_Val_data;
  Ary1D_u11p5_10 BmwTrfcJamAssiDampgBasDampgX_Ary1D_data;
  Ary1D_u4p12_10 BmwTrfcJamAssiDampgBasDampgY_Ary1D_data;
  Ary1D_u11p5_12 BmwTrfcJamAssiDampgLimdDampgX_Ary1D_data;
  Ary2D_u4p12_12_12 BmwTrfcJamAssiDampgLimdDampgY_Ary2D_data;
  Ary1D_u9p7_12 SysGlbPrmVehSpdBilnrSeln_Ary1D_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimBmwTrfcJamAssiDampgScaStVari = *TSC_BmwTrfcJamAssiDampg_Rte_Pim_BmwTrfcJamAssiDampgScaStVari();
  *TSC_BmwTrfcJamAssiDampg_Rte_Pim_BmwTrfcJamAssiDampgScaStVari() = PimBmwTrfcJamAssiDampgScaStVari;
  PimLimExcddFltRefTi = *TSC_BmwTrfcJamAssiDampg_Rte_Pim_LimExcddFltRefTi();
  *TSC_BmwTrfcJamAssiDampg_Rte_Pim_LimExcddFltRefTi() = PimLimExcddFltRefTi;
  PimTmpBmwTrfcJamAssiDampgSt = *TSC_BmwTrfcJamAssiDampg_Rte_Pim_TmpBmwTrfcJamAssiDampgSt();
  *TSC_BmwTrfcJamAssiDampg_Rte_Pim_TmpBmwTrfcJamAssiDampgSt() = PimTmpBmwTrfcJamAssiDampgSt;
  PimPrevLimExcddFlt = *TSC_BmwTrfcJamAssiDampg_Rte_Pim_PrevLimExcddFlt();
  *TSC_BmwTrfcJamAssiDampg_Rte_Pim_PrevLimExcddFlt() = PimPrevLimExcddFlt;

  BmwTrfcJamAssiDampgRatThd_Val_data = TSC_BmwTrfcJamAssiDampg_Rte_Prm_BmwTrfcJamAssiDampgRatThd_Val();
  BmwTrfcJamAssiDampgSlewRateDwnActv_Val_data = TSC_BmwTrfcJamAssiDampg_Rte_Prm_BmwTrfcJamAssiDampgSlewRateDwnActv_Val();
  BmwTrfcJamAssiDampgSlewRateDwnInactv_Val_data = TSC_BmwTrfcJamAssiDampg_Rte_Prm_BmwTrfcJamAssiDampgSlewRateDwnInactv_Val();
  BmwTrfcJamAssiDampgSlewRateDwnInvld_Val_data = TSC_BmwTrfcJamAssiDampg_Rte_Prm_BmwTrfcJamAssiDampgSlewRateDwnInvld_Val();
  BmwTrfcJamAssiDampgSlewRateUp_Val_data = TSC_BmwTrfcJamAssiDampg_Rte_Prm_BmwTrfcJamAssiDampgSlewRateUp_Val();
  BmwTrfcJamAssiDampgLimExcddFltRefTiThd_Val_data = TSC_BmwTrfcJamAssiDampg_Rte_Prm_BmwTrfcJamAssiDampgLimExcddFltRefTiThd_Val();
  (void)memcpy(BmwTrfcJamAssiDampgBasDampgX_Ary1D_data, TSC_BmwTrfcJamAssiDampg_Rte_Prm_BmwTrfcJamAssiDampgBasDampgX_Ary1D(), sizeof(Ary1D_u11p5_10));
  (void)memcpy(BmwTrfcJamAssiDampgBasDampgY_Ary1D_data, TSC_BmwTrfcJamAssiDampg_Rte_Prm_BmwTrfcJamAssiDampgBasDampgY_Ary1D(), sizeof(Ary1D_u4p12_10));
  (void)memcpy(BmwTrfcJamAssiDampgLimdDampgX_Ary1D_data, TSC_BmwTrfcJamAssiDampg_Rte_Prm_BmwTrfcJamAssiDampgLimdDampgX_Ary1D(), sizeof(Ary1D_u11p5_12));
  (void)memcpy(BmwTrfcJamAssiDampgLimdDampgY_Ary2D_data, TSC_BmwTrfcJamAssiDampg_Rte_Prm_BmwTrfcJamAssiDampgLimdDampgY_Ary2D(), sizeof(Ary2D_u4p12_12_12));
  (void)memcpy(SysGlbPrmVehSpdBilnrSeln_Ary1D_data, TSC_BmwTrfcJamAssiDampg_Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D(), sizeof(Ary1D_u9p7_12));

  BmwTrfcJamAssiDampg_TestDefines();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwTrfcJamAssiDampgPer1
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
 *   Std_ReturnType Rte_Read_BmwTrfcJamAssiDampgScaReq_Val(float32 *data)
 *   Std_ReturnType Rte_Read_BmwTrfcJamAssiDampgScaReqVld_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_BmwTrfcJamAssiDampgStReq_Val(BmwTrfcJamAssiDampgStReq1 *data)
 *   Std_ReturnType Rte_Read_BmwTrfcJamAssiDampgStReqVld_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_MotVelCrf_Val(float32 *data)
 *   Std_ReturnType Rte_Read_TrfcJamAssiCmdEna_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_VehSpd_Val(float32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_BmwTrfcJamAssiDampgSt_Val(BmwTrfcJamAssiSt1 data)
 *   Std_ReturnType Rte_Write_TrfcJamAssiCmd_Val(float32 data)
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
 * Symbol: BmwTrfcJamAssiDampgPer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwTrfcJamAssiDampg_CODE) BmwTrfcJamAssiDampgPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwTrfcJamAssiDampgPer1
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  float32 Read_BmwTrfcJamAssiDampgScaReq_Val;
  boolean Read_BmwTrfcJamAssiDampgScaReqVld_Logl;
  BmwTrfcJamAssiDampgStReq1 Read_BmwTrfcJamAssiDampgStReq_Val;
  boolean Read_BmwTrfcJamAssiDampgStReqVld_Logl;
  float32 Read_MotVelCrf_Val;
  boolean Read_TrfcJamAssiCmdEna_Logl;
  float32 Read_VehSpd_Val;

  float32 PimBmwTrfcJamAssiDampgScaStVari;
  uint32 PimLimExcddFltRefTi;
  uint8 PimTmpBmwTrfcJamAssiDampgSt;
  boolean PimPrevLimExcddFlt;

  float32 BmwTrfcJamAssiDampgRatThd_Val_data;
  float32 BmwTrfcJamAssiDampgSlewRateDwnActv_Val_data;
  float32 BmwTrfcJamAssiDampgSlewRateDwnInactv_Val_data;
  float32 BmwTrfcJamAssiDampgSlewRateDwnInvld_Val_data;
  float32 BmwTrfcJamAssiDampgSlewRateUp_Val_data;
  uint16 BmwTrfcJamAssiDampgLimExcddFltRefTiThd_Val_data;
  Ary1D_u11p5_10 BmwTrfcJamAssiDampgBasDampgX_Ary1D_data;
  Ary1D_u4p12_10 BmwTrfcJamAssiDampgBasDampgY_Ary1D_data;
  Ary1D_u11p5_12 BmwTrfcJamAssiDampgLimdDampgX_Ary1D_data;
  Ary2D_u4p12_12_12 BmwTrfcJamAssiDampgLimdDampgY_Ary2D_data;
  Ary1D_u9p7_12 SysGlbPrmVehSpdBilnrSeln_Ary1D_data;

  uint32 Call_GetRefTmr100MicroSec32bit_Oper_RefTmr_Arg = 0U;
  uint32 Call_GetTiSpan100MicroSec32bit_Oper_TiSpan_Arg = 0U;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimBmwTrfcJamAssiDampgScaStVari = *TSC_BmwTrfcJamAssiDampg_Rte_Pim_BmwTrfcJamAssiDampgScaStVari();
  *TSC_BmwTrfcJamAssiDampg_Rte_Pim_BmwTrfcJamAssiDampgScaStVari() = PimBmwTrfcJamAssiDampgScaStVari;
  PimLimExcddFltRefTi = *TSC_BmwTrfcJamAssiDampg_Rte_Pim_LimExcddFltRefTi();
  *TSC_BmwTrfcJamAssiDampg_Rte_Pim_LimExcddFltRefTi() = PimLimExcddFltRefTi;
  PimTmpBmwTrfcJamAssiDampgSt = *TSC_BmwTrfcJamAssiDampg_Rte_Pim_TmpBmwTrfcJamAssiDampgSt();
  *TSC_BmwTrfcJamAssiDampg_Rte_Pim_TmpBmwTrfcJamAssiDampgSt() = PimTmpBmwTrfcJamAssiDampgSt;
  PimPrevLimExcddFlt = *TSC_BmwTrfcJamAssiDampg_Rte_Pim_PrevLimExcddFlt();
  *TSC_BmwTrfcJamAssiDampg_Rte_Pim_PrevLimExcddFlt() = PimPrevLimExcddFlt;

  BmwTrfcJamAssiDampgRatThd_Val_data = TSC_BmwTrfcJamAssiDampg_Rte_Prm_BmwTrfcJamAssiDampgRatThd_Val();
  BmwTrfcJamAssiDampgSlewRateDwnActv_Val_data = TSC_BmwTrfcJamAssiDampg_Rte_Prm_BmwTrfcJamAssiDampgSlewRateDwnActv_Val();
  BmwTrfcJamAssiDampgSlewRateDwnInactv_Val_data = TSC_BmwTrfcJamAssiDampg_Rte_Prm_BmwTrfcJamAssiDampgSlewRateDwnInactv_Val();
  BmwTrfcJamAssiDampgSlewRateDwnInvld_Val_data = TSC_BmwTrfcJamAssiDampg_Rte_Prm_BmwTrfcJamAssiDampgSlewRateDwnInvld_Val();
  BmwTrfcJamAssiDampgSlewRateUp_Val_data = TSC_BmwTrfcJamAssiDampg_Rte_Prm_BmwTrfcJamAssiDampgSlewRateUp_Val();
  BmwTrfcJamAssiDampgLimExcddFltRefTiThd_Val_data = TSC_BmwTrfcJamAssiDampg_Rte_Prm_BmwTrfcJamAssiDampgLimExcddFltRefTiThd_Val();
  (void)memcpy(BmwTrfcJamAssiDampgBasDampgX_Ary1D_data, TSC_BmwTrfcJamAssiDampg_Rte_Prm_BmwTrfcJamAssiDampgBasDampgX_Ary1D(), sizeof(Ary1D_u11p5_10));
  (void)memcpy(BmwTrfcJamAssiDampgBasDampgY_Ary1D_data, TSC_BmwTrfcJamAssiDampg_Rte_Prm_BmwTrfcJamAssiDampgBasDampgY_Ary1D(), sizeof(Ary1D_u4p12_10));
  (void)memcpy(BmwTrfcJamAssiDampgLimdDampgX_Ary1D_data, TSC_BmwTrfcJamAssiDampg_Rte_Prm_BmwTrfcJamAssiDampgLimdDampgX_Ary1D(), sizeof(Ary1D_u11p5_12));
  (void)memcpy(BmwTrfcJamAssiDampgLimdDampgY_Ary2D_data, TSC_BmwTrfcJamAssiDampg_Rte_Prm_BmwTrfcJamAssiDampgLimdDampgY_Ary2D(), sizeof(Ary2D_u4p12_12_12));
  (void)memcpy(SysGlbPrmVehSpdBilnrSeln_Ary1D_data, TSC_BmwTrfcJamAssiDampg_Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D(), sizeof(Ary1D_u9p7_12));

  fct_status = TSC_BmwTrfcJamAssiDampg_Rte_Read_BmwTrfcJamAssiDampgScaReq_Val(&Read_BmwTrfcJamAssiDampgScaReq_Val);
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

  fct_status = TSC_BmwTrfcJamAssiDampg_Rte_Read_BmwTrfcJamAssiDampgScaReqVld_Logl(&Read_BmwTrfcJamAssiDampgScaReqVld_Logl);
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

  fct_status = TSC_BmwTrfcJamAssiDampg_Rte_Read_BmwTrfcJamAssiDampgStReq_Val(&Read_BmwTrfcJamAssiDampgStReq_Val);
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

  fct_status = TSC_BmwTrfcJamAssiDampg_Rte_Read_BmwTrfcJamAssiDampgStReqVld_Logl(&Read_BmwTrfcJamAssiDampgStReqVld_Logl);
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

  fct_status = TSC_BmwTrfcJamAssiDampg_Rte_Read_MotVelCrf_Val(&Read_MotVelCrf_Val);
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

  fct_status = TSC_BmwTrfcJamAssiDampg_Rte_Read_TrfcJamAssiCmdEna_Logl(&Read_TrfcJamAssiCmdEna_Logl);
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

  fct_status = TSC_BmwTrfcJamAssiDampg_Rte_Read_VehSpd_Val(&Read_VehSpd_Val);
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

  fct_status = TSC_BmwTrfcJamAssiDampg_Rte_Write_BmwTrfcJamAssiDampgSt_Val(Rte_InitValue_BmwTrfcJamAssiDampgSt_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwTrfcJamAssiDampg_Rte_Write_TrfcJamAssiCmd_Val(Rte_InitValue_TrfcJamAssiCmd_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwTrfcJamAssiDampg_Rte_Call_GetRefTmr100MicroSec32bit_Oper(&Call_GetRefTmr100MicroSec32bit_Oper_RefTmr_Arg);
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

  fct_status = TSC_BmwTrfcJamAssiDampg_Rte_Call_GetTiSpan100MicroSec32bit_Oper(0U, &Call_GetTiSpan100MicroSec32bit_Oper_TiSpan_Arg);
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


#define BmwTrfcJamAssiDampg_STOP_SEC_CODE
#include "BmwTrfcJamAssiDampg_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void BmwTrfcJamAssiDampg_TestDefines(void)
{
  /* Enumeration Data Types */

  BmwTrfcJamAssiDampgStReq1 Test_BmwTrfcJamAssiDampgStReq1_V_1 = BMWTRFCJAMASSIDAMPGSTREQ_DONOTCNVSPADDLDAMPG;
  BmwTrfcJamAssiDampgStReq1 Test_BmwTrfcJamAssiDampgStReq1_V_2 = BMWTRFCJAMASSIDAMPGSTREQ_CNVSPADDLDAMPG;
  BmwTrfcJamAssiDampgStReq1 Test_BmwTrfcJamAssiDampgStReq1_V_3 = BMWTRFCJAMASSIDAMPGSTREQ_INVLDSIG;

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
