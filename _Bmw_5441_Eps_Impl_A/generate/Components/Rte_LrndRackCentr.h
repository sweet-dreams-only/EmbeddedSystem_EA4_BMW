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
 *          File:  Rte_LrndRackCentr.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <LrndRackCentr>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_LRNDRACKCENTR_H
# define _RTE_LRNDRACKCENTR_H

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

# include "Rte_LrndRackCentr_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_Appl7_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_INIT) Rte_LrnPinionCentr_PinionCentrLrnHwCentr_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_LrnPinionCentr_PinionCentrLrnHwTrvl_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_INIT) Rte_LrnPinionCentr_PinionCentrLrnSt_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_Appl7_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(boolean, RTE_VAR_INIT) Rte_LrndRackCentr_LongTermRackCentrCmpl_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_LrndRackCentr_RackCentrCmpl_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_LrndRackCentr_RackCentrMotAgErrPrsnt_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_LrndRackCentr_RackCentrMotAgVld_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_LrndRackCentr_RackCentrPinionAg_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_LrndRackCentr_TotRackTrvl_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwHwAgArbnAndEotPosn_AlgndPinionAg_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_MotTqTranlDampg_MotTqCmdCrfDampd_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
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
#  define Rte_InitValue_LongTermRackCentrCmpl_Logl (FALSE)
#  define Rte_InitValue_MotTqCmd_Val (0.0F)
#  define Rte_InitValue_MotVelCrf_Val (0.0F)
#  define Rte_InitValue_PinionCentrLrnEna_Logl (FALSE)
#  define Rte_InitValue_PinionCentrLrnHwCentr_Val (0.0F)
#  define Rte_InitValue_PinionCentrLrnHwTrvl_Val (0.0F)
#  define Rte_InitValue_PinionCentrLrnSt_Val (0U)
#  define Rte_InitValue_RackCentrCmpl_Logl (FALSE)
#  define Rte_InitValue_RackCentrMotAgErrPrsnt_Logl (FALSE)
#  define Rte_InitValue_RackCentrMotAgVld_Logl (FALSE)
#  define Rte_InitValue_RackCentrPinionAg_Val (0.0F)
#  define Rte_InitValue_TotRackTrvl_Val (0.0F)
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_HwAg_Val Rte_Read_LrndRackCentr_HwAg_Val
#  define Rte_Read_LrndRackCentr_HwAg_Val(data) (*(data) = Rte_BmwHwAgArbnAndEotPosn_AlgndPinionAg_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotTqCmd_Val Rte_Read_LrndRackCentr_MotTqCmd_Val
#  define Rte_Read_LrndRackCentr_MotTqCmd_Val(data) (*(data) = Rte_MotTqTranlDampg_MotTqCmdCrfDampd_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotVelCrf_Val Rte_Read_LrndRackCentr_MotVelCrf_Val
#  define Rte_Read_LrndRackCentr_MotVelCrf_Val(data) (*(data) = Rte_CDD_MotVel_MotVelCrf_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_PinionCentrLrnEna_Logl Rte_Read_LrndRackCentr_PinionCentrLrnEna_Logl
#  define Rte_Read_LrndRackCentr_PinionCentrLrnEna_Logl(data) (*(data) = Rte_BmwDiagcSrvHndlg_LockToLockEna_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_PinionCentrLrnHwCentr_Val Rte_Read_LrndRackCentr_PinionCentrLrnHwCentr_Val
#  define Rte_Read_LrndRackCentr_PinionCentrLrnHwCentr_Val(data) (*(data) = Rte_LrnPinionCentr_PinionCentrLrnHwCentr_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_PinionCentrLrnHwTrvl_Val Rte_Read_LrndRackCentr_PinionCentrLrnHwTrvl_Val
#  define Rte_Read_LrndRackCentr_PinionCentrLrnHwTrvl_Val(data) (*(data) = Rte_LrnPinionCentr_PinionCentrLrnHwTrvl_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_PinionCentrLrnSt_Val Rte_Read_LrndRackCentr_PinionCentrLrnSt_Val
#  define Rte_Read_LrndRackCentr_PinionCentrLrnSt_Val(data) (*(data) = Rte_LrnPinionCentr_PinionCentrLrnSt_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_LongTermRackCentrCmpl_Logl Rte_Write_LrndRackCentr_LongTermRackCentrCmpl_Logl
#  define Rte_Write_LrndRackCentr_LongTermRackCentrCmpl_Logl(data) (Rte_LrndRackCentr_LongTermRackCentrCmpl_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_RackCentrCmpl_Logl Rte_Write_LrndRackCentr_RackCentrCmpl_Logl
#  define Rte_Write_LrndRackCentr_RackCentrCmpl_Logl(data) (Rte_LrndRackCentr_RackCentrCmpl_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_RackCentrMotAgErrPrsnt_Logl Rte_Write_LrndRackCentr_RackCentrMotAgErrPrsnt_Logl
#  define Rte_Write_LrndRackCentr_RackCentrMotAgErrPrsnt_Logl(data) (Rte_LrndRackCentr_RackCentrMotAgErrPrsnt_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_RackCentrMotAgVld_Logl Rte_Write_LrndRackCentr_RackCentrMotAgVld_Logl
#  define Rte_Write_LrndRackCentr_RackCentrMotAgVld_Logl(data) (Rte_LrndRackCentr_RackCentrMotAgVld_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_RackCentrPinionAg_Val Rte_Write_LrndRackCentr_RackCentrPinionAg_Val
#  define Rte_Write_LrndRackCentr_RackCentrPinionAg_Val(data) (Rte_LrndRackCentr_RackCentrPinionAg_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_TotRackTrvl_Val Rte_Write_LrndRackCentr_TotRackTrvl_Val
#  define Rte_Write_LrndRackCentr_TotRackTrvl_Val(data) (Rte_LrndRackCentr_TotRackTrvl_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


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
#  define RTE_START_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_NVMPROXY_APPL_CODE) NvMProxy_GetErrorStatus(NvM_BlockIdType parg0, P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_NVMPROXY_APPL_VAR) ErrorStatus_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_LrndRackCentrNvm_GetErrorStatus(arg1) (NvMProxy_GetErrorStatus((NvM_BlockIdType)15, arg1)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_NVMPROXY_APPL_CODE) NvMProxy_SetRamBlockStatus(NvM_BlockIdType parg0, boolean RamBlockStatus_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_LrndRackCentrNvm_SetRamBlockStatus(arg1) (NvMProxy_SetRamBlockStatus((NvM_BlockIdType)15, arg1)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

#  define Rte_Prm_LrndRackCentrConfTrvlThd_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->LrndRackCentrConfTrvlThd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_LrndRackCentrHwAgFilFrq_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->LrndRackCentrHwAgFilFrq_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_LrndRackCentrMinMaxAdjmtFac_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->LrndRackCentrMinMaxAdjmtFac_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_LrndRackCentrMotTqThd_Val() (((P2CONST(Rte_Calprm_CalRegn01IninOptSetA00_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01IninOptSetA00_DEFAULT_RTE_CALPRM_GROUP])->LrndRackCentrMotTqThd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_LrndRackCentrMotVelThd_Val() (((P2CONST(Rte_Calprm_CalRegn01IninOptSetA00_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01IninOptSetA00_DEFAULT_RTE_CALPRM_GROUP])->LrndRackCentrMotVelThd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_LrndRackCentrRackCentrPosnChgAllwd_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->LrndRackCentrRackCentrPosnChgAllwd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_SysGlbPrmSysKineRat_Val() (((P2CONST(Rte_Calprm_CalRegn01Inin00_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00_DEFAULT_RTE_CALPRM_GROUP])->SysGlbPrmSysKineRat_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_LrndRackCentrTiThd_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->LrndRackCentrTiThd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_LrndRackCentrAllwManIniLrng_Logl() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->LrndRackCentrAllwManIniLrng_Logl) /* PRQA S 3453 */ /* MD_MSR_19.7 */

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_LrndRackCentr_ManLrndRackCentrNegEot; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_LrndRackCentr_ManLrndRackCentrPosEot; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_LrndRackCentr_RackCentrPinionAgPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_LrndRackCentr_RackCentrMaxTmr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_LrndRackCentr_RackCentrMinTmr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_LrndRackCentr_ManLrndRackCentrNegEotVld; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_LrndRackCentr_ManLrndRackCentrPosEotVld; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_LrndRackCentr_HwAgFil; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(LrndRackCentrNvmRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_LrndRackCentr_LrndRackCentr; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  endif

#  define Rte_Pim_ManLrndRackCentrNegEot() \
  (&Rte_LrndRackCentr_ManLrndRackCentrNegEot) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_ManLrndRackCentrPosEot() \
  (&Rte_LrndRackCentr_ManLrndRackCentrPosEot) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_RackCentrPinionAgPrev() \
  (&Rte_LrndRackCentr_RackCentrPinionAgPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_RackCentrMaxTmr() \
  (&Rte_LrndRackCentr_RackCentrMaxTmr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_RackCentrMinTmr() \
  (&Rte_LrndRackCentr_RackCentrMinTmr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_ManLrndRackCentrNegEotVld() \
  (&Rte_LrndRackCentr_ManLrndRackCentrNegEotVld) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_ManLrndRackCentrPosEotVld() \
  (&Rte_LrndRackCentr_ManLrndRackCentrPosEotVld) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_HwAgFil() \
  (&Rte_LrndRackCentr_HwAgFil) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_LrndRackCentr() \
  (&Rte_LrndRackCentr_LrndRackCentr) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define LrndRackCentr_START_SEC_CODE
# include "LrndRackCentr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_LrndRackCentrInit1 LrndRackCentrInit1
#  define RTE_RUNNABLE_LrndRackCentrPer1 LrndRackCentrPer1
#  define RTE_RUNNABLE_RstRackCentrMotAg_Oper RstRackCentrMotAg_Oper
#  define RTE_RUNNABLE_RstRackCentrMotRev_Oper RstRackCentrMotRev_Oper
# endif

FUNC(void, LrndRackCentr_CODE) LrndRackCentrInit1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, LrndRackCentr_CODE) LrndRackCentrPer1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, LrndRackCentr_CODE) RstRackCentrMotAg_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, LrndRackCentr_CODE) RstRackCentrMotRev_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define LrndRackCentr_STOP_SEC_CODE
# include "LrndRackCentr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_NvMService_AC3_SRBS_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_LRNDRACKCENTR_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
