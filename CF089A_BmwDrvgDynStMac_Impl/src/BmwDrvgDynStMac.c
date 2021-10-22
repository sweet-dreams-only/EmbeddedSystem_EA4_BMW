/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  BmwDrvgDynStMac.c
 *        Config:  C:/_S/work/ses_dev_ea4/CF089A_BmwDrvgDynStMac_Impl-z172399/CF089A_BmwDrvgDynStMac_Impl/tools/Component.dpa
 *     SW-C Type:  BmwDrvgDynStMac
 *  Generated at:  Thu Jun 28 10:48:30 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <BmwDrvgDynStMac>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Copyright 2018 Nxtr
 * Nxtr Confidential
 *
 * Module File Name  : BmwDrvgDynStMac.c
 * Module Description: CF089A Implementation - BMW Driving Dynamics State Machine
 * Project           : CBD
 * Author            : Krzysztof Byrski
 **********************************************************************************************************************
 * Version Control:
 * %version:          2 %
 * %derived_by:       z172399 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                             SCR #
 * --------  -------  --------  ----------------------------------------------------------------------------  ---------
 * 04/17/18  1        KByrski   Initial version (based on Design 1.0.0)                                       EA4#22366
 * 06/28/18  2        BrykczyM  Update per the Design 1.1.0                                                   EA4#25416
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
 * BmwTrfcJamAssiDampgStReq1
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * BmwVehCdn1
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
 * StsSteerAssi1
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 *********************************************************************************************************************/

#include "Rte_BmwDrvgDynStMac.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/************************************************ Include Statements *************************************************/
#include "ArchGlbPrm.h"
#include "NxtrMath.h"

/******************************************** File Level Rule Deviations *********************************************/
/* MISRA-C:2004 Rule 16.10 [NXTRDEV 16.10.1]: There is no appropriate action to take on the return value for Rte_Call, Rte_Read, Rte_Write */
/* MISRA-C:2004 Rule 19.1  [NXTRDEV 19.1.1]:  AUTOSAR requires deviation from this rule for Memory Mapping include statements */

/********************************************* Embedded Local Constants **********************************************/
#define CNVMILLISECTOCNT_CNTPERMILLISEC_U16     (10U)
#define FLOATZEROTHD_MOTNWTMTR_F32              (1.1920929e-07F)

/********************************************* Local Function Prototypes *********************************************/
static FUNC(boolean, BmwDrvgDynStMac_CODE) DetermineErrorMode(
        VAR(boolean,       AUTOMATIC) SysStFltOutpReqDi_Cnt_T_logl,
        VAR(boolean,       AUTOMATIC) DiagcStsNonRcvrlReqDiFltPrsnt_Cnt_T_logl,
        VAR(boolean,       AUTOMATIC) DiagcStsCtrldShtDwnFltPrsnt_Cnt_T_logl,
        VAR(StsSteerAssi1, AUTOMATIC) StsSteerAssi_Cnt_T_enum,
        VAR(BmwVehCdn1,    AUTOMATIC) BmwVehCdn_Cnt_T_enum);

static FUNC(boolean, BmwDrvgDynStMac_CODE) Fac(
        VAR(float32, AUTOMATIC) EffortCmdSca_Uls_T_f32,
        VAR(float32, AUTOMATIC) DampgCmdSca_Uls_T_f32,
        VAR(float32, AUTOMATIC) RtnCmdSca_Uls_T_f32);

static FUNC(void, BmwDrvgDynStMac_CODE) AssiLvlCnd(
        VAR(float32,   AUTOMATIC) MotTqCmdPwrLimd_MotNwtMtr_T_f32,
        P2VAR(boolean, AUTOMATIC, BmwDrvgDynStMac_VAR) MotTqCmdPwrLimdActvtUppr_Cnt_T_logl,
        P2VAR(boolean, AUTOMATIC, BmwDrvgDynStMac_VAR) MotTqCmdPwrLimdActvtLowr_Cnt_T_logl,
        P2VAR(boolean, AUTOMATIC, BmwDrvgDynStMac_VAR) MotTqCmdPwrLimdDeactvtLowr_Cnt_T_logl);

static FUNC(boolean, BmwDrvgDynStMac_CODE) CheckActivityTime(
        VAR(boolean, AUTOMATIC) MotTqCmdPwrLimdCdnActvt_Cnt_T_logl);

static FUNC(boolean, BmwDrvgDynStMac_CODE) CheckDeactivateTime(
        VAR(boolean, AUTOMATIC) MotTqCmdPwrLimdCdnDeactvt_Cnt_T_logl);

static FUNC(boolean, BmwDrvgDynStMac_CODE) ErrorIfTi(
        VAR(boolean, AUTOMATIC) ErrIf_Cnt_T_logl);

static FUNC(void, BmwDrvgDynStMac_CODE) StateMachine(
        VAR(boolean, AUTOMATIC) ErrMod_Cnt_T_logl,
        VAR(boolean, AUTOMATIC) AllwTran_Cnt_T_logl,
        VAR(boolean, AUTOMATIC) ErrIf_Cnt_T_logl,
        VAR(BmwOvrlCmdQlfr1, AUTOMATIC) BmwTarHwTqOvrlQlfr_Cnt_T_enum,
        VAR(BmwOvrlCmdQlfr1, AUTOMATIC) BmwDrvgDynFacQlfr_Cnt_T_enum,
        VAR(BmwOvrlCmdQlfr1, AUTOMATIC) BmwTarSteerTqDrvrActrQlfr_Cnt_T_enum,
        VAR(BmwTrfcJamAssiDampgStReq1, AUTOMATIC) BmwTrfcJamAssiDampgStReq_Cnt_T_enum,
        VAR(boolean, AUTOMATIC) Fac_Cnt_T_logl,
        VAR(boolean, AUTOMATIC) MotTqCmdOvrlEquZero_Cnt_T_logl,
        VAR(float32, AUTOMATIC) MotTqCmdPwrLimd_MotNwtMtr_T_f32);

static FUNC(void, BmwDrvgDynStMac_CODE) StateMachineInit(
        VAR(boolean, AUTOMATIC) ErrMod_Cnt_T_logl,
        VAR(boolean, AUTOMATIC) AllwTran_Cnt_T_logl,
        VAR(boolean, AUTOMATIC) ErrIf_Cnt_T_logl,
        VAR(BmwOvrlCmdQlfr1, AUTOMATIC) BmwTarHwTqOvrlQlfr_Cnt_T_enum,
        VAR(BmwOvrlCmdQlfr1, AUTOMATIC) BmwDrvgDynFacQlfr_Cnt_T_enum,
        VAR(BmwOvrlCmdQlfr1, AUTOMATIC) BmwTarSteerTqDrvrActrQlfr_Cnt_T_enum,
        VAR(BmwTrfcJamAssiDampgStReq1, AUTOMATIC) BmwTrfcJamAssiDampgStReq_Cnt_T_enum,
        VAR(boolean, AUTOMATIC) MotTqCmdPwrLimdActvtUppr_Cnt_T_logl,
        VAR(boolean, AUTOMATIC) MotTqCmdPwrLimdActvtLowr_Cnt_T_logl);

static FUNC(void, BmwDrvgDynStMac_CODE) StateMachineIfAvl(
        VAR(boolean, AUTOMATIC) ErrMod_Cnt_T_logl,
        VAR(boolean, AUTOMATIC) AllwTran_Cnt_T_logl,
        VAR(boolean, AUTOMATIC) ErrIf_Cnt_T_logl,
        VAR(BmwOvrlCmdQlfr1, AUTOMATIC) BmwTarHwTqOvrlQlfr_Cnt_T_enum,
        VAR(BmwOvrlCmdQlfr1, AUTOMATIC) BmwDrvgDynFacQlfr_Cnt_T_enum,
        VAR(BmwOvrlCmdQlfr1, AUTOMATIC) BmwTarSteerTqDrvrActrQlfr_Cnt_T_enum,
        VAR(BmwTrfcJamAssiDampgStReq1, AUTOMATIC) BmwTrfcJamAssiDampgStReq_Cnt_T_enum,
        VAR(boolean, AUTOMATIC) MotTqCmdPwrLimdDeactvtLowr_Cnt_T_logl);

static FUNC(void, BmwDrvgDynStMac_CODE) StateMachineIfActv(
        VAR(boolean, AUTOMATIC) ErrMod_Cnt_T_logl,
        VAR(boolean, AUTOMATIC) AllwTran_Cnt_T_logl,
        VAR(boolean, AUTOMATIC) ErrIf_Cnt_T_logl,
        VAR(BmwOvrlCmdQlfr1, AUTOMATIC) BmwTarHwTqOvrlQlfr_Cnt_T_enum,
        VAR(BmwOvrlCmdQlfr1, AUTOMATIC) BmwDrvgDynFacQlfr_Cnt_T_enum,
        VAR(BmwOvrlCmdQlfr1, AUTOMATIC) BmwTarSteerTqDrvrActrQlfr_Cnt_T_enum,
        VAR(BmwTrfcJamAssiDampgStReq1, AUTOMATIC) BmwTrfcJamAssiDampgStReq_Cnt_T_enum,
        VAR(boolean, AUTOMATIC) ErrIfTi_Cnt_T_logl);

static FUNC(void, BmwDrvgDynStMac_CODE) StateMachineStbEpsSts(
        VAR(boolean, AUTOMATIC) ErrMod_Cnt_T_logl,
        VAR(boolean, AUTOMATIC) AllwTran_Cnt_T_logl,
        VAR(boolean, AUTOMATIC) ErrIf_Cnt_T_logl,
        VAR(BmwOvrlCmdQlfr1, AUTOMATIC) BmwTarHwTqOvrlQlfr_Cnt_T_enum,
        VAR(BmwOvrlCmdQlfr1, AUTOMATIC) BmwDrvgDynFacQlfr_Cnt_T_enum,
        VAR(BmwOvrlCmdQlfr1, AUTOMATIC) BmwTarSteerTqDrvrActrQlfr_Cnt_T_enum,
        VAR(BmwTrfcJamAssiDampgStReq1, AUTOMATIC) BmwTrfcJamAssiDampgStReq_Cnt_T_enum,
        VAR(boolean, AUTOMATIC) Fac_Cnt_T_logl,
        VAR(boolean, AUTOMATIC) MotTqCmdOvrlEquZero_Cnt_T_logl,
        VAR(boolean, AUTOMATIC) MotTqCmdPwrLimdActvtUppr_Cnt_T_logl);

static FUNC(void, BmwDrvgDynStMac_CODE) StateMachineEntry(
        P2VAR(boolean,      AUTOMATIC, BmwDrvgDynStMac_VAR) DrvgDynActv_Cnt_T_logl,
        P2VAR(DrvgDynIfSt1, AUTOMATIC, BmwDrvgDynStMac_VAR) DrvgDynIfSt_Cnt_T_enum,
        P2VAR(boolean,      AUTOMATIC, BmwDrvgDynStMac_VAR) OutpTqOvrlRampInEna_Cnt_T_logl);

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
 * BmwOvrlCmdQlfr1: Enumeration of integer in interval [0...255] with enumerators
 *   BMWOVRLCMDQLFR_IMPLSP (2U)
 *   BMWOVRLCMDQLFR_SPNOTAVL (7U)
 *   BMWOVRLCMDQLFR_STBDONOTCNVSP (14U)
 *   BMWOVRLCMDQLFR_INVLDSIG (15U)
 * BmwTrfcJamAssiDampgStReq1: Enumeration of integer in interval [0...255] with enumerators
 *   BMWTRFCJAMASSIDAMPGSTREQ_DONOTCNVSPADDLDAMPG (1U)
 *   BMWTRFCJAMASSIDAMPGSTREQ_CNVSPADDLDAMPG (2U)
 *   BMWTRFCJAMASSIDAMPGSTREQ_INVLDSIG (15U)
 * BmwVehCdn1: Enumeration of integer in interval [0...255] with enumerators
 *   BMWVEHCDN_PRKGNBNOK (1U)
 *   BMWVEHCDN_PRKGBNOK (2U)
 *   BMWVEHCDN_FCTCUSTNOTINFZG (3U)
 *   BMWVEHCDN_LVNG (5U)
 *   BMWVEHCDN_CHKDIAGCANLS (7U)
 *   BMWVEHCDN_DRVRPREPGFOROPER (8U)
 *   BMWVEHCDN_DRVG (10U)
 *   BMWVEHCDN_DRVRPREPGFOREXITOPER (12U)
 *   BMWVEHCDN_INVLD (15U)
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
 * StsSteerAssi1: Enumeration of integer in interval [0...255] with enumerators
 *   STSSTEERASSI_OFF (0U)
 *   STSSTEERASSI_ON (1U)
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   uint32 *Rte_Pim_AssiLvlActvtTi(void)
 *   uint32 *Rte_Pim_AssiLvlDeactvtTi(void)
 *   uint32 *Rte_Pim_ErrIfTi(void)
 *   uint32 *Rte_Pim_VehCdnTi(void)
 *   uint8 *Rte_Pim_StMacSt(void)
 *   boolean *Rte_Pim_MotTqCmdPwrLimdCdnActvt(void)
 *   boolean *Rte_Pim_MotTqCmdPwrLimdCdnDeactvt(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_BmwDrvgDynStMacDampgCmdScaDft_Val(void)
 *   float32 Rte_Prm_BmwDrvgDynStMacEffortCmdScaDft_Val(void)
 *   float32 Rte_Prm_BmwDrvgDynStMacMotTqCmdOvrlActvtThd_Val(void)
 *   float32 Rte_Prm_BmwDrvgDynStMacMotTqCmdOvrlDeactvtThd_Val(void)
 *   float32 Rte_Prm_BmwDrvgDynStMacRtnCmdScaDft_Val(void)
 *   uint16 Rte_Prm_BmwDrvgDynStMacAssiLvlThd_Val(void)
 *   uint16 Rte_Prm_BmwDrvgDynStMacErrIfTmrThd_Val(void)
 *   uint16 Rte_Prm_BmwDrvgDynStMacVehCdnTmrThd_Val(void)
 *
 *********************************************************************************************************************/


#define BmwDrvgDynStMac_START_SEC_CODE
#include "BmwDrvgDynStMac_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwDrvgDynStMacInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_MotTqCmdPwrLimd_Val(float32 *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDrvgDynStMacInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwDrvgDynStMac_CODE) BmwDrvgDynStMacInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDrvgDynStMacInit1
 *********************************************************************************************************************/

    /* Inputs */
    VAR(float32, AUTOMATIC) MotTqCmdPwrLimd_MotNwtMtr_T_f32;

    /* Read inputs */
    (void) Rte_Read_MotTqCmdPwrLimd_Val(&MotTqCmdPwrLimd_MotNwtMtr_T_f32);

    MotTqCmdPwrLimd_MotNwtMtr_T_f32 = Abslt_f32_f32(MotTqCmdPwrLimd_MotNwtMtr_T_f32);

    if (MotTqCmdPwrLimd_MotNwtMtr_T_f32 >= Rte_Prm_BmwDrvgDynStMacMotTqCmdOvrlActvtThd_Val())
    {
        *Rte_Pim_MotTqCmdPwrLimdCdnActvt() = TRUE;
    }
    else
    {
        *Rte_Pim_MotTqCmdPwrLimdCdnActvt() = FALSE;
    }

    if (MotTqCmdPwrLimd_MotNwtMtr_T_f32 <= Rte_Prm_BmwDrvgDynStMacMotTqCmdOvrlDeactvtThd_Val())
    {
        *Rte_Pim_MotTqCmdPwrLimdCdnDeactvt() = TRUE;
    }
    else
    {
        *Rte_Pim_MotTqCmdPwrLimdCdnDeactvt() = FALSE;
    }

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwDrvgDynStMacPer1
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
 *   Std_ReturnType Rte_Read_BmwDrvgDynEnaReq_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_BmwDrvgDynFacQlfr_Val(BmwOvrlCmdQlfr1 *data)
 *   Std_ReturnType Rte_Read_BmwDrvgDynFacQlfrVld_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_BmwTarHwTqOvrlQlfr_Val(BmwOvrlCmdQlfr1 *data)
 *   Std_ReturnType Rte_Read_BmwTarHwTqOvrlQlfrVld_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_BmwTarSteerTqDrvrActrQlfr_Val(BmwOvrlCmdQlfr1 *data)
 *   Std_ReturnType Rte_Read_BmwTarSteerTqDrvrActrQlfrVld_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_BmwTrfcJamAssiDampgStReq_Val(BmwTrfcJamAssiDampgStReq1 *data)
 *   Std_ReturnType Rte_Read_BmwTrfcJamAssiDampgStReqVld_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_BmwVehCdn_Val(BmwVehCdn1 *data)
 *   Std_ReturnType Rte_Read_DampgCmdSca_Val(float32 *data)
 *   Std_ReturnType Rte_Read_DiagcStsCtrldShtDwnFltPrsnt_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_DiagcStsNonRcvrlReqDiFltPrsnt_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_EffortCmdSca_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotTqCmdPwrLimd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotTqOvrlCmd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_RtnCmdSca_Val(float32 *data)
 *   Std_ReturnType Rte_Read_StsSteerAssi_Val(StsSteerAssi1 *data)
 *   Std_ReturnType Rte_Read_SysStFltOutpReqDi_Logl(boolean *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_DrvgDynActv_Logl(boolean data)
 *   Std_ReturnType Rte_Write_DrvgDynIfSt_Val(DrvgDynIfSt1 data)
 *   Std_ReturnType Rte_Write_OutpTqOvrlRampInEna_Logl(boolean data)
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
 * Symbol: BmwDrvgDynStMacPer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwDrvgDynStMac_CODE) BmwDrvgDynStMacPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDrvgDynStMacPer1
 *********************************************************************************************************************/

    /* Inputs */
    VAR(boolean, AUTOMATIC) BmwDrvgDynEnaReq_Cnt_T_logl;
    VAR(BmwOvrlCmdQlfr1, AUTOMATIC) BmwDrvgDynFacQlfr_Cnt_T_enum;
    VAR(boolean, AUTOMATIC) BmwDrvgDynFacQlfrVld_Cnt_T_logl;
    VAR(BmwOvrlCmdQlfr1, AUTOMATIC) BmwTarHwTqOvrlQlfr_Cnt_T_enum;
    VAR(boolean, AUTOMATIC) BmwTarHwTqOvrlQlfrVld_Cnt_T_logl;
    VAR(BmwOvrlCmdQlfr1, AUTOMATIC) BmwTarSteerTqDrvrActrQlfr_Cnt_T_enum;
    VAR(boolean, AUTOMATIC) BmwTarSteerTqDrvrActrQlfrVld_Cnt_T_logl;
    VAR(BmwTrfcJamAssiDampgStReq1, AUTOMATIC) BmwTrfcJamAssiDampgStReq_Cnt_T_enum;
    VAR(boolean, AUTOMATIC) BmwTrfcJamAssiDampgStReqVld_Cnt_T_logl;
    VAR(BmwVehCdn1, AUTOMATIC) BmwVehCdn_Cnt_T_enum;
    VAR(float32, AUTOMATIC) DampgCmdSca_Uls_T_f32;
    VAR(boolean, AUTOMATIC) DiagcStsCtrldShtDwnFltPrsnt_Cnt_T_logl;
    VAR(boolean, AUTOMATIC) DiagcStsNonRcvrlReqDiFltPrsnt_Cnt_T_logl;
    VAR(float32, AUTOMATIC) EffortCmdSca_Uls_T_f32;
    VAR(float32, AUTOMATIC) MotTqCmdPwrLimd_MotNwtMtr_T_f32;
    VAR(float32, AUTOMATIC) MotTqOvrlCmd_MotNwtMtr_T_f32;
    VAR(float32, AUTOMATIC) RtnCmdSca_Uls_T_f32;
    VAR(StsSteerAssi1, AUTOMATIC) StsSteerAssi_Cnt_T_enum;
    VAR(boolean, AUTOMATIC) SysStFltOutpReqDi_Cnt_T_logl;

    /* Outputs */
    VAR(boolean, AUTOMATIC) DrvgDynActv_Cnt_T_logl;
    VAR(DrvgDynIfSt1, AUTOMATIC) DrvgDynIfSt_Cnt_T_enum;
    VAR(boolean, AUTOMATIC) OutpTqOvrlRampInEna_Cnt_T_logl;

    /* Temporary */
    VAR(boolean, AUTOMATIC) ErrMod_Cnt_T_logl;
    VAR(boolean, AUTOMATIC) AllwTran_Cnt_T_logl;
    VAR(boolean, AUTOMATIC) ErrIf_Cnt_T_logl;
    VAR(boolean, AUTOMATIC) Fac_Cnt_T_logl;
    VAR(boolean, AUTOMATIC) MotTqCmdOvrlEquZero_Cnt_T_logl;

    /* Read inputs */
    (void) Rte_Read_BmwDrvgDynEnaReq_Logl(&BmwDrvgDynEnaReq_Cnt_T_logl);
    (void) Rte_Read_BmwDrvgDynFacQlfr_Val(&BmwDrvgDynFacQlfr_Cnt_T_enum);
    (void) Rte_Read_BmwDrvgDynFacQlfrVld_Logl(&BmwDrvgDynFacQlfrVld_Cnt_T_logl);
    (void) Rte_Read_BmwTarHwTqOvrlQlfr_Val(&BmwTarHwTqOvrlQlfr_Cnt_T_enum);
    (void) Rte_Read_BmwTarHwTqOvrlQlfrVld_Logl(&BmwTarHwTqOvrlQlfrVld_Cnt_T_logl);
    (void) Rte_Read_BmwTarSteerTqDrvrActrQlfr_Val(&BmwTarSteerTqDrvrActrQlfr_Cnt_T_enum);
    (void) Rte_Read_BmwTarSteerTqDrvrActrQlfrVld_Logl(&BmwTarSteerTqDrvrActrQlfrVld_Cnt_T_logl);
    (void) Rte_Read_BmwTrfcJamAssiDampgStReq_Val(&BmwTrfcJamAssiDampgStReq_Cnt_T_enum);
    (void) Rte_Read_BmwTrfcJamAssiDampgStReqVld_Logl(&BmwTrfcJamAssiDampgStReqVld_Cnt_T_logl);
    (void) Rte_Read_BmwVehCdn_Val(&BmwVehCdn_Cnt_T_enum);
    (void) Rte_Read_DampgCmdSca_Val(&DampgCmdSca_Uls_T_f32);
    (void) Rte_Read_DiagcStsCtrldShtDwnFltPrsnt_Logl(&DiagcStsCtrldShtDwnFltPrsnt_Cnt_T_logl);
    (void) Rte_Read_DiagcStsNonRcvrlReqDiFltPrsnt_Logl(&DiagcStsNonRcvrlReqDiFltPrsnt_Cnt_T_logl);
    (void) Rte_Read_EffortCmdSca_Val(&EffortCmdSca_Uls_T_f32);
    (void) Rte_Read_MotTqCmdPwrLimd_Val(&MotTqCmdPwrLimd_MotNwtMtr_T_f32);
    (void) Rte_Read_MotTqOvrlCmd_Val(&MotTqOvrlCmd_MotNwtMtr_T_f32);
    (void) Rte_Read_RtnCmdSca_Val(&RtnCmdSca_Uls_T_f32);
    (void) Rte_Read_StsSteerAssi_Val(&StsSteerAssi_Cnt_T_enum);
    (void) Rte_Read_SysStFltOutpReqDi_Logl(&SysStFltOutpReqDi_Cnt_T_logl);

    /* DetermineErrorMode */
    ErrMod_Cnt_T_logl = DetermineErrorMode(
            SysStFltOutpReqDi_Cnt_T_logl,
            DiagcStsNonRcvrlReqDiFltPrsnt_Cnt_T_logl,
            DiagcStsCtrldShtDwnFltPrsnt_Cnt_T_logl,
            StsSteerAssi_Cnt_T_enum,
            BmwVehCdn_Cnt_T_enum);

    /* AllwTran */
    if ((BmwDrvgDynFacQlfrVld_Cnt_T_logl         != FALSE) &&
        (BmwTarHwTqOvrlQlfrVld_Cnt_T_logl        != FALSE) &&
        (BmwTrfcJamAssiDampgStReqVld_Cnt_T_logl  != FALSE) &&
        (BmwTarSteerTqDrvrActrQlfrVld_Cnt_T_logl != FALSE))
    {
        AllwTran_Cnt_T_logl = TRUE;
    }
    else
    {
        AllwTran_Cnt_T_logl = FALSE;
    }

    /* CalcErrIf */
    if ((BmwDrvgDynEnaReq_Cnt_T_logl          == FALSE) ||
        (BmwDrvgDynFacQlfr_Cnt_T_enum         == BMWOVRLCMDQLFR_SPNOTAVL) ||
        (BmwTarHwTqOvrlQlfr_Cnt_T_enum        == BMWOVRLCMDQLFR_SPNOTAVL) ||
        (BmwTarSteerTqDrvrActrQlfr_Cnt_T_enum == BMWOVRLCMDQLFR_SPNOTAVL))
    {
        ErrIf_Cnt_T_logl = TRUE;
    }
    else
    {
        ErrIf_Cnt_T_logl = FALSE;
    }

    /* Fac */
    Fac_Cnt_T_logl = Fac(
            EffortCmdSca_Uls_T_f32,
            DampgCmdSca_Uls_T_f32,
            RtnCmdSca_Uls_T_f32);

    if (Abslt_f32_f32(MotTqOvrlCmd_MotNwtMtr_T_f32) <= FLOATZEROTHD_MOTNWTMTR_F32)
    {
        MotTqCmdOvrlEquZero_Cnt_T_logl = TRUE;
    }
    else
    {
        MotTqCmdOvrlEquZero_Cnt_T_logl = FALSE;
    }

    /* StateMachine */
    StateMachine(
            ErrMod_Cnt_T_logl,
            AllwTran_Cnt_T_logl,
            ErrIf_Cnt_T_logl,
            BmwTarHwTqOvrlQlfr_Cnt_T_enum,
            BmwDrvgDynFacQlfr_Cnt_T_enum,
            BmwTarSteerTqDrvrActrQlfr_Cnt_T_enum,
            BmwTrfcJamAssiDampgStReq_Cnt_T_enum,
            Fac_Cnt_T_logl,
            MotTqCmdOvrlEquZero_Cnt_T_logl,
            MotTqCmdPwrLimd_MotNwtMtr_T_f32);

    StateMachineEntry(&DrvgDynActv_Cnt_T_logl, &DrvgDynIfSt_Cnt_T_enum, &OutpTqOvrlRampInEna_Cnt_T_logl);

    /* Write outputs */
    (void) Rte_Write_DrvgDynActv_Logl(DrvgDynActv_Cnt_T_logl);
    (void) Rte_Write_DrvgDynIfSt_Val(DrvgDynIfSt_Cnt_T_enum);
    (void) Rte_Write_OutpTqOvrlRampInEna_Logl(OutpTqOvrlRampInEna_Cnt_T_logl);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define BmwDrvgDynStMac_STOP_SEC_CODE
#include "BmwDrvgDynStMac_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#define BmwDrvgDynStMac_START_SEC_CODE
#include "BmwDrvgDynStMac_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * Name:        DetermineErrorMode
 * Description: Implementation of "DetermineErrorMode" Simulink block
 * Inputs:      SysStFltOutpReqDi_Cnt_T_logl
 *              DiagcStsNonRcvrlReqDiFltPrsnt_Cnt_T_logl
 *              DiagcStsCtrldShtDwnFltPrsnt_Cnt_T_logl
 *              StsSteerAssi_Cnt_T_enum
 *              BmwVehCdn_Cnt_T_enum
 * Outputs:     ErrorMode_Cnt_T_logl
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(boolean, BmwDrvgDynStMac_CODE) DetermineErrorMode(
        VAR(boolean,       AUTOMATIC) SysStFltOutpReqDi_Cnt_T_logl,
        VAR(boolean,       AUTOMATIC) DiagcStsNonRcvrlReqDiFltPrsnt_Cnt_T_logl,
        VAR(boolean,       AUTOMATIC) DiagcStsCtrldShtDwnFltPrsnt_Cnt_T_logl,
        VAR(StsSteerAssi1, AUTOMATIC) StsSteerAssi_Cnt_T_enum,
        VAR(BmwVehCdn1,    AUTOMATIC) BmwVehCdn_Cnt_T_enum)
{
    VAR(boolean, AUTOMATIC) ErrMod_Cnt_T_logl;
    VAR(boolean, AUTOMATIC) ErrorMode_Cnt_T_logl;
    VAR(uint32, AUTOMATIC) TiSpan_Cnt_T_u32;

    if ((SysStFltOutpReqDi_Cnt_T_logl != FALSE) ||
        (DiagcStsNonRcvrlReqDiFltPrsnt_Cnt_T_logl != FALSE) ||
        (DiagcStsCtrldShtDwnFltPrsnt_Cnt_T_logl != FALSE))
    {
        /* FehlerVorhanden */
        ErrorMode_Cnt_T_logl = TRUE;
    }
    else
    {
        /* KeepChecking */

        /* ErrMod */
        if (BmwVehCdn_Cnt_T_enum == BMWVEHCDN_DRVG)
        {
            /* Equal Start Counting */
           (void) Rte_Call_GetTiSpan100MicroSec32bit_Oper(*Rte_Pim_VehCdnTi(), &TiSpan_Cnt_T_u32);

            if (TiSpan_Cnt_T_u32 > ((uint32) Rte_Prm_BmwDrvgDynStMacVehCdnTmrThd_Val() * (uint32) CNVMILLISECTOCNT_CNTPERMILLISEC_U16))
            {
                /* Equal for long enough */
                ErrMod_Cnt_T_logl = TRUE;
            }
            else
            {
                /* Not long enough */
                ErrMod_Cnt_T_logl = FALSE;
            }
        }
        else
        {
            /* NotEqual_Reset */
            ErrMod_Cnt_T_logl = FALSE;
            (void) Rte_Call_GetRefTmr100MicroSec32bit_Oper(Rte_Pim_VehCdnTi());
        }

        /* CheckVehicleCDNandSteeringSt */
        if ((StsSteerAssi_Cnt_T_enum == STSSTEERASSI_OFF) && (ErrMod_Cnt_T_logl != FALSE))
        {
            /* FehlerVorhanden */
            ErrorMode_Cnt_T_logl = TRUE;
        }
        else
        {
            /* KeepChecking */
            ErrorMode_Cnt_T_logl = FALSE;
        }
    }

    return ErrorMode_Cnt_T_logl;
}

/**********************************************************************************************************************
 * Name:        Fac
 * Description: Implementation of "Fac" Simulink block
 * Inputs:      EffortCmdSca_Uls_T_f32
 *              DampgCmdSca_Uls_T_f32
 *              RtnCmdSca_Uls_T_f32
 * Outputs:     Fac_Cnt_T_logl
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(boolean, BmwDrvgDynStMac_CODE) Fac(
        VAR(float32, AUTOMATIC) EffortCmdSca_Uls_T_f32,
        VAR(float32, AUTOMATIC) DampgCmdSca_Uls_T_f32,
        VAR(float32, AUTOMATIC) RtnCmdSca_Uls_T_f32)
{
    VAR(boolean, AUTOMATIC) Fac_Cnt_T_logl = FALSE;

    if (Abslt_f32_f32(EffortCmdSca_Uls_T_f32 - Rte_Prm_BmwDrvgDynStMacEffortCmdScaDft_Val()) <= ARCHGLBPRM_FLOATZEROTHD_ULS_F32)
    {
        if (Abslt_f32_f32(DampgCmdSca_Uls_T_f32 - Rte_Prm_BmwDrvgDynStMacDampgCmdScaDft_Val()) <= ARCHGLBPRM_FLOATZEROTHD_ULS_F32)
        {
            if (Abslt_f32_f32(RtnCmdSca_Uls_T_f32 - Rte_Prm_BmwDrvgDynStMacRtnCmdScaDft_Val()) <= ARCHGLBPRM_FLOATZEROTHD_ULS_F32)
            {
                Fac_Cnt_T_logl = TRUE;
            }
        }
    }

    return Fac_Cnt_T_logl;
}

/**********************************************************************************************************************
 * Name:        AssiLvlCnd
 * Description: Implementation of "AssiLvlCnd" Simulink block
 * Inputs:      MotTqCmdPwrLimd_MotNwtMtr_T_f32
 * Outputs:     MotTqCmdPwrLimdActvtUppr_Cnt_T_logl
 *              MotTqCmdPwrLimdActvtLowr_Cnt_T_logl
 *              MotTqCmdPwrLimdDeactvtLowr_Cnt_T_logl
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(void, BmwDrvgDynStMac_CODE) AssiLvlCnd(
        VAR(float32,   AUTOMATIC) MotTqCmdPwrLimd_MotNwtMtr_T_f32,
        P2VAR(boolean, AUTOMATIC, BmwDrvgDynStMac_VAR) MotTqCmdPwrLimdActvtUppr_Cnt_T_logl,
        P2VAR(boolean, AUTOMATIC, BmwDrvgDynStMac_VAR) MotTqCmdPwrLimdActvtLowr_Cnt_T_logl,
        P2VAR(boolean, AUTOMATIC, BmwDrvgDynStMac_VAR) MotTqCmdPwrLimdDeactvtLowr_Cnt_T_logl)
{
    VAR(boolean, AUTOMATIC) MotTqCmdPwrLimdCdnActvt_Cnt_T_logl = FALSE;
    VAR(boolean, AUTOMATIC) MotTqCmdPwrLimdCdnDeactvt_Cnt_T_logl = FALSE;
    VAR(boolean, AUTOMATIC) MotTqCmdPwrLimdActvt_Cnt_T_logl;
    VAR(boolean, AUTOMATIC) MotTqCmdPwrLimdDeactvt_Cnt_T_logl;

    MotTqCmdPwrLimd_MotNwtMtr_T_f32 = Abslt_f32_f32(MotTqCmdPwrLimd_MotNwtMtr_T_f32);

    if (MotTqCmdPwrLimd_MotNwtMtr_T_f32 >= Rte_Prm_BmwDrvgDynStMacMotTqCmdOvrlActvtThd_Val() )
    {
        MotTqCmdPwrLimdCdnActvt_Cnt_T_logl = TRUE;
    }
    if (MotTqCmdPwrLimd_MotNwtMtr_T_f32 <= Rte_Prm_BmwDrvgDynStMacMotTqCmdOvrlDeactvtThd_Val() )
    {
        MotTqCmdPwrLimdCdnDeactvt_Cnt_T_logl = TRUE;
    }

    /* CheckActivity Time */
    MotTqCmdPwrLimdActvt_Cnt_T_logl = CheckActivityTime(MotTqCmdPwrLimdCdnActvt_Cnt_T_logl);

    /* CheckDeactivate Time */
    MotTqCmdPwrLimdDeactvt_Cnt_T_logl = CheckDeactivateTime(MotTqCmdPwrLimdCdnDeactvt_Cnt_T_logl);

    if ((MotTqCmdPwrLimdCdnActvt_Cnt_T_logl != FALSE) && (MotTqCmdPwrLimdActvt_Cnt_T_logl != FALSE))
    {
        *MotTqCmdPwrLimdActvtUppr_Cnt_T_logl = TRUE;
    }
    else
    {
        *MotTqCmdPwrLimdActvtUppr_Cnt_T_logl = FALSE;
    }

    if ((MotTqCmdPwrLimdCdnActvt_Cnt_T_logl == FALSE) && (MotTqCmdPwrLimdActvt_Cnt_T_logl != FALSE))
    {
        *MotTqCmdPwrLimdActvtLowr_Cnt_T_logl = TRUE;
    }
    else
    {
        *MotTqCmdPwrLimdActvtLowr_Cnt_T_logl = FALSE;
    }

    if ((MotTqCmdPwrLimdCdnDeactvt_Cnt_T_logl != FALSE) && (MotTqCmdPwrLimdDeactvt_Cnt_T_logl != FALSE))
    {
        *MotTqCmdPwrLimdDeactvtLowr_Cnt_T_logl = TRUE;
    }
    else
    {
        *MotTqCmdPwrLimdDeactvtLowr_Cnt_T_logl = FALSE;
    }
}

/**********************************************************************************************************************
 * Name:        CheckActivityTime
 * Description: Implementation of "CheckActivity Time" Simulink block
 * Inputs:      MotTqCmdPwrLimdCdnActvt_Cnt_T_logl
 * Outputs:     MotTqCmdPwrLimdActvt_Cnt_T_logl
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(boolean, BmwDrvgDynStMac_CODE) CheckActivityTime(
        VAR(boolean, AUTOMATIC) MotTqCmdPwrLimdCdnActvt_Cnt_T_logl)
{
    VAR(boolean, AUTOMATIC) MotTqCmdPwrLimdActvt_Cnt_T_logl;
    VAR(uint32, AUTOMATIC) TiSpan_Cnt_T_u32;

    if (MotTqCmdPwrLimdCdnActvt_Cnt_T_logl == *Rte_Pim_MotTqCmdPwrLimdCdnActvt())
    {
        /* Keep Checking */
        (void) Rte_Call_GetTiSpan100MicroSec32bit_Oper(*Rte_Pim_AssiLvlActvtTi(), &TiSpan_Cnt_T_u32);

        if (TiSpan_Cnt_T_u32 > ((uint32) Rte_Prm_BmwDrvgDynStMacAssiLvlThd_Val() * (uint32) CNVMILLISECTOCNT_CNTPERMILLISEC_U16))
        {
            /* long enough */
            MotTqCmdPwrLimdActvt_Cnt_T_logl = TRUE;
        }
        else
        {
            /* Not long enough */
            MotTqCmdPwrLimdActvt_Cnt_T_logl = FALSE;
        }
    }
    else
    {
        /* Reset Timer */
        MotTqCmdPwrLimdActvt_Cnt_T_logl = FALSE;
        (void) Rte_Call_GetRefTmr100MicroSec32bit_Oper(Rte_Pim_AssiLvlActvtTi());
    }
    *Rte_Pim_MotTqCmdPwrLimdCdnActvt() = MotTqCmdPwrLimdCdnActvt_Cnt_T_logl;

    return MotTqCmdPwrLimdActvt_Cnt_T_logl;
}

/**********************************************************************************************************************
 * Name:        CheckDeactivateTime
 * Description: Implementation of "CheckDeactivate Time" Simulink block
 * Inputs:      MotTqCmdPwrLimdCdnDeactvt_Cnt_T_logl
 * Outputs:     MotTqCmdPwrLimdDeactvt_Cnt_T_logl
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(boolean, BmwDrvgDynStMac_CODE) CheckDeactivateTime(
        VAR(boolean, AUTOMATIC) MotTqCmdPwrLimdCdnDeactvt_Cnt_T_logl)
{
    VAR(boolean, AUTOMATIC) MotTqCmdPwrLimdDeactvt_Cnt_T_logl;
    VAR(uint32, AUTOMATIC) TiSpan_Cnt_T_u32;

    if (MotTqCmdPwrLimdCdnDeactvt_Cnt_T_logl == *Rte_Pim_MotTqCmdPwrLimdCdnDeactvt())
    {
        /* Keep Checking */
        (void) Rte_Call_GetTiSpan100MicroSec32bit_Oper(*Rte_Pim_AssiLvlActvtTi(), &TiSpan_Cnt_T_u32);

        if (TiSpan_Cnt_T_u32 > ((uint32) Rte_Prm_BmwDrvgDynStMacAssiLvlThd_Val() * (uint32) CNVMILLISECTOCNT_CNTPERMILLISEC_U16))
        {
            /* long enough */
            MotTqCmdPwrLimdDeactvt_Cnt_T_logl = TRUE;
        }
        else
        {
            /* Not long enough */
            MotTqCmdPwrLimdDeactvt_Cnt_T_logl = FALSE;
        }
    }
    else
    {
        /* Reset Timer */
        MotTqCmdPwrLimdDeactvt_Cnt_T_logl = FALSE;
        (void) Rte_Call_GetRefTmr100MicroSec32bit_Oper(Rte_Pim_AssiLvlDeactvtTi());
    }
    *Rte_Pim_MotTqCmdPwrLimdCdnDeactvt() = MotTqCmdPwrLimdCdnDeactvt_Cnt_T_logl;

    return MotTqCmdPwrLimdDeactvt_Cnt_T_logl;
}


/**********************************************************************************************************************
 * Name:        ErrorIfTi
 * Description: Implementation of "ErrorIfTi" Simulink block
 * Inputs:      ErrIf_Cnt_T_logl
 * Outputs:     ErrIfTi_Cnt_T_logl
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(boolean, BmwDrvgDynStMac_CODE) ErrorIfTi(
        VAR(boolean, AUTOMATIC) ErrIf_Cnt_T_logl)
{
    VAR(boolean, AUTOMATIC) ErrIfTi_Cnt_T_logl;
    VAR(uint32, AUTOMATIC) TiSpan_Cnt_T_u32;

    if (ErrIf_Cnt_T_logl != FALSE)
    {
        /* Equal Start Counting */
        (void) Rte_Call_GetTiSpan100MicroSec32bit_Oper(*Rte_Pim_ErrIfTi(), &TiSpan_Cnt_T_u32);

        if (TiSpan_Cnt_T_u32 > ((uint32) Rte_Prm_BmwDrvgDynStMacErrIfTmrThd_Val() * (uint32) CNVMILLISECTOCNT_CNTPERMILLISEC_U16))
        {
            /* Equal for long enough */
            ErrIfTi_Cnt_T_logl = TRUE;
        }
        else
        {
            /* Not long enough */
            ErrIfTi_Cnt_T_logl = FALSE;
        }
    }
    else
    {
        /* NotEqual_Reset */
        ErrIfTi_Cnt_T_logl = FALSE;
        (void) Rte_Call_GetRefTmr100MicroSec32bit_Oper(Rte_Pim_ErrIfTi());
    }

    return ErrIfTi_Cnt_T_logl;
}

/**********************************************************************************************************************
 * Name:        StateMachine
 * Description: Implementation of "StateMachine" Simulink state machine
 * Inputs:      ErrMod_Cnt_T_logl
 *              AllwTran_Cnt_T_logl
 *              ErrIf_Cnt_T_logl
 *              BmwTarHwTqOvrlQlfr_Cnt_T_enum
 *              BmwDrvgDynFacQlfr_Cnt_T_enum
 *              BmwTarSteerTqDrvrActrQlfr_Cnt_T_enum
 *              BmwTrfcJamAssiDampgStReq_Cnt_T_enum
 *              Fac_Cnt_T_logl
 *              MotTqCmdOvrlEquZero_Cnt_T_logl
 *              MotTqCmdPwrLimd_MotNwtMtr_T_f32
 * Outputs:     Rte_Pim_StMacSt
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(void, BmwDrvgDynStMac_CODE) StateMachine(
        VAR(boolean, AUTOMATIC) ErrMod_Cnt_T_logl,
        VAR(boolean, AUTOMATIC) AllwTran_Cnt_T_logl,
        VAR(boolean, AUTOMATIC) ErrIf_Cnt_T_logl,
        VAR(BmwOvrlCmdQlfr1, AUTOMATIC) BmwTarHwTqOvrlQlfr_Cnt_T_enum,
        VAR(BmwOvrlCmdQlfr1, AUTOMATIC) BmwDrvgDynFacQlfr_Cnt_T_enum,
        VAR(BmwOvrlCmdQlfr1, AUTOMATIC) BmwTarSteerTqDrvrActrQlfr_Cnt_T_enum,
        VAR(BmwTrfcJamAssiDampgStReq1, AUTOMATIC) BmwTrfcJamAssiDampgStReq_Cnt_T_enum,
        VAR(boolean, AUTOMATIC) Fac_Cnt_T_logl,
        VAR(boolean, AUTOMATIC) MotTqCmdOvrlEquZero_Cnt_T_logl,
        VAR(float32, AUTOMATIC) MotTqCmdPwrLimd_MotNwtMtr_T_f32)
{
    VAR(boolean, AUTOMATIC) MotTqCmdPwrLimdActvtUppr_Cnt_T_logl;
    VAR(boolean, AUTOMATIC) MotTqCmdPwrLimdActvtLowr_Cnt_T_logl;
    VAR(boolean, AUTOMATIC) MotTqCmdPwrLimdDeactvtLowr_Cnt_T_logl;
    VAR(boolean, AUTOMATIC) ErrIfTi_Cnt_T_logl;

    /* AssiLvlCnd */
    AssiLvlCnd(
            MotTqCmdPwrLimd_MotNwtMtr_T_f32,
            &MotTqCmdPwrLimdActvtUppr_Cnt_T_logl,
            &MotTqCmdPwrLimdActvtLowr_Cnt_T_logl,
            &MotTqCmdPwrLimdDeactvtLowr_Cnt_T_logl);

    /* ErrorIfTi */
    ErrIfTi_Cnt_T_logl = ErrorIfTi(ErrIf_Cnt_T_logl);

    switch (*Rte_Pim_StMacSt())
    {
        case DRVGDYNIFST_IFINID: /* INIT */
            StateMachineInit(
                    ErrMod_Cnt_T_logl,
                    AllwTran_Cnt_T_logl,
                    ErrIf_Cnt_T_logl, BmwTarHwTqOvrlQlfr_Cnt_T_enum,
                    BmwDrvgDynFacQlfr_Cnt_T_enum,
                    BmwTarSteerTqDrvrActrQlfr_Cnt_T_enum,
                    BmwTrfcJamAssiDampgStReq_Cnt_T_enum,
                    MotTqCmdPwrLimdActvtUppr_Cnt_T_logl,
                    MotTqCmdPwrLimdActvtLowr_Cnt_T_logl);
            break;

        case DRVGDYNIFST_IFAVLRDYFOROPERADDLDAMPG: /* IF_AVL */
            StateMachineIfAvl(
                    ErrMod_Cnt_T_logl,
                    AllwTran_Cnt_T_logl,
                    ErrIf_Cnt_T_logl,
                    BmwTarHwTqOvrlQlfr_Cnt_T_enum,
                    BmwDrvgDynFacQlfr_Cnt_T_enum,
                    BmwTarSteerTqDrvrActrQlfr_Cnt_T_enum,
                    BmwTrfcJamAssiDampgStReq_Cnt_T_enum,
                    MotTqCmdPwrLimdDeactvtLowr_Cnt_T_logl);
            break;

        case DRVGDYNIFST_IFACTVADDLDAMPGAVL: /* IF_ACTV */
            StateMachineIfActv(
                    ErrMod_Cnt_T_logl,
                    AllwTran_Cnt_T_logl,
                    ErrIf_Cnt_T_logl,
                    BmwTarHwTqOvrlQlfr_Cnt_T_enum,
                    BmwDrvgDynFacQlfr_Cnt_T_enum,
                    BmwTarSteerTqDrvrActrQlfr_Cnt_T_enum,
                    BmwTrfcJamAssiDampgStReq_Cnt_T_enum,
                    ErrIfTi_Cnt_T_logl);
            break;

        case DRVGDYNIFST_SRVNOTAVLSTBEPSSTS: /* STB_EPS_STS */
            StateMachineStbEpsSts(
                    ErrMod_Cnt_T_logl,
                    AllwTran_Cnt_T_logl,
                    ErrIf_Cnt_T_logl,
                    BmwTarHwTqOvrlQlfr_Cnt_T_enum,
                    BmwDrvgDynFacQlfr_Cnt_T_enum,
                    BmwTarSteerTqDrvrActrQlfr_Cnt_T_enum,
                    BmwTrfcJamAssiDampgStReq_Cnt_T_enum,
                    Fac_Cnt_T_logl,
                    MotTqCmdOvrlEquZero_Cnt_T_logl,
                    MotTqCmdPwrLimdActvtUppr_Cnt_T_logl);
        break;

        case DRVGDYNIFST_SRVNOTAVLERR: /* EPS_FLT */
            break;

        default:
            /* StateMachine Initialisation */
            *Rte_Pim_StMacSt() = DRVGDYNIFST_IFINID;
            break;
    }
}

/**********************************************************************************************************************
 * Name:        StateMachineInit
 * Description: Implementation of INIT State
 * Inputs:      ErrMod_Cnt_T_logl
 *              AllwTran_Cnt_T_logl
 *              ErrIf_Cnt_T_logl
 *              BmwTarHwTqOvrlQlfr_Cnt_T_enum
 *              BmwDrvgDynFacQlfr_Cnt_T_enum
 *              BmwTarSteerTqDrvrActrQlfr_Cnt_T_enum
 *              BmwTrfcJamAssiDampgStReq_Cnt_T_enum
 *              MotTqCmdPwrLimdActvtUppr_Cnt_T_logl
 *              MotTqCmdPwrLimdActvtLowr_Cnt_T_logl
 * Outputs:     Rte_Pim_StMacSt
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(void, BmwDrvgDynStMac_CODE) StateMachineInit(
        VAR(boolean, AUTOMATIC) ErrMod_Cnt_T_logl,
        VAR(boolean, AUTOMATIC) AllwTran_Cnt_T_logl,
        VAR(boolean, AUTOMATIC) ErrIf_Cnt_T_logl,
        VAR(BmwOvrlCmdQlfr1, AUTOMATIC) BmwTarHwTqOvrlQlfr_Cnt_T_enum,
        VAR(BmwOvrlCmdQlfr1, AUTOMATIC) BmwDrvgDynFacQlfr_Cnt_T_enum,
        VAR(BmwOvrlCmdQlfr1, AUTOMATIC) BmwTarSteerTqDrvrActrQlfr_Cnt_T_enum,
        VAR(BmwTrfcJamAssiDampgStReq1, AUTOMATIC) BmwTrfcJamAssiDampgStReq_Cnt_T_enum,
        VAR(boolean, AUTOMATIC) MotTqCmdPwrLimdActvtUppr_Cnt_T_logl,
        VAR(boolean, AUTOMATIC) MotTqCmdPwrLimdActvtLowr_Cnt_T_logl)
{
    if (ErrMod_Cnt_T_logl != FALSE)
    {
        *Rte_Pim_StMacSt() = DRVGDYNIFST_SRVNOTAVLERR;
    }
    else if ((AllwTran_Cnt_T_logl != FALSE) &&
             ((ErrIf_Cnt_T_logl != FALSE) ||
              (BmwTarHwTqOvrlQlfr_Cnt_T_enum        == BMWOVRLCMDQLFR_IMPLSP) ||
              (BmwDrvgDynFacQlfr_Cnt_T_enum         == BMWOVRLCMDQLFR_IMPLSP) ||
              (BmwTarSteerTqDrvrActrQlfr_Cnt_T_enum == BMWOVRLCMDQLFR_IMPLSP) ||
              (BmwTrfcJamAssiDampgStReq_Cnt_T_enum  == BMWTRFCJAMASSIDAMPGSTREQ_CNVSPADDLDAMPG) ||
              (MotTqCmdPwrLimdActvtLowr_Cnt_T_logl  != FALSE)))
    {
        *Rte_Pim_StMacSt() = DRVGDYNIFST_SRVNOTAVLSTBEPSSTS;
    }
    else if ((AllwTran_Cnt_T_logl != FALSE) &&
             ((BmwTarHwTqOvrlQlfr_Cnt_T_enum        == BMWOVRLCMDQLFR_STBDONOTCNVSP) &&
              (BmwDrvgDynFacQlfr_Cnt_T_enum         == BMWOVRLCMDQLFR_STBDONOTCNVSP) &&
              (BmwTarSteerTqDrvrActrQlfr_Cnt_T_enum == BMWOVRLCMDQLFR_STBDONOTCNVSP) &&
              (BmwTrfcJamAssiDampgStReq_Cnt_T_enum  == BMWTRFCJAMASSIDAMPGSTREQ_DONOTCNVSPADDLDAMPG) &&
              (MotTqCmdPwrLimdActvtUppr_Cnt_T_logl  != FALSE)))
    {
        *Rte_Pim_StMacSt() = DRVGDYNIFST_IFAVLRDYFOROPERADDLDAMPG;
    }
    else
    {
        /* Do nothing */
    }
}

/**********************************************************************************************************************
 * Name:        StateMachineIfAvl
 * Description: Implementation of IF_AVL State
 * Inputs:      ErrMod_Cnt_T_logl
 *              AllwTran_Cnt_T_logl
 *              ErrIf_Cnt_T_logl
 *              BmwTarHwTqOvrlQlfr_Cnt_T_enum
 *              BmwDrvgDynFacQlfr_Cnt_T_enum
 *              BmwTrfcJamAssiDampgStReq_Cnt_T_enum
 *              MotTqCmdPwrLimdDeactvtLowr_Cnt_T_logl
 * Outputs:     Rte_Pim_StMacSt
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(void, BmwDrvgDynStMac_CODE) StateMachineIfAvl(
        VAR(boolean, AUTOMATIC) ErrMod_Cnt_T_logl,
        VAR(boolean, AUTOMATIC) AllwTran_Cnt_T_logl,
        VAR(boolean, AUTOMATIC) ErrIf_Cnt_T_logl,
        VAR(BmwOvrlCmdQlfr1, AUTOMATIC) BmwTarHwTqOvrlQlfr_Cnt_T_enum,
        VAR(BmwOvrlCmdQlfr1, AUTOMATIC) BmwDrvgDynFacQlfr_Cnt_T_enum,
        VAR(BmwOvrlCmdQlfr1, AUTOMATIC) BmwTarSteerTqDrvrActrQlfr_Cnt_T_enum,
        VAR(BmwTrfcJamAssiDampgStReq1, AUTOMATIC) BmwTrfcJamAssiDampgStReq_Cnt_T_enum,
        VAR(boolean, AUTOMATIC) MotTqCmdPwrLimdDeactvtLowr_Cnt_T_logl)
{
    if (ErrMod_Cnt_T_logl != FALSE)
    {
        *Rte_Pim_StMacSt() = DRVGDYNIFST_SRVNOTAVLERR;
    }
    else if ((ErrIf_Cnt_T_logl != FALSE) &&
             (MotTqCmdPwrLimdDeactvtLowr_Cnt_T_logl != FALSE))
    {
        *Rte_Pim_StMacSt() = DRVGDYNIFST_SRVNOTAVLSTBEPSSTS;
    }
    else if ((AllwTran_Cnt_T_logl != FALSE) &&
             (ErrIf_Cnt_T_logl == FALSE) &&
             ((BmwTarHwTqOvrlQlfr_Cnt_T_enum        == BMWOVRLCMDQLFR_IMPLSP) ||
              (BmwDrvgDynFacQlfr_Cnt_T_enum         == BMWOVRLCMDQLFR_IMPLSP) ||
              (BmwTarSteerTqDrvrActrQlfr_Cnt_T_enum == BMWOVRLCMDQLFR_IMPLSP) ||
              (BmwTrfcJamAssiDampgStReq_Cnt_T_enum  == BMWTRFCJAMASSIDAMPGSTREQ_CNVSPADDLDAMPG)))
    {
        *Rte_Pim_StMacSt() = DRVGDYNIFST_IFACTVADDLDAMPGAVL;
    }
    else
    {
        /* Do nothing */
    }
}

/**********************************************************************************************************************
 * Name:        StateMachineIfActv
 * Description: Implementation of IF_ACTV State
 * Inputs:      ErrMod_Cnt_T_logl
 *              AllwTran_Cnt_T_logl
 *              ErrIf_Cnt_T_logl
 *              BmwTarHwTqOvrlQlfr_Cnt_T_enum
 *              BmwDrvgDynFacQlfr_Cnt_T_enum
 *              BmwTrfcJamAssiDampgStReq_Cnt_T_enum
 * Outputs:     Rte_Pim_StMacSt
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(void, BmwDrvgDynStMac_CODE) StateMachineIfActv(
        VAR(boolean, AUTOMATIC) ErrMod_Cnt_T_logl,
        VAR(boolean, AUTOMATIC) AllwTran_Cnt_T_logl,
        VAR(boolean, AUTOMATIC) ErrIf_Cnt_T_logl,
        VAR(BmwOvrlCmdQlfr1, AUTOMATIC) BmwTarHwTqOvrlQlfr_Cnt_T_enum,
        VAR(BmwOvrlCmdQlfr1, AUTOMATIC) BmwDrvgDynFacQlfr_Cnt_T_enum,
        VAR(BmwOvrlCmdQlfr1, AUTOMATIC) BmwTarSteerTqDrvrActrQlfr_Cnt_T_enum,
        VAR(BmwTrfcJamAssiDampgStReq1, AUTOMATIC) BmwTrfcJamAssiDampgStReq_Cnt_T_enum,
        VAR(boolean, AUTOMATIC) ErrIfTi_Cnt_T_logl)
{
    if (ErrMod_Cnt_T_logl != FALSE)
    {
        *Rte_Pim_StMacSt() = DRVGDYNIFST_SRVNOTAVLERR;
    }
    else if ((AllwTran_Cnt_T_logl != FALSE) &&
             ((ErrIf_Cnt_T_logl == FALSE) &&
              (BmwTarHwTqOvrlQlfr_Cnt_T_enum        == BMWOVRLCMDQLFR_STBDONOTCNVSP) &&
              (BmwTarSteerTqDrvrActrQlfr_Cnt_T_enum == BMWOVRLCMDQLFR_STBDONOTCNVSP) &&
              (BmwDrvgDynFacQlfr_Cnt_T_enum         == BMWOVRLCMDQLFR_STBDONOTCNVSP) &&
              (BmwTrfcJamAssiDampgStReq_Cnt_T_enum  == BMWTRFCJAMASSIDAMPGSTREQ_DONOTCNVSPADDLDAMPG)))
    {
        *Rte_Pim_StMacSt() = DRVGDYNIFST_IFAVLRDYFOROPERADDLDAMPG;
    }
    else if (ErrIfTi_Cnt_T_logl != FALSE)
    {
        *Rte_Pim_StMacSt() = DRVGDYNIFST_SRVNOTAVLSTBEPSSTS;
    }
    else
    {
        /* Do nothing */
    }
}

/**********************************************************************************************************************
 * Name:        StateMachineStbEpsSts
 * Description: Implementation of STB_EPS_STS State
 * Inputs:      ErrMod_Cnt_T_logl
 *              AllwTran_Cnt_T_logl
 *              ErrIf_Cnt_T_logl
 *              BmwTarHwTqOvrlQlfr_Cnt_T_enum
 *              BmwDrvgDynFacQlfr_Cnt_T_enum
 *              BmwTarSteerTqDrvrActrQlfr_Cnt_T_enum
 *              BmwTrfcJamAssiDampgStReq_Cnt_T_enum
 *              Fac_Cnt_T_logl
 *              MotTqCmdOvrlEquZero_Cnt_T_logl
 *              MotTqCmdPwrLimdActvtUppr_Cnt_T_logl
 * Outputs:     Rte_Pim_StMacSt
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(void, BmwDrvgDynStMac_CODE) StateMachineStbEpsSts(
        VAR(boolean, AUTOMATIC) ErrMod_Cnt_T_logl,
        VAR(boolean, AUTOMATIC) AllwTran_Cnt_T_logl,
        VAR(boolean, AUTOMATIC) ErrIf_Cnt_T_logl,
        VAR(BmwOvrlCmdQlfr1, AUTOMATIC) BmwTarHwTqOvrlQlfr_Cnt_T_enum,
        VAR(BmwOvrlCmdQlfr1, AUTOMATIC) BmwDrvgDynFacQlfr_Cnt_T_enum,
        VAR(BmwOvrlCmdQlfr1, AUTOMATIC) BmwTarSteerTqDrvrActrQlfr_Cnt_T_enum,
        VAR(BmwTrfcJamAssiDampgStReq1, AUTOMATIC) BmwTrfcJamAssiDampgStReq_Cnt_T_enum,
        VAR(boolean, AUTOMATIC) Fac_Cnt_T_logl,
        VAR(boolean, AUTOMATIC) MotTqCmdOvrlEquZero_Cnt_T_logl,
        VAR(boolean, AUTOMATIC) MotTqCmdPwrLimdActvtUppr_Cnt_T_logl)
{
    if (ErrMod_Cnt_T_logl != FALSE)
    {
        *Rte_Pim_StMacSt() = DRVGDYNIFST_SRVNOTAVLERR;
    }
    else if ((AllwTran_Cnt_T_logl != FALSE) &&
             ((ErrIf_Cnt_T_logl == FALSE) &&
              (BmwTarHwTqOvrlQlfr_Cnt_T_enum        == BMWOVRLCMDQLFR_STBDONOTCNVSP) &&
              (BmwDrvgDynFacQlfr_Cnt_T_enum         == BMWOVRLCMDQLFR_STBDONOTCNVSP) &&
              (BmwTarSteerTqDrvrActrQlfr_Cnt_T_enum == BMWOVRLCMDQLFR_STBDONOTCNVSP) &&
              (BmwTrfcJamAssiDampgStReq_Cnt_T_enum  == BMWTRFCJAMASSIDAMPGSTREQ_DONOTCNVSPADDLDAMPG) &&
              (MotTqCmdOvrlEquZero_Cnt_T_logl != FALSE) &&
              (Fac_Cnt_T_logl != FALSE) &&
              (MotTqCmdPwrLimdActvtUppr_Cnt_T_logl != FALSE)))
    {
        *Rte_Pim_StMacSt() = DRVGDYNIFST_IFAVLRDYFOROPERADDLDAMPG;
    }
    else
    {
        /* Do nothing */
    }
}

/**********************************************************************************************************************
 * Name:        StateMachineEntry
 * Description: Implementation of "StateMachine" Entry sections
 * Inputs:      Rte_Pim_StMacSt
 * Outputs:     DrvgDynActv_Cnt_T_logl
 *              DrvgDynIfSt_Cnt_T_enum
 *              OutpTqOvrlRampInEna_Cnt_T_logl
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(void, BmwDrvgDynStMac_CODE) StateMachineEntry(
        P2VAR(boolean,      AUTOMATIC, BmwDrvgDynStMac_VAR) DrvgDynActv_Cnt_T_logl,
        P2VAR(DrvgDynIfSt1, AUTOMATIC, BmwDrvgDynStMac_VAR) DrvgDynIfSt_Cnt_T_enum,
        P2VAR(boolean,      AUTOMATIC, BmwDrvgDynStMac_VAR) OutpTqOvrlRampInEna_Cnt_T_logl)
{
    switch (*Rte_Pim_StMacSt())
    {
        case DRVGDYNIFST_IFACTVADDLDAMPGAVL:
            *DrvgDynActv_Cnt_T_logl = TRUE;
            *OutpTqOvrlRampInEna_Cnt_T_logl = TRUE;
            *DrvgDynIfSt_Cnt_T_enum = DRVGDYNIFST_IFACTVADDLDAMPGAVL;
        break;

        case DRVGDYNIFST_SRVNOTAVLERR:
            *DrvgDynActv_Cnt_T_logl = FALSE;
            *OutpTqOvrlRampInEna_Cnt_T_logl = FALSE;
            *DrvgDynIfSt_Cnt_T_enum = DRVGDYNIFST_SRVNOTAVLERR;
        break;

        case DRVGDYNIFST_SRVNOTAVLSTBEPSSTS:
            *DrvgDynActv_Cnt_T_logl = FALSE;
            *OutpTqOvrlRampInEna_Cnt_T_logl = TRUE;
            *DrvgDynIfSt_Cnt_T_enum = DRVGDYNIFST_SRVNOTAVLSTBEPSSTS;
        break;

        case DRVGDYNIFST_IFAVLRDYFOROPERADDLDAMPG:
            *DrvgDynActv_Cnt_T_logl = FALSE;
            *OutpTqOvrlRampInEna_Cnt_T_logl = FALSE;
            *DrvgDynIfSt_Cnt_T_enum = DRVGDYNIFST_IFAVLRDYFOROPERADDLDAMPG;
        break;

        default: /* DRVGDYNIFST_IFINID */
            *DrvgDynActv_Cnt_T_logl = FALSE;
            *OutpTqOvrlRampInEna_Cnt_T_logl = FALSE;
            *DrvgDynIfSt_Cnt_T_enum = DRVGDYNIFST_IFINID;
        break;
    }
}


#define BmwDrvgDynStMac_STOP_SEC_CODE
#include "BmwDrvgDynStMac_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
