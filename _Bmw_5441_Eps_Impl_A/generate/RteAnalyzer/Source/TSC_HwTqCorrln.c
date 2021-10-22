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
 *          File:  TSC_HwTqCorrln.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_HwTqCorrln.h"
#include "TSC_HwTqCorrln.h"















     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_HwTqCorrln_Rte_Read_HwTqA_Val(float32 *data)
{
  return Rte_Read_HwTqA_Val(data);
}

Std_ReturnType TSC_HwTqCorrln_Rte_Read_HwTqAQlfr_Val(SigQlfr1 *data)
{
  return Rte_Read_HwTqAQlfr_Val(data);
}

Std_ReturnType TSC_HwTqCorrln_Rte_Read_HwTqARollgCntr_Val(uint8 *data)
{
  return Rte_Read_HwTqARollgCntr_Val(data);
}

Std_ReturnType TSC_HwTqCorrln_Rte_Read_HwTqB_Val(float32 *data)
{
  return Rte_Read_HwTqB_Val(data);
}

Std_ReturnType TSC_HwTqCorrln_Rte_Read_HwTqBQlfr_Val(SigQlfr1 *data)
{
  return Rte_Read_HwTqBQlfr_Val(data);
}

Std_ReturnType TSC_HwTqCorrln_Rte_Read_HwTqBRollgCntr_Val(uint8 *data)
{
  return Rte_Read_HwTqBRollgCntr_Val(data);
}




Std_ReturnType TSC_HwTqCorrln_Rte_Write_HwTqCorrlnSts_Val(uint8 data)
{
  return Rte_Write_HwTqCorrlnSts_Val(data);
}





     /* Client Server Interfaces: */
Std_ReturnType TSC_HwTqCorrln_Rte_Call_GetNtcQlfrSts_Oper(NtcNr1 NtcNr_Arg, SigQlfr1 *NtcQlfr_Arg)
{
  return Rte_Call_GetNtcQlfrSts_Oper(NtcNr_Arg, NtcQlfr_Arg);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */

void TSC_HwTqCorrln_Rte_IrvWrite_HwTqCorrlnPer1_HwTqChAAvl(boolean data)
{
  Rte_IrvWrite_HwTqCorrlnPer1_HwTqChAAvl( data);
}








Std_ReturnType TSC_HwTqCorrln_Rte_Write_HwTqChACorrlnTraErr_Val(float32 data)
{
  return Rte_Write_HwTqChACorrlnTraErr_Val(data);
}

Std_ReturnType TSC_HwTqCorrln_Rte_Write_HwTqIdptSig_Val(uint8 data)
{
  return Rte_Write_HwTqIdptSig_Val(data);
}





     /* Client Server Interfaces: */
Std_ReturnType TSC_HwTqCorrln_Rte_Call_FltInj_u08_Oper(uint8 *SigPah_Arg, uint16 LocnKey_Arg)
{
  return Rte_Call_FltInj_u08_Oper(SigPah_Arg, LocnKey_Arg);
}
Std_ReturnType TSC_HwTqCorrln_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
{
  return Rte_Call_SetNtcSts_Oper(NtcNr_Arg, NtcStInfo_Arg, NtcSts_Arg, DebStep_Arg);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */
boolean TSC_HwTqCorrln_Rte_IrvRead_HwTqCorrlnPer2_HwTqChAAvl(void)
{
return Rte_IrvRead_HwTqCorrlnPer2_HwTqChAAvl();
}

void TSC_HwTqCorrln_Rte_IrvWrite_HwTqCorrlnPer2_HwTqChATqSumLim(float32 data)
{
  Rte_IrvWrite_HwTqCorrlnPer2_HwTqChATqSumLim( data);
}





Std_ReturnType TSC_HwTqCorrln_Rte_Read_HwTqChA_Val(float32 *data)
{
  return Rte_Read_HwTqChA_Val(data);
}








     /* Client Server Interfaces: */


     /* Service calls */
Std_ReturnType TSC_HwTqCorrln_Rte_Call_HwTqChACmnModCmpLpFilSt_SetRamBlockStatus(boolean RamBlockStatus_Arg)
{
  return Rte_Call_HwTqChACmnModCmpLpFilSt_SetRamBlockStatus(RamBlockStatus_Arg);
}


     /* Mode Interfaces */




     /* Inter-Runnable variables */
float32 TSC_HwTqCorrln_Rte_IrvRead_HwTqCorrlnPer3_HwTqChATqSumLim(void)
{
return Rte_IrvRead_HwTqCorrlnPer3_HwTqChATqSumLim();
}





float32  TSC_HwTqCorrln_Rte_Prm_HwTqCorrlnChACmnModCmpLpFilActvnThd_Val(void)
{
  return (float32 ) Rte_Prm_HwTqCorrlnChACmnModCmpLpFilActvnThd_Val();
}
float32  TSC_HwTqCorrln_Rte_Prm_HwTqCorrlnChACmnModCmpLpFilFrq_Val(void)
{
  return (float32 ) Rte_Prm_HwTqCorrlnChACmnModCmpLpFilFrq_Val();
}
float32  TSC_HwTqCorrln_Rte_Prm_HwTqCorrlnChACmnModCmpLpFilOutpLim_Val(void)
{
  return (float32 ) Rte_Prm_HwTqCorrlnChACmnModCmpLpFilOutpLim_Val();
}
float32  TSC_HwTqCorrln_Rte_Prm_HwTqCorrlnChAImdtCorrlnChkFailThd_Val(void)
{
  return (float32 ) Rte_Prm_HwTqCorrlnChAImdtCorrlnChkFailThd_Val();
}
float32  TSC_HwTqCorrln_Rte_Prm_HwTqCorrlnChAImdtCorrlnChkPassThd_Val(void)
{
  return (float32 ) Rte_Prm_HwTqCorrlnChAImdtCorrlnChkPassThd_Val();
}
float32  TSC_HwTqCorrln_Rte_Prm_HwTqCorrlnChAStabStClrFltThd_Val(void)
{
  return (float32 ) Rte_Prm_HwTqCorrlnChAStabStClrFltThd_Val();
}
float32  TSC_HwTqCorrln_Rte_Prm_HwTqCorrlnChAStabStLpFilFrq_Val(void)
{
  return (float32 ) Rte_Prm_HwTqCorrlnChAStabStLpFilFrq_Val();
}
float32  TSC_HwTqCorrln_Rte_Prm_HwTqCorrlnChAStabStSetFltThd_Val(void)
{
  return (float32 ) Rte_Prm_HwTqCorrlnChAStabStSetFltThd_Val();
}
float32  TSC_HwTqCorrln_Rte_Prm_HwTqCorrlnChATqSumMaxLim_Val(void)
{
  return (float32 ) Rte_Prm_HwTqCorrlnChATqSumMaxLim_Val();
}
float32  TSC_HwTqCorrln_Rte_Prm_HwTqCorrlnChATraSumClrFltThd_Val(void)
{
  return (float32 ) Rte_Prm_HwTqCorrlnChATraSumClrFltThd_Val();
}
float32  TSC_HwTqCorrln_Rte_Prm_HwTqCorrlnChATraSumSetFltThd_Val(void)
{
  return (float32 ) Rte_Prm_HwTqCorrlnChATraSumSetFltThd_Val();
}
Ary1D_u5p11_17 * TSC_HwTqCorrln_Rte_Prm_HwTqCorrlnChATraLpFilX_Ary1D(void)
{
  return (Ary1D_u5p11_17 *) Rte_Prm_HwTqCorrlnChATraLpFilX_Ary1D();
}
Ary1D_u6p10_17 * TSC_HwTqCorrln_Rte_Prm_HwTqCorrlnChATraLpFilY_Ary1D(void)
{
  return (Ary1D_u6p10_17 *) Rte_Prm_HwTqCorrlnChATraLpFilY_Ary1D();
}

float32  TSC_HwTqCorrln_Rte_CData_HwTqChACmnModCmpLpFilStDft(void)
{
  return (float32 ) Rte_CData_HwTqChACmnModCmpLpFilStDft();
}

     /* HwTqCorrln */
      /* HwTqCorrln */

/** Per Instance Memories */
float32 *TSC_HwTqCorrln_Rte_Pim_HwTqChACmnModCmpLpFilSt(void)
{
  return Rte_Pim_HwTqChACmnModCmpLpFilSt();
}
uint8 *TSC_HwTqCorrln_Rte_Pim_HwTqARollgCntrPrev(void)
{
  return Rte_Pim_HwTqARollgCntrPrev();
}
uint8 *TSC_HwTqCorrln_Rte_Pim_HwTqAStallCntrPrev(void)
{
  return Rte_Pim_HwTqAStallCntrPrev();
}
uint8 *TSC_HwTqCorrln_Rte_Pim_HwTqBRollgCntrPrev(void)
{
  return Rte_Pim_HwTqBRollgCntrPrev();
}
uint8 *TSC_HwTqCorrln_Rte_Pim_HwTqBStallCntrPrev(void)
{
  return Rte_Pim_HwTqBStallCntrPrev();
}
boolean *TSC_HwTqCorrln_Rte_Pim_HwTqChAImdtCorrlnChk(void)
{
  return Rte_Pim_HwTqChAImdtCorrlnChk();
}
FilLpRec1 *TSC_HwTqCorrln_Rte_Pim_HwTqChACmnModCmpLpFil(void)
{
  return Rte_Pim_HwTqChACmnModCmpLpFil();
}
FilLpRec1 *TSC_HwTqCorrln_Rte_Pim_HwTqChAStabStLpFil(void)
{
  return Rte_Pim_HwTqChAStabStLpFil();
}
FilLpRec1 *TSC_HwTqCorrln_Rte_Pim_HwTqChATraLpFil(void)
{
  return Rte_Pim_HwTqChATraLpFil();
}



