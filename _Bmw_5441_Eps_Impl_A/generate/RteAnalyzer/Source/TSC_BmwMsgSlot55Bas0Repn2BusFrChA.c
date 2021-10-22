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
 *          File:  TSC_BmwMsgSlot55Bas0Repn2BusFrChA.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_BmwMsgSlot55Bas0Repn2BusFrChA.h"
#include "TSC_BmwMsgSlot55Bas0Repn2BusFrChA.h"








Std_ReturnType TSC_BmwMsgSlot55Bas0Repn2BusFrChA_Rte_Read_FltCodEnad_Logl(boolean *data)
{
  return Rte_Read_FltCodEnad_Logl(data);
}

Std_ReturnType TSC_BmwMsgSlot55Bas0Repn2BusFrChA_Rte_Read_sigGroup_ACLNY_MASSCNTR_sigGroup_ACLNY_MASSCNTR(sigGroup_ACLNY_MASSCNTR1 *data)
{
  return Rte_Read_sigGroup_ACLNY_MASSCNTR_sigGroup_ACLNY_MASSCNTR(data);
}


boolean TSC_BmwMsgSlot55Bas0Repn2BusFrChA_Rte_IsUpdated_sigGroup_ACLNY_MASSCNTR_sigGroup_ACLNY_MASSCNTR(void)
{
  return Rte_IsUpdated_sigGroup_ACLNY_MASSCNTR_sigGroup_ACLNY_MASSCNTR();
}



Std_ReturnType TSC_BmwMsgSlot55Bas0Repn2BusFrChA_Rte_Write_BmwVehLatA_Val(float32 data)
{
  return Rte_Write_BmwVehLatA_Val(data);
}

Std_ReturnType TSC_BmwMsgSlot55Bas0Repn2BusFrChA_Rte_Write_BmwVehLatAQlfr_Val(BmwVehLatAQlfr1 data)
{
  return Rte_Write_BmwVehLatAQlfr_Val(data);
}

Std_ReturnType TSC_BmwMsgSlot55Bas0Repn2BusFrChA_Rte_Write_BmwVehLatAQlfrVld_Logl(boolean data)
{
  return Rte_Write_BmwVehLatAQlfrVld_Logl(data);
}

Std_ReturnType TSC_BmwMsgSlot55Bas0Repn2BusFrChA_Rte_Write_BmwVehLatAVld_Logl(boolean data)
{
  return Rte_Write_BmwVehLatAVld_Logl(data);
}





     /* Client Server Interfaces: */
Std_ReturnType TSC_BmwMsgSlot55Bas0Repn2BusFrChA_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
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





sint8  TSC_BmwMsgSlot55Bas0Repn2BusFrChA_Rte_Prm_BmwMsgSlot55Bas0Repn2BusFrChABmwLatAPolarity_Val(void)
{
  return (sint8 ) Rte_Prm_BmwMsgSlot55Bas0Repn2BusFrChABmwLatAPolarity_Val();
}


     /* BmwMsgSlot55Bas0Repn2BusFrChA */
      /* BmwMsgSlot55Bas0Repn2BusFrChA */

/** Per Instance Memories */
float32 *TSC_BmwMsgSlot55Bas0Repn2BusFrChA_Rte_Pim_BmwVehLatAPrev(void)
{
  return Rte_Pim_BmwVehLatAPrev();
}
uint8 *TSC_BmwMsgSlot55Bas0Repn2BusFrChA_Rte_Pim_AclnyCogFaildCnt(void)
{
  return Rte_Pim_AclnyCogFaildCnt();
}
uint8 *TSC_BmwMsgSlot55Bas0Repn2BusFrChA_Rte_Pim_AclnyCogPassdCnt(void)
{
  return Rte_Pim_AclnyCogPassdCnt();
}
uint8 *TSC_BmwMsgSlot55Bas0Repn2BusFrChA_Rte_Pim_AlvFaildCnt(void)
{
  return Rte_Pim_AlvFaildCnt();
}
uint8 *TSC_BmwMsgSlot55Bas0Repn2BusFrChA_Rte_Pim_AlvPassdCnt(void)
{
  return Rte_Pim_AlvPassdCnt();
}
BmwVehLatAQlfr1 *TSC_BmwMsgSlot55Bas0Repn2BusFrChA_Rte_Pim_BmwVehLatAQlfrPrev(void)
{
  return Rte_Pim_BmwVehLatAQlfrPrev();
}
uint8 *TSC_BmwMsgSlot55Bas0Repn2BusFrChA_Rte_Pim_CrcFaildCnt(void)
{
  return Rte_Pim_CrcFaildCnt();
}
uint8 *TSC_BmwMsgSlot55Bas0Repn2BusFrChA_Rte_Pim_CrcPassdCnt(void)
{
  return Rte_Pim_CrcPassdCnt();
}
uint8 *TSC_BmwMsgSlot55Bas0Repn2BusFrChA_Rte_Pim_MissingMsgCnt(void)
{
  return Rte_Pim_MissingMsgCnt();
}
uint8 *TSC_BmwMsgSlot55Bas0Repn2BusFrChA_Rte_Pim_QuAclnyCogFaildCnt(void)
{
  return Rte_Pim_QuAclnyCogFaildCnt();
}
uint8 *TSC_BmwMsgSlot55Bas0Repn2BusFrChA_Rte_Pim_QuAclnyCogPassdCnt(void)
{
  return Rte_Pim_QuAclnyCogPassdCnt();
}
uint8 *TSC_BmwMsgSlot55Bas0Repn2BusFrChA_Rte_Pim_RxdMsgCnt(void)
{
  return Rte_Pim_RxdMsgCnt();
}



