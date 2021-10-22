/******************************************************************************************************************
* Copyright 2016 Nxtr
* Nxtr Confidential
*
* Module File Name:   Rte_Stubs.c
* Module Description: Stubs for Polyspace analysis.  Generated from TL109A_SwcSuprt.
* Project:            CBD
* Author:             Owen Tosh
******************************************************************************************************************/


#include "Rte_TunSelnMngt.h"
#include "float.h"


/*** Server Port Stubs ***/

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_TunSelnMngt_Calc32BitCrc_u32_Oper(uint32 * DataPtr_Arg, uint32 Len_Arg, uint32 StrtVal_Arg, boolean FirstCall_Arg, uint32 * CalcCrcRes_Arg)
{
    TunSelnMngt_Srv_Calc32BitCrc_u32_DataPtr = DataPtr_Arg;
    TunSelnMngt_Srv_Calc32BitCrc_u32_Len = Len_Arg;
    TunSelnMngt_Srv_Calc32BitCrc_u32_StrtVal = StrtVal_Arg;
    TunSelnMngt_Srv_Calc32BitCrc_u32_FirstCall = FirstCall_Arg;
    *CalcCrcRes_Arg = TunSelnMngt_Srv_Calc32BitCrc_u32_CalcCrcRes;
    return TunSelnMngt_Srv_Calc32BitCrc_u32_Return;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_TunSelnMngt_RtCalChgReq_Oper()
{
    return TunSelnMngt_Srv_RtCalChgReq_Return;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_TunSelnMngt_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
{
    TunSelnMngt_Srv_SetNtcSts_NtcNr = NtcNr_Arg;
    TunSelnMngt_Srv_SetNtcSts_NtcStInfo = NtcStInfo_Arg;
    TunSelnMngt_Srv_SetNtcSts_NtcSts = NtcSts_Arg;
    TunSelnMngt_Srv_SetNtcSts_DebStep = DebStep_Arg;
    return TunSelnMngt_Srv_SetNtcSts_Return;
}


/*** Client Port Stubs ***/

FUNC(void, AUTOMATIC) Rte_Stub(void)
{
    TunSelnMngtInit1();
    TunSelnMngtPer1();
    TunSelnMngt_Cli_CopyCalPageReq_Return = CopyCalPageReq_Oper(TunSelnMngt_Cli_CopyCalPageReq_Seg_Arg);
    GetCalPageReq_Oper(TunSelnMngt_Cli_GetCalPageReq_Seg_Arg, TunSelnMngt_Cli_GetCalPageReq_Mod_Arg, &TunSelnMngt_Cli_GetCalPageReq_Page_Arg, &TunSelnMngt_Cli_GetCalPageReq_Rtn_Arg);
    GetSegInfoReq_Oper(TunSelnMngt_Cli_GetSegInfoReq_Mod_Arg, TunSelnMngt_Cli_GetSegInfoReq_Seg_Arg, TunSelnMngt_Cli_GetSegInfoReq_SegInfo_Arg, TunSelnMngt_Cli_GetSegInfoReq_MpgIdx_Arg, &TunSelnMngt_Cli_GetSegInfoReq_Resp_Arg[0], &TunSelnMngt_Cli_GetSegInfoReq_RespLen_Arg, &TunSelnMngt_Cli_GetSegInfoReq_Rtn_Arg);
    OnlineTunRamAdrMpg_Oper(TunSelnMngt_Cli_OnlineTunRamAdrMpg_ReqAdr_Arg, &TunSelnMngt_Cli_OnlineTunRamAdrMpg_CorrdAdr_Arg, &TunSelnMngt_Cli_OnlineTunRamAdrMpg_ReqTyp_Arg);
    SetCalPageReq_Oper(TunSelnMngt_Cli_SetCalPageReq_Seg_Arg, TunSelnMngt_Cli_SetCalPageReq_Mod_Arg, TunSelnMngt_Cli_SetCalPageReq_Page_Arg);
}

