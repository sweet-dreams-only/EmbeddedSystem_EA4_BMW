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
 *          File:  TSC_PhaDiscnct.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_PhaDiscnct.h"
#include "TSC_PhaDiscnct.h"















     /* Client Server Interfaces: */
Std_ReturnType TSC_PhaDiscnct_Rte_Call_IoHwAb_SetGpioPhaDiscnctA_Oper(boolean PinSt_Arg)
{
  return Rte_Call_IoHwAb_SetGpioPhaDiscnctA_Oper(PinSt_Arg);
}
Std_ReturnType TSC_PhaDiscnct_Rte_Call_IoHwAb_SetGpioPhaDiscnctB_Oper(boolean PinSt_Arg)
{
  return Rte_Call_IoHwAb_SetGpioPhaDiscnctB_Oper(PinSt_Arg);
}
Std_ReturnType TSC_PhaDiscnct_Rte_Call_IoHwAb_SetGpioPhaDiscnctC_Oper(boolean PinSt_Arg)
{
  return Rte_Call_IoHwAb_SetGpioPhaDiscnctC_Oper(PinSt_Arg);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_PhaDiscnct_Rte_Read_DiagcStsIvtr1Inactv_Logl(boolean *data)
{
  return Rte_Read_DiagcStsIvtr1Inactv_Logl(data);
}

Std_ReturnType TSC_PhaDiscnct_Rte_Read_IvtrFetFltTyp_Val(IvtrFetFltTyp1 *data)
{
  return Rte_Read_IvtrFetFltTyp_Val(data);
}

Std_ReturnType TSC_PhaDiscnct_Rte_Read_MotCurrCorrdA_Val(float32 *data)
{
  return Rte_Read_MotCurrCorrdA_Val(data);
}

Std_ReturnType TSC_PhaDiscnct_Rte_Read_MotCurrCorrdB_Val(float32 *data)
{
  return Rte_Read_MotCurrCorrdB_Val(data);
}

Std_ReturnType TSC_PhaDiscnct_Rte_Read_MotCurrCorrdC_Val(float32 *data)
{
  return Rte_Read_MotCurrCorrdC_Val(data);
}

Std_ReturnType TSC_PhaDiscnct_Rte_Read_MotCurrQlfr1_Val(SigQlfr1 *data)
{
  return Rte_Read_MotCurrQlfr1_Val(data);
}

Std_ReturnType TSC_PhaDiscnct_Rte_Read_StrtUpSt_Val(uint8 *data)
{
  return Rte_Read_StrtUpSt_Val(data);
}




Std_ReturnType TSC_PhaDiscnct_Rte_Write_PhaDiscnctDiagcActv_Logl(boolean data)
{
  return Rte_Write_PhaDiscnctDiagcActv_Logl(data);
}

Std_ReturnType TSC_PhaDiscnct_Rte_Write_PhaDiscnctDiagcPwmVect_Val(PhaDiscnctPwmVect1 data)
{
  return Rte_Write_PhaDiscnctDiagcPwmVect_Val(data);
}





     /* Client Server Interfaces: */
Std_ReturnType TSC_PhaDiscnct_Rte_Call_SetNtcStsAndSnpshtData_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg, uint32 SpclSnpshtData0_Arg, uint32 SpclSnpshtData1_Arg, uint32 SpclSnpshtData2_Arg)
{
  return Rte_Call_SetNtcStsAndSnpshtData_Oper(NtcNr_Arg, NtcStInfo_Arg, NtcSts_Arg, DebStep_Arg, SpclSnpshtData0_Arg, SpclSnpshtData1_Arg, SpclSnpshtData2_Arg);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_PhaDiscnct_Rte_Read_IvtrFetFltPha_Val(IvtrFetFltPha1 *data)
{
  return Rte_Read_IvtrFetFltPha_Val(data);
}

Std_ReturnType TSC_PhaDiscnct_Rte_Read_SysSt_Val(SysSt1 *data)
{
  return Rte_Read_SysSt_Val(data);
}




Std_ReturnType TSC_PhaDiscnct_Rte_Write_PhaDiscnctInactv_Logl(boolean data)
{
  return Rte_Write_PhaDiscnctInactv_Logl(data);
}

Std_ReturnType TSC_PhaDiscnct_Rte_Write_PhaDiscnctWrmIninTestCmpl_Logl(boolean data)
{
  return Rte_Write_PhaDiscnctWrmIninTestCmpl_Logl(data);
}





     /* Client Server Interfaces: */
Std_ReturnType TSC_PhaDiscnct_Rte_Call_GetRefTmr100MicroSec32bit_Oper(uint32 *RefTmr_Arg)
{
  return Rte_Call_GetRefTmr100MicroSec32bit_Oper(RefTmr_Arg);
}
Std_ReturnType TSC_PhaDiscnct_Rte_Call_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg)
{
  return Rte_Call_GetTiSpan100MicroSec32bit_Oper(RefTmr_Arg, TiSpan_Arg);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */





float32  TSC_PhaDiscnct_Rte_Prm_PhaDiscnctTestCurrTestVal_Val(void)
{
  return (float32 ) Rte_Prm_PhaDiscnctTestCurrTestVal_Val();
}
uint32  TSC_PhaDiscnct_Rte_Prm_PhaDiscnctFixdPhaOnTi_Val(void)
{
  return (uint32 ) Rte_Prm_PhaDiscnctFixdPhaOnTi_Val();
}
uint32  TSC_PhaDiscnct_Rte_Prm_PhaDiscnctFixdPwmPerd_Val(void)
{
  return (uint32 ) Rte_Prm_PhaDiscnctFixdPwmPerd_Val();
}
uint16  TSC_PhaDiscnct_Rte_Prm_PhaDiscnctClsDlyTi_Val(void)
{
  return (uint16 ) Rte_Prm_PhaDiscnctClsDlyTi_Val();
}
uint16  TSC_PhaDiscnct_Rte_Prm_PhaDiscnctOpenDlyTi_Val(void)
{
  return (uint16 ) Rte_Prm_PhaDiscnctOpenDlyTi_Val();
}
uint8  TSC_PhaDiscnct_Rte_Prm_PhaDiscnctTestFailScanMax_Val(void)
{
  return (uint8 ) Rte_Prm_PhaDiscnctTestFailScanMax_Val();
}
uint8  TSC_PhaDiscnct_Rte_Prm_PhaDiscnctTestIninScan_Val(void)
{
  return (uint8 ) Rte_Prm_PhaDiscnctTestIninScan_Val();
}
uint8  TSC_PhaDiscnct_Rte_Prm_PhaDiscnctTestScanCnt_Val(void)
{
  return (uint8 ) Rte_Prm_PhaDiscnctTestScanCnt_Val();
}


     /* PhaDiscnct */
      /* PhaDiscnct */

/** Per Instance Memories */
uint32 *TSC_PhaDiscnct_Rte_Pim_DiscnctClsTmr(void)
{
  return Rte_Pim_DiscnctClsTmr();
}
uint32 *TSC_PhaDiscnct_Rte_Pim_DiscnctOpenTmr(void)
{
  return Rte_Pim_DiscnctOpenTmr();
}
uint8 *TSC_PhaDiscnct_Rte_Pim_DiscnctDiagCurrComp(void)
{
  return Rte_Pim_DiscnctDiagCurrComp();
}
uint8 *TSC_PhaDiscnct_Rte_Pim_DiscnctDiagFailScan(void)
{
  return Rte_Pim_DiscnctDiagFailScan();
}
uint8 *TSC_PhaDiscnct_Rte_Pim_DiscnctDiagFltSts(void)
{
  return Rte_Pim_DiscnctDiagFltSts();
}
uint8 *TSC_PhaDiscnct_Rte_Pim_DiscnctDiagItrn(void)
{
  return Rte_Pim_DiscnctDiagItrn();
}
uint8 *TSC_PhaDiscnct_Rte_Pim_DiscnctDiagSt(void)
{
  return Rte_Pim_DiscnctDiagSt();
}
uint8 *TSC_PhaDiscnct_Rte_Pim_DiscnctDiagTestScan(void)
{
  return Rte_Pim_DiscnctDiagTestScan();
}
uint8 *TSC_PhaDiscnct_Rte_Pim_DiscnctFltPrm(void)
{
  return Rte_Pim_DiscnctFltPrm();
}
uint8 *TSC_PhaDiscnct_Rte_Pim_DiscnctSt(void)
{
  return Rte_Pim_DiscnctSt();
}
uint8 *TSC_PhaDiscnct_Rte_Pim_PrevDiscnctCmd(void)
{
  return Rte_Pim_PrevDiscnctCmd();
}
uint8 *TSC_PhaDiscnct_Rte_Pim_dPhaDiscnctCmd(void)
{
  return Rte_Pim_dPhaDiscnctCmd();
}
boolean *TSC_PhaDiscnct_Rte_Pim_WrmIninTestCmpl(void)
{
  return Rte_Pim_WrmIninTestCmpl();
}
boolean *TSC_PhaDiscnct_Rte_Pim_dPhaDiscnctActvd(void)
{
  return Rte_Pim_dPhaDiscnctActvd();
}



