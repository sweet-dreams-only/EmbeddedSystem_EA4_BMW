/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  BmwStReqMgr.c
 *        Config:  C:/Users/nz2999/Documents/Synergy/ccm_wa/ses_dev_ea4/CF069A_BmwStReqMgr_Impl-nz2999/CF069A_BmwStReqMgr_Impl/tools/Component.dpa
 *     SW-C Type:  BmwStReqMgr
 *  Generated at:  Thu May 24 09:30:34 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <BmwStReqMgr>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Copyright 2017, 2018 Nxtr
 * Nxtr Confidential
 *
 * Module File Name  : BmwStReqMgr.c
 * Module Description: Implementation of BMW State Request Manager
 * Project           : CBD
 * Author            : Krzysztof Byrski
 **********************************************************************************************************************
 * Version Control:
 * %version:          7 %
 * %derived_by:       nz2999 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                             SCR #
 * --------  -------  --------  ----------------------------------------------------------------------------  ---------
 * 10/23/17  1        KByrski   Initial version                                                               EA4#15483
 * 11/14/17  2        MB        Update to design 2.0.0                                                        EA4#17437
 * 01/10/18  3        ML        Added Calibrations and PIM. Added logic to override TarEcuSt. Updated         EA4#18784
                                StsDrvrActvyTmr logic to compare HwTq to Threshold. Rearranged logic in
                                DeterminationOfStatusSteeringAssistAndEpsFctSts.
 * 01/19/18  4        ML        Added logic to override output values.                                        EA4#19561
 * 02/22/18  5        ML        Modified Override logic. Added new inputs and logic to State Machine.         EA4#20459
 * 03/22/18  6        KByrski   Update to design 3.0.0                                                        EA4#21718
 * 05/22/18  7        KByrski   Update to design 4.0.0                                                        EA4#22918
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
 * BmwEpsFctSts1
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
 * BmwVehSpdSts1
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * StsDrvrActvy1
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
 * SysSt1
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * u16p0
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 *
 * Component Types:
 * ================
 * BmwStReqMgr
 *   This function will be responsible for requesting transitions between the states and modes of the steering system based on vehicle signals
 *
 *
 * Port Prototypes:
 * ================
 * BmwEpsFctSts
 *   Eps Function Status enumerated signal
 *
 * BmwVehCdn
 *   Signal for BMW Vehicle Condition
 *
 * BmwVehCdnVld
 *   Signal for BMW Vehicle Condition Validity
 *
 * BmwVehSpdSts
 *   Signal for BMW Vehicle Speed Status
 *
 * DiagcStsNonRcvrlReqDiFltPrsnt
 *   Signal to determine whether a Non-Recoverable Fault is present
 *
 * GetRefTmr100MicroSec32bit
 *   Autosar Client to get the Reference time to calculate the elapsed time
 *
 * GetTiSpan100MicroSec32bit
 *   Time Span
 *
 * HwTq
 *   Signal for Handwheel Torque
 *
 * IoHwAb_GetGpioMcuEna
 *   Output to be used in logic
 *
 * PwrLimrRednFac
 *   Power Limiter Reduction Factor
 *
 * PwrSplyEnaReq
 *   Power Supply Enable Request Signal
 *
 * StsDrvrActvy
 *   Signal for Status Driver Activity
 *
 * StsSteerAssi
 *   Status Steering Assist
 *
 * SysOperMotTqCmdSca
 *   System Operate Motor Torque Command Scale Signal
 *
 * SysOperRampRate
 *   System Operate Ramp Rate Signal
 *
 * SysSt
 *   Signal for System State
 *
 * SysStFltOutpReqDi
 *   Signal to determine a fault is present that will request a transition to disable
 *
 * SysStReqEna
 *   System State Request Enable Signal
 *
 * TarEcuSt
 *   Target ECU State Signal
 *
 * ThermRednFac
 *   Signal Description for THermRednFac: Value representing the percent reduction in assist being produced by the ThermMotTqLim value
 *
 * VehSpd
 *   Signal for Vehicle Speed
 *
 *
 * Runnable Entities:
 * ==================
 * BmwStReqMgrInit1
 *   Function initialization. Empty
 *
 * BmwStReqMgrPer1
 *   Periodic functionality. It contains the State Machine that Feeds may other components. E.g. determines the Target ECU Sts.
 *
 *
 * Per-Instance Memory:
 * ====================
 * BmwVehCdnLvngDurn
 *   Elapsed time timer
 *
 * DrvrActvRefTmr
 *   Elapsed time timer
 *
 * PrevHwTq
 *   Variable to store the Previous value of Handwheel Torque
 *
 * PrevTarEcuSt
 *   Variable to store the State Machine in
 *
 *********************************************************************************************************************/

#include "Rte_BmwStReqMgr.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/************************************************ Include Statements *************************************************/
#include "NxtrMath.h"

/******************************************** File Level Rule Deviations *********************************************/
/* MISRA-C: 2004 Rule 16.10 [NXTRDEV 16.10.1]: There is no appropriate action to take on the return value for IoHwAb_GetGpioMcuEna. */
/* MISRA-C:2004 Rule 16.10 [NXTRDEV 16.10.2]: Server runnable is a void function; Rte generation adds standard return
                                              type but no error information is returned for GetRefTmr100MicroSec32bit, GetTiSpan100MicroSec32bit */
/* MISRA-C:2004 Rule 19.1 [NXTRDEV 19.1.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */

/********************************************* Embedded Local Constants **********************************************/
#define CNVMILLISECTOCNT_CNTPERMILLISEC_U16       (10U)
#define LIMPERCCMPLHILIM_ULS_F32                  (1.0F)
#define LIMPERCCMPLLOLIM_ULS_F32                  (0.0F)
#define ONECNT_CNT_U16                            (20U)
#define ONE_CNT_U08                               (1U)
#define ONE_ULS_F32                               (1.0F)
#define OVRDTHD_CNT_U08                           (15U)
#define SYSOPERAMPRATEMAX_ULSPERSEC_F32           (500.0F)
#define SYSOPERAMPRATEMIN_ULSPERSEC_F32           (0.1F)
#define ZERO_ULS_F32                              (0.0F)

/********************************************* Local Function Prototypes *********************************************/
static FUNC(void, BmwStReqMgr_CODE) Override(P2VAR(boolean,    AUTOMATIC, BmwStReqMgr_VAR) BmwVehCdnVld_Cnt_T_logl,
                                             P2VAR(BmwVehCdn1, AUTOMATIC, BmwStReqMgr_VAR) BmwVehCdn_Cnt_T_enum);

static FUNC(void, BmwStReqMgr_CODE) CalcOfStsSteerAssiAndEpsFctSts(VAR(SysSt1,  AUTOMATIC) SysSt_Cnt_T_enum,
                                                                   VAR(float32, AUTOMATIC) ThermRednFac_Uls_T_f32,
                                                                   VAR(boolean, AUTOMATIC) RcvrlFltPrsnt_Cnt_T_logl,
                                                                   VAR(boolean, AUTOMATIC) DiagcStsNonRcvrlReqDiFltPrsnt_Cnt_T_logl,
                                                                   VAR(float32, AUTOMATIC) PwrLimrRednFac_Uls_T_f32,
                                                                   P2VAR(StsSteerAssi1, AUTOMATIC, BmwStReqMgr_VAR) StsSteerAssi_Cnt_T_enum,
                                                                   P2VAR(BmwEpsFctSts1, AUTOMATIC, BmwStReqMgr_VAR) BmwEpsFctSts_Cnt_T_enum);

static FUNC(StsDrvrActvy1, BmwStReqMgr_CODE) StsDrvrActvyTmr(VAR(float32, AUTOMATIC) HwTq_HwNwtMtr_T_f32);

static FUNC(boolean, BmwStReqMgr_CODE) AssiOnToOffFlg(VAR(boolean,       AUTOMATIC) DiagcStsNonRcvrlReqDiFltPrsnt_Cnt_T_logl,
                                                      VAR(boolean,       AUTOMATIC) BmwVehCdnVld_Cnt_T_logl,
                                                      VAR(BmwVehSpdSts1, AUTOMATIC) BmwVehSpdSts_Cnt_T_enum,
                                                      VAR(float32,       AUTOMATIC) VehSpd_Kph_T_f32,
                                                      VAR(BmwVehCdn1,    AUTOMATIC) BmwVehCdn_Cnt_T_enum,
                                                      VAR(StsDrvrActvy1, AUTOMATIC) StsDrvrActvy_Cnt_T_enum,
                                                      VAR(boolean,       AUTOMATIC) PinSt_Cnt_T_logl);

static FUNC(boolean, BmwStReqMgr_CODE) AllwToOff(VAR(BmwVehCdn1, AUTOMATIC) BmwVehCdn_Cnt_T_enum,
                                                 VAR(boolean,    AUTOMATIC) IgnLine_Cnt_T_logl);

static FUNC(void, BmwStReqMgr_CODE) TargetECUState(VAR(boolean,    AUTOMATIC) DiagcStsNonRcvrlReqDiFltPrsnt_Cnt_T_logl,
                                                   VAR(BmwVehCdn1, AUTOMATIC) BmwVehCdn_Cnt_T_enum,
                                                   VAR(boolean,    AUTOMATIC) AssiOnToOffFlg_Cnt_T_logl,
                                                   VAR(boolean,    AUTOMATIC) AllwTranToDi_Cnt_T_logl,
                                                   VAR(boolean,    AUTOMATIC) IgnLine_Cnt_T_logl,
                                                   VAR(boolean,    AUTOMATIC) AllwToOff_Cnt_T_logl,
                                                   P2VAR(SysSt1,  AUTOMATIC, BmwStReqMgr_VAR) TarEcuSt_Cnt_T_enum,
                                                   P2VAR(boolean, AUTOMATIC, BmwStReqMgr_VAR) PwrSplyEnaReq_Cnt_T_logl,
                                                   P2VAR(boolean, AUTOMATIC, BmwStReqMgr_VAR) SysStReqEna_Cnt_T_logl,
                                                   P2VAR(float32, AUTOMATIC, BmwStReqMgr_VAR) SysOperMotTqCmdSca_Uls_T_f32);

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
 * u16p0: Integer in interval [0...65535]
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * BmwEpsFctSts1: Enumeration of integer in interval [0...255] with enumerators
 *   BMWEPSFCTSTS_FCTINFALLBACK (49U)
 *   BMWEPSFCTSTS_FCTINFALLBACKEMGYFCNENVTLINFLSACTV (51U)
 *   BMWEPSFCTSTS_NOTAVIERR (96U)
 *   BMWEPSFCTSTS_ININ (128U)
 *   BMWEPSFCTSTS_FCTAVIACTV12VEPS (160U)
 *   BMWEPSFCTSTS_FCTAVIACTVEMGYFCNENVTLINFLSACTV (162U)
 *   BMWEPSFCTSTS_FCTAVIACTV12VEAS (164U)
 *   BMWEPSFCTSTS_FCTAVIACTV24VEAS (168U)
 *   BMWEPSFCTSTS_FCTTMPINFALLBACK (176U)
 *   BMWEPSFCTSTS_FCTTMPINFALLBACKEMGYFCNENVTLINFLSACT (178U)
 *   BMWEPSFCTSTS_NOTAVISWDOFF (224U)
 *   BMWEPSFCTSTS_INVLD (255U)
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
 * BmwVehSpdSts1: Enumeration of integer in interval [0...255] with enumerators
 *   BMWVEHSPDSTS_VLD (1U)
 *   BMWVEHSPDSTS_SUBVALSETINUSFLSIGVEHSTANDG (4U)
 *   BMWVEHSPDSTS_SUBVALSETINUSFLSIGVEHRUNNG (12U)
 *   BMWVEHSPDSTS_SUBVALSETINUSRSIGNOINFO (14U)
 *   BMWVEHSPDSTS_INVLD (15U)
 * StsDrvrActvy1: Enumeration of integer in interval [0...255] with enumerators
 *   STSDRVRACTVY_NODRVRACTVY (0U)
 *   STSDRVRACTVY_DRVRACTVY (1U)
 * StsSteerAssi1: Enumeration of integer in interval [0...255] with enumerators
 *   STSSTEERASSI_OFF (0U)
 *   STSSTEERASSI_ON (1U)
 * SysSt1: Enumeration of integer in interval [0...255] with enumerators
 *   SYSST_DI (0U)
 *   SYSST_OFF (1U)
 *   SYSST_ENA (2U)
 *   SYSST_WRMININ (3U)
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   float32 *Rte_Pim_PrevHwTq(void)
 *   uint32 *Rte_Pim_BmwVehCdnLvngDurn(void)
 *   uint32 *Rte_Pim_DrvrActvRefTmr(void)
 *   uint8 *Rte_Pim_PrevTarEcuSt(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_BmwStReqMgrHwTqThd_Val(void)
 *   float32 Rte_Prm_BmwStReqMgrOperRampRate_Val(void)
 *   float32 Rte_Prm_BmwStReqMgrStsDrvrActvyTqChgThd_Val(void)
 *   float32 Rte_Prm_BmwStReqMgrSwtOffSpdLim_Val(void)
 *   float32 Rte_Prm_BmwStReqMgrSysProtnRednFacThd_Val(void)
 *   u16p0 Rte_Prm_BmwStReqMgrAllwToOffThd_Val(void)
 *   u16p0 Rte_Prm_BmwStReqMgrDrvrActvTmrThd_Val(void)
 *   uint8 Rte_Prm_BmwStReqMgrVehCdnOvrd_Val(void)
 *
 *********************************************************************************************************************/


#define BmwStReqMgr_START_SEC_CODE
#include "BmwStReqMgr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwStReqMgrInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_GetRefTmr100MicroSec32bit_Oper(uint32 *RefTmr_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwStReqMgrInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwStReqMgr_CODE) BmwStReqMgrInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwStReqMgrInit1
 *********************************************************************************************************************/

    /* Empty Init function */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwStReqMgrPer1
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
 *   Std_ReturnType Rte_Read_BmwVehCdn_Val(BmwVehCdn1 *data)
 *   Std_ReturnType Rte_Read_BmwVehCdnVld_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_BmwVehSpdSts_Val(BmwVehSpdSts1 *data)
 *   Std_ReturnType Rte_Read_DiagcStsNonRcvrlReqDiFltPrsnt_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_HwTq_Val(float32 *data)
 *   Std_ReturnType Rte_Read_PwrLimrRednFac_Val(float32 *data)
 *   Std_ReturnType Rte_Read_SysSt_Val(SysSt1 *data)
 *   Std_ReturnType Rte_Read_SysStFltOutpReqDi_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_ThermRednFac_Val(float32 *data)
 *   Std_ReturnType Rte_Read_VehSpd_Val(float32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_BmwEpsFctSts_Val(BmwEpsFctSts1 data)
 *   Std_ReturnType Rte_Write_PwrSplyEnaReq_Logl(boolean data)
 *   Std_ReturnType Rte_Write_StsDrvrActvy_Val(StsDrvrActvy1 data)
 *   Std_ReturnType Rte_Write_StsSteerAssi_Val(StsSteerAssi1 data)
 *   Std_ReturnType Rte_Write_SysOperMotTqCmdSca_Val(float32 data)
 *   Std_ReturnType Rte_Write_SysOperRampRate_Val(float32 data)
 *   Std_ReturnType Rte_Write_SysStReqEna_Logl(boolean data)
 *   Std_ReturnType Rte_Write_TarEcuSt_Val(SysSt1 data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_GetRefTmr100MicroSec32bit_Oper(uint32 *RefTmr_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_IoHwAb_GetGpioMcuEna_Oper(boolean *PinSt_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_GetGpio_PortIf1_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwStReqMgrPer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwStReqMgr_CODE) BmwStReqMgrPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwStReqMgrPer1
 *********************************************************************************************************************/

    /* Inputs */
    VAR(BmwVehCdn1,    AUTOMATIC) BmwVehCdn_Cnt_T_enum;
    VAR(boolean,       AUTOMATIC) BmwVehCdnVld_Cnt_T_logl;
    VAR(BmwVehSpdSts1, AUTOMATIC) BmwVehSpdSts_Cnt_T_enum;
    VAR(boolean,       AUTOMATIC) DiagcStsNonRcvrlReqDiFltPrsnt_Cnt_T_logl;
    VAR(float32,       AUTOMATIC) HwTq_HwNwtMtr_T_f32;
    VAR(float32,       AUTOMATIC) PwrLimrRednFac_Uls_T_f32;
    VAR(SysSt1,        AUTOMATIC) SysSt_Cnt_T_enum;
    VAR(boolean,       AUTOMATIC) SysStFltOutpReqDi_Cnt_T_logl;
    VAR(float32,       AUTOMATIC) ThermRednFac_Uls_T_f32;
    VAR(float32,       AUTOMATIC) VehSpd_Kph_T_f32;

    /* Outputs */
    VAR(BmwEpsFctSts1, AUTOMATIC) BmwEpsFctSts_Cnt_T_enum;
    VAR(boolean,       AUTOMATIC) PwrSplyEnaReq_Cnt_T_logl;
    VAR(StsDrvrActvy1, AUTOMATIC) StsDrvrActvy_Cnt_T_enum;
    VAR(StsSteerAssi1, AUTOMATIC) StsSteerAssi_Cnt_T_enum;
    VAR(float32,       AUTOMATIC) SysOperMotTqCmdSca_Uls_T_f32;
    VAR(float32,       AUTOMATIC) SysOperRampRate_UlsPerSec_T_f32;
    VAR(boolean,       AUTOMATIC) SysStReqEna_Cnt_T_logl;
    VAR(SysSt1,        AUTOMATIC) TarEcuSt_Cnt_T_enum;

    /* Temporary */
    VAR(boolean,       AUTOMATIC) RcvrlFltPrsnt_Cnt_T_logl;
    VAR(boolean,       AUTOMATIC) AssiOnToOffFlg_Cnt_T_logl;
    VAR(boolean,       AUTOMATIC) AllwTranToDi_Cnt_T_logl;
    VAR(boolean,       AUTOMATIC) PinSt_Cnt_T_logl;
    VAR(boolean,       AUTOMATIC) AllwToOff_Cnt_T_logl;

    /* Read inputs */
    (void) Rte_Read_BmwVehCdn_Val(&BmwVehCdn_Cnt_T_enum);
    (void) Rte_Read_BmwVehCdnVld_Logl(&BmwVehCdnVld_Cnt_T_logl);
    (void) Rte_Read_BmwVehSpdSts_Val(&BmwVehSpdSts_Cnt_T_enum);
    (void) Rte_Read_DiagcStsNonRcvrlReqDiFltPrsnt_Logl(&DiagcStsNonRcvrlReqDiFltPrsnt_Cnt_T_logl);
    (void) Rte_Read_HwTq_Val(&HwTq_HwNwtMtr_T_f32);
    (void) Rte_Read_PwrLimrRednFac_Val(&PwrLimrRednFac_Uls_T_f32);
    (void) Rte_Read_SysSt_Val(&SysSt_Cnt_T_enum);
    (void) Rte_Read_SysStFltOutpReqDi_Logl(&SysStFltOutpReqDi_Cnt_T_logl);
    (void) Rte_Read_ThermRednFac_Val(&ThermRednFac_Uls_T_f32);
    (void) Rte_Read_VehSpd_Val(&VehSpd_Kph_T_f32);

    /* override */
    Override(&BmwVehCdnVld_Cnt_T_logl, &BmwVehCdn_Cnt_T_enum);

    if ((SysStFltOutpReqDi_Cnt_T_logl != FALSE) && (DiagcStsNonRcvrlReqDiFltPrsnt_Cnt_T_logl == FALSE))
    {
        RcvrlFltPrsnt_Cnt_T_logl = TRUE;
    }
    else
    {

        RcvrlFltPrsnt_Cnt_T_logl = FALSE;
    }

    /* DeterminationOfStatusSteeringAssistAndEpsFctSts */
    CalcOfStsSteerAssiAndEpsFctSts(SysSt_Cnt_T_enum,
                                   ThermRednFac_Uls_T_f32,
                                   RcvrlFltPrsnt_Cnt_T_logl,
                                   DiagcStsNonRcvrlReqDiFltPrsnt_Cnt_T_logl,
                                   PwrLimrRednFac_Uls_T_f32,
                                   &StsSteerAssi_Cnt_T_enum,
                                   &BmwEpsFctSts_Cnt_T_enum);

    /* StsDrvrActvyTmr */
    StsDrvrActvy_Cnt_T_enum = StsDrvrActvyTmr(HwTq_HwNwtMtr_T_f32);

    /* IoHwAb_GetGpioMcuEna */
    (void) Rte_Call_IoHwAb_GetGpioMcuEna_Oper(&PinSt_Cnt_T_logl);

    /* AssiOnToOffFlg */
    AssiOnToOffFlg_Cnt_T_logl = AssiOnToOffFlg(DiagcStsNonRcvrlReqDiFltPrsnt_Cnt_T_logl,
                                               BmwVehCdnVld_Cnt_T_logl,
                                               BmwVehSpdSts_Cnt_T_enum,
                                               VehSpd_Kph_T_f32,
                                               BmwVehCdn_Cnt_T_enum,
                                               StsDrvrActvy_Cnt_T_enum,
                                               PinSt_Cnt_T_logl);

    if ((BmwVehSpdSts_Cnt_T_enum == BMWVEHSPDSTS_VLD) && (VehSpd_Kph_T_f32 > Rte_Prm_BmwStReqMgrSwtOffSpdLim_Val()))
    {
        AllwTranToDi_Cnt_T_logl = FALSE;
    }
    else
    {
        AllwTranToDi_Cnt_T_logl = TRUE;
    }

    /* AllwToOff */
    AllwToOff_Cnt_T_logl = AllwToOff(BmwVehCdn_Cnt_T_enum, PinSt_Cnt_T_logl);

    /* TargetECUState */
    TargetECUState(DiagcStsNonRcvrlReqDiFltPrsnt_Cnt_T_logl,
                   BmwVehCdn_Cnt_T_enum,
                   AssiOnToOffFlg_Cnt_T_logl,
                   AllwTranToDi_Cnt_T_logl,
                   PinSt_Cnt_T_logl,
                   AllwToOff_Cnt_T_logl,
                   &TarEcuSt_Cnt_T_enum,
                   &PwrSplyEnaReq_Cnt_T_logl,
                   &SysStReqEna_Cnt_T_logl,
                   &SysOperMotTqCmdSca_Uls_T_f32);

    *Rte_Pim_PrevTarEcuSt() = (uint8) TarEcuSt_Cnt_T_enum + ONE_CNT_U08;

    SysOperRampRate_UlsPerSec_T_f32 = Lim_f32(Rte_Prm_BmwStReqMgrOperRampRate_Val(),
                                              SYSOPERAMPRATEMIN_ULSPERSEC_F32,
                                              SYSOPERAMPRATEMAX_ULSPERSEC_F32);
    SysOperMotTqCmdSca_Uls_T_f32 = Lim_f32(SysOperMotTqCmdSca_Uls_T_f32, ZERO_ULS_F32, ONE_ULS_F32);

    /* Write outputs */
    (void) Rte_Write_BmwEpsFctSts_Val(BmwEpsFctSts_Cnt_T_enum);
    (void) Rte_Write_PwrSplyEnaReq_Logl(PwrSplyEnaReq_Cnt_T_logl);
    (void) Rte_Write_StsDrvrActvy_Val(StsDrvrActvy_Cnt_T_enum);
    (void) Rte_Write_StsSteerAssi_Val(StsSteerAssi_Cnt_T_enum);
    (void) Rte_Write_SysOperMotTqCmdSca_Val(SysOperMotTqCmdSca_Uls_T_f32);
    (void) Rte_Write_SysOperRampRate_Val(SysOperRampRate_UlsPerSec_T_f32);
    (void) Rte_Write_SysStReqEna_Logl(SysStReqEna_Cnt_T_logl);
    (void) Rte_Write_TarEcuSt_Val(TarEcuSt_Cnt_T_enum);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define BmwStReqMgr_STOP_SEC_CODE
#include "BmwStReqMgr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


#define BmwStReqMgr_START_SEC_CODE
#include "BmwStReqMgr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Name:        Override
 * Description: Implementation of Override block from FDD
 * Inputs:      BmwVehCdnVld_Cnt_T_logl
 *              BmwVehCdn_Cnt_T_enum
 * Outputs:     BmwVehCdnVld_Cnt_T_logl
 *              BmwVehCdn_Cnt_T_enum
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(void, BmwStReqMgr_CODE) Override(P2VAR(boolean,    AUTOMATIC, BmwStReqMgr_VAR) BmwVehCdnVld_Cnt_T_logl,
                                             P2VAR(BmwVehCdn1, AUTOMATIC, BmwStReqMgr_VAR) BmwVehCdn_Cnt_T_enum)
{
    if (Rte_Prm_BmwStReqMgrVehCdnOvrd_Val() < OVRDTHD_CNT_U08)
    {
        /* Override */
        *BmwVehCdnVld_Cnt_T_logl = TRUE;

        switch (Rte_Prm_BmwStReqMgrVehCdnOvrd_Val())
        {
            case BMWVEHCDN_PRKGNBNOK:
            {
                *BmwVehCdn_Cnt_T_enum = BMWVEHCDN_PRKGNBNOK;
            }
            break;

            case BMWVEHCDN_PRKGBNOK:
            {
                *BmwVehCdn_Cnt_T_enum = BMWVEHCDN_PRKGBNOK;
            }
            break;

            case BMWVEHCDN_FCTCUSTNOTINFZG:
            {
                *BmwVehCdn_Cnt_T_enum = BMWVEHCDN_FCTCUSTNOTINFZG;
            }
            break;

            case BMWVEHCDN_LVNG:
            {
                *BmwVehCdn_Cnt_T_enum = BMWVEHCDN_LVNG;
            }
            break;

            case BMWVEHCDN_CHKDIAGCANLS:
            {
                *BmwVehCdn_Cnt_T_enum = BMWVEHCDN_CHKDIAGCANLS;
            }
            break;

            case BMWVEHCDN_DRVRPREPGFOROPER:
            {
                *BmwVehCdn_Cnt_T_enum = BMWVEHCDN_DRVRPREPGFOROPER;
            }
            break;

            case BMWVEHCDN_DRVG:
            {
                *BmwVehCdn_Cnt_T_enum = BMWVEHCDN_DRVG;
            }
            break;

            case BMWVEHCDN_DRVRPREPGFOREXITOPER:
            {
                *BmwVehCdn_Cnt_T_enum = BMWVEHCDN_DRVRPREPGFOREXITOPER;
            }
            break;

            default:
            {
                *BmwVehCdn_Cnt_T_enum = BMWVEHCDN_INVLD;
            }
            break;
        }
    }
}

/**********************************************************************************************************************
 * Name:        CalcOfStsSteerAssiAndEpsFctSts
 * Description: Determination Of StatusSteeringAssist And EPS Function Status
 * Inputs:      SysSt_Cnt_T_enum
 *              ThermRednFac_Uls_T_f32
 *              SysStFltOutpReqDi_Cnt_T_logl
 *              DiagcStsNonRcvrlReqDiFltPrsnt_Cnt_T_logl
 *              PwrLimrRednFac_Uls_T_f32
 * Outputs:     StsSteerAssi_Cnt_T_enum
 *              BmwEpsFctSts_Cnt_T_enum
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(void, BmwStReqMgr_CODE) CalcOfStsSteerAssiAndEpsFctSts(VAR(SysSt1,  AUTOMATIC) SysSt_Cnt_T_enum,
                                                                   VAR(float32, AUTOMATIC) ThermRednFac_Uls_T_f32,
                                                                   VAR(boolean, AUTOMATIC) RcvrlFltPrsnt_Cnt_T_logl,
                                                                   VAR(boolean, AUTOMATIC) DiagcStsNonRcvrlReqDiFltPrsnt_Cnt_T_logl,
                                                                   VAR(float32, AUTOMATIC) PwrLimrRednFac_Uls_T_f32,
                                                                   P2VAR(StsSteerAssi1, AUTOMATIC, BmwStReqMgr_VAR) StsSteerAssi_Cnt_T_enum,
                                                                   P2VAR(BmwEpsFctSts1, AUTOMATIC, BmwStReqMgr_VAR) BmwEpsFctSts_Cnt_T_enum)
{
    VAR(float32, AUTOMATIC) LimPercCmp_Uls_T_f32;

    switch (SysSt_Cnt_T_enum)
    {
        case SYSST_DI:
        case SYSST_OFF:
        case SYSST_WRMININ:
        {
            /* SetToOff */
            *StsSteerAssi_Cnt_T_enum = STSSTEERASSI_OFF;
        }
        break;

        default:
        {
            /* SetToOperate */
            *StsSteerAssi_Cnt_T_enum = STSSTEERASSI_ON;
        }
        break;
    }

    if (DiagcStsNonRcvrlReqDiFltPrsnt_Cnt_T_logl != FALSE)
    {
        /* F1Fault */
        *BmwEpsFctSts_Cnt_T_enum = BMWEPSFCTSTS_NOTAVIERR;
    }
    else
    {
        /* NoF1Fault */
        if (SysSt_Cnt_T_enum == SYSST_ENA)
        {
            LimPercCmp_Uls_T_f32 = Max_f32(PwrLimrRednFac_Uls_T_f32, ThermRednFac_Uls_T_f32);
            LimPercCmp_Uls_T_f32 = Lim_f32(LimPercCmp_Uls_T_f32, LIMPERCCMPLLOLIM_ULS_F32, LIMPERCCMPLHILIM_ULS_F32);

            /* CF069A_102_104 */
            if (LimPercCmp_Uls_T_f32 > Rte_Prm_BmwStReqMgrSysProtnRednFacThd_Val())
            {
                /* CF069A_102 */
                *BmwEpsFctSts_Cnt_T_enum = BMWEPSFCTSTS_FCTTMPINFALLBACK;
            }
            else
            {
                /* CF069A_104 */
                *BmwEpsFctSts_Cnt_T_enum = BMWEPSFCTSTS_FCTAVIACTV12VEPS;
            }
        }
        else if (SysSt_Cnt_T_enum == SYSST_DI)
        {
            /* CF069A_103_106 */
            if (RcvrlFltPrsnt_Cnt_T_logl != FALSE)
            {
                /* CF069A_103 */
                *BmwEpsFctSts_Cnt_T_enum = BMWEPSFCTSTS_FCTTMPINFALLBACK;
            }
            else
            {
                /* CF069A_106 */
                *BmwEpsFctSts_Cnt_T_enum = BMWEPSFCTSTS_NOTAVISWDOFF;
            }
        }
        else
        {
            /* Initialization */
            *BmwEpsFctSts_Cnt_T_enum = BMWEPSFCTSTS_ININ;
        }
    }
}

/**********************************************************************************************************************
 * Name:        StsDrvrActvyTmr
 * Description: Determination of StsDrvrActvy
 * Inputs:      HwTq_HwNwtMtr_T_f32
 * Outputs:     StsDrvrActvy_Cnt_T_enum
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(StsDrvrActvy1, BmwStReqMgr_CODE) StsDrvrActvyTmr(VAR(float32, AUTOMATIC) HwTq_HwNwtMtr_T_f32)
{
    VAR(StsDrvrActvy1, AUTOMATIC) StsDrvrActvy_Cnt_T_enum;
    VAR(uint32, AUTOMATIC) TiSpan_Cnt_T_u32;

    if ((Abslt_f32_f32(HwTq_HwNwtMtr_T_f32) > Rte_Prm_BmwStReqMgrHwTqThd_Val()) ||
        (Abslt_f32_f32(HwTq_HwNwtMtr_T_f32 - *Rte_Pim_PrevHwTq()) > Rte_Prm_BmwStReqMgrStsDrvrActvyTqChgThd_Val()))
    {
        /* DriverActive */
        StsDrvrActvy_Cnt_T_enum = STSDRVRACTVY_DRVRACTVY;
        (void) Rte_Call_GetRefTmr100MicroSec32bit_Oper(Rte_Pim_DrvrActvRefTmr());
    }
    else
    {
        /* DriverInactive */
        (void) Rte_Call_GetTiSpan100MicroSec32bit_Oper(*Rte_Pim_DrvrActvRefTmr(), &TiSpan_Cnt_T_u32);

        if (TiSpan_Cnt_T_u32 > ((uint32) Rte_Prm_BmwStReqMgrDrvrActvTmrThd_Val() * (uint32) CNVMILLISECTOCNT_CNTPERMILLISEC_U16))
        {
            /* InactiveForEnoughTime */
            StsDrvrActvy_Cnt_T_enum = STSDRVRACTVY_NODRVRACTVY;
        }
        else
        {
            /* Active */
            StsDrvrActvy_Cnt_T_enum = STSDRVRACTVY_DRVRACTVY;
        }
    }

    *Rte_Pim_PrevHwTq() = HwTq_HwNwtMtr_T_f32;

    return StsDrvrActvy_Cnt_T_enum;
}

/**********************************************************************************************************************
 * Name:        AssiOnToOffFlg
 * Description: Determination of AssiOnToOffFlg
 * Inputs:      DiagcStsNonRcvrlReqDiFltPrsnt_Cnt_T_logl
 *              BmwVehCdnVld_Cnt_T_logl
 *              BmwVehSpdSts_Cnt_T_enum
 *              VehSpd_Kph_T_f32
 *              BmwVehCdn_Cnt_T_enum
 *              HwTq_HwNwtMtr_T_f32
 * Outputs:     AssiOnToOffFlg_Cnt_T_logl
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(boolean, BmwStReqMgr_CODE) AssiOnToOffFlg(VAR(boolean,       AUTOMATIC) DiagcStsNonRcvrlReqDiFltPrsnt_Cnt_T_logl,
                                                      VAR(boolean,       AUTOMATIC) BmwVehCdnVld_Cnt_T_logl,
                                                      VAR(BmwVehSpdSts1, AUTOMATIC) BmwVehSpdSts_Cnt_T_enum,
                                                      VAR(float32,       AUTOMATIC) VehSpd_Kph_T_f32,
                                                      VAR(BmwVehCdn1,    AUTOMATIC) BmwVehCdn_Cnt_T_enum,
                                                      VAR(StsDrvrActvy1, AUTOMATIC) StsDrvrActvy_Cnt_T_enum,
                                                      VAR(boolean,       AUTOMATIC) PinSt_Cnt_T_logl)
{
    VAR(boolean, AUTOMATIC) AssiOnToOffFlg_Cnt_T_logl;

    if (BmwVehCdnVld_Cnt_T_logl != FALSE)
    {
        /* VehCdnVld */
        if (BmwVehCdn_Cnt_T_enum != BMWVEHCDN_DRVG)
        {
            /* VehCndVldAndNotDrvg */
            if (((BmwVehSpdSts_Cnt_T_enum == BMWVEHSPDSTS_VLD) && (VehSpd_Kph_T_f32 < Rte_Prm_BmwStReqMgrSwtOffSpdLim_Val())) ||
                (BmwVehSpdSts_Cnt_T_enum == BMWVEHSPDSTS_SUBVALSETINUSFLSIGVEHSTANDG) ||
                ((BmwVehSpdSts_Cnt_T_enum == BMWVEHSPDSTS_SUBVALSETINUSRSIGNOINFO) && (StsDrvrActvy_Cnt_T_enum == STSDRVRACTVY_NODRVRACTVY)))
            {
                AssiOnToOffFlg_Cnt_T_logl = TRUE;
            }
            else
            {
                AssiOnToOffFlg_Cnt_T_logl = FALSE;
            }
        }
        else
        {
            /* VehCndVldAndDrvg */
            AssiOnToOffFlg_Cnt_T_logl = FALSE;
        }
    }
    else
    {
        /* VehCdnNotVld */
        if (PinSt_Cnt_T_logl != FALSE)
        {
            /* VehCndVldAndDrvg */
            AssiOnToOffFlg_Cnt_T_logl = FALSE;
        }
        else
        {
            /* Klemme_15_OFF */
            if (((BmwVehSpdSts_Cnt_T_enum == BMWVEHSPDSTS_VLD) && (VehSpd_Kph_T_f32 < Rte_Prm_BmwStReqMgrSwtOffSpdLim_Val())) ||
                (BmwVehSpdSts_Cnt_T_enum == BMWVEHSPDSTS_SUBVALSETINUSFLSIGVEHSTANDG) ||
                ((BmwVehSpdSts_Cnt_T_enum == BMWVEHSPDSTS_SUBVALSETINUSRSIGNOINFO) &&
                 (StsDrvrActvy_Cnt_T_enum == STSDRVRACTVY_NODRVRACTVY) &&
                 (BmwVehCdn_Cnt_T_enum != BMWVEHCDN_DRVG)))
            {
                AssiOnToOffFlg_Cnt_T_logl = TRUE;
            }
            else
            {
                AssiOnToOffFlg_Cnt_T_logl = FALSE;
            }
        }
    }

    if ((DiagcStsNonRcvrlReqDiFltPrsnt_Cnt_T_logl != FALSE) || (AssiOnToOffFlg_Cnt_T_logl != FALSE))
    {
        AssiOnToOffFlg_Cnt_T_logl = TRUE;
    }
    else
    {
        AssiOnToOffFlg_Cnt_T_logl = FALSE;
    }

    return AssiOnToOffFlg_Cnt_T_logl;
}

/**********************************************************************************************************************
 * Name:        AllwToOff
 * Description: Implementation of AllwToOff block from FDD
 * Inputs:      BmwVehCdn_Cnt_T_enum
 *              IgnLine_Cnt_T_logl
 * Outputs:     AllwToOff_Cnt_T_logl
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(boolean, BmwStReqMgr_CODE) AllwToOff(VAR(BmwVehCdn1, AUTOMATIC) BmwVehCdn_Cnt_T_enum,
                                                 VAR(boolean,    AUTOMATIC) IgnLine_Cnt_T_logl)
{
    VAR(uint32,  AUTOMATIC) TiSpan_Cnt_T_u32;
    VAR(boolean, AUTOMATIC) LvngCnd_Cnt_T_logl;
    VAR(boolean, AUTOMATIC) AllwToOff_Cnt_T_logl;

    /* Cntr */
    if (BmwVehCdn_Cnt_T_enum == BMWVEHCDN_LVNG)
    {
        /* LvngCndElpdTi */
        (void) Rte_Call_GetTiSpan100MicroSec32bit_Oper(*Rte_Pim_BmwVehCdnLvngDurn(), &TiSpan_Cnt_T_u32);

        if (TiSpan_Cnt_T_u32 >= ((uint32) Rte_Prm_BmwStReqMgrAllwToOffThd_Val() * (uint32) CNVMILLISECTOCNT_CNTPERMILLISEC_U16))
        {
            /* LvngCndDurnTrue */
            LvngCnd_Cnt_T_logl = TRUE;
        }
        else
        {
            /* LvngCndDurnFalse */
            LvngCnd_Cnt_T_logl = FALSE;
        }
    }
    else
    {
        /* GetTi */
        (void) Rte_Call_GetRefTmr100MicroSec32bit_Oper(Rte_Pim_BmwVehCdnLvngDurn());
        *Rte_Pim_BmwVehCdnLvngDurn() += (uint32) ONECNT_CNT_U16;
        LvngCnd_Cnt_T_logl = FALSE;
    }

    if (((BmwVehCdn_Cnt_T_enum == BMWVEHCDN_PRKGNBNOK) ||
         (BmwVehCdn_Cnt_T_enum == BMWVEHCDN_PRKGBNOK) ||
         (BmwVehCdn_Cnt_T_enum == BMWVEHCDN_FCTCUSTNOTINFZG) ||
         (LvngCnd_Cnt_T_logl != FALSE)) &&
        (IgnLine_Cnt_T_logl == FALSE) &&
        (*Rte_Pim_PrevTarEcuSt() == ONE_CNT_U08))
    {
        /* SetAllwToOff */
        AllwToOff_Cnt_T_logl = TRUE;
    }
    else
    {
        /* ClrAllwToOff */
        AllwToOff_Cnt_T_logl = FALSE;
    }

    return AllwToOff_Cnt_T_logl;
}

/**********************************************************************************************************************
 * Name:        TargetECUState
 * Description: Target ECU State Machine
 * Inputs:      DiagcStsNonRcvrlReqDiFltPrsnt_Cnt_T_logl
 *              BmwVehCdn_Cnt_T_enum
 *              AssiOnToOffFlg_Cnt_T_logl
 *              AllwTranToDi_Cnt_T_logl
 * Outputs:     TarEcuSt_Cnt_T_enum
 *              PwrSplyEnaReq_Cnt_T_logl
 *              SysStReqEna_Cnt_T_logl
 *              SysOperMotTqCmdSca_Uls_T_f32
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(void, BmwStReqMgr_CODE) TargetECUState(VAR(boolean,    AUTOMATIC) DiagcStsNonRcvrlReqDiFltPrsnt_Cnt_T_logl,
                                                   VAR(BmwVehCdn1, AUTOMATIC) BmwVehCdn_Cnt_T_enum,
                                                   VAR(boolean,    AUTOMATIC) AssiOnToOffFlg_Cnt_T_logl,
                                                   VAR(boolean,    AUTOMATIC) AllwTranToDi_Cnt_T_logl,
                                                   VAR(boolean,    AUTOMATIC) IgnLine_Cnt_T_logl,
                                                   VAR(boolean,    AUTOMATIC) AllwToOff_Cnt_T_logl,
                                                   P2VAR(SysSt1,  AUTOMATIC, BmwStReqMgr_VAR) TarEcuSt_Cnt_T_enum,
                                                   P2VAR(boolean, AUTOMATIC, BmwStReqMgr_VAR) PwrSplyEnaReq_Cnt_T_logl,
                                                   P2VAR(boolean, AUTOMATIC, BmwStReqMgr_VAR) SysStReqEna_Cnt_T_logl,
                                                   P2VAR(float32, AUTOMATIC, BmwStReqMgr_VAR) SysOperMotTqCmdSca_Uls_T_f32)
{
    *TarEcuSt_Cnt_T_enum = (SysSt1) (*Rte_Pim_PrevTarEcuSt() - ONE_CNT_U08);

    /* Transitions */
    switch (*TarEcuSt_Cnt_T_enum)
    {
        case SYSST_DI:
        {
            /* DISABLE */
            if ((IgnLine_Cnt_T_logl == FALSE) &&
                (AllwToOff_Cnt_T_logl != FALSE))
            {
                *TarEcuSt_Cnt_T_enum = SYSST_OFF;
            }
            else if (((BmwVehCdn_Cnt_T_enum == BMWVEHCDN_CHKDIAGCANLS) ||
                      (BmwVehCdn_Cnt_T_enum == BMWVEHCDN_DRVRPREPGFOROPER) ||
                      (BmwVehCdn_Cnt_T_enum == BMWVEHCDN_DRVRPREPGFOREXITOPER) ||
                      (BmwVehCdn_Cnt_T_enum == BMWVEHCDN_DRVG)) &&
                     (DiagcStsNonRcvrlReqDiFltPrsnt_Cnt_T_logl == FALSE))
            {
                *TarEcuSt_Cnt_T_enum = SYSST_WRMININ;
            }
            else
            {
                /* Do nothing */
            }
        }
        break;

        case SYSST_OFF:
        {
            /* OFF */
            if ((BmwVehCdn_Cnt_T_enum == BMWVEHCDN_CHKDIAGCANLS) ||
                (BmwVehCdn_Cnt_T_enum == BMWVEHCDN_DRVRPREPGFOROPER) ||
                (BmwVehCdn_Cnt_T_enum == BMWVEHCDN_DRVG) ||
                (BmwVehCdn_Cnt_T_enum == BMWVEHCDN_DRVRPREPGFOREXITOPER))
            {
                *TarEcuSt_Cnt_T_enum = SYSST_WRMININ;
            }
        }
        break;

        case SYSST_ENA:
        {
            /* ENABLE */
            if ((AssiOnToOffFlg_Cnt_T_logl != FALSE) && (AllwTranToDi_Cnt_T_logl != FALSE))
            {
                *TarEcuSt_Cnt_T_enum = SYSST_DI;
            }
        }
        break;

        case SYSST_WRMININ:
        {
            /* WARMININ */
            if ((BmwVehCdn_Cnt_T_enum == BMWVEHCDN_DRVG) && (DiagcStsNonRcvrlReqDiFltPrsnt_Cnt_T_logl == FALSE))
            {
                *TarEcuSt_Cnt_T_enum = SYSST_ENA;
            }
            else if (((BmwVehCdn_Cnt_T_enum == BMWVEHCDN_PRKGNBNOK) ||
                      (BmwVehCdn_Cnt_T_enum == BMWVEHCDN_PRKGBNOK) ||
                      (BmwVehCdn_Cnt_T_enum == BMWVEHCDN_FCTCUSTNOTINFZG) ||
                      (BmwVehCdn_Cnt_T_enum == BMWVEHCDN_LVNG) ||
                      (DiagcStsNonRcvrlReqDiFltPrsnt_Cnt_T_logl != FALSE)) &&
                     (AllwTranToDi_Cnt_T_logl != FALSE))
            {
                *TarEcuSt_Cnt_T_enum = SYSST_DI;
            }
            else
            {
                /* Do nothing */
            }
        }
        break;

        default:
        {
            /* Set state to WARMININ during initialization */
            *TarEcuSt_Cnt_T_enum = SYSST_WRMININ;
        }
        break;
    }

    /* On entry */
    switch (*TarEcuSt_Cnt_T_enum)
    {
        case SYSST_DI:
        {
            /* DISABLE */
            *PwrSplyEnaReq_Cnt_T_logl      = TRUE;
            *SysStReqEna_Cnt_T_logl        = FALSE;
            *SysOperMotTqCmdSca_Uls_T_f32  = ZERO_ULS_F32;
        }
        break;

        case SYSST_OFF:
        {
            /* OFF */
            *PwrSplyEnaReq_Cnt_T_logl      = FALSE;
            *SysStReqEna_Cnt_T_logl        = FALSE;
            *SysOperMotTqCmdSca_Uls_T_f32  = ZERO_ULS_F32;
        }
        break;

        case SYSST_ENA:
        {
            /* ENABLE */
            *PwrSplyEnaReq_Cnt_T_logl      = TRUE;
            *SysStReqEna_Cnt_T_logl        = TRUE;
            *SysOperMotTqCmdSca_Uls_T_f32  = ONE_ULS_F32;
        }
        break;

        default: /* SYSST_WRMININ */
        {
            /* WARMININ */
            *PwrSplyEnaReq_Cnt_T_logl      = TRUE;
            *SysStReqEna_Cnt_T_logl        = FALSE;
            *SysOperMotTqCmdSca_Uls_T_f32  = ZERO_ULS_F32;
        }
        break;
    }
}


#define BmwStReqMgr_STOP_SEC_CODE
#include "BmwStReqMgr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
