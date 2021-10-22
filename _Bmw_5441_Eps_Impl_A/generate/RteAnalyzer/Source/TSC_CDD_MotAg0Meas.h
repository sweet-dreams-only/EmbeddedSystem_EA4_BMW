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
 *          File:  TSC_CDD_MotAg0Meas.h
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
Std_ReturnType TSC_CDD_MotAg0Meas_Rte_Read_MotAg0Polarity_Val(sint8 *data);
Std_ReturnType TSC_CDD_MotAg0Meas_Rte_Read_MotAg0ErrReg_Val(uint32 *data);
Std_ReturnType TSC_CDD_MotAg0Meas_Rte_Read_MotAg0ParFltCnt_Val(uint16 *data);
Std_ReturnType TSC_CDD_MotAg0Meas_Rte_Read_MotAg0Polarity_Val(sint8 *data);
Std_ReturnType TSC_CDD_MotAg0Meas_Rte_Read_MotAg0SpiMecl_Val(u0p16 *data);
Std_ReturnType TSC_CDD_MotAg0Meas_Rte_Read_MotAg0TurnCntrReg_Val(uint32 *data);
Std_ReturnType TSC_CDD_MotAg0Meas_Rte_Read_MotAg0VltgFltCnt_Val(uint16 *data);
Std_ReturnType TSC_CDD_MotAg0Meas_Rte_Read_MotAg0WarnReg_Val(uint32 *data);
Std_ReturnType TSC_CDD_MotAg0Meas_Rte_Read_MotAg3Mecl_Val(u0p16 *data);
Std_ReturnType TSC_CDD_MotAg0Meas_Rte_Read_EgyModSt_Val(EgyModSt1 *data);
Std_ReturnType TSC_CDD_MotAg0Meas_Rte_Read_MotAg1MeclQlfr_Val(SigQlfr1 *data);
Std_ReturnType TSC_CDD_MotAg0Meas_Rte_Read_MotAg1TurnCntrQlfr_Val(SigQlfr1 *data);
Std_ReturnType TSC_CDD_MotAg0Meas_Rte_Read_TurnCntrIdptSig_Val(uint8 *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_CDD_MotAg0Meas_Rte_Write_MotAg0SnsrCfgAdr_Val(uint32 data);
Std_ReturnType TSC_CDD_MotAg0Meas_Rte_Write_MotAg0MeclQlfr_Val(SigQlfr1 data);
Std_ReturnType TSC_CDD_MotAg0Meas_Rte_Write_MotAg0QepFaild_Logl(boolean data);
Std_ReturnType TSC_CDD_MotAg0Meas_Rte_Write_MotAg0TurnCntr_Val(float32 data);
Std_ReturnType TSC_CDD_MotAg0Meas_Rte_Write_MotAg0TurnCntrQlfr_Val(SigQlfr1 data);
Std_ReturnType TSC_CDD_MotAg0Meas_Rte_Write_MotAg0TurnCntrRollgCntr_Val(uint8 data);

/** Client server interfaces */
Std_ReturnType TSC_CDD_MotAg0Meas_Rte_Call_IoHwAb_SetFctGpioMotAg0Clk_Oper(void);
Std_ReturnType TSC_CDD_MotAg0Meas_Rte_Call_IoHwAb_SetFctGpioMotAg0Cs_Oper(void);
Std_ReturnType TSC_CDD_MotAg0Meas_Rte_Call_IoHwAb_SetFctGpioMotAg0Mosi_Oper(void);
Std_ReturnType TSC_CDD_MotAg0Meas_Rte_Call_IoHwAb_SetGpioMotAg0Clk_Oper(boolean PinSt_Arg);
Std_ReturnType TSC_CDD_MotAg0Meas_Rte_Call_IoHwAb_SetGpioMotAg0Cs_Oper(boolean PinSt_Arg);
Std_ReturnType TSC_CDD_MotAg0Meas_Rte_Call_IoHwAb_SetGpioMotAg0Mosi_Oper(boolean PinSt_Arg);
Std_ReturnType TSC_CDD_MotAg0Meas_Rte_Call_CnvSnpshtData_s16_Oper(uint32 *SnpshtDataCnvd_Arg, sint16 SnpshtData_Arg);
Std_ReturnType TSC_CDD_MotAg0Meas_Rte_Call_CnvSnpshtData_u16_Oper(uint32 *SnpshtDataCnvd_Arg, uint16 SnpshtData_Arg);
Std_ReturnType TSC_CDD_MotAg0Meas_Rte_Call_GetNtcQlfrSts_Oper(NtcNr1 NtcNr_Arg, SigQlfr1 *NtcQlfr_Arg);
Std_ReturnType TSC_CDD_MotAg0Meas_Rte_Call_SetNtcStsAndSnpshtData_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg, uint32 SpclSnpshtData0_Arg, uint32 SpclSnpshtData1_Arg, uint32 SpclSnpshtData2_Arg);
Std_ReturnType TSC_CDD_MotAg0Meas_Rte_Call_MotAg0SnsrCfgDmaStrt_Oper(void);

/** Service interfaces */
Std_ReturnType TSC_CDD_MotAg0Meas_Rte_Call_MotAg0CoeffTbl_SetRamBlockStatus(boolean RamBlockStatus_Arg);
Std_ReturnType TSC_CDD_MotAg0Meas_Rte_Call_MotAg0CoeffTbl_GetErrorStatus(NvM_RequestResultType *ErrorStatus_Arg);

/** Explicit inter-runnable variables */
void TSC_CDD_MotAg0Meas_Rte_IrvWrite_MotAg0MeasPer2_MotAg0Qlfr(SigQlfr1);
void TSC_CDD_MotAg0Meas_Rte_IrvWrite_MotAg0MeasPer2_TurnCntr0Qlfr(SigQlfr1);
SigQlfr1 TSC_CDD_MotAg0Meas_Rte_IrvRead_MotAg0MeasPer3_MotAg0Qlfr(void);
SigQlfr1 TSC_CDD_MotAg0Meas_Rte_IrvRead_MotAg0MeasPer3_TurnCntr0Qlfr(void);

/** Calibration Component Calibration Parameters */
uint16  TSC_CDD_MotAg0Meas_Rte_Prm_MotAg0MeasSnsrIfErrNtcMask_Val(void);

/** SW-C local Calibration Parameters */
Ary1D_f32_26 * TSC_CDD_MotAg0Meas_Rte_CData_MotAg0CoeffTblDft(void);

/** Per Instance Memories */
uint32 *TSC_CDD_MotAg0Meas_Rte_Pim_MotAg0QepFaildCntr(void);
uint32 *TSC_CDD_MotAg0Meas_Rte_Pim_MotAg0SnsrCfg(void);
uint32 *TSC_CDD_MotAg0Meas_Rte_Pim_dMotAg0MeasMotAg0RawAgReg(void);
uint32 *TSC_CDD_MotAg0Meas_Rte_Pim_dMotAg0MeasMotAg0RawErrReg(void);
uint32 *TSC_CDD_MotAg0Meas_Rte_Pim_dMotAg0MeasMotAg0RawStsReg(void);
uint32 *TSC_CDD_MotAg0Meas_Rte_Pim_dMotAg0MeasMotAg0RawTurnCntrReg(void);
uint32 *TSC_CDD_MotAg0Meas_Rte_Pim_dMotAg0MeasMotAg0RawWarnReg(void);
sint32 *TSC_CDD_MotAg0Meas_Rte_Pim_MotAg0InitOffs(void);
sint32 *TSC_CDD_MotAg0Meas_Rte_Pim_dMotAg0MeasMotAg0RtOffs(void);
uint16 *TSC_CDD_MotAg0Meas_Rte_Pim_MotAg0ParFltCntNtcPrev(void);
uint16 *TSC_CDD_MotAg0Meas_Rte_Pim_MotAg0ParFltCntPrev(void);
u0p16 *TSC_CDD_MotAg0Meas_Rte_Pim_MotAg0PrevSpiMecl(void);
u0p16 *TSC_CDD_MotAg0Meas_Rte_Pim_MotAg0RawMeclPrev(void);
uint16 *TSC_CDD_MotAg0Meas_Rte_Pim_MotAg0TurnCntrParFltCntNtcPrev(void);
uint16 *TSC_CDD_MotAg0Meas_Rte_Pim_MotAg0TurnCntrParFltCntPrev(void);
uint16 *TSC_CDD_MotAg0Meas_Rte_Pim_MotAg0VltgFltCntNtcPrev(void);
uint16 *TSC_CDD_MotAg0Meas_Rte_Pim_MotAg0VltgFltCntPrev(void);
u0p16 *TSC_CDD_MotAg0Meas_Rte_Pim_dMotAg0MeasMotAg0Delta(void);
sint16 *TSC_CDD_MotAg0Meas_Rte_Pim_MotAg0PrevTCUpd(void);
sint16 *TSC_CDD_MotAg0Meas_Rte_Pim_MotAg0TurnCntrPrev(void);
uint8 *TSC_CDD_MotAg0Meas_Rte_Pim_MotAg0InitOffsCntr(void);
uint8 *TSC_CDD_MotAg0Meas_Rte_Pim_MotAg0MeclRollgCntrPrev(void);
uint8 *TSC_CDD_MotAg0Meas_Rte_Pim_MotAg0TurnCntrRollgCntrPrev(void);
uint8 *TSC_CDD_MotAg0Meas_Rte_Pim_MotAgCtrlRegCfg(void);
MotAgSnsrCfgSt1 *TSC_CDD_MotAg0Meas_Rte_Pim_MotAgSnsrCfgSt(void);
sint8 *TSC_CDD_MotAg0Meas_Rte_Pim_MotAgMecl0Polarity(void);
boolean *TSC_CDD_MotAg0Meas_Rte_Pim_MotAg0QepFaildPrev(void);
boolean *TSC_CDD_MotAg0Meas_Rte_Pim_dMotAg0MeasPwrRstStsLtch(void);
float32 *TSC_CDD_MotAg0Meas_Rte_Pim_MotAg0CoeffTbl(void);
sm5p12 *TSC_CDD_MotAg0Meas_Rte_Pim_MotAg0CorrnTbl(void);



