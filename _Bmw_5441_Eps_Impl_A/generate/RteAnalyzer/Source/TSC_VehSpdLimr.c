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
 *          File:  TSC_VehSpdLimr.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_VehSpdLimr.h"
#include "TSC_VehSpdLimr.h"








Std_ReturnType TSC_VehSpdLimr_Rte_Read_HwAg_Val(float32 *data)
{
  return Rte_Read_HwAg_Val(data);
}

Std_ReturnType TSC_VehSpdLimr_Rte_Read_HwAgAuthy_Val(float32 *data)
{
  return Rte_Read_HwAgAuthy_Val(data);
}

Std_ReturnType TSC_VehSpdLimr_Rte_Read_HwAgEotCcw_Val(float32 *data)
{
  return Rte_Read_HwAgEotCcw_Val(data);
}

Std_ReturnType TSC_VehSpdLimr_Rte_Read_HwAgEotCw_Val(float32 *data)
{
  return Rte_Read_HwAgEotCw_Val(data);
}

Std_ReturnType TSC_VehSpdLimr_Rte_Read_VehSpd_Val(float32 *data)
{
  return Rte_Read_VehSpd_Val(data);
}




Std_ReturnType TSC_VehSpdLimr_Rte_Write_VehSpdMotTqLim_Val(float32 data)
{
  return Rte_Write_VehSpdMotTqLim_Val(data);
}





     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */





float32  TSC_VehSpdLimr_Rte_Prm_VehSpdLimrPosMaxOffs1_Val(void)
{
  return (float32 ) Rte_Prm_VehSpdLimrPosMaxOffs1_Val();
}
float32  TSC_VehSpdLimr_Rte_Prm_VehSpdLimrPosMaxOffs2_Val(void)
{
  return (float32 ) Rte_Prm_VehSpdLimrPosMaxOffs2_Val();
}
Ary1D_u9p7_5 * TSC_VehSpdLimr_Rte_Prm_VehSpdLimrMaxAssiX_Ary1D(void)
{
  return (Ary1D_u9p7_5 *) Rte_Prm_VehSpdLimrMaxAssiX_Ary1D();
}
Ary1D_u5p11_5 * TSC_VehSpdLimr_Rte_Prm_VehSpdLimrMaxAssiY_Ary1D(void)
{
  return (Ary1D_u5p11_5 *) Rte_Prm_VehSpdLimrMaxAssiY_Ary1D();
}


     /* VehSpdLimr */
      /* VehSpdLimr */

/** Per Instance Memories */
float32 *TSC_VehSpdLimr_Rte_Pim_dVehSpdLimrBreakPt1(void)
{
  return Rte_Pim_dVehSpdLimrBreakPt1();
}
float32 *TSC_VehSpdLimr_Rte_Pim_dVehSpdLimrBreakPt2(void)
{
  return Rte_Pim_dVehSpdLimrBreakPt2();
}
u5p11 *TSC_VehSpdLimr_Rte_Pim_dVehSpdLimrLimTerm(void)
{
  return Rte_Pim_dVehSpdLimrLimTerm();
}
u5p11 *TSC_VehSpdLimr_Rte_Pim_dVehSpdLimrZeroVehSpd(void)
{
  return Rte_Pim_dVehSpdLimrZeroVehSpd();
}



