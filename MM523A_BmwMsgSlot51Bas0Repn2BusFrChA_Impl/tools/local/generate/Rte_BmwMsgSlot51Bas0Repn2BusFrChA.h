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
 *        Config:  C:/_Synergy_Projects/Working/MM523A_BmwMsgSlot51Bas0Repn2BusFrChA_Impl/tools/Component.dpa
 *     SW-C Type:  BmwMsgSlot51Bas0Repn2BusFrChA
 *  Generated at:  Tue Mar 27 17:52:25 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <BmwMsgSlot51Bas0Repn2BusFrChA> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_BMWMSGSLOT51BAS0REPN2BUSFRCHA_H
# define _RTE_BMWMSGSLOT51BAS0REPN2BUSFRCHA_H

# ifdef RTE_APPLICATION_HEADER_FILE
#  error Multiple application header files included.
# endif
# define RTE_APPLICATION_HEADER_FILE
# ifndef RTE_PTR2ARRAYBASETYPE_PASSING
#  define RTE_PTR2ARRAYBASETYPE_PASSING
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_BmwMsgSlot51Bas0Repn2BusFrChA_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_BmwMsgSlot51Bas0Repn2BusFrChA
{
  /* dummy entry */
  uint8 _dummy;
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_BmwMsgSlot51Bas0Repn2BusFrChA, RTE_CONST, RTE_CONST) Rte_Inst_BmwMsgSlot51Bas0Repn2BusFrChA; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_BmwMsgSlot51Bas0Repn2BusFrChA, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_BmwPinionAg_Val (0.0F)
# define Rte_InitValue_BmwPinionAgIdx_Val (0.0F)
# define Rte_InitValue_BmwPinionAgIdxVld_Logl (FALSE)
# define Rte_InitValue_BmwPinionAgQlfr_Val (14U)
# define Rte_InitValue_BmwRackCntrToVehCntrOffs_Val (0.0F)
# define Rte_InitValue_BmwRackCntrToVehCntrOffsVld_Logl (FALSE)
# define Rte_InitValue_BmwSeldPosnUnit_Val (0U)
# define Rte_InitValue_BmwTarMotTq_Val (0.0F)
# define Rte_InitValue_BmwTarMotTqVld_Logl (FALSE)
# define Rte_InitValue_BmwTqSnsrIdx_Val (3U)
# define Rte_InitValue_TRGG_ENGTORQ_EPS_Val (4095U)


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwMsgSlot51Bas0Repn2BusFrChA_BmwPinionAg_Val(P2VAR(float32, AUTOMATIC, RTE_BMWMSGSLOT51BAS0REPN2BUSFRCHA_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwMsgSlot51Bas0Repn2BusFrChA_BmwPinionAgIdx_Val(P2VAR(float32, AUTOMATIC, RTE_BMWMSGSLOT51BAS0REPN2BUSFRCHA_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwMsgSlot51Bas0Repn2BusFrChA_BmwPinionAgIdxVld_Logl(P2VAR(boolean, AUTOMATIC, RTE_BMWMSGSLOT51BAS0REPN2BUSFRCHA_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwMsgSlot51Bas0Repn2BusFrChA_BmwPinionAgQlfr_Val(P2VAR(BmwPinionAgQlfr1, AUTOMATIC, RTE_BMWMSGSLOT51BAS0REPN2BUSFRCHA_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwMsgSlot51Bas0Repn2BusFrChA_BmwRackCntrToVehCntrOffs_Val(P2VAR(float32, AUTOMATIC, RTE_BMWMSGSLOT51BAS0REPN2BUSFRCHA_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwMsgSlot51Bas0Repn2BusFrChA_BmwRackCntrToVehCntrOffsVld_Logl(P2VAR(boolean, AUTOMATIC, RTE_BMWMSGSLOT51BAS0REPN2BUSFRCHA_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwMsgSlot51Bas0Repn2BusFrChA_BmwSeldPosnUnit_Val(P2VAR(BmwSeldPosnUnit1, AUTOMATIC, RTE_BMWMSGSLOT51BAS0REPN2BUSFRCHA_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwMsgSlot51Bas0Repn2BusFrChA_BmwTarMotTq_Val(P2VAR(float32, AUTOMATIC, RTE_BMWMSGSLOT51BAS0REPN2BUSFRCHA_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwMsgSlot51Bas0Repn2BusFrChA_BmwTarMotTqVld_Logl(P2VAR(boolean, AUTOMATIC, RTE_BMWMSGSLOT51BAS0REPN2BUSFRCHA_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwMsgSlot51Bas0Repn2BusFrChA_BmwTqSnsrIdx_Val(P2VAR(BmwTqSnsrIdx1, AUTOMATIC, RTE_BMWMSGSLOT51BAS0REPN2BUSFRCHA_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot51Bas0Repn2BusFrChA_TRGG_ENGTORQ_EPS_Val(uint16 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot51Bas0Repn2BusFrChA_sigGroup_AVL_PO_EPS_sigGroup_AVL_PO_EPS(P2CONST(sigGroup_AVL_PO_EPS1, AUTOMATIC, RTE_BMWMSGSLOT51BAS0REPN2BUSFRCHA_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Invalidate_BmwMsgSlot51Bas0Repn2BusFrChA_sigGroup_AVL_PO_EPS_sigGroup_AVL_PO_EPS(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(sint8, RTE_CODE) Rte_Prm_BmwMsgSlot51Bas0Repn2BusFrChA_BmwSteerPolarity_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_BmwPinionAg_Val Rte_Read_BmwMsgSlot51Bas0Repn2BusFrChA_BmwPinionAg_Val
# define Rte_Read_BmwPinionAgIdx_Val Rte_Read_BmwMsgSlot51Bas0Repn2BusFrChA_BmwPinionAgIdx_Val
# define Rte_Read_BmwPinionAgIdxVld_Logl Rte_Read_BmwMsgSlot51Bas0Repn2BusFrChA_BmwPinionAgIdxVld_Logl
# define Rte_Read_BmwPinionAgQlfr_Val Rte_Read_BmwMsgSlot51Bas0Repn2BusFrChA_BmwPinionAgQlfr_Val
# define Rte_Read_BmwRackCntrToVehCntrOffs_Val Rte_Read_BmwMsgSlot51Bas0Repn2BusFrChA_BmwRackCntrToVehCntrOffs_Val
# define Rte_Read_BmwRackCntrToVehCntrOffsVld_Logl Rte_Read_BmwMsgSlot51Bas0Repn2BusFrChA_BmwRackCntrToVehCntrOffsVld_Logl
# define Rte_Read_BmwSeldPosnUnit_Val Rte_Read_BmwMsgSlot51Bas0Repn2BusFrChA_BmwSeldPosnUnit_Val
# define Rte_Read_BmwTarMotTq_Val Rte_Read_BmwMsgSlot51Bas0Repn2BusFrChA_BmwTarMotTq_Val
# define Rte_Read_BmwTarMotTqVld_Logl Rte_Read_BmwMsgSlot51Bas0Repn2BusFrChA_BmwTarMotTqVld_Logl
# define Rte_Read_BmwTqSnsrIdx_Val Rte_Read_BmwMsgSlot51Bas0Repn2BusFrChA_BmwTqSnsrIdx_Val


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_TRGG_ENGTORQ_EPS_Val Rte_Write_BmwMsgSlot51Bas0Repn2BusFrChA_TRGG_ENGTORQ_EPS_Val
# define Rte_Write_sigGroup_AVL_PO_EPS_sigGroup_AVL_PO_EPS Rte_Write_BmwMsgSlot51Bas0Repn2BusFrChA_sigGroup_AVL_PO_EPS_sigGroup_AVL_PO_EPS


/**********************************************************************************************************************
 * Rte_Invalidate_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Invalidate_sigGroup_AVL_PO_EPS_sigGroup_AVL_PO_EPS Rte_Invalidate_BmwMsgSlot51Bas0Repn2BusFrChA_sigGroup_AVL_PO_EPS_sigGroup_AVL_PO_EPS


/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

# define Rte_Prm_BmwSteerPolarity_Val Rte_Prm_BmwMsgSlot51Bas0Repn2BusFrChA_BmwSteerPolarity_Val



/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   sint8 Rte_Prm_BmwSteerPolarity_Val(void)
 *
 *********************************************************************************************************************/


# define BmwMsgSlot51Bas0Repn2BusFrChA_START_SEC_CODE
# include "BmwMsgSlot51Bas0Repn2BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwMsgSlot51Bas0Repn2BusFrChAInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_BmwMsgSlot51Bas0Repn2BusFrChAInit1 BmwMsgSlot51Bas0Repn2BusFrChAInit1
FUNC(void, BmwMsgSlot51Bas0Repn2BusFrChA_CODE) BmwMsgSlot51Bas0Repn2BusFrChAInit1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwMsgSlot51Bas0Repn2BusFrChAPer1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_BmwPinionAg_Val(float32 *data)
 *   Std_ReturnType Rte_Read_BmwPinionAgIdx_Val(float32 *data)
 *   Std_ReturnType Rte_Read_BmwPinionAgIdxVld_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_BmwPinionAgQlfr_Val(BmwPinionAgQlfr1 *data)
 *   Std_ReturnType Rte_Read_BmwRackCntrToVehCntrOffs_Val(float32 *data)
 *   Std_ReturnType Rte_Read_BmwRackCntrToVehCntrOffsVld_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_BmwSeldPosnUnit_Val(BmwSeldPosnUnit1 *data)
 *   Std_ReturnType Rte_Read_BmwTarMotTq_Val(float32 *data)
 *   Std_ReturnType Rte_Read_BmwTarMotTqVld_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_BmwTqSnsrIdx_Val(BmwTqSnsrIdx1 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_TRGG_ENGTORQ_EPS_Val(uint16 data)
 *   Std_ReturnType Rte_Write_sigGroup_AVL_PO_EPS_sigGroup_AVL_PO_EPS(const sigGroup_AVL_PO_EPS1 *data)
 *   Std_ReturnType Rte_Invalidate_sigGroup_AVL_PO_EPS_sigGroup_AVL_PO_EPS(void)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_BmwMsgSlot51Bas0Repn2BusFrChAPer1 BmwMsgSlot51Bas0Repn2BusFrChAPer1
FUNC(void, BmwMsgSlot51Bas0Repn2BusFrChA_CODE) BmwMsgSlot51Bas0Repn2BusFrChAPer1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define BmwMsgSlot51Bas0Repn2BusFrChA_STOP_SEC_CODE
# include "BmwMsgSlot51Bas0Repn2BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_BMWMSGSLOT51BAS0REPN2BUSFRCHA_H */
