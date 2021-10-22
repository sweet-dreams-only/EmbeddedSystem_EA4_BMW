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
 *          File:  Rte_PhaDiscnct.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <PhaDiscnct>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_PHADISCNCT_H
# define _RTE_PHADISCNCT_H

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

# include "Rte_PhaDiscnct_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(boolean, RTE_VAR_INIT) Rte_PhaDiscnct_PhaDiscnctDiagcActv_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(PhaDiscnctPwmVect1, RTE_VAR_INIT) Rte_PhaDiscnct_PhaDiscnctDiagcPwmVect_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_PhaDiscnct_PhaDiscnctInactv_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_PhaDiscnct_PhaDiscnctWrmIninTestCmpl_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_GateDrv0Ctrl_DiagcStsIvtr1Inactv_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(IvtrFetFltPha1, RTE_VAR_INIT) Rte_GateDrv0Ctrl_IvtrFetFltPha_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(IvtrFetFltTyp1, RTE_VAR_INIT) Rte_GateDrv0Ctrl_IvtrFetFltTyp_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotCurrCorrdA_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotCurrCorrdB_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotCurrCorrdC_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(SigQlfr1, RTE_VAR_INIT) Rte_CDD_CurrMeas_MotCurrQlfr1_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_INIT) Rte_PwrUpSeq_StrtUpSt_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(SysSt1, RTE_VAR_INIT) Rte_SysStMod_SysSt_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_DiagcStsIvtr1Inactv_Logl (FALSE)
#  define Rte_InitValue_IvtrFetFltPha_Val (0U)
#  define Rte_InitValue_IvtrFetFltTyp_Val (0U)
#  define Rte_InitValue_MotCurrCorrdA_Val (0.0F)
#  define Rte_InitValue_MotCurrCorrdB_Val (0.0F)
#  define Rte_InitValue_MotCurrCorrdC_Val (0.0F)
#  define Rte_InitValue_MotCurrQlfr1_Val (0U)
#  define Rte_InitValue_PhaDiscnctDiagcActv_Logl (FALSE)
#  define Rte_InitValue_PhaDiscnctDiagcPwmVect_Val (0U)
#  define Rte_InitValue_PhaDiscnctInactv_Logl (FALSE)
#  define Rte_InitValue_PhaDiscnctWrmIninTestCmpl_Logl (FALSE)
#  define Rte_InitValue_StrtUpSt_Val (0U)
#  define Rte_InitValue_SysSt_Val (3U)
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_DiagcStsIvtr1Inactv_Logl Rte_Read_PhaDiscnct_DiagcStsIvtr1Inactv_Logl
#  define Rte_Read_PhaDiscnct_DiagcStsIvtr1Inactv_Logl(data) (*(data) = Rte_GateDrv0Ctrl_DiagcStsIvtr1Inactv_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_IvtrFetFltPha_Val Rte_Read_PhaDiscnct_IvtrFetFltPha_Val
#  define Rte_Read_PhaDiscnct_IvtrFetFltPha_Val(data) (*(data) = Rte_GateDrv0Ctrl_IvtrFetFltPha_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_IvtrFetFltTyp_Val Rte_Read_PhaDiscnct_IvtrFetFltTyp_Val
#  define Rte_Read_PhaDiscnct_IvtrFetFltTyp_Val(data) (*(data) = Rte_GateDrv0Ctrl_IvtrFetFltTyp_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotCurrCorrdA_Val Rte_Read_PhaDiscnct_MotCurrCorrdA_Val
#  define Rte_Read_PhaDiscnct_MotCurrCorrdA_Val(data) (*(data) = Rte_CDD_MotCtrlMgr_MotCurrCorrdA_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotCurrCorrdB_Val Rte_Read_PhaDiscnct_MotCurrCorrdB_Val
#  define Rte_Read_PhaDiscnct_MotCurrCorrdB_Val(data) (*(data) = Rte_CDD_MotCtrlMgr_MotCurrCorrdB_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotCurrCorrdC_Val Rte_Read_PhaDiscnct_MotCurrCorrdC_Val
#  define Rte_Read_PhaDiscnct_MotCurrCorrdC_Val(data) (*(data) = Rte_CDD_MotCtrlMgr_MotCurrCorrdC_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotCurrQlfr1_Val Rte_Read_PhaDiscnct_MotCurrQlfr1_Val
#  define Rte_Read_PhaDiscnct_MotCurrQlfr1_Val(data) (*(data) = Rte_CDD_CurrMeas_MotCurrQlfr1_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_StrtUpSt_Val Rte_Read_PhaDiscnct_StrtUpSt_Val
#  define Rte_Read_PhaDiscnct_StrtUpSt_Val(data) (*(data) = Rte_PwrUpSeq_StrtUpSt_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_SysSt_Val Rte_Read_PhaDiscnct_SysSt_Val
#  define Rte_Read_PhaDiscnct_SysSt_Val(data) (*(data) = Rte_SysStMod_SysSt_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_PhaDiscnctDiagcActv_Logl Rte_Write_PhaDiscnct_PhaDiscnctDiagcActv_Logl
#  define Rte_Write_PhaDiscnct_PhaDiscnctDiagcActv_Logl(data) (Rte_PhaDiscnct_PhaDiscnctDiagcActv_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_PhaDiscnctDiagcPwmVect_Val Rte_Write_PhaDiscnct_PhaDiscnctDiagcPwmVect_Val
#  define Rte_Write_PhaDiscnct_PhaDiscnctDiagcPwmVect_Val(data) (Rte_PhaDiscnct_PhaDiscnctDiagcPwmVect_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_PhaDiscnctInactv_Logl Rte_Write_PhaDiscnct_PhaDiscnctInactv_Logl
#  define Rte_Write_PhaDiscnct_PhaDiscnctInactv_Logl(data) (Rte_PhaDiscnct_PhaDiscnctInactv_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_PhaDiscnctWrmIninTestCmpl_Logl Rte_Write_PhaDiscnct_PhaDiscnctWrmIninTestCmpl_Logl
#  define Rte_Write_PhaDiscnct_PhaDiscnctWrmIninTestCmpl_Logl(data) (Rte_PhaDiscnct_PhaDiscnctWrmIninTestCmpl_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


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
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_SetGpioPhaDiscnctA_Oper(IOHWAB_BOOL PinSt_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_IoHwAb_SetGpioPhaDiscnctA_Oper IoHwAb_SetGpioPhaDiscnctA_Oper
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_SetGpioPhaDiscnctB_Oper(IOHWAB_BOOL PinSt_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_IoHwAb_SetGpioPhaDiscnctB_Oper IoHwAb_SetGpioPhaDiscnctB_Oper
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_SetGpioPhaDiscnctC_Oper(IOHWAB_BOOL PinSt_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_IoHwAb_SetGpioPhaDiscnctC_Oper IoHwAb_SetGpioPhaDiscnctC_Oper
#  define RTE_START_SEC_DIAGCMGRPROXYAPPL10_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_DIAGCMGRPROXYAPPL10_APPL_CODE) SetNtcStsAndSnpshtData10_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg, uint32 SpclSnpshtData0_Arg, uint32 SpclSnpshtData1_Arg, uint32 SpclSnpshtData2_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DIAGCMGRPROXYAPPL10_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_SetNtcStsAndSnpshtData_Oper SetNtcStsAndSnpshtData10_Oper


/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

#  define Rte_Prm_PhaDiscnctTestCurrTestVal_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->PhaDiscnctTestCurrTestVal_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PhaDiscnctFixdPhaOnTi_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->PhaDiscnctFixdPhaOnTi_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PhaDiscnctFixdPwmPerd_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->PhaDiscnctFixdPwmPerd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PhaDiscnctClsDlyTi_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->PhaDiscnctClsDlyTi_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PhaDiscnctOpenDlyTi_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->PhaDiscnctOpenDlyTi_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PhaDiscnctTestFailScanMax_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->PhaDiscnctTestFailScanMax_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PhaDiscnctTestIninScan_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->PhaDiscnctTestIninScan_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PhaDiscnctTestScanCnt_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->PhaDiscnctTestScanCnt_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PhaDiscnct_DiscnctClsTmr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PhaDiscnct_DiscnctOpenTmr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PhaDiscnct_DiscnctDiagCurrComp; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PhaDiscnct_DiscnctDiagFailScan; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PhaDiscnct_DiscnctDiagFltSts; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PhaDiscnct_DiscnctDiagItrn; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PhaDiscnct_DiscnctDiagSt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PhaDiscnct_DiscnctDiagTestScan; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PhaDiscnct_DiscnctFltPrm; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PhaDiscnct_DiscnctSt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PhaDiscnct_PrevDiscnctCmd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PhaDiscnct_dPhaDiscnctCmd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PhaDiscnct_WrmIninTestCmpl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PhaDiscnct_dPhaDiscnctActvd; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  endif

#  define Rte_Pim_DiscnctClsTmr() \
  (&Rte_PhaDiscnct_DiscnctClsTmr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_DiscnctOpenTmr() \
  (&Rte_PhaDiscnct_DiscnctOpenTmr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_DiscnctDiagCurrComp() \
  (&Rte_PhaDiscnct_DiscnctDiagCurrComp) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_DiscnctDiagFailScan() \
  (&Rte_PhaDiscnct_DiscnctDiagFailScan) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_DiscnctDiagFltSts() \
  (&Rte_PhaDiscnct_DiscnctDiagFltSts) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_DiscnctDiagItrn() \
  (&Rte_PhaDiscnct_DiscnctDiagItrn) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_DiscnctDiagSt() \
  (&Rte_PhaDiscnct_DiscnctDiagSt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_DiscnctDiagTestScan() \
  (&Rte_PhaDiscnct_DiscnctDiagTestScan) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_DiscnctFltPrm() \
  (&Rte_PhaDiscnct_DiscnctFltPrm) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_DiscnctSt() \
  (&Rte_PhaDiscnct_DiscnctSt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_PrevDiscnctCmd() \
  (&Rte_PhaDiscnct_PrevDiscnctCmd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dPhaDiscnctCmd() \
  (&Rte_PhaDiscnct_dPhaDiscnctCmd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_WrmIninTestCmpl() \
  (&Rte_PhaDiscnct_WrmIninTestCmpl) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dPhaDiscnctActvd() \
  (&Rte_PhaDiscnct_dPhaDiscnctActvd) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define PhaDiscnct_START_SEC_CODE
# include "PhaDiscnct_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_PhaDiscnctInit1 PhaDiscnctInit1
#  define RTE_RUNNABLE_PhaDiscnctPer1 PhaDiscnctPer1
#  define RTE_RUNNABLE_PhaDiscnctPer2 PhaDiscnctPer2
# endif

FUNC(void, PhaDiscnct_CODE) PhaDiscnctInit1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, PhaDiscnct_CODE) PhaDiscnctPer1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, PhaDiscnct_CODE) PhaDiscnctPer2(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define PhaDiscnct_STOP_SEC_CODE
# include "PhaDiscnct_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_SetGpio_PortIf1_E_NOT_OK (1U)

#  define RTE_E_SetNtcStsAndSnpshtData_PortIf1_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_PHADISCNCT_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
