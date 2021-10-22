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
 *        Config:  C:/_PratikJadhav/_Synergy_Projects/Working/MM522A_BmwMsgSlot49Bas1Repn2BusFrChA_Impl/tools/Component.dpa
 *     SW-C Type:  BmwMsgSlot49Bas1Repn2BusFrChA
 *  Generated at:  Mon May  7 10:19:48 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <BmwMsgSlot49Bas1Repn2BusFrChA> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_BMWMSGSLOT49BAS1REPN2BUSFRCHA_H
# define _RTE_BMWMSGSLOT49BAS1REPN2BUSFRCHA_H

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

# include "Rte_BmwMsgSlot49Bas1Repn2BusFrChA_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_BmwMsgSlot49Bas1Repn2BusFrChA
{
  /* dummy entry */
  uint8 _dummy;
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_BmwMsgSlot49Bas1Repn2BusFrChA, RTE_CONST, RTE_CONST) Rte_Inst_BmwMsgSlot49Bas1Repn2BusFrChA; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_BmwMsgSlot49Bas1Repn2BusFrChA, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_BattRtnCurrAmpr_Val (0.0F)
# define Rte_InitValue_BattRtnCurrAmprQlfr_Val (15U)
# define Rte_InitValue_EpsCurrLimSts_Val (15U)


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwMsgSlot49Bas1Repn2BusFrChA_BattRtnCurrAmpr_Val(P2VAR(float32, AUTOMATIC, RTE_BMWMSGSLOT49BAS1REPN2BUSFRCHA_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwMsgSlot49Bas1Repn2BusFrChA_BattRtnCurrAmprQlfr_Val(P2VAR(BattRtnCurrAmprQlfr1, AUTOMATIC, RTE_BMWMSGSLOT49BAS1REPN2BUSFRCHA_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwMsgSlot49Bas1Repn2BusFrChA_EpsCurrLimSts_Val(P2VAR(EpsCurrLimSts1, AUTOMATIC, RTE_BMWMSGSLOT49BAS1REPN2BUSFRCHA_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot49Bas1Repn2BusFrChA_sigGroup_DT_EST_sigGroup_DT_EST(P2CONST(sigGroup_DT_EST1, AUTOMATIC, RTE_BMWMSGSLOT49BAS1REPN2BUSFRCHA_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_BattRtnCurrAmpr_Val Rte_Read_BmwMsgSlot49Bas1Repn2BusFrChA_BattRtnCurrAmpr_Val
# define Rte_Read_BattRtnCurrAmprQlfr_Val Rte_Read_BmwMsgSlot49Bas1Repn2BusFrChA_BattRtnCurrAmprQlfr_Val
# define Rte_Read_EpsCurrLimSts_Val Rte_Read_BmwMsgSlot49Bas1Repn2BusFrChA_EpsCurrLimSts_Val


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_sigGroup_DT_EST_sigGroup_DT_EST Rte_Write_BmwMsgSlot49Bas1Repn2BusFrChA_sigGroup_DT_EST_sigGroup_DT_EST




# define BmwMsgSlot49Bas1Repn2BusFrChA_START_SEC_CODE
# include "BmwMsgSlot49Bas1Repn2BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwMsgSlot49Bas1Repn2BusFrChAInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_BmwMsgSlot49Bas1Repn2BusFrChAInit1 BmwMsgSlot49Bas1Repn2BusFrChAInit1
FUNC(void, BmwMsgSlot49Bas1Repn2BusFrChA_CODE) BmwMsgSlot49Bas1Repn2BusFrChAInit1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwMsgSlot49Bas1Repn2BusFrChAPer1
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
 *   Std_ReturnType Rte_Read_BattRtnCurrAmpr_Val(float32 *data)
 *   Std_ReturnType Rte_Read_BattRtnCurrAmprQlfr_Val(BattRtnCurrAmprQlfr1 *data)
 *   Std_ReturnType Rte_Read_EpsCurrLimSts_Val(EpsCurrLimSts1 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_sigGroup_DT_EST_sigGroup_DT_EST(const sigGroup_DT_EST1 *data)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_BmwMsgSlot49Bas1Repn2BusFrChAPer1 BmwMsgSlot49Bas1Repn2BusFrChAPer1
FUNC(void, BmwMsgSlot49Bas1Repn2BusFrChA_CODE) BmwMsgSlot49Bas1Repn2BusFrChAPer1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define BmwMsgSlot49Bas1Repn2BusFrChA_STOP_SEC_CODE
# include "BmwMsgSlot49Bas1Repn2BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_BMWMSGSLOT49BAS1REPN2BUSFRCHA_H */
