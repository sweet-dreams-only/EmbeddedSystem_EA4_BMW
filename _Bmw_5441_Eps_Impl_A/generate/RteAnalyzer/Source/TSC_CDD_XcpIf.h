/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  TSC_CDD_XcpIf.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Header of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/


/** Sender receiver - explicit read services */
Std_ReturnType TSC_CDD_XcpIf_Rte_Read_ActvGroup_Val(uint8 *data);
Std_ReturnType TSC_CDD_XcpIf_Rte_Read_ActvIninIdx_Val(uint8 *data);
Std_ReturnType TSC_CDD_XcpIf_Rte_Read_ActvIninOptSetAIdx_Val(uint8 *data);
Std_ReturnType TSC_CDD_XcpIf_Rte_Read_ActvRtIdx_Val(uint8 *data);
Std_ReturnType TSC_CDD_XcpIf_Rte_Read_CalCopySts_Val(CalCopySts1 *data);
Std_ReturnType TSC_CDD_XcpIf_Rte_Read_CustXcpEna_Logl(boolean *data);
Std_ReturnType TSC_CDD_XcpIf_Rte_Read_MfgEnaSt_Val(MfgEnaSt1 *data);
Std_ReturnType TSC_CDD_XcpIf_Rte_Read_CustXcpEna_Logl(boolean *data);
Std_ReturnType TSC_CDD_XcpIf_Rte_Read_MfgEnaSt_Val(MfgEnaSt1 *data);

/** Client server interfaces */
Std_ReturnType TSC_CDD_XcpIf_Rte_Call_XcpCalChgReq_Oper(void);
Std_ReturnType TSC_CDD_XcpIf_Rte_Call_CopyCalPageReq_Oper(uint8 Seg_Arg);
Std_ReturnType TSC_CDD_XcpIf_Rte_Call_GetCalPageReq_Oper(uint8 Seg_Arg, uint8 Mod_Arg, uint8 *Page_Arg, uint8 *Rtn_Arg);
Std_ReturnType TSC_CDD_XcpIf_Rte_Call_GetRefTmr1MicroSec32bit_Oper(uint32 *RefTmr_Arg);
Std_ReturnType TSC_CDD_XcpIf_Rte_Call_GetSegInfoReq_Oper(GetSegMod1 Mod_Arg, uint8 Seg_Arg, uint8 SegInfo_Arg, uint8 MpgIdx_Arg, uint8 *Resp_Arg, uint8 *RespLen_Arg, uint8 *Rtn_Arg);
Std_ReturnType TSC_CDD_XcpIf_Rte_Call_OnlineTunRamAdrMpg_Oper(uint32 ReqAdr_Arg, uint32 *CorrdAdr_Arg, AdrMpgReqTyp1 ReqTyp_Arg);
Std_ReturnType TSC_CDD_XcpIf_Rte_Call_SetCalPageReq_Oper(uint8 Seg_Arg, uint8 Mod_Arg, uint8 Page_Arg);
Std_ReturnType TSC_CDD_XcpIf_Rte_Call_XcpCalChgReq_Oper(void);




