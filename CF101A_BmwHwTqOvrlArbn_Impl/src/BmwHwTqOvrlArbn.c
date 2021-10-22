/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  BmwHwTqOvrlArbn.c
 *        Config:  C:/Users/nz2999/Documents/Synergy/ccm_wa/ses_dev_ea4/CF101A_BmwHwTqOvrlArbn_Impl-nz2999/CF101A_BmwHwTqOvrlArbn_Impl/tools/Component.dpa
 *     SW-C Type:  BmwHwTqOvrlArbn
 *  Generated at:  Tue Apr 17 10:49:08 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <BmwHwTqOvrlArbn>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Copyright 2018 Nxtr
 * Nxtr Confidential
 *
 * Module File Name  : BmwHwTqOvrlArbn.c
 * Module Description: CF101A Implementation - BMW Handwheel Torque Overlay Arbitration
 * Project           : CBD
 * Author            : Krzysztof Byrski
 **********************************************************************************************************************
 * Version Control:
 * %version:          1 %
 * %derived_by:       nz2999 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                             SCR #
 * --------  -------  --------  ----------------------------------------------------------------------------  ---------
 * 04/13/18  1        KByrski   Initial version (based on Design 1.0.0)                                       EA4#22038
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
 * BmwOvrlCmdQlfr1
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * DrvgDynIfSt1
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
 * u9p7
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 *********************************************************************************************************************/

#include "Rte_BmwHwTqOvrlArbn.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/************************************************ Include Statements *************************************************/
#include "ArchGlbPrm.h"
#include "NxtrFixdPt.h"
#include "NxtrIntrpn.h"
#include "NxtrMath.h"

/******************************************** File Level Rule Deviations *********************************************/
/* MISRA-C:2004 Rule 16.10 [NXTRDEV 16.10.1]: There is no appropriate action to take on the return value for Rte_Call, Rte_Read, Rte_Write */
/* MISRA-C:2004 Rule 19.1  [NXTRDEV 19.1.1]:  AUTOSAR requires deviation from this rule for Memory Mapping include statements */

/********************************************* Embedded Local Constants **********************************************/
#define CNVMILLISECTOCNT_CNTPERMILLISEC_U16     (10U)
#define ONELOOPCNT_CNT_U32                      (20U)
#define ONE_ULS_F32                             (1.0F)
#define ZERO_HWNWTMTR_F32                       (0.0F)
#define ZERO_ULS_F32                            (0.0F)

/*************************************************** Local Macros ****************************************************/
#define PrmBmwHwTqOvrlArbnVehSpdX            (*(const Ary1D_u9p7_6 *) Rte_Prm_BmwHwTqOvrlArbnVehSpdX_Ary1D())


/********************************************* Local Function Prototypes *********************************************/
static FUNC(boolean, BmwHwTqOvrlArbn_CODE) FctlErr(
        VAR(boolean, AUTOMATIC) HwTqOvrlAvl_Cnt_T_logl,
        VAR(float32, AUTOMATIC) VehSpd_Kph_T_f32,
        VAR(float32, AUTOMATIC) BmwTarHwTqOvrl_HwNwtMtr_T_f32);

static FUNC(float32, BmwHwTqOvrlArbn_CODE) HwTqOvrlArbn(
        VAR(boolean, AUTOMATIC) FctlErr_Cnt_T_logl,
        VAR(float32, AUTOMATIC) HwTqOvrl_HwNwtMtr_T_f32,
        VAR(boolean, AUTOMATIC) HwTqOvrlAvl_Cnt_T_logl);

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
 * u9p7: Integer in interval [0...65535]
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * BmwOvrlCmdQlfr1: Enumeration of integer in interval [0...255] with enumerators
 *   BMWOVRLCMDQLFR_IMPLSP (2U)
 *   BMWOVRLCMDQLFR_SPNOTAVL (7U)
 *   BMWOVRLCMDQLFR_STBDONOTCNVSP (14U)
 *   BMWOVRLCMDQLFR_INVLDSIG (15U)
 * DrvgDynIfSt1: Enumeration of integer in interval [0...255] with enumerators
 *   DRVGDYNIFST_IFAVLRDYFOROPERWOADDLDAMPG (32U)
 *   DRVGDYNIFST_IFACTVADDLDAMPGNOTAVL (33U)
 *   DRVGDYNIFST_IFAVLRDYFOROPERADDLDAMPG (34U)
 *   DRVGDYNIFST_IFACTVADDLDAMPGAVL (35U)
 *   DRVGDYNIFST_SRVNOTAVLERR (96U)
 *   DRVGDYNIFST_IFINID (128U)
 *   DRVGDYNIFST_SRVNOTAVLSTBPMA (224U)
 *   DRVGDYNIFST_SRVNOTAVLSTBEPSSTS (225U)
 *   DRVGDYNIFST_INVLDSIG (255U)
 *
 * Array Types:
 * ============
 * Ary1D_u4p12_6: Array with 6 element(s) of type u4p12
 * Ary1D_u9p7_6: Array with 6 element(s) of type u9p7
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   float32 *Rte_Pim_ArbdHwTqOvrlLtch(void)
 *   float32 *Rte_Pim_HwTqOvrlScaFacStVari(void)
 *   float32 *Rte_Pim_PrevArbdHwTqOvrl(void)
 *   uint32 *Rte_Pim_FctlErrTmr(void)
 *   boolean *Rte_Pim_FctlErrActv(void)
 *   boolean *Rte_Pim_PrevFctlErr(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_BmwHwTqOvrlArbnCmdErrThd_Val(void)
 *   float32 Rte_Prm_BmwHwTqOvrlArbnOutpTqCmdLim_Val(void)
 *   float32 Rte_Prm_BmwHwTqOvrlArbnRampRate_Val(void)
 *   uint16 Rte_Prm_BmwHwTqOvrlArbnRefTiThd_Val(void)
 *   u4p12 *Rte_Prm_BmwHwTqOvrlArbnHwTqThdY_Ary1D(void)
 *     Returnvalue: u4p12* is of type Ary1D_u4p12_6
 *   u9p7 *Rte_Prm_BmwHwTqOvrlArbnVehSpdX_Ary1D(void)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_6
 *
 *********************************************************************************************************************/


#define BmwHwTqOvrlArbn_START_SEC_CODE
#include "BmwHwTqOvrlArbn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwHwTqOvrlArbnInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwHwTqOvrlArbnInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwHwTqOvrlArbn_CODE) BmwHwTqOvrlArbnInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwHwTqOvrlArbnInit1
 *********************************************************************************************************************/

    /* Empty Init function */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwHwTqOvrlArbnPer1
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
 *   Std_ReturnType Rte_Read_BmwDrvgDynErrIfActv_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_BmwTarHwTqOvrl_Val(float32 *data)
 *   Std_ReturnType Rte_Read_BmwTarHwTqOvrlQlfr_Val(BmwOvrlCmdQlfr1 *data)
 *   Std_ReturnType Rte_Read_DrvgDynIfSt_Val(DrvgDynIfSt1 *data)
 *   Std_ReturnType Rte_Read_HwTqOvrlCmdEna_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_VehSpd_Val(float32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_HwTqCmdOvrl_Val(float32 data)
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
 * Symbol: BmwHwTqOvrlArbnPer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwHwTqOvrlArbn_CODE) BmwHwTqOvrlArbnPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwHwTqOvrlArbnPer1
 *********************************************************************************************************************/

    /* Inputs */
    VAR(boolean, AUTOMATIC) BmwDrvgDynErrIfActv_Cnt_T_logl;
    VAR(float32, AUTOMATIC) BmwTarHwTqOvrl_HwNwtMtr_T_f32;
    VAR(BmwOvrlCmdQlfr1, AUTOMATIC) BmwTarHwTqOvrlQlfr_Cnt_T_enum;
    VAR(DrvgDynIfSt1, AUTOMATIC) DrvgDynIfSt_Cnt_T_enum;
    VAR(boolean, AUTOMATIC) HwTqOvrlCmdEna_Cnt_T_logl;
    VAR(float32, AUTOMATIC) VehSpd_Kph_T_f32;

    /* Outputs */
    VAR(float32, AUTOMATIC) HwTqCmdOvrl_HwNwtMtr_T_f32;

    /* Temporary */
    VAR(boolean, AUTOMATIC) HwTqOvrlAvl_Cnt_T_logl;
    VAR(boolean, AUTOMATIC) FctlErr_Cnt_T_logl;
    VAR(float32, AUTOMATIC) ArbdHwTqOvrl_HwNwtMtr_T_f32;

    /* Read inputs */
    (void) Rte_Read_BmwDrvgDynErrIfActv_Logl(&BmwDrvgDynErrIfActv_Cnt_T_logl);
    (void) Rte_Read_BmwTarHwTqOvrl_Val(&BmwTarHwTqOvrl_HwNwtMtr_T_f32);
    (void) Rte_Read_BmwTarHwTqOvrlQlfr_Val(&BmwTarHwTqOvrlQlfr_Cnt_T_enum);
    (void) Rte_Read_DrvgDynIfSt_Val(&DrvgDynIfSt_Cnt_T_enum);
    (void) Rte_Read_HwTqOvrlCmdEna_Logl(&HwTqOvrlCmdEna_Cnt_T_logl);
    (void) Rte_Read_VehSpd_Val(&VehSpd_Kph_T_f32);

    /* CalcnHwTqOvrlAvl */
    if ((DrvgDynIfSt_Cnt_T_enum == DRVGDYNIFST_IFACTVADDLDAMPGAVL) &&
        (HwTqOvrlCmdEna_Cnt_T_logl != FALSE) &&
        (BmwDrvgDynErrIfActv_Cnt_T_logl == FALSE) &&
        (BmwTarHwTqOvrlQlfr_Cnt_T_enum == BMWOVRLCMDQLFR_IMPLSP))
    {
        HwTqOvrlAvl_Cnt_T_logl = TRUE;
    }
    else
    {
        HwTqOvrlAvl_Cnt_T_logl = FALSE;
    }

    /* FctlErr */
    FctlErr_Cnt_T_logl = FctlErr(HwTqOvrlAvl_Cnt_T_logl, VehSpd_Kph_T_f32, BmwTarHwTqOvrl_HwNwtMtr_T_f32);

    /* HwTqOvrlArbn */
    ArbdHwTqOvrl_HwNwtMtr_T_f32 = HwTqOvrlArbn(FctlErr_Cnt_T_logl, BmwTarHwTqOvrl_HwNwtMtr_T_f32, HwTqOvrlAvl_Cnt_T_logl);

    /* FinalCalcn */
    HwTqCmdOvrl_HwNwtMtr_T_f32 = Lim_f32(ArbdHwTqOvrl_HwNwtMtr_T_f32, -Rte_Prm_BmwHwTqOvrlArbnOutpTqCmdLim_Val(), Rte_Prm_BmwHwTqOvrlArbnOutpTqCmdLim_Val());

    /* Write outputs */
    (void) Rte_Write_HwTqCmdOvrl_Val(HwTqCmdOvrl_HwNwtMtr_T_f32);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define BmwHwTqOvrlArbn_STOP_SEC_CODE
#include "BmwHwTqOvrlArbn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#define BmwHwTqOvrlArbn_START_SEC_CODE
#include "BmwHwTqOvrlArbn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Name:        FctlErr
 * Description: Implementation of "FctlErr" Simulink block
 * Inputs:      HwTqOvrlAvl_Cnt_T_logl
 *              VehSpd_Kph_T_f32
 *              BmwTarHwTqOvrl_HwNwtMtr_T_f32
 * Outputs:     Rte_Pim_FctlErrActv
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(boolean, BmwHwTqOvrlArbn_CODE) FctlErr(
        VAR(boolean, AUTOMATIC) HwTqOvrlAvl_Cnt_T_logl,
        VAR(float32, AUTOMATIC) VehSpd_Kph_T_f32,
        VAR(float32, AUTOMATIC) BmwTarHwTqOvrl_HwNwtMtr_T_f32)
{
    VAR(float32, AUTOMATIC) AbsltHwTqOvrll_HwNwtMtr_T_f32;
    VAR(boolean, AUTOMATIC) ChkTiAndSetOutp_Cnt_T_logl = FALSE;
    VAR(u4p12, AUTOMATIC) HwTqThd_HwNwtMtr_T_u4p12;
    VAR(uint32, AUTOMATIC) TiSpan_Cnt_T_u32;

    if (*Rte_Pim_FctlErrActv() == FALSE)
    {
        AbsltHwTqOvrll_HwNwtMtr_T_f32 = Abslt_f32_f32(BmwTarHwTqOvrl_HwNwtMtr_T_f32);

        if ((AbsltHwTqOvrll_HwNwtMtr_T_f32 > Rte_Prm_BmwHwTqOvrlArbnCmdErrThd_Val()) && (HwTqOvrlAvl_Cnt_T_logl == FALSE))
        {
            ChkTiAndSetOutp_Cnt_T_logl = TRUE;
        }
        else
        {
            HwTqThd_HwNwtMtr_T_u4p12 = LnrIntrpn_u16_u16VariXu16VariY(
                    Rte_Prm_BmwHwTqOvrlArbnVehSpdX_Ary1D(),
                    Rte_Prm_BmwHwTqOvrlArbnHwTqThdY_Ary1D(),
                    (uint16) TblSize_m(PrmBmwHwTqOvrlArbnVehSpdX),
                    FloatToFixd_u16_f32(VehSpd_Kph_T_f32, NXTRFIXDPT_FLOATTOP7_ULS_F32));

            if (AbsltHwTqOvrll_HwNwtMtr_T_f32 > FixdToFloat_f32_u16(HwTqThd_HwNwtMtr_T_u4p12, NXTRFIXDPT_P12TOFLOAT_ULS_F32))
            {
                ChkTiAndSetOutp_Cnt_T_logl = TRUE;
            }
        }

        if (ChkTiAndSetOutp_Cnt_T_logl != FALSE)
        {
            /* ChkTiAndSetOutp */
            (void) Rte_Call_GetTiSpan100MicroSec32bit_Oper(*Rte_Pim_FctlErrTmr(), &TiSpan_Cnt_T_u32);

            if (TiSpan_Cnt_T_u32 >= ((uint32) Rte_Prm_BmwHwTqOvrlArbnRefTiThd_Val() * (uint32) CNVMILLISECTOCNT_CNTPERMILLISEC_U16))
            {
                *Rte_Pim_FctlErrActv() = TRUE;
            }
        }
        else
        {
            /* UpdTiAndSetFalse */
            (void) Rte_Call_GetRefTmr100MicroSec32bit_Oper(Rte_Pim_FctlErrTmr());
            *Rte_Pim_FctlErrTmr() += ONELOOPCNT_CNT_U32;
        }
    }

    return *Rte_Pim_FctlErrActv();
}

/**********************************************************************************************************************
 * Name:        HwTqOvrlArbn
 * Description: Implementation of "HwTqOvrlArbn" Simulink block
 * Inputs:      FctlErr_Cnt_T_logl
 *              HwTqOvrl_HwNwtMtr_T_f32
 *              HwTqOvrlAvl_Cnt_T_logl
 * Outputs:     ArbdHwTqOvrl_HwNwtMtr_T_f32
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(float32, BmwHwTqOvrlArbn_CODE) HwTqOvrlArbn(
        VAR(boolean, AUTOMATIC) FctlErr_Cnt_T_logl,
        VAR(float32, AUTOMATIC) HwTqOvrl_HwNwtMtr_T_f32,
        VAR(boolean, AUTOMATIC) HwTqOvrlAvl_Cnt_T_logl)
{
    VAR(float32, AUTOMATIC) ArbdHwTqOvrl_HwNwtMtr_T_f32;
    VAR(float32, AUTOMATIC) HwTqOvrlScaFac_Uls_T_f32;
    VAR(float32, AUTOMATIC) PreFinalHwTqOvrl_HwNwtMtr_T_f32;

    if (FctlErr_Cnt_T_logl != *Rte_Pim_PrevFctlErr())
    {
        /* TranDetn */
        *Rte_Pim_ArbdHwTqOvrlLtch() = *Rte_Pim_PrevArbdHwTqOvrl();
    }
    *Rte_Pim_PrevFctlErr() = FctlErr_Cnt_T_logl;

    if (HwTqOvrlAvl_Cnt_T_logl != FALSE)
    {
        /* PassHwTqOvrl */
        if (FctlErr_Cnt_T_logl != FALSE)
        {
            /* FacOne */
            HwTqOvrlScaFac_Uls_T_f32 = ONE_ULS_F32;
            PreFinalHwTqOvrl_HwNwtMtr_T_f32 = *Rte_Pim_ArbdHwTqOvrlLtch();
        }
        else
        {
            /* FacZero */
            HwTqOvrlScaFac_Uls_T_f32 = ZERO_ULS_F32;
            PreFinalHwTqOvrl_HwNwtMtr_T_f32 = HwTqOvrl_HwNwtMtr_T_f32;
        }

        *Rte_Pim_HwTqOvrlScaFacStVari() = Lim_f32(
                HwTqOvrlScaFac_Uls_T_f32,
                *Rte_Pim_HwTqOvrlScaFacStVari() - (Rte_Prm_BmwHwTqOvrlArbnRampRate_Val() * ARCHGLBPRM_2MILLISEC_SEC_F32),
                *Rte_Pim_HwTqOvrlScaFacStVari() + (Rte_Prm_BmwHwTqOvrlArbnRampRate_Val() * ARCHGLBPRM_2MILLISEC_SEC_F32));

        ArbdHwTqOvrl_HwNwtMtr_T_f32 = (ONE_ULS_F32 - *Rte_Pim_HwTqOvrlScaFacStVari()) * PreFinalHwTqOvrl_HwNwtMtr_T_f32;
    }
    else
    {
        /* PassZero */
        ArbdHwTqOvrl_HwNwtMtr_T_f32 = ZERO_HWNWTMTR_F32;
    }

    *Rte_Pim_PrevArbdHwTqOvrl() = ArbdHwTqOvrl_HwNwtMtr_T_f32;

    return ArbdHwTqOvrl_HwNwtMtr_T_f32;
}


#define BmwHwTqOvrlArbn_STOP_SEC_CODE
#include "BmwHwTqOvrlArbn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
