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
 *          File:  Rte_BmwMsgSlot49Bas0Repn2BusFrChA.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <BmwMsgSlot49Bas0Repn2BusFrChA>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_BMWMSGSLOT49BAS0REPN2BUSFRCHA_H
# define _RTE_BMWMSGSLOT49BAS0REPN2BUSFRCHA_H

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

# include "Rte_BmwMsgSlot49Bas0Repn2BusFrChA_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_Appl7_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_INIT) Rte_EpsStEstimn_RackFEstimd_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_Appl7_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_Appl8_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_INIT) Rte_ElecPwrCns_ElecInpPwrEstim_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_Appl8_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_INIT) Rte_HwTqArbn_HwTq_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(SigQlfr1, RTE_VAR_INIT) Rte_CDD_HwTq4Meas_HwTq4Qlfr_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(SigQlfr1, RTE_VAR_INIT) Rte_CDD_HwTq5Meas_HwTq5Qlfr_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_ElecInpPwrEstim_Val (0.0F)
#  define Rte_InitValue_HwTq_Val (0.0F)
#  define Rte_InitValue_HwTq4Qlfr_Val (0U)
#  define Rte_InitValue_HwTq5Qlfr_Val (0U)
#  define Rte_InitValue_RackFEstimd_Val (0.0F)
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot49Bas0Repn2BusFrChA_sigGroup_AVL_FORC_GRD_sigGroup_AVL_FORC_GRD(P2CONST(sigGroup_AVL_FORC_GRD1, AUTOMATIC, RTE_BMWMSGSLOT49BAS0REPN2BUSFRCHA_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot49Bas0Repn2BusFrChA_sigGroup_AVL_STMOM_DV_ACT_sigGroup_AVL_STMOM_DV_ACT(P2CONST(sigGroup_AVL_STMOM_DV_ACT1, AUTOMATIC, RTE_BMWMSGSLOT49BAS0REPN2BUSFRCHA_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_ElecInpPwrEstim_Val Rte_Read_BmwMsgSlot49Bas0Repn2BusFrChA_ElecInpPwrEstim_Val
#  define Rte_Read_BmwMsgSlot49Bas0Repn2BusFrChA_ElecInpPwrEstim_Val(data) (*(data) = Rte_ElecPwrCns_ElecInpPwrEstim_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_HwTq_Val Rte_Read_BmwMsgSlot49Bas0Repn2BusFrChA_HwTq_Val
#  define Rte_Read_BmwMsgSlot49Bas0Repn2BusFrChA_HwTq_Val(data) (*(data) = Rte_HwTqArbn_HwTq_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_HwTq4Qlfr_Val Rte_Read_BmwMsgSlot49Bas0Repn2BusFrChA_HwTq4Qlfr_Val
#  define Rte_Read_BmwMsgSlot49Bas0Repn2BusFrChA_HwTq4Qlfr_Val(data) (*(data) = Rte_CDD_HwTq4Meas_HwTq4Qlfr_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_HwTq5Qlfr_Val Rte_Read_BmwMsgSlot49Bas0Repn2BusFrChA_HwTq5Qlfr_Val
#  define Rte_Read_BmwMsgSlot49Bas0Repn2BusFrChA_HwTq5Qlfr_Val(data) (*(data) = Rte_CDD_HwTq5Meas_HwTq5Qlfr_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_RackFEstimd_Val Rte_Read_BmwMsgSlot49Bas0Repn2BusFrChA_RackFEstimd_Val
#  define Rte_Read_BmwMsgSlot49Bas0Repn2BusFrChA_RackFEstimd_Val(data) (*(data) = Rte_EpsStEstimn_RackFEstimd_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_sigGroup_AVL_FORC_GRD_sigGroup_AVL_FORC_GRD Rte_Write_BmwMsgSlot49Bas0Repn2BusFrChA_sigGroup_AVL_FORC_GRD_sigGroup_AVL_FORC_GRD
#  define Rte_Write_sigGroup_AVL_STMOM_DV_ACT_sigGroup_AVL_STMOM_DV_ACT Rte_Write_BmwMsgSlot49Bas0Repn2BusFrChA_sigGroup_AVL_STMOM_DV_ACT_sigGroup_AVL_STMOM_DV_ACT


/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

#  define Rte_Prm_BmwMsgSlot49Bas0Repn2BusFrChARackEstimnLowrLim_Val() (-25000.0F) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwMsgSlot49Bas0Repn2BusFrChARackEstimnUpprLim_Val() (25000.0F) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwMsgSlot49Bas0Repn2BusFrChABmwSteerPolarity_Val() (-1) /* PRQA S 3453 */ /* MD_MSR_19.7 */

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot49Bas0Repn2BusFrChA_PerCntr; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  endif

#  define Rte_Pim_PerCntr() \
  (&Rte_BmwMsgSlot49Bas0Repn2BusFrChA_PerCntr) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define BmwMsgSlot49Bas0Repn2BusFrChA_START_SEC_CODE
# include "BmwMsgSlot49Bas0Repn2BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_BmwMsgSlot49Bas0Repn2BusFrChAInit1 BmwMsgSlot49Bas0Repn2BusFrChAInit1
#  define RTE_RUNNABLE_BmwMsgSlot49Bas0Repn2BusFrChAPer1 BmwMsgSlot49Bas0Repn2BusFrChAPer1
# endif

FUNC(void, BmwMsgSlot49Bas0Repn2BusFrChA_CODE) BmwMsgSlot49Bas0Repn2BusFrChAInit1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, BmwMsgSlot49Bas0Repn2BusFrChA_CODE) BmwMsgSlot49Bas0Repn2BusFrChAPer1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define BmwMsgSlot49Bas0Repn2BusFrChA_STOP_SEC_CODE
# include "BmwMsgSlot49Bas0Repn2BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_BMWMSGSLOT49BAS0REPN2BUSFRCHA_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
