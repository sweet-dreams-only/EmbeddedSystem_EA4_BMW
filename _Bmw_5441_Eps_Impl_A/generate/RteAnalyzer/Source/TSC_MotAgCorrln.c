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
 *          File:  TSC_MotAgCorrln.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_MotAgCorrln.h"
#include "TSC_MotAgCorrln.h"















     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_MotAgCorrln_Rte_Read_MotAgAMecl_Val(u0p16 *data)
{
  return Rte_Read_MotAgAMecl_Val(data);
}

Std_ReturnType TSC_MotAgCorrln_Rte_Read_MotAgAMeclQlfr_Val(SigQlfr1 *data)
{
  return Rte_Read_MotAgAMeclQlfr_Val(data);
}

Std_ReturnType TSC_MotAgCorrln_Rte_Read_MotAgAMeclRollgCntr_Val(uint8 *data)
{
  return Rte_Read_MotAgAMeclRollgCntr_Val(data);
}

Std_ReturnType TSC_MotAgCorrln_Rte_Read_MotAgBMecl_Val(u0p16 *data)
{
  return Rte_Read_MotAgBMecl_Val(data);
}

Std_ReturnType TSC_MotAgCorrln_Rte_Read_MotAgBMeclQlfr_Val(SigQlfr1 *data)
{
  return Rte_Read_MotAgBMeclQlfr_Val(data);
}

Std_ReturnType TSC_MotAgCorrln_Rte_Read_MotAgBMeclRollgCntr_Val(uint8 *data)
{
  return Rte_Read_MotAgBMeclRollgCntr_Val(data);
}




Std_ReturnType TSC_MotAgCorrln_Rte_Write_MotAgMeclCorrlnSt_Val(uint8 data)
{
  return Rte_Write_MotAgMeclCorrlnSt_Val(data);
}

Std_ReturnType TSC_MotAgCorrln_Rte_Write_MotAgMeclIdptSig_Val(uint8 data)
{
  return Rte_Write_MotAgMeclIdptSig_Val(data);
}





     /* Client Server Interfaces: */
Std_ReturnType TSC_MotAgCorrln_Rte_Call_FltInj_u08_Oper(uint8 *SigPah_Arg, uint16 LocnKey_Arg)
{
  return Rte_Call_FltInj_u08_Oper(SigPah_Arg, LocnKey_Arg);
}
Std_ReturnType TSC_MotAgCorrln_Rte_Call_GetNtcQlfrSts_Oper(NtcNr1 NtcNr_Arg, SigQlfr1 *NtcQlfr_Arg)
{
  return Rte_Call_GetNtcQlfrSts_Oper(NtcNr_Arg, NtcQlfr_Arg);
}
Std_ReturnType TSC_MotAgCorrln_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
{
  return Rte_Call_SetNtcSts_Oper(NtcNr_Arg, NtcStInfo_Arg, NtcSts_Arg, DebStep_Arg);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */





uint8  TSC_MotAgCorrln_Rte_Prm_SysGlbPrmMotPoleCnt_Val(void)
{
  return (uint8 ) Rte_Prm_SysGlbPrmMotPoleCnt_Val();
}


     /* MotAgCorrln */
      /* MotAgCorrln */

/** Per Instance Memories */
u0p16 *TSC_MotAgCorrln_Rte_Pim_MotAgCorrlnErrThd(void)
{
  return Rte_Pim_MotAgCorrlnErrThd();
}
uint8 *TSC_MotAgCorrln_Rte_Pim_MotAgCorrlnMotAgARollgCntPrev(void)
{
  return Rte_Pim_MotAgCorrlnMotAgARollgCntPrev();
}
uint8 *TSC_MotAgCorrln_Rte_Pim_MotAgCorrlnMotAgAStallCntPrev(void)
{
  return Rte_Pim_MotAgCorrlnMotAgAStallCntPrev();
}
uint8 *TSC_MotAgCorrln_Rte_Pim_MotAgCorrlnMotAgBRollgCntPrev(void)
{
  return Rte_Pim_MotAgCorrlnMotAgBRollgCntPrev();
}
uint8 *TSC_MotAgCorrln_Rte_Pim_MotAgCorrlnMotAgBStallCntPrev(void)
{
  return Rte_Pim_MotAgCorrlnMotAgBStallCntPrev();
}
boolean *TSC_MotAgCorrln_Rte_Pim_dMotAgCorrlnMotAgABOk(void)
{
  return Rte_Pim_dMotAgCorrlnMotAgABOk();
}



