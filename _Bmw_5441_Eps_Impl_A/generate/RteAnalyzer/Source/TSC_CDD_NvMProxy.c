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
 *          File:  TSC_CDD_NvMProxy.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_CDD_NvMProxy.h"
#include "TSC_CDD_NvMProxy.h"















     /* Client Server Interfaces: */
Std_ReturnType TSC_CDD_NvMProxy_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
{
  return Rte_Call_SetNtcSts_Oper(NtcNr_Arg, NtcStInfo_Arg, NtcSts_Arg, DebStep_Arg);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */







     /* CDD_NvMProxy */
      /* CDD_NvMProxy */

/** Per Instance Memories */
uint32 *TSC_CDD_NvMProxy_Rte_Pim_ShtdwnClsChk(void)
{
  return Rte_Pim_ShtdwnClsChk();
}
boolean *TSC_CDD_NvMProxy_Rte_Pim_NvmStsCollctd(void)
{
  return Rte_Pim_NvmStsCollctd();
}
BlkFltTblRec1 *TSC_CDD_NvMProxy_Rte_Pim_BlkFltTbl(void)
{
  return Rte_Pim_BlkFltTbl();
}
CmdRtnBufRec1 *TSC_CDD_NvMProxy_Rte_Pim_CmdRtnBuf(void)
{
  return Rte_Pim_CmdRtnBuf();
}
boolean *TSC_CDD_NvMProxy_Rte_Pim_NvmBlkActv(void)
{
  return Rte_Pim_NvmBlkActv();
}



