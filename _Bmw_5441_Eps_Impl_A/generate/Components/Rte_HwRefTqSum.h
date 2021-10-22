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
 *          File:  Rte_HwRefTqSum.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <HwRefTqSum>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_HWREFTQSUM_H
# define _RTE_HWREFTQSUM_H

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

# include "Rte_HwRefTqSum_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_Appl7_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_INIT) Rte_HwRefTqSum_HwTqCmdSum_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwPwrPrkgDampg_DampgCmdPwrPrkg_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_Effort_HwTqCmdEffort_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwHwTqOvrlArbn_HwTqCmdOvrl_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_Appl7_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_INIT) Rte_BmwSwFctDi_HwTqCmdHysBmwOvrd_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwSwFctDi_CtrldVelRtnCmdBmwOvrd_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_HwTqCmdDampg_Val (0.0F)
#  define Rte_InitValue_HwTqCmdEffort_Val (0.0F)
#  define Rte_InitValue_HwTqCmdHys_Val (0.0F)
#  define Rte_InitValue_HwTqCmdOvrl_Val (0.0F)
#  define Rte_InitValue_HwTqCmdSum_Val (0.0F)
#  define Rte_InitValue_RtnCmd_Val (0.0F)
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_HwTqCmdDampg_Val Rte_Read_HwRefTqSum_HwTqCmdDampg_Val
#  define Rte_Read_HwRefTqSum_HwTqCmdDampg_Val(data) (*(data) = Rte_BmwPwrPrkgDampg_DampgCmdPwrPrkg_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_HwTqCmdEffort_Val Rte_Read_HwRefTqSum_HwTqCmdEffort_Val
#  define Rte_Read_HwRefTqSum_HwTqCmdEffort_Val(data) (*(data) = Rte_Effort_HwTqCmdEffort_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_HwTqCmdHys_Val Rte_Read_HwRefTqSum_HwTqCmdHys_Val
#  define Rte_Read_HwRefTqSum_HwTqCmdHys_Val(data) (*(data) = Rte_BmwSwFctDi_HwTqCmdHysBmwOvrd_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_HwTqCmdOvrl_Val Rte_Read_HwRefTqSum_HwTqCmdOvrl_Val
#  define Rte_Read_HwRefTqSum_HwTqCmdOvrl_Val(data) (*(data) = Rte_BmwHwTqOvrlArbn_HwTqCmdOvrl_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_RtnCmd_Val Rte_Read_HwRefTqSum_RtnCmd_Val
#  define Rte_Read_HwRefTqSum_RtnCmd_Val(data) (*(data) = Rte_BmwSwFctDi_CtrldVelRtnCmdBmwOvrd_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_HwTqCmdSum_Val Rte_Write_HwRefTqSum_HwTqCmdSum_Val
#  define Rte_Write_HwRefTqSum_HwTqCmdSum_Val(data) (Rte_HwRefTqSum_HwTqCmdSum_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

#  define Rte_Prm_SysGlbPrmSysTqRat_Val() (((P2CONST(Rte_Calprm_CalRegn01IninOptSetA00_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01IninOptSetA00_DEFAULT_RTE_CALPRM_GROUP])->SysGlbPrmSysTqRat_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# endif /* !defined(RTE_CORE) */


# define HwRefTqSum_START_SEC_CODE
# include "HwRefTqSum_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_HwRefTqSumInit1 HwRefTqSumInit1
#  define RTE_RUNNABLE_HwRefTqSumPer1 HwRefTqSumPer1
# endif

FUNC(void, HwRefTqSum_CODE) HwRefTqSumInit1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, HwRefTqSum_CODE) HwRefTqSumPer1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define HwRefTqSum_STOP_SEC_CODE
# include "HwRefTqSum_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_HWREFTQSUM_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
