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
 *          File:  TSC_BmwMsgSlot276Bas4Repn8BusFrChA.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_BmwMsgSlot276Bas4Repn8BusFrChA.h"
#include "TSC_BmwMsgSlot276Bas4Repn8BusFrChA.h"








Std_ReturnType TSC_BmwMsgSlot276Bas4Repn8BusFrChA_Rte_Read_FltCodEnad_Logl(boolean *data)
{
  return Rte_Read_FltCodEnad_Logl(data);
}

Std_ReturnType TSC_BmwMsgSlot276Bas4Repn8BusFrChA_Rte_Read_MILE_KM_MILE_KM(MILE_KM1 *data)
{
  return Rte_Read_MILE_KM_MILE_KM(data);
}




Std_ReturnType TSC_BmwMsgSlot276Bas4Repn8BusFrChA_Rte_Write_BmwOdomDst_Val(uint32 data)
{
  return Rte_Write_BmwOdomDst_Val(data);
}

Std_ReturnType TSC_BmwMsgSlot276Bas4Repn8BusFrChA_Rte_Write_BmwOdomDstVld_Logl(boolean data)
{
  return Rte_Write_BmwOdomDstVld_Logl(data);
}





     /* Client Server Interfaces: */
Std_ReturnType TSC_BmwMsgSlot276Bas4Repn8BusFrChA_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
{
  return Rte_Call_SetNtcSts_Oper(NtcNr_Arg, NtcStInfo_Arg, NtcSts_Arg, DebStep_Arg);
}


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







     /* BmwMsgSlot276Bas4Repn8BusFrChA */
      /* BmwMsgSlot276Bas4Repn8BusFrChA */

/** Per Instance Memories */
uint32 *TSC_BmwMsgSlot276Bas4Repn8BusFrChA_Rte_Pim_BmwOdomDstPrev(void)
{
  return Rte_Pim_BmwOdomDstPrev();
}
uint8 *TSC_BmwMsgSlot276Bas4Repn8BusFrChA_Rte_Pim_KiloMtrStandFaildCnt(void)
{
  return Rte_Pim_KiloMtrStandFaildCnt();
}
uint8 *TSC_BmwMsgSlot276Bas4Repn8BusFrChA_Rte_Pim_KiloMtrStandPassdCnt(void)
{
  return Rte_Pim_KiloMtrStandPassdCnt();
}
uint8 *TSC_BmwMsgSlot276Bas4Repn8BusFrChA_Rte_Pim_MissingMsgCnt(void)
{
  return Rte_Pim_MissingMsgCnt();
}
uint8 *TSC_BmwMsgSlot276Bas4Repn8BusFrChA_Rte_Pim_RxMsgCnt(void)
{
  return Rte_Pim_RxMsgCnt();
}



