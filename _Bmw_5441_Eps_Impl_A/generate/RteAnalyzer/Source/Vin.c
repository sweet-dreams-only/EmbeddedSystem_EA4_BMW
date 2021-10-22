/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Vin.c
 *        Config:  EPS.dpa
 *     SW-C Type:  Vin
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <Vin>
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
 * NvM_RequestResultType
 *   
 *
 * Vin_LifeCycleRequestType
 *   
 *
 * Vin_QualifierType
 *   
 *
 *********************************************************************************************************************/

#include "Rte_Vin.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_Vin.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"

static void Vin_TestDefines(void);


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
 * NvM_DstPtrType: DataReference
 * NvM_SrcPtrType: DataReference
 * uint16: Integer in interval [0...65535] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * NvM_RequestResultType: Enumeration of integer in interval [0...255] with enumerators
 *   NVM_REQ_OK (0U)
 *   NVM_REQ_NOT_OK (1U)
 *   NVM_REQ_PENDING (2U)
 *   NVM_REQ_INTEGRITY_FAILED (3U)
 *   NVM_REQ_BLOCK_SKIPPED (4U)
 *   NVM_REQ_NV_INVALIDATED (5U)
 *   NVM_REQ_CANCELED (6U)
 *   NVM_REQ_REDUNDANCY_FAILED (7U)
 *   NVM_REQ_RESTORED_FROM_ROM (8U)
 * Vin_LifeCycleRequestType: Enumeration of integer in interval [0...255] with enumerators
 *   VIN_INITIALIZED (0U)
 *   VIN_RUNNING (1U)
 *   VIN_STOPPED (2U)
 * Vin_QualifierType: Enumeration of integer in interval [0...255] with enumerators
 *   VIN_QUAL_INIT (0U)
 *   VIN_QUAL_RECEIVED (1U)
 *   VIN_QUAL_EQ_INTERNAL (2U)
 *   VIN_QUAL_SECURE_PENDING (4U)
 *   VIN_QUAL_SECURE_FINISHED (8U)
 *   VIN_QUAL_SECURE_OK (16U)
 *   VIN_QUAL_SECURE_MASK (28U)
 *
 * Array Types:
 * ============
 * Dlog_VinArrayType: Array with 17 element(s) of type uint8
 * VinArrayType: Array with 7 element(s) of type uint8
 *
 * Record Types:
 * =============
 * Vin_ComVinType: Record with elements
 *   Vin1 of type uint8
 *   Vin2 of type uint8
 *   Vin3 of type uint8
 *   Vin4 of type uint8
 *   Vin5 of type uint8
 *   Vin6 of type uint8
 *   Vin7 of type uint8
 * Vin_VinType: Record with elements
 *   Vin of type VinArrayType
 *   Qualifier of type Vin_QualifierType
 *
 *********************************************************************************************************************/


#define Vin_START_SEC_CODE
#include "Vin_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Vin_LifeCycleModeRequest
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <requestMode> of PortPrototype <LifeCycleRequest>
 *
 * Executed in the context of the following exclusive areas:
 *   - VinState
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Vin_LifeCycleRequestType Rte_IRead_Vin_LifeCycleModeRequest_LifeCycleRequest_requestMode(void)
 *
 * Mode Interfaces:
 * ================
 *   Std_ReturnType Rte_Switch_LifeCycle_Mode(Vin_LifeCycleRequestType mode)
 *   Modes of Rte_ModeType_Vin_LifeCycle:
 *   - RTE_MODE_Vin_LifeCycle_VIN_INITIALIZED
 *   - RTE_MODE_Vin_LifeCycle_VIN_RUNNING
 *   - RTE_MODE_Vin_LifeCycle_VIN_STOPPED
 *   - RTE_TRANSITION_Vin_LifeCycle
 *   Vin_LifeCycleRequestType Rte_Mode_LifeCycle_Mode(Vin_LifeCycleRequestType *previousMode, Vin_LifeCycleRequestType *nextMode)
 *   Modes of Rte_ModeType_Vin_LifeCycle:
 *   - RTE_MODE_Vin_LifeCycle_VIN_INITIALIZED
 *   - RTE_MODE_Vin_LifeCycle_VIN_RUNNING
 *   - RTE_MODE_Vin_LifeCycle_VIN_STOPPED
 *   - RTE_TRANSITION_Vin_LifeCycle
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Vin_LifeCycleModeRequest_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Vin_CODE) Vin_LifeCycleModeRequest(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Vin_LifeCycleModeRequest
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  Vin_LifeCycleRequestType IRead_LifeCycleRequest_requestMode;

  Rte_ModeType_Vin_LifeCycle LifeCycle_Mode;
  Rte_ModeType_Vin_LifeCycle LifeCycle_Mode_previousMode;
  Rte_ModeType_Vin_LifeCycle LifeCycle_Mode_nextMode;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  IRead_LifeCycleRequest_requestMode = TSC_Vin_Rte_IRead_Vin_LifeCycleModeRequest_LifeCycleRequest_requestMode();

  fct_status = TSC_Vin_Rte_Switch_LifeCycle_Mode(RTE_MODE_Vin_LifeCycle_VIN_STOPPED);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  LifeCycle_Mode = TSC_Vin_Rte_Mode_LifeCycle_Mode(&LifeCycle_Mode_previousMode, &LifeCycle_Mode_nextMode);

  Vin_TestDefines();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Vin_Main
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 100ms
 *     and not in Mode(s) <VIN_INITIALIZED, VIN_STOPPED, VIN_VINCOMOFF>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Send_VinRequest_RequestMessageIdentifier(uint16 data)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_NvMService_Vin_GetErrorStatus(NvM_RequestResultType *RequestResultPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Vin_NvMService_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_Vin_ReadBlock(NvM_DstPtrType DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Vin_NvMService_E_NOT_OK
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_VinState(void)
 *   void Rte_Exit_VinState(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Vin_Main_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Vin_CODE) Vin_Main(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Vin_Main
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  NvM_RequestResultType Call_NvMService_Vin_GetErrorStatus_RequestResultPtr = 0U;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_Vin_Rte_Send_VinRequest_RequestMessageIdentifier(0U);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Vin_Rte_Call_NvMService_Vin_GetErrorStatus(&Call_NvMService_Vin_GetErrorStatus_RequestResultPtr);
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
    case RTE_E_Vin_NvMService_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Vin_Rte_Call_NvMService_Vin_ReadBlock(0);
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
    case RTE_E_Vin_NvMService_E_NOT_OK:
      fct_error = 1;
      break;
  }

  TSC_Vin_Rte_Enter_VinState();
  TSC_Vin_Rte_Exit_VinState();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Vin_NvmJobFinished
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <NvMNotifyJobFinished_Vin>
 *
 **********************************************************************************************************************
 *
 * Mode Interfaces:
 * ================
 *   Std_ReturnType Rte_Switch_VinChangeIndicator_ChangeIndicator(uint8 mode)
 *   Modes of Rte_ModeType_Vin_ChangeIndicator:
 *   - RTE_MODE_Vin_ChangeIndicator_VIN_CI_CHANGED
 *   - RTE_MODE_Vin_ChangeIndicator_VIN_CI_INIT
 *   - RTE_MODE_Vin_ChangeIndicator_VIN_CI_NOCHANGE
 *   - RTE_TRANSITION_Vin_ChangeIndicator
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_NvMService_Vin_WriteBlock(NvM_SrcPtrType SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Vin_NvMService_E_NOT_OK
 *
 * Status Interfaces:
 * ==================
 *   Mode Switch Acknowledge:
 *   -------------------------
 *   Std_ReturnType Rte_SwitchAck_VinChangeIndicator_ChangeIndicator(void)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_VinState(void)
 *   void Rte_Exit_VinState(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Vin_NvmJobFinished(uint8 ServiceId, NvM_RequestResultType JobResult)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_Vin_NvMNotifyJobFinished_E_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Vin_NvmJobFinished_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Vin_CODE) Vin_NvmJobFinished(uint8 ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Vin_NvmJobFinished (returns application error)
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_Vin_Rte_Switch_VinChangeIndicator_ChangeIndicator(RTE_MODE_Vin_ChangeIndicator_VIN_CI_INIT);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Vin_Rte_Call_NvMService_Vin_WriteBlock(0);
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
    case RTE_E_Vin_NvMService_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Vin_Rte_SwitchAck_VinChangeIndicator_ChangeIndicator();
  switch (fct_status)
  {
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TRANSMIT_ACK:
      fct_error = 1;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
  }

  TSC_Vin_Rte_Enter_VinState();
  TSC_Vin_Rte_Exit_VinState();

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Vin_OnComOff
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on exiting of Mode <VIN_VINCOMON> and entering of Mode <VIN_VINCOMOFF> of ModeDeclarationGroupPrototype <Mode> of PortPrototype <VinCom>
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Vin_OnComOff_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Vin_CODE) Vin_OnComOff(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Vin_OnComOff
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Vin_OnComOn
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on exiting of Mode <VIN_VINCOMOFF> and entering of Mode <VIN_VINCOMON> of ModeDeclarationGroupPrototype <Mode> of PortPrototype <VinCom>
 *
 * Executed in the context of the following exclusive areas:
 *   - VinState
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Vin_OnComOn_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Vin_CODE) Vin_OnComOn(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Vin_OnComOn
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Vin_OnVinChangeIndicatorAck
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on mode ModeSwitchedAckEvent for ModeDeclarationGroupPrototype <ChangeIndicator> of PortPrototype <VinChangeIndicator>
 *
 * Executed in the context of the following exclusive areas:
 *   - VinState
 *
 **********************************************************************************************************************
 *
 * Mode Interfaces:
 * ================
 *   Std_ReturnType Rte_Switch_VinChangeIndicator_ChangeIndicator(uint8 mode)
 *   Modes of Rte_ModeType_Vin_ChangeIndicator:
 *   - RTE_MODE_Vin_ChangeIndicator_VIN_CI_CHANGED
 *   - RTE_MODE_Vin_ChangeIndicator_VIN_CI_INIT
 *   - RTE_MODE_Vin_ChangeIndicator_VIN_CI_NOCHANGE
 *   - RTE_TRANSITION_Vin_ChangeIndicator
 *   uint8 Rte_Mode_VinChangeIndicator_ChangeIndicator(void)
 *   Modes of Rte_ModeType_Vin_ChangeIndicator:
 *   - RTE_MODE_Vin_ChangeIndicator_VIN_CI_CHANGED
 *   - RTE_MODE_Vin_ChangeIndicator_VIN_CI_INIT
 *   - RTE_MODE_Vin_ChangeIndicator_VIN_CI_NOCHANGE
 *   - RTE_TRANSITION_Vin_ChangeIndicator
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_NvMService_Vin_WriteBlock(NvM_SrcPtrType SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Vin_NvMService_E_NOT_OK
 *
 * Status Interfaces:
 * ==================
 *   Mode Switch Acknowledge:
 *   -------------------------
 *   Std_ReturnType Rte_SwitchAck_VinChangeIndicator_ChangeIndicator(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Vin_OnVinChangeIndicatorAck_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Vin_CODE) Vin_OnVinChangeIndicatorAck(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Vin_OnVinChangeIndicatorAck
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  Rte_ModeType_Vin_ChangeIndicator VinChangeIndicator_ChangeIndicator;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_Vin_Rte_Switch_VinChangeIndicator_ChangeIndicator(RTE_MODE_Vin_ChangeIndicator_VIN_CI_INIT);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  VinChangeIndicator_ChangeIndicator = TSC_Vin_Rte_Mode_VinChangeIndicator_ChangeIndicator();

  fct_status = TSC_Vin_Rte_Call_NvMService_Vin_WriteBlock(0);
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
    case RTE_E_Vin_NvMService_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Vin_Rte_SwitchAck_VinChangeIndicator_ChangeIndicator();
  switch (fct_status)
  {
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TRANSMIT_ACK:
      fct_error = 1;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
  }


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Vin_ReceiveFromCom
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <ComVin> of PortPrototype <ComVin>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Vin_ComVinType *Rte_IRead_Vin_ReceiveFromCom_ComVin_ComVin(void)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_Vin_Vin(const Vin_VinType *data)
 *
 * Mode Interfaces:
 * ================
 *   Std_ReturnType Rte_Switch_VinChangeIndicator_ChangeIndicator(uint8 mode)
 *   Modes of Rte_ModeType_Vin_ChangeIndicator:
 *   - RTE_MODE_Vin_ChangeIndicator_VIN_CI_CHANGED
 *   - RTE_MODE_Vin_ChangeIndicator_VIN_CI_INIT
 *   - RTE_MODE_Vin_ChangeIndicator_VIN_CI_NOCHANGE
 *   - RTE_TRANSITION_Vin_ChangeIndicator
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_DlogEcuInfo_GetVin(uint8 *Vin)
 *     Argument Vin: uint8* is of type Dlog_VinArrayType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EcuInfo_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_NvMService_Vin_WriteBlock(NvM_SrcPtrType SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Vin_NvMService_E_NOT_OK
 *
 * Status Interfaces:
 * ==================
 *   Mode Switch Acknowledge:
 *   -------------------------
 *   Std_ReturnType Rte_SwitchAck_VinChangeIndicator_ChangeIndicator(void)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_VinState(void)
 *   void Rte_Exit_VinState(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Vin_ReceiveFromCom_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Vin_CODE) Vin_ReceiveFromCom(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Vin_ReceiveFromCom
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  Vin_ComVinType IRead_ComVin_ComVin;

  Vin_VinType Write_Vin_Vin;

  Dlog_VinArrayType Call_DlogEcuInfo_GetVin_Vin = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  IRead_ComVin_ComVin = *TSC_Vin_Rte_IRead_Vin_ReceiveFromCom_ComVin_ComVin();

  (void)memset(&Write_Vin_Vin, 0, sizeof(Write_Vin_Vin));
  fct_status = TSC_Vin_Rte_Write_Vin_Vin(&Write_Vin_Vin);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_Vin_Rte_Switch_VinChangeIndicator_ChangeIndicator(RTE_MODE_Vin_ChangeIndicator_VIN_CI_INIT);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Vin_Rte_Call_DlogEcuInfo_GetVin(Call_DlogEcuInfo_GetVin_Vin);
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
    case RTE_E_EcuInfo_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Vin_Rte_Call_NvMService_Vin_WriteBlock(0);
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
    case RTE_E_Vin_NvMService_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Vin_Rte_SwitchAck_VinChangeIndicator_ChangeIndicator();
  switch (fct_status)
  {
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TRANSMIT_ACK:
      fct_error = 1;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
  }

  TSC_Vin_Rte_Enter_VinState();
  TSC_Vin_Rte_Exit_VinState();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define Vin_STOP_SEC_CODE
#include "Vin_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void Vin_TestDefines(void)
{
  /* Enumeration Data Types */

  NvM_RequestResultType Test_NvM_RequestResultType_V_1 = NVM_REQ_OK;
  NvM_RequestResultType Test_NvM_RequestResultType_V_2 = NVM_REQ_NOT_OK;
  NvM_RequestResultType Test_NvM_RequestResultType_V_3 = NVM_REQ_PENDING;
  NvM_RequestResultType Test_NvM_RequestResultType_V_4 = NVM_REQ_INTEGRITY_FAILED;
  NvM_RequestResultType Test_NvM_RequestResultType_V_5 = NVM_REQ_BLOCK_SKIPPED;
  NvM_RequestResultType Test_NvM_RequestResultType_V_6 = NVM_REQ_NV_INVALIDATED;
  NvM_RequestResultType Test_NvM_RequestResultType_V_7 = NVM_REQ_CANCELED;
  NvM_RequestResultType Test_NvM_RequestResultType_V_8 = NVM_REQ_REDUNDANCY_FAILED;
  NvM_RequestResultType Test_NvM_RequestResultType_V_9 = NVM_REQ_RESTORED_FROM_ROM;

  Vin_LifeCycleRequestType Test_Vin_LifeCycleRequestType_V_1 = VIN_INITIALIZED;
  Vin_LifeCycleRequestType Test_Vin_LifeCycleRequestType_V_2 = VIN_RUNNING;
  Vin_LifeCycleRequestType Test_Vin_LifeCycleRequestType_V_3 = VIN_STOPPED;

  Vin_QualifierType Test_Vin_QualifierType_V_1 = VIN_QUAL_INIT;
  Vin_QualifierType Test_Vin_QualifierType_V_2 = VIN_QUAL_RECEIVED;
  Vin_QualifierType Test_Vin_QualifierType_V_3 = VIN_QUAL_EQ_INTERNAL;
  Vin_QualifierType Test_Vin_QualifierType_V_4 = VIN_QUAL_SECURE_PENDING;
  Vin_QualifierType Test_Vin_QualifierType_V_5 = VIN_QUAL_SECURE_FINISHED;
  Vin_QualifierType Test_Vin_QualifierType_V_6 = VIN_QUAL_SECURE_OK;
  Vin_QualifierType Test_Vin_QualifierType_V_7 = VIN_QUAL_SECURE_MASK;

  /* Modes */

  uint8 Test_Vin_ChangeIndicator_MV_1 = RTE_MODE_Vin_ChangeIndicator_VIN_CI_INIT;
  uint8 Test_Vin_ChangeIndicator_MV_2 = RTE_MODE_Vin_ChangeIndicator_VIN_CI_NOCHANGE;
  uint8 Test_Vin_ChangeIndicator_MV_3 = RTE_MODE_Vin_ChangeIndicator_VIN_CI_CHANGED;
  uint8 Test_Vin_ChangeIndicator_TV = RTE_TRANSITION_Vin_ChangeIndicator;

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
