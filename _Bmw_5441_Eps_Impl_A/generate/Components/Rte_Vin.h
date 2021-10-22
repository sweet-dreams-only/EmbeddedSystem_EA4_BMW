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
 *          File:  Rte_Vin.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <Vin>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_VIN_H
# define _RTE_VIN_H

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

# include "Rte_Vin_Type.h"
# include "Rte_DataHandleType.h"

# include "Rte_Hook.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(Vin_ComVinType, RTE_VAR_INIT) Rte_BacComIf_ComVin_ComVin; /* PRQA S 0850 */ /* MD_MSR_19.8 */

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

extern VAR(uint8, RTE_VAR_INIT) Rte_ModeMachine_Vin_VinChangeIndicator_ChangeIndicator; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */



# ifndef RTE_CORE

/**********************************************************************************************************************
 * Buffers for implicit communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(Rte_tsTask_100ms_Appl10, RTE_VAR_NOINIT) Rte_Task_100ms_Appl10; /* PRQA S 0850, 0759 */ /* MD_MSR_19.8, MD_MSR_18.4 */

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# endif


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Vin_Vin_Vin(P2CONST(Vin_VinType, AUTOMATIC, RTE_VIN_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Vin_LifeCycleRequestType, RTE_CODE) Rte_Mode_Vin_LifeCycle_Mode(P2VAR(Vin_LifeCycleRequestType, AUTOMATIC, RTE_VIN_APPL_VAR) previousMode, P2VAR(Vin_LifeCycleRequestType, AUTOMATIC, RTE_VIN_APPL_VAR) nextMode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Vin_LifeCycle_Mode(Vin_LifeCycleRequestType nextMode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Vin_VinChangeIndicator_ChangeIndicator(uint8 nextMode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_SwitchAck_Vin_VinChangeIndicator_ChangeIndicator(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */


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
#  define Rte_IRead_Vin_LifeCycleModeRequest_LifeCycleRequest_requestMode() \
  (Rte_Task_100ms_Appl10.Rte_RB.Rte_Vin_Vin_LifeCycleModeRequest.Rte_LifeCycleRequest_requestMode.value)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_19.7 */
#  define Rte_IRead_Vin_ReceiveFromCom_ComVin_ComVin() \
  (&Rte_BacComIf_ComVin_ComVin)
/* PRQA L:L1 */


/**********************************************************************************************************************
 * Rte_Send_<p>_<d> (explicit S/R communication with isQueued = true)
 *********************************************************************************************************************/
#  define Rte_Send_VinRequest_RequestMessageIdentifier Rte_Send_Vin_VinRequest_RequestMessageIdentifier
#  define Rte_Send_Vin_VinRequest_RequestMessageIdentifier(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_Vin_Vin Rte_Write_Vin_Vin_Vin


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Mode_LifeCycle_Mode Rte_Mode_Vin_LifeCycle_Mode
#  define Rte_Mode_VinChangeIndicator_ChangeIndicator() (Rte_ModeMachine_Vin_VinChangeIndicator_ChangeIndicator) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Switch_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Switch_LifeCycle_Mode Rte_Switch_Vin_LifeCycle_Mode
#  define Rte_Switch_VinChangeIndicator_ChangeIndicator Rte_Switch_Vin_VinChangeIndicator_ChangeIndicator


/**********************************************************************************************************************
 * Rte_Feedback_<p>_<m> (mode switch acknowledge)
 *********************************************************************************************************************/
#  define Rte_SwitchAck_VinChangeIndicator_ChangeIndicator Rte_SwitchAck_Vin_VinChangeIndicator_ChangeIndicator


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_DLOG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_DLOG_APPL_CODE) Dlog_GetVin(P2VAR(uint8, AUTOMATIC, RTE_DLOG_APPL_VAR) Vin); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_DLOG_APPL_CODE) Dlog_GetVin(P2VAR(Dlog_VinArrayType, AUTOMATIC, RTE_DLOG_APPL_VAR) Vin); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_DLOG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_DlogEcuInfo_GetVin Dlog_GetVin
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_GetErrorStatus(NvM_BlockIdType parg0, P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_NVM_APPL_VAR) ErrorStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_NvMService_Vin_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)27, arg1)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_ReadBlock(NvM_BlockIdType parg0, dtRef_VOID DstPtr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_NvMService_Vin_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)27, arg1)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_WriteBlock(NvM_BlockIdType parg0, dtRef_const_VOID SrcPtr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_NvMService_Vin_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)27, arg1)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Exclusive Areas
 *********************************************************************************************************************/

/* PRQA S 3458 L1 */ /* MD_MSR_19.4 */
#  define Rte_Enter_VinState()  /* RteAnalyzer(ExclusiveArea, OS_RESOURCE) */ \
  { \
    StatusType osStatus; \
    osStatus = GetResource(Rte_Res_Vin_VinState); /* PRQA S 3417 */ /* MD_Rte_Os */ \
    Rte_CheckDetErrorContinue((osStatus != E_OS_ACCESS) && (osStatus != E_OS_DISABLEDINT), RTE_ENTER_SERVICE_ID, RTE_E_DET_ILLEGAL_NESTED_EXCLUSIVE_AREA); /* PRQA S 3109 */ /* MD_MSR_14.3 */ \
  }
/* PRQA L:L1 */

/* PRQA S 3458 L1 */ /* MD_MSR_19.4 */
#  define Rte_Exit_VinState()  /* RteAnalyzer(ExclusiveArea, OS_RESOURCE) */ \
  { \
    StatusType osStatus; \
    osStatus = ReleaseResource(Rte_Res_Vin_VinState); /* PRQA S 3417 */ /* MD_Rte_Os */ \
    Rte_CheckDetErrorContinue((osStatus != E_OS_ACCESS) && (osStatus != E_OS_DISABLEDINT) && (osStatus != E_OS_NOFUNC), RTE_EXIT_SERVICE_ID, RTE_E_DET_ILLEGAL_NESTED_EXCLUSIVE_AREA); /* PRQA S 3109 */ /* MD_MSR_14.3 */ \
  }
/* PRQA L:L1 */


# endif /* !defined(RTE_CORE) */


# define Vin_START_SEC_CODE
# include "Vin_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_Vin_LifeCycleModeRequest Vin_LifeCycleModeRequest
#  define RTE_RUNNABLE_Vin_Main Vin_Main
#  define RTE_RUNNABLE_Vin_NvmJobFinished Vin_NvmJobFinished
#  define RTE_RUNNABLE_Vin_OnComOff Vin_OnComOff
#  define RTE_RUNNABLE_Vin_OnComOn Vin_OnComOn
#  define RTE_RUNNABLE_Vin_OnVinChangeIndicatorAck Vin_OnVinChangeIndicatorAck
#  define RTE_RUNNABLE_Vin_ReceiveFromCom Vin_ReceiveFromCom
# endif

FUNC(void, Vin_CODE) Vin_LifeCycleModeRequest(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, Vin_CODE) Vin_Main(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, Vin_CODE) Vin_NvmJobFinished(uint8 ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, Vin_CODE) Vin_OnComOff(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, Vin_CODE) Vin_OnComOn(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, Vin_CODE) Vin_OnVinChangeIndicatorAck(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, Vin_CODE) Vin_ReceiveFromCom(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define Vin_STOP_SEC_CODE
# include "Vin_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_EcuInfo_E_NOT_OK (1U)

#  define RTE_E_Vin_NvMNotifyJobFinished_E_OK (0U)

#  define RTE_E_Vin_NvMService_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_VIN_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_Os:
     Reason:     This justification is used as summary justification for all deviations caused by the MICROSAR OS
                 which is for testing of the RTE. Those deviations are no issues in the RTE code.
     Risk:       No functional risk.
     Prevention: Not required.

*/
