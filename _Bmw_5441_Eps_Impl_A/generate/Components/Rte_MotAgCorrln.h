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
 *          File:  Rte_MotAgCorrln.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <MotAgCorrln>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_MOTAGCORRLN_H
# define _RTE_MOTAGCORRLN_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
#  ifndef RTE_PTR2ARRAYBASETYPE_PASSING
#   define RTE_PTR2ARRAYBASETYPE_PASSING
#  endif
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_MotAgCorrln_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_INIT) Rte_MotAgCorrln_MotAgMeclCorrlnSt_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_INIT) Rte_MotAgCorrln_MotAgMeclIdptSig_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(u0p16, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotAg0Mecl_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(SigQlfr1, RTE_VAR_INIT) Rte_CDD_MotAg0Meas_MotAg0MeclQlfr_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotAg0MeclRollgCntr_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(u0p16, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotAg1Mecl_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(SigQlfr1, RTE_VAR_INIT) Rte_CDD_MotAg1Meas_MotAg1MeclQlfr_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotAg1MeclRollgCntr_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_MotAgAMecl_Val (0U)
#  define Rte_InitValue_MotAgAMeclQlfr_Val (0U)
#  define Rte_InitValue_MotAgAMeclRollgCntr_Val (0U)
#  define Rte_InitValue_MotAgBMecl_Val (0U)
#  define Rte_InitValue_MotAgBMeclQlfr_Val (0U)
#  define Rte_InitValue_MotAgBMeclRollgCntr_Val (0U)
#  define Rte_InitValue_MotAgMeclCorrlnSt_Val (3U)
#  define Rte_InitValue_MotAgMeclIdptSig_Val (2U)
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_MotAgAMecl_Val Rte_Read_MotAgCorrln_MotAgAMecl_Val
#  define Rte_Read_MotAgCorrln_MotAgAMecl_Val(data) (*(data) = Rte_CDD_MotCtrlMgr_MotAg0Mecl_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotAgAMeclQlfr_Val Rte_Read_MotAgCorrln_MotAgAMeclQlfr_Val
#  define Rte_Read_MotAgCorrln_MotAgAMeclQlfr_Val(data) (*(data) = Rte_CDD_MotAg0Meas_MotAg0MeclQlfr_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotAgAMeclRollgCntr_Val Rte_Read_MotAgCorrln_MotAgAMeclRollgCntr_Val
#  define Rte_Read_MotAgCorrln_MotAgAMeclRollgCntr_Val(data) (*(data) = Rte_CDD_MotCtrlMgr_MotAg0MeclRollgCntr_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotAgBMecl_Val Rte_Read_MotAgCorrln_MotAgBMecl_Val
#  define Rte_Read_MotAgCorrln_MotAgBMecl_Val(data) (*(data) = Rte_CDD_MotCtrlMgr_MotAg1Mecl_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotAgBMeclQlfr_Val Rte_Read_MotAgCorrln_MotAgBMeclQlfr_Val
#  define Rte_Read_MotAgCorrln_MotAgBMeclQlfr_Val(data) (*(data) = Rte_CDD_MotAg1Meas_MotAg1MeclQlfr_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotAgBMeclRollgCntr_Val Rte_Read_MotAgCorrln_MotAgBMeclRollgCntr_Val
#  define Rte_Read_MotAgCorrln_MotAgBMeclRollgCntr_Val(data) (*(data) = Rte_CDD_MotCtrlMgr_MotAg1MeclRollgCntr_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_MotAgMeclCorrlnSt_Val Rte_Write_MotAgCorrln_MotAgMeclCorrlnSt_Val
#  define Rte_Write_MotAgCorrln_MotAgMeclCorrlnSt_Val(data) (Rte_MotAgCorrln_MotAgMeclCorrlnSt_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_MotAgMeclIdptSig_Val Rte_Write_MotAgCorrln_MotAgMeclIdptSig_Val
#  define Rte_Write_MotAgCorrln_MotAgMeclIdptSig_Val(data) (Rte_MotAgCorrln_MotAgMeclIdptSig_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_FLTINJ_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_FLTINJ_APPL_CODE) FltInj_u08_Oper(P2VAR(uint8, AUTOMATIC, RTE_FLTINJ_APPL_VAR) SigPah_Arg, uint16 LocnKey_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_FLTINJ_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_FltInj_u08_Oper(arg1, arg2) (FltInj_u08_Oper(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_DIAGCMGRPROXYAPPL10_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_DIAGCMGRPROXYAPPL10_APPL_CODE) GetNtcQlfrSts10_Oper(NtcNr1 NtcNr_Arg, P2VAR(SigQlfr1, AUTOMATIC, RTE_DIAGCMGRPROXYAPPL10_APPL_VAR) NtcQlfr_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DIAGCMGRPROXYAPPL10_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_GetNtcQlfrSts_Oper GetNtcQlfrSts10_Oper
#  define RTE_START_SEC_DIAGCMGRPROXYAPPL10_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_DIAGCMGRPROXYAPPL10_APPL_CODE) SetNtcSts10_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DIAGCMGRPROXYAPPL10_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_SetNtcSts_Oper SetNtcSts10_Oper


/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

#  define Rte_Prm_SysGlbPrmMotPoleCnt_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->SysGlbPrmMotPoleCnt_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(u0p16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotAgCorrln_MotAgCorrlnErrThd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotAgCorrln_MotAgCorrlnMotAgARollgCntPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotAgCorrln_MotAgCorrlnMotAgAStallCntPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotAgCorrln_MotAgCorrlnMotAgBRollgCntPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotAgCorrln_MotAgCorrlnMotAgBStallCntPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotAgCorrln_dMotAgCorrlnMotAgABOk; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  endif

#  define Rte_Pim_MotAgCorrlnErrThd() \
  (&Rte_MotAgCorrln_MotAgCorrlnErrThd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MotAgCorrlnMotAgARollgCntPrev() \
  (&Rte_MotAgCorrln_MotAgCorrlnMotAgARollgCntPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MotAgCorrlnMotAgAStallCntPrev() \
  (&Rte_MotAgCorrln_MotAgCorrlnMotAgAStallCntPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MotAgCorrlnMotAgBRollgCntPrev() \
  (&Rte_MotAgCorrln_MotAgCorrlnMotAgBRollgCntPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MotAgCorrlnMotAgBStallCntPrev() \
  (&Rte_MotAgCorrln_MotAgCorrlnMotAgBStallCntPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dMotAgCorrlnMotAgABOk() \
  (&Rte_MotAgCorrln_dMotAgCorrlnMotAgABOk) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define MotAgCorrln_START_SEC_CODE
# include "MotAgCorrln_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_MotAgCorrlnInit1 MotAgCorrlnInit1
#  define RTE_RUNNABLE_MotAgCorrlnPer1 MotAgCorrlnPer1
# endif

FUNC(void, MotAgCorrln_CODE) MotAgCorrlnInit1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, MotAgCorrln_CODE) MotAgCorrlnPer1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define MotAgCorrln_STOP_SEC_CODE
# include "MotAgCorrln_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_GetNtcQlfrSts_PortIf1_E_NOT_OK (1U)

#  define RTE_E_SetNtcSts_PortIf1_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_MOTAGCORRLN_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
