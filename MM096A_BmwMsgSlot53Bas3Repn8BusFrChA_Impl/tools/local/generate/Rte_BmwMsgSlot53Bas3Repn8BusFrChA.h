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
 *          File:  Rte_BmwMsgSlot53Bas3Repn8BusFrChA.h
 *        Config:  C:/_PratikJadhav/_Synergy_Projects/Working/MM096A_BmwMsgSlot53Bas3Repn8BusFrChA_Impl/tools/Component.dpa
 *     SW-C Type:  BmwMsgSlot53Bas3Repn8BusFrChA
 *  Generated at:  Tue May 29 21:44:00 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <BmwMsgSlot53Bas3Repn8BusFrChA> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_BMWMSGSLOT53BAS3REPN8BUSFRCHA_H
# define _RTE_BMWMSGSLOT53BAS3REPN8BUSFRCHA_H

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

# include "Rte_BmwMsgSlot53Bas3Repn8BusFrChA_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_BmwMsgSlot53Bas3Repn8BusFrChA
{
  /* PIM Handles section */
  P2VAR(BmwRtIdx1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwRtIdxPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwSteerMdfnFacPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(BmwSteerMdfnFacSts1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwSteerMdfnFacStsPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_FactMoSteSoDxpVldFaild; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_FactMoSteSoDxpVldPassd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MissMsgFaild; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MissMsgPassd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_SuCluStmomSfeDxpVldFaild; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_SuCluStmomSfeDxpVldPassd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_BmwMsgSlot53Bas3Repn8BusFrChA, RTE_CONST, RTE_CONST) Rte_Inst_BmwMsgSlot53Bas3Repn8BusFrChA; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_BmwMsgSlot53Bas3Repn8BusFrChA, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_BmwRtIdx_Val (15U)
# define Rte_InitValue_BmwRtIdxVld_Logl (FALSE)
# define Rte_InitValue_BmwSteerMdfnFac_Val (0.0F)
# define Rte_InitValue_BmwSteerMdfnFacSts_Val (4U)
# define Rte_InitValue_FACT_MO_STE_SO_DXP_FACT_MO_STE_SO_DXP (255U)
# define Rte_InitValue_FltCodEnad_Logl (TRUE)
# define Rte_InitValue_SU_CLU_STMOM_SFE_DXP_SU_CLU_STMOM_SFE_DXP (15U)


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwMsgSlot53Bas3Repn8BusFrChA_FACT_MO_STE_SO_DXP_FACT_MO_STE_SO_DXP(P2VAR(FACT_MO_STE_SO_DXP1, AUTOMATIC, RTE_BMWMSGSLOT53BAS3REPN8BUSFRCHA_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwMsgSlot53Bas3Repn8BusFrChA_FltCodEnad_Logl(P2VAR(boolean, AUTOMATIC, RTE_BMWMSGSLOT53BAS3REPN8BUSFRCHA_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwMsgSlot53Bas3Repn8BusFrChA_SU_CLU_STMOM_SFE_DXP_SU_CLU_STMOM_SFE_DXP(P2VAR(SU_CLU_STMOM_SFE_DXP1, AUTOMATIC, RTE_BMWMSGSLOT53BAS3REPN8BUSFRCHA_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(boolean, RTE_CODE) Rte_IsUpdated_BmwMsgSlot53Bas3Repn8BusFrChA_FACT_MO_STE_SO_DXP_FACT_MO_STE_SO_DXP(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot53Bas3Repn8BusFrChA_BmwRtIdx_Val(BmwRtIdx1 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot53Bas3Repn8BusFrChA_BmwRtIdxVld_Logl(boolean data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot53Bas3Repn8BusFrChA_BmwSteerMdfnFac_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot53Bas3Repn8BusFrChA_BmwSteerMdfnFacSts_Val(BmwSteerMdfnFacSts1 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwMsgSlot53Bas3Repn8BusFrChA_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_FACT_MO_STE_SO_DXP_FACT_MO_STE_SO_DXP Rte_Read_BmwMsgSlot53Bas3Repn8BusFrChA_FACT_MO_STE_SO_DXP_FACT_MO_STE_SO_DXP
# define Rte_Read_FltCodEnad_Logl Rte_Read_BmwMsgSlot53Bas3Repn8BusFrChA_FltCodEnad_Logl
# define Rte_Read_SU_CLU_STMOM_SFE_DXP_SU_CLU_STMOM_SFE_DXP Rte_Read_BmwMsgSlot53Bas3Repn8BusFrChA_SU_CLU_STMOM_SFE_DXP_SU_CLU_STMOM_SFE_DXP


/**********************************************************************************************************************
 * Rte_IsUpdated_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_IsUpdated_FACT_MO_STE_SO_DXP_FACT_MO_STE_SO_DXP Rte_IsUpdated_BmwMsgSlot53Bas3Repn8BusFrChA_FACT_MO_STE_SO_DXP_FACT_MO_STE_SO_DXP


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_BmwRtIdx_Val Rte_Write_BmwMsgSlot53Bas3Repn8BusFrChA_BmwRtIdx_Val
# define Rte_Write_BmwRtIdxVld_Logl Rte_Write_BmwMsgSlot53Bas3Repn8BusFrChA_BmwRtIdxVld_Logl
# define Rte_Write_BmwSteerMdfnFac_Val Rte_Write_BmwMsgSlot53Bas3Repn8BusFrChA_BmwSteerMdfnFac_Val
# define Rte_Write_BmwSteerMdfnFacSts_Val Rte_Write_BmwMsgSlot53Bas3Repn8BusFrChA_BmwSteerMdfnFacSts_Val


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_SetNtcSts_Oper Rte_Call_BmwMsgSlot53Bas3Repn8BusFrChA_SetNtcSts_Oper


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_BmwSteerMdfnFacPrev() (Rte_Inst_BmwMsgSlot53Bas3Repn8BusFrChA->Pim_BmwSteerMdfnFacPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_BmwRtIdxPrev() (Rte_Inst_BmwMsgSlot53Bas3Repn8BusFrChA->Pim_BmwRtIdxPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_BmwSteerMdfnFacStsPrev() (Rte_Inst_BmwMsgSlot53Bas3Repn8BusFrChA->Pim_BmwSteerMdfnFacStsPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_FactMoSteSoDxpVldFaild() (Rte_Inst_BmwMsgSlot53Bas3Repn8BusFrChA->Pim_FactMoSteSoDxpVldFaild) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_FactMoSteSoDxpVldPassd() (Rte_Inst_BmwMsgSlot53Bas3Repn8BusFrChA->Pim_FactMoSteSoDxpVldPassd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MissMsgFaild() (Rte_Inst_BmwMsgSlot53Bas3Repn8BusFrChA->Pim_MissMsgFaild) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MissMsgPassd() (Rte_Inst_BmwMsgSlot53Bas3Repn8BusFrChA->Pim_MissMsgPassd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_SuCluStmomSfeDxpVldFaild() (Rte_Inst_BmwMsgSlot53Bas3Repn8BusFrChA->Pim_SuCluStmomSfeDxpVldFaild) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_SuCluStmomSfeDxpVldPassd() (Rte_Inst_BmwMsgSlot53Bas3Repn8BusFrChA->Pim_SuCluStmomSfeDxpVldPassd) /* PRQA S 3453 */ /* MD_MSR_19.7 */




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   float32 *Rte_Pim_BmwSteerMdfnFacPrev(void)
 *   BmwRtIdx1 *Rte_Pim_BmwRtIdxPrev(void)
 *   BmwSteerMdfnFacSts1 *Rte_Pim_BmwSteerMdfnFacStsPrev(void)
 *   uint8 *Rte_Pim_FactMoSteSoDxpVldFaild(void)
 *   uint8 *Rte_Pim_FactMoSteSoDxpVldPassd(void)
 *   uint8 *Rte_Pim_MissMsgFaild(void)
 *   uint8 *Rte_Pim_MissMsgPassd(void)
 *   uint8 *Rte_Pim_SuCluStmomSfeDxpVldFaild(void)
 *   uint8 *Rte_Pim_SuCluStmomSfeDxpVldPassd(void)
 *
 *********************************************************************************************************************/


# define BmwMsgSlot53Bas3Repn8BusFrChA_START_SEC_CODE
# include "BmwMsgSlot53Bas3Repn8BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwMsgSlot53Bas3Repn8BusFrChAInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_FACT_MO_STE_SO_DXP_FACT_MO_STE_SO_DXP(FACT_MO_STE_SO_DXP1 *data)
 *   Std_ReturnType Rte_Read_FltCodEnad_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_SU_CLU_STMOM_SFE_DXP_SU_CLU_STMOM_SFE_DXP(SU_CLU_STMOM_SFE_DXP1 *data)
 *   boolean Rte_IsUpdated_FACT_MO_STE_SO_DXP_FACT_MO_STE_SO_DXP(void)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_BmwRtIdx_Val(BmwRtIdx1 data)
 *   Std_ReturnType Rte_Write_BmwRtIdxVld_Logl(boolean data)
 *   Std_ReturnType Rte_Write_BmwSteerMdfnFac_Val(float32 data)
 *   Std_ReturnType Rte_Write_BmwSteerMdfnFacSts_Val(BmwSteerMdfnFacSts1 data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetNtcSts_PortIf1_E_NOT_OK
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_BmwMsgSlot53Bas3Repn8BusFrChAInit1 BmwMsgSlot53Bas3Repn8BusFrChAInit1
FUNC(void, BmwMsgSlot53Bas3Repn8BusFrChA_CODE) BmwMsgSlot53Bas3Repn8BusFrChAInit1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SU_CLE_DRDY_DXP_Miss
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceiveErrorEvent for DataElementPrototype <FACT_MO_STE_SO_DXP> of PortPrototype <FACT_MO_STE_SO_DXP>
 *   - triggered on DataReceiveErrorEvent for DataElementPrototype <SU_CLU_STMOM_SFE_DXP> of PortPrototype <SU_CLU_STMOM_SFE_DXP>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_FltCodEnad_Logl(boolean *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_BmwRtIdx_Val(BmwRtIdx1 data)
 *   Std_ReturnType Rte_Write_BmwRtIdxVld_Logl(boolean data)
 *   Std_ReturnType Rte_Write_BmwSteerMdfnFac_Val(float32 data)
 *   Std_ReturnType Rte_Write_BmwSteerMdfnFacSts_Val(BmwSteerMdfnFacSts1 data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetNtcSts_PortIf1_E_NOT_OK
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_SU_CLE_DRDY_DXP_Miss SU_CLE_DRDY_DXP_Miss
FUNC(void, BmwMsgSlot53Bas3Repn8BusFrChA_CODE) SU_CLE_DRDY_DXP_Miss(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SU_CLE_DRDY_DXP_Rxd
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <FACT_MO_STE_SO_DXP> of PortPrototype <FACT_MO_STE_SO_DXP>
 *   - triggered on DataReceivedEvent for DataElementPrototype <SU_CLU_STMOM_SFE_DXP> of PortPrototype <SU_CLU_STMOM_SFE_DXP>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_FACT_MO_STE_SO_DXP_FACT_MO_STE_SO_DXP(FACT_MO_STE_SO_DXP1 *data)
 *   Std_ReturnType Rte_Read_FltCodEnad_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_SU_CLU_STMOM_SFE_DXP_SU_CLU_STMOM_SFE_DXP(SU_CLU_STMOM_SFE_DXP1 *data)
 *   boolean Rte_IsUpdated_FACT_MO_STE_SO_DXP_FACT_MO_STE_SO_DXP(void)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_BmwRtIdx_Val(BmwRtIdx1 data)
 *   Std_ReturnType Rte_Write_BmwRtIdxVld_Logl(boolean data)
 *   Std_ReturnType Rte_Write_BmwSteerMdfnFac_Val(float32 data)
 *   Std_ReturnType Rte_Write_BmwSteerMdfnFacSts_Val(BmwSteerMdfnFacSts1 data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetNtcSts_PortIf1_E_NOT_OK
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_SU_CLE_DRDY_DXP_Rxd SU_CLE_DRDY_DXP_Rxd
FUNC(void, BmwMsgSlot53Bas3Repn8BusFrChA_CODE) SU_CLE_DRDY_DXP_Rxd(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define BmwMsgSlot53Bas3Repn8BusFrChA_STOP_SEC_CODE
# include "BmwMsgSlot53Bas3Repn8BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_SetNtcSts_PortIf1_E_NOT_OK (1U)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_BMWMSGSLOT53BAS3REPN8BUSFRCHA_H */
