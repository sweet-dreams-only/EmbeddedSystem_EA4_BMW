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
 *          File:  TSC_BmwMsgSlot108Bas0Repn2BusFrChA.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_BmwMsgSlot108Bas0Repn2BusFrChA.h"
#include "TSC_BmwMsgSlot108Bas0Repn2BusFrChA.h"















     /* Client Server Interfaces: */
Std_ReturnType TSC_BmwMsgSlot108Bas0Repn2BusFrChA_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
{
  return Rte_Call_SetNtcSts_Oper(NtcNr_Arg, NtcStInfo_Arg, NtcSts_Arg, DebStep_Arg);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_BmwMsgSlot108Bas0Repn2BusFrChA_Rte_Read_FltCodEnad_Logl(boolean *data)
{
  return Rte_Read_FltCodEnad_Logl(data);
}




Std_ReturnType TSC_BmwMsgSlot108Bas0Repn2BusFrChA_Rte_Write_BmwPinionAgOffs_Val(float32 data)
{
  return Rte_Write_BmwPinionAgOffs_Val(data);
}

Std_ReturnType TSC_BmwMsgSlot108Bas0Repn2BusFrChA_Rte_Write_BmwPinionAgOffsSts_Val(BmwPinionAgOffsSts1 data)
{
  return Rte_Write_BmwPinionAgOffsSts_Val(data);
}





     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_BmwMsgSlot108Bas0Repn2BusFrChA_Rte_Read_AVL_STEA_PNI_OFFS_AVL_STEA_PNI_OFFS(AVL_STEA_PNI_OFFS1 *data)
{
  return Rte_Read_AVL_STEA_PNI_OFFS_AVL_STEA_PNI_OFFS(data);
}


boolean TSC_BmwMsgSlot108Bas0Repn2BusFrChA_Rte_IsUpdated_AVL_STEA_PNI_OFFS_AVL_STEA_PNI_OFFS(void)
{
  return Rte_IsUpdated_AVL_STEA_PNI_OFFS_AVL_STEA_PNI_OFFS();
}







     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */





sint8  TSC_BmwMsgSlot108Bas0Repn2BusFrChA_Rte_Prm_BmwMsgSlot108Bas0Repn2BusFrChABmwSteerPolarity_Val(void)
{
  return (sint8 ) Rte_Prm_BmwMsgSlot108Bas0Repn2BusFrChABmwSteerPolarity_Val();
}


     /* BmwMsgSlot108Bas0Repn2BusFrChA */
      /* BmwMsgSlot108Bas0Repn2BusFrChA */

/** Per Instance Memories */
float32 *TSC_BmwMsgSlot108Bas0Repn2BusFrChA_Rte_Pim_BmwPinionAgOffsPrev(void)
{
  return Rte_Pim_BmwPinionAgOffsPrev();
}
uint8 *TSC_BmwMsgSlot108Bas0Repn2BusFrChA_Rte_Pim_AvlSteaPniOffsFaildCnt(void)
{
  return Rte_Pim_AvlSteaPniOffsFaildCnt();
}
uint8 *TSC_BmwMsgSlot108Bas0Repn2BusFrChA_Rte_Pim_AvlSteaPniOffsPassdCnt(void)
{
  return Rte_Pim_AvlSteaPniOffsPassdCnt();
}
uint8 *TSC_BmwMsgSlot108Bas0Repn2BusFrChA_Rte_Pim_MissingMsgCnt(void)
{
  return Rte_Pim_MissingMsgCnt();
}
uint8 *TSC_BmwMsgSlot108Bas0Repn2BusFrChA_Rte_Pim_RxMsgCnt(void)
{
  return Rte_Pim_RxMsgCnt();
}



