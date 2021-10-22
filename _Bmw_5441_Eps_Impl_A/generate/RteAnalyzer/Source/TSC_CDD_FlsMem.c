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
 *          File:  TSC_CDD_FlsMem.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_CDD_FlsMem.h"
#include "TSC_CDD_FlsMem.h"











Std_ReturnType TSC_CDD_FlsMem_Rte_Write_SwApplCrc_Val(uint32 data)
{
  return Rte_Write_SwApplCrc_Val(data);
}





     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */









Std_ReturnType TSC_CDD_FlsMem_Rte_Write_CodFlsCrcChkCmpl_Logl(boolean data)
{
  return Rte_Write_CodFlsCrcChkCmpl_Logl(data);
}





     /* Client Server Interfaces: */
Std_ReturnType TSC_CDD_FlsMem_Rte_Call_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg)
{
  return Rte_Call_GetTiSpan100MicroSec32bit_Oper(RefTmr_Arg, TiSpan_Arg);
}
Std_ReturnType TSC_CDD_FlsMem_Rte_Call_ResvCrcHwUnit_Oper(CrcHwResvMod1 Mod_Arg, CrcHwResvCfg1 CrcCfg_Arg, uint32 *CrcHwInRegAdr_Arg, uint32 *CrcHwOutRegAdr_Arg, uint32 StrtVal_Arg, uint32 *ResvKey_Arg)
{
  return Rte_Call_ResvCrcHwUnit_Oper(Mod_Arg, CrcCfg_Arg, CrcHwInRegAdr_Arg, CrcHwOutRegAdr_Arg, StrtVal_Arg, ResvKey_Arg);
}
Std_ReturnType TSC_CDD_FlsMem_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
{
  return Rte_Call_SetNtcSts_Oper(NtcNr_Arg, NtcStInfo_Arg, NtcSts_Arg, DebStep_Arg);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */







     /* CDD_FlsMem */
      /* CDD_FlsMem */

/** Per Instance Memories */
uint32 *TSC_CDD_FlsMem_Rte_Pim_CodFlsCrcChkStrtTi(void)
{
  return Rte_Pim_CodFlsCrcChkStrtTi();
}
uint32 *TSC_CDD_FlsMem_Rte_Pim_CodFlsDummyRead1(void)
{
  return Rte_Pim_CodFlsDummyRead1();
}
uint32 *TSC_CDD_FlsMem_Rte_Pim_CodFlsDummyRead2(void)
{
  return Rte_Pim_CodFlsDummyRead2();
}
uint32 *TSC_CDD_FlsMem_Rte_Pim_CodFlsDummyRead3(void)
{
  return Rte_Pim_CodFlsDummyRead3();
}
uint32 *TSC_CDD_FlsMem_Rte_Pim_CodFlsDummyRead4(void)
{
  return Rte_Pim_CodFlsDummyRead4();
}
uint32 *TSC_CDD_FlsMem_Rte_Pim_CrcHwIdxKey(void)
{
  return Rte_Pim_CrcHwIdxKey();
}
boolean *TSC_CDD_FlsMem_Rte_Pim_CodFlsSngBitErr(void)
{
  return Rte_Pim_CodFlsSngBitErr();
}
boolean *TSC_CDD_FlsMem_Rte_Pim_CrcChkCmpl(void)
{
  return Rte_Pim_CrcChkCmpl();
}
boolean *TSC_CDD_FlsMem_Rte_Pim_PwrOnRstCrcChkCmpl(void)
{
  return Rte_Pim_PwrOnRstCrcChkCmpl();
}



