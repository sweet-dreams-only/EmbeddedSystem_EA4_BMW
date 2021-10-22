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
 *          File:  Rte_TqOscn.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <TqOscn>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_TQOSCN_H
# define _RTE_TQOSCN_H

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

# include "Rte_TqOscn_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_Appl7_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(boolean, RTE_VAR_INIT) Rte_BmwHaptcFb_HwOscnEna_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwHaptcFb_HwOscnFallRampRate_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwHaptcFb_HwOscnFrq_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwHaptcFb_HwOscnMotAmp_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwHaptcFb_HwOscnRisngRampRate_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_Appl7_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(boolean, RTE_VAR_INIT) Rte_TqOscn_HwOscnActv_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_TqOscn_HwOscnCmd_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_TqOscn_HwOscnDcThdExcdd_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_HwOscnActv_Logl (FALSE)
#  define Rte_InitValue_HwOscnCmd_Val (0.0F)
#  define Rte_InitValue_HwOscnDcThdExcdd_Logl (FALSE)
#  define Rte_InitValue_HwOscnEna_Logl (FALSE)
#  define Rte_InitValue_HwOscnFallRampRate_Val (-4400.0F)
#  define Rte_InitValue_HwOscnFrq_Val (50.0F)
#  define Rte_InitValue_HwOscnMotAmp_Val (0.0F)
#  define Rte_InitValue_HwOscnRisngRampRate_Val (4400.0F)
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_HwOscnEna_Logl Rte_Read_TqOscn_HwOscnEna_Logl
#  define Rte_Read_TqOscn_HwOscnEna_Logl(data) (*(data) = Rte_BmwHaptcFb_HwOscnEna_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_HwOscnFallRampRate_Val Rte_Read_TqOscn_HwOscnFallRampRate_Val
#  define Rte_Read_TqOscn_HwOscnFallRampRate_Val(data) (*(data) = Rte_BmwHaptcFb_HwOscnFallRampRate_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_HwOscnFrq_Val Rte_Read_TqOscn_HwOscnFrq_Val
#  define Rte_Read_TqOscn_HwOscnFrq_Val(data) (*(data) = Rte_BmwHaptcFb_HwOscnFrq_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_HwOscnMotAmp_Val Rte_Read_TqOscn_HwOscnMotAmp_Val
#  define Rte_Read_TqOscn_HwOscnMotAmp_Val(data) (*(data) = Rte_BmwHaptcFb_HwOscnMotAmp_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_HwOscnRisngRampRate_Val Rte_Read_TqOscn_HwOscnRisngRampRate_Val
#  define Rte_Read_TqOscn_HwOscnRisngRampRate_Val(data) (*(data) = Rte_BmwHaptcFb_HwOscnRisngRampRate_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_HwOscnActv_Logl Rte_Write_TqOscn_HwOscnActv_Logl
#  define Rte_Write_TqOscn_HwOscnActv_Logl(data) (Rte_TqOscn_HwOscnActv_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_HwOscnCmd_Val Rte_Write_TqOscn_HwOscnCmd_Val
#  define Rte_Write_TqOscn_HwOscnCmd_Val(data) (Rte_TqOscn_HwOscnCmd_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_HwOscnDcThdExcdd_Logl Rte_Write_TqOscn_HwOscnDcThdExcdd_Logl
#  define Rte_Write_TqOscn_HwOscnDcThdExcdd_Logl(data) (Rte_TqOscn_HwOscnDcThdExcdd_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_FLTINJ_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_FLTINJ_APPL_CODE) FltInj_f32_Oper(P2VAR(float32, AUTOMATIC, RTE_FLTINJ_APPL_VAR) SigPah_Arg, uint16 LocnKey_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_FLTINJ_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_FltInj_f32_Oper(arg1, arg2) (FltInj_f32_Oper(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

#  define Rte_Prm_TqOscnFallRampRateCal_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->TqOscnFallRampRateCal_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_TqOscnRisngRampRateCal_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->TqOscnRisngRampRateCal_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_TqOscnUseRampRateCal_Logl() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->TqOscnUseRampRateCal_Logl) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_TqOscnAmpLimY_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->TqOscnAmpLimY_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_TqOscnAmpLimY_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->TqOscnAmpLimY_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_TqOscnFrqIn_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->TqOscnFrqIn_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_TqOscnFrqIn_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->TqOscnFrqIn_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TqOscn_AmpRampSt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TqOscn_PrevFallRampRate; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TqOscn_PrevLimdAmp; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TqOscn_PrevPhaAg; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TqOscn_PrevPhaAgInc; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TqOscn_PrevRisngRampRate; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TqOscn_dTqOscnPreFinalCmd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TqOscn_dTqOscnRateLimdAmp; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TqOscn_dTqOscnSinCmd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TqOscn_PrevActv; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TqOscn_PrevDcThdExcdd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TqOscn_PrevEna; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TqOscn_dTqOscnNonZeroAmpFlg; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TqOscn_PreFinalCmdLpFil; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  endif

#  define Rte_Pim_AmpRampSt() \
  (&Rte_TqOscn_AmpRampSt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_PrevFallRampRate() \
  (&Rte_TqOscn_PrevFallRampRate) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_PrevLimdAmp() \
  (&Rte_TqOscn_PrevLimdAmp) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_PrevPhaAg() \
  (&Rte_TqOscn_PrevPhaAg) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_PrevPhaAgInc() \
  (&Rte_TqOscn_PrevPhaAgInc) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_PrevRisngRampRate() \
  (&Rte_TqOscn_PrevRisngRampRate) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dTqOscnPreFinalCmd() \
  (&Rte_TqOscn_dTqOscnPreFinalCmd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dTqOscnRateLimdAmp() \
  (&Rte_TqOscn_dTqOscnRateLimdAmp) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dTqOscnSinCmd() \
  (&Rte_TqOscn_dTqOscnSinCmd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_PrevActv() \
  (&Rte_TqOscn_PrevActv) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_PrevDcThdExcdd() \
  (&Rte_TqOscn_PrevDcThdExcdd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_PrevEna() \
  (&Rte_TqOscn_PrevEna) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dTqOscnNonZeroAmpFlg() \
  (&Rte_TqOscn_dTqOscnNonZeroAmpFlg) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_PreFinalCmdLpFil() \
  (&Rte_TqOscn_PreFinalCmdLpFil) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define TqOscn_START_SEC_CODE
# include "TqOscn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_TqOscnInit1 TqOscnInit1
#  define RTE_RUNNABLE_TqOscnPer1 TqOscnPer1
# endif

FUNC(void, TqOscn_CODE) TqOscnInit1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, TqOscn_CODE) TqOscnPer1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define TqOscn_STOP_SEC_CODE
# include "TqOscn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_TQOSCN_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
