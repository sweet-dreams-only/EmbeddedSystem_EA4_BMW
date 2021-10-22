/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  InertiaCmpVel.c
 *        Config:  EPS.dpa
 *     SW-C Type:  InertiaCmpVel
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <InertiaCmpVel>
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
 * u11p5
 *   
 *
 * u12p4
 *   
 *
 * u13p3
 *   
 *
 * u1p15
 *   
 *
 * u2p14
 *   
 *
 * u4p12
 *   
 *
 * u7p9
 *   
 *
 * u9p7
 *   
 *
 *********************************************************************************************************************/

#include "Rte_InertiaCmpVel.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_InertiaCmpVel.h"


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
 * u11p5: Integer in interval [0...65535]
 * u12p4: Integer in interval [0...65535]
 * u13p3: Integer in interval [0...65535]
 * u1p15: Integer in interval [0...65535]
 * u2p14: Integer in interval [0...65535]
 * u4p12: Integer in interval [0...65535]
 * u7p9: Integer in interval [0...65535]
 * u9p7: Integer in interval [0...65535]
 * uint16: Integer in interval [0...65535] (standard type)
 *
 * Array Types:
 * ============
 * Ary1D_u0p16_10: Array with 10 element(s) of type u0p16
 * Ary1D_u11p5_6: Array with 6 element(s) of type u11p5
 * Ary1D_u12p4_2: Array with 2 element(s) of type u12p4
 * Ary1D_u13p3_6: Array with 6 element(s) of type u13p3
 * Ary1D_u1p15_12: Array with 12 element(s) of type u1p15
 * Ary1D_u1p15_2: Array with 2 element(s) of type u1p15
 * Ary1D_u1p15_5: Array with 5 element(s) of type u1p15
 * Ary1D_u2p14_12: Array with 12 element(s) of type u2p14
 * Ary1D_u4p12_10: Array with 10 element(s) of type u4p12
 * Ary1D_u4p12_2: Array with 2 element(s) of type u4p12
 * Ary1D_u4p12_5: Array with 5 element(s) of type u4p12
 * Ary1D_u7p9_12: Array with 12 element(s) of type u7p9
 * Ary1D_u9p7_12: Array with 12 element(s) of type u9p7
 *
 * Record Types:
 * =============
 * FilLpRec1: Record with elements
 *   FilSt of type float32
 *   FilGain of type float32
 * FilNotchGainRec1: Record with elements
 *   FilGainB0 of type float32
 *   FilGainB1 of type float32
 *   FilGainB2 of type float32
 *   FilGainA1 of type float32
 *   FilGainA2 of type float32
 * FilNotchStRec1: Record with elements
 *   FilSt1 of type float32
 *   FilSt2 of type float32
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   float32 *Rte_Pim_DecelGain(void)
 *   float32 *Rte_Pim_PreScagCmpCmdPrev1(void)
 *   float32 *Rte_Pim_PreScagCmpCmdPrev2(void)
 *   float32 *Rte_Pim_ScaDrvrVelPrev1(void)
 *   float32 *Rte_Pim_ScaDrvrVelPrev2(void)
 *   float32 *Rte_Pim_TqSnsrAgPrev(void)
 *   float32 *Rte_Pim_dInertiaCmpVelAssiBasdDampgCoeff(void)
 *   float32 *Rte_Pim_dInertiaCmpVelCalcdInertiaCmp(void)
 *   float32 *Rte_Pim_dInertiaCmpVelFilFrq(void)
 *   float32 *Rte_Pim_dInertiaCmpVelMotVelBasdOutpScag(void)
 *   float32 *Rte_Pim_dInertiaCmpVelNotScadDrvrVel(void)
 *   float32 *Rte_Pim_dInertiaCmpVelNotchBlndVal(void)
 *   float32 *Rte_Pim_dInertiaCmpVelNotchInpVal(void)
 *   float32 *Rte_Pim_dInertiaCmpVelNotchOutpVal(void)
 *   float32 *Rte_Pim_dInertiaCmpVelRawDecelGain(void)
 *   float32 *Rte_Pim_dInertiaCmpVelScadDrvrVel(void)
 *   float32 *Rte_Pim_dInertiaCmpVelTqSnsrVelFildVal(void)
 *   boolean *Rte_Pim_NotchFilChk(void)
 *   FilLpRec1 *Rte_Pim_TqSnsrVelFil(void)
 *   FilNotchStRec1 *Rte_Pim_TqSnsrVelFilNotchSt(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_InertiaCmpVelDampgDecelGain_Val(void)
 *   float32 Rte_Prm_InertiaCmpVelDampgDecelGainFallSlew_Val(void)
 *   float32 Rte_Prm_InertiaCmpVelDampgGainOffThd_Val(void)
 *   float32 Rte_Prm_InertiaCmpVelDampgGainOnThd_Val(void)
 *   float32 Rte_Prm_InertiaCmpVelMotInertia_Val(void)
 *   float32 Rte_Prm_InertiaCmpVelTqSnsrVelFilFrq_Val(void)
 *   float32 Rte_Prm_SysGlbPrmSysKineRat_Val(void)
 *   float32 Rte_Prm_SysGlbPrmTorsBarStfn_Val(void)
 *   boolean Rte_Prm_InertiaCmpVelDecelGainEnaCal_Logl(void)
 *   u4p12 *Rte_Prm_InertiaCmpVelAssiBasdDampgCoeffX_Ary1D(void)
 *     Returnvalue: u4p12* is of type Ary1D_u4p12_10
 *   u0p16 *Rte_Prm_InertiaCmpVelAssiBasdDampgRollgWhlImbRejctnOnY_Ary1D(void)
 *     Returnvalue: u0p16* is of type Ary1D_u0p16_10
 *   u0p16 *Rte_Prm_InertiaCmpVelAssiBasdDampgRollgY_Ary1D(void)
 *     Returnvalue: u0p16* is of type Ary1D_u0p16_10
 *   u0p16 *Rte_Prm_InertiaCmpVelAssiBasdDampgStatWhlImbRejctnOnY_Ary1D(void)
 *     Returnvalue: u0p16* is of type Ary1D_u0p16_10
 *   u0p16 *Rte_Prm_InertiaCmpVelAssiBasdDampgStatY_Ary1D(void)
 *     Returnvalue: u0p16* is of type Ary1D_u0p16_10
 *   u2p14 *Rte_Prm_InertiaCmpVelCmdScaY_Ary1D(void)
 *     Returnvalue: u2p14* is of type Ary1D_u2p14_12
 *   u11p5 *Rte_Prm_InertiaCmpVelDampgDecelGainRisngSlewX_Ary1D(void)
 *     Returnvalue: u11p5* is of type Ary1D_u11p5_6
 *   u13p3 *Rte_Prm_InertiaCmpVelDampgDecelGainRisngSlewY_Ary1D(void)
 *     Returnvalue: u13p3* is of type Ary1D_u13p3_6
 *   u7p9 *Rte_Prm_InertiaCmpVelDampgFilFrq_Ary1D(void)
 *     Returnvalue: u7p9* is of type Ary1D_u7p9_12
 *   u7p9 *Rte_Prm_InertiaCmpVelDampgFilFrqWhlImbRejctnOn_Ary1D(void)
 *     Returnvalue: u7p9* is of type Ary1D_u7p9_12
 *   u1p15 *Rte_Prm_InertiaCmpVelDampgSpdBlndY_Ary1D(void)
 *     Returnvalue: u1p15* is of type Ary1D_u1p15_12
 *   u4p12 *Rte_Prm_InertiaCmpVelDampgWhlImbRejctnBlndX_Ary1D(void)
 *     Returnvalue: u4p12* is of type Ary1D_u4p12_5
 *   u1p15 *Rte_Prm_InertiaCmpVelDampgWhlImbRejctnBlndY_Ary1D(void)
 *     Returnvalue: u1p15* is of type Ary1D_u1p15_5
 *   u4p12 *Rte_Prm_InertiaCmpVelModWhlImbRejctnBlndX_Ary1D(void)
 *     Returnvalue: u4p12* is of type Ary1D_u4p12_2
 *   u1p15 *Rte_Prm_InertiaCmpVelModWhlImbRejctnBlndY_Ary1D(void)
 *     Returnvalue: u1p15* is of type Ary1D_u1p15_2
 *   u12p4 *Rte_Prm_InertiaCmpVelMotVelBasdOutpScagX_Ary1D(void)
 *     Returnvalue: u12p4* is of type Ary1D_u12p4_2
 *   u1p15 *Rte_Prm_InertiaCmpVelMotVelBasdOutpScagY_Ary1D(void)
 *     Returnvalue: u1p15* is of type Ary1D_u1p15_2
 *   u1p15 *Rte_Prm_InertiaCmpVelNotchBlndY_Ary1D(void)
 *     Returnvalue: u1p15* is of type Ary1D_u1p15_12
 *   u2p14 *Rte_Prm_InertiaCmpVelTqSnsrVelSca_Ary1D(void)
 *     Returnvalue: u2p14* is of type Ary1D_u2p14_12
 *   u9p7 *Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D(void)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_12
 *   FilNotchGainRec1 *Rte_Prm_InertiaCmpVelNotchFilStruct_Rec(void)
 *
 *********************************************************************************************************************/


#define InertiaCmpVel_START_SEC_CODE
#include "InertiaCmpVel_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: InertiaCmpVelInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: InertiaCmpVelInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, InertiaCmpVel_CODE) InertiaCmpVelInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: InertiaCmpVelInit1
 *********************************************************************************************************************/

  float32 PimDecelGain;
  float32 PimPreScagCmpCmdPrev1;
  float32 PimPreScagCmpCmdPrev2;
  float32 PimScaDrvrVelPrev1;
  float32 PimScaDrvrVelPrev2;
  float32 PimTqSnsrAgPrev;
  float32 PimdInertiaCmpVelAssiBasdDampgCoeff;
  float32 PimdInertiaCmpVelCalcdInertiaCmp;
  float32 PimdInertiaCmpVelFilFrq;
  float32 PimdInertiaCmpVelMotVelBasdOutpScag;
  float32 PimdInertiaCmpVelNotScadDrvrVel;
  float32 PimdInertiaCmpVelNotchBlndVal;
  float32 PimdInertiaCmpVelNotchInpVal;
  float32 PimdInertiaCmpVelNotchOutpVal;
  float32 PimdInertiaCmpVelRawDecelGain;
  float32 PimdInertiaCmpVelScadDrvrVel;
  float32 PimdInertiaCmpVelTqSnsrVelFildVal;
  boolean PimNotchFilChk;
  FilLpRec1 PimTqSnsrVelFil;
  FilNotchStRec1 PimTqSnsrVelFilNotchSt;

  float32 InertiaCmpVelDampgDecelGain_Val_data;
  float32 InertiaCmpVelDampgDecelGainFallSlew_Val_data;
  float32 InertiaCmpVelDampgGainOffThd_Val_data;
  float32 InertiaCmpVelDampgGainOnThd_Val_data;
  float32 InertiaCmpVelMotInertia_Val_data;
  float32 InertiaCmpVelTqSnsrVelFilFrq_Val_data;
  float32 SysGlbPrmSysKineRat_Val_data;
  float32 SysGlbPrmTorsBarStfn_Val_data;
  boolean InertiaCmpVelDecelGainEnaCal_Logl_data;
  Ary1D_u4p12_10 InertiaCmpVelAssiBasdDampgCoeffX_Ary1D_data;
  Ary1D_u0p16_10 InertiaCmpVelAssiBasdDampgRollgWhlImbRejctnOnY_Ary1D_data;
  Ary1D_u0p16_10 InertiaCmpVelAssiBasdDampgRollgY_Ary1D_data;
  Ary1D_u0p16_10 InertiaCmpVelAssiBasdDampgStatWhlImbRejctnOnY_Ary1D_data;
  Ary1D_u0p16_10 InertiaCmpVelAssiBasdDampgStatY_Ary1D_data;
  Ary1D_u2p14_12 InertiaCmpVelCmdScaY_Ary1D_data;
  Ary1D_u11p5_6 InertiaCmpVelDampgDecelGainRisngSlewX_Ary1D_data;
  Ary1D_u13p3_6 InertiaCmpVelDampgDecelGainRisngSlewY_Ary1D_data;
  Ary1D_u7p9_12 InertiaCmpVelDampgFilFrq_Ary1D_data;
  Ary1D_u7p9_12 InertiaCmpVelDampgFilFrqWhlImbRejctnOn_Ary1D_data;
  Ary1D_u1p15_12 InertiaCmpVelDampgSpdBlndY_Ary1D_data;
  Ary1D_u4p12_5 InertiaCmpVelDampgWhlImbRejctnBlndX_Ary1D_data;
  Ary1D_u1p15_5 InertiaCmpVelDampgWhlImbRejctnBlndY_Ary1D_data;
  Ary1D_u4p12_2 InertiaCmpVelModWhlImbRejctnBlndX_Ary1D_data;
  Ary1D_u1p15_2 InertiaCmpVelModWhlImbRejctnBlndY_Ary1D_data;
  Ary1D_u12p4_2 InertiaCmpVelMotVelBasdOutpScagX_Ary1D_data;
  Ary1D_u1p15_2 InertiaCmpVelMotVelBasdOutpScagY_Ary1D_data;
  Ary1D_u1p15_12 InertiaCmpVelNotchBlndY_Ary1D_data;
  Ary1D_u2p14_12 InertiaCmpVelTqSnsrVelSca_Ary1D_data;
  Ary1D_u9p7_12 SysGlbPrmVehSpdBilnrSeln_Ary1D_data;
  FilNotchGainRec1 InertiaCmpVelNotchFilStruct_Rec_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimDecelGain = *TSC_InertiaCmpVel_Rte_Pim_DecelGain();
  *TSC_InertiaCmpVel_Rte_Pim_DecelGain() = PimDecelGain;
  PimPreScagCmpCmdPrev1 = *TSC_InertiaCmpVel_Rte_Pim_PreScagCmpCmdPrev1();
  *TSC_InertiaCmpVel_Rte_Pim_PreScagCmpCmdPrev1() = PimPreScagCmpCmdPrev1;
  PimPreScagCmpCmdPrev2 = *TSC_InertiaCmpVel_Rte_Pim_PreScagCmpCmdPrev2();
  *TSC_InertiaCmpVel_Rte_Pim_PreScagCmpCmdPrev2() = PimPreScagCmpCmdPrev2;
  PimScaDrvrVelPrev1 = *TSC_InertiaCmpVel_Rte_Pim_ScaDrvrVelPrev1();
  *TSC_InertiaCmpVel_Rte_Pim_ScaDrvrVelPrev1() = PimScaDrvrVelPrev1;
  PimScaDrvrVelPrev2 = *TSC_InertiaCmpVel_Rte_Pim_ScaDrvrVelPrev2();
  *TSC_InertiaCmpVel_Rte_Pim_ScaDrvrVelPrev2() = PimScaDrvrVelPrev2;
  PimTqSnsrAgPrev = *TSC_InertiaCmpVel_Rte_Pim_TqSnsrAgPrev();
  *TSC_InertiaCmpVel_Rte_Pim_TqSnsrAgPrev() = PimTqSnsrAgPrev;
  PimdInertiaCmpVelAssiBasdDampgCoeff = *TSC_InertiaCmpVel_Rte_Pim_dInertiaCmpVelAssiBasdDampgCoeff();
  *TSC_InertiaCmpVel_Rte_Pim_dInertiaCmpVelAssiBasdDampgCoeff() = PimdInertiaCmpVelAssiBasdDampgCoeff;
  PimdInertiaCmpVelCalcdInertiaCmp = *TSC_InertiaCmpVel_Rte_Pim_dInertiaCmpVelCalcdInertiaCmp();
  *TSC_InertiaCmpVel_Rte_Pim_dInertiaCmpVelCalcdInertiaCmp() = PimdInertiaCmpVelCalcdInertiaCmp;
  PimdInertiaCmpVelFilFrq = *TSC_InertiaCmpVel_Rte_Pim_dInertiaCmpVelFilFrq();
  *TSC_InertiaCmpVel_Rte_Pim_dInertiaCmpVelFilFrq() = PimdInertiaCmpVelFilFrq;
  PimdInertiaCmpVelMotVelBasdOutpScag = *TSC_InertiaCmpVel_Rte_Pim_dInertiaCmpVelMotVelBasdOutpScag();
  *TSC_InertiaCmpVel_Rte_Pim_dInertiaCmpVelMotVelBasdOutpScag() = PimdInertiaCmpVelMotVelBasdOutpScag;
  PimdInertiaCmpVelNotScadDrvrVel = *TSC_InertiaCmpVel_Rte_Pim_dInertiaCmpVelNotScadDrvrVel();
  *TSC_InertiaCmpVel_Rte_Pim_dInertiaCmpVelNotScadDrvrVel() = PimdInertiaCmpVelNotScadDrvrVel;
  PimdInertiaCmpVelNotchBlndVal = *TSC_InertiaCmpVel_Rte_Pim_dInertiaCmpVelNotchBlndVal();
  *TSC_InertiaCmpVel_Rte_Pim_dInertiaCmpVelNotchBlndVal() = PimdInertiaCmpVelNotchBlndVal;
  PimdInertiaCmpVelNotchInpVal = *TSC_InertiaCmpVel_Rte_Pim_dInertiaCmpVelNotchInpVal();
  *TSC_InertiaCmpVel_Rte_Pim_dInertiaCmpVelNotchInpVal() = PimdInertiaCmpVelNotchInpVal;
  PimdInertiaCmpVelNotchOutpVal = *TSC_InertiaCmpVel_Rte_Pim_dInertiaCmpVelNotchOutpVal();
  *TSC_InertiaCmpVel_Rte_Pim_dInertiaCmpVelNotchOutpVal() = PimdInertiaCmpVelNotchOutpVal;
  PimdInertiaCmpVelRawDecelGain = *TSC_InertiaCmpVel_Rte_Pim_dInertiaCmpVelRawDecelGain();
  *TSC_InertiaCmpVel_Rte_Pim_dInertiaCmpVelRawDecelGain() = PimdInertiaCmpVelRawDecelGain;
  PimdInertiaCmpVelScadDrvrVel = *TSC_InertiaCmpVel_Rte_Pim_dInertiaCmpVelScadDrvrVel();
  *TSC_InertiaCmpVel_Rte_Pim_dInertiaCmpVelScadDrvrVel() = PimdInertiaCmpVelScadDrvrVel;
  PimdInertiaCmpVelTqSnsrVelFildVal = *TSC_InertiaCmpVel_Rte_Pim_dInertiaCmpVelTqSnsrVelFildVal();
  *TSC_InertiaCmpVel_Rte_Pim_dInertiaCmpVelTqSnsrVelFildVal() = PimdInertiaCmpVelTqSnsrVelFildVal;
  PimNotchFilChk = *TSC_InertiaCmpVel_Rte_Pim_NotchFilChk();
  *TSC_InertiaCmpVel_Rte_Pim_NotchFilChk() = PimNotchFilChk;
  PimTqSnsrVelFil = *TSC_InertiaCmpVel_Rte_Pim_TqSnsrVelFil();
  *TSC_InertiaCmpVel_Rte_Pim_TqSnsrVelFil() = PimTqSnsrVelFil;
  PimTqSnsrVelFilNotchSt = *TSC_InertiaCmpVel_Rte_Pim_TqSnsrVelFilNotchSt();
  *TSC_InertiaCmpVel_Rte_Pim_TqSnsrVelFilNotchSt() = PimTqSnsrVelFilNotchSt;

  InertiaCmpVelDampgDecelGain_Val_data = TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelDampgDecelGain_Val();
  InertiaCmpVelDampgDecelGainFallSlew_Val_data = TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelDampgDecelGainFallSlew_Val();
  InertiaCmpVelDampgGainOffThd_Val_data = TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelDampgGainOffThd_Val();
  InertiaCmpVelDampgGainOnThd_Val_data = TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelDampgGainOnThd_Val();
  InertiaCmpVelMotInertia_Val_data = TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelMotInertia_Val();
  InertiaCmpVelTqSnsrVelFilFrq_Val_data = TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelTqSnsrVelFilFrq_Val();
  SysGlbPrmSysKineRat_Val_data = TSC_InertiaCmpVel_Rte_Prm_SysGlbPrmSysKineRat_Val();
  SysGlbPrmTorsBarStfn_Val_data = TSC_InertiaCmpVel_Rte_Prm_SysGlbPrmTorsBarStfn_Val();
  InertiaCmpVelDecelGainEnaCal_Logl_data = TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelDecelGainEnaCal_Logl();
  (void)memcpy(InertiaCmpVelAssiBasdDampgCoeffX_Ary1D_data, TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelAssiBasdDampgCoeffX_Ary1D(), sizeof(Ary1D_u4p12_10));
  (void)memcpy(InertiaCmpVelAssiBasdDampgRollgWhlImbRejctnOnY_Ary1D_data, TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelAssiBasdDampgRollgWhlImbRejctnOnY_Ary1D(), sizeof(Ary1D_u0p16_10));
  (void)memcpy(InertiaCmpVelAssiBasdDampgRollgY_Ary1D_data, TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelAssiBasdDampgRollgY_Ary1D(), sizeof(Ary1D_u0p16_10));
  (void)memcpy(InertiaCmpVelAssiBasdDampgStatWhlImbRejctnOnY_Ary1D_data, TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelAssiBasdDampgStatWhlImbRejctnOnY_Ary1D(), sizeof(Ary1D_u0p16_10));
  (void)memcpy(InertiaCmpVelAssiBasdDampgStatY_Ary1D_data, TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelAssiBasdDampgStatY_Ary1D(), sizeof(Ary1D_u0p16_10));
  (void)memcpy(InertiaCmpVelCmdScaY_Ary1D_data, TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelCmdScaY_Ary1D(), sizeof(Ary1D_u2p14_12));
  (void)memcpy(InertiaCmpVelDampgDecelGainRisngSlewX_Ary1D_data, TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelDampgDecelGainRisngSlewX_Ary1D(), sizeof(Ary1D_u11p5_6));
  (void)memcpy(InertiaCmpVelDampgDecelGainRisngSlewY_Ary1D_data, TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelDampgDecelGainRisngSlewY_Ary1D(), sizeof(Ary1D_u13p3_6));
  (void)memcpy(InertiaCmpVelDampgFilFrq_Ary1D_data, TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelDampgFilFrq_Ary1D(), sizeof(Ary1D_u7p9_12));
  (void)memcpy(InertiaCmpVelDampgFilFrqWhlImbRejctnOn_Ary1D_data, TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelDampgFilFrqWhlImbRejctnOn_Ary1D(), sizeof(Ary1D_u7p9_12));
  (void)memcpy(InertiaCmpVelDampgSpdBlndY_Ary1D_data, TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelDampgSpdBlndY_Ary1D(), sizeof(Ary1D_u1p15_12));
  (void)memcpy(InertiaCmpVelDampgWhlImbRejctnBlndX_Ary1D_data, TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelDampgWhlImbRejctnBlndX_Ary1D(), sizeof(Ary1D_u4p12_5));
  (void)memcpy(InertiaCmpVelDampgWhlImbRejctnBlndY_Ary1D_data, TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelDampgWhlImbRejctnBlndY_Ary1D(), sizeof(Ary1D_u1p15_5));
  (void)memcpy(InertiaCmpVelModWhlImbRejctnBlndX_Ary1D_data, TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelModWhlImbRejctnBlndX_Ary1D(), sizeof(Ary1D_u4p12_2));
  (void)memcpy(InertiaCmpVelModWhlImbRejctnBlndY_Ary1D_data, TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelModWhlImbRejctnBlndY_Ary1D(), sizeof(Ary1D_u1p15_2));
  (void)memcpy(InertiaCmpVelMotVelBasdOutpScagX_Ary1D_data, TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelMotVelBasdOutpScagX_Ary1D(), sizeof(Ary1D_u12p4_2));
  (void)memcpy(InertiaCmpVelMotVelBasdOutpScagY_Ary1D_data, TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelMotVelBasdOutpScagY_Ary1D(), sizeof(Ary1D_u1p15_2));
  (void)memcpy(InertiaCmpVelNotchBlndY_Ary1D_data, TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelNotchBlndY_Ary1D(), sizeof(Ary1D_u1p15_12));
  (void)memcpy(InertiaCmpVelTqSnsrVelSca_Ary1D_data, TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelTqSnsrVelSca_Ary1D(), sizeof(Ary1D_u2p14_12));
  (void)memcpy(SysGlbPrmVehSpdBilnrSeln_Ary1D_data, TSC_InertiaCmpVel_Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D(), sizeof(Ary1D_u9p7_12));
  InertiaCmpVelNotchFilStruct_Rec_data = *TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelNotchFilStruct_Rec();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: InertiaCmpVelPer1
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
 *   Std_ReturnType Rte_Read_AssiCmdBas_Val(float32 *data)
 *   Std_ReturnType Rte_Read_HwTq_Val(float32 *data)
 *   Std_ReturnType Rte_Read_InertiaCmpDecelGainDi_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_InertiaCmpVelCmdDi_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_MotVelCrf_Val(float32 *data)
 *   Std_ReturnType Rte_Read_VehLgtA_Val(float32 *data)
 *   Std_ReturnType Rte_Read_VehSpd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_WhlImbRejctnAmp_Val(float32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_InertiaCmpVelCmd_Val(float32 data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_FltInj_f32_Oper(float32 *SigPah_Arg, uint16 LocnKey_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: InertiaCmpVelPer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, InertiaCmpVel_CODE) InertiaCmpVelPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: InertiaCmpVelPer1
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  float32 Read_AssiCmdBas_Val;
  float32 Read_HwTq_Val;
  boolean Read_InertiaCmpDecelGainDi_Logl;
  boolean Read_InertiaCmpVelCmdDi_Logl;
  float32 Read_MotVelCrf_Val;
  float32 Read_VehLgtA_Val;
  float32 Read_VehSpd_Val;
  float32 Read_WhlImbRejctnAmp_Val;

  float32 PimDecelGain;
  float32 PimPreScagCmpCmdPrev1;
  float32 PimPreScagCmpCmdPrev2;
  float32 PimScaDrvrVelPrev1;
  float32 PimScaDrvrVelPrev2;
  float32 PimTqSnsrAgPrev;
  float32 PimdInertiaCmpVelAssiBasdDampgCoeff;
  float32 PimdInertiaCmpVelCalcdInertiaCmp;
  float32 PimdInertiaCmpVelFilFrq;
  float32 PimdInertiaCmpVelMotVelBasdOutpScag;
  float32 PimdInertiaCmpVelNotScadDrvrVel;
  float32 PimdInertiaCmpVelNotchBlndVal;
  float32 PimdInertiaCmpVelNotchInpVal;
  float32 PimdInertiaCmpVelNotchOutpVal;
  float32 PimdInertiaCmpVelRawDecelGain;
  float32 PimdInertiaCmpVelScadDrvrVel;
  float32 PimdInertiaCmpVelTqSnsrVelFildVal;
  boolean PimNotchFilChk;
  FilLpRec1 PimTqSnsrVelFil;
  FilNotchStRec1 PimTqSnsrVelFilNotchSt;

  float32 InertiaCmpVelDampgDecelGain_Val_data;
  float32 InertiaCmpVelDampgDecelGainFallSlew_Val_data;
  float32 InertiaCmpVelDampgGainOffThd_Val_data;
  float32 InertiaCmpVelDampgGainOnThd_Val_data;
  float32 InertiaCmpVelMotInertia_Val_data;
  float32 InertiaCmpVelTqSnsrVelFilFrq_Val_data;
  float32 SysGlbPrmSysKineRat_Val_data;
  float32 SysGlbPrmTorsBarStfn_Val_data;
  boolean InertiaCmpVelDecelGainEnaCal_Logl_data;
  Ary1D_u4p12_10 InertiaCmpVelAssiBasdDampgCoeffX_Ary1D_data;
  Ary1D_u0p16_10 InertiaCmpVelAssiBasdDampgRollgWhlImbRejctnOnY_Ary1D_data;
  Ary1D_u0p16_10 InertiaCmpVelAssiBasdDampgRollgY_Ary1D_data;
  Ary1D_u0p16_10 InertiaCmpVelAssiBasdDampgStatWhlImbRejctnOnY_Ary1D_data;
  Ary1D_u0p16_10 InertiaCmpVelAssiBasdDampgStatY_Ary1D_data;
  Ary1D_u2p14_12 InertiaCmpVelCmdScaY_Ary1D_data;
  Ary1D_u11p5_6 InertiaCmpVelDampgDecelGainRisngSlewX_Ary1D_data;
  Ary1D_u13p3_6 InertiaCmpVelDampgDecelGainRisngSlewY_Ary1D_data;
  Ary1D_u7p9_12 InertiaCmpVelDampgFilFrq_Ary1D_data;
  Ary1D_u7p9_12 InertiaCmpVelDampgFilFrqWhlImbRejctnOn_Ary1D_data;
  Ary1D_u1p15_12 InertiaCmpVelDampgSpdBlndY_Ary1D_data;
  Ary1D_u4p12_5 InertiaCmpVelDampgWhlImbRejctnBlndX_Ary1D_data;
  Ary1D_u1p15_5 InertiaCmpVelDampgWhlImbRejctnBlndY_Ary1D_data;
  Ary1D_u4p12_2 InertiaCmpVelModWhlImbRejctnBlndX_Ary1D_data;
  Ary1D_u1p15_2 InertiaCmpVelModWhlImbRejctnBlndY_Ary1D_data;
  Ary1D_u12p4_2 InertiaCmpVelMotVelBasdOutpScagX_Ary1D_data;
  Ary1D_u1p15_2 InertiaCmpVelMotVelBasdOutpScagY_Ary1D_data;
  Ary1D_u1p15_12 InertiaCmpVelNotchBlndY_Ary1D_data;
  Ary1D_u2p14_12 InertiaCmpVelTqSnsrVelSca_Ary1D_data;
  Ary1D_u9p7_12 SysGlbPrmVehSpdBilnrSeln_Ary1D_data;
  FilNotchGainRec1 InertiaCmpVelNotchFilStruct_Rec_data;

  float32 Call_FltInj_f32_Oper_SigPah_Arg = 0.0F;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimDecelGain = *TSC_InertiaCmpVel_Rte_Pim_DecelGain();
  *TSC_InertiaCmpVel_Rte_Pim_DecelGain() = PimDecelGain;
  PimPreScagCmpCmdPrev1 = *TSC_InertiaCmpVel_Rte_Pim_PreScagCmpCmdPrev1();
  *TSC_InertiaCmpVel_Rte_Pim_PreScagCmpCmdPrev1() = PimPreScagCmpCmdPrev1;
  PimPreScagCmpCmdPrev2 = *TSC_InertiaCmpVel_Rte_Pim_PreScagCmpCmdPrev2();
  *TSC_InertiaCmpVel_Rte_Pim_PreScagCmpCmdPrev2() = PimPreScagCmpCmdPrev2;
  PimScaDrvrVelPrev1 = *TSC_InertiaCmpVel_Rte_Pim_ScaDrvrVelPrev1();
  *TSC_InertiaCmpVel_Rte_Pim_ScaDrvrVelPrev1() = PimScaDrvrVelPrev1;
  PimScaDrvrVelPrev2 = *TSC_InertiaCmpVel_Rte_Pim_ScaDrvrVelPrev2();
  *TSC_InertiaCmpVel_Rte_Pim_ScaDrvrVelPrev2() = PimScaDrvrVelPrev2;
  PimTqSnsrAgPrev = *TSC_InertiaCmpVel_Rte_Pim_TqSnsrAgPrev();
  *TSC_InertiaCmpVel_Rte_Pim_TqSnsrAgPrev() = PimTqSnsrAgPrev;
  PimdInertiaCmpVelAssiBasdDampgCoeff = *TSC_InertiaCmpVel_Rte_Pim_dInertiaCmpVelAssiBasdDampgCoeff();
  *TSC_InertiaCmpVel_Rte_Pim_dInertiaCmpVelAssiBasdDampgCoeff() = PimdInertiaCmpVelAssiBasdDampgCoeff;
  PimdInertiaCmpVelCalcdInertiaCmp = *TSC_InertiaCmpVel_Rte_Pim_dInertiaCmpVelCalcdInertiaCmp();
  *TSC_InertiaCmpVel_Rte_Pim_dInertiaCmpVelCalcdInertiaCmp() = PimdInertiaCmpVelCalcdInertiaCmp;
  PimdInertiaCmpVelFilFrq = *TSC_InertiaCmpVel_Rte_Pim_dInertiaCmpVelFilFrq();
  *TSC_InertiaCmpVel_Rte_Pim_dInertiaCmpVelFilFrq() = PimdInertiaCmpVelFilFrq;
  PimdInertiaCmpVelMotVelBasdOutpScag = *TSC_InertiaCmpVel_Rte_Pim_dInertiaCmpVelMotVelBasdOutpScag();
  *TSC_InertiaCmpVel_Rte_Pim_dInertiaCmpVelMotVelBasdOutpScag() = PimdInertiaCmpVelMotVelBasdOutpScag;
  PimdInertiaCmpVelNotScadDrvrVel = *TSC_InertiaCmpVel_Rte_Pim_dInertiaCmpVelNotScadDrvrVel();
  *TSC_InertiaCmpVel_Rte_Pim_dInertiaCmpVelNotScadDrvrVel() = PimdInertiaCmpVelNotScadDrvrVel;
  PimdInertiaCmpVelNotchBlndVal = *TSC_InertiaCmpVel_Rte_Pim_dInertiaCmpVelNotchBlndVal();
  *TSC_InertiaCmpVel_Rte_Pim_dInertiaCmpVelNotchBlndVal() = PimdInertiaCmpVelNotchBlndVal;
  PimdInertiaCmpVelNotchInpVal = *TSC_InertiaCmpVel_Rte_Pim_dInertiaCmpVelNotchInpVal();
  *TSC_InertiaCmpVel_Rte_Pim_dInertiaCmpVelNotchInpVal() = PimdInertiaCmpVelNotchInpVal;
  PimdInertiaCmpVelNotchOutpVal = *TSC_InertiaCmpVel_Rte_Pim_dInertiaCmpVelNotchOutpVal();
  *TSC_InertiaCmpVel_Rte_Pim_dInertiaCmpVelNotchOutpVal() = PimdInertiaCmpVelNotchOutpVal;
  PimdInertiaCmpVelRawDecelGain = *TSC_InertiaCmpVel_Rte_Pim_dInertiaCmpVelRawDecelGain();
  *TSC_InertiaCmpVel_Rte_Pim_dInertiaCmpVelRawDecelGain() = PimdInertiaCmpVelRawDecelGain;
  PimdInertiaCmpVelScadDrvrVel = *TSC_InertiaCmpVel_Rte_Pim_dInertiaCmpVelScadDrvrVel();
  *TSC_InertiaCmpVel_Rte_Pim_dInertiaCmpVelScadDrvrVel() = PimdInertiaCmpVelScadDrvrVel;
  PimdInertiaCmpVelTqSnsrVelFildVal = *TSC_InertiaCmpVel_Rte_Pim_dInertiaCmpVelTqSnsrVelFildVal();
  *TSC_InertiaCmpVel_Rte_Pim_dInertiaCmpVelTqSnsrVelFildVal() = PimdInertiaCmpVelTqSnsrVelFildVal;
  PimNotchFilChk = *TSC_InertiaCmpVel_Rte_Pim_NotchFilChk();
  *TSC_InertiaCmpVel_Rte_Pim_NotchFilChk() = PimNotchFilChk;
  PimTqSnsrVelFil = *TSC_InertiaCmpVel_Rte_Pim_TqSnsrVelFil();
  *TSC_InertiaCmpVel_Rte_Pim_TqSnsrVelFil() = PimTqSnsrVelFil;
  PimTqSnsrVelFilNotchSt = *TSC_InertiaCmpVel_Rte_Pim_TqSnsrVelFilNotchSt();
  *TSC_InertiaCmpVel_Rte_Pim_TqSnsrVelFilNotchSt() = PimTqSnsrVelFilNotchSt;

  InertiaCmpVelDampgDecelGain_Val_data = TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelDampgDecelGain_Val();
  InertiaCmpVelDampgDecelGainFallSlew_Val_data = TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelDampgDecelGainFallSlew_Val();
  InertiaCmpVelDampgGainOffThd_Val_data = TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelDampgGainOffThd_Val();
  InertiaCmpVelDampgGainOnThd_Val_data = TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelDampgGainOnThd_Val();
  InertiaCmpVelMotInertia_Val_data = TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelMotInertia_Val();
  InertiaCmpVelTqSnsrVelFilFrq_Val_data = TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelTqSnsrVelFilFrq_Val();
  SysGlbPrmSysKineRat_Val_data = TSC_InertiaCmpVel_Rte_Prm_SysGlbPrmSysKineRat_Val();
  SysGlbPrmTorsBarStfn_Val_data = TSC_InertiaCmpVel_Rte_Prm_SysGlbPrmTorsBarStfn_Val();
  InertiaCmpVelDecelGainEnaCal_Logl_data = TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelDecelGainEnaCal_Logl();
  (void)memcpy(InertiaCmpVelAssiBasdDampgCoeffX_Ary1D_data, TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelAssiBasdDampgCoeffX_Ary1D(), sizeof(Ary1D_u4p12_10));
  (void)memcpy(InertiaCmpVelAssiBasdDampgRollgWhlImbRejctnOnY_Ary1D_data, TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelAssiBasdDampgRollgWhlImbRejctnOnY_Ary1D(), sizeof(Ary1D_u0p16_10));
  (void)memcpy(InertiaCmpVelAssiBasdDampgRollgY_Ary1D_data, TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelAssiBasdDampgRollgY_Ary1D(), sizeof(Ary1D_u0p16_10));
  (void)memcpy(InertiaCmpVelAssiBasdDampgStatWhlImbRejctnOnY_Ary1D_data, TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelAssiBasdDampgStatWhlImbRejctnOnY_Ary1D(), sizeof(Ary1D_u0p16_10));
  (void)memcpy(InertiaCmpVelAssiBasdDampgStatY_Ary1D_data, TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelAssiBasdDampgStatY_Ary1D(), sizeof(Ary1D_u0p16_10));
  (void)memcpy(InertiaCmpVelCmdScaY_Ary1D_data, TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelCmdScaY_Ary1D(), sizeof(Ary1D_u2p14_12));
  (void)memcpy(InertiaCmpVelDampgDecelGainRisngSlewX_Ary1D_data, TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelDampgDecelGainRisngSlewX_Ary1D(), sizeof(Ary1D_u11p5_6));
  (void)memcpy(InertiaCmpVelDampgDecelGainRisngSlewY_Ary1D_data, TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelDampgDecelGainRisngSlewY_Ary1D(), sizeof(Ary1D_u13p3_6));
  (void)memcpy(InertiaCmpVelDampgFilFrq_Ary1D_data, TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelDampgFilFrq_Ary1D(), sizeof(Ary1D_u7p9_12));
  (void)memcpy(InertiaCmpVelDampgFilFrqWhlImbRejctnOn_Ary1D_data, TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelDampgFilFrqWhlImbRejctnOn_Ary1D(), sizeof(Ary1D_u7p9_12));
  (void)memcpy(InertiaCmpVelDampgSpdBlndY_Ary1D_data, TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelDampgSpdBlndY_Ary1D(), sizeof(Ary1D_u1p15_12));
  (void)memcpy(InertiaCmpVelDampgWhlImbRejctnBlndX_Ary1D_data, TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelDampgWhlImbRejctnBlndX_Ary1D(), sizeof(Ary1D_u4p12_5));
  (void)memcpy(InertiaCmpVelDampgWhlImbRejctnBlndY_Ary1D_data, TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelDampgWhlImbRejctnBlndY_Ary1D(), sizeof(Ary1D_u1p15_5));
  (void)memcpy(InertiaCmpVelModWhlImbRejctnBlndX_Ary1D_data, TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelModWhlImbRejctnBlndX_Ary1D(), sizeof(Ary1D_u4p12_2));
  (void)memcpy(InertiaCmpVelModWhlImbRejctnBlndY_Ary1D_data, TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelModWhlImbRejctnBlndY_Ary1D(), sizeof(Ary1D_u1p15_2));
  (void)memcpy(InertiaCmpVelMotVelBasdOutpScagX_Ary1D_data, TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelMotVelBasdOutpScagX_Ary1D(), sizeof(Ary1D_u12p4_2));
  (void)memcpy(InertiaCmpVelMotVelBasdOutpScagY_Ary1D_data, TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelMotVelBasdOutpScagY_Ary1D(), sizeof(Ary1D_u1p15_2));
  (void)memcpy(InertiaCmpVelNotchBlndY_Ary1D_data, TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelNotchBlndY_Ary1D(), sizeof(Ary1D_u1p15_12));
  (void)memcpy(InertiaCmpVelTqSnsrVelSca_Ary1D_data, TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelTqSnsrVelSca_Ary1D(), sizeof(Ary1D_u2p14_12));
  (void)memcpy(SysGlbPrmVehSpdBilnrSeln_Ary1D_data, TSC_InertiaCmpVel_Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D(), sizeof(Ary1D_u9p7_12));
  InertiaCmpVelNotchFilStruct_Rec_data = *TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelNotchFilStruct_Rec();

  fct_status = TSC_InertiaCmpVel_Rte_Read_AssiCmdBas_Val(&Read_AssiCmdBas_Val);
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

  fct_status = TSC_InertiaCmpVel_Rte_Read_HwTq_Val(&Read_HwTq_Val);
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

  fct_status = TSC_InertiaCmpVel_Rte_Read_InertiaCmpDecelGainDi_Logl(&Read_InertiaCmpDecelGainDi_Logl);
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

  fct_status = TSC_InertiaCmpVel_Rte_Read_InertiaCmpVelCmdDi_Logl(&Read_InertiaCmpVelCmdDi_Logl);
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

  fct_status = TSC_InertiaCmpVel_Rte_Read_MotVelCrf_Val(&Read_MotVelCrf_Val);
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

  fct_status = TSC_InertiaCmpVel_Rte_Read_VehLgtA_Val(&Read_VehLgtA_Val);
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

  fct_status = TSC_InertiaCmpVel_Rte_Read_VehSpd_Val(&Read_VehSpd_Val);
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

  fct_status = TSC_InertiaCmpVel_Rte_Read_WhlImbRejctnAmp_Val(&Read_WhlImbRejctnAmp_Val);
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

  fct_status = TSC_InertiaCmpVel_Rte_Write_InertiaCmpVelCmd_Val(Rte_InitValue_InertiaCmpVelCmd_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_InertiaCmpVel_Rte_Call_FltInj_f32_Oper(&Call_FltInj_f32_Oper_SigPah_Arg, 0U);
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


#define InertiaCmpVel_STOP_SEC_CODE
#include "InertiaCmpVel_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


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
