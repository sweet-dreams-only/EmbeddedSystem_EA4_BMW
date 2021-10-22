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
 *          File:  Rte_DiagcMgrProxyAppl9.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <DiagcMgrProxyAppl9>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_DIAGCMGRPROXYAPPL9_H
# define _RTE_DIAGCMGRPROXYAPPL9_H

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

# include "Rte_DiagcMgrProxyAppl9_Type.h"
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
#  define Rte_Read_ClrDiagcFlgProxy_Val Rte_Read_DiagcMgrProxyAppl9_ClrDiagcFlgProxy_Val
#  define Rte_Read_DiagcMgrProxyAppl9_ClrDiagcFlgProxy_Val(data) (*(data) = Rte_DiagcMgr_ClrDiagcFlgProxy_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


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

#  define Rte_Enter_DiagcMgrProxyAppl9() SuspendOSInterrupts()  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */

#  define Rte_Exit_DiagcMgrProxyAppl9() ResumeOSInterrupts()  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */


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
#   define RTE_START_SEC_VAR_DEFAULT_RTE_Appl9_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl9_PIM_GROUP) Rte_DiagcMgrProxyAppl9_PrevClrNtcFlg9; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(Ary1D_NtcInfoRec4_DiagcMgrProxyAppl9, RTE_VAR_DEFAULT_RTE_Appl9_PIM_GROUP) Rte_DiagcMgrProxyAppl9_DiagcMgrNtcInfo9Ary; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(Ary1D_s16_DiagcMgrProxyAppl9, RTE_VAR_DEFAULT_RTE_Appl9_PIM_GROUP) Rte_DiagcMgrProxyAppl9_DiagcMgrNtcInfo9DebCntrAry; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(DiagcDataRec2, RTE_VAR_DEFAULT_RTE_Appl9_PIM_GROUP) Rte_DiagcMgrProxyAppl9_DiagcData9; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(DiagcDataRec2, RTE_VAR_DEFAULT_RTE_Appl9_PIM_GROUP) Rte_DiagcMgrProxyAppl9_ProxySetNtcData9; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Appl9_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  endif

#  define Rte_Pim_PrevClrNtcFlg9() \
  (&Rte_DiagcMgrProxyAppl9_PrevClrNtcFlg9) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_DiagcMgrNtcInfo9Ary() (&((*RtePim_DiagcMgrNtcInfo9Ary())[0]))
#  else
#   define Rte_Pim_DiagcMgrNtcInfo9Ary() RtePim_DiagcMgrNtcInfo9Ary()
#  endif
#  define RtePim_DiagcMgrNtcInfo9Ary() \
  (&Rte_DiagcMgrProxyAppl9_DiagcMgrNtcInfo9Ary) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_DiagcMgrNtcInfo9DebCntrAry() (&((*RtePim_DiagcMgrNtcInfo9DebCntrAry())[0]))
#  else
#   define Rte_Pim_DiagcMgrNtcInfo9DebCntrAry() RtePim_DiagcMgrNtcInfo9DebCntrAry()
#  endif
#  define RtePim_DiagcMgrNtcInfo9DebCntrAry() \
  (&Rte_DiagcMgrProxyAppl9_DiagcMgrNtcInfo9DebCntrAry) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_DiagcData9() \
  (&Rte_DiagcMgrProxyAppl9_DiagcData9) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_ProxySetNtcData9() \
  (&Rte_DiagcMgrProxyAppl9_ProxySetNtcData9) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define DiagcMgrProxyAppl9_START_SEC_CODE
# include "DiagcMgrProxyAppl9_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_DiagcMgrProxyAppl9Init1 DiagcMgrProxyAppl9Init1
#  define RTE_RUNNABLE_DiagcMgrProxyAppl9Per1 DiagcMgrProxyAppl9Per1
#  define RTE_RUNNABLE_GetDiagcDataAppl9_Oper GetDiagcDataAppl9_Oper
#  define RTE_RUNNABLE_GetNtcActv9_Oper GetNtcActv9_Oper
#  define RTE_RUNNABLE_GetNtcDebCntrAppl9_Oper GetNtcDebCntrAppl9_Oper
#  define RTE_RUNNABLE_GetNtcInfoAppl9_Oper GetNtcInfoAppl9_Oper
#  define RTE_RUNNABLE_GetNtcQlfrSts9_Oper GetNtcQlfrSts9_Oper
#  define RTE_RUNNABLE_GetNtcSts9_Oper GetNtcSts9_Oper
#  define RTE_RUNNABLE_SetNtcSts9_Oper SetNtcSts9_Oper
#  define RTE_RUNNABLE_SetNtcStsAndSnpshtData9_Oper SetNtcStsAndSnpshtData9_Oper
# endif

FUNC(void, DiagcMgrProxyAppl9_CODE) DiagcMgrProxyAppl9Init1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, DiagcMgrProxyAppl9_CODE) DiagcMgrProxyAppl9Per1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, DiagcMgrProxyAppl9_CODE) GetDiagcDataAppl9_Oper(P2VAR(DiagcDataRec2, AUTOMATIC, RTE_DIAGCMGRPROXYAPPL9_APPL_VAR) DiagcData_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, DiagcMgrProxyAppl9_CODE) GetNtcActv9_Oper(NtcNr1 NtcNr_Arg, P2VAR(boolean, AUTOMATIC, RTE_DIAGCMGRPROXYAPPL9_APPL_VAR) NtcActv_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, DiagcMgrProxyAppl9_CODE) GetNtcDebCntrAppl9_Oper(uint8 DebCntrIdx_Arg, P2VAR(sint16, AUTOMATIC, RTE_DIAGCMGRPROXYAPPL9_APPL_VAR) DebCntr_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, DiagcMgrProxyAppl9_CODE) GetNtcInfoAppl9_Oper(uint8 NtcInfoIdx_Arg, P2VAR(NtcInfoRec4, AUTOMATIC, RTE_DIAGCMGRPROXYAPPL9_APPL_VAR) NtcInfo_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, DiagcMgrProxyAppl9_CODE) GetNtcQlfrSts9_Oper(NtcNr1 NtcNr_Arg, P2VAR(SigQlfr1, AUTOMATIC, RTE_DIAGCMGRPROXYAPPL9_APPL_VAR) NtcQlfr_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, DiagcMgrProxyAppl9_CODE) GetNtcSts9_Oper(NtcNr1 NtcNr_Arg, P2VAR(uint8, AUTOMATIC, RTE_DIAGCMGRPROXYAPPL9_APPL_VAR) NtcInfoSts_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, DiagcMgrProxyAppl9_CODE) SetNtcSts9_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, DiagcMgrProxyAppl9_CODE) SetNtcStsAndSnpshtData9_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg, uint32 SpclSnpshtData0_Arg, uint32 SpclSnpshtData1_Arg, uint32 SpclSnpshtData2_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define DiagcMgrProxyAppl9_STOP_SEC_CODE
# include "DiagcMgrProxyAppl9_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


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

#endif /* _RTE_DIAGCMGRPROXYAPPL9_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
