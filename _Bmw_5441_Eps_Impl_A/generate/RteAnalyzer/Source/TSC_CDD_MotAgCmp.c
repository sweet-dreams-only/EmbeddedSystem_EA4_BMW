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
 *          File:  TSC_CDD_MotAgCmp.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_CDD_MotAgCmp.h"
#include "TSC_CDD_MotAgCmp.h"















     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */
Std_ReturnType TSC_CDD_MotAgCmp_Rte_Call_MotAgCmpMotAgBackEmf_SetRamBlockStatus(boolean RamBlockStatus_Arg)
{
  return Rte_Call_MotAgCmpMotAgBackEmf_SetRamBlockStatus(RamBlockStatus_Arg);
}


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_CDD_MotAgCmp_Rte_Read_AssiMechPolarity_Val(sint8 *data)
{
  return Rte_Read_AssiMechPolarity_Val(data);
}

Std_ReturnType TSC_CDD_MotAgCmp_Rte_Read_MotAgCumvAlgndMrfRev_Val(s15p16 *data)
{
  return Rte_Read_MotAgCumvAlgndMrfRev_Val(data);
}

Std_ReturnType TSC_CDD_MotAgCmp_Rte_Read_MotAgCumvInid_Logl(boolean *data)
{
  return Rte_Read_MotAgCumvInid_Logl(data);
}




Std_ReturnType TSC_CDD_MotAgCmp_Rte_Write_MotAgCumvAlgndCrf_Val(s18p13 data)
{
  return Rte_Write_MotAgCumvAlgndCrf_Val(data);
}

Std_ReturnType TSC_CDD_MotAgCmp_Rte_Write_MotAgCumvAlgndMrf_Val(s18p13 data)
{
  return Rte_Write_MotAgCumvAlgndMrf_Val(data);
}

Std_ReturnType TSC_CDD_MotAgCmp_Rte_Write_MotAgCumvAlgndVld_Logl(boolean data)
{
  return Rte_Write_MotAgCumvAlgndVld_Logl(data);
}





     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */





float32  TSC_CDD_MotAgCmp_Rte_Prm_SysGlbPrmSysKineRat_Val(void)
{
  return (float32 ) Rte_Prm_SysGlbPrmSysKineRat_Val();
}
uint8  TSC_CDD_MotAgCmp_Rte_Prm_SysGlbPrmMotPoleCnt_Val(void)
{
  return (uint8 ) Rte_Prm_SysGlbPrmMotPoleCnt_Val();
}

u0p16  TSC_CDD_MotAgCmp_Rte_CData_MotAgCmpMotAgBackEmfDft(void)
{
  return (u0p16 ) Rte_CData_MotAgCmpMotAgBackEmfDft();
}

     /* CDD_MotAgCmp */
      /* CDD_MotAgCmp */

/** Per Instance Memories */
float32 *TSC_CDD_MotAgCmp_Rte_Pim_DigMotHwPosn(void)
{
  return Rte_Pim_DigMotHwPosn();
}
s15p16 *TSC_CDD_MotAgCmp_Rte_Pim_MotAgCmpMotCtrlMotAgCumvAlgndMrfRevPrev(void)
{
  return Rte_Pim_MotAgCmpMotCtrlMotAgCumvAlgndMrfRevPrev();
}
s15p16 *TSC_CDD_MotAgCmp_Rte_Pim_MotAgCmpMotCtrlMotAgMeclPrev(void)
{
  return Rte_Pim_MotAgCmpMotCtrlMotAgMeclPrev();
}
u0p16 *TSC_CDD_MotAgCmp_Rte_Pim_MotAgCmpMotAgBackEmf(void)
{
  return Rte_Pim_MotAgCmpMotAgBackEmf();
}
uint8 *TSC_CDD_MotAgCmp_Rte_Pim_CmpEnaCntr(void)
{
  return Rte_Pim_CmpEnaCntr();
}



