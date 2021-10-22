/******************************************************************************************************************
* Copyright 2016 Nxtr
* Nxtr Confidential
*
* Module File Name:   Rte_Stubs.c
* Module Description: Stubs for Polyspace analysis.  Generated from TL109A_SwcSuprt.
* Project:            CBD
* Author:             Owen Tosh
******************************************************************************************************************/


#include "Rte_McalErrHndlg.h"
#include "float.h"


/*** Server Port Stubs ***/

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_McalErrHndlg_MCalReadVrfyFailFltInfo_Oper(uint8 PrphlId_Arg, uint16 ErrId_Arg)
{
    McalErrHndlg_Srv_MCalReadVrfyFailFltInfo_PrphlId = PrphlId_Arg;
    McalErrHndlg_Srv_MCalReadVrfyFailFltInfo_ErrId = ErrId_Arg;
    return (Std_ReturnType)0U;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_McalErrHndlg_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
{
    McalErrHndlg_Srv_SetNtcSts_NtcNr = NtcNr_Arg;
    McalErrHndlg_Srv_SetNtcSts_NtcStInfo = NtcStInfo_Arg;
    McalErrHndlg_Srv_SetNtcSts_NtcSts = NtcSts_Arg;
    McalErrHndlg_Srv_SetNtcSts_DebStep = DebStep_Arg;
    return McalErrHndlg_Srv_SetNtcSts_Return;
}


/*** Client Port Stubs ***/

FUNC(void, AUTOMATIC) Rte_Stub(void)
{
    McalErrHndlgInit1();
    McalErrHndlgPer1();
}

