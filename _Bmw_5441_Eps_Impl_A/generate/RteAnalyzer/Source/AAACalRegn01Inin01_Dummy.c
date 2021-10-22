/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  AAACalRegn01Inin01_Dummy.c
 *        Config:  EPS.dpa
 *     SW-C Type:  AAACalRegn01Inin01_Dummy
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <AAACalRegn01Inin01_Dummy>
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
 * s15p0
 *   
 *
 * s2p13
 *   
 *
 * u11p5
 *   
 *
 * u1p15
 *   
 *
 * u4p12
 *   
 *
 * u5p11
 *   
 *
 * u6p10
 *   
 *
 * u9p7
 *   
 *
 *********************************************************************************************************************/

#include "Rte_AAACalRegn01Inin01_Dummy.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_AAACalRegn01Inin01_Dummy.h"


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
 * s15p0: Integer in interval [-32768...32767]
 * s2p13: Integer in interval [-32768...32767]
 * sint16: Integer in interval [-32768...32767] (standard type)
 * u11p5: Integer in interval [0...65535]
 * u1p15: Integer in interval [0...65535]
 * u4p12: Integer in interval [0...65535]
 * u5p11: Integer in interval [0...65535]
 * u6p10: Integer in interval [0...65535]
 * u9p7: Integer in interval [0...65535]
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 *
 * Array Types:
 * ============
 * Ary1D_f32_2: Array with 2 element(s) of type float32
 * Ary1D_f32_4: Array with 4 element(s) of type float32
 * Ary1D_logl_4: Array with 4 element(s) of type boolean
 * Ary1D_s15p0_10: Array with 10 element(s) of type s15p0
 * Ary1D_s2p13_21: Array with 21 element(s) of type s2p13
 * Ary1D_u11p5_10: Array with 10 element(s) of type u11p5
 * Ary1D_u16_3: Array with 3 element(s) of type uint16
 * Ary1D_u1p15_10: Array with 10 element(s) of type u1p15
 * Ary1D_u1p15_21: Array with 21 element(s) of type u1p15
 * Ary1D_u4p12_21: Array with 21 element(s) of type u4p12
 * Ary1D_u5p11_21: Array with 21 element(s) of type u5p11
 * Ary1D_u6p10_10: Array with 10 element(s) of type u6p10
 * Ary1D_u9p7_12: Array with 12 element(s) of type u9p7
 * Ary1D_u9p7_6: Array with 6 element(s) of type u9p7
 * Ary2D_f32_4_2: Array with 4 element(s) of type Ary1D_f32_2
 * Ary2D_f32_8_4: Array with 8 element(s) of type Ary1D_f32_4
 * Ary2D_u16_8_3: Array with 8 element(s) of type Ary1D_u16_3
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
 *   float32 Rte_Prm_BmwHwAgArbnAndEotPosnKineIntegrityDiagcMaxRackLim_Val(Rte_Instance self)
 *   float32 Rte_Prm_EffortScaRackFThd_Val(Rte_Instance self)
 *   float32 Rte_Prm_PosnTrakgServoArbnFltMtgtnLpFilCutOffFrq_Val(Rte_Instance self)
 *   float32 Rte_Prm_PullCmpActvHwTqFilFrqLrngEna_Val(Rte_Instance self)
 *   float32 Rte_Prm_PullCmpActvYawRateFilFrq_Val(Rte_Instance self)
 *   float32 Rte_Prm_SysFricLrngAvrgFricFrq_Val(Rte_Instance self)
 *   float32 Rte_Prm_SysFricLrngBasLineEolFric_Val(Rte_Instance self)
 *   float32 Rte_Prm_SysFricLrngDataPrepLpFilFrq_Val(Rte_Instance self)
 *   float32 Rte_Prm_SysFricLrngEolFricDifHiLim_Val(Rte_Instance self)
 *   float32 Rte_Prm_SysFricLrngEolFricDifLoLim_Val(Rte_Instance self)
 *   float32 Rte_Prm_SysFricLrngEolFricDifScagFac_Val(Rte_Instance self)
 *   float32 Rte_Prm_SysFricLrngFricDiagcThd_Val(Rte_Instance self)
 *   float32 Rte_Prm_SysFricLrngFricOffs_Val(Rte_Instance self)
 *   float32 Rte_Prm_SysFricLrngFricOffsHiLim_Val(Rte_Instance self)
 *   float32 Rte_Prm_SysFricLrngFricOffsLoLim_Val(Rte_Instance self)
 *   float32 Rte_Prm_SysFricLrngFricOffsLpFilFrq_Val(Rte_Instance self)
 *   float32 Rte_Prm_SysFricLrngGain_Val(Rte_Instance self)
 *   float32 Rte_Prm_SysFricLrngHiFricDiagcThd_Val(Rte_Instance self)
 *   float32 Rte_Prm_SysFricLrngHwPosnAuthyThd_Val(Rte_Instance self)
 *   float32 Rte_Prm_SysFricLrngHwVelConstrLim_Val(Rte_Instance self)
 *   float32 Rte_Prm_SysFricLrngHwVelHiLim_Val(Rte_Instance self)
 *   float32 Rte_Prm_SysFricLrngHwVelLoLim_Val(Rte_Instance self)
 *   float32 Rte_Prm_SysFricLrngIgnCycFricChgLim_Val(Rte_Instance self)
 *   float32 Rte_Prm_SysFricLrngIgnCycFricOffs_Val(Rte_Instance self)
 *   float32 Rte_Prm_SysFricLrngLatAHiLim_Val(Rte_Instance self)
 *   float32 Rte_Prm_SysFricLrngLatALoLim_Val(Rte_Instance self)
 *   float32 Rte_Prm_SysFricLrngTHiLim_Val(Rte_Instance self)
 *   float32 Rte_Prm_SysFricLrngTLoLim_Val(Rte_Instance self)
 *   float32 Rte_Prm_SysGlbPrmSysKineRat_Val(Rte_Instance self)
 *   uint32 Rte_Prm_SysFricLrngThd_Val(Rte_Instance self)
 *   uint16 Rte_Prm_SysFricLrngDebStep_Val(Rte_Instance self)
 *   uint16 Rte_Prm_SysFricLrngHiFricDebStep_Val(Rte_Instance self)
 *   uint16 Rte_Prm_SysFricLrngRngCntrThd_Val(Rte_Instance self)
 *   s15p0 *Rte_Prm_EffortScaBlndX_Ary1D(Rte_Instance self)
 *     Returnvalue: s15p0* is of type Ary1D_s15p0_10
 *   u1p15 *Rte_Prm_EffortScaBlndY_Ary1D(Rte_Instance self)
 *     Returnvalue: u1p15* is of type Ary1D_u1p15_10
 *   float32 *Rte_Prm_SysFricLrngBasLineFric_Ary1D(Rte_Instance self)
 *     Returnvalue: float32* is of type Ary1D_f32_4
 *   float32 *Rte_Prm_SysFricLrngBasLineHys_Ary2D(Rte_Instance self)
 *     Returnvalue: float32* is of type Ary2D_f32_8_4
 *   uint16 *Rte_Prm_SysFricLrngBasLineRngCntr_Ary2D(Rte_Instance self)
 *     Returnvalue: uint16* is of type Ary2D_u16_8_3
 *   float32 *Rte_Prm_SysFricLrngFricChgWght_Ary1D(Rte_Instance self)
 *     Returnvalue: float32* is of type Ary1D_f32_4
 *   float32 *Rte_Prm_SysFricLrngFricHysHwAgPt_Ary1D(Rte_Instance self)
 *     Returnvalue: float32* is of type Ary1D_f32_4
 *   u11p5 *Rte_Prm_SysFricLrngIvsTrsmRatX_Ary1D(Rte_Instance self)
 *     Returnvalue: u11p5* is of type Ary1D_u11p5_10
 *   u6p10 *Rte_Prm_SysFricLrngIvsTrsmRatY_Ary1D(Rte_Instance self)
 *     Returnvalue: u6p10* is of type Ary1D_u6p10_10
 *   boolean *Rte_Prm_SysFricLrngMaskVehSpd_Ary1D(Rte_Instance self)
 *     Returnvalue: boolean* is of type Ary1D_logl_4
 *   float32 *Rte_Prm_SysFricLrngVehSpd_Ary2D(Rte_Instance self)
 *     Returnvalue: float32* is of type Ary2D_f32_4_2
 *   u9p7 *Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D(Rte_Instance self)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_12
 *   u4p12 *Rte_Prm_SysKineAndEffMotAgToRackPosRatScaY_Ary1D(Rte_Instance self)
 *     Returnvalue: u4p12* is of type Ary1D_u4p12_21
 *   u5p11 *Rte_Prm_SysKineAndEffPinionAgToRackPosRatScaY_Ary1D(Rte_Instance self)
 *     Returnvalue: u5p11* is of type Ary1D_u5p11_21
 *   u1p15 *Rte_Prm_SysKineAndEffPinionToRackEffScaY_Ary1D(Rte_Instance self)
 *     Returnvalue: u1p15* is of type Ary1D_u1p15_21
 *   s2p13 *Rte_Prm_SysKineAndEffRoadWhlFromRackPosScaY_Ary1D(Rte_Instance self)
 *     Returnvalue: s2p13* is of type Ary1D_s2p13_21
 *   u1p15 *Rte_Prm_SysKineAndEffSteerArmLenFromRackPosScaY_Ary1D(Rte_Instance self)
 *     Returnvalue: u1p15* is of type Ary1D_u1p15_21
 *   u9p7 *Rte_Prm_TunSelnAuthyVehSpdX_Ary1D(Rte_Instance self)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_6
 *
 *********************************************************************************************************************/


#define AAACalRegn01Inin01_Dummy_START_SEC_CODE
#include "AAACalRegn01Inin01_Dummy_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CalRegn01Inin01DummyInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CalRegn01Inin01DummyInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, AAACalRegn01Inin01_Dummy_CODE) CalRegn01Inin01DummyInit1(Rte_Instance self) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CalRegn01Inin01DummyInit1
 *********************************************************************************************************************/

  float32 BmwHwAgArbnAndEotPosnKineIntegrityDiagcMaxRackLim_Val_data;
  float32 EffortScaRackFThd_Val_data;
  float32 PosnTrakgServoArbnFltMtgtnLpFilCutOffFrq_Val_data;
  float32 PullCmpActvHwTqFilFrqLrngEna_Val_data;
  float32 PullCmpActvYawRateFilFrq_Val_data;
  float32 SysFricLrngAvrgFricFrq_Val_data;
  float32 SysFricLrngBasLineEolFric_Val_data;
  float32 SysFricLrngDataPrepLpFilFrq_Val_data;
  float32 SysFricLrngEolFricDifHiLim_Val_data;
  float32 SysFricLrngEolFricDifLoLim_Val_data;
  float32 SysFricLrngEolFricDifScagFac_Val_data;
  float32 SysFricLrngFricDiagcThd_Val_data;
  float32 SysFricLrngFricOffs_Val_data;
  float32 SysFricLrngFricOffsHiLim_Val_data;
  float32 SysFricLrngFricOffsLoLim_Val_data;
  float32 SysFricLrngFricOffsLpFilFrq_Val_data;
  float32 SysFricLrngGain_Val_data;
  float32 SysFricLrngHiFricDiagcThd_Val_data;
  float32 SysFricLrngHwPosnAuthyThd_Val_data;
  float32 SysFricLrngHwVelConstrLim_Val_data;
  float32 SysFricLrngHwVelHiLim_Val_data;
  float32 SysFricLrngHwVelLoLim_Val_data;
  float32 SysFricLrngIgnCycFricChgLim_Val_data;
  float32 SysFricLrngIgnCycFricOffs_Val_data;
  float32 SysFricLrngLatAHiLim_Val_data;
  float32 SysFricLrngLatALoLim_Val_data;
  float32 SysFricLrngTHiLim_Val_data;
  float32 SysFricLrngTLoLim_Val_data;
  float32 SysGlbPrmSysKineRat_Val_data;
  uint32 SysFricLrngThd_Val_data;
  uint16 SysFricLrngDebStep_Val_data;
  uint16 SysFricLrngHiFricDebStep_Val_data;
  uint16 SysFricLrngRngCntrThd_Val_data;
  Ary1D_s15p0_10 EffortScaBlndX_Ary1D_data;
  Ary1D_u1p15_10 EffortScaBlndY_Ary1D_data;
  Ary1D_f32_4 SysFricLrngBasLineFric_Ary1D_data;
  Ary2D_f32_8_4 SysFricLrngBasLineHys_Ary2D_data;
  Ary2D_u16_8_3 SysFricLrngBasLineRngCntr_Ary2D_data;
  Ary1D_f32_4 SysFricLrngFricChgWght_Ary1D_data;
  Ary1D_f32_4 SysFricLrngFricHysHwAgPt_Ary1D_data;
  Ary1D_u11p5_10 SysFricLrngIvsTrsmRatX_Ary1D_data;
  Ary1D_u6p10_10 SysFricLrngIvsTrsmRatY_Ary1D_data;
  Ary1D_logl_4 SysFricLrngMaskVehSpd_Ary1D_data;
  Ary2D_f32_4_2 SysFricLrngVehSpd_Ary2D_data;
  Ary1D_u9p7_12 SysGlbPrmVehSpdBilnrSeln_Ary1D_data;
  Ary1D_u4p12_21 SysKineAndEffMotAgToRackPosRatScaY_Ary1D_data;
  Ary1D_u5p11_21 SysKineAndEffPinionAgToRackPosRatScaY_Ary1D_data;
  Ary1D_u1p15_21 SysKineAndEffPinionToRackEffScaY_Ary1D_data;
  Ary1D_s2p13_21 SysKineAndEffRoadWhlFromRackPosScaY_Ary1D_data;
  Ary1D_u1p15_21 SysKineAndEffSteerArmLenFromRackPosScaY_Ary1D_data;
  Ary1D_u9p7_6 TunSelnAuthyVehSpdX_Ary1D_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  BmwHwAgArbnAndEotPosnKineIntegrityDiagcMaxRackLim_Val_data = TSC_AAACalRegn01Inin01_Dummy_Rte_Prm_BmwHwAgArbnAndEotPosnKineIntegrityDiagcMaxRackLim_Val(self);
  EffortScaRackFThd_Val_data = TSC_AAACalRegn01Inin01_Dummy_Rte_Prm_EffortScaRackFThd_Val(self);
  PosnTrakgServoArbnFltMtgtnLpFilCutOffFrq_Val_data = TSC_AAACalRegn01Inin01_Dummy_Rte_Prm_PosnTrakgServoArbnFltMtgtnLpFilCutOffFrq_Val(self);
  PullCmpActvHwTqFilFrqLrngEna_Val_data = TSC_AAACalRegn01Inin01_Dummy_Rte_Prm_PullCmpActvHwTqFilFrqLrngEna_Val(self);
  PullCmpActvYawRateFilFrq_Val_data = TSC_AAACalRegn01Inin01_Dummy_Rte_Prm_PullCmpActvYawRateFilFrq_Val(self);
  SysFricLrngAvrgFricFrq_Val_data = TSC_AAACalRegn01Inin01_Dummy_Rte_Prm_SysFricLrngAvrgFricFrq_Val(self);
  SysFricLrngBasLineEolFric_Val_data = TSC_AAACalRegn01Inin01_Dummy_Rte_Prm_SysFricLrngBasLineEolFric_Val(self);
  SysFricLrngDataPrepLpFilFrq_Val_data = TSC_AAACalRegn01Inin01_Dummy_Rte_Prm_SysFricLrngDataPrepLpFilFrq_Val(self);
  SysFricLrngEolFricDifHiLim_Val_data = TSC_AAACalRegn01Inin01_Dummy_Rte_Prm_SysFricLrngEolFricDifHiLim_Val(self);
  SysFricLrngEolFricDifLoLim_Val_data = TSC_AAACalRegn01Inin01_Dummy_Rte_Prm_SysFricLrngEolFricDifLoLim_Val(self);
  SysFricLrngEolFricDifScagFac_Val_data = TSC_AAACalRegn01Inin01_Dummy_Rte_Prm_SysFricLrngEolFricDifScagFac_Val(self);
  SysFricLrngFricDiagcThd_Val_data = TSC_AAACalRegn01Inin01_Dummy_Rte_Prm_SysFricLrngFricDiagcThd_Val(self);
  SysFricLrngFricOffs_Val_data = TSC_AAACalRegn01Inin01_Dummy_Rte_Prm_SysFricLrngFricOffs_Val(self);
  SysFricLrngFricOffsHiLim_Val_data = TSC_AAACalRegn01Inin01_Dummy_Rte_Prm_SysFricLrngFricOffsHiLim_Val(self);
  SysFricLrngFricOffsLoLim_Val_data = TSC_AAACalRegn01Inin01_Dummy_Rte_Prm_SysFricLrngFricOffsLoLim_Val(self);
  SysFricLrngFricOffsLpFilFrq_Val_data = TSC_AAACalRegn01Inin01_Dummy_Rte_Prm_SysFricLrngFricOffsLpFilFrq_Val(self);
  SysFricLrngGain_Val_data = TSC_AAACalRegn01Inin01_Dummy_Rte_Prm_SysFricLrngGain_Val(self);
  SysFricLrngHiFricDiagcThd_Val_data = TSC_AAACalRegn01Inin01_Dummy_Rte_Prm_SysFricLrngHiFricDiagcThd_Val(self);
  SysFricLrngHwPosnAuthyThd_Val_data = TSC_AAACalRegn01Inin01_Dummy_Rte_Prm_SysFricLrngHwPosnAuthyThd_Val(self);
  SysFricLrngHwVelConstrLim_Val_data = TSC_AAACalRegn01Inin01_Dummy_Rte_Prm_SysFricLrngHwVelConstrLim_Val(self);
  SysFricLrngHwVelHiLim_Val_data = TSC_AAACalRegn01Inin01_Dummy_Rte_Prm_SysFricLrngHwVelHiLim_Val(self);
  SysFricLrngHwVelLoLim_Val_data = TSC_AAACalRegn01Inin01_Dummy_Rte_Prm_SysFricLrngHwVelLoLim_Val(self);
  SysFricLrngIgnCycFricChgLim_Val_data = TSC_AAACalRegn01Inin01_Dummy_Rte_Prm_SysFricLrngIgnCycFricChgLim_Val(self);
  SysFricLrngIgnCycFricOffs_Val_data = TSC_AAACalRegn01Inin01_Dummy_Rte_Prm_SysFricLrngIgnCycFricOffs_Val(self);
  SysFricLrngLatAHiLim_Val_data = TSC_AAACalRegn01Inin01_Dummy_Rte_Prm_SysFricLrngLatAHiLim_Val(self);
  SysFricLrngLatALoLim_Val_data = TSC_AAACalRegn01Inin01_Dummy_Rte_Prm_SysFricLrngLatALoLim_Val(self);
  SysFricLrngTHiLim_Val_data = TSC_AAACalRegn01Inin01_Dummy_Rte_Prm_SysFricLrngTHiLim_Val(self);
  SysFricLrngTLoLim_Val_data = TSC_AAACalRegn01Inin01_Dummy_Rte_Prm_SysFricLrngTLoLim_Val(self);
  SysGlbPrmSysKineRat_Val_data = TSC_AAACalRegn01Inin01_Dummy_Rte_Prm_SysGlbPrmSysKineRat_Val(self);
  SysFricLrngThd_Val_data = TSC_AAACalRegn01Inin01_Dummy_Rte_Prm_SysFricLrngThd_Val(self);
  SysFricLrngDebStep_Val_data = TSC_AAACalRegn01Inin01_Dummy_Rte_Prm_SysFricLrngDebStep_Val(self);
  SysFricLrngHiFricDebStep_Val_data = TSC_AAACalRegn01Inin01_Dummy_Rte_Prm_SysFricLrngHiFricDebStep_Val(self);
  SysFricLrngRngCntrThd_Val_data = TSC_AAACalRegn01Inin01_Dummy_Rte_Prm_SysFricLrngRngCntrThd_Val(self);
  (void)memcpy(EffortScaBlndX_Ary1D_data, TSC_AAACalRegn01Inin01_Dummy_Rte_Prm_EffortScaBlndX_Ary1D(self), sizeof(Ary1D_s15p0_10));
  (void)memcpy(EffortScaBlndY_Ary1D_data, TSC_AAACalRegn01Inin01_Dummy_Rte_Prm_EffortScaBlndY_Ary1D(self), sizeof(Ary1D_u1p15_10));
  (void)memcpy(SysFricLrngBasLineFric_Ary1D_data, TSC_AAACalRegn01Inin01_Dummy_Rte_Prm_SysFricLrngBasLineFric_Ary1D(self), sizeof(Ary1D_f32_4));
  (void)memcpy(SysFricLrngBasLineHys_Ary2D_data, TSC_AAACalRegn01Inin01_Dummy_Rte_Prm_SysFricLrngBasLineHys_Ary2D(self), sizeof(Ary2D_f32_8_4));
  (void)memcpy(SysFricLrngBasLineRngCntr_Ary2D_data, TSC_AAACalRegn01Inin01_Dummy_Rte_Prm_SysFricLrngBasLineRngCntr_Ary2D(self), sizeof(Ary2D_u16_8_3));
  (void)memcpy(SysFricLrngFricChgWght_Ary1D_data, TSC_AAACalRegn01Inin01_Dummy_Rte_Prm_SysFricLrngFricChgWght_Ary1D(self), sizeof(Ary1D_f32_4));
  (void)memcpy(SysFricLrngFricHysHwAgPt_Ary1D_data, TSC_AAACalRegn01Inin01_Dummy_Rte_Prm_SysFricLrngFricHysHwAgPt_Ary1D(self), sizeof(Ary1D_f32_4));
  (void)memcpy(SysFricLrngIvsTrsmRatX_Ary1D_data, TSC_AAACalRegn01Inin01_Dummy_Rte_Prm_SysFricLrngIvsTrsmRatX_Ary1D(self), sizeof(Ary1D_u11p5_10));
  (void)memcpy(SysFricLrngIvsTrsmRatY_Ary1D_data, TSC_AAACalRegn01Inin01_Dummy_Rte_Prm_SysFricLrngIvsTrsmRatY_Ary1D(self), sizeof(Ary1D_u6p10_10));
  (void)memcpy(SysFricLrngMaskVehSpd_Ary1D_data, TSC_AAACalRegn01Inin01_Dummy_Rte_Prm_SysFricLrngMaskVehSpd_Ary1D(self), sizeof(Ary1D_logl_4));
  (void)memcpy(SysFricLrngVehSpd_Ary2D_data, TSC_AAACalRegn01Inin01_Dummy_Rte_Prm_SysFricLrngVehSpd_Ary2D(self), sizeof(Ary2D_f32_4_2));
  (void)memcpy(SysGlbPrmVehSpdBilnrSeln_Ary1D_data, TSC_AAACalRegn01Inin01_Dummy_Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D(self), sizeof(Ary1D_u9p7_12));
  (void)memcpy(SysKineAndEffMotAgToRackPosRatScaY_Ary1D_data, TSC_AAACalRegn01Inin01_Dummy_Rte_Prm_SysKineAndEffMotAgToRackPosRatScaY_Ary1D(self), sizeof(Ary1D_u4p12_21));
  (void)memcpy(SysKineAndEffPinionAgToRackPosRatScaY_Ary1D_data, TSC_AAACalRegn01Inin01_Dummy_Rte_Prm_SysKineAndEffPinionAgToRackPosRatScaY_Ary1D(self), sizeof(Ary1D_u5p11_21));
  (void)memcpy(SysKineAndEffPinionToRackEffScaY_Ary1D_data, TSC_AAACalRegn01Inin01_Dummy_Rte_Prm_SysKineAndEffPinionToRackEffScaY_Ary1D(self), sizeof(Ary1D_u1p15_21));
  (void)memcpy(SysKineAndEffRoadWhlFromRackPosScaY_Ary1D_data, TSC_AAACalRegn01Inin01_Dummy_Rte_Prm_SysKineAndEffRoadWhlFromRackPosScaY_Ary1D(self), sizeof(Ary1D_s2p13_21));
  (void)memcpy(SysKineAndEffSteerArmLenFromRackPosScaY_Ary1D_data, TSC_AAACalRegn01Inin01_Dummy_Rte_Prm_SysKineAndEffSteerArmLenFromRackPosScaY_Ary1D(self), sizeof(Ary1D_u1p15_21));
  (void)memcpy(TunSelnAuthyVehSpdX_Ary1D_data, TSC_AAACalRegn01Inin01_Dummy_Rte_Prm_TunSelnAuthyVehSpdX_Ary1D(self), sizeof(Ary1D_u9p7_6));


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define AAACalRegn01Inin01_Dummy_STOP_SEC_CODE
#include "AAACalRegn01Inin01_Dummy_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


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
