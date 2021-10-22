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
 *          File:  Rte_BmwMsgSlot121Bas1Repn2BusFrChA.h
 *        Config:  C:/Component/MM109A_BmwMsgSlot121Bas1Repn2BusFrChA_Impl/tools/Component.dpa
 *     SW-C Type:  BmwMsgSlot121Bas1Repn2BusFrChA
 *  Generated at:  Sat Nov  4 14:51:38 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <BmwMsgSlot121Bas1Repn2BusFrChA> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_BMWMSGSLOT121BAS1REPN2BUSFRCHA_H
# define _RTE_BMWMSGSLOT121BAS1REPN2BUSFRCHA_H

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

# include "Rte_BmwMsgSlot121Bas1Repn2BusFrChA_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_BmwMsgSlot121Bas1Repn2BusFrChA
{
  /* PIM Handles section */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_AlvFaildCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_AlvPassdCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(BmwBasPtlNetCtrl1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwBasPtlNetCtrlPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(BmwVehCdn1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwVehCdnPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(BmwVehCdnQlfr1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwVehCdnQlfrPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_CrcFaildCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_CrcPassdCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_CtrBsPrtntFaildCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_CtrBsPrtntPassdCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_CtrFktnPrtntFaildCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_CtrFktnPrtntPassdCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(QU_ST_CON_VEH1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_Dummy_PIM1; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(QU_V_VEH_COG1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_Dummy_PIM2; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(ST_CON_VEH1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_Dummy_PIM3; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(CTR_BS_PRTNT1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_Dummy_PIM4; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MissMsgCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_QlfrCogFaildCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_QlfrCogPassdCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_QuStConVehFaildCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_QuStConVehPassdCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_RxdMsgCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_StConVehFaildCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_StConVehPassdCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_BmwMsgSlot121Bas1Repn2BusFrChA, RTE_CONST, RTE_CONST) Rte_Inst_BmwMsgSlot121Bas1Repn2BusFrChA; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_BmwMsgSlot121Bas1Repn2BusFrChA, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_BmwBasPtlNetCtrl_Val (15U)
# define Rte_InitValue_BmwBasPtlNetCtrlVld_Logl (FALSE)
# define Rte_InitValue_BmwVehCdn_Val (15U)
# define Rte_InitValue_BmwVehCdnQlfr_Val (15U)
# define Rte_InitValue_BmwVehCdnQlfrVld_Logl (FALSE)
# define Rte_InitValue_BmwVehCdnVld_Logl (FALSE)
# define Rte_InitValue_FltCodEnad_Logl (TRUE)


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwMsgSlot121Bas1Repn2BusFrChA_FltCodEnad_Logl(P2VAR(boolean, AUTOMATIC, RTE_BMWMSGSLOT121BAS1REPN2BUSFRCHA_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwMsgSlot121Bas1Repn2BusFrChA_sigGroup_CON_VEH_sigGroup_CON_VEH(P2VAR(sigGroup_CON_VEH1, AUTOMATIC, RTE_BMWMSGSLOT121BAS1REPN2BUSFRCHA_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(boolean, RTE_CODE) Rte_IsUpdated_BmwMsgSlot121Bas1Repn2BusFrChA_sigGroup_CON_VEH_sigGroup_CON_VEH(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot121Bas1Repn2BusFrChA_BmwBasPtlNetCtrl_Val(BmwBasPtlNetCtrl1 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot121Bas1Repn2BusFrChA_BmwBasPtlNetCtrlVld_Logl(boolean data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot121Bas1Repn2BusFrChA_BmwVehCdn_Val(BmwVehCdn1 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot121Bas1Repn2BusFrChA_BmwVehCdnQlfr_Val(BmwVehCdnQlfr1 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot121Bas1Repn2BusFrChA_BmwVehCdnQlfrVld_Logl(boolean data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot121Bas1Repn2BusFrChA_BmwVehCdnVld_Logl(boolean data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwMsgSlot121Bas1Repn2BusFrChA_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_FltCodEnad_Logl Rte_Read_BmwMsgSlot121Bas1Repn2BusFrChA_FltCodEnad_Logl
# define Rte_Read_sigGroup_CON_VEH_sigGroup_CON_VEH Rte_Read_BmwMsgSlot121Bas1Repn2BusFrChA_sigGroup_CON_VEH_sigGroup_CON_VEH


/**********************************************************************************************************************
 * Rte_IsUpdated_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_IsUpdated_sigGroup_CON_VEH_sigGroup_CON_VEH Rte_IsUpdated_BmwMsgSlot121Bas1Repn2BusFrChA_sigGroup_CON_VEH_sigGroup_CON_VEH


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_BmwBasPtlNetCtrl_Val Rte_Write_BmwMsgSlot121Bas1Repn2BusFrChA_BmwBasPtlNetCtrl_Val
# define Rte_Write_BmwBasPtlNetCtrlVld_Logl Rte_Write_BmwMsgSlot121Bas1Repn2BusFrChA_BmwBasPtlNetCtrlVld_Logl
# define Rte_Write_BmwVehCdn_Val Rte_Write_BmwMsgSlot121Bas1Repn2BusFrChA_BmwVehCdn_Val
# define Rte_Write_BmwVehCdnQlfr_Val Rte_Write_BmwMsgSlot121Bas1Repn2BusFrChA_BmwVehCdnQlfr_Val
# define Rte_Write_BmwVehCdnQlfrVld_Logl Rte_Write_BmwMsgSlot121Bas1Repn2BusFrChA_BmwVehCdnQlfrVld_Logl
# define Rte_Write_BmwVehCdnVld_Logl Rte_Write_BmwMsgSlot121Bas1Repn2BusFrChA_BmwVehCdnVld_Logl


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_SetNtcSts_Oper Rte_Call_BmwMsgSlot121Bas1Repn2BusFrChA_SetNtcSts_Oper


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_AlvFaildCnt() (Rte_Inst_BmwMsgSlot121Bas1Repn2BusFrChA->Pim_AlvFaildCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_AlvPassdCnt() (Rte_Inst_BmwMsgSlot121Bas1Repn2BusFrChA->Pim_AlvPassdCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_BmwBasPtlNetCtrlPrev() (Rte_Inst_BmwMsgSlot121Bas1Repn2BusFrChA->Pim_BmwBasPtlNetCtrlPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_BmwVehCdnPrev() (Rte_Inst_BmwMsgSlot121Bas1Repn2BusFrChA->Pim_BmwVehCdnPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_BmwVehCdnQlfrPrev() (Rte_Inst_BmwMsgSlot121Bas1Repn2BusFrChA->Pim_BmwVehCdnQlfrPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_CrcFaildCnt() (Rte_Inst_BmwMsgSlot121Bas1Repn2BusFrChA->Pim_CrcFaildCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_CrcPassdCnt() (Rte_Inst_BmwMsgSlot121Bas1Repn2BusFrChA->Pim_CrcPassdCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_CtrBsPrtntFaildCnt() (Rte_Inst_BmwMsgSlot121Bas1Repn2BusFrChA->Pim_CtrBsPrtntFaildCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_CtrBsPrtntPassdCnt() (Rte_Inst_BmwMsgSlot121Bas1Repn2BusFrChA->Pim_CtrBsPrtntPassdCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_CtrFktnPrtntFaildCnt() (Rte_Inst_BmwMsgSlot121Bas1Repn2BusFrChA->Pim_CtrFktnPrtntFaildCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_CtrFktnPrtntPassdCnt() (Rte_Inst_BmwMsgSlot121Bas1Repn2BusFrChA->Pim_CtrFktnPrtntPassdCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_Dummy_PIM1() (Rte_Inst_BmwMsgSlot121Bas1Repn2BusFrChA->Pim_Dummy_PIM1) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_Dummy_PIM2() (Rte_Inst_BmwMsgSlot121Bas1Repn2BusFrChA->Pim_Dummy_PIM2) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_Dummy_PIM3() (Rte_Inst_BmwMsgSlot121Bas1Repn2BusFrChA->Pim_Dummy_PIM3) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_Dummy_PIM4() (Rte_Inst_BmwMsgSlot121Bas1Repn2BusFrChA->Pim_Dummy_PIM4) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MissMsgCnt() (Rte_Inst_BmwMsgSlot121Bas1Repn2BusFrChA->Pim_MissMsgCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_QlfrCogFaildCnt() (Rte_Inst_BmwMsgSlot121Bas1Repn2BusFrChA->Pim_QlfrCogFaildCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_QlfrCogPassdCnt() (Rte_Inst_BmwMsgSlot121Bas1Repn2BusFrChA->Pim_QlfrCogPassdCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_QuStConVehFaildCnt() (Rte_Inst_BmwMsgSlot121Bas1Repn2BusFrChA->Pim_QuStConVehFaildCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_QuStConVehPassdCnt() (Rte_Inst_BmwMsgSlot121Bas1Repn2BusFrChA->Pim_QuStConVehPassdCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_RxdMsgCnt() (Rte_Inst_BmwMsgSlot121Bas1Repn2BusFrChA->Pim_RxdMsgCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_StConVehFaildCnt() (Rte_Inst_BmwMsgSlot121Bas1Repn2BusFrChA->Pim_StConVehFaildCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_StConVehPassdCnt() (Rte_Inst_BmwMsgSlot121Bas1Repn2BusFrChA->Pim_StConVehPassdCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   uint8 *Rte_Pim_AlvFaildCnt(void)
 *   uint8 *Rte_Pim_AlvPassdCnt(void)
 *   BmwBasPtlNetCtrl1 *Rte_Pim_BmwBasPtlNetCtrlPrev(void)
 *   BmwVehCdn1 *Rte_Pim_BmwVehCdnPrev(void)
 *   BmwVehCdnQlfr1 *Rte_Pim_BmwVehCdnQlfrPrev(void)
 *   uint8 *Rte_Pim_CrcFaildCnt(void)
 *   uint8 *Rte_Pim_CrcPassdCnt(void)
 *   uint8 *Rte_Pim_CtrBsPrtntFaildCnt(void)
 *   uint8 *Rte_Pim_CtrBsPrtntPassdCnt(void)
 *   uint8 *Rte_Pim_CtrFktnPrtntFaildCnt(void)
 *   uint8 *Rte_Pim_CtrFktnPrtntPassdCnt(void)
 *   QU_ST_CON_VEH1 *Rte_Pim_Dummy_PIM1(void)
 *   QU_V_VEH_COG1 *Rte_Pim_Dummy_PIM2(void)
 *   ST_CON_VEH1 *Rte_Pim_Dummy_PIM3(void)
 *   CTR_BS_PRTNT1 *Rte_Pim_Dummy_PIM4(void)
 *   uint8 *Rte_Pim_MissMsgCnt(void)
 *   uint8 *Rte_Pim_QlfrCogFaildCnt(void)
 *   uint8 *Rte_Pim_QlfrCogPassdCnt(void)
 *   uint8 *Rte_Pim_QuStConVehFaildCnt(void)
 *   uint8 *Rte_Pim_QuStConVehPassdCnt(void)
 *   uint8 *Rte_Pim_RxdMsgCnt(void)
 *   uint8 *Rte_Pim_StConVehFaildCnt(void)
 *   uint8 *Rte_Pim_StConVehPassdCnt(void)
 *
 *********************************************************************************************************************/


# define BmwMsgSlot121Bas1Repn2BusFrChA_START_SEC_CODE
# include "BmwMsgSlot121Bas1Repn2BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwMsgSlot121Bas1Repn2BusFrChAInit1
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
 *   Std_ReturnType Rte_Read_FltCodEnad_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_sigGroup_CON_VEH_sigGroup_CON_VEH(sigGroup_CON_VEH1 *data)
 *   boolean Rte_IsUpdated_sigGroup_CON_VEH_sigGroup_CON_VEH(void)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_BmwBasPtlNetCtrl_Val(BmwBasPtlNetCtrl1 data)
 *   Std_ReturnType Rte_Write_BmwBasPtlNetCtrlVld_Logl(boolean data)
 *   Std_ReturnType Rte_Write_BmwVehCdn_Val(BmwVehCdn1 data)
 *   Std_ReturnType Rte_Write_BmwVehCdnQlfr_Val(BmwVehCdnQlfr1 data)
 *   Std_ReturnType Rte_Write_BmwVehCdnQlfrVld_Logl(boolean data)
 *   Std_ReturnType Rte_Write_BmwVehCdnVld_Logl(boolean data)
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

# define RTE_RUNNABLE_BmwMsgSlot121Bas1Repn2BusFrChAInit1 BmwMsgSlot121Bas1Repn2BusFrChAInit1
FUNC(void, BmwMsgSlot121Bas1Repn2BusFrChA_CODE) BmwMsgSlot121Bas1Repn2BusFrChAInit1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CON_VEH_Missing_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceiveErrorEvent for DataElementPrototype <sigGroup_CON_VEH> of PortPrototype <sigGroup_CON_VEH>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_FltCodEnad_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_sigGroup_CON_VEH_sigGroup_CON_VEH(sigGroup_CON_VEH1 *data)
 *   boolean Rte_IsUpdated_sigGroup_CON_VEH_sigGroup_CON_VEH(void)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_BmwBasPtlNetCtrl_Val(BmwBasPtlNetCtrl1 data)
 *   Std_ReturnType Rte_Write_BmwBasPtlNetCtrlVld_Logl(boolean data)
 *   Std_ReturnType Rte_Write_BmwVehCdn_Val(BmwVehCdn1 data)
 *   Std_ReturnType Rte_Write_BmwVehCdnQlfr_Val(BmwVehCdnQlfr1 data)
 *   Std_ReturnType Rte_Write_BmwVehCdnQlfrVld_Logl(boolean data)
 *   Std_ReturnType Rte_Write_BmwVehCdnVld_Logl(boolean data)
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

# define RTE_RUNNABLE_CON_VEH_Missing_Oper CON_VEH_Missing_Oper
FUNC(void, BmwMsgSlot121Bas1Repn2BusFrChA_CODE) CON_VEH_Missing_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CON_VEH_Received_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <sigGroup_CON_VEH> of PortPrototype <sigGroup_CON_VEH>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_FltCodEnad_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_sigGroup_CON_VEH_sigGroup_CON_VEH(sigGroup_CON_VEH1 *data)
 *   boolean Rte_IsUpdated_sigGroup_CON_VEH_sigGroup_CON_VEH(void)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_BmwBasPtlNetCtrl_Val(BmwBasPtlNetCtrl1 data)
 *   Std_ReturnType Rte_Write_BmwBasPtlNetCtrlVld_Logl(boolean data)
 *   Std_ReturnType Rte_Write_BmwVehCdn_Val(BmwVehCdn1 data)
 *   Std_ReturnType Rte_Write_BmwVehCdnQlfr_Val(BmwVehCdnQlfr1 data)
 *   Std_ReturnType Rte_Write_BmwVehCdnQlfrVld_Logl(boolean data)
 *   Std_ReturnType Rte_Write_BmwVehCdnVld_Logl(boolean data)
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

# define RTE_RUNNABLE_CON_VEH_Received_Oper CON_VEH_Received_Oper
FUNC(void, BmwMsgSlot121Bas1Repn2BusFrChA_CODE) CON_VEH_Received_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define BmwMsgSlot121Bas1Repn2BusFrChA_STOP_SEC_CODE
# include "BmwMsgSlot121Bas1Repn2BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_SetNtcSts_PortIf1_E_NOT_OK (1U)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_BMWMSGSLOT121BAS1REPN2BUSFRCHA_H */
