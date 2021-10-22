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
 *          File:  TSC_BmwMsgSlot56Bas0Repn2BusFrChA.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_BmwMsgSlot56Bas0Repn2BusFrChA.h"
#include "TSC_BmwMsgSlot56Bas0Repn2BusFrChA.h"








Std_ReturnType TSC_BmwMsgSlot56Bas0Repn2BusFrChA_Rte_Read_FltCodEnad_Logl(boolean *data)
{
  return Rte_Read_FltCodEnad_Logl(data);
}

Std_ReturnType TSC_BmwMsgSlot56Bas0Repn2BusFrChA_Rte_Read_sigGroup_VYAW_VEH_sigGroup_VYAW_VEH(sigGroup_VYAW_VEH1 *data)
{
  return Rte_Read_sigGroup_VYAW_VEH_sigGroup_VYAW_VEH(data);
}


boolean TSC_BmwMsgSlot56Bas0Repn2BusFrChA_Rte_IsUpdated_sigGroup_VYAW_VEH_sigGroup_VYAW_VEH(void)
{
  return Rte_IsUpdated_sigGroup_VYAW_VEH_sigGroup_VYAW_VEH();
}



Std_ReturnType TSC_BmwMsgSlot56Bas0Repn2BusFrChA_Rte_Write_BmwVehYawQlfr_Val(BmwVehYawQlfr1 data)
{
  return Rte_Write_BmwVehYawQlfr_Val(data);
}

Std_ReturnType TSC_BmwMsgSlot56Bas0Repn2BusFrChA_Rte_Write_BmwVehYawQlfrVld_Logl(boolean data)
{
  return Rte_Write_BmwVehYawQlfrVld_Logl(data);
}

Std_ReturnType TSC_BmwMsgSlot56Bas0Repn2BusFrChA_Rte_Write_BmwVehYawRate_Val(float32 data)
{
  return Rte_Write_BmwVehYawRate_Val(data);
}

Std_ReturnType TSC_BmwMsgSlot56Bas0Repn2BusFrChA_Rte_Write_BmwVehYawRateVld_Logl(boolean data)
{
  return Rte_Write_BmwVehYawRateVld_Logl(data);
}





     /* Client Server Interfaces: */
Std_ReturnType TSC_BmwMsgSlot56Bas0Repn2BusFrChA_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
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







     /* BmwMsgSlot56Bas0Repn2BusFrChA */
      /* BmwMsgSlot56Bas0Repn2BusFrChA */

/** Per Instance Memories */
float32 *TSC_BmwMsgSlot56Bas0Repn2BusFrChA_Rte_Pim_BmwVehYawRatePrev(void)
{
  return Rte_Pim_BmwVehYawRatePrev();
}
uint8 *TSC_BmwMsgSlot56Bas0Repn2BusFrChA_Rte_Pim_AlvFaildCnt(void)
{
  return Rte_Pim_AlvFaildCnt();
}
uint8 *TSC_BmwMsgSlot56Bas0Repn2BusFrChA_Rte_Pim_AlvPassdCnt(void)
{
  return Rte_Pim_AlvPassdCnt();
}
BmwVehYawQlfr1 *TSC_BmwMsgSlot56Bas0Repn2BusFrChA_Rte_Pim_BmwVehYawQlfrPrev(void)
{
  return Rte_Pim_BmwVehYawQlfrPrev();
}
uint8 *TSC_BmwMsgSlot56Bas0Repn2BusFrChA_Rte_Pim_CrcFaildCnt(void)
{
  return Rte_Pim_CrcFaildCnt();
}
uint8 *TSC_BmwMsgSlot56Bas0Repn2BusFrChA_Rte_Pim_CrcPassdCnt(void)
{
  return Rte_Pim_CrcPassdCnt();
}
uint8 *TSC_BmwMsgSlot56Bas0Repn2BusFrChA_Rte_Pim_MissingMsgCnt(void)
{
  return Rte_Pim_MissingMsgCnt();
}
uint8 *TSC_BmwMsgSlot56Bas0Repn2BusFrChA_Rte_Pim_QuVyawVehFaildCnt(void)
{
  return Rte_Pim_QuVyawVehFaildCnt();
}
uint8 *TSC_BmwMsgSlot56Bas0Repn2BusFrChA_Rte_Pim_QuVyawVehPassdCnt(void)
{
  return Rte_Pim_QuVyawVehPassdCnt();
}
uint8 *TSC_BmwMsgSlot56Bas0Repn2BusFrChA_Rte_Pim_RxdMsgCnt(void)
{
  return Rte_Pim_RxdMsgCnt();
}
uint8 *TSC_BmwMsgSlot56Bas0Repn2BusFrChA_Rte_Pim_VyawVehFaildCnt(void)
{
  return Rte_Pim_VyawVehFaildCnt();
}
uint8 *TSC_BmwMsgSlot56Bas0Repn2BusFrChA_Rte_Pim_VyawVehPassdCnt(void)
{
  return Rte_Pim_VyawVehPassdCnt();
}



