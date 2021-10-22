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
extern VAR(float32, AUTOMATIC) BmwPwrPrkgDampg_Ip_DampgCmdBas;
extern VAR(boolean, AUTOMATIC) BmwPwrPrkgDampg_Ip_DampgCmdPwrPrkgEna;
extern VAR(float32, AUTOMATIC) BmwPwrPrkgDampg_Ip_HwVel;
extern VAR(float32, AUTOMATIC) BmwPwrPrkgDampg_Ip_PinionAg;
extern VAR(float32, AUTOMATIC) BmwPwrPrkgDampg_Ip_PinionAgConf;
extern VAR(float32, AUTOMATIC) BmwPwrPrkgDampg_Ip_VehSpd;

/* Outputs */
extern VAR(float32, AUTOMATIC) BmwPwrPrkgDampg_Op_DampgCmdPwrPrkg;

/* Calibrations */
extern CONST(u5p11, AUTOMATIC) BmwPwrPrkgDampg_Cal_BmwPwrPrkgDampgBasPwrPrkgDampgY[9][9];
extern CONST(boolean, AUTOMATIC) BmwPwrPrkgDampg_Cal_BmwPwrPrkgDampgDiScadDampg;
extern CONST(u6p10, AUTOMATIC) BmwPwrPrkgDampg_Cal_BmwPwrPrkgDampgHwVelTblX[9];
extern CONST(float32, AUTOMATIC) BmwPwrPrkgDampg_Cal_BmwPwrPrkgDampgMaxRate;
extern CONST(float32, AUTOMATIC) BmwPwrPrkgDampg_Cal_BmwPwrPrkgDampgMinPinionAgConf;
extern CONST(u12p4, AUTOMATIC) BmwPwrPrkgDampg_Cal_BmwPwrPrkgDampgPinionAgSelnTbl[9];
extern CONST(u9p7, AUTOMATIC) BmwPwrPrkgDampg_Cal_BmwPwrPrkgDampgVehSpdLnrSelnX[11];
extern CONST(u1p15, AUTOMATIC) BmwPwrPrkgDampg_Cal_BmwPwrPrkgDampgVehSpdScaFacY[11];

/* PIMs */
extern VAR(float32, AUTOMATIC) BmwPwrPrkgDampg_Pim_DampgCmdPwrPrkgStVari;

/* Arguments and Returns */


/*** Input Stubs ***/

#ifdef Rte_Read_DampgCmdBas_Val
# undef Rte_Read_DampgCmdBas_Val
#else
#error Rte_Read_DampgCmdBas_Val is missing
#endif
#define Rte_Read_DampgCmdBas_Val(data) (*(data) = BmwPwrPrkgDampg_Ip_DampgCmdBas)

#ifdef Rte_Read_DampgCmdPwrPrkgEna_Logl
# undef Rte_Read_DampgCmdPwrPrkgEna_Logl
#else
#error Rte_Read_DampgCmdPwrPrkgEna_Logl is missing
#endif
#define Rte_Read_DampgCmdPwrPrkgEna_Logl(data) (*(data) = BmwPwrPrkgDampg_Ip_DampgCmdPwrPrkgEna)

#ifdef Rte_Read_HwVel_Val
# undef Rte_Read_HwVel_Val
#else
#error Rte_Read_HwVel_Val is missing
#endif
#define Rte_Read_HwVel_Val(data) (*(data) = BmwPwrPrkgDampg_Ip_HwVel)

#ifdef Rte_Read_PinionAg_Val
# undef Rte_Read_PinionAg_Val
#else
#error Rte_Read_PinionAg_Val is missing
#endif
#define Rte_Read_PinionAg_Val(data) (*(data) = BmwPwrPrkgDampg_Ip_PinionAg)

#ifdef Rte_Read_PinionAgConf_Val
# undef Rte_Read_PinionAgConf_Val
#else
#error Rte_Read_PinionAgConf_Val is missing
#endif
#define Rte_Read_PinionAgConf_Val(data) (*(data) = BmwPwrPrkgDampg_Ip_PinionAgConf)

#ifdef Rte_Read_VehSpd_Val
# undef Rte_Read_VehSpd_Val
#else
#error Rte_Read_VehSpd_Val is missing
#endif
#define Rte_Read_VehSpd_Val(data) (*(data) = BmwPwrPrkgDampg_Ip_VehSpd)


/*** Output Stubs ***/

#ifdef Rte_Write_DampgCmdPwrPrkg_Val
# undef Rte_Write_DampgCmdPwrPrkg_Val
#else
#error Rte_Write_DampgCmdPwrPrkg_Val is missing
#endif
#define Rte_Write_DampgCmdPwrPrkg_Val(data) (BmwPwrPrkgDampg_Op_DampgCmdPwrPrkg = (data))


/*** Calibration Stubs ***/

#ifdef Rte_Prm_BmwPwrPrkgDampgBasPwrPrkgDampgY_Ary2D
# undef Rte_Prm_BmwPwrPrkgDampgBasPwrPrkgDampgY_Ary2D
#else
#error Rte_Prm_BmwPwrPrkgDampgBasPwrPrkgDampgY_Ary2D is missing
#endif
#define Rte_Prm_BmwPwrPrkgDampgBasPwrPrkgDampgY_Ary2D() (&(BmwPwrPrkgDampg_Cal_BmwPwrPrkgDampgBasPwrPrkgDampgY[0][0]))

#ifdef Rte_Prm_BmwPwrPrkgDampgDiScadDampg_Logl
# undef Rte_Prm_BmwPwrPrkgDampgDiScadDampg_Logl
#else
#error Rte_Prm_BmwPwrPrkgDampgDiScadDampg_Logl is missing
#endif
#define Rte_Prm_BmwPwrPrkgDampgDiScadDampg_Logl() (BmwPwrPrkgDampg_Cal_BmwPwrPrkgDampgDiScadDampg)

#ifdef Rte_Prm_BmwPwrPrkgDampgHwVelTblX_Ary1D
# undef Rte_Prm_BmwPwrPrkgDampgHwVelTblX_Ary1D
#else
#error Rte_Prm_BmwPwrPrkgDampgHwVelTblX_Ary1D is missing
#endif
#define Rte_Prm_BmwPwrPrkgDampgHwVelTblX_Ary1D() (&(BmwPwrPrkgDampg_Cal_BmwPwrPrkgDampgHwVelTblX[0]))

#ifdef Rte_Prm_BmwPwrPrkgDampgMaxRate_Val
# undef Rte_Prm_BmwPwrPrkgDampgMaxRate_Val
#else
#error Rte_Prm_BmwPwrPrkgDampgMaxRate_Val is missing
#endif
#define Rte_Prm_BmwPwrPrkgDampgMaxRate_Val() (BmwPwrPrkgDampg_Cal_BmwPwrPrkgDampgMaxRate)

#ifdef Rte_Prm_BmwPwrPrkgDampgMinPinionAgConf_Val
# undef Rte_Prm_BmwPwrPrkgDampgMinPinionAgConf_Val
#else
#error Rte_Prm_BmwPwrPrkgDampgMinPinionAgConf_Val is missing
#endif
#define Rte_Prm_BmwPwrPrkgDampgMinPinionAgConf_Val() (BmwPwrPrkgDampg_Cal_BmwPwrPrkgDampgMinPinionAgConf)

#ifdef Rte_Prm_BmwPwrPrkgDampgPinionAgSelnTbl_Ary1D
# undef Rte_Prm_BmwPwrPrkgDampgPinionAgSelnTbl_Ary1D
#else
#error Rte_Prm_BmwPwrPrkgDampgPinionAgSelnTbl_Ary1D is missing
#endif
#define Rte_Prm_BmwPwrPrkgDampgPinionAgSelnTbl_Ary1D() (&(BmwPwrPrkgDampg_Cal_BmwPwrPrkgDampgPinionAgSelnTbl[0]))

#ifdef Rte_Prm_BmwPwrPrkgDampgVehSpdLnrSelnX_Ary1D
# undef Rte_Prm_BmwPwrPrkgDampgVehSpdLnrSelnX_Ary1D
#else
#error Rte_Prm_BmwPwrPrkgDampgVehSpdLnrSelnX_Ary1D is missing
#endif
#define Rte_Prm_BmwPwrPrkgDampgVehSpdLnrSelnX_Ary1D() (&(BmwPwrPrkgDampg_Cal_BmwPwrPrkgDampgVehSpdLnrSelnX[0]))

#ifdef Rte_Prm_BmwPwrPrkgDampgVehSpdScaFacY_Ary1D
# undef Rte_Prm_BmwPwrPrkgDampgVehSpdScaFacY_Ary1D
#else
#error Rte_Prm_BmwPwrPrkgDampgVehSpdScaFacY_Ary1D is missing
#endif
#define Rte_Prm_BmwPwrPrkgDampgVehSpdScaFacY_Ary1D() (&(BmwPwrPrkgDampg_Cal_BmwPwrPrkgDampgVehSpdScaFacY[0]))


/*** PIM Stubs ***/

#ifdef Rte_Pim_DampgCmdPwrPrkgStVari
# undef Rte_Pim_DampgCmdPwrPrkgStVari
#else
#error Rte_Pim_DampgCmdPwrPrkgStVari is missing
#endif
#define Rte_Pim_DampgCmdPwrPrkgStVari() (&BmwPwrPrkgDampg_Pim_DampgCmdPwrPrkgStVari)


/*** Client Stub ***/

extern FUNC(void, AUTOMATIC) Rte_Stub(void);


#endif
