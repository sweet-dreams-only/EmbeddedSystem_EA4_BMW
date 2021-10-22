/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Darh.c
 *        Config:  EPS.dpa
 *     SW-C Type:  Darh
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <Darh>
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
 * Darh_LifeCycleRequestType
 *   
 *
 * Darh_RoeStateType
 *   
 *
 * Darh_SuspendedStateType
 *   
 *
 * Dcm_NegativeResponseCodeType
 *   
 *
 * Dcm_OpStatusType
 *   
 *
 * Dem_DTCFormatType
 *   
 *
 * Dem_EventIdType
 *   
 *
 * Dem_EventStatusType
 *   
 *
 * NvM_RequestResultType
 *   
 *
 *********************************************************************************************************************/

#include "Rte_Darh.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_Darh.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"

static void Darh_TestDefines(void);


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
 * Dem_EventIdType: Integer in interval [1...72]
 * NvM_SrcPtrType: DataReference
 * boolean: Boolean (standard type)
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * Darh_LifeCycleRequestType: Enumeration of integer in interval [0...255] with enumerators
 *   DARH_INITIALIZED (0U)
 *   DARH_RUNNING (1U)
 *   DARH_STOPPED (2U)
 * Darh_RoeStateType: Enumeration of integer in interval [0...255] with enumerators
 *   DARH_ROE_STOPPED (0U)
 *   DARH_ROE_STARTED (1U)
 *   DARH_ROE_UNKNOWN (2U)
 * Darh_SuspendedStateType: Enumeration of integer in interval [0...255] with enumerators
 *   DARH_NOT_SUSPENDED (0U)
 *   DARH_SUSPENDED (1U)
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
 * Dem_DTCFormatType: Enumeration of integer in interval [0...2] with enumerators
 *   DEM_DTC_FORMAT_OBD (0U)
 *   DEM_DTC_FORMAT_UDS (1U)
 *   DEM_DTC_FORMAT_J1939 (2U)
 * Dem_EventStatusType: Enumeration of integer in interval [0...4] with enumerators
 *   DEM_EVENT_STATUS_PASSED (0U)
 *   DEM_EVENT_STATUS_FAILED (1U)
 *   DEM_EVENT_STATUS_PREPASSED (2U)
 *   DEM_EVENT_STATUS_PREFAILED (3U)
 *   DEM_EVENT_STATUS_FDC_THRESHOLD_REACHED (4U)
 * NvM_RequestResultType: Enumeration of integer in interval [0...8] with enumerators
 *   NVM_REQ_OK (0U)
 *   NVM_REQ_NOT_OK (1U)
 *   NVM_REQ_PENDING (2U)
 *   NVM_REQ_INTEGRITY_FAILED (3U)
 *   NVM_REQ_BLOCK_SKIPPED (4U)
 *   NVM_REQ_NV_INVALIDATED (5U)
 *   NVM_REQ_CANCELED (6U)
 *   NVM_REQ_REDUNDANCY_FAILED (7U)
 *   NVM_REQ_RESTORED_FROM_ROM (8U)
 *
 * Array Types:
 * ============
 * Darh_ActivelyReportedErrorListType: Array with 39 element(s) of type uint8
 * Dem_MaxDataValueType: Array with 4 element(s) of type uint8
 * Rte_DT_Darh_TransmissionArrayType_1: Array with 23 element(s) of type uint8
 *
 * Record Types:
 * =============
 * Darh_TransmissionArrayType: Record with elements
 *   size of type uint16
 *   payload of type Rte_DT_Darh_TransmissionArrayType_1
 *
 *********************************************************************************************************************/


#define Darh_START_SEC_CODE
#include "Darh_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ConditionCheckRead
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * This runnable is never executed by the RTE.
 *
 **********************************************************************************************************************
 *
 * Mode Interfaces:
 * ================
 *   Darh_LifeCycleRequestType Rte_Mode_LifeCycle_Mode(Darh_LifeCycleRequestType *previousMode, Darh_LifeCycleRequestType *nextMode)
 *   Modes of Rte_ModeType_Darh_LifeCycle:
 *   - RTE_MODE_Darh_LifeCycle_DARH_INITIALIZED
 *   - RTE_MODE_Darh_LifeCycle_DARH_RUNNING
 *   - RTE_MODE_Darh_LifeCycle_DARH_STOPPED
 *   - RTE_TRANSITION_Darh_LifeCycle
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ConditionCheckRead_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Darh_CODE) Darh_ConditionCheckReadErrorQueueHandler(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Darh_ConditionCheckReadErrorQueueHandler
 *********************************************************************************************************************/

  Rte_ModeType_Darh_LifeCycle LifeCycle_Mode;
  Rte_ModeType_Darh_LifeCycle LifeCycle_Mode_previousMode;
  Rte_ModeType_Darh_LifeCycle LifeCycle_Mode_nextMode;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  LifeCycle_Mode = TSC_Darh_Rte_Mode_LifeCycle_Mode(&LifeCycle_Mode_previousMode, &LifeCycle_Mode_nextMode);

  Darh_TestDefines();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ConditionCheckReadActivelyReportedDtc
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DmIsDtcActiveResponse>
 *
 **********************************************************************************************************************
 *
 * Mode Interfaces:
 * ================
 *   Darh_LifeCycleRequestType Rte_Mode_LifeCycle_Mode(Darh_LifeCycleRequestType *previousMode, Darh_LifeCycleRequestType *nextMode)
 *   Modes of Rte_ModeType_Darh_LifeCycle:
 *   - RTE_MODE_Darh_LifeCycle_DARH_INITIALIZED
 *   - RTE_MODE_Darh_LifeCycle_DARH_RUNNING
 *   - RTE_MODE_Darh_LifeCycle_DARH_STOPPED
 *   - RTE_TRANSITION_Darh_LifeCycle
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Darh_ConditionCheckReadActivelyReportedDtcHandler(Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_ActivelyReportedDtc_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ConditionCheckReadActivelyReportedDtc_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Darh_CODE) Darh_ConditionCheckReadActivelyReportedDtcHandler(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DARH_APPL_VAR) ErrorCode) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Darh_ConditionCheckReadActivelyReportedDtcHandler (returns application error)
 *********************************************************************************************************************/

  Rte_ModeType_Darh_LifeCycle LifeCycle_Mode;
  Rte_ModeType_Darh_LifeCycle LifeCycle_Mode_previousMode;
  Rte_ModeType_Darh_LifeCycle LifeCycle_Mode_nextMode;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  LifeCycle_Mode = TSC_Darh_Rte_Mode_LifeCycle_Mode(&LifeCycle_Mode_previousMode, &LifeCycle_Mode_nextMode);

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: EventDataChanged
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <EventDataChanged> of PortPrototype <EventDataChangedPort>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_ReportDynamicallyEventPort_EventToReport(Dem_EventIdType event, boolean *toReport)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DarhReportDynamicallyEvent_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_ErrorQueueBlock_SetRamBlockStatus(boolean BlockChanged)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Darh_NvMService_E_NOT_OK
 *   Std_ReturnType Rte_Call_GeneralDiagnosticInfoPort_GetEventFreezeFrameData(Dem_EventIdType EventId, uint8 RecordNumber, boolean ReportTotalRecord, uint16 DataId, uint8 *DestBuffer)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Darh_GeneralDiagnosticInfo_DEM_E_NODATAAVAILABLE, RTE_E_Darh_GeneralDiagnosticInfo_DEM_E_WRONG_DIDNUMBER, RTE_E_Darh_GeneralDiagnosticInfo_DEM_E_WRONG_RECORDNUMBER, RTE_E_Darh_GeneralDiagnosticInfo_E_NOT_OK
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_ExclusiveArea_0(void)
 *   void Rte_Exit_ExclusiveArea_0(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void Darh_EventDataChangedHandler(Dem_EventIdType EventId)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: EventDataChanged_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Darh_CODE) Darh_EventDataChangedHandler(Dem_EventIdType EventId) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Darh_EventDataChangedHandler
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  boolean Call_ReportDynamicallyEventPort_EventToReport_toReport = FALSE;

  Dem_MaxDataValueType Call_GeneralDiagnosticInfoPort_GetEventFreezeFrameData_DestBuffer = {
  0U, 0U, 0U, 0U
};

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_Darh_Rte_Call_ReportDynamicallyEventPort_EventToReport(0U, &Call_ReportDynamicallyEventPort_EventToReport_toReport);
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
    case RTE_E_DarhReportDynamicallyEvent_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Darh_Rte_Call_ErrorQueueBlock_SetRamBlockStatus(FALSE);
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
    case RTE_E_Darh_NvMService_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Darh_Rte_Call_GeneralDiagnosticInfoPort_GetEventFreezeFrameData(0U, 0U, FALSE, 0U, Call_GeneralDiagnosticInfoPort_GetEventFreezeFrameData_DestBuffer);
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
    case RTE_E_Darh_GeneralDiagnosticInfo_DEM_E_NODATAAVAILABLE:
      fct_error = 1;
      break;
    case RTE_E_Darh_GeneralDiagnosticInfo_DEM_E_WRONG_DIDNUMBER:
      fct_error = 1;
      break;
    case RTE_E_Darh_GeneralDiagnosticInfo_DEM_E_WRONG_RECORDNUMBER:
      fct_error = 1;
      break;
    case RTE_E_Darh_GeneralDiagnosticInfo_E_NOT_OK:
      fct_error = 1;
      break;
  }

  TSC_Darh_Rte_Enter_ExclusiveArea_0();
  TSC_Darh_Rte_Exit_ExclusiveArea_0();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: GetRoeState
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetRoeState> of PortPrototype <RoeStatePort>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_ExclusiveArea_0(void)
 *   void Rte_Exit_ExclusiveArea_0(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Darh_ReadRoeStateDataHandler(Darh_RoeStateType *RoeState)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoeStateInterface_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: GetRoeState_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Darh_CODE) Darh_ReadRoeStateDataHandler(P2VAR(Darh_RoeStateType, AUTOMATIC, RTE_DARH_APPL_VAR) RoeState) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Darh_ReadRoeStateDataHandler (returns application error)
 *********************************************************************************************************************/

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  TSC_Darh_Rte_Enter_ExclusiveArea_0();
  TSC_Darh_Rte_Exit_ExclusiveArea_0();

  return RTE_E_OK;

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
 *   Darh_LifeCycleRequestType Rte_IRead_LifeCycleHandler_LifeCycleRequest_requestMode(void)
 *
 * Mode Interfaces:
 * ================
 *   Std_ReturnType Rte_Switch_LifeCycle_Mode(Darh_LifeCycleRequestType mode)
 *   Modes of Rte_ModeType_Darh_LifeCycle:
 *   - RTE_MODE_Darh_LifeCycle_DARH_INITIALIZED
 *   - RTE_MODE_Darh_LifeCycle_DARH_RUNNING
 *   - RTE_MODE_Darh_LifeCycle_DARH_STOPPED
 *   - RTE_TRANSITION_Darh_LifeCycle
 *   Darh_LifeCycleRequestType Rte_Mode_LifeCycle_Mode(Darh_LifeCycleRequestType *previousMode, Darh_LifeCycleRequestType *nextMode)
 *   Modes of Rte_ModeType_Darh_LifeCycle:
 *   - RTE_MODE_Darh_LifeCycle_DARH_INITIALIZED
 *   - RTE_MODE_Darh_LifeCycle_DARH_RUNNING
 *   - RTE_MODE_Darh_LifeCycle_DARH_STOPPED
 *   - RTE_TRANSITION_Darh_LifeCycle
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_ExclusiveArea_0(void)
 *   void Rte_Exit_ExclusiveArea_0(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: LifeCycleHandler_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Darh_CODE) Darh_LifeCycleHandler(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Darh_LifeCycleHandler
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  Darh_LifeCycleRequestType IRead_LifeCycleRequest_requestMode;

  Rte_ModeType_Darh_LifeCycle LifeCycle_Mode;
  Rte_ModeType_Darh_LifeCycle LifeCycle_Mode_previousMode;
  Rte_ModeType_Darh_LifeCycle LifeCycle_Mode_nextMode;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  IRead_LifeCycleRequest_requestMode = TSC_Darh_Rte_IRead_LifeCycleHandler_LifeCycleRequest_requestMode();

  fct_status = TSC_Darh_Rte_Switch_LifeCycle_Mode(RTE_MODE_Darh_LifeCycle_DARH_STOPPED);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  LifeCycle_Mode = TSC_Darh_Rte_Mode_LifeCycle_Mode(&LifeCycle_Mode_previousMode, &LifeCycle_Mode_nextMode);

  TSC_Darh_Rte_Enter_ExclusiveArea_0();
  TSC_Darh_Rte_Exit_ExclusiveArea_0();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: QueueHandler
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 1s
 *     and not in Mode(s) <DARH_INITIALIZED, DARH_STOPPED>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_Com_data(const Darh_TransmissionArrayType *data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_ExclusiveArea_0(void)
 *   void Rte_Exit_ExclusiveArea_0(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: QueueHandler_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Darh_CODE) Darh_ErrorQueueHandler(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Darh_ErrorQueueHandler
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  Darh_TransmissionArrayType Write_Com_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  (void)memset(&Write_Com_data, 0, sizeof(Write_Com_data));
  fct_status = TSC_Darh_Rte_Write_Com_data(&Write_Com_data);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  TSC_Darh_Rte_Enter_ExclusiveArea_0();
  TSC_Darh_Rte_Exit_ExclusiveArea_0();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ReadActivelyReportedDtc
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DmIsDtcActiveResponse>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_ReportDynamicallyEventPort_EventIdx2EventId(uint16 eventIdx, Dem_EventIdType *eventId)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DarhReportDynamicallyEvent_E_NOT_OK
 *   Std_ReturnType Rte_Call_ReportDynamicallyEventPort_EventToReport(Dem_EventIdType event, boolean *toReport)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DarhReportDynamicallyEvent_E_NOT_OK
 *   Std_ReturnType Rte_Call_ReportDynamicallyEventPort_EventToReportCount(uint16 *eventCount)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DarhReportDynamicallyEvent_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_GeneralDiagnosticInfoPort_GetDTCOfEvent(Dem_EventIdType EventId, Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Darh_GeneralDiagnosticInfo_DEM_E_NO_DTC_AVAILABLE, RTE_E_Darh_GeneralDiagnosticInfo_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Darh_ReadActivelyReportedDtcDataHandler(uint8 *Data)
 *     Argument Data: uint8* is of type Darh_ActivelyReportedErrorListType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_ActivelyReportedDtc_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ReadActivelyReportedDtc_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Darh_CODE) Darh_ReadActivelyReportedDtcDataHandler(P2VAR(uint8, AUTOMATIC, RTE_DARH_APPL_VAR) Data) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Darh_ReadActivelyReportedDtcDataHandler (returns application error)
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  Dem_EventIdType Call_ReportDynamicallyEventPort_EventIdx2EventId_eventId = 0U;
  boolean Call_ReportDynamicallyEventPort_EventToReport_toReport = FALSE;
  uint16 Call_ReportDynamicallyEventPort_EventToReportCount_eventCount = 0U;

  uint32 Call_GeneralDiagnosticInfoPort_GetDTCOfEvent_DTCOfEvent = 0U;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_Darh_Rte_Call_ReportDynamicallyEventPort_EventIdx2EventId(0U, &Call_ReportDynamicallyEventPort_EventIdx2EventId_eventId);
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
    case RTE_E_DarhReportDynamicallyEvent_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Darh_Rte_Call_ReportDynamicallyEventPort_EventToReport(0U, &Call_ReportDynamicallyEventPort_EventToReport_toReport);
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
    case RTE_E_DarhReportDynamicallyEvent_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Darh_Rte_Call_ReportDynamicallyEventPort_EventToReportCount(&Call_ReportDynamicallyEventPort_EventToReportCount_eventCount);
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
    case RTE_E_DarhReportDynamicallyEvent_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Darh_Rte_Call_GeneralDiagnosticInfoPort_GetDTCOfEvent(0U, 0U, &Call_GeneralDiagnosticInfoPort_GetDTCOfEvent_DTCOfEvent);
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
    case RTE_E_Darh_GeneralDiagnosticInfo_DEM_E_NO_DTC_AVAILABLE:
      fct_error = 1;
      break;
    case RTE_E_Darh_GeneralDiagnosticInfo_E_NOT_OK:
      fct_error = 1;
      break;
  }

  return RTE_E_DataServices_ActivelyReportedDtc_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ReadActivelyReportedDtcLength
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadDataLength> of PortPrototype <DmIsDtcActiveResponse>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_ReportDynamicallyEventPort_EventToReportCount(uint16 *eventCount)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DarhReportDynamicallyEvent_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Darh_ReadActivelyReportedDtcLengthHandler(uint16 *DataLength)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_ActivelyReportedDtc_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ReadActivelyReportedDtcLength_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Darh_CODE) Darh_ReadActivelyReportedDtcLengthHandler(P2VAR(uint16, AUTOMATIC, RTE_DARH_APPL_VAR) DataLength) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Darh_ReadActivelyReportedDtcLengthHandler (returns application error)
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  uint16 Call_ReportDynamicallyEventPort_EventToReportCount_eventCount = 0U;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_Darh_Rte_Call_ReportDynamicallyEventPort_EventToReportCount(&Call_ReportDynamicallyEventPort_EventToReportCount_eventCount);
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
    case RTE_E_DarhReportDynamicallyEvent_E_NOT_OK:
      fct_error = 1;
      break;
  }

  return RTE_E_DataServices_ActivelyReportedDtc_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ReadErrorQueue
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * This runnable is never executed by the RTE.
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_GeneralDiagnosticInfoPort_GetDTCOfEvent(Dem_EventIdType EventId, Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Darh_GeneralDiagnosticInfo_DEM_E_NO_DTC_AVAILABLE, RTE_E_Darh_GeneralDiagnosticInfo_E_NOT_OK
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_ExclusiveArea_0(void)
 *   void Rte_Exit_ExclusiveArea_0(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ReadErrorQueue_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Darh_CODE) Darh_ReadErrorQueueDataHandler(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Darh_ReadErrorQueueDataHandler
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  uint32 Call_GeneralDiagnosticInfoPort_GetDTCOfEvent_DTCOfEvent = 0U;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_Darh_Rte_Call_GeneralDiagnosticInfoPort_GetDTCOfEvent(0U, 0U, &Call_GeneralDiagnosticInfoPort_GetDTCOfEvent_DTCOfEvent);
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
    case RTE_E_Darh_GeneralDiagnosticInfo_DEM_E_NO_DTC_AVAILABLE:
      fct_error = 1;
      break;
    case RTE_E_Darh_GeneralDiagnosticInfo_E_NOT_OK:
      fct_error = 1;
      break;
  }

  TSC_Darh_Rte_Enter_ExclusiveArea_0();
  TSC_Darh_Rte_Exit_ExclusiveArea_0();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ReadErrorQueueLength
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * This runnable is never executed by the RTE.
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_ExclusiveArea_0(void)
 *   void Rte_Exit_ExclusiveArea_0(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ReadErrorQueueLength_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Darh_CODE) Darh_ReadErrorQueueLengthHandler(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Darh_ReadErrorQueueLengthHandler
 *********************************************************************************************************************/

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  TSC_Darh_Rte_Enter_ExclusiveArea_0();
  TSC_Darh_Rte_Exit_ExclusiveArea_0();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SetRoeSuspended
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetRoeSuspended> of PortPrototype <ControlPort>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Darh_SetRoeSuspendedHandler(boolean suspended)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DarhControlInterface_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: SetRoeSuspended_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Darh_CODE) Darh_SetRoeSuspendedHandler(boolean suspended) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Darh_SetRoeSuspendedHandler (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: StartRoutineDiagnoseMaster
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <StartStopRoutineDiagnoseMaster>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_DiagnoseMasterStatus_WriteBlock(NvM_SrcPtrType SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Darh_NvMService_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Darh_StartRoutineDiagnoseMasterHandler(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_StartStopRoutineDiagnoseMaster_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_StartStopRoutineDiagnoseMaster_DCM_E_PENDING
 *   RTE_E_RoutineServices_StartStopRoutineDiagnoseMaster_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: StartRoutineDiagnoseMaster_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Darh_CODE) Darh_StartRoutineDiagnoseMasterHandler(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DARH_APPL_VAR) ErrorCode) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Darh_StartRoutineDiagnoseMasterHandler (returns application error)
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_Darh_Rte_Call_DiagnoseMasterStatus_WriteBlock(0);
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
    case RTE_E_Darh_NvMService_E_NOT_OK:
      fct_error = 1;
      break;
  }

  return RTE_E_RoutineServices_StartStopRoutineDiagnoseMaster_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: StartRoutineTriggerDtc
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <DmClientTriggerDtcEntry>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_ApplicationDTCInfoPort_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Darh_DiagnosticInfo_DEM_E_NO_DTC_AVAILABLE, RTE_E_Darh_DiagnosticInfo_E_NOT_OK
 *   Std_ReturnType Rte_Call_DmTestAppl_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Darh_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DmTestCom_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Darh_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_NetworkDTCInfoPort_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Darh_DiagnosticInfo_DEM_E_NO_DTC_AVAILABLE, RTE_E_Darh_DiagnosticInfo_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Darh_StartRoutineTriggerDtcHandler(uint8 DTCType, Dcm_OpStatusType OpStatus, uint8 *DTCTypeOut, uint8 *DTCByte1, uint8 *DTCByte2, uint8 *DTCByte3, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_TriggerDTC_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_TriggerDTC_DCM_E_PENDING
 *   RTE_E_RoutineServices_TriggerDTC_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: StartRoutineTriggerDtc_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Darh_CODE) Darh_StartRoutineTriggerDtcHandler(uint8 DTCType, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DARH_APPL_VAR) DTCTypeOut, P2VAR(uint8, AUTOMATIC, RTE_DARH_APPL_VAR) DTCByte1, P2VAR(uint8, AUTOMATIC, RTE_DARH_APPL_VAR) DTCByte2, P2VAR(uint8, AUTOMATIC, RTE_DARH_APPL_VAR) DTCByte3, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DARH_APPL_VAR) ErrorCode) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Darh_StartRoutineTriggerDtcHandler (returns application error)
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  uint32 Call_ApplicationDTCInfoPort_GetDTCOfEvent_DTCOfEvent = 0U;
  uint32 Call_NetworkDTCInfoPort_GetDTCOfEvent_DTCOfEvent = 0U;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_Darh_Rte_Call_ApplicationDTCInfoPort_GetDTCOfEvent(0U, &Call_ApplicationDTCInfoPort_GetDTCOfEvent_DTCOfEvent);
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
    case RTE_E_Darh_DiagnosticInfo_DEM_E_NO_DTC_AVAILABLE:
      fct_error = 1;
      break;
    case RTE_E_Darh_DiagnosticInfo_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Darh_Rte_Call_DmTestAppl_SetEventStatus(0U);
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
    case RTE_E_Darh_DiagnosticMonitor_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Darh_Rte_Call_DmTestCom_SetEventStatus(0U);
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
    case RTE_E_Darh_DiagnosticMonitor_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Darh_Rte_Call_NetworkDTCInfoPort_GetDTCOfEvent(0U, &Call_NetworkDTCInfoPort_GetDTCOfEvent_DTCOfEvent);
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
    case RTE_E_Darh_DiagnosticInfo_DEM_E_NO_DTC_AVAILABLE:
      fct_error = 1;
      break;
    case RTE_E_Darh_DiagnosticInfo_E_NOT_OK:
      fct_error = 1;
      break;
  }

  return RTE_E_RoutineServices_TriggerDTC_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: StopRoutineDiagnoseMaster
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Stop> of PortPrototype <StartStopRoutineDiagnoseMaster>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_DiagnoseMasterStatus_WriteBlock(NvM_SrcPtrType SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Darh_NvMService_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Darh_StopRoutineDiagnoseMasterHandler(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_StartStopRoutineDiagnoseMaster_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_StartStopRoutineDiagnoseMaster_DCM_E_PENDING
 *   RTE_E_RoutineServices_StartStopRoutineDiagnoseMaster_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: StopRoutineDiagnoseMaster_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Darh_CODE) Darh_StopRoutineDiagnoseMasterHandler(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DARH_APPL_VAR) ErrorCode) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Darh_StopRoutineDiagnoseMasterHandler (returns application error)
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_Darh_Rte_Call_DiagnoseMasterStatus_WriteBlock(0);
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
    case RTE_E_Darh_NvMService_E_NOT_OK:
      fct_error = 1;
      break;
  }

  return RTE_E_RoutineServices_StartStopRoutineDiagnoseMaster_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: WriteDataBlockNotification
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <NvMNotifyJobFinished>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Darh_NvMNotifyJobFinishedDiagnoseMasterStatus(uint8 ServiceId, NvM_RequestResultType JobResult)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_NvMNotifyJobFinished_E_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: WriteDataBlockNotification_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Darh_CODE) Darh_NvMNotifyJobFinishedDiagnoseMasterStatus(uint8 ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Darh_NvMNotifyJobFinishedDiagnoseMasterStatus (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define Darh_STOP_SEC_CODE
#include "Darh_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void Darh_TestDefines(void)
{
  /* Enumeration Data Types */

  Darh_LifeCycleRequestType Test_Darh_LifeCycleRequestType_V_1 = DARH_INITIALIZED;
  Darh_LifeCycleRequestType Test_Darh_LifeCycleRequestType_V_2 = DARH_RUNNING;
  Darh_LifeCycleRequestType Test_Darh_LifeCycleRequestType_V_3 = DARH_STOPPED;

  Darh_RoeStateType Test_Darh_RoeStateType_V_1 = DARH_ROE_STOPPED;
  Darh_RoeStateType Test_Darh_RoeStateType_V_2 = DARH_ROE_STARTED;
  Darh_RoeStateType Test_Darh_RoeStateType_V_3 = DARH_ROE_UNKNOWN;

  Darh_SuspendedStateType Test_Darh_SuspendedStateType_V_1 = DARH_NOT_SUSPENDED;
  Darh_SuspendedStateType Test_Darh_SuspendedStateType_V_2 = DARH_SUSPENDED;

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

  Dem_DTCFormatType Test_Dem_DTCFormatType_V_1 = DEM_DTC_FORMAT_OBD;
  Dem_DTCFormatType Test_Dem_DTCFormatType_V_2 = DEM_DTC_FORMAT_UDS;
  Dem_DTCFormatType Test_Dem_DTCFormatType_V_3 = DEM_DTC_FORMAT_J1939;

  Dem_EventStatusType Test_Dem_EventStatusType_V_1 = DEM_EVENT_STATUS_PASSED;
  Dem_EventStatusType Test_Dem_EventStatusType_V_2 = DEM_EVENT_STATUS_FAILED;
  Dem_EventStatusType Test_Dem_EventStatusType_V_3 = DEM_EVENT_STATUS_PREPASSED;
  Dem_EventStatusType Test_Dem_EventStatusType_V_4 = DEM_EVENT_STATUS_PREFAILED;
  Dem_EventStatusType Test_Dem_EventStatusType_V_5 = DEM_EVENT_STATUS_FDC_THRESHOLD_REACHED;

  NvM_RequestResultType Test_NvM_RequestResultType_V_1 = NVM_REQ_OK;
  NvM_RequestResultType Test_NvM_RequestResultType_V_2 = NVM_REQ_NOT_OK;
  NvM_RequestResultType Test_NvM_RequestResultType_V_3 = NVM_REQ_PENDING;
  NvM_RequestResultType Test_NvM_RequestResultType_V_4 = NVM_REQ_INTEGRITY_FAILED;
  NvM_RequestResultType Test_NvM_RequestResultType_V_5 = NVM_REQ_BLOCK_SKIPPED;
  NvM_RequestResultType Test_NvM_RequestResultType_V_6 = NVM_REQ_NV_INVALIDATED;
  NvM_RequestResultType Test_NvM_RequestResultType_V_7 = NVM_REQ_CANCELED;
  NvM_RequestResultType Test_NvM_RequestResultType_V_8 = NVM_REQ_REDUNDANCY_FAILED;
  NvM_RequestResultType Test_NvM_RequestResultType_V_9 = NVM_REQ_RESTORED_FROM_ROM;

  /* Modes */

  uint8 Test_DarhReportErrorMode_MV_1 = RTE_MODE_DarhReportErrorMode_DARH_REPORT_ERROR_ACTIVE;
  uint8 Test_DarhReportErrorMode_MV_2 = RTE_MODE_DarhReportErrorMode_DARH_REPORT_ERROR_INACTIVE;
  uint8 Test_DarhReportErrorMode_TV = RTE_TRANSITION_DarhReportErrorMode;

  Darh_LifeCycleRequestType Test_Darh_LifeCycle_MV_1 = RTE_MODE_Darh_LifeCycle_DARH_INITIALIZED;
  Darh_LifeCycleRequestType Test_Darh_LifeCycle_MV_2 = RTE_MODE_Darh_LifeCycle_DARH_RUNNING;
  Darh_LifeCycleRequestType Test_Darh_LifeCycle_MV_3 = RTE_MODE_Darh_LifeCycle_DARH_STOPPED;
  Darh_LifeCycleRequestType Test_Darh_LifeCycle_TV = RTE_TRANSITION_Darh_LifeCycle;

  uint8 Test_DcmResponseOnEvent_MV_1 = RTE_MODE_DcmResponseOnEvent_EVENT_CLEARED;
  uint8 Test_DcmResponseOnEvent_MV_2 = RTE_MODE_DcmResponseOnEvent_EVENT_STARTED;
  uint8 Test_DcmResponseOnEvent_MV_3 = RTE_MODE_DcmResponseOnEvent_EVENT_STOPPED;
  uint8 Test_DcmResponseOnEvent_TV = RTE_TRANSITION_DcmResponseOnEvent;
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
