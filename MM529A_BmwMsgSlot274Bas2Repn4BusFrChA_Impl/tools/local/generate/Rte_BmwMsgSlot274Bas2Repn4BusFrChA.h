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
 *          File:  Rte_BmwMsgSlot274Bas2Repn4BusFrChA.h
 *        Config:  C:/_PratikJadhav/_Synergy_Projects/Working/MM529A_BmwMsgSlot274Bas2Repn4BusFrChA_Impl/tools/Component.dpa
 *     SW-C Type:  BmwMsgSlot274Bas2Repn4BusFrChA
 *  Generated at:  Thu Apr 26 18:59:15 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <BmwMsgSlot274Bas2Repn4BusFrChA> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_BMWMSGSLOT274BAS2REPN4BUSFRCHA_H
# define _RTE_BMWMSGSLOT274BAS2REPN4BUSFRCHA_H

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

# include "Rte_BmwMsgSlot274Bas2Repn4BusFrChA_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_BmwMsgSlot274Bas2Repn4BusFrChA
{
  /* PIM Handles section */
  P2VAR(BmwFltLampFlsgFrq1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwFltLampFlsgFrqPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(BmwFltLampReqSts1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwFltLampReqStsPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwFltLampReqTxTypPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(BmwFltLampReqTyp2, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwFltLampReqTypPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_LstTxCntr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_PerdCntr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_BmwMsgSlot274Bas2Repn4BusFrChA, RTE_CONST, RTE_CONST) Rte_Inst_BmwMsgSlot274Bas2Repn4BusFrChA; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_BmwMsgSlot274Bas2Repn4BusFrChA, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_BmwFltLampFlsgFrq_Val (0U)
# define Rte_InitValue_BmwFltLampReqSts_Val (0U)
# define Rte_InitValue_BmwFltLampReqTxTyp_Val (5U)
# define Rte_InitValue_BmwFltLampReqTyp_Val (0U)


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwMsgSlot274Bas2Repn4BusFrChA_BmwFltLampFlsgFrq_Val(P2VAR(BmwFltLampFlsgFrq1, AUTOMATIC, RTE_BMWMSGSLOT274BAS2REPN4BUSFRCHA_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwMsgSlot274Bas2Repn4BusFrChA_BmwFltLampReqSts_Val(P2VAR(BmwFltLampReqSts1, AUTOMATIC, RTE_BMWMSGSLOT274BAS2REPN4BUSFRCHA_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwMsgSlot274Bas2Repn4BusFrChA_BmwFltLampReqTxTyp_Val(P2VAR(uint8, AUTOMATIC, RTE_BMWMSGSLOT274BAS2REPN4BUSFRCHA_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwMsgSlot274Bas2Repn4BusFrChA_BmwFltLampReqTyp_Val(P2VAR(BmwFltLampReqTyp2, AUTOMATIC, RTE_BMWMSGSLOT274BAS2REPN4BUSFRCHA_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot274Bas2Repn4BusFrChA_sigGroup_DISP_CC_EPS_sigGroup_DISP_CC_EPS(P2CONST(sigGroup_DISP_CC_EPS1, AUTOMATIC, RTE_BMWMSGSLOT274BAS2REPN4BUSFRCHA_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Invalidate_BmwMsgSlot274Bas2Repn4BusFrChA_sigGroup_DISP_CC_EPS_sigGroup_DISP_CC_EPS(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_BmwFltLampFlsgFrq_Val Rte_Read_BmwMsgSlot274Bas2Repn4BusFrChA_BmwFltLampFlsgFrq_Val
# define Rte_Read_BmwFltLampReqSts_Val Rte_Read_BmwMsgSlot274Bas2Repn4BusFrChA_BmwFltLampReqSts_Val
# define Rte_Read_BmwFltLampReqTxTyp_Val Rte_Read_BmwMsgSlot274Bas2Repn4BusFrChA_BmwFltLampReqTxTyp_Val
# define Rte_Read_BmwFltLampReqTyp_Val Rte_Read_BmwMsgSlot274Bas2Repn4BusFrChA_BmwFltLampReqTyp_Val


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_sigGroup_DISP_CC_EPS_sigGroup_DISP_CC_EPS Rte_Write_BmwMsgSlot274Bas2Repn4BusFrChA_sigGroup_DISP_CC_EPS_sigGroup_DISP_CC_EPS


/**********************************************************************************************************************
 * Rte_Invalidate_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Invalidate_sigGroup_DISP_CC_EPS_sigGroup_DISP_CC_EPS Rte_Invalidate_BmwMsgSlot274Bas2Repn4BusFrChA_sigGroup_DISP_CC_EPS_sigGroup_DISP_CC_EPS


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_BmwFltLampReqTypPrev() (Rte_Inst_BmwMsgSlot274Bas2Repn4BusFrChA->Pim_BmwFltLampReqTypPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_BmwFltLampFlsgFrqPrev() (Rte_Inst_BmwMsgSlot274Bas2Repn4BusFrChA->Pim_BmwFltLampFlsgFrqPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_BmwFltLampReqStsPrev() (Rte_Inst_BmwMsgSlot274Bas2Repn4BusFrChA->Pim_BmwFltLampReqStsPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_BmwFltLampReqTxTypPrev() (Rte_Inst_BmwMsgSlot274Bas2Repn4BusFrChA->Pim_BmwFltLampReqTxTypPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_LstTxCntr() (Rte_Inst_BmwMsgSlot274Bas2Repn4BusFrChA->Pim_LstTxCntr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_PerdCntr() (Rte_Inst_BmwMsgSlot274Bas2Repn4BusFrChA->Pim_PerdCntr) /* PRQA S 3453 */ /* MD_MSR_19.7 */




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   BmwFltLampReqTyp2 *Rte_Pim_BmwFltLampReqTypPrev(void)
 *   BmwFltLampFlsgFrq1 *Rte_Pim_BmwFltLampFlsgFrqPrev(void)
 *   BmwFltLampReqSts1 *Rte_Pim_BmwFltLampReqStsPrev(void)
 *   uint8 *Rte_Pim_BmwFltLampReqTxTypPrev(void)
 *   uint8 *Rte_Pim_LstTxCntr(void)
 *   uint8 *Rte_Pim_PerdCntr(void)
 *
 *********************************************************************************************************************/


# define BmwMsgSlot274Bas2Repn4BusFrChA_START_SEC_CODE
# include "BmwMsgSlot274Bas2Repn4BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwMsgSlot274Bas2Repn4BusFrChAInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_BmwMsgSlot274Bas2Repn4BusFrChAInit1 BmwMsgSlot274Bas2Repn4BusFrChAInit1
FUNC(void, BmwMsgSlot274Bas2Repn4BusFrChA_CODE) BmwMsgSlot274Bas2Repn4BusFrChAInit1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwMsgSlot274Bas2Repn4BusFrChAPer1
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
 *   Std_ReturnType Rte_Read_BmwFltLampFlsgFrq_Val(BmwFltLampFlsgFrq1 *data)
 *   Std_ReturnType Rte_Read_BmwFltLampReqSts_Val(BmwFltLampReqSts1 *data)
 *   Std_ReturnType Rte_Read_BmwFltLampReqTxTyp_Val(uint8 *data)
 *   Std_ReturnType Rte_Read_BmwFltLampReqTyp_Val(BmwFltLampReqTyp2 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_sigGroup_DISP_CC_EPS_sigGroup_DISP_CC_EPS(const sigGroup_DISP_CC_EPS1 *data)
 *   Std_ReturnType Rte_Invalidate_sigGroup_DISP_CC_EPS_sigGroup_DISP_CC_EPS(void)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_BmwMsgSlot274Bas2Repn4BusFrChAPer1 BmwMsgSlot274Bas2Repn4BusFrChAPer1
FUNC(void, BmwMsgSlot274Bas2Repn4BusFrChA_CODE) BmwMsgSlot274Bas2Repn4BusFrChAPer1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define BmwMsgSlot274Bas2Repn4BusFrChA_STOP_SEC_CODE
# include "BmwMsgSlot274Bas2Repn4BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_BMWMSGSLOT274BAS2REPN4BUSFRCHA_H */
