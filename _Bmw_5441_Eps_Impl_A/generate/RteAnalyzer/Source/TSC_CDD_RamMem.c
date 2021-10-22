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
 *          File:  TSC_CDD_RamMem.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_CDD_RamMem.h"
#include "TSC_CDD_RamMem.h"















     /* Client Server Interfaces: */
Std_ReturnType TSC_CDD_RamMem_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
{
  return Rte_Call_SetNtcSts_Oper(NtcNr_Arg, NtcStInfo_Arg, NtcSts_Arg, DebStep_Arg);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */









Std_ReturnType TSC_CDD_RamMem_Rte_Write_LclRamEccSngBitCntrOutp_Val(uint8 data)
{
  return Rte_Write_LclRamEccSngBitCntrOutp_Val(data);
}





     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */







     /* CDD_RamMem */
      /* CDD_RamMem */

/** Per Instance Memories */
uint32 *TSC_CDD_RamMem_Rte_Pim_LclRamFailrAdr(void)
{
  return Rte_Pim_LclRamFailrAdr();
}
uint32 *TSC_CDD_RamMem_Rte_Pim_LclRamWordLineRead(void)
{
  return Rte_Pim_LclRamWordLineRead();
}
uint32 *TSC_CDD_RamMem_Rte_Pim_dRamMemCanRamDblBitEccErrAdr(void)
{
  return Rte_Pim_dRamMemCanRamDblBitEccErrAdr();
}
uint32 *TSC_CDD_RamMem_Rte_Pim_dRamMemCanRamSngBitEccErrAdr(void)
{
  return Rte_Pim_dRamMemCanRamSngBitEccErrAdr();
}
uint32 *TSC_CDD_RamMem_Rte_Pim_dRamMemFrRamDblBitEccErrAdr(void)
{
  return Rte_Pim_dRamMemFrRamDblBitEccErrAdr();
}
uint32 *TSC_CDD_RamMem_Rte_Pim_dRamMemFrRamSngBitEccErrAdr(void)
{
  return Rte_Pim_dRamMemFrRamSngBitEccErrAdr();
}
uint32 *TSC_CDD_RamMem_Rte_Pim_dRamMemFrRamTmpBufADblBitEccErrAdr(void)
{
  return Rte_Pim_dRamMemFrRamTmpBufADblBitEccErrAdr();
}
uint32 *TSC_CDD_RamMem_Rte_Pim_dRamMemFrRamTmpBufBDblBitEccErrAdr(void)
{
  return Rte_Pim_dRamMemFrRamTmpBufBDblBitEccErrAdr();
}
uint32 *TSC_CDD_RamMem_Rte_Pim_dRamMemSpi0RamEccErrAdr(void)
{
  return Rte_Pim_dRamMemSpi0RamEccErrAdr();
}
uint32 *TSC_CDD_RamMem_Rte_Pim_dRamMemSpi1RamEccErrAdr(void)
{
  return Rte_Pim_dRamMemSpi1RamEccErrAdr();
}
uint32 *TSC_CDD_RamMem_Rte_Pim_dRamMemSpi2RamEccErrAdr(void)
{
  return Rte_Pim_dRamMemSpi2RamEccErrAdr();
}
uint32 *TSC_CDD_RamMem_Rte_Pim_dRamMemSpi3RamEccErrAdr(void)
{
  return Rte_Pim_dRamMemSpi3RamEccErrAdr();
}
uint32 *TSC_CDD_RamMem_Rte_Pim_dRamMemSpiRamEccErrAdr(void)
{
  return Rte_Pim_dRamMemSpiRamEccErrAdr();
}
uint8 *TSC_CDD_RamMem_Rte_Pim_LclRamEccSngBitCntr(void)
{
  return Rte_Pim_LclRamEccSngBitCntr();
}
boolean *TSC_CDD_RamMem_Rte_Pim_LclRamEccSngBitSoftFailr(void)
{
  return Rte_Pim_LclRamEccSngBitSoftFailr();
}



