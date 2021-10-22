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
extern VAR(float32, AUTOMATIC) BmwSplyCurrLim_Ip_BmwMaxCurrLimr;
extern VAR(BmwMaxCurrLimrSts1, AUTOMATIC) BmwSplyCurrLim_Ip_BmwMaxCurrLimrSts;
extern VAR(float32, AUTOMATIC) BmwSplyCurrLim_Ip_BmwStrtStopLim;
extern VAR(boolean, AUTOMATIC) BmwSplyCurrLim_Ip_BmwStrtStopMsgActv;
extern VAR(float32, AUTOMATIC) BmwSplyCurrLim_Ip_BrdgVltg;
extern VAR(float32, AUTOMATIC) BmwSplyCurrLim_Ip_MaxCurrAtHiSpd;
extern VAR(float32, AUTOMATIC) BmwSplyCurrLim_Ip_MaxCurrAtLoSpd;
extern VAR(boolean, AUTOMATIC) BmwSplyCurrLim_Ip_RemCtrlPrkgEna;
extern VAR(float32, AUTOMATIC) BmwSplyCurrLim_Ip_SysMotTqCmdSca;
extern VAR(float32, AUTOMATIC) BmwSplyCurrLim_Ip_VehSpd;

/* Outputs */
extern VAR(float32, AUTOMATIC) BmwSplyCurrLim_Op_SplyCurrLim;

/* Calibrations */
extern CONST(float32, AUTOMATIC) BmwSplyCurrLim_Cal_BmwSplyCurrLimBmwMaxCurrLimMax;
extern CONST(float32, AUTOMATIC) BmwSplyCurrLim_Cal_BmwSplyCurrLimBmwMaxCurrLimMin;
extern CONST(float32, AUTOMATIC) BmwSplyCurrLim_Cal_BmwSplyCurrLimBmwMaxCurrLimrGrdt;
extern CONST(u6p10, AUTOMATIC) BmwSplyCurrLim_Cal_BmwSplyCurrLimDegradedVltgMaxCurrX[8];
extern CONST(u8p8, AUTOMATIC) BmwSplyCurrLim_Cal_BmwSplyCurrLimDegradedVltgMaxCurrY[8];
extern CONST(float32, AUTOMATIC) BmwSplyCurrLim_Cal_BmwSplyCurrLimEpsCpbyOffs;
extern CONST(float32, AUTOMATIC) BmwSplyCurrLim_Cal_BmwSplyCurrLimEpsMaxGrdt;
extern CONST(float32, AUTOMATIC) BmwSplyCurrLim_Cal_BmwSplyCurrLimEpsMinGrdt;
extern CONST(float32, AUTOMATIC) BmwSplyCurrLim_Cal_BmwSplyCurrLimMaxCurrLim;
extern CONST(u6p10, AUTOMATIC) BmwSplyCurrLim_Cal_BmwSplyCurrLimNormVltgMaxCurrX[8];
extern CONST(u8p8, AUTOMATIC) BmwSplyCurrLim_Cal_BmwSplyCurrLimNormVltgMaxCurrY[8];
extern CONST(float32, AUTOMATIC) BmwSplyCurrLim_Cal_BmwSplyCurrLimRemCtrlPrkgLim;
extern CONST(u9p7, AUTOMATIC) BmwSplyCurrLim_Cal_BmwSplyCurrLimVehSpdDptCurrLimX[6];
extern CONST(u8p8, AUTOMATIC) BmwSplyCurrLim_Cal_BmwSplyCurrLimVehSpdDptCurrLimY[6];
extern CONST(u6p10, AUTOMATIC) BmwSplyCurrLim_Cal_BmwSplyCurrLimVltgDptCurrGrdtDecX[8];
extern CONST(u16p0, AUTOMATIC) BmwSplyCurrLim_Cal_BmwSplyCurrLimVltgDptCurrGrdtDecY[8];
extern CONST(u6p10, AUTOMATIC) BmwSplyCurrLim_Cal_BmwSplyCurrLimVltgDptCurrGrdtIncX[8];
extern CONST(u16p0, AUTOMATIC) BmwSplyCurrLim_Cal_BmwSplyCurrLimVltgDptCurrGrdtIncY[8];
extern CONST(float32, AUTOMATIC) BmwSplyCurrLim_Cal_BmwSplyCurrLimVltgDptCurrLimFltThd;
extern CONST(float32, AUTOMATIC) BmwSplyCurrLim_Cal_BmwSplyCurrLimVrntMaxCurr;

/* PIMs */
extern VAR(float32, AUTOMATIC) BmwSplyCurrLim_Pim_dBmwSplyCurrLimBmwMaxCurrLim;
extern VAR(float32, AUTOMATIC) BmwSplyCurrLim_Pim_dBmwSplyCurrLimCurrLim;
extern VAR(float32, AUTOMATIC) BmwSplyCurrLim_Pim_dBmwSplyCurrLimCurrLimPrel;
extern VAR(float32, AUTOMATIC) BmwSplyCurrLim_Pim_dBmwSplyCurrLimGlbLim;
extern VAR(float32, AUTOMATIC) BmwSplyCurrLim_Pim_dBmwSplyCurrLimSplyCurrLim;
extern VAR(float32, AUTOMATIC) BmwSplyCurrLim_Pim_dBmwSplyCurrLimVehSpdDptCurrLim;
extern VAR(float32, AUTOMATIC) BmwSplyCurrLim_Pim_dBmwSplyCurrLimVltgDptCurrLim;
extern VAR(float32, AUTOMATIC) BmwSplyCurrLim_Pim_BmwMaxCurrLimGrdt;
extern VAR(float32, AUTOMATIC) BmwSplyCurrLim_Pim_SplyCurrLimGrdt;
extern VAR(float32, AUTOMATIC) BmwSplyCurrLim_Pim_VltgDptCurrLimGrdt;

/* Arguments and Returns */
extern VAR(NtcNr1, AUTOMATIC) BmwSplyCurrLim_Srv_SetNtcSts_NtcNr;
extern VAR(uint8, AUTOMATIC) BmwSplyCurrLim_Srv_SetNtcSts_NtcStInfo;
extern VAR(NtcSts1, AUTOMATIC) BmwSplyCurrLim_Srv_SetNtcSts_NtcSts;
extern VAR(uint16, AUTOMATIC) BmwSplyCurrLim_Srv_SetNtcSts_DebStep;
extern VAR(Std_ReturnType, AUTOMATIC) BmwSplyCurrLim_Srv_SetNtcSts_Return;


/*** Input Stubs ***/

#ifdef Rte_Read_BmwMaxCurrLimr_Val
# undef Rte_Read_BmwMaxCurrLimr_Val
#else
#error Rte_Read_BmwMaxCurrLimr_Val is missing
#endif
#define Rte_Read_BmwMaxCurrLimr_Val(data) (*(data) = BmwSplyCurrLim_Ip_BmwMaxCurrLimr)

#ifdef Rte_Read_BmwMaxCurrLimrSts_Val
# undef Rte_Read_BmwMaxCurrLimrSts_Val
#else
#error Rte_Read_BmwMaxCurrLimrSts_Val is missing
#endif
#define Rte_Read_BmwMaxCurrLimrSts_Val(data) (*(data) = BmwSplyCurrLim_Ip_BmwMaxCurrLimrSts)

#ifdef Rte_Read_BmwStrtStopLim_Val
# undef Rte_Read_BmwStrtStopLim_Val
#else
#error Rte_Read_BmwStrtStopLim_Val is missing
#endif
#define Rte_Read_BmwStrtStopLim_Val(data) (*(data) = BmwSplyCurrLim_Ip_BmwStrtStopLim)

#ifdef Rte_Read_BmwStrtStopMsgActv_Logl
# undef Rte_Read_BmwStrtStopMsgActv_Logl
#else
#error Rte_Read_BmwStrtStopMsgActv_Logl is missing
#endif
#define Rte_Read_BmwStrtStopMsgActv_Logl(data) (*(data) = BmwSplyCurrLim_Ip_BmwStrtStopMsgActv)

#ifdef Rte_Read_BrdgVltg_Val
# undef Rte_Read_BrdgVltg_Val
#else
#error Rte_Read_BrdgVltg_Val is missing
#endif
#define Rte_Read_BrdgVltg_Val(data) (*(data) = BmwSplyCurrLim_Ip_BrdgVltg)

#ifdef Rte_Read_MaxCurrAtHiSpd_Val
# undef Rte_Read_MaxCurrAtHiSpd_Val
#else
#error Rte_Read_MaxCurrAtHiSpd_Val is missing
#endif
#define Rte_Read_MaxCurrAtHiSpd_Val(data) (*(data) = BmwSplyCurrLim_Ip_MaxCurrAtHiSpd)

#ifdef Rte_Read_MaxCurrAtLoSpd_Val
# undef Rte_Read_MaxCurrAtLoSpd_Val
#else
#error Rte_Read_MaxCurrAtLoSpd_Val is missing
#endif
#define Rte_Read_MaxCurrAtLoSpd_Val(data) (*(data) = BmwSplyCurrLim_Ip_MaxCurrAtLoSpd)

#ifdef Rte_Read_RemCtrlPrkgEna_Logl
# undef Rte_Read_RemCtrlPrkgEna_Logl
#else
#error Rte_Read_RemCtrlPrkgEna_Logl is missing
#endif
#define Rte_Read_RemCtrlPrkgEna_Logl(data) (*(data) = BmwSplyCurrLim_Ip_RemCtrlPrkgEna)

#ifdef Rte_Read_SysMotTqCmdSca_Val
# undef Rte_Read_SysMotTqCmdSca_Val
#else
#error Rte_Read_SysMotTqCmdSca_Val is missing
#endif
#define Rte_Read_SysMotTqCmdSca_Val(data) (*(data) = BmwSplyCurrLim_Ip_SysMotTqCmdSca)

#ifdef Rte_Read_VehSpd_Val
# undef Rte_Read_VehSpd_Val
#else
#error Rte_Read_VehSpd_Val is missing
#endif
#define Rte_Read_VehSpd_Val(data) (*(data) = BmwSplyCurrLim_Ip_VehSpd)


/*** Output Stubs ***/

#ifdef Rte_Write_SplyCurrLim_Val
# undef Rte_Write_SplyCurrLim_Val
#else
#error Rte_Write_SplyCurrLim_Val is missing
#endif
#define Rte_Write_SplyCurrLim_Val(data) (BmwSplyCurrLim_Op_SplyCurrLim = (data))


/*** Calibration Stubs ***/

#ifdef Rte_Prm_BmwSplyCurrLimBmwMaxCurrLimMax_Val
# undef Rte_Prm_BmwSplyCurrLimBmwMaxCurrLimMax_Val
#else
#error Rte_Prm_BmwSplyCurrLimBmwMaxCurrLimMax_Val is missing
#endif
#define Rte_Prm_BmwSplyCurrLimBmwMaxCurrLimMax_Val() (BmwSplyCurrLim_Cal_BmwSplyCurrLimBmwMaxCurrLimMax)

#ifdef Rte_Prm_BmwSplyCurrLimBmwMaxCurrLimMin_Val
# undef Rte_Prm_BmwSplyCurrLimBmwMaxCurrLimMin_Val
#else
#error Rte_Prm_BmwSplyCurrLimBmwMaxCurrLimMin_Val is missing
#endif
#define Rte_Prm_BmwSplyCurrLimBmwMaxCurrLimMin_Val() (BmwSplyCurrLim_Cal_BmwSplyCurrLimBmwMaxCurrLimMin)

#ifdef Rte_Prm_BmwSplyCurrLimBmwMaxCurrLimrGrdt_Val
# undef Rte_Prm_BmwSplyCurrLimBmwMaxCurrLimrGrdt_Val
#else
#error Rte_Prm_BmwSplyCurrLimBmwMaxCurrLimrGrdt_Val is missing
#endif
#define Rte_Prm_BmwSplyCurrLimBmwMaxCurrLimrGrdt_Val() (BmwSplyCurrLim_Cal_BmwSplyCurrLimBmwMaxCurrLimrGrdt)

#ifdef Rte_Prm_BmwSplyCurrLimDegradedVltgMaxCurrX_Ary1D
# undef Rte_Prm_BmwSplyCurrLimDegradedVltgMaxCurrX_Ary1D
#else
#error Rte_Prm_BmwSplyCurrLimDegradedVltgMaxCurrX_Ary1D is missing
#endif
#define Rte_Prm_BmwSplyCurrLimDegradedVltgMaxCurrX_Ary1D() (&(BmwSplyCurrLim_Cal_BmwSplyCurrLimDegradedVltgMaxCurrX[0]))

#ifdef Rte_Prm_BmwSplyCurrLimDegradedVltgMaxCurrY_Ary1D
# undef Rte_Prm_BmwSplyCurrLimDegradedVltgMaxCurrY_Ary1D
#else
#error Rte_Prm_BmwSplyCurrLimDegradedVltgMaxCurrY_Ary1D is missing
#endif
#define Rte_Prm_BmwSplyCurrLimDegradedVltgMaxCurrY_Ary1D() (&(BmwSplyCurrLim_Cal_BmwSplyCurrLimDegradedVltgMaxCurrY[0]))

#ifdef Rte_Prm_BmwSplyCurrLimEpsCpbyOffs_Val
# undef Rte_Prm_BmwSplyCurrLimEpsCpbyOffs_Val
#else
#error Rte_Prm_BmwSplyCurrLimEpsCpbyOffs_Val is missing
#endif
#define Rte_Prm_BmwSplyCurrLimEpsCpbyOffs_Val() (BmwSplyCurrLim_Cal_BmwSplyCurrLimEpsCpbyOffs)

#ifdef Rte_Prm_BmwSplyCurrLimEpsMaxGrdt_Val
# undef Rte_Prm_BmwSplyCurrLimEpsMaxGrdt_Val
#else
#error Rte_Prm_BmwSplyCurrLimEpsMaxGrdt_Val is missing
#endif
#define Rte_Prm_BmwSplyCurrLimEpsMaxGrdt_Val() (BmwSplyCurrLim_Cal_BmwSplyCurrLimEpsMaxGrdt)

#ifdef Rte_Prm_BmwSplyCurrLimEpsMinGrdt_Val
# undef Rte_Prm_BmwSplyCurrLimEpsMinGrdt_Val
#else
#error Rte_Prm_BmwSplyCurrLimEpsMinGrdt_Val is missing
#endif
#define Rte_Prm_BmwSplyCurrLimEpsMinGrdt_Val() (BmwSplyCurrLim_Cal_BmwSplyCurrLimEpsMinGrdt)

#ifdef Rte_Prm_BmwSplyCurrLimMaxCurrLim_Val
# undef Rte_Prm_BmwSplyCurrLimMaxCurrLim_Val
#else
#error Rte_Prm_BmwSplyCurrLimMaxCurrLim_Val is missing
#endif
#define Rte_Prm_BmwSplyCurrLimMaxCurrLim_Val() (BmwSplyCurrLim_Cal_BmwSplyCurrLimMaxCurrLim)

#ifdef Rte_Prm_BmwSplyCurrLimNormVltgMaxCurrX_Ary1D
# undef Rte_Prm_BmwSplyCurrLimNormVltgMaxCurrX_Ary1D
#else
#error Rte_Prm_BmwSplyCurrLimNormVltgMaxCurrX_Ary1D is missing
#endif
#define Rte_Prm_BmwSplyCurrLimNormVltgMaxCurrX_Ary1D() (&(BmwSplyCurrLim_Cal_BmwSplyCurrLimNormVltgMaxCurrX[0]))

#ifdef Rte_Prm_BmwSplyCurrLimNormVltgMaxCurrY_Ary1D
# undef Rte_Prm_BmwSplyCurrLimNormVltgMaxCurrY_Ary1D
#else
#error Rte_Prm_BmwSplyCurrLimNormVltgMaxCurrY_Ary1D is missing
#endif
#define Rte_Prm_BmwSplyCurrLimNormVltgMaxCurrY_Ary1D() (&(BmwSplyCurrLim_Cal_BmwSplyCurrLimNormVltgMaxCurrY[0]))

#ifdef Rte_Prm_BmwSplyCurrLimRemCtrlPrkgLim_Val
# undef Rte_Prm_BmwSplyCurrLimRemCtrlPrkgLim_Val
#else
#error Rte_Prm_BmwSplyCurrLimRemCtrlPrkgLim_Val is missing
#endif
#define Rte_Prm_BmwSplyCurrLimRemCtrlPrkgLim_Val() (BmwSplyCurrLim_Cal_BmwSplyCurrLimRemCtrlPrkgLim)

#ifdef Rte_Prm_BmwSplyCurrLimVehSpdDptCurrLimX_Ary1D
# undef Rte_Prm_BmwSplyCurrLimVehSpdDptCurrLimX_Ary1D
#else
#error Rte_Prm_BmwSplyCurrLimVehSpdDptCurrLimX_Ary1D is missing
#endif
#define Rte_Prm_BmwSplyCurrLimVehSpdDptCurrLimX_Ary1D() (&(BmwSplyCurrLim_Cal_BmwSplyCurrLimVehSpdDptCurrLimX[0]))

#ifdef Rte_Prm_BmwSplyCurrLimVehSpdDptCurrLimY_Ary1D
# undef Rte_Prm_BmwSplyCurrLimVehSpdDptCurrLimY_Ary1D
#else
#error Rte_Prm_BmwSplyCurrLimVehSpdDptCurrLimY_Ary1D is missing
#endif
#define Rte_Prm_BmwSplyCurrLimVehSpdDptCurrLimY_Ary1D() (&(BmwSplyCurrLim_Cal_BmwSplyCurrLimVehSpdDptCurrLimY[0]))

#ifdef Rte_Prm_BmwSplyCurrLimVltgDptCurrGrdtDecX_Ary1D
# undef Rte_Prm_BmwSplyCurrLimVltgDptCurrGrdtDecX_Ary1D
#else
#error Rte_Prm_BmwSplyCurrLimVltgDptCurrGrdtDecX_Ary1D is missing
#endif
#define Rte_Prm_BmwSplyCurrLimVltgDptCurrGrdtDecX_Ary1D() (&(BmwSplyCurrLim_Cal_BmwSplyCurrLimVltgDptCurrGrdtDecX[0]))

#ifdef Rte_Prm_BmwSplyCurrLimVltgDptCurrGrdtDecY_Ary1D
# undef Rte_Prm_BmwSplyCurrLimVltgDptCurrGrdtDecY_Ary1D
#else
#error Rte_Prm_BmwSplyCurrLimVltgDptCurrGrdtDecY_Ary1D is missing
#endif
#define Rte_Prm_BmwSplyCurrLimVltgDptCurrGrdtDecY_Ary1D() (&(BmwSplyCurrLim_Cal_BmwSplyCurrLimVltgDptCurrGrdtDecY[0]))

#ifdef Rte_Prm_BmwSplyCurrLimVltgDptCurrGrdtIncX_Ary1D
# undef Rte_Prm_BmwSplyCurrLimVltgDptCurrGrdtIncX_Ary1D
#else
#error Rte_Prm_BmwSplyCurrLimVltgDptCurrGrdtIncX_Ary1D is missing
#endif
#define Rte_Prm_BmwSplyCurrLimVltgDptCurrGrdtIncX_Ary1D() (&(BmwSplyCurrLim_Cal_BmwSplyCurrLimVltgDptCurrGrdtIncX[0]))

#ifdef Rte_Prm_BmwSplyCurrLimVltgDptCurrGrdtIncY_Ary1D
# undef Rte_Prm_BmwSplyCurrLimVltgDptCurrGrdtIncY_Ary1D
#else
#error Rte_Prm_BmwSplyCurrLimVltgDptCurrGrdtIncY_Ary1D is missing
#endif
#define Rte_Prm_BmwSplyCurrLimVltgDptCurrGrdtIncY_Ary1D() (&(BmwSplyCurrLim_Cal_BmwSplyCurrLimVltgDptCurrGrdtIncY[0]))

#ifdef Rte_Prm_BmwSplyCurrLimVltgDptCurrLimFltThd_Val
# undef Rte_Prm_BmwSplyCurrLimVltgDptCurrLimFltThd_Val
#else
#error Rte_Prm_BmwSplyCurrLimVltgDptCurrLimFltThd_Val is missing
#endif
#define Rte_Prm_BmwSplyCurrLimVltgDptCurrLimFltThd_Val() (BmwSplyCurrLim_Cal_BmwSplyCurrLimVltgDptCurrLimFltThd)

#ifdef Rte_Prm_BmwSplyCurrLimVrntMaxCurr_Val
# undef Rte_Prm_BmwSplyCurrLimVrntMaxCurr_Val
#else
#error Rte_Prm_BmwSplyCurrLimVrntMaxCurr_Val is missing
#endif
#define Rte_Prm_BmwSplyCurrLimVrntMaxCurr_Val() (BmwSplyCurrLim_Cal_BmwSplyCurrLimVrntMaxCurr)


/*** PIM Stubs ***/

#ifdef Rte_Pim_dBmwSplyCurrLimBmwMaxCurrLim
# undef Rte_Pim_dBmwSplyCurrLimBmwMaxCurrLim
#else
#error Rte_Pim_dBmwSplyCurrLimBmwMaxCurrLim is missing
#endif
#define Rte_Pim_dBmwSplyCurrLimBmwMaxCurrLim() (&BmwSplyCurrLim_Pim_dBmwSplyCurrLimBmwMaxCurrLim)

#ifdef Rte_Pim_dBmwSplyCurrLimCurrLim
# undef Rte_Pim_dBmwSplyCurrLimCurrLim
#else
#error Rte_Pim_dBmwSplyCurrLimCurrLim is missing
#endif
#define Rte_Pim_dBmwSplyCurrLimCurrLim() (&BmwSplyCurrLim_Pim_dBmwSplyCurrLimCurrLim)

#ifdef Rte_Pim_dBmwSplyCurrLimCurrLimPrel
# undef Rte_Pim_dBmwSplyCurrLimCurrLimPrel
#else
#error Rte_Pim_dBmwSplyCurrLimCurrLimPrel is missing
#endif
#define Rte_Pim_dBmwSplyCurrLimCurrLimPrel() (&BmwSplyCurrLim_Pim_dBmwSplyCurrLimCurrLimPrel)

#ifdef Rte_Pim_dBmwSplyCurrLimGlbLim
# undef Rte_Pim_dBmwSplyCurrLimGlbLim
#else
#error Rte_Pim_dBmwSplyCurrLimGlbLim is missing
#endif
#define Rte_Pim_dBmwSplyCurrLimGlbLim() (&BmwSplyCurrLim_Pim_dBmwSplyCurrLimGlbLim)

#ifdef Rte_Pim_dBmwSplyCurrLimSplyCurrLim
# undef Rte_Pim_dBmwSplyCurrLimSplyCurrLim
#else
#error Rte_Pim_dBmwSplyCurrLimSplyCurrLim is missing
#endif
#define Rte_Pim_dBmwSplyCurrLimSplyCurrLim() (&BmwSplyCurrLim_Pim_dBmwSplyCurrLimSplyCurrLim)

#ifdef Rte_Pim_dBmwSplyCurrLimVehSpdDptCurrLim
# undef Rte_Pim_dBmwSplyCurrLimVehSpdDptCurrLim
#else
#error Rte_Pim_dBmwSplyCurrLimVehSpdDptCurrLim is missing
#endif
#define Rte_Pim_dBmwSplyCurrLimVehSpdDptCurrLim() (&BmwSplyCurrLim_Pim_dBmwSplyCurrLimVehSpdDptCurrLim)

#ifdef Rte_Pim_dBmwSplyCurrLimVltgDptCurrLim
# undef Rte_Pim_dBmwSplyCurrLimVltgDptCurrLim
#else
#error Rte_Pim_dBmwSplyCurrLimVltgDptCurrLim is missing
#endif
#define Rte_Pim_dBmwSplyCurrLimVltgDptCurrLim() (&BmwSplyCurrLim_Pim_dBmwSplyCurrLimVltgDptCurrLim)

#ifdef Rte_Pim_BmwMaxCurrLimGrdt
# undef Rte_Pim_BmwMaxCurrLimGrdt
#else
#error Rte_Pim_BmwMaxCurrLimGrdt is missing
#endif
#define Rte_Pim_BmwMaxCurrLimGrdt() (&BmwSplyCurrLim_Pim_BmwMaxCurrLimGrdt)

#ifdef Rte_Pim_SplyCurrLimGrdt
# undef Rte_Pim_SplyCurrLimGrdt
#else
#error Rte_Pim_SplyCurrLimGrdt is missing
#endif
#define Rte_Pim_SplyCurrLimGrdt() (&BmwSplyCurrLim_Pim_SplyCurrLimGrdt)

#ifdef Rte_Pim_VltgDptCurrLimGrdt
# undef Rte_Pim_VltgDptCurrLimGrdt
#else
#error Rte_Pim_VltgDptCurrLimGrdt is missing
#endif
#define Rte_Pim_VltgDptCurrLimGrdt() (&BmwSplyCurrLim_Pim_VltgDptCurrLimGrdt)


/*** Client Stub ***/

extern FUNC(void, AUTOMATIC) Rte_Stub(void);


#endif
