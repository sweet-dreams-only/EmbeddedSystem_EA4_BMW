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
extern VAR(float32, AUTOMATIC) SysKineAndEff_Ip_CmplncErrPinionToHw;
extern VAR(s18p13, AUTOMATIC) SysKineAndEff_Ip_MotAgCumvAlgndMrf;
extern VAR(float32, AUTOMATIC) SysKineAndEff_Ip_MotVelCrf;
extern VAR(float32, AUTOMATIC) SysKineAndEff_Ip_PinionAg;

/* Outputs */
extern VAR(float32, AUTOMATIC) SysKineAndEff_Op_HwAg;
extern VAR(float32, AUTOMATIC) SysKineAndEff_Op_HwVel;
extern VAR(float32, AUTOMATIC) SysKineAndEff_Op_MotAgToRackPosnInstsRat;
extern VAR(float32, AUTOMATIC) SysKineAndEff_Op_MotToRackFInstsRat;
extern VAR(float32, AUTOMATIC) SysKineAndEff_Op_MotToRackInstsEff;
extern VAR(float32, AUTOMATIC) SysKineAndEff_Op_PinionAgToRackInstsEff;
extern VAR(float32, AUTOMATIC) SysKineAndEff_Op_PinionAgToRackPosnInstsRat;
extern VAR(float32, AUTOMATIC) SysKineAndEff_Op_PinionTqToRackFInstsRat;
extern VAR(float32, AUTOMATIC) SysKineAndEff_Op_PinionVel;
extern VAR(float32, AUTOMATIC) SysKineAndEff_Op_RackPosn;
extern VAR(float32, AUTOMATIC) SysKineAndEff_Op_RackVel;
extern VAR(float32, AUTOMATIC) SysKineAndEff_Op_RoadWhlAg;
extern VAR(float32, AUTOMATIC) SysKineAndEff_Op_SteerArmLen;
extern VAR(float32, AUTOMATIC) SysKineAndEff_Op_SysAssiTqRat;
extern VAR(float32, AUTOMATIC) SysKineAndEff_Op_SysKineRat;
extern VAR(float32, AUTOMATIC) SysKineAndEff_Op_SysTqRat;

/* Calibrations */
extern CONST(float32, AUTOMATIC) SysKineAndEff_Cal_SysKineAndEffCmplncErrDerivtvCutOffFrq;
extern CONST(s15p0, AUTOMATIC) SysKineAndEff_Cal_SysKineAndEffMotAgScaX[21];
extern CONST(u4p12, AUTOMATIC) SysKineAndEff_Cal_SysKineAndEffMotAgToRackPosRatScaY[21];
extern CONST(u1p15, AUTOMATIC) SysKineAndEff_Cal_SysKineAndEffMotToRackEffScaY[21];
extern CONST(u5p11, AUTOMATIC) SysKineAndEff_Cal_SysKineAndEffPinionAgToRackPosRatScaY[21];
extern CONST(u1p15, AUTOMATIC) SysKineAndEff_Cal_SysKineAndEffPinionToRackEffScaY[21];
extern CONST(s8p7, AUTOMATIC) SysKineAndEff_Cal_SysKineAndEffRackPosScaY[21];
extern CONST(s2p13, AUTOMATIC) SysKineAndEff_Cal_SysKineAndEffRoadWhlFromRackPosScaY[21];
extern CONST(u1p15, AUTOMATIC) SysKineAndEff_Cal_SysKineAndEffSteerArmLenFromRackPosScaY[21];

/* PIMs */
extern VAR(float32, AUTOMATIC) SysKineAndEff_Pim_CmplncErrDerivtvPrev;
extern VAR(float32, AUTOMATIC) SysKineAndEff_Pim_CmplncErrPinionToHwPrev;

/* Arguments and Returns */


/*** Input Stubs ***/

#ifdef Rte_Read_CmplncErrPinionToHw_Val
# undef Rte_Read_CmplncErrPinionToHw_Val
#else
#error Rte_Read_CmplncErrPinionToHw_Val is missing
#endif
#define Rte_Read_CmplncErrPinionToHw_Val(data) (*(data) = SysKineAndEff_Ip_CmplncErrPinionToHw)

#ifdef Rte_Read_MotAgCumvAlgndMrf_Val
# undef Rte_Read_MotAgCumvAlgndMrf_Val
#else
#error Rte_Read_MotAgCumvAlgndMrf_Val is missing
#endif
#define Rte_Read_MotAgCumvAlgndMrf_Val(data) (*(data) = SysKineAndEff_Ip_MotAgCumvAlgndMrf)

#ifdef Rte_Read_MotVelCrf_Val
# undef Rte_Read_MotVelCrf_Val
#else
#error Rte_Read_MotVelCrf_Val is missing
#endif
#define Rte_Read_MotVelCrf_Val(data) (*(data) = SysKineAndEff_Ip_MotVelCrf)

#ifdef Rte_Read_PinionAg_Val
# undef Rte_Read_PinionAg_Val
#else
#error Rte_Read_PinionAg_Val is missing
#endif
#define Rte_Read_PinionAg_Val(data) (*(data) = SysKineAndEff_Ip_PinionAg)


/*** Output Stubs ***/

#ifdef Rte_Write_HwAg_Val
# undef Rte_Write_HwAg_Val
#else
#error Rte_Write_HwAg_Val is missing
#endif
#define Rte_Write_HwAg_Val(data) (SysKineAndEff_Op_HwAg = (data))

#ifdef Rte_Write_HwVel_Val
# undef Rte_Write_HwVel_Val
#else
#error Rte_Write_HwVel_Val is missing
#endif
#define Rte_Write_HwVel_Val(data) (SysKineAndEff_Op_HwVel = (data))

#ifdef Rte_Write_MotAgToRackPosnInstsRat_Val
# undef Rte_Write_MotAgToRackPosnInstsRat_Val
#else
#error Rte_Write_MotAgToRackPosnInstsRat_Val is missing
#endif
#define Rte_Write_MotAgToRackPosnInstsRat_Val(data) (SysKineAndEff_Op_MotAgToRackPosnInstsRat = (data))

#ifdef Rte_Write_MotToRackFInstsRat_Val
# undef Rte_Write_MotToRackFInstsRat_Val
#else
#error Rte_Write_MotToRackFInstsRat_Val is missing
#endif
#define Rte_Write_MotToRackFInstsRat_Val(data) (SysKineAndEff_Op_MotToRackFInstsRat = (data))

#ifdef Rte_Write_MotToRackInstsEff_Val
# undef Rte_Write_MotToRackInstsEff_Val
#else
#error Rte_Write_MotToRackInstsEff_Val is missing
#endif
#define Rte_Write_MotToRackInstsEff_Val(data) (SysKineAndEff_Op_MotToRackInstsEff = (data))

#ifdef Rte_Write_PinionAgToRackInstsEff_Val
# undef Rte_Write_PinionAgToRackInstsEff_Val
#else
#error Rte_Write_PinionAgToRackInstsEff_Val is missing
#endif
#define Rte_Write_PinionAgToRackInstsEff_Val(data) (SysKineAndEff_Op_PinionAgToRackInstsEff = (data))

#ifdef Rte_Write_PinionAgToRackPosnInstsRat_Val
# undef Rte_Write_PinionAgToRackPosnInstsRat_Val
#else
#error Rte_Write_PinionAgToRackPosnInstsRat_Val is missing
#endif
#define Rte_Write_PinionAgToRackPosnInstsRat_Val(data) (SysKineAndEff_Op_PinionAgToRackPosnInstsRat = (data))

#ifdef Rte_Write_PinionTqToRackFInstsRat_Val
# undef Rte_Write_PinionTqToRackFInstsRat_Val
#else
#error Rte_Write_PinionTqToRackFInstsRat_Val is missing
#endif
#define Rte_Write_PinionTqToRackFInstsRat_Val(data) (SysKineAndEff_Op_PinionTqToRackFInstsRat = (data))

#ifdef Rte_Write_PinionVel_Val
# undef Rte_Write_PinionVel_Val
#else
#error Rte_Write_PinionVel_Val is missing
#endif
#define Rte_Write_PinionVel_Val(data) (SysKineAndEff_Op_PinionVel = (data))

#ifdef Rte_Write_RackPosn_Val
# undef Rte_Write_RackPosn_Val
#else
#error Rte_Write_RackPosn_Val is missing
#endif
#define Rte_Write_RackPosn_Val(data) (SysKineAndEff_Op_RackPosn = (data))

#ifdef Rte_Write_RackVel_Val
# undef Rte_Write_RackVel_Val
#else
#error Rte_Write_RackVel_Val is missing
#endif
#define Rte_Write_RackVel_Val(data) (SysKineAndEff_Op_RackVel = (data))

#ifdef Rte_Write_RoadWhlAg_Val
# undef Rte_Write_RoadWhlAg_Val
#else
#error Rte_Write_RoadWhlAg_Val is missing
#endif
#define Rte_Write_RoadWhlAg_Val(data) (SysKineAndEff_Op_RoadWhlAg = (data))

#ifdef Rte_Write_SteerArmLen_Val
# undef Rte_Write_SteerArmLen_Val
#else
#error Rte_Write_SteerArmLen_Val is missing
#endif
#define Rte_Write_SteerArmLen_Val(data) (SysKineAndEff_Op_SteerArmLen = (data))

#ifdef Rte_Write_SysAssiTqRat_Val
# undef Rte_Write_SysAssiTqRat_Val
#else
#error Rte_Write_SysAssiTqRat_Val is missing
#endif
#define Rte_Write_SysAssiTqRat_Val(data) (SysKineAndEff_Op_SysAssiTqRat = (data))

#ifdef Rte_Write_SysKineRat_Val
# undef Rte_Write_SysKineRat_Val
#else
#error Rte_Write_SysKineRat_Val is missing
#endif
#define Rte_Write_SysKineRat_Val(data) (SysKineAndEff_Op_SysKineRat = (data))

#ifdef Rte_Write_SysTqRat_Val
# undef Rte_Write_SysTqRat_Val
#else
#error Rte_Write_SysTqRat_Val is missing
#endif
#define Rte_Write_SysTqRat_Val(data) (SysKineAndEff_Op_SysTqRat = (data))


/*** Calibration Stubs ***/

#ifdef Rte_Prm_SysKineAndEffCmplncErrDerivtvCutOffFrq_Val
# undef Rte_Prm_SysKineAndEffCmplncErrDerivtvCutOffFrq_Val
#else
#error Rte_Prm_SysKineAndEffCmplncErrDerivtvCutOffFrq_Val is missing
#endif
#define Rte_Prm_SysKineAndEffCmplncErrDerivtvCutOffFrq_Val() (SysKineAndEff_Cal_SysKineAndEffCmplncErrDerivtvCutOffFrq)

#ifdef Rte_Prm_SysKineAndEffMotAgScaX_Ary1D
# undef Rte_Prm_SysKineAndEffMotAgScaX_Ary1D
#else
#error Rte_Prm_SysKineAndEffMotAgScaX_Ary1D is missing
#endif
#define Rte_Prm_SysKineAndEffMotAgScaX_Ary1D() (&(SysKineAndEff_Cal_SysKineAndEffMotAgScaX[0]))

#ifdef Rte_Prm_SysKineAndEffMotAgToRackPosRatScaY_Ary1D
# undef Rte_Prm_SysKineAndEffMotAgToRackPosRatScaY_Ary1D
#else
#error Rte_Prm_SysKineAndEffMotAgToRackPosRatScaY_Ary1D is missing
#endif
#define Rte_Prm_SysKineAndEffMotAgToRackPosRatScaY_Ary1D() (&(SysKineAndEff_Cal_SysKineAndEffMotAgToRackPosRatScaY[0]))

#ifdef Rte_Prm_SysKineAndEffMotToRackEffScaY_Ary1D
# undef Rte_Prm_SysKineAndEffMotToRackEffScaY_Ary1D
#else
#error Rte_Prm_SysKineAndEffMotToRackEffScaY_Ary1D is missing
#endif
#define Rte_Prm_SysKineAndEffMotToRackEffScaY_Ary1D() (&(SysKineAndEff_Cal_SysKineAndEffMotToRackEffScaY[0]))

#ifdef Rte_Prm_SysKineAndEffPinionAgToRackPosRatScaY_Ary1D
# undef Rte_Prm_SysKineAndEffPinionAgToRackPosRatScaY_Ary1D
#else
#error Rte_Prm_SysKineAndEffPinionAgToRackPosRatScaY_Ary1D is missing
#endif
#define Rte_Prm_SysKineAndEffPinionAgToRackPosRatScaY_Ary1D() (&(SysKineAndEff_Cal_SysKineAndEffPinionAgToRackPosRatScaY[0]))

#ifdef Rte_Prm_SysKineAndEffPinionToRackEffScaY_Ary1D
# undef Rte_Prm_SysKineAndEffPinionToRackEffScaY_Ary1D
#else
#error Rte_Prm_SysKineAndEffPinionToRackEffScaY_Ary1D is missing
#endif
#define Rte_Prm_SysKineAndEffPinionToRackEffScaY_Ary1D() (&(SysKineAndEff_Cal_SysKineAndEffPinionToRackEffScaY[0]))

#ifdef Rte_Prm_SysKineAndEffRackPosScaY_Ary1D
# undef Rte_Prm_SysKineAndEffRackPosScaY_Ary1D
#else
#error Rte_Prm_SysKineAndEffRackPosScaY_Ary1D is missing
#endif
#define Rte_Prm_SysKineAndEffRackPosScaY_Ary1D() (&(SysKineAndEff_Cal_SysKineAndEffRackPosScaY[0]))

#ifdef Rte_Prm_SysKineAndEffRoadWhlFromRackPosScaY_Ary1D
# undef Rte_Prm_SysKineAndEffRoadWhlFromRackPosScaY_Ary1D
#else
#error Rte_Prm_SysKineAndEffRoadWhlFromRackPosScaY_Ary1D is missing
#endif
#define Rte_Prm_SysKineAndEffRoadWhlFromRackPosScaY_Ary1D() (&(SysKineAndEff_Cal_SysKineAndEffRoadWhlFromRackPosScaY[0]))

#ifdef Rte_Prm_SysKineAndEffSteerArmLenFromRackPosScaY_Ary1D
# undef Rte_Prm_SysKineAndEffSteerArmLenFromRackPosScaY_Ary1D
#else
#error Rte_Prm_SysKineAndEffSteerArmLenFromRackPosScaY_Ary1D is missing
#endif
#define Rte_Prm_SysKineAndEffSteerArmLenFromRackPosScaY_Ary1D() (&(SysKineAndEff_Cal_SysKineAndEffSteerArmLenFromRackPosScaY[0]))


/*** PIM Stubs ***/

#ifdef Rte_Pim_CmplncErrDerivtvPrev
# undef Rte_Pim_CmplncErrDerivtvPrev
#else
#error Rte_Pim_CmplncErrDerivtvPrev is missing
#endif
#define Rte_Pim_CmplncErrDerivtvPrev() (&SysKineAndEff_Pim_CmplncErrDerivtvPrev)

#ifdef Rte_Pim_CmplncErrPinionToHwPrev
# undef Rte_Pim_CmplncErrPinionToHwPrev
#else
#error Rte_Pim_CmplncErrPinionToHwPrev is missing
#endif
#define Rte_Pim_CmplncErrPinionToHwPrev() (&SysKineAndEff_Pim_CmplncErrPinionToHwPrev)


/*** Client Stub ***/

extern FUNC(void, AUTOMATIC) Rte_Stub(void);


#endif
