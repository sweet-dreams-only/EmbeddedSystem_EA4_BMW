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
extern VAR(float32, AUTOMATIC) LrndRackCentr_Ip_HwAg;
extern VAR(float32, AUTOMATIC) LrndRackCentr_Ip_MotTqCmd;
extern VAR(float32, AUTOMATIC) LrndRackCentr_Ip_MotVelCrf;
extern VAR(boolean, AUTOMATIC) LrndRackCentr_Ip_PinionCentrLrnEna;
extern VAR(float32, AUTOMATIC) LrndRackCentr_Ip_PinionCentrLrnHwCentr;
extern VAR(float32, AUTOMATIC) LrndRackCentr_Ip_PinionCentrLrnHwTrvl;
extern VAR(uint8, AUTOMATIC) LrndRackCentr_Ip_PinionCentrLrnSt;

/* Outputs */
extern VAR(boolean, AUTOMATIC) LrndRackCentr_Op_LongTermRackCentrCmpl;
extern VAR(boolean, AUTOMATIC) LrndRackCentr_Op_RackCentrCmpl;
extern VAR(boolean, AUTOMATIC) LrndRackCentr_Op_RackCentrMotAgErrPrsnt;
extern VAR(boolean, AUTOMATIC) LrndRackCentr_Op_RackCentrMotAgVld;
extern VAR(float32, AUTOMATIC) LrndRackCentr_Op_RackCentrPinionAg;
extern VAR(float32, AUTOMATIC) LrndRackCentr_Op_TotRackTrvl;

/* Calibrations */
extern CONST(boolean, AUTOMATIC) LrndRackCentr_Cal_LrndRackCentrAllwManIniLrng;
extern CONST(float32, AUTOMATIC) LrndRackCentr_Cal_LrndRackCentrConfTrvlThd;
extern CONST(float32, AUTOMATIC) LrndRackCentr_Cal_LrndRackCentrHwAgFilFrq;
extern CONST(float32, AUTOMATIC) LrndRackCentr_Cal_LrndRackCentrMinMaxAdjmtFac;
extern CONST(float32, AUTOMATIC) LrndRackCentr_Cal_LrndRackCentrMotTqThd;
extern CONST(float32, AUTOMATIC) LrndRackCentr_Cal_LrndRackCentrMotVelThd;
extern CONST(float32, AUTOMATIC) LrndRackCentr_Cal_LrndRackCentrRackCentrPosnChgAllwd;
extern CONST(uint16, AUTOMATIC) LrndRackCentr_Cal_LrndRackCentrTiThd;
extern CONST(float32, AUTOMATIC) LrndRackCentr_Cal_SysGlbPrmSysKineRat;

/* PIMs */
extern VAR(LrndRackCentrNvmRec1, AUTOMATIC) LrndRackCentr_Pim_LrndRackCentrNvm;
extern VAR(FilLpRec1, AUTOMATIC) LrndRackCentr_Pim_HwAgFil;
extern VAR(float32, AUTOMATIC) LrndRackCentr_Pim_ManLrndRackCentrNegEot;
extern VAR(boolean, AUTOMATIC) LrndRackCentr_Pim_ManLrndRackCentrNegEotVld;
extern VAR(float32, AUTOMATIC) LrndRackCentr_Pim_ManLrndRackCentrPosEot;
extern VAR(boolean, AUTOMATIC) LrndRackCentr_Pim_ManLrndRackCentrPosEotVld;
extern VAR(uint32, AUTOMATIC) LrndRackCentr_Pim_RackCentrMaxTmr;
extern VAR(uint32, AUTOMATIC) LrndRackCentr_Pim_RackCentrMinTmr;
extern VAR(float32, AUTOMATIC) LrndRackCentr_Pim_RackCentrPinionAgPrev;

/* Arguments and Returns */
extern VAR(uint32, AUTOMATIC) LrndRackCentr_Srv_GetRefTmr100MicroSec32bit_RefTmr;
extern VAR(uint32, AUTOMATIC) LrndRackCentr_Srv_GetTiSpan100MicroSec32bit_RefTmr;
extern VAR(uint32, AUTOMATIC) LrndRackCentr_Srv_GetTiSpan100MicroSec32bit_TiSpan;


/*** Input Stubs ***/

#ifdef Rte_Read_HwAg_Val
# undef Rte_Read_HwAg_Val
#endif
#define Rte_Read_HwAg_Val(data) (*(data) = LrndRackCentr_Ip_HwAg)

#ifdef Rte_Read_MotTqCmd_Val
# undef Rte_Read_MotTqCmd_Val
#endif
#define Rte_Read_MotTqCmd_Val(data) (*(data) = LrndRackCentr_Ip_MotTqCmd)

#ifdef Rte_Read_MotVelCrf_Val
# undef Rte_Read_MotVelCrf_Val
#endif
#define Rte_Read_MotVelCrf_Val(data) (*(data) = LrndRackCentr_Ip_MotVelCrf)

#ifdef Rte_Read_PinionCentrLrnEna_Logl
# undef Rte_Read_PinionCentrLrnEna_Logl
#endif
#define Rte_Read_PinionCentrLrnEna_Logl(data) (*(data) = LrndRackCentr_Ip_PinionCentrLrnEna)

#ifdef Rte_Read_PinionCentrLrnHwCentr_Val
# undef Rte_Read_PinionCentrLrnHwCentr_Val
#endif
#define Rte_Read_PinionCentrLrnHwCentr_Val(data) (*(data) = LrndRackCentr_Ip_PinionCentrLrnHwCentr)

#ifdef Rte_Read_PinionCentrLrnHwTrvl_Val
# undef Rte_Read_PinionCentrLrnHwTrvl_Val
#endif
#define Rte_Read_PinionCentrLrnHwTrvl_Val(data) (*(data) = LrndRackCentr_Ip_PinionCentrLrnHwTrvl)

#ifdef Rte_Read_PinionCentrLrnSt_Val
# undef Rte_Read_PinionCentrLrnSt_Val
#endif
#define Rte_Read_PinionCentrLrnSt_Val(data) (*(data) = LrndRackCentr_Ip_PinionCentrLrnSt)


/*** Output Stubs ***/

#ifdef Rte_Write_LongTermRackCentrCmpl_Logl
# undef Rte_Write_LongTermRackCentrCmpl_Logl
#endif
#define Rte_Write_LongTermRackCentrCmpl_Logl(data) (LrndRackCentr_Op_LongTermRackCentrCmpl = (data))

#ifdef Rte_Write_RackCentrCmpl_Logl
# undef Rte_Write_RackCentrCmpl_Logl
#endif
#define Rte_Write_RackCentrCmpl_Logl(data) (LrndRackCentr_Op_RackCentrCmpl = (data))

#ifdef Rte_Write_RackCentrMotAgErrPrsnt_Logl
# undef Rte_Write_RackCentrMotAgErrPrsnt_Logl
#endif
#define Rte_Write_RackCentrMotAgErrPrsnt_Logl(data) (LrndRackCentr_Op_RackCentrMotAgErrPrsnt = (data))

#ifdef Rte_Write_RackCentrMotAgVld_Logl
# undef Rte_Write_RackCentrMotAgVld_Logl
#endif
#define Rte_Write_RackCentrMotAgVld_Logl(data) (LrndRackCentr_Op_RackCentrMotAgVld = (data))

#ifdef Rte_Write_RackCentrPinionAg_Val
# undef Rte_Write_RackCentrPinionAg_Val
#endif
#define Rte_Write_RackCentrPinionAg_Val(data) (LrndRackCentr_Op_RackCentrPinionAg = (data))

#ifdef Rte_Write_TotRackTrvl_Val
# undef Rte_Write_TotRackTrvl_Val
#endif
#define Rte_Write_TotRackTrvl_Val(data) (LrndRackCentr_Op_TotRackTrvl = (data))


/*** Calibration Stubs ***/

#ifdef Rte_Prm_LrndRackCentrAllwManIniLrng_Logl
# undef Rte_Prm_LrndRackCentrAllwManIniLrng_Logl
#endif
#define Rte_Prm_LrndRackCentrAllwManIniLrng_Logl() (LrndRackCentr_Cal_LrndRackCentrAllwManIniLrng)

#ifdef Rte_Prm_LrndRackCentrConfTrvlThd_Val
# undef Rte_Prm_LrndRackCentrConfTrvlThd_Val
#endif
#define Rte_Prm_LrndRackCentrConfTrvlThd_Val() (LrndRackCentr_Cal_LrndRackCentrConfTrvlThd)

#ifdef Rte_Prm_LrndRackCentrHwAgFilFrq_Val
# undef Rte_Prm_LrndRackCentrHwAgFilFrq_Val
#endif
#define Rte_Prm_LrndRackCentrHwAgFilFrq_Val() (LrndRackCentr_Cal_LrndRackCentrHwAgFilFrq)

#ifdef Rte_Prm_LrndRackCentrMinMaxAdjmtFac_Val
# undef Rte_Prm_LrndRackCentrMinMaxAdjmtFac_Val
#endif
#define Rte_Prm_LrndRackCentrMinMaxAdjmtFac_Val() (LrndRackCentr_Cal_LrndRackCentrMinMaxAdjmtFac)

#ifdef Rte_Prm_LrndRackCentrMotTqThd_Val
# undef Rte_Prm_LrndRackCentrMotTqThd_Val
#endif
#define Rte_Prm_LrndRackCentrMotTqThd_Val() (LrndRackCentr_Cal_LrndRackCentrMotTqThd)

#ifdef Rte_Prm_LrndRackCentrMotVelThd_Val
# undef Rte_Prm_LrndRackCentrMotVelThd_Val
#endif
#define Rte_Prm_LrndRackCentrMotVelThd_Val() (LrndRackCentr_Cal_LrndRackCentrMotVelThd)

#ifdef Rte_Prm_LrndRackCentrRackCentrPosnChgAllwd_Val
# undef Rte_Prm_LrndRackCentrRackCentrPosnChgAllwd_Val
#endif
#define Rte_Prm_LrndRackCentrRackCentrPosnChgAllwd_Val() (LrndRackCentr_Cal_LrndRackCentrRackCentrPosnChgAllwd)

#ifdef Rte_Prm_LrndRackCentrTiThd_Val
# undef Rte_Prm_LrndRackCentrTiThd_Val
#endif
#define Rte_Prm_LrndRackCentrTiThd_Val() (LrndRackCentr_Cal_LrndRackCentrTiThd)

#ifdef Rte_Prm_SysGlbPrmSysKineRat_Val
# undef Rte_Prm_SysGlbPrmSysKineRat_Val
#endif
#define Rte_Prm_SysGlbPrmSysKineRat_Val() (LrndRackCentr_Cal_SysGlbPrmSysKineRat)


/*** PIM Stubs ***/

#ifdef Rte_Pim_LrndRackCentrNvm
# undef Rte_Pim_LrndRackCentrNvm
#endif
#define Rte_Pim_LrndRackCentrNvm() (&LrndRackCentr_Pim_LrndRackCentrNvm)

#ifdef Rte_Pim_HwAgFil
# undef Rte_Pim_HwAgFil
#endif
#define Rte_Pim_HwAgFil() (&LrndRackCentr_Pim_HwAgFil)

#ifdef Rte_Pim_ManLrndRackCentrNegEot
# undef Rte_Pim_ManLrndRackCentrNegEot
#endif
#define Rte_Pim_ManLrndRackCentrNegEot() (&LrndRackCentr_Pim_ManLrndRackCentrNegEot)

#ifdef Rte_Pim_ManLrndRackCentrNegEotVld
# undef Rte_Pim_ManLrndRackCentrNegEotVld
#endif
#define Rte_Pim_ManLrndRackCentrNegEotVld() (&LrndRackCentr_Pim_ManLrndRackCentrNegEotVld)

#ifdef Rte_Pim_ManLrndRackCentrPosEot
# undef Rte_Pim_ManLrndRackCentrPosEot
#endif
#define Rte_Pim_ManLrndRackCentrPosEot() (&LrndRackCentr_Pim_ManLrndRackCentrPosEot)

#ifdef Rte_Pim_ManLrndRackCentrPosEotVld
# undef Rte_Pim_ManLrndRackCentrPosEotVld
#endif
#define Rte_Pim_ManLrndRackCentrPosEotVld() (&LrndRackCentr_Pim_ManLrndRackCentrPosEotVld)

#ifdef Rte_Pim_RackCentrMaxTmr
# undef Rte_Pim_RackCentrMaxTmr
#endif
#define Rte_Pim_RackCentrMaxTmr() (&LrndRackCentr_Pim_RackCentrMaxTmr)

#ifdef Rte_Pim_RackCentrMinTmr
# undef Rte_Pim_RackCentrMinTmr
#endif
#define Rte_Pim_RackCentrMinTmr() (&LrndRackCentr_Pim_RackCentrMinTmr)

#ifdef Rte_Pim_RackCentrPinionAgPrev
# undef Rte_Pim_RackCentrPinionAgPrev
#endif
#define Rte_Pim_RackCentrPinionAgPrev() (&LrndRackCentr_Pim_RackCentrPinionAgPrev)


/*** Client Stub ***/

extern FUNC(void, AUTOMATIC) Rte_Stub(void);


#endif
