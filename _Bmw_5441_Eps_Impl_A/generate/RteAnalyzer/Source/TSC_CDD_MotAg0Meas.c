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
 *          File:  TSC_CDD_MotAg0Meas.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_CDD_MotAg0Meas.h"
#include "TSC_CDD_MotAg0Meas.h"















     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */
Std_ReturnType TSC_CDD_MotAg0Meas_Rte_Call_MotAg0CoeffTbl_SetRamBlockStatus(boolean RamBlockStatus_Arg)
{
  return Rte_Call_MotAg0CoeffTbl_SetRamBlockStatus(RamBlockStatus_Arg);
}


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_CDD_MotAg0Meas_Rte_Read_MotAg0Polarity_Val(sint8 *data)
{
  return Rte_Read_MotAg0Polarity_Val(data);
}




Std_ReturnType TSC_CDD_MotAg0Meas_Rte_Write_MotAg0SnsrCfgAdr_Val(uint32 data)
{
  return Rte_Write_MotAg0SnsrCfgAdr_Val(data);
}





     /* Client Server Interfaces: */
Std_ReturnType TSC_CDD_MotAg0Meas_Rte_Call_IoHwAb_SetFctGpioMotAg0Clk_Oper(void)
{
  return Rte_Call_IoHwAb_SetFctGpioMotAg0Clk_Oper();
}
Std_ReturnType TSC_CDD_MotAg0Meas_Rte_Call_IoHwAb_SetFctGpioMotAg0Cs_Oper(void)
{
  return Rte_Call_IoHwAb_SetFctGpioMotAg0Cs_Oper();
}
Std_ReturnType TSC_CDD_MotAg0Meas_Rte_Call_IoHwAb_SetFctGpioMotAg0Mosi_Oper(void)
{
  return Rte_Call_IoHwAb_SetFctGpioMotAg0Mosi_Oper();
}
Std_ReturnType TSC_CDD_MotAg0Meas_Rte_Call_IoHwAb_SetGpioMotAg0Clk_Oper(boolean PinSt_Arg)
{
  return Rte_Call_IoHwAb_SetGpioMotAg0Clk_Oper(PinSt_Arg);
}
Std_ReturnType TSC_CDD_MotAg0Meas_Rte_Call_IoHwAb_SetGpioMotAg0Cs_Oper(boolean PinSt_Arg)
{
  return Rte_Call_IoHwAb_SetGpioMotAg0Cs_Oper(PinSt_Arg);
}
Std_ReturnType TSC_CDD_MotAg0Meas_Rte_Call_IoHwAb_SetGpioMotAg0Mosi_Oper(boolean PinSt_Arg)
{
  return Rte_Call_IoHwAb_SetGpioMotAg0Mosi_Oper(PinSt_Arg);
}


     /* Service calls */
Std_ReturnType TSC_CDD_MotAg0Meas_Rte_Call_MotAg0CoeffTbl_GetErrorStatus(NvM_RequestResultType *ErrorStatus_Arg)
{
  return Rte_Call_MotAg0CoeffTbl_GetErrorStatus(ErrorStatus_Arg);
}


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_CDD_MotAg0Meas_Rte_Read_MotAg0ErrReg_Val(uint32 *data)
{
  return Rte_Read_MotAg0ErrReg_Val(data);
}

Std_ReturnType TSC_CDD_MotAg0Meas_Rte_Read_MotAg0ParFltCnt_Val(uint16 *data)
{
  return Rte_Read_MotAg0ParFltCnt_Val(data);
}

Std_ReturnType TSC_CDD_MotAg0Meas_Rte_Read_MotAg0SpiMecl_Val(u0p16 *data)
{
  return Rte_Read_MotAg0SpiMecl_Val(data);
}

Std_ReturnType TSC_CDD_MotAg0Meas_Rte_Read_MotAg0TurnCntrReg_Val(uint32 *data)
{
  return Rte_Read_MotAg0TurnCntrReg_Val(data);
}

Std_ReturnType TSC_CDD_MotAg0Meas_Rte_Read_MotAg0VltgFltCnt_Val(uint16 *data)
{
  return Rte_Read_MotAg0VltgFltCnt_Val(data);
}

Std_ReturnType TSC_CDD_MotAg0Meas_Rte_Read_MotAg0WarnReg_Val(uint32 *data)
{
  return Rte_Read_MotAg0WarnReg_Val(data);
}

Std_ReturnType TSC_CDD_MotAg0Meas_Rte_Read_MotAg3Mecl_Val(u0p16 *data)
{
  return Rte_Read_MotAg3Mecl_Val(data);
}




Std_ReturnType TSC_CDD_MotAg0Meas_Rte_Write_MotAg0MeclQlfr_Val(SigQlfr1 data)
{
  return Rte_Write_MotAg0MeclQlfr_Val(data);
}

Std_ReturnType TSC_CDD_MotAg0Meas_Rte_Write_MotAg0QepFaild_Logl(boolean data)
{
  return Rte_Write_MotAg0QepFaild_Logl(data);
}

Std_ReturnType TSC_CDD_MotAg0Meas_Rte_Write_MotAg0TurnCntr_Val(float32 data)
{
  return Rte_Write_MotAg0TurnCntr_Val(data);
}

Std_ReturnType TSC_CDD_MotAg0Meas_Rte_Write_MotAg0TurnCntrQlfr_Val(SigQlfr1 data)
{
  return Rte_Write_MotAg0TurnCntrQlfr_Val(data);
}

Std_ReturnType TSC_CDD_MotAg0Meas_Rte_Write_MotAg0TurnCntrRollgCntr_Val(uint8 data)
{
  return Rte_Write_MotAg0TurnCntrRollgCntr_Val(data);
}





     /* Client Server Interfaces: */
Std_ReturnType TSC_CDD_MotAg0Meas_Rte_Call_CnvSnpshtData_s16_Oper(uint32 *SnpshtDataCnvd_Arg, sint16 SnpshtData_Arg)
{
  return Rte_Call_CnvSnpshtData_s16_Oper(SnpshtDataCnvd_Arg, SnpshtData_Arg);
}
Std_ReturnType TSC_CDD_MotAg0Meas_Rte_Call_CnvSnpshtData_u16_Oper(uint32 *SnpshtDataCnvd_Arg, uint16 SnpshtData_Arg)
{
  return Rte_Call_CnvSnpshtData_u16_Oper(SnpshtDataCnvd_Arg, SnpshtData_Arg);
}
Std_ReturnType TSC_CDD_MotAg0Meas_Rte_Call_GetNtcQlfrSts_Oper(NtcNr1 NtcNr_Arg, SigQlfr1 *NtcQlfr_Arg)
{
  return Rte_Call_GetNtcQlfrSts_Oper(NtcNr_Arg, NtcQlfr_Arg);
}
Std_ReturnType TSC_CDD_MotAg0Meas_Rte_Call_SetNtcStsAndSnpshtData_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg, uint32 SpclSnpshtData0_Arg, uint32 SpclSnpshtData1_Arg, uint32 SpclSnpshtData2_Arg)
{
  return Rte_Call_SetNtcStsAndSnpshtData_Oper(NtcNr_Arg, NtcStInfo_Arg, NtcSts_Arg, DebStep_Arg, SpclSnpshtData0_Arg, SpclSnpshtData1_Arg, SpclSnpshtData2_Arg);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */

void TSC_CDD_MotAg0Meas_Rte_IrvWrite_MotAg0MeasPer2_MotAg0Qlfr(SigQlfr1 data)
{
  Rte_IrvWrite_MotAg0MeasPer2_MotAg0Qlfr( data);
}
void TSC_CDD_MotAg0Meas_Rte_IrvWrite_MotAg0MeasPer2_TurnCntr0Qlfr(SigQlfr1 data)
{
  Rte_IrvWrite_MotAg0MeasPer2_TurnCntr0Qlfr( data);
}





Std_ReturnType TSC_CDD_MotAg0Meas_Rte_Read_EgyModSt_Val(EgyModSt1 *data)
{
  return Rte_Read_EgyModSt_Val(data);
}

Std_ReturnType TSC_CDD_MotAg0Meas_Rte_Read_MotAg1MeclQlfr_Val(SigQlfr1 *data)
{
  return Rte_Read_MotAg1MeclQlfr_Val(data);
}

Std_ReturnType TSC_CDD_MotAg0Meas_Rte_Read_MotAg1TurnCntrQlfr_Val(SigQlfr1 *data)
{
  return Rte_Read_MotAg1TurnCntrQlfr_Val(data);
}

Std_ReturnType TSC_CDD_MotAg0Meas_Rte_Read_TurnCntrIdptSig_Val(uint8 *data)
{
  return Rte_Read_TurnCntrIdptSig_Val(data);
}








     /* Client Server Interfaces: */
Std_ReturnType TSC_CDD_MotAg0Meas_Rte_Call_MotAg0SnsrCfgDmaStrt_Oper(void)
{
  return Rte_Call_MotAg0SnsrCfgDmaStrt_Oper();
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */
SigQlfr1 TSC_CDD_MotAg0Meas_Rte_IrvRead_MotAg0MeasPer3_MotAg0Qlfr(void)
{
return Rte_IrvRead_MotAg0MeasPer3_MotAg0Qlfr();
}
SigQlfr1 TSC_CDD_MotAg0Meas_Rte_IrvRead_MotAg0MeasPer3_TurnCntr0Qlfr(void)
{
return Rte_IrvRead_MotAg0MeasPer3_TurnCntr0Qlfr();
}





uint16  TSC_CDD_MotAg0Meas_Rte_Prm_MotAg0MeasSnsrIfErrNtcMask_Val(void)
{
  return (uint16 ) Rte_Prm_MotAg0MeasSnsrIfErrNtcMask_Val();
}

Ary1D_f32_26 * TSC_CDD_MotAg0Meas_Rte_CData_MotAg0CoeffTblDft(void)
{
  return (Ary1D_f32_26 *) Rte_CData_MotAg0CoeffTblDft();
}

     /* CDD_MotAg0Meas */
      /* CDD_MotAg0Meas */

/** Per Instance Memories */
uint32 *TSC_CDD_MotAg0Meas_Rte_Pim_MotAg0QepFaildCntr(void)
{
  return Rte_Pim_MotAg0QepFaildCntr();
}
uint32 *TSC_CDD_MotAg0Meas_Rte_Pim_MotAg0SnsrCfg(void)
{
  return Rte_Pim_MotAg0SnsrCfg();
}
uint32 *TSC_CDD_MotAg0Meas_Rte_Pim_dMotAg0MeasMotAg0RawAgReg(void)
{
  return Rte_Pim_dMotAg0MeasMotAg0RawAgReg();
}
uint32 *TSC_CDD_MotAg0Meas_Rte_Pim_dMotAg0MeasMotAg0RawErrReg(void)
{
  return Rte_Pim_dMotAg0MeasMotAg0RawErrReg();
}
uint32 *TSC_CDD_MotAg0Meas_Rte_Pim_dMotAg0MeasMotAg0RawStsReg(void)
{
  return Rte_Pim_dMotAg0MeasMotAg0RawStsReg();
}
uint32 *TSC_CDD_MotAg0Meas_Rte_Pim_dMotAg0MeasMotAg0RawTurnCntrReg(void)
{
  return Rte_Pim_dMotAg0MeasMotAg0RawTurnCntrReg();
}
uint32 *TSC_CDD_MotAg0Meas_Rte_Pim_dMotAg0MeasMotAg0RawWarnReg(void)
{
  return Rte_Pim_dMotAg0MeasMotAg0RawWarnReg();
}
sint32 *TSC_CDD_MotAg0Meas_Rte_Pim_MotAg0InitOffs(void)
{
  return Rte_Pim_MotAg0InitOffs();
}
sint32 *TSC_CDD_MotAg0Meas_Rte_Pim_dMotAg0MeasMotAg0RtOffs(void)
{
  return Rte_Pim_dMotAg0MeasMotAg0RtOffs();
}
uint16 *TSC_CDD_MotAg0Meas_Rte_Pim_MotAg0ParFltCntNtcPrev(void)
{
  return Rte_Pim_MotAg0ParFltCntNtcPrev();
}
uint16 *TSC_CDD_MotAg0Meas_Rte_Pim_MotAg0ParFltCntPrev(void)
{
  return Rte_Pim_MotAg0ParFltCntPrev();
}
u0p16 *TSC_CDD_MotAg0Meas_Rte_Pim_MotAg0PrevSpiMecl(void)
{
  return Rte_Pim_MotAg0PrevSpiMecl();
}
u0p16 *TSC_CDD_MotAg0Meas_Rte_Pim_MotAg0RawMeclPrev(void)
{
  return Rte_Pim_MotAg0RawMeclPrev();
}
uint16 *TSC_CDD_MotAg0Meas_Rte_Pim_MotAg0TurnCntrParFltCntNtcPrev(void)
{
  return Rte_Pim_MotAg0TurnCntrParFltCntNtcPrev();
}
uint16 *TSC_CDD_MotAg0Meas_Rte_Pim_MotAg0TurnCntrParFltCntPrev(void)
{
  return Rte_Pim_MotAg0TurnCntrParFltCntPrev();
}
uint16 *TSC_CDD_MotAg0Meas_Rte_Pim_MotAg0VltgFltCntNtcPrev(void)
{
  return Rte_Pim_MotAg0VltgFltCntNtcPrev();
}
uint16 *TSC_CDD_MotAg0Meas_Rte_Pim_MotAg0VltgFltCntPrev(void)
{
  return Rte_Pim_MotAg0VltgFltCntPrev();
}
u0p16 *TSC_CDD_MotAg0Meas_Rte_Pim_dMotAg0MeasMotAg0Delta(void)
{
  return Rte_Pim_dMotAg0MeasMotAg0Delta();
}
sint16 *TSC_CDD_MotAg0Meas_Rte_Pim_MotAg0PrevTCUpd(void)
{
  return Rte_Pim_MotAg0PrevTCUpd();
}
sint16 *TSC_CDD_MotAg0Meas_Rte_Pim_MotAg0TurnCntrPrev(void)
{
  return Rte_Pim_MotAg0TurnCntrPrev();
}
uint8 *TSC_CDD_MotAg0Meas_Rte_Pim_MotAg0InitOffsCntr(void)
{
  return Rte_Pim_MotAg0InitOffsCntr();
}
uint8 *TSC_CDD_MotAg0Meas_Rte_Pim_MotAg0MeclRollgCntrPrev(void)
{
  return Rte_Pim_MotAg0MeclRollgCntrPrev();
}
uint8 *TSC_CDD_MotAg0Meas_Rte_Pim_MotAg0TurnCntrRollgCntrPrev(void)
{
  return Rte_Pim_MotAg0TurnCntrRollgCntrPrev();
}
uint8 *TSC_CDD_MotAg0Meas_Rte_Pim_MotAgCtrlRegCfg(void)
{
  return Rte_Pim_MotAgCtrlRegCfg();
}
MotAgSnsrCfgSt1 *TSC_CDD_MotAg0Meas_Rte_Pim_MotAgSnsrCfgSt(void)
{
  return Rte_Pim_MotAgSnsrCfgSt();
}
sint8 *TSC_CDD_MotAg0Meas_Rte_Pim_MotAgMecl0Polarity(void)
{
  return Rte_Pim_MotAgMecl0Polarity();
}
boolean *TSC_CDD_MotAg0Meas_Rte_Pim_MotAg0QepFaildPrev(void)
{
  return Rte_Pim_MotAg0QepFaildPrev();
}
boolean *TSC_CDD_MotAg0Meas_Rte_Pim_dMotAg0MeasPwrRstStsLtch(void)
{
  return Rte_Pim_dMotAg0MeasPwrRstStsLtch();
}
float32 *TSC_CDD_MotAg0Meas_Rte_Pim_MotAg0CoeffTbl(void)
{
  return Rte_Pim_MotAg0CoeffTbl();
}
sm5p12 *TSC_CDD_MotAg0Meas_Rte_Pim_MotAg0CorrnTbl(void)
{
  return Rte_Pim_MotAg0CorrnTbl();
}



