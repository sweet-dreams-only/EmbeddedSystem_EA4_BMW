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
 *          File:  Rte_McuErrInj.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <McuErrInj>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_MCUERRINJ_H
# define _RTE_MCUERRINJ_H

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

# include "Rte_McuErrInj_Type.h"
# include "Rte_DataHandleType.h"


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_McuErrInj_ErrInjActvCntr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_McuErrInj_StrtErrInj; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  endif

#  define Rte_Pim_ErrInjActvCntr() \
  (&Rte_McuErrInj_ErrInjActvCntr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_StrtErrInj() \
  (&Rte_McuErrInj_StrtErrInj) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define McuErrInj_START_SEC_CODE
# include "McuErrInj_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_ClrErrInjReg_Oper ClrErrInjReg_Oper
#  define RTE_RUNNABLE_McuErrInjInit1 McuErrInjInit1
#  define RTE_RUNNABLE_McuErrInjPer1 McuErrInjPer1
#  define RTE_RUNNABLE_ReadErrInjReg_Oper ReadErrInjReg_Oper
#  define RTE_RUNNABLE_StrtErrInjCntr_Oper StrtErrInjCntr_Oper
#  define RTE_RUNNABLE_UpdErrInjReg_Oper UpdErrInjReg_Oper
# endif

FUNC(void, McuErrInj_CODE) ClrErrInjReg_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, McuErrInj_CODE) McuErrInjInit1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, McuErrInj_CODE) McuErrInjPer1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, McuErrInj_CODE) ReadErrInjReg_Oper(P2VAR(uint32, AUTOMATIC, RTE_MCUERRINJ_APPL_VAR) ErrId_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, McuErrInj_CODE) StrtErrInjCntr_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, McuErrInj_CODE) UpdErrInjReg_Oper(uint16 NtcNr_Arg, uint8 NtcStInfo_Arg, uint8 ErrInjNr_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define McuErrInj_STOP_SEC_CODE
# include "McuErrInj_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_MCUERRINJ_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
