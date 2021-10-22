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
 *          File:  TSC_BmwMsgSlot274Bas2Repn4BusFrChA.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_BmwMsgSlot274Bas2Repn4BusFrChA.h"
#include "TSC_BmwMsgSlot274Bas2Repn4BusFrChA.h"















     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_BmwMsgSlot274Bas2Repn4BusFrChA_Rte_Read_BmwFltLampFlsgFrq_Val(BmwFltLampFlsgFrq1 *data)
{
  return Rte_Read_BmwFltLampFlsgFrq_Val(data);
}

Std_ReturnType TSC_BmwMsgSlot274Bas2Repn4BusFrChA_Rte_Read_BmwFltLampReqSts_Val(BmwFltLampReqSts1 *data)
{
  return Rte_Read_BmwFltLampReqSts_Val(data);
}

Std_ReturnType TSC_BmwMsgSlot274Bas2Repn4BusFrChA_Rte_Read_BmwFltLampReqTxTyp_Val(uint8 *data)
{
  return Rte_Read_BmwFltLampReqTxTyp_Val(data);
}

Std_ReturnType TSC_BmwMsgSlot274Bas2Repn4BusFrChA_Rte_Read_BmwFltLampReqTyp_Val(BmwFltLampReqTyp2 *data)
{
  return Rte_Read_BmwFltLampReqTyp_Val(data);
}




Std_ReturnType TSC_BmwMsgSlot274Bas2Repn4BusFrChA_Rte_Write_sigGroup_DISP_CC_EPS_sigGroup_DISP_CC_EPS(const sigGroup_DISP_CC_EPS1 *data)
{
  return Rte_Write_sigGroup_DISP_CC_EPS_sigGroup_DISP_CC_EPS(data);
}


Std_ReturnType TSC_BmwMsgSlot274Bas2Repn4BusFrChA_Rte_Invalidate_sigGroup_DISP_CC_EPS_sigGroup_DISP_CC_EPS(void)
{
  return Rte_Invalidate_sigGroup_DISP_CC_EPS_sigGroup_DISP_CC_EPS();
}




     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */







     /* BmwMsgSlot274Bas2Repn4BusFrChA */
      /* BmwMsgSlot274Bas2Repn4BusFrChA */

/** Per Instance Memories */
BmwFltLampReqTyp2 *TSC_BmwMsgSlot274Bas2Repn4BusFrChA_Rte_Pim_BmwFltLampReqTypPrev(void)
{
  return Rte_Pim_BmwFltLampReqTypPrev();
}
BmwFltLampFlsgFrq1 *TSC_BmwMsgSlot274Bas2Repn4BusFrChA_Rte_Pim_BmwFltLampFlsgFrqPrev(void)
{
  return Rte_Pim_BmwFltLampFlsgFrqPrev();
}
BmwFltLampReqSts1 *TSC_BmwMsgSlot274Bas2Repn4BusFrChA_Rte_Pim_BmwFltLampReqStsPrev(void)
{
  return Rte_Pim_BmwFltLampReqStsPrev();
}
uint8 *TSC_BmwMsgSlot274Bas2Repn4BusFrChA_Rte_Pim_BmwFltLampReqTxTypPrev(void)
{
  return Rte_Pim_BmwFltLampReqTxTypPrev();
}
uint8 *TSC_BmwMsgSlot274Bas2Repn4BusFrChA_Rte_Pim_LstTxCntr(void)
{
  return Rte_Pim_LstTxCntr();
}
uint8 *TSC_BmwMsgSlot274Bas2Repn4BusFrChA_Rte_Pim_PerdCntr(void)
{
  return Rte_Pim_PerdCntr();
}



