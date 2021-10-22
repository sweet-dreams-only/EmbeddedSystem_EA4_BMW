/******************************************************************************************************************
* Copyright 2016 Nxtr
* Nxtr Confidential
*
* Module File Name:   Rte_Stubs.c
* Module Description: Stubs for Polyspace analysis.  Generated from TL109A_SwcSuprt.
* Project:            CBD
* Author:             Owen Tosh
******************************************************************************************************************/


#include "Rte_PhaDiscnct.h"
#include "float.h"


/*** Server Port Stubs ***/

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PhaDiscnct_GetRefTmr100MicroSec32bit_Oper(uint32 * RefTmr_Arg)
{
    *RefTmr_Arg = PhaDiscnct_Srv_GetRefTmr100MicroSec32bit_RefTmr;
    return (Std_ReturnType)0U;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PhaDiscnct_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 * TiSpan_Arg)
{
    PhaDiscnct_Srv_GetTiSpan100MicroSec32bit_RefTmr = RefTmr_Arg;
    *TiSpan_Arg = PhaDiscnct_Srv_GetTiSpan100MicroSec32bit_TiSpan;
    return PhaDiscnct_Srv_GetTiSpan100MicroSec32bit_Return;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PhaDiscnct_SetNtcStsAndSnpshtData_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg, uint32 SpclSnpshtData0_Arg, uint32 SpclSnpshtData1_Arg, uint32 SpclSnpshtData2_Arg)
{
    PhaDiscnct_Srv_SetNtcStsAndSnpshtData_NtcNr = NtcNr_Arg;
    PhaDiscnct_Srv_SetNtcStsAndSnpshtData_NtcStInfo = NtcStInfo_Arg;
    PhaDiscnct_Srv_SetNtcStsAndSnpshtData_NtcSts = NtcSts_Arg;
    PhaDiscnct_Srv_SetNtcStsAndSnpshtData_DebStep = DebStep_Arg;
    PhaDiscnct_Srv_SetNtcStsAndSnpshtData_SpclSnpshtData0 = SpclSnpshtData0_Arg;
    PhaDiscnct_Srv_SetNtcStsAndSnpshtData_SpclSnpshtData1 = SpclSnpshtData1_Arg;
    PhaDiscnct_Srv_SetNtcStsAndSnpshtData_SpclSnpshtData2 = SpclSnpshtData2_Arg;
    return PhaDiscnct_Srv_SetNtcStsAndSnpshtData_Return;
}


/*** Client Port Stubs ***/

FUNC(void, AUTOMATIC) Rte_Stub(void)
{
    PhaDiscnctInit1();
    PhaDiscnctPer1();
    PhaDiscnctPer2();
}

