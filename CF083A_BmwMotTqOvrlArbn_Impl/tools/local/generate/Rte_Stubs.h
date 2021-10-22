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
extern VAR(BmwNearStillVehSpdSts1, AUTOMATIC) BmwMotTqOvrlArbn_Ip_BmwNearStillVehSpdSts;
extern VAR(float32, AUTOMATIC) BmwMotTqOvrlArbn_Ip_BmwOutpTqOvrlCmd;
extern VAR(BmwTrfcJamAssiSt1, AUTOMATIC) BmwMotTqOvrlArbn_Ip_BmwTrfcJamAssiDampgSt;
extern VAR(boolean, AUTOMATIC) BmwMotTqOvrlArbn_Ip_DrvgDynActv;
extern VAR(boolean, AUTOMATIC) BmwMotTqOvrlArbn_Ip_HwOscnActv;
extern VAR(float32, AUTOMATIC) BmwMotTqOvrlArbn_Ip_HwOscnCmd;
extern VAR(boolean, AUTOMATIC) BmwMotTqOvrlArbn_Ip_HwOscnDcThdExcdd;
extern VAR(float32, AUTOMATIC) BmwMotTqOvrlArbn_Ip_PinionCentrLrnCmd;
extern VAR(boolean, AUTOMATIC) BmwMotTqOvrlArbn_Ip_PinionCentrLrnEna;
extern VAR(float32, AUTOMATIC) BmwMotTqOvrlArbn_Ip_PosnServoCmd;
extern VAR(boolean, AUTOMATIC) BmwMotTqOvrlArbn_Ip_PosnServoEna;
extern VAR(float32, AUTOMATIC) BmwMotTqOvrlArbn_Ip_PullCmpCmd;
extern VAR(float32, AUTOMATIC) BmwMotTqOvrlArbn_Ip_TrfcJamAssiCmd;
extern VAR(float32, AUTOMATIC) BmwMotTqOvrlArbn_Ip_VehSpd;

/* Outputs */
extern VAR(float32, AUTOMATIC) BmwMotTqOvrlArbn_Op_MotTqOvrlCmd;

/* Calibrations */
extern CONST(uint16, AUTOMATIC) BmwMotTqOvrlArbn_Cal_BmwMotTqOvrlArbnBmwNearStillVehSpdStsRefTiThd;
extern CONST(uint16, AUTOMATIC) BmwMotTqOvrlArbn_Cal_BmwMotTqOvrlArbnMfgModCmdRefTiThd;
extern CONST(float32, AUTOMATIC) BmwMotTqOvrlArbn_Cal_BmwMotTqOvrlArbnMfgModCmdThd;
extern CONST(float32, AUTOMATIC) BmwMotTqOvrlArbn_Cal_BmwMotTqOvrlArbnMfgModVehSpdThd;
extern CONST(float32, AUTOMATIC) BmwMotTqOvrlArbn_Cal_BmwMotTqOvrlArbnPullCmpCmdLim;
extern CONST(uint16, AUTOMATIC) BmwMotTqOvrlArbn_Cal_BmwMotTqOvrlArbnVehSpdRefTiThd;

/* PIMs */
extern VAR(uint32, AUTOMATIC) BmwMotTqOvrlArbn_Pim_BmwNearStillVehSpdStsCdnRefTi;
extern VAR(boolean, AUTOMATIC) BmwMotTqOvrlArbn_Pim_FctlErrStVari;
extern VAR(uint32, AUTOMATIC) BmwMotTqOvrlArbn_Pim_MfgModCmdCdnRefTi;
extern VAR(uint32, AUTOMATIC) BmwMotTqOvrlArbn_Pim_VehSpdCdnRefTi;

/* Arguments and Returns */
extern VAR(uint32, AUTOMATIC) BmwMotTqOvrlArbn_Srv_GetRefTmr100MicroSec32bit_RefTmr;
extern VAR(uint32, AUTOMATIC) BmwMotTqOvrlArbn_Srv_GetTiSpan100MicroSec32bit_RefTmr;
extern VAR(uint32, AUTOMATIC) BmwMotTqOvrlArbn_Srv_GetTiSpan100MicroSec32bit_TiSpan;


/*** Input Stubs ***/

#ifdef Rte_Read_BmwNearStillVehSpdSts_Val
# undef Rte_Read_BmwNearStillVehSpdSts_Val
#else
#error Rte_Read_BmwNearStillVehSpdSts_Val is missing
#endif
#define Rte_Read_BmwNearStillVehSpdSts_Val(data) (*(data) = BmwMotTqOvrlArbn_Ip_BmwNearStillVehSpdSts)

#ifdef Rte_Read_BmwOutpTqOvrlCmd_Val
# undef Rte_Read_BmwOutpTqOvrlCmd_Val
#else
#error Rte_Read_BmwOutpTqOvrlCmd_Val is missing
#endif
#define Rte_Read_BmwOutpTqOvrlCmd_Val(data) (*(data) = BmwMotTqOvrlArbn_Ip_BmwOutpTqOvrlCmd)

#ifdef Rte_Read_BmwTrfcJamAssiDampgSt_Val
# undef Rte_Read_BmwTrfcJamAssiDampgSt_Val
#else
#error Rte_Read_BmwTrfcJamAssiDampgSt_Val is missing
#endif
#define Rte_Read_BmwTrfcJamAssiDampgSt_Val(data) (*(data) = BmwMotTqOvrlArbn_Ip_BmwTrfcJamAssiDampgSt)

#ifdef Rte_Read_DrvgDynActv_Logl
# undef Rte_Read_DrvgDynActv_Logl
#else
#error Rte_Read_DrvgDynActv_Logl is missing
#endif
#define Rte_Read_DrvgDynActv_Logl(data) (*(data) = BmwMotTqOvrlArbn_Ip_DrvgDynActv)

#ifdef Rte_Read_HwOscnActv_Logl
# undef Rte_Read_HwOscnActv_Logl
#else
#error Rte_Read_HwOscnActv_Logl is missing
#endif
#define Rte_Read_HwOscnActv_Logl(data) (*(data) = BmwMotTqOvrlArbn_Ip_HwOscnActv)

#ifdef Rte_Read_HwOscnCmd_Val
# undef Rte_Read_HwOscnCmd_Val
#else
#error Rte_Read_HwOscnCmd_Val is missing
#endif
#define Rte_Read_HwOscnCmd_Val(data) (*(data) = BmwMotTqOvrlArbn_Ip_HwOscnCmd)

#ifdef Rte_Read_HwOscnDcThdExcdd_Logl
# undef Rte_Read_HwOscnDcThdExcdd_Logl
#else
#error Rte_Read_HwOscnDcThdExcdd_Logl is missing
#endif
#define Rte_Read_HwOscnDcThdExcdd_Logl(data) (*(data) = BmwMotTqOvrlArbn_Ip_HwOscnDcThdExcdd)

#ifdef Rte_Read_PinionCentrLrnCmd_Val
# undef Rte_Read_PinionCentrLrnCmd_Val
#else
#error Rte_Read_PinionCentrLrnCmd_Val is missing
#endif
#define Rte_Read_PinionCentrLrnCmd_Val(data) (*(data) = BmwMotTqOvrlArbn_Ip_PinionCentrLrnCmd)

#ifdef Rte_Read_PinionCentrLrnEna_Logl
# undef Rte_Read_PinionCentrLrnEna_Logl
#else
#error Rte_Read_PinionCentrLrnEna_Logl is missing
#endif
#define Rte_Read_PinionCentrLrnEna_Logl(data) (*(data) = BmwMotTqOvrlArbn_Ip_PinionCentrLrnEna)

#ifdef Rte_Read_PosnServoCmd_Val
# undef Rte_Read_PosnServoCmd_Val
#else
#error Rte_Read_PosnServoCmd_Val is missing
#endif
#define Rte_Read_PosnServoCmd_Val(data) (*(data) = BmwMotTqOvrlArbn_Ip_PosnServoCmd)

#ifdef Rte_Read_PosnServoEna_Logl
# undef Rte_Read_PosnServoEna_Logl
#else
#error Rte_Read_PosnServoEna_Logl is missing
#endif
#define Rte_Read_PosnServoEna_Logl(data) (*(data) = BmwMotTqOvrlArbn_Ip_PosnServoEna)

#ifdef Rte_Read_PullCmpCmd_Val
# undef Rte_Read_PullCmpCmd_Val
#else
#error Rte_Read_PullCmpCmd_Val is missing
#endif
#define Rte_Read_PullCmpCmd_Val(data) (*(data) = BmwMotTqOvrlArbn_Ip_PullCmpCmd)

#ifdef Rte_Read_TrfcJamAssiCmd_Val
# undef Rte_Read_TrfcJamAssiCmd_Val
#else
#error Rte_Read_TrfcJamAssiCmd_Val is missing
#endif
#define Rte_Read_TrfcJamAssiCmd_Val(data) (*(data) = BmwMotTqOvrlArbn_Ip_TrfcJamAssiCmd)

#ifdef Rte_Read_VehSpd_Val
# undef Rte_Read_VehSpd_Val
#else
#error Rte_Read_VehSpd_Val is missing
#endif
#define Rte_Read_VehSpd_Val(data) (*(data) = BmwMotTqOvrlArbn_Ip_VehSpd)


/*** Output Stubs ***/

#ifdef Rte_Write_MotTqOvrlCmd_Val
# undef Rte_Write_MotTqOvrlCmd_Val
#else
#error Rte_Write_MotTqOvrlCmd_Val is missing
#endif
#define Rte_Write_MotTqOvrlCmd_Val(data) (BmwMotTqOvrlArbn_Op_MotTqOvrlCmd = (data))


/*** Calibration Stubs ***/

#ifdef Rte_Prm_BmwMotTqOvrlArbnBmwNearStillVehSpdStsRefTiThd_Val
# undef Rte_Prm_BmwMotTqOvrlArbnBmwNearStillVehSpdStsRefTiThd_Val
#else
#error Rte_Prm_BmwMotTqOvrlArbnBmwNearStillVehSpdStsRefTiThd_Val is missing
#endif
#define Rte_Prm_BmwMotTqOvrlArbnBmwNearStillVehSpdStsRefTiThd_Val() (BmwMotTqOvrlArbn_Cal_BmwMotTqOvrlArbnBmwNearStillVehSpdStsRefTiThd)

#ifdef Rte_Prm_BmwMotTqOvrlArbnMfgModCmdRefTiThd_Val
# undef Rte_Prm_BmwMotTqOvrlArbnMfgModCmdRefTiThd_Val
#else
#error Rte_Prm_BmwMotTqOvrlArbnMfgModCmdRefTiThd_Val is missing
#endif
#define Rte_Prm_BmwMotTqOvrlArbnMfgModCmdRefTiThd_Val() (BmwMotTqOvrlArbn_Cal_BmwMotTqOvrlArbnMfgModCmdRefTiThd)

#ifdef Rte_Prm_BmwMotTqOvrlArbnMfgModCmdThd_Val
# undef Rte_Prm_BmwMotTqOvrlArbnMfgModCmdThd_Val
#else
#error Rte_Prm_BmwMotTqOvrlArbnMfgModCmdThd_Val is missing
#endif
#define Rte_Prm_BmwMotTqOvrlArbnMfgModCmdThd_Val() (BmwMotTqOvrlArbn_Cal_BmwMotTqOvrlArbnMfgModCmdThd)

#ifdef Rte_Prm_BmwMotTqOvrlArbnMfgModVehSpdThd_Val
# undef Rte_Prm_BmwMotTqOvrlArbnMfgModVehSpdThd_Val
#else
#error Rte_Prm_BmwMotTqOvrlArbnMfgModVehSpdThd_Val is missing
#endif
#define Rte_Prm_BmwMotTqOvrlArbnMfgModVehSpdThd_Val() (BmwMotTqOvrlArbn_Cal_BmwMotTqOvrlArbnMfgModVehSpdThd)

#ifdef Rte_Prm_BmwMotTqOvrlArbnPullCmpCmdLim_Val
# undef Rte_Prm_BmwMotTqOvrlArbnPullCmpCmdLim_Val
#else
#error Rte_Prm_BmwMotTqOvrlArbnPullCmpCmdLim_Val is missing
#endif
#define Rte_Prm_BmwMotTqOvrlArbnPullCmpCmdLim_Val() (BmwMotTqOvrlArbn_Cal_BmwMotTqOvrlArbnPullCmpCmdLim)

#ifdef Rte_Prm_BmwMotTqOvrlArbnVehSpdRefTiThd_Val
# undef Rte_Prm_BmwMotTqOvrlArbnVehSpdRefTiThd_Val
#else
#error Rte_Prm_BmwMotTqOvrlArbnVehSpdRefTiThd_Val is missing
#endif
#define Rte_Prm_BmwMotTqOvrlArbnVehSpdRefTiThd_Val() (BmwMotTqOvrlArbn_Cal_BmwMotTqOvrlArbnVehSpdRefTiThd)


/*** PIM Stubs ***/

#ifdef Rte_Pim_BmwNearStillVehSpdStsCdnRefTi
# undef Rte_Pim_BmwNearStillVehSpdStsCdnRefTi
#else
#error Rte_Pim_BmwNearStillVehSpdStsCdnRefTi is missing
#endif
#define Rte_Pim_BmwNearStillVehSpdStsCdnRefTi() (&BmwMotTqOvrlArbn_Pim_BmwNearStillVehSpdStsCdnRefTi)

#ifdef Rte_Pim_FctlErrStVari
# undef Rte_Pim_FctlErrStVari
#else
#error Rte_Pim_FctlErrStVari is missing
#endif
#define Rte_Pim_FctlErrStVari() (&BmwMotTqOvrlArbn_Pim_FctlErrStVari)

#ifdef Rte_Pim_MfgModCmdCdnRefTi
# undef Rte_Pim_MfgModCmdCdnRefTi
#else
#error Rte_Pim_MfgModCmdCdnRefTi is missing
#endif
#define Rte_Pim_MfgModCmdCdnRefTi() (&BmwMotTqOvrlArbn_Pim_MfgModCmdCdnRefTi)

#ifdef Rte_Pim_VehSpdCdnRefTi
# undef Rte_Pim_VehSpdCdnRefTi
#else
#error Rte_Pim_VehSpdCdnRefTi is missing
#endif
#define Rte_Pim_VehSpdCdnRefTi() (&BmwMotTqOvrlArbn_Pim_VehSpdCdnRefTi)


/*** Client Stub ***/

extern FUNC(void, AUTOMATIC) Rte_Stub(void);


#endif
