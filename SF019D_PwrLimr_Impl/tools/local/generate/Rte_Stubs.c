/******************************************************************************************************************
* Copyright 2016 Nxtr
* Nxtr Confidential
*
* Module File Name:   Rte_Stubs.c
* Module Description: Stubs for Polyspace analysis.  Generated from TL109A_SwcSuprt.
* Project:            CBD
* Author:             Owen Tosh
******************************************************************************************************************/


#include "Rte_PwrLimr.h"
#include "float.h"


/*** Server Port Stubs ***/

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PwrLimr_GetRefTmr100MicroSec32bit_Oper(uint32 * RefTmr_Arg)
{
    *RefTmr_Arg = PwrLimr_Srv_GetRefTmr100MicroSec32bit_RefTmr;
    return (Std_ReturnType)0U;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PwrLimr_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 * TiSpan_Arg)
{
    PwrLimr_Srv_GetTiSpan100MicroSec32bit_RefTmr = RefTmr_Arg;
    *TiSpan_Arg = PwrLimr_Srv_GetTiSpan100MicroSec32bit_TiSpan;
    return (Std_ReturnType)0U;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PwrLimr_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
{
    PwrLimr_Srv_SetNtcSts_NtcNr = NtcNr_Arg;
    PwrLimr_Srv_SetNtcSts_NtcStInfo = NtcStInfo_Arg;
    PwrLimr_Srv_SetNtcSts_NtcSts = NtcSts_Arg;
    PwrLimr_Srv_SetNtcSts_DebStep = DebStep_Arg;
    return PwrLimr_Srv_SetNtcSts_Return;
}


/*** Client Port Stubs ***/

FUNC(void, AUTOMATIC) Rte_Stub(void)
{
    PwrLimrInit1();
    PwrLimrPer1();
    PwrLimrPer2();
}

