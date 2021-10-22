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
extern VAR(boolean, AUTOMATIC) BmwHwTqOvrlArbn_Ip_BmwDrvgDynErrIfActv;
extern VAR(float32, AUTOMATIC) BmwHwTqOvrlArbn_Ip_BmwTarHwTqOvrl;
extern VAR(BmwOvrlCmdQlfr1, AUTOMATIC) BmwHwTqOvrlArbn_Ip_BmwTarHwTqOvrlQlfr;
extern VAR(DrvgDynIfSt1, AUTOMATIC) BmwHwTqOvrlArbn_Ip_DrvgDynIfSt;
extern VAR(boolean, AUTOMATIC) BmwHwTqOvrlArbn_Ip_HwTqOvrlCmdEna;
extern VAR(float32, AUTOMATIC) BmwHwTqOvrlArbn_Ip_VehSpd;

/* Outputs */
extern VAR(float32, AUTOMATIC) BmwHwTqOvrlArbn_Op_HwTqCmdOvrl;

/* Calibrations */
extern CONST(float32, AUTOMATIC) BmwHwTqOvrlArbn_Cal_BmwHwTqOvrlArbnCmdErrThd;
extern CONST(u4p12, AUTOMATIC) BmwHwTqOvrlArbn_Cal_BmwHwTqOvrlArbnHwTqThdY[6];
extern CONST(float32, AUTOMATIC) BmwHwTqOvrlArbn_Cal_BmwHwTqOvrlArbnOutpTqCmdLim;
extern CONST(float32, AUTOMATIC) BmwHwTqOvrlArbn_Cal_BmwHwTqOvrlArbnRampRate;
extern CONST(uint16, AUTOMATIC) BmwHwTqOvrlArbn_Cal_BmwHwTqOvrlArbnRefTiThd;
extern CONST(u9p7, AUTOMATIC) BmwHwTqOvrlArbn_Cal_BmwHwTqOvrlArbnVehSpdX[6];

/* PIMs */
extern VAR(float32, AUTOMATIC) BmwHwTqOvrlArbn_Pim_ArbdHwTqOvrlLtch;
extern VAR(boolean, AUTOMATIC) BmwHwTqOvrlArbn_Pim_FctlErrActv;
extern VAR(uint32, AUTOMATIC) BmwHwTqOvrlArbn_Pim_FctlErrTmr;
extern VAR(float32, AUTOMATIC) BmwHwTqOvrlArbn_Pim_HwTqOvrlScaFacStVari;
extern VAR(float32, AUTOMATIC) BmwHwTqOvrlArbn_Pim_PrevArbdHwTqOvrl;
extern VAR(boolean, AUTOMATIC) BmwHwTqOvrlArbn_Pim_PrevFctlErr;

/* Arguments and Returns */
extern VAR(uint32, AUTOMATIC) BmwHwTqOvrlArbn_Srv_GetRefTmr100MicroSec32bit_RefTmr;
extern VAR(uint32, AUTOMATIC) BmwHwTqOvrlArbn_Srv_GetTiSpan100MicroSec32bit_RefTmr;
extern VAR(uint32, AUTOMATIC) BmwHwTqOvrlArbn_Srv_GetTiSpan100MicroSec32bit_TiSpan;


/*** Input Stubs ***/

#ifdef Rte_Read_BmwDrvgDynErrIfActv_Logl
# undef Rte_Read_BmwDrvgDynErrIfActv_Logl
#else
#error Rte_Read_BmwDrvgDynErrIfActv_Logl is missing
#endif
#define Rte_Read_BmwDrvgDynErrIfActv_Logl(data) (*(data) = BmwHwTqOvrlArbn_Ip_BmwDrvgDynErrIfActv)

#ifdef Rte_Read_BmwTarHwTqOvrl_Val
# undef Rte_Read_BmwTarHwTqOvrl_Val
#else
#error Rte_Read_BmwTarHwTqOvrl_Val is missing
#endif
#define Rte_Read_BmwTarHwTqOvrl_Val(data) (*(data) = BmwHwTqOvrlArbn_Ip_BmwTarHwTqOvrl)

#ifdef Rte_Read_BmwTarHwTqOvrlQlfr_Val
# undef Rte_Read_BmwTarHwTqOvrlQlfr_Val
#else
#error Rte_Read_BmwTarHwTqOvrlQlfr_Val is missing
#endif
#define Rte_Read_BmwTarHwTqOvrlQlfr_Val(data) (*(data) = BmwHwTqOvrlArbn_Ip_BmwTarHwTqOvrlQlfr)

#ifdef Rte_Read_DrvgDynIfSt_Val
# undef Rte_Read_DrvgDynIfSt_Val
#else
#error Rte_Read_DrvgDynIfSt_Val is missing
#endif
#define Rte_Read_DrvgDynIfSt_Val(data) (*(data) = BmwHwTqOvrlArbn_Ip_DrvgDynIfSt)

#ifdef Rte_Read_HwTqOvrlCmdEna_Logl
# undef Rte_Read_HwTqOvrlCmdEna_Logl
#else
#error Rte_Read_HwTqOvrlCmdEna_Logl is missing
#endif
#define Rte_Read_HwTqOvrlCmdEna_Logl(data) (*(data) = BmwHwTqOvrlArbn_Ip_HwTqOvrlCmdEna)

#ifdef Rte_Read_VehSpd_Val
# undef Rte_Read_VehSpd_Val
#else
#error Rte_Read_VehSpd_Val is missing
#endif
#define Rte_Read_VehSpd_Val(data) (*(data) = BmwHwTqOvrlArbn_Ip_VehSpd)


/*** Output Stubs ***/

#ifdef Rte_Write_HwTqCmdOvrl_Val
# undef Rte_Write_HwTqCmdOvrl_Val
#else
#error Rte_Write_HwTqCmdOvrl_Val is missing
#endif
#define Rte_Write_HwTqCmdOvrl_Val(data) (BmwHwTqOvrlArbn_Op_HwTqCmdOvrl = (data))


/*** Calibration Stubs ***/

#ifdef Rte_Prm_BmwHwTqOvrlArbnCmdErrThd_Val
# undef Rte_Prm_BmwHwTqOvrlArbnCmdErrThd_Val
#else
#error Rte_Prm_BmwHwTqOvrlArbnCmdErrThd_Val is missing
#endif
#define Rte_Prm_BmwHwTqOvrlArbnCmdErrThd_Val() (BmwHwTqOvrlArbn_Cal_BmwHwTqOvrlArbnCmdErrThd)

#ifdef Rte_Prm_BmwHwTqOvrlArbnHwTqThdY_Ary1D
# undef Rte_Prm_BmwHwTqOvrlArbnHwTqThdY_Ary1D
#else
#error Rte_Prm_BmwHwTqOvrlArbnHwTqThdY_Ary1D is missing
#endif
#define Rte_Prm_BmwHwTqOvrlArbnHwTqThdY_Ary1D() (&(BmwHwTqOvrlArbn_Cal_BmwHwTqOvrlArbnHwTqThdY[0]))

#ifdef Rte_Prm_BmwHwTqOvrlArbnOutpTqCmdLim_Val
# undef Rte_Prm_BmwHwTqOvrlArbnOutpTqCmdLim_Val
#else
#error Rte_Prm_BmwHwTqOvrlArbnOutpTqCmdLim_Val is missing
#endif
#define Rte_Prm_BmwHwTqOvrlArbnOutpTqCmdLim_Val() (BmwHwTqOvrlArbn_Cal_BmwHwTqOvrlArbnOutpTqCmdLim)

#ifdef Rte_Prm_BmwHwTqOvrlArbnRampRate_Val
# undef Rte_Prm_BmwHwTqOvrlArbnRampRate_Val
#else
#error Rte_Prm_BmwHwTqOvrlArbnRampRate_Val is missing
#endif
#define Rte_Prm_BmwHwTqOvrlArbnRampRate_Val() (BmwHwTqOvrlArbn_Cal_BmwHwTqOvrlArbnRampRate)

#ifdef Rte_Prm_BmwHwTqOvrlArbnRefTiThd_Val
# undef Rte_Prm_BmwHwTqOvrlArbnRefTiThd_Val
#else
#error Rte_Prm_BmwHwTqOvrlArbnRefTiThd_Val is missing
#endif
#define Rte_Prm_BmwHwTqOvrlArbnRefTiThd_Val() (BmwHwTqOvrlArbn_Cal_BmwHwTqOvrlArbnRefTiThd)

#ifdef Rte_Prm_BmwHwTqOvrlArbnVehSpdX_Ary1D
# undef Rte_Prm_BmwHwTqOvrlArbnVehSpdX_Ary1D
#else
#error Rte_Prm_BmwHwTqOvrlArbnVehSpdX_Ary1D is missing
#endif
#define Rte_Prm_BmwHwTqOvrlArbnVehSpdX_Ary1D() (&(BmwHwTqOvrlArbn_Cal_BmwHwTqOvrlArbnVehSpdX[0]))


/*** PIM Stubs ***/

#ifdef Rte_Pim_ArbdHwTqOvrlLtch
# undef Rte_Pim_ArbdHwTqOvrlLtch
#else
#error Rte_Pim_ArbdHwTqOvrlLtch is missing
#endif
#define Rte_Pim_ArbdHwTqOvrlLtch() (&BmwHwTqOvrlArbn_Pim_ArbdHwTqOvrlLtch)

#ifdef Rte_Pim_FctlErrActv
# undef Rte_Pim_FctlErrActv
#else
#error Rte_Pim_FctlErrActv is missing
#endif
#define Rte_Pim_FctlErrActv() (&BmwHwTqOvrlArbn_Pim_FctlErrActv)

#ifdef Rte_Pim_FctlErrTmr
# undef Rte_Pim_FctlErrTmr
#else
#error Rte_Pim_FctlErrTmr is missing
#endif
#define Rte_Pim_FctlErrTmr() (&BmwHwTqOvrlArbn_Pim_FctlErrTmr)

#ifdef Rte_Pim_HwTqOvrlScaFacStVari
# undef Rte_Pim_HwTqOvrlScaFacStVari
#else
#error Rte_Pim_HwTqOvrlScaFacStVari is missing
#endif
#define Rte_Pim_HwTqOvrlScaFacStVari() (&BmwHwTqOvrlArbn_Pim_HwTqOvrlScaFacStVari)

#ifdef Rte_Pim_PrevArbdHwTqOvrl
# undef Rte_Pim_PrevArbdHwTqOvrl
#else
#error Rte_Pim_PrevArbdHwTqOvrl is missing
#endif
#define Rte_Pim_PrevArbdHwTqOvrl() (&BmwHwTqOvrlArbn_Pim_PrevArbdHwTqOvrl)

#ifdef Rte_Pim_PrevFctlErr
# undef Rte_Pim_PrevFctlErr
#else
#error Rte_Pim_PrevFctlErr is missing
#endif
#define Rte_Pim_PrevFctlErr() (&BmwHwTqOvrlArbn_Pim_PrevFctlErr)


/*** Client Stub ***/

extern FUNC(void, AUTOMATIC) Rte_Stub(void);


#endif
