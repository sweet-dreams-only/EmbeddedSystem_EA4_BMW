/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  Copyright (c) 2006-2014 by Vctr Informatik GmbH.                                             All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_MotAgCorrln.h
 *     SW-C Type:  MotAgCorrln
 *  Generated at:  Tue May 31 16:17:29 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 4.3.0
 *                 RTE Core Version 1.3.0
 *       License:  Unlimited license CBD1400351 (THE ECU PRODUCT "STEERING SYSTEMS", THE ECU SUPPLIER "NXTR", THE VEHICLE MANUFACTURER "GENERAL MOTORS CORPORATION") for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <MotAgCorrln> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_MOTAGCORRLN_H
# define _RTE_MOTAGCORRLN_H

# ifdef RTE_APPLICATION_HEADER_FILE
#  error Multiple application header files included.
# endif
# define RTE_APPLICATION_HEADER_FILE
# define RTE_PTR2ARRAYBASETYPE_PASSING

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_MotAgCorrln_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_MotAgCorrln
{
  /* PIM Handles section */
  P2VAR(u0p16, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MotAgCorrlnErrThd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MotAgCorrlnMotAgARollgCntPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MotAgCorrlnMotAgAStallCntPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MotAgCorrlnMotAgBRollgCntPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MotAgCorrlnMotAgBStallCntPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dMotAgCorrlnMotAgABOk; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_MotAgCorrln, RTE_CONST, RTE_CONST) Rte_Inst_MotAgCorrln; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_MotAgCorrln, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_MotAgAMecl_Val (0U)
# define Rte_InitValue_MotAgAMeclQlfr_Val (0U)
# define Rte_InitValue_MotAgAMeclRollgCntr_Val (0U)
# define Rte_InitValue_MotAgBMecl_Val (0U)
# define Rte_InitValue_MotAgBMeclQlfr_Val (0U)
# define Rte_InitValue_MotAgBMeclRollgCntr_Val (0U)
# define Rte_InitValue_MotAgMeclCorrlnSt_Val (3U)
# define Rte_InitValue_MotAgMeclIdptSig_Val (2U)


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MotAgCorrln_MotAgAMecl_Val(P2VAR(u0p16, AUTOMATIC, RTE_MOTAGCORRLN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MotAgCorrln_MotAgAMeclQlfr_Val(P2VAR(SigQlfr1, AUTOMATIC, RTE_MOTAGCORRLN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MotAgCorrln_MotAgAMeclRollgCntr_Val(P2VAR(uint8, AUTOMATIC, RTE_MOTAGCORRLN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MotAgCorrln_MotAgBMecl_Val(P2VAR(u0p16, AUTOMATIC, RTE_MOTAGCORRLN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MotAgCorrln_MotAgBMeclQlfr_Val(P2VAR(SigQlfr1, AUTOMATIC, RTE_MOTAGCORRLN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MotAgCorrln_MotAgBMeclRollgCntr_Val(P2VAR(uint8, AUTOMATIC, RTE_MOTAGCORRLN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MotAgCorrln_MotAgMeclCorrlnSt_Val(uint8 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MotAgCorrln_MotAgMeclIdptSig_Val(uint8 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_MotAgCorrln_FltInj_u08_Oper(P2VAR(uint8, AUTOMATIC, RTE_MOTAGCORRLN_APPL_VAR) SigPah_Arg, uint16 LocnKey_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_MotAgCorrln_GetNtcQlfrSts_Oper(NtcNr1 NtcNr_Arg, P2VAR(SigQlfr1, AUTOMATIC, RTE_MOTAGCORRLN_APPL_VAR) NtcQlfr_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_MotAgCorrln_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint8, RTE_CODE) Rte_Prm_MotAgCorrln_SysGlbPrmMotPoleCnt_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_MotAgAMecl_Val Rte_Read_MotAgCorrln_MotAgAMecl_Val
# define Rte_Read_MotAgAMeclQlfr_Val Rte_Read_MotAgCorrln_MotAgAMeclQlfr_Val
# define Rte_Read_MotAgAMeclRollgCntr_Val Rte_Read_MotAgCorrln_MotAgAMeclRollgCntr_Val
# define Rte_Read_MotAgBMecl_Val Rte_Read_MotAgCorrln_MotAgBMecl_Val
# define Rte_Read_MotAgBMeclQlfr_Val Rte_Read_MotAgCorrln_MotAgBMeclQlfr_Val
# define Rte_Read_MotAgBMeclRollgCntr_Val Rte_Read_MotAgCorrln_MotAgBMeclRollgCntr_Val


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_MotAgMeclCorrlnSt_Val Rte_Write_MotAgCorrln_MotAgMeclCorrlnSt_Val
# define Rte_Write_MotAgMeclIdptSig_Val Rte_Write_MotAgCorrln_MotAgMeclIdptSig_Val


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_FltInj_u08_Oper Rte_Call_MotAgCorrln_FltInj_u08_Oper
# define Rte_Call_GetNtcQlfrSts_Oper Rte_Call_MotAgCorrln_GetNtcQlfrSts_Oper
# define Rte_Call_SetNtcSts_Oper Rte_Call_MotAgCorrln_SetNtcSts_Oper


/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

# define Rte_Prm_SysGlbPrmMotPoleCnt_Val Rte_Prm_MotAgCorrln_SysGlbPrmMotPoleCnt_Val

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_MotAgCorrlnErrThd() (Rte_Inst_MotAgCorrln->Pim_MotAgCorrlnErrThd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MotAgCorrlnMotAgARollgCntPrev() (Rte_Inst_MotAgCorrln->Pim_MotAgCorrlnMotAgARollgCntPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MotAgCorrlnMotAgAStallCntPrev() (Rte_Inst_MotAgCorrln->Pim_MotAgCorrlnMotAgAStallCntPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MotAgCorrlnMotAgBRollgCntPrev() (Rte_Inst_MotAgCorrln->Pim_MotAgCorrlnMotAgBRollgCntPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MotAgCorrlnMotAgBStallCntPrev() (Rte_Inst_MotAgCorrln->Pim_MotAgCorrlnMotAgBStallCntPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dMotAgCorrlnMotAgABOk() (Rte_Inst_MotAgCorrln->Pim_dMotAgCorrlnMotAgABOk) /* PRQA S 3453 */ /* MD_MSR_19.7 */




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   u0p16 *Rte_Pim_MotAgCorrlnErrThd(void)
 *   uint8 *Rte_Pim_MotAgCorrlnMotAgARollgCntPrev(void)
 *   uint8 *Rte_Pim_MotAgCorrlnMotAgAStallCntPrev(void)
 *   uint8 *Rte_Pim_MotAgCorrlnMotAgBRollgCntPrev(void)
 *   uint8 *Rte_Pim_MotAgCorrlnMotAgBStallCntPrev(void)
 *   boolean *Rte_Pim_dMotAgCorrlnMotAgABOk(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   uint8 Rte_Prm_SysGlbPrmMotPoleCnt_Val(void)
 *
 *********************************************************************************************************************/


# define MotAgCorrln_START_SEC_CODE
# include "MotAgCorrln_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: MotAgCorrlnInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_MotAgCorrlnInit1 MotAgCorrlnInit1
FUNC(void, MotAgCorrln_CODE) MotAgCorrlnInit1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MotAgCorrlnPer1
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
 *   Std_ReturnType Rte_Read_MotAgAMecl_Val(u0p16 *data)
 *   Std_ReturnType Rte_Read_MotAgAMeclQlfr_Val(SigQlfr1 *data)
 *   Std_ReturnType Rte_Read_MotAgAMeclRollgCntr_Val(uint8 *data)
 *   Std_ReturnType Rte_Read_MotAgBMecl_Val(u0p16 *data)
 *   Std_ReturnType Rte_Read_MotAgBMeclQlfr_Val(SigQlfr1 *data)
 *   Std_ReturnType Rte_Read_MotAgBMeclRollgCntr_Val(uint8 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_MotAgMeclCorrlnSt_Val(uint8 data)
 *   Std_ReturnType Rte_Write_MotAgMeclIdptSig_Val(uint8 data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_FltInj_u08_Oper(uint8 *SigPah_Arg, uint16 LocnKey_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_GetNtcQlfrSts_Oper(NtcNr1 NtcNr_Arg, SigQlfr1 *NtcQlfr_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_GetNtcQlfrSts_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetNtcSts_PortIf1_E_NOT_OK
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_MotAgCorrlnPer1 MotAgCorrlnPer1
FUNC(void, MotAgCorrln_CODE) MotAgCorrlnPer1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define MotAgCorrln_STOP_SEC_CODE
# include "MotAgCorrln_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_GetNtcQlfrSts_PortIf1_E_NOT_OK (1U)

# define RTE_E_SetNtcSts_PortIf1_E_NOT_OK (1U)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1464721736
#    error "The magic number of the generated file <C:/Component/ES249B_MotAgCorrln_Impl/tools/contract/Rte_MotAgCorrln.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1464721736
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_MOTAGCORRLN_H */
