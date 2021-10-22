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
 *          File:  Rte_BmwMsgSlot49Bas1Repn2BusFrChA.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <BmwMsgSlot49Bas1Repn2BusFrChA>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_BMWMSGSLOT49BAS1REPN2BUSFRCHA_H
# define _RTE_BMWMSGSLOT49BAS1REPN2BUSFRCHA_H

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

# include "Rte_BmwMsgSlot49Bas1Repn2BusFrChA_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_Appl8_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_INIT) Rte_CDD_BattRtnCurr_BattRtnCurrAmpr_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(BattRtnCurrAmprQlfr1, RTE_VAR_INIT) Rte_CDD_BattRtnCurr_BattRtnCurrStsQlfr_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_Appl8_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(EpsCurrLimSts1, RTE_VAR_INIT) Rte_BmwMsgSlot49Bas1Repn2BusFrChA_EpsCurrLimSts_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_BattRtnCurrAmpr_Val (0.0F)
#  define Rte_InitValue_BattRtnCurrAmprQlfr_Val (15U)
#  define Rte_InitValue_EpsCurrLimSts_Val (15U)
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot49Bas1Repn2BusFrChA_sigGroup_DT_EST_sigGroup_DT_EST(P2CONST(sigGroup_DT_EST1, AUTOMATIC, RTE_BMWMSGSLOT49BAS1REPN2BUSFRCHA_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_BattRtnCurrAmpr_Val Rte_Read_BmwMsgSlot49Bas1Repn2BusFrChA_BattRtnCurrAmpr_Val
#  define Rte_Read_BmwMsgSlot49Bas1Repn2BusFrChA_BattRtnCurrAmpr_Val(data) (*(data) = Rte_CDD_BattRtnCurr_BattRtnCurrAmpr_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BattRtnCurrAmprQlfr_Val Rte_Read_BmwMsgSlot49Bas1Repn2BusFrChA_BattRtnCurrAmprQlfr_Val
#  define Rte_Read_BmwMsgSlot49Bas1Repn2BusFrChA_BattRtnCurrAmprQlfr_Val(data) (*(data) = Rte_CDD_BattRtnCurr_BattRtnCurrStsQlfr_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_EpsCurrLimSts_Val Rte_Read_BmwMsgSlot49Bas1Repn2BusFrChA_EpsCurrLimSts_Val
#  define Rte_Read_BmwMsgSlot49Bas1Repn2BusFrChA_EpsCurrLimSts_Val(data) (*(data) = Rte_BmwMsgSlot49Bas1Repn2BusFrChA_EpsCurrLimSts_Val, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_sigGroup_DT_EST_sigGroup_DT_EST Rte_Write_BmwMsgSlot49Bas1Repn2BusFrChA_sigGroup_DT_EST_sigGroup_DT_EST


# endif /* !defined(RTE_CORE) */


# define BmwMsgSlot49Bas1Repn2BusFrChA_START_SEC_CODE
# include "BmwMsgSlot49Bas1Repn2BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_BmwMsgSlot49Bas1Repn2BusFrChAInit1 BmwMsgSlot49Bas1Repn2BusFrChAInit1
#  define RTE_RUNNABLE_BmwMsgSlot49Bas1Repn2BusFrChAPer1 BmwMsgSlot49Bas1Repn2BusFrChAPer1
# endif

FUNC(void, BmwMsgSlot49Bas1Repn2BusFrChA_CODE) BmwMsgSlot49Bas1Repn2BusFrChAInit1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, BmwMsgSlot49Bas1Repn2BusFrChA_CODE) BmwMsgSlot49Bas1Repn2BusFrChAPer1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define BmwMsgSlot49Bas1Repn2BusFrChA_STOP_SEC_CODE
# include "BmwMsgSlot49Bas1Repn2BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_BMWMSGSLOT49BAS1REPN2BUSFRCHA_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
