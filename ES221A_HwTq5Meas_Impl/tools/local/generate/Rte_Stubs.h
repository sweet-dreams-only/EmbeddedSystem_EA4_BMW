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


/*** Extern Statements ***/

/* Inputs */
extern VAR(float32, AUTOMATIC) HwTq5Meas_Ip_HwTq5RawFastAdcBuf;
extern VAR(sint8, AUTOMATIC) HwTq5Meas_Ip_HwTq5Polarity;
extern VAR(float32, AUTOMATIC) HwTq5Meas_Ip_HwTq5RawAdc;
extern VAR(boolean, AUTOMATIC) HwTq5Meas_Ip_HwTq5RawAdcAdcFaild;
extern VAR(boolean, AUTOMATIC) HwTq5Meas_Ip_HwTq5RawFastAdcAdcFaild;

/* Outputs */
extern VAR(float32, AUTOMATIC) HwTq5Meas_Op_HwTq5;
extern VAR(SigQlfr1, AUTOMATIC) HwTq5Meas_Op_HwTq5Qlfr;
extern VAR(uint8, AUTOMATIC) HwTq5Meas_Op_HwTq5RollgCntr;

/* Calibrations */
extern CONST(uint16, AUTOMATIC) HwTq5Meas_Cal_HwTq5MeasHwTq5PrtclFltFailStep;
extern CONST(uint16, AUTOMATIC) HwTq5Meas_Cal_HwTq5MeasHwTq5PrtclFltPassStep;
extern CONST(float32, AUTOMATIC) HwTq5Meas_Cal_HwTq5MeasHwTqRngHiLim;
extern CONST(float32, AUTOMATIC) HwTq5Meas_Cal_HwTq5MeasHwTqRngLoLim;
extern CONST(boolean, AUTOMATIC) HwTq5Meas_Cal_HwTq5MeasMovgAvrgFilEna;

/* PIMs */
extern VAR(HwTqOffsRec1, AUTOMATIC) HwTq5Meas_Pim_HwTq5Offs;
extern VAR(AnHwTqScaFacRec1, AUTOMATIC) HwTq5Meas_Pim_HwTq5Sca;
extern VAR(float32, AUTOMATIC) HwTq5Meas_Pim_HwTq5PrevHwTq5;
extern VAR(uint8, AUTOMATIC) HwTq5Meas_Pim_HwTq5PrevRollgCntr;
extern VAR(uint8, AUTOMATIC) HwTq5Meas_Pim_HwTq5RawFastAdcIdxCntr;

/* Arguments and Returns */
extern VAR(NtcNr1, AUTOMATIC) HwTq5Meas_Srv_GetNtcQlfrSts_NtcNr;
extern VAR(SigQlfr1, AUTOMATIC) HwTq5Meas_Srv_GetNtcQlfrSts_NtcQlfr;
extern VAR(Std_ReturnType, AUTOMATIC) HwTq5Meas_Srv_GetNtcQlfrSts_Return;
extern VAR(NtcNr1, AUTOMATIC) HwTq5Meas_Srv_SetNtcSts_NtcNr;
extern VAR(uint8, AUTOMATIC) HwTq5Meas_Srv_SetNtcSts_NtcStInfo;
extern VAR(NtcSts1, AUTOMATIC) HwTq5Meas_Srv_SetNtcSts_NtcSts;
extern VAR(uint16, AUTOMATIC) HwTq5Meas_Srv_SetNtcSts_DebStep;
extern VAR(Std_ReturnType, AUTOMATIC) HwTq5Meas_Srv_SetNtcSts_Return;
extern VAR(float32, AUTOMATIC) HwTq5Meas_Cli_HwTq5ReadSnsrSca_HwTqReadScaData;
extern VAR(float32, AUTOMATIC) HwTq5Meas_Cli_HwTq5ReadTrim_HwTqReadTrimData;
extern VAR(boolean, AUTOMATIC) HwTq5Meas_Cli_HwTq5TrimPrfmdSts_HwTqOffsTrimPrfmdStsData;
extern VAR(float32, AUTOMATIC) HwTq5Meas_Cli_HwTq5WrSnsrSca_HwTqScaVal;
extern VAR(float32, AUTOMATIC) HwTq5Meas_Cli_HwTq5WrTrim_HwTqWrOffsTrimData;


/*** Input Stubs ***/

#ifdef Rte_Read_HwTq5RawFastAdcBuf_Val
# undef Rte_Read_HwTq5RawFastAdcBuf_Val
#endif
#define Rte_Read_HwTq5RawFastAdcBuf_Val(data) (*(data) = HwTq5Meas_Ip_HwTq5RawFastAdcBuf)

#ifdef Rte_Read_HwTq5Polarity_Val
# undef Rte_Read_HwTq5Polarity_Val
#endif
#define Rte_Read_HwTq5Polarity_Val(data) (*(data) = HwTq5Meas_Ip_HwTq5Polarity)

#ifdef Rte_Read_HwTq5RawAdc_Val
# undef Rte_Read_HwTq5RawAdc_Val
#endif
#define Rte_Read_HwTq5RawAdc_Val(data) (*(data) = HwTq5Meas_Ip_HwTq5RawAdc)

#ifdef Rte_Read_HwTq5RawAdcAdcFaild_Logl
# undef Rte_Read_HwTq5RawAdcAdcFaild_Logl
#endif
#define Rte_Read_HwTq5RawAdcAdcFaild_Logl(data) (*(data) = HwTq5Meas_Ip_HwTq5RawAdcAdcFaild)

#ifdef Rte_Read_HwTq5RawFastAdcAdcFaild_Logl
# undef Rte_Read_HwTq5RawFastAdcAdcFaild_Logl
#endif
#define Rte_Read_HwTq5RawFastAdcAdcFaild_Logl(data) (*(data) = HwTq5Meas_Ip_HwTq5RawFastAdcAdcFaild)


/*** Output Stubs ***/

#ifdef Rte_Write_HwTq5_Val
# undef Rte_Write_HwTq5_Val
#endif
#define Rte_Write_HwTq5_Val(data) (HwTq5Meas_Op_HwTq5 = (data))

#ifdef Rte_Write_HwTq5Qlfr_Val
# undef Rte_Write_HwTq5Qlfr_Val
#endif
#define Rte_Write_HwTq5Qlfr_Val(data) (HwTq5Meas_Op_HwTq5Qlfr = (data))

#ifdef Rte_Write_HwTq5RollgCntr_Val
# undef Rte_Write_HwTq5RollgCntr_Val
#endif
#define Rte_Write_HwTq5RollgCntr_Val(data) (HwTq5Meas_Op_HwTq5RollgCntr = (data))


/*** Calibration Stubs ***/

#ifdef Rte_Prm_HwTq5MeasHwTq5PrtclFltFailStep_Val
# undef Rte_Prm_HwTq5MeasHwTq5PrtclFltFailStep_Val
#endif
#define Rte_Prm_HwTq5MeasHwTq5PrtclFltFailStep_Val() (HwTq5Meas_Cal_HwTq5MeasHwTq5PrtclFltFailStep)

#ifdef Rte_Prm_HwTq5MeasHwTq5PrtclFltPassStep_Val
# undef Rte_Prm_HwTq5MeasHwTq5PrtclFltPassStep_Val
#endif
#define Rte_Prm_HwTq5MeasHwTq5PrtclFltPassStep_Val() (HwTq5Meas_Cal_HwTq5MeasHwTq5PrtclFltPassStep)

#ifdef Rte_Prm_HwTq5MeasHwTqRngHiLim_Val
# undef Rte_Prm_HwTq5MeasHwTqRngHiLim_Val
#endif
#define Rte_Prm_HwTq5MeasHwTqRngHiLim_Val() (HwTq5Meas_Cal_HwTq5MeasHwTqRngHiLim)

#ifdef Rte_Prm_HwTq5MeasHwTqRngLoLim_Val
# undef Rte_Prm_HwTq5MeasHwTqRngLoLim_Val
#endif
#define Rte_Prm_HwTq5MeasHwTqRngLoLim_Val() (HwTq5Meas_Cal_HwTq5MeasHwTqRngLoLim)

#ifdef Rte_Prm_HwTq5MeasMovgAvrgFilEna_Logl
# undef Rte_Prm_HwTq5MeasMovgAvrgFilEna_Logl
#endif
#define Rte_Prm_HwTq5MeasMovgAvrgFilEna_Logl() (HwTq5Meas_Cal_HwTq5MeasMovgAvrgFilEna)


/*** PIM Stubs ***/

#ifdef Rte_Pim_HwTq5Offs
# undef Rte_Pim_HwTq5Offs
#endif
#define Rte_Pim_HwTq5Offs() (&HwTq5Meas_Pim_HwTq5Offs)

#ifdef Rte_Pim_HwTq5Sca
# undef Rte_Pim_HwTq5Sca
#endif
#define Rte_Pim_HwTq5Sca() (&HwTq5Meas_Pim_HwTq5Sca)

#ifdef Rte_Pim_HwTq5PrevHwTq5
# undef Rte_Pim_HwTq5PrevHwTq5
#endif
#define Rte_Pim_HwTq5PrevHwTq5() (&HwTq5Meas_Pim_HwTq5PrevHwTq5)

#ifdef Rte_Pim_HwTq5PrevRollgCntr
# undef Rte_Pim_HwTq5PrevRollgCntr
#endif
#define Rte_Pim_HwTq5PrevRollgCntr() (&HwTq5Meas_Pim_HwTq5PrevRollgCntr)

#ifdef Rte_Pim_HwTq5RawFastAdcIdxCntr
# undef Rte_Pim_HwTq5RawFastAdcIdxCntr
#endif
#define Rte_Pim_HwTq5RawFastAdcIdxCntr() (&HwTq5Meas_Pim_HwTq5RawFastAdcIdxCntr)


/*** Client Stub ***/

extern FUNC(void, AUTOMATIC) Rte_Stub(void);


#endif
