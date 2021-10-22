/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_Dlog.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <Dlog>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_DLOG_H
# define _RTE_DLOG_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
#  ifndef RTE_PTR2ARRAYBASETYPE_PASSING
#   define RTE_PTR2ARRAYBASETYPE_PASSING
#  endif
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_Dlog_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(Dlog_LifeCycleRequestType, RTE_VAR_INIT) Rte_BswM_Provide_MSRP_Dlog_requestMode; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_LifeCycleRequest_requestMode (2U)
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Buffers for implicit communication
 *********************************************************************************************************************/

# endif


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Dlog_ProgId_progId(P2CONST(uint8, AUTOMATIC, RTE_DLOG_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Dlog_ProgId_progId(P2CONST(Dlog_ProgIdArrayType, AUTOMATIC, RTE_DLOG_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
FUNC(Dlog_LifeCycleRequestType, RTE_CODE) Rte_Mode_Dlog_LifeCycle_Mode(P2VAR(Dlog_LifeCycleRequestType, AUTOMATIC, RTE_DLOG_APPL_VAR) previousMode, P2VAR(Dlog_LifeCycleRequestType, AUTOMATIC, RTE_DLOG_APPL_VAR) nextMode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Dlog_LifeCycle_Mode(Dlog_LifeCycleRequestType nextMode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_SwitchAck_Dlog_LifeCycle_Mode(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

/* PRQA S 3453 L1 */ /* MD_MSR_19.7 */
#  define Rte_IRead_Dlog_ModeSwitchRequestLifeCycle_LifeCycleRequest_requestMode() \
  (Rte_BswM_Provide_MSRP_Dlog_requestMode)
/* PRQA L:L1 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_ProgId_progId Rte_Write_Dlog_ProgId_progId


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Mode_LifeCycle_Mode Rte_Mode_Dlog_LifeCycle_Mode


/**********************************************************************************************************************
 * Rte_Switch_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Switch_LifeCycle_Mode Rte_Switch_Dlog_LifeCycle_Mode


/**********************************************************************************************************************
 * Rte_Feedback_<p>_<m> (mode switch acknowledge)
 *********************************************************************************************************************/
#  define Rte_SwitchAck_LifeCycle_Mode Rte_SwitchAck_Dlog_LifeCycle_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_CODING_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODING_APPL_CODE) Coding_DlogGetCafIds(P2VAR(uint8, AUTOMATIC, RTE_CODING_APPL_VAR) cafIds, P2VAR(uint16, AUTOMATIC, RTE_CODING_APPL_VAR) numberOfCafIds); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_CODING_APPL_CODE) Coding_DlogGetCafIds(P2VAR(Coding_CafIdArrayType, AUTOMATIC, RTE_CODING_APPL_VAR) cafIds, P2VAR(uint16, AUTOMATIC, RTE_CODING_APPL_VAR) numberOfCafIds); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_CODING_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_Coding_Svk_GetCafIds Coding_DlogGetCafIds
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_SetBlockProtection(NvM_BlockIdType parg0, boolean ProtectionEnabled); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_NvMAdmin_DlogProgData_SetBlockProtection(arg1) (NvM_SetBlockProtection((NvM_BlockIdType)24, arg1)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_WriteBlock(NvM_BlockIdType parg0, dtRef_const_VOID SrcPtr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_NvMService_DlogProgData_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)24, arg1)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_NVMPROXY_APPL_CODE) NvMProxy_ReadBlock(NvM_BlockIdType parg0, dtRef_VOID DstPtr_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_NvMService_DlogSvkEntry_ReadBlock(arg1) (NvMProxy_ReadBlock((NvM_BlockIdType)12, arg1)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_NVMPROXY_APPL_CODE) NvM_SetDataIndex(NvM_BlockIdType parg0, uint8 DataIndex_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_NvMService_DlogSvkEntry_SetDataIndex(arg1) (NvM_SetDataIndex((NvM_BlockIdType)12, arg1)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_NVMPROXY_APPL_CODE) NvMProxy_WriteBlock(NvM_BlockIdType parg0, dtRef_const_VOID SrcPtr_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_NvMService_DlogSvkEntry_WriteBlock(arg1) (NvMProxy_WriteBlock((NvM_BlockIdType)12, arg1)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_GetErrorStatus(NvM_BlockIdType parg0, P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_NVM_APPL_VAR) ErrorStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_NvMService_DlogSvkHistory_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)23, arg1)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_NvMService_DlogSvkHistory_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)23, arg1)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define Dlog_START_SEC_CODE
# include "Dlog_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_CondCheckSvkCurrent Dlog_ConditionCheckSvkCurrent
#  define RTE_RUNNABLE_CondCheckSvkPlant Dlog_ConditionCheckSvkPlant
#  define RTE_RUNNABLE_CondCheckSvkSysSupplier Dlog_ConditionCheckSvkSysSupplier
#  define RTE_RUNNABLE_CondCheckVin Dlog_ConditionCheckVin
#  define RTE_RUNNABLE_DataLengthSvkCurrent Dlog_ReadDataLengthSvkCurrent
#  define RTE_RUNNABLE_Dlog_GetEcuId Dlog_GetEcuId
#  define RTE_RUNNABLE_Dlog_GetVin Dlog_GetVin
#  define RTE_RUNNABLE_Dlog_ModeSwitchAckLifeCycle Dlog_ModeSwitchAckLifeCycle
#  define RTE_RUNNABLE_Dlog_ModeSwitchRequestLifeCycle Dlog_ModeSwitchRequestLifeCycle
#  define RTE_RUNNABLE_Dlog_NotifyJobFinishedProgData Dlog_NotifyJobFinishedProgData
#  define RTE_RUNNABLE_Dlog_NotifyJobFinishedSvkEntry Dlog_NotifyJobFinishedSvkEntry
#  define RTE_RUNNABLE_Dlog_ReadDataByIdentifierEcuUid Dlog_ReadDataByIdentifierEcuUid
#  define RTE_RUNNABLE_Dlog_ReadDataByIdentifierHWModificationIndex Dlog_ReadDataByIdentifierHWModificationIndex
#  define RTE_RUNNABLE_InitBlockProgData Dlog_InitProgData
#  define RTE_RUNNABLE_ReadEcuSerialNumber Dlog_ReadDataByIdentifierEcuSerialNumber
#  define RTE_RUNNABLE_ReadFlashTimingParameter Dlog_ReadDataByIdentifierFlashTimingParameter
#  define RTE_RUNNABLE_ReadManufacturingDate Dlog_ReadDataByIdentifierManufacturingDate
#  define RTE_RUNNABLE_ReadSvkCurrent Dlog_ReadDataByIdentifierSvkCurrent
#  define RTE_RUNNABLE_ReadSvkPlant Dlog_ReadDataByIdentifierSvkPlant
#  define RTE_RUNNABLE_ReadSvkSysSupplier Dlog_ReadDataByIdentifierSvkSysSupplier
#  define RTE_RUNNABLE_ReadVin Dlog_ReadDataByIdentifierVin
#  define RTE_RUNNABLE_StartReadReadDevInfoField Dlog_RoutineControlStartReadDevelopmentInfoField
#  define RTE_RUNNABLE_SweGetNumSig Dlog_SweGetNumSig
#  define RTE_RUNNABLE_SweGetNumSwe Dlog_SweGetNumSwe
#  define RTE_RUNNABLE_SweGetSigLength Dlog_SweGetSigLength
#  define RTE_RUNNABLE_SweGetSigStart Dlog_SweGetSigStart
#  define RTE_RUNNABLE_SweGetSignature Dlog_SweGetSignatureRte
# endif

FUNC(Std_ReturnType, Dlog_CODE) Dlog_ConditionCheckSvkCurrent(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DLOG_APPL_VAR) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Dlog_CODE) Dlog_ConditionCheckSvkPlant(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DLOG_APPL_VAR) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Dlog_CODE) Dlog_ConditionCheckSvkSysSupplier(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DLOG_APPL_VAR) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Dlog_CODE) Dlog_ConditionCheckVin(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DLOG_APPL_VAR) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Dlog_CODE) Dlog_ReadDataLengthSvkCurrent(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_DLOG_APPL_VAR) DataLength); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Dlog_CODE) Dlog_GetEcuId(P2VAR(uint8, AUTOMATIC, RTE_DLOG_APPL_VAR) ecuId); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, Dlog_CODE) Dlog_GetVin(P2VAR(uint8, AUTOMATIC, RTE_DLOG_APPL_VAR) Vin); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, Dlog_CODE) Dlog_GetVin(P2VAR(uint8, AUTOMATIC, RTE_DLOG_APPL_VAR) Vin); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
FUNC(void, Dlog_CODE) Dlog_ModeSwitchAckLifeCycle(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, Dlog_CODE) Dlog_ModeSwitchRequestLifeCycle(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, Dlog_CODE) Dlog_NotifyJobFinishedProgData(uint8 ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Dlog_CODE) Dlog_NotifyJobFinishedSvkEntry(uint8 ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, Dlog_CODE) Dlog_ReadDataByIdentifierEcuUid(P2VAR(uint8, AUTOMATIC, RTE_DLOG_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, Dlog_CODE) Dlog_ReadDataByIdentifierEcuUid(P2VAR(Dlog_EcuUidArrayType, AUTOMATIC, RTE_DLOG_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, Dlog_CODE) Dlog_ReadDataByIdentifierHWModificationIndex(P2VAR(uint8, AUTOMATIC, RTE_DLOG_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, Dlog_CODE) Dlog_ReadDataByIdentifierHWModificationIndex(P2VAR(Dlog_HWModificationIndexArrayType, AUTOMATIC, RTE_DLOG_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
FUNC(Std_ReturnType, Dlog_CODE) Dlog_InitProgData(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, Dlog_CODE) Dlog_ReadDataByIdentifierEcuSerialNumber(P2VAR(uint8, AUTOMATIC, RTE_DLOG_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, Dlog_CODE) Dlog_ReadDataByIdentifierEcuSerialNumber(P2VAR(SerialNumberArrayType, AUTOMATIC, RTE_DLOG_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, Dlog_CODE) Dlog_ReadDataByIdentifierFlashTimingParameter(P2VAR(uint8, AUTOMATIC, RTE_DLOG_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, Dlog_CODE) Dlog_ReadDataByIdentifierFlashTimingParameter(P2VAR(TimingParametersArrayType, AUTOMATIC, RTE_DLOG_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, Dlog_CODE) Dlog_ReadDataByIdentifierManufacturingDate(P2VAR(uint8, AUTOMATIC, RTE_DLOG_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, Dlog_CODE) Dlog_ReadDataByIdentifierManufacturingDate(P2VAR(ManufacturingDataArrayType, AUTOMATIC, RTE_DLOG_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, Dlog_CODE) Dlog_ReadDataByIdentifierSvkCurrent(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DLOG_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, Dlog_CODE) Dlog_ReadDataByIdentifierSvkCurrent(Dcm_OpStatusType OpStatus, P2VAR(SvkDataArrayType, AUTOMATIC, RTE_DLOG_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, Dlog_CODE) Dlog_ReadDataByIdentifierSvkPlant(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DLOG_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, Dlog_CODE) Dlog_ReadDataByIdentifierSvkPlant(Dcm_OpStatusType OpStatus, P2VAR(SvkHistoryDataArrayType, AUTOMATIC, RTE_DLOG_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, Dlog_CODE) Dlog_ReadDataByIdentifierSvkSysSupplier(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DLOG_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, Dlog_CODE) Dlog_ReadDataByIdentifierSvkSysSupplier(Dcm_OpStatusType OpStatus, P2VAR(SvkHistoryDataArrayType, AUTOMATIC, RTE_DLOG_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, Dlog_CODE) Dlog_ReadDataByIdentifierVin(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DLOG_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, Dlog_CODE) Dlog_ReadDataByIdentifierVin(Dcm_OpStatusType OpStatus, P2VAR(Dlog_VinArrayType, AUTOMATIC, RTE_DLOG_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, Dlog_CODE) Dlog_RoutineControlStartReadDevelopmentInfoField(P2CONST(uint8, AUTOMATIC, RTE_DLOG_APPL_DATA) DataIn, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DLOG_APPL_VAR) DataOut, P2VAR(uint16, AUTOMATIC, RTE_DLOG_APPL_VAR) CurrentDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DLOG_APPL_VAR) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, Dlog_CODE) Dlog_RoutineControlStartReadDevelopmentInfoField(P2CONST(RSInputArrayType, AUTOMATIC, RTE_DLOG_APPL_DATA) DataIn, Dcm_OpStatusType OpStatus, P2VAR(DevInfoArrayType, AUTOMATIC, RTE_DLOG_APPL_VAR) DataOut, P2VAR(uint16, AUTOMATIC, RTE_DLOG_APPL_VAR) CurrentDataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DLOG_APPL_VAR) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
FUNC(Std_ReturnType, Dlog_CODE) Dlog_SweGetNumSig(uint8 sweId, P2VAR(uint8, AUTOMATIC, RTE_DLOG_APPL_VAR) numSig); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Dlog_CODE) Dlog_SweGetNumSwe(P2VAR(uint8, AUTOMATIC, RTE_DLOG_APPL_VAR) numSwe); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Dlog_CODE) Dlog_SweGetSigLength(uint8 sweId, uint8 blkNum, P2VAR(uint32, AUTOMATIC, RTE_DLOG_APPL_VAR) length); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Dlog_CODE) Dlog_SweGetSigStart(uint8 sweId, uint8 blkNum, P2VAR(uint32, AUTOMATIC, RTE_DLOG_APPL_VAR) address); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, Dlog_CODE) Dlog_SweGetSignatureRte(uint8 sweId, P2VAR(uint8, AUTOMATIC, RTE_DLOG_APPL_VAR) signature); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, Dlog_CODE) Dlog_SweGetSignatureRte(uint8 sweId, P2VAR(Dlog_SignatureArrayType, AUTOMATIC, RTE_DLOG_APPL_VAR) signature); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif

# define Dlog_STOP_SEC_CODE
# include "Dlog_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_Coding_SVKInterface_E_NOT_OK (1U)

#  define RTE_E_DataServices_EcuSerialNumber_E_NOT_OK (1U)

#  define RTE_E_DataServices_EcuUid_E_NOT_OK (1U)

#  define RTE_E_DataServices_FlashTimingParameter_E_NOT_OK (1U)

#  define RTE_E_DataServices_HWModificationIndex_E_NOT_OK (1U)

#  define RTE_E_DataServices_ManufacturingDate_E_NOT_OK (1U)

#  define RTE_E_DataServices_Svk_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Svk_E_NOT_OK (1U)

#  define RTE_E_DataServices_SvkHistory_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_SvkHistory_E_NOT_OK (1U)

#  define RTE_E_DataServices_Vin_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Vin_E_NOT_OK (1U)

#  define RTE_E_Dlog_NvMAdmin_E_NOT_OK (1U)

#  define RTE_E_Dlog_NvMNotifyInitBlock_E_OK (0U)

#  define RTE_E_Dlog_NvMNotifyJobFinished_E_OK (0U)

#  define RTE_E_EcuInfo_E_NOT_OK (1U)

#  define RTE_E_NvMService_E_NOT_OK (1U)

#  define RTE_E_NvMServiceSvkEntry_E_NOT_OK (1U)

#  define RTE_E_RoutineService_DevInfo_DCM_E_PENDING (10U)

#  define RTE_E_RoutineService_DevInfo_E_NOT_OK (1U)

#  define RTE_E_SweSignatureAccess_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_DLOG_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
