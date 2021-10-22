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
 *          File:  Rte_RvsBattProtn.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <RvsBattProtn>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_RVSBATTPROTN_H
# define _RTE_RVSBATTPROTN_H

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

# include "Rte_RvsBattProtn_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_Appl7_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(SigQlfr1, RTE_VAR_INIT) Rte_RvsBattProtn_RvsBattProtnStsQlfr_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_Appl7_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_INIT) Rte_CDD_Bmw5441McuCfg_RvsBattDiagcGndAdc_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_CDD_Bmw5441McuCfg_RvsBattDiagcGndAdcFaild_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_Bmw5441McuCfg_RvsBattDiagcRtnAdc_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_CDD_Bmw5441McuCfg_RvsBattDiagcRtnAdcFaild_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_RvsBattDiagcGndAdc_Val (0.0F)
#  define Rte_InitValue_RvsBattDiagcGndAdcFaild_Logl (FALSE)
#  define Rte_InitValue_RvsBattDiagcRtnAdc_Val (0.0F)
#  define Rte_InitValue_RvsBattDiagcRtnAdcFaild_Logl (FALSE)
#  define Rte_InitValue_RvsBattProtnStsQlfr_Val (0U)
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_RvsBattDiagcGndAdc_Val Rte_Read_RvsBattProtn_RvsBattDiagcGndAdc_Val
#  define Rte_Read_RvsBattProtn_RvsBattDiagcGndAdc_Val(data) (*(data) = Rte_CDD_Bmw5441McuCfg_RvsBattDiagcGndAdc_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_RvsBattDiagcGndAdcFaild_Logl Rte_Read_RvsBattProtn_RvsBattDiagcGndAdcFaild_Logl
#  define Rte_Read_RvsBattProtn_RvsBattDiagcGndAdcFaild_Logl(data) (*(data) = Rte_CDD_Bmw5441McuCfg_RvsBattDiagcGndAdcFaild_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_RvsBattDiagcRtnAdc_Val Rte_Read_RvsBattProtn_RvsBattDiagcRtnAdc_Val
#  define Rte_Read_RvsBattProtn_RvsBattDiagcRtnAdc_Val(data) (*(data) = Rte_CDD_Bmw5441McuCfg_RvsBattDiagcRtnAdc_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_RvsBattDiagcRtnAdcFaild_Logl Rte_Read_RvsBattProtn_RvsBattDiagcRtnAdcFaild_Logl
#  define Rte_Read_RvsBattProtn_RvsBattDiagcRtnAdcFaild_Logl(data) (*(data) = Rte_CDD_Bmw5441McuCfg_RvsBattDiagcRtnAdcFaild_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_RvsBattProtnStsQlfr_Val Rte_Write_RvsBattProtn_RvsBattProtnStsQlfr_Val
#  define Rte_Write_RvsBattProtn_RvsBattProtnStsQlfr_Val(data) (Rte_RvsBattProtn_RvsBattProtnStsQlfr_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_DIAGCMGR_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_DIAGCMGR_APPL_CODE) CnvSnpshtData_f32_Oper(P2VAR(uint32, AUTOMATIC, RTE_DIAGCMGR_APPL_VAR) SnpshtDataCnvd_Arg, float32 SnpshtData_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DIAGCMGR_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_CnvSnpshtData_f32_Oper(arg1, arg2) (CnvSnpshtData_f32_Oper(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_DIAGCMGRPROXYAPPL7_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_DIAGCMGRPROXYAPPL7_APPL_CODE) GetNtcQlfrSts7_Oper(NtcNr1 NtcNr_Arg, P2VAR(SigQlfr1, AUTOMATIC, RTE_DIAGCMGRPROXYAPPL7_APPL_VAR) NtcQlfr_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DIAGCMGRPROXYAPPL7_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_GetNtcQlfrSts_Oper GetNtcQlfrSts7_Oper
#  define RTE_START_SEC_DIAGCMGRPROXYAPPL7_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_DIAGCMGRPROXYAPPL7_APPL_CODE) SetNtcStsAndSnpshtData7_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg, uint32 SpclSnpshtData0_Arg, uint32 SpclSnpshtData1_Arg, uint32 SpclSnpshtData2_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DIAGCMGRPROXYAPPL7_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_SetNtcStsAndSnpshtData_Oper SetNtcStsAndSnpshtData7_Oper


# endif /* !defined(RTE_CORE) */


# define RvsBattProtn_START_SEC_CODE
# include "RvsBattProtn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_RvsBattProtnInit1 RvsBattProtnInit1
#  define RTE_RUNNABLE_RvsBattProtnPer1 RvsBattProtnPer1
# endif

FUNC(void, RvsBattProtn_CODE) RvsBattProtnInit1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, RvsBattProtn_CODE) RvsBattProtnPer1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define RvsBattProtn_STOP_SEC_CODE
# include "RvsBattProtn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


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

#endif /* _RTE_RVSBATTPROTN_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
