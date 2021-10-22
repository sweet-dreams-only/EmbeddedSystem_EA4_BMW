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
 *          File:  Rte_PullCmpActv.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <PullCmpActv>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_PULLCMPACTV_H
# define _RTE_PULLCMPACTV_H

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

# include "Rte_PullCmpActv_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_Appl7_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_INIT) Rte_SysKineAndEff_HwVel_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_Appl7_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_Appl9_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_INIT) Rte_VehSigCdng_VehLgtA_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwVehSpd_VehSpd_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwVehSpd_VehSpdVld_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_Appl9_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_INIT) Rte_PullCmpActv_PullCmpCmd_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwHwAgArbnAndEotPosn_PinionAg_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_HwTqArbn_HwTq_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwHwAgArbnAndEotPosn_PinionAgConf_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_PullCmpActv_PullCmpActvDi_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwSwFctDi_PullCmpCmdDiBmwOvrd_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_PullCmpActv_PullCmpCustLrngDi_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_CmnMfgSrv_PullCmpLrngDi_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_PullCmpActv_VehYawRate_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_PullCmpActv_VehYawRateVld_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_HwAg_Val (0.0F)
#  define Rte_InitValue_HwTq_Val (0.0F)
#  define Rte_InitValue_HwVel_Val (0.0F)
#  define Rte_InitValue_PinionAgConf_Val (0.0F)
#  define Rte_InitValue_PullCmpActvDi_Logl (FALSE)
#  define Rte_InitValue_PullCmpCmd_Val (0.0F)
#  define Rte_InitValue_PullCmpCmdDi_Logl (FALSE)
#  define Rte_InitValue_PullCmpCustLrngDi_Logl (FALSE)
#  define Rte_InitValue_PullCmpLrngDi_Logl (FALSE)
#  define Rte_InitValue_VehLatA_Val (0.0F)
#  define Rte_InitValue_VehSpd_Val (0.0F)
#  define Rte_InitValue_VehSpdVld_Logl (FALSE)
#  define Rte_InitValue_VehYawRate_Val (0.0F)
#  define Rte_InitValue_VehYawRateVld_Logl (FALSE)
# endif


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Buffers for inter-runnable variables
 *********************************************************************************************************************/

#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_INIT) Rte_Irv_PullCmpActv_RampDwnStepSize; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_HwAg_Val Rte_Read_PullCmpActv_HwAg_Val
#  define Rte_Read_PullCmpActv_HwAg_Val(data) (*(data) = Rte_BmwHwAgArbnAndEotPosn_PinionAg_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_HwTq_Val Rte_Read_PullCmpActv_HwTq_Val
#  define Rte_Read_PullCmpActv_HwTq_Val(data) (*(data) = Rte_HwTqArbn_HwTq_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_HwVel_Val Rte_Read_PullCmpActv_HwVel_Val
#  define Rte_Read_PullCmpActv_HwVel_Val(data) (*(data) = Rte_SysKineAndEff_HwVel_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_PinionAgConf_Val Rte_Read_PullCmpActv_PinionAgConf_Val
#  define Rte_Read_PullCmpActv_PinionAgConf_Val(data) (*(data) = Rte_BmwHwAgArbnAndEotPosn_PinionAgConf_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_PullCmpActvDi_Logl Rte_Read_PullCmpActv_PullCmpActvDi_Logl
#  define Rte_Read_PullCmpActv_PullCmpActvDi_Logl(data) (*(data) = Rte_PullCmpActv_PullCmpActvDi_Logl, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_PullCmpCmdDi_Logl Rte_Read_PullCmpActv_PullCmpCmdDi_Logl
#  define Rte_Read_PullCmpActv_PullCmpCmdDi_Logl(data) (*(data) = Rte_BmwSwFctDi_PullCmpCmdDiBmwOvrd_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_PullCmpCustLrngDi_Logl Rte_Read_PullCmpActv_PullCmpCustLrngDi_Logl
#  define Rte_Read_PullCmpActv_PullCmpCustLrngDi_Logl(data) (*(data) = Rte_PullCmpActv_PullCmpCustLrngDi_Logl, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_PullCmpLrngDi_Logl Rte_Read_PullCmpActv_PullCmpLrngDi_Logl
#  define Rte_Read_PullCmpActv_PullCmpLrngDi_Logl(data) (*(data) = Rte_CmnMfgSrv_PullCmpLrngDi_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_VehLatA_Val Rte_Read_PullCmpActv_VehLatA_Val
#  define Rte_Read_PullCmpActv_VehLatA_Val(data) (*(data) = Rte_VehSigCdng_VehLgtA_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_VehSpd_Val Rte_Read_PullCmpActv_VehSpd_Val
#  define Rte_Read_PullCmpActv_VehSpd_Val(data) (*(data) = Rte_BmwVehSpd_VehSpd_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_VehSpdVld_Logl Rte_Read_PullCmpActv_VehSpdVld_Logl
#  define Rte_Read_PullCmpActv_VehSpdVld_Logl(data) (*(data) = Rte_BmwVehSpd_VehSpdVld_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_VehYawRate_Val Rte_Read_PullCmpActv_VehYawRate_Val
#  define Rte_Read_PullCmpActv_VehYawRate_Val(data) (*(data) = Rte_PullCmpActv_VehYawRate_Val, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_VehYawRateVld_Logl Rte_Read_PullCmpActv_VehYawRateVld_Logl
#  define Rte_Read_PullCmpActv_VehYawRateVld_Logl(data) (*(data) = Rte_PullCmpActv_VehYawRateVld_Logl, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_PullCmpCmd_Val Rte_Write_PullCmpActv_PullCmpCmd_Val
#  define Rte_Write_PullCmpActv_PullCmpCmd_Val(data) (Rte_PullCmpActv_PullCmpCmd_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_FLTINJ_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_FLTINJ_APPL_CODE) FltInj_f32_Oper(P2VAR(float32, AUTOMATIC, RTE_FLTINJ_APPL_VAR) SigPah_Arg, uint16 LocnKey_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_FLTINJ_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_FltInj_f32_Oper(arg1, arg2) (FltInj_f32_Oper(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
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

#  define Rte_Call_PullCmpLongTerm_GetErrorStatus(arg1) (NvMProxy_GetErrorStatus((NvM_BlockIdType)3, arg1)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_NVMPROXY_APPL_CODE) NvMProxy_SetRamBlockStatus(NvM_BlockIdType parg0, boolean RamBlockStatus_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_PullCmpLongTerm_SetRamBlockStatus(arg1) (NvMProxy_SetRamBlockStatus((NvM_BlockIdType)3, arg1)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Inter-runnable variables
 *********************************************************************************************************************/

/* PRQA S 3453 L1 */ /* MD_MSR_19.7 */
#  define Rte_IrvWrite_PullCmpActvInit1_RampDwnStepSize(data) \
  (Rte_Irv_PullCmpActv_RampDwnStepSize = (data))
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_19.7 */
#  define Rte_IrvRead_PullCmpActvPer1_RampDwnStepSize() \
  Rte_Irv_PullCmpActv_RampDwnStepSize
/* PRQA L:L1 */


/**********************************************************************************************************************
 * Rte_CData (SW-C local calibration parameters)
 *********************************************************************************************************************/

#  define Rte_CData_PullCmpLongTermDft() (((P2CONST(Rte_Calprm_PullCmpActv_DEFAULT_RTE_CDATA_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_PullCmpActv_DEFAULT_RTE_CDATA_GROUP])->PullCmpLongTermDft) /* PRQA S 3453 */ /* MD_MSR_19.7 */

/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

#  define Rte_Prm_PullCmpActvCmpLrnTiDecShoTerm_Val() (((P2CONST(Rte_Calprm_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP])->PullCmpActvCmpLrnTiDecShoTerm_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PullCmpActvCmpLrnTiIncShoTerm_Val() (((P2CONST(Rte_Calprm_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP])->PullCmpActvCmpLrnTiIncShoTerm_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PullCmpActvCmpLrnTiLongTerm_Val() (((P2CONST(Rte_Calprm_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP])->PullCmpActvCmpLrnTiLongTerm_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PullCmpActvCmpShoTermRstHwAgThd_Val() (((P2CONST(Rte_Calprm_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP])->PullCmpActvCmpShoTermRstHwAgThd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PullCmpActvCmpShoTermRstHwTqThd_Val() (((P2CONST(Rte_Calprm_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP])->PullCmpActvCmpShoTermRstHwTqThd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PullCmpActvCmpShoTermRstLatAThd_Val() (((P2CONST(Rte_Calprm_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP])->PullCmpActvCmpShoTermRstLatAThd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PullCmpActvCmpShoTermRstYawRateThd_Val() (((P2CONST(Rte_Calprm_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP])->PullCmpActvCmpShoTermRstYawRateThd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PullCmpActvHwTqFilFrqLongTerm_Val() (((P2CONST(Rte_Calprm_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP])->PullCmpActvHwTqFilFrqLongTerm_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PullCmpActvHwTqFilFrqLrngEna_Val() (((P2CONST(Rte_Calprm_CalRegn01Inin00_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00_DEFAULT_RTE_CALPRM_GROUP])->PullCmpActvHwTqFilFrqLrngEna_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PullCmpActvHwTqFilFrqShoTerm_Val() (((P2CONST(Rte_Calprm_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP])->PullCmpActvHwTqFilFrqShoTerm_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PullCmpActvLongTermLim_Val() (((P2CONST(Rte_Calprm_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP])->PullCmpActvLongTermLim_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PullCmpActvLrngEnaAgConfMinMgn_Val() (((P2CONST(Rte_Calprm_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP])->PullCmpActvLrngEnaAgConfMinMgn_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PullCmpActvLrngEnaHwAgMaxMgn_Val() (((P2CONST(Rte_Calprm_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP])->PullCmpActvLrngEnaHwAgMaxMgn_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PullCmpActvLrngEnaHwTqMaxMgn_Val() (((P2CONST(Rte_Calprm_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP])->PullCmpActvLrngEnaHwTqMaxMgn_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PullCmpActvLrngEnaHwVelMaxMgn_Val() (((P2CONST(Rte_Calprm_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP])->PullCmpActvLrngEnaHwVelMaxMgn_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PullCmpActvLrngEnaLatAMaxMgn_Val() (((P2CONST(Rte_Calprm_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP])->PullCmpActvLrngEnaLatAMaxMgn_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PullCmpActvLrngEnaTiThd_Val() (((P2CONST(Rte_Calprm_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP])->PullCmpActvLrngEnaTiThd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PullCmpActvLrngEnaVehSpdMaxMgn_Val() (((P2CONST(Rte_Calprm_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP])->PullCmpActvLrngEnaVehSpdMaxMgn_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PullCmpActvLrngEnaVehSpdMinMgn_Val() (((P2CONST(Rte_Calprm_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP])->PullCmpActvLrngEnaVehSpdMinMgn_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PullCmpActvLrngEnaVehSpdRateMaxMgn_Val() (((P2CONST(Rte_Calprm_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP])->PullCmpActvLrngEnaVehSpdRateMaxMgn_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PullCmpActvLrngEnaYawRateMaxMgn_Val() (((P2CONST(Rte_Calprm_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP])->PullCmpActvLrngEnaYawRateMaxMgn_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PullCmpActvOpstSignTiShoTerm_Val() (((P2CONST(Rte_Calprm_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP])->PullCmpActvOpstSignTiShoTerm_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PullCmpActvOutpMaxRate_Val() (((P2CONST(Rte_Calprm_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP])->PullCmpActvOutpMaxRate_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PullCmpActvPullCmpShoTermLim_Val() (((P2CONST(Rte_Calprm_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP])->PullCmpActvPullCmpShoTermLim_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PullCmpActvPullCmpTotLim_Val() (((P2CONST(Rte_Calprm_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP])->PullCmpActvPullCmpTotLim_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PullCmpActvPullErrLimLongTerm_Val() (((P2CONST(Rte_Calprm_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP])->PullCmpActvPullErrLimLongTerm_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PullCmpActvPullErrMgnThd_Val() (((P2CONST(Rte_Calprm_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP])->PullCmpActvPullErrMgnThd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PullCmpActvPullErrShoTermLim_Val() (((P2CONST(Rte_Calprm_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP])->PullCmpActvPullErrShoTermLim_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PullCmpActvShoTermRampTi_Val() (((P2CONST(Rte_Calprm_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP])->PullCmpActvShoTermRampTi_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PullCmpActvYawRateFilFrq_Val() (((P2CONST(Rte_Calprm_CalRegn01Inin00_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00_DEFAULT_RTE_CALPRM_GROUP])->PullCmpActvYawRateFilFrq_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_SysGlbPrmSysTqRat_Val() (((P2CONST(Rte_Calprm_CalRegn01IninOptSetA00_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01IninOptSetA00_DEFAULT_RTE_CALPRM_GROUP])->SysGlbPrmSysTqRat_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PullCmpActvEna_Logl() (((P2CONST(Rte_Calprm_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP])->PullCmpActvEna_Logl) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_PullCmpActvVehSpdScaTblX_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP])->PullCmpActvVehSpdScaTblX_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_PullCmpActvVehSpdScaTblX_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP])->PullCmpActvVehSpdScaTblX_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_PullCmpActvVehSpdScaTblY_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP])->PullCmpActvVehSpdScaTblY_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_PullCmpActvVehSpdScaTblY_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP])->PullCmpActvVehSpdScaTblY_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
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

extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PullCmpActv_CmpLrnTiDecShoTerm; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PullCmpActv_CmpLrnTiIncShoTerm; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PullCmpActv_CmpLrnTiLongTerm; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PullCmpActv_IntgtrGainDecShoTerm; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PullCmpActv_IntgtrGainIncShoTerm; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PullCmpActv_PrevLrnTiLongTerm; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PullCmpActv_PullCmpCmdRateLimPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PullCmpActv_PullCmpCmdTot; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PullCmpActv_PullCmpLongTerm; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PullCmpActv_PullCmpShoTerm; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PullCmpActv_VehSpdPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PullCmpActv_VehSpdRate; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PullCmpActv_dPullCmpActvIntgtrGainShoTerm; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PullCmpActv_dPullCmpActvPullErrLongTerm; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PullCmpActv_dPullCmpActvPullErrShoTerm; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PullCmpActv_RefTiEnaLrng; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PullCmpActv_RefTiOpstSign; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PullCmpActv_LrngEnaPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PullCmpActv_LrngEnad; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PullCmpActv_OpstSignPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PullCmpActv_PullCmpActvDi; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PullCmpActv_PullCmpLongTermRst; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PullCmpActv_PullCmpShoTermRst; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PullCmpActv_dPullCmpActvShoTermRst; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PullCmpActv_HwTqLpFilLongTerm; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PullCmpActv_HwTqLpFilLrngEna; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PullCmpActv_HwTqLpFilShoTerm; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PullCmpActv_VehYawRateLpFil; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  endif

#  define Rte_Pim_CmpLrnTiDecShoTerm() \
  (&Rte_PullCmpActv_CmpLrnTiDecShoTerm) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_CmpLrnTiIncShoTerm() \
  (&Rte_PullCmpActv_CmpLrnTiIncShoTerm) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_CmpLrnTiLongTerm() \
  (&Rte_PullCmpActv_CmpLrnTiLongTerm) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_IntgtrGainDecShoTerm() \
  (&Rte_PullCmpActv_IntgtrGainDecShoTerm) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_IntgtrGainIncShoTerm() \
  (&Rte_PullCmpActv_IntgtrGainIncShoTerm) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_PrevLrnTiLongTerm() \
  (&Rte_PullCmpActv_PrevLrnTiLongTerm) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_PullCmpCmdRateLimPrev() \
  (&Rte_PullCmpActv_PullCmpCmdRateLimPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_PullCmpCmdTot() \
  (&Rte_PullCmpActv_PullCmpCmdTot) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_PullCmpLongTerm() \
  (&Rte_PullCmpActv_PullCmpLongTerm) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_PullCmpShoTerm() \
  (&Rte_PullCmpActv_PullCmpShoTerm) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_VehSpdPrev() \
  (&Rte_PullCmpActv_VehSpdPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_VehSpdRate() \
  (&Rte_PullCmpActv_VehSpdRate) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dPullCmpActvIntgtrGainShoTerm() \
  (&Rte_PullCmpActv_dPullCmpActvIntgtrGainShoTerm) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dPullCmpActvPullErrLongTerm() \
  (&Rte_PullCmpActv_dPullCmpActvPullErrLongTerm) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dPullCmpActvPullErrShoTerm() \
  (&Rte_PullCmpActv_dPullCmpActvPullErrShoTerm) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_RefTiEnaLrng() \
  (&Rte_PullCmpActv_RefTiEnaLrng) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_RefTiOpstSign() \
  (&Rte_PullCmpActv_RefTiOpstSign) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_LrngEnaPrev() \
  (&Rte_PullCmpActv_LrngEnaPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_LrngEnad() \
  (&Rte_PullCmpActv_LrngEnad) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_OpstSignPrev() \
  (&Rte_PullCmpActv_OpstSignPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_PullCmpActvDi() \
  (&Rte_PullCmpActv_PullCmpActvDi) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_PullCmpLongTermRst() \
  (&Rte_PullCmpActv_PullCmpLongTermRst) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_PullCmpShoTermRst() \
  (&Rte_PullCmpActv_PullCmpShoTermRst) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dPullCmpActvShoTermRst() \
  (&Rte_PullCmpActv_dPullCmpActvShoTermRst) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_HwTqLpFilLongTerm() \
  (&Rte_PullCmpActv_HwTqLpFilLongTerm) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_HwTqLpFilLrngEna() \
  (&Rte_PullCmpActv_HwTqLpFilLrngEna) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_HwTqLpFilShoTerm() \
  (&Rte_PullCmpActv_HwTqLpFilShoTerm) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_VehYawRateLpFil() \
  (&Rte_PullCmpActv_VehYawRateLpFil) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define PullCmpActv_START_SEC_CODE
# include "PullCmpActv_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_GetPullCmpPrm_Oper GetPullCmpPrm_Oper
#  define RTE_RUNNABLE_PullCmpActvInit1 PullCmpActvInit1
#  define RTE_RUNNABLE_PullCmpActvPer1 PullCmpActvPer1
#  define RTE_RUNNABLE_PullCmpActvPer2 PullCmpActvPer2
#  define RTE_RUNNABLE_RstPullCmp_Oper RstPullCmp_Oper
#  define RTE_RUNNABLE_SetPullCmpLongTerm_Oper SetPullCmpLongTerm_Oper
#  define RTE_RUNNABLE_SetPullCmpShoTerm_Oper SetPullCmpShoTerm_Oper
# endif

FUNC(void, PullCmpActv_CODE) GetPullCmpPrm_Oper(P2VAR(float32, AUTOMATIC, RTE_PULLCMPACTV_APPL_VAR) PullCmpCmdTot_Arg, P2VAR(float32, AUTOMATIC, RTE_PULLCMPACTV_APPL_VAR) PullCmpShoTerm_Arg, P2VAR(float32, AUTOMATIC, RTE_PULLCMPACTV_APPL_VAR) PullCmpLongTerm_Arg, P2VAR(boolean, AUTOMATIC, RTE_PULLCMPACTV_APPL_VAR) LrngEnad_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, PullCmpActv_CODE) PullCmpActvInit1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, PullCmpActv_CODE) PullCmpActvPer1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, PullCmpActv_CODE) PullCmpActvPer2(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, PullCmpActv_CODE) RstPullCmp_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, PullCmpActv_CODE) SetPullCmpLongTerm_Oper(float32 PullCmpLongTerm_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, PullCmpActv_CODE) SetPullCmpShoTerm_Oper(float32 PullCmpShoTerm_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define PullCmpActv_STOP_SEC_CODE
# include "PullCmpActv_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_PULLCMPACTV_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
