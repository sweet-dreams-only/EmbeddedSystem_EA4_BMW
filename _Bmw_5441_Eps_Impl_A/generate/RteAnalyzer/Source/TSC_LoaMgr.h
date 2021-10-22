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
 *          File:  TSC_LoaMgr.h
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
Std_ReturnType TSC_LoaMgr_Rte_Read_CurrMeasIdptSig_Val(uint8 *data);
Std_ReturnType TSC_LoaMgr_Rte_Read_DiagcStsIvtr1Inactv_Logl(boolean *data);
Std_ReturnType TSC_LoaMgr_Rte_Read_DiagcStsIvtr2Inactv_Logl(boolean *data);
Std_ReturnType TSC_LoaMgr_Rte_Read_HwTqIdptSig_Val(uint8 *data);
Std_ReturnType TSC_LoaMgr_Rte_Read_IvtrFetFltTyp_Val(IvtrFetFltTyp1 *data);
Std_ReturnType TSC_LoaMgr_Rte_Read_LoaScaDi_Logl(boolean *data);
Std_ReturnType TSC_LoaMgr_Rte_Read_MotAgMeclIdptSig_Val(uint8 *data);
Std_ReturnType TSC_LoaMgr_Rte_Read_MotAgSnsrlsAvl_Logl(boolean *data);
Std_ReturnType TSC_LoaMgr_Rte_Read_TqLoaAvl_Logl(boolean *data);
Std_ReturnType TSC_LoaMgr_Rte_Read_VehSteerMod_Val(SteerMod1 *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_LoaMgr_Rte_Write_HwTqLoaMtgtnEna_Logl(boolean data);
Std_ReturnType TSC_LoaMgr_Rte_Write_LoaRateLim_Val(float32 data);
Std_ReturnType TSC_LoaMgr_Rte_Write_LoaSca_Val(float32 data);
Std_ReturnType TSC_LoaMgr_Rte_Write_LoaSt_Val(LoaSt1 data);
Std_ReturnType TSC_LoaMgr_Rte_Write_MotAgLoaMtgtnEna_Logl(boolean data);
Std_ReturnType TSC_LoaMgr_Rte_Write_MotAndThermProtnLoaMod_Val(uint8 data);

/** Client server interfaces */
Std_ReturnType TSC_LoaMgr_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg);
Std_ReturnType TSC_LoaMgr_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg);

/** Calibration Component Calibration Parameters */
float32  TSC_LoaMgr_Rte_Prm_LoaMgrCurrIvtrMtgtnRate_Val(void);
float32  TSC_LoaMgr_Rte_Prm_LoaMgrCurrIvtrMtgtnSca_Val(void);
float32  TSC_LoaMgr_Rte_Prm_LoaMgrCurrMeasMtgtnRate_Val(void);
float32  TSC_LoaMgr_Rte_Prm_LoaMgrCurrMeasMtgtnSca_Val(void);
float32  TSC_LoaMgr_Rte_Prm_LoaMgrFadeOutStRate_Val(void);
float32  TSC_LoaMgr_Rte_Prm_LoaMgrIvtrMtgtnRate_Val(void);
float32  TSC_LoaMgr_Rte_Prm_LoaMgrIvtrMtgtnSca_Val(void);
float32  TSC_LoaMgr_Rte_Prm_LoaMgrLimdStRate_Val(void);
float32  TSC_LoaMgr_Rte_Prm_LoaMgrLimdStSca_Val(void);
float32  TSC_LoaMgr_Rte_Prm_LoaMgrMotAgMtgtnRate_Val(void);
float32  TSC_LoaMgr_Rte_Prm_LoaMgrMotAgMtgtnSca_Val(void);
uint8  TSC_LoaMgr_Rte_Prm_LoaMgrCurrMeasIdptSig0Resp_Val(void);
uint8  TSC_LoaMgr_Rte_Prm_LoaMgrCurrMeasIdptSig1Resp_Val(void);
uint8  TSC_LoaMgr_Rte_Prm_LoaMgrCurrMeasIdptSig2Resp_Val(void);
uint8  TSC_LoaMgr_Rte_Prm_LoaMgrCurrMeasIdptSigFltThd_Val(void);
uint8  TSC_LoaMgr_Rte_Prm_LoaMgrHwTqIdptSig0NoTqLoaResp_Val(void);
uint8  TSC_LoaMgr_Rte_Prm_LoaMgrHwTqIdptSig1NoTqLoaResp_Val(void);
uint8  TSC_LoaMgr_Rte_Prm_LoaMgrHwTqIdptSig2Resp_Val(void);
uint8  TSC_LoaMgr_Rte_Prm_LoaMgrHwTqIdptSig3Resp_Val(void);
uint8  TSC_LoaMgr_Rte_Prm_LoaMgrHwTqIdptSig4Resp_Val(void);
uint8  TSC_LoaMgr_Rte_Prm_LoaMgrHwTqIdptSigFltThd_Val(void);
uint8  TSC_LoaMgr_Rte_Prm_LoaMgrHwTqLoaAvlResp_Val(void);
uint8  TSC_LoaMgr_Rte_Prm_LoaMgrIvtrIdptSig0Resp_Val(void);
uint8  TSC_LoaMgr_Rte_Prm_LoaMgrIvtrIdptSig1Resp_Val(void);
uint8  TSC_LoaMgr_Rte_Prm_LoaMgrIvtrIdptSig2Resp_Val(void);
uint8  TSC_LoaMgr_Rte_Prm_LoaMgrIvtrIdptSigFltThd_Val(void);
uint8  TSC_LoaMgr_Rte_Prm_LoaMgrMotAgAvlSnsrlsResp_Val(void);
uint8  TSC_LoaMgr_Rte_Prm_LoaMgrMotAgIdptSig0NoSnsrlsResp_Val(void);
uint8  TSC_LoaMgr_Rte_Prm_LoaMgrMotAgIdptSig1NoSnsrlsResp_Val(void);
uint8  TSC_LoaMgr_Rte_Prm_LoaMgrMotAgIdptSig2Resp_Val(void);
uint8  TSC_LoaMgr_Rte_Prm_LoaMgrMotAgIdptSig3Resp_Val(void);
uint8  TSC_LoaMgr_Rte_Prm_LoaMgrMotAgIdptSigFltThd_Val(void);
boolean  TSC_LoaMgr_Rte_Prm_LoaMgrCurrIvtrMtgtnScaZeroEna_Logl(void);
boolean  TSC_LoaMgr_Rte_Prm_LoaMgrCurrMeasMtgtnScaZeroEna_Logl(void);
boolean  TSC_LoaMgr_Rte_Prm_LoaMgrIvtrMtgtnScaZeroEna_Logl(void);
boolean  TSC_LoaMgr_Rte_Prm_LoaMgrMotAgMtgtnScaZeroEna_Logl(void);

/** Exclusive Areas */
void TSC_LoaMgr_Rte_Enter_LoaMgrExclusiveArea(void);
void TSC_LoaMgr_Rte_Exit_LoaMgrExclusiveArea(void);

/** Per Instance Memories */
uint8 *TSC_LoaMgr_Rte_Pim_PrevCurrMeasIdptSigResp(void);
uint8 *TSC_LoaMgr_Rte_Pim_PrevCurrMeasIdptSigVal(void);
uint8 *TSC_LoaMgr_Rte_Pim_PrevHwTqIdptSigResp(void);
uint8 *TSC_LoaMgr_Rte_Pim_PrevHwTqIdptSigVal(void);
uint8 *TSC_LoaMgr_Rte_Pim_PrevIvtrIdptSigResp(void);
uint8 *TSC_LoaMgr_Rte_Pim_PrevIvtrIdptSigVal(void);
uint8 *TSC_LoaMgr_Rte_Pim_PrevMotAgMeclIdptSigResp(void);
uint8 *TSC_LoaMgr_Rte_Pim_PrevMotAgMeclIdptSigVal(void);
uint8 *TSC_LoaMgr_Rte_Pim_PrevVltgModSrc(void);
boolean *TSC_LoaMgr_Rte_Pim_PrevCurrMeasLoaStSwMtgtnEna(void);
boolean *TSC_LoaMgr_Rte_Pim_PrevHwTqLoaStSwMtgtnEna(void);
boolean *TSC_LoaMgr_Rte_Pim_PrevIvtrLoaStSwMtgtnEna(void);
boolean *TSC_LoaMgr_Rte_Pim_PrevMotAgLoaMtgtnEna(void);
boolean *TSC_LoaMgr_Rte_Pim_PrevMotAgLoaStSwMtgtnEna(void);



