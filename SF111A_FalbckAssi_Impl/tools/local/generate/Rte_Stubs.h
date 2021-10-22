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
extern VAR(float32, AUTOMATIC) FalbckAssi_Ip_HwTq;
extern VAR(float32, AUTOMATIC) FalbckAssi_Ip_VehSpd;

/* Outputs */
extern VAR(float32, AUTOMATIC) FalbckAssi_Op_FalbckAssiMotTqCmd;

/* Calibrations */
extern CONST(u6p10, AUTOMATIC) FalbckAssi_Cal_FalbckAssiAssiX[12][20];
extern CONST(u4p12, AUTOMATIC) FalbckAssi_Cal_FalbckAssiAssiY[12][20];
extern CONST(FilNotchGainRec1, AUTOMATIC) FalbckAssi_Cal_FalbckAssiNotchFil[1];
extern CONST(u9p7, AUTOMATIC) FalbckAssi_Cal_SysGlbPrmVehSpdBilnrSeln[12];

/* PIMs */
extern VAR(float32, AUTOMATIC) FalbckAssi_Pim_FalbckAssiNotchFil1;
extern VAR(float32, AUTOMATIC) FalbckAssi_Pim_FalbckAssiNotchFil2;

/* Arguments and Returns */


/*** Input Stubs ***/

#ifdef Rte_Read_HwTq_Val
# undef Rte_Read_HwTq_Val
#else
#error Rte_Read_HwTq_Val is missing
#endif
#define Rte_Read_HwTq_Val(data) (*(data) = FalbckAssi_Ip_HwTq)

#ifdef Rte_Read_VehSpd_Val
# undef Rte_Read_VehSpd_Val
#else
#error Rte_Read_VehSpd_Val is missing
#endif
#define Rte_Read_VehSpd_Val(data) (*(data) = FalbckAssi_Ip_VehSpd)


/*** Output Stubs ***/

#ifdef Rte_Write_FalbckAssiMotTqCmd_Val
# undef Rte_Write_FalbckAssiMotTqCmd_Val
#else
#error Rte_Write_FalbckAssiMotTqCmd_Val is missing
#endif
#define Rte_Write_FalbckAssiMotTqCmd_Val(data) (FalbckAssi_Op_FalbckAssiMotTqCmd = (data))


/*** Calibration Stubs ***/

#ifdef Rte_Prm_FalbckAssiAssiX_Ary2D
# undef Rte_Prm_FalbckAssiAssiX_Ary2D
#else
#error Rte_Prm_FalbckAssiAssiX_Ary2D is missing
#endif
#define Rte_Prm_FalbckAssiAssiX_Ary2D() (&(FalbckAssi_Cal_FalbckAssiAssiX[0][0]))

#ifdef Rte_Prm_FalbckAssiAssiY_Ary2D
# undef Rte_Prm_FalbckAssiAssiY_Ary2D
#else
#error Rte_Prm_FalbckAssiAssiY_Ary2D is missing
#endif
#define Rte_Prm_FalbckAssiAssiY_Ary2D() (&(FalbckAssi_Cal_FalbckAssiAssiY[0][0]))

#ifdef Rte_Prm_FalbckAssiNotchFil_Rec
# undef Rte_Prm_FalbckAssiNotchFil_Rec
#else
#error Rte_Prm_FalbckAssiNotchFil_Rec is missing
#endif
#define Rte_Prm_FalbckAssiNotchFil_Rec() (&(FalbckAssi_Cal_FalbckAssiNotchFil[0]))

#ifdef Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D
# undef Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D
#else
#error Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D is missing
#endif
#define Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D() (&(FalbckAssi_Cal_SysGlbPrmVehSpdBilnrSeln[0]))


/*** PIM Stubs ***/

#ifdef Rte_Pim_FalbckAssiNotchFil1
# undef Rte_Pim_FalbckAssiNotchFil1
#else
#error Rte_Pim_FalbckAssiNotchFil1 is missing
#endif
#define Rte_Pim_FalbckAssiNotchFil1() (&FalbckAssi_Pim_FalbckAssiNotchFil1)

#ifdef Rte_Pim_FalbckAssiNotchFil2
# undef Rte_Pim_FalbckAssiNotchFil2
#else
#error Rte_Pim_FalbckAssiNotchFil2 is missing
#endif
#define Rte_Pim_FalbckAssiNotchFil2() (&FalbckAssi_Pim_FalbckAssiNotchFil2)


/*** Client Stub ***/

extern FUNC(void, AUTOMATIC) Rte_Stub(void);


#endif
