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
 *          File:  TSC_BmwHwAgArbnAndEotPosn.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_BmwHwAgArbnAndEotPosn.h"
#include "TSC_BmwHwAgArbnAndEotPosn.h"















     /* Client Server Interfaces: */


     /* Service calls */
Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Call_BmwVehCentrOffs_GetErrorStatus(NvM_RequestResultType *ErrorStatus_Arg)
{
  return Rte_Call_BmwVehCentrOffs_GetErrorStatus(ErrorStatus_Arg);
}
Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Call_BmwVehCentrOffs_SetRamBlockStatus(boolean RamBlockStatus_Arg)
{
  return Rte_Call_BmwVehCentrOffs_SetRamBlockStatus(RamBlockStatus_Arg);
}


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Read_BmwHwAgOffs_Val(float32 *data)
{
  return Rte_Read_BmwHwAgOffs_Val(data);
}

Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Read_BmwPinionAgOffs_Val(float32 *data)
{
  return Rte_Read_BmwPinionAgOffs_Val(data);
}

Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Read_BmwPinionAgOffsSts_Val(BmwPinionAgOffsSts1 *data)
{
  return Rte_Read_BmwPinionAgOffsSts_Val(data);
}

Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Read_BmwQuadOffsSts_Val(BmwQuadOffsSts1 *data)
{
  return Rte_Read_BmwQuadOffsSts_Val(data);
}

Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Read_BmwQuadOffsStsVld_Logl(boolean *data)
{
  return Rte_Read_BmwQuadOffsStsVld_Logl(data);
}

Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Read_BmwQuadRotorOffs_Val(sint8 *data)
{
  return Rte_Read_BmwQuadRotorOffs_Val(data);
}

Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Read_BmwQuadRotorOffsVld_Logl(boolean *data)
{
  return Rte_Read_BmwQuadRotorOffsVld_Logl(data);
}

Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Read_BmwVehSpdSts_Val(BmwVehSpdSts1 *data)
{
  return Rte_Read_BmwVehSpdSts_Val(data);
}

Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Read_CmplncErrMotToPinion_Val(float32 *data)
{
  return Rte_Read_CmplncErrMotToPinion_Val(data);
}

Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Read_DiKineIntegrityTest_Logl(boolean *data)
{
  return Rte_Read_DiKineIntegrityTest_Logl(data);
}

Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Read_LongTermRackCentrCmpl_Logl(boolean *data)
{
  return Rte_Read_LongTermRackCentrCmpl_Logl(data);
}

Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Read_MotAgCumvAlgndMrf_Val(s18p13 *data)
{
  return Rte_Read_MotAgCumvAlgndMrf_Val(data);
}

Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Read_MotAgMeclCorrlnSt_Val(uint8 *data)
{
  return Rte_Read_MotAgMeclCorrlnSt_Val(data);
}

Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Read_MotAgTurnCntr_Val(float32 *data)
{
  return Rte_Read_MotAgTurnCntr_Val(data);
}

Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Read_RackCentrPinionAg_Val(float32 *data)
{
  return Rte_Read_RackCentrPinionAg_Val(data);
}

Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Read_TotRackTrvl_Val(float32 *data)
{
  return Rte_Read_TotRackTrvl_Val(data);
}

Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Read_TurnCntrCorrlnSts_Val(uint8 *data)
{
  return Rte_Read_TurnCntrCorrlnSts_Val(data);
}

Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Read_VehSpd_Val(float32 *data)
{
  return Rte_Read_VehSpd_Val(data);
}

Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Read_VehSpdVld_Logl(boolean *data)
{
  return Rte_Read_VehSpdVld_Logl(data);
}




Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Write_AlgndPinionAg_Val(float32 data)
{
  return Rte_Write_AlgndPinionAg_Val(data);
}

Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Write_BmwPinionAg_Val(float32 data)
{
  return Rte_Write_BmwPinionAg_Val(data);
}

Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Write_BmwPinionAgQlfr_Val(BmwPinionAgQlfr1 data)
{
  return Rte_Write_BmwPinionAgQlfr_Val(data);
}

Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Write_BmwRackCentrToVehCentrOffs_Val(float32 data)
{
  return Rte_Write_BmwRackCentrToVehCentrOffs_Val(data);
}

Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Write_BmwRackCentrToVehCentrOffsVld_Logl(boolean data)
{
  return Rte_Write_BmwRackCentrToVehCentrOffsVld_Logl(data);
}

Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Write_HwAgCcwDetd_Logl(boolean data)
{
  return Rte_Write_HwAgCcwDetd_Logl(data);
}

Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Write_HwAgCwDetd_Logl(boolean data)
{
  return Rte_Write_HwAgCwDetd_Logl(data);
}

Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Write_HwAgEotCcw_Val(float32 data)
{
  return Rte_Write_HwAgEotCcw_Val(data);
}

Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Write_HwAgEotCw_Val(float32 data)
{
  return Rte_Write_HwAgEotCw_Val(data);
}

Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Write_LongTermVehCentrCmpl_Logl(boolean data)
{
  return Rte_Write_LongTermVehCentrCmpl_Logl(data);
}

Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Write_OffsCmpdPinionAg_Val(float32 data)
{
  return Rte_Write_OffsCmpdPinionAg_Val(data);
}

Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Write_PinionAg_Val(float32 data)
{
  return Rte_Write_PinionAg_Val(data);
}

Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Write_PinionAgConf_Val(float32 data)
{
  return Rte_Write_PinionAgConf_Val(data);
}





     /* Client Server Interfaces: */
Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Call_GetNtcQlfrSts_Oper(NtcNr1 NtcNr_Arg, SigQlfr1 *NtcQlfr_Arg)
{
  return Rte_Call_GetNtcQlfrSts_Oper(NtcNr_Arg, NtcQlfr_Arg);
}
Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Call_GetRefTmr100MicroSec32bit_Oper(uint32 *RefTmr_Arg)
{
  return Rte_Call_GetRefTmr100MicroSec32bit_Oper(RefTmr_Arg);
}
Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Call_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg)
{
  return Rte_Call_GetTiSpan100MicroSec32bit_Oper(RefTmr_Arg, TiSpan_Arg);
}
Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Call_RstRackCentrMotRev_Oper(void)
{
  return Rte_Call_RstRackCentrMotRev_Oper();
}
Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
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





float32  TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnBmwPinionAgOffsLim_Val(void)
{
  return (float32 ) Rte_Prm_BmwHwAgArbnAndEotPosnBmwPinionAgOffsLim_Val();
}
float32  TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnBmwPinionAgOffsRateLim_Val(void)
{
  return (float32 ) Rte_Prm_BmwHwAgArbnAndEotPosnBmwPinionAgOffsRateLim_Val();
}
float32  TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnEotCcwMax_Val(void)
{
  return (float32 ) Rte_Prm_BmwHwAgArbnAndEotPosnEotCcwMax_Val();
}
float32  TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnEotCcwMin_Val(void)
{
  return (float32 ) Rte_Prm_BmwHwAgArbnAndEotPosnEotCcwMin_Val();
}
float32  TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnEotCwMax_Val(void)
{
  return (float32 ) Rte_Prm_BmwHwAgArbnAndEotPosnEotCwMax_Val();
}
float32  TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnEotCwMin_Val(void)
{
  return (float32 ) Rte_Prm_BmwHwAgArbnAndEotPosnEotCwMin_Val();
}
float32  TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnKineIntegrityDiagcMaxRackLim_Val(void)
{
  return (float32 ) Rte_Prm_BmwHwAgArbnAndEotPosnKineIntegrityDiagcMaxRackLim_Val();
}
float32  TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnMinVehSpdReqdVldAbsPos_Val(void)
{
  return (float32 ) Rte_Prm_BmwHwAgArbnAndEotPosnMinVehSpdReqdVldAbsPos_Val();
}
float32  TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnMotToHwResl_Val(void)
{
  return (float32 ) Rte_Prm_BmwHwAgArbnAndEotPosnMotToHwResl_Val();
}
float32  TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnOffsAuthy_Val(void)
{
  return (float32 ) Rte_Prm_BmwHwAgArbnAndEotPosnOffsAuthy_Val();
}
float32  TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnOffsCorrnAuthy_Val(void)
{
  return (float32 ) Rte_Prm_BmwHwAgArbnAndEotPosnOffsCorrnAuthy_Val();
}
float32  TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgConfRampDwnRate_Val(void)
{
  return (float32 ) Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgConfRampDwnRate_Val();
}
float32  TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgConfRampUpRate_Val(void)
{
  return (float32 ) Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgConfRampUpRate_Val();
}
float32  TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgDifThd_Val(void)
{
  return (float32 ) Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgDifThd_Val();
}
float32  TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgFilFrq_Val(void)
{
  return (float32 ) Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgFilFrq_Val();
}
float32  TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnTmpCmpdAuthy_Val(void)
{
  return (float32 ) Rte_Prm_BmwHwAgArbnAndEotPosnTmpCmpdAuthy_Val();
}
float32  TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnTurnCntrAuthy_Val(void)
{
  return (float32 ) Rte_Prm_BmwHwAgArbnAndEotPosnTurnCntrAuthy_Val();
}
float32  TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_SysGlbPrmSysKineRat_Val(void)
{
  return (float32 ) Rte_Prm_SysGlbPrmSysKineRat_Val();
}
uint32  TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnMotPosnDegArbdBlnd_Val(void)
{
  return (uint32 ) Rte_Prm_BmwHwAgArbnAndEotPosnMotPosnDegArbdBlnd_Val();
}
uint32  TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnTurnCntrCorrlnStsTmrThd_Val(void)
{
  return (uint32 ) Rte_Prm_BmwHwAgArbnAndEotPosnTurnCntrCorrlnStsTmrThd_Val();
}
uint16  TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnAllwExitFromInit_Val(void)
{
  return (uint16 ) Rte_Prm_BmwHwAgArbnAndEotPosnAllwExitFromInit_Val();
}
uint16  TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnOffsCorrnTmrThd_Val(void)
{
  return (uint16 ) Rte_Prm_BmwHwAgArbnAndEotPosnOffsCorrnTmrThd_Val();
}
uint16  TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgFltTmrThd_Val(void)
{
  return (uint16 ) Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgFltTmrThd_Val();
}
boolean  TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnSysPolarityAssi_Logl(void)
{
  return (boolean ) Rte_Prm_BmwHwAgArbnAndEotPosnSysPolarityAssi_Logl();
}


     /* BmwHwAgArbnAndEotPosn */
      /* BmwHwAgArbnAndEotPosn */

/** Per Instance Memories */
float32 *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_BmwPinionAgOffsRateLim(void)
{
  return Rte_Pim_BmwPinionAgOffsRateLim();
}
float32 *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_CurrAlgndPinionAg(void)
{
  return Rte_Pim_CurrAlgndPinionAg();
}
float32 *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PinionAgConfRampStVari(void)
{
  return Rte_Pim_PinionAgConfRampStVari();
}
float32 *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevBmwOffsAuthy(void)
{
  return Rte_Pim_PrevBmwOffsAuthy();
}
float32 *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevLoopPinionAg(void)
{
  return Rte_Pim_PrevLoopPinionAg();
}
float32 *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevPinionAgConf(void)
{
  return Rte_Pim_PrevPinionAgConf();
}
uint32 *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_AllwExitFromInitTi(void)
{
  return Rte_Pim_AllwExitFromInitTi();
}
uint32 *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_MotPosnDegArbdBlndTi(void)
{
  return Rte_Pim_MotPosnDegArbdBlndTi();
}
uint32 *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_OffsCorrnRefTi(void)
{
  return Rte_Pim_OffsCorrnRefTi();
}
uint32 *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PinionAgFltRefTi(void)
{
  return Rte_Pim_PinionAgFltRefTi();
}
uint32 *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_TurnCntrValTi(void)
{
  return Rte_Pim_TurnCntrValTi();
}
BmwRackToVehCentrOffsSts1 *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_BmwRackCentrToVehCentrOffsSts(void)
{
  return Rte_Pim_BmwRackCentrToVehCentrOffsSts();
}
uint8 *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_FirstLoopIndcr(void)
{
  return Rte_Pim_FirstLoopIndcr();
}
uint8 *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_IniTurnCntrCorrlnSts(void)
{
  return Rte_Pim_IniTurnCntrCorrlnSts();
}
BmwMotAgSelnSt1 *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevBmwMotAgSelnSt(void)
{
  return Rte_Pim_PrevBmwMotAgSelnSt();
}
uint8 *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevIgnCycBmwMotAgSelnSt(void)
{
  return Rte_Pim_PrevIgnCycBmwMotAgSelnSt();
}
uint8 *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevIgnCycNtc8CSts(void)
{
  return Rte_Pim_PrevIgnCycNtc8CSts();
}
uint8 *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevIgnCycNtc8ESts(void)
{
  return Rte_Pim_PrevIgnCycNtc8ESts();
}
uint8 *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevIgnCycTurnCntrCorrlnSts(void)
{
  return Rte_Pim_PrevIgnCycTurnCntrCorrlnSts();
}
BmwMotAgSelnSt1 *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevLoopBmwMotAgSelnSt(void)
{
  return Rte_Pim_PrevLoopBmwMotAgSelnSt();
}
BmwQuadOffsSts1 *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevLoopBmwQuadOffsSts(void)
{
  return Rte_Pim_PrevLoopBmwQuadOffsSts();
}
uint8 *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_dBmwHwAgArbnAndEotPosnBmwMotAgSelnSt(void)
{
  return Rte_Pim_dBmwHwAgArbnAndEotPosnBmwMotAgSelnSt();
}
boolean *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_ClrNotCmplPinionAgFlg(void)
{
  return Rte_Pim_ClrNotCmplPinionAgFlg();
}
boolean *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_CurrDftPinionAgFltPrsnt(void)
{
  return Rte_Pim_CurrDftPinionAgFltPrsnt();
}
boolean *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_DynStabyCtrlCdn(void)
{
  return Rte_Pim_DynStabyCtrlCdn();
}
boolean *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_KineIntegrityFlt(void)
{
  return Rte_Pim_KineIntegrityFlt();
}
boolean *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_LpFilActvd(void)
{
  return Rte_Pim_LpFilActvd();
}
boolean *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_MotPosnDegArbdBlndFac(void)
{
  return Rte_Pim_MotPosnDegArbdBlndFac();
}
boolean *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevAllwCorrn(void)
{
  return Rte_Pim_PrevAllwCorrn();
}
boolean *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevBmwOffsAuthyFlg(void)
{
  return Rte_Pim_PrevBmwOffsAuthyFlg();
}
boolean *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_SetBmwRackCentrToVehCentrOffsTrig(void)
{
  return Rte_Pim_SetBmwRackCentrToVehCentrOffsTrig();
}
boolean *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_SigInvldTranTrig(void)
{
  return Rte_Pim_SigInvldTranTrig();
}
boolean *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_TurnCntrCorrlnStsTmrTrig(void)
{
  return Rte_Pim_TurnCntrCorrlnStsTmrTrig();
}
boolean *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_VehCentrCmpl(void)
{
  return Rte_Pim_VehCentrCmpl();
}
BmwVehCentrOffsRec1 *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_BmwVehCentrOffs(void)
{
  return Rte_Pim_BmwVehCentrOffs();
}
FilLpRec1 *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PinionAgFilStVari(void)
{
  return Rte_Pim_PinionAgFilStVari();
}



