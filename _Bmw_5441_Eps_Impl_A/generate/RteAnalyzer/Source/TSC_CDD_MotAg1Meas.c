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
 *          File:  TSC_CDD_MotAg1Meas.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_CDD_MotAg1Meas.h"
#include "TSC_CDD_MotAg1Meas.h"















     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */
Std_ReturnType TSC_CDD_MotAg1Meas_Rte_Call_MotAg1CoeffTbl_SetRamBlockStatus(boolean RamBlockStatus_Arg)
{
  return Rte_Call_MotAg1CoeffTbl_SetRamBlockStatus(RamBlockStatus_Arg);
}


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_CDD_MotAg1Meas_Rte_Read_MotAg1Polarity_Val(sint8 *data)
{
  return Rte_Read_MotAg1Polarity_Val(data);
}








     /* Client Server Interfaces: */
Std_ReturnType TSC_CDD_MotAg1Meas_Rte_Call_IoHwAb_SetFctGpioMotAg1Clk_Oper(void)
{
  return Rte_Call_IoHwAb_SetFctGpioMotAg1Clk_Oper();
}
Std_ReturnType TSC_CDD_MotAg1Meas_Rte_Call_IoHwAb_SetFctGpioMotAg1Cs_Oper(void)
{
  return Rte_Call_IoHwAb_SetFctGpioMotAg1Cs_Oper();
}
Std_ReturnType TSC_CDD_MotAg1Meas_Rte_Call_IoHwAb_SetFctGpioMotAg1Mosi_Oper(void)
{
  return Rte_Call_IoHwAb_SetFctGpioMotAg1Mosi_Oper();
}
Std_ReturnType TSC_CDD_MotAg1Meas_Rte_Call_IoHwAb_SetGpioMotAg1Clk_Oper(boolean PinSt_Arg)
{
  return Rte_Call_IoHwAb_SetGpioMotAg1Clk_Oper(PinSt_Arg);
}
Std_ReturnType TSC_CDD_MotAg1Meas_Rte_Call_IoHwAb_SetGpioMotAg1Cs_Oper(boolean PinSt_Arg)
{
  return Rte_Call_IoHwAb_SetGpioMotAg1Cs_Oper(PinSt_Arg);
}
Std_ReturnType TSC_CDD_MotAg1Meas_Rte_Call_IoHwAb_SetGpioMotAg1Mosi_Oper(boolean PinSt_Arg)
{
  return Rte_Call_IoHwAb_SetGpioMotAg1Mosi_Oper(PinSt_Arg);
}


     /* Service calls */
Std_ReturnType TSC_CDD_MotAg1Meas_Rte_Call_MotAg1CoeffTbl_GetErrorStatus(NvM_RequestResultType *ErrorStatus_Arg)
{
  return Rte_Call_MotAg1CoeffTbl_GetErrorStatus(ErrorStatus_Arg);
}


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_CDD_MotAg1Meas_Rte_Read_MotAg1ErrReg_Val(uint32 *data)
{
  return Rte_Read_MotAg1ErrReg_Val(data);
}

Std_ReturnType TSC_CDD_MotAg1Meas_Rte_Read_MotAg1ParFltCnt_Val(uint16 *data)
{
  return Rte_Read_MotAg1ParFltCnt_Val(data);
}

Std_ReturnType TSC_CDD_MotAg1Meas_Rte_Read_MotAg1SpiMecl_Val(u0p16 *data)
{
  return Rte_Read_MotAg1SpiMecl_Val(data);
}

Std_ReturnType TSC_CDD_MotAg1Meas_Rte_Read_MotAg1TurnCntrReg_Val(uint32 *data)
{
  return Rte_Read_MotAg1TurnCntrReg_Val(data);
}

Std_ReturnType TSC_CDD_MotAg1Meas_Rte_Read_MotAg1VltgFltCnt_Val(uint16 *data)
{
  return Rte_Read_MotAg1VltgFltCnt_Val(data);
}

Std_ReturnType TSC_CDD_MotAg1Meas_Rte_Read_MotAg1WarnReg_Val(uint32 *data)
{
  return Rte_Read_MotAg1WarnReg_Val(data);
}

Std_ReturnType TSC_CDD_MotAg1Meas_Rte_Read_MotAg4Mecl_Val(u0p16 *data)
{
  return Rte_Read_MotAg4Mecl_Val(data);
}




Std_ReturnType TSC_CDD_MotAg1Meas_Rte_Write_MotAg1MeclQlfr_Val(SigQlfr1 data)
{
  return Rte_Write_MotAg1MeclQlfr_Val(data);
}

Std_ReturnType TSC_CDD_MotAg1Meas_Rte_Write_MotAg1QepFaild_Logl(boolean data)
{
  return Rte_Write_MotAg1QepFaild_Logl(data);
}

Std_ReturnType TSC_CDD_MotAg1Meas_Rte_Write_MotAg1TurnCntr_Val(float32 data)
{
  return Rte_Write_MotAg1TurnCntr_Val(data);
}

Std_ReturnType TSC_CDD_MotAg1Meas_Rte_Write_MotAg1TurnCntrQlfr_Val(SigQlfr1 data)
{
  return Rte_Write_MotAg1TurnCntrQlfr_Val(data);
}

Std_ReturnType TSC_CDD_MotAg1Meas_Rte_Write_MotAg1TurnCntrRollgCntr_Val(uint8 data)
{
  return Rte_Write_MotAg1TurnCntrRollgCntr_Val(data);
}





     /* Client Server Interfaces: */
Std_ReturnType TSC_CDD_MotAg1Meas_Rte_Call_CnvSnpshtData_s16_Oper(uint32 *SnpshtDataCnvd_Arg, sint16 SnpshtData_Arg)
{
  return Rte_Call_CnvSnpshtData_s16_Oper(SnpshtDataCnvd_Arg, SnpshtData_Arg);
}
Std_ReturnType TSC_CDD_MotAg1Meas_Rte_Call_CnvSnpshtData_u16_Oper(uint32 *SnpshtDataCnvd_Arg, uint16 SnpshtData_Arg)
{
  return Rte_Call_CnvSnpshtData_u16_Oper(SnpshtDataCnvd_Arg, SnpshtData_Arg);
}
Std_ReturnType TSC_CDD_MotAg1Meas_Rte_Call_GetNtcQlfrSts_Oper(NtcNr1 NtcNr_Arg, SigQlfr1 *NtcQlfr_Arg)
{
  return Rte_Call_GetNtcQlfrSts_Oper(NtcNr_Arg, NtcQlfr_Arg);
}
Std_ReturnType TSC_CDD_MotAg1Meas_Rte_Call_SetNtcStsAndSnpshtData_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg, uint32 SpclSnpshtData0_Arg, uint32 SpclSnpshtData1_Arg, uint32 SpclSnpshtData2_Arg)
{
  return Rte_Call_SetNtcStsAndSnpshtData_Oper(NtcNr_Arg, NtcStInfo_Arg, NtcSts_Arg, DebStep_Arg, SpclSnpshtData0_Arg, SpclSnpshtData1_Arg, SpclSnpshtData2_Arg);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */





u0p16  TSC_CDD_MotAg1Meas_Rte_Prm_MotAg1MeasOffs_Val(void)
{
  return (u0p16 ) Rte_Prm_MotAg1MeasOffs_Val();
}
uint16  TSC_CDD_MotAg1Meas_Rte_Prm_MotAg1MeasSnsrIfErrNtcMask_Val(void)
{
  return (uint16 ) Rte_Prm_MotAg1MeasSnsrIfErrNtcMask_Val();
}

Ary1D_f32_26 * TSC_CDD_MotAg1Meas_Rte_CData_MotAg1CoeffTblDft(void)
{
  return (Ary1D_f32_26 *) Rte_CData_MotAg1CoeffTblDft();
}

     /* CDD_MotAg1Meas */
      /* CDD_MotAg1Meas */

/** Per Instance Memories */
uint32 *TSC_CDD_MotAg1Meas_Rte_Pim_MotAg1QepFaildCntr(void)
{
  return Rte_Pim_MotAg1QepFaildCntr();
}
uint32 *TSC_CDD_MotAg1Meas_Rte_Pim_dMotAg1MeasMotAg1RawAgReg(void)
{
  return Rte_Pim_dMotAg1MeasMotAg1RawAgReg();
}
uint32 *TSC_CDD_MotAg1Meas_Rte_Pim_dMotAg1MeasMotAg1RawErrReg(void)
{
  return Rte_Pim_dMotAg1MeasMotAg1RawErrReg();
}
uint32 *TSC_CDD_MotAg1Meas_Rte_Pim_dMotAg1MeasMotAg1RawStsReg(void)
{
  return Rte_Pim_dMotAg1MeasMotAg1RawStsReg();
}
uint32 *TSC_CDD_MotAg1Meas_Rte_Pim_dMotAg1MeasMotAg1RawTurnCntrReg(void)
{
  return Rte_Pim_dMotAg1MeasMotAg1RawTurnCntrReg();
}
uint32 *TSC_CDD_MotAg1Meas_Rte_Pim_dMotAg1MeasMotAg1RawWarnReg(void)
{
  return Rte_Pim_dMotAg1MeasMotAg1RawWarnReg();
}
sint32 *TSC_CDD_MotAg1Meas_Rte_Pim_MotAg1InitOffs(void)
{
  return Rte_Pim_MotAg1InitOffs();
}
uint16 *TSC_CDD_MotAg1Meas_Rte_Pim_MotAg1ParFltCntNtcPrev(void)
{
  return Rte_Pim_MotAg1ParFltCntNtcPrev();
}
uint16 *TSC_CDD_MotAg1Meas_Rte_Pim_MotAg1ParFltCntPrev(void)
{
  return Rte_Pim_MotAg1ParFltCntPrev();
}
u0p16 *TSC_CDD_MotAg1Meas_Rte_Pim_MotAg1PrevSpiMecl(void)
{
  return Rte_Pim_MotAg1PrevSpiMecl();
}
u0p16 *TSC_CDD_MotAg1Meas_Rte_Pim_MotAg1RawMeclPrev(void)
{
  return Rte_Pim_MotAg1RawMeclPrev();
}
uint16 *TSC_CDD_MotAg1Meas_Rte_Pim_MotAg1TurnCntrParFltCntNtcPrev(void)
{
  return Rte_Pim_MotAg1TurnCntrParFltCntNtcPrev();
}
uint16 *TSC_CDD_MotAg1Meas_Rte_Pim_MotAg1TurnCntrParFltCntPrev(void)
{
  return Rte_Pim_MotAg1TurnCntrParFltCntPrev();
}
uint16 *TSC_CDD_MotAg1Meas_Rte_Pim_MotAg1VltgFltCntNtcPrev(void)
{
  return Rte_Pim_MotAg1VltgFltCntNtcPrev();
}
uint16 *TSC_CDD_MotAg1Meas_Rte_Pim_MotAg1VltgFltCntPrev(void)
{
  return Rte_Pim_MotAg1VltgFltCntPrev();
}
u0p16 *TSC_CDD_MotAg1Meas_Rte_Pim_dMotAg1MeasMotAg1Delta(void)
{
  return Rte_Pim_dMotAg1MeasMotAg1Delta();
}
uint16 *TSC_CDD_MotAg1Meas_Rte_Pim_dMotAg1MeasMotAg1RtOffs(void)
{
  return Rte_Pim_dMotAg1MeasMotAg1RtOffs();
}
sint16 *TSC_CDD_MotAg1Meas_Rte_Pim_MotAg1PrevTCUpd(void)
{
  return Rte_Pim_MotAg1PrevTCUpd();
}
sint16 *TSC_CDD_MotAg1Meas_Rte_Pim_MotAg1TurnCntrPrev(void)
{
  return Rte_Pim_MotAg1TurnCntrPrev();
}
uint8 *TSC_CDD_MotAg1Meas_Rte_Pim_MotAg1InitOffsCntr(void)
{
  return Rte_Pim_MotAg1InitOffsCntr();
}
uint8 *TSC_CDD_MotAg1Meas_Rte_Pim_MotAg1MeclRollgCntrPrev(void)
{
  return Rte_Pim_MotAg1MeclRollgCntrPrev();
}
uint8 *TSC_CDD_MotAg1Meas_Rte_Pim_MotAg1TurnCntrRollgCntrPrev(void)
{
  return Rte_Pim_MotAg1TurnCntrRollgCntrPrev();
}
sint8 *TSC_CDD_MotAg1Meas_Rte_Pim_MotAgMecl1Polarity(void)
{
  return Rte_Pim_MotAgMecl1Polarity();
}
boolean *TSC_CDD_MotAg1Meas_Rte_Pim_MotAg1QepFaildPrev(void)
{
  return Rte_Pim_MotAg1QepFaildPrev();
}
boolean *TSC_CDD_MotAg1Meas_Rte_Pim_dMotAg1MeasPwrRstStsLtch(void)
{
  return Rte_Pim_dMotAg1MeasPwrRstStsLtch();
}
float32 *TSC_CDD_MotAg1Meas_Rte_Pim_MotAg1CoeffTbl(void)
{
  return Rte_Pim_MotAg1CoeffTbl();
}
sm5p12 *TSC_CDD_MotAg1Meas_Rte_Pim_MotAg1CorrnTbl(void)
{
  return Rte_Pim_MotAg1CorrnTbl();
}



