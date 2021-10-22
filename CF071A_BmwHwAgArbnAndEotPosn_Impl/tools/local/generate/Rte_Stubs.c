/******************************************************************************************************************
* Copyright 2016 Nxtr
* Nxtr Confidential
*
* Module File Name:   Rte_Stubs.c
* Module Description: Stubs for Polyspace analysis.  Generated from TL109A_SwcSuprt.
* Project:            CBD
* Author:             Owen Tosh
******************************************************************************************************************/


#include "Rte_BmwHwAgArbnAndEotPosn.h"
#include "float.h"


/*** Server Port Stubs ***/

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwHwAgArbnAndEotPosn_BmwVehCentrOffs_GetErrorStatus(uint8 * ReqResPtr_Arg)
{
    *ReqResPtr_Arg = BmwHwAgArbnAndEotPosn_Srv_BmwVehCentrOffs_GetErrorStatus_ReqResPtr;
    return BmwHwAgArbnAndEotPosn_Srv_BmwVehCentrOffs_GetErrorStatus_Return;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwHwAgArbnAndEotPosn_BmwVehCentrOffs_SetRamBlockStatus(boolean BlockChanged_Arg)
{
    BmwHwAgArbnAndEotPosn_Srv_BmwVehCentrOffs_SetRamBlockStatus_BlockChanged = BlockChanged_Arg;
    return BmwHwAgArbnAndEotPosn_Srv_BmwVehCentrOffs_SetRamBlockStatus_Return;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwHwAgArbnAndEotPosn_GetNtcQlfrSts_Oper(NtcNr1 NtcNr_Arg, SigQlfr1 * NtcQlfr_Arg)
{
    BmwHwAgArbnAndEotPosn_Srv_GetNtcQlfrSts_NtcNr = NtcNr_Arg;
    *NtcQlfr_Arg = BmwHwAgArbnAndEotPosn_Srv_GetNtcQlfrSts_NtcQlfr;
    return BmwHwAgArbnAndEotPosn_Srv_GetNtcQlfrSts_Return;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwHwAgArbnAndEotPosn_GetRefTmr100MicroSec32bit_Oper(uint32 * RefTmr_Arg)
{
    *RefTmr_Arg = BmwHwAgArbnAndEotPosn_Srv_GetRefTmr100MicroSec32bit_RefTmr;
    return (Std_ReturnType)0U;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwHwAgArbnAndEotPosn_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 * TiSpan_Arg)
{
    BmwHwAgArbnAndEotPosn_Srv_GetTiSpan100MicroSec32bit_RefTmr = RefTmr_Arg;
    *TiSpan_Arg = BmwHwAgArbnAndEotPosn_Srv_GetTiSpan100MicroSec32bit_TiSpan;
    return (Std_ReturnType)0U;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwHwAgArbnAndEotPosn_RstRackCentrMotRev_Oper()
{
    return (Std_ReturnType)0U;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwHwAgArbnAndEotPosn_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
{
    BmwHwAgArbnAndEotPosn_Srv_SetNtcSts_NtcNr = NtcNr_Arg;
    BmwHwAgArbnAndEotPosn_Srv_SetNtcSts_NtcStInfo = NtcStInfo_Arg;
    BmwHwAgArbnAndEotPosn_Srv_SetNtcSts_NtcSts = NtcSts_Arg;
    BmwHwAgArbnAndEotPosn_Srv_SetNtcSts_DebStep = DebStep_Arg;
    return BmwHwAgArbnAndEotPosn_Srv_SetNtcSts_Return;
}


/*** Client Port Stubs ***/

FUNC(void, AUTOMATIC) Rte_Stub(void)
{
    BmwHwAgArbnAndEotPosnInit1();
    BmwHwAgArbnAndEotPosnPer1();
    ClrBmwRackCentrToVehCentrOffs_Oper();
    ClrVehCentrPosn_Oper();
    SetVehCentrPosn_Oper(&BmwHwAgArbnAndEotPosn_Cli_SetVehCentrPosn_BmwSetVehCentrOffsSts);
}

