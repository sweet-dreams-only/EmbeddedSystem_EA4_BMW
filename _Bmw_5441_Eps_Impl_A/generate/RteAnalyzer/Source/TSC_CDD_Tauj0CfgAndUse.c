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
 *          File:  TSC_CDD_Tauj0CfgAndUse.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_CDD_Tauj0CfgAndUse.h"
#include "TSC_CDD_Tauj0CfgAndUse.h"















     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */









Std_ReturnType TSC_CDD_Tauj0CfgAndUse_Rte_Write_PhaOnTiMeasdA_Val(uint32 data)
{
  return Rte_Write_PhaOnTiMeasdA_Val(data);
}

Std_ReturnType TSC_CDD_Tauj0CfgAndUse_Rte_Write_PhaOnTiMeasdB_Val(uint32 data)
{
  return Rte_Write_PhaOnTiMeasdB_Val(data);
}

Std_ReturnType TSC_CDD_Tauj0CfgAndUse_Rte_Write_PhaOnTiMeasdC_Val(uint32 data)
{
  return Rte_Write_PhaOnTiMeasdC_Val(data);
}





     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */







     /* CDD_Tauj0CfgAndUse */
      /* CDD_Tauj0CfgAndUse */

/** Per Instance Memories */
uint32 *TSC_CDD_Tauj0CfgAndUse_Rte_Pim_PhaOnTiCntrAPrev(void)
{
  return Rte_Pim_PhaOnTiCntrAPrev();
}
uint32 *TSC_CDD_Tauj0CfgAndUse_Rte_Pim_PhaOnTiCntrBPrev(void)
{
  return Rte_Pim_PhaOnTiCntrBPrev();
}
uint32 *TSC_CDD_Tauj0CfgAndUse_Rte_Pim_PhaOnTiCntrCPrev(void)
{
  return Rte_Pim_PhaOnTiCntrCPrev();
}



