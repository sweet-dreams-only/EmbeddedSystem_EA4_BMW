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
 *          File:  TSC_ClsdLoopDampg.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_ClsdLoopDampg.h"
#include "TSC_ClsdLoopDampg.h"















     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_ClsdLoopDampg_Rte_Read_DampgCmdSca_Val(float32 *data)
{
  return Rte_Read_DampgCmdSca_Val(data);
}

Std_ReturnType TSC_ClsdLoopDampg_Rte_Read_EotCtrlSca_Val(float32 *data)
{
  return Rte_Read_EotCtrlSca_Val(data);
}

Std_ReturnType TSC_ClsdLoopDampg_Rte_Read_EotDeltaAg_Val(float32 *data)
{
  return Rte_Read_EotDeltaAg_Val(data);
}

Std_ReturnType TSC_ClsdLoopDampg_Rte_Read_EotSt_Val(EotSt1 *data)
{
  return Rte_Read_EotSt_Val(data);
}

Std_ReturnType TSC_ClsdLoopDampg_Rte_Read_PinionVel_Val(float32 *data)
{
  return Rte_Read_PinionVel_Val(data);
}

Std_ReturnType TSC_ClsdLoopDampg_Rte_Read_RackFEstimd_Val(float32 *data)
{
  return Rte_Read_RackFEstimd_Val(data);
}

Std_ReturnType TSC_ClsdLoopDampg_Rte_Read_VehSpd_Val(float32 *data)
{
  return Rte_Read_VehSpd_Val(data);
}




Std_ReturnType TSC_ClsdLoopDampg_Rte_Write_HwTqCmdDampg_Val(float32 data)
{
  return Rte_Write_HwTqCmdDampg_Val(data);
}





     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */





Ary1D_u10p6_4 * TSC_ClsdLoopDampg_Rte_Prm_ClsdLoopDampgEotEntrX_Ary1D(void)
{
  return (Ary1D_u10p6_4 *) Rte_Prm_ClsdLoopDampgEotEntrX_Ary1D();
}
Ary1D_u1p15_4 * TSC_ClsdLoopDampg_Rte_Prm_ClsdLoopDampgEotEntrY_Ary1D(void)
{
  return (Ary1D_u1p15_4 *) Rte_Prm_ClsdLoopDampgEotEntrY_Ary1D();
}
Ary1D_u10p6_4 * TSC_ClsdLoopDampg_Rte_Prm_ClsdLoopDampgEotExitX_Ary1D(void)
{
  return (Ary1D_u10p6_4 *) Rte_Prm_ClsdLoopDampgEotExitX_Ary1D();
}
Ary1D_u1p15_4 * TSC_ClsdLoopDampg_Rte_Prm_ClsdLoopDampgEotExitY_Ary1D(void)
{
  return (Ary1D_u1p15_4 *) Rte_Prm_ClsdLoopDampgEotExitY_Ary1D();
}
Ary2D_u6p10_12_9 * TSC_ClsdLoopDampg_Rte_Prm_ClsdLoopDampgPinionVelX_Ary2D(void)
{
  return (Ary2D_u6p10_12_9 *) Rte_Prm_ClsdLoopDampgPinionVelX_Ary2D();
}
Ary2D_u4p12_12_9 * TSC_ClsdLoopDampg_Rte_Prm_ClsdLoopDampgPinionVelY_Ary2D(void)
{
  return (Ary2D_u4p12_12_9 *) Rte_Prm_ClsdLoopDampgPinionVelY_Ary2D();
}
Ary2D_u15p1_12_9 * TSC_ClsdLoopDampg_Rte_Prm_ClsdLoopDampgRackFX_Ary2D(void)
{
  return (Ary2D_u15p1_12_9 *) Rte_Prm_ClsdLoopDampgRackFX_Ary2D();
}
Ary2D_u1p15_12_9 * TSC_ClsdLoopDampg_Rte_Prm_ClsdLoopDampgRackFY_Ary2D(void)
{
  return (Ary2D_u1p15_12_9 *) Rte_Prm_ClsdLoopDampgRackFY_Ary2D();
}
Ary1D_u9p7_12 * TSC_ClsdLoopDampg_Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D(void)
{
  return (Ary1D_u9p7_12 *) Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D();
}


     /* ClsdLoopDampg */
      /* ClsdLoopDampg */



