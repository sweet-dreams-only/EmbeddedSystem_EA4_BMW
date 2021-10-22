/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  BmwHaptcFb.c
 *        Config:  C:/Users/nz2999/Documents/Synergy/ccm_wa/ses_dev_ea4/CF020A_BmwHaptcFb_Impl-nz2999/CF020A_BmwHaptcFb_Impl/tools/Component.dpa
 *     SW-C Type:  BmwHaptcFb
 *  Generated at:  Fri May 18 11:14:55 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <BmwHaptcFb>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Copyright 2018 Nxtr
 * Nxtr Confidential
 *
 * Module File Name  : BmwHaptcFb.c
 * Module Description: CF020A Implementation - Bmw Haptic Feedback
 * Project           : CBD
 * Author            : Krzysztof Byrski
 **********************************************************************************************************************
 * Version Control:
 * %version:          1 %
 * %derived_by:       nz2999 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                             SCR #
 * --------  -------  --------  ----------------------------------------------------------------------------  ---------
 * 05/24/18  1        KByrski   Initial version (based on Design 1.1.0)                                       EA4#16079
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
 * BmwHaptcFbIntenNr1
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * BmwHaptcFbPatNr1
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * HaptcFbSt1
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * StsSteerAssi1
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
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

#include "Rte_BmwHaptcFb.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/************************************************ Include Statements *************************************************/
#include "NxtrFixdPt.h"
#include "NxtrIntrpn.h"
#include "NxtrMath.h"

/******************************************** File Level Rule Deviations *********************************************/
/* MISRA-C:2004 Rule 16.10 [NXTRDEV 16.10.1]: There is no appropriate action to take on the return value for Rte_Call, Rte_Read, Rte_Write */
/* MISRA-C:2004 Rule 19.1 [NXTRDEV 19.1.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */

/********************************************* Embedded Local Constants **********************************************/
#define CNVMILLISECTOCNT_CNTPERMILLISEC_U16         (10U)
#define CNVSECTOMILLISEC_MILLISECPERSEC_F32         (1000.0F)
#define TQOSCNAMPMAX_MOTNWTMTR_F32                  (1.2F)
#define TQOSCNAMPMIN_MOTNWTMTR_F32                  (0.0F)
#define TQOSCNFALLRAMPRATEMAX_MOTNWTMTRPERSEC_F32   (-0.1F)
#define TQOSCNFALLRAMPRATEMIN_MOTNWTMTRPERSEC_F32   (-4400.0F)
#define TQOSCNFRQINIT_HZ_F32                        (15.0F)
#define TQOSCNFRQMAX_HZ_F32                         (50.0F)
#define TQOSCNFRQMIN_HZ_F32                         (10.0F)
#define TQOSCNRISNGRAMPRATEMAX_MOTNWTMTRPERSEC_F32  (4400.0F)
#define TQOSCNRISNGRAMPRATEMIN_MOTNWTMTRPERSEC_F32  (0.1F)
#define TQOSCNZERO_MOTNWTMTR_F32                    (0.0F)
#define ZEROACTVTI_CNT_U08                          (0U)

/*************************************************** Local Macros ****************************************************/
#define PrmSysGlbPrmVehSpdBilnrSeln         (*(const Ary1D_u9p7_12 *)  Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D())
#define PrmBmwHaptcFbAmpAndIntenHwTqTblX    (*(const Ary1D_u4p12_12 *) Rte_Prm_BmwHaptcFbAmpAndIntenHwTqTblX_Ary1D())
#define PrmBmwHaptcFbAmpBilnrSeln           (*(const Ary1D_u4p12_13 *) Rte_Prm_BmwHaptcFbAmpBilnrSeln_Ary1D())
#define PrmBmwHaptcFbIntenSelnTblX          (*(const Ary1D_u16_13 *)   Rte_Prm_BmwHaptcFbIntenSelnTblX_Ary1D())
#define PrmBmwHaptcFbFrqBilnrSeln           (*(const Ary1D_u6p10_13 *) Rte_Prm_BmwHaptcFbFrqBilnrSeln_Ary1D())

/******************************************** Local Function Prototypes **********************************************/
static FUNC(boolean, BmwHaptcFb_CODE) CalcBmwHaptcFbPatNr(
        P2VAR(boolean, AUTOMATIC, BmwHaptcFb_VAR) BmwHaptcFbPatNr_Cnt_T_enum,
        CONST(boolean, AUTOMATIC) BmwHaptcFbPatNrVld_Cnt_T_logl,
        CONST(boolean, AUTOMATIC) HwOscnActv_Cnt_T_logl);

 static FUNC(boolean, BmwHaptcFb_CODE) CalcBmwHaptcFbIntenNr(
         P2VAR(boolean, AUTOMATIC, BmwHaptcFb_VAR) BmwHaptcFbIntenNr_Cnt_T_enum,
         CONST(boolean, AUTOMATIC) BmwHaptcFbIntenNrVld_Cnt_T_logl,
         CONST(boolean, AUTOMATIC) HwOscnActv_Cnt_T_logl);

 static FUNC(boolean, BmwHaptcFb_CODE) CalcHwOscnEna(
         CONST(boolean, AUTOMATIC) PatChgReq_Cnt_T_logl,
         CONST(float32, AUTOMATIC) ActvTi_MilliSec_T_f32,
         CONST(float32, AUTOMATIC) PasTi_MilliSec_T_f32);

static FUNC(void, BmwHaptcFb_CODE) CalcAmpAndFrq(
        CONST(float32, AUTOMATIC) VehSpd_Kph_T_f32,
        CONST(float32, AUTOMATIC) HwTq_HwNwtMtr_T_f32,
        P2VAR(float32, AUTOMATIC, BmwHaptcFb_VAR) HwOscnMotAmp_MotNwtMtr_T_f32,
        P2VAR(float32, AUTOMATIC, BmwHaptcFb_VAR) HwOscnFrq_Hz_T_f32);

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
 * u4p12: Integer in interval [0...65535]
 * u6p10: Integer in interval [0...65535]
 * u9p7: Integer in interval [0...65535]
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * BmwHaptcFbIntenNr1: Enumeration of integer in interval [0...255] with enumerators
 *   BMWHAPTCFBINTENNR_INTEN0 (0U)
 *   BMWHAPTCFBINTENNR_INTEN1 (1U)
 *   BMWHAPTCFBINTENNR_INTEN2 (2U)
 *   BMWHAPTCFBINTENNR_INTEN3 (3U)
 *   BMWHAPTCFBINTENNR_INTEN4 (4U)
 *   BMWHAPTCFBINTENNR_INTEN5 (5U)
 *   BMWHAPTCFBINTENNR_INTEN6 (6U)
 *   BMWHAPTCFBINTENNR_INTEN7 (7U)
 *   BMWHAPTCFBINTENNR_INTEN8 (8U)
 *   BMWHAPTCFBINTENNR_INTEN9 (9U)
 *   BMWHAPTCFBINTENNR_INTEN10 (10U)
 *   BMWHAPTCFBINTENNR_INTEN11 (11U)
 *   BMWHAPTCFBINTENNR_INTEN12 (12U)
 *   BMWHAPTCFBINTENNR_RESD1 (13U)
 *   BMWHAPTCFBINTENNR_RESD2 (14U)
 *   BMWHAPTCFBINTENNR_INVLDSIG (15U)
 * BmwHaptcFbPatNr1: Enumeration of integer in interval [0...255] with enumerators
 *   BMWHAPTCFBPATNR_NOHAPTCWARN (0U)
 *   BMWHAPTCFBPATNR_PAT1 (1U)
 *   BMWHAPTCFBPATNR_PAT2 (2U)
 *   BMWHAPTCFBPATNR_PAT3 (3U)
 *   BMWHAPTCFBPATNR_PAT4 (4U)
 *   BMWHAPTCFBPATNR_PAT5 (5U)
 *   BMWHAPTCFBPATNR_PAT6 (6U)
 *   BMWHAPTCFBPATNR_PAT7 (7U)
 *   BMWHAPTCFBPATNR_PAT8 (8U)
 *   BMWHAPTCFBPATNR_PAT9 (9U)
 *   BMWHAPTCFBPATNR_PAT10 (10U)
 *   BMWHAPTCFBPATNR_FCTIFNOTAVL (13U)
 *   BMWHAPTCFBPATNR_FCTRPRTERR (14U)
 *   BMWHAPTCFBPATNR_INVLDSIG (15U)
 * HaptcFbSt1: Enumeration of integer in interval [0...255] with enumerators
 *   HAPTCFBST_FCTAVLNOTACTV (1U)
 *   HAPTCFBST_ERR (6U)
 *   HAPTCFBST_FCTAVLACTV (9U)
 *   HAPTCFBST_FCTNOTAVL (14U)
 *   HAPTCFBST_INVLDSIG (15U)
 * StsSteerAssi1: Enumeration of integer in interval [0...255] with enumerators
 *   STSSTEERASSI_OFF (0U)
 *   STSSTEERASSI_ON (1U)
 *
 * Array Types:
 * ============
 * Ary1D_f32_11: Array with 11 element(s) of type float32
 * Ary1D_u16_13: Array with 13 element(s) of type uint16
 * Ary1D_u4p12_12: Array with 12 element(s) of type u4p12
 * Ary1D_u4p12_13: Array with 13 element(s) of type u4p12
 * Ary1D_u6p10_12: Array with 12 element(s) of type u6p10
 * Ary1D_u6p10_13: Array with 13 element(s) of type u6p10
 * Ary1D_u9p7_12: Array with 12 element(s) of type u9p7
 * Ary2D_u4p12_12_12: Array with 12 element(s) of type Ary1D_u4p12_12
 * Ary2D_u4p12_13_13: Array with 13 element(s) of type Ary1D_u4p12_13
 * Ary2D_u6p10_12_12: Array with 12 element(s) of type Ary1D_u6p10_12
 * Ary2D_u6p10_13_13: Array with 13 element(s) of type Ary1D_u6p10_13
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   uint32 *Rte_Pim_TqOscnEnaTmr(void)
 *   BmwHaptcFbIntenNr1 *Rte_Pim_CurrInten(void)
 *   BmwHaptcFbPatNr1 *Rte_Pim_CurrPat(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_BmwHaptcFbEpsDegradedFltThd_Val(void)
 *   u4p12 *Rte_Prm_BmwHaptcFbAmpAndIntenHwTqTblX_Ary1D(void)
 *     Returnvalue: u4p12* is of type Ary1D_u4p12_12
 *   u4p12 *Rte_Prm_BmwHaptcFbAmpBilnrSeln_Ary1D(void)
 *     Returnvalue: u4p12* is of type Ary1D_u4p12_13
 *   u4p12 *Rte_Prm_BmwHaptcFbAmpSelnTblY_Ary2D(void)
 *     Returnvalue: u4p12* is of type Ary2D_u4p12_13_13
 *   u6p10 *Rte_Prm_BmwHaptcFbFrqBilnrSeln_Ary1D(void)
 *     Returnvalue: u6p10* is of type Ary1D_u6p10_13
 *   u6p10 *Rte_Prm_BmwHaptcFbFrqSelnTblY_Ary2D(void)
 *     Returnvalue: u6p10* is of type Ary2D_u6p10_13_13
 *   u6p10 *Rte_Prm_BmwHaptcFbHwTqFrqTblY_Ary2D(void)
 *     Returnvalue: u6p10* is of type Ary2D_u6p10_12_12
 *   uint16 *Rte_Prm_BmwHaptcFbIntenSelnTblX_Ary1D(void)
 *     Returnvalue: uint16* is of type Ary1D_u16_13
 *   u4p12 *Rte_Prm_BmwHaptcFbMotTqAmpTblY_Ary2D(void)
 *     Returnvalue: u4p12* is of type Ary2D_u4p12_12_12
 *   float32 *Rte_Prm_BmwHaptcFbPatActvTiTblY_Ary1D(void)
 *     Returnvalue: float32* is of type Ary1D_f32_11
 *   float32 *Rte_Prm_BmwHaptcFbPatPasTiTblY_Ary1D(void)
 *     Returnvalue: float32* is of type Ary1D_f32_11
 *   float32 *Rte_Prm_BmwHaptcFbPatRisngSlewTblY_Ary1D(void)
 *     Returnvalue: float32* is of type Ary1D_f32_11
 *   u9p7 *Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D(void)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_12
 *
 *********************************************************************************************************************/


#define BmwHaptcFb_START_SEC_CODE
#include "BmwHaptcFb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwHaptcFbInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwHaptcFbInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwHaptcFb_CODE) BmwHaptcFbInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwHaptcFbInit1
 *********************************************************************************************************************/

    *Rte_Pim_CurrPat() = BMWHAPTCFBPATNR_NOHAPTCWARN;
    *Rte_Pim_CurrInten() = BMWHAPTCFBINTENNR_INTEN0;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwHaptcFbPer1
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
 *   Std_ReturnType Rte_Read_BmwHaptcFbIntenNr_Val(BmwHaptcFbIntenNr1 *data)
 *   Std_ReturnType Rte_Read_BmwHaptcFbIntenNrVld_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_BmwHaptcFbPatNr_Val(BmwHaptcFbPatNr1 *data)
 *   Std_ReturnType Rte_Read_BmwHaptcFbPatNrVld_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_DiagcStsNonRcvrlReqDiFltPrsnt_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_HaptcFbEna_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_HwOscnActv_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_HwOscnDcThdExcdd_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_HwTq_Val(float32 *data)
 *   Std_ReturnType Rte_Read_StsSteerAssi_Val(StsSteerAssi1 *data)
 *   Std_ReturnType Rte_Read_ThermRednFac_Val(float32 *data)
 *   Std_ReturnType Rte_Read_VehSpd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_VehSpdVld_Logl(boolean *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_HaptcFbSt_Val(HaptcFbSt1 data)
 *   Std_ReturnType Rte_Write_HwOscnEna_Logl(boolean data)
 *   Std_ReturnType Rte_Write_HwOscnFallRampRate_Val(float32 data)
 *   Std_ReturnType Rte_Write_HwOscnFrq_Val(float32 data)
 *   Std_ReturnType Rte_Write_HwOscnMotAmp_Val(float32 data)
 *   Std_ReturnType Rte_Write_HwOscnRisngRampRate_Val(float32 data)
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
 * Symbol: BmwHaptcFbPer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwHaptcFb_CODE) BmwHaptcFbPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwHaptcFbPer1
 *********************************************************************************************************************/

    /* Inputs */
    VAR(BmwHaptcFbIntenNr1,  AUTOMATIC) BmwHaptcFbIntenNr_Cnt_T_enum;
    VAR(boolean, AUTOMATIC) BmwHaptcFbIntenNrVld_Cnt_T_logl;
    VAR(BmwHaptcFbPatNr1,  AUTOMATIC) BmwHaptcFbPatNr_Cnt_T_enum;
    VAR(boolean, AUTOMATIC) BmwHaptcFbPatNrVld_Cnt_T_logl;
    VAR(boolean, AUTOMATIC) DiagcStsNonRcvrlReqDiFltPrsnt_Cnt_T_logl;
    VAR(boolean, AUTOMATIC) HaptcFbEna_Cnt_T_logl;
    VAR(boolean, AUTOMATIC) HwOscnActv_Cnt_T_logl;
    VAR(boolean, AUTOMATIC) HwOscnDcThdExcdd_Cnt_T_logl;
    VAR(float32, AUTOMATIC) HwTq_HwNwtMtr_T_f32;
    VAR(StsSteerAssi1, AUTOMATIC) StsSteerAssi_Cnt_T_enum;
    VAR(float32, AUTOMATIC) ThermRednFac_Uls_T_f32;
    VAR(float32, AUTOMATIC) VehSpd_Kph_T_f32;
    VAR(boolean, AUTOMATIC) VehSpdVld_Cnt_T_logl;

    /* Outputs */
    VAR(HaptcFbSt1, AUTOMATIC) HaptcFbSt_Cnt_T_enum;
    VAR(boolean, AUTOMATIC) HwOscnEna_Cnt_T_logl;
    VAR(float32, AUTOMATIC) HwOscnFallRampRate_MotNwtMtrPerSec_T_f32;
    VAR(float32, AUTOMATIC) HwOscnFrq_Hz_T_f32;
    VAR(float32, AUTOMATIC) HwOscnMotAmp_MotNwtMtr_T_f32;
    VAR(float32, AUTOMATIC) HwOscnRisngRampRate_MotNwtMtrPerSec_T_f32;

    /* Internals */
    VAR(boolean, AUTOMATIC) Flt_Cnt_T_logl;
    VAR(boolean, AUTOMATIC) BmwHaptcFbPatNrLgc_Cnt_T_logl;
    VAR(boolean, AUTOMATIC) BmwHaptcFbIntenNrLgc_Cnt_T_logl;
    VAR(boolean, AUTOMATIC) PatChgReq_Cnt_T_logl;
    VAR(float32, AUTOMATIC) ActvTi_MilliSec_T_f32;
    VAR(float32, AUTOMATIC) PasTi_MilliSec_T_f32;

    /* Read inputs */
    (void) Rte_Read_BmwHaptcFbIntenNr_Val(&BmwHaptcFbIntenNr_Cnt_T_enum);
    (void) Rte_Read_BmwHaptcFbIntenNrVld_Logl(&BmwHaptcFbIntenNrVld_Cnt_T_logl);
    (void) Rte_Read_BmwHaptcFbPatNr_Val(&BmwHaptcFbPatNr_Cnt_T_enum);
    (void) Rte_Read_BmwHaptcFbPatNrVld_Logl(&BmwHaptcFbPatNrVld_Cnt_T_logl);
    (void) Rte_Read_DiagcStsNonRcvrlReqDiFltPrsnt_Logl(&DiagcStsNonRcvrlReqDiFltPrsnt_Cnt_T_logl);
    (void) Rte_Read_HaptcFbEna_Logl(&HaptcFbEna_Cnt_T_logl);
    (void) Rte_Read_HwOscnActv_Logl(&HwOscnActv_Cnt_T_logl);
    (void) Rte_Read_HwOscnDcThdExcdd_Logl(&HwOscnDcThdExcdd_Cnt_T_logl);
    (void) Rte_Read_HwTq_Val(&HwTq_HwNwtMtr_T_f32);
    (void) Rte_Read_StsSteerAssi_Val(&StsSteerAssi_Cnt_T_enum);
    (void) Rte_Read_ThermRednFac_Val(&ThermRednFac_Uls_T_f32);
    (void) Rte_Read_VehSpd_Val(&VehSpd_Kph_T_f32);
    (void) Rte_Read_VehSpdVld_Logl(&VehSpdVld_Cnt_T_logl);

    /* ComErrAndFlt */
    if ((DiagcStsNonRcvrlReqDiFltPrsnt_Cnt_T_logl != FALSE) ||
        (VehSpdVld_Cnt_T_logl == FALSE) ||
        (HwOscnDcThdExcdd_Cnt_T_logl != FALSE) ||
        (ThermRednFac_Uls_T_f32 > Rte_Prm_BmwHaptcFbEpsDegradedFltThd_Val()))
    {
        Flt_Cnt_T_logl = TRUE;
    }
    else
    {
        Flt_Cnt_T_logl = FALSE;
    }

    /* StateMachine */
    BmwHaptcFbPatNrLgc_Cnt_T_logl = CalcBmwHaptcFbPatNr(
            &BmwHaptcFbPatNr_Cnt_T_enum,
            BmwHaptcFbPatNrVld_Cnt_T_logl,
            HwOscnActv_Cnt_T_logl);

    BmwHaptcFbIntenNrLgc_Cnt_T_logl = CalcBmwHaptcFbIntenNr(
            &BmwHaptcFbIntenNr_Cnt_T_enum,
            BmwHaptcFbIntenNrVld_Cnt_T_logl,
            HwOscnActv_Cnt_T_logl);

    /* CalcHaptcFbSt */
    if ((HaptcFbEna_Cnt_T_logl == FALSE) ||
        (StsSteerAssi_Cnt_T_enum == STSSTEERASSI_OFF) ||
        (BmwHaptcFbPatNrLgc_Cnt_T_logl != FALSE) ||
        (BmwHaptcFbIntenNrLgc_Cnt_T_logl != FALSE) ||
        (Flt_Cnt_T_logl != FALSE))
    {
        /* HAPTCFBST_FCTNOTAVL */
        HaptcFbSt_Cnt_T_enum = HAPTCFBST_FCTNOTAVL;
    }
    else
    {
        /* KeepChecking */
        if (((BmwHaptcFbPatNr_Cnt_T_enum == BMWHAPTCFBPATNR_NOHAPTCWARN) ||
             (BmwHaptcFbIntenNr_Cnt_T_enum == BMWHAPTCFBINTENNR_INTEN0)) &&
            (HwOscnActv_Cnt_T_logl == FALSE))
        {
            /* HAPTCFBST_FCTAVLNOTACTV */
            HaptcFbSt_Cnt_T_enum = HAPTCFBST_FCTAVLNOTACTV;
        }
        else
        {
            /* HAPTCFBST_FCTAVLACTV */
            HaptcFbSt_Cnt_T_enum = HAPTCFBST_FCTAVLACTV;
        }
    }

    if ((HaptcFbSt_Cnt_T_enum != HAPTCFBST_FCTAVLNOTACTV) &&
        (HaptcFbSt_Cnt_T_enum != HAPTCFBST_FCTAVLACTV))
    {
        /* ZeroOutp */
        HwOscnFrq_Hz_T_f32 = TQOSCNFRQINIT_HZ_F32;
        HwOscnMotAmp_MotNwtMtr_T_f32 = TQOSCNZERO_MOTNWTMTR_F32;
        HwOscnRisngRampRate_MotNwtMtrPerSec_T_f32 = TQOSCNRISNGRAMPRATEMAX_MOTNWTMTRPERSEC_F32;
        HwOscnEna_Cnt_T_logl = FALSE;
    }
    else
    {
        /* Calc */

        /* NrArbn */
        if(HwOscnActv_Cnt_T_logl == FALSE)
        {
            /* UpdPatAndIntenNr */
            *Rte_Pim_CurrPat() = BmwHaptcFbPatNr_Cnt_T_enum;
            *Rte_Pim_CurrInten() = BmwHaptcFbIntenNr_Cnt_T_enum;
        }

        if ((*Rte_Pim_CurrPat() != BmwHaptcFbPatNr_Cnt_T_enum) ||
            (*Rte_Pim_CurrInten() != BmwHaptcFbIntenNr_Cnt_T_enum))
        {
            PatChgReq_Cnt_T_logl = TRUE;
        }
        else
        {
            PatChgReq_Cnt_T_logl = FALSE;
        }

        /* GenPat */
        ActvTi_MilliSec_T_f32 = Rte_Prm_BmwHaptcFbPatActvTiTblY_Ary1D()[(uint8) *Rte_Pim_CurrPat()] * CNVSECTOMILLISEC_MILLISECPERSEC_F32;
        PasTi_MilliSec_T_f32 = Rte_Prm_BmwHaptcFbPatPasTiTblY_Ary1D()[(uint8) *Rte_Pim_CurrPat()] * CNVSECTOMILLISEC_MILLISECPERSEC_F32;
        HwOscnRisngRampRate_MotNwtMtrPerSec_T_f32 = Rte_Prm_BmwHaptcFbPatRisngSlewTblY_Ary1D()[(uint8) *Rte_Pim_CurrPat()];

        /* CalcHwOscnEna */
        HwOscnEna_Cnt_T_logl = CalcHwOscnEna(
                PatChgReq_Cnt_T_logl,
                ActvTi_MilliSec_T_f32,
                PasTi_MilliSec_T_f32);

        /* CalcAmpAndFrq */
        CalcAmpAndFrq(
                VehSpd_Kph_T_f32,
                HwTq_HwNwtMtr_T_f32,
                &HwOscnMotAmp_MotNwtMtr_T_f32,
                &HwOscnFrq_Hz_T_f32);
    }

    HwOscnFrq_Hz_T_f32 = Lim_f32(
            HwOscnFrq_Hz_T_f32,
            TQOSCNFRQMIN_HZ_F32,
            TQOSCNFRQMAX_HZ_F32);

    HwOscnMotAmp_MotNwtMtr_T_f32 = Lim_f32(
            HwOscnMotAmp_MotNwtMtr_T_f32,
            TQOSCNAMPMIN_MOTNWTMTR_F32,
            TQOSCNAMPMAX_MOTNWTMTR_F32);

    HwOscnRisngRampRate_MotNwtMtrPerSec_T_f32 = Lim_f32(
            HwOscnRisngRampRate_MotNwtMtrPerSec_T_f32,
            TQOSCNRISNGRAMPRATEMIN_MOTNWTMTRPERSEC_F32,
            TQOSCNRISNGRAMPRATEMAX_MOTNWTMTRPERSEC_F32);

    HwOscnFallRampRate_MotNwtMtrPerSec_T_f32 = Lim_f32(
            -HwOscnRisngRampRate_MotNwtMtrPerSec_T_f32,
            TQOSCNFALLRAMPRATEMIN_MOTNWTMTRPERSEC_F32,
            TQOSCNFALLRAMPRATEMAX_MOTNWTMTRPERSEC_F32);

    /* Write outputs */
    (void) Rte_Write_HaptcFbSt_Val(HaptcFbSt_Cnt_T_enum);
    (void) Rte_Write_HwOscnEna_Logl(HwOscnEna_Cnt_T_logl);
    (void) Rte_Write_HwOscnFallRampRate_Val(HwOscnFallRampRate_MotNwtMtrPerSec_T_f32);
    (void) Rte_Write_HwOscnFrq_Val(HwOscnFrq_Hz_T_f32);
    (void) Rte_Write_HwOscnMotAmp_Val(HwOscnMotAmp_MotNwtMtr_T_f32);
    (void) Rte_Write_HwOscnRisngRampRate_Val(HwOscnRisngRampRate_MotNwtMtrPerSec_T_f32);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define BmwHaptcFb_STOP_SEC_CODE
#include "BmwHaptcFb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


#define BmwHaptcFb_START_SEC_CODE
#include "BmwHaptcFb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Name:        CalcBmwHaptcFbPatNr
 * Description: Implementation of "CalcBmwHaptcFbPatNr" and "BmwHaptcFbPatNrLgc" Simulink block
 * Inputs:      BmwHaptcFbPatNr_Cnt_T_enum
 *              BmwHaptcFbPatNrVld_Cnt_T_logl
 *              HwOscnActv_Cnt_T_logl
 * Outputs:     BmwHaptcFbPatNr_Cnt_T_enum
 *              BmwHaptcFbPatNrLgc_Cnt_T_logl
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(boolean, BmwHaptcFb_CODE) CalcBmwHaptcFbPatNr(
        P2VAR(boolean, AUTOMATIC, BmwHaptcFb_VAR) BmwHaptcFbPatNr_Cnt_T_enum,
        CONST(boolean, AUTOMATIC) BmwHaptcFbPatNrVld_Cnt_T_logl,
        CONST(boolean, AUTOMATIC) HwOscnActv_Cnt_T_logl)
{
    VAR(boolean, AUTOMATIC) BmwHaptcFbPatNrLgc_Cnt_T_logl;

    /* CalcBmwHaptcFbPatNr */
    if (BmwHaptcFbPatNrVld_Cnt_T_logl == FALSE)
    {
        /* Invld */
        *BmwHaptcFbPatNr_Cnt_T_enum = BMWHAPTCFBPATNR_INVLDSIG;
    }
    else
    {
        /* Vld */
        switch (*BmwHaptcFbPatNr_Cnt_T_enum)
        {
            case BMWHAPTCFBPATNR_FCTRPRTERR:
            case BMWHAPTCFBPATNR_FCTIFNOTAVL:
            case BMWHAPTCFBPATNR_INVLDSIG:
                /* Invld */
                *BmwHaptcFbPatNr_Cnt_T_enum = BMWHAPTCFBPATNR_INVLDSIG;
            break;

            default:
                /* Vld */
            break;
        }
    }

    /* BmwHaptcFbPatNrLgc */
    if ((HwOscnActv_Cnt_T_logl == FALSE) && (*BmwHaptcFbPatNr_Cnt_T_enum == BMWHAPTCFBPATNR_INVLDSIG))
    {
        BmwHaptcFbPatNrLgc_Cnt_T_logl = TRUE;
    }
    else
    {
        BmwHaptcFbPatNrLgc_Cnt_T_logl = FALSE;
    }

    return BmwHaptcFbPatNrLgc_Cnt_T_logl;
}

/**********************************************************************************************************************
 * Name:        CalcBmwHaptcFbIntenNr
 * Description: Implementation of "CalcBmwHaptcFbIntenNr" and "BmwHaptcFbIntenNrLgc" Simulink block
 * Inputs:      BmwHaptcFbIntenNr_Cnt_T_enum
 *              BmwHaptcFbIntenNrVld_Cnt_T_logl
 *              HwOscnActv_Cnt_T_logl
 * Outputs:     BmwHaptcFbIntenNr_Cnt_T_enum
 *              BmwHaptcFbIntenNrLgc_Cnt_T_logl
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(boolean, BmwHaptcFb_CODE) CalcBmwHaptcFbIntenNr(
        P2VAR(boolean, AUTOMATIC, BmwHaptcFb_VAR) BmwHaptcFbIntenNr_Cnt_T_enum,
        CONST(boolean, AUTOMATIC) BmwHaptcFbIntenNrVld_Cnt_T_logl,
        CONST(boolean, AUTOMATIC) HwOscnActv_Cnt_T_logl)
{
    VAR(boolean, AUTOMATIC) BmwHaptcFbIntenNrLgc_Cnt_T_logl;

    if (BmwHaptcFbIntenNrVld_Cnt_T_logl == FALSE)
    {
        /* Invld */
        *BmwHaptcFbIntenNr_Cnt_T_enum = BMWHAPTCFBINTENNR_INVLDSIG;
    }
    else
    {
        /* Vld */
        switch(*BmwHaptcFbIntenNr_Cnt_T_enum)
        {
            case BMWHAPTCFBINTENNR_RESD1:
            case BMWHAPTCFBINTENNR_RESD2:
            case BMWHAPTCFBINTENNR_INVLDSIG:
                /* Invld */
                *BmwHaptcFbIntenNr_Cnt_T_enum = BMWHAPTCFBINTENNR_INVLDSIG;
            break;

            default:
                /* Vld */
            break;
        }
    }

    /* BmwHaptcFbIntenNrLgc */
    if ((HwOscnActv_Cnt_T_logl == FALSE) && (*BmwHaptcFbIntenNr_Cnt_T_enum == BMWHAPTCFBINTENNR_INVLDSIG))
    {
        BmwHaptcFbIntenNrLgc_Cnt_T_logl = TRUE;
    }
    else
    {
        BmwHaptcFbIntenNrLgc_Cnt_T_logl = FALSE;
    }

    return BmwHaptcFbIntenNrLgc_Cnt_T_logl;
}

/**********************************************************************************************************************
 * Name:        CalcHwOscnEna
 * Description: Implementation of "CalcHwOscnEna" Simulink block
 * Inputs:      PatChgReq_Cnt_T_logl
 *              Rte_Pim_CurrPat
 *              ActvTi_Sec_T_f32
 *              PasTi_Sec_T_u32
 *              Rte_Pim_CurrInten
 * Outputs:     HwOscnEna_Cnt_T_logl
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(boolean, BmwHaptcFb_CODE) CalcHwOscnEna(
        CONST(boolean, AUTOMATIC) PatChgReq_Cnt_T_logl,
        CONST(float32, AUTOMATIC) ActvTi_MilliSec_T_f32,
        CONST(float32, AUTOMATIC) PasTi_MilliSec_T_f32)
{
    VAR(uint32, AUTOMATIC) ActvTi_Cnt_T_u32;
    VAR(uint32, AUTOMATIC) PasTi_Cnt_T_u32;
    VAR(uint32, AUTOMATIC) TiSpan_Cnt_T_u32;
    VAR(boolean, AUTOMATIC) HwOscnEna_Cnt_T_logl;

    if ((*Rte_Pim_CurrPat() != BMWHAPTCFBPATNR_NOHAPTCWARN) &&
        (*Rte_Pim_CurrInten() != BMWHAPTCFBINTENNR_INTEN0))
    {
        /* CalcDurn */

        /* ConvertToUint */
        ActvTi_Cnt_T_u32 = (uint32) ActvTi_MilliSec_T_f32 * (uint32) CNVMILLISECTOCNT_CNTPERMILLISEC_U16;
        PasTi_Cnt_T_u32 = (uint32) PasTi_MilliSec_T_f32 * (uint32) CNVMILLISECTOCNT_CNTPERMILLISEC_U16;

        (void) Rte_Call_GetTiSpan100MicroSec32bit_Oper(*Rte_Pim_TqOscnEnaTmr(), &TiSpan_Cnt_T_u32);

        if (TiSpan_Cnt_T_u32 <= ActvTi_Cnt_T_u32)
        {
            /* TqOscnEnaTrue */
            if ((PasTi_Cnt_T_u32 == (uint32) ZEROACTVTI_CNT_U08) && (PatChgReq_Cnt_T_logl != FALSE))
            {
                HwOscnEna_Cnt_T_logl = FALSE;
            }
            else
            {
                HwOscnEna_Cnt_T_logl = TRUE;
            }
        }
        else
        {
            HwOscnEna_Cnt_T_logl = FALSE;

            /* TqOscnEnaFalse */
            if((ActvTi_Cnt_T_u32 + PasTi_Cnt_T_u32) <= TiSpan_Cnt_T_u32)
            {
                /* RstTmr */
                (void) Rte_Call_GetRefTmr100MicroSec32bit_Oper(Rte_Pim_TqOscnEnaTmr());
            }
        }
    }
    else
    {
        /* RstTmr */
        HwOscnEna_Cnt_T_logl = FALSE;
        (void) Rte_Call_GetRefTmr100MicroSec32bit_Oper(Rte_Pim_TqOscnEnaTmr());
    }

    return HwOscnEna_Cnt_T_logl;
}

/**********************************************************************************************************************
 * Name:        CalcAmpAndFrq
 * Description: Implementation of "CalcAmpAndFrq" Simulink block
 * Inputs:      Rte_Pim_CurrInten
 *              VehSpd_Kph_T_f32
 *              HwTq_HwNwtMtr_T_f32
 * Outputs:     HwOscnMotAmp_MotNwtMtr_T_f32
 *              HwOscnFrq_Hz_T_f32
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(void, BmwHaptcFb_CODE) CalcAmpAndFrq(
        CONST(float32, AUTOMATIC) VehSpd_Kph_T_f32,
        CONST(float32, AUTOMATIC) HwTq_HwNwtMtr_T_f32,
        P2VAR(float32, AUTOMATIC, BmwHaptcFb_VAR) HwOscnMotAmp_MotNwtMtr_T_f32,
        P2VAR(float32, AUTOMATIC, BmwHaptcFb_VAR) HwOscnFrq_Hz_T_f32)
{
    VAR(u4p12, AUTOMATIC) AbsHwTq_HwNwtMtr_T_u4p12;
    VAR(u9p7,  AUTOMATIC) VehSpd_Kph_T_u9p7;
    VAR(u4p12, AUTOMATIC) MotTqAmp_MotNwtMtr_T_u4p12;
    VAR(u6p10, AUTOMATIC) HwTqFrq_Hz_T_u6p10;
    VAR(u4p12, AUTOMATIC) HwOscnMotAmp_MotNwtMtr_T_u4p12;
    VAR(u6p10, AUTOMATIC) HwOscnFrq_Hz_T_u6p10;

    AbsHwTq_HwNwtMtr_T_u4p12 = FloatToFixd_u16_f32(Abslt_f32_f32(HwTq_HwNwtMtr_T_f32), NXTRFIXDPT_FLOATTOP12_ULS_F32);
    VehSpd_Kph_T_u9p7 = FloatToFixd_u16_f32(VehSpd_Kph_T_f32, NXTRFIXDPT_FLOATTOP7_ULS_F32);

    MotTqAmp_MotNwtMtr_T_u4p12 = BilnrIntrpnWithRound_u16_u16CmnXu16MplY(
            VehSpd_Kph_T_u9p7,
            AbsHwTq_HwNwtMtr_T_u4p12,
            Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D(),
            (uint16) TblSize_m(PrmSysGlbPrmVehSpdBilnrSeln),
            Rte_Prm_BmwHaptcFbAmpAndIntenHwTqTblX_Ary1D(),
            Rte_Prm_BmwHaptcFbMotTqAmpTblY_Ary2D(),
            (uint16) TblSize_m(PrmBmwHaptcFbAmpAndIntenHwTqTblX));

    HwOscnMotAmp_MotNwtMtr_T_u4p12 = BilnrIntrpnWithRound_u16_u16CmnXu16MplY(
            MotTqAmp_MotNwtMtr_T_u4p12,
            (uint16) *Rte_Pim_CurrInten(),
            Rte_Prm_BmwHaptcFbAmpBilnrSeln_Ary1D(),
            (uint16) TblSize_m(PrmBmwHaptcFbAmpBilnrSeln),
            Rte_Prm_BmwHaptcFbIntenSelnTblX_Ary1D(),
            Rte_Prm_BmwHaptcFbAmpSelnTblY_Ary2D(),
            (uint16) TblSize_m(PrmBmwHaptcFbIntenSelnTblX));

    *HwOscnMotAmp_MotNwtMtr_T_f32 = FixdToFloat_f32_u16(HwOscnMotAmp_MotNwtMtr_T_u4p12, NXTRFIXDPT_P12TOFLOAT_ULS_F32);

    HwTqFrq_Hz_T_u6p10 = BilnrIntrpnWithRound_u16_u16CmnXu16MplY(
            VehSpd_Kph_T_u9p7,
            AbsHwTq_HwNwtMtr_T_u4p12,
            Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D(),
            (uint16) TblSize_m(PrmSysGlbPrmVehSpdBilnrSeln),
            Rte_Prm_BmwHaptcFbAmpAndIntenHwTqTblX_Ary1D(),
            Rte_Prm_BmwHaptcFbHwTqFrqTblY_Ary2D(),
            (uint16) TblSize_m(PrmBmwHaptcFbAmpAndIntenHwTqTblX));

    HwOscnFrq_Hz_T_u6p10 = BilnrIntrpnWithRound_u16_u16CmnXu16MplY(
            HwTqFrq_Hz_T_u6p10,
            (uint16) *Rte_Pim_CurrInten(),
            Rte_Prm_BmwHaptcFbFrqBilnrSeln_Ary1D(),
            (uint16) TblSize_m(PrmBmwHaptcFbFrqBilnrSeln),
            Rte_Prm_BmwHaptcFbIntenSelnTblX_Ary1D(),
            Rte_Prm_BmwHaptcFbFrqSelnTblY_Ary2D(),
            (uint16) TblSize_m(PrmBmwHaptcFbIntenSelnTblX));

    *HwOscnFrq_Hz_T_f32 = FixdToFloat_f32_u16(HwOscnFrq_Hz_T_u6p10, NXTRFIXDPT_P10TOFLOAT_ULS_F32);
}


#define BmwHaptcFb_STOP_SEC_CODE
#include "BmwHaptcFb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
