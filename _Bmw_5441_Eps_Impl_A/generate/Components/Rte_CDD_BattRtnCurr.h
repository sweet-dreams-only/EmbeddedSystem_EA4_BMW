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
 *          File:  Rte_CDD_BattRtnCurr.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <CDD_BattRtnCurr>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CDD_BATTRTNCURR_H
# define _RTE_CDD_BATTRTNCURR_H

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

# include "Rte_CDD_BattRtnCurr_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_Appl8_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_INIT) Rte_CDD_BattRtnCurr_BattRtnCurrAmpr_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(SigQlfr1, RTE_VAR_INIT) Rte_CDD_BattRtnCurr_BattRtnCurrStsQlfr_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_ElecPwrCns_SplyCurrEstim_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_Appl8_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_BattRtnCurrAdc_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_CDD_Bmw5441McuCfg_BattRtnCurrAdcFaild_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(SysSt1, RTE_VAR_INIT) Rte_SysStMod_SysSt_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_BattRtnCurrAdc_Val (0.0F)
#  define Rte_InitValue_BattRtnCurrAdcFaild_Logl (FALSE)
#  define Rte_InitValue_BattRtnCurrAmpr_Val (0.0F)
#  define Rte_InitValue_BattRtnCurrStsQlfr_Val (0U)
#  define Rte_InitValue_SplyCurrEstim_Val (0.0F)
#  define Rte_InitValue_SysSt_Val (3U)
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_BattRtnCurrAdc_Val Rte_Read_CDD_BattRtnCurr_BattRtnCurrAdc_Val
#  define Rte_Read_CDD_BattRtnCurr_BattRtnCurrAdc_Val(data) (*(data) = Rte_CDD_MotCtrlMgr_BattRtnCurrAdc_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BattRtnCurrAdcFaild_Logl Rte_Read_CDD_BattRtnCurr_BattRtnCurrAdcFaild_Logl
#  define Rte_Read_CDD_BattRtnCurr_BattRtnCurrAdcFaild_Logl(data) (*(data) = Rte_CDD_Bmw5441McuCfg_BattRtnCurrAdcFaild_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_SplyCurrEstim_Val Rte_Read_CDD_BattRtnCurr_SplyCurrEstim_Val
#  define Rte_Read_CDD_BattRtnCurr_SplyCurrEstim_Val(data) (*(data) = Rte_ElecPwrCns_SplyCurrEstim_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_SysSt_Val Rte_Read_CDD_BattRtnCurr_SysSt_Val
#  define Rte_Read_CDD_BattRtnCurr_SysSt_Val(data) (*(data) = Rte_SysStMod_SysSt_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_BattRtnCurrAmpr_Val Rte_Write_CDD_BattRtnCurr_BattRtnCurrAmpr_Val
#  define Rte_Write_CDD_BattRtnCurr_BattRtnCurrAmpr_Val(data) (Rte_CDD_BattRtnCurr_BattRtnCurrAmpr_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_BattRtnCurrStsQlfr_Val Rte_Write_CDD_BattRtnCurr_BattRtnCurrStsQlfr_Val
#  define Rte_Write_CDD_BattRtnCurr_BattRtnCurrStsQlfr_Val(data) (Rte_CDD_BattRtnCurr_BattRtnCurrStsQlfr_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_DIAGCMGR_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_DIAGCMGR_APPL_CODE) CnvSnpshtData_f32_Oper(P2VAR(uint32, AUTOMATIC, RTE_DIAGCMGR_APPL_VAR) SnpshtDataCnvd_Arg, float32 SnpshtData_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DIAGCMGR_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_CnvSnpshtData_f32_Oper(arg1, arg2) (CnvSnpshtData_f32_Oper(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_DIAGCMGR_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_DIAGCMGR_APPL_CODE) CnvSnpshtData_u08_Oper(P2VAR(uint32, AUTOMATIC, RTE_DIAGCMGR_APPL_VAR) SnpshtDataCnvd_Arg, uint8 SnpshtData_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DIAGCMGR_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_CnvSnpshtData_u08_Oper(arg1, arg2) (CnvSnpshtData_u08_Oper(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_DIAGCMGRPROXYAPPL8_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_DIAGCMGRPROXYAPPL8_APPL_CODE) GetNtcQlfrSts8_Oper(NtcNr1 NtcNr_Arg, P2VAR(SigQlfr1, AUTOMATIC, RTE_DIAGCMGRPROXYAPPL8_APPL_VAR) NtcQlfr_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DIAGCMGRPROXYAPPL8_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_GetNtcQlfrSts_Oper GetNtcQlfrSts8_Oper
#  define RTE_START_SEC_DIAGCMGRPROXYAPPL8_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_DIAGCMGRPROXYAPPL8_APPL_CODE) SetNtcStsAndSnpshtData8_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg, uint32 SpclSnpshtData0_Arg, uint32 SpclSnpshtData1_Arg, uint32 SpclSnpshtData2_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DIAGCMGRPROXYAPPL8_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_SetNtcStsAndSnpshtData_Oper SetNtcStsAndSnpshtData8_Oper


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_Appl8_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl8_PIM_GROUP) Rte_CDD_BattRtnCurr_dBattRtnCurrBfrSatn; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl8_PIM_GROUP) Rte_CDD_BattRtnCurr_BattCurrEstimDifLpFil; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Appl8_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  endif

#  define Rte_Pim_dBattRtnCurrBfrSatn() \
  (&Rte_CDD_BattRtnCurr_dBattRtnCurrBfrSatn) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_BattCurrEstimDifLpFil() \
  (&Rte_CDD_BattRtnCurr_BattCurrEstimDifLpFil) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define CDD_BattRtnCurr_START_SEC_CODE
# include "CDD_BattRtnCurr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_BattRtnCurrInit1 BattRtnCurrInit1
#  define RTE_RUNNABLE_BattRtnCurrPer2 BattRtnCurrPer2
# endif

FUNC(void, CDD_BattRtnCurr_CODE) BattRtnCurrInit1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CDD_BattRtnCurr_CODE) BattRtnCurrPer2(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define CDD_BattRtnCurr_STOP_SEC_CODE
# include "CDD_BattRtnCurr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_GetNtcQlfrSts_PortIf1_E_NOT_OK (1U)

#  define RTE_E_SetNtcStsAndSnpshtData_PortIf1_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CDD_BATTRTNCURR_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
