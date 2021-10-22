/******************************************************************************************************************
* Copyright 2016 Nxtr
* Nxtr Confidential
*
* Module File Name:   Rte_Stubs.c
* Module Description: Stubs for Polyspace analysis.  Generated from TL109A_SwcSuprt.
* Project:            CBD
* Author:             Owen Tosh
******************************************************************************************************************/


#include "Rte_BmwTunSetHndlr.h"
#include "float.h"


/*** Server Port Stubs ***/

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwTunSetHndlr_BmwDesIninIdx_GetErrorStatus(uint8 * ReqResPtr_Arg)
{
    *ReqResPtr_Arg = BmwTunSetHndlr_Srv_BmwDesIninIdx_GetErrorStatus_ReqResPtr;
    return BmwTunSetHndlr_Srv_BmwDesIninIdx_GetErrorStatus_Return;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwTunSetHndlr_BmwDesIninIdx_SetRamBlockStatus(boolean BlockChanged_Arg)
{
    BmwTunSetHndlr_Srv_BmwDesIninIdx_SetRamBlockStatus_BlockChanged = BlockChanged_Arg;
    return BmwTunSetHndlr_Srv_BmwDesIninIdx_SetRamBlockStatus_Return;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwTunSetHndlr_BmwDesIninOptSetAIdx_GetErrorStatus(uint8 * ReqResPtr_Arg)
{
    *ReqResPtr_Arg = BmwTunSetHndlr_Srv_BmwDesIninOptSetAIdx_GetErrorStatus_ReqResPtr;
    return BmwTunSetHndlr_Srv_BmwDesIninOptSetAIdx_GetErrorStatus_Return;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwTunSetHndlr_BmwDesIninOptSetAIdx_SetRamBlockStatus(boolean BlockChanged_Arg)
{
    BmwTunSetHndlr_Srv_BmwDesIninOptSetAIdx_SetRamBlockStatus_BlockChanged = BlockChanged_Arg;
    return BmwTunSetHndlr_Srv_BmwDesIninOptSetAIdx_SetRamBlockStatus_Return;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwTunSetHndlr_GetRefTmr100MicroSec32bit_Oper(uint32 * RefTmr_Arg)
{
    *RefTmr_Arg = BmwTunSetHndlr_Srv_GetRefTmr100MicroSec32bit_RefTmr;
    return (Std_ReturnType)0U;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwTunSetHndlr_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 * TiSpan_Arg)
{
    BmwTunSetHndlr_Srv_GetTiSpan100MicroSec32bit_RefTmr = RefTmr_Arg;
    *TiSpan_Arg = BmwTunSetHndlr_Srv_GetTiSpan100MicroSec32bit_TiSpan;
    return (Std_ReturnType)0U;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwTunSetHndlr_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
{
    BmwTunSetHndlr_Srv_SetNtcSts_NtcNr = NtcNr_Arg;
    BmwTunSetHndlr_Srv_SetNtcSts_NtcStInfo = NtcStInfo_Arg;
    BmwTunSetHndlr_Srv_SetNtcSts_NtcSts = NtcSts_Arg;
    BmwTunSetHndlr_Srv_SetNtcSts_DebStep = DebStep_Arg;
    return BmwTunSetHndlr_Srv_SetNtcSts_Return;
}


/*** Client Port Stubs ***/

FUNC(void, AUTOMATIC) Rte_Stub(void)
{
    BmwTunSetHndlrInit1();
    BmwTunSetHndlrPer1();
    BmwTunSetHndlr_Cli_MotVrntRead_Return = MotVrntRead_Oper(&BmwTunSetHndlr_Cli_MotVrntRead_BmwDesIninOptSetAIdx);
    BmwTunSetHndlr_Cli_MotVrntWr_Return = MotVrntWr_Oper(BmwTunSetHndlr_Cli_MotVrntWr_BmwDesIninOptSetAIdx);
    BmwTunSetHndlr_Cli_TunVrntRead_Return = TunVrntRead_Oper(&BmwTunSetHndlr_Cli_TunVrntRead_BmwDesIninIdx);
    BmwTunSetHndlr_Cli_TunVrntWr_Return = TunVrntWr_Oper(BmwTunSetHndlr_Cli_TunVrntWr_BmwDesIninIdx);
}

