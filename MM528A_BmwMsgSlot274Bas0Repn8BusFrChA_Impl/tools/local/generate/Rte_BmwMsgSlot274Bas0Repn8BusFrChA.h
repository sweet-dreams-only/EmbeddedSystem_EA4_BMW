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
 *        Config:  C:/_Synergy_Projects/Working/ses_dev_ea4/MM528A_BmwMsgSlot274Bas0Repn8BusFrChA_Impl/tools/Component.dpa
 *     SW-C Type:  BmwMsgSlot274Bas0Repn8BusFrChA
 *  Generated at:  Thu May 31 11:34:48 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <BmwMsgSlot274Bas0Repn8BusFrChA> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_BMWMSGSLOT274BAS0REPN8BUSFRCHA_H
# define _RTE_BMWMSGSLOT274BAS0REPN8BUSFRCHA_H

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

# include "Rte_BmwMsgSlot274Bas0Repn8BusFrChA_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_BmwMsgSlot274Bas0Repn8BusFrChA
{
  /* PIM Handles section */
  P2VAR(sigGroup_SU_EPS1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_SigGroupSuEps; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_SuEpsBurstCntr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_SuEpsDebCntr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint16, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_SuEpsPerCntr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_BmwMsgSlot274Bas0Repn8BusFrChA, RTE_CONST, RTE_CONST) Rte_Inst_BmwMsgSlot274Bas0Repn8BusFrChA; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_BmwMsgSlot274Bas0Repn8BusFrChA, TYPEDEF, RTE_CONST) Rte_Instance;


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot274Bas0Repn8BusFrChA_sigGroup_SU_EPS_sigGroup_SU_EPS(P2CONST(sigGroup_SU_EPS1, AUTOMATIC, RTE_BMWMSGSLOT274BAS0REPN8BUSFRCHA_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_sigGroup_SU_EPS_sigGroup_SU_EPS Rte_Write_BmwMsgSlot274Bas0Repn8BusFrChA_sigGroup_SU_EPS_sigGroup_SU_EPS


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_SuEpsPerCntr() (Rte_Inst_BmwMsgSlot274Bas0Repn8BusFrChA->Pim_SuEpsPerCntr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_SuEpsBurstCntr() (Rte_Inst_BmwMsgSlot274Bas0Repn8BusFrChA->Pim_SuEpsBurstCntr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_SuEpsDebCntr() (Rte_Inst_BmwMsgSlot274Bas0Repn8BusFrChA->Pim_SuEpsDebCntr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_SigGroupSuEps() (Rte_Inst_BmwMsgSlot274Bas0Repn8BusFrChA->Pim_SigGroupSuEps) /* PRQA S 3453 */ /* MD_MSR_19.7 */




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   uint16 *Rte_Pim_SuEpsPerCntr(void)
 *   uint8 *Rte_Pim_SuEpsBurstCntr(void)
 *   uint8 *Rte_Pim_SuEpsDebCntr(void)
 *   sigGroup_SU_EPS1 *Rte_Pim_SigGroupSuEps(void)
 *
 *********************************************************************************************************************/


# define BmwMsgSlot274Bas0Repn8BusFrChA_START_SEC_CODE
# include "BmwMsgSlot274Bas0Repn8BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwMsgSlot274Bas0Repn8BusFrChAInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_BmwMsgSlot274Bas0Repn8BusFrChAInit1 BmwMsgSlot274Bas0Repn8BusFrChAInit1
FUNC(void, BmwMsgSlot274Bas0Repn8BusFrChA_CODE) BmwMsgSlot274Bas0Repn8BusFrChAInit1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwMsgSlot274Bas0Repn8BusFrChAPer1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_sigGroup_SU_EPS_sigGroup_SU_EPS(const sigGroup_SU_EPS1 *data)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_BmwMsgSlot274Bas0Repn8BusFrChAPer1 BmwMsgSlot274Bas0Repn8BusFrChAPer1
FUNC(void, BmwMsgSlot274Bas0Repn8BusFrChA_CODE) BmwMsgSlot274Bas0Repn8BusFrChAPer1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CfgMsgTxReq_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <CfgMsgTxReq>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void CfgMsgTxReq_Oper(void)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_CfgMsgTxReq_Oper CfgMsgTxReq_Oper
FUNC(void, BmwMsgSlot274Bas0Repn8BusFrChA_CODE) CfgMsgTxReq_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define BmwMsgSlot274Bas0Repn8BusFrChA_STOP_SEC_CODE
# include "BmwMsgSlot274Bas0Repn8BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_BMWMSGSLOT274BAS0REPN8BUSFRCHA_H */
