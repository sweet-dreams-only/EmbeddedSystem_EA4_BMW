/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  BmwTqOvrlCdngAndDrvgDynFac.c
 *        Config:  C:/S/W/ses_dev_ea4/CF040A_BmwTqOvrlCdngAndDrvgDynFac_Impl-z172399/CF040A_BmwTqOvrlCdngAndDrvgDynFac_Impl/tools/Component.dpa
 *     SW-C Type:  BmwTqOvrlCdngAndDrvgDynFac
 *  Generated at:  Tue Apr 24 15:38:29 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <BmwTqOvrlCdngAndDrvgDynFac>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Copyright 2018 Nxtr
 * Nxtr Confidential
 *
 * Module File Name  : BmwTqOvrlCdngAndDrvgDynFac.c
 * Module Description: The BMW Output Torque Overlay Command functionality and conditioning of the BMW Driving Dynamic Factors
 * Project           : CBD
 * Author            : Marek Brykczynski
 **********************************************************************************************************************
 * Version Control:
 * %version:          1 %
 * %derived_by:       z172399 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                             SCR #
 * --------  -------  --------  ----------------------------------------------------------------------------  ---------
 * 04/26/18  1        BrykczyM  The initial version based on the Design 1.0.0                                 EA4#21202
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
 * DrvgDynIfSt1
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
 * u1p15
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
 * u9p7
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 *********************************************************************************************************************/

#include "Rte_BmwTqOvrlCdngAndDrvgDynFac.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/************************************************ Include Statements *************************************************/
#include "NxtrFil.h"
#include "NxtrFixdPt.h"
#include "NxtrIntrpn.h"
#include "ArchGlbPrm.h"
#include "SysGlbPrm.h"
#include "FltInj.h"

/******************************************** File Level Rule Deviations *********************************************/
/* MISRA-C:2004 Rule 16.10 [NXTRDEV 16.10.1]: There is no appropriate action to take on the return value for Rte_Call, Rte_Read, Rte_Write */
/* MISRA-C:2004 Rule 19.1  [NXTRDEV 19.1.1]:  AUTOSAR requires deviation from this rule for Memory Mapping include statements */

/********************************************* Embedded Local Constants **********************************************/
#define EFFORTCMDSCAHILIM_ULS_F32           (2.0F)
#define FACBIGSLEW_ULSPERSEC_F32            (500.0F)
#define MSGCYCTI_CNT_U32                    (300U)
#define ONELOOPCNT_CNT_U32                  (20U)
#define ONE_ULS_F32                         (1.0F)
#define TQOVRLBIGSLEW_MOTNWTMTRPERSEC_F32   (4400.0F)
#define ZERO_MOTNWTMTR_F32                  (0.0F)
#define ZERO_ULS_F32                        (0.0F)

/*************************************************** Local Macros ****************************************************/
#define PrmBmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrSpdX     (*(const Ary1D_u9p7_10 *)   Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrSpdX_Ary1D())
#define PrmBmwTqOvrlCdngAndDrvgDynFacEffortScaHiLimX_Ary1D      (*(const Ary1D_u4p12_12 *)  Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacEffortScaHiLimX_Ary1D())
#define PrmBmwTqOvrlCdngAndDrvgDynFacDampgScaLoLimX_Ary1D       (*(const Ary1D_u11p5_12 *)  Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacDampgScaLoLimX_Ary1D())
#define PrmSysGlbPrmVehSpdBilnrSeln_Ary1D                       (*(const Ary1D_u9p7_12 *)   Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D())

/********************************************* Local Function Prototypes *********************************************/
static FUNC(boolean, BmwTqOvrlCdngAndDrvgDynFac_CODE) TqOvrlCdng(
        CONST(uint8, AUTOMATIC)   DrvgDynIfSt_Cnt_T_u08,
        CONST(float32, AUTOMATIC) BmwTarSteerTqDrvrActr_MotNwtMtr_T_f32,
        CONST(u9p7, AUTOMATIC) VehSpd_Kph_T_u9p7,
        P2VAR(boolean, AUTOMATIC, BmwTqOvrlCdngAndDrvgDynFac_VAR) BmwDrvgDynErrIfActv_Cnt_T_logl);

static FUNC(boolean, BmwTqOvrlCdngAndDrvgDynFac_CODE) StTranDetn(
        CONST(uint8, AUTOMATIC)   DrvgDynIfSt_Cnt_T_u08,
        CONST(float32, AUTOMATIC) BmwTarSteerTqDrvrActr_MotNwtMtr_T_f32,
        CONSTP2VAR(float32, AUTOMATIC, BmwTqOvrlCdngAndDrvgDynFac_VAR) FildBmwTarSteerTqDrvrActr_MotNwtMtr_T_f32);

static FUNC(float32, BmwTqOvrlCdngAndDrvgDynFac_CODE) CalcCdndTqOvrl(
        CONST(float32, AUTOMATIC)   FildBmwTarSteerTqDrvrActr_MotNwtMtr_T_f32,
        CONST(float32, AUTOMATIC) BmwTarSteerTqDrvrActr_MotNwtMtr_T_f32,
        P2VAR(boolean, AUTOMATIC, BmwTqOvrlCdngAndDrvgDynFac_VAR) BmwDrvgDynErrIfActv_Cnt_T_logl);

static FUNC(void, BmwTqOvrlCdngAndDrvgDynFac_CODE) CalcnLimdCdndTqOvrl(
        CONST(float32, AUTOMATIC) CdndTqOvrl_MotNwtMtr_T_f32,
        CONST(u9p7, AUTOMATIC) VehSpd_Kph_T_u9p7);

static FUNC(void, BmwTqOvrlCdngAndDrvgDynFac_CODE) CalcnEffortCmdSca(
        CONST(boolean, AUTOMATIC) DrvgDynActv_Cnt_T_logl,
        CONST(float32, AUTOMATIC) ReqdEffortCmdSca_Uls_T_f32,
        CONST(boolean, AUTOMATIC) DrvgDynActvTrig_Cnt_T_logl);

static FUNC(void, BmwTqOvrlCdngAndDrvgDynFac_CODE) CalcnDampgCmdSca(
        CONST(boolean, AUTOMATIC) DrvgDynActv_Cnt_T_logl,
        CONST(float32, AUTOMATIC) ReqdDampgCmdSca_Uls_T_f32,
        CONST(boolean, AUTOMATIC) DrvgDynActvTrig_Cnt_T_logl);

static FUNC(void, BmwTqOvrlCdngAndDrvgDynFac_CODE) CalcnRtnCmdSca(
        CONST(boolean, AUTOMATIC) DrvgDynActv_Cnt_T_logl,
        CONST(float32, AUTOMATIC) ReqdRtnCmdSca_Uls_T_f32,
        CONST(boolean, AUTOMATIC) DrvgDynActvTrig_Cnt_T_logl);

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
 * u1p15: Integer in interval [0...65535]
 * u2p14: Integer in interval [0...65535]
 * u4p12: Integer in interval [0...65535]
 * u9p7: Integer in interval [0...65535]
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
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
 * Ary1D_u11p5_12: Array with 12 element(s) of type u11p5
 * Ary1D_u1p15_12: Array with 12 element(s) of type u1p15
 * Ary1D_u2p14_12: Array with 12 element(s) of type u2p14
 * Ary1D_u4p12_10: Array with 10 element(s) of type u4p12
 * Ary1D_u4p12_12: Array with 12 element(s) of type u4p12
 * Ary1D_u9p7_10: Array with 10 element(s) of type u9p7
 * Ary1D_u9p7_12: Array with 12 element(s) of type u9p7
 * Ary2D_u1p15_12_12: Array with 12 element(s) of type Ary1D_u1p15_12
 * Ary2D_u2p14_12_12: Array with 12 element(s) of type Ary1D_u2p14_12
 *
 * Record Types:
 * =============
 * FilLpRec1: Record with elements
 *   FilSt of type float32
 *   FilGain of type float32
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   float32 *Rte_Pim_BmwOutpTqOvrlCmdStVari(void)
 *   float32 *Rte_Pim_DampgCmdScaRateLimrStVari(void)
 *   float32 *Rte_Pim_EffortCmdScaRateLimrStVari(void)
 *   float32 *Rte_Pim_FrznBmwTarSteerTqDrvrActr(void)
 *   float32 *Rte_Pim_LimdCdndTqOvrl(void)
 *   float32 *Rte_Pim_RtnCmdScaRateLimrStVari(void)
 *   uint32 *Rte_Pim_MsgCycTmr(void)
 *   DrvgDynIfSt1 *Rte_Pim_PrevDrvgDynIfSt(void)
 *   boolean *Rte_Pim_BmwOutpTqOvrlCmdRampCmpl(void)
 *   boolean *Rte_Pim_FrznSigActv(void)
 *   boolean *Rte_Pim_PrevDampgSlewInProgs(void)
 *   boolean *Rte_Pim_PrevDrvgDynActv(void)
 *   boolean *Rte_Pim_PrevEffortSlewInProgs(void)
 *   boolean *Rte_Pim_PrevRtnSlewInProgs(void)
 *   boolean *Rte_Pim_RampToZeroEnad(void)
 *   FilLpRec1 *Rte_Pim_BmwTarSteerTqDrvrActrLpFilStVari(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacActvDampgSlewRate_Val(void)
 *   float32 Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacActvEffortSlewRate_Val(void)
 *   float32 Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacActvRtnSlewRate_Val(void)
 *   float32 Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacInactvDampgSlewRate_Val(void)
 *   float32 Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacInactvEffortSlewRate_Val(void)
 *   float32 Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacInactvRtnSlewRate_Val(void)
 *   float32 Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacOutpTqOvrlSlew_Val(void)
 *   float32 Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacReqdRtnCmdScaLoLim_Val(void)
 *   float32 Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrLpFilFrq_Val(void)
 *   u11p5 *Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacDampgScaLoLimX_Ary1D(void)
 *     Returnvalue: u11p5* is of type Ary1D_u11p5_12
 *   u1p15 *Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacDampgScaLoLimY_Ary2D(void)
 *     Returnvalue: u1p15* is of type Ary2D_u1p15_12_12
 *   u4p12 *Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacEffortScaHiLimX_Ary1D(void)
 *     Returnvalue: u4p12* is of type Ary1D_u4p12_12
 *   u2p14 *Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacEffortScaHiLimY_Ary2D(void)
 *     Returnvalue: u2p14* is of type Ary2D_u2p14_12_12
 *   u4p12 *Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrMaxY_Ary1D(void)
 *     Returnvalue: u4p12* is of type Ary1D_u4p12_10
 *   u9p7 *Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrSpdX_Ary1D(void)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_10
 *   u9p7 *Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D(void)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_12
 *
 *********************************************************************************************************************/


#define BmwTqOvrlCdngAndDrvgDynFac_START_SEC_CODE
#include "BmwTqOvrlCdngAndDrvgDynFac_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwTqOvrlCdngAndDrvgDynFacInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwTqOvrlCdngAndDrvgDynFacInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwTqOvrlCdngAndDrvgDynFac_CODE) BmwTqOvrlCdngAndDrvgDynFacInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwTqOvrlCdngAndDrvgDynFacInit1
 *********************************************************************************************************************/

    FilLpInit(
     ZERO_ULS_F32,
     Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrLpFilFrq_Val(),
     ARCHGLBPRM_2MILLISEC_SEC_F32,
     Rte_Pim_BmwTarSteerTqDrvrActrLpFilStVari());

    *Rte_Pim_RtnCmdScaRateLimrStVari()    = ONE_ULS_F32;
    *Rte_Pim_DampgCmdScaRateLimrStVari()  = ONE_ULS_F32;
    *Rte_Pim_EffortCmdScaRateLimrStVari() = ONE_ULS_F32;
    *Rte_Pim_PrevDrvgDynIfSt()            = DRVGDYNIFST_IFINID;


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwTqOvrlCdngAndDrvgDynFacPer1
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
 *   Std_ReturnType Rte_Read_BmwDrvgDynDampgFacReq_Val(float32 *data)
 *   Std_ReturnType Rte_Read_BmwDrvgDynEffortFacReq_Val(float32 *data)
 *   Std_ReturnType Rte_Read_BmwDrvgDynErrIfActv_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_BmwDrvgDynRtnFacReq_Val(float32 *data)
 *   Std_ReturnType Rte_Read_BmwOutpTqOvrlCmdEna_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_BmwTarSteerTqDrvrActr_Val(float32 *data)
 *   Std_ReturnType Rte_Read_DrvgDynActv_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_DrvgDynFacEna_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_DrvgDynIfSt_Val(DrvgDynIfSt1 *data)
 *   Std_ReturnType Rte_Read_HwTq_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotVelCrf_Val(float32 *data)
 *   Std_ReturnType Rte_Read_OutpTqOvrlRampInEna_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_VehSpd_Val(float32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_BmwOutpTqOvrlCmd_Val(float32 data)
 *   Std_ReturnType Rte_Write_DampgCmdSca_Val(float32 data)
 *   Std_ReturnType Rte_Write_EffortCmdSca_Val(float32 data)
 *   Std_ReturnType Rte_Write_RtnCmdSca_Val(float32 data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_FltInj_f32_Oper(float32 *SigPah_Arg, uint16 LocnKey_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_GetRefTmr100MicroSec32bit_Oper(uint32 *RefTmr_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwTqOvrlCdngAndDrvgDynFacPer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwTqOvrlCdngAndDrvgDynFac_CODE) BmwTqOvrlCdngAndDrvgDynFacPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwTqOvrlCdngAndDrvgDynFacPer1
 *********************************************************************************************************************/

    /* Inputs */
    VAR(float32, AUTOMATIC) BmwDrvgDynDampgFacReq_Uls_T_f32;
    VAR(float32, AUTOMATIC) BmwDrvgDynEffortFacReq_Uls_T_f32;
    VAR(boolean, AUTOMATIC) BmwDrvgDynErrIfActv_Cnt_T_logl;
    VAR(float32, AUTOMATIC) BmwDrvgDynRtnFacReq_Uls_T_f32;
    VAR(float32, AUTOMATIC) BmwTarSteerTqDrvrActr_MotNwtMtr_T_f32;
    VAR(boolean, AUTOMATIC) DrvgDynActv_Cnt_T_logl;
    VAR(boolean, AUTOMATIC) DrvgDynActvTrig_Cnt_T_logl;
    VAR(DrvgDynIfSt1, AUTOMATIC) DrvgDynIfSt_Cnt_T_u08;
    VAR(float32, AUTOMATIC) HwTq_HwNwtMtr_T_f32;
    VAR(float32, AUTOMATIC) MotVelCrf_MotRadPerSec_T_f32;
    VAR(boolean, AUTOMATIC) OutpTqOvrlRampInEna_Cnt_T_logl;
    VAR(float32, AUTOMATIC) VehSpd_Kph_T_f32;
    VAR(u9p7, AUTOMATIC)    VehSpd_Kph_T_u9p7;
    VAR(boolean, AUTOMATIC) BmwOutpTqOvrlCmdEna_Cnt_T_logl;
    VAR(boolean, AUTOMATIC) DrvgDynFacEna_Cnt_T_logl;

    /* Internals */
    VAR(boolean, AUTOMATIC) OutpRstTrig_Cnt_T_logl;
    VAR(float32, AUTOMATIC) Delta_MotNwtMtr_T_f32;
    VAR(u4p12, AUTOMATIC) EffortSca_Uls_T_u4p12;
    VAR(float32, AUTOMATIC) ReqdEffortCmdSca_Uls_T_f32;
    VAR(u1p15, AUTOMATIC) DampgSca_Uls_T_u1p15;
    VAR(float32, AUTOMATIC) ReqdDampgCmdSca_Uls_T_f32;
    VAR(float32, AUTOMATIC) ReqdRtnCmdSca_Uls_T_f32;
    VAR(float32, AUTOMATIC) PreLimdEffortCmdSca_Uls_Tf32;
    VAR(float32, AUTOMATIC) PreLimdDampgCmdSca_Uls_Tf32;
    VAR(float32, AUTOMATIC) PreLimdRtnCmdSca_Uls_Tf32;

    /* Outputs */
    VAR(float32, AUTOMATIC) BmwOutpTqOvrlCmd_MotNwtMtr_T_f32;

    /* Read inputs */
    (void)Rte_Read_BmwDrvgDynDampgFacReq_Val(&BmwDrvgDynDampgFacReq_Uls_T_f32);
    (void)Rte_Read_BmwDrvgDynEffortFacReq_Val(&BmwDrvgDynEffortFacReq_Uls_T_f32);
    (void)Rte_Read_BmwDrvgDynErrIfActv_Logl(&BmwDrvgDynErrIfActv_Cnt_T_logl);
    (void)Rte_Read_BmwDrvgDynRtnFacReq_Val(&BmwDrvgDynRtnFacReq_Uls_T_f32);
    (void)Rte_Read_BmwTarSteerTqDrvrActr_Val(&BmwTarSteerTqDrvrActr_MotNwtMtr_T_f32);
    (void)Rte_Read_DrvgDynActv_Logl(&DrvgDynActv_Cnt_T_logl);
    (void)Rte_Read_DrvgDynIfSt_Val(&DrvgDynIfSt_Cnt_T_u08);
    (void)Rte_Read_HwTq_Val(&HwTq_HwNwtMtr_T_f32);
    (void)Rte_Read_MotVelCrf_Val(&MotVelCrf_MotRadPerSec_T_f32);
    (void)Rte_Read_OutpTqOvrlRampInEna_Logl(&OutpTqOvrlRampInEna_Cnt_T_logl);
    (void)Rte_Read_VehSpd_Val(&VehSpd_Kph_T_f32);
    (void)Rte_Read_BmwOutpTqOvrlCmdEna_Logl(&BmwOutpTqOvrlCmdEna_Cnt_T_logl);
    (void)Rte_Read_DrvgDynFacEna_Logl(&DrvgDynFacEna_Cnt_T_logl);


    VehSpd_Kph_T_u9p7 = FloatToFixd_u16_f32(VehSpd_Kph_T_f32, NXTRFIXDPT_FLOATTOP7_ULS_F32);


    if (BmwOutpTqOvrlCmdEna_Cnt_T_logl != FALSE)
    {
        /* BmwOutpTqOvrlCmdCodBitEnad */
        OutpRstTrig_Cnt_T_logl = TqOvrlCdng(
                DrvgDynIfSt_Cnt_T_u08,
                BmwTarSteerTqDrvrActr_MotNwtMtr_T_f32,
                VehSpd_Kph_T_u9p7,
                &BmwDrvgDynErrIfActv_Cnt_T_logl);

        if ((*Rte_Pim_RampToZeroEnad() != FALSE) || (BmwDrvgDynErrIfActv_Cnt_T_logl != FALSE))
        {
            /* PassLimdCdndTqOvrl */
            BmwOutpTqOvrlCmd_MotNwtMtr_T_f32 = *Rte_Pim_LimdCdndTqOvrl();
        }
        else if (OutpRstTrig_Cnt_T_logl != FALSE)
        {
            /* PassZero */
            BmwOutpTqOvrlCmd_MotNwtMtr_T_f32 = ZERO_MOTNWTMTR_F32;
        }
        else
        {
            /* NormMod */
            if (DrvgDynActv_Cnt_T_logl != FALSE)
            {
                /* CalcOutp */
                if ((OutpTqOvrlRampInEna_Cnt_T_logl != FALSE) && (*Rte_Pim_BmwOutpTqOvrlCmdRampCmpl() == FALSE))
                {
                    /* CaldSlewRate */
                    Delta_MotNwtMtr_T_f32 = Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacOutpTqOvrlSlew_Val() * ARCHGLBPRM_2MILLISEC_SEC_F32;
                }
                else
                {
                    /* ConSlewRate */
                    Delta_MotNwtMtr_T_f32 = TQOVRLBIGSLEW_MOTNWTMTRPERSEC_F32 * ARCHGLBPRM_2MILLISEC_SEC_F32;
                }

                BmwOutpTqOvrlCmd_MotNwtMtr_T_f32 = Lim_f32(
                        *Rte_Pim_LimdCdndTqOvrl(),
                        *Rte_Pim_BmwOutpTqOvrlCmdStVari() - Delta_MotNwtMtr_T_f32,
                        *Rte_Pim_BmwOutpTqOvrlCmdStVari() + Delta_MotNwtMtr_T_f32);

                if ((Abslt_f32_f32(*Rte_Pim_BmwOutpTqOvrlCmdStVari() - BmwOutpTqOvrlCmd_MotNwtMtr_T_f32)) <= ARCHGLBPRM_FLOATZEROTHD_ULS_F32)
                {
                    *Rte_Pim_BmwOutpTqOvrlCmdRampCmpl() = TRUE;
                }
                else
                {
                    *Rte_Pim_BmwOutpTqOvrlCmdRampCmpl() = FALSE;
                }
            }
            else
            {
                /* SlewDwnToZero */
                Delta_MotNwtMtr_T_f32 = Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacOutpTqOvrlSlew_Val() * ARCHGLBPRM_2MILLISEC_SEC_F32;

                BmwOutpTqOvrlCmd_MotNwtMtr_T_f32 = Lim_f32(
                        ZERO_MOTNWTMTR_F32,
                        *Rte_Pim_BmwOutpTqOvrlCmdStVari() - Delta_MotNwtMtr_T_f32,
                        *Rte_Pim_BmwOutpTqOvrlCmdStVari() + Delta_MotNwtMtr_T_f32);

                *Rte_Pim_BmwOutpTqOvrlCmdRampCmpl() = FALSE;

            }
        }

        *Rte_Pim_BmwOutpTqOvrlCmdStVari() = BmwOutpTqOvrlCmd_MotNwtMtr_T_f32;

    }
    else
    {
        /* BmwOutpTqOvrlCmdCodBitDisad */
        BmwOutpTqOvrlCmd_MotNwtMtr_T_f32                    = ZERO_MOTNWTMTR_F32;
        *Rte_Pim_BmwOutpTqOvrlCmdStVari()                   = ZERO_MOTNWTMTR_F32;
        *Rte_Pim_FrznBmwTarSteerTqDrvrActr()                = ZERO_MOTNWTMTR_F32;
        *Rte_Pim_LimdCdndTqOvrl()                           = ZERO_MOTNWTMTR_F32;
        (*Rte_Pim_BmwTarSteerTqDrvrActrLpFilStVari()).FilSt = ZERO_MOTNWTMTR_F32;
        *Rte_Pim_PrevDrvgDynIfSt()                          = DRVGDYNIFST_IFINID;
        *Rte_Pim_BmwOutpTqOvrlCmdRampCmpl()                 = FALSE;
        *Rte_Pim_RampToZeroEnad()                           = FALSE;
        *Rte_Pim_FrznSigActv()                              = FALSE;

        (void)Rte_Call_GetRefTmr100MicroSec32bit_Oper(Rte_Pim_MsgCycTmr());
        *Rte_Pim_MsgCycTmr() += ONELOOPCNT_CNT_U32;
    }


    BmwOutpTqOvrlCmd_MotNwtMtr_T_f32 = Lim_f32(
            BmwOutpTqOvrlCmd_MotNwtMtr_T_f32,
            SYSGLBPRM_MOTTQCMDLOLIM_MOTNWTMTR_F32,
            SYSGLBPRM_MOTTQCMDHILIM_MOTNWTMTR_F32);

#if(STD_ON == FLTINJENA)
    (void) Rte_Call_FltInj_f32_Oper(&BmwOutpTqOvrlCmd_MotNwtMtr_T_f32, FLTINJ_BMWTQOVRLCDNGANDDRVGDYNFAC_BMWOUTPTQOVRLCMD);
#endif

    if (DrvgDynFacEna_Cnt_T_logl != FALSE)
    {

        DrvgDynActvTrig_Cnt_T_logl = (DrvgDynActv_Cnt_T_logl != *Rte_Pim_PrevDrvgDynActv()) ? TRUE : FALSE;
        *Rte_Pim_PrevDrvgDynActv() = DrvgDynActv_Cnt_T_logl;

        if (DrvgDynActv_Cnt_T_logl != FALSE)
        {
            /* PassFac */
            PreLimdEffortCmdSca_Uls_Tf32 = BmwDrvgDynEffortFacReq_Uls_T_f32;
            PreLimdDampgCmdSca_Uls_Tf32  = BmwDrvgDynDampgFacReq_Uls_T_f32;
            PreLimdRtnCmdSca_Uls_Tf32    = BmwDrvgDynRtnFacReq_Uls_T_f32;

        }
        else
        {
            /* OutDftVal */
            PreLimdEffortCmdSca_Uls_Tf32 = ONE_ULS_F32;
            PreLimdDampgCmdSca_Uls_Tf32  = ONE_ULS_F32;
            PreLimdRtnCmdSca_Uls_Tf32    = ONE_ULS_F32;

        }

        /* CalcnReqdEffortCmdSca */
        EffortSca_Uls_T_u4p12 = BilnrIntrpnWithRound_u16_u16CmnXu16MplY(
                VehSpd_Kph_T_u9p7,
                FloatToFixd_u16_f32(Abslt_f32_f32(HwTq_HwNwtMtr_T_f32), NXTRFIXDPT_FLOATTOP12_ULS_F32),
                Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D(),
                (uint16) TblSize_m(PrmSysGlbPrmVehSpdBilnrSeln_Ary1D),
                Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacEffortScaHiLimX_Ary1D(),
                Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacEffortScaHiLimY_Ary2D(),
                (uint16) TblSize_m(PrmBmwTqOvrlCdngAndDrvgDynFacEffortScaHiLimX_Ary1D));

        ReqdEffortCmdSca_Uls_T_f32 = Lim_f32(
                PreLimdEffortCmdSca_Uls_Tf32,
                ONE_ULS_F32,
                FixdToFloat_f32_u16(EffortSca_Uls_T_u4p12, NXTRFIXDPT_P12TOFLOAT_ULS_F32));

        /* CalcnReqdDampgCmdSca */
        DampgSca_Uls_T_u1p15 = BilnrIntrpnWithRound_u16_u16CmnXu16MplY(
                VehSpd_Kph_T_u9p7,
                FloatToFixd_u16_f32(Abslt_f32_f32(MotVelCrf_MotRadPerSec_T_f32), NXTRFIXDPT_FLOATTOP5_ULS_F32),
                Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D(),
                (uint16) TblSize_m(PrmSysGlbPrmVehSpdBilnrSeln_Ary1D),
                Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacDampgScaLoLimX_Ary1D(),
                Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacDampgScaLoLimY_Ary2D(),
                (uint16) TblSize_m(PrmBmwTqOvrlCdngAndDrvgDynFacDampgScaLoLimX_Ary1D));

        ReqdDampgCmdSca_Uls_T_f32 = Lim_f32(
                PreLimdDampgCmdSca_Uls_Tf32,
                FixdToFloat_f32_u16(DampgSca_Uls_T_u1p15, NXTRFIXDPT_P15TOFLOAT_ULS_F32),
                ONE_ULS_F32);

        ReqdRtnCmdSca_Uls_T_f32 = Lim_f32(
                PreLimdRtnCmdSca_Uls_Tf32,
                Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacReqdRtnCmdScaLoLim_Val(),
                ONE_ULS_F32);

        CalcnEffortCmdSca(DrvgDynActv_Cnt_T_logl, ReqdEffortCmdSca_Uls_T_f32, DrvgDynActvTrig_Cnt_T_logl);

        CalcnDampgCmdSca(DrvgDynActv_Cnt_T_logl, ReqdDampgCmdSca_Uls_T_f32, DrvgDynActvTrig_Cnt_T_logl);

        CalcnRtnCmdSca(DrvgDynActv_Cnt_T_logl, ReqdRtnCmdSca_Uls_T_f32, DrvgDynActvTrig_Cnt_T_logl);

    }
    else
    {
        /* DrvgDynFacCodBitDisad */
        *Rte_Pim_RtnCmdScaRateLimrStVari()    = ONE_ULS_F32;
        *Rte_Pim_DampgCmdScaRateLimrStVari()  = ONE_ULS_F32;
        *Rte_Pim_EffortCmdScaRateLimrStVari() = ONE_ULS_F32;
        *Rte_Pim_PrevEffortSlewInProgs()      = FALSE;
        *Rte_Pim_PrevDampgSlewInProgs()       = FALSE;
        *Rte_Pim_PrevRtnSlewInProgs()         = FALSE;
        *Rte_Pim_PrevDrvgDynActv()            = FALSE;
    }


    /* LimStat_f1 */
    *Rte_Pim_EffortCmdScaRateLimrStVari() = Lim_f32(
            *Rte_Pim_EffortCmdScaRateLimrStVari(),
            ONE_ULS_F32,
            EFFORTCMDSCAHILIM_ULS_F32);

    /* LimStat_f2 */
    *Rte_Pim_DampgCmdScaRateLimrStVari() = Lim_f32(
            *Rte_Pim_DampgCmdScaRateLimrStVari(),
            ZERO_ULS_F32,
            ONE_ULS_F32);

    /* LimStat_f3 */
    *Rte_Pim_RtnCmdScaRateLimrStVari() = Lim_f32(
            *Rte_Pim_RtnCmdScaRateLimrStVari(),
            ZERO_ULS_F32,
            ONE_ULS_F32);


    /* Write outputs */

    (void)Rte_Write_BmwOutpTqOvrlCmd_Val(BmwOutpTqOvrlCmd_MotNwtMtr_T_f32);
    (void)Rte_Write_EffortCmdSca_Val(*Rte_Pim_EffortCmdScaRateLimrStVari());
    (void)Rte_Write_DampgCmdSca_Val(*Rte_Pim_DampgCmdScaRateLimrStVari());
    (void)Rte_Write_RtnCmdSca_Val(*Rte_Pim_RtnCmdScaRateLimrStVari());


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define BmwTqOvrlCdngAndDrvgDynFac_STOP_SEC_CODE
#include "BmwTqOvrlCdngAndDrvgDynFac_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Name:        TqOvrlCdng
 * Description: The implementation of a Simulink block TqOvrlCdng
 * Inputs:      DrvgDynIfSt_Cnt_T_u08
 *              BmwTarSteerTqDrvrActr_MotNwtMtr_T_f32
 *              VehSpd_Kph_T_u9p7
 *              BmwDrvgDynErrIfActv_Cnt_T_logl
 * Outputs:     *Rte_Pim_LimdCdndTqOvrl()
 *              OutpRstTrig_Cnt_T_logl
 * Usage Notes: NONE
 *********************************************************************************************************************/

static FUNC(boolean, BmwTqOvrlCdngAndDrvgDynFac_CODE) TqOvrlCdng(
        CONST(uint8, AUTOMATIC)   DrvgDynIfSt_Cnt_T_u08,
        CONST(float32, AUTOMATIC) BmwTarSteerTqDrvrActr_MotNwtMtr_T_f32,
        CONST(u9p7, AUTOMATIC) VehSpd_Kph_T_u9p7,
        P2VAR(boolean, AUTOMATIC, BmwTqOvrlCdngAndDrvgDynFac_VAR) BmwDrvgDynErrIfActv_Cnt_T_logl)
{

    VAR(boolean, AUTOMATIC) OutpRstTrig_Cnt_T_logl;
    VAR(float32, AUTOMATIC) FildBmwTarSteerTqDrvrActr_MotNwtMtr_T_f32;
    VAR(float32, AUTOMATIC) CdndTqOvrl_MotNwtMtr_T_f32;

    OutpRstTrig_Cnt_T_logl = StTranDetn(
            DrvgDynIfSt_Cnt_T_u08,
            BmwTarSteerTqDrvrActr_MotNwtMtr_T_f32,
            &FildBmwTarSteerTqDrvrActr_MotNwtMtr_T_f32);

    CdndTqOvrl_MotNwtMtr_T_f32 = CalcCdndTqOvrl(
            FildBmwTarSteerTqDrvrActr_MotNwtMtr_T_f32,
            BmwTarSteerTqDrvrActr_MotNwtMtr_T_f32,
            BmwDrvgDynErrIfActv_Cnt_T_logl);

    CalcnLimdCdndTqOvrl(
            CdndTqOvrl_MotNwtMtr_T_f32,
            VehSpd_Kph_T_u9p7);


    return OutpRstTrig_Cnt_T_logl;
}


/**********************************************************************************************************************
 * Name:        StTranDetn
 * Description: The implementation of a Simulink block StTranDetn
 * Inputs:      DrvgDynIfSt_Cnt_T_u08
 *              BmwTarSteerTqDrvrActr_MotNwtMtr_T_f32
 * Outputs:     FildBmwTarSteerTqDrvrActr_MotNwtMtr_T_f32
 *              *Rte_Pim_FrznBmwTarSteerTqDrvrActr()
 *              OutpRstTrig_Cnt_T_logl
 * Usage Notes: NONE
 *********************************************************************************************************************/

static FUNC(boolean, BmwTqOvrlCdngAndDrvgDynFac_CODE) StTranDetn(
        CONST(uint8, AUTOMATIC)   DrvgDynIfSt_Cnt_T_u08,
        CONST(float32, AUTOMATIC) BmwTarSteerTqDrvrActr_MotNwtMtr_T_f32,
        CONSTP2VAR(float32, AUTOMATIC, BmwTqOvrlCdngAndDrvgDynFac_VAR) FildBmwTarSteerTqDrvrActr_MotNwtMtr_T_f32)
{

    VAR(boolean, AUTOMATIC) OutpRstTrig_Cnt_T_logl  = FALSE;
    VAR(boolean, AUTOMATIC) CurrActv_Cnt_T_logl     = FALSE;
    VAR(boolean, AUTOMATIC) FromCdnVld_Cnt_T_logl   = FALSE;


    FromCdnVld_Cnt_T_logl       = (*Rte_Pim_PrevDrvgDynIfSt() == DRVGDYNIFST_IFAVLRDYFOROPERADDLDAMPG) ? TRUE : FALSE;

    CurrActv_Cnt_T_logl         = (DrvgDynIfSt_Cnt_T_u08 == DRVGDYNIFST_IFACTVADDLDAMPGAVL) ? TRUE : FALSE;

    /* A PrevActv label from model is evaluated as the second argument of the conditional expression below */
    OutpRstTrig_Cnt_T_logl      = ((DrvgDynIfSt_Cnt_T_u08 == DRVGDYNIFST_IFAVLRDYFOROPERADDLDAMPG)
            && (*Rte_Pim_PrevDrvgDynIfSt() == DRVGDYNIFST_IFACTVADDLDAMPGAVL)) ? TRUE : FALSE;

    *Rte_Pim_PrevDrvgDynIfSt()  = DrvgDynIfSt_Cnt_T_u08;


    if ((FromCdnVld_Cnt_T_logl != FALSE)
        && ((CurrActv_Cnt_T_logl != FALSE)
        || (DrvgDynIfSt_Cnt_T_u08 == DRVGDYNIFST_SRVNOTAVLSTBEPSSTS)
        || (DrvgDynIfSt_Cnt_T_u08 == DRVGDYNIFST_SRVNOTAVLERR)))
    {
        /* RstFrznBmwTarSteerTqDrvrActr */
       *Rte_Pim_FrznBmwTarSteerTqDrvrActr() = ZERO_MOTNWTMTR_F32;
    }
    else
    {
        /* Do Nothing */
    }

    Rte_Pim_BmwTarSteerTqDrvrActrLpFilStVari()->FilSt = FilLpUpdOutp_f32(
            BmwTarSteerTqDrvrActr_MotNwtMtr_T_f32,
            Rte_Pim_BmwTarSteerTqDrvrActrLpFilStVari());


    if ((FromCdnVld_Cnt_T_logl != FALSE)
        && (CurrActv_Cnt_T_logl != FALSE))
    {
        /* RstFildBmwTarSteerTqDrvrActr */
        *FildBmwTarSteerTqDrvrActr_MotNwtMtr_T_f32 = ZERO_MOTNWTMTR_F32;
    }
    else
    {
        /* PassFildSig */
        *FildBmwTarSteerTqDrvrActr_MotNwtMtr_T_f32 = Rte_Pim_BmwTarSteerTqDrvrActrLpFilStVari()->FilSt;

    }

    return OutpRstTrig_Cnt_T_logl;
}


/**********************************************************************************************************************
 * Name:        CalcCdndTqOvrl
 * Description: The implementation of a Simulink block CalcCdndTqOvrl
 * Inputs:      FildBmwTarSteerTqDrvrActr_MotNwtMtr_T_f32
 *              BmwTarSteerTqDrvrActr_MotNwtMtr_T_f32
 *              BmwDrvgDynErrIfActv_Cnt_T_logl
 * Outputs:     CdndTqOvrl_MotNwtMtr_T_f32
 * Usage Notes: NONE
 *********************************************************************************************************************/

static FUNC(float32, BmwTqOvrlCdngAndDrvgDynFac_CODE) CalcCdndTqOvrl(
        CONST(float32, AUTOMATIC)   FildBmwTarSteerTqDrvrActr_MotNwtMtr_T_f32,
        CONST(float32, AUTOMATIC) BmwTarSteerTqDrvrActr_MotNwtMtr_T_f32,
        P2VAR(boolean, AUTOMATIC, BmwTqOvrlCdngAndDrvgDynFac_VAR) BmwDrvgDynErrIfActv_Cnt_T_logl)
{

    VAR(float32, AUTOMATIC) CdndTqOvrl_MotNwtMtr_T_f32;
    VAR(uint32, AUTOMATIC) TiSpan_Cnt_T_u32;
    VAR(float32, AUTOMATIC) Delta_Cnt_T_f32;


    if (*Rte_Pim_RampToZeroEnad() == FALSE)
    {
        /* PassSig */

    }
    else
    {
        /* OvrwrTrue */
        *BmwDrvgDynErrIfActv_Cnt_T_logl = TRUE;
    }

    if (*BmwDrvgDynErrIfActv_Cnt_T_logl != FALSE)
    {
        /* UseFildSig */

        if (*Rte_Pim_FrznSigActv() == FALSE)
        {
            /* LtchFildVal */
            *Rte_Pim_FrznBmwTarSteerTqDrvrActr() = FildBmwTarSteerTqDrvrActr_MotNwtMtr_T_f32;
            *Rte_Pim_FrznSigActv()               = TRUE;
        }
        else
        {
            /* Do Nothing */
        }

        (void) Rte_Call_GetTiSpan100MicroSec32bit_Oper(*Rte_Pim_MsgCycTmr(), &TiSpan_Cnt_T_u32);

        if (TiSpan_Cnt_T_u32 <= MSGCYCTI_CNT_U32)
        {
            /* Wait */
            CdndTqOvrl_MotNwtMtr_T_f32 = *Rte_Pim_FrznBmwTarSteerTqDrvrActr();
            *Rte_Pim_RampToZeroEnad()  = FALSE;
        }
        else
        {
            /* RampDwn*/
            Delta_Cnt_T_f32 = Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacOutpTqOvrlSlew_Val() * ARCHGLBPRM_2MILLISEC_SEC_F32;

            CdndTqOvrl_MotNwtMtr_T_f32 = Lim_f32(
                    ZERO_ULS_F32,
                    *Rte_Pim_LimdCdndTqOvrl() - Delta_Cnt_T_f32,
                    *Rte_Pim_LimdCdndTqOvrl() + Delta_Cnt_T_f32);

            if(Abslt_f32_f32(CdndTqOvrl_MotNwtMtr_T_f32) <= ARCHGLBPRM_FLOATZEROTHD_ULS_F32)
            {
                *Rte_Pim_RampToZeroEnad() = FALSE;
            }
            else
            {
                *Rte_Pim_RampToZeroEnad() = TRUE;
            }

        }

    }
    else
    {
        /* PassInpSig */
        CdndTqOvrl_MotNwtMtr_T_f32 = BmwTarSteerTqDrvrActr_MotNwtMtr_T_f32;
        *Rte_Pim_FrznSigActv()     = FALSE;
        *Rte_Pim_RampToZeroEnad()  = FALSE;

        (void)Rte_Call_GetRefTmr100MicroSec32bit_Oper(Rte_Pim_MsgCycTmr());
        *Rte_Pim_MsgCycTmr() += ONELOOPCNT_CNT_U32;

    }

    return CdndTqOvrl_MotNwtMtr_T_f32;
}


/**********************************************************************************************************************
 * Name:        CalcnLimdCdndTqOvrl
 * Description: The implementation of a Simulink block CalcnLimdCdndTqOvrl
 * Inputs:      CdndTqOvrl_MotNwtMtr_T_f32
 *              VehSpd_Kph_T_u9p7
 * Outputs:     *Rte_Pim_LimdCdndTqOvrl()
 * Usage Notes: NONE
 *********************************************************************************************************************/

static FUNC(void, BmwTqOvrlCdngAndDrvgDynFac_CODE) CalcnLimdCdndTqOvrl(
        CONST(float32, AUTOMATIC) CdndTqOvrl_MotNwtMtr_T_f32,
        CONST(u9p7, AUTOMATIC) VehSpd_Kph_T_u9p7)
{

    VAR(uint16, AUTOMATIC) LimdCdndTqOvrl_MotNwtMtr_T_u4p12;

    LimdCdndTqOvrl_MotNwtMtr_T_u4p12 = LnrIntrpn_u16_u16VariXu16VariY(
            Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrSpdX_Ary1D(),
            Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrMaxY_Ary1D(),
            (uint16) TblSize_m(PrmBmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrSpdX),
            VehSpd_Kph_T_u9p7);

    *Rte_Pim_LimdCdndTqOvrl() = Lim_f32(
            CdndTqOvrl_MotNwtMtr_T_f32,
            -FixdToFloat_f32_u16(LimdCdndTqOvrl_MotNwtMtr_T_u4p12, NXTRFIXDPT_P12TOFLOAT_ULS_F32),
            FixdToFloat_f32_u16(LimdCdndTqOvrl_MotNwtMtr_T_u4p12, NXTRFIXDPT_P12TOFLOAT_ULS_F32));

}

/**********************************************************************************************************************
 * Name:        CalcnEffortCmdSca
 * Description: The implementation of a Simulink block CalcnEffortCmdSca
 * Inputs:      DrvgDynActv_Cnt_T_logl
 *              ReqdEffortCmdSca_Uls_T_f32
 *              DrvgDynActvTrig_Cnt_T_logl
 * Outputs:     *Rte_Pim_EffortCmdScaRateLimrStVari()
 * Usage Notes: NONE
 *********************************************************************************************************************/

static FUNC(void, BmwTqOvrlCdngAndDrvgDynFac_CODE) CalcnEffortCmdSca(
        CONST(boolean, AUTOMATIC) DrvgDynActv_Cnt_T_logl,
        CONST(float32, AUTOMATIC) ReqdEffortCmdSca_Uls_T_f32,
        CONST(boolean, AUTOMATIC) DrvgDynActvTrig_Cnt_T_logl)
{

    /* Internals */
    VAR(float32, AUTOMATIC) EffortSlewRate_Uls_T_f32;

    if ((DrvgDynActvTrig_Cnt_T_logl != FALSE) || (*Rte_Pim_PrevEffortSlewInProgs() != FALSE))
    {
        /* RampEffortFac */
        if (DrvgDynActv_Cnt_T_logl != FALSE)
        {
            EffortSlewRate_Uls_T_f32 = Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacActvEffortSlewRate_Val();
        }
        else
        {
            EffortSlewRate_Uls_T_f32 = Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacInactvEffortSlewRate_Val();
        }

        *Rte_Pim_PrevEffortSlewInProgs() = TRUE;
    }
    else
    {
        /* NoRampEffortFac */
        EffortSlewRate_Uls_T_f32         = FACBIGSLEW_ULSPERSEC_F32;
        *Rte_Pim_PrevEffortSlewInProgs() = FALSE;

    }


    /* RateLimDyn_f32 */
    *Rte_Pim_EffortCmdScaRateLimrStVari() = Lim_f32(
            ReqdEffortCmdSca_Uls_T_f32,
            -(EffortSlewRate_Uls_T_f32 * ARCHGLBPRM_2MILLISEC_SEC_F32) + *Rte_Pim_EffortCmdScaRateLimrStVari(),
            (EffortSlewRate_Uls_T_f32 * ARCHGLBPRM_2MILLISEC_SEC_F32) + *Rte_Pim_EffortCmdScaRateLimrStVari());


    if (Abslt_f32_f32(*Rte_Pim_EffortCmdScaRateLimrStVari() - ReqdEffortCmdSca_Uls_T_f32) > ARCHGLBPRM_FLOATZEROTHD_ULS_F32)
    {
    }
    else
    {
        *Rte_Pim_PrevEffortSlewInProgs() = FALSE;
    }

}


/**********************************************************************************************************************
 * Name:        CalcnDampgCmdSca
 * Description: The implementation of a Simulink block CalcnDampgCmdSca
 * Inputs:      DrvgDynActv_Cnt_T_logl
 *              ReqdDampgCmdSca_Uls_T_f32
 *              DrvgDynActvTrig_Cnt_T_logl
 * Outputs:     *Rte_Pim_DampgCmdScaRateLimrStVari()
 * Usage Notes: NONE
 *********************************************************************************************************************/

static FUNC(void, BmwTqOvrlCdngAndDrvgDynFac_CODE) CalcnDampgCmdSca(
        CONST(boolean, AUTOMATIC) DrvgDynActv_Cnt_T_logl,
        CONST(float32, AUTOMATIC) ReqdDampgCmdSca_Uls_T_f32,
        CONST(boolean, AUTOMATIC) DrvgDynActvTrig_Cnt_T_logl)
{

    /* Internals */
    VAR(float32, AUTOMATIC) DampgSlewRate_Uls_T_f32;

    if ((DrvgDynActvTrig_Cnt_T_logl != FALSE) || (*Rte_Pim_PrevDampgSlewInProgs() != FALSE))
    {
        /* RampDampgFac */
        if (DrvgDynActv_Cnt_T_logl != FALSE)
        {
            DampgSlewRate_Uls_T_f32 = Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacActvDampgSlewRate_Val();
        }
        else
        {
            DampgSlewRate_Uls_T_f32 = Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacInactvDampgSlewRate_Val();
        }

        *Rte_Pim_PrevDampgSlewInProgs() = TRUE;
    }
    else
    {
        /* NoRampDampgFac */
        DampgSlewRate_Uls_T_f32         = FACBIGSLEW_ULSPERSEC_F32;
        *Rte_Pim_PrevDampgSlewInProgs() = FALSE;

    }

    /* RateLimDyn_f32 */
    *Rte_Pim_DampgCmdScaRateLimrStVari() = Lim_f32(
            ReqdDampgCmdSca_Uls_T_f32,
            -(DampgSlewRate_Uls_T_f32 * ARCHGLBPRM_2MILLISEC_SEC_F32) + *Rte_Pim_DampgCmdScaRateLimrStVari(),
            (DampgSlewRate_Uls_T_f32 * ARCHGLBPRM_2MILLISEC_SEC_F32) + *Rte_Pim_DampgCmdScaRateLimrStVari());


    if (Abslt_f32_f32(*Rte_Pim_DampgCmdScaRateLimrStVari() - ReqdDampgCmdSca_Uls_T_f32) > ARCHGLBPRM_FLOATZEROTHD_ULS_F32)
    {
    }
    else
    {
        *Rte_Pim_PrevDampgSlewInProgs() = FALSE;
    }

}

/**********************************************************************************************************************
 * Name:        CalcnRtnCmdSca
 * Description: The implementation of a Simulink block CalcnRtnCmdSca
 * Inputs:      DrvgDynActv_Cnt_T_logl
 *              ReqdRtnCmdSca_Uls_T_f32
 *              DrvgDynActvTrig_Cnt_T_logl
 * Outputs:     *Rte_Pim_RtnCmdScaRateLimrStVari()
 * Usage Notes: NONE
 *********************************************************************************************************************/

static FUNC(void, BmwTqOvrlCdngAndDrvgDynFac_CODE) CalcnRtnCmdSca(
        CONST(boolean, AUTOMATIC) DrvgDynActv_Cnt_T_logl,
        CONST(float32, AUTOMATIC) ReqdRtnCmdSca_Uls_T_f32,
        CONST(boolean, AUTOMATIC) DrvgDynActvTrig_Cnt_T_logl)
{

    /* Internals */
    VAR(float32, AUTOMATIC) RtnSlewRate_Uls_T_f32;

    if ((DrvgDynActvTrig_Cnt_T_logl != FALSE) || (*Rte_Pim_PrevRtnSlewInProgs() != FALSE))
    {
        /* RampRtnFac */
        if (DrvgDynActv_Cnt_T_logl != FALSE)
        {
            RtnSlewRate_Uls_T_f32 = Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacActvRtnSlewRate_Val();
        }
        else
        {
            RtnSlewRate_Uls_T_f32 = Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacInactvRtnSlewRate_Val();
        }

        *Rte_Pim_PrevRtnSlewInProgs() = TRUE;
    }
    else
    {
        /* NoRampRtnFac */
        RtnSlewRate_Uls_T_f32         = FACBIGSLEW_ULSPERSEC_F32;
        *Rte_Pim_PrevRtnSlewInProgs() = FALSE;

    }

    /* RateLimDyn_f32 */
    *Rte_Pim_RtnCmdScaRateLimrStVari() = Lim_f32(
            ReqdRtnCmdSca_Uls_T_f32,
            -(RtnSlewRate_Uls_T_f32 * ARCHGLBPRM_2MILLISEC_SEC_F32) + *Rte_Pim_RtnCmdScaRateLimrStVari(),
            (RtnSlewRate_Uls_T_f32 * ARCHGLBPRM_2MILLISEC_SEC_F32) + *Rte_Pim_RtnCmdScaRateLimrStVari());

    if (Abslt_f32_f32(*Rte_Pim_RtnCmdScaRateLimrStVari() - ReqdRtnCmdSca_Uls_T_f32) > ARCHGLBPRM_FLOATZEROTHD_ULS_F32)
    {
    }
    else
    {
        *Rte_Pim_PrevRtnSlewInProgs() = FALSE;
    }

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
