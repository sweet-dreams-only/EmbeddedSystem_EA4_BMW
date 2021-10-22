/******************************************************************************************************************
* Copyright 2016 Nxtr
* Nxtr Confidential
*
* Module File Name:   Rte_Stubs.c
* Module Description: Stubs for Polyspace analysis.  Generated from TL109A_SwcSuprt.
* Project:            CBD
* Author:             Owen Tosh
******************************************************************************************************************/


#include "Rte_HwTq5Meas.h"
#include "float.h"


/*** Server Port Stubs ***/

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_HwTq5Meas_GetNtcQlfrSts_Oper(NtcNr1 NtcNr_Arg, SigQlfr1 * NtcQlfr_Arg)
{
    HwTq5Meas_Srv_GetNtcQlfrSts_NtcNr = NtcNr_Arg;
    *NtcQlfr_Arg = HwTq5Meas_Srv_GetNtcQlfrSts_NtcQlfr;
    return HwTq5Meas_Srv_GetNtcQlfrSts_Return;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_HwTq5Meas_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
{
    HwTq5Meas_Srv_SetNtcSts_NtcNr = NtcNr_Arg;
    HwTq5Meas_Srv_SetNtcSts_NtcStInfo = NtcStInfo_Arg;
    HwTq5Meas_Srv_SetNtcSts_NtcSts = NtcSts_Arg;
    HwTq5Meas_Srv_SetNtcSts_DebStep = DebStep_Arg;
    return HwTq5Meas_Srv_SetNtcSts_Return;
}


/*** Client Port Stubs ***/

FUNC(void, AUTOMATIC) Rte_Stub(void)
{
    HwTq5MeasInit1();
    HwTq5MeasPer1();
    HwTq5MeasPer2();
    HwTq5MeasPer3();
    HwTq5MeasPer4();
    HwTq5AutTrim_Oper();
    HwTq5ClrSnsrSca_Oper();
    HwTq5ClrTrim_Oper();
    HwTq5ReadSnsrSca_Oper(&HwTq5Meas_Cli_HwTq5ReadSnsrSca_HwTqReadScaData);
    HwTq5ReadTrim_Oper(&HwTq5Meas_Cli_HwTq5ReadTrim_HwTqReadTrimData);
    HwTq5TrimPrfmdSts_Oper(&HwTq5Meas_Cli_HwTq5TrimPrfmdSts_HwTqOffsTrimPrfmdStsData);
    HwTq5WrSnsrSca_Oper(HwTq5Meas_Cli_HwTq5WrSnsrSca_HwTqScaVal);
    HwTq5WrTrim_Oper(HwTq5Meas_Cli_HwTq5WrTrim_HwTqWrOffsTrimData);
}

