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
 *          File:  TSC_TmplMonr.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_TmplMonr.h"
#include "TSC_TmplMonr.h"











Std_ReturnType TSC_TmplMonr_Rte_Write_TmplMonrIninTestCmpl_Logl(boolean data)
{
  return Rte_Write_TmplMonrIninTestCmpl_Logl(data);
}





     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_TmplMonr_Rte_Read_StrtUpSt_Val(uint8 *data)
{
  return Rte_Read_StrtUpSt_Val(data);
}








     /* Client Server Interfaces: */
Std_ReturnType TSC_TmplMonr_Rte_Call_CtrlErrOut_Oper(boolean PinSt_Arg, TrigReg1 TrigReg_Arg)
{
  return Rte_Call_CtrlErrOut_Oper(PinSt_Arg, TrigReg_Arg);
}
Std_ReturnType TSC_TmplMonr_Rte_Call_GetRefTmr1MicroSec32bit_Oper(uint32 *RefTmr_Arg)
{
  return Rte_Call_GetRefTmr1MicroSec32bit_Oper(RefTmr_Arg);
}
Std_ReturnType TSC_TmplMonr_Rte_Call_IoHwAb_GetGpioPwrOutpEnaFb_Oper(boolean *PinSt_Arg)
{
  return Rte_Call_IoHwAb_GetGpioPwrOutpEnaFb_Oper(PinSt_Arg);
}
Std_ReturnType TSC_TmplMonr_Rte_Call_IoHwAb_SetGpioTmplMonrWdg_Oper(boolean PinSt_Arg)
{
  return Rte_Call_IoHwAb_SetGpioTmplMonrWdg_Oper(PinSt_Arg);
}
Std_ReturnType TSC_TmplMonr_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
{
  return Rte_Call_SetNtcSts_Oper(NtcNr_Arg, NtcStInfo_Arg, NtcSts_Arg, DebStep_Arg);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */

void TSC_TmplMonr_Rte_IrvWrite_TmplMonrPer1_ElpdTiMicroSec(uint32 data)
{
  Rte_IrvWrite_TmplMonrPer1_ElpdTiMicroSec( data);
}












     /* Client Server Interfaces: */
Std_ReturnType TSC_TmplMonr_Rte_Call_GetTiSpan1MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg)
{
  return Rte_Call_GetTiSpan1MicroSec32bit_Oper(RefTmr_Arg, TiSpan_Arg);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */
uint32 TSC_TmplMonr_Rte_IrvRead_TmplMonrPer2_ElpdTiMicroSec(void)
{
return Rte_IrvRead_TmplMonrPer2_ElpdTiMicroSec();
}






Std_ReturnType TSC_TmplMonr_Rte_Read_SysSt_Val(SysSt1 *data)
{
  return Rte_Read_SysSt_Val(data);
}








     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */







     /* TmplMonr */
      /* TmplMonr */

/** Per Instance Memories */
uint32 *TSC_TmplMonr_Rte_Pim_AvrgElpdTiMicroSec(void)
{
  return Rte_Pim_AvrgElpdTiMicroSec();
}
uint16 *TSC_TmplMonr_Rte_Pim_TrsmErrCntr(void)
{
  return Rte_Pim_TrsmErrCntr();
}
uint8 *TSC_TmplMonr_Rte_Pim_TmplMonrIninCntr(void)
{
  return Rte_Pim_TmplMonrIninCntr();
}
uint8 *TSC_TmplMonr_Rte_Pim_TmplMonrNtc40PrmByte(void)
{
  return Rte_Pim_TmplMonrNtc40PrmByte();
}
uint8 *TSC_TmplMonr_Rte_Pim_TmplMonrWdgRstrtCnt(void)
{
  return Rte_Pim_TmplMonrWdgRstrtCnt();
}
uint8 *TSC_TmplMonr_Rte_Pim_TrsmErrNtcThd(void)
{
  return Rte_Pim_TrsmErrNtcThd();
}
boolean *TSC_TmplMonr_Rte_Pim_TmplMonrIninTestCmplFlg(void)
{
  return Rte_Pim_TmplMonrIninTestCmplFlg();
}
boolean *TSC_TmplMonr_Rte_Pim_TmplMonrSpiReadWrOrderFlg1(void)
{
  return Rte_Pim_TmplMonrSpiReadWrOrderFlg1();
}
boolean *TSC_TmplMonr_Rte_Pim_TmplMonrSpiReadWrOrderFlg2(void)
{
  return Rte_Pim_TmplMonrSpiReadWrOrderFlg2();
}



