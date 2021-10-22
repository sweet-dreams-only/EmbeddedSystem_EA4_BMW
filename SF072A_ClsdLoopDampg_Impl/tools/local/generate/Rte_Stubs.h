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
extern VAR(float32, AUTOMATIC) ClsdLoopDampg_Ip_DampgCmdSca;
extern VAR(float32, AUTOMATIC) ClsdLoopDampg_Ip_EotCtrlSca;
extern VAR(float32, AUTOMATIC) ClsdLoopDampg_Ip_EotDeltaAg;
extern VAR(EotSt1, AUTOMATIC) ClsdLoopDampg_Ip_EotSt;
extern VAR(float32, AUTOMATIC) ClsdLoopDampg_Ip_PinionVel;
extern VAR(float32, AUTOMATIC) ClsdLoopDampg_Ip_RackFEstimd;
extern VAR(float32, AUTOMATIC) ClsdLoopDampg_Ip_VehSpd;

/* Outputs */
extern VAR(float32, AUTOMATIC) ClsdLoopDampg_Op_HwTqCmdDampg;

/* Calibrations */
extern CONST(u10p6, AUTOMATIC) ClsdLoopDampg_Cal_ClsdLoopDampgEotEntrX[4];
extern CONST(u1p15, AUTOMATIC) ClsdLoopDampg_Cal_ClsdLoopDampgEotEntrY[4];
extern CONST(u10p6, AUTOMATIC) ClsdLoopDampg_Cal_ClsdLoopDampgEotExitX[4];
extern CONST(u1p15, AUTOMATIC) ClsdLoopDampg_Cal_ClsdLoopDampgEotExitY[4];
extern CONST(u6p10, AUTOMATIC) ClsdLoopDampg_Cal_ClsdLoopDampgPinionVelX[9][12];
extern CONST(u4p12, AUTOMATIC) ClsdLoopDampg_Cal_ClsdLoopDampgPinionVelY[9][12];
extern CONST(u15p1, AUTOMATIC) ClsdLoopDampg_Cal_ClsdLoopDampgRackFX[9][12];
extern CONST(u1p15, AUTOMATIC) ClsdLoopDampg_Cal_ClsdLoopDampgRackFY[9][12];
extern CONST(u9p7, AUTOMATIC) ClsdLoopDampg_Cal_SysGlbPrmVehSpdBilnrSeln[12];

/* Arguments and Returns */


/*** Input Stubs ***/

#ifdef Rte_Read_DampgCmdSca_Val
# undef Rte_Read_DampgCmdSca_Val
#else
#error Rte_Read_DampgCmdSca_Val is missing
#endif
#define Rte_Read_DampgCmdSca_Val(data) (*(data) = ClsdLoopDampg_Ip_DampgCmdSca)

#ifdef Rte_Read_EotCtrlSca_Val
# undef Rte_Read_EotCtrlSca_Val
#else
#error Rte_Read_EotCtrlSca_Val is missing
#endif
#define Rte_Read_EotCtrlSca_Val(data) (*(data) = ClsdLoopDampg_Ip_EotCtrlSca)

#ifdef Rte_Read_EotDeltaAg_Val
# undef Rte_Read_EotDeltaAg_Val
#else
#error Rte_Read_EotDeltaAg_Val is missing
#endif
#define Rte_Read_EotDeltaAg_Val(data) (*(data) = ClsdLoopDampg_Ip_EotDeltaAg)

#ifdef Rte_Read_EotSt_Val
# undef Rte_Read_EotSt_Val
#else
#error Rte_Read_EotSt_Val is missing
#endif
#define Rte_Read_EotSt_Val(data) (*(data) = ClsdLoopDampg_Ip_EotSt)

#ifdef Rte_Read_PinionVel_Val
# undef Rte_Read_PinionVel_Val
#else
#error Rte_Read_PinionVel_Val is missing
#endif
#define Rte_Read_PinionVel_Val(data) (*(data) = ClsdLoopDampg_Ip_PinionVel)

#ifdef Rte_Read_RackFEstimd_Val
# undef Rte_Read_RackFEstimd_Val
#else
#error Rte_Read_RackFEstimd_Val is missing
#endif
#define Rte_Read_RackFEstimd_Val(data) (*(data) = ClsdLoopDampg_Ip_RackFEstimd)

#ifdef Rte_Read_VehSpd_Val
# undef Rte_Read_VehSpd_Val
#else
#error Rte_Read_VehSpd_Val is missing
#endif
#define Rte_Read_VehSpd_Val(data) (*(data) = ClsdLoopDampg_Ip_VehSpd)


/*** Output Stubs ***/

#ifdef Rte_Write_HwTqCmdDampg_Val
# undef Rte_Write_HwTqCmdDampg_Val
#else
#error Rte_Write_HwTqCmdDampg_Val is missing
#endif
#define Rte_Write_HwTqCmdDampg_Val(data) (ClsdLoopDampg_Op_HwTqCmdDampg = (data))


/*** Calibration Stubs ***/

#ifdef Rte_Prm_ClsdLoopDampgEotEntrX_Ary1D
# undef Rte_Prm_ClsdLoopDampgEotEntrX_Ary1D
#else
#error Rte_Prm_ClsdLoopDampgEotEntrX_Ary1D is missing
#endif
#define Rte_Prm_ClsdLoopDampgEotEntrX_Ary1D() (&(ClsdLoopDampg_Cal_ClsdLoopDampgEotEntrX[0]))

#ifdef Rte_Prm_ClsdLoopDampgEotEntrY_Ary1D
# undef Rte_Prm_ClsdLoopDampgEotEntrY_Ary1D
#else
#error Rte_Prm_ClsdLoopDampgEotEntrY_Ary1D is missing
#endif
#define Rte_Prm_ClsdLoopDampgEotEntrY_Ary1D() (&(ClsdLoopDampg_Cal_ClsdLoopDampgEotEntrY[0]))

#ifdef Rte_Prm_ClsdLoopDampgEotExitX_Ary1D
# undef Rte_Prm_ClsdLoopDampgEotExitX_Ary1D
#else
#error Rte_Prm_ClsdLoopDampgEotExitX_Ary1D is missing
#endif
#define Rte_Prm_ClsdLoopDampgEotExitX_Ary1D() (&(ClsdLoopDampg_Cal_ClsdLoopDampgEotExitX[0]))

#ifdef Rte_Prm_ClsdLoopDampgEotExitY_Ary1D
# undef Rte_Prm_ClsdLoopDampgEotExitY_Ary1D
#else
#error Rte_Prm_ClsdLoopDampgEotExitY_Ary1D is missing
#endif
#define Rte_Prm_ClsdLoopDampgEotExitY_Ary1D() (&(ClsdLoopDampg_Cal_ClsdLoopDampgEotExitY[0]))

#ifdef Rte_Prm_ClsdLoopDampgPinionVelX_Ary2D
# undef Rte_Prm_ClsdLoopDampgPinionVelX_Ary2D
#else
#error Rte_Prm_ClsdLoopDampgPinionVelX_Ary2D is missing
#endif
#define Rte_Prm_ClsdLoopDampgPinionVelX_Ary2D() (&(ClsdLoopDampg_Cal_ClsdLoopDampgPinionVelX[0][0]))

#ifdef Rte_Prm_ClsdLoopDampgPinionVelY_Ary2D
# undef Rte_Prm_ClsdLoopDampgPinionVelY_Ary2D
#else
#error Rte_Prm_ClsdLoopDampgPinionVelY_Ary2D is missing
#endif
#define Rte_Prm_ClsdLoopDampgPinionVelY_Ary2D() (&(ClsdLoopDampg_Cal_ClsdLoopDampgPinionVelY[0][0]))

#ifdef Rte_Prm_ClsdLoopDampgRackFX_Ary2D
# undef Rte_Prm_ClsdLoopDampgRackFX_Ary2D
#else
#error Rte_Prm_ClsdLoopDampgRackFX_Ary2D is missing
#endif
#define Rte_Prm_ClsdLoopDampgRackFX_Ary2D() (&(ClsdLoopDampg_Cal_ClsdLoopDampgRackFX[0][0]))

#ifdef Rte_Prm_ClsdLoopDampgRackFY_Ary2D
# undef Rte_Prm_ClsdLoopDampgRackFY_Ary2D
#else
#error Rte_Prm_ClsdLoopDampgRackFY_Ary2D is missing
#endif
#define Rte_Prm_ClsdLoopDampgRackFY_Ary2D() (&(ClsdLoopDampg_Cal_ClsdLoopDampgRackFY[0][0]))

#ifdef Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D
# undef Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D
#else
#error Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D is missing
#endif
#define Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D() (&(ClsdLoopDampg_Cal_SysGlbPrmVehSpdBilnrSeln[0]))


/*** Client Stub ***/

extern FUNC(void, AUTOMATIC) Rte_Stub(void);


#endif
