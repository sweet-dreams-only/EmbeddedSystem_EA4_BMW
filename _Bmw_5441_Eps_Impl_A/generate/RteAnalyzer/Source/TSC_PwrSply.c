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
 *          File:  TSC_PwrSply.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_PwrSply.h"
#include "TSC_PwrSply.h"















     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_PwrSply_Rte_Read_SysSt_Val(SysSt1 *data)
{
  return Rte_Read_SysSt_Val(data);
}








     /* Client Server Interfaces: */
Std_ReturnType TSC_PwrSply_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
{
  return Rte_Call_SetNtcSts_Oper(NtcNr_Arg, NtcStInfo_Arg, NtcSts_Arg, DebStep_Arg);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */





uint16  TSC_PwrSply_Rte_Prm_PwrSplyNtc0x07BFailStep_Val(void)
{
  return (uint16 ) Rte_Prm_PwrSplyNtc0x07BFailStep_Val();
}
uint16  TSC_PwrSply_Rte_Prm_PwrSplyNtc0x07BPassStep_Val(void)
{
  return (uint16 ) Rte_Prm_PwrSplyNtc0x07BPassStep_Val();
}
uint16  TSC_PwrSply_Rte_Prm_PwrSplyNtc0x07CFailStep_Val(void)
{
  return (uint16 ) Rte_Prm_PwrSplyNtc0x07CFailStep_Val();
}
uint16  TSC_PwrSply_Rte_Prm_PwrSplyNtc0x07CPassStep_Val(void)
{
  return (uint16 ) Rte_Prm_PwrSplyNtc0x07CPassStep_Val();
}
uint16  TSC_PwrSply_Rte_Prm_PwrSplyNtc0x07DFailStep_Val(void)
{
  return (uint16 ) Rte_Prm_PwrSplyNtc0x07DFailStep_Val();
}
uint16  TSC_PwrSply_Rte_Prm_PwrSplyNtc0x07DPassStep_Val(void)
{
  return (uint16 ) Rte_Prm_PwrSplyNtc0x07DPassStep_Val();
}


     /* PwrSply */
      /* PwrSply */

/** Per Instance Memories */
uint16 *TSC_PwrSply_Rte_Pim_SpiTrsmErrCntr(void)
{
  return Rte_Pim_SpiTrsmErrCntr();
}
boolean *TSC_PwrSply_Rte_Pim_ReadWrOrderFlg1(void)
{
  return Rte_Pim_ReadWrOrderFlg1();
}
boolean *TSC_PwrSply_Rte_Pim_ReadWrOrderFlg2(void)
{
  return Rte_Pim_ReadWrOrderFlg2();
}
boolean *TSC_PwrSply_Rte_Pim_StrtUpSelfTestCmpl(void)
{
  return Rte_Pim_StrtUpSelfTestCmpl();
}



