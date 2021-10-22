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
 *          File:  Rte_Dcm.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <Dcm>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_DCM_H
# define _RTE_DCM_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
#  ifndef RTE_PTR2ARRAYBASETYPE_PASSING
#   define RTE_PTR2ARRAYBASETYPE_PASSING
#  endif
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_Dcm_Type.h"
# include "Rte_DataHandleType.h"


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Dcm_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6(Dcm_CommunicationModeType nextMode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Dcm_DcmControlDtcSetting_DcmControlDtcSetting(Dcm_ControlDtcSettingType nextMode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl(Dcm_DiagnosticSessionControlType nextMode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Dcm_DcmEcuReset_DcmEcuReset(Dcm_EcuResetType nextMode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Dcm_DcmResponseOnEvent_DcmDspRoeEvent_DcmResponseOnEvent_DcmDspRoeEvent(Dcm_ResponseOnEventType nextMode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_SwitchAck_Dcm_DcmEcuReset_DcmEcuReset(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DID_37FE_Cps_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DID_37FE_Cps_ReadData(P2VAR(uint8, AUTOMATIC, RTE_DCM_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DID_37FE_Cps_ReadData(P2VAR(Dcm_Data18ByteType, AUTOMATIC, RTE_DCM_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DID_37FF_ReadProtocolData_ReadData(P2VAR(uint8, AUTOMATIC, RTE_DCM_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DID_37FF_ReadProtocolData_ReadData(P2VAR(Dcm_Data9ByteType, AUTOMATIC, RTE_DCM_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_RoutineServices_CheckNcd_Routine_Start(P2CONST(uint8, AUTOMATIC, RTE_DCM_APPL_DATA) Cps_In, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DCM_APPL_VAR) StatCheckNcdResult_Out, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_RoutineServices_CheckNcd_Routine_Start(P2CONST(Dcm_Data18ByteType, AUTOMATIC, RTE_DCM_APPL_DATA) Cps_In, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DCM_APPL_VAR) StatCheckNcdResult_Out, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_RoutineServices_ReadNcd_Routine_Start(P2CONST(uint8, AUTOMATIC, RTE_DCM_APPL_DATA) ArgCodingArea_In, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DCM_APPL_VAR) StatCodingArea_Out, P2VAR(uint16, AUTOMATIC, RTE_DCM_APPL_VAR) DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_RoutineServices_ReadNcd_Routine_Start(P2CONST(Dcm_Data6ByteType, AUTOMATIC, RTE_DCM_APPL_DATA) ArgCodingArea_In, Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1024ByteType, AUTOMATIC, RTE_DCM_APPL_VAR) StatCodingArea_Out, P2VAR(uint16, AUTOMATIC, RTE_DCM_APPL_VAR) DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_RoutineServices_WriteNcd_Routine_Start(P2CONST(uint8, AUTOMATIC, RTE_DCM_APPL_DATA) ArgCodingArea_In, Dcm_OpStatusType OpStatus, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_RoutineServices_WriteNcd_Routine_Start(P2CONST(Dcm_Data1024ByteType, AUTOMATIC, RTE_DCM_APPL_DATA) ArgCodingArea_In, Dcm_OpStatusType OpStatus, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DID_1704_DmDtcAktiveMeldung_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DID_1704_DmDtcAktiveMeldung_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DCM_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DID_1704_DmDtcAktiveMeldung_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data4ByteType, AUTOMATIC, RTE_DCM_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DID_2507_SwfkDeleteSupported_ConditionCheckRead(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DID_2507_SwfkDeleteSupported_ReadData(P2VAR(uint8, AUTOMATIC, RTE_DCM_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DID_2507_SwfkDeleteSupported_ReadData(P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DCM_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DID_2541_StatusCalcvn_ReadData(P2VAR(uint8, AUTOMATIC, RTE_DCM_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DID_2541_StatusCalcvn_ReadData(P2VAR(Dcm_Data20ByteType, AUTOMATIC, RTE_DCM_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DID_F15A_WdbiFp_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DCM_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DID_F15A_WdbiFp_WriteData(P2CONST(Dcm_Data1ByteType, AUTOMATIC, RTE_DCM_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DcmDspData_SvkBackup0_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DcmDspData_SvkBackup0_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DCM_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DcmDspData_SvkBackup0_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data57ByteType, AUTOMATIC, RTE_DCM_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DcmDspData_SvkBackup1_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DcmDspData_SvkBackup1_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DCM_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DcmDspData_SvkBackup1_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data57ByteType, AUTOMATIC, RTE_DCM_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DcmDspData_SvkBackup2_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DcmDspData_SvkBackup2_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DCM_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DcmDspData_SvkBackup2_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data57ByteType, AUTOMATIC, RTE_DCM_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_RoutineServices_DeleteSwPackage_Routine_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_RoutineServices_RcCm_Routine_Start(uint8 RcCmIcvRcoStruct_In, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DCM_APPL_VAR) StatRoutineStatus_Out, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_RoutineServices_RcCpd_Routine_Start(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DCM_APPL_VAR) StatRoutineStatus_Out, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_RoutineServices_RcEm_Routine_Start(uint8 RcEmIeRco_In, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DCM_APPL_VAR) StatRoutineStatus_Out, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_RoutineServices_SteuernEpsPulldriftOffsetReset_Routine_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_Coding_CompareKey(P2CONST(uint8, AUTOMATIC, RTE_DCM_APPL_DATA) Key, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_Coding_CompareKey(P2CONST(Dcm_Data132ByteType, AUTOMATIC, RTE_DCM_APPL_DATA) Key, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_Coding_GetSeed(P2CONST(uint8, AUTOMATIC, RTE_DCM_APPL_DATA) SecurityAccessDataRecord, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DCM_APPL_VAR) Seed, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_Coding_GetSeed(P2CONST(Dcm_Data4ByteType, AUTOMATIC, RTE_DCM_APPL_DATA) SecurityAccessDataRecord, Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data8ByteType, AUTOMATIC, RTE_DCM_APPL_VAR) Seed, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# endif

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Switch_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Switch_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6 Rte_Switch_Dcm_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6
#  define Rte_Switch_DcmControlDtcSetting_DcmControlDtcSetting Rte_Switch_Dcm_DcmControlDtcSetting_DcmControlDtcSetting
#  define Rte_Switch_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl Rte_Switch_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl
#  define Rte_Switch_DcmEcuReset_DcmEcuReset Rte_Switch_Dcm_DcmEcuReset_DcmEcuReset
#  define Rte_Switch_DcmResponseOnEvent_DcmDspRoeEvent_DcmResponseOnEvent_DcmDspRoeEvent Rte_Switch_Dcm_DcmResponseOnEvent_DcmDspRoeEvent_DcmResponseOnEvent_DcmDspRoeEvent


/**********************************************************************************************************************
 * Rte_Feedback_<p>_<m> (mode switch acknowledge)
 *********************************************************************************************************************/
#  define Rte_SwitchAck_DcmEcuReset_DcmEcuReset Rte_SwitchAck_Dcm_DcmEcuReset_DcmEcuReset


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (mapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define Rte_Call_DataServices_DID_37FE_Cps_ConditionCheckRead Rte_Call_Dcm_DataServices_DID_37FE_Cps_ConditionCheckRead
#  define Rte_Call_DataServices_DID_37FE_Cps_ReadData Rte_Call_Dcm_DataServices_DID_37FE_Cps_ReadData
#  define Rte_Call_DataServices_DID_37FF_ReadProtocolData_ReadData Rte_Call_Dcm_DataServices_DID_37FF_ReadProtocolData_ReadData
#  define Rte_Call_RoutineServices_CheckNcd_Routine_Start Rte_Call_Dcm_RoutineServices_CheckNcd_Routine_Start
#  define Rte_Call_RoutineServices_ReadNcd_Routine_Start Rte_Call_Dcm_RoutineServices_ReadNcd_Routine_Start
#  define Rte_Call_RoutineServices_WriteNcd_Routine_Start Rte_Call_Dcm_RoutineServices_WriteNcd_Routine_Start


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_BMWDIAGCSRVHNDLG_APPL_CODE) BmwDiagcSrvFHndlgEpsTestStampReadCdnChk_Oper(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  define RTE_STOP_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_DataServices_DID_1000_Pruefstempel_ConditionCheckRead BmwDiagcSrvFHndlgEpsTestStampReadCdnChk_Oper
#  define RTE_START_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_BMWDIAGCSRVHNDLG_APPL_CODE) BmwDiagcSrvFHndlgEpsTestStampRead_Oper(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  else
FUNC(Std_ReturnType, RTE_BMWDIAGCSRVHNDLG_APPL_CODE) BmwDiagcSrvFHndlgEpsTestStampRead_Oper(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data3ByteType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  endif
#  define RTE_STOP_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_DataServices_DID_1000_Pruefstempel_ReadData BmwDiagcSrvFHndlgEpsTestStampRead_Oper
#  define RTE_START_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_BMWDIAGCSRVHNDLG_APPL_CODE) BmwDiagcSrvFHndlgEpsTestStampWrite_Oper(P2CONST(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  else
FUNC(Std_ReturnType, RTE_BMWDIAGCSRVHNDLG_APPL_CODE) BmwDiagcSrvFHndlgEpsTestStampWrite_Oper(P2CONST(Dcm_Data3ByteType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  endif
#  define RTE_STOP_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_DataServices_DID_1000_Pruefstempel_WriteData BmwDiagcSrvFHndlgEpsTestStampWrite_Oper
#  define RTE_START_SEC_OMC_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_OMC_APPL_CODE) Omc_ReadDIDOperatingMode(P2VAR(uint8, AUTOMATIC, RTE_OMC_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  else
FUNC(Std_ReturnType, RTE_OMC_APPL_CODE) Omc_ReadDIDOperatingMode(P2VAR(UInt8_Array1, AUTOMATIC, RTE_OMC_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  endif
#  define RTE_STOP_SEC_OMC_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_DataServices_DID_100A_EnergySavingState_ReadData Omc_ReadDIDOperatingMode
#  define RTE_START_SEC_OMC_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_OMC_APPL_CODE) Omc_ReadDIDExtendedOperatingMode(P2VAR(uint8, AUTOMATIC, RTE_OMC_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  else
FUNC(Std_ReturnType, RTE_OMC_APPL_CODE) Omc_ReadDIDExtendedOperatingMode(P2VAR(UInt8_Array1, AUTOMATIC, RTE_OMC_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  endif
#  define RTE_STOP_SEC_OMC_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_DataServices_DID_100E_ExtendedEnergySavingState_ReadData Omc_ReadDIDExtendedOperatingMode
#  define RTE_START_SEC_SYSTIME_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_SYSTIME_APPL_CODE) SysTime_GetSystemTime(P2VAR(uint8, AUTOMATIC, RTE_SYSTIME_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  else
FUNC(Std_ReturnType, RTE_SYSTIME_APPL_CODE) SysTime_GetSystemTime(P2VAR(Array4, AUTOMATIC, RTE_SYSTIME_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  endif
#  define RTE_STOP_SEC_SYSTIME_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_DataServices_DID_1701_Systemzeit_ReadData SysTime_GetSystemTime
#  define Rte_Call_DataServices_DID_1704_DmDtcAktiveMeldung_ConditionCheckRead Rte_Call_Dcm_DataServices_DID_1704_DmDtcAktiveMeldung_ConditionCheckRead
#  define Rte_Call_DataServices_DID_1704_DmDtcAktiveMeldung_ReadData Rte_Call_Dcm_DataServices_DID_1704_DmDtcAktiveMeldung_ReadData
#  define RTE_START_SEC_DARH_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_DARH_APPL_CODE) Darh_ReadActivelyReportedDtcDataHandler(P2VAR(uint8, AUTOMATIC, RTE_DARH_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  else
FUNC(Std_ReturnType, RTE_DARH_APPL_CODE) Darh_ReadActivelyReportedDtcDataHandler(P2VAR(Darh_ActivelyReportedErrorListType, AUTOMATIC, RTE_DARH_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  endif
#  define RTE_STOP_SEC_DARH_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_DataServices_DID_1723_DmIsDtcActiveResponse_ReadData Darh_ReadActivelyReportedDtcDataHandler
#  define RTE_START_SEC_DARH_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_DARH_APPL_CODE) Darh_ReadActivelyReportedDtcLengthHandler(P2VAR(uint16, AUTOMATIC, RTE_DARH_APPL_VAR) DataLength); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  define RTE_STOP_SEC_DARH_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_DataServices_DID_1723_DmIsDtcActiveResponse_ReadDataLength Darh_ReadActivelyReportedDtcLengthHandler
#  define RTE_START_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_BMWDIAGCSRVHNDLG_APPL_CODE) BmwDiagcSrvFHndlgProgmCntrRead_Oper(P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  else
FUNC(Std_ReturnType, RTE_BMWDIAGCSRVHNDLG_APPL_CODE) BmwDiagcSrvFHndlgProgmCntrRead_Oper(P2VAR(ProgCounterArrayType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  endif
#  define RTE_STOP_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_DataServices_DID_2502_ProgrammingCounter_ReadData BmwDiagcSrvFHndlgProgmCntrRead_Oper
#  define RTE_START_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_BMWDIAGCSRVHNDLG_APPL_CODE) BmwDiagcSrvFHndlgProgmCntrMaxValReadCdnChk_Oper(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  define RTE_STOP_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_DataServices_DID_2503_ProgrammingCounterMaxValue_ConditionCheckRead BmwDiagcSrvFHndlgProgmCntrMaxValReadCdnChk_Oper
#  define RTE_START_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_BMWDIAGCSRVHNDLG_APPL_CODE) BmwDiagcSrvFHndlgProgmCntrMaxValRead_Oper(P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  else
FUNC(Std_ReturnType, RTE_BMWDIAGCSRVHNDLG_APPL_CODE) BmwDiagcSrvFHndlgProgmCntrMaxValRead_Oper(P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  endif
#  define RTE_STOP_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_DataServices_DID_2503_ProgrammingCounterMaxValue_ReadData BmwDiagcSrvFHndlgProgmCntrMaxValRead_Oper
#  define RTE_START_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_BMWDIAGCSRVHNDLG_APPL_CODE) BmwDiagcSrvFHndlgEpsProgCntrMaxValWrite_Oper(P2CONST(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  else
FUNC(Std_ReturnType, RTE_BMWDIAGCSRVHNDLG_APPL_CODE) BmwDiagcSrvFHndlgEpsProgCntrMaxValWrite_Oper(P2CONST(Dcm_Data2ByteType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  endif
#  define RTE_STOP_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_DataServices_DID_2503_ProgrammingCounterMaxValue_WriteData BmwDiagcSrvFHndlgEpsProgCntrMaxValWrite_Oper
#  define RTE_START_SEC_DLOG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_DLOG_APPL_CODE) Dlog_ReadDataByIdentifierFlashTimingParameter(P2VAR(uint8, AUTOMATIC, RTE_DLOG_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  else
FUNC(Std_ReturnType, RTE_DLOG_APPL_CODE) Dlog_ReadDataByIdentifierFlashTimingParameter(P2VAR(TimingParametersArrayType, AUTOMATIC, RTE_DLOG_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  endif
#  define RTE_STOP_SEC_DLOG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_DataServices_DID_2504_FlashTimingParameter_ReadData Dlog_ReadDataByIdentifierFlashTimingParameter
#  define Rte_Call_DataServices_DID_2507_SwfkDeleteSupported_ConditionCheckRead Rte_Call_Dcm_DataServices_DID_2507_SwfkDeleteSupported_ConditionCheckRead
#  define Rte_Call_DataServices_DID_2507_SwfkDeleteSupported_ReadData Rte_Call_Dcm_DataServices_DID_2507_SwfkDeleteSupported_ReadData
#  define RTE_START_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_BMWDIAGCSRVHNDLG_APPL_CODE) BmwDiagcSrvFHndlgReadSwRevisionCdnChk_Oper(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  define RTE_STOP_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_DataServices_DID_250B_ReadSwRevision_ConditionCheckRead BmwDiagcSrvFHndlgReadSwRevisionCdnChk_Oper
#  define RTE_START_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_BMWDIAGCSRVHNDLG_APPL_CODE) BmwDiagcSrvFHndlgReadSwRevision_Oper(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  else
FUNC(Std_ReturnType, RTE_BMWDIAGCSRVHNDLG_APPL_CODE) BmwDiagcSrvFHndlgReadSwRevision_Oper(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data140ByteType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  endif
#  define RTE_STOP_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_DataServices_DID_250B_ReadSwRevision_ReadData BmwDiagcSrvFHndlgReadSwRevision_Oper
#  define RTE_START_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_BMWDIAGCSRVHNDLG_APPL_CODE) BmwDiagcSrvFHndlgMileKmEepromReadCdnChk_Oper(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  define RTE_STOP_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_DataServices_DID_2540_MileKmEeprom_ConditionCheckRead BmwDiagcSrvFHndlgMileKmEepromReadCdnChk_Oper
#  define RTE_START_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_BMWDIAGCSRVHNDLG_APPL_CODE) BmwDiagcSrvFHndlgMileKmEepromRead_Oper(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  else
FUNC(Std_ReturnType, RTE_BMWDIAGCSRVHNDLG_APPL_CODE) BmwDiagcSrvFHndlgMileKmEepromRead_Oper(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data3ByteType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  endif
#  define RTE_STOP_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_DataServices_DID_2540_MileKmEeprom_ReadData BmwDiagcSrvFHndlgMileKmEepromRead_Oper
#  define Rte_Call_DataServices_DID_2541_StatusCalcvn_ReadData Rte_Call_Dcm_DataServices_DID_2541_StatusCalcvn_ReadData
#  define RTE_START_SEC_CODING_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CODING_APPL_CODE) Coding_ConditionCheckReadProtocolData(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CODING_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  define RTE_STOP_SEC_CODING_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_DataServices_DID_37FF_ReadProtocolData_ConditionCheckRead Coding_ConditionCheckReadProtocolData
#  define RTE_START_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_BMWDIAGCSRVHNDLG_APPL_CODE) BmwDiagcSrvHndlgStatusFzgBordnetzReadCdnChk_Oper(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  define RTE_STOP_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_DataServices_DID_DB3C_StatusFzgBordnetz_ConditionCheckRead BmwDiagcSrvHndlgStatusFzgBordnetzReadCdnChk_Oper
#  define RTE_START_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_BMWDIAGCSRVHNDLG_APPL_CODE) BmwDiagcSrvHndlgStatusFzgBordnetzRead_Oper(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  else
FUNC(Std_ReturnType, RTE_BMWDIAGCSRVHNDLG_APPL_CODE) BmwDiagcSrvHndlgStatusFzgBordnetzRead_Oper(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data15ByteType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  endif
#  define RTE_STOP_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_DataServices_DID_DB3C_StatusFzgBordnetz_ReadData BmwDiagcSrvHndlgStatusFzgBordnetzRead_Oper
#  define RTE_START_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_BMWDIAGCSRVHNDLG_APPL_CODE) BmwDiagcSrvFHndlgEpsPinionAgSnsrReadCdnChk_Oper(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  define RTE_STOP_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_DataServices_DID_DB57_EpsRitzelwinkelsensor_ConditionCheckRead BmwDiagcSrvFHndlgEpsPinionAgSnsrReadCdnChk_Oper
#  define RTE_START_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_BMWDIAGCSRVHNDLG_APPL_CODE) BmwDiagcSrvFHndlgEpsPinionAgSnsrRead_Oper(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  else
FUNC(Std_ReturnType, RTE_BMWDIAGCSRVHNDLG_APPL_CODE) BmwDiagcSrvFHndlgEpsPinionAgSnsrRead_Oper(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data7ByteType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  endif
#  define RTE_STOP_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_DataServices_DID_DB57_EpsRitzelwinkelsensor_ReadData BmwDiagcSrvFHndlgEpsPinionAgSnsrRead_Oper
#  define RTE_START_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_BMWDIAGCSRVHNDLG_APPL_CODE) BmwDiagcSrvFHndlgEpsSteerAgSnsrCalReadCdnChk_Oper(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  define RTE_STOP_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_DataServices_DID_DB5A_EpsLenkwinkelsensorKalibrierung_ConditionCheckRead BmwDiagcSrvFHndlgEpsSteerAgSnsrCalReadCdnChk_Oper
#  define RTE_START_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_BMWDIAGCSRVHNDLG_APPL_CODE) BmwDiagcSrvFHndlgEpsSteerAgSnsrCalRead_Oper(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  else
FUNC(Std_ReturnType, RTE_BMWDIAGCSRVHNDLG_APPL_CODE) BmwDiagcSrvFHndlgEpsSteerAgSnsrCalRead_Oper(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  endif
#  define RTE_STOP_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_DataServices_DID_DB5A_EpsLenkwinkelsensorKalibrierung_ReadData BmwDiagcSrvFHndlgEpsSteerAgSnsrCalRead_Oper
#  define RTE_START_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_BMWDIAGCSRVHNDLG_APPL_CODE) BmwDiagcSrvFHndlgEpsSteerAgSnsrCalWrite_Oper(P2CONST(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  else
FUNC(Std_ReturnType, RTE_BMWDIAGCSRVHNDLG_APPL_CODE) BmwDiagcSrvFHndlgEpsSteerAgSnsrCalWrite_Oper(P2CONST(Dcm_Data2ByteType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  endif
#  define RTE_STOP_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_DataServices_DID_DB5A_EpsLenkwinkelsensorKalibrierung_WriteData BmwDiagcSrvFHndlgEpsSteerAgSnsrCalWrite_Oper
#  define RTE_START_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_BMWDIAGCSRVHNDLG_APPL_CODE) BmwDiagcSrvHndlgEpsTqSensrReadCdnChk_Oper(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  define RTE_STOP_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_DataServices_DID_DB99_EpsMomentensensor_ConditionCheckRead BmwDiagcSrvHndlgEpsTqSensrReadCdnChk_Oper
#  define RTE_START_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_BMWDIAGCSRVHNDLG_APPL_CODE) BmwDiagcSrvHndlgEpsTqSensrRead_Oper(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  else
FUNC(Std_ReturnType, RTE_BMWDIAGCSRVHNDLG_APPL_CODE) BmwDiagcSrvHndlgEpsTqSensrRead_Oper(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data3ByteType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  endif
#  define RTE_STOP_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_DataServices_DID_DB99_EpsMomentensensor_ReadData BmwDiagcSrvHndlgEpsTqSensrRead_Oper
#  define RTE_START_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_BMWDIAGCSRVHNDLG_APPL_CODE) BmwDiagcSrvHndlgEpsRackCentrMotAgStsReadCdnChk_Oper(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  define RTE_STOP_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_DataServices_DID_DC77_EpsZahnstangenmitte_ConditionCheckRead BmwDiagcSrvHndlgEpsRackCentrMotAgStsReadCdnChk_Oper
#  define RTE_START_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_BMWDIAGCSRVHNDLG_APPL_CODE) BmwDiagcSrvHndlgEpsRackCentrMotAgStsRead_Oper(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  else
FUNC(Std_ReturnType, RTE_BMWDIAGCSRVHNDLG_APPL_CODE) BmwDiagcSrvHndlgEpsRackCentrMotAgStsRead_Oper(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  endif
#  define RTE_STOP_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_DataServices_DID_DC77_EpsZahnstangenmitte_ReadData BmwDiagcSrvHndlgEpsRackCentrMotAgStsRead_Oper
#  define RTE_START_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_BMWDIAGCSRVHNDLG_APPL_CODE) BmwDiagcSrvFHndlgStordRackTrvlAndCentrDataReadCdnChk_Oper(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  define RTE_STOP_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_DataServices_DID_DFDD_GelernterZahnstangenweg_ConditionCheckRead BmwDiagcSrvFHndlgStordRackTrvlAndCentrDataReadCdnChk_Oper
#  define RTE_START_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_BMWDIAGCSRVHNDLG_APPL_CODE) BmwDiagcSrvFHndlgStordRackTrvlAndCentrDataRead_Oper(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  else
FUNC(Std_ReturnType, RTE_BMWDIAGCSRVHNDLG_APPL_CODE) BmwDiagcSrvFHndlgStordRackTrvlAndCentrDataRead_Oper(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data8ByteType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  endif
#  define RTE_STOP_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_DataServices_DID_DFDD_GelernterZahnstangenweg_ReadData BmwDiagcSrvFHndlgStordRackTrvlAndCentrDataRead_Oper
#  define RTE_START_SEC_STDDIAG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_STDDIAG_APPL_CODE) StdDiag_ConditionCheckActiveSessionState(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_STDDIAG_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  define RTE_STOP_SEC_STDDIAG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_DataServices_DID_F100_ReadActiveSessionState_ConditionCheckRead StdDiag_ConditionCheckActiveSessionState
#  define RTE_START_SEC_STDDIAG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_STDDIAG_APPL_CODE) StdDiag_ReadActiveSessionState(P2VAR(uint8, AUTOMATIC, RTE_STDDIAG_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  else
FUNC(Std_ReturnType, RTE_STDDIAG_APPL_CODE) StdDiag_ReadActiveSessionState(P2VAR(ActiveSessionState_ArrayType, AUTOMATIC, RTE_STDDIAG_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  endif
#  define RTE_STOP_SEC_STDDIAG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_DataServices_DID_F100_ReadActiveSessionState_ReadData StdDiag_ReadActiveSessionState
#  define RTE_START_SEC_DLOG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_DLOG_APPL_CODE) Dlog_ConditionCheckSvkCurrent(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DLOG_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  define RTE_STOP_SEC_DLOG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_DataServices_DID_F101_SvkAktuell_ConditionCheckRead Dlog_ConditionCheckSvkCurrent
#  define RTE_START_SEC_DLOG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_DLOG_APPL_CODE) Dlog_ReadDataByIdentifierSvkCurrent(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DLOG_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  else
FUNC(Std_ReturnType, RTE_DLOG_APPL_CODE) Dlog_ReadDataByIdentifierSvkCurrent(Dcm_OpStatusType OpStatus, P2VAR(SvkDataArrayType, AUTOMATIC, RTE_DLOG_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  endif
#  define RTE_STOP_SEC_DLOG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_DataServices_DID_F101_SvkAktuell_ReadData Dlog_ReadDataByIdentifierSvkCurrent
#  define RTE_START_SEC_DLOG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_DLOG_APPL_CODE) Dlog_ConditionCheckSvkSysSupplier(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DLOG_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  define RTE_STOP_SEC_DLOG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_DataServices_DID_F102_SvkSysSupplier_ConditionCheckRead Dlog_ConditionCheckSvkSysSupplier
#  define RTE_START_SEC_DLOG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_DLOG_APPL_CODE) Dlog_ReadDataByIdentifierSvkSysSupplier(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DLOG_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  else
FUNC(Std_ReturnType, RTE_DLOG_APPL_CODE) Dlog_ReadDataByIdentifierSvkSysSupplier(Dcm_OpStatusType OpStatus, P2VAR(SvkHistoryDataArrayType, AUTOMATIC, RTE_DLOG_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  endif
#  define RTE_STOP_SEC_DLOG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_DataServices_DID_F102_SvkSysSupplier_ReadData Dlog_ReadDataByIdentifierSvkSysSupplier
#  define RTE_START_SEC_DLOG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_DLOG_APPL_CODE) Dlog_ConditionCheckSvkPlant(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DLOG_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  define RTE_STOP_SEC_DLOG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_DataServices_DID_F103_SvkWerk_ConditionCheckRead Dlog_ConditionCheckSvkPlant
#  define RTE_START_SEC_DLOG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_DLOG_APPL_CODE) Dlog_ReadDataByIdentifierSvkPlant(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DLOG_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  else
FUNC(Std_ReturnType, RTE_DLOG_APPL_CODE) Dlog_ReadDataByIdentifierSvkPlant(Dcm_OpStatusType OpStatus, P2VAR(SvkHistoryDataArrayType, AUTOMATIC, RTE_DLOG_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  endif
#  define RTE_STOP_SEC_DLOG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_DataServices_DID_F103_SvkWerk_ReadData Dlog_ReadDataByIdentifierSvkPlant
#  define RTE_START_SEC_STDDIAG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_STDDIAG_APPL_CODE) StdDiag_ReadSgbdIndex(P2VAR(uint8, AUTOMATIC, RTE_STDDIAG_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  else
FUNC(Std_ReturnType, RTE_STDDIAG_APPL_CODE) StdDiag_ReadSgbdIndex(P2VAR(SgbdIndex_ArrayType, AUTOMATIC, RTE_STDDIAG_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  endif
#  define RTE_STOP_SEC_STDDIAG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_DataServices_DID_F150_SgbdIdx_ReadData StdDiag_ReadSgbdIndex
#  define RTE_START_SEC_DLOG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_DLOG_APPL_CODE) Dlog_ReadDataByIdentifierHWModificationIndex(P2VAR(uint8, AUTOMATIC, RTE_DLOG_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  else
FUNC(Std_ReturnType, RTE_DLOG_APPL_CODE) Dlog_ReadDataByIdentifierHWModificationIndex(P2VAR(Dlog_HWModificationIndexArrayType, AUTOMATIC, RTE_DLOG_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  endif
#  define RTE_STOP_SEC_DLOG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_DataServices_DID_F152_Readhwmodificationindex_ReadData Dlog_ReadDataByIdentifierHWModificationIndex
#  define Rte_Call_DataServices_DID_F15A_WdbiFp_WriteData Rte_Call_Dcm_DataServices_DID_F15A_WdbiFp_WriteData
#  define RTE_START_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_BMWDIAGCSRVHNDLG_APPL_CODE) BmwDiagcSrvFHndlgSysSupplierIdentifierCdnChk_Oper(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  define RTE_STOP_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_DataServices_DID_F18A_SystemSupplierIdentifier_ConditionCheckRead BmwDiagcSrvFHndlgSysSupplierIdentifierCdnChk_Oper
#  define RTE_START_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_BMWDIAGCSRVHNDLG_APPL_CODE) BmwDiagcSrvFHndlgSysSupplierIdentifierRead_Oper(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  else
FUNC(Std_ReturnType, RTE_BMWDIAGCSRVHNDLG_APPL_CODE) BmwDiagcSrvFHndlgSysSupplierIdentifierRead_Oper(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data3ByteType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  endif
#  define RTE_STOP_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_DataServices_DID_F18A_SystemSupplierIdentifier_ReadData BmwDiagcSrvFHndlgSysSupplierIdentifierRead_Oper
#  define RTE_START_SEC_DLOG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_DLOG_APPL_CODE) Dlog_ReadDataByIdentifierManufacturingDate(P2VAR(uint8, AUTOMATIC, RTE_DLOG_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  else
FUNC(Std_ReturnType, RTE_DLOG_APPL_CODE) Dlog_ReadDataByIdentifierManufacturingDate(P2VAR(ManufacturingDataArrayType, AUTOMATIC, RTE_DLOG_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  endif
#  define RTE_STOP_SEC_DLOG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_DataServices_DID_F18B_Herstelldatum_ReadData Dlog_ReadDataByIdentifierManufacturingDate
#  define RTE_START_SEC_DLOG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_DLOG_APPL_CODE) Dlog_ReadDataByIdentifierEcuSerialNumber(P2VAR(uint8, AUTOMATIC, RTE_DLOG_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  else
FUNC(Std_ReturnType, RTE_DLOG_APPL_CODE) Dlog_ReadDataByIdentifierEcuSerialNumber(P2VAR(SerialNumberArrayType, AUTOMATIC, RTE_DLOG_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  endif
#  define RTE_STOP_SEC_DLOG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_DataServices_DID_F18C_EcuSerialNumber_ReadData Dlog_ReadDataByIdentifierEcuSerialNumber
#  define Rte_Call_DataServices_DcmDspData_SvkBackup0_ConditionCheckRead Rte_Call_Dcm_DataServices_DcmDspData_SvkBackup0_ConditionCheckRead
#  define Rte_Call_DataServices_DcmDspData_SvkBackup0_ReadData Rte_Call_Dcm_DataServices_DcmDspData_SvkBackup0_ReadData
#  define Rte_Call_DataServices_DcmDspData_SvkBackup1_ConditionCheckRead Rte_Call_Dcm_DataServices_DcmDspData_SvkBackup1_ConditionCheckRead
#  define Rte_Call_DataServices_DcmDspData_SvkBackup1_ReadData Rte_Call_Dcm_DataServices_DcmDspData_SvkBackup1_ReadData
#  define Rte_Call_DataServices_DcmDspData_SvkBackup2_ConditionCheckRead Rte_Call_Dcm_DataServices_DcmDspData_SvkBackup2_ConditionCheckRead
#  define Rte_Call_DataServices_DcmDspData_SvkBackup2_ReadData Rte_Call_Dcm_DataServices_DcmDspData_SvkBackup2_ReadData
#  define RTE_START_SEC_DLOG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_DLOG_APPL_CODE) Dlog_ReadDataByIdentifierVin(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DLOG_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  else
FUNC(Std_ReturnType, RTE_DLOG_APPL_CODE) Dlog_ReadDataByIdentifierVin(Dcm_OpStatusType OpStatus, P2VAR(Dlog_VinArrayType, AUTOMATIC, RTE_DLOG_APPL_VAR) Data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  endif
#  define RTE_STOP_SEC_DLOG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_DataServices_DcmDspData_Vin_ReadData Dlog_ReadDataByIdentifierVin
#  define RTE_START_SEC_OMC_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_OMC_APPL_CODE) Omc_RoutineControlStartExtendedOperatingMode(uint8 ExtendedOperatingMode, OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_OMC_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  define RTE_STOP_SEC_OMC_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_RoutineServices_ControlExtendedEnergySavingState_Routine_Start Omc_RoutineControlStartExtendedOperatingMode
#  define RTE_START_SEC_DARH_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_DARH_APPL_CODE) Darh_StartRoutineDiagnoseMasterHandler(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DARH_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  define RTE_STOP_SEC_DARH_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_RoutineServices_DarhStrtStop_Routine_Start Darh_StartRoutineDiagnoseMasterHandler
#  define RTE_START_SEC_DARH_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_DARH_APPL_CODE) Darh_StopRoutineDiagnoseMasterHandler(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DARH_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  define RTE_STOP_SEC_DARH_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_RoutineServices_DarhStrtStop_Routine_Stop Darh_StopRoutineDiagnoseMasterHandler
#  define Rte_Call_RoutineServices_DeleteSwPackage_Routine_Start Rte_Call_Dcm_RoutineServices_DeleteSwPackage_Routine_Start
#  define RTE_START_SEC_STDDIAG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_STDDIAG_APPL_CODE) StdDiag_RoutineControlStartDiagCommLoopback(P2CONST(uint8, AUTOMATIC, RTE_STDDIAG_APPL_DATA) dataIn, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_STDDIAG_APPL_VAR) dataOut, P2VAR(uint16, AUTOMATIC, RTE_STDDIAG_APPL_VAR) currentDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_STDDIAG_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  else
FUNC(Std_ReturnType, RTE_STDDIAG_APPL_CODE) StdDiag_RoutineControlStartDiagCommLoopback(P2CONST(DiagCommLoopback_ArrayType, AUTOMATIC, RTE_STDDIAG_APPL_DATA) dataIn, Dcm_OpStatusType OpStatus, P2VAR(DiagCommLoopback_ArrayType, AUTOMATIC, RTE_STDDIAG_APPL_VAR) dataOut, P2VAR(uint16, AUTOMATIC, RTE_STDDIAG_APPL_VAR) currentDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_STDDIAG_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  endif
#  define RTE_STOP_SEC_STDDIAG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_RoutineServices_DiagCommLoopback_Routine_Start StdDiag_RoutineControlStartDiagCommLoopback
#  define RTE_START_SEC_DARH_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_DARH_APPL_CODE) Darh_StartRoutineTriggerDtcHandler(uint8 DTCType, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DARH_APPL_VAR) DTCTypeOut, P2VAR(uint8, AUTOMATIC, RTE_DARH_APPL_VAR) DTCByte1, P2VAR(uint8, AUTOMATIC, RTE_DARH_APPL_VAR) DTCByte2, P2VAR(uint8, AUTOMATIC, RTE_DARH_APPL_VAR) DTCByte3, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DARH_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  define RTE_STOP_SEC_DARH_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_RoutineServices_DmClientTriggerDtcEntry_Routine_Start Darh_StartRoutineTriggerDtcHandler
#  define RTE_START_SEC_OMC_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_OMC_APPL_CODE) Omc_RoutineControlStartOperatingMode(uint8 OperatingMode, OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_OMC_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  define RTE_STOP_SEC_OMC_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_RoutineServices_Energiesparmode_Routine_Start Omc_RoutineControlStartOperatingMode
#  define RTE_START_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_BMWDIAGCSRVHNDLG_APPL_CODE) BmwDiagcSrvHndlgEpsIninSrvRes_Oper(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) StatRoutineStatus_Out, P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) StatLenkradwinkelWert_Out, P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) StatSensorZustandNr_Out, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  else
FUNC(Std_ReturnType, RTE_BMWDIAGCSRVHNDLG_APPL_CODE) BmwDiagcSrvHndlgEpsIninSrvRes_Oper(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) StatRoutineStatus_Out, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) StatLenkradwinkelWert_Out, P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) StatSensorZustandNr_Out, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  endif
#  define RTE_STOP_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_RoutineServices_EpsInitialisierungService_Routine_RequestResults BmwDiagcSrvHndlgEpsIninSrvRes_Oper
#  define RTE_START_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_BMWDIAGCSRVHNDLG_APPL_CODE) BmwDiagcSrvHndlgEpsIninSrvStrt_Oper(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  define RTE_STOP_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_RoutineServices_EpsInitialisierungService_Routine_Start BmwDiagcSrvHndlgEpsIninSrvStrt_Oper
#  define RTE_START_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_BMWDIAGCSRVHNDLG_APPL_CODE) BmwDiagcSrvHndlgEpsIninSrvStop_Oper(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  define RTE_STOP_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_RoutineServices_EpsInitialisierungService_Routine_Stop BmwDiagcSrvHndlgEpsIninSrvStop_Oper
#  define RTE_START_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_BMWDIAGCSRVHNDLG_APPL_CODE) BmwDiagcSrvFHndlgEpsFactryIninRes_Oper(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) StatRoutineStatus_Out, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  define RTE_STOP_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_RoutineServices_EpsInitialisierungWerk_Routine_RequestResults BmwDiagcSrvFHndlgEpsFactryIninRes_Oper
#  define RTE_START_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_BMWDIAGCSRVHNDLG_APPL_CODE) BmwDiagcSrvFHndlgEpsFactryIninStrt_Oper(uint8 Winkel_In, uint8 Winkelgeschwindigkeit_In, uint8 Winkelbeschleunigung_In, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  define RTE_STOP_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_RoutineServices_EpsInitialisierungWerk_Routine_Start BmwDiagcSrvFHndlgEpsFactryIninStrt_Oper
#  define RTE_START_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_BMWDIAGCSRVHNDLG_APPL_CODE) BmwDiagcSrvFHndlgEpsFactryIninStop_Oper(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  define RTE_STOP_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_RoutineServices_EpsInitialisierungWerk_Routine_Stop BmwDiagcSrvFHndlgEpsFactryIninStop_Oper
#  define RTE_START_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_BMWDIAGCSRVHNDLG_APPL_CODE) BmwDiagcSrvHndlgEpsSteerAgSnsrCalRstStrt_Oper(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  define RTE_STOP_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_RoutineServices_EpsLenkwinkelsensorKalibrierungReset_Routine_Start BmwDiagcSrvHndlgEpsSteerAgSnsrCalRstStrt_Oper
#  define RTE_START_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_BMWDIAGCSRVHNDLG_APPL_CODE) BmwDiagcSrvHndlgEpsCommuteRes_Oper(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) StatEpsPendelnAktivNr_Out, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  define RTE_STOP_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_RoutineServices_EpsPendeln_Routine_RequestResults BmwDiagcSrvHndlgEpsCommuteRes_Oper
#  define RTE_START_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_BMWDIAGCSRVHNDLG_APPL_CODE) BmwDiagcSrvHndlgEpsCommuteStrt_Oper(uint8 Frequenz_In, uint8 MaxAmplitude_In, uint8 NumberOfCycles_In, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  define RTE_STOP_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_RoutineServices_EpsPendeln_Routine_Start BmwDiagcSrvHndlgEpsCommuteStrt_Oper
#  define RTE_START_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_BMWDIAGCSRVHNDLG_APPL_CODE) BmwDiagcSrvHndlgEpsProcRes_Oper(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) StatEpsVerfahrenAktivNr_Out, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  define RTE_STOP_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_RoutineServices_EpsVerfahren_Routine_RequestResults BmwDiagcSrvHndlgEpsProcRes_Oper
#  define RTE_START_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_BMWDIAGCSRVHNDLG_APPL_CODE) BmwDiagcSrvHndlgEpsProcStrt_Oper(P2CONST(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_DATA) Winkel_In, uint8 Winkelgeschwindigkeit_In, uint8 Winkelbeschleunigung_In, uint8 AbsolutEin_In, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  else
FUNC(Std_ReturnType, RTE_BMWDIAGCSRVHNDLG_APPL_CODE) BmwDiagcSrvHndlgEpsProcStrt_Oper(P2CONST(Dcm_Data2ByteType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_DATA) Winkel_In, uint8 Winkelgeschwindigkeit_In, uint8 Winkelbeschleunigung_In, uint8 AbsolutEin_In, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  endif
#  define RTE_STOP_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_RoutineServices_EpsVerfahren_Routine_Start BmwDiagcSrvHndlgEpsProcStrt_Oper
#  define RTE_START_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_BMWDIAGCSRVHNDLG_APPL_CODE) BmwDiagcSrvHndlgEpsRackCentrRstStrt_Oper(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  define RTE_STOP_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_RoutineServices_EpsZahnstangenmitteReset_Routine_Start BmwDiagcSrvHndlgEpsRackCentrRstStrt_Oper
#  define RTE_START_SEC_STDDIAG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_STDDIAG_APPL_CODE) StdDiag_RoutineControlStartClearDTCSecondaryErrorMemory(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_STDDIAG_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  define RTE_STOP_SEC_STDDIAG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_RoutineServices_IsLoeschen_Routine_Start StdDiag_RoutineControlStartClearDTCSecondaryErrorMemory
#  define Rte_Call_RoutineServices_RcCm_Routine_Start Rte_Call_Dcm_RoutineServices_RcCm_Routine_Start
#  define Rte_Call_RoutineServices_RcCpd_Routine_Start Rte_Call_Dcm_RoutineServices_RcCpd_Routine_Start
#  define RTE_START_SEC_STDDIAG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_STDDIAG_APPL_CODE) StdDiag_RoutineControlStartCheckProgrammingPreconditions(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_STDDIAG_APPL_VAR) dataOut, P2VAR(uint16, AUTOMATIC, RTE_STDDIAG_APPL_VAR) currentDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_STDDIAG_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  else
FUNC(Std_ReturnType, RTE_STDDIAG_APPL_CODE) StdDiag_RoutineControlStartCheckProgrammingPreconditions(Dcm_OpStatusType OpStatus, P2VAR(CheckProgrammingPreconditions_ArrayType, AUTOMATIC, RTE_STDDIAG_APPL_VAR) dataOut, P2VAR(uint16, AUTOMATIC, RTE_STDDIAG_APPL_VAR) currentDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_STDDIAG_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  endif
#  define RTE_STOP_SEC_STDDIAG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_RoutineServices_RcCppc_Routine_Start StdDiag_RoutineControlStartCheckProgrammingPreconditions
#  define Rte_Call_RoutineServices_RcEm_Routine_Start Rte_Call_Dcm_RoutineServices_RcEm_Routine_Start
#  define RTE_START_SEC_DLOG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_DLOG_APPL_CODE) Dlog_RoutineControlStartReadDevelopmentInfoField(P2CONST(uint8, AUTOMATIC, RTE_DLOG_APPL_DATA) DataIn, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DLOG_APPL_VAR) DataOut, P2VAR(uint16, AUTOMATIC, RTE_DLOG_APPL_VAR) CurrentDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DLOG_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  else
FUNC(Std_ReturnType, RTE_DLOG_APPL_CODE) Dlog_RoutineControlStartReadDevelopmentInfoField(P2CONST(RSInputArrayType, AUTOMATIC, RTE_DLOG_APPL_DATA) DataIn, Dcm_OpStatusType OpStatus, P2VAR(DevInfoArrayType, AUTOMATIC, RTE_DLOG_APPL_VAR) DataOut, P2VAR(uint16, AUTOMATIC, RTE_DLOG_APPL_VAR) CurrentDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DLOG_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  endif
#  define RTE_STOP_SEC_DLOG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_RoutineServices_RcRswedi_Routine_Start Dlog_RoutineControlStartReadDevelopmentInfoField
#  define RTE_START_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_BMWDIAGCSRVHNDLG_APPL_CODE) BmwDiagcSrvHndlgEpsPtlRackCentrRstStrt_Oper(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  define RTE_STOP_SEC_BMWDIAGCSRVHNDLG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_RoutineServices_SteuernEpsMultiturnwertReset_Routine_Start BmwDiagcSrvHndlgEpsPtlRackCentrRstStrt_Oper
#  define Rte_Call_RoutineServices_SteuernEpsPulldriftOffsetReset_Routine_Start Rte_Call_Dcm_RoutineServices_SteuernEpsPulldriftOffsetReset_Routine_Start
#  define Rte_Call_SecurityAccess_DcmDspSecurityRow_Coding_CompareKey Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_Coding_CompareKey
#  define Rte_Call_SecurityAccess_DcmDspSecurityRow_Coding_GetSeed Rte_Call_Dcm_SecurityAccess_DcmDspSecurityRow_Coding_GetSeed
#  define RTE_START_SEC_CODING_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CODING_APPL_CODE) Coding_DCMConfirmation(uint8 SID, uint8 ReqType, uint16 SourceAddress, Dcm_ConfirmationStatusType ConfirmationStatus); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  define RTE_STOP_SEC_CODING_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_ServiceRequestManufacturerNotification_Coding_Confirmation Coding_DCMConfirmation
#  define RTE_START_SEC_CODING_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODING_APPL_CODE) Coding_DCMIndication(uint8 SID, P2CONST(uint8, AUTOMATIC, RTE_CODING_APPL_DATA) RequestData, uint16 DataSize, uint8 ReqType, uint16 SourceAddress, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CODING_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  else
FUNC(Std_ReturnType, RTE_CODING_APPL_CODE) Coding_DCMIndication(uint8 SID, P2CONST(Dcm_Data1024ByteType, AUTOMATIC, RTE_CODING_APPL_DATA) RequestData, uint16 DataSize, uint8 ReqType, uint16 SourceAddress, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CODING_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  endif
#  define RTE_STOP_SEC_CODING_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_ServiceRequestManufacturerNotification_Coding_Indication Coding_DCMIndication
#  define RTE_START_SEC_STDDIAG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_STDDIAG_APPL_CODE) StdDiag_ManufacturerConfirmation(uint8 SID, uint8 ReqType, uint16 SourceAddress, Dcm_ConfirmationStatusType ConfirmationStatus); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  define RTE_STOP_SEC_STDDIAG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_ServiceRequestManufacturerNotification_StdDiag_Confirmation StdDiag_ManufacturerConfirmation
#  define RTE_START_SEC_STDDIAG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_STDDIAG_APPL_CODE) StdDiag_ManufacturerIndication(uint8 SID, P2CONST(uint8, AUTOMATIC, RTE_STDDIAG_APPL_DATA) RequestData, uint16 DataSize, uint8 ReqType, uint16 SourceAddress, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_STDDIAG_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  else
FUNC(Std_ReturnType, RTE_STDDIAG_APPL_CODE) StdDiag_ManufacturerIndication(uint8 SID, P2CONST(RequestDataArray, AUTOMATIC, RTE_STDDIAG_APPL_DATA) RequestData, uint16 DataSize, uint8 ReqType, uint16 SourceAddress, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_STDDIAG_APPL_VAR) ErrorCode); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
#  endif
#  define RTE_STOP_SEC_STDDIAG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_ServiceRequestManufacturerNotification_StdDiag_Indication StdDiag_ManufacturerIndication


# endif /* !defined(RTE_CORE) */


# define Dcm_START_SEC_CODE
# include "Dcm_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_Dcm_MainFunction Dcm_MainFunction
#  define RTE_RUNNABLE_GetActiveProtocol Dcm_GetActiveProtocol
#  define RTE_RUNNABLE_GetRequestKind Dcm_GetRequestKind
#  define RTE_RUNNABLE_GetSecurityLevel Dcm_GetSecurityLevel
#  define RTE_RUNNABLE_GetSesCtrlType Dcm_GetSesCtrlType
#  define RTE_RUNNABLE_ResetToDefaultSession Dcm_ResetToDefaultSession
#  define RTE_RUNNABLE_SetActiveDiagnostic Dcm_SetActiveDiagnostic
#  define RTE_RUNNABLE_TriggerOnEvent Dcm_TriggerOnEvent
# endif

FUNC(void, Dcm_CODE) Dcm_MainFunction(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, Dcm_CODE) Dcm_GetActiveProtocol(P2VAR(Dcm_ProtocolType, AUTOMATIC, RTE_DCM_APPL_VAR) ActiveProtocol); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, Dcm_CODE) Dcm_GetRequestKind(uint16 TesterSourceAddress, P2VAR(Dcm_RequestKindType, AUTOMATIC, RTE_DCM_APPL_VAR) RequestKind); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, Dcm_CODE) Dcm_GetSecurityLevel(P2VAR(Dcm_SecLevelType, AUTOMATIC, RTE_DCM_APPL_VAR) SecLevel); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, Dcm_CODE) Dcm_GetSesCtrlType(P2VAR(Dcm_SesCtrlType, AUTOMATIC, RTE_DCM_APPL_VAR) SesCtrlType); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, Dcm_CODE) Dcm_ResetToDefaultSession(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, Dcm_CODE) Dcm_SetActiveDiagnostic(boolean active); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, Dcm_CODE) Dcm_TriggerOnEvent(uint8 parg0); /* PRQA S 0850, 1330, 3451 */ /* MD_MSR_19.8, MD_Rte_1330, MD_Rte_3451 */

# define Dcm_STOP_SEC_CODE
# include "Dcm_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_DCMServices_E_NOT_OK (1U)

#  define RTE_E_DCMServices_E_OK (0U)

#  define RTE_E_DCM_Roe_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_1000_Pruefstempel_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_1000_Pruefstempel_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_100A_EnergySavingState_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_100E_ExtendedEnergySavingState_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_1701_Systemzeit_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_1704_DmDtcAktiveMeldung_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_1704_DmDtcAktiveMeldung_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_1723_DmIsDtcActiveResponse_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_2502_ProgrammingCounter_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_2503_ProgrammingCounterMaxValue_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_2504_FlashTimingParameter_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_2507_SwfkDeleteSupported_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_250B_ReadSwRevision_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_250B_ReadSwRevision_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_2540_MileKmEeprom_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_2540_MileKmEeprom_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_2541_StatusCalcvn_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_37FE_Cps_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_37FF_ReadProtocolData_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_DB3C_StatusFzgBordnetz_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_DB3C_StatusFzgBordnetz_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_DB57_EpsRitzelwinkelsensor_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_DB57_EpsRitzelwinkelsensor_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_DB5A_EpsLenkwinkelsensorKalibrierung_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_DB5A_EpsLenkwinkelsensorKalibrierung_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_DB99_EpsMomentensensor_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_DB99_EpsMomentensensor_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_DC77_EpsZahnstangenmitte_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_DC77_EpsZahnstangenmitte_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_DFDD_GelernterZahnstangenweg_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_DFDD_GelernterZahnstangenweg_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_F100_ReadActiveSessionState_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_F101_SvkAktuell_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_F101_SvkAktuell_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_F102_SvkSysSupplier_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_F102_SvkSysSupplier_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_F103_SvkWerk_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_F103_SvkWerk_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_F150_SgbdIdx_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_F152_Readhwmodificationindex_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_F15A_WdbiFp_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_F15A_WdbiFp_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_F18A_SystemSupplierIdentifier_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_F18A_SystemSupplierIdentifier_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_F18B_Herstelldatum_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_F18C_EcuSerialNumber_E_NOT_OK (1U)

#  define RTE_E_DataServices_DcmDspData_SvkBackup0_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DcmDspData_SvkBackup0_E_NOT_OK (1U)

#  define RTE_E_DataServices_DcmDspData_SvkBackup1_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DcmDspData_SvkBackup1_E_NOT_OK (1U)

#  define RTE_E_DataServices_DcmDspData_SvkBackup2_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DcmDspData_SvkBackup2_E_NOT_OK (1U)

#  define RTE_E_DataServices_DcmDspData_Vin_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DcmDspData_Vin_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_CheckNcd_Routine_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_CheckNcd_Routine_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_CheckNcd_Routine_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_ControlExtendedEnergySavingState_Routine_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_ControlExtendedEnergySavingState_Routine_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_ControlExtendedEnergySavingState_Routine_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_DarhStrtStop_Routine_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_DarhStrtStop_Routine_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_DarhStrtStop_Routine_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_DeleteSwPackage_Routine_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_DeleteSwPackage_Routine_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_DeleteSwPackage_Routine_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_DiagCommLoopback_Routine_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_DiagCommLoopback_Routine_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_DiagCommLoopback_Routine_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_DmClientTriggerDtcEntry_Routine_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_DmClientTriggerDtcEntry_Routine_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_DmClientTriggerDtcEntry_Routine_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Energiesparmode_Routine_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Energiesparmode_Routine_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Energiesparmode_Routine_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_EpsInitialisierungService_Routine_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_EpsInitialisierungService_Routine_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_EpsInitialisierungService_Routine_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_EpsInitialisierungWerk_Routine_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_EpsInitialisierungWerk_Routine_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_EpsInitialisierungWerk_Routine_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_EpsLenkwinkelsensorKalibrierungReset_Routine_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_EpsLenkwinkelsensorKalibrierungReset_Routine_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_EpsLenkwinkelsensorKalibrierungReset_Routine_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_EpsPendeln_Routine_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_EpsPendeln_Routine_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_EpsPendeln_Routine_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_EpsVerfahren_Routine_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_EpsVerfahren_Routine_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_EpsVerfahren_Routine_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_EpsZahnstangenmitteReset_Routine_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_EpsZahnstangenmitteReset_Routine_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_EpsZahnstangenmitteReset_Routine_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_IsLoeschen_Routine_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_IsLoeschen_Routine_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_IsLoeschen_Routine_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_RcCm_Routine_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_RcCm_Routine_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_RcCm_Routine_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_RcCpd_Routine_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_RcCpd_Routine_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_RcCpd_Routine_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_RcCppc_Routine_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_RcCppc_Routine_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_RcCppc_Routine_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_RcEm_Routine_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_RcEm_Routine_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_RcEm_Routine_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_RcRswedi_Routine_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_RcRswedi_Routine_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_RcRswedi_Routine_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_ReadNcd_Routine_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_ReadNcd_Routine_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_ReadNcd_Routine_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_SteuernEpsMultiturnwertReset_Routine_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_SteuernEpsMultiturnwertReset_Routine_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_SteuernEpsMultiturnwertReset_Routine_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_SteuernEpsPulldriftOffsetReset_Routine_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_SteuernEpsPulldriftOffsetReset_Routine_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_SteuernEpsPulldriftOffsetReset_Routine_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_WriteNcd_Routine_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_WriteNcd_Routine_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_WriteNcd_Routine_E_NOT_OK (1U)

#  define RTE_E_SecurityAccess_DcmDspSecurityRow_Coding_DCM_E_COMPARE_KEY_FAILED (11U)

#  define RTE_E_SecurityAccess_DcmDspSecurityRow_Coding_DCM_E_PENDING (10U)

#  define RTE_E_SecurityAccess_DcmDspSecurityRow_Coding_E_NOT_OK (1U)

#  define RTE_E_ServiceRequestNotification_E_NOT_OK (1U)

#  define RTE_E_ServiceRequestNotification_E_REQUEST_NOT_ACCEPTED (8U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_DCM_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_1330:  MISRA rule: 16.4
     Reason:     The RTE Generator uses default names for parameter identifiers of port defined arguments of service modules.
                 Therefore the parameter identifiers in the function declaration differs from those of the implementation of the BSW module.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
