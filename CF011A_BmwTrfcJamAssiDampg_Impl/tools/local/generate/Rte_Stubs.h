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
extern VAR(float32, AUTOMATIC) BmwTrfcJamAssiDampg_Ip_BmwTrfcJamAssiDampgScaReq;
extern VAR(boolean, AUTOMATIC) BmwTrfcJamAssiDampg_Ip_BmwTrfcJamAssiDampgScaReqVld;
extern VAR(BmwTrfcJamAssiDampgStReq1, AUTOMATIC) BmwTrfcJamAssiDampg_Ip_BmwTrfcJamAssiDampgStReq;
extern VAR(boolean, AUTOMATIC) BmwTrfcJamAssiDampg_Ip_BmwTrfcJamAssiDampgStReqVld;
extern VAR(float32, AUTOMATIC) BmwTrfcJamAssiDampg_Ip_MotVelCrf;
extern VAR(boolean, AUTOMATIC) BmwTrfcJamAssiDampg_Ip_TrfcJamAssiCmdEna;
extern VAR(float32, AUTOMATIC) BmwTrfcJamAssiDampg_Ip_VehSpd;

/* Outputs */
extern VAR(BmwTrfcJamAssiSt1, AUTOMATIC) BmwTrfcJamAssiDampg_Op_BmwTrfcJamAssiDampgSt;
extern VAR(float32, AUTOMATIC) BmwTrfcJamAssiDampg_Op_TrfcJamAssiCmd;

/* Calibrations */
extern CONST(u11p5, AUTOMATIC) BmwTrfcJamAssiDampg_Cal_BmwTrfcJamAssiDampgBasDampgX[10];
extern CONST(u4p12, AUTOMATIC) BmwTrfcJamAssiDampg_Cal_BmwTrfcJamAssiDampgBasDampgY[10];
extern CONST(uint16, AUTOMATIC) BmwTrfcJamAssiDampg_Cal_BmwTrfcJamAssiDampgLimExcddFltRefTiThd;
extern CONST(u11p5, AUTOMATIC) BmwTrfcJamAssiDampg_Cal_BmwTrfcJamAssiDampgLimdDampgX[12];
extern CONST(u4p12, AUTOMATIC) BmwTrfcJamAssiDampg_Cal_BmwTrfcJamAssiDampgLimdDampgY[12][12];
extern CONST(float32, AUTOMATIC) BmwTrfcJamAssiDampg_Cal_BmwTrfcJamAssiDampgRatThd;
extern CONST(float32, AUTOMATIC) BmwTrfcJamAssiDampg_Cal_BmwTrfcJamAssiDampgSlewRateDwnActv;
extern CONST(float32, AUTOMATIC) BmwTrfcJamAssiDampg_Cal_BmwTrfcJamAssiDampgSlewRateDwnInactv;
extern CONST(float32, AUTOMATIC) BmwTrfcJamAssiDampg_Cal_BmwTrfcJamAssiDampgSlewRateDwnInvld;
extern CONST(float32, AUTOMATIC) BmwTrfcJamAssiDampg_Cal_BmwTrfcJamAssiDampgSlewRateUp;
extern CONST(u9p7, AUTOMATIC) BmwTrfcJamAssiDampg_Cal_SysGlbPrmVehSpdBilnrSeln[12];

/* PIMs */
extern VAR(float32, AUTOMATIC) BmwTrfcJamAssiDampg_Pim_BmwTrfcJamAssiDampgScaStVari;
extern VAR(uint32, AUTOMATIC) BmwTrfcJamAssiDampg_Pim_LimExcddFltRefTi;
extern VAR(boolean, AUTOMATIC) BmwTrfcJamAssiDampg_Pim_PrevLimExcddFlt;
extern VAR(uint8, AUTOMATIC) BmwTrfcJamAssiDampg_Pim_TmpBmwTrfcJamAssiDampgSt;

/* Arguments and Returns */
extern VAR(uint32, AUTOMATIC) BmwTrfcJamAssiDampg_Srv_GetRefTmr100MicroSec32bit_RefTmr;
extern VAR(uint32, AUTOMATIC) BmwTrfcJamAssiDampg_Srv_GetTiSpan100MicroSec32bit_RefTmr;
extern VAR(uint32, AUTOMATIC) BmwTrfcJamAssiDampg_Srv_GetTiSpan100MicroSec32bit_TiSpan;


/*** Input Stubs ***/

#ifdef Rte_Read_BmwTrfcJamAssiDampgScaReq_Val
# undef Rte_Read_BmwTrfcJamAssiDampgScaReq_Val
#else
#error Rte_Read_BmwTrfcJamAssiDampgScaReq_Val is missing
#endif
#define Rte_Read_BmwTrfcJamAssiDampgScaReq_Val(data) (*(data) = BmwTrfcJamAssiDampg_Ip_BmwTrfcJamAssiDampgScaReq)

#ifdef Rte_Read_BmwTrfcJamAssiDampgScaReqVld_Logl
# undef Rte_Read_BmwTrfcJamAssiDampgScaReqVld_Logl
#else
#error Rte_Read_BmwTrfcJamAssiDampgScaReqVld_Logl is missing
#endif
#define Rte_Read_BmwTrfcJamAssiDampgScaReqVld_Logl(data) (*(data) = BmwTrfcJamAssiDampg_Ip_BmwTrfcJamAssiDampgScaReqVld)

#ifdef Rte_Read_BmwTrfcJamAssiDampgStReq_Val
# undef Rte_Read_BmwTrfcJamAssiDampgStReq_Val
#else
#error Rte_Read_BmwTrfcJamAssiDampgStReq_Val is missing
#endif
#define Rte_Read_BmwTrfcJamAssiDampgStReq_Val(data) (*(data) = BmwTrfcJamAssiDampg_Ip_BmwTrfcJamAssiDampgStReq)

#ifdef Rte_Read_BmwTrfcJamAssiDampgStReqVld_Logl
# undef Rte_Read_BmwTrfcJamAssiDampgStReqVld_Logl
#else
#error Rte_Read_BmwTrfcJamAssiDampgStReqVld_Logl is missing
#endif
#define Rte_Read_BmwTrfcJamAssiDampgStReqVld_Logl(data) (*(data) = BmwTrfcJamAssiDampg_Ip_BmwTrfcJamAssiDampgStReqVld)

#ifdef Rte_Read_MotVelCrf_Val
# undef Rte_Read_MotVelCrf_Val
#else
#error Rte_Read_MotVelCrf_Val is missing
#endif
#define Rte_Read_MotVelCrf_Val(data) (*(data) = BmwTrfcJamAssiDampg_Ip_MotVelCrf)

#ifdef Rte_Read_TrfcJamAssiCmdEna_Logl
# undef Rte_Read_TrfcJamAssiCmdEna_Logl
#else
#error Rte_Read_TrfcJamAssiCmdEna_Logl is missing
#endif
#define Rte_Read_TrfcJamAssiCmdEna_Logl(data) (*(data) = BmwTrfcJamAssiDampg_Ip_TrfcJamAssiCmdEna)

#ifdef Rte_Read_VehSpd_Val
# undef Rte_Read_VehSpd_Val
#else
#error Rte_Read_VehSpd_Val is missing
#endif
#define Rte_Read_VehSpd_Val(data) (*(data) = BmwTrfcJamAssiDampg_Ip_VehSpd)


/*** Output Stubs ***/

#ifdef Rte_Write_BmwTrfcJamAssiDampgSt_Val
# undef Rte_Write_BmwTrfcJamAssiDampgSt_Val
#else
#error Rte_Write_BmwTrfcJamAssiDampgSt_Val is missing
#endif
#define Rte_Write_BmwTrfcJamAssiDampgSt_Val(data) (BmwTrfcJamAssiDampg_Op_BmwTrfcJamAssiDampgSt = (data))

#ifdef Rte_Write_TrfcJamAssiCmd_Val
# undef Rte_Write_TrfcJamAssiCmd_Val
#else
#error Rte_Write_TrfcJamAssiCmd_Val is missing
#endif
#define Rte_Write_TrfcJamAssiCmd_Val(data) (BmwTrfcJamAssiDampg_Op_TrfcJamAssiCmd = (data))


/*** Calibration Stubs ***/

#ifdef Rte_Prm_BmwTrfcJamAssiDampgBasDampgX_Ary1D
# undef Rte_Prm_BmwTrfcJamAssiDampgBasDampgX_Ary1D
#else
#error Rte_Prm_BmwTrfcJamAssiDampgBasDampgX_Ary1D is missing
#endif
#define Rte_Prm_BmwTrfcJamAssiDampgBasDampgX_Ary1D() (&(BmwTrfcJamAssiDampg_Cal_BmwTrfcJamAssiDampgBasDampgX[0]))

#ifdef Rte_Prm_BmwTrfcJamAssiDampgBasDampgY_Ary1D
# undef Rte_Prm_BmwTrfcJamAssiDampgBasDampgY_Ary1D
#else
#error Rte_Prm_BmwTrfcJamAssiDampgBasDampgY_Ary1D is missing
#endif
#define Rte_Prm_BmwTrfcJamAssiDampgBasDampgY_Ary1D() (&(BmwTrfcJamAssiDampg_Cal_BmwTrfcJamAssiDampgBasDampgY[0]))

#ifdef Rte_Prm_BmwTrfcJamAssiDampgLimExcddFltRefTiThd_Val
# undef Rte_Prm_BmwTrfcJamAssiDampgLimExcddFltRefTiThd_Val
#else
#error Rte_Prm_BmwTrfcJamAssiDampgLimExcddFltRefTiThd_Val is missing
#endif
#define Rte_Prm_BmwTrfcJamAssiDampgLimExcddFltRefTiThd_Val() (BmwTrfcJamAssiDampg_Cal_BmwTrfcJamAssiDampgLimExcddFltRefTiThd)

#ifdef Rte_Prm_BmwTrfcJamAssiDampgLimdDampgX_Ary1D
# undef Rte_Prm_BmwTrfcJamAssiDampgLimdDampgX_Ary1D
#else
#error Rte_Prm_BmwTrfcJamAssiDampgLimdDampgX_Ary1D is missing
#endif
#define Rte_Prm_BmwTrfcJamAssiDampgLimdDampgX_Ary1D() (&(BmwTrfcJamAssiDampg_Cal_BmwTrfcJamAssiDampgLimdDampgX[0]))

#ifdef Rte_Prm_BmwTrfcJamAssiDampgLimdDampgY_Ary2D
# undef Rte_Prm_BmwTrfcJamAssiDampgLimdDampgY_Ary2D
#else
#error Rte_Prm_BmwTrfcJamAssiDampgLimdDampgY_Ary2D is missing
#endif
#define Rte_Prm_BmwTrfcJamAssiDampgLimdDampgY_Ary2D() (&(BmwTrfcJamAssiDampg_Cal_BmwTrfcJamAssiDampgLimdDampgY[0][0]))

#ifdef Rte_Prm_BmwTrfcJamAssiDampgRatThd_Val
# undef Rte_Prm_BmwTrfcJamAssiDampgRatThd_Val
#else
#error Rte_Prm_BmwTrfcJamAssiDampgRatThd_Val is missing
#endif
#define Rte_Prm_BmwTrfcJamAssiDampgRatThd_Val() (BmwTrfcJamAssiDampg_Cal_BmwTrfcJamAssiDampgRatThd)

#ifdef Rte_Prm_BmwTrfcJamAssiDampgSlewRateDwnActv_Val
# undef Rte_Prm_BmwTrfcJamAssiDampgSlewRateDwnActv_Val
#else
#error Rte_Prm_BmwTrfcJamAssiDampgSlewRateDwnActv_Val is missing
#endif
#define Rte_Prm_BmwTrfcJamAssiDampgSlewRateDwnActv_Val() (BmwTrfcJamAssiDampg_Cal_BmwTrfcJamAssiDampgSlewRateDwnActv)

#ifdef Rte_Prm_BmwTrfcJamAssiDampgSlewRateDwnInactv_Val
# undef Rte_Prm_BmwTrfcJamAssiDampgSlewRateDwnInactv_Val
#else
#error Rte_Prm_BmwTrfcJamAssiDampgSlewRateDwnInactv_Val is missing
#endif
#define Rte_Prm_BmwTrfcJamAssiDampgSlewRateDwnInactv_Val() (BmwTrfcJamAssiDampg_Cal_BmwTrfcJamAssiDampgSlewRateDwnInactv)

#ifdef Rte_Prm_BmwTrfcJamAssiDampgSlewRateDwnInvld_Val
# undef Rte_Prm_BmwTrfcJamAssiDampgSlewRateDwnInvld_Val
#else
#error Rte_Prm_BmwTrfcJamAssiDampgSlewRateDwnInvld_Val is missing
#endif
#define Rte_Prm_BmwTrfcJamAssiDampgSlewRateDwnInvld_Val() (BmwTrfcJamAssiDampg_Cal_BmwTrfcJamAssiDampgSlewRateDwnInvld)

#ifdef Rte_Prm_BmwTrfcJamAssiDampgSlewRateUp_Val
# undef Rte_Prm_BmwTrfcJamAssiDampgSlewRateUp_Val
#else
#error Rte_Prm_BmwTrfcJamAssiDampgSlewRateUp_Val is missing
#endif
#define Rte_Prm_BmwTrfcJamAssiDampgSlewRateUp_Val() (BmwTrfcJamAssiDampg_Cal_BmwTrfcJamAssiDampgSlewRateUp)

#ifdef Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D
# undef Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D
#else
#error Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D is missing
#endif
#define Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D() (&(BmwTrfcJamAssiDampg_Cal_SysGlbPrmVehSpdBilnrSeln[0]))


/*** PIM Stubs ***/

#ifdef Rte_Pim_BmwTrfcJamAssiDampgScaStVari
# undef Rte_Pim_BmwTrfcJamAssiDampgScaStVari
#else
#error Rte_Pim_BmwTrfcJamAssiDampgScaStVari is missing
#endif
#define Rte_Pim_BmwTrfcJamAssiDampgScaStVari() (&BmwTrfcJamAssiDampg_Pim_BmwTrfcJamAssiDampgScaStVari)

#ifdef Rte_Pim_LimExcddFltRefTi
# undef Rte_Pim_LimExcddFltRefTi
#else
#error Rte_Pim_LimExcddFltRefTi is missing
#endif
#define Rte_Pim_LimExcddFltRefTi() (&BmwTrfcJamAssiDampg_Pim_LimExcddFltRefTi)

#ifdef Rte_Pim_PrevLimExcddFlt
# undef Rte_Pim_PrevLimExcddFlt
#else
#error Rte_Pim_PrevLimExcddFlt is missing
#endif
#define Rte_Pim_PrevLimExcddFlt() (&BmwTrfcJamAssiDampg_Pim_PrevLimExcddFlt)

#ifdef Rte_Pim_TmpBmwTrfcJamAssiDampgSt
# undef Rte_Pim_TmpBmwTrfcJamAssiDampgSt
#else
#error Rte_Pim_TmpBmwTrfcJamAssiDampgSt is missing
#endif
#define Rte_Pim_TmpBmwTrfcJamAssiDampgSt() (&BmwTrfcJamAssiDampg_Pim_TmpBmwTrfcJamAssiDampgSt)


/*** Client Stub ***/

extern FUNC(void, AUTOMATIC) Rte_Stub(void);


#endif
