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
 *          File:  TSC_CDD_HwTq5Meas.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_CDD_HwTq5Meas.h"
#include "TSC_CDD_HwTq5Meas.h"















     /* Client Server Interfaces: */


     /* Service calls */
Std_ReturnType TSC_CDD_HwTq5Meas_Rte_Call_HwTq5Offs_SetRamBlockStatus(boolean RamBlockStatus_Arg)
{
  return Rte_Call_HwTq5Offs_SetRamBlockStatus(RamBlockStatus_Arg);
}


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */
Std_ReturnType TSC_CDD_HwTq5Meas_Rte_Call_HwTq5Sca_SetRamBlockStatus(boolean RamBlockStatus_Arg)
{
  return Rte_Call_HwTq5Sca_SetRamBlockStatus(RamBlockStatus_Arg);
}


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */
Std_ReturnType TSC_CDD_HwTq5Meas_Rte_Call_HwTq5Offs_GetErrorStatus(NvM_RequestResultType *ErrorStatus_Arg)
{
  return Rte_Call_HwTq5Offs_GetErrorStatus(ErrorStatus_Arg);
}
Std_ReturnType TSC_CDD_HwTq5Meas_Rte_Call_HwTq5Sca_GetErrorStatus(NvM_RequestResultType *ErrorStatus_Arg)
{
  return Rte_Call_HwTq5Sca_GetErrorStatus(ErrorStatus_Arg);
}


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_CDD_HwTq5Meas_Rte_Read_HwTq5Polarity_Val(sint8 *data)
{
  return Rte_Read_HwTq5Polarity_Val(data);
}

Std_ReturnType TSC_CDD_HwTq5Meas_Rte_Read_HwTq5RawAdc_Val(float32 *data)
{
  return Rte_Read_HwTq5RawAdc_Val(data);
}

Std_ReturnType TSC_CDD_HwTq5Meas_Rte_Read_HwTq5RawAdcAdcFaild_Logl(boolean *data)
{
  return Rte_Read_HwTq5RawAdcAdcFaild_Logl(data);
}

Std_ReturnType TSC_CDD_HwTq5Meas_Rte_Read_HwTq5RawFastAdcAdcFaild_Logl(boolean *data)
{
  return Rte_Read_HwTq5RawFastAdcAdcFaild_Logl(data);
}

Std_ReturnType TSC_CDD_HwTq5Meas_Rte_Read_HwTq5RawFastAdcBuf_Ary1D(float32 *data)
{
  return Rte_Read_HwTq5RawFastAdcBuf_Ary1D(data);
}




Std_ReturnType TSC_CDD_HwTq5Meas_Rte_Write_HwTq5_Val(float32 data)
{
  return Rte_Write_HwTq5_Val(data);
}

Std_ReturnType TSC_CDD_HwTq5Meas_Rte_Write_HwTq5Qlfr_Val(SigQlfr1 data)
{
  return Rte_Write_HwTq5Qlfr_Val(data);
}

Std_ReturnType TSC_CDD_HwTq5Meas_Rte_Write_HwTq5RollgCntr_Val(uint8 data)
{
  return Rte_Write_HwTq5RollgCntr_Val(data);
}





     /* Client Server Interfaces: */
Std_ReturnType TSC_CDD_HwTq5Meas_Rte_Call_GetNtcQlfrSts_Oper(NtcNr1 NtcNr_Arg, SigQlfr1 *NtcQlfr_Arg)
{
  return Rte_Call_GetNtcQlfrSts_Oper(NtcNr_Arg, NtcQlfr_Arg);
}
Std_ReturnType TSC_CDD_HwTq5Meas_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
{
  return Rte_Call_SetNtcSts_Oper(NtcNr_Arg, NtcStInfo_Arg, NtcSts_Arg, DebStep_Arg);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */





float32  TSC_CDD_HwTq5Meas_Rte_Prm_HwTq5MeasHwTqRngHiLim_Val(void)
{
  return (float32 ) Rte_Prm_HwTq5MeasHwTqRngHiLim_Val();
}
float32  TSC_CDD_HwTq5Meas_Rte_Prm_HwTq5MeasHwTqRngLoLim_Val(void)
{
  return (float32 ) Rte_Prm_HwTq5MeasHwTqRngLoLim_Val();
}
uint16  TSC_CDD_HwTq5Meas_Rte_Prm_HwTq5MeasHwTq5PrtclFltFailStep_Val(void)
{
  return (uint16 ) Rte_Prm_HwTq5MeasHwTq5PrtclFltFailStep_Val();
}
uint16  TSC_CDD_HwTq5Meas_Rte_Prm_HwTq5MeasHwTq5PrtclFltPassStep_Val(void)
{
  return (uint16 ) Rte_Prm_HwTq5MeasHwTq5PrtclFltPassStep_Val();
}
boolean  TSC_CDD_HwTq5Meas_Rte_Prm_HwTq5MeasMovgAvrgFilEna_Logl(void)
{
  return (boolean ) Rte_Prm_HwTq5MeasMovgAvrgFilEna_Logl();
}


     /* CDD_HwTq5Meas */
      /* CDD_HwTq5Meas */

/** Per Instance Memories */
float32 *TSC_CDD_HwTq5Meas_Rte_Pim_HwTq5PrevHwTq5(void)
{
  return Rte_Pim_HwTq5PrevHwTq5();
}
uint8 *TSC_CDD_HwTq5Meas_Rte_Pim_HwTq5PrevRollgCntr(void)
{
  return Rte_Pim_HwTq5PrevRollgCntr();
}
uint8 *TSC_CDD_HwTq5Meas_Rte_Pim_HwTq5RawFastAdcIdxCntr(void)
{
  return Rte_Pim_HwTq5RawFastAdcIdxCntr();
}
HwTqOffsRec1 *TSC_CDD_HwTq5Meas_Rte_Pim_HwTq5Offs(void)
{
  return Rte_Pim_HwTq5Offs();
}
AnHwTqScaFacRec1 *TSC_CDD_HwTq5Meas_Rte_Pim_HwTq5Sca(void)
{
  return Rte_Pim_HwTq5Sca();
}



