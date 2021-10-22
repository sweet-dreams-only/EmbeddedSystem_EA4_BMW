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
 *          File:  Rte_CDD_HwTq5Meas.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <CDD_HwTq5Meas>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CDD_HWTQ5MEAS_H
# define _RTE_CDD_HWTQ5MEAS_H

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

# include "Rte_CDD_HwTq5Meas_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_INIT) Rte_CDD_HwTq5Meas_HwTq5_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(SigQlfr1, RTE_VAR_INIT) Rte_CDD_HwTq5Meas_HwTq5Qlfr_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_INIT) Rte_CDD_HwTq5Meas_HwTq5RollgCntr_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(sint8, RTE_VAR_INIT) Rte_PolarityCfg_HwTq5Polarity_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_HwTq5RawAdc_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_CDD_Bmw5441McuCfg_HwTq5RawAdcAdcFaild_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_HwTq5_Val (0.0F)
#  define Rte_InitValue_HwTq5Polarity_Val (1)
#  define Rte_InitValue_HwTq5Qlfr_Val (0U)
#  define Rte_InitValue_HwTq5RawAdc_Val (0.0F)
#  define Rte_InitValue_HwTq5RawAdcAdcFaild_Logl (FALSE)
#  define Rte_InitValue_HwTq5RawFastAdcAdcFaild_Logl (FALSE)
#  define Rte_InitValue_HwTq5RollgCntr_Val (0U)
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_HwTq5Meas_HwTq5RawFastAdcBuf_Ary1D(P2VAR(float32, AUTOMATIC, RTE_CDD_HWTQ5MEAS_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_HwTq5Meas_HwTq5RawFastAdcBuf_Ary1D(P2VAR(Ary1D_f32_8, AUTOMATIC, RTE_CDD_HWTQ5MEAS_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_HwTq5Polarity_Val Rte_Read_CDD_HwTq5Meas_HwTq5Polarity_Val
#  define Rte_Read_CDD_HwTq5Meas_HwTq5Polarity_Val(data) (*(data) = Rte_PolarityCfg_HwTq5Polarity_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_HwTq5RawAdc_Val Rte_Read_CDD_HwTq5Meas_HwTq5RawAdc_Val
#  define Rte_Read_CDD_HwTq5Meas_HwTq5RawAdc_Val(data) (*(data) = Rte_CDD_MotCtrlMgr_HwTq5RawAdc_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_HwTq5RawAdcAdcFaild_Logl Rte_Read_CDD_HwTq5Meas_HwTq5RawAdcAdcFaild_Logl
#  define Rte_Read_CDD_HwTq5Meas_HwTq5RawAdcAdcFaild_Logl(data) (*(data) = Rte_CDD_Bmw5441McuCfg_HwTq5RawAdcAdcFaild_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_HwTq5RawFastAdcAdcFaild_Logl Rte_Read_CDD_HwTq5Meas_HwTq5RawFastAdcAdcFaild_Logl
#  define Rte_Read_CDD_HwTq5Meas_HwTq5RawFastAdcAdcFaild_Logl(data) (*(data) = Rte_CDD_Bmw5441McuCfg_HwTq5RawAdcAdcFaild_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_HwTq5RawFastAdcBuf_Ary1D Rte_Read_CDD_HwTq5Meas_HwTq5RawFastAdcBuf_Ary1D


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_HwTq5_Val Rte_Write_CDD_HwTq5Meas_HwTq5_Val
#  define Rte_Write_CDD_HwTq5Meas_HwTq5_Val(data) (Rte_CDD_HwTq5Meas_HwTq5_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_HwTq5Qlfr_Val Rte_Write_CDD_HwTq5Meas_HwTq5Qlfr_Val
#  define Rte_Write_CDD_HwTq5Meas_HwTq5Qlfr_Val(data) (Rte_CDD_HwTq5Meas_HwTq5Qlfr_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_HwTq5RollgCntr_Val Rte_Write_CDD_HwTq5Meas_HwTq5RollgCntr_Val
#  define Rte_Write_CDD_HwTq5Meas_HwTq5RollgCntr_Val(data) (Rte_CDD_HwTq5Meas_HwTq5RollgCntr_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_DIAGCMGRPROXYAPPL10_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_DIAGCMGRPROXYAPPL10_APPL_CODE) GetNtcQlfrSts10_Oper(NtcNr1 NtcNr_Arg, P2VAR(SigQlfr1, AUTOMATIC, RTE_DIAGCMGRPROXYAPPL10_APPL_VAR) NtcQlfr_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DIAGCMGRPROXYAPPL10_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_GetNtcQlfrSts_Oper GetNtcQlfrSts10_Oper
#  define RTE_START_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_NVMPROXY_APPL_CODE) NvMProxy_GetErrorStatus(NvM_BlockIdType parg0, P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_NVMPROXY_APPL_VAR) ErrorStatus_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_HwTq5Offs_GetErrorStatus(arg1) (NvMProxy_GetErrorStatus((NvM_BlockIdType)34, arg1)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_NVMPROXY_APPL_CODE) NvMProxy_SetRamBlockStatus(NvM_BlockIdType parg0, boolean RamBlockStatus_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_HwTq5Offs_SetRamBlockStatus(arg1) (NvMProxy_SetRamBlockStatus((NvM_BlockIdType)34, arg1)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_HwTq5Sca_GetErrorStatus(arg1) (NvMProxy_GetErrorStatus((NvM_BlockIdType)32, arg1)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_HwTq5Sca_SetRamBlockStatus(arg1) (NvMProxy_SetRamBlockStatus((NvM_BlockIdType)32, arg1)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_DIAGCMGRPROXYAPPL10_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_DIAGCMGRPROXYAPPL10_APPL_CODE) SetNtcSts10_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DIAGCMGRPROXYAPPL10_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_SetNtcSts_Oper SetNtcSts10_Oper


/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

#  define Rte_Prm_HwTq5MeasHwTqRngHiLim_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->HwTq5MeasHwTqRngHiLim_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_HwTq5MeasHwTqRngLoLim_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->HwTq5MeasHwTqRngLoLim_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_HwTq5MeasHwTq5PrtclFltFailStep_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->HwTq5MeasHwTq5PrtclFltFailStep_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_HwTq5MeasHwTq5PrtclFltPassStep_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->HwTq5MeasHwTq5PrtclFltPassStep_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_HwTq5MeasMovgAvrgFilEna_Logl() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->HwTq5MeasMovgAvrgFilEna_Logl) /* PRQA S 3453 */ /* MD_MSR_19.7 */

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_HwTq5Meas_HwTq5PrevHwTq5; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_HwTq5Meas_HwTq5PrevRollgCntr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_HwTq5Meas_HwTq5RawFastAdcIdxCntr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(HwTqOffsRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_HwTq5Meas_HwTq5Offs; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(AnHwTqScaFacRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_HwTq5Meas_HwTq5Sca; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  endif

#  define Rte_Pim_HwTq5PrevHwTq5() \
  (&Rte_CDD_HwTq5Meas_HwTq5PrevHwTq5) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_HwTq5PrevRollgCntr() \
  (&Rte_CDD_HwTq5Meas_HwTq5PrevRollgCntr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_HwTq5RawFastAdcIdxCntr() \
  (&Rte_CDD_HwTq5Meas_HwTq5RawFastAdcIdxCntr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_HwTq5Offs() \
  (&Rte_CDD_HwTq5Meas_HwTq5Offs) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_HwTq5Sca() \
  (&Rte_CDD_HwTq5Meas_HwTq5Sca) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define CDD_HwTq5Meas_START_SEC_CODE
# include "CDD_HwTq5Meas_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_HwTq5AutTrim_Oper HwTq5AutTrim_Oper
#  define RTE_RUNNABLE_HwTq5ClrSnsrSca_Oper HwTq5ClrSnsrSca_Oper
#  define RTE_RUNNABLE_HwTq5ClrTrim_Oper HwTq5ClrTrim_Oper
#  define RTE_RUNNABLE_HwTq5MeasInit1 HwTq5MeasInit1
#  define RTE_RUNNABLE_HwTq5MeasPer2 HwTq5MeasPer2
#  define RTE_RUNNABLE_HwTq5MeasPer3 HwTq5MeasPer3
#  define RTE_RUNNABLE_HwTq5MeasPer4 HwTq5MeasPer4
#  define RTE_RUNNABLE_HwTq5ReadSnsrSca_Oper HwTq5ReadSnsrSca_Oper
#  define RTE_RUNNABLE_HwTq5ReadTrim_Oper HwTq5ReadTrim_Oper
#  define RTE_RUNNABLE_HwTq5SnsrScaPrfmdSts_Oper HwTq5SnsrScaPrfmdSts_Oper
#  define RTE_RUNNABLE_HwTq5TrimPrfmdSts_Oper HwTq5TrimPrfmdSts_Oper
#  define RTE_RUNNABLE_HwTq5WrSnsrSca_Oper HwTq5WrSnsrSca_Oper
#  define RTE_RUNNABLE_HwTq5WrTrim_Oper HwTq5WrTrim_Oper
# endif

FUNC(void, CDD_HwTq5Meas_CODE) HwTq5AutTrim_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, CDD_HwTq5Meas_CODE) HwTq5ClrSnsrSca_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, CDD_HwTq5Meas_CODE) HwTq5ClrTrim_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, CDD_HwTq5Meas_CODE) HwTq5MeasInit1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CDD_HwTq5Meas_CODE) HwTq5MeasPer2(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CDD_HwTq5Meas_CODE) HwTq5MeasPer3(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CDD_HwTq5Meas_CODE) HwTq5MeasPer4(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CDD_HwTq5Meas_CODE) HwTq5ReadSnsrSca_Oper(P2VAR(float32, AUTOMATIC, RTE_CDD_HWTQ5MEAS_APPL_VAR) HwTqReadScaData_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, CDD_HwTq5Meas_CODE) HwTq5ReadTrim_Oper(P2VAR(float32, AUTOMATIC, RTE_CDD_HWTQ5MEAS_APPL_VAR) HwTqReadTrimData_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, CDD_HwTq5Meas_CODE) HwTq5SnsrScaPrfmdSts_Oper(P2VAR(boolean, AUTOMATIC, RTE_CDD_HWTQ5MEAS_APPL_VAR) HwTqScaPrfmdStsData_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, CDD_HwTq5Meas_CODE) HwTq5TrimPrfmdSts_Oper(P2VAR(boolean, AUTOMATIC, RTE_CDD_HWTQ5MEAS_APPL_VAR) HwTqOffsTrimPrfmdStsData_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, CDD_HwTq5Meas_CODE) HwTq5WrSnsrSca_Oper(float32 HwTqScaVal_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, CDD_HwTq5Meas_CODE) HwTq5WrTrim_Oper(float32 HwTqWrOffsTrimData_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define CDD_HwTq5Meas_STOP_SEC_CODE
# include "CDD_HwTq5Meas_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_GetNtcQlfrSts_PortIf1_E_NOT_OK (1U)

#  define RTE_E_NvMService_AC3_SRBS_E_NOT_OK (1U)

#  define RTE_E_SetNtcSts_PortIf1_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CDD_HWTQ5MEAS_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
