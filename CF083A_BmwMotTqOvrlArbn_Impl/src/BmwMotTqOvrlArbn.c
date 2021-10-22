/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  BmwMotTqOvrlArbn.c
 *        Config:  C:/Users/nz2999/Documents/Synergy/ccm_wa/ses_dev_ea4/CF083A_BmwMotTqOvrlArbn_Impl-nz2999/CF083A_BmwMotTqOvrlArbn_Impl/tools/Component.dpa
 *     SW-C Type:  BmwMotTqOvrlArbn
 *  Generated at:  Tue Jul  3 10:29:19 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <BmwMotTqOvrlArbn>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Copyright 2018 Nxtr
 * Nxtr Confidential
 *
 * Module File Name  : BmwMotTqOvrlArbn.c
 * Module Description: Implementation of CF083A - BmwMotTqOvrlArbn
 * Project           : CBD
 * Author            : Krzysztof Byrski
 **********************************************************************************************************************
 * Version Control:
 * %version:          4 %
 * %derived_by:       nz2999 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                             SCR #
 * --------  -------  --------  ----------------------------------------------------------------------------  ---------
 * 02/28/18  1        KByrski   Initial version (based on Design 1.0.1)                                       EA4#20723
 * 04/04/18  2        KByrski   Updated to Design 2.0.0                                                       EA4#21983
 * 06/22/18  3        KByrski   Resolving Anomaly EA4#24536                                                   EA4#25327
 * 07/03/18  4        KByrski   Updated to Design 3.0.0                                                       EA4#25257
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
 * BmwNearStillVehSpdSts1
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
 *********************************************************************************************************************/

#include "Rte_BmwMotTqOvrlArbn.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/************************************************ Include Statements *************************************************/
#include "Dcm.h"
#include "NxtrMath.h"
#include "SysGlbPrm.h"

/******************************************** File Level Rule Deviations *********************************************/
/* MISRA-C:2004 Rule 16.10 [NXTRDEV 16.10.1]: There is no appropriate action to take on the return value for: Rte_Call, Rte_Read, Rte_Write */
/* MISRA-C:2004 Rule 19.1  [NXTRDEV 19.1.1]:  AUTOSAR requires deviation from this rule for Memory Mapping include statements */

/********************************************* Embedded Local Constants **********************************************/
#define CNVMILLISECTOCNT_CNTPERMILLISEC_U16   (10U)
#define TWENTYCNT_CNT_U32                     (20U)
#define ZERO_MOTNWTMTR_F32                    (0.0F)

/********************************************* Local Function Prototypes *********************************************/
static FUNC(void, BmwMotTqOvrlArbn_CODE) ChkForFctlErr(
        VAR(boolean, AUTOMATIC) MfgModActv_Cnt_T_logl,
        VAR(BmwNearStillVehSpdSts1, AUTOMATIC) BmwNearStillVehSpdSts_Cnt_T_enum,
        VAR(float32, AUTOMATIC) VehSpd_Kph_T_f32,
        VAR(float32, AUTOMATIC) MfgModCmd_MotNwtMtr_T_f32);

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
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * BmwNearStillVehSpdSts1: Enumeration of integer in interval [0...255] with enumerators
 *   BMWNEARSTILLVEHSPDSTS_VEHREST (12U)
 *   BMWNEARSTILLVEHSPDSTS_VEHNOTREST (13U)
 *   BMWNEARSTILLVEHSPDSTS_INVLD (15U)
 * BmwTrfcJamAssiSt1: Enumeration of integer in interval [0...255] with enumerators
 *   BMWTRFCJAMASSIST_INACTV (1U)
 *   BMWTRFCJAMASSIST_ACTV (2U)
 *   BMWTRFCJAMASSIST_INVLD (15U)
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   uint32 *Rte_Pim_BmwNearStillVehSpdStsCdnRefTi(void)
 *   uint32 *Rte_Pim_MfgModCmdCdnRefTi(void)
 *   uint32 *Rte_Pim_VehSpdCdnRefTi(void)
 *   boolean *Rte_Pim_FctlErrStVari(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_BmwMotTqOvrlArbnMfgModCmdThd_Val(void)
 *   float32 Rte_Prm_BmwMotTqOvrlArbnMfgModVehSpdThd_Val(void)
 *   float32 Rte_Prm_BmwMotTqOvrlArbnPullCmpCmdLim_Val(void)
 *   uint16 Rte_Prm_BmwMotTqOvrlArbnBmwNearStillVehSpdStsRefTiThd_Val(void)
 *   uint16 Rte_Prm_BmwMotTqOvrlArbnMfgModCmdRefTiThd_Val(void)
 *   uint16 Rte_Prm_BmwMotTqOvrlArbnVehSpdRefTiThd_Val(void)
 *
 *********************************************************************************************************************/


#define BmwMotTqOvrlArbn_START_SEC_CODE
#include "BmwMotTqOvrlArbn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwMotTqOvrlArbnInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwMotTqOvrlArbnInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwMotTqOvrlArbn_CODE) BmwMotTqOvrlArbnInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwMotTqOvrlArbnInit1
 *********************************************************************************************************************/

    /* Empty Init function */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwMotTqOvrlArbnPer1
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
 *   Std_ReturnType Rte_Read_BmwNearStillVehSpdSts_Val(BmwNearStillVehSpdSts1 *data)
 *   Std_ReturnType Rte_Read_BmwOutpTqOvrlCmd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_BmwTrfcJamAssiDampgSt_Val(BmwTrfcJamAssiSt1 *data)
 *   Std_ReturnType Rte_Read_DrvgDynActv_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_HwOscnActv_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_HwOscnCmd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_HwOscnDcThdExcdd_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_PinionCentrLrnCmd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_PinionCentrLrnEna_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_PosnServoCmd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_PosnServoEna_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_PullCmpCmd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_TrfcJamAssiCmd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_VehSpd_Val(float32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_MotTqOvrlCmd_Val(float32 data)
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
 * Symbol: BmwMotTqOvrlArbnPer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwMotTqOvrlArbn_CODE) BmwMotTqOvrlArbnPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwMotTqOvrlArbnPer1
 *********************************************************************************************************************/

    /* Inputs */
    VAR(BmwNearStillVehSpdSts1, AUTOMATIC) BmwNearStillVehSpdSts_Cnt_T_enum;
    VAR(float32, AUTOMATIC) BmwOutpTqOvrlCmd_MotNwtMtr_T_f32;
    VAR(BmwTrfcJamAssiSt1, AUTOMATIC) BmwTrfcJamAssiDampgSt_Cnt_T_enum;
    VAR(boolean, AUTOMATIC) DrvgDynActv_Cnt_T_logl;
    VAR(boolean, AUTOMATIC) HwOscnActv_Cnt_T_logl;
    VAR(float32, AUTOMATIC) HwOscnCmd_MotNwtMtr_T_f32;
    VAR(boolean, AUTOMATIC) HwOscnDcThdExcdd_Cnt_T_logl;
    VAR(float32, AUTOMATIC) PinionCentrLrnCmd_MotNwtMtr_T_f32;
    VAR(boolean, AUTOMATIC) PinionCentrLrnEna_Cnt_T_logl;
    VAR(float32, AUTOMATIC) PosnServoCmd_MotNwtMtr_T_f32;
    VAR(boolean, AUTOMATIC) PosnServoEna_Cnt_T_logl;
    VAR(float32, AUTOMATIC) PullCmpCmd_MotNwtMtr_T_f32;
    VAR(float32, AUTOMATIC) TrfcJamAssiCmd_MotNwtMtr_T_f32;
    VAR(float32, AUTOMATIC) VehSpd_Kph_T_f32;

    /* Outputs */
    VAR(float32, AUTOMATIC) MotTqOvrlCmd_MotNwtMtr_T_f32;

    /* Temporary */
    VAR(Dcm_SesCtrlType, AUTOMATIC) SesCtrlType_Cnt_T_enum = DCM_DEFAULT_SESSION;
    VAR(boolean, AUTOMATIC) MfgModActv_Cnt_T_logl;
    VAR(float32, AUTOMATIC) MfgModCmd_MotNwtMtr_T_f32;
    VAR(float32, AUTOMATIC) AddlTqOvrlCmd_MotNwtMtr_T_f32;

    /* Read inputs */
    (void) Rte_Read_BmwNearStillVehSpdSts_Val(&BmwNearStillVehSpdSts_Cnt_T_enum);
    (void) Rte_Read_BmwOutpTqOvrlCmd_Val(&BmwOutpTqOvrlCmd_MotNwtMtr_T_f32);
    (void) Rte_Read_BmwTrfcJamAssiDampgSt_Val(&BmwTrfcJamAssiDampgSt_Cnt_T_enum);
    (void) Rte_Read_DrvgDynActv_Logl(&DrvgDynActv_Cnt_T_logl);
    (void) Rte_Read_HwOscnActv_Logl(&HwOscnActv_Cnt_T_logl);
    (void) Rte_Read_HwOscnCmd_Val(&HwOscnCmd_MotNwtMtr_T_f32);
    (void) Rte_Read_HwOscnDcThdExcdd_Logl(&HwOscnDcThdExcdd_Cnt_T_logl);
    (void) Rte_Read_PinionCentrLrnCmd_Val(&PinionCentrLrnCmd_MotNwtMtr_T_f32);
    (void) Rte_Read_PinionCentrLrnEna_Logl(&PinionCentrLrnEna_Cnt_T_logl);
    (void) Rte_Read_PosnServoCmd_Val(&PosnServoCmd_MotNwtMtr_T_f32);
    (void) Rte_Read_PosnServoEna_Logl(&PosnServoEna_Cnt_T_logl);
    (void) Rte_Read_PullCmpCmd_Val(&PullCmpCmd_MotNwtMtr_T_f32);
    (void) Rte_Read_TrfcJamAssiCmd_Val(&TrfcJamAssiCmd_MotNwtMtr_T_f32);
    (void) Rte_Read_VehSpd_Val(&VehSpd_Kph_T_f32);

    (void) Dcm_GetSesCtrlType(&SesCtrlType_Cnt_T_enum);

    /* CalcnMfgModActv */
    MfgModActv_Cnt_T_logl = (SesCtrlType_Cnt_T_enum == DCM_GarageMode) ? TRUE : FALSE;

    /* CalcnMfgModCmd */
    if (PosnServoEna_Cnt_T_logl != PinionCentrLrnEna_Cnt_T_logl)
    {
        /* CheckWhichSig */
        if (PosnServoEna_Cnt_T_logl != FALSE)
        {
            /* PassPosnServCmd */
            MfgModCmd_MotNwtMtr_T_f32 = PosnServoCmd_MotNwtMtr_T_f32;
        }
        else
        {
            /* PassPinionCentrLrnCmd */
            MfgModCmd_MotNwtMtr_T_f32 = PinionCentrLrnCmd_MotNwtMtr_T_f32;
        }
    }
    else
    {
        /* Invld */
        MfgModCmd_MotNwtMtr_T_f32 = ZERO_MOTNWTMTR_F32;
    }

    /* ChkForFctlErr */
    ChkForFctlErr(
            MfgModActv_Cnt_T_logl,
            BmwNearStillVehSpdSts_Cnt_T_enum,
            VehSpd_Kph_T_f32,
            MfgModCmd_MotNwtMtr_T_f32);

    /* CalcnMotTqOvrlCmd */
    if ((MfgModActv_Cnt_T_logl != FALSE) && (*Rte_Pim_FctlErrStVari() == FALSE))
    {
        /* PassMfgModCmd */
        MotTqOvrlCmd_MotNwtMtr_T_f32 = MfgModCmd_MotNwtMtr_T_f32;
    }
    else if ((MfgModActv_Cnt_T_logl == FALSE) && (DrvgDynActv_Cnt_T_logl != FALSE))
    {
        /* CalcnAddlTqOvrlCmd */
        AddlTqOvrlCmd_MotNwtMtr_T_f32 = BmwOutpTqOvrlCmd_MotNwtMtr_T_f32;
        if (BmwTrfcJamAssiDampgSt_Cnt_T_enum == BMWTRFCJAMASSIST_ACTV)
        {
            /* PassTrfcJamAssiCmd */
            AddlTqOvrlCmd_MotNwtMtr_T_f32 += TrfcJamAssiCmd_MotNwtMtr_T_f32;
        }
        if ((HwOscnActv_Cnt_T_logl != FALSE) && (HwOscnDcThdExcdd_Cnt_T_logl == FALSE))
        {
            /* PassHwOscnCmd */
            AddlTqOvrlCmd_MotNwtMtr_T_f32 += HwOscnCmd_MotNwtMtr_T_f32;
        }

        /* PassAddlTqOvrlCmd */
        MotTqOvrlCmd_MotNwtMtr_T_f32 = AddlTqOvrlCmd_MotNwtMtr_T_f32;
    }
    else
    {
        /* OutpZero */
        MotTqOvrlCmd_MotNwtMtr_T_f32 = ZERO_MOTNWTMTR_F32;
    }

    /* AddLimdPullCmpCmd */
    MotTqOvrlCmd_MotNwtMtr_T_f32 += Lim_f32(
            PullCmpCmd_MotNwtMtr_T_f32,
            -Rte_Prm_BmwMotTqOvrlArbnPullCmpCmdLim_Val(),
            Rte_Prm_BmwMotTqOvrlArbnPullCmpCmdLim_Val());

    MotTqOvrlCmd_MotNwtMtr_T_f32 = Lim_f32(
            MotTqOvrlCmd_MotNwtMtr_T_f32,
            SYSGLBPRM_MOTTQCMDLOLIM_MOTNWTMTR_F32,
            SYSGLBPRM_MOTTQCMDHILIM_MOTNWTMTR_F32);

    /* Write outputs */
    (void) Rte_Write_MotTqOvrlCmd_Val(MotTqOvrlCmd_MotNwtMtr_T_f32);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define BmwMotTqOvrlArbn_STOP_SEC_CODE
#include "BmwMotTqOvrlArbn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#define BmwMotTqOvrlArbn_START_SEC_CODE
#include "BmwMotTqOvrlArbn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Name:        ChkForFctlErr
 * Description: Implementation of "ChkForFctlErr" FDD block
 * Inputs:      MfgModActv_Cnt_T_logl
 *              BmwNearStillVehSpdSts_Cnt_T_enum
 *              VehSpd_Kph_T_f32
 *              MfgModCmd_MotNwtMtr_T_f32
 * Outputs:     Rte_Pim_FctlErrStVari
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(void, BmwMotTqOvrlArbn_CODE) ChkForFctlErr(
        VAR(boolean, AUTOMATIC) MfgModActv_Cnt_T_logl,
        VAR(BmwNearStillVehSpdSts1, AUTOMATIC) BmwNearStillVehSpdSts_Cnt_T_enum,
        VAR(float32, AUTOMATIC) VehSpd_Kph_T_f32,
        VAR(float32, AUTOMATIC) MfgModCmd_MotNwtMtr_T_f32)
{
    /* Temporary */
    VAR(uint32, AUTOMATIC) TiSpan_Cnt_T_u32;

    /* CalcnVehSpdCdnTrig */
    if ((MfgModActv_Cnt_T_logl != FALSE) && (VehSpd_Kph_T_f32 > Rte_Prm_BmwMotTqOvrlArbnMfgModVehSpdThd_Val()))
    {
        /* ChkTiAndSetOutp */
        (void) Rte_Call_GetTiSpan100MicroSec32bit_Oper(*Rte_Pim_VehSpdCdnRefTi(), &TiSpan_Cnt_T_u32);

        if (TiSpan_Cnt_T_u32 >= ((uint32) Rte_Prm_BmwMotTqOvrlArbnVehSpdRefTiThd_Val() * (uint32) CNVMILLISECTOCNT_CNTPERMILLISEC_U16))
        {
            *Rte_Pim_FctlErrStVari() = TRUE;
        }
    }
    else
    {
        /* UpdTiAndSetFalse */
        (void) Rte_Call_GetRefTmr100MicroSec32bit_Oper(Rte_Pim_VehSpdCdnRefTi());
        *Rte_Pim_VehSpdCdnRefTi() += TWENTYCNT_CNT_U32;
    }

    /* CalcnBmwNearStillVehSpdStsTrig */
    if ((MfgModActv_Cnt_T_logl != FALSE) && (BmwNearStillVehSpdSts_Cnt_T_enum != BMWNEARSTILLVEHSPDSTS_VEHREST))
    {
        /* ChkTiAndSetOutp */
        (void) Rte_Call_GetTiSpan100MicroSec32bit_Oper(*Rte_Pim_BmwNearStillVehSpdStsCdnRefTi(), &TiSpan_Cnt_T_u32);

        if (TiSpan_Cnt_T_u32 >= ((uint32) Rte_Prm_BmwMotTqOvrlArbnBmwNearStillVehSpdStsRefTiThd_Val() * (uint32) CNVMILLISECTOCNT_CNTPERMILLISEC_U16))
        {
            *Rte_Pim_FctlErrStVari() = TRUE;
        }
    }
    else
    {
        /* UpdTiAndSetFalse */
        (void) Rte_Call_GetRefTmr100MicroSec32bit_Oper(Rte_Pim_BmwNearStillVehSpdStsCdnRefTi());
        *Rte_Pim_BmwNearStillVehSpdStsCdnRefTi() += TWENTYCNT_CNT_U32;
    }

    /* CalcnMfgModCmdTrig */
    if ((Abslt_f32_f32(MfgModCmd_MotNwtMtr_T_f32) > Rte_Prm_BmwMotTqOvrlArbnMfgModCmdThd_Val()) && (MfgModActv_Cnt_T_logl == FALSE))
    {
        /* ChkTiAndSetOutp */
        (void) Rte_Call_GetTiSpan100MicroSec32bit_Oper(*Rte_Pim_MfgModCmdCdnRefTi(), &TiSpan_Cnt_T_u32);

        if (TiSpan_Cnt_T_u32 >= ((uint32) Rte_Prm_BmwMotTqOvrlArbnMfgModCmdRefTiThd_Val() * (uint32) CNVMILLISECTOCNT_CNTPERMILLISEC_U16))
        {
            *Rte_Pim_FctlErrStVari() = TRUE;
        }
    }
    else
    {
        /* UpdTiAndSetFalse */
        (void) Rte_Call_GetRefTmr100MicroSec32bit_Oper(Rte_Pim_MfgModCmdCdnRefTi());
        *Rte_Pim_MfgModCmdCdnRefTi() += TWENTYCNT_CNT_U32;
    }
}

#define BmwMotTqOvrlArbn_STOP_SEC_CODE
#include "BmwMotTqOvrlArbn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
