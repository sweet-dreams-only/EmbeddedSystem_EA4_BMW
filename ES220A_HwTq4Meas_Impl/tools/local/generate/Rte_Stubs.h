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
extern VAR(float32, AUTOMATIC) HwTq4Meas_Ip_HwTq4RawFastAdcBuf;
extern VAR(sint8, AUTOMATIC) HwTq4Meas_Ip_HwTq4Polarity;
extern VAR(float32, AUTOMATIC) HwTq4Meas_Ip_HwTq4RawAdc;
extern VAR(boolean, AUTOMATIC) HwTq4Meas_Ip_HwTq4RawAdcAdcFaild;
extern VAR(boolean, AUTOMATIC) HwTq4Meas_Ip_HwTq4RawFastAdcAdcFaild;

/* Outputs */
extern VAR(float32, AUTOMATIC) HwTq4Meas_Op_HwTq4;
extern VAR(SigQlfr1, AUTOMATIC) HwTq4Meas_Op_HwTq4Qlfr;
extern VAR(uint8, AUTOMATIC) HwTq4Meas_Op_HwTq4RollgCntr;

/* Calibrations */
extern CONST(uint16, AUTOMATIC) HwTq4Meas_Cal_HwTq4MeasHwTq4PrtclFltFailStep;
extern CONST(uint16, AUTOMATIC) HwTq4Meas_Cal_HwTq4MeasHwTq4PrtclFltPassStep;
extern CONST(float32, AUTOMATIC) HwTq4Meas_Cal_HwTq4MeasHwTqRngHiLim;
extern CONST(float32, AUTOMATIC) HwTq4Meas_Cal_HwTq4MeasHwTqRngLoLim;
extern CONST(boolean, AUTOMATIC) HwTq4Meas_Cal_HwTq4MeasMovgAvrgFilEna;

/* PIMs */
extern VAR(HwTqOffsRec1, AUTOMATIC) HwTq4Meas_Pim_HwTq4Offs;
extern VAR(AnHwTqScaFacRec1, AUTOMATIC) HwTq4Meas_Pim_HwTq4Sca;
extern VAR(float32, AUTOMATIC) HwTq4Meas_Pim_HwTq4PrevHwTq4;
extern VAR(uint8, AUTOMATIC) HwTq4Meas_Pim_HwTq4PrevRollgCntr;
extern VAR(uint8, AUTOMATIC) HwTq4Meas_Pim_HwTq4RawFastAdcIdxCntr;

/* Arguments and Returns */
extern VAR(NtcNr1, AUTOMATIC) HwTq4Meas_Srv_GetNtcQlfrSts_NtcNr;
extern VAR(SigQlfr1, AUTOMATIC) HwTq4Meas_Srv_GetNtcQlfrSts_NtcQlfr;
extern VAR(Std_ReturnType, AUTOMATIC) HwTq4Meas_Srv_GetNtcQlfrSts_Return;
extern VAR(boolean, AUTOMATIC) HwTq4Meas_Srv_HwTq4Offs_SetRamBlockStatus_BlockChanged;
extern VAR(Std_ReturnType, AUTOMATIC) HwTq4Meas_Srv_HwTq4Offs_SetRamBlockStatus_Return;
extern VAR(boolean, AUTOMATIC) HwTq4Meas_Srv_HwTq4Sca_SetRamBlockStatus_BlockChanged;
extern VAR(Std_ReturnType, AUTOMATIC) HwTq4Meas_Srv_HwTq4Sca_SetRamBlockStatus_Return;
extern VAR(NtcNr1, AUTOMATIC) HwTq4Meas_Srv_SetNtcSts_NtcNr;
extern VAR(uint8, AUTOMATIC) HwTq4Meas_Srv_SetNtcSts_NtcStInfo;
extern VAR(NtcSts1, AUTOMATIC) HwTq4Meas_Srv_SetNtcSts_NtcSts;
extern VAR(uint16, AUTOMATIC) HwTq4Meas_Srv_SetNtcSts_DebStep;
extern VAR(Std_ReturnType, AUTOMATIC) HwTq4Meas_Srv_SetNtcSts_Return;
extern VAR(float32, AUTOMATIC) HwTq4Meas_Cli_HwTq4ReadSnsrSca_HwTqReadScaData;
extern VAR(float32, AUTOMATIC) HwTq4Meas_Cli_HwTq4ReadTrim_HwTqReadTrimData;
extern VAR(boolean, AUTOMATIC) HwTq4Meas_Cli_HwTq4TrimPrfmdSts_HwTqOffsTrimPrfmdStsData;
extern VAR(float32, AUTOMATIC) HwTq4Meas_Cli_HwTq4WrSnsrSca_HwTqScaVal;
extern VAR(float32, AUTOMATIC) HwTq4Meas_Cli_HwTq4WrTrim_HwTqWrOffsTrimData;


/*** Input Stubs ***/

#ifdef Rte_Read_HwTq4RawFastAdcBuf_Val
# undef Rte_Read_HwTq4RawFastAdcBuf_Val
#endif
#define Rte_Read_HwTq4RawFastAdcBuf_Val(data) (*(data) = HwTq4Meas_Ip_HwTq4RawFastAdcBuf)

#ifdef Rte_Read_HwTq4Polarity_Val
# undef Rte_Read_HwTq4Polarity_Val
#endif
#define Rte_Read_HwTq4Polarity_Val(data) (*(data) = HwTq4Meas_Ip_HwTq4Polarity)

#ifdef Rte_Read_HwTq4RawAdc_Val
# undef Rte_Read_HwTq4RawAdc_Val
#endif
#define Rte_Read_HwTq4RawAdc_Val(data) (*(data) = HwTq4Meas_Ip_HwTq4RawAdc)

#ifdef Rte_Read_HwTq4RawAdcAdcFaild_Logl
# undef Rte_Read_HwTq4RawAdcAdcFaild_Logl
#endif
#define Rte_Read_HwTq4RawAdcAdcFaild_Logl(data) (*(data) = HwTq4Meas_Ip_HwTq4RawAdcAdcFaild)

#ifdef Rte_Read_HwTq4RawFastAdcAdcFaild_Logl
# undef Rte_Read_HwTq4RawFastAdcAdcFaild_Logl
#endif
#define Rte_Read_HwTq4RawFastAdcAdcFaild_Logl(data) (*(data) = HwTq4Meas_Ip_HwTq4RawFastAdcAdcFaild)


/*** Output Stubs ***/

#ifdef Rte_Write_HwTq4_Val
# undef Rte_Write_HwTq4_Val
#endif
#define Rte_Write_HwTq4_Val(data) (HwTq4Meas_Op_HwTq4 = (data))

#ifdef Rte_Write_HwTq4Qlfr_Val
# undef Rte_Write_HwTq4Qlfr_Val
#endif
#define Rte_Write_HwTq4Qlfr_Val(data) (HwTq4Meas_Op_HwTq4Qlfr = (data))

#ifdef Rte_Write_HwTq4RollgCntr_Val
# undef Rte_Write_HwTq4RollgCntr_Val
#endif
#define Rte_Write_HwTq4RollgCntr_Val(data) (HwTq4Meas_Op_HwTq4RollgCntr = (data))


/*** Calibration Stubs ***/

#ifdef Rte_Prm_HwTq4MeasHwTq4PrtclFltFailStep_Val
# undef Rte_Prm_HwTq4MeasHwTq4PrtclFltFailStep_Val
#endif
#define Rte_Prm_HwTq4MeasHwTq4PrtclFltFailStep_Val() (HwTq4Meas_Cal_HwTq4MeasHwTq4PrtclFltFailStep)

#ifdef Rte_Prm_HwTq4MeasHwTq4PrtclFltPassStep_Val
# undef Rte_Prm_HwTq4MeasHwTq4PrtclFltPassStep_Val
#endif
#define Rte_Prm_HwTq4MeasHwTq4PrtclFltPassStep_Val() (HwTq4Meas_Cal_HwTq4MeasHwTq4PrtclFltPassStep)

#ifdef Rte_Prm_HwTq4MeasHwTqRngHiLim_Val
# undef Rte_Prm_HwTq4MeasHwTqRngHiLim_Val
#endif
#define Rte_Prm_HwTq4MeasHwTqRngHiLim_Val() (HwTq4Meas_Cal_HwTq4MeasHwTqRngHiLim)

#ifdef Rte_Prm_HwTq4MeasHwTqRngLoLim_Val
# undef Rte_Prm_HwTq4MeasHwTqRngLoLim_Val
#endif
#define Rte_Prm_HwTq4MeasHwTqRngLoLim_Val() (HwTq4Meas_Cal_HwTq4MeasHwTqRngLoLim)

#ifdef Rte_Prm_HwTq4MeasMovgAvrgFilEna_Logl
# undef Rte_Prm_HwTq4MeasMovgAvrgFilEna_Logl
#endif
#define Rte_Prm_HwTq4MeasMovgAvrgFilEna_Logl() (HwTq4Meas_Cal_HwTq4MeasMovgAvrgFilEna)


/*** PIM Stubs ***/

#ifdef Rte_Pim_HwTq4Offs
# undef Rte_Pim_HwTq4Offs
#endif
#define Rte_Pim_HwTq4Offs() (&HwTq4Meas_Pim_HwTq4Offs)

#ifdef Rte_Pim_HwTq4Sca
# undef Rte_Pim_HwTq4Sca
#endif
#define Rte_Pim_HwTq4Sca() (&HwTq4Meas_Pim_HwTq4Sca)

#ifdef Rte_Pim_HwTq4PrevHwTq4
# undef Rte_Pim_HwTq4PrevHwTq4
#endif
#define Rte_Pim_HwTq4PrevHwTq4() (&HwTq4Meas_Pim_HwTq4PrevHwTq4)

#ifdef Rte_Pim_HwTq4PrevRollgCntr
# undef Rte_Pim_HwTq4PrevRollgCntr
#endif
#define Rte_Pim_HwTq4PrevRollgCntr() (&HwTq4Meas_Pim_HwTq4PrevRollgCntr)

#ifdef Rte_Pim_HwTq4RawFastAdcIdxCntr
# undef Rte_Pim_HwTq4RawFastAdcIdxCntr
#endif
#define Rte_Pim_HwTq4RawFastAdcIdxCntr() (&HwTq4Meas_Pim_HwTq4RawFastAdcIdxCntr)


/*** Client Stub ***/

extern FUNC(void, AUTOMATIC) Rte_Stub(void);


#endif
