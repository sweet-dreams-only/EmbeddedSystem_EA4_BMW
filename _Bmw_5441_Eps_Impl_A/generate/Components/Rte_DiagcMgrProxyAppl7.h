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
 *          File:  Rte_DiagcMgrProxyAppl7.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <DiagcMgrProxyAppl7>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_DIAGCMGRPROXYAPPL7_H
# define _RTE_DIAGCMGRPROXYAPPL7_H

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

# include "Rte_DiagcMgrProxyAppl7_Type.h"
# include "Rte_DataHandleType.h"

# include "Rte_Hook.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_INIT) Rte_DiagcMgr_ClrDiagcFlgProxy_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_ClrDiagcFlgProxy_Val (0U)
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/


# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_ClrDiagcFlgProxy_Val Rte_Read_DiagcMgrProxyAppl7_ClrDiagcFlgProxy_Val
#  define Rte_Read_DiagcMgrProxyAppl7_ClrDiagcFlgProxy_Val(data) (*(data) = Rte_DiagcMgr_ClrDiagcFlgProxy_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_DIAGCMGR_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_DIAGCMGR_APPL_CODE) DiagcMgrIninCore_Oper(uint8 ApplIdx_Arg, uint8 NtcInfoArySize_Arg, P2VAR(NtcInfoRec4, AUTOMATIC, RTE_DIAGCMGR_APPL_VAR) NtcInfoAry_Arg, P2VAR(DiagcDataRec2, AUTOMATIC, RTE_DIAGCMGR_APPL_VAR) DiagcData_Arg, P2VAR(DiagcDataRec2, AUTOMATIC, RTE_DIAGCMGR_APPL_VAR) ProxySetNtcData_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_DIAGCMGR_APPL_CODE) DiagcMgrIninCore_Oper(uint8 ApplIdx_Arg, uint8 NtcInfoArySize_Arg, P2VAR(Ary1D_NtcInfoRec4_DiagcMgr, AUTOMATIC, RTE_DIAGCMGR_APPL_VAR) NtcInfoAry_Arg, P2VAR(DiagcDataRec2, AUTOMATIC, RTE_DIAGCMGR_APPL_VAR) DiagcData_Arg, P2VAR(DiagcDataRec2, AUTOMATIC, RTE_DIAGCMGR_APPL_VAR) ProxySetNtcData_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_DIAGCMGR_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_DiagcMgrIninCore_Oper(arg1, arg2, arg3, arg4, arg5) (DiagcMgrIninCore_Oper(arg1, arg2, arg3, arg4, arg5), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_DIAGCMGR_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_DIAGCMGR_APPL_CODE) GetNtcActvCore_Oper(NtcNr1 NtcNr_Arg, P2VAR(boolean, AUTOMATIC, RTE_DIAGCMGR_APPL_VAR) NtcActv_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DIAGCMGR_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_GetNtcActvCore_Oper(arg1, arg2) (GetNtcActvCore_Oper(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_DIAGCMGR_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_DIAGCMGR_APPL_CODE) GetNtcQlfrStsCore_Oper(NtcNr1 NtcNr_Arg, P2VAR(SigQlfr1, AUTOMATIC, RTE_DIAGCMGR_APPL_VAR) NtcQlfr_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DIAGCMGR_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_GetNtcQlfrStsCore_Oper(arg1, arg2) (GetNtcQlfrStsCore_Oper(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_DIAGCMGR_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_DIAGCMGR_APPL_CODE) GetNtcStsCore_Oper(NtcNr1 NtcNr_Arg, P2VAR(uint8, AUTOMATIC, RTE_DIAGCMGR_APPL_VAR) NtcInfoSts_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DIAGCMGR_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_GetNtcStsCore_Oper(arg1, arg2) (GetNtcStsCore_Oper(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_DIAGCMGR_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_DIAGCMGR_APPL_CODE) SetNtcStsCore_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg, P2VAR(DiagcDataRec2, AUTOMATIC, RTE_DIAGCMGR_APPL_VAR) DiagcData_Arg, P2VAR(DiagcDataRec2, AUTOMATIC, RTE_DIAGCMGR_APPL_VAR) ProxySetNtcData_Arg, P2VAR(NtcInfoRec4, AUTOMATIC, RTE_DIAGCMGR_APPL_VAR) NtcInfo_Arg, P2VAR(sint16, AUTOMATIC, RTE_DIAGCMGR_APPL_VAR) NtcInfoDebCntr_Arg, uint32 SpclSnpshtData0_Arg, uint32 SpclSnpshtData1_Arg, uint32 SpclSnpshtData2_Arg, boolean SpclSnpshtDataPrsnt_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DIAGCMGR_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_SetNtcStsCore_Oper SetNtcStsCore_Oper


/**********************************************************************************************************************
 * Exclusive Areas
 *********************************************************************************************************************/

#  define Rte_Enter_DiagcMgrProxyAppl7() SuspendOSInterrupts()  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */

#  define Rte_Exit_DiagcMgrProxyAppl7() ResumeOSInterrupts()  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */


/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_DiagcMgrFltResp_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->DiagcMgrFltResp_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_DiagcMgrFltResp_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->DiagcMgrFltResp_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_Appl7_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_DiagcMgrProxyAppl7_PrevClrNtcFlg7; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(Ary1D_NtcInfoRec4_DiagcMgrProxyAppl7, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_DiagcMgrProxyAppl7_DiagcMgrNtcInfo7Ary; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(Ary1D_s16_DiagcMgrProxyAppl7, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_DiagcMgrProxyAppl7_DiagcMgrNtcInfo7DebCntrAry; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(DiagcDataRec2, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_DiagcMgrProxyAppl7_DiagcData7; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(DiagcDataRec2, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_DiagcMgrProxyAppl7_ProxySetNtcData7; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Appl7_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  endif

#  define Rte_Pim_PrevClrNtcFlg7() \
  (&Rte_DiagcMgrProxyAppl7_PrevClrNtcFlg7) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_DiagcMgrNtcInfo7Ary() (&((*RtePim_DiagcMgrNtcInfo7Ary())[0]))
#  else
#   define Rte_Pim_DiagcMgrNtcInfo7Ary() RtePim_DiagcMgrNtcInfo7Ary()
#  endif
#  define RtePim_DiagcMgrNtcInfo7Ary() \
  (&Rte_DiagcMgrProxyAppl7_DiagcMgrNtcInfo7Ary) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_DiagcMgrNtcInfo7DebCntrAry() (&((*RtePim_DiagcMgrNtcInfo7DebCntrAry())[0]))
#  else
#   define Rte_Pim_DiagcMgrNtcInfo7DebCntrAry() RtePim_DiagcMgrNtcInfo7DebCntrAry()
#  endif
#  define RtePim_DiagcMgrNtcInfo7DebCntrAry() \
  (&Rte_DiagcMgrProxyAppl7_DiagcMgrNtcInfo7DebCntrAry) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_DiagcData7() \
  (&Rte_DiagcMgrProxyAppl7_DiagcData7) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_ProxySetNtcData7() \
  (&Rte_DiagcMgrProxyAppl7_ProxySetNtcData7) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define DiagcMgrProxyAppl7_START_SEC_CODE
# include "DiagcMgrProxyAppl7_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_DiagcMgrProxyAppl7Init1 DiagcMgrProxyAppl7Init1
#  define RTE_RUNNABLE_DiagcMgrProxyAppl7Per1 DiagcMgrProxyAppl7Per1
#  define RTE_RUNNABLE_GetDiagcDataAppl7_Oper GetDiagcDataAppl7_Oper
#  define RTE_RUNNABLE_GetNtcActv7_Oper GetNtcActv7_Oper
#  define RTE_RUNNABLE_GetNtcDebCntrAppl7_Oper GetNtcDebCntrAppl7_Oper
#  define RTE_RUNNABLE_GetNtcInfoAppl7_Oper GetNtcInfoAppl7_Oper
#  define RTE_RUNNABLE_GetNtcQlfrSts7_Oper GetNtcQlfrSts7_Oper
#  define RTE_RUNNABLE_GetNtcSts7_Oper GetNtcSts7_Oper
#  define RTE_RUNNABLE_SetNtcSts7_Oper SetNtcSts7_Oper
#  define RTE_RUNNABLE_SetNtcStsAndSnpshtData7_Oper SetNtcStsAndSnpshtData7_Oper
# endif

FUNC(void, DiagcMgrProxyAppl7_CODE) DiagcMgrProxyAppl7Init1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, DiagcMgrProxyAppl7_CODE) DiagcMgrProxyAppl7Per1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, DiagcMgrProxyAppl7_CODE) GetDiagcDataAppl7_Oper(P2VAR(DiagcDataRec2, AUTOMATIC, RTE_DIAGCMGRPROXYAPPL7_APPL_VAR) DiagcData_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, DiagcMgrProxyAppl7_CODE) GetNtcActv7_Oper(NtcNr1 NtcNr_Arg, P2VAR(boolean, AUTOMATIC, RTE_DIAGCMGRPROXYAPPL7_APPL_VAR) NtcActv_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, DiagcMgrProxyAppl7_CODE) GetNtcDebCntrAppl7_Oper(uint8 DebCntrIdx_Arg, P2VAR(sint16, AUTOMATIC, RTE_DIAGCMGRPROXYAPPL7_APPL_VAR) DebCntr_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, DiagcMgrProxyAppl7_CODE) GetNtcInfoAppl7_Oper(uint8 NtcInfoIdx_Arg, P2VAR(NtcInfoRec4, AUTOMATIC, RTE_DIAGCMGRPROXYAPPL7_APPL_VAR) NtcInfo_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, DiagcMgrProxyAppl7_CODE) GetNtcQlfrSts7_Oper(NtcNr1 NtcNr_Arg, P2VAR(SigQlfr1, AUTOMATIC, RTE_DIAGCMGRPROXYAPPL7_APPL_VAR) NtcQlfr_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, DiagcMgrProxyAppl7_CODE) GetNtcSts7_Oper(NtcNr1 NtcNr_Arg, P2VAR(uint8, AUTOMATIC, RTE_DIAGCMGRPROXYAPPL7_APPL_VAR) NtcInfoSts_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, DiagcMgrProxyAppl7_CODE) SetNtcSts7_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, DiagcMgrProxyAppl7_CODE) SetNtcStsAndSnpshtData7_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg, uint32 SpclSnpshtData0_Arg, uint32 SpclSnpshtData1_Arg, uint32 SpclSnpshtData2_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define DiagcMgrProxyAppl7_STOP_SEC_CODE
# include "DiagcMgrProxyAppl7_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_GetNtcActv_PortIf1_E_NOT_OK (1U)

#  define RTE_E_GetNtcQlfrSts_PortIf1_E_NOT_OK (1U)

#  define RTE_E_GetNtcSts_PortIf1_E_NOT_OK (1U)

#  define RTE_E_SetNtcStsAndSnpshtData_PortIf1_E_NOT_OK (1U)

#  define RTE_E_SetNtcStsCore_PortIf2_E_NOT_OK (1U)

#  define RTE_E_SetNtcSts_PortIf1_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_DIAGCMGRPROXYAPPL7_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
