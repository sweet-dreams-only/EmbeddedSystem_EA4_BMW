/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  PosnTrakgServo.c
 *        Config:  EPS.dpa
 *     SW-C Type:  PosnTrakgServo
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <PosnTrakgServo>
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
 * s4p11
 *   
 *
 * s8p7
 *   
 *
 * u11p5
 *   
 *
 * u12p4
 *   
 *
 * u15p1
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

#include "Rte_PosnTrakgServo.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_PosnTrakgServo.h"


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
 * s4p11: Integer in interval [-32768...32767]
 * s8p7: Integer in interval [-32768...32767]
 * sint16: Integer in interval [-32768...32767] (standard type)
 * u11p5: Integer in interval [0...65535]
 * u12p4: Integer in interval [0...65535]
 * u15p1: Integer in interval [0...65535]
 * u2p14: Integer in interval [0...65535]
 * u8p8: Integer in interval [0...65535]
 * u9p7: Integer in interval [0...65535]
 * uint16: Integer in interval [0...65535] (standard type)
 *
 * Array Types:
 * ============
 * Ary1D_s4p11_12: Array with 12 element(s) of type s4p11
 * Ary1D_s8p7_12: Array with 12 element(s) of type s8p7
 * Ary1D_u11p5_12: Array with 12 element(s) of type u11p5
 * Ary1D_u12p4_12: Array with 12 element(s) of type u12p4
 * Ary1D_u15p1_12: Array with 12 element(s) of type u15p1
 * Ary1D_u2p14_10: Array with 10 element(s) of type u2p14
 * Ary1D_u2p14_12: Array with 12 element(s) of type u2p14
 * Ary1D_u8p8_10: Array with 10 element(s) of type u8p8
 * Ary1D_u8p8_12: Array with 12 element(s) of type u8p8
 * Ary1D_u9p7_12: Array with 12 element(s) of type u9p7
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   float32 *Rte_Pim_AntiWdupCmdPrev(void)
 *   float32 *Rte_Pim_HwTqDerivtvPrev(void)
 *   float32 *Rte_Pim_HwTqPrev(void)
 *   float32 *Rte_Pim_IntgtrInpPrev(void)
 *   float32 *Rte_Pim_IntgtrOutpPrev(void)
 *   float32 *Rte_Pim_OutpAntiWdupCmdPrev(void)
 *   float32 *Rte_Pim_PosnServoCmdInpArbnFltMtgtnPrev(void)
 *   float32 *Rte_Pim_PosnServoCmdOutpArbnFltMtgtnPrev(void)
 *   float32 *Rte_Pim_PosnServoEnaTiPrev(void)
 *   float32 *Rte_Pim_PosnServoHwAgValRateLim(void)
 *   float32 *Rte_Pim_PosnServoHwVelValRateLim(void)
 *   float32 *Rte_Pim_dPosnTrakgServoCmdPreLimd(void)
 *   float32 *Rte_Pim_dPosnTrakgServoEnaBlndFac(void)
 *   float32 *Rte_Pim_dPosnTrakgServoFfCmd(void)
 *   float32 *Rte_Pim_dPosnTrakgServoHwAg(void)
 *   float32 *Rte_Pim_dPosnTrakgServoHwAgErr(void)
 *   float32 *Rte_Pim_dPosnTrakgServoHwAgTarLimd(void)
 *   float32 *Rte_Pim_dPosnTrakgServoHwVelTarLimd(void)
 *   float32 *Rte_Pim_dPosnTrakgServoIntgtrCmdLimd(void)
 *   float32 *Rte_Pim_dPosnTrakgServoPtlStFbCmd(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_PosnTrakgServoArbnFltMtgtnLpFilCutOffFrq_Val(void)
 *   float32 Rte_Prm_PosnTrakgServoIntgtrAntiWdupGain_Val(void)
 *   float32 Rte_Prm_PosnTrakgServoIntgtrStCorrnGain_Val(void)
 *   float32 Rte_Prm_PosnTrakgServoLpFilCutOffFrq_Val(void)
 *   float32 Rte_Prm_PosnTrakgServoOutpAntiWdupGain_Val(void)
 *   float32 Rte_Prm_SysGlbPrmSysKineRat_Val(void)
 *   float32 Rte_Prm_SysGlbPrmSysTqRat_Val(void)
 *   u8p8 *Rte_Prm_PosnTrakgServoEnaBlndFacTblX_Ary1D(void)
 *     Returnvalue: u8p8* is of type Ary1D_u8p8_10
 *   u2p14 *Rte_Prm_PosnTrakgServoEnaBlndFacTblY_Ary1D(void)
 *     Returnvalue: u2p14* is of type Ary1D_u2p14_10
 *   u12p4 *Rte_Prm_PosnTrakgServoFfGain_Ary1D(void)
 *     Returnvalue: u12p4* is of type Ary1D_u12p4_12
 *   u8p8 *Rte_Prm_PosnTrakgServoFfVelGain_Ary1D(void)
 *     Returnvalue: u8p8* is of type Ary1D_u8p8_12
 *   u12p4 *Rte_Prm_PosnTrakgServoGain1_Ary1D(void)
 *     Returnvalue: u12p4* is of type Ary1D_u12p4_12
 *   u8p8 *Rte_Prm_PosnTrakgServoGain2_Ary1D(void)
 *     Returnvalue: u8p8* is of type Ary1D_u8p8_12
 *   s8p7 *Rte_Prm_PosnTrakgServoGain3_Ary1D(void)
 *     Returnvalue: s8p7* is of type Ary1D_s8p7_12
 *   s4p11 *Rte_Prm_PosnTrakgServoGain4_Ary1D(void)
 *     Returnvalue: s4p11* is of type Ary1D_s4p11_12
 *   u2p14 *Rte_Prm_PosnTrakgServoGainArbnFltMtgtn_Ary1D(void)
 *     Returnvalue: u2p14* is of type Ary1D_u2p14_12
 *   u11p5 *Rte_Prm_PosnTrakgServoHwAgTarMgnLimTblY_Ary1D(void)
 *     Returnvalue: u11p5* is of type Ary1D_u11p5_12
 *   u15p1 *Rte_Prm_PosnTrakgServoHwAgTarRateLimTblY_Ary1D(void)
 *     Returnvalue: u15p1* is of type Ary1D_u15p1_12
 *   u15p1 *Rte_Prm_PosnTrakgServoHwVelTarRateLimTblY_Ary1D(void)
 *     Returnvalue: u15p1* is of type Ary1D_u15p1_12
 *   u15p1 *Rte_Prm_PosnTrakgServoIntglGain_Ary1D(void)
 *     Returnvalue: u15p1* is of type Ary1D_u15p1_12
 *   u15p1 *Rte_Prm_PosnTrakgServoIntglLim_Ary1D(void)
 *     Returnvalue: u15p1* is of type Ary1D_u15p1_12
 *   u8p8 *Rte_Prm_PosnTrakgServoOutpLim_Ary1D(void)
 *     Returnvalue: u8p8* is of type Ary1D_u8p8_12
 *   u9p7 *Rte_Prm_PosnTrakgServoVehSpdTbl_Ary1D(void)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_12
 *
 *********************************************************************************************************************/


#define PosnTrakgServo_START_SEC_CODE
#include "PosnTrakgServo_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PosnTrakgServoInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: PosnTrakgServoInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, PosnTrakgServo_CODE) PosnTrakgServoInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: PosnTrakgServoInit1
 *********************************************************************************************************************/

  float32 PimAntiWdupCmdPrev;
  float32 PimHwTqDerivtvPrev;
  float32 PimHwTqPrev;
  float32 PimIntgtrInpPrev;
  float32 PimIntgtrOutpPrev;
  float32 PimOutpAntiWdupCmdPrev;
  float32 PimPosnServoCmdInpArbnFltMtgtnPrev;
  float32 PimPosnServoCmdOutpArbnFltMtgtnPrev;
  float32 PimPosnServoEnaTiPrev;
  float32 PimPosnServoHwAgValRateLim;
  float32 PimPosnServoHwVelValRateLim;
  float32 PimdPosnTrakgServoCmdPreLimd;
  float32 PimdPosnTrakgServoEnaBlndFac;
  float32 PimdPosnTrakgServoFfCmd;
  float32 PimdPosnTrakgServoHwAg;
  float32 PimdPosnTrakgServoHwAgErr;
  float32 PimdPosnTrakgServoHwAgTarLimd;
  float32 PimdPosnTrakgServoHwVelTarLimd;
  float32 PimdPosnTrakgServoIntgtrCmdLimd;
  float32 PimdPosnTrakgServoPtlStFbCmd;

  float32 PosnTrakgServoArbnFltMtgtnLpFilCutOffFrq_Val_data;
  float32 PosnTrakgServoIntgtrAntiWdupGain_Val_data;
  float32 PosnTrakgServoIntgtrStCorrnGain_Val_data;
  float32 PosnTrakgServoLpFilCutOffFrq_Val_data;
  float32 PosnTrakgServoOutpAntiWdupGain_Val_data;
  float32 SysGlbPrmSysKineRat_Val_data;
  float32 SysGlbPrmSysTqRat_Val_data;
  Ary1D_u8p8_10 PosnTrakgServoEnaBlndFacTblX_Ary1D_data;
  Ary1D_u2p14_10 PosnTrakgServoEnaBlndFacTblY_Ary1D_data;
  Ary1D_u12p4_12 PosnTrakgServoFfGain_Ary1D_data;
  Ary1D_u8p8_12 PosnTrakgServoFfVelGain_Ary1D_data;
  Ary1D_u12p4_12 PosnTrakgServoGain1_Ary1D_data;
  Ary1D_u8p8_12 PosnTrakgServoGain2_Ary1D_data;
  Ary1D_s8p7_12 PosnTrakgServoGain3_Ary1D_data;
  Ary1D_s4p11_12 PosnTrakgServoGain4_Ary1D_data;
  Ary1D_u2p14_12 PosnTrakgServoGainArbnFltMtgtn_Ary1D_data;
  Ary1D_u11p5_12 PosnTrakgServoHwAgTarMgnLimTblY_Ary1D_data;
  Ary1D_u15p1_12 PosnTrakgServoHwAgTarRateLimTblY_Ary1D_data;
  Ary1D_u15p1_12 PosnTrakgServoHwVelTarRateLimTblY_Ary1D_data;
  Ary1D_u15p1_12 PosnTrakgServoIntglGain_Ary1D_data;
  Ary1D_u15p1_12 PosnTrakgServoIntglLim_Ary1D_data;
  Ary1D_u8p8_12 PosnTrakgServoOutpLim_Ary1D_data;
  Ary1D_u9p7_12 PosnTrakgServoVehSpdTbl_Ary1D_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimAntiWdupCmdPrev = *TSC_PosnTrakgServo_Rte_Pim_AntiWdupCmdPrev();
  *TSC_PosnTrakgServo_Rte_Pim_AntiWdupCmdPrev() = PimAntiWdupCmdPrev;
  PimHwTqDerivtvPrev = *TSC_PosnTrakgServo_Rte_Pim_HwTqDerivtvPrev();
  *TSC_PosnTrakgServo_Rte_Pim_HwTqDerivtvPrev() = PimHwTqDerivtvPrev;
  PimHwTqPrev = *TSC_PosnTrakgServo_Rte_Pim_HwTqPrev();
  *TSC_PosnTrakgServo_Rte_Pim_HwTqPrev() = PimHwTqPrev;
  PimIntgtrInpPrev = *TSC_PosnTrakgServo_Rte_Pim_IntgtrInpPrev();
  *TSC_PosnTrakgServo_Rte_Pim_IntgtrInpPrev() = PimIntgtrInpPrev;
  PimIntgtrOutpPrev = *TSC_PosnTrakgServo_Rte_Pim_IntgtrOutpPrev();
  *TSC_PosnTrakgServo_Rte_Pim_IntgtrOutpPrev() = PimIntgtrOutpPrev;
  PimOutpAntiWdupCmdPrev = *TSC_PosnTrakgServo_Rte_Pim_OutpAntiWdupCmdPrev();
  *TSC_PosnTrakgServo_Rte_Pim_OutpAntiWdupCmdPrev() = PimOutpAntiWdupCmdPrev;
  PimPosnServoCmdInpArbnFltMtgtnPrev = *TSC_PosnTrakgServo_Rte_Pim_PosnServoCmdInpArbnFltMtgtnPrev();
  *TSC_PosnTrakgServo_Rte_Pim_PosnServoCmdInpArbnFltMtgtnPrev() = PimPosnServoCmdInpArbnFltMtgtnPrev;
  PimPosnServoCmdOutpArbnFltMtgtnPrev = *TSC_PosnTrakgServo_Rte_Pim_PosnServoCmdOutpArbnFltMtgtnPrev();
  *TSC_PosnTrakgServo_Rte_Pim_PosnServoCmdOutpArbnFltMtgtnPrev() = PimPosnServoCmdOutpArbnFltMtgtnPrev;
  PimPosnServoEnaTiPrev = *TSC_PosnTrakgServo_Rte_Pim_PosnServoEnaTiPrev();
  *TSC_PosnTrakgServo_Rte_Pim_PosnServoEnaTiPrev() = PimPosnServoEnaTiPrev;
  PimPosnServoHwAgValRateLim = *TSC_PosnTrakgServo_Rte_Pim_PosnServoHwAgValRateLim();
  *TSC_PosnTrakgServo_Rte_Pim_PosnServoHwAgValRateLim() = PimPosnServoHwAgValRateLim;
  PimPosnServoHwVelValRateLim = *TSC_PosnTrakgServo_Rte_Pim_PosnServoHwVelValRateLim();
  *TSC_PosnTrakgServo_Rte_Pim_PosnServoHwVelValRateLim() = PimPosnServoHwVelValRateLim;
  PimdPosnTrakgServoCmdPreLimd = *TSC_PosnTrakgServo_Rte_Pim_dPosnTrakgServoCmdPreLimd();
  *TSC_PosnTrakgServo_Rte_Pim_dPosnTrakgServoCmdPreLimd() = PimdPosnTrakgServoCmdPreLimd;
  PimdPosnTrakgServoEnaBlndFac = *TSC_PosnTrakgServo_Rte_Pim_dPosnTrakgServoEnaBlndFac();
  *TSC_PosnTrakgServo_Rte_Pim_dPosnTrakgServoEnaBlndFac() = PimdPosnTrakgServoEnaBlndFac;
  PimdPosnTrakgServoFfCmd = *TSC_PosnTrakgServo_Rte_Pim_dPosnTrakgServoFfCmd();
  *TSC_PosnTrakgServo_Rte_Pim_dPosnTrakgServoFfCmd() = PimdPosnTrakgServoFfCmd;
  PimdPosnTrakgServoHwAg = *TSC_PosnTrakgServo_Rte_Pim_dPosnTrakgServoHwAg();
  *TSC_PosnTrakgServo_Rte_Pim_dPosnTrakgServoHwAg() = PimdPosnTrakgServoHwAg;
  PimdPosnTrakgServoHwAgErr = *TSC_PosnTrakgServo_Rte_Pim_dPosnTrakgServoHwAgErr();
  *TSC_PosnTrakgServo_Rte_Pim_dPosnTrakgServoHwAgErr() = PimdPosnTrakgServoHwAgErr;
  PimdPosnTrakgServoHwAgTarLimd = *TSC_PosnTrakgServo_Rte_Pim_dPosnTrakgServoHwAgTarLimd();
  *TSC_PosnTrakgServo_Rte_Pim_dPosnTrakgServoHwAgTarLimd() = PimdPosnTrakgServoHwAgTarLimd;
  PimdPosnTrakgServoHwVelTarLimd = *TSC_PosnTrakgServo_Rte_Pim_dPosnTrakgServoHwVelTarLimd();
  *TSC_PosnTrakgServo_Rte_Pim_dPosnTrakgServoHwVelTarLimd() = PimdPosnTrakgServoHwVelTarLimd;
  PimdPosnTrakgServoIntgtrCmdLimd = *TSC_PosnTrakgServo_Rte_Pim_dPosnTrakgServoIntgtrCmdLimd();
  *TSC_PosnTrakgServo_Rte_Pim_dPosnTrakgServoIntgtrCmdLimd() = PimdPosnTrakgServoIntgtrCmdLimd;
  PimdPosnTrakgServoPtlStFbCmd = *TSC_PosnTrakgServo_Rte_Pim_dPosnTrakgServoPtlStFbCmd();
  *TSC_PosnTrakgServo_Rte_Pim_dPosnTrakgServoPtlStFbCmd() = PimdPosnTrakgServoPtlStFbCmd;

  PosnTrakgServoArbnFltMtgtnLpFilCutOffFrq_Val_data = TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoArbnFltMtgtnLpFilCutOffFrq_Val();
  PosnTrakgServoIntgtrAntiWdupGain_Val_data = TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoIntgtrAntiWdupGain_Val();
  PosnTrakgServoIntgtrStCorrnGain_Val_data = TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoIntgtrStCorrnGain_Val();
  PosnTrakgServoLpFilCutOffFrq_Val_data = TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoLpFilCutOffFrq_Val();
  PosnTrakgServoOutpAntiWdupGain_Val_data = TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoOutpAntiWdupGain_Val();
  SysGlbPrmSysKineRat_Val_data = TSC_PosnTrakgServo_Rte_Prm_SysGlbPrmSysKineRat_Val();
  SysGlbPrmSysTqRat_Val_data = TSC_PosnTrakgServo_Rte_Prm_SysGlbPrmSysTqRat_Val();
  (void)memcpy(PosnTrakgServoEnaBlndFacTblX_Ary1D_data, TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoEnaBlndFacTblX_Ary1D(), sizeof(Ary1D_u8p8_10));
  (void)memcpy(PosnTrakgServoEnaBlndFacTblY_Ary1D_data, TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoEnaBlndFacTblY_Ary1D(), sizeof(Ary1D_u2p14_10));
  (void)memcpy(PosnTrakgServoFfGain_Ary1D_data, TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoFfGain_Ary1D(), sizeof(Ary1D_u12p4_12));
  (void)memcpy(PosnTrakgServoFfVelGain_Ary1D_data, TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoFfVelGain_Ary1D(), sizeof(Ary1D_u8p8_12));
  (void)memcpy(PosnTrakgServoGain1_Ary1D_data, TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoGain1_Ary1D(), sizeof(Ary1D_u12p4_12));
  (void)memcpy(PosnTrakgServoGain2_Ary1D_data, TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoGain2_Ary1D(), sizeof(Ary1D_u8p8_12));
  (void)memcpy(PosnTrakgServoGain3_Ary1D_data, TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoGain3_Ary1D(), sizeof(Ary1D_s8p7_12));
  (void)memcpy(PosnTrakgServoGain4_Ary1D_data, TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoGain4_Ary1D(), sizeof(Ary1D_s4p11_12));
  (void)memcpy(PosnTrakgServoGainArbnFltMtgtn_Ary1D_data, TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoGainArbnFltMtgtn_Ary1D(), sizeof(Ary1D_u2p14_12));
  (void)memcpy(PosnTrakgServoHwAgTarMgnLimTblY_Ary1D_data, TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoHwAgTarMgnLimTblY_Ary1D(), sizeof(Ary1D_u11p5_12));
  (void)memcpy(PosnTrakgServoHwAgTarRateLimTblY_Ary1D_data, TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoHwAgTarRateLimTblY_Ary1D(), sizeof(Ary1D_u15p1_12));
  (void)memcpy(PosnTrakgServoHwVelTarRateLimTblY_Ary1D_data, TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoHwVelTarRateLimTblY_Ary1D(), sizeof(Ary1D_u15p1_12));
  (void)memcpy(PosnTrakgServoIntglGain_Ary1D_data, TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoIntglGain_Ary1D(), sizeof(Ary1D_u15p1_12));
  (void)memcpy(PosnTrakgServoIntglLim_Ary1D_data, TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoIntglLim_Ary1D(), sizeof(Ary1D_u15p1_12));
  (void)memcpy(PosnTrakgServoOutpLim_Ary1D_data, TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoOutpLim_Ary1D(), sizeof(Ary1D_u8p8_12));
  (void)memcpy(PosnTrakgServoVehSpdTbl_Ary1D_data, TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoVehSpdTbl_Ary1D(), sizeof(Ary1D_u9p7_12));


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PosnTrakgServoPer1
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
 *   Std_ReturnType Rte_Read_HwAg_Val(float32 *data)
 *   Std_ReturnType Rte_Read_HwTq_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotVelCrf_Val(float32 *data)
 *   Std_ReturnType Rte_Read_PosnServoEna_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_PosnServoHwAg_Val(float32 *data)
 *   Std_ReturnType Rte_Read_PosnServoHwVel_Val(float32 *data)
 *   Std_ReturnType Rte_Read_PosnServoIntgtrOffs_Val(float32 *data)
 *   Std_ReturnType Rte_Read_PosnTrakgArbnFltMtgtnEna_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_VehSpd_Val(float32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_PosnServoCmd_Val(float32 data)
 *   Std_ReturnType Rte_Write_PosnServoIntgtrSt_Val(float32 data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: PosnTrakgServoPer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, PosnTrakgServo_CODE) PosnTrakgServoPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: PosnTrakgServoPer1
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  float32 Read_HwAg_Val;
  float32 Read_HwTq_Val;
  float32 Read_MotVelCrf_Val;
  boolean Read_PosnServoEna_Logl;
  float32 Read_PosnServoHwAg_Val;
  float32 Read_PosnServoHwVel_Val;
  float32 Read_PosnServoIntgtrOffs_Val;
  boolean Read_PosnTrakgArbnFltMtgtnEna_Logl;
  float32 Read_VehSpd_Val;

  float32 PimAntiWdupCmdPrev;
  float32 PimHwTqDerivtvPrev;
  float32 PimHwTqPrev;
  float32 PimIntgtrInpPrev;
  float32 PimIntgtrOutpPrev;
  float32 PimOutpAntiWdupCmdPrev;
  float32 PimPosnServoCmdInpArbnFltMtgtnPrev;
  float32 PimPosnServoCmdOutpArbnFltMtgtnPrev;
  float32 PimPosnServoEnaTiPrev;
  float32 PimPosnServoHwAgValRateLim;
  float32 PimPosnServoHwVelValRateLim;
  float32 PimdPosnTrakgServoCmdPreLimd;
  float32 PimdPosnTrakgServoEnaBlndFac;
  float32 PimdPosnTrakgServoFfCmd;
  float32 PimdPosnTrakgServoHwAg;
  float32 PimdPosnTrakgServoHwAgErr;
  float32 PimdPosnTrakgServoHwAgTarLimd;
  float32 PimdPosnTrakgServoHwVelTarLimd;
  float32 PimdPosnTrakgServoIntgtrCmdLimd;
  float32 PimdPosnTrakgServoPtlStFbCmd;

  float32 PosnTrakgServoArbnFltMtgtnLpFilCutOffFrq_Val_data;
  float32 PosnTrakgServoIntgtrAntiWdupGain_Val_data;
  float32 PosnTrakgServoIntgtrStCorrnGain_Val_data;
  float32 PosnTrakgServoLpFilCutOffFrq_Val_data;
  float32 PosnTrakgServoOutpAntiWdupGain_Val_data;
  float32 SysGlbPrmSysKineRat_Val_data;
  float32 SysGlbPrmSysTqRat_Val_data;
  Ary1D_u8p8_10 PosnTrakgServoEnaBlndFacTblX_Ary1D_data;
  Ary1D_u2p14_10 PosnTrakgServoEnaBlndFacTblY_Ary1D_data;
  Ary1D_u12p4_12 PosnTrakgServoFfGain_Ary1D_data;
  Ary1D_u8p8_12 PosnTrakgServoFfVelGain_Ary1D_data;
  Ary1D_u12p4_12 PosnTrakgServoGain1_Ary1D_data;
  Ary1D_u8p8_12 PosnTrakgServoGain2_Ary1D_data;
  Ary1D_s8p7_12 PosnTrakgServoGain3_Ary1D_data;
  Ary1D_s4p11_12 PosnTrakgServoGain4_Ary1D_data;
  Ary1D_u2p14_12 PosnTrakgServoGainArbnFltMtgtn_Ary1D_data;
  Ary1D_u11p5_12 PosnTrakgServoHwAgTarMgnLimTblY_Ary1D_data;
  Ary1D_u15p1_12 PosnTrakgServoHwAgTarRateLimTblY_Ary1D_data;
  Ary1D_u15p1_12 PosnTrakgServoHwVelTarRateLimTblY_Ary1D_data;
  Ary1D_u15p1_12 PosnTrakgServoIntglGain_Ary1D_data;
  Ary1D_u15p1_12 PosnTrakgServoIntglLim_Ary1D_data;
  Ary1D_u8p8_12 PosnTrakgServoOutpLim_Ary1D_data;
  Ary1D_u9p7_12 PosnTrakgServoVehSpdTbl_Ary1D_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimAntiWdupCmdPrev = *TSC_PosnTrakgServo_Rte_Pim_AntiWdupCmdPrev();
  *TSC_PosnTrakgServo_Rte_Pim_AntiWdupCmdPrev() = PimAntiWdupCmdPrev;
  PimHwTqDerivtvPrev = *TSC_PosnTrakgServo_Rte_Pim_HwTqDerivtvPrev();
  *TSC_PosnTrakgServo_Rte_Pim_HwTqDerivtvPrev() = PimHwTqDerivtvPrev;
  PimHwTqPrev = *TSC_PosnTrakgServo_Rte_Pim_HwTqPrev();
  *TSC_PosnTrakgServo_Rte_Pim_HwTqPrev() = PimHwTqPrev;
  PimIntgtrInpPrev = *TSC_PosnTrakgServo_Rte_Pim_IntgtrInpPrev();
  *TSC_PosnTrakgServo_Rte_Pim_IntgtrInpPrev() = PimIntgtrInpPrev;
  PimIntgtrOutpPrev = *TSC_PosnTrakgServo_Rte_Pim_IntgtrOutpPrev();
  *TSC_PosnTrakgServo_Rte_Pim_IntgtrOutpPrev() = PimIntgtrOutpPrev;
  PimOutpAntiWdupCmdPrev = *TSC_PosnTrakgServo_Rte_Pim_OutpAntiWdupCmdPrev();
  *TSC_PosnTrakgServo_Rte_Pim_OutpAntiWdupCmdPrev() = PimOutpAntiWdupCmdPrev;
  PimPosnServoCmdInpArbnFltMtgtnPrev = *TSC_PosnTrakgServo_Rte_Pim_PosnServoCmdInpArbnFltMtgtnPrev();
  *TSC_PosnTrakgServo_Rte_Pim_PosnServoCmdInpArbnFltMtgtnPrev() = PimPosnServoCmdInpArbnFltMtgtnPrev;
  PimPosnServoCmdOutpArbnFltMtgtnPrev = *TSC_PosnTrakgServo_Rte_Pim_PosnServoCmdOutpArbnFltMtgtnPrev();
  *TSC_PosnTrakgServo_Rte_Pim_PosnServoCmdOutpArbnFltMtgtnPrev() = PimPosnServoCmdOutpArbnFltMtgtnPrev;
  PimPosnServoEnaTiPrev = *TSC_PosnTrakgServo_Rte_Pim_PosnServoEnaTiPrev();
  *TSC_PosnTrakgServo_Rte_Pim_PosnServoEnaTiPrev() = PimPosnServoEnaTiPrev;
  PimPosnServoHwAgValRateLim = *TSC_PosnTrakgServo_Rte_Pim_PosnServoHwAgValRateLim();
  *TSC_PosnTrakgServo_Rte_Pim_PosnServoHwAgValRateLim() = PimPosnServoHwAgValRateLim;
  PimPosnServoHwVelValRateLim = *TSC_PosnTrakgServo_Rte_Pim_PosnServoHwVelValRateLim();
  *TSC_PosnTrakgServo_Rte_Pim_PosnServoHwVelValRateLim() = PimPosnServoHwVelValRateLim;
  PimdPosnTrakgServoCmdPreLimd = *TSC_PosnTrakgServo_Rte_Pim_dPosnTrakgServoCmdPreLimd();
  *TSC_PosnTrakgServo_Rte_Pim_dPosnTrakgServoCmdPreLimd() = PimdPosnTrakgServoCmdPreLimd;
  PimdPosnTrakgServoEnaBlndFac = *TSC_PosnTrakgServo_Rte_Pim_dPosnTrakgServoEnaBlndFac();
  *TSC_PosnTrakgServo_Rte_Pim_dPosnTrakgServoEnaBlndFac() = PimdPosnTrakgServoEnaBlndFac;
  PimdPosnTrakgServoFfCmd = *TSC_PosnTrakgServo_Rte_Pim_dPosnTrakgServoFfCmd();
  *TSC_PosnTrakgServo_Rte_Pim_dPosnTrakgServoFfCmd() = PimdPosnTrakgServoFfCmd;
  PimdPosnTrakgServoHwAg = *TSC_PosnTrakgServo_Rte_Pim_dPosnTrakgServoHwAg();
  *TSC_PosnTrakgServo_Rte_Pim_dPosnTrakgServoHwAg() = PimdPosnTrakgServoHwAg;
  PimdPosnTrakgServoHwAgErr = *TSC_PosnTrakgServo_Rte_Pim_dPosnTrakgServoHwAgErr();
  *TSC_PosnTrakgServo_Rte_Pim_dPosnTrakgServoHwAgErr() = PimdPosnTrakgServoHwAgErr;
  PimdPosnTrakgServoHwAgTarLimd = *TSC_PosnTrakgServo_Rte_Pim_dPosnTrakgServoHwAgTarLimd();
  *TSC_PosnTrakgServo_Rte_Pim_dPosnTrakgServoHwAgTarLimd() = PimdPosnTrakgServoHwAgTarLimd;
  PimdPosnTrakgServoHwVelTarLimd = *TSC_PosnTrakgServo_Rte_Pim_dPosnTrakgServoHwVelTarLimd();
  *TSC_PosnTrakgServo_Rte_Pim_dPosnTrakgServoHwVelTarLimd() = PimdPosnTrakgServoHwVelTarLimd;
  PimdPosnTrakgServoIntgtrCmdLimd = *TSC_PosnTrakgServo_Rte_Pim_dPosnTrakgServoIntgtrCmdLimd();
  *TSC_PosnTrakgServo_Rte_Pim_dPosnTrakgServoIntgtrCmdLimd() = PimdPosnTrakgServoIntgtrCmdLimd;
  PimdPosnTrakgServoPtlStFbCmd = *TSC_PosnTrakgServo_Rte_Pim_dPosnTrakgServoPtlStFbCmd();
  *TSC_PosnTrakgServo_Rte_Pim_dPosnTrakgServoPtlStFbCmd() = PimdPosnTrakgServoPtlStFbCmd;

  PosnTrakgServoArbnFltMtgtnLpFilCutOffFrq_Val_data = TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoArbnFltMtgtnLpFilCutOffFrq_Val();
  PosnTrakgServoIntgtrAntiWdupGain_Val_data = TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoIntgtrAntiWdupGain_Val();
  PosnTrakgServoIntgtrStCorrnGain_Val_data = TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoIntgtrStCorrnGain_Val();
  PosnTrakgServoLpFilCutOffFrq_Val_data = TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoLpFilCutOffFrq_Val();
  PosnTrakgServoOutpAntiWdupGain_Val_data = TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoOutpAntiWdupGain_Val();
  SysGlbPrmSysKineRat_Val_data = TSC_PosnTrakgServo_Rte_Prm_SysGlbPrmSysKineRat_Val();
  SysGlbPrmSysTqRat_Val_data = TSC_PosnTrakgServo_Rte_Prm_SysGlbPrmSysTqRat_Val();
  (void)memcpy(PosnTrakgServoEnaBlndFacTblX_Ary1D_data, TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoEnaBlndFacTblX_Ary1D(), sizeof(Ary1D_u8p8_10));
  (void)memcpy(PosnTrakgServoEnaBlndFacTblY_Ary1D_data, TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoEnaBlndFacTblY_Ary1D(), sizeof(Ary1D_u2p14_10));
  (void)memcpy(PosnTrakgServoFfGain_Ary1D_data, TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoFfGain_Ary1D(), sizeof(Ary1D_u12p4_12));
  (void)memcpy(PosnTrakgServoFfVelGain_Ary1D_data, TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoFfVelGain_Ary1D(), sizeof(Ary1D_u8p8_12));
  (void)memcpy(PosnTrakgServoGain1_Ary1D_data, TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoGain1_Ary1D(), sizeof(Ary1D_u12p4_12));
  (void)memcpy(PosnTrakgServoGain2_Ary1D_data, TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoGain2_Ary1D(), sizeof(Ary1D_u8p8_12));
  (void)memcpy(PosnTrakgServoGain3_Ary1D_data, TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoGain3_Ary1D(), sizeof(Ary1D_s8p7_12));
  (void)memcpy(PosnTrakgServoGain4_Ary1D_data, TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoGain4_Ary1D(), sizeof(Ary1D_s4p11_12));
  (void)memcpy(PosnTrakgServoGainArbnFltMtgtn_Ary1D_data, TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoGainArbnFltMtgtn_Ary1D(), sizeof(Ary1D_u2p14_12));
  (void)memcpy(PosnTrakgServoHwAgTarMgnLimTblY_Ary1D_data, TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoHwAgTarMgnLimTblY_Ary1D(), sizeof(Ary1D_u11p5_12));
  (void)memcpy(PosnTrakgServoHwAgTarRateLimTblY_Ary1D_data, TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoHwAgTarRateLimTblY_Ary1D(), sizeof(Ary1D_u15p1_12));
  (void)memcpy(PosnTrakgServoHwVelTarRateLimTblY_Ary1D_data, TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoHwVelTarRateLimTblY_Ary1D(), sizeof(Ary1D_u15p1_12));
  (void)memcpy(PosnTrakgServoIntglGain_Ary1D_data, TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoIntglGain_Ary1D(), sizeof(Ary1D_u15p1_12));
  (void)memcpy(PosnTrakgServoIntglLim_Ary1D_data, TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoIntglLim_Ary1D(), sizeof(Ary1D_u15p1_12));
  (void)memcpy(PosnTrakgServoOutpLim_Ary1D_data, TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoOutpLim_Ary1D(), sizeof(Ary1D_u8p8_12));
  (void)memcpy(PosnTrakgServoVehSpdTbl_Ary1D_data, TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoVehSpdTbl_Ary1D(), sizeof(Ary1D_u9p7_12));

  fct_status = TSC_PosnTrakgServo_Rte_Read_HwAg_Val(&Read_HwAg_Val);
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

  fct_status = TSC_PosnTrakgServo_Rte_Read_HwTq_Val(&Read_HwTq_Val);
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

  fct_status = TSC_PosnTrakgServo_Rte_Read_MotVelCrf_Val(&Read_MotVelCrf_Val);
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

  fct_status = TSC_PosnTrakgServo_Rte_Read_PosnServoEna_Logl(&Read_PosnServoEna_Logl);
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

  fct_status = TSC_PosnTrakgServo_Rte_Read_PosnServoHwAg_Val(&Read_PosnServoHwAg_Val);
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

  fct_status = TSC_PosnTrakgServo_Rte_Read_PosnServoHwVel_Val(&Read_PosnServoHwVel_Val);
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

  fct_status = TSC_PosnTrakgServo_Rte_Read_PosnServoIntgtrOffs_Val(&Read_PosnServoIntgtrOffs_Val);
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

  fct_status = TSC_PosnTrakgServo_Rte_Read_PosnTrakgArbnFltMtgtnEna_Logl(&Read_PosnTrakgArbnFltMtgtnEna_Logl);
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

  fct_status = TSC_PosnTrakgServo_Rte_Read_VehSpd_Val(&Read_VehSpd_Val);
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

  fct_status = TSC_PosnTrakgServo_Rte_Write_PosnServoCmd_Val(Rte_InitValue_PosnServoCmd_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_PosnTrakgServo_Rte_Write_PosnServoIntgtrSt_Val(Rte_InitValue_PosnServoIntgtrSt_Val);
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


#define PosnTrakgServo_STOP_SEC_CODE
#include "PosnTrakgServo_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


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
