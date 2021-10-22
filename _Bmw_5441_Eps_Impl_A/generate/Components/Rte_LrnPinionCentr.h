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
 *          File:  Rte_LrnPinionCentr.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <LrnPinionCentr>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_LRNPINIONCENTR_H
# define _RTE_LRNPINIONCENTR_H

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

# include "Rte_LrnPinionCentr_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_Appl7_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_INIT) Rte_LrnPinionCentr_PinionCentrLrnCmd_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_LrnPinionCentr_PinionCentrLrnHwCentr_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_LrnPinionCentr_PinionCentrLrnHwTrvl_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_INIT) Rte_LrnPinionCentr_PinionCentrLrnSt_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_Appl7_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_INIT) Rte_BmwHwAgArbnAndEotPosn_PinionAg_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_MotVel_MotVelCrf_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwDiagcSrvHndlg_LockToLockEna_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_HwAg_Val (0.0F)
#  define Rte_InitValue_MotVelCrf_Val (0.0F)
#  define Rte_InitValue_PinionCentrLrnCmd_Val (0.0F)
#  define Rte_InitValue_PinionCentrLrnEna_Logl (FALSE)
#  define Rte_InitValue_PinionCentrLrnHwCentr_Val (0.0F)
#  define Rte_InitValue_PinionCentrLrnHwTrvl_Val (0.0F)
#  define Rte_InitValue_PinionCentrLrnSt_Val (0U)
# endif


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Buffers for inter-runnable variables
 *********************************************************************************************************************/

#  define RTE_START_SEC_VAR_Appl7_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_INIT) Rte_Irv_LrnPinionCentr_TarA; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_Irv_LrnPinionCentr_TarVel; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_Appl7_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_HwAg_Val Rte_Read_LrnPinionCentr_HwAg_Val
#  define Rte_Read_LrnPinionCentr_HwAg_Val(data) (*(data) = Rte_BmwHwAgArbnAndEotPosn_PinionAg_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotVelCrf_Val Rte_Read_LrnPinionCentr_MotVelCrf_Val
#  define Rte_Read_LrnPinionCentr_MotVelCrf_Val(data) (*(data) = Rte_CDD_MotVel_MotVelCrf_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_PinionCentrLrnEna_Logl Rte_Read_LrnPinionCentr_PinionCentrLrnEna_Logl
#  define Rte_Read_LrnPinionCentr_PinionCentrLrnEna_Logl(data) (*(data) = Rte_BmwDiagcSrvHndlg_LockToLockEna_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_PinionCentrLrnCmd_Val Rte_Write_LrnPinionCentr_PinionCentrLrnCmd_Val
#  define Rte_Write_LrnPinionCentr_PinionCentrLrnCmd_Val(data) (Rte_LrnPinionCentr_PinionCentrLrnCmd_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_PinionCentrLrnHwCentr_Val Rte_Write_LrnPinionCentr_PinionCentrLrnHwCentr_Val
#  define Rte_Write_LrnPinionCentr_PinionCentrLrnHwCentr_Val(data) (Rte_LrnPinionCentr_PinionCentrLrnHwCentr_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_PinionCentrLrnHwTrvl_Val Rte_Write_LrnPinionCentr_PinionCentrLrnHwTrvl_Val
#  define Rte_Write_LrnPinionCentr_PinionCentrLrnHwTrvl_Val(data) (Rte_LrnPinionCentr_PinionCentrLrnHwTrvl_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_PinionCentrLrnSt_Val Rte_Write_LrnPinionCentr_PinionCentrLrnSt_Val
#  define Rte_Write_LrnPinionCentr_PinionCentrLrnSt_Val(data) (Rte_LrnPinionCentr_PinionCentrLrnSt_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_CDD_NXTRTI_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_CDD_NXTRTI_APPL_CODE) GetRefTmr100MicroSec32bit_Oper(P2VAR(uint32, AUTOMATIC, RTE_CDD_NXTRTI_APPL_VAR) RefTmr_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CDD_NXTRTI_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_GetRefTmr100MicroSec32bit_Oper(arg1) (GetRefTmr100MicroSec32bit_Oper(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_CDD_NXTRTI_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_CDD_NXTRTI_APPL_CODE) GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, P2VAR(uint32, AUTOMATIC, RTE_CDD_NXTRTI_APPL_VAR) TiSpan_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CDD_NXTRTI_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_GetTiSpan100MicroSec32bit_Oper(arg1, arg2) (GetTiSpan100MicroSec32bit_Oper(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Inter-runnable variables
 *********************************************************************************************************************/

/* PRQA S 3453 L1 */ /* MD_MSR_19.7 */
#  define Rte_IrvRead_LrnPinionCentrPer1_TarA() \
  Rte_Irv_LrnPinionCentr_TarA
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_19.7 */
#  define Rte_IrvRead_LrnPinionCentrPer1_TarVel() \
  Rte_Irv_LrnPinionCentr_TarVel
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_19.7 */
#  define Rte_IrvWrite_SetInpPrm_Oper_TarA(data) \
  (Rte_Irv_LrnPinionCentr_TarA = (data))
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_19.7 */
#  define Rte_IrvWrite_SetInpPrm_Oper_TarVel(data) \
  (Rte_Irv_LrnPinionCentr_TarVel = (data))
/* PRQA L:L1 */


/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

#  define Rte_Prm_LrnPinionCentrDampgCtrlGain_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->LrnPinionCentrDampgCtrlGain_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_LrnPinionCentrHldTq_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->LrnPinionCentrHldTq_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_LrnPinionCentrHldTqErrThd_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->LrnPinionCentrHldTqErrThd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_LrnPinionCentrHldTqRateLim_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->LrnPinionCentrHldTqRateLim_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_LrnPinionCentrHwPosnErrThd_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->LrnPinionCentrHwPosnErrThd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_LrnPinionCentrIntglCtrlGain_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->LrnPinionCentrIntglCtrlGain_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_LrnPinionCentrMaxTqCmd_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->LrnPinionCentrMaxTqCmd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_LrnPinionCentrMinMotTq_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->LrnPinionCentrMinMotTq_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_LrnPinionCentrMotVelThd_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->LrnPinionCentrMotVelThd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_LrnPinionCentrPropCtrlGain_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->LrnPinionCentrPropCtrlGain_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_SysGlbPrmSysKineRat_Val() (((P2CONST(Rte_Calprm_CalRegn01Inin00_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00_DEFAULT_RTE_CALPRM_GROUP])->SysGlbPrmSysKineRat_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_LrnPinionCentrTiOutThd_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->LrnPinionCentrTiOutThd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_LrnPinionCentrTiThd_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->LrnPinionCentrTiThd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_Appl7_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_LrnPinionCentr_MaxHwPosnPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_LrnPinionCentr_MinHwPosnPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_LrnPinionCentr_PinionCentrLrnHwCentrPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_LrnPinionCentr_PinionCentrLrnHwTrvlPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_LrnPinionCentr_StCtrl1PosnErrRateLim; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_LrnPinionCentr_StCtrl2TqErrRateLim; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_LrnPinionCentr_StCtrl3PosnErrRateLim; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_LrnPinionCentr_StCtrl3TqErrRateLim; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_LrnPinionCentr_StCtrl4TqErrRateLim; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_LrnPinionCentr_StCtrl5IntglEnaOutpPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_LrnPinionCentr_StCtrl5PosnErrRateLim; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_LrnPinionCentr_StCtrl5TqErrRateLim; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_LrnPinionCentr_TarHwAg; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_LrnPinionCentr_TarMotVel; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_LrnPinionCentr_TqCmdEstimdPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_LrnPinionCentr_dLrnPinionCentrHwPosnCmd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_LrnPinionCentr_StCtrl1TmrARefTi; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_LrnPinionCentr_StCtrl1TmrBRefTi; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_LrnPinionCentr_StCtrl2TmrARefTi; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_LrnPinionCentr_StCtrl2TmrBRefTi; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_LrnPinionCentr_StCtrl3TmrARefTi; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_LrnPinionCentr_StCtrl3TmrBRefTi; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_LrnPinionCentr_StCtrl4TmrARefTi; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_LrnPinionCentr_StCtrl4TmrBRefTi; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_LrnPinionCentr_StCtrl5TmrARefTi; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_LrnPinionCentr_StCtrl5TmrBRefTi; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_LrnPinionCentr_StEstimdPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_LrnPinionCentr_PinionCentrLrnEnaPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_LrnPinionCentr_StCtrl1RateLimdPosnErrLpFil; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_LrnPinionCentr_StCtrl2RateLimdTqErrLpFil; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_LrnPinionCentr_StCtrl3RateLimdPosnErrLpFil; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_LrnPinionCentr_StCtrl3RateLimdTqErrLpFil; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_LrnPinionCentr_StCtrl4RateLimdTqErrLpFil; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_LrnPinionCentr_StCtrl5RateLimdPosnErrLpFil; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_LrnPinionCentr_StCtrl5RateLimdTqErrLpFil; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Appl7_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  endif

#  define Rte_Pim_MaxHwPosnPrev() \
  (&Rte_LrnPinionCentr_MaxHwPosnPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MinHwPosnPrev() \
  (&Rte_LrnPinionCentr_MinHwPosnPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_PinionCentrLrnHwCentrPrev() \
  (&Rte_LrnPinionCentr_PinionCentrLrnHwCentrPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_PinionCentrLrnHwTrvlPrev() \
  (&Rte_LrnPinionCentr_PinionCentrLrnHwTrvlPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_StCtrl1PosnErrRateLim() \
  (&Rte_LrnPinionCentr_StCtrl1PosnErrRateLim) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_StCtrl2TqErrRateLim() \
  (&Rte_LrnPinionCentr_StCtrl2TqErrRateLim) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_StCtrl3PosnErrRateLim() \
  (&Rte_LrnPinionCentr_StCtrl3PosnErrRateLim) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_StCtrl3TqErrRateLim() \
  (&Rte_LrnPinionCentr_StCtrl3TqErrRateLim) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_StCtrl4TqErrRateLim() \
  (&Rte_LrnPinionCentr_StCtrl4TqErrRateLim) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_StCtrl5IntglEnaOutpPrev() \
  (&Rte_LrnPinionCentr_StCtrl5IntglEnaOutpPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_StCtrl5PosnErrRateLim() \
  (&Rte_LrnPinionCentr_StCtrl5PosnErrRateLim) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_StCtrl5TqErrRateLim() \
  (&Rte_LrnPinionCentr_StCtrl5TqErrRateLim) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_TarHwAg() \
  (&Rte_LrnPinionCentr_TarHwAg) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_TarMotVel() \
  (&Rte_LrnPinionCentr_TarMotVel) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_TqCmdEstimdPrev() \
  (&Rte_LrnPinionCentr_TqCmdEstimdPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dLrnPinionCentrHwPosnCmd() \
  (&Rte_LrnPinionCentr_dLrnPinionCentrHwPosnCmd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_StCtrl1TmrARefTi() \
  (&Rte_LrnPinionCentr_StCtrl1TmrARefTi) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_StCtrl1TmrBRefTi() \
  (&Rte_LrnPinionCentr_StCtrl1TmrBRefTi) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_StCtrl2TmrARefTi() \
  (&Rte_LrnPinionCentr_StCtrl2TmrARefTi) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_StCtrl2TmrBRefTi() \
  (&Rte_LrnPinionCentr_StCtrl2TmrBRefTi) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_StCtrl3TmrARefTi() \
  (&Rte_LrnPinionCentr_StCtrl3TmrARefTi) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_StCtrl3TmrBRefTi() \
  (&Rte_LrnPinionCentr_StCtrl3TmrBRefTi) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_StCtrl4TmrARefTi() \
  (&Rte_LrnPinionCentr_StCtrl4TmrARefTi) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_StCtrl4TmrBRefTi() \
  (&Rte_LrnPinionCentr_StCtrl4TmrBRefTi) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_StCtrl5TmrARefTi() \
  (&Rte_LrnPinionCentr_StCtrl5TmrARefTi) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_StCtrl5TmrBRefTi() \
  (&Rte_LrnPinionCentr_StCtrl5TmrBRefTi) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_StEstimdPrev() \
  (&Rte_LrnPinionCentr_StEstimdPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_PinionCentrLrnEnaPrev() \
  (&Rte_LrnPinionCentr_PinionCentrLrnEnaPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_StCtrl1RateLimdPosnErrLpFil() \
  (&Rte_LrnPinionCentr_StCtrl1RateLimdPosnErrLpFil) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_StCtrl2RateLimdTqErrLpFil() \
  (&Rte_LrnPinionCentr_StCtrl2RateLimdTqErrLpFil) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_StCtrl3RateLimdPosnErrLpFil() \
  (&Rte_LrnPinionCentr_StCtrl3RateLimdPosnErrLpFil) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_StCtrl3RateLimdTqErrLpFil() \
  (&Rte_LrnPinionCentr_StCtrl3RateLimdTqErrLpFil) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_StCtrl4RateLimdTqErrLpFil() \
  (&Rte_LrnPinionCentr_StCtrl4RateLimdTqErrLpFil) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_StCtrl5RateLimdPosnErrLpFil() \
  (&Rte_LrnPinionCentr_StCtrl5RateLimdPosnErrLpFil) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_StCtrl5RateLimdTqErrLpFil() \
  (&Rte_LrnPinionCentr_StCtrl5RateLimdTqErrLpFil) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define LrnPinionCentr_START_SEC_CODE
# include "LrnPinionCentr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_LrnPinionCentrInit1 LrnPinionCentrInit1
#  define RTE_RUNNABLE_LrnPinionCentrPer1 LrnPinionCentrPer1
#  define RTE_RUNNABLE_SetInpPrm_Oper SetInpPrm_Oper
# endif

FUNC(void, LrnPinionCentr_CODE) LrnPinionCentrInit1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, LrnPinionCentr_CODE) LrnPinionCentrPer1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, LrnPinionCentr_CODE) SetInpPrm_Oper(float32 TarVel_Arg, float32 TarA_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define LrnPinionCentr_STOP_SEC_CODE
# include "LrnPinionCentr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_LRNPINIONCENTR_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
