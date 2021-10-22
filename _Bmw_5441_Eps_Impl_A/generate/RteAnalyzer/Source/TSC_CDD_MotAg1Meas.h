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
 *          File:  TSC_CDD_MotAg1Meas.h
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
Std_ReturnType TSC_CDD_MotAg1Meas_Rte_Read_MotAg1Polarity_Val(sint8 *data);
Std_ReturnType TSC_CDD_MotAg1Meas_Rte_Read_MotAg1ErrReg_Val(uint32 *data);
Std_ReturnType TSC_CDD_MotAg1Meas_Rte_Read_MotAg1ParFltCnt_Val(uint16 *data);
Std_ReturnType TSC_CDD_MotAg1Meas_Rte_Read_MotAg1Polarity_Val(sint8 *data);
Std_ReturnType TSC_CDD_MotAg1Meas_Rte_Read_MotAg1SpiMecl_Val(u0p16 *data);
Std_ReturnType TSC_CDD_MotAg1Meas_Rte_Read_MotAg1TurnCntrReg_Val(uint32 *data);
Std_ReturnType TSC_CDD_MotAg1Meas_Rte_Read_MotAg1VltgFltCnt_Val(uint16 *data);
Std_ReturnType TSC_CDD_MotAg1Meas_Rte_Read_MotAg1WarnReg_Val(uint32 *data);
Std_ReturnType TSC_CDD_MotAg1Meas_Rte_Read_MotAg4Mecl_Val(u0p16 *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_CDD_MotAg1Meas_Rte_Write_MotAg1MeclQlfr_Val(SigQlfr1 data);
Std_ReturnType TSC_CDD_MotAg1Meas_Rte_Write_MotAg1QepFaild_Logl(boolean data);
Std_ReturnType TSC_CDD_MotAg1Meas_Rte_Write_MotAg1TurnCntr_Val(float32 data);
Std_ReturnType TSC_CDD_MotAg1Meas_Rte_Write_MotAg1TurnCntrQlfr_Val(SigQlfr1 data);
Std_ReturnType TSC_CDD_MotAg1Meas_Rte_Write_MotAg1TurnCntrRollgCntr_Val(uint8 data);

/** Client server interfaces */
Std_ReturnType TSC_CDD_MotAg1Meas_Rte_Call_IoHwAb_SetFctGpioMotAg1Clk_Oper(void);
Std_ReturnType TSC_CDD_MotAg1Meas_Rte_Call_IoHwAb_SetFctGpioMotAg1Cs_Oper(void);
Std_ReturnType TSC_CDD_MotAg1Meas_Rte_Call_IoHwAb_SetFctGpioMotAg1Mosi_Oper(void);
Std_ReturnType TSC_CDD_MotAg1Meas_Rte_Call_IoHwAb_SetGpioMotAg1Clk_Oper(boolean PinSt_Arg);
Std_ReturnType TSC_CDD_MotAg1Meas_Rte_Call_IoHwAb_SetGpioMotAg1Cs_Oper(boolean PinSt_Arg);
Std_ReturnType TSC_CDD_MotAg1Meas_Rte_Call_IoHwAb_SetGpioMotAg1Mosi_Oper(boolean PinSt_Arg);
Std_ReturnType TSC_CDD_MotAg1Meas_Rte_Call_CnvSnpshtData_s16_Oper(uint32 *SnpshtDataCnvd_Arg, sint16 SnpshtData_Arg);
Std_ReturnType TSC_CDD_MotAg1Meas_Rte_Call_CnvSnpshtData_u16_Oper(uint32 *SnpshtDataCnvd_Arg, uint16 SnpshtData_Arg);
Std_ReturnType TSC_CDD_MotAg1Meas_Rte_Call_GetNtcQlfrSts_Oper(NtcNr1 NtcNr_Arg, SigQlfr1 *NtcQlfr_Arg);
Std_ReturnType TSC_CDD_MotAg1Meas_Rte_Call_SetNtcStsAndSnpshtData_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg, uint32 SpclSnpshtData0_Arg, uint32 SpclSnpshtData1_Arg, uint32 SpclSnpshtData2_Arg);

/** Service interfaces */
Std_ReturnType TSC_CDD_MotAg1Meas_Rte_Call_MotAg1CoeffTbl_SetRamBlockStatus(boolean RamBlockStatus_Arg);
Std_ReturnType TSC_CDD_MotAg1Meas_Rte_Call_MotAg1CoeffTbl_GetErrorStatus(NvM_RequestResultType *ErrorStatus_Arg);

/** Calibration Component Calibration Parameters */
u0p16  TSC_CDD_MotAg1Meas_Rte_Prm_MotAg1MeasOffs_Val(void);
uint16  TSC_CDD_MotAg1Meas_Rte_Prm_MotAg1MeasSnsrIfErrNtcMask_Val(void);

/** SW-C local Calibration Parameters */
Ary1D_f32_26 * TSC_CDD_MotAg1Meas_Rte_CData_MotAg1CoeffTblDft(void);

/** Per Instance Memories */
uint32 *TSC_CDD_MotAg1Meas_Rte_Pim_MotAg1QepFaildCntr(void);
uint32 *TSC_CDD_MotAg1Meas_Rte_Pim_dMotAg1MeasMotAg1RawAgReg(void);
uint32 *TSC_CDD_MotAg1Meas_Rte_Pim_dMotAg1MeasMotAg1RawErrReg(void);
uint32 *TSC_CDD_MotAg1Meas_Rte_Pim_dMotAg1MeasMotAg1RawStsReg(void);
uint32 *TSC_CDD_MotAg1Meas_Rte_Pim_dMotAg1MeasMotAg1RawTurnCntrReg(void);
uint32 *TSC_CDD_MotAg1Meas_Rte_Pim_dMotAg1MeasMotAg1RawWarnReg(void);
sint32 *TSC_CDD_MotAg1Meas_Rte_Pim_MotAg1InitOffs(void);
uint16 *TSC_CDD_MotAg1Meas_Rte_Pim_MotAg1ParFltCntNtcPrev(void);
uint16 *TSC_CDD_MotAg1Meas_Rte_Pim_MotAg1ParFltCntPrev(void);
u0p16 *TSC_CDD_MotAg1Meas_Rte_Pim_MotAg1PrevSpiMecl(void);
u0p16 *TSC_CDD_MotAg1Meas_Rte_Pim_MotAg1RawMeclPrev(void);
uint16 *TSC_CDD_MotAg1Meas_Rte_Pim_MotAg1TurnCntrParFltCntNtcPrev(void);
uint16 *TSC_CDD_MotAg1Meas_Rte_Pim_MotAg1TurnCntrParFltCntPrev(void);
uint16 *TSC_CDD_MotAg1Meas_Rte_Pim_MotAg1VltgFltCntNtcPrev(void);
uint16 *TSC_CDD_MotAg1Meas_Rte_Pim_MotAg1VltgFltCntPrev(void);
u0p16 *TSC_CDD_MotAg1Meas_Rte_Pim_dMotAg1MeasMotAg1Delta(void);
uint16 *TSC_CDD_MotAg1Meas_Rte_Pim_dMotAg1MeasMotAg1RtOffs(void);
sint16 *TSC_CDD_MotAg1Meas_Rte_Pim_MotAg1PrevTCUpd(void);
sint16 *TSC_CDD_MotAg1Meas_Rte_Pim_MotAg1TurnCntrPrev(void);
uint8 *TSC_CDD_MotAg1Meas_Rte_Pim_MotAg1InitOffsCntr(void);
uint8 *TSC_CDD_MotAg1Meas_Rte_Pim_MotAg1MeclRollgCntrPrev(void);
uint8 *TSC_CDD_MotAg1Meas_Rte_Pim_MotAg1TurnCntrRollgCntrPrev(void);
sint8 *TSC_CDD_MotAg1Meas_Rte_Pim_MotAgMecl1Polarity(void);
boolean *TSC_CDD_MotAg1Meas_Rte_Pim_MotAg1QepFaildPrev(void);
boolean *TSC_CDD_MotAg1Meas_Rte_Pim_dMotAg1MeasPwrRstStsLtch(void);
float32 *TSC_CDD_MotAg1Meas_Rte_Pim_MotAg1CoeffTbl(void);
sm5p12 *TSC_CDD_MotAg1Meas_Rte_Pim_MotAg1CorrnTbl(void);



