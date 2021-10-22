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


/*** Extern Statements ***/

/* Inputs */
extern VAR(float32, AUTOMATIC) PullCmpActv_Ip_HwAg;
extern VAR(float32, AUTOMATIC) PullCmpActv_Ip_HwTq;
extern VAR(float32, AUTOMATIC) PullCmpActv_Ip_HwVel;
extern VAR(float32, AUTOMATIC) PullCmpActv_Ip_PinionAgConf;
extern VAR(boolean, AUTOMATIC) PullCmpActv_Ip_PullCmpActvDi;
extern VAR(boolean, AUTOMATIC) PullCmpActv_Ip_PullCmpCmdDi;
extern VAR(boolean, AUTOMATIC) PullCmpActv_Ip_PullCmpCustLrngDi;
extern VAR(boolean, AUTOMATIC) PullCmpActv_Ip_PullCmpLrngDi;
extern VAR(float32, AUTOMATIC) PullCmpActv_Ip_VehLatA;
extern VAR(float32, AUTOMATIC) PullCmpActv_Ip_VehSpd;
extern VAR(boolean, AUTOMATIC) PullCmpActv_Ip_VehSpdVld;
extern VAR(float32, AUTOMATIC) PullCmpActv_Ip_VehYawRate;
extern VAR(boolean, AUTOMATIC) PullCmpActv_Ip_VehYawRateVld;

/* Outputs */
extern VAR(float32, AUTOMATIC) PullCmpActv_Op_PullCmpCmd;

/* Calibrations */
extern CONST(float32, AUTOMATIC) PullCmpActv_Cal_PullCmpActvCmpLrnTiDecShoTerm;
extern CONST(float32, AUTOMATIC) PullCmpActv_Cal_PullCmpActvCmpLrnTiIncShoTerm;
extern CONST(float32, AUTOMATIC) PullCmpActv_Cal_PullCmpActvCmpLrnTiLongTerm;
extern CONST(float32, AUTOMATIC) PullCmpActv_Cal_PullCmpActvCmpShoTermRstHwAgThd;
extern CONST(float32, AUTOMATIC) PullCmpActv_Cal_PullCmpActvCmpShoTermRstHwTqThd;
extern CONST(float32, AUTOMATIC) PullCmpActv_Cal_PullCmpActvCmpShoTermRstLatAThd;
extern CONST(float32, AUTOMATIC) PullCmpActv_Cal_PullCmpActvCmpShoTermRstYawRateThd;
extern CONST(boolean, AUTOMATIC) PullCmpActv_Cal_PullCmpActvEna;
extern CONST(float32, AUTOMATIC) PullCmpActv_Cal_PullCmpActvHwTqFilFrqLongTerm;
extern CONST(float32, AUTOMATIC) PullCmpActv_Cal_PullCmpActvHwTqFilFrqLrngEna;
extern CONST(float32, AUTOMATIC) PullCmpActv_Cal_PullCmpActvHwTqFilFrqShoTerm;
extern CONST(float32, AUTOMATIC) PullCmpActv_Cal_PullCmpActvLongTermLim;
extern CONST(float32, AUTOMATIC) PullCmpActv_Cal_PullCmpActvLrngEnaAgConfMinMgn;
extern CONST(float32, AUTOMATIC) PullCmpActv_Cal_PullCmpActvLrngEnaHwAgMaxMgn;
extern CONST(float32, AUTOMATIC) PullCmpActv_Cal_PullCmpActvLrngEnaHwTqMaxMgn;
extern CONST(float32, AUTOMATIC) PullCmpActv_Cal_PullCmpActvLrngEnaHwVelMaxMgn;
extern CONST(float32, AUTOMATIC) PullCmpActv_Cal_PullCmpActvLrngEnaLatAMaxMgn;
extern CONST(float32, AUTOMATIC) PullCmpActv_Cal_PullCmpActvLrngEnaTiThd;
extern CONST(float32, AUTOMATIC) PullCmpActv_Cal_PullCmpActvLrngEnaVehSpdMaxMgn;
extern CONST(float32, AUTOMATIC) PullCmpActv_Cal_PullCmpActvLrngEnaVehSpdMinMgn;
extern CONST(float32, AUTOMATIC) PullCmpActv_Cal_PullCmpActvLrngEnaVehSpdRateMaxMgn;
extern CONST(float32, AUTOMATIC) PullCmpActv_Cal_PullCmpActvLrngEnaYawRateMaxMgn;
extern CONST(float32, AUTOMATIC) PullCmpActv_Cal_PullCmpActvOpstSignTiShoTerm;
extern CONST(float32, AUTOMATIC) PullCmpActv_Cal_PullCmpActvOutpMaxRate;
extern CONST(float32, AUTOMATIC) PullCmpActv_Cal_PullCmpActvPullCmpShoTermLim;
extern CONST(float32, AUTOMATIC) PullCmpActv_Cal_PullCmpActvPullCmpTotLim;
extern CONST(float32, AUTOMATIC) PullCmpActv_Cal_PullCmpActvPullErrLimLongTerm;
extern CONST(float32, AUTOMATIC) PullCmpActv_Cal_PullCmpActvPullErrMgnThd;
extern CONST(float32, AUTOMATIC) PullCmpActv_Cal_PullCmpActvPullErrShoTermLim;
extern CONST(float32, AUTOMATIC) PullCmpActv_Cal_PullCmpActvShoTermRampTi;
extern CONST(u9p7, AUTOMATIC) PullCmpActv_Cal_PullCmpActvVehSpdScaTblX[4];
extern CONST(u2p14, AUTOMATIC) PullCmpActv_Cal_PullCmpActvVehSpdScaTblY[4];
extern CONST(float32, AUTOMATIC) PullCmpActv_Cal_PullCmpActvYawRateFilFrq;
extern CONST(float32, AUTOMATIC) PullCmpActv_Cal_SysGlbPrmSysTqRat;

/* PIMs */
extern VAR(float32, AUTOMATIC) PullCmpActv_Pim_PullCmpLongTerm;
extern VAR(float32, AUTOMATIC) PullCmpActv_Pim_dPullCmpActvIntgtrGainShoTerm;
extern VAR(float32, AUTOMATIC) PullCmpActv_Pim_dPullCmpActvPullErrLongTerm;
extern VAR(float32, AUTOMATIC) PullCmpActv_Pim_dPullCmpActvPullErrShoTerm;
extern VAR(boolean, AUTOMATIC) PullCmpActv_Pim_dPullCmpActvShoTermRst;
extern VAR(float32, AUTOMATIC) PullCmpActv_Pim_CmpLrnTiDecShoTerm;
extern VAR(float32, AUTOMATIC) PullCmpActv_Pim_CmpLrnTiIncShoTerm;
extern VAR(float32, AUTOMATIC) PullCmpActv_Pim_CmpLrnTiLongTerm;
extern VAR(FilLpRec1, AUTOMATIC) PullCmpActv_Pim_HwTqLpFilLongTerm;
extern VAR(FilLpRec1, AUTOMATIC) PullCmpActv_Pim_HwTqLpFilLrngEna;
extern VAR(FilLpRec1, AUTOMATIC) PullCmpActv_Pim_HwTqLpFilShoTerm;
extern VAR(float32, AUTOMATIC) PullCmpActv_Pim_IntgtrGainDecShoTerm;
extern VAR(float32, AUTOMATIC) PullCmpActv_Pim_IntgtrGainIncShoTerm;
extern VAR(boolean, AUTOMATIC) PullCmpActv_Pim_LrngEnaPrev;
extern VAR(boolean, AUTOMATIC) PullCmpActv_Pim_LrngEnad;
extern VAR(boolean, AUTOMATIC) PullCmpActv_Pim_OpstSignPrev;
extern VAR(float32, AUTOMATIC) PullCmpActv_Pim_PrevLrnTiLongTerm;
extern VAR(float32, AUTOMATIC) PullCmpActv_Pim_PullCmpCmdRateLimPrev;
extern VAR(float32, AUTOMATIC) PullCmpActv_Pim_PullCmpCmdTot;
extern VAR(boolean, AUTOMATIC) PullCmpActv_Pim_PullCmpLongTermRst;
extern VAR(float32, AUTOMATIC) PullCmpActv_Pim_PullCmpShoTerm;
extern VAR(boolean, AUTOMATIC) PullCmpActv_Pim_PullCmpShoTermRst;
extern VAR(uint32, AUTOMATIC) PullCmpActv_Pim_RefTiEnaLrng;
extern VAR(uint32, AUTOMATIC) PullCmpActv_Pim_RefTiOpstSign;
extern VAR(float32, AUTOMATIC) PullCmpActv_Pim_VehSpdPrev;
extern VAR(float32, AUTOMATIC) PullCmpActv_Pim_VehSpdRate;
extern VAR(FilLpRec1, AUTOMATIC) PullCmpActv_Pim_VehYawRateLpFil;

/* IRVs */
extern VAR(float32, AUTOMATIC) PullCmpActv_Irv_RampDwnStepSize;

/* Arguments and Returns */
extern VAR(uint32, AUTOMATIC) PullCmpActv_Srv_GetRefTmr100MicroSec32bit_RefTmr;
extern VAR(uint32, AUTOMATIC) PullCmpActv_Srv_GetTiSpan100MicroSec32bit_RefTmr;
extern VAR(uint32, AUTOMATIC) PullCmpActv_Srv_GetTiSpan100MicroSec32bit_TiSpan;
extern VAR(boolean, AUTOMATIC) PullCmpActv_Srv_PullCmpLongTerm_SetRamBlockStatus_BlockChanged;
extern VAR(float32, AUTOMATIC) PullCmpActv_Cli_GetPullCmpPrm_PullCmpCmdTot;
extern VAR(float32, AUTOMATIC) PullCmpActv_Cli_GetPullCmpPrm_PullCmpShoTerm;
extern VAR(float32, AUTOMATIC) PullCmpActv_Cli_GetPullCmpPrm_PullCmpLongTerm;
extern VAR(boolean, AUTOMATIC) PullCmpActv_Cli_GetPullCmpPrm_LrngEnad;
extern VAR(float32, AUTOMATIC) PullCmpActv_Cli_SetPullCmpLongTerm_PullCmpLongTerm;
extern VAR(float32, AUTOMATIC) PullCmpActv_Cli_SetPullCmpShoTerm_PullCmpShoTerm;


/*** Input Stubs ***/

#ifdef Rte_Read_HwAg_Val
# undef Rte_Read_HwAg_Val
#endif
#define Rte_Read_HwAg_Val(data) (*(data) = PullCmpActv_Ip_HwAg)

#ifdef Rte_Read_HwTq_Val
# undef Rte_Read_HwTq_Val
#endif
#define Rte_Read_HwTq_Val(data) (*(data) = PullCmpActv_Ip_HwTq)

#ifdef Rte_Read_HwVel_Val
# undef Rte_Read_HwVel_Val
#endif
#define Rte_Read_HwVel_Val(data) (*(data) = PullCmpActv_Ip_HwVel)

#ifdef Rte_Read_PinionAgConf_Val
# undef Rte_Read_PinionAgConf_Val
#endif
#define Rte_Read_PinionAgConf_Val(data) (*(data) = PullCmpActv_Ip_PinionAgConf)

#ifdef Rte_Read_PullCmpActvDi_Logl
# undef Rte_Read_PullCmpActvDi_Logl
#endif
#define Rte_Read_PullCmpActvDi_Logl(data) (*(data) = PullCmpActv_Ip_PullCmpActvDi)

#ifdef Rte_Read_PullCmpCmdDi_Logl
# undef Rte_Read_PullCmpCmdDi_Logl
#endif
#define Rte_Read_PullCmpCmdDi_Logl(data) (*(data) = PullCmpActv_Ip_PullCmpCmdDi)

#ifdef Rte_Read_PullCmpCustLrngDi_Logl
# undef Rte_Read_PullCmpCustLrngDi_Logl
#endif
#define Rte_Read_PullCmpCustLrngDi_Logl(data) (*(data) = PullCmpActv_Ip_PullCmpCustLrngDi)

#ifdef Rte_Read_PullCmpLrngDi_Logl
# undef Rte_Read_PullCmpLrngDi_Logl
#endif
#define Rte_Read_PullCmpLrngDi_Logl(data) (*(data) = PullCmpActv_Ip_PullCmpLrngDi)

#ifdef Rte_Read_VehLatA_Val
# undef Rte_Read_VehLatA_Val
#endif
#define Rte_Read_VehLatA_Val(data) (*(data) = PullCmpActv_Ip_VehLatA)

#ifdef Rte_Read_VehSpd_Val
# undef Rte_Read_VehSpd_Val
#endif
#define Rte_Read_VehSpd_Val(data) (*(data) = PullCmpActv_Ip_VehSpd)

#ifdef Rte_Read_VehSpdVld_Logl
# undef Rte_Read_VehSpdVld_Logl
#endif
#define Rte_Read_VehSpdVld_Logl(data) (*(data) = PullCmpActv_Ip_VehSpdVld)

#ifdef Rte_Read_VehYawRate_Val
# undef Rte_Read_VehYawRate_Val
#endif
#define Rte_Read_VehYawRate_Val(data) (*(data) = PullCmpActv_Ip_VehYawRate)

#ifdef Rte_Read_VehYawRateVld_Logl
# undef Rte_Read_VehYawRateVld_Logl
#endif
#define Rte_Read_VehYawRateVld_Logl(data) (*(data) = PullCmpActv_Ip_VehYawRateVld)


/*** Output Stubs ***/

#ifdef Rte_Write_PullCmpCmd_Val
# undef Rte_Write_PullCmpCmd_Val
#endif
#define Rte_Write_PullCmpCmd_Val(data) (PullCmpActv_Op_PullCmpCmd = (data))


/*** Calibration Stubs ***/

#ifdef Rte_Prm_PullCmpActvCmpLrnTiDecShoTerm_Val
# undef Rte_Prm_PullCmpActvCmpLrnTiDecShoTerm_Val
#endif
#define Rte_Prm_PullCmpActvCmpLrnTiDecShoTerm_Val() (PullCmpActv_Cal_PullCmpActvCmpLrnTiDecShoTerm)

#ifdef Rte_Prm_PullCmpActvCmpLrnTiIncShoTerm_Val
# undef Rte_Prm_PullCmpActvCmpLrnTiIncShoTerm_Val
#endif
#define Rte_Prm_PullCmpActvCmpLrnTiIncShoTerm_Val() (PullCmpActv_Cal_PullCmpActvCmpLrnTiIncShoTerm)

#ifdef Rte_Prm_PullCmpActvCmpLrnTiLongTerm_Val
# undef Rte_Prm_PullCmpActvCmpLrnTiLongTerm_Val
#endif
#define Rte_Prm_PullCmpActvCmpLrnTiLongTerm_Val() (PullCmpActv_Cal_PullCmpActvCmpLrnTiLongTerm)

#ifdef Rte_Prm_PullCmpActvCmpShoTermRstHwAgThd_Val
# undef Rte_Prm_PullCmpActvCmpShoTermRstHwAgThd_Val
#endif
#define Rte_Prm_PullCmpActvCmpShoTermRstHwAgThd_Val() (PullCmpActv_Cal_PullCmpActvCmpShoTermRstHwAgThd)

#ifdef Rte_Prm_PullCmpActvCmpShoTermRstHwTqThd_Val
# undef Rte_Prm_PullCmpActvCmpShoTermRstHwTqThd_Val
#endif
#define Rte_Prm_PullCmpActvCmpShoTermRstHwTqThd_Val() (PullCmpActv_Cal_PullCmpActvCmpShoTermRstHwTqThd)

#ifdef Rte_Prm_PullCmpActvCmpShoTermRstLatAThd_Val
# undef Rte_Prm_PullCmpActvCmpShoTermRstLatAThd_Val
#endif
#define Rte_Prm_PullCmpActvCmpShoTermRstLatAThd_Val() (PullCmpActv_Cal_PullCmpActvCmpShoTermRstLatAThd)

#ifdef Rte_Prm_PullCmpActvCmpShoTermRstYawRateThd_Val
# undef Rte_Prm_PullCmpActvCmpShoTermRstYawRateThd_Val
#endif
#define Rte_Prm_PullCmpActvCmpShoTermRstYawRateThd_Val() (PullCmpActv_Cal_PullCmpActvCmpShoTermRstYawRateThd)

#ifdef Rte_Prm_PullCmpActvEna_Logl
# undef Rte_Prm_PullCmpActvEna_Logl
#endif
#define Rte_Prm_PullCmpActvEna_Logl() (PullCmpActv_Cal_PullCmpActvEna)

#ifdef Rte_Prm_PullCmpActvHwTqFilFrqLongTerm_Val
# undef Rte_Prm_PullCmpActvHwTqFilFrqLongTerm_Val
#endif
#define Rte_Prm_PullCmpActvHwTqFilFrqLongTerm_Val() (PullCmpActv_Cal_PullCmpActvHwTqFilFrqLongTerm)

#ifdef Rte_Prm_PullCmpActvHwTqFilFrqLrngEna_Val
# undef Rte_Prm_PullCmpActvHwTqFilFrqLrngEna_Val
#endif
#define Rte_Prm_PullCmpActvHwTqFilFrqLrngEna_Val() (PullCmpActv_Cal_PullCmpActvHwTqFilFrqLrngEna)

#ifdef Rte_Prm_PullCmpActvHwTqFilFrqShoTerm_Val
# undef Rte_Prm_PullCmpActvHwTqFilFrqShoTerm_Val
#endif
#define Rte_Prm_PullCmpActvHwTqFilFrqShoTerm_Val() (PullCmpActv_Cal_PullCmpActvHwTqFilFrqShoTerm)

#ifdef Rte_Prm_PullCmpActvLongTermLim_Val
# undef Rte_Prm_PullCmpActvLongTermLim_Val
#endif
#define Rte_Prm_PullCmpActvLongTermLim_Val() (PullCmpActv_Cal_PullCmpActvLongTermLim)

#ifdef Rte_Prm_PullCmpActvLrngEnaAgConfMinMgn_Val
# undef Rte_Prm_PullCmpActvLrngEnaAgConfMinMgn_Val
#endif
#define Rte_Prm_PullCmpActvLrngEnaAgConfMinMgn_Val() (PullCmpActv_Cal_PullCmpActvLrngEnaAgConfMinMgn)

#ifdef Rte_Prm_PullCmpActvLrngEnaHwAgMaxMgn_Val
# undef Rte_Prm_PullCmpActvLrngEnaHwAgMaxMgn_Val
#endif
#define Rte_Prm_PullCmpActvLrngEnaHwAgMaxMgn_Val() (PullCmpActv_Cal_PullCmpActvLrngEnaHwAgMaxMgn)

#ifdef Rte_Prm_PullCmpActvLrngEnaHwTqMaxMgn_Val
# undef Rte_Prm_PullCmpActvLrngEnaHwTqMaxMgn_Val
#endif
#define Rte_Prm_PullCmpActvLrngEnaHwTqMaxMgn_Val() (PullCmpActv_Cal_PullCmpActvLrngEnaHwTqMaxMgn)

#ifdef Rte_Prm_PullCmpActvLrngEnaHwVelMaxMgn_Val
# undef Rte_Prm_PullCmpActvLrngEnaHwVelMaxMgn_Val
#endif
#define Rte_Prm_PullCmpActvLrngEnaHwVelMaxMgn_Val() (PullCmpActv_Cal_PullCmpActvLrngEnaHwVelMaxMgn)

#ifdef Rte_Prm_PullCmpActvLrngEnaLatAMaxMgn_Val
# undef Rte_Prm_PullCmpActvLrngEnaLatAMaxMgn_Val
#endif
#define Rte_Prm_PullCmpActvLrngEnaLatAMaxMgn_Val() (PullCmpActv_Cal_PullCmpActvLrngEnaLatAMaxMgn)

#ifdef Rte_Prm_PullCmpActvLrngEnaTiThd_Val
# undef Rte_Prm_PullCmpActvLrngEnaTiThd_Val
#endif
#define Rte_Prm_PullCmpActvLrngEnaTiThd_Val() (PullCmpActv_Cal_PullCmpActvLrngEnaTiThd)

#ifdef Rte_Prm_PullCmpActvLrngEnaVehSpdMaxMgn_Val
# undef Rte_Prm_PullCmpActvLrngEnaVehSpdMaxMgn_Val
#endif
#define Rte_Prm_PullCmpActvLrngEnaVehSpdMaxMgn_Val() (PullCmpActv_Cal_PullCmpActvLrngEnaVehSpdMaxMgn)

#ifdef Rte_Prm_PullCmpActvLrngEnaVehSpdMinMgn_Val
# undef Rte_Prm_PullCmpActvLrngEnaVehSpdMinMgn_Val
#endif
#define Rte_Prm_PullCmpActvLrngEnaVehSpdMinMgn_Val() (PullCmpActv_Cal_PullCmpActvLrngEnaVehSpdMinMgn)

#ifdef Rte_Prm_PullCmpActvLrngEnaVehSpdRateMaxMgn_Val
# undef Rte_Prm_PullCmpActvLrngEnaVehSpdRateMaxMgn_Val
#endif
#define Rte_Prm_PullCmpActvLrngEnaVehSpdRateMaxMgn_Val() (PullCmpActv_Cal_PullCmpActvLrngEnaVehSpdRateMaxMgn)

#ifdef Rte_Prm_PullCmpActvLrngEnaYawRateMaxMgn_Val
# undef Rte_Prm_PullCmpActvLrngEnaYawRateMaxMgn_Val
#endif
#define Rte_Prm_PullCmpActvLrngEnaYawRateMaxMgn_Val() (PullCmpActv_Cal_PullCmpActvLrngEnaYawRateMaxMgn)

#ifdef Rte_Prm_PullCmpActvOpstSignTiShoTerm_Val
# undef Rte_Prm_PullCmpActvOpstSignTiShoTerm_Val
#endif
#define Rte_Prm_PullCmpActvOpstSignTiShoTerm_Val() (PullCmpActv_Cal_PullCmpActvOpstSignTiShoTerm)

#ifdef Rte_Prm_PullCmpActvOutpMaxRate_Val
# undef Rte_Prm_PullCmpActvOutpMaxRate_Val
#endif
#define Rte_Prm_PullCmpActvOutpMaxRate_Val() (PullCmpActv_Cal_PullCmpActvOutpMaxRate)

#ifdef Rte_Prm_PullCmpActvPullCmpShoTermLim_Val
# undef Rte_Prm_PullCmpActvPullCmpShoTermLim_Val
#endif
#define Rte_Prm_PullCmpActvPullCmpShoTermLim_Val() (PullCmpActv_Cal_PullCmpActvPullCmpShoTermLim)

#ifdef Rte_Prm_PullCmpActvPullCmpTotLim_Val
# undef Rte_Prm_PullCmpActvPullCmpTotLim_Val
#endif
#define Rte_Prm_PullCmpActvPullCmpTotLim_Val() (PullCmpActv_Cal_PullCmpActvPullCmpTotLim)

#ifdef Rte_Prm_PullCmpActvPullErrLimLongTerm_Val
# undef Rte_Prm_PullCmpActvPullErrLimLongTerm_Val
#endif
#define Rte_Prm_PullCmpActvPullErrLimLongTerm_Val() (PullCmpActv_Cal_PullCmpActvPullErrLimLongTerm)

#ifdef Rte_Prm_PullCmpActvPullErrMgnThd_Val
# undef Rte_Prm_PullCmpActvPullErrMgnThd_Val
#endif
#define Rte_Prm_PullCmpActvPullErrMgnThd_Val() (PullCmpActv_Cal_PullCmpActvPullErrMgnThd)

#ifdef Rte_Prm_PullCmpActvPullErrShoTermLim_Val
# undef Rte_Prm_PullCmpActvPullErrShoTermLim_Val
#endif
#define Rte_Prm_PullCmpActvPullErrShoTermLim_Val() (PullCmpActv_Cal_PullCmpActvPullErrShoTermLim)

#ifdef Rte_Prm_PullCmpActvShoTermRampTi_Val
# undef Rte_Prm_PullCmpActvShoTermRampTi_Val
#endif
#define Rte_Prm_PullCmpActvShoTermRampTi_Val() (PullCmpActv_Cal_PullCmpActvShoTermRampTi)

#ifdef Rte_Prm_PullCmpActvVehSpdScaTblX_Ary1D
# undef Rte_Prm_PullCmpActvVehSpdScaTblX_Ary1D
#endif
#define Rte_Prm_PullCmpActvVehSpdScaTblX_Ary1D() (&(PullCmpActv_Cal_PullCmpActvVehSpdScaTblX[0]))

#ifdef Rte_Prm_PullCmpActvVehSpdScaTblY_Ary1D
# undef Rte_Prm_PullCmpActvVehSpdScaTblY_Ary1D
#endif
#define Rte_Prm_PullCmpActvVehSpdScaTblY_Ary1D() (&(PullCmpActv_Cal_PullCmpActvVehSpdScaTblY[0]))

#ifdef Rte_Prm_PullCmpActvYawRateFilFrq_Val
# undef Rte_Prm_PullCmpActvYawRateFilFrq_Val
#endif
#define Rte_Prm_PullCmpActvYawRateFilFrq_Val() (PullCmpActv_Cal_PullCmpActvYawRateFilFrq)

#ifdef Rte_Prm_SysGlbPrmSysTqRat_Val
# undef Rte_Prm_SysGlbPrmSysTqRat_Val
#endif
#define Rte_Prm_SysGlbPrmSysTqRat_Val() (PullCmpActv_Cal_SysGlbPrmSysTqRat)


/*** PIM Stubs ***/

#ifdef Rte_Pim_PullCmpLongTerm
# undef Rte_Pim_PullCmpLongTerm
#endif
#define Rte_Pim_PullCmpLongTerm() (&PullCmpActv_Pim_PullCmpLongTerm)

#ifdef Rte_Pim_dPullCmpActvIntgtrGainShoTerm
# undef Rte_Pim_dPullCmpActvIntgtrGainShoTerm
#endif
#define Rte_Pim_dPullCmpActvIntgtrGainShoTerm() (&PullCmpActv_Pim_dPullCmpActvIntgtrGainShoTerm)

#ifdef Rte_Pim_dPullCmpActvPullErrLongTerm
# undef Rte_Pim_dPullCmpActvPullErrLongTerm
#endif
#define Rte_Pim_dPullCmpActvPullErrLongTerm() (&PullCmpActv_Pim_dPullCmpActvPullErrLongTerm)

#ifdef Rte_Pim_dPullCmpActvPullErrShoTerm
# undef Rte_Pim_dPullCmpActvPullErrShoTerm
#endif
#define Rte_Pim_dPullCmpActvPullErrShoTerm() (&PullCmpActv_Pim_dPullCmpActvPullErrShoTerm)

#ifdef Rte_Pim_dPullCmpActvShoTermRst
# undef Rte_Pim_dPullCmpActvShoTermRst
#endif
#define Rte_Pim_dPullCmpActvShoTermRst() (&PullCmpActv_Pim_dPullCmpActvShoTermRst)

#ifdef Rte_Pim_CmpLrnTiDecShoTerm
# undef Rte_Pim_CmpLrnTiDecShoTerm
#endif
#define Rte_Pim_CmpLrnTiDecShoTerm() (&PullCmpActv_Pim_CmpLrnTiDecShoTerm)

#ifdef Rte_Pim_CmpLrnTiIncShoTerm
# undef Rte_Pim_CmpLrnTiIncShoTerm
#endif
#define Rte_Pim_CmpLrnTiIncShoTerm() (&PullCmpActv_Pim_CmpLrnTiIncShoTerm)

#ifdef Rte_Pim_CmpLrnTiLongTerm
# undef Rte_Pim_CmpLrnTiLongTerm
#endif
#define Rte_Pim_CmpLrnTiLongTerm() (&PullCmpActv_Pim_CmpLrnTiLongTerm)

#ifdef Rte_Pim_HwTqLpFilLongTerm
# undef Rte_Pim_HwTqLpFilLongTerm
#endif
#define Rte_Pim_HwTqLpFilLongTerm() (&PullCmpActv_Pim_HwTqLpFilLongTerm)

#ifdef Rte_Pim_HwTqLpFilLrngEna
# undef Rte_Pim_HwTqLpFilLrngEna
#endif
#define Rte_Pim_HwTqLpFilLrngEna() (&PullCmpActv_Pim_HwTqLpFilLrngEna)

#ifdef Rte_Pim_HwTqLpFilShoTerm
# undef Rte_Pim_HwTqLpFilShoTerm
#endif
#define Rte_Pim_HwTqLpFilShoTerm() (&PullCmpActv_Pim_HwTqLpFilShoTerm)

#ifdef Rte_Pim_IntgtrGainDecShoTerm
# undef Rte_Pim_IntgtrGainDecShoTerm
#endif
#define Rte_Pim_IntgtrGainDecShoTerm() (&PullCmpActv_Pim_IntgtrGainDecShoTerm)

#ifdef Rte_Pim_IntgtrGainIncShoTerm
# undef Rte_Pim_IntgtrGainIncShoTerm
#endif
#define Rte_Pim_IntgtrGainIncShoTerm() (&PullCmpActv_Pim_IntgtrGainIncShoTerm)

#ifdef Rte_Pim_LrngEnaPrev
# undef Rte_Pim_LrngEnaPrev
#endif
#define Rte_Pim_LrngEnaPrev() (&PullCmpActv_Pim_LrngEnaPrev)

#ifdef Rte_Pim_LrngEnad
# undef Rte_Pim_LrngEnad
#endif
#define Rte_Pim_LrngEnad() (&PullCmpActv_Pim_LrngEnad)

#ifdef Rte_Pim_OpstSignPrev
# undef Rte_Pim_OpstSignPrev
#endif
#define Rte_Pim_OpstSignPrev() (&PullCmpActv_Pim_OpstSignPrev)

#ifdef Rte_Pim_PrevLrnTiLongTerm
# undef Rte_Pim_PrevLrnTiLongTerm
#endif
#define Rte_Pim_PrevLrnTiLongTerm() (&PullCmpActv_Pim_PrevLrnTiLongTerm)

#ifdef Rte_Pim_PullCmpCmdRateLimPrev
# undef Rte_Pim_PullCmpCmdRateLimPrev
#endif
#define Rte_Pim_PullCmpCmdRateLimPrev() (&PullCmpActv_Pim_PullCmpCmdRateLimPrev)

#ifdef Rte_Pim_PullCmpCmdTot
# undef Rte_Pim_PullCmpCmdTot
#endif
#define Rte_Pim_PullCmpCmdTot() (&PullCmpActv_Pim_PullCmpCmdTot)

#ifdef Rte_Pim_PullCmpLongTermRst
# undef Rte_Pim_PullCmpLongTermRst
#endif
#define Rte_Pim_PullCmpLongTermRst() (&PullCmpActv_Pim_PullCmpLongTermRst)

#ifdef Rte_Pim_PullCmpShoTerm
# undef Rte_Pim_PullCmpShoTerm
#endif
#define Rte_Pim_PullCmpShoTerm() (&PullCmpActv_Pim_PullCmpShoTerm)

#ifdef Rte_Pim_PullCmpShoTermRst
# undef Rte_Pim_PullCmpShoTermRst
#endif
#define Rte_Pim_PullCmpShoTermRst() (&PullCmpActv_Pim_PullCmpShoTermRst)

#ifdef Rte_Pim_RefTiEnaLrng
# undef Rte_Pim_RefTiEnaLrng
#endif
#define Rte_Pim_RefTiEnaLrng() (&PullCmpActv_Pim_RefTiEnaLrng)

#ifdef Rte_Pim_RefTiOpstSign
# undef Rte_Pim_RefTiOpstSign
#endif
#define Rte_Pim_RefTiOpstSign() (&PullCmpActv_Pim_RefTiOpstSign)

#ifdef Rte_Pim_VehSpdPrev
# undef Rte_Pim_VehSpdPrev
#endif
#define Rte_Pim_VehSpdPrev() (&PullCmpActv_Pim_VehSpdPrev)

#ifdef Rte_Pim_VehSpdRate
# undef Rte_Pim_VehSpdRate
#endif
#define Rte_Pim_VehSpdRate() (&PullCmpActv_Pim_VehSpdRate)

#ifdef Rte_Pim_VehYawRateLpFil
# undef Rte_Pim_VehYawRateLpFil
#endif
#define Rte_Pim_VehYawRateLpFil() (&PullCmpActv_Pim_VehYawRateLpFil)


/*** IRV Stubs ***/

#ifdef Rte_IrvRead_PullCmpActvPer1_RampDwnStepSize
# undef Rte_IrvRead_PullCmpActvPer1_RampDwnStepSize
#endif
#define Rte_IrvRead_PullCmpActvPer1_RampDwnStepSize() (PullCmpActv_Irv_RampDwnStepSize)

#ifdef Rte_IrvWrite_PullCmpActvInit1_RampDwnStepSize
# undef Rte_IrvWrite_PullCmpActvInit1_RampDwnStepSize
#endif
#define Rte_IrvWrite_PullCmpActvInit1_RampDwnStepSize(data) (PullCmpActv_Irv_RampDwnStepSize = (data))


/*** Client Stub ***/

extern FUNC(void, AUTOMATIC) Rte_Stub(void);


#endif
