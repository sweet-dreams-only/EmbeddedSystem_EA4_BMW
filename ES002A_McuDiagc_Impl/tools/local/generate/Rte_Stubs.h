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
extern VAR(uint16, AUTOMATIC) McuDiagc_Ip_FastLoopCntr;
extern VAR(uint16, AUTOMATIC) McuDiagc_Ip_SlowLoopCntr;
extern VAR(SysSt1, AUTOMATIC) McuDiagc_Ip_SysSt;

/* Outputs */
extern VAR(uint16, AUTOMATIC) McuDiagc_Op_LoopCntr2MilliSec;

/* Calibrations */
extern CONST(uint16, AUTOMATIC) McuDiagc_Cal_McuDiagc2MilliSecCntrCompThd;
extern CONST(uint16, AUTOMATIC) McuDiagc_Cal_McuDiagcFltFailStep;
extern CONST(uint16, AUTOMATIC) McuDiagc_Cal_McuDiagcFltPassStep;

/* PIMs */
extern VAR(uint16, AUTOMATIC) McuDiagc_Pim_dMcuDiagcFastLoopCntrMax;
extern VAR(uint16, AUTOMATIC) McuDiagc_Pim_dMcuDiagcFastLoopCntrMin;
extern VAR(uint16, AUTOMATIC) McuDiagc_Pim_dMcuDiagcLoopCntr2MilliSecMotCtrlDif;
extern VAR(uint8, AUTOMATIC) McuDiagc_Pim_FastLoopCntrDiagcCfgd;
extern VAR(uint16, AUTOMATIC) McuDiagc_Pim_FastLoopCntrPrev;
extern VAR(uint16, AUTOMATIC) McuDiagc_Pim_LoopCntr2MilliSecStore;
extern VAR(uint16, AUTOMATIC) McuDiagc_Pim_LoopCntrPrev;

/* Arguments and Returns */
extern VAR(NtcNr1, AUTOMATIC) McuDiagc_Srv_SetNtcSts_NtcNr;
extern VAR(uint8, AUTOMATIC) McuDiagc_Srv_SetNtcSts_NtcStInfo;
extern VAR(NtcSts1, AUTOMATIC) McuDiagc_Srv_SetNtcSts_NtcSts;
extern VAR(uint16, AUTOMATIC) McuDiagc_Srv_SetNtcSts_DebStep;
extern VAR(Std_ReturnType, AUTOMATIC) McuDiagc_Srv_SetNtcSts_Return;


/*** Input Stubs ***/

#ifdef Rte_Read_FastLoopCntr_Val
# undef Rte_Read_FastLoopCntr_Val
#endif
#define Rte_Read_FastLoopCntr_Val(data) (*(data) = McuDiagc_Ip_FastLoopCntr)

#ifdef Rte_Read_SlowLoopCntr_Val
# undef Rte_Read_SlowLoopCntr_Val
#endif
#define Rte_Read_SlowLoopCntr_Val(data) (*(data) = McuDiagc_Ip_SlowLoopCntr)

#ifdef Rte_Read_SysSt_Val
# undef Rte_Read_SysSt_Val
#endif
#define Rte_Read_SysSt_Val(data) (*(data) = McuDiagc_Ip_SysSt)


/*** Output Stubs ***/

#ifdef Rte_Write_LoopCntr2MilliSec_Val
# undef Rte_Write_LoopCntr2MilliSec_Val
#endif
#define Rte_Write_LoopCntr2MilliSec_Val(data) (McuDiagc_Op_LoopCntr2MilliSec = (data))


/*** Calibration Stubs ***/

#ifdef Rte_Prm_McuDiagc2MilliSecCntrCompThd_Val
# undef Rte_Prm_McuDiagc2MilliSecCntrCompThd_Val
#endif
#define Rte_Prm_McuDiagc2MilliSecCntrCompThd_Val() (McuDiagc_Cal_McuDiagc2MilliSecCntrCompThd)

#ifdef Rte_Prm_McuDiagcFltFailStep_Val
# undef Rte_Prm_McuDiagcFltFailStep_Val
#endif
#define Rte_Prm_McuDiagcFltFailStep_Val() (McuDiagc_Cal_McuDiagcFltFailStep)

#ifdef Rte_Prm_McuDiagcFltPassStep_Val
# undef Rte_Prm_McuDiagcFltPassStep_Val
#endif
#define Rte_Prm_McuDiagcFltPassStep_Val() (McuDiagc_Cal_McuDiagcFltPassStep)


/*** PIM Stubs ***/

#ifdef Rte_Pim_dMcuDiagcFastLoopCntrMax
# undef Rte_Pim_dMcuDiagcFastLoopCntrMax
#endif
#define Rte_Pim_dMcuDiagcFastLoopCntrMax() (&McuDiagc_Pim_dMcuDiagcFastLoopCntrMax)

#ifdef Rte_Pim_dMcuDiagcFastLoopCntrMin
# undef Rte_Pim_dMcuDiagcFastLoopCntrMin
#endif
#define Rte_Pim_dMcuDiagcFastLoopCntrMin() (&McuDiagc_Pim_dMcuDiagcFastLoopCntrMin)

#ifdef Rte_Pim_dMcuDiagcLoopCntr2MilliSecMotCtrlDif
# undef Rte_Pim_dMcuDiagcLoopCntr2MilliSecMotCtrlDif
#endif
#define Rte_Pim_dMcuDiagcLoopCntr2MilliSecMotCtrlDif() (&McuDiagc_Pim_dMcuDiagcLoopCntr2MilliSecMotCtrlDif)

#ifdef Rte_Pim_FastLoopCntrDiagcCfgd
# undef Rte_Pim_FastLoopCntrDiagcCfgd
#endif
#define Rte_Pim_FastLoopCntrDiagcCfgd() (&McuDiagc_Pim_FastLoopCntrDiagcCfgd)

#ifdef Rte_Pim_FastLoopCntrPrev
# undef Rte_Pim_FastLoopCntrPrev
#endif
#define Rte_Pim_FastLoopCntrPrev() (&McuDiagc_Pim_FastLoopCntrPrev)

#ifdef Rte_Pim_LoopCntr2MilliSecStore
# undef Rte_Pim_LoopCntr2MilliSecStore
#endif
#define Rte_Pim_LoopCntr2MilliSecStore() (&McuDiagc_Pim_LoopCntr2MilliSecStore)

#ifdef Rte_Pim_LoopCntrPrev
# undef Rte_Pim_LoopCntrPrev
#endif
#define Rte_Pim_LoopCntrPrev() (&McuDiagc_Pim_LoopCntrPrev)


/*** Client Stub ***/

extern FUNC(void, AUTOMATIC) Rte_Stub(void);


#endif
