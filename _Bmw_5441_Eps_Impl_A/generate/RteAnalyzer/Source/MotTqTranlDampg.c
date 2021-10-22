/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  MotTqTranlDampg.c
 *        Config:  EPS.dpa
 *     SW-C Type:  MotTqTranlDampg
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <MotTqTranlDampg>
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
 * LoaSt1
 *   
 *
 * SysSt1
 *   
 *
 * u16p0
 *   
 *
 * u2p14
 *   
 *
 * u9p7
 *   
 *
 *********************************************************************************************************************/

#include "Rte_MotTqTranlDampg.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_MotTqTranlDampg.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"
#include "float.h"

static void MotTqTranlDampg_TestDefines(void);


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
 * boolean: Boolean (standard type)
 * float32: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * float32: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * sint8: Integer in interval [-128...127] (standard type)
 * u16p0: Integer in interval [0...65535]
 * u2p14: Integer in interval [0...65535]
 * u9p7: Integer in interval [0...65535]
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * LoaSt1: Enumeration of integer in interval [0...255] with enumerators
 *   LOAST_NORM (0U)
 *   LOAST_LIMD (1U)
 *   LOAST_SWBASDMTGTN (2U)
 *   LOAST_FADEOUT (3U)
 *   LOAST_CTRLDSHTDWNREQD (4U)
 *   LOAST_IMDTSHTDWNREQD (5U)
 * SysSt1: Enumeration of integer in interval [0...255] with enumerators
 *   SYSST_DI (0U)
 *   SYSST_OFF (1U)
 *   SYSST_ENA (2U)
 *   SYSST_WRMININ (3U)
 *
 * Array Types:
 * ============
 * Ary1D_u16p0_2: Array with 2 element(s) of type u16p0
 * Ary1D_u2p14_2: Array with 2 element(s) of type u2p14
 * Ary1D_u2p14_4: Array with 4 element(s) of type u2p14
 * Ary1D_u9p7_4: Array with 4 element(s) of type u9p7
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   float32 *Rte_Pim_dMotTqTranlDampgCmdCtrld(void)
 *   float32 *Rte_Pim_dMotTqTranlDampgSignPhaSca(void)
 *   float32 *Rte_Pim_dMotTqTranlDampgTiElpd(void)
 *   float32 *Rte_Pim_dMotTqTranlDampgVelDampgCmd(void)
 *   uint32 *Rte_Pim_TmrRefTi(void)
 *   LoaSt1 *Rte_Pim_LoaStPrev(void)
 *   boolean *Rte_Pim_DiagStsPrev(void)
 *   boolean *Rte_Pim_StLtchPrev(void)
 *   boolean *Rte_Pim_dMotTqTranlDampgTmrEna(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_MotTqTranlDampgCmdLim_Val(void)
 *   float32 Rte_Prm_MotTqTranlDampgDampgCoeff_Val(void)
 *   float32 Rte_Prm_MotTqTranlDampgTmrPt1_Val(void)
 *   float32 Rte_Prm_MotTqTranlDampgTmrPt2_Val(void)
 *   float32 Rte_Prm_MotTqTranlDampgVelThd_Val(void)
 *   u2p14 Rte_Prm_MotTqTranlDampgRampEnd_Val(void)
 *   u9p7 *Rte_Prm_MotTqTranlDampgVehSpdBlndX_Ary1D(void)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_4
 *   u2p14 *Rte_Prm_MotTqTranlDampgVehSpdBlndY_Ary1D(void)
 *     Returnvalue: u2p14* is of type Ary1D_u2p14_4
 *
 *********************************************************************************************************************/


#define MotTqTranlDampg_START_SEC_CODE
#include "MotTqTranlDampg_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MotTqTranlDampgInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Inter Runnable Variables:
 * =========================
 *   Explicit Write Access:
 *   ----------------------
 *   void Rte_IrvWrite_MotTqTranlDampgInit1_CtrldDampgScaX(const u16p0 *data)
 *   void Rte_IrvWrite_MotTqTranlDampgInit1_CtrldDampgScaY(const u2p14 *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MotTqTranlDampgInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MotTqTranlDampg_CODE) MotTqTranlDampgInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MotTqTranlDampgInit1
 *********************************************************************************************************************/

  float32 PimdMotTqTranlDampgCmdCtrld;
  float32 PimdMotTqTranlDampgSignPhaSca;
  float32 PimdMotTqTranlDampgTiElpd;
  float32 PimdMotTqTranlDampgVelDampgCmd;
  uint32 PimTmrRefTi;
  LoaSt1 PimLoaStPrev;
  boolean PimDiagStsPrev;
  boolean PimStLtchPrev;
  boolean PimdMotTqTranlDampgTmrEna;

  float32 MotTqTranlDampgCmdLim_Val_data;
  float32 MotTqTranlDampgDampgCoeff_Val_data;
  float32 MotTqTranlDampgTmrPt1_Val_data;
  float32 MotTqTranlDampgTmrPt2_Val_data;
  float32 MotTqTranlDampgVelThd_Val_data;
  u2p14 MotTqTranlDampgRampEnd_Val_data;
  Ary1D_u9p7_4 MotTqTranlDampgVehSpdBlndX_Ary1D_data;
  Ary1D_u2p14_4 MotTqTranlDampgVehSpdBlndY_Ary1D_data;

  Ary1D_u16p0_2 MotTqTranlDampgInit1_CtrldDampgScaX_Write;
  Ary1D_u2p14_2 MotTqTranlDampgInit1_CtrldDampgScaY_Write;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimdMotTqTranlDampgCmdCtrld = *TSC_MotTqTranlDampg_Rte_Pim_dMotTqTranlDampgCmdCtrld();
  *TSC_MotTqTranlDampg_Rte_Pim_dMotTqTranlDampgCmdCtrld() = PimdMotTqTranlDampgCmdCtrld;
  PimdMotTqTranlDampgSignPhaSca = *TSC_MotTqTranlDampg_Rte_Pim_dMotTqTranlDampgSignPhaSca();
  *TSC_MotTqTranlDampg_Rte_Pim_dMotTqTranlDampgSignPhaSca() = PimdMotTqTranlDampgSignPhaSca;
  PimdMotTqTranlDampgTiElpd = *TSC_MotTqTranlDampg_Rte_Pim_dMotTqTranlDampgTiElpd();
  *TSC_MotTqTranlDampg_Rte_Pim_dMotTqTranlDampgTiElpd() = PimdMotTqTranlDampgTiElpd;
  PimdMotTqTranlDampgVelDampgCmd = *TSC_MotTqTranlDampg_Rte_Pim_dMotTqTranlDampgVelDampgCmd();
  *TSC_MotTqTranlDampg_Rte_Pim_dMotTqTranlDampgVelDampgCmd() = PimdMotTqTranlDampgVelDampgCmd;
  PimTmrRefTi = *TSC_MotTqTranlDampg_Rte_Pim_TmrRefTi();
  *TSC_MotTqTranlDampg_Rte_Pim_TmrRefTi() = PimTmrRefTi;
  PimLoaStPrev = *TSC_MotTqTranlDampg_Rte_Pim_LoaStPrev();
  *TSC_MotTqTranlDampg_Rte_Pim_LoaStPrev() = PimLoaStPrev;
  PimDiagStsPrev = *TSC_MotTqTranlDampg_Rte_Pim_DiagStsPrev();
  *TSC_MotTqTranlDampg_Rte_Pim_DiagStsPrev() = PimDiagStsPrev;
  PimStLtchPrev = *TSC_MotTqTranlDampg_Rte_Pim_StLtchPrev();
  *TSC_MotTqTranlDampg_Rte_Pim_StLtchPrev() = PimStLtchPrev;
  PimdMotTqTranlDampgTmrEna = *TSC_MotTqTranlDampg_Rte_Pim_dMotTqTranlDampgTmrEna();
  *TSC_MotTqTranlDampg_Rte_Pim_dMotTqTranlDampgTmrEna() = PimdMotTqTranlDampgTmrEna;

  MotTqTranlDampgCmdLim_Val_data = TSC_MotTqTranlDampg_Rte_Prm_MotTqTranlDampgCmdLim_Val();
  MotTqTranlDampgDampgCoeff_Val_data = TSC_MotTqTranlDampg_Rte_Prm_MotTqTranlDampgDampgCoeff_Val();
  MotTqTranlDampgTmrPt1_Val_data = TSC_MotTqTranlDampg_Rte_Prm_MotTqTranlDampgTmrPt1_Val();
  MotTqTranlDampgTmrPt2_Val_data = TSC_MotTqTranlDampg_Rte_Prm_MotTqTranlDampgTmrPt2_Val();
  MotTqTranlDampgVelThd_Val_data = TSC_MotTqTranlDampg_Rte_Prm_MotTqTranlDampgVelThd_Val();
  MotTqTranlDampgRampEnd_Val_data = TSC_MotTqTranlDampg_Rte_Prm_MotTqTranlDampgRampEnd_Val();
  (void)memcpy(MotTqTranlDampgVehSpdBlndX_Ary1D_data, TSC_MotTqTranlDampg_Rte_Prm_MotTqTranlDampgVehSpdBlndX_Ary1D(), sizeof(Ary1D_u9p7_4));
  (void)memcpy(MotTqTranlDampgVehSpdBlndY_Ary1D_data, TSC_MotTqTranlDampg_Rte_Prm_MotTqTranlDampgVehSpdBlndY_Ary1D(), sizeof(Ary1D_u2p14_4));

  (void)memset(&MotTqTranlDampgInit1_CtrldDampgScaX_Write, 0, sizeof(MotTqTranlDampgInit1_CtrldDampgScaX_Write));
  TSC_MotTqTranlDampg_Rte_IrvWrite_MotTqTranlDampgInit1_CtrldDampgScaX(MotTqTranlDampgInit1_CtrldDampgScaX_Write);
  (void)memset(&MotTqTranlDampgInit1_CtrldDampgScaY_Write, 0, sizeof(MotTqTranlDampgInit1_CtrldDampgScaY_Write));
  TSC_MotTqTranlDampg_Rte_IrvWrite_MotTqTranlDampgInit1_CtrldDampgScaY(MotTqTranlDampgInit1_CtrldDampgScaY_Write);

  MotTqTranlDampg_TestDefines();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MotTqTranlDampgPer1
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
 *   Std_ReturnType Rte_Read_AssiMechPolarity_Val(sint8 *data)
 *   Std_ReturnType Rte_Read_DiagcStsCtrldShtDwnFltPrsnt_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_HwAg_Val(float32 *data)
 *   Std_ReturnType Rte_Read_LoaSt_Val(LoaSt1 *data)
 *   Std_ReturnType Rte_Read_MotTqCmdCrf_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotVelCrf_Val(float32 *data)
 *   Std_ReturnType Rte_Read_SysSt_Val(SysSt1 *data)
 *   Std_ReturnType Rte_Read_VehSpd_Val(float32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_MotTqCmdCrfDampd_Val(float32 data)
 *   Std_ReturnType Rte_Write_MotTqCmdMrfDampd_Val(float32 data)
 *   Std_ReturnType Rte_Write_MotTqTranlDampgCmpl_Logl(boolean data)
 *
 * Inter Runnable Variables:
 * =========================
 *   Explicit Read Access:
 *   ---------------------
 *   void Rte_IrvRead_MotTqTranlDampgPer1_CtrldDampgScaX(u16p0 *data)
 *   void Rte_IrvRead_MotTqTranlDampgPer1_CtrldDampgScaY(u2p14 *data)
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
 * Symbol: MotTqTranlDampgPer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MotTqTranlDampg_CODE) MotTqTranlDampgPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MotTqTranlDampgPer1
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  sint8 Read_AssiMechPolarity_Val;
  boolean Read_DiagcStsCtrldShtDwnFltPrsnt_Logl;
  float32 Read_HwAg_Val;
  LoaSt1 Read_LoaSt_Val;
  float32 Read_MotTqCmdCrf_Val;
  float32 Read_MotVelCrf_Val;
  SysSt1 Read_SysSt_Val;
  float32 Read_VehSpd_Val;

  float32 PimdMotTqTranlDampgCmdCtrld;
  float32 PimdMotTqTranlDampgSignPhaSca;
  float32 PimdMotTqTranlDampgTiElpd;
  float32 PimdMotTqTranlDampgVelDampgCmd;
  uint32 PimTmrRefTi;
  LoaSt1 PimLoaStPrev;
  boolean PimDiagStsPrev;
  boolean PimStLtchPrev;
  boolean PimdMotTqTranlDampgTmrEna;

  float32 MotTqTranlDampgCmdLim_Val_data;
  float32 MotTqTranlDampgDampgCoeff_Val_data;
  float32 MotTqTranlDampgTmrPt1_Val_data;
  float32 MotTqTranlDampgTmrPt2_Val_data;
  float32 MotTqTranlDampgVelThd_Val_data;
  u2p14 MotTqTranlDampgRampEnd_Val_data;
  Ary1D_u9p7_4 MotTqTranlDampgVehSpdBlndX_Ary1D_data;
  Ary1D_u2p14_4 MotTqTranlDampgVehSpdBlndY_Ary1D_data;

  Ary1D_u16p0_2 MotTqTranlDampgPer1_CtrldDampgScaX;
  Ary1D_u2p14_2 MotTqTranlDampgPer1_CtrldDampgScaY;

  uint32 Call_GetRefTmr100MicroSec32bit_Oper_RefTmr_Arg = 0U;
  uint32 Call_GetTiSpan100MicroSec32bit_Oper_TiSpan_Arg = 0U;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimdMotTqTranlDampgCmdCtrld = *TSC_MotTqTranlDampg_Rte_Pim_dMotTqTranlDampgCmdCtrld();
  *TSC_MotTqTranlDampg_Rte_Pim_dMotTqTranlDampgCmdCtrld() = PimdMotTqTranlDampgCmdCtrld;
  PimdMotTqTranlDampgSignPhaSca = *TSC_MotTqTranlDampg_Rte_Pim_dMotTqTranlDampgSignPhaSca();
  *TSC_MotTqTranlDampg_Rte_Pim_dMotTqTranlDampgSignPhaSca() = PimdMotTqTranlDampgSignPhaSca;
  PimdMotTqTranlDampgTiElpd = *TSC_MotTqTranlDampg_Rte_Pim_dMotTqTranlDampgTiElpd();
  *TSC_MotTqTranlDampg_Rte_Pim_dMotTqTranlDampgTiElpd() = PimdMotTqTranlDampgTiElpd;
  PimdMotTqTranlDampgVelDampgCmd = *TSC_MotTqTranlDampg_Rte_Pim_dMotTqTranlDampgVelDampgCmd();
  *TSC_MotTqTranlDampg_Rte_Pim_dMotTqTranlDampgVelDampgCmd() = PimdMotTqTranlDampgVelDampgCmd;
  PimTmrRefTi = *TSC_MotTqTranlDampg_Rte_Pim_TmrRefTi();
  *TSC_MotTqTranlDampg_Rte_Pim_TmrRefTi() = PimTmrRefTi;
  PimLoaStPrev = *TSC_MotTqTranlDampg_Rte_Pim_LoaStPrev();
  *TSC_MotTqTranlDampg_Rte_Pim_LoaStPrev() = PimLoaStPrev;
  PimDiagStsPrev = *TSC_MotTqTranlDampg_Rte_Pim_DiagStsPrev();
  *TSC_MotTqTranlDampg_Rte_Pim_DiagStsPrev() = PimDiagStsPrev;
  PimStLtchPrev = *TSC_MotTqTranlDampg_Rte_Pim_StLtchPrev();
  *TSC_MotTqTranlDampg_Rte_Pim_StLtchPrev() = PimStLtchPrev;
  PimdMotTqTranlDampgTmrEna = *TSC_MotTqTranlDampg_Rte_Pim_dMotTqTranlDampgTmrEna();
  *TSC_MotTqTranlDampg_Rte_Pim_dMotTqTranlDampgTmrEna() = PimdMotTqTranlDampgTmrEna;

  MotTqTranlDampgCmdLim_Val_data = TSC_MotTqTranlDampg_Rte_Prm_MotTqTranlDampgCmdLim_Val();
  MotTqTranlDampgDampgCoeff_Val_data = TSC_MotTqTranlDampg_Rte_Prm_MotTqTranlDampgDampgCoeff_Val();
  MotTqTranlDampgTmrPt1_Val_data = TSC_MotTqTranlDampg_Rte_Prm_MotTqTranlDampgTmrPt1_Val();
  MotTqTranlDampgTmrPt2_Val_data = TSC_MotTqTranlDampg_Rte_Prm_MotTqTranlDampgTmrPt2_Val();
  MotTqTranlDampgVelThd_Val_data = TSC_MotTqTranlDampg_Rte_Prm_MotTqTranlDampgVelThd_Val();
  MotTqTranlDampgRampEnd_Val_data = TSC_MotTqTranlDampg_Rte_Prm_MotTqTranlDampgRampEnd_Val();
  (void)memcpy(MotTqTranlDampgVehSpdBlndX_Ary1D_data, TSC_MotTqTranlDampg_Rte_Prm_MotTqTranlDampgVehSpdBlndX_Ary1D(), sizeof(Ary1D_u9p7_4));
  (void)memcpy(MotTqTranlDampgVehSpdBlndY_Ary1D_data, TSC_MotTqTranlDampg_Rte_Prm_MotTqTranlDampgVehSpdBlndY_Ary1D(), sizeof(Ary1D_u2p14_4));

  fct_status = TSC_MotTqTranlDampg_Rte_Read_AssiMechPolarity_Val(&Read_AssiMechPolarity_Val);
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

  fct_status = TSC_MotTqTranlDampg_Rte_Read_DiagcStsCtrldShtDwnFltPrsnt_Logl(&Read_DiagcStsCtrldShtDwnFltPrsnt_Logl);
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

  fct_status = TSC_MotTqTranlDampg_Rte_Read_HwAg_Val(&Read_HwAg_Val);
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

  fct_status = TSC_MotTqTranlDampg_Rte_Read_LoaSt_Val(&Read_LoaSt_Val);
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

  fct_status = TSC_MotTqTranlDampg_Rte_Read_MotTqCmdCrf_Val(&Read_MotTqCmdCrf_Val);
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

  fct_status = TSC_MotTqTranlDampg_Rte_Read_MotVelCrf_Val(&Read_MotVelCrf_Val);
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

  fct_status = TSC_MotTqTranlDampg_Rte_Read_SysSt_Val(&Read_SysSt_Val);
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

  fct_status = TSC_MotTqTranlDampg_Rte_Read_VehSpd_Val(&Read_VehSpd_Val);
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

  fct_status = TSC_MotTqTranlDampg_Rte_Write_MotTqCmdCrfDampd_Val(Rte_InitValue_MotTqCmdCrfDampd_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MotTqTranlDampg_Rte_Write_MotTqCmdMrfDampd_Val(Rte_InitValue_MotTqCmdMrfDampd_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MotTqTranlDampg_Rte_Write_MotTqTranlDampgCmpl_Logl(Rte_InitValue_MotTqTranlDampgCmpl_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  TSC_MotTqTranlDampg_Rte_IrvRead_MotTqTranlDampgPer1_CtrldDampgScaX(MotTqTranlDampgPer1_CtrldDampgScaX);
  TSC_MotTqTranlDampg_Rte_IrvRead_MotTqTranlDampgPer1_CtrldDampgScaY(MotTqTranlDampgPer1_CtrldDampgScaY);

  fct_status = TSC_MotTqTranlDampg_Rte_Call_GetRefTmr100MicroSec32bit_Oper(&Call_GetRefTmr100MicroSec32bit_Oper_RefTmr_Arg);
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

  fct_status = TSC_MotTqTranlDampg_Rte_Call_GetTiSpan100MicroSec32bit_Oper(0U, &Call_GetTiSpan100MicroSec32bit_Oper_TiSpan_Arg);
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


#define MotTqTranlDampg_STOP_SEC_CODE
#include "MotTqTranlDampg_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void MotTqTranlDampg_TestDefines(void)
{
  /* Enumeration Data Types */

  LoaSt1 Test_LoaSt1_V_1 = LOAST_NORM;
  LoaSt1 Test_LoaSt1_V_2 = LOAST_LIMD;
  LoaSt1 Test_LoaSt1_V_3 = LOAST_SWBASDMTGTN;
  LoaSt1 Test_LoaSt1_V_4 = LOAST_FADEOUT;
  LoaSt1 Test_LoaSt1_V_5 = LOAST_CTRLDSHTDWNREQD;
  LoaSt1 Test_LoaSt1_V_6 = LOAST_IMDTSHTDWNREQD;

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
