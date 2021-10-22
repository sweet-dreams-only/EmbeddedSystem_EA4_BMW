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
 *          File:  TSC_MotQuadDetn.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_MotQuadDetn.h"
#include "TSC_MotQuadDetn.h"















     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_MotQuadDetn_Rte_Read_MotAgCumvAlgndMrf_Val(s18p13 *data)
{
  return Rte_Read_MotAgCumvAlgndMrf_Val(data);
}

Std_ReturnType TSC_MotQuadDetn_Rte_Read_MotTqCmd_Val(float32 *data)
{
  return Rte_Read_MotTqCmd_Val(data);
}




Std_ReturnType TSC_MotQuadDetn_Rte_Write_MotDirInsts_Val(sint8 data)
{
  return Rte_Write_MotDirInsts_Val(data);
}

Std_ReturnType TSC_MotQuadDetn_Rte_Write_MotQuad_Val(MotQuad1 data)
{
  return Rte_Write_MotQuad_Val(data);
}





     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */





s18p13  TSC_MotQuadDetn_Rte_Prm_MotQuadDetnMotDirHysInsts_Val(void)
{
  return (s18p13 ) Rte_Prm_MotQuadDetnMotDirHysInsts_Val();
}


     /* MotQuadDetn */
      /* MotQuadDetn */

/** Per Instance Memories */
s18p13 *TSC_MotQuadDetn_Rte_Pim_MotAgCumvPrev(void)
{
  return Rte_Pim_MotAgCumvPrev();
}
s18p13 *TSC_MotQuadDetn_Rte_Pim_dMotQuadDetnMotAgCumvDelta(void)
{
  return Rte_Pim_dMotQuadDetnMotAgCumvDelta();
}
sint8 *TSC_MotQuadDetn_Rte_Pim_MotDirInstsPrev(void)
{
  return Rte_Pim_MotDirInstsPrev();
}
sint8 *TSC_MotQuadDetn_Rte_Pim_MotTqCmdSignPrev(void)
{
  return Rte_Pim_MotTqCmdSignPrev();
}
sint8 *TSC_MotQuadDetn_Rte_Pim_dMotQuadDetnTqCmdSign(void)
{
  return Rte_Pim_dMotQuadDetnTqCmdSign();
}



