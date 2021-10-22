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
 *          File:  Rte_CDD_AdcDiagc.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <CDD_AdcDiagc>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CDD_ADCDIAGC_H
# define _RTE_CDD_ADCDIAGC_H

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

# include "Rte_CDD_AdcDiagc_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(boolean, RTE_VAR_INIT) Rte_CDD_AdcDiagc_Adc0Faild_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_CDD_AdcDiagc_Adc1Faild_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_INIT) Rte_CDD_AdcDiagc_AdcDiagcEndPtrOutp_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_INIT) Rte_CDD_AdcDiagc_AdcDiagcStrtPtrOutp_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_Adc0ScanGroup2Ref0_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_Adc0ScanGroup2Ref1_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_Adc0ScanGroup3Ref0_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_Adc0ScanGroup3Ref1_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_Adc0SelfDiag0_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_Adc0SelfDiag2_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_Adc0SelfDiag4_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_Bmw5441McuCfg_Adc1ScanGroup2Ref0_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_Bmw5441McuCfg_Adc1ScanGroup2Ref1_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_Bmw5441McuCfg_Adc1ScanGroup3Ref0_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_Bmw5441McuCfg_Adc1ScanGroup3Ref1_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_Bmw5441McuCfg_Adc1SelfDiag0_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_Bmw5441McuCfg_Adc1SelfDiag2_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_Bmw5441McuCfg_Adc1SelfDiag4_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_Adc0Faild_Logl (FALSE)
#  define Rte_InitValue_Adc0ScanGroup2Ref0_Val (0.0F)
#  define Rte_InitValue_Adc0ScanGroup2Ref1_Val (0.0F)
#  define Rte_InitValue_Adc0ScanGroup3Ref0_Val (0.0F)
#  define Rte_InitValue_Adc0ScanGroup3Ref1_Val (0.0F)
#  define Rte_InitValue_Adc0SelfDiag0_Val (0.0F)
#  define Rte_InitValue_Adc0SelfDiag2_Val (0.0F)
#  define Rte_InitValue_Adc0SelfDiag4_Val (0.0F)
#  define Rte_InitValue_Adc1Faild_Logl (FALSE)
#  define Rte_InitValue_Adc1ScanGroup2Ref0_Val (0.0F)
#  define Rte_InitValue_Adc1ScanGroup2Ref1_Val (0.0F)
#  define Rte_InitValue_Adc1ScanGroup3Ref0_Val (0.0F)
#  define Rte_InitValue_Adc1ScanGroup3Ref1_Val (0.0F)
#  define Rte_InitValue_Adc1SelfDiag0_Val (0.0F)
#  define Rte_InitValue_Adc1SelfDiag2_Val (0.0F)
#  define Rte_InitValue_Adc1SelfDiag4_Val (0.0F)
#  define Rte_InitValue_AdcDiagcEndPtrOutp_Val (23U)
#  define Rte_InitValue_AdcDiagcStrtPtrOutp_Val (21U)
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_Adc0ScanGroup2Ref0_Val Rte_Read_CDD_AdcDiagc_Adc0ScanGroup2Ref0_Val
#  define Rte_Read_CDD_AdcDiagc_Adc0ScanGroup2Ref0_Val(data) (*(data) = Rte_CDD_MotCtrlMgr_Adc0ScanGroup2Ref0_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_Adc0ScanGroup2Ref1_Val Rte_Read_CDD_AdcDiagc_Adc0ScanGroup2Ref1_Val
#  define Rte_Read_CDD_AdcDiagc_Adc0ScanGroup2Ref1_Val(data) (*(data) = Rte_CDD_MotCtrlMgr_Adc0ScanGroup2Ref1_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_Adc0ScanGroup3Ref0_Val Rte_Read_CDD_AdcDiagc_Adc0ScanGroup3Ref0_Val
#  define Rte_Read_CDD_AdcDiagc_Adc0ScanGroup3Ref0_Val(data) (*(data) = Rte_CDD_MotCtrlMgr_Adc0ScanGroup3Ref0_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_Adc0ScanGroup3Ref1_Val Rte_Read_CDD_AdcDiagc_Adc0ScanGroup3Ref1_Val
#  define Rte_Read_CDD_AdcDiagc_Adc0ScanGroup3Ref1_Val(data) (*(data) = Rte_CDD_MotCtrlMgr_Adc0ScanGroup3Ref1_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_Adc0SelfDiag0_Val Rte_Read_CDD_AdcDiagc_Adc0SelfDiag0_Val
#  define Rte_Read_CDD_AdcDiagc_Adc0SelfDiag0_Val(data) (*(data) = Rte_CDD_MotCtrlMgr_Adc0SelfDiag0_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_Adc0SelfDiag2_Val Rte_Read_CDD_AdcDiagc_Adc0SelfDiag2_Val
#  define Rte_Read_CDD_AdcDiagc_Adc0SelfDiag2_Val(data) (*(data) = Rte_CDD_MotCtrlMgr_Adc0SelfDiag2_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_Adc0SelfDiag4_Val Rte_Read_CDD_AdcDiagc_Adc0SelfDiag4_Val
#  define Rte_Read_CDD_AdcDiagc_Adc0SelfDiag4_Val(data) (*(data) = Rte_CDD_MotCtrlMgr_Adc0SelfDiag4_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_Adc1ScanGroup2Ref0_Val Rte_Read_CDD_AdcDiagc_Adc1ScanGroup2Ref0_Val
#  define Rte_Read_CDD_AdcDiagc_Adc1ScanGroup2Ref0_Val(data) (*(data) = Rte_CDD_Bmw5441McuCfg_Adc1ScanGroup2Ref0_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_Adc1ScanGroup2Ref1_Val Rte_Read_CDD_AdcDiagc_Adc1ScanGroup2Ref1_Val
#  define Rte_Read_CDD_AdcDiagc_Adc1ScanGroup2Ref1_Val(data) (*(data) = Rte_CDD_Bmw5441McuCfg_Adc1ScanGroup2Ref1_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_Adc1ScanGroup3Ref0_Val Rte_Read_CDD_AdcDiagc_Adc1ScanGroup3Ref0_Val
#  define Rte_Read_CDD_AdcDiagc_Adc1ScanGroup3Ref0_Val(data) (*(data) = Rte_CDD_Bmw5441McuCfg_Adc1ScanGroup3Ref0_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_Adc1ScanGroup3Ref1_Val Rte_Read_CDD_AdcDiagc_Adc1ScanGroup3Ref1_Val
#  define Rte_Read_CDD_AdcDiagc_Adc1ScanGroup3Ref1_Val(data) (*(data) = Rte_CDD_Bmw5441McuCfg_Adc1ScanGroup3Ref1_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_Adc1SelfDiag0_Val Rte_Read_CDD_AdcDiagc_Adc1SelfDiag0_Val
#  define Rte_Read_CDD_AdcDiagc_Adc1SelfDiag0_Val(data) (*(data) = Rte_CDD_Bmw5441McuCfg_Adc1SelfDiag0_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_Adc1SelfDiag2_Val Rte_Read_CDD_AdcDiagc_Adc1SelfDiag2_Val
#  define Rte_Read_CDD_AdcDiagc_Adc1SelfDiag2_Val(data) (*(data) = Rte_CDD_Bmw5441McuCfg_Adc1SelfDiag2_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_Adc1SelfDiag4_Val Rte_Read_CDD_AdcDiagc_Adc1SelfDiag4_Val
#  define Rte_Read_CDD_AdcDiagc_Adc1SelfDiag4_Val(data) (*(data) = Rte_CDD_Bmw5441McuCfg_Adc1SelfDiag4_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_Adc0Faild_Logl Rte_Write_CDD_AdcDiagc_Adc0Faild_Logl
#  define Rte_Write_CDD_AdcDiagc_Adc0Faild_Logl(data) (Rte_CDD_AdcDiagc_Adc0Faild_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_Adc1Faild_Logl Rte_Write_CDD_AdcDiagc_Adc1Faild_Logl
#  define Rte_Write_CDD_AdcDiagc_Adc1Faild_Logl(data) (Rte_CDD_AdcDiagc_Adc1Faild_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_AdcDiagcEndPtrOutp_Val Rte_Write_CDD_AdcDiagc_AdcDiagcEndPtrOutp_Val
#  define Rte_Write_CDD_AdcDiagc_AdcDiagcEndPtrOutp_Val(data) (Rte_CDD_AdcDiagc_AdcDiagcEndPtrOutp_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_AdcDiagcStrtPtrOutp_Val Rte_Write_CDD_AdcDiagc_AdcDiagcStrtPtrOutp_Val
#  define Rte_Write_CDD_AdcDiagc_AdcDiagcStrtPtrOutp_Val(data) (Rte_CDD_AdcDiagc_AdcDiagcStrtPtrOutp_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_DIAGCMGRPROXYAPPL10_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_DIAGCMGRPROXYAPPL10_APPL_CODE) GetNtcQlfrSts10_Oper(NtcNr1 NtcNr_Arg, P2VAR(SigQlfr1, AUTOMATIC, RTE_DIAGCMGRPROXYAPPL10_APPL_VAR) NtcQlfr_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DIAGCMGRPROXYAPPL10_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_GetNtcQlfrSts_Oper GetNtcQlfrSts10_Oper
#  define RTE_START_SEC_MCUERRINJ_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MCUERRINJ_APPL_CODE) ReadErrInjReg_Oper(P2VAR(uint32, AUTOMATIC, RTE_MCUERRINJ_APPL_VAR) ErrId_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MCUERRINJ_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_ReadErrInjReg_Oper(arg1) (ReadErrInjReg_Oper(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_DIAGCMGRPROXYAPPL10_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_DIAGCMGRPROXYAPPL10_APPL_CODE) SetNtcSts10_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DIAGCMGRPROXYAPPL10_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_SetNtcSts_Oper SetNtcSts10_Oper
#  define RTE_START_SEC_MCUERRINJ_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MCUERRINJ_APPL_CODE) StrtErrInjCntr_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MCUERRINJ_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_StrtErrInjCntr_Oper() (StrtErrInjCntr_Oper(), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

#  define Rte_Prm_AdcDiagcNtc0x032FailStep_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->AdcDiagcNtc0x032FailStep_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_AdcDiagcNtc0x032PassStep_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->AdcDiagcNtc0x032PassStep_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_AdcDiagcNtc0x033FailStep_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->AdcDiagcNtc0x033FailStep_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_AdcDiagcNtc0x033PassStep_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->AdcDiagcNtc0x033PassStep_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_AdcDiagc_Adc0FltCntSt0; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_AdcDiagc_Adc0FltCntSt2; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_AdcDiagc_Adc0FltCntSt4; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_AdcDiagc_Adc0FltCntSt6; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_AdcDiagc_Adc0ScanGroup2RefFltCntSt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_AdcDiagc_Adc0ScanGroup3RefFltCntSt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_AdcDiagc_Adc1FltCntSt0; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_AdcDiagc_Adc1FltCntSt2; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_AdcDiagc_Adc1FltCntSt4; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_AdcDiagc_Adc1FltCntSt6; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_AdcDiagc_Adc1ScanGroup2RefFltCntSt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_AdcDiagc_Adc1ScanGroup3RefFltCntSt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_AdcDiagc_AdcDiagcEndPtr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_AdcDiagc_AdcDiagcSt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_AdcDiagc_AdcDiagcStrtPtr; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  endif

#  define Rte_Pim_Adc0FltCntSt0() \
  (&Rte_CDD_AdcDiagc_Adc0FltCntSt0) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_Adc0FltCntSt2() \
  (&Rte_CDD_AdcDiagc_Adc0FltCntSt2) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_Adc0FltCntSt4() \
  (&Rte_CDD_AdcDiagc_Adc0FltCntSt4) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_Adc0FltCntSt6() \
  (&Rte_CDD_AdcDiagc_Adc0FltCntSt6) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_Adc0ScanGroup2RefFltCntSt() \
  (&Rte_CDD_AdcDiagc_Adc0ScanGroup2RefFltCntSt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_Adc0ScanGroup3RefFltCntSt() \
  (&Rte_CDD_AdcDiagc_Adc0ScanGroup3RefFltCntSt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_Adc1FltCntSt0() \
  (&Rte_CDD_AdcDiagc_Adc1FltCntSt0) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_Adc1FltCntSt2() \
  (&Rte_CDD_AdcDiagc_Adc1FltCntSt2) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_Adc1FltCntSt4() \
  (&Rte_CDD_AdcDiagc_Adc1FltCntSt4) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_Adc1FltCntSt6() \
  (&Rte_CDD_AdcDiagc_Adc1FltCntSt6) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_Adc1ScanGroup2RefFltCntSt() \
  (&Rte_CDD_AdcDiagc_Adc1ScanGroup2RefFltCntSt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_Adc1ScanGroup3RefFltCntSt() \
  (&Rte_CDD_AdcDiagc_Adc1ScanGroup3RefFltCntSt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_AdcDiagcEndPtr() \
  (&Rte_CDD_AdcDiagc_AdcDiagcEndPtr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_AdcDiagcSt() \
  (&Rte_CDD_AdcDiagc_AdcDiagcSt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_AdcDiagcStrtPtr() \
  (&Rte_CDD_AdcDiagc_AdcDiagcStrtPtr) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define CDD_AdcDiagc_START_SEC_CODE
# include "CDD_AdcDiagc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_AdcDiagcInit1 AdcDiagcInit1
#  define RTE_RUNNABLE_AdcDiagcPer1 AdcDiagcPer1
# endif

FUNC(void, CDD_AdcDiagc_CODE) AdcDiagcInit1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CDD_AdcDiagc_CODE) AdcDiagcPer1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define CDD_AdcDiagc_STOP_SEC_CODE
# include "CDD_AdcDiagc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


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

#endif /* _RTE_CDD_ADCDIAGC_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
