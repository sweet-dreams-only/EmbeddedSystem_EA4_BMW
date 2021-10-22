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
extern VAR(float32, AUTOMATIC) GlbLimr_Ip_HwTq;
extern VAR(float32, AUTOMATIC) GlbLimr_Ip_MotTqCmd;
extern VAR(float32, AUTOMATIC) GlbLimr_Ip_VehSpd;

/* Outputs */
extern VAR(float32, AUTOMATIC) GlbLimr_Op_LimdMotTqCmd;

/* Calibrations */
extern CONST(s4p11, AUTOMATIC) GlbLimr_Cal_GlbLimrBndX[10][13];
extern CONST(s4p11, AUTOMATIC) GlbLimr_Cal_GlbLimrBndY[10][13];
extern CONST(FilNotchGainRec1, AUTOMATIC) GlbLimr_Cal_GlbLimrNotchFilStruct[1];
extern CONST(u9p7, AUTOMATIC) GlbLimr_Cal_GlbLimrVehSpdBilnrSeln[10];

/* PIMs */
extern VAR(float32, AUTOMATIC) GlbLimr_Pim_GlbLimrNotch1Fil1;
extern VAR(float32, AUTOMATIC) GlbLimr_Pim_GlbLimrNotch1Fil2;
extern VAR(float32, AUTOMATIC) GlbLimr_Pim_GlbLimrNotch2Fil1;
extern VAR(float32, AUTOMATIC) GlbLimr_Pim_GlbLimrNotch2Fil2;

/* Arguments and Returns */


/*** Input Stubs ***/

#ifdef Rte_Read_HwTq_Val
# undef Rte_Read_HwTq_Val
#else
#error Rte_Read_HwTq_Val is missing
#endif
#define Rte_Read_HwTq_Val(data) (*(data) = GlbLimr_Ip_HwTq)

#ifdef Rte_Read_MotTqCmd_Val
# undef Rte_Read_MotTqCmd_Val
#else
#error Rte_Read_MotTqCmd_Val is missing
#endif
#define Rte_Read_MotTqCmd_Val(data) (*(data) = GlbLimr_Ip_MotTqCmd)

#ifdef Rte_Read_VehSpd_Val
# undef Rte_Read_VehSpd_Val
#else
#error Rte_Read_VehSpd_Val is missing
#endif
#define Rte_Read_VehSpd_Val(data) (*(data) = GlbLimr_Ip_VehSpd)


/*** Output Stubs ***/

#ifdef Rte_Write_LimdMotTqCmd_Val
# undef Rte_Write_LimdMotTqCmd_Val
#else
#error Rte_Write_LimdMotTqCmd_Val is missing
#endif
#define Rte_Write_LimdMotTqCmd_Val(data) (GlbLimr_Op_LimdMotTqCmd = (data))


/*** Calibration Stubs ***/

#ifdef Rte_Prm_GlbLimrBndX_Ary2D
# undef Rte_Prm_GlbLimrBndX_Ary2D
#else
#error Rte_Prm_GlbLimrBndX_Ary2D is missing
#endif
#define Rte_Prm_GlbLimrBndX_Ary2D() (&(GlbLimr_Cal_GlbLimrBndX[0][0]))

#ifdef Rte_Prm_GlbLimrBndY_Ary2D
# undef Rte_Prm_GlbLimrBndY_Ary2D
#else
#error Rte_Prm_GlbLimrBndY_Ary2D is missing
#endif
#define Rte_Prm_GlbLimrBndY_Ary2D() (&(GlbLimr_Cal_GlbLimrBndY[0][0]))

#ifdef Rte_Prm_GlbLimrNotchFilStruct_Rec
# undef Rte_Prm_GlbLimrNotchFilStruct_Rec
#else
#error Rte_Prm_GlbLimrNotchFilStruct_Rec is missing
#endif
#define Rte_Prm_GlbLimrNotchFilStruct_Rec() (&(GlbLimr_Cal_GlbLimrNotchFilStruct[0]))

#ifdef Rte_Prm_GlbLimrVehSpdBilnrSeln_Ary1D
# undef Rte_Prm_GlbLimrVehSpdBilnrSeln_Ary1D
#else
#error Rte_Prm_GlbLimrVehSpdBilnrSeln_Ary1D is missing
#endif
#define Rte_Prm_GlbLimrVehSpdBilnrSeln_Ary1D() (&(GlbLimr_Cal_GlbLimrVehSpdBilnrSeln[0]))


/*** PIM Stubs ***/

#ifdef Rte_Pim_GlbLimrNotch1Fil1
# undef Rte_Pim_GlbLimrNotch1Fil1
#else
#error Rte_Pim_GlbLimrNotch1Fil1 is missing
#endif
#define Rte_Pim_GlbLimrNotch1Fil1() (&GlbLimr_Pim_GlbLimrNotch1Fil1)

#ifdef Rte_Pim_GlbLimrNotch1Fil2
# undef Rte_Pim_GlbLimrNotch1Fil2
#else
#error Rte_Pim_GlbLimrNotch1Fil2 is missing
#endif
#define Rte_Pim_GlbLimrNotch1Fil2() (&GlbLimr_Pim_GlbLimrNotch1Fil2)

#ifdef Rte_Pim_GlbLimrNotch2Fil1
# undef Rte_Pim_GlbLimrNotch2Fil1
#else
#error Rte_Pim_GlbLimrNotch2Fil1 is missing
#endif
#define Rte_Pim_GlbLimrNotch2Fil1() (&GlbLimr_Pim_GlbLimrNotch2Fil1)

#ifdef Rte_Pim_GlbLimrNotch2Fil2
# undef Rte_Pim_GlbLimrNotch2Fil2
#else
#error Rte_Pim_GlbLimrNotch2Fil2 is missing
#endif
#define Rte_Pim_GlbLimrNotch2Fil2() (&GlbLimr_Pim_GlbLimrNotch2Fil2)


/*** Client Stub ***/

extern FUNC(void, AUTOMATIC) Rte_Stub(void);


#endif
