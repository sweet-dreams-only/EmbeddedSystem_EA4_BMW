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
 *          File:  Rte_StdDiag.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <StdDiag>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_STDDIAG_H
# define _RTE_STDDIAG_H

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

# include "Rte_StdDiag_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(StdDiag_LifeCycleRequestType, RTE_VAR_INIT) Rte_BswM_Provide_MSRP_StdDiag_requestMode; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_LifeCycleRequest_requestMode (2U)
# endif


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Buffers for Mode Management
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(NormalCommunicationModeType, RTE_VAR_INIT) Rte_ModeMachine_BswM_Switch_StdDiagComControlNormalNotificationPort_CommunicationModeDeclarationGroup; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(Omc_ExtendedOperatingModeType, RTE_VAR_INIT) Rte_ModeMachine_Omc_extendedOperatingModeSwitchPort_currentExtendedOperatingMode; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(Omc_OperatingModeType, RTE_VAR_INIT) Rte_ModeMachine_Omc_operatingModeSwitchPort_currentOperatingMode; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */



# ifndef RTE_CORE

/**********************************************************************************************************************
 * Buffers for implicit communication
 *********************************************************************************************************************/

# endif


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_StdDiag_ComControlModeRequestPort_requestedMode(NormalCommunicationModeType data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(StdDiag_LifeCycleRequestType, RTE_CODE) Rte_Mode_StdDiag_LifeCycle_Mode(P2VAR(StdDiag_LifeCycleRequestType, AUTOMATIC, RTE_STDDIAG_APPL_VAR) previousMode, P2VAR(StdDiag_LifeCycleRequestType, AUTOMATIC, RTE_STDDIAG_APPL_VAR) nextMode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_StdDiag_LifeCycle_Mode(StdDiag_LifeCycleRequestType nextMode); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

/* PRQA S 3453 L1 */ /* MD_MSR_19.7 */
#  define Rte_IRead_LifeCycleHandler_LifeCycleRequest_requestMode() \
  (Rte_BswM_Provide_MSRP_StdDiag_requestMode)
/* PRQA L:L1 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_ComControlModeRequestPort_requestedMode Rte_Write_StdDiag_ComControlModeRequestPort_requestedMode


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Mode_ComControlNormalModeAccessPort_CommunicationModeDeclarationGroup() (Rte_ModeMachine_BswM_Switch_StdDiagComControlNormalNotificationPort_CommunicationModeDeclarationGroup) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Mode_ExtendedOperatingModeControlPort_currentExtendedOperatingMode() (Rte_ModeMachine_Omc_extendedOperatingModeSwitchPort_currentExtendedOperatingMode) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Mode_LifeCycle_Mode Rte_Mode_StdDiag_LifeCycle_Mode
#  define Rte_Mode_OperatingModeControlPort_currentOperatingMode() (Rte_ModeMachine_Omc_operatingModeSwitchPort_currentOperatingMode) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Mode_VehicleStatePort_currentVehicleStateMode() (RTE_MODE_Stm_VehicleStateMode_STM_VEHICLE_STATE_UNAVAILABLE) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Switch_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Switch_LifeCycle_Mode Rte_Switch_StdDiag_LifeCycle_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_DEMWRAPPER_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_DEMWRAPPER_APPL_CODE) DemWrapper_CddIf_ClearDTC(uint32 DTC, Dem_DTCFormatType DTCFormat, Dem_DTCOriginType DTCOrigin); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DEMWRAPPER_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_ClearDTCPort_ClearDTC DemWrapper_CddIf_ClearDTC
#  define RTE_START_SEC_DCM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_DCM_APPL_CODE) Dcm_GetSesCtrlType(P2VAR(Dcm_SesCtrlType, AUTOMATIC, RTE_DCM_APPL_VAR) SesCtrlType); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DCM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_DCMServicesPort_GetSesCtrlType Dcm_GetSesCtrlType
#  define RTE_START_SEC_DEMMASTER_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_DEMMASTER_0_APPL_CODE) Dem_SetEnableCondition(uint8 parg0, boolean ConditionFulfilled); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DEMMASTER_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_EnableConditionPort_SetEnableCondition(arg1) (Dem_SetEnableCondition((uint8)2, arg1)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_DARH_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_DARH_APPL_CODE) Darh_ReadRoeStateDataHandler(P2VAR(Darh_RoeStateType, AUTOMATIC, RTE_DARH_APPL_VAR) RoeState); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DARH_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_RoeStatePort_GetRoeState Darh_ReadRoeStateDataHandler
#  define Rte_Call_UserActiveSessionStatePort_GetActiveSessionState(arg1, arg2) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define StdDiag_START_SEC_CODE
# include "StdDiag_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_AllowOpModeChange StdDiag_AllowOpModeChange
#  define RTE_RUNNABLE_ConditionCheckActiveSessionState StdDiag_ConditionCheckActiveSessionState
#  define RTE_RUNNABLE_LifeCycleHandler StdDiag_LifeCycleHandler
#  define RTE_RUNNABLE_ManufacturerConfirmation StdDiag_ManufacturerConfirmation
#  define RTE_RUNNABLE_ManufacturerIndication StdDiag_ManufacturerIndication
#  define RTE_RUNNABLE_OpModeChangeCancelled StdDiag_OpModeChangeCancelled
#  define RTE_RUNNABLE_ReadDataActiveSessionState StdDiag_ReadActiveSessionState
#  define RTE_RUNNABLE_ReadDataSgbdIndex StdDiag_ReadSgbdIndex
#  define RTE_RUNNABLE_RoutineControlStartCheckProgrammingPreconditions StdDiag_RoutineControlStartCheckProgrammingPreconditions
#  define RTE_RUNNABLE_RoutineControlStartClearDTCSecondaryErrorMemory StdDiag_RoutineControlStartClearDTCSecondaryErrorMemory
#  define RTE_RUNNABLE_RoutineControlStartDiagCommLoopback StdDiag_RoutineControlStartDiagCommLoopback
#  define RTE_RUNNABLE_SessionChange_DefaultSession StdDiag_SesChgIndication_DefaultSession
#  define RTE_RUNNABLE_SessionChange_OtherSession StdDiag_SesChgIndication_OtherSession
# endif

FUNC(Std_ReturnType, StdDiag_CODE) StdDiag_AllowOpModeChange(Omc_OperatingModeType OperatingMode, Omc_ExtendedOperatingModeType ExtendedOperatingMode, Omc_OperatingModeType NewOperatingMode, Omc_ExtendedOperatingModeType NewExtendedOperatingMode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, StdDiag_CODE) StdDiag_ConditionCheckActiveSessionState(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_STDDIAG_APPL_VAR) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, StdDiag_CODE) StdDiag_LifeCycleHandler(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, StdDiag_CODE) StdDiag_ManufacturerConfirmation(uint8 SID, uint8 ReqType, uint16 SourceAddress, Dcm_ConfirmationStatusType ConfirmationStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, StdDiag_CODE) StdDiag_ManufacturerIndication(uint8 SID, P2CONST(uint8, AUTOMATIC, RTE_STDDIAG_APPL_DATA) RequestData, uint16 DataSize, uint8 ReqType, uint16 SourceAddress, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_STDDIAG_APPL_VAR) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, StdDiag_CODE) StdDiag_ManufacturerIndication(uint8 SID, P2CONST(RequestDataArray, AUTOMATIC, RTE_STDDIAG_APPL_DATA) RequestData, uint16 DataSize, uint8 ReqType, uint16 SourceAddress, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_STDDIAG_APPL_VAR) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
FUNC(Std_ReturnType, StdDiag_CODE) StdDiag_OpModeChangeCancelled(Omc_OperatingModeType OperatingMode, Omc_ExtendedOperatingModeType ExtendedOperatingMode, Omc_OperatingModeType RequestedOperatingMode, Omc_ExtendedOperatingModeType RequestedExtendedOperatingMode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, StdDiag_CODE) StdDiag_ReadActiveSessionState(P2VAR(uint8, AUTOMATIC, RTE_STDDIAG_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, StdDiag_CODE) StdDiag_ReadActiveSessionState(P2VAR(ActiveSessionState_ArrayType, AUTOMATIC, RTE_STDDIAG_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, StdDiag_CODE) StdDiag_ReadSgbdIndex(P2VAR(uint8, AUTOMATIC, RTE_STDDIAG_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, StdDiag_CODE) StdDiag_ReadSgbdIndex(P2VAR(SgbdIndex_ArrayType, AUTOMATIC, RTE_STDDIAG_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, StdDiag_CODE) StdDiag_RoutineControlStartCheckProgrammingPreconditions(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_STDDIAG_APPL_VAR) dataOut, P2VAR(uint16, AUTOMATIC, RTE_STDDIAG_APPL_VAR) currentDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_STDDIAG_APPL_VAR) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, StdDiag_CODE) StdDiag_RoutineControlStartCheckProgrammingPreconditions(Dcm_OpStatusType OpStatus, P2VAR(CheckProgrammingPreconditions_ArrayType, AUTOMATIC, RTE_STDDIAG_APPL_VAR) dataOut, P2VAR(uint16, AUTOMATIC, RTE_STDDIAG_APPL_VAR) currentDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_STDDIAG_APPL_VAR) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
FUNC(Std_ReturnType, StdDiag_CODE) StdDiag_RoutineControlStartClearDTCSecondaryErrorMemory(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_STDDIAG_APPL_VAR) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, StdDiag_CODE) StdDiag_RoutineControlStartDiagCommLoopback(P2CONST(uint8, AUTOMATIC, RTE_STDDIAG_APPL_DATA) dataIn, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_STDDIAG_APPL_VAR) dataOut, P2VAR(uint16, AUTOMATIC, RTE_STDDIAG_APPL_VAR) currentDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_STDDIAG_APPL_VAR) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, StdDiag_CODE) StdDiag_RoutineControlStartDiagCommLoopback(P2CONST(DiagCommLoopback_ArrayType, AUTOMATIC, RTE_STDDIAG_APPL_DATA) dataIn, Dcm_OpStatusType OpStatus, P2VAR(DiagCommLoopback_ArrayType, AUTOMATIC, RTE_STDDIAG_APPL_VAR) dataOut, P2VAR(uint16, AUTOMATIC, RTE_STDDIAG_APPL_VAR) currentDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_STDDIAG_APPL_VAR) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
FUNC(void, StdDiag_CODE) StdDiag_SesChgIndication_DefaultSession(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, StdDiag_CODE) StdDiag_SesChgIndication_OtherSession(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define StdDiag_STOP_SEC_CODE
# include "StdDiag_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_CddIf_DEM_CLEAR_BUSY (5U)

#  define RTE_E_CddIf_DEM_CLEAR_FAILED (3U)

#  define RTE_E_CddIf_DEM_CLEAR_MEMORY_ERROR (6U)

#  define RTE_E_CddIf_DEM_CLEAR_PENDING (4U)

#  define RTE_E_CddIf_DEM_CLEAR_WRONG_DTC (1U)

#  define RTE_E_CddIf_DEM_CLEAR_WRONG_DTCORIGIN (2U)

#  define RTE_E_CddIf_E_OK (0U)

#  define RTE_E_DataServices_ActiveSessionState_E_NOT_OK (1U)

#  define RTE_E_DataServices_ActiveSessionState_E_OK (0U)

#  define RTE_E_DataServices_SgbdIndex_E_NOT_OK (1U)

#  define RTE_E_DataServices_SgbdIndex_E_OK (0U)

#  define RTE_E_EnableCondition_E_NOT_OK (1U)

#  define RTE_E_EnableCondition_E_OK (0U)

#  define RTE_E_OmcModesCallouts_E_NOT_OK (1U)

#  define RTE_E_OmcModesCallouts_E_OK (0U)

#  define RTE_E_OmcModesCallouts_E_RUNNING (10U)

#  define RTE_E_RoeStateInterface_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_CheckProgrammingPreconditions_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_CheckProgrammingPreconditions_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_CheckProgrammingPreconditions_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_CheckProgrammingPreconditions_E_OK (0U)

#  define RTE_E_RoutineServices_ClearDTCSecondaryErrorMemory_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_ClearDTCSecondaryErrorMemory_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_ClearDTCSecondaryErrorMemory_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_DiagCommLoopback_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_DiagCommLoopback_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_DiagCommLoopback_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_DiagCommLoopback_E_OK (0U)

#  define RTE_E_ServiceRequestNotification_E_NOT_OK (1U)

#  define RTE_E_ServiceRequestNotification_E_OK (0U)

#  define RTE_E_ServiceRequestNotification_E_REQUEST_NOT_ACCEPTED (8U)

#  define RTE_E_StdDiagDCMServices_E_NOT_OK (1U)

#  define RTE_E_StdDiagDCMServices_E_OK (0U)

#  define RTE_E_UserActiveSessionState_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_STDDIAG_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
