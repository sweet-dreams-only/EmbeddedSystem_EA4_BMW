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
extern VAR(float32, AUTOMATIC) ClsdLoopHys_Ip_HwAg;
extern VAR(float32, AUTOMATIC) ClsdLoopHys_Ip_HwTq;
extern VAR(float32, AUTOMATIC) ClsdLoopHys_Ip_HwTqCmdEffort;
extern VAR(float32, AUTOMATIC) ClsdLoopHys_Ip_HwVel;
extern VAR(float32, AUTOMATIC) ClsdLoopHys_Ip_RackFEstimd;
extern VAR(float32, AUTOMATIC) ClsdLoopHys_Ip_SysFricOffs;
extern VAR(float32, AUTOMATIC) ClsdLoopHys_Ip_VehSpd;

/* Outputs */
extern VAR(float32, AUTOMATIC) ClsdLoopHys_Op_HwTqCmdHys;

/* Calibrations */
extern CONST(u6p10, AUTOMATIC) ClsdLoopHys_Cal_ClsdLoopHysDeltaY[12];
extern CONST(u6p10, AUTOMATIC) ClsdLoopHys_Cal_ClsdLoopHysGainY[12];
extern CONST(float32, AUTOMATIC) ClsdLoopHys_Cal_ClsdLoopHysHwAgBlndFac;
extern CONST(u6p10, AUTOMATIC) ClsdLoopHys_Cal_ClsdLoopHysHwAgQuadBlndX[2];
extern CONST(u2p14, AUTOMATIC) ClsdLoopHys_Cal_ClsdLoopHysHwAgQuadBlndY[2];
extern CONST(u2p14, AUTOMATIC) ClsdLoopHys_Cal_ClsdLoopHysHwAgQuadQlfrX[2];
extern CONST(u2p14, AUTOMATIC) ClsdLoopHys_Cal_ClsdLoopHysHwAgQuadQlfrY[2];
extern CONST(u6p10, AUTOMATIC) ClsdLoopHys_Cal_ClsdLoopHysHwVelQuadBlndX[2];
extern CONST(u2p14, AUTOMATIC) ClsdLoopHys_Cal_ClsdLoopHysHwVelQuadBlndY[2];
extern CONST(float32, AUTOMATIC) ClsdLoopHys_Cal_ClsdLoopHysPolarity;
extern CONST(u15p1, AUTOMATIC) ClsdLoopHys_Cal_ClsdLoopHysRackFFacX[4];
extern CONST(u2p14, AUTOMATIC) ClsdLoopHys_Cal_ClsdLoopHysRackFFacY[12][4];
extern CONST(u6p10, AUTOMATIC) ClsdLoopHys_Cal_ClsdLoopHysRhoY[12];
extern CONST(float32, AUTOMATIC) ClsdLoopHys_Cal_ClsdLoopHysSteerInHwAgNegLowrLim;
extern CONST(float32, AUTOMATIC) ClsdLoopHys_Cal_ClsdLoopHysSteerInHwAgNegUpprLim;
extern CONST(float32, AUTOMATIC) ClsdLoopHys_Cal_ClsdLoopHysSteerInHwAgPosLowrLim;
extern CONST(float32, AUTOMATIC) ClsdLoopHys_Cal_ClsdLoopHysSteerInHwAgPosUpprLim;
extern CONST(float32, AUTOMATIC) ClsdLoopHys_Cal_ClsdLoopHysSteerOutHwAgNegLowrLim;
extern CONST(float32, AUTOMATIC) ClsdLoopHys_Cal_ClsdLoopHysSteerOutHwAgNegUpprLim;
extern CONST(float32, AUTOMATIC) ClsdLoopHys_Cal_ClsdLoopHysSteerOutHwAgPosLowrLim;
extern CONST(float32, AUTOMATIC) ClsdLoopHys_Cal_ClsdLoopHysSteerOutHwAgPosUpprLim;
extern CONST(u9p7, AUTOMATIC) ClsdLoopHys_Cal_ClsdLoopHysSysFricOffsLimX[5];
extern CONST(u4p12, AUTOMATIC) ClsdLoopHys_Cal_ClsdLoopHysSysFricOffsLimY[5];
extern CONST(s4p11, AUTOMATIC) ClsdLoopHys_Cal_ClsdLoopHysSysFricScaX[7];
extern CONST(u2p14, AUTOMATIC) ClsdLoopHys_Cal_ClsdLoopHysSysFricScaY[7];
extern CONST(u9p7, AUTOMATIC) ClsdLoopHys_Cal_SysGlbPrmVehSpdBilnrSeln[12];

/* PIMs */
extern VAR(float32, AUTOMATIC) ClsdLoopHys_Pim_IntgtrSt;

/* Arguments and Returns */


/*** Input Stubs ***/

#ifdef Rte_Read_HwAg_Val
# undef Rte_Read_HwAg_Val
#else
#error Rte_Read_HwAg_Val is missing
#endif
#define Rte_Read_HwAg_Val(data) (*(data) = ClsdLoopHys_Ip_HwAg)

#ifdef Rte_Read_HwTq_Val
# undef Rte_Read_HwTq_Val
#else
#error Rte_Read_HwTq_Val is missing
#endif
#define Rte_Read_HwTq_Val(data) (*(data) = ClsdLoopHys_Ip_HwTq)

#ifdef Rte_Read_HwTqCmdEffort_Val
# undef Rte_Read_HwTqCmdEffort_Val
#else
#error Rte_Read_HwTqCmdEffort_Val is missing
#endif
#define Rte_Read_HwTqCmdEffort_Val(data) (*(data) = ClsdLoopHys_Ip_HwTqCmdEffort)

#ifdef Rte_Read_HwVel_Val
# undef Rte_Read_HwVel_Val
#else
#error Rte_Read_HwVel_Val is missing
#endif
#define Rte_Read_HwVel_Val(data) (*(data) = ClsdLoopHys_Ip_HwVel)

#ifdef Rte_Read_RackFEstimd_Val
# undef Rte_Read_RackFEstimd_Val
#else
#error Rte_Read_RackFEstimd_Val is missing
#endif
#define Rte_Read_RackFEstimd_Val(data) (*(data) = ClsdLoopHys_Ip_RackFEstimd)

#ifdef Rte_Read_SysFricOffs_Val
# undef Rte_Read_SysFricOffs_Val
#else
#error Rte_Read_SysFricOffs_Val is missing
#endif
#define Rte_Read_SysFricOffs_Val(data) (*(data) = ClsdLoopHys_Ip_SysFricOffs)

#ifdef Rte_Read_VehSpd_Val
# undef Rte_Read_VehSpd_Val
#else
#error Rte_Read_VehSpd_Val is missing
#endif
#define Rte_Read_VehSpd_Val(data) (*(data) = ClsdLoopHys_Ip_VehSpd)


/*** Output Stubs ***/

#ifdef Rte_Write_HwTqCmdHys_Val
# undef Rte_Write_HwTqCmdHys_Val
#else
#error Rte_Write_HwTqCmdHys_Val is missing
#endif
#define Rte_Write_HwTqCmdHys_Val(data) (ClsdLoopHys_Op_HwTqCmdHys = (data))


/*** Calibration Stubs ***/

#ifdef Rte_Prm_ClsdLoopHysDeltaY_Ary1D
# undef Rte_Prm_ClsdLoopHysDeltaY_Ary1D
#else
#error Rte_Prm_ClsdLoopHysDeltaY_Ary1D is missing
#endif
#define Rte_Prm_ClsdLoopHysDeltaY_Ary1D() (&(ClsdLoopHys_Cal_ClsdLoopHysDeltaY[0]))

#ifdef Rte_Prm_ClsdLoopHysGainY_Ary1D
# undef Rte_Prm_ClsdLoopHysGainY_Ary1D
#else
#error Rte_Prm_ClsdLoopHysGainY_Ary1D is missing
#endif
#define Rte_Prm_ClsdLoopHysGainY_Ary1D() (&(ClsdLoopHys_Cal_ClsdLoopHysGainY[0]))

#ifdef Rte_Prm_ClsdLoopHysHwAgBlndFac_Val
# undef Rte_Prm_ClsdLoopHysHwAgBlndFac_Val
#else
#error Rte_Prm_ClsdLoopHysHwAgBlndFac_Val is missing
#endif
#define Rte_Prm_ClsdLoopHysHwAgBlndFac_Val() (ClsdLoopHys_Cal_ClsdLoopHysHwAgBlndFac)

#ifdef Rte_Prm_ClsdLoopHysHwAgQuadBlndX_Ary1D
# undef Rte_Prm_ClsdLoopHysHwAgQuadBlndX_Ary1D
#else
#error Rte_Prm_ClsdLoopHysHwAgQuadBlndX_Ary1D is missing
#endif
#define Rte_Prm_ClsdLoopHysHwAgQuadBlndX_Ary1D() (&(ClsdLoopHys_Cal_ClsdLoopHysHwAgQuadBlndX[0]))

#ifdef Rte_Prm_ClsdLoopHysHwAgQuadBlndY_Ary1D
# undef Rte_Prm_ClsdLoopHysHwAgQuadBlndY_Ary1D
#else
#error Rte_Prm_ClsdLoopHysHwAgQuadBlndY_Ary1D is missing
#endif
#define Rte_Prm_ClsdLoopHysHwAgQuadBlndY_Ary1D() (&(ClsdLoopHys_Cal_ClsdLoopHysHwAgQuadBlndY[0]))

#ifdef Rte_Prm_ClsdLoopHysHwAgQuadQlfrX_Ary1D
# undef Rte_Prm_ClsdLoopHysHwAgQuadQlfrX_Ary1D
#else
#error Rte_Prm_ClsdLoopHysHwAgQuadQlfrX_Ary1D is missing
#endif
#define Rte_Prm_ClsdLoopHysHwAgQuadQlfrX_Ary1D() (&(ClsdLoopHys_Cal_ClsdLoopHysHwAgQuadQlfrX[0]))

#ifdef Rte_Prm_ClsdLoopHysHwAgQuadQlfrY_Ary1D
# undef Rte_Prm_ClsdLoopHysHwAgQuadQlfrY_Ary1D
#else
#error Rte_Prm_ClsdLoopHysHwAgQuadQlfrY_Ary1D is missing
#endif
#define Rte_Prm_ClsdLoopHysHwAgQuadQlfrY_Ary1D() (&(ClsdLoopHys_Cal_ClsdLoopHysHwAgQuadQlfrY[0]))

#ifdef Rte_Prm_ClsdLoopHysHwVelQuadBlndX_Ary1D
# undef Rte_Prm_ClsdLoopHysHwVelQuadBlndX_Ary1D
#else
#error Rte_Prm_ClsdLoopHysHwVelQuadBlndX_Ary1D is missing
#endif
#define Rte_Prm_ClsdLoopHysHwVelQuadBlndX_Ary1D() (&(ClsdLoopHys_Cal_ClsdLoopHysHwVelQuadBlndX[0]))

#ifdef Rte_Prm_ClsdLoopHysHwVelQuadBlndY_Ary1D
# undef Rte_Prm_ClsdLoopHysHwVelQuadBlndY_Ary1D
#else
#error Rte_Prm_ClsdLoopHysHwVelQuadBlndY_Ary1D is missing
#endif
#define Rte_Prm_ClsdLoopHysHwVelQuadBlndY_Ary1D() (&(ClsdLoopHys_Cal_ClsdLoopHysHwVelQuadBlndY[0]))

#ifdef Rte_Prm_ClsdLoopHysPolarity_Val
# undef Rte_Prm_ClsdLoopHysPolarity_Val
#else
#error Rte_Prm_ClsdLoopHysPolarity_Val is missing
#endif
#define Rte_Prm_ClsdLoopHysPolarity_Val() (ClsdLoopHys_Cal_ClsdLoopHysPolarity)

#ifdef Rte_Prm_ClsdLoopHysRackFFacX_Ary1D
# undef Rte_Prm_ClsdLoopHysRackFFacX_Ary1D
#else
#error Rte_Prm_ClsdLoopHysRackFFacX_Ary1D is missing
#endif
#define Rte_Prm_ClsdLoopHysRackFFacX_Ary1D() (&(ClsdLoopHys_Cal_ClsdLoopHysRackFFacX[0]))

#ifdef Rte_Prm_ClsdLoopHysRackFFacY_Ary2D
# undef Rte_Prm_ClsdLoopHysRackFFacY_Ary2D
#else
#error Rte_Prm_ClsdLoopHysRackFFacY_Ary2D is missing
#endif
#define Rte_Prm_ClsdLoopHysRackFFacY_Ary2D() (&(ClsdLoopHys_Cal_ClsdLoopHysRackFFacY[0][0]))

#ifdef Rte_Prm_ClsdLoopHysRhoY_Ary1D
# undef Rte_Prm_ClsdLoopHysRhoY_Ary1D
#else
#error Rte_Prm_ClsdLoopHysRhoY_Ary1D is missing
#endif
#define Rte_Prm_ClsdLoopHysRhoY_Ary1D() (&(ClsdLoopHys_Cal_ClsdLoopHysRhoY[0]))

#ifdef Rte_Prm_ClsdLoopHysSteerInHwAgNegLowrLim_Val
# undef Rte_Prm_ClsdLoopHysSteerInHwAgNegLowrLim_Val
#else
#error Rte_Prm_ClsdLoopHysSteerInHwAgNegLowrLim_Val is missing
#endif
#define Rte_Prm_ClsdLoopHysSteerInHwAgNegLowrLim_Val() (ClsdLoopHys_Cal_ClsdLoopHysSteerInHwAgNegLowrLim)

#ifdef Rte_Prm_ClsdLoopHysSteerInHwAgNegUpprLim_Val
# undef Rte_Prm_ClsdLoopHysSteerInHwAgNegUpprLim_Val
#else
#error Rte_Prm_ClsdLoopHysSteerInHwAgNegUpprLim_Val is missing
#endif
#define Rte_Prm_ClsdLoopHysSteerInHwAgNegUpprLim_Val() (ClsdLoopHys_Cal_ClsdLoopHysSteerInHwAgNegUpprLim)

#ifdef Rte_Prm_ClsdLoopHysSteerInHwAgPosLowrLim_Val
# undef Rte_Prm_ClsdLoopHysSteerInHwAgPosLowrLim_Val
#else
#error Rte_Prm_ClsdLoopHysSteerInHwAgPosLowrLim_Val is missing
#endif
#define Rte_Prm_ClsdLoopHysSteerInHwAgPosLowrLim_Val() (ClsdLoopHys_Cal_ClsdLoopHysSteerInHwAgPosLowrLim)

#ifdef Rte_Prm_ClsdLoopHysSteerInHwAgPosUpprLim_Val
# undef Rte_Prm_ClsdLoopHysSteerInHwAgPosUpprLim_Val
#else
#error Rte_Prm_ClsdLoopHysSteerInHwAgPosUpprLim_Val is missing
#endif
#define Rte_Prm_ClsdLoopHysSteerInHwAgPosUpprLim_Val() (ClsdLoopHys_Cal_ClsdLoopHysSteerInHwAgPosUpprLim)

#ifdef Rte_Prm_ClsdLoopHysSteerOutHwAgNegLowrLim_Val
# undef Rte_Prm_ClsdLoopHysSteerOutHwAgNegLowrLim_Val
#else
#error Rte_Prm_ClsdLoopHysSteerOutHwAgNegLowrLim_Val is missing
#endif
#define Rte_Prm_ClsdLoopHysSteerOutHwAgNegLowrLim_Val() (ClsdLoopHys_Cal_ClsdLoopHysSteerOutHwAgNegLowrLim)

#ifdef Rte_Prm_ClsdLoopHysSteerOutHwAgNegUpprLim_Val
# undef Rte_Prm_ClsdLoopHysSteerOutHwAgNegUpprLim_Val
#else
#error Rte_Prm_ClsdLoopHysSteerOutHwAgNegUpprLim_Val is missing
#endif
#define Rte_Prm_ClsdLoopHysSteerOutHwAgNegUpprLim_Val() (ClsdLoopHys_Cal_ClsdLoopHysSteerOutHwAgNegUpprLim)

#ifdef Rte_Prm_ClsdLoopHysSteerOutHwAgPosLowrLim_Val
# undef Rte_Prm_ClsdLoopHysSteerOutHwAgPosLowrLim_Val
#else
#error Rte_Prm_ClsdLoopHysSteerOutHwAgPosLowrLim_Val is missing
#endif
#define Rte_Prm_ClsdLoopHysSteerOutHwAgPosLowrLim_Val() (ClsdLoopHys_Cal_ClsdLoopHysSteerOutHwAgPosLowrLim)

#ifdef Rte_Prm_ClsdLoopHysSteerOutHwAgPosUpprLim_Val
# undef Rte_Prm_ClsdLoopHysSteerOutHwAgPosUpprLim_Val
#else
#error Rte_Prm_ClsdLoopHysSteerOutHwAgPosUpprLim_Val is missing
#endif
#define Rte_Prm_ClsdLoopHysSteerOutHwAgPosUpprLim_Val() (ClsdLoopHys_Cal_ClsdLoopHysSteerOutHwAgPosUpprLim)

#ifdef Rte_Prm_ClsdLoopHysSysFricOffsLimX_Ary1D
# undef Rte_Prm_ClsdLoopHysSysFricOffsLimX_Ary1D
#else
#error Rte_Prm_ClsdLoopHysSysFricOffsLimX_Ary1D is missing
#endif
#define Rte_Prm_ClsdLoopHysSysFricOffsLimX_Ary1D() (&(ClsdLoopHys_Cal_ClsdLoopHysSysFricOffsLimX[0]))

#ifdef Rte_Prm_ClsdLoopHysSysFricOffsLimY_Ary1D
# undef Rte_Prm_ClsdLoopHysSysFricOffsLimY_Ary1D
#else
#error Rte_Prm_ClsdLoopHysSysFricOffsLimY_Ary1D is missing
#endif
#define Rte_Prm_ClsdLoopHysSysFricOffsLimY_Ary1D() (&(ClsdLoopHys_Cal_ClsdLoopHysSysFricOffsLimY[0]))

#ifdef Rte_Prm_ClsdLoopHysSysFricScaX_Ary1D
# undef Rte_Prm_ClsdLoopHysSysFricScaX_Ary1D
#else
#error Rte_Prm_ClsdLoopHysSysFricScaX_Ary1D is missing
#endif
#define Rte_Prm_ClsdLoopHysSysFricScaX_Ary1D() (&(ClsdLoopHys_Cal_ClsdLoopHysSysFricScaX[0]))

#ifdef Rte_Prm_ClsdLoopHysSysFricScaY_Ary1D
# undef Rte_Prm_ClsdLoopHysSysFricScaY_Ary1D
#else
#error Rte_Prm_ClsdLoopHysSysFricScaY_Ary1D is missing
#endif
#define Rte_Prm_ClsdLoopHysSysFricScaY_Ary1D() (&(ClsdLoopHys_Cal_ClsdLoopHysSysFricScaY[0]))

#ifdef Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D
# undef Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D
#else
#error Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D is missing
#endif
#define Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D() (&(ClsdLoopHys_Cal_SysGlbPrmVehSpdBilnrSeln[0]))


/*** PIM Stubs ***/

#ifdef Rte_Pim_IntgtrSt
# undef Rte_Pim_IntgtrSt
#else
#error Rte_Pim_IntgtrSt is missing
#endif
#define Rte_Pim_IntgtrSt() (&ClsdLoopHys_Pim_IntgtrSt)


/*** Client Stub ***/

extern FUNC(void, AUTOMATIC) Rte_Stub(void);


#endif
