/******************************************************************************************************************
* Copyright 2016 Nxtr
* Nxtr Confidential
*
* Module File Name:   Rte_Stubs.c
* Module Description: Stubs for Polyspace analysis.  Generated from TL109A_SwcSuprt.
* Project:            CBD
* Author:             Owen Tosh
******************************************************************************************************************/


#include "Rte_PwrDiscnct.h"
#include "float.h"


/*** Server Port Stubs ***/

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PwrDiscnct_GetNtcQlfrSts_Oper(NtcNr1 NtcNr_Arg, SigQlfr1 * NtcQlfr_Arg)
{
    PwrDiscnct_Srv_GetNtcQlfrSts_NtcNr = NtcNr_Arg;
    *NtcQlfr_Arg = PwrDiscnct_Srv_GetNtcQlfrSts_NtcQlfr;
    return PwrDiscnct_Srv_GetNtcQlfrSts_Return;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PwrDiscnct_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
{
    PwrDiscnct_Srv_SetNtcSts_NtcNr = NtcNr_Arg;
    PwrDiscnct_Srv_SetNtcSts_NtcStInfo = NtcStInfo_Arg;
    PwrDiscnct_Srv_SetNtcSts_NtcSts = NtcSts_Arg;
    PwrDiscnct_Srv_SetNtcSts_DebStep = DebStep_Arg;
    return PwrDiscnct_Srv_SetNtcSts_Return;
}


/*** Client Port Stubs ***/

FUNC(void, AUTOMATIC) Rte_Stub(void)
{
    PwrDiscnctInit1();
    PwrDiscnctPer1();
}

