
/**********************************************************************************************************************
* Copyright 2015, 2016 Nxtr 
* Nxtr Confidential
*
* Module File Name:   CDD_NvMProxy_Cfg.c
* Module Description: Implementation of NvM Proxy ES006A
* Project           : CBD 
* Author            : Kevin Smith
***********************************************************************************************************************
* Version Control:
* %version:          27 %
* %derived_by:       tzyksv %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     --------
* 05/01/15  1        KJS       Initial Version                                                                 EA4#471
* 09/02/15  2        KJS       Set the ApplCallBack back to NULL_PTR at the start of each loop iteration       EA4#1484
* 01/26/16  3        KJS       Updated name of included header, NTC indexes, and file name to EA4 standards    EA4#3443
* 01/29/16  4        KJS       Removed CDD_ prefix from the module reference                                   EA4#6371
**********************************************************************************************************************/

#include "CDD_NvMProxy_Cfg_private.h"
#include "NvM.h"

/******************************************** File Level Rule Deviations *********************************************/
/* MISRA-C:2004 Rule 19.1 [NXTRDEV 19.1.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */

/********************************************* Embedded Local Constants **********************************************/

/******************************************* Module Specific Data Types **********************************************/

/******************************************** Module Specific Variables **********************************************/
#define CDD_NvMProxy_START_SEC_CONST_UNSPECIFIED
#include "CDD_NvMProxy_MemMap.h"

/* Table Contents: <NvM Block Number>, <Fault Response Index (0xFF, disabled)> */
const VAR(NvMProxyCrcFltDescrTblTyp, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) NvMProxy_CrcFltDescrTbl[] = {
    {NULL_PTR, 0x3AU, NTCCHKDISAD_CNT_U08}, /* Rte_NvmBlock_CDD_NvMProxy_ShtdwnClsChk */
    {NULL_PTR, 0x37U, NTCNR06IDX_CNT_U08}, /* Rte_NvmBlock_DiagcMgr_DiagcMgrApplCrc */
    {NULL_PTR, 0x39U, NTCNR06IDX_CNT_U08}, /* Rte_NvmBlock_DiagcMgr_DiagcMgrLtchCntrAry */
    {NULL_PTR, 0x38U, NTCNR06IDX_CNT_U08}, /* Rte_NvmBlock_DiagcMgr_DiagcMgrNtcFltAry */
    {NULL_PTR, 0x25U, NTCNR0AIDX_CNT_U08}, /* Rte_NvmBlock_PolarityCfg_PolarityCfgSaved */
    {NULL_PTR, 0x24U, NTCNR0AIDX_CNT_U08}, /* Rte_NvmBlock_CDD_MotAgCmp_MotAgCmpMotAgBackEmf */
    {NULL_PTR, 0x1FU, NTCNR06IDX_CNT_U08}, /* Rte_NvmBlock_HwTqCorrln_HwTqChACmnModCmpLpFilSt */
    {NULL_PTR, 0x1DU, NTCNR06IDX_CNT_U08}, /* Rte_NvmBlock_MotTqCmdSca_MotTqScaFac */
    {NULL_PTR, 0x1CU, NTCNR06IDX_CNT_U08}, /* Rte_NvmBlock_MotCtrlPrmEstimn_MotPrmNom */
    {NULL_PTR, 0x34U, NTCNR06IDX_CNT_U08}, /* Rte_NvmBlock_CDD_CurrMeas_CurrMeasEolGainCalSetABC */
    {NULL_PTR, 0x33U, NTCNR06IDX_CNT_U08}, /* Rte_NvmBlock_CDD_CurrMeas_CurrMeasEolOffsCalSetABC */
    {NULL_PTR, 0x23U, NTCNR0AIDX_CNT_U08}, /* Rte_NvmBlock_CDD_HwTq4Meas_HwTq4Offs_MirrorBlock */
    {NULL_PTR, 0x21U, NTCNR0AIDX_CNT_U08}, /* Rte_NvmBlock_CDD_HwTq4Meas_HwTq4Sca_MirrorBlock */
    {NULL_PTR, 0x22U, NTCNR0AIDX_CNT_U08}, /* Rte_NvmBlock_CDD_HwTq5Meas_HwTq5Offs_MirrorBlock */
    {NULL_PTR, 0x20U, NTCNR0AIDX_CNT_U08}, /* Rte_NvmBlock_CDD_HwTq5Meas_HwTq5Sca_MirrorBlock */
    {NULL_PTR, 0x36U, NTCNR08IDX_CNT_U08}, /* Rte_NvmBlock_CDD_MotAg0Meas_MotAg0CoeffTbl */
    {NULL_PTR, 0x35U, NTCNR08IDX_CNT_U08}, /* Rte_NvmBlock_CDD_MotAg1Meas_MotAg1CoeffTbl */
    {NULL_PTR, 0x31U, NTCNR06IDX_CNT_U08}, /* Rte_NvmBlock_CmnMfgSrv_CcaHwPartNr */
    {NULL_PTR, 0x30U, NTCNR06IDX_CNT_U08}, /* Rte_NvmBlock_CmnMfgSrv_CcaSerlNr */
    {NULL_PTR, 0x2FU, NTCNR06IDX_CNT_U08}, /* Rte_NvmBlock_CmnMfgSrv_DiRestore */
    {NULL_PTR, 0x2EU, NTCNR06IDX_CNT_U08}, /* Rte_NvmBlock_CmnMfgSrv_EpsSysSerlNr */
    {NULL_PTR, 0x2DU, NTCNR06IDX_CNT_U08}, /* Rte_NvmBlock_CmnMfgSrv_IgnCntr */
    {NULL_PTR, 0x2BU, NTCNR06IDX_CNT_U08}, /* Rte_NvmBlock_CmnMfgSrv_MfgTmpBuf0 */
    {NULL_PTR, 0x2AU, NTCNR06IDX_CNT_U08}, /* Rte_NvmBlock_CmnMfgSrv_MfgTmpBuf1 */
    {NULL_PTR, 0x29U, NTCNR06IDX_CNT_U08}, /* Rte_NvmBlock_CmnMfgSrv_MfgTmpBuf2 */
    {NULL_PTR, 0x28U, NTCNR06IDX_CNT_U08}, /* Rte_NvmBlock_CmnMfgSrv_MfgTmpBuf3 */
    {NULL_PTR, 0x27U, NTCNR06IDX_CNT_U08}, /* Rte_NvmBlock_CmnMfgSrv_MfgTmpBuf4 */
    {NULL_PTR, 0x2CU, NTCNR06IDX_CNT_U08}, /* Rte_NvmBlock_CmnMfgSrv_NxtrMfgEnaCntr */
    {NULL_PTR, 0x26U, NTCNR06IDX_CNT_U08}, /* Rte_NvmBlock_CmnMfgSrv_SeedKey */
    {NULL_PTR, 0x1EU, NTCNR08IDX_CNT_U08}, /* Rte_NvmBlock_DutyCycThermProtn_FilStVal */
    {NULL_PTR, 0x11U, NTCCHKDISAD_CNT_U08}, /* Rte_NvmBlock_CDD_VrfyCritReg_MCalReadVrfyCritRegFltInfo */
    {NULL_PTR, 0x10U, NTCNR06IDX_CNT_U08}, /* Rte_NvmBlock_BmwHwAgArbnAndEotPosn_BmwVehCentrOffs */
    {NULL_PTR, 0x0FU, NTCNR07IDX_CNT_U08}, /* Rte_NvmBlock_LrndRackCentr_LrndRackCentr */
    {NULL_PTR, 0x0EU, NTCNR06IDX_CNT_U08}, /* Rte_NvmBlock_ExcpnHndlg_McuDiagcData */
    {NULL_PTR, 0x0DU, NTCNR08IDX_CNT_U08}, /* Rte_NvmBlock_TEstimn_TFilStVal */
    {NULL_PTR, 0x0CU, NTCCHKDISAD_CNT_U08}, /* NVM_BLOCK_DLOG_SVK_ENTRY */
    {NULL_PTR, 0x0BU, NTCCHKDISAD_CNT_U08}, /* Rte_NvmBlock_Darh_DiagnoseMasterEnable */
    {NULL_PTR, 0x0AU, NTCCHKDISAD_CNT_U08}, /* Rte_NvmBlock_Coding_CodingData */
    {NULL_PTR, 0x09U, NTCNR06IDX_CNT_U08}, /* Rte_NvmBlock_BmwTunSetHndlr_BmwDesIninIdx */
    {NULL_PTR, 0x08U, NTCNR06IDX_CNT_U08}, /* Rte_NvmBlock_BmwTunSetHndlr_NvmBmwDesIninOptSetAIdx */
    {NULL_PTR, 0x07U, NTCCHKDISAD_CNT_U08}, /* Rte_NvmBlock_BmwDiagcSrvHndlg_MilesKmEeprom */
    {NULL_PTR, 0x06U, NTCCHKDISAD_CNT_U08}, /* Rte_NvmBlock_BmwDiagcSrvHndlg_ProgCntr */
    {NULL_PTR, 0x05U, NTCCHKDISAD_CNT_U08}, /* Rte_NvmBlock_BmwDiagcSrvHndlg_ProgCntrMaxVal */
    {NULL_PTR, 0x04U, NTCCHKDISAD_CNT_U08}, /* Rte_NvmBlock_BmwDiagcSrvHndlg_TestStamp */
    {NULL_PTR, 0x12U, NTCNR06IDX_CNT_U08}, /* Rte_NvmBlock_SysFricLrng_FricNonLrngData */
    {NULL_PTR, 0x13U, NTCNR06IDX_CNT_U08}, /* Rte_NvmBlock_SysFricLrng_FricLrngData */
    {NULL_PTR, 0x03U, NTCCHKDISAD_CNT_U08}  /* Rte_NvmBlock_PullCmpActv_PullCmpLongTerm */
};

#define CDD_NvMProxy_STOP_SEC_CONST_UNSPECIFIED
#include "CDD_NvMProxy_MemMap.h"

/******************************************** Local Function Prototypes **********************************************/

/*********************************************** Function Definitions ************************************************/

/* End of File */
