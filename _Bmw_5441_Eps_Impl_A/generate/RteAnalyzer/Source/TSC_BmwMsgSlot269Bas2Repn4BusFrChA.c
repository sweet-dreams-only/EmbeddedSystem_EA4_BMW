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
 *          File:  TSC_BmwMsgSlot269Bas2Repn4BusFrChA.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_BmwMsgSlot269Bas2Repn4BusFrChA.h"
#include "TSC_BmwMsgSlot269Bas2Repn4BusFrChA.h"















     /* Client Server Interfaces: */
Std_ReturnType TSC_BmwMsgSlot269Bas2Repn4BusFrChA_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
{
  return Rte_Call_SetNtcSts_Oper(NtcNr_Arg, NtcStInfo_Arg, NtcSts_Arg, DebStep_Arg);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_BmwMsgSlot269Bas2Repn4BusFrChA_Rte_Read_FltCodEnad_Logl(boolean *data)
{
  return Rte_Read_FltCodEnad_Logl(data);
}




Std_ReturnType TSC_BmwMsgSlot269Bas2Repn4BusFrChA_Rte_Write_BmwHaptcFbDirNr_Val(BmwHaptcFbDirNr1 data)
{
  return Rte_Write_BmwHaptcFbDirNr_Val(data);
}

Std_ReturnType TSC_BmwMsgSlot269Bas2Repn4BusFrChA_Rte_Write_BmwHaptcFbDirNrVld_Logl(boolean data)
{
  return Rte_Write_BmwHaptcFbDirNrVld_Logl(data);
}

Std_ReturnType TSC_BmwMsgSlot269Bas2Repn4BusFrChA_Rte_Write_BmwHaptcFbIntenNr_Val(BmwHaptcFbIntenNr1 data)
{
  return Rte_Write_BmwHaptcFbIntenNr_Val(data);
}

Std_ReturnType TSC_BmwMsgSlot269Bas2Repn4BusFrChA_Rte_Write_BmwHaptcFbIntenNrVld_Logl(boolean data)
{
  return Rte_Write_BmwHaptcFbIntenNrVld_Logl(data);
}

Std_ReturnType TSC_BmwMsgSlot269Bas2Repn4BusFrChA_Rte_Write_BmwHaptcFbPatNr_Val(BmwHaptcFbPatNr1 data)
{
  return Rte_Write_BmwHaptcFbPatNr_Val(data);
}

Std_ReturnType TSC_BmwMsgSlot269Bas2Repn4BusFrChA_Rte_Write_BmwHaptcFbPatNrVld_Logl(boolean data)
{
  return Rte_Write_BmwHaptcFbPatNrVld_Logl(data);
}





     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_BmwMsgSlot269Bas2Repn4BusFrChA_Rte_Read_CTR_WARN_DIR_VIB_EPS_CTR_WARN_DIR_VIB_EPS(CTR_WARN_DIR_VIB_EPS1 *data)
{
  return Rte_Read_CTR_WARN_DIR_VIB_EPS_CTR_WARN_DIR_VIB_EPS(data);
}

Std_ReturnType TSC_BmwMsgSlot269Bas2Repn4BusFrChA_Rte_Read_CTR_WARN_ILVL_VIB_EPS_CTR_WARN_ILVL_VIB_EPS(CTR_WARN_ILVL_VIB_EPS1 *data)
{
  return Rte_Read_CTR_WARN_ILVL_VIB_EPS_CTR_WARN_ILVL_VIB_EPS(data);
}

Std_ReturnType TSC_BmwMsgSlot269Bas2Repn4BusFrChA_Rte_Read_CTR_WARN_PTRN_VIB_EPS_CTR_WARN_PTRN_VIB_EPS(CTR_WARN_PTRN_VIB_EPS1 *data)
{
  return Rte_Read_CTR_WARN_PTRN_VIB_EPS_CTR_WARN_PTRN_VIB_EPS(data);
}








     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */







     /* BmwMsgSlot269Bas2Repn4BusFrChA */
      /* BmwMsgSlot269Bas2Repn4BusFrChA */

/** Per Instance Memories */
BmwHaptcFbDirNr1 *TSC_BmwMsgSlot269Bas2Repn4BusFrChA_Rte_Pim_BmwHaptcFbDirNrPrev(void)
{
  return Rte_Pim_BmwHaptcFbDirNrPrev();
}
BmwHaptcFbIntenNr1 *TSC_BmwMsgSlot269Bas2Repn4BusFrChA_Rte_Pim_BmwHaptcFbIntenNrPrev(void)
{
  return Rte_Pim_BmwHaptcFbIntenNrPrev();
}
BmwHaptcFbPatNr1 *TSC_BmwMsgSlot269Bas2Repn4BusFrChA_Rte_Pim_BmwHaptcFbPatNrPrev(void)
{
  return Rte_Pim_BmwHaptcFbPatNrPrev();
}
uint8 *TSC_BmwMsgSlot269Bas2Repn4BusFrChA_Rte_Pim_CtrVibStwDispExmiSp2015MissFaild(void)
{
  return Rte_Pim_CtrVibStwDispExmiSp2015MissFaild();
}
uint8 *TSC_BmwMsgSlot269Bas2Repn4BusFrChA_Rte_Pim_CtrVibStwDispExmiSp2015MissPassd(void)
{
  return Rte_Pim_CtrVibStwDispExmiSp2015MissPassd();
}
uint8 *TSC_BmwMsgSlot269Bas2Repn4BusFrChA_Rte_Pim_CtrWarnDirVibEpsVldFaild(void)
{
  return Rte_Pim_CtrWarnDirVibEpsVldFaild();
}
uint8 *TSC_BmwMsgSlot269Bas2Repn4BusFrChA_Rte_Pim_CtrWarnDirVibEpsVldPassd(void)
{
  return Rte_Pim_CtrWarnDirVibEpsVldPassd();
}
uint8 *TSC_BmwMsgSlot269Bas2Repn4BusFrChA_Rte_Pim_CtrWarnIlvlVibEpsVldFaild(void)
{
  return Rte_Pim_CtrWarnIlvlVibEpsVldFaild();
}
uint8 *TSC_BmwMsgSlot269Bas2Repn4BusFrChA_Rte_Pim_CtrWarnIlvlVibEpsVldPassd(void)
{
  return Rte_Pim_CtrWarnIlvlVibEpsVldPassd();
}
uint8 *TSC_BmwMsgSlot269Bas2Repn4BusFrChA_Rte_Pim_CtrWarnPtrnVibEpsVldFaild(void)
{
  return Rte_Pim_CtrWarnPtrnVibEpsVldFaild();
}
uint8 *TSC_BmwMsgSlot269Bas2Repn4BusFrChA_Rte_Pim_CtrWarnPtrnVibEpsVldPassd(void)
{
  return Rte_Pim_CtrWarnPtrnVibEpsVldPassd();
}



