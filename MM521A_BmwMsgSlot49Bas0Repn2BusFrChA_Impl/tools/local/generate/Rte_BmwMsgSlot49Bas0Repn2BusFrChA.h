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
 *        Config:  C:/_PratikJadhav/_Synergy_Projects/Working/MM521A_BmwMsgSlot49Bas0Repn2BusFrChA_Impl/tools/Component.dpa
 *     SW-C Type:  BmwMsgSlot49Bas0Repn2BusFrChA
 *  Generated at:  Mon May  7 09:17:37 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <BmwMsgSlot49Bas0Repn2BusFrChA> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_BMWMSGSLOT49BAS0REPN2BUSFRCHA_H
# define _RTE_BMWMSGSLOT49BAS0REPN2BUSFRCHA_H

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

# include "Rte_BmwMsgSlot49Bas0Repn2BusFrChA_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_BmwMsgSlot49Bas0Repn2BusFrChA
{
  /* PIM Handles section */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_PerCntr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_BmwMsgSlot49Bas0Repn2BusFrChA, RTE_CONST, RTE_CONST) Rte_Inst_BmwMsgSlot49Bas0Repn2BusFrChA; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_BmwMsgSlot49Bas0Repn2BusFrChA, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_ElecInpPwrEstim_Val (0.0F)
# define Rte_InitValue_HwTq_Val (0.0F)
# define Rte_InitValue_HwTq4Qlfr_Val (0U)
# define Rte_InitValue_HwTq5Qlfr_Val (0U)
# define Rte_InitValue_RackFEstimd_Val (0.0F)


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwMsgSlot49Bas0Repn2BusFrChA_ElecInpPwrEstim_Val(P2VAR(float32, AUTOMATIC, RTE_BMWMSGSLOT49BAS0REPN2BUSFRCHA_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwMsgSlot49Bas0Repn2BusFrChA_HwTq_Val(P2VAR(float32, AUTOMATIC, RTE_BMWMSGSLOT49BAS0REPN2BUSFRCHA_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwMsgSlot49Bas0Repn2BusFrChA_HwTq4Qlfr_Val(P2VAR(SigQlfr1, AUTOMATIC, RTE_BMWMSGSLOT49BAS0REPN2BUSFRCHA_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwMsgSlot49Bas0Repn2BusFrChA_HwTq5Qlfr_Val(P2VAR(SigQlfr1, AUTOMATIC, RTE_BMWMSGSLOT49BAS0REPN2BUSFRCHA_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwMsgSlot49Bas0Repn2BusFrChA_RackFEstimd_Val(P2VAR(float32, AUTOMATIC, RTE_BMWMSGSLOT49BAS0REPN2BUSFRCHA_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot49Bas0Repn2BusFrChA_sigGroup_AVL_FORC_GRD_sigGroup_AVL_FORC_GRD(P2CONST(sigGroup_AVL_FORC_GRD1, AUTOMATIC, RTE_BMWMSGSLOT49BAS0REPN2BUSFRCHA_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot49Bas0Repn2BusFrChA_sigGroup_AVL_STMOM_DV_ACT_sigGroup_AVL_STMOM_DV_ACT(P2CONST(sigGroup_AVL_STMOM_DV_ACT1, AUTOMATIC, RTE_BMWMSGSLOT49BAS0REPN2BUSFRCHA_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_BmwMsgSlot49Bas0Repn2BusFrChA_BmwMsgSlot49Bas0Repn2BusFrChARackEstimnLowrLim_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_BmwMsgSlot49Bas0Repn2BusFrChA_BmwMsgSlot49Bas0Repn2BusFrChARackEstimnUpprLim_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(sint8, RTE_CODE) Rte_Prm_BmwMsgSlot49Bas0Repn2BusFrChA_BmwMsgSlot49Bas0Repn2BusFrChABmwSteerPolarity_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_ElecInpPwrEstim_Val Rte_Read_BmwMsgSlot49Bas0Repn2BusFrChA_ElecInpPwrEstim_Val
# define Rte_Read_HwTq_Val Rte_Read_BmwMsgSlot49Bas0Repn2BusFrChA_HwTq_Val
# define Rte_Read_HwTq4Qlfr_Val Rte_Read_BmwMsgSlot49Bas0Repn2BusFrChA_HwTq4Qlfr_Val
# define Rte_Read_HwTq5Qlfr_Val Rte_Read_BmwMsgSlot49Bas0Repn2BusFrChA_HwTq5Qlfr_Val
# define Rte_Read_RackFEstimd_Val Rte_Read_BmwMsgSlot49Bas0Repn2BusFrChA_RackFEstimd_Val


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_sigGroup_AVL_FORC_GRD_sigGroup_AVL_FORC_GRD Rte_Write_BmwMsgSlot49Bas0Repn2BusFrChA_sigGroup_AVL_FORC_GRD_sigGroup_AVL_FORC_GRD
# define Rte_Write_sigGroup_AVL_STMOM_DV_ACT_sigGroup_AVL_STMOM_DV_ACT Rte_Write_BmwMsgSlot49Bas0Repn2BusFrChA_sigGroup_AVL_STMOM_DV_ACT_sigGroup_AVL_STMOM_DV_ACT


/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

# define Rte_Prm_BmwMsgSlot49Bas0Repn2BusFrChARackEstimnLowrLim_Val Rte_Prm_BmwMsgSlot49Bas0Repn2BusFrChA_BmwMsgSlot49Bas0Repn2BusFrChARackEstimnLowrLim_Val

# define Rte_Prm_BmwMsgSlot49Bas0Repn2BusFrChARackEstimnUpprLim_Val Rte_Prm_BmwMsgSlot49Bas0Repn2BusFrChA_BmwMsgSlot49Bas0Repn2BusFrChARackEstimnUpprLim_Val

# define Rte_Prm_BmwMsgSlot49Bas0Repn2BusFrChABmwSteerPolarity_Val Rte_Prm_BmwMsgSlot49Bas0Repn2BusFrChA_BmwMsgSlot49Bas0Repn2BusFrChABmwSteerPolarity_Val

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_PerCntr() (Rte_Inst_BmwMsgSlot49Bas0Repn2BusFrChA->Pim_PerCntr) /* PRQA S 3453 */ /* MD_MSR_19.7 */




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   uint8 *Rte_Pim_PerCntr(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_BmwMsgSlot49Bas0Repn2BusFrChARackEstimnLowrLim_Val(void)
 *   float32 Rte_Prm_BmwMsgSlot49Bas0Repn2BusFrChARackEstimnUpprLim_Val(void)
 *   sint8 Rte_Prm_BmwMsgSlot49Bas0Repn2BusFrChABmwSteerPolarity_Val(void)
 *
 *********************************************************************************************************************/


# define BmwMsgSlot49Bas0Repn2BusFrChA_START_SEC_CODE
# include "BmwMsgSlot49Bas0Repn2BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwMsgSlot49Bas0Repn2BusFrChAInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_BmwMsgSlot49Bas0Repn2BusFrChAInit1 BmwMsgSlot49Bas0Repn2BusFrChAInit1
FUNC(void, BmwMsgSlot49Bas0Repn2BusFrChA_CODE) BmwMsgSlot49Bas0Repn2BusFrChAInit1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwMsgSlot49Bas0Repn2BusFrChAPer1
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
 *   Std_ReturnType Rte_Read_ElecInpPwrEstim_Val(float32 *data)
 *   Std_ReturnType Rte_Read_HwTq_Val(float32 *data)
 *   Std_ReturnType Rte_Read_HwTq4Qlfr_Val(SigQlfr1 *data)
 *   Std_ReturnType Rte_Read_HwTq5Qlfr_Val(SigQlfr1 *data)
 *   Std_ReturnType Rte_Read_RackFEstimd_Val(float32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_sigGroup_AVL_FORC_GRD_sigGroup_AVL_FORC_GRD(const sigGroup_AVL_FORC_GRD1 *data)
 *   Std_ReturnType Rte_Write_sigGroup_AVL_STMOM_DV_ACT_sigGroup_AVL_STMOM_DV_ACT(const sigGroup_AVL_STMOM_DV_ACT1 *data)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_BmwMsgSlot49Bas0Repn2BusFrChAPer1 BmwMsgSlot49Bas0Repn2BusFrChAPer1
FUNC(void, BmwMsgSlot49Bas0Repn2BusFrChA_CODE) BmwMsgSlot49Bas0Repn2BusFrChAPer1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define BmwMsgSlot49Bas0Repn2BusFrChA_STOP_SEC_CODE
# include "BmwMsgSlot49Bas0Repn2BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_BMWMSGSLOT49BAS0REPN2BUSFRCHA_H */
