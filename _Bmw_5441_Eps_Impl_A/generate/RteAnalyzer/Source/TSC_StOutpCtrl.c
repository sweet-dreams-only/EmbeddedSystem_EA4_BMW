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
 *          File:  TSC_StOutpCtrl.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_StOutpCtrl.h"
#include "TSC_StOutpCtrl.h"















     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_StOutpCtrl_Rte_Read_DiagcStsCtrldShtDwnFltPrsnt_Logl(boolean *data)
{
  return Rte_Read_DiagcStsCtrldShtDwnFltPrsnt_Logl(data);
}

Std_ReturnType TSC_StOutpCtrl_Rte_Read_LoaRateLim_Val(float32 *data)
{
  return Rte_Read_LoaRateLim_Val(data);
}

Std_ReturnType TSC_StOutpCtrl_Rte_Read_LoaSca_Val(float32 *data)
{
  return Rte_Read_LoaSca_Val(data);
}

Std_ReturnType TSC_StOutpCtrl_Rte_Read_MotTqTranlDampgCmpl_Logl(boolean *data)
{
  return Rte_Read_MotTqTranlDampgCmpl_Logl(data);
}

Std_ReturnType TSC_StOutpCtrl_Rte_Read_SysDiMotTqCmdSca_Val(float32 *data)
{
  return Rte_Read_SysDiMotTqCmdSca_Val(data);
}

Std_ReturnType TSC_StOutpCtrl_Rte_Read_SysDiRampRate_Val(float32 *data)
{
  return Rte_Read_SysDiRampRate_Val(data);
}

Std_ReturnType TSC_StOutpCtrl_Rte_Read_SysMotTqCmdRampRateDi_Logl(boolean *data)
{
  return Rte_Read_SysMotTqCmdRampRateDi_Logl(data);
}

Std_ReturnType TSC_StOutpCtrl_Rte_Read_SysOperMotTqCmdSca_Val(float32 *data)
{
  return Rte_Read_SysOperMotTqCmdSca_Val(data);
}

Std_ReturnType TSC_StOutpCtrl_Rte_Read_SysOperRampRate_Val(float32 *data)
{
  return Rte_Read_SysOperRampRate_Val(data);
}

Std_ReturnType TSC_StOutpCtrl_Rte_Read_SysStFltOutpReqDi_Logl(boolean *data)
{
  return Rte_Read_SysStFltOutpReqDi_Logl(data);
}

Std_ReturnType TSC_StOutpCtrl_Rte_Read_VehStrtStopMotTqCmdSca_Val(float32 *data)
{
  return Rte_Read_VehStrtStopMotTqCmdSca_Val(data);
}

Std_ReturnType TSC_StOutpCtrl_Rte_Read_VehStrtStopRampRate_Val(float32 *data)
{
  return Rte_Read_VehStrtStopRampRate_Val(data);
}




Std_ReturnType TSC_StOutpCtrl_Rte_Write_SysMotTqCmdSca_Val(float32 data)
{
  return Rte_Write_SysMotTqCmdSca_Val(data);
}

Std_ReturnType TSC_StOutpCtrl_Rte_Write_SysStReqDi_Logl(boolean data)
{
  return Rte_Write_SysStReqDi_Logl(data);
}





     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */







     /* StOutpCtrl */
      /* StOutpCtrl */

/** Per Instance Memories */
float32 *TSC_StOutpCtrl_Rte_Pim_StOutpCtrlPrevCmdSca(void)
{
  return Rte_Pim_StOutpCtrlPrevCmdSca();
}
float32 *TSC_StOutpCtrl_Rte_Pim_dStOutpCtrlRateLim(void)
{
  return Rte_Pim_dStOutpCtrlRateLim();
}
float32 *TSC_StOutpCtrl_Rte_Pim_dStOutpCtrlTarSca(void)
{
  return Rte_Pim_dStOutpCtrlTarSca();
}
uint8 *TSC_StOutpCtrl_Rte_Pim_StOutpCtrlPrevSrc(void)
{
  return Rte_Pim_StOutpCtrlPrevSrc();
}



