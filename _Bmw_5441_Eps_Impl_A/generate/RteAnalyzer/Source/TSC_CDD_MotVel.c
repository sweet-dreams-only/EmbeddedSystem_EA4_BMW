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
 *          File:  TSC_CDD_MotVel.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_CDD_MotVel.h"
#include "TSC_CDD_MotVel.h"















     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_CDD_MotVel_Rte_Read_AssiMechPolarity_Val(sint8 *data)
{
  return Rte_Read_AssiMechPolarity_Val(data);
}

Std_ReturnType TSC_CDD_MotVel_Rte_Read_MotAgBuf_Ary1D(u0p16 *data)
{
  return Rte_Read_MotAgBuf_Ary1D(data);
}

Std_ReturnType TSC_CDD_MotVel_Rte_Read_MotAgBufIdx_Val(uint8 *data)
{
  return Rte_Read_MotAgBufIdx_Val(data);
}

Std_ReturnType TSC_CDD_MotVel_Rte_Read_MotAgMeclIdptSig_Val(uint8 *data)
{
  return Rte_Read_MotAgMeclIdptSig_Val(data);
}

Std_ReturnType TSC_CDD_MotVel_Rte_Read_MotAgTiBuf_Ary1D(uint32 *data)
{
  return Rte_Read_MotAgTiBuf_Ary1D(data);
}




Std_ReturnType TSC_CDD_MotVel_Rte_Write_MotVelCrf_Val(float32 data)
{
  return Rte_Write_MotVelCrf_Val(data);
}

Std_ReturnType TSC_CDD_MotVel_Rte_Write_MotVelMrf_Val(float32 data)
{
  return Rte_Write_MotVelMrf_Val(data);
}

Std_ReturnType TSC_CDD_MotVel_Rte_Write_MotVelVld_Logl(boolean data)
{
  return Rte_Write_MotVelVld_Logl(data);
}





     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */







     /* CDD_MotVel */
      /* CDD_MotVel */

/** Per Instance Memories */
float32 *TSC_CDD_MotVel_Rte_Pim_dMotVelAvrgTi(void)
{
  return Rte_Pim_dMotVelAvrgTi();
}
float32 *TSC_CDD_MotVel_Rte_Pim_dMotVelTiStampRef(void)
{
  return Rte_Pim_dMotVelTiStampRef();
}
u0p16 *TSC_CDD_MotVel_Rte_Pim_dMotVelMotAgRef(void)
{
  return Rte_Pim_dMotVelMotAgRef();
}
uint8 *TSC_CDD_MotVel_Rte_Pim_MotAgBufIdxPrev(void)
{
  return Rte_Pim_MotAgBufIdxPrev();
}
uint8 *TSC_CDD_MotVel_Rte_Pim_MotAgBufIdxPrim(void)
{
  return Rte_Pim_MotAgBufIdxPrim();
}
uint8 *TSC_CDD_MotVel_Rte_Pim_MotVelIninCntr(void)
{
  return Rte_Pim_MotVelIninCntr();
}
u0p16 *TSC_CDD_MotVel_Rte_Pim_MotAgBufPrev(void)
{
  return Rte_Pim_MotAgBufPrev();
}
uint32 *TSC_CDD_MotVel_Rte_Pim_MotAgTiBufPrev(void)
{
  return Rte_Pim_MotAgTiBufPrev();
}



