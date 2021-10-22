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
 *          File:  TSC_TEstimn.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_TEstimn.h"
#include "TSC_TEstimn.h"








Std_ReturnType TSC_TEstimn_Rte_Read_AmbT_Val(float32 *data)
{
  return Rte_Read_AmbT_Val(data);
}

Std_ReturnType TSC_TEstimn_Rte_Read_AmbTVld_Logl(boolean *data)
{
  return Rte_Read_AmbTVld_Logl(data);
}

Std_ReturnType TSC_TEstimn_Rte_Read_DualEcuFltMtgtnEna_Logl(boolean *data)
{
  return Rte_Read_DualEcuFltMtgtnEna_Logl(data);
}

Std_ReturnType TSC_TEstimn_Rte_Read_EcuTFild_Val(float32 *data)
{
  return Rte_Read_EcuTFild_Val(data);
}

Std_ReturnType TSC_TEstimn_Rte_Read_EngOilT_Val(float32 *data)
{
  return Rte_Read_EngOilT_Val(data);
}

Std_ReturnType TSC_TEstimn_Rte_Read_EngOilTVld_Logl(boolean *data)
{
  return Rte_Read_EngOilTVld_Logl(data);
}

Std_ReturnType TSC_TEstimn_Rte_Read_IgnTiOff_Val(uint32 *data)
{
  return Rte_Read_IgnTiOff_Val(data);
}

Std_ReturnType TSC_TEstimn_Rte_Read_MotAndThermProtnLoaMod_Val(uint8 *data)
{
  return Rte_Read_MotAndThermProtnLoaMod_Val(data);
}

Std_ReturnType TSC_TEstimn_Rte_Read_VehTiVld_Logl(boolean *data)
{
  return Rte_Read_VehTiVld_Logl(data);
}




Std_ReturnType TSC_TEstimn_Rte_Write_AssiMechT_Val(float32 data)
{
  return Rte_Write_AssiMechT_Val(data);
}

Std_ReturnType TSC_TEstimn_Rte_Write_MotFetT_Val(float32 data)
{
  return Rte_Write_MotFetT_Val(data);
}

Std_ReturnType TSC_TEstimn_Rte_Write_MotMagT_Val(float32 data)
{
  return Rte_Write_MotMagT_Val(data);
}

Std_ReturnType TSC_TEstimn_Rte_Write_MotWidgT_Val(float32 data)
{
  return Rte_Write_MotWidgT_Val(data);
}





     /* Client Server Interfaces: */


     /* Service calls */
Std_ReturnType TSC_TEstimn_Rte_Call_TFilStVal_GetErrorStatus(NvM_RequestResultType *ErrorStatus_Arg)
{
  return Rte_Call_TFilStVal_GetErrorStatus(ErrorStatus_Arg);
}
Std_ReturnType TSC_TEstimn_Rte_Call_TFilStVal_SetRamBlockStatus(boolean RamBlockStatus_Arg)
{
  return Rte_Call_TFilStVal_SetRamBlockStatus(RamBlockStatus_Arg);
}


     /* Mode Interfaces */




     /* Inter-Runnable variables */

void TSC_TEstimn_Rte_IrvWrite_TEstimnInit1_FilStVariRepInitFlg(boolean data)
{
  Rte_IrvWrite_TEstimnInit1_FilStVariRepInitFlg( data);
}





Std_ReturnType TSC_TEstimn_Rte_Read_AssiMechTEstimnDi_Logl(boolean *data)
{
  return Rte_Read_AssiMechTEstimnDi_Logl(data);
}

Std_ReturnType TSC_TEstimn_Rte_Read_HwVel_Val(float32 *data)
{
  return Rte_Read_HwVel_Val(data);
}

Std_ReturnType TSC_TEstimn_Rte_Read_MotCurrPeakEstimd_Val(float32 *data)
{
  return Rte_Read_MotCurrPeakEstimd_Val(data);
}








     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */
boolean TSC_TEstimn_Rte_IrvRead_TEstimnPer1_FilStVariRepInitFlg(void)
{
return Rte_IrvRead_TEstimnPer1_FilStVariRepInitFlg();
}





float32  TSC_TEstimn_Rte_Prm_TEstimnAssiMechAmbLpFilFrq_Val(void)
{
  return (float32 ) Rte_Prm_TEstimnAssiMechAmbLpFilFrq_Val();
}
float32  TSC_TEstimn_Rte_Prm_TEstimnAssiMechAmbLpFilFrqDualEcuFltMtgtn_Val(void)
{
  return (float32 ) Rte_Prm_TEstimnAssiMechAmbLpFilFrqDualEcuFltMtgtn_Val();
}
float32  TSC_TEstimn_Rte_Prm_TEstimnAssiMechAmbLpFilFrqFetMtgtnEna_Val(void)
{
  return (float32 ) Rte_Prm_TEstimnAssiMechAmbLpFilFrqFetMtgtnEna_Val();
}
float32  TSC_TEstimn_Rte_Prm_TEstimnCuAmbLpFilFrq_Val(void)
{
  return (float32 ) Rte_Prm_TEstimnCuAmbLpFilFrq_Val();
}
float32  TSC_TEstimn_Rte_Prm_TEstimnCuAmbLpFilFrqDualEcuFltMtgtn_Val(void)
{
  return (float32 ) Rte_Prm_TEstimnCuAmbLpFilFrqDualEcuFltMtgtn_Val();
}
float32  TSC_TEstimn_Rte_Prm_TEstimnCuAmbLpFilFrqFetMtgtnEna_Val(void)
{
  return (float32 ) Rte_Prm_TEstimnCuAmbLpFilFrqFetMtgtnEna_Val();
}
float32  TSC_TEstimn_Rte_Prm_TEstimnIgnOffMsgWaitTi_Val(void)
{
  return (float32 ) Rte_Prm_TEstimnIgnOffMsgWaitTi_Val();
}
float32  TSC_TEstimn_Rte_Prm_TEstimnMagAmbLpFilFrq_Val(void)
{
  return (float32 ) Rte_Prm_TEstimnMagAmbLpFilFrq_Val();
}
float32  TSC_TEstimn_Rte_Prm_TEstimnMagAmbLpFilFrqDualEcuFltMtgtn_Val(void)
{
  return (float32 ) Rte_Prm_TEstimnMagAmbLpFilFrqDualEcuFltMtgtn_Val();
}
float32  TSC_TEstimn_Rte_Prm_TEstimnMagAmbLpFilFrqFetMtgtnEna_Val(void)
{
  return (float32 ) Rte_Prm_TEstimnMagAmbLpFilFrqFetMtgtnEna_Val();
}
float32  TSC_TEstimn_Rte_Prm_TEstimnSiAmbLpFilFrq_Val(void)
{
  return (float32 ) Rte_Prm_TEstimnSiAmbLpFilFrq_Val();
}
float32  TSC_TEstimn_Rte_Prm_TEstimnSiAmbLpFilFrqDualEcuFltMtgtn_Val(void)
{
  return (float32 ) Rte_Prm_TEstimnSiAmbLpFilFrqDualEcuFltMtgtn_Val();
}
float32  TSC_TEstimn_Rte_Prm_TEstimnSiAmbLpFilFrqFetMtgtnEna_Val(void)
{
  return (float32 ) Rte_Prm_TEstimnSiAmbLpFilFrqFetMtgtnEna_Val();
}
boolean  TSC_TEstimn_Rte_Prm_TEstimnIgnOffCtrlEna_Logl(void)
{
  return (boolean ) Rte_Prm_TEstimnIgnOffCtrlEna_Logl();
}
Ary1D_f32_3 * TSC_TEstimn_Rte_Prm_TEstimnAmbPwrMplr_Ary1D(void)
{
  return (Ary1D_f32_3 *) Rte_Prm_TEstimnAmbPwrMplr_Ary1D();
}
Ary1D_f32_3 * TSC_TEstimn_Rte_Prm_TEstimnAmbTSca_Ary1D(void)
{
  return (Ary1D_f32_3 *) Rte_Prm_TEstimnAmbTSca_Ary1D();
}
Ary1D_f32_3 * TSC_TEstimn_Rte_Prm_TEstimnAssiMechAmbMplr_Ary1D(void)
{
  return (Ary1D_f32_3 *) Rte_Prm_TEstimnAssiMechAmbMplr_Ary1D();
}
Ary1D_f32_3 * TSC_TEstimn_Rte_Prm_TEstimnAssiMechCorrLim_Ary1D(void)
{
  return (Ary1D_f32_3 *) Rte_Prm_TEstimnAssiMechCorrLim_Ary1D();
}
Ary1D_f32_3 * TSC_TEstimn_Rte_Prm_TEstimnAssiMechDampgSca_Ary1D(void)
{
  return (Ary1D_f32_3 *) Rte_Prm_TEstimnAssiMechDampgSca_Ary1D();
}
Ary1D_f32_3 * TSC_TEstimn_Rte_Prm_TEstimnAssiMechDftT_Ary1D(void)
{
  return (Ary1D_f32_3 *) Rte_Prm_TEstimnAssiMechDftT_Ary1D();
}
Ary1D_f32_3 * TSC_TEstimn_Rte_Prm_TEstimnAssiMechLLFilCoeffA1_Ary1D(void)
{
  return (Ary1D_f32_3 *) Rte_Prm_TEstimnAssiMechLLFilCoeffA1_Ary1D();
}
Ary1D_f32_3 * TSC_TEstimn_Rte_Prm_TEstimnAssiMechLLFilCoeffB0_Ary1D(void)
{
  return (Ary1D_f32_3 *) Rte_Prm_TEstimnAssiMechLLFilCoeffB0_Ary1D();
}
Ary1D_f32_3 * TSC_TEstimn_Rte_Prm_TEstimnAssiMechLLFilCoeffB1_Ary1D(void)
{
  return (Ary1D_f32_3 *) Rte_Prm_TEstimnAssiMechLLFilCoeffB1_Ary1D();
}
Ary1D_f32_3 * TSC_TEstimn_Rte_Prm_TEstimnAssiMechSlew_Ary1D(void)
{
  return (Ary1D_f32_3 *) Rte_Prm_TEstimnAssiMechSlew_Ary1D();
}
Ary1D_f32_3 * TSC_TEstimn_Rte_Prm_TEstimnCorrnTAssiMech_Ary1D(void)
{
  return (Ary1D_f32_3 *) Rte_Prm_TEstimnCorrnTAssiMech_Ary1D();
}
Ary1D_f32_3 * TSC_TEstimn_Rte_Prm_TEstimnCorrnTCu_Ary1D(void)
{
  return (Ary1D_f32_3 *) Rte_Prm_TEstimnCorrnTCu_Ary1D();
}
Ary1D_f32_3 * TSC_TEstimn_Rte_Prm_TEstimnCorrnTMag_Ary1D(void)
{
  return (Ary1D_f32_3 *) Rte_Prm_TEstimnCorrnTMag_Ary1D();
}
Ary1D_f32_3 * TSC_TEstimn_Rte_Prm_TEstimnCorrnTSi_Ary1D(void)
{
  return (Ary1D_f32_3 *) Rte_Prm_TEstimnCorrnTSi_Ary1D();
}
Ary1D_f32_3 * TSC_TEstimn_Rte_Prm_TEstimnCuAmbMplr_Ary1D(void)
{
  return (Ary1D_f32_3 *) Rte_Prm_TEstimnCuAmbMplr_Ary1D();
}
Ary1D_f32_3 * TSC_TEstimn_Rte_Prm_TEstimnCuCorrnLim_Ary1D(void)
{
  return (Ary1D_f32_3 *) Rte_Prm_TEstimnCuCorrnLim_Ary1D();
}
Ary1D_f32_3 * TSC_TEstimn_Rte_Prm_TEstimnCuLLFilCoeffA1_Ary1D(void)
{
  return (Ary1D_f32_3 *) Rte_Prm_TEstimnCuLLFilCoeffA1_Ary1D();
}
Ary1D_f32_3 * TSC_TEstimn_Rte_Prm_TEstimnCuLLFilCoeffB0_Ary1D(void)
{
  return (Ary1D_f32_3 *) Rte_Prm_TEstimnCuLLFilCoeffB0_Ary1D();
}
Ary1D_f32_3 * TSC_TEstimn_Rte_Prm_TEstimnCuLLFilCoeffB1_Ary1D(void)
{
  return (Ary1D_f32_3 *) Rte_Prm_TEstimnCuLLFilCoeffB1_Ary1D();
}
Ary1D_f32_3 * TSC_TEstimn_Rte_Prm_TEstimnEngTSca_Ary1D(void)
{
  return (Ary1D_f32_3 *) Rte_Prm_TEstimnEngTSca_Ary1D();
}
Ary1D_f32_3 * TSC_TEstimn_Rte_Prm_TEstimnMagAmbMplr_Ary1D(void)
{
  return (Ary1D_f32_3 *) Rte_Prm_TEstimnMagAmbMplr_Ary1D();
}
Ary1D_f32_3 * TSC_TEstimn_Rte_Prm_TEstimnMagCorrnLim_Ary1D(void)
{
  return (Ary1D_f32_3 *) Rte_Prm_TEstimnMagCorrnLim_Ary1D();
}
Ary1D_f32_3 * TSC_TEstimn_Rte_Prm_TEstimnMagLLFilCoeffA1_Ary1D(void)
{
  return (Ary1D_f32_3 *) Rte_Prm_TEstimnMagLLFilCoeffA1_Ary1D();
}
Ary1D_f32_3 * TSC_TEstimn_Rte_Prm_TEstimnMagLLFilCoeffB0_Ary1D(void)
{
  return (Ary1D_f32_3 *) Rte_Prm_TEstimnMagLLFilCoeffB0_Ary1D();
}
Ary1D_f32_3 * TSC_TEstimn_Rte_Prm_TEstimnMagLLFilCoeffB1_Ary1D(void)
{
  return (Ary1D_f32_3 *) Rte_Prm_TEstimnMagLLFilCoeffB1_Ary1D();
}
Ary1D_f32_3 * TSC_TEstimn_Rte_Prm_TEstimnSiAmbMplr_Ary1D(void)
{
  return (Ary1D_f32_3 *) Rte_Prm_TEstimnSiAmbMplr_Ary1D();
}
Ary1D_f32_3 * TSC_TEstimn_Rte_Prm_TEstimnSiCorrnLim_Ary1D(void)
{
  return (Ary1D_f32_3 *) Rte_Prm_TEstimnSiCorrnLim_Ary1D();
}
Ary1D_f32_3 * TSC_TEstimn_Rte_Prm_TEstimnSiLLFilCoeffA1_Ary1D(void)
{
  return (Ary1D_f32_3 *) Rte_Prm_TEstimnSiLLFilCoeffA1_Ary1D();
}
Ary1D_f32_3 * TSC_TEstimn_Rte_Prm_TEstimnSiLLFilCoeffB0_Ary1D(void)
{
  return (Ary1D_f32_3 *) Rte_Prm_TEstimnSiLLFilCoeffB0_Ary1D();
}
Ary1D_f32_3 * TSC_TEstimn_Rte_Prm_TEstimnSiLLFilCoeffB1_Ary1D(void)
{
  return (Ary1D_f32_3 *) Rte_Prm_TEstimnSiLLFilCoeffB1_Ary1D();
}
Ary1D_f32_3 * TSC_TEstimn_Rte_Prm_TEstimnTauAssiMech_Ary1D(void)
{
  return (Ary1D_f32_3 *) Rte_Prm_TEstimnTauAssiMech_Ary1D();
}
Ary1D_f32_3 * TSC_TEstimn_Rte_Prm_TEstimnTauCu_Ary1D(void)
{
  return (Ary1D_f32_3 *) Rte_Prm_TEstimnTauCu_Ary1D();
}
Ary1D_f32_3 * TSC_TEstimn_Rte_Prm_TEstimnTauMag_Ary1D(void)
{
  return (Ary1D_f32_3 *) Rte_Prm_TEstimnTauMag_Ary1D();
}
Ary1D_f32_3 * TSC_TEstimn_Rte_Prm_TEstimnTauSi_Ary1D(void)
{
  return (Ary1D_f32_3 *) Rte_Prm_TEstimnTauSi_Ary1D();
}
Ary1D_logl_3 * TSC_TEstimn_Rte_Prm_TEstimnWghtAvrgTDi_Ary1D(void)
{
  return (Ary1D_logl_3 *) Rte_Prm_TEstimnWghtAvrgTDi_Ary1D();
}


     /* TEstimn */
      /* TEstimn */

/** Per Instance Memories */
float32 *TSC_TEstimn_Rte_Pim_AssiMechTEstimnPrev(void)
{
  return Rte_Pim_AssiMechTEstimnPrev();
}
float32 *TSC_TEstimn_Rte_Pim_AssiMechTSlewLimPrev(void)
{
  return Rte_Pim_AssiMechTSlewLimPrev();
}
float32 *TSC_TEstimn_Rte_Pim_CuTEstimnPrev(void)
{
  return Rte_Pim_CuTEstimnPrev();
}
float32 *TSC_TEstimn_Rte_Pim_FilAssiMechLLValPwrUp(void)
{
  return Rte_Pim_FilAssiMechLLValPwrUp();
}
float32 *TSC_TEstimn_Rte_Pim_FilAssiMechLpValPwrUp(void)
{
  return Rte_Pim_FilAssiMechLpValPwrUp();
}
float32 *TSC_TEstimn_Rte_Pim_FilCuLLValPwrUp(void)
{
  return Rte_Pim_FilCuLLValPwrUp();
}
float32 *TSC_TEstimn_Rte_Pim_FilCuLpValPwrUp(void)
{
  return Rte_Pim_FilCuLpValPwrUp();
}
float32 *TSC_TEstimn_Rte_Pim_FilMagLLValPwrUp(void)
{
  return Rte_Pim_FilMagLLValPwrUp();
}
float32 *TSC_TEstimn_Rte_Pim_FilMagLpValPwrUp(void)
{
  return Rte_Pim_FilMagLpValPwrUp();
}
float32 *TSC_TEstimn_Rte_Pim_FilSiLLValPwrUp(void)
{
  return Rte_Pim_FilSiLLValPwrUp();
}
float32 *TSC_TEstimn_Rte_Pim_FilSiLpValPwrUp(void)
{
  return Rte_Pim_FilSiLpValPwrUp();
}
float32 *TSC_TEstimn_Rte_Pim_MagTEstimnPrev(void)
{
  return Rte_Pim_MagTEstimnPrev();
}
float32 *TSC_TEstimn_Rte_Pim_RepInitCntrVal(void)
{
  return Rte_Pim_RepInitCntrVal();
}
float32 *TSC_TEstimn_Rte_Pim_SiTEstimnPrev(void)
{
  return Rte_Pim_SiTEstimnPrev();
}
float32 *TSC_TEstimn_Rte_Pim_dTEstimnAmbPwr(void)
{
  return Rte_Pim_dTEstimnAmbPwr();
}
float32 *TSC_TEstimn_Rte_Pim_dTEstimnAssiMechCorrn(void)
{
  return Rte_Pim_dTEstimnAssiMechCorrn();
}
float32 *TSC_TEstimn_Rte_Pim_dTEstimnAssiMechDampgSca(void)
{
  return Rte_Pim_dTEstimnAssiMechDampgSca();
}
float32 *TSC_TEstimn_Rte_Pim_dTEstimnAssiMechFil(void)
{
  return Rte_Pim_dTEstimnAssiMechFil();
}
float32 *TSC_TEstimn_Rte_Pim_dTEstimnCuCorrn(void)
{
  return Rte_Pim_dTEstimnCuCorrn();
}
float32 *TSC_TEstimn_Rte_Pim_dTEstimnMagCorrn(void)
{
  return Rte_Pim_dTEstimnMagCorrn();
}
float32 *TSC_TEstimn_Rte_Pim_dTEstimnScadAmbT(void)
{
  return Rte_Pim_dTEstimnScadAmbT();
}
float32 *TSC_TEstimn_Rte_Pim_dTEstimnScadEngT(void)
{
  return Rte_Pim_dTEstimnScadEngT();
}
float32 *TSC_TEstimn_Rte_Pim_dTEstimnSiCorrn(void)
{
  return Rte_Pim_dTEstimnSiCorrn();
}
float32 *TSC_TEstimn_Rte_Pim_dTEstimnWghtAvrgT(void)
{
  return Rte_Pim_dTEstimnWghtAvrgT();
}
uint8 *TSC_TEstimn_Rte_Pim_TEstimnFltMtgtnCalIdx(void)
{
  return Rte_Pim_TEstimnFltMtgtnCalIdx();
}
boolean *TSC_TEstimn_Rte_Pim_AmbTVldPrev(void)
{
  return Rte_Pim_AmbTVldPrev();
}
boolean *TSC_TEstimn_Rte_Pim_AssiMechTInitEna(void)
{
  return Rte_Pim_AssiMechTInitEna();
}
boolean *TSC_TEstimn_Rte_Pim_DualEcuFltMtgtnPrev(void)
{
  return Rte_Pim_DualEcuFltMtgtnPrev();
}
boolean *TSC_TEstimn_Rte_Pim_EngOilTVldPrev(void)
{
  return Rte_Pim_EngOilTVldPrev();
}
boolean *TSC_TEstimn_Rte_Pim_FetMtgtnEnaPrev(void)
{
  return Rte_Pim_FetMtgtnEnaPrev();
}
boolean *TSC_TEstimn_Rte_Pim_RepInitCntrFlg(void)
{
  return Rte_Pim_RepInitCntrFlg();
}
FilLpRec1 *TSC_TEstimn_Rte_Pim_AssiMechFilLp(void)
{
  return Rte_Pim_AssiMechFilLp();
}
FilLpRec1 *TSC_TEstimn_Rte_Pim_CuFilLp(void)
{
  return Rte_Pim_CuFilLp();
}
FilLpRec1 *TSC_TEstimn_Rte_Pim_MagFilLp(void)
{
  return Rte_Pim_MagFilLp();
}
FilLpRec1 *TSC_TEstimn_Rte_Pim_SiFilLp(void)
{
  return Rte_Pim_SiFilLp();
}
TFilStValRec1 *TSC_TEstimn_Rte_Pim_TFilStVal(void)
{
  return Rte_Pim_TFilStVal();
}



