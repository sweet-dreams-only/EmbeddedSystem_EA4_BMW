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
 *          File:  Rte_TurnCntrCorrln.h
 *        Config:  C:/Users/nz2999/Documents/Synergy/ccm_wa/ses_dev_ea4/ES261A_TurnCntrCorrln_Impl-nz2999/ES261A_TurnCntrCorrln_Impl/tools/Component.dpa
 *     SW-C Type:  TurnCntrCorrln
 *  Generated at:  Thu Apr 20 14:32:23 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <TurnCntrCorrln> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_TURNCNTRCORRLN_H
# define _RTE_TURNCNTRCORRLN_H

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

# include "Rte_TurnCntrCorrln_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_TurnCntrCorrln
{
  /* PIM Handles section */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MotAgATurnCntrRollgCntPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MotAgATurnCntrStallCntPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MotAgBTurnCntrRollgCntPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MotAgBTurnCntrStallCntPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_TurnCntrCorrln, RTE_CONST, RTE_CONST) Rte_Inst_TurnCntrCorrln; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_TurnCntrCorrln, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_MotAgATurnCntr_Val (0.0F)
# define Rte_InitValue_MotAgATurnCntrQlfr_Val (0U)
# define Rte_InitValue_MotAgATurnCntrRollgCntr_Val (0U)
# define Rte_InitValue_MotAgBTurnCntr_Val (0.0F)
# define Rte_InitValue_MotAgBTurnCntrQlfr_Val (0U)
# define Rte_InitValue_MotAgBTurnCntrRollgCntr_Val (0U)
# define Rte_InitValue_TurnCntrCorrlnSts_Val (3U)
# define Rte_InitValue_TurnCntrIdptSig_Val (2U)


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_TurnCntrCorrln_MotAgATurnCntr_Val(P2VAR(float32, AUTOMATIC, RTE_TURNCNTRCORRLN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_TurnCntrCorrln_MotAgATurnCntrQlfr_Val(P2VAR(SigQlfr1, AUTOMATIC, RTE_TURNCNTRCORRLN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_TurnCntrCorrln_MotAgATurnCntrRollgCntr_Val(P2VAR(uint8, AUTOMATIC, RTE_TURNCNTRCORRLN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_TurnCntrCorrln_MotAgBTurnCntr_Val(P2VAR(float32, AUTOMATIC, RTE_TURNCNTRCORRLN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_TurnCntrCorrln_MotAgBTurnCntrQlfr_Val(P2VAR(SigQlfr1, AUTOMATIC, RTE_TURNCNTRCORRLN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_TurnCntrCorrln_MotAgBTurnCntrRollgCntr_Val(P2VAR(uint8, AUTOMATIC, RTE_TURNCNTRCORRLN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_TurnCntrCorrln_TurnCntrCorrlnSts_Val(uint8 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_TurnCntrCorrln_TurnCntrIdptSig_Val(uint8 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_TurnCntrCorrln_GetNtcQlfrSts_Oper(NtcNr1 NtcNr_Arg, P2VAR(SigQlfr1, AUTOMATIC, RTE_TURNCNTRCORRLN_APPL_VAR) NtcQlfr_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_TurnCntrCorrln_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_MotAgATurnCntr_Val Rte_Read_TurnCntrCorrln_MotAgATurnCntr_Val
# define Rte_Read_MotAgATurnCntrQlfr_Val Rte_Read_TurnCntrCorrln_MotAgATurnCntrQlfr_Val
# define Rte_Read_MotAgATurnCntrRollgCntr_Val Rte_Read_TurnCntrCorrln_MotAgATurnCntrRollgCntr_Val
# define Rte_Read_MotAgBTurnCntr_Val Rte_Read_TurnCntrCorrln_MotAgBTurnCntr_Val
# define Rte_Read_MotAgBTurnCntrQlfr_Val Rte_Read_TurnCntrCorrln_MotAgBTurnCntrQlfr_Val
# define Rte_Read_MotAgBTurnCntrRollgCntr_Val Rte_Read_TurnCntrCorrln_MotAgBTurnCntrRollgCntr_Val


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_TurnCntrCorrlnSts_Val Rte_Write_TurnCntrCorrln_TurnCntrCorrlnSts_Val
# define Rte_Write_TurnCntrIdptSig_Val Rte_Write_TurnCntrCorrln_TurnCntrIdptSig_Val


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_GetNtcQlfrSts_Oper Rte_Call_TurnCntrCorrln_GetNtcQlfrSts_Oper
# define Rte_Call_SetNtcSts_Oper Rte_Call_TurnCntrCorrln_SetNtcSts_Oper


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_MotAgATurnCntrRollgCntPrev() (Rte_Inst_TurnCntrCorrln->Pim_MotAgATurnCntrRollgCntPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MotAgATurnCntrStallCntPrev() (Rte_Inst_TurnCntrCorrln->Pim_MotAgATurnCntrStallCntPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MotAgBTurnCntrRollgCntPrev() (Rte_Inst_TurnCntrCorrln->Pim_MotAgBTurnCntrRollgCntPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MotAgBTurnCntrStallCntPrev() (Rte_Inst_TurnCntrCorrln->Pim_MotAgBTurnCntrStallCntPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   uint8 *Rte_Pim_MotAgATurnCntrRollgCntPrev(void)
 *   uint8 *Rte_Pim_MotAgATurnCntrStallCntPrev(void)
 *   uint8 *Rte_Pim_MotAgBTurnCntrRollgCntPrev(void)
 *   uint8 *Rte_Pim_MotAgBTurnCntrStallCntPrev(void)
 *
 *********************************************************************************************************************/


# define TurnCntrCorrln_START_SEC_CODE
# include "TurnCntrCorrln_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: TurnCntrCorrlnInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_TurnCntrCorrlnInit1 TurnCntrCorrlnInit1
FUNC(void, TurnCntrCorrln_CODE) TurnCntrCorrlnInit1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TurnCntrCorrlnPer1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_MotAgATurnCntr_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotAgATurnCntrQlfr_Val(SigQlfr1 *data)
 *   Std_ReturnType Rte_Read_MotAgATurnCntrRollgCntr_Val(uint8 *data)
 *   Std_ReturnType Rte_Read_MotAgBTurnCntr_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotAgBTurnCntrQlfr_Val(SigQlfr1 *data)
 *   Std_ReturnType Rte_Read_MotAgBTurnCntrRollgCntr_Val(uint8 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_TurnCntrCorrlnSts_Val(uint8 data)
 *   Std_ReturnType Rte_Write_TurnCntrIdptSig_Val(uint8 data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_GetNtcQlfrSts_Oper(NtcNr1 NtcNr_Arg, SigQlfr1 *NtcQlfr_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_GetNtcQlfrSts_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetNtcSts_PortIf1_E_NOT_OK
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_TurnCntrCorrlnPer1 TurnCntrCorrlnPer1
FUNC(void, TurnCntrCorrln_CODE) TurnCntrCorrlnPer1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define TurnCntrCorrln_STOP_SEC_CODE
# include "TurnCntrCorrln_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_GetNtcQlfrSts_PortIf1_E_NOT_OK (1U)

# define RTE_E_SetNtcSts_PortIf1_E_NOT_OK (1U)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_TURNCNTRCORRLN_H */

#include "Rte_Stubs.h"
