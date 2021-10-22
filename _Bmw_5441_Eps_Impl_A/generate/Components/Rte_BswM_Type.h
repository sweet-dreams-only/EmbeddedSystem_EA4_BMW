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
 *          File:  Rte_BswM_Type.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application types header file for SW-C <BswM>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_BSWM_TYPE_H
# define _RTE_BSWM_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  ifndef CODING_ALLOWED
#   define CODING_ALLOWED (0U)
#  endif

#  ifndef CODING_NOT_ALLOWED
#   define CODING_NOT_ALLOWED (1U)
#  endif

#  ifndef CODING_INITIALIZED
#   define CODING_INITIALIZED (0U)
#  endif

#  ifndef CODING_RUNNING
#   define CODING_RUNNING (1U)
#  endif

#  ifndef CODING_STOPPED
#   define CODING_STOPPED (2U)
#  endif

#  ifndef DARH_INITIALIZED
#   define DARH_INITIALIZED (0U)
#  endif

#  ifndef DARH_RUNNING
#   define DARH_RUNNING (1U)
#  endif

#  ifndef DARH_STOPPED
#   define DARH_STOPPED (2U)
#  endif

#  ifndef DCM_ENABLE_RX_TX_NORM
#   define DCM_ENABLE_RX_TX_NORM (0U)
#  endif

#  ifndef DCM_ENABLE_RX_DISABLE_TX_NORM
#   define DCM_ENABLE_RX_DISABLE_TX_NORM (1U)
#  endif

#  ifndef DCM_DISABLE_RX_ENABLE_TX_NORM
#   define DCM_DISABLE_RX_ENABLE_TX_NORM (2U)
#  endif

#  ifndef DCM_DISABLE_RX_TX_NORMAL
#   define DCM_DISABLE_RX_TX_NORMAL (3U)
#  endif

#  ifndef DCM_ENABLE_RX_TX_NM
#   define DCM_ENABLE_RX_TX_NM (4U)
#  endif

#  ifndef DCM_ENABLE_RX_DISABLE_TX_NM
#   define DCM_ENABLE_RX_DISABLE_TX_NM (5U)
#  endif

#  ifndef DCM_DISABLE_RX_ENABLE_TX_NM
#   define DCM_DISABLE_RX_ENABLE_TX_NM (6U)
#  endif

#  ifndef DCM_DISABLE_RX_TX_NM
#   define DCM_DISABLE_RX_TX_NM (7U)
#  endif

#  ifndef DCM_ENABLE_RX_TX_NORM_NM
#   define DCM_ENABLE_RX_TX_NORM_NM (8U)
#  endif

#  ifndef DCM_ENABLE_RX_DISABLE_TX_NORM_NM
#   define DCM_ENABLE_RX_DISABLE_TX_NORM_NM (9U)
#  endif

#  ifndef DCM_DISABLE_RX_ENABLE_TX_NORM_NM
#   define DCM_DISABLE_RX_ENABLE_TX_NORM_NM (10U)
#  endif

#  ifndef DCM_DISABLE_RX_TX_NORM_NM
#   define DCM_DISABLE_RX_TX_NORM_NM (11U)
#  endif

#  ifndef DCM_ENUM_DEFAULT_SESSION
#   define DCM_ENUM_DEFAULT_SESSION (1U)
#  endif

#  ifndef DCM_ENUM_PROGRAMMING_SESSION
#   define DCM_ENUM_PROGRAMMING_SESSION (2U)
#  endif

#  ifndef DCM_ENUM_EXTENDED_SESSION
#   define DCM_ENUM_EXTENDED_SESSION (3U)
#  endif

#  ifndef DCM_ENUM_CODING_SESSION
#   define DCM_ENUM_CODING_SESSION (65U)
#  endif

#  ifndef DCM_ENUM_RSU_SESSION
#   define DCM_ENUM_RSU_SESSION (68U)
#  endif

#  ifndef DCM_ENUM_DEVELOPMENT_SESSION
#   define DCM_ENUM_DEVELOPMENT_SESSION (79U)
#  endif

#  ifndef DCM_ENUM_GarageMode
#   define DCM_ENUM_GarageMode (95U)
#  endif

#  ifndef DCM_ENUM_SYSTEM_SUPPLIER_SPECIFIC_61
#   define DCM_ENUM_SYSTEM_SUPPLIER_SPECIFIC_61 (97U)
#  endif

#  ifndef DCM_ENUM_DcmDspSessionRow_NXTRMFG
#   define DCM_ENUM_DcmDspSessionRow_NXTRMFG (126U)
#  endif

#  ifndef DCM_ENUM_NONE
#   define DCM_ENUM_NONE (0U)
#  endif

#  ifndef DCM_ENUM_HARD
#   define DCM_ENUM_HARD (1U)
#  endif

#  ifndef DCM_ENUM_KEYONOFF
#   define DCM_ENUM_KEYONOFF (2U)
#  endif

#  ifndef DCM_ENUM_SOFT
#   define DCM_ENUM_SOFT (3U)
#  endif

#  ifndef DCM_ENUM_JUMPTOBOOTLOADER
#   define DCM_ENUM_JUMPTOBOOTLOADER (4U)
#  endif

#  ifndef DCM_ENUM_JUMPTOSYSSUPPLIERBOOTLOADER
#   define DCM_ENUM_JUMPTOSYSSUPPLIERBOOTLOADER (5U)
#  endif

#  ifndef DCM_ENUM_EXECUTE
#   define DCM_ENUM_EXECUTE (6U)
#  endif

#  ifndef DLOG_INITIALIZED
#   define DLOG_INITIALIZED (0U)
#  endif

#  ifndef DLOG_RUNNING
#   define DLOG_RUNNING (1U)
#  endif

#  ifndef DLOG_STOPPED
#   define DLOG_STOPPED (2U)
#  endif

#  ifndef DISABLE_RX_AND_TX_NORMAL
#   define DISABLE_RX_AND_TX_NORMAL (0U)
#  endif

#  ifndef DISABLE_RX_ENABLE_TX_NORMAL
#   define DISABLE_RX_ENABLE_TX_NORMAL (1U)
#  endif

#  ifndef ENABLE_RX_AND_TX_NORMAL
#   define ENABLE_RX_AND_TX_NORMAL (2U)
#  endif

#  ifndef ENABLE_RX_DISABLE_TX_NORMAL
#   define ENABLE_RX_DISABLE_TX_NORMAL (3U)
#  endif

#  ifndef OMC_INITIALIZED
#   define OMC_INITIALIZED (0U)
#  endif

#  ifndef OMC_RUNNING
#   define OMC_RUNNING (1U)
#  endif

#  ifndef OMC_STOPPED
#   define OMC_STOPPED (2U)
#  endif

#  ifndef STDDIAG_INITIALIZED
#   define STDDIAG_INITIALIZED (0U)
#  endif

#  ifndef STDDIAG_RUNNING
#   define STDDIAG_RUNNING (1U)
#  endif

#  ifndef STDDIAG_STOPPED
#   define STDDIAG_STOPPED (2U)
#  endif

#  ifndef STM_CEL_UNLOCKED
#   define STM_CEL_UNLOCKED (0U)
#  endif

#  ifndef STM_CEL_LOCKED
#   define STM_CEL_LOCKED (1U)
#  endif

#  ifndef STM_CEL_INVALID
#   define STM_CEL_INVALID (3U)
#  endif

#  ifndef SYSTIME_INITIALIZED
#   define SYSTIME_INITIALIZED (0U)
#  endif

#  ifndef SYSTIME_RUNNING
#   define SYSTIME_RUNNING (1U)
#  endif

#  ifndef SYSTIME_STOPPED
#   define SYSTIME_STOPPED (2U)
#  endif

#  ifndef VIN_INITIALIZED
#   define VIN_INITIALIZED (0U)
#  endif

#  ifndef VIN_RUNNING
#   define VIN_RUNNING (1U)
#  endif

#  ifndef VIN_STOPPED
#   define VIN_STOPPED (2U)
#  endif

# endif /* RTE_CORE */


/**********************************************************************************************************************
 * Definitions for Mode Management
 *********************************************************************************************************************/
# ifndef RTE_MODETYPE_Coding_BusComMode
#  define RTE_MODETYPE_Coding_BusComMode
typedef uint8 Rte_ModeType_Coding_BusComMode;
# endif
# ifndef RTE_MODETYPE_Coding_ConditionMode
#  define RTE_MODETYPE_Coding_ConditionMode
typedef Coding_ConditionModeType Rte_ModeType_Coding_ConditionMode;
# endif
# ifndef RTE_MODETYPE_Coding_LifeCycle
#  define RTE_MODETYPE_Coding_LifeCycle
typedef Coding_LifeCycleRequestType Rte_ModeType_Coding_LifeCycle;
# endif
# ifndef RTE_MODETYPE_DarhReportErrorMode
#  define RTE_MODETYPE_DarhReportErrorMode
typedef uint8 Rte_ModeType_DarhReportErrorMode;
# endif
# ifndef RTE_MODETYPE_Darh_LifeCycle
#  define RTE_MODETYPE_Darh_LifeCycle
typedef Darh_LifeCycleRequestType Rte_ModeType_Darh_LifeCycle;
# endif
# ifndef RTE_MODETYPE_DcmCommunicationControl
#  define RTE_MODETYPE_DcmCommunicationControl
typedef Dcm_CommunicationModeType Rte_ModeType_DcmCommunicationControl;
# endif
# ifndef RTE_MODETYPE_DcmDiagnosticSessionControl
#  define RTE_MODETYPE_DcmDiagnosticSessionControl
typedef Dcm_DiagnosticSessionControlType Rte_ModeType_DcmDiagnosticSessionControl;
# endif
# ifndef RTE_MODETYPE_DcmEcuReset
#  define RTE_MODETYPE_DcmEcuReset
typedef Dcm_EcuResetType Rte_ModeType_DcmEcuReset;
# endif
# ifndef RTE_MODETYPE_Dlog_LifeCycle
#  define RTE_MODETYPE_Dlog_LifeCycle
typedef Dlog_LifeCycleRequestType Rte_ModeType_Dlog_LifeCycle;
# endif
# ifndef RTE_MODETYPE_ErrorMemoryLockSignalReceptionMode
#  define RTE_MODETYPE_ErrorMemoryLockSignalReceptionMode
typedef uint8 Rte_ModeType_ErrorMemoryLockSignalReceptionMode;
# endif
# ifndef RTE_MODETYPE_Omc_LifeCycle
#  define RTE_MODETYPE_Omc_LifeCycle
typedef Omc_LifeCycleRequestType Rte_ModeType_Omc_LifeCycle;
# endif
# ifndef RTE_MODETYPE_StdDiag_LifeCycle
#  define RTE_MODETYPE_StdDiag_LifeCycle
typedef StdDiag_LifeCycleRequestType Rte_ModeType_StdDiag_LifeCycle;
# endif
# ifndef RTE_MODETYPE_StdDiag_NormalCommunicationModeGroup
#  define RTE_MODETYPE_StdDiag_NormalCommunicationModeGroup
typedef NormalCommunicationModeType Rte_ModeType_StdDiag_NormalCommunicationModeGroup;
# endif
# ifndef RTE_MODETYPE_StdDiag_SessionModeGroup
#  define RTE_MODETYPE_StdDiag_SessionModeGroup
typedef uint8 Rte_ModeType_StdDiag_SessionModeGroup;
# endif
# ifndef RTE_MODETYPE_Stm_CentralErrorLockMode
#  define RTE_MODETYPE_Stm_CentralErrorLockMode
typedef Stm_CentralErrorLockType Rte_ModeType_Stm_CentralErrorLockMode;
# endif
# ifndef RTE_MODETYPE_SysTime_LifeCycle
#  define RTE_MODETYPE_SysTime_LifeCycle
typedef SysTime_LifeCycleRequestType Rte_ModeType_SysTime_LifeCycle;
# endif
# ifndef RTE_MODETYPE_Vin_LifeCycle
#  define RTE_MODETYPE_Vin_LifeCycle
typedef Vin_LifeCycleRequestType Rte_ModeType_Vin_LifeCycle;
# endif
# ifndef RTE_MODETYPE_Vin_VinComMode
#  define RTE_MODETYPE_Vin_VinComMode
typedef uint8 Rte_ModeType_Vin_VinComMode;
# endif

# ifndef RTE_MODE_Coding_BusComMode_CODING_BUSCOMOFF
#  define RTE_MODE_Coding_BusComMode_CODING_BUSCOMOFF (0U)
# endif
# ifndef RTE_MODE_Coding_BusComMode_CODING_BUSCOMON
#  define RTE_MODE_Coding_BusComMode_CODING_BUSCOMON (1U)
# endif
# ifndef RTE_TRANSITION_Coding_BusComMode
#  define RTE_TRANSITION_Coding_BusComMode (2U)
# endif

# ifndef RTE_MODE_Coding_ConditionMode_CODING_ALLOWED
#  define RTE_MODE_Coding_ConditionMode_CODING_ALLOWED (0U)
# endif
# ifndef RTE_MODE_Coding_ConditionMode_CODING_NOT_ALLOWED
#  define RTE_MODE_Coding_ConditionMode_CODING_NOT_ALLOWED (1U)
# endif
# ifndef RTE_TRANSITION_Coding_ConditionMode
#  define RTE_TRANSITION_Coding_ConditionMode (2U)
# endif

# ifndef RTE_MODE_Coding_LifeCycle_CODING_INITIALIZED
#  define RTE_MODE_Coding_LifeCycle_CODING_INITIALIZED (0U)
# endif
# ifndef RTE_MODE_Coding_LifeCycle_CODING_RUNNING
#  define RTE_MODE_Coding_LifeCycle_CODING_RUNNING (1U)
# endif
# ifndef RTE_MODE_Coding_LifeCycle_CODING_STOPPED
#  define RTE_MODE_Coding_LifeCycle_CODING_STOPPED (2U)
# endif
# ifndef RTE_TRANSITION_Coding_LifeCycle
#  define RTE_TRANSITION_Coding_LifeCycle (3U)
# endif

# ifndef RTE_MODE_DarhReportErrorMode_DARH_REPORT_ERROR_ACTIVE
#  define RTE_MODE_DarhReportErrorMode_DARH_REPORT_ERROR_ACTIVE (0U)
# endif
# ifndef RTE_MODE_DarhReportErrorMode_DARH_REPORT_ERROR_INACTIVE
#  define RTE_MODE_DarhReportErrorMode_DARH_REPORT_ERROR_INACTIVE (1U)
# endif
# ifndef RTE_TRANSITION_DarhReportErrorMode
#  define RTE_TRANSITION_DarhReportErrorMode (2U)
# endif

# ifndef RTE_MODE_Darh_LifeCycle_DARH_INITIALIZED
#  define RTE_MODE_Darh_LifeCycle_DARH_INITIALIZED (0U)
# endif
# ifndef RTE_MODE_Darh_LifeCycle_DARH_RUNNING
#  define RTE_MODE_Darh_LifeCycle_DARH_RUNNING (1U)
# endif
# ifndef RTE_MODE_Darh_LifeCycle_DARH_STOPPED
#  define RTE_MODE_Darh_LifeCycle_DARH_STOPPED (2U)
# endif
# ifndef RTE_TRANSITION_Darh_LifeCycle
#  define RTE_TRANSITION_Darh_LifeCycle (3U)
# endif

# ifndef RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_TX_NORM
#  define RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_TX_NORM (0U)
# endif
# ifndef RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_DISABLE_TX_NORM
#  define RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_DISABLE_TX_NORM (1U)
# endif
# ifndef RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_ENABLE_TX_NORM
#  define RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_ENABLE_TX_NORM (2U)
# endif
# ifndef RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_TX_NORMAL
#  define RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_TX_NORMAL (3U)
# endif
# ifndef RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_TX_NM
#  define RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_TX_NM (4U)
# endif
# ifndef RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_DISABLE_TX_NM
#  define RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_DISABLE_TX_NM (5U)
# endif
# ifndef RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_ENABLE_TX_NM
#  define RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_ENABLE_TX_NM (6U)
# endif
# ifndef RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_TX_NM
#  define RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_TX_NM (7U)
# endif
# ifndef RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_TX_NORM_NM
#  define RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_TX_NORM_NM (8U)
# endif
# ifndef RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_DISABLE_TX_NORM_NM
#  define RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_DISABLE_TX_NORM_NM (9U)
# endif
# ifndef RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_ENABLE_TX_NORM_NM
#  define RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_ENABLE_TX_NORM_NM (10U)
# endif
# ifndef RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_TX_NORM_NM
#  define RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_TX_NORM_NM (11U)
# endif
# ifndef RTE_TRANSITION_DcmCommunicationControl
#  define RTE_TRANSITION_DcmCommunicationControl (12U)
# endif

# ifndef RTE_MODE_DcmDiagnosticSessionControl_DEFAULT_SESSION
#  define RTE_MODE_DcmDiagnosticSessionControl_DEFAULT_SESSION (1U)
# endif
# ifndef RTE_MODE_DcmDiagnosticSessionControl_PROGRAMMING_SESSION
#  define RTE_MODE_DcmDiagnosticSessionControl_PROGRAMMING_SESSION (2U)
# endif
# ifndef RTE_MODE_DcmDiagnosticSessionControl_EXTENDED_SESSION
#  define RTE_MODE_DcmDiagnosticSessionControl_EXTENDED_SESSION (3U)
# endif
# ifndef RTE_MODE_DcmDiagnosticSessionControl_CODING_SESSION
#  define RTE_MODE_DcmDiagnosticSessionControl_CODING_SESSION (65U)
# endif
# ifndef RTE_MODE_DcmDiagnosticSessionControl_RSU_SESSION
#  define RTE_MODE_DcmDiagnosticSessionControl_RSU_SESSION (68U)
# endif
# ifndef RTE_MODE_DcmDiagnosticSessionControl_DEVELOPMENT_SESSION
#  define RTE_MODE_DcmDiagnosticSessionControl_DEVELOPMENT_SESSION (79U)
# endif
# ifndef RTE_MODE_DcmDiagnosticSessionControl_GarageMode
#  define RTE_MODE_DcmDiagnosticSessionControl_GarageMode (95U)
# endif
# ifndef RTE_MODE_DcmDiagnosticSessionControl_SYSTEM_SUPPLIER_SPECIFIC_61
#  define RTE_MODE_DcmDiagnosticSessionControl_SYSTEM_SUPPLIER_SPECIFIC_61 (97U)
# endif
# ifndef RTE_MODE_DcmDiagnosticSessionControl_DcmDspSessionRow_NXTRMFG
#  define RTE_MODE_DcmDiagnosticSessionControl_DcmDspSessionRow_NXTRMFG (126U)
# endif
# ifndef RTE_TRANSITION_DcmDiagnosticSessionControl
#  define RTE_TRANSITION_DcmDiagnosticSessionControl (255U)
# endif

# ifndef RTE_MODE_DcmEcuReset_NONE
#  define RTE_MODE_DcmEcuReset_NONE (0U)
# endif
# ifndef RTE_MODE_DcmEcuReset_HARD
#  define RTE_MODE_DcmEcuReset_HARD (1U)
# endif
# ifndef RTE_MODE_DcmEcuReset_KEYONOFF
#  define RTE_MODE_DcmEcuReset_KEYONOFF (2U)
# endif
# ifndef RTE_MODE_DcmEcuReset_SOFT
#  define RTE_MODE_DcmEcuReset_SOFT (3U)
# endif
# ifndef RTE_MODE_DcmEcuReset_JUMPTOBOOTLOADER
#  define RTE_MODE_DcmEcuReset_JUMPTOBOOTLOADER (4U)
# endif
# ifndef RTE_MODE_DcmEcuReset_JUMPTOSYSSUPPLIERBOOTLOADER
#  define RTE_MODE_DcmEcuReset_JUMPTOSYSSUPPLIERBOOTLOADER (5U)
# endif
# ifndef RTE_MODE_DcmEcuReset_EXECUTE
#  define RTE_MODE_DcmEcuReset_EXECUTE (6U)
# endif
# ifndef RTE_TRANSITION_DcmEcuReset
#  define RTE_TRANSITION_DcmEcuReset (7U)
# endif

# ifndef RTE_MODE_Dlog_LifeCycle_DLOG_INITIALIZED
#  define RTE_MODE_Dlog_LifeCycle_DLOG_INITIALIZED (0U)
# endif
# ifndef RTE_MODE_Dlog_LifeCycle_DLOG_RUNNING
#  define RTE_MODE_Dlog_LifeCycle_DLOG_RUNNING (1U)
# endif
# ifndef RTE_MODE_Dlog_LifeCycle_DLOG_STOPPED
#  define RTE_MODE_Dlog_LifeCycle_DLOG_STOPPED (2U)
# endif
# ifndef RTE_TRANSITION_Dlog_LifeCycle
#  define RTE_TRANSITION_Dlog_LifeCycle (3U)
# endif

# ifndef RTE_MODE_ErrorMemoryLockSignalReceptionMode_EM_LOCK_NOT_RECEIVABLE
#  define RTE_MODE_ErrorMemoryLockSignalReceptionMode_EM_LOCK_NOT_RECEIVABLE (0U)
# endif
# ifndef RTE_MODE_ErrorMemoryLockSignalReceptionMode_EM_LOCK_RECEIVABLE
#  define RTE_MODE_ErrorMemoryLockSignalReceptionMode_EM_LOCK_RECEIVABLE (1U)
# endif
# ifndef RTE_TRANSITION_ErrorMemoryLockSignalReceptionMode
#  define RTE_TRANSITION_ErrorMemoryLockSignalReceptionMode (2U)
# endif

# ifndef RTE_MODE_Omc_LifeCycle_OMC_INITIALIZED
#  define RTE_MODE_Omc_LifeCycle_OMC_INITIALIZED (0U)
# endif
# ifndef RTE_MODE_Omc_LifeCycle_OMC_RUNNING
#  define RTE_MODE_Omc_LifeCycle_OMC_RUNNING (1U)
# endif
# ifndef RTE_MODE_Omc_LifeCycle_OMC_STOPPED
#  define RTE_MODE_Omc_LifeCycle_OMC_STOPPED (2U)
# endif
# ifndef RTE_TRANSITION_Omc_LifeCycle
#  define RTE_TRANSITION_Omc_LifeCycle (3U)
# endif

# ifndef RTE_MODE_StdDiag_LifeCycle_STDDIAG_INITIALIZED
#  define RTE_MODE_StdDiag_LifeCycle_STDDIAG_INITIALIZED (0U)
# endif
# ifndef RTE_MODE_StdDiag_LifeCycle_STDDIAG_RUNNING
#  define RTE_MODE_StdDiag_LifeCycle_STDDIAG_RUNNING (1U)
# endif
# ifndef RTE_MODE_StdDiag_LifeCycle_STDDIAG_STOPPED
#  define RTE_MODE_StdDiag_LifeCycle_STDDIAG_STOPPED (2U)
# endif
# ifndef RTE_TRANSITION_StdDiag_LifeCycle
#  define RTE_TRANSITION_StdDiag_LifeCycle (3U)
# endif

# ifndef RTE_MODE_StdDiag_NormalCommunicationModeGroup_DISABLE_RX_AND_TX_NORMAL
#  define RTE_MODE_StdDiag_NormalCommunicationModeGroup_DISABLE_RX_AND_TX_NORMAL (0U)
# endif
# ifndef RTE_MODE_StdDiag_NormalCommunicationModeGroup_DISABLE_RX_ENABLE_TX_NORMAL
#  define RTE_MODE_StdDiag_NormalCommunicationModeGroup_DISABLE_RX_ENABLE_TX_NORMAL (1U)
# endif
# ifndef RTE_MODE_StdDiag_NormalCommunicationModeGroup_ENABLE_RX_AND_TX_NORMAL
#  define RTE_MODE_StdDiag_NormalCommunicationModeGroup_ENABLE_RX_AND_TX_NORMAL (2U)
# endif
# ifndef RTE_MODE_StdDiag_NormalCommunicationModeGroup_ENABLE_RX_DISABLE_TX_NORMAL
#  define RTE_MODE_StdDiag_NormalCommunicationModeGroup_ENABLE_RX_DISABLE_TX_NORMAL (3U)
# endif
# ifndef RTE_TRANSITION_StdDiag_NormalCommunicationModeGroup
#  define RTE_TRANSITION_StdDiag_NormalCommunicationModeGroup (4U)
# endif

# ifndef RTE_MODE_StdDiag_SessionModeGroup_STDDIAG_DEFAULT_SESSION
#  define RTE_MODE_StdDiag_SessionModeGroup_STDDIAG_DEFAULT_SESSION (0U)
# endif
# ifndef RTE_MODE_StdDiag_SessionModeGroup_STDDIAG_OTHER_SESSION
#  define RTE_MODE_StdDiag_SessionModeGroup_STDDIAG_OTHER_SESSION (1U)
# endif
# ifndef RTE_TRANSITION_StdDiag_SessionModeGroup
#  define RTE_TRANSITION_StdDiag_SessionModeGroup (2U)
# endif

# ifndef RTE_MODE_Stm_CentralErrorLockMode_STM_CEL_INVALID
#  define RTE_MODE_Stm_CentralErrorLockMode_STM_CEL_INVALID (0U)
# endif
# ifndef RTE_MODE_Stm_CentralErrorLockMode_STM_CEL_LOCKED
#  define RTE_MODE_Stm_CentralErrorLockMode_STM_CEL_LOCKED (1U)
# endif
# ifndef RTE_MODE_Stm_CentralErrorLockMode_STM_CEL_UNLOCKED
#  define RTE_MODE_Stm_CentralErrorLockMode_STM_CEL_UNLOCKED (2U)
# endif
# ifndef RTE_TRANSITION_Stm_CentralErrorLockMode
#  define RTE_TRANSITION_Stm_CentralErrorLockMode (3U)
# endif

# ifndef RTE_MODE_SysTime_LifeCycle_SYSTIME_INITIALIZED
#  define RTE_MODE_SysTime_LifeCycle_SYSTIME_INITIALIZED (0U)
# endif
# ifndef RTE_MODE_SysTime_LifeCycle_SYSTIME_RUNNING
#  define RTE_MODE_SysTime_LifeCycle_SYSTIME_RUNNING (1U)
# endif
# ifndef RTE_MODE_SysTime_LifeCycle_SYSTIME_STOPPED
#  define RTE_MODE_SysTime_LifeCycle_SYSTIME_STOPPED (2U)
# endif
# ifndef RTE_TRANSITION_SysTime_LifeCycle
#  define RTE_TRANSITION_SysTime_LifeCycle (3U)
# endif

# ifndef RTE_MODE_Vin_LifeCycle_VIN_INITIALIZED
#  define RTE_MODE_Vin_LifeCycle_VIN_INITIALIZED (0U)
# endif
# ifndef RTE_MODE_Vin_LifeCycle_VIN_RUNNING
#  define RTE_MODE_Vin_LifeCycle_VIN_RUNNING (1U)
# endif
# ifndef RTE_MODE_Vin_LifeCycle_VIN_STOPPED
#  define RTE_MODE_Vin_LifeCycle_VIN_STOPPED (2U)
# endif
# ifndef RTE_TRANSITION_Vin_LifeCycle
#  define RTE_TRANSITION_Vin_LifeCycle (3U)
# endif

# ifndef RTE_MODE_Vin_VinComMode_VIN_VINCOMON
#  define RTE_MODE_Vin_VinComMode_VIN_VINCOMON (0U)
# endif
# ifndef RTE_MODE_Vin_VinComMode_VIN_VINCOMOFF
#  define RTE_MODE_Vin_VinComMode_VIN_VINCOMOFF (1U)
# endif
# ifndef RTE_TRANSITION_Vin_VinComMode
#  define RTE_TRANSITION_Vin_VinComMode (2U)
# endif

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_BSWM_TYPE_H */
