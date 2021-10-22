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
extern VAR(float32, AUTOMATIC) BmwTqOvrlCdngAndDrvgDynFac_Ip_BmwDrvgDynDampgFacReq;
extern VAR(float32, AUTOMATIC) BmwTqOvrlCdngAndDrvgDynFac_Ip_BmwDrvgDynEffortFacReq;
extern VAR(boolean, AUTOMATIC) BmwTqOvrlCdngAndDrvgDynFac_Ip_BmwDrvgDynErrIfActv;
extern VAR(float32, AUTOMATIC) BmwTqOvrlCdngAndDrvgDynFac_Ip_BmwDrvgDynRtnFacReq;
extern VAR(boolean, AUTOMATIC) BmwTqOvrlCdngAndDrvgDynFac_Ip_BmwOutpTqOvrlCmdEna;
extern VAR(float32, AUTOMATIC) BmwTqOvrlCdngAndDrvgDynFac_Ip_BmwTarSteerTqDrvrActr;
extern VAR(boolean, AUTOMATIC) BmwTqOvrlCdngAndDrvgDynFac_Ip_DrvgDynActv;
extern VAR(boolean, AUTOMATIC) BmwTqOvrlCdngAndDrvgDynFac_Ip_DrvgDynFacEna;
extern VAR(DrvgDynIfSt1, AUTOMATIC) BmwTqOvrlCdngAndDrvgDynFac_Ip_DrvgDynIfSt;
extern VAR(float32, AUTOMATIC) BmwTqOvrlCdngAndDrvgDynFac_Ip_HwTq;
extern VAR(float32, AUTOMATIC) BmwTqOvrlCdngAndDrvgDynFac_Ip_MotVelCrf;
extern VAR(boolean, AUTOMATIC) BmwTqOvrlCdngAndDrvgDynFac_Ip_OutpTqOvrlRampInEna;
extern VAR(float32, AUTOMATIC) BmwTqOvrlCdngAndDrvgDynFac_Ip_VehSpd;

/* Outputs */
extern VAR(float32, AUTOMATIC) BmwTqOvrlCdngAndDrvgDynFac_Op_BmwOutpTqOvrlCmd;
extern VAR(float32, AUTOMATIC) BmwTqOvrlCdngAndDrvgDynFac_Op_DampgCmdSca;
extern VAR(float32, AUTOMATIC) BmwTqOvrlCdngAndDrvgDynFac_Op_EffortCmdSca;
extern VAR(float32, AUTOMATIC) BmwTqOvrlCdngAndDrvgDynFac_Op_RtnCmdSca;

/* Calibrations */
extern CONST(float32, AUTOMATIC) BmwTqOvrlCdngAndDrvgDynFac_Cal_BmwTqOvrlCdngAndDrvgDynFacActvDampgSlewRate;
extern CONST(float32, AUTOMATIC) BmwTqOvrlCdngAndDrvgDynFac_Cal_BmwTqOvrlCdngAndDrvgDynFacActvEffortSlewRate;
extern CONST(float32, AUTOMATIC) BmwTqOvrlCdngAndDrvgDynFac_Cal_BmwTqOvrlCdngAndDrvgDynFacActvRtnSlewRate;
extern CONST(u11p5, AUTOMATIC) BmwTqOvrlCdngAndDrvgDynFac_Cal_BmwTqOvrlCdngAndDrvgDynFacDampgScaLoLimX[12];
extern CONST(u1p15, AUTOMATIC) BmwTqOvrlCdngAndDrvgDynFac_Cal_BmwTqOvrlCdngAndDrvgDynFacDampgScaLoLimY[12][12];
extern CONST(u4p12, AUTOMATIC) BmwTqOvrlCdngAndDrvgDynFac_Cal_BmwTqOvrlCdngAndDrvgDynFacEffortScaHiLimX[12];
extern CONST(u2p14, AUTOMATIC) BmwTqOvrlCdngAndDrvgDynFac_Cal_BmwTqOvrlCdngAndDrvgDynFacEffortScaHiLimY[12][12];
extern CONST(float32, AUTOMATIC) BmwTqOvrlCdngAndDrvgDynFac_Cal_BmwTqOvrlCdngAndDrvgDynFacInactvDampgSlewRate;
extern CONST(float32, AUTOMATIC) BmwTqOvrlCdngAndDrvgDynFac_Cal_BmwTqOvrlCdngAndDrvgDynFacInactvEffortSlewRate;
extern CONST(float32, AUTOMATIC) BmwTqOvrlCdngAndDrvgDynFac_Cal_BmwTqOvrlCdngAndDrvgDynFacInactvRtnSlewRate;
extern CONST(float32, AUTOMATIC) BmwTqOvrlCdngAndDrvgDynFac_Cal_BmwTqOvrlCdngAndDrvgDynFacOutpTqOvrlSlew;
extern CONST(float32, AUTOMATIC) BmwTqOvrlCdngAndDrvgDynFac_Cal_BmwTqOvrlCdngAndDrvgDynFacReqdRtnCmdScaLoLim;
extern CONST(float32, AUTOMATIC) BmwTqOvrlCdngAndDrvgDynFac_Cal_BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrLpFilFrq;
extern CONST(u4p12, AUTOMATIC) BmwTqOvrlCdngAndDrvgDynFac_Cal_BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrMaxY[10];
extern CONST(u9p7, AUTOMATIC) BmwTqOvrlCdngAndDrvgDynFac_Cal_BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrSpdX[10];
extern CONST(u9p7, AUTOMATIC) BmwTqOvrlCdngAndDrvgDynFac_Cal_SysGlbPrmVehSpdBilnrSeln[12];

/* PIMs */
extern VAR(boolean, AUTOMATIC) BmwTqOvrlCdngAndDrvgDynFac_Pim_BmwOutpTqOvrlCmdRampCmpl;
extern VAR(float32, AUTOMATIC) BmwTqOvrlCdngAndDrvgDynFac_Pim_BmwOutpTqOvrlCmdStVari;
extern VAR(FilLpRec1, AUTOMATIC) BmwTqOvrlCdngAndDrvgDynFac_Pim_BmwTarSteerTqDrvrActrLpFilStVari;
extern VAR(float32, AUTOMATIC) BmwTqOvrlCdngAndDrvgDynFac_Pim_DampgCmdScaRateLimrStVari;
extern VAR(float32, AUTOMATIC) BmwTqOvrlCdngAndDrvgDynFac_Pim_EffortCmdScaRateLimrStVari;
extern VAR(float32, AUTOMATIC) BmwTqOvrlCdngAndDrvgDynFac_Pim_FrznBmwTarSteerTqDrvrActr;
extern VAR(boolean, AUTOMATIC) BmwTqOvrlCdngAndDrvgDynFac_Pim_FrznSigActv;
extern VAR(float32, AUTOMATIC) BmwTqOvrlCdngAndDrvgDynFac_Pim_LimdCdndTqOvrl;
extern VAR(uint32, AUTOMATIC) BmwTqOvrlCdngAndDrvgDynFac_Pim_MsgCycTmr;
extern VAR(boolean, AUTOMATIC) BmwTqOvrlCdngAndDrvgDynFac_Pim_PrevDampgSlewInProgs;
extern VAR(boolean, AUTOMATIC) BmwTqOvrlCdngAndDrvgDynFac_Pim_PrevDrvgDynActv;
extern VAR(DrvgDynIfSt1, AUTOMATIC) BmwTqOvrlCdngAndDrvgDynFac_Pim_PrevDrvgDynIfSt;
extern VAR(boolean, AUTOMATIC) BmwTqOvrlCdngAndDrvgDynFac_Pim_PrevEffortSlewInProgs;
extern VAR(boolean, AUTOMATIC) BmwTqOvrlCdngAndDrvgDynFac_Pim_PrevRtnSlewInProgs;
extern VAR(boolean, AUTOMATIC) BmwTqOvrlCdngAndDrvgDynFac_Pim_RampToZeroEnad;
extern VAR(float32, AUTOMATIC) BmwTqOvrlCdngAndDrvgDynFac_Pim_RtnCmdScaRateLimrStVari;

/* Arguments and Returns */
extern VAR(uint32, AUTOMATIC) BmwTqOvrlCdngAndDrvgDynFac_Srv_GetRefTmr100MicroSec32bit_RefTmr;
extern VAR(uint32, AUTOMATIC) BmwTqOvrlCdngAndDrvgDynFac_Srv_GetTiSpan100MicroSec32bit_RefTmr;
extern VAR(uint32, AUTOMATIC) BmwTqOvrlCdngAndDrvgDynFac_Srv_GetTiSpan100MicroSec32bit_TiSpan;


/*** Input Stubs ***/

#ifdef Rte_Read_BmwDrvgDynDampgFacReq_Val
# undef Rte_Read_BmwDrvgDynDampgFacReq_Val
#else
#error Rte_Read_BmwDrvgDynDampgFacReq_Val is missing
#endif
#define Rte_Read_BmwDrvgDynDampgFacReq_Val(data) (*(data) = BmwTqOvrlCdngAndDrvgDynFac_Ip_BmwDrvgDynDampgFacReq)

#ifdef Rte_Read_BmwDrvgDynEffortFacReq_Val
# undef Rte_Read_BmwDrvgDynEffortFacReq_Val
#else
#error Rte_Read_BmwDrvgDynEffortFacReq_Val is missing
#endif
#define Rte_Read_BmwDrvgDynEffortFacReq_Val(data) (*(data) = BmwTqOvrlCdngAndDrvgDynFac_Ip_BmwDrvgDynEffortFacReq)

#ifdef Rte_Read_BmwDrvgDynErrIfActv_Logl
# undef Rte_Read_BmwDrvgDynErrIfActv_Logl
#else
#error Rte_Read_BmwDrvgDynErrIfActv_Logl is missing
#endif
#define Rte_Read_BmwDrvgDynErrIfActv_Logl(data) (*(data) = BmwTqOvrlCdngAndDrvgDynFac_Ip_BmwDrvgDynErrIfActv)

#ifdef Rte_Read_BmwDrvgDynRtnFacReq_Val
# undef Rte_Read_BmwDrvgDynRtnFacReq_Val
#else
#error Rte_Read_BmwDrvgDynRtnFacReq_Val is missing
#endif
#define Rte_Read_BmwDrvgDynRtnFacReq_Val(data) (*(data) = BmwTqOvrlCdngAndDrvgDynFac_Ip_BmwDrvgDynRtnFacReq)

#ifdef Rte_Read_BmwOutpTqOvrlCmdEna_Logl
# undef Rte_Read_BmwOutpTqOvrlCmdEna_Logl
#else
#error Rte_Read_BmwOutpTqOvrlCmdEna_Logl is missing
#endif
#define Rte_Read_BmwOutpTqOvrlCmdEna_Logl(data) (*(data) = BmwTqOvrlCdngAndDrvgDynFac_Ip_BmwOutpTqOvrlCmdEna)

#ifdef Rte_Read_BmwTarSteerTqDrvrActr_Val
# undef Rte_Read_BmwTarSteerTqDrvrActr_Val
#else
#error Rte_Read_BmwTarSteerTqDrvrActr_Val is missing
#endif
#define Rte_Read_BmwTarSteerTqDrvrActr_Val(data) (*(data) = BmwTqOvrlCdngAndDrvgDynFac_Ip_BmwTarSteerTqDrvrActr)

#ifdef Rte_Read_DrvgDynActv_Logl
# undef Rte_Read_DrvgDynActv_Logl
#else
#error Rte_Read_DrvgDynActv_Logl is missing
#endif
#define Rte_Read_DrvgDynActv_Logl(data) (*(data) = BmwTqOvrlCdngAndDrvgDynFac_Ip_DrvgDynActv)

#ifdef Rte_Read_DrvgDynFacEna_Logl
# undef Rte_Read_DrvgDynFacEna_Logl
#else
#error Rte_Read_DrvgDynFacEna_Logl is missing
#endif
#define Rte_Read_DrvgDynFacEna_Logl(data) (*(data) = BmwTqOvrlCdngAndDrvgDynFac_Ip_DrvgDynFacEna)

#ifdef Rte_Read_DrvgDynIfSt_Val
# undef Rte_Read_DrvgDynIfSt_Val
#else
#error Rte_Read_DrvgDynIfSt_Val is missing
#endif
#define Rte_Read_DrvgDynIfSt_Val(data) (*(data) = BmwTqOvrlCdngAndDrvgDynFac_Ip_DrvgDynIfSt)

#ifdef Rte_Read_HwTq_Val
# undef Rte_Read_HwTq_Val
#else
#error Rte_Read_HwTq_Val is missing
#endif
#define Rte_Read_HwTq_Val(data) (*(data) = BmwTqOvrlCdngAndDrvgDynFac_Ip_HwTq)

#ifdef Rte_Read_MotVelCrf_Val
# undef Rte_Read_MotVelCrf_Val
#else
#error Rte_Read_MotVelCrf_Val is missing
#endif
#define Rte_Read_MotVelCrf_Val(data) (*(data) = BmwTqOvrlCdngAndDrvgDynFac_Ip_MotVelCrf)

#ifdef Rte_Read_OutpTqOvrlRampInEna_Logl
# undef Rte_Read_OutpTqOvrlRampInEna_Logl
#else
#error Rte_Read_OutpTqOvrlRampInEna_Logl is missing
#endif
#define Rte_Read_OutpTqOvrlRampInEna_Logl(data) (*(data) = BmwTqOvrlCdngAndDrvgDynFac_Ip_OutpTqOvrlRampInEna)

#ifdef Rte_Read_VehSpd_Val
# undef Rte_Read_VehSpd_Val
#else
#error Rte_Read_VehSpd_Val is missing
#endif
#define Rte_Read_VehSpd_Val(data) (*(data) = BmwTqOvrlCdngAndDrvgDynFac_Ip_VehSpd)


/*** Output Stubs ***/

#ifdef Rte_Write_BmwOutpTqOvrlCmd_Val
# undef Rte_Write_BmwOutpTqOvrlCmd_Val
#else
#error Rte_Write_BmwOutpTqOvrlCmd_Val is missing
#endif
#define Rte_Write_BmwOutpTqOvrlCmd_Val(data) (BmwTqOvrlCdngAndDrvgDynFac_Op_BmwOutpTqOvrlCmd = (data))

#ifdef Rte_Write_DampgCmdSca_Val
# undef Rte_Write_DampgCmdSca_Val
#else
#error Rte_Write_DampgCmdSca_Val is missing
#endif
#define Rte_Write_DampgCmdSca_Val(data) (BmwTqOvrlCdngAndDrvgDynFac_Op_DampgCmdSca = (data))

#ifdef Rte_Write_EffortCmdSca_Val
# undef Rte_Write_EffortCmdSca_Val
#else
#error Rte_Write_EffortCmdSca_Val is missing
#endif
#define Rte_Write_EffortCmdSca_Val(data) (BmwTqOvrlCdngAndDrvgDynFac_Op_EffortCmdSca = (data))

#ifdef Rte_Write_RtnCmdSca_Val
# undef Rte_Write_RtnCmdSca_Val
#else
#error Rte_Write_RtnCmdSca_Val is missing
#endif
#define Rte_Write_RtnCmdSca_Val(data) (BmwTqOvrlCdngAndDrvgDynFac_Op_RtnCmdSca = (data))


/*** Calibration Stubs ***/

#ifdef Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacActvDampgSlewRate_Val
# undef Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacActvDampgSlewRate_Val
#else
#error Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacActvDampgSlewRate_Val is missing
#endif
#define Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacActvDampgSlewRate_Val() (BmwTqOvrlCdngAndDrvgDynFac_Cal_BmwTqOvrlCdngAndDrvgDynFacActvDampgSlewRate)

#ifdef Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacActvEffortSlewRate_Val
# undef Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacActvEffortSlewRate_Val
#else
#error Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacActvEffortSlewRate_Val is missing
#endif
#define Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacActvEffortSlewRate_Val() (BmwTqOvrlCdngAndDrvgDynFac_Cal_BmwTqOvrlCdngAndDrvgDynFacActvEffortSlewRate)

#ifdef Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacActvRtnSlewRate_Val
# undef Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacActvRtnSlewRate_Val
#else
#error Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacActvRtnSlewRate_Val is missing
#endif
#define Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacActvRtnSlewRate_Val() (BmwTqOvrlCdngAndDrvgDynFac_Cal_BmwTqOvrlCdngAndDrvgDynFacActvRtnSlewRate)

#ifdef Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacDampgScaLoLimX_Ary1D
# undef Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacDampgScaLoLimX_Ary1D
#else
#error Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacDampgScaLoLimX_Ary1D is missing
#endif
#define Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacDampgScaLoLimX_Ary1D() (&(BmwTqOvrlCdngAndDrvgDynFac_Cal_BmwTqOvrlCdngAndDrvgDynFacDampgScaLoLimX[0]))

#ifdef Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacDampgScaLoLimY_Ary2D
# undef Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacDampgScaLoLimY_Ary2D
#else
#error Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacDampgScaLoLimY_Ary2D is missing
#endif
#define Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacDampgScaLoLimY_Ary2D() (&(BmwTqOvrlCdngAndDrvgDynFac_Cal_BmwTqOvrlCdngAndDrvgDynFacDampgScaLoLimY[0][0]))

#ifdef Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacEffortScaHiLimX_Ary1D
# undef Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacEffortScaHiLimX_Ary1D
#else
#error Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacEffortScaHiLimX_Ary1D is missing
#endif
#define Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacEffortScaHiLimX_Ary1D() (&(BmwTqOvrlCdngAndDrvgDynFac_Cal_BmwTqOvrlCdngAndDrvgDynFacEffortScaHiLimX[0]))

#ifdef Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacEffortScaHiLimY_Ary2D
# undef Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacEffortScaHiLimY_Ary2D
#else
#error Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacEffortScaHiLimY_Ary2D is missing
#endif
#define Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacEffortScaHiLimY_Ary2D() (&(BmwTqOvrlCdngAndDrvgDynFac_Cal_BmwTqOvrlCdngAndDrvgDynFacEffortScaHiLimY[0][0]))

#ifdef Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacInactvDampgSlewRate_Val
# undef Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacInactvDampgSlewRate_Val
#else
#error Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacInactvDampgSlewRate_Val is missing
#endif
#define Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacInactvDampgSlewRate_Val() (BmwTqOvrlCdngAndDrvgDynFac_Cal_BmwTqOvrlCdngAndDrvgDynFacInactvDampgSlewRate)

#ifdef Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacInactvEffortSlewRate_Val
# undef Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacInactvEffortSlewRate_Val
#else
#error Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacInactvEffortSlewRate_Val is missing
#endif
#define Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacInactvEffortSlewRate_Val() (BmwTqOvrlCdngAndDrvgDynFac_Cal_BmwTqOvrlCdngAndDrvgDynFacInactvEffortSlewRate)

#ifdef Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacInactvRtnSlewRate_Val
# undef Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacInactvRtnSlewRate_Val
#else
#error Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacInactvRtnSlewRate_Val is missing
#endif
#define Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacInactvRtnSlewRate_Val() (BmwTqOvrlCdngAndDrvgDynFac_Cal_BmwTqOvrlCdngAndDrvgDynFacInactvRtnSlewRate)

#ifdef Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacOutpTqOvrlSlew_Val
# undef Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacOutpTqOvrlSlew_Val
#else
#error Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacOutpTqOvrlSlew_Val is missing
#endif
#define Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacOutpTqOvrlSlew_Val() (BmwTqOvrlCdngAndDrvgDynFac_Cal_BmwTqOvrlCdngAndDrvgDynFacOutpTqOvrlSlew)

#ifdef Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacReqdRtnCmdScaLoLim_Val
# undef Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacReqdRtnCmdScaLoLim_Val
#else
#error Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacReqdRtnCmdScaLoLim_Val is missing
#endif
#define Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacReqdRtnCmdScaLoLim_Val() (BmwTqOvrlCdngAndDrvgDynFac_Cal_BmwTqOvrlCdngAndDrvgDynFacReqdRtnCmdScaLoLim)

#ifdef Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrLpFilFrq_Val
# undef Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrLpFilFrq_Val
#else
#error Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrLpFilFrq_Val is missing
#endif
#define Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrLpFilFrq_Val() (BmwTqOvrlCdngAndDrvgDynFac_Cal_BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrLpFilFrq)

#ifdef Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrMaxY_Ary1D
# undef Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrMaxY_Ary1D
#else
#error Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrMaxY_Ary1D is missing
#endif
#define Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrMaxY_Ary1D() (&(BmwTqOvrlCdngAndDrvgDynFac_Cal_BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrMaxY[0]))

#ifdef Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrSpdX_Ary1D
# undef Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrSpdX_Ary1D
#else
#error Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrSpdX_Ary1D is missing
#endif
#define Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrSpdX_Ary1D() (&(BmwTqOvrlCdngAndDrvgDynFac_Cal_BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrSpdX[0]))

#ifdef Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D
# undef Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D
#else
#error Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D is missing
#endif
#define Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D() (&(BmwTqOvrlCdngAndDrvgDynFac_Cal_SysGlbPrmVehSpdBilnrSeln[0]))


/*** PIM Stubs ***/

#ifdef Rte_Pim_BmwOutpTqOvrlCmdRampCmpl
# undef Rte_Pim_BmwOutpTqOvrlCmdRampCmpl
#else
#error Rte_Pim_BmwOutpTqOvrlCmdRampCmpl is missing
#endif
#define Rte_Pim_BmwOutpTqOvrlCmdRampCmpl() (&BmwTqOvrlCdngAndDrvgDynFac_Pim_BmwOutpTqOvrlCmdRampCmpl)

#ifdef Rte_Pim_BmwOutpTqOvrlCmdStVari
# undef Rte_Pim_BmwOutpTqOvrlCmdStVari
#else
#error Rte_Pim_BmwOutpTqOvrlCmdStVari is missing
#endif
#define Rte_Pim_BmwOutpTqOvrlCmdStVari() (&BmwTqOvrlCdngAndDrvgDynFac_Pim_BmwOutpTqOvrlCmdStVari)

#ifdef Rte_Pim_BmwTarSteerTqDrvrActrLpFilStVari
# undef Rte_Pim_BmwTarSteerTqDrvrActrLpFilStVari
#else
#error Rte_Pim_BmwTarSteerTqDrvrActrLpFilStVari is missing
#endif
#define Rte_Pim_BmwTarSteerTqDrvrActrLpFilStVari() (&BmwTqOvrlCdngAndDrvgDynFac_Pim_BmwTarSteerTqDrvrActrLpFilStVari)

#ifdef Rte_Pim_DampgCmdScaRateLimrStVari
# undef Rte_Pim_DampgCmdScaRateLimrStVari
#else
#error Rte_Pim_DampgCmdScaRateLimrStVari is missing
#endif
#define Rte_Pim_DampgCmdScaRateLimrStVari() (&BmwTqOvrlCdngAndDrvgDynFac_Pim_DampgCmdScaRateLimrStVari)

#ifdef Rte_Pim_EffortCmdScaRateLimrStVari
# undef Rte_Pim_EffortCmdScaRateLimrStVari
#else
#error Rte_Pim_EffortCmdScaRateLimrStVari is missing
#endif
#define Rte_Pim_EffortCmdScaRateLimrStVari() (&BmwTqOvrlCdngAndDrvgDynFac_Pim_EffortCmdScaRateLimrStVari)

#ifdef Rte_Pim_FrznBmwTarSteerTqDrvrActr
# undef Rte_Pim_FrznBmwTarSteerTqDrvrActr
#else
#error Rte_Pim_FrznBmwTarSteerTqDrvrActr is missing
#endif
#define Rte_Pim_FrznBmwTarSteerTqDrvrActr() (&BmwTqOvrlCdngAndDrvgDynFac_Pim_FrznBmwTarSteerTqDrvrActr)

#ifdef Rte_Pim_FrznSigActv
# undef Rte_Pim_FrznSigActv
#else
#error Rte_Pim_FrznSigActv is missing
#endif
#define Rte_Pim_FrznSigActv() (&BmwTqOvrlCdngAndDrvgDynFac_Pim_FrznSigActv)

#ifdef Rte_Pim_LimdCdndTqOvrl
# undef Rte_Pim_LimdCdndTqOvrl
#else
#error Rte_Pim_LimdCdndTqOvrl is missing
#endif
#define Rte_Pim_LimdCdndTqOvrl() (&BmwTqOvrlCdngAndDrvgDynFac_Pim_LimdCdndTqOvrl)

#ifdef Rte_Pim_MsgCycTmr
# undef Rte_Pim_MsgCycTmr
#else
#error Rte_Pim_MsgCycTmr is missing
#endif
#define Rte_Pim_MsgCycTmr() (&BmwTqOvrlCdngAndDrvgDynFac_Pim_MsgCycTmr)

#ifdef Rte_Pim_PrevDampgSlewInProgs
# undef Rte_Pim_PrevDampgSlewInProgs
#else
#error Rte_Pim_PrevDampgSlewInProgs is missing
#endif
#define Rte_Pim_PrevDampgSlewInProgs() (&BmwTqOvrlCdngAndDrvgDynFac_Pim_PrevDampgSlewInProgs)

#ifdef Rte_Pim_PrevDrvgDynActv
# undef Rte_Pim_PrevDrvgDynActv
#else
#error Rte_Pim_PrevDrvgDynActv is missing
#endif
#define Rte_Pim_PrevDrvgDynActv() (&BmwTqOvrlCdngAndDrvgDynFac_Pim_PrevDrvgDynActv)

#ifdef Rte_Pim_PrevDrvgDynIfSt
# undef Rte_Pim_PrevDrvgDynIfSt
#else
#error Rte_Pim_PrevDrvgDynIfSt is missing
#endif
#define Rte_Pim_PrevDrvgDynIfSt() (&BmwTqOvrlCdngAndDrvgDynFac_Pim_PrevDrvgDynIfSt)

#ifdef Rte_Pim_PrevEffortSlewInProgs
# undef Rte_Pim_PrevEffortSlewInProgs
#else
#error Rte_Pim_PrevEffortSlewInProgs is missing
#endif
#define Rte_Pim_PrevEffortSlewInProgs() (&BmwTqOvrlCdngAndDrvgDynFac_Pim_PrevEffortSlewInProgs)

#ifdef Rte_Pim_PrevRtnSlewInProgs
# undef Rte_Pim_PrevRtnSlewInProgs
#else
#error Rte_Pim_PrevRtnSlewInProgs is missing
#endif
#define Rte_Pim_PrevRtnSlewInProgs() (&BmwTqOvrlCdngAndDrvgDynFac_Pim_PrevRtnSlewInProgs)

#ifdef Rte_Pim_RampToZeroEnad
# undef Rte_Pim_RampToZeroEnad
#else
#error Rte_Pim_RampToZeroEnad is missing
#endif
#define Rte_Pim_RampToZeroEnad() (&BmwTqOvrlCdngAndDrvgDynFac_Pim_RampToZeroEnad)

#ifdef Rte_Pim_RtnCmdScaRateLimrStVari
# undef Rte_Pim_RtnCmdScaRateLimrStVari
#else
#error Rte_Pim_RtnCmdScaRateLimrStVari is missing
#endif
#define Rte_Pim_RtnCmdScaRateLimrStVari() (&BmwTqOvrlCdngAndDrvgDynFac_Pim_RtnCmdScaRateLimrStVari)


/*** Client Stub ***/

extern FUNC(void, AUTOMATIC) Rte_Stub(void);


#endif
