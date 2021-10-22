/******************************************************************************************************************
* Copyright 2016 Nxtr
* Nxtr Confidential
*
* Module File Name:   Rte_Stubs.c
* Module Description: Stubs for Polyspace analysis.  Generated from TL109A_SwcSuprt.
* Project:            CBD
* Author:             Owen Tosh
******************************************************************************************************************/


#include "Rte_SerlComTrcvIf.h"
#include "float.h"


/*** Server Port Stubs ***/

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SerlComTrcvIf_CnvSnpshtData_u16_Oper(uint32 * SnpshtDataCnvd_Arg, uint16 SnpshtData_Arg)
{
    SerlComTrcvIf_Srv_CnvSnpshtData_u16_SnpshtData = SnpshtData_Arg;
    *SnpshtDataCnvd_Arg = SerlComTrcvIf_Srv_CnvSnpshtData_u16_SnpshtDataCnvd;
    return (Std_ReturnType)0U;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SerlComTrcvIf_GetNtcQlfrSts_Oper(NtcNr1 NtcNr_Arg, SigQlfr1 * NtcQlfr_Arg)
{
    SerlComTrcvIf_Srv_GetNtcQlfrSts_NtcNr = NtcNr_Arg;
    *NtcQlfr_Arg = SerlComTrcvIf_Srv_GetNtcQlfrSts_NtcQlfr;
    return SerlComTrcvIf_Srv_GetNtcQlfrSts_Return;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SerlComTrcvIf_IoHwAb_GetGpioERRN_Oper(boolean * PinSt_Arg)
{
    *PinSt_Arg = SerlComTrcvIf_Srv_IoHwAb_GetGpioERRN_PinSt;
    return SerlComTrcvIf_Srv_IoHwAb_GetGpioERRN_Return;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SerlComTrcvIf_SetNtcStsAndSnpshtData_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg, uint32 SpclSnpshtData0_Arg, uint32 SpclSnpshtData1_Arg, uint32 SpclSnpshtData2_Arg)
{
    SerlComTrcvIf_Srv_SetNtcStsAndSnpshtData_NtcNr = NtcNr_Arg;
    SerlComTrcvIf_Srv_SetNtcStsAndSnpshtData_NtcStInfo = NtcStInfo_Arg;
    SerlComTrcvIf_Srv_SetNtcStsAndSnpshtData_NtcSts = NtcSts_Arg;
    SerlComTrcvIf_Srv_SetNtcStsAndSnpshtData_DebStep = DebStep_Arg;
    SerlComTrcvIf_Srv_SetNtcStsAndSnpshtData_SpclSnpshtData0 = SpclSnpshtData0_Arg;
    SerlComTrcvIf_Srv_SetNtcStsAndSnpshtData_SpclSnpshtData1 = SpclSnpshtData1_Arg;
    SerlComTrcvIf_Srv_SetNtcStsAndSnpshtData_SpclSnpshtData2 = SpclSnpshtData2_Arg;
    return SerlComTrcvIf_Srv_SetNtcStsAndSnpshtData_Return;
}


/*** Client Port Stubs ***/

FUNC(void, AUTOMATIC) Rte_Stub(void)
{
    SerlComTrcvIfInit1();
    SerlComTrcvIfPer1();
}

