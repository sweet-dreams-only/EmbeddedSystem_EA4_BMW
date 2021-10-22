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
extern VAR(BmwRtIdx1, AUTOMATIC) BmwTunSetHndlr_Ip_BmwRtIdx;
extern VAR(boolean, AUTOMATIC) BmwTunSetHndlr_Ip_BmwRtIdxVld;
extern VAR(boolean, AUTOMATIC) BmwTunSetHndlr_Ip_TunSetHndlrEna;

/* Outputs */
extern VAR(uint8, AUTOMATIC) BmwTunSetHndlr_Op_DesIninIdx;
extern VAR(uint8, AUTOMATIC) BmwTunSetHndlr_Op_DesIninOptSetAIdx;
extern VAR(uint8, AUTOMATIC) BmwTunSetHndlr_Op_DesRtIdx;

/* Calibrations */
extern CONST(uint16, AUTOMATIC) BmwTunSetHndlr_Cal_BmwTunSetHndlrBmwRtIdxDebThd;
extern CONST(uint8, AUTOMATIC) BmwTunSetHndlr_Cal_BmwTunSetHndlrCptDisadOutp;
extern CONST(uint8, AUTOMATIC) BmwTunSetHndlr_Cal_BmwTunSetHndlrNrOfMotVrnt;
extern CONST(uint8, AUTOMATIC) BmwTunSetHndlr_Cal_BmwTunSetHndlrNrOfTunSet;
extern CONST(uint8, AUTOMATIC) BmwTunSetHndlr_Cal_BmwTunSetHndlrOvrdDesRtIdx;

/* PIMs */
extern VAR(BmwDesIninIdxRec1, AUTOMATIC) BmwTunSetHndlr_Pim_BmwDesIninIdx;
extern VAR(BmwDesIninOptSetAIdxRec1, AUTOMATIC) BmwTunSetHndlr_Pim_BmwDesIninOptSetAIdx;
extern VAR(uint32, AUTOMATIC) BmwTunSetHndlr_Pim_BmwRtIdxTi;
extern VAR(BmwRtIdx1, AUTOMATIC) BmwTunSetHndlr_Pim_DebBmwRtIdx;
extern VAR(uint8, AUTOMATIC) BmwTunSetHndlr_Pim_LstVldIdx;
extern VAR(BmwRtIdx1, AUTOMATIC) BmwTunSetHndlr_Pim_PrevBmwRtIdx;

/* Arguments and Returns */
extern VAR(uint8, AUTOMATIC) BmwTunSetHndlr_Srv_BmwDesIninIdx_GetErrorStatus_ReqResPtr;
extern VAR(Std_ReturnType, AUTOMATIC) BmwTunSetHndlr_Srv_BmwDesIninIdx_GetErrorStatus_Return;
extern VAR(boolean, AUTOMATIC) BmwTunSetHndlr_Srv_BmwDesIninIdx_SetRamBlockStatus_BlockChanged;
extern VAR(Std_ReturnType, AUTOMATIC) BmwTunSetHndlr_Srv_BmwDesIninIdx_SetRamBlockStatus_Return;
extern VAR(uint8, AUTOMATIC) BmwTunSetHndlr_Srv_BmwDesIninOptSetAIdx_GetErrorStatus_ReqResPtr;
extern VAR(Std_ReturnType, AUTOMATIC) BmwTunSetHndlr_Srv_BmwDesIninOptSetAIdx_GetErrorStatus_Return;
extern VAR(boolean, AUTOMATIC) BmwTunSetHndlr_Srv_BmwDesIninOptSetAIdx_SetRamBlockStatus_BlockChanged;
extern VAR(Std_ReturnType, AUTOMATIC) BmwTunSetHndlr_Srv_BmwDesIninOptSetAIdx_SetRamBlockStatus_Return;
extern VAR(uint32, AUTOMATIC) BmwTunSetHndlr_Srv_GetRefTmr100MicroSec32bit_RefTmr;
extern VAR(uint32, AUTOMATIC) BmwTunSetHndlr_Srv_GetTiSpan100MicroSec32bit_RefTmr;
extern VAR(uint32, AUTOMATIC) BmwTunSetHndlr_Srv_GetTiSpan100MicroSec32bit_TiSpan;
extern VAR(NtcNr1, AUTOMATIC) BmwTunSetHndlr_Srv_SetNtcSts_NtcNr;
extern VAR(uint8, AUTOMATIC) BmwTunSetHndlr_Srv_SetNtcSts_NtcStInfo;
extern VAR(NtcSts1, AUTOMATIC) BmwTunSetHndlr_Srv_SetNtcSts_NtcSts;
extern VAR(uint16, AUTOMATIC) BmwTunSetHndlr_Srv_SetNtcSts_DebStep;
extern VAR(Std_ReturnType, AUTOMATIC) BmwTunSetHndlr_Srv_SetNtcSts_Return;
extern VAR(uint8, AUTOMATIC) BmwTunSetHndlr_Cli_MotVrntRead_BmwDesIninOptSetAIdx;
extern VAR(Std_ReturnType, AUTOMATIC) BmwTunSetHndlr_Cli_MotVrntRead_Return;
extern VAR(uint8, AUTOMATIC) BmwTunSetHndlr_Cli_MotVrntWr_BmwDesIninOptSetAIdx;
extern VAR(Std_ReturnType, AUTOMATIC) BmwTunSetHndlr_Cli_MotVrntWr_Return;
extern VAR(uint8, AUTOMATIC) BmwTunSetHndlr_Cli_TunVrntRead_BmwDesIninIdx;
extern VAR(Std_ReturnType, AUTOMATIC) BmwTunSetHndlr_Cli_TunVrntRead_Return;
extern VAR(uint8, AUTOMATIC) BmwTunSetHndlr_Cli_TunVrntWr_BmwDesIninIdx;
extern VAR(Std_ReturnType, AUTOMATIC) BmwTunSetHndlr_Cli_TunVrntWr_Return;


/*** Input Stubs ***/

#ifdef Rte_Read_BmwRtIdx_Val
# undef Rte_Read_BmwRtIdx_Val
#else
#error Rte_Read_BmwRtIdx_Val is missing
#endif
#define Rte_Read_BmwRtIdx_Val(data) (*(data) = BmwTunSetHndlr_Ip_BmwRtIdx)

#ifdef Rte_Read_BmwRtIdxVld_Logl
# undef Rte_Read_BmwRtIdxVld_Logl
#else
#error Rte_Read_BmwRtIdxVld_Logl is missing
#endif
#define Rte_Read_BmwRtIdxVld_Logl(data) (*(data) = BmwTunSetHndlr_Ip_BmwRtIdxVld)

#ifdef Rte_Read_TunSetHndlrEna_Logl
# undef Rte_Read_TunSetHndlrEna_Logl
#else
#error Rte_Read_TunSetHndlrEna_Logl is missing
#endif
#define Rte_Read_TunSetHndlrEna_Logl(data) (*(data) = BmwTunSetHndlr_Ip_TunSetHndlrEna)


/*** Output Stubs ***/

#ifdef Rte_Write_DesIninIdx_Val
# undef Rte_Write_DesIninIdx_Val
#else
#error Rte_Write_DesIninIdx_Val is missing
#endif
#define Rte_Write_DesIninIdx_Val(data) (BmwTunSetHndlr_Op_DesIninIdx = (data))

#ifdef Rte_Write_DesIninOptSetAIdx_Val
# undef Rte_Write_DesIninOptSetAIdx_Val
#else
#error Rte_Write_DesIninOptSetAIdx_Val is missing
#endif
#define Rte_Write_DesIninOptSetAIdx_Val(data) (BmwTunSetHndlr_Op_DesIninOptSetAIdx = (data))

#ifdef Rte_Write_DesRtIdx_Val
# undef Rte_Write_DesRtIdx_Val
#else
#error Rte_Write_DesRtIdx_Val is missing
#endif
#define Rte_Write_DesRtIdx_Val(data) (BmwTunSetHndlr_Op_DesRtIdx = (data))


/*** Calibration Stubs ***/

#ifdef Rte_Prm_BmwTunSetHndlrBmwRtIdxDebThd_Val
# undef Rte_Prm_BmwTunSetHndlrBmwRtIdxDebThd_Val
#else
#error Rte_Prm_BmwTunSetHndlrBmwRtIdxDebThd_Val is missing
#endif
#define Rte_Prm_BmwTunSetHndlrBmwRtIdxDebThd_Val() (BmwTunSetHndlr_Cal_BmwTunSetHndlrBmwRtIdxDebThd)

#ifdef Rte_Prm_BmwTunSetHndlrCptDisadOutp_Val
# undef Rte_Prm_BmwTunSetHndlrCptDisadOutp_Val
#else
#error Rte_Prm_BmwTunSetHndlrCptDisadOutp_Val is missing
#endif
#define Rte_Prm_BmwTunSetHndlrCptDisadOutp_Val() (BmwTunSetHndlr_Cal_BmwTunSetHndlrCptDisadOutp)

#ifdef Rte_Prm_BmwTunSetHndlrNrOfMotVrnt_Val
# undef Rte_Prm_BmwTunSetHndlrNrOfMotVrnt_Val
#else
#error Rte_Prm_BmwTunSetHndlrNrOfMotVrnt_Val is missing
#endif
#define Rte_Prm_BmwTunSetHndlrNrOfMotVrnt_Val() (BmwTunSetHndlr_Cal_BmwTunSetHndlrNrOfMotVrnt)

#ifdef Rte_Prm_BmwTunSetHndlrNrOfTunSet_Val
# undef Rte_Prm_BmwTunSetHndlrNrOfTunSet_Val
#else
#error Rte_Prm_BmwTunSetHndlrNrOfTunSet_Val is missing
#endif
#define Rte_Prm_BmwTunSetHndlrNrOfTunSet_Val() (BmwTunSetHndlr_Cal_BmwTunSetHndlrNrOfTunSet)

#ifdef Rte_Prm_BmwTunSetHndlrOvrdDesRtIdx_Val
# undef Rte_Prm_BmwTunSetHndlrOvrdDesRtIdx_Val
#else
#error Rte_Prm_BmwTunSetHndlrOvrdDesRtIdx_Val is missing
#endif
#define Rte_Prm_BmwTunSetHndlrOvrdDesRtIdx_Val() (BmwTunSetHndlr_Cal_BmwTunSetHndlrOvrdDesRtIdx)


/*** PIM Stubs ***/

#ifdef Rte_Pim_BmwDesIninIdx
# undef Rte_Pim_BmwDesIninIdx
#else
#error Rte_Pim_BmwDesIninIdx is missing
#endif
#define Rte_Pim_BmwDesIninIdx() (&BmwTunSetHndlr_Pim_BmwDesIninIdx)

#ifdef Rte_Pim_BmwDesIninOptSetAIdx
# undef Rte_Pim_BmwDesIninOptSetAIdx
#else
#error Rte_Pim_BmwDesIninOptSetAIdx is missing
#endif
#define Rte_Pim_BmwDesIninOptSetAIdx() (&BmwTunSetHndlr_Pim_BmwDesIninOptSetAIdx)

#ifdef Rte_Pim_BmwRtIdxTi
# undef Rte_Pim_BmwRtIdxTi
#else
#error Rte_Pim_BmwRtIdxTi is missing
#endif
#define Rte_Pim_BmwRtIdxTi() (&BmwTunSetHndlr_Pim_BmwRtIdxTi)

#ifdef Rte_Pim_DebBmwRtIdx
# undef Rte_Pim_DebBmwRtIdx
#else
#error Rte_Pim_DebBmwRtIdx is missing
#endif
#define Rte_Pim_DebBmwRtIdx() (&BmwTunSetHndlr_Pim_DebBmwRtIdx)

#ifdef Rte_Pim_LstVldIdx
# undef Rte_Pim_LstVldIdx
#else
#error Rte_Pim_LstVldIdx is missing
#endif
#define Rte_Pim_LstVldIdx() (&BmwTunSetHndlr_Pim_LstVldIdx)

#ifdef Rte_Pim_PrevBmwRtIdx
# undef Rte_Pim_PrevBmwRtIdx
#else
#error Rte_Pim_PrevBmwRtIdx is missing
#endif
#define Rte_Pim_PrevBmwRtIdx() (&BmwTunSetHndlr_Pim_PrevBmwRtIdx)


/*** Client Stub ***/

extern FUNC(void, AUTOMATIC) Rte_Stub(void);


#endif
