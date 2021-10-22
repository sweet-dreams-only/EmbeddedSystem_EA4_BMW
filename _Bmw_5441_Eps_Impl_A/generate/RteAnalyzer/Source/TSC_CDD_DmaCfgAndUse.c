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
 *          File:  TSC_CDD_DmaCfgAndUse.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_CDD_DmaCfgAndUse.h"
#include "TSC_CDD_DmaCfgAndUse.h"








Std_ReturnType TSC_CDD_DmaCfgAndUse_Rte_Read_MotAg0SnsrCfgAdr_Val(uint32 *data)
{
  return Rte_Read_MotAg0SnsrCfgAdr_Val(data);
}








     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */
Std_ReturnType TSC_CDD_DmaCfgAndUse_Rte_Call_Adc1CfgAndUseAdc1EnaCnvn_Oper(void)
{
  return Rte_Call_Adc1CfgAndUseAdc1EnaCnvn_Oper();
}
Std_ReturnType TSC_CDD_DmaCfgAndUse_Rte_Call_GetRefTmr1MicroSec32bit_Oper(uint32 *RefTmr_Arg)
{
  return Rte_Call_GetRefTmr1MicroSec32bit_Oper(RefTmr_Arg);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */
Std_ReturnType TSC_CDD_DmaCfgAndUse_Rte_Call_ReadErrInjReg_Oper(uint32 *ErrId_Arg)
{
  return Rte_Call_ReadErrInjReg_Oper(ErrId_Arg);
}
Std_ReturnType TSC_CDD_DmaCfgAndUse_Rte_Call_StrtErrInjCntr_Oper(void)
{
  return Rte_Call_StrtErrInjCntr_Oper();
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */
Std_ReturnType TSC_CDD_DmaCfgAndUse_Rte_Call_GetTiSpan1MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg)
{
  return Rte_Call_GetTiSpan1MicroSec32bit_Oper(RefTmr_Arg, TiSpan_Arg);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */







     /* CDD_DmaCfgAndUse */
      /* CDD_DmaCfgAndUse */

/** Per Instance Memories */
uint32 *TSC_CDD_DmaCfgAndUse_Rte_Pim_DmaCfgAndUse2MilliSecAdcMaxDmaTrfTi(void)
{
  return Rte_Pim_DmaCfgAndUse2MilliSecAdcMaxDmaTrfTi();
}
uint32 *TSC_CDD_DmaCfgAndUse_Rte_Pim_DmaCfgAndUse2MilliSecAdcStrtTi(void)
{
  return Rte_Pim_DmaCfgAndUse2MilliSecAdcStrtTi();
}
uint32 *TSC_CDD_DmaCfgAndUse_Rte_Pim_MotAg0ReadPtrRst(void)
{
  return Rte_Pim_MotAg0ReadPtrRst();
}
uint32 *TSC_CDD_DmaCfgAndUse_Rte_Pim_MotAg0SnsrCfgAdrStord(void)
{
  return Rte_Pim_MotAg0SnsrCfgAdrStord();
}
uint32 *TSC_CDD_DmaCfgAndUse_Rte_Pim_MotAg0TrsmStrt(void)
{
  return Rte_Pim_MotAg0TrsmStrt();
}
uint32 *TSC_CDD_DmaCfgAndUse_Rte_Pim_MotAg1ReadPtrRst(void)
{
  return Rte_Pim_MotAg1ReadPtrRst();
}
uint32 *TSC_CDD_DmaCfgAndUse_Rte_Pim_MotAg1SnsrCfgAdrStord(void)
{
  return Rte_Pim_MotAg1SnsrCfgAdrStord();
}
uint32 *TSC_CDD_DmaCfgAndUse_Rte_Pim_MotAg1TrsmStrt(void)
{
  return Rte_Pim_MotAg1TrsmStrt();
}
uint32 *TSC_CDD_DmaCfgAndUse_Rte_Pim_d2MilliSecAdcActDmaTrfTi(void)
{
  return Rte_Pim_d2MilliSecAdcActDmaTrfTi();
}



