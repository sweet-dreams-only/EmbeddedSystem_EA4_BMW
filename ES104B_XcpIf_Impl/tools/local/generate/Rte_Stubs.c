/******************************************************************************************************************
* Copyright 2016 Nxtr
* Nxtr Confidential
*
* Module File Name:   Rte_Stubs.c
* Module Description: Stubs for Polyspace analysis.  Generated from TL109A_SwcSuprt.
* Project:            CBD
* Author:             Owen Tosh
******************************************************************************************************************/


#include "Rte_CDD_XcpIf.h"
#include "float.h"


/*** Server Port Stubs ***/

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_XcpIf_CopyCalPageReq_Oper(uint8 Seg_Arg_Arg)
{
    XcpIf_Srv_CopyCalPageReq_Seg_Arg = Seg_Arg_Arg;
    return XcpIf_Srv_CopyCalPageReq_Return;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_XcpIf_GetCalPageReq_Oper(uint8 Seg_Arg_Arg, uint8 Mod_Arg_Arg, uint8 * Page_Arg_Arg, uint8 * Rtn_Arg_Arg)
{
    XcpIf_Srv_GetCalPageReq_Seg_Arg = Seg_Arg_Arg;
    XcpIf_Srv_GetCalPageReq_Mod_Arg = Mod_Arg_Arg;
    XcpIf_Srv_GetCalPageReq_Page_Arg = *Page_Arg_Arg;
    *Page_Arg_Arg = XcpIf_Srv_GetCalPageReq_Page_Arg;
    *Rtn_Arg_Arg = XcpIf_Srv_GetCalPageReq_Rtn_Arg;
    return (Std_ReturnType)0U;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_XcpIf_GetSegInfoReq_Oper(GetSegMod1 Mod_Arg_Arg, uint8 Seg_Arg_Arg, uint8 SegInfo_Arg_Arg, uint8 MpgIdx_Arg_Arg, uint8 * Resp_Arg_Arg, uint8 * RespLen_Arg_Arg, uint8 * Rtn_Arg_Arg)
{
    XcpIf_Srv_GetSegInfoReq_Mod_Arg = Mod_Arg_Arg;
    XcpIf_Srv_GetSegInfoReq_Seg_Arg = Seg_Arg_Arg;
    XcpIf_Srv_GetSegInfoReq_SegInfo_Arg = SegInfo_Arg_Arg;
    XcpIf_Srv_GetSegInfoReq_MpgIdx_Arg = MpgIdx_Arg_Arg;
    XcpIf_Srv_GetSegInfoReq_Resp_Arg = *Resp_Arg_Arg;
    XcpIf_Srv_GetSegInfoReq_RespLen_Arg = *RespLen_Arg_Arg;
    *Resp_Arg_Arg = XcpIf_Srv_GetSegInfoReq_Resp_Arg;
    *RespLen_Arg_Arg = XcpIf_Srv_GetSegInfoReq_RespLen_Arg;
    *Rtn_Arg_Arg = XcpIf_Srv_GetSegInfoReq_Rtn_Arg;
    return (Std_ReturnType)0U;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_XcpIf_OnlineTunRamAdrMpg_Oper(uint32 ReqAdr_Arg_Arg, uint32 * CorrdAdr_Arg_Arg, AdrMpgReqTyp1 ReqTyp_Arg_Arg)
{
    XcpIf_Srv_OnlineTunRamAdrMpg_ReqAdr_Arg = ReqAdr_Arg_Arg;
    XcpIf_Srv_OnlineTunRamAdrMpg_CorrdAdr_Arg = *CorrdAdr_Arg_Arg;
    XcpIf_Srv_OnlineTunRamAdrMpg_ReqTyp_Arg = ReqTyp_Arg_Arg;
    *CorrdAdr_Arg_Arg = XcpIf_Srv_OnlineTunRamAdrMpg_CorrdAdr_Arg;
    return (Std_ReturnType)0U;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_XcpIf_SetCalPageReq_Oper(uint8 Seg_Arg_Arg, uint8 Mod_Arg_Arg, uint8 Page_Arg_Arg)
{
    XcpIf_Srv_SetCalPageReq_Seg_Arg = Seg_Arg_Arg;
    XcpIf_Srv_SetCalPageReq_Mod_Arg = Mod_Arg_Arg;
    XcpIf_Srv_SetCalPageReq_Page_Arg = Page_Arg_Arg;
    return (Std_ReturnType)0U;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_XcpIf_XcpCalChgReq_Oper()
{
    return (Std_ReturnType)0U;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_XcpIf_GetRefTmr1MicroSec32bit_Oper(uint32 * RefTmr_Arg)
{
    *RefTmr_Arg = XcpIf_Srv_GetRefTmr1MicroSec32bit_RefTmr;
    return (Std_ReturnType)0U;
}


/*** Client Port Stubs ***/

FUNC(void, AUTOMATIC) Rte_Stub(void)
{
    CDD_XcpIfInit1();
    CDD_XcpIfPer1();
    ActvTunStsReq_Oper(&XcpIf_Cli_ActvTunStsReq_ActvRtIdx_Arg, &XcpIf_Cli_ActvTunStsReq_ActvIninIdx_Arg, &XcpIf_Cli_ActvTunStsReq_ActvRtIdx_Arg, &XcpIf_Cli_ActvTunStsReq_CalChgAllwd_Arg, &XcpIf_Cli_ActvTunStsReq_ActvGroup_Arg, &XcpIf_Cli_ActvTunStsReq_CalCopyCmpl_Arg);
}

