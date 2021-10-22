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
 *          File:  Rte_BmwMsgSlot274Bas0Repn8BusFrChA.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <BmwMsgSlot274Bas0Repn8BusFrChA>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_BMWMSGSLOT274BAS0REPN8BUSFRCHA_H
# define _RTE_BMWMSGSLOT274BAS0REPN8BUSFRCHA_H

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

# include "Rte_BmwMsgSlot274Bas0Repn8BusFrChA_Type.h"
# include "Rte_DataHandleType.h"


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot274Bas0Repn8BusFrChA_sigGroup_SU_EPS_sigGroup_SU_EPS(P2CONST(sigGroup_SU_EPS1, AUTOMATIC, RTE_BMWMSGSLOT274BAS0REPN8BUSFRCHA_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_sigGroup_SU_EPS_sigGroup_SU_EPS Rte_Write_BmwMsgSlot274Bas0Repn8BusFrChA_sigGroup_SU_EPS_sigGroup_SU_EPS


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot274Bas0Repn8BusFrChA_SuEpsPerCntr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot274Bas0Repn8BusFrChA_SuEpsBurstCntr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot274Bas0Repn8BusFrChA_SuEpsDebCntr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(sigGroup_SU_EPS1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot274Bas0Repn8BusFrChA_SigGroupSuEps; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  endif

#  define Rte_Pim_SuEpsPerCntr() \
  (&Rte_BmwMsgSlot274Bas0Repn8BusFrChA_SuEpsPerCntr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_SuEpsBurstCntr() \
  (&Rte_BmwMsgSlot274Bas0Repn8BusFrChA_SuEpsBurstCntr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_SuEpsDebCntr() \
  (&Rte_BmwMsgSlot274Bas0Repn8BusFrChA_SuEpsDebCntr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_SigGroupSuEps() \
  (&Rte_BmwMsgSlot274Bas0Repn8BusFrChA_SigGroupSuEps) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define BmwMsgSlot274Bas0Repn8BusFrChA_START_SEC_CODE
# include "BmwMsgSlot274Bas0Repn8BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_BmwMsgSlot274Bas0Repn8BusFrChAInit1 BmwMsgSlot274Bas0Repn8BusFrChAInit1
#  define RTE_RUNNABLE_BmwMsgSlot274Bas0Repn8BusFrChAPer1 BmwMsgSlot274Bas0Repn8BusFrChAPer1
#  define RTE_RUNNABLE_CfgMsgTxReq_Oper CfgMsgTxReq_Oper
# endif

FUNC(void, BmwMsgSlot274Bas0Repn8BusFrChA_CODE) BmwMsgSlot274Bas0Repn8BusFrChAInit1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, BmwMsgSlot274Bas0Repn8BusFrChA_CODE) BmwMsgSlot274Bas0Repn8BusFrChAPer1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, BmwMsgSlot274Bas0Repn8BusFrChA_CODE) CfgMsgTxReq_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define BmwMsgSlot274Bas0Repn8BusFrChA_STOP_SEC_CODE
# include "BmwMsgSlot274Bas0Repn8BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_BMWMSGSLOT274BAS0REPN8BUSFRCHA_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
