/******************************************************************************************************************
* Copyright 2016 Nxtr
* Nxtr Confidential
*
* Module File Name:   Rte_Stubs.c
* Module Description: Stubs for Polyspace analysis.  Generated from TL109A_SwcSuprt.
* Project:            CBD
* Author:             Owen Tosh
******************************************************************************************************************/


#include "Rte_HwTq4Meas.h"
#include "float.h"


/*** Server Port Stubs ***/

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_HwTq4Meas_GetNtcQlfrSts_Oper(NtcNr1 NtcNr_Arg, SigQlfr1 * NtcQlfr_Arg)
{
    HwTq4Meas_Srv_GetNtcQlfrSts_NtcNr = NtcNr_Arg;
    *NtcQlfr_Arg = HwTq4Meas_Srv_GetNtcQlfrSts_NtcQlfr;
    return HwTq4Meas_Srv_GetNtcQlfrSts_Return;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_HwTq4Meas_HwTq4Offs_SetRamBlockStatus(boolean BlockChanged_Arg)
{
    HwTq4Meas_Srv_HwTq4Offs_SetRamBlockStatus_BlockChanged = BlockChanged_Arg;
    return HwTq4Meas_Srv_HwTq4Offs_SetRamBlockStatus_Return;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_HwTq4Meas_HwTq4Sca_SetRamBlockStatus(boolean BlockChanged_Arg)
{
    HwTq4Meas_Srv_HwTq4Sca_SetRamBlockStatus_BlockChanged = BlockChanged_Arg;
    return HwTq4Meas_Srv_HwTq4Sca_SetRamBlockStatus_Return;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_HwTq4Meas_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
{
    HwTq4Meas_Srv_SetNtcSts_NtcNr = NtcNr_Arg;
    HwTq4Meas_Srv_SetNtcSts_NtcStInfo = NtcStInfo_Arg;
    HwTq4Meas_Srv_SetNtcSts_NtcSts = NtcSts_Arg;
    HwTq4Meas_Srv_SetNtcSts_DebStep = DebStep_Arg;
    return HwTq4Meas_Srv_SetNtcSts_Return;
}


/*** Client Port Stubs ***/

FUNC(void, AUTOMATIC) Rte_Stub(void)
{
    HwTq4MeasInit1();
    HwTq4MeasPer1();
    HwTq4MeasPer2();
    HwTq4MeasPer3();
    HwTq4MeasPer4();
    HwTq4AutTrim_Oper();
    HwTq4ClrSnsrSca_Oper();
    HwTq4ClrTrim_Oper();
    HwTq4ReadSnsrSca_Oper(&HwTq4Meas_Cli_HwTq4ReadSnsrSca_HwTqReadScaData);
    HwTq4ReadTrim_Oper(&HwTq4Meas_Cli_HwTq4ReadTrim_HwTqReadTrimData);
    HwTq4TrimPrfmdSts_Oper(&HwTq4Meas_Cli_HwTq4TrimPrfmdSts_HwTqOffsTrimPrfmdStsData);
    HwTq4WrSnsrSca_Oper(HwTq4Meas_Cli_HwTq4WrSnsrSca_HwTqScaVal);
    HwTq4WrTrim_Oper(HwTq4Meas_Cli_HwTq4WrTrim_HwTqWrOffsTrimData);
}

