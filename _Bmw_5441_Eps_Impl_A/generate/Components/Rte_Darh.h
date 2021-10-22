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
 *          File:  Rte_Darh.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <Darh>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_DARH_H
# define _RTE_DARH_H

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

# include "Rte_Darh_Type.h"
# include "Rte_DataHandleType.h"

# include "Rte_Hook.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(Darh_LifeCycleRequestType, RTE_VAR_INIT) Rte_BswM_Provide_MSRP_Darh_requestMode; /* PRQA S 0850 */ /* MD_MSR_19.8 */

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
 * Buffers for implicit communication
 *********************************************************************************************************************/

# endif


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Darh_LifeCycleRequestType, RTE_CODE) Rte_Mode_Darh_LifeCycle_Mode(P2VAR(Darh_LifeCycleRequestType, AUTOMATIC, RTE_DARH_APPL_VAR) previousMode, P2VAR(Darh_LifeCycleRequestType, AUTOMATIC, RTE_DARH_APPL_VAR) nextMode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Darh_LifeCycle_Mode(Darh_LifeCycleRequestType nextMode); /* PRQA S 0850 */ /* MD_MSR_19.8 */


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
  (Rte_BswM_Provide_MSRP_Darh_requestMode)
/* PRQA L:L1 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_Com_data Rte_Write_Darh_Com_data
#  define Rte_Write_Darh_Com_data(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Mode_LifeCycle_Mode Rte_Mode_Darh_LifeCycle_Mode


/**********************************************************************************************************************
 * Rte_Switch_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Switch_LifeCycle_Mode Rte_Switch_Darh_LifeCycle_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_DEMWRAPPER_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_DEMWRAPPER_APPL_CODE) DemWrapper_ApplicationDTCInfoPort_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, P2VAR(uint32, AUTOMATIC, RTE_DEMWRAPPER_APPL_VAR) DTCOfEvent); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DEMWRAPPER_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_ApplicationDTCInfoPort_GetDTCOfEvent DemWrapper_ApplicationDTCInfoPort_GetDTCOfEvent
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_WriteBlock(NvM_BlockIdType parg0, dtRef_const_VOID SrcPtr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_DiagnoseMasterStatus_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)11, arg1)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_DEMSATELLITE_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_DEMSATELLITE_0_APPL_CODE) Dem_SetEventStatus(Dem_EventIdType parg0, Dem_EventStatusType EventStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DEMSATELLITE_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_DmTestAppl_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)7, arg1)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_DmTestCom_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)9, arg1)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_SetRamBlockStatus(NvM_BlockIdType parg0, boolean RamBlockStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_ErrorQueueBlock_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)20, arg1)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_DEMWRAPPER_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_DEMWRAPPER_APPL_CODE) DemWrapper_Darh_GeneralDiagnosticInfo_GetDTCOfEvent(Dem_EventIdType EventId, Dem_DTCFormatType DTCFormat, P2VAR(uint32, AUTOMATIC, RTE_DEMWRAPPER_APPL_VAR) DTCOfEvent); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DEMWRAPPER_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_GeneralDiagnosticInfoPort_GetDTCOfEvent DemWrapper_Darh_GeneralDiagnosticInfo_GetDTCOfEvent
#  define RTE_START_SEC_DEMWRAPPER_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_DEMWRAPPER_APPL_CODE) DemWrapper_Darh_GeneralDiagnosticInfo_GetEventFreezeFrameData(Dem_EventIdType EventId, uint8 RecordNumber, boolean ReportTotalRecord, uint16 DataId, P2VAR(uint8, AUTOMATIC, RTE_DEMWRAPPER_APPL_VAR) DestBuffer); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_DEMWRAPPER_APPL_CODE) DemWrapper_Darh_GeneralDiagnosticInfo_GetEventFreezeFrameData(Dem_EventIdType EventId, uint8 RecordNumber, boolean ReportTotalRecord, uint16 DataId, P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_DEMWRAPPER_APPL_VAR) DestBuffer); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_DEMWRAPPER_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_GeneralDiagnosticInfoPort_GetEventFreezeFrameData DemWrapper_Darh_GeneralDiagnosticInfo_GetEventFreezeFrameData
#  define RTE_START_SEC_DEMWRAPPER_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_DEMWRAPPER_APPL_CODE) DemWrapper_NetworkDTCInfoPort_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, P2VAR(uint32, AUTOMATIC, RTE_DEMWRAPPER_APPL_VAR) DTCOfEvent); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DEMWRAPPER_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_NetworkDTCInfoPort_GetDTCOfEvent DemWrapper_NetworkDTCInfoPort_GetDTCOfEvent
#  define Rte_Call_ReportDynamicallyEventPort_EventIdx2EventId(arg1, arg2) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_ReportDynamicallyEventPort_EventToReport(arg1, arg2) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_ReportDynamicallyEventPort_EventToReportCount(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Exclusive Areas
 *********************************************************************************************************************/

#  define Rte_Enter_ExclusiveArea_0() SuspendAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */

#  define Rte_Exit_ExclusiveArea_0() ResumeAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */


# endif /* !defined(RTE_CORE) */


# define Darh_START_SEC_CODE
# include "Darh_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_ConditionCheckRead Darh_ConditionCheckReadErrorQueueHandler
#  define RTE_RUNNABLE_ConditionCheckReadActivelyReportedDtc Darh_ConditionCheckReadActivelyReportedDtcHandler
#  define RTE_RUNNABLE_EventDataChanged Darh_EventDataChangedHandler
#  define RTE_RUNNABLE_GetRoeState Darh_ReadRoeStateDataHandler
#  define RTE_RUNNABLE_LifeCycleHandler Darh_LifeCycleHandler
#  define RTE_RUNNABLE_QueueHandler Darh_ErrorQueueHandler
#  define RTE_RUNNABLE_ReadActivelyReportedDtc Darh_ReadActivelyReportedDtcDataHandler
#  define RTE_RUNNABLE_ReadActivelyReportedDtcLength Darh_ReadActivelyReportedDtcLengthHandler
#  define RTE_RUNNABLE_ReadErrorQueue Darh_ReadErrorQueueDataHandler
#  define RTE_RUNNABLE_ReadErrorQueueLength Darh_ReadErrorQueueLengthHandler
#  define RTE_RUNNABLE_SetRoeSuspended Darh_SetRoeSuspendedHandler
#  define RTE_RUNNABLE_StartRoutineDiagnoseMaster Darh_StartRoutineDiagnoseMasterHandler
#  define RTE_RUNNABLE_StartRoutineTriggerDtc Darh_StartRoutineTriggerDtcHandler
#  define RTE_RUNNABLE_StopRoutineDiagnoseMaster Darh_StopRoutineDiagnoseMasterHandler
#  define RTE_RUNNABLE_WriteDataBlockNotification Darh_NvMNotifyJobFinishedDiagnoseMasterStatus
# endif

FUNC(void, Darh_CODE) Darh_ConditionCheckReadErrorQueueHandler(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, Darh_CODE) Darh_ConditionCheckReadActivelyReportedDtcHandler(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DARH_APPL_VAR) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, Darh_CODE) Darh_EventDataChangedHandler(Dem_EventIdType EventId); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Darh_CODE) Darh_ReadRoeStateDataHandler(P2VAR(Darh_RoeStateType, AUTOMATIC, RTE_DARH_APPL_VAR) RoeState); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, Darh_CODE) Darh_LifeCycleHandler(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, Darh_CODE) Darh_ErrorQueueHandler(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, Darh_CODE) Darh_ReadActivelyReportedDtcDataHandler(P2VAR(uint8, AUTOMATIC, RTE_DARH_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, Darh_CODE) Darh_ReadActivelyReportedDtcDataHandler(P2VAR(Darh_ActivelyReportedErrorListType, AUTOMATIC, RTE_DARH_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
FUNC(Std_ReturnType, Darh_CODE) Darh_ReadActivelyReportedDtcLengthHandler(P2VAR(uint16, AUTOMATIC, RTE_DARH_APPL_VAR) DataLength); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, Darh_CODE) Darh_ReadErrorQueueDataHandler(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, Darh_CODE) Darh_ReadErrorQueueLengthHandler(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, Darh_CODE) Darh_SetRoeSuspendedHandler(boolean suspended); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Darh_CODE) Darh_StartRoutineDiagnoseMasterHandler(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DARH_APPL_VAR) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Darh_CODE) Darh_StartRoutineTriggerDtcHandler(uint8 DTCType, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DARH_APPL_VAR) DTCTypeOut, P2VAR(uint8, AUTOMATIC, RTE_DARH_APPL_VAR) DTCByte1, P2VAR(uint8, AUTOMATIC, RTE_DARH_APPL_VAR) DTCByte2, P2VAR(uint8, AUTOMATIC, RTE_DARH_APPL_VAR) DTCByte3, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DARH_APPL_VAR) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Darh_CODE) Darh_StopRoutineDiagnoseMasterHandler(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DARH_APPL_VAR) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Darh_CODE) Darh_NvMNotifyJobFinishedDiagnoseMasterStatus(uint8 ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define Darh_STOP_SEC_CODE
# include "Darh_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_DarhControlInterface_E_NOT_OK (1U)

#  define RTE_E_DarhReportDynamicallyEvent_E_NOT_OK (1U)

#  define RTE_E_Darh_DiagnosticInfo_DEM_E_NO_DTC_AVAILABLE (2U)

#  define RTE_E_Darh_DiagnosticInfo_E_NOT_OK (1U)

#  define RTE_E_Darh_DiagnosticMonitor_E_NOT_OK (1U)

#  define RTE_E_Darh_GeneralDiagnosticInfo_DEM_E_NODATAAVAILABLE (48U)

#  define RTE_E_Darh_GeneralDiagnosticInfo_DEM_E_NO_DTC_AVAILABLE (2U)

#  define RTE_E_Darh_GeneralDiagnosticInfo_DEM_E_WRONG_DIDNUMBER (50U)

#  define RTE_E_Darh_GeneralDiagnosticInfo_DEM_E_WRONG_RECORDNUMBER (49U)

#  define RTE_E_Darh_GeneralDiagnosticInfo_E_NOT_OK (1U)

#  define RTE_E_Darh_NvMService_E_NOT_OK (1U)

#  define RTE_E_DataServices_ActivelyReportedDtc_E_NOT_OK (1U)

#  define RTE_E_NvMNotifyJobFinished_E_OK (0U)

#  define RTE_E_RoeStateInterface_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_StartStopRoutineDiagnoseMaster_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_StartStopRoutineDiagnoseMaster_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_StartStopRoutineDiagnoseMaster_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_TriggerDTC_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_TriggerDTC_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_TriggerDTC_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_DARH_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
