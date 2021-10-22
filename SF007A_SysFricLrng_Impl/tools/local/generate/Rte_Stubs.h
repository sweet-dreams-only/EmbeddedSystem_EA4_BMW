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
extern VAR(float32, AUTOMATIC) SysFricLrng_Ip_AssiMechT;
extern VAR(boolean, AUTOMATIC) SysFricLrng_Ip_FricLrngCustEna;
extern VAR(boolean, AUTOMATIC) SysFricLrng_Ip_FricLrngDi;
extern VAR(float32, AUTOMATIC) SysFricLrng_Ip_HwAg;
extern VAR(float32, AUTOMATIC) SysFricLrng_Ip_HwAgAuthy;
extern VAR(float32, AUTOMATIC) SysFricLrng_Ip_HwTq;
extern VAR(float32, AUTOMATIC) SysFricLrng_Ip_HwVel;
extern VAR(float32, AUTOMATIC) SysFricLrng_Ip_MotTqCmdCrf;
extern VAR(float32, AUTOMATIC) SysFricLrng_Ip_VehLatA;
extern VAR(float32, AUTOMATIC) SysFricLrng_Ip_VehSpd;
extern VAR(boolean, AUTOMATIC) SysFricLrng_Ip_VehSpdVld;

/* Outputs */
extern VAR(float32, AUTOMATIC) SysFricLrng_Op_MaxLrndFric;
extern VAR(float32, AUTOMATIC) SysFricLrng_Op_SysFricEstimd;
extern VAR(float32, AUTOMATIC) SysFricLrng_Op_SysFricOffs;
extern VAR(float32, AUTOMATIC) SysFricLrng_Op_SysSatnFricEstimd;

/* Calibrations */
extern CONST(float32, AUTOMATIC) SysFricLrng_Cal_SysFricLrngAvrgFricFrq;
extern CONST(float32, AUTOMATIC) SysFricLrng_Cal_SysFricLrngBasLineEolFric;
extern CONST(float32, AUTOMATIC) SysFricLrng_Cal_SysFricLrngBasLineFric[4];
extern CONST(float32, AUTOMATIC) SysFricLrng_Cal_SysFricLrngBasLineHys[4][8];
extern CONST(uint16, AUTOMATIC) SysFricLrng_Cal_SysFricLrngBasLineRngCntr[3][8];
extern CONST(float32, AUTOMATIC) SysFricLrng_Cal_SysFricLrngDataPrepLpFilFrq;
extern CONST(uint16, AUTOMATIC) SysFricLrng_Cal_SysFricLrngDebStep;
extern CONST(float32, AUTOMATIC) SysFricLrng_Cal_SysFricLrngEolFricDifHiLim;
extern CONST(float32, AUTOMATIC) SysFricLrng_Cal_SysFricLrngEolFricDifLoLim;
extern CONST(float32, AUTOMATIC) SysFricLrng_Cal_SysFricLrngEolFricDifScagFac;
extern CONST(float32, AUTOMATIC) SysFricLrng_Cal_SysFricLrngFricChgWght[4];
extern CONST(float32, AUTOMATIC) SysFricLrng_Cal_SysFricLrngFricDiagcThd;
extern CONST(float32, AUTOMATIC) SysFricLrng_Cal_SysFricLrngFricHysHwAgPt[4];
extern CONST(float32, AUTOMATIC) SysFricLrng_Cal_SysFricLrngFricOffs;
extern CONST(float32, AUTOMATIC) SysFricLrng_Cal_SysFricLrngFricOffsHiLim;
extern CONST(float32, AUTOMATIC) SysFricLrng_Cal_SysFricLrngFricOffsLoLim;
extern CONST(float32, AUTOMATIC) SysFricLrng_Cal_SysFricLrngFricOffsLpFilFrq;
extern CONST(float32, AUTOMATIC) SysFricLrng_Cal_SysFricLrngGain;
extern CONST(uint16, AUTOMATIC) SysFricLrng_Cal_SysFricLrngHiFricDebStep;
extern CONST(float32, AUTOMATIC) SysFricLrng_Cal_SysFricLrngHiFricDiagcThd;
extern CONST(float32, AUTOMATIC) SysFricLrng_Cal_SysFricLrngHwPosnAuthyThd;
extern CONST(float32, AUTOMATIC) SysFricLrng_Cal_SysFricLrngHwVelConstrLim;
extern CONST(float32, AUTOMATIC) SysFricLrng_Cal_SysFricLrngHwVelHiLim;
extern CONST(float32, AUTOMATIC) SysFricLrng_Cal_SysFricLrngHwVelLoLim;
extern CONST(float32, AUTOMATIC) SysFricLrng_Cal_SysFricLrngIgnCycFricChgLim;
extern CONST(float32, AUTOMATIC) SysFricLrng_Cal_SysFricLrngIgnCycFricOffs;
extern CONST(u11p5, AUTOMATIC) SysFricLrng_Cal_SysFricLrngIvsTrsmRatX[10];
extern CONST(u6p10, AUTOMATIC) SysFricLrng_Cal_SysFricLrngIvsTrsmRatY[10];
extern CONST(float32, AUTOMATIC) SysFricLrng_Cal_SysFricLrngLatAHiLim;
extern CONST(float32, AUTOMATIC) SysFricLrng_Cal_SysFricLrngLatALoLim;
extern CONST(boolean, AUTOMATIC) SysFricLrng_Cal_SysFricLrngMaskVehSpd[4];
extern CONST(uint16, AUTOMATIC) SysFricLrng_Cal_SysFricLrngRngCntrThd;
extern CONST(float32, AUTOMATIC) SysFricLrng_Cal_SysFricLrngTHiLim;
extern CONST(float32, AUTOMATIC) SysFricLrng_Cal_SysFricLrngTLoLim;
extern CONST(uint32, AUTOMATIC) SysFricLrng_Cal_SysFricLrngThd;
extern CONST(float32, AUTOMATIC) SysFricLrng_Cal_SysFricLrngVehSpd[2][4];

/* PIMs */
extern VAR(SysFricDataRec1, AUTOMATIC) SysFricLrng_Pim_FricLrngData;
extern VAR(SysFricNonLrngDataRec1, AUTOMATIC) SysFricLrng_Pim_FricNonLrngData;
extern VAR(FilLpRec1, AUTOMATIC) SysFricLrng_Pim_AssiMechTLpFil;
extern VAR(FilLpRec1, AUTOMATIC) SysFricLrng_Pim_AvrgFricLpFil1;
extern VAR(FilLpRec1, AUTOMATIC) SysFricLrng_Pim_AvrgFricLpFil2;
extern VAR(FilLpRec1, AUTOMATIC) SysFricLrng_Pim_AvrgFricLpFil3;
extern VAR(FilLpRec1, AUTOMATIC) SysFricLrng_Pim_AvrgFricLpFil4;
extern VAR(float32, AUTOMATIC) SysFricLrng_Pim_ColTqAry[12];
extern VAR(FilLpRec1, AUTOMATIC) SysFricLrng_Pim_ColTqLpFil;
extern VAR(float32, AUTOMATIC) SysFricLrng_Pim_EstimdFric;
extern VAR(float32, AUTOMATIC) SysFricLrng_Pim_FilAvrgFric[4];
extern VAR(FilLpRec1, AUTOMATIC) SysFricLrng_Pim_FricChgLpFil;
extern VAR(SysFricLrngOperMod1, AUTOMATIC) SysFricLrng_Pim_FricLrngOperModPrev;
extern VAR(boolean, AUTOMATIC) SysFricLrng_Pim_FricLrngRunOneTi;
extern VAR(float32, AUTOMATIC) SysFricLrng_Pim_FricOffs;
extern VAR(boolean, AUTOMATIC) SysFricLrng_Pim_FricOffsOutpDi;
extern VAR(FilLpRec1, AUTOMATIC) SysFricLrng_Pim_HwAgAuthyLpFil;
extern VAR(float32, AUTOMATIC) SysFricLrng_Pim_HwAgBuf[12];
extern VAR(FilLpRec1, AUTOMATIC) SysFricLrng_Pim_HwAgLpFil;
extern VAR(float32, AUTOMATIC) SysFricLrng_Pim_HwVelBuf[12];
extern VAR(FilLpRec1, AUTOMATIC) SysFricLrng_Pim_HwVelLpFil;
extern VAR(FilLpRec1, AUTOMATIC) SysFricLrng_Pim_LatALpFil;
extern VAR(float32, AUTOMATIC) SysFricLrng_Pim_PrevMaxRawAvrgFric;
extern VAR(float32, AUTOMATIC) SysFricLrng_Pim_RawAvrgFric[4];
extern VAR(uint32, AUTOMATIC) SysFricLrng_Pim_RefTmrLrngConstr;
extern VAR(float32, AUTOMATIC) SysFricLrng_Pim_SatnAvrgFric[4];
extern VAR(float32, AUTOMATIC) SysFricLrng_Pim_SatnEstimdFric;
extern VAR(float32, AUTOMATIC) SysFricLrng_Pim_VehBasLineFric[4];
extern VAR(FilLpRec1, AUTOMATIC) SysFricLrng_Pim_VehSpdLpFil;

/* Arguments and Returns */
extern VAR(boolean, AUTOMATIC) SysFricLrng_Srv_FricLrngData_SetRamBlockStatus_BlockChanged;
extern VAR(Std_ReturnType, AUTOMATIC) SysFricLrng_Srv_FricLrngData_SetRamBlockStatus_Return;
extern VAR(boolean, AUTOMATIC) SysFricLrng_Srv_FricNonLrngData_SetRamBlockStatus_BlockChanged;
extern VAR(Std_ReturnType, AUTOMATIC) SysFricLrng_Srv_FricNonLrngData_SetRamBlockStatus_Return;
extern VAR(NtcNr1, AUTOMATIC) SysFricLrng_Srv_GetNtcQlfrSts_NtcNr;
extern VAR(SigQlfr1, AUTOMATIC) SysFricLrng_Srv_GetNtcQlfrSts_NtcQlfr;
extern VAR(Std_ReturnType, AUTOMATIC) SysFricLrng_Srv_GetNtcQlfrSts_Return;
extern VAR(uint32, AUTOMATIC) SysFricLrng_Srv_GetRefTmr100MicroSec32bit_RefTmr;
extern VAR(uint32, AUTOMATIC) SysFricLrng_Srv_GetTiSpan100MicroSec32bit_RefTmr;
extern VAR(uint32, AUTOMATIC) SysFricLrng_Srv_GetTiSpan100MicroSec32bit_TiSpan;
extern VAR(NtcNr1, AUTOMATIC) SysFricLrng_Srv_SetNtcSts_NtcNr;
extern VAR(uint8, AUTOMATIC) SysFricLrng_Srv_SetNtcSts_NtcStInfo;
extern VAR(NtcSts1, AUTOMATIC) SysFricLrng_Srv_SetNtcSts_NtcSts;
extern VAR(uint16, AUTOMATIC) SysFricLrng_Srv_SetNtcSts_DebStep;
extern VAR(float32, AUTOMATIC) SysFricLrng_Cli_GetFricData_FricOffs;
extern VAR(float32, AUTOMATIC) SysFricLrng_Cli_GetFricData_BasLineFric[4];
extern VAR(float32, AUTOMATIC) SysFricLrng_Cli_GetFricData_VehLrndFric[4];
extern VAR(float32, AUTOMATIC) SysFricLrng_Cli_GetFricData_Hys[8][4];
extern VAR(uint16, AUTOMATIC) SysFricLrng_Cli_GetFricData_RngCntr[8][3];
extern VAR(boolean, AUTOMATIC) SysFricLrng_Cli_GetFricLrngData_FricLrngEna;
extern VAR(boolean, AUTOMATIC) SysFricLrng_Cli_GetFricLrngData_FricLrngOffsOutpEna;
extern VAR(SysFricLrngOperMod1, AUTOMATIC) SysFricLrng_Cli_GetFricLrngData_FricLrngOperMod;
extern VAR(float32, AUTOMATIC) SysFricLrng_Cli_GetFricLrngData_EolFric;
extern VAR(boolean, AUTOMATIC) SysFricLrng_Cli_GetFricOffsOutpDi_FricOffsOutpDi;
extern VAR(float32, AUTOMATIC) SysFricLrng_Cli_SetFricData_FricOffs;
extern VAR(float32, AUTOMATIC) SysFricLrng_Cli_SetFricData_BasLineFric[4];
extern VAR(float32, AUTOMATIC) SysFricLrng_Cli_SetFricData_VehLrndFric[4];
extern VAR(float32, AUTOMATIC) SysFricLrng_Cli_SetFricData_Hys[8][4];
extern VAR(uint16, AUTOMATIC) SysFricLrng_Cli_SetFricData_RngCntr[8][3];
extern VAR(boolean, AUTOMATIC) SysFricLrng_Cli_SetFricLrngData_FricLrngEna;
extern VAR(boolean, AUTOMATIC) SysFricLrng_Cli_SetFricLrngData_FricLrngOffsOutpEna;
extern VAR(SysFricLrngOperMod1, AUTOMATIC) SysFricLrng_Cli_SetFricLrngData_FricLrngOperMod;
extern VAR(float32, AUTOMATIC) SysFricLrng_Cli_SetFricLrngData_EolFric;
extern VAR(boolean, AUTOMATIC) SysFricLrng_Cli_SetFricOffsOutpDi_FricOffsOutpDi;


/*** Input Stubs ***/

#ifdef Rte_Read_AssiMechT_Val
# undef Rte_Read_AssiMechT_Val
#else
#error Rte_Read_AssiMechT_Val is missing
#endif
#define Rte_Read_AssiMechT_Val(data) (*(data) = SysFricLrng_Ip_AssiMechT)

#ifdef Rte_Read_FricLrngCustEna_Logl
# undef Rte_Read_FricLrngCustEna_Logl
#else
#error Rte_Read_FricLrngCustEna_Logl is missing
#endif
#define Rte_Read_FricLrngCustEna_Logl(data) (*(data) = SysFricLrng_Ip_FricLrngCustEna)

#ifdef Rte_Read_FricLrngDi_Logl
# undef Rte_Read_FricLrngDi_Logl
#else
#error Rte_Read_FricLrngDi_Logl is missing
#endif
#define Rte_Read_FricLrngDi_Logl(data) (*(data) = SysFricLrng_Ip_FricLrngDi)

#ifdef Rte_Read_HwAg_Val
# undef Rte_Read_HwAg_Val
#else
#error Rte_Read_HwAg_Val is missing
#endif
#define Rte_Read_HwAg_Val(data) (*(data) = SysFricLrng_Ip_HwAg)

#ifdef Rte_Read_HwAgAuthy_Val
# undef Rte_Read_HwAgAuthy_Val
#else
#error Rte_Read_HwAgAuthy_Val is missing
#endif
#define Rte_Read_HwAgAuthy_Val(data) (*(data) = SysFricLrng_Ip_HwAgAuthy)

#ifdef Rte_Read_HwTq_Val
# undef Rte_Read_HwTq_Val
#else
#error Rte_Read_HwTq_Val is missing
#endif
#define Rte_Read_HwTq_Val(data) (*(data) = SysFricLrng_Ip_HwTq)

#ifdef Rte_Read_HwVel_Val
# undef Rte_Read_HwVel_Val
#else
#error Rte_Read_HwVel_Val is missing
#endif
#define Rte_Read_HwVel_Val(data) (*(data) = SysFricLrng_Ip_HwVel)

#ifdef Rte_Read_MotTqCmdCrf_Val
# undef Rte_Read_MotTqCmdCrf_Val
#else
#error Rte_Read_MotTqCmdCrf_Val is missing
#endif
#define Rte_Read_MotTqCmdCrf_Val(data) (*(data) = SysFricLrng_Ip_MotTqCmdCrf)

#ifdef Rte_Read_VehLatA_Val
# undef Rte_Read_VehLatA_Val
#else
#error Rte_Read_VehLatA_Val is missing
#endif
#define Rte_Read_VehLatA_Val(data) (*(data) = SysFricLrng_Ip_VehLatA)

#ifdef Rte_Read_VehSpd_Val
# undef Rte_Read_VehSpd_Val
#else
#error Rte_Read_VehSpd_Val is missing
#endif
#define Rte_Read_VehSpd_Val(data) (*(data) = SysFricLrng_Ip_VehSpd)

#ifdef Rte_Read_VehSpdVld_Logl
# undef Rte_Read_VehSpdVld_Logl
#else
#error Rte_Read_VehSpdVld_Logl is missing
#endif
#define Rte_Read_VehSpdVld_Logl(data) (*(data) = SysFricLrng_Ip_VehSpdVld)


/*** Output Stubs ***/

#ifdef Rte_Write_MaxLrndFric_Val
# undef Rte_Write_MaxLrndFric_Val
#else
#error Rte_Write_MaxLrndFric_Val is missing
#endif
#define Rte_Write_MaxLrndFric_Val(data) (SysFricLrng_Op_MaxLrndFric = (data))

#ifdef Rte_Write_SysFricEstimd_Val
# undef Rte_Write_SysFricEstimd_Val
#else
#error Rte_Write_SysFricEstimd_Val is missing
#endif
#define Rte_Write_SysFricEstimd_Val(data) (SysFricLrng_Op_SysFricEstimd = (data))

#ifdef Rte_Write_SysFricOffs_Val
# undef Rte_Write_SysFricOffs_Val
#else
#error Rte_Write_SysFricOffs_Val is missing
#endif
#define Rte_Write_SysFricOffs_Val(data) (SysFricLrng_Op_SysFricOffs = (data))

#ifdef Rte_Write_SysSatnFricEstimd_Val
# undef Rte_Write_SysSatnFricEstimd_Val
#else
#error Rte_Write_SysSatnFricEstimd_Val is missing
#endif
#define Rte_Write_SysSatnFricEstimd_Val(data) (SysFricLrng_Op_SysSatnFricEstimd = (data))


/*** Calibration Stubs ***/

#ifdef Rte_Prm_SysFricLrngAvrgFricFrq_Val
# undef Rte_Prm_SysFricLrngAvrgFricFrq_Val
#else
#error Rte_Prm_SysFricLrngAvrgFricFrq_Val is missing
#endif
#define Rte_Prm_SysFricLrngAvrgFricFrq_Val() (SysFricLrng_Cal_SysFricLrngAvrgFricFrq)

#ifdef Rte_Prm_SysFricLrngBasLineEolFric_Val
# undef Rte_Prm_SysFricLrngBasLineEolFric_Val
#else
#error Rte_Prm_SysFricLrngBasLineEolFric_Val is missing
#endif
#define Rte_Prm_SysFricLrngBasLineEolFric_Val() (SysFricLrng_Cal_SysFricLrngBasLineEolFric)

#ifdef Rte_Prm_SysFricLrngBasLineFric_Ary1D
# undef Rte_Prm_SysFricLrngBasLineFric_Ary1D
#else
#error Rte_Prm_SysFricLrngBasLineFric_Ary1D is missing
#endif
#define Rte_Prm_SysFricLrngBasLineFric_Ary1D() (&(SysFricLrng_Cal_SysFricLrngBasLineFric[0]))

#ifdef Rte_Prm_SysFricLrngBasLineHys_Ary2D
# undef Rte_Prm_SysFricLrngBasLineHys_Ary2D
#else
#error Rte_Prm_SysFricLrngBasLineHys_Ary2D is missing
#endif
#define Rte_Prm_SysFricLrngBasLineHys_Ary2D() (&(SysFricLrng_Cal_SysFricLrngBasLineHys[0][0]))

#ifdef Rte_Prm_SysFricLrngBasLineRngCntr_Ary2D
# undef Rte_Prm_SysFricLrngBasLineRngCntr_Ary2D
#else
#error Rte_Prm_SysFricLrngBasLineRngCntr_Ary2D is missing
#endif
#define Rte_Prm_SysFricLrngBasLineRngCntr_Ary2D() (&(SysFricLrng_Cal_SysFricLrngBasLineRngCntr[0][0]))

#ifdef Rte_Prm_SysFricLrngDataPrepLpFilFrq_Val
# undef Rte_Prm_SysFricLrngDataPrepLpFilFrq_Val
#else
#error Rte_Prm_SysFricLrngDataPrepLpFilFrq_Val is missing
#endif
#define Rte_Prm_SysFricLrngDataPrepLpFilFrq_Val() (SysFricLrng_Cal_SysFricLrngDataPrepLpFilFrq)

#ifdef Rte_Prm_SysFricLrngDebStep_Val
# undef Rte_Prm_SysFricLrngDebStep_Val
#else
#error Rte_Prm_SysFricLrngDebStep_Val is missing
#endif
#define Rte_Prm_SysFricLrngDebStep_Val() (SysFricLrng_Cal_SysFricLrngDebStep)

#ifdef Rte_Prm_SysFricLrngEolFricDifHiLim_Val
# undef Rte_Prm_SysFricLrngEolFricDifHiLim_Val
#else
#error Rte_Prm_SysFricLrngEolFricDifHiLim_Val is missing
#endif
#define Rte_Prm_SysFricLrngEolFricDifHiLim_Val() (SysFricLrng_Cal_SysFricLrngEolFricDifHiLim)

#ifdef Rte_Prm_SysFricLrngEolFricDifLoLim_Val
# undef Rte_Prm_SysFricLrngEolFricDifLoLim_Val
#else
#error Rte_Prm_SysFricLrngEolFricDifLoLim_Val is missing
#endif
#define Rte_Prm_SysFricLrngEolFricDifLoLim_Val() (SysFricLrng_Cal_SysFricLrngEolFricDifLoLim)

#ifdef Rte_Prm_SysFricLrngEolFricDifScagFac_Val
# undef Rte_Prm_SysFricLrngEolFricDifScagFac_Val
#else
#error Rte_Prm_SysFricLrngEolFricDifScagFac_Val is missing
#endif
#define Rte_Prm_SysFricLrngEolFricDifScagFac_Val() (SysFricLrng_Cal_SysFricLrngEolFricDifScagFac)

#ifdef Rte_Prm_SysFricLrngFricChgWght_Ary1D
# undef Rte_Prm_SysFricLrngFricChgWght_Ary1D
#else
#error Rte_Prm_SysFricLrngFricChgWght_Ary1D is missing
#endif
#define Rte_Prm_SysFricLrngFricChgWght_Ary1D() (&(SysFricLrng_Cal_SysFricLrngFricChgWght[0]))

#ifdef Rte_Prm_SysFricLrngFricDiagcThd_Val
# undef Rte_Prm_SysFricLrngFricDiagcThd_Val
#else
#error Rte_Prm_SysFricLrngFricDiagcThd_Val is missing
#endif
#define Rte_Prm_SysFricLrngFricDiagcThd_Val() (SysFricLrng_Cal_SysFricLrngFricDiagcThd)

#ifdef Rte_Prm_SysFricLrngFricHysHwAgPt_Ary1D
# undef Rte_Prm_SysFricLrngFricHysHwAgPt_Ary1D
#else
#error Rte_Prm_SysFricLrngFricHysHwAgPt_Ary1D is missing
#endif
#define Rte_Prm_SysFricLrngFricHysHwAgPt_Ary1D() (&(SysFricLrng_Cal_SysFricLrngFricHysHwAgPt[0]))

#ifdef Rte_Prm_SysFricLrngFricOffs_Val
# undef Rte_Prm_SysFricLrngFricOffs_Val
#else
#error Rte_Prm_SysFricLrngFricOffs_Val is missing
#endif
#define Rte_Prm_SysFricLrngFricOffs_Val() (SysFricLrng_Cal_SysFricLrngFricOffs)

#ifdef Rte_Prm_SysFricLrngFricOffsHiLim_Val
# undef Rte_Prm_SysFricLrngFricOffsHiLim_Val
#else
#error Rte_Prm_SysFricLrngFricOffsHiLim_Val is missing
#endif
#define Rte_Prm_SysFricLrngFricOffsHiLim_Val() (SysFricLrng_Cal_SysFricLrngFricOffsHiLim)

#ifdef Rte_Prm_SysFricLrngFricOffsLoLim_Val
# undef Rte_Prm_SysFricLrngFricOffsLoLim_Val
#else
#error Rte_Prm_SysFricLrngFricOffsLoLim_Val is missing
#endif
#define Rte_Prm_SysFricLrngFricOffsLoLim_Val() (SysFricLrng_Cal_SysFricLrngFricOffsLoLim)

#ifdef Rte_Prm_SysFricLrngFricOffsLpFilFrq_Val
# undef Rte_Prm_SysFricLrngFricOffsLpFilFrq_Val
#else
#error Rte_Prm_SysFricLrngFricOffsLpFilFrq_Val is missing
#endif
#define Rte_Prm_SysFricLrngFricOffsLpFilFrq_Val() (SysFricLrng_Cal_SysFricLrngFricOffsLpFilFrq)

#ifdef Rte_Prm_SysFricLrngGain_Val
# undef Rte_Prm_SysFricLrngGain_Val
#else
#error Rte_Prm_SysFricLrngGain_Val is missing
#endif
#define Rte_Prm_SysFricLrngGain_Val() (SysFricLrng_Cal_SysFricLrngGain)

#ifdef Rte_Prm_SysFricLrngHiFricDebStep_Val
# undef Rte_Prm_SysFricLrngHiFricDebStep_Val
#else
#error Rte_Prm_SysFricLrngHiFricDebStep_Val is missing
#endif
#define Rte_Prm_SysFricLrngHiFricDebStep_Val() (SysFricLrng_Cal_SysFricLrngHiFricDebStep)

#ifdef Rte_Prm_SysFricLrngHiFricDiagcThd_Val
# undef Rte_Prm_SysFricLrngHiFricDiagcThd_Val
#else
#error Rte_Prm_SysFricLrngHiFricDiagcThd_Val is missing
#endif
#define Rte_Prm_SysFricLrngHiFricDiagcThd_Val() (SysFricLrng_Cal_SysFricLrngHiFricDiagcThd)

#ifdef Rte_Prm_SysFricLrngHwPosnAuthyThd_Val
# undef Rte_Prm_SysFricLrngHwPosnAuthyThd_Val
#else
#error Rte_Prm_SysFricLrngHwPosnAuthyThd_Val is missing
#endif
#define Rte_Prm_SysFricLrngHwPosnAuthyThd_Val() (SysFricLrng_Cal_SysFricLrngHwPosnAuthyThd)

#ifdef Rte_Prm_SysFricLrngHwVelConstrLim_Val
# undef Rte_Prm_SysFricLrngHwVelConstrLim_Val
#else
#error Rte_Prm_SysFricLrngHwVelConstrLim_Val is missing
#endif
#define Rte_Prm_SysFricLrngHwVelConstrLim_Val() (SysFricLrng_Cal_SysFricLrngHwVelConstrLim)

#ifdef Rte_Prm_SysFricLrngHwVelHiLim_Val
# undef Rte_Prm_SysFricLrngHwVelHiLim_Val
#else
#error Rte_Prm_SysFricLrngHwVelHiLim_Val is missing
#endif
#define Rte_Prm_SysFricLrngHwVelHiLim_Val() (SysFricLrng_Cal_SysFricLrngHwVelHiLim)

#ifdef Rte_Prm_SysFricLrngHwVelLoLim_Val
# undef Rte_Prm_SysFricLrngHwVelLoLim_Val
#else
#error Rte_Prm_SysFricLrngHwVelLoLim_Val is missing
#endif
#define Rte_Prm_SysFricLrngHwVelLoLim_Val() (SysFricLrng_Cal_SysFricLrngHwVelLoLim)

#ifdef Rte_Prm_SysFricLrngIgnCycFricChgLim_Val
# undef Rte_Prm_SysFricLrngIgnCycFricChgLim_Val
#else
#error Rte_Prm_SysFricLrngIgnCycFricChgLim_Val is missing
#endif
#define Rte_Prm_SysFricLrngIgnCycFricChgLim_Val() (SysFricLrng_Cal_SysFricLrngIgnCycFricChgLim)

#ifdef Rte_Prm_SysFricLrngIgnCycFricOffs_Val
# undef Rte_Prm_SysFricLrngIgnCycFricOffs_Val
#else
#error Rte_Prm_SysFricLrngIgnCycFricOffs_Val is missing
#endif
#define Rte_Prm_SysFricLrngIgnCycFricOffs_Val() (SysFricLrng_Cal_SysFricLrngIgnCycFricOffs)

#ifdef Rte_Prm_SysFricLrngIvsTrsmRatX_Ary1D
# undef Rte_Prm_SysFricLrngIvsTrsmRatX_Ary1D
#else
#error Rte_Prm_SysFricLrngIvsTrsmRatX_Ary1D is missing
#endif
#define Rte_Prm_SysFricLrngIvsTrsmRatX_Ary1D() (&(SysFricLrng_Cal_SysFricLrngIvsTrsmRatX[0]))

#ifdef Rte_Prm_SysFricLrngIvsTrsmRatY_Ary1D
# undef Rte_Prm_SysFricLrngIvsTrsmRatY_Ary1D
#else
#error Rte_Prm_SysFricLrngIvsTrsmRatY_Ary1D is missing
#endif
#define Rte_Prm_SysFricLrngIvsTrsmRatY_Ary1D() (&(SysFricLrng_Cal_SysFricLrngIvsTrsmRatY[0]))

#ifdef Rte_Prm_SysFricLrngLatAHiLim_Val
# undef Rte_Prm_SysFricLrngLatAHiLim_Val
#else
#error Rte_Prm_SysFricLrngLatAHiLim_Val is missing
#endif
#define Rte_Prm_SysFricLrngLatAHiLim_Val() (SysFricLrng_Cal_SysFricLrngLatAHiLim)

#ifdef Rte_Prm_SysFricLrngLatALoLim_Val
# undef Rte_Prm_SysFricLrngLatALoLim_Val
#else
#error Rte_Prm_SysFricLrngLatALoLim_Val is missing
#endif
#define Rte_Prm_SysFricLrngLatALoLim_Val() (SysFricLrng_Cal_SysFricLrngLatALoLim)

#ifdef Rte_Prm_SysFricLrngMaskVehSpd_Ary1D
# undef Rte_Prm_SysFricLrngMaskVehSpd_Ary1D
#else
#error Rte_Prm_SysFricLrngMaskVehSpd_Ary1D is missing
#endif
#define Rte_Prm_SysFricLrngMaskVehSpd_Ary1D() (&(SysFricLrng_Cal_SysFricLrngMaskVehSpd[0]))

#ifdef Rte_Prm_SysFricLrngRngCntrThd_Val
# undef Rte_Prm_SysFricLrngRngCntrThd_Val
#else
#error Rte_Prm_SysFricLrngRngCntrThd_Val is missing
#endif
#define Rte_Prm_SysFricLrngRngCntrThd_Val() (SysFricLrng_Cal_SysFricLrngRngCntrThd)

#ifdef Rte_Prm_SysFricLrngTHiLim_Val
# undef Rte_Prm_SysFricLrngTHiLim_Val
#else
#error Rte_Prm_SysFricLrngTHiLim_Val is missing
#endif
#define Rte_Prm_SysFricLrngTHiLim_Val() (SysFricLrng_Cal_SysFricLrngTHiLim)

#ifdef Rte_Prm_SysFricLrngTLoLim_Val
# undef Rte_Prm_SysFricLrngTLoLim_Val
#else
#error Rte_Prm_SysFricLrngTLoLim_Val is missing
#endif
#define Rte_Prm_SysFricLrngTLoLim_Val() (SysFricLrng_Cal_SysFricLrngTLoLim)

#ifdef Rte_Prm_SysFricLrngThd_Val
# undef Rte_Prm_SysFricLrngThd_Val
#else
#error Rte_Prm_SysFricLrngThd_Val is missing
#endif
#define Rte_Prm_SysFricLrngThd_Val() (SysFricLrng_Cal_SysFricLrngThd)

#ifdef Rte_Prm_SysFricLrngVehSpd_Ary2D
# undef Rte_Prm_SysFricLrngVehSpd_Ary2D
#else
#error Rte_Prm_SysFricLrngVehSpd_Ary2D is missing
#endif
#define Rte_Prm_SysFricLrngVehSpd_Ary2D() (&(SysFricLrng_Cal_SysFricLrngVehSpd[0][0]))


/*** PIM Stubs ***/

#ifdef Rte_Pim_FricLrngData
# undef Rte_Pim_FricLrngData
#else
#error Rte_Pim_FricLrngData is missing
#endif
#define Rte_Pim_FricLrngData() (&SysFricLrng_Pim_FricLrngData)

#ifdef Rte_Pim_FricNonLrngData
# undef Rte_Pim_FricNonLrngData
#else
#error Rte_Pim_FricNonLrngData is missing
#endif
#define Rte_Pim_FricNonLrngData() (&SysFricLrng_Pim_FricNonLrngData)

#ifdef Rte_Pim_AssiMechTLpFil
# undef Rte_Pim_AssiMechTLpFil
#else
#error Rte_Pim_AssiMechTLpFil is missing
#endif
#define Rte_Pim_AssiMechTLpFil() (&SysFricLrng_Pim_AssiMechTLpFil)

#ifdef Rte_Pim_AvrgFricLpFil1
# undef Rte_Pim_AvrgFricLpFil1
#else
#error Rte_Pim_AvrgFricLpFil1 is missing
#endif
#define Rte_Pim_AvrgFricLpFil1() (&SysFricLrng_Pim_AvrgFricLpFil1)

#ifdef Rte_Pim_AvrgFricLpFil2
# undef Rte_Pim_AvrgFricLpFil2
#else
#error Rte_Pim_AvrgFricLpFil2 is missing
#endif
#define Rte_Pim_AvrgFricLpFil2() (&SysFricLrng_Pim_AvrgFricLpFil2)

#ifdef Rte_Pim_AvrgFricLpFil3
# undef Rte_Pim_AvrgFricLpFil3
#else
#error Rte_Pim_AvrgFricLpFil3 is missing
#endif
#define Rte_Pim_AvrgFricLpFil3() (&SysFricLrng_Pim_AvrgFricLpFil3)

#ifdef Rte_Pim_AvrgFricLpFil4
# undef Rte_Pim_AvrgFricLpFil4
#else
#error Rte_Pim_AvrgFricLpFil4 is missing
#endif
#define Rte_Pim_AvrgFricLpFil4() (&SysFricLrng_Pim_AvrgFricLpFil4)

#ifdef Rte_Pim_ColTqAry
# undef Rte_Pim_ColTqAry
#else
#error Rte_Pim_ColTqAry is missing
#endif
#define Rte_Pim_ColTqAry() (&(SysFricLrng_Pim_ColTqAry[0]))

#ifdef Rte_Pim_ColTqLpFil
# undef Rte_Pim_ColTqLpFil
#else
#error Rte_Pim_ColTqLpFil is missing
#endif
#define Rte_Pim_ColTqLpFil() (&SysFricLrng_Pim_ColTqLpFil)

#ifdef Rte_Pim_EstimdFric
# undef Rte_Pim_EstimdFric
#else
#error Rte_Pim_EstimdFric is missing
#endif
#define Rte_Pim_EstimdFric() (&SysFricLrng_Pim_EstimdFric)

#ifdef Rte_Pim_FilAvrgFric
# undef Rte_Pim_FilAvrgFric
#else
#error Rte_Pim_FilAvrgFric is missing
#endif
#define Rte_Pim_FilAvrgFric() (&(SysFricLrng_Pim_FilAvrgFric[0]))

#ifdef Rte_Pim_FricChgLpFil
# undef Rte_Pim_FricChgLpFil
#else
#error Rte_Pim_FricChgLpFil is missing
#endif
#define Rte_Pim_FricChgLpFil() (&SysFricLrng_Pim_FricChgLpFil)

#ifdef Rte_Pim_FricLrngOperModPrev
# undef Rte_Pim_FricLrngOperModPrev
#else
#error Rte_Pim_FricLrngOperModPrev is missing
#endif
#define Rte_Pim_FricLrngOperModPrev() (&SysFricLrng_Pim_FricLrngOperModPrev)

#ifdef Rte_Pim_FricLrngRunOneTi
# undef Rte_Pim_FricLrngRunOneTi
#else
#error Rte_Pim_FricLrngRunOneTi is missing
#endif
#define Rte_Pim_FricLrngRunOneTi() (&SysFricLrng_Pim_FricLrngRunOneTi)

#ifdef Rte_Pim_FricOffs
# undef Rte_Pim_FricOffs
#else
#error Rte_Pim_FricOffs is missing
#endif
#define Rte_Pim_FricOffs() (&SysFricLrng_Pim_FricOffs)

#ifdef Rte_Pim_FricOffsOutpDi
# undef Rte_Pim_FricOffsOutpDi
#else
#error Rte_Pim_FricOffsOutpDi is missing
#endif
#define Rte_Pim_FricOffsOutpDi() (&SysFricLrng_Pim_FricOffsOutpDi)

#ifdef Rte_Pim_HwAgAuthyLpFil
# undef Rte_Pim_HwAgAuthyLpFil
#else
#error Rte_Pim_HwAgAuthyLpFil is missing
#endif
#define Rte_Pim_HwAgAuthyLpFil() (&SysFricLrng_Pim_HwAgAuthyLpFil)

#ifdef Rte_Pim_HwAgBuf
# undef Rte_Pim_HwAgBuf
#else
#error Rte_Pim_HwAgBuf is missing
#endif
#define Rte_Pim_HwAgBuf() (&(SysFricLrng_Pim_HwAgBuf[0]))

#ifdef Rte_Pim_HwAgLpFil
# undef Rte_Pim_HwAgLpFil
#else
#error Rte_Pim_HwAgLpFil is missing
#endif
#define Rte_Pim_HwAgLpFil() (&SysFricLrng_Pim_HwAgLpFil)

#ifdef Rte_Pim_HwVelBuf
# undef Rte_Pim_HwVelBuf
#else
#error Rte_Pim_HwVelBuf is missing
#endif
#define Rte_Pim_HwVelBuf() (&(SysFricLrng_Pim_HwVelBuf[0]))

#ifdef Rte_Pim_HwVelLpFil
# undef Rte_Pim_HwVelLpFil
#else
#error Rte_Pim_HwVelLpFil is missing
#endif
#define Rte_Pim_HwVelLpFil() (&SysFricLrng_Pim_HwVelLpFil)

#ifdef Rte_Pim_LatALpFil
# undef Rte_Pim_LatALpFil
#else
#error Rte_Pim_LatALpFil is missing
#endif
#define Rte_Pim_LatALpFil() (&SysFricLrng_Pim_LatALpFil)

#ifdef Rte_Pim_PrevMaxRawAvrgFric
# undef Rte_Pim_PrevMaxRawAvrgFric
#else
#error Rte_Pim_PrevMaxRawAvrgFric is missing
#endif
#define Rte_Pim_PrevMaxRawAvrgFric() (&SysFricLrng_Pim_PrevMaxRawAvrgFric)

#ifdef Rte_Pim_RawAvrgFric
# undef Rte_Pim_RawAvrgFric
#else
#error Rte_Pim_RawAvrgFric is missing
#endif
#define Rte_Pim_RawAvrgFric() (&(SysFricLrng_Pim_RawAvrgFric[0]))

#ifdef Rte_Pim_RefTmrLrngConstr
# undef Rte_Pim_RefTmrLrngConstr
#else
#error Rte_Pim_RefTmrLrngConstr is missing
#endif
#define Rte_Pim_RefTmrLrngConstr() (&SysFricLrng_Pim_RefTmrLrngConstr)

#ifdef Rte_Pim_SatnAvrgFric
# undef Rte_Pim_SatnAvrgFric
#else
#error Rte_Pim_SatnAvrgFric is missing
#endif
#define Rte_Pim_SatnAvrgFric() (&(SysFricLrng_Pim_SatnAvrgFric[0]))

#ifdef Rte_Pim_SatnEstimdFric
# undef Rte_Pim_SatnEstimdFric
#else
#error Rte_Pim_SatnEstimdFric is missing
#endif
#define Rte_Pim_SatnEstimdFric() (&SysFricLrng_Pim_SatnEstimdFric)

#ifdef Rte_Pim_VehBasLineFric
# undef Rte_Pim_VehBasLineFric
#else
#error Rte_Pim_VehBasLineFric is missing
#endif
#define Rte_Pim_VehBasLineFric() (&(SysFricLrng_Pim_VehBasLineFric[0]))

#ifdef Rte_Pim_VehSpdLpFil
# undef Rte_Pim_VehSpdLpFil
#else
#error Rte_Pim_VehSpdLpFil is missing
#endif
#define Rte_Pim_VehSpdLpFil() (&SysFricLrng_Pim_VehSpdLpFil)


/*** Client Stub ***/

extern FUNC(void, AUTOMATIC) Rte_Stub(void);


#endif
