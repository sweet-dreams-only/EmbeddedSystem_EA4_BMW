/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  AAACalRegn01Inin01GroupA_Dummy.c
 *        Config:  EPS.dpa
 *     SW-C Type:  AAACalRegn01Inin01GroupA_Dummy
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <AAACalRegn01Inin01GroupA_Dummy>
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
 * s14p1
 *   
 *
 * s3p12
 *   
 *
 * s7p8
 *   
 *
 * s8p7
 *   
 *
 * u12p4
 *   
 *
 * u2p14
 *   
 *
 * u8p8
 *   
 *
 * u9p7
 *   
 *
 *********************************************************************************************************************/

#include "Rte_AAACalRegn01Inin01GroupA_Dummy.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_AAACalRegn01Inin01GroupA_Dummy.h"


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
 * s14p1: Integer in interval [-32768...32767]
 * s3p12: Integer in interval [-32768...32767]
 * s7p8: Integer in interval [-32768...32767]
 * s8p7: Integer in interval [-32768...32767]
 * sint16: Integer in interval [-32768...32767] (standard type)
 * u12p4: Integer in interval [0...65535]
 * u2p14: Integer in interval [0...65535]
 * u8p8: Integer in interval [0...65535]
 * u9p7: Integer in interval [0...65535]
 * uint16: Integer in interval [0...65535] (standard type)
 *
 * Array Types:
 * ============
 * Ary1D_f32_3: Array with 3 element(s) of type float32
 * Ary1D_f32_5: Array with 5 element(s) of type float32
 * Ary1D_s14p1_4: Array with 4 element(s) of type s14p1
 * Ary1D_s3p12_4: Array with 4 element(s) of type s3p12
 * Ary1D_s7p8_4: Array with 4 element(s) of type s7p8
 * Ary1D_s8p7_4: Array with 4 element(s) of type s8p7
 * Ary1D_u12p4_12: Array with 12 element(s) of type u12p4
 * Ary1D_u2p14_10: Array with 10 element(s) of type u2p14
 * Ary1D_u2p14_4: Array with 4 element(s) of type u2p14
 * Ary1D_u8p8_10: Array with 10 element(s) of type u8p8
 * Ary1D_u9p7_4: Array with 4 element(s) of type u9p7
 * Ary2D_f32_5_3: Array with 5 element(s) of type Ary1D_f32_3
 * Ary2D_f32_5_5: Array with 5 element(s) of type Ary1D_f32_5
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
 *   float32 Rte_Prm_BmwHwAgArbnAndEotPosnEotCcwMax_Val(Rte_Instance self)
 *   float32 Rte_Prm_BmwHwAgArbnAndEotPosnEotCcwMin_Val(Rte_Instance self)
 *   float32 Rte_Prm_BmwHwAgArbnAndEotPosnEotCwMax_Val(Rte_Instance self)
 *   float32 Rte_Prm_BmwHwAgArbnAndEotPosnEotCwMin_Val(Rte_Instance self)
 *   float32 Rte_Prm_BmwPwrPrkgDampgMaxRate_Val(Rte_Instance self)
 *   float32 Rte_Prm_PullCmpActvCmpLrnTiDecShoTerm_Val(Rte_Instance self)
 *   float32 Rte_Prm_PullCmpActvCmpLrnTiIncShoTerm_Val(Rte_Instance self)
 *   float32 Rte_Prm_PullCmpActvCmpLrnTiLongTerm_Val(Rte_Instance self)
 *   float32 Rte_Prm_PullCmpActvCmpShoTermRstHwAgThd_Val(Rte_Instance self)
 *   float32 Rte_Prm_PullCmpActvCmpShoTermRstHwTqThd_Val(Rte_Instance self)
 *   float32 Rte_Prm_PullCmpActvCmpShoTermRstLatAThd_Val(Rte_Instance self)
 *   float32 Rte_Prm_PullCmpActvCmpShoTermRstYawRateThd_Val(Rte_Instance self)
 *   float32 Rte_Prm_PullCmpActvHwTqFilFrqLongTerm_Val(Rte_Instance self)
 *   float32 Rte_Prm_PullCmpActvHwTqFilFrqShoTerm_Val(Rte_Instance self)
 *   float32 Rte_Prm_PullCmpActvLongTermLim_Val(Rte_Instance self)
 *   float32 Rte_Prm_PullCmpActvLrngEnaAgConfMinMgn_Val(Rte_Instance self)
 *   float32 Rte_Prm_PullCmpActvLrngEnaHwAgMaxMgn_Val(Rte_Instance self)
 *   float32 Rte_Prm_PullCmpActvLrngEnaHwTqMaxMgn_Val(Rte_Instance self)
 *   float32 Rte_Prm_PullCmpActvLrngEnaHwVelMaxMgn_Val(Rte_Instance self)
 *   float32 Rte_Prm_PullCmpActvLrngEnaLatAMaxMgn_Val(Rte_Instance self)
 *   float32 Rte_Prm_PullCmpActvLrngEnaTiThd_Val(Rte_Instance self)
 *   float32 Rte_Prm_PullCmpActvLrngEnaVehSpdMaxMgn_Val(Rte_Instance self)
 *   float32 Rte_Prm_PullCmpActvLrngEnaVehSpdMinMgn_Val(Rte_Instance self)
 *   float32 Rte_Prm_PullCmpActvLrngEnaVehSpdRateMaxMgn_Val(Rte_Instance self)
 *   float32 Rte_Prm_PullCmpActvLrngEnaYawRateMaxMgn_Val(Rte_Instance self)
 *   float32 Rte_Prm_PullCmpActvOpstSignTiShoTerm_Val(Rte_Instance self)
 *   float32 Rte_Prm_PullCmpActvOutpMaxRate_Val(Rte_Instance self)
 *   float32 Rte_Prm_PullCmpActvPullCmpShoTermLim_Val(Rte_Instance self)
 *   float32 Rte_Prm_PullCmpActvPullCmpTotLim_Val(Rte_Instance self)
 *   float32 Rte_Prm_PullCmpActvPullErrLimLongTerm_Val(Rte_Instance self)
 *   float32 Rte_Prm_PullCmpActvPullErrMgnThd_Val(Rte_Instance self)
 *   float32 Rte_Prm_PullCmpActvPullErrShoTermLim_Val(Rte_Instance self)
 *   float32 Rte_Prm_PullCmpActvShoTermRampTi_Val(Rte_Instance self)
 *   boolean Rte_Prm_BmwPwrPrkgDampgDiScadDampg_Logl(Rte_Instance self)
 *   boolean Rte_Prm_PullCmpActvEna_Logl(Rte_Instance self)
 *   float32 *Rte_Prm_EpsStEstimnMtrxA_Ary2D(Rte_Instance self)
 *     Returnvalue: float32* is of type Ary2D_f32_5_5
 *   float32 *Rte_Prm_EpsStEstimnMtrxB_Ary2D(Rte_Instance self)
 *     Returnvalue: float32* is of type Ary2D_f32_5_3
 *   float32 *Rte_Prm_EpsStEstimnMtrxC_Ary2D(Rte_Instance self)
 *     Returnvalue: float32* is of type Ary2D_f32_5_5
 *   float32 *Rte_Prm_EpsStEstimnMtrxD_Ary2D(Rte_Instance self)
 *     Returnvalue: float32* is of type Ary2D_f32_5_3
 *   s3p12 *Rte_Prm_HwTqTrakgCtrlFbGain1_Ary1D(Rte_Instance self)
 *     Returnvalue: s3p12* is of type Ary1D_s3p12_4
 *   s14p1 *Rte_Prm_HwTqTrakgCtrlFbGain2_Ary1D(Rte_Instance self)
 *     Returnvalue: s14p1* is of type Ary1D_s14p1_4
 *   s8p7 *Rte_Prm_HwTqTrakgCtrlFbGain3_Ary1D(Rte_Instance self)
 *     Returnvalue: s8p7* is of type Ary1D_s8p7_4
 *   s3p12 *Rte_Prm_HwTqTrakgCtrlFbGain4_Ary1D(Rte_Instance self)
 *     Returnvalue: s3p12* is of type Ary1D_s3p12_4
 *   s3p12 *Rte_Prm_HwTqTrakgCtrlFbGain5_Ary1D(Rte_Instance self)
 *     Returnvalue: s3p12* is of type Ary1D_s3p12_4
 *   s7p8 *Rte_Prm_HwTqTrakgCtrlFfGainScaY_Ary1D(Rte_Instance self)
 *     Returnvalue: s7p8* is of type Ary1D_s7p8_4
 *   u9p7 *Rte_Prm_HwTqTrakgCtrlVehSpdScaX_Ary1D(Rte_Instance self)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_4
 *   u8p8 *Rte_Prm_PosnTrakgServoEnaBlndFacTblX_Ary1D(Rte_Instance self)
 *     Returnvalue: u8p8* is of type Ary1D_u8p8_10
 *   u2p14 *Rte_Prm_PosnTrakgServoEnaBlndFacTblY_Ary1D(Rte_Instance self)
 *     Returnvalue: u2p14* is of type Ary1D_u2p14_10
 *   u12p4 *Rte_Prm_PosnTrakgServoGainArbnFltMtgtn_Ary1D(Rte_Instance self)
 *     Returnvalue: u12p4* is of type Ary1D_u12p4_12
 *   u9p7 *Rte_Prm_PullCmpActvVehSpdScaTblX_Ary1D(Rte_Instance self)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_4
 *   u2p14 *Rte_Prm_PullCmpActvVehSpdScaTblY_Ary1D(Rte_Instance self)
 *     Returnvalue: u2p14* is of type Ary1D_u2p14_4
 *
 *********************************************************************************************************************/


#define AAACalRegn01Inin01GroupA_Dummy_START_SEC_CODE
#include "AAACalRegn01Inin01GroupA_Dummy_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CalRegn01Inin01GroupADummyInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CalRegn01Inin01GroupADummyInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, AAACalRegn01Inin01GroupA_Dummy_CODE) CalRegn01Inin01GroupADummyInit1(Rte_Instance self) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CalRegn01Inin01GroupADummyInit1
 *********************************************************************************************************************/

  float32 BmwHwAgArbnAndEotPosnEotCcwMax_Val_data;
  float32 BmwHwAgArbnAndEotPosnEotCcwMin_Val_data;
  float32 BmwHwAgArbnAndEotPosnEotCwMax_Val_data;
  float32 BmwHwAgArbnAndEotPosnEotCwMin_Val_data;
  float32 BmwPwrPrkgDampgMaxRate_Val_data;
  float32 PullCmpActvCmpLrnTiDecShoTerm_Val_data;
  float32 PullCmpActvCmpLrnTiIncShoTerm_Val_data;
  float32 PullCmpActvCmpLrnTiLongTerm_Val_data;
  float32 PullCmpActvCmpShoTermRstHwAgThd_Val_data;
  float32 PullCmpActvCmpShoTermRstHwTqThd_Val_data;
  float32 PullCmpActvCmpShoTermRstLatAThd_Val_data;
  float32 PullCmpActvCmpShoTermRstYawRateThd_Val_data;
  float32 PullCmpActvHwTqFilFrqLongTerm_Val_data;
  float32 PullCmpActvHwTqFilFrqShoTerm_Val_data;
  float32 PullCmpActvLongTermLim_Val_data;
  float32 PullCmpActvLrngEnaAgConfMinMgn_Val_data;
  float32 PullCmpActvLrngEnaHwAgMaxMgn_Val_data;
  float32 PullCmpActvLrngEnaHwTqMaxMgn_Val_data;
  float32 PullCmpActvLrngEnaHwVelMaxMgn_Val_data;
  float32 PullCmpActvLrngEnaLatAMaxMgn_Val_data;
  float32 PullCmpActvLrngEnaTiThd_Val_data;
  float32 PullCmpActvLrngEnaVehSpdMaxMgn_Val_data;
  float32 PullCmpActvLrngEnaVehSpdMinMgn_Val_data;
  float32 PullCmpActvLrngEnaVehSpdRateMaxMgn_Val_data;
  float32 PullCmpActvLrngEnaYawRateMaxMgn_Val_data;
  float32 PullCmpActvOpstSignTiShoTerm_Val_data;
  float32 PullCmpActvOutpMaxRate_Val_data;
  float32 PullCmpActvPullCmpShoTermLim_Val_data;
  float32 PullCmpActvPullCmpTotLim_Val_data;
  float32 PullCmpActvPullErrLimLongTerm_Val_data;
  float32 PullCmpActvPullErrMgnThd_Val_data;
  float32 PullCmpActvPullErrShoTermLim_Val_data;
  float32 PullCmpActvShoTermRampTi_Val_data;
  boolean BmwPwrPrkgDampgDiScadDampg_Logl_data;
  boolean PullCmpActvEna_Logl_data;
  Ary2D_f32_5_5 EpsStEstimnMtrxA_Ary2D_data;
  Ary2D_f32_5_3 EpsStEstimnMtrxB_Ary2D_data;
  Ary2D_f32_5_5 EpsStEstimnMtrxC_Ary2D_data;
  Ary2D_f32_5_3 EpsStEstimnMtrxD_Ary2D_data;
  Ary1D_s3p12_4 HwTqTrakgCtrlFbGain1_Ary1D_data;
  Ary1D_s14p1_4 HwTqTrakgCtrlFbGain2_Ary1D_data;
  Ary1D_s8p7_4 HwTqTrakgCtrlFbGain3_Ary1D_data;
  Ary1D_s3p12_4 HwTqTrakgCtrlFbGain4_Ary1D_data;
  Ary1D_s3p12_4 HwTqTrakgCtrlFbGain5_Ary1D_data;
  Ary1D_s7p8_4 HwTqTrakgCtrlFfGainScaY_Ary1D_data;
  Ary1D_u9p7_4 HwTqTrakgCtrlVehSpdScaX_Ary1D_data;
  Ary1D_u8p8_10 PosnTrakgServoEnaBlndFacTblX_Ary1D_data;
  Ary1D_u2p14_10 PosnTrakgServoEnaBlndFacTblY_Ary1D_data;
  Ary1D_u12p4_12 PosnTrakgServoGainArbnFltMtgtn_Ary1D_data;
  Ary1D_u9p7_4 PullCmpActvVehSpdScaTblX_Ary1D_data;
  Ary1D_u2p14_4 PullCmpActvVehSpdScaTblY_Ary1D_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  BmwHwAgArbnAndEotPosnEotCcwMax_Val_data = TSC_AAACalRegn01Inin01GroupA_Dummy_Rte_Prm_BmwHwAgArbnAndEotPosnEotCcwMax_Val(self);
  BmwHwAgArbnAndEotPosnEotCcwMin_Val_data = TSC_AAACalRegn01Inin01GroupA_Dummy_Rte_Prm_BmwHwAgArbnAndEotPosnEotCcwMin_Val(self);
  BmwHwAgArbnAndEotPosnEotCwMax_Val_data = TSC_AAACalRegn01Inin01GroupA_Dummy_Rte_Prm_BmwHwAgArbnAndEotPosnEotCwMax_Val(self);
  BmwHwAgArbnAndEotPosnEotCwMin_Val_data = TSC_AAACalRegn01Inin01GroupA_Dummy_Rte_Prm_BmwHwAgArbnAndEotPosnEotCwMin_Val(self);
  BmwPwrPrkgDampgMaxRate_Val_data = TSC_AAACalRegn01Inin01GroupA_Dummy_Rte_Prm_BmwPwrPrkgDampgMaxRate_Val(self);
  PullCmpActvCmpLrnTiDecShoTerm_Val_data = TSC_AAACalRegn01Inin01GroupA_Dummy_Rte_Prm_PullCmpActvCmpLrnTiDecShoTerm_Val(self);
  PullCmpActvCmpLrnTiIncShoTerm_Val_data = TSC_AAACalRegn01Inin01GroupA_Dummy_Rte_Prm_PullCmpActvCmpLrnTiIncShoTerm_Val(self);
  PullCmpActvCmpLrnTiLongTerm_Val_data = TSC_AAACalRegn01Inin01GroupA_Dummy_Rte_Prm_PullCmpActvCmpLrnTiLongTerm_Val(self);
  PullCmpActvCmpShoTermRstHwAgThd_Val_data = TSC_AAACalRegn01Inin01GroupA_Dummy_Rte_Prm_PullCmpActvCmpShoTermRstHwAgThd_Val(self);
  PullCmpActvCmpShoTermRstHwTqThd_Val_data = TSC_AAACalRegn01Inin01GroupA_Dummy_Rte_Prm_PullCmpActvCmpShoTermRstHwTqThd_Val(self);
  PullCmpActvCmpShoTermRstLatAThd_Val_data = TSC_AAACalRegn01Inin01GroupA_Dummy_Rte_Prm_PullCmpActvCmpShoTermRstLatAThd_Val(self);
  PullCmpActvCmpShoTermRstYawRateThd_Val_data = TSC_AAACalRegn01Inin01GroupA_Dummy_Rte_Prm_PullCmpActvCmpShoTermRstYawRateThd_Val(self);
  PullCmpActvHwTqFilFrqLongTerm_Val_data = TSC_AAACalRegn01Inin01GroupA_Dummy_Rte_Prm_PullCmpActvHwTqFilFrqLongTerm_Val(self);
  PullCmpActvHwTqFilFrqShoTerm_Val_data = TSC_AAACalRegn01Inin01GroupA_Dummy_Rte_Prm_PullCmpActvHwTqFilFrqShoTerm_Val(self);
  PullCmpActvLongTermLim_Val_data = TSC_AAACalRegn01Inin01GroupA_Dummy_Rte_Prm_PullCmpActvLongTermLim_Val(self);
  PullCmpActvLrngEnaAgConfMinMgn_Val_data = TSC_AAACalRegn01Inin01GroupA_Dummy_Rte_Prm_PullCmpActvLrngEnaAgConfMinMgn_Val(self);
  PullCmpActvLrngEnaHwAgMaxMgn_Val_data = TSC_AAACalRegn01Inin01GroupA_Dummy_Rte_Prm_PullCmpActvLrngEnaHwAgMaxMgn_Val(self);
  PullCmpActvLrngEnaHwTqMaxMgn_Val_data = TSC_AAACalRegn01Inin01GroupA_Dummy_Rte_Prm_PullCmpActvLrngEnaHwTqMaxMgn_Val(self);
  PullCmpActvLrngEnaHwVelMaxMgn_Val_data = TSC_AAACalRegn01Inin01GroupA_Dummy_Rte_Prm_PullCmpActvLrngEnaHwVelMaxMgn_Val(self);
  PullCmpActvLrngEnaLatAMaxMgn_Val_data = TSC_AAACalRegn01Inin01GroupA_Dummy_Rte_Prm_PullCmpActvLrngEnaLatAMaxMgn_Val(self);
  PullCmpActvLrngEnaTiThd_Val_data = TSC_AAACalRegn01Inin01GroupA_Dummy_Rte_Prm_PullCmpActvLrngEnaTiThd_Val(self);
  PullCmpActvLrngEnaVehSpdMaxMgn_Val_data = TSC_AAACalRegn01Inin01GroupA_Dummy_Rte_Prm_PullCmpActvLrngEnaVehSpdMaxMgn_Val(self);
  PullCmpActvLrngEnaVehSpdMinMgn_Val_data = TSC_AAACalRegn01Inin01GroupA_Dummy_Rte_Prm_PullCmpActvLrngEnaVehSpdMinMgn_Val(self);
  PullCmpActvLrngEnaVehSpdRateMaxMgn_Val_data = TSC_AAACalRegn01Inin01GroupA_Dummy_Rte_Prm_PullCmpActvLrngEnaVehSpdRateMaxMgn_Val(self);
  PullCmpActvLrngEnaYawRateMaxMgn_Val_data = TSC_AAACalRegn01Inin01GroupA_Dummy_Rte_Prm_PullCmpActvLrngEnaYawRateMaxMgn_Val(self);
  PullCmpActvOpstSignTiShoTerm_Val_data = TSC_AAACalRegn01Inin01GroupA_Dummy_Rte_Prm_PullCmpActvOpstSignTiShoTerm_Val(self);
  PullCmpActvOutpMaxRate_Val_data = TSC_AAACalRegn01Inin01GroupA_Dummy_Rte_Prm_PullCmpActvOutpMaxRate_Val(self);
  PullCmpActvPullCmpShoTermLim_Val_data = TSC_AAACalRegn01Inin01GroupA_Dummy_Rte_Prm_PullCmpActvPullCmpShoTermLim_Val(self);
  PullCmpActvPullCmpTotLim_Val_data = TSC_AAACalRegn01Inin01GroupA_Dummy_Rte_Prm_PullCmpActvPullCmpTotLim_Val(self);
  PullCmpActvPullErrLimLongTerm_Val_data = TSC_AAACalRegn01Inin01GroupA_Dummy_Rte_Prm_PullCmpActvPullErrLimLongTerm_Val(self);
  PullCmpActvPullErrMgnThd_Val_data = TSC_AAACalRegn01Inin01GroupA_Dummy_Rte_Prm_PullCmpActvPullErrMgnThd_Val(self);
  PullCmpActvPullErrShoTermLim_Val_data = TSC_AAACalRegn01Inin01GroupA_Dummy_Rte_Prm_PullCmpActvPullErrShoTermLim_Val(self);
  PullCmpActvShoTermRampTi_Val_data = TSC_AAACalRegn01Inin01GroupA_Dummy_Rte_Prm_PullCmpActvShoTermRampTi_Val(self);
  BmwPwrPrkgDampgDiScadDampg_Logl_data = TSC_AAACalRegn01Inin01GroupA_Dummy_Rte_Prm_BmwPwrPrkgDampgDiScadDampg_Logl(self);
  PullCmpActvEna_Logl_data = TSC_AAACalRegn01Inin01GroupA_Dummy_Rte_Prm_PullCmpActvEna_Logl(self);
  (void)memcpy(EpsStEstimnMtrxA_Ary2D_data, TSC_AAACalRegn01Inin01GroupA_Dummy_Rte_Prm_EpsStEstimnMtrxA_Ary2D(self), sizeof(Ary2D_f32_5_5));
  (void)memcpy(EpsStEstimnMtrxB_Ary2D_data, TSC_AAACalRegn01Inin01GroupA_Dummy_Rte_Prm_EpsStEstimnMtrxB_Ary2D(self), sizeof(Ary2D_f32_5_3));
  (void)memcpy(EpsStEstimnMtrxC_Ary2D_data, TSC_AAACalRegn01Inin01GroupA_Dummy_Rte_Prm_EpsStEstimnMtrxC_Ary2D(self), sizeof(Ary2D_f32_5_5));
  (void)memcpy(EpsStEstimnMtrxD_Ary2D_data, TSC_AAACalRegn01Inin01GroupA_Dummy_Rte_Prm_EpsStEstimnMtrxD_Ary2D(self), sizeof(Ary2D_f32_5_3));
  (void)memcpy(HwTqTrakgCtrlFbGain1_Ary1D_data, TSC_AAACalRegn01Inin01GroupA_Dummy_Rte_Prm_HwTqTrakgCtrlFbGain1_Ary1D(self), sizeof(Ary1D_s3p12_4));
  (void)memcpy(HwTqTrakgCtrlFbGain2_Ary1D_data, TSC_AAACalRegn01Inin01GroupA_Dummy_Rte_Prm_HwTqTrakgCtrlFbGain2_Ary1D(self), sizeof(Ary1D_s14p1_4));
  (void)memcpy(HwTqTrakgCtrlFbGain3_Ary1D_data, TSC_AAACalRegn01Inin01GroupA_Dummy_Rte_Prm_HwTqTrakgCtrlFbGain3_Ary1D(self), sizeof(Ary1D_s8p7_4));
  (void)memcpy(HwTqTrakgCtrlFbGain4_Ary1D_data, TSC_AAACalRegn01Inin01GroupA_Dummy_Rte_Prm_HwTqTrakgCtrlFbGain4_Ary1D(self), sizeof(Ary1D_s3p12_4));
  (void)memcpy(HwTqTrakgCtrlFbGain5_Ary1D_data, TSC_AAACalRegn01Inin01GroupA_Dummy_Rte_Prm_HwTqTrakgCtrlFbGain5_Ary1D(self), sizeof(Ary1D_s3p12_4));
  (void)memcpy(HwTqTrakgCtrlFfGainScaY_Ary1D_data, TSC_AAACalRegn01Inin01GroupA_Dummy_Rte_Prm_HwTqTrakgCtrlFfGainScaY_Ary1D(self), sizeof(Ary1D_s7p8_4));
  (void)memcpy(HwTqTrakgCtrlVehSpdScaX_Ary1D_data, TSC_AAACalRegn01Inin01GroupA_Dummy_Rte_Prm_HwTqTrakgCtrlVehSpdScaX_Ary1D(self), sizeof(Ary1D_u9p7_4));
  (void)memcpy(PosnTrakgServoEnaBlndFacTblX_Ary1D_data, TSC_AAACalRegn01Inin01GroupA_Dummy_Rte_Prm_PosnTrakgServoEnaBlndFacTblX_Ary1D(self), sizeof(Ary1D_u8p8_10));
  (void)memcpy(PosnTrakgServoEnaBlndFacTblY_Ary1D_data, TSC_AAACalRegn01Inin01GroupA_Dummy_Rte_Prm_PosnTrakgServoEnaBlndFacTblY_Ary1D(self), sizeof(Ary1D_u2p14_10));
  (void)memcpy(PosnTrakgServoGainArbnFltMtgtn_Ary1D_data, TSC_AAACalRegn01Inin01GroupA_Dummy_Rte_Prm_PosnTrakgServoGainArbnFltMtgtn_Ary1D(self), sizeof(Ary1D_u12p4_12));
  (void)memcpy(PullCmpActvVehSpdScaTblX_Ary1D_data, TSC_AAACalRegn01Inin01GroupA_Dummy_Rte_Prm_PullCmpActvVehSpdScaTblX_Ary1D(self), sizeof(Ary1D_u9p7_4));
  (void)memcpy(PullCmpActvVehSpdScaTblY_Ary1D_data, TSC_AAACalRegn01Inin01GroupA_Dummy_Rte_Prm_PullCmpActvVehSpdScaTblY_Ary1D(self), sizeof(Ary1D_u2p14_4));


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define AAACalRegn01Inin01GroupA_Dummy_STOP_SEC_CODE
#include "AAACalRegn01Inin01GroupA_Dummy_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


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
