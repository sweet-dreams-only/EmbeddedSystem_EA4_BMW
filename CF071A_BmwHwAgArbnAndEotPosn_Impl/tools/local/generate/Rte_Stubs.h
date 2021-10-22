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
extern VAR(float32, AUTOMATIC) BmwHwAgArbnAndEotPosn_Ip_BmwHwAgOffs;
extern VAR(float32, AUTOMATIC) BmwHwAgArbnAndEotPosn_Ip_BmwPinionAgOffs;
extern VAR(BmwPinionAgOffsSts1, AUTOMATIC) BmwHwAgArbnAndEotPosn_Ip_BmwPinionAgOffsSts;
extern VAR(BmwQuadOffsSts1, AUTOMATIC) BmwHwAgArbnAndEotPosn_Ip_BmwQuadOffsSts;
extern VAR(boolean, AUTOMATIC) BmwHwAgArbnAndEotPosn_Ip_BmwQuadOffsStsVld;
extern VAR(sint8, AUTOMATIC) BmwHwAgArbnAndEotPosn_Ip_BmwQuadRotorOffs;
extern VAR(boolean, AUTOMATIC) BmwHwAgArbnAndEotPosn_Ip_BmwQuadRotorOffsVld;
extern VAR(BmwVehSpdSts1, AUTOMATIC) BmwHwAgArbnAndEotPosn_Ip_BmwVehSpdSts;
extern VAR(float32, AUTOMATIC) BmwHwAgArbnAndEotPosn_Ip_CmplncErrMotToPinion;
extern VAR(boolean, AUTOMATIC) BmwHwAgArbnAndEotPosn_Ip_DiKineIntegrityTest;
extern VAR(boolean, AUTOMATIC) BmwHwAgArbnAndEotPosn_Ip_LongTermRackCentrCmpl;
extern VAR(s18p13, AUTOMATIC) BmwHwAgArbnAndEotPosn_Ip_MotAgCumvAlgndMrf;
extern VAR(uint8, AUTOMATIC) BmwHwAgArbnAndEotPosn_Ip_MotAgMeclCorrlnSt;
extern VAR(float32, AUTOMATIC) BmwHwAgArbnAndEotPosn_Ip_MotAgTurnCntr;
extern VAR(float32, AUTOMATIC) BmwHwAgArbnAndEotPosn_Ip_RackCentrPinionAg;
extern VAR(float32, AUTOMATIC) BmwHwAgArbnAndEotPosn_Ip_TotRackTrvl;
extern VAR(uint8, AUTOMATIC) BmwHwAgArbnAndEotPosn_Ip_TurnCntrCorrlnSts;
extern VAR(float32, AUTOMATIC) BmwHwAgArbnAndEotPosn_Ip_VehSpd;
extern VAR(boolean, AUTOMATIC) BmwHwAgArbnAndEotPosn_Ip_VehSpdVld;

/* Outputs */
extern VAR(float32, AUTOMATIC) BmwHwAgArbnAndEotPosn_Op_AlgndPinionAg;
extern VAR(float32, AUTOMATIC) BmwHwAgArbnAndEotPosn_Op_BmwPinionAg;
extern VAR(BmwPinionAgQlfr1, AUTOMATIC) BmwHwAgArbnAndEotPosn_Op_BmwPinionAgQlfr;
extern VAR(float32, AUTOMATIC) BmwHwAgArbnAndEotPosn_Op_BmwRackCentrToVehCentrOffs;
extern VAR(boolean, AUTOMATIC) BmwHwAgArbnAndEotPosn_Op_BmwRackCentrToVehCentrOffsVld;
extern VAR(boolean, AUTOMATIC) BmwHwAgArbnAndEotPosn_Op_HwAgCcwDetd;
extern VAR(boolean, AUTOMATIC) BmwHwAgArbnAndEotPosn_Op_HwAgCwDetd;
extern VAR(float32, AUTOMATIC) BmwHwAgArbnAndEotPosn_Op_HwAgEotCcw;
extern VAR(float32, AUTOMATIC) BmwHwAgArbnAndEotPosn_Op_HwAgEotCw;
extern VAR(boolean, AUTOMATIC) BmwHwAgArbnAndEotPosn_Op_LongTermVehCentrCmpl;
extern VAR(float32, AUTOMATIC) BmwHwAgArbnAndEotPosn_Op_OffsCmpdPinionAg;
extern VAR(float32, AUTOMATIC) BmwHwAgArbnAndEotPosn_Op_PinionAg;
extern VAR(float32, AUTOMATIC) BmwHwAgArbnAndEotPosn_Op_PinionAgConf;

/* Calibrations */
extern CONST(uint16, AUTOMATIC) BmwHwAgArbnAndEotPosn_Cal_BmwHwAgArbnAndEotPosnAllwExitFromInit;
extern CONST(float32, AUTOMATIC) BmwHwAgArbnAndEotPosn_Cal_BmwHwAgArbnAndEotPosnBmwPinionAgOffsLim;
extern CONST(float32, AUTOMATIC) BmwHwAgArbnAndEotPosn_Cal_BmwHwAgArbnAndEotPosnBmwPinionAgOffsRateLim;
extern CONST(float32, AUTOMATIC) BmwHwAgArbnAndEotPosn_Cal_BmwHwAgArbnAndEotPosnEotCcwMax;
extern CONST(float32, AUTOMATIC) BmwHwAgArbnAndEotPosn_Cal_BmwHwAgArbnAndEotPosnEotCcwMin;
extern CONST(float32, AUTOMATIC) BmwHwAgArbnAndEotPosn_Cal_BmwHwAgArbnAndEotPosnEotCwMax;
extern CONST(float32, AUTOMATIC) BmwHwAgArbnAndEotPosn_Cal_BmwHwAgArbnAndEotPosnEotCwMin;
extern CONST(float32, AUTOMATIC) BmwHwAgArbnAndEotPosn_Cal_BmwHwAgArbnAndEotPosnKineIntegrityDiagcMaxRackLim;
extern CONST(float32, AUTOMATIC) BmwHwAgArbnAndEotPosn_Cal_BmwHwAgArbnAndEotPosnMinVehSpdReqdVldAbsPos;
extern CONST(uint32, AUTOMATIC) BmwHwAgArbnAndEotPosn_Cal_BmwHwAgArbnAndEotPosnMotPosnDegArbdBlnd;
extern CONST(float32, AUTOMATIC) BmwHwAgArbnAndEotPosn_Cal_BmwHwAgArbnAndEotPosnMotToHwResl;
extern CONST(float32, AUTOMATIC) BmwHwAgArbnAndEotPosn_Cal_BmwHwAgArbnAndEotPosnOffsAuthy;
extern CONST(float32, AUTOMATIC) BmwHwAgArbnAndEotPosn_Cal_BmwHwAgArbnAndEotPosnOffsCorrnAuthy;
extern CONST(uint16, AUTOMATIC) BmwHwAgArbnAndEotPosn_Cal_BmwHwAgArbnAndEotPosnOffsCorrnTmrThd;
extern CONST(float32, AUTOMATIC) BmwHwAgArbnAndEotPosn_Cal_BmwHwAgArbnAndEotPosnPinionAgConfRampDwnRate;
extern CONST(float32, AUTOMATIC) BmwHwAgArbnAndEotPosn_Cal_BmwHwAgArbnAndEotPosnPinionAgConfRampUpRate;
extern CONST(float32, AUTOMATIC) BmwHwAgArbnAndEotPosn_Cal_BmwHwAgArbnAndEotPosnPinionAgDifThd;
extern CONST(float32, AUTOMATIC) BmwHwAgArbnAndEotPosn_Cal_BmwHwAgArbnAndEotPosnPinionAgFilFrq;
extern CONST(uint16, AUTOMATIC) BmwHwAgArbnAndEotPosn_Cal_BmwHwAgArbnAndEotPosnPinionAgFltTmrThd;
extern CONST(boolean, AUTOMATIC) BmwHwAgArbnAndEotPosn_Cal_BmwHwAgArbnAndEotPosnSysPolarityAssi;
extern CONST(float32, AUTOMATIC) BmwHwAgArbnAndEotPosn_Cal_BmwHwAgArbnAndEotPosnTmpCmpdAuthy;
extern CONST(float32, AUTOMATIC) BmwHwAgArbnAndEotPosn_Cal_BmwHwAgArbnAndEotPosnTurnCntrAuthy;
extern CONST(uint32, AUTOMATIC) BmwHwAgArbnAndEotPosn_Cal_BmwHwAgArbnAndEotPosnTurnCntrCorrlnStsTmrThd;
extern CONST(float32, AUTOMATIC) BmwHwAgArbnAndEotPosn_Cal_SysGlbPrmSysKineRat;

/* PIMs */
extern VAR(BmwVehCentrOffsRec1, AUTOMATIC) BmwHwAgArbnAndEotPosn_Pim_BmwVehCentrOffs;
extern VAR(uint8, AUTOMATIC) BmwHwAgArbnAndEotPosn_Pim_dBmwHwAgArbnAndEotPosnBmwMotAgSelnSt;
extern VAR(uint32, AUTOMATIC) BmwHwAgArbnAndEotPosn_Pim_AllwExitFromInitTi;
extern VAR(float32, AUTOMATIC) BmwHwAgArbnAndEotPosn_Pim_BmwPinionAgOffsRateLim;
extern VAR(BmwRackToVehCentrOffsSts1, AUTOMATIC) BmwHwAgArbnAndEotPosn_Pim_BmwRackCentrToVehCentrOffsSts;
extern VAR(boolean, AUTOMATIC) BmwHwAgArbnAndEotPosn_Pim_ClrNotCmplPinionAgFlg;
extern VAR(float32, AUTOMATIC) BmwHwAgArbnAndEotPosn_Pim_CurrAlgndPinionAg;
extern VAR(boolean, AUTOMATIC) BmwHwAgArbnAndEotPosn_Pim_CurrDftPinionAgFltPrsnt;
extern VAR(boolean, AUTOMATIC) BmwHwAgArbnAndEotPosn_Pim_DynStabyCtrlCdn;
extern VAR(uint8, AUTOMATIC) BmwHwAgArbnAndEotPosn_Pim_FirstLoopIndcr;
extern VAR(uint8, AUTOMATIC) BmwHwAgArbnAndEotPosn_Pim_IniTurnCntrCorrlnSts;
extern VAR(boolean, AUTOMATIC) BmwHwAgArbnAndEotPosn_Pim_KineIntegrityFlt;
extern VAR(boolean, AUTOMATIC) BmwHwAgArbnAndEotPosn_Pim_LpFilActvd;
extern VAR(boolean, AUTOMATIC) BmwHwAgArbnAndEotPosn_Pim_MotPosnDegArbdBlndFac;
extern VAR(uint32, AUTOMATIC) BmwHwAgArbnAndEotPosn_Pim_MotPosnDegArbdBlndTi;
extern VAR(uint32, AUTOMATIC) BmwHwAgArbnAndEotPosn_Pim_OffsCorrnRefTi;
extern VAR(float32, AUTOMATIC) BmwHwAgArbnAndEotPosn_Pim_PinionAgConfRampStVari;
extern VAR(FilLpRec1, AUTOMATIC) BmwHwAgArbnAndEotPosn_Pim_PinionAgFilStVari;
extern VAR(uint32, AUTOMATIC) BmwHwAgArbnAndEotPosn_Pim_PinionAgFltRefTi;
extern VAR(boolean, AUTOMATIC) BmwHwAgArbnAndEotPosn_Pim_PrevAllwCorrn;
extern VAR(BmwMotAgSelnSt1, AUTOMATIC) BmwHwAgArbnAndEotPosn_Pim_PrevBmwMotAgSelnSt;
extern VAR(float32, AUTOMATIC) BmwHwAgArbnAndEotPosn_Pim_PrevBmwOffsAuthy;
extern VAR(boolean, AUTOMATIC) BmwHwAgArbnAndEotPosn_Pim_PrevBmwOffsAuthyFlg;
extern VAR(uint8, AUTOMATIC) BmwHwAgArbnAndEotPosn_Pim_PrevIgnCycBmwMotAgSelnSt;
extern VAR(uint8, AUTOMATIC) BmwHwAgArbnAndEotPosn_Pim_PrevIgnCycNtc8CSts;
extern VAR(uint8, AUTOMATIC) BmwHwAgArbnAndEotPosn_Pim_PrevIgnCycNtc8ESts;
extern VAR(uint8, AUTOMATIC) BmwHwAgArbnAndEotPosn_Pim_PrevIgnCycTurnCntrCorrlnSts;
extern VAR(BmwMotAgSelnSt1, AUTOMATIC) BmwHwAgArbnAndEotPosn_Pim_PrevLoopBmwMotAgSelnSt;
extern VAR(BmwQuadOffsSts1, AUTOMATIC) BmwHwAgArbnAndEotPosn_Pim_PrevLoopBmwQuadOffsSts;
extern VAR(float32, AUTOMATIC) BmwHwAgArbnAndEotPosn_Pim_PrevLoopPinionAg;
extern VAR(float32, AUTOMATIC) BmwHwAgArbnAndEotPosn_Pim_PrevPinionAgConf;
extern VAR(boolean, AUTOMATIC) BmwHwAgArbnAndEotPosn_Pim_SetBmwRackCentrToVehCentrOffsTrig;
extern VAR(boolean, AUTOMATIC) BmwHwAgArbnAndEotPosn_Pim_SigInvldTranTrig;
extern VAR(boolean, AUTOMATIC) BmwHwAgArbnAndEotPosn_Pim_TurnCntrCorrlnStsTmrTrig;
extern VAR(uint32, AUTOMATIC) BmwHwAgArbnAndEotPosn_Pim_TurnCntrValTi;
extern VAR(boolean, AUTOMATIC) BmwHwAgArbnAndEotPosn_Pim_VehCentrCmpl;

/* Arguments and Returns */
extern VAR(uint8, AUTOMATIC) BmwHwAgArbnAndEotPosn_Srv_BmwVehCentrOffs_GetErrorStatus_ReqResPtr;
extern VAR(Std_ReturnType, AUTOMATIC) BmwHwAgArbnAndEotPosn_Srv_BmwVehCentrOffs_GetErrorStatus_Return;
extern VAR(boolean, AUTOMATIC) BmwHwAgArbnAndEotPosn_Srv_BmwVehCentrOffs_SetRamBlockStatus_BlockChanged;
extern VAR(Std_ReturnType, AUTOMATIC) BmwHwAgArbnAndEotPosn_Srv_BmwVehCentrOffs_SetRamBlockStatus_Return;
extern VAR(NtcNr1, AUTOMATIC) BmwHwAgArbnAndEotPosn_Srv_GetNtcQlfrSts_NtcNr;
extern VAR(SigQlfr1, AUTOMATIC) BmwHwAgArbnAndEotPosn_Srv_GetNtcQlfrSts_NtcQlfr;
extern VAR(Std_ReturnType, AUTOMATIC) BmwHwAgArbnAndEotPosn_Srv_GetNtcQlfrSts_Return;
extern VAR(uint32, AUTOMATIC) BmwHwAgArbnAndEotPosn_Srv_GetRefTmr100MicroSec32bit_RefTmr;
extern VAR(uint32, AUTOMATIC) BmwHwAgArbnAndEotPosn_Srv_GetTiSpan100MicroSec32bit_RefTmr;
extern VAR(uint32, AUTOMATIC) BmwHwAgArbnAndEotPosn_Srv_GetTiSpan100MicroSec32bit_TiSpan;
extern VAR(NtcNr1, AUTOMATIC) BmwHwAgArbnAndEotPosn_Srv_SetNtcSts_NtcNr;
extern VAR(uint8, AUTOMATIC) BmwHwAgArbnAndEotPosn_Srv_SetNtcSts_NtcStInfo;
extern VAR(NtcSts1, AUTOMATIC) BmwHwAgArbnAndEotPosn_Srv_SetNtcSts_NtcSts;
extern VAR(uint16, AUTOMATIC) BmwHwAgArbnAndEotPosn_Srv_SetNtcSts_DebStep;
extern VAR(Std_ReturnType, AUTOMATIC) BmwHwAgArbnAndEotPosn_Srv_SetNtcSts_Return;
extern VAR(BmwSetVehCentrOffsSts1, AUTOMATIC) BmwHwAgArbnAndEotPosn_Cli_SetVehCentrPosn_BmwSetVehCentrOffsSts;


/*** Input Stubs ***/

#ifdef Rte_Read_BmwHwAgOffs_Val
# undef Rte_Read_BmwHwAgOffs_Val
#else
#error Rte_Read_BmwHwAgOffs_Val is missing
#endif
#define Rte_Read_BmwHwAgOffs_Val(data) (*(data) = BmwHwAgArbnAndEotPosn_Ip_BmwHwAgOffs)

#ifdef Rte_Read_BmwPinionAgOffs_Val
# undef Rte_Read_BmwPinionAgOffs_Val
#else
#error Rte_Read_BmwPinionAgOffs_Val is missing
#endif
#define Rte_Read_BmwPinionAgOffs_Val(data) (*(data) = BmwHwAgArbnAndEotPosn_Ip_BmwPinionAgOffs)

#ifdef Rte_Read_BmwPinionAgOffsSts_Val
# undef Rte_Read_BmwPinionAgOffsSts_Val
#else
#error Rte_Read_BmwPinionAgOffsSts_Val is missing
#endif
#define Rte_Read_BmwPinionAgOffsSts_Val(data) (*(data) = BmwHwAgArbnAndEotPosn_Ip_BmwPinionAgOffsSts)

#ifdef Rte_Read_BmwQuadOffsSts_Val
# undef Rte_Read_BmwQuadOffsSts_Val
#else
#error Rte_Read_BmwQuadOffsSts_Val is missing
#endif
#define Rte_Read_BmwQuadOffsSts_Val(data) (*(data) = BmwHwAgArbnAndEotPosn_Ip_BmwQuadOffsSts)

#ifdef Rte_Read_BmwQuadOffsStsVld_Logl
# undef Rte_Read_BmwQuadOffsStsVld_Logl
#else
#error Rte_Read_BmwQuadOffsStsVld_Logl is missing
#endif
#define Rte_Read_BmwQuadOffsStsVld_Logl(data) (*(data) = BmwHwAgArbnAndEotPosn_Ip_BmwQuadOffsStsVld)

#ifdef Rte_Read_BmwQuadRotorOffs_Val
# undef Rte_Read_BmwQuadRotorOffs_Val
#else
#error Rte_Read_BmwQuadRotorOffs_Val is missing
#endif
#define Rte_Read_BmwQuadRotorOffs_Val(data) (*(data) = BmwHwAgArbnAndEotPosn_Ip_BmwQuadRotorOffs)

#ifdef Rte_Read_BmwQuadRotorOffsVld_Logl
# undef Rte_Read_BmwQuadRotorOffsVld_Logl
#else
#error Rte_Read_BmwQuadRotorOffsVld_Logl is missing
#endif
#define Rte_Read_BmwQuadRotorOffsVld_Logl(data) (*(data) = BmwHwAgArbnAndEotPosn_Ip_BmwQuadRotorOffsVld)

#ifdef Rte_Read_BmwVehSpdSts_Val
# undef Rte_Read_BmwVehSpdSts_Val
#else
#error Rte_Read_BmwVehSpdSts_Val is missing
#endif
#define Rte_Read_BmwVehSpdSts_Val(data) (*(data) = BmwHwAgArbnAndEotPosn_Ip_BmwVehSpdSts)

#ifdef Rte_Read_CmplncErrMotToPinion_Val
# undef Rte_Read_CmplncErrMotToPinion_Val
#else
#error Rte_Read_CmplncErrMotToPinion_Val is missing
#endif
#define Rte_Read_CmplncErrMotToPinion_Val(data) (*(data) = BmwHwAgArbnAndEotPosn_Ip_CmplncErrMotToPinion)

#ifdef Rte_Read_DiKineIntegrityTest_Logl
# undef Rte_Read_DiKineIntegrityTest_Logl
#else
#error Rte_Read_DiKineIntegrityTest_Logl is missing
#endif
#define Rte_Read_DiKineIntegrityTest_Logl(data) (*(data) = BmwHwAgArbnAndEotPosn_Ip_DiKineIntegrityTest)

#ifdef Rte_Read_LongTermRackCentrCmpl_Logl
# undef Rte_Read_LongTermRackCentrCmpl_Logl
#else
#error Rte_Read_LongTermRackCentrCmpl_Logl is missing
#endif
#define Rte_Read_LongTermRackCentrCmpl_Logl(data) (*(data) = BmwHwAgArbnAndEotPosn_Ip_LongTermRackCentrCmpl)

#ifdef Rte_Read_MotAgCumvAlgndMrf_Val
# undef Rte_Read_MotAgCumvAlgndMrf_Val
#else
#error Rte_Read_MotAgCumvAlgndMrf_Val is missing
#endif
#define Rte_Read_MotAgCumvAlgndMrf_Val(data) (*(data) = BmwHwAgArbnAndEotPosn_Ip_MotAgCumvAlgndMrf)

#ifdef Rte_Read_MotAgMeclCorrlnSt_Val
# undef Rte_Read_MotAgMeclCorrlnSt_Val
#else
#error Rte_Read_MotAgMeclCorrlnSt_Val is missing
#endif
#define Rte_Read_MotAgMeclCorrlnSt_Val(data) (*(data) = BmwHwAgArbnAndEotPosn_Ip_MotAgMeclCorrlnSt)

#ifdef Rte_Read_MotAgTurnCntr_Val
# undef Rte_Read_MotAgTurnCntr_Val
#else
#error Rte_Read_MotAgTurnCntr_Val is missing
#endif
#define Rte_Read_MotAgTurnCntr_Val(data) (*(data) = BmwHwAgArbnAndEotPosn_Ip_MotAgTurnCntr)

#ifdef Rte_Read_RackCentrPinionAg_Val
# undef Rte_Read_RackCentrPinionAg_Val
#else
#error Rte_Read_RackCentrPinionAg_Val is missing
#endif
#define Rte_Read_RackCentrPinionAg_Val(data) (*(data) = BmwHwAgArbnAndEotPosn_Ip_RackCentrPinionAg)

#ifdef Rte_Read_TotRackTrvl_Val
# undef Rte_Read_TotRackTrvl_Val
#else
#error Rte_Read_TotRackTrvl_Val is missing
#endif
#define Rte_Read_TotRackTrvl_Val(data) (*(data) = BmwHwAgArbnAndEotPosn_Ip_TotRackTrvl)

#ifdef Rte_Read_TurnCntrCorrlnSts_Val
# undef Rte_Read_TurnCntrCorrlnSts_Val
#else
#error Rte_Read_TurnCntrCorrlnSts_Val is missing
#endif
#define Rte_Read_TurnCntrCorrlnSts_Val(data) (*(data) = BmwHwAgArbnAndEotPosn_Ip_TurnCntrCorrlnSts)

#ifdef Rte_Read_VehSpd_Val
# undef Rte_Read_VehSpd_Val
#else
#error Rte_Read_VehSpd_Val is missing
#endif
#define Rte_Read_VehSpd_Val(data) (*(data) = BmwHwAgArbnAndEotPosn_Ip_VehSpd)

#ifdef Rte_Read_VehSpdVld_Logl
# undef Rte_Read_VehSpdVld_Logl
#else
#error Rte_Read_VehSpdVld_Logl is missing
#endif
#define Rte_Read_VehSpdVld_Logl(data) (*(data) = BmwHwAgArbnAndEotPosn_Ip_VehSpdVld)


/*** Output Stubs ***/

#ifdef Rte_Write_AlgndPinionAg_Val
# undef Rte_Write_AlgndPinionAg_Val
#else
#error Rte_Write_AlgndPinionAg_Val is missing
#endif
#define Rte_Write_AlgndPinionAg_Val(data) (BmwHwAgArbnAndEotPosn_Op_AlgndPinionAg = (data))

#ifdef Rte_Write_BmwPinionAg_Val
# undef Rte_Write_BmwPinionAg_Val
#else
#error Rte_Write_BmwPinionAg_Val is missing
#endif
#define Rte_Write_BmwPinionAg_Val(data) (BmwHwAgArbnAndEotPosn_Op_BmwPinionAg = (data))

#ifdef Rte_Write_BmwPinionAgQlfr_Val
# undef Rte_Write_BmwPinionAgQlfr_Val
#else
#error Rte_Write_BmwPinionAgQlfr_Val is missing
#endif
#define Rte_Write_BmwPinionAgQlfr_Val(data) (BmwHwAgArbnAndEotPosn_Op_BmwPinionAgQlfr = (data))

#ifdef Rte_Write_BmwRackCentrToVehCentrOffs_Val
# undef Rte_Write_BmwRackCentrToVehCentrOffs_Val
#else
#error Rte_Write_BmwRackCentrToVehCentrOffs_Val is missing
#endif
#define Rte_Write_BmwRackCentrToVehCentrOffs_Val(data) (BmwHwAgArbnAndEotPosn_Op_BmwRackCentrToVehCentrOffs = (data))

#ifdef Rte_Write_BmwRackCentrToVehCentrOffsVld_Logl
# undef Rte_Write_BmwRackCentrToVehCentrOffsVld_Logl
#else
#error Rte_Write_BmwRackCentrToVehCentrOffsVld_Logl is missing
#endif
#define Rte_Write_BmwRackCentrToVehCentrOffsVld_Logl(data) (BmwHwAgArbnAndEotPosn_Op_BmwRackCentrToVehCentrOffsVld = (data))

#ifdef Rte_Write_HwAgCcwDetd_Logl
# undef Rte_Write_HwAgCcwDetd_Logl
#else
#error Rte_Write_HwAgCcwDetd_Logl is missing
#endif
#define Rte_Write_HwAgCcwDetd_Logl(data) (BmwHwAgArbnAndEotPosn_Op_HwAgCcwDetd = (data))

#ifdef Rte_Write_HwAgCwDetd_Logl
# undef Rte_Write_HwAgCwDetd_Logl
#else
#error Rte_Write_HwAgCwDetd_Logl is missing
#endif
#define Rte_Write_HwAgCwDetd_Logl(data) (BmwHwAgArbnAndEotPosn_Op_HwAgCwDetd = (data))

#ifdef Rte_Write_HwAgEotCcw_Val
# undef Rte_Write_HwAgEotCcw_Val
#else
#error Rte_Write_HwAgEotCcw_Val is missing
#endif
#define Rte_Write_HwAgEotCcw_Val(data) (BmwHwAgArbnAndEotPosn_Op_HwAgEotCcw = (data))

#ifdef Rte_Write_HwAgEotCw_Val
# undef Rte_Write_HwAgEotCw_Val
#else
#error Rte_Write_HwAgEotCw_Val is missing
#endif
#define Rte_Write_HwAgEotCw_Val(data) (BmwHwAgArbnAndEotPosn_Op_HwAgEotCw = (data))

#ifdef Rte_Write_LongTermVehCentrCmpl_Logl
# undef Rte_Write_LongTermVehCentrCmpl_Logl
#else
#error Rte_Write_LongTermVehCentrCmpl_Logl is missing
#endif
#define Rte_Write_LongTermVehCentrCmpl_Logl(data) (BmwHwAgArbnAndEotPosn_Op_LongTermVehCentrCmpl = (data))

#ifdef Rte_Write_OffsCmpdPinionAg_Val
# undef Rte_Write_OffsCmpdPinionAg_Val
#else
#error Rte_Write_OffsCmpdPinionAg_Val is missing
#endif
#define Rte_Write_OffsCmpdPinionAg_Val(data) (BmwHwAgArbnAndEotPosn_Op_OffsCmpdPinionAg = (data))

#ifdef Rte_Write_PinionAg_Val
# undef Rte_Write_PinionAg_Val
#else
#error Rte_Write_PinionAg_Val is missing
#endif
#define Rte_Write_PinionAg_Val(data) (BmwHwAgArbnAndEotPosn_Op_PinionAg = (data))

#ifdef Rte_Write_PinionAgConf_Val
# undef Rte_Write_PinionAgConf_Val
#else
#error Rte_Write_PinionAgConf_Val is missing
#endif
#define Rte_Write_PinionAgConf_Val(data) (BmwHwAgArbnAndEotPosn_Op_PinionAgConf = (data))


/*** Calibration Stubs ***/

#ifdef Rte_Prm_BmwHwAgArbnAndEotPosnAllwExitFromInit_Val
# undef Rte_Prm_BmwHwAgArbnAndEotPosnAllwExitFromInit_Val
#else
#error Rte_Prm_BmwHwAgArbnAndEotPosnAllwExitFromInit_Val is missing
#endif
#define Rte_Prm_BmwHwAgArbnAndEotPosnAllwExitFromInit_Val() (BmwHwAgArbnAndEotPosn_Cal_BmwHwAgArbnAndEotPosnAllwExitFromInit)

#ifdef Rte_Prm_BmwHwAgArbnAndEotPosnBmwPinionAgOffsLim_Val
# undef Rte_Prm_BmwHwAgArbnAndEotPosnBmwPinionAgOffsLim_Val
#else
#error Rte_Prm_BmwHwAgArbnAndEotPosnBmwPinionAgOffsLim_Val is missing
#endif
#define Rte_Prm_BmwHwAgArbnAndEotPosnBmwPinionAgOffsLim_Val() (BmwHwAgArbnAndEotPosn_Cal_BmwHwAgArbnAndEotPosnBmwPinionAgOffsLim)

#ifdef Rte_Prm_BmwHwAgArbnAndEotPosnBmwPinionAgOffsRateLim_Val
# undef Rte_Prm_BmwHwAgArbnAndEotPosnBmwPinionAgOffsRateLim_Val
#else
#error Rte_Prm_BmwHwAgArbnAndEotPosnBmwPinionAgOffsRateLim_Val is missing
#endif
#define Rte_Prm_BmwHwAgArbnAndEotPosnBmwPinionAgOffsRateLim_Val() (BmwHwAgArbnAndEotPosn_Cal_BmwHwAgArbnAndEotPosnBmwPinionAgOffsRateLim)

#ifdef Rte_Prm_BmwHwAgArbnAndEotPosnEotCcwMax_Val
# undef Rte_Prm_BmwHwAgArbnAndEotPosnEotCcwMax_Val
#else
#error Rte_Prm_BmwHwAgArbnAndEotPosnEotCcwMax_Val is missing
#endif
#define Rte_Prm_BmwHwAgArbnAndEotPosnEotCcwMax_Val() (BmwHwAgArbnAndEotPosn_Cal_BmwHwAgArbnAndEotPosnEotCcwMax)

#ifdef Rte_Prm_BmwHwAgArbnAndEotPosnEotCcwMin_Val
# undef Rte_Prm_BmwHwAgArbnAndEotPosnEotCcwMin_Val
#else
#error Rte_Prm_BmwHwAgArbnAndEotPosnEotCcwMin_Val is missing
#endif
#define Rte_Prm_BmwHwAgArbnAndEotPosnEotCcwMin_Val() (BmwHwAgArbnAndEotPosn_Cal_BmwHwAgArbnAndEotPosnEotCcwMin)

#ifdef Rte_Prm_BmwHwAgArbnAndEotPosnEotCwMax_Val
# undef Rte_Prm_BmwHwAgArbnAndEotPosnEotCwMax_Val
#else
#error Rte_Prm_BmwHwAgArbnAndEotPosnEotCwMax_Val is missing
#endif
#define Rte_Prm_BmwHwAgArbnAndEotPosnEotCwMax_Val() (BmwHwAgArbnAndEotPosn_Cal_BmwHwAgArbnAndEotPosnEotCwMax)

#ifdef Rte_Prm_BmwHwAgArbnAndEotPosnEotCwMin_Val
# undef Rte_Prm_BmwHwAgArbnAndEotPosnEotCwMin_Val
#else
#error Rte_Prm_BmwHwAgArbnAndEotPosnEotCwMin_Val is missing
#endif
#define Rte_Prm_BmwHwAgArbnAndEotPosnEotCwMin_Val() (BmwHwAgArbnAndEotPosn_Cal_BmwHwAgArbnAndEotPosnEotCwMin)

#ifdef Rte_Prm_BmwHwAgArbnAndEotPosnKineIntegrityDiagcMaxRackLim_Val
# undef Rte_Prm_BmwHwAgArbnAndEotPosnKineIntegrityDiagcMaxRackLim_Val
#else
#error Rte_Prm_BmwHwAgArbnAndEotPosnKineIntegrityDiagcMaxRackLim_Val is missing
#endif
#define Rte_Prm_BmwHwAgArbnAndEotPosnKineIntegrityDiagcMaxRackLim_Val() (BmwHwAgArbnAndEotPosn_Cal_BmwHwAgArbnAndEotPosnKineIntegrityDiagcMaxRackLim)

#ifdef Rte_Prm_BmwHwAgArbnAndEotPosnMinVehSpdReqdVldAbsPos_Val
# undef Rte_Prm_BmwHwAgArbnAndEotPosnMinVehSpdReqdVldAbsPos_Val
#else
#error Rte_Prm_BmwHwAgArbnAndEotPosnMinVehSpdReqdVldAbsPos_Val is missing
#endif
#define Rte_Prm_BmwHwAgArbnAndEotPosnMinVehSpdReqdVldAbsPos_Val() (BmwHwAgArbnAndEotPosn_Cal_BmwHwAgArbnAndEotPosnMinVehSpdReqdVldAbsPos)

#ifdef Rte_Prm_BmwHwAgArbnAndEotPosnMotPosnDegArbdBlnd_Val
# undef Rte_Prm_BmwHwAgArbnAndEotPosnMotPosnDegArbdBlnd_Val
#else
#error Rte_Prm_BmwHwAgArbnAndEotPosnMotPosnDegArbdBlnd_Val is missing
#endif
#define Rte_Prm_BmwHwAgArbnAndEotPosnMotPosnDegArbdBlnd_Val() (BmwHwAgArbnAndEotPosn_Cal_BmwHwAgArbnAndEotPosnMotPosnDegArbdBlnd)

#ifdef Rte_Prm_BmwHwAgArbnAndEotPosnMotToHwResl_Val
# undef Rte_Prm_BmwHwAgArbnAndEotPosnMotToHwResl_Val
#else
#error Rte_Prm_BmwHwAgArbnAndEotPosnMotToHwResl_Val is missing
#endif
#define Rte_Prm_BmwHwAgArbnAndEotPosnMotToHwResl_Val() (BmwHwAgArbnAndEotPosn_Cal_BmwHwAgArbnAndEotPosnMotToHwResl)

#ifdef Rte_Prm_BmwHwAgArbnAndEotPosnOffsAuthy_Val
# undef Rte_Prm_BmwHwAgArbnAndEotPosnOffsAuthy_Val
#else
#error Rte_Prm_BmwHwAgArbnAndEotPosnOffsAuthy_Val is missing
#endif
#define Rte_Prm_BmwHwAgArbnAndEotPosnOffsAuthy_Val() (BmwHwAgArbnAndEotPosn_Cal_BmwHwAgArbnAndEotPosnOffsAuthy)

#ifdef Rte_Prm_BmwHwAgArbnAndEotPosnOffsCorrnAuthy_Val
# undef Rte_Prm_BmwHwAgArbnAndEotPosnOffsCorrnAuthy_Val
#else
#error Rte_Prm_BmwHwAgArbnAndEotPosnOffsCorrnAuthy_Val is missing
#endif
#define Rte_Prm_BmwHwAgArbnAndEotPosnOffsCorrnAuthy_Val() (BmwHwAgArbnAndEotPosn_Cal_BmwHwAgArbnAndEotPosnOffsCorrnAuthy)

#ifdef Rte_Prm_BmwHwAgArbnAndEotPosnOffsCorrnTmrThd_Val
# undef Rte_Prm_BmwHwAgArbnAndEotPosnOffsCorrnTmrThd_Val
#else
#error Rte_Prm_BmwHwAgArbnAndEotPosnOffsCorrnTmrThd_Val is missing
#endif
#define Rte_Prm_BmwHwAgArbnAndEotPosnOffsCorrnTmrThd_Val() (BmwHwAgArbnAndEotPosn_Cal_BmwHwAgArbnAndEotPosnOffsCorrnTmrThd)

#ifdef Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgConfRampDwnRate_Val
# undef Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgConfRampDwnRate_Val
#else
#error Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgConfRampDwnRate_Val is missing
#endif
#define Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgConfRampDwnRate_Val() (BmwHwAgArbnAndEotPosn_Cal_BmwHwAgArbnAndEotPosnPinionAgConfRampDwnRate)

#ifdef Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgConfRampUpRate_Val
# undef Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgConfRampUpRate_Val
#else
#error Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgConfRampUpRate_Val is missing
#endif
#define Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgConfRampUpRate_Val() (BmwHwAgArbnAndEotPosn_Cal_BmwHwAgArbnAndEotPosnPinionAgConfRampUpRate)

#ifdef Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgDifThd_Val
# undef Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgDifThd_Val
#else
#error Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgDifThd_Val is missing
#endif
#define Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgDifThd_Val() (BmwHwAgArbnAndEotPosn_Cal_BmwHwAgArbnAndEotPosnPinionAgDifThd)

#ifdef Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgFilFrq_Val
# undef Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgFilFrq_Val
#else
#error Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgFilFrq_Val is missing
#endif
#define Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgFilFrq_Val() (BmwHwAgArbnAndEotPosn_Cal_BmwHwAgArbnAndEotPosnPinionAgFilFrq)

#ifdef Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgFltTmrThd_Val
# undef Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgFltTmrThd_Val
#else
#error Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgFltTmrThd_Val is missing
#endif
#define Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgFltTmrThd_Val() (BmwHwAgArbnAndEotPosn_Cal_BmwHwAgArbnAndEotPosnPinionAgFltTmrThd)

#ifdef Rte_Prm_BmwHwAgArbnAndEotPosnSysPolarityAssi_Logl
# undef Rte_Prm_BmwHwAgArbnAndEotPosnSysPolarityAssi_Logl
#else
#error Rte_Prm_BmwHwAgArbnAndEotPosnSysPolarityAssi_Logl is missing
#endif
#define Rte_Prm_BmwHwAgArbnAndEotPosnSysPolarityAssi_Logl() (BmwHwAgArbnAndEotPosn_Cal_BmwHwAgArbnAndEotPosnSysPolarityAssi)

#ifdef Rte_Prm_BmwHwAgArbnAndEotPosnTmpCmpdAuthy_Val
# undef Rte_Prm_BmwHwAgArbnAndEotPosnTmpCmpdAuthy_Val
#else
#error Rte_Prm_BmwHwAgArbnAndEotPosnTmpCmpdAuthy_Val is missing
#endif
#define Rte_Prm_BmwHwAgArbnAndEotPosnTmpCmpdAuthy_Val() (BmwHwAgArbnAndEotPosn_Cal_BmwHwAgArbnAndEotPosnTmpCmpdAuthy)

#ifdef Rte_Prm_BmwHwAgArbnAndEotPosnTurnCntrAuthy_Val
# undef Rte_Prm_BmwHwAgArbnAndEotPosnTurnCntrAuthy_Val
#else
#error Rte_Prm_BmwHwAgArbnAndEotPosnTurnCntrAuthy_Val is missing
#endif
#define Rte_Prm_BmwHwAgArbnAndEotPosnTurnCntrAuthy_Val() (BmwHwAgArbnAndEotPosn_Cal_BmwHwAgArbnAndEotPosnTurnCntrAuthy)

#ifdef Rte_Prm_BmwHwAgArbnAndEotPosnTurnCntrCorrlnStsTmrThd_Val
# undef Rte_Prm_BmwHwAgArbnAndEotPosnTurnCntrCorrlnStsTmrThd_Val
#else
#error Rte_Prm_BmwHwAgArbnAndEotPosnTurnCntrCorrlnStsTmrThd_Val is missing
#endif
#define Rte_Prm_BmwHwAgArbnAndEotPosnTurnCntrCorrlnStsTmrThd_Val() (BmwHwAgArbnAndEotPosn_Cal_BmwHwAgArbnAndEotPosnTurnCntrCorrlnStsTmrThd)

#ifdef Rte_Prm_SysGlbPrmSysKineRat_Val
# undef Rte_Prm_SysGlbPrmSysKineRat_Val
#else
#error Rte_Prm_SysGlbPrmSysKineRat_Val is missing
#endif
#define Rte_Prm_SysGlbPrmSysKineRat_Val() (BmwHwAgArbnAndEotPosn_Cal_SysGlbPrmSysKineRat)


/*** PIM Stubs ***/

#ifdef Rte_Pim_BmwVehCentrOffs
# undef Rte_Pim_BmwVehCentrOffs
#else
#error Rte_Pim_BmwVehCentrOffs is missing
#endif
#define Rte_Pim_BmwVehCentrOffs() (&BmwHwAgArbnAndEotPosn_Pim_BmwVehCentrOffs)

#ifdef Rte_Pim_dBmwHwAgArbnAndEotPosnBmwMotAgSelnSt
# undef Rte_Pim_dBmwHwAgArbnAndEotPosnBmwMotAgSelnSt
#else
#error Rte_Pim_dBmwHwAgArbnAndEotPosnBmwMotAgSelnSt is missing
#endif
#define Rte_Pim_dBmwHwAgArbnAndEotPosnBmwMotAgSelnSt() (&BmwHwAgArbnAndEotPosn_Pim_dBmwHwAgArbnAndEotPosnBmwMotAgSelnSt)

#ifdef Rte_Pim_AllwExitFromInitTi
# undef Rte_Pim_AllwExitFromInitTi
#else
#error Rte_Pim_AllwExitFromInitTi is missing
#endif
#define Rte_Pim_AllwExitFromInitTi() (&BmwHwAgArbnAndEotPosn_Pim_AllwExitFromInitTi)

#ifdef Rte_Pim_BmwPinionAgOffsRateLim
# undef Rte_Pim_BmwPinionAgOffsRateLim
#else
#error Rte_Pim_BmwPinionAgOffsRateLim is missing
#endif
#define Rte_Pim_BmwPinionAgOffsRateLim() (&BmwHwAgArbnAndEotPosn_Pim_BmwPinionAgOffsRateLim)

#ifdef Rte_Pim_BmwRackCentrToVehCentrOffsSts
# undef Rte_Pim_BmwRackCentrToVehCentrOffsSts
#else
#error Rte_Pim_BmwRackCentrToVehCentrOffsSts is missing
#endif
#define Rte_Pim_BmwRackCentrToVehCentrOffsSts() (&BmwHwAgArbnAndEotPosn_Pim_BmwRackCentrToVehCentrOffsSts)

#ifdef Rte_Pim_ClrNotCmplPinionAgFlg
# undef Rte_Pim_ClrNotCmplPinionAgFlg
#else
#error Rte_Pim_ClrNotCmplPinionAgFlg is missing
#endif
#define Rte_Pim_ClrNotCmplPinionAgFlg() (&BmwHwAgArbnAndEotPosn_Pim_ClrNotCmplPinionAgFlg)

#ifdef Rte_Pim_CurrAlgndPinionAg
# undef Rte_Pim_CurrAlgndPinionAg
#else
#error Rte_Pim_CurrAlgndPinionAg is missing
#endif
#define Rte_Pim_CurrAlgndPinionAg() (&BmwHwAgArbnAndEotPosn_Pim_CurrAlgndPinionAg)

#ifdef Rte_Pim_CurrDftPinionAgFltPrsnt
# undef Rte_Pim_CurrDftPinionAgFltPrsnt
#else
#error Rte_Pim_CurrDftPinionAgFltPrsnt is missing
#endif
#define Rte_Pim_CurrDftPinionAgFltPrsnt() (&BmwHwAgArbnAndEotPosn_Pim_CurrDftPinionAgFltPrsnt)

#ifdef Rte_Pim_DynStabyCtrlCdn
# undef Rte_Pim_DynStabyCtrlCdn
#else
#error Rte_Pim_DynStabyCtrlCdn is missing
#endif
#define Rte_Pim_DynStabyCtrlCdn() (&BmwHwAgArbnAndEotPosn_Pim_DynStabyCtrlCdn)

#ifdef Rte_Pim_FirstLoopIndcr
# undef Rte_Pim_FirstLoopIndcr
#else
#error Rte_Pim_FirstLoopIndcr is missing
#endif
#define Rte_Pim_FirstLoopIndcr() (&BmwHwAgArbnAndEotPosn_Pim_FirstLoopIndcr)

#ifdef Rte_Pim_IniTurnCntrCorrlnSts
# undef Rte_Pim_IniTurnCntrCorrlnSts
#else
#error Rte_Pim_IniTurnCntrCorrlnSts is missing
#endif
#define Rte_Pim_IniTurnCntrCorrlnSts() (&BmwHwAgArbnAndEotPosn_Pim_IniTurnCntrCorrlnSts)

#ifdef Rte_Pim_KineIntegrityFlt
# undef Rte_Pim_KineIntegrityFlt
#else
#error Rte_Pim_KineIntegrityFlt is missing
#endif
#define Rte_Pim_KineIntegrityFlt() (&BmwHwAgArbnAndEotPosn_Pim_KineIntegrityFlt)

#ifdef Rte_Pim_LpFilActvd
# undef Rte_Pim_LpFilActvd
#else
#error Rte_Pim_LpFilActvd is missing
#endif
#define Rte_Pim_LpFilActvd() (&BmwHwAgArbnAndEotPosn_Pim_LpFilActvd)

#ifdef Rte_Pim_MotPosnDegArbdBlndFac
# undef Rte_Pim_MotPosnDegArbdBlndFac
#else
#error Rte_Pim_MotPosnDegArbdBlndFac is missing
#endif
#define Rte_Pim_MotPosnDegArbdBlndFac() (&BmwHwAgArbnAndEotPosn_Pim_MotPosnDegArbdBlndFac)

#ifdef Rte_Pim_MotPosnDegArbdBlndTi
# undef Rte_Pim_MotPosnDegArbdBlndTi
#else
#error Rte_Pim_MotPosnDegArbdBlndTi is missing
#endif
#define Rte_Pim_MotPosnDegArbdBlndTi() (&BmwHwAgArbnAndEotPosn_Pim_MotPosnDegArbdBlndTi)

#ifdef Rte_Pim_OffsCorrnRefTi
# undef Rte_Pim_OffsCorrnRefTi
#else
#error Rte_Pim_OffsCorrnRefTi is missing
#endif
#define Rte_Pim_OffsCorrnRefTi() (&BmwHwAgArbnAndEotPosn_Pim_OffsCorrnRefTi)

#ifdef Rte_Pim_PinionAgConfRampStVari
# undef Rte_Pim_PinionAgConfRampStVari
#else
#error Rte_Pim_PinionAgConfRampStVari is missing
#endif
#define Rte_Pim_PinionAgConfRampStVari() (&BmwHwAgArbnAndEotPosn_Pim_PinionAgConfRampStVari)

#ifdef Rte_Pim_PinionAgFilStVari
# undef Rte_Pim_PinionAgFilStVari
#else
#error Rte_Pim_PinionAgFilStVari is missing
#endif
#define Rte_Pim_PinionAgFilStVari() (&BmwHwAgArbnAndEotPosn_Pim_PinionAgFilStVari)

#ifdef Rte_Pim_PinionAgFltRefTi
# undef Rte_Pim_PinionAgFltRefTi
#else
#error Rte_Pim_PinionAgFltRefTi is missing
#endif
#define Rte_Pim_PinionAgFltRefTi() (&BmwHwAgArbnAndEotPosn_Pim_PinionAgFltRefTi)

#ifdef Rte_Pim_PrevAllwCorrn
# undef Rte_Pim_PrevAllwCorrn
#else
#error Rte_Pim_PrevAllwCorrn is missing
#endif
#define Rte_Pim_PrevAllwCorrn() (&BmwHwAgArbnAndEotPosn_Pim_PrevAllwCorrn)

#ifdef Rte_Pim_PrevBmwMotAgSelnSt
# undef Rte_Pim_PrevBmwMotAgSelnSt
#else
#error Rte_Pim_PrevBmwMotAgSelnSt is missing
#endif
#define Rte_Pim_PrevBmwMotAgSelnSt() (&BmwHwAgArbnAndEotPosn_Pim_PrevBmwMotAgSelnSt)

#ifdef Rte_Pim_PrevBmwOffsAuthy
# undef Rte_Pim_PrevBmwOffsAuthy
#else
#error Rte_Pim_PrevBmwOffsAuthy is missing
#endif
#define Rte_Pim_PrevBmwOffsAuthy() (&BmwHwAgArbnAndEotPosn_Pim_PrevBmwOffsAuthy)

#ifdef Rte_Pim_PrevBmwOffsAuthyFlg
# undef Rte_Pim_PrevBmwOffsAuthyFlg
#else
#error Rte_Pim_PrevBmwOffsAuthyFlg is missing
#endif
#define Rte_Pim_PrevBmwOffsAuthyFlg() (&BmwHwAgArbnAndEotPosn_Pim_PrevBmwOffsAuthyFlg)

#ifdef Rte_Pim_PrevIgnCycBmwMotAgSelnSt
# undef Rte_Pim_PrevIgnCycBmwMotAgSelnSt
#else
#error Rte_Pim_PrevIgnCycBmwMotAgSelnSt is missing
#endif
#define Rte_Pim_PrevIgnCycBmwMotAgSelnSt() (&BmwHwAgArbnAndEotPosn_Pim_PrevIgnCycBmwMotAgSelnSt)

#ifdef Rte_Pim_PrevIgnCycNtc8CSts
# undef Rte_Pim_PrevIgnCycNtc8CSts
#else
#error Rte_Pim_PrevIgnCycNtc8CSts is missing
#endif
#define Rte_Pim_PrevIgnCycNtc8CSts() (&BmwHwAgArbnAndEotPosn_Pim_PrevIgnCycNtc8CSts)

#ifdef Rte_Pim_PrevIgnCycNtc8ESts
# undef Rte_Pim_PrevIgnCycNtc8ESts
#else
#error Rte_Pim_PrevIgnCycNtc8ESts is missing
#endif
#define Rte_Pim_PrevIgnCycNtc8ESts() (&BmwHwAgArbnAndEotPosn_Pim_PrevIgnCycNtc8ESts)

#ifdef Rte_Pim_PrevIgnCycTurnCntrCorrlnSts
# undef Rte_Pim_PrevIgnCycTurnCntrCorrlnSts
#else
#error Rte_Pim_PrevIgnCycTurnCntrCorrlnSts is missing
#endif
#define Rte_Pim_PrevIgnCycTurnCntrCorrlnSts() (&BmwHwAgArbnAndEotPosn_Pim_PrevIgnCycTurnCntrCorrlnSts)

#ifdef Rte_Pim_PrevLoopBmwMotAgSelnSt
# undef Rte_Pim_PrevLoopBmwMotAgSelnSt
#else
#error Rte_Pim_PrevLoopBmwMotAgSelnSt is missing
#endif
#define Rte_Pim_PrevLoopBmwMotAgSelnSt() (&BmwHwAgArbnAndEotPosn_Pim_PrevLoopBmwMotAgSelnSt)

#ifdef Rte_Pim_PrevLoopBmwQuadOffsSts
# undef Rte_Pim_PrevLoopBmwQuadOffsSts
#else
#error Rte_Pim_PrevLoopBmwQuadOffsSts is missing
#endif
#define Rte_Pim_PrevLoopBmwQuadOffsSts() (&BmwHwAgArbnAndEotPosn_Pim_PrevLoopBmwQuadOffsSts)

#ifdef Rte_Pim_PrevLoopPinionAg
# undef Rte_Pim_PrevLoopPinionAg
#else
#error Rte_Pim_PrevLoopPinionAg is missing
#endif
#define Rte_Pim_PrevLoopPinionAg() (&BmwHwAgArbnAndEotPosn_Pim_PrevLoopPinionAg)

#ifdef Rte_Pim_PrevPinionAgConf
# undef Rte_Pim_PrevPinionAgConf
#else
#error Rte_Pim_PrevPinionAgConf is missing
#endif
#define Rte_Pim_PrevPinionAgConf() (&BmwHwAgArbnAndEotPosn_Pim_PrevPinionAgConf)

#ifdef Rte_Pim_SetBmwRackCentrToVehCentrOffsTrig
# undef Rte_Pim_SetBmwRackCentrToVehCentrOffsTrig
#else
#error Rte_Pim_SetBmwRackCentrToVehCentrOffsTrig is missing
#endif
#define Rte_Pim_SetBmwRackCentrToVehCentrOffsTrig() (&BmwHwAgArbnAndEotPosn_Pim_SetBmwRackCentrToVehCentrOffsTrig)

#ifdef Rte_Pim_SigInvldTranTrig
# undef Rte_Pim_SigInvldTranTrig
#else
#error Rte_Pim_SigInvldTranTrig is missing
#endif
#define Rte_Pim_SigInvldTranTrig() (&BmwHwAgArbnAndEotPosn_Pim_SigInvldTranTrig)

#ifdef Rte_Pim_TurnCntrCorrlnStsTmrTrig
# undef Rte_Pim_TurnCntrCorrlnStsTmrTrig
#else
#error Rte_Pim_TurnCntrCorrlnStsTmrTrig is missing
#endif
#define Rte_Pim_TurnCntrCorrlnStsTmrTrig() (&BmwHwAgArbnAndEotPosn_Pim_TurnCntrCorrlnStsTmrTrig)

#ifdef Rte_Pim_TurnCntrValTi
# undef Rte_Pim_TurnCntrValTi
#else
#error Rte_Pim_TurnCntrValTi is missing
#endif
#define Rte_Pim_TurnCntrValTi() (&BmwHwAgArbnAndEotPosn_Pim_TurnCntrValTi)

#ifdef Rte_Pim_VehCentrCmpl
# undef Rte_Pim_VehCentrCmpl
#else
#error Rte_Pim_VehCentrCmpl is missing
#endif
#define Rte_Pim_VehCentrCmpl() (&BmwHwAgArbnAndEotPosn_Pim_VehCentrCmpl)


/*** Client Stub ***/

extern FUNC(void, AUTOMATIC) Rte_Stub(void);


#endif
