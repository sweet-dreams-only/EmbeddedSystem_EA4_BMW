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
 *          File:  TSC_CDD_SinVltgGenn.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_CDD_SinVltgGenn.h"
#include "TSC_CDD_SinVltgGenn.h"








Std_ReturnType TSC_CDD_SinVltgGenn_Rte_Read_MotElecMeclPolarity_Val(sint8 *data)
{
  return Rte_Read_MotElecMeclPolarity_Val(data);
}








     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */





float32  TSC_CDD_SinVltgGenn_Rte_Prm_MotAgSwCalVehSpdThd_Val(void)
{
  return (float32 ) Rte_Prm_MotAgSwCalVehSpdThd_Val();
}
float32  TSC_CDD_SinVltgGenn_Rte_Prm_SinVltgGennDthrLpFilCoeff_Val(void)
{
  return (float32 ) Rte_Prm_SinVltgGennDthrLpFilCoeff_Val();
}
boolean  TSC_CDD_SinVltgGenn_Rte_Prm_SinVltgGennDthrEna_Logl(void)
{
  return (boolean ) Rte_Prm_SinVltgGennDthrEna_Logl();
}


     /* CDD_SinVltgGenn */
      /* CDD_SinVltgGenn */

/** Per Instance Memories */
float32 *TSC_CDD_SinVltgGenn_Rte_Pim_Fil1OutpPrev(void)
{
  return Rte_Pim_Fil1OutpPrev();
}
float32 *TSC_CDD_SinVltgGenn_Rte_Pim_Fil2OutpPrev(void)
{
  return Rte_Pim_Fil2OutpPrev();
}
float32 *TSC_CDD_SinVltgGenn_Rte_Pim_PhaDptOffsA(void)
{
  return Rte_Pim_PhaDptOffsA();
}
float32 *TSC_CDD_SinVltgGenn_Rte_Pim_PhaDptOffsB(void)
{
  return Rte_Pim_PhaDptOffsB();
}
float32 *TSC_CDD_SinVltgGenn_Rte_Pim_PhaDptOffsC(void)
{
  return Rte_Pim_PhaDptOffsC();
}
float32 *TSC_CDD_SinVltgGenn_Rte_Pim_RndNrPrev(void)
{
  return Rte_Pim_RndNrPrev();
}
uint32 *TSC_CDD_SinVltgGenn_Rte_Pim_PhaOnTiSumAPrev(void)
{
  return Rte_Pim_PhaOnTiSumAPrev();
}
uint32 *TSC_CDD_SinVltgGenn_Rte_Pim_PhaOnTiSumBPrev(void)
{
  return Rte_Pim_PhaOnTiSumBPrev();
}
uint32 *TSC_CDD_SinVltgGenn_Rte_Pim_PhaOnTiSumCPrev(void)
{
  return Rte_Pim_PhaOnTiSumCPrev();
}
uint32 *TSC_CDD_SinVltgGenn_Rte_Pim_PwmPerdRng(void)
{
  return Rte_Pim_PwmPerdRng();
}



