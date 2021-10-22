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
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <TurnCntrCorrln>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_TURNCNTRCORRLN_H
# define _RTE_TURNCNTRCORRLN_H

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

# include "Rte_TurnCntrCorrln_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_Appl8_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_INIT) Rte_TurnCntrCorrln_TurnCntrCorrlnSts_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_INIT) Rte_TurnCntrCorrln_TurnCntrIdptSig_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_Appl8_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_INIT) Rte_CDD_MotAg0Meas_MotAg0TurnCntr_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(SigQlfr1, RTE_VAR_INIT) Rte_CDD_MotAg0Meas_MotAg0TurnCntrQlfr_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_INIT) Rte_CDD_MotAg0Meas_MotAg0TurnCntrRollgCntr_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_MotAg1Meas_MotAg1TurnCntr_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(SigQlfr1, RTE_VAR_INIT) Rte_CDD_MotAg1Meas_MotAg1TurnCntrQlfr_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_INIT) Rte_CDD_MotAg1Meas_MotAg1TurnCntrRollgCntr_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_MotAgATurnCntr_Val (0.0F)
#  define Rte_InitValue_MotAgATurnCntrQlfr_Val (0U)
#  define Rte_InitValue_MotAgATurnCntrRollgCntr_Val (0U)
#  define Rte_InitValue_MotAgBTurnCntr_Val (0.0F)
#  define Rte_InitValue_MotAgBTurnCntrQlfr_Val (0U)
#  define Rte_InitValue_MotAgBTurnCntrRollgCntr_Val (0U)
#  define Rte_InitValue_TurnCntrCorrlnSts_Val (3U)
#  define Rte_InitValue_TurnCntrIdptSig_Val (2U)
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_MotAgATurnCntr_Val Rte_Read_TurnCntrCorrln_MotAgATurnCntr_Val
#  define Rte_Read_TurnCntrCorrln_MotAgATurnCntr_Val(data) (*(data) = Rte_CDD_MotAg0Meas_MotAg0TurnCntr_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotAgATurnCntrQlfr_Val Rte_Read_TurnCntrCorrln_MotAgATurnCntrQlfr_Val
#  define Rte_Read_TurnCntrCorrln_MotAgATurnCntrQlfr_Val(data) (*(data) = Rte_CDD_MotAg0Meas_MotAg0TurnCntrQlfr_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotAgATurnCntrRollgCntr_Val Rte_Read_TurnCntrCorrln_MotAgATurnCntrRollgCntr_Val
#  define Rte_Read_TurnCntrCorrln_MotAgATurnCntrRollgCntr_Val(data) (*(data) = Rte_CDD_MotAg0Meas_MotAg0TurnCntrRollgCntr_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotAgBTurnCntr_Val Rte_Read_TurnCntrCorrln_MotAgBTurnCntr_Val
#  define Rte_Read_TurnCntrCorrln_MotAgBTurnCntr_Val(data) (*(data) = Rte_CDD_MotAg1Meas_MotAg1TurnCntr_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotAgBTurnCntrQlfr_Val Rte_Read_TurnCntrCorrln_MotAgBTurnCntrQlfr_Val
#  define Rte_Read_TurnCntrCorrln_MotAgBTurnCntrQlfr_Val(data) (*(data) = Rte_CDD_MotAg1Meas_MotAg1TurnCntrQlfr_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotAgBTurnCntrRollgCntr_Val Rte_Read_TurnCntrCorrln_MotAgBTurnCntrRollgCntr_Val
#  define Rte_Read_TurnCntrCorrln_MotAgBTurnCntrRollgCntr_Val(data) (*(data) = Rte_CDD_MotAg1Meas_MotAg1TurnCntrRollgCntr_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_TurnCntrCorrlnSts_Val Rte_Write_TurnCntrCorrln_TurnCntrCorrlnSts_Val
#  define Rte_Write_TurnCntrCorrln_TurnCntrCorrlnSts_Val(data) (Rte_TurnCntrCorrln_TurnCntrCorrlnSts_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_TurnCntrIdptSig_Val Rte_Write_TurnCntrCorrln_TurnCntrIdptSig_Val
#  define Rte_Write_TurnCntrCorrln_TurnCntrIdptSig_Val(data) (Rte_TurnCntrCorrln_TurnCntrIdptSig_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_DIAGCMGRPROXYAPPL8_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_DIAGCMGRPROXYAPPL8_APPL_CODE) GetNtcQlfrSts8_Oper(NtcNr1 NtcNr_Arg, P2VAR(SigQlfr1, AUTOMATIC, RTE_DIAGCMGRPROXYAPPL8_APPL_VAR) NtcQlfr_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DIAGCMGRPROXYAPPL8_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_GetNtcQlfrSts_Oper GetNtcQlfrSts8_Oper
#  define RTE_START_SEC_DIAGCMGRPROXYAPPL8_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_DIAGCMGRPROXYAPPL8_APPL_CODE) SetNtcSts8_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DIAGCMGRPROXYAPPL8_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_SetNtcSts_Oper SetNtcSts8_Oper


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_Appl8_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl8_PIM_GROUP) Rte_TurnCntrCorrln_MotAgATurnCntrRollgCntPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl8_PIM_GROUP) Rte_TurnCntrCorrln_MotAgATurnCntrStallCntPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl8_PIM_GROUP) Rte_TurnCntrCorrln_MotAgBTurnCntrRollgCntPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl8_PIM_GROUP) Rte_TurnCntrCorrln_MotAgBTurnCntrStallCntPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Appl8_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  endif

#  define Rte_Pim_MotAgATurnCntrRollgCntPrev() \
  (&Rte_TurnCntrCorrln_MotAgATurnCntrRollgCntPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MotAgATurnCntrStallCntPrev() \
  (&Rte_TurnCntrCorrln_MotAgATurnCntrStallCntPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MotAgBTurnCntrRollgCntPrev() \
  (&Rte_TurnCntrCorrln_MotAgBTurnCntrRollgCntPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MotAgBTurnCntrStallCntPrev() \
  (&Rte_TurnCntrCorrln_MotAgBTurnCntrStallCntPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define TurnCntrCorrln_START_SEC_CODE
# include "TurnCntrCorrln_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_TurnCntrCorrlnInit1 TurnCntrCorrlnInit1
#  define RTE_RUNNABLE_TurnCntrCorrlnPer1 TurnCntrCorrlnPer1
# endif

FUNC(void, TurnCntrCorrln_CODE) TurnCntrCorrlnInit1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, TurnCntrCorrln_CODE) TurnCntrCorrlnPer1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define TurnCntrCorrln_STOP_SEC_CODE
# include "TurnCntrCorrln_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


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

#endif /* _RTE_TURNCNTRCORRLN_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
