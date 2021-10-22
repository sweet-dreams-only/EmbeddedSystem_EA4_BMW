/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Omc.c
 *        Config:  EPS.dpa
 *     SW-C Type:  Omc
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <Omc>
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
 * Dcm_NegativeResponseCodeType
 *   
 *
 * Dem_EventStatusType
 *   
 *
 * Omc_ExtendedOperatingModeType
 *   
 *
 * Omc_LifeCycleRequestType
 *   
 *
 * Omc_OperatingModeType
 *   
 *
 * OpStatusType
 *   
 *
 * RequestResultType
 *   
 *
 *********************************************************************************************************************/

#include "Rte_Omc.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_Omc.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"

static void Omc_TestDefines(void);


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
 * SrcPtrType: DataReference
 * boolean: Boolean (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * Dcm_NegativeResponseCodeType: Enumeration of integer in interval [0...255] with enumerators
 *   DCM_E_GENERALREJECT (16U)
 *   DCM_E_BUSYREPEATREQUEST (33U)
 *   DCM_E_CONDITIONSNOTCORRECT (34U)
 *   DCM_E_REQUESTSEQUENCEERROR (36U)
 *   DCM_E_REQUESTOUTOFRANGE (49U)
 *   DCM_E_SECURITYACCESSDENIED (51U)
 *   DCM_E_GENERALPROGRAMMINGFAILURE (114U)
 *   DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION (126U)
 *   DCM_E_RPMTOOHIGH (129U)
 *   DCM_E_RPMTOOLOW (130U)
 *   DCM_E_ENGINEISRUNNING (131U)
 *   DCM_E_ENGINEISNOTRUNNING (132U)
 *   DCM_E_ENGINERUNTIMETOOLOW (133U)
 *   DCM_E_TEMPERATURETOOHIGH (134U)
 *   DCM_E_TEMPERATURETOOLOW (135U)
 *   DCM_E_VEHICLESPEEDTOOHIGH (136U)
 *   DCM_E_VEHICLESPEEDTOOLOW (137U)
 *   DCM_E_THROTTLE_PEDALTOOHIGH (138U)
 *   DCM_E_THROTTLE_PEDALTOOLOW (139U)
 *   DCM_E_TRANSMISSIONRANGENOTINNEUTRAL (140U)
 *   DCM_E_TRANSMISSIONRANGENOTINGEAR (141U)
 *   DCM_E_BRAKESWITCH_NOTCLOSED (143U)
 *   DCM_E_SHIFTERLEVERNOTINPARK (144U)
 *   DCM_E_TORQUECONVERTERCLUTCHLOCKED (145U)
 *   DCM_E_VOLTAGETOOHIGH (146U)
 *   DCM_E_VOLTAGETOOLOW (147U)
 * Dem_EventStatusType: Enumeration of integer in interval [0...255] with enumerators
 *   DEM_EVENT_STATUS_PASSED (0U)
 *   DEM_EVENT_STATUS_FAILED (1U)
 *   DEM_EVENT_STATUS_PREPASSED (2U)
 *   DEM_EVENT_STATUS_PREFAILED (3U)
 *   DEM_EVENT_STATUS_FDC_THRESHOLD_REACHED (4U)
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
 * Omc_LifeCycleRequestType: Enumeration of integer in interval [0...255] with enumerators
 *   OMC_INITIALIZED (0U)
 *   OMC_RUNNING (1U)
 *   OMC_STOPPED (2U)
 * Omc_OperatingModeType: Enumeration of integer in interval [0...255] with enumerators
 *   OMC_MODE_NORMAL (0U)
 *   OMC_MODE_ASSEMBLY (1U)
 *   OMC_MODE_TRANSPORT (2U)
 *   OMC_MODE_BMW_FLASH (3U)
 * OpStatusType: Enumeration of integer in interval [0...255] with enumerators
 *   DCM_INITIAL (0U)
 *   DCM_PENDING (1U)
 *   DCM_CANCEL (2U)
 *   DCM_FORCE_RCRRP_OK (3U)
 * RequestResultType: Enumeration of integer in interval [0...255] with enumerators
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
 * UInt8_Array1: Array with 1 element(s) of type uint8
 *
 *********************************************************************************************************************/


#define Omc_START_SEC_CODE
#include "Omc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ChangeExtendedOperatingMode
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <ControlExtendedEnergySavingState>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_StdDiag_AllowOpModeSwitch(Omc_OperatingModeType OperatingMode, Omc_ExtendedOperatingModeType ExtendedOperatingMode, Omc_OperatingModeType NewOperatingMode, Omc_ExtendedOperatingModeType NewExtendedOperatingMode)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_OmcModesCallouts_E_NOT_OK, RTE_E_OmcModesCallouts_E_RUNNING
 *   Std_ReturnType Rte_Call_StdDiag_OpModeSwitchCancelled(Omc_OperatingModeType OperatingMode, Omc_ExtendedOperatingModeType ExtendedOperatingMode, Omc_OperatingModeType RequestedOperatingMode, Omc_ExtendedOperatingModeType RequestedExtendedOperatingMode)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_OmcModesCallouts_E_OK, RTE_E_OmcModesCallouts_E_RUNNING
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_NvMServicePort_GetErrorStatus(RequestResultType *RequestResultPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_OMC_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMServicePort_WriteBlock(SrcPtrType SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_OMC_E_NOT_OK
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Mode(void)
 *   void Rte_Exit_Mode(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Omc_RoutineControlStartExtendedOperatingMode(uint8 ExtendedOperatingMode, OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_ExtendedOperatingModeControl_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_ExtendedOperatingModeControl_DCM_E_PENDING
 *   RTE_E_RoutineServices_ExtendedOperatingModeControl_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ChangeExtendedOperatingMode_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Omc_CODE) Omc_RoutineControlStartExtendedOperatingMode(uint8 ExtendedOperatingMode, OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_OMC_APPL_VAR) ErrorCode) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Omc_RoutineControlStartExtendedOperatingMode (returns application error)
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  RequestResultType Call_NvMServicePort_GetErrorStatus_RequestResultPtr = 0U;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_Omc_Rte_Call_StdDiag_AllowOpModeSwitch(0U, 0U, 0U, 0U);
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
    case RTE_E_OmcModesCallouts_E_NOT_OK:
      fct_error = 1;
      break;
    case RTE_E_OmcModesCallouts_E_RUNNING:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Omc_Rte_Call_StdDiag_OpModeSwitchCancelled(0U, 0U, 0U, 0U);
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
    case RTE_E_OmcModesCallouts_E_RUNNING:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Omc_Rte_Call_NvMServicePort_GetErrorStatus(&Call_NvMServicePort_GetErrorStatus_RequestResultPtr);
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
    case RTE_E_NvMService_OMC_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Omc_Rte_Call_NvMServicePort_WriteBlock(0);
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
    case RTE_E_NvMService_OMC_E_NOT_OK:
      fct_error = 1;
      break;
  }

  TSC_Omc_Rte_Enter_Mode();
  TSC_Omc_Rte_Exit_Mode();

  Omc_TestDefines();

  return RTE_E_RoutineServices_ExtendedOperatingModeControl_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ChangeOperatingMode
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <ControlEnergySavingState>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_StdDiag_AllowOpModeSwitch(Omc_OperatingModeType OperatingMode, Omc_ExtendedOperatingModeType ExtendedOperatingMode, Omc_OperatingModeType NewOperatingMode, Omc_ExtendedOperatingModeType NewExtendedOperatingMode)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_OmcModesCallouts_E_NOT_OK, RTE_E_OmcModesCallouts_E_RUNNING
 *   Std_ReturnType Rte_Call_StdDiag_OpModeSwitchCancelled(Omc_OperatingModeType OperatingMode, Omc_ExtendedOperatingModeType ExtendedOperatingMode, Omc_OperatingModeType RequestedOperatingMode, Omc_ExtendedOperatingModeType RequestedExtendedOperatingMode)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_OmcModesCallouts_E_OK, RTE_E_OmcModesCallouts_E_RUNNING
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_NvMServicePort_GetErrorStatus(RequestResultType *RequestResultPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_OMC_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMServicePort_WriteBlock(SrcPtrType SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_OMC_E_NOT_OK
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Mode(void)
 *   void Rte_Exit_Mode(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Omc_RoutineControlStartOperatingMode(uint8 OperatingMode, OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_OperatingModeControl_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_OperatingModeControl_DCM_E_PENDING
 *   RTE_E_RoutineServices_OperatingModeControl_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ChangeOperatingMode_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Omc_CODE) Omc_RoutineControlStartOperatingMode(uint8 OperatingMode, OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_OMC_APPL_VAR) ErrorCode) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Omc_RoutineControlStartOperatingMode (returns application error)
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  RequestResultType Call_NvMServicePort_GetErrorStatus_RequestResultPtr = 0U;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_Omc_Rte_Call_StdDiag_AllowOpModeSwitch(0U, 0U, 0U, 0U);
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
    case RTE_E_OmcModesCallouts_E_NOT_OK:
      fct_error = 1;
      break;
    case RTE_E_OmcModesCallouts_E_RUNNING:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Omc_Rte_Call_StdDiag_OpModeSwitchCancelled(0U, 0U, 0U, 0U);
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
    case RTE_E_OmcModesCallouts_E_RUNNING:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Omc_Rte_Call_NvMServicePort_GetErrorStatus(&Call_NvMServicePort_GetErrorStatus_RequestResultPtr);
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
    case RTE_E_NvMService_OMC_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Omc_Rte_Call_NvMServicePort_WriteBlock(0);
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
    case RTE_E_NvMService_OMC_E_NOT_OK:
      fct_error = 1;
      break;
  }

  TSC_Omc_Rte_Enter_Mode();
  TSC_Omc_Rte_Exit_Mode();

  return RTE_E_RoutineServices_OperatingModeControl_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ClearEventAllowed
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ClearEventAllowed> of PortPrototype <ClearEventAllowedPort>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Mode(void)
 *   void Rte_Exit_Mode(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Omc_ClearEventAllowed(boolean *Allowed)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CallbackClearEventAllowed_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ClearEventAllowed_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Omc_CODE) Omc_ClearEventAllowed(P2VAR(boolean, AUTOMATIC, RTE_OMC_APPL_VAR) Allowed) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Omc_ClearEventAllowed (returns application error)
 *********************************************************************************************************************/

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  TSC_Omc_Rte_Enter_Mode();
  TSC_Omc_Rte_Exit_Mode();

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ConditionCheckReadExtendedOperatingMode
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <ExtendedEnergySavingState>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Mode(void)
 *   void Rte_Exit_Mode(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Omc_ConditionCheckReadDIDExtendedOperatingMode(Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_ExtendedOperatingMode_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ConditionCheckReadExtendedOperatingMode_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Omc_CODE) Omc_ConditionCheckReadDIDExtendedOperatingMode(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_OMC_APPL_VAR) ErrorCode) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Omc_ConditionCheckReadDIDExtendedOperatingMode (returns application error)
 *********************************************************************************************************************/

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  TSC_Omc_Rte_Enter_Mode();
  TSC_Omc_Rte_Exit_Mode();

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ConditionCheckReadOperatingMode
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <EnergySavingState>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Mode(void)
 *   void Rte_Exit_Mode(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Omc_ConditionCheckReadDIDOperatingMode(Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_OperatingMode_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ConditionCheckReadOperatingMode_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Omc_CODE) Omc_ConditionCheckReadDIDOperatingMode(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_OMC_APPL_VAR) ErrorCode) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Omc_ConditionCheckReadDIDOperatingMode (returns application error)
 *********************************************************************************************************************/

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  TSC_Omc_Rte_Enter_Mode();
  TSC_Omc_Rte_Exit_Mode();

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
 *   Omc_LifeCycleRequestType Rte_IRead_LifeCycleHandler_LifeCycleRequest_requestMode(void)
 *
 * Mode Interfaces:
 * ================
 *   Std_ReturnType Rte_Switch_LifeCycle_Mode(Omc_LifeCycleRequestType mode)
 *   Modes of Rte_ModeType_Omc_LifeCycle:
 *   - RTE_MODE_Omc_LifeCycle_OMC_INITIALIZED
 *   - RTE_MODE_Omc_LifeCycle_OMC_RUNNING
 *   - RTE_MODE_Omc_LifeCycle_OMC_STOPPED
 *   - RTE_TRANSITION_Omc_LifeCycle
 *   Std_ReturnType Rte_Switch_extendedOperatingModeSwitchPort_currentExtendedOperatingMode(Omc_ExtendedOperatingModeType mode)
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
 *   Std_ReturnType Rte_Switch_operatingModeSwitchPort_currentOperatingMode(Omc_OperatingModeType mode)
 *   Modes of Rte_ModeType_OmcOperatingMode:
 *   - RTE_MODE_OmcOperatingMode_OMC_MODE_ASSEMBLY
 *   - RTE_MODE_OmcOperatingMode_OMC_MODE_BMW_FLASH
 *   - RTE_MODE_OmcOperatingMode_OMC_MODE_NORMAL
 *   - RTE_MODE_OmcOperatingMode_OMC_MODE_TRANSPORT
 *   - RTE_TRANSITION_OmcOperatingMode
 *   Omc_LifeCycleRequestType Rte_Mode_LifeCycle_Mode(Omc_LifeCycleRequestType *previousMode, Omc_LifeCycleRequestType *nextMode)
 *   Modes of Rte_ModeType_Omc_LifeCycle:
 *   - RTE_MODE_Omc_LifeCycle_OMC_INITIALIZED
 *   - RTE_MODE_Omc_LifeCycle_OMC_RUNNING
 *   - RTE_MODE_Omc_LifeCycle_OMC_STOPPED
 *   - RTE_TRANSITION_Omc_LifeCycle
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_EnableCond_OMC_SetEnableCondition(boolean ConditionFulfilled)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EnableCondition_E_NOT_OK
 *   Std_ReturnType Rte_Call_VsmEventOpmode_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Omc_DiagnosticMonitor_E_NOT_OK
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Mode(void)
 *   void Rte_Exit_Mode(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: LifeCycleHandler_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Omc_CODE) Omc_LifeCycleHandler(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Omc_LifeCycleHandler
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  Omc_LifeCycleRequestType IRead_LifeCycleRequest_requestMode;

  Rte_ModeType_Omc_LifeCycle LifeCycle_Mode;
  Rte_ModeType_Omc_LifeCycle LifeCycle_Mode_previousMode;
  Rte_ModeType_Omc_LifeCycle LifeCycle_Mode_nextMode;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  IRead_LifeCycleRequest_requestMode = TSC_Omc_Rte_IRead_LifeCycleHandler_LifeCycleRequest_requestMode();

  fct_status = TSC_Omc_Rte_Switch_LifeCycle_Mode(RTE_MODE_Omc_LifeCycle_OMC_STOPPED);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Omc_Rte_Switch_extendedOperatingModeSwitchPort_currentExtendedOperatingMode(RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_NORMAL);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Omc_Rte_Switch_operatingModeSwitchPort_currentOperatingMode(RTE_MODE_OmcOperatingMode_OMC_MODE_NORMAL);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  LifeCycle_Mode = TSC_Omc_Rte_Mode_LifeCycle_Mode(&LifeCycle_Mode_previousMode, &LifeCycle_Mode_nextMode);

  fct_status = TSC_Omc_Rte_Call_EnableCond_OMC_SetEnableCondition(FALSE);
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

  fct_status = TSC_Omc_Rte_Call_VsmEventOpmode_SetEventStatus(0U);
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
    case RTE_E_Omc_DiagnosticMonitor_E_NOT_OK:
      fct_error = 1;
      break;
  }

  TSC_Omc_Rte_Enter_Mode();
  TSC_Omc_Rte_Exit_Mode();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NvMWriteJobFinished
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
 * Mode Interfaces:
 * ================
 *   Std_ReturnType Rte_Switch_extendedOperatingModeSwitchPort_currentExtendedOperatingMode(Omc_ExtendedOperatingModeType mode)
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
 *   Std_ReturnType Rte_Switch_operatingModeSwitchPort_currentOperatingMode(Omc_OperatingModeType mode)
 *   Modes of Rte_ModeType_OmcOperatingMode:
 *   - RTE_MODE_OmcOperatingMode_OMC_MODE_ASSEMBLY
 *   - RTE_MODE_OmcOperatingMode_OMC_MODE_BMW_FLASH
 *   - RTE_MODE_OmcOperatingMode_OMC_MODE_NORMAL
 *   - RTE_MODE_OmcOperatingMode_OMC_MODE_TRANSPORT
 *   - RTE_TRANSITION_OmcOperatingMode
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_EnableCond_OMC_SetEnableCondition(boolean ConditionFulfilled)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EnableCondition_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMServicePort_GetErrorStatus(RequestResultType *RequestResultPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_OMC_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMServicePort_WriteBlock(SrcPtrType SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_OMC_E_NOT_OK
 *   Std_ReturnType Rte_Call_VsmEventOpmode_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Omc_DiagnosticMonitor_E_NOT_OK
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Mode(void)
 *   void Rte_Exit_Mode(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Omc_NvMNotifyJobFinishedOperatingModes(uint8 ServiceId, RequestResultType JobResult)
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
 * Symbol: NvMWriteJobFinished_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Omc_CODE) Omc_NvMNotifyJobFinishedOperatingModes(uint8 ServiceId, RequestResultType JobResult) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Omc_NvMNotifyJobFinishedOperatingModes (returns application error)
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  RequestResultType Call_NvMServicePort_GetErrorStatus_RequestResultPtr = 0U;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_Omc_Rte_Switch_extendedOperatingModeSwitchPort_currentExtendedOperatingMode(RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_NORMAL);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Omc_Rte_Switch_operatingModeSwitchPort_currentOperatingMode(RTE_MODE_OmcOperatingMode_OMC_MODE_NORMAL);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Omc_Rte_Call_EnableCond_OMC_SetEnableCondition(FALSE);
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

  fct_status = TSC_Omc_Rte_Call_NvMServicePort_GetErrorStatus(&Call_NvMServicePort_GetErrorStatus_RequestResultPtr);
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
    case RTE_E_NvMService_OMC_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Omc_Rte_Call_NvMServicePort_WriteBlock(0);
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
    case RTE_E_NvMService_OMC_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Omc_Rte_Call_VsmEventOpmode_SetEventStatus(0U);
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
    case RTE_E_Omc_DiagnosticMonitor_E_NOT_OK:
      fct_error = 1;
      break;
  }

  TSC_Omc_Rte_Enter_Mode();
  TSC_Omc_Rte_Exit_Mode();

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ReadDIDExtendedOperatingMode
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <ExtendedEnergySavingState>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Mode(void)
 *   void Rte_Exit_Mode(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Omc_ReadDIDExtendedOperatingMode(uint8 *Data)
 *     Argument Data: uint8* is of type UInt8_Array1
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_ExtendedOperatingMode_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ReadDIDExtendedOperatingMode_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Omc_CODE) Omc_ReadDIDExtendedOperatingMode(P2VAR(uint8, AUTOMATIC, RTE_OMC_APPL_VAR) Data) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Omc_ReadDIDExtendedOperatingMode (returns application error)
 *********************************************************************************************************************/

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  TSC_Omc_Rte_Enter_Mode();
  TSC_Omc_Rte_Exit_Mode();

  return RTE_E_DataServices_ExtendedOperatingMode_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ReadOperatingMode
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <EnergySavingState>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Mode(void)
 *   void Rte_Exit_Mode(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Omc_ReadDIDOperatingMode(uint8 *Data)
 *     Argument Data: uint8* is of type UInt8_Array1
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_OperatingMode_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ReadOperatingMode_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Omc_CODE) Omc_ReadDIDOperatingMode(P2VAR(uint8, AUTOMATIC, RTE_OMC_APPL_VAR) Data) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Omc_ReadDIDOperatingMode (returns application error)
 *********************************************************************************************************************/

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  TSC_Omc_Rte_Enter_Mode();
  TSC_Omc_Rte_Exit_Mode();

  return RTE_E_DataServices_OperatingMode_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: StdDiag_OpModeSwitchAllowedResult
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <OpModeSwitchAllowedResult> of PortPrototype <StdDiagCbk>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Omc_StdDiag_OpModeSwitchAllowedResult(boolean Result)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_OmcModesCalloutsResult_E_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: StdDiag_OpModeSwitchAllowedResult_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Omc_CODE) Omc_StdDiag_OpModeSwitchAllowedResult(boolean Result) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Omc_StdDiag_OpModeSwitchAllowedResult (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: StdDiag_OpModeSwitchCancelledAck
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <OpModeSwitchCancelledAck> of PortPrototype <StdDiagCbk>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Omc_StdDiag_OpModeSwitchCancelledAck(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_OmcModesCalloutsResult_E_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: StdDiag_OpModeSwitchCancelledAck_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Omc_CODE) Omc_StdDiag_OpModeSwitchCancelledAck(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Omc_StdDiag_OpModeSwitchCancelledAck (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define Omc_STOP_SEC_CODE
#include "Omc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void Omc_TestDefines(void)
{
  /* Enumeration Data Types */

  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_1 = DCM_E_GENERALREJECT;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_2 = DCM_E_BUSYREPEATREQUEST;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_3 = DCM_E_CONDITIONSNOTCORRECT;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_4 = DCM_E_REQUESTSEQUENCEERROR;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_5 = DCM_E_REQUESTOUTOFRANGE;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_6 = DCM_E_SECURITYACCESSDENIED;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_7 = DCM_E_GENERALPROGRAMMINGFAILURE;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_8 = DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_9 = DCM_E_RPMTOOHIGH;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_10 = DCM_E_RPMTOOLOW;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_11 = DCM_E_ENGINEISRUNNING;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_12 = DCM_E_ENGINEISNOTRUNNING;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_13 = DCM_E_ENGINERUNTIMETOOLOW;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_14 = DCM_E_TEMPERATURETOOHIGH;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_15 = DCM_E_TEMPERATURETOOLOW;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_16 = DCM_E_VEHICLESPEEDTOOHIGH;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_17 = DCM_E_VEHICLESPEEDTOOLOW;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_18 = DCM_E_THROTTLE_PEDALTOOHIGH;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_19 = DCM_E_THROTTLE_PEDALTOOLOW;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_20 = DCM_E_TRANSMISSIONRANGENOTINNEUTRAL;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_21 = DCM_E_TRANSMISSIONRANGENOTINGEAR;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_22 = DCM_E_BRAKESWITCH_NOTCLOSED;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_23 = DCM_E_SHIFTERLEVERNOTINPARK;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_24 = DCM_E_TORQUECONVERTERCLUTCHLOCKED;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_25 = DCM_E_VOLTAGETOOHIGH;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_26 = DCM_E_VOLTAGETOOLOW;

  Dem_EventStatusType Test_Dem_EventStatusType_V_1 = DEM_EVENT_STATUS_PASSED;
  Dem_EventStatusType Test_Dem_EventStatusType_V_2 = DEM_EVENT_STATUS_FAILED;
  Dem_EventStatusType Test_Dem_EventStatusType_V_3 = DEM_EVENT_STATUS_PREPASSED;
  Dem_EventStatusType Test_Dem_EventStatusType_V_4 = DEM_EVENT_STATUS_PREFAILED;
  Dem_EventStatusType Test_Dem_EventStatusType_V_5 = DEM_EVENT_STATUS_FDC_THRESHOLD_REACHED;

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

  Omc_LifeCycleRequestType Test_Omc_LifeCycleRequestType_V_1 = OMC_INITIALIZED;
  Omc_LifeCycleRequestType Test_Omc_LifeCycleRequestType_V_2 = OMC_RUNNING;
  Omc_LifeCycleRequestType Test_Omc_LifeCycleRequestType_V_3 = OMC_STOPPED;

  Omc_OperatingModeType Test_Omc_OperatingModeType_V_1 = OMC_MODE_NORMAL;
  Omc_OperatingModeType Test_Omc_OperatingModeType_V_2 = OMC_MODE_ASSEMBLY;
  Omc_OperatingModeType Test_Omc_OperatingModeType_V_3 = OMC_MODE_TRANSPORT;
  Omc_OperatingModeType Test_Omc_OperatingModeType_V_4 = OMC_MODE_BMW_FLASH;

  OpStatusType Test_OpStatusType_V_1 = DCM_INITIAL;
  OpStatusType Test_OpStatusType_V_2 = DCM_PENDING;
  OpStatusType Test_OpStatusType_V_3 = DCM_CANCEL;
  OpStatusType Test_OpStatusType_V_4 = DCM_FORCE_RCRRP_OK;

  RequestResultType Test_RequestResultType_V_1 = NVM_REQ_OK;
  RequestResultType Test_RequestResultType_V_2 = NVM_REQ_NOT_OK;
  RequestResultType Test_RequestResultType_V_3 = NVM_REQ_PENDING;
  RequestResultType Test_RequestResultType_V_4 = NVM_REQ_INTEGRITY_FAILED;
  RequestResultType Test_RequestResultType_V_5 = NVM_REQ_BLOCK_SKIPPED;
  RequestResultType Test_RequestResultType_V_6 = NVM_REQ_NV_INVALIDATED;
  RequestResultType Test_RequestResultType_V_7 = NVM_REQ_CANCELED;
  RequestResultType Test_RequestResultType_V_8 = NVM_REQ_REDUNDANCY_FAILED;
  RequestResultType Test_RequestResultType_V_9 = NVM_REQ_RESTORED_FROM_ROM;

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

  Omc_LifeCycleRequestType Test_Omc_LifeCycle_MV_1 = RTE_MODE_Omc_LifeCycle_OMC_INITIALIZED;
  Omc_LifeCycleRequestType Test_Omc_LifeCycle_MV_2 = RTE_MODE_Omc_LifeCycle_OMC_RUNNING;
  Omc_LifeCycleRequestType Test_Omc_LifeCycle_MV_3 = RTE_MODE_Omc_LifeCycle_OMC_STOPPED;
  Omc_LifeCycleRequestType Test_Omc_LifeCycle_TV = RTE_TRANSITION_Omc_LifeCycle;
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
