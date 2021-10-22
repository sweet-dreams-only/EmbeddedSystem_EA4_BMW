/******************************************************************************************************************
* Copyright 2016 Nxtr
* Nxtr Confidential
*
* Module File Name:   Rte_Stubs.c
* Module Description: Stubs for Polyspace analysis.  Generated from TL109A_SwcSuprt.
* Project:            CBD
* Author:             Owen Tosh
******************************************************************************************************************/


#include "Rte_LoaMgr.h"
#include "float.h"


/*** Server Port Stubs ***/

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_LoaMgr_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
{
    LoaMgr_Srv_SetNtcSts_NtcNr = NtcNr_Arg;
    LoaMgr_Srv_SetNtcSts_NtcStInfo = NtcStInfo_Arg;
    LoaMgr_Srv_SetNtcSts_NtcSts = NtcSts_Arg;
    LoaMgr_Srv_SetNtcSts_DebStep = DebStep_Arg;
    return LoaMgr_Srv_SetNtcSts_Return;
}


/*** Client Port Stubs ***/

FUNC(void, AUTOMATIC) Rte_Stub(void)
{
    LoaMgrInit1();
    LoaMgrPer1();
}

