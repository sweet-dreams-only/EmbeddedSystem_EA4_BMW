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
 *          File:  TSC_LoaMgr.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_LoaMgr.h"
#include "TSC_LoaMgr.h"















     /* Client Server Interfaces: */
Std_ReturnType TSC_LoaMgr_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
{
  return Rte_Call_SetNtcSts_Oper(NtcNr_Arg, NtcStInfo_Arg, NtcSts_Arg, DebStep_Arg);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_LoaMgr_Rte_Read_CurrMeasIdptSig_Val(uint8 *data)
{
  return Rte_Read_CurrMeasIdptSig_Val(data);
}

Std_ReturnType TSC_LoaMgr_Rte_Read_DiagcStsIvtr1Inactv_Logl(boolean *data)
{
  return Rte_Read_DiagcStsIvtr1Inactv_Logl(data);
}

Std_ReturnType TSC_LoaMgr_Rte_Read_DiagcStsIvtr2Inactv_Logl(boolean *data)
{
  return Rte_Read_DiagcStsIvtr2Inactv_Logl(data);
}

Std_ReturnType TSC_LoaMgr_Rte_Read_HwTqIdptSig_Val(uint8 *data)
{
  return Rte_Read_HwTqIdptSig_Val(data);
}

Std_ReturnType TSC_LoaMgr_Rte_Read_IvtrFetFltTyp_Val(IvtrFetFltTyp1 *data)
{
  return Rte_Read_IvtrFetFltTyp_Val(data);
}

Std_ReturnType TSC_LoaMgr_Rte_Read_LoaScaDi_Logl(boolean *data)
{
  return Rte_Read_LoaScaDi_Logl(data);
}

Std_ReturnType TSC_LoaMgr_Rte_Read_MotAgMeclIdptSig_Val(uint8 *data)
{
  return Rte_Read_MotAgMeclIdptSig_Val(data);
}

Std_ReturnType TSC_LoaMgr_Rte_Read_MotAgSnsrlsAvl_Logl(boolean *data)
{
  return Rte_Read_MotAgSnsrlsAvl_Logl(data);
}

Std_ReturnType TSC_LoaMgr_Rte_Read_TqLoaAvl_Logl(boolean *data)
{
  return Rte_Read_TqLoaAvl_Logl(data);
}

Std_ReturnType TSC_LoaMgr_Rte_Read_VehSteerMod_Val(SteerMod1 *data)
{
  return Rte_Read_VehSteerMod_Val(data);
}




Std_ReturnType TSC_LoaMgr_Rte_Write_HwTqLoaMtgtnEna_Logl(boolean data)
{
  return Rte_Write_HwTqLoaMtgtnEna_Logl(data);
}

Std_ReturnType TSC_LoaMgr_Rte_Write_LoaRateLim_Val(float32 data)
{
  return Rte_Write_LoaRateLim_Val(data);
}

Std_ReturnType TSC_LoaMgr_Rte_Write_LoaSca_Val(float32 data)
{
  return Rte_Write_LoaSca_Val(data);
}

Std_ReturnType TSC_LoaMgr_Rte_Write_LoaSt_Val(LoaSt1 data)
{
  return Rte_Write_LoaSt_Val(data);
}

Std_ReturnType TSC_LoaMgr_Rte_Write_MotAgLoaMtgtnEna_Logl(boolean data)
{
  return Rte_Write_MotAgLoaMtgtnEna_Logl(data);
}

Std_ReturnType TSC_LoaMgr_Rte_Write_MotAndThermProtnLoaMod_Val(uint8 data)
{
  return Rte_Write_MotAndThermProtnLoaMod_Val(data);
}





     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */





float32  TSC_LoaMgr_Rte_Prm_LoaMgrCurrIvtrMtgtnRate_Val(void)
{
  return (float32 ) Rte_Prm_LoaMgrCurrIvtrMtgtnRate_Val();
}
float32  TSC_LoaMgr_Rte_Prm_LoaMgrCurrIvtrMtgtnSca_Val(void)
{
  return (float32 ) Rte_Prm_LoaMgrCurrIvtrMtgtnSca_Val();
}
float32  TSC_LoaMgr_Rte_Prm_LoaMgrCurrMeasMtgtnRate_Val(void)
{
  return (float32 ) Rte_Prm_LoaMgrCurrMeasMtgtnRate_Val();
}
float32  TSC_LoaMgr_Rte_Prm_LoaMgrCurrMeasMtgtnSca_Val(void)
{
  return (float32 ) Rte_Prm_LoaMgrCurrMeasMtgtnSca_Val();
}
float32  TSC_LoaMgr_Rte_Prm_LoaMgrFadeOutStRate_Val(void)
{
  return (float32 ) Rte_Prm_LoaMgrFadeOutStRate_Val();
}
float32  TSC_LoaMgr_Rte_Prm_LoaMgrIvtrMtgtnRate_Val(void)
{
  return (float32 ) Rte_Prm_LoaMgrIvtrMtgtnRate_Val();
}
float32  TSC_LoaMgr_Rte_Prm_LoaMgrIvtrMtgtnSca_Val(void)
{
  return (float32 ) Rte_Prm_LoaMgrIvtrMtgtnSca_Val();
}
float32  TSC_LoaMgr_Rte_Prm_LoaMgrLimdStRate_Val(void)
{
  return (float32 ) Rte_Prm_LoaMgrLimdStRate_Val();
}
float32  TSC_LoaMgr_Rte_Prm_LoaMgrLimdStSca_Val(void)
{
  return (float32 ) Rte_Prm_LoaMgrLimdStSca_Val();
}
float32  TSC_LoaMgr_Rte_Prm_LoaMgrMotAgMtgtnRate_Val(void)
{
  return (float32 ) Rte_Prm_LoaMgrMotAgMtgtnRate_Val();
}
float32  TSC_LoaMgr_Rte_Prm_LoaMgrMotAgMtgtnSca_Val(void)
{
  return (float32 ) Rte_Prm_LoaMgrMotAgMtgtnSca_Val();
}
uint8  TSC_LoaMgr_Rte_Prm_LoaMgrCurrMeasIdptSig0Resp_Val(void)
{
  return (uint8 ) Rte_Prm_LoaMgrCurrMeasIdptSig0Resp_Val();
}
uint8  TSC_LoaMgr_Rte_Prm_LoaMgrCurrMeasIdptSig1Resp_Val(void)
{
  return (uint8 ) Rte_Prm_LoaMgrCurrMeasIdptSig1Resp_Val();
}
uint8  TSC_LoaMgr_Rte_Prm_LoaMgrCurrMeasIdptSig2Resp_Val(void)
{
  return (uint8 ) Rte_Prm_LoaMgrCurrMeasIdptSig2Resp_Val();
}
uint8  TSC_LoaMgr_Rte_Prm_LoaMgrCurrMeasIdptSigFltThd_Val(void)
{
  return (uint8 ) Rte_Prm_LoaMgrCurrMeasIdptSigFltThd_Val();
}
uint8  TSC_LoaMgr_Rte_Prm_LoaMgrHwTqIdptSig0NoTqLoaResp_Val(void)
{
  return (uint8 ) Rte_Prm_LoaMgrHwTqIdptSig0NoTqLoaResp_Val();
}
uint8  TSC_LoaMgr_Rte_Prm_LoaMgrHwTqIdptSig1NoTqLoaResp_Val(void)
{
  return (uint8 ) Rte_Prm_LoaMgrHwTqIdptSig1NoTqLoaResp_Val();
}
uint8  TSC_LoaMgr_Rte_Prm_LoaMgrHwTqIdptSig2Resp_Val(void)
{
  return (uint8 ) Rte_Prm_LoaMgrHwTqIdptSig2Resp_Val();
}
uint8  TSC_LoaMgr_Rte_Prm_LoaMgrHwTqIdptSig3Resp_Val(void)
{
  return (uint8 ) Rte_Prm_LoaMgrHwTqIdptSig3Resp_Val();
}
uint8  TSC_LoaMgr_Rte_Prm_LoaMgrHwTqIdptSig4Resp_Val(void)
{
  return (uint8 ) Rte_Prm_LoaMgrHwTqIdptSig4Resp_Val();
}
uint8  TSC_LoaMgr_Rte_Prm_LoaMgrHwTqIdptSigFltThd_Val(void)
{
  return (uint8 ) Rte_Prm_LoaMgrHwTqIdptSigFltThd_Val();
}
uint8  TSC_LoaMgr_Rte_Prm_LoaMgrHwTqLoaAvlResp_Val(void)
{
  return (uint8 ) Rte_Prm_LoaMgrHwTqLoaAvlResp_Val();
}
uint8  TSC_LoaMgr_Rte_Prm_LoaMgrIvtrIdptSig0Resp_Val(void)
{
  return (uint8 ) Rte_Prm_LoaMgrIvtrIdptSig0Resp_Val();
}
uint8  TSC_LoaMgr_Rte_Prm_LoaMgrIvtrIdptSig1Resp_Val(void)
{
  return (uint8 ) Rte_Prm_LoaMgrIvtrIdptSig1Resp_Val();
}
uint8  TSC_LoaMgr_Rte_Prm_LoaMgrIvtrIdptSig2Resp_Val(void)
{
  return (uint8 ) Rte_Prm_LoaMgrIvtrIdptSig2Resp_Val();
}
uint8  TSC_LoaMgr_Rte_Prm_LoaMgrIvtrIdptSigFltThd_Val(void)
{
  return (uint8 ) Rte_Prm_LoaMgrIvtrIdptSigFltThd_Val();
}
uint8  TSC_LoaMgr_Rte_Prm_LoaMgrMotAgAvlSnsrlsResp_Val(void)
{
  return (uint8 ) Rte_Prm_LoaMgrMotAgAvlSnsrlsResp_Val();
}
uint8  TSC_LoaMgr_Rte_Prm_LoaMgrMotAgIdptSig0NoSnsrlsResp_Val(void)
{
  return (uint8 ) Rte_Prm_LoaMgrMotAgIdptSig0NoSnsrlsResp_Val();
}
uint8  TSC_LoaMgr_Rte_Prm_LoaMgrMotAgIdptSig1NoSnsrlsResp_Val(void)
{
  return (uint8 ) Rte_Prm_LoaMgrMotAgIdptSig1NoSnsrlsResp_Val();
}
uint8  TSC_LoaMgr_Rte_Prm_LoaMgrMotAgIdptSig2Resp_Val(void)
{
  return (uint8 ) Rte_Prm_LoaMgrMotAgIdptSig2Resp_Val();
}
uint8  TSC_LoaMgr_Rte_Prm_LoaMgrMotAgIdptSig3Resp_Val(void)
{
  return (uint8 ) Rte_Prm_LoaMgrMotAgIdptSig3Resp_Val();
}
uint8  TSC_LoaMgr_Rte_Prm_LoaMgrMotAgIdptSigFltThd_Val(void)
{
  return (uint8 ) Rte_Prm_LoaMgrMotAgIdptSigFltThd_Val();
}
boolean  TSC_LoaMgr_Rte_Prm_LoaMgrCurrIvtrMtgtnScaZeroEna_Logl(void)
{
  return (boolean ) Rte_Prm_LoaMgrCurrIvtrMtgtnScaZeroEna_Logl();
}
boolean  TSC_LoaMgr_Rte_Prm_LoaMgrCurrMeasMtgtnScaZeroEna_Logl(void)
{
  return (boolean ) Rte_Prm_LoaMgrCurrMeasMtgtnScaZeroEna_Logl();
}
boolean  TSC_LoaMgr_Rte_Prm_LoaMgrIvtrMtgtnScaZeroEna_Logl(void)
{
  return (boolean ) Rte_Prm_LoaMgrIvtrMtgtnScaZeroEna_Logl();
}
boolean  TSC_LoaMgr_Rte_Prm_LoaMgrMotAgMtgtnScaZeroEna_Logl(void)
{
  return (boolean ) Rte_Prm_LoaMgrMotAgMtgtnScaZeroEna_Logl();
}


     /* LoaMgr */
      /* LoaMgr */
void TSC_LoaMgr_Rte_Enter_LoaMgrExclusiveArea(void)
{
  Rte_Enter_LoaMgrExclusiveArea();
}
void TSC_LoaMgr_Rte_Exit_LoaMgrExclusiveArea(void)
{
  Rte_Exit_LoaMgrExclusiveArea();
}

/** Per Instance Memories */
uint8 *TSC_LoaMgr_Rte_Pim_PrevCurrMeasIdptSigResp(void)
{
  return Rte_Pim_PrevCurrMeasIdptSigResp();
}
uint8 *TSC_LoaMgr_Rte_Pim_PrevCurrMeasIdptSigVal(void)
{
  return Rte_Pim_PrevCurrMeasIdptSigVal();
}
uint8 *TSC_LoaMgr_Rte_Pim_PrevHwTqIdptSigResp(void)
{
  return Rte_Pim_PrevHwTqIdptSigResp();
}
uint8 *TSC_LoaMgr_Rte_Pim_PrevHwTqIdptSigVal(void)
{
  return Rte_Pim_PrevHwTqIdptSigVal();
}
uint8 *TSC_LoaMgr_Rte_Pim_PrevIvtrIdptSigResp(void)
{
  return Rte_Pim_PrevIvtrIdptSigResp();
}
uint8 *TSC_LoaMgr_Rte_Pim_PrevIvtrIdptSigVal(void)
{
  return Rte_Pim_PrevIvtrIdptSigVal();
}
uint8 *TSC_LoaMgr_Rte_Pim_PrevMotAgMeclIdptSigResp(void)
{
  return Rte_Pim_PrevMotAgMeclIdptSigResp();
}
uint8 *TSC_LoaMgr_Rte_Pim_PrevMotAgMeclIdptSigVal(void)
{
  return Rte_Pim_PrevMotAgMeclIdptSigVal();
}
uint8 *TSC_LoaMgr_Rte_Pim_PrevVltgModSrc(void)
{
  return Rte_Pim_PrevVltgModSrc();
}
boolean *TSC_LoaMgr_Rte_Pim_PrevCurrMeasLoaStSwMtgtnEna(void)
{
  return Rte_Pim_PrevCurrMeasLoaStSwMtgtnEna();
}
boolean *TSC_LoaMgr_Rte_Pim_PrevHwTqLoaStSwMtgtnEna(void)
{
  return Rte_Pim_PrevHwTqLoaStSwMtgtnEna();
}
boolean *TSC_LoaMgr_Rte_Pim_PrevIvtrLoaStSwMtgtnEna(void)
{
  return Rte_Pim_PrevIvtrLoaStSwMtgtnEna();
}
boolean *TSC_LoaMgr_Rte_Pim_PrevMotAgLoaMtgtnEna(void)
{
  return Rte_Pim_PrevMotAgLoaMtgtnEna();
}
boolean *TSC_LoaMgr_Rte_Pim_PrevMotAgLoaStSwMtgtnEna(void)
{
  return Rte_Pim_PrevMotAgLoaStSwMtgtnEna();
}



