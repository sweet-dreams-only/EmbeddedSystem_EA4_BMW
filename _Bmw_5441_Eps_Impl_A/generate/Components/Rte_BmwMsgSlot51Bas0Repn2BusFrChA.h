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
 *          File:  Rte_BmwMsgSlot51Bas0Repn2BusFrChA.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <BmwMsgSlot51Bas0Repn2BusFrChA>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_BMWMSGSLOT51BAS0REPN2BUSFRCHA_H
# define _RTE_BMWMSGSLOT51BAS0REPN2BUSFRCHA_H

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

# include "Rte_BmwMsgSlot51Bas0Repn2BusFrChA_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_INIT) Rte_BmwHwAgArbnAndEotPosn_BmwPinionAg_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwMsgSlot51Bas0Repn2BusFrChA_BmwPinionAgIdx_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwMsgSlot51Bas0Repn2BusFrChA_BmwPinionAgIdxVld_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(BmwPinionAgQlfr1, RTE_VAR_INIT) Rte_BmwHwAgArbnAndEotPosn_BmwPinionAgQlfr_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwHwAgArbnAndEotPosn_BmwRackCentrToVehCentrOffs_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwHwAgArbnAndEotPosn_BmwRackCentrToVehCentrOffsVld_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(BmwSeldPosnUnit1, RTE_VAR_INIT) Rte_BmwMsgSlot51Bas0Repn2BusFrChA_BmwSeldPosnUnit_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_HwTqTrakgCtrl_MotTqCmdTrakgCtrl_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwMsgSlot51Bas0Repn2BusFrChA_BmwTarMotTqVld_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(BmwTqSnsrIdx1, RTE_VAR_INIT) Rte_BmwMsgSlot51Bas0Repn2BusFrChA_BmwTqSnsrIdx_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_BmwPinionAg_Val (0.0F)
#  define Rte_InitValue_BmwPinionAgIdx_Val (0.0F)
#  define Rte_InitValue_BmwPinionAgIdxVld_Logl (FALSE)
#  define Rte_InitValue_BmwPinionAgQlfr_Val (14U)
#  define Rte_InitValue_BmwRackCntrToVehCntrOffs_Val (0.0F)
#  define Rte_InitValue_BmwRackCntrToVehCntrOffsVld_Logl (FALSE)
#  define Rte_InitValue_BmwSeldPosnUnit_Val (0U)
#  define Rte_InitValue_BmwTarMotTq_Val (0.0F)
#  define Rte_InitValue_BmwTarMotTqVld_Logl (FALSE)
#  define Rte_InitValue_BmwTqSnsrIdx_Val (3U)
#  define Rte_InitValue_TRGG_ENGTORQ_EPS_Val (4095U)
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot51Bas0Repn2BusFrChA_TRGG_ENGTORQ_EPS_Val(uint16 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot51Bas0Repn2BusFrChA_sigGroup_AVL_PO_EPS_sigGroup_AVL_PO_EPS(P2CONST(sigGroup_AVL_PO_EPS1, AUTOMATIC, RTE_BMWMSGSLOT51BAS0REPN2BUSFRCHA_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Invalidate_BmwMsgSlot51Bas0Repn2BusFrChA_sigGroup_AVL_PO_EPS_sigGroup_AVL_PO_EPS(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_BmwPinionAg_Val Rte_Read_BmwMsgSlot51Bas0Repn2BusFrChA_BmwPinionAg_Val
#  define Rte_Read_BmwMsgSlot51Bas0Repn2BusFrChA_BmwPinionAg_Val(data) (*(data) = Rte_BmwHwAgArbnAndEotPosn_BmwPinionAg_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BmwPinionAgIdx_Val Rte_Read_BmwMsgSlot51Bas0Repn2BusFrChA_BmwPinionAgIdx_Val
#  define Rte_Read_BmwMsgSlot51Bas0Repn2BusFrChA_BmwPinionAgIdx_Val(data) (*(data) = Rte_BmwMsgSlot51Bas0Repn2BusFrChA_BmwPinionAgIdx_Val, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BmwPinionAgIdxVld_Logl Rte_Read_BmwMsgSlot51Bas0Repn2BusFrChA_BmwPinionAgIdxVld_Logl
#  define Rte_Read_BmwMsgSlot51Bas0Repn2BusFrChA_BmwPinionAgIdxVld_Logl(data) (*(data) = Rte_BmwMsgSlot51Bas0Repn2BusFrChA_BmwPinionAgIdxVld_Logl, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BmwPinionAgQlfr_Val Rte_Read_BmwMsgSlot51Bas0Repn2BusFrChA_BmwPinionAgQlfr_Val
#  define Rte_Read_BmwMsgSlot51Bas0Repn2BusFrChA_BmwPinionAgQlfr_Val(data) (*(data) = Rte_BmwHwAgArbnAndEotPosn_BmwPinionAgQlfr_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BmwRackCntrToVehCntrOffs_Val Rte_Read_BmwMsgSlot51Bas0Repn2BusFrChA_BmwRackCntrToVehCntrOffs_Val
#  define Rte_Read_BmwMsgSlot51Bas0Repn2BusFrChA_BmwRackCntrToVehCntrOffs_Val(data) (*(data) = Rte_BmwHwAgArbnAndEotPosn_BmwRackCentrToVehCentrOffs_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BmwRackCntrToVehCntrOffsVld_Logl Rte_Read_BmwMsgSlot51Bas0Repn2BusFrChA_BmwRackCntrToVehCntrOffsVld_Logl
#  define Rte_Read_BmwMsgSlot51Bas0Repn2BusFrChA_BmwRackCntrToVehCntrOffsVld_Logl(data) (*(data) = Rte_BmwHwAgArbnAndEotPosn_BmwRackCentrToVehCentrOffsVld_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BmwSeldPosnUnit_Val Rte_Read_BmwMsgSlot51Bas0Repn2BusFrChA_BmwSeldPosnUnit_Val
#  define Rte_Read_BmwMsgSlot51Bas0Repn2BusFrChA_BmwSeldPosnUnit_Val(data) (*(data) = Rte_BmwMsgSlot51Bas0Repn2BusFrChA_BmwSeldPosnUnit_Val, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BmwTarMotTq_Val Rte_Read_BmwMsgSlot51Bas0Repn2BusFrChA_BmwTarMotTq_Val
#  define Rte_Read_BmwMsgSlot51Bas0Repn2BusFrChA_BmwTarMotTq_Val(data) (*(data) = Rte_HwTqTrakgCtrl_MotTqCmdTrakgCtrl_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BmwTarMotTqVld_Logl Rte_Read_BmwMsgSlot51Bas0Repn2BusFrChA_BmwTarMotTqVld_Logl
#  define Rte_Read_BmwMsgSlot51Bas0Repn2BusFrChA_BmwTarMotTqVld_Logl(data) (*(data) = Rte_BmwMsgSlot51Bas0Repn2BusFrChA_BmwTarMotTqVld_Logl, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BmwTqSnsrIdx_Val Rte_Read_BmwMsgSlot51Bas0Repn2BusFrChA_BmwTqSnsrIdx_Val
#  define Rte_Read_BmwMsgSlot51Bas0Repn2BusFrChA_BmwTqSnsrIdx_Val(data) (*(data) = Rte_BmwMsgSlot51Bas0Repn2BusFrChA_BmwTqSnsrIdx_Val, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_TRGG_ENGTORQ_EPS_Val Rte_Write_BmwMsgSlot51Bas0Repn2BusFrChA_TRGG_ENGTORQ_EPS_Val
#  define Rte_Write_sigGroup_AVL_PO_EPS_sigGroup_AVL_PO_EPS Rte_Write_BmwMsgSlot51Bas0Repn2BusFrChA_sigGroup_AVL_PO_EPS_sigGroup_AVL_PO_EPS


/**********************************************************************************************************************
 * Rte_Invalidate_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Invalidate_sigGroup_AVL_PO_EPS_sigGroup_AVL_PO_EPS Rte_Invalidate_BmwMsgSlot51Bas0Repn2BusFrChA_sigGroup_AVL_PO_EPS_sigGroup_AVL_PO_EPS


/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

#  define Rte_Prm_BmwSteerPolarity_Val() (-1) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# endif /* !defined(RTE_CORE) */


# define BmwMsgSlot51Bas0Repn2BusFrChA_START_SEC_CODE
# include "BmwMsgSlot51Bas0Repn2BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_BmwMsgSlot51Bas0Repn2BusFrChAInit1 BmwMsgSlot51Bas0Repn2BusFrChAInit1
#  define RTE_RUNNABLE_BmwMsgSlot51Bas0Repn2BusFrChAPer1 BmwMsgSlot51Bas0Repn2BusFrChAPer1
# endif

FUNC(void, BmwMsgSlot51Bas0Repn2BusFrChA_CODE) BmwMsgSlot51Bas0Repn2BusFrChAInit1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, BmwMsgSlot51Bas0Repn2BusFrChA_CODE) BmwMsgSlot51Bas0Repn2BusFrChAPer1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define BmwMsgSlot51Bas0Repn2BusFrChA_STOP_SEC_CODE
# include "BmwMsgSlot51Bas0Repn2BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_BMWMSGSLOT51BAS0REPN2BUSFRCHA_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
