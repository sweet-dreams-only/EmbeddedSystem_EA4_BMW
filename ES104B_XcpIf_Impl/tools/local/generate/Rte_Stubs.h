/******************************************************************************************************************
* Copyright 2016 Nxtr
* Nxtr Confidential
*
* Module File Name:   Rte_Stubs.h
* Module Description: Stubs header for Polyspace analysis.  Generated from TL109A_SwcSuprt.
* Project:            CBD
* Author:             Owen Tosh
******************************************************************************************************************/


#ifndef RTE_STUBS_H
#define RTE_STUBS_H

#include "math_stubs.h"

/*** Extern Statements ***/

/* Inputs */
extern VAR(uint8, AUTOMATIC) XcpIf_Ip_ActvGroup;
extern VAR(uint8, AUTOMATIC) XcpIf_Ip_ActvIninIdx;
extern VAR(uint8, AUTOMATIC) XcpIf_Ip_ActvRtIdx;
extern VAR(CalCopySts1, AUTOMATIC) XcpIf_Ip_CalCopySts;
extern VAR(boolean, AUTOMATIC) XcpIf_Ip_CustXcpEna;
extern VAR(MfgEnaSt1, AUTOMATIC) XcpIf_Ip_MfgEnaSt;

/* Arguments and Returns */
extern VAR(uint8, AUTOMATIC) XcpIf_Srv_CopyCalPageReq_Seg_Arg;
extern VAR(Std_ReturnType, AUTOMATIC) XcpIf_Srv_CopyCalPageReq_Return;
extern VAR(uint8, AUTOMATIC) XcpIf_Srv_GetCalPageReq_Seg_Arg;
extern VAR(uint8, AUTOMATIC) XcpIf_Srv_GetCalPageReq_Mod_Arg;
extern VAR(uint8, AUTOMATIC) XcpIf_Srv_GetCalPageReq_Page_Arg;
extern VAR(uint8, AUTOMATIC) XcpIf_Srv_GetCalPageReq_Rtn_Arg;
extern VAR(GetSegMod1, AUTOMATIC) XcpIf_Srv_GetSegInfoReq_Mod_Arg;
extern VAR(uint8, AUTOMATIC) XcpIf_Srv_GetSegInfoReq_Seg_Arg;
extern VAR(uint8, AUTOMATIC) XcpIf_Srv_GetSegInfoReq_SegInfo_Arg;
extern VAR(uint8, AUTOMATIC) XcpIf_Srv_GetSegInfoReq_MpgIdx_Arg;
extern VAR(uint8, AUTOMATIC) XcpIf_Srv_GetSegInfoReq_Resp_Arg;
extern VAR(uint8, AUTOMATIC) XcpIf_Srv_GetSegInfoReq_RespLen_Arg;
extern VAR(uint8, AUTOMATIC) XcpIf_Srv_GetSegInfoReq_Rtn_Arg;
extern VAR(uint32, AUTOMATIC) XcpIf_Srv_OnlineTunRamAdrMpg_ReqAdr_Arg;
extern VAR(uint32, AUTOMATIC) XcpIf_Srv_OnlineTunRamAdrMpg_CorrdAdr_Arg;
extern VAR(AdrMpgReqTyp1, AUTOMATIC) XcpIf_Srv_OnlineTunRamAdrMpg_ReqTyp_Arg;
extern VAR(uint8, AUTOMATIC) XcpIf_Srv_SetCalPageReq_Seg_Arg;
extern VAR(uint8, AUTOMATIC) XcpIf_Srv_SetCalPageReq_Mod_Arg;
extern VAR(uint8, AUTOMATIC) XcpIf_Srv_SetCalPageReq_Page_Arg;
extern VAR(uint32, AUTOMATIC) XcpIf_Srv_GetRefTmr1MicroSec32bit_RefTmr;
extern VAR(uint8, AUTOMATIC) XcpIf_Cli_ActvTunStsReq_ActvRtIdx_Arg;
extern VAR(uint8, AUTOMATIC) XcpIf_Cli_ActvTunStsReq_ActvIninIdx_Arg;
extern VAR(uint8, AUTOMATIC) XcpIf_Cli_ActvTunStsReq_ActvRtIdx_Arg;
extern VAR(uint8, AUTOMATIC) XcpIf_Cli_ActvTunStsReq_CalChgAllwd_Arg;
extern VAR(uint8, AUTOMATIC) XcpIf_Cli_ActvTunStsReq_ActvGroup_Arg;
extern VAR(uint8, AUTOMATIC) XcpIf_Cli_ActvTunStsReq_CalCopyCmpl_Arg;


/*** Input Stubs ***/

#ifdef Rte_Read_ActvGroup_Val
# undef Rte_Read_ActvGroup_Val
#else
#error Rte_Read_ActvGroup_Val is missing
#endif
#define Rte_Read_ActvGroup_Val(data) (*(data) = XcpIf_Ip_ActvGroup)

#ifdef Rte_Read_ActvIninIdx_Val
# undef Rte_Read_ActvIninIdx_Val
#else
#error Rte_Read_ActvIninIdx_Val is missing
#endif
#define Rte_Read_ActvIninIdx_Val(data) (*(data) = XcpIf_Ip_ActvIninIdx)

#ifdef Rte_Read_ActvRtIdx_Val
# undef Rte_Read_ActvRtIdx_Val
#else
#error Rte_Read_ActvRtIdx_Val is missing
#endif
#define Rte_Read_ActvRtIdx_Val(data) (*(data) = XcpIf_Ip_ActvRtIdx)

#ifdef Rte_Read_CalCopySts_Val
# undef Rte_Read_CalCopySts_Val
#else
#error Rte_Read_CalCopySts_Val is missing
#endif
#define Rte_Read_CalCopySts_Val(data) (*(data) = XcpIf_Ip_CalCopySts)

#ifdef Rte_Read_CustXcpEna_Logl
# undef Rte_Read_CustXcpEna_Logl
#else
#error Rte_Read_CustXcpEna_Logl is missing
#endif
#define Rte_Read_CustXcpEna_Logl(data) (*(data) = XcpIf_Ip_CustXcpEna)

#ifdef Rte_Read_MfgEnaSt_Val
# undef Rte_Read_MfgEnaSt_Val
#else
#error Rte_Read_MfgEnaSt_Val is missing
#endif
#define Rte_Read_MfgEnaSt_Val(data) (*(data) = XcpIf_Ip_MfgEnaSt)


/*** Client Stub ***/

extern FUNC(void, AUTOMATIC) Rte_Stub(void);


#endif
