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
extern VAR(sint8, AUTOMATIC) CtrldVelRtn_Ip_AssiMechPolarity;
extern VAR(float32, AUTOMATIC) CtrldVelRtn_Ip_HwAg;
extern VAR(float32, AUTOMATIC) CtrldVelRtn_Ip_HwAgAuthy;
extern VAR(float32, AUTOMATIC) CtrldVelRtn_Ip_HwAgRtnOffs;
extern VAR(float32, AUTOMATIC) CtrldVelRtn_Ip_HwTq;
extern VAR(float32, AUTOMATIC) CtrldVelRtn_Ip_HwVel;
extern VAR(float32, AUTOMATIC) CtrldVelRtn_Ip_MotTqCmdPwrLimd;
extern VAR(boolean, AUTOMATIC) CtrldVelRtn_Ip_RtnCmdDi;
extern VAR(boolean, AUTOMATIC) CtrldVelRtn_Ip_RtnCmdDiagcDi;
extern VAR(float32, AUTOMATIC) CtrldVelRtn_Ip_RtnCmdSca;
extern VAR(float32, AUTOMATIC) CtrldVelRtn_Ip_RtnCmdScaServo;
extern VAR(float32, AUTOMATIC) CtrldVelRtn_Ip_VehSpd;

/* Outputs */
extern VAR(float32, AUTOMATIC) CtrldVelRtn_Op_CtrldVelRtnCmd;

/* Calibrations */
extern CONST(float32, AUTOMATIC) CtrldVelRtn_Cal_CtrldVelRtnAntiWdup;
extern CONST(boolean, AUTOMATIC) CtrldVelRtn_Cal_CtrldVelRtnDampgEna;
extern CONST(boolean, AUTOMATIC) CtrldVelRtn_Cal_CtrldVelRtnDampgScaEna;
extern CONST(u10p6, AUTOMATIC) CtrldVelRtn_Cal_CtrldVelRtnDampgX[9][8];
extern CONST(u6p10, AUTOMATIC) CtrldVelRtn_Cal_CtrldVelRtnDampgY[9][8];
extern CONST(float32, AUTOMATIC) CtrldVelRtn_Cal_CtrldVelRtnDesVelLpFilFrq;
extern CONST(u8p8, AUTOMATIC) CtrldVelRtn_Cal_CtrldVelRtnDesVelScaX[8][5];
extern CONST(u2p14, AUTOMATIC) CtrldVelRtn_Cal_CtrldVelRtnDesVelScaY[8][5];
extern CONST(u12p4, AUTOMATIC) CtrldVelRtn_Cal_CtrldVelRtnDesVelX[12][8];
extern CONST(u10p6, AUTOMATIC) CtrldVelRtn_Cal_CtrldVelRtnDesVelY[12][8];
extern CONST(boolean, AUTOMATIC) CtrldVelRtn_Cal_CtrldVelRtnDrvrTqEna;
extern CONST(float32, AUTOMATIC) CtrldVelRtn_Cal_CtrldVelRtnDrvrTqMtrxA[5][5];
extern CONST(float32, AUTOMATIC) CtrldVelRtn_Cal_CtrldVelRtnDrvrTqMtrxB[4][5];
extern CONST(float32, AUTOMATIC) CtrldVelRtn_Cal_CtrldVelRtnDrvrTqMtrxC[5];
extern CONST(float32, AUTOMATIC) CtrldVelRtn_Cal_CtrldVelRtnDrvrTqMtrxD[4];
extern CONST(u2p14, AUTOMATIC) CtrldVelRtn_Cal_CtrldVelRtnHwAuthyScaX[4];
extern CONST(u2p14, AUTOMATIC) CtrldVelRtn_Cal_CtrldVelRtnHwAuthyScaY[4];
extern CONST(float32, AUTOMATIC) CtrldVelRtn_Cal_CtrldVelRtnHwAuthySlewThd;
extern CONST(u12p4, AUTOMATIC) CtrldVelRtn_Cal_CtrldVelRtnHwPosnScaX[9];
extern CONST(u2p14, AUTOMATIC) CtrldVelRtn_Cal_CtrldVelRtnHwPosnScaY[1][9];
extern CONST(float32, AUTOMATIC) CtrldVelRtn_Cal_CtrldVelRtnHwTqLpFilFrq;
extern CONST(u8p8, AUTOMATIC) CtrldVelRtn_Cal_CtrldVelRtnHwTqSca1X[10][5];
extern CONST(u2p14, AUTOMATIC) CtrldVelRtn_Cal_CtrldVelRtnHwTqSca1Y[10][5];
extern CONST(u8p8, AUTOMATIC) CtrldVelRtn_Cal_CtrldVelRtnHwTqSca2X[10][5];
extern CONST(u2p14, AUTOMATIC) CtrldVelRtn_Cal_CtrldVelRtnHwTqSca2Y[10][5];
extern CONST(float32, AUTOMATIC) CtrldVelRtn_Cal_CtrldVelRtnHwTqScaSelnSlewHiLim;
extern CONST(float32, AUTOMATIC) CtrldVelRtn_Cal_CtrldVelRtnHwTqScaSelnSlewLoLim;
extern CONST(float32, AUTOMATIC) CtrldVelRtn_Cal_CtrldVelRtnHwTqScaSelnTqThd;
extern CONST(float32, AUTOMATIC) CtrldVelRtn_Cal_CtrldVelRtnHwTqScaSelnVelThd;
extern CONST(u8p8, AUTOMATIC) CtrldVelRtn_Cal_CtrldVelRtnIntglGain[8];
extern CONST(u6p10, AUTOMATIC) CtrldVelRtn_Cal_CtrldVelRtnIntgrLimY[9][5];
extern CONST(float32, AUTOMATIC) CtrldVelRtn_Cal_CtrldVelRtnOffsSlewThd;
extern CONST(float32, AUTOMATIC) CtrldVelRtn_Cal_CtrldVelRtnOffsThd;
extern CONST(u8p8, AUTOMATIC) CtrldVelRtn_Cal_CtrldVelRtnPinionTqScaX[8][5];
extern CONST(u2p14, AUTOMATIC) CtrldVelRtn_Cal_CtrldVelRtnPinionTqScaY[8][5];
extern CONST(u4p12, AUTOMATIC) CtrldVelRtn_Cal_CtrldVelRtnPropGain[8];
extern CONST(u4p12, AUTOMATIC) CtrldVelRtn_Cal_CtrldVelRtnRtnCmdLimY[8];
extern CONST(float32, AUTOMATIC) CtrldVelRtn_Cal_CtrldVelRtnScaLpFilFrq;
extern CONST(boolean, AUTOMATIC) CtrldVelRtn_Cal_CtrldVelRtnTqGrdtScaEna;
extern CONST(u8p8, AUTOMATIC) CtrldVelRtn_Cal_CtrldVelRtnTqGrdtScaX[8][5];
extern CONST(u2p14, AUTOMATIC) CtrldVelRtn_Cal_CtrldVelRtnTqGrdtScaY[8][5];
extern CONST(u9p7, AUTOMATIC) CtrldVelRtn_Cal_CtrldVelRtnVehSpdScaBilnrSeln[5];
extern CONST(u12p4, AUTOMATIC) CtrldVelRtn_Cal_CtrldVelRtnVelErrScaBilnrSeln[7];
extern CONST(boolean, AUTOMATIC) CtrldVelRtn_Cal_CtrldVelRtnVelErrScaEna;
extern CONST(s10p5, AUTOMATIC) CtrldVelRtn_Cal_CtrldVelRtnVelErrScaX[8];
extern CONST(u2p14, AUTOMATIC) CtrldVelRtn_Cal_CtrldVelRtnVelErrScaY[8][7];
extern CONST(u2p14, AUTOMATIC) CtrldVelRtn_Cal_CtrldVelRtnVelErrVehSpdScaY[5];
extern CONST(u9p7, AUTOMATIC) CtrldVelRtn_Cal_CtrldVelRtnVelSpdTbl[8];
extern CONST(float32, AUTOMATIC) CtrldVelRtn_Cal_SysGlbPrmSysTqRat;

/* PIMs */
extern VAR(float32, AUTOMATIC) CtrldVelRtn_Pim_dCtrldVelRtnCtrlSca;
extern VAR(float32, AUTOMATIC) CtrldVelRtn_Pim_dCtrldVelRtnCtrlScaPreFild;
extern VAR(float32, AUTOMATIC) CtrldVelRtn_Pim_dCtrldVelRtnDampgCmd;
extern VAR(float32, AUTOMATIC) CtrldVelRtn_Pim_dCtrldVelRtnDesVel;
extern VAR(float32, AUTOMATIC) CtrldVelRtn_Pim_dCtrldVelRtnDesVelSca;
extern VAR(float32, AUTOMATIC) CtrldVelRtn_Pim_dCtrldVelRtnDesVelScaPreFild;
extern VAR(float32, AUTOMATIC) CtrldVelRtn_Pim_dCtrldVelRtnDrvrTqEstimd;
extern VAR(float32, AUTOMATIC) CtrldVelRtn_Pim_dCtrldVelRtnDrvrTqFild;
extern VAR(float32, AUTOMATIC) CtrldVelRtn_Pim_dCtrldVelRtnHwAgCmp;
extern VAR(float32, AUTOMATIC) CtrldVelRtn_Pim_dCtrldVelRtnHwAuthySca;
extern VAR(float32, AUTOMATIC) CtrldVelRtn_Pim_dCtrldVelRtnHwPosnSca;
extern VAR(float32, AUTOMATIC) CtrldVelRtn_Pim_dCtrldVelRtnHwTqSca;
extern VAR(float32, AUTOMATIC) CtrldVelRtn_Pim_dCtrldVelRtnHwTqScaSeln;
extern VAR(float32, AUTOMATIC) CtrldVelRtn_Pim_dCtrldVelRtnIntglTermCmd;
extern VAR(float32, AUTOMATIC) CtrldVelRtn_Pim_dCtrldVelRtnIntgrLim;
extern VAR(float32, AUTOMATIC) CtrldVelRtn_Pim_dCtrldVelRtnPinionTqSca;
extern VAR(float32, AUTOMATIC) CtrldVelRtn_Pim_dCtrldVelRtnPropTermCmd;
extern VAR(float32, AUTOMATIC) CtrldVelRtn_Pim_dCtrldVelRtnRtnCmd;
extern VAR(float32, AUTOMATIC) CtrldVelRtn_Pim_dCtrldVelRtnRtnCmdPreLim;
extern VAR(float32, AUTOMATIC) CtrldVelRtn_Pim_dCtrldVelRtnTqGrdt;
extern VAR(float32, AUTOMATIC) CtrldVelRtn_Pim_dCtrldVelRtnTqGrdtSca;
extern VAR(float32, AUTOMATIC) CtrldVelRtn_Pim_dCtrldVelRtnVelErrSca;
extern VAR(FilLpRec1, AUTOMATIC) CtrldVelRtn_Pim_CtrlScaLpFil;
extern VAR(FilLpRec1, AUTOMATIC) CtrldVelRtn_Pim_DesVelLpFil;
extern VAR(FilLpRec1, AUTOMATIC) CtrldVelRtn_Pim_DesVelScaLpFil;
extern VAR(FilLpRec1, AUTOMATIC) CtrldVelRtn_Pim_DrvrTqLpFil;
extern VAR(FilLpRec1, AUTOMATIC) CtrldVelRtn_Pim_PinionTqLpFil;
extern VAR(float32, AUTOMATIC) CtrldVelRtn_Pim_PrevDesVel;
extern VAR(float32, AUTOMATIC) CtrldVelRtn_Pim_PrevDrvrTqFildA;
extern VAR(float32, AUTOMATIC) CtrldVelRtn_Pim_PrevDrvrTqFildB;
extern VAR(float32, AUTOMATIC) CtrldVelRtn_Pim_PrevDrvrTqFildC;
extern VAR(float32, AUTOMATIC) CtrldVelRtn_Pim_PrevDrvrTqFildD;
extern VAR(float32, AUTOMATIC) CtrldVelRtn_Pim_PrevDrvrTqFildE;
extern VAR(float32, AUTOMATIC) CtrldVelRtn_Pim_PrevDrvrTqFildF;
extern VAR(float32, AUTOMATIC) CtrldVelRtn_Pim_PrevDrvrTqMtrx[5];
extern VAR(float32, AUTOMATIC) CtrldVelRtn_Pim_PrevHwAuthySca;
extern VAR(float32, AUTOMATIC) CtrldVelRtn_Pim_PrevHwTqSeln;
extern VAR(float32, AUTOMATIC) CtrldVelRtn_Pim_PrevIntglTermA;
extern VAR(float32, AUTOMATIC) CtrldVelRtn_Pim_PrevIntglTermB;
extern VAR(float32, AUTOMATIC) CtrldVelRtn_Pim_PrevIntglTermC;
extern VAR(float32, AUTOMATIC) CtrldVelRtn_Pim_PrevRtnOffs;

/* Arguments and Returns */


/*** Input Stubs ***/

#ifdef Rte_Read_AssiMechPolarity_Val
# undef Rte_Read_AssiMechPolarity_Val
#endif
#define Rte_Read_AssiMechPolarity_Val(data) (*(data) = CtrldVelRtn_Ip_AssiMechPolarity)

#ifdef Rte_Read_HwAg_Val
# undef Rte_Read_HwAg_Val
#endif
#define Rte_Read_HwAg_Val(data) (*(data) = CtrldVelRtn_Ip_HwAg)

#ifdef Rte_Read_HwAgAuthy_Val
# undef Rte_Read_HwAgAuthy_Val
#endif
#define Rte_Read_HwAgAuthy_Val(data) (*(data) = CtrldVelRtn_Ip_HwAgAuthy)

#ifdef Rte_Read_HwAgRtnOffs_Val
# undef Rte_Read_HwAgRtnOffs_Val
#endif
#define Rte_Read_HwAgRtnOffs_Val(data) (*(data) = CtrldVelRtn_Ip_HwAgRtnOffs)

#ifdef Rte_Read_HwTq_Val
# undef Rte_Read_HwTq_Val
#endif
#define Rte_Read_HwTq_Val(data) (*(data) = CtrldVelRtn_Ip_HwTq)

#ifdef Rte_Read_HwVel_Val
# undef Rte_Read_HwVel_Val
#endif
#define Rte_Read_HwVel_Val(data) (*(data) = CtrldVelRtn_Ip_HwVel)

#ifdef Rte_Read_MotTqCmdPwrLimd_Val
# undef Rte_Read_MotTqCmdPwrLimd_Val
#endif
#define Rte_Read_MotTqCmdPwrLimd_Val(data) (*(data) = CtrldVelRtn_Ip_MotTqCmdPwrLimd)

#ifdef Rte_Read_RtnCmdDi_Logl
# undef Rte_Read_RtnCmdDi_Logl
#endif
#define Rte_Read_RtnCmdDi_Logl(data) (*(data) = CtrldVelRtn_Ip_RtnCmdDi)

#ifdef Rte_Read_RtnCmdDiagcDi_Logl
# undef Rte_Read_RtnCmdDiagcDi_Logl
#endif
#define Rte_Read_RtnCmdDiagcDi_Logl(data) (*(data) = CtrldVelRtn_Ip_RtnCmdDiagcDi)

#ifdef Rte_Read_RtnCmdSca_Val
# undef Rte_Read_RtnCmdSca_Val
#endif
#define Rte_Read_RtnCmdSca_Val(data) (*(data) = CtrldVelRtn_Ip_RtnCmdSca)

#ifdef Rte_Read_RtnCmdScaServo_Val
# undef Rte_Read_RtnCmdScaServo_Val
#endif
#define Rte_Read_RtnCmdScaServo_Val(data) (*(data) = CtrldVelRtn_Ip_RtnCmdScaServo)

#ifdef Rte_Read_VehSpd_Val
# undef Rte_Read_VehSpd_Val
#endif
#define Rte_Read_VehSpd_Val(data) (*(data) = CtrldVelRtn_Ip_VehSpd)


/*** Output Stubs ***/

#ifdef Rte_Write_CtrldVelRtnCmd_Val
# undef Rte_Write_CtrldVelRtnCmd_Val
#endif
#define Rte_Write_CtrldVelRtnCmd_Val(data) (CtrldVelRtn_Op_CtrldVelRtnCmd = (data))


/*** Calibration Stubs ***/

#ifdef Rte_Prm_CtrldVelRtnAntiWdup_Val
# undef Rte_Prm_CtrldVelRtnAntiWdup_Val
#endif
#define Rte_Prm_CtrldVelRtnAntiWdup_Val() (CtrldVelRtn_Cal_CtrldVelRtnAntiWdup)

#ifdef Rte_Prm_CtrldVelRtnDampgEna_Logl
# undef Rte_Prm_CtrldVelRtnDampgEna_Logl
#endif
#define Rte_Prm_CtrldVelRtnDampgEna_Logl() (CtrldVelRtn_Cal_CtrldVelRtnDampgEna)

#ifdef Rte_Prm_CtrldVelRtnDampgScaEna_Logl
# undef Rte_Prm_CtrldVelRtnDampgScaEna_Logl
#endif
#define Rte_Prm_CtrldVelRtnDampgScaEna_Logl() (CtrldVelRtn_Cal_CtrldVelRtnDampgScaEna)

#ifdef Rte_Prm_CtrldVelRtnDampgX_Ary2D
# undef Rte_Prm_CtrldVelRtnDampgX_Ary2D
#endif
#define Rte_Prm_CtrldVelRtnDampgX_Ary2D() (&(CtrldVelRtn_Cal_CtrldVelRtnDampgX[0][0]))

#ifdef Rte_Prm_CtrldVelRtnDampgY_Ary2D
# undef Rte_Prm_CtrldVelRtnDampgY_Ary2D
#endif
#define Rte_Prm_CtrldVelRtnDampgY_Ary2D() (&(CtrldVelRtn_Cal_CtrldVelRtnDampgY[0][0]))

#ifdef Rte_Prm_CtrldVelRtnDesVelLpFilFrq_Val
# undef Rte_Prm_CtrldVelRtnDesVelLpFilFrq_Val
#endif
#define Rte_Prm_CtrldVelRtnDesVelLpFilFrq_Val() (CtrldVelRtn_Cal_CtrldVelRtnDesVelLpFilFrq)

#ifdef Rte_Prm_CtrldVelRtnDesVelScaX_Ary2D
# undef Rte_Prm_CtrldVelRtnDesVelScaX_Ary2D
#endif
#define Rte_Prm_CtrldVelRtnDesVelScaX_Ary2D() (&(CtrldVelRtn_Cal_CtrldVelRtnDesVelScaX[0][0]))

#ifdef Rte_Prm_CtrldVelRtnDesVelScaY_Ary2D
# undef Rte_Prm_CtrldVelRtnDesVelScaY_Ary2D
#endif
#define Rte_Prm_CtrldVelRtnDesVelScaY_Ary2D() (&(CtrldVelRtn_Cal_CtrldVelRtnDesVelScaY[0][0]))

#ifdef Rte_Prm_CtrldVelRtnDesVelX_Ary2D
# undef Rte_Prm_CtrldVelRtnDesVelX_Ary2D
#endif
#define Rte_Prm_CtrldVelRtnDesVelX_Ary2D() (&(CtrldVelRtn_Cal_CtrldVelRtnDesVelX[0][0]))

#ifdef Rte_Prm_CtrldVelRtnDesVelY_Ary2D
# undef Rte_Prm_CtrldVelRtnDesVelY_Ary2D
#endif
#define Rte_Prm_CtrldVelRtnDesVelY_Ary2D() (&(CtrldVelRtn_Cal_CtrldVelRtnDesVelY[0][0]))

#ifdef Rte_Prm_CtrldVelRtnDrvrTqEna_Logl
# undef Rte_Prm_CtrldVelRtnDrvrTqEna_Logl
#endif
#define Rte_Prm_CtrldVelRtnDrvrTqEna_Logl() (CtrldVelRtn_Cal_CtrldVelRtnDrvrTqEna)

#ifdef Rte_Prm_CtrldVelRtnDrvrTqMtrxA_Ary2D
# undef Rte_Prm_CtrldVelRtnDrvrTqMtrxA_Ary2D
#endif
#define Rte_Prm_CtrldVelRtnDrvrTqMtrxA_Ary2D() (&(CtrldVelRtn_Cal_CtrldVelRtnDrvrTqMtrxA[0][0]))

#ifdef Rte_Prm_CtrldVelRtnDrvrTqMtrxB_Ary2D
# undef Rte_Prm_CtrldVelRtnDrvrTqMtrxB_Ary2D
#endif
#define Rte_Prm_CtrldVelRtnDrvrTqMtrxB_Ary2D() (&(CtrldVelRtn_Cal_CtrldVelRtnDrvrTqMtrxB[0][0]))

#ifdef Rte_Prm_CtrldVelRtnDrvrTqMtrxC_Ary1D
# undef Rte_Prm_CtrldVelRtnDrvrTqMtrxC_Ary1D
#endif
#define Rte_Prm_CtrldVelRtnDrvrTqMtrxC_Ary1D() (&(CtrldVelRtn_Cal_CtrldVelRtnDrvrTqMtrxC[0]))

#ifdef Rte_Prm_CtrldVelRtnDrvrTqMtrxD_Ary1D
# undef Rte_Prm_CtrldVelRtnDrvrTqMtrxD_Ary1D
#endif
#define Rte_Prm_CtrldVelRtnDrvrTqMtrxD_Ary1D() (&(CtrldVelRtn_Cal_CtrldVelRtnDrvrTqMtrxD[0]))

#ifdef Rte_Prm_CtrldVelRtnHwAuthyScaX_Ary1D
# undef Rte_Prm_CtrldVelRtnHwAuthyScaX_Ary1D
#endif
#define Rte_Prm_CtrldVelRtnHwAuthyScaX_Ary1D() (&(CtrldVelRtn_Cal_CtrldVelRtnHwAuthyScaX[0]))

#ifdef Rte_Prm_CtrldVelRtnHwAuthyScaY_Ary1D
# undef Rte_Prm_CtrldVelRtnHwAuthyScaY_Ary1D
#endif
#define Rte_Prm_CtrldVelRtnHwAuthyScaY_Ary1D() (&(CtrldVelRtn_Cal_CtrldVelRtnHwAuthyScaY[0]))

#ifdef Rte_Prm_CtrldVelRtnHwAuthySlewThd_Val
# undef Rte_Prm_CtrldVelRtnHwAuthySlewThd_Val
#endif
#define Rte_Prm_CtrldVelRtnHwAuthySlewThd_Val() (CtrldVelRtn_Cal_CtrldVelRtnHwAuthySlewThd)

#ifdef Rte_Prm_CtrldVelRtnHwPosnScaX_Ary1D
# undef Rte_Prm_CtrldVelRtnHwPosnScaX_Ary1D
#endif
#define Rte_Prm_CtrldVelRtnHwPosnScaX_Ary1D() (&(CtrldVelRtn_Cal_CtrldVelRtnHwPosnScaX[0]))

#ifdef Rte_Prm_CtrldVelRtnHwPosnScaY_Ary2D
# undef Rte_Prm_CtrldVelRtnHwPosnScaY_Ary2D
#endif
#define Rte_Prm_CtrldVelRtnHwPosnScaY_Ary2D() (&(CtrldVelRtn_Cal_CtrldVelRtnHwPosnScaY[0][0]))

#ifdef Rte_Prm_CtrldVelRtnHwTqLpFilFrq_Val
# undef Rte_Prm_CtrldVelRtnHwTqLpFilFrq_Val
#endif
#define Rte_Prm_CtrldVelRtnHwTqLpFilFrq_Val() (CtrldVelRtn_Cal_CtrldVelRtnHwTqLpFilFrq)

#ifdef Rte_Prm_CtrldVelRtnHwTqSca1X_Ary2D
# undef Rte_Prm_CtrldVelRtnHwTqSca1X_Ary2D
#endif
#define Rte_Prm_CtrldVelRtnHwTqSca1X_Ary2D() (&(CtrldVelRtn_Cal_CtrldVelRtnHwTqSca1X[0][0]))

#ifdef Rte_Prm_CtrldVelRtnHwTqSca1Y_Ary2D
# undef Rte_Prm_CtrldVelRtnHwTqSca1Y_Ary2D
#endif
#define Rte_Prm_CtrldVelRtnHwTqSca1Y_Ary2D() (&(CtrldVelRtn_Cal_CtrldVelRtnHwTqSca1Y[0][0]))

#ifdef Rte_Prm_CtrldVelRtnHwTqSca2X_Ary2D
# undef Rte_Prm_CtrldVelRtnHwTqSca2X_Ary2D
#endif
#define Rte_Prm_CtrldVelRtnHwTqSca2X_Ary2D() (&(CtrldVelRtn_Cal_CtrldVelRtnHwTqSca2X[0][0]))

#ifdef Rte_Prm_CtrldVelRtnHwTqSca2Y_Ary2D
# undef Rte_Prm_CtrldVelRtnHwTqSca2Y_Ary2D
#endif
#define Rte_Prm_CtrldVelRtnHwTqSca2Y_Ary2D() (&(CtrldVelRtn_Cal_CtrldVelRtnHwTqSca2Y[0][0]))

#ifdef Rte_Prm_CtrldVelRtnHwTqScaSelnSlewHiLim_Val
# undef Rte_Prm_CtrldVelRtnHwTqScaSelnSlewHiLim_Val
#endif
#define Rte_Prm_CtrldVelRtnHwTqScaSelnSlewHiLim_Val() (CtrldVelRtn_Cal_CtrldVelRtnHwTqScaSelnSlewHiLim)

#ifdef Rte_Prm_CtrldVelRtnHwTqScaSelnSlewLoLim_Val
# undef Rte_Prm_CtrldVelRtnHwTqScaSelnSlewLoLim_Val
#endif
#define Rte_Prm_CtrldVelRtnHwTqScaSelnSlewLoLim_Val() (CtrldVelRtn_Cal_CtrldVelRtnHwTqScaSelnSlewLoLim)

#ifdef Rte_Prm_CtrldVelRtnHwTqScaSelnTqThd_Val
# undef Rte_Prm_CtrldVelRtnHwTqScaSelnTqThd_Val
#endif
#define Rte_Prm_CtrldVelRtnHwTqScaSelnTqThd_Val() (CtrldVelRtn_Cal_CtrldVelRtnHwTqScaSelnTqThd)

#ifdef Rte_Prm_CtrldVelRtnHwTqScaSelnVelThd_Val
# undef Rte_Prm_CtrldVelRtnHwTqScaSelnVelThd_Val
#endif
#define Rte_Prm_CtrldVelRtnHwTqScaSelnVelThd_Val() (CtrldVelRtn_Cal_CtrldVelRtnHwTqScaSelnVelThd)

#ifdef Rte_Prm_CtrldVelRtnIntglGain_Ary1D
# undef Rte_Prm_CtrldVelRtnIntglGain_Ary1D
#endif
#define Rte_Prm_CtrldVelRtnIntglGain_Ary1D() (&(CtrldVelRtn_Cal_CtrldVelRtnIntglGain[0]))

#ifdef Rte_Prm_CtrldVelRtnIntgrLimY_Ary2D
# undef Rte_Prm_CtrldVelRtnIntgrLimY_Ary2D
#endif
#define Rte_Prm_CtrldVelRtnIntgrLimY_Ary2D() (&(CtrldVelRtn_Cal_CtrldVelRtnIntgrLimY[0][0]))

#ifdef Rte_Prm_CtrldVelRtnOffsSlewThd_Val
# undef Rte_Prm_CtrldVelRtnOffsSlewThd_Val
#endif
#define Rte_Prm_CtrldVelRtnOffsSlewThd_Val() (CtrldVelRtn_Cal_CtrldVelRtnOffsSlewThd)

#ifdef Rte_Prm_CtrldVelRtnOffsThd_Val
# undef Rte_Prm_CtrldVelRtnOffsThd_Val
#endif
#define Rte_Prm_CtrldVelRtnOffsThd_Val() (CtrldVelRtn_Cal_CtrldVelRtnOffsThd)

#ifdef Rte_Prm_CtrldVelRtnPinionTqScaX_Ary2D
# undef Rte_Prm_CtrldVelRtnPinionTqScaX_Ary2D
#endif
#define Rte_Prm_CtrldVelRtnPinionTqScaX_Ary2D() (&(CtrldVelRtn_Cal_CtrldVelRtnPinionTqScaX[0][0]))

#ifdef Rte_Prm_CtrldVelRtnPinionTqScaY_Ary2D
# undef Rte_Prm_CtrldVelRtnPinionTqScaY_Ary2D
#endif
#define Rte_Prm_CtrldVelRtnPinionTqScaY_Ary2D() (&(CtrldVelRtn_Cal_CtrldVelRtnPinionTqScaY[0][0]))

#ifdef Rte_Prm_CtrldVelRtnPropGain_Ary1D
# undef Rte_Prm_CtrldVelRtnPropGain_Ary1D
#endif
#define Rte_Prm_CtrldVelRtnPropGain_Ary1D() (&(CtrldVelRtn_Cal_CtrldVelRtnPropGain[0]))

#ifdef Rte_Prm_CtrldVelRtnRtnCmdLimY_Ary1D
# undef Rte_Prm_CtrldVelRtnRtnCmdLimY_Ary1D
#endif
#define Rte_Prm_CtrldVelRtnRtnCmdLimY_Ary1D() (&(CtrldVelRtn_Cal_CtrldVelRtnRtnCmdLimY[0]))

#ifdef Rte_Prm_CtrldVelRtnScaLpFilFrq_Val
# undef Rte_Prm_CtrldVelRtnScaLpFilFrq_Val
#endif
#define Rte_Prm_CtrldVelRtnScaLpFilFrq_Val() (CtrldVelRtn_Cal_CtrldVelRtnScaLpFilFrq)

#ifdef Rte_Prm_CtrldVelRtnTqGrdtScaEna_Logl
# undef Rte_Prm_CtrldVelRtnTqGrdtScaEna_Logl
#endif
#define Rte_Prm_CtrldVelRtnTqGrdtScaEna_Logl() (CtrldVelRtn_Cal_CtrldVelRtnTqGrdtScaEna)

#ifdef Rte_Prm_CtrldVelRtnTqGrdtScaX_Ary2D
# undef Rte_Prm_CtrldVelRtnTqGrdtScaX_Ary2D
#endif
#define Rte_Prm_CtrldVelRtnTqGrdtScaX_Ary2D() (&(CtrldVelRtn_Cal_CtrldVelRtnTqGrdtScaX[0][0]))

#ifdef Rte_Prm_CtrldVelRtnTqGrdtScaY_Ary2D
# undef Rte_Prm_CtrldVelRtnTqGrdtScaY_Ary2D
#endif
#define Rte_Prm_CtrldVelRtnTqGrdtScaY_Ary2D() (&(CtrldVelRtn_Cal_CtrldVelRtnTqGrdtScaY[0][0]))

#ifdef Rte_Prm_CtrldVelRtnVehSpdScaBilnrSeln_Ary1D
# undef Rte_Prm_CtrldVelRtnVehSpdScaBilnrSeln_Ary1D
#endif
#define Rte_Prm_CtrldVelRtnVehSpdScaBilnrSeln_Ary1D() (&(CtrldVelRtn_Cal_CtrldVelRtnVehSpdScaBilnrSeln[0]))

#ifdef Rte_Prm_CtrldVelRtnVelErrScaBilnrSeln_Ary1D
# undef Rte_Prm_CtrldVelRtnVelErrScaBilnrSeln_Ary1D
#endif
#define Rte_Prm_CtrldVelRtnVelErrScaBilnrSeln_Ary1D() (&(CtrldVelRtn_Cal_CtrldVelRtnVelErrScaBilnrSeln[0]))

#ifdef Rte_Prm_CtrldVelRtnVelErrScaEna_Logl
# undef Rte_Prm_CtrldVelRtnVelErrScaEna_Logl
#endif
#define Rte_Prm_CtrldVelRtnVelErrScaEna_Logl() (CtrldVelRtn_Cal_CtrldVelRtnVelErrScaEna)

#ifdef Rte_Prm_CtrldVelRtnVelErrScaX_Ary1D
# undef Rte_Prm_CtrldVelRtnVelErrScaX_Ary1D
#endif
#define Rte_Prm_CtrldVelRtnVelErrScaX_Ary1D() (&(CtrldVelRtn_Cal_CtrldVelRtnVelErrScaX[0]))

#ifdef Rte_Prm_CtrldVelRtnVelErrScaY_Ary2D
# undef Rte_Prm_CtrldVelRtnVelErrScaY_Ary2D
#endif
#define Rte_Prm_CtrldVelRtnVelErrScaY_Ary2D() (&(CtrldVelRtn_Cal_CtrldVelRtnVelErrScaY[0][0]))

#ifdef Rte_Prm_CtrldVelRtnVelErrVehSpdScaY_Ary1D
# undef Rte_Prm_CtrldVelRtnVelErrVehSpdScaY_Ary1D
#endif
#define Rte_Prm_CtrldVelRtnVelErrVehSpdScaY_Ary1D() (&(CtrldVelRtn_Cal_CtrldVelRtnVelErrVehSpdScaY[0]))

#ifdef Rte_Prm_CtrldVelRtnVelSpdTbl_Ary1D
# undef Rte_Prm_CtrldVelRtnVelSpdTbl_Ary1D
#endif
#define Rte_Prm_CtrldVelRtnVelSpdTbl_Ary1D() (&(CtrldVelRtn_Cal_CtrldVelRtnVelSpdTbl[0]))

#ifdef Rte_Prm_SysGlbPrmSysTqRat_Val
# undef Rte_Prm_SysGlbPrmSysTqRat_Val
#endif
#define Rte_Prm_SysGlbPrmSysTqRat_Val() (CtrldVelRtn_Cal_SysGlbPrmSysTqRat)


/*** PIM Stubs ***/

#ifdef Rte_Pim_dCtrldVelRtnCtrlSca
# undef Rte_Pim_dCtrldVelRtnCtrlSca
#endif
#define Rte_Pim_dCtrldVelRtnCtrlSca() (&CtrldVelRtn_Pim_dCtrldVelRtnCtrlSca)

#ifdef Rte_Pim_dCtrldVelRtnCtrlScaPreFild
# undef Rte_Pim_dCtrldVelRtnCtrlScaPreFild
#endif
#define Rte_Pim_dCtrldVelRtnCtrlScaPreFild() (&CtrldVelRtn_Pim_dCtrldVelRtnCtrlScaPreFild)

#ifdef Rte_Pim_dCtrldVelRtnDampgCmd
# undef Rte_Pim_dCtrldVelRtnDampgCmd
#endif
#define Rte_Pim_dCtrldVelRtnDampgCmd() (&CtrldVelRtn_Pim_dCtrldVelRtnDampgCmd)

#ifdef Rte_Pim_dCtrldVelRtnDesVel
# undef Rte_Pim_dCtrldVelRtnDesVel
#endif
#define Rte_Pim_dCtrldVelRtnDesVel() (&CtrldVelRtn_Pim_dCtrldVelRtnDesVel)

#ifdef Rte_Pim_dCtrldVelRtnDesVelSca
# undef Rte_Pim_dCtrldVelRtnDesVelSca
#endif
#define Rte_Pim_dCtrldVelRtnDesVelSca() (&CtrldVelRtn_Pim_dCtrldVelRtnDesVelSca)

#ifdef Rte_Pim_dCtrldVelRtnDesVelScaPreFild
# undef Rte_Pim_dCtrldVelRtnDesVelScaPreFild
#endif
#define Rte_Pim_dCtrldVelRtnDesVelScaPreFild() (&CtrldVelRtn_Pim_dCtrldVelRtnDesVelScaPreFild)

#ifdef Rte_Pim_dCtrldVelRtnDrvrTqEstimd
# undef Rte_Pim_dCtrldVelRtnDrvrTqEstimd
#endif
#define Rte_Pim_dCtrldVelRtnDrvrTqEstimd() (&CtrldVelRtn_Pim_dCtrldVelRtnDrvrTqEstimd)

#ifdef Rte_Pim_dCtrldVelRtnDrvrTqFild
# undef Rte_Pim_dCtrldVelRtnDrvrTqFild
#endif
#define Rte_Pim_dCtrldVelRtnDrvrTqFild() (&CtrldVelRtn_Pim_dCtrldVelRtnDrvrTqFild)

#ifdef Rte_Pim_dCtrldVelRtnHwAgCmp
# undef Rte_Pim_dCtrldVelRtnHwAgCmp
#endif
#define Rte_Pim_dCtrldVelRtnHwAgCmp() (&CtrldVelRtn_Pim_dCtrldVelRtnHwAgCmp)

#ifdef Rte_Pim_dCtrldVelRtnHwAuthySca
# undef Rte_Pim_dCtrldVelRtnHwAuthySca
#endif
#define Rte_Pim_dCtrldVelRtnHwAuthySca() (&CtrldVelRtn_Pim_dCtrldVelRtnHwAuthySca)

#ifdef Rte_Pim_dCtrldVelRtnHwPosnSca
# undef Rte_Pim_dCtrldVelRtnHwPosnSca
#endif
#define Rte_Pim_dCtrldVelRtnHwPosnSca() (&CtrldVelRtn_Pim_dCtrldVelRtnHwPosnSca)

#ifdef Rte_Pim_dCtrldVelRtnHwTqSca
# undef Rte_Pim_dCtrldVelRtnHwTqSca
#endif
#define Rte_Pim_dCtrldVelRtnHwTqSca() (&CtrldVelRtn_Pim_dCtrldVelRtnHwTqSca)

#ifdef Rte_Pim_dCtrldVelRtnHwTqScaSeln
# undef Rte_Pim_dCtrldVelRtnHwTqScaSeln
#endif
#define Rte_Pim_dCtrldVelRtnHwTqScaSeln() (&CtrldVelRtn_Pim_dCtrldVelRtnHwTqScaSeln)

#ifdef Rte_Pim_dCtrldVelRtnIntglTermCmd
# undef Rte_Pim_dCtrldVelRtnIntglTermCmd
#endif
#define Rte_Pim_dCtrldVelRtnIntglTermCmd() (&CtrldVelRtn_Pim_dCtrldVelRtnIntglTermCmd)

#ifdef Rte_Pim_dCtrldVelRtnIntgrLim
# undef Rte_Pim_dCtrldVelRtnIntgrLim
#endif
#define Rte_Pim_dCtrldVelRtnIntgrLim() (&CtrldVelRtn_Pim_dCtrldVelRtnIntgrLim)

#ifdef Rte_Pim_dCtrldVelRtnPinionTqSca
# undef Rte_Pim_dCtrldVelRtnPinionTqSca
#endif
#define Rte_Pim_dCtrldVelRtnPinionTqSca() (&CtrldVelRtn_Pim_dCtrldVelRtnPinionTqSca)

#ifdef Rte_Pim_dCtrldVelRtnPropTermCmd
# undef Rte_Pim_dCtrldVelRtnPropTermCmd
#endif
#define Rte_Pim_dCtrldVelRtnPropTermCmd() (&CtrldVelRtn_Pim_dCtrldVelRtnPropTermCmd)

#ifdef Rte_Pim_dCtrldVelRtnRtnCmd
# undef Rte_Pim_dCtrldVelRtnRtnCmd
#endif
#define Rte_Pim_dCtrldVelRtnRtnCmd() (&CtrldVelRtn_Pim_dCtrldVelRtnRtnCmd)

#ifdef Rte_Pim_dCtrldVelRtnRtnCmdPreLim
# undef Rte_Pim_dCtrldVelRtnRtnCmdPreLim
#endif
#define Rte_Pim_dCtrldVelRtnRtnCmdPreLim() (&CtrldVelRtn_Pim_dCtrldVelRtnRtnCmdPreLim)

#ifdef Rte_Pim_dCtrldVelRtnTqGrdt
# undef Rte_Pim_dCtrldVelRtnTqGrdt
#endif
#define Rte_Pim_dCtrldVelRtnTqGrdt() (&CtrldVelRtn_Pim_dCtrldVelRtnTqGrdt)

#ifdef Rte_Pim_dCtrldVelRtnTqGrdtSca
# undef Rte_Pim_dCtrldVelRtnTqGrdtSca
#endif
#define Rte_Pim_dCtrldVelRtnTqGrdtSca() (&CtrldVelRtn_Pim_dCtrldVelRtnTqGrdtSca)

#ifdef Rte_Pim_dCtrldVelRtnVelErrSca
# undef Rte_Pim_dCtrldVelRtnVelErrSca
#endif
#define Rte_Pim_dCtrldVelRtnVelErrSca() (&CtrldVelRtn_Pim_dCtrldVelRtnVelErrSca)

#ifdef Rte_Pim_CtrlScaLpFil
# undef Rte_Pim_CtrlScaLpFil
#endif
#define Rte_Pim_CtrlScaLpFil() (&CtrldVelRtn_Pim_CtrlScaLpFil)

#ifdef Rte_Pim_DesVelLpFil
# undef Rte_Pim_DesVelLpFil
#endif
#define Rte_Pim_DesVelLpFil() (&CtrldVelRtn_Pim_DesVelLpFil)

#ifdef Rte_Pim_DesVelScaLpFil
# undef Rte_Pim_DesVelScaLpFil
#endif
#define Rte_Pim_DesVelScaLpFil() (&CtrldVelRtn_Pim_DesVelScaLpFil)

#ifdef Rte_Pim_DrvrTqLpFil
# undef Rte_Pim_DrvrTqLpFil
#endif
#define Rte_Pim_DrvrTqLpFil() (&CtrldVelRtn_Pim_DrvrTqLpFil)

#ifdef Rte_Pim_PinionTqLpFil
# undef Rte_Pim_PinionTqLpFil
#endif
#define Rte_Pim_PinionTqLpFil() (&CtrldVelRtn_Pim_PinionTqLpFil)

#ifdef Rte_Pim_PrevDesVel
# undef Rte_Pim_PrevDesVel
#endif
#define Rte_Pim_PrevDesVel() (&CtrldVelRtn_Pim_PrevDesVel)

#ifdef Rte_Pim_PrevDrvrTqFildA
# undef Rte_Pim_PrevDrvrTqFildA
#endif
#define Rte_Pim_PrevDrvrTqFildA() (&CtrldVelRtn_Pim_PrevDrvrTqFildA)

#ifdef Rte_Pim_PrevDrvrTqFildB
# undef Rte_Pim_PrevDrvrTqFildB
#endif
#define Rte_Pim_PrevDrvrTqFildB() (&CtrldVelRtn_Pim_PrevDrvrTqFildB)

#ifdef Rte_Pim_PrevDrvrTqFildC
# undef Rte_Pim_PrevDrvrTqFildC
#endif
#define Rte_Pim_PrevDrvrTqFildC() (&CtrldVelRtn_Pim_PrevDrvrTqFildC)

#ifdef Rte_Pim_PrevDrvrTqFildD
# undef Rte_Pim_PrevDrvrTqFildD
#endif
#define Rte_Pim_PrevDrvrTqFildD() (&CtrldVelRtn_Pim_PrevDrvrTqFildD)

#ifdef Rte_Pim_PrevDrvrTqFildE
# undef Rte_Pim_PrevDrvrTqFildE
#endif
#define Rte_Pim_PrevDrvrTqFildE() (&CtrldVelRtn_Pim_PrevDrvrTqFildE)

#ifdef Rte_Pim_PrevDrvrTqFildF
# undef Rte_Pim_PrevDrvrTqFildF
#endif
#define Rte_Pim_PrevDrvrTqFildF() (&CtrldVelRtn_Pim_PrevDrvrTqFildF)

#ifdef Rte_Pim_PrevDrvrTqMtrx
# undef Rte_Pim_PrevDrvrTqMtrx
#endif
#define Rte_Pim_PrevDrvrTqMtrx() (&(CtrldVelRtn_Pim_PrevDrvrTqMtrx[0]))

#ifdef Rte_Pim_PrevHwAuthySca
# undef Rte_Pim_PrevHwAuthySca
#endif
#define Rte_Pim_PrevHwAuthySca() (&CtrldVelRtn_Pim_PrevHwAuthySca)

#ifdef Rte_Pim_PrevHwTqSeln
# undef Rte_Pim_PrevHwTqSeln
#endif
#define Rte_Pim_PrevHwTqSeln() (&CtrldVelRtn_Pim_PrevHwTqSeln)

#ifdef Rte_Pim_PrevIntglTermA
# undef Rte_Pim_PrevIntglTermA
#endif
#define Rte_Pim_PrevIntglTermA() (&CtrldVelRtn_Pim_PrevIntglTermA)

#ifdef Rte_Pim_PrevIntglTermB
# undef Rte_Pim_PrevIntglTermB
#endif
#define Rte_Pim_PrevIntglTermB() (&CtrldVelRtn_Pim_PrevIntglTermB)

#ifdef Rte_Pim_PrevIntglTermC
# undef Rte_Pim_PrevIntglTermC
#endif
#define Rte_Pim_PrevIntglTermC() (&CtrldVelRtn_Pim_PrevIntglTermC)

#ifdef Rte_Pim_PrevRtnOffs
# undef Rte_Pim_PrevRtnOffs
#endif
#define Rte_Pim_PrevRtnOffs() (&CtrldVelRtn_Pim_PrevRtnOffs)


/*** Client Stub ***/

extern FUNC(void, AUTOMATIC) Rte_Stub(void);


#endif
