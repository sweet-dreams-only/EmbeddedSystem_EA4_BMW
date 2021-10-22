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
 *          File:  Rte_BmwMsgSlot234Bas1Repn2BusFrChA.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <BmwMsgSlot234Bas1Repn2BusFrChA>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_BMWMSGSLOT234BAS1REPN2BUSFRCHA_H
# define _RTE_BMWMSGSLOT234BAS1REPN2BUSFRCHA_H

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

# include "Rte_BmwMsgSlot234Bas1Repn2BusFrChA_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_Appl7_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(HaptcFbSt1, RTE_VAR_INIT) Rte_BmwHaptcFb_HaptcFbSt_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_Appl7_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(BmwEpsFctSts1, RTE_VAR_INIT) Rte_BmwStReqMgr_BmwEpsFctSts_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(DrvgDynIfSt1, RTE_VAR_INIT) Rte_BmwDrvgDynStMac_DrvgDynIfSt_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_BmwEpsFctSts_Val (128U)
#  define Rte_InitValue_DrvgDynIfSt_Val (128U)
#  define Rte_InitValue_HaptcFbSt_Val (14U)
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot234Bas1Repn2BusFrChA_sigGroup_ST_EST_sigGroup_ST_EST(P2CONST(sigGroup_ST_EST1, AUTOMATIC, RTE_BMWMSGSLOT234BAS1REPN2BUSFRCHA_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_BmwEpsFctSts_Val Rte_Read_BmwMsgSlot234Bas1Repn2BusFrChA_BmwEpsFctSts_Val
#  define Rte_Read_BmwMsgSlot234Bas1Repn2BusFrChA_BmwEpsFctSts_Val(data) (*(data) = Rte_BmwStReqMgr_BmwEpsFctSts_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_DrvgDynIfSt_Val Rte_Read_BmwMsgSlot234Bas1Repn2BusFrChA_DrvgDynIfSt_Val
#  define Rte_Read_BmwMsgSlot234Bas1Repn2BusFrChA_DrvgDynIfSt_Val(data) (*(data) = Rte_BmwDrvgDynStMac_DrvgDynIfSt_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_HaptcFbSt_Val Rte_Read_BmwMsgSlot234Bas1Repn2BusFrChA_HaptcFbSt_Val
#  define Rte_Read_BmwMsgSlot234Bas1Repn2BusFrChA_HaptcFbSt_Val(data) (*(data) = Rte_BmwHaptcFb_HaptcFbSt_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_sigGroup_ST_EST_sigGroup_ST_EST Rte_Write_BmwMsgSlot234Bas1Repn2BusFrChA_sigGroup_ST_EST_sigGroup_ST_EST


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(BmwEpsFctSts1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot234Bas1Repn2BusFrChA_BmwEpsFctStsPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot234Bas1Repn2BusFrChA_BurstModCntr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot234Bas1Repn2BusFrChA_CycCntr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(DrvgDynIfSt1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot234Bas1Repn2BusFrChA_DrvgDynIfStPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(HaptcFbSt1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot234Bas1Repn2BusFrChA_HaptcFbStPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot234Bas1Repn2BusFrChA_PerdCntr; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  endif

#  define Rte_Pim_BmwEpsFctStsPrev() \
  (&Rte_BmwMsgSlot234Bas1Repn2BusFrChA_BmwEpsFctStsPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_BurstModCntr() \
  (&Rte_BmwMsgSlot234Bas1Repn2BusFrChA_BurstModCntr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_CycCntr() \
  (&Rte_BmwMsgSlot234Bas1Repn2BusFrChA_CycCntr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_DrvgDynIfStPrev() \
  (&Rte_BmwMsgSlot234Bas1Repn2BusFrChA_DrvgDynIfStPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_HaptcFbStPrev() \
  (&Rte_BmwMsgSlot234Bas1Repn2BusFrChA_HaptcFbStPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_PerdCntr() \
  (&Rte_BmwMsgSlot234Bas1Repn2BusFrChA_PerdCntr) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define BmwMsgSlot234Bas1Repn2BusFrChA_START_SEC_CODE
# include "BmwMsgSlot234Bas1Repn2BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_BmwMsgSlot234Bas1Repn2BusFrChAInit1 BmwMsgSlot234Bas1Repn2BusFrChAInit1
#  define RTE_RUNNABLE_BmwMsgSlot234Bas1Repn2BusFrChAPer1 BmwMsgSlot234Bas1Repn2BusFrChAPer1
# endif

FUNC(void, BmwMsgSlot234Bas1Repn2BusFrChA_CODE) BmwMsgSlot234Bas1Repn2BusFrChAInit1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, BmwMsgSlot234Bas1Repn2BusFrChA_CODE) BmwMsgSlot234Bas1Repn2BusFrChAPer1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define BmwMsgSlot234Bas1Repn2BusFrChA_STOP_SEC_CODE
# include "BmwMsgSlot234Bas1Repn2BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_BMWMSGSLOT234BAS1REPN2BUSFRCHA_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
