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
 *          File:  Rte_CDD_DmaCfgAndUse.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <CDD_DmaCfgAndUse>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CDD_DMACFGANDUSE_H
# define _RTE_CDD_DMACFGANDUSE_H

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

# include "Rte_CDD_DmaCfgAndUse_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint32, RTE_VAR_INIT) Rte_CDD_MotAg0Meas_MotAg0SnsrCfgAdr_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_MotAg0SnsrCfgAdr_Val (0U)
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_MotAg0SnsrCfgAdr_Val Rte_Read_CDD_DmaCfgAndUse_MotAg0SnsrCfgAdr_Val
#  define Rte_Read_CDD_DmaCfgAndUse_MotAg0SnsrCfgAdr_Val(data) (*(data) = Rte_CDD_MotAg0Meas_MotAg0SnsrCfgAdr_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_CDD_ADC1CFGANDUSE_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_CDD_ADC1CFGANDUSE_APPL_CODE) Adc1CfgAndUseAdc1EnaCnvn_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CDD_ADC1CFGANDUSE_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_Adc1CfgAndUseAdc1EnaCnvn_Oper() (Adc1CfgAndUseAdc1EnaCnvn_Oper(), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_CDD_NXTRTI_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_CDD_NXTRTI_APPL_CODE) GetRefTmr1MicroSec32bit_Oper(P2VAR(uint32, AUTOMATIC, RTE_CDD_NXTRTI_APPL_VAR) RefTmr_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CDD_NXTRTI_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_GetRefTmr1MicroSec32bit_Oper(arg1) (GetRefTmr1MicroSec32bit_Oper(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_CDD_NXTRTI_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_CDD_NXTRTI_APPL_CODE) GetTiSpan1MicroSec32bit_Oper(uint32 RefTmr_Arg, P2VAR(uint32, AUTOMATIC, RTE_CDD_NXTRTI_APPL_VAR) TiSpan_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CDD_NXTRTI_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_GetTiSpan1MicroSec32bit_Oper(arg1, arg2) (GetTiSpan1MicroSec32bit_Oper(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_ReadErrInjReg_Oper(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_StrtErrInjCntr_Oper() (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_DmaCfgAndUse_DmaCfgAndUse2MilliSecAdcMaxDmaTrfTi; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_DmaCfgAndUse_DmaCfgAndUse2MilliSecAdcStrtTi; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_DmaCfgAndUse_MotAg0ReadPtrRst; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_DmaCfgAndUse_MotAg0SnsrCfgAdrStord; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_DmaCfgAndUse_MotAg0TrsmStrt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_DmaCfgAndUse_MotAg1ReadPtrRst; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_DmaCfgAndUse_MotAg1SnsrCfgAdrStord; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_DmaCfgAndUse_MotAg1TrsmStrt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_DmaCfgAndUse_d2MilliSecAdcActDmaTrfTi; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  endif

#  define Rte_Pim_DmaCfgAndUse2MilliSecAdcMaxDmaTrfTi() \
  (&Rte_CDD_DmaCfgAndUse_DmaCfgAndUse2MilliSecAdcMaxDmaTrfTi) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_DmaCfgAndUse2MilliSecAdcStrtTi() \
  (&Rte_CDD_DmaCfgAndUse_DmaCfgAndUse2MilliSecAdcStrtTi) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MotAg0ReadPtrRst() \
  (&Rte_CDD_DmaCfgAndUse_MotAg0ReadPtrRst) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MotAg0SnsrCfgAdrStord() \
  (&Rte_CDD_DmaCfgAndUse_MotAg0SnsrCfgAdrStord) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MotAg0TrsmStrt() \
  (&Rte_CDD_DmaCfgAndUse_MotAg0TrsmStrt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MotAg1ReadPtrRst() \
  (&Rte_CDD_DmaCfgAndUse_MotAg1ReadPtrRst) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MotAg1SnsrCfgAdrStord() \
  (&Rte_CDD_DmaCfgAndUse_MotAg1SnsrCfgAdrStord) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MotAg1TrsmStrt() \
  (&Rte_CDD_DmaCfgAndUse_MotAg1TrsmStrt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_d2MilliSecAdcActDmaTrfTi() \
  (&Rte_CDD_DmaCfgAndUse_d2MilliSecAdcActDmaTrfTi) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define CDD_DmaCfgAndUse_START_SEC_CODE
# include "CDD_DmaCfgAndUse_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_DmaCfgAndUseInit1 DmaCfgAndUseInit1
#  define RTE_RUNNABLE_DmaCfgAndUsePer1 DmaCfgAndUsePer1
#  define RTE_RUNNABLE_DmaEna2MilliSecToMotCtrlTrf_Oper DmaEna2MilliSecToMotCtrlTrf_Oper
#  define RTE_RUNNABLE_DmaWaitForMotCtrlTo2MilliSecTrf_Oper DmaWaitForMotCtrlTo2MilliSecTrf_Oper
#  define RTE_RUNNABLE_MotAg0SnsrCfgDmaStrt_Oper MotAg0SnsrCfgDmaStrt_Oper
# endif

FUNC(void, CDD_DmaCfgAndUse_CODE) DmaCfgAndUseInit1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CDD_DmaCfgAndUse_CODE) DmaCfgAndUsePer1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CDD_DmaCfgAndUse_CODE) DmaEna2MilliSecToMotCtrlTrf_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, CDD_DmaCfgAndUse_CODE) DmaWaitForMotCtrlTo2MilliSecTrf_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, CDD_DmaCfgAndUse_CODE) MotAg0SnsrCfgDmaStrt_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define CDD_DmaCfgAndUse_STOP_SEC_CODE
# include "CDD_DmaCfgAndUse_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_DmaWaitForMotCtrlTo2MilliSecTrf_PortIf1_E_NOT_OK (1U)

#  define RTE_E_MotAg0SnsrCfgDmaStrt_PortIf2_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CDD_DMACFGANDUSE_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
