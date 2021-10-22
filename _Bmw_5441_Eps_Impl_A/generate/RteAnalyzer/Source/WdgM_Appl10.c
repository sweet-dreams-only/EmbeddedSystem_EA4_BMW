/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  WdgM_Appl10.c
 *        Config:  EPS.dpa
 *     SW-C Type:  WdgM_Appl10
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <WdgM_Appl10>
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
 * WdgM_CheckpointIdType
 *   
 *
 * WdgM_GlobalStatusType
 *   
 *
 * WdgM_LocalStatusType
 *   
 *
 * WdgM_ModeType
 *   
 *
 * WdgM_SupervisedEntityIdType
 *   
 *
 *
 * Port Prototypes:
 * ================
 * alive_SE_100ms_Appl10_ChkPt_100ms_Appl10_End
 *
 * alive_SE_100ms_Appl10_ChkPt_100ms_Appl10_Strt
 *
 * alive_SE_10msBsw_Appl10_ChkPt_10msBsw_Appl10_End
 *
 * alive_SE_10msBsw_Appl10_ChkPt_10msBsw_Appl10_Strt
 *
 * alive_SE_10ms_Appl10_ChkPt_10ms_Appl10_End
 *
 * alive_SE_10ms_Appl10_ChkPt_10ms_Appl10_Strt
 *
 * alive_SE_2msA_Appl10_ChkPt_2msA_Appl10_End
 *
 * alive_SE_2msA_Appl10_ChkPt_2msA_Appl10_Strt
 *
 * alive_SE_2msA_Appl10_ChkPt_GblFinal
 *
 * alive_SE_2msB_Appl10_ChkPt_2msB_Appl10_End
 *
 * alive_SE_2msB_Appl10_ChkPt_2msB_Appl10_Strt
 *
 * alive_SE_4ms_Appl10_ChkPt_4ms_Appl10_End
 *
 * alive_SE_4ms_Appl10_ChkPt_4ms_Appl10_Strt
 *
 * general_Core0
 *
 * localStatus_SE_100ms_Appl10
 *
 * localStatus_SE_10msBsw_Appl10
 *
 * localStatus_SE_10ms_Appl10
 *
 * localStatus_SE_2msA_Appl10
 *
 * localStatus_SE_2msB_Appl10
 *
 * localStatus_SE_4ms_Appl10
 *
 *
 * Operation Prototypes:
 * =====================
 * CheckpointReached of Port Interface WdgM_AliveSupervision
 *   
 *
 * ActivateSupervisionEntity of Port Interface WdgM_General
 *   
 *
 * DeactivateSupervisionEntity of Port Interface WdgM_General
 *   
 *
 * GetFirstExpiredSEID of Port Interface WdgM_General
 *   
 *
 * GetGlobalStatus of Port Interface WdgM_General
 *   
 *
 * GetLocalStatus of Port Interface WdgM_General
 *   
 *
 * GetMode of Port Interface WdgM_General
 *   
 *
 * PerformReset of Port Interface WdgM_General
 *   
 *
 * SetMode of Port Interface WdgM_General
 *   
 *
 * GetLocalStatus of Port Interface WdgM_LocalStatus
 *   
 *
 *********************************************************************************************************************/

#include "Rte_WdgM_Appl10.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_WdgM_Appl10.h"
#include "SchM_WdgM.h"
#include "TSC_SchM_WdgM.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"

static void WdgM_Appl10_TestDefines(void);


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
 * WdgM_CheckpointIdType: Integer in interval [0...65535]
 * WdgM_ModeType: Integer in interval [0...255]
 * WdgM_SupervisedEntityIdType: Integer in interval [0...65535]
 * uint16: Integer in interval [0...65535] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * WdgM_GlobalStatusType: Enumeration of integer in interval [0...255] with enumerators
 *   WDGM_GLOBAL_STATUS_OK (0U)
 *   WDGM_GLOBAL_STATUS_FAILED (1U)
 *   WDGM_GLOBAL_STATUS_EXPIRED (2U)
 *   WDGM_GLOBAL_STATUS_STOPPED (3U)
 *   WDGM_GLOBAL_STATUS_DEACTIVATED (4U)
 * WdgM_LocalStatusType: Enumeration of integer in interval [0...255] with enumerators
 *   WDGM_LOCAL_STATUS_OK (0U)
 *   WDGM_LOCAL_STATUS_FAILED (1U)
 *   WDGM_LOCAL_STATUS_EXPIRED (2U)
 *   WDGM_LOCAL_STATUS_DEACTIVATED (4U)
 *
 *********************************************************************************************************************/


#define WdgM_Appl10_START_SEC_CODE
#include "WdgM_Appl10_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ActivateSupervisionEntity
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ActivateSupervisionEntity> of PortPrototype <general_Core0>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType WdgM_ActivateSupervisionEntity(WdgM_SupervisedEntityIdType SEID)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_WdgM_General_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ActivateSupervisionEntity_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, WdgM_Appl10_CODE) WdgM_ActivateSupervisionEntity(WdgM_SupervisedEntityIdType SEID) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: WdgM_ActivateSupervisionEntity (returns application error)
 *********************************************************************************************************************/

  WdgM_Appl10_TestDefines();

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CheckpointReached
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <CheckpointReached> of PortPrototype <alive_SE_100ms_Appl10_ChkPt_100ms_Appl10_End>
 *   - triggered by server invocation for OperationPrototype <CheckpointReached> of PortPrototype <alive_SE_100ms_Appl10_ChkPt_100ms_Appl10_Strt>
 *   - triggered by server invocation for OperationPrototype <CheckpointReached> of PortPrototype <alive_SE_10msBsw_Appl10_ChkPt_10msBsw_Appl10_End>
 *   - triggered by server invocation for OperationPrototype <CheckpointReached> of PortPrototype <alive_SE_10msBsw_Appl10_ChkPt_10msBsw_Appl10_Strt>
 *   - triggered by server invocation for OperationPrototype <CheckpointReached> of PortPrototype <alive_SE_10ms_Appl10_ChkPt_10ms_Appl10_End>
 *   - triggered by server invocation for OperationPrototype <CheckpointReached> of PortPrototype <alive_SE_10ms_Appl10_ChkPt_10ms_Appl10_Strt>
 *   - triggered by server invocation for OperationPrototype <CheckpointReached> of PortPrototype <alive_SE_2msA_Appl10_ChkPt_2msA_Appl10_End>
 *   - triggered by server invocation for OperationPrototype <CheckpointReached> of PortPrototype <alive_SE_2msA_Appl10_ChkPt_2msA_Appl10_Strt>
 *   - triggered by server invocation for OperationPrototype <CheckpointReached> of PortPrototype <alive_SE_2msA_Appl10_ChkPt_GblFinal>
 *   - triggered by server invocation for OperationPrototype <CheckpointReached> of PortPrototype <alive_SE_2msB_Appl10_ChkPt_2msB_Appl10_End>
 *   - triggered by server invocation for OperationPrototype <CheckpointReached> of PortPrototype <alive_SE_2msB_Appl10_ChkPt_2msB_Appl10_Strt>
 *   - triggered by server invocation for OperationPrototype <CheckpointReached> of PortPrototype <alive_SE_4ms_Appl10_ChkPt_4ms_Appl10_End>
 *   - triggered by server invocation for OperationPrototype <CheckpointReached> of PortPrototype <alive_SE_4ms_Appl10_ChkPt_4ms_Appl10_Strt>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType WdgM_CheckpointReached(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_WdgM_AliveSupervision_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CheckpointReached_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, WdgM_Appl10_CODE) WdgM_CheckpointReached(WdgM_SupervisedEntityIdType parg0, WdgM_CheckpointIdType parg1) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: WdgM_CheckpointReached (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DeactivateSupervisionEntity
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <DeactivateSupervisionEntity> of PortPrototype <general_Core0>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType WdgM_DeactivateSupervisionEntity(WdgM_SupervisedEntityIdType SEID)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_WdgM_General_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DeactivateSupervisionEntity_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, WdgM_Appl10_CODE) WdgM_DeactivateSupervisionEntity(WdgM_SupervisedEntityIdType SEID) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: WdgM_DeactivateSupervisionEntity (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: GetFirstExpiredSEID
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetFirstExpiredSEID> of PortPrototype <general_Core0>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType WdgM_GetFirstExpiredSEID(WdgM_SupervisedEntityIdType *SEID)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_WdgM_General_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: GetFirstExpiredSEID_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, WdgM_Appl10_CODE) WdgM_GetFirstExpiredSEID(P2VAR(WdgM_SupervisedEntityIdType, AUTOMATIC, RTE_WDGM_APPL10_APPL_VAR) SEID) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: WdgM_GetFirstExpiredSEID (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: GetGlobalStatus
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetGlobalStatus> of PortPrototype <general_Core0>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType WdgM_GetGlobalStatus(WdgM_GlobalStatusType *Status)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_WdgM_General_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: GetGlobalStatus_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, WdgM_Appl10_CODE) WdgM_GetGlobalStatus(P2VAR(WdgM_GlobalStatusType, AUTOMATIC, RTE_WDGM_APPL10_APPL_VAR) Status) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: WdgM_GetGlobalStatus (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: GetLocalStatus
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetLocalStatus> of PortPrototype <general_Core0>
 *   - triggered by server invocation for OperationPrototype <GetLocalStatus> of PortPrototype <localStatus_SE_100ms_Appl10>
 *   - triggered by server invocation for OperationPrototype <GetLocalStatus> of PortPrototype <localStatus_SE_10msBsw_Appl10>
 *   - triggered by server invocation for OperationPrototype <GetLocalStatus> of PortPrototype <localStatus_SE_10ms_Appl10>
 *   - triggered by server invocation for OperationPrototype <GetLocalStatus> of PortPrototype <localStatus_SE_2msA_Appl10>
 *   - triggered by server invocation for OperationPrototype <GetLocalStatus> of PortPrototype <localStatus_SE_2msB_Appl10>
 *   - triggered by server invocation for OperationPrototype <GetLocalStatus> of PortPrototype <localStatus_SE_4ms_Appl10>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType WdgM_GetLocalStatus(WdgM_SupervisedEntityIdType SEID, WdgM_LocalStatusType *Status)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_WdgM_General_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: GetLocalStatus_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, WdgM_Appl10_CODE) WdgM_GetLocalStatus(WdgM_SupervisedEntityIdType SEID, P2VAR(WdgM_LocalStatusType, AUTOMATIC, RTE_WDGM_APPL10_APPL_VAR) Status) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: WdgM_GetLocalStatus (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: GetMode
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetMode> of PortPrototype <general_Core0>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType WdgM_GetMode(WdgM_ModeType *Mode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_WdgM_General_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: GetMode_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, WdgM_Appl10_CODE) WdgM_GetMode(P2VAR(WdgM_ModeType, AUTOMATIC, RTE_WDGM_APPL10_APPL_VAR) Mode) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: WdgM_GetMode (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PerformReset
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <PerformReset> of PortPrototype <general_Core0>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType WdgM_PerformReset(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_WdgM_General_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: PerformReset_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, WdgM_Appl10_CODE) WdgM_PerformReset(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: WdgM_PerformReset (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SetMode
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetMode> of PortPrototype <general_Core0>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType WdgM_SetMode(WdgM_ModeType Mode, uint16 CallerID)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_WdgM_General_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: SetMode_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, WdgM_Appl10_CODE) WdgM_SetMode(WdgM_ModeType Mode, uint16 CallerID) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: WdgM_SetMode (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: WdgM_MainFunction
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 4ms
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: WdgM_MainFunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, WdgM_Appl10_CODE) WdgM_MainFunction(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: WdgM_MainFunction
 *********************************************************************************************************************/

  TSC_WdgM_SchM_Enter_WdgM_WDGM_EXCLUSIVE_AREA_0();
  TSC_WdgM_SchM_Exit_WdgM_WDGM_EXCLUSIVE_AREA_0();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define WdgM_Appl10_STOP_SEC_CODE
#include "WdgM_Appl10_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void WdgM_Appl10_TestDefines(void)
{
  /* Enumeration Data Types */

  WdgM_GlobalStatusType Test_WdgM_GlobalStatusType_V_1 = WDGM_GLOBAL_STATUS_OK;
  WdgM_GlobalStatusType Test_WdgM_GlobalStatusType_V_2 = WDGM_GLOBAL_STATUS_FAILED;
  WdgM_GlobalStatusType Test_WdgM_GlobalStatusType_V_3 = WDGM_GLOBAL_STATUS_EXPIRED;
  WdgM_GlobalStatusType Test_WdgM_GlobalStatusType_V_4 = WDGM_GLOBAL_STATUS_STOPPED;
  WdgM_GlobalStatusType Test_WdgM_GlobalStatusType_V_5 = WDGM_GLOBAL_STATUS_DEACTIVATED;

  WdgM_LocalStatusType Test_WdgM_LocalStatusType_V_1 = WDGM_LOCAL_STATUS_OK;
  WdgM_LocalStatusType Test_WdgM_LocalStatusType_V_2 = WDGM_LOCAL_STATUS_FAILED;
  WdgM_LocalStatusType Test_WdgM_LocalStatusType_V_3 = WDGM_LOCAL_STATUS_EXPIRED;
  WdgM_LocalStatusType Test_WdgM_LocalStatusType_V_4 = WDGM_LOCAL_STATUS_DEACTIVATED;
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
