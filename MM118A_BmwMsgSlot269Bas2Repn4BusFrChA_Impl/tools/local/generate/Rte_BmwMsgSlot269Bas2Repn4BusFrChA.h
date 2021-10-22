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
 *          File:  Rte_BmwMsgSlot269Bas2Repn4BusFrChA.h
 *        Config:  C:/_PratikJadhav/_Synergy_Projects/Working/MM118A_BmwMsgSlot269Bas2Repn4BusFrChA_Impl/tools/Component.dpa
 *     SW-C Type:  BmwMsgSlot269Bas2Repn4BusFrChA
 *  Generated at:  Wed May 30 15:11:01 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <BmwMsgSlot269Bas2Repn4BusFrChA> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_BMWMSGSLOT269BAS2REPN4BUSFRCHA_H
# define _RTE_BMWMSGSLOT269BAS2REPN4BUSFRCHA_H

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

# include "Rte_BmwMsgSlot269Bas2Repn4BusFrChA_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_BmwMsgSlot269Bas2Repn4BusFrChA
{
  /* PIM Handles section */
  P2VAR(BmwHaptcFbDirNr1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwHaptcFbDirNrPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(BmwHaptcFbIntenNr1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwHaptcFbIntenNrPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(BmwHaptcFbPatNr1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwHaptcFbPatNrPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_CtrVibStwDispExmiSp2015MissFaild; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_CtrVibStwDispExmiSp2015MissPassd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_CtrWarnDirVibEpsVldFaild; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_CtrWarnDirVibEpsVldPassd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_CtrWarnIlvlVibEpsVldFaild; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_CtrWarnIlvlVibEpsVldPassd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_CtrWarnPtrnVibEpsVldFaild; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_CtrWarnPtrnVibEpsVldPassd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_BmwMsgSlot269Bas2Repn4BusFrChA, RTE_CONST, RTE_CONST) Rte_Inst_BmwMsgSlot269Bas2Repn4BusFrChA; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_BmwMsgSlot269Bas2Repn4BusFrChA, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_BmwHaptcFbDirNr_Val (3U)
# define Rte_InitValue_BmwHaptcFbDirNrVld_Logl (FALSE)
# define Rte_InitValue_BmwHaptcFbIntenNr_Val (15U)
# define Rte_InitValue_BmwHaptcFbIntenNrVld_Logl (FALSE)
# define Rte_InitValue_BmwHaptcFbPatNr_Val (15U)
# define Rte_InitValue_BmwHaptcFbPatNrVld_Logl (FALSE)
# define Rte_InitValue_CTR_WARN_DIR_VIB_EPS_CTR_WARN_DIR_VIB_EPS (3U)
# define Rte_InitValue_CTR_WARN_ILVL_VIB_EPS_CTR_WARN_ILVL_VIB_EPS (15U)
# define Rte_InitValue_CTR_WARN_PTRN_VIB_EPS_CTR_WARN_PTRN_VIB_EPS (15U)
# define Rte_InitValue_FltCodEnad_Logl (TRUE)


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwMsgSlot269Bas2Repn4BusFrChA_CTR_WARN_DIR_VIB_EPS_CTR_WARN_DIR_VIB_EPS(P2VAR(CTR_WARN_DIR_VIB_EPS1, AUTOMATIC, RTE_BMWMSGSLOT269BAS2REPN4BUSFRCHA_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwMsgSlot269Bas2Repn4BusFrChA_CTR_WARN_ILVL_VIB_EPS_CTR_WARN_ILVL_VIB_EPS(P2VAR(CTR_WARN_ILVL_VIB_EPS1, AUTOMATIC, RTE_BMWMSGSLOT269BAS2REPN4BUSFRCHA_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwMsgSlot269Bas2Repn4BusFrChA_CTR_WARN_PTRN_VIB_EPS_CTR_WARN_PTRN_VIB_EPS(P2VAR(CTR_WARN_PTRN_VIB_EPS1, AUTOMATIC, RTE_BMWMSGSLOT269BAS2REPN4BUSFRCHA_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwMsgSlot269Bas2Repn4BusFrChA_FltCodEnad_Logl(P2VAR(boolean, AUTOMATIC, RTE_BMWMSGSLOT269BAS2REPN4BUSFRCHA_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot269Bas2Repn4BusFrChA_BmwHaptcFbDirNr_Val(BmwHaptcFbDirNr1 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot269Bas2Repn4BusFrChA_BmwHaptcFbDirNrVld_Logl(boolean data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot269Bas2Repn4BusFrChA_BmwHaptcFbIntenNr_Val(BmwHaptcFbIntenNr1 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot269Bas2Repn4BusFrChA_BmwHaptcFbIntenNrVld_Logl(boolean data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot269Bas2Repn4BusFrChA_BmwHaptcFbPatNr_Val(BmwHaptcFbPatNr1 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMsgSlot269Bas2Repn4BusFrChA_BmwHaptcFbPatNrVld_Logl(boolean data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwMsgSlot269Bas2Repn4BusFrChA_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_CTR_WARN_DIR_VIB_EPS_CTR_WARN_DIR_VIB_EPS Rte_Read_BmwMsgSlot269Bas2Repn4BusFrChA_CTR_WARN_DIR_VIB_EPS_CTR_WARN_DIR_VIB_EPS
# define Rte_Read_CTR_WARN_ILVL_VIB_EPS_CTR_WARN_ILVL_VIB_EPS Rte_Read_BmwMsgSlot269Bas2Repn4BusFrChA_CTR_WARN_ILVL_VIB_EPS_CTR_WARN_ILVL_VIB_EPS
# define Rte_Read_CTR_WARN_PTRN_VIB_EPS_CTR_WARN_PTRN_VIB_EPS Rte_Read_BmwMsgSlot269Bas2Repn4BusFrChA_CTR_WARN_PTRN_VIB_EPS_CTR_WARN_PTRN_VIB_EPS
# define Rte_Read_FltCodEnad_Logl Rte_Read_BmwMsgSlot269Bas2Repn4BusFrChA_FltCodEnad_Logl


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_BmwHaptcFbDirNr_Val Rte_Write_BmwMsgSlot269Bas2Repn4BusFrChA_BmwHaptcFbDirNr_Val
# define Rte_Write_BmwHaptcFbDirNrVld_Logl Rte_Write_BmwMsgSlot269Bas2Repn4BusFrChA_BmwHaptcFbDirNrVld_Logl
# define Rte_Write_BmwHaptcFbIntenNr_Val Rte_Write_BmwMsgSlot269Bas2Repn4BusFrChA_BmwHaptcFbIntenNr_Val
# define Rte_Write_BmwHaptcFbIntenNrVld_Logl Rte_Write_BmwMsgSlot269Bas2Repn4BusFrChA_BmwHaptcFbIntenNrVld_Logl
# define Rte_Write_BmwHaptcFbPatNr_Val Rte_Write_BmwMsgSlot269Bas2Repn4BusFrChA_BmwHaptcFbPatNr_Val
# define Rte_Write_BmwHaptcFbPatNrVld_Logl Rte_Write_BmwMsgSlot269Bas2Repn4BusFrChA_BmwHaptcFbPatNrVld_Logl


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_SetNtcSts_Oper Rte_Call_BmwMsgSlot269Bas2Repn4BusFrChA_SetNtcSts_Oper


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_BmwHaptcFbDirNrPrev() (Rte_Inst_BmwMsgSlot269Bas2Repn4BusFrChA->Pim_BmwHaptcFbDirNrPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_BmwHaptcFbIntenNrPrev() (Rte_Inst_BmwMsgSlot269Bas2Repn4BusFrChA->Pim_BmwHaptcFbIntenNrPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_BmwHaptcFbPatNrPrev() (Rte_Inst_BmwMsgSlot269Bas2Repn4BusFrChA->Pim_BmwHaptcFbPatNrPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_CtrVibStwDispExmiSp2015MissFaild() (Rte_Inst_BmwMsgSlot269Bas2Repn4BusFrChA->Pim_CtrVibStwDispExmiSp2015MissFaild) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_CtrVibStwDispExmiSp2015MissPassd() (Rte_Inst_BmwMsgSlot269Bas2Repn4BusFrChA->Pim_CtrVibStwDispExmiSp2015MissPassd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_CtrWarnDirVibEpsVldFaild() (Rte_Inst_BmwMsgSlot269Bas2Repn4BusFrChA->Pim_CtrWarnDirVibEpsVldFaild) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_CtrWarnDirVibEpsVldPassd() (Rte_Inst_BmwMsgSlot269Bas2Repn4BusFrChA->Pim_CtrWarnDirVibEpsVldPassd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_CtrWarnIlvlVibEpsVldFaild() (Rte_Inst_BmwMsgSlot269Bas2Repn4BusFrChA->Pim_CtrWarnIlvlVibEpsVldFaild) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_CtrWarnIlvlVibEpsVldPassd() (Rte_Inst_BmwMsgSlot269Bas2Repn4BusFrChA->Pim_CtrWarnIlvlVibEpsVldPassd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_CtrWarnPtrnVibEpsVldFaild() (Rte_Inst_BmwMsgSlot269Bas2Repn4BusFrChA->Pim_CtrWarnPtrnVibEpsVldFaild) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_CtrWarnPtrnVibEpsVldPassd() (Rte_Inst_BmwMsgSlot269Bas2Repn4BusFrChA->Pim_CtrWarnPtrnVibEpsVldPassd) /* PRQA S 3453 */ /* MD_MSR_19.7 */




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   BmwHaptcFbDirNr1 *Rte_Pim_BmwHaptcFbDirNrPrev(void)
 *   BmwHaptcFbIntenNr1 *Rte_Pim_BmwHaptcFbIntenNrPrev(void)
 *   BmwHaptcFbPatNr1 *Rte_Pim_BmwHaptcFbPatNrPrev(void)
 *   uint8 *Rte_Pim_CtrVibStwDispExmiSp2015MissFaild(void)
 *   uint8 *Rte_Pim_CtrVibStwDispExmiSp2015MissPassd(void)
 *   uint8 *Rte_Pim_CtrWarnDirVibEpsVldFaild(void)
 *   uint8 *Rte_Pim_CtrWarnDirVibEpsVldPassd(void)
 *   uint8 *Rte_Pim_CtrWarnIlvlVibEpsVldFaild(void)
 *   uint8 *Rte_Pim_CtrWarnIlvlVibEpsVldPassd(void)
 *   uint8 *Rte_Pim_CtrWarnPtrnVibEpsVldFaild(void)
 *   uint8 *Rte_Pim_CtrWarnPtrnVibEpsVldPassd(void)
 *
 *********************************************************************************************************************/


# define BmwMsgSlot269Bas2Repn4BusFrChA_START_SEC_CODE
# include "BmwMsgSlot269Bas2Repn4BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwMsgSlot269Bas2Repn4BusFrChA_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
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

# define RTE_RUNNABLE_BmwMsgSlot269Bas2Repn4BusFrChA_Init BmwMsgSlot269Bas2Repn4BusFrChA_Init
FUNC(void, BmwMsgSlot269Bas2Repn4BusFrChA_CODE) BmwMsgSlot269Bas2Repn4BusFrChA_Init(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CTR_VIB_STW_DISP_EXMI_SP2015_Missing
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceiveErrorEvent for DataElementPrototype <CTR_WARN_DIR_VIB_EPS> of PortPrototype <CTR_WARN_DIR_VIB_EPS>
 *   - triggered on DataReceiveErrorEvent for DataElementPrototype <CTR_WARN_ILVL_VIB_EPS> of PortPrototype <CTR_WARN_ILVL_VIB_EPS>
 *   - triggered on DataReceiveErrorEvent for DataElementPrototype <CTR_WARN_PTRN_VIB_EPS> of PortPrototype <CTR_WARN_PTRN_VIB_EPS>
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
 *   Std_ReturnType Rte_Write_BmwHaptcFbDirNr_Val(BmwHaptcFbDirNr1 data)
 *   Std_ReturnType Rte_Write_BmwHaptcFbDirNrVld_Logl(boolean data)
 *   Std_ReturnType Rte_Write_BmwHaptcFbIntenNr_Val(BmwHaptcFbIntenNr1 data)
 *   Std_ReturnType Rte_Write_BmwHaptcFbIntenNrVld_Logl(boolean data)
 *   Std_ReturnType Rte_Write_BmwHaptcFbPatNr_Val(BmwHaptcFbPatNr1 data)
 *   Std_ReturnType Rte_Write_BmwHaptcFbPatNrVld_Logl(boolean data)
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

# define RTE_RUNNABLE_CTR_VIB_STW_DISP_EXMI_SP2015_Missing CTR_VIB_STW_DISP_EXMI_SP2015_Missing
FUNC(void, BmwMsgSlot269Bas2Repn4BusFrChA_CODE) CTR_VIB_STW_DISP_EXMI_SP2015_Missing(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CTR_VIB_STW_DISP_EXMI_SP2015_Received
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <CTR_WARN_DIR_VIB_EPS> of PortPrototype <CTR_WARN_DIR_VIB_EPS>
 *   - triggered on DataReceivedEvent for DataElementPrototype <CTR_WARN_ILVL_VIB_EPS> of PortPrototype <CTR_WARN_ILVL_VIB_EPS>
 *   - triggered on DataReceivedEvent for DataElementPrototype <CTR_WARN_PTRN_VIB_EPS> of PortPrototype <CTR_WARN_PTRN_VIB_EPS>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_CTR_WARN_DIR_VIB_EPS_CTR_WARN_DIR_VIB_EPS(CTR_WARN_DIR_VIB_EPS1 *data)
 *   Std_ReturnType Rte_Read_CTR_WARN_ILVL_VIB_EPS_CTR_WARN_ILVL_VIB_EPS(CTR_WARN_ILVL_VIB_EPS1 *data)
 *   Std_ReturnType Rte_Read_CTR_WARN_PTRN_VIB_EPS_CTR_WARN_PTRN_VIB_EPS(CTR_WARN_PTRN_VIB_EPS1 *data)
 *   Std_ReturnType Rte_Read_FltCodEnad_Logl(boolean *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_BmwHaptcFbDirNr_Val(BmwHaptcFbDirNr1 data)
 *   Std_ReturnType Rte_Write_BmwHaptcFbDirNrVld_Logl(boolean data)
 *   Std_ReturnType Rte_Write_BmwHaptcFbIntenNr_Val(BmwHaptcFbIntenNr1 data)
 *   Std_ReturnType Rte_Write_BmwHaptcFbIntenNrVld_Logl(boolean data)
 *   Std_ReturnType Rte_Write_BmwHaptcFbPatNr_Val(BmwHaptcFbPatNr1 data)
 *   Std_ReturnType Rte_Write_BmwHaptcFbPatNrVld_Logl(boolean data)
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

# define RTE_RUNNABLE_CTR_VIB_STW_DISP_EXMI_SP2015_Received CTR_VIB_STW_DISP_EXMI_SP2015_Received
FUNC(void, BmwMsgSlot269Bas2Repn4BusFrChA_CODE) CTR_VIB_STW_DISP_EXMI_SP2015_Received(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define BmwMsgSlot269Bas2Repn4BusFrChA_STOP_SEC_CODE
# include "BmwMsgSlot269Bas2Repn4BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_SetNtcSts_PortIf1_E_NOT_OK (1U)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_BMWMSGSLOT269BAS2REPN4BUSFRCHA_H */
