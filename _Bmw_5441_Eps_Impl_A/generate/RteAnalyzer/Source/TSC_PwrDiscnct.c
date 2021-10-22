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
 *          File:  TSC_PwrDiscnct.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_PwrDiscnct.h"
#include "TSC_PwrDiscnct.h"















     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_PwrDiscnct_Rte_Read_BattVltg_Val(float32 *data)
{
  return Rte_Read_BattVltg_Val(data);
}

Std_ReturnType TSC_PwrDiscnct_Rte_Read_BattVltgSwd1_Val(float32 *data)
{
  return Rte_Read_BattVltgSwd1_Val(data);
}

Std_ReturnType TSC_PwrDiscnct_Rte_Read_StrtUpSt_Val(uint8 *data)
{
  return Rte_Read_StrtUpSt_Val(data);
}




Std_ReturnType TSC_PwrDiscnct_Rte_Write_PwrDiscnctATestCmpl_Logl(boolean data)
{
  return Rte_Write_PwrDiscnctATestCmpl_Logl(data);
}

Std_ReturnType TSC_PwrDiscnct_Rte_Write_PwrDiscnctBTestCmpl_Logl(boolean data)
{
  return Rte_Write_PwrDiscnctBTestCmpl_Logl(data);
}





     /* Client Server Interfaces: */
Std_ReturnType TSC_PwrDiscnct_Rte_Call_GetNtcQlfrSts_Oper(NtcNr1 NtcNr_Arg, SigQlfr1 *NtcQlfr_Arg)
{
  return Rte_Call_GetNtcQlfrSts_Oper(NtcNr_Arg, NtcQlfr_Arg);
}
Std_ReturnType TSC_PwrDiscnct_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
{
  return Rte_Call_SetNtcSts_Oper(NtcNr_Arg, NtcStInfo_Arg, NtcSts_Arg, DebStep_Arg);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */





float32  TSC_PwrDiscnct_Rte_Prm_BattVltgSwdMax_Val(void)
{
  return (float32 ) Rte_Prm_BattVltgSwdMax_Val();
}


     /* PwrDiscnct */
      /* PwrDiscnct */

/** Per Instance Memories */
boolean *TSC_PwrDiscnct_Rte_Pim_PwrDiscnctATestCmplPrev(void)
{
  return Rte_Pim_PwrDiscnctATestCmplPrev();
}



