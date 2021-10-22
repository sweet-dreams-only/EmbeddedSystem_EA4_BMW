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
 *          File:  Rte_CDD_Tauj0CfgAndUse.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <CDD_Tauj0CfgAndUse>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CDD_TAUJ0CFGANDUSE_H
# define _RTE_CDD_TAUJ0CFGANDUSE_H

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

# include "Rte_CDD_Tauj0CfgAndUse_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint32, RTE_VAR_INIT) Rte_CDD_Tauj0CfgAndUse_PhaOnTiMeasdA_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_INIT) Rte_CDD_Tauj0CfgAndUse_PhaOnTiMeasdB_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_INIT) Rte_CDD_Tauj0CfgAndUse_PhaOnTiMeasdC_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_PhaOnTiMeasdA_Val (0U)
#  define Rte_InitValue_PhaOnTiMeasdB_Val (0U)
#  define Rte_InitValue_PhaOnTiMeasdC_Val (0U)
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_PhaOnTiMeasdA_Val Rte_Write_CDD_Tauj0CfgAndUse_PhaOnTiMeasdA_Val
#  define Rte_Write_CDD_Tauj0CfgAndUse_PhaOnTiMeasdA_Val(data) (Rte_CDD_Tauj0CfgAndUse_PhaOnTiMeasdA_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_PhaOnTiMeasdB_Val Rte_Write_CDD_Tauj0CfgAndUse_PhaOnTiMeasdB_Val
#  define Rte_Write_CDD_Tauj0CfgAndUse_PhaOnTiMeasdB_Val(data) (Rte_CDD_Tauj0CfgAndUse_PhaOnTiMeasdB_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_PhaOnTiMeasdC_Val Rte_Write_CDD_Tauj0CfgAndUse_PhaOnTiMeasdC_Val
#  define Rte_Write_CDD_Tauj0CfgAndUse_PhaOnTiMeasdC_Val(data) (Rte_CDD_Tauj0CfgAndUse_PhaOnTiMeasdC_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_Tauj0CfgAndUse_PhaOnTiCntrAPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_Tauj0CfgAndUse_PhaOnTiCntrBPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_Tauj0CfgAndUse_PhaOnTiCntrCPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  endif

#  define Rte_Pim_PhaOnTiCntrAPrev() \
  (&Rte_CDD_Tauj0CfgAndUse_PhaOnTiCntrAPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_PhaOnTiCntrBPrev() \
  (&Rte_CDD_Tauj0CfgAndUse_PhaOnTiCntrBPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_PhaOnTiCntrCPrev() \
  (&Rte_CDD_Tauj0CfgAndUse_PhaOnTiCntrCPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define CDD_Tauj0CfgAndUse_START_SEC_CODE
# include "CDD_Tauj0CfgAndUse_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_Tauj0CfgAndUseInit1 Tauj0CfgAndUseInit1
#  define RTE_RUNNABLE_Tauj0CfgAndUsePer1 Tauj0CfgAndUsePer1
# endif

FUNC(void, CDD_Tauj0CfgAndUse_CODE) Tauj0CfgAndUseInit1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CDD_Tauj0CfgAndUse_CODE) Tauj0CfgAndUsePer1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define CDD_Tauj0CfgAndUse_STOP_SEC_CODE
# include "CDD_Tauj0CfgAndUse_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CDD_TAUJ0CFGANDUSE_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
