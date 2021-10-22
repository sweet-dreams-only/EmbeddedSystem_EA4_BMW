/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  NvMProxy.c
 *        Config:  EPS.dpa
 *     SW-C Type:  NvMProxy
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <NvMProxy>
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

#include "Rte_NvMProxy.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_NvMProxy.h"
#include "SchM_NvMProxy.h"
#include "TSC_SchM_NvMProxy.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"

static void NvMProxy_TestDefines(void);


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
 * NvM_BlockIdType: Integer in interval [1...32767]
 * boolean: Boolean (standard type)
 * dtRef_VOID: DataReference
 * dtRef_const_VOID: DataReference
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
 *
 *********************************************************************************************************************/


#define NvMProxy_START_SEC_CODE
#include "NvMProxy_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: EraseBlock
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PSProxy_NVM_BLOCK_BOOT_PROG_COUNTER>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PSProxy_NVM_BLOCK_BOOT_PROG_DATA>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PSProxy_NVM_BLOCK_BOOT_SVK_HISTORY>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PSProxy_NVM_BLOCK_DLOG_SVK_ENTRY>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PSProxy_NVM_BLOCK_DLOG_SVK_PLANT>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PSProxy_NVM_BLOCK_DLOG_SVK_SYS_SUPP>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PSProxy_Rte_NvmBlock_BmwDiagcSrvHndlg_MilesKmEeprom>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PSProxy_Rte_NvmBlock_BmwDiagcSrvHndlg_ProgCntr>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PSProxy_Rte_NvmBlock_BmwDiagcSrvHndlg_ProgCntrMaxVal>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PSProxy_Rte_NvmBlock_BmwDiagcSrvHndlg_TestStamp>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PSProxy_Rte_NvmBlock_BmwHwAgArbnAndEotPosn_BmwVehCentrOffs>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PSProxy_Rte_NvmBlock_BmwTunSetHndlr_BmwDesIninIdx>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PSProxy_Rte_NvmBlock_BmwTunSetHndlr_NvmBmwDesIninOptSetAIdx>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CDD_CurrMeas_CurrMeasEolGainCalSetABC>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CDD_CurrMeas_CurrMeasEolOffsCalSetABC>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CDD_HwTq4Meas_HwTq4Offs_MirrorBlock>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CDD_HwTq4Meas_HwTq4Sca_MirrorBlock>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CDD_HwTq5Meas_HwTq5Offs_MirrorBlock>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CDD_HwTq5Meas_HwTq5Sca_MirrorBlock>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CDD_MotAg0Meas_MotAg0CoeffTbl>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CDD_MotAg1Meas_MotAg1CoeffTbl>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CDD_MotAgCmp_MotAgCmpMotAgBackEmf>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CDD_NvMProxy_ShtdwnClsChk>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CDD_VrfyCritReg_MCalReadVrfyCritRegFltInfo>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_CcaHwPartNr>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_CcaSerlNr>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_DiRestore>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_EpsSysSerlNr>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_IgnCntr>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_MfgTmpBuf0>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_MfgTmpBuf1>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_MfgTmpBuf2>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_MfgTmpBuf3>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_MfgTmpBuf4>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_NxtrMfgEnaCntr>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_SeedKey>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PSProxy_Rte_NvmBlock_Coding_CodingData>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PSProxy_Rte_NvmBlock_Darh_DiagnoseMasterEnable>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PSProxy_Rte_NvmBlock_Darh_ErrorQueue>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PSProxy_Rte_NvmBlock_DiagcMgr_DiagcMgrApplCrc>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PSProxy_Rte_NvmBlock_DiagcMgr_DiagcMgrLtchCntrAry>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PSProxy_Rte_NvmBlock_DiagcMgr_DiagcMgrNtcFltAry>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PSProxy_Rte_NvmBlock_DutyCycThermProtn_FilStVal>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PSProxy_Rte_NvmBlock_ExcpnHndlg_McuDiagcData>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PSProxy_Rte_NvmBlock_HwTqCorrln_HwTqChACmnModCmpLpFilSt>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PSProxy_Rte_NvmBlock_LrndRackCentr_LrndRackCentr>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PSProxy_Rte_NvmBlock_MotCtrlPrmEstimn_MotPrmNom>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PSProxy_Rte_NvmBlock_MotTqCmdSca_MotTqScaFac>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PSProxy_Rte_NvmBlock_Omc>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PSProxy_Rte_NvmBlock_PolarityCfg_PolarityCfgSaved>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PSProxy_Rte_NvmBlock_PullCmpActv_PullCmpLongTerm>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PSProxy_Rte_NvmBlock_TEstimn_TFilStVal>
 *   - triggered by server invocation for OperationPrototype <EraseBlock> of PortPrototype <PSProxy_Rte_NvmBlock_Vin>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType NvMProxy_EraseNvBlock(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: EraseBlock_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, NvMProxy_CODE) NvMProxy_EraseNvBlock(NvM_BlockIdType parg0) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMProxy_EraseNvBlock (returns application error)
 *********************************************************************************************************************/

  NvMProxy_TestDefines();

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: GetDataIndex
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetDataIndex> of PortPrototype <PSProxy_NVM_BLOCK_DLOG_SVK_ENTRY>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType NvMProxy_GetDataIndex(uint8 *DataIndex_Arg)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_NvMService_AC3_SRBS_DS_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: GetDataIndex_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, NvMProxy_CODE) NvMProxy_GetDataIndex(NvM_BlockIdType parg0, P2VAR(uint8, AUTOMATIC, RTE_NVMPROXY_APPL_VAR) DataIndex_Arg) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMProxy_GetDataIndex (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: GetErrorStatus
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PSProxy_NVM_BLOCK_BOOT_PROG_COUNTER>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PSProxy_NVM_BLOCK_BOOT_PROG_DATA>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PSProxy_NVM_BLOCK_BOOT_SVK_HISTORY>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PSProxy_NVM_BLOCK_DLOG_SVK_ENTRY>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PSProxy_NVM_BLOCK_DLOG_SVK_PLANT>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PSProxy_NVM_BLOCK_DLOG_SVK_SYS_SUPP>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PSProxy_Rte_NvmBlock_BmwDiagcSrvHndlg_MilesKmEeprom>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PSProxy_Rte_NvmBlock_BmwDiagcSrvHndlg_ProgCntr>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PSProxy_Rte_NvmBlock_BmwDiagcSrvHndlg_ProgCntrMaxVal>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PSProxy_Rte_NvmBlock_BmwDiagcSrvHndlg_TestStamp>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PSProxy_Rte_NvmBlock_BmwHwAgArbnAndEotPosn_BmwVehCentrOffs>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PSProxy_Rte_NvmBlock_BmwTunSetHndlr_BmwDesIninIdx>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PSProxy_Rte_NvmBlock_BmwTunSetHndlr_NvmBmwDesIninOptSetAIdx>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PSProxy_Rte_NvmBlock_CDD_CurrMeas_CurrMeasEolGainCalSetABC>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PSProxy_Rte_NvmBlock_CDD_CurrMeas_CurrMeasEolOffsCalSetABC>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PSProxy_Rte_NvmBlock_CDD_HwTq4Meas_HwTq4Offs_MirrorBlock>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PSProxy_Rte_NvmBlock_CDD_HwTq4Meas_HwTq4Sca_MirrorBlock>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PSProxy_Rte_NvmBlock_CDD_HwTq5Meas_HwTq5Offs_MirrorBlock>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PSProxy_Rte_NvmBlock_CDD_HwTq5Meas_HwTq5Sca_MirrorBlock>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PSProxy_Rte_NvmBlock_CDD_MotAg0Meas_MotAg0CoeffTbl>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PSProxy_Rte_NvmBlock_CDD_MotAg1Meas_MotAg1CoeffTbl>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PSProxy_Rte_NvmBlock_CDD_MotAgCmp_MotAgCmpMotAgBackEmf>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PSProxy_Rte_NvmBlock_CDD_NvMProxy_ShtdwnClsChk>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PSProxy_Rte_NvmBlock_CDD_VrfyCritReg_MCalReadVrfyCritRegFltInfo>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_CcaHwPartNr>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_CcaSerlNr>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_DiRestore>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_EpsSysSerlNr>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_IgnCntr>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_MfgTmpBuf0>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_MfgTmpBuf1>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_MfgTmpBuf2>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_MfgTmpBuf3>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_MfgTmpBuf4>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_NxtrMfgEnaCntr>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_SeedKey>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PSProxy_Rte_NvmBlock_Coding_CodingData>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PSProxy_Rte_NvmBlock_Darh_DiagnoseMasterEnable>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PSProxy_Rte_NvmBlock_Darh_ErrorQueue>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PSProxy_Rte_NvmBlock_DiagcMgr_DiagcMgrApplCrc>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PSProxy_Rte_NvmBlock_DiagcMgr_DiagcMgrLtchCntrAry>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PSProxy_Rte_NvmBlock_DiagcMgr_DiagcMgrNtcFltAry>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PSProxy_Rte_NvmBlock_DutyCycThermProtn_FilStVal>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PSProxy_Rte_NvmBlock_ExcpnHndlg_McuDiagcData>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PSProxy_Rte_NvmBlock_HwTqCorrln_HwTqChACmnModCmpLpFilSt>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PSProxy_Rte_NvmBlock_LrndRackCentr_LrndRackCentr>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PSProxy_Rte_NvmBlock_MotCtrlPrmEstimn_MotPrmNom>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PSProxy_Rte_NvmBlock_MotTqCmdSca_MotTqScaFac>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PSProxy_Rte_NvmBlock_Omc>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PSProxy_Rte_NvmBlock_PolarityCfg_PolarityCfgSaved>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PSProxy_Rte_NvmBlock_PullCmpActv_PullCmpLongTerm>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PSProxy_Rte_NvmBlock_TEstimn_TFilStVal>
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <PSProxy_Rte_NvmBlock_Vin>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType NvMProxy_GetErrorStatus(NvM_RequestResultType *ErrorStatus_Arg)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: GetErrorStatus_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, NvMProxy_CODE) NvMProxy_GetErrorStatus(NvM_BlockIdType parg0, P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_NVMPROXY_APPL_VAR) ErrorStatus_Arg) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMProxy_GetErrorStatus (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: InvalidateNvBlock
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PSProxy_NVM_BLOCK_BOOT_PROG_COUNTER>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PSProxy_NVM_BLOCK_BOOT_PROG_DATA>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PSProxy_NVM_BLOCK_BOOT_SVK_HISTORY>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PSProxy_NVM_BLOCK_DLOG_SVK_ENTRY>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PSProxy_NVM_BLOCK_DLOG_SVK_PLANT>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PSProxy_NVM_BLOCK_DLOG_SVK_SYS_SUPP>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PSProxy_Rte_NvmBlock_BmwDiagcSrvHndlg_MilesKmEeprom>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PSProxy_Rte_NvmBlock_BmwDiagcSrvHndlg_ProgCntr>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PSProxy_Rte_NvmBlock_BmwDiagcSrvHndlg_ProgCntrMaxVal>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PSProxy_Rte_NvmBlock_BmwDiagcSrvHndlg_TestStamp>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PSProxy_Rte_NvmBlock_BmwHwAgArbnAndEotPosn_BmwVehCentrOffs>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PSProxy_Rte_NvmBlock_BmwTunSetHndlr_BmwDesIninIdx>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PSProxy_Rte_NvmBlock_BmwTunSetHndlr_NvmBmwDesIninOptSetAIdx>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CDD_CurrMeas_CurrMeasEolGainCalSetABC>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CDD_CurrMeas_CurrMeasEolOffsCalSetABC>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CDD_HwTq4Meas_HwTq4Offs_MirrorBlock>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CDD_HwTq4Meas_HwTq4Sca_MirrorBlock>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CDD_HwTq5Meas_HwTq5Offs_MirrorBlock>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CDD_HwTq5Meas_HwTq5Sca_MirrorBlock>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CDD_MotAg0Meas_MotAg0CoeffTbl>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CDD_MotAg1Meas_MotAg1CoeffTbl>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CDD_MotAgCmp_MotAgCmpMotAgBackEmf>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CDD_NvMProxy_ShtdwnClsChk>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CDD_VrfyCritReg_MCalReadVrfyCritRegFltInfo>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_CcaHwPartNr>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_CcaSerlNr>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_DiRestore>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_EpsSysSerlNr>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_IgnCntr>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_MfgTmpBuf0>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_MfgTmpBuf1>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_MfgTmpBuf2>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_MfgTmpBuf3>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_MfgTmpBuf4>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_NxtrMfgEnaCntr>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_SeedKey>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PSProxy_Rte_NvmBlock_Coding_CodingData>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PSProxy_Rte_NvmBlock_Darh_DiagnoseMasterEnable>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PSProxy_Rte_NvmBlock_Darh_ErrorQueue>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PSProxy_Rte_NvmBlock_DiagcMgr_DiagcMgrApplCrc>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PSProxy_Rte_NvmBlock_DiagcMgr_DiagcMgrLtchCntrAry>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PSProxy_Rte_NvmBlock_DiagcMgr_DiagcMgrNtcFltAry>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PSProxy_Rte_NvmBlock_DutyCycThermProtn_FilStVal>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PSProxy_Rte_NvmBlock_ExcpnHndlg_McuDiagcData>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PSProxy_Rte_NvmBlock_HwTqCorrln_HwTqChACmnModCmpLpFilSt>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PSProxy_Rte_NvmBlock_LrndRackCentr_LrndRackCentr>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PSProxy_Rte_NvmBlock_MotCtrlPrmEstimn_MotPrmNom>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PSProxy_Rte_NvmBlock_MotTqCmdSca_MotTqScaFac>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PSProxy_Rte_NvmBlock_Omc>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PSProxy_Rte_NvmBlock_PolarityCfg_PolarityCfgSaved>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PSProxy_Rte_NvmBlock_PullCmpActv_PullCmpLongTerm>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PSProxy_Rte_NvmBlock_TEstimn_TFilStVal>
 *   - triggered by server invocation for OperationPrototype <InvalidateNvBlock> of PortPrototype <PSProxy_Rte_NvmBlock_Vin>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType NvMProxy_InvalidateNvBlock(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: InvalidateNvBlock_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, NvMProxy_CODE) NvMProxy_InvalidateNvBlock(NvM_BlockIdType parg0) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMProxy_InvalidateNvBlock (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NvMProxy_MainFunction
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMProxy_MainFunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, NvMProxy_CODE) NvMProxy_MainFunction(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMProxy_MainFunction
 *********************************************************************************************************************/

  TSC_NvMProxy_SchM_Enter_NvMProxy_NvMProxy_EXCLUSIVE_AREA_0();
  TSC_NvMProxy_SchM_Exit_NvMProxy_NvMProxy_EXCLUSIVE_AREA_0();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ReadBlock
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PSProxy_NVM_BLOCK_BOOT_PROG_COUNTER>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PSProxy_NVM_BLOCK_BOOT_PROG_DATA>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PSProxy_NVM_BLOCK_BOOT_SVK_HISTORY>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PSProxy_NVM_BLOCK_DLOG_SVK_ENTRY>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PSProxy_NVM_BLOCK_DLOG_SVK_PLANT>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PSProxy_NVM_BLOCK_DLOG_SVK_SYS_SUPP>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PSProxy_Rte_NvmBlock_BmwDiagcSrvHndlg_MilesKmEeprom>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PSProxy_Rte_NvmBlock_BmwDiagcSrvHndlg_ProgCntr>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PSProxy_Rte_NvmBlock_BmwDiagcSrvHndlg_ProgCntrMaxVal>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PSProxy_Rte_NvmBlock_BmwDiagcSrvHndlg_TestStamp>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PSProxy_Rte_NvmBlock_BmwHwAgArbnAndEotPosn_BmwVehCentrOffs>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PSProxy_Rte_NvmBlock_BmwTunSetHndlr_BmwDesIninIdx>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PSProxy_Rte_NvmBlock_BmwTunSetHndlr_NvmBmwDesIninOptSetAIdx>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CDD_CurrMeas_CurrMeasEolGainCalSetABC>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CDD_CurrMeas_CurrMeasEolOffsCalSetABC>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CDD_HwTq4Meas_HwTq4Offs_MirrorBlock>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CDD_HwTq4Meas_HwTq4Sca_MirrorBlock>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CDD_HwTq5Meas_HwTq5Offs_MirrorBlock>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CDD_HwTq5Meas_HwTq5Sca_MirrorBlock>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CDD_MotAg0Meas_MotAg0CoeffTbl>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CDD_MotAg1Meas_MotAg1CoeffTbl>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CDD_MotAgCmp_MotAgCmpMotAgBackEmf>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CDD_NvMProxy_ShtdwnClsChk>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CDD_VrfyCritReg_MCalReadVrfyCritRegFltInfo>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_CcaHwPartNr>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_CcaSerlNr>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_DiRestore>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_EpsSysSerlNr>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_IgnCntr>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_MfgTmpBuf0>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_MfgTmpBuf1>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_MfgTmpBuf2>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_MfgTmpBuf3>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_MfgTmpBuf4>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_NxtrMfgEnaCntr>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_SeedKey>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PSProxy_Rte_NvmBlock_Coding_CodingData>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PSProxy_Rte_NvmBlock_Darh_DiagnoseMasterEnable>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PSProxy_Rte_NvmBlock_Darh_ErrorQueue>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PSProxy_Rte_NvmBlock_DiagcMgr_DiagcMgrApplCrc>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PSProxy_Rte_NvmBlock_DiagcMgr_DiagcMgrLtchCntrAry>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PSProxy_Rte_NvmBlock_DiagcMgr_DiagcMgrNtcFltAry>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PSProxy_Rte_NvmBlock_DutyCycThermProtn_FilStVal>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PSProxy_Rte_NvmBlock_ExcpnHndlg_McuDiagcData>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PSProxy_Rte_NvmBlock_HwTqCorrln_HwTqChACmnModCmpLpFilSt>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PSProxy_Rte_NvmBlock_LrndRackCentr_LrndRackCentr>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PSProxy_Rte_NvmBlock_MotCtrlPrmEstimn_MotPrmNom>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PSProxy_Rte_NvmBlock_MotTqCmdSca_MotTqScaFac>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PSProxy_Rte_NvmBlock_Omc>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PSProxy_Rte_NvmBlock_PolarityCfg_PolarityCfgSaved>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PSProxy_Rte_NvmBlock_PullCmpActv_PullCmpLongTerm>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PSProxy_Rte_NvmBlock_TEstimn_TFilStVal>
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <PSProxy_Rte_NvmBlock_Vin>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType NvMProxy_ReadBlock(dtRef_VOID DstPtr_Arg)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ReadBlock_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, NvMProxy_CODE) NvMProxy_ReadBlock(NvM_BlockIdType parg0, dtRef_VOID DstPtr_Arg) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMProxy_ReadBlock (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RestoreBlockDefaults
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <RestoreBlockDefaults> of PortPrototype <PSProxy_Rte_NvmBlock_BmwDiagcSrvHndlg_ProgCntrMaxVal>
 *   - triggered by server invocation for OperationPrototype <RestoreBlockDefaults> of PortPrototype <PSProxy_Rte_NvmBlock_BmwTunSetHndlr_BmwDesIninIdx>
 *   - triggered by server invocation for OperationPrototype <RestoreBlockDefaults> of PortPrototype <PSProxy_Rte_NvmBlock_BmwTunSetHndlr_NvmBmwDesIninOptSetAIdx>
 *   - triggered by server invocation for OperationPrototype <RestoreBlockDefaults> of PortPrototype <PSProxy_Rte_NvmBlock_CDD_CurrMeas_CurrMeasEolGainCalSetABC>
 *   - triggered by server invocation for OperationPrototype <RestoreBlockDefaults> of PortPrototype <PSProxy_Rte_NvmBlock_CDD_CurrMeas_CurrMeasEolOffsCalSetABC>
 *   - triggered by server invocation for OperationPrototype <RestoreBlockDefaults> of PortPrototype <PSProxy_Rte_NvmBlock_CDD_MotAgCmp_MotAgCmpMotAgBackEmf>
 *   - triggered by server invocation for OperationPrototype <RestoreBlockDefaults> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_IgnCntr>
 *   - triggered by server invocation for OperationPrototype <RestoreBlockDefaults> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_NxtrMfgEnaCntr>
 *   - triggered by server invocation for OperationPrototype <RestoreBlockDefaults> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_SeedKey>
 *   - triggered by server invocation for OperationPrototype <RestoreBlockDefaults> of PortPrototype <PSProxy_Rte_NvmBlock_Coding_CodingData>
 *   - triggered by server invocation for OperationPrototype <RestoreBlockDefaults> of PortPrototype <PSProxy_Rte_NvmBlock_Darh_ErrorQueue>
 *   - triggered by server invocation for OperationPrototype <RestoreBlockDefaults> of PortPrototype <PSProxy_Rte_NvmBlock_DiagcMgr_DiagcMgrApplCrc>
 *   - triggered by server invocation for OperationPrototype <RestoreBlockDefaults> of PortPrototype <PSProxy_Rte_NvmBlock_ExcpnHndlg_McuDiagcData>
 *   - triggered by server invocation for OperationPrototype <RestoreBlockDefaults> of PortPrototype <PSProxy_Rte_NvmBlock_HwTqCorrln_HwTqChACmnModCmpLpFilSt>
 *   - triggered by server invocation for OperationPrototype <RestoreBlockDefaults> of PortPrototype <PSProxy_Rte_NvmBlock_Omc>
 *   - triggered by server invocation for OperationPrototype <RestoreBlockDefaults> of PortPrototype <PSProxy_Rte_NvmBlock_PolarityCfg_PolarityCfgSaved>
 *   - triggered by server invocation for OperationPrototype <RestoreBlockDefaults> of PortPrototype <PSProxy_Rte_NvmBlock_PullCmpActv_PullCmpLongTerm>
 *   - triggered by server invocation for OperationPrototype <RestoreBlockDefaults> of PortPrototype <PSProxy_Rte_NvmBlock_Vin>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType NvMProxy_RestoreBlockDefaults(dtRef_VOID DstPtr_Arg)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RestoreBlockDefaults_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, NvMProxy_CODE) NvMProxy_RestoreBlockDefaults(NvM_BlockIdType parg0, dtRef_VOID DstPtr_Arg) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMProxy_RestoreBlockDefaults (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SetBlockProtection
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdminProxy_NVM_BLOCK_BOOT_PROG_COUNTER>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdminProxy_NVM_BLOCK_BOOT_PROG_DATA>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdminProxy_NVM_BLOCK_BOOT_SVK_HISTORY>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdminProxy_NVM_BLOCK_DLOG_SVK_ENTRY>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdminProxy_NVM_BLOCK_DLOG_SVK_PLANT>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdminProxy_NVM_BLOCK_DLOG_SVK_SYS_SUPP>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdminProxy_Rte_NvmBlock_BmwDiagcSrvHndlg_MilesKmEeprom>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdminProxy_Rte_NvmBlock_BmwDiagcSrvHndlg_ProgCntr>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdminProxy_Rte_NvmBlock_BmwDiagcSrvHndlg_ProgCntrMaxVal>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdminProxy_Rte_NvmBlock_BmwDiagcSrvHndlg_TestStamp>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdminProxy_Rte_NvmBlock_BmwHwAgArbnAndEotPosn_BmwVehCentrOffs>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdminProxy_Rte_NvmBlock_BmwTunSetHndlr_BmwDesIninIdx>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdminProxy_Rte_NvmBlock_BmwTunSetHndlr_NvmBmwDesIninOptSetAIdx>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdminProxy_Rte_NvmBlock_CDD_CurrMeas_CurrMeasEolGainCalSetABC>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdminProxy_Rte_NvmBlock_CDD_CurrMeas_CurrMeasEolOffsCalSetABC>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdminProxy_Rte_NvmBlock_CDD_HwTq4Meas_HwTq4Offs_MirrorBlock>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdminProxy_Rte_NvmBlock_CDD_HwTq4Meas_HwTq4Sca_MirrorBlock>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdminProxy_Rte_NvmBlock_CDD_HwTq5Meas_HwTq5Offs_MirrorBlock>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdminProxy_Rte_NvmBlock_CDD_HwTq5Meas_HwTq5Sca_MirrorBlock>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdminProxy_Rte_NvmBlock_CDD_MotAg0Meas_MotAg0CoeffTbl>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdminProxy_Rte_NvmBlock_CDD_MotAg1Meas_MotAg1CoeffTbl>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdminProxy_Rte_NvmBlock_CDD_MotAgCmp_MotAgCmpMotAgBackEmf>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdminProxy_Rte_NvmBlock_CDD_NvMProxy_ShtdwnClsChk>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdminProxy_Rte_NvmBlock_CDD_VrfyCritReg_MCalReadVrfyCritRegFltInfo>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdminProxy_Rte_NvmBlock_CmnMfgSrv_CcaHwPartNr>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdminProxy_Rte_NvmBlock_CmnMfgSrv_CcaSerlNr>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdminProxy_Rte_NvmBlock_CmnMfgSrv_DiRestore>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdminProxy_Rte_NvmBlock_CmnMfgSrv_EpsSysSerlNr>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdminProxy_Rte_NvmBlock_CmnMfgSrv_IgnCntr>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdminProxy_Rte_NvmBlock_CmnMfgSrv_MfgTmpBuf0>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdminProxy_Rte_NvmBlock_CmnMfgSrv_MfgTmpBuf1>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdminProxy_Rte_NvmBlock_CmnMfgSrv_MfgTmpBuf2>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdminProxy_Rte_NvmBlock_CmnMfgSrv_MfgTmpBuf3>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdminProxy_Rte_NvmBlock_CmnMfgSrv_MfgTmpBuf4>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdminProxy_Rte_NvmBlock_CmnMfgSrv_NxtrMfgEnaCntr>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdminProxy_Rte_NvmBlock_CmnMfgSrv_SeedKey>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdminProxy_Rte_NvmBlock_Coding_CodingData>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdminProxy_Rte_NvmBlock_Darh_DiagnoseMasterEnable>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdminProxy_Rte_NvmBlock_Darh_ErrorQueue>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdminProxy_Rte_NvmBlock_DiagcMgr_DiagcMgrApplCrc>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdminProxy_Rte_NvmBlock_DiagcMgr_DiagcMgrLtchCntrAry>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdminProxy_Rte_NvmBlock_DiagcMgr_DiagcMgrNtcFltAry>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdminProxy_Rte_NvmBlock_DutyCycThermProtn_FilStVal>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdminProxy_Rte_NvmBlock_ExcpnHndlg_McuDiagcData>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdminProxy_Rte_NvmBlock_HwTqCorrln_HwTqChACmnModCmpLpFilSt>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdminProxy_Rte_NvmBlock_LrndRackCentr_LrndRackCentr>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdminProxy_Rte_NvmBlock_MotCtrlPrmEstimn_MotPrmNom>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdminProxy_Rte_NvmBlock_MotTqCmdSca_MotTqScaFac>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdminProxy_Rte_NvmBlock_Omc>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdminProxy_Rte_NvmBlock_PolarityCfg_PolarityCfgSaved>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdminProxy_Rte_NvmBlock_PullCmpActv_PullCmpLongTerm>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdminProxy_Rte_NvmBlock_TEstimn_TFilStVal>
 *   - triggered by server invocation for OperationPrototype <SetBlockProtection> of PortPrototype <PAdminProxy_Rte_NvmBlock_Vin>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType NvMProxy_SetBlockProtection(boolean ProtectionEnabled_Arg)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_NvMAdministration_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: SetBlockProtection_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, NvMProxy_CODE) NvMProxy_SetBlockProtection(NvM_BlockIdType parg0, boolean ProtectionEnabled_Arg) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMProxy_SetBlockProtection (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SetRamBlockStatus
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PSProxy_NVM_BLOCK_BOOT_PROG_COUNTER>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PSProxy_NVM_BLOCK_BOOT_PROG_DATA>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PSProxy_NVM_BLOCK_BOOT_SVK_HISTORY>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PSProxy_NVM_BLOCK_DLOG_SVK_ENTRY>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PSProxy_NVM_BLOCK_DLOG_SVK_PLANT>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PSProxy_NVM_BLOCK_DLOG_SVK_SYS_SUPP>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PSProxy_Rte_NvmBlock_BmwDiagcSrvHndlg_MilesKmEeprom>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PSProxy_Rte_NvmBlock_BmwDiagcSrvHndlg_ProgCntr>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PSProxy_Rte_NvmBlock_BmwDiagcSrvHndlg_ProgCntrMaxVal>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PSProxy_Rte_NvmBlock_BmwDiagcSrvHndlg_TestStamp>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PSProxy_Rte_NvmBlock_BmwHwAgArbnAndEotPosn_BmwVehCentrOffs>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PSProxy_Rte_NvmBlock_BmwTunSetHndlr_BmwDesIninIdx>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PSProxy_Rte_NvmBlock_BmwTunSetHndlr_NvmBmwDesIninOptSetAIdx>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PSProxy_Rte_NvmBlock_CDD_CurrMeas_CurrMeasEolGainCalSetABC>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PSProxy_Rte_NvmBlock_CDD_CurrMeas_CurrMeasEolOffsCalSetABC>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PSProxy_Rte_NvmBlock_CDD_HwTq4Meas_HwTq4Offs_MirrorBlock>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PSProxy_Rte_NvmBlock_CDD_HwTq4Meas_HwTq4Sca_MirrorBlock>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PSProxy_Rte_NvmBlock_CDD_HwTq5Meas_HwTq5Offs_MirrorBlock>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PSProxy_Rte_NvmBlock_CDD_HwTq5Meas_HwTq5Sca_MirrorBlock>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PSProxy_Rte_NvmBlock_CDD_MotAg0Meas_MotAg0CoeffTbl>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PSProxy_Rte_NvmBlock_CDD_MotAg1Meas_MotAg1CoeffTbl>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PSProxy_Rte_NvmBlock_CDD_MotAgCmp_MotAgCmpMotAgBackEmf>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PSProxy_Rte_NvmBlock_CDD_NvMProxy_ShtdwnClsChk>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PSProxy_Rte_NvmBlock_CDD_VrfyCritReg_MCalReadVrfyCritRegFltInfo>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_CcaHwPartNr>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_CcaSerlNr>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_DiRestore>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_EpsSysSerlNr>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_IgnCntr>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_MfgTmpBuf0>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_MfgTmpBuf1>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_MfgTmpBuf2>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_MfgTmpBuf3>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_MfgTmpBuf4>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_NxtrMfgEnaCntr>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_SeedKey>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PSProxy_Rte_NvmBlock_Coding_CodingData>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PSProxy_Rte_NvmBlock_Darh_DiagnoseMasterEnable>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PSProxy_Rte_NvmBlock_Darh_ErrorQueue>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PSProxy_Rte_NvmBlock_DiagcMgr_DiagcMgrApplCrc>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PSProxy_Rte_NvmBlock_DiagcMgr_DiagcMgrLtchCntrAry>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PSProxy_Rte_NvmBlock_DiagcMgr_DiagcMgrNtcFltAry>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PSProxy_Rte_NvmBlock_DutyCycThermProtn_FilStVal>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PSProxy_Rte_NvmBlock_ExcpnHndlg_McuDiagcData>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PSProxy_Rte_NvmBlock_HwTqCorrln_HwTqChACmnModCmpLpFilSt>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PSProxy_Rte_NvmBlock_LrndRackCentr_LrndRackCentr>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PSProxy_Rte_NvmBlock_MotCtrlPrmEstimn_MotPrmNom>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PSProxy_Rte_NvmBlock_MotTqCmdSca_MotTqScaFac>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PSProxy_Rte_NvmBlock_Omc>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PSProxy_Rte_NvmBlock_PolarityCfg_PolarityCfgSaved>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PSProxy_Rte_NvmBlock_PullCmpActv_PullCmpLongTerm>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PSProxy_Rte_NvmBlock_TEstimn_TFilStVal>
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <PSProxy_Rte_NvmBlock_Vin>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType NvMProxy_SetRamBlockStatus(boolean RamBlockStatus_Arg)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: SetRamBlockStatus_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, NvMProxy_CODE) NvMProxy_SetRamBlockStatus(NvM_BlockIdType parg0, boolean RamBlockStatus_Arg) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMProxy_SetRamBlockStatus (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: WriteBlock
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PSProxy_NVM_BLOCK_BOOT_PROG_COUNTER>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PSProxy_NVM_BLOCK_BOOT_PROG_DATA>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PSProxy_NVM_BLOCK_BOOT_SVK_HISTORY>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PSProxy_NVM_BLOCK_DLOG_SVK_ENTRY>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PSProxy_NVM_BLOCK_DLOG_SVK_PLANT>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PSProxy_NVM_BLOCK_DLOG_SVK_SYS_SUPP>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PSProxy_Rte_NvmBlock_BmwDiagcSrvHndlg_MilesKmEeprom>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PSProxy_Rte_NvmBlock_BmwDiagcSrvHndlg_ProgCntr>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PSProxy_Rte_NvmBlock_BmwDiagcSrvHndlg_ProgCntrMaxVal>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PSProxy_Rte_NvmBlock_BmwDiagcSrvHndlg_TestStamp>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PSProxy_Rte_NvmBlock_BmwHwAgArbnAndEotPosn_BmwVehCentrOffs>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PSProxy_Rte_NvmBlock_BmwTunSetHndlr_BmwDesIninIdx>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PSProxy_Rte_NvmBlock_BmwTunSetHndlr_NvmBmwDesIninOptSetAIdx>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CDD_CurrMeas_CurrMeasEolGainCalSetABC>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CDD_CurrMeas_CurrMeasEolOffsCalSetABC>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CDD_HwTq4Meas_HwTq4Offs_MirrorBlock>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CDD_HwTq4Meas_HwTq4Sca_MirrorBlock>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CDD_HwTq5Meas_HwTq5Offs_MirrorBlock>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CDD_HwTq5Meas_HwTq5Sca_MirrorBlock>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CDD_MotAg0Meas_MotAg0CoeffTbl>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CDD_MotAg1Meas_MotAg1CoeffTbl>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CDD_MotAgCmp_MotAgCmpMotAgBackEmf>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CDD_NvMProxy_ShtdwnClsChk>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CDD_VrfyCritReg_MCalReadVrfyCritRegFltInfo>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_CcaHwPartNr>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_CcaSerlNr>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_DiRestore>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_EpsSysSerlNr>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_IgnCntr>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_MfgTmpBuf0>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_MfgTmpBuf1>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_MfgTmpBuf2>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_MfgTmpBuf3>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_MfgTmpBuf4>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_NxtrMfgEnaCntr>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PSProxy_Rte_NvmBlock_CmnMfgSrv_SeedKey>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PSProxy_Rte_NvmBlock_Coding_CodingData>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PSProxy_Rte_NvmBlock_Darh_DiagnoseMasterEnable>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PSProxy_Rte_NvmBlock_Darh_ErrorQueue>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PSProxy_Rte_NvmBlock_DiagcMgr_DiagcMgrApplCrc>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PSProxy_Rte_NvmBlock_DiagcMgr_DiagcMgrLtchCntrAry>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PSProxy_Rte_NvmBlock_DiagcMgr_DiagcMgrNtcFltAry>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PSProxy_Rte_NvmBlock_DutyCycThermProtn_FilStVal>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PSProxy_Rte_NvmBlock_ExcpnHndlg_McuDiagcData>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PSProxy_Rte_NvmBlock_HwTqCorrln_HwTqChACmnModCmpLpFilSt>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PSProxy_Rte_NvmBlock_LrndRackCentr_LrndRackCentr>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PSProxy_Rte_NvmBlock_MotCtrlPrmEstimn_MotPrmNom>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PSProxy_Rte_NvmBlock_MotTqCmdSca_MotTqScaFac>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PSProxy_Rte_NvmBlock_Omc>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PSProxy_Rte_NvmBlock_PolarityCfg_PolarityCfgSaved>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PSProxy_Rte_NvmBlock_PullCmpActv_PullCmpLongTerm>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PSProxy_Rte_NvmBlock_TEstimn_TFilStVal>
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <PSProxy_Rte_NvmBlock_Vin>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType NvMProxy_WriteBlock(dtRef_const_VOID SrcPtr_Arg)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: WriteBlock_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, NvMProxy_CODE) NvMProxy_WriteBlock(NvM_BlockIdType parg0, dtRef_const_VOID SrcPtr_Arg) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMProxy_WriteBlock (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define NvMProxy_STOP_SEC_CODE
#include "NvMProxy_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void NvMProxy_TestDefines(void)
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
