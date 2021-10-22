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
 *          File:  TSC_EpsStEstimn.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_EpsStEstimn.h"
#include "TSC_EpsStEstimn.h"















     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_EpsStEstimn_Rte_Read_HwTq_Val(float32 *data)
{
  return Rte_Read_HwTq_Val(data);
}

Std_ReturnType TSC_EpsStEstimn_Rte_Read_MotTqEstimd_Val(float32 *data)
{
  return Rte_Read_MotTqEstimd_Val(data);
}

Std_ReturnType TSC_EpsStEstimn_Rte_Read_MotVelCrf_Val(float32 *data)
{
  return Rte_Read_MotVelCrf_Val(data);
}

Std_ReturnType TSC_EpsStEstimn_Rte_Read_PinionTqToRackFInstsRat_Val(float32 *data)
{
  return Rte_Read_PinionTqToRackFInstsRat_Val(data);
}

Std_ReturnType TSC_EpsStEstimn_Rte_Read_SysKineRat_Val(float32 *data)
{
  return Rte_Read_SysKineRat_Val(data);
}

Std_ReturnType TSC_EpsStEstimn_Rte_Read_SysTqRat_Val(float32 *data)
{
  return Rte_Read_SysTqRat_Val(data);
}




Std_ReturnType TSC_EpsStEstimn_Rte_Write_RackFEstimd_Val(float32 data)
{
  return Rte_Write_RackFEstimd_Val(data);
}

Std_ReturnType TSC_EpsStEstimn_Rte_Write_TorsBarStEstimd_Rec(const TorsBarStEstimdRec1 *data)
{
  return Rte_Write_TorsBarStEstimd_Rec(data);
}





     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */





Ary2D_f32_5_5 * TSC_EpsStEstimn_Rte_Prm_EpsStEstimnMtrxA_Ary2D(void)
{
  return (Ary2D_f32_5_5 *) Rte_Prm_EpsStEstimnMtrxA_Ary2D();
}
Ary2D_f32_5_3 * TSC_EpsStEstimn_Rte_Prm_EpsStEstimnMtrxB_Ary2D(void)
{
  return (Ary2D_f32_5_3 *) Rte_Prm_EpsStEstimnMtrxB_Ary2D();
}
Ary2D_f32_5_5 * TSC_EpsStEstimn_Rte_Prm_EpsStEstimnMtrxC_Ary2D(void)
{
  return (Ary2D_f32_5_5 *) Rte_Prm_EpsStEstimnMtrxC_Ary2D();
}
Ary2D_f32_5_3 * TSC_EpsStEstimn_Rte_Prm_EpsStEstimnMtrxD_Ary2D(void)
{
  return (Ary2D_f32_5_3 *) Rte_Prm_EpsStEstimnMtrxD_Ary2D();
}


     /* EpsStEstimn */
      /* EpsStEstimn */

/** Per Instance Memories */
float32 *TSC_EpsStEstimn_Rte_Pim_StEstimrStPrev(void)
{
  return Rte_Pim_StEstimrStPrev();
}



