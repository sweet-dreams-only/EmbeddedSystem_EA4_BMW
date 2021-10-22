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
 *          File:  TSC_CDD_McuDiagc.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_CDD_McuDiagc.h"
#include "TSC_CDD_McuDiagc.h"















     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_CDD_McuDiagc_Rte_Read_FastLoopCntr_Val(uint16 *data)
{
  return Rte_Read_FastLoopCntr_Val(data);
}

Std_ReturnType TSC_CDD_McuDiagc_Rte_Read_SlowLoopCntr_Val(uint16 *data)
{
  return Rte_Read_SlowLoopCntr_Val(data);
}

Std_ReturnType TSC_CDD_McuDiagc_Rte_Read_SysSt_Val(SysSt1 *data)
{
  return Rte_Read_SysSt_Val(data);
}




Std_ReturnType TSC_CDD_McuDiagc_Rte_Write_LoopCntr2MilliSec_Val(uint16 data)
{
  return Rte_Write_LoopCntr2MilliSec_Val(data);
}





     /* Client Server Interfaces: */
Std_ReturnType TSC_CDD_McuDiagc_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
{
  return Rte_Call_SetNtcSts_Oper(NtcNr_Arg, NtcStInfo_Arg, NtcSts_Arg, DebStep_Arg);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */





uint16  TSC_CDD_McuDiagc_Rte_Prm_McuDiagc2MilliSecCntrCompThd_Val(void)
{
  return (uint16 ) Rte_Prm_McuDiagc2MilliSecCntrCompThd_Val();
}
uint16  TSC_CDD_McuDiagc_Rte_Prm_McuDiagcFltFailStep_Val(void)
{
  return (uint16 ) Rte_Prm_McuDiagcFltFailStep_Val();
}
uint16  TSC_CDD_McuDiagc_Rte_Prm_McuDiagcFltPassStep_Val(void)
{
  return (uint16 ) Rte_Prm_McuDiagcFltPassStep_Val();
}


     /* CDD_McuDiagc */
      /* CDD_McuDiagc */

/** Per Instance Memories */
uint16 *TSC_CDD_McuDiagc_Rte_Pim_FastLoopCntrPrev(void)
{
  return Rte_Pim_FastLoopCntrPrev();
}
uint16 *TSC_CDD_McuDiagc_Rte_Pim_LoopCntr2MilliSecStore(void)
{
  return Rte_Pim_LoopCntr2MilliSecStore();
}
uint16 *TSC_CDD_McuDiagc_Rte_Pim_LoopCntrPrev(void)
{
  return Rte_Pim_LoopCntrPrev();
}
uint16 *TSC_CDD_McuDiagc_Rte_Pim_dMcuDiagcFastLoopCntrMax(void)
{
  return Rte_Pim_dMcuDiagcFastLoopCntrMax();
}
uint16 *TSC_CDD_McuDiagc_Rte_Pim_dMcuDiagcFastLoopCntrMin(void)
{
  return Rte_Pim_dMcuDiagcFastLoopCntrMin();
}
uint16 *TSC_CDD_McuDiagc_Rte_Pim_dMcuDiagcLoopCntr2MilliSecMotCtrlDif(void)
{
  return Rte_Pim_dMcuDiagcLoopCntr2MilliSecMotCtrlDif();
}
uint8 *TSC_CDD_McuDiagc_Rte_Pim_FastLoopCntrDiagcCfgd(void)
{
  return Rte_Pim_FastLoopCntrDiagcCfgd();
}



