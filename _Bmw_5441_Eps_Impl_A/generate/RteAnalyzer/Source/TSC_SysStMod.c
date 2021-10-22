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
 *          File:  TSC_SysStMod.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_SysStMod.h"
#include "TSC_SysStMod.h"















     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_SysStMod_Rte_Read_PwrSplyEnaReq_Logl(boolean *data)
{
  return Rte_Read_PwrSplyEnaReq_Logl(data);
}

Std_ReturnType TSC_SysStMod_Rte_Read_StrtUpSt_Val(uint8 *data)
{
  return Rte_Read_StrtUpSt_Val(data);
}

Std_ReturnType TSC_SysStMod_Rte_Read_SysStFltOutpReqDi_Logl(boolean *data)
{
  return Rte_Read_SysStFltOutpReqDi_Logl(data);
}

Std_ReturnType TSC_SysStMod_Rte_Read_SysStImdtTranReqOff_Logl(boolean *data)
{
  return Rte_Read_SysStImdtTranReqOff_Logl(data);
}

Std_ReturnType TSC_SysStMod_Rte_Read_SysStReqDi_Logl(boolean *data)
{
  return Rte_Read_SysStReqDi_Logl(data);
}

Std_ReturnType TSC_SysStMod_Rte_Read_SysStReqEna_Logl(boolean *data)
{
  return Rte_Read_SysStReqEna_Logl(data);
}

Std_ReturnType TSC_SysStMod_Rte_Read_SysStWrmIninCmpl_Logl(boolean *data)
{
  return Rte_Read_SysStWrmIninCmpl_Logl(data);
}




Std_ReturnType TSC_SysStMod_Rte_Write_SysSt_Val(SysSt1 data)
{
  return Rte_Write_SysSt_Val(data);
}





     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */







     /* SysStMod */
      /* SysStMod */

/** Per Instance Memories */
uint16 *TSC_SysStMod_Rte_Pim_dSysStModTranVect(void)
{
  return Rte_Pim_dSysStModTranVect();
}
SysSt1 *TSC_SysStMod_Rte_Pim_SysStModPrevSysSt(void)
{
  return Rte_Pim_SysStModPrevSysSt();
}



