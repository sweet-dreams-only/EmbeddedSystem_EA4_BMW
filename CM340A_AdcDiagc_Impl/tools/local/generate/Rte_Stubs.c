/******************************************************************************************************************
* Copyright 2016 Nxtr
* Nxtr Confidential
*
* Module File Name:   Rte_Stubs.c
* Module Description: Stubs for Polyspace analysis.  Generated from TL109A_SwcSuprt.
* Project:            CBD
* Author:             Owen Tosh
******************************************************************************************************************/


#include "Rte_CDD_AdcDiagc.h"
#include "float.h"


/*** Server Port Stubs ***/

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_AdcDiagc_GetNtcQlfrSts_Oper(NtcNr1 NtcNr_Arg, SigQlfr1 * NtcQlfr_Arg)
{
    AdcDiagc_Srv_GetNtcQlfrSts_NtcNr = NtcNr_Arg;
    *NtcQlfr_Arg = AdcDiagc_Srv_GetNtcQlfrSts_NtcQlfr;
    return AdcDiagc_Srv_GetNtcQlfrSts_Return;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_AdcDiagc_ReadErrInjReg_Oper(uint32 * ErrId_Arg)
{
    *ErrId_Arg = AdcDiagc_Srv_ReadErrInjReg_ErrId;
    return (Std_ReturnType)0U;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_AdcDiagc_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
{
    AdcDiagc_Srv_SetNtcSts_NtcNr = NtcNr_Arg;
    AdcDiagc_Srv_SetNtcSts_NtcStInfo = NtcStInfo_Arg;
    AdcDiagc_Srv_SetNtcSts_NtcSts = NtcSts_Arg;
    AdcDiagc_Srv_SetNtcSts_DebStep = DebStep_Arg;
    return AdcDiagc_Srv_SetNtcSts_Return;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_AdcDiagc_StrtErrInjCntr_Oper()
{
    return (Std_ReturnType)0U;
}


/*** Client Port Stubs ***/

FUNC(void, AUTOMATIC) Rte_Stub(void)
{
    AdcDiagcInit1();
    AdcDiagcPer1();
}

