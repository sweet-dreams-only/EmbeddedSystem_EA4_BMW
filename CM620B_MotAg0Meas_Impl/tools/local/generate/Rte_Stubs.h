/******************************************************************************************************************
* Copyright 2016 Nxtr
* Nxtr Confidential
*
* Module File Name:   Rte_Stubs.h
* Module Description: Stubs header for Polyspace analysis.  Generated from TL109A_SwcSuprt.
* Project:            CBD
* Author:             Owen Tosh
******************************************************************************************************************/


#ifndef RTE_STUBS_H
#define RTE_STUBS_H

#include "math_stubs.h"

/*** Extern Statements ***/

/* Inputs */
extern VAR(EgyModSt1, AUTOMATIC) MotAg0Meas_Ip_EgyModSt;
extern VAR(uint32, AUTOMATIC) MotAg0Meas_Ip_MotAg0ErrReg;
extern VAR(uint16, AUTOMATIC) MotAg0Meas_Ip_MotAg0ParFltCnt;
extern VAR(sint8, AUTOMATIC) MotAg0Meas_Ip_MotAg0Polarity;
extern VAR(u0p16, AUTOMATIC) MotAg0Meas_Ip_MotAg0SpiMecl;
extern VAR(uint32, AUTOMATIC) MotAg0Meas_Ip_MotAg0TurnCntrReg;
extern VAR(uint16, AUTOMATIC) MotAg0Meas_Ip_MotAg0VltgFltCnt;
extern VAR(uint32, AUTOMATIC) MotAg0Meas_Ip_MotAg0WarnReg;
extern VAR(SigQlfr1, AUTOMATIC) MotAg0Meas_Ip_MotAg1MeclQlfr;
extern VAR(SigQlfr1, AUTOMATIC) MotAg0Meas_Ip_MotAg1TurnCntrQlfr;
extern VAR(u0p16, AUTOMATIC) MotAg0Meas_Ip_MotAg3Mecl;
extern VAR(uint8, AUTOMATIC) MotAg0Meas_Ip_TurnCntrIdptSig;

/* Outputs */
extern VAR(SigQlfr1, AUTOMATIC) MotAg0Meas_Op_MotAg0MeclQlfr;
extern VAR(boolean, AUTOMATIC) MotAg0Meas_Op_MotAg0QepFaild;
extern VAR(uint32, AUTOMATIC) MotAg0Meas_Op_MotAg0SnsrCfgAdr;
extern VAR(float32, AUTOMATIC) MotAg0Meas_Op_MotAg0TurnCntr;
extern VAR(SigQlfr1, AUTOMATIC) MotAg0Meas_Op_MotAg0TurnCntrQlfr;
extern VAR(uint8, AUTOMATIC) MotAg0Meas_Op_MotAg0TurnCntrRollgCntr;

/* Calibrations */
extern CONST(uint16, AUTOMATIC) MotAg0Meas_Cal_MotAg0MeasSnsrIfErrNtcMask;

/* PIMs */
extern VAR(float32, AUTOMATIC) MotAg0Meas_Pim_MotAg0CoeffTbl[26];
extern VAR(u0p16, AUTOMATIC) MotAg0Meas_Pim_dMotAg0MeasMotAg0Delta;
extern VAR(uint32, AUTOMATIC) MotAg0Meas_Pim_dMotAg0MeasMotAg0RawAgReg;
extern VAR(uint32, AUTOMATIC) MotAg0Meas_Pim_dMotAg0MeasMotAg0RawErrReg;
extern VAR(uint32, AUTOMATIC) MotAg0Meas_Pim_dMotAg0MeasMotAg0RawStsReg;
extern VAR(uint32, AUTOMATIC) MotAg0Meas_Pim_dMotAg0MeasMotAg0RawTurnCntrReg;
extern VAR(uint32, AUTOMATIC) MotAg0Meas_Pim_dMotAg0MeasMotAg0RawWarnReg;
extern VAR(sint32, AUTOMATIC) MotAg0Meas_Pim_dMotAg0MeasMotAg0RtOffs;
extern VAR(boolean, AUTOMATIC) MotAg0Meas_Pim_dMotAg0MeasPwrRstStsLtch;
extern VAR(sm5p12, AUTOMATIC) MotAg0Meas_Pim_MotAg0CorrnTbl[128];
extern VAR(sint32, AUTOMATIC) MotAg0Meas_Pim_MotAg0InitOffs;
extern VAR(uint8, AUTOMATIC) MotAg0Meas_Pim_MotAg0InitOffsCntr;
extern VAR(uint8, AUTOMATIC) MotAg0Meas_Pim_MotAg0MeclRollgCntrPrev;
extern VAR(uint16, AUTOMATIC) MotAg0Meas_Pim_MotAg0ParFltCntNtcPrev;
extern VAR(uint16, AUTOMATIC) MotAg0Meas_Pim_MotAg0ParFltCntPrev;
extern VAR(u0p16, AUTOMATIC) MotAg0Meas_Pim_MotAg0PrevSpiMecl;
extern VAR(sint16, AUTOMATIC) MotAg0Meas_Pim_MotAg0PrevTCUpd;
extern VAR(uint32, AUTOMATIC) MotAg0Meas_Pim_MotAg0QepFaildCntr;
extern VAR(boolean, AUTOMATIC) MotAg0Meas_Pim_MotAg0QepFaildPrev;
extern VAR(u0p16, AUTOMATIC) MotAg0Meas_Pim_MotAg0RawMeclPrev;
extern VAR(uint32, AUTOMATIC) MotAg0Meas_Pim_MotAg0SnsrCfg;
extern VAR(uint16, AUTOMATIC) MotAg0Meas_Pim_MotAg0TurnCntrParFltCntNtcPrev;
extern VAR(uint16, AUTOMATIC) MotAg0Meas_Pim_MotAg0TurnCntrParFltCntPrev;
extern VAR(sint16, AUTOMATIC) MotAg0Meas_Pim_MotAg0TurnCntrPrev;
extern VAR(uint8, AUTOMATIC) MotAg0Meas_Pim_MotAg0TurnCntrRollgCntrPrev;
extern VAR(uint16, AUTOMATIC) MotAg0Meas_Pim_MotAg0VltgFltCntNtcPrev;
extern VAR(uint16, AUTOMATIC) MotAg0Meas_Pim_MotAg0VltgFltCntPrev;
extern VAR(uint8, AUTOMATIC) MotAg0Meas_Pim_MotAgCtrlRegCfg;
extern VAR(sint8, AUTOMATIC) MotAg0Meas_Pim_MotAgMecl0Polarity;
extern VAR(MotAgSnsrCfgSt1, AUTOMATIC) MotAg0Meas_Pim_MotAgSnsrCfgSt;

/* IRVs */
extern VAR(SigQlfr1, AUTOMATIC) MotAg0Meas_Irv_MotAg0Qlfr;
extern VAR(SigQlfr1, AUTOMATIC) MotAg0Meas_Irv_TurnCntr0Qlfr;

/* Arguments and Returns */
extern VAR(uint32, AUTOMATIC) MotAg0Meas_Srv_CnvSnpshtData_s16_SnpshtDataCnvd;
extern VAR(sint16, AUTOMATIC) MotAg0Meas_Srv_CnvSnpshtData_s16_SnpshtData;
extern VAR(uint32, AUTOMATIC) MotAg0Meas_Srv_CnvSnpshtData_u16_SnpshtDataCnvd;
extern VAR(uint16, AUTOMATIC) MotAg0Meas_Srv_CnvSnpshtData_u16_SnpshtData;
extern VAR(NtcNr1, AUTOMATIC) MotAg0Meas_Srv_GetNtcQlfrSts_NtcNr;
extern VAR(SigQlfr1, AUTOMATIC) MotAg0Meas_Srv_GetNtcQlfrSts_NtcQlfr;
extern VAR(Std_ReturnType, AUTOMATIC) MotAg0Meas_Srv_GetNtcQlfrSts_Return;
extern VAR(Std_ReturnType, AUTOMATIC) MotAg0Meas_Srv_IoHwAb_SetFctGpioMotAg0Clk_Return;
extern VAR(Std_ReturnType, AUTOMATIC) MotAg0Meas_Srv_IoHwAb_SetFctGpioMotAg0Cs_Return;
extern VAR(Std_ReturnType, AUTOMATIC) MotAg0Meas_Srv_IoHwAb_SetFctGpioMotAg0Mosi_Return;
extern VAR(boolean, AUTOMATIC) MotAg0Meas_Srv_IoHwAb_SetGpioMotAg0Clk_PinSt;
extern VAR(Std_ReturnType, AUTOMATIC) MotAg0Meas_Srv_IoHwAb_SetGpioMotAg0Clk_Return;
extern VAR(boolean, AUTOMATIC) MotAg0Meas_Srv_IoHwAb_SetGpioMotAg0Cs_PinSt;
extern VAR(Std_ReturnType, AUTOMATIC) MotAg0Meas_Srv_IoHwAb_SetGpioMotAg0Cs_Return;
extern VAR(boolean, AUTOMATIC) MotAg0Meas_Srv_IoHwAb_SetGpioMotAg0Mosi_PinSt;
extern VAR(Std_ReturnType, AUTOMATIC) MotAg0Meas_Srv_IoHwAb_SetGpioMotAg0Mosi_Return;
extern VAR(uint8, AUTOMATIC) MotAg0Meas_Srv_MotAg0CoeffTbl_GetErrorStatus_RequestResultPtr;
extern VAR(Std_ReturnType, AUTOMATIC) MotAg0Meas_Srv_MotAg0CoeffTbl_GetErrorStatus_Return;
extern VAR(boolean, AUTOMATIC) MotAg0Meas_Srv_MotAg0CoeffTbl_SetRamBlockStatus_BlockChanged;
extern VAR(Std_ReturnType, AUTOMATIC) MotAg0Meas_Srv_MotAg0CoeffTbl_SetRamBlockStatus_Return;
extern VAR(Std_ReturnType, AUTOMATIC) MotAg0Meas_Srv_MotAg0SnsrCfgDmaStrt_Return;
extern VAR(NtcNr1, AUTOMATIC) MotAg0Meas_Srv_SetNtcStsAndSnpshtData_NtcNr;
extern VAR(uint8, AUTOMATIC) MotAg0Meas_Srv_SetNtcStsAndSnpshtData_NtcStInfo;
extern VAR(NtcSts1, AUTOMATIC) MotAg0Meas_Srv_SetNtcStsAndSnpshtData_NtcSts;
extern VAR(uint16, AUTOMATIC) MotAg0Meas_Srv_SetNtcStsAndSnpshtData_DebStep;
extern VAR(uint32, AUTOMATIC) MotAg0Meas_Srv_SetNtcStsAndSnpshtData_SpclSnpshtData0;
extern VAR(uint32, AUTOMATIC) MotAg0Meas_Srv_SetNtcStsAndSnpshtData_SpclSnpshtData1;
extern VAR(uint32, AUTOMATIC) MotAg0Meas_Srv_SetNtcStsAndSnpshtData_SpclSnpshtData2;
extern VAR(Std_ReturnType, AUTOMATIC) MotAg0Meas_Srv_SetNtcStsAndSnpshtData_Return;
extern VAR(float32, AUTOMATIC) MotAg0Meas_Cli_MotAg0CoeffTblRead_MotAgCoeffTbl[26];
extern VAR(float32, AUTOMATIC) MotAg0Meas_Cli_MotAg0CoeffTblWr_MotAgCoeffTbl[26];


/*** Input Stubs ***/

#ifdef Rte_Read_EgyModSt_Val
# undef Rte_Read_EgyModSt_Val
#else
#error Rte_Read_EgyModSt_Val is missing
#endif
#define Rte_Read_EgyModSt_Val(data) (*(data) = MotAg0Meas_Ip_EgyModSt)

#ifdef Rte_Read_MotAg0ErrReg_Val
# undef Rte_Read_MotAg0ErrReg_Val
#else
#error Rte_Read_MotAg0ErrReg_Val is missing
#endif
#define Rte_Read_MotAg0ErrReg_Val(data) (*(data) = MotAg0Meas_Ip_MotAg0ErrReg)

#ifdef Rte_Read_MotAg0ParFltCnt_Val
# undef Rte_Read_MotAg0ParFltCnt_Val
#else
#error Rte_Read_MotAg0ParFltCnt_Val is missing
#endif
#define Rte_Read_MotAg0ParFltCnt_Val(data) (*(data) = MotAg0Meas_Ip_MotAg0ParFltCnt)

#ifdef Rte_Read_MotAg0Polarity_Val
# undef Rte_Read_MotAg0Polarity_Val
#else
#error Rte_Read_MotAg0Polarity_Val is missing
#endif
#define Rte_Read_MotAg0Polarity_Val(data) (*(data) = MotAg0Meas_Ip_MotAg0Polarity)

#ifdef Rte_Read_MotAg0SpiMecl_Val
# undef Rte_Read_MotAg0SpiMecl_Val
#else
#error Rte_Read_MotAg0SpiMecl_Val is missing
#endif
#define Rte_Read_MotAg0SpiMecl_Val(data) (*(data) = MotAg0Meas_Ip_MotAg0SpiMecl)

#ifdef Rte_Read_MotAg0TurnCntrReg_Val
# undef Rte_Read_MotAg0TurnCntrReg_Val
#else
#error Rte_Read_MotAg0TurnCntrReg_Val is missing
#endif
#define Rte_Read_MotAg0TurnCntrReg_Val(data) (*(data) = MotAg0Meas_Ip_MotAg0TurnCntrReg)

#ifdef Rte_Read_MotAg0VltgFltCnt_Val
# undef Rte_Read_MotAg0VltgFltCnt_Val
#else
#error Rte_Read_MotAg0VltgFltCnt_Val is missing
#endif
#define Rte_Read_MotAg0VltgFltCnt_Val(data) (*(data) = MotAg0Meas_Ip_MotAg0VltgFltCnt)

#ifdef Rte_Read_MotAg0WarnReg_Val
# undef Rte_Read_MotAg0WarnReg_Val
#else
#error Rte_Read_MotAg0WarnReg_Val is missing
#endif
#define Rte_Read_MotAg0WarnReg_Val(data) (*(data) = MotAg0Meas_Ip_MotAg0WarnReg)

#ifdef Rte_Read_MotAg1MeclQlfr_Val
# undef Rte_Read_MotAg1MeclQlfr_Val
#else
#error Rte_Read_MotAg1MeclQlfr_Val is missing
#endif
#define Rte_Read_MotAg1MeclQlfr_Val(data) (*(data) = MotAg0Meas_Ip_MotAg1MeclQlfr)

#ifdef Rte_Read_MotAg1TurnCntrQlfr_Val
# undef Rte_Read_MotAg1TurnCntrQlfr_Val
#else
#error Rte_Read_MotAg1TurnCntrQlfr_Val is missing
#endif
#define Rte_Read_MotAg1TurnCntrQlfr_Val(data) (*(data) = MotAg0Meas_Ip_MotAg1TurnCntrQlfr)

#ifdef Rte_Read_MotAg3Mecl_Val
# undef Rte_Read_MotAg3Mecl_Val
#else
#error Rte_Read_MotAg3Mecl_Val is missing
#endif
#define Rte_Read_MotAg3Mecl_Val(data) (*(data) = MotAg0Meas_Ip_MotAg3Mecl)

#ifdef Rte_Read_TurnCntrIdptSig_Val
# undef Rte_Read_TurnCntrIdptSig_Val
#else
#error Rte_Read_TurnCntrIdptSig_Val is missing
#endif
#define Rte_Read_TurnCntrIdptSig_Val(data) (*(data) = MotAg0Meas_Ip_TurnCntrIdptSig)


/*** Output Stubs ***/

#ifdef Rte_Write_MotAg0MeclQlfr_Val
# undef Rte_Write_MotAg0MeclQlfr_Val
#else
#error Rte_Write_MotAg0MeclQlfr_Val is missing
#endif
#define Rte_Write_MotAg0MeclQlfr_Val(data) (MotAg0Meas_Op_MotAg0MeclQlfr = (data))

#ifdef Rte_Write_MotAg0QepFaild_Logl
# undef Rte_Write_MotAg0QepFaild_Logl
#else
#error Rte_Write_MotAg0QepFaild_Logl is missing
#endif
#define Rte_Write_MotAg0QepFaild_Logl(data) (MotAg0Meas_Op_MotAg0QepFaild = (data))

#ifdef Rte_Write_MotAg0SnsrCfgAdr_Val
# undef Rte_Write_MotAg0SnsrCfgAdr_Val
#else
#error Rte_Write_MotAg0SnsrCfgAdr_Val is missing
#endif
#define Rte_Write_MotAg0SnsrCfgAdr_Val(data) (MotAg0Meas_Op_MotAg0SnsrCfgAdr = (data))

#ifdef Rte_Write_MotAg0TurnCntr_Val
# undef Rte_Write_MotAg0TurnCntr_Val
#else
#error Rte_Write_MotAg0TurnCntr_Val is missing
#endif
#define Rte_Write_MotAg0TurnCntr_Val(data) (MotAg0Meas_Op_MotAg0TurnCntr = (data))

#ifdef Rte_Write_MotAg0TurnCntrQlfr_Val
# undef Rte_Write_MotAg0TurnCntrQlfr_Val
#else
#error Rte_Write_MotAg0TurnCntrQlfr_Val is missing
#endif
#define Rte_Write_MotAg0TurnCntrQlfr_Val(data) (MotAg0Meas_Op_MotAg0TurnCntrQlfr = (data))

#ifdef Rte_Write_MotAg0TurnCntrRollgCntr_Val
# undef Rte_Write_MotAg0TurnCntrRollgCntr_Val
#else
#error Rte_Write_MotAg0TurnCntrRollgCntr_Val is missing
#endif
#define Rte_Write_MotAg0TurnCntrRollgCntr_Val(data) (MotAg0Meas_Op_MotAg0TurnCntrRollgCntr = (data))


/*** Calibration Stubs ***/

#ifdef Rte_Prm_MotAg0MeasSnsrIfErrNtcMask_Val
# undef Rte_Prm_MotAg0MeasSnsrIfErrNtcMask_Val
#else
#error Rte_Prm_MotAg0MeasSnsrIfErrNtcMask_Val is missing
#endif
#define Rte_Prm_MotAg0MeasSnsrIfErrNtcMask_Val() (MotAg0Meas_Cal_MotAg0MeasSnsrIfErrNtcMask)


/*** PIM Stubs ***/

#ifdef Rte_Pim_MotAg0CoeffTbl
# undef Rte_Pim_MotAg0CoeffTbl
#else
#error Rte_Pim_MotAg0CoeffTbl is missing
#endif
#define Rte_Pim_MotAg0CoeffTbl() (&(MotAg0Meas_Pim_MotAg0CoeffTbl[0]))

#ifdef Rte_Pim_dMotAg0MeasMotAg0Delta
# undef Rte_Pim_dMotAg0MeasMotAg0Delta
#else
#error Rte_Pim_dMotAg0MeasMotAg0Delta is missing
#endif
#define Rte_Pim_dMotAg0MeasMotAg0Delta() (&MotAg0Meas_Pim_dMotAg0MeasMotAg0Delta)

#ifdef Rte_Pim_dMotAg0MeasMotAg0RawAgReg
# undef Rte_Pim_dMotAg0MeasMotAg0RawAgReg
#else
#error Rte_Pim_dMotAg0MeasMotAg0RawAgReg is missing
#endif
#define Rte_Pim_dMotAg0MeasMotAg0RawAgReg() (&MotAg0Meas_Pim_dMotAg0MeasMotAg0RawAgReg)

#ifdef Rte_Pim_dMotAg0MeasMotAg0RawErrReg
# undef Rte_Pim_dMotAg0MeasMotAg0RawErrReg
#else
#error Rte_Pim_dMotAg0MeasMotAg0RawErrReg is missing
#endif
#define Rte_Pim_dMotAg0MeasMotAg0RawErrReg() (&MotAg0Meas_Pim_dMotAg0MeasMotAg0RawErrReg)

#ifdef Rte_Pim_dMotAg0MeasMotAg0RawStsReg
# undef Rte_Pim_dMotAg0MeasMotAg0RawStsReg
#else
#error Rte_Pim_dMotAg0MeasMotAg0RawStsReg is missing
#endif
#define Rte_Pim_dMotAg0MeasMotAg0RawStsReg() (&MotAg0Meas_Pim_dMotAg0MeasMotAg0RawStsReg)

#ifdef Rte_Pim_dMotAg0MeasMotAg0RawTurnCntrReg
# undef Rte_Pim_dMotAg0MeasMotAg0RawTurnCntrReg
#else
#error Rte_Pim_dMotAg0MeasMotAg0RawTurnCntrReg is missing
#endif
#define Rte_Pim_dMotAg0MeasMotAg0RawTurnCntrReg() (&MotAg0Meas_Pim_dMotAg0MeasMotAg0RawTurnCntrReg)

#ifdef Rte_Pim_dMotAg0MeasMotAg0RawWarnReg
# undef Rte_Pim_dMotAg0MeasMotAg0RawWarnReg
#else
#error Rte_Pim_dMotAg0MeasMotAg0RawWarnReg is missing
#endif
#define Rte_Pim_dMotAg0MeasMotAg0RawWarnReg() (&MotAg0Meas_Pim_dMotAg0MeasMotAg0RawWarnReg)

#ifdef Rte_Pim_dMotAg0MeasMotAg0RtOffs
# undef Rte_Pim_dMotAg0MeasMotAg0RtOffs
#else
#error Rte_Pim_dMotAg0MeasMotAg0RtOffs is missing
#endif
#define Rte_Pim_dMotAg0MeasMotAg0RtOffs() (&MotAg0Meas_Pim_dMotAg0MeasMotAg0RtOffs)

#ifdef Rte_Pim_dMotAg0MeasPwrRstStsLtch
# undef Rte_Pim_dMotAg0MeasPwrRstStsLtch
#else
#error Rte_Pim_dMotAg0MeasPwrRstStsLtch is missing
#endif
#define Rte_Pim_dMotAg0MeasPwrRstStsLtch() (&MotAg0Meas_Pim_dMotAg0MeasPwrRstStsLtch)

#ifdef Rte_Pim_MotAg0CorrnTbl
# undef Rte_Pim_MotAg0CorrnTbl
#else
#error Rte_Pim_MotAg0CorrnTbl is missing
#endif
#define Rte_Pim_MotAg0CorrnTbl() (&(MotAg0Meas_Pim_MotAg0CorrnTbl[0]))

#ifdef Rte_Pim_MotAg0InitOffs
# undef Rte_Pim_MotAg0InitOffs
#else
#error Rte_Pim_MotAg0InitOffs is missing
#endif
#define Rte_Pim_MotAg0InitOffs() (&MotAg0Meas_Pim_MotAg0InitOffs)

#ifdef Rte_Pim_MotAg0InitOffsCntr
# undef Rte_Pim_MotAg0InitOffsCntr
#else
#error Rte_Pim_MotAg0InitOffsCntr is missing
#endif
#define Rte_Pim_MotAg0InitOffsCntr() (&MotAg0Meas_Pim_MotAg0InitOffsCntr)

#ifdef Rte_Pim_MotAg0MeclRollgCntrPrev
# undef Rte_Pim_MotAg0MeclRollgCntrPrev
#else
#error Rte_Pim_MotAg0MeclRollgCntrPrev is missing
#endif
#define Rte_Pim_MotAg0MeclRollgCntrPrev() (&MotAg0Meas_Pim_MotAg0MeclRollgCntrPrev)

#ifdef Rte_Pim_MotAg0ParFltCntNtcPrev
# undef Rte_Pim_MotAg0ParFltCntNtcPrev
#else
#error Rte_Pim_MotAg0ParFltCntNtcPrev is missing
#endif
#define Rte_Pim_MotAg0ParFltCntNtcPrev() (&MotAg0Meas_Pim_MotAg0ParFltCntNtcPrev)

#ifdef Rte_Pim_MotAg0ParFltCntPrev
# undef Rte_Pim_MotAg0ParFltCntPrev
#else
#error Rte_Pim_MotAg0ParFltCntPrev is missing
#endif
#define Rte_Pim_MotAg0ParFltCntPrev() (&MotAg0Meas_Pim_MotAg0ParFltCntPrev)

#ifdef Rte_Pim_MotAg0PrevSpiMecl
# undef Rte_Pim_MotAg0PrevSpiMecl
#else
#error Rte_Pim_MotAg0PrevSpiMecl is missing
#endif
#define Rte_Pim_MotAg0PrevSpiMecl() (&MotAg0Meas_Pim_MotAg0PrevSpiMecl)

#ifdef Rte_Pim_MotAg0PrevTCUpd
# undef Rte_Pim_MotAg0PrevTCUpd
#else
#error Rte_Pim_MotAg0PrevTCUpd is missing
#endif
#define Rte_Pim_MotAg0PrevTCUpd() (&MotAg0Meas_Pim_MotAg0PrevTCUpd)

#ifdef Rte_Pim_MotAg0QepFaildCntr
# undef Rte_Pim_MotAg0QepFaildCntr
#else
#error Rte_Pim_MotAg0QepFaildCntr is missing
#endif
#define Rte_Pim_MotAg0QepFaildCntr() (&MotAg0Meas_Pim_MotAg0QepFaildCntr)

#ifdef Rte_Pim_MotAg0QepFaildPrev
# undef Rte_Pim_MotAg0QepFaildPrev
#else
#error Rte_Pim_MotAg0QepFaildPrev is missing
#endif
#define Rte_Pim_MotAg0QepFaildPrev() (&MotAg0Meas_Pim_MotAg0QepFaildPrev)

#ifdef Rte_Pim_MotAg0RawMeclPrev
# undef Rte_Pim_MotAg0RawMeclPrev
#else
#error Rte_Pim_MotAg0RawMeclPrev is missing
#endif
#define Rte_Pim_MotAg0RawMeclPrev() (&MotAg0Meas_Pim_MotAg0RawMeclPrev)

#ifdef Rte_Pim_MotAg0SnsrCfg
# undef Rte_Pim_MotAg0SnsrCfg
#else
#error Rte_Pim_MotAg0SnsrCfg is missing
#endif
#define Rte_Pim_MotAg0SnsrCfg() (&MotAg0Meas_Pim_MotAg0SnsrCfg)

#ifdef Rte_Pim_MotAg0TurnCntrParFltCntNtcPrev
# undef Rte_Pim_MotAg0TurnCntrParFltCntNtcPrev
#else
#error Rte_Pim_MotAg0TurnCntrParFltCntNtcPrev is missing
#endif
#define Rte_Pim_MotAg0TurnCntrParFltCntNtcPrev() (&MotAg0Meas_Pim_MotAg0TurnCntrParFltCntNtcPrev)

#ifdef Rte_Pim_MotAg0TurnCntrParFltCntPrev
# undef Rte_Pim_MotAg0TurnCntrParFltCntPrev
#else
#error Rte_Pim_MotAg0TurnCntrParFltCntPrev is missing
#endif
#define Rte_Pim_MotAg0TurnCntrParFltCntPrev() (&MotAg0Meas_Pim_MotAg0TurnCntrParFltCntPrev)

#ifdef Rte_Pim_MotAg0TurnCntrPrev
# undef Rte_Pim_MotAg0TurnCntrPrev
#else
#error Rte_Pim_MotAg0TurnCntrPrev is missing
#endif
#define Rte_Pim_MotAg0TurnCntrPrev() (&MotAg0Meas_Pim_MotAg0TurnCntrPrev)

#ifdef Rte_Pim_MotAg0TurnCntrRollgCntrPrev
# undef Rte_Pim_MotAg0TurnCntrRollgCntrPrev
#else
#error Rte_Pim_MotAg0TurnCntrRollgCntrPrev is missing
#endif
#define Rte_Pim_MotAg0TurnCntrRollgCntrPrev() (&MotAg0Meas_Pim_MotAg0TurnCntrRollgCntrPrev)

#ifdef Rte_Pim_MotAg0VltgFltCntNtcPrev
# undef Rte_Pim_MotAg0VltgFltCntNtcPrev
#else
#error Rte_Pim_MotAg0VltgFltCntNtcPrev is missing
#endif
#define Rte_Pim_MotAg0VltgFltCntNtcPrev() (&MotAg0Meas_Pim_MotAg0VltgFltCntNtcPrev)

#ifdef Rte_Pim_MotAg0VltgFltCntPrev
# undef Rte_Pim_MotAg0VltgFltCntPrev
#else
#error Rte_Pim_MotAg0VltgFltCntPrev is missing
#endif
#define Rte_Pim_MotAg0VltgFltCntPrev() (&MotAg0Meas_Pim_MotAg0VltgFltCntPrev)

#ifdef Rte_Pim_MotAgCtrlRegCfg
# undef Rte_Pim_MotAgCtrlRegCfg
#else
#error Rte_Pim_MotAgCtrlRegCfg is missing
#endif
#define Rte_Pim_MotAgCtrlRegCfg() (&MotAg0Meas_Pim_MotAgCtrlRegCfg)

#ifdef Rte_Pim_MotAgMecl0Polarity
# undef Rte_Pim_MotAgMecl0Polarity
#else
#error Rte_Pim_MotAgMecl0Polarity is missing
#endif
#define Rte_Pim_MotAgMecl0Polarity() (&MotAg0Meas_Pim_MotAgMecl0Polarity)

#ifdef Rte_Pim_MotAgSnsrCfgSt
# undef Rte_Pim_MotAgSnsrCfgSt
#else
#error Rte_Pim_MotAgSnsrCfgSt is missing
#endif
#define Rte_Pim_MotAgSnsrCfgSt() (&MotAg0Meas_Pim_MotAgSnsrCfgSt)


/*** IRV Stubs ***/

#ifdef Rte_IrvRead_MotAg0MeasPer3_MotAg0Qlfr
# undef Rte_IrvRead_MotAg0MeasPer3_MotAg0Qlfr
#else
#error MotAg0Qlfr is missing
#endif
#define Rte_IrvRead_MotAg0MeasPer3_MotAg0Qlfr() (MotAg0Meas_Irv_MotAg0Qlfr)

#ifdef Rte_IrvWrite_MotAg0MeasPer2_MotAg0Qlfr
# undef Rte_IrvWrite_MotAg0MeasPer2_MotAg0Qlfr
#else
#error MotAg0Qlfr is missing
#endif
#define Rte_IrvWrite_MotAg0MeasPer2_MotAg0Qlfr(data) (MotAg0Meas_Irv_MotAg0Qlfr = (data))

#ifdef Rte_IrvRead_MotAg0MeasPer3_TurnCntr0Qlfr
# undef Rte_IrvRead_MotAg0MeasPer3_TurnCntr0Qlfr
#else
#error TurnCntr0Qlfr is missing
#endif
#define Rte_IrvRead_MotAg0MeasPer3_TurnCntr0Qlfr() (MotAg0Meas_Irv_TurnCntr0Qlfr)

#ifdef Rte_IrvWrite_MotAg0MeasPer2_TurnCntr0Qlfr
# undef Rte_IrvWrite_MotAg0MeasPer2_TurnCntr0Qlfr
#else
#error TurnCntr0Qlfr is missing
#endif
#define Rte_IrvWrite_MotAg0MeasPer2_TurnCntr0Qlfr(data) (MotAg0Meas_Irv_TurnCntr0Qlfr = (data))


/*** Client Stub ***/

extern FUNC(void, AUTOMATIC) Rte_Stub(void);


#endif
