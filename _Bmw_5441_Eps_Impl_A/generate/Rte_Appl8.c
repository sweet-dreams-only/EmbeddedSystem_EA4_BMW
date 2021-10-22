/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_Appl8.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  RTE implementation file
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* PRQA S 0777, 0779, 0781, 0857 EOF */ /* MD_MSR_5.1_777, MD_MSR_5.1_779, MD_Rte_0781, MD_MSR_1.1_857 */

#define RTE_CORE
#include "Os.h" /* PRQA S 0828, 0883 */ /* MD_MSR_1.1_828, MD_Rte_Os */
#include "Rte_Type.h"
#include "Rte_Main.h"

#include "Rte_AAACalRegn01Inin01GroupA_Dummy.h"
#include "Rte_AAACalRegn01Inin01GroupC_Dummy.h"
#include "Rte_AAACalRegn01Inin01GroupD_Dummy.h"
#include "Rte_AAACalRegn01Inin01_Dummy.h"
#include "Rte_AAACalRegn01IninOptSetA01_Dummy.h"
#include "Rte_AAACalRegn02Rt01GroupA_Dummy.h"
#include "Rte_AAACalRegn02Rt01GroupC_Dummy.h"
#include "Rte_AAACalRegn02Rt01GroupD_Dummy.h"
#include "Rte_AAACalRegn02Rt01_Dummy.h"
#include "Rte_BacComIf.h"
#include "Rte_BattVltg.h"
#include "Rte_BattVltgCorrln.h"
#include "Rte_BmwDiagcSrvHndlg.h"
#include "Rte_BmwDrvgDynStMac.h"
#include "Rte_BmwFltHndlg.h"
#include "Rte_BmwHaptcFb.h"
#include "Rte_BmwHwAgArbnAndEotPosn.h"
#include "Rte_BmwHwTqOvrlArbn.h"
#include "Rte_BmwMotTqOvrlArbn.h"
#include "Rte_BmwMsgSlot107Bas0Repn1BusFrChA.h"
#include "Rte_BmwMsgSlot108Bas0Repn2BusFrChA.h"
#include "Rte_BmwMsgSlot121Bas1Repn2BusFrChA.h"
#include "Rte_BmwMsgSlot234Bas1Repn2BusFrChA.h"
#include "Rte_BmwMsgSlot269Bas2Repn4BusFrChA.h"
#include "Rte_BmwMsgSlot274Bas0Repn8BusFrChA.h"
#include "Rte_BmwMsgSlot274Bas2Repn4BusFrChA.h"
#include "Rte_BmwMsgSlot276Bas4Repn8BusFrChA.h"
#include "Rte_BmwMsgSlot315Bas0Repn1BusFrChA.h"
#include "Rte_BmwMsgSlot49Bas0Repn2BusFrChA.h"
#include "Rte_BmwMsgSlot49Bas1Repn2BusFrChA.h"
#include "Rte_BmwMsgSlot51Bas0Repn2BusFrChA.h"
#include "Rte_BmwMsgSlot53Bas3Repn8BusFrChA.h"
#include "Rte_BmwMsgSlot55Bas0Repn2BusFrChA.h"
#include "Rte_BmwMsgSlot55Bas3Repn4BusFrChA.h"
#include "Rte_BmwMsgSlot56Bas0Repn2BusFrChA.h"
#include "Rte_BmwMsgSlot68Bas0Repn2BusFrChA.h"
#include "Rte_BmwMsgSlot68Bas1Repn2BusFrChA.h"
#include "Rte_BmwPwrPrkgDampg.h"
#include "Rte_BmwSplyCurrLim.h"
#include "Rte_BmwStReqMgr.h"
#include "Rte_BmwSwFctDi.h"
#include "Rte_BmwTqOvrlCdngAndDrvgDynFac.h"
#include "Rte_BmwTrfcJamAssiDampg.h"
#include "Rte_BmwTunSetHndlr.h"
#include "Rte_BmwVehSpd.h"
#include "Rte_BswM.h"
#include "Rte_CDD_Adc0CfgAndUse.h"
#include "Rte_CDD_Adc1CfgAndUse.h"
#include "Rte_CDD_AdcDiagc.h"
#include "Rte_CDD_BattRtnCurr.h"
#include "Rte_CDD_Bmw5441McuCfg.h"
#include "Rte_CDD_ChkPtAppl10.h"
#include "Rte_CDD_ChkPtAppl7.h"
#include "Rte_CDD_ChkPtAppl8.h"
#include "Rte_CDD_ChkPtAppl9.h"
#include "Rte_CDD_CoreVltgMonr.h"
#include "Rte_CDD_CurrMeas.h"
#include "Rte_CDD_CurrMeasArbn.h"
#include "Rte_CDD_DataAndAdrPar.h"
#include "Rte_CDD_DmaCfgAndUse.h"
#include "Rte_CDD_EcmOutpAndDiagc.h"
#include "Rte_CDD_ExcpnHndlg.h"
#include "Rte_CDD_FlsMem.h"
#include "Rte_CDD_GuardCfgAndDiagc.h"
#include "Rte_CDD_HwTq4Meas.h"
#include "Rte_CDD_HwTq5Meas.h"
#include "Rte_CDD_McuCoreCfgAndDiagc.h"
#include "Rte_CDD_McuDiagc.h"
#include "Rte_CDD_MotAg0Meas.h"
#include "Rte_CDD_MotAg1Meas.h"
#include "Rte_CDD_MotAg3Meas.h"
#include "Rte_CDD_MotAg4Meas.h"
#include "Rte_CDD_MotAgCmp.h"
#include "Rte_CDD_MotCtrlMgr.h"
#include "Rte_CDD_MotCurrRegVltgLimr.h"
#include "Rte_CDD_MotVel.h"
#include "Rte_CDD_NvMProxy.h"
#include "Rte_CDD_NxtrTi.h"
#include "Rte_CDD_RamMem.h"
#include "Rte_CDD_SinVltgGenn.h"
#include "Rte_CDD_SyncCrc.h"
#include "Rte_CDD_TSG31CfgAndUse.h"
#include "Rte_CDD_Tauj0CfgAndUse.h"
#include "Rte_CDD_VrfyCritReg.h"
#include "Rte_CDD_XcpIf.h"
#include "Rte_CDD_XcpIfXcpEve2MilliSecDataAcqn.h"
#include "Rte_ClsdLoopDampg.h"
#include "Rte_ClsdLoopHys.h"
#include "Rte_CmnMfgSrv.h"
#include "Rte_CmnMfgSrvIf.h"
#include "Rte_CmplncErr.h"
#include "Rte_Coding.h"
#include "Rte_ComM.h"
#include "Rte_CtrldVelRtn.h"
#include "Rte_CurrMeasCorrln.h"
#include "Rte_Darh.h"
#include "Rte_Dcm.h"
#include "Rte_DemMaster_0.h"
#include "Rte_DemSatellite_0.h"
#include "Rte_DemWrapper.h"
#include "Rte_Det.h"
#include "Rte_DiagcMgr.h"
#include "Rte_DiagcMgrProxyAppl10.h"
#include "Rte_DiagcMgrProxyAppl7.h"
#include "Rte_DiagcMgrProxyAppl8.h"
#include "Rte_DiagcMgrProxyAppl9.h"
#include "Rte_DiagcMgrStub.h"
#include "Rte_Dlog.h"
#include "Rte_DutyCycThermProtn.h"
#include "Rte_EcuM.h"
#include "Rte_EcuTMeas.h"
#include "Rte_Effort.h"
#include "Rte_ElecPwrCns.h"
#include "Rte_EotProtn.h"
#include "Rte_EpsStEstimn.h"
#include "Rte_FalbckAssi.h"
#include "Rte_FltInj.h"
#include "Rte_GateDrv0Ctrl.h"
#include "Rte_GlbLimr.h"
#include "Rte_HiLoadStallLimr.h"
#include "Rte_HwRefTqSum.h"
#include "Rte_HwTqArbn.h"
#include "Rte_HwTqCorrln.h"
#include "Rte_HwTqTrakgCtrl.h"
#include "Rte_InertiaCmpVel.h"
#include "Rte_IoHwAb.h"
#include "Rte_LimrCdng.h"
#include "Rte_LoaMgr.h"
#include "Rte_LrnPinionCentr.h"
#include "Rte_LrndRackCentr.h"
#include "Rte_McalErrHndlg.h"
#include "Rte_McuErrInj.h"
#include "Rte_MotAgCorrln.h"
#include "Rte_MotCtrlPrmEstimn.h"
#include "Rte_MotCurrPeakEstimn.h"
#include "Rte_MotCurrRegCfg.h"
#include "Rte_MotQuadDetn.h"
#include "Rte_MotRefMdl.h"
#include "Rte_MotTqCalcd.h"
#include "Rte_MotTqCmdSca.h"
#include "Rte_MotTqTranlDampg.h"
#include "Rte_MotVelCtrl.h"
#include "Rte_NvM.h"
#include "Rte_NvMProxy.h"
#include "Rte_NxtrCalIds.h"
#include "Rte_NxtrMath.h"
#include "Rte_NxtrSwIds.h"
#include "Rte_Omc.h"
#include "Rte_Os_OsCore_CORE0_swc.h"
#include "Rte_PhaDiscnct.h"
#include "Rte_PolarityCfg.h"
#include "Rte_PosnTrakgServo.h"
#include "Rte_ProgMfgSrv.h"
#include "Rte_PullCmpActv.h"
#include "Rte_PwrDiscnct.h"
#include "Rte_PwrLimr.h"
#include "Rte_PwrSply.h"
#include "Rte_PwrUpSeq.h"
#include "Rte_Rmh.h"
#include "Rte_Rmh_Cdd.h"
#include "Rte_RvsBattProtn.h"
#include "Rte_ShtdwnMech.h"
#include "Rte_StOutpCtrl.h"
#include "Rte_StdDiag.h"
#include "Rte_SteerCmdArbnAndLim.h"
#include "Rte_Stm.h"
#include "Rte_Swp.h"
#include "Rte_SysFricLrng.h"
#include "Rte_SysKineAndEff.h"
#include "Rte_SysStMod.h"
#include "Rte_SysTime.h"
#include "Rte_TEstimn.h"
#include "Rte_TmplMonr.h"
#include "Rte_TqOscn.h"
#include "Rte_TunSelnAuthy.h"
#include "Rte_TunSelnMngt.h"
#include "Rte_TurnCntrCorrln.h"
#include "Rte_VehSigCdng.h"
#include "Rte_VehSpdLimr.h"
#include "Rte_Vin.h"
#include "Rte_WdgM_Appl10.h"
#include "Rte_WdgM_Appl7.h"
#include "Rte_WdgM_Appl8.h"
#include "Rte_WdgM_Appl9.h"
#include "SchM_BswM.h"
#include "SchM_ChkPt.h"
#include "SchM_Com.h"
#include "SchM_ComM.h"
#include "SchM_Dcm.h"
#include "SchM_Dem.h"
#include "SchM_Det.h"
#include "SchM_Dio.h"
#include "SchM_EcuM.h"
#include "SchM_Fee_30_SmallSector.h"
#include "SchM_Fls.h"
#include "SchM_Fr.h"
#include "SchM_FrIf.h"
#include "SchM_FrSM.h"
#include "SchM_FrTp.h"
#include "SchM_FrTrcv_30_Tja1082.h"
#include "SchM_IoHwAb.h"
#include "SchM_IpduM.h"
#include "SchM_Mcu.h"
#include "SchM_NvM.h"
#include "SchM_NvMProxy.h"
#include "SchM_PduR.h"
#include "SchM_Port.h"
#include "SchM_Spi.h"
#include "SchM_WdgM.h"
#include "SchM_Wdg_59_DriverA.h"
#include "SchM_Xcp.h"

#include "Rte_Hook.h"

#include "Com.h"
#if defined(IL_ASRCOM_VERSION)
# define RTE_USE_COM_TXSIGNAL_RDACCESS
#endif

#include "Rte_Cbk.h"

/* AUTOSAR 3.x compatibility */
#if !defined (RTE_LOCAL)
# define RTE_LOCAL static
#endif


/**********************************************************************************************************************
 * API for enable / disable interrupts global
 *********************************************************************************************************************/

#if defined(osDisableGlobalUM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_DisableAllInterrupts() osDisableGlobalUM()   /* MICROSAR OS */
#else
# define Rte_DisableAllInterrupts() DisableAllInterrupts()   /* AUTOSAR OS */
#endif

#if defined(osEnableGlobalUM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_EnableAllInterrupts() osEnableGlobalUM()   /* MICROSAR OS */
#else
# define Rte_EnableAllInterrupts() EnableAllInterrupts()   /* AUTOSAR OS */
#endif

/**********************************************************************************************************************
 * API for enable / disable interrupts up to the systemLevel
 *********************************************************************************************************************/

#if defined(osDisableLevelUM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_DisableOSInterrupts() osDisableLevelUM()   /* MICROSAR OS */
#else
# define Rte_DisableOSInterrupts() SuspendOSInterrupts()   /* AUTOSAR OS */
#endif

#if defined(osEnableLevelUM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_EnableOSInterrupts() osEnableLevelUM()   /* MICROSAR OS */
#else
# define Rte_EnableOSInterrupts() ResumeOSInterrupts()   /* AUTOSAR OS */
#endif


/**********************************************************************************************************************
 * Buffers for unqueued S/R
 *********************************************************************************************************************/

#define RTE_START_SEC_VAR_Appl8_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

VAR(float32, RTE_VAR_INIT) Rte_CDD_BattRtnCurr_BattRtnCurrAmpr_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(SigQlfr1, RTE_VAR_INIT) Rte_CDD_BattRtnCurr_BattRtnCurrStsQlfr_Val = 15U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_ElecPwrCns_ElecInpPwrEstim_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_ElecPwrCns_SplyCurrEstim_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_INIT) Rte_TurnCntrCorrln_TurnCntrCorrlnSts_Val = 3U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_INIT) Rte_TurnCntrCorrln_TurnCntrIdptSig_Val = 2U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */

#define RTE_STOP_SEC_VAR_Appl8_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * Per-Instance Memory
 *********************************************************************************************************************/

#define RTE_START_SEC_VAR_DEFAULT_RTE_Appl8_PIM_GROUP_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

VAR(float32, RTE_VAR_DEFAULT_RTE_Appl8_PIM_GROUP) Rte_CDD_BattRtnCurr_dBattRtnCurrBfrSatn; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl8_PIM_GROUP) Rte_ElecPwrCns_dElecPwrCnsDrpInpPwr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl8_PIM_GROUP) Rte_ElecPwrCns_dElecPwrCnsModInpPwr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl8_PIM_GROUP) Rte_ElecPwrCns_dElecPwrCnsMotCurrDaxEstim; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl8_PIM_GROUP) Rte_ElecPwrCns_dElecPwrCnsMotCurrQaxEstim; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl8_PIM_GROUP) Rte_DiagcMgrProxyAppl8_PrevClrNtcFlg8; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl8_PIM_GROUP) Rte_TurnCntrCorrln_MotAgATurnCntrRollgCntPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl8_PIM_GROUP) Rte_TurnCntrCorrln_MotAgATurnCntrStallCntPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl8_PIM_GROUP) Rte_TurnCntrCorrln_MotAgBTurnCntrRollgCntPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl8_PIM_GROUP) Rte_TurnCntrCorrln_MotAgBTurnCntrStallCntPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(Ary1D_NtcInfoRec4_DiagcMgrProxyAppl8, RTE_VAR_DEFAULT_RTE_Appl8_PIM_GROUP) Rte_DiagcMgrProxyAppl8_DiagcMgrNtcInfo8Ary; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(Ary1D_s16_DiagcMgrProxyAppl8, RTE_VAR_DEFAULT_RTE_Appl8_PIM_GROUP) Rte_DiagcMgrProxyAppl8_DiagcMgrNtcInfo8DebCntrAry; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl8_PIM_GROUP) Rte_CDD_BattRtnCurr_BattCurrEstimDifLpFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(DiagcDataRec2, RTE_VAR_DEFAULT_RTE_Appl8_PIM_GROUP) Rte_DiagcMgrProxyAppl8_DiagcData8; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(DiagcDataRec2, RTE_VAR_DEFAULT_RTE_Appl8_PIM_GROUP) Rte_DiagcMgrProxyAppl8_ProxySetNtcData8; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */

#define RTE_STOP_SEC_VAR_DEFAULT_RTE_Appl8_PIM_GROUP_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
/**********************************************************************************************************************
 * Defines for Rte_ComSendSignalProxy
 *********************************************************************************************************************/
#define RTE_COM_SENDSIGNALPROXY_NOCHANGE       (0U)
#define RTE_COM_SENDSIGNALPROXY_SEND           (1U)
#define RTE_COM_SENDSIGNALPROXY_INVALIDATE     (2U)



/**********************************************************************************************************************
 * Update Flags for each Receiver with enableUpdate != 0
 *********************************************************************************************************************/



/**********************************************************************************************************************
 * Internal C/S connections
 *********************************************************************************************************************/
#define Rte_CS_ClientConfigIndex_Dcm_RoutineServices_CheckNcd_Routine_Start 0U
#define Rte_CS_ClientConfigIndex_Dcm_DataServices_DID_37FE_Cps_ConditionCheckRead 0U
#define Rte_CS_ClientConfigIndex_Dcm_DataServices_DID_37FE_Cps_ReadData 0U
#define Rte_CS_ClientConfigIndex_Dcm_RoutineServices_ReadNcd_Routine_Start 0U
#define Rte_CS_ClientConfigIndex_Dcm_DataServices_DID_37FF_ReadProtocolData_ReadData 0U
#define Rte_CS_ClientConfigIndex_Dcm_RoutineServices_WriteNcd_Routine_Start 0U

#define RTE_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

FUNC(void, RTE_CODE) Rte_MemClr(P2VAR(void, AUTOMATIC, RTE_VAR_NOINIT) ptr, uint16_least num); /* PRQA S 0850, 3447, 3408 */ /* MD_MSR_19.8, MD_Rte_3447, MD_Rte_3408 */
FUNC(void, RTE_CODE) Rte_MemCpy(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) destination, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, uint32_least num); /* PRQA S 0850, 1505, 3447, 3408 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_3447, MD_Rte_3408 */
FUNC(void, RTE_CODE) Rte_MemCpy32(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) destination, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, uint32_least num); /* PRQA S 0850, 1505, 3447, 3408 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_3447, MD_Rte_3408 */

#define RTE_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Helper functions for mode management
 *********************************************************************************************************************/
FUNC(uint8, RTE_CODE) Rte_GetInternalModeIndex_Coding_DataMode(uint8 mode); /* PRQA S 3408 */ /* MD_Rte_3408 */
/**********************************************************************************************************************
 * Helper functions for mode management
 *********************************************************************************************************************/
FUNC(uint8, RTE_CODE) Rte_GetInternalModeIndex_Coding_BusComMode(uint8 mode); /* PRQA S 3408 */ /* MD_Rte_3408 */
FUNC(uint8, RTE_CODE) Rte_GetInternalModeIndex_Coding_LifeCycle(Coding_LifeCycleRequestType mode); /* PRQA S 3408 */ /* MD_Rte_3408 */
FUNC(uint8, RTE_CODE) Rte_GetInternalModeIndex_Darh_LifeCycle(Darh_LifeCycleRequestType mode); /* PRQA S 3408 */ /* MD_Rte_3408 */
FUNC(uint8, RTE_CODE) Rte_GetInternalModeIndex_DcmCommunicationControl(Dcm_CommunicationModeType mode); /* PRQA S 3408 */ /* MD_Rte_3408 */
FUNC(uint8, RTE_CODE) Rte_GetInternalModeIndex_DcmDiagnosticSessionControl(Dcm_DiagnosticSessionControlType mode); /* PRQA S 3408 */ /* MD_Rte_3408 */
FUNC(uint8, RTE_CODE) Rte_GetInternalModeIndex_DcmEcuReset(Dcm_EcuResetType mode); /* PRQA S 3408 */ /* MD_Rte_3408 */
FUNC(uint8, RTE_CODE) Rte_GetInternalModeIndex_Dlog_LifeCycle(Dlog_LifeCycleRequestType mode); /* PRQA S 3408 */ /* MD_Rte_3408 */
FUNC(uint8, RTE_CODE) Rte_GetInternalModeIndex_StdDiag_LifeCycle(StdDiag_LifeCycleRequestType mode); /* PRQA S 3408 */ /* MD_Rte_3408 */
FUNC(uint8, RTE_CODE) Rte_GetInternalModeIndex_StdDiag_NormalCommunicationModeGroup(NormalCommunicationModeType mode); /* PRQA S 3408 */ /* MD_Rte_3408 */
FUNC(uint8, RTE_CODE) Rte_GetInternalModeIndex_SysTime_LifeCycle(SysTime_LifeCycleRequestType mode); /* PRQA S 3408 */ /* MD_Rte_3408 */
FUNC(uint8, RTE_CODE) Rte_GetInternalModeIndex_Vin_LifeCycle(Vin_LifeCycleRequestType mode); /* PRQA S 3408 */ /* MD_Rte_3408 */
FUNC(uint8, RTE_CODE) Rte_GetInternalModeIndex_Vin_VinComMode(uint8 mode); /* PRQA S 3408 */ /* MD_Rte_3408 */
/**********************************************************************************************************************
 * Helper functions for mode management
 *********************************************************************************************************************/
FUNC(uint8, RTE_CODE) Rte_GetInternalModeIndex_OmcExtendedOperatingMode(Omc_ExtendedOperatingModeType mode); /* PRQA S 3408 */ /* MD_Rte_3408 */
FUNC(uint8, RTE_CODE) Rte_GetInternalModeIndex_OmcOperatingMode(Omc_OperatingModeType mode); /* PRQA S 3408 */ /* MD_Rte_3408 */
/**********************************************************************************************************************
 * Helper functions for mode management
 *********************************************************************************************************************/
FUNC(uint8, RTE_CODE) Rte_GetInternalModeIndex_Vin_ChangeIndicator(uint8 mode); /* PRQA S 3408 */ /* MD_Rte_3408 */

#define RTE_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * Timer handling
 *********************************************************************************************************************/

#if defined OS_US2TICKS_FrCycleCounter
# define RTE_USEC_FrCycleCounter OS_US2TICKS_FrCycleCounter
#else
# define RTE_USEC_FrCycleCounter(val) ((TickType)RTE_CONST_USEC_FrCycleCounter_##val) /* PRQA S 0342 */ /* MD_MSR_19.13_0342 */
#endif

#if defined OS_MS2TICKS_FrCycleCounter
# define RTE_MSEC_FrCycleCounter OS_MS2TICKS_FrCycleCounter
#else
# define RTE_MSEC_FrCycleCounter(val) ((TickType)RTE_CONST_MSEC_FrCycleCounter_##val) /* PRQA S 0342 */ /* MD_MSR_19.13_0342 */
#endif

#if defined OS_SEC2TICKS_FrCycleCounter
# define RTE_SEC_FrCycleCounter OS_SEC2TICKS_FrCycleCounter
#else
# define RTE_SEC_FrCycleCounter(val)  ((TickType)RTE_CONST_SEC_FrCycleCounter_##val) /* PRQA S 0342 */ /* MD_MSR_19.13_0342 */
#endif

#if defined OS_US2TICKS_OsCounter
# define RTE_USEC_OsCounter OS_US2TICKS_OsCounter
#else
# define RTE_USEC_OsCounter(val) ((TickType)RTE_CONST_USEC_OsCounter_##val) /* PRQA S 0342 */ /* MD_MSR_19.13_0342 */
#endif

#if defined OS_MS2TICKS_OsCounter
# define RTE_MSEC_OsCounter OS_MS2TICKS_OsCounter
#else
# define RTE_MSEC_OsCounter(val) ((TickType)RTE_CONST_MSEC_OsCounter_##val) /* PRQA S 0342 */ /* MD_MSR_19.13_0342 */
#endif

#if defined OS_SEC2TICKS_OsCounter
# define RTE_SEC_OsCounter OS_SEC2TICKS_OsCounter
#else
# define RTE_SEC_OsCounter(val)  ((TickType)RTE_CONST_SEC_OsCounter_##val) /* PRQA S 0342 */ /* MD_MSR_19.13_0342 */
#endif

#define RTE_CONST_MSEC_FrCycleCounter_0 (0UL)
#define RTE_CONST_MSEC_OsCounter_0 (0UL)
#define RTE_CONST_MSEC_FrCycleCounter_10 (2UL)
#define RTE_CONST_MSEC_OsCounter_10 (10UL)
#define RTE_CONST_MSEC_OsCounter_100 (100UL)
#define RTE_CONST_MSEC_OsCounter_2 (2UL)
#define RTE_CONST_MSEC_OsCounter_4 (4UL)
#define RTE_CONST_MSEC_FrCycleCounter_5 (1UL)
#define RTE_CONST_MSEC_OsCounter_5 (5UL)

#define RTE_CONST_SEC_OsCounter_0 (0UL)
#define RTE_CONST_SEC_OsCounter_1 (1000UL)


/**********************************************************************************************************************
 * Internal definitions
 *********************************************************************************************************************/

#define RTE_TASK_TIMEOUT_EVENT_MASK   ((EventMaskType)0x01)
#define RTE_TASK_WAITPOINT_EVENT_MASK ((EventMaskType)0x02)

/**********************************************************************************************************************
 * RTE life cycle API
 *********************************************************************************************************************/

#define RTE_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


FUNC(void, RTE_CODE) Rte_InitMemory_Appl8(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  /* set default values for internal data */
  Rte_CDD_BattRtnCurr_BattRtnCurrAmpr_Val = 0.0F;
  Rte_CDD_BattRtnCurr_BattRtnCurrStsQlfr_Val = 15U;
  Rte_ElecPwrCns_ElecInpPwrEstim_Val = 0.0F;
  Rte_ElecPwrCns_SplyCurrEstim_Val = 0.0F;
  Rte_TurnCntrCorrln_TurnCntrCorrlnSts_Val = 3U;
  Rte_TurnCntrCorrln_TurnCntrIdptSig_Val = 2U;

}


/**********************************************************************************************************************
 * Task bodies for RTE controlled tasks
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Task:     Task_10ms_Appl8
 * Priority: 46
 * Schedule: FULL
 * Alarm:    Cycle Time 0.01 s Alarm Offset 0 s
 *********************************************************************************************************************/
TASK(Task_10ms_Appl8) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_14.1 */
{

  /* call runnable */
  ChkPt_10msAppl8Strt();

  /* call runnable */
  ElecPwrCnsPer1();

  /* call runnable */
  DiagcMgrProxyAppl8Per1();

  /* call runnable */
  ChkPt_10msAppl8End();

  (void)TerminateTask(); /* PRQA S 3417 */ /* MD_Rte_Os */
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 * Task:     Task_2ms_Appl8
 * Priority: 77
 * Schedule: FULL
 * Alarm:    Cycle Time 0.002 s Alarm Offset 0 s
 *********************************************************************************************************************/
TASK(Task_2ms_Appl8) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_14.1 */
{

  /* call runnable */
  ChkPt_2msAppl8Strt();

  /* call runnable */
  BattRtnCurrPer2();

  /* call runnable */
  TurnCntrCorrlnPer1();

  /* call runnable */
  ChkPt_2msAppl8End();

  (void)TerminateTask(); /* PRQA S 3417 */ /* MD_Rte_Os */
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 * Task:     Task_Init_Appl8
 * Priority: 97
 * Schedule: FULL
 *********************************************************************************************************************/
TASK(Task_Init_Appl8) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_14.1 */
{

  /* call runnable */
  BattRtnCurrInit1();

  /* call runnable */
  TurnCntrCorrlnInit1();

  /* call runnable */
  DiagcMgrProxyAppl8Init1();

  (void)TerminateTask(); /* PRQA S 3417 */ /* MD_Rte_Os */
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

#define RTE_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0781:  MISRA rule: 5.6
     Reason:     The name is being used as a structure/union member as well as being a label, tag or ordinary identifier.
                 The compliance to this rule is under user's control.
     Risk:       Ambiguous identifiers can lead to compiler errors / warnings.
     Prevention: Verified during compile time. If the compiler reports an error or warning, the user has to rename the objects leading to the violation.

   MD_Rte_3408:  MISRA rule: 8.8
     Reason:     For the purpose of monitoring during calibration or debugging it is necessary to use non-static declarations.
                 This is covered in the MISRA C compliance section of the Rte specification.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3447:  MISRA rule: 8.8
     Reason:     For the purpose of monitoring during calibration or debugging it is necessary to use non-static declarations.
                 This is covered in the MISRA C compliance section of the Rte specification.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_Os:
     Reason:     This justification is used as summary justification for all deviations caused by the MICROSAR OS
                 which is for testing of the RTE. Those deviations are no issues in the RTE code.
     Risk:       No functional risk.
     Prevention: Not required.

*/
