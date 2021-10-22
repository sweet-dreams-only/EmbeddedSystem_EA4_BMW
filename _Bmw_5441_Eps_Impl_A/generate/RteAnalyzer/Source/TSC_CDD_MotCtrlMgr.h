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
 *          File:  TSC_CDD_MotCtrlMgr.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Header of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/


/** Sender receiver - explicit read services */
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Read_MotAndThermProtnLoaMod_Val(uint8 *data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Read_AdcDiagcEndPtrOutp_Val(uint8 *data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Read_AdcDiagcStrtPtrOutp_Val(uint8 *data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Read_BrdgVltg_Val(float32 *data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Read_CurrMeasCorrlnSts_Val(uint8 *data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Read_CurrMeasWrmIninTestCmpl_Logl(boolean *data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Read_DiagcStsIvtr1Inactv_Logl(boolean *data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Read_EcuTFild_Val(float32 *data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Read_IvtrFetFltPha_Val(IvtrFetFltPha1 *data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Read_IvtrFetFltTyp_Val(IvtrFetFltTyp1 *data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Read_LoopCntr2MilliSec_Val(uint16 *data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Read_MotAg0QepFaild_Logl(boolean *data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Read_MotAg1QepFaild_Logl(boolean *data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Read_MotAgElecDly_Val(float32 *data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Read_MotAndThermProtnLoaMod_Val(uint8 *data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Read_MotBackEmfVltg_Val(float32 *data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Read_MotCurrAdcVlyAAdcFaild_Logl(boolean *data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Read_MotCurrAdcVlyBAdcFaild_Logl(boolean *data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Read_MotCurrAdcVlyCAdcFaild_Logl(boolean *data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Read_MotCurrDaxCmd_Val(float32 *data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Read_MotCurrDaxMax_Val(float32 *data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Read_MotCurrEolCalSt_Val(MotCurrEolCalSt2 *data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Read_MotCurrQaxCmd_Val(float32 *data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Read_MotCurrQlfr1_Val(SigQlfr1 *data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Read_MotDampgDax_Val(float32 *data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Read_MotDampgQax_Val(float32 *data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Read_MotElecMeclPolarity_Val(sint8 *data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Read_MotInduDaxEstimdIvs_Val(float32 *data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Read_MotInduQaxEstimdIvs_Val(float32 *data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Read_MotIntglGainDax_Val(float32 *data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Read_MotIntglGainQax_Val(float32 *data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Read_MotPropGainDax_Val(float32 *data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Read_MotPropGainQax_Val(float32 *data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Read_MotREstimd_Val(float32 *data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Read_MotReacncDax_Val(float32 *data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Read_MotReacncQax_Val(float32 *data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Read_MotVelMrf_Val(float32 *data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Read_MotVltgDaxFf_Val(float32 *data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Read_MotVltgQaxFf_Val(float32 *data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Read_PhaDiscnctDiagcActv_Logl(boolean *data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Read_PhaDiscnctDiagcPwmVect_Val(PhaDiscnctPwmVect1 *data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Read_SysSt_Val(SysSt1 *data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Read_VehSpd_Val(float32 *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Write_Adc0ScanGroup2Ref0_Val(float32 data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Write_Adc0ScanGroup2Ref1_Val(float32 data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Write_Adc0ScanGroup3Ref0_Val(float32 data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Write_Adc0ScanGroup3Ref1_Val(float32 data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Write_Adc0SelfDiag0_Val(float32 data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Write_Adc0SelfDiag2_Val(float32 data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Write_Adc0SelfDiag4_Val(float32 data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Write_BattRtnCurrAdc_Val(float32 data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Write_BattVltgAdc_Val(float32 data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Write_FastLoopCntr_Val(uint16 data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Write_HwTq4RawAdc_Val(float32 data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Write_HwTq4RawFastAdcBuf_Ary1D(const float32 *data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Write_HwTq5RawAdc_Val(float32 data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Write_HwTq5RawFastAdcBuf_Ary1D(const float32 *data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Write_MotAg0ErrReg_Val(uint32 data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Write_MotAg0Mecl_Val(u0p16 data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Write_MotAg0MeclRollgCntr_Val(uint8 data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Write_MotAg0ParFltCnt_Val(uint16 data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Write_MotAg0SpiMecl_Val(uint16 data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Write_MotAg0TurnCntrReg_Val(uint32 data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Write_MotAg0VltgFltCnt_Val(uint16 data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Write_MotAg0WarnReg_Val(uint32 data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Write_MotAg1ErrReg_Val(uint32 data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Write_MotAg1Mecl_Val(u0p16 data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Write_MotAg1MeclRollgCntr_Val(uint8 data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Write_MotAg1ParFltCnt_Val(uint16 data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Write_MotAg1SpiMecl_Val(uint16 data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Write_MotAg1TurnCntrReg_Val(uint32 data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Write_MotAg1VltgFltCnt_Val(uint16 data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Write_MotAg1WarnReg_Val(uint32 data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Write_MotAg3Mecl_Val(uint16 data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Write_MotAg4Mecl_Val(uint16 data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Write_MotAgBuf_Ary1D(const u0p16 *data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Write_MotAgBufIdx_Val(uint8 data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Write_MotAgCumvAlgndMrfRev_Val(s15p16 data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Write_MotAgCumvInid_Logl(boolean data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Write_MotAgTiBuf_Ary1D(const uint32 *data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Write_MotCurrAdcVlyA_Val(float32 data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Write_MotCurrAdcVlyB_Val(float32 data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Write_MotCurrAdcVlyC_Val(float32 data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Write_MotCurrCorrdA_Val(float32 data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Write_MotCurrCorrdB_Val(float32 data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Write_MotCurrCorrdC_Val(float32 data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Write_MotCurrDax_Val(float32 data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Write_MotCurrQax_Val(float32 data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Write_MotCurrRollgCntr1_Val(uint8 data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Write_MotVltgDax_Val(float32 data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Write_MotVltgQax_Val(float32 data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Write_Ntc5DErrCnt_Val(uint16 data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Write_PhaOnTiSumA_Val(uint32 data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Write_PhaOnTiSumB_Val(uint32 data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Write_PhaOnTiSumC_Val(uint32 data);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Write_SlowLoopCntr_Val(uint16 data);

/** Client server interfaces */
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Call_DmaWaitForMotCtrlTo2MilliSecTrf_Oper(void);
Std_ReturnType TSC_CDD_MotCtrlMgr_Rte_Call_DmaEna2MilliSecToMotCtrlTrf_Oper(void);




