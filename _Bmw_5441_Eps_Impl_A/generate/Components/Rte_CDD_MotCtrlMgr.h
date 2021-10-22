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
 *          File:  Rte_CDD_MotCtrlMgr.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <CDD_MotCtrlMgr>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CDD_MOTCTRLMGR_H
# define _RTE_CDD_MOTCTRLMGR_H

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

# include "Rte_CDD_MotCtrlMgr_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_Appl9_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_INIT) Rte_EcuTMeas_EcuTFild_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwVehSpd_VehSpd_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_Appl9_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_Adc0ScanGroup2Ref0_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_Adc0ScanGroup2Ref1_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_Adc0ScanGroup3Ref0_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_Adc0ScanGroup3Ref1_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_Adc0SelfDiag0_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_Adc0SelfDiag2_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_Adc0SelfDiag4_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_BattRtnCurrAdc_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_BattVltgAdc_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint16, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_FastLoopCntr_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_HwTq4RawAdc_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_HwTq5RawAdc_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotAg0ErrReg_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(u0p16, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotAg0Mecl_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotAg0MeclRollgCntr_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint16, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotAg0ParFltCnt_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint16, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotAg0SpiMecl_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotAg0TurnCntrReg_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint16, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotAg0VltgFltCnt_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotAg0WarnReg_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotAg1ErrReg_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(u0p16, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotAg1Mecl_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotAg1MeclRollgCntr_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint16, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotAg1ParFltCnt_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint16, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotAg1SpiMecl_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotAg1TurnCntrReg_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint16, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotAg1VltgFltCnt_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotAg1WarnReg_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint16, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotAg3Mecl_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint16, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotAg4Mecl_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotAgBufIdx_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(s15p16, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotAgCumvAlgndMrfRev_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotAgCumvInid_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotCurrAdcVlyA_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotCurrAdcVlyB_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotCurrAdcVlyC_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotCurrCorrdA_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotCurrCorrdB_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotCurrCorrdC_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotCurrDax_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotCurrQax_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotCurrRollgCntr1_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotVltgDax_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotVltgQax_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint16, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_Ntc5DErrCnt_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_PhaOnTiSumA_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_PhaOnTiSumB_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_PhaOnTiSumC_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint16, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_SlowLoopCntr_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_INIT) Rte_CDD_AdcDiagc_AdcDiagcEndPtrOutp_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_INIT) Rte_CDD_AdcDiagc_AdcDiagcStrtPtrOutp_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BattVltg_BrdgVltg_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_INIT) Rte_CurrMeasCorrln_CurrMeasCorrlnSts_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_CDD_CurrMeas_CurrMeasWrmIninTestCmpl_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_GateDrv0Ctrl_DiagcStsIvtr1Inactv_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(IvtrFetFltPha1, RTE_VAR_INIT) Rte_GateDrv0Ctrl_IvtrFetFltPha_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(IvtrFetFltTyp1, RTE_VAR_INIT) Rte_GateDrv0Ctrl_IvtrFetFltTyp_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint16, RTE_VAR_INIT) Rte_CDD_McuDiagc_LoopCntr2MilliSec_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_CDD_MotAg0Meas_MotAg0QepFaild_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_CDD_MotAg1Meas_MotAg1QepFaild_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_MotCurrRegCfg_MotAgElecDly_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_INIT) Rte_LoaMgr_MotAndThermProtnLoaMod_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_MotRefMdl_MotBackEmfVltg_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_CDD_Bmw5441McuCfg_MotCurrAdcVlyAAdcFaild_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_CDD_Bmw5441McuCfg_MotCurrAdcVlyBAdcFaild_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_CDD_Bmw5441McuCfg_MotCurrAdcVlyCAdcFaild_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_MotRefMdl_MotCurrDaxCmd_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_MotRefMdl_MotCurrDaxMax_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(MotCurrEolCalSt2, RTE_VAR_INIT) Rte_CDD_CurrMeas_MotCurrEolCalSt_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_MotRefMdl_MotCurrQaxCmd_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(SigQlfr1, RTE_VAR_INIT) Rte_CDD_CurrMeas_MotCurrQlfr1_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_MotCurrRegCfg_MotDampgDax_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_MotCurrRegCfg_MotDampgQax_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(sint8, RTE_VAR_INIT) Rte_PolarityCfg_MotElecMeclPolarity_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_MotCtrlPrmEstimn_MotInduDaxEstimdIvs_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_MotCtrlPrmEstimn_MotInduQaxEstimdIvs_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_MotCurrRegCfg_MotIntglGainDax_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_MotCurrRegCfg_MotIntglGainQax_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_MotCurrRegCfg_MotPropGainDax_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_MotCurrRegCfg_MotPropGainQax_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_MotCtrlPrmEstimn_MotREstimd_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_MotRefMdl_MotReacncDax_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_MotRefMdl_MotReacncQax_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_MotVel_MotVelMrf_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_MotRefMdl_MotVltgDaxFf_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_MotRefMdl_MotVltgQaxFf_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_PhaDiscnct_PhaDiscnctDiagcActv_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(PhaDiscnctPwmVect1, RTE_VAR_INIT) Rte_PhaDiscnct_PhaDiscnctDiagcPwmVect_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(SysSt1, RTE_VAR_INIT) Rte_SysStMod_SysSt_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_Adc0ScanGroup2Ref0_Val (0.0F)
#  define Rte_InitValue_Adc0ScanGroup2Ref1_Val (0.0F)
#  define Rte_InitValue_Adc0ScanGroup3Ref0_Val (0.0F)
#  define Rte_InitValue_Adc0ScanGroup3Ref1_Val (0.0F)
#  define Rte_InitValue_Adc0SelfDiag0_Val (0.0F)
#  define Rte_InitValue_Adc0SelfDiag2_Val (0.0F)
#  define Rte_InitValue_Adc0SelfDiag4_Val (0.0F)
#  define Rte_InitValue_AdcDiagcEndPtrOutp_Val (23U)
#  define Rte_InitValue_AdcDiagcStrtPtrOutp_Val (21U)
#  define Rte_InitValue_BattRtnCurrAdc_Val (0.0F)
#  define Rte_InitValue_BattVltgAdc_Val (0.0F)
#  define Rte_InitValue_BrdgVltg_Val (6.0F)
#  define Rte_InitValue_CurrMeasCorrlnSts_Val (0U)
#  define Rte_InitValue_CurrMeasWrmIninTestCmpl_Logl (FALSE)
#  define Rte_InitValue_DiagcStsIvtr1Inactv_Logl (FALSE)
#  define Rte_InitValue_EcuTFild_Val (25.0F)
#  define Rte_InitValue_FastLoopCntr_Val (0U)
#  define Rte_InitValue_HwTq4RawAdc_Val (0.0F)
#  define Rte_InitValue_HwTq5RawAdc_Val (0.0F)
#  define Rte_InitValue_IvtrFetFltPha_Val (0U)
#  define Rte_InitValue_IvtrFetFltTyp_Val (0U)
#  define Rte_InitValue_LoopCntr2MilliSec_Val (0U)
#  define Rte_InitValue_MotAg0ErrReg_Val (0U)
#  define Rte_InitValue_MotAg0Mecl_Val (0U)
#  define Rte_InitValue_MotAg0MeclRollgCntr_Val (0U)
#  define Rte_InitValue_MotAg0ParFltCnt_Val (0U)
#  define Rte_InitValue_MotAg0QepFaild_Logl (FALSE)
#  define Rte_InitValue_MotAg0SpiMecl_Val (0U)
#  define Rte_InitValue_MotAg0TurnCntrReg_Val (0U)
#  define Rte_InitValue_MotAg0VltgFltCnt_Val (0U)
#  define Rte_InitValue_MotAg0WarnReg_Val (0U)
#  define Rte_InitValue_MotAg1ErrReg_Val (0U)
#  define Rte_InitValue_MotAg1Mecl_Val (0U)
#  define Rte_InitValue_MotAg1MeclRollgCntr_Val (0U)
#  define Rte_InitValue_MotAg1ParFltCnt_Val (0U)
#  define Rte_InitValue_MotAg1QepFaild_Logl (FALSE)
#  define Rte_InitValue_MotAg1SpiMecl_Val (0U)
#  define Rte_InitValue_MotAg1TurnCntrReg_Val (0U)
#  define Rte_InitValue_MotAg1VltgFltCnt_Val (0U)
#  define Rte_InitValue_MotAg1WarnReg_Val (0U)
#  define Rte_InitValue_MotAg3Mecl_Val (0U)
#  define Rte_InitValue_MotAg4Mecl_Val (0U)
#  define Rte_InitValue_MotAgBufIdx_Val (0U)
#  define Rte_InitValue_MotAgCumvAlgndMrfRev_Val (0)
#  define Rte_InitValue_MotAgCumvInid_Logl (FALSE)
#  define Rte_InitValue_MotAgElecDly_Val (0.0F)
#  define Rte_InitValue_MotAndThermProtnLoaMod_Val (0U)
#  define Rte_InitValue_MotBackEmfVltg_Val (0.0F)
#  define Rte_InitValue_MotCurrAdcVlyA_Val (0.0F)
#  define Rte_InitValue_MotCurrAdcVlyAAdcFaild_Logl (FALSE)
#  define Rte_InitValue_MotCurrAdcVlyB_Val (0.0F)
#  define Rte_InitValue_MotCurrAdcVlyBAdcFaild_Logl (FALSE)
#  define Rte_InitValue_MotCurrAdcVlyC_Val (0.0F)
#  define Rte_InitValue_MotCurrAdcVlyCAdcFaild_Logl (FALSE)
#  define Rte_InitValue_MotCurrCorrdA_Val (0.0F)
#  define Rte_InitValue_MotCurrCorrdB_Val (0.0F)
#  define Rte_InitValue_MotCurrCorrdC_Val (0.0F)
#  define Rte_InitValue_MotCurrDax_Val (0.0F)
#  define Rte_InitValue_MotCurrDaxCmd_Val (0.0F)
#  define Rte_InitValue_MotCurrDaxMax_Val (0.0F)
#  define Rte_InitValue_MotCurrEolCalSt_Val (0U)
#  define Rte_InitValue_MotCurrQax_Val (0.0F)
#  define Rte_InitValue_MotCurrQaxCmd_Val (0.0F)
#  define Rte_InitValue_MotCurrQlfr1_Val (0U)
#  define Rte_InitValue_MotCurrRollgCntr1_Val (0U)
#  define Rte_InitValue_MotDampgDax_Val (0.0F)
#  define Rte_InitValue_MotDampgQax_Val (0.0F)
#  define Rte_InitValue_MotElecMeclPolarity_Val (1)
#  define Rte_InitValue_MotInduDaxEstimdIvs_Val (0.0F)
#  define Rte_InitValue_MotInduQaxEstimdIvs_Val (0.0F)
#  define Rte_InitValue_MotIntglGainDax_Val (0.0F)
#  define Rte_InitValue_MotIntglGainQax_Val (0.0F)
#  define Rte_InitValue_MotPropGainDax_Val (0.0F)
#  define Rte_InitValue_MotPropGainQax_Val (0.0F)
#  define Rte_InitValue_MotREstimd_Val (0.0139083F)
#  define Rte_InitValue_MotReacncDax_Val (0.0F)
#  define Rte_InitValue_MotReacncQax_Val (0.0F)
#  define Rte_InitValue_MotVelMrf_Val (0.0F)
#  define Rte_InitValue_MotVltgDax_Val (0.0F)
#  define Rte_InitValue_MotVltgDaxFf_Val (0.0F)
#  define Rte_InitValue_MotVltgQax_Val (0.0F)
#  define Rte_InitValue_MotVltgQaxFf_Val (0.0F)
#  define Rte_InitValue_Ntc5DErrCnt_Val (0U)
#  define Rte_InitValue_PhaDiscnctDiagcActv_Logl (FALSE)
#  define Rte_InitValue_PhaDiscnctDiagcPwmVect_Val (0U)
#  define Rte_InitValue_PhaOnTiSumA_Val (0U)
#  define Rte_InitValue_PhaOnTiSumB_Val (0U)
#  define Rte_InitValue_PhaOnTiSumC_Val (0U)
#  define Rte_InitValue_SlowLoopCntr_Val (0U)
#  define Rte_InitValue_SysSt_Val (3U)
#  define Rte_InitValue_VehSpd_Val (0.0F)
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_MotCtrlMgr_HwTq4RawFastAdcBuf_Ary1D(P2CONST(float32, AUTOMATIC, RTE_CDD_MOTCTRLMGR_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_MotCtrlMgr_HwTq4RawFastAdcBuf_Ary1D(P2CONST(Ary1D_f32_8, AUTOMATIC, RTE_CDD_MOTCTRLMGR_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_MotCtrlMgr_HwTq5RawFastAdcBuf_Ary1D(P2CONST(float32, AUTOMATIC, RTE_CDD_MOTCTRLMGR_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_MotCtrlMgr_HwTq5RawFastAdcBuf_Ary1D(P2CONST(Ary1D_f32_8, AUTOMATIC, RTE_CDD_MOTCTRLMGR_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_MotCtrlMgr_MotAgBuf_Ary1D(P2CONST(u0p16, AUTOMATIC, RTE_CDD_MOTCTRLMGR_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_MotCtrlMgr_MotAgBuf_Ary1D(P2CONST(Ary1D_u0p16_8, AUTOMATIC, RTE_CDD_MOTCTRLMGR_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_MotCtrlMgr_MotAgTiBuf_Ary1D(P2CONST(uint32, AUTOMATIC, RTE_CDD_MOTCTRLMGR_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_MotCtrlMgr_MotAgTiBuf_Ary1D(P2CONST(Ary1D_u32_8, AUTOMATIC, RTE_CDD_MOTCTRLMGR_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_AdcDiagcEndPtrOutp_Val Rte_Read_CDD_MotCtrlMgr_AdcDiagcEndPtrOutp_Val
#  define Rte_Read_CDD_MotCtrlMgr_AdcDiagcEndPtrOutp_Val(data) (*(data) = Rte_CDD_AdcDiagc_AdcDiagcEndPtrOutp_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_AdcDiagcStrtPtrOutp_Val Rte_Read_CDD_MotCtrlMgr_AdcDiagcStrtPtrOutp_Val
#  define Rte_Read_CDD_MotCtrlMgr_AdcDiagcStrtPtrOutp_Val(data) (*(data) = Rte_CDD_AdcDiagc_AdcDiagcStrtPtrOutp_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BrdgVltg_Val Rte_Read_CDD_MotCtrlMgr_BrdgVltg_Val
#  define Rte_Read_CDD_MotCtrlMgr_BrdgVltg_Val(data) (*(data) = Rte_BattVltg_BrdgVltg_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_CurrMeasCorrlnSts_Val Rte_Read_CDD_MotCtrlMgr_CurrMeasCorrlnSts_Val
#  define Rte_Read_CDD_MotCtrlMgr_CurrMeasCorrlnSts_Val(data) (*(data) = Rte_CurrMeasCorrln_CurrMeasCorrlnSts_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_CurrMeasWrmIninTestCmpl_Logl Rte_Read_CDD_MotCtrlMgr_CurrMeasWrmIninTestCmpl_Logl
#  define Rte_Read_CDD_MotCtrlMgr_CurrMeasWrmIninTestCmpl_Logl(data) (*(data) = Rte_CDD_CurrMeas_CurrMeasWrmIninTestCmpl_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_DiagcStsIvtr1Inactv_Logl Rte_Read_CDD_MotCtrlMgr_DiagcStsIvtr1Inactv_Logl
#  define Rte_Read_CDD_MotCtrlMgr_DiagcStsIvtr1Inactv_Logl(data) (*(data) = Rte_GateDrv0Ctrl_DiagcStsIvtr1Inactv_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_EcuTFild_Val Rte_Read_CDD_MotCtrlMgr_EcuTFild_Val
#  define Rte_Read_CDD_MotCtrlMgr_EcuTFild_Val(data) (*(data) = Rte_EcuTMeas_EcuTFild_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_IvtrFetFltPha_Val Rte_Read_CDD_MotCtrlMgr_IvtrFetFltPha_Val
#  define Rte_Read_CDD_MotCtrlMgr_IvtrFetFltPha_Val(data) (*(data) = Rte_GateDrv0Ctrl_IvtrFetFltPha_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_IvtrFetFltTyp_Val Rte_Read_CDD_MotCtrlMgr_IvtrFetFltTyp_Val
#  define Rte_Read_CDD_MotCtrlMgr_IvtrFetFltTyp_Val(data) (*(data) = Rte_GateDrv0Ctrl_IvtrFetFltTyp_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_LoopCntr2MilliSec_Val Rte_Read_CDD_MotCtrlMgr_LoopCntr2MilliSec_Val
#  define Rte_Read_CDD_MotCtrlMgr_LoopCntr2MilliSec_Val(data) (*(data) = Rte_CDD_McuDiagc_LoopCntr2MilliSec_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotAg0QepFaild_Logl Rte_Read_CDD_MotCtrlMgr_MotAg0QepFaild_Logl
#  define Rte_Read_CDD_MotCtrlMgr_MotAg0QepFaild_Logl(data) (*(data) = Rte_CDD_MotAg0Meas_MotAg0QepFaild_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotAg1QepFaild_Logl Rte_Read_CDD_MotCtrlMgr_MotAg1QepFaild_Logl
#  define Rte_Read_CDD_MotCtrlMgr_MotAg1QepFaild_Logl(data) (*(data) = Rte_CDD_MotAg1Meas_MotAg1QepFaild_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotAgElecDly_Val Rte_Read_CDD_MotCtrlMgr_MotAgElecDly_Val
#  define Rte_Read_CDD_MotCtrlMgr_MotAgElecDly_Val(data) (*(data) = Rte_MotCurrRegCfg_MotAgElecDly_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotAndThermProtnLoaMod_Val Rte_Read_CDD_MotCtrlMgr_MotAndThermProtnLoaMod_Val
#  define Rte_Read_CDD_MotCtrlMgr_MotAndThermProtnLoaMod_Val(data) (*(data) = Rte_LoaMgr_MotAndThermProtnLoaMod_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotBackEmfVltg_Val Rte_Read_CDD_MotCtrlMgr_MotBackEmfVltg_Val
#  define Rte_Read_CDD_MotCtrlMgr_MotBackEmfVltg_Val(data) (*(data) = Rte_MotRefMdl_MotBackEmfVltg_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotCurrAdcVlyAAdcFaild_Logl Rte_Read_CDD_MotCtrlMgr_MotCurrAdcVlyAAdcFaild_Logl
#  define Rte_Read_CDD_MotCtrlMgr_MotCurrAdcVlyAAdcFaild_Logl(data) (*(data) = Rte_CDD_Bmw5441McuCfg_MotCurrAdcVlyAAdcFaild_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotCurrAdcVlyBAdcFaild_Logl Rte_Read_CDD_MotCtrlMgr_MotCurrAdcVlyBAdcFaild_Logl
#  define Rte_Read_CDD_MotCtrlMgr_MotCurrAdcVlyBAdcFaild_Logl(data) (*(data) = Rte_CDD_Bmw5441McuCfg_MotCurrAdcVlyBAdcFaild_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotCurrAdcVlyCAdcFaild_Logl Rte_Read_CDD_MotCtrlMgr_MotCurrAdcVlyCAdcFaild_Logl
#  define Rte_Read_CDD_MotCtrlMgr_MotCurrAdcVlyCAdcFaild_Logl(data) (*(data) = Rte_CDD_Bmw5441McuCfg_MotCurrAdcVlyCAdcFaild_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotCurrDaxCmd_Val Rte_Read_CDD_MotCtrlMgr_MotCurrDaxCmd_Val
#  define Rte_Read_CDD_MotCtrlMgr_MotCurrDaxCmd_Val(data) (*(data) = Rte_MotRefMdl_MotCurrDaxCmd_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotCurrDaxMax_Val Rte_Read_CDD_MotCtrlMgr_MotCurrDaxMax_Val
#  define Rte_Read_CDD_MotCtrlMgr_MotCurrDaxMax_Val(data) (*(data) = Rte_MotRefMdl_MotCurrDaxMax_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotCurrEolCalSt_Val Rte_Read_CDD_MotCtrlMgr_MotCurrEolCalSt_Val
#  define Rte_Read_CDD_MotCtrlMgr_MotCurrEolCalSt_Val(data) (*(data) = Rte_CDD_CurrMeas_MotCurrEolCalSt_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotCurrQaxCmd_Val Rte_Read_CDD_MotCtrlMgr_MotCurrQaxCmd_Val
#  define Rte_Read_CDD_MotCtrlMgr_MotCurrQaxCmd_Val(data) (*(data) = Rte_MotRefMdl_MotCurrQaxCmd_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotCurrQlfr1_Val Rte_Read_CDD_MotCtrlMgr_MotCurrQlfr1_Val
#  define Rte_Read_CDD_MotCtrlMgr_MotCurrQlfr1_Val(data) (*(data) = Rte_CDD_CurrMeas_MotCurrQlfr1_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotDampgDax_Val Rte_Read_CDD_MotCtrlMgr_MotDampgDax_Val
#  define Rte_Read_CDD_MotCtrlMgr_MotDampgDax_Val(data) (*(data) = Rte_MotCurrRegCfg_MotDampgDax_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotDampgQax_Val Rte_Read_CDD_MotCtrlMgr_MotDampgQax_Val
#  define Rte_Read_CDD_MotCtrlMgr_MotDampgQax_Val(data) (*(data) = Rte_MotCurrRegCfg_MotDampgQax_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotElecMeclPolarity_Val Rte_Read_CDD_MotCtrlMgr_MotElecMeclPolarity_Val
#  define Rte_Read_CDD_MotCtrlMgr_MotElecMeclPolarity_Val(data) (*(data) = Rte_PolarityCfg_MotElecMeclPolarity_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotInduDaxEstimdIvs_Val Rte_Read_CDD_MotCtrlMgr_MotInduDaxEstimdIvs_Val
#  define Rte_Read_CDD_MotCtrlMgr_MotInduDaxEstimdIvs_Val(data) (*(data) = Rte_MotCtrlPrmEstimn_MotInduDaxEstimdIvs_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotInduQaxEstimdIvs_Val Rte_Read_CDD_MotCtrlMgr_MotInduQaxEstimdIvs_Val
#  define Rte_Read_CDD_MotCtrlMgr_MotInduQaxEstimdIvs_Val(data) (*(data) = Rte_MotCtrlPrmEstimn_MotInduQaxEstimdIvs_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotIntglGainDax_Val Rte_Read_CDD_MotCtrlMgr_MotIntglGainDax_Val
#  define Rte_Read_CDD_MotCtrlMgr_MotIntglGainDax_Val(data) (*(data) = Rte_MotCurrRegCfg_MotIntglGainDax_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotIntglGainQax_Val Rte_Read_CDD_MotCtrlMgr_MotIntglGainQax_Val
#  define Rte_Read_CDD_MotCtrlMgr_MotIntglGainQax_Val(data) (*(data) = Rte_MotCurrRegCfg_MotIntglGainQax_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotPropGainDax_Val Rte_Read_CDD_MotCtrlMgr_MotPropGainDax_Val
#  define Rte_Read_CDD_MotCtrlMgr_MotPropGainDax_Val(data) (*(data) = Rte_MotCurrRegCfg_MotPropGainDax_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotPropGainQax_Val Rte_Read_CDD_MotCtrlMgr_MotPropGainQax_Val
#  define Rte_Read_CDD_MotCtrlMgr_MotPropGainQax_Val(data) (*(data) = Rte_MotCurrRegCfg_MotPropGainQax_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotREstimd_Val Rte_Read_CDD_MotCtrlMgr_MotREstimd_Val
#  define Rte_Read_CDD_MotCtrlMgr_MotREstimd_Val(data) (*(data) = Rte_MotCtrlPrmEstimn_MotREstimd_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotReacncDax_Val Rte_Read_CDD_MotCtrlMgr_MotReacncDax_Val
#  define Rte_Read_CDD_MotCtrlMgr_MotReacncDax_Val(data) (*(data) = Rte_MotRefMdl_MotReacncDax_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotReacncQax_Val Rte_Read_CDD_MotCtrlMgr_MotReacncQax_Val
#  define Rte_Read_CDD_MotCtrlMgr_MotReacncQax_Val(data) (*(data) = Rte_MotRefMdl_MotReacncQax_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotVelMrf_Val Rte_Read_CDD_MotCtrlMgr_MotVelMrf_Val
#  define Rte_Read_CDD_MotCtrlMgr_MotVelMrf_Val(data) (*(data) = Rte_CDD_MotVel_MotVelMrf_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotVltgDaxFf_Val Rte_Read_CDD_MotCtrlMgr_MotVltgDaxFf_Val
#  define Rte_Read_CDD_MotCtrlMgr_MotVltgDaxFf_Val(data) (*(data) = Rte_MotRefMdl_MotVltgDaxFf_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotVltgQaxFf_Val Rte_Read_CDD_MotCtrlMgr_MotVltgQaxFf_Val
#  define Rte_Read_CDD_MotCtrlMgr_MotVltgQaxFf_Val(data) (*(data) = Rte_MotRefMdl_MotVltgQaxFf_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_PhaDiscnctDiagcActv_Logl Rte_Read_CDD_MotCtrlMgr_PhaDiscnctDiagcActv_Logl
#  define Rte_Read_CDD_MotCtrlMgr_PhaDiscnctDiagcActv_Logl(data) (*(data) = Rte_PhaDiscnct_PhaDiscnctDiagcActv_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_PhaDiscnctDiagcPwmVect_Val Rte_Read_CDD_MotCtrlMgr_PhaDiscnctDiagcPwmVect_Val
#  define Rte_Read_CDD_MotCtrlMgr_PhaDiscnctDiagcPwmVect_Val(data) (*(data) = Rte_PhaDiscnct_PhaDiscnctDiagcPwmVect_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_SysSt_Val Rte_Read_CDD_MotCtrlMgr_SysSt_Val
#  define Rte_Read_CDD_MotCtrlMgr_SysSt_Val(data) (*(data) = Rte_SysStMod_SysSt_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_VehSpd_Val Rte_Read_CDD_MotCtrlMgr_VehSpd_Val
#  define Rte_Read_CDD_MotCtrlMgr_VehSpd_Val(data) (*(data) = Rte_BmwVehSpd_VehSpd_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_Adc0ScanGroup2Ref0_Val Rte_Write_CDD_MotCtrlMgr_Adc0ScanGroup2Ref0_Val
#  define Rte_Write_CDD_MotCtrlMgr_Adc0ScanGroup2Ref0_Val(data) (Rte_CDD_MotCtrlMgr_Adc0ScanGroup2Ref0_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_Adc0ScanGroup2Ref1_Val Rte_Write_CDD_MotCtrlMgr_Adc0ScanGroup2Ref1_Val
#  define Rte_Write_CDD_MotCtrlMgr_Adc0ScanGroup2Ref1_Val(data) (Rte_CDD_MotCtrlMgr_Adc0ScanGroup2Ref1_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_Adc0ScanGroup3Ref0_Val Rte_Write_CDD_MotCtrlMgr_Adc0ScanGroup3Ref0_Val
#  define Rte_Write_CDD_MotCtrlMgr_Adc0ScanGroup3Ref0_Val(data) (Rte_CDD_MotCtrlMgr_Adc0ScanGroup3Ref0_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_Adc0ScanGroup3Ref1_Val Rte_Write_CDD_MotCtrlMgr_Adc0ScanGroup3Ref1_Val
#  define Rte_Write_CDD_MotCtrlMgr_Adc0ScanGroup3Ref1_Val(data) (Rte_CDD_MotCtrlMgr_Adc0ScanGroup3Ref1_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_Adc0SelfDiag0_Val Rte_Write_CDD_MotCtrlMgr_Adc0SelfDiag0_Val
#  define Rte_Write_CDD_MotCtrlMgr_Adc0SelfDiag0_Val(data) (Rte_CDD_MotCtrlMgr_Adc0SelfDiag0_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_Adc0SelfDiag2_Val Rte_Write_CDD_MotCtrlMgr_Adc0SelfDiag2_Val
#  define Rte_Write_CDD_MotCtrlMgr_Adc0SelfDiag2_Val(data) (Rte_CDD_MotCtrlMgr_Adc0SelfDiag2_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_Adc0SelfDiag4_Val Rte_Write_CDD_MotCtrlMgr_Adc0SelfDiag4_Val
#  define Rte_Write_CDD_MotCtrlMgr_Adc0SelfDiag4_Val(data) (Rte_CDD_MotCtrlMgr_Adc0SelfDiag4_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_BattRtnCurrAdc_Val Rte_Write_CDD_MotCtrlMgr_BattRtnCurrAdc_Val
#  define Rte_Write_CDD_MotCtrlMgr_BattRtnCurrAdc_Val(data) (Rte_CDD_MotCtrlMgr_BattRtnCurrAdc_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_BattVltgAdc_Val Rte_Write_CDD_MotCtrlMgr_BattVltgAdc_Val
#  define Rte_Write_CDD_MotCtrlMgr_BattVltgAdc_Val(data) (Rte_CDD_MotCtrlMgr_BattVltgAdc_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_FastLoopCntr_Val Rte_Write_CDD_MotCtrlMgr_FastLoopCntr_Val
#  define Rte_Write_CDD_MotCtrlMgr_FastLoopCntr_Val(data) (Rte_CDD_MotCtrlMgr_FastLoopCntr_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_HwTq4RawAdc_Val Rte_Write_CDD_MotCtrlMgr_HwTq4RawAdc_Val
#  define Rte_Write_CDD_MotCtrlMgr_HwTq4RawAdc_Val(data) (Rte_CDD_MotCtrlMgr_HwTq4RawAdc_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_HwTq4RawFastAdcBuf_Ary1D Rte_Write_CDD_MotCtrlMgr_HwTq4RawFastAdcBuf_Ary1D
#  define Rte_Write_HwTq5RawAdc_Val Rte_Write_CDD_MotCtrlMgr_HwTq5RawAdc_Val
#  define Rte_Write_CDD_MotCtrlMgr_HwTq5RawAdc_Val(data) (Rte_CDD_MotCtrlMgr_HwTq5RawAdc_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_HwTq5RawFastAdcBuf_Ary1D Rte_Write_CDD_MotCtrlMgr_HwTq5RawFastAdcBuf_Ary1D
#  define Rte_Write_MotAg0ErrReg_Val Rte_Write_CDD_MotCtrlMgr_MotAg0ErrReg_Val
#  define Rte_Write_CDD_MotCtrlMgr_MotAg0ErrReg_Val(data) (Rte_CDD_MotCtrlMgr_MotAg0ErrReg_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_MotAg0Mecl_Val Rte_Write_CDD_MotCtrlMgr_MotAg0Mecl_Val
#  define Rte_Write_CDD_MotCtrlMgr_MotAg0Mecl_Val(data) (Rte_CDD_MotCtrlMgr_MotAg0Mecl_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_MotAg0MeclRollgCntr_Val Rte_Write_CDD_MotCtrlMgr_MotAg0MeclRollgCntr_Val
#  define Rte_Write_CDD_MotCtrlMgr_MotAg0MeclRollgCntr_Val(data) (Rte_CDD_MotCtrlMgr_MotAg0MeclRollgCntr_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_MotAg0ParFltCnt_Val Rte_Write_CDD_MotCtrlMgr_MotAg0ParFltCnt_Val
#  define Rte_Write_CDD_MotCtrlMgr_MotAg0ParFltCnt_Val(data) (Rte_CDD_MotCtrlMgr_MotAg0ParFltCnt_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_MotAg0SpiMecl_Val Rte_Write_CDD_MotCtrlMgr_MotAg0SpiMecl_Val
#  define Rte_Write_CDD_MotCtrlMgr_MotAg0SpiMecl_Val(data) (Rte_CDD_MotCtrlMgr_MotAg0SpiMecl_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_MotAg0TurnCntrReg_Val Rte_Write_CDD_MotCtrlMgr_MotAg0TurnCntrReg_Val
#  define Rte_Write_CDD_MotCtrlMgr_MotAg0TurnCntrReg_Val(data) (Rte_CDD_MotCtrlMgr_MotAg0TurnCntrReg_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_MotAg0VltgFltCnt_Val Rte_Write_CDD_MotCtrlMgr_MotAg0VltgFltCnt_Val
#  define Rte_Write_CDD_MotCtrlMgr_MotAg0VltgFltCnt_Val(data) (Rte_CDD_MotCtrlMgr_MotAg0VltgFltCnt_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_MotAg0WarnReg_Val Rte_Write_CDD_MotCtrlMgr_MotAg0WarnReg_Val
#  define Rte_Write_CDD_MotCtrlMgr_MotAg0WarnReg_Val(data) (Rte_CDD_MotCtrlMgr_MotAg0WarnReg_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_MotAg1ErrReg_Val Rte_Write_CDD_MotCtrlMgr_MotAg1ErrReg_Val
#  define Rte_Write_CDD_MotCtrlMgr_MotAg1ErrReg_Val(data) (Rte_CDD_MotCtrlMgr_MotAg1ErrReg_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_MotAg1Mecl_Val Rte_Write_CDD_MotCtrlMgr_MotAg1Mecl_Val
#  define Rte_Write_CDD_MotCtrlMgr_MotAg1Mecl_Val(data) (Rte_CDD_MotCtrlMgr_MotAg1Mecl_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_MotAg1MeclRollgCntr_Val Rte_Write_CDD_MotCtrlMgr_MotAg1MeclRollgCntr_Val
#  define Rte_Write_CDD_MotCtrlMgr_MotAg1MeclRollgCntr_Val(data) (Rte_CDD_MotCtrlMgr_MotAg1MeclRollgCntr_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_MotAg1ParFltCnt_Val Rte_Write_CDD_MotCtrlMgr_MotAg1ParFltCnt_Val
#  define Rte_Write_CDD_MotCtrlMgr_MotAg1ParFltCnt_Val(data) (Rte_CDD_MotCtrlMgr_MotAg1ParFltCnt_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_MotAg1SpiMecl_Val Rte_Write_CDD_MotCtrlMgr_MotAg1SpiMecl_Val
#  define Rte_Write_CDD_MotCtrlMgr_MotAg1SpiMecl_Val(data) (Rte_CDD_MotCtrlMgr_MotAg1SpiMecl_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_MotAg1TurnCntrReg_Val Rte_Write_CDD_MotCtrlMgr_MotAg1TurnCntrReg_Val
#  define Rte_Write_CDD_MotCtrlMgr_MotAg1TurnCntrReg_Val(data) (Rte_CDD_MotCtrlMgr_MotAg1TurnCntrReg_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_MotAg1VltgFltCnt_Val Rte_Write_CDD_MotCtrlMgr_MotAg1VltgFltCnt_Val
#  define Rte_Write_CDD_MotCtrlMgr_MotAg1VltgFltCnt_Val(data) (Rte_CDD_MotCtrlMgr_MotAg1VltgFltCnt_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_MotAg1WarnReg_Val Rte_Write_CDD_MotCtrlMgr_MotAg1WarnReg_Val
#  define Rte_Write_CDD_MotCtrlMgr_MotAg1WarnReg_Val(data) (Rte_CDD_MotCtrlMgr_MotAg1WarnReg_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_MotAg3Mecl_Val Rte_Write_CDD_MotCtrlMgr_MotAg3Mecl_Val
#  define Rte_Write_CDD_MotCtrlMgr_MotAg3Mecl_Val(data) (Rte_CDD_MotCtrlMgr_MotAg3Mecl_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_MotAg4Mecl_Val Rte_Write_CDD_MotCtrlMgr_MotAg4Mecl_Val
#  define Rte_Write_CDD_MotCtrlMgr_MotAg4Mecl_Val(data) (Rte_CDD_MotCtrlMgr_MotAg4Mecl_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_MotAgBuf_Ary1D Rte_Write_CDD_MotCtrlMgr_MotAgBuf_Ary1D
#  define Rte_Write_MotAgBufIdx_Val Rte_Write_CDD_MotCtrlMgr_MotAgBufIdx_Val
#  define Rte_Write_CDD_MotCtrlMgr_MotAgBufIdx_Val(data) (Rte_CDD_MotCtrlMgr_MotAgBufIdx_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_MotAgCumvAlgndMrfRev_Val Rte_Write_CDD_MotCtrlMgr_MotAgCumvAlgndMrfRev_Val
#  define Rte_Write_CDD_MotCtrlMgr_MotAgCumvAlgndMrfRev_Val(data) (Rte_CDD_MotCtrlMgr_MotAgCumvAlgndMrfRev_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_MotAgCumvInid_Logl Rte_Write_CDD_MotCtrlMgr_MotAgCumvInid_Logl
#  define Rte_Write_CDD_MotCtrlMgr_MotAgCumvInid_Logl(data) (Rte_CDD_MotCtrlMgr_MotAgCumvInid_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_MotAgTiBuf_Ary1D Rte_Write_CDD_MotCtrlMgr_MotAgTiBuf_Ary1D
#  define Rte_Write_MotCurrAdcVlyA_Val Rte_Write_CDD_MotCtrlMgr_MotCurrAdcVlyA_Val
#  define Rte_Write_CDD_MotCtrlMgr_MotCurrAdcVlyA_Val(data) (Rte_CDD_MotCtrlMgr_MotCurrAdcVlyA_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_MotCurrAdcVlyB_Val Rte_Write_CDD_MotCtrlMgr_MotCurrAdcVlyB_Val
#  define Rte_Write_CDD_MotCtrlMgr_MotCurrAdcVlyB_Val(data) (Rte_CDD_MotCtrlMgr_MotCurrAdcVlyB_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_MotCurrAdcVlyC_Val Rte_Write_CDD_MotCtrlMgr_MotCurrAdcVlyC_Val
#  define Rte_Write_CDD_MotCtrlMgr_MotCurrAdcVlyC_Val(data) (Rte_CDD_MotCtrlMgr_MotCurrAdcVlyC_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_MotCurrCorrdA_Val Rte_Write_CDD_MotCtrlMgr_MotCurrCorrdA_Val
#  define Rte_Write_CDD_MotCtrlMgr_MotCurrCorrdA_Val(data) (Rte_CDD_MotCtrlMgr_MotCurrCorrdA_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_MotCurrCorrdB_Val Rte_Write_CDD_MotCtrlMgr_MotCurrCorrdB_Val
#  define Rte_Write_CDD_MotCtrlMgr_MotCurrCorrdB_Val(data) (Rte_CDD_MotCtrlMgr_MotCurrCorrdB_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_MotCurrCorrdC_Val Rte_Write_CDD_MotCtrlMgr_MotCurrCorrdC_Val
#  define Rte_Write_CDD_MotCtrlMgr_MotCurrCorrdC_Val(data) (Rte_CDD_MotCtrlMgr_MotCurrCorrdC_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_MotCurrDax_Val Rte_Write_CDD_MotCtrlMgr_MotCurrDax_Val
#  define Rte_Write_CDD_MotCtrlMgr_MotCurrDax_Val(data) (Rte_CDD_MotCtrlMgr_MotCurrDax_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_MotCurrQax_Val Rte_Write_CDD_MotCtrlMgr_MotCurrQax_Val
#  define Rte_Write_CDD_MotCtrlMgr_MotCurrQax_Val(data) (Rte_CDD_MotCtrlMgr_MotCurrQax_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_MotCurrRollgCntr1_Val Rte_Write_CDD_MotCtrlMgr_MotCurrRollgCntr1_Val
#  define Rte_Write_CDD_MotCtrlMgr_MotCurrRollgCntr1_Val(data) (Rte_CDD_MotCtrlMgr_MotCurrRollgCntr1_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_MotVltgDax_Val Rte_Write_CDD_MotCtrlMgr_MotVltgDax_Val
#  define Rte_Write_CDD_MotCtrlMgr_MotVltgDax_Val(data) (Rte_CDD_MotCtrlMgr_MotVltgDax_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_MotVltgQax_Val Rte_Write_CDD_MotCtrlMgr_MotVltgQax_Val
#  define Rte_Write_CDD_MotCtrlMgr_MotVltgQax_Val(data) (Rte_CDD_MotCtrlMgr_MotVltgQax_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_Ntc5DErrCnt_Val Rte_Write_CDD_MotCtrlMgr_Ntc5DErrCnt_Val
#  define Rte_Write_CDD_MotCtrlMgr_Ntc5DErrCnt_Val(data) (Rte_CDD_MotCtrlMgr_Ntc5DErrCnt_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_PhaOnTiSumA_Val Rte_Write_CDD_MotCtrlMgr_PhaOnTiSumA_Val
#  define Rte_Write_CDD_MotCtrlMgr_PhaOnTiSumA_Val(data) (Rte_CDD_MotCtrlMgr_PhaOnTiSumA_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_PhaOnTiSumB_Val Rte_Write_CDD_MotCtrlMgr_PhaOnTiSumB_Val
#  define Rte_Write_CDD_MotCtrlMgr_PhaOnTiSumB_Val(data) (Rte_CDD_MotCtrlMgr_PhaOnTiSumB_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_PhaOnTiSumC_Val Rte_Write_CDD_MotCtrlMgr_PhaOnTiSumC_Val
#  define Rte_Write_CDD_MotCtrlMgr_PhaOnTiSumC_Val(data) (Rte_CDD_MotCtrlMgr_PhaOnTiSumC_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_SlowLoopCntr_Val Rte_Write_CDD_MotCtrlMgr_SlowLoopCntr_Val
#  define Rte_Write_CDD_MotCtrlMgr_SlowLoopCntr_Val(data) (Rte_CDD_MotCtrlMgr_SlowLoopCntr_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_CDD_DMACFGANDUSE_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_CDD_DMACFGANDUSE_APPL_CODE) DmaEna2MilliSecToMotCtrlTrf_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CDD_DMACFGANDUSE_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_DmaEna2MilliSecToMotCtrlTrf_Oper() (DmaEna2MilliSecToMotCtrlTrf_Oper(), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_CDD_DMACFGANDUSE_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CDD_DMACFGANDUSE_APPL_CODE) DmaWaitForMotCtrlTo2MilliSecTrf_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CDD_DMACFGANDUSE_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_DmaWaitForMotCtrlTo2MilliSecTrf_Oper DmaWaitForMotCtrlTo2MilliSecTrf_Oper


# endif /* !defined(RTE_CORE) */


# define CDD_MotCtrlMgr_START_SEC_CODE
# include "CDD_MotCtrlMgr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_MotCtrlMgrPer1 MotCtrlMgrPer1
#  define RTE_RUNNABLE_MotCtrlMgrPer2 MotCtrlMgrPer2
# endif

FUNC(void, CDD_MotCtrlMgr_CODE) MotCtrlMgrPer1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CDD_MotCtrlMgr_CODE) MotCtrlMgrPer2(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define CDD_MotCtrlMgr_STOP_SEC_CODE
# include "CDD_MotCtrlMgr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_DmaWaitForMotCtrlTo2MilliSecTrf1_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CDD_MOTCTRLMGR_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
