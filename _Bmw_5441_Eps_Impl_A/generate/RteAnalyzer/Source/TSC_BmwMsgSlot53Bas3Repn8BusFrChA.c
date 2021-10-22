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
 *          File:  TSC_BmwMsgSlot53Bas3Repn8BusFrChA.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_BmwMsgSlot53Bas3Repn8BusFrChA.h"
#include "TSC_BmwMsgSlot53Bas3Repn8BusFrChA.h"








Std_ReturnType TSC_BmwMsgSlot53Bas3Repn8BusFrChA_Rte_Read_FACT_MO_STE_SO_DXP_FACT_MO_STE_SO_DXP(FACT_MO_STE_SO_DXP1 *data)
{
  return Rte_Read_FACT_MO_STE_SO_DXP_FACT_MO_STE_SO_DXP(data);
}

Std_ReturnType TSC_BmwMsgSlot53Bas3Repn8BusFrChA_Rte_Read_FltCodEnad_Logl(boolean *data)
{
  return Rte_Read_FltCodEnad_Logl(data);
}

Std_ReturnType TSC_BmwMsgSlot53Bas3Repn8BusFrChA_Rte_Read_SU_CLU_STMOM_SFE_DXP_SU_CLU_STMOM_SFE_DXP(SU_CLU_STMOM_SFE_DXP1 *data)
{
  return Rte_Read_SU_CLU_STMOM_SFE_DXP_SU_CLU_STMOM_SFE_DXP(data);
}


boolean TSC_BmwMsgSlot53Bas3Repn8BusFrChA_Rte_IsUpdated_FACT_MO_STE_SO_DXP_FACT_MO_STE_SO_DXP(void)
{
  return Rte_IsUpdated_FACT_MO_STE_SO_DXP_FACT_MO_STE_SO_DXP();
}



Std_ReturnType TSC_BmwMsgSlot53Bas3Repn8BusFrChA_Rte_Write_BmwRtIdx_Val(BmwRtIdx1 data)
{
  return Rte_Write_BmwRtIdx_Val(data);
}

Std_ReturnType TSC_BmwMsgSlot53Bas3Repn8BusFrChA_Rte_Write_BmwRtIdxVld_Logl(boolean data)
{
  return Rte_Write_BmwRtIdxVld_Logl(data);
}

Std_ReturnType TSC_BmwMsgSlot53Bas3Repn8BusFrChA_Rte_Write_BmwSteerMdfnFac_Val(float32 data)
{
  return Rte_Write_BmwSteerMdfnFac_Val(data);
}

Std_ReturnType TSC_BmwMsgSlot53Bas3Repn8BusFrChA_Rte_Write_BmwSteerMdfnFacSts_Val(BmwSteerMdfnFacSts1 data)
{
  return Rte_Write_BmwSteerMdfnFacSts_Val(data);
}





     /* Client Server Interfaces: */
Std_ReturnType TSC_BmwMsgSlot53Bas3Repn8BusFrChA_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
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







     /* BmwMsgSlot53Bas3Repn8BusFrChA */
      /* BmwMsgSlot53Bas3Repn8BusFrChA */

/** Per Instance Memories */
float32 *TSC_BmwMsgSlot53Bas3Repn8BusFrChA_Rte_Pim_BmwSteerMdfnFacPrev(void)
{
  return Rte_Pim_BmwSteerMdfnFacPrev();
}
BmwRtIdx1 *TSC_BmwMsgSlot53Bas3Repn8BusFrChA_Rte_Pim_BmwRtIdxPrev(void)
{
  return Rte_Pim_BmwRtIdxPrev();
}
BmwSteerMdfnFacSts1 *TSC_BmwMsgSlot53Bas3Repn8BusFrChA_Rte_Pim_BmwSteerMdfnFacStsPrev(void)
{
  return Rte_Pim_BmwSteerMdfnFacStsPrev();
}
uint8 *TSC_BmwMsgSlot53Bas3Repn8BusFrChA_Rte_Pim_FactMoSteSoDxpVldFaild(void)
{
  return Rte_Pim_FactMoSteSoDxpVldFaild();
}
uint8 *TSC_BmwMsgSlot53Bas3Repn8BusFrChA_Rte_Pim_FactMoSteSoDxpVldPassd(void)
{
  return Rte_Pim_FactMoSteSoDxpVldPassd();
}
uint8 *TSC_BmwMsgSlot53Bas3Repn8BusFrChA_Rte_Pim_MissMsgFaild(void)
{
  return Rte_Pim_MissMsgFaild();
}
uint8 *TSC_BmwMsgSlot53Bas3Repn8BusFrChA_Rte_Pim_MissMsgPassd(void)
{
  return Rte_Pim_MissMsgPassd();
}
uint8 *TSC_BmwMsgSlot53Bas3Repn8BusFrChA_Rte_Pim_SuCluStmomSfeDxpVldFaild(void)
{
  return Rte_Pim_SuCluStmomSfeDxpVldFaild();
}
uint8 *TSC_BmwMsgSlot53Bas3Repn8BusFrChA_Rte_Pim_SuCluStmomSfeDxpVldPassd(void)
{
  return Rte_Pim_SuCluStmomSfeDxpVldPassd();
}



