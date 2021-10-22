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
extern VAR(float32, AUTOMATIC) LrnPinionCentr_Ip_HwAg;
extern VAR(float32, AUTOMATIC) LrnPinionCentr_Ip_MotVelCrf;
extern VAR(boolean, AUTOMATIC) LrnPinionCentr_Ip_PinionCentrLrnEna;

/* Outputs */
extern VAR(float32, AUTOMATIC) LrnPinionCentr_Op_PinionCentrLrnCmd;
extern VAR(float32, AUTOMATIC) LrnPinionCentr_Op_PinionCentrLrnHwCentr;
extern VAR(float32, AUTOMATIC) LrnPinionCentr_Op_PinionCentrLrnHwTrvl;
extern VAR(uint8, AUTOMATIC) LrnPinionCentr_Op_PinionCentrLrnSt;

/* Calibrations */
extern CONST(float32, AUTOMATIC) LrnPinionCentr_Cal_LrnPinionCentrDampgCtrlGain;
extern CONST(float32, AUTOMATIC) LrnPinionCentr_Cal_LrnPinionCentrHldTq;
extern CONST(float32, AUTOMATIC) LrnPinionCentr_Cal_LrnPinionCentrHldTqErrThd;
extern CONST(float32, AUTOMATIC) LrnPinionCentr_Cal_LrnPinionCentrHldTqRateLim;
extern CONST(float32, AUTOMATIC) LrnPinionCentr_Cal_LrnPinionCentrHwPosnErrThd;
extern CONST(float32, AUTOMATIC) LrnPinionCentr_Cal_LrnPinionCentrIntglCtrlGain;
extern CONST(float32, AUTOMATIC) LrnPinionCentr_Cal_LrnPinionCentrMaxTqCmd;
extern CONST(float32, AUTOMATIC) LrnPinionCentr_Cal_LrnPinionCentrMinMotTq;
extern CONST(float32, AUTOMATIC) LrnPinionCentr_Cal_LrnPinionCentrMotVelThd;
extern CONST(float32, AUTOMATIC) LrnPinionCentr_Cal_LrnPinionCentrPropCtrlGain;
extern CONST(uint16, AUTOMATIC) LrnPinionCentr_Cal_LrnPinionCentrTiOutThd;
extern CONST(uint16, AUTOMATIC) LrnPinionCentr_Cal_LrnPinionCentrTiThd;
extern CONST(float32, AUTOMATIC) LrnPinionCentr_Cal_SysGlbPrmSysKineRat;

/* PIMs */
extern VAR(float32, AUTOMATIC) LrnPinionCentr_Pim_dLrnPinionCentrHwPosnCmd;
extern VAR(float32, AUTOMATIC) LrnPinionCentr_Pim_MaxHwPosnPrev;
extern VAR(float32, AUTOMATIC) LrnPinionCentr_Pim_MinHwPosnPrev;
extern VAR(boolean, AUTOMATIC) LrnPinionCentr_Pim_PinionCentrLrnEnaPrev;
extern VAR(float32, AUTOMATIC) LrnPinionCentr_Pim_PinionCentrLrnHwCentrPrev;
extern VAR(float32, AUTOMATIC) LrnPinionCentr_Pim_PinionCentrLrnHwTrvlPrev;
extern VAR(float32, AUTOMATIC) LrnPinionCentr_Pim_StCtrl1PosnErrRateLim;
extern VAR(FilLpRec1, AUTOMATIC) LrnPinionCentr_Pim_StCtrl1RateLimdPosnErrLpFil;
extern VAR(uint32, AUTOMATIC) LrnPinionCentr_Pim_StCtrl1TmrARefTi;
extern VAR(uint32, AUTOMATIC) LrnPinionCentr_Pim_StCtrl1TmrBRefTi;
extern VAR(FilLpRec1, AUTOMATIC) LrnPinionCentr_Pim_StCtrl2RateLimdTqErrLpFil;
extern VAR(uint32, AUTOMATIC) LrnPinionCentr_Pim_StCtrl2TmrARefTi;
extern VAR(uint32, AUTOMATIC) LrnPinionCentr_Pim_StCtrl2TmrBRefTi;
extern VAR(float32, AUTOMATIC) LrnPinionCentr_Pim_StCtrl2TqErrRateLim;
extern VAR(float32, AUTOMATIC) LrnPinionCentr_Pim_StCtrl3PosnErrRateLim;
extern VAR(FilLpRec1, AUTOMATIC) LrnPinionCentr_Pim_StCtrl3RateLimdPosnErrLpFil;
extern VAR(FilLpRec1, AUTOMATIC) LrnPinionCentr_Pim_StCtrl3RateLimdTqErrLpFil;
extern VAR(uint32, AUTOMATIC) LrnPinionCentr_Pim_StCtrl3TmrARefTi;
extern VAR(uint32, AUTOMATIC) LrnPinionCentr_Pim_StCtrl3TmrBRefTi;
extern VAR(float32, AUTOMATIC) LrnPinionCentr_Pim_StCtrl3TqErrRateLim;
extern VAR(FilLpRec1, AUTOMATIC) LrnPinionCentr_Pim_StCtrl4RateLimdTqErrLpFil;
extern VAR(uint32, AUTOMATIC) LrnPinionCentr_Pim_StCtrl4TmrARefTi;
extern VAR(uint32, AUTOMATIC) LrnPinionCentr_Pim_StCtrl4TmrBRefTi;
extern VAR(float32, AUTOMATIC) LrnPinionCentr_Pim_StCtrl4TqErrRateLim;
extern VAR(float32, AUTOMATIC) LrnPinionCentr_Pim_StCtrl5IntglEnaOutpPrev;
extern VAR(float32, AUTOMATIC) LrnPinionCentr_Pim_StCtrl5PosnErrRateLim;
extern VAR(FilLpRec1, AUTOMATIC) LrnPinionCentr_Pim_StCtrl5RateLimdPosnErrLpFil;
extern VAR(FilLpRec1, AUTOMATIC) LrnPinionCentr_Pim_StCtrl5RateLimdTqErrLpFil;
extern VAR(uint32, AUTOMATIC) LrnPinionCentr_Pim_StCtrl5TmrARefTi;
extern VAR(uint32, AUTOMATIC) LrnPinionCentr_Pim_StCtrl5TmrBRefTi;
extern VAR(float32, AUTOMATIC) LrnPinionCentr_Pim_StCtrl5TqErrRateLim;
extern VAR(uint8, AUTOMATIC) LrnPinionCentr_Pim_StEstimdPrev;
extern VAR(float32, AUTOMATIC) LrnPinionCentr_Pim_TarHwAg;
extern VAR(float32, AUTOMATIC) LrnPinionCentr_Pim_TarMotVel;
extern VAR(float32, AUTOMATIC) LrnPinionCentr_Pim_TqCmdEstimdPrev;

/* IRVs */
extern VAR(float32, AUTOMATIC) LrnPinionCentr_Irv_TarA;
extern VAR(float32, AUTOMATIC) LrnPinionCentr_Irv_TarVel;

/* Arguments and Returns */
extern VAR(uint32, AUTOMATIC) LrnPinionCentr_Srv_GetRefTmr100MicroSec32bit_RefTmr;
extern VAR(uint32, AUTOMATIC) LrnPinionCentr_Srv_GetTiSpan100MicroSec32bit_RefTmr;
extern VAR(uint32, AUTOMATIC) LrnPinionCentr_Srv_GetTiSpan100MicroSec32bit_TiSpan;
extern VAR(float32, AUTOMATIC) LrnPinionCentr_Cli_SetInpPrm_TarVel;
extern VAR(float32, AUTOMATIC) LrnPinionCentr_Cli_SetInpPrm_TarA;


/*** Input Stubs ***/

#ifdef Rte_Read_HwAg_Val
# undef Rte_Read_HwAg_Val
#endif
#define Rte_Read_HwAg_Val(data) (*(data) = LrnPinionCentr_Ip_HwAg)

#ifdef Rte_Read_MotVelCrf_Val
# undef Rte_Read_MotVelCrf_Val
#endif
#define Rte_Read_MotVelCrf_Val(data) (*(data) = LrnPinionCentr_Ip_MotVelCrf)

#ifdef Rte_Read_PinionCentrLrnEna_Logl
# undef Rte_Read_PinionCentrLrnEna_Logl
#endif
#define Rte_Read_PinionCentrLrnEna_Logl(data) (*(data) = LrnPinionCentr_Ip_PinionCentrLrnEna)


/*** Output Stubs ***/

#ifdef Rte_Write_PinionCentrLrnCmd_Val
# undef Rte_Write_PinionCentrLrnCmd_Val
#endif
#define Rte_Write_PinionCentrLrnCmd_Val(data) (LrnPinionCentr_Op_PinionCentrLrnCmd = (data))

#ifdef Rte_Write_PinionCentrLrnHwCentr_Val
# undef Rte_Write_PinionCentrLrnHwCentr_Val
#endif
#define Rte_Write_PinionCentrLrnHwCentr_Val(data) (LrnPinionCentr_Op_PinionCentrLrnHwCentr = (data))

#ifdef Rte_Write_PinionCentrLrnHwTrvl_Val
# undef Rte_Write_PinionCentrLrnHwTrvl_Val
#endif
#define Rte_Write_PinionCentrLrnHwTrvl_Val(data) (LrnPinionCentr_Op_PinionCentrLrnHwTrvl = (data))

#ifdef Rte_Write_PinionCentrLrnSt_Val
# undef Rte_Write_PinionCentrLrnSt_Val
#endif
#define Rte_Write_PinionCentrLrnSt_Val(data) (LrnPinionCentr_Op_PinionCentrLrnSt = (data))


/*** Calibration Stubs ***/

#ifdef Rte_Prm_LrnPinionCentrDampgCtrlGain_Val
# undef Rte_Prm_LrnPinionCentrDampgCtrlGain_Val
#endif
#define Rte_Prm_LrnPinionCentrDampgCtrlGain_Val() (LrnPinionCentr_Cal_LrnPinionCentrDampgCtrlGain)

#ifdef Rte_Prm_LrnPinionCentrHldTq_Val
# undef Rte_Prm_LrnPinionCentrHldTq_Val
#endif
#define Rte_Prm_LrnPinionCentrHldTq_Val() (LrnPinionCentr_Cal_LrnPinionCentrHldTq)

#ifdef Rte_Prm_LrnPinionCentrHldTqErrThd_Val
# undef Rte_Prm_LrnPinionCentrHldTqErrThd_Val
#endif
#define Rte_Prm_LrnPinionCentrHldTqErrThd_Val() (LrnPinionCentr_Cal_LrnPinionCentrHldTqErrThd)

#ifdef Rte_Prm_LrnPinionCentrHldTqRateLim_Val
# undef Rte_Prm_LrnPinionCentrHldTqRateLim_Val
#endif
#define Rte_Prm_LrnPinionCentrHldTqRateLim_Val() (LrnPinionCentr_Cal_LrnPinionCentrHldTqRateLim)

#ifdef Rte_Prm_LrnPinionCentrHwPosnErrThd_Val
# undef Rte_Prm_LrnPinionCentrHwPosnErrThd_Val
#endif
#define Rte_Prm_LrnPinionCentrHwPosnErrThd_Val() (LrnPinionCentr_Cal_LrnPinionCentrHwPosnErrThd)

#ifdef Rte_Prm_LrnPinionCentrIntglCtrlGain_Val
# undef Rte_Prm_LrnPinionCentrIntglCtrlGain_Val
#endif
#define Rte_Prm_LrnPinionCentrIntglCtrlGain_Val() (LrnPinionCentr_Cal_LrnPinionCentrIntglCtrlGain)

#ifdef Rte_Prm_LrnPinionCentrMaxTqCmd_Val
# undef Rte_Prm_LrnPinionCentrMaxTqCmd_Val
#endif
#define Rte_Prm_LrnPinionCentrMaxTqCmd_Val() (LrnPinionCentr_Cal_LrnPinionCentrMaxTqCmd)

#ifdef Rte_Prm_LrnPinionCentrMinMotTq_Val
# undef Rte_Prm_LrnPinionCentrMinMotTq_Val
#endif
#define Rte_Prm_LrnPinionCentrMinMotTq_Val() (LrnPinionCentr_Cal_LrnPinionCentrMinMotTq)

#ifdef Rte_Prm_LrnPinionCentrMotVelThd_Val
# undef Rte_Prm_LrnPinionCentrMotVelThd_Val
#endif
#define Rte_Prm_LrnPinionCentrMotVelThd_Val() (LrnPinionCentr_Cal_LrnPinionCentrMotVelThd)

#ifdef Rte_Prm_LrnPinionCentrPropCtrlGain_Val
# undef Rte_Prm_LrnPinionCentrPropCtrlGain_Val
#endif
#define Rte_Prm_LrnPinionCentrPropCtrlGain_Val() (LrnPinionCentr_Cal_LrnPinionCentrPropCtrlGain)

#ifdef Rte_Prm_LrnPinionCentrTiOutThd_Val
# undef Rte_Prm_LrnPinionCentrTiOutThd_Val
#endif
#define Rte_Prm_LrnPinionCentrTiOutThd_Val() (LrnPinionCentr_Cal_LrnPinionCentrTiOutThd)

#ifdef Rte_Prm_LrnPinionCentrTiThd_Val
# undef Rte_Prm_LrnPinionCentrTiThd_Val
#endif
#define Rte_Prm_LrnPinionCentrTiThd_Val() (LrnPinionCentr_Cal_LrnPinionCentrTiThd)

#ifdef Rte_Prm_SysGlbPrmSysKineRat_Val
# undef Rte_Prm_SysGlbPrmSysKineRat_Val
#endif
#define Rte_Prm_SysGlbPrmSysKineRat_Val() (LrnPinionCentr_Cal_SysGlbPrmSysKineRat)


/*** PIM Stubs ***/

#ifdef Rte_Pim_dLrnPinionCentrHwPosnCmd
# undef Rte_Pim_dLrnPinionCentrHwPosnCmd
#endif
#define Rte_Pim_dLrnPinionCentrHwPosnCmd() (&LrnPinionCentr_Pim_dLrnPinionCentrHwPosnCmd)

#ifdef Rte_Pim_MaxHwPosnPrev
# undef Rte_Pim_MaxHwPosnPrev
#endif
#define Rte_Pim_MaxHwPosnPrev() (&LrnPinionCentr_Pim_MaxHwPosnPrev)

#ifdef Rte_Pim_MinHwPosnPrev
# undef Rte_Pim_MinHwPosnPrev
#endif
#define Rte_Pim_MinHwPosnPrev() (&LrnPinionCentr_Pim_MinHwPosnPrev)

#ifdef Rte_Pim_PinionCentrLrnEnaPrev
# undef Rte_Pim_PinionCentrLrnEnaPrev
#endif
#define Rte_Pim_PinionCentrLrnEnaPrev() (&LrnPinionCentr_Pim_PinionCentrLrnEnaPrev)

#ifdef Rte_Pim_PinionCentrLrnHwCentrPrev
# undef Rte_Pim_PinionCentrLrnHwCentrPrev
#endif
#define Rte_Pim_PinionCentrLrnHwCentrPrev() (&LrnPinionCentr_Pim_PinionCentrLrnHwCentrPrev)

#ifdef Rte_Pim_PinionCentrLrnHwTrvlPrev
# undef Rte_Pim_PinionCentrLrnHwTrvlPrev
#endif
#define Rte_Pim_PinionCentrLrnHwTrvlPrev() (&LrnPinionCentr_Pim_PinionCentrLrnHwTrvlPrev)

#ifdef Rte_Pim_StCtrl1PosnErrRateLim
# undef Rte_Pim_StCtrl1PosnErrRateLim
#endif
#define Rte_Pim_StCtrl1PosnErrRateLim() (&LrnPinionCentr_Pim_StCtrl1PosnErrRateLim)

#ifdef Rte_Pim_StCtrl1RateLimdPosnErrLpFil
# undef Rte_Pim_StCtrl1RateLimdPosnErrLpFil
#endif
#define Rte_Pim_StCtrl1RateLimdPosnErrLpFil() (&LrnPinionCentr_Pim_StCtrl1RateLimdPosnErrLpFil)

#ifdef Rte_Pim_StCtrl1TmrARefTi
# undef Rte_Pim_StCtrl1TmrARefTi
#endif
#define Rte_Pim_StCtrl1TmrARefTi() (&LrnPinionCentr_Pim_StCtrl1TmrARefTi)

#ifdef Rte_Pim_StCtrl1TmrBRefTi
# undef Rte_Pim_StCtrl1TmrBRefTi
#endif
#define Rte_Pim_StCtrl1TmrBRefTi() (&LrnPinionCentr_Pim_StCtrl1TmrBRefTi)

#ifdef Rte_Pim_StCtrl2RateLimdTqErrLpFil
# undef Rte_Pim_StCtrl2RateLimdTqErrLpFil
#endif
#define Rte_Pim_StCtrl2RateLimdTqErrLpFil() (&LrnPinionCentr_Pim_StCtrl2RateLimdTqErrLpFil)

#ifdef Rte_Pim_StCtrl2TmrARefTi
# undef Rte_Pim_StCtrl2TmrARefTi
#endif
#define Rte_Pim_StCtrl2TmrARefTi() (&LrnPinionCentr_Pim_StCtrl2TmrARefTi)

#ifdef Rte_Pim_StCtrl2TmrBRefTi
# undef Rte_Pim_StCtrl2TmrBRefTi
#endif
#define Rte_Pim_StCtrl2TmrBRefTi() (&LrnPinionCentr_Pim_StCtrl2TmrBRefTi)

#ifdef Rte_Pim_StCtrl2TqErrRateLim
# undef Rte_Pim_StCtrl2TqErrRateLim
#endif
#define Rte_Pim_StCtrl2TqErrRateLim() (&LrnPinionCentr_Pim_StCtrl2TqErrRateLim)

#ifdef Rte_Pim_StCtrl3PosnErrRateLim
# undef Rte_Pim_StCtrl3PosnErrRateLim
#endif
#define Rte_Pim_StCtrl3PosnErrRateLim() (&LrnPinionCentr_Pim_StCtrl3PosnErrRateLim)

#ifdef Rte_Pim_StCtrl3RateLimdPosnErrLpFil
# undef Rte_Pim_StCtrl3RateLimdPosnErrLpFil
#endif
#define Rte_Pim_StCtrl3RateLimdPosnErrLpFil() (&LrnPinionCentr_Pim_StCtrl3RateLimdPosnErrLpFil)

#ifdef Rte_Pim_StCtrl3RateLimdTqErrLpFil
# undef Rte_Pim_StCtrl3RateLimdTqErrLpFil
#endif
#define Rte_Pim_StCtrl3RateLimdTqErrLpFil() (&LrnPinionCentr_Pim_StCtrl3RateLimdTqErrLpFil)

#ifdef Rte_Pim_StCtrl3TmrARefTi
# undef Rte_Pim_StCtrl3TmrARefTi
#endif
#define Rte_Pim_StCtrl3TmrARefTi() (&LrnPinionCentr_Pim_StCtrl3TmrARefTi)

#ifdef Rte_Pim_StCtrl3TmrBRefTi
# undef Rte_Pim_StCtrl3TmrBRefTi
#endif
#define Rte_Pim_StCtrl3TmrBRefTi() (&LrnPinionCentr_Pim_StCtrl3TmrBRefTi)

#ifdef Rte_Pim_StCtrl3TqErrRateLim
# undef Rte_Pim_StCtrl3TqErrRateLim
#endif
#define Rte_Pim_StCtrl3TqErrRateLim() (&LrnPinionCentr_Pim_StCtrl3TqErrRateLim)

#ifdef Rte_Pim_StCtrl4RateLimdTqErrLpFil
# undef Rte_Pim_StCtrl4RateLimdTqErrLpFil
#endif
#define Rte_Pim_StCtrl4RateLimdTqErrLpFil() (&LrnPinionCentr_Pim_StCtrl4RateLimdTqErrLpFil)

#ifdef Rte_Pim_StCtrl4TmrARefTi
# undef Rte_Pim_StCtrl4TmrARefTi
#endif
#define Rte_Pim_StCtrl4TmrARefTi() (&LrnPinionCentr_Pim_StCtrl4TmrARefTi)

#ifdef Rte_Pim_StCtrl4TmrBRefTi
# undef Rte_Pim_StCtrl4TmrBRefTi
#endif
#define Rte_Pim_StCtrl4TmrBRefTi() (&LrnPinionCentr_Pim_StCtrl4TmrBRefTi)

#ifdef Rte_Pim_StCtrl4TqErrRateLim
# undef Rte_Pim_StCtrl4TqErrRateLim
#endif
#define Rte_Pim_StCtrl4TqErrRateLim() (&LrnPinionCentr_Pim_StCtrl4TqErrRateLim)

#ifdef Rte_Pim_StCtrl5IntglEnaOutpPrev
# undef Rte_Pim_StCtrl5IntglEnaOutpPrev
#endif
#define Rte_Pim_StCtrl5IntglEnaOutpPrev() (&LrnPinionCentr_Pim_StCtrl5IntglEnaOutpPrev)

#ifdef Rte_Pim_StCtrl5PosnErrRateLim
# undef Rte_Pim_StCtrl5PosnErrRateLim
#endif
#define Rte_Pim_StCtrl5PosnErrRateLim() (&LrnPinionCentr_Pim_StCtrl5PosnErrRateLim)

#ifdef Rte_Pim_StCtrl5RateLimdPosnErrLpFil
# undef Rte_Pim_StCtrl5RateLimdPosnErrLpFil
#endif
#define Rte_Pim_StCtrl5RateLimdPosnErrLpFil() (&LrnPinionCentr_Pim_StCtrl5RateLimdPosnErrLpFil)

#ifdef Rte_Pim_StCtrl5RateLimdTqErrLpFil
# undef Rte_Pim_StCtrl5RateLimdTqErrLpFil
#endif
#define Rte_Pim_StCtrl5RateLimdTqErrLpFil() (&LrnPinionCentr_Pim_StCtrl5RateLimdTqErrLpFil)

#ifdef Rte_Pim_StCtrl5TmrARefTi
# undef Rte_Pim_StCtrl5TmrARefTi
#endif
#define Rte_Pim_StCtrl5TmrARefTi() (&LrnPinionCentr_Pim_StCtrl5TmrARefTi)

#ifdef Rte_Pim_StCtrl5TmrBRefTi
# undef Rte_Pim_StCtrl5TmrBRefTi
#endif
#define Rte_Pim_StCtrl5TmrBRefTi() (&LrnPinionCentr_Pim_StCtrl5TmrBRefTi)

#ifdef Rte_Pim_StCtrl5TqErrRateLim
# undef Rte_Pim_StCtrl5TqErrRateLim
#endif
#define Rte_Pim_StCtrl5TqErrRateLim() (&LrnPinionCentr_Pim_StCtrl5TqErrRateLim)

#ifdef Rte_Pim_StEstimdPrev
# undef Rte_Pim_StEstimdPrev
#endif
#define Rte_Pim_StEstimdPrev() (&LrnPinionCentr_Pim_StEstimdPrev)

#ifdef Rte_Pim_TarHwAg
# undef Rte_Pim_TarHwAg
#endif
#define Rte_Pim_TarHwAg() (&LrnPinionCentr_Pim_TarHwAg)

#ifdef Rte_Pim_TarMotVel
# undef Rte_Pim_TarMotVel
#endif
#define Rte_Pim_TarMotVel() (&LrnPinionCentr_Pim_TarMotVel)

#ifdef Rte_Pim_TqCmdEstimdPrev
# undef Rte_Pim_TqCmdEstimdPrev
#endif
#define Rte_Pim_TqCmdEstimdPrev() (&LrnPinionCentr_Pim_TqCmdEstimdPrev)


/*** IRV Stubs ***/

#ifdef Rte_IrvRead_LrnPinionCentrPer1_TarA
# undef Rte_IrvRead_LrnPinionCentrPer1_TarA
#endif
#define Rte_IrvRead_LrnPinionCentrPer1_TarA() (LrnPinionCentr_Irv_TarA)

#ifdef Rte_IrvWrite_SetInpPrm_TarA
# undef Rte_IrvWrite_SetInpPrm_TarA
#endif
#define Rte_IrvWrite_SetInpPrm_TarA(data) (LrnPinionCentr_Irv_TarA = (data))

#ifdef Rte_IrvRead_LrnPinionCentrPer1_TarVel
# undef Rte_IrvRead_LrnPinionCentrPer1_TarVel
#endif
#define Rte_IrvRead_LrnPinionCentrPer1_TarVel() (LrnPinionCentr_Irv_TarVel)

#ifdef Rte_IrvWrite_SetInpPrm_TarVel
# undef Rte_IrvWrite_SetInpPrm_TarVel
#endif
#define Rte_IrvWrite_SetInpPrm_TarVel(data) (LrnPinionCentr_Irv_TarVel = (data))


/*** Client Stub ***/

extern FUNC(void, AUTOMATIC) Rte_Stub(void);


#endif
