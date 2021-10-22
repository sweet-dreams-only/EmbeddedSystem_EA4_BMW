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
 *          File:  Rte.c
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
 * Rte Init State Variable
 *********************************************************************************************************************/

#define RTE_START_SEC_VAR_ZERO_INIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

volatile VAR(uint8, RTE_VAR_ZERO_INIT) Rte_InitState = RTE_STATE_UNINIT; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */

#define RTE_STOP_SEC_VAR_ZERO_INIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * Constants
 *********************************************************************************************************************/

#define RTE_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(Ary1D_f32_8, RTE_CONST) Rte_C_Ary1D_f32_8_1 = {
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(Ary1D_u0p16_8, RTE_CONST) Rte_C_Ary1D_u0p16_8_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(Ary1D_u16p0_2, RTE_CONST) Rte_C_Ary1D_u16p0_2_0 = {
  0U, 100U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(Ary1D_u2p14_2, RTE_CONST) Rte_C_Ary1D_u2p14_2_1 = {
  16384U, 0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(Ary1D_u32_8, RTE_CONST) Rte_C_Ary1D_u32_8_0 = {
  0U, 62U, 125U, 187U, 250U, 312U, 375U, 437U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(Dlog_ProgIdArrayType, RTE_CONST) Rte_C_Dlog_ProgIdArrayType_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(NO_VECH_1, RTE_CONST) Rte_C_NO_VECH_1_0 = {
  0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(NO_VECH_2, RTE_CONST) Rte_C_NO_VECH_2_0 = {
  0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(NO_VECH_3, RTE_CONST) Rte_C_NO_VECH_3_0 = {
  0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(NO_VECH_4, RTE_CONST) Rte_C_NO_VECH_4_0 = {
  0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(NO_VECH_5, RTE_CONST) Rte_C_NO_VECH_5_0 = {
  0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(NO_VECH_6, RTE_CONST) Rte_C_NO_VECH_6_0 = {
  0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(NO_VECH_7, RTE_CONST) Rte_C_NO_VECH_7_0 = {
  0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(TorsBarStEstimdRec1, RTE_CONST) Rte_C_TorsBarStEstimdRec1_0 = {
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(TorsBarStEstimdRec1, RTE_CONST) Rte_C_TorsBarStEstimdRec1_1 = {
  10.0F, 0.95F, 1000.0F, 20.0F, 100.0F
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(Vin_ComVinType, RTE_CONST) Rte_C_Vin_ComVinType_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(Vin_VinType, RTE_CONST) Rte_C_Vin_VinType_0 = {
  {255U, 255U, 255U, 255U, 255U, 255U, 255U}, 0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(Vin_VinType, RTE_CONST) Rte_C_Vin_VinType_1 = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U}, 0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(sigGroup_ACLNY_MASSCNTR1, RTE_CONST) Rte_C_sigGroup_ACLNY_MASSCNTR1_0 = {
  0U, 65535U, 15U, 0U, 15U, 0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(sigGroup_AVL_FORC_GRD1, RTE_CONST) Rte_C_sigGroup_AVL_FORC_GRD1_0 = {
  0U, 120U, 15U, 0U, 8U, 15U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(sigGroup_AVL_PO_EPS1, RTE_CONST) Rte_C_sigGroup_AVL_PO_EPS1_0 = {
  65535U, 3U, 4095U, 65535U, 0U, 15U, 15U, 0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(sigGroup_AVL_STMOM_DV_ACT1, RTE_CONST) Rte_C_sigGroup_AVL_STMOM_DV_ACT1_0 = {
  2000U, 15U, 8U, 0U, 15U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(sigGroup_CON_VEH1, RTE_CONST) Rte_C_sigGroup_CON_VEH1_0 = {
  0U, 15U, 0U, 15U, 15U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(sigGroup_DISP_CC_EPS1, RTE_CONST) Rte_C_sigGroup_DISP_CC_EPS1_0 = {
  0U, 15U, 0U, 0U, 12U, 65534U, 5U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(sigGroup_DT_EST1, RTE_CONST) Rte_C_sigGroup_DT_EST1_0 = {
  0U, 0U, 14U, 0U, 0U, 15U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(sigGroup_ENERG_DGR_DRDY1, RTE_CONST) Rte_C_sigGroup_ENERG_DGR_DRDY1_0 = {
  0U, 0U, 15U, 15U, 0U, 0U, 0U, 0U, 0U, 255U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(sigGroup_OFFS_QUAD_EPS1, RTE_CONST) Rte_C_sigGroup_OFFS_QUAD_EPS1_0 = {
  65535U, 15U, 0U, 255U, 0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(sigGroup_ST_EST1, RTE_CONST) Rte_C_sigGroup_ST_EST1_0 = {
  128U, 14U, 0U, 15U, 0U, 128U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(sigGroup_SU_EPS1, RTE_CONST) Rte_C_sigGroup_SU_EPS1_0 = {
  0U, 0U, 15U, 1228U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(sigGroup_TAR_QTA_STRMOM_DV1, RTE_CONST) Rte_C_sigGroup_TAR_QTA_STRMOM_DV1_0 = {
  0U, 15U, 15U, 15U, 15U, 0U, 0U, 0U, 2000U, 0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(sigGroup_TAR_STMOM_DV_ACT1, RTE_CONST) Rte_C_sigGroup_TAR_STMOM_DV_ACT1_0 = {
  0U, 0U, 15U, 255U, 2000U, 255U, 15U, 15U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(sigGroup_VYAW_VEH1, RTE_CONST) Rte_C_sigGroup_VYAW_VEH1_0 = {
  0U, 0U, 32768U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(sigGroup_V_VEH1, RTE_CONST) Rte_C_sigGroup_V_VEH1_0 = {
  0U, 0U, 0U, 0U, 1U, 0U, 0U
};
/* PRQA L:L1 */

#define RTE_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * Calibration Parameters (SW-C local and calibration component calibration parameters)
 *********************************************************************************************************************/

#define RTE_START_SEC_CONST_DEFAULT_RTE_CALPRM_GROUP_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

CONST(Rte_Calprm_CalRegn01CmnGroupA_DEFAULT_RTE_CALPRM_GROUP_Type, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_CalprmRom_CalRegn01CmnGroupA_DEFAULT_RTE_CALPRM_GROUP = { /* PRQA S 3408 */ /* MD_Rte_3408 */
  1.0F,
  1.0F,
  0.2F,
  7.5F,
  10.0F,
  1.0F,
  10.0F,
  0.0F,
  200U,
  50U,
  15U,
  255U,
  255U,
  255U,
  255U,
  255U,
  255U,
  255U,
  255U,
  255U,
  255U,
  255U,
  255U,
  255U,
  255U,
  255U,
  0U,
  0U,
  0U,
  5U,
  {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  },
  {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  },
  {
    16261U, 16261U, 16261U, 16261U, 16261U, 16261U, 16261U, 16261U, 16261U, 16261U, 16261U, 16261U
  },
  {
    5780U, 5780U, 5780U, 5780U, 5780U, 5780U, 5780U, 5780U, 5780U, 5780U, 5780U, 5780U
  },
  {
    -326, -326, -326, -326, -326, -326, -326, -326, -326, -326, -326, -326
  },
  {
    222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222, 222
  },
  {
    4480U, 14400U, 11520U, 5760U, 5760U, 5760U, 5760U, 5760U, 5760U, 5760U, 5760U, 5760U
  },
  {
    23464U, 23464U, 23464U, 23464U, 23464U, 23464U, 23464U, 23464U, 23464U, 23464U, 23464U, 23464U
  },
  {
    0U, 1280U, 2560U, 3840U, 5120U, 6400U, 7680U, 8960U, 10240U, 11520U, 12800U, 14080U
  }
};
CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_CalprmRom_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP = { /* PRQA S 3408 */ /* MD_Rte_3408 */
  1.0F,
  1.0F,
  0.0F,
  0.0F,
  1.0F,
  0.9F,
  0.1F,
  3.0F,
  10.0F,
  0.0F,
  10.0F,
  120.0F,
  43.0F,
  20.0F,
  0.0F,
  50000.0F,
  200.0F,
  120.0F,
  120.0F,
  55.0F,
  120.0F,
  500.0F,
  500.0F,
  500.0F,
  500.0F,
  500.0F,
  500.0F,
  2.0F,
  0.0F,
  0.3F,
  0.9F,
  1000.0F,
  1000.0F,
  1000.0F,
  1000.0F,
  20U,
  20U,
  20U,
  500U,
  10U,
  10U,
  10U,
  10U,
  {
    0U, 4096U, 8192U, 12288U, 16384U, 20480U, 24576U, 28672U, 32768U, 36864U, 38912U, 40960U
  },
  {
    0U, 4096U, 8192U, 12288U, 16384U, 20480U, 24576U, 28672U, 32768U, 36864U, 40960U, 40960U, 40960U
  },
  {
    {0U, 40960U, 40960U, 40960U, 40960U, 40960U, 40960U, 40960U, 40960U, 40960U, 40960U, 40960U, 40960U}, {0U, 40960U, 
    40960U, 40960U, 40960U, 40960U, 40960U, 40960U, 40960U, 40960U, 40960U, 40960U, 40960U}, {0U, 40960U, 40960U, 40960U, 
    40960U, 40960U, 40960U, 40960U, 40960U, 40960U, 40960U, 40960U, 40960U}, {0U, 40960U, 40960U, 40960U, 40960U, 40960U, 
    40960U, 40960U, 40960U, 40960U, 40960U, 40960U, 40960U}, {0U, 40960U, 40960U, 40960U, 40960U, 40960U, 40960U, 40960U, 
    40960U, 40960U, 40960U, 40960U, 40960U}, {0U, 40960U, 40960U, 40960U, 40960U, 40960U, 40960U, 40960U, 40960U, 40960U, 
    40960U, 40960U, 40960U}, {0U, 40960U, 40960U, 40960U, 40960U, 40960U, 40960U, 40960U, 40960U, 40960U, 40960U, 40960U, 
    40960U}, {0U, 40960U, 40960U, 40960U, 40960U, 40960U, 40960U, 40960U, 40960U, 40960U, 40960U, 40960U, 40960U}, {0U, 
    40960U, 40960U, 40960U, 40960U, 40960U, 40960U, 40960U, 40960U, 40960U, 40960U, 40960U, 40960U}, {0U, 40960U, 40960U, 
    40960U, 40960U, 40960U, 40960U, 40960U, 40960U, 40960U, 40960U, 40960U, 40960U}, {0U, 40960U, 40960U, 40960U, 40960U, 
    40960U, 40960U, 40960U, 40960U, 40960U, 40960U, 40960U, 40960U}, {0U, 40960U, 40960U, 40960U, 40960U, 40960U, 40960U, 
    40960U, 40960U, 40960U, 40960U, 40960U, 40960U}, {0U, 40960U, 40960U, 40960U, 40960U, 40960U, 40960U, 40960U, 40960U, 
    40960U, 40960U, 40960U, 40960U}
  },
  {
    30720U, 10240U, 30720U, 10240U, 40960U, 40960U, 40960U, 20480U, 20480U, 46080U, 20480U, 46080U, 51200U
  },
  {
    {30720U, 10240U, 30720U, 10240U, 40960U, 40960U, 40960U, 20480U, 20480U, 46080U, 20480U, 46080U, 51200U}, {31744U, 
    12288U, 31744U, 13312U, 41984U, 30720U, 30720U, 40960U, 20480U, 15360U, 15360U, 46080U, 51200U}, {32768U, 14336U, 
    32768U, 16384U, 43008U, 51200U, 51200U, 20480U, 20480U, 20480U, 46080U, 46080U, 51200U}, {33792U, 16384U, 33792U, 
    18432U, 44032U, 20480U, 20480U, 15360U, 15360U, 15360U, 18432U, 46080U, 51200U}, {34816U, 17408U, 34816U, 20480U, 
    45056U, 10240U, 15360U, 46080U, 46080U, 18432U, 15360U, 46080U, 51200U}, {17408U, 18432U, 35840U, 22528U, 46080U, 
    15360U, 51200U, 18432U, 18432U, 15360U, 51200U, 15360U, 51200U}, {19456U, 19456U, 36864U, 24576U, 47104U, 51200U, 
    46080U, 51200U, 51200U, 20480U, 51200U, 15360U, 51200U}, {20480U, 20480U, 37888U, 26624U, 48128U, 18432U, 18432U, 
    18432U, 51200U, 18432U, 51200U, 18432U, 51200U}, {30720U, 21504U, 38912U, 28672U, 49152U, 28672U, 51200U, 46080U, 
    20480U, 18432U, 51200U, 18432U, 51200U}, {30720U, 22528U, 39936U, 30720U, 51200U, 46080U, 20480U, 30720U, 18432U, 
    18432U, 51200U, 18432U, 51200U}, {30720U, 22528U, 39936U, 30720U, 51200U, 46080U, 20480U, 30720U, 18432U, 18432U, 
    51200U, 18432U, 51200U}, {30720U, 22528U, 39936U, 30720U, 51200U, 46080U, 20480U, 30720U, 18432U, 18432U, 51200U, 
    18432U, 51200U}, {30720U, 22528U, 39936U, 30720U, 51200U, 46080U, 20480U, 30720U, 18432U, 18432U, 51200U, 18432U, 
    51200U}
  },
  {
    {30720U, 10240U, 30720U, 10240U, 40960U, 40960U, 40960U, 20480U, 20480U, 46080U, 20480U, 46080U}, {31744U, 12288U, 
    31744U, 13312U, 41984U, 30720U, 30720U, 40960U, 20480U, 15360U, 15360U, 46080U}, {32768U, 14336U, 32768U, 16384U, 
    43008U, 51200U, 51200U, 20480U, 20480U, 20480U, 46080U, 46080U}, {33792U, 16384U, 33792U, 18432U, 44032U, 20480U, 
    20480U, 15360U, 15360U, 15360U, 18432U, 46080U}, {34816U, 17408U, 34816U, 20480U, 45056U, 10240U, 15360U, 46080U, 
    46080U, 18432U, 15360U, 46080U}, {17408U, 18432U, 35840U, 22528U, 46080U, 15360U, 51200U, 18432U, 18432U, 15360U, 
    51200U, 15360U}, {19456U, 19456U, 36864U, 24576U, 47104U, 51200U, 46080U, 51200U, 51200U, 20480U, 51200U, 15360U}, {
    20480U, 20480U, 37888U, 26624U, 48128U, 18432U, 18432U, 18432U, 51200U, 18432U, 51200U, 18432U}, {30720U, 21504U, 
    38912U, 28672U, 49152U, 28672U, 51200U, 46080U, 20480U, 18432U, 51200U, 18432U}, {30720U, 22528U, 39936U, 30720U, 
    51200U, 46080U, 20480U, 30720U, 18432U, 18432U, 51200U, 18432U}, {30720U, 22528U, 39936U, 30720U, 51200U, 46080U, 
    20480U, 30720U, 18432U, 18432U, 51200U, 18432U}, {30720U, 22528U, 39936U, 30720U, 51200U, 46080U, 20480U, 30720U, 
    18432U, 18432U, 51200U, 18432U}
  },
  {
    0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U, 10U, 11U, 12U
  },
  {
    {0U, 1229U, 1229U, 1229U, 1229U, 1229U, 1229U, 1229U, 1229U, 1229U, 1229U, 1229U}, {0U, 1229U, 1229U, 1229U, 1229U, 
    1229U, 1229U, 1229U, 1229U, 1229U, 1229U, 1229U}, {0U, 1229U, 1229U, 1229U, 1229U, 1229U, 1229U, 1229U, 1229U, 1229U, 
    1229U, 1229U}, {0U, 1229U, 1229U, 1229U, 1229U, 1229U, 1229U, 1229U, 1229U, 1229U, 1229U, 1229U}, {0U, 1229U, 1229U, 
    1229U, 1229U, 1229U, 1229U, 1229U, 1229U, 1229U, 1229U, 1229U}, {0U, 1229U, 1229U, 1229U, 1229U, 1229U, 1229U, 1229U, 
    1229U, 1229U, 1229U, 1229U}, {0U, 1229U, 1229U, 1229U, 1229U, 1229U, 1229U, 1229U, 1229U, 1229U, 1229U, 1229U}, {0U, 
    1229U, 1229U, 1229U, 1229U, 1229U, 1229U, 1229U, 1229U, 1229U, 1229U, 1229U}, {0U, 1229U, 1229U, 1229U, 1229U, 1229U, 
    1229U, 1229U, 1229U, 1229U, 1229U, 1229U}, {0U, 1229U, 1229U, 1229U, 1229U, 1229U, 1229U, 1229U, 1229U, 1229U, 1229U, 
    1229U}, {0U, 1229U, 1229U, 1229U, 1229U, 1229U, 1229U, 1229U, 1229U, 1229U, 1229U, 1229U}, {0U, 1229U, 1229U, 1229U, 
    1229U, 1229U, 1229U, 1229U, 1229U, 1229U, 1229U, 1229U}
  },
  {
    0.0F, 0.1F, 0.2F, 0.3F, 0.4F, 0.5F, 0.6F, 0.7F, 0.8F, 0.9F, 3.0F
  },
  {
    0.0F, 0.0F, 0.1F, 0.2F, 0.3F, 0.4F, 0.5F, 0.6F, 0.7F, 0.8F, 1.0F
  },
  {
    0.1F, 24.4F, 13.2F, 10.0F, 15.0F, 5.0F, 10.0F, 15.0F, 20.0F, 26.0F, 30.0F
  },
  {
    12288U, 12288U, 8192U, 4096U, 0U, 0U
  },
  {
    0U, 1280U, 2560U, 6400U, 12800U, 25600U
  },
  {
    7168U, 10240U, 11264U, 14336U, 17408U, 20480U, 27648U, 32768U
  },
  {
    0U, 10880U, 10880U, 10880U, 10880U, 10880U, 10880U, 10880U
  },
  {
    6400U, 6912U, 7168U, 9216U, 10240U, 11264U, 14336U, 27648U
  },
  {
    0U, 10880U, 10880U, 15360U, 25600U, 30720U, 30720U, 15360U
  },
  {
    0U, 640U, 1280U, 2560U, 6400U, 12800U
  },
  {
    30720U, 30720U, 26880U, 21760U, 15360U, 15360U
  },
  {
    10752U, 11776U, 17920U, 18944U, 20480U, 24576U, 27648U, 32768U
  },
  {
    50000U, 50000U, 50000U, 800U, 800U, 800U, 800U, 800U
  },
  {
    10752U, 11776U, 17920U, 18944U, 20480U, 24576U, 27648U, 32768U
  },
  {
    800U, 50000U, 50000U, 50000U, 50000U, 50000U, 50000U, 50000U
  },
  {
    0U, 1164U, 2327U, 3491U, 4655U, 5818U, 6982U, 8145U, 9309U, 10473U, 11636U, 12800U
  },
  {
    {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
    0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
    0U, 0U, 0U, 0U}
  },
  {
    0U, 3724U, 7447U, 11171U, 14895U, 18618U, 22342U, 26065U, 29789U, 33513U, 37236U, 40960U
  },
  {
    {32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U}, {32768U, 32768U, 
    32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U}, {32768U, 32768U, 32768U, 32768U, 
    32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U}, {32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 
    32768U, 32768U, 32768U, 32768U, 32768U, 32768U}, {32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 
    32768U, 32768U, 32768U, 32768U}, {32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 
    32768U, 32768U}, {32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U}, {
    32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U}, {32768U, 32768U, 
    32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U}, {32768U, 32768U, 32768U, 32768U, 
    32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U}, {32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 
    32768U, 32768U, 32768U, 32768U, 32768U, 32768U}, {32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 
    32768U, 32768U, 32768U, 32768U}
  },
  {
    14336U, 12288U, 10240U, 8192U, 6144U, 4096U, 3072U, 2048U, 1024U, 410U
  },
  {
    0U, 256U, 1280U, 3200U, 6400U, 9600U, 12800U, 19200U, 25600U, 31872U
  },
  {
    0U, 960U, 1920U, 2880U, 3840U, 4800U, 5760U, 6720U, 7680U, 9600U
  },
  {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  },
  {
    0U, 873U, 1745U, 2618U, 3491U, 4364U, 5236U, 6109U, 6982U, 7855U, 8727U, 9600U
  },
  {
    {36045U, 36045U, 36045U, 36045U, 36045U, 36045U, 36045U, 36045U, 36045U, 36045U, 36045U, 36045U}, {36045U, 36045U, 
    36045U, 36045U, 36045U, 36045U, 36045U, 36045U, 36045U, 36045U, 36045U, 36045U}, {36045U, 36045U, 36045U, 36045U, 
    36045U, 36045U, 36045U, 36045U, 36045U, 36045U, 36045U, 36045U}, {36045U, 36045U, 36045U, 36045U, 36045U, 36045U, 
    36045U, 36045U, 36045U, 36045U, 36045U, 36045U}, {36045U, 36045U, 36045U, 36045U, 36045U, 36045U, 36045U, 36045U, 
    36045U, 36045U, 36045U, 36045U}, {36045U, 36045U, 36045U, 36045U, 36045U, 36045U, 36045U, 36045U, 36045U, 36045U, 
    36045U, 36045U}, {36045U, 36045U, 36045U, 36045U, 36045U, 36045U, 36045U, 36045U, 36045U, 36045U, 36045U, 36045U}, {
    36045U, 36045U, 36045U, 36045U, 36045U, 36045U, 36045U, 36045U, 36045U, 36045U, 36045U, 36045U}, {36045U, 36045U, 
    36045U, 36045U, 36045U, 36045U, 36045U, 36045U, 36045U, 36045U, 36045U, 36045U}, {36045U, 36045U, 36045U, 36045U, 
    36045U, 36045U, 36045U, 36045U, 36045U, 36045U, 36045U, 36045U}, {36045U, 36045U, 36045U, 36045U, 36045U, 36045U, 
    36045U, 36045U, 36045U, 36045U, 36045U, 36045U}, {36045U, 36045U, 36045U, 36045U, 36045U, 36045U, 36045U, 36045U, 
    36045U, 36045U, 36045U, 36045U}
  }
};
CONST(Rte_Calprm_CalRegn01CmnGroupC_DEFAULT_RTE_CALPRM_GROUP_Type, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_CalprmRom_CalRegn01CmnGroupC_DEFAULT_RTE_CALPRM_GROUP = { /* PRQA S 3408 */ /* MD_Rte_3408 */
  1.0F,
  0.5F,
  1000U,
  100U,
  FALSE,
  FALSE,
  FALSE,
  FALSE,
  {
    {-0.17159F, 0.00010352F, 1.1696F, 0.00024516F, 1.9834e-05F}, {-240.58F, 0.060289F, 240.53F, 0.17028F, 0.047148F}, {
    0.0018246F, -4.2826e-06F, 0.99616F, 0.00025897F, -2.8965e-07F}, {-6.1943F, 0.014635F, 5.9127F, 0.11656F, 0.00098854F
    }, {-70.875F, -0.28572F, 70.86F, 0.053221F, 0.98679F}
  },
  {
    {3.2994e-07F, 0.0081464F, 0.0019034F, 0.0016485F}, {0.00045434F, 1.6329F, 0.0015119F, 0.76734F}, {1.1488e-06F, 
    -2.4566e-05F, 0.0019002F, 0.001743F}, {0.0027499F, 0.045004F, 0.00025007F, 0.86756F}, {0.0001448F, 0.50816F, 
    -2.5948e-05F, 0.23299F}
  },
  {
    0.0F, 0.0F, 0.0F, 0.0F, 1.0F
  },
  {
    0.0F, 0.0F, 0.0F, 0.0F
  },
  {
    0U, 8192U, 12288U, 16384U
  },
  {
    0U, 0U, 0U, 16384U
  },
  {
    16384U, 16384U, 16384U, 16384U, 16384U, 16384U, 16384U, 16384U
  }
};
CONST(Rte_Calprm_CalRegn01CmnGroupD_DEFAULT_RTE_CALPRM_GROUP_Type, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_CalprmRom_CalRegn01CmnGroupD_DEFAULT_RTE_CALPRM_GROUP = { /* PRQA S 3408 */ /* MD_Rte_3408 */
  0.5F,
  400.0F,
  100.0F,
  0.15F,
  600.0F,
  550.0F,
  0.9F,
  30.0F,
  FALSE,
  FALSE
};
CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_CalprmRom_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP = { /* PRQA S 3408 */ /* MD_Rte_3408 */
  0.73F,
  10.0F,
  16.0F,
  9.0F,
  10.5F,
  15.5F,
  9.5F,
  16.0F,
  6.0F,
  0.0F,
  50.0F,
  18.0F,
  1.0F,
  0.8F,
  0.6F,
  1.0F,
  8.8F,
  9.0F,
  130.0F,
  50.0F,
  50.0F,
  76.0F,
  56.0F,
  66.66F,
  45.0F,
  16.0F,
  262500.0F,
  2.8F,
  2.3F,
  2.5F,
  3.0F,
  2.0F,
  4.75F,
  0.25F,
  4.75F,
  0.25F,
  0.0F,
  1.0F,
  0.625F,
  12.0F,
  0.0005F,
  1.8F,
  2.0F,
  2.0F,
  0.2857143F,
  0.01989437F,
  0.5714F,
  2.85F,
  2.0F,
  2.515F,
  0.01989437F,
  2.85F,
  20.0F,
  1.425F,
  2.85F,
  2.5F,
  500.0F,
  4400.0F,
  1.0F,
  1.0F,
  1.0F,
  1.0F,
  1.0F,
  1.0F,
  1.0F,
  1.0F,
  1.0F,
  1.0F,
  1.0F,
  0.0F,
  0.0F,
  1.0F,
  100.0F,
  100.0F,
  0.0F,
  0.0F,
  0.01F,
  500.0F,
  5.0F,
  800.0F,
  1.0F,
  0.25F,
  3.0F,
  0.005F,
  -0.001F,
  255.0F,
  0.000125F,
  9.375e-05F,
  125.0F,
  0.0026526F,
  0.015F,
  1.1F,
  0.9F,
  0.036F,
  100.0F,
  1000.0F,
  20.0F,
  0.0F,
  0.1F,
  250.0F,
  0.0F,
  25.0F,
  0.5F,
  -4400.0F,
  4400.0F,
  0.0F,
  0.0F,
  100.0F,
  0.0F,
  0.2F,
  100.0F,
  10.0F,
  1.0F,
  50.0F,
  5.0F,
  50.0F,
  120.0F,
  20.0F,
  140.0F,
  200U,
  50U,
  62500U,
  50000U,
  6250U,
  11000U,
  30000U,
  6250U,
  62500U,
  5000U,
  6000U,
  7000U,
  1000U,
  200U,
  0U,
  180000U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  20480,
  410U,
  272U,
  327U,
  327U,
  327U,
  327U,
  327U,
  327U,
  20U,
  120U,
  300U,
  6554U,
  65U,
  6554U,
  65U,
  5U,
  20U,
  16384U,
  16384U,
  2521U,
  1000U,
  2521U,
  1000U,
  5U,
  16385U,
  160U,
  512U,
  32768U,
  512U,
  0U,
  512U,
  512U,
  4096U,
  2048U,
  4096U,
  2048U,
  4096U,
  2048U,
  2832U,
  3598U,
  4622U,
  7924U,
  200U,
  100U,
  200U,
  0U,
  40U,
  40U,
  52424U,
  13106U,
  52424U,
  13106U,
  52424U,
  13106U,
  4U,
  7U,
  5U,
  6U,
  20U,
  0U,
  200U,
  2U,
  0U,
  0U,
  0U,
  4U,
  4U,
  0U,
  0U,
  0U,
  1U,
  2U,
  5U,
  2U,
  0U,
  0U,
  2U,
  5U,
  5U,
  1U,
  0U,
  2U,
  3U,
  10U,
  3U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  2U,
  3U,
  4U,
  TRUE,
  FALSE,
  FALSE,
  TRUE,
  FALSE,
  FALSE,
  TRUE,
  TRUE,
  FALSE,
  TRUE,
  FALSE,
  TRUE,
  FALSE,
  FALSE,
  TRUE,
  FALSE,
  FALSE,
  TRUE,
  FALSE,
  {
    0U, 0U, 0U, 0U, 0U, 0U
  },
  {
    0U, 1024U, 3072U, 6144U, 10240U, 16384U
  },
  {
    0U, 0U, 0U, 0U, 0U, 0U
  },
  {
    0U, 1024U, 3072U, 6144U, 10240U, 16384U
  },
  {
    0U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 
    34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 
    34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 
    34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 
    34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 
    34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 
    34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 
    34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 
    34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 
    34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 
    34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 
    34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 
    34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 
    34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 
    34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 
    34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 
    34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 
    34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 
    34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 
    34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 
    34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 
    34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 
    34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 
    34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 
    34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 
    34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 
    34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 
    34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 
    34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 
    34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 
    34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 
    34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 
    34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 
    34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 
    34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 
    34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 
    34560U, 34560U, 34560U, 34560U, 34560U, 34560U, 34560U
  },
  {
    0U, 1783U, 3560U, 5342U, 7125U, 8902U, 10685U, 12467U, 14245U, 16027U, 17810U, 19587U, 21370U, 23152U, 24935U, 
    26712U, 28495U
  },
  {
    34873U, 34873U, 34873U, 34873U, 19910U, 12411U, 9199U, 7350U, 6137U, 5272U, 4623U, 4119U, 3714U, 3382U, 3104U, 2870U, 
    2668U
  },
  {
    1280U, 2560U
  },
  {
    64000U, 64000U
  },
  {
    1280U, 2560U
  },
  {
    35200U, 35200U
  },
  {
    0U, 32U, 160U, 320U
  },
  {
    0U, 1280U, 2560U, 12800U
  },
  {
    16384U, 16384U, 0U, 0U
  },
  {
    0U, 0U, 0U, 0U, 0U, 0U
  },
  {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  },
  {
    0U, 0U, 0U, 0U, 0U, 0U
  },
  {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  },
  {
    0U, 0U, 0U, 0U, 0U, 0U
  },
  {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  },
  {
    45000U, 45000U, 45000U, 45000U, 45000U, 45000U, 45000U, 45000U, 45000U, 45000U, 45000U, 45000U
  },
  {
    45000U, 45000U, 45000U, 45000U, 45000U, 45000U, 45000U, 45000U, 45000U, 45000U, 45000U, 45000U
  },
  {
    24000U, 20000U, 16000U, 12000U, 8000U, 8000U, 8000U, 8000U, 8000U, 8000U, 8000U, 8000U
  },
  {
    32000U, 32000U, 32000U, 32000U, 32000U, 32000U, 32000U, 32000U, 32000U, 32000U, 32000U, 32000U
  },
  {
    320U, 480U, 640U, 800U, 960U, 1120U, 1280U, 1440U, 1600U, 1920U
  },
  {
    10304U, 7874U, 5864U, 4106U, 2848U, 1742U, 0U, 0U, 0U, 0U
  },
  {
    -19165, -17140, -15133, -13160, -11221, -9315, -7436, -5574, -3715, -1857, 0, 1857, 3715, 5572, 7430, 9293, 11171, 
    13078, 15016, 16988, 18994
  },
  {
    27853U, 27918U, 27984U, 28049U, 28115U, 28180U, 28180U, 28180U, 28180U, 28180U, 28180U, 28180U, 28180U, 28180U, 
    28180U, 28180U, 28115U, 28049U, 27984U, 27918U, 27853U
  },
  {
    -12800, -11520, -10240, -8960, -7680, -6400, -5120, -3840, -2560, -1280, 0, 1280, 2560, 3840, 5120, 6400, 7680, 8960, 
    10240, 11520, 12800
  },
  {
    819U, 922U, 1024U, 1126U, 1229U, 1331U, 1434U, 1434U, 1434U, 1434U, 1434U
  },
  {
    2560U, 3200U, 3840U, 4480U, 5120U, 6400U, 7680U, 8960U, 10240U, 11520U, 12800U
  },
  {
    20480U, 20480U, 20480U, 20480U, 20480U, 20480U
  },
  {
    20480U, 20480U, 20480U, 20480U, 20480U, 20480U
  },
  {
    0U, 3200U, 6400U, 8320U, 9600U
  },
  {
    18022U, 18022U, 18022U, 18022U, 18022U
  }
};
CONST(Rte_Calprm_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_CalprmRom_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP = { /* PRQA S 3408 */ /* MD_Rte_3408 */
  -360.0F,
  -900.0F,
  900.0F,
  360.0F,
  1.0F,
  45.0F,
  45.0F,
  45.0F,
  45.0F,
  3.0F,
  1.0F,
  1.0F,
  0.5F,
  0.5F,
  0.5F,
  1.0F,
  45.0F,
  2.8F,
  10.0F,
  0.5F,
  2.0F,
  160.0F,
  60.0F,
  1.0F,
  1.0F,
  0.1F,
  100.0F,
  1.0F,
  0.0F,
  3.0F,
  0.25F,
  3.0F,
  1.0F,
  TRUE,
  TRUE,
  {
    {1.0F, 0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 1.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 1.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 
    1.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F, 1.0F}
  },
  {
    {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}
  },
  {
    {1.0F, 0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 1.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 1.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 
    1.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F, 1.0F}
  },
  {
    {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}
  },
  {
    0, 0, 0, 0
  },
  {
    0, 0, 0, 0
  },
  {
    0, 0, 0, 0
  },
  {
    0, 0, 0, 0
  },
  {
    0, 0, 0, 0
  },
  {
    0, 0, 0, 0
  },
  {
    0U, 1280U, 2560U, 25600U
  },
  {
    0U, 26U, 51U, 77U, 128U, 256U, 512U, 768U, 1024U, 2560U
  },
  {
    0U, 164U, 328U, 819U, 1638U, 3277U, 8192U, 11469U, 16384U, 16384U
  },
  {
    960U, 960U, 800U, 640U, 480U, 320U, 320U, 160U, 160U, 160U, 160U, 160U
  },
  {
    0U, 3840U, 7680U, 11520U
  },
  {
    0U, 4096U, 16384U, 16384U
  }
};
CONST(Rte_Calprm_CalRegn01Inin00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_CalprmRom_CalRegn01Inin00GroupC_DEFAULT_RTE_CALPRM_GROUP = { /* PRQA S 3408 */ /* MD_Rte_3408 */
  20.0F,
  20.0F,
  500.0F,
  -500.0F,
  0.0F,
  0.0F,
  0.04F,
  17.0F,
  20.0F,
  {
    {2048U, 5120U, 5120U, 10240U, 10240U, 15360U, 15360U, 20480U, 20480U}, {2048U, 5120U, 5120U, 10240U, 10240U, 15360U, 
    15360U, 20480U, 20480U}, {2048U, 5120U, 5120U, 10240U, 10240U, 10240U, 15360U, 15360U, 15360U}, {2048U, 5120U, 5120U, 
    10240U, 10240U, 10240U, 10240U, 10240U, 10240U}, {2048U, 5120U, 5120U, 10240U, 10240U, 10240U, 10240U, 10240U, 10240U}
  },
  {
    {0U, 4U, 508U, 608U, 712U, 816U, 916U, 1020U, 1124U, 1228U, 1328U, 1432U, 1536U, 1636U, 1740U, 1844U, 1944U, 2048U, 
    6920U, 10240U}, {0U, 204U, 716U, 792U, 868U, 944U, 1016U, 1092U, 1168U, 1244U, 1316U, 1392U, 1468U, 1544U, 1616U, 
    1692U, 1768U, 1844U, 9348U, 10240U}, {0U, 308U, 820U, 908U, 1000U, 1088U, 1176U, 1268U, 1356U, 1448U, 1536U, 1624U, 
    1716U, 1804U, 1896U, 1984U, 2072U, 2164U, 2252U, 10240U}, {0U, 192U, 1024U, 1164U, 1304U, 1448U, 1588U, 1728U, 1868U, 
    2008U, 2152U, 2292U, 2432U, 2572U, 2712U, 2856U, 2996U, 3136U, 3276U, 10240U}, {0U, 176U, 836U, 1048U, 1260U, 1472U, 
    1684U, 1896U, 2108U, 2320U, 2532U, 2744U, 2956U, 3168U, 3380U, 3592U, 3804U, 4016U, 4228U, 10240U}, {0U, 192U, 916U, 
    1148U, 1376U, 1608U, 1840U, 2072U, 2304U, 2536U, 2768U, 3000U, 3232U, 3464U, 3692U, 3924U, 4156U, 4388U, 4620U, 10240U
    }, {0U, 204U, 972U, 1220U, 1464U, 1712U, 1960U, 2204U, 2452U, 2696U, 2944U, 3192U, 3436U, 3684U, 3928U, 4176U, 4424U, 
    4668U, 4916U, 10240U}, {0U, 216U, 1020U, 1280U, 1540U, 1796U, 2056U, 2316U, 2572U, 2832U, 3092U, 3348U, 3608U, 3868U, 
    4128U, 4384U, 4644U, 4904U, 5160U, 10240U}, {0U, 244U, 1168U, 1464U, 1760U, 2056U, 2352U, 2644U, 2940U, 3236U, 3532U, 
    3828U, 4124U, 4420U, 4716U, 5012U, 5308U, 5604U, 5900U, 10240U}, {0U, 308U, 1460U, 1828U, 2200U, 2568U, 2936U, 3308U, 
    3676U, 4048U, 4416U, 4784U, 5156U, 5524U, 5896U, 6264U, 6632U, 7004U, 7372U, 10240U}, {0U, 4U, 1892U, 2140U, 2596U, 
    2880U, 3396U, 3640U, 4436U, 4676U, 5200U, 5712U, 6220U, 6748U, 7268U, 7512U, 8024U, 8552U, 8800U, 10240U}, {0U, 4U, 
    1892U, 2140U, 2596U, 2880U, 3396U, 3640U, 4436U, 4676U, 5200U, 5712U, 6220U, 6748U, 7268U, 7512U, 8024U, 8552U, 
    8800U, 10240U}
  },
  {
    {0U, 0U, 40U, 58U, 98U, 159U, 242U, 343U, 470U, 615U, 782U, 972U, 1182U, 1411U, 1663U, 1937U, 2232U, 2546U, 18022U, 
    18022U}, {0U, 0U, 41U, 52U, 73U, 107U, 150U, 205U, 270U, 346U, 432U, 530U, 637U, 756U, 885U, 1025U, 1176U, 1338U, 
    18022U, 18022U}, {0U, 0U, 29U, 37U, 55U, 86U, 122U, 171U, 229U, 294U, 372U, 458U, 551U, 655U, 770U, 894U, 1027U, 
    1169U, 1321U, 15274U}, {0U, 0U, 41U, 55U, 79U, 121U, 171U, 239U, 317U, 409U, 513U, 630U, 759U, 904U, 1059U, 1230U, 
    1413U, 1607U, 1815U, 12432U}, {0U, 0U, 49U, 73U, 113U, 171U, 245U, 340U, 447U, 574U, 716U, 879U, 1053U, 1249U, 1460U, 
    1688U, 1933U, 2196U, 2473U, 10636U}, {0U, 0U, 49U, 73U, 113U, 171U, 245U, 340U, 447U, 574U, 716U, 879U, 1053U, 1249U, 
    1460U, 1688U, 1933U, 2196U, 2473U, 9452U}, {0U, 0U, 49U, 73U, 113U, 171U, 245U, 340U, 447U, 574U, 716U, 879U, 1053U, 
    1249U, 1460U, 1688U, 1933U, 2196U, 2473U, 8691U}, {0U, 0U, 49U, 73U, 113U, 171U, 245U, 340U, 447U, 574U, 716U, 879U, 
    1053U, 1249U, 1460U, 1688U, 1933U, 2196U, 2473U, 8122U}, {0U, 0U, 49U, 73U, 113U, 171U, 245U, 340U, 447U, 574U, 716U, 
    879U, 1053U, 1249U, 1460U, 1688U, 1933U, 2196U, 2473U, 6697U}, {0U, 0U, 49U, 73U, 113U, 171U, 245U, 340U, 447U, 574U, 
    716U, 879U, 1053U, 1249U, 1460U, 1688U, 1933U, 2196U, 2473U, 4706U}, {0U, 0U, 66U, 84U, 131U, 168U, 254U, 300U, 488U, 
    554U, 713U, 892U, 1090U, 1315U, 1559U, 1681U, 1953U, 2253U, 2404U, 3267U}, {0U, 0U, 66U, 84U, 131U, 168U, 254U, 300U, 
    488U, 554U, 713U, 892U, 1090U, 1315U, 1559U, 1681U, 1953U, 2253U, 2404U, 3267U}
  },
  {
    {-20480, -10240, -8192, -6144, -4096, -2048, 0, 2048, 4096, 6144, 8192, 10240, 20480}, {-20480, -10240, -8192, -6144, 
    -4096, -2048, 0, 2048, 4096, 6144, 8192, 10240, 20480}, {-20480, -10240, -8192, -6144, -4096, -2048, 0, 2048, 4096, 
    6144, 8192, 10240, 20480}, {-20480, -10240, -8192, -6144, -4096, -2048, 0, 2048, 4096, 6144, 8192, 10240, 20480}, {
    -20480, -10240, -8192, -6144, -4096, -2048, 0, 2048, 4096, 6144, 8192, 10240, 20480}, {-20480, -10240, -8192, -6144, 
    -4096, -2048, 0, 2048, 4096, 6144, 8192, 10240, 20480}, {-20480, -10240, -8192, -6144, -4096, -2048, 0, 2048, 4096, 
    6144, 8192, 10240, 20480}, {-20480, -10240, -8192, -6144, -4096, -2048, 0, 2048, 4096, 6144, 8192, 10240, 20480}, {
    -20480, -10240, -8192, -6144, -4096, -2048, 0, 2048, 4096, 6144, 8192, 10240, 20480}, {-20480, -10240, -8192, -6144, 
    -4096, -2048, 0, 2048, 4096, 6144, 8192, 10240, 20480}
  },
  {
    {-11754, -11754, -10774, -4114, -1959, -196, 1567, 3918, 7836, 17631, 18022, 18022, 18022}, {-11754, -11754, -9795, 
    -1959, -784, 196, 784, 1175, 5877, 12537, 15672, 18022, 18022}, {-11754, -7836, -3918, -1959, -196, 0, 1175, 2938, 
    3526, 6269, 18022, 18022, 18022}, {-11754, -5877, -4506, 0, 196, 588, 784, 980, 2938, 5093, 7836, 18022, 18022}, {0, 
    0, 0, 392, 588, 588, 784, 2938, 3330, 4114, 5877, 5877, 5877}, {0, 784, 784, 784, 784, 784, 784, 2547, 2938, 3526, 
    5877, 5877, 5877}, {0, 784, 784, 784, 784, 784, 784, 2547, 2938, 3526, 5877, 5877, 5877}, {0, 784, 784, 784, 784, 
    784, 784, 2547, 2938, 3526, 5877, 5877, 5877}, {0, 784, 784, 784, 784, 784, 784, 2547, 2938, 3526, 5877, 5877, 5877}, 
    {0, 784, 784, 784, 784, 784, 784, 2547, 2938, 3526, 5877, 5877, 5877}
  },
  {
    0U, 640U, 3840U, 7680U, 10240U, 12800U, 15360U, 19200U, 23040U, 25600U
  },
  {
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F
  },
  {
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F
  }
};
CONST(Rte_Calprm_CalRegn01Inin00GroupD_DEFAULT_RTE_CALPRM_GROUP_Type, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_CalprmRom_CalRegn01Inin00GroupD_DEFAULT_RTE_CALPRM_GROUP = { /* PRQA S 3408 */ /* MD_Rte_3408 */
  0.0F,
  0.5F,
  30.0F,
  5.0F,
  30.0F,
  0.02F,
  0.29F,
  3.0F,
  1.0F,
  1.0F,
  90.0F,
  20.0F,
  20.0F,
  1.0F,
  -4500.0F,
  1.0F,
  10.0F,
  0.001F,
  20.0F,
  FALSE,
  FALSE,
  {
    0U, 640U, 1280U, 2560U
  },
  {
    0U, 640U, 1280U, 1920U, 2560U
  },
  {
    {0U, 480U, 960U, 1440U}, {0U, 480U, 960U, 1440U}, {0U, 480U, 960U, 1440U}, {0U, 480U, 960U, 1440U}, {0U, 480U, 960U, 
    1440U}
  },
  {
    {0U, 10813U, 21627U, 32768U}, {0U, 10813U, 21627U, 32768U}, {0U, 10813U, 21627U, 32768U}, {0U, 10813U, 21627U, 32768U
    }, {0U, 10813U, 21627U, 32768U}
  },
  {
    {0U, 262U}, {0U, 262U}, {0U, 262U}, {0U, 262U}
  },
  {
    {1920U, 0U}, {1920U, 0U}, {1920U, 0U}, {1920U, 0U}
  },
  {
    0U, 4096U
  },
  {
    {0U, 9830U, 22938U, 32768U}, {0U, 9830U, 22938U, 32768U}, {0U, 9830U, 22938U, 32768U}, {0U, 9830U, 22938U, 32768U}, {
    0U, 9830U, 22938U, 32768U}
  },
  {
    800U, 400U
  },
  {
    10400U, 10400U
  },
  {
    {0U, 262U}, {0U, 262U}, {0U, 262U}, {0U, 262U}
  },
  {
    0U, 2048U, 4096U, 6144U, 8192U, 10240U, 12288U, 14336U, 16384U, 18432U
  },
  {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  },
  {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  },
  {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  },
  {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  },
  {
    384U, 384U, 384U, 384U, 384U, 384U, 384U, 384U, 384U, 384U, 384U, 384U
  },
  {
    0U, 640U, 1088U, 1120U, 1152U, 1184U
  },
  {
    36000U, 36000U, 36000U, 36000U, 36000U, 36000U
  },
  {
    8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U
  },
  {
    8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U
  },
  {
    32768U, 32768U, 9830U, 6554U, 3277U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  },
  {
    208U, 432U, 640U, 848U, 1056U
  },
  {
    0U, 0U, 0U, 0U, 0U
  },
  {
    0U, 4096U
  },
  {
    32768U, 0U
  },
  {
    1005U, 1100U
  },
  {
    32768U, 32768U
  },
  {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  },
  {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  },
  {
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F
  }
};
CONST(Rte_Calprm_CalRegn01Inin00_DEFAULT_RTE_CALPRM_GROUP_Type, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_CalprmRom_CalRegn01Inin00_DEFAULT_RTE_CALPRM_GROUP = { /* PRQA S 3408 */ /* MD_Rte_3408 */
  2100.0F,
  500.0F,
  1.0F,
  20.0F,
  3.0F,
  0.1F,
  0.0F,
  30.0F,
  1.0F,
  -1.0F,
  0.8F,
  15.0F,
  0.0F,
  1.0F,
  -1.0F,
  4.0F,
  0.2F,
  30.0F,
  0.98F,
  360.0F,
  180.0F,
  10.0F,
  3.0F,
  3.0F,
  10.0F,
  0.0F,
  100.0F,
  0.0F,
  22.0F,
  1U,
  656U,
  656U,
  65534U,
  {
    0, 20, 40, 60, 80, 100, 120, 140, 160, 180
  },
  {
    0U, 3641U, 7281U, 10922U, 14562U, 18206U, 21846U, 25487U, 29127U, 32768U
  },
  {
    0.0F, 0.0F, 0.0F, 0.0F
  },
  {
    {0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 
    0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F}
  },
  {
    {0U, 0U, 0U}, {0U, 0U, 0U}, {0U, 0U, 0U}, {0U, 0U, 0U}, {0U, 0U, 0U}, {0U, 0U, 0U}, {0U, 0U, 0U}, {0U, 0U, 0U}
  },
  {
    1.0F, 1.0F, 1.0F, 1.0F
  },
  {
    -15.0F, -5.0F, 5.0F, 15.0F
  },
  {
    0U, 960U, 1920U, 2880U, 3840U, 5760U, 8640U, 11520U, 14400U, 17280U
  },
  {
    24269U, 24269U, 24269U, 24269U, 24269U, 24269U, 24269U, 24269U, 24269U, 24269U
  },
  {
    TRUE, TRUE, TRUE, TRUE
  },
  {
    {0.0F, 5.0F}, {60.0F, 80.0F}, {80.0F, 100.0F}, {100.0F, 120.0F}
  },
  {
    0U, 640U, 1920U, 3840U, 7680U, 10240U, 12800U, 15360U, 19200U, 23040U, 25600U, 28160U
  },
  {
    1233U, 1237U, 1241U, 1245U, 1249U, 1253U, 1257U, 1262U, 1262U, 1262U, 1262U, 1262U, 1262U, 1262U, 1257U, 1253U, 
    1249U, 1245U, 1241U, 1237U, 1233U
  },
  {
    17592U, 17592U, 17592U, 17285U, 16589U, 15770U, 14930U, 14213U, 13926U, 13681U, 13681U, 13681U, 13926U, 14213U, 
    14930U, 15770U, 16589U, 17285U, 17592U, 17592U, 17592U
  },
  {
    29491U, 29655U, 29819U, 29983U, 30147U, 30147U, 30147U, 30147U, 30147U, 30147U, 30147U, 30147U, 30147U, 30147U, 
    30147U, 30147U, 30147U, 29983U, 29819U, 29655U, 29491U
  },
  {
    -5939, -5300, -4678, -4063, -3465, -2867, -2277, -1704, -1139, -565, 0, 565, 1139, 1704, 2277, 2867, 3465, 4063, 
    4678, 5300, 5939
  },
  {
    4522U, 4555U, 4588U, 4620U, 4653U, 4686U, 4719U, 4719U, 4719U, 4719U, 4719U, 4719U, 4719U, 4719U, 4719U, 4686U, 
    4653U, 4620U, 4588U, 4555U, 4522U
  },
  {
    0U, 12800U, 25600U, 38400U, 51200U, 65408U
  }
};
CONST(Rte_Calprm_CalRegn01Inin01GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_CalprmRom_CalRegn01Inin01GroupA_DEFAULT_RTE_CALPRM_GROUP = { /* PRQA S 3408 */ /* MD_Rte_3408 */
  -360.0F,
  -900.0F,
  900.0F,
  360.0F,
  1.0F,
  45.0F,
  45.0F,
  45.0F,
  45.0F,
  3.0F,
  1.0F,
  1.0F,
  0.5F,
  0.5F,
  0.5F,
  1.0F,
  45.0F,
  2.8F,
  10.0F,
  0.5F,
  2.0F,
  160.0F,
  60.0F,
  1.0F,
  1.0F,
  0.1F,
  100.0F,
  1.0F,
  0.0F,
  3.0F,
  0.25F,
  3.0F,
  1.0F,
  TRUE,
  TRUE,
  {
    {1.0F, 0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 1.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 1.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 
    1.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F, 1.0F}
  },
  {
    {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}
  },
  {
    {1.0F, 0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 1.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 1.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 
    1.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F, 1.0F}
  },
  {
    {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}
  },
  {
    0, 0, 0, 0
  },
  {
    0, 0, 0, 0
  },
  {
    0, 0, 0, 0
  },
  {
    0, 0, 0, 0
  },
  {
    0, 0, 0, 0
  },
  {
    0, 0, 0, 0
  },
  {
    0U, 1280U, 2560U, 25600U
  },
  {
    0U, 26U, 51U, 77U, 128U, 256U, 512U, 768U, 1024U, 2560U
  },
  {
    0U, 164U, 328U, 819U, 1638U, 3277U, 8192U, 11469U, 16384U, 16384U
  },
  {
    960U, 960U, 800U, 640U, 480U, 320U, 320U, 160U, 160U, 160U, 160U, 160U
  },
  {
    0U, 3840U, 7680U, 11520U
  },
  {
    0U, 4096U, 16384U, 16384U
  }
};
CONST(Rte_Calprm_CalRegn01Inin01GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_CalprmRom_CalRegn01Inin01GroupC_DEFAULT_RTE_CALPRM_GROUP = { /* PRQA S 3408 */ /* MD_Rte_3408 */
  20.0F,
  20.0F,
  500.0F,
  -500.0F,
  0.0F,
  0.0F,
  0.04F,
  17.0F,
  20.0F,
  {
    {2048U, 5120U, 5120U, 10240U, 10240U, 15360U, 15360U, 20480U, 20480U}, {2048U, 5120U, 5120U, 10240U, 10240U, 15360U, 
    15360U, 20480U, 20480U}, {2048U, 5120U, 5120U, 10240U, 10240U, 10240U, 15360U, 15360U, 15360U}, {2048U, 5120U, 5120U, 
    10240U, 10240U, 10240U, 10240U, 10240U, 10240U}, {2048U, 5120U, 5120U, 10240U, 10240U, 10240U, 10240U, 10240U, 10240U}
  },
  {
    {0U, 4U, 508U, 608U, 712U, 816U, 916U, 1020U, 1124U, 1228U, 1328U, 1432U, 1536U, 1636U, 1740U, 1844U, 1944U, 2048U, 
    6920U, 10240U}, {0U, 204U, 716U, 792U, 868U, 944U, 1016U, 1092U, 1168U, 1244U, 1316U, 1392U, 1468U, 1544U, 1616U, 
    1692U, 1768U, 1844U, 9348U, 10240U}, {0U, 308U, 820U, 908U, 1000U, 1088U, 1176U, 1268U, 1356U, 1448U, 1536U, 1624U, 
    1716U, 1804U, 1896U, 1984U, 2072U, 2164U, 2252U, 10240U}, {0U, 192U, 1024U, 1164U, 1304U, 1448U, 1588U, 1728U, 1868U, 
    2008U, 2152U, 2292U, 2432U, 2572U, 2712U, 2856U, 2996U, 3136U, 3276U, 10240U}, {0U, 176U, 836U, 1048U, 1260U, 1472U, 
    1684U, 1896U, 2108U, 2320U, 2532U, 2744U, 2956U, 3168U, 3380U, 3592U, 3804U, 4016U, 4228U, 10240U}, {0U, 192U, 916U, 
    1148U, 1376U, 1608U, 1840U, 2072U, 2304U, 2536U, 2768U, 3000U, 3232U, 3464U, 3692U, 3924U, 4156U, 4388U, 4620U, 10240U
    }, {0U, 204U, 972U, 1220U, 1464U, 1712U, 1960U, 2204U, 2452U, 2696U, 2944U, 3192U, 3436U, 3684U, 3928U, 4176U, 4424U, 
    4668U, 4916U, 10240U}, {0U, 216U, 1020U, 1280U, 1540U, 1796U, 2056U, 2316U, 2572U, 2832U, 3092U, 3348U, 3608U, 3868U, 
    4128U, 4384U, 4644U, 4904U, 5160U, 10240U}, {0U, 244U, 1168U, 1464U, 1760U, 2056U, 2352U, 2644U, 2940U, 3236U, 3532U, 
    3828U, 4124U, 4420U, 4716U, 5012U, 5308U, 5604U, 5900U, 10240U}, {0U, 308U, 1460U, 1828U, 2200U, 2568U, 2936U, 3308U, 
    3676U, 4048U, 4416U, 4784U, 5156U, 5524U, 5896U, 6264U, 6632U, 7004U, 7372U, 10240U}, {0U, 4U, 1892U, 2140U, 2596U, 
    2880U, 3396U, 3640U, 4436U, 4676U, 5200U, 5712U, 6220U, 6748U, 7268U, 7512U, 8024U, 8552U, 8800U, 10240U}, {0U, 4U, 
    1892U, 2140U, 2596U, 2880U, 3396U, 3640U, 4436U, 4676U, 5200U, 5712U, 6220U, 6748U, 7268U, 7512U, 8024U, 8552U, 
    8800U, 10240U}
  },
  {
    {0U, 0U, 40U, 58U, 98U, 159U, 242U, 343U, 470U, 615U, 782U, 972U, 1182U, 1411U, 1663U, 1937U, 2232U, 2546U, 18022U, 
    18022U}, {0U, 0U, 41U, 52U, 73U, 107U, 150U, 205U, 270U, 346U, 432U, 530U, 637U, 756U, 885U, 1025U, 1176U, 1338U, 
    18022U, 18022U}, {0U, 0U, 29U, 37U, 55U, 86U, 122U, 171U, 229U, 294U, 372U, 458U, 551U, 655U, 770U, 894U, 1027U, 
    1169U, 1321U, 15274U}, {0U, 0U, 41U, 55U, 79U, 121U, 171U, 239U, 317U, 409U, 513U, 630U, 759U, 904U, 1059U, 1230U, 
    1413U, 1607U, 1815U, 12432U}, {0U, 0U, 49U, 73U, 113U, 171U, 245U, 340U, 447U, 574U, 716U, 879U, 1053U, 1249U, 1460U, 
    1688U, 1933U, 2196U, 2473U, 10636U}, {0U, 0U, 49U, 73U, 113U, 171U, 245U, 340U, 447U, 574U, 716U, 879U, 1053U, 1249U, 
    1460U, 1688U, 1933U, 2196U, 2473U, 9452U}, {0U, 0U, 49U, 73U, 113U, 171U, 245U, 340U, 447U, 574U, 716U, 879U, 1053U, 
    1249U, 1460U, 1688U, 1933U, 2196U, 2473U, 8691U}, {0U, 0U, 49U, 73U, 113U, 171U, 245U, 340U, 447U, 574U, 716U, 879U, 
    1053U, 1249U, 1460U, 1688U, 1933U, 2196U, 2473U, 8122U}, {0U, 0U, 49U, 73U, 113U, 171U, 245U, 340U, 447U, 574U, 716U, 
    879U, 1053U, 1249U, 1460U, 1688U, 1933U, 2196U, 2473U, 6697U}, {0U, 0U, 49U, 73U, 113U, 171U, 245U, 340U, 447U, 574U, 
    716U, 879U, 1053U, 1249U, 1460U, 1688U, 1933U, 2196U, 2473U, 4706U}, {0U, 0U, 66U, 84U, 131U, 168U, 254U, 300U, 488U, 
    554U, 713U, 892U, 1090U, 1315U, 1559U, 1681U, 1953U, 2253U, 2404U, 3267U}, {0U, 0U, 66U, 84U, 131U, 168U, 254U, 300U, 
    488U, 554U, 713U, 892U, 1090U, 1315U, 1559U, 1681U, 1953U, 2253U, 2404U, 3267U}
  },
  {
    {-20480, -10240, -8192, -6144, -4096, -2048, 0, 2048, 4096, 6144, 8192, 10240, 20480}, {-20480, -10240, -8192, -6144, 
    -4096, -2048, 0, 2048, 4096, 6144, 8192, 10240, 20480}, {-20480, -10240, -8192, -6144, -4096, -2048, 0, 2048, 4096, 
    6144, 8192, 10240, 20480}, {-20480, -10240, -8192, -6144, -4096, -2048, 0, 2048, 4096, 6144, 8192, 10240, 20480}, {
    -20480, -10240, -8192, -6144, -4096, -2048, 0, 2048, 4096, 6144, 8192, 10240, 20480}, {-20480, -10240, -8192, -6144, 
    -4096, -2048, 0, 2048, 4096, 6144, 8192, 10240, 20480}, {-20480, -10240, -8192, -6144, -4096, -2048, 0, 2048, 4096, 
    6144, 8192, 10240, 20480}, {-20480, -10240, -8192, -6144, -4096, -2048, 0, 2048, 4096, 6144, 8192, 10240, 20480}, {
    -20480, -10240, -8192, -6144, -4096, -2048, 0, 2048, 4096, 6144, 8192, 10240, 20480}, {-20480, -10240, -8192, -6144, 
    -4096, -2048, 0, 2048, 4096, 6144, 8192, 10240, 20480}
  },
  {
    {-11754, -11754, -10774, -4114, -1959, -196, 1567, 3918, 7836, 17631, 18022, 18022, 18022}, {-11754, -11754, -9795, 
    -1959, -784, 196, 784, 1175, 5877, 12537, 15672, 18022, 18022}, {-11754, -7836, -3918, -1959, -196, 0, 1175, 2938, 
    3526, 6269, 18022, 18022, 18022}, {-11754, -5877, -4506, 0, 196, 588, 784, 980, 2938, 5093, 7836, 18022, 18022}, {0, 
    0, 0, 392, 588, 588, 784, 2938, 3330, 4114, 5877, 5877, 5877}, {0, 784, 784, 784, 784, 784, 784, 2547, 2938, 3526, 
    5877, 5877, 5877}, {0, 784, 784, 784, 784, 784, 784, 2547, 2938, 3526, 5877, 5877, 5877}, {0, 784, 784, 784, 784, 
    784, 784, 2547, 2938, 3526, 5877, 5877, 5877}, {0, 784, 784, 784, 784, 784, 784, 2547, 2938, 3526, 5877, 5877, 5877}, 
    {0, 784, 784, 784, 784, 784, 784, 2547, 2938, 3526, 5877, 5877, 5877}
  },
  {
    0U, 640U, 3840U, 7680U, 10240U, 12800U, 15360U, 19200U, 23040U, 25600U
  },
  {
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F
  },
  {
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F
  }
};
CONST(Rte_Calprm_CalRegn01Inin01GroupD_DEFAULT_RTE_CALPRM_GROUP_Type, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_CalprmRom_CalRegn01Inin01GroupD_DEFAULT_RTE_CALPRM_GROUP = { /* PRQA S 3408 */ /* MD_Rte_3408 */
  0.0F,
  0.5F,
  30.0F,
  5.0F,
  30.0F,
  0.02F,
  0.29F,
  3.0F,
  1.0F,
  1.0F,
  90.0F,
  20.0F,
  20.0F,
  1.0F,
  -4500.0F,
  1.0F,
  10.0F,
  0.001F,
  20.0F,
  FALSE,
  FALSE,
  {
    0U, 640U, 1280U, 2560U
  },
  {
    0U, 640U, 1280U, 1920U, 2560U
  },
  {
    {0U, 480U, 960U, 1440U}, {0U, 480U, 960U, 1440U}, {0U, 480U, 960U, 1440U}, {0U, 480U, 960U, 1440U}, {0U, 480U, 960U, 
    1440U}
  },
  {
    {0U, 10813U, 21627U, 32768U}, {0U, 10813U, 21627U, 32768U}, {0U, 10813U, 21627U, 32768U}, {0U, 10813U, 21627U, 32768U
    }, {0U, 10813U, 21627U, 32768U}
  },
  {
    {0U, 262U}, {0U, 262U}, {0U, 262U}, {0U, 262U}
  },
  {
    {1920U, 0U}, {1920U, 0U}, {1920U, 0U}, {1920U, 0U}
  },
  {
    0U, 4096U
  },
  {
    {0U, 9830U, 22938U, 32768U}, {0U, 9830U, 22938U, 32768U}, {0U, 9830U, 22938U, 32768U}, {0U, 9830U, 22938U, 32768U}, {
    0U, 9830U, 22938U, 32768U}
  },
  {
    800U, 400U
  },
  {
    10400U, 10400U
  },
  {
    {0U, 262U}, {0U, 262U}, {0U, 262U}, {0U, 262U}
  },
  {
    0U, 2048U, 4096U, 6144U, 8192U, 10240U, 12288U, 14336U, 16384U, 18432U
  },
  {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  },
  {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  },
  {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  },
  {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  },
  {
    384U, 384U, 384U, 384U, 384U, 384U, 384U, 384U, 384U, 384U, 384U, 384U
  },
  {
    0U, 640U, 1088U, 1120U, 1152U, 1184U
  },
  {
    36000U, 36000U, 36000U, 36000U, 36000U, 36000U
  },
  {
    8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U
  },
  {
    8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U
  },
  {
    32768U, 32768U, 9830U, 6554U, 3277U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  },
  {
    208U, 432U, 640U, 848U, 1056U
  },
  {
    0U, 0U, 0U, 0U, 0U
  },
  {
    0U, 4096U
  },
  {
    32768U, 0U
  },
  {
    1005U, 1100U
  },
  {
    32768U, 32768U
  },
  {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  },
  {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  },
  {
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F
  }
};
CONST(Rte_Calprm_CalRegn01Inin01_DEFAULT_RTE_CALPRM_GROUP_Type, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_CalprmRom_CalRegn01Inin01_DEFAULT_RTE_CALPRM_GROUP = { /* PRQA S 3408 */ /* MD_Rte_3408 */
  2100.0F,
  500.0F,
  1.0F,
  20.0F,
  3.0F,
  0.1F,
  0.0F,
  30.0F,
  1.0F,
  -1.0F,
  0.8F,
  15.0F,
  0.0F,
  1.0F,
  -1.0F,
  4.0F,
  0.2F,
  30.0F,
  0.98F,
  360.0F,
  180.0F,
  10.0F,
  3.0F,
  3.0F,
  10.0F,
  0.0F,
  100.0F,
  0.0F,
  22.0F,
  1U,
  656U,
  656U,
  65534U,
  {
    0, 20, 40, 60, 80, 100, 120, 140, 160, 180
  },
  {
    0U, 3641U, 7281U, 10922U, 14562U, 18206U, 21846U, 25487U, 29127U, 32768U
  },
  {
    0.0F, 0.0F, 0.0F, 0.0F
  },
  {
    {0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 
    0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F}
  },
  {
    {0U, 0U, 0U}, {0U, 0U, 0U}, {0U, 0U, 0U}, {0U, 0U, 0U}, {0U, 0U, 0U}, {0U, 0U, 0U}, {0U, 0U, 0U}, {0U, 0U, 0U}
  },
  {
    1.0F, 1.0F, 1.0F, 1.0F
  },
  {
    -15.0F, -5.0F, 5.0F, 15.0F
  },
  {
    0U, 960U, 1920U, 2880U, 3840U, 5760U, 8640U, 11520U, 14400U, 17280U
  },
  {
    24269U, 24269U, 24269U, 24269U, 24269U, 24269U, 24269U, 24269U, 24269U, 24269U
  },
  {
    TRUE, TRUE, TRUE, TRUE
  },
  {
    {0.0F, 5.0F}, {60.0F, 80.0F}, {80.0F, 100.0F}, {100.0F, 120.0F}
  },
  {
    0U, 640U, 1920U, 3840U, 7680U, 10240U, 12800U, 15360U, 19200U, 23040U, 25600U, 28160U
  },
  {
    1233U, 1237U, 1241U, 1245U, 1249U, 1253U, 1257U, 1262U, 1262U, 1262U, 1262U, 1262U, 1262U, 1262U, 1257U, 1253U, 
    1249U, 1245U, 1241U, 1237U, 1233U
  },
  {
    17592U, 17592U, 17592U, 17285U, 16589U, 15770U, 14930U, 14213U, 13926U, 13681U, 13681U, 13681U, 13926U, 14213U, 
    14930U, 15770U, 16589U, 17285U, 17592U, 17592U, 17592U
  },
  {
    29491U, 29655U, 29819U, 29983U, 30147U, 30147U, 30147U, 30147U, 30147U, 30147U, 30147U, 30147U, 30147U, 30147U, 
    30147U, 30147U, 30147U, 29983U, 29819U, 29655U, 29491U
  },
  {
    -5939, -5300, -4678, -4063, -3465, -2867, -2277, -1704, -1139, -565, 0, 565, 1139, 1704, 2277, 2867, 3465, 4063, 
    4678, 5300, 5939
  },
  {
    4522U, 4555U, 4588U, 4620U, 4653U, 4686U, 4719U, 4719U, 4719U, 4719U, 4719U, 4719U, 4719U, 4719U, 4719U, 4686U, 
    4653U, 4620U, 4588U, 4555U, 4522U
  },
  {
    0U, 12800U, 25600U, 38400U, 51200U, 65408U
  }
};
CONST(Rte_Calprm_CalRegn01Inin02GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_CalprmRom_CalRegn01Inin02GroupA_DEFAULT_RTE_CALPRM_GROUP = { /* PRQA S 3408 */ /* MD_Rte_3408 */
  -360.0F,
  -900.0F,
  900.0F,
  360.0F,
  1.0F,
  45.0F,
  45.0F,
  45.0F,
  45.0F,
  3.0F,
  1.0F,
  1.0F,
  0.5F,
  0.5F,
  0.5F,
  1.0F,
  45.0F,
  2.8F,
  10.0F,
  0.5F,
  2.0F,
  160.0F,
  60.0F,
  1.0F,
  1.0F,
  0.1F,
  100.0F,
  1.0F,
  0.0F,
  3.0F,
  0.25F,
  3.0F,
  1.0F,
  TRUE,
  TRUE,
  {
    {1.0F, 0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 1.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 1.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 
    1.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F, 1.0F}
  },
  {
    {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}
  },
  {
    {1.0F, 0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 1.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 1.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 
    1.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F, 1.0F}
  },
  {
    {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}
  },
  {
    0, 0, 0, 0
  },
  {
    0, 0, 0, 0
  },
  {
    0, 0, 0, 0
  },
  {
    0, 0, 0, 0
  },
  {
    0, 0, 0, 0
  },
  {
    0, 0, 0, 0
  },
  {
    0U, 1280U, 2560U, 25600U
  },
  {
    0U, 26U, 51U, 77U, 128U, 256U, 512U, 768U, 1024U, 2560U
  },
  {
    0U, 164U, 328U, 819U, 1638U, 3277U, 8192U, 11469U, 16384U, 16384U
  },
  {
    960U, 960U, 800U, 640U, 480U, 320U, 320U, 160U, 160U, 160U, 160U, 160U
  },
  {
    0U, 3840U, 7680U, 11520U
  },
  {
    0U, 4096U, 16384U, 16384U
  }
};
CONST(Rte_Calprm_CalRegn01Inin02GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_CalprmRom_CalRegn01Inin02GroupC_DEFAULT_RTE_CALPRM_GROUP = { /* PRQA S 3408 */ /* MD_Rte_3408 */
  20.0F,
  20.0F,
  500.0F,
  -500.0F,
  0.0F,
  0.0F,
  0.04F,
  17.0F,
  20.0F,
  {
    {2048U, 5120U, 5120U, 10240U, 10240U, 15360U, 15360U, 20480U, 20480U}, {2048U, 5120U, 5120U, 10240U, 10240U, 15360U, 
    15360U, 20480U, 20480U}, {2048U, 5120U, 5120U, 10240U, 10240U, 10240U, 15360U, 15360U, 15360U}, {2048U, 5120U, 5120U, 
    10240U, 10240U, 10240U, 10240U, 10240U, 10240U}, {2048U, 5120U, 5120U, 10240U, 10240U, 10240U, 10240U, 10240U, 10240U}
  },
  {
    {0U, 4U, 508U, 608U, 712U, 816U, 916U, 1020U, 1124U, 1228U, 1328U, 1432U, 1536U, 1636U, 1740U, 1844U, 1944U, 2048U, 
    6920U, 10240U}, {0U, 204U, 716U, 792U, 868U, 944U, 1016U, 1092U, 1168U, 1244U, 1316U, 1392U, 1468U, 1544U, 1616U, 
    1692U, 1768U, 1844U, 9348U, 10240U}, {0U, 308U, 820U, 908U, 1000U, 1088U, 1176U, 1268U, 1356U, 1448U, 1536U, 1624U, 
    1716U, 1804U, 1896U, 1984U, 2072U, 2164U, 2252U, 10240U}, {0U, 192U, 1024U, 1164U, 1304U, 1448U, 1588U, 1728U, 1868U, 
    2008U, 2152U, 2292U, 2432U, 2572U, 2712U, 2856U, 2996U, 3136U, 3276U, 10240U}, {0U, 176U, 836U, 1048U, 1260U, 1472U, 
    1684U, 1896U, 2108U, 2320U, 2532U, 2744U, 2956U, 3168U, 3380U, 3592U, 3804U, 4016U, 4228U, 10240U}, {0U, 192U, 916U, 
    1148U, 1376U, 1608U, 1840U, 2072U, 2304U, 2536U, 2768U, 3000U, 3232U, 3464U, 3692U, 3924U, 4156U, 4388U, 4620U, 10240U
    }, {0U, 204U, 972U, 1220U, 1464U, 1712U, 1960U, 2204U, 2452U, 2696U, 2944U, 3192U, 3436U, 3684U, 3928U, 4176U, 4424U, 
    4668U, 4916U, 10240U}, {0U, 216U, 1020U, 1280U, 1540U, 1796U, 2056U, 2316U, 2572U, 2832U, 3092U, 3348U, 3608U, 3868U, 
    4128U, 4384U, 4644U, 4904U, 5160U, 10240U}, {0U, 244U, 1168U, 1464U, 1760U, 2056U, 2352U, 2644U, 2940U, 3236U, 3532U, 
    3828U, 4124U, 4420U, 4716U, 5012U, 5308U, 5604U, 5900U, 10240U}, {0U, 308U, 1460U, 1828U, 2200U, 2568U, 2936U, 3308U, 
    3676U, 4048U, 4416U, 4784U, 5156U, 5524U, 5896U, 6264U, 6632U, 7004U, 7372U, 10240U}, {0U, 4U, 1892U, 2140U, 2596U, 
    2880U, 3396U, 3640U, 4436U, 4676U, 5200U, 5712U, 6220U, 6748U, 7268U, 7512U, 8024U, 8552U, 8800U, 10240U}, {0U, 4U, 
    1892U, 2140U, 2596U, 2880U, 3396U, 3640U, 4436U, 4676U, 5200U, 5712U, 6220U, 6748U, 7268U, 7512U, 8024U, 8552U, 
    8800U, 10240U}
  },
  {
    {0U, 0U, 40U, 58U, 98U, 159U, 242U, 343U, 470U, 615U, 782U, 972U, 1182U, 1411U, 1663U, 1937U, 2232U, 2546U, 18022U, 
    18022U}, {0U, 0U, 41U, 52U, 73U, 107U, 150U, 205U, 270U, 346U, 432U, 530U, 637U, 756U, 885U, 1025U, 1176U, 1338U, 
    18022U, 18022U}, {0U, 0U, 29U, 37U, 55U, 86U, 122U, 171U, 229U, 294U, 372U, 458U, 551U, 655U, 770U, 894U, 1027U, 
    1169U, 1321U, 15274U}, {0U, 0U, 41U, 55U, 79U, 121U, 171U, 239U, 317U, 409U, 513U, 630U, 759U, 904U, 1059U, 1230U, 
    1413U, 1607U, 1815U, 12432U}, {0U, 0U, 49U, 73U, 113U, 171U, 245U, 340U, 447U, 574U, 716U, 879U, 1053U, 1249U, 1460U, 
    1688U, 1933U, 2196U, 2473U, 10636U}, {0U, 0U, 49U, 73U, 113U, 171U, 245U, 340U, 447U, 574U, 716U, 879U, 1053U, 1249U, 
    1460U, 1688U, 1933U, 2196U, 2473U, 9452U}, {0U, 0U, 49U, 73U, 113U, 171U, 245U, 340U, 447U, 574U, 716U, 879U, 1053U, 
    1249U, 1460U, 1688U, 1933U, 2196U, 2473U, 8691U}, {0U, 0U, 49U, 73U, 113U, 171U, 245U, 340U, 447U, 574U, 716U, 879U, 
    1053U, 1249U, 1460U, 1688U, 1933U, 2196U, 2473U, 8122U}, {0U, 0U, 49U, 73U, 113U, 171U, 245U, 340U, 447U, 574U, 716U, 
    879U, 1053U, 1249U, 1460U, 1688U, 1933U, 2196U, 2473U, 6697U}, {0U, 0U, 49U, 73U, 113U, 171U, 245U, 340U, 447U, 574U, 
    716U, 879U, 1053U, 1249U, 1460U, 1688U, 1933U, 2196U, 2473U, 4706U}, {0U, 0U, 66U, 84U, 131U, 168U, 254U, 300U, 488U, 
    554U, 713U, 892U, 1090U, 1315U, 1559U, 1681U, 1953U, 2253U, 2404U, 3267U}, {0U, 0U, 66U, 84U, 131U, 168U, 254U, 300U, 
    488U, 554U, 713U, 892U, 1090U, 1315U, 1559U, 1681U, 1953U, 2253U, 2404U, 3267U}
  },
  {
    {-20480, -10240, -8192, -6144, -4096, -2048, 0, 2048, 4096, 6144, 8192, 10240, 20480}, {-20480, -10240, -8192, -6144, 
    -4096, -2048, 0, 2048, 4096, 6144, 8192, 10240, 20480}, {-20480, -10240, -8192, -6144, -4096, -2048, 0, 2048, 4096, 
    6144, 8192, 10240, 20480}, {-20480, -10240, -8192, -6144, -4096, -2048, 0, 2048, 4096, 6144, 8192, 10240, 20480}, {
    -20480, -10240, -8192, -6144, -4096, -2048, 0, 2048, 4096, 6144, 8192, 10240, 20480}, {-20480, -10240, -8192, -6144, 
    -4096, -2048, 0, 2048, 4096, 6144, 8192, 10240, 20480}, {-20480, -10240, -8192, -6144, -4096, -2048, 0, 2048, 4096, 
    6144, 8192, 10240, 20480}, {-20480, -10240, -8192, -6144, -4096, -2048, 0, 2048, 4096, 6144, 8192, 10240, 20480}, {
    -20480, -10240, -8192, -6144, -4096, -2048, 0, 2048, 4096, 6144, 8192, 10240, 20480}, {-20480, -10240, -8192, -6144, 
    -4096, -2048, 0, 2048, 4096, 6144, 8192, 10240, 20480}
  },
  {
    {-11754, -11754, -10774, -4114, -1959, -196, 1567, 3918, 7836, 17631, 18022, 18022, 18022}, {-11754, -11754, -9795, 
    -1959, -784, 196, 784, 1175, 5877, 12537, 15672, 18022, 18022}, {-11754, -7836, -3918, -1959, -196, 0, 1175, 2938, 
    3526, 6269, 18022, 18022, 18022}, {-11754, -5877, -4506, 0, 196, 588, 784, 980, 2938, 5093, 7836, 18022, 18022}, {0, 
    0, 0, 392, 588, 588, 784, 2938, 3330, 4114, 5877, 5877, 5877}, {0, 784, 784, 784, 784, 784, 784, 2547, 2938, 3526, 
    5877, 5877, 5877}, {0, 784, 784, 784, 784, 784, 784, 2547, 2938, 3526, 5877, 5877, 5877}, {0, 784, 784, 784, 784, 
    784, 784, 2547, 2938, 3526, 5877, 5877, 5877}, {0, 784, 784, 784, 784, 784, 784, 2547, 2938, 3526, 5877, 5877, 5877}, 
    {0, 784, 784, 784, 784, 784, 784, 2547, 2938, 3526, 5877, 5877, 5877}
  },
  {
    0U, 640U, 3840U, 7680U, 10240U, 12800U, 15360U, 19200U, 23040U, 25600U
  },
  {
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F
  },
  {
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F
  }
};
CONST(Rte_Calprm_CalRegn01Inin02GroupD_DEFAULT_RTE_CALPRM_GROUP_Type, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_CalprmRom_CalRegn01Inin02GroupD_DEFAULT_RTE_CALPRM_GROUP = { /* PRQA S 3408 */ /* MD_Rte_3408 */
  0.0F,
  0.5F,
  30.0F,
  5.0F,
  30.0F,
  0.02F,
  0.29F,
  3.0F,
  1.0F,
  1.0F,
  90.0F,
  20.0F,
  20.0F,
  1.0F,
  -4500.0F,
  1.0F,
  10.0F,
  0.001F,
  20.0F,
  FALSE,
  FALSE,
  {
    0U, 640U, 1280U, 2560U
  },
  {
    0U, 640U, 1280U, 1920U, 2560U
  },
  {
    {0U, 480U, 960U, 1440U}, {0U, 480U, 960U, 1440U}, {0U, 480U, 960U, 1440U}, {0U, 480U, 960U, 1440U}, {0U, 480U, 960U, 
    1440U}
  },
  {
    {0U, 10813U, 21627U, 32768U}, {0U, 10813U, 21627U, 32768U}, {0U, 10813U, 21627U, 32768U}, {0U, 10813U, 21627U, 32768U
    }, {0U, 10813U, 21627U, 32768U}
  },
  {
    {0U, 262U}, {0U, 262U}, {0U, 262U}, {0U, 262U}
  },
  {
    {1920U, 0U}, {1920U, 0U}, {1920U, 0U}, {1920U, 0U}
  },
  {
    0U, 4096U
  },
  {
    {0U, 9830U, 22938U, 32768U}, {0U, 9830U, 22938U, 32768U}, {0U, 9830U, 22938U, 32768U}, {0U, 9830U, 22938U, 32768U}, {
    0U, 9830U, 22938U, 32768U}
  },
  {
    800U, 400U
  },
  {
    10400U, 10400U
  },
  {
    {0U, 262U}, {0U, 262U}, {0U, 262U}, {0U, 262U}
  },
  {
    0U, 2048U, 4096U, 6144U, 8192U, 10240U, 12288U, 14336U, 16384U, 18432U
  },
  {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  },
  {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  },
  {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  },
  {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  },
  {
    384U, 384U, 384U, 384U, 384U, 384U, 384U, 384U, 384U, 384U, 384U, 384U
  },
  {
    0U, 640U, 1088U, 1120U, 1152U, 1184U
  },
  {
    36000U, 36000U, 36000U, 36000U, 36000U, 36000U
  },
  {
    8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U
  },
  {
    8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U
  },
  {
    32768U, 32768U, 9830U, 6554U, 3277U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  },
  {
    208U, 432U, 640U, 848U, 1056U
  },
  {
    0U, 0U, 0U, 0U, 0U
  },
  {
    0U, 4096U
  },
  {
    32768U, 0U
  },
  {
    1005U, 1100U
  },
  {
    32768U, 32768U
  },
  {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  },
  {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  },
  {
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F
  }
};
CONST(Rte_Calprm_CalRegn01Inin02_DEFAULT_RTE_CALPRM_GROUP_Type, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_CalprmRom_CalRegn01Inin02_DEFAULT_RTE_CALPRM_GROUP = { /* PRQA S 3408 */ /* MD_Rte_3408 */
  2100.0F,
  500.0F,
  1.0F,
  20.0F,
  3.0F,
  0.1F,
  0.0F,
  30.0F,
  1.0F,
  -1.0F,
  0.8F,
  15.0F,
  0.0F,
  1.0F,
  -1.0F,
  4.0F,
  0.2F,
  30.0F,
  0.98F,
  360.0F,
  180.0F,
  10.0F,
  3.0F,
  3.0F,
  10.0F,
  0.0F,
  100.0F,
  0.0F,
  22.0F,
  1U,
  656U,
  656U,
  65534U,
  {
    0, 20, 40, 60, 80, 100, 120, 140, 160, 180
  },
  {
    0U, 3641U, 7281U, 10922U, 14562U, 18206U, 21846U, 25487U, 29127U, 32768U
  },
  {
    0.0F, 0.0F, 0.0F, 0.0F
  },
  {
    {0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 
    0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F}
  },
  {
    {0U, 0U, 0U}, {0U, 0U, 0U}, {0U, 0U, 0U}, {0U, 0U, 0U}, {0U, 0U, 0U}, {0U, 0U, 0U}, {0U, 0U, 0U}, {0U, 0U, 0U}
  },
  {
    1.0F, 1.0F, 1.0F, 1.0F
  },
  {
    -15.0F, -5.0F, 5.0F, 15.0F
  },
  {
    0U, 960U, 1920U, 2880U, 3840U, 5760U, 8640U, 11520U, 14400U, 17280U
  },
  {
    24269U, 24269U, 24269U, 24269U, 24269U, 24269U, 24269U, 24269U, 24269U, 24269U
  },
  {
    TRUE, TRUE, TRUE, TRUE
  },
  {
    {0.0F, 5.0F}, {60.0F, 80.0F}, {80.0F, 100.0F}, {100.0F, 120.0F}
  },
  {
    0U, 640U, 1920U, 3840U, 7680U, 10240U, 12800U, 15360U, 19200U, 23040U, 25600U, 28160U
  },
  {
    1233U, 1237U, 1241U, 1245U, 1249U, 1253U, 1257U, 1262U, 1262U, 1262U, 1262U, 1262U, 1262U, 1262U, 1257U, 1253U, 
    1249U, 1245U, 1241U, 1237U, 1233U
  },
  {
    17592U, 17592U, 17592U, 17285U, 16589U, 15770U, 14930U, 14213U, 13926U, 13681U, 13681U, 13681U, 13926U, 14213U, 
    14930U, 15770U, 16589U, 17285U, 17592U, 17592U, 17592U
  },
  {
    29491U, 29655U, 29819U, 29983U, 30147U, 30147U, 30147U, 30147U, 30147U, 30147U, 30147U, 30147U, 30147U, 30147U, 
    30147U, 30147U, 30147U, 29983U, 29819U, 29655U, 29491U
  },
  {
    -5939, -5300, -4678, -4063, -3465, -2867, -2277, -1704, -1139, -565, 0, 565, 1139, 1704, 2277, 2867, 3465, 4063, 
    4678, 5300, 5939
  },
  {
    4522U, 4555U, 4588U, 4620U, 4653U, 4686U, 4719U, 4719U, 4719U, 4719U, 4719U, 4719U, 4719U, 4719U, 4719U, 4686U, 
    4653U, 4620U, 4588U, 4555U, 4522U
  },
  {
    0U, 12800U, 25600U, 38400U, 51200U, 65408U
  }
};
CONST(Rte_Calprm_CalRegn01Inin03GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_CalprmRom_CalRegn01Inin03GroupA_DEFAULT_RTE_CALPRM_GROUP = { /* PRQA S 3408 */ /* MD_Rte_3408 */
  -360.0F,
  -900.0F,
  900.0F,
  360.0F,
  1.0F,
  45.0F,
  45.0F,
  45.0F,
  45.0F,
  3.0F,
  1.0F,
  1.0F,
  0.5F,
  0.5F,
  0.5F,
  1.0F,
  45.0F,
  2.8F,
  10.0F,
  0.5F,
  2.0F,
  160.0F,
  60.0F,
  1.0F,
  1.0F,
  0.1F,
  100.0F,
  1.0F,
  0.0F,
  3.0F,
  0.25F,
  3.0F,
  1.0F,
  TRUE,
  TRUE,
  {
    {1.0F, 0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 1.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 1.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 
    1.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F, 1.0F}
  },
  {
    {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}
  },
  {
    {1.0F, 0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 1.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 1.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 
    1.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F, 1.0F}
  },
  {
    {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}
  },
  {
    0, 0, 0, 0
  },
  {
    0, 0, 0, 0
  },
  {
    0, 0, 0, 0
  },
  {
    0, 0, 0, 0
  },
  {
    0, 0, 0, 0
  },
  {
    0, 0, 0, 0
  },
  {
    0U, 1280U, 2560U, 25600U
  },
  {
    0U, 26U, 51U, 77U, 128U, 256U, 512U, 768U, 1024U, 2560U
  },
  {
    0U, 164U, 328U, 819U, 1638U, 3277U, 8192U, 11469U, 16384U, 16384U
  },
  {
    960U, 960U, 800U, 640U, 480U, 320U, 320U, 160U, 160U, 160U, 160U, 160U
  },
  {
    0U, 3840U, 7680U, 11520U
  },
  {
    0U, 4096U, 16384U, 16384U
  }
};
CONST(Rte_Calprm_CalRegn01Inin03GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_CalprmRom_CalRegn01Inin03GroupC_DEFAULT_RTE_CALPRM_GROUP = { /* PRQA S 3408 */ /* MD_Rte_3408 */
  20.0F,
  20.0F,
  500.0F,
  -500.0F,
  0.0F,
  0.0F,
  0.04F,
  17.0F,
  20.0F,
  {
    {2048U, 5120U, 5120U, 10240U, 10240U, 15360U, 15360U, 20480U, 20480U}, {2048U, 5120U, 5120U, 10240U, 10240U, 15360U, 
    15360U, 20480U, 20480U}, {2048U, 5120U, 5120U, 10240U, 10240U, 10240U, 15360U, 15360U, 15360U}, {2048U, 5120U, 5120U, 
    10240U, 10240U, 10240U, 10240U, 10240U, 10240U}, {2048U, 5120U, 5120U, 10240U, 10240U, 10240U, 10240U, 10240U, 10240U}
  },
  {
    {0U, 4U, 508U, 608U, 712U, 816U, 916U, 1020U, 1124U, 1228U, 1328U, 1432U, 1536U, 1636U, 1740U, 1844U, 1944U, 2048U, 
    6920U, 10240U}, {0U, 204U, 716U, 792U, 868U, 944U, 1016U, 1092U, 1168U, 1244U, 1316U, 1392U, 1468U, 1544U, 1616U, 
    1692U, 1768U, 1844U, 9348U, 10240U}, {0U, 308U, 820U, 908U, 1000U, 1088U, 1176U, 1268U, 1356U, 1448U, 1536U, 1624U, 
    1716U, 1804U, 1896U, 1984U, 2072U, 2164U, 2252U, 10240U}, {0U, 192U, 1024U, 1164U, 1304U, 1448U, 1588U, 1728U, 1868U, 
    2008U, 2152U, 2292U, 2432U, 2572U, 2712U, 2856U, 2996U, 3136U, 3276U, 10240U}, {0U, 176U, 836U, 1048U, 1260U, 1472U, 
    1684U, 1896U, 2108U, 2320U, 2532U, 2744U, 2956U, 3168U, 3380U, 3592U, 3804U, 4016U, 4228U, 10240U}, {0U, 192U, 916U, 
    1148U, 1376U, 1608U, 1840U, 2072U, 2304U, 2536U, 2768U, 3000U, 3232U, 3464U, 3692U, 3924U, 4156U, 4388U, 4620U, 10240U
    }, {0U, 204U, 972U, 1220U, 1464U, 1712U, 1960U, 2204U, 2452U, 2696U, 2944U, 3192U, 3436U, 3684U, 3928U, 4176U, 4424U, 
    4668U, 4916U, 10240U}, {0U, 216U, 1020U, 1280U, 1540U, 1796U, 2056U, 2316U, 2572U, 2832U, 3092U, 3348U, 3608U, 3868U, 
    4128U, 4384U, 4644U, 4904U, 5160U, 10240U}, {0U, 244U, 1168U, 1464U, 1760U, 2056U, 2352U, 2644U, 2940U, 3236U, 3532U, 
    3828U, 4124U, 4420U, 4716U, 5012U, 5308U, 5604U, 5900U, 10240U}, {0U, 308U, 1460U, 1828U, 2200U, 2568U, 2936U, 3308U, 
    3676U, 4048U, 4416U, 4784U, 5156U, 5524U, 5896U, 6264U, 6632U, 7004U, 7372U, 10240U}, {0U, 4U, 1892U, 2140U, 2596U, 
    2880U, 3396U, 3640U, 4436U, 4676U, 5200U, 5712U, 6220U, 6748U, 7268U, 7512U, 8024U, 8552U, 8800U, 10240U}, {0U, 4U, 
    1892U, 2140U, 2596U, 2880U, 3396U, 3640U, 4436U, 4676U, 5200U, 5712U, 6220U, 6748U, 7268U, 7512U, 8024U, 8552U, 
    8800U, 10240U}
  },
  {
    {0U, 0U, 40U, 58U, 98U, 159U, 242U, 343U, 470U, 615U, 782U, 972U, 1182U, 1411U, 1663U, 1937U, 2232U, 2546U, 18022U, 
    18022U}, {0U, 0U, 41U, 52U, 73U, 107U, 150U, 205U, 270U, 346U, 432U, 530U, 637U, 756U, 885U, 1025U, 1176U, 1338U, 
    18022U, 18022U}, {0U, 0U, 29U, 37U, 55U, 86U, 122U, 171U, 229U, 294U, 372U, 458U, 551U, 655U, 770U, 894U, 1027U, 
    1169U, 1321U, 15274U}, {0U, 0U, 41U, 55U, 79U, 121U, 171U, 239U, 317U, 409U, 513U, 630U, 759U, 904U, 1059U, 1230U, 
    1413U, 1607U, 1815U, 12432U}, {0U, 0U, 49U, 73U, 113U, 171U, 245U, 340U, 447U, 574U, 716U, 879U, 1053U, 1249U, 1460U, 
    1688U, 1933U, 2196U, 2473U, 10636U}, {0U, 0U, 49U, 73U, 113U, 171U, 245U, 340U, 447U, 574U, 716U, 879U, 1053U, 1249U, 
    1460U, 1688U, 1933U, 2196U, 2473U, 9452U}, {0U, 0U, 49U, 73U, 113U, 171U, 245U, 340U, 447U, 574U, 716U, 879U, 1053U, 
    1249U, 1460U, 1688U, 1933U, 2196U, 2473U, 8691U}, {0U, 0U, 49U, 73U, 113U, 171U, 245U, 340U, 447U, 574U, 716U, 879U, 
    1053U, 1249U, 1460U, 1688U, 1933U, 2196U, 2473U, 8122U}, {0U, 0U, 49U, 73U, 113U, 171U, 245U, 340U, 447U, 574U, 716U, 
    879U, 1053U, 1249U, 1460U, 1688U, 1933U, 2196U, 2473U, 6697U}, {0U, 0U, 49U, 73U, 113U, 171U, 245U, 340U, 447U, 574U, 
    716U, 879U, 1053U, 1249U, 1460U, 1688U, 1933U, 2196U, 2473U, 4706U}, {0U, 0U, 66U, 84U, 131U, 168U, 254U, 300U, 488U, 
    554U, 713U, 892U, 1090U, 1315U, 1559U, 1681U, 1953U, 2253U, 2404U, 3267U}, {0U, 0U, 66U, 84U, 131U, 168U, 254U, 300U, 
    488U, 554U, 713U, 892U, 1090U, 1315U, 1559U, 1681U, 1953U, 2253U, 2404U, 3267U}
  },
  {
    {-20480, -10240, -8192, -6144, -4096, -2048, 0, 2048, 4096, 6144, 8192, 10240, 20480}, {-20480, -10240, -8192, -6144, 
    -4096, -2048, 0, 2048, 4096, 6144, 8192, 10240, 20480}, {-20480, -10240, -8192, -6144, -4096, -2048, 0, 2048, 4096, 
    6144, 8192, 10240, 20480}, {-20480, -10240, -8192, -6144, -4096, -2048, 0, 2048, 4096, 6144, 8192, 10240, 20480}, {
    -20480, -10240, -8192, -6144, -4096, -2048, 0, 2048, 4096, 6144, 8192, 10240, 20480}, {-20480, -10240, -8192, -6144, 
    -4096, -2048, 0, 2048, 4096, 6144, 8192, 10240, 20480}, {-20480, -10240, -8192, -6144, -4096, -2048, 0, 2048, 4096, 
    6144, 8192, 10240, 20480}, {-20480, -10240, -8192, -6144, -4096, -2048, 0, 2048, 4096, 6144, 8192, 10240, 20480}, {
    -20480, -10240, -8192, -6144, -4096, -2048, 0, 2048, 4096, 6144, 8192, 10240, 20480}, {-20480, -10240, -8192, -6144, 
    -4096, -2048, 0, 2048, 4096, 6144, 8192, 10240, 20480}
  },
  {
    {-11754, -11754, -10774, -4114, -1959, -196, 1567, 3918, 7836, 17631, 18022, 18022, 18022}, {-11754, -11754, -9795, 
    -1959, -784, 196, 784, 1175, 5877, 12537, 15672, 18022, 18022}, {-11754, -7836, -3918, -1959, -196, 0, 1175, 2938, 
    3526, 6269, 18022, 18022, 18022}, {-11754, -5877, -4506, 0, 196, 588, 784, 980, 2938, 5093, 7836, 18022, 18022}, {0, 
    0, 0, 392, 588, 588, 784, 2938, 3330, 4114, 5877, 5877, 5877}, {0, 784, 784, 784, 784, 784, 784, 2547, 2938, 3526, 
    5877, 5877, 5877}, {0, 784, 784, 784, 784, 784, 784, 2547, 2938, 3526, 5877, 5877, 5877}, {0, 784, 784, 784, 784, 
    784, 784, 2547, 2938, 3526, 5877, 5877, 5877}, {0, 784, 784, 784, 784, 784, 784, 2547, 2938, 3526, 5877, 5877, 5877}, 
    {0, 784, 784, 784, 784, 784, 784, 2547, 2938, 3526, 5877, 5877, 5877}
  },
  {
    0U, 640U, 3840U, 7680U, 10240U, 12800U, 15360U, 19200U, 23040U, 25600U
  },
  {
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F
  },
  {
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F
  }
};
CONST(Rte_Calprm_CalRegn01Inin03GroupD_DEFAULT_RTE_CALPRM_GROUP_Type, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_CalprmRom_CalRegn01Inin03GroupD_DEFAULT_RTE_CALPRM_GROUP = { /* PRQA S 3408 */ /* MD_Rte_3408 */
  0.0F,
  0.5F,
  30.0F,
  5.0F,
  30.0F,
  0.02F,
  0.29F,
  3.0F,
  1.0F,
  1.0F,
  90.0F,
  20.0F,
  20.0F,
  1.0F,
  -4500.0F,
  1.0F,
  10.0F,
  0.001F,
  20.0F,
  FALSE,
  FALSE,
  {
    0U, 640U, 1280U, 2560U
  },
  {
    0U, 640U, 1280U, 1920U, 2560U
  },
  {
    {0U, 480U, 960U, 1440U}, {0U, 480U, 960U, 1440U}, {0U, 480U, 960U, 1440U}, {0U, 480U, 960U, 1440U}, {0U, 480U, 960U, 
    1440U}
  },
  {
    {0U, 10813U, 21627U, 32768U}, {0U, 10813U, 21627U, 32768U}, {0U, 10813U, 21627U, 32768U}, {0U, 10813U, 21627U, 32768U
    }, {0U, 10813U, 21627U, 32768U}
  },
  {
    {0U, 262U}, {0U, 262U}, {0U, 262U}, {0U, 262U}
  },
  {
    {1920U, 0U}, {1920U, 0U}, {1920U, 0U}, {1920U, 0U}
  },
  {
    0U, 4096U
  },
  {
    {0U, 9830U, 22938U, 32768U}, {0U, 9830U, 22938U, 32768U}, {0U, 9830U, 22938U, 32768U}, {0U, 9830U, 22938U, 32768U}, {
    0U, 9830U, 22938U, 32768U}
  },
  {
    800U, 400U
  },
  {
    10400U, 10400U
  },
  {
    {0U, 262U}, {0U, 262U}, {0U, 262U}, {0U, 262U}
  },
  {
    0U, 2048U, 4096U, 6144U, 8192U, 10240U, 12288U, 14336U, 16384U, 18432U
  },
  {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  },
  {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  },
  {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  },
  {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  },
  {
    384U, 384U, 384U, 384U, 384U, 384U, 384U, 384U, 384U, 384U, 384U, 384U
  },
  {
    0U, 640U, 1088U, 1120U, 1152U, 1184U
  },
  {
    36000U, 36000U, 36000U, 36000U, 36000U, 36000U
  },
  {
    8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U
  },
  {
    8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U
  },
  {
    32768U, 32768U, 9830U, 6554U, 3277U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  },
  {
    208U, 432U, 640U, 848U, 1056U
  },
  {
    0U, 0U, 0U, 0U, 0U
  },
  {
    0U, 4096U
  },
  {
    32768U, 0U
  },
  {
    1005U, 1100U
  },
  {
    32768U, 32768U
  },
  {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  },
  {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  },
  {
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F
  }
};
CONST(Rte_Calprm_CalRegn01Inin03_DEFAULT_RTE_CALPRM_GROUP_Type, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_CalprmRom_CalRegn01Inin03_DEFAULT_RTE_CALPRM_GROUP = { /* PRQA S 3408 */ /* MD_Rte_3408 */
  2100.0F,
  500.0F,
  1.0F,
  20.0F,
  3.0F,
  0.1F,
  0.0F,
  30.0F,
  1.0F,
  -1.0F,
  0.8F,
  15.0F,
  0.0F,
  1.0F,
  -1.0F,
  4.0F,
  0.2F,
  30.0F,
  0.98F,
  360.0F,
  180.0F,
  10.0F,
  3.0F,
  3.0F,
  10.0F,
  0.0F,
  100.0F,
  0.0F,
  22.0F,
  1U,
  656U,
  656U,
  65534U,
  {
    0, 20, 40, 60, 80, 100, 120, 140, 160, 180
  },
  {
    0U, 3641U, 7281U, 10922U, 14562U, 18206U, 21846U, 25487U, 29127U, 32768U
  },
  {
    0.0F, 0.0F, 0.0F, 0.0F
  },
  {
    {0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 
    0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F}
  },
  {
    {0U, 0U, 0U}, {0U, 0U, 0U}, {0U, 0U, 0U}, {0U, 0U, 0U}, {0U, 0U, 0U}, {0U, 0U, 0U}, {0U, 0U, 0U}, {0U, 0U, 0U}
  },
  {
    1.0F, 1.0F, 1.0F, 1.0F
  },
  {
    -15.0F, -5.0F, 5.0F, 15.0F
  },
  {
    0U, 960U, 1920U, 2880U, 3840U, 5760U, 8640U, 11520U, 14400U, 17280U
  },
  {
    24269U, 24269U, 24269U, 24269U, 24269U, 24269U, 24269U, 24269U, 24269U, 24269U
  },
  {
    TRUE, TRUE, TRUE, TRUE
  },
  {
    {0.0F, 5.0F}, {60.0F, 80.0F}, {80.0F, 100.0F}, {100.0F, 120.0F}
  },
  {
    0U, 640U, 1920U, 3840U, 7680U, 10240U, 12800U, 15360U, 19200U, 23040U, 25600U, 28160U
  },
  {
    1233U, 1237U, 1241U, 1245U, 1249U, 1253U, 1257U, 1262U, 1262U, 1262U, 1262U, 1262U, 1262U, 1262U, 1257U, 1253U, 
    1249U, 1245U, 1241U, 1237U, 1233U
  },
  {
    17592U, 17592U, 17592U, 17285U, 16589U, 15770U, 14930U, 14213U, 13926U, 13681U, 13681U, 13681U, 13926U, 14213U, 
    14930U, 15770U, 16589U, 17285U, 17592U, 17592U, 17592U
  },
  {
    29491U, 29655U, 29819U, 29983U, 30147U, 30147U, 30147U, 30147U, 30147U, 30147U, 30147U, 30147U, 30147U, 30147U, 
    30147U, 30147U, 30147U, 29983U, 29819U, 29655U, 29491U
  },
  {
    -5939, -5300, -4678, -4063, -3465, -2867, -2277, -1704, -1139, -565, 0, 565, 1139, 1704, 2277, 2867, 3465, 4063, 
    4678, 5300, 5939
  },
  {
    4522U, 4555U, 4588U, 4620U, 4653U, 4686U, 4719U, 4719U, 4719U, 4719U, 4719U, 4719U, 4719U, 4719U, 4719U, 4686U, 
    4653U, 4620U, 4588U, 4555U, 4522U
  },
  {
    0U, 12800U, 25600U, 38400U, 51200U, 65408U
  }
};
CONST(Rte_Calprm_CalRegn01Inin04GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_CalprmRom_CalRegn01Inin04GroupA_DEFAULT_RTE_CALPRM_GROUP = { /* PRQA S 3408 */ /* MD_Rte_3408 */
  -360.0F,
  -900.0F,
  900.0F,
  360.0F,
  1.0F,
  45.0F,
  45.0F,
  45.0F,
  45.0F,
  3.0F,
  1.0F,
  1.0F,
  0.5F,
  0.5F,
  0.5F,
  1.0F,
  45.0F,
  2.8F,
  10.0F,
  0.5F,
  2.0F,
  160.0F,
  60.0F,
  1.0F,
  1.0F,
  0.1F,
  100.0F,
  1.0F,
  0.0F,
  3.0F,
  0.25F,
  3.0F,
  1.0F,
  TRUE,
  TRUE,
  {
    {1.0F, 0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 1.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 1.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 
    1.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F, 1.0F}
  },
  {
    {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}
  },
  {
    {1.0F, 0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 1.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 1.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 
    1.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F, 1.0F}
  },
  {
    {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}
  },
  {
    0, 0, 0, 0
  },
  {
    0, 0, 0, 0
  },
  {
    0, 0, 0, 0
  },
  {
    0, 0, 0, 0
  },
  {
    0, 0, 0, 0
  },
  {
    0, 0, 0, 0
  },
  {
    0U, 1280U, 2560U, 25600U
  },
  {
    0U, 26U, 51U, 77U, 128U, 256U, 512U, 768U, 1024U, 2560U
  },
  {
    0U, 164U, 328U, 819U, 1638U, 3277U, 8192U, 11469U, 16384U, 16384U
  },
  {
    960U, 960U, 800U, 640U, 480U, 320U, 320U, 160U, 160U, 160U, 160U, 160U
  },
  {
    0U, 3840U, 7680U, 11520U
  },
  {
    0U, 4096U, 16384U, 16384U
  }
};
CONST(Rte_Calprm_CalRegn01Inin04GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_CalprmRom_CalRegn01Inin04GroupC_DEFAULT_RTE_CALPRM_GROUP = { /* PRQA S 3408 */ /* MD_Rte_3408 */
  20.0F,
  20.0F,
  500.0F,
  -500.0F,
  0.0F,
  0.0F,
  0.04F,
  17.0F,
  20.0F,
  {
    {2048U, 5120U, 5120U, 10240U, 10240U, 15360U, 15360U, 20480U, 20480U}, {2048U, 5120U, 5120U, 10240U, 10240U, 15360U, 
    15360U, 20480U, 20480U}, {2048U, 5120U, 5120U, 10240U, 10240U, 10240U, 15360U, 15360U, 15360U}, {2048U, 5120U, 5120U, 
    10240U, 10240U, 10240U, 10240U, 10240U, 10240U}, {2048U, 5120U, 5120U, 10240U, 10240U, 10240U, 10240U, 10240U, 10240U}
  },
  {
    {0U, 4U, 508U, 608U, 712U, 816U, 916U, 1020U, 1124U, 1228U, 1328U, 1432U, 1536U, 1636U, 1740U, 1844U, 1944U, 2048U, 
    6920U, 10240U}, {0U, 204U, 716U, 792U, 868U, 944U, 1016U, 1092U, 1168U, 1244U, 1316U, 1392U, 1468U, 1544U, 1616U, 
    1692U, 1768U, 1844U, 9348U, 10240U}, {0U, 308U, 820U, 908U, 1000U, 1088U, 1176U, 1268U, 1356U, 1448U, 1536U, 1624U, 
    1716U, 1804U, 1896U, 1984U, 2072U, 2164U, 2252U, 10240U}, {0U, 192U, 1024U, 1164U, 1304U, 1448U, 1588U, 1728U, 1868U, 
    2008U, 2152U, 2292U, 2432U, 2572U, 2712U, 2856U, 2996U, 3136U, 3276U, 10240U}, {0U, 176U, 836U, 1048U, 1260U, 1472U, 
    1684U, 1896U, 2108U, 2320U, 2532U, 2744U, 2956U, 3168U, 3380U, 3592U, 3804U, 4016U, 4228U, 10240U}, {0U, 192U, 916U, 
    1148U, 1376U, 1608U, 1840U, 2072U, 2304U, 2536U, 2768U, 3000U, 3232U, 3464U, 3692U, 3924U, 4156U, 4388U, 4620U, 10240U
    }, {0U, 204U, 972U, 1220U, 1464U, 1712U, 1960U, 2204U, 2452U, 2696U, 2944U, 3192U, 3436U, 3684U, 3928U, 4176U, 4424U, 
    4668U, 4916U, 10240U}, {0U, 216U, 1020U, 1280U, 1540U, 1796U, 2056U, 2316U, 2572U, 2832U, 3092U, 3348U, 3608U, 3868U, 
    4128U, 4384U, 4644U, 4904U, 5160U, 10240U}, {0U, 244U, 1168U, 1464U, 1760U, 2056U, 2352U, 2644U, 2940U, 3236U, 3532U, 
    3828U, 4124U, 4420U, 4716U, 5012U, 5308U, 5604U, 5900U, 10240U}, {0U, 308U, 1460U, 1828U, 2200U, 2568U, 2936U, 3308U, 
    3676U, 4048U, 4416U, 4784U, 5156U, 5524U, 5896U, 6264U, 6632U, 7004U, 7372U, 10240U}, {0U, 4U, 1892U, 2140U, 2596U, 
    2880U, 3396U, 3640U, 4436U, 4676U, 5200U, 5712U, 6220U, 6748U, 7268U, 7512U, 8024U, 8552U, 8800U, 10240U}, {0U, 4U, 
    1892U, 2140U, 2596U, 2880U, 3396U, 3640U, 4436U, 4676U, 5200U, 5712U, 6220U, 6748U, 7268U, 7512U, 8024U, 8552U, 
    8800U, 10240U}
  },
  {
    {0U, 0U, 40U, 58U, 98U, 159U, 242U, 343U, 470U, 615U, 782U, 972U, 1182U, 1411U, 1663U, 1937U, 2232U, 2546U, 18022U, 
    18022U}, {0U, 0U, 41U, 52U, 73U, 107U, 150U, 205U, 270U, 346U, 432U, 530U, 637U, 756U, 885U, 1025U, 1176U, 1338U, 
    18022U, 18022U}, {0U, 0U, 29U, 37U, 55U, 86U, 122U, 171U, 229U, 294U, 372U, 458U, 551U, 655U, 770U, 894U, 1027U, 
    1169U, 1321U, 15274U}, {0U, 0U, 41U, 55U, 79U, 121U, 171U, 239U, 317U, 409U, 513U, 630U, 759U, 904U, 1059U, 1230U, 
    1413U, 1607U, 1815U, 12432U}, {0U, 0U, 49U, 73U, 113U, 171U, 245U, 340U, 447U, 574U, 716U, 879U, 1053U, 1249U, 1460U, 
    1688U, 1933U, 2196U, 2473U, 10636U}, {0U, 0U, 49U, 73U, 113U, 171U, 245U, 340U, 447U, 574U, 716U, 879U, 1053U, 1249U, 
    1460U, 1688U, 1933U, 2196U, 2473U, 9452U}, {0U, 0U, 49U, 73U, 113U, 171U, 245U, 340U, 447U, 574U, 716U, 879U, 1053U, 
    1249U, 1460U, 1688U, 1933U, 2196U, 2473U, 8691U}, {0U, 0U, 49U, 73U, 113U, 171U, 245U, 340U, 447U, 574U, 716U, 879U, 
    1053U, 1249U, 1460U, 1688U, 1933U, 2196U, 2473U, 8122U}, {0U, 0U, 49U, 73U, 113U, 171U, 245U, 340U, 447U, 574U, 716U, 
    879U, 1053U, 1249U, 1460U, 1688U, 1933U, 2196U, 2473U, 6697U}, {0U, 0U, 49U, 73U, 113U, 171U, 245U, 340U, 447U, 574U, 
    716U, 879U, 1053U, 1249U, 1460U, 1688U, 1933U, 2196U, 2473U, 4706U}, {0U, 0U, 66U, 84U, 131U, 168U, 254U, 300U, 488U, 
    554U, 713U, 892U, 1090U, 1315U, 1559U, 1681U, 1953U, 2253U, 2404U, 3267U}, {0U, 0U, 66U, 84U, 131U, 168U, 254U, 300U, 
    488U, 554U, 713U, 892U, 1090U, 1315U, 1559U, 1681U, 1953U, 2253U, 2404U, 3267U}
  },
  {
    {-20480, -10240, -8192, -6144, -4096, -2048, 0, 2048, 4096, 6144, 8192, 10240, 20480}, {-20480, -10240, -8192, -6144, 
    -4096, -2048, 0, 2048, 4096, 6144, 8192, 10240, 20480}, {-20480, -10240, -8192, -6144, -4096, -2048, 0, 2048, 4096, 
    6144, 8192, 10240, 20480}, {-20480, -10240, -8192, -6144, -4096, -2048, 0, 2048, 4096, 6144, 8192, 10240, 20480}, {
    -20480, -10240, -8192, -6144, -4096, -2048, 0, 2048, 4096, 6144, 8192, 10240, 20480}, {-20480, -10240, -8192, -6144, 
    -4096, -2048, 0, 2048, 4096, 6144, 8192, 10240, 20480}, {-20480, -10240, -8192, -6144, -4096, -2048, 0, 2048, 4096, 
    6144, 8192, 10240, 20480}, {-20480, -10240, -8192, -6144, -4096, -2048, 0, 2048, 4096, 6144, 8192, 10240, 20480}, {
    -20480, -10240, -8192, -6144, -4096, -2048, 0, 2048, 4096, 6144, 8192, 10240, 20480}, {-20480, -10240, -8192, -6144, 
    -4096, -2048, 0, 2048, 4096, 6144, 8192, 10240, 20480}
  },
  {
    {-11754, -11754, -10774, -4114, -1959, -196, 1567, 3918, 7836, 17631, 18022, 18022, 18022}, {-11754, -11754, -9795, 
    -1959, -784, 196, 784, 1175, 5877, 12537, 15672, 18022, 18022}, {-11754, -7836, -3918, -1959, -196, 0, 1175, 2938, 
    3526, 6269, 18022, 18022, 18022}, {-11754, -5877, -4506, 0, 196, 588, 784, 980, 2938, 5093, 7836, 18022, 18022}, {0, 
    0, 0, 392, 588, 588, 784, 2938, 3330, 4114, 5877, 5877, 5877}, {0, 784, 784, 784, 784, 784, 784, 2547, 2938, 3526, 
    5877, 5877, 5877}, {0, 784, 784, 784, 784, 784, 784, 2547, 2938, 3526, 5877, 5877, 5877}, {0, 784, 784, 784, 784, 
    784, 784, 2547, 2938, 3526, 5877, 5877, 5877}, {0, 784, 784, 784, 784, 784, 784, 2547, 2938, 3526, 5877, 5877, 5877}, 
    {0, 784, 784, 784, 784, 784, 784, 2547, 2938, 3526, 5877, 5877, 5877}
  },
  {
    0U, 640U, 3840U, 7680U, 10240U, 12800U, 15360U, 19200U, 23040U, 25600U
  },
  {
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F
  },
  {
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F
  }
};
CONST(Rte_Calprm_CalRegn01Inin04GroupD_DEFAULT_RTE_CALPRM_GROUP_Type, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_CalprmRom_CalRegn01Inin04GroupD_DEFAULT_RTE_CALPRM_GROUP = { /* PRQA S 3408 */ /* MD_Rte_3408 */
  0.0F,
  0.5F,
  30.0F,
  5.0F,
  30.0F,
  0.02F,
  0.29F,
  3.0F,
  1.0F,
  1.0F,
  90.0F,
  20.0F,
  20.0F,
  1.0F,
  -4500.0F,
  1.0F,
  10.0F,
  0.001F,
  20.0F,
  FALSE,
  FALSE,
  {
    0U, 640U, 1280U, 2560U
  },
  {
    0U, 640U, 1280U, 1920U, 2560U
  },
  {
    {0U, 480U, 960U, 1440U}, {0U, 480U, 960U, 1440U}, {0U, 480U, 960U, 1440U}, {0U, 480U, 960U, 1440U}, {0U, 480U, 960U, 
    1440U}
  },
  {
    {0U, 10813U, 21627U, 32768U}, {0U, 10813U, 21627U, 32768U}, {0U, 10813U, 21627U, 32768U}, {0U, 10813U, 21627U, 32768U
    }, {0U, 10813U, 21627U, 32768U}
  },
  {
    {0U, 262U}, {0U, 262U}, {0U, 262U}, {0U, 262U}
  },
  {
    {1920U, 0U}, {1920U, 0U}, {1920U, 0U}, {1920U, 0U}
  },
  {
    0U, 4096U
  },
  {
    {0U, 9830U, 22938U, 32768U}, {0U, 9830U, 22938U, 32768U}, {0U, 9830U, 22938U, 32768U}, {0U, 9830U, 22938U, 32768U}, {
    0U, 9830U, 22938U, 32768U}
  },
  {
    800U, 400U
  },
  {
    10400U, 10400U
  },
  {
    {0U, 262U}, {0U, 262U}, {0U, 262U}, {0U, 262U}
  },
  {
    0U, 2048U, 4096U, 6144U, 8192U, 10240U, 12288U, 14336U, 16384U, 18432U
  },
  {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  },
  {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  },
  {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  },
  {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  },
  {
    384U, 384U, 384U, 384U, 384U, 384U, 384U, 384U, 384U, 384U, 384U, 384U
  },
  {
    0U, 640U, 1088U, 1120U, 1152U, 1184U
  },
  {
    36000U, 36000U, 36000U, 36000U, 36000U, 36000U
  },
  {
    8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U
  },
  {
    8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U
  },
  {
    32768U, 32768U, 9830U, 6554U, 3277U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  },
  {
    208U, 432U, 640U, 848U, 1056U
  },
  {
    0U, 0U, 0U, 0U, 0U
  },
  {
    0U, 4096U
  },
  {
    32768U, 0U
  },
  {
    1005U, 1100U
  },
  {
    32768U, 32768U
  },
  {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  },
  {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  },
  {
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F
  }
};
CONST(Rte_Calprm_CalRegn01Inin04_DEFAULT_RTE_CALPRM_GROUP_Type, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_CalprmRom_CalRegn01Inin04_DEFAULT_RTE_CALPRM_GROUP = { /* PRQA S 3408 */ /* MD_Rte_3408 */
  2100.0F,
  500.0F,
  1.0F,
  20.0F,
  3.0F,
  0.1F,
  0.0F,
  30.0F,
  1.0F,
  -1.0F,
  0.8F,
  15.0F,
  0.0F,
  1.0F,
  -1.0F,
  4.0F,
  0.2F,
  30.0F,
  0.98F,
  360.0F,
  180.0F,
  10.0F,
  3.0F,
  3.0F,
  10.0F,
  0.0F,
  100.0F,
  0.0F,
  22.0F,
  1U,
  656U,
  656U,
  65534U,
  {
    0, 20, 40, 60, 80, 100, 120, 140, 160, 180
  },
  {
    0U, 3641U, 7281U, 10922U, 14562U, 18206U, 21846U, 25487U, 29127U, 32768U
  },
  {
    0.0F, 0.0F, 0.0F, 0.0F
  },
  {
    {0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 
    0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F}
  },
  {
    {0U, 0U, 0U}, {0U, 0U, 0U}, {0U, 0U, 0U}, {0U, 0U, 0U}, {0U, 0U, 0U}, {0U, 0U, 0U}, {0U, 0U, 0U}, {0U, 0U, 0U}
  },
  {
    1.0F, 1.0F, 1.0F, 1.0F
  },
  {
    -15.0F, -5.0F, 5.0F, 15.0F
  },
  {
    0U, 960U, 1920U, 2880U, 3840U, 5760U, 8640U, 11520U, 14400U, 17280U
  },
  {
    24269U, 24269U, 24269U, 24269U, 24269U, 24269U, 24269U, 24269U, 24269U, 24269U
  },
  {
    TRUE, TRUE, TRUE, TRUE
  },
  {
    {0.0F, 5.0F}, {60.0F, 80.0F}, {80.0F, 100.0F}, {100.0F, 120.0F}
  },
  {
    0U, 640U, 1920U, 3840U, 7680U, 10240U, 12800U, 15360U, 19200U, 23040U, 25600U, 28160U
  },
  {
    1233U, 1237U, 1241U, 1245U, 1249U, 1253U, 1257U, 1262U, 1262U, 1262U, 1262U, 1262U, 1262U, 1262U, 1257U, 1253U, 
    1249U, 1245U, 1241U, 1237U, 1233U
  },
  {
    17592U, 17592U, 17592U, 17285U, 16589U, 15770U, 14930U, 14213U, 13926U, 13681U, 13681U, 13681U, 13926U, 14213U, 
    14930U, 15770U, 16589U, 17285U, 17592U, 17592U, 17592U
  },
  {
    29491U, 29655U, 29819U, 29983U, 30147U, 30147U, 30147U, 30147U, 30147U, 30147U, 30147U, 30147U, 30147U, 30147U, 
    30147U, 30147U, 30147U, 29983U, 29819U, 29655U, 29491U
  },
  {
    -5939, -5300, -4678, -4063, -3465, -2867, -2277, -1704, -1139, -565, 0, 565, 1139, 1704, 2277, 2867, 3465, 4063, 
    4678, 5300, 5939
  },
  {
    4522U, 4555U, 4588U, 4620U, 4653U, 4686U, 4719U, 4719U, 4719U, 4719U, 4719U, 4719U, 4719U, 4719U, 4719U, 4686U, 
    4653U, 4620U, 4588U, 4555U, 4522U
  },
  {
    0U, 12800U, 25600U, 38400U, 51200U, 65408U
  }
};
CONST(Rte_Calprm_CalRegn01Inin05GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_CalprmRom_CalRegn01Inin05GroupA_DEFAULT_RTE_CALPRM_GROUP = { /* PRQA S 3408 */ /* MD_Rte_3408 */
  -360.0F,
  -900.0F,
  900.0F,
  360.0F,
  1.0F,
  45.0F,
  45.0F,
  45.0F,
  45.0F,
  3.0F,
  1.0F,
  1.0F,
  0.5F,
  0.5F,
  0.5F,
  1.0F,
  45.0F,
  2.8F,
  10.0F,
  0.5F,
  2.0F,
  160.0F,
  60.0F,
  1.0F,
  1.0F,
  0.1F,
  100.0F,
  1.0F,
  0.0F,
  3.0F,
  0.25F,
  3.0F,
  1.0F,
  TRUE,
  TRUE,
  {
    {1.0F, 0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 1.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 1.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 
    1.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F, 1.0F}
  },
  {
    {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}
  },
  {
    {1.0F, 0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 1.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 1.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 
    1.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F, 1.0F}
  },
  {
    {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}
  },
  {
    0, 0, 0, 0
  },
  {
    0, 0, 0, 0
  },
  {
    0, 0, 0, 0
  },
  {
    0, 0, 0, 0
  },
  {
    0, 0, 0, 0
  },
  {
    0, 0, 0, 0
  },
  {
    0U, 1280U, 2560U, 25600U
  },
  {
    0U, 26U, 51U, 77U, 128U, 256U, 512U, 768U, 1024U, 2560U
  },
  {
    0U, 164U, 328U, 819U, 1638U, 3277U, 8192U, 11469U, 16384U, 16384U
  },
  {
    960U, 960U, 800U, 640U, 480U, 320U, 320U, 160U, 160U, 160U, 160U, 160U
  },
  {
    0U, 3840U, 7680U, 11520U
  },
  {
    0U, 4096U, 16384U, 16384U
  }
};
CONST(Rte_Calprm_CalRegn01Inin05GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_CalprmRom_CalRegn01Inin05GroupC_DEFAULT_RTE_CALPRM_GROUP = { /* PRQA S 3408 */ /* MD_Rte_3408 */
  20.0F,
  20.0F,
  500.0F,
  -500.0F,
  0.0F,
  0.0F,
  0.04F,
  17.0F,
  20.0F,
  {
    {2048U, 5120U, 5120U, 10240U, 10240U, 15360U, 15360U, 20480U, 20480U}, {2048U, 5120U, 5120U, 10240U, 10240U, 15360U, 
    15360U, 20480U, 20480U}, {2048U, 5120U, 5120U, 10240U, 10240U, 10240U, 15360U, 15360U, 15360U}, {2048U, 5120U, 5120U, 
    10240U, 10240U, 10240U, 10240U, 10240U, 10240U}, {2048U, 5120U, 5120U, 10240U, 10240U, 10240U, 10240U, 10240U, 10240U}
  },
  {
    {0U, 4U, 508U, 608U, 712U, 816U, 916U, 1020U, 1124U, 1228U, 1328U, 1432U, 1536U, 1636U, 1740U, 1844U, 1944U, 2048U, 
    6920U, 10240U}, {0U, 204U, 716U, 792U, 868U, 944U, 1016U, 1092U, 1168U, 1244U, 1316U, 1392U, 1468U, 1544U, 1616U, 
    1692U, 1768U, 1844U, 9348U, 10240U}, {0U, 308U, 820U, 908U, 1000U, 1088U, 1176U, 1268U, 1356U, 1448U, 1536U, 1624U, 
    1716U, 1804U, 1896U, 1984U, 2072U, 2164U, 2252U, 10240U}, {0U, 192U, 1024U, 1164U, 1304U, 1448U, 1588U, 1728U, 1868U, 
    2008U, 2152U, 2292U, 2432U, 2572U, 2712U, 2856U, 2996U, 3136U, 3276U, 10240U}, {0U, 176U, 836U, 1048U, 1260U, 1472U, 
    1684U, 1896U, 2108U, 2320U, 2532U, 2744U, 2956U, 3168U, 3380U, 3592U, 3804U, 4016U, 4228U, 10240U}, {0U, 192U, 916U, 
    1148U, 1376U, 1608U, 1840U, 2072U, 2304U, 2536U, 2768U, 3000U, 3232U, 3464U, 3692U, 3924U, 4156U, 4388U, 4620U, 10240U
    }, {0U, 204U, 972U, 1220U, 1464U, 1712U, 1960U, 2204U, 2452U, 2696U, 2944U, 3192U, 3436U, 3684U, 3928U, 4176U, 4424U, 
    4668U, 4916U, 10240U}, {0U, 216U, 1020U, 1280U, 1540U, 1796U, 2056U, 2316U, 2572U, 2832U, 3092U, 3348U, 3608U, 3868U, 
    4128U, 4384U, 4644U, 4904U, 5160U, 10240U}, {0U, 244U, 1168U, 1464U, 1760U, 2056U, 2352U, 2644U, 2940U, 3236U, 3532U, 
    3828U, 4124U, 4420U, 4716U, 5012U, 5308U, 5604U, 5900U, 10240U}, {0U, 308U, 1460U, 1828U, 2200U, 2568U, 2936U, 3308U, 
    3676U, 4048U, 4416U, 4784U, 5156U, 5524U, 5896U, 6264U, 6632U, 7004U, 7372U, 10240U}, {0U, 4U, 1892U, 2140U, 2596U, 
    2880U, 3396U, 3640U, 4436U, 4676U, 5200U, 5712U, 6220U, 6748U, 7268U, 7512U, 8024U, 8552U, 8800U, 10240U}, {0U, 4U, 
    1892U, 2140U, 2596U, 2880U, 3396U, 3640U, 4436U, 4676U, 5200U, 5712U, 6220U, 6748U, 7268U, 7512U, 8024U, 8552U, 
    8800U, 10240U}
  },
  {
    {0U, 0U, 40U, 58U, 98U, 159U, 242U, 343U, 470U, 615U, 782U, 972U, 1182U, 1411U, 1663U, 1937U, 2232U, 2546U, 18022U, 
    18022U}, {0U, 0U, 41U, 52U, 73U, 107U, 150U, 205U, 270U, 346U, 432U, 530U, 637U, 756U, 885U, 1025U, 1176U, 1338U, 
    18022U, 18022U}, {0U, 0U, 29U, 37U, 55U, 86U, 122U, 171U, 229U, 294U, 372U, 458U, 551U, 655U, 770U, 894U, 1027U, 
    1169U, 1321U, 15274U}, {0U, 0U, 41U, 55U, 79U, 121U, 171U, 239U, 317U, 409U, 513U, 630U, 759U, 904U, 1059U, 1230U, 
    1413U, 1607U, 1815U, 12432U}, {0U, 0U, 49U, 73U, 113U, 171U, 245U, 340U, 447U, 574U, 716U, 879U, 1053U, 1249U, 1460U, 
    1688U, 1933U, 2196U, 2473U, 10636U}, {0U, 0U, 49U, 73U, 113U, 171U, 245U, 340U, 447U, 574U, 716U, 879U, 1053U, 1249U, 
    1460U, 1688U, 1933U, 2196U, 2473U, 9452U}, {0U, 0U, 49U, 73U, 113U, 171U, 245U, 340U, 447U, 574U, 716U, 879U, 1053U, 
    1249U, 1460U, 1688U, 1933U, 2196U, 2473U, 8691U}, {0U, 0U, 49U, 73U, 113U, 171U, 245U, 340U, 447U, 574U, 716U, 879U, 
    1053U, 1249U, 1460U, 1688U, 1933U, 2196U, 2473U, 8122U}, {0U, 0U, 49U, 73U, 113U, 171U, 245U, 340U, 447U, 574U, 716U, 
    879U, 1053U, 1249U, 1460U, 1688U, 1933U, 2196U, 2473U, 6697U}, {0U, 0U, 49U, 73U, 113U, 171U, 245U, 340U, 447U, 574U, 
    716U, 879U, 1053U, 1249U, 1460U, 1688U, 1933U, 2196U, 2473U, 4706U}, {0U, 0U, 66U, 84U, 131U, 168U, 254U, 300U, 488U, 
    554U, 713U, 892U, 1090U, 1315U, 1559U, 1681U, 1953U, 2253U, 2404U, 3267U}, {0U, 0U, 66U, 84U, 131U, 168U, 254U, 300U, 
    488U, 554U, 713U, 892U, 1090U, 1315U, 1559U, 1681U, 1953U, 2253U, 2404U, 3267U}
  },
  {
    {-20480, -10240, -8192, -6144, -4096, -2048, 0, 2048, 4096, 6144, 8192, 10240, 20480}, {-20480, -10240, -8192, -6144, 
    -4096, -2048, 0, 2048, 4096, 6144, 8192, 10240, 20480}, {-20480, -10240, -8192, -6144, -4096, -2048, 0, 2048, 4096, 
    6144, 8192, 10240, 20480}, {-20480, -10240, -8192, -6144, -4096, -2048, 0, 2048, 4096, 6144, 8192, 10240, 20480}, {
    -20480, -10240, -8192, -6144, -4096, -2048, 0, 2048, 4096, 6144, 8192, 10240, 20480}, {-20480, -10240, -8192, -6144, 
    -4096, -2048, 0, 2048, 4096, 6144, 8192, 10240, 20480}, {-20480, -10240, -8192, -6144, -4096, -2048, 0, 2048, 4096, 
    6144, 8192, 10240, 20480}, {-20480, -10240, -8192, -6144, -4096, -2048, 0, 2048, 4096, 6144, 8192, 10240, 20480}, {
    -20480, -10240, -8192, -6144, -4096, -2048, 0, 2048, 4096, 6144, 8192, 10240, 20480}, {-20480, -10240, -8192, -6144, 
    -4096, -2048, 0, 2048, 4096, 6144, 8192, 10240, 20480}
  },
  {
    {-11754, -11754, -10774, -4114, -1959, -196, 1567, 3918, 7836, 17631, 18022, 18022, 18022}, {-11754, -11754, -9795, 
    -1959, -784, 196, 784, 1175, 5877, 12537, 15672, 18022, 18022}, {-11754, -7836, -3918, -1959, -196, 0, 1175, 2938, 
    3526, 6269, 18022, 18022, 18022}, {-11754, -5877, -4506, 0, 196, 588, 784, 980, 2938, 5093, 7836, 18022, 18022}, {0, 
    0, 0, 392, 588, 588, 784, 2938, 3330, 4114, 5877, 5877, 5877}, {0, 784, 784, 784, 784, 784, 784, 2547, 2938, 3526, 
    5877, 5877, 5877}, {0, 784, 784, 784, 784, 784, 784, 2547, 2938, 3526, 5877, 5877, 5877}, {0, 784, 784, 784, 784, 
    784, 784, 2547, 2938, 3526, 5877, 5877, 5877}, {0, 784, 784, 784, 784, 784, 784, 2547, 2938, 3526, 5877, 5877, 5877}, 
    {0, 784, 784, 784, 784, 784, 784, 2547, 2938, 3526, 5877, 5877, 5877}
  },
  {
    0U, 640U, 3840U, 7680U, 10240U, 12800U, 15360U, 19200U, 23040U, 25600U
  },
  {
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F
  },
  {
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F
  }
};
CONST(Rte_Calprm_CalRegn01Inin05GroupD_DEFAULT_RTE_CALPRM_GROUP_Type, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_CalprmRom_CalRegn01Inin05GroupD_DEFAULT_RTE_CALPRM_GROUP = { /* PRQA S 3408 */ /* MD_Rte_3408 */
  0.0F,
  0.5F,
  30.0F,
  5.0F,
  30.0F,
  0.02F,
  0.29F,
  3.0F,
  1.0F,
  1.0F,
  90.0F,
  20.0F,
  20.0F,
  1.0F,
  -4500.0F,
  1.0F,
  10.0F,
  0.001F,
  20.0F,
  FALSE,
  FALSE,
  {
    0U, 640U, 1280U, 2560U
  },
  {
    0U, 640U, 1280U, 1920U, 2560U
  },
  {
    {0U, 480U, 960U, 1440U}, {0U, 480U, 960U, 1440U}, {0U, 480U, 960U, 1440U}, {0U, 480U, 960U, 1440U}, {0U, 480U, 960U, 
    1440U}
  },
  {
    {0U, 10813U, 21627U, 32768U}, {0U, 10813U, 21627U, 32768U}, {0U, 10813U, 21627U, 32768U}, {0U, 10813U, 21627U, 32768U
    }, {0U, 10813U, 21627U, 32768U}
  },
  {
    {0U, 262U}, {0U, 262U}, {0U, 262U}, {0U, 262U}
  },
  {
    {1920U, 0U}, {1920U, 0U}, {1920U, 0U}, {1920U, 0U}
  },
  {
    0U, 4096U
  },
  {
    {0U, 9830U, 22938U, 32768U}, {0U, 9830U, 22938U, 32768U}, {0U, 9830U, 22938U, 32768U}, {0U, 9830U, 22938U, 32768U}, {
    0U, 9830U, 22938U, 32768U}
  },
  {
    800U, 400U
  },
  {
    10400U, 10400U
  },
  {
    {0U, 262U}, {0U, 262U}, {0U, 262U}, {0U, 262U}
  },
  {
    0U, 2048U, 4096U, 6144U, 8192U, 10240U, 12288U, 14336U, 16384U, 18432U
  },
  {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  },
  {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  },
  {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  },
  {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  },
  {
    384U, 384U, 384U, 384U, 384U, 384U, 384U, 384U, 384U, 384U, 384U, 384U
  },
  {
    0U, 640U, 1088U, 1120U, 1152U, 1184U
  },
  {
    36000U, 36000U, 36000U, 36000U, 36000U, 36000U
  },
  {
    8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U
  },
  {
    8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U
  },
  {
    32768U, 32768U, 9830U, 6554U, 3277U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  },
  {
    208U, 432U, 640U, 848U, 1056U
  },
  {
    0U, 0U, 0U, 0U, 0U
  },
  {
    0U, 4096U
  },
  {
    32768U, 0U
  },
  {
    1005U, 1100U
  },
  {
    32768U, 32768U
  },
  {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  },
  {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  },
  {
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F
  }
};
CONST(Rte_Calprm_CalRegn01Inin05_DEFAULT_RTE_CALPRM_GROUP_Type, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_CalprmRom_CalRegn01Inin05_DEFAULT_RTE_CALPRM_GROUP = { /* PRQA S 3408 */ /* MD_Rte_3408 */
  2100.0F,
  500.0F,
  1.0F,
  20.0F,
  3.0F,
  0.1F,
  0.0F,
  30.0F,
  1.0F,
  -1.0F,
  0.8F,
  15.0F,
  0.0F,
  1.0F,
  -1.0F,
  4.0F,
  0.2F,
  30.0F,
  0.98F,
  360.0F,
  180.0F,
  10.0F,
  3.0F,
  3.0F,
  10.0F,
  0.0F,
  100.0F,
  0.0F,
  22.0F,
  1U,
  656U,
  656U,
  65534U,
  {
    0, 20, 40, 60, 80, 100, 120, 140, 160, 180
  },
  {
    0U, 3641U, 7281U, 10922U, 14562U, 18206U, 21846U, 25487U, 29127U, 32768U
  },
  {
    0.0F, 0.0F, 0.0F, 0.0F
  },
  {
    {0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 
    0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F}
  },
  {
    {0U, 0U, 0U}, {0U, 0U, 0U}, {0U, 0U, 0U}, {0U, 0U, 0U}, {0U, 0U, 0U}, {0U, 0U, 0U}, {0U, 0U, 0U}, {0U, 0U, 0U}
  },
  {
    1.0F, 1.0F, 1.0F, 1.0F
  },
  {
    -15.0F, -5.0F, 5.0F, 15.0F
  },
  {
    0U, 960U, 1920U, 2880U, 3840U, 5760U, 8640U, 11520U, 14400U, 17280U
  },
  {
    24269U, 24269U, 24269U, 24269U, 24269U, 24269U, 24269U, 24269U, 24269U, 24269U
  },
  {
    TRUE, TRUE, TRUE, TRUE
  },
  {
    {0.0F, 5.0F}, {60.0F, 80.0F}, {80.0F, 100.0F}, {100.0F, 120.0F}
  },
  {
    0U, 640U, 1920U, 3840U, 7680U, 10240U, 12800U, 15360U, 19200U, 23040U, 25600U, 28160U
  },
  {
    1233U, 1237U, 1241U, 1245U, 1249U, 1253U, 1257U, 1262U, 1262U, 1262U, 1262U, 1262U, 1262U, 1262U, 1257U, 1253U, 
    1249U, 1245U, 1241U, 1237U, 1233U
  },
  {
    17592U, 17592U, 17592U, 17285U, 16589U, 15770U, 14930U, 14213U, 13926U, 13681U, 13681U, 13681U, 13926U, 14213U, 
    14930U, 15770U, 16589U, 17285U, 17592U, 17592U, 17592U
  },
  {
    29491U, 29655U, 29819U, 29983U, 30147U, 30147U, 30147U, 30147U, 30147U, 30147U, 30147U, 30147U, 30147U, 30147U, 
    30147U, 30147U, 30147U, 29983U, 29819U, 29655U, 29491U
  },
  {
    -5939, -5300, -4678, -4063, -3465, -2867, -2277, -1704, -1139, -565, 0, 565, 1139, 1704, 2277, 2867, 3465, 4063, 
    4678, 5300, 5939
  },
  {
    4522U, 4555U, 4588U, 4620U, 4653U, 4686U, 4719U, 4719U, 4719U, 4719U, 4719U, 4719U, 4719U, 4719U, 4719U, 4686U, 
    4653U, 4620U, 4588U, 4555U, 4522U
  },
  {
    0U, 12800U, 25600U, 38400U, 51200U, 65408U
  }
};
CONST(Rte_Calprm_CalRegn01Inin06GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_CalprmRom_CalRegn01Inin06GroupA_DEFAULT_RTE_CALPRM_GROUP = { /* PRQA S 3408 */ /* MD_Rte_3408 */
  -360.0F,
  -900.0F,
  900.0F,
  360.0F,
  1.0F,
  45.0F,
  45.0F,
  45.0F,
  45.0F,
  3.0F,
  1.0F,
  1.0F,
  0.5F,
  0.5F,
  0.5F,
  1.0F,
  45.0F,
  2.8F,
  10.0F,
  0.5F,
  2.0F,
  160.0F,
  60.0F,
  1.0F,
  1.0F,
  0.1F,
  100.0F,
  1.0F,
  0.0F,
  3.0F,
  0.25F,
  3.0F,
  1.0F,
  TRUE,
  TRUE,
  {
    {1.0F, 0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 1.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 1.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 
    1.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F, 1.0F}
  },
  {
    {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}
  },
  {
    {1.0F, 0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 1.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 1.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 
    1.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F, 1.0F}
  },
  {
    {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}
  },
  {
    0, 0, 0, 0
  },
  {
    0, 0, 0, 0
  },
  {
    0, 0, 0, 0
  },
  {
    0, 0, 0, 0
  },
  {
    0, 0, 0, 0
  },
  {
    0, 0, 0, 0
  },
  {
    0U, 1280U, 2560U, 25600U
  },
  {
    0U, 26U, 51U, 77U, 128U, 256U, 512U, 768U, 1024U, 2560U
  },
  {
    0U, 164U, 328U, 819U, 1638U, 3277U, 8192U, 11469U, 16384U, 16384U
  },
  {
    960U, 960U, 800U, 640U, 480U, 320U, 320U, 160U, 160U, 160U, 160U, 160U
  },
  {
    0U, 3840U, 7680U, 11520U
  },
  {
    0U, 4096U, 16384U, 16384U
  }
};
CONST(Rte_Calprm_CalRegn01Inin06GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_CalprmRom_CalRegn01Inin06GroupC_DEFAULT_RTE_CALPRM_GROUP = { /* PRQA S 3408 */ /* MD_Rte_3408 */
  20.0F,
  20.0F,
  500.0F,
  -500.0F,
  0.0F,
  0.0F,
  0.04F,
  17.0F,
  20.0F,
  {
    {2048U, 5120U, 5120U, 10240U, 10240U, 15360U, 15360U, 20480U, 20480U}, {2048U, 5120U, 5120U, 10240U, 10240U, 15360U, 
    15360U, 20480U, 20480U}, {2048U, 5120U, 5120U, 10240U, 10240U, 10240U, 15360U, 15360U, 15360U}, {2048U, 5120U, 5120U, 
    10240U, 10240U, 10240U, 10240U, 10240U, 10240U}, {2048U, 5120U, 5120U, 10240U, 10240U, 10240U, 10240U, 10240U, 10240U}
  },
  {
    {0U, 4U, 508U, 608U, 712U, 816U, 916U, 1020U, 1124U, 1228U, 1328U, 1432U, 1536U, 1636U, 1740U, 1844U, 1944U, 2048U, 
    6920U, 10240U}, {0U, 204U, 716U, 792U, 868U, 944U, 1016U, 1092U, 1168U, 1244U, 1316U, 1392U, 1468U, 1544U, 1616U, 
    1692U, 1768U, 1844U, 9348U, 10240U}, {0U, 308U, 820U, 908U, 1000U, 1088U, 1176U, 1268U, 1356U, 1448U, 1536U, 1624U, 
    1716U, 1804U, 1896U, 1984U, 2072U, 2164U, 2252U, 10240U}, {0U, 192U, 1024U, 1164U, 1304U, 1448U, 1588U, 1728U, 1868U, 
    2008U, 2152U, 2292U, 2432U, 2572U, 2712U, 2856U, 2996U, 3136U, 3276U, 10240U}, {0U, 176U, 836U, 1048U, 1260U, 1472U, 
    1684U, 1896U, 2108U, 2320U, 2532U, 2744U, 2956U, 3168U, 3380U, 3592U, 3804U, 4016U, 4228U, 10240U}, {0U, 192U, 916U, 
    1148U, 1376U, 1608U, 1840U, 2072U, 2304U, 2536U, 2768U, 3000U, 3232U, 3464U, 3692U, 3924U, 4156U, 4388U, 4620U, 10240U
    }, {0U, 204U, 972U, 1220U, 1464U, 1712U, 1960U, 2204U, 2452U, 2696U, 2944U, 3192U, 3436U, 3684U, 3928U, 4176U, 4424U, 
    4668U, 4916U, 10240U}, {0U, 216U, 1020U, 1280U, 1540U, 1796U, 2056U, 2316U, 2572U, 2832U, 3092U, 3348U, 3608U, 3868U, 
    4128U, 4384U, 4644U, 4904U, 5160U, 10240U}, {0U, 244U, 1168U, 1464U, 1760U, 2056U, 2352U, 2644U, 2940U, 3236U, 3532U, 
    3828U, 4124U, 4420U, 4716U, 5012U, 5308U, 5604U, 5900U, 10240U}, {0U, 308U, 1460U, 1828U, 2200U, 2568U, 2936U, 3308U, 
    3676U, 4048U, 4416U, 4784U, 5156U, 5524U, 5896U, 6264U, 6632U, 7004U, 7372U, 10240U}, {0U, 4U, 1892U, 2140U, 2596U, 
    2880U, 3396U, 3640U, 4436U, 4676U, 5200U, 5712U, 6220U, 6748U, 7268U, 7512U, 8024U, 8552U, 8800U, 10240U}, {0U, 4U, 
    1892U, 2140U, 2596U, 2880U, 3396U, 3640U, 4436U, 4676U, 5200U, 5712U, 6220U, 6748U, 7268U, 7512U, 8024U, 8552U, 
    8800U, 10240U}
  },
  {
    {0U, 0U, 40U, 58U, 98U, 159U, 242U, 343U, 470U, 615U, 782U, 972U, 1182U, 1411U, 1663U, 1937U, 2232U, 2546U, 18022U, 
    18022U}, {0U, 0U, 41U, 52U, 73U, 107U, 150U, 205U, 270U, 346U, 432U, 530U, 637U, 756U, 885U, 1025U, 1176U, 1338U, 
    18022U, 18022U}, {0U, 0U, 29U, 37U, 55U, 86U, 122U, 171U, 229U, 294U, 372U, 458U, 551U, 655U, 770U, 894U, 1027U, 
    1169U, 1321U, 15274U}, {0U, 0U, 41U, 55U, 79U, 121U, 171U, 239U, 317U, 409U, 513U, 630U, 759U, 904U, 1059U, 1230U, 
    1413U, 1607U, 1815U, 12432U}, {0U, 0U, 49U, 73U, 113U, 171U, 245U, 340U, 447U, 574U, 716U, 879U, 1053U, 1249U, 1460U, 
    1688U, 1933U, 2196U, 2473U, 10636U}, {0U, 0U, 49U, 73U, 113U, 171U, 245U, 340U, 447U, 574U, 716U, 879U, 1053U, 1249U, 
    1460U, 1688U, 1933U, 2196U, 2473U, 9452U}, {0U, 0U, 49U, 73U, 113U, 171U, 245U, 340U, 447U, 574U, 716U, 879U, 1053U, 
    1249U, 1460U, 1688U, 1933U, 2196U, 2473U, 8691U}, {0U, 0U, 49U, 73U, 113U, 171U, 245U, 340U, 447U, 574U, 716U, 879U, 
    1053U, 1249U, 1460U, 1688U, 1933U, 2196U, 2473U, 8122U}, {0U, 0U, 49U, 73U, 113U, 171U, 245U, 340U, 447U, 574U, 716U, 
    879U, 1053U, 1249U, 1460U, 1688U, 1933U, 2196U, 2473U, 6697U}, {0U, 0U, 49U, 73U, 113U, 171U, 245U, 340U, 447U, 574U, 
    716U, 879U, 1053U, 1249U, 1460U, 1688U, 1933U, 2196U, 2473U, 4706U}, {0U, 0U, 66U, 84U, 131U, 168U, 254U, 300U, 488U, 
    554U, 713U, 892U, 1090U, 1315U, 1559U, 1681U, 1953U, 2253U, 2404U, 3267U}, {0U, 0U, 66U, 84U, 131U, 168U, 254U, 300U, 
    488U, 554U, 713U, 892U, 1090U, 1315U, 1559U, 1681U, 1953U, 2253U, 2404U, 3267U}
  },
  {
    {-20480, -10240, -8192, -6144, -4096, -2048, 0, 2048, 4096, 6144, 8192, 10240, 20480}, {-20480, -10240, -8192, -6144, 
    -4096, -2048, 0, 2048, 4096, 6144, 8192, 10240, 20480}, {-20480, -10240, -8192, -6144, -4096, -2048, 0, 2048, 4096, 
    6144, 8192, 10240, 20480}, {-20480, -10240, -8192, -6144, -4096, -2048, 0, 2048, 4096, 6144, 8192, 10240, 20480}, {
    -20480, -10240, -8192, -6144, -4096, -2048, 0, 2048, 4096, 6144, 8192, 10240, 20480}, {-20480, -10240, -8192, -6144, 
    -4096, -2048, 0, 2048, 4096, 6144, 8192, 10240, 20480}, {-20480, -10240, -8192, -6144, -4096, -2048, 0, 2048, 4096, 
    6144, 8192, 10240, 20480}, {-20480, -10240, -8192, -6144, -4096, -2048, 0, 2048, 4096, 6144, 8192, 10240, 20480}, {
    -20480, -10240, -8192, -6144, -4096, -2048, 0, 2048, 4096, 6144, 8192, 10240, 20480}, {-20480, -10240, -8192, -6144, 
    -4096, -2048, 0, 2048, 4096, 6144, 8192, 10240, 20480}
  },
  {
    {-11754, -11754, -10774, -4114, -1959, -196, 1567, 3918, 7836, 17631, 18022, 18022, 18022}, {-11754, -11754, -9795, 
    -1959, -784, 196, 784, 1175, 5877, 12537, 15672, 18022, 18022}, {-11754, -7836, -3918, -1959, -196, 0, 1175, 2938, 
    3526, 6269, 18022, 18022, 18022}, {-11754, -5877, -4506, 0, 196, 588, 784, 980, 2938, 5093, 7836, 18022, 18022}, {0, 
    0, 0, 392, 588, 588, 784, 2938, 3330, 4114, 5877, 5877, 5877}, {0, 784, 784, 784, 784, 784, 784, 2547, 2938, 3526, 
    5877, 5877, 5877}, {0, 784, 784, 784, 784, 784, 784, 2547, 2938, 3526, 5877, 5877, 5877}, {0, 784, 784, 784, 784, 
    784, 784, 2547, 2938, 3526, 5877, 5877, 5877}, {0, 784, 784, 784, 784, 784, 784, 2547, 2938, 3526, 5877, 5877, 5877}, 
    {0, 784, 784, 784, 784, 784, 784, 2547, 2938, 3526, 5877, 5877, 5877}
  },
  {
    0U, 640U, 3840U, 7680U, 10240U, 12800U, 15360U, 19200U, 23040U, 25600U
  },
  {
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F
  },
  {
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F
  }
};
CONST(Rte_Calprm_CalRegn01Inin06GroupD_DEFAULT_RTE_CALPRM_GROUP_Type, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_CalprmRom_CalRegn01Inin06GroupD_DEFAULT_RTE_CALPRM_GROUP = { /* PRQA S 3408 */ /* MD_Rte_3408 */
  0.0F,
  0.5F,
  30.0F,
  5.0F,
  30.0F,
  0.02F,
  0.29F,
  3.0F,
  1.0F,
  1.0F,
  90.0F,
  20.0F,
  20.0F,
  1.0F,
  -4500.0F,
  1.0F,
  10.0F,
  0.001F,
  20.0F,
  FALSE,
  FALSE,
  {
    0U, 640U, 1280U, 2560U
  },
  {
    0U, 640U, 1280U, 1920U, 2560U
  },
  {
    {0U, 480U, 960U, 1440U}, {0U, 480U, 960U, 1440U}, {0U, 480U, 960U, 1440U}, {0U, 480U, 960U, 1440U}, {0U, 480U, 960U, 
    1440U}
  },
  {
    {0U, 10813U, 21627U, 32768U}, {0U, 10813U, 21627U, 32768U}, {0U, 10813U, 21627U, 32768U}, {0U, 10813U, 21627U, 32768U
    }, {0U, 10813U, 21627U, 32768U}
  },
  {
    {0U, 262U}, {0U, 262U}, {0U, 262U}, {0U, 262U}
  },
  {
    {1920U, 0U}, {1920U, 0U}, {1920U, 0U}, {1920U, 0U}
  },
  {
    0U, 4096U
  },
  {
    {0U, 9830U, 22938U, 32768U}, {0U, 9830U, 22938U, 32768U}, {0U, 9830U, 22938U, 32768U}, {0U, 9830U, 22938U, 32768U}, {
    0U, 9830U, 22938U, 32768U}
  },
  {
    800U, 400U
  },
  {
    10400U, 10400U
  },
  {
    {0U, 262U}, {0U, 262U}, {0U, 262U}, {0U, 262U}
  },
  {
    0U, 2048U, 4096U, 6144U, 8192U, 10240U, 12288U, 14336U, 16384U, 18432U
  },
  {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  },
  {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  },
  {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  },
  {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  },
  {
    384U, 384U, 384U, 384U, 384U, 384U, 384U, 384U, 384U, 384U, 384U, 384U
  },
  {
    0U, 640U, 1088U, 1120U, 1152U, 1184U
  },
  {
    36000U, 36000U, 36000U, 36000U, 36000U, 36000U
  },
  {
    8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U
  },
  {
    8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U, 8192U
  },
  {
    32768U, 32768U, 9830U, 6554U, 3277U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  },
  {
    208U, 432U, 640U, 848U, 1056U
  },
  {
    0U, 0U, 0U, 0U, 0U
  },
  {
    0U, 4096U
  },
  {
    32768U, 0U
  },
  {
    1005U, 1100U
  },
  {
    32768U, 32768U
  },
  {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  },
  {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  },
  {
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F
  }
};
CONST(Rte_Calprm_CalRegn01Inin06_DEFAULT_RTE_CALPRM_GROUP_Type, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_CalprmRom_CalRegn01Inin06_DEFAULT_RTE_CALPRM_GROUP = { /* PRQA S 3408 */ /* MD_Rte_3408 */
  2100.0F,
  500.0F,
  1.0F,
  20.0F,
  3.0F,
  0.1F,
  0.0F,
  30.0F,
  1.0F,
  -1.0F,
  0.8F,
  15.0F,
  0.0F,
  1.0F,
  -1.0F,
  4.0F,
  0.2F,
  30.0F,
  0.98F,
  360.0F,
  180.0F,
  10.0F,
  3.0F,
  3.0F,
  10.0F,
  0.0F,
  100.0F,
  0.0F,
  22.0F,
  1U,
  656U,
  656U,
  65534U,
  {
    0, 20, 40, 60, 80, 100, 120, 140, 160, 180
  },
  {
    0U, 3641U, 7281U, 10922U, 14562U, 18206U, 21846U, 25487U, 29127U, 32768U
  },
  {
    0.0F, 0.0F, 0.0F, 0.0F
  },
  {
    {0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 
    0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F}
  },
  {
    {0U, 0U, 0U}, {0U, 0U, 0U}, {0U, 0U, 0U}, {0U, 0U, 0U}, {0U, 0U, 0U}, {0U, 0U, 0U}, {0U, 0U, 0U}, {0U, 0U, 0U}
  },
  {
    1.0F, 1.0F, 1.0F, 1.0F
  },
  {
    -15.0F, -5.0F, 5.0F, 15.0F
  },
  {
    0U, 960U, 1920U, 2880U, 3840U, 5760U, 8640U, 11520U, 14400U, 17280U
  },
  {
    24269U, 24269U, 24269U, 24269U, 24269U, 24269U, 24269U, 24269U, 24269U, 24269U
  },
  {
    TRUE, TRUE, TRUE, TRUE
  },
  {
    {0.0F, 5.0F}, {60.0F, 80.0F}, {80.0F, 100.0F}, {100.0F, 120.0F}
  },
  {
    0U, 640U, 1920U, 3840U, 7680U, 10240U, 12800U, 15360U, 19200U, 23040U, 25600U, 28160U
  },
  {
    1233U, 1237U, 1241U, 1245U, 1249U, 1253U, 1257U, 1262U, 1262U, 1262U, 1262U, 1262U, 1262U, 1262U, 1257U, 1253U, 
    1249U, 1245U, 1241U, 1237U, 1233U
  },
  {
    17592U, 17592U, 17592U, 17285U, 16589U, 15770U, 14930U, 14213U, 13926U, 13681U, 13681U, 13681U, 13926U, 14213U, 
    14930U, 15770U, 16589U, 17285U, 17592U, 17592U, 17592U
  },
  {
    29491U, 29655U, 29819U, 29983U, 30147U, 30147U, 30147U, 30147U, 30147U, 30147U, 30147U, 30147U, 30147U, 30147U, 
    30147U, 30147U, 30147U, 29983U, 29819U, 29655U, 29491U
  },
  {
    -5939, -5300, -4678, -4063, -3465, -2867, -2277, -1704, -1139, -565, 0, 565, 1139, 1704, 2277, 2867, 3465, 4063, 
    4678, 5300, 5939
  },
  {
    4522U, 4555U, 4588U, 4620U, 4653U, 4686U, 4719U, 4719U, 4719U, 4719U, 4719U, 4719U, 4719U, 4719U, 4719U, 4686U, 
    4653U, 4620U, 4588U, 4555U, 4522U
  },
  {
    0U, 12800U, 25600U, 38400U, 51200U, 65408U
  }
};
CONST(Rte_Calprm_CalRegn01IninOptSetA00_DEFAULT_RTE_CALPRM_GROUP_Type, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_CalprmRom_CalRegn01IninOptSetA00_DEFAULT_RTE_CALPRM_GROUP = { /* PRQA S 3408 */ /* MD_Rte_3408 */
  1.375F,
  0.3F,
  0.3F,
  70.0F,
  0.5F,
  0.5F,
  0.3F,
  0.3F,
  0.5F,
  2.8F,
  25.0F,
  0.0052F,
  0.045F,
  0.031F,
  0.04F,
  1.0F,
  0.00013F,
  0.00013F,
  0.0001F,
  0.00011889F,
  0.00013F,
  0.00013F,
  0.0001F,
  0.00011889F,
  0.032F,
  0.01246F,
  0.0139F,
  0.0039F,
  25.0F,
  8.0F,
  0.03F,
  1.0F,
  1.0F,
  0.0F,
  0.0F,
  10.0F,
  100.0F,
  0.0F,
  100.0F,
  100.0F,
  100.0F,
  200.0F,
  9.0F,
  -4.5F,
  500.0F,
  14.5F,
  -14.5F,
  0.0F,
  0.0F,
  0.1F,
  1.0F,
  0.25F,
  3.0F,
  2.3F,
  0.365F,
  0.0335999F,
  0.5F,
  1.0F,
  0.6F,
  13.5F,
  100.0F,
  3.125F,
  3125.0F,
  20.0F,
  0.024F,
  0.024F,
  0.024F,
  0.024F,
  0.024F,
  0.024F,
  0.024F,
  0.024F,
  0.024F,
  0.024F,
  0.024F,
  0.024F,
  120.0F,
  92U,
  2000U,
  TRUE,
  FALSE,
  TRUE,
  TRUE,
  FALSE,
  FALSE,
  TRUE,
  {
    122, 123, 125, 127
  },
  {
    122, 123, 125, 127
  },
  {
    346U, 287U, 234U, 0U
  },
  {
    346U, 287U, 234U, 0U
  },
  {
    122, 123, 125, 127
  },
  {
    122, 123, 125, 127
  },
  {
    346U, 287U, 234U, 0U
  },
  {
    346U, 287U, 234U, 0U
  },
  {
    {128U, 128U, 128U, 44U, 44U}, {128U, 128U, 128U, 44U, 44U}
  },
  {
    {124U, 124U, 124U, 40U, 40U}, {124U, 124U, 124U, 40U, 40U}
  },
  {
    127U, 127U, 127U, 1630U, 1630U
  },
  {
    133U, 133U, 133U, 180U, 180U
  },
  {
    127U, 127U, 127U, 1630U, 1630U
  },
  {
    133U, 133U, 133U, 180U, 180U
  },
  {
    159U, 159U, 159U, 281U, 281U
  },
  {
    167U, 167U, 167U, 310U, 310U
  },
  {
    159U, 159U, 159U, 281U, 281U
  },
  {
    167U, 167U, 167U, 310U, 310U
  },
  {
    199U, 199U, 199U, 1282U, 1282U
  },
  {
    210U, 210U, 210U, 1707U, 1707U
  },
  {
    199U, 199U, 199U, 1282U, 1282U
  },
  {
    210U, 210U, 210U, 1707U, 1707U
  },
  {
    1U, 1U, 1U, 1U, 1U
  },
  {
    1U, 1U, 1U, 1U, 1U
  },
  {
    1U, 1U, 1U, 1U, 1U
  },
  {
    1U, 1U, 1U, 1U, 1U
  },
  {
    998U, 998U, 998U, 9535U, 9535U
  },
  {
    998U, 998U, 998U, 9535U, 9535U
  },
  {
    998U, 998U, 998U, 9535U, 9535U
  },
  {
    998U, 998U, 998U, 9535U, 9535U
  },
  {
    1U, 1U, 1U, 1U, 1U
  },
  {
    1U, 1U, 1U, 1U, 1U
  },
  {
    1U, 1U, 1U, 1U, 1U
  },
  {
    1U, 1U, 1U, 1U, 1U
  },
  {
    -40, 0, 83, 84, 85
  },
  {
    -40, 0, 83, 84, 85
  },
  {
    {0U, 76U, 80U, 84U, 88U, 92U, 96U, 100U}, {0U, 76U, 80U, 84U, 88U, 92U, 96U, 100U}
  },
  {
    {346U, 346U, 346U, 346U, 287U, 234U, 181U, 128U}, {346U, 346U, 346U, 346U, 287U, 234U, 181U, 128U}
  },
  {
    1.375F, 1.375F
  },
  {
    0U, 563U, 640U, 717U, 768U, 768U
  },
  {
    768U, 768U, 512U, 256U, 0U, 0U
  },
  {
    0U, 563U, 640U, 717U, 768U, 768U
  },
  {
    768U, 768U, 512U, 256U, 0U, 0U
  },
  {
    0.101563F, 0.101563F
  },
  {
    0U, 1280U, 2560U, 3840U, 5120U, 6400U, 7680U, 8960U, 10240U, 11520U, 12800U, 14080U, 15360U, 16640U, 19200U, 21760U
  },
  {
    16384U, 16384U, 16384U, 16384U, 16384U, 16384U, 16384U, 16384U, 16384U, 16384U, 16384U, 16370U, 16336U, 16276U, 
    16095U, 15869U
  },
  {
    0U, 3200U, 6400U, 9600U, 12800U, 16000U
  },
  {
    0U, 3200U, 6400U, 9600U, 12800U, 16000U, 19200U
  },
  {
    {16384U, 16384U, 16384U, 16384U, 16384U, 16305U, 16096U}, {16384U, 16384U, 16384U, 16384U, 16384U, 16305U, 16096U}, {
    16384U, 16384U, 16384U, 16384U, 16384U, 16305U, 16096U}, {16384U, 16384U, 16384U, 16384U, 16384U, 16305U, 16096U}, {
    16384U, 16384U, 16384U, 16384U, 16384U, 16305U, 16096U}, {16384U, 16384U, 16384U, 16384U, 16384U, 16305U, 16096U}
  },
  {
    {16384U, 16384U, 16384U, 16384U, 16384U, 16305U, 16096U}, {16384U, 16384U, 16384U, 16384U, 16384U, 16305U, 16096U}, {
    16384U, 16384U, 16384U, 16384U, 16384U, 16305U, 16096U}, {16384U, 16384U, 16384U, 16384U, 16384U, 16305U, 16096U}, {
    16384U, 16384U, 16384U, 16384U, 16384U, 16305U, 16096U}, {16384U, 16384U, 16384U, 16384U, 16384U, 16305U, 16096U}
  },
  {
    12800U, 19200U, 19200U, 19200U
  },
  {
    12800U, 19200U, 19200U, 19200U
  },
  {
    38400U, 38400U, 38400U, 38400U
  },
  {
    38400U, 38400U, 38400U, 38400U
  },
  {
    0U, 6144U, 7168U, 8192U, 9216U, 10240U, 12288U, 14336U, 16384U, 18432U, 20480U
  },
  {
    0U, 16384U, 19661U, 22938U, 23757U, 25395U, 27034U, 27853U, 29491U, 31130U, 32768U
  },
  {
    -3.1415927F, -2.3561945F, -1.5707964F, -0.7853982F, 0.0F, 0.7853982F, 1.5707964F, 2.3561945F
  },
  {
    0U, 3200U, 6400U, 9600U, 16000U, 19200U, 22400U, 25600U, 28800U, 35200U
  },
  {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  },
  {
    0U, 3200U, 6400U, 9600U, 16000U, 19200U, 22400U, 25600U, 28800U, 35200U
  },
  {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  },
  {
    -17600, -12800, -10400, -8800, -5657, -4600, -3499, -1731, 0, 1731, 3499, 4600, 5657, 8800
  },
  {
    1475U, 2867U, 3891U, 4710U, 7168U, 8397U, 9486U, 9486U, 9486U, 9486U, 7277U, 5994U, 4506U, 0U
  },
  {
    0U, 2182U, 5717U, 7919U, 10034U, 16320U
  },
  {
    18973U, 18973U, 14553U, 11989U, 9011U, 0U
  },
  {
    17496U, 18728U, 18928U, 19136U, 19336U, 19544U, 20568U, 21592U, 22208U, 25280U
  },
  {
    3395U, 2859U, 2769U, 2680U, 2591U, 2501U, 2054U, 1608U, 1340U, 0U
  },
  {
    0.01F, 0.01F, 0.01F
  },
  {
    0.9F, 0.9F, 0.9F
  },
  {
    0.01F, 0.01F, 0.01F
  },
  {
    60.0F, 60.0F, 60.0F
  },
  {
    0.0001F, 0.0001F, 0.0001F
  },
  {
    50.0F, 50.0F, 50.0F
  },
  {
    0.99996858F, 0.99996858F, 0.99996858F
  },
  {
    0.4761987F, 0.4761987F, 0.4761987F
  },
  {
    -0.4761673F, -0.4761673F, -0.4761673F
  },
  {
    1.0F, 1.0F, 1.0F
  },
  {
    0.0F, 0.0F, 0.0F
  },
  {
    0.0F, 0.0F, 0.0F
  },
  {
    0.0F, 0.0F, 0.0F
  },
  {
    0.0F, 0.0F, 0.0F
  },
  {
    0.75F, 0.75F, 0.75F
  },
  {
    80.0F, 80.0F, 80.0F
  },
  {
    0.999943F, 0.999943F, 0.999943F
  },
  {
    0.86667F, 0.86667F, 0.86667F
  },
  {
    -0.866613F, -0.866613F, -0.866613F
  },
  {
    0.1F, 0.1F, 0.1F
  },
  {
    0.01F, 0.01F, 0.01F
  },
  {
    60.0F, 60.0F, 60.0F
  },
  {
    0.999962F, 0.999962F, 0.999962F
  },
  {
    0.571437F, 0.571437F, 0.571437F
  },
  {
    -0.571399F, -0.571399F, -0.571399F
  },
  {
    0.0F, 0.0F, 0.0F
  },
  {
    60.0F, 60.0F, 60.0F
  },
  {
    0.999889F, 0.999889F, 0.999889F
  },
  {
    1.68568F, 1.68568F, 1.68568F
  },
  {
    -1.68556F, -1.68556F, -1.68556F
  },
  {
    4000.0F, 4000.0F, 4000.0F
  },
  {
    79.0F, 79.0F, 79.0F
  },
  {
    50.0F, 50.0F, 50.0F
  },
  {
    214.0F, 214.0F, 214.0F
  },
  {
    FALSE, FALSE, FALSE
  }
};
CONST(Rte_Calprm_CalRegn01IninOptSetA01_DEFAULT_RTE_CALPRM_GROUP_Type, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_CalprmRom_CalRegn01IninOptSetA01_DEFAULT_RTE_CALPRM_GROUP = { /* PRQA S 3408 */ /* MD_Rte_3408 */
  1.375F,
  0.3F,
  0.3F,
  70.0F,
  0.5F,
  0.5F,
  0.3F,
  0.3F,
  0.5F,
  2.8F,
  25.0F,
  0.0052F,
  0.045F,
  0.031F,
  0.04F,
  1.0F,
  0.00013F,
  0.00013F,
  0.0001F,
  0.00011889F,
  0.00013F,
  0.00013F,
  0.0001F,
  0.00011889F,
  0.032F,
  0.01246F,
  0.0139F,
  0.0039F,
  25.0F,
  8.0F,
  0.03F,
  1.0F,
  1.0F,
  0.0F,
  0.0F,
  10.0F,
  100.0F,
  0.0F,
  100.0F,
  100.0F,
  100.0F,
  200.0F,
  9.0F,
  -4.5F,
  500.0F,
  14.5F,
  -14.5F,
  0.0F,
  0.0F,
  0.1F,
  1.0F,
  0.25F,
  3.0F,
  2.3F,
  0.365F,
  0.0335999F,
  0.5F,
  1.0F,
  0.6F,
  13.5F,
  100.0F,
  3.125F,
  3125.0F,
  20.0F,
  0.024F,
  0.024F,
  0.024F,
  0.024F,
  0.024F,
  0.024F,
  0.024F,
  0.024F,
  0.024F,
  0.024F,
  0.024F,
  0.024F,
  120.0F,
  92U,
  2000U,
  TRUE,
  FALSE,
  TRUE,
  TRUE,
  FALSE,
  FALSE,
  TRUE,
  {
    122, 123, 125, 127
  },
  {
    122, 123, 125, 127
  },
  {
    346U, 287U, 234U, 0U
  },
  {
    346U, 287U, 234U, 0U
  },
  {
    122, 123, 125, 127
  },
  {
    122, 123, 125, 127
  },
  {
    346U, 287U, 234U, 0U
  },
  {
    346U, 287U, 234U, 0U
  },
  {
    {128U, 128U, 128U, 44U, 44U}, {128U, 128U, 128U, 44U, 44U}
  },
  {
    {124U, 124U, 124U, 40U, 40U}, {124U, 124U, 124U, 40U, 40U}
  },
  {
    127U, 127U, 127U, 1630U, 1630U
  },
  {
    133U, 133U, 133U, 180U, 180U
  },
  {
    127U, 127U, 127U, 1630U, 1630U
  },
  {
    133U, 133U, 133U, 180U, 180U
  },
  {
    159U, 159U, 159U, 281U, 281U
  },
  {
    167U, 167U, 167U, 310U, 310U
  },
  {
    159U, 159U, 159U, 281U, 281U
  },
  {
    167U, 167U, 167U, 310U, 310U
  },
  {
    199U, 199U, 199U, 1282U, 1282U
  },
  {
    210U, 210U, 210U, 1707U, 1707U
  },
  {
    199U, 199U, 199U, 1282U, 1282U
  },
  {
    210U, 210U, 210U, 1707U, 1707U
  },
  {
    1U, 1U, 1U, 1U, 1U
  },
  {
    1U, 1U, 1U, 1U, 1U
  },
  {
    1U, 1U, 1U, 1U, 1U
  },
  {
    1U, 1U, 1U, 1U, 1U
  },
  {
    998U, 998U, 998U, 9535U, 9535U
  },
  {
    998U, 998U, 998U, 9535U, 9535U
  },
  {
    998U, 998U, 998U, 9535U, 9535U
  },
  {
    998U, 998U, 998U, 9535U, 9535U
  },
  {
    1U, 1U, 1U, 1U, 1U
  },
  {
    1U, 1U, 1U, 1U, 1U
  },
  {
    1U, 1U, 1U, 1U, 1U
  },
  {
    1U, 1U, 1U, 1U, 1U
  },
  {
    -40, 0, 83, 84, 85
  },
  {
    -40, 0, 83, 84, 85
  },
  {
    {0U, 76U, 80U, 84U, 88U, 92U, 96U, 100U}, {0U, 76U, 80U, 84U, 88U, 92U, 96U, 100U}
  },
  {
    {346U, 346U, 346U, 346U, 287U, 234U, 181U, 128U}, {346U, 346U, 346U, 346U, 287U, 234U, 181U, 128U}
  },
  {
    1.375F, 1.375F
  },
  {
    0U, 563U, 640U, 717U, 768U, 768U
  },
  {
    768U, 768U, 512U, 256U, 0U, 0U
  },
  {
    0U, 563U, 640U, 717U, 768U, 768U
  },
  {
    768U, 768U, 512U, 256U, 0U, 0U
  },
  {
    0.101563F, 0.101563F
  },
  {
    0U, 1280U, 2560U, 3840U, 5120U, 6400U, 7680U, 8960U, 10240U, 11520U, 12800U, 14080U, 15360U, 16640U, 19200U, 21760U
  },
  {
    16384U, 16384U, 16384U, 16384U, 16384U, 16384U, 16384U, 16384U, 16384U, 16384U, 16384U, 16370U, 16336U, 16276U, 
    16095U, 15869U
  },
  {
    0U, 3200U, 6400U, 9600U, 12800U, 16000U
  },
  {
    0U, 3200U, 6400U, 9600U, 12800U, 16000U, 19200U
  },
  {
    {16384U, 16384U, 16384U, 16384U, 16384U, 16305U, 16096U}, {16384U, 16384U, 16384U, 16384U, 16384U, 16305U, 16096U}, {
    16384U, 16384U, 16384U, 16384U, 16384U, 16305U, 16096U}, {16384U, 16384U, 16384U, 16384U, 16384U, 16305U, 16096U}, {
    16384U, 16384U, 16384U, 16384U, 16384U, 16305U, 16096U}, {16384U, 16384U, 16384U, 16384U, 16384U, 16305U, 16096U}
  },
  {
    {16384U, 16384U, 16384U, 16384U, 16384U, 16305U, 16096U}, {16384U, 16384U, 16384U, 16384U, 16384U, 16305U, 16096U}, {
    16384U, 16384U, 16384U, 16384U, 16384U, 16305U, 16096U}, {16384U, 16384U, 16384U, 16384U, 16384U, 16305U, 16096U}, {
    16384U, 16384U, 16384U, 16384U, 16384U, 16305U, 16096U}, {16384U, 16384U, 16384U, 16384U, 16384U, 16305U, 16096U}
  },
  {
    12800U, 19200U, 19200U, 19200U
  },
  {
    12800U, 19200U, 19200U, 19200U
  },
  {
    38400U, 38400U, 38400U, 38400U
  },
  {
    38400U, 38400U, 38400U, 38400U
  },
  {
    0U, 6144U, 7168U, 8192U, 9216U, 10240U, 12288U, 14336U, 16384U, 18432U, 20480U
  },
  {
    0U, 16384U, 19661U, 22938U, 23757U, 25395U, 27034U, 27853U, 29491U, 31130U, 32768U
  },
  {
    -3.1415927F, -2.3561945F, -1.5707964F, -0.7853982F, 0.0F, 0.7853982F, 1.5707964F, 2.3561945F
  },
  {
    0U, 3200U, 6400U, 9600U, 16000U, 19200U, 22400U, 25600U, 28800U, 35200U
  },
  {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  },
  {
    0U, 3200U, 6400U, 9600U, 16000U, 19200U, 22400U, 25600U, 28800U, 35200U
  },
  {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  },
  {
    -17600, -12800, -10400, -8800, -5657, -4600, -3499, -1731, 0, 1731, 3499, 4600, 5657, 8800
  },
  {
    1475U, 2867U, 3891U, 4710U, 7168U, 8397U, 9486U, 9486U, 9486U, 9486U, 7277U, 5994U, 4506U, 0U
  },
  {
    0U, 2182U, 5717U, 7919U, 10034U, 16320U
  },
  {
    18973U, 18973U, 14553U, 11989U, 9011U, 0U
  },
  {
    17496U, 18728U, 18928U, 19136U, 19336U, 19544U, 20568U, 21592U, 22208U, 25280U
  },
  {
    3395U, 2859U, 2769U, 2680U, 2591U, 2501U, 2054U, 1608U, 1340U, 0U
  },
  {
    0.01F, 0.01F, 0.01F
  },
  {
    0.9F, 0.9F, 0.9F
  },
  {
    0.01F, 0.01F, 0.01F
  },
  {
    60.0F, 60.0F, 60.0F
  },
  {
    0.0001F, 0.0001F, 0.0001F
  },
  {
    50.0F, 50.0F, 50.0F
  },
  {
    0.99996858F, 0.99996858F, 0.99996858F
  },
  {
    0.4761987F, 0.4761987F, 0.4761987F
  },
  {
    -0.4761673F, -0.4761673F, -0.4761673F
  },
  {
    1.0F, 1.0F, 1.0F
  },
  {
    0.0F, 0.0F, 0.0F
  },
  {
    0.0F, 0.0F, 0.0F
  },
  {
    0.0F, 0.0F, 0.0F
  },
  {
    0.0F, 0.0F, 0.0F
  },
  {
    0.75F, 0.75F, 0.75F
  },
  {
    80.0F, 80.0F, 80.0F
  },
  {
    0.999943F, 0.999943F, 0.999943F
  },
  {
    0.86667F, 0.86667F, 0.86667F
  },
  {
    -0.866613F, -0.866613F, -0.866613F
  },
  {
    0.1F, 0.1F, 0.1F
  },
  {
    0.01F, 0.01F, 0.01F
  },
  {
    60.0F, 60.0F, 60.0F
  },
  {
    0.999962F, 0.999962F, 0.999962F
  },
  {
    0.571437F, 0.571437F, 0.571437F
  },
  {
    -0.571399F, -0.571399F, -0.571399F
  },
  {
    0.0F, 0.0F, 0.0F
  },
  {
    60.0F, 60.0F, 60.0F
  },
  {
    0.999889F, 0.999889F, 0.999889F
  },
  {
    1.68568F, 1.68568F, 1.68568F
  },
  {
    -1.68556F, -1.68556F, -1.68556F
  },
  {
    4000.0F, 4000.0F, 4000.0F
  },
  {
    79.0F, 79.0F, 79.0F
  },
  {
    50.0F, 50.0F, 50.0F
  },
  {
    214.0F, 214.0F, 214.0F
  },
  {
    FALSE, FALSE, FALSE
  }
};
CONST(Rte_Calprm_CalRegn01IninOptSetA02_DEFAULT_RTE_CALPRM_GROUP_Type, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_CalprmRom_CalRegn01IninOptSetA02_DEFAULT_RTE_CALPRM_GROUP = { /* PRQA S 3408 */ /* MD_Rte_3408 */
  1.375F,
  0.3F,
  0.3F,
  70.0F,
  0.5F,
  0.5F,
  0.3F,
  0.3F,
  0.5F,
  2.8F,
  25.0F,
  0.0052F,
  0.045F,
  0.031F,
  0.04F,
  1.0F,
  0.00013F,
  0.00013F,
  0.0001F,
  0.00011889F,
  0.00013F,
  0.00013F,
  0.0001F,
  0.00011889F,
  0.032F,
  0.01246F,
  0.0139F,
  0.0039F,
  25.0F,
  8.0F,
  0.03F,
  1.0F,
  1.0F,
  0.0F,
  0.0F,
  10.0F,
  100.0F,
  0.0F,
  100.0F,
  100.0F,
  100.0F,
  200.0F,
  9.0F,
  -4.5F,
  500.0F,
  14.5F,
  -14.5F,
  0.0F,
  0.0F,
  0.1F,
  1.0F,
  0.25F,
  3.0F,
  2.3F,
  0.365F,
  0.0335999F,
  0.5F,
  1.0F,
  0.6F,
  13.5F,
  100.0F,
  3.125F,
  3125.0F,
  20.0F,
  0.024F,
  0.024F,
  0.024F,
  0.024F,
  0.024F,
  0.024F,
  0.024F,
  0.024F,
  0.024F,
  0.024F,
  0.024F,
  0.024F,
  120.0F,
  92U,
  2000U,
  TRUE,
  FALSE,
  TRUE,
  TRUE,
  FALSE,
  FALSE,
  TRUE,
  {
    122, 123, 125, 127
  },
  {
    122, 123, 125, 127
  },
  {
    346U, 287U, 234U, 0U
  },
  {
    346U, 287U, 234U, 0U
  },
  {
    122, 123, 125, 127
  },
  {
    122, 123, 125, 127
  },
  {
    346U, 287U, 234U, 0U
  },
  {
    346U, 287U, 234U, 0U
  },
  {
    {128U, 128U, 128U, 44U, 44U}, {128U, 128U, 128U, 44U, 44U}
  },
  {
    {124U, 124U, 124U, 40U, 40U}, {124U, 124U, 124U, 40U, 40U}
  },
  {
    127U, 127U, 127U, 1630U, 1630U
  },
  {
    133U, 133U, 133U, 180U, 180U
  },
  {
    127U, 127U, 127U, 1630U, 1630U
  },
  {
    133U, 133U, 133U, 180U, 180U
  },
  {
    159U, 159U, 159U, 281U, 281U
  },
  {
    167U, 167U, 167U, 310U, 310U
  },
  {
    159U, 159U, 159U, 281U, 281U
  },
  {
    167U, 167U, 167U, 310U, 310U
  },
  {
    199U, 199U, 199U, 1282U, 1282U
  },
  {
    210U, 210U, 210U, 1707U, 1707U
  },
  {
    199U, 199U, 199U, 1282U, 1282U
  },
  {
    210U, 210U, 210U, 1707U, 1707U
  },
  {
    1U, 1U, 1U, 1U, 1U
  },
  {
    1U, 1U, 1U, 1U, 1U
  },
  {
    1U, 1U, 1U, 1U, 1U
  },
  {
    1U, 1U, 1U, 1U, 1U
  },
  {
    998U, 998U, 998U, 9535U, 9535U
  },
  {
    998U, 998U, 998U, 9535U, 9535U
  },
  {
    998U, 998U, 998U, 9535U, 9535U
  },
  {
    998U, 998U, 998U, 9535U, 9535U
  },
  {
    1U, 1U, 1U, 1U, 1U
  },
  {
    1U, 1U, 1U, 1U, 1U
  },
  {
    1U, 1U, 1U, 1U, 1U
  },
  {
    1U, 1U, 1U, 1U, 1U
  },
  {
    -40, 0, 83, 84, 85
  },
  {
    -40, 0, 83, 84, 85
  },
  {
    {0U, 76U, 80U, 84U, 88U, 92U, 96U, 100U}, {0U, 76U, 80U, 84U, 88U, 92U, 96U, 100U}
  },
  {
    {346U, 346U, 346U, 346U, 287U, 234U, 181U, 128U}, {346U, 346U, 346U, 346U, 287U, 234U, 181U, 128U}
  },
  {
    1.375F, 1.375F
  },
  {
    0U, 563U, 640U, 717U, 768U, 768U
  },
  {
    768U, 768U, 512U, 256U, 0U, 0U
  },
  {
    0U, 563U, 640U, 717U, 768U, 768U
  },
  {
    768U, 768U, 512U, 256U, 0U, 0U
  },
  {
    0.101563F, 0.101563F
  },
  {
    0U, 1280U, 2560U, 3840U, 5120U, 6400U, 7680U, 8960U, 10240U, 11520U, 12800U, 14080U, 15360U, 16640U, 19200U, 21760U
  },
  {
    16384U, 16384U, 16384U, 16384U, 16384U, 16384U, 16384U, 16384U, 16384U, 16384U, 16384U, 16370U, 16336U, 16276U, 
    16095U, 15869U
  },
  {
    0U, 3200U, 6400U, 9600U, 12800U, 16000U
  },
  {
    0U, 3200U, 6400U, 9600U, 12800U, 16000U, 19200U
  },
  {
    {16384U, 16384U, 16384U, 16384U, 16384U, 16305U, 16096U}, {16384U, 16384U, 16384U, 16384U, 16384U, 16305U, 16096U}, {
    16384U, 16384U, 16384U, 16384U, 16384U, 16305U, 16096U}, {16384U, 16384U, 16384U, 16384U, 16384U, 16305U, 16096U}, {
    16384U, 16384U, 16384U, 16384U, 16384U, 16305U, 16096U}, {16384U, 16384U, 16384U, 16384U, 16384U, 16305U, 16096U}
  },
  {
    {16384U, 16384U, 16384U, 16384U, 16384U, 16305U, 16096U}, {16384U, 16384U, 16384U, 16384U, 16384U, 16305U, 16096U}, {
    16384U, 16384U, 16384U, 16384U, 16384U, 16305U, 16096U}, {16384U, 16384U, 16384U, 16384U, 16384U, 16305U, 16096U}, {
    16384U, 16384U, 16384U, 16384U, 16384U, 16305U, 16096U}, {16384U, 16384U, 16384U, 16384U, 16384U, 16305U, 16096U}
  },
  {
    12800U, 19200U, 19200U, 19200U
  },
  {
    12800U, 19200U, 19200U, 19200U
  },
  {
    38400U, 38400U, 38400U, 38400U
  },
  {
    38400U, 38400U, 38400U, 38400U
  },
  {
    0U, 6144U, 7168U, 8192U, 9216U, 10240U, 12288U, 14336U, 16384U, 18432U, 20480U
  },
  {
    0U, 16384U, 19661U, 22938U, 23757U, 25395U, 27034U, 27853U, 29491U, 31130U, 32768U
  },
  {
    -3.1415927F, -2.3561945F, -1.5707964F, -0.7853982F, 0.0F, 0.7853982F, 1.5707964F, 2.3561945F
  },
  {
    0U, 3200U, 6400U, 9600U, 16000U, 19200U, 22400U, 25600U, 28800U, 35200U
  },
  {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  },
  {
    0U, 3200U, 6400U, 9600U, 16000U, 19200U, 22400U, 25600U, 28800U, 35200U
  },
  {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  },
  {
    -17600, -12800, -10400, -8800, -5657, -4600, -3499, -1731, 0, 1731, 3499, 4600, 5657, 8800
  },
  {
    1475U, 2867U, 3891U, 4710U, 7168U, 8397U, 9486U, 9486U, 9486U, 9486U, 7277U, 5994U, 4506U, 0U
  },
  {
    0U, 2182U, 5717U, 7919U, 10034U, 16320U
  },
  {
    18973U, 18973U, 14553U, 11989U, 9011U, 0U
  },
  {
    17496U, 18728U, 18928U, 19136U, 19336U, 19544U, 20568U, 21592U, 22208U, 25280U
  },
  {
    3395U, 2859U, 2769U, 2680U, 2591U, 2501U, 2054U, 1608U, 1340U, 0U
  },
  {
    0.01F, 0.01F, 0.01F
  },
  {
    0.9F, 0.9F, 0.9F
  },
  {
    0.01F, 0.01F, 0.01F
  },
  {
    60.0F, 60.0F, 60.0F
  },
  {
    0.0001F, 0.0001F, 0.0001F
  },
  {
    50.0F, 50.0F, 50.0F
  },
  {
    0.99996858F, 0.99996858F, 0.99996858F
  },
  {
    0.4761987F, 0.4761987F, 0.4761987F
  },
  {
    -0.4761673F, -0.4761673F, -0.4761673F
  },
  {
    1.0F, 1.0F, 1.0F
  },
  {
    0.0F, 0.0F, 0.0F
  },
  {
    0.0F, 0.0F, 0.0F
  },
  {
    0.0F, 0.0F, 0.0F
  },
  {
    0.0F, 0.0F, 0.0F
  },
  {
    0.75F, 0.75F, 0.75F
  },
  {
    80.0F, 80.0F, 80.0F
  },
  {
    0.999943F, 0.999943F, 0.999943F
  },
  {
    0.86667F, 0.86667F, 0.86667F
  },
  {
    -0.866613F, -0.866613F, -0.866613F
  },
  {
    0.1F, 0.1F, 0.1F
  },
  {
    0.01F, 0.01F, 0.01F
  },
  {
    60.0F, 60.0F, 60.0F
  },
  {
    0.999962F, 0.999962F, 0.999962F
  },
  {
    0.571437F, 0.571437F, 0.571437F
  },
  {
    -0.571399F, -0.571399F, -0.571399F
  },
  {
    0.0F, 0.0F, 0.0F
  },
  {
    60.0F, 60.0F, 60.0F
  },
  {
    0.999889F, 0.999889F, 0.999889F
  },
  {
    1.68568F, 1.68568F, 1.68568F
  },
  {
    -1.68556F, -1.68556F, -1.68556F
  },
  {
    4000.0F, 4000.0F, 4000.0F
  },
  {
    79.0F, 79.0F, 79.0F
  },
  {
    50.0F, 50.0F, 50.0F
  },
  {
    214.0F, 214.0F, 214.0F
  },
  {
    FALSE, FALSE, FALSE
  }
};
CONST(Rte_Calprm_CalRegn01IninOptSetA03_DEFAULT_RTE_CALPRM_GROUP_Type, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_CalprmRom_CalRegn01IninOptSetA03_DEFAULT_RTE_CALPRM_GROUP = { /* PRQA S 3408 */ /* MD_Rte_3408 */
  1.375F,
  0.3F,
  0.3F,
  70.0F,
  0.5F,
  0.5F,
  0.3F,
  0.3F,
  0.5F,
  2.8F,
  25.0F,
  0.0052F,
  0.045F,
  0.031F,
  0.04F,
  1.0F,
  0.00013F,
  0.00013F,
  0.0001F,
  0.00011889F,
  0.00013F,
  0.00013F,
  0.0001F,
  0.00011889F,
  0.032F,
  0.01246F,
  0.0139F,
  0.0039F,
  25.0F,
  8.0F,
  0.03F,
  1.0F,
  1.0F,
  0.0F,
  0.0F,
  10.0F,
  100.0F,
  0.0F,
  100.0F,
  100.0F,
  100.0F,
  200.0F,
  9.0F,
  -4.5F,
  500.0F,
  14.5F,
  -14.5F,
  0.0F,
  0.0F,
  0.1F,
  1.0F,
  0.25F,
  3.0F,
  2.3F,
  0.365F,
  0.0335999F,
  0.5F,
  1.0F,
  0.6F,
  13.5F,
  100.0F,
  3.125F,
  3125.0F,
  20.0F,
  0.024F,
  0.024F,
  0.024F,
  0.024F,
  0.024F,
  0.024F,
  0.024F,
  0.024F,
  0.024F,
  0.024F,
  0.024F,
  0.024F,
  120.0F,
  92U,
  2000U,
  TRUE,
  FALSE,
  TRUE,
  TRUE,
  FALSE,
  FALSE,
  TRUE,
  {
    122, 123, 125, 127
  },
  {
    122, 123, 125, 127
  },
  {
    346U, 287U, 234U, 0U
  },
  {
    346U, 287U, 234U, 0U
  },
  {
    122, 123, 125, 127
  },
  {
    122, 123, 125, 127
  },
  {
    346U, 287U, 234U, 0U
  },
  {
    346U, 287U, 234U, 0U
  },
  {
    {128U, 128U, 128U, 44U, 44U}, {128U, 128U, 128U, 44U, 44U}
  },
  {
    {124U, 124U, 124U, 40U, 40U}, {124U, 124U, 124U, 40U, 40U}
  },
  {
    127U, 127U, 127U, 1630U, 1630U
  },
  {
    133U, 133U, 133U, 180U, 180U
  },
  {
    127U, 127U, 127U, 1630U, 1630U
  },
  {
    133U, 133U, 133U, 180U, 180U
  },
  {
    159U, 159U, 159U, 281U, 281U
  },
  {
    167U, 167U, 167U, 310U, 310U
  },
  {
    159U, 159U, 159U, 281U, 281U
  },
  {
    167U, 167U, 167U, 310U, 310U
  },
  {
    199U, 199U, 199U, 1282U, 1282U
  },
  {
    210U, 210U, 210U, 1707U, 1707U
  },
  {
    199U, 199U, 199U, 1282U, 1282U
  },
  {
    210U, 210U, 210U, 1707U, 1707U
  },
  {
    1U, 1U, 1U, 1U, 1U
  },
  {
    1U, 1U, 1U, 1U, 1U
  },
  {
    1U, 1U, 1U, 1U, 1U
  },
  {
    1U, 1U, 1U, 1U, 1U
  },
  {
    998U, 998U, 998U, 9535U, 9535U
  },
  {
    998U, 998U, 998U, 9535U, 9535U
  },
  {
    998U, 998U, 998U, 9535U, 9535U
  },
  {
    998U, 998U, 998U, 9535U, 9535U
  },
  {
    1U, 1U, 1U, 1U, 1U
  },
  {
    1U, 1U, 1U, 1U, 1U
  },
  {
    1U, 1U, 1U, 1U, 1U
  },
  {
    1U, 1U, 1U, 1U, 1U
  },
  {
    -40, 0, 83, 84, 85
  },
  {
    -40, 0, 83, 84, 85
  },
  {
    {0U, 76U, 80U, 84U, 88U, 92U, 96U, 100U}, {0U, 76U, 80U, 84U, 88U, 92U, 96U, 100U}
  },
  {
    {346U, 346U, 346U, 346U, 287U, 234U, 181U, 128U}, {346U, 346U, 346U, 346U, 287U, 234U, 181U, 128U}
  },
  {
    1.375F, 1.375F
  },
  {
    0U, 563U, 640U, 717U, 768U, 768U
  },
  {
    768U, 768U, 512U, 256U, 0U, 0U
  },
  {
    0U, 563U, 640U, 717U, 768U, 768U
  },
  {
    768U, 768U, 512U, 256U, 0U, 0U
  },
  {
    0.101563F, 0.101563F
  },
  {
    0U, 1280U, 2560U, 3840U, 5120U, 6400U, 7680U, 8960U, 10240U, 11520U, 12800U, 14080U, 15360U, 16640U, 19200U, 21760U
  },
  {
    16384U, 16384U, 16384U, 16384U, 16384U, 16384U, 16384U, 16384U, 16384U, 16384U, 16384U, 16370U, 16336U, 16276U, 
    16095U, 15869U
  },
  {
    0U, 3200U, 6400U, 9600U, 12800U, 16000U
  },
  {
    0U, 3200U, 6400U, 9600U, 12800U, 16000U, 19200U
  },
  {
    {16384U, 16384U, 16384U, 16384U, 16384U, 16305U, 16096U}, {16384U, 16384U, 16384U, 16384U, 16384U, 16305U, 16096U}, {
    16384U, 16384U, 16384U, 16384U, 16384U, 16305U, 16096U}, {16384U, 16384U, 16384U, 16384U, 16384U, 16305U, 16096U}, {
    16384U, 16384U, 16384U, 16384U, 16384U, 16305U, 16096U}, {16384U, 16384U, 16384U, 16384U, 16384U, 16305U, 16096U}
  },
  {
    {16384U, 16384U, 16384U, 16384U, 16384U, 16305U, 16096U}, {16384U, 16384U, 16384U, 16384U, 16384U, 16305U, 16096U}, {
    16384U, 16384U, 16384U, 16384U, 16384U, 16305U, 16096U}, {16384U, 16384U, 16384U, 16384U, 16384U, 16305U, 16096U}, {
    16384U, 16384U, 16384U, 16384U, 16384U, 16305U, 16096U}, {16384U, 16384U, 16384U, 16384U, 16384U, 16305U, 16096U}
  },
  {
    12800U, 19200U, 19200U, 19200U
  },
  {
    12800U, 19200U, 19200U, 19200U
  },
  {
    38400U, 38400U, 38400U, 38400U
  },
  {
    38400U, 38400U, 38400U, 38400U
  },
  {
    0U, 6144U, 7168U, 8192U, 9216U, 10240U, 12288U, 14336U, 16384U, 18432U, 20480U
  },
  {
    0U, 16384U, 19661U, 22938U, 23757U, 25395U, 27034U, 27853U, 29491U, 31130U, 32768U
  },
  {
    -3.1415927F, -2.3561945F, -1.5707964F, -0.7853982F, 0.0F, 0.7853982F, 1.5707964F, 2.3561945F
  },
  {
    0U, 3200U, 6400U, 9600U, 16000U, 19200U, 22400U, 25600U, 28800U, 35200U
  },
  {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  },
  {
    0U, 3200U, 6400U, 9600U, 16000U, 19200U, 22400U, 25600U, 28800U, 35200U
  },
  {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  },
  {
    -17600, -12800, -10400, -8800, -5657, -4600, -3499, -1731, 0, 1731, 3499, 4600, 5657, 8800
  },
  {
    1475U, 2867U, 3891U, 4710U, 7168U, 8397U, 9486U, 9486U, 9486U, 9486U, 7277U, 5994U, 4506U, 0U
  },
  {
    0U, 2182U, 5717U, 7919U, 10034U, 16320U
  },
  {
    18973U, 18973U, 14553U, 11989U, 9011U, 0U
  },
  {
    17496U, 18728U, 18928U, 19136U, 19336U, 19544U, 20568U, 21592U, 22208U, 25280U
  },
  {
    3395U, 2859U, 2769U, 2680U, 2591U, 2501U, 2054U, 1608U, 1340U, 0U
  },
  {
    0.01F, 0.01F, 0.01F
  },
  {
    0.9F, 0.9F, 0.9F
  },
  {
    0.01F, 0.01F, 0.01F
  },
  {
    60.0F, 60.0F, 60.0F
  },
  {
    0.0001F, 0.0001F, 0.0001F
  },
  {
    50.0F, 50.0F, 50.0F
  },
  {
    0.99996858F, 0.99996858F, 0.99996858F
  },
  {
    0.4761987F, 0.4761987F, 0.4761987F
  },
  {
    -0.4761673F, -0.4761673F, -0.4761673F
  },
  {
    1.0F, 1.0F, 1.0F
  },
  {
    0.0F, 0.0F, 0.0F
  },
  {
    0.0F, 0.0F, 0.0F
  },
  {
    0.0F, 0.0F, 0.0F
  },
  {
    0.0F, 0.0F, 0.0F
  },
  {
    0.75F, 0.75F, 0.75F
  },
  {
    80.0F, 80.0F, 80.0F
  },
  {
    0.999943F, 0.999943F, 0.999943F
  },
  {
    0.86667F, 0.86667F, 0.86667F
  },
  {
    -0.866613F, -0.866613F, -0.866613F
  },
  {
    0.1F, 0.1F, 0.1F
  },
  {
    0.01F, 0.01F, 0.01F
  },
  {
    60.0F, 60.0F, 60.0F
  },
  {
    0.999962F, 0.999962F, 0.999962F
  },
  {
    0.571437F, 0.571437F, 0.571437F
  },
  {
    -0.571399F, -0.571399F, -0.571399F
  },
  {
    0.0F, 0.0F, 0.0F
  },
  {
    60.0F, 60.0F, 60.0F
  },
  {
    0.999889F, 0.999889F, 0.999889F
  },
  {
    1.68568F, 1.68568F, 1.68568F
  },
  {
    -1.68556F, -1.68556F, -1.68556F
  },
  {
    4000.0F, 4000.0F, 4000.0F
  },
  {
    79.0F, 79.0F, 79.0F
  },
  {
    50.0F, 50.0F, 50.0F
  },
  {
    214.0F, 214.0F, 214.0F
  },
  {
    FALSE, FALSE, FALSE
  }
};
CONST(Rte_Calprm_CalRegn02Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_CalprmRom_CalRegn02Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP = { /* PRQA S 3408 */ /* MD_Rte_3408 */
  0.4F,
  1.0F,
  10.0F,
  0.3F,
  500U,
  {
    {0U, 0U, 0U, 0U, 205U, 410U, 614U, 819U, 1024U}, {0U, 0U, 0U, 0U, 205U, 410U, 614U, 819U, 1024U}, {0U, 0U, 0U, 0U, 
    205U, 410U, 614U, 819U, 1024U}, {0U, 0U, 0U, 0U, 205U, 410U, 614U, 819U, 1024U}, {0U, 0U, 0U, 0U, 205U, 410U, 614U, 
    819U, 1024U}, {0U, 0U, 0U, 0U, 205U, 410U, 614U, 819U, 1024U}, {0U, 0U, 0U, 0U, 205U, 410U, 614U, 819U, 1024U}, {0U, 
    0U, 0U, 0U, 154U, 307U, 471U, 604U, 819U}, {0U, 0U, 0U, 0U, 20U, 41U, 61U, 82U, 102U}
  },
  {
    0U, 1280U, 2560U, 3840U, 5120U, 6400U, 7680U, 8960U, 10240U
  },
  {
    0U, 1200U, 2400U, 3600U, 4800U, 6000U, 7200U, 8400U, 9600U
  },
  {
    0U, 256U, 512U, 768U, 1024U, 1280U, 1536U, 1792U, 2048U, 2304U, 2560U
  },
  {
    32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 26214U, 19661U, 13107U, 6554U, 0U
  }
};
CONST(Rte_Calprm_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_CalprmRom_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP = { /* PRQA S 3408 */ /* MD_Rte_3408 */
  FALSE,
  {
    {0U, 8960U, 10560U, 12160U, 13760U, 15360U, 18560U, 21760U, 24960U}, {0U, 8960U, 10560U, 12160U, 13760U, 15360U, 
    18560U, 21760U, 24960U}, {0U, 8960U, 10560U, 12160U, 13760U, 15360U, 18560U, 21760U, 24960U}, {0U, 8960U, 10560U, 
    12160U, 13760U, 15360U, 18560U, 21760U, 24960U}, {0U, 8960U, 10560U, 12160U, 13760U, 15360U, 18560U, 21760U, 24960U}, 
    {0U, 16000U, 17600U, 19200U, 20800U, 22400U, 25600U, 28800U, 32000U}, {0U, 20608U, 22208U, 23808U, 25408U, 27008U, 
    30208U, 33408U, 36608U}, {0U, 26112U, 27712U, 29312U, 30912U, 32512U, 35712U, 38912U, 42112U}
  },
  {
    {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 1037U, 4355U, 9735U, 16396U, 33177U, 33177U, 33177U}, {0U, 0U, 1152U, 
    4839U, 10817U, 18218U, 36863U, 36863U, 36863U}, {0U, 0U, 1152U, 4839U, 10817U, 18218U, 36863U, 36863U, 36863U}, {0U, 
    0U, 1152U, 4839U, 10817U, 18218U, 36863U, 36863U, 36863U}
  },
  {
    {0U, 384U, 512U, 640U, 768U, 896U, 1024U, 2560U}, {0U, 384U, 512U, 640U, 768U, 896U, 1024U, 2560U}, {0U, 384U, 512U, 
    640U, 768U, 896U, 1024U, 2560U}, {0U, 384U, 512U, 640U, 768U, 896U, 1024U, 2560U}, {0U, 384U, 512U, 640U, 768U, 896U, 
    1024U, 2560U}
  },
  {
    {16384U, 16384U, 16384U, 16384U, 0U, 0U, 0U, 0U}, {16384U, 16384U, 16384U, 16384U, 0U, 0U, 0U, 0U}, {16384U, 16384U, 
    16384U, 16384U, 0U, 0U, 0U, 0U}, {16384U, 16384U, 16384U, 16384U, 0U, 0U, 0U, 0U}, {16384U, 16384U, 16384U, 16384U, 
    0U, 0U, 0U, 0U}
  },
  {
    {0U, 261U, 451U, 776U, 994U, 1220U, 1441U, 1767U, 7200U, 7216U, 7232U, 7248U}, {0U, 261U, 451U, 776U, 994U, 1220U, 
    1441U, 1767U, 7200U, 7216U, 7232U, 7248U}, {0U, 261U, 451U, 776U, 994U, 1220U, 1441U, 1767U, 7200U, 7216U, 7232U, 
    7248U}, {0U, 261U, 451U, 776U, 994U, 1220U, 1441U, 1767U, 7200U, 7216U, 7232U, 7248U}, {0U, 261U, 451U, 776U, 994U, 
    1220U, 1441U, 1767U, 7200U, 7216U, 7232U, 7248U}, {0U, 261U, 451U, 776U, 994U, 1220U, 1441U, 1767U, 7200U, 7216U, 
    7232U, 7248U}, {0U, 261U, 451U, 776U, 994U, 1220U, 1441U, 1767U, 7200U, 7216U, 7232U, 7248U}, {0U, 261U, 451U, 776U, 
    994U, 1220U, 1441U, 1767U, 7200U, 7216U, 7232U, 7248U}
  },
  {
    {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 1788U, 3385U, 5353U, 6805U, 8089U, 8953U, 9259U, 9259U, 9259U, 
    9259U, 9259U}, {0U, 2446U, 4630U, 7323U, 9309U, 11066U, 12247U, 12666U, 12666U, 12666U, 12666U, 12666U}, {0U, 3090U, 
    5849U, 9249U, 11759U, 13978U, 15470U, 16000U, 16000U, 16000U, 16000U, 16000U}, {0U, 3708U, 7019U, 11099U, 14111U, 
    16774U, 18564U, 19200U, 19200U, 19200U, 19200U, 19200U}, {0U, 5340U, 10108U, 15983U, 20320U, 24155U, 26732U, 27648U, 
    27648U, 27648U, 27648U, 27648U}, {0U, 6408U, 12130U, 19180U, 24384U, 28986U, 32078U, 33178U, 33178U, 33178U, 33178U, 
    33178U}, {0U, 7306U, 13828U, 21865U, 27798U, 33044U, 36569U, 37823U, 37823U, 37823U, 37823U, 37823U}
  },
  {
    0U, 160U, 320U, 640U, 656U, 1440U, 2880U, 5760U, 16000U
  },
  {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  },
  {
    {0U, 102U, 128U, 154U, 182U, 337U, 412U, 521U, 640U, 2048U}, {0U, 102U, 128U, 154U, 182U, 337U, 412U, 521U, 640U, 
    2048U}, {0U, 102U, 128U, 154U, 182U, 337U, 412U, 521U, 640U, 2048U}, {0U, 102U, 128U, 154U, 182U, 337U, 412U, 521U, 
    640U, 2048U}, {0U, 102U, 128U, 154U, 182U, 337U, 412U, 521U, 640U, 2048U}
  },
  {
    {16384U, 16384U, 16071U, 15540U, 14495U, 9349U, 6704U, 3116U, 0U, 0U}, {16384U, 16384U, 16071U, 15540U, 14495U, 
    9349U, 6704U, 3116U, 0U, 0U}, {16384U, 16384U, 16071U, 15540U, 14495U, 9349U, 6704U, 3116U, 0U, 0U}, {16384U, 16384U, 
    16071U, 15540U, 14495U, 9349U, 6704U, 3116U, 0U, 0U}, {16384U, 16384U, 16071U, 15540U, 14495U, 9349U, 6704U, 3116U, 
    0U, 0U}
  },
  {
    {0U, 102U, 128U, 154U, 182U, 337U, 412U, 521U, 640U, 2048U}, {0U, 102U, 128U, 154U, 182U, 337U, 412U, 521U, 640U, 
    2048U}, {0U, 102U, 128U, 154U, 182U, 337U, 412U, 521U, 640U, 2048U}, {0U, 102U, 128U, 154U, 182U, 337U, 412U, 521U, 
    640U, 2048U}, {0U, 102U, 128U, 154U, 182U, 337U, 412U, 521U, 640U, 2048U}
  },
  {
    {16384U, 16384U, 16071U, 15540U, 14495U, 9349U, 6704U, 3116U, 0U, 0U}, {16384U, 16384U, 16071U, 15540U, 14495U, 
    9349U, 6704U, 3116U, 0U, 0U}, {16384U, 16384U, 16071U, 15540U, 14495U, 9349U, 6704U, 3116U, 0U, 0U}, {16384U, 16384U, 
    16071U, 15540U, 14495U, 9349U, 6704U, 3116U, 0U, 0U}, {16384U, 16384U, 16071U, 15540U, 14495U, 9349U, 6704U, 3116U, 
    0U, 0U}
  },
  {
    0U, 38U, 38U, 51U, 64U, 64U, 64U, 64U
  },
  {
    {0U, 384U, 512U, 640U, 768U, 896U, 1024U, 2560U}, {0U, 384U, 512U, 640U, 768U, 896U, 1024U, 2560U}, {0U, 384U, 512U, 
    640U, 768U, 896U, 1024U, 2560U}, {0U, 384U, 512U, 640U, 768U, 896U, 1024U, 2560U}, {0U, 384U, 512U, 640U, 768U, 896U, 
    1024U, 2560U}
  },
  {
    {16384U, 16384U, 16384U, 9830U, 0U, 0U, 0U, 0U}, {16384U, 16384U, 16384U, 9830U, 0U, 0U, 0U, 0U}, {16384U, 16384U, 
    16384U, 9830U, 0U, 0U, 0U, 0U}, {16384U, 16384U, 16384U, 16384U, 16384U, 16384U, 16384U, 16384U}, {16384U, 16384U, 
    16384U, 16384U, 16384U, 16384U, 16384U, 16384U}
  },
  {
    0U, 82U, 82U, 205U, 492U, 492U, 492U, 492U
  },
  {
    {0U, 5120U, 6400U, 7680U, 8960U, 10240U, 11520U, 12800U}, {0U, 5120U, 6400U, 7680U, 8960U, 10240U, 11520U, 12800U}, {
    0U, 5120U, 6400U, 7680U, 8960U, 10240U, 11520U, 12800U}, {0U, 5120U, 6400U, 7680U, 8960U, 10240U, 11520U, 12800U}, {
    0U, 5120U, 6400U, 7680U, 8960U, 10240U, 11520U, 12800U}
  },
  {
    {16384U, 16384U, 13107U, 8192U, 4915U, 4915U, 4915U, 4915U}, {16384U, 16384U, 13107U, 8192U, 4915U, 4915U, 4915U, 
    4915U}, {16384U, 16384U, 13107U, 8192U, 4915U, 4915U, 4915U, 4915U}, {16384U, 16384U, 13107U, 11469U, 6554U, 6554U, 
    6554U, 6554U}, {16384U, 16384U, 13107U, 11469U, 6554U, 6554U, 6554U, 6554U}
  },
  {
    0U, 1280U, 3840U, 6400U, 10240U
  },
  {
    0U, 160U, 320U, 480U, 800U, 1280U, 7200U
  },
  {
    -6400, 0, 640, 1600, 3200, 6400, 8000, 25600
  },
  {
    {16384U, 16384U, 16384U, 16384U, 16384U, 16384U, 16384U, 16384U}, {16384U, 16384U, 13107U, 8192U, 4915U, 8192U, 
    11469U, 16384U}, {16384U, 16384U, 13107U, 8192U, 4915U, 4915U, 8192U, 16384U}, {16384U, 16384U, 13107U, 8192U, 4915U, 
    4915U, 8192U, 16384U}, {16384U, 16384U, 13107U, 13107U, 8192U, 8192U, 8192U, 16384U}, {16384U, 16384U, 16384U, 
    16384U, 16384U, 16384U, 16384U, 16384U}, {16384U, 16384U, 16384U, 16384U, 16384U, 16384U, 16384U, 16384U}
  },
  {
    16384U, 16384U, 16384U, 11469U, 11469U
  },
  {
    0U, 320U, 640U, 2560U, 3840U, 6400U, 7680U, 10240U
  }
};
CONST(Rte_Calprm_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP_Type, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_CalprmRom_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP = { /* PRQA S 3408 */ /* MD_Rte_3408 */
  0.2F,
  1.0F,
  -1.0F,
  1.0F,
  -1.0F,
  1.0F,
  -0.1F,
  0.1F,
  -0.1F,
  0.1F,
  {
    0U, 448U, 3008U, 3520U
  },
  {
    557U, 557U, 0U, 0U
  },
  {
    0U, 448U, 3008U, 3520U
  },
  {
    557U, 557U, 0U, 0U
  },
  {
    {0U, 89U, 179U, 357U, 715U, 1430U, 2860U, 5719U, 8936U}, {0U, 89U, 179U, 357U, 715U, 1430U, 2860U, 5719U, 8936U}, {
    0U, 89U, 179U, 357U, 715U, 1430U, 2860U, 5719U, 8936U}, {0U, 89U, 179U, 357U, 715U, 1430U, 2860U, 5719U, 8936U}, {0U, 
    89U, 179U, 357U, 715U, 1430U, 2860U, 5719U, 8936U}, {0U, 89U, 179U, 357U, 715U, 1430U, 2860U, 5719U, 8936U}, {0U, 
    89U, 179U, 357U, 715U, 1430U, 2860U, 5719U, 8936U}, {0U, 89U, 179U, 357U, 715U, 1430U, 2860U, 5719U, 8936U}, {0U, 
    89U, 179U, 357U, 715U, 1430U, 2860U, 5719U, 8936U}, {0U, 89U, 179U, 357U, 715U, 1430U, 2860U, 5719U, 8936U}, {0U, 
    89U, 179U, 357U, 715U, 1430U, 2860U, 5719U, 8936U}, {0U, 89U, 179U, 357U, 715U, 1430U, 2860U, 5719U, 8936U}
  },
  {
    {0U, 64U, 124U, 288U, 900U, 2456U, 5980U, 12288U, 12288U}, {0U, 64U, 124U, 288U, 900U, 2456U, 5980U, 12288U, 12288U}, 
    {0U, 64U, 124U, 288U, 900U, 2456U, 5980U, 12288U, 12288U}, {0U, 64U, 124U, 288U, 900U, 2456U, 5980U, 12288U, 12288U}, 
    {0U, 64U, 124U, 288U, 900U, 2456U, 5980U, 12288U, 12288U}, {0U, 64U, 124U, 288U, 900U, 2456U, 5980U, 12288U, 12288U}, 
    {0U, 64U, 124U, 288U, 900U, 2456U, 5980U, 12288U, 12288U}, {0U, 64U, 124U, 288U, 900U, 2456U, 5980U, 12288U, 12288U}, 
    {0U, 64U, 124U, 288U, 900U, 2456U, 5980U, 12288U, 12288U}, {0U, 64U, 124U, 288U, 900U, 2456U, 5980U, 12288U, 12288U}, 
    {0U, 64U, 124U, 288U, 900U, 2456U, 5980U, 12288U, 12288U}, {0U, 64U, 124U, 288U, 900U, 2456U, 5980U, 12288U, 12288U}
  },
  {
    {0U, 394U, 798U, 1204U, 1610U, 2009U, 2406U, 2834U, 29568U}, {0U, 394U, 798U, 1204U, 1610U, 2009U, 2406U, 2834U, 
    29568U}, {0U, 394U, 798U, 1204U, 1610U, 2009U, 2406U, 2834U, 29568U}, {0U, 394U, 798U, 1204U, 1610U, 2009U, 2406U, 
    2834U, 29568U}, {0U, 394U, 798U, 1204U, 1610U, 2009U, 2406U, 2834U, 29568U}, {0U, 394U, 798U, 1204U, 1610U, 2009U, 
    2406U, 2834U, 29568U}, {0U, 394U, 798U, 1204U, 1610U, 2009U, 2406U, 2834U, 29568U}, {0U, 394U, 798U, 1204U, 1610U, 
    2009U, 2406U, 2834U, 29568U}, {0U, 394U, 798U, 1204U, 1610U, 2009U, 2406U, 2834U, 29568U}, {0U, 394U, 798U, 1204U, 
    1610U, 2009U, 2406U, 2834U, 29568U}, {0U, 394U, 798U, 1204U, 1610U, 2009U, 2406U, 2834U, 29568U}, {0U, 394U, 798U, 
    1204U, 1610U, 2009U, 2406U, 2834U, 29568U}
  },
  {
    {32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U}, {32768U, 32768U, 32768U, 32768U, 32768U, 
    32768U, 32768U, 32768U, 32768U}, {32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U}, {32768U, 
    32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U}, {32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 
    32768U, 32768U, 32768U}, {32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U}, {32768U, 32768U, 
    32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U}, {32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 
    32768U, 32768U}, {32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U}, {32768U, 32768U, 32768U, 
    32768U, 32768U, 32768U, 32768U, 32768U, 32768U}, {32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 
    32768U}, {32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U}
  },
  {
    205U, 205U, 256U, 307U, 512U, 512U, 512U, 512U, 512U, 512U, 512U, 512U
  },
  {
    205U, 205U, 205U, 102U, 102U, 51U, 51U, 51U, 51U, 51U, 51U, 51U
  },
  {
    0U, 102U
  },
  {
    0U, 16384U
  },
  {
    0U, 16384U
  },
  {
    0U, 16384U
  },
  {
    0U, 1024U
  },
  {
    0U, 16384U
  },
  {
    0U, 2000U, 10000U, 18000U
  },
  {
    {164U, 164U, 164U, 164U}, {164U, 164U, 164U, 164U}, {164U, 164U, 164U, 164U}, {164U, 164U, 164U, 164U}, {164U, 164U, 
    164U, 164U}, {164U, 164U, 164U, 164U}, {164U, 164U, 164U, 164U}, {164U, 164U, 164U, 164U}, {164U, 164U, 164U, 164U}, {
    164U, 164U, 164U, 164U}, {164U, 164U, 164U, 164U}, {164U, 164U, 164U, 164U}
  },
  {
    10240U, 10240U, 5120U, 5120U, 3072U, 3072U, 2560U, 2560U, 2560U, 2560U, 2560U, 0U
  },
  {
    0U, 1280U, 5120U, 10240U, 25600U
  },
  {
    20480U, 20480U, 16384U, 4096U, 0U
  },
  {
    -10240, -8192, -4096, 0, 4096, 8192, 10240
  },
  {
    19661U, 19661U, 18022U, 16384U, 14746U, 13107U, 13107U
  },
  {
    {0U, 123U, 258U, 395U, 530U, 661U, 798U, 934U, 1069U, 1204U, 1335U, 1474U, 1610U, 1741U, 1874U, 2009U, 2145U, 2280U, 
    2406U, 2540U, 2675U, 2834U, 2957U, 29568U}, {0U, 124U, 258U, 394U, 528U, 664U, 798U, 932U, 1066U, 1201U, 1340U, 
    1472U, 1609U, 1744U, 1876U, 2014U, 2145U, 2277U, 2425U, 2543U, 2692U, 2834U, 2957U, 29568U}, {0U, 124U, 258U, 393U, 
    527U, 663U, 798U, 934U, 1067U, 1203U, 1339U, 1471U, 1608U, 1739U, 1878U, 2009U, 2145U, 2288U, 2421U, 2546U, 2676U, 
    2834U, 2957U, 29568U}, {0U, 124U, 259U, 392U, 529U, 664U, 798U, 934U, 1068U, 1202U, 1336U, 1472U, 1609U, 1743U, 
    1880U, 2009U, 2145U, 2277U, 2413U, 2548U, 2695U, 2815U, 2957U, 29568U}, {0U, 122U, 258U, 392U, 529U, 662U, 798U, 
    932U, 1068U, 1201U, 1339U, 1474U, 1607U, 1742U, 1880U, 2013U, 2145U, 2285U, 2418U, 2549U, 2691U, 2834U, 2957U, 29568U
    }, {0U, 123U, 257U, 392U, 527U, 664U, 798U, 934U, 1069U, 1204U, 1337U, 1472U, 1605U, 1741U, 1881U, 2009U, 2145U, 
    2280U, 2422U, 2549U, 2686U, 2826U, 2957U, 29568U}, {0U, 124U, 259U, 394U, 528U, 663U, 798U, 932U, 1069U, 1203U, 
    1336U, 1475U, 1608U, 1740U, 1874U, 2013U, 2145U, 2287U, 2411U, 2550U, 2682U, 2816U, 2957U, 29568U}, {0U, 123U, 258U, 
    394U, 528U, 662U, 798U, 934U, 1066U, 1203U, 1338U, 1473U, 1606U, 1744U, 1875U, 2009U, 2145U, 2282U, 2415U, 2551U, 
    2678U, 2834U, 2957U, 29568U}, {0U, 124U, 259U, 394U, 529U, 663U, 798U, 932U, 1067U, 1202U, 1337U, 1471U, 1609U, 
    1743U, 1876U, 2012U, 2145U, 2278U, 2419U, 2551U, 2698U, 2826U, 2957U, 29568U}, {0U, 122U, 258U, 394U, 527U, 662U, 
    798U, 934U, 1067U, 1202U, 1339U, 1473U, 1607U, 1742U, 1876U, 2009U, 2145U, 2284U, 2423U, 2552U, 2694U, 2817U, 2957U, 
    29568U}
  },
  {
    {0U, 512U, 1072U, 1632U, 2176U, 2688U, 3200U, 3680U, 4128U, 4544U, 4912U, 5264U, 5568U, 5824U, 6048U, 6240U, 6400U, 
    6528U, 6624U, 6704U, 6768U, 6832U, 6864U, 15712U}, {0U, 592U, 1232U, 1872U, 2496U, 3104U, 3680U, 4224U, 4736U, 5216U, 
    5664U, 6048U, 6400U, 6704U, 6960U, 7184U, 7360U, 7504U, 7632U, 7712U, 7792U, 7856U, 7904U, 18080U}, {0U, 672U, 1392U, 
    2112U, 2816U, 3504U, 4160U, 4784U, 5360U, 5904U, 6400U, 6832U, 7232U, 7568U, 7872U, 8112U, 8320U, 8496U, 8624U, 
    8720U, 8800U, 8880U, 8928U, 20432U}, {0U, 720U, 1504U, 2272U, 3040U, 3776U, 4480U, 5152U, 5776U, 6352U, 6880U, 7360U, 
    7792U, 8160U, 8480U, 8736U, 8960U, 9136U, 9280U, 9392U, 9488U, 9552U, 9616U, 22000U}, {0U, 736U, 1552U, 2352U, 3152U, 
    3904U, 4640U, 5328U, 5984U, 6576U, 7136U, 7632U, 8064U, 8448U, 8784U, 9056U, 9280U, 9472U, 9616U, 9728U, 9824U, 
    9904U, 9968U, 22784U}, {0U, 768U, 1600U, 2432U, 3248U, 4048U, 4800U, 5520U, 6192U, 6816U, 7376U, 7888U, 8336U, 8736U, 
    9088U, 9360U, 9600U, 9792U, 9952U, 10064U, 10160U, 10240U, 10304U, 23584U}, {0U, 800U, 1664U, 2528U, 3360U, 4176U, 
    4960U, 5696U, 6400U, 7040U, 7616U, 8160U, 8624U, 9024U, 9376U, 9680U, 9920U, 10128U, 10272U, 10400U, 10496U, 10576U, 
    10656U, 24368U}, {0U, 816U, 1712U, 2608U, 3472U, 4304U, 5120U, 5888U, 6592U, 7264U, 7872U, 8416U, 8896U, 9328U, 
    9680U, 9984U, 10240U, 10448U, 10608U, 10736U, 10832U, 10928U, 10992U, 25152U}, {0U, 848U, 1776U, 2688U, 3584U, 4448U, 
    5280U, 6064U, 6800U, 7488U, 8112U, 8672U, 9184U, 9616U, 9984U, 10304U, 10560U, 10768U, 10944U, 11072U, 11184U, 
    11264U, 11344U, 25936U}, {0U, 864U, 1824U, 2768U, 3680U, 4576U, 5440U, 6256U, 7008U, 7712U, 8368U, 8944U, 9456U, 
    9904U, 10288U, 10608U, 10880U, 11104U, 11280U, 11408U, 11520U, 11600U, 11680U, 26720U}
  },
  {
    0U, 1920U, 3840U, 7680U, 10240U, 12800U, 15360U, 19200U, 23040U, 28160U
  }
};
CONST(Rte_Calprm_CalRegn02Rt00_DEFAULT_RTE_CALPRM_GROUP_Type, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_CalprmRom_CalRegn02Rt00_DEFAULT_RTE_CALPRM_GROUP = { /* PRQA S 3408 */ /* MD_Rte_3408 */
  0.2F,
  500U
};
CONST(Rte_Calprm_CalRegn02Rt01GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_CalprmRom_CalRegn02Rt01GroupA_DEFAULT_RTE_CALPRM_GROUP = { /* PRQA S 3408 */ /* MD_Rte_3408 */
  0.4F,
  1.0F,
  10.0F,
  0.3F,
  500U,
  {
    {0U, 0U, 0U, 0U, 205U, 410U, 614U, 819U, 1024U}, {0U, 0U, 0U, 0U, 205U, 410U, 614U, 819U, 1024U}, {0U, 0U, 0U, 0U, 
    205U, 410U, 614U, 819U, 1024U}, {0U, 0U, 0U, 0U, 205U, 410U, 614U, 819U, 1024U}, {0U, 0U, 0U, 0U, 205U, 410U, 614U, 
    819U, 1024U}, {0U, 0U, 0U, 0U, 205U, 410U, 614U, 819U, 1024U}, {0U, 0U, 0U, 0U, 205U, 410U, 614U, 819U, 1024U}, {0U, 
    0U, 0U, 0U, 154U, 307U, 471U, 604U, 819U}, {0U, 0U, 0U, 0U, 20U, 41U, 61U, 82U, 102U}
  },
  {
    0U, 1280U, 2560U, 3840U, 5120U, 6400U, 7680U, 8960U, 10240U
  },
  {
    0U, 1200U, 2400U, 3600U, 4800U, 6000U, 7200U, 8400U, 9600U
  },
  {
    0U, 256U, 512U, 768U, 1024U, 1280U, 1536U, 1792U, 2048U, 2304U, 2560U
  },
  {
    32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 26214U, 19661U, 13107U, 6554U, 0U
  }
};
CONST(Rte_Calprm_CalRegn02Rt01GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_CalprmRom_CalRegn02Rt01GroupC_DEFAULT_RTE_CALPRM_GROUP = { /* PRQA S 3408 */ /* MD_Rte_3408 */
  FALSE,
  {
    {0U, 8960U, 10560U, 12160U, 13760U, 15360U, 18560U, 21760U, 24960U}, {0U, 8960U, 10560U, 12160U, 13760U, 15360U, 
    18560U, 21760U, 24960U}, {0U, 8960U, 10560U, 12160U, 13760U, 15360U, 18560U, 21760U, 24960U}, {0U, 8960U, 10560U, 
    12160U, 13760U, 15360U, 18560U, 21760U, 24960U}, {0U, 8960U, 10560U, 12160U, 13760U, 15360U, 18560U, 21760U, 24960U}, 
    {0U, 16000U, 17600U, 19200U, 20800U, 22400U, 25600U, 28800U, 32000U}, {0U, 20608U, 22208U, 23808U, 25408U, 27008U, 
    30208U, 33408U, 36608U}, {0U, 26112U, 27712U, 29312U, 30912U, 32512U, 35712U, 38912U, 42112U}
  },
  {
    {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 1037U, 4355U, 9735U, 16396U, 33177U, 33177U, 33177U}, {0U, 0U, 1152U, 
    4839U, 10817U, 18218U, 36863U, 36863U, 36863U}, {0U, 0U, 1152U, 4839U, 10817U, 18218U, 36863U, 36863U, 36863U}, {0U, 
    0U, 1152U, 4839U, 10817U, 18218U, 36863U, 36863U, 36863U}
  },
  {
    {0U, 384U, 512U, 640U, 768U, 896U, 1024U, 2560U}, {0U, 384U, 512U, 640U, 768U, 896U, 1024U, 2560U}, {0U, 384U, 512U, 
    640U, 768U, 896U, 1024U, 2560U}, {0U, 384U, 512U, 640U, 768U, 896U, 1024U, 2560U}, {0U, 384U, 512U, 640U, 768U, 896U, 
    1024U, 2560U}
  },
  {
    {16384U, 16384U, 16384U, 16384U, 0U, 0U, 0U, 0U}, {16384U, 16384U, 16384U, 16384U, 0U, 0U, 0U, 0U}, {16384U, 16384U, 
    16384U, 16384U, 0U, 0U, 0U, 0U}, {16384U, 16384U, 16384U, 16384U, 0U, 0U, 0U, 0U}, {16384U, 16384U, 16384U, 16384U, 
    0U, 0U, 0U, 0U}
  },
  {
    {0U, 261U, 451U, 776U, 994U, 1220U, 1441U, 1767U, 7200U, 7216U, 7232U, 7248U}, {0U, 261U, 451U, 776U, 994U, 1220U, 
    1441U, 1767U, 7200U, 7216U, 7232U, 7248U}, {0U, 261U, 451U, 776U, 994U, 1220U, 1441U, 1767U, 7200U, 7216U, 7232U, 
    7248U}, {0U, 261U, 451U, 776U, 994U, 1220U, 1441U, 1767U, 7200U, 7216U, 7232U, 7248U}, {0U, 261U, 451U, 776U, 994U, 
    1220U, 1441U, 1767U, 7200U, 7216U, 7232U, 7248U}, {0U, 261U, 451U, 776U, 994U, 1220U, 1441U, 1767U, 7200U, 7216U, 
    7232U, 7248U}, {0U, 261U, 451U, 776U, 994U, 1220U, 1441U, 1767U, 7200U, 7216U, 7232U, 7248U}, {0U, 261U, 451U, 776U, 
    994U, 1220U, 1441U, 1767U, 7200U, 7216U, 7232U, 7248U}
  },
  {
    {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 1788U, 3385U, 5353U, 6805U, 8089U, 8953U, 9259U, 9259U, 9259U, 
    9259U, 9259U}, {0U, 2446U, 4630U, 7323U, 9309U, 11066U, 12247U, 12666U, 12666U, 12666U, 12666U, 12666U}, {0U, 3090U, 
    5849U, 9249U, 11759U, 13978U, 15470U, 16000U, 16000U, 16000U, 16000U, 16000U}, {0U, 3708U, 7019U, 11099U, 14111U, 
    16774U, 18564U, 19200U, 19200U, 19200U, 19200U, 19200U}, {0U, 5340U, 10108U, 15983U, 20320U, 24155U, 26732U, 27648U, 
    27648U, 27648U, 27648U, 27648U}, {0U, 6408U, 12130U, 19180U, 24384U, 28986U, 32078U, 33178U, 33178U, 33178U, 33178U, 
    33178U}, {0U, 7306U, 13828U, 21865U, 27798U, 33044U, 36569U, 37823U, 37823U, 37823U, 37823U, 37823U}
  },
  {
    0U, 160U, 320U, 640U, 656U, 1440U, 2880U, 5760U, 16000U
  },
  {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  },
  {
    {0U, 102U, 128U, 154U, 182U, 337U, 412U, 521U, 640U, 2048U}, {0U, 102U, 128U, 154U, 182U, 337U, 412U, 521U, 640U, 
    2048U}, {0U, 102U, 128U, 154U, 182U, 337U, 412U, 521U, 640U, 2048U}, {0U, 102U, 128U, 154U, 182U, 337U, 412U, 521U, 
    640U, 2048U}, {0U, 102U, 128U, 154U, 182U, 337U, 412U, 521U, 640U, 2048U}
  },
  {
    {16384U, 16384U, 16071U, 15540U, 14495U, 9349U, 6704U, 3116U, 0U, 0U}, {16384U, 16384U, 16071U, 15540U, 14495U, 
    9349U, 6704U, 3116U, 0U, 0U}, {16384U, 16384U, 16071U, 15540U, 14495U, 9349U, 6704U, 3116U, 0U, 0U}, {16384U, 16384U, 
    16071U, 15540U, 14495U, 9349U, 6704U, 3116U, 0U, 0U}, {16384U, 16384U, 16071U, 15540U, 14495U, 9349U, 6704U, 3116U, 
    0U, 0U}
  },
  {
    {0U, 102U, 128U, 154U, 182U, 337U, 412U, 521U, 640U, 2048U}, {0U, 102U, 128U, 154U, 182U, 337U, 412U, 521U, 640U, 
    2048U}, {0U, 102U, 128U, 154U, 182U, 337U, 412U, 521U, 640U, 2048U}, {0U, 102U, 128U, 154U, 182U, 337U, 412U, 521U, 
    640U, 2048U}, {0U, 102U, 128U, 154U, 182U, 337U, 412U, 521U, 640U, 2048U}
  },
  {
    {16384U, 16384U, 16071U, 15540U, 14495U, 9349U, 6704U, 3116U, 0U, 0U}, {16384U, 16384U, 16071U, 15540U, 14495U, 
    9349U, 6704U, 3116U, 0U, 0U}, {16384U, 16384U, 16071U, 15540U, 14495U, 9349U, 6704U, 3116U, 0U, 0U}, {16384U, 16384U, 
    16071U, 15540U, 14495U, 9349U, 6704U, 3116U, 0U, 0U}, {16384U, 16384U, 16071U, 15540U, 14495U, 9349U, 6704U, 3116U, 
    0U, 0U}
  },
  {
    0U, 38U, 38U, 51U, 64U, 64U, 64U, 64U
  },
  {
    {0U, 384U, 512U, 640U, 768U, 896U, 1024U, 2560U}, {0U, 384U, 512U, 640U, 768U, 896U, 1024U, 2560U}, {0U, 384U, 512U, 
    640U, 768U, 896U, 1024U, 2560U}, {0U, 384U, 512U, 640U, 768U, 896U, 1024U, 2560U}, {0U, 384U, 512U, 640U, 768U, 896U, 
    1024U, 2560U}
  },
  {
    {16384U, 16384U, 16384U, 9830U, 0U, 0U, 0U, 0U}, {16384U, 16384U, 16384U, 9830U, 0U, 0U, 0U, 0U}, {16384U, 16384U, 
    16384U, 9830U, 0U, 0U, 0U, 0U}, {16384U, 16384U, 16384U, 16384U, 16384U, 16384U, 16384U, 16384U}, {16384U, 16384U, 
    16384U, 16384U, 16384U, 16384U, 16384U, 16384U}
  },
  {
    0U, 82U, 82U, 205U, 492U, 492U, 492U, 492U
  },
  {
    {0U, 5120U, 6400U, 7680U, 8960U, 10240U, 11520U, 12800U}, {0U, 5120U, 6400U, 7680U, 8960U, 10240U, 11520U, 12800U}, {
    0U, 5120U, 6400U, 7680U, 8960U, 10240U, 11520U, 12800U}, {0U, 5120U, 6400U, 7680U, 8960U, 10240U, 11520U, 12800U}, {
    0U, 5120U, 6400U, 7680U, 8960U, 10240U, 11520U, 12800U}
  },
  {
    {16384U, 16384U, 13107U, 8192U, 4915U, 4915U, 4915U, 4915U}, {16384U, 16384U, 13107U, 8192U, 4915U, 4915U, 4915U, 
    4915U}, {16384U, 16384U, 13107U, 8192U, 4915U, 4915U, 4915U, 4915U}, {16384U, 16384U, 13107U, 11469U, 6554U, 6554U, 
    6554U, 6554U}, {16384U, 16384U, 13107U, 11469U, 6554U, 6554U, 6554U, 6554U}
  },
  {
    0U, 1280U, 3840U, 6400U, 10240U
  },
  {
    0U, 160U, 320U, 480U, 800U, 1280U, 7200U
  },
  {
    -6400, 0, 640, 1600, 3200, 6400, 8000, 25600
  },
  {
    {16384U, 16384U, 16384U, 16384U, 16384U, 16384U, 16384U, 16384U}, {16384U, 16384U, 13107U, 8192U, 4915U, 8192U, 
    11469U, 16384U}, {16384U, 16384U, 13107U, 8192U, 4915U, 4915U, 8192U, 16384U}, {16384U, 16384U, 13107U, 8192U, 4915U, 
    4915U, 8192U, 16384U}, {16384U, 16384U, 13107U, 13107U, 8192U, 8192U, 8192U, 16384U}, {16384U, 16384U, 16384U, 
    16384U, 16384U, 16384U, 16384U, 16384U}, {16384U, 16384U, 16384U, 16384U, 16384U, 16384U, 16384U, 16384U}
  },
  {
    16384U, 16384U, 16384U, 11469U, 11469U
  },
  {
    0U, 320U, 640U, 2560U, 3840U, 6400U, 7680U, 10240U
  }
};
CONST(Rte_Calprm_CalRegn02Rt01GroupD_DEFAULT_RTE_CALPRM_GROUP_Type, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_CalprmRom_CalRegn02Rt01GroupD_DEFAULT_RTE_CALPRM_GROUP = { /* PRQA S 3408 */ /* MD_Rte_3408 */
  0.2F,
  1.0F,
  -1.0F,
  1.0F,
  -1.0F,
  1.0F,
  -0.1F,
  0.1F,
  -0.1F,
  0.1F,
  {
    0U, 448U, 3008U, 3520U
  },
  {
    557U, 557U, 0U, 0U
  },
  {
    0U, 448U, 3008U, 3520U
  },
  {
    557U, 557U, 0U, 0U
  },
  {
    {0U, 89U, 179U, 357U, 715U, 1430U, 2860U, 5719U, 8936U}, {0U, 89U, 179U, 357U, 715U, 1430U, 2860U, 5719U, 8936U}, {
    0U, 89U, 179U, 357U, 715U, 1430U, 2860U, 5719U, 8936U}, {0U, 89U, 179U, 357U, 715U, 1430U, 2860U, 5719U, 8936U}, {0U, 
    89U, 179U, 357U, 715U, 1430U, 2860U, 5719U, 8936U}, {0U, 89U, 179U, 357U, 715U, 1430U, 2860U, 5719U, 8936U}, {0U, 
    89U, 179U, 357U, 715U, 1430U, 2860U, 5719U, 8936U}, {0U, 89U, 179U, 357U, 715U, 1430U, 2860U, 5719U, 8936U}, {0U, 
    89U, 179U, 357U, 715U, 1430U, 2860U, 5719U, 8936U}, {0U, 89U, 179U, 357U, 715U, 1430U, 2860U, 5719U, 8936U}, {0U, 
    89U, 179U, 357U, 715U, 1430U, 2860U, 5719U, 8936U}, {0U, 89U, 179U, 357U, 715U, 1430U, 2860U, 5719U, 8936U}
  },
  {
    {0U, 64U, 124U, 288U, 900U, 2456U, 5980U, 12288U, 12288U}, {0U, 64U, 124U, 288U, 900U, 2456U, 5980U, 12288U, 12288U}, 
    {0U, 64U, 124U, 288U, 900U, 2456U, 5980U, 12288U, 12288U}, {0U, 64U, 124U, 288U, 900U, 2456U, 5980U, 12288U, 12288U}, 
    {0U, 64U, 124U, 288U, 900U, 2456U, 5980U, 12288U, 12288U}, {0U, 64U, 124U, 288U, 900U, 2456U, 5980U, 12288U, 12288U}, 
    {0U, 64U, 124U, 288U, 900U, 2456U, 5980U, 12288U, 12288U}, {0U, 64U, 124U, 288U, 900U, 2456U, 5980U, 12288U, 12288U}, 
    {0U, 64U, 124U, 288U, 900U, 2456U, 5980U, 12288U, 12288U}, {0U, 64U, 124U, 288U, 900U, 2456U, 5980U, 12288U, 12288U}, 
    {0U, 64U, 124U, 288U, 900U, 2456U, 5980U, 12288U, 12288U}, {0U, 64U, 124U, 288U, 900U, 2456U, 5980U, 12288U, 12288U}
  },
  {
    {0U, 394U, 798U, 1204U, 1610U, 2009U, 2406U, 2834U, 29568U}, {0U, 394U, 798U, 1204U, 1610U, 2009U, 2406U, 2834U, 
    29568U}, {0U, 394U, 798U, 1204U, 1610U, 2009U, 2406U, 2834U, 29568U}, {0U, 394U, 798U, 1204U, 1610U, 2009U, 2406U, 
    2834U, 29568U}, {0U, 394U, 798U, 1204U, 1610U, 2009U, 2406U, 2834U, 29568U}, {0U, 394U, 798U, 1204U, 1610U, 2009U, 
    2406U, 2834U, 29568U}, {0U, 394U, 798U, 1204U, 1610U, 2009U, 2406U, 2834U, 29568U}, {0U, 394U, 798U, 1204U, 1610U, 
    2009U, 2406U, 2834U, 29568U}, {0U, 394U, 798U, 1204U, 1610U, 2009U, 2406U, 2834U, 29568U}, {0U, 394U, 798U, 1204U, 
    1610U, 2009U, 2406U, 2834U, 29568U}, {0U, 394U, 798U, 1204U, 1610U, 2009U, 2406U, 2834U, 29568U}, {0U, 394U, 798U, 
    1204U, 1610U, 2009U, 2406U, 2834U, 29568U}
  },
  {
    {32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U}, {32768U, 32768U, 32768U, 32768U, 32768U, 
    32768U, 32768U, 32768U, 32768U}, {32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U}, {32768U, 
    32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U}, {32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 
    32768U, 32768U, 32768U}, {32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U}, {32768U, 32768U, 
    32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U}, {32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 
    32768U, 32768U}, {32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U}, {32768U, 32768U, 32768U, 
    32768U, 32768U, 32768U, 32768U, 32768U, 32768U}, {32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 
    32768U}, {32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U}
  },
  {
    205U, 205U, 256U, 307U, 512U, 512U, 512U, 512U, 512U, 512U, 512U, 512U
  },
  {
    205U, 205U, 205U, 102U, 102U, 51U, 51U, 51U, 51U, 51U, 51U, 51U
  },
  {
    0U, 102U
  },
  {
    0U, 16384U
  },
  {
    0U, 16384U
  },
  {
    0U, 16384U
  },
  {
    0U, 1024U
  },
  {
    0U, 16384U
  },
  {
    0U, 2000U, 10000U, 18000U
  },
  {
    {164U, 164U, 164U, 164U}, {164U, 164U, 164U, 164U}, {164U, 164U, 164U, 164U}, {164U, 164U, 164U, 164U}, {164U, 164U, 
    164U, 164U}, {164U, 164U, 164U, 164U}, {164U, 164U, 164U, 164U}, {164U, 164U, 164U, 164U}, {164U, 164U, 164U, 164U}, {
    164U, 164U, 164U, 164U}, {164U, 164U, 164U, 164U}, {164U, 164U, 164U, 164U}
  },
  {
    10240U, 10240U, 5120U, 5120U, 3072U, 3072U, 2560U, 2560U, 2560U, 2560U, 2560U, 0U
  },
  {
    0U, 1280U, 5120U, 10240U, 25600U
  },
  {
    20480U, 20480U, 16384U, 4096U, 0U
  },
  {
    -10240, -8192, -4096, 0, 4096, 8192, 10240
  },
  {
    19661U, 19661U, 18022U, 16384U, 14746U, 13107U, 13107U
  },
  {
    {0U, 123U, 258U, 395U, 530U, 661U, 798U, 934U, 1069U, 1204U, 1335U, 1474U, 1610U, 1741U, 1874U, 2009U, 2145U, 2280U, 
    2406U, 2540U, 2675U, 2834U, 2957U, 29568U}, {0U, 124U, 258U, 394U, 528U, 664U, 798U, 932U, 1066U, 1201U, 1340U, 
    1472U, 1609U, 1744U, 1876U, 2014U, 2145U, 2277U, 2425U, 2543U, 2692U, 2834U, 2957U, 29568U}, {0U, 124U, 258U, 393U, 
    527U, 663U, 798U, 934U, 1067U, 1203U, 1339U, 1471U, 1608U, 1739U, 1878U, 2009U, 2145U, 2288U, 2421U, 2546U, 2676U, 
    2834U, 2957U, 29568U}, {0U, 124U, 259U, 392U, 529U, 664U, 798U, 934U, 1068U, 1202U, 1336U, 1472U, 1609U, 1743U, 
    1880U, 2009U, 2145U, 2277U, 2413U, 2548U, 2695U, 2815U, 2957U, 29568U}, {0U, 122U, 258U, 392U, 529U, 662U, 798U, 
    932U, 1068U, 1201U, 1339U, 1474U, 1607U, 1742U, 1880U, 2013U, 2145U, 2285U, 2418U, 2549U, 2691U, 2834U, 2957U, 29568U
    }, {0U, 123U, 257U, 392U, 527U, 664U, 798U, 934U, 1069U, 1204U, 1337U, 1472U, 1605U, 1741U, 1881U, 2009U, 2145U, 
    2280U, 2422U, 2549U, 2686U, 2826U, 2957U, 29568U}, {0U, 124U, 259U, 394U, 528U, 663U, 798U, 932U, 1069U, 1203U, 
    1336U, 1475U, 1608U, 1740U, 1874U, 2013U, 2145U, 2287U, 2411U, 2550U, 2682U, 2816U, 2957U, 29568U}, {0U, 123U, 258U, 
    394U, 528U, 662U, 798U, 934U, 1066U, 1203U, 1338U, 1473U, 1606U, 1744U, 1875U, 2009U, 2145U, 2282U, 2415U, 2551U, 
    2678U, 2834U, 2957U, 29568U}, {0U, 124U, 259U, 394U, 529U, 663U, 798U, 932U, 1067U, 1202U, 1337U, 1471U, 1609U, 
    1743U, 1876U, 2012U, 2145U, 2278U, 2419U, 2551U, 2698U, 2826U, 2957U, 29568U}, {0U, 122U, 258U, 394U, 527U, 662U, 
    798U, 934U, 1067U, 1202U, 1339U, 1473U, 1607U, 1742U, 1876U, 2009U, 2145U, 2284U, 2423U, 2552U, 2694U, 2817U, 2957U, 
    29568U}
  },
  {
    {0U, 512U, 1072U, 1632U, 2176U, 2688U, 3200U, 3680U, 4128U, 4544U, 4912U, 5264U, 5568U, 5824U, 6048U, 6240U, 6400U, 
    6528U, 6624U, 6704U, 6768U, 6832U, 6864U, 15712U}, {0U, 592U, 1232U, 1872U, 2496U, 3104U, 3680U, 4224U, 4736U, 5216U, 
    5664U, 6048U, 6400U, 6704U, 6960U, 7184U, 7360U, 7504U, 7632U, 7712U, 7792U, 7856U, 7904U, 18080U}, {0U, 672U, 1392U, 
    2112U, 2816U, 3504U, 4160U, 4784U, 5360U, 5904U, 6400U, 6832U, 7232U, 7568U, 7872U, 8112U, 8320U, 8496U, 8624U, 
    8720U, 8800U, 8880U, 8928U, 20432U}, {0U, 720U, 1504U, 2272U, 3040U, 3776U, 4480U, 5152U, 5776U, 6352U, 6880U, 7360U, 
    7792U, 8160U, 8480U, 8736U, 8960U, 9136U, 9280U, 9392U, 9488U, 9552U, 9616U, 22000U}, {0U, 736U, 1552U, 2352U, 3152U, 
    3904U, 4640U, 5328U, 5984U, 6576U, 7136U, 7632U, 8064U, 8448U, 8784U, 9056U, 9280U, 9472U, 9616U, 9728U, 9824U, 
    9904U, 9968U, 22784U}, {0U, 768U, 1600U, 2432U, 3248U, 4048U, 4800U, 5520U, 6192U, 6816U, 7376U, 7888U, 8336U, 8736U, 
    9088U, 9360U, 9600U, 9792U, 9952U, 10064U, 10160U, 10240U, 10304U, 23584U}, {0U, 800U, 1664U, 2528U, 3360U, 4176U, 
    4960U, 5696U, 6400U, 7040U, 7616U, 8160U, 8624U, 9024U, 9376U, 9680U, 9920U, 10128U, 10272U, 10400U, 10496U, 10576U, 
    10656U, 24368U}, {0U, 816U, 1712U, 2608U, 3472U, 4304U, 5120U, 5888U, 6592U, 7264U, 7872U, 8416U, 8896U, 9328U, 
    9680U, 9984U, 10240U, 10448U, 10608U, 10736U, 10832U, 10928U, 10992U, 25152U}, {0U, 848U, 1776U, 2688U, 3584U, 4448U, 
    5280U, 6064U, 6800U, 7488U, 8112U, 8672U, 9184U, 9616U, 9984U, 10304U, 10560U, 10768U, 10944U, 11072U, 11184U, 
    11264U, 11344U, 25936U}, {0U, 864U, 1824U, 2768U, 3680U, 4576U, 5440U, 6256U, 7008U, 7712U, 8368U, 8944U, 9456U, 
    9904U, 10288U, 10608U, 10880U, 11104U, 11280U, 11408U, 11520U, 11600U, 11680U, 26720U}
  },
  {
    0U, 1920U, 3840U, 7680U, 10240U, 12800U, 15360U, 19200U, 23040U, 28160U
  }
};
CONST(Rte_Calprm_CalRegn02Rt01_DEFAULT_RTE_CALPRM_GROUP_Type, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_CalprmRom_CalRegn02Rt01_DEFAULT_RTE_CALPRM_GROUP = { /* PRQA S 3408 */ /* MD_Rte_3408 */
  0.2F,
  500U
};
CONST(Rte_Calprm_CalRegn02Rt02GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_CalprmRom_CalRegn02Rt02GroupA_DEFAULT_RTE_CALPRM_GROUP = { /* PRQA S 3408 */ /* MD_Rte_3408 */
  0.4F,
  1.0F,
  10.0F,
  0.3F,
  500U,
  {
    {0U, 0U, 0U, 0U, 205U, 410U, 614U, 819U, 1024U}, {0U, 0U, 0U, 0U, 205U, 410U, 614U, 819U, 1024U}, {0U, 0U, 0U, 0U, 
    205U, 410U, 614U, 819U, 1024U}, {0U, 0U, 0U, 0U, 205U, 410U, 614U, 819U, 1024U}, {0U, 0U, 0U, 0U, 205U, 410U, 614U, 
    819U, 1024U}, {0U, 0U, 0U, 0U, 205U, 410U, 614U, 819U, 1024U}, {0U, 0U, 0U, 0U, 205U, 410U, 614U, 819U, 1024U}, {0U, 
    0U, 0U, 0U, 154U, 307U, 471U, 604U, 819U}, {0U, 0U, 0U, 0U, 20U, 41U, 61U, 82U, 102U}
  },
  {
    0U, 1280U, 2560U, 3840U, 5120U, 6400U, 7680U, 8960U, 10240U
  },
  {
    0U, 1200U, 2400U, 3600U, 4800U, 6000U, 7200U, 8400U, 9600U
  },
  {
    0U, 256U, 512U, 768U, 1024U, 1280U, 1536U, 1792U, 2048U, 2304U, 2560U
  },
  {
    32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 26214U, 19661U, 13107U, 6554U, 0U
  }
};
CONST(Rte_Calprm_CalRegn02Rt02GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_CalprmRom_CalRegn02Rt02GroupC_DEFAULT_RTE_CALPRM_GROUP = { /* PRQA S 3408 */ /* MD_Rte_3408 */
  FALSE,
  {
    {0U, 8960U, 10560U, 12160U, 13760U, 15360U, 18560U, 21760U, 24960U}, {0U, 8960U, 10560U, 12160U, 13760U, 15360U, 
    18560U, 21760U, 24960U}, {0U, 8960U, 10560U, 12160U, 13760U, 15360U, 18560U, 21760U, 24960U}, {0U, 8960U, 10560U, 
    12160U, 13760U, 15360U, 18560U, 21760U, 24960U}, {0U, 8960U, 10560U, 12160U, 13760U, 15360U, 18560U, 21760U, 24960U}, 
    {0U, 16000U, 17600U, 19200U, 20800U, 22400U, 25600U, 28800U, 32000U}, {0U, 20608U, 22208U, 23808U, 25408U, 27008U, 
    30208U, 33408U, 36608U}, {0U, 26112U, 27712U, 29312U, 30912U, 32512U, 35712U, 38912U, 42112U}
  },
  {
    {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 1037U, 4355U, 9735U, 16396U, 33177U, 33177U, 33177U}, {0U, 0U, 1152U, 
    4839U, 10817U, 18218U, 36863U, 36863U, 36863U}, {0U, 0U, 1152U, 4839U, 10817U, 18218U, 36863U, 36863U, 36863U}, {0U, 
    0U, 1152U, 4839U, 10817U, 18218U, 36863U, 36863U, 36863U}
  },
  {
    {0U, 384U, 512U, 640U, 768U, 896U, 1024U, 2560U}, {0U, 384U, 512U, 640U, 768U, 896U, 1024U, 2560U}, {0U, 384U, 512U, 
    640U, 768U, 896U, 1024U, 2560U}, {0U, 384U, 512U, 640U, 768U, 896U, 1024U, 2560U}, {0U, 384U, 512U, 640U, 768U, 896U, 
    1024U, 2560U}
  },
  {
    {16384U, 16384U, 16384U, 16384U, 0U, 0U, 0U, 0U}, {16384U, 16384U, 16384U, 16384U, 0U, 0U, 0U, 0U}, {16384U, 16384U, 
    16384U, 16384U, 0U, 0U, 0U, 0U}, {16384U, 16384U, 16384U, 16384U, 0U, 0U, 0U, 0U}, {16384U, 16384U, 16384U, 16384U, 
    0U, 0U, 0U, 0U}
  },
  {
    {0U, 261U, 451U, 776U, 994U, 1220U, 1441U, 1767U, 7200U, 7216U, 7232U, 7248U}, {0U, 261U, 451U, 776U, 994U, 1220U, 
    1441U, 1767U, 7200U, 7216U, 7232U, 7248U}, {0U, 261U, 451U, 776U, 994U, 1220U, 1441U, 1767U, 7200U, 7216U, 7232U, 
    7248U}, {0U, 261U, 451U, 776U, 994U, 1220U, 1441U, 1767U, 7200U, 7216U, 7232U, 7248U}, {0U, 261U, 451U, 776U, 994U, 
    1220U, 1441U, 1767U, 7200U, 7216U, 7232U, 7248U}, {0U, 261U, 451U, 776U, 994U, 1220U, 1441U, 1767U, 7200U, 7216U, 
    7232U, 7248U}, {0U, 261U, 451U, 776U, 994U, 1220U, 1441U, 1767U, 7200U, 7216U, 7232U, 7248U}, {0U, 261U, 451U, 776U, 
    994U, 1220U, 1441U, 1767U, 7200U, 7216U, 7232U, 7248U}
  },
  {
    {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 1788U, 3385U, 5353U, 6805U, 8089U, 8953U, 9259U, 9259U, 9259U, 
    9259U, 9259U}, {0U, 2446U, 4630U, 7323U, 9309U, 11066U, 12247U, 12666U, 12666U, 12666U, 12666U, 12666U}, {0U, 3090U, 
    5849U, 9249U, 11759U, 13978U, 15470U, 16000U, 16000U, 16000U, 16000U, 16000U}, {0U, 3708U, 7019U, 11099U, 14111U, 
    16774U, 18564U, 19200U, 19200U, 19200U, 19200U, 19200U}, {0U, 5340U, 10108U, 15983U, 20320U, 24155U, 26732U, 27648U, 
    27648U, 27648U, 27648U, 27648U}, {0U, 6408U, 12130U, 19180U, 24384U, 28986U, 32078U, 33178U, 33178U, 33178U, 33178U, 
    33178U}, {0U, 7306U, 13828U, 21865U, 27798U, 33044U, 36569U, 37823U, 37823U, 37823U, 37823U, 37823U}
  },
  {
    0U, 160U, 320U, 640U, 656U, 1440U, 2880U, 5760U, 16000U
  },
  {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  },
  {
    {0U, 102U, 128U, 154U, 182U, 337U, 412U, 521U, 640U, 2048U}, {0U, 102U, 128U, 154U, 182U, 337U, 412U, 521U, 640U, 
    2048U}, {0U, 102U, 128U, 154U, 182U, 337U, 412U, 521U, 640U, 2048U}, {0U, 102U, 128U, 154U, 182U, 337U, 412U, 521U, 
    640U, 2048U}, {0U, 102U, 128U, 154U, 182U, 337U, 412U, 521U, 640U, 2048U}
  },
  {
    {16384U, 16384U, 16071U, 15540U, 14495U, 9349U, 6704U, 3116U, 0U, 0U}, {16384U, 16384U, 16071U, 15540U, 14495U, 
    9349U, 6704U, 3116U, 0U, 0U}, {16384U, 16384U, 16071U, 15540U, 14495U, 9349U, 6704U, 3116U, 0U, 0U}, {16384U, 16384U, 
    16071U, 15540U, 14495U, 9349U, 6704U, 3116U, 0U, 0U}, {16384U, 16384U, 16071U, 15540U, 14495U, 9349U, 6704U, 3116U, 
    0U, 0U}
  },
  {
    {0U, 102U, 128U, 154U, 182U, 337U, 412U, 521U, 640U, 2048U}, {0U, 102U, 128U, 154U, 182U, 337U, 412U, 521U, 640U, 
    2048U}, {0U, 102U, 128U, 154U, 182U, 337U, 412U, 521U, 640U, 2048U}, {0U, 102U, 128U, 154U, 182U, 337U, 412U, 521U, 
    640U, 2048U}, {0U, 102U, 128U, 154U, 182U, 337U, 412U, 521U, 640U, 2048U}
  },
  {
    {16384U, 16384U, 16071U, 15540U, 14495U, 9349U, 6704U, 3116U, 0U, 0U}, {16384U, 16384U, 16071U, 15540U, 14495U, 
    9349U, 6704U, 3116U, 0U, 0U}, {16384U, 16384U, 16071U, 15540U, 14495U, 9349U, 6704U, 3116U, 0U, 0U}, {16384U, 16384U, 
    16071U, 15540U, 14495U, 9349U, 6704U, 3116U, 0U, 0U}, {16384U, 16384U, 16071U, 15540U, 14495U, 9349U, 6704U, 3116U, 
    0U, 0U}
  },
  {
    0U, 38U, 38U, 51U, 64U, 64U, 64U, 64U
  },
  {
    {0U, 384U, 512U, 640U, 768U, 896U, 1024U, 2560U}, {0U, 384U, 512U, 640U, 768U, 896U, 1024U, 2560U}, {0U, 384U, 512U, 
    640U, 768U, 896U, 1024U, 2560U}, {0U, 384U, 512U, 640U, 768U, 896U, 1024U, 2560U}, {0U, 384U, 512U, 640U, 768U, 896U, 
    1024U, 2560U}
  },
  {
    {16384U, 16384U, 16384U, 9830U, 0U, 0U, 0U, 0U}, {16384U, 16384U, 16384U, 9830U, 0U, 0U, 0U, 0U}, {16384U, 16384U, 
    16384U, 9830U, 0U, 0U, 0U, 0U}, {16384U, 16384U, 16384U, 16384U, 16384U, 16384U, 16384U, 16384U}, {16384U, 16384U, 
    16384U, 16384U, 16384U, 16384U, 16384U, 16384U}
  },
  {
    0U, 82U, 82U, 205U, 492U, 492U, 492U, 492U
  },
  {
    {0U, 5120U, 6400U, 7680U, 8960U, 10240U, 11520U, 12800U}, {0U, 5120U, 6400U, 7680U, 8960U, 10240U, 11520U, 12800U}, {
    0U, 5120U, 6400U, 7680U, 8960U, 10240U, 11520U, 12800U}, {0U, 5120U, 6400U, 7680U, 8960U, 10240U, 11520U, 12800U}, {
    0U, 5120U, 6400U, 7680U, 8960U, 10240U, 11520U, 12800U}
  },
  {
    {16384U, 16384U, 13107U, 8192U, 4915U, 4915U, 4915U, 4915U}, {16384U, 16384U, 13107U, 8192U, 4915U, 4915U, 4915U, 
    4915U}, {16384U, 16384U, 13107U, 8192U, 4915U, 4915U, 4915U, 4915U}, {16384U, 16384U, 13107U, 11469U, 6554U, 6554U, 
    6554U, 6554U}, {16384U, 16384U, 13107U, 11469U, 6554U, 6554U, 6554U, 6554U}
  },
  {
    0U, 1280U, 3840U, 6400U, 10240U
  },
  {
    0U, 160U, 320U, 480U, 800U, 1280U, 7200U
  },
  {
    -6400, 0, 640, 1600, 3200, 6400, 8000, 25600
  },
  {
    {16384U, 16384U, 16384U, 16384U, 16384U, 16384U, 16384U, 16384U}, {16384U, 16384U, 13107U, 8192U, 4915U, 8192U, 
    11469U, 16384U}, {16384U, 16384U, 13107U, 8192U, 4915U, 4915U, 8192U, 16384U}, {16384U, 16384U, 13107U, 8192U, 4915U, 
    4915U, 8192U, 16384U}, {16384U, 16384U, 13107U, 13107U, 8192U, 8192U, 8192U, 16384U}, {16384U, 16384U, 16384U, 
    16384U, 16384U, 16384U, 16384U, 16384U}, {16384U, 16384U, 16384U, 16384U, 16384U, 16384U, 16384U, 16384U}
  },
  {
    16384U, 16384U, 16384U, 11469U, 11469U
  },
  {
    0U, 320U, 640U, 2560U, 3840U, 6400U, 7680U, 10240U
  }
};
CONST(Rte_Calprm_CalRegn02Rt02GroupD_DEFAULT_RTE_CALPRM_GROUP_Type, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_CalprmRom_CalRegn02Rt02GroupD_DEFAULT_RTE_CALPRM_GROUP = { /* PRQA S 3408 */ /* MD_Rte_3408 */
  0.2F,
  1.0F,
  -1.0F,
  1.0F,
  -1.0F,
  1.0F,
  -0.1F,
  0.1F,
  -0.1F,
  0.1F,
  {
    0U, 448U, 3008U, 3520U
  },
  {
    557U, 557U, 0U, 0U
  },
  {
    0U, 448U, 3008U, 3520U
  },
  {
    557U, 557U, 0U, 0U
  },
  {
    {0U, 89U, 179U, 357U, 715U, 1430U, 2860U, 5719U, 8936U}, {0U, 89U, 179U, 357U, 715U, 1430U, 2860U, 5719U, 8936U}, {
    0U, 89U, 179U, 357U, 715U, 1430U, 2860U, 5719U, 8936U}, {0U, 89U, 179U, 357U, 715U, 1430U, 2860U, 5719U, 8936U}, {0U, 
    89U, 179U, 357U, 715U, 1430U, 2860U, 5719U, 8936U}, {0U, 89U, 179U, 357U, 715U, 1430U, 2860U, 5719U, 8936U}, {0U, 
    89U, 179U, 357U, 715U, 1430U, 2860U, 5719U, 8936U}, {0U, 89U, 179U, 357U, 715U, 1430U, 2860U, 5719U, 8936U}, {0U, 
    89U, 179U, 357U, 715U, 1430U, 2860U, 5719U, 8936U}, {0U, 89U, 179U, 357U, 715U, 1430U, 2860U, 5719U, 8936U}, {0U, 
    89U, 179U, 357U, 715U, 1430U, 2860U, 5719U, 8936U}, {0U, 89U, 179U, 357U, 715U, 1430U, 2860U, 5719U, 8936U}
  },
  {
    {0U, 64U, 124U, 288U, 900U, 2456U, 5980U, 12288U, 12288U}, {0U, 64U, 124U, 288U, 900U, 2456U, 5980U, 12288U, 12288U}, 
    {0U, 64U, 124U, 288U, 900U, 2456U, 5980U, 12288U, 12288U}, {0U, 64U, 124U, 288U, 900U, 2456U, 5980U, 12288U, 12288U}, 
    {0U, 64U, 124U, 288U, 900U, 2456U, 5980U, 12288U, 12288U}, {0U, 64U, 124U, 288U, 900U, 2456U, 5980U, 12288U, 12288U}, 
    {0U, 64U, 124U, 288U, 900U, 2456U, 5980U, 12288U, 12288U}, {0U, 64U, 124U, 288U, 900U, 2456U, 5980U, 12288U, 12288U}, 
    {0U, 64U, 124U, 288U, 900U, 2456U, 5980U, 12288U, 12288U}, {0U, 64U, 124U, 288U, 900U, 2456U, 5980U, 12288U, 12288U}, 
    {0U, 64U, 124U, 288U, 900U, 2456U, 5980U, 12288U, 12288U}, {0U, 64U, 124U, 288U, 900U, 2456U, 5980U, 12288U, 12288U}
  },
  {
    {0U, 394U, 798U, 1204U, 1610U, 2009U, 2406U, 2834U, 29568U}, {0U, 394U, 798U, 1204U, 1610U, 2009U, 2406U, 2834U, 
    29568U}, {0U, 394U, 798U, 1204U, 1610U, 2009U, 2406U, 2834U, 29568U}, {0U, 394U, 798U, 1204U, 1610U, 2009U, 2406U, 
    2834U, 29568U}, {0U, 394U, 798U, 1204U, 1610U, 2009U, 2406U, 2834U, 29568U}, {0U, 394U, 798U, 1204U, 1610U, 2009U, 
    2406U, 2834U, 29568U}, {0U, 394U, 798U, 1204U, 1610U, 2009U, 2406U, 2834U, 29568U}, {0U, 394U, 798U, 1204U, 1610U, 
    2009U, 2406U, 2834U, 29568U}, {0U, 394U, 798U, 1204U, 1610U, 2009U, 2406U, 2834U, 29568U}, {0U, 394U, 798U, 1204U, 
    1610U, 2009U, 2406U, 2834U, 29568U}, {0U, 394U, 798U, 1204U, 1610U, 2009U, 2406U, 2834U, 29568U}, {0U, 394U, 798U, 
    1204U, 1610U, 2009U, 2406U, 2834U, 29568U}
  },
  {
    {32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U}, {32768U, 32768U, 32768U, 32768U, 32768U, 
    32768U, 32768U, 32768U, 32768U}, {32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U}, {32768U, 
    32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U}, {32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 
    32768U, 32768U, 32768U}, {32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U}, {32768U, 32768U, 
    32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U}, {32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 
    32768U, 32768U}, {32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U}, {32768U, 32768U, 32768U, 
    32768U, 32768U, 32768U, 32768U, 32768U, 32768U}, {32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 
    32768U}, {32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U}
  },
  {
    205U, 205U, 256U, 307U, 512U, 512U, 512U, 512U, 512U, 512U, 512U, 512U
  },
  {
    205U, 205U, 205U, 102U, 102U, 51U, 51U, 51U, 51U, 51U, 51U, 51U
  },
  {
    0U, 102U
  },
  {
    0U, 16384U
  },
  {
    0U, 16384U
  },
  {
    0U, 16384U
  },
  {
    0U, 1024U
  },
  {
    0U, 16384U
  },
  {
    0U, 2000U, 10000U, 18000U
  },
  {
    {164U, 164U, 164U, 164U}, {164U, 164U, 164U, 164U}, {164U, 164U, 164U, 164U}, {164U, 164U, 164U, 164U}, {164U, 164U, 
    164U, 164U}, {164U, 164U, 164U, 164U}, {164U, 164U, 164U, 164U}, {164U, 164U, 164U, 164U}, {164U, 164U, 164U, 164U}, {
    164U, 164U, 164U, 164U}, {164U, 164U, 164U, 164U}, {164U, 164U, 164U, 164U}
  },
  {
    10240U, 10240U, 5120U, 5120U, 3072U, 3072U, 2560U, 2560U, 2560U, 2560U, 2560U, 0U
  },
  {
    0U, 1280U, 5120U, 10240U, 25600U
  },
  {
    20480U, 20480U, 16384U, 4096U, 0U
  },
  {
    -10240, -8192, -4096, 0, 4096, 8192, 10240
  },
  {
    19661U, 19661U, 18022U, 16384U, 14746U, 13107U, 13107U
  },
  {
    {0U, 123U, 258U, 395U, 530U, 661U, 798U, 934U, 1069U, 1204U, 1335U, 1474U, 1610U, 1741U, 1874U, 2009U, 2145U, 2280U, 
    2406U, 2540U, 2675U, 2834U, 2957U, 29568U}, {0U, 124U, 258U, 394U, 528U, 664U, 798U, 932U, 1066U, 1201U, 1340U, 
    1472U, 1609U, 1744U, 1876U, 2014U, 2145U, 2277U, 2425U, 2543U, 2692U, 2834U, 2957U, 29568U}, {0U, 124U, 258U, 393U, 
    527U, 663U, 798U, 934U, 1067U, 1203U, 1339U, 1471U, 1608U, 1739U, 1878U, 2009U, 2145U, 2288U, 2421U, 2546U, 2676U, 
    2834U, 2957U, 29568U}, {0U, 124U, 259U, 392U, 529U, 664U, 798U, 934U, 1068U, 1202U, 1336U, 1472U, 1609U, 1743U, 
    1880U, 2009U, 2145U, 2277U, 2413U, 2548U, 2695U, 2815U, 2957U, 29568U}, {0U, 122U, 258U, 392U, 529U, 662U, 798U, 
    932U, 1068U, 1201U, 1339U, 1474U, 1607U, 1742U, 1880U, 2013U, 2145U, 2285U, 2418U, 2549U, 2691U, 2834U, 2957U, 29568U
    }, {0U, 123U, 257U, 392U, 527U, 664U, 798U, 934U, 1069U, 1204U, 1337U, 1472U, 1605U, 1741U, 1881U, 2009U, 2145U, 
    2280U, 2422U, 2549U, 2686U, 2826U, 2957U, 29568U}, {0U, 124U, 259U, 394U, 528U, 663U, 798U, 932U, 1069U, 1203U, 
    1336U, 1475U, 1608U, 1740U, 1874U, 2013U, 2145U, 2287U, 2411U, 2550U, 2682U, 2816U, 2957U, 29568U}, {0U, 123U, 258U, 
    394U, 528U, 662U, 798U, 934U, 1066U, 1203U, 1338U, 1473U, 1606U, 1744U, 1875U, 2009U, 2145U, 2282U, 2415U, 2551U, 
    2678U, 2834U, 2957U, 29568U}, {0U, 124U, 259U, 394U, 529U, 663U, 798U, 932U, 1067U, 1202U, 1337U, 1471U, 1609U, 
    1743U, 1876U, 2012U, 2145U, 2278U, 2419U, 2551U, 2698U, 2826U, 2957U, 29568U}, {0U, 122U, 258U, 394U, 527U, 662U, 
    798U, 934U, 1067U, 1202U, 1339U, 1473U, 1607U, 1742U, 1876U, 2009U, 2145U, 2284U, 2423U, 2552U, 2694U, 2817U, 2957U, 
    29568U}
  },
  {
    {0U, 512U, 1072U, 1632U, 2176U, 2688U, 3200U, 3680U, 4128U, 4544U, 4912U, 5264U, 5568U, 5824U, 6048U, 6240U, 6400U, 
    6528U, 6624U, 6704U, 6768U, 6832U, 6864U, 15712U}, {0U, 592U, 1232U, 1872U, 2496U, 3104U, 3680U, 4224U, 4736U, 5216U, 
    5664U, 6048U, 6400U, 6704U, 6960U, 7184U, 7360U, 7504U, 7632U, 7712U, 7792U, 7856U, 7904U, 18080U}, {0U, 672U, 1392U, 
    2112U, 2816U, 3504U, 4160U, 4784U, 5360U, 5904U, 6400U, 6832U, 7232U, 7568U, 7872U, 8112U, 8320U, 8496U, 8624U, 
    8720U, 8800U, 8880U, 8928U, 20432U}, {0U, 720U, 1504U, 2272U, 3040U, 3776U, 4480U, 5152U, 5776U, 6352U, 6880U, 7360U, 
    7792U, 8160U, 8480U, 8736U, 8960U, 9136U, 9280U, 9392U, 9488U, 9552U, 9616U, 22000U}, {0U, 736U, 1552U, 2352U, 3152U, 
    3904U, 4640U, 5328U, 5984U, 6576U, 7136U, 7632U, 8064U, 8448U, 8784U, 9056U, 9280U, 9472U, 9616U, 9728U, 9824U, 
    9904U, 9968U, 22784U}, {0U, 768U, 1600U, 2432U, 3248U, 4048U, 4800U, 5520U, 6192U, 6816U, 7376U, 7888U, 8336U, 8736U, 
    9088U, 9360U, 9600U, 9792U, 9952U, 10064U, 10160U, 10240U, 10304U, 23584U}, {0U, 800U, 1664U, 2528U, 3360U, 4176U, 
    4960U, 5696U, 6400U, 7040U, 7616U, 8160U, 8624U, 9024U, 9376U, 9680U, 9920U, 10128U, 10272U, 10400U, 10496U, 10576U, 
    10656U, 24368U}, {0U, 816U, 1712U, 2608U, 3472U, 4304U, 5120U, 5888U, 6592U, 7264U, 7872U, 8416U, 8896U, 9328U, 
    9680U, 9984U, 10240U, 10448U, 10608U, 10736U, 10832U, 10928U, 10992U, 25152U}, {0U, 848U, 1776U, 2688U, 3584U, 4448U, 
    5280U, 6064U, 6800U, 7488U, 8112U, 8672U, 9184U, 9616U, 9984U, 10304U, 10560U, 10768U, 10944U, 11072U, 11184U, 
    11264U, 11344U, 25936U}, {0U, 864U, 1824U, 2768U, 3680U, 4576U, 5440U, 6256U, 7008U, 7712U, 8368U, 8944U, 9456U, 
    9904U, 10288U, 10608U, 10880U, 11104U, 11280U, 11408U, 11520U, 11600U, 11680U, 26720U}
  },
  {
    0U, 1920U, 3840U, 7680U, 10240U, 12800U, 15360U, 19200U, 23040U, 28160U
  }
};
CONST(Rte_Calprm_CalRegn02Rt02_DEFAULT_RTE_CALPRM_GROUP_Type, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_CalprmRom_CalRegn02Rt02_DEFAULT_RTE_CALPRM_GROUP = { /* PRQA S 3408 */ /* MD_Rte_3408 */
  0.2F,
  500U
};
CONST(Rte_Calprm_CalRegn02Rt03GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_CalprmRom_CalRegn02Rt03GroupA_DEFAULT_RTE_CALPRM_GROUP = { /* PRQA S 3408 */ /* MD_Rte_3408 */
  0.4F,
  1.0F,
  10.0F,
  0.3F,
  500U,
  {
    {0U, 0U, 0U, 0U, 205U, 410U, 614U, 819U, 1024U}, {0U, 0U, 0U, 0U, 205U, 410U, 614U, 819U, 1024U}, {0U, 0U, 0U, 0U, 
    205U, 410U, 614U, 819U, 1024U}, {0U, 0U, 0U, 0U, 205U, 410U, 614U, 819U, 1024U}, {0U, 0U, 0U, 0U, 205U, 410U, 614U, 
    819U, 1024U}, {0U, 0U, 0U, 0U, 205U, 410U, 614U, 819U, 1024U}, {0U, 0U, 0U, 0U, 205U, 410U, 614U, 819U, 1024U}, {0U, 
    0U, 0U, 0U, 154U, 307U, 471U, 604U, 819U}, {0U, 0U, 0U, 0U, 20U, 41U, 61U, 82U, 102U}
  },
  {
    0U, 1280U, 2560U, 3840U, 5120U, 6400U, 7680U, 8960U, 10240U
  },
  {
    0U, 1200U, 2400U, 3600U, 4800U, 6000U, 7200U, 8400U, 9600U
  },
  {
    0U, 256U, 512U, 768U, 1024U, 1280U, 1536U, 1792U, 2048U, 2304U, 2560U
  },
  {
    32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 26214U, 19661U, 13107U, 6554U, 0U
  }
};
CONST(Rte_Calprm_CalRegn02Rt03GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_CalprmRom_CalRegn02Rt03GroupC_DEFAULT_RTE_CALPRM_GROUP = { /* PRQA S 3408 */ /* MD_Rte_3408 */
  FALSE,
  {
    {0U, 8960U, 10560U, 12160U, 13760U, 15360U, 18560U, 21760U, 24960U}, {0U, 8960U, 10560U, 12160U, 13760U, 15360U, 
    18560U, 21760U, 24960U}, {0U, 8960U, 10560U, 12160U, 13760U, 15360U, 18560U, 21760U, 24960U}, {0U, 8960U, 10560U, 
    12160U, 13760U, 15360U, 18560U, 21760U, 24960U}, {0U, 8960U, 10560U, 12160U, 13760U, 15360U, 18560U, 21760U, 24960U}, 
    {0U, 16000U, 17600U, 19200U, 20800U, 22400U, 25600U, 28800U, 32000U}, {0U, 20608U, 22208U, 23808U, 25408U, 27008U, 
    30208U, 33408U, 36608U}, {0U, 26112U, 27712U, 29312U, 30912U, 32512U, 35712U, 38912U, 42112U}
  },
  {
    {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 1037U, 4355U, 9735U, 16396U, 33177U, 33177U, 33177U}, {0U, 0U, 1152U, 
    4839U, 10817U, 18218U, 36863U, 36863U, 36863U}, {0U, 0U, 1152U, 4839U, 10817U, 18218U, 36863U, 36863U, 36863U}, {0U, 
    0U, 1152U, 4839U, 10817U, 18218U, 36863U, 36863U, 36863U}
  },
  {
    {0U, 384U, 512U, 640U, 768U, 896U, 1024U, 2560U}, {0U, 384U, 512U, 640U, 768U, 896U, 1024U, 2560U}, {0U, 384U, 512U, 
    640U, 768U, 896U, 1024U, 2560U}, {0U, 384U, 512U, 640U, 768U, 896U, 1024U, 2560U}, {0U, 384U, 512U, 640U, 768U, 896U, 
    1024U, 2560U}
  },
  {
    {16384U, 16384U, 16384U, 16384U, 0U, 0U, 0U, 0U}, {16384U, 16384U, 16384U, 16384U, 0U, 0U, 0U, 0U}, {16384U, 16384U, 
    16384U, 16384U, 0U, 0U, 0U, 0U}, {16384U, 16384U, 16384U, 16384U, 0U, 0U, 0U, 0U}, {16384U, 16384U, 16384U, 16384U, 
    0U, 0U, 0U, 0U}
  },
  {
    {0U, 261U, 451U, 776U, 994U, 1220U, 1441U, 1767U, 7200U, 7216U, 7232U, 7248U}, {0U, 261U, 451U, 776U, 994U, 1220U, 
    1441U, 1767U, 7200U, 7216U, 7232U, 7248U}, {0U, 261U, 451U, 776U, 994U, 1220U, 1441U, 1767U, 7200U, 7216U, 7232U, 
    7248U}, {0U, 261U, 451U, 776U, 994U, 1220U, 1441U, 1767U, 7200U, 7216U, 7232U, 7248U}, {0U, 261U, 451U, 776U, 994U, 
    1220U, 1441U, 1767U, 7200U, 7216U, 7232U, 7248U}, {0U, 261U, 451U, 776U, 994U, 1220U, 1441U, 1767U, 7200U, 7216U, 
    7232U, 7248U}, {0U, 261U, 451U, 776U, 994U, 1220U, 1441U, 1767U, 7200U, 7216U, 7232U, 7248U}, {0U, 261U, 451U, 776U, 
    994U, 1220U, 1441U, 1767U, 7200U, 7216U, 7232U, 7248U}
  },
  {
    {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 1788U, 3385U, 5353U, 6805U, 8089U, 8953U, 9259U, 9259U, 9259U, 
    9259U, 9259U}, {0U, 2446U, 4630U, 7323U, 9309U, 11066U, 12247U, 12666U, 12666U, 12666U, 12666U, 12666U}, {0U, 3090U, 
    5849U, 9249U, 11759U, 13978U, 15470U, 16000U, 16000U, 16000U, 16000U, 16000U}, {0U, 3708U, 7019U, 11099U, 14111U, 
    16774U, 18564U, 19200U, 19200U, 19200U, 19200U, 19200U}, {0U, 5340U, 10108U, 15983U, 20320U, 24155U, 26732U, 27648U, 
    27648U, 27648U, 27648U, 27648U}, {0U, 6408U, 12130U, 19180U, 24384U, 28986U, 32078U, 33178U, 33178U, 33178U, 33178U, 
    33178U}, {0U, 7306U, 13828U, 21865U, 27798U, 33044U, 36569U, 37823U, 37823U, 37823U, 37823U, 37823U}
  },
  {
    0U, 160U, 320U, 640U, 656U, 1440U, 2880U, 5760U, 16000U
  },
  {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  },
  {
    {0U, 102U, 128U, 154U, 182U, 337U, 412U, 521U, 640U, 2048U}, {0U, 102U, 128U, 154U, 182U, 337U, 412U, 521U, 640U, 
    2048U}, {0U, 102U, 128U, 154U, 182U, 337U, 412U, 521U, 640U, 2048U}, {0U, 102U, 128U, 154U, 182U, 337U, 412U, 521U, 
    640U, 2048U}, {0U, 102U, 128U, 154U, 182U, 337U, 412U, 521U, 640U, 2048U}
  },
  {
    {16384U, 16384U, 16071U, 15540U, 14495U, 9349U, 6704U, 3116U, 0U, 0U}, {16384U, 16384U, 16071U, 15540U, 14495U, 
    9349U, 6704U, 3116U, 0U, 0U}, {16384U, 16384U, 16071U, 15540U, 14495U, 9349U, 6704U, 3116U, 0U, 0U}, {16384U, 16384U, 
    16071U, 15540U, 14495U, 9349U, 6704U, 3116U, 0U, 0U}, {16384U, 16384U, 16071U, 15540U, 14495U, 9349U, 6704U, 3116U, 
    0U, 0U}
  },
  {
    {0U, 102U, 128U, 154U, 182U, 337U, 412U, 521U, 640U, 2048U}, {0U, 102U, 128U, 154U, 182U, 337U, 412U, 521U, 640U, 
    2048U}, {0U, 102U, 128U, 154U, 182U, 337U, 412U, 521U, 640U, 2048U}, {0U, 102U, 128U, 154U, 182U, 337U, 412U, 521U, 
    640U, 2048U}, {0U, 102U, 128U, 154U, 182U, 337U, 412U, 521U, 640U, 2048U}
  },
  {
    {16384U, 16384U, 16071U, 15540U, 14495U, 9349U, 6704U, 3116U, 0U, 0U}, {16384U, 16384U, 16071U, 15540U, 14495U, 
    9349U, 6704U, 3116U, 0U, 0U}, {16384U, 16384U, 16071U, 15540U, 14495U, 9349U, 6704U, 3116U, 0U, 0U}, {16384U, 16384U, 
    16071U, 15540U, 14495U, 9349U, 6704U, 3116U, 0U, 0U}, {16384U, 16384U, 16071U, 15540U, 14495U, 9349U, 6704U, 3116U, 
    0U, 0U}
  },
  {
    0U, 38U, 38U, 51U, 64U, 64U, 64U, 64U
  },
  {
    {0U, 384U, 512U, 640U, 768U, 896U, 1024U, 2560U}, {0U, 384U, 512U, 640U, 768U, 896U, 1024U, 2560U}, {0U, 384U, 512U, 
    640U, 768U, 896U, 1024U, 2560U}, {0U, 384U, 512U, 640U, 768U, 896U, 1024U, 2560U}, {0U, 384U, 512U, 640U, 768U, 896U, 
    1024U, 2560U}
  },
  {
    {16384U, 16384U, 16384U, 9830U, 0U, 0U, 0U, 0U}, {16384U, 16384U, 16384U, 9830U, 0U, 0U, 0U, 0U}, {16384U, 16384U, 
    16384U, 9830U, 0U, 0U, 0U, 0U}, {16384U, 16384U, 16384U, 16384U, 16384U, 16384U, 16384U, 16384U}, {16384U, 16384U, 
    16384U, 16384U, 16384U, 16384U, 16384U, 16384U}
  },
  {
    0U, 82U, 82U, 205U, 492U, 492U, 492U, 492U
  },
  {
    {0U, 5120U, 6400U, 7680U, 8960U, 10240U, 11520U, 12800U}, {0U, 5120U, 6400U, 7680U, 8960U, 10240U, 11520U, 12800U}, {
    0U, 5120U, 6400U, 7680U, 8960U, 10240U, 11520U, 12800U}, {0U, 5120U, 6400U, 7680U, 8960U, 10240U, 11520U, 12800U}, {
    0U, 5120U, 6400U, 7680U, 8960U, 10240U, 11520U, 12800U}
  },
  {
    {16384U, 16384U, 13107U, 8192U, 4915U, 4915U, 4915U, 4915U}, {16384U, 16384U, 13107U, 8192U, 4915U, 4915U, 4915U, 
    4915U}, {16384U, 16384U, 13107U, 8192U, 4915U, 4915U, 4915U, 4915U}, {16384U, 16384U, 13107U, 11469U, 6554U, 6554U, 
    6554U, 6554U}, {16384U, 16384U, 13107U, 11469U, 6554U, 6554U, 6554U, 6554U}
  },
  {
    0U, 1280U, 3840U, 6400U, 10240U
  },
  {
    0U, 160U, 320U, 480U, 800U, 1280U, 7200U
  },
  {
    -6400, 0, 640, 1600, 3200, 6400, 8000, 25600
  },
  {
    {16384U, 16384U, 16384U, 16384U, 16384U, 16384U, 16384U, 16384U}, {16384U, 16384U, 13107U, 8192U, 4915U, 8192U, 
    11469U, 16384U}, {16384U, 16384U, 13107U, 8192U, 4915U, 4915U, 8192U, 16384U}, {16384U, 16384U, 13107U, 8192U, 4915U, 
    4915U, 8192U, 16384U}, {16384U, 16384U, 13107U, 13107U, 8192U, 8192U, 8192U, 16384U}, {16384U, 16384U, 16384U, 
    16384U, 16384U, 16384U, 16384U, 16384U}, {16384U, 16384U, 16384U, 16384U, 16384U, 16384U, 16384U, 16384U}
  },
  {
    16384U, 16384U, 16384U, 11469U, 11469U
  },
  {
    0U, 320U, 640U, 2560U, 3840U, 6400U, 7680U, 10240U
  }
};
CONST(Rte_Calprm_CalRegn02Rt03GroupD_DEFAULT_RTE_CALPRM_GROUP_Type, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_CalprmRom_CalRegn02Rt03GroupD_DEFAULT_RTE_CALPRM_GROUP = { /* PRQA S 3408 */ /* MD_Rte_3408 */
  0.2F,
  1.0F,
  -1.0F,
  1.0F,
  -1.0F,
  1.0F,
  -0.1F,
  0.1F,
  -0.1F,
  0.1F,
  {
    0U, 448U, 3008U, 3520U
  },
  {
    557U, 557U, 0U, 0U
  },
  {
    0U, 448U, 3008U, 3520U
  },
  {
    557U, 557U, 0U, 0U
  },
  {
    {0U, 89U, 179U, 357U, 715U, 1430U, 2860U, 5719U, 8936U}, {0U, 89U, 179U, 357U, 715U, 1430U, 2860U, 5719U, 8936U}, {
    0U, 89U, 179U, 357U, 715U, 1430U, 2860U, 5719U, 8936U}, {0U, 89U, 179U, 357U, 715U, 1430U, 2860U, 5719U, 8936U}, {0U, 
    89U, 179U, 357U, 715U, 1430U, 2860U, 5719U, 8936U}, {0U, 89U, 179U, 357U, 715U, 1430U, 2860U, 5719U, 8936U}, {0U, 
    89U, 179U, 357U, 715U, 1430U, 2860U, 5719U, 8936U}, {0U, 89U, 179U, 357U, 715U, 1430U, 2860U, 5719U, 8936U}, {0U, 
    89U, 179U, 357U, 715U, 1430U, 2860U, 5719U, 8936U}, {0U, 89U, 179U, 357U, 715U, 1430U, 2860U, 5719U, 8936U}, {0U, 
    89U, 179U, 357U, 715U, 1430U, 2860U, 5719U, 8936U}, {0U, 89U, 179U, 357U, 715U, 1430U, 2860U, 5719U, 8936U}
  },
  {
    {0U, 64U, 124U, 288U, 900U, 2456U, 5980U, 12288U, 12288U}, {0U, 64U, 124U, 288U, 900U, 2456U, 5980U, 12288U, 12288U}, 
    {0U, 64U, 124U, 288U, 900U, 2456U, 5980U, 12288U, 12288U}, {0U, 64U, 124U, 288U, 900U, 2456U, 5980U, 12288U, 12288U}, 
    {0U, 64U, 124U, 288U, 900U, 2456U, 5980U, 12288U, 12288U}, {0U, 64U, 124U, 288U, 900U, 2456U, 5980U, 12288U, 12288U}, 
    {0U, 64U, 124U, 288U, 900U, 2456U, 5980U, 12288U, 12288U}, {0U, 64U, 124U, 288U, 900U, 2456U, 5980U, 12288U, 12288U}, 
    {0U, 64U, 124U, 288U, 900U, 2456U, 5980U, 12288U, 12288U}, {0U, 64U, 124U, 288U, 900U, 2456U, 5980U, 12288U, 12288U}, 
    {0U, 64U, 124U, 288U, 900U, 2456U, 5980U, 12288U, 12288U}, {0U, 64U, 124U, 288U, 900U, 2456U, 5980U, 12288U, 12288U}
  },
  {
    {0U, 394U, 798U, 1204U, 1610U, 2009U, 2406U, 2834U, 29568U}, {0U, 394U, 798U, 1204U, 1610U, 2009U, 2406U, 2834U, 
    29568U}, {0U, 394U, 798U, 1204U, 1610U, 2009U, 2406U, 2834U, 29568U}, {0U, 394U, 798U, 1204U, 1610U, 2009U, 2406U, 
    2834U, 29568U}, {0U, 394U, 798U, 1204U, 1610U, 2009U, 2406U, 2834U, 29568U}, {0U, 394U, 798U, 1204U, 1610U, 2009U, 
    2406U, 2834U, 29568U}, {0U, 394U, 798U, 1204U, 1610U, 2009U, 2406U, 2834U, 29568U}, {0U, 394U, 798U, 1204U, 1610U, 
    2009U, 2406U, 2834U, 29568U}, {0U, 394U, 798U, 1204U, 1610U, 2009U, 2406U, 2834U, 29568U}, {0U, 394U, 798U, 1204U, 
    1610U, 2009U, 2406U, 2834U, 29568U}, {0U, 394U, 798U, 1204U, 1610U, 2009U, 2406U, 2834U, 29568U}, {0U, 394U, 798U, 
    1204U, 1610U, 2009U, 2406U, 2834U, 29568U}
  },
  {
    {32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U}, {32768U, 32768U, 32768U, 32768U, 32768U, 
    32768U, 32768U, 32768U, 32768U}, {32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U}, {32768U, 
    32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U}, {32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 
    32768U, 32768U, 32768U}, {32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U}, {32768U, 32768U, 
    32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U}, {32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 
    32768U, 32768U}, {32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U}, {32768U, 32768U, 32768U, 
    32768U, 32768U, 32768U, 32768U, 32768U, 32768U}, {32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 
    32768U}, {32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U, 32768U}
  },
  {
    205U, 205U, 256U, 307U, 512U, 512U, 512U, 512U, 512U, 512U, 512U, 512U
  },
  {
    205U, 205U, 205U, 102U, 102U, 51U, 51U, 51U, 51U, 51U, 51U, 51U
  },
  {
    0U, 102U
  },
  {
    0U, 16384U
  },
  {
    0U, 16384U
  },
  {
    0U, 16384U
  },
  {
    0U, 1024U
  },
  {
    0U, 16384U
  },
  {
    0U, 2000U, 10000U, 18000U
  },
  {
    {164U, 164U, 164U, 164U}, {164U, 164U, 164U, 164U}, {164U, 164U, 164U, 164U}, {164U, 164U, 164U, 164U}, {164U, 164U, 
    164U, 164U}, {164U, 164U, 164U, 164U}, {164U, 164U, 164U, 164U}, {164U, 164U, 164U, 164U}, {164U, 164U, 164U, 164U}, {
    164U, 164U, 164U, 164U}, {164U, 164U, 164U, 164U}, {164U, 164U, 164U, 164U}
  },
  {
    10240U, 10240U, 5120U, 5120U, 3072U, 3072U, 2560U, 2560U, 2560U, 2560U, 2560U, 0U
  },
  {
    0U, 1280U, 5120U, 10240U, 25600U
  },
  {
    20480U, 20480U, 16384U, 4096U, 0U
  },
  {
    -10240, -8192, -4096, 0, 4096, 8192, 10240
  },
  {
    19661U, 19661U, 18022U, 16384U, 14746U, 13107U, 13107U
  },
  {
    {0U, 123U, 258U, 395U, 530U, 661U, 798U, 934U, 1069U, 1204U, 1335U, 1474U, 1610U, 1741U, 1874U, 2009U, 2145U, 2280U, 
    2406U, 2540U, 2675U, 2834U, 2957U, 29568U}, {0U, 124U, 258U, 394U, 528U, 664U, 798U, 932U, 1066U, 1201U, 1340U, 
    1472U, 1609U, 1744U, 1876U, 2014U, 2145U, 2277U, 2425U, 2543U, 2692U, 2834U, 2957U, 29568U}, {0U, 124U, 258U, 393U, 
    527U, 663U, 798U, 934U, 1067U, 1203U, 1339U, 1471U, 1608U, 1739U, 1878U, 2009U, 2145U, 2288U, 2421U, 2546U, 2676U, 
    2834U, 2957U, 29568U}, {0U, 124U, 259U, 392U, 529U, 664U, 798U, 934U, 1068U, 1202U, 1336U, 1472U, 1609U, 1743U, 
    1880U, 2009U, 2145U, 2277U, 2413U, 2548U, 2695U, 2815U, 2957U, 29568U}, {0U, 122U, 258U, 392U, 529U, 662U, 798U, 
    932U, 1068U, 1201U, 1339U, 1474U, 1607U, 1742U, 1880U, 2013U, 2145U, 2285U, 2418U, 2549U, 2691U, 2834U, 2957U, 29568U
    }, {0U, 123U, 257U, 392U, 527U, 664U, 798U, 934U, 1069U, 1204U, 1337U, 1472U, 1605U, 1741U, 1881U, 2009U, 2145U, 
    2280U, 2422U, 2549U, 2686U, 2826U, 2957U, 29568U}, {0U, 124U, 259U, 394U, 528U, 663U, 798U, 932U, 1069U, 1203U, 
    1336U, 1475U, 1608U, 1740U, 1874U, 2013U, 2145U, 2287U, 2411U, 2550U, 2682U, 2816U, 2957U, 29568U}, {0U, 123U, 258U, 
    394U, 528U, 662U, 798U, 934U, 1066U, 1203U, 1338U, 1473U, 1606U, 1744U, 1875U, 2009U, 2145U, 2282U, 2415U, 2551U, 
    2678U, 2834U, 2957U, 29568U}, {0U, 124U, 259U, 394U, 529U, 663U, 798U, 932U, 1067U, 1202U, 1337U, 1471U, 1609U, 
    1743U, 1876U, 2012U, 2145U, 2278U, 2419U, 2551U, 2698U, 2826U, 2957U, 29568U}, {0U, 122U, 258U, 394U, 527U, 662U, 
    798U, 934U, 1067U, 1202U, 1339U, 1473U, 1607U, 1742U, 1876U, 2009U, 2145U, 2284U, 2423U, 2552U, 2694U, 2817U, 2957U, 
    29568U}
  },
  {
    {0U, 512U, 1072U, 1632U, 2176U, 2688U, 3200U, 3680U, 4128U, 4544U, 4912U, 5264U, 5568U, 5824U, 6048U, 6240U, 6400U, 
    6528U, 6624U, 6704U, 6768U, 6832U, 6864U, 15712U}, {0U, 592U, 1232U, 1872U, 2496U, 3104U, 3680U, 4224U, 4736U, 5216U, 
    5664U, 6048U, 6400U, 6704U, 6960U, 7184U, 7360U, 7504U, 7632U, 7712U, 7792U, 7856U, 7904U, 18080U}, {0U, 672U, 1392U, 
    2112U, 2816U, 3504U, 4160U, 4784U, 5360U, 5904U, 6400U, 6832U, 7232U, 7568U, 7872U, 8112U, 8320U, 8496U, 8624U, 
    8720U, 8800U, 8880U, 8928U, 20432U}, {0U, 720U, 1504U, 2272U, 3040U, 3776U, 4480U, 5152U, 5776U, 6352U, 6880U, 7360U, 
    7792U, 8160U, 8480U, 8736U, 8960U, 9136U, 9280U, 9392U, 9488U, 9552U, 9616U, 22000U}, {0U, 736U, 1552U, 2352U, 3152U, 
    3904U, 4640U, 5328U, 5984U, 6576U, 7136U, 7632U, 8064U, 8448U, 8784U, 9056U, 9280U, 9472U, 9616U, 9728U, 9824U, 
    9904U, 9968U, 22784U}, {0U, 768U, 1600U, 2432U, 3248U, 4048U, 4800U, 5520U, 6192U, 6816U, 7376U, 7888U, 8336U, 8736U, 
    9088U, 9360U, 9600U, 9792U, 9952U, 10064U, 10160U, 10240U, 10304U, 23584U}, {0U, 800U, 1664U, 2528U, 3360U, 4176U, 
    4960U, 5696U, 6400U, 7040U, 7616U, 8160U, 8624U, 9024U, 9376U, 9680U, 9920U, 10128U, 10272U, 10400U, 10496U, 10576U, 
    10656U, 24368U}, {0U, 816U, 1712U, 2608U, 3472U, 4304U, 5120U, 5888U, 6592U, 7264U, 7872U, 8416U, 8896U, 9328U, 
    9680U, 9984U, 10240U, 10448U, 10608U, 10736U, 10832U, 10928U, 10992U, 25152U}, {0U, 848U, 1776U, 2688U, 3584U, 4448U, 
    5280U, 6064U, 6800U, 7488U, 8112U, 8672U, 9184U, 9616U, 9984U, 10304U, 10560U, 10768U, 10944U, 11072U, 11184U, 
    11264U, 11344U, 25936U}, {0U, 864U, 1824U, 2768U, 3680U, 4576U, 5440U, 6256U, 7008U, 7712U, 8368U, 8944U, 9456U, 
    9904U, 10288U, 10608U, 10880U, 11104U, 11280U, 11408U, 11520U, 11600U, 11680U, 26720U}
  },
  {
    0U, 1920U, 3840U, 7680U, 10240U, 12800U, 15360U, 19200U, 23040U, 28160U
  }
};
CONST(Rte_Calprm_CalRegn02Rt03_DEFAULT_RTE_CALPRM_GROUP_Type, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_CalprmRom_CalRegn02Rt03_DEFAULT_RTE_CALPRM_GROUP = { /* PRQA S 3408 */ /* MD_Rte_3408 */
  0.2F,
  500U
};

#define RTE_STOP_SEC_CONST_DEFAULT_RTE_CALPRM_GROUP_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

CONST(Rte_Calprm_BmwDiagcSrvHndlg_DEFAULT_RTE_CDATA_GROUP_Type, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CalprmRom_BmwDiagcSrvHndlg_DEFAULT_RTE_CDATA_GROUP = { /* PRQA S 3408 */ /* MD_Rte_3408 */
  0U,
  1000U
};
CONST(Rte_Calprm_BmwTunSetHndlr_DEFAULT_RTE_CDATA_GROUP_Type, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CalprmRom_BmwTunSetHndlr_DEFAULT_RTE_CDATA_GROUP = { /* PRQA S 3408 */ /* MD_Rte_3408 */
  {
    0U, FALSE
  },
  {
    0U, FALSE
  }
};
CONST(Rte_Calprm_CDD_CurrMeas_DEFAULT_RTE_CDATA_GROUP_Type, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CalprmRom_CDD_CurrMeas_DEFAULT_RTE_CDATA_GROUP = { /* PRQA S 3408 */ /* MD_Rte_3408 */
  {
    66.66F, 66.66F, 66.66F
  },
  {
    700000.0F, 0.0F, 0.0F, 0.0F, 2.5F, 2.5F, 2.5F
  }
};
CONST(Rte_Calprm_CDD_ExcpnHndlg_DEFAULT_RTE_CDATA_GROUP_Type, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CalprmRom_CDD_ExcpnHndlg_DEFAULT_RTE_CDATA_GROUP = { /* PRQA S 3408 */ /* MD_Rte_3408 */
  {
    0U, 0U, 0U, 0U
  }
};
CONST(Rte_Calprm_CDD_MotAg0Meas_DEFAULT_RTE_CDATA_GROUP_Type, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CalprmRom_CDD_MotAg0Meas_DEFAULT_RTE_CDATA_GROUP = { /* PRQA S 3408 */ /* MD_Rte_3408 */
  {
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F
  }
};
CONST(Rte_Calprm_CDD_MotAg1Meas_DEFAULT_RTE_CDATA_GROUP_Type, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CalprmRom_CDD_MotAg1Meas_DEFAULT_RTE_CDATA_GROUP = { /* PRQA S 3408 */ /* MD_Rte_3408 */
  {
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F
  }
};
CONST(Rte_Calprm_CDD_MotAgCmp_DEFAULT_RTE_CDATA_GROUP_Type, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CalprmRom_CDD_MotAgCmp_DEFAULT_RTE_CDATA_GROUP = { /* PRQA S 3408 */ /* MD_Rte_3408 */
  0U
};
CONST(Rte_Calprm_CmnMfgSrv_DEFAULT_RTE_CDATA_GROUP_Type, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CalprmRom_CmnMfgSrv_DEFAULT_RTE_CDATA_GROUP = { /* PRQA S 3408 */ /* MD_Rte_3408 */
  0U,
  254U,
  {
    1U, 2U, 3U, 4U, 5U, 254U, 253U, 252U, 251U, 250U
  },
  {
    19088743U, 2309737967U
  }
};
CONST(Rte_Calprm_DiagcMgr_DEFAULT_RTE_CDATA_GROUP_Type, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CalprmRom_DiagcMgr_DEFAULT_RTE_CDATA_GROUP = { /* PRQA S 3408 */ /* MD_Rte_3408 */
  0U
};
CONST(Rte_Calprm_HwTqCorrln_DEFAULT_RTE_CDATA_GROUP_Type, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CalprmRom_HwTqCorrln_DEFAULT_RTE_CDATA_GROUP = { /* PRQA S 3408 */ /* MD_Rte_3408 */
  0.0F
};
CONST(Rte_Calprm_PolarityCfg_DEFAULT_RTE_CDATA_GROUP_Type, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CalprmRom_PolarityCfg_DEFAULT_RTE_CDATA_GROUP = { /* PRQA S 3408 */ /* MD_Rte_3408 */
  0U
};
CONST(Rte_Calprm_PullCmpActv_DEFAULT_RTE_CDATA_GROUP_Type, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CalprmRom_PullCmpActv_DEFAULT_RTE_CDATA_GROUP = { /* PRQA S 3408 */ /* MD_Rte_3408 */
  0.0F
};
CONST(Rte_Calprm_SysFricLrng_DEFAULT_RTE_CDATA_GROUP_Type, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CalprmRom_SysFricLrng_DEFAULT_RTE_CDATA_GROUP = { /* PRQA S 3408 */ /* MD_Rte_3408 */
  {
    0.0F, {0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F}, {{0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 
    0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 
    0.0F}, {0.0F, 0.0F, 0.0F, 0.0F}}, {{0U, 0U, 0U}, {0U, 0U, 0U}, {0U, 0U, 0U}, {0U, 0U, 0U}, {0U, 0U, 0U}, {0U, 0U, 0U
    }, {0U, 0U, 0U}, {0U, 0U, 0U}}, 0U
  },
  {
    0.0F, FALSE, FALSE
  }
};

#define RTE_STOP_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

VAR(Rte_ParameterBaseType, RTE_VAR_INIT) RteParameterBase = &RteParameterRefTab[0];

#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

CONST(Rte_ParameterRefTabType, RTE_CONST) RteParameterRefTab =
{
  &Rte_CalprmRom_BmwTunSetHndlr_DEFAULT_RTE_CDATA_GROUP,
  &Rte_CalprmRom_CDD_CurrMeas_DEFAULT_RTE_CDATA_GROUP,
  &Rte_CalprmRom_DiagcMgr_DEFAULT_RTE_CDATA_GROUP,
  &Rte_CalprmRom_SysFricLrng_DEFAULT_RTE_CDATA_GROUP,
  &Rte_CalprmRom_HwTqCorrln_DEFAULT_RTE_CDATA_GROUP,
  &Rte_CalprmRom_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP,
  &Rte_CalprmRom_CalRegn02Rt01GroupC_DEFAULT_RTE_CALPRM_GROUP,
  &Rte_CalprmRom_CalRegn02Rt02GroupC_DEFAULT_RTE_CALPRM_GROUP,
  &Rte_CalprmRom_CalRegn02Rt03GroupC_DEFAULT_RTE_CALPRM_GROUP,
  &Rte_CalprmRom_CDD_ExcpnHndlg_DEFAULT_RTE_CDATA_GROUP,
  &Rte_CalprmRom_CDD_MotAg0Meas_DEFAULT_RTE_CDATA_GROUP,
  &Rte_CalprmRom_CDD_MotAg1Meas_DEFAULT_RTE_CDATA_GROUP,
  &Rte_CalprmRom_CDD_MotAgCmp_DEFAULT_RTE_CDATA_GROUP,
  &Rte_CalprmRom_CmnMfgSrv_DEFAULT_RTE_CDATA_GROUP,
  &Rte_CalprmRom_BmwDiagcSrvHndlg_DEFAULT_RTE_CDATA_GROUP,
  &Rte_CalprmRom_PolarityCfg_DEFAULT_RTE_CDATA_GROUP,
  &Rte_CalprmRom_PullCmpActv_DEFAULT_RTE_CDATA_GROUP,
  &Rte_CalprmRom_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP,
  &Rte_CalprmRom_CalRegn01CmnGroupA_DEFAULT_RTE_CALPRM_GROUP,
  &Rte_CalprmRom_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP,
  &Rte_CalprmRom_CalRegn01CmnGroupC_DEFAULT_RTE_CALPRM_GROUP,
  &Rte_CalprmRom_CalRegn01CmnGroupD_DEFAULT_RTE_CALPRM_GROUP,
  &Rte_CalprmRom_CalRegn01Inin00_DEFAULT_RTE_CALPRM_GROUP,
  &Rte_CalprmRom_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP,
  &Rte_CalprmRom_CalRegn01Inin00GroupC_DEFAULT_RTE_CALPRM_GROUP,
  &Rte_CalprmRom_CalRegn01Inin00GroupD_DEFAULT_RTE_CALPRM_GROUP,
  &Rte_CalprmRom_CalRegn01Inin01_DEFAULT_RTE_CALPRM_GROUP,
  &Rte_CalprmRom_CalRegn01Inin01GroupA_DEFAULT_RTE_CALPRM_GROUP,
  &Rte_CalprmRom_CalRegn01Inin01GroupC_DEFAULT_RTE_CALPRM_GROUP,
  &Rte_CalprmRom_CalRegn01Inin01GroupD_DEFAULT_RTE_CALPRM_GROUP,
  &Rte_CalprmRom_CalRegn01Inin02_DEFAULT_RTE_CALPRM_GROUP,
  &Rte_CalprmRom_CalRegn01Inin02GroupA_DEFAULT_RTE_CALPRM_GROUP,
  &Rte_CalprmRom_CalRegn01Inin02GroupC_DEFAULT_RTE_CALPRM_GROUP,
  &Rte_CalprmRom_CalRegn01Inin02GroupD_DEFAULT_RTE_CALPRM_GROUP,
  &Rte_CalprmRom_CalRegn01Inin03_DEFAULT_RTE_CALPRM_GROUP,
  &Rte_CalprmRom_CalRegn01Inin03GroupA_DEFAULT_RTE_CALPRM_GROUP,
  &Rte_CalprmRom_CalRegn01Inin03GroupC_DEFAULT_RTE_CALPRM_GROUP,
  &Rte_CalprmRom_CalRegn01Inin03GroupD_DEFAULT_RTE_CALPRM_GROUP,
  &Rte_CalprmRom_CalRegn01Inin04_DEFAULT_RTE_CALPRM_GROUP,
  &Rte_CalprmRom_CalRegn01Inin04GroupA_DEFAULT_RTE_CALPRM_GROUP,
  &Rte_CalprmRom_CalRegn01Inin04GroupC_DEFAULT_RTE_CALPRM_GROUP,
  &Rte_CalprmRom_CalRegn01Inin04GroupD_DEFAULT_RTE_CALPRM_GROUP,
  &Rte_CalprmRom_CalRegn01Inin05_DEFAULT_RTE_CALPRM_GROUP,
  &Rte_CalprmRom_CalRegn01Inin05GroupA_DEFAULT_RTE_CALPRM_GROUP,
  &Rte_CalprmRom_CalRegn01Inin05GroupC_DEFAULT_RTE_CALPRM_GROUP,
  &Rte_CalprmRom_CalRegn01Inin05GroupD_DEFAULT_RTE_CALPRM_GROUP,
  &Rte_CalprmRom_CalRegn01Inin06_DEFAULT_RTE_CALPRM_GROUP,
  &Rte_CalprmRom_CalRegn01Inin06GroupA_DEFAULT_RTE_CALPRM_GROUP,
  &Rte_CalprmRom_CalRegn01Inin06GroupC_DEFAULT_RTE_CALPRM_GROUP,
  &Rte_CalprmRom_CalRegn01Inin06GroupD_DEFAULT_RTE_CALPRM_GROUP,
  &Rte_CalprmRom_CalRegn01IninOptSetA00_DEFAULT_RTE_CALPRM_GROUP,
  &Rte_CalprmRom_CalRegn01IninOptSetA01_DEFAULT_RTE_CALPRM_GROUP,
  &Rte_CalprmRom_CalRegn01IninOptSetA02_DEFAULT_RTE_CALPRM_GROUP,
  &Rte_CalprmRom_CalRegn01IninOptSetA03_DEFAULT_RTE_CALPRM_GROUP,
  &Rte_CalprmRom_CalRegn02Rt00_DEFAULT_RTE_CALPRM_GROUP,
  &Rte_CalprmRom_CalRegn02Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP,
  &Rte_CalprmRom_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP,
  &Rte_CalprmRom_CalRegn02Rt01_DEFAULT_RTE_CALPRM_GROUP,
  &Rte_CalprmRom_CalRegn02Rt01GroupA_DEFAULT_RTE_CALPRM_GROUP,
  &Rte_CalprmRom_CalRegn02Rt01GroupD_DEFAULT_RTE_CALPRM_GROUP,
  &Rte_CalprmRom_CalRegn02Rt02_DEFAULT_RTE_CALPRM_GROUP,
  &Rte_CalprmRom_CalRegn02Rt02GroupA_DEFAULT_RTE_CALPRM_GROUP,
  &Rte_CalprmRom_CalRegn02Rt02GroupD_DEFAULT_RTE_CALPRM_GROUP,
  &Rte_CalprmRom_CalRegn02Rt03_DEFAULT_RTE_CALPRM_GROUP,
  &Rte_CalprmRom_CalRegn02Rt03GroupA_DEFAULT_RTE_CALPRM_GROUP,
  &Rte_CalprmRom_CalRegn02Rt03GroupD_DEFAULT_RTE_CALPRM_GROUP,
};
#define RTE_STOP_SEC_CONST_UNSPECIFIED
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

/* Queue definitions for internal C/S connections */
#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

VAR(Rte_CS_ServerQueueType_Coding_CheckNCD_Start, RTE_VAR_NOINIT) Rte_CS_ServerQueue_Coding_CheckNCD_Start; /* PRQA S 0850, 1504, 3229 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_Qac */
VAR(Rte_CS_ServerQueueInfoType_Coding_CheckNCD_Start, RTE_VAR_NOINIT) Rte_CS_ServerQueueInfo_Coding_CheckNCD_Start; /* PRQA S 0850, 1504 */ /* MD_MSR_19.8, MD_MSR_8.10 */
VAR(Rte_CS_ClientQueueType_Coding_CheckNCD_Start, RTE_VAR_NOINIT) Rte_CS_ClientQueue_Dcm_RoutineServices_CheckNcd_Routine_Start; /* PRQA S 0850, 1504 */ /* MD_MSR_19.8, MD_MSR_8.10 */

#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

VAR(Rte_CS_ServerQueueType_Coding_ReadCPS_ConditionCheckRead, RTE_VAR_NOINIT) Rte_CS_ServerQueue_Coding_ReadCPS_ConditionCheckRead; /* PRQA S 0850, 1504 */ /* MD_MSR_19.8, MD_MSR_8.10 */
VAR(Rte_CS_ServerQueueInfoType_Coding_ReadCPS_ConditionCheckRead, RTE_VAR_NOINIT) Rte_CS_ServerQueueInfo_Coding_ReadCPS_ConditionCheckRead; /* PRQA S 0850, 1504 */ /* MD_MSR_19.8, MD_MSR_8.10 */
VAR(Rte_CS_ClientQueueType_Coding_ReadCPS_ConditionCheckRead, RTE_VAR_NOINIT) Rte_CS_ClientQueue_Dcm_DataServices_DID_37FE_Cps_ConditionCheckRead; /* PRQA S 0850, 1504 */ /* MD_MSR_19.8, MD_MSR_8.10 */

#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

VAR(Rte_CS_ServerQueueType_Coding_ReadCPS_ReadData, RTE_VAR_NOINIT) Rte_CS_ServerQueue_Coding_ReadCPS_ReadData; /* PRQA S 0850, 1504 */ /* MD_MSR_19.8, MD_MSR_8.10 */
VAR(Rte_CS_ServerQueueInfoType_Coding_ReadCPS_ReadData, RTE_VAR_NOINIT) Rte_CS_ServerQueueInfo_Coding_ReadCPS_ReadData; /* PRQA S 0850, 1504 */ /* MD_MSR_19.8, MD_MSR_8.10 */
VAR(Rte_CS_ClientQueueType_Coding_ReadCPS_ReadData, RTE_VAR_NOINIT) Rte_CS_ClientQueue_Dcm_DataServices_DID_37FE_Cps_ReadData; /* PRQA S 0850, 1504 */ /* MD_MSR_19.8, MD_MSR_8.10 */

#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

VAR(Rte_CS_ServerQueueType_Coding_ReadNCD_Start, RTE_VAR_NOINIT) Rte_CS_ServerQueue_Coding_ReadNCD_Start; /* PRQA S 0850, 1504 */ /* MD_MSR_19.8, MD_MSR_8.10 */
VAR(Rte_CS_ServerQueueInfoType_Coding_ReadNCD_Start, RTE_VAR_NOINIT) Rte_CS_ServerQueueInfo_Coding_ReadNCD_Start; /* PRQA S 0850, 1504 */ /* MD_MSR_19.8, MD_MSR_8.10 */
VAR(Rte_CS_ClientQueueType_Coding_ReadNCD_Start, RTE_VAR_NOINIT) Rte_CS_ClientQueue_Dcm_RoutineServices_ReadNcd_Routine_Start; /* PRQA S 0850, 1504 */ /* MD_MSR_19.8, MD_MSR_8.10 */

#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

VAR(Rte_CS_ServerQueueType_Coding_ReadProtocolData_ReadData, RTE_VAR_NOINIT) Rte_CS_ServerQueue_Coding_ReadProtocolData_ReadData; /* PRQA S 0850, 1504 */ /* MD_MSR_19.8, MD_MSR_8.10 */
VAR(Rte_CS_ServerQueueInfoType_Coding_ReadProtocolData_ReadData, RTE_VAR_NOINIT) Rte_CS_ServerQueueInfo_Coding_ReadProtocolData_ReadData; /* PRQA S 0850, 1504 */ /* MD_MSR_19.8, MD_MSR_8.10 */
VAR(Rte_CS_ClientQueueType_Coding_ReadProtocolData_ReadData, RTE_VAR_NOINIT) Rte_CS_ClientQueue_Dcm_DataServices_DID_37FF_ReadProtocolData_ReadData; /* PRQA S 0850, 1504 */ /* MD_MSR_19.8, MD_MSR_8.10 */

#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

VAR(Rte_CS_ServerQueueType_Coding_WriteNCD_Start, RTE_VAR_NOINIT) Rte_CS_ServerQueue_Coding_WriteNCD_Start; /* PRQA S 0850, 1504 */ /* MD_MSR_19.8, MD_MSR_8.10 */
VAR(Rte_CS_ServerQueueInfoType_Coding_WriteNCD_Start, RTE_VAR_NOINIT) Rte_CS_ServerQueueInfo_Coding_WriteNCD_Start; /* PRQA S 0850, 1504 */ /* MD_MSR_19.8, MD_MSR_8.10 */
VAR(Rte_CS_ClientQueueType_Coding_WriteNCD_Start, RTE_VAR_NOINIT) Rte_CS_ClientQueue_Dcm_RoutineServices_WriteNcd_Routine_Start; /* PRQA S 0850, 1504 */ /* MD_MSR_19.8, MD_MSR_8.10 */

#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

CONST(Rte_CS_ClientConfigType_Coding_CheckNCD_Start, RTE_CONST) Rte_CS_ClientConfig_Coding_CheckNCD_Start[1] = { /* PRQA S 0850 */ /* MD_MSR_19.8 */
  {
    &Rte_CS_ClientQueue_Dcm_RoutineServices_CheckNcd_Routine_Start
  }
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_Dcm_DataServices_DID_37FE_Cps_ConditionCheckRead[1] = {
  Task_5msBsw_Appl10
};

CONST(Rte_CS_ClientConfigType_Coding_ReadCPS_ConditionCheckRead, RTE_CONST) Rte_CS_ClientConfig_Coding_ReadCPS_ConditionCheckRead[1] = { /* PRQA S 0850 */ /* MD_MSR_19.8 */
  {
    1,
    Rte_CS_WaitingTaskList_Dcm_DataServices_DID_37FE_Cps_ConditionCheckRead,
    &Rte_CS_ClientQueue_Dcm_DataServices_DID_37FE_Cps_ConditionCheckRead
  }
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_Dcm_DataServices_DID_37FE_Cps_ReadData[1] = {
  Task_5msBsw_Appl10
};

CONST(Rte_CS_ClientConfigType_Coding_ReadCPS_ReadData, RTE_CONST) Rte_CS_ClientConfig_Coding_ReadCPS_ReadData[1] = { /* PRQA S 0850 */ /* MD_MSR_19.8 */
  {
    1,
    Rte_CS_WaitingTaskList_Dcm_DataServices_DID_37FE_Cps_ReadData,
    &Rte_CS_ClientQueue_Dcm_DataServices_DID_37FE_Cps_ReadData
  }
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_Dcm_RoutineServices_ReadNcd_Routine_Start[1] = {
  Task_5msBsw_Appl10
};

CONST(Rte_CS_ClientConfigType_Coding_ReadNCD_Start, RTE_CONST) Rte_CS_ClientConfig_Coding_ReadNCD_Start[1] = { /* PRQA S 0850 */ /* MD_MSR_19.8 */
  {
    1,
    Rte_CS_WaitingTaskList_Dcm_RoutineServices_ReadNcd_Routine_Start,
    &Rte_CS_ClientQueue_Dcm_RoutineServices_ReadNcd_Routine_Start
  }
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_Dcm_DataServices_DID_37FF_ReadProtocolData_ReadData[1] = {
  Task_5msBsw_Appl10
};

CONST(Rte_CS_ClientConfigType_Coding_ReadProtocolData_ReadData, RTE_CONST) Rte_CS_ClientConfig_Coding_ReadProtocolData_ReadData[1] = { /* PRQA S 0850 */ /* MD_MSR_19.8 */
  {
    1,
    Rte_CS_WaitingTaskList_Dcm_DataServices_DID_37FF_ReadProtocolData_ReadData,
    &Rte_CS_ClientQueue_Dcm_DataServices_DID_37FF_ReadProtocolData_ReadData
  }
};

CONST(TaskType, RTE_CONST) Rte_CS_WaitingTaskList_Dcm_RoutineServices_WriteNcd_Routine_Start[1] = {
  Task_5msBsw_Appl10
};

CONST(Rte_CS_ClientConfigType_Coding_WriteNCD_Start, RTE_CONST) Rte_CS_ClientConfig_Coding_WriteNCD_Start[1] = { /* PRQA S 0850 */ /* MD_MSR_19.8 */
  {
    1,
    Rte_CS_WaitingTaskList_Dcm_RoutineServices_WriteNcd_Routine_Start,
    &Rte_CS_ClientQueue_Dcm_RoutineServices_WriteNcd_Routine_Start
  }
};

#define RTE_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

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
FUNC(uint8, RTE_CODE) Rte_GetInternalModeIndex_Coding_DataMode(uint8 mode) /* PRQA S 3408 */ /* MD_Rte_3408 */
{
  uint8 ret;

  if (mode == 0U)
  {
    ret = 1U;
  }
  else if (mode == 1U)
  {
    ret = 0U;
  }
  else if (mode == 2U)
  {
    ret = 2U;
  }
  else if (mode == 3U)
  {
    ret = 3U;
  }
  else if (mode == 4U)
  {
    ret = 4U;
  }
  else
  {
    ret = 5U;
  }

  return ret;
}
/**********************************************************************************************************************
 * Helper functions for mode management
 *********************************************************************************************************************/

FUNC(uint8, RTE_CODE) Rte_GetInternalModeIndex_Coding_BusComMode(uint8 mode) /* PRQA S 3408 */ /* MD_Rte_3408 */
{
  uint8 ret;

  if (mode == 0U)
  {
    ret = 0U;
  }
  else if (mode == 1U)
  {
    ret = 1U;
  }
  else
  {
    ret = 2U;
  }

  return ret;
}

FUNC(uint8, RTE_CODE) Rte_GetInternalModeIndex_Coding_LifeCycle(Coding_LifeCycleRequestType mode) /* PRQA S 3408 */ /* MD_Rte_3408 */
{
  uint8 ret;

  if (mode == 0U)
  {
    ret = 0U;
  }
  else if (mode == 1U)
  {
    ret = 1U;
  }
  else if (mode == 2U)
  {
    ret = 2U;
  }
  else
  {
    ret = 3U;
  }

  return ret;
}

FUNC(uint8, RTE_CODE) Rte_GetInternalModeIndex_Darh_LifeCycle(Darh_LifeCycleRequestType mode) /* PRQA S 3408 */ /* MD_Rte_3408 */
{
  uint8 ret;

  if (mode == 0U)
  {
    ret = 0U;
  }
  else if (mode == 1U)
  {
    ret = 1U;
  }
  else if (mode == 2U)
  {
    ret = 2U;
  }
  else
  {
    ret = 3U;
  }

  return ret;
}

FUNC(uint8, RTE_CODE) Rte_GetInternalModeIndex_DcmCommunicationControl(Dcm_CommunicationModeType mode) /* PRQA S 3408 */ /* MD_Rte_3408 */
{
  uint8 ret;

  if (mode == 0U)
  {
    ret = 10U;
  }
  else if (mode == 1U)
  {
    ret = 7U;
  }
  else if (mode == 2U)
  {
    ret = 1U;
  }
  else if (mode == 3U)
  {
    ret = 4U;
  }
  else if (mode == 4U)
  {
    ret = 9U;
  }
  else if (mode == 5U)
  {
    ret = 6U;
  }
  else if (mode == 6U)
  {
    ret = 0U;
  }
  else if (mode == 7U)
  {
    ret = 3U;
  }
  else if (mode == 8U)
  {
    ret = 11U;
  }
  else if (mode == 9U)
  {
    ret = 8U;
  }
  else if (mode == 10U)
  {
    ret = 2U;
  }
  else if (mode == 11U)
  {
    ret = 5U;
  }
  else
  {
    ret = 12U;
  }

  return ret;
} /* PRQA S 6030, 6080 */ /* MD_MSR_STCYC, MD_MSR_STMIF */

FUNC(uint8, RTE_CODE) Rte_GetInternalModeIndex_DcmDiagnosticSessionControl(Dcm_DiagnosticSessionControlType mode) /* PRQA S 3408 */ /* MD_Rte_3408 */
{
  uint8 ret;

  if (mode == 1U)
  {
    ret = 1U;
  }
  else if (mode == 2U)
  {
    ret = 6U;
  }
  else if (mode == 3U)
  {
    ret = 4U;
  }
  else if (mode == 65U)
  {
    ret = 0U;
  }
  else if (mode == 68U)
  {
    ret = 7U;
  }
  else if (mode == 79U)
  {
    ret = 2U;
  }
  else if (mode == 95U)
  {
    ret = 5U;
  }
  else if (mode == 97U)
  {
    ret = 8U;
  }
  else if (mode == 126U)
  {
    ret = 3U;
  }
  else
  {
    ret = 9U;
  }

  return ret;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

FUNC(uint8, RTE_CODE) Rte_GetInternalModeIndex_DcmEcuReset(Dcm_EcuResetType mode) /* PRQA S 3408 */ /* MD_Rte_3408 */
{
  uint8 ret;

  if (mode == 0U)
  {
    ret = 5U;
  }
  else if (mode == 1U)
  {
    ret = 1U;
  }
  else if (mode == 2U)
  {
    ret = 4U;
  }
  else if (mode == 3U)
  {
    ret = 6U;
  }
  else if (mode == 4U)
  {
    ret = 2U;
  }
  else if (mode == 5U)
  {
    ret = 3U;
  }
  else if (mode == 6U)
  {
    ret = 0U;
  }
  else
  {
    ret = 7U;
  }

  return ret;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

FUNC(uint8, RTE_CODE) Rte_GetInternalModeIndex_Dlog_LifeCycle(Dlog_LifeCycleRequestType mode) /* PRQA S 3408 */ /* MD_Rte_3408 */
{
  uint8 ret;

  if (mode == 0U)
  {
    ret = 0U;
  }
  else if (mode == 1U)
  {
    ret = 1U;
  }
  else if (mode == 2U)
  {
    ret = 2U;
  }
  else
  {
    ret = 3U;
  }

  return ret;
}

FUNC(uint8, RTE_CODE) Rte_GetInternalModeIndex_StdDiag_LifeCycle(StdDiag_LifeCycleRequestType mode) /* PRQA S 3408 */ /* MD_Rte_3408 */
{
  uint8 ret;

  if (mode == 0U)
  {
    ret = 0U;
  }
  else if (mode == 1U)
  {
    ret = 1U;
  }
  else if (mode == 2U)
  {
    ret = 2U;
  }
  else
  {
    ret = 3U;
  }

  return ret;
}

FUNC(uint8, RTE_CODE) Rte_GetInternalModeIndex_StdDiag_NormalCommunicationModeGroup(NormalCommunicationModeType mode) /* PRQA S 3408 */ /* MD_Rte_3408 */
{
  uint8 ret;

  if (mode == 0U)
  {
    ret = 0U;
  }
  else if (mode == 1U)
  {
    ret = 1U;
  }
  else if (mode == 2U)
  {
    ret = 2U;
  }
  else if (mode == 3U)
  {
    ret = 3U;
  }
  else
  {
    ret = 4U;
  }

  return ret;
}

FUNC(uint8, RTE_CODE) Rte_GetInternalModeIndex_SysTime_LifeCycle(SysTime_LifeCycleRequestType mode) /* PRQA S 3408 */ /* MD_Rte_3408 */
{
  uint8 ret;

  if (mode == 0U)
  {
    ret = 0U;
  }
  else if (mode == 1U)
  {
    ret = 1U;
  }
  else if (mode == 2U)
  {
    ret = 2U;
  }
  else
  {
    ret = 3U;
  }

  return ret;
}

FUNC(uint8, RTE_CODE) Rte_GetInternalModeIndex_Vin_LifeCycle(Vin_LifeCycleRequestType mode) /* PRQA S 3408 */ /* MD_Rte_3408 */
{
  uint8 ret;

  if (mode == 0U)
  {
    ret = 0U;
  }
  else if (mode == 1U)
  {
    ret = 1U;
  }
  else if (mode == 2U)
  {
    ret = 2U;
  }
  else
  {
    ret = 3U;
  }

  return ret;
}

FUNC(uint8, RTE_CODE) Rte_GetInternalModeIndex_Vin_VinComMode(uint8 mode) /* PRQA S 3408 */ /* MD_Rte_3408 */
{
  uint8 ret;

  if (mode == 0U)
  {
    ret = 1U;
  }
  else if (mode == 1U)
  {
    ret = 0U;
  }
  else
  {
    ret = 2U;
  }

  return ret;
}
/**********************************************************************************************************************
 * Helper functions for mode management
 *********************************************************************************************************************/

FUNC(uint8, RTE_CODE) Rte_GetInternalModeIndex_OmcExtendedOperatingMode(Omc_ExtendedOperatingModeType mode) /* PRQA S 3408 */ /* MD_Rte_3408 */
{
  uint8 ret;

  if (mode == 0U)
  {
    ret = 15U;
  }
  else if (mode == 1U)
  {
    ret = 0U;
  }
  else if (mode == 2U)
  {
    ret = 6U;
  }
  else if (mode == 3U)
  {
    ret = 7U;
  }
  else if (mode == 4U)
  {
    ret = 8U;
  }
  else if (mode == 5U)
  {
    ret = 9U;
  }
  else if (mode == 6U)
  {
    ret = 10U;
  }
  else if (mode == 7U)
  {
    ret = 11U;
  }
  else if (mode == 8U)
  {
    ret = 12U;
  }
  else if (mode == 9U)
  {
    ret = 13U;
  }
  else if (mode == 10U)
  {
    ret = 1U;
  }
  else if (mode == 11U)
  {
    ret = 2U;
  }
  else if (mode == 12U)
  {
    ret = 3U;
  }
  else if (mode == 13U)
  {
    ret = 4U;
  }
  else if (mode == 14U)
  {
    ret = 5U;
  }
  else if (mode == 15U)
  {
    ret = 16U;
  }
  else if (mode == 255U)
  {
    ret = 14U;
  }
  else
  {
    ret = 17U;
  }

  return ret;
} /* PRQA S 6030, 6080 */ /* MD_MSR_STCYC, MD_MSR_STMIF */

FUNC(uint8, RTE_CODE) Rte_GetInternalModeIndex_OmcOperatingMode(Omc_OperatingModeType mode) /* PRQA S 3408 */ /* MD_Rte_3408 */
{
  uint8 ret;

  if (mode == 0U)
  {
    ret = 2U;
  }
  else if (mode == 1U)
  {
    ret = 0U;
  }
  else if (mode == 2U)
  {
    ret = 3U;
  }
  else if (mode == 3U)
  {
    ret = 1U;
  }
  else
  {
    ret = 4U;
  }

  return ret;
}
/**********************************************************************************************************************
 * Helper functions for mode management
 *********************************************************************************************************************/

FUNC(uint8, RTE_CODE) Rte_GetInternalModeIndex_Vin_ChangeIndicator(uint8 mode) /* PRQA S 3408 */ /* MD_Rte_3408 */
{
  uint8 ret;

  if (mode == 0U)
  {
    ret = 1U;
  }
  else if (mode == 1U)
  {
    ret = 2U;
  }
  else if (mode == 2U)
  {
    ret = 0U;
  }
  else
  {
    ret = 3U;
  }

  return ret;
}

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

FUNC(void, RTE_CODE) Rte_MemCpy(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) destination, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, uint32_least num) /* PRQA S 3408, 1505 */ /* MD_Rte_3408, MD_MSR_8.10 */
{
  P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) src = source;
  P2VAR(uint8, AUTOMATIC, RTE_APPL_VAR) dst = destination;
  uint32_least i;
  for (i = 0; i < num; i++)
  {
    dst[i] = src[i];
  }
}

#define RTE_MEMCPY32ALIGN (sizeof(uint32) - 1)

FUNC(void, RTE_CODE) Rte_MemCpy32(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) destination, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, uint32_least num)
{
  P2CONST(uint32, AUTOMATIC, RTE_APPL_DATA) asrc = source;
  P2VAR(uint32, AUTOMATIC, RTE_APPL_VAR) adst = destination;
  P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) src = source;
  P2VAR(uint8, AUTOMATIC, RTE_APPL_VAR) dst = destination;
  uint32_least i = 0;

  if (num >= 16)
  {
    if (((((uint32)src) & RTE_MEMCPY32ALIGN) == 0) && ((((uint32)dst) & RTE_MEMCPY32ALIGN) == 0)) /* PRQA S 0306 */ /* MD_Rte_0306 */
    {
      uint32_least asize = num / sizeof(uint32);
      uint32_least rem = num & RTE_MEMCPY32ALIGN;
      for (i = 0; i < (asize - 3); i += 4)
      {
        adst[i] = asrc[i];
        adst[i+1] = asrc[i+1];
        adst[i+2] = asrc[i+2];
        adst[i+3] = asrc[i+3];
      }

      while (i < asize)
      {
        adst[i] = asrc[i];
        ++i;
      }
      i = num - rem;
    }
    else
    {
      for (i = 0; (i + 15) < num; i += 16)
      {
        dst[i] = src[i];
        dst[i+1] = src[i+1];
        dst[i+2] = src[i+2];
        dst[i+3] = src[i+3];
        dst[i+4] = src[i+4];
        dst[i+5] = src[i+5];
        dst[i+6] = src[i+6];
        dst[i+7] = src[i+7];
        dst[i+8] = src[i+8];
        dst[i+9] = src[i+9];
        dst[i+10] = src[i+10];
        dst[i+11] = src[i+11];
        dst[i+12] = src[i+12];
        dst[i+13] = src[i+13];
        dst[i+14] = src[i+14];
        dst[i+15] = src[i+15];
      }
    }

  }
  while (i < num)
  {
    dst[i] = src[i];
    ++i;
  }
}

FUNC(void, RTE_CODE) Rte_MemClr(P2VAR(void, AUTOMATIC, RTE_VAR_NOINIT) ptr, uint16_least num)
{
  P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) dst = ptr;
  uint16_least i;
  for (i = 0; i < num; i++)
  {
    dst[i] = 0;
  }
}

FUNC(void, RTE_CODE) SchM_Init(void)
{
  /* activate the tasks */
  (void)ActivateTask(Task_5msBsw_Appl10); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)ActivateTask(Task_ComBsw_Appl10); /* PRQA S 3417 */ /* MD_Rte_Os */

  /* activate the alarms used for TimingEvents */
  (void)SetRelAlarm(Rte_Al_TE2_Task_4msBsw_Appl10_0_4ms, RTE_MSEC_OsCounter(0) + (TickType)1, RTE_MSEC_OsCounter(4)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE2_Task_ComBsw_Appl10_0_5ms, RTE_MSEC_FrCycleCounter(0) + (TickType)1, RTE_MSEC_FrCycleCounter(5)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE2_Task_5msBsw_Appl10_0_5ms, RTE_MSEC_OsCounter(0) + (TickType)1, RTE_MSEC_OsCounter(5)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE2_Task_10msBsw_Appl10_0_10ms, RTE_MSEC_OsCounter(0) + (TickType)1, RTE_MSEC_OsCounter(10)); /* PRQA S 3417 */ /* MD_Rte_Os */

  Rte_InitState = RTE_STATE_SCHM_INIT;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Start(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  /* C/S queue initialization */
  Rte_CS_ServerQueueInfo_Coding_CheckNCD_Start.Rte_Active = 0;
  Rte_CS_ClientQueue_Dcm_RoutineServices_CheckNcd_Routine_Start.Rte_CallCompleted = TRUE;
  Rte_CS_ServerQueueInfo_Coding_ReadCPS_ConditionCheckRead.Rte_Active = 0;
  Rte_CS_ClientQueue_Dcm_DataServices_DID_37FE_Cps_ConditionCheckRead.Rte_CallCompleted = TRUE;
  Rte_CS_ServerQueueInfo_Coding_ReadCPS_ReadData.Rte_Active = 0;
  Rte_CS_ClientQueue_Dcm_DataServices_DID_37FE_Cps_ReadData.Rte_CallCompleted = TRUE;
  Rte_CS_ServerQueueInfo_Coding_ReadNCD_Start.Rte_Active = 0;
  Rte_CS_ClientQueue_Dcm_RoutineServices_ReadNcd_Routine_Start.Rte_CallCompleted = TRUE;
  Rte_CS_ServerQueueInfo_Coding_ReadProtocolData_ReadData.Rte_Active = 0;
  Rte_CS_ClientQueue_Dcm_DataServices_DID_37FF_ReadProtocolData_ReadData.Rte_CallCompleted = TRUE;
  Rte_CS_ServerQueueInfo_Coding_WriteNCD_Start.Rte_Active = 0;
  Rte_CS_ClientQueue_Dcm_RoutineServices_WriteNcd_Routine_Start.Rte_CallCompleted = TRUE;

  /* activate the tasks */
  (void)ActivateTask(Task_100ms_Appl10); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)ActivateTask(Task_10ms_Appl10); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)ActivateTask(Task_Coding_Appl10); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)ActivateTask(Task_Init_Appl10); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)ActivateTask(Task_Init_Appl7); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)ActivateTask(Task_Init_Appl8); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)ActivateTask(Task_Init_Appl9); /* PRQA S 3417 */ /* MD_Rte_Os */

  /* activate the alarms used for TimingEvents */
  (void)SetRelAlarm(Rte_Al_TE_Task_2msTmplMonr_Appl10_0_2ms, RTE_MSEC_OsCounter(0) + (TickType)1, RTE_MSEC_OsCounter(2)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_Task_2msA_Appl10_0_2ms, RTE_MSEC_OsCounter(0) + (TickType)1, RTE_MSEC_OsCounter(2)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_Task_2ms_Appl8_0_2ms, RTE_MSEC_OsCounter(0) + (TickType)1, RTE_MSEC_OsCounter(2)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_Task_2ms_Appl7_0_2ms, RTE_MSEC_OsCounter(0) + (TickType)1, RTE_MSEC_OsCounter(2)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_Task_2ms_Appl9_0_2ms, RTE_MSEC_OsCounter(0) + (TickType)1, RTE_MSEC_OsCounter(2)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_Task_2msB_Appl10_0_2ms, RTE_MSEC_OsCounter(0) + (TickType)1, RTE_MSEC_OsCounter(2)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_Task_4ms_Appl10_0_4ms, RTE_MSEC_OsCounter(0) + (TickType)1, RTE_MSEC_OsCounter(4)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_Task_4ms_Appl7_0_4ms, RTE_MSEC_OsCounter(0) + (TickType)1, RTE_MSEC_OsCounter(4)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_Task_ComBsw_Appl10_0_10ms, RTE_MSEC_FrCycleCounter(0) + (TickType)1, RTE_MSEC_FrCycleCounter(10)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_Task_10ms_Appl10_0_10ms, RTE_MSEC_OsCounter(0) + (TickType)1, RTE_MSEC_OsCounter(10)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_Task_10ms_Appl9_0_10ms, RTE_MSEC_OsCounter(0) + (TickType)1, RTE_MSEC_OsCounter(10)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_Task_10ms_Appl8_0_10ms, RTE_MSEC_OsCounter(0) + (TickType)1, RTE_MSEC_OsCounter(10)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_Task_10ms_Appl7_0_10ms, RTE_MSEC_OsCounter(0) + (TickType)1, RTE_MSEC_OsCounter(10)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_Darh_QueueHandler, RTE_SEC_OsCounter(0) + (TickType)1, RTE_SEC_OsCounter(1)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_Task_100ms_Appl10_0_100ms, RTE_MSEC_OsCounter(0) + (TickType)1, RTE_MSEC_OsCounter(100)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_Task_100ms_Appl9_0_100ms, RTE_MSEC_OsCounter(0) + (TickType)1, RTE_MSEC_OsCounter(100)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_Task_100ms_Appl7_0_100ms, RTE_MSEC_OsCounter(0) + (TickType)1, RTE_MSEC_OsCounter(100)); /* PRQA S 3417 */ /* MD_Rte_Os */

  /* mode management initialization part 2 */
  (void)SetEvent(Task_10ms_Appl10, Rte_ModeEntryEventMask_BswM_Switch_ErrorMemoryLockSignalReceptionSwitchPort_currentEMLockSignalReceptionMode[RTE_MODE_ErrorMemoryLockSignalReceptionMode_EM_LOCK_NOT_RECEIVABLE]); /* PRQA S 3417 */ /* MD_Rte_Os */

  (void)SetEvent(Task_10ms_Appl10, Rte_ModeEntryEventMask_BswM_Switch_StdDiagSessionChangeIndicationPort_SessionModeDeclarationGroup[RTE_MODE_StdDiag_SessionModeGroup_STDDIAG_DEFAULT_SESSION]); /* PRQA S 3417 */ /* MD_Rte_Os */

  (void)SetEvent(Task_100ms_Appl10, Rte_Ev_MS_Task_100ms_Appl10); /* PRQA S 3417 */ /* MD_Rte_Os */

  (void)SetEvent(Task_100ms_Appl10, Rte_Ev_MS_Task_100ms_Appl10); /* PRQA S 3417 */ /* MD_Rte_Os */

  (void)SetEvent(Task_100ms_Appl10, Rte_Ev_MS_Task_100ms_Appl10); /* PRQA S 3417 */ /* MD_Rte_Os */

  /* scheduled trigger for runnables: Dlog_ModeSwitchAckLifeCycle */
  (void)SetEvent(Task_10ms_Appl10, Rte_Ev_Run_Dlog_Dlog_ModeSwitchAckLifeCycle); /* PRQA S 3417 */ /* MD_Rte_Os */

  (void)SetEvent(Task_10ms_Appl10, Rte_Ev_MS_Task_10ms_Appl10); /* PRQA S 3417 */ /* MD_Rte_Os */

  (void)SetEvent(Task_100ms_Appl10, Rte_Ev_MS_Task_100ms_Appl10); /* PRQA S 3417 */ /* MD_Rte_Os */

  /* scheduled trigger for runnables: Vin_OnVinChangeIndicatorAck */
  (void)SetEvent(Task_100ms_Appl10, Rte_Ev_Run_Vin_Vin_OnVinChangeIndicatorAck); /* PRQA S 3417 */ /* MD_Rte_Os */


  Rte_InitState = RTE_STATE_INIT;

  return RTE_E_OK;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Stop(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  /* deactivate alarms */
  (void)CancelAlarm(Rte_Al_TE_Darh_QueueHandler); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_Task_100ms_Appl10_0_100ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_Task_100ms_Appl7_0_100ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_Task_100ms_Appl9_0_100ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_Task_10ms_Appl10_0_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_Task_10ms_Appl7_0_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_Task_10ms_Appl8_0_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_Task_10ms_Appl9_0_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_Task_2msA_Appl10_0_2ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_Task_2msB_Appl10_0_2ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_Task_2msTmplMonr_Appl10_0_2ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_Task_2ms_Appl7_0_2ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_Task_2ms_Appl8_0_2ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_Task_2ms_Appl9_0_2ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_Task_4ms_Appl10_0_4ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_Task_4ms_Appl7_0_4ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_Task_ComBsw_Appl10_0_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */

  Rte_InitState = RTE_STATE_SCHM_INIT;

  return RTE_E_OK;
}

FUNC(void, RTE_CODE) SchM_Deinit(void)
{
  /* deactivate alarms */
  (void)CancelAlarm(Rte_Al_TE2_Task_10msBsw_Appl10_0_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE2_Task_4msBsw_Appl10_0_4ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE2_Task_5msBsw_Appl10_0_5ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE2_Task_ComBsw_Appl10_0_5ms); /* PRQA S 3417 */ /* MD_Rte_Os */

  Rte_InitState = RTE_STATE_UNINIT;
}

FUNC(void, RTE_CODE) Rte_InitMemory(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  Rte_InitState = RTE_STATE_UNINIT;

  Rte_InitMemory_Appl10();
  Rte_InitMemory_Appl7();
  Rte_InitMemory_Appl8();
  Rte_InitMemory_Appl9();
}


/**********************************************************************************************************************
 * Exclusive area access
 *********************************************************************************************************************/

FUNC(void, RTE_CODE) SchM_Enter_Dio_DIO_REGISTER_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  SuspendOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
}

FUNC(void, RTE_CODE) SchM_Exit_Dio_DIO_REGISTER_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  ResumeOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
}


FUNC(void, RTE_CODE) SchM_Enter_Fls_FLS_CODE_FLASH_DISABLED(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
}

FUNC(void, RTE_CODE) SchM_Exit_Fls_FLS_CODE_FLASH_DISABLED(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
}


FUNC(void, RTE_CODE) SchM_Enter_Fls_FLS_DRIVERSTATE_DATA_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  SuspendOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
}

FUNC(void, RTE_CODE) SchM_Exit_Fls_FLS_DRIVERSTATE_DATA_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  ResumeOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
}


FUNC(void, RTE_CODE) SchM_Enter_Fls_FLS_REGISTER_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  SuspendOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
}

FUNC(void, RTE_CODE) SchM_Exit_Fls_FLS_REGISTER_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  ResumeOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
}


FUNC(void, RTE_CODE) SchM_Enter_Mcu_MCU_REGISTER_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  SuspendOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
}

FUNC(void, RTE_CODE) SchM_Exit_Mcu_MCU_REGISTER_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  ResumeOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
}


FUNC(void, RTE_CODE) SchM_Enter_Mcu_MCU_VARIABLE_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
}

FUNC(void, RTE_CODE) SchM_Exit_Mcu_MCU_VARIABLE_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
}


FUNC(void, RTE_CODE) SchM_Enter_Port_PORT_INIT_CONFIG_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
}

FUNC(void, RTE_CODE) SchM_Exit_Port_PORT_INIT_CONFIG_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
}


FUNC(void, RTE_CODE) SchM_Enter_Port_PORT_REFRESHPORT_INTERNAL_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
}

FUNC(void, RTE_CODE) SchM_Exit_Port_PORT_REFRESHPORT_INTERNAL_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
}


FUNC(void, RTE_CODE) SchM_Enter_Port_PORT_SET_PIN_DEFAULT_DIR_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
}

FUNC(void, RTE_CODE) SchM_Exit_Port_PORT_SET_PIN_DEFAULT_DIR_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
}


FUNC(void, RTE_CODE) SchM_Enter_Port_PORT_SET_PIN_DEFAULT_MODE_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
}

FUNC(void, RTE_CODE) SchM_Exit_Port_PORT_SET_PIN_DEFAULT_MODE_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
}


FUNC(void, RTE_CODE) SchM_Enter_Port_PORT_SET_PIN_DIR_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
}

FUNC(void, RTE_CODE) SchM_Exit_Port_PORT_SET_PIN_DIR_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
}


FUNC(void, RTE_CODE) SchM_Enter_Port_PORT_SET_PIN_MODE_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
}

FUNC(void, RTE_CODE) SchM_Exit_Port_PORT_SET_PIN_MODE_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
}


FUNC(void, RTE_CODE) SchM_Enter_Port_PORT_SET_TO_DIO_ALT_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
}

FUNC(void, RTE_CODE) SchM_Exit_Port_PORT_SET_TO_DIO_ALT_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
}


FUNC(void, RTE_CODE) SchM_Enter_Spi_SPI_CHIP_SELECT_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  SuspendOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
}

FUNC(void, RTE_CODE) SchM_Exit_Spi_SPI_CHIP_SELECT_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  ResumeOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
}


FUNC(void, RTE_CODE) SchM_Enter_Spi_SPI_RAM_DATA_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  SuspendOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
}

FUNC(void, RTE_CODE) SchM_Exit_Spi_SPI_RAM_DATA_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  ResumeOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
}


FUNC(void, RTE_CODE) SchM_Enter_Wdg_59_DriverA_MODE_SWITCH_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  SuspendOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
}

FUNC(void, RTE_CODE) SchM_Exit_Wdg_59_DriverA_MODE_SWITCH_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  ResumeOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
}


FUNC(void, RTE_CODE) SchM_Enter_Wdg_59_DriverA_TRIGG_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
}

FUNC(void, RTE_CODE) SchM_Exit_Wdg_59_DriverA_TRIGG_PROTECTION(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
}



/**********************************************************************************************************************
 * COM-Callbacks for DataReceivedEvent triggered runnables, inter-ECU client/server communication, for queued com. and for Rx timeout / Rx inv. flag (reset)
 *********************************************************************************************************************/

FUNC(void, RTE_CODE) Rte_COMCbk_ANFRAGE_ID2_fbd80461_In(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    /* scheduled trigger for runnables: Rmh_RxRequestMsg */
    (void)SetEvent(Task_10ms_Appl10, Rte_Ev_Run_Rmh_RxRequestMsg); /* PRQA S 3417 */ /* MD_Rte_Os */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_AVL_STEA_PNI_OFFS_9678c0e9(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_Appl10_RxUpdateFlags.Rte_RxUpdate_BmwMsgSlot108Bas0Repn2BusFrChA_AVL_STEA_PNI_OFFS_AVL_STEA_PNI_OFFS_Sender = !Rte_Appl10_RxUpdateFlags.Rte_RxUpdate_BmwMsgSlot108Bas0Repn2BusFrChA_AVL_STEA_PNI_OFFS_AVL_STEA_PNI_OFFS;
    Rte_Appl10_RxTimeoutFlags.Rte_RxTimeout_AVL_STEA_PNI_OFFS_9678c0e9 = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    /* scheduled trigger for runnables: STEA_OFFS_Received_Oper */
    (void)SetEvent(Task_10ms_Appl10, Rte_Ev_Run_BmwMsgSlot108Bas0Repn2BusFrChA_STEA_OFFS_Received_Oper); /* PRQA S 3417 */ /* MD_Rte_Os */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_CTR_WARN_DIR_VIB_EPS_66c73f8f(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_Appl10_RxTimeoutFlags.Rte_RxTimeout_CTR_WARN_DIR_VIB_EPS_66c73f8f = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    /* scheduled trigger for runnables: CTR_VIB_STW_DISP_EXMI_SP2015_Received */
    (void)SetEvent(Task_10ms_Appl10, Rte_Ev_Run_BmwMsgSlot269Bas2Repn4BusFrChA_CTR_VIB_STW_DISP_EXMI_SP2015_Received); /* PRQA S 3417 */ /* MD_Rte_Os */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_CTR_WARN_ILVL_VIB_EPS_66c73f8f(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_Appl10_RxTimeoutFlags.Rte_RxTimeout_CTR_WARN_ILVL_VIB_EPS_66c73f8f = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    /* scheduled trigger for runnables: CTR_VIB_STW_DISP_EXMI_SP2015_Received */
    (void)SetEvent(Task_10ms_Appl10, Rte_Ev_Run_BmwMsgSlot269Bas2Repn4BusFrChA_CTR_VIB_STW_DISP_EXMI_SP2015_Received); /* PRQA S 3417 */ /* MD_Rte_Os */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_CTR_WARN_PTRN_VIB_EPS_66c73f8f(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_Appl10_RxTimeoutFlags.Rte_RxTimeout_CTR_WARN_PTRN_VIB_EPS_66c73f8f = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    /* scheduled trigger for runnables: CTR_VIB_STW_DISP_EXMI_SP2015_Received */
    (void)SetEvent(Task_10ms_Appl10, Rte_Ev_Run_BmwMsgSlot269Bas2Repn4BusFrChA_CTR_VIB_STW_DISP_EXMI_SP2015_Received); /* PRQA S 3417 */ /* MD_Rte_Os */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_FACT_MO_STE_SO_DXP_59dc6376(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_Appl10_RxUpdateFlags.Rte_RxUpdate_BmwMsgSlot53Bas3Repn8BusFrChA_FACT_MO_STE_SO_DXP_FACT_MO_STE_SO_DXP_Sender = !Rte_Appl10_RxUpdateFlags.Rte_RxUpdate_BmwMsgSlot53Bas3Repn8BusFrChA_FACT_MO_STE_SO_DXP_FACT_MO_STE_SO_DXP;
    Rte_Appl10_RxTimeoutFlags.Rte_RxTimeout_FACT_MO_STE_SO_DXP_59dc6376 = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    /* scheduled trigger for runnables: SU_CLE_DRDY_DXP_Rxd */
    (void)SetEvent(Task_10ms_Appl10, Rte_Ev_Run_BmwMsgSlot53Bas3Repn8BusFrChA_SU_CLE_DRDY_DXP_Rxd); /* PRQA S 3417 */ /* MD_Rte_Os */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_MILE_KM_a6dd5496(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_Appl10_RxTimeoutFlags.Rte_RxTimeout_MILE_KM_a6dd5496 = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    /* scheduled trigger for runnables: MILE_KM_Received_Oper */
    (void)SetEvent(Task_10ms_Appl10, Rte_Ev_Run_BmwMsgSlot276Bas4Repn8BusFrChA_MILE_KM_Received_Oper); /* PRQA S 3417 */ /* MD_Rte_Os */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_ST_ENERG_FZM_e7ce1a0c(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_Appl10_RxTimeoutFlags.Rte_RxTimeout_ST_ENERG_FZM_e7ce1a0c = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    /* scheduled trigger for runnables: Stm_ReceiveEnergyMode */
    (void)SetEvent(Task_10ms_Appl10, Rte_Ev_Run_Stm_Runnable_ReceiveEnergyMode); /* PRQA S 3417 */ /* MD_Rte_Os */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_ST_ILK_ERRM_FZM_e7ce1a0c(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_Appl10_RxTimeoutFlags.Rte_RxTimeout_ST_ILK_ERRM_FZM_e7ce1a0c = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    /* scheduled trigger for runnables: Stm_ReceiveCentralErrorLock */
    (void)SetEvent(Task_10ms_Appl10, Rte_Ev_Run_Stm_Runnable_ReceiveCentralErrorLock); /* PRQA S 3417 */ /* MD_Rte_Os */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_SU_CLU_STMOM_SFE_DXP_59dc6376(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_Appl10_RxTimeoutFlags.Rte_RxTimeout_SU_CLU_STMOM_SFE_DXP_59dc6376 = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    /* scheduled trigger for runnables: SU_CLE_DRDY_DXP_Rxd */
    (void)SetEvent(Task_10ms_Appl10, Rte_Ev_Run_BmwMsgSlot53Bas3Repn8BusFrChA_SU_CLE_DRDY_DXP_Rxd); /* PRQA S 3417 */ /* MD_Rte_Os */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_T_SEC_COU_REL_0b27fbfe(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    /* scheduled trigger for runnables: SysTime_ReceiveSignal */
    (void)SetEvent(Task_10ms_Appl10, Rte_Ev_Run1_SysTime_ReceiveSignal); /* PRQA S 3417 */ /* MD_Rte_Os */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_sigGroup_ACLNY_MASSCNTR_461c64b1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_Appl10_RxUpdateFlags.Rte_RxUpdate_BmwMsgSlot55Bas0Repn2BusFrChA_sigGroup_ACLNY_MASSCNTR_sigGroup_ACLNY_MASSCNTR_Sender = !Rte_Appl10_RxUpdateFlags.Rte_RxUpdate_BmwMsgSlot55Bas0Repn2BusFrChA_sigGroup_ACLNY_MASSCNTR_sigGroup_ACLNY_MASSCNTR;
    Rte_Appl10_RxTimeoutFlags.Rte_RxTimeout_sigGroup_ACLNY_MASSCNTR_461c64b1 = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    /* scheduled trigger for runnables: ACLNY_MASSCNTR_Received_Oper */
    (void)SetEvent(Task_10ms_Appl10, Rte_Ev_Run_BmwMsgSlot55Bas0Repn2BusFrChA_ACLNY_MASSCNTR_Received_Oper); /* PRQA S 3417 */ /* MD_Rte_Os */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_sigGroup_CON_VEH_675e7344(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_Appl10_RxUpdateFlags.Rte_RxUpdate_BmwMsgSlot121Bas1Repn2BusFrChA_sigGroup_CON_VEH_sigGroup_CON_VEH_Sender = !Rte_Appl10_RxUpdateFlags.Rte_RxUpdate_BmwMsgSlot121Bas1Repn2BusFrChA_sigGroup_CON_VEH_sigGroup_CON_VEH;
    Rte_Appl10_RxTimeoutFlags.Rte_RxTimeout_sigGroup_CON_VEH_675e7344 = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    /* scheduled trigger for runnables: CON_VEH_Received_Oper */
    (void)SetEvent(Task_100ms_Appl10, Rte_Ev_Run_BmwMsgSlot121Bas1Repn2BusFrChA_CON_VEH_Received_Oper); /* PRQA S 3417 */ /* MD_Rte_Os */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_sigGroup_ENERG_DGR_DRDY_3f76efd3(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_Appl10_RxUpdateFlags.Rte_RxUpdate_BmwMsgSlot68Bas1Repn2BusFrChA_sigGroup_ENERG_DGR_DRDY_sigGroup_ENERG_DGR_DRDY_Sender = !Rte_Appl10_RxUpdateFlags.Rte_RxUpdate_BmwMsgSlot68Bas1Repn2BusFrChA_sigGroup_ENERG_DGR_DRDY_sigGroup_ENERG_DGR_DRDY;
    Rte_Appl10_RxTimeoutFlags.Rte_RxTimeout_sigGroup_ENERG_DGR_DRDY_3f76efd3 = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    /* scheduled trigger for runnables: ENERG_DGR_DRDY_Received_Oper */
    (void)SetEvent(Task_10ms_Appl10, Rte_Ev_Run_BmwMsgSlot68Bas1Repn2BusFrChA_ENERG_DGR_DRDY_Received_Oper); /* PRQA S 3417 */ /* MD_Rte_Os */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_sigGroup_OFFS_QUAD_EPS_cc150a52(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_Appl10_RxUpdateFlags.Rte_RxUpdate_BmwMsgSlot107Bas0Repn1BusFrChA_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS_Sender = !Rte_Appl10_RxUpdateFlags.Rte_RxUpdate_BmwMsgSlot107Bas0Repn1BusFrChA_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS;
    Rte_Appl10_RxTimeoutFlags.Rte_RxTimeout_sigGroup_OFFS_QUAD_EPS_cc150a52 = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    /* scheduled trigger for runnables: OFFS_QUAD_EPS_Received_Oper */
    (void)SetEvent(Task_10ms_Appl10, Rte_Ev_Run_BmwMsgSlot107Bas0Repn1BusFrChA_OFFS_QUAD_EPS_Received_Oper); /* PRQA S 3417 */ /* MD_Rte_Os */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_sigGroup_TAR_QTA_STRMOM_DV_231dfb08(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_Appl10_RxUpdateFlags.Rte_RxUpdate_BmwMsgSlot68Bas0Repn2BusFrChA_sigGroup_TAR_QTA_STRMOM_DV_sigGroup_TAR_QTA_STRMOM_DV_Sender = !Rte_Appl10_RxUpdateFlags.Rte_RxUpdate_BmwMsgSlot68Bas0Repn2BusFrChA_sigGroup_TAR_QTA_STRMOM_DV_sigGroup_TAR_QTA_STRMOM_DV;
    Rte_Appl10_RxTimeoutFlags.Rte_RxTimeout_sigGroup_TAR_QTA_STRMOM_DV_231dfb08 = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    /* scheduled trigger for runnables: TAR_QTA_STRMOM_DV_Rxd */
    (void)SetEvent(Task_10ms_Appl10, Rte_Ev_Run_BmwMsgSlot68Bas0Repn2BusFrChA_TAR_QTA_STRMOM_DV_Rxd); /* PRQA S 3417 */ /* MD_Rte_Os */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_sigGroup_TAR_STMOM_DV_ACT_9a7b28d3(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_Appl10_RxUpdateFlags.Rte_RxUpdate_BmwMsgSlot68Bas0Repn2BusFrChA_sigGroup_TAR_STMOM_DV_ACT_sigGroup_TAR_STMOM_DV_ACT_Sender = !Rte_Appl10_RxUpdateFlags.Rte_RxUpdate_BmwMsgSlot68Bas0Repn2BusFrChA_sigGroup_TAR_STMOM_DV_ACT_sigGroup_TAR_STMOM_DV_ACT;
    Rte_Appl10_RxTimeoutFlags.Rte_RxTimeout_sigGroup_TAR_STMOM_DV_ACT_9a7b28d3 = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    /* scheduled trigger for runnables: TAR_STMOM_DV_ACT_Rxd */
    (void)SetEvent(Task_10ms_Appl10, Rte_Ev_Run_BmwMsgSlot68Bas0Repn2BusFrChA_TAR_STMOM_DV_ACT_Rxd); /* PRQA S 3417 */ /* MD_Rte_Os */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_sigGroup_VYAW_VEH_fc66be94(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_Appl10_RxUpdateFlags.Rte_RxUpdate_BmwMsgSlot56Bas0Repn2BusFrChA_sigGroup_VYAW_VEH_sigGroup_VYAW_VEH_Sender = !Rte_Appl10_RxUpdateFlags.Rte_RxUpdate_BmwMsgSlot56Bas0Repn2BusFrChA_sigGroup_VYAW_VEH_sigGroup_VYAW_VEH;
    Rte_Appl10_RxTimeoutFlags.Rte_RxTimeout_sigGroup_VYAW_VEH_fc66be94 = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    /* scheduled trigger for runnables: VYAW_VEH_Received_Oper */
    (void)SetEvent(Task_10ms_Appl10, Rte_Ev_Run_BmwMsgSlot56Bas0Repn2BusFrChA_VYAW_VEH_Received_Oper); /* PRQA S 3417 */ /* MD_Rte_Os */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_sigGroup_V_VEH_2fe00c20(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_Appl10_RxUpdateFlags.Rte_RxUpdate_BmwMsgSlot55Bas3Repn4BusFrChA_sigGroup_V_VEH_sigGroup_V_VEH_Sender = !Rte_Appl10_RxUpdateFlags.Rte_RxUpdate_BmwMsgSlot55Bas3Repn4BusFrChA_sigGroup_V_VEH_sigGroup_V_VEH;
    Rte_Appl10_RxTimeoutFlags.Rte_RxTimeout_sigGroup_V_VEH_2fe00c20 = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    /* scheduled trigger for runnables: V_VEH_Received_Oper */
    (void)SetEvent(Task_100ms_Appl10, Rte_Ev_Run_BmwMsgSlot55Bas3Repn4BusFrChA_V_VEH_Received_Oper); /* PRQA S 3417 */ /* MD_Rte_Os */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */


/**********************************************************************************************************************
 * COM Callbacks for Rx Timeout Notification
 *********************************************************************************************************************/

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_AVL_STEA_PNI_OFFS_9678c0e9(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_Appl10_RxTimeoutFlags.Rte_RxTimeout_AVL_STEA_PNI_OFFS_9678c0e9 = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  if (Rte_InitState == RTE_STATE_INIT)
  {
    /* scheduled trigger for runnables: STEA_OFFS_Missing_Oper */
    (void)SetEvent(Task_10ms_Appl10, Rte_Ev_Run_BmwMsgSlot108Bas0Repn2BusFrChA_STEA_OFFS_Missing_Oper); /* PRQA S 3417 */ /* MD_Rte_Os */
  }
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_CTR_WARN_DIR_VIB_EPS_66c73f8f(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_Appl10_RxTimeoutFlags.Rte_RxTimeout_CTR_WARN_DIR_VIB_EPS_66c73f8f = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  if (Rte_InitState == RTE_STATE_INIT)
  {
    /* scheduled trigger for runnables: CTR_VIB_STW_DISP_EXMI_SP2015_Missing */
    (void)SetEvent(Task_10ms_Appl10, Rte_Ev_Run_BmwMsgSlot269Bas2Repn4BusFrChA_CTR_VIB_STW_DISP_EXMI_SP2015_Missing); /* PRQA S 3417 */ /* MD_Rte_Os */
  }
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_CTR_WARN_ILVL_VIB_EPS_66c73f8f(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_Appl10_RxTimeoutFlags.Rte_RxTimeout_CTR_WARN_ILVL_VIB_EPS_66c73f8f = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  if (Rte_InitState == RTE_STATE_INIT)
  {
    /* scheduled trigger for runnables: CTR_VIB_STW_DISP_EXMI_SP2015_Missing */
    (void)SetEvent(Task_10ms_Appl10, Rte_Ev_Run_BmwMsgSlot269Bas2Repn4BusFrChA_CTR_VIB_STW_DISP_EXMI_SP2015_Missing); /* PRQA S 3417 */ /* MD_Rte_Os */
  }
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_CTR_WARN_PTRN_VIB_EPS_66c73f8f(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_Appl10_RxTimeoutFlags.Rte_RxTimeout_CTR_WARN_PTRN_VIB_EPS_66c73f8f = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  if (Rte_InitState == RTE_STATE_INIT)
  {
    /* scheduled trigger for runnables: CTR_VIB_STW_DISP_EXMI_SP2015_Missing */
    (void)SetEvent(Task_10ms_Appl10, Rte_Ev_Run_BmwMsgSlot269Bas2Repn4BusFrChA_CTR_VIB_STW_DISP_EXMI_SP2015_Missing); /* PRQA S 3417 */ /* MD_Rte_Os */
  }
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_FACT_MO_STE_SO_DXP_59dc6376(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_Appl10_RxTimeoutFlags.Rte_RxTimeout_FACT_MO_STE_SO_DXP_59dc6376 = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  if (Rte_InitState == RTE_STATE_INIT)
  {
    /* scheduled trigger for runnables: SU_CLE_DRDY_DXP_Miss */
    (void)SetEvent(Task_10ms_Appl10, Rte_Ev_Run_BmwMsgSlot53Bas3Repn8BusFrChA_SU_CLE_DRDY_DXP_Miss); /* PRQA S 3417 */ /* MD_Rte_Os */
  }
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_MILE_KM_a6dd5496(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_Appl10_RxTimeoutFlags.Rte_RxTimeout_MILE_KM_a6dd5496 = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  if (Rte_InitState == RTE_STATE_INIT)
  {
    /* scheduled trigger for runnables: MILE_KM_Missing_Oper */
    (void)SetEvent(Task_10ms_Appl10, Rte_Ev_Run_BmwMsgSlot276Bas4Repn8BusFrChA_MILE_KM_Missing_Oper); /* PRQA S 3417 */ /* MD_Rte_Os */
  }
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_ST_ENERG_FZM_e7ce1a0c(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_Appl10_RxTimeoutFlags.Rte_RxTimeout_ST_ENERG_FZM_e7ce1a0c = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  if (Rte_InitState == RTE_STATE_INIT)
  {
    /* scheduled trigger for runnables: Stm_ErrorEnergyMode */
    (void)SetEvent(Task_10ms_Appl10, Rte_Ev_Run_Stm_Runnable_ErrorEnergyMode); /* PRQA S 3417 */ /* MD_Rte_Os */
  }
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_ST_ILK_ERRM_FZM_e7ce1a0c(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_Appl10_RxTimeoutFlags.Rte_RxTimeout_ST_ILK_ERRM_FZM_e7ce1a0c = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  if (Rte_InitState == RTE_STATE_INIT)
  {
    /* scheduled trigger for runnables: Stm_ErrorCentralErrorLock */
    (void)SetEvent(Task_10ms_Appl10, Rte_Ev_Run_Stm_Runnable_ErrorCentralErrorLock); /* PRQA S 3417 */ /* MD_Rte_Os */
  }
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_SU_CLU_STMOM_SFE_DXP_59dc6376(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_Appl10_RxTimeoutFlags.Rte_RxTimeout_SU_CLU_STMOM_SFE_DXP_59dc6376 = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  if (Rte_InitState == RTE_STATE_INIT)
  {
    /* scheduled trigger for runnables: SU_CLE_DRDY_DXP_Miss */
    (void)SetEvent(Task_10ms_Appl10, Rte_Ev_Run_BmwMsgSlot53Bas3Repn8BusFrChA_SU_CLE_DRDY_DXP_Miss); /* PRQA S 3417 */ /* MD_Rte_Os */
  }
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_sigGroup_ACLNY_MASSCNTR_461c64b1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_Appl10_RxTimeoutFlags.Rte_RxTimeout_sigGroup_ACLNY_MASSCNTR_461c64b1 = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  if (Rte_InitState == RTE_STATE_INIT)
  {
    /* scheduled trigger for runnables: ACLNY_MASSCNTR_Missing_Oper */
    (void)SetEvent(Task_10ms_Appl10, Rte_Ev_Run_BmwMsgSlot55Bas0Repn2BusFrChA_ACLNY_MASSCNTR_Missing_Oper); /* PRQA S 3417 */ /* MD_Rte_Os */
  }
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_sigGroup_CON_VEH_675e7344(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_Appl10_RxTimeoutFlags.Rte_RxTimeout_sigGroup_CON_VEH_675e7344 = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  if (Rte_InitState == RTE_STATE_INIT)
  {
    /* scheduled trigger for runnables: CON_VEH_Missing_Oper */
    (void)SetEvent(Task_100ms_Appl10, Rte_Ev_Run_BmwMsgSlot121Bas1Repn2BusFrChA_CON_VEH_Missing_Oper); /* PRQA S 3417 */ /* MD_Rte_Os */
  }
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_sigGroup_ENERG_DGR_DRDY_3f76efd3(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_Appl10_RxTimeoutFlags.Rte_RxTimeout_sigGroup_ENERG_DGR_DRDY_3f76efd3 = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  if (Rte_InitState == RTE_STATE_INIT)
  {
    /* scheduled trigger for runnables: ENERG_DGR_DRDY_Missing_Oper */
    (void)SetEvent(Task_10ms_Appl10, Rte_Ev_Run_BmwMsgSlot68Bas1Repn2BusFrChA_ENERG_DGR_DRDY_Missing_Oper); /* PRQA S 3417 */ /* MD_Rte_Os */
  }
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_sigGroup_OFFS_QUAD_EPS_cc150a52(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_Appl10_RxTimeoutFlags.Rte_RxTimeout_sigGroup_OFFS_QUAD_EPS_cc150a52 = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  if (Rte_InitState == RTE_STATE_INIT)
  {
    /* scheduled trigger for runnables: OFFS_QUAD_EPS_Missing_Oper */
    (void)SetEvent(Task_10ms_Appl10, Rte_Ev_Run_BmwMsgSlot107Bas0Repn1BusFrChA_OFFS_QUAD_EPS_Missing_Oper); /* PRQA S 3417 */ /* MD_Rte_Os */
  }
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_sigGroup_TAR_QTA_STRMOM_DV_231dfb08(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_Appl10_RxTimeoutFlags.Rte_RxTimeout_sigGroup_TAR_QTA_STRMOM_DV_231dfb08 = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  if (Rte_InitState == RTE_STATE_INIT)
  {
    /* scheduled trigger for runnables: TAR_QTA_STRMOM_DV_Miss */
    (void)SetEvent(Task_10ms_Appl10, Rte_Ev_Run_BmwMsgSlot68Bas0Repn2BusFrChA_TAR_QTA_STRMOM_DV_Miss); /* PRQA S 3417 */ /* MD_Rte_Os */
  }
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_sigGroup_TAR_STMOM_DV_ACT_9a7b28d3(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_Appl10_RxTimeoutFlags.Rte_RxTimeout_sigGroup_TAR_STMOM_DV_ACT_9a7b28d3 = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  if (Rte_InitState == RTE_STATE_INIT)
  {
    /* scheduled trigger for runnables: TAR_STMOM_DV_ACT_Miss */
    (void)SetEvent(Task_10ms_Appl10, Rte_Ev_Run_BmwMsgSlot68Bas0Repn2BusFrChA_TAR_STMOM_DV_ACT_Miss); /* PRQA S 3417 */ /* MD_Rte_Os */
  }
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_sigGroup_VYAW_VEH_fc66be94(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_Appl10_RxTimeoutFlags.Rte_RxTimeout_sigGroup_VYAW_VEH_fc66be94 = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  if (Rte_InitState == RTE_STATE_INIT)
  {
    /* scheduled trigger for runnables: VYAW_VEH_Missing_Oper */
    (void)SetEvent(Task_10ms_Appl10, Rte_Ev_Run_BmwMsgSlot56Bas0Repn2BusFrChA_VYAW_VEH_Missing_Oper); /* PRQA S 3417 */ /* MD_Rte_Os */
  }
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_sigGroup_V_VEH_2fe00c20(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_Appl10_RxTimeoutFlags.Rte_RxTimeout_sigGroup_V_VEH_2fe00c20 = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  if (Rte_InitState == RTE_STATE_INIT)
  {
    /* scheduled trigger for runnables: V_VEH_Missing_Oper */
    (void)SetEvent(Task_100ms_Appl10, Rte_Ev_Run_BmwMsgSlot55Bas3Repn4BusFrChA_V_VEH_Missing_Oper); /* PRQA S 3417 */ /* MD_Rte_Os */
  }
}


/**********************************************************************************************************************
 * RTE Schedulable entity for COM-Access from different partitions
 *********************************************************************************************************************/
FUNC(void, RTE_CODE) Rte_ComSendSignalProxyPeriodic(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

#define RTE_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0306:  MISRA rule: 11.3
     Reason:     An optimized copy algorithm can be used for aligned data. To check if pointers are aligned, pointers need to be casted to an integer type.
     Risk:       No functional risk. Only the lower 8 bits of the address are checked, therefore all integer types are sufficient.
     Prevention: Not required.

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

   MD_Rte_Qac:
     Reason:     This justification is used as summary justification for all deviations caused by wrong analysis tool results.
                 The used analysis tool QAC 7.0 sometimes creates wrong messages. Those deviations are no issues in the RTE code.
     Risk:       No functional risk.
     Prevention: Not required.

*/
