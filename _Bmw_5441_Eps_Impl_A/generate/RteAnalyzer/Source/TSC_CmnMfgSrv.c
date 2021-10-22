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
 *          File:  TSC_CmnMfgSrv.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_CmnMfgSrv.h"
#include "TSC_CmnMfgSrv.h"








Std_ReturnType TSC_CmnMfgSrv_Rte_Read_BrdgVltg_Val(float32 *data)
{
  return Rte_Read_BrdgVltg_Val(data);
}

Std_ReturnType TSC_CmnMfgSrv_Rte_Read_EcuTFild_Val(float32 *data)
{
  return Rte_Read_EcuTFild_Val(data);
}

Std_ReturnType TSC_CmnMfgSrv_Rte_Read_HwAg_Val(float32 *data)
{
  return Rte_Read_HwAg_Val(data);
}

Std_ReturnType TSC_CmnMfgSrv_Rte_Read_HwAg0_Val(float32 *data)
{
  return Rte_Read_HwAg0_Val(data);
}

Std_ReturnType TSC_CmnMfgSrv_Rte_Read_HwAg1_Val(float32 *data)
{
  return Rte_Read_HwAg1_Val(data);
}

Std_ReturnType TSC_CmnMfgSrv_Rte_Read_HwTq_Val(float32 *data)
{
  return Rte_Read_HwTq_Val(data);
}

Std_ReturnType TSC_CmnMfgSrv_Rte_Read_HwTq0_Val(float32 *data)
{
  return Rte_Read_HwTq0_Val(data);
}

Std_ReturnType TSC_CmnMfgSrv_Rte_Read_HwTq1_Val(float32 *data)
{
  return Rte_Read_HwTq1_Val(data);
}

Std_ReturnType TSC_CmnMfgSrv_Rte_Read_HwTq2_Val(float32 *data)
{
  return Rte_Read_HwTq2_Val(data);
}

Std_ReturnType TSC_CmnMfgSrv_Rte_Read_HwTq3_Val(float32 *data)
{
  return Rte_Read_HwTq3_Val(data);
}

Std_ReturnType TSC_CmnMfgSrv_Rte_Read_MotAg0Mecl_Val(uint16 *data)
{
  return Rte_Read_MotAg0Mecl_Val(data);
}

Std_ReturnType TSC_CmnMfgSrv_Rte_Read_MotAg1Mecl_Val(uint16 *data)
{
  return Rte_Read_MotAg1Mecl_Val(data);
}

Std_ReturnType TSC_CmnMfgSrv_Rte_Read_MotAg2Mecl_Val(uint16 *data)
{
  return Rte_Read_MotAg2Mecl_Val(data);
}

Std_ReturnType TSC_CmnMfgSrv_Rte_Read_MotAgCumvAlgndMrf_Val(sint32 *data)
{
  return Rte_Read_MotAgCumvAlgndMrf_Val(data);
}

Std_ReturnType TSC_CmnMfgSrv_Rte_Read_MotAgMecl_Val(uint16 *data)
{
  return Rte_Read_MotAgMecl_Val(data);
}

Std_ReturnType TSC_CmnMfgSrv_Rte_Read_MotCurrDax_Val(float32 *data)
{
  return Rte_Read_MotCurrDax_Val(data);
}

Std_ReturnType TSC_CmnMfgSrv_Rte_Read_MotCurrQax_Val(float32 *data)
{
  return Rte_Read_MotCurrQax_Val(data);
}

Std_ReturnType TSC_CmnMfgSrv_Rte_Read_MotTqCmd_Val(float32 *data)
{
  return Rte_Read_MotTqCmd_Val(data);
}

Std_ReturnType TSC_CmnMfgSrv_Rte_Read_MotVelMrf_Val(float32 *data)
{
  return Rte_Read_MotVelMrf_Val(data);
}

Std_ReturnType TSC_CmnMfgSrv_Rte_Read_PinionAg_Val(float32 *data)
{
  return Rte_Read_PinionAg_Val(data);
}

Std_ReturnType TSC_CmnMfgSrv_Rte_Read_SysSt_Val(SysSt1 *data)
{
  return Rte_Read_SysSt_Val(data);
}




Std_ReturnType TSC_CmnMfgSrv_Rte_Write_AssiLnrGain_Val(float32 data)
{
  return Rte_Write_AssiLnrGain_Val(data);
}

Std_ReturnType TSC_CmnMfgSrv_Rte_Write_AssiLnrGainEna_Logl(boolean data)
{
  return Rte_Write_AssiLnrGainEna_Logl(data);
}

Std_ReturnType TSC_CmnMfgSrv_Rte_Write_IgnCntr_Val(uint32 data)
{
  return Rte_Write_IgnCntr_Val(data);
}

Std_ReturnType TSC_CmnMfgSrv_Rte_Write_MfgEnaSt_Val(MfgEnaSt1 data)
{
  return Rte_Write_MfgEnaSt_Val(data);
}

Std_ReturnType TSC_CmnMfgSrv_Rte_Write_SysStImdtTranReqOff_Logl(boolean data)
{
  return Rte_Write_SysStImdtTranReqOff_Logl(data);
}

Std_ReturnType TSC_CmnMfgSrv_Rte_Write_VehSpdOvrd_Val(float32 data)
{
  return Rte_Write_VehSpdOvrd_Val(data);
}

Std_ReturnType TSC_CmnMfgSrv_Rte_Write_VehSpdOvrdEna_Logl(boolean data)
{
  return Rte_Write_VehSpdOvrdEna_Logl(data);
}





     /* Client Server Interfaces: */
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_ClrAllDiagc_Oper(void)
{
  return Rte_Call_ClrAllDiagc_Oper();
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_ClrFricLrngOperMod_Oper(void)
{
  return Rte_Call_ClrFricLrngOperMod_Oper();
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_ClrHwAgTrimVal_Oper(void)
{
  return Rte_Call_ClrHwAgTrimVal_Oper();
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_ClrLtchCntrData_Oper(void)
{
  return Rte_Call_ClrLtchCntrData_Oper();
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_ClrSnpshtData_Oper(void)
{
  return Rte_Call_ClrSnpshtData_Oper();
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_CurrMeasEolGainReq_Oper(void)
{
  return Rte_Call_CurrMeasEolGainReq_Oper();
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_CurrMeasEolGainStReq_Oper(uint8 *CurrMeasEolGainSt_Arg)
{
  return Rte_Call_CurrMeasEolGainStReq_Oper(CurrMeasEolGainSt_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_CurrMeasEolOffsReq_Oper(void)
{
  return Rte_Call_CurrMeasEolOffsReq_Oper();
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_CurrMeasEolOffsStReq_Oper(uint8 *CurrMeasEolOffsSt_Arg)
{
  return Rte_Call_CurrMeasEolOffsStReq_Oper(CurrMeasEolOffsSt_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_CurrMeasGainReadReq_Oper(float32 *CurrMeasMotCurrGainA_Arg, float32 *CurrMeasMotCurrGainB_Arg, float32 *CurrMeasMotCurrGainC_Arg, float32 *CurrMeasMotCurrGainD_Arg, float32 *CurrMeasMotCurrGainE_Arg, float32 *CurrMeasMotCurrGainF_Arg)
{
  return Rte_Call_CurrMeasGainReadReq_Oper(CurrMeasMotCurrGainA_Arg, CurrMeasMotCurrGainB_Arg, CurrMeasMotCurrGainC_Arg, CurrMeasMotCurrGainD_Arg, CurrMeasMotCurrGainE_Arg, CurrMeasMotCurrGainF_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_CurrMeasGainReadReqSngIvtr_Oper(float32 *CurrMeasMotCurrGainA_Arg, float32 *CurrMeasMotCurrGainB_Arg, float32 *CurrMeasMotCurrGainC_Arg)
{
  return Rte_Call_CurrMeasGainReadReqSngIvtr_Oper(CurrMeasMotCurrGainA_Arg, CurrMeasMotCurrGainB_Arg, CurrMeasMotCurrGainC_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_CurrMeasGainWrReq_Oper(float32 CurrMeasMotCurrGainA_Arg, float32 CurrMeasMotCurrGainB_Arg, float32 CurrMeasMotCurrGainC_Arg, float32 CurrMeasMotCurrGainD_Arg, float32 CurrMeasMotCurrGainE_Arg, float32 CurrMeasMotCurrGainF_Arg, uint8 *CurrMeasGainWrReqSts_Arg)
{
  return Rte_Call_CurrMeasGainWrReq_Oper(CurrMeasMotCurrGainA_Arg, CurrMeasMotCurrGainB_Arg, CurrMeasMotCurrGainC_Arg, CurrMeasMotCurrGainD_Arg, CurrMeasMotCurrGainE_Arg, CurrMeasMotCurrGainF_Arg, CurrMeasGainWrReqSts_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_CurrMeasGainWrReqSngIvtr_Oper(float32 CurrMeasMotCurrGainA_Arg, float32 CurrMeasMotCurrGainB_Arg, float32 CurrMeasMotCurrGainC_Arg, uint8 *CurrMeasGainWrReqSts_Arg)
{
  return Rte_Call_CurrMeasGainWrReqSngIvtr_Oper(CurrMeasMotCurrGainA_Arg, CurrMeasMotCurrGainB_Arg, CurrMeasMotCurrGainC_Arg, CurrMeasGainWrReqSts_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_CurrMeasOffsReadReq_Oper(float32 *CurrMeasEolOffsHiBrdgVltg_Arg, float32 *CurrMeasMotCurrOffsDifA_Arg, float32 *CurrMeasMotCurrOffsDifB_Arg, float32 *CurrMeasMotCurrOffsDifC_Arg, float32 *CurrMeasMotCurrOffsDifD_Arg, float32 *CurrMeasMotCurrOffsDifE_Arg, float32 *CurrMeasMotCurrOffsDifF_Arg, float32 *CurrMeasMotCurrOffsLoAvrgA_Arg, float32 *CurrMeasMotCurrOffsLoAvrgB_Arg, float32 *CurrMeasMotCurrOffsLoAvrgC_Arg, float32 *CurrMeasMotCurrOffsLoAvrgD_Arg, float32 *CurrMeasMotCurrOffsLoAvrgE_Arg, float32 *CurrMeasMotCurrOffsLoAvrgF_Arg)
{
  return Rte_Call_CurrMeasOffsReadReq_Oper(CurrMeasEolOffsHiBrdgVltg_Arg, CurrMeasMotCurrOffsDifA_Arg, CurrMeasMotCurrOffsDifB_Arg, CurrMeasMotCurrOffsDifC_Arg, CurrMeasMotCurrOffsDifD_Arg, CurrMeasMotCurrOffsDifE_Arg, CurrMeasMotCurrOffsDifF_Arg, CurrMeasMotCurrOffsLoAvrgA_Arg, CurrMeasMotCurrOffsLoAvrgB_Arg, CurrMeasMotCurrOffsLoAvrgC_Arg, CurrMeasMotCurrOffsLoAvrgD_Arg, CurrMeasMotCurrOffsLoAvrgE_Arg, CurrMeasMotCurrOffsLoAvrgF_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_CurrMeasOffsReadReqSngIvtr_Oper(float32 *CurrMeasEolOffsHiBrdgVltg_Arg, float32 *CurrMeasMotCurrOffsDifA_Arg, float32 *CurrMeasMotCurrOffsDifB_Arg, float32 *CurrMeasMotCurrOffsDifC_Arg, float32 *CurrMeasMotCurrOffsLoAvrgA_Arg, float32 *CurrMeasMotCurrOffsLoAvrgB_Arg, float32 *CurrMeasMotCurrOffsLoAvrgC_Arg)
{
  return Rte_Call_CurrMeasOffsReadReqSngIvtr_Oper(CurrMeasEolOffsHiBrdgVltg_Arg, CurrMeasMotCurrOffsDifA_Arg, CurrMeasMotCurrOffsDifB_Arg, CurrMeasMotCurrOffsDifC_Arg, CurrMeasMotCurrOffsLoAvrgA_Arg, CurrMeasMotCurrOffsLoAvrgB_Arg, CurrMeasMotCurrOffsLoAvrgC_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_CurrMeasOffsWrReq_Oper(float32 CurrMeasEolOffsHiBrdgVltg_Arg, float32 CurrMeasMotCurrOffsDifA_Arg, float32 CurrMeasMotCurrOffsDifB_Arg, float32 CurrMeasMotCurrOffsDifC_Arg, float32 CurrMeasMotCurrOffsDifD_Arg, float32 CurrMeasMotCurrOffsDifE_Arg, float32 CurrMeasMotCurrOffsDifF_Arg, float32 CurrMeasMotCurrOffsLoAvrgA_Arg, float32 CurrMeasMotCurrOffsLoAvrgB_Arg, float32 CurrMeasMotCurrOffsLoAvrgC_Arg, float32 CurrMeasMotCurrOffsLoAvrgD_Arg, float32 CurrMeasMotCurrOffsLoAvrgE_Arg, float32 CurrMeasMotCurrOffsLoAvrgF_Arg, uint8 *CurrMeasOffsWrReqSts_Arg)
{
  return Rte_Call_CurrMeasOffsWrReq_Oper(CurrMeasEolOffsHiBrdgVltg_Arg, CurrMeasMotCurrOffsDifA_Arg, CurrMeasMotCurrOffsDifB_Arg, CurrMeasMotCurrOffsDifC_Arg, CurrMeasMotCurrOffsDifD_Arg, CurrMeasMotCurrOffsDifE_Arg, CurrMeasMotCurrOffsDifF_Arg, CurrMeasMotCurrOffsLoAvrgA_Arg, CurrMeasMotCurrOffsLoAvrgB_Arg, CurrMeasMotCurrOffsLoAvrgC_Arg, CurrMeasMotCurrOffsLoAvrgD_Arg, CurrMeasMotCurrOffsLoAvrgE_Arg, CurrMeasMotCurrOffsLoAvrgF_Arg, CurrMeasOffsWrReqSts_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_CurrMeasOffsWrReqSngIvtr_Oper(float32 CurrMeasEolOffsHiBrdgVltg_Arg, float32 CurrMeasMotCurrOffsDifA_Arg, float32 CurrMeasMotCurrOffsDifB_Arg, float32 CurrMeasMotCurrOffsDifC_Arg, float32 CurrMeasMotCurrOffsLoAvrgA_Arg, float32 CurrMeasMotCurrOffsLoAvrgB_Arg, float32 CurrMeasMotCurrOffsLoAvrgC_Arg, uint8 *CurrMeasOffsWrReqSts_Arg)
{
  return Rte_Call_CurrMeasOffsWrReqSngIvtr_Oper(CurrMeasEolOffsHiBrdgVltg_Arg, CurrMeasMotCurrOffsDifA_Arg, CurrMeasMotCurrOffsDifB_Arg, CurrMeasMotCurrOffsDifC_Arg, CurrMeasMotCurrOffsLoAvrgA_Arg, CurrMeasMotCurrOffsLoAvrgB_Arg, CurrMeasMotCurrOffsLoAvrgC_Arg, CurrMeasOffsWrReqSts_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_FSnsrlsHwCentr_Oper(void)
{
  return Rte_Call_FSnsrlsHwCentr_Oper();
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_GetCtrlPrm_Oper(float32 *MotVelCtrlPropGain_Arg, float32 *MotVelCtrlIntgtrGain_Arg, float32 *MotVelCtrlDerivtvGain_Arg, float32 *MotVelCtrlAntiWdupLim_Arg, float32 *MotVelCtrlAntiWdupGain_Arg, float32 *MotVelCtrlDerivtvLpFilTiCon_Arg, float32 *MotVelCtrlTqCmdLim_Arg)
{
  return Rte_Call_GetCtrlPrm_Oper(MotVelCtrlPropGain_Arg, MotVelCtrlIntgtrGain_Arg, MotVelCtrlDerivtvGain_Arg, MotVelCtrlAntiWdupLim_Arg, MotVelCtrlAntiWdupGain_Arg, MotVelCtrlDerivtvLpFilTiCon_Arg, MotVelCtrlTqCmdLim_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_GetFricData_Oper(float32 *FricOffs_Arg, float32 *BasLineFric_Arg, float32 *VehLrndFric_Arg, float32 *Hys_Arg, uint16 *RngCntr_Arg)
{
  return Rte_Call_GetFricData_Oper(FricOffs_Arg, BasLineFric_Arg, VehLrndFric_Arg, Hys_Arg, RngCntr_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_GetFricLrngData_Oper(boolean *FricLrngEna_Arg, boolean *FricLrngOffsOutpEna_Arg, SysFricLrngOperMod1 *FricLrngOperMod_Arg, float32 *EolFric_Arg)
{
  return Rte_Call_GetFricLrngData_Oper(FricLrngEna_Arg, FricLrngOffsOutpEna_Arg, FricLrngOperMod_Arg, EolFric_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_GetFricOffsOutpDi_Oper(boolean *FricOffsOutpDi_Arg)
{
  return Rte_Call_GetFricOffsOutpDi_Oper(FricOffsOutpDi_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_GetGearIdn_Oper(uint8 *GearIdn_Arg)
{
  return Rte_Call_GetGearIdn_Oper(GearIdn_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_GetHwAgOffs_Oper(float32 *HwAgOffs_Arg, boolean *HwAgLrngStRst_Arg)
{
  return Rte_Call_GetHwAgOffs_Oper(HwAgOffs_Arg, HwAgLrngStRst_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_GetHwAgOverTrvlCnt_Oper(uint8 *HwAgOverTrvlCnt_Arg)
{
  return Rte_Call_GetHwAgOverTrvlCnt_Oper(HwAgOverTrvlCnt_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_GetHwAgTrimVal_Oper(float32 *HwAgTrimVal_Arg, boolean *HwAgTrimPrfmd_Arg)
{
  return Rte_Call_GetHwAgTrimVal_Oper(HwAgTrimVal_Arg, HwAgTrimPrfmd_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_GetHwTqOffs_Oper(float32 *HwTqOffs_Arg, boolean *HwTqLrngStRst_Arg)
{
  return Rte_Call_GetHwTqOffs_Oper(HwTqOffs_Arg, HwTqLrngStRst_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_GetMotCoggCmdPrm_Oper(s1p14 *MotCoggCmdY_Arg, uint8 Idx_Arg)
{
  return Rte_Call_GetMotCoggCmdPrm_Oper(MotCoggCmdY_Arg, Idx_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_GetMotPrmNomEol_Oper(float32 *MotKeNom, float32 *MotRNom)
{
  return Rte_Call_GetMotPrmNomEol_Oper(MotKeNom, MotRNom);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_GetMotRplCoggPrm_Oper(uint16 *CoggOrder1_Arg, s1p14 *CoggOrder1X_Arg, s1p14 *CoggOrder1Y_Arg, uint16 *CoggOrder2_Arg, s1p14 *CoggOrder2X_Arg, s1p14 *CoggOrder2Y_Arg, uint16 *CoggOrder3_Arg, s1p14 *CoggOrder3X_Arg, s1p14 *CoggOrder3Y_Arg)
{
  return Rte_Call_GetMotRplCoggPrm_Oper(CoggOrder1_Arg, CoggOrder1X_Arg, CoggOrder1Y_Arg, CoggOrder2_Arg, CoggOrder2X_Arg, CoggOrder2Y_Arg, CoggOrder3_Arg, CoggOrder3X_Arg, CoggOrder3Y_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_GetMotTqCmdSca_Oper(float32 *MotTqCmdSca_Arg)
{
  return Rte_Call_GetMotTqCmdSca_Oper(MotTqCmdSca_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_GetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 *NtcInfoSts_Arg)
{
  return Rte_Call_GetNtcSts_Oper(NtcNr_Arg, NtcInfoSts_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_GetPullCmpPrm_Oper(float32 *PullCmpCmdTot_Arg, float32 *PullCmpShoTerm_Arg, float32 *PullCmpLongTerm_Arg, boolean *LrngEnad_Arg)
{
  return Rte_Call_GetPullCmpPrm_Oper(PullCmpCmdTot_Arg, PullCmpShoTerm_Arg, PullCmpLongTerm_Arg, LrngEnad_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_GetRefTmr100MicroSec32bit1_Oper(uint32 *RefTmr)
{
  return Rte_Call_GetRefTmr100MicroSec32bit1_Oper(RefTmr);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_GetTiSpan100MicroSec32bit1_Oper(uint32 RefTmr, uint32 *TiSpan)
{
  return Rte_Call_GetTiSpan100MicroSec32bit1_Oper(RefTmr, TiSpan);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_GetYawRateOffs_Oper(float32 *VehYawRateOffs_Arg, boolean *VehYawRateLrngStRst_Arg)
{
  return Rte_Call_GetYawRateOffs_Oper(VehYawRateOffs_Arg, VehYawRateLrngStRst_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_HwAg0ClrLtch_Oper(void)
{
  return Rte_Call_HwAg0ClrLtch_Oper();
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_HwAg0MeasHwAg0AutoTrim_Oper(void)
{
  return Rte_Call_HwAg0MeasHwAg0AutoTrim_Oper();
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_HwAg0MeasHwAg0ClrTrim_Oper(void)
{
  return Rte_Call_HwAg0MeasHwAg0ClrTrim_Oper();
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_HwAg0MeasHwAg0ReadTrim_Oper(float32 *HwAg0MeasHwAg0WrOffsTrimData)
{
  return Rte_Call_HwAg0MeasHwAg0ReadTrim_Oper(HwAg0MeasHwAg0WrOffsTrimData);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_HwAg0MeasHwAg0TrimPrfmdSts_Oper(boolean *HwAg0MeasHwAg0OffsTrimPrfmdStsData)
{
  return Rte_Call_HwAg0MeasHwAg0TrimPrfmdSts_Oper(HwAg0MeasHwAg0OffsTrimPrfmdStsData);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_HwAg0MeasHwAg0WrTrim_Oper(float32 HwAg0MeasHwAg0WrTrimData)
{
  return Rte_Call_HwAg0MeasHwAg0WrTrim_Oper(HwAg0MeasHwAg0WrTrimData);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_HwAg1ClrLtch_Oper(void)
{
  return Rte_Call_HwAg1ClrLtch_Oper();
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_HwAg1MeasHwAg1AutoTrim_Oper(void)
{
  return Rte_Call_HwAg1MeasHwAg1AutoTrim_Oper();
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_HwAg1MeasHwAg1ClrTrim_Oper(void)
{
  return Rte_Call_HwAg1MeasHwAg1ClrTrim_Oper();
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_HwAg1MeasHwAg1ReadTrim_Oper(float32 *HwAg1MeasHwAg1WrOffsTrimData)
{
  return Rte_Call_HwAg1MeasHwAg1ReadTrim_Oper(HwAg1MeasHwAg1WrOffsTrimData);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_HwAg1MeasHwAg1TrimPrfmdSts_Oper(boolean *HwAg1MeasHwAg1OffsTrimPrfmdStsData)
{
  return Rte_Call_HwAg1MeasHwAg1TrimPrfmdSts_Oper(HwAg1MeasHwAg1OffsTrimPrfmdStsData);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_HwAg1MeasHwAg1WrTrim_Oper(float32 HwAg1MeasHwAg1WrTrimData)
{
  return Rte_Call_HwAg1MeasHwAg1WrTrim_Oper(HwAg1MeasHwAg1WrTrimData);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_HwTq0MeasHwTq0AutTrim_Oper(void)
{
  return Rte_Call_HwTq0MeasHwTq0AutTrim_Oper();
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_HwTq0MeasHwTq0ClrTrim_Oper(void)
{
  return Rte_Call_HwTq0MeasHwTq0ClrTrim_Oper();
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_HwTq0MeasHwTq0ReadTrim_Oper(float32 *HwTq0MeasHwTq0ReadTrimData_Arg)
{
  return Rte_Call_HwTq0MeasHwTq0ReadTrim_Oper(HwTq0MeasHwTq0ReadTrimData_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_HwTq0MeasHwTq0TrimPrfmdSts_Oper(boolean *HwTq0MeasHwTq0OffsTrimPrfmdStsData_Arg)
{
  return Rte_Call_HwTq0MeasHwTq0TrimPrfmdSts_Oper(HwTq0MeasHwTq0OffsTrimPrfmdStsData_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_HwTq0MeasHwTq0WrTrim_Oper(float32 HwTq0MeasHwTq0WrOffsTrimData_Arg)
{
  return Rte_Call_HwTq0MeasHwTq0WrTrim_Oper(HwTq0MeasHwTq0WrOffsTrimData_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_HwTq1MeasHwTq1AutTrim_Oper(void)
{
  return Rte_Call_HwTq1MeasHwTq1AutTrim_Oper();
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_HwTq1MeasHwTq1ClrTrim_Oper(void)
{
  return Rte_Call_HwTq1MeasHwTq1ClrTrim_Oper();
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_HwTq1MeasHwTq1ReadTrim_Oper(float32 *HwTq1MeasHwTq1ReadTrimData_Arg)
{
  return Rte_Call_HwTq1MeasHwTq1ReadTrim_Oper(HwTq1MeasHwTq1ReadTrimData_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_HwTq1MeasHwTq1TrimPrfmdSts_Oper(boolean *HwTq1MeasHwTq1OffsTrimPrfmdStsData_Arg)
{
  return Rte_Call_HwTq1MeasHwTq1TrimPrfmdSts_Oper(HwTq1MeasHwTq1OffsTrimPrfmdStsData_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_HwTq1MeasHwTq1WrTrim_Oper(float32 HwTq1MeasHwTq1WrOffsTrimData_Arg)
{
  return Rte_Call_HwTq1MeasHwTq1WrTrim_Oper(HwTq1MeasHwTq1WrOffsTrimData_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_HwTq2MeasHwTq2AutTrim_Oper(void)
{
  return Rte_Call_HwTq2MeasHwTq2AutTrim_Oper();
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_HwTq2MeasHwTq2ClrTrim_Oper(void)
{
  return Rte_Call_HwTq2MeasHwTq2ClrTrim_Oper();
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_HwTq2MeasHwTq2ReadTrim_Oper(float32 *HwTq2MeasHwTq2ReadTrimData_Arg)
{
  return Rte_Call_HwTq2MeasHwTq2ReadTrim_Oper(HwTq2MeasHwTq2ReadTrimData_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_HwTq2MeasHwTq2TrimPrfmdSts_Oper(boolean *HwTq2MeasHwTq2OffsTrimPrfmdStsData_Arg)
{
  return Rte_Call_HwTq2MeasHwTq2TrimPrfmdSts_Oper(HwTq2MeasHwTq2OffsTrimPrfmdStsData_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_HwTq2MeasHwTq2WrTrim_Oper(float32 HwTq2MeasHwTq2WrOffsTrimData_Arg)
{
  return Rte_Call_HwTq2MeasHwTq2WrTrim_Oper(HwTq2MeasHwTq2WrOffsTrimData_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_HwTq3MeasHwTq3AutTrim_Oper(void)
{
  return Rte_Call_HwTq3MeasHwTq3AutTrim_Oper();
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_HwTq3MeasHwTq3ClrTrim_Oper(void)
{
  return Rte_Call_HwTq3MeasHwTq3ClrTrim_Oper();
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_HwTq3MeasHwTq3ReadTrim_Oper(float32 *HwTq3MeasHwTq3ReadTrimData_Arg)
{
  return Rte_Call_HwTq3MeasHwTq3ReadTrim_Oper(HwTq3MeasHwTq3ReadTrimData_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_HwTq3MeasHwTq3TrimPrfmdSts_Oper(boolean *HwTq3MeasHwTq3OffsTrimPrfmdStsData_Arg)
{
  return Rte_Call_HwTq3MeasHwTq3TrimPrfmdSts_Oper(HwTq3MeasHwTq3OffsTrimPrfmdStsData_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_HwTq3MeasHwTq3WrTrim_Oper(float32 HwTq3MeasHwTq3WrOffsTrimData_Arg)
{
  return Rte_Call_HwTq3MeasHwTq3WrTrim_Oper(HwTq3MeasHwTq3WrOffsTrimData_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_HwTq4AutTrim_Oper(void)
{
  return Rte_Call_HwTq4AutTrim_Oper();
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_HwTq4ClrSnsrSca_Oper(void)
{
  return Rte_Call_HwTq4ClrSnsrSca_Oper();
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_HwTq4ClrTrim_Oper(void)
{
  return Rte_Call_HwTq4ClrTrim_Oper();
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_HwTq4ReadSnsrSca_Oper(float32 *HwTqReadScaData_Arg)
{
  return Rte_Call_HwTq4ReadSnsrSca_Oper(HwTqReadScaData_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_HwTq4ReadTrim_Oper(float32 *HwTqReadTrimData_Arg)
{
  return Rte_Call_HwTq4ReadTrim_Oper(HwTqReadTrimData_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_HwTq4SnsrScaPrfmdSts_Oper(boolean *HwTqScaPrfmdStsData_Arg)
{
  return Rte_Call_HwTq4SnsrScaPrfmdSts_Oper(HwTqScaPrfmdStsData_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_HwTq4TrimPrfmdSts_Oper(boolean *HwTqOffsTrimPrfmdStsData_Arg)
{
  return Rte_Call_HwTq4TrimPrfmdSts_Oper(HwTqOffsTrimPrfmdStsData_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_HwTq4WrSnsrSca_Oper(float32 HwTqScaVal_Arg)
{
  return Rte_Call_HwTq4WrSnsrSca_Oper(HwTqScaVal_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_HwTq4WrTrim_Oper(float32 HwTqWrOffsTrimData_Arg)
{
  return Rte_Call_HwTq4WrTrim_Oper(HwTqWrOffsTrimData_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_HwTq5AutTrim_Oper(void)
{
  return Rte_Call_HwTq5AutTrim_Oper();
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_HwTq5ClrSnsrSca_Oper(void)
{
  return Rte_Call_HwTq5ClrSnsrSca_Oper();
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_HwTq5ClrTrim_Oper(void)
{
  return Rte_Call_HwTq5ClrTrim_Oper();
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_HwTq5ReadSnsrSca_Oper(float32 *HwTqReadScaData_Arg)
{
  return Rte_Call_HwTq5ReadSnsrSca_Oper(HwTqReadScaData_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_HwTq5ReadTrim_Oper(float32 *HwTqReadTrimData_Arg)
{
  return Rte_Call_HwTq5ReadTrim_Oper(HwTqReadTrimData_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_HwTq5SnsrScaPrfmdSts_Oper(boolean *HwTqScaPrfmdStsData_Arg)
{
  return Rte_Call_HwTq5SnsrScaPrfmdSts_Oper(HwTqScaPrfmdStsData_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_HwTq5TrimPrfmdSts_Oper(boolean *HwTqOffsTrimPrfmdStsData_Arg)
{
  return Rte_Call_HwTq5TrimPrfmdSts_Oper(HwTqOffsTrimPrfmdStsData_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_HwTq5WrSnsrSca_Oper(float32 HwTqScaVal_Arg)
{
  return Rte_Call_HwTq5WrSnsrSca_Oper(HwTqScaVal_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_HwTq5WrTrim_Oper(float32 HwTqWrOffsTrimData_Arg)
{
  return Rte_Call_HwTq5WrTrim_Oper(HwTqWrOffsTrimData_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_InitFricLrngTbl_Oper(void)
{
  return Rte_Call_InitFricLrngTbl_Oper();
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_MotAg0MeasMotAg0CoeffTblRead_Oper(float32 *MotAgCoeffTbl_Arg)
{
  return Rte_Call_MotAg0MeasMotAg0CoeffTblRead_Oper(MotAgCoeffTbl_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_MotAg0MeasMotAg0CoeffTblWr_Oper(const float32 *MotAgCoeffTbl_Arg)
{
  return Rte_Call_MotAg0MeasMotAg0CoeffTblWr_Oper(MotAgCoeffTbl_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_MotAg1MeasMotAg1CoeffTblRead_Oper(float32 *MotAgCoeffTbl_Arg)
{
  return Rte_Call_MotAg1MeasMotAg1CoeffTblRead_Oper(MotAgCoeffTbl_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_MotAg1MeasMotAg1CoeffTblWr_Oper(const float32 *MotAgCoeffTbl_Arg)
{
  return Rte_Call_MotAg1MeasMotAg1CoeffTblWr_Oper(MotAgCoeffTbl_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_MotAg5EolPrmRead_Oper(MotAgEolPrmRec1 *MotAgEolPrmData_Arg)
{
  return Rte_Call_MotAg5EolPrmRead_Oper(MotAgEolPrmData_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_MotAg5EolPrmWr_Oper(const MotAgEolPrmRec1 *MotAgEolPrmData_Arg)
{
  return Rte_Call_MotAg5EolPrmWr_Oper(MotAgEolPrmData_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_MotAg6EolPrmRead_Oper(MotAgEolPrmRec1 *MotAgEolPrmData_Arg)
{
  return Rte_Call_MotAg6EolPrmRead_Oper(MotAgEolPrmData_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_MotAg6EolPrmWr_Oper(const MotAgEolPrmRec1 *MotAgEolPrmData_Arg)
{
  return Rte_Call_MotAg6EolPrmWr_Oper(MotAgEolPrmData_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_MotAgCmpBackEmfRead_Oper(u0p16 *MotAgBackEmfRead)
{
  return Rte_Call_MotAgCmpBackEmfRead_Oper(MotAgBackEmfRead);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_MotAgCmpBackEmfWr_Oper(u0p16 MotAgCmpBackEmfWrData)
{
  return Rte_Call_MotAgCmpBackEmfWr_Oper(MotAgCmpBackEmfWrData);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_MotAgMeasEolPrmRead_Oper(MotAgMeasEolPrmRec1 *MotAgEolPrmRead_Arg)
{
  return Rte_Call_MotAgMeasEolPrmRead_Oper(MotAgEolPrmRead_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_MotAgMeasEolPrmWr_Oper(const MotAgMeasEolPrmRec1 *MotAgSinCosEolCalData_Arg)
{
  return Rte_Call_MotAgMeasEolPrmWr_Oper(MotAgSinCosEolCalData_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_NxtrCalIdsCalDevlpRd_Oper(uint8 CalRegn, uint8 *CalAuthor, uint8 *CalVers, uint32 *CalTiStamp, uint8 *CalDescr)
{
  return Rte_Call_NxtrCalIdsCalDevlpRd_Oper(CalRegn, CalAuthor, CalVers, CalTiStamp, CalDescr);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_NxtrCalIdsCalRelRd_Oper(uint8 CalRegn, uint32 *RelNr, uint8 *RelSt)
{
  return Rte_Call_NxtrCalIdsCalRelRd_Oper(CalRegn, RelNr, RelSt);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_NxtrSwIdsPsrInfoRd_Oper(uint32 *PsrId, uint8 *PsrRev)
{
  return Rte_Call_NxtrSwIdsPsrInfoRd_Oper(PsrId, PsrRev);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_NxtrSwIdsSwBuildDateTiRd_Oper(uint8 *SwBuildDateTi)
{
  return Rte_Call_NxtrSwIdsSwBuildDateTiRd_Oper(SwBuildDateTi);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_NxtrSwIdsSwRelInfoRd_Oper(uint8 *SwOrigin, uint8 *SwAuthor)
{
  return Rte_Call_NxtrSwIdsSwRelInfoRd_Oper(SwOrigin, SwAuthor);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_NxtrSwIdsSwRelNrRd_Oper(uint8 *SwRelNr)
{
  return Rte_Call_NxtrSwIdsSwRelNrRd_Oper(SwRelNr);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_NxtrSwIdsSwRelVerRd_Oper(uint8 *SwRelVer)
{
  return Rte_Call_NxtrSwIdsSwRelVerRd_Oper(SwRelVer);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_PolarityCfgRead_Oper(uint32 *PolarityCfgSaved)
{
  return Rte_Call_PolarityCfgRead_Oper(PolarityCfgSaved);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_PolarityCfgWr_Oper(uint32 PolarityCfgSaved)
{
  return Rte_Call_PolarityCfgWr_Oper(PolarityCfgSaved);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_ReadExtdSnpshtData_Oper(SnpshtDataRec2 *ReadSnpshtDataAry_Arg)
{
  return Rte_Call_ReadExtdSnpshtData_Oper(ReadSnpshtDataAry_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_ReadLtchCntrData_Oper(uint8 *ReadLtchCntrAry_Arg)
{
  return Rte_Call_ReadLtchCntrData_Oper(ReadLtchCntrAry_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_ReadNtcFltAry_Oper(ReadFltInfoRec1 *DiagcMgrReadFltInfo_Arg)
{
  return Rte_Call_ReadNtcFltAry_Oper(DiagcMgrReadFltInfo_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_ReadNtcInfoAndDebCntr_Oper(NtcNr1 NtcNr_Arg, NtcInfoRec4 *NtcInfo_Arg, sint16 *DebCntr_Arg)
{
  return Rte_Call_ReadNtcInfoAndDebCntr_Oper(NtcNr_Arg, NtcInfo_Arg, DebCntr_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_ReadSnpshtData_Oper(SnpshtDataRec1 *ReadSnpshtDataAry_Arg)
{
  return Rte_Call_ReadSnpshtData_Oper(ReadSnpshtDataAry_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_RstHwAgOverTrvlCnt_Oper(void)
{
  return Rte_Call_RstHwAgOverTrvlCnt_Oper();
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_RstHwTq_Oper(void)
{
  return Rte_Call_RstHwTq_Oper();
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_RstMaxHwAgCwAndCcw_Oper(void)
{
  return Rte_Call_RstMaxHwAgCwAndCcw_Oper();
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_RstPullCmp_Oper(void)
{
  return Rte_Call_RstPullCmp_Oper();
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_RstSnsrlsHwCentr_Oper(void)
{
  return Rte_Call_RstSnsrlsHwCentr_Oper();
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_RstYawAndAg_Oper(void)
{
  return Rte_Call_RstYawAndAg_Oper();
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_RtnMaxHwAgCwAndCcw_Oper(float32 *HwAgCcwMax_Arg, float32 *HwAgCwMax_Arg)
{
  return Rte_Call_RtnMaxHwAgCwAndCcw_Oper(HwAgCcwMax_Arg, HwAgCwMax_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_SerlComRstEot_Oper(void)
{
  return Rte_Call_SerlComRstEot_Oper();
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_SetCtrlPrm_Oper(float32 MotVelCtrlPropGain_Arg, float32 MotVelCtrlIntgtrGain_Arg, float32 MotVelCtrlDerivtvGain_Arg, float32 MotVelCtrlAntiWdupLim_Arg, float32 MotVelCtrlAntiWdupGain_Arg, float32 MotVelCtrlDerivtvLpFilTiCon_Arg, float32 MotVelCtrlTqCmdLim_Arg)
{
  return Rte_Call_SetCtrlPrm_Oper(MotVelCtrlPropGain_Arg, MotVelCtrlIntgtrGain_Arg, MotVelCtrlDerivtvGain_Arg, MotVelCtrlAntiWdupLim_Arg, MotVelCtrlAntiWdupGain_Arg, MotVelCtrlDerivtvLpFilTiCon_Arg, MotVelCtrlTqCmdLim_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_SetFricData_Oper(float32 FricOffs_Arg, const float32 *BasLineFric_Arg, const float32 *VehLrndFric_Arg, const float32 *Hys_Arg, const uint16 *RngCntr_Arg)
{
  return Rte_Call_SetFricData_Oper(FricOffs_Arg, BasLineFric_Arg, VehLrndFric_Arg, Hys_Arg, RngCntr_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_SetFricLrngData_Oper(boolean FricLrngEna_Arg, boolean FricLrngOffsOutpEna_Arg, SysFricLrngOperMod1 FricLrngOperMod_Arg, float32 EolFric_Arg)
{
  return Rte_Call_SetFricLrngData_Oper(FricLrngEna_Arg, FricLrngOffsOutpEna_Arg, FricLrngOperMod_Arg, EolFric_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_SetFricOffsOutpDi_Oper(boolean FricOffsOutpDi_Arg)
{
  return Rte_Call_SetFricOffsOutpDi_Oper(FricOffsOutpDi_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_SetHwAgOffs_Oper(float32 HwAgOffs_Arg, boolean HwAgLrngStRst_Arg)
{
  return Rte_Call_SetHwAgOffs_Oper(HwAgOffs_Arg, HwAgLrngStRst_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_SetHwAgOverTrvlCnt_Oper(uint8 HwAgOverTrvlCnt_Arg)
{
  return Rte_Call_SetHwAgOverTrvlCnt_Oper(HwAgOverTrvlCnt_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_SetHwAgTrimVal_Oper(float32 HwAgTrimVal_Arg, boolean HwAgTrimPrfmd_Arg)
{
  return Rte_Call_SetHwAgTrimVal_Oper(HwAgTrimVal_Arg, HwAgTrimPrfmd_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_SetHwTqOffs_Oper(float32 HwTqOffs_Arg, boolean HwTqLrngStRst_Arg)
{
  return Rte_Call_SetHwTqOffs_Oper(HwTqOffs_Arg, HwTqLrngStRst_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_SetManTqCmd_Oper(float32 ManTqCmd, boolean ManTqCmdEna)
{
  return Rte_Call_SetManTqCmd_Oper(ManTqCmd, ManTqCmdEna);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_SetMotCoggCmdPrm_Oper(const s1p14 *MotCoggCmdY_Arg, uint8 Idx_Arg)
{
  return Rte_Call_SetMotCoggCmdPrm_Oper(MotCoggCmdY_Arg, Idx_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_SetMotPrmNomEol_Oper(float32 MotKeNom, float32 MotRNom)
{
  return Rte_Call_SetMotPrmNomEol_Oper(MotKeNom, MotRNom);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_SetMotRplCoggPrm_Oper(uint16 CoggOrder1_Arg, s1p14 CoggOrder1X_Arg, s1p14 CoggOrder1Y_Arg, uint16 CoggOrder2_Arg, s1p14 CoggOrder2X_Arg, s1p14 CoggOrder2Y_Arg, uint16 CoggOrder3_Arg, s1p14 CoggOrder3X_Arg, s1p14 CoggOrder3Y_Arg)
{
  return Rte_Call_SetMotRplCoggPrm_Oper(CoggOrder1_Arg, CoggOrder1X_Arg, CoggOrder1Y_Arg, CoggOrder2_Arg, CoggOrder2X_Arg, CoggOrder2Y_Arg, CoggOrder3_Arg, CoggOrder3X_Arg, CoggOrder3Y_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_SetMotTqCmdSca_Oper(float32 MotTqCmdSca_Arg)
{
  return Rte_Call_SetMotTqCmdSca_Oper(MotTqCmdSca_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_SetPullCmpLongTerm_Oper(float32 PullCmpLongTerm_Arg)
{
  return Rte_Call_SetPullCmpLongTerm_Oper(PullCmpLongTerm_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_SetPullCmpShoTerm_Oper(float32 PullCmpShoTerm_Arg)
{
  return Rte_Call_SetPullCmpShoTerm_Oper(PullCmpShoTerm_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_SetYawRateOffs_Oper(float32 VehYawRateOffs_Arg, boolean VehYawRateLrngStRst_Arg)
{
  return Rte_Call_SetYawRateOffs_Oper(VehYawRateOffs_Arg, VehYawRateLrngStRst_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_StopCtrl_Oper(float32 MotVelCtrlVelSlewRate_Arg)
{
  return Rte_Call_StopCtrl_Oper(MotVelCtrlVelSlewRate_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_StrtCtrl_Oper(float32 MotVelCtrlMotVelTar_Arg, float32 MotVelCtrlVelSlewRate_Arg)
{
  return Rte_Call_StrtCtrl_Oper(MotVelCtrlMotVelTar_Arg, MotVelCtrlVelSlewRate_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_SwCalGetPrm_Oper(float32 *BoostModlnIdx_Arg, float32 *HldModlnIdx_Arg, float32 *CoolDwnModlnIdx_Arg, uint8 *Ramp1Ti_Arg, uint8 *Ramp2Ti_Arg, uint8 *Ramp3Ti_Arg, uint8 *BoostTi_Arg, uint16 *HldTi_Arg, uint16 *CoolDwnTi_Arg, u0p16 *PosnStepSize_Arg, uint8 *ElecRevCnt_Arg)
{
  return Rte_Call_SwCalGetPrm_Oper(BoostModlnIdx_Arg, HldModlnIdx_Arg, CoolDwnModlnIdx_Arg, Ramp1Ti_Arg, Ramp2Ti_Arg, Ramp3Ti_Arg, BoostTi_Arg, HldTi_Arg, CoolDwnTi_Arg, PosnStepSize_Arg, ElecRevCnt_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_SwCalSetPrm_Oper(float32 BoostModlnIdx_Arg, float32 HldModlnIdx_Arg, float32 CoolDwnModlnIdx_Arg, uint8 Ramp1Ti_Arg, uint8 Ramp2Ti_Arg, uint8 Ramp3Ti_Arg, uint8 BoostTi_Arg, uint16 HldTi_Arg, uint16 CoolDwnTi_Arg, u0p16 PosnStepSize_Arg, uint8 ElecRevCnt_Arg)
{
  return Rte_Call_SwCalSetPrm_Oper(BoostModlnIdx_Arg, HldModlnIdx_Arg, CoolDwnModlnIdx_Arg, Ramp1Ti_Arg, Ramp2Ti_Arg, Ramp3Ti_Arg, BoostTi_Arg, HldTi_Arg, CoolDwnTi_Arg, PosnStepSize_Arg, ElecRevCnt_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_SwCalStop_Oper(void)
{
  return Rte_Call_SwCalStop_Oper();
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_SwCalStrt_Oper(void)
{
  return Rte_Call_SwCalStrt_Oper();
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_UpdErrInjReg_Oper(uint16 NtcNr_Arg, uint8 NtcStInfo_Arg, uint8 ErrInjNr_Arg)
{
  return Rte_Call_UpdErrInjReg_Oper(NtcNr_Arg, NtcStInfo_Arg, ErrInjNr_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_UpdHwAgTrimVal_Oper(uint8 *UpdHwAgTrimValSrvResp_Arg)
{
  return Rte_Call_UpdHwAgTrimVal_Oper(UpdHwAgTrimValSrvResp_Arg);
}


     /* Service calls */
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_NvmCcaHwPartNr_SetRamBlockStatus(boolean RamBlockStatus_Arg)
{
  return Rte_Call_NvmCcaHwPartNr_SetRamBlockStatus(RamBlockStatus_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_NvmCcaSerlNr_SetRamBlockStatus(boolean RamBlockStatus_Arg)
{
  return Rte_Call_NvmCcaSerlNr_SetRamBlockStatus(RamBlockStatus_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_NvmDiRestore_SetRamBlockStatus(boolean RamBlockStatus_Arg)
{
  return Rte_Call_NvmDiRestore_SetRamBlockStatus(RamBlockStatus_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_NvmEpsSysSerlNr_SetRamBlockStatus(boolean RamBlockStatus_Arg)
{
  return Rte_Call_NvmEpsSysSerlNr_SetRamBlockStatus(RamBlockStatus_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_NvmIgnCntr_SetRamBlockStatus(boolean RamBlockStatus_Arg)
{
  return Rte_Call_NvmIgnCntr_SetRamBlockStatus(RamBlockStatus_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_NvmMfgEnaCntr_SetRamBlockStatus(boolean RamBlockStatus_Arg)
{
  return Rte_Call_NvmMfgEnaCntr_SetRamBlockStatus(RamBlockStatus_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_NvmMfgTmpBuf0_SetRamBlockStatus(boolean RamBlockStatus_Arg)
{
  return Rte_Call_NvmMfgTmpBuf0_SetRamBlockStatus(RamBlockStatus_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_NvmMfgTmpBuf1_SetRamBlockStatus(boolean RamBlockStatus_Arg)
{
  return Rte_Call_NvmMfgTmpBuf1_SetRamBlockStatus(RamBlockStatus_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_NvmMfgTmpBuf2_SetRamBlockStatus(boolean RamBlockStatus_Arg)
{
  return Rte_Call_NvmMfgTmpBuf2_SetRamBlockStatus(RamBlockStatus_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_NvmMfgTmpBuf3_SetRamBlockStatus(boolean RamBlockStatus_Arg)
{
  return Rte_Call_NvmMfgTmpBuf3_SetRamBlockStatus(RamBlockStatus_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_NvmMfgTmpBuf4_SetRamBlockStatus(boolean RamBlockStatus_Arg)
{
  return Rte_Call_NvmMfgTmpBuf4_SetRamBlockStatus(RamBlockStatus_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_NvmSeedKey_EraseBlock(void)
{
  return Rte_Call_NvmSeedKey_EraseBlock();
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_NvmSeedKey_GetErrorStatus(NvM_RequestResultType *ErrorStatus_Arg)
{
  return Rte_Call_NvmSeedKey_GetErrorStatus(ErrorStatus_Arg);
}
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_NvmSeedKey_SetRamBlockStatus(boolean RamBlockStatus_Arg)
{
  return Rte_Call_NvmSeedKey_SetRamBlockStatus(RamBlockStatus_Arg);
}


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */
Std_ReturnType TSC_CmnMfgSrv_Rte_Call_CmnMfgSrvIfCmnMfgSrvIfImdtTx_Oper(const uint8 *CmnMfgSrvCmnMfgSrvDataBufferPtr, uint16 CmnMfgSrvCmnMfgSrvDataLen)
{
  return Rte_Call_CmnMfgSrvIfCmnMfgSrvIfImdtTx_Oper(CmnMfgSrvCmnMfgSrvDataBufferPtr, CmnMfgSrvCmnMfgSrvDataLen);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */









Std_ReturnType TSC_CmnMfgSrv_Rte_Write_AssiMechTEstimnDi_Logl(boolean data)
{
  return Rte_Write_AssiMechTEstimnDi_Logl(data);
}

Std_ReturnType TSC_CmnMfgSrv_Rte_Write_DampgCmdBasDi_Logl(boolean data)
{
  return Rte_Write_DampgCmdBasDi_Logl(data);
}

Std_ReturnType TSC_CmnMfgSrv_Rte_Write_DutyCycThermProtnDi_Logl(boolean data)
{
  return Rte_Write_DutyCycThermProtnDi_Logl(data);
}

Std_ReturnType TSC_CmnMfgSrv_Rte_Write_EotProtnDi_Logl(boolean data)
{
  return Rte_Write_EotProtnDi_Logl(data);
}

Std_ReturnType TSC_CmnMfgSrv_Rte_Write_FricLrngDi_Logl(boolean data)
{
  return Rte_Write_FricLrngDi_Logl(data);
}

Std_ReturnType TSC_CmnMfgSrv_Rte_Write_HysCmpCmdDi_Logl(boolean data)
{
  return Rte_Write_HysCmpCmdDi_Logl(data);
}

Std_ReturnType TSC_CmnMfgSrv_Rte_Write_InertiaCmpVelCmdDi_Logl(boolean data)
{
  return Rte_Write_InertiaCmpVelCmdDi_Logl(data);
}

Std_ReturnType TSC_CmnMfgSrv_Rte_Write_LoaScaDi_Logl(boolean data)
{
  return Rte_Write_LoaScaDi_Logl(data);
}

Std_ReturnType TSC_CmnMfgSrv_Rte_Write_MfgDiagcInhb_Logl(boolean data)
{
  return Rte_Write_MfgDiagcInhb_Logl(data);
}

Std_ReturnType TSC_CmnMfgSrv_Rte_Write_PullCmpCmdDi_Logl(boolean data)
{
  return Rte_Write_PullCmpCmdDi_Logl(data);
}

Std_ReturnType TSC_CmnMfgSrv_Rte_Write_PullCmpLrngDi_Logl(boolean data)
{
  return Rte_Write_PullCmpLrngDi_Logl(data);
}

Std_ReturnType TSC_CmnMfgSrv_Rte_Write_RtnCmdDi_Logl(boolean data)
{
  return Rte_Write_RtnCmdDi_Logl(data);
}

Std_ReturnType TSC_CmnMfgSrv_Rte_Write_StallMotTqLimDi_Logl(boolean data)
{
  return Rte_Write_StallMotTqLimDi_Logl(data);
}

Std_ReturnType TSC_CmnMfgSrv_Rte_Write_SysMotTqCmdRampRateDi_Logl(boolean data)
{
  return Rte_Write_SysMotTqCmdRampRateDi_Logl(data);
}

Std_ReturnType TSC_CmnMfgSrv_Rte_Write_SysStReqEnaOvrd_Logl(boolean data)
{
  return Rte_Write_SysStReqEnaOvrd_Logl(data);
}





     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */





uint16  TSC_CmnMfgSrv_Rte_Prm_CmnMfgSrvSecuAcsAtmptTiOut_Val(void)
{
  return (uint16 ) Rte_Prm_CmnMfgSrvSecuAcsAtmptTiOut_Val();
}
uint8  TSC_CmnMfgSrv_Rte_Prm_CmnMfgSrvSecuAcsMaxNrAtmpt_Val(void)
{
  return (uint8 ) Rte_Prm_CmnMfgSrvSecuAcsMaxNrAtmpt_Val();
}

uint32  TSC_CmnMfgSrv_Rte_CData_NvmIgnCntr_DefaultValue(void)
{
  return (uint32 ) Rte_CData_NvmIgnCntr_DefaultValue();
}
uint8  TSC_CmnMfgSrv_Rte_CData_NvmMfgEnaCntr_DefaultValue(void)
{
  return (uint8 ) Rte_CData_NvmMfgEnaCntr_DefaultValue();
}
Ary1D_u8_10 * TSC_CmnMfgSrv_Rte_CData_NvmNxtrSeedKey_DefaultValue(void)
{
  return (Ary1D_u8_10 *) Rte_CData_NvmNxtrSeedKey_DefaultValue();
}
Ary1D_u32_2 * TSC_CmnMfgSrv_Rte_CData_SeedKeyDft(void)
{
  return (Ary1D_u32_2 *) Rte_CData_SeedKeyDft();
}

     /* CmnMfgSrv */
      /* CmnMfgSrv */

/** Per Instance Memories */
float32 *TSC_CmnMfgSrv_Rte_Pim_InpOutpCtrlAssiGain(void)
{
  return Rte_Pim_InpOutpCtrlAssiGain();
}
float32 *TSC_CmnMfgSrv_Rte_Pim_InpOutpCtrlVehSpdOvrd(void)
{
  return Rte_Pim_InpOutpCtrlVehSpdOvrd();
}
uint32 *TSC_CmnMfgSrv_Rte_Pim_IgnCntr(void)
{
  return Rte_Pim_IgnCntr();
}
uint32 *TSC_CmnMfgSrv_Rte_Pim_SecuAcsAtmptTmr(void)
{
  return Rte_Pim_SecuAcsAtmptTmr();
}
uint32 *TSC_CmnMfgSrv_Rte_Pim_SessionTiOut(void)
{
  return Rte_Pim_SessionTiOut();
}
uint16 *TSC_CmnMfgSrv_Rte_Pim_PerCyc(void)
{
  return Rte_Pim_PerCyc();
}
uint16 *TSC_CmnMfgSrv_Rte_Pim_PerDivdr(void)
{
  return Rte_Pim_PerDivdr();
}
uint16 *TSC_CmnMfgSrv_Rte_Pim_ReqLen(void)
{
  return Rte_Pim_ReqLen();
}
uint8 *TSC_CmnMfgSrv_Rte_Pim_NxtrMfgEnaCntr(void)
{
  return Rte_Pim_NxtrMfgEnaCntr();
}
uint8 *TSC_CmnMfgSrv_Rte_Pim_PerPidTblLen(void)
{
  return Rte_Pim_PerPidTblLen();
}
uint8 *TSC_CmnMfgSrv_Rte_Pim_SecuAcsAtmptCntr(void)
{
  return Rte_Pim_SecuAcsAtmptCntr();
}
uint8 *TSC_CmnMfgSrv_Rte_Pim_SessionCurr(void)
{
  return Rte_Pim_SessionCurr();
}
boolean *TSC_CmnMfgSrv_Rte_Pim_DiAssiMechTEstimn(void)
{
  return Rte_Pim_DiAssiMechTEstimn();
}
boolean *TSC_CmnMfgSrv_Rte_Pim_DiDampg(void)
{
  return Rte_Pim_DiDampg();
}
boolean *TSC_CmnMfgSrv_Rte_Pim_DiDutyCycThermProtn(void)
{
  return Rte_Pim_DiDutyCycThermProtn();
}
boolean *TSC_CmnMfgSrv_Rte_Pim_DiEotProtn(void)
{
  return Rte_Pim_DiEotProtn();
}
boolean *TSC_CmnMfgSrv_Rte_Pim_DiHysCmp(void)
{
  return Rte_Pim_DiHysCmp();
}
boolean *TSC_CmnMfgSrv_Rte_Pim_DiInertiaCmp(void)
{
  return Rte_Pim_DiInertiaCmp();
}
boolean *TSC_CmnMfgSrv_Rte_Pim_DiLoaSca(void)
{
  return Rte_Pim_DiLoaSca();
}
boolean *TSC_CmnMfgSrv_Rte_Pim_DiPullCmpActvCmd(void)
{
  return Rte_Pim_DiPullCmpActvCmd();
}
boolean *TSC_CmnMfgSrv_Rte_Pim_DiPullCmpActvLrng(void)
{
  return Rte_Pim_DiPullCmpActvLrng();
}
boolean *TSC_CmnMfgSrv_Rte_Pim_DiRtn(void)
{
  return Rte_Pim_DiRtn();
}
boolean *TSC_CmnMfgSrv_Rte_Pim_DiStallMotTqLim(void)
{
  return Rte_Pim_DiStallMotTqLim();
}
boolean *TSC_CmnMfgSrv_Rte_Pim_DiSysFricLrng(void)
{
  return Rte_Pim_DiSysFricLrng();
}
boolean *TSC_CmnMfgSrv_Rte_Pim_DiSysMotTqCmdRampRate(void)
{
  return Rte_Pim_DiSysMotTqCmdRampRate();
}
boolean *TSC_CmnMfgSrv_Rte_Pim_MfgDiagcInhb(void)
{
  return Rte_Pim_MfgDiagcInhb();
}
boolean *TSC_CmnMfgSrv_Rte_Pim_PerRunng(void)
{
  return Rte_Pim_PerRunng();
}
boolean *TSC_CmnMfgSrv_Rte_Pim_SecuAcsSeedReqCmpl(void)
{
  return Rte_Pim_SecuAcsSeedReqCmpl();
}
boolean *TSC_CmnMfgSrv_Rte_Pim_SecuAcsUnlckd(void)
{
  return Rte_Pim_SecuAcsUnlckd();
}
boolean *TSC_CmnMfgSrv_Rte_Pim_SysStReqEnaOvrd(void)
{
  return Rte_Pim_SysStReqEnaOvrd();
}
uint8 *TSC_CmnMfgSrv_Rte_Pim_CcaHwPartNr(void)
{
  return Rte_Pim_CcaHwPartNr();
}
uint8 *TSC_CmnMfgSrv_Rte_Pim_CcaSerlNr(void)
{
  return Rte_Pim_CcaSerlNr();
}
uint8 *TSC_CmnMfgSrv_Rte_Pim_DiRestore(void)
{
  return Rte_Pim_DiRestore();
}
uint8 *TSC_CmnMfgSrv_Rte_Pim_EpsSysSerlNr(void)
{
  return Rte_Pim_EpsSysSerlNr();
}
uint8 *TSC_CmnMfgSrv_Rte_Pim_MfgTmpBuf0(void)
{
  return Rte_Pim_MfgTmpBuf0();
}
uint8 *TSC_CmnMfgSrv_Rte_Pim_MfgTmpBuf1(void)
{
  return Rte_Pim_MfgTmpBuf1();
}
uint8 *TSC_CmnMfgSrv_Rte_Pim_MfgTmpBuf2(void)
{
  return Rte_Pim_MfgTmpBuf2();
}
uint8 *TSC_CmnMfgSrv_Rte_Pim_MfgTmpBuf3(void)
{
  return Rte_Pim_MfgTmpBuf3();
}
uint8 *TSC_CmnMfgSrv_Rte_Pim_MfgTmpBuf4(void)
{
  return Rte_Pim_MfgTmpBuf4();
}
uint16 *TSC_CmnMfgSrv_Rte_Pim_PerPidTbl(void)
{
  return Rte_Pim_PerPidTbl();
}
uint32 *TSC_CmnMfgSrv_Rte_Pim_SeedKey(void)
{
  return Rte_Pim_SeedKey();
}



