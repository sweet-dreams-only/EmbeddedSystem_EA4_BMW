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
 *          File:  TSC_CDD_HwTq4Meas.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_CDD_HwTq4Meas.h"
#include "TSC_CDD_HwTq4Meas.h"















     /* Client Server Interfaces: */


     /* Service calls */
Std_ReturnType TSC_CDD_HwTq4Meas_Rte_Call_HwTq4Offs_SetRamBlockStatus(boolean RamBlockStatus_Arg)
{
  return Rte_Call_HwTq4Offs_SetRamBlockStatus(RamBlockStatus_Arg);
}


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */
Std_ReturnType TSC_CDD_HwTq4Meas_Rte_Call_HwTq4Sca_SetRamBlockStatus(boolean RamBlockStatus_Arg)
{
  return Rte_Call_HwTq4Sca_SetRamBlockStatus(RamBlockStatus_Arg);
}


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */
Std_ReturnType TSC_CDD_HwTq4Meas_Rte_Call_HwTq4Offs_GetErrorStatus(NvM_RequestResultType *ErrorStatus_Arg)
{
  return Rte_Call_HwTq4Offs_GetErrorStatus(ErrorStatus_Arg);
}
Std_ReturnType TSC_CDD_HwTq4Meas_Rte_Call_HwTq4Sca_GetErrorStatus(NvM_RequestResultType *ErrorStatus_Arg)
{
  return Rte_Call_HwTq4Sca_GetErrorStatus(ErrorStatus_Arg);
}


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_CDD_HwTq4Meas_Rte_Read_HwTq4Polarity_Val(sint8 *data)
{
  return Rte_Read_HwTq4Polarity_Val(data);
}

Std_ReturnType TSC_CDD_HwTq4Meas_Rte_Read_HwTq4RawAdc_Val(float32 *data)
{
  return Rte_Read_HwTq4RawAdc_Val(data);
}

Std_ReturnType TSC_CDD_HwTq4Meas_Rte_Read_HwTq4RawAdcAdcFaild_Logl(boolean *data)
{
  return Rte_Read_HwTq4RawAdcAdcFaild_Logl(data);
}

Std_ReturnType TSC_CDD_HwTq4Meas_Rte_Read_HwTq4RawFastAdcAdcFaild_Logl(boolean *data)
{
  return Rte_Read_HwTq4RawFastAdcAdcFaild_Logl(data);
}

Std_ReturnType TSC_CDD_HwTq4Meas_Rte_Read_HwTq4RawFastAdcBuf_Ary1D(float32 *data)
{
  return Rte_Read_HwTq4RawFastAdcBuf_Ary1D(data);
}




Std_ReturnType TSC_CDD_HwTq4Meas_Rte_Write_HwTq4_Val(float32 data)
{
  return Rte_Write_HwTq4_Val(data);
}

Std_ReturnType TSC_CDD_HwTq4Meas_Rte_Write_HwTq4Qlfr_Val(SigQlfr1 data)
{
  return Rte_Write_HwTq4Qlfr_Val(data);
}

Std_ReturnType TSC_CDD_HwTq4Meas_Rte_Write_HwTq4RollgCntr_Val(uint8 data)
{
  return Rte_Write_HwTq4RollgCntr_Val(data);
}





     /* Client Server Interfaces: */
Std_ReturnType TSC_CDD_HwTq4Meas_Rte_Call_GetNtcQlfrSts_Oper(NtcNr1 NtcNr_Arg, SigQlfr1 *NtcQlfr_Arg)
{
  return Rte_Call_GetNtcQlfrSts_Oper(NtcNr_Arg, NtcQlfr_Arg);
}
Std_ReturnType TSC_CDD_HwTq4Meas_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
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





float32  TSC_CDD_HwTq4Meas_Rte_Prm_HwTq4MeasHwTqRngHiLim_Val(void)
{
  return (float32 ) Rte_Prm_HwTq4MeasHwTqRngHiLim_Val();
}
float32  TSC_CDD_HwTq4Meas_Rte_Prm_HwTq4MeasHwTqRngLoLim_Val(void)
{
  return (float32 ) Rte_Prm_HwTq4MeasHwTqRngLoLim_Val();
}
uint16  TSC_CDD_HwTq4Meas_Rte_Prm_HwTq4MeasHwTq4PrtclFltFailStep_Val(void)
{
  return (uint16 ) Rte_Prm_HwTq4MeasHwTq4PrtclFltFailStep_Val();
}
uint16  TSC_CDD_HwTq4Meas_Rte_Prm_HwTq4MeasHwTq4PrtclFltPassStep_Val(void)
{
  return (uint16 ) Rte_Prm_HwTq4MeasHwTq4PrtclFltPassStep_Val();
}
boolean  TSC_CDD_HwTq4Meas_Rte_Prm_HwTq4MeasMovgAvrgFilEna_Logl(void)
{
  return (boolean ) Rte_Prm_HwTq4MeasMovgAvrgFilEna_Logl();
}


     /* CDD_HwTq4Meas */
      /* CDD_HwTq4Meas */

/** Per Instance Memories */
float32 *TSC_CDD_HwTq4Meas_Rte_Pim_HwTq4PrevHwTq4(void)
{
  return Rte_Pim_HwTq4PrevHwTq4();
}
uint8 *TSC_CDD_HwTq4Meas_Rte_Pim_HwTq4PrevRollgCntr(void)
{
  return Rte_Pim_HwTq4PrevRollgCntr();
}
uint8 *TSC_CDD_HwTq4Meas_Rte_Pim_HwTq4RawFastAdcIdxCntr(void)
{
  return Rte_Pim_HwTq4RawFastAdcIdxCntr();
}
HwTqOffsRec1 *TSC_CDD_HwTq4Meas_Rte_Pim_HwTq4Offs(void)
{
  return Rte_Pim_HwTq4Offs();
}
AnHwTqScaFacRec1 *TSC_CDD_HwTq4Meas_Rte_Pim_HwTq4Sca(void)
{
  return Rte_Pim_HwTq4Sca();
}



