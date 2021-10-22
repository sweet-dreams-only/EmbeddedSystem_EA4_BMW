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
 *          File:  TSC_TunSelnMngt.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_TunSelnMngt.h"
#include "TSC_TunSelnMngt.h"















     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_TunSelnMngt_Rte_Read_DesIninIdx_Val(uint8 *data)
{
  return Rte_Read_DesIninIdx_Val(data);
}

Std_ReturnType TSC_TunSelnMngt_Rte_Read_DesIninOptSetAIdx_Val(uint8 *data)
{
  return Rte_Read_DesIninOptSetAIdx_Val(data);
}

Std_ReturnType TSC_TunSelnMngt_Rte_Read_DesRtIdx_Val(uint8 *data)
{
  return Rte_Read_DesRtIdx_Val(data);
}




Std_ReturnType TSC_TunSelnMngt_Rte_Write_ActvGroup_Val(uint8 data)
{
  return Rte_Write_ActvGroup_Val(data);
}

Std_ReturnType TSC_TunSelnMngt_Rte_Write_ActvIninIdx_Val(uint8 data)
{
  return Rte_Write_ActvIninIdx_Val(data);
}

Std_ReturnType TSC_TunSelnMngt_Rte_Write_ActvIninOptSetAIdx_Val(uint8 data)
{
  return Rte_Write_ActvIninOptSetAIdx_Val(data);
}

Std_ReturnType TSC_TunSelnMngt_Rte_Write_ActvRtIdx_Val(uint8 data)
{
  return Rte_Write_ActvRtIdx_Val(data);
}

Std_ReturnType TSC_TunSelnMngt_Rte_Write_CalCopySts_Val(CalCopySts1 data)
{
  return Rte_Write_CalCopySts_Val(data);
}

Std_ReturnType TSC_TunSelnMngt_Rte_Write_RtIdxChgSts_Val(RtIdxChgSts1 data)
{
  return Rte_Write_RtIdxChgSts_Val(data);
}





     /* Client Server Interfaces: */
Std_ReturnType TSC_TunSelnMngt_Rte_Call_Calc32BitCrc_u32_Oper(uint32 *DataPtr_Arg, uint32 Len_Arg, uint32 StrtVal_Arg, boolean FirstCall_Arg, uint32 *CalcCrcRes_Arg)
{
  return Rte_Call_Calc32BitCrc_u32_Oper(DataPtr_Arg, Len_Arg, StrtVal_Arg, FirstCall_Arg, CalcCrcRes_Arg);
}
Std_ReturnType TSC_TunSelnMngt_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
{
  return Rte_Call_SetNtcSts_Oper(NtcNr_Arg, NtcStInfo_Arg, NtcSts_Arg, DebStep_Arg);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */
Std_ReturnType TSC_TunSelnMngt_Rte_Call_RtCalChgReq_Oper(void)
{
  return Rte_Call_RtCalChgReq_Oper();
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */







     /* TunSelnMngt */
      /* TunSelnMngt */
void TSC_TunSelnMngt_Rte_Enter_TunSelnMngtIntDataProtnExclsvArea(void)
{
  Rte_Enter_TunSelnMngtIntDataProtnExclsvArea();
}
void TSC_TunSelnMngt_Rte_Exit_TunSelnMngtIntDataProtnExclsvArea(void)
{
  Rte_Exit_TunSelnMngtIntDataProtnExclsvArea();
}

/** Per Instance Memories */
uint8 *TSC_TunSelnMngt_Rte_Pim_PrevActvIninIdx(void)
{
  return Rte_Pim_PrevActvIninIdx();
}
uint8 *TSC_TunSelnMngt_Rte_Pim_PrevActvIninOptSetAIdx(void)
{
  return Rte_Pim_PrevActvIninOptSetAIdx();
}
uint8 *TSC_TunSelnMngt_Rte_Pim_PrevActvRtIdx(void)
{
  return Rte_Pim_PrevActvRtIdx();
}
uint8 *TSC_TunSelnMngt_Rte_Pim_PrevRamPageAcs(void)
{
  return Rte_Pim_PrevRamPageAcs();
}
RtIdxChgSts1 *TSC_TunSelnMngt_Rte_Pim_PrevRtIdxChgSts(void)
{
  return Rte_Pim_PrevRtIdxChgSts();
}
uint8 *TSC_TunSelnMngt_Rte_Pim_RamTblSwt(void)
{
  return Rte_Pim_RamTblSwt();
}
OnlineCalStsRec2 *TSC_TunSelnMngt_Rte_Pim_OnlineCalSts(void)
{
  return Rte_Pim_OnlineCalSts();
}



