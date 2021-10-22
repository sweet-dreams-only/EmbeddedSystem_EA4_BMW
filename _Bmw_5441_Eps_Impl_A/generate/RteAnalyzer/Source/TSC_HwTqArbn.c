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
 *          File:  TSC_HwTqArbn.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_HwTqArbn.h"
#include "TSC_HwTqArbn.h"















     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_HwTqArbn_Rte_Read_HwTqA_Val(float32 *data)
{
  return Rte_Read_HwTqA_Val(data);
}

Std_ReturnType TSC_HwTqArbn_Rte_Read_HwTqAQlfr_Val(SigQlfr1 *data)
{
  return Rte_Read_HwTqAQlfr_Val(data);
}

Std_ReturnType TSC_HwTqArbn_Rte_Read_HwTqARollgCntr_Val(uint8 *data)
{
  return Rte_Read_HwTqARollgCntr_Val(data);
}

Std_ReturnType TSC_HwTqArbn_Rte_Read_HwTqB_Val(float32 *data)
{
  return Rte_Read_HwTqB_Val(data);
}

Std_ReturnType TSC_HwTqArbn_Rte_Read_HwTqBQlfr_Val(SigQlfr1 *data)
{
  return Rte_Read_HwTqBQlfr_Val(data);
}

Std_ReturnType TSC_HwTqArbn_Rte_Read_HwTqBRollgCntr_Val(uint8 *data)
{
  return Rte_Read_HwTqBRollgCntr_Val(data);
}

Std_ReturnType TSC_HwTqArbn_Rte_Read_HwTqCorrlnSts_Val(uint8 *data)
{
  return Rte_Read_HwTqCorrlnSts_Val(data);
}




Std_ReturnType TSC_HwTqArbn_Rte_Write_HwTq_Val(float32 data)
{
  return Rte_Write_HwTq_Val(data);
}





     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */







     /* HwTqArbn */
      /* HwTqArbn */

/** Per Instance Memories */
float32 *TSC_HwTqArbn_Rte_Pim_HwTqPrevHwTq(void)
{
  return Rte_Pim_HwTqPrevHwTq();
}
uint8 *TSC_HwTqArbn_Rte_Pim_HwTqARollgCntrPrev(void)
{
  return Rte_Pim_HwTqARollgCntrPrev();
}
uint8 *TSC_HwTqArbn_Rte_Pim_HwTqAStallCntrPrev(void)
{
  return Rte_Pim_HwTqAStallCntrPrev();
}
uint8 *TSC_HwTqArbn_Rte_Pim_HwTqBRollgCntrPrev(void)
{
  return Rte_Pim_HwTqBRollgCntrPrev();
}
uint8 *TSC_HwTqArbn_Rte_Pim_HwTqBStallCntrPrev(void)
{
  return Rte_Pim_HwTqBStallCntrPrev();
}
boolean *TSC_HwTqArbn_Rte_Pim_dHwTqArbnChAAvl(void)
{
  return Rte_Pim_dHwTqArbnChAAvl();
}



