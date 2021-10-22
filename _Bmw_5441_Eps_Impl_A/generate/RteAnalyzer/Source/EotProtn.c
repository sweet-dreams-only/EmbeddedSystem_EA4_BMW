/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  EotProtn.c
 *        Config:  EPS.dpa
 *     SW-C Type:  EotProtn
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <EotProtn>
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
 * u0p16
 *   
 *
 * u12p4
 *   
 *
 * u1p15
 *   
 *
 * u4p12
 *   
 *
 * u9p7
 *   
 *
 *********************************************************************************************************************/

#include "Rte_EotProtn.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_EotProtn.h"


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
 * boolean: Boolean (standard type)
 * float32: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * float32: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * u0p16: Integer in interval [0...65535]
 * u12p4: Integer in interval [0...65535]
 * u1p15: Integer in interval [0...65535]
 * u4p12: Integer in interval [0...65535]
 * u9p7: Integer in interval [0...65535]
 * uint16: Integer in interval [0...65535] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Array Types:
 * ============
 * Ary1D_u0p16_2: Array with 2 element(s) of type u0p16
 * Ary1D_u12p4_2: Array with 2 element(s) of type u12p4
 * Ary1D_u12p4_4: Array with 4 element(s) of type u12p4
 * Ary1D_u1p15_4: Array with 4 element(s) of type u1p15
 * Ary1D_u4p12_2: Array with 2 element(s) of type u4p12
 * Ary1D_u9p7_4: Array with 4 element(s) of type u9p7
 * Ary1D_u9p7_5: Array with 5 element(s) of type u9p7
 * Ary2D_u0p16_4_2: Array with 4 element(s) of type Ary1D_u0p16_2
 * Ary2D_u12p4_4_2: Array with 4 element(s) of type Ary1D_u12p4_2
 * Ary2D_u12p4_5_4: Array with 5 element(s) of type Ary1D_u12p4_4
 * Ary2D_u1p15_5_4: Array with 5 element(s) of type Ary1D_u1p15_4
 *
 * Record Types:
 * =============
 * FilLpRec1: Record with elements
 *   FilSt of type float32
 *   FilGain of type float32
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   float32 *Rte_Pim_PrevEotAssiSca(void)
 *   float32 *Rte_Pim_PrevEotDampg(void)
 *   float32 *Rte_Pim_PrevImpctPosn(void)
 *   float32 *Rte_Pim_dEotProtnDampg(void)
 *   float32 *Rte_Pim_dEotProtnEntrGain(void)
 *   float32 *Rte_Pim_dEotProtnEotAssiSca(void)
 *   float32 *Rte_Pim_dEotProtnEotGain(void)
 *   float32 *Rte_Pim_dEotProtnExitGain(void)
 *   float32 *Rte_Pim_dEotProtnLimPosn(void)
 *   uint8 *Rte_Pim_NewSoftEndStopSt(void)
 *   uint8 *Rte_Pim_PrevSoftEndStopSt(void)
 *   boolean *Rte_Pim_PrevRackTrvlLimrEna(void)
 *   boolean *Rte_Pim_PrevRackTrvlLimrInin(void)
 *   boolean *Rte_Pim_dEotProtnDetd(void)
 *   boolean *Rte_Pim_dEotProtnRackTrvlLimrDi(void)
 *   FilLpRec1 *Rte_Pim_EotAssiScaLpFil(void)
 *   FilLpRec1 *Rte_Pim_HwTqLpFil(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_EotProtnActvRegnBypMaxThd_Val(void)
 *   float32 Rte_Prm_EotProtnDampgSlew_Val(void)
 *   float32 Rte_Prm_EotProtnDeltaTqThd_Val(void)
 *   float32 Rte_Prm_EotProtnDftPosn_Val(void)
 *   float32 Rte_Prm_EotProtnEntrGainAuthyThd_Val(void)
 *   float32 Rte_Prm_EotProtnEntrStLpFilFrq_Val(void)
 *   float32 Rte_Prm_EotProtnExitStLpFilFrq_Val(void)
 *   float32 Rte_Prm_EotProtnHwAgGain_Val(void)
 *   float32 Rte_Prm_EotProtnHwAgMax_Val(void)
 *   float32 Rte_Prm_EotProtnHwAgMin_Val(void)
 *   float32 Rte_Prm_EotProtnHwTqLpFilFrq_Val(void)
 *   float32 Rte_Prm_EotProtnMotSpdIncptSca_Val(void)
 *   float32 Rte_Prm_EotProtnMotVelGain_Val(void)
 *   float32 Rte_Prm_EotProtnPosnRampStep_Val(void)
 *   float32 Rte_Prm_EotProtnRackTrvlLimrAuthyThd_Val(void)
 *   float32 Rte_Prm_EotProtnRackTrvlLimrAuthyThdLimd_Val(void)
 *   float32 Rte_Prm_EotProtnRackTrvlLimrRng_Val(void)
 *   float32 Rte_Prm_EotProtnRackTrvlLimrRngLimd_Val(void)
 *   float32 Rte_Prm_EotProtnRackTrvlLimrVehSpdThd_Val(void)
 *   float32 Rte_Prm_EotProtnSoftEndStopAuthyThd_Val(void)
 *   float32 Rte_Prm_EotProtnSoftEndStopVehSpdThd_Val(void)
 *   boolean Rte_Prm_EotProtnRackTrvlLimrEna_Logl(void)
 *   boolean Rte_Prm_EotProtnRunEotVelImpctAndSoftEndStop_Logl(void)
 *   boolean Rte_Prm_EotProtnSoftEndStopEna_Logl(void)
 *   u9p7 *Rte_Prm_EotProtnDampgVehSpdTbl_Ary1D(void)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_4
 *   u9p7 *Rte_Prm_EotProtnEntrGainVehSpdTbl_Ary1D(void)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_5
 *   u12p4 *Rte_Prm_EotProtnEntrGainX_Ary2D(void)
 *     Returnvalue: u12p4* is of type Ary2D_u12p4_5_4
 *   u1p15 *Rte_Prm_EotProtnEntrGainY_Ary2D(void)
 *     Returnvalue: u1p15* is of type Ary2D_u1p15_5_4
 *   u0p16 *Rte_Prm_EotProtnExitDampgY_Ary2D(void)
 *     Returnvalue: u0p16* is of type Ary2D_u0p16_4_2
 *   u12p4 *Rte_Prm_EotProtnHwDegDampgX_Ary2D(void)
 *     Returnvalue: u12p4* is of type Ary2D_u12p4_4_2
 *   u4p12 *Rte_Prm_EotProtnHwTqScaX_Ary1D(void)
 *     Returnvalue: u4p12* is of type Ary1D_u4p12_2
 *   u1p15 *Rte_Prm_EotProtnLoAuthyEntrGainY_Ary2D(void)
 *     Returnvalue: u1p15* is of type Ary2D_u1p15_5_4
 *   u12p4 *Rte_Prm_EotProtnMotSpdIncptX_Ary1D(void)
 *     Returnvalue: u12p4* is of type Ary1D_u12p4_2
 *   u12p4 *Rte_Prm_EotProtnMotSpdIncptY_Ary1D(void)
 *     Returnvalue: u12p4* is of type Ary1D_u12p4_2
 *   u0p16 *Rte_Prm_EotProtnNormDampgY_Ary2D(void)
 *     Returnvalue: u0p16* is of type Ary2D_u0p16_4_2
 *
 *********************************************************************************************************************/


#define EotProtn_START_SEC_CODE
#include "EotProtn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: EotProtnInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: EotProtnInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, EotProtn_CODE) EotProtnInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: EotProtnInit1
 *********************************************************************************************************************/

  float32 PimPrevEotAssiSca;
  float32 PimPrevEotDampg;
  float32 PimPrevImpctPosn;
  float32 PimdEotProtnDampg;
  float32 PimdEotProtnEntrGain;
  float32 PimdEotProtnEotAssiSca;
  float32 PimdEotProtnEotGain;
  float32 PimdEotProtnExitGain;
  float32 PimdEotProtnLimPosn;
  uint8 PimNewSoftEndStopSt;
  uint8 PimPrevSoftEndStopSt;
  boolean PimPrevRackTrvlLimrEna;
  boolean PimPrevRackTrvlLimrInin;
  boolean PimdEotProtnDetd;
  boolean PimdEotProtnRackTrvlLimrDi;
  FilLpRec1 PimEotAssiScaLpFil;
  FilLpRec1 PimHwTqLpFil;

  float32 EotProtnActvRegnBypMaxThd_Val_data;
  float32 EotProtnDampgSlew_Val_data;
  float32 EotProtnDeltaTqThd_Val_data;
  float32 EotProtnDftPosn_Val_data;
  float32 EotProtnEntrGainAuthyThd_Val_data;
  float32 EotProtnEntrStLpFilFrq_Val_data;
  float32 EotProtnExitStLpFilFrq_Val_data;
  float32 EotProtnHwAgGain_Val_data;
  float32 EotProtnHwAgMax_Val_data;
  float32 EotProtnHwAgMin_Val_data;
  float32 EotProtnHwTqLpFilFrq_Val_data;
  float32 EotProtnMotSpdIncptSca_Val_data;
  float32 EotProtnMotVelGain_Val_data;
  float32 EotProtnPosnRampStep_Val_data;
  float32 EotProtnRackTrvlLimrAuthyThd_Val_data;
  float32 EotProtnRackTrvlLimrAuthyThdLimd_Val_data;
  float32 EotProtnRackTrvlLimrRng_Val_data;
  float32 EotProtnRackTrvlLimrRngLimd_Val_data;
  float32 EotProtnRackTrvlLimrVehSpdThd_Val_data;
  float32 EotProtnSoftEndStopAuthyThd_Val_data;
  float32 EotProtnSoftEndStopVehSpdThd_Val_data;
  boolean EotProtnRackTrvlLimrEna_Logl_data;
  boolean EotProtnRunEotVelImpctAndSoftEndStop_Logl_data;
  boolean EotProtnSoftEndStopEna_Logl_data;
  Ary1D_u9p7_4 EotProtnDampgVehSpdTbl_Ary1D_data;
  Ary1D_u9p7_5 EotProtnEntrGainVehSpdTbl_Ary1D_data;
  Ary2D_u12p4_5_4 EotProtnEntrGainX_Ary2D_data;
  Ary2D_u1p15_5_4 EotProtnEntrGainY_Ary2D_data;
  Ary2D_u0p16_4_2 EotProtnExitDampgY_Ary2D_data;
  Ary2D_u12p4_4_2 EotProtnHwDegDampgX_Ary2D_data;
  Ary1D_u4p12_2 EotProtnHwTqScaX_Ary1D_data;
  Ary2D_u1p15_5_4 EotProtnLoAuthyEntrGainY_Ary2D_data;
  Ary1D_u12p4_2 EotProtnMotSpdIncptX_Ary1D_data;
  Ary1D_u12p4_2 EotProtnMotSpdIncptY_Ary1D_data;
  Ary2D_u0p16_4_2 EotProtnNormDampgY_Ary2D_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimPrevEotAssiSca = *TSC_EotProtn_Rte_Pim_PrevEotAssiSca();
  *TSC_EotProtn_Rte_Pim_PrevEotAssiSca() = PimPrevEotAssiSca;
  PimPrevEotDampg = *TSC_EotProtn_Rte_Pim_PrevEotDampg();
  *TSC_EotProtn_Rte_Pim_PrevEotDampg() = PimPrevEotDampg;
  PimPrevImpctPosn = *TSC_EotProtn_Rte_Pim_PrevImpctPosn();
  *TSC_EotProtn_Rte_Pim_PrevImpctPosn() = PimPrevImpctPosn;
  PimdEotProtnDampg = *TSC_EotProtn_Rte_Pim_dEotProtnDampg();
  *TSC_EotProtn_Rte_Pim_dEotProtnDampg() = PimdEotProtnDampg;
  PimdEotProtnEntrGain = *TSC_EotProtn_Rte_Pim_dEotProtnEntrGain();
  *TSC_EotProtn_Rte_Pim_dEotProtnEntrGain() = PimdEotProtnEntrGain;
  PimdEotProtnEotAssiSca = *TSC_EotProtn_Rte_Pim_dEotProtnEotAssiSca();
  *TSC_EotProtn_Rte_Pim_dEotProtnEotAssiSca() = PimdEotProtnEotAssiSca;
  PimdEotProtnEotGain = *TSC_EotProtn_Rte_Pim_dEotProtnEotGain();
  *TSC_EotProtn_Rte_Pim_dEotProtnEotGain() = PimdEotProtnEotGain;
  PimdEotProtnExitGain = *TSC_EotProtn_Rte_Pim_dEotProtnExitGain();
  *TSC_EotProtn_Rte_Pim_dEotProtnExitGain() = PimdEotProtnExitGain;
  PimdEotProtnLimPosn = *TSC_EotProtn_Rte_Pim_dEotProtnLimPosn();
  *TSC_EotProtn_Rte_Pim_dEotProtnLimPosn() = PimdEotProtnLimPosn;
  PimNewSoftEndStopSt = *TSC_EotProtn_Rte_Pim_NewSoftEndStopSt();
  *TSC_EotProtn_Rte_Pim_NewSoftEndStopSt() = PimNewSoftEndStopSt;
  PimPrevSoftEndStopSt = *TSC_EotProtn_Rte_Pim_PrevSoftEndStopSt();
  *TSC_EotProtn_Rte_Pim_PrevSoftEndStopSt() = PimPrevSoftEndStopSt;
  PimPrevRackTrvlLimrEna = *TSC_EotProtn_Rte_Pim_PrevRackTrvlLimrEna();
  *TSC_EotProtn_Rte_Pim_PrevRackTrvlLimrEna() = PimPrevRackTrvlLimrEna;
  PimPrevRackTrvlLimrInin = *TSC_EotProtn_Rte_Pim_PrevRackTrvlLimrInin();
  *TSC_EotProtn_Rte_Pim_PrevRackTrvlLimrInin() = PimPrevRackTrvlLimrInin;
  PimdEotProtnDetd = *TSC_EotProtn_Rte_Pim_dEotProtnDetd();
  *TSC_EotProtn_Rte_Pim_dEotProtnDetd() = PimdEotProtnDetd;
  PimdEotProtnRackTrvlLimrDi = *TSC_EotProtn_Rte_Pim_dEotProtnRackTrvlLimrDi();
  *TSC_EotProtn_Rte_Pim_dEotProtnRackTrvlLimrDi() = PimdEotProtnRackTrvlLimrDi;
  PimEotAssiScaLpFil = *TSC_EotProtn_Rte_Pim_EotAssiScaLpFil();
  *TSC_EotProtn_Rte_Pim_EotAssiScaLpFil() = PimEotAssiScaLpFil;
  PimHwTqLpFil = *TSC_EotProtn_Rte_Pim_HwTqLpFil();
  *TSC_EotProtn_Rte_Pim_HwTqLpFil() = PimHwTqLpFil;

  EotProtnActvRegnBypMaxThd_Val_data = TSC_EotProtn_Rte_Prm_EotProtnActvRegnBypMaxThd_Val();
  EotProtnDampgSlew_Val_data = TSC_EotProtn_Rte_Prm_EotProtnDampgSlew_Val();
  EotProtnDeltaTqThd_Val_data = TSC_EotProtn_Rte_Prm_EotProtnDeltaTqThd_Val();
  EotProtnDftPosn_Val_data = TSC_EotProtn_Rte_Prm_EotProtnDftPosn_Val();
  EotProtnEntrGainAuthyThd_Val_data = TSC_EotProtn_Rte_Prm_EotProtnEntrGainAuthyThd_Val();
  EotProtnEntrStLpFilFrq_Val_data = TSC_EotProtn_Rte_Prm_EotProtnEntrStLpFilFrq_Val();
  EotProtnExitStLpFilFrq_Val_data = TSC_EotProtn_Rte_Prm_EotProtnExitStLpFilFrq_Val();
  EotProtnHwAgGain_Val_data = TSC_EotProtn_Rte_Prm_EotProtnHwAgGain_Val();
  EotProtnHwAgMax_Val_data = TSC_EotProtn_Rte_Prm_EotProtnHwAgMax_Val();
  EotProtnHwAgMin_Val_data = TSC_EotProtn_Rte_Prm_EotProtnHwAgMin_Val();
  EotProtnHwTqLpFilFrq_Val_data = TSC_EotProtn_Rte_Prm_EotProtnHwTqLpFilFrq_Val();
  EotProtnMotSpdIncptSca_Val_data = TSC_EotProtn_Rte_Prm_EotProtnMotSpdIncptSca_Val();
  EotProtnMotVelGain_Val_data = TSC_EotProtn_Rte_Prm_EotProtnMotVelGain_Val();
  EotProtnPosnRampStep_Val_data = TSC_EotProtn_Rte_Prm_EotProtnPosnRampStep_Val();
  EotProtnRackTrvlLimrAuthyThd_Val_data = TSC_EotProtn_Rte_Prm_EotProtnRackTrvlLimrAuthyThd_Val();
  EotProtnRackTrvlLimrAuthyThdLimd_Val_data = TSC_EotProtn_Rte_Prm_EotProtnRackTrvlLimrAuthyThdLimd_Val();
  EotProtnRackTrvlLimrRng_Val_data = TSC_EotProtn_Rte_Prm_EotProtnRackTrvlLimrRng_Val();
  EotProtnRackTrvlLimrRngLimd_Val_data = TSC_EotProtn_Rte_Prm_EotProtnRackTrvlLimrRngLimd_Val();
  EotProtnRackTrvlLimrVehSpdThd_Val_data = TSC_EotProtn_Rte_Prm_EotProtnRackTrvlLimrVehSpdThd_Val();
  EotProtnSoftEndStopAuthyThd_Val_data = TSC_EotProtn_Rte_Prm_EotProtnSoftEndStopAuthyThd_Val();
  EotProtnSoftEndStopVehSpdThd_Val_data = TSC_EotProtn_Rte_Prm_EotProtnSoftEndStopVehSpdThd_Val();
  EotProtnRackTrvlLimrEna_Logl_data = TSC_EotProtn_Rte_Prm_EotProtnRackTrvlLimrEna_Logl();
  EotProtnRunEotVelImpctAndSoftEndStop_Logl_data = TSC_EotProtn_Rte_Prm_EotProtnRunEotVelImpctAndSoftEndStop_Logl();
  EotProtnSoftEndStopEna_Logl_data = TSC_EotProtn_Rte_Prm_EotProtnSoftEndStopEna_Logl();
  (void)memcpy(EotProtnDampgVehSpdTbl_Ary1D_data, TSC_EotProtn_Rte_Prm_EotProtnDampgVehSpdTbl_Ary1D(), sizeof(Ary1D_u9p7_4));
  (void)memcpy(EotProtnEntrGainVehSpdTbl_Ary1D_data, TSC_EotProtn_Rte_Prm_EotProtnEntrGainVehSpdTbl_Ary1D(), sizeof(Ary1D_u9p7_5));
  (void)memcpy(EotProtnEntrGainX_Ary2D_data, TSC_EotProtn_Rte_Prm_EotProtnEntrGainX_Ary2D(), sizeof(Ary2D_u12p4_5_4));
  (void)memcpy(EotProtnEntrGainY_Ary2D_data, TSC_EotProtn_Rte_Prm_EotProtnEntrGainY_Ary2D(), sizeof(Ary2D_u1p15_5_4));
  (void)memcpy(EotProtnExitDampgY_Ary2D_data, TSC_EotProtn_Rte_Prm_EotProtnExitDampgY_Ary2D(), sizeof(Ary2D_u0p16_4_2));
  (void)memcpy(EotProtnHwDegDampgX_Ary2D_data, TSC_EotProtn_Rte_Prm_EotProtnHwDegDampgX_Ary2D(), sizeof(Ary2D_u12p4_4_2));
  (void)memcpy(EotProtnHwTqScaX_Ary1D_data, TSC_EotProtn_Rte_Prm_EotProtnHwTqScaX_Ary1D(), sizeof(Ary1D_u4p12_2));
  (void)memcpy(EotProtnLoAuthyEntrGainY_Ary2D_data, TSC_EotProtn_Rte_Prm_EotProtnLoAuthyEntrGainY_Ary2D(), sizeof(Ary2D_u1p15_5_4));
  (void)memcpy(EotProtnMotSpdIncptX_Ary1D_data, TSC_EotProtn_Rte_Prm_EotProtnMotSpdIncptX_Ary1D(), sizeof(Ary1D_u12p4_2));
  (void)memcpy(EotProtnMotSpdIncptY_Ary1D_data, TSC_EotProtn_Rte_Prm_EotProtnMotSpdIncptY_Ary1D(), sizeof(Ary1D_u12p4_2));
  (void)memcpy(EotProtnNormDampgY_Ary2D_data, TSC_EotProtn_Rte_Prm_EotProtnNormDampgY_Ary2D(), sizeof(Ary2D_u0p16_4_2));


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: EotProtnPer1
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
 *   Std_ReturnType Rte_Read_EotProtnDi_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_HwAg_Val(float32 *data)
 *   Std_ReturnType Rte_Read_HwAgAuthy_Val(float32 *data)
 *   Std_ReturnType Rte_Read_HwAgCcwDetd_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_HwAgCwDetd_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_HwAgEotCcw_Val(float32 *data)
 *   Std_ReturnType Rte_Read_HwAgEotCw_Val(float32 *data)
 *   Std_ReturnType Rte_Read_HwTq_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotVelCrf_Val(float32 *data)
 *   Std_ReturnType Rte_Read_SysMotTqCmdSca_Val(float32 *data)
 *   Std_ReturnType Rte_Read_VehSpd_Val(float32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_EotActvCmd_Val(float32 data)
 *   Std_ReturnType Rte_Write_EotAssiSca_Val(float32 data)
 *   Std_ReturnType Rte_Write_EotDampgCmd_Val(float32 data)
 *   Std_ReturnType Rte_Write_EotMotTqLim_Val(float32 data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: EotProtnPer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, EotProtn_CODE) EotProtnPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: EotProtnPer1
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  boolean Read_EotProtnDi_Logl;
  float32 Read_HwAg_Val;
  float32 Read_HwAgAuthy_Val;
  boolean Read_HwAgCcwDetd_Logl;
  boolean Read_HwAgCwDetd_Logl;
  float32 Read_HwAgEotCcw_Val;
  float32 Read_HwAgEotCw_Val;
  float32 Read_HwTq_Val;
  float32 Read_MotVelCrf_Val;
  float32 Read_SysMotTqCmdSca_Val;
  float32 Read_VehSpd_Val;

  float32 PimPrevEotAssiSca;
  float32 PimPrevEotDampg;
  float32 PimPrevImpctPosn;
  float32 PimdEotProtnDampg;
  float32 PimdEotProtnEntrGain;
  float32 PimdEotProtnEotAssiSca;
  float32 PimdEotProtnEotGain;
  float32 PimdEotProtnExitGain;
  float32 PimdEotProtnLimPosn;
  uint8 PimNewSoftEndStopSt;
  uint8 PimPrevSoftEndStopSt;
  boolean PimPrevRackTrvlLimrEna;
  boolean PimPrevRackTrvlLimrInin;
  boolean PimdEotProtnDetd;
  boolean PimdEotProtnRackTrvlLimrDi;
  FilLpRec1 PimEotAssiScaLpFil;
  FilLpRec1 PimHwTqLpFil;

  float32 EotProtnActvRegnBypMaxThd_Val_data;
  float32 EotProtnDampgSlew_Val_data;
  float32 EotProtnDeltaTqThd_Val_data;
  float32 EotProtnDftPosn_Val_data;
  float32 EotProtnEntrGainAuthyThd_Val_data;
  float32 EotProtnEntrStLpFilFrq_Val_data;
  float32 EotProtnExitStLpFilFrq_Val_data;
  float32 EotProtnHwAgGain_Val_data;
  float32 EotProtnHwAgMax_Val_data;
  float32 EotProtnHwAgMin_Val_data;
  float32 EotProtnHwTqLpFilFrq_Val_data;
  float32 EotProtnMotSpdIncptSca_Val_data;
  float32 EotProtnMotVelGain_Val_data;
  float32 EotProtnPosnRampStep_Val_data;
  float32 EotProtnRackTrvlLimrAuthyThd_Val_data;
  float32 EotProtnRackTrvlLimrAuthyThdLimd_Val_data;
  float32 EotProtnRackTrvlLimrRng_Val_data;
  float32 EotProtnRackTrvlLimrRngLimd_Val_data;
  float32 EotProtnRackTrvlLimrVehSpdThd_Val_data;
  float32 EotProtnSoftEndStopAuthyThd_Val_data;
  float32 EotProtnSoftEndStopVehSpdThd_Val_data;
  boolean EotProtnRackTrvlLimrEna_Logl_data;
  boolean EotProtnRunEotVelImpctAndSoftEndStop_Logl_data;
  boolean EotProtnSoftEndStopEna_Logl_data;
  Ary1D_u9p7_4 EotProtnDampgVehSpdTbl_Ary1D_data;
  Ary1D_u9p7_5 EotProtnEntrGainVehSpdTbl_Ary1D_data;
  Ary2D_u12p4_5_4 EotProtnEntrGainX_Ary2D_data;
  Ary2D_u1p15_5_4 EotProtnEntrGainY_Ary2D_data;
  Ary2D_u0p16_4_2 EotProtnExitDampgY_Ary2D_data;
  Ary2D_u12p4_4_2 EotProtnHwDegDampgX_Ary2D_data;
  Ary1D_u4p12_2 EotProtnHwTqScaX_Ary1D_data;
  Ary2D_u1p15_5_4 EotProtnLoAuthyEntrGainY_Ary2D_data;
  Ary1D_u12p4_2 EotProtnMotSpdIncptX_Ary1D_data;
  Ary1D_u12p4_2 EotProtnMotSpdIncptY_Ary1D_data;
  Ary2D_u0p16_4_2 EotProtnNormDampgY_Ary2D_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimPrevEotAssiSca = *TSC_EotProtn_Rte_Pim_PrevEotAssiSca();
  *TSC_EotProtn_Rte_Pim_PrevEotAssiSca() = PimPrevEotAssiSca;
  PimPrevEotDampg = *TSC_EotProtn_Rte_Pim_PrevEotDampg();
  *TSC_EotProtn_Rte_Pim_PrevEotDampg() = PimPrevEotDampg;
  PimPrevImpctPosn = *TSC_EotProtn_Rte_Pim_PrevImpctPosn();
  *TSC_EotProtn_Rte_Pim_PrevImpctPosn() = PimPrevImpctPosn;
  PimdEotProtnDampg = *TSC_EotProtn_Rte_Pim_dEotProtnDampg();
  *TSC_EotProtn_Rte_Pim_dEotProtnDampg() = PimdEotProtnDampg;
  PimdEotProtnEntrGain = *TSC_EotProtn_Rte_Pim_dEotProtnEntrGain();
  *TSC_EotProtn_Rte_Pim_dEotProtnEntrGain() = PimdEotProtnEntrGain;
  PimdEotProtnEotAssiSca = *TSC_EotProtn_Rte_Pim_dEotProtnEotAssiSca();
  *TSC_EotProtn_Rte_Pim_dEotProtnEotAssiSca() = PimdEotProtnEotAssiSca;
  PimdEotProtnEotGain = *TSC_EotProtn_Rte_Pim_dEotProtnEotGain();
  *TSC_EotProtn_Rte_Pim_dEotProtnEotGain() = PimdEotProtnEotGain;
  PimdEotProtnExitGain = *TSC_EotProtn_Rte_Pim_dEotProtnExitGain();
  *TSC_EotProtn_Rte_Pim_dEotProtnExitGain() = PimdEotProtnExitGain;
  PimdEotProtnLimPosn = *TSC_EotProtn_Rte_Pim_dEotProtnLimPosn();
  *TSC_EotProtn_Rte_Pim_dEotProtnLimPosn() = PimdEotProtnLimPosn;
  PimNewSoftEndStopSt = *TSC_EotProtn_Rte_Pim_NewSoftEndStopSt();
  *TSC_EotProtn_Rte_Pim_NewSoftEndStopSt() = PimNewSoftEndStopSt;
  PimPrevSoftEndStopSt = *TSC_EotProtn_Rte_Pim_PrevSoftEndStopSt();
  *TSC_EotProtn_Rte_Pim_PrevSoftEndStopSt() = PimPrevSoftEndStopSt;
  PimPrevRackTrvlLimrEna = *TSC_EotProtn_Rte_Pim_PrevRackTrvlLimrEna();
  *TSC_EotProtn_Rte_Pim_PrevRackTrvlLimrEna() = PimPrevRackTrvlLimrEna;
  PimPrevRackTrvlLimrInin = *TSC_EotProtn_Rte_Pim_PrevRackTrvlLimrInin();
  *TSC_EotProtn_Rte_Pim_PrevRackTrvlLimrInin() = PimPrevRackTrvlLimrInin;
  PimdEotProtnDetd = *TSC_EotProtn_Rte_Pim_dEotProtnDetd();
  *TSC_EotProtn_Rte_Pim_dEotProtnDetd() = PimdEotProtnDetd;
  PimdEotProtnRackTrvlLimrDi = *TSC_EotProtn_Rte_Pim_dEotProtnRackTrvlLimrDi();
  *TSC_EotProtn_Rte_Pim_dEotProtnRackTrvlLimrDi() = PimdEotProtnRackTrvlLimrDi;
  PimEotAssiScaLpFil = *TSC_EotProtn_Rte_Pim_EotAssiScaLpFil();
  *TSC_EotProtn_Rte_Pim_EotAssiScaLpFil() = PimEotAssiScaLpFil;
  PimHwTqLpFil = *TSC_EotProtn_Rte_Pim_HwTqLpFil();
  *TSC_EotProtn_Rte_Pim_HwTqLpFil() = PimHwTqLpFil;

  EotProtnActvRegnBypMaxThd_Val_data = TSC_EotProtn_Rte_Prm_EotProtnActvRegnBypMaxThd_Val();
  EotProtnDampgSlew_Val_data = TSC_EotProtn_Rte_Prm_EotProtnDampgSlew_Val();
  EotProtnDeltaTqThd_Val_data = TSC_EotProtn_Rte_Prm_EotProtnDeltaTqThd_Val();
  EotProtnDftPosn_Val_data = TSC_EotProtn_Rte_Prm_EotProtnDftPosn_Val();
  EotProtnEntrGainAuthyThd_Val_data = TSC_EotProtn_Rte_Prm_EotProtnEntrGainAuthyThd_Val();
  EotProtnEntrStLpFilFrq_Val_data = TSC_EotProtn_Rte_Prm_EotProtnEntrStLpFilFrq_Val();
  EotProtnExitStLpFilFrq_Val_data = TSC_EotProtn_Rte_Prm_EotProtnExitStLpFilFrq_Val();
  EotProtnHwAgGain_Val_data = TSC_EotProtn_Rte_Prm_EotProtnHwAgGain_Val();
  EotProtnHwAgMax_Val_data = TSC_EotProtn_Rte_Prm_EotProtnHwAgMax_Val();
  EotProtnHwAgMin_Val_data = TSC_EotProtn_Rte_Prm_EotProtnHwAgMin_Val();
  EotProtnHwTqLpFilFrq_Val_data = TSC_EotProtn_Rte_Prm_EotProtnHwTqLpFilFrq_Val();
  EotProtnMotSpdIncptSca_Val_data = TSC_EotProtn_Rte_Prm_EotProtnMotSpdIncptSca_Val();
  EotProtnMotVelGain_Val_data = TSC_EotProtn_Rte_Prm_EotProtnMotVelGain_Val();
  EotProtnPosnRampStep_Val_data = TSC_EotProtn_Rte_Prm_EotProtnPosnRampStep_Val();
  EotProtnRackTrvlLimrAuthyThd_Val_data = TSC_EotProtn_Rte_Prm_EotProtnRackTrvlLimrAuthyThd_Val();
  EotProtnRackTrvlLimrAuthyThdLimd_Val_data = TSC_EotProtn_Rte_Prm_EotProtnRackTrvlLimrAuthyThdLimd_Val();
  EotProtnRackTrvlLimrRng_Val_data = TSC_EotProtn_Rte_Prm_EotProtnRackTrvlLimrRng_Val();
  EotProtnRackTrvlLimrRngLimd_Val_data = TSC_EotProtn_Rte_Prm_EotProtnRackTrvlLimrRngLimd_Val();
  EotProtnRackTrvlLimrVehSpdThd_Val_data = TSC_EotProtn_Rte_Prm_EotProtnRackTrvlLimrVehSpdThd_Val();
  EotProtnSoftEndStopAuthyThd_Val_data = TSC_EotProtn_Rte_Prm_EotProtnSoftEndStopAuthyThd_Val();
  EotProtnSoftEndStopVehSpdThd_Val_data = TSC_EotProtn_Rte_Prm_EotProtnSoftEndStopVehSpdThd_Val();
  EotProtnRackTrvlLimrEna_Logl_data = TSC_EotProtn_Rte_Prm_EotProtnRackTrvlLimrEna_Logl();
  EotProtnRunEotVelImpctAndSoftEndStop_Logl_data = TSC_EotProtn_Rte_Prm_EotProtnRunEotVelImpctAndSoftEndStop_Logl();
  EotProtnSoftEndStopEna_Logl_data = TSC_EotProtn_Rte_Prm_EotProtnSoftEndStopEna_Logl();
  (void)memcpy(EotProtnDampgVehSpdTbl_Ary1D_data, TSC_EotProtn_Rte_Prm_EotProtnDampgVehSpdTbl_Ary1D(), sizeof(Ary1D_u9p7_4));
  (void)memcpy(EotProtnEntrGainVehSpdTbl_Ary1D_data, TSC_EotProtn_Rte_Prm_EotProtnEntrGainVehSpdTbl_Ary1D(), sizeof(Ary1D_u9p7_5));
  (void)memcpy(EotProtnEntrGainX_Ary2D_data, TSC_EotProtn_Rte_Prm_EotProtnEntrGainX_Ary2D(), sizeof(Ary2D_u12p4_5_4));
  (void)memcpy(EotProtnEntrGainY_Ary2D_data, TSC_EotProtn_Rte_Prm_EotProtnEntrGainY_Ary2D(), sizeof(Ary2D_u1p15_5_4));
  (void)memcpy(EotProtnExitDampgY_Ary2D_data, TSC_EotProtn_Rte_Prm_EotProtnExitDampgY_Ary2D(), sizeof(Ary2D_u0p16_4_2));
  (void)memcpy(EotProtnHwDegDampgX_Ary2D_data, TSC_EotProtn_Rte_Prm_EotProtnHwDegDampgX_Ary2D(), sizeof(Ary2D_u12p4_4_2));
  (void)memcpy(EotProtnHwTqScaX_Ary1D_data, TSC_EotProtn_Rte_Prm_EotProtnHwTqScaX_Ary1D(), sizeof(Ary1D_u4p12_2));
  (void)memcpy(EotProtnLoAuthyEntrGainY_Ary2D_data, TSC_EotProtn_Rte_Prm_EotProtnLoAuthyEntrGainY_Ary2D(), sizeof(Ary2D_u1p15_5_4));
  (void)memcpy(EotProtnMotSpdIncptX_Ary1D_data, TSC_EotProtn_Rte_Prm_EotProtnMotSpdIncptX_Ary1D(), sizeof(Ary1D_u12p4_2));
  (void)memcpy(EotProtnMotSpdIncptY_Ary1D_data, TSC_EotProtn_Rte_Prm_EotProtnMotSpdIncptY_Ary1D(), sizeof(Ary1D_u12p4_2));
  (void)memcpy(EotProtnNormDampgY_Ary2D_data, TSC_EotProtn_Rte_Prm_EotProtnNormDampgY_Ary2D(), sizeof(Ary2D_u0p16_4_2));

  fct_status = TSC_EotProtn_Rte_Read_EotProtnDi_Logl(&Read_EotProtnDi_Logl);
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

  fct_status = TSC_EotProtn_Rte_Read_HwAg_Val(&Read_HwAg_Val);
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

  fct_status = TSC_EotProtn_Rte_Read_HwAgAuthy_Val(&Read_HwAgAuthy_Val);
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

  fct_status = TSC_EotProtn_Rte_Read_HwAgCcwDetd_Logl(&Read_HwAgCcwDetd_Logl);
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

  fct_status = TSC_EotProtn_Rte_Read_HwAgCwDetd_Logl(&Read_HwAgCwDetd_Logl);
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

  fct_status = TSC_EotProtn_Rte_Read_HwAgEotCcw_Val(&Read_HwAgEotCcw_Val);
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

  fct_status = TSC_EotProtn_Rte_Read_HwAgEotCw_Val(&Read_HwAgEotCw_Val);
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

  fct_status = TSC_EotProtn_Rte_Read_HwTq_Val(&Read_HwTq_Val);
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

  fct_status = TSC_EotProtn_Rte_Read_MotVelCrf_Val(&Read_MotVelCrf_Val);
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

  fct_status = TSC_EotProtn_Rte_Read_SysMotTqCmdSca_Val(&Read_SysMotTqCmdSca_Val);
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

  fct_status = TSC_EotProtn_Rte_Read_VehSpd_Val(&Read_VehSpd_Val);
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

  fct_status = TSC_EotProtn_Rte_Write_EotActvCmd_Val(Rte_InitValue_EotActvCmd_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_EotProtn_Rte_Write_EotAssiSca_Val(Rte_InitValue_EotAssiSca_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_EotProtn_Rte_Write_EotDampgCmd_Val(Rte_InitValue_EotDampgCmd_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_EotProtn_Rte_Write_EotMotTqLim_Val(Rte_InitValue_EotMotTqLim_Val);
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


#define EotProtn_STOP_SEC_CODE
#include "EotProtn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


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
