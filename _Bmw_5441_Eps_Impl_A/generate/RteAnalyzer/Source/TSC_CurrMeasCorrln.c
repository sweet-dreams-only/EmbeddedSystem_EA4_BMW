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
 *          File:  TSC_CurrMeasCorrln.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_CurrMeasCorrln.h"
#include "TSC_CurrMeasCorrln.h"















     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_CurrMeasCorrln_Rte_Read_DiagcStsIvtr1Inactv_Logl(boolean *data)
{
  return Rte_Read_DiagcStsIvtr1Inactv_Logl(data);
}

Std_ReturnType TSC_CurrMeasCorrln_Rte_Read_MotCurrCorrdA_Val(float32 *data)
{
  return Rte_Read_MotCurrCorrdA_Val(data);
}

Std_ReturnType TSC_CurrMeasCorrln_Rte_Read_MotCurrCorrdB_Val(float32 *data)
{
  return Rte_Read_MotCurrCorrdB_Val(data);
}

Std_ReturnType TSC_CurrMeasCorrln_Rte_Read_MotCurrCorrdC_Val(float32 *data)
{
  return Rte_Read_MotCurrCorrdC_Val(data);
}

Std_ReturnType TSC_CurrMeasCorrln_Rte_Read_MotCurrEolCalSt_Val(MotCurrEolCalSt2 *data)
{
  return Rte_Read_MotCurrEolCalSt_Val(data);
}

Std_ReturnType TSC_CurrMeasCorrln_Rte_Read_MotCurrRollgCntr1_Val(uint8 *data)
{
  return Rte_Read_MotCurrRollgCntr1_Val(data);
}

Std_ReturnType TSC_CurrMeasCorrln_Rte_Read_SysSt_Val(SysSt1 *data)
{
  return Rte_Read_SysSt_Val(data);
}




Std_ReturnType TSC_CurrMeasCorrln_Rte_Write_CurrMeasCorrlnSts_Val(uint8 data)
{
  return Rte_Write_CurrMeasCorrlnSts_Val(data);
}

Std_ReturnType TSC_CurrMeasCorrln_Rte_Write_CurrMeasIdptSig_Val(uint8 data)
{
  return Rte_Write_CurrMeasIdptSig_Val(data);
}

Std_ReturnType TSC_CurrMeasCorrln_Rte_Write_CurrMotSumABC_Val(float32 data)
{
  return Rte_Write_CurrMotSumABC_Val(data);
}





     /* Client Server Interfaces: */
Std_ReturnType TSC_CurrMeasCorrln_Rte_Call_FltInj_u08_Oper(uint8 *SigPah_Arg, uint16 LocnKey_Arg)
{
  return Rte_Call_FltInj_u08_Oper(SigPah_Arg, LocnKey_Arg);
}
Std_ReturnType TSC_CurrMeasCorrln_Rte_Call_GetNtcQlfrSts_Oper(NtcNr1 NtcNr_Arg, SigQlfr1 *NtcQlfr_Arg)
{
  return Rte_Call_GetNtcQlfrSts_Oper(NtcNr_Arg, NtcQlfr_Arg);
}
Std_ReturnType TSC_CurrMeasCorrln_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
{
  return Rte_Call_SetNtcSts_Oper(NtcNr_Arg, NtcStInfo_Arg, NtcSts_Arg, DebStep_Arg);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */





float32  TSC_CurrMeasCorrln_Rte_Prm_CurrMeasCorrlnMaxErrCurr_Val(void)
{
  return (float32 ) Rte_Prm_CurrMeasCorrlnMaxErrCurr_Val();
}
uint16  TSC_CurrMeasCorrln_Rte_Prm_CurrMeasCorrlnNtc0x04DFailStep_Val(void)
{
  return (uint16 ) Rte_Prm_CurrMeasCorrlnNtc0x04DFailStep_Val();
}
uint16  TSC_CurrMeasCorrln_Rte_Prm_CurrMeasCorrlnNtc0x04DPassStep_Val(void)
{
  return (uint16 ) Rte_Prm_CurrMeasCorrlnNtc0x04DPassStep_Val();
}
uint8  TSC_CurrMeasCorrln_Rte_Prm_CurrMeasCorrlnMaxStallCntr_Val(void)
{
  return (uint8 ) Rte_Prm_CurrMeasCorrlnMaxStallCntr_Val();
}


     /* CurrMeasCorrln */
      /* CurrMeasCorrln */

/** Per Instance Memories */
uint8 *TSC_CurrMeasCorrln_Rte_Pim_Snsr0RollgCntPrev(void)
{
  return Rte_Pim_Snsr0RollgCntPrev();
}
uint8 *TSC_CurrMeasCorrln_Rte_Pim_Snsr0StallCntPrev(void)
{
  return Rte_Pim_Snsr0StallCntPrev();
}
boolean *TSC_CurrMeasCorrln_Rte_Pim_LongTermCorrlnStsABC(void)
{
  return Rte_Pim_LongTermCorrlnStsABC();
}



