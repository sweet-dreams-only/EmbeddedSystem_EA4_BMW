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
 *          File:  Rte_BswM.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <BswM>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_BSWM_H
# define _RTE_BSWM_H

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

# include "Rte_BswM_Type.h"
# include "Rte_DataHandleType.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_Provide_MSRP_StdDiag_requestMode (2U)
#  define Rte_InitValue_Provide_MSRP_Vin_requestMode (2U)
#  define Rte_InitValue_Request_StdDiag_ComControlModeRequest_requestedMode (0U)
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BswM_Request_StdDiag_ComControlModeRequest_requestedMode(P2VAR(NormalCommunicationModeType, AUTOMATIC, RTE_BSWM_APPL_VAR) data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BswM_Provide_MSRP_Coding_requestMode(Coding_LifeCycleRequestType data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BswM_Provide_MSRP_Darh_requestMode(Darh_LifeCycleRequestType data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BswM_Provide_MSRP_Dlog_requestMode(Dlog_LifeCycleRequestType data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BswM_Provide_MSRP_Omc_requestMode(Omc_LifeCycleRequestType data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BswM_Provide_MSRP_StdDiag_requestMode(StdDiag_LifeCycleRequestType data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BswM_Provide_MSRP_SysTime_requestMode(SysTime_LifeCycleRequestType data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BswM_Provide_MSRP_Vin_requestMode(Vin_LifeCycleRequestType data); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Stm_CentralErrorLockType, RTE_CODE) Rte_Mode_BswM_Notification_SWCModeSwitch_currentCentralErrorLockMode_currentCentralErrorLockMode(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Coding_LifeCycleRequestType, RTE_CODE) Rte_Mode_BswM_Notification_SwcModeNotification_Coding_LifeCycle_Mode(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Darh_LifeCycleRequestType, RTE_CODE) Rte_Mode_BswM_Notification_SwcModeNotification_Darh_LifeCycle_Mode(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Dcm_CommunicationModeType, RTE_CODE) Rte_Mode_BswM_Notification_SwcModeNotification_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Dcm_DiagnosticSessionControlType, RTE_CODE) Rte_Mode_BswM_Notification_SwcModeNotification_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Dcm_EcuResetType, RTE_CODE) Rte_Mode_BswM_Notification_SwcModeNotification_DcmEcuReset_DcmEcuReset(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Dlog_LifeCycleRequestType, RTE_CODE) Rte_Mode_BswM_Notification_SwcModeNotification_Dlog_LifeCycle_Mode(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Omc_LifeCycleRequestType, RTE_CODE) Rte_Mode_BswM_Notification_SwcModeNotification_Omc_LifeCycle_Mode(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(StdDiag_LifeCycleRequestType, RTE_CODE) Rte_Mode_BswM_Notification_SwcModeNotification_StdDiag_LifeCycle_Mode(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(SysTime_LifeCycleRequestType, RTE_CODE) Rte_Mode_BswM_Notification_SwcModeNotification_SysTime_LifeCycle_Mode(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Vin_LifeCycleRequestType, RTE_CODE) Rte_Mode_BswM_Notification_SwcModeNotification_Vin_LifeCycle_Mode(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_BswM_Switch_Coding_BusComModeSwitch_Mode(uint8 nextMode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_BswM_Switch_Coding_SwitchCodingMode_currentConditionMode(Coding_ConditionModeType nextMode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_BswM_Switch_ErrorMemoryLockSignalReceptionSwitchPort_currentEMLockSignalReceptionMode(uint8 nextMode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_BswM_Switch_StdDiagComControlNormalNotificationPort_CommunicationModeDeclarationGroup(NormalCommunicationModeType nextMode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_BswM_Switch_StdDiagSessionChangeIndicationPort_SessionModeDeclarationGroup(uint8 nextMode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_BswM_Switch_SwitchPort_Darh_ReportErrorMode_DarhReportErrorMode(uint8 nextMode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_BswM_Switch_VinComSwitchPort_Mode(uint8 nextMode); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_Request_StdDiag_ComControlModeRequest_requestedMode Rte_Read_BswM_Request_StdDiag_ComControlModeRequest_requestedMode


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_Provide_MSRP_Coding_requestMode Rte_Write_BswM_Provide_MSRP_Coding_requestMode
#  define Rte_Write_Provide_MSRP_Darh_requestMode Rte_Write_BswM_Provide_MSRP_Darh_requestMode
#  define Rte_Write_Provide_MSRP_Dlog_requestMode Rte_Write_BswM_Provide_MSRP_Dlog_requestMode
#  define Rte_Write_Provide_MSRP_Omc_requestMode Rte_Write_BswM_Provide_MSRP_Omc_requestMode
#  define Rte_Write_Provide_MSRP_StdDiag_requestMode Rte_Write_BswM_Provide_MSRP_StdDiag_requestMode
#  define Rte_Write_Provide_MSRP_SysTime_requestMode Rte_Write_BswM_Provide_MSRP_SysTime_requestMode
#  define Rte_Write_Provide_MSRP_Vin_requestMode Rte_Write_BswM_Provide_MSRP_Vin_requestMode


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Mode_Notification_SWCModeSwitch_currentCentralErrorLockMode_currentCentralErrorLockMode Rte_Mode_BswM_Notification_SWCModeSwitch_currentCentralErrorLockMode_currentCentralErrorLockMode
#  define Rte_Mode_Notification_SwcModeNotification_Coding_LifeCycle_Mode Rte_Mode_BswM_Notification_SwcModeNotification_Coding_LifeCycle_Mode
#  define Rte_Mode_Notification_SwcModeNotification_Darh_LifeCycle_Mode Rte_Mode_BswM_Notification_SwcModeNotification_Darh_LifeCycle_Mode
#  define Rte_Mode_Notification_SwcModeNotification_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6 Rte_Mode_BswM_Notification_SwcModeNotification_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6
#  define Rte_Mode_Notification_SwcModeNotification_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl Rte_Mode_BswM_Notification_SwcModeNotification_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl
#  define Rte_Mode_Notification_SwcModeNotification_DcmEcuReset_DcmEcuReset Rte_Mode_BswM_Notification_SwcModeNotification_DcmEcuReset_DcmEcuReset
#  define Rte_Mode_Notification_SwcModeNotification_Dlog_LifeCycle_Mode Rte_Mode_BswM_Notification_SwcModeNotification_Dlog_LifeCycle_Mode
#  define Rte_Mode_Notification_SwcModeNotification_Omc_LifeCycle_Mode Rte_Mode_BswM_Notification_SwcModeNotification_Omc_LifeCycle_Mode
#  define Rte_Mode_Notification_SwcModeNotification_StdDiag_LifeCycle_Mode Rte_Mode_BswM_Notification_SwcModeNotification_StdDiag_LifeCycle_Mode
#  define Rte_Mode_Notification_SwcModeNotification_SysTime_LifeCycle_Mode Rte_Mode_BswM_Notification_SwcModeNotification_SysTime_LifeCycle_Mode
#  define Rte_Mode_Notification_SwcModeNotification_Vin_LifeCycle_Mode Rte_Mode_BswM_Notification_SwcModeNotification_Vin_LifeCycle_Mode


/**********************************************************************************************************************
 * Rte_Switch_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Switch_Switch_Coding_BusComModeSwitch_Mode Rte_Switch_BswM_Switch_Coding_BusComModeSwitch_Mode
#  define Rte_Switch_Switch_Coding_SwitchCodingMode_currentConditionMode Rte_Switch_BswM_Switch_Coding_SwitchCodingMode_currentConditionMode
#  define Rte_Switch_Switch_ErrorMemoryLockSignalReceptionSwitchPort_currentEMLockSignalReceptionMode Rte_Switch_BswM_Switch_ErrorMemoryLockSignalReceptionSwitchPort_currentEMLockSignalReceptionMode
#  define Rte_Switch_Switch_StdDiagComControlNormalNotificationPort_CommunicationModeDeclarationGroup Rte_Switch_BswM_Switch_StdDiagComControlNormalNotificationPort_CommunicationModeDeclarationGroup
#  define Rte_Switch_Switch_StdDiagSessionChangeIndicationPort_SessionModeDeclarationGroup Rte_Switch_BswM_Switch_StdDiagSessionChangeIndicationPort_SessionModeDeclarationGroup
#  define Rte_Switch_Switch_SwitchPort_Darh_ReportErrorMode_DarhReportErrorMode Rte_Switch_BswM_Switch_SwitchPort_Darh_ReportErrorMode_DarhReportErrorMode
#  define Rte_Switch_Switch_VinComSwitchPort_Mode Rte_Switch_BswM_Switch_VinComSwitchPort_Mode


# endif /* !defined(RTE_CORE) */


# define BswM_START_SEC_CODE
# include "BswM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_BswM_MainFunction BswM_MainFunction
#  define RTE_RUNNABLE_BswM_Read_StdDiag_ComControlModeRequest BswM_Read_StdDiag_ComControlModeRequest
# endif

FUNC(void, BswM_CODE) BswM_MainFunction(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, BswM_CODE) BswM_Read_StdDiag_ComControlModeRequest(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define BswM_STOP_SEC_CODE
# include "BswM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_BSWM_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
