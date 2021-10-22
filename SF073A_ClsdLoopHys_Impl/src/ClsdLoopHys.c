/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  ClsdLoopHys.c
 *        Config:  C:/_S/work/ses_dev_ea4/SF073A_ClsdLoopHys_Impl-z172399/SF073A_ClsdLoopHys_Impl/tools/Component.dpa
 *     SW-C Type:  ClsdLoopHys
 *  Generated at:  Wed Jul 18 10:05:49 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <ClsdLoopHys>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Copyright 2018 Nxtr
 * Nxtr Confidential
 *
 * Module File Name  : ClsdLoopHys.c
 * Module Description: Closed Loop Hysteresis provides a controllable hysteresis shaped torque based on a rack load
 * Project           : CBD
 * Author            : Marek Brykczynski
 **********************************************************************************************************************
 * Version Control:
 * %version:          2 %
 * %derived_by:       z172399 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                             SCR #
 * --------  -------  --------  ----------------------------------------------------------------------------  ---------
 * 05/10/18  1        BrykczyM  The initial version based on the Design 1.0.0                                 EA4#22757
 * 07/18/18  2        BrykczyM  Updated according to the design 2.0.0 including fix for anomaly EA4#24758     EA4#25676
 *********************************************************************************************************************/
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
 *   SInt16 represents integers with a minimum value of -32768 and a maximum value 
 *      of 32767. The order-relation on sint16 is: x < y if y - x is positive.
 *      sint16 has a lexical representation consisting of an optional sign followed
 *      by a finite-length sequence of decimal digits (#x30-#x39). If the sign is
 *      omitted, "+" is assumed. 
 *      
 *      For example: -1, 0, -12678, +10000, 2500
 *
 * u15p1
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * u2p14
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * u4p12
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * u6p10
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * u9p7
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 *********************************************************************************************************************/

#include "Rte_ClsdLoopHys.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/******************************************** File Level Rule Deviations *********************************************/
/* MISRA-C:2004 Rule 16.10 [NXTRDEV 16.10.1]: There is no appropriate action to take on the return value for Rte_Call, Rte_Read, Rte_Write */
/* MISRA-C:2004 Rule 19.1  [NXTRDEV 19.1.1]:  AUTOSAR requires deviation from this rule for Memory Mapping include statements */

/************************************************ Include Statements *************************************************/
#include "NxtrMath.h"
#include "NxtrFixdpt.h"
#include "NxtrIntrpn.h"
#include "ArchGlbPrm.h"

/********************************************* Embedded Local Constants **********************************************/
#define MAXHWTQCMDDAMPG_HWNWTMTR_F32 (10.0F)
#define MINHWTQCMDDAMPG_HWNWTMTR_F32 (-10.0F)
#define ZERO_ULS_F32                 (0.0F)
#define ONE_ULS_F32                  (1.0F)

/*************************************************** Local Macros ****************************************************/
#define PrmClsdLoopHysHwAgQuadBlndX   (*(const Ary1D_u6p10_2 *) Rte_Prm_ClsdLoopHysHwAgQuadBlndX_Ary1D())
#define PrmClsdLoopHysHwAgQuadQlfrX   (*(const Ary1D_u2p14_2 *) Rte_Prm_ClsdLoopHysHwAgQuadQlfrX_Ary1D())
#define PrmClsdLoopHysHwVelQuadBlndX  (*(const Ary1D_u6p10_2 *) Rte_Prm_ClsdLoopHysHwVelQuadBlndX_Ary1D())
#define PrmClsdLoopHysRackFFacX       (*(const Ary1D_u15p1_4 *) Rte_Prm_ClsdLoopHysRackFFacX_Ary1D())
#define PrmSysGlbPrmVehSpdBilnrSeln   (*(const Ary1D_u9p7_12 *) Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D())
#define PrmClsdLoopHysSysFricOffsLimX (*(const Ary1D_u9p7_5  *) Rte_Prm_ClsdLoopHysSysFricOffsLimX_Ary1D())
#define PrmClsdLoopHysSysFricScaX     (*(const Ary1D_s4p11_7 *) Rte_Prm_ClsdLoopHysSysFricScaX_Ary1D())

/********************************************* Local Function Prototypes *********************************************/
static FUNC(float32, ClsdLoopHys_CODE) Interpolate(
        P2CONST(u6p10, AUTOMATIC, ClsdLoopHys_VAR) Y_Tbl_1D,
        CONST(u9p7, AUTOMATIC) VehSpd_Kph_T_u9p7);

 static FUNC(void, ClsdLoopHys_CODE) IntgtrLimCalcn(
         CONST(float32, AUTOMATIC) HwVel_HwRadPerSec_T_f32,
         CONST(float32, AUTOMATIC) HwAg_HwRad_T_f32,
         CONSTP2VAR(float32, AUTOMATIC, ClsdLoopHys_VAR) UpprIngtrLim_Uls_T_f32,
         CONSTP2VAR(float32, AUTOMATIC, ClsdLoopHys_VAR) LwrIngtrLim_Uls_T_f32);

static FUNC(float32, ClsdLoopHys_CODE) CompCalcn1(
        CONST(float32, AUTOMATIC) HwVel_HwRadPerSec_T_f32,
        CONST(float32, AUTOMATIC) HysBasFac_Uls_T_f32,
        CONST(float32, AUTOMATIC) Delta_Uls_T_f32);

static FUNC(float32, ClsdLoopHys_CODE) CompCalcn2(
        CONST(float32, AUTOMATIC) HwVel_HwRadPerSec_T_f32,
        CONST(float32, AUTOMATIC) HysBasFac_Uls_T_f32,
        CONST(float32, AUTOMATIC) Delta_Uls_T_f32);

static FUNC(float32, ClsdLoopHys_CODE) SysFricOffsLimdCalc(
        CONST(u9p7, AUTOMATIC) VehSpd_Kph_T_u9p7,
        VAR(float32, AUTOMATIC) SysFricOffs_HwNwtMtr_T_f32);

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
 * float32: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * s4p11: Integer in interval [-32768...32767]
 * sint16: Integer in interval [-32768...32767] (standard type)
 * u15p1: Integer in interval [0...65535]
 * u2p14: Integer in interval [0...65535]
 * u4p12: Integer in interval [0...65535]
 * u6p10: Integer in interval [0...65535]
 * u9p7: Integer in interval [0...65535]
 * uint16: Integer in interval [0...65535] (standard type)
 *
 * Array Types:
 * ============
 * Ary1D_s4p11_7: Array with 7 element(s) of type s4p11
 * Ary1D_u15p1_4: Array with 4 element(s) of type u15p1
 * Ary1D_u2p14_2: Array with 2 element(s) of type u2p14
 * Ary1D_u2p14_4: Array with 4 element(s) of type u2p14
 * Ary1D_u2p14_7: Array with 7 element(s) of type u2p14
 * Ary1D_u4p12_5: Array with 5 element(s) of type u4p12
 * Ary1D_u6p10_12: Array with 12 element(s) of type u6p10
 * Ary1D_u6p10_2: Array with 2 element(s) of type u6p10
 * Ary1D_u9p7_12: Array with 12 element(s) of type u9p7
 * Ary1D_u9p7_5: Array with 5 element(s) of type u9p7
 * Ary2D_u2p14_12_4: Array with 12 element(s) of type Ary1D_u2p14_4
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   float32 *Rte_Pim_IntgtrSt(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_ClsdLoopHysHwAgBlndFac_Val(void)
 *   float32 Rte_Prm_ClsdLoopHysPolarity_Val(void)
 *   float32 Rte_Prm_ClsdLoopHysSteerInHwAgNegLowrLim_Val(void)
 *   float32 Rte_Prm_ClsdLoopHysSteerInHwAgNegUpprLim_Val(void)
 *   float32 Rte_Prm_ClsdLoopHysSteerInHwAgPosLowrLim_Val(void)
 *   float32 Rte_Prm_ClsdLoopHysSteerInHwAgPosUpprLim_Val(void)
 *   float32 Rte_Prm_ClsdLoopHysSteerOutHwAgNegLowrLim_Val(void)
 *   float32 Rte_Prm_ClsdLoopHysSteerOutHwAgNegUpprLim_Val(void)
 *   float32 Rte_Prm_ClsdLoopHysSteerOutHwAgPosLowrLim_Val(void)
 *   float32 Rte_Prm_ClsdLoopHysSteerOutHwAgPosUpprLim_Val(void)
 *   u6p10 *Rte_Prm_ClsdLoopHysDeltaY_Ary1D(void)
 *     Returnvalue: u6p10* is of type Ary1D_u6p10_12
 *   u6p10 *Rte_Prm_ClsdLoopHysGainY_Ary1D(void)
 *     Returnvalue: u6p10* is of type Ary1D_u6p10_12
 *   u6p10 *Rte_Prm_ClsdLoopHysHwAgQuadBlndX_Ary1D(void)
 *     Returnvalue: u6p10* is of type Ary1D_u6p10_2
 *   u2p14 *Rte_Prm_ClsdLoopHysHwAgQuadBlndY_Ary1D(void)
 *     Returnvalue: u2p14* is of type Ary1D_u2p14_2
 *   u2p14 *Rte_Prm_ClsdLoopHysHwAgQuadQlfrX_Ary1D(void)
 *     Returnvalue: u2p14* is of type Ary1D_u2p14_2
 *   u2p14 *Rte_Prm_ClsdLoopHysHwAgQuadQlfrY_Ary1D(void)
 *     Returnvalue: u2p14* is of type Ary1D_u2p14_2
 *   u6p10 *Rte_Prm_ClsdLoopHysHwVelQuadBlndX_Ary1D(void)
 *     Returnvalue: u6p10* is of type Ary1D_u6p10_2
 *   u2p14 *Rte_Prm_ClsdLoopHysHwVelQuadBlndY_Ary1D(void)
 *     Returnvalue: u2p14* is of type Ary1D_u2p14_2
 *   u15p1 *Rte_Prm_ClsdLoopHysRackFFacX_Ary1D(void)
 *     Returnvalue: u15p1* is of type Ary1D_u15p1_4
 *   u2p14 *Rte_Prm_ClsdLoopHysRackFFacY_Ary2D(void)
 *     Returnvalue: u2p14* is of type Ary2D_u2p14_12_4
 *   u6p10 *Rte_Prm_ClsdLoopHysRhoY_Ary1D(void)
 *     Returnvalue: u6p10* is of type Ary1D_u6p10_12
 *   u9p7 *Rte_Prm_ClsdLoopHysSysFricOffsLimX_Ary1D(void)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_5
 *   u4p12 *Rte_Prm_ClsdLoopHysSysFricOffsLimY_Ary1D(void)
 *     Returnvalue: u4p12* is of type Ary1D_u4p12_5
 *   s4p11 *Rte_Prm_ClsdLoopHysSysFricScaX_Ary1D(void)
 *     Returnvalue: s4p11* is of type Ary1D_s4p11_7
 *   u2p14 *Rte_Prm_ClsdLoopHysSysFricScaY_Ary1D(void)
 *     Returnvalue: u2p14* is of type Ary1D_u2p14_7
 *   u9p7 *Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D(void)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_12
 *
 *********************************************************************************************************************/


#define ClsdLoopHys_START_SEC_CODE
#include "ClsdLoopHys_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ClsdLoopHysInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ClsdLoopHysInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, ClsdLoopHys_CODE) ClsdLoopHysInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: ClsdLoopHysInit1
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ClsdLoopHysPer1
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
 *   Std_ReturnType Rte_Read_HwTqCmdEffort_Val(float32 *data)
 *   Std_ReturnType Rte_Read_HwVel_Val(float32 *data)
 *   Std_ReturnType Rte_Read_RackFEstimd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_SysFricOffs_Val(float32 *data)
 *   Std_ReturnType Rte_Read_VehSpd_Val(float32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_HwTqCmdHys_Val(float32 data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ClsdLoopHysPer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, ClsdLoopHys_CODE) ClsdLoopHysPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: ClsdLoopHysPer1
 *********************************************************************************************************************/

    /* Inputs */
    VAR(float32, AUTOMATIC) HwAg_HwDeg_T_f32;
    VAR(float32, AUTOMATIC) HwTqCmdEffort_HwNwtMtr_T_f32;
    VAR(float32, AUTOMATIC) HwVel_HwRadPerSec_T_f32;
    VAR(float32, AUTOMATIC) RackFEstimd_RackNwt_T_f32;
    VAR(float32, AUTOMATIC) SysFricOffs_HwNwtMtr_T_f32;
    VAR(float32, AUTOMATIC) VehSpd_Kph_T_f32;

    /* Internals */
    VAR(float32, AUTOMATIC) Delta_Uls_T_f32;
    VAR(float32, AUTOMATIC) Rho_Uls_T_f32;
    VAR(float32, AUTOMATIC) HysGain_Uls_T_f32;
    VAR(float32, AUTOMATIC) UpprIngtrLim_Uls_T_f32;
    VAR(float32, AUTOMATIC) LwrIngtrLim_Uls_T_f32;
    VAR(float32, AUTOMATIC) HysBasFacDerivtv_Uls_T_f32;
    VAR(float32, AUTOMATIC) HysBasFac_Uls_T_f32;
    VAR(float32, AUTOMATIC) HysFac_Uls_T_f32;
    VAR(float32, AUTOMATIC) HysFacBlnd_Uls_T_f32;
    VAR(u2p14, AUTOMATIC)   CurrClsdLoopHysRackFFac_Uls_T_u2p14;
    VAR(float32, AUTOMATIC) HwTqHysEffort_HwNwtMtr_T_f32;
    VAR(float32, AUTOMATIC) SysFricOffsLimd_Uls_T_f32;
    VAR(u9p7, AUTOMATIC)    VehSpd_Kph_T_u9p7;

    /* Outputs */
    VAR(float32, AUTOMATIC) HwTqCmdHys_HwNwtMtr_T_f32;

    /* Read inputs */
    (void) Rte_Read_HwAg_Val(&HwAg_HwDeg_T_f32);
    (void) Rte_Read_HwTqCmdEffort_Val(&HwTqCmdEffort_HwNwtMtr_T_f32);
    (void) Rte_Read_HwVel_Val(&HwVel_HwRadPerSec_T_f32);
    (void) Rte_Read_RackFEstimd_Val(&RackFEstimd_RackNwt_T_f32);
    (void) Rte_Read_SysFricOffs_Val(&SysFricOffs_HwNwtMtr_T_f32);
    (void) Rte_Read_VehSpd_Val(&VehSpd_Kph_T_f32);

    VehSpd_Kph_T_u9p7 = FloatToFixd_u16_f32(VehSpd_Kph_T_f32, NXTRFIXDPT_FLOATTOP7_ULS_F32);

    Delta_Uls_T_f32 = Interpolate(
            Rte_Prm_ClsdLoopHysDeltaY_Ary1D(),
            VehSpd_Kph_T_u9p7);

    Rho_Uls_T_f32 = Interpolate(
            Rte_Prm_ClsdLoopHysRhoY_Ary1D(),
            VehSpd_Kph_T_u9p7);

    HysGain_Uls_T_f32 = Interpolate(
            Rte_Prm_ClsdLoopHysGainY_Ary1D(),
            VehSpd_Kph_T_u9p7);

    IntgtrLimCalcn(
            HwVel_HwRadPerSec_T_f32,
            (HwAg_HwDeg_T_f32 * ARCHGLBPRM_PIOVER180_ULS_F32),
            &UpprIngtrLim_Uls_T_f32,
            &LwrIngtrLim_Uls_T_f32);

    /* HysMdl */
    HysBasFac_Uls_T_f32 = *Rte_Pim_IntgtrSt();

    HysBasFacDerivtv_Uls_T_f32 =
            (HwVel_HwRadPerSec_T_f32
            + ( -CompCalcn1(HwVel_HwRadPerSec_T_f32, HysBasFac_Uls_T_f32, Delta_Uls_T_f32))
            + CompCalcn2(HwVel_HwRadPerSec_T_f32, HysBasFac_Uls_T_f32, Delta_Uls_T_f32))
            * Rho_Uls_T_f32;

    /* Intgtr */
    *Rte_Pim_IntgtrSt() = Lim_f32(
            (HysBasFacDerivtv_Uls_T_f32 * ARCHGLBPRM_2MILLISEC_SEC_F32) + *Rte_Pim_IntgtrSt(),
            LwrIngtrLim_Uls_T_f32,
            UpprIngtrLim_Uls_T_f32);

    HysFac_Uls_T_f32 = HysBasFac_Uls_T_f32 * HysGain_Uls_T_f32;

    HysFacBlnd_Uls_T_f32 =
            Min_f32((Abslt_f32_f32(HwAg_HwDeg_T_f32 * ARCHGLBPRM_PIOVER180_ULS_F32) * Rte_Prm_ClsdLoopHysHwAgBlndFac_Val()), Abslt_f32_f32(HysFac_Uls_T_f32))
            * (float32)Sign_s08_f32(HysFac_Uls_T_f32)
            * Rte_Prm_ClsdLoopHysPolarity_Val();

    /* HysEffortSca */
    CurrClsdLoopHysRackFFac_Uls_T_u2p14 = BilnrIntrpnWithRound_u16_u16CmnXu16MplY(
            FloatToFixd_u16_f32(Abslt_f32_f32(VehSpd_Kph_T_f32), NXTRFIXDPT_FLOATTOP7_ULS_F32),
            FloatToFixd_u16_f32(Abslt_f32_f32(RackFEstimd_RackNwt_T_f32), NXTRFIXDPT_FLOATTOP1_ULS_F32),
            Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D(),
            (uint16) TblSize_m(PrmSysGlbPrmVehSpdBilnrSeln),
            Rte_Prm_ClsdLoopHysRackFFacX_Ary1D(),
            Rte_Prm_ClsdLoopHysRackFFacY_Ary2D(),
            (uint16) TblSize_m(PrmClsdLoopHysRackFFacX));

    HwTqHysEffort_HwNwtMtr_T_f32 =
            FixdToFloat_f32_u16(CurrClsdLoopHysRackFFac_Uls_T_u2p14, NXTRFIXDPT_P14TOFLOAT_ULS_F32)
            * Abslt_f32_f32(HwTqCmdEffort_HwNwtMtr_T_f32)
            * HysFacBlnd_Uls_T_f32;

    /* SysFricOffsHandlr */
    SysFricOffsLimd_Uls_T_f32 = SysFricOffsLimdCalc(VehSpd_Kph_T_u9p7, SysFricOffs_HwNwtMtr_T_f32);

    HwTqCmdHys_HwNwtMtr_T_f32 = HwTqHysEffort_HwNwtMtr_T_f32 * SysFricOffsLimd_Uls_T_f32;

    HwTqCmdHys_HwNwtMtr_T_f32 = Lim_f32(
            HwTqCmdHys_HwNwtMtr_T_f32,
            MINHWTQCMDDAMPG_HWNWTMTR_F32,
            MAXHWTQCMDDAMPG_HWNWTMTR_F32);

    /* Write outputs */
    (void) Rte_Write_HwTqCmdHys_Val(HwTqCmdHys_HwNwtMtr_T_f32);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define ClsdLoopHys_STOP_SEC_CODE
#include "ClsdLoopHys_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Name:        Interpolate
 * Description: The unified implementation of a Simulink blocks to calculate Delta, Rho and HysGain
 * Inputs:      Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D()
 *              Y_Tbl_1D
 *              VehSpd_Kph_T_u9p7
 * Outputs:     return value of FixdToFloat_f32_u16
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(float32, ClsdLoopHys_CODE) Interpolate(
        P2CONST(u6p10, AUTOMATIC, ClsdLoopHys_VAR) Y_Tbl_1D,
        CONST(u9p7, AUTOMATIC) VehSpd_Kph_T_u9p7)
{

    /* Internals */
    VAR(u6p10, AUTOMATIC) Result_Uls_T_u16;

    Result_Uls_T_u16 = LnrIntrpn_u16_u16VariXu16VariY(
            Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D(),
            Y_Tbl_1D,
            (uint16) TblSize_m(PrmSysGlbPrmVehSpdBilnrSeln),
            VehSpd_Kph_T_u9p7);

    return FixdToFloat_f32_u16(Result_Uls_T_u16, NXTRFIXDPT_P10TOFLOAT_ULS_F32);

}

/**********************************************************************************************************************
 * Name:        IntgtrLimCalcn
 * Description: The implementation of a Simulink block IntgtrLimCalcn
 * Inputs:      HwVel_HwRadPerSec_T_f32
 *              HwAg_HwRad_T_f32
 * Outputs:     UpprIngtrLim_Uls_T_f32
 *              LwrIngtrLim_Uls_T_f32
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(void, ClsdLoopHys_CODE) IntgtrLimCalcn(
        CONST(float32, AUTOMATIC) HwVel_HwRadPerSec_T_f32,
        CONST(float32, AUTOMATIC) HwAg_HwRad_T_f32,
        CONSTP2VAR(float32, AUTOMATIC, ClsdLoopHys_VAR) UpprIngtrLim_Uls_T_f32,
        CONSTP2VAR(float32, AUTOMATIC, ClsdLoopHys_VAR) LwrIngtrLim_Uls_T_f32)
{

    /* Internals */
    VAR(u2p14, AUTOMATIC) HwVel_HwRadPerSec_T_u2p14;
    VAR(u2p14, AUTOMATIC) HwAg_HwRad_T_u2p14;
    VAR(float32, AUTOMATIC) QuadQlfr_T_Uls_f32;
    VAR(u2p14, AUTOMATIC) QuadQlfr_T_Uls_u2p14;


    HwVel_HwRadPerSec_T_u2p14 = LnrIntrpn_u16_u16VariXu16VariY(
                Rte_Prm_ClsdLoopHysHwVelQuadBlndX_Ary1D(),
                Rte_Prm_ClsdLoopHysHwVelQuadBlndY_Ary1D(),
                (uint16) TblSize_m(PrmClsdLoopHysHwVelQuadBlndX),
                FloatToFixd_u16_f32(Abslt_f32_f32(HwVel_HwRadPerSec_T_f32), NXTRFIXDPT_FLOATTOP10_ULS_F32));

    HwAg_HwRad_T_u2p14 = LnrIntrpn_u16_u16VariXu16VariY(
                Rte_Prm_ClsdLoopHysHwAgQuadBlndX_Ary1D(),
                Rte_Prm_ClsdLoopHysHwAgQuadBlndY_Ary1D(),
                (uint16) TblSize_m(PrmClsdLoopHysHwAgQuadBlndX),
                FloatToFixd_u16_f32(Abslt_f32_f32(HwAg_HwRad_T_f32), NXTRFIXDPT_FLOATTOP10_ULS_F32));

    QuadQlfr_T_Uls_f32 =
            (-(FixdToFloat_f32_u16(HwVel_HwRadPerSec_T_u2p14, NXTRFIXDPT_P14TOFLOAT_ULS_F32) * (float32)Sign_s08_f32(HwVel_HwRadPerSec_T_f32)))
            *(FixdToFloat_f32_u16(HwAg_HwRad_T_u2p14, NXTRFIXDPT_P14TOFLOAT_ULS_F32) * (float32)Sign_s08_f32(HwAg_HwRad_T_f32));


    QuadQlfr_T_Uls_u2p14 = LnrIntrpn_u16_u16VariXu16VariY(
            Rte_Prm_ClsdLoopHysHwAgQuadQlfrX_Ary1D(),
            Rte_Prm_ClsdLoopHysHwAgQuadQlfrY_Ary1D(),
            (uint16) TblSize_m(PrmClsdLoopHysHwAgQuadQlfrX),
            FloatToFixd_u16_f32(Abslt_f32_f32(QuadQlfr_T_Uls_f32), NXTRFIXDPT_FLOATTOP14_ULS_F32));


    QuadQlfr_T_Uls_f32 = (float32)Sign_s08_f32(-QuadQlfr_T_Uls_f32) * FixdToFloat_f32_u16(QuadQlfr_T_Uls_u2p14, NXTRFIXDPT_P14TOFLOAT_ULS_F32);


    if ((QuadQlfr_T_Uls_f32 <= ZERO_ULS_F32)
        && (HwAg_HwRad_T_f32 > ZERO_ULS_F32))
    {
        /* Steer In HwAg Positive */
        *UpprIngtrLim_Uls_T_f32 = Rte_Prm_ClsdLoopHysSteerInHwAgPosUpprLim_Val();
        *LwrIngtrLim_Uls_T_f32 = Rte_Prm_ClsdLoopHysSteerInHwAgPosLowrLim_Val();

    }
    else if (QuadQlfr_T_Uls_f32 <= ZERO_ULS_F32)
    {
        /* Steer In HwAg Negative */
        *UpprIngtrLim_Uls_T_f32 = Rte_Prm_ClsdLoopHysSteerInHwAgNegUpprLim_Val();
        *LwrIngtrLim_Uls_T_f32 = Rte_Prm_ClsdLoopHysSteerInHwAgNegLowrLim_Val();

    }
    else if (HwAg_HwRad_T_f32 > ZERO_ULS_F32)
    {
        /* Steer Out HwAg Positive */
        *UpprIngtrLim_Uls_T_f32 = Rte_Prm_ClsdLoopHysSteerOutHwAgPosUpprLim_Val();
        *LwrIngtrLim_Uls_T_f32 = Rte_Prm_ClsdLoopHysSteerOutHwAgPosLowrLim_Val();

    }
    else
    {
        /* Steer Out HwAg Negative */
        *UpprIngtrLim_Uls_T_f32 = Rte_Prm_ClsdLoopHysSteerOutHwAgNegUpprLim_Val();
        *LwrIngtrLim_Uls_T_f32 = Rte_Prm_ClsdLoopHysSteerOutHwAgNegLowrLim_Val();
    }

}

/**********************************************************************************************************************
 * Name:        CompCalcn1
 * Description: The implementation of a Simulink block CompCalcn1
 * Inputs:      HwVel_HwRadPerSec_T_f32
 *              HysBasFac_Uls_T_f32
 *              Delta_Uls_T_f32
 * Outputs:     Result_T_Uls_f32
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(float32, ClsdLoopHys_CODE) CompCalcn1(
        CONST(float32, AUTOMATIC) HwVel_HwRadPerSec_T_f32,
        CONST(float32, AUTOMATIC) HysBasFac_Uls_T_f32,
        CONST(float32, AUTOMATIC) Delta_Uls_T_f32)
{
    VAR(float32, AUTOMATIC) Result_T_Uls_f32;

    Result_T_Uls_f32 =
            (HysBasFac_Uls_T_f32)
            * Abslt_f32_f32(HysBasFac_Uls_T_f32)
            * Abslt_f32_f32(HwVel_HwRadPerSec_T_f32)
            * (Delta_Uls_T_f32);

    return Result_T_Uls_f32;
}

/**********************************************************************************************************************
 * Name:        CompCalcn2
 * Description: The implementation of a Simulink block CompCalcn2
 * Inputs:      HwVel_HwRadPerSec_T_f32
 *              HysBasFac_Uls_T_f32
 *              Delta_Uls_T_f32
 * Outputs:     Result_T_Uls_f32
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(float32, ClsdLoopHys_CODE) CompCalcn2(
        CONST(float32, AUTOMATIC) HwVel_HwRadPerSec_T_f32,
        CONST(float32, AUTOMATIC) HysBasFac_Uls_T_f32,
        CONST(float32, AUTOMATIC) Delta_Uls_T_f32)
{
    VAR(float32, AUTOMATIC) Result_T_Uls_f32;

    Result_T_Uls_f32 =
            (Abslt_f32_f32(HysBasFac_Uls_T_f32)
            * Abslt_f32_f32(HysBasFac_Uls_T_f32))
            * HwVel_HwRadPerSec_T_f32
            * (Delta_Uls_T_f32 - ONE_ULS_F32);

    return Result_T_Uls_f32;
}

/**********************************************************************************************************************
 * Name:        SysFricOffsLimdCalc
 * Description: The implementation of the Simulink block SysFricOffsLimdCalc
 * Inputs:      VehSpd_Kph_T_u9p7
 *              SysFricOffs_HwNwtMtr_T_f32
 * Outputs:     return value of FixdToFloat_f32_u16
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(float32, ClsdLoopHys_CODE) SysFricOffsLimdCalc(
        CONST(u9p7, AUTOMATIC) VehSpd_Kph_T_u9p7,
        VAR(float32, AUTOMATIC) SysFricOffs_HwNwtMtr_T_f32)
{
    VAR(u2p14, AUTOMATIC) SysFricOffsLimd_Uls_T_u2p14;
    VAR(u4p12, AUTOMATIC)   ResClsdLoopHysSysFricOffsLimY_HwNwtMtr_T_u4p12;
    VAR(float32, AUTOMATIC) ResClsdLoopHysSysFricOffsLimY_HwNwtMtr_T_f32;

    ResClsdLoopHysSysFricOffsLimY_HwNwtMtr_T_u4p12 = LnrIntrpn_u16_u16VariXu16VariY(
            Rte_Prm_ClsdLoopHysSysFricOffsLimX_Ary1D(),
            Rte_Prm_ClsdLoopHysSysFricOffsLimY_Ary1D(),
            (uint16) TblSize_m(PrmClsdLoopHysSysFricOffsLimX),
            VehSpd_Kph_T_u9p7);

    ResClsdLoopHysSysFricOffsLimY_HwNwtMtr_T_f32 = Abslt_f32_f32(FixdToFloat_f32_u16(ResClsdLoopHysSysFricOffsLimY_HwNwtMtr_T_u4p12, NXTRFIXDPT_P12TOFLOAT_ULS_F32));

    SysFricOffs_HwNwtMtr_T_f32 = Lim_f32(
            SysFricOffs_HwNwtMtr_T_f32,
            -ResClsdLoopHysSysFricOffsLimY_HwNwtMtr_T_f32,
            ResClsdLoopHysSysFricOffsLimY_HwNwtMtr_T_f32);

    SysFricOffsLimd_Uls_T_u2p14 = LnrIntrpn_u16_s16VariXu16VariY(
            Rte_Prm_ClsdLoopHysSysFricScaX_Ary1D(),
            Rte_Prm_ClsdLoopHysSysFricScaY_Ary1D(),
            (uint16) TblSize_m(PrmClsdLoopHysSysFricScaX),
            FloatToFixd_s16_f32(SysFricOffs_HwNwtMtr_T_f32, NXTRFIXDPT_FLOATTOP11_ULS_F32));

    return FixdToFloat_f32_u16(SysFricOffsLimd_Uls_T_u2p14, NXTRFIXDPT_P14TOFLOAT_ULS_F32);
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
