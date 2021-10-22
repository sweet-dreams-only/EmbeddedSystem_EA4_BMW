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
 *          File:  Rte_BmwHwTqOvrlArbn.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <BmwHwTqOvrlArbn>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_BMWHWTQOVRLARBN_H
# define _RTE_BMWHWTQOVRLARBN_H

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

# include "Rte_BmwHwTqOvrlArbn_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_Appl7_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_INIT) Rte_BmwHwTqOvrlArbn_HwTqCmdOvrl_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_Appl7_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_Appl9_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_INIT) Rte_BmwVehSpd_VehSpd_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_Appl9_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(boolean, RTE_VAR_INIT) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynErrIfActv_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTarHwTqOvrl_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(BmwOvrlCmdQlfr1, RTE_VAR_INIT) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTarHwTqOvrlQlfr_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(DrvgDynIfSt1, RTE_VAR_INIT) Rte_BmwDrvgDynStMac_DrvgDynIfSt_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwSwFctDi_HwTqOvrlCmdEna_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_BmwDrvgDynErrIfActv_Logl (FALSE)
#  define Rte_InitValue_BmwTarHwTqOvrl_Val (0.0F)
#  define Rte_InitValue_BmwTarHwTqOvrlQlfr_Val (15U)
#  define Rte_InitValue_DrvgDynIfSt_Val (128U)
#  define Rte_InitValue_HwTqCmdOvrl_Val (0.0F)
#  define Rte_InitValue_HwTqOvrlCmdEna_Logl (TRUE)
#  define Rte_InitValue_VehSpd_Val (0.0F)
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_BmwDrvgDynErrIfActv_Logl Rte_Read_BmwHwTqOvrlArbn_BmwDrvgDynErrIfActv_Logl
#  define Rte_Read_BmwHwTqOvrlArbn_BmwDrvgDynErrIfActv_Logl(data) (*(data) = Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynErrIfActv_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BmwTarHwTqOvrl_Val Rte_Read_BmwHwTqOvrlArbn_BmwTarHwTqOvrl_Val
#  define Rte_Read_BmwHwTqOvrlArbn_BmwTarHwTqOvrl_Val(data) (*(data) = Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTarHwTqOvrl_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BmwTarHwTqOvrlQlfr_Val Rte_Read_BmwHwTqOvrlArbn_BmwTarHwTqOvrlQlfr_Val
#  define Rte_Read_BmwHwTqOvrlArbn_BmwTarHwTqOvrlQlfr_Val(data) (*(data) = Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTarHwTqOvrlQlfr_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_DrvgDynIfSt_Val Rte_Read_BmwHwTqOvrlArbn_DrvgDynIfSt_Val
#  define Rte_Read_BmwHwTqOvrlArbn_DrvgDynIfSt_Val(data) (*(data) = Rte_BmwDrvgDynStMac_DrvgDynIfSt_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_HwTqOvrlCmdEna_Logl Rte_Read_BmwHwTqOvrlArbn_HwTqOvrlCmdEna_Logl
#  define Rte_Read_BmwHwTqOvrlArbn_HwTqOvrlCmdEna_Logl(data) (*(data) = Rte_BmwSwFctDi_HwTqOvrlCmdEna_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_VehSpd_Val Rte_Read_BmwHwTqOvrlArbn_VehSpd_Val
#  define Rte_Read_BmwHwTqOvrlArbn_VehSpd_Val(data) (*(data) = Rte_BmwVehSpd_VehSpd_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_HwTqCmdOvrl_Val Rte_Write_BmwHwTqOvrlArbn_HwTqCmdOvrl_Val
#  define Rte_Write_BmwHwTqOvrlArbn_HwTqCmdOvrl_Val(data) (Rte_BmwHwTqOvrlArbn_HwTqCmdOvrl_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


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
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

#  define Rte_Prm_BmwHwTqOvrlArbnCmdErrThd_Val() (((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwHwTqOvrlArbnCmdErrThd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwHwTqOvrlArbnOutpTqCmdLim_Val() (((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwHwTqOvrlArbnOutpTqCmdLim_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwHwTqOvrlArbnRampRate_Val() (((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwHwTqOvrlArbnRampRate_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwHwTqOvrlArbnRefTiThd_Val() (((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwHwTqOvrlArbnRefTiThd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_BmwHwTqOvrlArbnHwTqThdY_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwHwTqOvrlArbnHwTqThdY_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_BmwHwTqOvrlArbnHwTqThdY_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwHwTqOvrlArbnHwTqThdY_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_BmwHwTqOvrlArbnVehSpdX_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwHwTqOvrlArbnVehSpdX_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_BmwHwTqOvrlArbnVehSpdX_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwHwTqOvrlArbnVehSpdX_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_Appl7_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_BmwHwTqOvrlArbn_ArbdHwTqOvrlLtch; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_BmwHwTqOvrlArbn_HwTqOvrlScaFacStVari; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_BmwHwTqOvrlArbn_PrevArbdHwTqOvrl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_BmwHwTqOvrlArbn_FctlErrTmr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_BmwHwTqOvrlArbn_FctlErrActv; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_BmwHwTqOvrlArbn_PrevFctlErr; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Appl7_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  endif

#  define Rte_Pim_ArbdHwTqOvrlLtch() \
  (&Rte_BmwHwTqOvrlArbn_ArbdHwTqOvrlLtch) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_HwTqOvrlScaFacStVari() \
  (&Rte_BmwHwTqOvrlArbn_HwTqOvrlScaFacStVari) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_PrevArbdHwTqOvrl() \
  (&Rte_BmwHwTqOvrlArbn_PrevArbdHwTqOvrl) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_FctlErrTmr() \
  (&Rte_BmwHwTqOvrlArbn_FctlErrTmr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_FctlErrActv() \
  (&Rte_BmwHwTqOvrlArbn_FctlErrActv) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_PrevFctlErr() \
  (&Rte_BmwHwTqOvrlArbn_PrevFctlErr) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define BmwHwTqOvrlArbn_START_SEC_CODE
# include "BmwHwTqOvrlArbn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_BmwHwTqOvrlArbnInit1 BmwHwTqOvrlArbnInit1
#  define RTE_RUNNABLE_BmwHwTqOvrlArbnPer1 BmwHwTqOvrlArbnPer1
# endif

FUNC(void, BmwHwTqOvrlArbn_CODE) BmwHwTqOvrlArbnInit1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, BmwHwTqOvrlArbn_CODE) BmwHwTqOvrlArbnPer1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define BmwHwTqOvrlArbn_STOP_SEC_CODE
# include "BmwHwTqOvrlArbn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_BMWHWTQOVRLARBN_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
