/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  AAACalRegn01IninOptSetA01_Dummy.c
 *        Config:  EPS.dpa
 *     SW-C Type:  AAACalRegn01IninOptSetA01_Dummy
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <AAACalRegn01IninOptSetA01_Dummy>
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
 * s11p4
 *   
 *
 * s15p0
 *   
 *
 * u10p6
 *   
 *
 * u11p5
 *   
 *
 * u16p0
 *   
 *
 * u1p15
 *   
 *
 * u2p14
 *   
 *
 * u3p13
 *   
 *
 * u4p12
 *   
 *
 * u5p11
 *   
 *
 * u8p8
 *   
 *
 * u9p7
 *   
 *
 *********************************************************************************************************************/

#include "Rte_AAACalRegn01IninOptSetA01_Dummy.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_AAACalRegn01IninOptSetA01_Dummy.h"


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
 * s11p4: Integer in interval [-32768...32767]
 * s15p0: Integer in interval [-32768...32767]
 * sint16: Integer in interval [-32768...32767] (standard type)
 * u10p6: Integer in interval [0...65535]
 * u11p5: Integer in interval [0...65535]
 * u16p0: Integer in interval [0...65535]
 * u1p15: Integer in interval [0...65535]
 * u2p14: Integer in interval [0...65535]
 * u3p13: Integer in interval [0...65535]
 * u4p12: Integer in interval [0...65535]
 * u5p11: Integer in interval [0...65535]
 * u8p8: Integer in interval [0...65535]
 * u9p7: Integer in interval [0...65535]
 * uint16: Integer in interval [0...65535] (standard type)
 *
 * Array Types:
 * ============
 * Ary1D_f32_2: Array with 2 element(s) of type float32
 * Ary1D_f32_3: Array with 3 element(s) of type float32
 * Ary1D_f32_8: Array with 8 element(s) of type float32
 * Ary1D_logl_3: Array with 3 element(s) of type boolean
 * Ary1D_s11p4_14: Array with 14 element(s) of type s11p4
 * Ary1D_s15p0_4: Array with 4 element(s) of type s15p0
 * Ary1D_s15p0_5: Array with 5 element(s) of type s15p0
 * Ary1D_u10p6_4: Array with 4 element(s) of type u10p6
 * Ary1D_u11p5_10: Array with 10 element(s) of type u11p5
 * Ary1D_u11p5_6: Array with 6 element(s) of type u11p5
 * Ary1D_u16p0_8: Array with 8 element(s) of type u16p0
 * Ary1D_u1p15_11: Array with 11 element(s) of type u1p15
 * Ary1D_u2p14_16: Array with 16 element(s) of type u2p14
 * Ary1D_u2p14_7: Array with 7 element(s) of type u2p14
 * Ary1D_u3p13_10: Array with 10 element(s) of type u3p13
 * Ary1D_u3p13_5: Array with 5 element(s) of type u3p13
 * Ary1D_u4p12_11: Array with 11 element(s) of type u4p12
 * Ary1D_u4p12_6: Array with 6 element(s) of type u4p12
 * Ary1D_u5p11_10: Array with 10 element(s) of type u5p11
 * Ary1D_u5p11_14: Array with 14 element(s) of type u5p11
 * Ary1D_u8p8_6: Array with 6 element(s) of type u8p8
 * Ary1D_u9p7_16: Array with 16 element(s) of type u9p7
 * Ary1D_u9p7_4: Array with 4 element(s) of type u9p7
 * Ary1D_u9p7_5: Array with 5 element(s) of type u9p7
 * Ary1D_u9p7_6: Array with 6 element(s) of type u9p7
 * Ary1D_u9p7_7: Array with 7 element(s) of type u9p7
 * Ary1D_u9p7_8: Array with 8 element(s) of type u9p7
 * Ary2D_u16p0_2_8: Array with 2 element(s) of type Ary1D_u16p0_8
 * Ary2D_u2p14_6_7: Array with 6 element(s) of type Ary1D_u2p14_7
 * Ary2D_u9p7_2_5: Array with 2 element(s) of type Ary1D_u9p7_5
 * Ary2D_u9p7_2_8: Array with 2 element(s) of type Ary1D_u9p7_8
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
 *   float32 Rte_Prm_DutyCycThermProtnAbsltMotVelBreakPt_Val(Rte_Instance self)
 *   float32 Rte_Prm_DutyCycThermProtnAbsltTTqSlewHiLim_Val(Rte_Instance self)
 *   float32 Rte_Prm_DutyCycThermProtnAbsltTTqSlewLoLim_Val(Rte_Instance self)
 *   float32 Rte_Prm_DutyCycThermProtnCtrlT_Val(Rte_Instance self)
 *   float32 Rte_Prm_DutyCycThermProtnIgnOffMsgWaitTi_Val(Rte_Instance self)
 *   float32 Rte_Prm_DutyCycThermProtnThermLimScaFac_Val(Rte_Instance self)
 *   float32 Rte_Prm_DutyCycThermProtnTqCmdSlewDwn_Val(Rte_Instance self)
 *   float32 Rte_Prm_DutyCycThermProtnTqCmdSlewUp_Val(Rte_Instance self)
 *   float32 Rte_Prm_HiLoadStallLimrStallThermLimSca_Val(Rte_Instance self)
 *   float32 Rte_Prm_LrndRackCentrMotTqThd_Val(Rte_Instance self)
 *   float32 Rte_Prm_LrndRackCentrMotVelThd_Val(Rte_Instance self)
 *   float32 Rte_Prm_MotCtrlPrmEstimnFetRNom_Val(Rte_Instance self)
 *   float32 Rte_Prm_MotCtrlPrmEstimnMotBackEmfConHiLim_Val(Rte_Instance self)
 *   float32 Rte_Prm_MotCtrlPrmEstimnMotBackEmfConLoLim_Val(Rte_Instance self)
 *   float32 Rte_Prm_MotCtrlPrmEstimnMotBackEmfConNom_Val(Rte_Instance self)
 *   float32 Rte_Prm_MotCtrlPrmEstimnMotBackEmfConSatnScaIvtrLoaMtgtn_Val(Rte_Instance self)
 *   float32 Rte_Prm_MotCtrlPrmEstimnMotInduDaxHiLim_Val(Rte_Instance self)
 *   float32 Rte_Prm_MotCtrlPrmEstimnMotInduDaxIvtrLoaMtgtn_Val(Rte_Instance self)
 *   float32 Rte_Prm_MotCtrlPrmEstimnMotInduDaxLoLim_Val(Rte_Instance self)
 *   float32 Rte_Prm_MotCtrlPrmEstimnMotInduDaxNom_Val(Rte_Instance self)
 *   float32 Rte_Prm_MotCtrlPrmEstimnMotInduQaxHiLim_Val(Rte_Instance self)
 *   float32 Rte_Prm_MotCtrlPrmEstimnMotInduQaxIvtrLoaMtgtn_Val(Rte_Instance self)
 *   float32 Rte_Prm_MotCtrlPrmEstimnMotInduQaxLoLim_Val(Rte_Instance self)
 *   float32 Rte_Prm_MotCtrlPrmEstimnMotInduQaxNom_Val(Rte_Instance self)
 *   float32 Rte_Prm_MotCtrlPrmEstimnMotRHiLim_Val(Rte_Instance self)
 *   float32 Rte_Prm_MotCtrlPrmEstimnMotRLoLim_Val(Rte_Instance self)
 *   float32 Rte_Prm_MotCtrlPrmEstimnMotRNom_Val(Rte_Instance self)
 *   float32 Rte_Prm_MotCtrlPrmEstimnMotWidgThermCoeff_Val(Rte_Instance self)
 *   float32 Rte_Prm_MotCtrlPrmEstimnTNom_Val(Rte_Instance self)
 *   float32 Rte_Prm_MotCurrPeakEstimnCurrFilFrq_Val(Rte_Instance self)
 *   float32 Rte_Prm_MotCurrPeakEstimnCurrPeakEstimdFilFrq_Val(Rte_Instance self)
 *   float32 Rte_Prm_MotCurrRegCfgMotDampgRatDax_Val(Rte_Instance self)
 *   float32 Rte_Prm_MotCurrRegCfgMotDampgRatQax_Val(Rte_Instance self)
 *   float32 Rte_Prm_MotCurrRegCfgMotRVirtDax_Val(Rte_Instance self)
 *   float32 Rte_Prm_MotCurrRegCfgMotRVirtQax_Val(Rte_Instance self)
 *   float32 Rte_Prm_MotCurrRegCfgMotVelFilFrq_Val(Rte_Instance self)
 *   float32 Rte_Prm_MotCurrRegVltgLimrCurrLoaScarSlewRate_Val(Rte_Instance self)
 *   float32 Rte_Prm_MotCurrRegVltgLimrDaxAntiWdupCoeff_Val(Rte_Instance self)
 *   float32 Rte_Prm_MotCurrRegVltgLimrDualEcuLoaScarSlewRate_Val(Rte_Instance self)
 *   float32 Rte_Prm_MotCurrRegVltgLimrFETLoaScarSlewRate_Val(Rte_Instance self)
 *   float32 Rte_Prm_MotCurrRegVltgLimrIvtrLoaScarSlewRate_Val(Rte_Instance self)
 *   float32 Rte_Prm_MotCurrRegVltgLimrMotVltgBrdgLpFilFrq_Val(Rte_Instance self)
 *   float32 Rte_Prm_MotCurrRegVltgLimrMotVltgDaxIntglHiLim_Val(Rte_Instance self)
 *   float32 Rte_Prm_MotCurrRegVltgLimrMotVltgDaxIntglLoLim_Val(Rte_Instance self)
 *   float32 Rte_Prm_MotCurrRegVltgLimrMotVltgQaxFfLpFilFrq_Val(Rte_Instance self)
 *   float32 Rte_Prm_MotCurrRegVltgLimrMotVltgQaxIntglHiLim_Val(Rte_Instance self)
 *   float32 Rte_Prm_MotCurrRegVltgLimrMotVltgQaxIntglLoLim_Val(Rte_Instance self)
 *   float32 Rte_Prm_MotCurrRegVltgLimrQaxAntiWdupCoeff_Val(Rte_Instance self)
 *   float32 Rte_Prm_MotRefMdlCurrDaxBoostGain_Val(Rte_Instance self)
 *   float32 Rte_Prm_MotRefMdlCurrItrnTolr_Val(Rte_Instance self)
 *   float32 Rte_Prm_MotRefMdlMotCurrDaxMaxSca_Val(Rte_Instance self)
 *   float32 Rte_Prm_MotRefMdlVltgOverRThdSca_Val(Rte_Instance self)
 *   float32 Rte_Prm_MotTqTranlDampgCmdLim_Val(Rte_Instance self)
 *   float32 Rte_Prm_MotTqTranlDampgVelThd_Val(Rte_Instance self)
 *   float32 Rte_Prm_PwrLimrAssiRednLpFilFrq_Val(Rte_Instance self)
 *   float32 Rte_Prm_PwrLimrBackEmfConStdT_Val(Rte_Instance self)
 *   float32 Rte_Prm_PwrLimrBrdgVltgAdjSlew_Val(Rte_Instance self)
 *   float32 Rte_Prm_PwrLimrBrdgVltgAltFltAdj_Val(Rte_Instance self)
 *   float32 Rte_Prm_PwrLimrFilAssiRednThd_Val(Rte_Instance self)
 *   float32 Rte_Prm_PwrLimrLoVoltAssiRcvrThd_Val(Rte_Instance self)
 *   float32 Rte_Prm_PwrLimrMotVelLpFilFrq_Val(Rte_Instance self)
 *   float32 Rte_Prm_PwrLimrSpdAdjSlewDec_Val(Rte_Instance self)
 *   float32 Rte_Prm_PwrLimrSpdAdjSlewInc_Val(Rte_Instance self)
 *   float32 Rte_Prm_SysGlbPrmSysTqRat_Val(Rte_Instance self)
 *   float32 Rte_Prm_TEstimnAssiMechAmbLpFilFrq_Val(Rte_Instance self)
 *   float32 Rte_Prm_TEstimnAssiMechAmbLpFilFrqDualEcuFltMtgtn_Val(Rte_Instance self)
 *   float32 Rte_Prm_TEstimnAssiMechAmbLpFilFrqFetMtgtnEna_Val(Rte_Instance self)
 *   float32 Rte_Prm_TEstimnCuAmbLpFilFrq_Val(Rte_Instance self)
 *   float32 Rte_Prm_TEstimnCuAmbLpFilFrqDualEcuFltMtgtn_Val(Rte_Instance self)
 *   float32 Rte_Prm_TEstimnCuAmbLpFilFrqFetMtgtnEna_Val(Rte_Instance self)
 *   float32 Rte_Prm_TEstimnMagAmbLpFilFrq_Val(Rte_Instance self)
 *   float32 Rte_Prm_TEstimnMagAmbLpFilFrqDualEcuFltMtgtn_Val(Rte_Instance self)
 *   float32 Rte_Prm_TEstimnMagAmbLpFilFrqFetMtgtnEna_Val(Rte_Instance self)
 *   float32 Rte_Prm_TEstimnSiAmbLpFilFrq_Val(Rte_Instance self)
 *   float32 Rte_Prm_TEstimnSiAmbLpFilFrqDualEcuFltMtgtn_Val(Rte_Instance self)
 *   float32 Rte_Prm_TEstimnSiAmbLpFilFrqFetMtgtnEna_Val(Rte_Instance self)
 *   float32 Rte_Prm_VehSpdLimrPosMaxOffs2_Val(Rte_Instance self)
 *   u16p0 Rte_Prm_DutyCycThermProtnDutyCycFildThd_Val(Rte_Instance self)
 *   uint16 Rte_Prm_PwrLimrLoVoltAssiRcvrTi_Val(Rte_Instance self)
 *   boolean Rte_Prm_DutyCycThermProtnCtrlTSeln_Logl(Rte_Instance self)
 *   boolean Rte_Prm_DutyCycThermProtnIgnOffCtrlEna_Logl(Rte_Instance self)
 *   boolean Rte_Prm_DutyCycThermProtnMotPrTSeln_Logl(Rte_Instance self)
 *   boolean Rte_Prm_DutyCycThermProtnMplrTSeln_Logl(Rte_Instance self)
 *   boolean Rte_Prm_DutyCycThermProtnSlowFilTSeln_Logl(Rte_Instance self)
 *   boolean Rte_Prm_MotCurrRegVltgLimrQaxAntiWdupScagDi_Logl(Rte_Instance self)
 *   boolean Rte_Prm_PwrLimrSpdAdjSlewEna_Logl(Rte_Instance self)
 *   s15p0 *Rte_Prm_DutyCycThermProtnAbsltCtrlTFetMtgtnTblX_Ary1D(Rte_Instance self)
 *     Returnvalue: s15p0* is of type Ary1D_s15p0_4
 *   s15p0 *Rte_Prm_DutyCycThermProtnAbsltCtrlTTblX_Ary1D(Rte_Instance self)
 *     Returnvalue: s15p0* is of type Ary1D_s15p0_4
 *   u9p7 *Rte_Prm_DutyCycThermProtnAbsltCtrlTTqFetMtgtnTblY_Ary1D(Rte_Instance self)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_4
 *   u9p7 *Rte_Prm_DutyCycThermProtnAbsltCtrlTTqTblY_Ary1D(Rte_Instance self)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_4
 *   s15p0 *Rte_Prm_DutyCycThermProtnAbsltCuTFetMtgtnTblX_Ary1D(Rte_Instance self)
 *     Returnvalue: s15p0* is of type Ary1D_s15p0_4
 *   s15p0 *Rte_Prm_DutyCycThermProtnAbsltCuTTblX_Ary1D(Rte_Instance self)
 *     Returnvalue: s15p0* is of type Ary1D_s15p0_4
 *   u9p7 *Rte_Prm_DutyCycThermProtnAbsltCuTTqFetMtgtnTblY_Ary1D(Rte_Instance self)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_4
 *   u9p7 *Rte_Prm_DutyCycThermProtnAbsltCuTTqTblY_Ary1D(Rte_Instance self)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_4
 *   u9p7 *Rte_Prm_DutyCycThermProtnLstTblValNonStall_Ary2D(Rte_Instance self)
 *     Returnvalue: u9p7* is of type Ary2D_u9p7_2_5
 *   u9p7 *Rte_Prm_DutyCycThermProtnLstTblValStall_Ary2D(Rte_Instance self)
 *     Returnvalue: u9p7* is of type Ary2D_u9p7_2_5
 *   u3p13 *Rte_Prm_DutyCycThermProtnMplr1FetMtgtnNonStallTblY_Ary1D(Rte_Instance self)
 *     Returnvalue: u3p13* is of type Ary1D_u3p13_5
 *   u3p13 *Rte_Prm_DutyCycThermProtnMplr1FetMtgtnStallTblY_Ary1D(Rte_Instance self)
 *     Returnvalue: u3p13* is of type Ary1D_u3p13_5
 *   u3p13 *Rte_Prm_DutyCycThermProtnMplr1NonStallTblY_Ary1D(Rte_Instance self)
 *     Returnvalue: u3p13* is of type Ary1D_u3p13_5
 *   u3p13 *Rte_Prm_DutyCycThermProtnMplr1StallTblY_Ary1D(Rte_Instance self)
 *     Returnvalue: u3p13* is of type Ary1D_u3p13_5
 *   u3p13 *Rte_Prm_DutyCycThermProtnMplr2FetMtgtnNonStallTblY_Ary1D(Rte_Instance self)
 *     Returnvalue: u3p13* is of type Ary1D_u3p13_5
 *   u3p13 *Rte_Prm_DutyCycThermProtnMplr2FetMtgtnStallTblY_Ary1D(Rte_Instance self)
 *     Returnvalue: u3p13* is of type Ary1D_u3p13_5
 *   u3p13 *Rte_Prm_DutyCycThermProtnMplr2NonStallTblY_Ary1D(Rte_Instance self)
 *     Returnvalue: u3p13* is of type Ary1D_u3p13_5
 *   u3p13 *Rte_Prm_DutyCycThermProtnMplr2StallTblY_Ary1D(Rte_Instance self)
 *     Returnvalue: u3p13* is of type Ary1D_u3p13_5
 *   u3p13 *Rte_Prm_DutyCycThermProtnMplr3FetMtgtnNonStallTblY_Ary1D(Rte_Instance self)
 *     Returnvalue: u3p13* is of type Ary1D_u3p13_5
 *   u3p13 *Rte_Prm_DutyCycThermProtnMplr3FetMtgtnStallTblY_Ary1D(Rte_Instance self)
 *     Returnvalue: u3p13* is of type Ary1D_u3p13_5
 *   u3p13 *Rte_Prm_DutyCycThermProtnMplr3NonStallTblY_Ary1D(Rte_Instance self)
 *     Returnvalue: u3p13* is of type Ary1D_u3p13_5
 *   u3p13 *Rte_Prm_DutyCycThermProtnMplr3StallTblY_Ary1D(Rte_Instance self)
 *     Returnvalue: u3p13* is of type Ary1D_u3p13_5
 *   u3p13 *Rte_Prm_DutyCycThermProtnMplr4FetMtgtnNonStallTblY_Ary1D(Rte_Instance self)
 *     Returnvalue: u3p13* is of type Ary1D_u3p13_5
 *   u3p13 *Rte_Prm_DutyCycThermProtnMplr4FetMtgtnStallTblY_Ary1D(Rte_Instance self)
 *     Returnvalue: u3p13* is of type Ary1D_u3p13_5
 *   u3p13 *Rte_Prm_DutyCycThermProtnMplr4NonStallTblY_Ary1D(Rte_Instance self)
 *     Returnvalue: u3p13* is of type Ary1D_u3p13_5
 *   u3p13 *Rte_Prm_DutyCycThermProtnMplr4StallTblY_Ary1D(Rte_Instance self)
 *     Returnvalue: u3p13* is of type Ary1D_u3p13_5
 *   u3p13 *Rte_Prm_DutyCycThermProtnMplr5FetMtgtnNonStallTblY_Ary1D(Rte_Instance self)
 *     Returnvalue: u3p13* is of type Ary1D_u3p13_5
 *   u3p13 *Rte_Prm_DutyCycThermProtnMplr5FetMtgtnStallTblY_Ary1D(Rte_Instance self)
 *     Returnvalue: u3p13* is of type Ary1D_u3p13_5
 *   u3p13 *Rte_Prm_DutyCycThermProtnMplr5NonStallTblY_Ary1D(Rte_Instance self)
 *     Returnvalue: u3p13* is of type Ary1D_u3p13_5
 *   u3p13 *Rte_Prm_DutyCycThermProtnMplr5StallTblY_Ary1D(Rte_Instance self)
 *     Returnvalue: u3p13* is of type Ary1D_u3p13_5
 *   u3p13 *Rte_Prm_DutyCycThermProtnMplr6FetMtgtnNonStallTblY_Ary1D(Rte_Instance self)
 *     Returnvalue: u3p13* is of type Ary1D_u3p13_5
 *   u3p13 *Rte_Prm_DutyCycThermProtnMplr6FetMtgtnStallTblY_Ary1D(Rte_Instance self)
 *     Returnvalue: u3p13* is of type Ary1D_u3p13_5
 *   u3p13 *Rte_Prm_DutyCycThermProtnMplr6NonStallTblY_Ary1D(Rte_Instance self)
 *     Returnvalue: u3p13* is of type Ary1D_u3p13_5
 *   u3p13 *Rte_Prm_DutyCycThermProtnMplr6StallTblY_Ary1D(Rte_Instance self)
 *     Returnvalue: u3p13* is of type Ary1D_u3p13_5
 *   s15p0 *Rte_Prm_DutyCycThermProtnMplrFetMtgtnTblX_Ary1D(Rte_Instance self)
 *     Returnvalue: s15p0* is of type Ary1D_s15p0_5
 *   s15p0 *Rte_Prm_DutyCycThermProtnMplrTblX_Ary1D(Rte_Instance self)
 *     Returnvalue: s15p0* is of type Ary1D_s15p0_5
 *   u16p0 *Rte_Prm_DutyCycThermProtnThermLoadLimTblX_Ary2D(Rte_Instance self)
 *     Returnvalue: u16p0* is of type Ary2D_u16p0_2_8
 *   u9p7 *Rte_Prm_DutyCycThermProtnThermLoadLimTblY_Ary2D(Rte_Instance self)
 *     Returnvalue: u9p7* is of type Ary2D_u9p7_2_8
 *   float32 *Rte_Prm_HiLoadStallLimrMotVelMgnThd_Ary1D(Rte_Instance self)
 *     Returnvalue: float32* is of type Ary1D_f32_2
 *   u8p8 *Rte_Prm_HiLoadStallLimrStallMotTqCmdFetMtgtnLimX_Ary1D(Rte_Instance self)
 *     Returnvalue: u8p8* is of type Ary1D_u8p8_6
 *   u8p8 *Rte_Prm_HiLoadStallLimrStallMotTqCmdFetMtgtnLimY_Ary1D(Rte_Instance self)
 *     Returnvalue: u8p8* is of type Ary1D_u8p8_6
 *   u8p8 *Rte_Prm_HiLoadStallLimrStallMotTqCmdLimX_Ary1D(Rte_Instance self)
 *     Returnvalue: u8p8* is of type Ary1D_u8p8_6
 *   u8p8 *Rte_Prm_HiLoadStallLimrStallMotTqCmdLimY_Ary1D(Rte_Instance self)
 *     Returnvalue: u8p8* is of type Ary1D_u8p8_6
 *   float32 *Rte_Prm_HiLoadStallLimrStallMotTqLimSlewRate_Ary1D(Rte_Instance self)
 *     Returnvalue: float32* is of type Ary1D_f32_2
 *   u9p7 *Rte_Prm_MotCtrlPrmEstimnMotBackEmfConSatnX_Ary1D(Rte_Instance self)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_16
 *   u2p14 *Rte_Prm_MotCtrlPrmEstimnMotBackEmfConSatnY_Ary1D(Rte_Instance self)
 *     Returnvalue: u2p14* is of type Ary1D_u2p14_16
 *   u9p7 *Rte_Prm_MotCtrlPrmEstimnMotCurrDaxInduSatnBilnrSeln_Ary1D(Rte_Instance self)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_6
 *   u9p7 *Rte_Prm_MotCtrlPrmEstimnMotCurrQaxInduSatnX_Ary1D(Rte_Instance self)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_7
 *   u2p14 *Rte_Prm_MotCtrlPrmEstimnMotInduDaxSatnScaY_Ary2D(Rte_Instance self)
 *     Returnvalue: u2p14* is of type Ary2D_u2p14_6_7
 *   u2p14 *Rte_Prm_MotCtrlPrmEstimnMotInduQaxSatnScaY_Ary2D(Rte_Instance self)
 *     Returnvalue: u2p14* is of type Ary2D_u2p14_6_7
 *   u10p6 *Rte_Prm_MotCurrRegCfgMotClsdLoopBwDaxY_Ary1D(Rte_Instance self)
 *     Returnvalue: u10p6* is of type Ary1D_u10p6_4
 *   u10p6 *Rte_Prm_MotCurrRegCfgMotClsdLoopBwQaxY_Ary1D(Rte_Instance self)
 *     Returnvalue: u10p6* is of type Ary1D_u10p6_4
 *   u9p7 *Rte_Prm_MotCurrRegCfgMotNatFrqDaxY_Ary1D(Rte_Instance self)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_4
 *   u9p7 *Rte_Prm_MotCurrRegCfgMotNatFrqQaxY_Ary1D(Rte_Instance self)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_4
 *   u4p12 *Rte_Prm_MotRefMdlCurrDaxBoostTqScaX_Ary1D(Rte_Instance self)
 *     Returnvalue: u4p12* is of type Ary1D_u4p12_11
 *   u1p15 *Rte_Prm_MotRefMdlCurrDaxBoostTqScaY_Ary1D(Rte_Instance self)
 *     Returnvalue: u1p15* is of type Ary1D_u1p15_11
 *   float32 *Rte_Prm_MotRefMdlCurrDaxQaxRefDelta_Ary1D(Rte_Instance self)
 *     Returnvalue: float32* is of type Ary1D_f32_8
 *   u11p5 *Rte_Prm_MotRefMdlQuad13VltgSdlX_Ary1D(Rte_Instance self)
 *     Returnvalue: u11p5* is of type Ary1D_u11p5_10
 *   u3p13 *Rte_Prm_MotRefMdlQuad13VltgSdlY_Ary1D(Rte_Instance self)
 *     Returnvalue: u3p13* is of type Ary1D_u3p13_10
 *   u11p5 *Rte_Prm_MotRefMdlQuad24VltgSdlX_Ary1D(Rte_Instance self)
 *     Returnvalue: u11p5* is of type Ary1D_u11p5_10
 *   u3p13 *Rte_Prm_MotRefMdlQuad24VltgSdlY_Ary1D(Rte_Instance self)
 *     Returnvalue: u3p13* is of type Ary1D_u3p13_10
 *   s11p4 *Rte_Prm_PwrLimrMotEnvlpX_Ary1D(Rte_Instance self)
 *     Returnvalue: s11p4* is of type Ary1D_s11p4_14
 *   u5p11 *Rte_Prm_PwrLimrMotEnvlpY_Ary1D(Rte_Instance self)
 *     Returnvalue: u5p11* is of type Ary1D_u5p11_14
 *   u11p5 *Rte_Prm_PwrLimrStdOperMotEnvlpX_Ary1D(Rte_Instance self)
 *     Returnvalue: u11p5* is of type Ary1D_u11p5_6
 *   u4p12 *Rte_Prm_PwrLimrStdOperMotEnvlpY_Ary1D(Rte_Instance self)
 *     Returnvalue: u4p12* is of type Ary1D_u4p12_6
 *   u5p11 *Rte_Prm_PwrLimrVltgDptMotVelOffsX_Ary1D(Rte_Instance self)
 *     Returnvalue: u5p11* is of type Ary1D_u5p11_10
 *   u11p5 *Rte_Prm_PwrLimrVltgDptMotVelOffsY_Ary1D(Rte_Instance self)
 *     Returnvalue: u11p5* is of type Ary1D_u11p5_10
 *   float32 *Rte_Prm_TEstimnAmbPwrMplr_Ary1D(Rte_Instance self)
 *     Returnvalue: float32* is of type Ary1D_f32_3
 *   float32 *Rte_Prm_TEstimnAmbTSca_Ary1D(Rte_Instance self)
 *     Returnvalue: float32* is of type Ary1D_f32_3
 *   float32 *Rte_Prm_TEstimnAssiMechAmbMplr_Ary1D(Rte_Instance self)
 *     Returnvalue: float32* is of type Ary1D_f32_3
 *   float32 *Rte_Prm_TEstimnAssiMechCorrLim_Ary1D(Rte_Instance self)
 *     Returnvalue: float32* is of type Ary1D_f32_3
 *   float32 *Rte_Prm_TEstimnAssiMechDampgSca_Ary1D(Rte_Instance self)
 *     Returnvalue: float32* is of type Ary1D_f32_3
 *   float32 *Rte_Prm_TEstimnAssiMechDftT_Ary1D(Rte_Instance self)
 *     Returnvalue: float32* is of type Ary1D_f32_3
 *   float32 *Rte_Prm_TEstimnAssiMechLLFilCoeffA1_Ary1D(Rte_Instance self)
 *     Returnvalue: float32* is of type Ary1D_f32_3
 *   float32 *Rte_Prm_TEstimnAssiMechLLFilCoeffB0_Ary1D(Rte_Instance self)
 *     Returnvalue: float32* is of type Ary1D_f32_3
 *   float32 *Rte_Prm_TEstimnAssiMechLLFilCoeffB1_Ary1D(Rte_Instance self)
 *     Returnvalue: float32* is of type Ary1D_f32_3
 *   float32 *Rte_Prm_TEstimnAssiMechSlew_Ary1D(Rte_Instance self)
 *     Returnvalue: float32* is of type Ary1D_f32_3
 *   float32 *Rte_Prm_TEstimnCorrnTAssiMech_Ary1D(Rte_Instance self)
 *     Returnvalue: float32* is of type Ary1D_f32_3
 *   float32 *Rte_Prm_TEstimnCorrnTCu_Ary1D(Rte_Instance self)
 *     Returnvalue: float32* is of type Ary1D_f32_3
 *   float32 *Rte_Prm_TEstimnCorrnTMag_Ary1D(Rte_Instance self)
 *     Returnvalue: float32* is of type Ary1D_f32_3
 *   float32 *Rte_Prm_TEstimnCorrnTSi_Ary1D(Rte_Instance self)
 *     Returnvalue: float32* is of type Ary1D_f32_3
 *   float32 *Rte_Prm_TEstimnCuAmbMplr_Ary1D(Rte_Instance self)
 *     Returnvalue: float32* is of type Ary1D_f32_3
 *   float32 *Rte_Prm_TEstimnCuCorrnLim_Ary1D(Rte_Instance self)
 *     Returnvalue: float32* is of type Ary1D_f32_3
 *   float32 *Rte_Prm_TEstimnCuLLFilCoeffA1_Ary1D(Rte_Instance self)
 *     Returnvalue: float32* is of type Ary1D_f32_3
 *   float32 *Rte_Prm_TEstimnCuLLFilCoeffB0_Ary1D(Rte_Instance self)
 *     Returnvalue: float32* is of type Ary1D_f32_3
 *   float32 *Rte_Prm_TEstimnCuLLFilCoeffB1_Ary1D(Rte_Instance self)
 *     Returnvalue: float32* is of type Ary1D_f32_3
 *   float32 *Rte_Prm_TEstimnEngTSca_Ary1D(Rte_Instance self)
 *     Returnvalue: float32* is of type Ary1D_f32_3
 *   float32 *Rte_Prm_TEstimnMagAmbMplr_Ary1D(Rte_Instance self)
 *     Returnvalue: float32* is of type Ary1D_f32_3
 *   float32 *Rte_Prm_TEstimnMagCorrnLim_Ary1D(Rte_Instance self)
 *     Returnvalue: float32* is of type Ary1D_f32_3
 *   float32 *Rte_Prm_TEstimnMagLLFilCoeffA1_Ary1D(Rte_Instance self)
 *     Returnvalue: float32* is of type Ary1D_f32_3
 *   float32 *Rte_Prm_TEstimnMagLLFilCoeffB0_Ary1D(Rte_Instance self)
 *     Returnvalue: float32* is of type Ary1D_f32_3
 *   float32 *Rte_Prm_TEstimnMagLLFilCoeffB1_Ary1D(Rte_Instance self)
 *     Returnvalue: float32* is of type Ary1D_f32_3
 *   float32 *Rte_Prm_TEstimnSiAmbMplr_Ary1D(Rte_Instance self)
 *     Returnvalue: float32* is of type Ary1D_f32_3
 *   float32 *Rte_Prm_TEstimnSiCorrnLim_Ary1D(Rte_Instance self)
 *     Returnvalue: float32* is of type Ary1D_f32_3
 *   float32 *Rte_Prm_TEstimnSiLLFilCoeffA1_Ary1D(Rte_Instance self)
 *     Returnvalue: float32* is of type Ary1D_f32_3
 *   float32 *Rte_Prm_TEstimnSiLLFilCoeffB0_Ary1D(Rte_Instance self)
 *     Returnvalue: float32* is of type Ary1D_f32_3
 *   float32 *Rte_Prm_TEstimnSiLLFilCoeffB1_Ary1D(Rte_Instance self)
 *     Returnvalue: float32* is of type Ary1D_f32_3
 *   float32 *Rte_Prm_TEstimnTauAssiMech_Ary1D(Rte_Instance self)
 *     Returnvalue: float32* is of type Ary1D_f32_3
 *   float32 *Rte_Prm_TEstimnTauCu_Ary1D(Rte_Instance self)
 *     Returnvalue: float32* is of type Ary1D_f32_3
 *   float32 *Rte_Prm_TEstimnTauMag_Ary1D(Rte_Instance self)
 *     Returnvalue: float32* is of type Ary1D_f32_3
 *   float32 *Rte_Prm_TEstimnTauSi_Ary1D(Rte_Instance self)
 *     Returnvalue: float32* is of type Ary1D_f32_3
 *   boolean *Rte_Prm_TEstimnWghtAvrgTDi_Ary1D(Rte_Instance self)
 *     Returnvalue: boolean* is of type Ary1D_logl_3
 *
 *********************************************************************************************************************/


#define AAACalRegn01IninOptSetA01_Dummy_START_SEC_CODE
#include "AAACalRegn01IninOptSetA01_Dummy_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CalRegn01IninOptSetA01DummyInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CalRegn01IninOptSetA01DummyInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, AAACalRegn01IninOptSetA01_Dummy_CODE) CalRegn01IninOptSetA01DummyInit1(Rte_Instance self) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CalRegn01IninOptSetA01DummyInit1
 *********************************************************************************************************************/

  float32 DutyCycThermProtnAbsltMotVelBreakPt_Val_data;
  float32 DutyCycThermProtnAbsltTTqSlewHiLim_Val_data;
  float32 DutyCycThermProtnAbsltTTqSlewLoLim_Val_data;
  float32 DutyCycThermProtnCtrlT_Val_data;
  float32 DutyCycThermProtnIgnOffMsgWaitTi_Val_data;
  float32 DutyCycThermProtnThermLimScaFac_Val_data;
  float32 DutyCycThermProtnTqCmdSlewDwn_Val_data;
  float32 DutyCycThermProtnTqCmdSlewUp_Val_data;
  float32 HiLoadStallLimrStallThermLimSca_Val_data;
  float32 LrndRackCentrMotTqThd_Val_data;
  float32 LrndRackCentrMotVelThd_Val_data;
  float32 MotCtrlPrmEstimnFetRNom_Val_data;
  float32 MotCtrlPrmEstimnMotBackEmfConHiLim_Val_data;
  float32 MotCtrlPrmEstimnMotBackEmfConLoLim_Val_data;
  float32 MotCtrlPrmEstimnMotBackEmfConNom_Val_data;
  float32 MotCtrlPrmEstimnMotBackEmfConSatnScaIvtrLoaMtgtn_Val_data;
  float32 MotCtrlPrmEstimnMotInduDaxHiLim_Val_data;
  float32 MotCtrlPrmEstimnMotInduDaxIvtrLoaMtgtn_Val_data;
  float32 MotCtrlPrmEstimnMotInduDaxLoLim_Val_data;
  float32 MotCtrlPrmEstimnMotInduDaxNom_Val_data;
  float32 MotCtrlPrmEstimnMotInduQaxHiLim_Val_data;
  float32 MotCtrlPrmEstimnMotInduQaxIvtrLoaMtgtn_Val_data;
  float32 MotCtrlPrmEstimnMotInduQaxLoLim_Val_data;
  float32 MotCtrlPrmEstimnMotInduQaxNom_Val_data;
  float32 MotCtrlPrmEstimnMotRHiLim_Val_data;
  float32 MotCtrlPrmEstimnMotRLoLim_Val_data;
  float32 MotCtrlPrmEstimnMotRNom_Val_data;
  float32 MotCtrlPrmEstimnMotWidgThermCoeff_Val_data;
  float32 MotCtrlPrmEstimnTNom_Val_data;
  float32 MotCurrPeakEstimnCurrFilFrq_Val_data;
  float32 MotCurrPeakEstimnCurrPeakEstimdFilFrq_Val_data;
  float32 MotCurrRegCfgMotDampgRatDax_Val_data;
  float32 MotCurrRegCfgMotDampgRatQax_Val_data;
  float32 MotCurrRegCfgMotRVirtDax_Val_data;
  float32 MotCurrRegCfgMotRVirtQax_Val_data;
  float32 MotCurrRegCfgMotVelFilFrq_Val_data;
  float32 MotCurrRegVltgLimrCurrLoaScarSlewRate_Val_data;
  float32 MotCurrRegVltgLimrDaxAntiWdupCoeff_Val_data;
  float32 MotCurrRegVltgLimrDualEcuLoaScarSlewRate_Val_data;
  float32 MotCurrRegVltgLimrFETLoaScarSlewRate_Val_data;
  float32 MotCurrRegVltgLimrIvtrLoaScarSlewRate_Val_data;
  float32 MotCurrRegVltgLimrMotVltgBrdgLpFilFrq_Val_data;
  float32 MotCurrRegVltgLimrMotVltgDaxIntglHiLim_Val_data;
  float32 MotCurrRegVltgLimrMotVltgDaxIntglLoLim_Val_data;
  float32 MotCurrRegVltgLimrMotVltgQaxFfLpFilFrq_Val_data;
  float32 MotCurrRegVltgLimrMotVltgQaxIntglHiLim_Val_data;
  float32 MotCurrRegVltgLimrMotVltgQaxIntglLoLim_Val_data;
  float32 MotCurrRegVltgLimrQaxAntiWdupCoeff_Val_data;
  float32 MotRefMdlCurrDaxBoostGain_Val_data;
  float32 MotRefMdlCurrItrnTolr_Val_data;
  float32 MotRefMdlMotCurrDaxMaxSca_Val_data;
  float32 MotRefMdlVltgOverRThdSca_Val_data;
  float32 MotTqTranlDampgCmdLim_Val_data;
  float32 MotTqTranlDampgVelThd_Val_data;
  float32 PwrLimrAssiRednLpFilFrq_Val_data;
  float32 PwrLimrBackEmfConStdT_Val_data;
  float32 PwrLimrBrdgVltgAdjSlew_Val_data;
  float32 PwrLimrBrdgVltgAltFltAdj_Val_data;
  float32 PwrLimrFilAssiRednThd_Val_data;
  float32 PwrLimrLoVoltAssiRcvrThd_Val_data;
  float32 PwrLimrMotVelLpFilFrq_Val_data;
  float32 PwrLimrSpdAdjSlewDec_Val_data;
  float32 PwrLimrSpdAdjSlewInc_Val_data;
  float32 SysGlbPrmSysTqRat_Val_data;
  float32 TEstimnAssiMechAmbLpFilFrq_Val_data;
  float32 TEstimnAssiMechAmbLpFilFrqDualEcuFltMtgtn_Val_data;
  float32 TEstimnAssiMechAmbLpFilFrqFetMtgtnEna_Val_data;
  float32 TEstimnCuAmbLpFilFrq_Val_data;
  float32 TEstimnCuAmbLpFilFrqDualEcuFltMtgtn_Val_data;
  float32 TEstimnCuAmbLpFilFrqFetMtgtnEna_Val_data;
  float32 TEstimnMagAmbLpFilFrq_Val_data;
  float32 TEstimnMagAmbLpFilFrqDualEcuFltMtgtn_Val_data;
  float32 TEstimnMagAmbLpFilFrqFetMtgtnEna_Val_data;
  float32 TEstimnSiAmbLpFilFrq_Val_data;
  float32 TEstimnSiAmbLpFilFrqDualEcuFltMtgtn_Val_data;
  float32 TEstimnSiAmbLpFilFrqFetMtgtnEna_Val_data;
  float32 VehSpdLimrPosMaxOffs2_Val_data;
  u16p0 DutyCycThermProtnDutyCycFildThd_Val_data;
  uint16 PwrLimrLoVoltAssiRcvrTi_Val_data;
  boolean DutyCycThermProtnCtrlTSeln_Logl_data;
  boolean DutyCycThermProtnIgnOffCtrlEna_Logl_data;
  boolean DutyCycThermProtnMotPrTSeln_Logl_data;
  boolean DutyCycThermProtnMplrTSeln_Logl_data;
  boolean DutyCycThermProtnSlowFilTSeln_Logl_data;
  boolean MotCurrRegVltgLimrQaxAntiWdupScagDi_Logl_data;
  boolean PwrLimrSpdAdjSlewEna_Logl_data;
  Ary1D_s15p0_4 DutyCycThermProtnAbsltCtrlTFetMtgtnTblX_Ary1D_data;
  Ary1D_s15p0_4 DutyCycThermProtnAbsltCtrlTTblX_Ary1D_data;
  Ary1D_u9p7_4 DutyCycThermProtnAbsltCtrlTTqFetMtgtnTblY_Ary1D_data;
  Ary1D_u9p7_4 DutyCycThermProtnAbsltCtrlTTqTblY_Ary1D_data;
  Ary1D_s15p0_4 DutyCycThermProtnAbsltCuTFetMtgtnTblX_Ary1D_data;
  Ary1D_s15p0_4 DutyCycThermProtnAbsltCuTTblX_Ary1D_data;
  Ary1D_u9p7_4 DutyCycThermProtnAbsltCuTTqFetMtgtnTblY_Ary1D_data;
  Ary1D_u9p7_4 DutyCycThermProtnAbsltCuTTqTblY_Ary1D_data;
  Ary2D_u9p7_2_5 DutyCycThermProtnLstTblValNonStall_Ary2D_data;
  Ary2D_u9p7_2_5 DutyCycThermProtnLstTblValStall_Ary2D_data;
  Ary1D_u3p13_5 DutyCycThermProtnMplr1FetMtgtnNonStallTblY_Ary1D_data;
  Ary1D_u3p13_5 DutyCycThermProtnMplr1FetMtgtnStallTblY_Ary1D_data;
  Ary1D_u3p13_5 DutyCycThermProtnMplr1NonStallTblY_Ary1D_data;
  Ary1D_u3p13_5 DutyCycThermProtnMplr1StallTblY_Ary1D_data;
  Ary1D_u3p13_5 DutyCycThermProtnMplr2FetMtgtnNonStallTblY_Ary1D_data;
  Ary1D_u3p13_5 DutyCycThermProtnMplr2FetMtgtnStallTblY_Ary1D_data;
  Ary1D_u3p13_5 DutyCycThermProtnMplr2NonStallTblY_Ary1D_data;
  Ary1D_u3p13_5 DutyCycThermProtnMplr2StallTblY_Ary1D_data;
  Ary1D_u3p13_5 DutyCycThermProtnMplr3FetMtgtnNonStallTblY_Ary1D_data;
  Ary1D_u3p13_5 DutyCycThermProtnMplr3FetMtgtnStallTblY_Ary1D_data;
  Ary1D_u3p13_5 DutyCycThermProtnMplr3NonStallTblY_Ary1D_data;
  Ary1D_u3p13_5 DutyCycThermProtnMplr3StallTblY_Ary1D_data;
  Ary1D_u3p13_5 DutyCycThermProtnMplr4FetMtgtnNonStallTblY_Ary1D_data;
  Ary1D_u3p13_5 DutyCycThermProtnMplr4FetMtgtnStallTblY_Ary1D_data;
  Ary1D_u3p13_5 DutyCycThermProtnMplr4NonStallTblY_Ary1D_data;
  Ary1D_u3p13_5 DutyCycThermProtnMplr4StallTblY_Ary1D_data;
  Ary1D_u3p13_5 DutyCycThermProtnMplr5FetMtgtnNonStallTblY_Ary1D_data;
  Ary1D_u3p13_5 DutyCycThermProtnMplr5FetMtgtnStallTblY_Ary1D_data;
  Ary1D_u3p13_5 DutyCycThermProtnMplr5NonStallTblY_Ary1D_data;
  Ary1D_u3p13_5 DutyCycThermProtnMplr5StallTblY_Ary1D_data;
  Ary1D_u3p13_5 DutyCycThermProtnMplr6FetMtgtnNonStallTblY_Ary1D_data;
  Ary1D_u3p13_5 DutyCycThermProtnMplr6FetMtgtnStallTblY_Ary1D_data;
  Ary1D_u3p13_5 DutyCycThermProtnMplr6NonStallTblY_Ary1D_data;
  Ary1D_u3p13_5 DutyCycThermProtnMplr6StallTblY_Ary1D_data;
  Ary1D_s15p0_5 DutyCycThermProtnMplrFetMtgtnTblX_Ary1D_data;
  Ary1D_s15p0_5 DutyCycThermProtnMplrTblX_Ary1D_data;
  Ary2D_u16p0_2_8 DutyCycThermProtnThermLoadLimTblX_Ary2D_data;
  Ary2D_u9p7_2_8 DutyCycThermProtnThermLoadLimTblY_Ary2D_data;
  Ary1D_f32_2 HiLoadStallLimrMotVelMgnThd_Ary1D_data;
  Ary1D_u8p8_6 HiLoadStallLimrStallMotTqCmdFetMtgtnLimX_Ary1D_data;
  Ary1D_u8p8_6 HiLoadStallLimrStallMotTqCmdFetMtgtnLimY_Ary1D_data;
  Ary1D_u8p8_6 HiLoadStallLimrStallMotTqCmdLimX_Ary1D_data;
  Ary1D_u8p8_6 HiLoadStallLimrStallMotTqCmdLimY_Ary1D_data;
  Ary1D_f32_2 HiLoadStallLimrStallMotTqLimSlewRate_Ary1D_data;
  Ary1D_u9p7_16 MotCtrlPrmEstimnMotBackEmfConSatnX_Ary1D_data;
  Ary1D_u2p14_16 MotCtrlPrmEstimnMotBackEmfConSatnY_Ary1D_data;
  Ary1D_u9p7_6 MotCtrlPrmEstimnMotCurrDaxInduSatnBilnrSeln_Ary1D_data;
  Ary1D_u9p7_7 MotCtrlPrmEstimnMotCurrQaxInduSatnX_Ary1D_data;
  Ary2D_u2p14_6_7 MotCtrlPrmEstimnMotInduDaxSatnScaY_Ary2D_data;
  Ary2D_u2p14_6_7 MotCtrlPrmEstimnMotInduQaxSatnScaY_Ary2D_data;
  Ary1D_u10p6_4 MotCurrRegCfgMotClsdLoopBwDaxY_Ary1D_data;
  Ary1D_u10p6_4 MotCurrRegCfgMotClsdLoopBwQaxY_Ary1D_data;
  Ary1D_u9p7_4 MotCurrRegCfgMotNatFrqDaxY_Ary1D_data;
  Ary1D_u9p7_4 MotCurrRegCfgMotNatFrqQaxY_Ary1D_data;
  Ary1D_u4p12_11 MotRefMdlCurrDaxBoostTqScaX_Ary1D_data;
  Ary1D_u1p15_11 MotRefMdlCurrDaxBoostTqScaY_Ary1D_data;
  Ary1D_f32_8 MotRefMdlCurrDaxQaxRefDelta_Ary1D_data;
  Ary1D_u11p5_10 MotRefMdlQuad13VltgSdlX_Ary1D_data;
  Ary1D_u3p13_10 MotRefMdlQuad13VltgSdlY_Ary1D_data;
  Ary1D_u11p5_10 MotRefMdlQuad24VltgSdlX_Ary1D_data;
  Ary1D_u3p13_10 MotRefMdlQuad24VltgSdlY_Ary1D_data;
  Ary1D_s11p4_14 PwrLimrMotEnvlpX_Ary1D_data;
  Ary1D_u5p11_14 PwrLimrMotEnvlpY_Ary1D_data;
  Ary1D_u11p5_6 PwrLimrStdOperMotEnvlpX_Ary1D_data;
  Ary1D_u4p12_6 PwrLimrStdOperMotEnvlpY_Ary1D_data;
  Ary1D_u5p11_10 PwrLimrVltgDptMotVelOffsX_Ary1D_data;
  Ary1D_u11p5_10 PwrLimrVltgDptMotVelOffsY_Ary1D_data;
  Ary1D_f32_3 TEstimnAmbPwrMplr_Ary1D_data;
  Ary1D_f32_3 TEstimnAmbTSca_Ary1D_data;
  Ary1D_f32_3 TEstimnAssiMechAmbMplr_Ary1D_data;
  Ary1D_f32_3 TEstimnAssiMechCorrLim_Ary1D_data;
  Ary1D_f32_3 TEstimnAssiMechDampgSca_Ary1D_data;
  Ary1D_f32_3 TEstimnAssiMechDftT_Ary1D_data;
  Ary1D_f32_3 TEstimnAssiMechLLFilCoeffA1_Ary1D_data;
  Ary1D_f32_3 TEstimnAssiMechLLFilCoeffB0_Ary1D_data;
  Ary1D_f32_3 TEstimnAssiMechLLFilCoeffB1_Ary1D_data;
  Ary1D_f32_3 TEstimnAssiMechSlew_Ary1D_data;
  Ary1D_f32_3 TEstimnCorrnTAssiMech_Ary1D_data;
  Ary1D_f32_3 TEstimnCorrnTCu_Ary1D_data;
  Ary1D_f32_3 TEstimnCorrnTMag_Ary1D_data;
  Ary1D_f32_3 TEstimnCorrnTSi_Ary1D_data;
  Ary1D_f32_3 TEstimnCuAmbMplr_Ary1D_data;
  Ary1D_f32_3 TEstimnCuCorrnLim_Ary1D_data;
  Ary1D_f32_3 TEstimnCuLLFilCoeffA1_Ary1D_data;
  Ary1D_f32_3 TEstimnCuLLFilCoeffB0_Ary1D_data;
  Ary1D_f32_3 TEstimnCuLLFilCoeffB1_Ary1D_data;
  Ary1D_f32_3 TEstimnEngTSca_Ary1D_data;
  Ary1D_f32_3 TEstimnMagAmbMplr_Ary1D_data;
  Ary1D_f32_3 TEstimnMagCorrnLim_Ary1D_data;
  Ary1D_f32_3 TEstimnMagLLFilCoeffA1_Ary1D_data;
  Ary1D_f32_3 TEstimnMagLLFilCoeffB0_Ary1D_data;
  Ary1D_f32_3 TEstimnMagLLFilCoeffB1_Ary1D_data;
  Ary1D_f32_3 TEstimnSiAmbMplr_Ary1D_data;
  Ary1D_f32_3 TEstimnSiCorrnLim_Ary1D_data;
  Ary1D_f32_3 TEstimnSiLLFilCoeffA1_Ary1D_data;
  Ary1D_f32_3 TEstimnSiLLFilCoeffB0_Ary1D_data;
  Ary1D_f32_3 TEstimnSiLLFilCoeffB1_Ary1D_data;
  Ary1D_f32_3 TEstimnTauAssiMech_Ary1D_data;
  Ary1D_f32_3 TEstimnTauCu_Ary1D_data;
  Ary1D_f32_3 TEstimnTauMag_Ary1D_data;
  Ary1D_f32_3 TEstimnTauSi_Ary1D_data;
  Ary1D_logl_3 TEstimnWghtAvrgTDi_Ary1D_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  DutyCycThermProtnAbsltMotVelBreakPt_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_DutyCycThermProtnAbsltMotVelBreakPt_Val(self);
  DutyCycThermProtnAbsltTTqSlewHiLim_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_DutyCycThermProtnAbsltTTqSlewHiLim_Val(self);
  DutyCycThermProtnAbsltTTqSlewLoLim_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_DutyCycThermProtnAbsltTTqSlewLoLim_Val(self);
  DutyCycThermProtnCtrlT_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_DutyCycThermProtnCtrlT_Val(self);
  DutyCycThermProtnIgnOffMsgWaitTi_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_DutyCycThermProtnIgnOffMsgWaitTi_Val(self);
  DutyCycThermProtnThermLimScaFac_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_DutyCycThermProtnThermLimScaFac_Val(self);
  DutyCycThermProtnTqCmdSlewDwn_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_DutyCycThermProtnTqCmdSlewDwn_Val(self);
  DutyCycThermProtnTqCmdSlewUp_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_DutyCycThermProtnTqCmdSlewUp_Val(self);
  HiLoadStallLimrStallThermLimSca_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_HiLoadStallLimrStallThermLimSca_Val(self);
  LrndRackCentrMotTqThd_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_LrndRackCentrMotTqThd_Val(self);
  LrndRackCentrMotVelThd_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_LrndRackCentrMotVelThd_Val(self);
  MotCtrlPrmEstimnFetRNom_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_MotCtrlPrmEstimnFetRNom_Val(self);
  MotCtrlPrmEstimnMotBackEmfConHiLim_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_MotCtrlPrmEstimnMotBackEmfConHiLim_Val(self);
  MotCtrlPrmEstimnMotBackEmfConLoLim_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_MotCtrlPrmEstimnMotBackEmfConLoLim_Val(self);
  MotCtrlPrmEstimnMotBackEmfConNom_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_MotCtrlPrmEstimnMotBackEmfConNom_Val(self);
  MotCtrlPrmEstimnMotBackEmfConSatnScaIvtrLoaMtgtn_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_MotCtrlPrmEstimnMotBackEmfConSatnScaIvtrLoaMtgtn_Val(self);
  MotCtrlPrmEstimnMotInduDaxHiLim_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_MotCtrlPrmEstimnMotInduDaxHiLim_Val(self);
  MotCtrlPrmEstimnMotInduDaxIvtrLoaMtgtn_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_MotCtrlPrmEstimnMotInduDaxIvtrLoaMtgtn_Val(self);
  MotCtrlPrmEstimnMotInduDaxLoLim_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_MotCtrlPrmEstimnMotInduDaxLoLim_Val(self);
  MotCtrlPrmEstimnMotInduDaxNom_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_MotCtrlPrmEstimnMotInduDaxNom_Val(self);
  MotCtrlPrmEstimnMotInduQaxHiLim_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_MotCtrlPrmEstimnMotInduQaxHiLim_Val(self);
  MotCtrlPrmEstimnMotInduQaxIvtrLoaMtgtn_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_MotCtrlPrmEstimnMotInduQaxIvtrLoaMtgtn_Val(self);
  MotCtrlPrmEstimnMotInduQaxLoLim_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_MotCtrlPrmEstimnMotInduQaxLoLim_Val(self);
  MotCtrlPrmEstimnMotInduQaxNom_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_MotCtrlPrmEstimnMotInduQaxNom_Val(self);
  MotCtrlPrmEstimnMotRHiLim_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_MotCtrlPrmEstimnMotRHiLim_Val(self);
  MotCtrlPrmEstimnMotRLoLim_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_MotCtrlPrmEstimnMotRLoLim_Val(self);
  MotCtrlPrmEstimnMotRNom_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_MotCtrlPrmEstimnMotRNom_Val(self);
  MotCtrlPrmEstimnMotWidgThermCoeff_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_MotCtrlPrmEstimnMotWidgThermCoeff_Val(self);
  MotCtrlPrmEstimnTNom_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_MotCtrlPrmEstimnTNom_Val(self);
  MotCurrPeakEstimnCurrFilFrq_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_MotCurrPeakEstimnCurrFilFrq_Val(self);
  MotCurrPeakEstimnCurrPeakEstimdFilFrq_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_MotCurrPeakEstimnCurrPeakEstimdFilFrq_Val(self);
  MotCurrRegCfgMotDampgRatDax_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_MotCurrRegCfgMotDampgRatDax_Val(self);
  MotCurrRegCfgMotDampgRatQax_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_MotCurrRegCfgMotDampgRatQax_Val(self);
  MotCurrRegCfgMotRVirtDax_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_MotCurrRegCfgMotRVirtDax_Val(self);
  MotCurrRegCfgMotRVirtQax_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_MotCurrRegCfgMotRVirtQax_Val(self);
  MotCurrRegCfgMotVelFilFrq_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_MotCurrRegCfgMotVelFilFrq_Val(self);
  MotCurrRegVltgLimrCurrLoaScarSlewRate_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_MotCurrRegVltgLimrCurrLoaScarSlewRate_Val(self);
  MotCurrRegVltgLimrDaxAntiWdupCoeff_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_MotCurrRegVltgLimrDaxAntiWdupCoeff_Val(self);
  MotCurrRegVltgLimrDualEcuLoaScarSlewRate_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_MotCurrRegVltgLimrDualEcuLoaScarSlewRate_Val(self);
  MotCurrRegVltgLimrFETLoaScarSlewRate_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_MotCurrRegVltgLimrFETLoaScarSlewRate_Val(self);
  MotCurrRegVltgLimrIvtrLoaScarSlewRate_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_MotCurrRegVltgLimrIvtrLoaScarSlewRate_Val(self);
  MotCurrRegVltgLimrMotVltgBrdgLpFilFrq_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_MotCurrRegVltgLimrMotVltgBrdgLpFilFrq_Val(self);
  MotCurrRegVltgLimrMotVltgDaxIntglHiLim_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_MotCurrRegVltgLimrMotVltgDaxIntglHiLim_Val(self);
  MotCurrRegVltgLimrMotVltgDaxIntglLoLim_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_MotCurrRegVltgLimrMotVltgDaxIntglLoLim_Val(self);
  MotCurrRegVltgLimrMotVltgQaxFfLpFilFrq_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_MotCurrRegVltgLimrMotVltgQaxFfLpFilFrq_Val(self);
  MotCurrRegVltgLimrMotVltgQaxIntglHiLim_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_MotCurrRegVltgLimrMotVltgQaxIntglHiLim_Val(self);
  MotCurrRegVltgLimrMotVltgQaxIntglLoLim_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_MotCurrRegVltgLimrMotVltgQaxIntglLoLim_Val(self);
  MotCurrRegVltgLimrQaxAntiWdupCoeff_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_MotCurrRegVltgLimrQaxAntiWdupCoeff_Val(self);
  MotRefMdlCurrDaxBoostGain_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_MotRefMdlCurrDaxBoostGain_Val(self);
  MotRefMdlCurrItrnTolr_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_MotRefMdlCurrItrnTolr_Val(self);
  MotRefMdlMotCurrDaxMaxSca_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_MotRefMdlMotCurrDaxMaxSca_Val(self);
  MotRefMdlVltgOverRThdSca_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_MotRefMdlVltgOverRThdSca_Val(self);
  MotTqTranlDampgCmdLim_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_MotTqTranlDampgCmdLim_Val(self);
  MotTqTranlDampgVelThd_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_MotTqTranlDampgVelThd_Val(self);
  PwrLimrAssiRednLpFilFrq_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_PwrLimrAssiRednLpFilFrq_Val(self);
  PwrLimrBackEmfConStdT_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_PwrLimrBackEmfConStdT_Val(self);
  PwrLimrBrdgVltgAdjSlew_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_PwrLimrBrdgVltgAdjSlew_Val(self);
  PwrLimrBrdgVltgAltFltAdj_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_PwrLimrBrdgVltgAltFltAdj_Val(self);
  PwrLimrFilAssiRednThd_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_PwrLimrFilAssiRednThd_Val(self);
  PwrLimrLoVoltAssiRcvrThd_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_PwrLimrLoVoltAssiRcvrThd_Val(self);
  PwrLimrMotVelLpFilFrq_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_PwrLimrMotVelLpFilFrq_Val(self);
  PwrLimrSpdAdjSlewDec_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_PwrLimrSpdAdjSlewDec_Val(self);
  PwrLimrSpdAdjSlewInc_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_PwrLimrSpdAdjSlewInc_Val(self);
  SysGlbPrmSysTqRat_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_SysGlbPrmSysTqRat_Val(self);
  TEstimnAssiMechAmbLpFilFrq_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_TEstimnAssiMechAmbLpFilFrq_Val(self);
  TEstimnAssiMechAmbLpFilFrqDualEcuFltMtgtn_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_TEstimnAssiMechAmbLpFilFrqDualEcuFltMtgtn_Val(self);
  TEstimnAssiMechAmbLpFilFrqFetMtgtnEna_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_TEstimnAssiMechAmbLpFilFrqFetMtgtnEna_Val(self);
  TEstimnCuAmbLpFilFrq_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_TEstimnCuAmbLpFilFrq_Val(self);
  TEstimnCuAmbLpFilFrqDualEcuFltMtgtn_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_TEstimnCuAmbLpFilFrqDualEcuFltMtgtn_Val(self);
  TEstimnCuAmbLpFilFrqFetMtgtnEna_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_TEstimnCuAmbLpFilFrqFetMtgtnEna_Val(self);
  TEstimnMagAmbLpFilFrq_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_TEstimnMagAmbLpFilFrq_Val(self);
  TEstimnMagAmbLpFilFrqDualEcuFltMtgtn_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_TEstimnMagAmbLpFilFrqDualEcuFltMtgtn_Val(self);
  TEstimnMagAmbLpFilFrqFetMtgtnEna_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_TEstimnMagAmbLpFilFrqFetMtgtnEna_Val(self);
  TEstimnSiAmbLpFilFrq_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_TEstimnSiAmbLpFilFrq_Val(self);
  TEstimnSiAmbLpFilFrqDualEcuFltMtgtn_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_TEstimnSiAmbLpFilFrqDualEcuFltMtgtn_Val(self);
  TEstimnSiAmbLpFilFrqFetMtgtnEna_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_TEstimnSiAmbLpFilFrqFetMtgtnEna_Val(self);
  VehSpdLimrPosMaxOffs2_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_VehSpdLimrPosMaxOffs2_Val(self);
  DutyCycThermProtnDutyCycFildThd_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_DutyCycThermProtnDutyCycFildThd_Val(self);
  PwrLimrLoVoltAssiRcvrTi_Val_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_PwrLimrLoVoltAssiRcvrTi_Val(self);
  DutyCycThermProtnCtrlTSeln_Logl_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_DutyCycThermProtnCtrlTSeln_Logl(self);
  DutyCycThermProtnIgnOffCtrlEna_Logl_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_DutyCycThermProtnIgnOffCtrlEna_Logl(self);
  DutyCycThermProtnMotPrTSeln_Logl_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_DutyCycThermProtnMotPrTSeln_Logl(self);
  DutyCycThermProtnMplrTSeln_Logl_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_DutyCycThermProtnMplrTSeln_Logl(self);
  DutyCycThermProtnSlowFilTSeln_Logl_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_DutyCycThermProtnSlowFilTSeln_Logl(self);
  MotCurrRegVltgLimrQaxAntiWdupScagDi_Logl_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_MotCurrRegVltgLimrQaxAntiWdupScagDi_Logl(self);
  PwrLimrSpdAdjSlewEna_Logl_data = TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_PwrLimrSpdAdjSlewEna_Logl(self);
  (void)memcpy(DutyCycThermProtnAbsltCtrlTFetMtgtnTblX_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_DutyCycThermProtnAbsltCtrlTFetMtgtnTblX_Ary1D(self), sizeof(Ary1D_s15p0_4));
  (void)memcpy(DutyCycThermProtnAbsltCtrlTTblX_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_DutyCycThermProtnAbsltCtrlTTblX_Ary1D(self), sizeof(Ary1D_s15p0_4));
  (void)memcpy(DutyCycThermProtnAbsltCtrlTTqFetMtgtnTblY_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_DutyCycThermProtnAbsltCtrlTTqFetMtgtnTblY_Ary1D(self), sizeof(Ary1D_u9p7_4));
  (void)memcpy(DutyCycThermProtnAbsltCtrlTTqTblY_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_DutyCycThermProtnAbsltCtrlTTqTblY_Ary1D(self), sizeof(Ary1D_u9p7_4));
  (void)memcpy(DutyCycThermProtnAbsltCuTFetMtgtnTblX_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_DutyCycThermProtnAbsltCuTFetMtgtnTblX_Ary1D(self), sizeof(Ary1D_s15p0_4));
  (void)memcpy(DutyCycThermProtnAbsltCuTTblX_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_DutyCycThermProtnAbsltCuTTblX_Ary1D(self), sizeof(Ary1D_s15p0_4));
  (void)memcpy(DutyCycThermProtnAbsltCuTTqFetMtgtnTblY_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_DutyCycThermProtnAbsltCuTTqFetMtgtnTblY_Ary1D(self), sizeof(Ary1D_u9p7_4));
  (void)memcpy(DutyCycThermProtnAbsltCuTTqTblY_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_DutyCycThermProtnAbsltCuTTqTblY_Ary1D(self), sizeof(Ary1D_u9p7_4));
  (void)memcpy(DutyCycThermProtnLstTblValNonStall_Ary2D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_DutyCycThermProtnLstTblValNonStall_Ary2D(self), sizeof(Ary2D_u9p7_2_5));
  (void)memcpy(DutyCycThermProtnLstTblValStall_Ary2D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_DutyCycThermProtnLstTblValStall_Ary2D(self), sizeof(Ary2D_u9p7_2_5));
  (void)memcpy(DutyCycThermProtnMplr1FetMtgtnNonStallTblY_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_DutyCycThermProtnMplr1FetMtgtnNonStallTblY_Ary1D(self), sizeof(Ary1D_u3p13_5));
  (void)memcpy(DutyCycThermProtnMplr1FetMtgtnStallTblY_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_DutyCycThermProtnMplr1FetMtgtnStallTblY_Ary1D(self), sizeof(Ary1D_u3p13_5));
  (void)memcpy(DutyCycThermProtnMplr1NonStallTblY_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_DutyCycThermProtnMplr1NonStallTblY_Ary1D(self), sizeof(Ary1D_u3p13_5));
  (void)memcpy(DutyCycThermProtnMplr1StallTblY_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_DutyCycThermProtnMplr1StallTblY_Ary1D(self), sizeof(Ary1D_u3p13_5));
  (void)memcpy(DutyCycThermProtnMplr2FetMtgtnNonStallTblY_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_DutyCycThermProtnMplr2FetMtgtnNonStallTblY_Ary1D(self), sizeof(Ary1D_u3p13_5));
  (void)memcpy(DutyCycThermProtnMplr2FetMtgtnStallTblY_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_DutyCycThermProtnMplr2FetMtgtnStallTblY_Ary1D(self), sizeof(Ary1D_u3p13_5));
  (void)memcpy(DutyCycThermProtnMplr2NonStallTblY_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_DutyCycThermProtnMplr2NonStallTblY_Ary1D(self), sizeof(Ary1D_u3p13_5));
  (void)memcpy(DutyCycThermProtnMplr2StallTblY_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_DutyCycThermProtnMplr2StallTblY_Ary1D(self), sizeof(Ary1D_u3p13_5));
  (void)memcpy(DutyCycThermProtnMplr3FetMtgtnNonStallTblY_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_DutyCycThermProtnMplr3FetMtgtnNonStallTblY_Ary1D(self), sizeof(Ary1D_u3p13_5));
  (void)memcpy(DutyCycThermProtnMplr3FetMtgtnStallTblY_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_DutyCycThermProtnMplr3FetMtgtnStallTblY_Ary1D(self), sizeof(Ary1D_u3p13_5));
  (void)memcpy(DutyCycThermProtnMplr3NonStallTblY_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_DutyCycThermProtnMplr3NonStallTblY_Ary1D(self), sizeof(Ary1D_u3p13_5));
  (void)memcpy(DutyCycThermProtnMplr3StallTblY_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_DutyCycThermProtnMplr3StallTblY_Ary1D(self), sizeof(Ary1D_u3p13_5));
  (void)memcpy(DutyCycThermProtnMplr4FetMtgtnNonStallTblY_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_DutyCycThermProtnMplr4FetMtgtnNonStallTblY_Ary1D(self), sizeof(Ary1D_u3p13_5));
  (void)memcpy(DutyCycThermProtnMplr4FetMtgtnStallTblY_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_DutyCycThermProtnMplr4FetMtgtnStallTblY_Ary1D(self), sizeof(Ary1D_u3p13_5));
  (void)memcpy(DutyCycThermProtnMplr4NonStallTblY_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_DutyCycThermProtnMplr4NonStallTblY_Ary1D(self), sizeof(Ary1D_u3p13_5));
  (void)memcpy(DutyCycThermProtnMplr4StallTblY_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_DutyCycThermProtnMplr4StallTblY_Ary1D(self), sizeof(Ary1D_u3p13_5));
  (void)memcpy(DutyCycThermProtnMplr5FetMtgtnNonStallTblY_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_DutyCycThermProtnMplr5FetMtgtnNonStallTblY_Ary1D(self), sizeof(Ary1D_u3p13_5));
  (void)memcpy(DutyCycThermProtnMplr5FetMtgtnStallTblY_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_DutyCycThermProtnMplr5FetMtgtnStallTblY_Ary1D(self), sizeof(Ary1D_u3p13_5));
  (void)memcpy(DutyCycThermProtnMplr5NonStallTblY_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_DutyCycThermProtnMplr5NonStallTblY_Ary1D(self), sizeof(Ary1D_u3p13_5));
  (void)memcpy(DutyCycThermProtnMplr5StallTblY_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_DutyCycThermProtnMplr5StallTblY_Ary1D(self), sizeof(Ary1D_u3p13_5));
  (void)memcpy(DutyCycThermProtnMplr6FetMtgtnNonStallTblY_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_DutyCycThermProtnMplr6FetMtgtnNonStallTblY_Ary1D(self), sizeof(Ary1D_u3p13_5));
  (void)memcpy(DutyCycThermProtnMplr6FetMtgtnStallTblY_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_DutyCycThermProtnMplr6FetMtgtnStallTblY_Ary1D(self), sizeof(Ary1D_u3p13_5));
  (void)memcpy(DutyCycThermProtnMplr6NonStallTblY_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_DutyCycThermProtnMplr6NonStallTblY_Ary1D(self), sizeof(Ary1D_u3p13_5));
  (void)memcpy(DutyCycThermProtnMplr6StallTblY_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_DutyCycThermProtnMplr6StallTblY_Ary1D(self), sizeof(Ary1D_u3p13_5));
  (void)memcpy(DutyCycThermProtnMplrFetMtgtnTblX_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_DutyCycThermProtnMplrFetMtgtnTblX_Ary1D(self), sizeof(Ary1D_s15p0_5));
  (void)memcpy(DutyCycThermProtnMplrTblX_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_DutyCycThermProtnMplrTblX_Ary1D(self), sizeof(Ary1D_s15p0_5));
  (void)memcpy(DutyCycThermProtnThermLoadLimTblX_Ary2D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_DutyCycThermProtnThermLoadLimTblX_Ary2D(self), sizeof(Ary2D_u16p0_2_8));
  (void)memcpy(DutyCycThermProtnThermLoadLimTblY_Ary2D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_DutyCycThermProtnThermLoadLimTblY_Ary2D(self), sizeof(Ary2D_u9p7_2_8));
  (void)memcpy(HiLoadStallLimrMotVelMgnThd_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_HiLoadStallLimrMotVelMgnThd_Ary1D(self), sizeof(Ary1D_f32_2));
  (void)memcpy(HiLoadStallLimrStallMotTqCmdFetMtgtnLimX_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_HiLoadStallLimrStallMotTqCmdFetMtgtnLimX_Ary1D(self), sizeof(Ary1D_u8p8_6));
  (void)memcpy(HiLoadStallLimrStallMotTqCmdFetMtgtnLimY_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_HiLoadStallLimrStallMotTqCmdFetMtgtnLimY_Ary1D(self), sizeof(Ary1D_u8p8_6));
  (void)memcpy(HiLoadStallLimrStallMotTqCmdLimX_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_HiLoadStallLimrStallMotTqCmdLimX_Ary1D(self), sizeof(Ary1D_u8p8_6));
  (void)memcpy(HiLoadStallLimrStallMotTqCmdLimY_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_HiLoadStallLimrStallMotTqCmdLimY_Ary1D(self), sizeof(Ary1D_u8p8_6));
  (void)memcpy(HiLoadStallLimrStallMotTqLimSlewRate_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_HiLoadStallLimrStallMotTqLimSlewRate_Ary1D(self), sizeof(Ary1D_f32_2));
  (void)memcpy(MotCtrlPrmEstimnMotBackEmfConSatnX_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_MotCtrlPrmEstimnMotBackEmfConSatnX_Ary1D(self), sizeof(Ary1D_u9p7_16));
  (void)memcpy(MotCtrlPrmEstimnMotBackEmfConSatnY_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_MotCtrlPrmEstimnMotBackEmfConSatnY_Ary1D(self), sizeof(Ary1D_u2p14_16));
  (void)memcpy(MotCtrlPrmEstimnMotCurrDaxInduSatnBilnrSeln_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_MotCtrlPrmEstimnMotCurrDaxInduSatnBilnrSeln_Ary1D(self), sizeof(Ary1D_u9p7_6));
  (void)memcpy(MotCtrlPrmEstimnMotCurrQaxInduSatnX_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_MotCtrlPrmEstimnMotCurrQaxInduSatnX_Ary1D(self), sizeof(Ary1D_u9p7_7));
  (void)memcpy(MotCtrlPrmEstimnMotInduDaxSatnScaY_Ary2D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_MotCtrlPrmEstimnMotInduDaxSatnScaY_Ary2D(self), sizeof(Ary2D_u2p14_6_7));
  (void)memcpy(MotCtrlPrmEstimnMotInduQaxSatnScaY_Ary2D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_MotCtrlPrmEstimnMotInduQaxSatnScaY_Ary2D(self), sizeof(Ary2D_u2p14_6_7));
  (void)memcpy(MotCurrRegCfgMotClsdLoopBwDaxY_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_MotCurrRegCfgMotClsdLoopBwDaxY_Ary1D(self), sizeof(Ary1D_u10p6_4));
  (void)memcpy(MotCurrRegCfgMotClsdLoopBwQaxY_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_MotCurrRegCfgMotClsdLoopBwQaxY_Ary1D(self), sizeof(Ary1D_u10p6_4));
  (void)memcpy(MotCurrRegCfgMotNatFrqDaxY_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_MotCurrRegCfgMotNatFrqDaxY_Ary1D(self), sizeof(Ary1D_u9p7_4));
  (void)memcpy(MotCurrRegCfgMotNatFrqQaxY_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_MotCurrRegCfgMotNatFrqQaxY_Ary1D(self), sizeof(Ary1D_u9p7_4));
  (void)memcpy(MotRefMdlCurrDaxBoostTqScaX_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_MotRefMdlCurrDaxBoostTqScaX_Ary1D(self), sizeof(Ary1D_u4p12_11));
  (void)memcpy(MotRefMdlCurrDaxBoostTqScaY_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_MotRefMdlCurrDaxBoostTqScaY_Ary1D(self), sizeof(Ary1D_u1p15_11));
  (void)memcpy(MotRefMdlCurrDaxQaxRefDelta_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_MotRefMdlCurrDaxQaxRefDelta_Ary1D(self), sizeof(Ary1D_f32_8));
  (void)memcpy(MotRefMdlQuad13VltgSdlX_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_MotRefMdlQuad13VltgSdlX_Ary1D(self), sizeof(Ary1D_u11p5_10));
  (void)memcpy(MotRefMdlQuad13VltgSdlY_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_MotRefMdlQuad13VltgSdlY_Ary1D(self), sizeof(Ary1D_u3p13_10));
  (void)memcpy(MotRefMdlQuad24VltgSdlX_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_MotRefMdlQuad24VltgSdlX_Ary1D(self), sizeof(Ary1D_u11p5_10));
  (void)memcpy(MotRefMdlQuad24VltgSdlY_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_MotRefMdlQuad24VltgSdlY_Ary1D(self), sizeof(Ary1D_u3p13_10));
  (void)memcpy(PwrLimrMotEnvlpX_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_PwrLimrMotEnvlpX_Ary1D(self), sizeof(Ary1D_s11p4_14));
  (void)memcpy(PwrLimrMotEnvlpY_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_PwrLimrMotEnvlpY_Ary1D(self), sizeof(Ary1D_u5p11_14));
  (void)memcpy(PwrLimrStdOperMotEnvlpX_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_PwrLimrStdOperMotEnvlpX_Ary1D(self), sizeof(Ary1D_u11p5_6));
  (void)memcpy(PwrLimrStdOperMotEnvlpY_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_PwrLimrStdOperMotEnvlpY_Ary1D(self), sizeof(Ary1D_u4p12_6));
  (void)memcpy(PwrLimrVltgDptMotVelOffsX_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_PwrLimrVltgDptMotVelOffsX_Ary1D(self), sizeof(Ary1D_u5p11_10));
  (void)memcpy(PwrLimrVltgDptMotVelOffsY_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_PwrLimrVltgDptMotVelOffsY_Ary1D(self), sizeof(Ary1D_u11p5_10));
  (void)memcpy(TEstimnAmbPwrMplr_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_TEstimnAmbPwrMplr_Ary1D(self), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnAmbTSca_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_TEstimnAmbTSca_Ary1D(self), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnAssiMechAmbMplr_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_TEstimnAssiMechAmbMplr_Ary1D(self), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnAssiMechCorrLim_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_TEstimnAssiMechCorrLim_Ary1D(self), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnAssiMechDampgSca_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_TEstimnAssiMechDampgSca_Ary1D(self), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnAssiMechDftT_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_TEstimnAssiMechDftT_Ary1D(self), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnAssiMechLLFilCoeffA1_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_TEstimnAssiMechLLFilCoeffA1_Ary1D(self), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnAssiMechLLFilCoeffB0_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_TEstimnAssiMechLLFilCoeffB0_Ary1D(self), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnAssiMechLLFilCoeffB1_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_TEstimnAssiMechLLFilCoeffB1_Ary1D(self), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnAssiMechSlew_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_TEstimnAssiMechSlew_Ary1D(self), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnCorrnTAssiMech_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_TEstimnCorrnTAssiMech_Ary1D(self), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnCorrnTCu_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_TEstimnCorrnTCu_Ary1D(self), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnCorrnTMag_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_TEstimnCorrnTMag_Ary1D(self), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnCorrnTSi_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_TEstimnCorrnTSi_Ary1D(self), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnCuAmbMplr_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_TEstimnCuAmbMplr_Ary1D(self), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnCuCorrnLim_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_TEstimnCuCorrnLim_Ary1D(self), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnCuLLFilCoeffA1_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_TEstimnCuLLFilCoeffA1_Ary1D(self), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnCuLLFilCoeffB0_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_TEstimnCuLLFilCoeffB0_Ary1D(self), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnCuLLFilCoeffB1_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_TEstimnCuLLFilCoeffB1_Ary1D(self), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnEngTSca_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_TEstimnEngTSca_Ary1D(self), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnMagAmbMplr_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_TEstimnMagAmbMplr_Ary1D(self), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnMagCorrnLim_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_TEstimnMagCorrnLim_Ary1D(self), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnMagLLFilCoeffA1_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_TEstimnMagLLFilCoeffA1_Ary1D(self), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnMagLLFilCoeffB0_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_TEstimnMagLLFilCoeffB0_Ary1D(self), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnMagLLFilCoeffB1_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_TEstimnMagLLFilCoeffB1_Ary1D(self), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnSiAmbMplr_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_TEstimnSiAmbMplr_Ary1D(self), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnSiCorrnLim_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_TEstimnSiCorrnLim_Ary1D(self), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnSiLLFilCoeffA1_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_TEstimnSiLLFilCoeffA1_Ary1D(self), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnSiLLFilCoeffB0_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_TEstimnSiLLFilCoeffB0_Ary1D(self), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnSiLLFilCoeffB1_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_TEstimnSiLLFilCoeffB1_Ary1D(self), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnTauAssiMech_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_TEstimnTauAssiMech_Ary1D(self), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnTauCu_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_TEstimnTauCu_Ary1D(self), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnTauMag_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_TEstimnTauMag_Ary1D(self), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnTauSi_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_TEstimnTauSi_Ary1D(self), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnWghtAvrgTDi_Ary1D_data, TSC_AAACalRegn01IninOptSetA01_Dummy_Rte_Prm_TEstimnWghtAvrgTDi_Ary1D(self), sizeof(Ary1D_logl_3));


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define AAACalRegn01IninOptSetA01_Dummy_STOP_SEC_CODE
#include "AAACalRegn01IninOptSetA01_Dummy_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


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
