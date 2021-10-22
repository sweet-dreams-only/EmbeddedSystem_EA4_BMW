/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  BmwTrfcJamAssiDampg.c
 *        Config:  C:/_S/work/ses_dev_ea4/CF011A_BmwTrfcJamAssiDampg_Impl-z172399/CF011A_BmwTrfcJamAssiDampg_Impl/tools/Component.dpa
 *     SW-C Type:  BmwTrfcJamAssiDampg
 *  Generated at:  Tue Apr 17 15:01:17 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <BmwTrfcJamAssiDampg>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Copyright 2018 Nxtr
 * Nxtr Confidential
 *
 * Module File Name  : BmwTrfcJamAssiDampg.c
 * Module Description: The BMW Traffic Jam Assist Damping
 * Project           : CBD
 * Author            : Marek Brykczynski
 **********************************************************************************************************************
 * Version Control:
 * %version:          1 %
 * %derived_by:       z172399 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                             SCR #
 * --------  -------  --------  ----------------------------------------------------------------------------  ---------
 * 04/12/18  1        BrykczyM  The initial version based on the Design 1.0.0                                 EA4#20924
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
 * BmwTrfcJamAssiDampgStReq1
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * BmwTrfcJamAssiSt1
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * u11p5
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
 * u9p7
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 *********************************************************************************************************************/

#include "Rte_BmwTrfcJamAssiDampg.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/******************************************** File Level Rule Deviations *********************************************/
/* MISRA-C:2004 Rule 16.10 [NXTRDEV 16.10.1]: There is no appropriate action to take on the return value for Rte_Call, Rte_Read, Rte_Write */
/* MISRA-C:2004 Rule 19.1  [NXTRDEV 19.1.1]:  AUTOSAR requires deviation from this rule for Memory Mapping include statements */

/************************************************ Include Statements *************************************************/
#include "NxtrMath.h"
#include "NxtrFixdPt.h"
#include "NxtrIntrpn.h"
#include "SysGlbPrm.h"

/********************************************* Embedded Local Constants **********************************************/
#define CNVMILLISECTOCNT_CNTPERMILLISEC_U16 (10U)
#define MINDAMPG_MOTNWTMTR_F32              (0.1F)
#define ONELOOPCNT_CNT_U32                  (20U)
#define ONE_ULS_F32                         (1.0F)
#define ZERO_CNT_U08                        (0U)
#define ZERO_CNT_U32                        (0U)
#define ZERO_MOTNWTMTR_F32                  (0.0F)
#define ZERO_ULS_F32                        (0.0F)

/*************************************************** Local Macros ****************************************************/
#define PrmBmwTrfcJamAssiDampgBasDampgX_Ary1D    (*(const Ary1D_u11p5_10 *)   Rte_Prm_BmwTrfcJamAssiDampgBasDampgX_Ary1D())
#define PrmSysGlbPrmVehSpdBilnrSeln_Ary1D        (*(const Ary1D_u9p7_12 *)    Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D())
#define PrmBmwTrfcJamAssiDampgLimdDampgX_Ary1D   (*(const Ary1D_u4p12_12 *)   Rte_Prm_BmwTrfcJamAssiDampgLimdDampgX_Ary1D())

/********************************************* Local Function Prototypes *********************************************/
static FUNC(BmwTrfcJamAssiSt1, BmwTrfcJamAssiDampg_CODE) CalcnTrfcJamAssiSt(
        CONST(BmwTrfcJamAssiDampgStReq1, AUTOMATIC) BmwTrfcJamAssiDampgStReq_Cnt_T_enum,
        CONST(boolean, AUTOMATIC) BmwTrfcJamAssiDampgScaReqVld_Cnt_T_logl,
        CONST(boolean, AUTOMATIC) BmwTrfcJamAssiDampgStReqVld_Cnt_T_logl);

 static FUNC(boolean, BmwTrfcJamAssiDampg_CODE) ProcessBmwTrfcJamAssiDampgErr(
         CONST(BmwTrfcJamAssiDampgStReq1, AUTOMATIC) BmwTrfcJamAssiDampgStReq_Cnt_T_enum,
         CONST(boolean, AUTOMATIC) BmwTrfcJamAssiDampgScaReqVld_Cnt_T_logl,
         CONST(boolean, AUTOMATIC) BmwTrfcJamAssiDampgStReqVld_Cnt_T_logl);


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
 * u11p5: Integer in interval [0...65535]
 * u4p12: Integer in interval [0...65535]
 * u9p7: Integer in interval [0...65535]
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * BmwTrfcJamAssiDampgStReq1: Enumeration of integer in interval [0...255] with enumerators
 *   BMWTRFCJAMASSIDAMPGSTREQ_DONOTCNVSPADDLDAMPG (1U)
 *   BMWTRFCJAMASSIDAMPGSTREQ_CNVSPADDLDAMPG (2U)
 *   BMWTRFCJAMASSIDAMPGSTREQ_INVLDSIG (15U)
 * BmwTrfcJamAssiSt1: Enumeration of integer in interval [0...255] with enumerators
 *   BMWTRFCJAMASSIST_INACTV (1U)
 *   BMWTRFCJAMASSIST_ACTV (2U)
 *   BMWTRFCJAMASSIST_INVLD (15U)
 *
 * Array Types:
 * ============
 * Ary1D_u11p5_10: Array with 10 element(s) of type u11p5
 * Ary1D_u11p5_12: Array with 12 element(s) of type u11p5
 * Ary1D_u4p12_10: Array with 10 element(s) of type u4p12
 * Ary1D_u4p12_12: Array with 12 element(s) of type u4p12
 * Ary1D_u9p7_12: Array with 12 element(s) of type u9p7
 * Ary2D_u4p12_12_12: Array with 12 element(s) of type Ary1D_u4p12_12
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   float32 *Rte_Pim_BmwTrfcJamAssiDampgScaStVari(void)
 *   uint32 *Rte_Pim_LimExcddFltRefTi(void)
 *   uint8 *Rte_Pim_TmpBmwTrfcJamAssiDampgSt(void)
 *   boolean *Rte_Pim_PrevLimExcddFlt(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_BmwTrfcJamAssiDampgRatThd_Val(void)
 *   float32 Rte_Prm_BmwTrfcJamAssiDampgSlewRateDwnActv_Val(void)
 *   float32 Rte_Prm_BmwTrfcJamAssiDampgSlewRateDwnInactv_Val(void)
 *   float32 Rte_Prm_BmwTrfcJamAssiDampgSlewRateDwnInvld_Val(void)
 *   float32 Rte_Prm_BmwTrfcJamAssiDampgSlewRateUp_Val(void)
 *   uint16 Rte_Prm_BmwTrfcJamAssiDampgLimExcddFltRefTiThd_Val(void)
 *   u11p5 *Rte_Prm_BmwTrfcJamAssiDampgBasDampgX_Ary1D(void)
 *     Returnvalue: u11p5* is of type Ary1D_u11p5_10
 *   u4p12 *Rte_Prm_BmwTrfcJamAssiDampgBasDampgY_Ary1D(void)
 *     Returnvalue: u4p12* is of type Ary1D_u4p12_10
 *   u11p5 *Rte_Prm_BmwTrfcJamAssiDampgLimdDampgX_Ary1D(void)
 *     Returnvalue: u11p5* is of type Ary1D_u11p5_12
 *   u4p12 *Rte_Prm_BmwTrfcJamAssiDampgLimdDampgY_Ary2D(void)
 *     Returnvalue: u4p12* is of type Ary2D_u4p12_12_12
 *   u9p7 *Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D(void)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_12
 *
 *********************************************************************************************************************/


#define BmwTrfcJamAssiDampg_START_SEC_CODE
#include "BmwTrfcJamAssiDampg_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwTrfcJamAssiDampgInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwTrfcJamAssiDampgInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwTrfcJamAssiDampg_CODE) BmwTrfcJamAssiDampgInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwTrfcJamAssiDampgInit1
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwTrfcJamAssiDampgPer1
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
 *   Std_ReturnType Rte_Read_BmwTrfcJamAssiDampgScaReq_Val(float32 *data)
 *   Std_ReturnType Rte_Read_BmwTrfcJamAssiDampgScaReqVld_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_BmwTrfcJamAssiDampgStReq_Val(BmwTrfcJamAssiDampgStReq1 *data)
 *   Std_ReturnType Rte_Read_BmwTrfcJamAssiDampgStReqVld_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_MotVelCrf_Val(float32 *data)
 *   Std_ReturnType Rte_Read_TrfcJamAssiCmdEna_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_VehSpd_Val(float32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_BmwTrfcJamAssiDampgSt_Val(BmwTrfcJamAssiSt1 data)
 *   Std_ReturnType Rte_Write_TrfcJamAssiCmd_Val(float32 data)
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
 * Symbol: BmwTrfcJamAssiDampgPer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwTrfcJamAssiDampg_CODE) BmwTrfcJamAssiDampgPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwTrfcJamAssiDampgPer1
 *********************************************************************************************************************/

    /* Inputs */
    VAR(float32, AUTOMATIC) BmwTrfcJamAssiDampgScaReq_Uls_T_f32;
    VAR(boolean, AUTOMATIC) BmwTrfcJamAssiDampgScaReqVld_Cnt_T_logl;
    VAR(BmwTrfcJamAssiDampgStReq1, AUTOMATIC) BmwTrfcJamAssiDampgStReq_Cnt_T_enum;
    VAR(boolean, AUTOMATIC) BmwTrfcJamAssiDampgStReqVld_Cnt_T_logl;
    VAR(float32, AUTOMATIC) MotVelCrf_MotRadPerSec_T_f32;
    VAR(boolean, AUTOMATIC) TrfcJamAssiCmdEna_Cnt_T_logl;
    VAR(float32, AUTOMATIC) VehSpd_Kph_T_f32;

    /* Internals */
    VAR(float32, AUTOMATIC) BmwTrfcJamAssiDampgSca_Uls_T_f32;
    VAR(float32, AUTOMATIC) SlewRate_UlsPerSec_T_f32;
    VAR(uint16, AUTOMATIC) AbsltMotVelCrf_MotRadPerSec_T_u16;
    VAR(uint16, AUTOMATIC) ScadDampgCmd_MotNwtMtr_T_u16;
    VAR(float32, AUTOMATIC) ScadDampgCmd_MotNwtMtr_T_f32;
    VAR(uint16, AUTOMATIC) ScadDampgHiLim_Cnt_T_u16;
    VAR(float32, AUTOMATIC) LimdDampg_MotNwtMtr_T_f32;
    VAR(float32, AUTOMATIC) OverLimFac_Uls_T_f32;
    VAR(uint32, AUTOMATIC) TiSpan_Cnt_T_u32;

    /* Outputs */
    VAR(BmwTrfcJamAssiSt1, AUTOMATIC) BmwTrfcJamAssiDampgSt_Cnt_T_enum;
    VAR(float32, AUTOMATIC) TrfcJamAssiCmd_MotNwtMtr_T_f32;

    /* Read Inputs */
    (void) Rte_Read_BmwTrfcJamAssiDampgScaReq_Val(&BmwTrfcJamAssiDampgScaReq_Uls_T_f32);
    (void) Rte_Read_BmwTrfcJamAssiDampgScaReqVld_Logl(&BmwTrfcJamAssiDampgScaReqVld_Cnt_T_logl);
    (void) Rte_Read_BmwTrfcJamAssiDampgStReq_Val(&BmwTrfcJamAssiDampgStReq_Cnt_T_enum);
    (void) Rte_Read_BmwTrfcJamAssiDampgStReqVld_Logl(&BmwTrfcJamAssiDampgStReqVld_Cnt_T_logl);
    (void) Rte_Read_MotVelCrf_Val(&MotVelCrf_MotRadPerSec_T_f32);
    (void) Rte_Read_TrfcJamAssiCmdEna_Logl(&TrfcJamAssiCmdEna_Cnt_T_logl);
    (void) Rte_Read_VehSpd_Val(&VehSpd_Kph_T_f32);


    if(TrfcJamAssiCmdEna_Cnt_T_logl != FALSE)
    {
        /* NormMod */
        BmwTrfcJamAssiDampgSt_Cnt_T_enum = CalcnTrfcJamAssiSt(
                BmwTrfcJamAssiDampgStReq_Cnt_T_enum,
                BmwTrfcJamAssiDampgScaReqVld_Cnt_T_logl,
                BmwTrfcJamAssiDampgStReqVld_Cnt_T_logl);


        /* CalcnBmwTrfcJamAssiDampgSca */
        switch(BmwTrfcJamAssiDampgSt_Cnt_T_enum)
        {
            /* Actv */
            case BMWTRFCJAMASSIST_ACTV:
            {
                BmwTrfcJamAssiDampgSca_Uls_T_f32 = BmwTrfcJamAssiDampgScaReq_Uls_T_f32;
                SlewRate_UlsPerSec_T_f32         = Rte_Prm_BmwTrfcJamAssiDampgSlewRateDwnActv_Val();
                break;
            }

            /* Inactv */
            case BMWTRFCJAMASSIST_INACTV:
            {
                BmwTrfcJamAssiDampgSca_Uls_T_f32 = ZERO_ULS_F32;
                SlewRate_UlsPerSec_T_f32         = Rte_Prm_BmwTrfcJamAssiDampgSlewRateDwnInactv_Val();
                break;
            }

            /* Invld */
            default:
            {
                BmwTrfcJamAssiDampgSca_Uls_T_f32 = ZERO_ULS_F32;
                SlewRate_UlsPerSec_T_f32         = Rte_Prm_BmwTrfcJamAssiDampgSlewRateDwnInvld_Val();
                break;
            }

        }


        /* CalcnScadDampg */
        *Rte_Pim_BmwTrfcJamAssiDampgScaStVari() = Lim_f32(
                BmwTrfcJamAssiDampgSca_Uls_T_f32,
                (*Rte_Pim_BmwTrfcJamAssiDampgScaStVari() - (SlewRate_UlsPerSec_T_f32 * ARCHGLBPRM_2MILLISEC_SEC_F32)),
                (*Rte_Pim_BmwTrfcJamAssiDampgScaStVari() + (Rte_Prm_BmwTrfcJamAssiDampgSlewRateUp_Val() * ARCHGLBPRM_2MILLISEC_SEC_F32)));


        AbsltMotVelCrf_MotRadPerSec_T_u16 = FloatToFixd_u16_f32(
                Abslt_f32_f32(MotVelCrf_MotRadPerSec_T_f32),
                NXTRFIXDPT_FLOATTOP5_ULS_F32);

        ScadDampgCmd_MotNwtMtr_T_u16 = LnrIntrpn_u16_u16VariXu16VariY(
                Rte_Prm_BmwTrfcJamAssiDampgBasDampgX_Ary1D(),
                Rte_Prm_BmwTrfcJamAssiDampgBasDampgY_Ary1D(),
                (uint16) TblSize_m(PrmBmwTrfcJamAssiDampgBasDampgX_Ary1D),
                AbsltMotVelCrf_MotRadPerSec_T_u16);

        ScadDampgCmd_MotNwtMtr_T_f32 = FixdToFloat_f32_u16(
                ScadDampgCmd_MotNwtMtr_T_u16,
                NXTRFIXDPT_P12TOFLOAT_ULS_F32);

        ScadDampgCmd_MotNwtMtr_T_f32 *= *Rte_Pim_BmwTrfcJamAssiDampgScaStVari();


        /* CalcnTrfcJamAssiDampgCmd */

        ScadDampgHiLim_Cnt_T_u16 = BilnrIntrpnWithRound_u16_u16CmnXu16MplY(
                    FloatToFixd_u16_f32(VehSpd_Kph_T_f32, NXTRFIXDPT_FLOATTOP7_ULS_F32),
                    AbsltMotVelCrf_MotRadPerSec_T_u16,
                    Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D(),
                    (uint16) TblSize_m(PrmSysGlbPrmVehSpdBilnrSeln_Ary1D),
                    Rte_Prm_BmwTrfcJamAssiDampgLimdDampgX_Ary1D(),
                    Rte_Prm_BmwTrfcJamAssiDampgLimdDampgY_Ary2D(),
                    (uint16) TblSize_m(PrmBmwTrfcJamAssiDampgLimdDampgX_Ary1D));

        LimdDampg_MotNwtMtr_T_f32 = Lim_f32(
                 ScadDampgCmd_MotNwtMtr_T_f32,
                 ZERO_ULS_F32,
                 FixdToFloat_f32_u16(ScadDampgHiLim_Cnt_T_u16, NXTRFIXDPT_P12TOFLOAT_ULS_F32));

        TrfcJamAssiCmd_MotNwtMtr_T_f32 = Lim_f32(
                -(LimdDampg_MotNwtMtr_T_f32 * (float32)Sign_s08_f32(MotVelCrf_MotRadPerSec_T_f32)),
                SYSGLBPRM_MOTTQCMDLOLIM_MOTNWTMTR_F32,
                SYSGLBPRM_MOTTQCMDHILIM_MOTNWTMTR_F32);

        /* CalcnLimFlt */
        if(ScadDampgCmd_MotNwtMtr_T_f32 > MINDAMPG_MOTNWTMTR_F32)
        {
            /* CalcnFac */
            OverLimFac_Uls_T_f32 = LimdDampg_MotNwtMtr_T_f32 / ScadDampgCmd_MotNwtMtr_T_f32;

        }
        else
        {
            /* SetOne */
            OverLimFac_Uls_T_f32 = ONE_ULS_F32;
        }


        if(OverLimFac_Uls_T_f32 <= Rte_Prm_BmwTrfcJamAssiDampgRatThd_Val())
        {
            /* ChkTiAndSetOutp */
            (void)Rte_Call_GetTiSpan100MicroSec32bit_Oper(*Rte_Pim_LimExcddFltRefTi(), &TiSpan_Cnt_T_u32);

            if(TiSpan_Cnt_T_u32 >= ((uint32)Rte_Prm_BmwTrfcJamAssiDampgLimExcddFltRefTiThd_Val() * CNVMILLISECTOCNT_CNTPERMILLISEC_U16))
            {
                *Rte_Pim_PrevLimExcddFlt() = TRUE;
            }

        }
        else
        {
            /* UpdTiAndSetFalse */
            (void)Rte_Call_GetRefTmr100MicroSec32bit_Oper(Rte_Pim_LimExcddFltRefTi());
            *Rte_Pim_LimExcddFltRefTi() += ONELOOPCNT_CNT_U32;
            *Rte_Pim_PrevLimExcddFlt()  = FALSE;
        }


    }
    else
    {
        /* DiMod */
        TrfcJamAssiCmd_MotNwtMtr_T_f32          = ZERO_MOTNWTMTR_F32;
        BmwTrfcJamAssiDampgSt_Cnt_T_enum        = BMWTRFCJAMASSIST_INACTV;
        *Rte_Pim_BmwTrfcJamAssiDampgScaStVari() = ZERO_ULS_F32;
        *Rte_Pim_LimExcddFltRefTi()             = ZERO_CNT_U32;
        *Rte_Pim_TmpBmwTrfcJamAssiDampgSt()     = ZERO_CNT_U08;
        *Rte_Pim_PrevLimExcddFlt()              = FALSE;

    }


    /* Write Outputs */
    (void) Rte_Write_BmwTrfcJamAssiDampgSt_Val(BmwTrfcJamAssiDampgSt_Cnt_T_enum);
    (void) Rte_Write_TrfcJamAssiCmd_Val(TrfcJamAssiCmd_MotNwtMtr_T_f32);


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define BmwTrfcJamAssiDampg_STOP_SEC_CODE
#include "BmwTrfcJamAssiDampg_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Name:        CalcnTrfcJamAssiSt
 * Description: The implementation of Simulink block CalcnTrfcJamAssiSt
 * Inputs:      BmwTrfcJamAssiDampgStReq_Cnt_T_enum
 *              BmwTrfcJamAssiDampgScaReqVld_Cnt_T_logl
 *              BmwTrfcJamAssiDampgStReqVld_Cnt_T_logl
 * Outputs:     BmwTrfcJamAssiSt_T_Cnt_enum
 * Usage Notes:
 *********************************************************************************************************************/

static FUNC(BmwTrfcJamAssiSt1, BmwTrfcJamAssiDampg_CODE) CalcnTrfcJamAssiSt(
        CONST(BmwTrfcJamAssiDampgStReq1, AUTOMATIC) BmwTrfcJamAssiDampgStReq_Cnt_T_enum,
        CONST(boolean, AUTOMATIC) BmwTrfcJamAssiDampgScaReqVld_Cnt_T_logl,
        CONST(boolean, AUTOMATIC) BmwTrfcJamAssiDampgStReqVld_Cnt_T_logl)
{

    VAR(BmwTrfcJamAssiSt1, AUTOMATIC) BmwTrfcJamAssiSt_T_Cnt_enum;
    VAR(boolean, AUTOMATIC) BmwTrfcJamAssiDampgErr_T_Cnt_logl;


    BmwTrfcJamAssiDampgErr_T_Cnt_logl = ProcessBmwTrfcJamAssiDampgErr(
            BmwTrfcJamAssiDampgStReq_Cnt_T_enum,
            BmwTrfcJamAssiDampgScaReqVld_Cnt_T_logl,
            BmwTrfcJamAssiDampgStReqVld_Cnt_T_logl);


    /* CalcnTrfcJamAssiSt */

    switch(*Rte_Pim_TmpBmwTrfcJamAssiDampgSt())
    {

        case BMWTRFCJAMASSIST_INACTV:
        {

            BmwTrfcJamAssiSt_T_Cnt_enum = BMWTRFCJAMASSIST_INACTV;

            if (BmwTrfcJamAssiDampgStReq_Cnt_T_enum == BMWTRFCJAMASSIDAMPGSTREQ_CNVSPADDLDAMPG)
            {
                BmwTrfcJamAssiSt_T_Cnt_enum = BMWTRFCJAMASSIST_ACTV;
            }

            if(BmwTrfcJamAssiDampgErr_T_Cnt_logl != FALSE)
            {
                BmwTrfcJamAssiSt_T_Cnt_enum = BMWTRFCJAMASSIST_INVLD;
            }

            break;
        }

        case BMWTRFCJAMASSIST_ACTV:
        {
            BmwTrfcJamAssiSt_T_Cnt_enum = BMWTRFCJAMASSIST_ACTV;

            if (BmwTrfcJamAssiDampgStReq_Cnt_T_enum == BMWTRFCJAMASSIDAMPGSTREQ_DONOTCNVSPADDLDAMPG)
            {
                BmwTrfcJamAssiSt_T_Cnt_enum = BMWTRFCJAMASSIST_INACTV;
            }

            if(BmwTrfcJamAssiDampgErr_T_Cnt_logl != FALSE)
            {
                BmwTrfcJamAssiSt_T_Cnt_enum = BMWTRFCJAMASSIST_INVLD;
            }

            break;
        }
        case BMWTRFCJAMASSIST_INVLD:
        {

            BmwTrfcJamAssiSt_T_Cnt_enum = BMWTRFCJAMASSIST_INVLD;

            if((BmwTrfcJamAssiDampgStReq_Cnt_T_enum == BMWTRFCJAMASSIDAMPGSTREQ_DONOTCNVSPADDLDAMPG)
                &&(BmwTrfcJamAssiDampgErr_T_Cnt_logl == FALSE))
            {
                BmwTrfcJamAssiSt_T_Cnt_enum = BMWTRFCJAMASSIST_INACTV;
            }

            break;
        }

        default:
        {
            BmwTrfcJamAssiSt_T_Cnt_enum = BMWTRFCJAMASSIST_INACTV;

            break;
        }
    }

    *Rte_Pim_TmpBmwTrfcJamAssiDampgSt() = (uint8)BmwTrfcJamAssiSt_T_Cnt_enum;

    return BmwTrfcJamAssiSt_T_Cnt_enum;
}

/**********************************************************************************************************************
 * Name:        ProcessBmwTrfcJamAssiDampgErr
 * Description: Detecting of the erroneous state
 * Inputs:      BmwTrfcJamAssiDampgStReq_Cnt_T_enum
 *              BmwTrfcJamAssiDampgScaReqVld_Cnt_T_logl
 *              BmwTrfcJamAssiDampgStReqVld_Cnt_T_logl
 *              *Rte_Pim_PrevLimExcddFlt()
 * Outputs:     BmwTrfcJamAssiDampgErr_T_Cnt_logl
 * Usage Notes:
 *********************************************************************************************************************/

static FUNC(boolean, BmwTrfcJamAssiDampg_CODE) ProcessBmwTrfcJamAssiDampgErr(
        CONST(BmwTrfcJamAssiDampgStReq1, AUTOMATIC) BmwTrfcJamAssiDampgStReq_Cnt_T_enum,
        CONST(boolean, AUTOMATIC) BmwTrfcJamAssiDampgScaReqVld_Cnt_T_logl,
        CONST(boolean, AUTOMATIC) BmwTrfcJamAssiDampgStReqVld_Cnt_T_logl)
{

    VAR(boolean, AUTOMATIC) BmwTrfcJamAssiDampgErr_T_Cnt_logl;

    if((BmwTrfcJamAssiDampgStReq_Cnt_T_enum == BMWTRFCJAMASSIDAMPGSTREQ_INVLDSIG)
        ||(BmwTrfcJamAssiDampgScaReqVld_Cnt_T_logl == FALSE)
        ||(BmwTrfcJamAssiDampgStReqVld_Cnt_T_logl == FALSE)
        ||(*Rte_Pim_PrevLimExcddFlt() != FALSE))
    {
        BmwTrfcJamAssiDampgErr_T_Cnt_logl = TRUE;
    }
    else
    {
        BmwTrfcJamAssiDampgErr_T_Cnt_logl = FALSE;
    }


    return BmwTrfcJamAssiDampgErr_T_Cnt_logl;
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
