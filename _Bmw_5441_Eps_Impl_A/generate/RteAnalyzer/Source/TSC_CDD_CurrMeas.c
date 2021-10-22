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
 *          File:  TSC_CDD_CurrMeas.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_CDD_CurrMeas.h"
#include "TSC_CDD_CurrMeas.h"















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
Std_ReturnType TSC_CDD_CurrMeas_Rte_Call_CurrMeasEolGainCalSetABC_SetRamBlockStatus(boolean RamBlockStatus_Arg)
{
  return Rte_Call_CurrMeasEolGainCalSetABC_SetRamBlockStatus(RamBlockStatus_Arg);
}


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */
Std_ReturnType TSC_CDD_CurrMeas_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
{
  return Rte_Call_SetNtcSts_Oper(NtcNr_Arg, NtcStInfo_Arg, NtcSts_Arg, DebStep_Arg);
}


     /* Service calls */
Std_ReturnType TSC_CDD_CurrMeas_Rte_Call_CurrMeasEolGainCalSetABC_GetErrorStatus(NvM_RequestResultType *ErrorStatus_Arg)
{
  return Rte_Call_CurrMeasEolGainCalSetABC_GetErrorStatus(ErrorStatus_Arg);
}
Std_ReturnType TSC_CDD_CurrMeas_Rte_Call_CurrMeasEolOffsCalSetABC_GetErrorStatus(NvM_RequestResultType *ErrorStatus_Arg)
{
  return Rte_Call_CurrMeasEolOffsCalSetABC_GetErrorStatus(ErrorStatus_Arg);
}


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */
Std_ReturnType TSC_CDD_CurrMeas_Rte_Call_CurrMeasEolOffsCalSetABC_SetRamBlockStatus(boolean RamBlockStatus_Arg)
{
  return Rte_Call_CurrMeasEolOffsCalSetABC_SetRamBlockStatus(RamBlockStatus_Arg);
}


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_CDD_CurrMeas_Rte_Read_BrdgVltg_Val(float32 *data)
{
  return Rte_Read_BrdgVltg_Val(data);
}

Std_ReturnType TSC_CDD_CurrMeas_Rte_Read_DiagcStsIvtr1Inactv_Logl(boolean *data)
{
  return Rte_Read_DiagcStsIvtr1Inactv_Logl(data);
}

Std_ReturnType TSC_CDD_CurrMeas_Rte_Read_MotCurrAdcVlyA_Val(float32 *data)
{
  return Rte_Read_MotCurrAdcVlyA_Val(data);
}

Std_ReturnType TSC_CDD_CurrMeas_Rte_Read_MotCurrAdcVlyB_Val(float32 *data)
{
  return Rte_Read_MotCurrAdcVlyB_Val(data);
}

Std_ReturnType TSC_CDD_CurrMeas_Rte_Read_MotCurrAdcVlyC_Val(float32 *data)
{
  return Rte_Read_MotCurrAdcVlyC_Val(data);
}

Std_ReturnType TSC_CDD_CurrMeas_Rte_Read_MotVelMrf_Val(float32 *data)
{
  return Rte_Read_MotVelMrf_Val(data);
}

Std_ReturnType TSC_CDD_CurrMeas_Rte_Read_VehSpd_Val(float32 *data)
{
  return Rte_Read_VehSpd_Val(data);
}

Std_ReturnType TSC_CDD_CurrMeas_Rte_Read_VehSpdVld_Logl(boolean *data)
{
  return Rte_Read_VehSpdVld_Logl(data);
}




Std_ReturnType TSC_CDD_CurrMeas_Rte_Write_MotCurrEolCalSt_Val(MotCurrEolCalSt2 data)
{
  return Rte_Write_MotCurrEolCalSt_Val(data);
}





     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_CDD_CurrMeas_Rte_Read_Ntc5DErrCnt_Val(uint16 *data)
{
  return Rte_Read_Ntc5DErrCnt_Val(data);
}

Std_ReturnType TSC_CDD_CurrMeas_Rte_Read_StrtUpSt_Val(uint8 *data)
{
  return Rte_Read_StrtUpSt_Val(data);
}

Std_ReturnType TSC_CDD_CurrMeas_Rte_Read_SysSt_Val(SysSt1 *data)
{
  return Rte_Read_SysSt_Val(data);
}




Std_ReturnType TSC_CDD_CurrMeas_Rte_Write_CurrMeasWrmIninTestCmpl_Logl(boolean data)
{
  return Rte_Write_CurrMeasWrmIninTestCmpl_Logl(data);
}

Std_ReturnType TSC_CDD_CurrMeas_Rte_Write_MotCurrQlfr1_Val(SigQlfr1 data)
{
  return Rte_Write_MotCurrQlfr1_Val(data);
}





     /* Client Server Interfaces: */
Std_ReturnType TSC_CDD_CurrMeas_Rte_Call_GetNtcQlfrSts_Oper(NtcNr1 NtcNr_Arg, SigQlfr1 *NtcQlfr_Arg)
{
  return Rte_Call_GetNtcQlfrSts_Oper(NtcNr_Arg, NtcQlfr_Arg);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */





float32  TSC_CDD_CurrMeas_Rte_Prm_CurrMeasEolGainMax_Val(void)
{
  return (float32 ) Rte_Prm_CurrMeasEolGainMax_Val();
}
float32  TSC_CDD_CurrMeas_Rte_Prm_CurrMeasEolGainMin_Val(void)
{
  return (float32 ) Rte_Prm_CurrMeasEolGainMin_Val();
}
float32  TSC_CDD_CurrMeas_Rte_Prm_CurrMeasEolGainNom_Val(void)
{
  return (float32 ) Rte_Prm_CurrMeasEolGainNom_Val();
}
float32  TSC_CDD_CurrMeas_Rte_Prm_CurrMeasEolGainNumer_Val(void)
{
  return (float32 ) Rte_Prm_CurrMeasEolGainNumer_Val();
}
float32  TSC_CDD_CurrMeas_Rte_Prm_CurrMeasEolMaxMotVel_Val(void)
{
  return (float32 ) Rte_Prm_CurrMeasEolMaxMotVel_Val();
}
float32  TSC_CDD_CurrMeas_Rte_Prm_CurrMeasEolOffsHiBrdgVltgMin_Val(void)
{
  return (float32 ) Rte_Prm_CurrMeasEolOffsHiBrdgVltgMin_Val();
}
float32  TSC_CDD_CurrMeas_Rte_Prm_CurrMeasEolOffsMax_Val(void)
{
  return (float32 ) Rte_Prm_CurrMeasEolOffsMax_Val();
}
float32  TSC_CDD_CurrMeas_Rte_Prm_CurrMeasEolOffsMin_Val(void)
{
  return (float32 ) Rte_Prm_CurrMeasEolOffsMin_Val();
}
float32  TSC_CDD_CurrMeas_Rte_Prm_CurrMeasEolOffsNom_Val(void)
{
  return (float32 ) Rte_Prm_CurrMeasEolOffsNom_Val();
}
float32  TSC_CDD_CurrMeas_Rte_Prm_CurrMeasMotCurrAdcVlyWrmIninMax_Val(void)
{
  return (float32 ) Rte_Prm_CurrMeasMotCurrAdcVlyWrmIninMax_Val();
}
float32  TSC_CDD_CurrMeas_Rte_Prm_CurrMeasMotCurrAdcVlyWrmIninMin_Val(void)
{
  return (float32 ) Rte_Prm_CurrMeasMotCurrAdcVlyWrmIninMin_Val();
}
uint32  TSC_CDD_CurrMeas_Rte_Prm_CurrMeasEolFixdPwmPerd_Val(void)
{
  return (uint32 ) Rte_Prm_CurrMeasEolFixdPwmPerd_Val();
}
uint32  TSC_CDD_CurrMeas_Rte_Prm_CurrMeasEolOffsHiCmuOffs_Val(void)
{
  return (uint32 ) Rte_Prm_CurrMeasEolOffsHiCmuOffs_Val();
}
uint32  TSC_CDD_CurrMeas_Rte_Prm_CurrMeasEolOffsLoCmuOffs_Val(void)
{
  return (uint32 ) Rte_Prm_CurrMeasEolOffsLoCmuOffs_Val();
}
uint32  TSC_CDD_CurrMeas_Rte_Prm_CurrMeasMinRqrdPhaOnTi_Val(void)
{
  return (uint32 ) Rte_Prm_CurrMeasMinRqrdPhaOnTi_Val();
}
uint32  TSC_CDD_CurrMeas_Rte_Prm_CurrMeasMotAgCompuDly_Val(void)
{
  return (uint32 ) Rte_Prm_CurrMeasMotAgCompuDly_Val();
}
uint16  TSC_CDD_CurrMeas_Rte_Prm_CurrMeasEolGainNrOfSample_Val(void)
{
  return (uint16 ) Rte_Prm_CurrMeasEolGainNrOfSample_Val();
}
uint16  TSC_CDD_CurrMeas_Rte_Prm_CurrMeasEolOffsNrOfSample_Val(void)
{
  return (uint16 ) Rte_Prm_CurrMeasEolOffsNrOfSample_Val();
}
uint16  TSC_CDD_CurrMeas_Rte_Prm_CurrMeasNtc0x05DFailStep_Val(void)
{
  return (uint16 ) Rte_Prm_CurrMeasNtc0x05DFailStep_Val();
}
uint16  TSC_CDD_CurrMeas_Rte_Prm_CurrMeasNtc0x05DPassStep_Val(void)
{
  return (uint16 ) Rte_Prm_CurrMeasNtc0x05DPassStep_Val();
}
uint8  TSC_CDD_CurrMeas_Rte_Prm_CurrMeasEolTranCntrThd_Val(void)
{
  return (uint8 ) Rte_Prm_CurrMeasEolTranCntrThd_Val();
}
uint8  TSC_CDD_CurrMeas_Rte_Prm_SysGlbPrmMotPoleCnt_Val(void)
{
  return (uint8 ) Rte_Prm_SysGlbPrmMotPoleCnt_Val();
}

CurrMeasEolGainCal3PhaRec1 * TSC_CDD_CurrMeas_Rte_CData_CurrMeasEolGainCalSetABCDft(void)
{
  return (CurrMeasEolGainCal3PhaRec1 *) Rte_CData_CurrMeasEolGainCalSetABCDft();
}
CurrMeasEolOffsCal3PhaRec1 * TSC_CDD_CurrMeas_Rte_CData_CurrMeasEolOffsCalSetABCDft(void)
{
  return (CurrMeasEolOffsCal3PhaRec1 *) Rte_CData_CurrMeasEolOffsCalSetABCDft();
}

     /* CDD_CurrMeas */
      /* CDD_CurrMeas */

/** Per Instance Memories */
float32 *TSC_CDD_CurrMeas_Rte_Pim_BrdgVltgSumPrev(void)
{
  return Rte_Pim_BrdgVltgSumPrev();
}
float32 *TSC_CDD_CurrMeas_Rte_Pim_EolOffsHiBrdgVltg(void)
{
  return Rte_Pim_EolOffsHiBrdgVltg();
}
float32 *TSC_CDD_CurrMeas_Rte_Pim_MotCurrEolGainA(void)
{
  return Rte_Pim_MotCurrEolGainA();
}
float32 *TSC_CDD_CurrMeas_Rte_Pim_MotCurrEolGainB(void)
{
  return Rte_Pim_MotCurrEolGainB();
}
float32 *TSC_CDD_CurrMeas_Rte_Pim_MotCurrEolGainC(void)
{
  return Rte_Pim_MotCurrEolGainC();
}
float32 *TSC_CDD_CurrMeas_Rte_Pim_MotCurrOffsDeltaA(void)
{
  return Rte_Pim_MotCurrOffsDeltaA();
}
float32 *TSC_CDD_CurrMeas_Rte_Pim_MotCurrOffsDeltaB(void)
{
  return Rte_Pim_MotCurrOffsDeltaB();
}
float32 *TSC_CDD_CurrMeas_Rte_Pim_MotCurrOffsDeltaC(void)
{
  return Rte_Pim_MotCurrOffsDeltaC();
}
float32 *TSC_CDD_CurrMeas_Rte_Pim_MotCurrOffsHiAvrgA(void)
{
  return Rte_Pim_MotCurrOffsHiAvrgA();
}
float32 *TSC_CDD_CurrMeas_Rte_Pim_MotCurrOffsHiAvrgB(void)
{
  return Rte_Pim_MotCurrOffsHiAvrgB();
}
float32 *TSC_CDD_CurrMeas_Rte_Pim_MotCurrOffsHiAvrgC(void)
{
  return Rte_Pim_MotCurrOffsHiAvrgC();
}
float32 *TSC_CDD_CurrMeas_Rte_Pim_MotCurrOffsLoAvrgA(void)
{
  return Rte_Pim_MotCurrOffsLoAvrgA();
}
float32 *TSC_CDD_CurrMeas_Rte_Pim_MotCurrOffsLoAvrgB(void)
{
  return Rte_Pim_MotCurrOffsLoAvrgB();
}
float32 *TSC_CDD_CurrMeas_Rte_Pim_MotCurrOffsLoAvrgC(void)
{
  return Rte_Pim_MotCurrOffsLoAvrgC();
}
float32 *TSC_CDD_CurrMeas_Rte_Pim_MotCurrOffsZeroAvrgA(void)
{
  return Rte_Pim_MotCurrOffsZeroAvrgA();
}
float32 *TSC_CDD_CurrMeas_Rte_Pim_MotCurrOffsZeroAvrgB(void)
{
  return Rte_Pim_MotCurrOffsZeroAvrgB();
}
float32 *TSC_CDD_CurrMeas_Rte_Pim_MotCurrOffsZeroAvrgC(void)
{
  return Rte_Pim_MotCurrOffsZeroAvrgC();
}
float32 *TSC_CDD_CurrMeas_Rte_Pim_MotCurrSumAPrev(void)
{
  return Rte_Pim_MotCurrSumAPrev();
}
float32 *TSC_CDD_CurrMeas_Rte_Pim_MotCurrSumBPrev(void)
{
  return Rte_Pim_MotCurrSumBPrev();
}
float32 *TSC_CDD_CurrMeas_Rte_Pim_MotCurrSumCPrev(void)
{
  return Rte_Pim_MotCurrSumCPrev();
}
float32 *TSC_CDD_CurrMeas_Rte_Pim_TmpMotCurrAdcVlySum1Prev(void)
{
  return Rte_Pim_TmpMotCurrAdcVlySum1Prev();
}
uint16 *TSC_CDD_CurrMeas_Rte_Pim_GainEolAvrgCntrPrev(void)
{
  return Rte_Pim_GainEolAvrgCntrPrev();
}
uint16 *TSC_CDD_CurrMeas_Rte_Pim_MotCtrlNtc5DErrCntPrev(void)
{
  return Rte_Pim_MotCtrlNtc5DErrCntPrev();
}
uint16 *TSC_CDD_CurrMeas_Rte_Pim_Ntc5DErrCnt2MilliSecPrev(void)
{
  return Rte_Pim_Ntc5DErrCnt2MilliSecPrev();
}
uint16 *TSC_CDD_CurrMeas_Rte_Pim_OffsEolAvrgCntrPrev(void)
{
  return Rte_Pim_OffsEolAvrgCntrPrev();
}
uint16 *TSC_CDD_CurrMeas_Rte_Pim_PhaOnTiErrCntPrev(void)
{
  return Rte_Pim_PhaOnTiErrCntPrev();
}
uint8 *TSC_CDD_CurrMeas_Rte_Pim_EolGainSts(void)
{
  return Rte_Pim_EolGainSts();
}
uint8 *TSC_CDD_CurrMeas_Rte_Pim_EolGainTranCntrPrev(void)
{
  return Rte_Pim_EolGainTranCntrPrev();
}
uint8 *TSC_CDD_CurrMeas_Rte_Pim_EolOffsSts(void)
{
  return Rte_Pim_EolOffsSts();
}
uint8 *TSC_CDD_CurrMeas_Rte_Pim_EolOffsTranCntrPrev(void)
{
  return Rte_Pim_EolOffsTranCntrPrev();
}
MotCurrEolCalSt2 *TSC_CDD_CurrMeas_Rte_Pim_MotCurrEolCalStPrev(void)
{
  return Rte_Pim_MotCurrEolCalStPrev();
}
uint8 *TSC_CDD_CurrMeas_Rte_Pim_MotCurrRollgCnt1Prev(void)
{
  return Rte_Pim_MotCurrRollgCnt1Prev();
}
boolean *TSC_CDD_CurrMeas_Rte_Pim_MotCurrEolOffsProcFlg(void)
{
  return Rte_Pim_MotCurrEolOffsProcFlg();
}
boolean *TSC_CDD_CurrMeas_Rte_Pim_WrmIninTestCmplPrev(void)
{
  return Rte_Pim_WrmIninTestCmplPrev();
}
CurrMeasEolGainCal3PhaRec1 *TSC_CDD_CurrMeas_Rte_Pim_CurrMeasEolGainCalSetABC(void)
{
  return Rte_Pim_CurrMeasEolGainCalSetABC();
}
CurrMeasEolOffsCal3PhaRec1 *TSC_CDD_CurrMeas_Rte_Pim_CurrMeasEolOffsCalSetABC(void)
{
  return Rte_Pim_CurrMeasEolOffsCalSetABC();
}



