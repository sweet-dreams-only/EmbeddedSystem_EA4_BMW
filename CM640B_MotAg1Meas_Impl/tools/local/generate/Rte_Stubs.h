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
extern VAR(uint32, AUTOMATIC) MotAg1Meas_Ip_MotAg1ErrReg;
extern VAR(uint16, AUTOMATIC) MotAg1Meas_Ip_MotAg1ParFltCnt;
extern VAR(sint8, AUTOMATIC) MotAg1Meas_Ip_MotAg1Polarity;
extern VAR(u0p16, AUTOMATIC) MotAg1Meas_Ip_MotAg1SpiMecl;
extern VAR(uint32, AUTOMATIC) MotAg1Meas_Ip_MotAg1TurnCntrReg;
extern VAR(uint16, AUTOMATIC) MotAg1Meas_Ip_MotAg1VltgFltCnt;
extern VAR(uint32, AUTOMATIC) MotAg1Meas_Ip_MotAg1WarnReg;
extern VAR(u0p16, AUTOMATIC) MotAg1Meas_Ip_MotAg4Mecl;

/* Outputs */
extern VAR(SigQlfr1, AUTOMATIC) MotAg1Meas_Op_MotAg1MeclQlfr;
extern VAR(boolean, AUTOMATIC) MotAg1Meas_Op_MotAg1QepFaild;
extern VAR(float32, AUTOMATIC) MotAg1Meas_Op_MotAg1TurnCntr;
extern VAR(SigQlfr1, AUTOMATIC) MotAg1Meas_Op_MotAg1TurnCntrQlfr;
extern VAR(uint8, AUTOMATIC) MotAg1Meas_Op_MotAg1TurnCntrRollgCntr;

/* Calibrations */
extern CONST(u0p16, AUTOMATIC) MotAg1Meas_Cal_MotAg1MeasOffs;
extern CONST(uint16, AUTOMATIC) MotAg1Meas_Cal_MotAg1MeasSnsrIfErrNtcMask;

/* PIMs */
extern VAR(float32, AUTOMATIC) MotAg1Meas_Pim_MotAg1CoeffTbl[26];
extern VAR(u0p16, AUTOMATIC) MotAg1Meas_Pim_dMotAg1MeasMotAg1Delta;
extern VAR(uint32, AUTOMATIC) MotAg1Meas_Pim_dMotAg1MeasMotAg1RawAgReg;
extern VAR(uint32, AUTOMATIC) MotAg1Meas_Pim_dMotAg1MeasMotAg1RawErrReg;
extern VAR(uint32, AUTOMATIC) MotAg1Meas_Pim_dMotAg1MeasMotAg1RawStsReg;
extern VAR(uint32, AUTOMATIC) MotAg1Meas_Pim_dMotAg1MeasMotAg1RawTurnCntrReg;
extern VAR(uint32, AUTOMATIC) MotAg1Meas_Pim_dMotAg1MeasMotAg1RawWarnReg;
extern VAR(sint32, AUTOMATIC) MotAg1Meas_Pim_dMotAg1MeasMotAg1RtOffs;
extern VAR(boolean, AUTOMATIC) MotAg1Meas_Pim_dMotAg1MeasPwrRstStsLtch;
extern VAR(sm5p12, AUTOMATIC) MotAg1Meas_Pim_MotAg1CorrnTbl[128];
extern VAR(sint32, AUTOMATIC) MotAg1Meas_Pim_MotAg1InitOffs;
extern VAR(uint8, AUTOMATIC) MotAg1Meas_Pim_MotAg1InitOffsCntr;
extern VAR(uint8, AUTOMATIC) MotAg1Meas_Pim_MotAg1MeclRollgCntrPrev;
extern VAR(uint16, AUTOMATIC) MotAg1Meas_Pim_MotAg1ParFltCntNtcPrev;
extern VAR(uint16, AUTOMATIC) MotAg1Meas_Pim_MotAg1ParFltCntPrev;
extern VAR(u0p16, AUTOMATIC) MotAg1Meas_Pim_MotAg1PrevSpiMecl;
extern VAR(sint16, AUTOMATIC) MotAg1Meas_Pim_MotAg1PrevTCUpd;
extern VAR(uint32, AUTOMATIC) MotAg1Meas_Pim_MotAg1QepFaildCntr;
extern VAR(boolean, AUTOMATIC) MotAg1Meas_Pim_MotAg1QepFaildPrev;
extern VAR(u0p16, AUTOMATIC) MotAg1Meas_Pim_MotAg1RawMeclPrev;
extern VAR(uint16, AUTOMATIC) MotAg1Meas_Pim_MotAg1TurnCntrParFltCntNtcPrev;
extern VAR(uint16, AUTOMATIC) MotAg1Meas_Pim_MotAg1TurnCntrParFltCntPrev;
extern VAR(sint16, AUTOMATIC) MotAg1Meas_Pim_MotAg1TurnCntrPrev;
extern VAR(uint8, AUTOMATIC) MotAg1Meas_Pim_MotAg1TurnCntrRollgCntrPrev;
extern VAR(uint16, AUTOMATIC) MotAg1Meas_Pim_MotAg1VltgFltCntNtcPrev;
extern VAR(uint16, AUTOMATIC) MotAg1Meas_Pim_MotAg1VltgFltCntPrev;
extern VAR(sint8, AUTOMATIC) MotAg1Meas_Pim_MotAgMecl1Polarity;

/* Arguments and Returns */
extern VAR(uint32, AUTOMATIC) MotAg1Meas_Srv_CnvSnpshtData_s16_SnpshtDataCnvd;
extern VAR(sint16, AUTOMATIC) MotAg1Meas_Srv_CnvSnpshtData_s16_SnpshtData;
extern VAR(uint32, AUTOMATIC) MotAg1Meas_Srv_CnvSnpshtData_u16_SnpshtDataCnvd;
extern VAR(uint16, AUTOMATIC) MotAg1Meas_Srv_CnvSnpshtData_u16_SnpshtData;
extern VAR(NtcNr1, AUTOMATIC) MotAg1Meas_Srv_GetNtcQlfrSts_NtcNr;
extern VAR(SigQlfr1, AUTOMATIC) MotAg1Meas_Srv_GetNtcQlfrSts_NtcQlfr;
extern VAR(Std_ReturnType, AUTOMATIC) MotAg1Meas_Srv_GetNtcQlfrSts_Return;
extern VAR(Std_ReturnType, AUTOMATIC) MotAg1Meas_Srv_IoHwAb_SetFctGpioMotAg1Clk_Return;
extern VAR(Std_ReturnType, AUTOMATIC) MotAg1Meas_Srv_IoHwAb_SetFctGpioMotAg1Cs_Return;
extern VAR(Std_ReturnType, AUTOMATIC) MotAg1Meas_Srv_IoHwAb_SetFctGpioMotAg1Mosi_Return;
extern VAR(boolean, AUTOMATIC) MotAg1Meas_Srv_IoHwAb_SetGpioMotAg1Clk_PinSt;
extern VAR(Std_ReturnType, AUTOMATIC) MotAg1Meas_Srv_IoHwAb_SetGpioMotAg1Clk_Return;
extern VAR(boolean, AUTOMATIC) MotAg1Meas_Srv_IoHwAb_SetGpioMotAg1Cs_PinSt;
extern VAR(Std_ReturnType, AUTOMATIC) MotAg1Meas_Srv_IoHwAb_SetGpioMotAg1Cs_Return;
extern VAR(boolean, AUTOMATIC) MotAg1Meas_Srv_IoHwAb_SetGpioMotAg1Mosi_PinSt;
extern VAR(Std_ReturnType, AUTOMATIC) MotAg1Meas_Srv_IoHwAb_SetGpioMotAg1Mosi_Return;
extern VAR(uint8, AUTOMATIC) MotAg1Meas_Srv_MotAg1CoeffTbl_GetErrorStatus_RequestResultPtr;
extern VAR(Std_ReturnType, AUTOMATIC) MotAg1Meas_Srv_MotAg1CoeffTbl_GetErrorStatus_Return;
extern VAR(boolean, AUTOMATIC) MotAg1Meas_Srv_MotAg1CoeffTbl_SetRamBlockStatus_BlockChanged;
extern VAR(Std_ReturnType, AUTOMATIC) MotAg1Meas_Srv_MotAg1CoeffTbl_SetRamBlockStatus_Return;
extern VAR(NtcNr1, AUTOMATIC) MotAg1Meas_Srv_SetNtcStsAndSnpshtData_NtcNr;
extern VAR(uint8, AUTOMATIC) MotAg1Meas_Srv_SetNtcStsAndSnpshtData_NtcStInfo;
extern VAR(NtcSts1, AUTOMATIC) MotAg1Meas_Srv_SetNtcStsAndSnpshtData_NtcSts;
extern VAR(uint16, AUTOMATIC) MotAg1Meas_Srv_SetNtcStsAndSnpshtData_DebStep;
extern VAR(uint32, AUTOMATIC) MotAg1Meas_Srv_SetNtcStsAndSnpshtData_SpclSnpshtData0;
extern VAR(uint32, AUTOMATIC) MotAg1Meas_Srv_SetNtcStsAndSnpshtData_SpclSnpshtData1;
extern VAR(uint32, AUTOMATIC) MotAg1Meas_Srv_SetNtcStsAndSnpshtData_SpclSnpshtData2;
extern VAR(Std_ReturnType, AUTOMATIC) MotAg1Meas_Srv_SetNtcStsAndSnpshtData_Return;
extern VAR(float32, AUTOMATIC) MotAg1Meas_Cli_MotAg1CoeffTblRead_MotAgCoeffTbl[26];
extern VAR(float32, AUTOMATIC) MotAg1Meas_Cli_MotAg1CoeffTblWr_MotAgCoeffTbl[26];


/*** Input Stubs ***/

#ifdef Rte_Read_MotAg1ErrReg_Val
# undef Rte_Read_MotAg1ErrReg_Val
#else
#error Rte_Read_MotAg1ErrReg_Val is missing
#endif
#define Rte_Read_MotAg1ErrReg_Val(data) (*(data) = MotAg1Meas_Ip_MotAg1ErrReg)

#ifdef Rte_Read_MotAg1ParFltCnt_Val
# undef Rte_Read_MotAg1ParFltCnt_Val
#else
#error Rte_Read_MotAg1ParFltCnt_Val is missing
#endif
#define Rte_Read_MotAg1ParFltCnt_Val(data) (*(data) = MotAg1Meas_Ip_MotAg1ParFltCnt)

#ifdef Rte_Read_MotAg1Polarity_Val
# undef Rte_Read_MotAg1Polarity_Val
#else
#error Rte_Read_MotAg1Polarity_Val is missing
#endif
#define Rte_Read_MotAg1Polarity_Val(data) (*(data) = MotAg1Meas_Ip_MotAg1Polarity)

#ifdef Rte_Read_MotAg1SpiMecl_Val
# undef Rte_Read_MotAg1SpiMecl_Val
#else
#error Rte_Read_MotAg1SpiMecl_Val is missing
#endif
#define Rte_Read_MotAg1SpiMecl_Val(data) (*(data) = MotAg1Meas_Ip_MotAg1SpiMecl)

#ifdef Rte_Read_MotAg1TurnCntrReg_Val
# undef Rte_Read_MotAg1TurnCntrReg_Val
#else
#error Rte_Read_MotAg1TurnCntrReg_Val is missing
#endif
#define Rte_Read_MotAg1TurnCntrReg_Val(data) (*(data) = MotAg1Meas_Ip_MotAg1TurnCntrReg)

#ifdef Rte_Read_MotAg1VltgFltCnt_Val
# undef Rte_Read_MotAg1VltgFltCnt_Val
#else
#error Rte_Read_MotAg1VltgFltCnt_Val is missing
#endif
#define Rte_Read_MotAg1VltgFltCnt_Val(data) (*(data) = MotAg1Meas_Ip_MotAg1VltgFltCnt)

#ifdef Rte_Read_MotAg1WarnReg_Val
# undef Rte_Read_MotAg1WarnReg_Val
#else
#error Rte_Read_MotAg1WarnReg_Val is missing
#endif
#define Rte_Read_MotAg1WarnReg_Val(data) (*(data) = MotAg1Meas_Ip_MotAg1WarnReg)

#ifdef Rte_Read_MotAg4Mecl_Val
# undef Rte_Read_MotAg4Mecl_Val
#else
#error Rte_Read_MotAg4Mecl_Val is missing
#endif
#define Rte_Read_MotAg4Mecl_Val(data) (*(data) = MotAg1Meas_Ip_MotAg4Mecl)


/*** Output Stubs ***/

#ifdef Rte_Write_MotAg1MeclQlfr_Val
# undef Rte_Write_MotAg1MeclQlfr_Val
#else
#error Rte_Write_MotAg1MeclQlfr_Val is missing
#endif
#define Rte_Write_MotAg1MeclQlfr_Val(data) (MotAg1Meas_Op_MotAg1MeclQlfr = (data))

#ifdef Rte_Write_MotAg1QepFaild_Logl
# undef Rte_Write_MotAg1QepFaild_Logl
#else
#error Rte_Write_MotAg1QepFaild_Logl is missing
#endif
#define Rte_Write_MotAg1QepFaild_Logl(data) (MotAg1Meas_Op_MotAg1QepFaild = (data))

#ifdef Rte_Write_MotAg1TurnCntr_Val
# undef Rte_Write_MotAg1TurnCntr_Val
#else
#error Rte_Write_MotAg1TurnCntr_Val is missing
#endif
#define Rte_Write_MotAg1TurnCntr_Val(data) (MotAg1Meas_Op_MotAg1TurnCntr = (data))

#ifdef Rte_Write_MotAg1TurnCntrQlfr_Val
# undef Rte_Write_MotAg1TurnCntrQlfr_Val
#else
#error Rte_Write_MotAg1TurnCntrQlfr_Val is missing
#endif
#define Rte_Write_MotAg1TurnCntrQlfr_Val(data) (MotAg1Meas_Op_MotAg1TurnCntrQlfr = (data))

#ifdef Rte_Write_MotAg1TurnCntrRollgCntr_Val
# undef Rte_Write_MotAg1TurnCntrRollgCntr_Val
#else
#error Rte_Write_MotAg1TurnCntrRollgCntr_Val is missing
#endif
#define Rte_Write_MotAg1TurnCntrRollgCntr_Val(data) (MotAg1Meas_Op_MotAg1TurnCntrRollgCntr = (data))


/*** Calibration Stubs ***/

#ifdef Rte_Prm_MotAg1MeasOffs_Val
# undef Rte_Prm_MotAg1MeasOffs_Val
#else
#error Rte_Prm_MotAg1MeasOffs_Val is missing
#endif
#define Rte_Prm_MotAg1MeasOffs_Val() (MotAg1Meas_Cal_MotAg1MeasOffs)

#ifdef Rte_Prm_MotAg1MeasSnsrIfErrNtcMask_Val
# undef Rte_Prm_MotAg1MeasSnsrIfErrNtcMask_Val
#else
#error Rte_Prm_MotAg1MeasSnsrIfErrNtcMask_Val is missing
#endif
#define Rte_Prm_MotAg1MeasSnsrIfErrNtcMask_Val() (MotAg1Meas_Cal_MotAg1MeasSnsrIfErrNtcMask)


/*** PIM Stubs ***/

#ifdef Rte_Pim_MotAg1CoeffTbl
# undef Rte_Pim_MotAg1CoeffTbl
#else
#error Rte_Pim_MotAg1CoeffTbl is missing
#endif
#define Rte_Pim_MotAg1CoeffTbl() (&(MotAg1Meas_Pim_MotAg1CoeffTbl[0]))

#ifdef Rte_Pim_dMotAg1MeasMotAg1Delta
# undef Rte_Pim_dMotAg1MeasMotAg1Delta
#else
#error Rte_Pim_dMotAg1MeasMotAg1Delta is missing
#endif
#define Rte_Pim_dMotAg1MeasMotAg1Delta() (&MotAg1Meas_Pim_dMotAg1MeasMotAg1Delta)

#ifdef Rte_Pim_dMotAg1MeasMotAg1RawAgReg
# undef Rte_Pim_dMotAg1MeasMotAg1RawAgReg
#else
#error Rte_Pim_dMotAg1MeasMotAg1RawAgReg is missing
#endif
#define Rte_Pim_dMotAg1MeasMotAg1RawAgReg() (&MotAg1Meas_Pim_dMotAg1MeasMotAg1RawAgReg)

#ifdef Rte_Pim_dMotAg1MeasMotAg1RawErrReg
# undef Rte_Pim_dMotAg1MeasMotAg1RawErrReg
#else
#error Rte_Pim_dMotAg1MeasMotAg1RawErrReg is missing
#endif
#define Rte_Pim_dMotAg1MeasMotAg1RawErrReg() (&MotAg1Meas_Pim_dMotAg1MeasMotAg1RawErrReg)

#ifdef Rte_Pim_dMotAg1MeasMotAg1RawStsReg
# undef Rte_Pim_dMotAg1MeasMotAg1RawStsReg
#else
#error Rte_Pim_dMotAg1MeasMotAg1RawStsReg is missing
#endif
#define Rte_Pim_dMotAg1MeasMotAg1RawStsReg() (&MotAg1Meas_Pim_dMotAg1MeasMotAg1RawStsReg)

#ifdef Rte_Pim_dMotAg1MeasMotAg1RawTurnCntrReg
# undef Rte_Pim_dMotAg1MeasMotAg1RawTurnCntrReg
#else
#error Rte_Pim_dMotAg1MeasMotAg1RawTurnCntrReg is missing
#endif
#define Rte_Pim_dMotAg1MeasMotAg1RawTurnCntrReg() (&MotAg1Meas_Pim_dMotAg1MeasMotAg1RawTurnCntrReg)

#ifdef Rte_Pim_dMotAg1MeasMotAg1RawWarnReg
# undef Rte_Pim_dMotAg1MeasMotAg1RawWarnReg
#else
#error Rte_Pim_dMotAg1MeasMotAg1RawWarnReg is missing
#endif
#define Rte_Pim_dMotAg1MeasMotAg1RawWarnReg() (&MotAg1Meas_Pim_dMotAg1MeasMotAg1RawWarnReg)

#ifdef Rte_Pim_dMotAg1MeasMotAg1RtOffs
# undef Rte_Pim_dMotAg1MeasMotAg1RtOffs
#else
#error Rte_Pim_dMotAg1MeasMotAg1RtOffs is missing
#endif
#define Rte_Pim_dMotAg1MeasMotAg1RtOffs() (&MotAg1Meas_Pim_dMotAg1MeasMotAg1RtOffs)

#ifdef Rte_Pim_dMotAg1MeasPwrRstStsLtch
# undef Rte_Pim_dMotAg1MeasPwrRstStsLtch
#else
#error Rte_Pim_dMotAg1MeasPwrRstStsLtch is missing
#endif
#define Rte_Pim_dMotAg1MeasPwrRstStsLtch() (&MotAg1Meas_Pim_dMotAg1MeasPwrRstStsLtch)

#ifdef Rte_Pim_MotAg1CorrnTbl
# undef Rte_Pim_MotAg1CorrnTbl
#else
#error Rte_Pim_MotAg1CorrnTbl is missing
#endif
#define Rte_Pim_MotAg1CorrnTbl() (&(MotAg1Meas_Pim_MotAg1CorrnTbl[0]))

#ifdef Rte_Pim_MotAg1InitOffs
# undef Rte_Pim_MotAg1InitOffs
#else
#error Rte_Pim_MotAg1InitOffs is missing
#endif
#define Rte_Pim_MotAg1InitOffs() (&MotAg1Meas_Pim_MotAg1InitOffs)

#ifdef Rte_Pim_MotAg1InitOffsCntr
# undef Rte_Pim_MotAg1InitOffsCntr
#else
#error Rte_Pim_MotAg1InitOffsCntr is missing
#endif
#define Rte_Pim_MotAg1InitOffsCntr() (&MotAg1Meas_Pim_MotAg1InitOffsCntr)

#ifdef Rte_Pim_MotAg1MeclRollgCntrPrev
# undef Rte_Pim_MotAg1MeclRollgCntrPrev
#else
#error Rte_Pim_MotAg1MeclRollgCntrPrev is missing
#endif
#define Rte_Pim_MotAg1MeclRollgCntrPrev() (&MotAg1Meas_Pim_MotAg1MeclRollgCntrPrev)

#ifdef Rte_Pim_MotAg1ParFltCntNtcPrev
# undef Rte_Pim_MotAg1ParFltCntNtcPrev
#else
#error Rte_Pim_MotAg1ParFltCntNtcPrev is missing
#endif
#define Rte_Pim_MotAg1ParFltCntNtcPrev() (&MotAg1Meas_Pim_MotAg1ParFltCntNtcPrev)

#ifdef Rte_Pim_MotAg1ParFltCntPrev
# undef Rte_Pim_MotAg1ParFltCntPrev
#else
#error Rte_Pim_MotAg1ParFltCntPrev is missing
#endif
#define Rte_Pim_MotAg1ParFltCntPrev() (&MotAg1Meas_Pim_MotAg1ParFltCntPrev)

#ifdef Rte_Pim_MotAg1PrevSpiMecl
# undef Rte_Pim_MotAg1PrevSpiMecl
#else
#error Rte_Pim_MotAg1PrevSpiMecl is missing
#endif
#define Rte_Pim_MotAg1PrevSpiMecl() (&MotAg1Meas_Pim_MotAg1PrevSpiMecl)

#ifdef Rte_Pim_MotAg1PrevTCUpd
# undef Rte_Pim_MotAg1PrevTCUpd
#else
#error Rte_Pim_MotAg1PrevTCUpd is missing
#endif
#define Rte_Pim_MotAg1PrevTCUpd() (&MotAg1Meas_Pim_MotAg1PrevTCUpd)

#ifdef Rte_Pim_MotAg1QepFaildCntr
# undef Rte_Pim_MotAg1QepFaildCntr
#else
#error Rte_Pim_MotAg1QepFaildCntr is missing
#endif
#define Rte_Pim_MotAg1QepFaildCntr() (&MotAg1Meas_Pim_MotAg1QepFaildCntr)

#ifdef Rte_Pim_MotAg1QepFaildPrev
# undef Rte_Pim_MotAg1QepFaildPrev
#else
#error Rte_Pim_MotAg1QepFaildPrev is missing
#endif
#define Rte_Pim_MotAg1QepFaildPrev() (&MotAg1Meas_Pim_MotAg1QepFaildPrev)

#ifdef Rte_Pim_MotAg1RawMeclPrev
# undef Rte_Pim_MotAg1RawMeclPrev
#else
#error Rte_Pim_MotAg1RawMeclPrev is missing
#endif
#define Rte_Pim_MotAg1RawMeclPrev() (&MotAg1Meas_Pim_MotAg1RawMeclPrev)

#ifdef Rte_Pim_MotAg1TurnCntrParFltCntNtcPrev
# undef Rte_Pim_MotAg1TurnCntrParFltCntNtcPrev
#else
#error Rte_Pim_MotAg1TurnCntrParFltCntNtcPrev is missing
#endif
#define Rte_Pim_MotAg1TurnCntrParFltCntNtcPrev() (&MotAg1Meas_Pim_MotAg1TurnCntrParFltCntNtcPrev)

#ifdef Rte_Pim_MotAg1TurnCntrParFltCntPrev
# undef Rte_Pim_MotAg1TurnCntrParFltCntPrev
#else
#error Rte_Pim_MotAg1TurnCntrParFltCntPrev is missing
#endif
#define Rte_Pim_MotAg1TurnCntrParFltCntPrev() (&MotAg1Meas_Pim_MotAg1TurnCntrParFltCntPrev)

#ifdef Rte_Pim_MotAg1TurnCntrPrev
# undef Rte_Pim_MotAg1TurnCntrPrev
#else
#error Rte_Pim_MotAg1TurnCntrPrev is missing
#endif
#define Rte_Pim_MotAg1TurnCntrPrev() (&MotAg1Meas_Pim_MotAg1TurnCntrPrev)

#ifdef Rte_Pim_MotAg1TurnCntrRollgCntrPrev
# undef Rte_Pim_MotAg1TurnCntrRollgCntrPrev
#else
#error Rte_Pim_MotAg1TurnCntrRollgCntrPrev is missing
#endif
#define Rte_Pim_MotAg1TurnCntrRollgCntrPrev() (&MotAg1Meas_Pim_MotAg1TurnCntrRollgCntrPrev)

#ifdef Rte_Pim_MotAg1VltgFltCntNtcPrev
# undef Rte_Pim_MotAg1VltgFltCntNtcPrev
#else
#error Rte_Pim_MotAg1VltgFltCntNtcPrev is missing
#endif
#define Rte_Pim_MotAg1VltgFltCntNtcPrev() (&MotAg1Meas_Pim_MotAg1VltgFltCntNtcPrev)

#ifdef Rte_Pim_MotAg1VltgFltCntPrev
# undef Rte_Pim_MotAg1VltgFltCntPrev
#else
#error Rte_Pim_MotAg1VltgFltCntPrev is missing
#endif
#define Rte_Pim_MotAg1VltgFltCntPrev() (&MotAg1Meas_Pim_MotAg1VltgFltCntPrev)

#ifdef Rte_Pim_MotAgMecl1Polarity
# undef Rte_Pim_MotAgMecl1Polarity
#else
#error Rte_Pim_MotAgMecl1Polarity is missing
#endif
#define Rte_Pim_MotAgMecl1Polarity() (&MotAg1Meas_Pim_MotAgMecl1Polarity)


/*** Client Stub ***/

extern FUNC(void, AUTOMATIC) Rte_Stub(void);


#endif
