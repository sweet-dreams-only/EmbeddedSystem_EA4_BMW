/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  CtrldVelRtn.c
 *        Config:  EPS.dpa
 *     SW-C Type:  CtrldVelRtn
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <CtrldVelRtn>
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
 * s10p5
 *   
 *
 * u10p6
 *   
 *
 * u12p4
 *   
 *
 * u2p14
 *   
 *
 * u4p12
 *   
 *
 * u6p10
 *   
 *
 * u8p8
 *   
 *
 * u9p7
 *   
 *
 *********************************************************************************************************************/

#include "Rte_CtrldVelRtn.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_CtrldVelRtn.h"


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
 * float32: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * float32: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * s10p5: Integer in interval [-32768...32767]
 * sint16: Integer in interval [-32768...32767] (standard type)
 * sint8: Integer in interval [-128...127] (standard type)
 * u10p6: Integer in interval [0...65535]
 * u12p4: Integer in interval [0...65535]
 * u2p14: Integer in interval [0...65535]
 * u4p12: Integer in interval [0...65535]
 * u6p10: Integer in interval [0...65535]
 * u8p8: Integer in interval [0...65535]
 * u9p7: Integer in interval [0...65535]
 * uint16: Integer in interval [0...65535] (standard type)
 *
 * Array Types:
 * ============
 * Ary1D_f32_4: Array with 4 element(s) of type float32
 * Ary1D_f32_5: Array with 5 element(s) of type float32
 * Ary1D_s10p5_8: Array with 8 element(s) of type s10p5
 * Ary1D_u10p6_12: Array with 12 element(s) of type u10p6
 * Ary1D_u10p6_9: Array with 9 element(s) of type u10p6
 * Ary1D_u12p4_12: Array with 12 element(s) of type u12p4
 * Ary1D_u12p4_7: Array with 7 element(s) of type u12p4
 * Ary1D_u12p4_9: Array with 9 element(s) of type u12p4
 * Ary1D_u2p14_10: Array with 10 element(s) of type u2p14
 * Ary1D_u2p14_4: Array with 4 element(s) of type u2p14
 * Ary1D_u2p14_5: Array with 5 element(s) of type u2p14
 * Ary1D_u2p14_8: Array with 8 element(s) of type u2p14
 * Ary1D_u2p14_9: Array with 9 element(s) of type u2p14
 * Ary1D_u4p12_8: Array with 8 element(s) of type u4p12
 * Ary1D_u6p10_9: Array with 9 element(s) of type u6p10
 * Ary1D_u8p8_10: Array with 10 element(s) of type u8p8
 * Ary1D_u8p8_8: Array with 8 element(s) of type u8p8
 * Ary1D_u9p7_5: Array with 5 element(s) of type u9p7
 * Ary1D_u9p7_8: Array with 8 element(s) of type u9p7
 * Ary2D_f32_5_4: Array with 5 element(s) of type Ary1D_f32_4
 * Ary2D_f32_5_5: Array with 5 element(s) of type Ary1D_f32_5
 * Ary2D_u10p6_8_12: Array with 8 element(s) of type Ary1D_u10p6_12
 * Ary2D_u10p6_8_9: Array with 8 element(s) of type Ary1D_u10p6_9
 * Ary2D_u12p4_8_12: Array with 8 element(s) of type Ary1D_u12p4_12
 * Ary2D_u2p14_5_10: Array with 5 element(s) of type Ary1D_u2p14_10
 * Ary2D_u2p14_5_8: Array with 5 element(s) of type Ary1D_u2p14_8
 * Ary2D_u2p14_7_8: Array with 7 element(s) of type Ary1D_u2p14_8
 * Ary2D_u6p10_5_9: Array with 5 element(s) of type Ary1D_u6p10_9
 * Ary2D_u6p10_8_9: Array with 8 element(s) of type Ary1D_u6p10_9
 * Ary2D_u8p8_5_10: Array with 5 element(s) of type Ary1D_u8p8_10
 * Ary2D_u8p8_5_8: Array with 5 element(s) of type Ary1D_u8p8_8
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
 *   float32 *Rte_Pim_PrevDesVel(void)
 *   float32 *Rte_Pim_PrevDrvrTqFildA(void)
 *   float32 *Rte_Pim_PrevDrvrTqFildB(void)
 *   float32 *Rte_Pim_PrevDrvrTqFildC(void)
 *   float32 *Rte_Pim_PrevDrvrTqFildD(void)
 *   float32 *Rte_Pim_PrevDrvrTqFildE(void)
 *   float32 *Rte_Pim_PrevDrvrTqFildF(void)
 *   float32 *Rte_Pim_PrevHwAuthySca(void)
 *   float32 *Rte_Pim_PrevHwTqSeln(void)
 *   float32 *Rte_Pim_PrevIntglTermA(void)
 *   float32 *Rte_Pim_PrevIntglTermB(void)
 *   float32 *Rte_Pim_PrevIntglTermC(void)
 *   float32 *Rte_Pim_PrevRtnOffs(void)
 *   float32 *Rte_Pim_dCtrldVelRtnCtrlSca(void)
 *   float32 *Rte_Pim_dCtrldVelRtnCtrlScaPreFild(void)
 *   float32 *Rte_Pim_dCtrldVelRtnDampgCmd(void)
 *   float32 *Rte_Pim_dCtrldVelRtnDesVel(void)
 *   float32 *Rte_Pim_dCtrldVelRtnDesVelSca(void)
 *   float32 *Rte_Pim_dCtrldVelRtnDesVelScaPreFild(void)
 *   float32 *Rte_Pim_dCtrldVelRtnDrvrTqEstimd(void)
 *   float32 *Rte_Pim_dCtrldVelRtnDrvrTqFild(void)
 *   float32 *Rte_Pim_dCtrldVelRtnHwAgCmp(void)
 *   float32 *Rte_Pim_dCtrldVelRtnHwAuthySca(void)
 *   float32 *Rte_Pim_dCtrldVelRtnHwPosnSca(void)
 *   float32 *Rte_Pim_dCtrldVelRtnHwTqSca(void)
 *   float32 *Rte_Pim_dCtrldVelRtnHwTqScaSeln(void)
 *   float32 *Rte_Pim_dCtrldVelRtnIntglTermCmd(void)
 *   float32 *Rte_Pim_dCtrldVelRtnIntgrLim(void)
 *   float32 *Rte_Pim_dCtrldVelRtnPinionTqSca(void)
 *   float32 *Rte_Pim_dCtrldVelRtnPropTermCmd(void)
 *   float32 *Rte_Pim_dCtrldVelRtnRtnCmd(void)
 *   float32 *Rte_Pim_dCtrldVelRtnRtnCmdPreLim(void)
 *   float32 *Rte_Pim_dCtrldVelRtnTqGrdt(void)
 *   float32 *Rte_Pim_dCtrldVelRtnTqGrdtSca(void)
 *   float32 *Rte_Pim_dCtrldVelRtnVelErrSca(void)
 *   float32 *Rte_Pim_PrevDrvrTqMtrx(void)
 *     Returnvalue: float32* is of type Ary1D_f32_5
 *   FilLpRec1 *Rte_Pim_CtrlScaLpFil(void)
 *   FilLpRec1 *Rte_Pim_DesVelLpFil(void)
 *   FilLpRec1 *Rte_Pim_DesVelScaLpFil(void)
 *   FilLpRec1 *Rte_Pim_DrvrTqLpFil(void)
 *   FilLpRec1 *Rte_Pim_PinionTqLpFil(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_CtrldVelRtnAntiWdup_Val(void)
 *   float32 Rte_Prm_CtrldVelRtnDesVelLpFilFrq_Val(void)
 *   float32 Rte_Prm_CtrldVelRtnHwAuthySlewThd_Val(void)
 *   float32 Rte_Prm_CtrldVelRtnHwTqLpFilFrq_Val(void)
 *   float32 Rte_Prm_CtrldVelRtnHwTqScaSelnSlewHiLim_Val(void)
 *   float32 Rte_Prm_CtrldVelRtnHwTqScaSelnSlewLoLim_Val(void)
 *   float32 Rte_Prm_CtrldVelRtnHwTqScaSelnTqThd_Val(void)
 *   float32 Rte_Prm_CtrldVelRtnHwTqScaSelnVelThd_Val(void)
 *   float32 Rte_Prm_CtrldVelRtnOffsSlewThd_Val(void)
 *   float32 Rte_Prm_CtrldVelRtnOffsThd_Val(void)
 *   float32 Rte_Prm_CtrldVelRtnScaLpFilFrq_Val(void)
 *   float32 Rte_Prm_SysGlbPrmSysTqRat_Val(void)
 *   boolean Rte_Prm_CtrldVelRtnDampgEna_Logl(void)
 *   boolean Rte_Prm_CtrldVelRtnDampgScaEna_Logl(void)
 *   boolean Rte_Prm_CtrldVelRtnDrvrTqEna_Logl(void)
 *   boolean Rte_Prm_CtrldVelRtnTqGrdtScaEna_Logl(void)
 *   boolean Rte_Prm_CtrldVelRtnVelErrScaEna_Logl(void)
 *   u10p6 *Rte_Prm_CtrldVelRtnDampgX_Ary2D(void)
 *     Returnvalue: u10p6* is of type Ary2D_u10p6_8_9
 *   u6p10 *Rte_Prm_CtrldVelRtnDampgY_Ary2D(void)
 *     Returnvalue: u6p10* is of type Ary2D_u6p10_8_9
 *   u8p8 *Rte_Prm_CtrldVelRtnDesVelScaX_Ary2D(void)
 *     Returnvalue: u8p8* is of type Ary2D_u8p8_5_8
 *   u2p14 *Rte_Prm_CtrldVelRtnDesVelScaY_Ary2D(void)
 *     Returnvalue: u2p14* is of type Ary2D_u2p14_5_8
 *   u12p4 *Rte_Prm_CtrldVelRtnDesVelX_Ary2D(void)
 *     Returnvalue: u12p4* is of type Ary2D_u12p4_8_12
 *   u10p6 *Rte_Prm_CtrldVelRtnDesVelY_Ary2D(void)
 *     Returnvalue: u10p6* is of type Ary2D_u10p6_8_12
 *   float32 *Rte_Prm_CtrldVelRtnDrvrTqMtrxA_Ary2D(void)
 *     Returnvalue: float32* is of type Ary2D_f32_5_5
 *   float32 *Rte_Prm_CtrldVelRtnDrvrTqMtrxB_Ary2D(void)
 *     Returnvalue: float32* is of type Ary2D_f32_5_4
 *   float32 *Rte_Prm_CtrldVelRtnDrvrTqMtrxC_Ary1D(void)
 *     Returnvalue: float32* is of type Ary1D_f32_5
 *   float32 *Rte_Prm_CtrldVelRtnDrvrTqMtrxD_Ary1D(void)
 *     Returnvalue: float32* is of type Ary1D_f32_4
 *   u2p14 *Rte_Prm_CtrldVelRtnHwAuthyScaX_Ary1D(void)
 *     Returnvalue: u2p14* is of type Ary1D_u2p14_4
 *   u2p14 *Rte_Prm_CtrldVelRtnHwAuthyScaY_Ary1D(void)
 *     Returnvalue: u2p14* is of type Ary1D_u2p14_4
 *   u12p4 *Rte_Prm_CtrldVelRtnHwPosnScaX_Ary1D(void)
 *     Returnvalue: u12p4* is of type Ary1D_u12p4_9
 *   u2p14 *Rte_Prm_CtrldVelRtnHwPosnScaY_Ary1D(void)
 *     Returnvalue: u2p14* is of type Ary1D_u2p14_9
 *   u8p8 *Rte_Prm_CtrldVelRtnHwTqSca1X_Ary2D(void)
 *     Returnvalue: u8p8* is of type Ary2D_u8p8_5_10
 *   u2p14 *Rte_Prm_CtrldVelRtnHwTqSca1Y_Ary2D(void)
 *     Returnvalue: u2p14* is of type Ary2D_u2p14_5_10
 *   u8p8 *Rte_Prm_CtrldVelRtnHwTqSca2X_Ary2D(void)
 *     Returnvalue: u8p8* is of type Ary2D_u8p8_5_10
 *   u2p14 *Rte_Prm_CtrldVelRtnHwTqSca2Y_Ary2D(void)
 *     Returnvalue: u2p14* is of type Ary2D_u2p14_5_10
 *   u8p8 *Rte_Prm_CtrldVelRtnIntglGain_Ary1D(void)
 *     Returnvalue: u8p8* is of type Ary1D_u8p8_8
 *   u6p10 *Rte_Prm_CtrldVelRtnIntgrLimY_Ary2D(void)
 *     Returnvalue: u6p10* is of type Ary2D_u6p10_5_9
 *   u8p8 *Rte_Prm_CtrldVelRtnPinionTqScaX_Ary2D(void)
 *     Returnvalue: u8p8* is of type Ary2D_u8p8_5_8
 *   u2p14 *Rte_Prm_CtrldVelRtnPinionTqScaY_Ary2D(void)
 *     Returnvalue: u2p14* is of type Ary2D_u2p14_5_8
 *   u4p12 *Rte_Prm_CtrldVelRtnPropGain_Ary1D(void)
 *     Returnvalue: u4p12* is of type Ary1D_u4p12_8
 *   u4p12 *Rte_Prm_CtrldVelRtnRtnCmdLimY_Ary1D(void)
 *     Returnvalue: u4p12* is of type Ary1D_u4p12_8
 *   u8p8 *Rte_Prm_CtrldVelRtnTqGrdtScaX_Ary2D(void)
 *     Returnvalue: u8p8* is of type Ary2D_u8p8_5_8
 *   u2p14 *Rte_Prm_CtrldVelRtnTqGrdtScaY_Ary2D(void)
 *     Returnvalue: u2p14* is of type Ary2D_u2p14_5_8
 *   u9p7 *Rte_Prm_CtrldVelRtnVehSpdScaBilnrSeln_Ary1D(void)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_5
 *   u12p4 *Rte_Prm_CtrldVelRtnVelErrScaBilnrSeln_Ary1D(void)
 *     Returnvalue: u12p4* is of type Ary1D_u12p4_7
 *   s10p5 *Rte_Prm_CtrldVelRtnVelErrScaX_Ary1D(void)
 *     Returnvalue: s10p5* is of type Ary1D_s10p5_8
 *   u2p14 *Rte_Prm_CtrldVelRtnVelErrScaY_Ary2D(void)
 *     Returnvalue: u2p14* is of type Ary2D_u2p14_7_8
 *   u2p14 *Rte_Prm_CtrldVelRtnVelErrVehSpdScaY_Ary1D(void)
 *     Returnvalue: u2p14* is of type Ary1D_u2p14_5
 *   u9p7 *Rte_Prm_CtrldVelRtnVelSpdTbl_Ary1D(void)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_8
 *
 *********************************************************************************************************************/


#define CtrldVelRtn_START_SEC_CODE
#include "CtrldVelRtn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CtrldVelRtnInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CtrldVelRtnInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CtrldVelRtn_CODE) CtrldVelRtnInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CtrldVelRtnInit1
 *********************************************************************************************************************/

  float32 PimPrevDesVel;
  float32 PimPrevDrvrTqFildA;
  float32 PimPrevDrvrTqFildB;
  float32 PimPrevDrvrTqFildC;
  float32 PimPrevDrvrTqFildD;
  float32 PimPrevDrvrTqFildE;
  float32 PimPrevDrvrTqFildF;
  float32 PimPrevHwAuthySca;
  float32 PimPrevHwTqSeln;
  float32 PimPrevIntglTermA;
  float32 PimPrevIntglTermB;
  float32 PimPrevIntglTermC;
  float32 PimPrevRtnOffs;
  float32 PimdCtrldVelRtnCtrlSca;
  float32 PimdCtrldVelRtnCtrlScaPreFild;
  float32 PimdCtrldVelRtnDampgCmd;
  float32 PimdCtrldVelRtnDesVel;
  float32 PimdCtrldVelRtnDesVelSca;
  float32 PimdCtrldVelRtnDesVelScaPreFild;
  float32 PimdCtrldVelRtnDrvrTqEstimd;
  float32 PimdCtrldVelRtnDrvrTqFild;
  float32 PimdCtrldVelRtnHwAgCmp;
  float32 PimdCtrldVelRtnHwAuthySca;
  float32 PimdCtrldVelRtnHwPosnSca;
  float32 PimdCtrldVelRtnHwTqSca;
  float32 PimdCtrldVelRtnHwTqScaSeln;
  float32 PimdCtrldVelRtnIntglTermCmd;
  float32 PimdCtrldVelRtnIntgrLim;
  float32 PimdCtrldVelRtnPinionTqSca;
  float32 PimdCtrldVelRtnPropTermCmd;
  float32 PimdCtrldVelRtnRtnCmd;
  float32 PimdCtrldVelRtnRtnCmdPreLim;
  float32 PimdCtrldVelRtnTqGrdt;
  float32 PimdCtrldVelRtnTqGrdtSca;
  float32 PimdCtrldVelRtnVelErrSca;
  Ary1D_f32_5 PimPrevDrvrTqMtrx;
  FilLpRec1 PimCtrlScaLpFil;
  FilLpRec1 PimDesVelLpFil;
  FilLpRec1 PimDesVelScaLpFil;
  FilLpRec1 PimDrvrTqLpFil;
  FilLpRec1 PimPinionTqLpFil;

  float32 CtrldVelRtnAntiWdup_Val_data;
  float32 CtrldVelRtnDesVelLpFilFrq_Val_data;
  float32 CtrldVelRtnHwAuthySlewThd_Val_data;
  float32 CtrldVelRtnHwTqLpFilFrq_Val_data;
  float32 CtrldVelRtnHwTqScaSelnSlewHiLim_Val_data;
  float32 CtrldVelRtnHwTqScaSelnSlewLoLim_Val_data;
  float32 CtrldVelRtnHwTqScaSelnTqThd_Val_data;
  float32 CtrldVelRtnHwTqScaSelnVelThd_Val_data;
  float32 CtrldVelRtnOffsSlewThd_Val_data;
  float32 CtrldVelRtnOffsThd_Val_data;
  float32 CtrldVelRtnScaLpFilFrq_Val_data;
  float32 SysGlbPrmSysTqRat_Val_data;
  boolean CtrldVelRtnDampgEna_Logl_data;
  boolean CtrldVelRtnDampgScaEna_Logl_data;
  boolean CtrldVelRtnDrvrTqEna_Logl_data;
  boolean CtrldVelRtnTqGrdtScaEna_Logl_data;
  boolean CtrldVelRtnVelErrScaEna_Logl_data;
  Ary2D_u10p6_8_9 CtrldVelRtnDampgX_Ary2D_data;
  Ary2D_u6p10_8_9 CtrldVelRtnDampgY_Ary2D_data;
  Ary2D_u8p8_5_8 CtrldVelRtnDesVelScaX_Ary2D_data;
  Ary2D_u2p14_5_8 CtrldVelRtnDesVelScaY_Ary2D_data;
  Ary2D_u12p4_8_12 CtrldVelRtnDesVelX_Ary2D_data;
  Ary2D_u10p6_8_12 CtrldVelRtnDesVelY_Ary2D_data;
  Ary2D_f32_5_5 CtrldVelRtnDrvrTqMtrxA_Ary2D_data;
  Ary2D_f32_5_4 CtrldVelRtnDrvrTqMtrxB_Ary2D_data;
  Ary1D_f32_5 CtrldVelRtnDrvrTqMtrxC_Ary1D_data;
  Ary1D_f32_4 CtrldVelRtnDrvrTqMtrxD_Ary1D_data;
  Ary1D_u2p14_4 CtrldVelRtnHwAuthyScaX_Ary1D_data;
  Ary1D_u2p14_4 CtrldVelRtnHwAuthyScaY_Ary1D_data;
  Ary1D_u12p4_9 CtrldVelRtnHwPosnScaX_Ary1D_data;
  Ary1D_u2p14_9 CtrldVelRtnHwPosnScaY_Ary1D_data;
  Ary2D_u8p8_5_10 CtrldVelRtnHwTqSca1X_Ary2D_data;
  Ary2D_u2p14_5_10 CtrldVelRtnHwTqSca1Y_Ary2D_data;
  Ary2D_u8p8_5_10 CtrldVelRtnHwTqSca2X_Ary2D_data;
  Ary2D_u2p14_5_10 CtrldVelRtnHwTqSca2Y_Ary2D_data;
  Ary1D_u8p8_8 CtrldVelRtnIntglGain_Ary1D_data;
  Ary2D_u6p10_5_9 CtrldVelRtnIntgrLimY_Ary2D_data;
  Ary2D_u8p8_5_8 CtrldVelRtnPinionTqScaX_Ary2D_data;
  Ary2D_u2p14_5_8 CtrldVelRtnPinionTqScaY_Ary2D_data;
  Ary1D_u4p12_8 CtrldVelRtnPropGain_Ary1D_data;
  Ary1D_u4p12_8 CtrldVelRtnRtnCmdLimY_Ary1D_data;
  Ary2D_u8p8_5_8 CtrldVelRtnTqGrdtScaX_Ary2D_data;
  Ary2D_u2p14_5_8 CtrldVelRtnTqGrdtScaY_Ary2D_data;
  Ary1D_u9p7_5 CtrldVelRtnVehSpdScaBilnrSeln_Ary1D_data;
  Ary1D_u12p4_7 CtrldVelRtnVelErrScaBilnrSeln_Ary1D_data;
  Ary1D_s10p5_8 CtrldVelRtnVelErrScaX_Ary1D_data;
  Ary2D_u2p14_7_8 CtrldVelRtnVelErrScaY_Ary2D_data;
  Ary1D_u2p14_5 CtrldVelRtnVelErrVehSpdScaY_Ary1D_data;
  Ary1D_u9p7_8 CtrldVelRtnVelSpdTbl_Ary1D_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimPrevDesVel = *TSC_CtrldVelRtn_Rte_Pim_PrevDesVel();
  *TSC_CtrldVelRtn_Rte_Pim_PrevDesVel() = PimPrevDesVel;
  PimPrevDrvrTqFildA = *TSC_CtrldVelRtn_Rte_Pim_PrevDrvrTqFildA();
  *TSC_CtrldVelRtn_Rte_Pim_PrevDrvrTqFildA() = PimPrevDrvrTqFildA;
  PimPrevDrvrTqFildB = *TSC_CtrldVelRtn_Rte_Pim_PrevDrvrTqFildB();
  *TSC_CtrldVelRtn_Rte_Pim_PrevDrvrTqFildB() = PimPrevDrvrTqFildB;
  PimPrevDrvrTqFildC = *TSC_CtrldVelRtn_Rte_Pim_PrevDrvrTqFildC();
  *TSC_CtrldVelRtn_Rte_Pim_PrevDrvrTqFildC() = PimPrevDrvrTqFildC;
  PimPrevDrvrTqFildD = *TSC_CtrldVelRtn_Rte_Pim_PrevDrvrTqFildD();
  *TSC_CtrldVelRtn_Rte_Pim_PrevDrvrTqFildD() = PimPrevDrvrTqFildD;
  PimPrevDrvrTqFildE = *TSC_CtrldVelRtn_Rte_Pim_PrevDrvrTqFildE();
  *TSC_CtrldVelRtn_Rte_Pim_PrevDrvrTqFildE() = PimPrevDrvrTqFildE;
  PimPrevDrvrTqFildF = *TSC_CtrldVelRtn_Rte_Pim_PrevDrvrTqFildF();
  *TSC_CtrldVelRtn_Rte_Pim_PrevDrvrTqFildF() = PimPrevDrvrTqFildF;
  PimPrevHwAuthySca = *TSC_CtrldVelRtn_Rte_Pim_PrevHwAuthySca();
  *TSC_CtrldVelRtn_Rte_Pim_PrevHwAuthySca() = PimPrevHwAuthySca;
  PimPrevHwTqSeln = *TSC_CtrldVelRtn_Rte_Pim_PrevHwTqSeln();
  *TSC_CtrldVelRtn_Rte_Pim_PrevHwTqSeln() = PimPrevHwTqSeln;
  PimPrevIntglTermA = *TSC_CtrldVelRtn_Rte_Pim_PrevIntglTermA();
  *TSC_CtrldVelRtn_Rte_Pim_PrevIntglTermA() = PimPrevIntglTermA;
  PimPrevIntglTermB = *TSC_CtrldVelRtn_Rte_Pim_PrevIntglTermB();
  *TSC_CtrldVelRtn_Rte_Pim_PrevIntglTermB() = PimPrevIntglTermB;
  PimPrevIntglTermC = *TSC_CtrldVelRtn_Rte_Pim_PrevIntglTermC();
  *TSC_CtrldVelRtn_Rte_Pim_PrevIntglTermC() = PimPrevIntglTermC;
  PimPrevRtnOffs = *TSC_CtrldVelRtn_Rte_Pim_PrevRtnOffs();
  *TSC_CtrldVelRtn_Rte_Pim_PrevRtnOffs() = PimPrevRtnOffs;
  PimdCtrldVelRtnCtrlSca = *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnCtrlSca();
  *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnCtrlSca() = PimdCtrldVelRtnCtrlSca;
  PimdCtrldVelRtnCtrlScaPreFild = *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnCtrlScaPreFild();
  *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnCtrlScaPreFild() = PimdCtrldVelRtnCtrlScaPreFild;
  PimdCtrldVelRtnDampgCmd = *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnDampgCmd();
  *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnDampgCmd() = PimdCtrldVelRtnDampgCmd;
  PimdCtrldVelRtnDesVel = *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnDesVel();
  *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnDesVel() = PimdCtrldVelRtnDesVel;
  PimdCtrldVelRtnDesVelSca = *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnDesVelSca();
  *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnDesVelSca() = PimdCtrldVelRtnDesVelSca;
  PimdCtrldVelRtnDesVelScaPreFild = *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnDesVelScaPreFild();
  *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnDesVelScaPreFild() = PimdCtrldVelRtnDesVelScaPreFild;
  PimdCtrldVelRtnDrvrTqEstimd = *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnDrvrTqEstimd();
  *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnDrvrTqEstimd() = PimdCtrldVelRtnDrvrTqEstimd;
  PimdCtrldVelRtnDrvrTqFild = *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnDrvrTqFild();
  *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnDrvrTqFild() = PimdCtrldVelRtnDrvrTqFild;
  PimdCtrldVelRtnHwAgCmp = *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnHwAgCmp();
  *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnHwAgCmp() = PimdCtrldVelRtnHwAgCmp;
  PimdCtrldVelRtnHwAuthySca = *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnHwAuthySca();
  *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnHwAuthySca() = PimdCtrldVelRtnHwAuthySca;
  PimdCtrldVelRtnHwPosnSca = *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnHwPosnSca();
  *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnHwPosnSca() = PimdCtrldVelRtnHwPosnSca;
  PimdCtrldVelRtnHwTqSca = *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnHwTqSca();
  *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnHwTqSca() = PimdCtrldVelRtnHwTqSca;
  PimdCtrldVelRtnHwTqScaSeln = *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnHwTqScaSeln();
  *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnHwTqScaSeln() = PimdCtrldVelRtnHwTqScaSeln;
  PimdCtrldVelRtnIntglTermCmd = *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnIntglTermCmd();
  *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnIntglTermCmd() = PimdCtrldVelRtnIntglTermCmd;
  PimdCtrldVelRtnIntgrLim = *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnIntgrLim();
  *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnIntgrLim() = PimdCtrldVelRtnIntgrLim;
  PimdCtrldVelRtnPinionTqSca = *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnPinionTqSca();
  *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnPinionTqSca() = PimdCtrldVelRtnPinionTqSca;
  PimdCtrldVelRtnPropTermCmd = *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnPropTermCmd();
  *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnPropTermCmd() = PimdCtrldVelRtnPropTermCmd;
  PimdCtrldVelRtnRtnCmd = *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnRtnCmd();
  *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnRtnCmd() = PimdCtrldVelRtnRtnCmd;
  PimdCtrldVelRtnRtnCmdPreLim = *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnRtnCmdPreLim();
  *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnRtnCmdPreLim() = PimdCtrldVelRtnRtnCmdPreLim;
  PimdCtrldVelRtnTqGrdt = *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnTqGrdt();
  *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnTqGrdt() = PimdCtrldVelRtnTqGrdt;
  PimdCtrldVelRtnTqGrdtSca = *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnTqGrdtSca();
  *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnTqGrdtSca() = PimdCtrldVelRtnTqGrdtSca;
  PimdCtrldVelRtnVelErrSca = *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnVelErrSca();
  *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnVelErrSca() = PimdCtrldVelRtnVelErrSca;

  (void)memcpy(PimPrevDrvrTqMtrx, TSC_CtrldVelRtn_Rte_Pim_PrevDrvrTqMtrx(), sizeof(Ary1D_f32_5));
  (void)memcpy(TSC_CtrldVelRtn_Rte_Pim_PrevDrvrTqMtrx(), PimPrevDrvrTqMtrx, sizeof(Ary1D_f32_5));

  PimCtrlScaLpFil = *TSC_CtrldVelRtn_Rte_Pim_CtrlScaLpFil();
  *TSC_CtrldVelRtn_Rte_Pim_CtrlScaLpFil() = PimCtrlScaLpFil;
  PimDesVelLpFil = *TSC_CtrldVelRtn_Rte_Pim_DesVelLpFil();
  *TSC_CtrldVelRtn_Rte_Pim_DesVelLpFil() = PimDesVelLpFil;
  PimDesVelScaLpFil = *TSC_CtrldVelRtn_Rte_Pim_DesVelScaLpFil();
  *TSC_CtrldVelRtn_Rte_Pim_DesVelScaLpFil() = PimDesVelScaLpFil;
  PimDrvrTqLpFil = *TSC_CtrldVelRtn_Rte_Pim_DrvrTqLpFil();
  *TSC_CtrldVelRtn_Rte_Pim_DrvrTqLpFil() = PimDrvrTqLpFil;
  PimPinionTqLpFil = *TSC_CtrldVelRtn_Rte_Pim_PinionTqLpFil();
  *TSC_CtrldVelRtn_Rte_Pim_PinionTqLpFil() = PimPinionTqLpFil;

  CtrldVelRtnAntiWdup_Val_data = TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnAntiWdup_Val();
  CtrldVelRtnDesVelLpFilFrq_Val_data = TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnDesVelLpFilFrq_Val();
  CtrldVelRtnHwAuthySlewThd_Val_data = TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnHwAuthySlewThd_Val();
  CtrldVelRtnHwTqLpFilFrq_Val_data = TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnHwTqLpFilFrq_Val();
  CtrldVelRtnHwTqScaSelnSlewHiLim_Val_data = TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnHwTqScaSelnSlewHiLim_Val();
  CtrldVelRtnHwTqScaSelnSlewLoLim_Val_data = TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnHwTqScaSelnSlewLoLim_Val();
  CtrldVelRtnHwTqScaSelnTqThd_Val_data = TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnHwTqScaSelnTqThd_Val();
  CtrldVelRtnHwTqScaSelnVelThd_Val_data = TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnHwTqScaSelnVelThd_Val();
  CtrldVelRtnOffsSlewThd_Val_data = TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnOffsSlewThd_Val();
  CtrldVelRtnOffsThd_Val_data = TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnOffsThd_Val();
  CtrldVelRtnScaLpFilFrq_Val_data = TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnScaLpFilFrq_Val();
  SysGlbPrmSysTqRat_Val_data = TSC_CtrldVelRtn_Rte_Prm_SysGlbPrmSysTqRat_Val();
  CtrldVelRtnDampgEna_Logl_data = TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnDampgEna_Logl();
  CtrldVelRtnDampgScaEna_Logl_data = TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnDampgScaEna_Logl();
  CtrldVelRtnDrvrTqEna_Logl_data = TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnDrvrTqEna_Logl();
  CtrldVelRtnTqGrdtScaEna_Logl_data = TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnTqGrdtScaEna_Logl();
  CtrldVelRtnVelErrScaEna_Logl_data = TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnVelErrScaEna_Logl();
  (void)memcpy(CtrldVelRtnDampgX_Ary2D_data, TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnDampgX_Ary2D(), sizeof(Ary2D_u10p6_8_9));
  (void)memcpy(CtrldVelRtnDampgY_Ary2D_data, TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnDampgY_Ary2D(), sizeof(Ary2D_u6p10_8_9));
  (void)memcpy(CtrldVelRtnDesVelScaX_Ary2D_data, TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnDesVelScaX_Ary2D(), sizeof(Ary2D_u8p8_5_8));
  (void)memcpy(CtrldVelRtnDesVelScaY_Ary2D_data, TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnDesVelScaY_Ary2D(), sizeof(Ary2D_u2p14_5_8));
  (void)memcpy(CtrldVelRtnDesVelX_Ary2D_data, TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnDesVelX_Ary2D(), sizeof(Ary2D_u12p4_8_12));
  (void)memcpy(CtrldVelRtnDesVelY_Ary2D_data, TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnDesVelY_Ary2D(), sizeof(Ary2D_u10p6_8_12));
  (void)memcpy(CtrldVelRtnDrvrTqMtrxA_Ary2D_data, TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnDrvrTqMtrxA_Ary2D(), sizeof(Ary2D_f32_5_5));
  (void)memcpy(CtrldVelRtnDrvrTqMtrxB_Ary2D_data, TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnDrvrTqMtrxB_Ary2D(), sizeof(Ary2D_f32_5_4));
  (void)memcpy(CtrldVelRtnDrvrTqMtrxC_Ary1D_data, TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnDrvrTqMtrxC_Ary1D(), sizeof(Ary1D_f32_5));
  (void)memcpy(CtrldVelRtnDrvrTqMtrxD_Ary1D_data, TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnDrvrTqMtrxD_Ary1D(), sizeof(Ary1D_f32_4));
  (void)memcpy(CtrldVelRtnHwAuthyScaX_Ary1D_data, TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnHwAuthyScaX_Ary1D(), sizeof(Ary1D_u2p14_4));
  (void)memcpy(CtrldVelRtnHwAuthyScaY_Ary1D_data, TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnHwAuthyScaY_Ary1D(), sizeof(Ary1D_u2p14_4));
  (void)memcpy(CtrldVelRtnHwPosnScaX_Ary1D_data, TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnHwPosnScaX_Ary1D(), sizeof(Ary1D_u12p4_9));
  (void)memcpy(CtrldVelRtnHwPosnScaY_Ary1D_data, TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnHwPosnScaY_Ary1D(), sizeof(Ary1D_u2p14_9));
  (void)memcpy(CtrldVelRtnHwTqSca1X_Ary2D_data, TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnHwTqSca1X_Ary2D(), sizeof(Ary2D_u8p8_5_10));
  (void)memcpy(CtrldVelRtnHwTqSca1Y_Ary2D_data, TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnHwTqSca1Y_Ary2D(), sizeof(Ary2D_u2p14_5_10));
  (void)memcpy(CtrldVelRtnHwTqSca2X_Ary2D_data, TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnHwTqSca2X_Ary2D(), sizeof(Ary2D_u8p8_5_10));
  (void)memcpy(CtrldVelRtnHwTqSca2Y_Ary2D_data, TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnHwTqSca2Y_Ary2D(), sizeof(Ary2D_u2p14_5_10));
  (void)memcpy(CtrldVelRtnIntglGain_Ary1D_data, TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnIntglGain_Ary1D(), sizeof(Ary1D_u8p8_8));
  (void)memcpy(CtrldVelRtnIntgrLimY_Ary2D_data, TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnIntgrLimY_Ary2D(), sizeof(Ary2D_u6p10_5_9));
  (void)memcpy(CtrldVelRtnPinionTqScaX_Ary2D_data, TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnPinionTqScaX_Ary2D(), sizeof(Ary2D_u8p8_5_8));
  (void)memcpy(CtrldVelRtnPinionTqScaY_Ary2D_data, TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnPinionTqScaY_Ary2D(), sizeof(Ary2D_u2p14_5_8));
  (void)memcpy(CtrldVelRtnPropGain_Ary1D_data, TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnPropGain_Ary1D(), sizeof(Ary1D_u4p12_8));
  (void)memcpy(CtrldVelRtnRtnCmdLimY_Ary1D_data, TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnRtnCmdLimY_Ary1D(), sizeof(Ary1D_u4p12_8));
  (void)memcpy(CtrldVelRtnTqGrdtScaX_Ary2D_data, TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnTqGrdtScaX_Ary2D(), sizeof(Ary2D_u8p8_5_8));
  (void)memcpy(CtrldVelRtnTqGrdtScaY_Ary2D_data, TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnTqGrdtScaY_Ary2D(), sizeof(Ary2D_u2p14_5_8));
  (void)memcpy(CtrldVelRtnVehSpdScaBilnrSeln_Ary1D_data, TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnVehSpdScaBilnrSeln_Ary1D(), sizeof(Ary1D_u9p7_5));
  (void)memcpy(CtrldVelRtnVelErrScaBilnrSeln_Ary1D_data, TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnVelErrScaBilnrSeln_Ary1D(), sizeof(Ary1D_u12p4_7));
  (void)memcpy(CtrldVelRtnVelErrScaX_Ary1D_data, TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnVelErrScaX_Ary1D(), sizeof(Ary1D_s10p5_8));
  (void)memcpy(CtrldVelRtnVelErrScaY_Ary2D_data, TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnVelErrScaY_Ary2D(), sizeof(Ary2D_u2p14_7_8));
  (void)memcpy(CtrldVelRtnVelErrVehSpdScaY_Ary1D_data, TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnVelErrVehSpdScaY_Ary1D(), sizeof(Ary1D_u2p14_5));
  (void)memcpy(CtrldVelRtnVelSpdTbl_Ary1D_data, TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnVelSpdTbl_Ary1D(), sizeof(Ary1D_u9p7_8));


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CtrldVelRtnPer1
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
 *   Std_ReturnType Rte_Read_HwAg_Val(float32 *data)
 *   Std_ReturnType Rte_Read_HwAgAuthy_Val(float32 *data)
 *   Std_ReturnType Rte_Read_HwAgRtnOffs_Val(float32 *data)
 *   Std_ReturnType Rte_Read_HwTq_Val(float32 *data)
 *   Std_ReturnType Rte_Read_HwVel_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotTqCmdPwrLimd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_RtnCmdDi_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_RtnCmdDiagcDi_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_RtnCmdSca_Val(float32 *data)
 *   Std_ReturnType Rte_Read_RtnCmdScaServo_Val(float32 *data)
 *   Std_ReturnType Rte_Read_VehSpd_Val(float32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_CtrldVelRtnCmd_Val(float32 data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CtrldVelRtnPer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CtrldVelRtn_CODE) CtrldVelRtnPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CtrldVelRtnPer1
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  sint8 Read_AssiMechPolarity_Val;
  float32 Read_HwAg_Val;
  float32 Read_HwAgAuthy_Val;
  float32 Read_HwAgRtnOffs_Val;
  float32 Read_HwTq_Val;
  float32 Read_HwVel_Val;
  float32 Read_MotTqCmdPwrLimd_Val;
  boolean Read_RtnCmdDi_Logl;
  boolean Read_RtnCmdDiagcDi_Logl;
  float32 Read_RtnCmdSca_Val;
  float32 Read_RtnCmdScaServo_Val;
  float32 Read_VehSpd_Val;

  float32 PimPrevDesVel;
  float32 PimPrevDrvrTqFildA;
  float32 PimPrevDrvrTqFildB;
  float32 PimPrevDrvrTqFildC;
  float32 PimPrevDrvrTqFildD;
  float32 PimPrevDrvrTqFildE;
  float32 PimPrevDrvrTqFildF;
  float32 PimPrevHwAuthySca;
  float32 PimPrevHwTqSeln;
  float32 PimPrevIntglTermA;
  float32 PimPrevIntglTermB;
  float32 PimPrevIntglTermC;
  float32 PimPrevRtnOffs;
  float32 PimdCtrldVelRtnCtrlSca;
  float32 PimdCtrldVelRtnCtrlScaPreFild;
  float32 PimdCtrldVelRtnDampgCmd;
  float32 PimdCtrldVelRtnDesVel;
  float32 PimdCtrldVelRtnDesVelSca;
  float32 PimdCtrldVelRtnDesVelScaPreFild;
  float32 PimdCtrldVelRtnDrvrTqEstimd;
  float32 PimdCtrldVelRtnDrvrTqFild;
  float32 PimdCtrldVelRtnHwAgCmp;
  float32 PimdCtrldVelRtnHwAuthySca;
  float32 PimdCtrldVelRtnHwPosnSca;
  float32 PimdCtrldVelRtnHwTqSca;
  float32 PimdCtrldVelRtnHwTqScaSeln;
  float32 PimdCtrldVelRtnIntglTermCmd;
  float32 PimdCtrldVelRtnIntgrLim;
  float32 PimdCtrldVelRtnPinionTqSca;
  float32 PimdCtrldVelRtnPropTermCmd;
  float32 PimdCtrldVelRtnRtnCmd;
  float32 PimdCtrldVelRtnRtnCmdPreLim;
  float32 PimdCtrldVelRtnTqGrdt;
  float32 PimdCtrldVelRtnTqGrdtSca;
  float32 PimdCtrldVelRtnVelErrSca;
  Ary1D_f32_5 PimPrevDrvrTqMtrx;
  FilLpRec1 PimCtrlScaLpFil;
  FilLpRec1 PimDesVelLpFil;
  FilLpRec1 PimDesVelScaLpFil;
  FilLpRec1 PimDrvrTqLpFil;
  FilLpRec1 PimPinionTqLpFil;

  float32 CtrldVelRtnAntiWdup_Val_data;
  float32 CtrldVelRtnDesVelLpFilFrq_Val_data;
  float32 CtrldVelRtnHwAuthySlewThd_Val_data;
  float32 CtrldVelRtnHwTqLpFilFrq_Val_data;
  float32 CtrldVelRtnHwTqScaSelnSlewHiLim_Val_data;
  float32 CtrldVelRtnHwTqScaSelnSlewLoLim_Val_data;
  float32 CtrldVelRtnHwTqScaSelnTqThd_Val_data;
  float32 CtrldVelRtnHwTqScaSelnVelThd_Val_data;
  float32 CtrldVelRtnOffsSlewThd_Val_data;
  float32 CtrldVelRtnOffsThd_Val_data;
  float32 CtrldVelRtnScaLpFilFrq_Val_data;
  float32 SysGlbPrmSysTqRat_Val_data;
  boolean CtrldVelRtnDampgEna_Logl_data;
  boolean CtrldVelRtnDampgScaEna_Logl_data;
  boolean CtrldVelRtnDrvrTqEna_Logl_data;
  boolean CtrldVelRtnTqGrdtScaEna_Logl_data;
  boolean CtrldVelRtnVelErrScaEna_Logl_data;
  Ary2D_u10p6_8_9 CtrldVelRtnDampgX_Ary2D_data;
  Ary2D_u6p10_8_9 CtrldVelRtnDampgY_Ary2D_data;
  Ary2D_u8p8_5_8 CtrldVelRtnDesVelScaX_Ary2D_data;
  Ary2D_u2p14_5_8 CtrldVelRtnDesVelScaY_Ary2D_data;
  Ary2D_u12p4_8_12 CtrldVelRtnDesVelX_Ary2D_data;
  Ary2D_u10p6_8_12 CtrldVelRtnDesVelY_Ary2D_data;
  Ary2D_f32_5_5 CtrldVelRtnDrvrTqMtrxA_Ary2D_data;
  Ary2D_f32_5_4 CtrldVelRtnDrvrTqMtrxB_Ary2D_data;
  Ary1D_f32_5 CtrldVelRtnDrvrTqMtrxC_Ary1D_data;
  Ary1D_f32_4 CtrldVelRtnDrvrTqMtrxD_Ary1D_data;
  Ary1D_u2p14_4 CtrldVelRtnHwAuthyScaX_Ary1D_data;
  Ary1D_u2p14_4 CtrldVelRtnHwAuthyScaY_Ary1D_data;
  Ary1D_u12p4_9 CtrldVelRtnHwPosnScaX_Ary1D_data;
  Ary1D_u2p14_9 CtrldVelRtnHwPosnScaY_Ary1D_data;
  Ary2D_u8p8_5_10 CtrldVelRtnHwTqSca1X_Ary2D_data;
  Ary2D_u2p14_5_10 CtrldVelRtnHwTqSca1Y_Ary2D_data;
  Ary2D_u8p8_5_10 CtrldVelRtnHwTqSca2X_Ary2D_data;
  Ary2D_u2p14_5_10 CtrldVelRtnHwTqSca2Y_Ary2D_data;
  Ary1D_u8p8_8 CtrldVelRtnIntglGain_Ary1D_data;
  Ary2D_u6p10_5_9 CtrldVelRtnIntgrLimY_Ary2D_data;
  Ary2D_u8p8_5_8 CtrldVelRtnPinionTqScaX_Ary2D_data;
  Ary2D_u2p14_5_8 CtrldVelRtnPinionTqScaY_Ary2D_data;
  Ary1D_u4p12_8 CtrldVelRtnPropGain_Ary1D_data;
  Ary1D_u4p12_8 CtrldVelRtnRtnCmdLimY_Ary1D_data;
  Ary2D_u8p8_5_8 CtrldVelRtnTqGrdtScaX_Ary2D_data;
  Ary2D_u2p14_5_8 CtrldVelRtnTqGrdtScaY_Ary2D_data;
  Ary1D_u9p7_5 CtrldVelRtnVehSpdScaBilnrSeln_Ary1D_data;
  Ary1D_u12p4_7 CtrldVelRtnVelErrScaBilnrSeln_Ary1D_data;
  Ary1D_s10p5_8 CtrldVelRtnVelErrScaX_Ary1D_data;
  Ary2D_u2p14_7_8 CtrldVelRtnVelErrScaY_Ary2D_data;
  Ary1D_u2p14_5 CtrldVelRtnVelErrVehSpdScaY_Ary1D_data;
  Ary1D_u9p7_8 CtrldVelRtnVelSpdTbl_Ary1D_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimPrevDesVel = *TSC_CtrldVelRtn_Rte_Pim_PrevDesVel();
  *TSC_CtrldVelRtn_Rte_Pim_PrevDesVel() = PimPrevDesVel;
  PimPrevDrvrTqFildA = *TSC_CtrldVelRtn_Rte_Pim_PrevDrvrTqFildA();
  *TSC_CtrldVelRtn_Rte_Pim_PrevDrvrTqFildA() = PimPrevDrvrTqFildA;
  PimPrevDrvrTqFildB = *TSC_CtrldVelRtn_Rte_Pim_PrevDrvrTqFildB();
  *TSC_CtrldVelRtn_Rte_Pim_PrevDrvrTqFildB() = PimPrevDrvrTqFildB;
  PimPrevDrvrTqFildC = *TSC_CtrldVelRtn_Rte_Pim_PrevDrvrTqFildC();
  *TSC_CtrldVelRtn_Rte_Pim_PrevDrvrTqFildC() = PimPrevDrvrTqFildC;
  PimPrevDrvrTqFildD = *TSC_CtrldVelRtn_Rte_Pim_PrevDrvrTqFildD();
  *TSC_CtrldVelRtn_Rte_Pim_PrevDrvrTqFildD() = PimPrevDrvrTqFildD;
  PimPrevDrvrTqFildE = *TSC_CtrldVelRtn_Rte_Pim_PrevDrvrTqFildE();
  *TSC_CtrldVelRtn_Rte_Pim_PrevDrvrTqFildE() = PimPrevDrvrTqFildE;
  PimPrevDrvrTqFildF = *TSC_CtrldVelRtn_Rte_Pim_PrevDrvrTqFildF();
  *TSC_CtrldVelRtn_Rte_Pim_PrevDrvrTqFildF() = PimPrevDrvrTqFildF;
  PimPrevHwAuthySca = *TSC_CtrldVelRtn_Rte_Pim_PrevHwAuthySca();
  *TSC_CtrldVelRtn_Rte_Pim_PrevHwAuthySca() = PimPrevHwAuthySca;
  PimPrevHwTqSeln = *TSC_CtrldVelRtn_Rte_Pim_PrevHwTqSeln();
  *TSC_CtrldVelRtn_Rte_Pim_PrevHwTqSeln() = PimPrevHwTqSeln;
  PimPrevIntglTermA = *TSC_CtrldVelRtn_Rte_Pim_PrevIntglTermA();
  *TSC_CtrldVelRtn_Rte_Pim_PrevIntglTermA() = PimPrevIntglTermA;
  PimPrevIntglTermB = *TSC_CtrldVelRtn_Rte_Pim_PrevIntglTermB();
  *TSC_CtrldVelRtn_Rte_Pim_PrevIntglTermB() = PimPrevIntglTermB;
  PimPrevIntglTermC = *TSC_CtrldVelRtn_Rte_Pim_PrevIntglTermC();
  *TSC_CtrldVelRtn_Rte_Pim_PrevIntglTermC() = PimPrevIntglTermC;
  PimPrevRtnOffs = *TSC_CtrldVelRtn_Rte_Pim_PrevRtnOffs();
  *TSC_CtrldVelRtn_Rte_Pim_PrevRtnOffs() = PimPrevRtnOffs;
  PimdCtrldVelRtnCtrlSca = *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnCtrlSca();
  *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnCtrlSca() = PimdCtrldVelRtnCtrlSca;
  PimdCtrldVelRtnCtrlScaPreFild = *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnCtrlScaPreFild();
  *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnCtrlScaPreFild() = PimdCtrldVelRtnCtrlScaPreFild;
  PimdCtrldVelRtnDampgCmd = *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnDampgCmd();
  *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnDampgCmd() = PimdCtrldVelRtnDampgCmd;
  PimdCtrldVelRtnDesVel = *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnDesVel();
  *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnDesVel() = PimdCtrldVelRtnDesVel;
  PimdCtrldVelRtnDesVelSca = *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnDesVelSca();
  *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnDesVelSca() = PimdCtrldVelRtnDesVelSca;
  PimdCtrldVelRtnDesVelScaPreFild = *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnDesVelScaPreFild();
  *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnDesVelScaPreFild() = PimdCtrldVelRtnDesVelScaPreFild;
  PimdCtrldVelRtnDrvrTqEstimd = *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnDrvrTqEstimd();
  *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnDrvrTqEstimd() = PimdCtrldVelRtnDrvrTqEstimd;
  PimdCtrldVelRtnDrvrTqFild = *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnDrvrTqFild();
  *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnDrvrTqFild() = PimdCtrldVelRtnDrvrTqFild;
  PimdCtrldVelRtnHwAgCmp = *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnHwAgCmp();
  *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnHwAgCmp() = PimdCtrldVelRtnHwAgCmp;
  PimdCtrldVelRtnHwAuthySca = *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnHwAuthySca();
  *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnHwAuthySca() = PimdCtrldVelRtnHwAuthySca;
  PimdCtrldVelRtnHwPosnSca = *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnHwPosnSca();
  *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnHwPosnSca() = PimdCtrldVelRtnHwPosnSca;
  PimdCtrldVelRtnHwTqSca = *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnHwTqSca();
  *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnHwTqSca() = PimdCtrldVelRtnHwTqSca;
  PimdCtrldVelRtnHwTqScaSeln = *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnHwTqScaSeln();
  *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnHwTqScaSeln() = PimdCtrldVelRtnHwTqScaSeln;
  PimdCtrldVelRtnIntglTermCmd = *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnIntglTermCmd();
  *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnIntglTermCmd() = PimdCtrldVelRtnIntglTermCmd;
  PimdCtrldVelRtnIntgrLim = *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnIntgrLim();
  *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnIntgrLim() = PimdCtrldVelRtnIntgrLim;
  PimdCtrldVelRtnPinionTqSca = *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnPinionTqSca();
  *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnPinionTqSca() = PimdCtrldVelRtnPinionTqSca;
  PimdCtrldVelRtnPropTermCmd = *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnPropTermCmd();
  *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnPropTermCmd() = PimdCtrldVelRtnPropTermCmd;
  PimdCtrldVelRtnRtnCmd = *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnRtnCmd();
  *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnRtnCmd() = PimdCtrldVelRtnRtnCmd;
  PimdCtrldVelRtnRtnCmdPreLim = *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnRtnCmdPreLim();
  *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnRtnCmdPreLim() = PimdCtrldVelRtnRtnCmdPreLim;
  PimdCtrldVelRtnTqGrdt = *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnTqGrdt();
  *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnTqGrdt() = PimdCtrldVelRtnTqGrdt;
  PimdCtrldVelRtnTqGrdtSca = *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnTqGrdtSca();
  *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnTqGrdtSca() = PimdCtrldVelRtnTqGrdtSca;
  PimdCtrldVelRtnVelErrSca = *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnVelErrSca();
  *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnVelErrSca() = PimdCtrldVelRtnVelErrSca;

  (void)memcpy(PimPrevDrvrTqMtrx, TSC_CtrldVelRtn_Rte_Pim_PrevDrvrTqMtrx(), sizeof(Ary1D_f32_5));
  (void)memcpy(TSC_CtrldVelRtn_Rte_Pim_PrevDrvrTqMtrx(), PimPrevDrvrTqMtrx, sizeof(Ary1D_f32_5));

  PimCtrlScaLpFil = *TSC_CtrldVelRtn_Rte_Pim_CtrlScaLpFil();
  *TSC_CtrldVelRtn_Rte_Pim_CtrlScaLpFil() = PimCtrlScaLpFil;
  PimDesVelLpFil = *TSC_CtrldVelRtn_Rte_Pim_DesVelLpFil();
  *TSC_CtrldVelRtn_Rte_Pim_DesVelLpFil() = PimDesVelLpFil;
  PimDesVelScaLpFil = *TSC_CtrldVelRtn_Rte_Pim_DesVelScaLpFil();
  *TSC_CtrldVelRtn_Rte_Pim_DesVelScaLpFil() = PimDesVelScaLpFil;
  PimDrvrTqLpFil = *TSC_CtrldVelRtn_Rte_Pim_DrvrTqLpFil();
  *TSC_CtrldVelRtn_Rte_Pim_DrvrTqLpFil() = PimDrvrTqLpFil;
  PimPinionTqLpFil = *TSC_CtrldVelRtn_Rte_Pim_PinionTqLpFil();
  *TSC_CtrldVelRtn_Rte_Pim_PinionTqLpFil() = PimPinionTqLpFil;

  CtrldVelRtnAntiWdup_Val_data = TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnAntiWdup_Val();
  CtrldVelRtnDesVelLpFilFrq_Val_data = TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnDesVelLpFilFrq_Val();
  CtrldVelRtnHwAuthySlewThd_Val_data = TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnHwAuthySlewThd_Val();
  CtrldVelRtnHwTqLpFilFrq_Val_data = TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnHwTqLpFilFrq_Val();
  CtrldVelRtnHwTqScaSelnSlewHiLim_Val_data = TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnHwTqScaSelnSlewHiLim_Val();
  CtrldVelRtnHwTqScaSelnSlewLoLim_Val_data = TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnHwTqScaSelnSlewLoLim_Val();
  CtrldVelRtnHwTqScaSelnTqThd_Val_data = TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnHwTqScaSelnTqThd_Val();
  CtrldVelRtnHwTqScaSelnVelThd_Val_data = TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnHwTqScaSelnVelThd_Val();
  CtrldVelRtnOffsSlewThd_Val_data = TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnOffsSlewThd_Val();
  CtrldVelRtnOffsThd_Val_data = TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnOffsThd_Val();
  CtrldVelRtnScaLpFilFrq_Val_data = TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnScaLpFilFrq_Val();
  SysGlbPrmSysTqRat_Val_data = TSC_CtrldVelRtn_Rte_Prm_SysGlbPrmSysTqRat_Val();
  CtrldVelRtnDampgEna_Logl_data = TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnDampgEna_Logl();
  CtrldVelRtnDampgScaEna_Logl_data = TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnDampgScaEna_Logl();
  CtrldVelRtnDrvrTqEna_Logl_data = TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnDrvrTqEna_Logl();
  CtrldVelRtnTqGrdtScaEna_Logl_data = TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnTqGrdtScaEna_Logl();
  CtrldVelRtnVelErrScaEna_Logl_data = TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnVelErrScaEna_Logl();
  (void)memcpy(CtrldVelRtnDampgX_Ary2D_data, TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnDampgX_Ary2D(), sizeof(Ary2D_u10p6_8_9));
  (void)memcpy(CtrldVelRtnDampgY_Ary2D_data, TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnDampgY_Ary2D(), sizeof(Ary2D_u6p10_8_9));
  (void)memcpy(CtrldVelRtnDesVelScaX_Ary2D_data, TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnDesVelScaX_Ary2D(), sizeof(Ary2D_u8p8_5_8));
  (void)memcpy(CtrldVelRtnDesVelScaY_Ary2D_data, TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnDesVelScaY_Ary2D(), sizeof(Ary2D_u2p14_5_8));
  (void)memcpy(CtrldVelRtnDesVelX_Ary2D_data, TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnDesVelX_Ary2D(), sizeof(Ary2D_u12p4_8_12));
  (void)memcpy(CtrldVelRtnDesVelY_Ary2D_data, TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnDesVelY_Ary2D(), sizeof(Ary2D_u10p6_8_12));
  (void)memcpy(CtrldVelRtnDrvrTqMtrxA_Ary2D_data, TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnDrvrTqMtrxA_Ary2D(), sizeof(Ary2D_f32_5_5));
  (void)memcpy(CtrldVelRtnDrvrTqMtrxB_Ary2D_data, TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnDrvrTqMtrxB_Ary2D(), sizeof(Ary2D_f32_5_4));
  (void)memcpy(CtrldVelRtnDrvrTqMtrxC_Ary1D_data, TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnDrvrTqMtrxC_Ary1D(), sizeof(Ary1D_f32_5));
  (void)memcpy(CtrldVelRtnDrvrTqMtrxD_Ary1D_data, TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnDrvrTqMtrxD_Ary1D(), sizeof(Ary1D_f32_4));
  (void)memcpy(CtrldVelRtnHwAuthyScaX_Ary1D_data, TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnHwAuthyScaX_Ary1D(), sizeof(Ary1D_u2p14_4));
  (void)memcpy(CtrldVelRtnHwAuthyScaY_Ary1D_data, TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnHwAuthyScaY_Ary1D(), sizeof(Ary1D_u2p14_4));
  (void)memcpy(CtrldVelRtnHwPosnScaX_Ary1D_data, TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnHwPosnScaX_Ary1D(), sizeof(Ary1D_u12p4_9));
  (void)memcpy(CtrldVelRtnHwPosnScaY_Ary1D_data, TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnHwPosnScaY_Ary1D(), sizeof(Ary1D_u2p14_9));
  (void)memcpy(CtrldVelRtnHwTqSca1X_Ary2D_data, TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnHwTqSca1X_Ary2D(), sizeof(Ary2D_u8p8_5_10));
  (void)memcpy(CtrldVelRtnHwTqSca1Y_Ary2D_data, TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnHwTqSca1Y_Ary2D(), sizeof(Ary2D_u2p14_5_10));
  (void)memcpy(CtrldVelRtnHwTqSca2X_Ary2D_data, TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnHwTqSca2X_Ary2D(), sizeof(Ary2D_u8p8_5_10));
  (void)memcpy(CtrldVelRtnHwTqSca2Y_Ary2D_data, TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnHwTqSca2Y_Ary2D(), sizeof(Ary2D_u2p14_5_10));
  (void)memcpy(CtrldVelRtnIntglGain_Ary1D_data, TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnIntglGain_Ary1D(), sizeof(Ary1D_u8p8_8));
  (void)memcpy(CtrldVelRtnIntgrLimY_Ary2D_data, TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnIntgrLimY_Ary2D(), sizeof(Ary2D_u6p10_5_9));
  (void)memcpy(CtrldVelRtnPinionTqScaX_Ary2D_data, TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnPinionTqScaX_Ary2D(), sizeof(Ary2D_u8p8_5_8));
  (void)memcpy(CtrldVelRtnPinionTqScaY_Ary2D_data, TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnPinionTqScaY_Ary2D(), sizeof(Ary2D_u2p14_5_8));
  (void)memcpy(CtrldVelRtnPropGain_Ary1D_data, TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnPropGain_Ary1D(), sizeof(Ary1D_u4p12_8));
  (void)memcpy(CtrldVelRtnRtnCmdLimY_Ary1D_data, TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnRtnCmdLimY_Ary1D(), sizeof(Ary1D_u4p12_8));
  (void)memcpy(CtrldVelRtnTqGrdtScaX_Ary2D_data, TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnTqGrdtScaX_Ary2D(), sizeof(Ary2D_u8p8_5_8));
  (void)memcpy(CtrldVelRtnTqGrdtScaY_Ary2D_data, TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnTqGrdtScaY_Ary2D(), sizeof(Ary2D_u2p14_5_8));
  (void)memcpy(CtrldVelRtnVehSpdScaBilnrSeln_Ary1D_data, TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnVehSpdScaBilnrSeln_Ary1D(), sizeof(Ary1D_u9p7_5));
  (void)memcpy(CtrldVelRtnVelErrScaBilnrSeln_Ary1D_data, TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnVelErrScaBilnrSeln_Ary1D(), sizeof(Ary1D_u12p4_7));
  (void)memcpy(CtrldVelRtnVelErrScaX_Ary1D_data, TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnVelErrScaX_Ary1D(), sizeof(Ary1D_s10p5_8));
  (void)memcpy(CtrldVelRtnVelErrScaY_Ary2D_data, TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnVelErrScaY_Ary2D(), sizeof(Ary2D_u2p14_7_8));
  (void)memcpy(CtrldVelRtnVelErrVehSpdScaY_Ary1D_data, TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnVelErrVehSpdScaY_Ary1D(), sizeof(Ary1D_u2p14_5));
  (void)memcpy(CtrldVelRtnVelSpdTbl_Ary1D_data, TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnVelSpdTbl_Ary1D(), sizeof(Ary1D_u9p7_8));

  fct_status = TSC_CtrldVelRtn_Rte_Read_AssiMechPolarity_Val(&Read_AssiMechPolarity_Val);
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

  fct_status = TSC_CtrldVelRtn_Rte_Read_HwAg_Val(&Read_HwAg_Val);
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

  fct_status = TSC_CtrldVelRtn_Rte_Read_HwAgAuthy_Val(&Read_HwAgAuthy_Val);
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

  fct_status = TSC_CtrldVelRtn_Rte_Read_HwAgRtnOffs_Val(&Read_HwAgRtnOffs_Val);
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

  fct_status = TSC_CtrldVelRtn_Rte_Read_HwTq_Val(&Read_HwTq_Val);
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

  fct_status = TSC_CtrldVelRtn_Rte_Read_HwVel_Val(&Read_HwVel_Val);
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

  fct_status = TSC_CtrldVelRtn_Rte_Read_MotTqCmdPwrLimd_Val(&Read_MotTqCmdPwrLimd_Val);
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

  fct_status = TSC_CtrldVelRtn_Rte_Read_RtnCmdDi_Logl(&Read_RtnCmdDi_Logl);
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

  fct_status = TSC_CtrldVelRtn_Rte_Read_RtnCmdDiagcDi_Logl(&Read_RtnCmdDiagcDi_Logl);
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

  fct_status = TSC_CtrldVelRtn_Rte_Read_RtnCmdSca_Val(&Read_RtnCmdSca_Val);
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

  fct_status = TSC_CtrldVelRtn_Rte_Read_RtnCmdScaServo_Val(&Read_RtnCmdScaServo_Val);
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

  fct_status = TSC_CtrldVelRtn_Rte_Read_VehSpd_Val(&Read_VehSpd_Val);
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

  fct_status = TSC_CtrldVelRtn_Rte_Write_CtrldVelRtnCmd_Val(Rte_InitValue_CtrldVelRtnCmd_Val);
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


#define CtrldVelRtn_STOP_SEC_CODE
#include "CtrldVelRtn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


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
