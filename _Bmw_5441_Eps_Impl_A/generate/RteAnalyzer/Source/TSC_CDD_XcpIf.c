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
 *          File:  TSC_CDD_XcpIf.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_CDD_XcpIf.h"
#include "TSC_CDD_XcpIf.h"








Std_ReturnType TSC_CDD_XcpIf_Rte_Read_ActvGroup_Val(uint8 *data)
{
  return Rte_Read_ActvGroup_Val(data);
}

Std_ReturnType TSC_CDD_XcpIf_Rte_Read_ActvIninIdx_Val(uint8 *data)
{
  return Rte_Read_ActvIninIdx_Val(data);
}

Std_ReturnType TSC_CDD_XcpIf_Rte_Read_ActvIninOptSetAIdx_Val(uint8 *data)
{
  return Rte_Read_ActvIninOptSetAIdx_Val(data);
}

Std_ReturnType TSC_CDD_XcpIf_Rte_Read_ActvRtIdx_Val(uint8 *data)
{
  return Rte_Read_ActvRtIdx_Val(data);
}

Std_ReturnType TSC_CDD_XcpIf_Rte_Read_CalCopySts_Val(CalCopySts1 *data)
{
  return Rte_Read_CalCopySts_Val(data);
}








     /* Client Server Interfaces: */
Std_ReturnType TSC_CDD_XcpIf_Rte_Call_XcpCalChgReq_Oper(void)
{
  return Rte_Call_XcpCalChgReq_Oper();
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_CDD_XcpIf_Rte_Read_CustXcpEna_Logl(boolean *data)
{
  return Rte_Read_CustXcpEna_Logl(data);
}

Std_ReturnType TSC_CDD_XcpIf_Rte_Read_MfgEnaSt_Val(MfgEnaSt1 *data)
{
  return Rte_Read_MfgEnaSt_Val(data);
}








     /* Client Server Interfaces: */
Std_ReturnType TSC_CDD_XcpIf_Rte_Call_CopyCalPageReq_Oper(uint8 Seg_Arg)
{
  return Rte_Call_CopyCalPageReq_Oper(Seg_Arg);
}
Std_ReturnType TSC_CDD_XcpIf_Rte_Call_GetCalPageReq_Oper(uint8 Seg_Arg, uint8 Mod_Arg, uint8 *Page_Arg, uint8 *Rtn_Arg)
{
  return Rte_Call_GetCalPageReq_Oper(Seg_Arg, Mod_Arg, Page_Arg, Rtn_Arg);
}
Std_ReturnType TSC_CDD_XcpIf_Rte_Call_GetRefTmr1MicroSec32bit_Oper(uint32 *RefTmr_Arg)
{
  return Rte_Call_GetRefTmr1MicroSec32bit_Oper(RefTmr_Arg);
}
Std_ReturnType TSC_CDD_XcpIf_Rte_Call_GetSegInfoReq_Oper(GetSegMod1 Mod_Arg, uint8 Seg_Arg, uint8 SegInfo_Arg, uint8 MpgIdx_Arg, uint8 *Resp_Arg, uint8 *RespLen_Arg, uint8 *Rtn_Arg)
{
  return Rte_Call_GetSegInfoReq_Oper(Mod_Arg, Seg_Arg, SegInfo_Arg, MpgIdx_Arg, Resp_Arg, RespLen_Arg, Rtn_Arg);
}
Std_ReturnType TSC_CDD_XcpIf_Rte_Call_OnlineTunRamAdrMpg_Oper(uint32 ReqAdr_Arg, uint32 *CorrdAdr_Arg, AdrMpgReqTyp1 ReqTyp_Arg)
{
  return Rte_Call_OnlineTunRamAdrMpg_Oper(ReqAdr_Arg, CorrdAdr_Arg, ReqTyp_Arg);
}
Std_ReturnType TSC_CDD_XcpIf_Rte_Call_SetCalPageReq_Oper(uint8 Seg_Arg, uint8 Mod_Arg, uint8 Page_Arg)
{
  return Rte_Call_SetCalPageReq_Oper(Seg_Arg, Mod_Arg, Page_Arg);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */







     /* CDD_XcpIf */
      /* CDD_XcpIf */



