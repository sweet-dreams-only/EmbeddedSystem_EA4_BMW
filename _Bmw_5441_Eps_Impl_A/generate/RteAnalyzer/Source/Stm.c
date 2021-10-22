/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Stm.c
 *        Config:  EPS.dpa
 *     SW-C Type:  Stm
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <Stm>
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
 * Stm_CentralErrorLockType
 *   
 *
 * Stm_EnergyStateType
 *   
 *
 * Stm_VehicleStateType
 *   
 *
 *********************************************************************************************************************/

#include "Rte_Stm.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_Stm.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"

static void Stm_TestDefines(void);


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
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * Stm_CentralErrorLockType: Enumeration of integer in interval [0...255] with enumerators
 *   STM_CEL_UNLOCKED (0U)
 *   STM_CEL_LOCKED (1U)
 *   STM_CEL_INVALID (3U)
 * Stm_EnergyStateType: Enumeration of integer in interval [0...255] with enumerators
 *   STM_ENERGY_GOOD (0U)
 *   STM_ENERGY_OK (1U)
 *   STM_ENERGY_SHORTAGE (2U)
 *   STM_ENERGY_SEVERE_SHORTAGE (3U)
 *   STM_ENERGY_INVALID (15U)
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
 *********************************************************************************************************************/


#define Stm_START_SEC_CODE
#include "Stm_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Runnable_ErrorCentralErrorLock
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceiveErrorEvent for DataElementPrototype <centralErrorLock> of PortPrototype <CentralErrorLockRx>
 *
 * Executed in the context of the following exclusive areas:
 *   - CentralErrorLockReadWrite_EA
 *
 **********************************************************************************************************************
 *
 * Mode Interfaces:
 * ================
 *   Std_ReturnType Rte_Switch_CentralErrorLockModeSwitchPort_currentCentralErrorLockMode(Stm_CentralErrorLockType mode)
 *   Modes of Rte_ModeType_Stm_CentralErrorLockMode:
 *   - RTE_MODE_Stm_CentralErrorLockMode_STM_CEL_INVALID
 *   - RTE_MODE_Stm_CentralErrorLockMode_STM_CEL_LOCKED
 *   - RTE_MODE_Stm_CentralErrorLockMode_STM_CEL_UNLOCKED
 *   - RTE_TRANSITION_Stm_CentralErrorLockMode
 *   Stm_CentralErrorLockType Rte_Mode_CentralErrorLockModeSwitchPort_currentCentralErrorLockMode(Stm_CentralErrorLockType *previousMode, Stm_CentralErrorLockType *nextMode)
 *   Modes of Rte_ModeType_Stm_CentralErrorLockMode:
 *   - RTE_MODE_Stm_CentralErrorLockMode_STM_CEL_INVALID
 *   - RTE_MODE_Stm_CentralErrorLockMode_STM_CEL_LOCKED
 *   - RTE_MODE_Stm_CentralErrorLockMode_STM_CEL_UNLOCKED
 *   - RTE_TRANSITION_Stm_CentralErrorLockMode
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_CentralErrorLockEnableCondition_SetEnableCondition(boolean ConditionFulfilled)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EnableCondition_E_NOT_OK, RTE_E_EnableCondition_E_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Runnable_ErrorCentralErrorLock_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Stm_CODE) Stm_ErrorCentralErrorLock(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Stm_ErrorCentralErrorLock
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  Rte_ModeType_Stm_CentralErrorLockMode CentralErrorLockModeSwitchPort_currentCentralErrorLockMode;
  Rte_ModeType_Stm_CentralErrorLockMode CentralErrorLockModeSwitchPort_currentCentralErrorLockMode_previousMode;
  Rte_ModeType_Stm_CentralErrorLockMode CentralErrorLockModeSwitchPort_currentCentralErrorLockMode_nextMode;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_Stm_Rte_Switch_CentralErrorLockModeSwitchPort_currentCentralErrorLockMode(RTE_MODE_Stm_CentralErrorLockMode_STM_CEL_INVALID);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  CentralErrorLockModeSwitchPort_currentCentralErrorLockMode = TSC_Stm_Rte_Mode_CentralErrorLockModeSwitchPort_currentCentralErrorLockMode(&CentralErrorLockModeSwitchPort_currentCentralErrorLockMode_previousMode, &CentralErrorLockModeSwitchPort_currentCentralErrorLockMode_nextMode);

  fct_status = TSC_Stm_Rte_Call_CentralErrorLockEnableCondition_SetEnableCondition(FALSE);
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

  Stm_TestDefines();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Runnable_ErrorEnergyMode
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceiveErrorEvent for DataElementPrototype <energyState> of PortPrototype <EnergyModeRx>
 *
 **********************************************************************************************************************
 *
 * Mode Interfaces:
 * ================
 *   Std_ReturnType Rte_Switch_EnergyModeSwitchPort_currentEnergyMode(Stm_EnergyStateType mode)
 *   Modes of Rte_ModeType_Stm_EnergyStateMode:
 *   - RTE_MODE_Stm_EnergyStateMode_STM_ENERGY_GOOD
 *   - RTE_MODE_Stm_EnergyStateMode_STM_ENERGY_INVALID
 *   - RTE_MODE_Stm_EnergyStateMode_STM_ENERGY_OK
 *   - RTE_MODE_Stm_EnergyStateMode_STM_ENERGY_SEVERE_SHORTAGE
 *   - RTE_MODE_Stm_EnergyStateMode_STM_ENERGY_SHORTAGE
 *   - RTE_TRANSITION_Stm_EnergyStateMode
 *   Stm_EnergyStateType Rte_Mode_EnergyModeSwitchPort_currentEnergyMode(Stm_EnergyStateType *previousMode, Stm_EnergyStateType *nextMode)
 *   Modes of Rte_ModeType_Stm_EnergyStateMode:
 *   - RTE_MODE_Stm_EnergyStateMode_STM_ENERGY_GOOD
 *   - RTE_MODE_Stm_EnergyStateMode_STM_ENERGY_INVALID
 *   - RTE_MODE_Stm_EnergyStateMode_STM_ENERGY_OK
 *   - RTE_MODE_Stm_EnergyStateMode_STM_ENERGY_SEVERE_SHORTAGE
 *   - RTE_MODE_Stm_EnergyStateMode_STM_ENERGY_SHORTAGE
 *   - RTE_TRANSITION_Stm_EnergyStateMode
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Runnable_ErrorEnergyMode_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Stm_CODE) Stm_ErrorEnergyMode(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Stm_ErrorEnergyMode
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  Rte_ModeType_Stm_EnergyStateMode EnergyModeSwitchPort_currentEnergyMode;
  Rte_ModeType_Stm_EnergyStateMode EnergyModeSwitchPort_currentEnergyMode_previousMode;
  Rte_ModeType_Stm_EnergyStateMode EnergyModeSwitchPort_currentEnergyMode_nextMode;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_Stm_Rte_Switch_EnergyModeSwitchPort_currentEnergyMode(RTE_MODE_Stm_EnergyStateMode_STM_ENERGY_INVALID);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  EnergyModeSwitchPort_currentEnergyMode = TSC_Stm_Rte_Mode_EnergyModeSwitchPort_currentEnergyMode(&EnergyModeSwitchPort_currentEnergyMode_previousMode, &EnergyModeSwitchPort_currentEnergyMode_nextMode);


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Runnable_InitialCELSupervision
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on entering of Mode <EM_LOCK_RECEIVABLE> of ModeDeclarationGroupPrototype <currentEMLockSignalReceptionMode> of PortPrototype <EMLockSignalReceptionModeNotificationPort>
 *
 * Executed in the context of the following exclusive areas:
 *   - CentralErrorLockReadWrite_EA
 *
 **********************************************************************************************************************
 *
 * Mode Interfaces:
 * ================
 *   Stm_CentralErrorLockType Rte_Mode_CentralErrorLockModeSwitchPort_currentCentralErrorLockMode(Stm_CentralErrorLockType *previousMode, Stm_CentralErrorLockType *nextMode)
 *   Modes of Rte_ModeType_Stm_CentralErrorLockMode:
 *   - RTE_MODE_Stm_CentralErrorLockMode_STM_CEL_INVALID
 *   - RTE_MODE_Stm_CentralErrorLockMode_STM_CEL_LOCKED
 *   - RTE_MODE_Stm_CentralErrorLockMode_STM_CEL_UNLOCKED
 *   - RTE_TRANSITION_Stm_CentralErrorLockMode
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_CentralErrorLockEnableCondition_SetEnableCondition(boolean ConditionFulfilled)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EnableCondition_E_NOT_OK, RTE_E_EnableCondition_E_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Runnable_InitialCELSupervision_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Stm_CODE) Stm_InitialCentralErrorLockSupervision(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Stm_InitialCentralErrorLockSupervision
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  Rte_ModeType_Stm_CentralErrorLockMode CentralErrorLockModeSwitchPort_currentCentralErrorLockMode;
  Rte_ModeType_Stm_CentralErrorLockMode CentralErrorLockModeSwitchPort_currentCentralErrorLockMode_previousMode;
  Rte_ModeType_Stm_CentralErrorLockMode CentralErrorLockModeSwitchPort_currentCentralErrorLockMode_nextMode;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  CentralErrorLockModeSwitchPort_currentCentralErrorLockMode = TSC_Stm_Rte_Mode_CentralErrorLockModeSwitchPort_currentCentralErrorLockMode(&CentralErrorLockModeSwitchPort_currentCentralErrorLockMode_previousMode, &CentralErrorLockModeSwitchPort_currentCentralErrorLockMode_nextMode);

  fct_status = TSC_Stm_Rte_Call_CentralErrorLockEnableCondition_SetEnableCondition(FALSE);
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
 * Runnable Entity Name: Runnable_ReceiveCentralErrorLock
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <centralErrorLock> of PortPrototype <CentralErrorLockRx>
 *
 * Executed in the context of the following exclusive areas:
 *   - CentralErrorLockReadWrite_EA
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_CentralErrorLockRx_centralErrorLock(Stm_CentralErrorLockType *data)
 *
 * Mode Interfaces:
 * ================
 *   Std_ReturnType Rte_Switch_CentralErrorLockModeSwitchPort_currentCentralErrorLockMode(Stm_CentralErrorLockType mode)
 *   Modes of Rte_ModeType_Stm_CentralErrorLockMode:
 *   - RTE_MODE_Stm_CentralErrorLockMode_STM_CEL_INVALID
 *   - RTE_MODE_Stm_CentralErrorLockMode_STM_CEL_LOCKED
 *   - RTE_MODE_Stm_CentralErrorLockMode_STM_CEL_UNLOCKED
 *   - RTE_TRANSITION_Stm_CentralErrorLockMode
 *   Stm_CentralErrorLockType Rte_Mode_CentralErrorLockModeSwitchPort_currentCentralErrorLockMode(Stm_CentralErrorLockType *previousMode, Stm_CentralErrorLockType *nextMode)
 *   Modes of Rte_ModeType_Stm_CentralErrorLockMode:
 *   - RTE_MODE_Stm_CentralErrorLockMode_STM_CEL_INVALID
 *   - RTE_MODE_Stm_CentralErrorLockMode_STM_CEL_LOCKED
 *   - RTE_MODE_Stm_CentralErrorLockMode_STM_CEL_UNLOCKED
 *   - RTE_TRANSITION_Stm_CentralErrorLockMode
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_CentralErrorLockEnableCondition_SetEnableCondition(boolean ConditionFulfilled)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EnableCondition_E_NOT_OK, RTE_E_EnableCondition_E_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Runnable_ReceiveCentralErrorLock_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Stm_CODE) Stm_ReceiveCentralErrorLock(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Stm_ReceiveCentralErrorLock
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  Stm_CentralErrorLockType Read_CentralErrorLockRx_centralErrorLock;

  Rte_ModeType_Stm_CentralErrorLockMode CentralErrorLockModeSwitchPort_currentCentralErrorLockMode;
  Rte_ModeType_Stm_CentralErrorLockMode CentralErrorLockModeSwitchPort_currentCentralErrorLockMode_previousMode;
  Rte_ModeType_Stm_CentralErrorLockMode CentralErrorLockModeSwitchPort_currentCentralErrorLockMode_nextMode;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_Stm_Rte_Read_CentralErrorLockRx_centralErrorLock(&Read_CentralErrorLockRx_centralErrorLock);
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

  fct_status = TSC_Stm_Rte_Switch_CentralErrorLockModeSwitchPort_currentCentralErrorLockMode(RTE_MODE_Stm_CentralErrorLockMode_STM_CEL_INVALID);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  CentralErrorLockModeSwitchPort_currentCentralErrorLockMode = TSC_Stm_Rte_Mode_CentralErrorLockModeSwitchPort_currentCentralErrorLockMode(&CentralErrorLockModeSwitchPort_currentCentralErrorLockMode_previousMode, &CentralErrorLockModeSwitchPort_currentCentralErrorLockMode_nextMode);

  fct_status = TSC_Stm_Rte_Call_CentralErrorLockEnableCondition_SetEnableCondition(FALSE);
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
 * Runnable Entity Name: Runnable_ReceiveEnergyMode
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <energyState> of PortPrototype <EnergyModeRx>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_EnergyModeRx_energyState(Stm_EnergyStateType *data)
 *
 * Mode Interfaces:
 * ================
 *   Std_ReturnType Rte_Switch_EnergyModeSwitchPort_currentEnergyMode(Stm_EnergyStateType mode)
 *   Modes of Rte_ModeType_Stm_EnergyStateMode:
 *   - RTE_MODE_Stm_EnergyStateMode_STM_ENERGY_GOOD
 *   - RTE_MODE_Stm_EnergyStateMode_STM_ENERGY_INVALID
 *   - RTE_MODE_Stm_EnergyStateMode_STM_ENERGY_OK
 *   - RTE_MODE_Stm_EnergyStateMode_STM_ENERGY_SEVERE_SHORTAGE
 *   - RTE_MODE_Stm_EnergyStateMode_STM_ENERGY_SHORTAGE
 *   - RTE_TRANSITION_Stm_EnergyStateMode
 *   Stm_EnergyStateType Rte_Mode_EnergyModeSwitchPort_currentEnergyMode(Stm_EnergyStateType *previousMode, Stm_EnergyStateType *nextMode)
 *   Modes of Rte_ModeType_Stm_EnergyStateMode:
 *   - RTE_MODE_Stm_EnergyStateMode_STM_ENERGY_GOOD
 *   - RTE_MODE_Stm_EnergyStateMode_STM_ENERGY_INVALID
 *   - RTE_MODE_Stm_EnergyStateMode_STM_ENERGY_OK
 *   - RTE_MODE_Stm_EnergyStateMode_STM_ENERGY_SEVERE_SHORTAGE
 *   - RTE_MODE_Stm_EnergyStateMode_STM_ENERGY_SHORTAGE
 *   - RTE_TRANSITION_Stm_EnergyStateMode
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Runnable_ReceiveEnergyMode_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Stm_CODE) Stm_ReceiveEnergyMode(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Stm_ReceiveEnergyMode
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  Stm_EnergyStateType Read_EnergyModeRx_energyState;

  Rte_ModeType_Stm_EnergyStateMode EnergyModeSwitchPort_currentEnergyMode;
  Rte_ModeType_Stm_EnergyStateMode EnergyModeSwitchPort_currentEnergyMode_previousMode;
  Rte_ModeType_Stm_EnergyStateMode EnergyModeSwitchPort_currentEnergyMode_nextMode;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_Stm_Rte_Read_EnergyModeRx_energyState(&Read_EnergyModeRx_energyState);
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

  fct_status = TSC_Stm_Rte_Switch_EnergyModeSwitchPort_currentEnergyMode(RTE_MODE_Stm_EnergyStateMode_STM_ENERGY_INVALID);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  EnergyModeSwitchPort_currentEnergyMode = TSC_Stm_Rte_Mode_EnergyModeSwitchPort_currentEnergyMode(&EnergyModeSwitchPort_currentEnergyMode_previousMode, &EnergyModeSwitchPort_currentEnergyMode_nextMode);


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Runnable_StopCentralErrorLockSupervision
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on entering of Mode <EM_LOCK_NOT_RECEIVABLE> of ModeDeclarationGroupPrototype <currentEMLockSignalReceptionMode> of PortPrototype <EMLockSignalReceptionModeNotificationPort>
 *
 * Executed in the context of the following exclusive areas:
 *   - CentralErrorLockReadWrite_EA
 *
 **********************************************************************************************************************
 *
 * Mode Interfaces:
 * ================
 *   Std_ReturnType Rte_Switch_CentralErrorLockModeSwitchPort_currentCentralErrorLockMode(Stm_CentralErrorLockType mode)
 *   Modes of Rte_ModeType_Stm_CentralErrorLockMode:
 *   - RTE_MODE_Stm_CentralErrorLockMode_STM_CEL_INVALID
 *   - RTE_MODE_Stm_CentralErrorLockMode_STM_CEL_LOCKED
 *   - RTE_MODE_Stm_CentralErrorLockMode_STM_CEL_UNLOCKED
 *   - RTE_TRANSITION_Stm_CentralErrorLockMode
 *   Stm_CentralErrorLockType Rte_Mode_CentralErrorLockModeSwitchPort_currentCentralErrorLockMode(Stm_CentralErrorLockType *previousMode, Stm_CentralErrorLockType *nextMode)
 *   Modes of Rte_ModeType_Stm_CentralErrorLockMode:
 *   - RTE_MODE_Stm_CentralErrorLockMode_STM_CEL_INVALID
 *   - RTE_MODE_Stm_CentralErrorLockMode_STM_CEL_LOCKED
 *   - RTE_MODE_Stm_CentralErrorLockMode_STM_CEL_UNLOCKED
 *   - RTE_TRANSITION_Stm_CentralErrorLockMode
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_CentralErrorLockEnableCondition_SetEnableCondition(boolean ConditionFulfilled)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EnableCondition_E_NOT_OK, RTE_E_EnableCondition_E_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Runnable_StopCentralErrorLockSupervision_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Stm_CODE) Stm_StopCentralErrorLockSupervision(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Stm_StopCentralErrorLockSupervision
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  Rte_ModeType_Stm_CentralErrorLockMode CentralErrorLockModeSwitchPort_currentCentralErrorLockMode;
  Rte_ModeType_Stm_CentralErrorLockMode CentralErrorLockModeSwitchPort_currentCentralErrorLockMode_previousMode;
  Rte_ModeType_Stm_CentralErrorLockMode CentralErrorLockModeSwitchPort_currentCentralErrorLockMode_nextMode;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_Stm_Rte_Switch_CentralErrorLockModeSwitchPort_currentCentralErrorLockMode(RTE_MODE_Stm_CentralErrorLockMode_STM_CEL_INVALID);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  CentralErrorLockModeSwitchPort_currentCentralErrorLockMode = TSC_Stm_Rte_Mode_CentralErrorLockModeSwitchPort_currentCentralErrorLockMode(&CentralErrorLockModeSwitchPort_currentCentralErrorLockMode_previousMode, &CentralErrorLockModeSwitchPort_currentCentralErrorLockMode_nextMode);

  fct_status = TSC_Stm_Rte_Call_CentralErrorLockEnableCondition_SetEnableCondition(FALSE);
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


#define Stm_STOP_SEC_CODE
#include "Stm_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void Stm_TestDefines(void)
{
  /* Enumeration Data Types */

  Stm_CentralErrorLockType Test_Stm_CentralErrorLockType_V_1 = STM_CEL_UNLOCKED;
  Stm_CentralErrorLockType Test_Stm_CentralErrorLockType_V_2 = STM_CEL_LOCKED;
  Stm_CentralErrorLockType Test_Stm_CentralErrorLockType_V_3 = STM_CEL_INVALID;

  Stm_EnergyStateType Test_Stm_EnergyStateType_V_1 = STM_ENERGY_GOOD;
  Stm_EnergyStateType Test_Stm_EnergyStateType_V_2 = STM_ENERGY_OK;
  Stm_EnergyStateType Test_Stm_EnergyStateType_V_3 = STM_ENERGY_SHORTAGE;
  Stm_EnergyStateType Test_Stm_EnergyStateType_V_4 = STM_ENERGY_SEVERE_SHORTAGE;
  Stm_EnergyStateType Test_Stm_EnergyStateType_V_5 = STM_ENERGY_INVALID;

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

  uint8 Test_ErrorMemoryLockSignalReceptionMode_MV_1 = RTE_MODE_ErrorMemoryLockSignalReceptionMode_EM_LOCK_NOT_RECEIVABLE;
  uint8 Test_ErrorMemoryLockSignalReceptionMode_MV_2 = RTE_MODE_ErrorMemoryLockSignalReceptionMode_EM_LOCK_RECEIVABLE;
  uint8 Test_ErrorMemoryLockSignalReceptionMode_TV = RTE_TRANSITION_ErrorMemoryLockSignalReceptionMode;

  Stm_CentralErrorLockType Test_Stm_CentralErrorLockMode_MV_1 = RTE_MODE_Stm_CentralErrorLockMode_STM_CEL_INVALID;
  Stm_CentralErrorLockType Test_Stm_CentralErrorLockMode_MV_2 = RTE_MODE_Stm_CentralErrorLockMode_STM_CEL_LOCKED;
  Stm_CentralErrorLockType Test_Stm_CentralErrorLockMode_MV_3 = RTE_MODE_Stm_CentralErrorLockMode_STM_CEL_UNLOCKED;
  Stm_CentralErrorLockType Test_Stm_CentralErrorLockMode_TV = RTE_TRANSITION_Stm_CentralErrorLockMode;

  Stm_EnergyStateType Test_Stm_EnergyStateMode_MV_1 = RTE_MODE_Stm_EnergyStateMode_STM_ENERGY_GOOD;
  Stm_EnergyStateType Test_Stm_EnergyStateMode_MV_2 = RTE_MODE_Stm_EnergyStateMode_STM_ENERGY_INVALID;
  Stm_EnergyStateType Test_Stm_EnergyStateMode_MV_3 = RTE_MODE_Stm_EnergyStateMode_STM_ENERGY_OK;
  Stm_EnergyStateType Test_Stm_EnergyStateMode_MV_4 = RTE_MODE_Stm_EnergyStateMode_STM_ENERGY_SEVERE_SHORTAGE;
  Stm_EnergyStateType Test_Stm_EnergyStateMode_MV_5 = RTE_MODE_Stm_EnergyStateMode_STM_ENERGY_SHORTAGE;
  Stm_EnergyStateType Test_Stm_EnergyStateMode_TV = RTE_TRANSITION_Stm_EnergyStateMode;

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
