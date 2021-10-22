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
extern VAR(float32, AUTOMATIC) EpsStEstimn_Ip_HwTq;
extern VAR(float32, AUTOMATIC) EpsStEstimn_Ip_MotTqEstimd;
extern VAR(float32, AUTOMATIC) EpsStEstimn_Ip_MotVelCrf;
extern VAR(float32, AUTOMATIC) EpsStEstimn_Ip_PinionTqToRackFInstsRat;
extern VAR(float32, AUTOMATIC) EpsStEstimn_Ip_SysKineRat;
extern VAR(float32, AUTOMATIC) EpsStEstimn_Ip_SysTqRat;

/* Outputs */
extern VAR(float32, AUTOMATIC) EpsStEstimn_Op_RackFEstimd;
extern VAR(TorsBarStEstimdRec1, AUTOMATIC) EpsStEstimn_Op_TorsBarStEstimd;

/* Calibrations */
extern CONST(float32, AUTOMATIC) EpsStEstimn_Cal_EpsStEstimnMtrxA[5][5];
extern CONST(float32, AUTOMATIC) EpsStEstimn_Cal_EpsStEstimnMtrxB[3][5];
extern CONST(float32, AUTOMATIC) EpsStEstimn_Cal_EpsStEstimnMtrxC[5][5];
extern CONST(float32, AUTOMATIC) EpsStEstimn_Cal_EpsStEstimnMtrxD[3][5];

/* PIMs */
extern VAR(float32, AUTOMATIC) EpsStEstimn_Pim_StEstimrStPrev[5];

/* Arguments and Returns */


/*** Input Stubs ***/

#ifdef Rte_Read_HwTq_Val
# undef Rte_Read_HwTq_Val
#else
#error Rte_Read_HwTq_Val is missing
#endif
#define Rte_Read_HwTq_Val(data) (*(data) = EpsStEstimn_Ip_HwTq)

#ifdef Rte_Read_MotTqEstimd_Val
# undef Rte_Read_MotTqEstimd_Val
#else
#error Rte_Read_MotTqEstimd_Val is missing
#endif
#define Rte_Read_MotTqEstimd_Val(data) (*(data) = EpsStEstimn_Ip_MotTqEstimd)

#ifdef Rte_Read_MotVelCrf_Val
# undef Rte_Read_MotVelCrf_Val
#else
#error Rte_Read_MotVelCrf_Val is missing
#endif
#define Rte_Read_MotVelCrf_Val(data) (*(data) = EpsStEstimn_Ip_MotVelCrf)

#ifdef Rte_Read_PinionTqToRackFInstsRat_Val
# undef Rte_Read_PinionTqToRackFInstsRat_Val
#else
#error Rte_Read_PinionTqToRackFInstsRat_Val is missing
#endif
#define Rte_Read_PinionTqToRackFInstsRat_Val(data) (*(data) = EpsStEstimn_Ip_PinionTqToRackFInstsRat)

#ifdef Rte_Read_SysKineRat_Val
# undef Rte_Read_SysKineRat_Val
#else
#error Rte_Read_SysKineRat_Val is missing
#endif
#define Rte_Read_SysKineRat_Val(data) (*(data) = EpsStEstimn_Ip_SysKineRat)

#ifdef Rte_Read_SysTqRat_Val
# undef Rte_Read_SysTqRat_Val
#else
#error Rte_Read_SysTqRat_Val is missing
#endif
#define Rte_Read_SysTqRat_Val(data) (*(data) = EpsStEstimn_Ip_SysTqRat)


/*** Output Stubs ***/

#ifdef Rte_Write_RackFEstimd_Val
# undef Rte_Write_RackFEstimd_Val
#else
#error Rte_Write_RackFEstimd_Val is missing
#endif
#define Rte_Write_RackFEstimd_Val(data) (EpsStEstimn_Op_RackFEstimd = (data))

#ifdef Rte_Write_TorsBarStEstimd_Rec
# undef Rte_Write_TorsBarStEstimd_Rec
#else
#error Rte_Write_TorsBarStEstimd_Rec is missing
#endif
#define Rte_Write_TorsBarStEstimd_Rec(data) (EpsStEstimn_Op_TorsBarStEstimd = (*(data)))


/*** Calibration Stubs ***/

#ifdef Rte_Prm_EpsStEstimnMtrxA_Ary2D
# undef Rte_Prm_EpsStEstimnMtrxA_Ary2D
#else
#error Rte_Prm_EpsStEstimnMtrxA_Ary2D is missing
#endif
#define Rte_Prm_EpsStEstimnMtrxA_Ary2D() (&(EpsStEstimn_Cal_EpsStEstimnMtrxA[0][0]))

#ifdef Rte_Prm_EpsStEstimnMtrxB_Ary2D
# undef Rte_Prm_EpsStEstimnMtrxB_Ary2D
#else
#error Rte_Prm_EpsStEstimnMtrxB_Ary2D is missing
#endif
#define Rte_Prm_EpsStEstimnMtrxB_Ary2D() (&(EpsStEstimn_Cal_EpsStEstimnMtrxB[0][0]))

#ifdef Rte_Prm_EpsStEstimnMtrxC_Ary2D
# undef Rte_Prm_EpsStEstimnMtrxC_Ary2D
#else
#error Rte_Prm_EpsStEstimnMtrxC_Ary2D is missing
#endif
#define Rte_Prm_EpsStEstimnMtrxC_Ary2D() (&(EpsStEstimn_Cal_EpsStEstimnMtrxC[0][0]))

#ifdef Rte_Prm_EpsStEstimnMtrxD_Ary2D
# undef Rte_Prm_EpsStEstimnMtrxD_Ary2D
#else
#error Rte_Prm_EpsStEstimnMtrxD_Ary2D is missing
#endif
#define Rte_Prm_EpsStEstimnMtrxD_Ary2D() (&(EpsStEstimn_Cal_EpsStEstimnMtrxD[0][0]))


/*** PIM Stubs ***/

#ifdef Rte_Pim_StEstimrStPrev
# undef Rte_Pim_StEstimrStPrev
#else
#error Rte_Pim_StEstimrStPrev is missing
#endif
#define Rte_Pim_StEstimrStPrev() (&(EpsStEstimn_Pim_StEstimrStPrev[0]))


/*** Client Stub ***/

extern FUNC(void, AUTOMATIC) Rte_Stub(void);


#endif
