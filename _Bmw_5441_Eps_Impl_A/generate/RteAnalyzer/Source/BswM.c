/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  BswM.c
 *        Config:  EPS.dpa
 *     SW-C Type:  BswM
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <BswM>
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

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************
 *
 * Data Types:
 * ===========
 * Coding_ConditionModeType
 *   
 *
 * Coding_LifeCycleRequestType
 *   
 *
 * Darh_LifeCycleRequestType
 *   
 *
 * Dcm_CommunicationModeType
 *   
 *
 * Dcm_DiagnosticSessionControlType
 *   
 *
 * Dcm_EcuResetType
 *   
 *
 * Dlog_LifeCycleRequestType
 *   
 *
 * NormalCommunicationModeType
 *   
 *
 * Omc_LifeCycleRequestType
 *   
 *
 * StdDiag_LifeCycleRequestType
 *   
 *
 * Stm_CentralErrorLockType
 *   
 *
 * SysTime_LifeCycleRequestType
 *   
 *
 * Vin_LifeCycleRequestType
 *   
 *
 *********************************************************************************************************************/

#include "Rte_BswM.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_BswM.h"
#include "SchM_BswM.h"
#include "TSC_SchM_BswM.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"

static void BswM_TestDefines(void);

typedef P2FUNC(Std_ReturnType, RTE_CODE, FncPtrType)(void); /* PRQA S 3448 */ /* MD_Rte_TestCode */


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
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * Coding_ConditionModeType: Enumeration of integer in interval [0...255] with enumerators
 *   CODING_ALLOWED (0U)
 *   CODING_NOT_ALLOWED (1U)
 * Coding_LifeCycleRequestType: Enumeration of integer in interval [0...255] with enumerators
 *   CODING_INITIALIZED (0U)
 *   CODING_RUNNING (1U)
 *   CODING_STOPPED (2U)
 * Darh_LifeCycleRequestType: Enumeration of integer in interval [0...255] with enumerators
 *   DARH_INITIALIZED (0U)
 *   DARH_RUNNING (1U)
 *   DARH_STOPPED (2U)
 * Dcm_CommunicationModeType: Enumeration of integer in interval [0...255] with enumerators
 *   DCM_ENABLE_RX_TX_NORM (0U)
 *   DCM_ENABLE_RX_DISABLE_TX_NORM (1U)
 *   DCM_DISABLE_RX_ENABLE_TX_NORM (2U)
 *   DCM_DISABLE_RX_TX_NORMAL (3U)
 *   DCM_ENABLE_RX_TX_NM (4U)
 *   DCM_ENABLE_RX_DISABLE_TX_NM (5U)
 *   DCM_DISABLE_RX_ENABLE_TX_NM (6U)
 *   DCM_DISABLE_RX_TX_NM (7U)
 *   DCM_ENABLE_RX_TX_NORM_NM (8U)
 *   DCM_ENABLE_RX_DISABLE_TX_NORM_NM (9U)
 *   DCM_DISABLE_RX_ENABLE_TX_NORM_NM (10U)
 *   DCM_DISABLE_RX_TX_NORM_NM (11U)
 * Dcm_DiagnosticSessionControlType: Enumeration of integer in interval [0...255] with enumerators
 *   DCM_ENUM_DEFAULT_SESSION (1U)
 *   DCM_ENUM_PROGRAMMING_SESSION (2U)
 *   DCM_ENUM_EXTENDED_SESSION (3U)
 *   DCM_ENUM_CODING_SESSION (65U)
 *   DCM_ENUM_RSU_SESSION (68U)
 *   DCM_ENUM_DEVELOPMENT_SESSION (79U)
 *   DCM_ENUM_GarageMode (95U)
 *   DCM_ENUM_SYSTEM_SUPPLIER_SPECIFIC_61 (97U)
 *   DCM_ENUM_DcmDspSessionRow_NXTRMFG (126U)
 * Dcm_EcuResetType: Enumeration of integer in interval [0...255] with enumerators
 *   DCM_ENUM_NONE (0U)
 *   DCM_ENUM_HARD (1U)
 *   DCM_ENUM_KEYONOFF (2U)
 *   DCM_ENUM_SOFT (3U)
 *   DCM_ENUM_JUMPTOBOOTLOADER (4U)
 *   DCM_ENUM_JUMPTOSYSSUPPLIERBOOTLOADER (5U)
 *   DCM_ENUM_EXECUTE (6U)
 * Dlog_LifeCycleRequestType: Enumeration of integer in interval [0...255] with enumerators
 *   DLOG_INITIALIZED (0U)
 *   DLOG_RUNNING (1U)
 *   DLOG_STOPPED (2U)
 * NormalCommunicationModeType: Enumeration of integer in interval [0...255] with enumerators
 *   DISABLE_RX_AND_TX_NORMAL (0U)
 *   DISABLE_RX_ENABLE_TX_NORMAL (1U)
 *   ENABLE_RX_AND_TX_NORMAL (2U)
 *   ENABLE_RX_DISABLE_TX_NORMAL (3U)
 * Omc_LifeCycleRequestType: Enumeration of integer in interval [0...255] with enumerators
 *   OMC_INITIALIZED (0U)
 *   OMC_RUNNING (1U)
 *   OMC_STOPPED (2U)
 * StdDiag_LifeCycleRequestType: Enumeration of integer in interval [0...255] with enumerators
 *   STDDIAG_INITIALIZED (0U)
 *   STDDIAG_RUNNING (1U)
 *   STDDIAG_STOPPED (2U)
 * Stm_CentralErrorLockType: Enumeration of integer in interval [0...255] with enumerators
 *   STM_CEL_UNLOCKED (0U)
 *   STM_CEL_LOCKED (1U)
 *   STM_CEL_INVALID (3U)
 * SysTime_LifeCycleRequestType: Enumeration of integer in interval [0...255] with enumerators
 *   SYSTIME_INITIALIZED (0U)
 *   SYSTIME_RUNNING (1U)
 *   SYSTIME_STOPPED (2U)
 * Vin_LifeCycleRequestType: Enumeration of integer in interval [0...255] with enumerators
 *   VIN_INITIALIZED (0U)
 *   VIN_RUNNING (1U)
 *   VIN_STOPPED (2U)
 *
 *********************************************************************************************************************/


#define BswM_START_SEC_CODE
#include "BswM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BswM_MainFunction
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_Provide_MSRP_Coding_requestMode(Coding_LifeCycleRequestType data)
 *   Std_ReturnType Rte_Write_Provide_MSRP_Darh_requestMode(Darh_LifeCycleRequestType data)
 *   Std_ReturnType Rte_Write_Provide_MSRP_Dlog_requestMode(Dlog_LifeCycleRequestType data)
 *   Std_ReturnType Rte_Write_Provide_MSRP_Omc_requestMode(Omc_LifeCycleRequestType data)
 *   Std_ReturnType Rte_Write_Provide_MSRP_StdDiag_requestMode(StdDiag_LifeCycleRequestType data)
 *   Std_ReturnType Rte_Write_Provide_MSRP_SysTime_requestMode(SysTime_LifeCycleRequestType data)
 *   Std_ReturnType Rte_Write_Provide_MSRP_Vin_requestMode(Vin_LifeCycleRequestType data)
 *
 * Mode Interfaces:
 * ================
 *   Std_ReturnType Rte_Switch_Switch_Coding_BusComModeSwitch_Mode(uint8 mode)
 *   Modes of Rte_ModeType_Coding_BusComMode:
 *   - RTE_MODE_Coding_BusComMode_CODING_BUSCOMOFF
 *   - RTE_MODE_Coding_BusComMode_CODING_BUSCOMON
 *   - RTE_TRANSITION_Coding_BusComMode
 *   Std_ReturnType Rte_Switch_Switch_Coding_SwitchCodingMode_currentConditionMode(Coding_ConditionModeType mode)
 *   Modes of Rte_ModeType_Coding_ConditionMode:
 *   - RTE_MODE_Coding_ConditionMode_CODING_ALLOWED
 *   - RTE_MODE_Coding_ConditionMode_CODING_NOT_ALLOWED
 *   - RTE_TRANSITION_Coding_ConditionMode
 *   Std_ReturnType Rte_Switch_Switch_ErrorMemoryLockSignalReceptionSwitchPort_currentEMLockSignalReceptionMode(uint8 mode)
 *   Modes of Rte_ModeType_ErrorMemoryLockSignalReceptionMode:
 *   - RTE_MODE_ErrorMemoryLockSignalReceptionMode_EM_LOCK_NOT_RECEIVABLE
 *   - RTE_MODE_ErrorMemoryLockSignalReceptionMode_EM_LOCK_RECEIVABLE
 *   - RTE_TRANSITION_ErrorMemoryLockSignalReceptionMode
 *   Std_ReturnType Rte_Switch_Switch_StdDiagComControlNormalNotificationPort_CommunicationModeDeclarationGroup(NormalCommunicationModeType mode)
 *   Modes of Rte_ModeType_StdDiag_NormalCommunicationModeGroup:
 *   - RTE_MODE_StdDiag_NormalCommunicationModeGroup_DISABLE_RX_AND_TX_NORMAL
 *   - RTE_MODE_StdDiag_NormalCommunicationModeGroup_DISABLE_RX_ENABLE_TX_NORMAL
 *   - RTE_MODE_StdDiag_NormalCommunicationModeGroup_ENABLE_RX_AND_TX_NORMAL
 *   - RTE_MODE_StdDiag_NormalCommunicationModeGroup_ENABLE_RX_DISABLE_TX_NORMAL
 *   - RTE_TRANSITION_StdDiag_NormalCommunicationModeGroup
 *   Std_ReturnType Rte_Switch_Switch_StdDiagSessionChangeIndicationPort_SessionModeDeclarationGroup(uint8 mode)
 *   Modes of Rte_ModeType_StdDiag_SessionModeGroup:
 *   - RTE_MODE_StdDiag_SessionModeGroup_STDDIAG_DEFAULT_SESSION
 *   - RTE_MODE_StdDiag_SessionModeGroup_STDDIAG_OTHER_SESSION
 *   - RTE_TRANSITION_StdDiag_SessionModeGroup
 *   Std_ReturnType Rte_Switch_Switch_SwitchPort_Darh_ReportErrorMode_DarhReportErrorMode(uint8 mode)
 *   Modes of Rte_ModeType_DarhReportErrorMode:
 *   - RTE_MODE_DarhReportErrorMode_DARH_REPORT_ERROR_ACTIVE
 *   - RTE_MODE_DarhReportErrorMode_DARH_REPORT_ERROR_INACTIVE
 *   - RTE_TRANSITION_DarhReportErrorMode
 *   Std_ReturnType Rte_Switch_Switch_VinComSwitchPort_Mode(uint8 mode)
 *   Modes of Rte_ModeType_Vin_VinComMode:
 *   - RTE_MODE_Vin_VinComMode_VIN_VINCOMOFF
 *   - RTE_MODE_Vin_VinComMode_VIN_VINCOMON
 *   - RTE_TRANSITION_Vin_VinComMode
 *   Stm_CentralErrorLockType Rte_Mode_Notification_SWCModeSwitch_currentCentralErrorLockMode_currentCentralErrorLockMode(void)
 *   Modes of Rte_ModeType_Stm_CentralErrorLockMode:
 *   - RTE_MODE_Stm_CentralErrorLockMode_STM_CEL_INVALID
 *   - RTE_MODE_Stm_CentralErrorLockMode_STM_CEL_LOCKED
 *   - RTE_MODE_Stm_CentralErrorLockMode_STM_CEL_UNLOCKED
 *   - RTE_TRANSITION_Stm_CentralErrorLockMode
 *   Coding_LifeCycleRequestType Rte_Mode_Notification_SwcModeNotification_Coding_LifeCycle_Mode(void)
 *   Modes of Rte_ModeType_Coding_LifeCycle:
 *   - RTE_MODE_Coding_LifeCycle_CODING_INITIALIZED
 *   - RTE_MODE_Coding_LifeCycle_CODING_RUNNING
 *   - RTE_MODE_Coding_LifeCycle_CODING_STOPPED
 *   - RTE_TRANSITION_Coding_LifeCycle
 *   Darh_LifeCycleRequestType Rte_Mode_Notification_SwcModeNotification_Darh_LifeCycle_Mode(void)
 *   Modes of Rte_ModeType_Darh_LifeCycle:
 *   - RTE_MODE_Darh_LifeCycle_DARH_INITIALIZED
 *   - RTE_MODE_Darh_LifeCycle_DARH_RUNNING
 *   - RTE_MODE_Darh_LifeCycle_DARH_STOPPED
 *   - RTE_TRANSITION_Darh_LifeCycle
 *   Dcm_CommunicationModeType Rte_Mode_Notification_SwcModeNotification_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6(void)
 *   Modes of Rte_ModeType_DcmCommunicationControl:
 *   - RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_ENABLE_TX_NM
 *   - RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_ENABLE_TX_NORM
 *   - RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_ENABLE_TX_NORM_NM
 *   - RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_TX_NM
 *   - RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_TX_NORMAL
 *   - RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_TX_NORM_NM
 *   - RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_DISABLE_TX_NM
 *   - RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_DISABLE_TX_NORM
 *   - RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_DISABLE_TX_NORM_NM
 *   - RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_TX_NM
 *   - RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_TX_NORM
 *   - RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_TX_NORM_NM
 *   - RTE_TRANSITION_DcmCommunicationControl
 *   Dcm_DiagnosticSessionControlType Rte_Mode_Notification_SwcModeNotification_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl(void)
 *   Modes of Rte_ModeType_DcmDiagnosticSessionControl:
 *   - RTE_MODE_DcmDiagnosticSessionControl_CODING_SESSION
 *   - RTE_MODE_DcmDiagnosticSessionControl_DEFAULT_SESSION
 *   - RTE_MODE_DcmDiagnosticSessionControl_DEVELOPMENT_SESSION
 *   - RTE_MODE_DcmDiagnosticSessionControl_DcmDspSessionRow_NXTRMFG
 *   - RTE_MODE_DcmDiagnosticSessionControl_EXTENDED_SESSION
 *   - RTE_MODE_DcmDiagnosticSessionControl_GarageMode
 *   - RTE_MODE_DcmDiagnosticSessionControl_PROGRAMMING_SESSION
 *   - RTE_MODE_DcmDiagnosticSessionControl_RSU_SESSION
 *   - RTE_MODE_DcmDiagnosticSessionControl_SYSTEM_SUPPLIER_SPECIFIC_61
 *   - RTE_TRANSITION_DcmDiagnosticSessionControl
 *   Dcm_EcuResetType Rte_Mode_Notification_SwcModeNotification_DcmEcuReset_DcmEcuReset(void)
 *   Modes of Rte_ModeType_DcmEcuReset:
 *   - RTE_MODE_DcmEcuReset_EXECUTE
 *   - RTE_MODE_DcmEcuReset_HARD
 *   - RTE_MODE_DcmEcuReset_JUMPTOBOOTLOADER
 *   - RTE_MODE_DcmEcuReset_JUMPTOSYSSUPPLIERBOOTLOADER
 *   - RTE_MODE_DcmEcuReset_KEYONOFF
 *   - RTE_MODE_DcmEcuReset_NONE
 *   - RTE_MODE_DcmEcuReset_SOFT
 *   - RTE_TRANSITION_DcmEcuReset
 *   Dlog_LifeCycleRequestType Rte_Mode_Notification_SwcModeNotification_Dlog_LifeCycle_Mode(void)
 *   Modes of Rte_ModeType_Dlog_LifeCycle:
 *   - RTE_MODE_Dlog_LifeCycle_DLOG_INITIALIZED
 *   - RTE_MODE_Dlog_LifeCycle_DLOG_RUNNING
 *   - RTE_MODE_Dlog_LifeCycle_DLOG_STOPPED
 *   - RTE_TRANSITION_Dlog_LifeCycle
 *   Omc_LifeCycleRequestType Rte_Mode_Notification_SwcModeNotification_Omc_LifeCycle_Mode(void)
 *   Modes of Rte_ModeType_Omc_LifeCycle:
 *   - RTE_MODE_Omc_LifeCycle_OMC_INITIALIZED
 *   - RTE_MODE_Omc_LifeCycle_OMC_RUNNING
 *   - RTE_MODE_Omc_LifeCycle_OMC_STOPPED
 *   - RTE_TRANSITION_Omc_LifeCycle
 *   StdDiag_LifeCycleRequestType Rte_Mode_Notification_SwcModeNotification_StdDiag_LifeCycle_Mode(void)
 *   Modes of Rte_ModeType_StdDiag_LifeCycle:
 *   - RTE_MODE_StdDiag_LifeCycle_STDDIAG_INITIALIZED
 *   - RTE_MODE_StdDiag_LifeCycle_STDDIAG_RUNNING
 *   - RTE_MODE_StdDiag_LifeCycle_STDDIAG_STOPPED
 *   - RTE_TRANSITION_StdDiag_LifeCycle
 *   SysTime_LifeCycleRequestType Rte_Mode_Notification_SwcModeNotification_SysTime_LifeCycle_Mode(void)
 *   Modes of Rte_ModeType_SysTime_LifeCycle:
 *   - RTE_MODE_SysTime_LifeCycle_SYSTIME_INITIALIZED
 *   - RTE_MODE_SysTime_LifeCycle_SYSTIME_RUNNING
 *   - RTE_MODE_SysTime_LifeCycle_SYSTIME_STOPPED
 *   - RTE_TRANSITION_SysTime_LifeCycle
 *   Vin_LifeCycleRequestType Rte_Mode_Notification_SwcModeNotification_Vin_LifeCycle_Mode(void)
 *   Modes of Rte_ModeType_Vin_LifeCycle:
 *   - RTE_MODE_Vin_LifeCycle_VIN_INITIALIZED
 *   - RTE_MODE_Vin_LifeCycle_VIN_RUNNING
 *   - RTE_MODE_Vin_LifeCycle_VIN_STOPPED
 *   - RTE_TRANSITION_Vin_LifeCycle
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BswM_MainFunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BswM_CODE) BswM_MainFunction(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BswM_MainFunction
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  Coding_LifeCycleRequestType Write_Provide_MSRP_Coding_requestMode;
  Darh_LifeCycleRequestType Write_Provide_MSRP_Darh_requestMode;
  Dlog_LifeCycleRequestType Write_Provide_MSRP_Dlog_requestMode;
  Omc_LifeCycleRequestType Write_Provide_MSRP_Omc_requestMode;
  SysTime_LifeCycleRequestType Write_Provide_MSRP_SysTime_requestMode;

  Rte_ModeType_Stm_CentralErrorLockMode Notification_SWCModeSwitch_currentCentralErrorLockMode_currentCentralErrorLockMode;
  Rte_ModeType_Coding_LifeCycle Notification_SwcModeNotification_Coding_LifeCycle_Mode;
  Rte_ModeType_Darh_LifeCycle Notification_SwcModeNotification_Darh_LifeCycle_Mode;
  Rte_ModeType_DcmCommunicationControl Notification_SwcModeNotification_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6;
  Rte_ModeType_DcmDiagnosticSessionControl Notification_SwcModeNotification_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl;
  Rte_ModeType_DcmEcuReset Notification_SwcModeNotification_DcmEcuReset_DcmEcuReset;
  Rte_ModeType_Dlog_LifeCycle Notification_SwcModeNotification_Dlog_LifeCycle_Mode;
  Rte_ModeType_Omc_LifeCycle Notification_SwcModeNotification_Omc_LifeCycle_Mode;
  Rte_ModeType_StdDiag_LifeCycle Notification_SwcModeNotification_StdDiag_LifeCycle_Mode;
  Rte_ModeType_SysTime_LifeCycle Notification_SwcModeNotification_SysTime_LifeCycle_Mode;
  Rte_ModeType_Vin_LifeCycle Notification_SwcModeNotification_Vin_LifeCycle_Mode;

  /**********************************************************
  * Direct Function Accesses and Take Addresses of Functions
  **********************************************************/

  {
    FncPtrType BswM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    BswM_FctPtr = (FncPtrType)Rte_Write_Provide_MSRP_Coding_requestMode; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  (void)memset(&Write_Provide_MSRP_Coding_requestMode, 0, sizeof(Write_Provide_MSRP_Coding_requestMode));
  fct_status = TSC_BswM_Rte_Write_Provide_MSRP_Coding_requestMode(Write_Provide_MSRP_Coding_requestMode);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  {
    FncPtrType BswM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    BswM_FctPtr = (FncPtrType)Rte_Write_Provide_MSRP_Darh_requestMode; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  (void)memset(&Write_Provide_MSRP_Darh_requestMode, 0, sizeof(Write_Provide_MSRP_Darh_requestMode));
  fct_status = TSC_BswM_Rte_Write_Provide_MSRP_Darh_requestMode(Write_Provide_MSRP_Darh_requestMode);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  {
    FncPtrType BswM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    BswM_FctPtr = (FncPtrType)Rte_Write_Provide_MSRP_Dlog_requestMode; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  (void)memset(&Write_Provide_MSRP_Dlog_requestMode, 0, sizeof(Write_Provide_MSRP_Dlog_requestMode));
  fct_status = TSC_BswM_Rte_Write_Provide_MSRP_Dlog_requestMode(Write_Provide_MSRP_Dlog_requestMode);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  {
    FncPtrType BswM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    BswM_FctPtr = (FncPtrType)Rte_Write_Provide_MSRP_Omc_requestMode; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  (void)memset(&Write_Provide_MSRP_Omc_requestMode, 0, sizeof(Write_Provide_MSRP_Omc_requestMode));
  fct_status = TSC_BswM_Rte_Write_Provide_MSRP_Omc_requestMode(Write_Provide_MSRP_Omc_requestMode);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  {
    FncPtrType BswM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    BswM_FctPtr = (FncPtrType)Rte_Write_Provide_MSRP_StdDiag_requestMode; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_BswM_Rte_Write_Provide_MSRP_StdDiag_requestMode(Rte_InitValue_Provide_MSRP_StdDiag_requestMode);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  {
    FncPtrType BswM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    BswM_FctPtr = (FncPtrType)Rte_Write_Provide_MSRP_SysTime_requestMode; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  (void)memset(&Write_Provide_MSRP_SysTime_requestMode, 0, sizeof(Write_Provide_MSRP_SysTime_requestMode));
  fct_status = TSC_BswM_Rte_Write_Provide_MSRP_SysTime_requestMode(Write_Provide_MSRP_SysTime_requestMode);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  {
    FncPtrType BswM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    BswM_FctPtr = (FncPtrType)Rte_Write_Provide_MSRP_Vin_requestMode; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_BswM_Rte_Write_Provide_MSRP_Vin_requestMode(Rte_InitValue_Provide_MSRP_Vin_requestMode);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  {
    FncPtrType BswM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    BswM_FctPtr = (FncPtrType)Rte_Switch_Switch_Coding_BusComModeSwitch_Mode; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_BswM_Rte_Switch_Switch_Coding_BusComModeSwitch_Mode(RTE_MODE_Coding_BusComMode_CODING_BUSCOMOFF);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  {
    FncPtrType BswM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    BswM_FctPtr = (FncPtrType)Rte_Switch_Switch_Coding_SwitchCodingMode_currentConditionMode; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_BswM_Rte_Switch_Switch_Coding_SwitchCodingMode_currentConditionMode(RTE_MODE_Coding_ConditionMode_CODING_ALLOWED);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  {
    FncPtrType BswM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    BswM_FctPtr = (FncPtrType)Rte_Switch_Switch_ErrorMemoryLockSignalReceptionSwitchPort_currentEMLockSignalReceptionMode; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_BswM_Rte_Switch_Switch_ErrorMemoryLockSignalReceptionSwitchPort_currentEMLockSignalReceptionMode(RTE_MODE_ErrorMemoryLockSignalReceptionMode_EM_LOCK_NOT_RECEIVABLE);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  {
    FncPtrType BswM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    BswM_FctPtr = (FncPtrType)Rte_Switch_Switch_StdDiagComControlNormalNotificationPort_CommunicationModeDeclarationGroup; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_BswM_Rte_Switch_Switch_StdDiagComControlNormalNotificationPort_CommunicationModeDeclarationGroup(RTE_MODE_StdDiag_NormalCommunicationModeGroup_ENABLE_RX_AND_TX_NORMAL);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  {
    FncPtrType BswM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    BswM_FctPtr = (FncPtrType)Rte_Switch_Switch_StdDiagSessionChangeIndicationPort_SessionModeDeclarationGroup; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_BswM_Rte_Switch_Switch_StdDiagSessionChangeIndicationPort_SessionModeDeclarationGroup(RTE_MODE_StdDiag_SessionModeGroup_STDDIAG_DEFAULT_SESSION);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  {
    FncPtrType BswM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    BswM_FctPtr = (FncPtrType)Rte_Switch_Switch_SwitchPort_Darh_ReportErrorMode_DarhReportErrorMode; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_BswM_Rte_Switch_Switch_SwitchPort_Darh_ReportErrorMode_DarhReportErrorMode(RTE_MODE_DarhReportErrorMode_DARH_REPORT_ERROR_INACTIVE);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  {
    FncPtrType BswM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    BswM_FctPtr = (FncPtrType)Rte_Switch_Switch_VinComSwitchPort_Mode; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_BswM_Rte_Switch_Switch_VinComSwitchPort_Mode(RTE_MODE_Vin_VinComMode_VIN_VINCOMOFF);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  {
    FncPtrType BswM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    BswM_FctPtr = (FncPtrType)Rte_Mode_Notification_SWCModeSwitch_currentCentralErrorLockMode_currentCentralErrorLockMode; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  Notification_SWCModeSwitch_currentCentralErrorLockMode_currentCentralErrorLockMode = TSC_BswM_Rte_Mode_Notification_SWCModeSwitch_currentCentralErrorLockMode_currentCentralErrorLockMode();
  {
    FncPtrType BswM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    BswM_FctPtr = (FncPtrType)Rte_Mode_Notification_SwcModeNotification_Coding_LifeCycle_Mode; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  Notification_SwcModeNotification_Coding_LifeCycle_Mode = TSC_BswM_Rte_Mode_Notification_SwcModeNotification_Coding_LifeCycle_Mode();
  {
    FncPtrType BswM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    BswM_FctPtr = (FncPtrType)Rte_Mode_Notification_SwcModeNotification_Darh_LifeCycle_Mode; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  Notification_SwcModeNotification_Darh_LifeCycle_Mode = TSC_BswM_Rte_Mode_Notification_SwcModeNotification_Darh_LifeCycle_Mode();
  {
    FncPtrType BswM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    BswM_FctPtr = (FncPtrType)Rte_Mode_Notification_SwcModeNotification_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  Notification_SwcModeNotification_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6 = TSC_BswM_Rte_Mode_Notification_SwcModeNotification_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6();
  {
    FncPtrType BswM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    BswM_FctPtr = (FncPtrType)Rte_Mode_Notification_SwcModeNotification_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  Notification_SwcModeNotification_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl = TSC_BswM_Rte_Mode_Notification_SwcModeNotification_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl();
  {
    FncPtrType BswM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    BswM_FctPtr = (FncPtrType)Rte_Mode_Notification_SwcModeNotification_DcmEcuReset_DcmEcuReset; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  Notification_SwcModeNotification_DcmEcuReset_DcmEcuReset = TSC_BswM_Rte_Mode_Notification_SwcModeNotification_DcmEcuReset_DcmEcuReset();
  {
    FncPtrType BswM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    BswM_FctPtr = (FncPtrType)Rte_Mode_Notification_SwcModeNotification_Dlog_LifeCycle_Mode; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  Notification_SwcModeNotification_Dlog_LifeCycle_Mode = TSC_BswM_Rte_Mode_Notification_SwcModeNotification_Dlog_LifeCycle_Mode();
  {
    FncPtrType BswM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    BswM_FctPtr = (FncPtrType)Rte_Mode_Notification_SwcModeNotification_Omc_LifeCycle_Mode; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  Notification_SwcModeNotification_Omc_LifeCycle_Mode = TSC_BswM_Rte_Mode_Notification_SwcModeNotification_Omc_LifeCycle_Mode();
  {
    FncPtrType BswM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    BswM_FctPtr = (FncPtrType)Rte_Mode_Notification_SwcModeNotification_StdDiag_LifeCycle_Mode; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  Notification_SwcModeNotification_StdDiag_LifeCycle_Mode = TSC_BswM_Rte_Mode_Notification_SwcModeNotification_StdDiag_LifeCycle_Mode();
  {
    FncPtrType BswM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    BswM_FctPtr = (FncPtrType)Rte_Mode_Notification_SwcModeNotification_SysTime_LifeCycle_Mode; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  Notification_SwcModeNotification_SysTime_LifeCycle_Mode = TSC_BswM_Rte_Mode_Notification_SwcModeNotification_SysTime_LifeCycle_Mode();
  {
    FncPtrType BswM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    BswM_FctPtr = (FncPtrType)Rte_Mode_Notification_SwcModeNotification_Vin_LifeCycle_Mode; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  Notification_SwcModeNotification_Vin_LifeCycle_Mode = TSC_BswM_Rte_Mode_Notification_SwcModeNotification_Vin_LifeCycle_Mode();

  TSC_BswM_SchM_Enter_BswM_BSWM_EXCLUSIVE_AREA_0();
  TSC_BswM_SchM_Exit_BswM_BSWM_EXCLUSIVE_AREA_0();

  BswM_TestDefines();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BswM_Read_StdDiag_ComControlModeRequest
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <requestedMode> of PortPrototype <Request_StdDiag_ComControlModeRequest>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_Request_StdDiag_ComControlModeRequest_requestedMode(NormalCommunicationModeType *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BswM_Read_StdDiag_ComControlModeRequest_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BswM_CODE) BswM_Read_StdDiag_ComControlModeRequest(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BswM_Read_StdDiag_ComControlModeRequest
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  NormalCommunicationModeType Read_Request_StdDiag_ComControlModeRequest_requestedMode;

  /**********************************************************
  * Direct Function Accesses and Take Addresses of Functions
  **********************************************************/

  {
    FncPtrType BswM_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    BswM_FctPtr = (FncPtrType)Rte_Read_Request_StdDiag_ComControlModeRequest_requestedMode; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_BswM_Rte_Read_Request_StdDiag_ComControlModeRequest_requestedMode(&Read_Request_StdDiag_ComControlModeRequest_requestedMode);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define BswM_STOP_SEC_CODE
#include "BswM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void BswM_TestDefines(void)
{
  /* Enumeration Data Types */

  Coding_ConditionModeType Test_Coding_ConditionModeType_V_1 = CODING_ALLOWED;
  Coding_ConditionModeType Test_Coding_ConditionModeType_V_2 = CODING_NOT_ALLOWED;

  Coding_LifeCycleRequestType Test_Coding_LifeCycleRequestType_V_1 = CODING_INITIALIZED;
  Coding_LifeCycleRequestType Test_Coding_LifeCycleRequestType_V_2 = CODING_RUNNING;
  Coding_LifeCycleRequestType Test_Coding_LifeCycleRequestType_V_3 = CODING_STOPPED;

  Darh_LifeCycleRequestType Test_Darh_LifeCycleRequestType_V_1 = DARH_INITIALIZED;
  Darh_LifeCycleRequestType Test_Darh_LifeCycleRequestType_V_2 = DARH_RUNNING;
  Darh_LifeCycleRequestType Test_Darh_LifeCycleRequestType_V_3 = DARH_STOPPED;

  Dcm_CommunicationModeType Test_Dcm_CommunicationModeType_V_1 = DCM_ENABLE_RX_TX_NORM;
  Dcm_CommunicationModeType Test_Dcm_CommunicationModeType_V_2 = DCM_ENABLE_RX_DISABLE_TX_NORM;
  Dcm_CommunicationModeType Test_Dcm_CommunicationModeType_V_3 = DCM_DISABLE_RX_ENABLE_TX_NORM;
  Dcm_CommunicationModeType Test_Dcm_CommunicationModeType_V_4 = DCM_DISABLE_RX_TX_NORMAL;
  Dcm_CommunicationModeType Test_Dcm_CommunicationModeType_V_5 = DCM_ENABLE_RX_TX_NM;
  Dcm_CommunicationModeType Test_Dcm_CommunicationModeType_V_6 = DCM_ENABLE_RX_DISABLE_TX_NM;
  Dcm_CommunicationModeType Test_Dcm_CommunicationModeType_V_7 = DCM_DISABLE_RX_ENABLE_TX_NM;
  Dcm_CommunicationModeType Test_Dcm_CommunicationModeType_V_8 = DCM_DISABLE_RX_TX_NM;
  Dcm_CommunicationModeType Test_Dcm_CommunicationModeType_V_9 = DCM_ENABLE_RX_TX_NORM_NM;
  Dcm_CommunicationModeType Test_Dcm_CommunicationModeType_V_10 = DCM_ENABLE_RX_DISABLE_TX_NORM_NM;
  Dcm_CommunicationModeType Test_Dcm_CommunicationModeType_V_11 = DCM_DISABLE_RX_ENABLE_TX_NORM_NM;
  Dcm_CommunicationModeType Test_Dcm_CommunicationModeType_V_12 = DCM_DISABLE_RX_TX_NORM_NM;

  Dcm_DiagnosticSessionControlType Test_Dcm_DiagnosticSessionControlType_V_1 = DCM_ENUM_DEFAULT_SESSION;
  Dcm_DiagnosticSessionControlType Test_Dcm_DiagnosticSessionControlType_V_2 = DCM_ENUM_PROGRAMMING_SESSION;
  Dcm_DiagnosticSessionControlType Test_Dcm_DiagnosticSessionControlType_V_3 = DCM_ENUM_EXTENDED_SESSION;
  Dcm_DiagnosticSessionControlType Test_Dcm_DiagnosticSessionControlType_V_4 = DCM_ENUM_CODING_SESSION;
  Dcm_DiagnosticSessionControlType Test_Dcm_DiagnosticSessionControlType_V_5 = DCM_ENUM_RSU_SESSION;
  Dcm_DiagnosticSessionControlType Test_Dcm_DiagnosticSessionControlType_V_6 = DCM_ENUM_DEVELOPMENT_SESSION;
  Dcm_DiagnosticSessionControlType Test_Dcm_DiagnosticSessionControlType_V_7 = DCM_ENUM_GarageMode;
  Dcm_DiagnosticSessionControlType Test_Dcm_DiagnosticSessionControlType_V_8 = DCM_ENUM_SYSTEM_SUPPLIER_SPECIFIC_61;
  Dcm_DiagnosticSessionControlType Test_Dcm_DiagnosticSessionControlType_V_9 = DCM_ENUM_DcmDspSessionRow_NXTRMFG;

  Dcm_EcuResetType Test_Dcm_EcuResetType_V_1 = DCM_ENUM_NONE;
  Dcm_EcuResetType Test_Dcm_EcuResetType_V_2 = DCM_ENUM_HARD;
  Dcm_EcuResetType Test_Dcm_EcuResetType_V_3 = DCM_ENUM_KEYONOFF;
  Dcm_EcuResetType Test_Dcm_EcuResetType_V_4 = DCM_ENUM_SOFT;
  Dcm_EcuResetType Test_Dcm_EcuResetType_V_5 = DCM_ENUM_JUMPTOBOOTLOADER;
  Dcm_EcuResetType Test_Dcm_EcuResetType_V_6 = DCM_ENUM_JUMPTOSYSSUPPLIERBOOTLOADER;
  Dcm_EcuResetType Test_Dcm_EcuResetType_V_7 = DCM_ENUM_EXECUTE;

  Dlog_LifeCycleRequestType Test_Dlog_LifeCycleRequestType_V_1 = DLOG_INITIALIZED;
  Dlog_LifeCycleRequestType Test_Dlog_LifeCycleRequestType_V_2 = DLOG_RUNNING;
  Dlog_LifeCycleRequestType Test_Dlog_LifeCycleRequestType_V_3 = DLOG_STOPPED;

  NormalCommunicationModeType Test_NormalCommunicationModeType_V_1 = DISABLE_RX_AND_TX_NORMAL;
  NormalCommunicationModeType Test_NormalCommunicationModeType_V_2 = DISABLE_RX_ENABLE_TX_NORMAL;
  NormalCommunicationModeType Test_NormalCommunicationModeType_V_3 = ENABLE_RX_AND_TX_NORMAL;
  NormalCommunicationModeType Test_NormalCommunicationModeType_V_4 = ENABLE_RX_DISABLE_TX_NORMAL;

  Omc_LifeCycleRequestType Test_Omc_LifeCycleRequestType_V_1 = OMC_INITIALIZED;
  Omc_LifeCycleRequestType Test_Omc_LifeCycleRequestType_V_2 = OMC_RUNNING;
  Omc_LifeCycleRequestType Test_Omc_LifeCycleRequestType_V_3 = OMC_STOPPED;

  StdDiag_LifeCycleRequestType Test_StdDiag_LifeCycleRequestType_V_1 = STDDIAG_INITIALIZED;
  StdDiag_LifeCycleRequestType Test_StdDiag_LifeCycleRequestType_V_2 = STDDIAG_RUNNING;
  StdDiag_LifeCycleRequestType Test_StdDiag_LifeCycleRequestType_V_3 = STDDIAG_STOPPED;

  Stm_CentralErrorLockType Test_Stm_CentralErrorLockType_V_1 = STM_CEL_UNLOCKED;
  Stm_CentralErrorLockType Test_Stm_CentralErrorLockType_V_2 = STM_CEL_LOCKED;
  Stm_CentralErrorLockType Test_Stm_CentralErrorLockType_V_3 = STM_CEL_INVALID;

  SysTime_LifeCycleRequestType Test_SysTime_LifeCycleRequestType_V_1 = SYSTIME_INITIALIZED;
  SysTime_LifeCycleRequestType Test_SysTime_LifeCycleRequestType_V_2 = SYSTIME_RUNNING;
  SysTime_LifeCycleRequestType Test_SysTime_LifeCycleRequestType_V_3 = SYSTIME_STOPPED;

  Vin_LifeCycleRequestType Test_Vin_LifeCycleRequestType_V_1 = VIN_INITIALIZED;
  Vin_LifeCycleRequestType Test_Vin_LifeCycleRequestType_V_2 = VIN_RUNNING;
  Vin_LifeCycleRequestType Test_Vin_LifeCycleRequestType_V_3 = VIN_STOPPED;

  /* Modes */

  uint8 Test_Coding_BusComMode_MV_1 = RTE_MODE_Coding_BusComMode_CODING_BUSCOMOFF;
  uint8 Test_Coding_BusComMode_MV_2 = RTE_MODE_Coding_BusComMode_CODING_BUSCOMON;
  uint8 Test_Coding_BusComMode_TV = RTE_TRANSITION_Coding_BusComMode;

  Coding_ConditionModeType Test_Coding_ConditionMode_MV_1 = RTE_MODE_Coding_ConditionMode_CODING_ALLOWED;
  Coding_ConditionModeType Test_Coding_ConditionMode_MV_2 = RTE_MODE_Coding_ConditionMode_CODING_NOT_ALLOWED;
  Coding_ConditionModeType Test_Coding_ConditionMode_TV = RTE_TRANSITION_Coding_ConditionMode;

  Coding_LifeCycleRequestType Test_Coding_LifeCycle_MV_1 = RTE_MODE_Coding_LifeCycle_CODING_INITIALIZED;
  Coding_LifeCycleRequestType Test_Coding_LifeCycle_MV_2 = RTE_MODE_Coding_LifeCycle_CODING_RUNNING;
  Coding_LifeCycleRequestType Test_Coding_LifeCycle_MV_3 = RTE_MODE_Coding_LifeCycle_CODING_STOPPED;
  Coding_LifeCycleRequestType Test_Coding_LifeCycle_TV = RTE_TRANSITION_Coding_LifeCycle;

  uint8 Test_DarhReportErrorMode_MV_1 = RTE_MODE_DarhReportErrorMode_DARH_REPORT_ERROR_ACTIVE;
  uint8 Test_DarhReportErrorMode_MV_2 = RTE_MODE_DarhReportErrorMode_DARH_REPORT_ERROR_INACTIVE;
  uint8 Test_DarhReportErrorMode_TV = RTE_TRANSITION_DarhReportErrorMode;

  Darh_LifeCycleRequestType Test_Darh_LifeCycle_MV_1 = RTE_MODE_Darh_LifeCycle_DARH_INITIALIZED;
  Darh_LifeCycleRequestType Test_Darh_LifeCycle_MV_2 = RTE_MODE_Darh_LifeCycle_DARH_RUNNING;
  Darh_LifeCycleRequestType Test_Darh_LifeCycle_MV_3 = RTE_MODE_Darh_LifeCycle_DARH_STOPPED;
  Darh_LifeCycleRequestType Test_Darh_LifeCycle_TV = RTE_TRANSITION_Darh_LifeCycle;

  Dcm_CommunicationModeType Test_DcmCommunicationControl_MV_1 = RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_TX_NORM;
  Dcm_CommunicationModeType Test_DcmCommunicationControl_MV_2 = RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_DISABLE_TX_NORM;
  Dcm_CommunicationModeType Test_DcmCommunicationControl_MV_3 = RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_ENABLE_TX_NORM;
  Dcm_CommunicationModeType Test_DcmCommunicationControl_MV_4 = RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_TX_NORMAL;
  Dcm_CommunicationModeType Test_DcmCommunicationControl_MV_5 = RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_TX_NM;
  Dcm_CommunicationModeType Test_DcmCommunicationControl_MV_6 = RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_DISABLE_TX_NM;
  Dcm_CommunicationModeType Test_DcmCommunicationControl_MV_7 = RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_ENABLE_TX_NM;
  Dcm_CommunicationModeType Test_DcmCommunicationControl_MV_8 = RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_TX_NM;
  Dcm_CommunicationModeType Test_DcmCommunicationControl_MV_9 = RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_TX_NORM_NM;
  Dcm_CommunicationModeType Test_DcmCommunicationControl_MV_10 = RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_DISABLE_TX_NORM_NM;
  Dcm_CommunicationModeType Test_DcmCommunicationControl_MV_11 = RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_ENABLE_TX_NORM_NM;
  Dcm_CommunicationModeType Test_DcmCommunicationControl_MV_12 = RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_TX_NORM_NM;
  Dcm_CommunicationModeType Test_DcmCommunicationControl_TV = RTE_TRANSITION_DcmCommunicationControl;

  Dcm_DiagnosticSessionControlType Test_DcmDiagnosticSessionControl_MV_1 = RTE_MODE_DcmDiagnosticSessionControl_DEFAULT_SESSION;
  Dcm_DiagnosticSessionControlType Test_DcmDiagnosticSessionControl_MV_2 = RTE_MODE_DcmDiagnosticSessionControl_PROGRAMMING_SESSION;
  Dcm_DiagnosticSessionControlType Test_DcmDiagnosticSessionControl_MV_3 = RTE_MODE_DcmDiagnosticSessionControl_EXTENDED_SESSION;
  Dcm_DiagnosticSessionControlType Test_DcmDiagnosticSessionControl_MV_4 = RTE_MODE_DcmDiagnosticSessionControl_CODING_SESSION;
  Dcm_DiagnosticSessionControlType Test_DcmDiagnosticSessionControl_MV_5 = RTE_MODE_DcmDiagnosticSessionControl_RSU_SESSION;
  Dcm_DiagnosticSessionControlType Test_DcmDiagnosticSessionControl_MV_6 = RTE_MODE_DcmDiagnosticSessionControl_DEVELOPMENT_SESSION;
  Dcm_DiagnosticSessionControlType Test_DcmDiagnosticSessionControl_MV_7 = RTE_MODE_DcmDiagnosticSessionControl_GarageMode;
  Dcm_DiagnosticSessionControlType Test_DcmDiagnosticSessionControl_MV_8 = RTE_MODE_DcmDiagnosticSessionControl_SYSTEM_SUPPLIER_SPECIFIC_61;
  Dcm_DiagnosticSessionControlType Test_DcmDiagnosticSessionControl_MV_9 = RTE_MODE_DcmDiagnosticSessionControl_DcmDspSessionRow_NXTRMFG;
  Dcm_DiagnosticSessionControlType Test_DcmDiagnosticSessionControl_TV = RTE_TRANSITION_DcmDiagnosticSessionControl;

  Dcm_EcuResetType Test_DcmEcuReset_MV_1 = RTE_MODE_DcmEcuReset_NONE;
  Dcm_EcuResetType Test_DcmEcuReset_MV_2 = RTE_MODE_DcmEcuReset_HARD;
  Dcm_EcuResetType Test_DcmEcuReset_MV_3 = RTE_MODE_DcmEcuReset_KEYONOFF;
  Dcm_EcuResetType Test_DcmEcuReset_MV_4 = RTE_MODE_DcmEcuReset_SOFT;
  Dcm_EcuResetType Test_DcmEcuReset_MV_5 = RTE_MODE_DcmEcuReset_JUMPTOBOOTLOADER;
  Dcm_EcuResetType Test_DcmEcuReset_MV_6 = RTE_MODE_DcmEcuReset_JUMPTOSYSSUPPLIERBOOTLOADER;
  Dcm_EcuResetType Test_DcmEcuReset_MV_7 = RTE_MODE_DcmEcuReset_EXECUTE;
  Dcm_EcuResetType Test_DcmEcuReset_TV = RTE_TRANSITION_DcmEcuReset;

  Dlog_LifeCycleRequestType Test_Dlog_LifeCycle_MV_1 = RTE_MODE_Dlog_LifeCycle_DLOG_INITIALIZED;
  Dlog_LifeCycleRequestType Test_Dlog_LifeCycle_MV_2 = RTE_MODE_Dlog_LifeCycle_DLOG_RUNNING;
  Dlog_LifeCycleRequestType Test_Dlog_LifeCycle_MV_3 = RTE_MODE_Dlog_LifeCycle_DLOG_STOPPED;
  Dlog_LifeCycleRequestType Test_Dlog_LifeCycle_TV = RTE_TRANSITION_Dlog_LifeCycle;

  uint8 Test_ErrorMemoryLockSignalReceptionMode_MV_1 = RTE_MODE_ErrorMemoryLockSignalReceptionMode_EM_LOCK_NOT_RECEIVABLE;
  uint8 Test_ErrorMemoryLockSignalReceptionMode_MV_2 = RTE_MODE_ErrorMemoryLockSignalReceptionMode_EM_LOCK_RECEIVABLE;
  uint8 Test_ErrorMemoryLockSignalReceptionMode_TV = RTE_TRANSITION_ErrorMemoryLockSignalReceptionMode;

  Omc_LifeCycleRequestType Test_Omc_LifeCycle_MV_1 = RTE_MODE_Omc_LifeCycle_OMC_INITIALIZED;
  Omc_LifeCycleRequestType Test_Omc_LifeCycle_MV_2 = RTE_MODE_Omc_LifeCycle_OMC_RUNNING;
  Omc_LifeCycleRequestType Test_Omc_LifeCycle_MV_3 = RTE_MODE_Omc_LifeCycle_OMC_STOPPED;
  Omc_LifeCycleRequestType Test_Omc_LifeCycle_TV = RTE_TRANSITION_Omc_LifeCycle;

  StdDiag_LifeCycleRequestType Test_StdDiag_LifeCycle_MV_1 = RTE_MODE_StdDiag_LifeCycle_STDDIAG_INITIALIZED;
  StdDiag_LifeCycleRequestType Test_StdDiag_LifeCycle_MV_2 = RTE_MODE_StdDiag_LifeCycle_STDDIAG_RUNNING;
  StdDiag_LifeCycleRequestType Test_StdDiag_LifeCycle_MV_3 = RTE_MODE_StdDiag_LifeCycle_STDDIAG_STOPPED;
  StdDiag_LifeCycleRequestType Test_StdDiag_LifeCycle_TV = RTE_TRANSITION_StdDiag_LifeCycle;

  NormalCommunicationModeType Test_StdDiag_NormalCommunicationModeGroup_MV_1 = RTE_MODE_StdDiag_NormalCommunicationModeGroup_DISABLE_RX_AND_TX_NORMAL;
  NormalCommunicationModeType Test_StdDiag_NormalCommunicationModeGroup_MV_2 = RTE_MODE_StdDiag_NormalCommunicationModeGroup_DISABLE_RX_ENABLE_TX_NORMAL;
  NormalCommunicationModeType Test_StdDiag_NormalCommunicationModeGroup_MV_3 = RTE_MODE_StdDiag_NormalCommunicationModeGroup_ENABLE_RX_AND_TX_NORMAL;
  NormalCommunicationModeType Test_StdDiag_NormalCommunicationModeGroup_MV_4 = RTE_MODE_StdDiag_NormalCommunicationModeGroup_ENABLE_RX_DISABLE_TX_NORMAL;
  NormalCommunicationModeType Test_StdDiag_NormalCommunicationModeGroup_TV = RTE_TRANSITION_StdDiag_NormalCommunicationModeGroup;

  uint8 Test_StdDiag_SessionModeGroup_MV_1 = RTE_MODE_StdDiag_SessionModeGroup_STDDIAG_DEFAULT_SESSION;
  uint8 Test_StdDiag_SessionModeGroup_MV_2 = RTE_MODE_StdDiag_SessionModeGroup_STDDIAG_OTHER_SESSION;
  uint8 Test_StdDiag_SessionModeGroup_TV = RTE_TRANSITION_StdDiag_SessionModeGroup;

  Stm_CentralErrorLockType Test_Stm_CentralErrorLockMode_MV_1 = RTE_MODE_Stm_CentralErrorLockMode_STM_CEL_INVALID;
  Stm_CentralErrorLockType Test_Stm_CentralErrorLockMode_MV_2 = RTE_MODE_Stm_CentralErrorLockMode_STM_CEL_LOCKED;
  Stm_CentralErrorLockType Test_Stm_CentralErrorLockMode_MV_3 = RTE_MODE_Stm_CentralErrorLockMode_STM_CEL_UNLOCKED;
  Stm_CentralErrorLockType Test_Stm_CentralErrorLockMode_TV = RTE_TRANSITION_Stm_CentralErrorLockMode;

  SysTime_LifeCycleRequestType Test_SysTime_LifeCycle_MV_1 = RTE_MODE_SysTime_LifeCycle_SYSTIME_INITIALIZED;
  SysTime_LifeCycleRequestType Test_SysTime_LifeCycle_MV_2 = RTE_MODE_SysTime_LifeCycle_SYSTIME_RUNNING;
  SysTime_LifeCycleRequestType Test_SysTime_LifeCycle_MV_3 = RTE_MODE_SysTime_LifeCycle_SYSTIME_STOPPED;
  SysTime_LifeCycleRequestType Test_SysTime_LifeCycle_TV = RTE_TRANSITION_SysTime_LifeCycle;

  Vin_LifeCycleRequestType Test_Vin_LifeCycle_MV_1 = RTE_MODE_Vin_LifeCycle_VIN_INITIALIZED;
  Vin_LifeCycleRequestType Test_Vin_LifeCycle_MV_2 = RTE_MODE_Vin_LifeCycle_VIN_RUNNING;
  Vin_LifeCycleRequestType Test_Vin_LifeCycle_MV_3 = RTE_MODE_Vin_LifeCycle_VIN_STOPPED;
  Vin_LifeCycleRequestType Test_Vin_LifeCycle_TV = RTE_TRANSITION_Vin_LifeCycle;

  uint8 Test_Vin_VinComMode_MV_1 = RTE_MODE_Vin_VinComMode_VIN_VINCOMON;
  uint8 Test_Vin_VinComMode_MV_2 = RTE_MODE_Vin_VinComMode_VIN_VINCOMOFF;
  uint8 Test_Vin_VinComMode_TV = RTE_TRANSITION_Vin_VinComMode;
}

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
