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
extern VAR(float32, AUTOMATIC) Effort_Ip_EffortCmdSca;
extern VAR(float32, AUTOMATIC) Effort_Ip_RackFEstimd;
extern VAR(float32, AUTOMATIC) Effort_Ip_VehSpd;

/* Outputs */
extern VAR(float32, AUTOMATIC) Effort_Op_HwTqCmdEffort;

/* Calibrations */
extern CONST(u15p1, AUTOMATIC) Effort_Cal_EffortRackFX[24][10];
extern CONST(u4p12, AUTOMATIC) Effort_Cal_EffortRackFY[24][10];
extern CONST(s15p0, AUTOMATIC) Effort_Cal_EffortScaBlndX[10];
extern CONST(u1p15, AUTOMATIC) Effort_Cal_EffortScaBlndY[10];
extern CONST(float32, AUTOMATIC) Effort_Cal_EffortScaRackFThd;
extern CONST(u9p7, AUTOMATIC) Effort_Cal_EffortVehSpdBilnrSeln[10];

/* Arguments and Returns */


/*** Input Stubs ***/

#ifdef Rte_Read_EffortCmdSca_Val
# undef Rte_Read_EffortCmdSca_Val
#else
#error Rte_Read_EffortCmdSca_Val is missing
#endif
#define Rte_Read_EffortCmdSca_Val(data) (*(data) = Effort_Ip_EffortCmdSca)

#ifdef Rte_Read_RackFEstimd_Val
# undef Rte_Read_RackFEstimd_Val
#else
#error Rte_Read_RackFEstimd_Val is missing
#endif
#define Rte_Read_RackFEstimd_Val(data) (*(data) = Effort_Ip_RackFEstimd)

#ifdef Rte_Read_VehSpd_Val
# undef Rte_Read_VehSpd_Val
#else
#error Rte_Read_VehSpd_Val is missing
#endif
#define Rte_Read_VehSpd_Val(data) (*(data) = Effort_Ip_VehSpd)


/*** Output Stubs ***/

#ifdef Rte_Write_HwTqCmdEffort_Val
# undef Rte_Write_HwTqCmdEffort_Val
#else
#error Rte_Write_HwTqCmdEffort_Val is missing
#endif
#define Rte_Write_HwTqCmdEffort_Val(data) (Effort_Op_HwTqCmdEffort = (data))


/*** Calibration Stubs ***/

#ifdef Rte_Prm_EffortRackFX_Ary2D
# undef Rte_Prm_EffortRackFX_Ary2D
#else
#error Rte_Prm_EffortRackFX_Ary2D is missing
#endif
#define Rte_Prm_EffortRackFX_Ary2D() (&(Effort_Cal_EffortRackFX[0][0]))

#ifdef Rte_Prm_EffortRackFY_Ary2D
# undef Rte_Prm_EffortRackFY_Ary2D
#else
#error Rte_Prm_EffortRackFY_Ary2D is missing
#endif
#define Rte_Prm_EffortRackFY_Ary2D() (&(Effort_Cal_EffortRackFY[0][0]))

#ifdef Rte_Prm_EffortScaBlndX_Ary1D
# undef Rte_Prm_EffortScaBlndX_Ary1D
#else
#error Rte_Prm_EffortScaBlndX_Ary1D is missing
#endif
#define Rte_Prm_EffortScaBlndX_Ary1D() (&(Effort_Cal_EffortScaBlndX[0]))

#ifdef Rte_Prm_EffortScaBlndY_Ary1D
# undef Rte_Prm_EffortScaBlndY_Ary1D
#else
#error Rte_Prm_EffortScaBlndY_Ary1D is missing
#endif
#define Rte_Prm_EffortScaBlndY_Ary1D() (&(Effort_Cal_EffortScaBlndY[0]))

#ifdef Rte_Prm_EffortScaRackFThd_Val
# undef Rte_Prm_EffortScaRackFThd_Val
#else
#error Rte_Prm_EffortScaRackFThd_Val is missing
#endif
#define Rte_Prm_EffortScaRackFThd_Val() (Effort_Cal_EffortScaRackFThd)

#ifdef Rte_Prm_EffortVehSpdBilnrSeln_Ary1D
# undef Rte_Prm_EffortVehSpdBilnrSeln_Ary1D
#else
#error Rte_Prm_EffortVehSpdBilnrSeln_Ary1D is missing
#endif
#define Rte_Prm_EffortVehSpdBilnrSeln_Ary1D() (&(Effort_Cal_EffortVehSpdBilnrSeln[0]))


/*** Client Stub ***/

extern FUNC(void, AUTOMATIC) Rte_Stub(void);


#endif
