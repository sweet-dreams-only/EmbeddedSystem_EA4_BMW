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
 *          File:  TSC_BmwMsgSlot107Bas0Repn1BusFrChA.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_BmwMsgSlot107Bas0Repn1BusFrChA.h"
#include "TSC_BmwMsgSlot107Bas0Repn1BusFrChA.h"








Std_ReturnType TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_Read_FltCodEnad_Logl(boolean *data)
{
  return Rte_Read_FltCodEnad_Logl(data);
}

Std_ReturnType TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_Read_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS(sigGroup_OFFS_QUAD_EPS1 *data)
{
  return Rte_Read_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS(data);
}


boolean TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_IsUpdated_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS(void)
{
  return Rte_IsUpdated_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS();
}



Std_ReturnType TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_Write_BmwActIntgtdCtrlModlPosnIdxValVld_Logl(boolean data)
{
  return Rte_Write_BmwActIntgtdCtrlModlPosnIdxValVld_Logl(data);
}

Std_ReturnType TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_Write_BmwQuadOffsSts_Val(BmwQuadOffsSts1 data)
{
  return Rte_Write_BmwQuadOffsSts_Val(data);
}

Std_ReturnType TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_Write_BmwQuadOffsStsVld_Logl(boolean data)
{
  return Rte_Write_BmwQuadOffsStsVld_Logl(data);
}

Std_ReturnType TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_Write_BmwQuadRtrOffsVld_Logl(boolean data)
{
  return Rte_Write_BmwQuadRtrOffsVld_Logl(data);
}





     /* Client Server Interfaces: */
Std_ReturnType TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
{
  return Rte_Call_SetNtcSts_Oper(NtcNr_Arg, NtcStInfo_Arg, NtcSts_Arg, DebStep_Arg);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */









Std_ReturnType TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_Write_BmwActIntgtdCtrlModlPosnIdxVal_Val(float32 data)
{
  return Rte_Write_BmwActIntgtdCtrlModlPosnIdxVal_Val(data);
}

Std_ReturnType TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_Write_BmwQuadRtrOffs_Val(sint8 data)
{
  return Rte_Write_BmwQuadRtrOffs_Val(data);
}





     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */





sint8  TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_Prm_BmwMsgSlot108Bas0Repn2BusFrChABmwSteerPolarity_Val(void)
{
  return (sint8 ) Rte_Prm_BmwMsgSlot108Bas0Repn2BusFrChABmwSteerPolarity_Val();
}


     /* BmwMsgSlot107Bas0Repn1BusFrChA */
      /* BmwMsgSlot107Bas0Repn1BusFrChA */

/** Per Instance Memories */
float32 *TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_Pim_BmwActIntgtdCtrlModlPosnIdxValPrev(void)
{
  return Rte_Pim_BmwActIntgtdCtrlModlPosnIdxValPrev();
}
AVL_PO_IDX_ICM1 *TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_Pim_Dummy_PIM1(void)
{
  return Rte_Pim_Dummy_PIM1();
}
uint8 *TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_Pim_AlvFaildCnt(void)
{
  return Rte_Pim_AlvFaildCnt();
}
uint8 *TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_Pim_AlvPassdCnt(void)
{
  return Rte_Pim_AlvPassdCnt();
}
uint8 *TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_Pim_AvlPoIdxIcmFaildCnt(void)
{
  return Rte_Pim_AvlPoIdxIcmFaildCnt();
}
uint8 *TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_Pim_AvlPoIdxIcmPassdCnt(void)
{
  return Rte_Pim_AvlPoIdxIcmPassdCnt();
}
BmwQuadOffsSts1 *TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_Pim_BmwQuadOffsStsPrev(void)
{
  return Rte_Pim_BmwQuadOffsStsPrev();
}
uint8 *TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_Pim_CrcFaildCnt(void)
{
  return Rte_Pim_CrcFaildCnt();
}
uint8 *TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_Pim_CrcPassdCnt(void)
{
  return Rte_Pim_CrcPassdCnt();
}
ST_OFFS_QUAD_EPS1 *TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_Pim_Dummy_PIM2(void)
{
  return Rte_Pim_Dummy_PIM2();
}
OFFS_QUAD_RTR_EPS1 *TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_Pim_Dummy_PIM3(void)
{
  return Rte_Pim_Dummy_PIM3();
}
uint8 *TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_Pim_MissMsgCnt(void)
{
  return Rte_Pim_MissMsgCnt();
}
uint8 *TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_Pim_OffsQuadRtrEpsFaildCnt(void)
{
  return Rte_Pim_OffsQuadRtrEpsFaildCnt();
}
uint8 *TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_Pim_OffsQuadRtrEpsPassdCnt(void)
{
  return Rte_Pim_OffsQuadRtrEpsPassdCnt();
}
uint8 *TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_Pim_RxdMsgCnt(void)
{
  return Rte_Pim_RxdMsgCnt();
}
uint8 *TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_Pim_StOffsQuadEpsFaildCnt(void)
{
  return Rte_Pim_StOffsQuadEpsFaildCnt();
}
uint8 *TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_Pim_StOffsQuadEpsPassdCnt(void)
{
  return Rte_Pim_StOffsQuadEpsPassdCnt();
}
sint8 *TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_Pim_BmwQuadRtrOffsPrev(void)
{
  return Rte_Pim_BmwQuadRtrOffsPrev();
}



