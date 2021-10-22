/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  AAACalRegn01Inin01GroupD_Dummy.c
 *        Config:  EPS.dpa
 *     SW-C Type:  AAACalRegn01Inin01GroupD_Dummy
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <AAACalRegn01Inin01GroupD_Dummy>
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

#include "Rte_AAACalRegn01Inin01GroupD_Dummy.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_AAACalRegn01Inin01GroupD_Dummy.h"


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
 * Ary1D_u0p16_2: Array with 2 element(s) of type u0p16
 * Ary1D_u11p5_6: Array with 6 element(s) of type u11p5
 * Ary1D_u12p4_2: Array with 2 element(s) of type u12p4
 * Ary1D_u12p4_4: Array with 4 element(s) of type u12p4
 * Ary1D_u13p3_6: Array with 6 element(s) of type u13p3
 * Ary1D_u1p15_12: Array with 12 element(s) of type u1p15
 * Ary1D_u1p15_2: Array with 2 element(s) of type u1p15
 * Ary1D_u1p15_4: Array with 4 element(s) of type u1p15
 * Ary1D_u1p15_5: Array with 5 element(s) of type u1p15
 * Ary1D_u2p14_12: Array with 12 element(s) of type u2p14
 * Ary1D_u4p12_10: Array with 10 element(s) of type u4p12
 * Ary1D_u4p12_2: Array with 2 element(s) of type u4p12
 * Ary1D_u4p12_5: Array with 5 element(s) of type u4p12
 * Ary1D_u7p9_12: Array with 12 element(s) of type u7p9
 * Ary1D_u9p7_4: Array with 4 element(s) of type u9p7
 * Ary1D_u9p7_5: Array with 5 element(s) of type u9p7
 * Ary2D_u0p16_4_2: Array with 4 element(s) of type Ary1D_u0p16_2
 * Ary2D_u12p4_4_2: Array with 4 element(s) of type Ary1D_u12p4_2
 * Ary2D_u12p4_5_4: Array with 5 element(s) of type Ary1D_u12p4_4
 * Ary2D_u1p15_5_4: Array with 5 element(s) of type Ary1D_u1p15_4
 *
 * Record Types:
 * =============
 * FilNotchGainRec1: Record with elements
 *   FilGainB0 of type float32
 *   FilGainB1 of type float32
 *   FilGainB2 of type float32
 *   FilGainA1 of type float32
 *   FilGainA2 of type float32
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_EotProtnDeltaTqThd_Val(Rte_Instance self)
 *   float32 Rte_Prm_EotProtnEntrGainAuthyThd_Val(Rte_Instance self)
 *   float32 Rte_Prm_EotProtnEntrStLpFilFrq_Val(Rte_Instance self)
 *   float32 Rte_Prm_EotProtnExitStLpFilFrq_Val(Rte_Instance self)
 *   float32 Rte_Prm_EotProtnHwTqLpFilFrq_Val(Rte_Instance self)
 *   float32 Rte_Prm_EotProtnMotSpdIncptSca_Val(Rte_Instance self)
 *   float32 Rte_Prm_EotProtnMotVelGain_Val(Rte_Instance self)
 *   float32 Rte_Prm_EotProtnPosnRampStep_Val(Rte_Instance self)
 *   float32 Rte_Prm_EotProtnRackTrvlLimrAuthyThd_Val(Rte_Instance self)
 *   float32 Rte_Prm_EotProtnRackTrvlLimrAuthyThdLimd_Val(Rte_Instance self)
 *   float32 Rte_Prm_EotProtnRackTrvlLimrRng_Val(Rte_Instance self)
 *   float32 Rte_Prm_EotProtnRackTrvlLimrRngLimd_Val(Rte_Instance self)
 *   float32 Rte_Prm_EotProtnRackTrvlLimrVehSpdThd_Val(Rte_Instance self)
 *   float32 Rte_Prm_InertiaCmpVelDampgDecelGain_Val(Rte_Instance self)
 *   float32 Rte_Prm_InertiaCmpVelDampgDecelGainFallSlew_Val(Rte_Instance self)
 *   float32 Rte_Prm_InertiaCmpVelDampgGainOffThd_Val(Rte_Instance self)
 *   float32 Rte_Prm_InertiaCmpVelDampgGainOnThd_Val(Rte_Instance self)
 *   float32 Rte_Prm_InertiaCmpVelMotInertia_Val(Rte_Instance self)
 *   float32 Rte_Prm_InertiaCmpVelTqSnsrVelFilFrq_Val(Rte_Instance self)
 *   boolean Rte_Prm_EotProtnRunEotVelImpctAndSoftEndStop_Logl(Rte_Instance self)
 *   boolean Rte_Prm_InertiaCmpVelDecelGainEnaCal_Logl(Rte_Instance self)
 *   u9p7 *Rte_Prm_EotProtnDampgVehSpdTbl_Ary1D(Rte_Instance self)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_4
 *   u9p7 *Rte_Prm_EotProtnEntrGainVehSpdTbl_Ary1D(Rte_Instance self)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_5
 *   u12p4 *Rte_Prm_EotProtnEntrGainX_Ary2D(Rte_Instance self)
 *     Returnvalue: u12p4* is of type Ary2D_u12p4_5_4
 *   u1p15 *Rte_Prm_EotProtnEntrGainY_Ary2D(Rte_Instance self)
 *     Returnvalue: u1p15* is of type Ary2D_u1p15_5_4
 *   u0p16 *Rte_Prm_EotProtnExitDampgY_Ary2D(Rte_Instance self)
 *     Returnvalue: u0p16* is of type Ary2D_u0p16_4_2
 *   u12p4 *Rte_Prm_EotProtnHwDegDampgX_Ary2D(Rte_Instance self)
 *     Returnvalue: u12p4* is of type Ary2D_u12p4_4_2
 *   u4p12 *Rte_Prm_EotProtnHwTqScaX_Ary1D(Rte_Instance self)
 *     Returnvalue: u4p12* is of type Ary1D_u4p12_2
 *   u1p15 *Rte_Prm_EotProtnLoAuthyEntrGainY_Ary2D(Rte_Instance self)
 *     Returnvalue: u1p15* is of type Ary2D_u1p15_5_4
 *   u12p4 *Rte_Prm_EotProtnMotSpdIncptX_Ary1D(Rte_Instance self)
 *     Returnvalue: u12p4* is of type Ary1D_u12p4_2
 *   u12p4 *Rte_Prm_EotProtnMotSpdIncptY_Ary1D(Rte_Instance self)
 *     Returnvalue: u12p4* is of type Ary1D_u12p4_2
 *   u0p16 *Rte_Prm_EotProtnNormDampgY_Ary2D(Rte_Instance self)
 *     Returnvalue: u0p16* is of type Ary2D_u0p16_4_2
 *   u4p12 *Rte_Prm_InertiaCmpVelAssiBasdDampgCoeffX_Ary1D(Rte_Instance self)
 *     Returnvalue: u4p12* is of type Ary1D_u4p12_10
 *   u0p16 *Rte_Prm_InertiaCmpVelAssiBasdDampgRollgWhlImbRejctnOnY_Ary1D(Rte_Instance self)
 *     Returnvalue: u0p16* is of type Ary1D_u0p16_10
 *   u0p16 *Rte_Prm_InertiaCmpVelAssiBasdDampgRollgY_Ary1D(Rte_Instance self)
 *     Returnvalue: u0p16* is of type Ary1D_u0p16_10
 *   u0p16 *Rte_Prm_InertiaCmpVelAssiBasdDampgStatWhlImbRejctnOnY_Ary1D(Rte_Instance self)
 *     Returnvalue: u0p16* is of type Ary1D_u0p16_10
 *   u0p16 *Rte_Prm_InertiaCmpVelAssiBasdDampgStatY_Ary1D(Rte_Instance self)
 *     Returnvalue: u0p16* is of type Ary1D_u0p16_10
 *   u2p14 *Rte_Prm_InertiaCmpVelCmdScaY_Ary1D(Rte_Instance self)
 *     Returnvalue: u2p14* is of type Ary1D_u2p14_12
 *   u11p5 *Rte_Prm_InertiaCmpVelDampgDecelGainRisngSlewX_Ary1D(Rte_Instance self)
 *     Returnvalue: u11p5* is of type Ary1D_u11p5_6
 *   u13p3 *Rte_Prm_InertiaCmpVelDampgDecelGainRisngSlewY_Ary1D(Rte_Instance self)
 *     Returnvalue: u13p3* is of type Ary1D_u13p3_6
 *   u7p9 *Rte_Prm_InertiaCmpVelDampgFilFrq_Ary1D(Rte_Instance self)
 *     Returnvalue: u7p9* is of type Ary1D_u7p9_12
 *   u7p9 *Rte_Prm_InertiaCmpVelDampgFilFrqWhlImbRejctnOn_Ary1D(Rte_Instance self)
 *     Returnvalue: u7p9* is of type Ary1D_u7p9_12
 *   u1p15 *Rte_Prm_InertiaCmpVelDampgSpdBlndY_Ary1D(Rte_Instance self)
 *     Returnvalue: u1p15* is of type Ary1D_u1p15_12
 *   u4p12 *Rte_Prm_InertiaCmpVelDampgWhlImbRejctnBlndX_Ary1D(Rte_Instance self)
 *     Returnvalue: u4p12* is of type Ary1D_u4p12_5
 *   u1p15 *Rte_Prm_InertiaCmpVelDampgWhlImbRejctnBlndY_Ary1D(Rte_Instance self)
 *     Returnvalue: u1p15* is of type Ary1D_u1p15_5
 *   u4p12 *Rte_Prm_InertiaCmpVelModWhlImbRejctnBlndX_Ary1D(Rte_Instance self)
 *     Returnvalue: u4p12* is of type Ary1D_u4p12_2
 *   u1p15 *Rte_Prm_InertiaCmpVelModWhlImbRejctnBlndY_Ary1D(Rte_Instance self)
 *     Returnvalue: u1p15* is of type Ary1D_u1p15_2
 *   u12p4 *Rte_Prm_InertiaCmpVelMotVelBasdOutpScagX_Ary1D(Rte_Instance self)
 *     Returnvalue: u12p4* is of type Ary1D_u12p4_2
 *   u1p15 *Rte_Prm_InertiaCmpVelMotVelBasdOutpScagY_Ary1D(Rte_Instance self)
 *     Returnvalue: u1p15* is of type Ary1D_u1p15_2
 *   u1p15 *Rte_Prm_InertiaCmpVelNotchBlndY_Ary1D(Rte_Instance self)
 *     Returnvalue: u1p15* is of type Ary1D_u1p15_12
 *   u2p14 *Rte_Prm_InertiaCmpVelTqSnsrVelSca_Ary1D(Rte_Instance self)
 *     Returnvalue: u2p14* is of type Ary1D_u2p14_12
 *   FilNotchGainRec1 *Rte_Prm_InertiaCmpVelNotchFilStruct_Rec(Rte_Instance self)
 *
 *********************************************************************************************************************/


#define AAACalRegn01Inin01GroupD_Dummy_START_SEC_CODE
#include "AAACalRegn01Inin01GroupD_Dummy_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CalRegn01Inin01GroupDDummyInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CalRegn01Inin01GroupDDummyInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, AAACalRegn01Inin01GroupD_Dummy_CODE) CalRegn01Inin01GroupDDummyInit1(Rte_Instance self) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CalRegn01Inin01GroupDDummyInit1
 *********************************************************************************************************************/

  float32 EotProtnDeltaTqThd_Val_data;
  float32 EotProtnEntrGainAuthyThd_Val_data;
  float32 EotProtnEntrStLpFilFrq_Val_data;
  float32 EotProtnExitStLpFilFrq_Val_data;
  float32 EotProtnHwTqLpFilFrq_Val_data;
  float32 EotProtnMotSpdIncptSca_Val_data;
  float32 EotProtnMotVelGain_Val_data;
  float32 EotProtnPosnRampStep_Val_data;
  float32 EotProtnRackTrvlLimrAuthyThd_Val_data;
  float32 EotProtnRackTrvlLimrAuthyThdLimd_Val_data;
  float32 EotProtnRackTrvlLimrRng_Val_data;
  float32 EotProtnRackTrvlLimrRngLimd_Val_data;
  float32 EotProtnRackTrvlLimrVehSpdThd_Val_data;
  float32 InertiaCmpVelDampgDecelGain_Val_data;
  float32 InertiaCmpVelDampgDecelGainFallSlew_Val_data;
  float32 InertiaCmpVelDampgGainOffThd_Val_data;
  float32 InertiaCmpVelDampgGainOnThd_Val_data;
  float32 InertiaCmpVelMotInertia_Val_data;
  float32 InertiaCmpVelTqSnsrVelFilFrq_Val_data;
  boolean EotProtnRunEotVelImpctAndSoftEndStop_Logl_data;
  boolean InertiaCmpVelDecelGainEnaCal_Logl_data;
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
  FilNotchGainRec1 InertiaCmpVelNotchFilStruct_Rec_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  EotProtnDeltaTqThd_Val_data = TSC_AAACalRegn01Inin01GroupD_Dummy_Rte_Prm_EotProtnDeltaTqThd_Val(self);
  EotProtnEntrGainAuthyThd_Val_data = TSC_AAACalRegn01Inin01GroupD_Dummy_Rte_Prm_EotProtnEntrGainAuthyThd_Val(self);
  EotProtnEntrStLpFilFrq_Val_data = TSC_AAACalRegn01Inin01GroupD_Dummy_Rte_Prm_EotProtnEntrStLpFilFrq_Val(self);
  EotProtnExitStLpFilFrq_Val_data = TSC_AAACalRegn01Inin01GroupD_Dummy_Rte_Prm_EotProtnExitStLpFilFrq_Val(self);
  EotProtnHwTqLpFilFrq_Val_data = TSC_AAACalRegn01Inin01GroupD_Dummy_Rte_Prm_EotProtnHwTqLpFilFrq_Val(self);
  EotProtnMotSpdIncptSca_Val_data = TSC_AAACalRegn01Inin01GroupD_Dummy_Rte_Prm_EotProtnMotSpdIncptSca_Val(self);
  EotProtnMotVelGain_Val_data = TSC_AAACalRegn01Inin01GroupD_Dummy_Rte_Prm_EotProtnMotVelGain_Val(self);
  EotProtnPosnRampStep_Val_data = TSC_AAACalRegn01Inin01GroupD_Dummy_Rte_Prm_EotProtnPosnRampStep_Val(self);
  EotProtnRackTrvlLimrAuthyThd_Val_data = TSC_AAACalRegn01Inin01GroupD_Dummy_Rte_Prm_EotProtnRackTrvlLimrAuthyThd_Val(self);
  EotProtnRackTrvlLimrAuthyThdLimd_Val_data = TSC_AAACalRegn01Inin01GroupD_Dummy_Rte_Prm_EotProtnRackTrvlLimrAuthyThdLimd_Val(self);
  EotProtnRackTrvlLimrRng_Val_data = TSC_AAACalRegn01Inin01GroupD_Dummy_Rte_Prm_EotProtnRackTrvlLimrRng_Val(self);
  EotProtnRackTrvlLimrRngLimd_Val_data = TSC_AAACalRegn01Inin01GroupD_Dummy_Rte_Prm_EotProtnRackTrvlLimrRngLimd_Val(self);
  EotProtnRackTrvlLimrVehSpdThd_Val_data = TSC_AAACalRegn01Inin01GroupD_Dummy_Rte_Prm_EotProtnRackTrvlLimrVehSpdThd_Val(self);
  InertiaCmpVelDampgDecelGain_Val_data = TSC_AAACalRegn01Inin01GroupD_Dummy_Rte_Prm_InertiaCmpVelDampgDecelGain_Val(self);
  InertiaCmpVelDampgDecelGainFallSlew_Val_data = TSC_AAACalRegn01Inin01GroupD_Dummy_Rte_Prm_InertiaCmpVelDampgDecelGainFallSlew_Val(self);
  InertiaCmpVelDampgGainOffThd_Val_data = TSC_AAACalRegn01Inin01GroupD_Dummy_Rte_Prm_InertiaCmpVelDampgGainOffThd_Val(self);
  InertiaCmpVelDampgGainOnThd_Val_data = TSC_AAACalRegn01Inin01GroupD_Dummy_Rte_Prm_InertiaCmpVelDampgGainOnThd_Val(self);
  InertiaCmpVelMotInertia_Val_data = TSC_AAACalRegn01Inin01GroupD_Dummy_Rte_Prm_InertiaCmpVelMotInertia_Val(self);
  InertiaCmpVelTqSnsrVelFilFrq_Val_data = TSC_AAACalRegn01Inin01GroupD_Dummy_Rte_Prm_InertiaCmpVelTqSnsrVelFilFrq_Val(self);
  EotProtnRunEotVelImpctAndSoftEndStop_Logl_data = TSC_AAACalRegn01Inin01GroupD_Dummy_Rte_Prm_EotProtnRunEotVelImpctAndSoftEndStop_Logl(self);
  InertiaCmpVelDecelGainEnaCal_Logl_data = TSC_AAACalRegn01Inin01GroupD_Dummy_Rte_Prm_InertiaCmpVelDecelGainEnaCal_Logl(self);
  (void)memcpy(EotProtnDampgVehSpdTbl_Ary1D_data, TSC_AAACalRegn01Inin01GroupD_Dummy_Rte_Prm_EotProtnDampgVehSpdTbl_Ary1D(self), sizeof(Ary1D_u9p7_4));
  (void)memcpy(EotProtnEntrGainVehSpdTbl_Ary1D_data, TSC_AAACalRegn01Inin01GroupD_Dummy_Rte_Prm_EotProtnEntrGainVehSpdTbl_Ary1D(self), sizeof(Ary1D_u9p7_5));
  (void)memcpy(EotProtnEntrGainX_Ary2D_data, TSC_AAACalRegn01Inin01GroupD_Dummy_Rte_Prm_EotProtnEntrGainX_Ary2D(self), sizeof(Ary2D_u12p4_5_4));
  (void)memcpy(EotProtnEntrGainY_Ary2D_data, TSC_AAACalRegn01Inin01GroupD_Dummy_Rte_Prm_EotProtnEntrGainY_Ary2D(self), sizeof(Ary2D_u1p15_5_4));
  (void)memcpy(EotProtnExitDampgY_Ary2D_data, TSC_AAACalRegn01Inin01GroupD_Dummy_Rte_Prm_EotProtnExitDampgY_Ary2D(self), sizeof(Ary2D_u0p16_4_2));
  (void)memcpy(EotProtnHwDegDampgX_Ary2D_data, TSC_AAACalRegn01Inin01GroupD_Dummy_Rte_Prm_EotProtnHwDegDampgX_Ary2D(self), sizeof(Ary2D_u12p4_4_2));
  (void)memcpy(EotProtnHwTqScaX_Ary1D_data, TSC_AAACalRegn01Inin01GroupD_Dummy_Rte_Prm_EotProtnHwTqScaX_Ary1D(self), sizeof(Ary1D_u4p12_2));
  (void)memcpy(EotProtnLoAuthyEntrGainY_Ary2D_data, TSC_AAACalRegn01Inin01GroupD_Dummy_Rte_Prm_EotProtnLoAuthyEntrGainY_Ary2D(self), sizeof(Ary2D_u1p15_5_4));
  (void)memcpy(EotProtnMotSpdIncptX_Ary1D_data, TSC_AAACalRegn01Inin01GroupD_Dummy_Rte_Prm_EotProtnMotSpdIncptX_Ary1D(self), sizeof(Ary1D_u12p4_2));
  (void)memcpy(EotProtnMotSpdIncptY_Ary1D_data, TSC_AAACalRegn01Inin01GroupD_Dummy_Rte_Prm_EotProtnMotSpdIncptY_Ary1D(self), sizeof(Ary1D_u12p4_2));
  (void)memcpy(EotProtnNormDampgY_Ary2D_data, TSC_AAACalRegn01Inin01GroupD_Dummy_Rte_Prm_EotProtnNormDampgY_Ary2D(self), sizeof(Ary2D_u0p16_4_2));
  (void)memcpy(InertiaCmpVelAssiBasdDampgCoeffX_Ary1D_data, TSC_AAACalRegn01Inin01GroupD_Dummy_Rte_Prm_InertiaCmpVelAssiBasdDampgCoeffX_Ary1D(self), sizeof(Ary1D_u4p12_10));
  (void)memcpy(InertiaCmpVelAssiBasdDampgRollgWhlImbRejctnOnY_Ary1D_data, TSC_AAACalRegn01Inin01GroupD_Dummy_Rte_Prm_InertiaCmpVelAssiBasdDampgRollgWhlImbRejctnOnY_Ary1D(self), sizeof(Ary1D_u0p16_10));
  (void)memcpy(InertiaCmpVelAssiBasdDampgRollgY_Ary1D_data, TSC_AAACalRegn01Inin01GroupD_Dummy_Rte_Prm_InertiaCmpVelAssiBasdDampgRollgY_Ary1D(self), sizeof(Ary1D_u0p16_10));
  (void)memcpy(InertiaCmpVelAssiBasdDampgStatWhlImbRejctnOnY_Ary1D_data, TSC_AAACalRegn01Inin01GroupD_Dummy_Rte_Prm_InertiaCmpVelAssiBasdDampgStatWhlImbRejctnOnY_Ary1D(self), sizeof(Ary1D_u0p16_10));
  (void)memcpy(InertiaCmpVelAssiBasdDampgStatY_Ary1D_data, TSC_AAACalRegn01Inin01GroupD_Dummy_Rte_Prm_InertiaCmpVelAssiBasdDampgStatY_Ary1D(self), sizeof(Ary1D_u0p16_10));
  (void)memcpy(InertiaCmpVelCmdScaY_Ary1D_data, TSC_AAACalRegn01Inin01GroupD_Dummy_Rte_Prm_InertiaCmpVelCmdScaY_Ary1D(self), sizeof(Ary1D_u2p14_12));
  (void)memcpy(InertiaCmpVelDampgDecelGainRisngSlewX_Ary1D_data, TSC_AAACalRegn01Inin01GroupD_Dummy_Rte_Prm_InertiaCmpVelDampgDecelGainRisngSlewX_Ary1D(self), sizeof(Ary1D_u11p5_6));
  (void)memcpy(InertiaCmpVelDampgDecelGainRisngSlewY_Ary1D_data, TSC_AAACalRegn01Inin01GroupD_Dummy_Rte_Prm_InertiaCmpVelDampgDecelGainRisngSlewY_Ary1D(self), sizeof(Ary1D_u13p3_6));
  (void)memcpy(InertiaCmpVelDampgFilFrq_Ary1D_data, TSC_AAACalRegn01Inin01GroupD_Dummy_Rte_Prm_InertiaCmpVelDampgFilFrq_Ary1D(self), sizeof(Ary1D_u7p9_12));
  (void)memcpy(InertiaCmpVelDampgFilFrqWhlImbRejctnOn_Ary1D_data, TSC_AAACalRegn01Inin01GroupD_Dummy_Rte_Prm_InertiaCmpVelDampgFilFrqWhlImbRejctnOn_Ary1D(self), sizeof(Ary1D_u7p9_12));
  (void)memcpy(InertiaCmpVelDampgSpdBlndY_Ary1D_data, TSC_AAACalRegn01Inin01GroupD_Dummy_Rte_Prm_InertiaCmpVelDampgSpdBlndY_Ary1D(self), sizeof(Ary1D_u1p15_12));
  (void)memcpy(InertiaCmpVelDampgWhlImbRejctnBlndX_Ary1D_data, TSC_AAACalRegn01Inin01GroupD_Dummy_Rte_Prm_InertiaCmpVelDampgWhlImbRejctnBlndX_Ary1D(self), sizeof(Ary1D_u4p12_5));
  (void)memcpy(InertiaCmpVelDampgWhlImbRejctnBlndY_Ary1D_data, TSC_AAACalRegn01Inin01GroupD_Dummy_Rte_Prm_InertiaCmpVelDampgWhlImbRejctnBlndY_Ary1D(self), sizeof(Ary1D_u1p15_5));
  (void)memcpy(InertiaCmpVelModWhlImbRejctnBlndX_Ary1D_data, TSC_AAACalRegn01Inin01GroupD_Dummy_Rte_Prm_InertiaCmpVelModWhlImbRejctnBlndX_Ary1D(self), sizeof(Ary1D_u4p12_2));
  (void)memcpy(InertiaCmpVelModWhlImbRejctnBlndY_Ary1D_data, TSC_AAACalRegn01Inin01GroupD_Dummy_Rte_Prm_InertiaCmpVelModWhlImbRejctnBlndY_Ary1D(self), sizeof(Ary1D_u1p15_2));
  (void)memcpy(InertiaCmpVelMotVelBasdOutpScagX_Ary1D_data, TSC_AAACalRegn01Inin01GroupD_Dummy_Rte_Prm_InertiaCmpVelMotVelBasdOutpScagX_Ary1D(self), sizeof(Ary1D_u12p4_2));
  (void)memcpy(InertiaCmpVelMotVelBasdOutpScagY_Ary1D_data, TSC_AAACalRegn01Inin01GroupD_Dummy_Rte_Prm_InertiaCmpVelMotVelBasdOutpScagY_Ary1D(self), sizeof(Ary1D_u1p15_2));
  (void)memcpy(InertiaCmpVelNotchBlndY_Ary1D_data, TSC_AAACalRegn01Inin01GroupD_Dummy_Rte_Prm_InertiaCmpVelNotchBlndY_Ary1D(self), sizeof(Ary1D_u1p15_12));
  (void)memcpy(InertiaCmpVelTqSnsrVelSca_Ary1D_data, TSC_AAACalRegn01Inin01GroupD_Dummy_Rte_Prm_InertiaCmpVelTqSnsrVelSca_Ary1D(self), sizeof(Ary1D_u2p14_12));
  InertiaCmpVelNotchFilStruct_Rec_data = *TSC_AAACalRegn01Inin01GroupD_Dummy_Rte_Prm_InertiaCmpVelNotchFilStruct_Rec(self);


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define AAACalRegn01Inin01GroupD_Dummy_STOP_SEC_CODE
#include "AAACalRegn01Inin01GroupD_Dummy_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


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
