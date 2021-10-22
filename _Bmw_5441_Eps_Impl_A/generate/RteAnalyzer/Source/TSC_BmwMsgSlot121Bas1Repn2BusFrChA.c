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
 *          File:  TSC_BmwMsgSlot121Bas1Repn2BusFrChA.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_BmwMsgSlot121Bas1Repn2BusFrChA.h"
#include "TSC_BmwMsgSlot121Bas1Repn2BusFrChA.h"








Std_ReturnType TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Read_FltCodEnad_Logl(boolean *data)
{
  return Rte_Read_FltCodEnad_Logl(data);
}




Std_ReturnType TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Write_BmwBasPtlNetCtrl_Val(BmwBasPtlNetCtrl1 data)
{
  return Rte_Write_BmwBasPtlNetCtrl_Val(data);
}

Std_ReturnType TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Write_BmwBasPtlNetCtrlVld_Logl(boolean data)
{
  return Rte_Write_BmwBasPtlNetCtrlVld_Logl(data);
}

Std_ReturnType TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Write_BmwVehCdn_Val(BmwVehCdn1 data)
{
  return Rte_Write_BmwVehCdn_Val(data);
}

Std_ReturnType TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Write_BmwVehCdnQlfr_Val(BmwVehCdnQlfr1 data)
{
  return Rte_Write_BmwVehCdnQlfr_Val(data);
}

Std_ReturnType TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Write_BmwVehCdnQlfrVld_Logl(boolean data)
{
  return Rte_Write_BmwVehCdnQlfrVld_Logl(data);
}

Std_ReturnType TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Write_BmwVehCdnVld_Logl(boolean data)
{
  return Rte_Write_BmwVehCdnVld_Logl(data);
}





     /* Client Server Interfaces: */
Std_ReturnType TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
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






Std_ReturnType TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Read_sigGroup_CON_VEH_sigGroup_CON_VEH(sigGroup_CON_VEH1 *data)
{
  return Rte_Read_sigGroup_CON_VEH_sigGroup_CON_VEH(data);
}


boolean TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_IsUpdated_sigGroup_CON_VEH_sigGroup_CON_VEH(void)
{
  return Rte_IsUpdated_sigGroup_CON_VEH_sigGroup_CON_VEH();
}







     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */







     /* BmwMsgSlot121Bas1Repn2BusFrChA */
      /* BmwMsgSlot121Bas1Repn2BusFrChA */

/** Per Instance Memories */
uint8 *TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Pim_AlvFaildCnt(void)
{
  return Rte_Pim_AlvFaildCnt();
}
uint8 *TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Pim_AlvPassdCnt(void)
{
  return Rte_Pim_AlvPassdCnt();
}
BmwBasPtlNetCtrl1 *TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Pim_BmwBasPtlNetCtrlPrev(void)
{
  return Rte_Pim_BmwBasPtlNetCtrlPrev();
}
BmwVehCdn1 *TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Pim_BmwVehCdnPrev(void)
{
  return Rte_Pim_BmwVehCdnPrev();
}
BmwVehCdnQlfr1 *TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Pim_BmwVehCdnQlfrPrev(void)
{
  return Rte_Pim_BmwVehCdnQlfrPrev();
}
uint8 *TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Pim_CrcFaildCnt(void)
{
  return Rte_Pim_CrcFaildCnt();
}
uint8 *TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Pim_CrcPassdCnt(void)
{
  return Rte_Pim_CrcPassdCnt();
}
uint8 *TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Pim_CtrBsPrtntFaildCnt(void)
{
  return Rte_Pim_CtrBsPrtntFaildCnt();
}
uint8 *TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Pim_CtrBsPrtntPassdCnt(void)
{
  return Rte_Pim_CtrBsPrtntPassdCnt();
}
uint8 *TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Pim_CtrFktnPrtntFaildCnt(void)
{
  return Rte_Pim_CtrFktnPrtntFaildCnt();
}
uint8 *TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Pim_CtrFktnPrtntPassdCnt(void)
{
  return Rte_Pim_CtrFktnPrtntPassdCnt();
}
QU_ST_CON_VEH1 *TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Pim_Dummy_PIM1(void)
{
  return Rte_Pim_Dummy_PIM1();
}
QU_V_VEH_COG1 *TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Pim_Dummy_PIM2(void)
{
  return Rte_Pim_Dummy_PIM2();
}
ST_CON_VEH1 *TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Pim_Dummy_PIM3(void)
{
  return Rte_Pim_Dummy_PIM3();
}
CTR_BS_PRTNT1 *TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Pim_Dummy_PIM4(void)
{
  return Rte_Pim_Dummy_PIM4();
}
uint8 *TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Pim_MissMsgCnt(void)
{
  return Rte_Pim_MissMsgCnt();
}
uint8 *TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Pim_QlfrCogFaildCnt(void)
{
  return Rte_Pim_QlfrCogFaildCnt();
}
uint8 *TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Pim_QlfrCogPassdCnt(void)
{
  return Rte_Pim_QlfrCogPassdCnt();
}
uint8 *TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Pim_QuStConVehFaildCnt(void)
{
  return Rte_Pim_QuStConVehFaildCnt();
}
uint8 *TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Pim_QuStConVehPassdCnt(void)
{
  return Rte_Pim_QuStConVehPassdCnt();
}
uint8 *TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Pim_RxdMsgCnt(void)
{
  return Rte_Pim_RxdMsgCnt();
}
uint8 *TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Pim_StConVehFaildCnt(void)
{
  return Rte_Pim_StConVehFaildCnt();
}
uint8 *TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Pim_StConVehPassdCnt(void)
{
  return Rte_Pim_StConVehPassdCnt();
}



