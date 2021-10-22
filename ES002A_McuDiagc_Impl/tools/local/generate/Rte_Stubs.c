/******************************************************************************************************************
* Copyright 2016 Nxtr
* Nxtr Confidential
*
* Module File Name:   Rte_Stubs.c
* Module Description: Stubs for Polyspace analysis.  Generated from TL109A_SwcSuprt.
* Project:            CBD
* Author:             Owen Tosh
******************************************************************************************************************/


#include "Rte_CDD_McuDiagc.h"
#include "float.h"


/*** Server Port Stubs ***/

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_McuDiagc_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
{
    McuDiagc_Srv_SetNtcSts_NtcNr = NtcNr_Arg;
    McuDiagc_Srv_SetNtcSts_NtcStInfo = NtcStInfo_Arg;
    McuDiagc_Srv_SetNtcSts_NtcSts = NtcSts_Arg;
    McuDiagc_Srv_SetNtcSts_DebStep = DebStep_Arg;
    return McuDiagc_Srv_SetNtcSts_Return;
}


/*** Client Port Stubs ***/

FUNC(void, AUTOMATIC) Rte_Stub(void)
{
    McuDiagcInit1();
    McuDiagcPer1();
    McuDiagcPer2();
}

