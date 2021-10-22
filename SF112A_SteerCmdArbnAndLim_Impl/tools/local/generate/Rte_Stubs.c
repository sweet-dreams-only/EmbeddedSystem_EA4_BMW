/******************************************************************************************************************
* Copyright 2016 Nxtr
* Nxtr Confidential
*
* Module File Name:   Rte_Stubs.c
* Module Description: Stubs for Polyspace analysis.  Generated from TL109A_SwcSuprt.
* Project:            CBD
* Author:             Owen Tosh
******************************************************************************************************************/


#include "Rte_SteerCmdArbnAndLim.h"
#include "float.h"


/*** Server Port Stubs ***/

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SteerCmdArbnAndLim_GetRefTmr100MicroSec32bit_Oper(uint32 * RefTmr_Arg)
{
    *RefTmr_Arg = SteerCmdArbnAndLim_Srv_GetRefTmr100MicroSec32bit_RefTmr;
    return (Std_ReturnType)0U;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SteerCmdArbnAndLim_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 * TiSpan_Arg)
{
    SteerCmdArbnAndLim_Srv_GetTiSpan100MicroSec32bit_RefTmr = RefTmr_Arg;
    *TiSpan_Arg = SteerCmdArbnAndLim_Srv_GetTiSpan100MicroSec32bit_TiSpan;
    return (Std_ReturnType)0U;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SteerCmdArbnAndLim_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
{
    SteerCmdArbnAndLim_Srv_SetNtcSts_NtcNr = NtcNr_Arg;
    SteerCmdArbnAndLim_Srv_SetNtcSts_NtcStInfo = NtcStInfo_Arg;
    SteerCmdArbnAndLim_Srv_SetNtcSts_NtcSts = NtcSts_Arg;
    SteerCmdArbnAndLim_Srv_SetNtcSts_DebStep = DebStep_Arg;
    return SteerCmdArbnAndLim_Srv_SetNtcSts_Return;
}


/*** Client Port Stubs ***/

FUNC(void, AUTOMATIC) Rte_Stub(void)
{
    SteerCmdArbnAndLimInit1();
    SteerCmdArbnAndLimPer1();
    SteerCmdArbnAndLim_Cli_SetManTqCmd_Return = SetManTqCmd_Oper(SteerCmdArbnAndLim_Cli_SetManTqCmd_ManTqCmd, SteerCmdArbnAndLim_Cli_SetManTqCmd_ManTqCmdEna);
}

