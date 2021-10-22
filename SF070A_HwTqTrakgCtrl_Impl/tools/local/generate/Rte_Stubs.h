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
extern VAR(float32, AUTOMATIC) HwTqTrakgCtrl_Ip_HwTqCmd;
extern VAR(float32, AUTOMATIC) HwTqTrakgCtrl_Ip_MotTqCmdOvrl;
extern VAR(float32, AUTOMATIC) HwTqTrakgCtrl_Ip_SysTqRat;
extern VAR(TorsBarStEstimdRec1, AUTOMATIC) HwTqTrakgCtrl_Ip_TorsBarStEstimd;
extern VAR(float32, AUTOMATIC) HwTqTrakgCtrl_Ip_VehSpd;

/* Outputs */
extern VAR(float32, AUTOMATIC) HwTqTrakgCtrl_Op_MotTqCmdTrakgCtrl;

/* Calibrations */
extern CONST(s3p12, AUTOMATIC) HwTqTrakgCtrl_Cal_HwTqTrakgCtrlFbGain1[4];
extern CONST(s14p1, AUTOMATIC) HwTqTrakgCtrl_Cal_HwTqTrakgCtrlFbGain2[4];
extern CONST(s8p7, AUTOMATIC) HwTqTrakgCtrl_Cal_HwTqTrakgCtrlFbGain3[4];
extern CONST(s3p12, AUTOMATIC) HwTqTrakgCtrl_Cal_HwTqTrakgCtrlFbGain4[4];
extern CONST(s3p12, AUTOMATIC) HwTqTrakgCtrl_Cal_HwTqTrakgCtrlFbGain5[4];
extern CONST(s7p8, AUTOMATIC) HwTqTrakgCtrl_Cal_HwTqTrakgCtrlFfGainScaY[4];
extern CONST(float32, AUTOMATIC) HwTqTrakgCtrl_Cal_HwTqTrakgCtrlMotTqCmdOvrlGain;
extern CONST(u9p7, AUTOMATIC) HwTqTrakgCtrl_Cal_HwTqTrakgCtrlVehSpdScaX[4];

/* Arguments and Returns */


/*** Input Stubs ***/

#ifdef Rte_Read_HwTqCmd_Val
# undef Rte_Read_HwTqCmd_Val
#else
#error Rte_Read_HwTqCmd_Val is missing
#endif
#define Rte_Read_HwTqCmd_Val(data) (*(data) = HwTqTrakgCtrl_Ip_HwTqCmd)

#ifdef Rte_Read_MotTqCmdOvrl_Val
# undef Rte_Read_MotTqCmdOvrl_Val
#else
#error Rte_Read_MotTqCmdOvrl_Val is missing
#endif
#define Rte_Read_MotTqCmdOvrl_Val(data) (*(data) = HwTqTrakgCtrl_Ip_MotTqCmdOvrl)

#ifdef Rte_Read_SysTqRat_Val
# undef Rte_Read_SysTqRat_Val
#else
#error Rte_Read_SysTqRat_Val is missing
#endif
#define Rte_Read_SysTqRat_Val(data) (*(data) = HwTqTrakgCtrl_Ip_SysTqRat)

#ifdef Rte_Read_TorsBarStEstimd_Rec
# undef Rte_Read_TorsBarStEstimd_Rec
#else
#error Rte_Read_TorsBarStEstimd_Rec is missing
#endif
#define Rte_Read_TorsBarStEstimd_Rec(data) (*(data) = HwTqTrakgCtrl_Ip_TorsBarStEstimd)

#ifdef Rte_Read_VehSpd_Val
# undef Rte_Read_VehSpd_Val
#else
#error Rte_Read_VehSpd_Val is missing
#endif
#define Rte_Read_VehSpd_Val(data) (*(data) = HwTqTrakgCtrl_Ip_VehSpd)


/*** Output Stubs ***/

#ifdef Rte_Write_MotTqCmdTrakgCtrl_Val
# undef Rte_Write_MotTqCmdTrakgCtrl_Val
#else
#error Rte_Write_MotTqCmdTrakgCtrl_Val is missing
#endif
#define Rte_Write_MotTqCmdTrakgCtrl_Val(data) (HwTqTrakgCtrl_Op_MotTqCmdTrakgCtrl = (data))


/*** Calibration Stubs ***/

#ifdef Rte_Prm_HwTqTrakgCtrlFbGain1_Ary1D
# undef Rte_Prm_HwTqTrakgCtrlFbGain1_Ary1D
#else
#error Rte_Prm_HwTqTrakgCtrlFbGain1_Ary1D is missing
#endif
#define Rte_Prm_HwTqTrakgCtrlFbGain1_Ary1D() (&(HwTqTrakgCtrl_Cal_HwTqTrakgCtrlFbGain1[0]))

#ifdef Rte_Prm_HwTqTrakgCtrlFbGain2_Ary1D
# undef Rte_Prm_HwTqTrakgCtrlFbGain2_Ary1D
#else
#error Rte_Prm_HwTqTrakgCtrlFbGain2_Ary1D is missing
#endif
#define Rte_Prm_HwTqTrakgCtrlFbGain2_Ary1D() (&(HwTqTrakgCtrl_Cal_HwTqTrakgCtrlFbGain2[0]))

#ifdef Rte_Prm_HwTqTrakgCtrlFbGain3_Ary1D
# undef Rte_Prm_HwTqTrakgCtrlFbGain3_Ary1D
#else
#error Rte_Prm_HwTqTrakgCtrlFbGain3_Ary1D is missing
#endif
#define Rte_Prm_HwTqTrakgCtrlFbGain3_Ary1D() (&(HwTqTrakgCtrl_Cal_HwTqTrakgCtrlFbGain3[0]))

#ifdef Rte_Prm_HwTqTrakgCtrlFbGain4_Ary1D
# undef Rte_Prm_HwTqTrakgCtrlFbGain4_Ary1D
#else
#error Rte_Prm_HwTqTrakgCtrlFbGain4_Ary1D is missing
#endif
#define Rte_Prm_HwTqTrakgCtrlFbGain4_Ary1D() (&(HwTqTrakgCtrl_Cal_HwTqTrakgCtrlFbGain4[0]))

#ifdef Rte_Prm_HwTqTrakgCtrlFbGain5_Ary1D
# undef Rte_Prm_HwTqTrakgCtrlFbGain5_Ary1D
#else
#error Rte_Prm_HwTqTrakgCtrlFbGain5_Ary1D is missing
#endif
#define Rte_Prm_HwTqTrakgCtrlFbGain5_Ary1D() (&(HwTqTrakgCtrl_Cal_HwTqTrakgCtrlFbGain5[0]))

#ifdef Rte_Prm_HwTqTrakgCtrlFfGainScaY_Ary1D
# undef Rte_Prm_HwTqTrakgCtrlFfGainScaY_Ary1D
#else
#error Rte_Prm_HwTqTrakgCtrlFfGainScaY_Ary1D is missing
#endif
#define Rte_Prm_HwTqTrakgCtrlFfGainScaY_Ary1D() (&(HwTqTrakgCtrl_Cal_HwTqTrakgCtrlFfGainScaY[0]))

#ifdef Rte_Prm_HwTqTrakgCtrlMotTqCmdOvrlGain_Val
# undef Rte_Prm_HwTqTrakgCtrlMotTqCmdOvrlGain_Val
#else
#error Rte_Prm_HwTqTrakgCtrlMotTqCmdOvrlGain_Val is missing
#endif
#define Rte_Prm_HwTqTrakgCtrlMotTqCmdOvrlGain_Val() (HwTqTrakgCtrl_Cal_HwTqTrakgCtrlMotTqCmdOvrlGain)

#ifdef Rte_Prm_HwTqTrakgCtrlVehSpdScaX_Ary1D
# undef Rte_Prm_HwTqTrakgCtrlVehSpdScaX_Ary1D
#else
#error Rte_Prm_HwTqTrakgCtrlVehSpdScaX_Ary1D is missing
#endif
#define Rte_Prm_HwTqTrakgCtrlVehSpdScaX_Ary1D() (&(HwTqTrakgCtrl_Cal_HwTqTrakgCtrlVehSpdScaX[0]))


/*** Client Stub ***/

extern FUNC(void, AUTOMATIC) Rte_Stub(void);


#endif
