/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Mcu.c
 *        Config:  EPS.dpa
 *    BSW Module:  Mcu
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for BSW Module <Mcu>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_5.1_777, MD_MSR_5.1_779 */
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
/* PRQA S 0614 EOF */ /* MD_Rte_TestCode */

/* PRQA S 3109 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3112 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3197 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3198 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3199 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3201 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3203 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3205 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3206 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3218 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3229 EOF */ /* MD_Rte_TestCode */
/* PRQA S 2002 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3334 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3417 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3426 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3453 EOF */ /* MD_Rte_TestCode */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "SchM_Mcu.h"
#include "TSC_SchM_Mcu.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"


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
 * ACLNY_COG1: Integer in interval [0...65535]
 *   Unit: [m/s^2], Factor: 0.002, Offset: -65
 * ACLNY_COG_ERR_AMP1: Integer in interval [0...65535]
 *   Unit: [m/s^2], Factor: 0.005, Offset: 0
 * ACLNY_MASSCNTR_dummy_12_151: Integer in interval [0...255]
 * ALIV_CON_VEH1: Integer in interval [0...255]
 * ALIV_DISP_CC_EPS1: Integer in interval [0...255]
 * ALIV_DT_EST1: Integer in interval [0...255]
 * ALIV_ENERG_DGR_DRDY1: Integer in interval [0...255]
 * ALIV_SU_EPS1: Integer in interval [0...255]
 * ALIV_V_VEH1: Integer in interval [0...255]
 * AVL_FORC_GRD1: Integer in interval [0...65535]
 *   Unit: [kN], Factor: 0.0084, Offset: -17
 * AVL_FORC_GRD_dummy_12_151: Integer in interval [0...255]
 * AVL_PO_EPS1: Integer in interval [0...65535]
 * AVL_PO_IDX_EPS1: Integer in interval [0...65535]
 * AVL_PO_IDX_ICM1: Integer in interval [0...65535]
 * AVL_PWR_EL_EPS_COOD1: Integer in interval [0...255]
 *   Unit: [kW], Factor: 0.1, Offset: -12
 * AVL_STMOM_DV_ACT1: Integer in interval [0...65535]
 *   Factor: 0.005, Offset: -10
 * AVL_STMOM_DV_ACT_dummy_12_151: Integer in interval [0...255]
 * BATT_VLTG_EPS: Integer in interval [0...65535]
 * CHL_DISP_CC_EPS1: Integer in interval [0...255]
 * CON_VEH_dummy_56_631: Integer in interval [0...255]
 * CRC_ACLNY_COG1: Integer in interval [0...255]
 * CRC_AVL_FORC_GRD1: Integer in interval [0...255]
 * CRC_AVL_PO_EPS1: Integer in interval [0...255]
 * CRC_AVL_STMOM_DV_ACT1: Integer in interval [0...255]
 * CRC_CON_VEH1: Integer in interval [0...255]
 * CRC_DISP_CC_EPS1: Integer in interval [0...255]
 * CRC_DT_EST1: Integer in interval [0...255]
 * CRC_ENERG_DGR_DRDY1: Integer in interval [0...255]
 * CRC_OFFS_QUAD_EPS1: Integer in interval [0...255]
 * CRC_ST_EST_FTAX1: Integer in interval [0...255]
 * CRC_SU_EPS1: Integer in interval [0...255]
 * CRC_TAR_QTA_STMOM_DV1: Integer in interval [0...255]
 * CRC_TAR_STMOM_DV_ACT1: Integer in interval [0...255]
 * CRC_VYAW_VEH1: Integer in interval [0...255]
 * CRC_V_VEH1: Integer in interval [0...255]
 * CTR_FKTN_PRTNT1: Integer in interval [0...4294967295]
 * ComM_InhibitionStatusType: Integer in interval [0...255]
 * ComM_UserHandleType: Integer in interval [0...255]
 * ConstVoidPtr: DataReference
 * CounterType: Integer in interval [0...255]
 * DBG_EPS_BS_MOD_58_BYTE_ID2: Integer in interval [0...255]
 * DT_EST_dummy_12_151: Integer in interval [0...255]
 * DT_EST_dummy_16_471: Integer in interval [0...4294967295]
 * DT_EST_dummy_64_951: Integer in interval [0...4294967295]
 * DT_EST_dummy_96_1271: Integer in interval [0...4294967295]
 * DVCO_VEH1: Integer in interval [0...255]
 * Dem_DTCGroupType: Integer in interval [0...16777215]
 * Dem_DTCStatusMaskType: Integer in interval [0...255]
 * Dem_EventIdType: Integer in interval [1...72]
 * Dem_EventIdType: Integer in interval [1...65535]
 * Dem_OperationCycleIdType: Integer in interval [0...255]
 * Dem_RatioIdType: Integer in interval [1...65535]
 * ECU_TEMP_EPS: Integer in interval [0...255]
 * ENERG_DGR_DRDY_dummy_12_151: Integer in interval [0...255]
 * ESTIMD_PEAK_MOT_CURR_EPS: Integer in interval [0...4294967295]
 * EcuM_TimeType: Integer in interval [0...4294967295]
 * EcuM_UserType: Integer in interval [0...255]
 * FACT_ASS_STMOM_FTAX1: Integer in interval [0...255]
 *   Factor: 0.00390625, Offset: 1
 * FACT_CTRR_STMOM_FTAX1: Integer in interval [0...255]
 *   Factor: 0.00390625, Offset: 0.0078125
 * FACT_DMPNG_STMOM_FTAX1: Integer in interval [0...255]
 *   Factor: 0.00390625, Offset: 0.0078125
 * IOHWAB_BOOL: Boolean
 * MILE_KM1: Integer in interval [0...16777214]
 * MOT_FET_TEMP_EPS: Integer in interval [0...255]
 * MOT_MAG_TEMP_EPS: Integer in interval [0...255]
 * MOT_TQ_CMD_EPS: Integer in interval [0...65535]
 * MOT_TQ_CMD_LIMD_EPS: Integer in interval [0...65535]
 * MOT_VEL_EPS: Integer in interval [0...65535]
 * MOT_WIDG_TEMP_EPS: Integer in interval [0...65535]
 * NO_CC_EPS1: Integer in interval [0...65535]
 * NetworkHandleType: Integer in interval [0...255]
 * NvM_BlockIdType: Integer in interval [1...32767]
 * NvM_BlockIdType: Integer in interval [1...32767]
 * NvM_DstPtrType: DataReference
 * NvM_DstPtrType: DataReference
 * NvM_SrcPtrType: DataReference
 * NvM_SrcPtrType: DataReference
 * NvM_SrcPtrType: DataReference
 * OFFS_GRD_MID_EPS1: Integer in interval [0...65535]
 * OFFS_QUAD_RTR_EPS1: Integer in interval [0...255]
 * PRIM_HW_TQ_SNSR_VLTG_EPS: Integer in interval [0...255]
 * QU_V_VEH_COG1: Integer in interval [0...255]
 * SECDRY_HW_TQ_SNSR_VLTG_EPS: Integer in interval [0...255]
 * ST_CON_VEH_EPS: Integer in interval [0...255]
 * ST_EST_dummy_16_231: Integer in interval [0...255]
 * ST_V_VEH_NSS1: Integer in interval [0...255]
 * SU_EPS_dummy_14_191: Integer in interval [0...255]
 * SU_EPS_dummy_20_511: Integer in interval [0...4294967295]
 * SYS_ST_EPS: Integer in interval [0...255]
 * SrcPtrType: DataReference
 * TAR_QTA_STMOM_DV1: Integer in interval [0...65535]
 *   Factor: 0.005, Offset: -10
 * TAR_QTA_STRMOM_DV_dummy_12_151: Integer in interval [0...255]
 * TAR_STMOM_DV_ACT1: Integer in interval [0...65535]
 *   Factor: 0.006, Offset: -12
 * TAR_STMOM_DV_ACT_dummy_12_151: Integer in interval [0...255]
 * TAR_STMOM_DV_ACT_dummy_32_511: Integer in interval [0...4294967295]
 * TOT_STR_EPS1: Integer in interval [0...65535]
 *   Factor: 0.012213, Offset: 0
 * TRANF_CC_EPS1: Integer in interval [0...255]
 * TimeInMicrosecondsType: Integer in interval [0...4294967295]
 * VEH_SPD_EPS: Integer in interval [0...65535]
 * VYAW_VEH1: Integer in interval [0...65535]
 *   Unit: [deg. /s], Factor: 0.005, Offset: -163.84
 * VYAW_VEH_ERR_AMP1: Integer in interval [0...65535]
 *   Unit: [deg. /s], Factor: 0.0125, Offset: 0
 * VYAW_VEH_dummy_12_151: Integer in interval [0...255]
 * V_VEH_COG1: Integer in interval [0...65535]
 * V_VEH_dummy_39_391: Integer in interval [0...255]
 * VoidPtr: DataReference
 * WdgM_CheckpointIdType: Integer in interval [0...65535]
 * WdgM_ModeType: Integer in interval [0...255]
 * WdgM_SupervisedEntityIdType: Integer in interval [0...65535]
 * boolean: Boolean (standard type)
 * boolean: Boolean (standard type)
 * dtRef_VOID: DataReference
 * dtRef_const_VOID: DataReference
 * float32: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * float32: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * s10p5: Integer in interval [-32768...32767]
 * s11p4: Integer in interval [-32768...32767]
 * s14p1: Integer in interval [-32768...32767]
 * s15p0: Integer in interval [-32768...32767]
 * s15p16: Integer in interval [-2147483648...2147483647]
 * s18p13: Integer in interval [-2147483648...2147483647]
 * s1p14: Integer in interval [-32768...32767]
 * s2p13: Integer in interval [-32768...32767]
 * s3p12: Integer in interval [-32768...32767]
 * s4p11: Integer in interval [-32768...32767]
 * s5p10: Integer in interval [-32768...32767]
 * s7p8: Integer in interval [-32768...32767]
 * s8p7: Integer in interval [-32768...32767]
 * sint16: Integer in interval [-32768...32767] (standard type)
 * sint16: Integer in interval [-32768...32767] (standard type)
 * sint32: Integer in interval [-2147483648...2147483647] (standard type)
 * sint8: Integer in interval [-128...127] (standard type)
 * sint8: Integer in interval [-128...127] (standard type)
 * sm5p12: Integer in interval [-128...127]
 * sm6p13: Integer in interval [-128...127]
 * u0p16: Integer in interval [0...65535]
 * u10p6: Integer in interval [0...65535]
 * u11p5: Integer in interval [0...65535]
 * u12p4: Integer in interval [0...65535]
 * u13p3: Integer in interval [0...65535]
 * u15p1: Integer in interval [0...65535]
 * u16p0: Integer in interval [0...65535]
 * u1p15: Integer in interval [0...65535]
 * u2p14: Integer in interval [0...65535]
 * u3p13: Integer in interval [0...65535]
 * u4p12: Integer in interval [0...65535]
 * u5p11: Integer in interval [0...65535]
 * u6p10: Integer in interval [0...65535]
 * u7p9: Integer in interval [0...65535]
 * u8p8: Integer in interval [0...65535]
 * u9p7: Integer in interval [0...65535]
 * uint16: Integer in interval [0...65535] (standard type)
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * ALIV_ACLNY_COG1: Enumeration of integer in interval [0...255] with enumerators
 * ALIV_AVL_FORC_GRD1: Enumeration of integer in interval [0...255] with enumerators
 * ALIV_AVL_PO_EPS1: Enumeration of integer in interval [0...255] with enumerators
 * ALIV_AVL_STMOM_DV_ACT1: Enumeration of integer in interval [0...255] with enumerators
 * ALIV_OFFS_QUAD_EPS1: Enumeration of integer in interval [0...255] with enumerators
 * ALIV_ST_EST_FTAX1: Enumeration of integer in interval [0...255] with enumerators
 * ALIV_TAR_QTA_STMOM_DV1: Enumeration of integer in interval [0...255] with enumerators
 * ALIV_TAR_STMOM_DV_ACT1: Enumeration of integer in interval [0...255] with enumerators
 * ALIV_VYAW_VEH1: Enumeration of integer in interval [0...255] with enumerators
 * AVL_I_ACT_EST1: Enumeration of integer in interval [0...255] with enumerators
 *   Unit: [A], Factor: 1, Offset: 0
 * AVL_STEA_PNI_OFFS1: Enumeration of integer in interval [2046...188098] with enumerators
 *   Factor: 0.021994, Offset: -45
 * AdrMpgReqTyp1: Enumeration of integer in interval [0...255] with enumerators
 * BattRtnCurrAmprQlfr1: Enumeration of integer in interval [0...255] with enumerators
 * BmwBasPtlNetCtrl1: Enumeration of integer in interval [0...255] with enumerators
 * BmwCogVehSpdQlfr1: Enumeration of integer in interval [0...255] with enumerators
 * BmwEpsDeactvnCtrl1: Enumeration of integer in interval [0...255] with enumerators
 * BmwEpsFctSts1: Enumeration of integer in interval [0...255] with enumerators
 * BmwFltLampFlsgFrq1: Enumeration of integer in interval [0...255] with enumerators
 * BmwFltLampReqSts1: Enumeration of integer in interval [0...255] with enumerators
 * BmwFltLampReqTyp2: Enumeration of integer in interval [0...65535] with enumerators
 * BmwHaptcFbDirNr1: Enumeration of integer in interval [0...255] with enumerators
 * BmwHaptcFbIntenNr1: Enumeration of integer in interval [0...255] with enumerators
 * BmwHaptcFbPatNr1: Enumeration of integer in interval [0...255] with enumerators
 * BmwMaxCurrLimrSts1: Enumeration of integer in interval [0...255] with enumerators
 * BmwMaxCurrLimrSts1: Enumeration of integer in interval [0...255] with enumerators
 * BmwMotAgSelnSt1: Enumeration of integer in interval [0...255] with enumerators
 * BmwNearStillVehSpdSts1: Enumeration of integer in interval [0...255] with enumerators
 * BmwOvrlCmdQlfr1: Enumeration of integer in interval [0...255] with enumerators
 * BmwOvrlCmdQlfr1: Enumeration of integer in interval [0...255] with enumerators
 * BmwPinionAgOffsSts1: Enumeration of integer in interval [0...255] with enumerators
 * BmwPinionAgOffsSts1: Enumeration of integer in interval [0...255] with enumerators
 * BmwPinionAgQlfr1: Enumeration of integer in interval [0...255] with enumerators
 * BmwQuadOffsSts1: Enumeration of integer in interval [0...255] with enumerators
 * BmwRackToVehCentrOffsSts1: Enumeration of integer in interval [0...255] with enumerators
 * BmwRqrdCurrLimEpsSfty1: Enumeration of integer in interval [0...255] with enumerators
 * BmwRtIdx1: Enumeration of integer in interval [0...255] with enumerators
 * BmwRtIdx1: Enumeration of integer in interval [0...255] with enumerators
 * BmwSecurVehSpdSts1: Enumeration of integer in interval [0...255] with enumerators
 * BmwSeldPosnUnit1: Enumeration of integer in interval [0...255] with enumerators
 * BmwSetVehCentrOffsSts1: Enumeration of integer in interval [0...255] with enumerators
 * BmwSteerMdfnFacSts1: Enumeration of integer in interval [0...255] with enumerators
 * BmwTqSnsrIdx1: Enumeration of integer in interval [0...255] with enumerators
 * BmwTrfcJamAssiDampgStReq1: Enumeration of integer in interval [0...255] with enumerators
 * BmwTrfcJamAssiDampgStReq1: Enumeration of integer in interval [0...255] with enumerators
 * BmwTrfcJamAssiSt1: Enumeration of integer in interval [0...255] with enumerators
 * BmwVehCdn1: Enumeration of integer in interval [0...255] with enumerators
 * BmwVehCdnQlfr1: Enumeration of integer in interval [0...255] with enumerators
 * BmwVehLatAQlfr1: Enumeration of integer in interval [0...255] with enumerators
 * BmwVehSpdSts1: Enumeration of integer in interval [0...255] with enumerators
 * BmwVehYawQlfr1: Enumeration of integer in interval [0...255] with enumerators
 * CTR_BS_PRTNT1: Enumeration of integer in interval [0...255] with enumerators
 * CTR_DEAC_EPS_FNS1: Enumeration of integer in interval [0...255] with enumerators
 * CTR_WARN_DIR_VIB_EPS1: Enumeration of integer in interval [0...3] with enumerators
 * CTR_WARN_ILVL_VIB_EPS1: Enumeration of integer in interval [0...15] with enumerators
 * CTR_WARN_PTRN_VIB_EPS1: Enumeration of integer in interval [0...15] with enumerators
 * CalCopySts1: Enumeration of integer in interval [0...255] with enumerators
 * Coding_ConditionModeType: Enumeration of integer in interval [0...255] with enumerators
 * Coding_LifeCycleRequestType: Enumeration of integer in interval [0...255] with enumerators
 * ComM_ModeType: Enumeration of integer in interval [0...255] with enumerators
 * CrcHwResvCfg1: Enumeration of integer in interval [0...255] with enumerators
 * CrcHwResvMod1: Enumeration of integer in interval [0...255] with enumerators
 * CrcHwSts1: Enumeration of integer in interval [0...255] with enumerators
 * Darh_LifeCycleRequestType: Enumeration of integer in interval [0...255] with enumerators
 * Darh_RoeStateType: Enumeration of integer in interval [0...255] with enumerators
 * Darh_RoeStateType: Enumeration of integer in interval [0...255] with enumerators
 * Darh_SuspendedStateType: Enumeration of integer in interval [0...255] with enumerators
 * Dcm_CommunicationModeType: Enumeration of integer in interval [0...255] with enumerators
 * Dcm_ConfirmationStatusType: Enumeration of integer in interval [0...255] with enumerators
 * Dcm_ConfirmationStatusType: Enumeration of integer in interval [0...255] with enumerators
 * Dcm_ConfirmationStatusType: Enumeration of integer in interval [0...3] with enumerators
 * Dcm_ControlDtcSettingType: Enumeration of integer in interval [0...255] with enumerators
 * Dcm_DiagnosticSessionControlType: Enumeration of integer in interval [0...255] with enumerators
 * Dcm_EcuResetType: Enumeration of integer in interval [0...255] with enumerators
 * Dcm_NegativeResponseCodeType: Enumeration of integer in interval [0...255] with enumerators
 * Dcm_NegativeResponseCodeType: Enumeration of integer in interval [0...255] with enumerators
 * Dcm_NegativeResponseCodeType: Enumeration of integer in interval [16...254] with enumerators
 * Dcm_NegativeResponseCodeType: Enumeration of integer in interval [16...254] with enumerators
 * Dcm_NegativeResponseCodeType: Enumeration of integer in interval [16...254] with enumerators
 * Dcm_NegativeResponseCodeType: Enumeration of integer in interval [0...255] with enumerators
 * Dcm_OpStatusType: Enumeration of integer in interval [0...3] with enumerators
 * Dcm_OpStatusType: Enumeration of integer in interval [0...3] with enumerators
 * Dcm_OpStatusType: Enumeration of integer in interval [0...255] with enumerators
 * Dcm_OpStatusType: Enumeration of integer in interval [0...3] with enumerators
 * Dcm_OpStatusType: Enumeration of integer in interval [0...255] with enumerators
 * Dcm_ProtocolType: Enumeration of integer in interval [0...255] with enumerators
 * Dcm_RequestKindType: Enumeration of integer in interval [0...255] with enumerators
 * Dcm_ResponseOnEventType: Enumeration of integer in interval [0...255] with enumerators
 * Dcm_SecLevelType: Enumeration of integer in interval [0...255] with enumerators
 * Dcm_SesCtrlType: Enumeration of integer in interval [1...66] with enumerators
 * Dcm_SesCtrlType: Enumeration of integer in interval [0...255] with enumerators
 * Dem_DTCFormatType: Enumeration of integer in interval [0...255] with enumerators
 * Dem_DTCFormatType: Enumeration of integer in interval [0...2] with enumerators
 * Dem_DTCFormatType: Enumeration of integer in interval [0...2] with enumerators
 * Dem_DTCKindType: Enumeration of integer in interval [0...255] with enumerators
 * Dem_DTCOriginType: Enumeration of integer in interval [0...65535] with enumerators
 * Dem_DTCOriginType: Enumeration of integer in interval [1...4] with enumerators
 * Dem_DTCSeverityType: Enumeration of integer in interval [0...255] with enumerators
 * Dem_DTRControlType: Enumeration of integer in interval [0...255] with enumerators
 * Dem_DebounceResetStatusType: Enumeration of integer in interval [0...255] with enumerators
 * Dem_DebouncingStateType: Enumeration of integer in interval [0...255] with enumerators
 * Dem_EventStatusType: Enumeration of integer in interval [0...255] with enumerators
 * Dem_EventStatusType: Enumeration of integer in interval [0...4] with enumerators
 * Dem_EventStatusType: Enumeration of integer in interval [0...4] with enumerators
 * Dem_EventStatusType: Enumeration of integer in interval [0...255] with enumerators
 * Dem_IndicatorStatusType: Enumeration of integer in interval [0...255] with enumerators
 * Dem_InitMonitorReasonType: Enumeration of integer in interval [0...255] with enumerators
 * Dem_IumprDenomCondIdType: Enumeration of integer in interval [0...255] with enumerators
 * Dem_IumprDenomCondStatusType: Enumeration of integer in interval [0...255] with enumerators
 * Dem_IumprReadinessGroupType: Enumeration of integer in interval [0...255] with enumerators
 * Dem_MonitorStatusType: Enumeration of integer in interval [0...255] with enumerators
 * Dem_OperationCycleStateType: Enumeration of integer in interval [0...255] with enumerators
 * Dem_UdsStatusByteType: Enumeration of integer in interval [0...255] with enumerators
 * Dlog_LifeCycleRequestType: Enumeration of integer in interval [0...255] with enumerators
 * DrvgDynIfSt1: Enumeration of integer in interval [0...255] with enumerators
 * DrvgDynIfSt1: Enumeration of integer in interval [0...255] with enumerators
 * ENERG_AVAI_ARS1: Enumeration of integer in interval [0...255] with enumerators
 *   Factor: 1, Offset: 0
 * EcuM_BootTargetType: Enumeration of integer in interval [0...255] with enumerators
 * EcuM_ModeType: Enumeration of integer in interval [0...255] with enumerators
 * EcuM_ShutdownCauseType: Enumeration of integer in interval [0...255] with enumerators
 * EcuM_StateType: Enumeration of integer in interval [0...255] with enumerators
 * EgyModSt1: Enumeration of integer in interval [0...255] with enumerators
 * EotSt1: Enumeration of integer in interval [0...255] with enumerators
 * EpsCurrLimSts1: Enumeration of integer in interval [0...255] with enumerators
 * FACT_DMPNG_ADDON_STMOM_FTAX1: Enumeration of integer in interval [0...255] with enumerators
 *   Factor: 0.015625, Offset: 0
 * FACT_MO_STE_SO_DXP1: Enumeration of integer in interval [0...12500] with enumerators
 *   Factor: 0.02, Offset: 0
 * GetSegMod1: Enumeration of integer in interval [0...255] with enumerators
 * HaptcFbSt1: Enumeration of integer in interval [0...255] with enumerators
 * HaptcFbSt1: Enumeration of integer in interval [0...255] with enumerators
 * IDX_TORQ_SEN1: Enumeration of integer in interval [0...255] with enumerators
 * IvtrFetFltPha1: Enumeration of integer in interval [0...255] with enumerators
 * IvtrFetFltTyp1: Enumeration of integer in interval [0...255] with enumerators
 * LoaSt1: Enumeration of integer in interval [0...255] with enumerators
 * MAX_I_LD_SPEC_ARS1: Enumeration of integer in interval [0...255] with enumerators
 *   Unit: [A], Factor: 1, Offset: 0
 * MAX_I_RECUP_SPEC_ARS1: Enumeration of integer in interval [0...255] with enumerators
 *   Unit: [A], Factor: 1, Offset: -252
 * MAX_I_SPEC_BAX_STE1: Enumeration of integer in interval [0...255] with enumerators
 *   Unit: [A], Factor: 1, Offset: 0
 * MAX_I_SPEC_EPS1: Enumeration of integer in interval [0...255] with enumerators
 *   Unit: [A], Factor: 1, Offset: 0
 * MfgEnaSt1: Enumeration of integer in interval [0...255] with enumerators
 * MotAgSnsrCfgSt1: Enumeration of integer in interval [0...255] with enumerators
 * MotCurrEolCalSt2: Enumeration of integer in interval [0...255] with enumerators
 * MotQuad1: Enumeration of integer in interval [0...255] with enumerators
 * NormalCommunicationModeType: Enumeration of integer in interval [0...255] with enumerators
 * NtcNr1: Enumeration of integer in interval [0...65535] with enumerators
 * NtcNrWithResd1: Enumeration of integer in interval [0...65535] with enumerators
 * NtcSts1: Enumeration of integer in interval [0...255] with enumerators
 * NvM_RequestResultType: Enumeration of integer in interval [0...255] with enumerators
 * NvM_RequestResultType: Enumeration of integer in interval [0...255] with enumerators
 * NvM_RequestResultType: Enumeration of integer in interval [0...255] with enumerators
 * NvM_RequestResultType: Enumeration of integer in interval [0...8] with enumerators
 * NvM_RequestResultType: Enumeration of integer in interval [0...8] with enumerators
 * NvM_RequestResultType: Enumeration of integer in interval [0...255] with enumerators
 * NvM_ServiceIdType: Enumeration of integer in interval [0...255] with enumerators
 * Omc_ExtendedOperatingModeType: Enumeration of integer in interval [0...255] with enumerators
 * Omc_ExtendedOperatingModeType: Enumeration of integer in interval [0...255] with enumerators
 * Omc_LifeCycleRequestType: Enumeration of integer in interval [0...255] with enumerators
 * Omc_OperatingModeType: Enumeration of integer in interval [0...255] with enumerators
 * Omc_OperatingModeType: Enumeration of integer in interval [0...255] with enumerators
 * OpStatusType: Enumeration of integer in interval [0...255] with enumerators
 * PhaDiscnctPwmVect1: Enumeration of integer in interval [0...255] with enumerators
 * QU_ACLNY_COG1: Enumeration of integer in interval [0...255] with enumerators
 * QU_AVL_FORC_GRD1: Enumeration of integer in interval [0...255] with enumerators
 * QU_AVL_I_ACT_EST1: Enumeration of integer in interval [0...255] with enumerators
 * QU_AVL_PO_EPS1: Enumeration of integer in interval [0...255] with enumerators
 * QU_AVL_STMOM_DV_ACT1: Enumeration of integer in interval [0...255] with enumerators
 * QU_DGR_AISP_ENERG1: Enumeration of integer in interval [0...255] with enumerators
 * QU_FN_EST1: Enumeration of integer in interval [0...255] with enumerators
 * QU_FN_VIB_EPS1: Enumeration of integer in interval [0...255] with enumerators
 * QU_SER_STMOM_DV_ACT1: Enumeration of integer in interval [0...255] with enumerators
 * QU_ST_CON_VEH1: Enumeration of integer in interval [0...255] with enumerators
 * QU_TAR_DMPNG_ADDON_STMOM_FTAX1: Enumeration of integer in interval [0...255] with enumerators
 * QU_TAR_FACT_STMOM_FTAX1: Enumeration of integer in interval [0...255] with enumerators
 * QU_TAR_QTA_STMOM_DV1: Enumeration of integer in interval [0...255] with enumerators
 * QU_TAR_STMOM_DV_ACT1: Enumeration of integer in interval [0...255] with enumerators
 * QU_VYAW_VEH1: Enumeration of integer in interval [0...255] with enumerators
 * QU_V_VEH_COG1: Enumeration of integer in interval [0...255] with enumerators
 * RQ_CULI_EST_SFY1: Enumeration of integer in interval [0...255] with enumerators
 * RequestResultType: Enumeration of integer in interval [0...255] with enumerators
 * RtIdxChgSts1: Enumeration of integer in interval [0...255] with enumerators
 * ST_CC_EPS1: Enumeration of integer in interval [0...255] with enumerators
 * ST_CON_VEH1: Enumeration of integer in interval [0...255] with enumerators
 * ST_CULI_EST1: Enumeration of integer in interval [0...255] with enumerators
 * ST_IDC_CC_EPS1: Enumeration of integer in interval [0...255] with enumerators
 * ST_OFFS_QUAD_EPS1: Enumeration of integer in interval [0...255] with enumerators
 * ST_V_VEH_NSS1: Enumeration of integer in interval [0...255] with enumerators
 * SU_CLU_STMOM_SFE_DXP1: Enumeration of integer in interval [0...15] with enumerators
 * SigQlfr1: Enumeration of integer in interval [0...255] with enumerators
 * StdDiag_LifeCycleRequestType: Enumeration of integer in interval [0...255] with enumerators
 * SteerMod1: Enumeration of integer in interval [0...255] with enumerators
 * Stm_CentralErrorLockType: Enumeration of integer in interval [0...255] with enumerators
 * Stm_EnergyStateType: Enumeration of integer in interval [0...255] with enumerators
 * Stm_VehicleStateType: Enumeration of integer in interval [0...255] with enumerators
 * Stm_VehicleStateType: Enumeration of integer in interval [0...255] with enumerators
 * StsDrvrActvy1: Enumeration of integer in interval [0...255] with enumerators
 * StsSteerAssi1: Enumeration of integer in interval [0...255] with enumerators
 * SysFricLrngOperMod1: Enumeration of integer in interval [0...255] with enumerators
 * SysSt1: Enumeration of integer in interval [0...255] with enumerators
 * SysTime_LifeCycleRequestType: Enumeration of integer in interval [0...255] with enumerators
 * TrigReg1: Enumeration of integer in interval [0...255] with enumerators
 * UN_PO_EPS1: Enumeration of integer in interval [0...255] with enumerators
 * UN_TOT_STR_EPS1: Enumeration of integer in interval [0...255] with enumerators
 * Vin_LifeCycleRequestType: Enumeration of integer in interval [0...255] with enumerators
 * Vin_QualifierType: Enumeration of integer in interval [0...255] with enumerators
 * Vin_QualifierType: Enumeration of integer in interval [0...255] with enumerators
 * WdgM_GlobalStatusType: Enumeration of integer in interval [0...255] with enumerators
 * WdgM_LocalStatusType: Enumeration of integer in interval [0...255] with enumerators
 *
 * Array Types:
 * ============
 * ActiveSessionState_ArrayType: Array with 4 element(s) of type uint8
 * Array4: Array with 4 element(s) of type uint8
 * Ary1D_BlkFltTblRec1_5: Array with 5 element(s) of type BlkFltTblRec1
 * Ary1D_CmdRtnBufRec1_NvMProxy1: Array with 65535 element(s) of type CmdRtnBufRec1
 * Ary1D_CrcHwStsRec2_8: Array with 8 element(s) of type CrcHwStsRec2
 * Ary1D_NtcFltInfoRec2_20: Array with 20 element(s) of type NtcFltInfoRec2
 * Ary1D_NtcInfoRec4_DiagcMgr: Array with 65535 element(s) of type NtcInfoRec4
 * Ary1D_NtcInfoRec4_DiagcMgrProxyAppl10: Array with 65535 element(s) of type NtcInfoRec4
 * Ary1D_NtcInfoRec4_DiagcMgrProxyAppl7: Array with 65535 element(s) of type NtcInfoRec4
 * Ary1D_NtcInfoRec4_DiagcMgrProxyAppl8: Array with 65535 element(s) of type NtcInfoRec4
 * Ary1D_NtcInfoRec4_DiagcMgrProxyAppl9: Array with 65535 element(s) of type NtcInfoRec4
 * Ary1D_OnlineCalPageInfoRec1_2: Array with 2 element(s) of type OnlineCalPageInfoRec1
 * Ary1D_OnlineCalSegInfoRec1_TunSelnMngt1: Array with 65535 element(s) of type OnlineCalSegInfoRec1
 * Ary1D_ReadFltInfoRec1_20: Array with 20 element(s) of type ReadFltInfoRec1
 * Ary1D_SnpshtDataRec1_8: Array with 8 element(s) of type SnpshtDataRec1
 * Ary1D_SnpshtDataRec2_8: Array with 8 element(s) of type SnpshtDataRec2
 * Ary1D_boolean_4: Array with 4 element(s) of type boolean
 * Ary1D_boolean_NvMProxy1: Array with 65535 element(s) of type boolean
 * Ary1D_f32_11: Array with 11 element(s) of type float32
 * Ary1D_f32_12: Array with 12 element(s) of type float32
 * Ary1D_f32_2: Array with 2 element(s) of type float32
 * Ary1D_f32_26: Array with 26 element(s) of type float32
 * Ary1D_f32_3: Array with 3 element(s) of type float32
 * Ary1D_f32_4: Array with 4 element(s) of type float32
 * Ary1D_f32_5: Array with 5 element(s) of type float32
 * Ary1D_f32_8: Array with 8 element(s) of type float32
 * Ary1D_logl_3: Array with 3 element(s) of type boolean
 * Ary1D_logl_4: Array with 4 element(s) of type boolean
 * Ary1D_s10p5_8: Array with 8 element(s) of type s10p5
 * Ary1D_s11p4_14: Array with 14 element(s) of type s11p4
 * Ary1D_s14p1_4: Array with 4 element(s) of type s14p1
 * Ary1D_s15p0_10: Array with 10 element(s) of type s15p0
 * Ary1D_s15p0_21: Array with 21 element(s) of type s15p0
 * Ary1D_s15p0_4: Array with 4 element(s) of type s15p0
 * Ary1D_s15p0_5: Array with 5 element(s) of type s15p0
 * Ary1D_s16_DiagcMgrProxyAppl10: Array with 65535 element(s) of type sint16
 * Ary1D_s16_DiagcMgrProxyAppl7: Array with 65535 element(s) of type sint16
 * Ary1D_s16_DiagcMgrProxyAppl8: Array with 65535 element(s) of type sint16
 * Ary1D_s16_DiagcMgrProxyAppl9: Array with 65535 element(s) of type sint16
 * Ary1D_s1p14_128: Array with 128 element(s) of type s1p14
 * Ary1D_s2p13_21: Array with 21 element(s) of type s2p13
 * Ary1D_s3p12_4: Array with 4 element(s) of type s3p12
 * Ary1D_s4p11_12: Array with 12 element(s) of type s4p11
 * Ary1D_s4p11_13: Array with 13 element(s) of type s4p11
 * Ary1D_s4p11_7: Array with 7 element(s) of type s4p11
 * Ary1D_s7p8_4: Array with 4 element(s) of type s7p8
 * Ary1D_s8p7_12: Array with 12 element(s) of type s8p7
 * Ary1D_s8p7_21: Array with 21 element(s) of type s8p7
 * Ary1D_s8p7_4: Array with 4 element(s) of type s8p7
 * Ary1D_sm5p12_128: Array with 128 element(s) of type sm5p12
 * Ary1D_sm6p13_144: Array with 144 element(s) of type sm6p13
 * Ary1D_u08_20: Array with 20 element(s) of type uint8
 * Ary1D_u08_3: Array with 3 element(s) of type uint8
 * Ary1D_u08_48: Array with 48 element(s) of type uint8
 * Ary1D_u08_6: Array with 6 element(s) of type uint8
 * Ary1D_u08_DiagcMgr1: Array with 65535 element(s) of type uint8
 * Ary1D_u0p16_10: Array with 10 element(s) of type u0p16
 * Ary1D_u0p16_2: Array with 2 element(s) of type u0p16
 * Ary1D_u0p16_8: Array with 8 element(s) of type u0p16
 * Ary1D_u10p6_12: Array with 12 element(s) of type u10p6
 * Ary1D_u10p6_4: Array with 4 element(s) of type u10p6
 * Ary1D_u10p6_9: Array with 9 element(s) of type u10p6
 * Ary1D_u11p5_10: Array with 10 element(s) of type u11p5
 * Ary1D_u11p5_12: Array with 12 element(s) of type u11p5
 * Ary1D_u11p5_4: Array with 4 element(s) of type u11p5
 * Ary1D_u11p5_6: Array with 6 element(s) of type u11p5
 * Ary1D_u12p4_10: Array with 10 element(s) of type u12p4
 * Ary1D_u12p4_12: Array with 12 element(s) of type u12p4
 * Ary1D_u12p4_2: Array with 2 element(s) of type u12p4
 * Ary1D_u12p4_4: Array with 4 element(s) of type u12p4
 * Ary1D_u12p4_7: Array with 7 element(s) of type u12p4
 * Ary1D_u12p4_9: Array with 9 element(s) of type u12p4
 * Ary1D_u13p3_2: Array with 2 element(s) of type u13p3
 * Ary1D_u13p3_6: Array with 6 element(s) of type u13p3
 * Ary1D_u15p1_12: Array with 12 element(s) of type u15p1
 * Ary1D_u15p1_24: Array with 24 element(s) of type u15p1
 * Ary1D_u15p1_4: Array with 4 element(s) of type u15p1
 * Ary1D_u15p1_9: Array with 9 element(s) of type u15p1
 * Ary1D_u16_12: Array with 12 element(s) of type uint16
 * Ary1D_u16_13: Array with 13 element(s) of type uint16
 * Ary1D_u16_16: Array with 16 element(s) of type uint16
 * Ary1D_u16_3: Array with 3 element(s) of type uint16
 * Ary1D_u16_512: Array with 512 element(s) of type uint16
 * Ary1D_u16p0_2: Array with 2 element(s) of type u16p0
 * Ary1D_u16p0_8: Array with 8 element(s) of type u16p0
 * Ary1D_u1p15_10: Array with 10 element(s) of type u1p15
 * Ary1D_u1p15_11: Array with 11 element(s) of type u1p15
 * Ary1D_u1p15_12: Array with 12 element(s) of type u1p15
 * Ary1D_u1p15_2: Array with 2 element(s) of type u1p15
 * Ary1D_u1p15_21: Array with 21 element(s) of type u1p15
 * Ary1D_u1p15_4: Array with 4 element(s) of type u1p15
 * Ary1D_u1p15_5: Array with 5 element(s) of type u1p15
 * Ary1D_u1p15_6: Array with 6 element(s) of type u1p15
 * Ary1D_u1p15_9: Array with 9 element(s) of type u1p15
 * Ary1D_u2p14_10: Array with 10 element(s) of type u2p14
 * Ary1D_u2p14_12: Array with 12 element(s) of type u2p14
 * Ary1D_u2p14_16: Array with 16 element(s) of type u2p14
 * Ary1D_u2p14_2: Array with 2 element(s) of type u2p14
 * Ary1D_u2p14_4: Array with 4 element(s) of type u2p14
 * Ary1D_u2p14_5: Array with 5 element(s) of type u2p14
 * Ary1D_u2p14_7: Array with 7 element(s) of type u2p14
 * Ary1D_u2p14_8: Array with 8 element(s) of type u2p14
 * Ary1D_u2p14_9: Array with 9 element(s) of type u2p14
 * Ary1D_u32_2: Array with 2 element(s) of type uint32
 * Ary1D_u32_4: Array with 4 element(s) of type uint32
 * Ary1D_u32_8: Array with 8 element(s) of type uint32
 * Ary1D_u3p13_10: Array with 10 element(s) of type u3p13
 * Ary1D_u3p13_5: Array with 5 element(s) of type u3p13
 * Ary1D_u4p12_10: Array with 10 element(s) of type u4p12
 * Ary1D_u4p12_11: Array with 11 element(s) of type u4p12
 * Ary1D_u4p12_12: Array with 12 element(s) of type u4p12
 * Ary1D_u4p12_13: Array with 13 element(s) of type u4p12
 * Ary1D_u4p12_2: Array with 2 element(s) of type u4p12
 * Ary1D_u4p12_20: Array with 20 element(s) of type u4p12
 * Ary1D_u4p12_21: Array with 21 element(s) of type u4p12
 * Ary1D_u4p12_24: Array with 24 element(s) of type u4p12
 * Ary1D_u4p12_5: Array with 5 element(s) of type u4p12
 * Ary1D_u4p12_6: Array with 6 element(s) of type u4p12
 * Ary1D_u4p12_8: Array with 8 element(s) of type u4p12
 * Ary1D_u4p12_9: Array with 9 element(s) of type u4p12
 * Ary1D_u5p11_10: Array with 10 element(s) of type u5p11
 * Ary1D_u5p11_11: Array with 11 element(s) of type u5p11
 * Ary1D_u5p11_14: Array with 14 element(s) of type u5p11
 * Ary1D_u5p11_17: Array with 17 element(s) of type u5p11
 * Ary1D_u5p11_21: Array with 21 element(s) of type u5p11
 * Ary1D_u5p11_5: Array with 5 element(s) of type u5p11
 * Ary1D_u5p11_6: Array with 6 element(s) of type u5p11
 * Ary1D_u5p11_9: Array with 9 element(s) of type u5p11
 * Ary1D_u6p10_10: Array with 10 element(s) of type u6p10
 * Ary1D_u6p10_12: Array with 12 element(s) of type u6p10
 * Ary1D_u6p10_13: Array with 13 element(s) of type u6p10
 * Ary1D_u6p10_17: Array with 17 element(s) of type u6p10
 * Ary1D_u6p10_2: Array with 2 element(s) of type u6p10
 * Ary1D_u6p10_20: Array with 20 element(s) of type u6p10
 * Ary1D_u6p10_6: Array with 6 element(s) of type u6p10
 * Ary1D_u6p10_8: Array with 8 element(s) of type u6p10
 * Ary1D_u6p10_9: Array with 9 element(s) of type u6p10
 * Ary1D_u7p9_12: Array with 12 element(s) of type u7p9
 * Ary1D_u8_10: Array with 10 element(s) of type uint8
 * Ary1D_u8_16: Array with 16 element(s) of type uint8
 * Ary1D_u8_20: Array with 20 element(s) of type uint8
 * Ary1D_u8_20: Array with 20 element(s) of type uint8
 * Ary1D_u8_48: Array with 48 element(s) of type uint8
 * Ary1D_u8_6: Array with 6 element(s) of type uint8
 * Ary1D_u8_8: Array with 8 element(s) of type uint8
 * Ary1D_u8_CmnMfgSrvIf: Array with 65535 element(s) of type uint8
 * Ary1D_u8p8_10: Array with 10 element(s) of type u8p8
 * Ary1D_u8p8_11: Array with 11 element(s) of type u8p8
 * Ary1D_u8p8_12: Array with 12 element(s) of type u8p8
 * Ary1D_u8p8_6: Array with 6 element(s) of type u8p8
 * Ary1D_u8p8_8: Array with 8 element(s) of type u8p8
 * Ary1D_u9p7_10: Array with 10 element(s) of type u9p7
 * Ary1D_u9p7_11: Array with 11 element(s) of type u9p7
 * Ary1D_u9p7_12: Array with 12 element(s) of type u9p7
 * Ary1D_u9p7_16: Array with 16 element(s) of type u9p7
 * Ary1D_u9p7_2: Array with 2 element(s) of type u9p7
 * Ary1D_u9p7_4: Array with 4 element(s) of type u9p7
 * Ary1D_u9p7_5: Array with 5 element(s) of type u9p7
 * Ary1D_u9p7_6: Array with 6 element(s) of type u9p7
 * Ary1D_u9p7_7: Array with 7 element(s) of type u9p7
 * Ary1D_u9p7_8: Array with 8 element(s) of type u9p7
 * Ary2D_f32_4_2: Array with 4 element(s) of type Ary1D_f32_2
 * Ary2D_f32_5_3: Array with 5 element(s) of type Ary1D_f32_3
 * Ary2D_f32_5_4: Array with 5 element(s) of type Ary1D_f32_4
 * Ary2D_f32_5_5: Array with 5 element(s) of type Ary1D_f32_5
 * Ary2D_f32_8_4: Array with 8 element(s) of type Ary1D_f32_4
 * Ary2D_s4p11_10_13: Array with 10 element(s) of type Ary1D_s4p11_13
 * Ary2D_u0p16_4_2: Array with 4 element(s) of type Ary1D_u0p16_2
 * Ary2D_u10p6_8_12: Array with 8 element(s) of type Ary1D_u10p6_12
 * Ary2D_u10p6_8_9: Array with 8 element(s) of type Ary1D_u10p6_9
 * Ary2D_u12p4_4_2: Array with 4 element(s) of type Ary1D_u12p4_2
 * Ary2D_u12p4_5_4: Array with 5 element(s) of type Ary1D_u12p4_4
 * Ary2D_u12p4_8_12: Array with 8 element(s) of type Ary1D_u12p4_12
 * Ary2D_u15p1_10_24: Array with 10 element(s) of type Ary1D_u15p1_24
 * Ary2D_u15p1_12_9: Array with 12 element(s) of type Ary1D_u15p1_9
 * Ary2D_u16_8_3: Array with 8 element(s) of type Ary1D_u16_3
 * Ary2D_u16p0_2_8: Array with 2 element(s) of type Ary1D_u16p0_8
 * Ary2D_u1p15_12_12: Array with 12 element(s) of type Ary1D_u1p15_12
 * Ary2D_u1p15_12_9: Array with 12 element(s) of type Ary1D_u1p15_9
 * Ary2D_u1p15_5_4: Array with 5 element(s) of type Ary1D_u1p15_4
 * Ary2D_u2p14_12_12: Array with 12 element(s) of type Ary1D_u2p14_12
 * Ary2D_u2p14_12_4: Array with 12 element(s) of type Ary1D_u2p14_4
 * Ary2D_u2p14_5_10: Array with 5 element(s) of type Ary1D_u2p14_10
 * Ary2D_u2p14_5_8: Array with 5 element(s) of type Ary1D_u2p14_8
 * Ary2D_u2p14_6_7: Array with 6 element(s) of type Ary1D_u2p14_7
 * Ary2D_u2p14_7_8: Array with 7 element(s) of type Ary1D_u2p14_8
 * Ary2D_u4p12_10_24: Array with 10 element(s) of type Ary1D_u4p12_24
 * Ary2D_u4p12_12_12: Array with 12 element(s) of type Ary1D_u4p12_12
 * Ary2D_u4p12_12_20: Array with 12 element(s) of type Ary1D_u4p12_20
 * Ary2D_u4p12_12_9: Array with 12 element(s) of type Ary1D_u4p12_9
 * Ary2D_u4p12_13_13: Array with 13 element(s) of type Ary1D_u4p12_13
 * Ary2D_u5p11_9_9: Array with 9 element(s) of type Ary1D_u5p11_9
 * Ary2D_u6p10_12_12: Array with 12 element(s) of type Ary1D_u6p10_12
 * Ary2D_u6p10_12_20: Array with 12 element(s) of type Ary1D_u6p10_20
 * Ary2D_u6p10_12_9: Array with 12 element(s) of type Ary1D_u6p10_9
 * Ary2D_u6p10_13_13: Array with 13 element(s) of type Ary1D_u6p10_13
 * Ary2D_u6p10_5_9: Array with 5 element(s) of type Ary1D_u6p10_9
 * Ary2D_u6p10_8_9: Array with 8 element(s) of type Ary1D_u6p10_9
 * Ary2D_u8p8_5_10: Array with 5 element(s) of type Ary1D_u8p8_10
 * Ary2D_u8p8_5_8: Array with 5 element(s) of type Ary1D_u8p8_8
 * Ary2D_u9p7_2_5: Array with 2 element(s) of type Ary1D_u9p7_5
 * Ary2D_u9p7_2_8: Array with 2 element(s) of type Ary1D_u9p7_8
 * CheckProgrammingPreconditions_ArrayType: Array with 256 element(s) of type uint8
 * Coding_CafIdArrayType: Array with 8 element(s) of type uint8
 * Coding_CafIdArrayType: Array with 8 element(s) of type uint8
 * Darh_ActivelyReportedErrorListType: Array with 39 element(s) of type uint8
 * DataArrayType_uint8_1: Array with 1 element(s) of type uint8
 * DataArrayType_uint8_2: Array with 2 element(s) of type uint8
 * DataArrayType_uint8_3: Array with 3 element(s) of type uint8
 * DataArrayType_uint8_4: Array with 4 element(s) of type uint8
 * Dcm_Data100ByteType: Array with 100 element(s) of type uint8
 * Dcm_Data1024ByteType: Array with 1024 element(s) of type uint8
 * Dcm_Data1024ByteType: Array with 1024 element(s) of type uint8
 * Dcm_Data10ByteType: Array with 10 element(s) of type uint8
 * Dcm_Data12ByteType: Array with 12 element(s) of type uint8
 * Dcm_Data132ByteType: Array with 132 element(s) of type uint8
 * Dcm_Data140ByteType: Array with 140 element(s) of type uint8
 * Dcm_Data15ByteType: Array with 15 element(s) of type uint8
 * Dcm_Data17ByteType: Array with 17 element(s) of type uint8
 * Dcm_Data18ByteType: Array with 18 element(s) of type uint8
 * Dcm_Data18ByteType: Array with 18 element(s) of type uint8
 * Dcm_Data1ByteType: Array with 1 element(s) of type uint8
 * Dcm_Data20ByteType: Array with 20 element(s) of type uint8
 * Dcm_Data256ByteType: Array with 256 element(s) of type uint8
 * Dcm_Data2ByteType: Array with 2 element(s) of type uint8
 * Dcm_Data3ByteType: Array with 3 element(s) of type uint8
 * Dcm_Data40ByteType: Array with 40 element(s) of type uint8
 * Dcm_Data48ByteType: Array with 48 element(s) of type uint8
 * Dcm_Data4ByteType: Array with 4 element(s) of type uint8
 * Dcm_Data57ByteType: Array with 57 element(s) of type uint8
 * Dcm_Data6ByteType: Array with 6 element(s) of type uint8
 * Dcm_Data6ByteType: Array with 6 element(s) of type uint8
 * Dcm_Data7ByteType: Array with 7 element(s) of type uint8
 * Dcm_Data8195ByteType: Array with 8195 element(s) of type uint8
 * Dcm_Data8ByteType: Array with 8 element(s) of type uint8
 * Dcm_Data9ByteType: Array with 9 element(s) of type uint8
 * Dcm_Data9ByteType: Array with 9 element(s) of type uint8
 * Dem_MaxDataValueType: Array with 4 element(s) of type uint8
 * Dem_MaxDataValueType: Array with 4 element(s) of type uint8
 * DevInfoArrayType: Array with 11 element(s) of type uint8
 * DiagCommLoopback_ArrayType: Array with 1024 element(s) of type uint8
 * Dlog_EcuUidArrayType: Array with 16 element(s) of type uint8
 * Dlog_HWModificationIndexArrayType: Array with 2 element(s) of type uint8
 * Dlog_ProgIdArrayType: Array with 8 element(s) of type uint8
 * Dlog_ProgIdArrayType: Array with 8 element(s) of type uint8
 * Dlog_SignatureArrayType: Array with 260 element(s) of type uint8
 * Dlog_VinArrayType: Array with 17 element(s) of type uint8
 * Dlog_VinArrayType: Array with 17 element(s) of type uint8
 * ManufacturingDataArrayType: Array with 3 element(s) of type uint8
 * NO_VECH_1: Array with 1 element(s) of type uint8
 * NO_VECH_2: Array with 1 element(s) of type uint8
 * NO_VECH_3: Array with 1 element(s) of type uint8
 * NO_VECH_4: Array with 1 element(s) of type uint8
 * NO_VECH_5: Array with 1 element(s) of type uint8
 * NO_VECH_6: Array with 1 element(s) of type uint8
 * NO_VECH_7: Array with 1 element(s) of type uint8
 * ProgCounterArrayType: Array with 4 element(s) of type uint8
 * RSInputArrayType: Array with 8 element(s) of type uint8
 * RequestDataArray: Array with 1024 element(s) of type uint8
 * Rte_DT_Darh_TransmissionArrayType_1: Array with 23 element(s) of type uint8
 * SerialNumberArrayType: Array with 10 element(s) of type uint8
 * SgbdIndex_ArrayType: Array with 3 element(s) of type uint8
 * SvkDataArrayType: Array with 100 element(s) of type uint8
 * SvkHistoryDataArrayType: Array with 48 element(s) of type uint8
 * TimingParametersArrayType: Array with 12 element(s) of type uint8
 * UInt8_Array1: Array with 1 element(s) of type uint8
 * VinArrayType: Array with 7 element(s) of type uint8
 * VinArrayType: Array with 7 element(s) of type uint8
 *
 * Record Types:
 * =============
 * AnHwTqScaFacRec1: Record with elements
 *   SnsrSca of type float32
 *   SnsrScaPrfmdSts of type boolean
 * BlkFltTblRec1: Record with elements
 *   Sts of type NtcSts1
 *   Prm of type uint8
 * BmwDesIninIdxRec1: Record with elements
 *   BmwDesIninIdx of type uint8
 *   BmwDesIninIdxWrSts of type boolean
 * BmwDesIninOptSetAIdxRec1: Record with elements
 *   BmwDesIninOptSetAIdx of type uint8
 *   BmwDesIninOptSetAIdxWrSts of type boolean
 * BmwVehCentrOffsRec1: Record with elements
 *   BmwRackCentrToVehCentrOffs of type float32
 *   VehCentrOffs of type float32
 *   BmwPinionAgOffs of type float32
 *   BmwQuadRotorOffs of type sint8
 *   TurnCntrCorrlnSts of type uint8
 *   Ntc8CSts of type uint8
 *   Ntc8ESts of type uint8
 *   BmwMotAgSelnSt of type uint8
 *   LongTermVehCentrCmpl of type boolean
 *   RackCentrToVehCentrOffsVld of type boolean
 * CmdRtnBufRec1: Record with elements
 *   StdRtn of type uint8
 *   ReqPen of type uint8
 *   ReqRes of type uint8
 * CrcHwStsRec2: Record with elements
 *   TaskId of type uint32
 *   CrcHwSts of type CrcHwSts1
 * CurrMeasEolGainCal3PhaRec1: Record with elements
 *   CurrMeasMotCurrEolGainA of type float32
 *   CurrMeasMotCurrEolGainB of type float32
 *   CurrMeasMotCurrEolGainC of type float32
 * CurrMeasEolOffsCal3PhaRec1: Record with elements
 *   CurrMeasEolOffsHiBrdgVltg of type float32
 *   CurrMeasMotCurrEolOffsDifA of type float32
 *   CurrMeasMotCurrEolOffsDifB of type float32
 *   CurrMeasMotCurrEolOffsDifC of type float32
 *   CurrMeasMotCurrOffsLoAvrgA of type float32
 *   CurrMeasMotCurrOffsLoAvrgB of type float32
 *   CurrMeasMotCurrOffsLoAvrgC of type float32
 * Darh_TransmissionArrayType: Record with elements
 *   size of type uint16
 *   payload of type Rte_DT_Darh_TransmissionArrayType_1
 * DiagcDataRec2: Record with elements
 *   DiagcSts of type uint8
 *   ActvRampRate of type float32
 *   ActvMotTqCmdSca of type float32
 * DutyCycThermProtnFilStValRec1: Record with elements
 *   Fil3StVal of type uint8
 *   Fil4StVal of type uint8
 *   Fil5StVal of type uint8
 *   Fil6StVal of type uint8
 * FilLpRec1: Record with elements
 *   FilSt of type float32
 *   FilGain of type float32
 * FilNotchGainRec1: Record with elements
 *   FilGainB0 of type float32
 *   FilGainB1 of type float32
 *   FilGainB2 of type float32
 *   FilGainA1 of type float32
 *   FilGainA2 of type float32
 * FilNotchStRec1: Record with elements
 *   FilSt1 of type float32
 *   FilSt2 of type float32
 * HwTqOffsRec1: Record with elements
 *   OffsTrim of type float32
 *   OffsTrimPrfmdSts of type boolean
 * LrndRackCentrNvmRec1: Record with elements
 *   TotRackTrvl of type float32
 *   RackCentrMotDeg of type float32
 *   RackCentrMotRev of type sint16
 *   LongTermRackCentrCmpl of type boolean
 *   MotAgVld of type boolean
 * MotAgEolPrmRec1: Record with elements
 *   SinOffs of type u3p13
 *   CosOffs of type u3p13
 *   SinAmpRecpr of type u3p13
 *   CosAmpRecpr of type u3p13
 *   SinDelta of type s2p13
 *   SinHrmncTbl of type Ary1D_sm6p13_144
 *   CosHrmncTbl of type Ary1D_sm6p13_144
 *   SinGainCorrd of type u1p15
 *   CosGainCorrd of type u1p15
 *   SinOffsCorrd of type s2p13
 *   CosOffsCorrd of type s2p13
 *   CosDeltaRecpr of type u3p13
 * MotAgMeasEolPrmRec1: Record with elements
 *   SinOffs of type float32
 *   CosOffs of type float32
 *   SinAmpRecpr of type float32
 *   CosAmpRecpr of type float32
 *   SinDelta of type float32
 * MotPrmNomEolRec3: Record with elements
 *   MotBackEmfConNom of type float32
 *   MotRNom of type float32
 * NtcFltInfoRec2: Record with elements
 *   NtcNr of type NtcNrWithResd1
 *   AgiCntr of type uint8
 *   Sts of type uint8
 * NtcInfoRec4: Record with elements
 *   NtcStInfo of type uint8
 *   Sts of type uint8
 *   AgiCntr of type uint8
 * OnlineCalPageInfoRec1: Record with elements
 *   PageAcs of type uint8
 * OnlineCalSegInfoRec1: Record with elements
 *   Page of type Ary1D_OnlineCalPageInfoRec1_2
 * OnlineCalStsRec2: Record with elements
 *   Seg of type Ary1D_OnlineCalSegInfoRec1_TunSelnMngt1
 *   CopySts of type CalCopySts1
 *   ActvGroup of type uint8
 *   ActvInin of type uint8
 *   ActvIninOptSetA of type uint8
 *   ActvRt of type uint8
 * ReadFltInfoRec1: Record with elements
 *   NtcNr of type NtcNrWithResd1
 *   AgiCntr of type uint8
 *   Sts of type uint8
 *   NtcStInfo of type uint8
 * SnpshtDataRec1: Record with elements
 *   MicroDiagcData of type uint32
 *   HwTq of type s5p10
 *   MotTq of type s5p10
 *   IgnCntr of type uint32
 *   BrdgVltg of type u6p10
 *   EcuT of type s8p7
 *   NtcNr of type uint16
 *   NtcStInfo of type uint8
 *   SysSt of type SysSt1
 *   VehSpd of type u9p7
 * SnpshtDataRec2: Record with elements
 *   SpclSnpshtData0 of type uint32
 *   SpclSnpshtData1 of type uint32
 *   SpclSnpshtData2 of type uint32
 *   MicroDiagcData of type uint32
 *   IgnCntr of type uint32
 *   HwTq of type s5p10
 *   MotTq of type s5p10
 *   BrdgVltg of type u6p10
 *   EcuT of type s8p7
 *   NtcNr of type NtcNrWithResd1
 *   NtcStInfo of type uint8
 *   SysSt of type SysSt1
 * SysFricDataRec1: Record with elements
 *   FricOffs of type float32
 *   BasLineFric of type Ary1D_f32_4
 *   VehLrndFric of type Ary1D_f32_4
 *   Hys of type Ary2D_f32_8_4
 *   RngCntr of type Ary2D_u16_8_3
 *   SysFricLrngOperMod of type SysFricLrngOperMod1
 * SysFricNonLrngDataRec1: Record with elements
 *   EolFric of type float32
 *   EnaFricLrng of type boolean
 *   EnaFricOffsOutp of type boolean
 * TFilStValRec1: Record with elements
 *   FilSiLpStVal of type float32
 *   FilMagLpStVal of type float32
 *   FilCuLpStVal of type float32
 *   FilAssisMechLpStVal of type float32
 *   FilSiLLStVal of type float32
 *   FilMagLLStVal of type float32
 *   FilCuLLStVal of type float32
 *   FilAssisMechLLStVal of type float32
 * TorsBarStEstimdRec1: Record with elements
 *   MotVelEstimd of type float32
 *   TorsBarTqEstimd of type float32
 *   TorsBarRotatmEstimd of type float32
 *   DrvrTqEstimd of type float32
 *   RackTqEstimd of type float32
 * Vin_ComVinType: Record with elements
 *   Vin1 of type uint8
 *   Vin2 of type uint8
 *   Vin3 of type uint8
 *   Vin4 of type uint8
 *   Vin5 of type uint8
 *   Vin6 of type uint8
 *   Vin7 of type uint8
 * Vin_VinType: Record with elements
 *   Vin of type VinArrayType
 *   Qualifier of type Vin_QualifierType
 * Vin_VinType: Record with elements
 *   Vin of type VinArrayType
 *   Qualifier of type Vin_QualifierType
 * sigGroup_ACLNY_MASSCNTR1: Record with elements
 *   ACLNY_MASSCNTR_dummy_12_15 of type ACLNY_MASSCNTR_dummy_12_151
 *   ACLNY_COG of type ACLNY_COG1
 *   QU_ACLNY_COG of type QU_ACLNY_COG1
 *   ACLNY_COG_ERR_AMP of type ACLNY_COG_ERR_AMP1
 *   ALIV_ACLNY_COG of type ALIV_ACLNY_COG1
 *   CRC_ACLNY_COG of type CRC_ACLNY_COG1
 * sigGroup_AVL_FORC_GRD1: Record with elements
 *   AVL_FORC_GRD of type AVL_FORC_GRD1
 *   AVL_PWR_EL_EPS_COOD of type AVL_PWR_EL_EPS_COOD1
 *   ALIV_AVL_FORC_GRD of type ALIV_AVL_FORC_GRD1
 *   CRC_AVL_FORC_GRD of type CRC_AVL_FORC_GRD1
 *   QU_AVL_FORC_GRD of type QU_AVL_FORC_GRD1
 *   AVL_FORC_GRD_dummy_12_15 of type AVL_FORC_GRD_dummy_12_151
 * sigGroup_AVL_PO_EPS1: Record with elements
 *   AVL_PO_EPS of type AVL_PO_EPS1
 *   IDX_TORQ_SEN of type IDX_TORQ_SEN1
 *   OFFS_GRD_MID_EPS of type OFFS_GRD_MID_EPS1
 *   AVL_PO_IDX_EPS of type AVL_PO_IDX_EPS1
 *   CRC_AVL_PO_EPS of type CRC_AVL_PO_EPS1
 *   QU_AVL_PO_EPS of type QU_AVL_PO_EPS1
 *   ALIV_AVL_PO_EPS of type ALIV_AVL_PO_EPS1
 *   UN_PO_EPS of type UN_PO_EPS1
 * sigGroup_AVL_STMOM_DV_ACT1: Record with elements
 *   AVL_STMOM_DV_ACT of type AVL_STMOM_DV_ACT1
 *   ALIV_AVL_STMOM_DV_ACT of type ALIV_AVL_STMOM_DV_ACT1
 *   QU_AVL_STMOM_DV_ACT of type QU_AVL_STMOM_DV_ACT1
 *   CRC_AVL_STMOM_DV_ACT of type CRC_AVL_STMOM_DV_ACT1
 *   AVL_STMOM_DV_ACT_dummy_12_15 of type AVL_STMOM_DV_ACT_dummy_12_151
 * sigGroup_CON_VEH1: Record with elements
 *   CTR_FKTN_PRTNT of type CTR_FKTN_PRTNT1
 *   QU_ST_CON_VEH of type QU_ST_CON_VEH1
 *   CRC_CON_VEH of type CRC_CON_VEH1
 *   ST_CON_VEH of type ST_CON_VEH1
 *   CTR_BS_PRTNT of type CTR_BS_PRTNT1
 *   ALIV_CON_VEH of type ALIV_CON_VEH1
 *   CON_VEH_dummy_56_63 of type CON_VEH_dummy_56_631
 * sigGroup_DISP_CC_EPS1: Record with elements
 *   ST_CC_EPS of type ST_CC_EPS1
 *   ALIV_DISP_CC_EPS of type ALIV_DISP_CC_EPS1
 *   ST_IDC_CC_EPS of type ST_IDC_CC_EPS1
 *   CRC_DISP_CC_EPS of type CRC_DISP_CC_EPS1
 *   CHL_DISP_CC_EPS of type CHL_DISP_CC_EPS1
 *   NO_CC_EPS of type NO_CC_EPS1
 *   TRANF_CC_EPS of type TRANF_CC_EPS1
 * sigGroup_DT_EST1: Record with elements
 *   ST_CULI_EST of type ST_CULI_EST1
 *   DT_EST_dummy_64_95 of type DT_EST_dummy_64_951
 *   QU_AVL_I_ACT_EST of type QU_AVL_I_ACT_EST1
 *   DT_EST_dummy_12_15 of type DT_EST_dummy_12_151
 *   AVL_I_ACT_EST of type AVL_I_ACT_EST1
 *   ALIV_DT_EST of type ALIV_DT_EST1
 *   CRC_DT_EST of type CRC_DT_EST1
 *   DT_EST_dummy_96_127 of type DT_EST_dummy_96_1271
 *   DT_EST_dummy_16_47 of type DT_EST_dummy_16_471
 * sigGroup_ENERG_DGR_DRDY1: Record with elements
 *   MAX_I_LD_SPEC_ARS of type MAX_I_LD_SPEC_ARS1
 *   MAX_I_RECUP_SPEC_ARS of type MAX_I_RECUP_SPEC_ARS1
 *   RQ_CULI_EST_SFY of type RQ_CULI_EST_SFY1
 *   ALIV_ENERG_DGR_DRDY of type ALIV_ENERG_DGR_DRDY1
 *   ENERG_AVAI_ARS of type ENERG_AVAI_ARS1
 *   QU_DGR_AISP_ENERG of type QU_DGR_AISP_ENERG1
 *   CRC_ENERG_DGR_DRDY of type CRC_ENERG_DGR_DRDY1
 *   MAX_I_SPEC_BAX_STE of type MAX_I_SPEC_BAX_STE1
 *   ENERG_DGR_DRDY_dummy_12_15 of type ENERG_DGR_DRDY_dummy_12_151
 *   MAX_I_SPEC_EPS of type MAX_I_SPEC_EPS1
 * sigGroup_OFFS_QUAD_EPS1: Record with elements
 *   AVL_PO_IDX_ICM of type AVL_PO_IDX_ICM1
 *   ST_OFFS_QUAD_EPS of type ST_OFFS_QUAD_EPS1
 *   CRC_OFFS_QUAD_EPS of type CRC_OFFS_QUAD_EPS1
 *   OFFS_QUAD_RTR_EPS of type OFFS_QUAD_RTR_EPS1
 *   ALIV_OFFS_QUAD_EPS of type ALIV_OFFS_QUAD_EPS1
 * sigGroup_ST_EST1: Record with elements
 *   QU_SER_STMOM_DV_ACT of type QU_SER_STMOM_DV_ACT1
 *   QU_FN_VIB_EPS of type QU_FN_VIB_EPS1
 *   ST_EST_dummy_16_23 of type ST_EST_dummy_16_231
 *   ALIV_ST_EST_FTAX of type ALIV_ST_EST_FTAX1
 *   CRC_ST_EST_FTAX of type CRC_ST_EST_FTAX1
 *   QU_FN_EST of type QU_FN_EST1
 * sigGroup_SU_EPS1: Record with elements
 *   CRC_SU_EPS of type CRC_SU_EPS1
 *   UN_TOT_STR_EPS of type UN_TOT_STR_EPS1
 *   ALIV_SU_EPS of type ALIV_SU_EPS1
 *   TOT_STR_EPS of type TOT_STR_EPS1
 *   SU_EPS_dummy_20_51 of type SU_EPS_dummy_20_511
 *   SU_EPS_dummy_14_19 of type SU_EPS_dummy_14_191
 * sigGroup_TAR_QTA_STRMOM_DV1: Record with elements
 *   FACT_DMPNG_STMOM_FTAX of type FACT_DMPNG_STMOM_FTAX1
 *   QU_TAR_QTA_STMOM_DV of type QU_TAR_QTA_STMOM_DV1
 *   ALIV_TAR_QTA_STMOM_DV of type ALIV_TAR_QTA_STMOM_DV1
 *   QU_TAR_FACT_STMOM_FTAX of type QU_TAR_FACT_STMOM_FTAX1
 *   CTR_DEAC_EPS_FNS of type CTR_DEAC_EPS_FNS1
 *   FACT_CTRR_STMOM_FTAX of type FACT_CTRR_STMOM_FTAX1
 *   TAR_QTA_STRMOM_DV_dummy_12_15 of type TAR_QTA_STRMOM_DV_dummy_12_151
 *   FACT_ASS_STMOM_FTAX of type FACT_ASS_STMOM_FTAX1
 *   TAR_QTA_STMOM_DV of type TAR_QTA_STMOM_DV1
 *   CRC_TAR_QTA_STMOM_DV of type CRC_TAR_QTA_STMOM_DV1
 * sigGroup_TAR_STMOM_DV_ACT1: Record with elements
 *   TAR_STMOM_DV_ACT_dummy_12_15 of type TAR_STMOM_DV_ACT_dummy_12_151
 *   TAR_STMOM_DV_ACT_dummy_32_51 of type TAR_STMOM_DV_ACT_dummy_32_511
 *   QU_TAR_DMPNG_ADDON_STMOM_FTAX of type QU_TAR_DMPNG_ADDON_STMOM_FTAX1
 *   FACT_DMPNG_ADDON_STMOM_FTAX of type FACT_DMPNG_ADDON_STMOM_FTAX1
 *   TAR_STMOM_DV_ACT of type TAR_STMOM_DV_ACT1
 *   CRC_TAR_STMOM_DV_ACT of type CRC_TAR_STMOM_DV_ACT1
 *   QU_TAR_STMOM_DV_ACT of type QU_TAR_STMOM_DV_ACT1
 *   ALIV_TAR_STMOM_DV_ACT of type ALIV_TAR_STMOM_DV_ACT1
 * sigGroup_VYAW_VEH1: Record with elements
 *   QU_VYAW_VEH of type QU_VYAW_VEH1
 *   VYAW_VEH_ERR_AMP of type VYAW_VEH_ERR_AMP1
 *   VYAW_VEH of type VYAW_VEH1
 *   VYAW_VEH_dummy_12_15 of type VYAW_VEH_dummy_12_151
 *   CRC_VYAW_VEH of type CRC_VYAW_VEH1
 *   ALIV_VYAW_VEH of type ALIV_VYAW_VEH1
 * sigGroup_V_VEH1: Record with elements
 *   V_VEH_COG of type V_VEH_COG1
 *   ST_V_VEH_NSS of type ST_V_VEH_NSS1
 *   QU_V_VEH_COG of type QU_V_VEH_COG1
 *   ALIV_V_VEH of type ALIV_V_VEH1
 *   V_VEH_dummy_39_39 of type V_VEH_dummy_39_391
 *   DVCO_VEH of type DVCO_VEH1
 *   CRC_V_VEH of type CRC_V_VEH1
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_TestCode:
     Reason:     This justification is used within the generated test code by the Rte Analyzer.
     Risk:       No functional risk.
     Prevention: Not required.

*/
