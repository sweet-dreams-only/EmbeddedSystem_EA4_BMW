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
 *          File:  TSC_CDD_Bmw5441McuCfg.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_CDD_Bmw5441McuCfg.h"
#include "TSC_CDD_Bmw5441McuCfg.h"















     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */
Std_ReturnType TSC_CDD_Bmw5441McuCfg_Rte_Call_GetRefTmr1MicroSec32bit_Oper(uint32 *RefTmr_Arg)
{
  return Rte_Call_GetRefTmr1MicroSec32bit_Oper(RefTmr_Arg);
}
Std_ReturnType TSC_CDD_Bmw5441McuCfg_Rte_Call_GetTiSpan1MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg)
{
  return Rte_Call_GetTiSpan1MicroSec32bit_Oper(RefTmr_Arg, TiSpan_Arg);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */









Std_ReturnType TSC_CDD_Bmw5441McuCfg_Rte_Write_Adc1ScanGroup2Ref0_Val(float32 data)
{
  return Rte_Write_Adc1ScanGroup2Ref0_Val(data);
}

Std_ReturnType TSC_CDD_Bmw5441McuCfg_Rte_Write_Adc1ScanGroup2Ref1_Val(float32 data)
{
  return Rte_Write_Adc1ScanGroup2Ref1_Val(data);
}

Std_ReturnType TSC_CDD_Bmw5441McuCfg_Rte_Write_Adc1ScanGroup3Ref0_Val(float32 data)
{
  return Rte_Write_Adc1ScanGroup3Ref0_Val(data);
}

Std_ReturnType TSC_CDD_Bmw5441McuCfg_Rte_Write_Adc1ScanGroup3Ref1_Val(float32 data)
{
  return Rte_Write_Adc1ScanGroup3Ref1_Val(data);
}

Std_ReturnType TSC_CDD_Bmw5441McuCfg_Rte_Write_Adc1SelfDiag0_Val(float32 data)
{
  return Rte_Write_Adc1SelfDiag0_Val(data);
}

Std_ReturnType TSC_CDD_Bmw5441McuCfg_Rte_Write_Adc1SelfDiag2_Val(float32 data)
{
  return Rte_Write_Adc1SelfDiag2_Val(data);
}

Std_ReturnType TSC_CDD_Bmw5441McuCfg_Rte_Write_Adc1SelfDiag4_Val(float32 data)
{
  return Rte_Write_Adc1SelfDiag4_Val(data);
}

Std_ReturnType TSC_CDD_Bmw5441McuCfg_Rte_Write_BattVltg_Val(float32 data)
{
  return Rte_Write_BattVltg_Val(data);
}

Std_ReturnType TSC_CDD_Bmw5441McuCfg_Rte_Write_BattVltgSwd1_Val(float32 data)
{
  return Rte_Write_BattVltgSwd1_Val(data);
}

Std_ReturnType TSC_CDD_Bmw5441McuCfg_Rte_Write_EcuT_Val(float32 data)
{
  return Rte_Write_EcuT_Val(data);
}

Std_ReturnType TSC_CDD_Bmw5441McuCfg_Rte_Write_RvsBattDiagcGndAdc_Val(float32 data)
{
  return Rte_Write_RvsBattDiagcGndAdc_Val(data);
}

Std_ReturnType TSC_CDD_Bmw5441McuCfg_Rte_Write_RvsBattDiagcRtnAdc_Val(float32 data)
{
  return Rte_Write_RvsBattDiagcRtnAdc_Val(data);
}





     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_CDD_Bmw5441McuCfg_Rte_Read_Adc0Faild_Logl(boolean *data)
{
  return Rte_Read_Adc0Faild_Logl(data);
}

Std_ReturnType TSC_CDD_Bmw5441McuCfg_Rte_Read_Adc1Faild_Logl(boolean *data)
{
  return Rte_Read_Adc1Faild_Logl(data);
}




Std_ReturnType TSC_CDD_Bmw5441McuCfg_Rte_Write_BattRtnCurrAdcFaild_Logl(boolean data)
{
  return Rte_Write_BattRtnCurrAdcFaild_Logl(data);
}

Std_ReturnType TSC_CDD_Bmw5441McuCfg_Rte_Write_BattVltgAdcFaild_Logl(boolean data)
{
  return Rte_Write_BattVltgAdcFaild_Logl(data);
}

Std_ReturnType TSC_CDD_Bmw5441McuCfg_Rte_Write_BattVltgSwd1AdcFaild_Logl(boolean data)
{
  return Rte_Write_BattVltgSwd1AdcFaild_Logl(data);
}

Std_ReturnType TSC_CDD_Bmw5441McuCfg_Rte_Write_EcuTAdcFaild_Logl(boolean data)
{
  return Rte_Write_EcuTAdcFaild_Logl(data);
}

Std_ReturnType TSC_CDD_Bmw5441McuCfg_Rte_Write_HwTq4RawAdcAdcFaild_Logl(boolean data)
{
  return Rte_Write_HwTq4RawAdcAdcFaild_Logl(data);
}

Std_ReturnType TSC_CDD_Bmw5441McuCfg_Rte_Write_HwTq5RawAdcAdcFaild_Logl(boolean data)
{
  return Rte_Write_HwTq5RawAdcAdcFaild_Logl(data);
}

Std_ReturnType TSC_CDD_Bmw5441McuCfg_Rte_Write_MotCurrAdcVlyAAdcFaild_Logl(boolean data)
{
  return Rte_Write_MotCurrAdcVlyAAdcFaild_Logl(data);
}

Std_ReturnType TSC_CDD_Bmw5441McuCfg_Rte_Write_MotCurrAdcVlyBAdcFaild_Logl(boolean data)
{
  return Rte_Write_MotCurrAdcVlyBAdcFaild_Logl(data);
}

Std_ReturnType TSC_CDD_Bmw5441McuCfg_Rte_Write_MotCurrAdcVlyCAdcFaild_Logl(boolean data)
{
  return Rte_Write_MotCurrAdcVlyCAdcFaild_Logl(data);
}

Std_ReturnType TSC_CDD_Bmw5441McuCfg_Rte_Write_MotDrvr1IninTestCmpl_Logl(boolean data)
{
  return Rte_Write_MotDrvr1IninTestCmpl_Logl(data);
}

Std_ReturnType TSC_CDD_Bmw5441McuCfg_Rte_Write_RvsBattDiagcGndAdcFaild_Logl(boolean data)
{
  return Rte_Write_RvsBattDiagcGndAdcFaild_Logl(data);
}

Std_ReturnType TSC_CDD_Bmw5441McuCfg_Rte_Write_RvsBattDiagcRtnAdcFaild_Logl(boolean data)
{
  return Rte_Write_RvsBattDiagcRtnAdcFaild_Logl(data);
}





     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */







     /* CDD_Bmw5441McuCfg */
      /* CDD_Bmw5441McuCfg */



