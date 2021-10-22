/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Dlog.c
 *        Config:  EPS.dpa
 *     SW-C Type:  Dlog
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <Dlog>
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
 * Dcm_OpStatusType
 *   
 *
 * Dlog_LifeCycleRequestType
 *   
 *
 * NvM_RequestResultType
 *   
 *
 *********************************************************************************************************************/

#include "Rte_Dlog.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_Dlog.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"

static void Dlog_TestDefines(void);


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
 * boolean: Boolean (standard type)
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * Dcm_NegativeResponseCodeType: Enumeration of integer in interval [0...255] with enumerators
 *   DCM_E_GENERALREJECT (16U)
 *   DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT (19U)
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
 * Dcm_OpStatusType: Enumeration of integer in interval [0...255] with enumerators
 *   DCM_INITIAL (0U)
 *   DCM_PENDING (1U)
 *   DCM_CANCEL (2U)
 *   DCM_FORCE_RCRRP_OK (3U)
 * Dlog_LifeCycleRequestType: Enumeration of integer in interval [0...255] with enumerators
 *   DLOG_INITIALIZED (0U)
 *   DLOG_RUNNING (1U)
 *   DLOG_STOPPED (2U)
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
 *
 * Array Types:
 * ============
 * Coding_CafIdArrayType: Array with 8 element(s) of type uint8
 * DevInfoArrayType: Array with 11 element(s) of type uint8
 * Dlog_EcuUidArrayType: Array with 16 element(s) of type uint8
 * Dlog_HWModificationIndexArrayType: Array with 2 element(s) of type uint8
 * Dlog_ProgIdArrayType: Array with 8 element(s) of type uint8
 * Dlog_SignatureArrayType: Array with 260 element(s) of type uint8
 * Dlog_VinArrayType: Array with 17 element(s) of type uint8
 * ManufacturingDataArrayType: Array with 3 element(s) of type uint8
 * RSInputArrayType: Array with 8 element(s) of type uint8
 * SerialNumberArrayType: Array with 10 element(s) of type uint8
 * SvkDataArrayType: Array with 100 element(s) of type uint8
 * SvkHistoryDataArrayType: Array with 48 element(s) of type uint8
 * TimingParametersArrayType: Array with 12 element(s) of type uint8
 *
 *********************************************************************************************************************/


#define Dlog_START_SEC_CODE
#include "Dlog_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CondCheckSvkCurrent
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <SvkCurrent>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_Coding_Svk_GetCafIds(uint8 *cafIds, uint16 *numberOfCafIds)
 *     Argument cafIds: uint8* is of type Coding_CafIdArrayType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Coding_SVKInterface_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Dlog_ConditionCheckSvkCurrent(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Svk_DCM_E_PENDING
 *   RTE_E_DataServices_Svk_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CondCheckSvkCurrent_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Dlog_CODE) Dlog_ConditionCheckSvkCurrent(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DLOG_APPL_VAR) ErrorCode) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlog_ConditionCheckSvkCurrent (returns application error)
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  Coding_CafIdArrayType Call_Coding_Svk_GetCafIds_cafIds = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  uint16 Call_Coding_Svk_GetCafIds_numberOfCafIds = 0U;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_Dlog_Rte_Call_Coding_Svk_GetCafIds(Call_Coding_Svk_GetCafIds_cafIds, &Call_Coding_Svk_GetCafIds_numberOfCafIds);
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
    case RTE_E_Coding_SVKInterface_E_NOT_OK:
      fct_error = 1;
      break;
  }

  Dlog_TestDefines();

  return RTE_E_DataServices_Svk_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CondCheckSvkPlant
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <SvkPlant>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_NvMService_DlogSvkEntry_ReadBlock(NvM_DstPtrType DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMServiceSvkEntry_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_DlogSvkEntry_SetDataIndex(uint8 DataIndex)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMServiceSvkEntry_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Dlog_ConditionCheckSvkPlant(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_SvkHistory_DCM_E_PENDING
 *   RTE_E_DataServices_SvkHistory_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CondCheckSvkPlant_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Dlog_CODE) Dlog_ConditionCheckSvkPlant(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DLOG_APPL_VAR) ErrorCode) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlog_ConditionCheckSvkPlant (returns application error)
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_Dlog_Rte_Call_NvMService_DlogSvkEntry_ReadBlock(0);
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
    case RTE_E_NvMServiceSvkEntry_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Dlog_Rte_Call_NvMService_DlogSvkEntry_SetDataIndex(0U);
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
    case RTE_E_NvMServiceSvkEntry_E_NOT_OK:
      fct_error = 1;
      break;
  }

  return RTE_E_DataServices_SvkHistory_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CondCheckSvkSysSupplier
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <SvkSysSupplier>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_NvMService_DlogSvkEntry_ReadBlock(NvM_DstPtrType DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMServiceSvkEntry_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_DlogSvkEntry_SetDataIndex(uint8 DataIndex)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMServiceSvkEntry_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Dlog_ConditionCheckSvkSysSupplier(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_SvkHistory_DCM_E_PENDING
 *   RTE_E_DataServices_SvkHistory_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CondCheckSvkSysSupplier_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Dlog_CODE) Dlog_ConditionCheckSvkSysSupplier(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DLOG_APPL_VAR) ErrorCode) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlog_ConditionCheckSvkSysSupplier (returns application error)
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_Dlog_Rte_Call_NvMService_DlogSvkEntry_ReadBlock(0);
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
    case RTE_E_NvMServiceSvkEntry_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Dlog_Rte_Call_NvMService_DlogSvkEntry_SetDataIndex(0U);
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
    case RTE_E_NvMServiceSvkEntry_E_NOT_OK:
      fct_error = 1;
      break;
  }

  return RTE_E_DataServices_SvkHistory_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CondCheckVin
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <Vin>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Dlog_ConditionCheckVin(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Vin_DCM_E_PENDING
 *   RTE_E_DataServices_Vin_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CondCheckVin_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Dlog_CODE) Dlog_ConditionCheckVin(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DLOG_APPL_VAR) ErrorCode) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlog_ConditionCheckVin (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataLengthSvkCurrent
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadDataLength> of PortPrototype <SvkCurrent>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Dlog_ReadDataLengthSvkCurrent(Dcm_OpStatusType OpStatus, uint16 *DataLength)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Svk_DCM_E_PENDING
 *   RTE_E_DataServices_Svk_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataLengthSvkCurrent_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Dlog_CODE) Dlog_ReadDataLengthSvkCurrent(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_DLOG_APPL_VAR) DataLength) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlog_ReadDataLengthSvkCurrent (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Dlog_GetEcuId
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetEcuId> of PortPrototype <EcuInfo>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Dlog_GetEcuId(uint8 *ecuId)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_EcuInfo_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlog_GetEcuId_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Dlog_CODE) Dlog_GetEcuId(P2VAR(uint8, AUTOMATIC, RTE_DLOG_APPL_VAR) ecuId) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlog_GetEcuId (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Dlog_GetVin
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetVin> of PortPrototype <EcuInfo>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Dlog_GetVin(uint8 *Vin)
 *     Argument Vin: uint8* is of type Dlog_VinArrayType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_EcuInfo_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlog_GetVin_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Dlog_CODE) Dlog_GetVin(P2VAR(uint8, AUTOMATIC, RTE_DLOG_APPL_VAR) Vin) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlog_GetVin (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Dlog_ModeSwitchAckLifeCycle
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on mode ModeSwitchedAckEvent for ModeDeclarationGroupPrototype <Mode> of PortPrototype <LifeCycle>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ProgId_progId(const uint8 *data)
 *     Argument data: uint8* is of type Dlog_ProgIdArrayType
 *
 * Mode Interfaces:
 * ================
 *   Std_ReturnType Rte_Switch_LifeCycle_Mode(Dlog_LifeCycleRequestType mode)
 *   Modes of Rte_ModeType_Dlog_LifeCycle:
 *   - RTE_MODE_Dlog_LifeCycle_DLOG_INITIALIZED
 *   - RTE_MODE_Dlog_LifeCycle_DLOG_RUNNING
 *   - RTE_MODE_Dlog_LifeCycle_DLOG_STOPPED
 *   - RTE_TRANSITION_Dlog_LifeCycle
 *
 * Status Interfaces:
 * ==================
 *   Mode Switch Acknowledge:
 *   -------------------------
 *   Std_ReturnType Rte_SwitchAck_LifeCycle_Mode(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlog_ModeSwitchAckLifeCycle_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Dlog_CODE) Dlog_ModeSwitchAckLifeCycle(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlog_ModeSwitchAckLifeCycle
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  Dlog_ProgIdArrayType Write_ProgId_progId;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  (void)memset(&Write_ProgId_progId, 0, sizeof(Write_ProgId_progId));
  fct_status = TSC_Dlog_Rte_Write_ProgId_progId(Write_ProgId_progId);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_Dlog_Rte_Switch_LifeCycle_Mode(RTE_MODE_Dlog_LifeCycle_DLOG_STOPPED);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Dlog_Rte_SwitchAck_LifeCycle_Mode();
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
 * Runnable Entity Name: Dlog_ModeSwitchRequestLifeCycle
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
 *   Dlog_LifeCycleRequestType Rte_IRead_Dlog_ModeSwitchRequestLifeCycle_LifeCycleRequest_requestMode(void)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ProgId_progId(const uint8 *data)
 *     Argument data: uint8* is of type Dlog_ProgIdArrayType
 *
 * Mode Interfaces:
 * ================
 *   Std_ReturnType Rte_Switch_LifeCycle_Mode(Dlog_LifeCycleRequestType mode)
 *   Modes of Rte_ModeType_Dlog_LifeCycle:
 *   - RTE_MODE_Dlog_LifeCycle_DLOG_INITIALIZED
 *   - RTE_MODE_Dlog_LifeCycle_DLOG_RUNNING
 *   - RTE_MODE_Dlog_LifeCycle_DLOG_STOPPED
 *   - RTE_TRANSITION_Dlog_LifeCycle
 *   Dlog_LifeCycleRequestType Rte_Mode_LifeCycle_Mode(Dlog_LifeCycleRequestType *previousMode, Dlog_LifeCycleRequestType *nextMode)
 *   Modes of Rte_ModeType_Dlog_LifeCycle:
 *   - RTE_MODE_Dlog_LifeCycle_DLOG_INITIALIZED
 *   - RTE_MODE_Dlog_LifeCycle_DLOG_RUNNING
 *   - RTE_MODE_Dlog_LifeCycle_DLOG_STOPPED
 *   - RTE_TRANSITION_Dlog_LifeCycle
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_NvMService_DlogProgData_WriteBlock(NvM_SrcPtrType SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_DlogSvkEntry_WriteBlock(NvM_SrcPtrType SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMServiceSvkEntry_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_DlogSvkHistory_GetErrorStatus(NvM_RequestResultType *RequestResultPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_DlogSvkHistory_WriteBlock(NvM_SrcPtrType SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_E_NOT_OK
 *
 * Status Interfaces:
 * ==================
 *   Mode Switch Acknowledge:
 *   -------------------------
 *   Std_ReturnType Rte_SwitchAck_LifeCycle_Mode(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlog_ModeSwitchRequestLifeCycle_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Dlog_CODE) Dlog_ModeSwitchRequestLifeCycle(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlog_ModeSwitchRequestLifeCycle
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  Dlog_LifeCycleRequestType IRead_LifeCycleRequest_requestMode;

  Dlog_ProgIdArrayType Write_ProgId_progId;

  Rte_ModeType_Dlog_LifeCycle LifeCycle_Mode;
  Rte_ModeType_Dlog_LifeCycle LifeCycle_Mode_previousMode;
  Rte_ModeType_Dlog_LifeCycle LifeCycle_Mode_nextMode;

  NvM_RequestResultType Call_NvMService_DlogSvkHistory_GetErrorStatus_RequestResultPtr = 0U;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  IRead_LifeCycleRequest_requestMode = TSC_Dlog_Rte_IRead_Dlog_ModeSwitchRequestLifeCycle_LifeCycleRequest_requestMode();

  (void)memset(&Write_ProgId_progId, 0, sizeof(Write_ProgId_progId));
  fct_status = TSC_Dlog_Rte_Write_ProgId_progId(Write_ProgId_progId);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_Dlog_Rte_Switch_LifeCycle_Mode(RTE_MODE_Dlog_LifeCycle_DLOG_STOPPED);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  LifeCycle_Mode = TSC_Dlog_Rte_Mode_LifeCycle_Mode(&LifeCycle_Mode_previousMode, &LifeCycle_Mode_nextMode);

  fct_status = TSC_Dlog_Rte_Call_NvMService_DlogProgData_WriteBlock(0);
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
    case RTE_E_NvMService_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Dlog_Rte_Call_NvMService_DlogSvkEntry_WriteBlock(0);
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
    case RTE_E_NvMServiceSvkEntry_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Dlog_Rte_Call_NvMService_DlogSvkHistory_GetErrorStatus(&Call_NvMService_DlogSvkHistory_GetErrorStatus_RequestResultPtr);
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
    case RTE_E_NvMService_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Dlog_Rte_Call_NvMService_DlogSvkHistory_WriteBlock(0);
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
    case RTE_E_NvMService_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Dlog_Rte_SwitchAck_LifeCycle_Mode();
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
 * Runnable Entity Name: Dlog_NotifyJobFinishedProgData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <NvMNotifyJobFinished_DlogProgData>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_NvMAdmin_DlogProgData_SetBlockProtection(boolean ProtectionEnabled)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Dlog_NvMAdmin_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Dlog_NotifyJobFinishedProgData(uint8 ServiceId, NvM_RequestResultType JobResult)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_Dlog_NvMNotifyJobFinished_E_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlog_NotifyJobFinishedProgData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Dlog_CODE) Dlog_NotifyJobFinishedProgData(uint8 ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlog_NotifyJobFinishedProgData (returns application error)
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_Dlog_Rte_Call_NvMAdmin_DlogProgData_SetBlockProtection(FALSE);
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
    case RTE_E_Dlog_NvMAdmin_E_NOT_OK:
      fct_error = 1;
      break;
  }

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Dlog_NotifyJobFinishedSvkEntry
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <NvMNotifyJobFinished_SvkEntry>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Dlog_NotifyJobFinishedSvkEntry(uint8 ServiceId, NvM_RequestResultType JobResult)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_Dlog_NvMNotifyJobFinished_E_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlog_NotifyJobFinishedSvkEntry_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Dlog_CODE) Dlog_NotifyJobFinishedSvkEntry(uint8 ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlog_NotifyJobFinishedSvkEntry (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Dlog_ReadDataByIdentifierEcuUid
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <EcuUid>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Dlog_ReadDataByIdentifierEcuUid(uint8 *Data)
 *     Argument Data: uint8* is of type Dlog_EcuUidArrayType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_EcuUid_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlog_ReadDataByIdentifierEcuUid_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Dlog_CODE) Dlog_ReadDataByIdentifierEcuUid(P2VAR(uint8, AUTOMATIC, RTE_DLOG_APPL_VAR) Data) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlog_ReadDataByIdentifierEcuUid (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Dlog_ReadDataByIdentifierHWModificationIndex
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <HWModificationIndex>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Dlog_ReadDataByIdentifierHWModificationIndex(uint8 *Data)
 *     Argument Data: uint8* is of type Dlog_HWModificationIndexArrayType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_HWModificationIndex_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlog_ReadDataByIdentifierHWModificationIndex_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Dlog_CODE) Dlog_ReadDataByIdentifierHWModificationIndex(P2VAR(uint8, AUTOMATIC, RTE_DLOG_APPL_VAR) Data) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlog_ReadDataByIdentifierHWModificationIndex (returns application error)
 *********************************************************************************************************************/

  return RTE_E_DataServices_HWModificationIndex_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: InitBlockProgData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <InitBlock> of PortPrototype <InitBlockProgData>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Dlog_InitProgData(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_Dlog_NvMNotifyInitBlock_E_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: InitBlockProgData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Dlog_CODE) Dlog_InitProgData(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlog_InitProgData (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ReadEcuSerialNumber
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <EcuSerialNumber>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Dlog_ReadDataByIdentifierEcuSerialNumber(uint8 *Data)
 *     Argument Data: uint8* is of type SerialNumberArrayType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_EcuSerialNumber_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ReadEcuSerialNumber_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Dlog_CODE) Dlog_ReadDataByIdentifierEcuSerialNumber(P2VAR(uint8, AUTOMATIC, RTE_DLOG_APPL_VAR) Data) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlog_ReadDataByIdentifierEcuSerialNumber (returns application error)
 *********************************************************************************************************************/

  return RTE_E_DataServices_EcuSerialNumber_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ReadFlashTimingParameter
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <FlashTimingParameter>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Dlog_ReadDataByIdentifierFlashTimingParameter(uint8 *Data)
 *     Argument Data: uint8* is of type TimingParametersArrayType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_FlashTimingParameter_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ReadFlashTimingParameter_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Dlog_CODE) Dlog_ReadDataByIdentifierFlashTimingParameter(P2VAR(uint8, AUTOMATIC, RTE_DLOG_APPL_VAR) Data) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlog_ReadDataByIdentifierFlashTimingParameter (returns application error)
 *********************************************************************************************************************/

  return RTE_E_DataServices_FlashTimingParameter_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ReadManufacturingDate
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <ManufacturingDate>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Dlog_ReadDataByIdentifierManufacturingDate(uint8 *Data)
 *     Argument Data: uint8* is of type ManufacturingDataArrayType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_ManufacturingDate_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ReadManufacturingDate_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Dlog_CODE) Dlog_ReadDataByIdentifierManufacturingDate(P2VAR(uint8, AUTOMATIC, RTE_DLOG_APPL_VAR) Data) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlog_ReadDataByIdentifierManufacturingDate (returns application error)
 *********************************************************************************************************************/

  return RTE_E_DataServices_ManufacturingDate_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ReadSvkCurrent
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <SvkCurrent>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Dlog_ReadDataByIdentifierSvkCurrent(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type SvkDataArrayType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Svk_DCM_E_PENDING
 *   RTE_E_DataServices_Svk_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ReadSvkCurrent_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Dlog_CODE) Dlog_ReadDataByIdentifierSvkCurrent(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DLOG_APPL_VAR) Data) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlog_ReadDataByIdentifierSvkCurrent (returns application error)
 *********************************************************************************************************************/

  return RTE_E_DataServices_Svk_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ReadSvkPlant
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <SvkPlant>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Dlog_ReadDataByIdentifierSvkPlant(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type SvkHistoryDataArrayType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_SvkHistory_DCM_E_PENDING
 *   RTE_E_DataServices_SvkHistory_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ReadSvkPlant_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Dlog_CODE) Dlog_ReadDataByIdentifierSvkPlant(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DLOG_APPL_VAR) Data) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlog_ReadDataByIdentifierSvkPlant (returns application error)
 *********************************************************************************************************************/

  return RTE_E_DataServices_SvkHistory_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ReadSvkSysSupplier
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <SvkSysSupplier>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Dlog_ReadDataByIdentifierSvkSysSupplier(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type SvkHistoryDataArrayType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_SvkHistory_DCM_E_PENDING
 *   RTE_E_DataServices_SvkHistory_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ReadSvkSysSupplier_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Dlog_CODE) Dlog_ReadDataByIdentifierSvkSysSupplier(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DLOG_APPL_VAR) Data) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlog_ReadDataByIdentifierSvkSysSupplier (returns application error)
 *********************************************************************************************************************/

  return RTE_E_DataServices_SvkHistory_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ReadVin
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <Vin>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Dlog_ReadDataByIdentifierVin(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dlog_VinArrayType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Vin_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ReadVin_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Dlog_CODE) Dlog_ReadDataByIdentifierVin(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DLOG_APPL_VAR) Data) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlog_ReadDataByIdentifierVin (returns application error)
 *********************************************************************************************************************/

  return RTE_E_DataServices_Vin_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: StartReadReadDevInfoField
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <DevelopmentInfoField>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Dlog_RoutineControlStartReadDevelopmentInfoField(const uint8 *DataIn, Dcm_OpStatusType OpStatus, uint8 *DataOut, uint16 *CurrentDataLength, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument DataIn: uint8* is of type RSInputArrayType
 *     Argument DataOut: uint8* is of type DevInfoArrayType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineService_DevInfo_DCM_E_PENDING
 *   RTE_E_RoutineService_DevInfo_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: StartReadReadDevInfoField_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Dlog_CODE) Dlog_RoutineControlStartReadDevelopmentInfoField(P2CONST(uint8, AUTOMATIC, RTE_DLOG_APPL_DATA) DataIn, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DLOG_APPL_VAR) DataOut, P2VAR(uint16, AUTOMATIC, RTE_DLOG_APPL_VAR) CurrentDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DLOG_APPL_VAR) ErrorCode) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlog_RoutineControlStartReadDevelopmentInfoField (returns application error)
 *********************************************************************************************************************/

  return RTE_E_RoutineService_DevInfo_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SweGetNumSig
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetNumSig> of PortPrototype <SweSignatureAccess>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Dlog_SweGetNumSig(uint8 sweId, uint8 *numSig)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_SweSignatureAccess_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: SweGetNumSig_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Dlog_CODE) Dlog_SweGetNumSig(uint8 sweId, P2VAR(uint8, AUTOMATIC, RTE_DLOG_APPL_VAR) numSig) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlog_SweGetNumSig (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SweGetNumSwe
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetNumSwe> of PortPrototype <SweSignatureAccess>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Dlog_SweGetNumSwe(uint8 *numSwe)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_SweSignatureAccess_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: SweGetNumSwe_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Dlog_CODE) Dlog_SweGetNumSwe(P2VAR(uint8, AUTOMATIC, RTE_DLOG_APPL_VAR) numSwe) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlog_SweGetNumSwe (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SweGetSigLength
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetSigLength> of PortPrototype <SweSignatureAccess>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Dlog_SweGetSigLength(uint8 sweId, uint8 blkNum, uint32 *length)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_SweSignatureAccess_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: SweGetSigLength_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Dlog_CODE) Dlog_SweGetSigLength(uint8 sweId, uint8 blkNum, P2VAR(uint32, AUTOMATIC, RTE_DLOG_APPL_VAR) length) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlog_SweGetSigLength (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SweGetSigStart
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetSigStart> of PortPrototype <SweSignatureAccess>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Dlog_SweGetSigStart(uint8 sweId, uint8 blkNum, uint32 *address)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_SweSignatureAccess_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: SweGetSigStart_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Dlog_CODE) Dlog_SweGetSigStart(uint8 sweId, uint8 blkNum, P2VAR(uint32, AUTOMATIC, RTE_DLOG_APPL_VAR) address) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlog_SweGetSigStart (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SweGetSignature
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetSignature> of PortPrototype <SweSignatureAccess>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Dlog_SweGetSignatureRte(uint8 sweId, uint8 *signature)
 *     Argument signature: uint8* is of type Dlog_SignatureArrayType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_SweSignatureAccess_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: SweGetSignature_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Dlog_CODE) Dlog_SweGetSignatureRte(uint8 sweId, P2VAR(uint8, AUTOMATIC, RTE_DLOG_APPL_VAR) signature) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlog_SweGetSignatureRte (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define Dlog_STOP_SEC_CODE
#include "Dlog_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void Dlog_TestDefines(void)
{
  /* Enumeration Data Types */

  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_1 = DCM_E_GENERALREJECT;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_2 = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_3 = DCM_E_BUSYREPEATREQUEST;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_4 = DCM_E_CONDITIONSNOTCORRECT;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_5 = DCM_E_REQUESTSEQUENCEERROR;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_6 = DCM_E_REQUESTOUTOFRANGE;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_7 = DCM_E_SECURITYACCESSDENIED;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_8 = DCM_E_GENERALPROGRAMMINGFAILURE;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_9 = DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_10 = DCM_E_RPMTOOHIGH;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_11 = DCM_E_RPMTOOLOW;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_12 = DCM_E_ENGINEISRUNNING;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_13 = DCM_E_ENGINEISNOTRUNNING;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_14 = DCM_E_ENGINERUNTIMETOOLOW;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_15 = DCM_E_TEMPERATURETOOHIGH;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_16 = DCM_E_TEMPERATURETOOLOW;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_17 = DCM_E_VEHICLESPEEDTOOHIGH;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_18 = DCM_E_VEHICLESPEEDTOOLOW;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_19 = DCM_E_THROTTLE_PEDALTOOHIGH;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_20 = DCM_E_THROTTLE_PEDALTOOLOW;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_21 = DCM_E_TRANSMISSIONRANGENOTINNEUTRAL;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_22 = DCM_E_TRANSMISSIONRANGENOTINGEAR;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_23 = DCM_E_BRAKESWITCH_NOTCLOSED;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_24 = DCM_E_SHIFTERLEVERNOTINPARK;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_25 = DCM_E_TORQUECONVERTERCLUTCHLOCKED;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_26 = DCM_E_VOLTAGETOOHIGH;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_27 = DCM_E_VOLTAGETOOLOW;

  Dcm_OpStatusType Test_Dcm_OpStatusType_V_1 = DCM_INITIAL;
  Dcm_OpStatusType Test_Dcm_OpStatusType_V_2 = DCM_PENDING;
  Dcm_OpStatusType Test_Dcm_OpStatusType_V_3 = DCM_CANCEL;
  Dcm_OpStatusType Test_Dcm_OpStatusType_V_4 = DCM_FORCE_RCRRP_OK;

  Dlog_LifeCycleRequestType Test_Dlog_LifeCycleRequestType_V_1 = DLOG_INITIALIZED;
  Dlog_LifeCycleRequestType Test_Dlog_LifeCycleRequestType_V_2 = DLOG_RUNNING;
  Dlog_LifeCycleRequestType Test_Dlog_LifeCycleRequestType_V_3 = DLOG_STOPPED;

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

  Dlog_LifeCycleRequestType Test_Dlog_LifeCycle_MV_1 = RTE_MODE_Dlog_LifeCycle_DLOG_INITIALIZED;
  Dlog_LifeCycleRequestType Test_Dlog_LifeCycle_MV_2 = RTE_MODE_Dlog_LifeCycle_DLOG_RUNNING;
  Dlog_LifeCycleRequestType Test_Dlog_LifeCycle_MV_3 = RTE_MODE_Dlog_LifeCycle_DLOG_STOPPED;
  Dlog_LifeCycleRequestType Test_Dlog_LifeCycle_TV = RTE_TRANSITION_Dlog_LifeCycle;
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
