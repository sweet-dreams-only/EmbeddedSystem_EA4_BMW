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


/*** Extern Statements ***/

/* Inputs */
extern VAR(uint8, AUTOMATIC) TunSelnMngt_Ip_DesIninIdx;
extern VAR(uint8, AUTOMATIC) TunSelnMngt_Ip_DesIninOptSetAIdx;
extern VAR(uint8, AUTOMATIC) TunSelnMngt_Ip_DesRtIdx;

/* Outputs */
extern VAR(uint8, AUTOMATIC) TunSelnMngt_Op_ActvGroup;
extern VAR(uint8, AUTOMATIC) TunSelnMngt_Op_ActvIninIdx;
extern VAR(uint8, AUTOMATIC) TunSelnMngt_Op_ActvIninOptSetAIdx;
extern VAR(uint8, AUTOMATIC) TunSelnMngt_Op_ActvRtIdx;
extern VAR(CalCopySts1, AUTOMATIC) TunSelnMngt_Op_CalCopySts;
extern VAR(RtIdxChgSts1, AUTOMATIC) TunSelnMngt_Op_RtIdxChgSts;

/* PIMs */
extern VAR(OnlineCalStsRec2, AUTOMATIC) TunSelnMngt_Pim_OnlineCalSts;
extern VAR(uint8, AUTOMATIC) TunSelnMngt_Pim_PrevActvIninIdx;
extern VAR(uint8, AUTOMATIC) TunSelnMngt_Pim_PrevActvIninOptSetAIdx;
extern VAR(uint8, AUTOMATIC) TunSelnMngt_Pim_PrevActvRtIdx;
extern VAR(uint8, AUTOMATIC) TunSelnMngt_Pim_PrevRamPageAcs;
extern VAR(uint8, AUTOMATIC) TunSelnMngt_Pim_RamTblSwt;
extern VAR(RtIdxChgSts1, AUTOMATIC) TunSelnMngt_Pim_PrevRtIdxChgSts;

/* Arguments and Returns */
extern VAR(uint32, AUTOMATIC) TunSelnMngt_Srv_Calc32BitCrc_u32_DataPtr;
extern VAR(uint32, AUTOMATIC) TunSelnMngt_Srv_Calc32BitCrc_u32_Len;
extern VAR(uint32, AUTOMATIC) TunSelnMngt_Srv_Calc32BitCrc_u32_StrtVal;
extern VAR(boolean, AUTOMATIC) TunSelnMngt_Srv_Calc32BitCrc_u32_FirstCall;
extern VAR(uint32, AUTOMATIC) TunSelnMngt_Srv_Calc32BitCrc_u32_CalcCrcRes;
extern VAR(Std_ReturnType, AUTOMATIC) TunSelnMngt_Srv_Calc32BitCrc_u32_Return;
extern VAR(Std_ReturnType, AUTOMATIC) TunSelnMngt_Srv_RtCalChgReq_Return;
extern VAR(NtcNr1, AUTOMATIC) TunSelnMngt_Srv_SetNtcSts_NtcNr;
extern VAR(uint8, AUTOMATIC) TunSelnMngt_Srv_SetNtcSts_NtcStInfo;
extern VAR(NtcSts1, AUTOMATIC) TunSelnMngt_Srv_SetNtcSts_NtcSts;
extern VAR(uint16, AUTOMATIC) TunSelnMngt_Srv_SetNtcSts_DebStep;
extern VAR(Std_ReturnType, AUTOMATIC) TunSelnMngt_Srv_SetNtcSts_Return;
extern VAR(uint8, AUTOMATIC) TunSelnMngt_Cli_CopyCalPageReq_Seg_Arg;
extern VAR(Std_ReturnType, AUTOMATIC) TunSelnMngt_Cli_CopyCalPageReq_Return;
extern VAR(uint8, AUTOMATIC) TunSelnMngt_Cli_GetCalPageReq_Seg_Arg;
extern VAR(uint8, AUTOMATIC) TunSelnMngt_Cli_GetCalPageReq_Mod_Arg;
extern VAR(uint8, AUTOMATIC) TunSelnMngt_Cli_GetCalPageReq_Page_Arg;
extern VAR(uint8, AUTOMATIC) TunSelnMngt_Cli_GetCalPageReq_Rtn_Arg;
extern VAR(GetSegMod1, AUTOMATIC) TunSelnMngt_Cli_GetSegInfoReq_Mod_Arg;
extern VAR(uint8, AUTOMATIC) TunSelnMngt_Cli_GetSegInfoReq_Seg_Arg;
extern VAR(uint8, AUTOMATIC) TunSelnMngt_Cli_GetSegInfoReq_SegInfo_Arg;
extern VAR(uint8, AUTOMATIC) TunSelnMngt_Cli_GetSegInfoReq_MpgIdx_Arg;
extern VAR(uint8, AUTOMATIC) TunSelnMngt_Cli_GetSegInfoReq_Resp_Arg[65535];
extern VAR(uint8, AUTOMATIC) TunSelnMngt_Cli_GetSegInfoReq_RespLen_Arg;
extern VAR(uint8, AUTOMATIC) TunSelnMngt_Cli_GetSegInfoReq_Rtn_Arg;
extern VAR(uint32, AUTOMATIC) TunSelnMngt_Cli_OnlineTunRamAdrMpg_ReqAdr_Arg;
extern VAR(uint32, AUTOMATIC) TunSelnMngt_Cli_OnlineTunRamAdrMpg_CorrdAdr_Arg;
extern VAR(AdrMpgReqTyp1, AUTOMATIC) TunSelnMngt_Cli_OnlineTunRamAdrMpg_ReqTyp_Arg;
extern VAR(uint8, AUTOMATIC) TunSelnMngt_Cli_SetCalPageReq_Seg_Arg;
extern VAR(uint8, AUTOMATIC) TunSelnMngt_Cli_SetCalPageReq_Mod_Arg;
extern VAR(uint8, AUTOMATIC) TunSelnMngt_Cli_SetCalPageReq_Page_Arg;


/*** Input Stubs ***/

#ifdef Rte_Read_DesIninIdx_Val
# undef Rte_Read_DesIninIdx_Val
#endif
#define Rte_Read_DesIninIdx_Val(data) (*(data) = TunSelnMngt_Ip_DesIninIdx)

#ifdef Rte_Read_DesIninOptSetAIdx_Val
# undef Rte_Read_DesIninOptSetAIdx_Val
#endif
#define Rte_Read_DesIninOptSetAIdx_Val(data) (*(data) = TunSelnMngt_Ip_DesIninOptSetAIdx)

#ifdef Rte_Read_DesRtIdx_Val
# undef Rte_Read_DesRtIdx_Val
#endif
#define Rte_Read_DesRtIdx_Val(data) (*(data) = TunSelnMngt_Ip_DesRtIdx)


/*** Output Stubs ***/

#ifdef Rte_Write_ActvGroup_Val
# undef Rte_Write_ActvGroup_Val
#endif
#define Rte_Write_ActvGroup_Val(data) (TunSelnMngt_Op_ActvGroup = (data))

#ifdef Rte_Write_ActvIninIdx_Val
# undef Rte_Write_ActvIninIdx_Val
#endif
#define Rte_Write_ActvIninIdx_Val(data) (TunSelnMngt_Op_ActvIninIdx = (data))

#ifdef Rte_Write_ActvIninOptSetAIdx_Val
# undef Rte_Write_ActvIninOptSetAIdx_Val
#endif
#define Rte_Write_ActvIninOptSetAIdx_Val(data) (TunSelnMngt_Op_ActvIninOptSetAIdx = (data))

#ifdef Rte_Write_ActvRtIdx_Val
# undef Rte_Write_ActvRtIdx_Val
#endif
#define Rte_Write_ActvRtIdx_Val(data) (TunSelnMngt_Op_ActvRtIdx = (data))

#ifdef Rte_Write_CalCopySts_Val
# undef Rte_Write_CalCopySts_Val
#endif
#define Rte_Write_CalCopySts_Val(data) (TunSelnMngt_Op_CalCopySts = (data))

#ifdef Rte_Write_RtIdxChgSts_Val
# undef Rte_Write_RtIdxChgSts_Val
#endif
#define Rte_Write_RtIdxChgSts_Val(data) (TunSelnMngt_Op_RtIdxChgSts = (data))


/*** PIM Stubs ***/

#ifdef Rte_Pim_OnlineCalSts
# undef Rte_Pim_OnlineCalSts
#endif
#define Rte_Pim_OnlineCalSts() (&TunSelnMngt_Pim_OnlineCalSts)

#ifdef Rte_Pim_PrevActvIninIdx
# undef Rte_Pim_PrevActvIninIdx
#endif
#define Rte_Pim_PrevActvIninIdx() (&TunSelnMngt_Pim_PrevActvIninIdx)

#ifdef Rte_Pim_PrevActvIninOptSetAIdx
# undef Rte_Pim_PrevActvIninOptSetAIdx
#endif
#define Rte_Pim_PrevActvIninOptSetAIdx() (&TunSelnMngt_Pim_PrevActvIninOptSetAIdx)

#ifdef Rte_Pim_PrevActvRtIdx
# undef Rte_Pim_PrevActvRtIdx
#endif
#define Rte_Pim_PrevActvRtIdx() (&TunSelnMngt_Pim_PrevActvRtIdx)

#ifdef Rte_Pim_PrevRamPageAcs
# undef Rte_Pim_PrevRamPageAcs
#endif
#define Rte_Pim_PrevRamPageAcs() (&TunSelnMngt_Pim_PrevRamPageAcs)

#ifdef Rte_Pim_RamTblSwt
# undef Rte_Pim_RamTblSwt
#endif
#define Rte_Pim_RamTblSwt() (&TunSelnMngt_Pim_RamTblSwt)

#ifdef Rte_Pim_PrevRtIdxChgSts
# undef Rte_Pim_PrevRtIdxChgSts
#endif
#define Rte_Pim_PrevRtIdxChgSts() (&TunSelnMngt_Pim_PrevRtIdxChgSts)


/*** Client Stub ***/

extern FUNC(void, AUTOMATIC) Rte_Stub(void);


#endif
