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
 *          File:  TSC_GateDrv0Ctrl.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_GateDrv0Ctrl.h"
#include "TSC_GateDrv0Ctrl.h"















     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_GateDrv0Ctrl_Rte_Read_StrtUpSt_Val(uint8 *data)
{
  return Rte_Read_StrtUpSt_Val(data);
}

Std_ReturnType TSC_GateDrv0Ctrl_Rte_Read_SysSt_Val(SysSt1 *data)
{
  return Rte_Read_SysSt_Val(data);
}








     /* Client Server Interfaces: */
Std_ReturnType TSC_GateDrv0Ctrl_Rte_Call_IoHwAb_GetGpioMotDrvr0Diag_Oper(boolean *PinSt_Arg)
{
  return Rte_Call_IoHwAb_GetGpioMotDrvr0Diag_Oper(PinSt_Arg);
}
Std_ReturnType TSC_GateDrv0Ctrl_Rte_Call_IoHwAb_SetGpioGateDrv0Rst_Oper(boolean PinSt_Arg)
{
  return Rte_Call_IoHwAb_SetGpioGateDrv0Rst_Oper(PinSt_Arg);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */

void TSC_GateDrv0Ctrl_Rte_IrvWrite_GateDrv0CtrlPer1_GateDrv0Ena(boolean data)
{
  Rte_IrvWrite_GateDrv0CtrlPer1_GateDrv0Ena( data);
}
void TSC_GateDrv0Ctrl_Rte_IrvWrite_GateDrv0CtrlPer1_GateDrv0PhaReasbnDiagcEna(boolean data)
{
  Rte_IrvWrite_GateDrv0CtrlPer1_GateDrv0PhaReasbnDiagcEna( data);
}
void TSC_GateDrv0Ctrl_Rte_IrvWrite_GateDrv0CtrlPer1_Ivtr0PhyFltInpActv(boolean data)
{
  Rte_IrvWrite_GateDrv0CtrlPer1_Ivtr0PhyFltInpActv( data);
}





Std_ReturnType TSC_GateDrv0Ctrl_Rte_Read_Ivtr1PwrDiscnctFltSts_Logl(boolean *data)
{
  return Rte_Read_Ivtr1PwrDiscnctFltSts_Logl(data);
}

Std_ReturnType TSC_GateDrv0Ctrl_Rte_Read_PhaOnTiMeasdA_Val(uint32 *data)
{
  return Rte_Read_PhaOnTiMeasdA_Val(data);
}

Std_ReturnType TSC_GateDrv0Ctrl_Rte_Read_PhaOnTiMeasdB_Val(uint32 *data)
{
  return Rte_Read_PhaOnTiMeasdB_Val(data);
}

Std_ReturnType TSC_GateDrv0Ctrl_Rte_Read_PhaOnTiMeasdC_Val(uint32 *data)
{
  return Rte_Read_PhaOnTiMeasdC_Val(data);
}

Std_ReturnType TSC_GateDrv0Ctrl_Rte_Read_PhaOnTiSumA_Val(uint32 *data)
{
  return Rte_Read_PhaOnTiSumA_Val(data);
}

Std_ReturnType TSC_GateDrv0Ctrl_Rte_Read_PhaOnTiSumB_Val(uint32 *data)
{
  return Rte_Read_PhaOnTiSumB_Val(data);
}

Std_ReturnType TSC_GateDrv0Ctrl_Rte_Read_PhaOnTiSumC_Val(uint32 *data)
{
  return Rte_Read_PhaOnTiSumC_Val(data);
}




Std_ReturnType TSC_GateDrv0Ctrl_Rte_Write_DiagcStsIvtr1Inactv_Logl(boolean data)
{
  return Rte_Write_DiagcStsIvtr1Inactv_Logl(data);
}

Std_ReturnType TSC_GateDrv0Ctrl_Rte_Write_IvtrFetFltPha_Val(IvtrFetFltPha1 data)
{
  return Rte_Write_IvtrFetFltPha_Val(data);
}

Std_ReturnType TSC_GateDrv0Ctrl_Rte_Write_IvtrFetFltTyp_Val(IvtrFetFltTyp1 data)
{
  return Rte_Write_IvtrFetFltTyp_Val(data);
}

Std_ReturnType TSC_GateDrv0Ctrl_Rte_Write_MotDrvErrA_Val(float32 data)
{
  return Rte_Write_MotDrvErrA_Val(data);
}

Std_ReturnType TSC_GateDrv0Ctrl_Rte_Write_MotDrvErrB_Val(float32 data)
{
  return Rte_Write_MotDrvErrB_Val(data);
}

Std_ReturnType TSC_GateDrv0Ctrl_Rte_Write_MotDrvErrC_Val(float32 data)
{
  return Rte_Write_MotDrvErrC_Val(data);
}

Std_ReturnType TSC_GateDrv0Ctrl_Rte_Write_MotDrvr0IninTestCmpl_Logl(boolean data)
{
  return Rte_Write_MotDrvr0IninTestCmpl_Logl(data);
}





     /* Client Server Interfaces: */
Std_ReturnType TSC_GateDrv0Ctrl_Rte_Call_GetNtcQlfrSts_Oper(NtcNr1 NtcNr_Arg, SigQlfr1 *NtcQlfr_Arg)
{
  return Rte_Call_GetNtcQlfrSts_Oper(NtcNr_Arg, NtcQlfr_Arg);
}
Std_ReturnType TSC_GateDrv0Ctrl_Rte_Call_IoHwAb_SetGpioSysFlt2A_Oper(boolean PinSt_Arg)
{
  return Rte_Call_IoHwAb_SetGpioSysFlt2A_Oper(PinSt_Arg);
}
Std_ReturnType TSC_GateDrv0Ctrl_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
{
  return Rte_Call_SetNtcSts_Oper(NtcNr_Arg, NtcStInfo_Arg, NtcSts_Arg, DebStep_Arg);
}
Std_ReturnType TSC_GateDrv0Ctrl_Rte_Call_SetNtcStsAndSnpshtData_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg, uint32 SpclSnpshtData0_Arg, uint32 SpclSnpshtData1_Arg, uint32 SpclSnpshtData2_Arg)
{
  return Rte_Call_SetNtcStsAndSnpshtData_Oper(NtcNr_Arg, NtcStInfo_Arg, NtcSts_Arg, DebStep_Arg, SpclSnpshtData0_Arg, SpclSnpshtData1_Arg, SpclSnpshtData2_Arg);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */
boolean TSC_GateDrv0Ctrl_Rte_IrvRead_GateDrv0CtrlPer2_GateDrv0Ena(void)
{
return Rte_IrvRead_GateDrv0CtrlPer2_GateDrv0Ena();
}
boolean TSC_GateDrv0Ctrl_Rte_IrvRead_GateDrv0CtrlPer2_GateDrv0PhaReasbnDiagcEna(void)
{
return Rte_IrvRead_GateDrv0CtrlPer2_GateDrv0PhaReasbnDiagcEna();
}
boolean TSC_GateDrv0Ctrl_Rte_IrvRead_GateDrv0CtrlPer2_Ivtr0PhyFltInpActv(void)
{
return Rte_IrvRead_GateDrv0CtrlPer2_Ivtr0PhyFltInpActv();
}





float32  TSC_GateDrv0Ctrl_Rte_Prm_GateDrv0CtrlErrFilFrq_Val(void)
{
  return (float32 ) Rte_Prm_GateDrv0CtrlErrFilFrq_Val();
}
uint32  TSC_GateDrv0Ctrl_Rte_Prm_GateDrv0CtrlErrOffs_Val(void)
{
  return (uint32 ) Rte_Prm_GateDrv0CtrlErrOffs_Val();
}
uint32  TSC_GateDrv0Ctrl_Rte_Prm_GateDrv0CtrlErrThd_Val(void)
{
  return (uint32 ) Rte_Prm_GateDrv0CtrlErrThd_Val();
}
uint16  TSC_GateDrv0Ctrl_Rte_Prm_GateDrv0CtrlNtcNr0x050FailStep_Val(void)
{
  return (uint16 ) Rte_Prm_GateDrv0CtrlNtcNr0x050FailStep_Val();
}
uint16  TSC_GateDrv0Ctrl_Rte_Prm_GateDrv0CtrlNtcNr0x050PassStep_Val(void)
{
  return (uint16 ) Rte_Prm_GateDrv0CtrlNtcNr0x050PassStep_Val();
}
uint16  TSC_GateDrv0Ctrl_Rte_Prm_GateDrv0CtrlNtcNr0x051FailStep_Val(void)
{
  return (uint16 ) Rte_Prm_GateDrv0CtrlNtcNr0x051FailStep_Val();
}
uint16  TSC_GateDrv0Ctrl_Rte_Prm_GateDrv0CtrlNtcNr0x051PassStep_Val(void)
{
  return (uint16 ) Rte_Prm_GateDrv0CtrlNtcNr0x051PassStep_Val();
}
uint16  TSC_GateDrv0Ctrl_Rte_Prm_GateDrv0CtrlNtcNr0x055FailStep_Val(void)
{
  return (uint16 ) Rte_Prm_GateDrv0CtrlNtcNr0x055FailStep_Val();
}
uint16  TSC_GateDrv0Ctrl_Rte_Prm_GateDrv0CtrlNtcNr0x055PassStep_Val(void)
{
  return (uint16 ) Rte_Prm_GateDrv0CtrlNtcNr0x055PassStep_Val();
}
uint16  TSC_GateDrv0Ctrl_Rte_Prm_GateDrv0CtrlUnit0Cfg2WrVal_Val(void)
{
  return (uint16 ) Rte_Prm_GateDrv0CtrlUnit0Cfg2WrVal_Val();
}
uint16  TSC_GateDrv0Ctrl_Rte_Prm_GateDrv0CtrlUnit0Cfg3WrVal_Val(void)
{
  return (uint16 ) Rte_Prm_GateDrv0CtrlUnit0Cfg3WrVal_Val();
}
uint16  TSC_GateDrv0Ctrl_Rte_Prm_GateDrv0CtrlUnit0Cfg4WrVal_Val(void)
{
  return (uint16 ) Rte_Prm_GateDrv0CtrlUnit0Cfg4WrVal_Val();
}
uint16  TSC_GateDrv0Ctrl_Rte_Prm_GateDrv0CtrlUnit0Cfg7WrVal_Val(void)
{
  return (uint16 ) Rte_Prm_GateDrv0CtrlUnit0Cfg7WrVal_Val();
}


     /* GateDrv0Ctrl */
      /* GateDrv0Ctrl */

/** Per Instance Memories */
uint32 *TSC_GateDrv0Ctrl_Rte_Pim_GateDrv0PhaOnTiSumAPrev(void)
{
  return Rte_Pim_GateDrv0PhaOnTiSumAPrev();
}
uint32 *TSC_GateDrv0Ctrl_Rte_Pim_GateDrv0PhaOnTiSumBPrev(void)
{
  return Rte_Pim_GateDrv0PhaOnTiSumBPrev();
}
uint32 *TSC_GateDrv0Ctrl_Rte_Pim_GateDrv0PhaOnTiSumCPrev(void)
{
  return Rte_Pim_GateDrv0PhaOnTiSumCPrev();
}
uint32 *TSC_GateDrv0Ctrl_Rte_Pim_GateDrv0SpiTrsmErrCntr(void)
{
  return Rte_Pim_GateDrv0SpiTrsmErrCntr();
}
uint32 *TSC_GateDrv0Ctrl_Rte_Pim_dGateDrv0CtrlGateDrv0PhaOnTiSumAExp(void)
{
  return Rte_Pim_dGateDrv0CtrlGateDrv0PhaOnTiSumAExp();
}
uint32 *TSC_GateDrv0Ctrl_Rte_Pim_dGateDrv0CtrlGateDrv0PhaOnTiSumBExp(void)
{
  return Rte_Pim_dGateDrv0CtrlGateDrv0PhaOnTiSumBExp();
}
uint32 *TSC_GateDrv0Ctrl_Rte_Pim_dGateDrv0CtrlGateDrv0PhaOnTiSumCExp(void)
{
  return Rte_Pim_dGateDrv0CtrlGateDrv0PhaOnTiSumCExp();
}
uint16 *TSC_GateDrv0Ctrl_Rte_Pim_GateDrv0Diag0Val(void)
{
  return Rte_Pim_GateDrv0Diag0Val();
}
uint16 *TSC_GateDrv0Ctrl_Rte_Pim_GateDrv0Diag1Val(void)
{
  return Rte_Pim_GateDrv0Diag1Val();
}
uint16 *TSC_GateDrv0Ctrl_Rte_Pim_GateDrv0Diag2Val(void)
{
  return Rte_Pim_GateDrv0Diag2Val();
}
uint16 *TSC_GateDrv0Ctrl_Rte_Pim_GateDrv0StsVal(void)
{
  return Rte_Pim_GateDrv0StsVal();
}
uint16 *TSC_GateDrv0Ctrl_Rte_Pim_GateDrv0VrfyRes0Val(void)
{
  return Rte_Pim_GateDrv0VrfyRes0Val();
}
uint16 *TSC_GateDrv0Ctrl_Rte_Pim_GateDrv0VrfyRes1Val(void)
{
  return Rte_Pim_GateDrv0VrfyRes1Val();
}
uint16 *TSC_GateDrv0Ctrl_Rte_Pim_dGateDrv0CtrlGateDrv0Diag0Val(void)
{
  return Rte_Pim_dGateDrv0CtrlGateDrv0Diag0Val();
}
uint16 *TSC_GateDrv0Ctrl_Rte_Pim_dGateDrv0CtrlGateDrv0Diag1Val(void)
{
  return Rte_Pim_dGateDrv0CtrlGateDrv0Diag1Val();
}
uint16 *TSC_GateDrv0Ctrl_Rte_Pim_dGateDrv0CtrlGateDrv0Diag2Val(void)
{
  return Rte_Pim_dGateDrv0CtrlGateDrv0Diag2Val();
}
uint16 *TSC_GateDrv0Ctrl_Rte_Pim_dGateDrv0CtrlGateDrv0StsVal(void)
{
  return Rte_Pim_dGateDrv0CtrlGateDrv0StsVal();
}
uint16 *TSC_GateDrv0Ctrl_Rte_Pim_dGateDrv0CtrlGateDrv0VrfyRes0Val(void)
{
  return Rte_Pim_dGateDrv0CtrlGateDrv0VrfyRes0Val();
}
uint16 *TSC_GateDrv0Ctrl_Rte_Pim_dGateDrv0CtrlGateDrv0VrfyRes1Val(void)
{
  return Rte_Pim_dGateDrv0CtrlGateDrv0VrfyRes1Val();
}
uint8 *TSC_GateDrv0Ctrl_Rte_Pim_GateDrv0CfgCnt(void)
{
  return Rte_Pim_GateDrv0CfgCnt();
}
uint8 *TSC_GateDrv0Ctrl_Rte_Pim_GateDrv0OffStChkIdx(void)
{
  return Rte_Pim_GateDrv0OffStChkIdx();
}
uint8 *TSC_GateDrv0Ctrl_Rte_Pim_GateDrv0OffStCnt(void)
{
  return Rte_Pim_GateDrv0OffStCnt();
}
uint8 *TSC_GateDrv0Ctrl_Rte_Pim_GateDrv0St(void)
{
  return Rte_Pim_GateDrv0St();
}
uint8 *TSC_GateDrv0Ctrl_Rte_Pim_Ivtr0BootstrpSplyFltPrmVal(void)
{
  return Rte_Pim_Ivtr0BootstrpSplyFltPrmVal();
}
uint8 *TSC_GateDrv0Ctrl_Rte_Pim_Ivtr0GenericFltPrmVal(void)
{
  return Rte_Pim_Ivtr0GenericFltPrmVal();
}
IvtrFetFltPha1 *TSC_GateDrv0Ctrl_Rte_Pim_IvtrFetFltPhaDataStore(void)
{
  return Rte_Pim_IvtrFetFltPhaDataStore();
}
IvtrFetFltTyp1 *TSC_GateDrv0Ctrl_Rte_Pim_IvtrFetFltTypDataStore(void)
{
  return Rte_Pim_IvtrFetFltTypDataStore();
}
uint8 *TSC_GateDrv0Ctrl_Rte_Pim_dGateDrv0CtrlGateDrv0OffsStVrfyPrmBitIdx(void)
{
  return Rte_Pim_dGateDrv0CtrlGateDrv0OffsStVrfyPrmBitIdx();
}
boolean *TSC_GateDrv0Ctrl_Rte_Pim_GateDrv0CfgSecAtmpt(void)
{
  return Rte_Pim_GateDrv0CfgSecAtmpt();
}
boolean *TSC_GateDrv0Ctrl_Rte_Pim_GateDrv0OffStChkSecAtmpt(void)
{
  return Rte_Pim_GateDrv0OffStChkSecAtmpt();
}
boolean *TSC_GateDrv0Ctrl_Rte_Pim_GateDrv0SpiErrSecAtmpt(void)
{
  return Rte_Pim_GateDrv0SpiErrSecAtmpt();
}
boolean *TSC_GateDrv0Ctrl_Rte_Pim_Ivtr0InactvSts(void)
{
  return Rte_Pim_Ivtr0InactvSts();
}
boolean *TSC_GateDrv0Ctrl_Rte_Pim_Ivtr0OffStChkCmpl(void)
{
  return Rte_Pim_Ivtr0OffStChkCmpl();
}
FilLpRec1 *TSC_GateDrv0Ctrl_Rte_Pim_GateDrv0PhaAFilLp(void)
{
  return Rte_Pim_GateDrv0PhaAFilLp();
}
FilLpRec1 *TSC_GateDrv0Ctrl_Rte_Pim_GateDrv0PhaBFilLp(void)
{
  return Rte_Pim_GateDrv0PhaBFilLp();
}
FilLpRec1 *TSC_GateDrv0Ctrl_Rte_Pim_GateDrv0PhaCFilLp(void)
{
  return Rte_Pim_GateDrv0PhaCFilLp();
}



