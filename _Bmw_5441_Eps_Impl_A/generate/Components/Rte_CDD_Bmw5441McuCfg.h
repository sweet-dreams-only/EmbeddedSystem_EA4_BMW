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
 *          File:  Rte_CDD_Bmw5441McuCfg.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <CDD_Bmw5441McuCfg>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CDD_BMW5441MCUCFG_H
# define _RTE_CDD_BMW5441MCUCFG_H

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

# include "Rte_CDD_Bmw5441McuCfg_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_INIT) Rte_CDD_Bmw5441McuCfg_Adc1ScanGroup2Ref0_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_Bmw5441McuCfg_Adc1ScanGroup2Ref1_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_Bmw5441McuCfg_Adc1ScanGroup3Ref0_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_Bmw5441McuCfg_Adc1ScanGroup3Ref1_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_Bmw5441McuCfg_Adc1SelfDiag0_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_Bmw5441McuCfg_Adc1SelfDiag2_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_Bmw5441McuCfg_Adc1SelfDiag4_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_CDD_Bmw5441McuCfg_BattRtnCurrAdcFaild_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_Bmw5441McuCfg_BattVltg_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_CDD_Bmw5441McuCfg_BattVltgAdcFaild_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_Bmw5441McuCfg_BattVltgSwd1_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_CDD_Bmw5441McuCfg_BattVltgSwd1AdcFaild_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_Bmw5441McuCfg_EcuT_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_CDD_Bmw5441McuCfg_EcuTAdcFaild_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_CDD_Bmw5441McuCfg_HwTq4RawAdcAdcFaild_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_CDD_Bmw5441McuCfg_HwTq5RawAdcAdcFaild_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_CDD_Bmw5441McuCfg_MotCurrAdcVlyAAdcFaild_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_CDD_Bmw5441McuCfg_MotCurrAdcVlyBAdcFaild_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_CDD_Bmw5441McuCfg_MotCurrAdcVlyCAdcFaild_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_CDD_Bmw5441McuCfg_MotDrvr1IninTestCmpl_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_Bmw5441McuCfg_RvsBattDiagcGndAdc_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_CDD_Bmw5441McuCfg_RvsBattDiagcGndAdcFaild_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_Bmw5441McuCfg_RvsBattDiagcRtnAdc_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_CDD_Bmw5441McuCfg_RvsBattDiagcRtnAdcFaild_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_CDD_AdcDiagc_Adc0Faild_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_CDD_AdcDiagc_Adc1Faild_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_Adc0Faild_Logl (FALSE)
#  define Rte_InitValue_Adc1Faild_Logl (FALSE)
#  define Rte_InitValue_Adc1ScanGroup2Ref0_Val (0.0F)
#  define Rte_InitValue_Adc1ScanGroup2Ref1_Val (0.0F)
#  define Rte_InitValue_Adc1ScanGroup3Ref0_Val (0.0F)
#  define Rte_InitValue_Adc1ScanGroup3Ref1_Val (0.0F)
#  define Rte_InitValue_Adc1SelfDiag0_Val (0.0F)
#  define Rte_InitValue_Adc1SelfDiag2_Val (0.0F)
#  define Rte_InitValue_Adc1SelfDiag4_Val (0.0F)
#  define Rte_InitValue_BattRtnCurrAdcFaild_Logl (FALSE)
#  define Rte_InitValue_BattVltg_Val (0.0F)
#  define Rte_InitValue_BattVltgAdcFaild_Logl (FALSE)
#  define Rte_InitValue_BattVltgSwd1_Val (0.0F)
#  define Rte_InitValue_BattVltgSwd1AdcFaild_Logl (FALSE)
#  define Rte_InitValue_EcuT_Val (0.0F)
#  define Rte_InitValue_EcuTAdcFaild_Logl (FALSE)
#  define Rte_InitValue_HwTq4RawAdcAdcFaild_Logl (FALSE)
#  define Rte_InitValue_HwTq5RawAdcAdcFaild_Logl (FALSE)
#  define Rte_InitValue_MotCurrAdcVlyAAdcFaild_Logl (FALSE)
#  define Rte_InitValue_MotCurrAdcVlyBAdcFaild_Logl (FALSE)
#  define Rte_InitValue_MotCurrAdcVlyCAdcFaild_Logl (FALSE)
#  define Rte_InitValue_MotDrvr1IninTestCmpl_Logl (FALSE)
#  define Rte_InitValue_RvsBattDiagcGndAdc_Val (0.0F)
#  define Rte_InitValue_RvsBattDiagcGndAdcFaild_Logl (FALSE)
#  define Rte_InitValue_RvsBattDiagcRtnAdc_Val (0.0F)
#  define Rte_InitValue_RvsBattDiagcRtnAdcFaild_Logl (FALSE)
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_Adc0Faild_Logl Rte_Read_CDD_Bmw5441McuCfg_Adc0Faild_Logl
#  define Rte_Read_CDD_Bmw5441McuCfg_Adc0Faild_Logl(data) (*(data) = Rte_CDD_AdcDiagc_Adc0Faild_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_Adc1Faild_Logl Rte_Read_CDD_Bmw5441McuCfg_Adc1Faild_Logl
#  define Rte_Read_CDD_Bmw5441McuCfg_Adc1Faild_Logl(data) (*(data) = Rte_CDD_AdcDiagc_Adc1Faild_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_Adc1ScanGroup2Ref0_Val Rte_Write_CDD_Bmw5441McuCfg_Adc1ScanGroup2Ref0_Val
#  define Rte_Write_CDD_Bmw5441McuCfg_Adc1ScanGroup2Ref0_Val(data) (Rte_CDD_Bmw5441McuCfg_Adc1ScanGroup2Ref0_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_Adc1ScanGroup2Ref1_Val Rte_Write_CDD_Bmw5441McuCfg_Adc1ScanGroup2Ref1_Val
#  define Rte_Write_CDD_Bmw5441McuCfg_Adc1ScanGroup2Ref1_Val(data) (Rte_CDD_Bmw5441McuCfg_Adc1ScanGroup2Ref1_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_Adc1ScanGroup3Ref0_Val Rte_Write_CDD_Bmw5441McuCfg_Adc1ScanGroup3Ref0_Val
#  define Rte_Write_CDD_Bmw5441McuCfg_Adc1ScanGroup3Ref0_Val(data) (Rte_CDD_Bmw5441McuCfg_Adc1ScanGroup3Ref0_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_Adc1ScanGroup3Ref1_Val Rte_Write_CDD_Bmw5441McuCfg_Adc1ScanGroup3Ref1_Val
#  define Rte_Write_CDD_Bmw5441McuCfg_Adc1ScanGroup3Ref1_Val(data) (Rte_CDD_Bmw5441McuCfg_Adc1ScanGroup3Ref1_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_Adc1SelfDiag0_Val Rte_Write_CDD_Bmw5441McuCfg_Adc1SelfDiag0_Val
#  define Rte_Write_CDD_Bmw5441McuCfg_Adc1SelfDiag0_Val(data) (Rte_CDD_Bmw5441McuCfg_Adc1SelfDiag0_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_Adc1SelfDiag2_Val Rte_Write_CDD_Bmw5441McuCfg_Adc1SelfDiag2_Val
#  define Rte_Write_CDD_Bmw5441McuCfg_Adc1SelfDiag2_Val(data) (Rte_CDD_Bmw5441McuCfg_Adc1SelfDiag2_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_Adc1SelfDiag4_Val Rte_Write_CDD_Bmw5441McuCfg_Adc1SelfDiag4_Val
#  define Rte_Write_CDD_Bmw5441McuCfg_Adc1SelfDiag4_Val(data) (Rte_CDD_Bmw5441McuCfg_Adc1SelfDiag4_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_BattRtnCurrAdcFaild_Logl Rte_Write_CDD_Bmw5441McuCfg_BattRtnCurrAdcFaild_Logl
#  define Rte_Write_CDD_Bmw5441McuCfg_BattRtnCurrAdcFaild_Logl(data) (Rte_CDD_Bmw5441McuCfg_BattRtnCurrAdcFaild_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_BattVltg_Val Rte_Write_CDD_Bmw5441McuCfg_BattVltg_Val
#  define Rte_Write_CDD_Bmw5441McuCfg_BattVltg_Val(data) (Rte_CDD_Bmw5441McuCfg_BattVltg_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_BattVltgAdcFaild_Logl Rte_Write_CDD_Bmw5441McuCfg_BattVltgAdcFaild_Logl
#  define Rte_Write_CDD_Bmw5441McuCfg_BattVltgAdcFaild_Logl(data) (Rte_CDD_Bmw5441McuCfg_BattVltgAdcFaild_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_BattVltgSwd1_Val Rte_Write_CDD_Bmw5441McuCfg_BattVltgSwd1_Val
#  define Rte_Write_CDD_Bmw5441McuCfg_BattVltgSwd1_Val(data) (Rte_CDD_Bmw5441McuCfg_BattVltgSwd1_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_BattVltgSwd1AdcFaild_Logl Rte_Write_CDD_Bmw5441McuCfg_BattVltgSwd1AdcFaild_Logl
#  define Rte_Write_CDD_Bmw5441McuCfg_BattVltgSwd1AdcFaild_Logl(data) (Rte_CDD_Bmw5441McuCfg_BattVltgSwd1AdcFaild_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_EcuT_Val Rte_Write_CDD_Bmw5441McuCfg_EcuT_Val
#  define Rte_Write_CDD_Bmw5441McuCfg_EcuT_Val(data) (Rte_CDD_Bmw5441McuCfg_EcuT_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_EcuTAdcFaild_Logl Rte_Write_CDD_Bmw5441McuCfg_EcuTAdcFaild_Logl
#  define Rte_Write_CDD_Bmw5441McuCfg_EcuTAdcFaild_Logl(data) (Rte_CDD_Bmw5441McuCfg_EcuTAdcFaild_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_HwTq4RawAdcAdcFaild_Logl Rte_Write_CDD_Bmw5441McuCfg_HwTq4RawAdcAdcFaild_Logl
#  define Rte_Write_CDD_Bmw5441McuCfg_HwTq4RawAdcAdcFaild_Logl(data) (Rte_CDD_Bmw5441McuCfg_HwTq4RawAdcAdcFaild_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_HwTq5RawAdcAdcFaild_Logl Rte_Write_CDD_Bmw5441McuCfg_HwTq5RawAdcAdcFaild_Logl
#  define Rte_Write_CDD_Bmw5441McuCfg_HwTq5RawAdcAdcFaild_Logl(data) (Rte_CDD_Bmw5441McuCfg_HwTq5RawAdcAdcFaild_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_MotCurrAdcVlyAAdcFaild_Logl Rte_Write_CDD_Bmw5441McuCfg_MotCurrAdcVlyAAdcFaild_Logl
#  define Rte_Write_CDD_Bmw5441McuCfg_MotCurrAdcVlyAAdcFaild_Logl(data) (Rte_CDD_Bmw5441McuCfg_MotCurrAdcVlyAAdcFaild_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_MotCurrAdcVlyBAdcFaild_Logl Rte_Write_CDD_Bmw5441McuCfg_MotCurrAdcVlyBAdcFaild_Logl
#  define Rte_Write_CDD_Bmw5441McuCfg_MotCurrAdcVlyBAdcFaild_Logl(data) (Rte_CDD_Bmw5441McuCfg_MotCurrAdcVlyBAdcFaild_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_MotCurrAdcVlyCAdcFaild_Logl Rte_Write_CDD_Bmw5441McuCfg_MotCurrAdcVlyCAdcFaild_Logl
#  define Rte_Write_CDD_Bmw5441McuCfg_MotCurrAdcVlyCAdcFaild_Logl(data) (Rte_CDD_Bmw5441McuCfg_MotCurrAdcVlyCAdcFaild_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_MotDrvr1IninTestCmpl_Logl Rte_Write_CDD_Bmw5441McuCfg_MotDrvr1IninTestCmpl_Logl
#  define Rte_Write_CDD_Bmw5441McuCfg_MotDrvr1IninTestCmpl_Logl(data) (Rte_CDD_Bmw5441McuCfg_MotDrvr1IninTestCmpl_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_RvsBattDiagcGndAdc_Val Rte_Write_CDD_Bmw5441McuCfg_RvsBattDiagcGndAdc_Val
#  define Rte_Write_CDD_Bmw5441McuCfg_RvsBattDiagcGndAdc_Val(data) (Rte_CDD_Bmw5441McuCfg_RvsBattDiagcGndAdc_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_RvsBattDiagcGndAdcFaild_Logl Rte_Write_CDD_Bmw5441McuCfg_RvsBattDiagcGndAdcFaild_Logl
#  define Rte_Write_CDD_Bmw5441McuCfg_RvsBattDiagcGndAdcFaild_Logl(data) (Rte_CDD_Bmw5441McuCfg_RvsBattDiagcGndAdcFaild_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_RvsBattDiagcRtnAdc_Val Rte_Write_CDD_Bmw5441McuCfg_RvsBattDiagcRtnAdc_Val
#  define Rte_Write_CDD_Bmw5441McuCfg_RvsBattDiagcRtnAdc_Val(data) (Rte_CDD_Bmw5441McuCfg_RvsBattDiagcRtnAdc_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_RvsBattDiagcRtnAdcFaild_Logl Rte_Write_CDD_Bmw5441McuCfg_RvsBattDiagcRtnAdcFaild_Logl
#  define Rte_Write_CDD_Bmw5441McuCfg_RvsBattDiagcRtnAdcFaild_Logl(data) (Rte_CDD_Bmw5441McuCfg_RvsBattDiagcRtnAdcFaild_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_CDD_NXTRTI_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_CDD_NXTRTI_APPL_CODE) GetRefTmr1MicroSec32bit_Oper(P2VAR(uint32, AUTOMATIC, RTE_CDD_NXTRTI_APPL_VAR) RefTmr_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CDD_NXTRTI_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_GetRefTmr1MicroSec32bit_Oper(arg1) (GetRefTmr1MicroSec32bit_Oper(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_CDD_NXTRTI_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_CDD_NXTRTI_APPL_CODE) GetTiSpan1MicroSec32bit_Oper(uint32 RefTmr_Arg, P2VAR(uint32, AUTOMATIC, RTE_CDD_NXTRTI_APPL_VAR) TiSpan_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CDD_NXTRTI_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_GetTiSpan1MicroSec32bit_Oper(arg1, arg2) (GetTiSpan1MicroSec32bit_Oper(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define CDD_Bmw5441McuCfg_START_SEC_CODE
# include "CDD_Bmw5441McuCfg_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_Bmw5441McuCfgInit1 Bmw5441McuCfgInit1
#  define RTE_RUNNABLE_Bmw5441McuCfgInit2 Bmw5441McuCfgInit2
#  define RTE_RUNNABLE_Bmw5441McuCfgInit3 Bmw5441McuCfgInit3
#  define RTE_RUNNABLE_Bmw5441McuCfgPer2 Bmw5441McuCfgPer2
#  define RTE_RUNNABLE_Bmw5441McuCfgPer3 Bmw5441McuCfgPer3
# endif

FUNC(void, CDD_Bmw5441McuCfg_CODE) Bmw5441McuCfgInit1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CDD_Bmw5441McuCfg_CODE) Bmw5441McuCfgInit2(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CDD_Bmw5441McuCfg_CODE) Bmw5441McuCfgInit3(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CDD_Bmw5441McuCfg_CODE) Bmw5441McuCfgPer2(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CDD_Bmw5441McuCfg_CODE) Bmw5441McuCfgPer3(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define CDD_Bmw5441McuCfg_STOP_SEC_CODE
# include "CDD_Bmw5441McuCfg_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CDD_BMW5441MCUCFG_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
