/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  StdDiag.c
 *        Config:  EPS.dpa
 *     SW-C Type:  StdDiag
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <StdDiag>
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
 * Darh_RoeStateType
 *   
 *
 * Dcm_ConfirmationStatusType
 *   
 *
 * Dcm_NegativeResponseCodeType
 *   
 *
 * Dcm_OpStatusType
 *   
 *
 * Dcm_SesCtrlType
 *   
 *
 * Dem_DTCFormatType
 *   
 *
 * Dem_DTCOriginType
 *   
 *
 * NormalCommunicationModeType
 *   
 *
 * Omc_ExtendedOperatingModeType
 *   
 *
 * Omc_OperatingModeType
 *   
 *
 * StdDiag_LifeCycleRequestType
 *   
 *
 * Stm_VehicleStateType
 *   
 *
 *********************************************************************************************************************/

#include "Rte_StdDiag.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_StdDiag.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"

static void StdDiag_TestDefines(void);


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
 * boolean: Boolean (standard type)
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * Darh_RoeStateType: Enumeration of integer in interval [0...255] with enumerators
 *   DARH_ROE_STOPPED (0U)
 *   DARH_ROE_STARTED (1U)
 *   DARH_ROE_UNKNOWN (2U)
 * Dcm_ConfirmationStatusType: Enumeration of integer in interval [0...3] with enumerators
 *   DCM_RES_POS_OK (0U)
 *   DCM_RES_POS_NOT_OK (1U)
 *   DCM_RES_NEG_OK (2U)
 *   DCM_RES_NEG_NOT_OK (3U)
 * Dcm_NegativeResponseCodeType: Enumeration of integer in interval [16...254] with enumerators
 *   DCM_E_BRAKESWITCH_NOTCLOSED (143U)
 *   DCM_E_BUSYREPEATREQUEST (33U)
 *   DCM_E_CONDITIONSNOTCORRECT (34U)
 *   DCM_E_ENGINEISNOTRUNNING (132U)
 *   DCM_E_ENGINEISRUNNING (131U)
 *   DCM_E_ENGINERUNTIMETOOLOW (133U)
 *   DCM_E_EXCEEDNUMBEROFATTEMPTS (54U)
 *   DCM_E_FAILUREPREVENTSEXECUTIONOFREQUESTEDACTION (38U)
 *   DCM_E_GENERALPROGRAMMINGFAILURE (114U)
 *   DCM_E_GENERALREJECT (16U)
 *   DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT (19U)
 *   DCM_E_INVALIDKEY (53U)
 *   DCM_E_NORESPONSEFROMSUBNETCOMPONENT (37U)
 *   DCM_E_REQUESTOUTOFRANGE (49U)
 *   DCM_E_REQUESTSEQUENCEERROR (36U)
 *   DCM_E_REQUIREDTIMEDELAYNOTEXPIRED (55U)
 *   DCM_E_RESPONSETOOLONG (20U)
 *   DCM_E_RPMTOOHIGH (129U)
 *   DCM_E_RPMTOOLOW (130U)
 *   DCM_E_SECURITYACCESSDENIED (51U)
 *   DCM_E_SERVICENOTSUPPORTED (17U)
 *   DCM_E_SERVICENOTSUPPORTEDINACTIVESESSION (127U)
 *   DCM_E_SHIFTERLEVERNOTINPARK (144U)
 *   DCM_E_SUBFUNCTIONNOTSUPPORTED (18U)
 *   DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION (126U)
 *   DCM_E_TEMPERATURETOOHIGH (134U)
 *   DCM_E_TEMPERATURETOOLOW (135U)
 *   DCM_E_THROTTLE_PEDALTOOHIGH (138U)
 *   DCM_E_THROTTLE_PEDALTOOLOW (139U)
 *   DCM_E_TORQUECONVERTERCLUTCHLOCKED (145U)
 *   DCM_E_TRANSFERDATASUSPENDED (113U)
 *   DCM_E_TRANSMISSIONRANGENOTINGEAR (141U)
 *   DCM_E_TRANSMISSIONRANGENOTINNEUTRAL (140U)
 *   DCM_E_UPLOADDOWNLOADNOTACCEPTED (112U)
 *   DCM_E_VEHICLESPEEDTOOHIGH (136U)
 *   DCM_E_VEHICLESPEEDTOOLOW (137U)
 *   DCM_E_VOLTAGETOOHIGH (146U)
 *   DCM_E_VOLTAGETOOLOW (147U)
 *   DCM_E_WRONGBLOCKSEQUENCECOUNTER (115U)
 *   DCM_E_VMSCNC_0 (240U)
 *   DCM_E_VMSCNC_1 (241U)
 *   DCM_E_VMSCNC_2 (242U)
 *   DCM_E_VMSCNC_3 (243U)
 *   DCM_E_VMSCNC_4 (244U)
 *   DCM_E_VMSCNC_5 (245U)
 *   DCM_E_VMSCNC_6 (246U)
 *   DCM_E_VMSCNC_7 (247U)
 *   DCM_E_VMSCNC_8 (248U)
 *   DCM_E_VMSCNC_9 (249U)
 *   DCM_E_VMSCNC_A (250U)
 *   DCM_E_VMSCNC_B (251U)
 *   DCM_E_VMSCNC_C (252U)
 *   DCM_E_VMSCNC_D (253U)
 *   DCM_E_VMSCNC_E (254U)
 * Dcm_OpStatusType: Enumeration of integer in interval [0...3] with enumerators
 *   DCM_INITIAL (0U)
 *   DCM_PENDING (1U)
 *   DCM_CANCEL (2U)
 *   DCM_FORCE_RCRRP_OK (3U)
 * Dcm_SesCtrlType: Enumeration of integer in interval [1...66] with enumerators
 *   DCM_DEFAULT_SESSION (1U)
 *   DCM_PROGRAMMING_SESSION (2U)
 *   DCM_EXTENDED_DIAGNOSTIC_SESSION (3U)
 *   DCM_SAFETY_SYSTEM_DIAGNOSTIC_SESSION (4U)
 *   DCM_CODING_SESSION (65U)
 *   DCM_SWT_SESSION (66U)
 * Dem_DTCFormatType: Enumeration of integer in interval [0...2] with enumerators
 *   DEM_DTC_FORMAT_OBD (0U)
 *   DEM_DTC_FORMAT_UDS (1U)
 *   DEM_DTC_FORMAT_J1939 (2U)
 * Dem_DTCOriginType: Enumeration of integer in interval [1...4] with enumerators
 *   DEM_DTC_ORIGIN_PRIMARY_MEMORY (1U)
 *   DEM_DTC_ORIGIN_MIRROR_MEMORY (2U)
 *   DEM_DTC_ORIGIN_PERMANENT_MEMORY (3U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_BMWSecondaryErrorMemory (4U)
 * NormalCommunicationModeType: Enumeration of integer in interval [0...255] with enumerators
 *   DISABLE_RX_AND_TX_NORMAL (0U)
 *   DISABLE_RX_ENABLE_TX_NORMAL (1U)
 *   ENABLE_RX_AND_TX_NORMAL (2U)
 *   ENABLE_RX_DISABLE_TX_NORMAL (3U)
 * Omc_ExtendedOperatingModeType: Enumeration of integer in interval [0...255] with enumerators
 *   OMC_MODE_EXTENSION_NORMAL (0U)
 *   OMC_MODE_EXTENSION_1 (1U)
 *   OMC_MODE_EXTENSION_2 (2U)
 *   OMC_MODE_EXTENSION_3 (3U)
 *   OMC_MODE_EXTENSION_4 (4U)
 *   OMC_MODE_EXTENSION_5 (5U)
 *   OMC_MODE_EXTENSION_6 (6U)
 *   OMC_MODE_EXTENSION_7 (7U)
 *   OMC_MODE_EXTENSION_8 (8U)
 *   OMC_MODE_EXTENSION_9 (9U)
 *   OMC_MODE_EXTENSION_10 (10U)
 *   OMC_MODE_EXTENSION_11 (11U)
 *   OMC_MODE_EXTENSION_12 (12U)
 *   OMC_MODE_EXTENSION_13 (13U)
 *   OMC_MODE_EXTENSION_14 (14U)
 *   OMC_MODE_EXTENSION_SAVE_ENERGY (15U)
 *   OMC_MODE_EXTENSION_INVALID (255U)
 * Omc_OperatingModeType: Enumeration of integer in interval [0...255] with enumerators
 *   OMC_MODE_NORMAL (0U)
 *   OMC_MODE_ASSEMBLY (1U)
 *   OMC_MODE_TRANSPORT (2U)
 *   OMC_MODE_BMW_FLASH (3U)
 * StdDiag_LifeCycleRequestType: Enumeration of integer in interval [0...255] with enumerators
 *   STDDIAG_INITIALIZED (0U)
 *   STDDIAG_RUNNING (1U)
 *   STDDIAG_STOPPED (2U)
 * Stm_VehicleStateType: Enumeration of integer in interval [0...255] with enumerators
 *   STM_VEHICLE_STATE_PARKING_BN_NOK (1U)
 *   STM_VEHICLE_STATE_PARKING_BN_OK (2U)
 *   STM_VEHICLE_STATE_CUSTOMER_ABSENT (3U)
 *   STM_VEHICLE_STATE_LIVING (5U)
 *   STM_VEHICLE_STATE_CHECK_ANALYS_DIAGNOSTICS (7U)
 *   STM_VEHICLE_STATE_READINESS_TO_DRIVE_INIT (8U)
 *   STM_VEHICLE_STATE_DRIVE (10U)
 *   STM_VEHICLE_STATE_READINESS_TO_DRIVE_STOP (12U)
 *   STM_VEHICLE_STATE_UNAVAILABLE (14U)
 *   STM_VEHICLE_STATE_INVALID (15U)
 *
 * Array Types:
 * ============
 * ActiveSessionState_ArrayType: Array with 4 element(s) of type uint8
 * CheckProgrammingPreconditions_ArrayType: Array with 256 element(s) of type uint8
 * DiagCommLoopback_ArrayType: Array with 1024 element(s) of type uint8
 * RequestDataArray: Array with 1024 element(s) of type uint8
 * SgbdIndex_ArrayType: Array with 3 element(s) of type uint8
 *
 *********************************************************************************************************************/


#define StdDiag_START_SEC_CODE
#include "StdDiag_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AllowOpModeChange
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <AllowOpModeSwitch> of PortPrototype <AllowOpModeChangePort>
 *
 **********************************************************************************************************************
 *
 * Mode Interfaces:
 * ================
 *   Stm_VehicleStateType Rte_Mode_VehicleStatePort_currentVehicleStateMode(void)
 *   Modes of Rte_ModeType_Stm_VehicleStateMode:
 *   - RTE_MODE_Stm_VehicleStateMode_STM_VEHICLE_STATE_CHECK_ANALYS_DIAGNOSTICS
 *   - RTE_MODE_Stm_VehicleStateMode_STM_VEHICLE_STATE_CUSTOMER_ABSENT
 *   - RTE_MODE_Stm_VehicleStateMode_STM_VEHICLE_STATE_DRIVE
 *   - RTE_MODE_Stm_VehicleStateMode_STM_VEHICLE_STATE_INVALID
 *   - RTE_MODE_Stm_VehicleStateMode_STM_VEHICLE_STATE_LIVING
 *   - RTE_MODE_Stm_VehicleStateMode_STM_VEHICLE_STATE_PARKING_BN_NOK
 *   - RTE_MODE_Stm_VehicleStateMode_STM_VEHICLE_STATE_PARKING_BN_OK
 *   - RTE_MODE_Stm_VehicleStateMode_STM_VEHICLE_STATE_READINESS_TO_DRIVE_INIT
 *   - RTE_MODE_Stm_VehicleStateMode_STM_VEHICLE_STATE_READINESS_TO_DRIVE_STOP
 *   - RTE_MODE_Stm_VehicleStateMode_STM_VEHICLE_STATE_UNAVAILABLE
 *   - RTE_TRANSITION_Stm_VehicleStateMode
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType StdDiag_AllowOpModeChange(Omc_OperatingModeType OperatingMode, Omc_ExtendedOperatingModeType ExtendedOperatingMode, Omc_OperatingModeType NewOperatingMode, Omc_ExtendedOperatingModeType NewExtendedOperatingMode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_OmcModesCallouts_E_NOT_OK
 *   RTE_E_OmcModesCallouts_E_RUNNING
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: AllowOpModeChange_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, StdDiag_CODE) StdDiag_AllowOpModeChange(Omc_OperatingModeType OperatingMode, Omc_ExtendedOperatingModeType ExtendedOperatingMode, Omc_OperatingModeType NewOperatingMode, Omc_ExtendedOperatingModeType NewExtendedOperatingMode) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: StdDiag_AllowOpModeChange (returns application error)
 *********************************************************************************************************************/

  Rte_ModeType_Stm_VehicleStateMode VehicleStatePort_currentVehicleStateMode;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  VehicleStatePort_currentVehicleStateMode = TSC_StdDiag_Rte_Mode_VehicleStatePort_currentVehicleStateMode();

  StdDiag_TestDefines();

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ConditionCheckActiveSessionState
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <ActiveSessionState>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_UserActiveSessionStatePort_GetActiveSessionState(Dcm_SesCtrlType activeSession, uint8 *activeSessionState)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_UserActiveSessionState_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_DCMServicesPort_GetSesCtrlType(Dcm_SesCtrlType *SesCtrlType)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_StdDiagDCMServices_E_NOT_OK, RTE_E_StdDiagDCMServices_E_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType StdDiag_ConditionCheckActiveSessionState(Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_ActiveSessionState_E_NOT_OK
 *   RTE_E_DataServices_ActiveSessionState_E_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ConditionCheckActiveSessionState_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, StdDiag_CODE) StdDiag_ConditionCheckActiveSessionState(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_STDDIAG_APPL_VAR) ErrorCode) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: StdDiag_ConditionCheckActiveSessionState (returns application error)
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  uint8 Call_UserActiveSessionStatePort_GetActiveSessionState_activeSessionState = 0U;

  Dcm_SesCtrlType Call_DCMServicesPort_GetSesCtrlType_SesCtrlType = 0U;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_StdDiag_Rte_Call_UserActiveSessionStatePort_GetActiveSessionState(0U, &Call_UserActiveSessionStatePort_GetActiveSessionState_activeSessionState);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_UserActiveSessionState_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_StdDiag_Rte_Call_DCMServicesPort_GetSesCtrlType(&Call_DCMServicesPort_GetSesCtrlType_SesCtrlType);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_StdDiagDCMServices_E_NOT_OK:
      fct_error = 1;
      break;
  }

  return RTE_E_DataServices_ActiveSessionState_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: LifeCycleHandler
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <requestMode> of PortPrototype <LifeCycleRequest>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   StdDiag_LifeCycleRequestType Rte_IRead_LifeCycleHandler_LifeCycleRequest_requestMode(void)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ComControlModeRequestPort_requestedMode(NormalCommunicationModeType data)
 *
 * Mode Interfaces:
 * ================
 *   Std_ReturnType Rte_Switch_LifeCycle_Mode(StdDiag_LifeCycleRequestType mode)
 *   Modes of Rte_ModeType_StdDiag_LifeCycle:
 *   - RTE_MODE_StdDiag_LifeCycle_STDDIAG_INITIALIZED
 *   - RTE_MODE_StdDiag_LifeCycle_STDDIAG_RUNNING
 *   - RTE_MODE_StdDiag_LifeCycle_STDDIAG_STOPPED
 *   - RTE_TRANSITION_StdDiag_LifeCycle
 *   Omc_ExtendedOperatingModeType Rte_Mode_ExtendedOperatingModeControlPort_currentExtendedOperatingMode(void)
 *   Modes of Rte_ModeType_OmcExtendedOperatingMode:
 *   - RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_1
 *   - RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_10
 *   - RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_11
 *   - RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_12
 *   - RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_13
 *   - RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_14
 *   - RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_2
 *   - RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_3
 *   - RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_4
 *   - RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_5
 *   - RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_6
 *   - RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_7
 *   - RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_8
 *   - RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_9
 *   - RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_INVALID
 *   - RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_NORMAL
 *   - RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_SAVE_ENERGY
 *   - RTE_TRANSITION_OmcExtendedOperatingMode
 *   StdDiag_LifeCycleRequestType Rte_Mode_LifeCycle_Mode(StdDiag_LifeCycleRequestType *previousMode, StdDiag_LifeCycleRequestType *nextMode)
 *   Modes of Rte_ModeType_StdDiag_LifeCycle:
 *   - RTE_MODE_StdDiag_LifeCycle_STDDIAG_INITIALIZED
 *   - RTE_MODE_StdDiag_LifeCycle_STDDIAG_RUNNING
 *   - RTE_MODE_StdDiag_LifeCycle_STDDIAG_STOPPED
 *   - RTE_TRANSITION_StdDiag_LifeCycle
 *   Omc_OperatingModeType Rte_Mode_OperatingModeControlPort_currentOperatingMode(void)
 *   Modes of Rte_ModeType_OmcOperatingMode:
 *   - RTE_MODE_OmcOperatingMode_OMC_MODE_ASSEMBLY
 *   - RTE_MODE_OmcOperatingMode_OMC_MODE_BMW_FLASH
 *   - RTE_MODE_OmcOperatingMode_OMC_MODE_NORMAL
 *   - RTE_MODE_OmcOperatingMode_OMC_MODE_TRANSPORT
 *   - RTE_TRANSITION_OmcOperatingMode
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_RoeStatePort_GetRoeState(Darh_RoeStateType *RoeState)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_RoeStateInterface_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_DCMServicesPort_GetSesCtrlType(Dcm_SesCtrlType *SesCtrlType)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_StdDiagDCMServices_E_NOT_OK, RTE_E_StdDiagDCMServices_E_OK
 *   Std_ReturnType Rte_Call_EnableConditionPort_SetEnableCondition(boolean ConditionFulfilled)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EnableCondition_E_NOT_OK, RTE_E_EnableCondition_E_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: LifeCycleHandler_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, StdDiag_CODE) StdDiag_LifeCycleHandler(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: StdDiag_LifeCycleHandler
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  StdDiag_LifeCycleRequestType IRead_LifeCycleRequest_requestMode;

  NormalCommunicationModeType Write_ComControlModeRequestPort_requestedMode;

  Rte_ModeType_OmcExtendedOperatingMode ExtendedOperatingModeControlPort_currentExtendedOperatingMode;
  Rte_ModeType_StdDiag_LifeCycle LifeCycle_Mode;
  Rte_ModeType_StdDiag_LifeCycle LifeCycle_Mode_previousMode;
  Rte_ModeType_StdDiag_LifeCycle LifeCycle_Mode_nextMode;
  Rte_ModeType_OmcOperatingMode OperatingModeControlPort_currentOperatingMode;

  Darh_RoeStateType Call_RoeStatePort_GetRoeState_RoeState = 0U;

  Dcm_SesCtrlType Call_DCMServicesPort_GetSesCtrlType_SesCtrlType = 0U;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  IRead_LifeCycleRequest_requestMode = TSC_StdDiag_Rte_IRead_LifeCycleHandler_LifeCycleRequest_requestMode();

  (void)memset(&Write_ComControlModeRequestPort_requestedMode, 0, sizeof(Write_ComControlModeRequestPort_requestedMode));
  fct_status = TSC_StdDiag_Rte_Write_ComControlModeRequestPort_requestedMode(Write_ComControlModeRequestPort_requestedMode);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_StdDiag_Rte_Switch_LifeCycle_Mode(RTE_MODE_StdDiag_LifeCycle_STDDIAG_STOPPED);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  ExtendedOperatingModeControlPort_currentExtendedOperatingMode = TSC_StdDiag_Rte_Mode_ExtendedOperatingModeControlPort_currentExtendedOperatingMode();
  LifeCycle_Mode = TSC_StdDiag_Rte_Mode_LifeCycle_Mode(&LifeCycle_Mode_previousMode, &LifeCycle_Mode_nextMode);
  OperatingModeControlPort_currentOperatingMode = TSC_StdDiag_Rte_Mode_OperatingModeControlPort_currentOperatingMode();

  fct_status = TSC_StdDiag_Rte_Call_RoeStatePort_GetRoeState(&Call_RoeStatePort_GetRoeState_RoeState);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_RoeStateInterface_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_StdDiag_Rte_Call_DCMServicesPort_GetSesCtrlType(&Call_DCMServicesPort_GetSesCtrlType_SesCtrlType);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_StdDiagDCMServices_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_StdDiag_Rte_Call_EnableConditionPort_SetEnableCondition(FALSE);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_EnableCondition_E_NOT_OK:
      fct_error = 1;
      break;
  }


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ManufacturerConfirmation
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Confirmation> of PortPrototype <ServiceRequestManufacturerNotificationPort>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ComControlModeRequestPort_requestedMode(NormalCommunicationModeType data)
 *
 * Mode Interfaces:
 * ================
 *   NormalCommunicationModeType Rte_Mode_ComControlNormalModeAccessPort_CommunicationModeDeclarationGroup(void)
 *   Modes of Rte_ModeType_StdDiag_NormalCommunicationModeGroup:
 *   - RTE_MODE_StdDiag_NormalCommunicationModeGroup_DISABLE_RX_AND_TX_NORMAL
 *   - RTE_MODE_StdDiag_NormalCommunicationModeGroup_DISABLE_RX_ENABLE_TX_NORMAL
 *   - RTE_MODE_StdDiag_NormalCommunicationModeGroup_ENABLE_RX_AND_TX_NORMAL
 *   - RTE_MODE_StdDiag_NormalCommunicationModeGroup_ENABLE_RX_DISABLE_TX_NORMAL
 *   - RTE_TRANSITION_StdDiag_NormalCommunicationModeGroup
 *   Omc_ExtendedOperatingModeType Rte_Mode_ExtendedOperatingModeControlPort_currentExtendedOperatingMode(void)
 *   Modes of Rte_ModeType_OmcExtendedOperatingMode:
 *   - RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_1
 *   - RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_10
 *   - RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_11
 *   - RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_12
 *   - RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_13
 *   - RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_14
 *   - RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_2
 *   - RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_3
 *   - RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_4
 *   - RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_5
 *   - RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_6
 *   - RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_7
 *   - RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_8
 *   - RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_9
 *   - RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_INVALID
 *   - RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_NORMAL
 *   - RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_SAVE_ENERGY
 *   - RTE_TRANSITION_OmcExtendedOperatingMode
 *   Omc_OperatingModeType Rte_Mode_OperatingModeControlPort_currentOperatingMode(void)
 *   Modes of Rte_ModeType_OmcOperatingMode:
 *   - RTE_MODE_OmcOperatingMode_OMC_MODE_ASSEMBLY
 *   - RTE_MODE_OmcOperatingMode_OMC_MODE_BMW_FLASH
 *   - RTE_MODE_OmcOperatingMode_OMC_MODE_NORMAL
 *   - RTE_MODE_OmcOperatingMode_OMC_MODE_TRANSPORT
 *   - RTE_TRANSITION_OmcOperatingMode
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_RoeStatePort_GetRoeState(Darh_RoeStateType *RoeState)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_RoeStateInterface_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_EnableConditionPort_SetEnableCondition(boolean ConditionFulfilled)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EnableCondition_E_NOT_OK, RTE_E_EnableCondition_E_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType StdDiag_ManufacturerConfirmation(uint8 SID, uint8 ReqType, uint16 SourceAddress, Dcm_ConfirmationStatusType ConfirmationStatus)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_ServiceRequestNotification_E_NOT_OK
 *   RTE_E_ServiceRequestNotification_E_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ManufacturerConfirmation_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, StdDiag_CODE) StdDiag_ManufacturerConfirmation(uint8 SID, uint8 ReqType, uint16 SourceAddress, Dcm_ConfirmationStatusType ConfirmationStatus) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: StdDiag_ManufacturerConfirmation (returns application error)
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  NormalCommunicationModeType Write_ComControlModeRequestPort_requestedMode;

  Rte_ModeType_StdDiag_NormalCommunicationModeGroup ComControlNormalModeAccessPort_CommunicationModeDeclarationGroup;
  Rte_ModeType_OmcExtendedOperatingMode ExtendedOperatingModeControlPort_currentExtendedOperatingMode;
  Rte_ModeType_OmcOperatingMode OperatingModeControlPort_currentOperatingMode;

  Darh_RoeStateType Call_RoeStatePort_GetRoeState_RoeState = 0U;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  (void)memset(&Write_ComControlModeRequestPort_requestedMode, 0, sizeof(Write_ComControlModeRequestPort_requestedMode));
  fct_status = TSC_StdDiag_Rte_Write_ComControlModeRequestPort_requestedMode(Write_ComControlModeRequestPort_requestedMode);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  ComControlNormalModeAccessPort_CommunicationModeDeclarationGroup = TSC_StdDiag_Rte_Mode_ComControlNormalModeAccessPort_CommunicationModeDeclarationGroup();
  ExtendedOperatingModeControlPort_currentExtendedOperatingMode = TSC_StdDiag_Rte_Mode_ExtendedOperatingModeControlPort_currentExtendedOperatingMode();
  OperatingModeControlPort_currentOperatingMode = TSC_StdDiag_Rte_Mode_OperatingModeControlPort_currentOperatingMode();

  fct_status = TSC_StdDiag_Rte_Call_RoeStatePort_GetRoeState(&Call_RoeStatePort_GetRoeState_RoeState);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_RoeStateInterface_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_StdDiag_Rte_Call_EnableConditionPort_SetEnableCondition(FALSE);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_EnableCondition_E_NOT_OK:
      fct_error = 1;
      break;
  }

  return RTE_E_ServiceRequestNotification_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ManufacturerIndication
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Indication> of PortPrototype <ServiceRequestManufacturerNotificationPort>
 *
 **********************************************************************************************************************
 *
 * Mode Interfaces:
 * ================
 *   Omc_OperatingModeType Rte_Mode_OperatingModeControlPort_currentOperatingMode(void)
 *   Modes of Rte_ModeType_OmcOperatingMode:
 *   - RTE_MODE_OmcOperatingMode_OMC_MODE_ASSEMBLY
 *   - RTE_MODE_OmcOperatingMode_OMC_MODE_BMW_FLASH
 *   - RTE_MODE_OmcOperatingMode_OMC_MODE_NORMAL
 *   - RTE_MODE_OmcOperatingMode_OMC_MODE_TRANSPORT
 *   - RTE_TRANSITION_OmcOperatingMode
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType StdDiag_ManufacturerIndication(uint8 SID, const uint8 *RequestData, uint16 DataSize, uint8 ReqType, uint16 SourceAddress, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument RequestData: uint8* is of type RequestDataArray
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_ServiceRequestNotification_E_NOT_OK
 *   RTE_E_ServiceRequestNotification_E_OK
 *   RTE_E_ServiceRequestNotification_E_REQUEST_NOT_ACCEPTED
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ManufacturerIndication_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, StdDiag_CODE) StdDiag_ManufacturerIndication(uint8 SID, P2CONST(uint8, AUTOMATIC, RTE_STDDIAG_APPL_DATA) RequestData, uint16 DataSize, uint8 ReqType, uint16 SourceAddress, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_STDDIAG_APPL_VAR) ErrorCode) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: StdDiag_ManufacturerIndication (returns application error)
 *********************************************************************************************************************/

  Rte_ModeType_OmcOperatingMode OperatingModeControlPort_currentOperatingMode;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  OperatingModeControlPort_currentOperatingMode = TSC_StdDiag_Rte_Mode_OperatingModeControlPort_currentOperatingMode();

  return RTE_E_ServiceRequestNotification_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: OpModeChangeCancelled
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <OpModeSwitchCancelled> of PortPrototype <AllowOpModeChangePort>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType StdDiag_OpModeChangeCancelled(Omc_OperatingModeType OperatingMode, Omc_ExtendedOperatingModeType ExtendedOperatingMode, Omc_OperatingModeType RequestedOperatingMode, Omc_ExtendedOperatingModeType RequestedExtendedOperatingMode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_OmcModesCallouts_E_OK
 *   RTE_E_OmcModesCallouts_E_RUNNING
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: OpModeChangeCancelled_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, StdDiag_CODE) StdDiag_OpModeChangeCancelled(Omc_OperatingModeType OperatingMode, Omc_ExtendedOperatingModeType ExtendedOperatingMode, Omc_OperatingModeType RequestedOperatingMode, Omc_ExtendedOperatingModeType RequestedExtendedOperatingMode) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: StdDiag_OpModeChangeCancelled (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ReadDataActiveSessionState
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <ActiveSessionState>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType StdDiag_ReadActiveSessionState(uint8 *Data)
 *     Argument Data: uint8* is of type ActiveSessionState_ArrayType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_ActiveSessionState_E_NOT_OK
 *   RTE_E_DataServices_ActiveSessionState_E_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ReadDataActiveSessionState_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, StdDiag_CODE) StdDiag_ReadActiveSessionState(P2VAR(uint8, AUTOMATIC, RTE_STDDIAG_APPL_VAR) Data) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: StdDiag_ReadActiveSessionState (returns application error)
 *********************************************************************************************************************/

  return RTE_E_DataServices_ActiveSessionState_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ReadDataSgbdIndex
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <SgbdIndex>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType StdDiag_ReadSgbdIndex(uint8 *Data)
 *     Argument Data: uint8* is of type SgbdIndex_ArrayType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_SgbdIndex_E_NOT_OK
 *   RTE_E_DataServices_SgbdIndex_E_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ReadDataSgbdIndex_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, StdDiag_CODE) StdDiag_ReadSgbdIndex(P2VAR(uint8, AUTOMATIC, RTE_STDDIAG_APPL_VAR) Data) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: StdDiag_ReadSgbdIndex (returns application error)
 *********************************************************************************************************************/

  return RTE_E_DataServices_SgbdIndex_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RoutineControlStartCheckProgrammingPreconditions
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <CheckProgrammingPreconditions>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType StdDiag_RoutineControlStartCheckProgrammingPreconditions(Dcm_OpStatusType OpStatus, uint8 *dataOut, uint16 *currentDataLength, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument dataOut: uint8* is of type CheckProgrammingPreconditions_ArrayType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_CheckProgrammingPreconditions_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_CheckProgrammingPreconditions_DCM_E_PENDING
 *   RTE_E_RoutineServices_CheckProgrammingPreconditions_E_NOT_OK
 *   RTE_E_RoutineServices_CheckProgrammingPreconditions_E_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineControlStartCheckProgrammingPreconditions_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, StdDiag_CODE) StdDiag_RoutineControlStartCheckProgrammingPreconditions(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_STDDIAG_APPL_VAR) dataOut, P2VAR(uint16, AUTOMATIC, RTE_STDDIAG_APPL_VAR) currentDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_STDDIAG_APPL_VAR) ErrorCode) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: StdDiag_RoutineControlStartCheckProgrammingPreconditions (returns application error)
 *********************************************************************************************************************/

  return RTE_E_RoutineServices_CheckProgrammingPreconditions_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RoutineControlStartClearDTCSecondaryErrorMemory
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <ClearSecondaryErrorMemory>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_ClearDTCPort_ClearDTC(uint32 DTC, Dem_DTCFormatType DTCFormat, Dem_DTCOriginType DTCOrigin)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_CddIf_DEM_CLEAR_BUSY, RTE_E_CddIf_DEM_CLEAR_FAILED, RTE_E_CddIf_DEM_CLEAR_MEMORY_ERROR, RTE_E_CddIf_DEM_CLEAR_PENDING, RTE_E_CddIf_DEM_CLEAR_WRONG_DTC, RTE_E_CddIf_DEM_CLEAR_WRONG_DTCORIGIN, RTE_E_CddIf_E_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType StdDiag_RoutineControlStartClearDTCSecondaryErrorMemory(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_ClearDTCSecondaryErrorMemory_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_ClearDTCSecondaryErrorMemory_DCM_E_PENDING
 *   RTE_E_RoutineServices_ClearDTCSecondaryErrorMemory_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineControlStartClearDTCSecondaryErrorMemory_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, StdDiag_CODE) StdDiag_RoutineControlStartClearDTCSecondaryErrorMemory(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_STDDIAG_APPL_VAR) ErrorCode) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: StdDiag_RoutineControlStartClearDTCSecondaryErrorMemory (returns application error)
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_StdDiag_Rte_Call_ClearDTCPort_ClearDTC(0U, 0U, 0U);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_CddIf_DEM_CLEAR_BUSY:
      fct_error = 1;
      break;
    case RTE_E_CddIf_DEM_CLEAR_FAILED:
      fct_error = 1;
      break;
    case RTE_E_CddIf_DEM_CLEAR_MEMORY_ERROR:
      fct_error = 1;
      break;
    case RTE_E_CddIf_DEM_CLEAR_PENDING:
      fct_error = 1;
      break;
    case RTE_E_CddIf_DEM_CLEAR_WRONG_DTC:
      fct_error = 1;
      break;
    case RTE_E_CddIf_DEM_CLEAR_WRONG_DTCORIGIN:
      fct_error = 1;
      break;
  }

  return RTE_E_RoutineServices_ClearDTCSecondaryErrorMemory_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RoutineControlStartDiagCommLoopback
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <DiagCommLoopback>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType StdDiag_RoutineControlStartDiagCommLoopback(const uint8 *dataIn, Dcm_OpStatusType OpStatus, uint8 *dataOut, uint16 *currentDataLength, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument dataIn: uint8* is of type DiagCommLoopback_ArrayType
 *     Argument dataOut: uint8* is of type DiagCommLoopback_ArrayType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_DiagCommLoopback_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_DiagCommLoopback_DCM_E_PENDING
 *   RTE_E_RoutineServices_DiagCommLoopback_E_NOT_OK
 *   RTE_E_RoutineServices_DiagCommLoopback_E_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineControlStartDiagCommLoopback_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, StdDiag_CODE) StdDiag_RoutineControlStartDiagCommLoopback(P2CONST(uint8, AUTOMATIC, RTE_STDDIAG_APPL_DATA) dataIn, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_STDDIAG_APPL_VAR) dataOut, P2VAR(uint16, AUTOMATIC, RTE_STDDIAG_APPL_VAR) currentDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_STDDIAG_APPL_VAR) ErrorCode) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: StdDiag_RoutineControlStartDiagCommLoopback (returns application error)
 *********************************************************************************************************************/

  return RTE_E_RoutineServices_DiagCommLoopback_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SessionChange_DefaultSession
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on entering of Mode <STDDIAG_DEFAULT_SESSION> of ModeDeclarationGroupPrototype <SessionModeDeclarationGroup> of PortPrototype <SessionChangeIndicationPort>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ComControlModeRequestPort_requestedMode(NormalCommunicationModeType data)
 *
 * Mode Interfaces:
 * ================
 *   NormalCommunicationModeType Rte_Mode_ComControlNormalModeAccessPort_CommunicationModeDeclarationGroup(void)
 *   Modes of Rte_ModeType_StdDiag_NormalCommunicationModeGroup:
 *   - RTE_MODE_StdDiag_NormalCommunicationModeGroup_DISABLE_RX_AND_TX_NORMAL
 *   - RTE_MODE_StdDiag_NormalCommunicationModeGroup_DISABLE_RX_ENABLE_TX_NORMAL
 *   - RTE_MODE_StdDiag_NormalCommunicationModeGroup_ENABLE_RX_AND_TX_NORMAL
 *   - RTE_MODE_StdDiag_NormalCommunicationModeGroup_ENABLE_RX_DISABLE_TX_NORMAL
 *   - RTE_TRANSITION_StdDiag_NormalCommunicationModeGroup
 *   Omc_ExtendedOperatingModeType Rte_Mode_ExtendedOperatingModeControlPort_currentExtendedOperatingMode(void)
 *   Modes of Rte_ModeType_OmcExtendedOperatingMode:
 *   - RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_1
 *   - RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_10
 *   - RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_11
 *   - RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_12
 *   - RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_13
 *   - RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_14
 *   - RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_2
 *   - RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_3
 *   - RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_4
 *   - RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_5
 *   - RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_6
 *   - RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_7
 *   - RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_8
 *   - RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_9
 *   - RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_INVALID
 *   - RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_NORMAL
 *   - RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_SAVE_ENERGY
 *   - RTE_TRANSITION_OmcExtendedOperatingMode
 *   Omc_OperatingModeType Rte_Mode_OperatingModeControlPort_currentOperatingMode(void)
 *   Modes of Rte_ModeType_OmcOperatingMode:
 *   - RTE_MODE_OmcOperatingMode_OMC_MODE_ASSEMBLY
 *   - RTE_MODE_OmcOperatingMode_OMC_MODE_BMW_FLASH
 *   - RTE_MODE_OmcOperatingMode_OMC_MODE_NORMAL
 *   - RTE_MODE_OmcOperatingMode_OMC_MODE_TRANSPORT
 *   - RTE_TRANSITION_OmcOperatingMode
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_RoeStatePort_GetRoeState(Darh_RoeStateType *RoeState)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_RoeStateInterface_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_EnableConditionPort_SetEnableCondition(boolean ConditionFulfilled)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EnableCondition_E_NOT_OK, RTE_E_EnableCondition_E_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: SessionChange_DefaultSession_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, StdDiag_CODE) StdDiag_SesChgIndication_DefaultSession(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: StdDiag_SesChgIndication_DefaultSession
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  NormalCommunicationModeType Write_ComControlModeRequestPort_requestedMode;

  Rte_ModeType_StdDiag_NormalCommunicationModeGroup ComControlNormalModeAccessPort_CommunicationModeDeclarationGroup;
  Rte_ModeType_OmcExtendedOperatingMode ExtendedOperatingModeControlPort_currentExtendedOperatingMode;
  Rte_ModeType_OmcOperatingMode OperatingModeControlPort_currentOperatingMode;

  Darh_RoeStateType Call_RoeStatePort_GetRoeState_RoeState = 0U;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  (void)memset(&Write_ComControlModeRequestPort_requestedMode, 0, sizeof(Write_ComControlModeRequestPort_requestedMode));
  fct_status = TSC_StdDiag_Rte_Write_ComControlModeRequestPort_requestedMode(Write_ComControlModeRequestPort_requestedMode);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  ComControlNormalModeAccessPort_CommunicationModeDeclarationGroup = TSC_StdDiag_Rte_Mode_ComControlNormalModeAccessPort_CommunicationModeDeclarationGroup();
  ExtendedOperatingModeControlPort_currentExtendedOperatingMode = TSC_StdDiag_Rte_Mode_ExtendedOperatingModeControlPort_currentExtendedOperatingMode();
  OperatingModeControlPort_currentOperatingMode = TSC_StdDiag_Rte_Mode_OperatingModeControlPort_currentOperatingMode();

  fct_status = TSC_StdDiag_Rte_Call_RoeStatePort_GetRoeState(&Call_RoeStatePort_GetRoeState_RoeState);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_RoeStateInterface_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_StdDiag_Rte_Call_EnableConditionPort_SetEnableCondition(FALSE);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_EnableCondition_E_NOT_OK:
      fct_error = 1;
      break;
  }


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SessionChange_OtherSession
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on entering of Mode <STDDIAG_OTHER_SESSION> of ModeDeclarationGroupPrototype <SessionModeDeclarationGroup> of PortPrototype <SessionChangeIndicationPort>
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: SessionChange_OtherSession_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, StdDiag_CODE) StdDiag_SesChgIndication_OtherSession(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: StdDiag_SesChgIndication_OtherSession
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define StdDiag_STOP_SEC_CODE
#include "StdDiag_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void StdDiag_TestDefines(void)
{
  /* Enumeration Data Types */

  Darh_RoeStateType Test_Darh_RoeStateType_V_1 = DARH_ROE_STOPPED;
  Darh_RoeStateType Test_Darh_RoeStateType_V_2 = DARH_ROE_STARTED;
  Darh_RoeStateType Test_Darh_RoeStateType_V_3 = DARH_ROE_UNKNOWN;

  Dcm_ConfirmationStatusType Test_Dcm_ConfirmationStatusType_V_1 = DCM_RES_POS_OK;
  Dcm_ConfirmationStatusType Test_Dcm_ConfirmationStatusType_V_2 = DCM_RES_POS_NOT_OK;
  Dcm_ConfirmationStatusType Test_Dcm_ConfirmationStatusType_V_3 = DCM_RES_NEG_OK;
  Dcm_ConfirmationStatusType Test_Dcm_ConfirmationStatusType_V_4 = DCM_RES_NEG_NOT_OK;

  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_1 = DCM_E_BRAKESWITCH_NOTCLOSED;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_2 = DCM_E_BUSYREPEATREQUEST;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_3 = DCM_E_CONDITIONSNOTCORRECT;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_4 = DCM_E_ENGINEISNOTRUNNING;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_5 = DCM_E_ENGINEISRUNNING;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_6 = DCM_E_ENGINERUNTIMETOOLOW;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_7 = DCM_E_EXCEEDNUMBEROFATTEMPTS;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_8 = DCM_E_FAILUREPREVENTSEXECUTIONOFREQUESTEDACTION;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_9 = DCM_E_GENERALPROGRAMMINGFAILURE;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_10 = DCM_E_GENERALREJECT;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_11 = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_12 = DCM_E_INVALIDKEY;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_13 = DCM_E_NORESPONSEFROMSUBNETCOMPONENT;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_14 = DCM_E_REQUESTOUTOFRANGE;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_15 = DCM_E_REQUESTSEQUENCEERROR;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_16 = DCM_E_REQUIREDTIMEDELAYNOTEXPIRED;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_17 = DCM_E_RESPONSETOOLONG;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_18 = DCM_E_RPMTOOHIGH;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_19 = DCM_E_RPMTOOLOW;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_20 = DCM_E_SECURITYACCESSDENIED;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_21 = DCM_E_SERVICENOTSUPPORTED;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_22 = DCM_E_SERVICENOTSUPPORTEDINACTIVESESSION;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_23 = DCM_E_SHIFTERLEVERNOTINPARK;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_24 = DCM_E_SUBFUNCTIONNOTSUPPORTED;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_25 = DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_26 = DCM_E_TEMPERATURETOOHIGH;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_27 = DCM_E_TEMPERATURETOOLOW;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_28 = DCM_E_THROTTLE_PEDALTOOHIGH;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_29 = DCM_E_THROTTLE_PEDALTOOLOW;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_30 = DCM_E_TORQUECONVERTERCLUTCHLOCKED;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_31 = DCM_E_TRANSFERDATASUSPENDED;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_32 = DCM_E_TRANSMISSIONRANGENOTINGEAR;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_33 = DCM_E_TRANSMISSIONRANGENOTINNEUTRAL;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_34 = DCM_E_UPLOADDOWNLOADNOTACCEPTED;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_35 = DCM_E_VEHICLESPEEDTOOHIGH;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_36 = DCM_E_VEHICLESPEEDTOOLOW;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_37 = DCM_E_VOLTAGETOOHIGH;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_38 = DCM_E_VOLTAGETOOLOW;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_39 = DCM_E_WRONGBLOCKSEQUENCECOUNTER;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_40 = DCM_E_VMSCNC_0;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_41 = DCM_E_VMSCNC_1;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_42 = DCM_E_VMSCNC_2;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_43 = DCM_E_VMSCNC_3;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_44 = DCM_E_VMSCNC_4;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_45 = DCM_E_VMSCNC_5;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_46 = DCM_E_VMSCNC_6;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_47 = DCM_E_VMSCNC_7;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_48 = DCM_E_VMSCNC_8;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_49 = DCM_E_VMSCNC_9;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_50 = DCM_E_VMSCNC_A;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_51 = DCM_E_VMSCNC_B;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_52 = DCM_E_VMSCNC_C;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_53 = DCM_E_VMSCNC_D;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_54 = DCM_E_VMSCNC_E;

  Dcm_OpStatusType Test_Dcm_OpStatusType_V_1 = DCM_INITIAL;
  Dcm_OpStatusType Test_Dcm_OpStatusType_V_2 = DCM_PENDING;
  Dcm_OpStatusType Test_Dcm_OpStatusType_V_3 = DCM_CANCEL;
  Dcm_OpStatusType Test_Dcm_OpStatusType_V_4 = DCM_FORCE_RCRRP_OK;

  Dcm_SesCtrlType Test_Dcm_SesCtrlType_V_1 = DCM_DEFAULT_SESSION;
  Dcm_SesCtrlType Test_Dcm_SesCtrlType_V_2 = DCM_PROGRAMMING_SESSION;
  Dcm_SesCtrlType Test_Dcm_SesCtrlType_V_3 = DCM_EXTENDED_DIAGNOSTIC_SESSION;
  Dcm_SesCtrlType Test_Dcm_SesCtrlType_V_4 = DCM_SAFETY_SYSTEM_DIAGNOSTIC_SESSION;
  Dcm_SesCtrlType Test_Dcm_SesCtrlType_V_5 = DCM_CODING_SESSION;
  Dcm_SesCtrlType Test_Dcm_SesCtrlType_V_6 = DCM_SWT_SESSION;

  Dem_DTCFormatType Test_Dem_DTCFormatType_V_1 = DEM_DTC_FORMAT_OBD;
  Dem_DTCFormatType Test_Dem_DTCFormatType_V_2 = DEM_DTC_FORMAT_UDS;
  Dem_DTCFormatType Test_Dem_DTCFormatType_V_3 = DEM_DTC_FORMAT_J1939;

  Dem_DTCOriginType Test_Dem_DTCOriginType_V_1 = DEM_DTC_ORIGIN_PRIMARY_MEMORY;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_2 = DEM_DTC_ORIGIN_MIRROR_MEMORY;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_3 = DEM_DTC_ORIGIN_PERMANENT_MEMORY;
  Dem_DTCOriginType Test_Dem_DTCOriginType_V_4 = DEM_DTC_ORIGIN_USERDEFINED_MEMORY_BMWSecondaryErrorMemory;

  NormalCommunicationModeType Test_NormalCommunicationModeType_V_1 = DISABLE_RX_AND_TX_NORMAL;
  NormalCommunicationModeType Test_NormalCommunicationModeType_V_2 = DISABLE_RX_ENABLE_TX_NORMAL;
  NormalCommunicationModeType Test_NormalCommunicationModeType_V_3 = ENABLE_RX_AND_TX_NORMAL;
  NormalCommunicationModeType Test_NormalCommunicationModeType_V_4 = ENABLE_RX_DISABLE_TX_NORMAL;

  Omc_ExtendedOperatingModeType Test_Omc_ExtendedOperatingModeType_V_1 = OMC_MODE_EXTENSION_NORMAL;
  Omc_ExtendedOperatingModeType Test_Omc_ExtendedOperatingModeType_V_2 = OMC_MODE_EXTENSION_1;
  Omc_ExtendedOperatingModeType Test_Omc_ExtendedOperatingModeType_V_3 = OMC_MODE_EXTENSION_2;
  Omc_ExtendedOperatingModeType Test_Omc_ExtendedOperatingModeType_V_4 = OMC_MODE_EXTENSION_3;
  Omc_ExtendedOperatingModeType Test_Omc_ExtendedOperatingModeType_V_5 = OMC_MODE_EXTENSION_4;
  Omc_ExtendedOperatingModeType Test_Omc_ExtendedOperatingModeType_V_6 = OMC_MODE_EXTENSION_5;
  Omc_ExtendedOperatingModeType Test_Omc_ExtendedOperatingModeType_V_7 = OMC_MODE_EXTENSION_6;
  Omc_ExtendedOperatingModeType Test_Omc_ExtendedOperatingModeType_V_8 = OMC_MODE_EXTENSION_7;
  Omc_ExtendedOperatingModeType Test_Omc_ExtendedOperatingModeType_V_9 = OMC_MODE_EXTENSION_8;
  Omc_ExtendedOperatingModeType Test_Omc_ExtendedOperatingModeType_V_10 = OMC_MODE_EXTENSION_9;
  Omc_ExtendedOperatingModeType Test_Omc_ExtendedOperatingModeType_V_11 = OMC_MODE_EXTENSION_10;
  Omc_ExtendedOperatingModeType Test_Omc_ExtendedOperatingModeType_V_12 = OMC_MODE_EXTENSION_11;
  Omc_ExtendedOperatingModeType Test_Omc_ExtendedOperatingModeType_V_13 = OMC_MODE_EXTENSION_12;
  Omc_ExtendedOperatingModeType Test_Omc_ExtendedOperatingModeType_V_14 = OMC_MODE_EXTENSION_13;
  Omc_ExtendedOperatingModeType Test_Omc_ExtendedOperatingModeType_V_15 = OMC_MODE_EXTENSION_14;
  Omc_ExtendedOperatingModeType Test_Omc_ExtendedOperatingModeType_V_16 = OMC_MODE_EXTENSION_SAVE_ENERGY;
  Omc_ExtendedOperatingModeType Test_Omc_ExtendedOperatingModeType_V_17 = OMC_MODE_EXTENSION_INVALID;

  Omc_OperatingModeType Test_Omc_OperatingModeType_V_1 = OMC_MODE_NORMAL;
  Omc_OperatingModeType Test_Omc_OperatingModeType_V_2 = OMC_MODE_ASSEMBLY;
  Omc_OperatingModeType Test_Omc_OperatingModeType_V_3 = OMC_MODE_TRANSPORT;
  Omc_OperatingModeType Test_Omc_OperatingModeType_V_4 = OMC_MODE_BMW_FLASH;

  StdDiag_LifeCycleRequestType Test_StdDiag_LifeCycleRequestType_V_1 = STDDIAG_INITIALIZED;
  StdDiag_LifeCycleRequestType Test_StdDiag_LifeCycleRequestType_V_2 = STDDIAG_RUNNING;
  StdDiag_LifeCycleRequestType Test_StdDiag_LifeCycleRequestType_V_3 = STDDIAG_STOPPED;

  Stm_VehicleStateType Test_Stm_VehicleStateType_V_1 = STM_VEHICLE_STATE_PARKING_BN_NOK;
  Stm_VehicleStateType Test_Stm_VehicleStateType_V_2 = STM_VEHICLE_STATE_PARKING_BN_OK;
  Stm_VehicleStateType Test_Stm_VehicleStateType_V_3 = STM_VEHICLE_STATE_CUSTOMER_ABSENT;
  Stm_VehicleStateType Test_Stm_VehicleStateType_V_4 = STM_VEHICLE_STATE_LIVING;
  Stm_VehicleStateType Test_Stm_VehicleStateType_V_5 = STM_VEHICLE_STATE_CHECK_ANALYS_DIAGNOSTICS;
  Stm_VehicleStateType Test_Stm_VehicleStateType_V_6 = STM_VEHICLE_STATE_READINESS_TO_DRIVE_INIT;
  Stm_VehicleStateType Test_Stm_VehicleStateType_V_7 = STM_VEHICLE_STATE_DRIVE;
  Stm_VehicleStateType Test_Stm_VehicleStateType_V_8 = STM_VEHICLE_STATE_READINESS_TO_DRIVE_STOP;
  Stm_VehicleStateType Test_Stm_VehicleStateType_V_9 = STM_VEHICLE_STATE_UNAVAILABLE;
  Stm_VehicleStateType Test_Stm_VehicleStateType_V_10 = STM_VEHICLE_STATE_INVALID;

  /* Modes */

  Omc_ExtendedOperatingModeType Test_OmcExtendedOperatingMode_MV_1 = RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_NORMAL;
  Omc_ExtendedOperatingModeType Test_OmcExtendedOperatingMode_MV_2 = RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_1;
  Omc_ExtendedOperatingModeType Test_OmcExtendedOperatingMode_MV_3 = RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_2;
  Omc_ExtendedOperatingModeType Test_OmcExtendedOperatingMode_MV_4 = RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_3;
  Omc_ExtendedOperatingModeType Test_OmcExtendedOperatingMode_MV_5 = RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_4;
  Omc_ExtendedOperatingModeType Test_OmcExtendedOperatingMode_MV_6 = RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_5;
  Omc_ExtendedOperatingModeType Test_OmcExtendedOperatingMode_MV_7 = RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_6;
  Omc_ExtendedOperatingModeType Test_OmcExtendedOperatingMode_MV_8 = RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_7;
  Omc_ExtendedOperatingModeType Test_OmcExtendedOperatingMode_MV_9 = RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_8;
  Omc_ExtendedOperatingModeType Test_OmcExtendedOperatingMode_MV_10 = RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_9;
  Omc_ExtendedOperatingModeType Test_OmcExtendedOperatingMode_MV_11 = RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_10;
  Omc_ExtendedOperatingModeType Test_OmcExtendedOperatingMode_MV_12 = RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_11;
  Omc_ExtendedOperatingModeType Test_OmcExtendedOperatingMode_MV_13 = RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_12;
  Omc_ExtendedOperatingModeType Test_OmcExtendedOperatingMode_MV_14 = RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_13;
  Omc_ExtendedOperatingModeType Test_OmcExtendedOperatingMode_MV_15 = RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_14;
  Omc_ExtendedOperatingModeType Test_OmcExtendedOperatingMode_MV_16 = RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_SAVE_ENERGY;
  Omc_ExtendedOperatingModeType Test_OmcExtendedOperatingMode_MV_17 = RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_INVALID;
  Omc_ExtendedOperatingModeType Test_OmcExtendedOperatingMode_TV = RTE_TRANSITION_OmcExtendedOperatingMode;

  Omc_OperatingModeType Test_OmcOperatingMode_MV_1 = RTE_MODE_OmcOperatingMode_OMC_MODE_NORMAL;
  Omc_OperatingModeType Test_OmcOperatingMode_MV_2 = RTE_MODE_OmcOperatingMode_OMC_MODE_ASSEMBLY;
  Omc_OperatingModeType Test_OmcOperatingMode_MV_3 = RTE_MODE_OmcOperatingMode_OMC_MODE_TRANSPORT;
  Omc_OperatingModeType Test_OmcOperatingMode_MV_4 = RTE_MODE_OmcOperatingMode_OMC_MODE_BMW_FLASH;
  Omc_OperatingModeType Test_OmcOperatingMode_TV = RTE_TRANSITION_OmcOperatingMode;

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

  Stm_VehicleStateType Test_Stm_VehicleStateMode_MV_1 = RTE_MODE_Stm_VehicleStateMode_STM_VEHICLE_STATE_CHECK_ANALYS_DIAGNOSTICS;
  Stm_VehicleStateType Test_Stm_VehicleStateMode_MV_2 = RTE_MODE_Stm_VehicleStateMode_STM_VEHICLE_STATE_CUSTOMER_ABSENT;
  Stm_VehicleStateType Test_Stm_VehicleStateMode_MV_3 = RTE_MODE_Stm_VehicleStateMode_STM_VEHICLE_STATE_DRIVE;
  Stm_VehicleStateType Test_Stm_VehicleStateMode_MV_4 = RTE_MODE_Stm_VehicleStateMode_STM_VEHICLE_STATE_INVALID;
  Stm_VehicleStateType Test_Stm_VehicleStateMode_MV_5 = RTE_MODE_Stm_VehicleStateMode_STM_VEHICLE_STATE_LIVING;
  Stm_VehicleStateType Test_Stm_VehicleStateMode_MV_6 = RTE_MODE_Stm_VehicleStateMode_STM_VEHICLE_STATE_PARKING_BN_NOK;
  Stm_VehicleStateType Test_Stm_VehicleStateMode_MV_7 = RTE_MODE_Stm_VehicleStateMode_STM_VEHICLE_STATE_PARKING_BN_OK;
  Stm_VehicleStateType Test_Stm_VehicleStateMode_MV_8 = RTE_MODE_Stm_VehicleStateMode_STM_VEHICLE_STATE_READINESS_TO_DRIVE_INIT;
  Stm_VehicleStateType Test_Stm_VehicleStateMode_MV_9 = RTE_MODE_Stm_VehicleStateMode_STM_VEHICLE_STATE_READINESS_TO_DRIVE_STOP;
  Stm_VehicleStateType Test_Stm_VehicleStateMode_MV_10 = RTE_MODE_Stm_VehicleStateMode_STM_VEHICLE_STATE_UNAVAILABLE;
  Stm_VehicleStateType Test_Stm_VehicleStateMode_TV = RTE_TRANSITION_Stm_VehicleStateMode;
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
