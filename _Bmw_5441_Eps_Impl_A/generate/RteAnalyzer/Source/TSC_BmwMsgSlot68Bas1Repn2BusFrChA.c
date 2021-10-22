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
 *          File:  TSC_BmwMsgSlot68Bas1Repn2BusFrChA.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_BmwMsgSlot68Bas1Repn2BusFrChA.h"
#include "TSC_BmwMsgSlot68Bas1Repn2BusFrChA.h"















     /* Client Server Interfaces: */
Std_ReturnType TSC_BmwMsgSlot68Bas1Repn2BusFrChA_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
{
  return Rte_Call_SetNtcSts_Oper(NtcNr_Arg, NtcStInfo_Arg, NtcSts_Arg, DebStep_Arg);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_BmwMsgSlot68Bas1Repn2BusFrChA_Rte_Read_FltCodEnad_Logl(boolean *data)
{
  return Rte_Read_FltCodEnad_Logl(data);
}




Std_ReturnType TSC_BmwMsgSlot68Bas1Repn2BusFrChA_Rte_Write_BmwMaxCurrLimr_Val(float32 data)
{
  return Rte_Write_BmwMaxCurrLimr_Val(data);
}

Std_ReturnType TSC_BmwMsgSlot68Bas1Repn2BusFrChA_Rte_Write_BmwMaxCurrLimrSts_Val(BmwMaxCurrLimrSts1 data)
{
  return Rte_Write_BmwMaxCurrLimrSts_Val(data);
}

Std_ReturnType TSC_BmwMsgSlot68Bas1Repn2BusFrChA_Rte_Write_BmwRqrdCurrLimEpsSfty_Val(BmwRqrdCurrLimEpsSfty1 data)
{
  return Rte_Write_BmwRqrdCurrLimEpsSfty_Val(data);
}

Std_ReturnType TSC_BmwMsgSlot68Bas1Repn2BusFrChA_Rte_Write_BmwRqrdCurrLimEpsSftyVld_Logl(boolean data)
{
  return Rte_Write_BmwRqrdCurrLimEpsSftyVld_Logl(data);
}





     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_BmwMsgSlot68Bas1Repn2BusFrChA_Rte_Read_sigGroup_ENERG_DGR_DRDY_sigGroup_ENERG_DGR_DRDY(sigGroup_ENERG_DGR_DRDY1 *data)
{
  return Rte_Read_sigGroup_ENERG_DGR_DRDY_sigGroup_ENERG_DGR_DRDY(data);
}


boolean TSC_BmwMsgSlot68Bas1Repn2BusFrChA_Rte_IsUpdated_sigGroup_ENERG_DGR_DRDY_sigGroup_ENERG_DGR_DRDY(void)
{
  return Rte_IsUpdated_sigGroup_ENERG_DGR_DRDY_sigGroup_ENERG_DGR_DRDY();
}







     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */







     /* BmwMsgSlot68Bas1Repn2BusFrChA */
      /* BmwMsgSlot68Bas1Repn2BusFrChA */

/** Per Instance Memories */
float32 *TSC_BmwMsgSlot68Bas1Repn2BusFrChA_Rte_Pim_BmwMaxCurrLimrPrev(void)
{
  return Rte_Pim_BmwMaxCurrLimrPrev();
}
uint8 *TSC_BmwMsgSlot68Bas1Repn2BusFrChA_Rte_Pim_AlvFaildCnt(void)
{
  return Rte_Pim_AlvFaildCnt();
}
uint8 *TSC_BmwMsgSlot68Bas1Repn2BusFrChA_Rte_Pim_AlvPassdCnt(void)
{
  return Rte_Pim_AlvPassdCnt();
}
uint8 *TSC_BmwMsgSlot68Bas1Repn2BusFrChA_Rte_Pim_BmwRqrdCurrLimEpsSftyPrev(void)
{
  return Rte_Pim_BmwRqrdCurrLimEpsSftyPrev();
}
uint8 *TSC_BmwMsgSlot68Bas1Repn2BusFrChA_Rte_Pim_CrcFaildCnt(void)
{
  return Rte_Pim_CrcFaildCnt();
}
uint8 *TSC_BmwMsgSlot68Bas1Repn2BusFrChA_Rte_Pim_CrcPassdCnt(void)
{
  return Rte_Pim_CrcPassdCnt();
}
uint8 *TSC_BmwMsgSlot68Bas1Repn2BusFrChA_Rte_Pim_MaxCurrSpecEPSFaildCnt(void)
{
  return Rte_Pim_MaxCurrSpecEPSFaildCnt();
}
uint8 *TSC_BmwMsgSlot68Bas1Repn2BusFrChA_Rte_Pim_MaxCurrSpecEPSPassdCnt(void)
{
  return Rte_Pim_MaxCurrSpecEPSPassdCnt();
}
uint8 *TSC_BmwMsgSlot68Bas1Repn2BusFrChA_Rte_Pim_MissingMsgCnt(void)
{
  return Rte_Pim_MissingMsgCnt();
}
uint8 *TSC_BmwMsgSlot68Bas1Repn2BusFrChA_Rte_Pim_RqCuliEstSfyFaildCnt(void)
{
  return Rte_Pim_RqCuliEstSfyFaildCnt();
}
uint8 *TSC_BmwMsgSlot68Bas1Repn2BusFrChA_Rte_Pim_RqCuliEstSfyPassdCnt(void)
{
  return Rte_Pim_RqCuliEstSfyPassdCnt();
}
uint8 *TSC_BmwMsgSlot68Bas1Repn2BusFrChA_Rte_Pim_RxdMsgCnt(void)
{
  return Rte_Pim_RxdMsgCnt();
}



