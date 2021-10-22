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
extern VAR(float32, AUTOMATIC) SteerCmdArbnAndLim_Ip_AssiLnrGain;
extern VAR(boolean, AUTOMATIC) SteerCmdArbnAndLim_Ip_AssiLnrGainEna;
extern VAR(float32, AUTOMATIC) SteerCmdArbnAndLim_Ip_EotCtrlSca;
extern VAR(float32, AUTOMATIC) SteerCmdArbnAndLim_Ip_FalbckAssiMotTqCmd;
extern VAR(float32, AUTOMATIC) SteerCmdArbnAndLim_Ip_HwTq;
extern VAR(float32, AUTOMATIC) SteerCmdArbnAndLim_Ip_LimdMotTqCmd;
extern VAR(float32, AUTOMATIC) SteerCmdArbnAndLim_Ip_MotTqCmd;
extern VAR(boolean, AUTOMATIC) SteerCmdArbnAndLim_Ip_MotTqCmdLimDi;
extern VAR(float32, AUTOMATIC) SteerCmdArbnAndLim_Ip_StallMotTqLim;
extern VAR(float32, AUTOMATIC) SteerCmdArbnAndLim_Ip_SysMotTqCmdSca;
extern VAR(float32, AUTOMATIC) SteerCmdArbnAndLim_Ip_ThermMotTqLim;
extern VAR(float32, AUTOMATIC) SteerCmdArbnAndLim_Ip_VehSpd;
extern VAR(float32, AUTOMATIC) SteerCmdArbnAndLim_Ip_VehSpdMotTqLim;

/* Outputs */
extern VAR(float32, AUTOMATIC) SteerCmdArbnAndLim_Op_ArbdMotTqCmd;
extern VAR(float32, AUTOMATIC) SteerCmdArbnAndLim_Op_MotTqCmdLimdPreStall;

/* Calibrations */
extern CONST(uint16, AUTOMATIC) SteerCmdArbnAndLim_Cal_SteerCmdArbnAndLimFalbckTiThd;
extern CONST(uint16, AUTOMATIC) SteerCmdArbnAndLim_Cal_SteerCmdArbnAndLimFwTiThd;

/* PIMs */
extern VAR(boolean, AUTOMATIC) SteerCmdArbnAndLim_Pim_FalbckDebStVari;
extern VAR(boolean, AUTOMATIC) SteerCmdArbnAndLim_Pim_FwDebStVari;
extern VAR(uint32, AUTOMATIC) SteerCmdArbnAndLim_Pim_SteerCmdArbnAndLimDebStFalbck;
extern VAR(uint32, AUTOMATIC) SteerCmdArbnAndLim_Pim_SteerCmdArbnAndLimDebStFw;
extern VAR(uint8, AUTOMATIC) SteerCmdArbnAndLim_Pim_SteerCmdArbnAndLimSt;

/* IRVs */
extern VAR(float32, AUTOMATIC) SteerCmdArbnAndLim_Irv_ProcdManTqCmd;
extern VAR(boolean, AUTOMATIC) SteerCmdArbnAndLim_Irv_ProcdManTqCmdEna;

/* Arguments and Returns */
extern VAR(uint32, AUTOMATIC) SteerCmdArbnAndLim_Srv_GetRefTmr100MicroSec32bit_RefTmr;
extern VAR(uint32, AUTOMATIC) SteerCmdArbnAndLim_Srv_GetTiSpan100MicroSec32bit_RefTmr;
extern VAR(uint32, AUTOMATIC) SteerCmdArbnAndLim_Srv_GetTiSpan100MicroSec32bit_TiSpan;
extern VAR(float32, AUTOMATIC) SteerCmdArbnAndLim_Cli_SetManTqCmd_ManTqCmd;
extern VAR(boolean, AUTOMATIC) SteerCmdArbnAndLim_Cli_SetManTqCmd_ManTqCmdEna;
extern VAR(Std_ReturnType, AUTOMATIC) SteerCmdArbnAndLim_Cli_SetManTqCmd_Return;
extern VAR(NtcNr1, AUTOMATIC) SteerCmdArbnAndLim_Srv_SetNtcSts_NtcNr;
extern VAR(uint8, AUTOMATIC) SteerCmdArbnAndLim_Srv_SetNtcSts_NtcStInfo;
extern VAR(NtcSts1, AUTOMATIC) SteerCmdArbnAndLim_Srv_SetNtcSts_NtcSts;
extern VAR(uint16, AUTOMATIC) SteerCmdArbnAndLim_Srv_SetNtcSts_DebStep;
extern VAR(Std_ReturnType, AUTOMATIC) SteerCmdArbnAndLim_Srv_SetNtcSts_Return;

/*** Input Stubs ***/

#ifdef Rte_Read_AssiLnrGain_Val
# undef Rte_Read_AssiLnrGain_Val
#else
#error Rte_Read_AssiLnrGain_Val is missing
#endif
#define Rte_Read_AssiLnrGain_Val(data) (*(data) = SteerCmdArbnAndLim_Ip_AssiLnrGain)

#ifdef Rte_Read_AssiLnrGainEna_Logl
# undef Rte_Read_AssiLnrGainEna_Logl
#else
#error Rte_Read_AssiLnrGainEna_Logl is missing
#endif
#define Rte_Read_AssiLnrGainEna_Logl(data) (*(data) = SteerCmdArbnAndLim_Ip_AssiLnrGainEna)

#ifdef Rte_Read_EotCtrlSca_Val
# undef Rte_Read_EotCtrlSca_Val
#else
#error Rte_Read_EotCtrlSca_Val is missing
#endif
#define Rte_Read_EotCtrlSca_Val(data) (*(data) = SteerCmdArbnAndLim_Ip_EotCtrlSca)

#ifdef Rte_Read_FalbckAssiMotTqCmd_Val
# undef Rte_Read_FalbckAssiMotTqCmd_Val
#else
#error Rte_Read_FalbckAssiMotTqCmd_Val is missing
#endif
#define Rte_Read_FalbckAssiMotTqCmd_Val(data) (*(data) = SteerCmdArbnAndLim_Ip_FalbckAssiMotTqCmd)

#ifdef Rte_Read_HwTq_Val
# undef Rte_Read_HwTq_Val
#else
#error Rte_Read_HwTq_Val is missing
#endif
#define Rte_Read_HwTq_Val(data) (*(data) = SteerCmdArbnAndLim_Ip_HwTq)

#ifdef Rte_Read_LimdMotTqCmd_Val
# undef Rte_Read_LimdMotTqCmd_Val
#else
#error Rte_Read_LimdMotTqCmd_Val is missing
#endif
#define Rte_Read_LimdMotTqCmd_Val(data) (*(data) = SteerCmdArbnAndLim_Ip_LimdMotTqCmd)

#ifdef Rte_Read_MotTqCmd_Val
# undef Rte_Read_MotTqCmd_Val
#else
#error Rte_Read_MotTqCmd_Val is missing
#endif
#define Rte_Read_MotTqCmd_Val(data) (*(data) = SteerCmdArbnAndLim_Ip_MotTqCmd)

#ifdef Rte_Read_MotTqCmdLimDi_Logl
# undef Rte_Read_MotTqCmdLimDi_Logl
#else
#error Rte_Read_MotTqCmdLimDi_Logl is missing
#endif
#define Rte_Read_MotTqCmdLimDi_Logl(data) (*(data) = SteerCmdArbnAndLim_Ip_MotTqCmdLimDi)

#ifdef Rte_Read_StallMotTqLim_Val
# undef Rte_Read_StallMotTqLim_Val
#else
#error Rte_Read_StallMotTqLim_Val is missing
#endif
#define Rte_Read_StallMotTqLim_Val(data) (*(data) = SteerCmdArbnAndLim_Ip_StallMotTqLim)

#ifdef Rte_Read_SysMotTqCmdSca_Val
# undef Rte_Read_SysMotTqCmdSca_Val
#else
#error Rte_Read_SysMotTqCmdSca_Val is missing
#endif
#define Rte_Read_SysMotTqCmdSca_Val(data) (*(data) = SteerCmdArbnAndLim_Ip_SysMotTqCmdSca)

#ifdef Rte_Read_ThermMotTqLim_Val
# undef Rte_Read_ThermMotTqLim_Val
#else
#error Rte_Read_ThermMotTqLim_Val is missing
#endif
#define Rte_Read_ThermMotTqLim_Val(data) (*(data) = SteerCmdArbnAndLim_Ip_ThermMotTqLim)

#ifdef Rte_Read_VehSpd_Val
# undef Rte_Read_VehSpd_Val
#else
#error Rte_Read_VehSpd_Val is missing
#endif
#define Rte_Read_VehSpd_Val(data) (*(data) = SteerCmdArbnAndLim_Ip_VehSpd)

#ifdef Rte_Read_VehSpdMotTqLim_Val
# undef Rte_Read_VehSpdMotTqLim_Val
#else
#error Rte_Read_VehSpdMotTqLim_Val is missing
#endif
#define Rte_Read_VehSpdMotTqLim_Val(data) (*(data) = SteerCmdArbnAndLim_Ip_VehSpdMotTqLim)


/*** Output Stubs ***/

#ifdef Rte_Write_ArbdMotTqCmd_Val
# undef Rte_Write_ArbdMotTqCmd_Val
#else
#error Rte_Write_ArbdMotTqCmd_Val is missing
#endif
#define Rte_Write_ArbdMotTqCmd_Val(data) (SteerCmdArbnAndLim_Op_ArbdMotTqCmd = (data))

#ifdef Rte_Write_MotTqCmdLimdPreStall_Val
# undef Rte_Write_MotTqCmdLimdPreStall_Val
#else
#error Rte_Write_MotTqCmdLimdPreStall_Val is missing
#endif
#define Rte_Write_MotTqCmdLimdPreStall_Val(data) (SteerCmdArbnAndLim_Op_MotTqCmdLimdPreStall = (data))


/*** Calibration Stubs ***/

#ifdef Rte_Prm_SteerCmdArbnAndLimFalbckTiThd_Val
# undef Rte_Prm_SteerCmdArbnAndLimFalbckTiThd_Val
#else
#error Rte_Prm_SteerCmdArbnAndLimFalbckTiThd_Val is missing
#endif
#define Rte_Prm_SteerCmdArbnAndLimFalbckTiThd_Val() (SteerCmdArbnAndLim_Cal_SteerCmdArbnAndLimFalbckTiThd)

#ifdef Rte_Prm_SteerCmdArbnAndLimFwTiThd_Val
# undef Rte_Prm_SteerCmdArbnAndLimFwTiThd_Val
#else
#error Rte_Prm_SteerCmdArbnAndLimFwTiThd_Val is missing
#endif
#define Rte_Prm_SteerCmdArbnAndLimFwTiThd_Val() (SteerCmdArbnAndLim_Cal_SteerCmdArbnAndLimFwTiThd)


/*** PIM Stubs ***/

#ifdef Rte_Pim_FalbckDebStVari
# undef Rte_Pim_FalbckDebStVari
#else
#error Rte_Pim_FalbckDebStVari is missing
#endif
#define Rte_Pim_FalbckDebStVari() (&SteerCmdArbnAndLim_Pim_FalbckDebStVari)

#ifdef Rte_Pim_FwDebStVari
# undef Rte_Pim_FwDebStVari
#else
#error Rte_Pim_FwDebStVari is missing
#endif
#define Rte_Pim_FwDebStVari() (&SteerCmdArbnAndLim_Pim_FwDebStVari)

#ifdef Rte_Pim_SteerCmdArbnAndLimDebStFalbck
# undef Rte_Pim_SteerCmdArbnAndLimDebStFalbck
#else
#error Rte_Pim_SteerCmdArbnAndLimDebStFalbck is missing
#endif
#define Rte_Pim_SteerCmdArbnAndLimDebStFalbck() (&SteerCmdArbnAndLim_Pim_SteerCmdArbnAndLimDebStFalbck)

#ifdef Rte_Pim_SteerCmdArbnAndLimDebStFw
# undef Rte_Pim_SteerCmdArbnAndLimDebStFw
#else
#error Rte_Pim_SteerCmdArbnAndLimDebStFw is missing
#endif
#define Rte_Pim_SteerCmdArbnAndLimDebStFw() (&SteerCmdArbnAndLim_Pim_SteerCmdArbnAndLimDebStFw)

#ifdef Rte_Pim_SteerCmdArbnAndLimSt
# undef Rte_Pim_SteerCmdArbnAndLimSt
#else
#error Rte_Pim_SteerCmdArbnAndLimSt is missing
#endif
#define Rte_Pim_SteerCmdArbnAndLimSt() (&SteerCmdArbnAndLim_Pim_SteerCmdArbnAndLimSt)


/*** IRV Stubs ***/

#ifdef Rte_IrvRead_SteerCmdArbnAndLimPer1_ProcdManTqCmd
# undef Rte_IrvRead_SteerCmdArbnAndLimPer1_ProcdManTqCmd
#else
#error ProcdManTqCmd is missing
#endif
#define Rte_IrvRead_SteerCmdArbnAndLimPer1_ProcdManTqCmd() (SteerCmdArbnAndLim_Irv_ProcdManTqCmd)

#ifdef Rte_IrvWrite_SetManTqCmd_Oper_ProcdManTqCmd
# undef Rte_IrvWrite_SetManTqCmd_Oper_ProcdManTqCmd
#else
#error ProcdManTqCmd is missing
#endif
#define Rte_IrvWrite_SetManTqCmd_Oper_ProcdManTqCmd(data) (SteerCmdArbnAndLim_Irv_ProcdManTqCmd = (data))

#ifdef Rte_IrvRead_SteerCmdArbnAndLimPer1_ProcdManTqCmdEna
# undef Rte_IrvRead_SteerCmdArbnAndLimPer1_ProcdManTqCmdEna
#else
#error ProcdManTqCmdEna is missing
#endif
#define Rte_IrvRead_SteerCmdArbnAndLimPer1_ProcdManTqCmdEna() (SteerCmdArbnAndLim_Irv_ProcdManTqCmdEna)

#ifdef Rte_IrvWrite_SetManTqCmd_Oper_ProcdManTqCmdEna
# undef Rte_IrvWrite_SetManTqCmd_Oper_ProcdManTqCmdEna
#else
#error ProcdManTqCmdEna is missing
#endif
#define Rte_IrvWrite_SetManTqCmd_Oper_ProcdManTqCmdEna(data) (SteerCmdArbnAndLim_Irv_ProcdManTqCmdEna = (data))


/*** Client Stub ***/

extern FUNC(void, AUTOMATIC) Rte_Stub(void);


#endif
