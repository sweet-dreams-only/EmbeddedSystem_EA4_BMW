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
 *          File:  Rte_Omc.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <Omc>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_OMC_H
# define _RTE_OMC_H

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

# include "Rte_Omc_Type.h"
# include "Rte_DataHandleType.h"

# include "Rte_Hook.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(Omc_LifeCycleRequestType, RTE_VAR_INIT) Rte_BswM_Provide_MSRP_Omc_requestMode; /* PRQA S 0850 */ /* MD_MSR_19.8 */

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
FUNC(Omc_LifeCycleRequestType, RTE_CODE) Rte_Mode_Omc_LifeCycle_Mode(P2VAR(Omc_LifeCycleRequestType, AUTOMATIC, RTE_OMC_APPL_VAR) previousMode, P2VAR(Omc_LifeCycleRequestType, AUTOMATIC, RTE_OMC_APPL_VAR) nextMode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Omc_LifeCycle_Mode(Omc_LifeCycleRequestType nextMode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Omc_extendedOperatingModeSwitchPort_currentExtendedOperatingMode(Omc_ExtendedOperatingModeType nextMode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Omc_operatingModeSwitchPort_currentOperatingMode(Omc_OperatingModeType nextMode); /* PRQA S 0850 */ /* MD_MSR_19.8 */


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
  (Rte_BswM_Provide_MSRP_Omc_requestMode)
/* PRQA L:L1 */


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Mode_LifeCycle_Mode Rte_Mode_Omc_LifeCycle_Mode


/**********************************************************************************************************************
 * Rte_Switch_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Switch_LifeCycle_Mode Rte_Switch_Omc_LifeCycle_Mode
#  define Rte_Switch_extendedOperatingModeSwitchPort_currentExtendedOperatingMode Rte_Switch_Omc_extendedOperatingModeSwitchPort_currentExtendedOperatingMode
#  define Rte_Switch_operatingModeSwitchPort_currentOperatingMode Rte_Switch_Omc_operatingModeSwitchPort_currentOperatingMode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_DEMMASTER_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_DEMMASTER_0_APPL_CODE) Dem_SetEnableCondition(uint8 parg0, boolean ConditionFulfilled); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DEMMASTER_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_EnableCond_OMC_SetEnableCondition(arg1) (Dem_SetEnableCondition((uint8)1, arg1)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_GetErrorStatus(NvM_BlockIdType parg0, P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_NVM_APPL_VAR) ErrorStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_NvMServicePort_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)26, arg1)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_WriteBlock(NvM_BlockIdType parg0, dtRef_const_VOID SrcPtr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_NvMServicePort_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)26, arg1)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_STDDIAG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_STDDIAG_APPL_CODE) StdDiag_AllowOpModeChange(Omc_OperatingModeType OperatingMode, Omc_ExtendedOperatingModeType ExtendedOperatingMode, Omc_OperatingModeType NewOperatingMode, Omc_ExtendedOperatingModeType NewExtendedOperatingMode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_STDDIAG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_StdDiag_AllowOpModeSwitch StdDiag_AllowOpModeChange
#  define RTE_START_SEC_STDDIAG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_STDDIAG_APPL_CODE) StdDiag_OpModeChangeCancelled(Omc_OperatingModeType OperatingMode, Omc_ExtendedOperatingModeType ExtendedOperatingMode, Omc_OperatingModeType RequestedOperatingMode, Omc_ExtendedOperatingModeType RequestedExtendedOperatingMode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_STDDIAG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_StdDiag_OpModeSwitchCancelled StdDiag_OpModeChangeCancelled
#  define RTE_START_SEC_DEMSATELLITE_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_DEMSATELLITE_0_APPL_CODE) Dem_SetEventStatus(Dem_EventIdType parg0, Dem_EventStatusType EventStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DEMSATELLITE_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_VsmEventOpmode_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)27, arg1)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Exclusive Areas
 *********************************************************************************************************************/

#  define Rte_Enter_Mode() SuspendAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */

#  define Rte_Exit_Mode() ResumeAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */


# endif /* !defined(RTE_CORE) */


# define Omc_START_SEC_CODE
# include "Omc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_ChangeExtendedOperatingMode Omc_RoutineControlStartExtendedOperatingMode
#  define RTE_RUNNABLE_ChangeOperatingMode Omc_RoutineControlStartOperatingMode
#  define RTE_RUNNABLE_ClearEventAllowed Omc_ClearEventAllowed
#  define RTE_RUNNABLE_ConditionCheckReadExtendedOperatingMode Omc_ConditionCheckReadDIDExtendedOperatingMode
#  define RTE_RUNNABLE_ConditionCheckReadOperatingMode Omc_ConditionCheckReadDIDOperatingMode
#  define RTE_RUNNABLE_LifeCycleHandler Omc_LifeCycleHandler
#  define RTE_RUNNABLE_NvMWriteJobFinished Omc_NvMNotifyJobFinishedOperatingModes
#  define RTE_RUNNABLE_ReadDIDExtendedOperatingMode Omc_ReadDIDExtendedOperatingMode
#  define RTE_RUNNABLE_ReadOperatingMode Omc_ReadDIDOperatingMode
#  define RTE_RUNNABLE_StdDiag_OpModeSwitchAllowedResult Omc_StdDiag_OpModeSwitchAllowedResult
#  define RTE_RUNNABLE_StdDiag_OpModeSwitchCancelledAck Omc_StdDiag_OpModeSwitchCancelledAck
# endif

FUNC(Std_ReturnType, Omc_CODE) Omc_RoutineControlStartExtendedOperatingMode(uint8 ExtendedOperatingMode, OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_OMC_APPL_VAR) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Omc_CODE) Omc_RoutineControlStartOperatingMode(uint8 OperatingMode, OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_OMC_APPL_VAR) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Omc_CODE) Omc_ClearEventAllowed(P2VAR(boolean, AUTOMATIC, RTE_OMC_APPL_VAR) Allowed); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Omc_CODE) Omc_ConditionCheckReadDIDExtendedOperatingMode(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_OMC_APPL_VAR) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Omc_CODE) Omc_ConditionCheckReadDIDOperatingMode(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_OMC_APPL_VAR) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, Omc_CODE) Omc_LifeCycleHandler(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, Omc_CODE) Omc_NvMNotifyJobFinishedOperatingModes(uint8 ServiceId, RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, Omc_CODE) Omc_ReadDIDExtendedOperatingMode(P2VAR(uint8, AUTOMATIC, RTE_OMC_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, Omc_CODE) Omc_ReadDIDExtendedOperatingMode(P2VAR(uint8, AUTOMATIC, RTE_OMC_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, Omc_CODE) Omc_ReadDIDOperatingMode(P2VAR(uint8, AUTOMATIC, RTE_OMC_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, Omc_CODE) Omc_ReadDIDOperatingMode(P2VAR(uint8, AUTOMATIC, RTE_OMC_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
FUNC(Std_ReturnType, Omc_CODE) Omc_StdDiag_OpModeSwitchAllowedResult(boolean Result); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Omc_CODE) Omc_StdDiag_OpModeSwitchCancelledAck(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define Omc_STOP_SEC_CODE
# include "Omc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_CallbackClearEventAllowed_E_NOT_OK (1U)

#  define RTE_E_DataServices_ExtendedOperatingMode_E_NOT_OK (1U)

#  define RTE_E_DataServices_OperatingMode_E_NOT_OK (1U)

#  define RTE_E_EnableCondition_E_NOT_OK (1U)

#  define RTE_E_NvMNotifyJobFinished_E_OK (0U)

#  define RTE_E_NvMService_OMC_E_NOT_OK (1U)

#  define RTE_E_OmcModesCallouts_E_NOT_OK (1U)

#  define RTE_E_OmcModesCallouts_E_OK (0U)

#  define RTE_E_OmcModesCallouts_E_RUNNING (10U)

#  define RTE_E_OmcModesCalloutsResult_E_OK (0U)

#  define RTE_E_Omc_DiagnosticMonitor_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_ExtendedOperatingModeControl_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_ExtendedOperatingModeControl_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_ExtendedOperatingModeControl_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_OperatingModeControl_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_OperatingModeControl_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_OperatingModeControl_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_OMC_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
