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
 *          File:  TSC_BmwMsgSlot55Bas3Repn4BusFrChA.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_BmwMsgSlot55Bas3Repn4BusFrChA.h"
#include "TSC_BmwMsgSlot55Bas3Repn4BusFrChA.h"















     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_BmwMsgSlot55Bas3Repn4BusFrChA_Rte_Read_FltCodEnad_Logl(boolean *data)
{
  return Rte_Read_FltCodEnad_Logl(data);
}




Std_ReturnType TSC_BmwMsgSlot55Bas3Repn4BusFrChA_Rte_Write_BmwCogVehSpd_Val(float32 data)
{
  return Rte_Write_BmwCogVehSpd_Val(data);
}

Std_ReturnType TSC_BmwMsgSlot55Bas3Repn4BusFrChA_Rte_Write_BmwCogVehSpdQlfr_Val(BmwCogVehSpdQlfr1 data)
{
  return Rte_Write_BmwCogVehSpdQlfr_Val(data);
}

Std_ReturnType TSC_BmwMsgSlot55Bas3Repn4BusFrChA_Rte_Write_BmwCogVehSpdQlfrVld_Logl(boolean data)
{
  return Rte_Write_BmwCogVehSpdQlfrVld_Logl(data);
}

Std_ReturnType TSC_BmwMsgSlot55Bas3Repn4BusFrChA_Rte_Write_BmwCogVehSpdVld_Logl(boolean data)
{
  return Rte_Write_BmwCogVehSpdVld_Logl(data);
}

Std_ReturnType TSC_BmwMsgSlot55Bas3Repn4BusFrChA_Rte_Write_BmwNearStillVehSpdSts_Val(BmwNearStillVehSpdSts1 data)
{
  return Rte_Write_BmwNearStillVehSpdSts_Val(data);
}

Std_ReturnType TSC_BmwMsgSlot55Bas3Repn4BusFrChA_Rte_Write_BmwNearStillVehSpdStsVld_Logl(boolean data)
{
  return Rte_Write_BmwNearStillVehSpdStsVld_Logl(data);
}





     /* Client Server Interfaces: */
Std_ReturnType TSC_BmwMsgSlot55Bas3Repn4BusFrChA_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
{
  return Rte_Call_SetNtcSts_Oper(NtcNr_Arg, NtcStInfo_Arg, NtcSts_Arg, DebStep_Arg);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_BmwMsgSlot55Bas3Repn4BusFrChA_Rte_Read_sigGroup_V_VEH_sigGroup_V_VEH(sigGroup_V_VEH1 *data)
{
  return Rte_Read_sigGroup_V_VEH_sigGroup_V_VEH(data);
}


boolean TSC_BmwMsgSlot55Bas3Repn4BusFrChA_Rte_IsUpdated_sigGroup_V_VEH_sigGroup_V_VEH(void)
{
  return Rte_IsUpdated_sigGroup_V_VEH_sigGroup_V_VEH();
}







     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */







     /* BmwMsgSlot55Bas3Repn4BusFrChA */
      /* BmwMsgSlot55Bas3Repn4BusFrChA */

/** Per Instance Memories */
float32 *TSC_BmwMsgSlot55Bas3Repn4BusFrChA_Rte_Pim_BmwCogVehSpdPrev(void)
{
  return Rte_Pim_BmwCogVehSpdPrev();
}
uint8 *TSC_BmwMsgSlot55Bas3Repn4BusFrChA_Rte_Pim_AlvFaildCnt(void)
{
  return Rte_Pim_AlvFaildCnt();
}
uint8 *TSC_BmwMsgSlot55Bas3Repn4BusFrChA_Rte_Pim_AlvPassdCnt(void)
{
  return Rte_Pim_AlvPassdCnt();
}
BmwCogVehSpdQlfr1 *TSC_BmwMsgSlot55Bas3Repn4BusFrChA_Rte_Pim_BmwCogVehSpdQlfrPrev(void)
{
  return Rte_Pim_BmwCogVehSpdQlfrPrev();
}
BmwNearStillVehSpdSts1 *TSC_BmwMsgSlot55Bas3Repn4BusFrChA_Rte_Pim_BmwNearStillVehSpdStsPrev(void)
{
  return Rte_Pim_BmwNearStillVehSpdStsPrev();
}
uint8 *TSC_BmwMsgSlot55Bas3Repn4BusFrChA_Rte_Pim_CrcFaildCnt(void)
{
  return Rte_Pim_CrcFaildCnt();
}
uint8 *TSC_BmwMsgSlot55Bas3Repn4BusFrChA_Rte_Pim_CrcPassdCnt(void)
{
  return Rte_Pim_CrcPassdCnt();
}
QU_V_VEH_COG1 *TSC_BmwMsgSlot55Bas3Repn4BusFrChA_Rte_Pim_Dummy_PIM1(void)
{
  return Rte_Pim_Dummy_PIM1();
}
ST_V_VEH_NSS1 *TSC_BmwMsgSlot55Bas3Repn4BusFrChA_Rte_Pim_Dummy_PIM2(void)
{
  return Rte_Pim_Dummy_PIM2();
}
uint8 *TSC_BmwMsgSlot55Bas3Repn4BusFrChA_Rte_Pim_MissMsgCnt(void)
{
  return Rte_Pim_MissMsgCnt();
}
uint8 *TSC_BmwMsgSlot55Bas3Repn4BusFrChA_Rte_Pim_QlfrCogFaildCnt(void)
{
  return Rte_Pim_QlfrCogFaildCnt();
}
uint8 *TSC_BmwMsgSlot55Bas3Repn4BusFrChA_Rte_Pim_QlfrCogPassdCnt(void)
{
  return Rte_Pim_QlfrCogPassdCnt();
}
uint8 *TSC_BmwMsgSlot55Bas3Repn4BusFrChA_Rte_Pim_RxdMsgCnt(void)
{
  return Rte_Pim_RxdMsgCnt();
}
uint8 *TSC_BmwMsgSlot55Bas3Repn4BusFrChA_Rte_Pim_StVehNearStillFailCnt(void)
{
  return Rte_Pim_StVehNearStillFailCnt();
}
uint8 *TSC_BmwMsgSlot55Bas3Repn4BusFrChA_Rte_Pim_StVehNearStillPassCnt(void)
{
  return Rte_Pim_StVehNearStillPassCnt();
}
uint8 *TSC_BmwMsgSlot55Bas3Repn4BusFrChA_Rte_Pim_VehCogFaildCnt(void)
{
  return Rte_Pim_VehCogFaildCnt();
}
uint8 *TSC_BmwMsgSlot55Bas3Repn4BusFrChA_Rte_Pim_VehCogPassdCnt(void)
{
  return Rte_Pim_VehCogPassdCnt();
}



