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
 *          File:  TSC_MotRefMdl.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_MotRefMdl.h"
#include "TSC_MotRefMdl.h"















     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_MotRefMdl_Rte_Read_BrdgVltg_Val(float32 *data)
{
  return Rte_Read_BrdgVltg_Val(data);
}

Std_ReturnType TSC_MotRefMdl_Rte_Read_DualEcuMotCtrlMtgtnEna_Logl(boolean *data)
{
  return Rte_Read_DualEcuMotCtrlMtgtnEna_Logl(data);
}

Std_ReturnType TSC_MotRefMdl_Rte_Read_MotAndThermProtnLoaMod_Val(uint8 *data)
{
  return Rte_Read_MotAndThermProtnLoaMod_Val(data);
}

Std_ReturnType TSC_MotRefMdl_Rte_Read_MotBackEmfConEstimd_Val(float32 *data)
{
  return Rte_Read_MotBackEmfConEstimd_Val(data);
}

Std_ReturnType TSC_MotRefMdl_Rte_Read_MotInduDaxEstimd_Val(float32 *data)
{
  return Rte_Read_MotInduDaxEstimd_Val(data);
}

Std_ReturnType TSC_MotRefMdl_Rte_Read_MotInduQaxEstimd_Val(float32 *data)
{
  return Rte_Read_MotInduQaxEstimd_Val(data);
}

Std_ReturnType TSC_MotRefMdl_Rte_Read_MotQuad_Val(MotQuad1 *data)
{
  return Rte_Read_MotQuad_Val(data);
}

Std_ReturnType TSC_MotRefMdl_Rte_Read_MotREstimd_Val(float32 *data)
{
  return Rte_Read_MotREstimd_Val(data);
}

Std_ReturnType TSC_MotRefMdl_Rte_Read_MotTqCmdMrfScad_Val(float32 *data)
{
  return Rte_Read_MotTqCmdMrfScad_Val(data);
}

Std_ReturnType TSC_MotRefMdl_Rte_Read_MotVelMrf_Val(float32 *data)
{
  return Rte_Read_MotVelMrf_Val(data);
}




Std_ReturnType TSC_MotRefMdl_Rte_Write_MotBackEmfVltg_Val(float32 data)
{
  return Rte_Write_MotBackEmfVltg_Val(data);
}

Std_ReturnType TSC_MotRefMdl_Rte_Write_MotCurrAg_Val(float32 data)
{
  return Rte_Write_MotCurrAg_Val(data);
}

Std_ReturnType TSC_MotRefMdl_Rte_Write_MotCurrDaxCmd_Val(float32 data)
{
  return Rte_Write_MotCurrDaxCmd_Val(data);
}

Std_ReturnType TSC_MotRefMdl_Rte_Write_MotCurrDaxMax_Val(float32 data)
{
  return Rte_Write_MotCurrDaxMax_Val(data);
}

Std_ReturnType TSC_MotRefMdl_Rte_Write_MotCurrQaxCmd_Val(float32 data)
{
  return Rte_Write_MotCurrQaxCmd_Val(data);
}

Std_ReturnType TSC_MotRefMdl_Rte_Write_MotReacncDax_Val(float32 data)
{
  return Rte_Write_MotReacncDax_Val(data);
}

Std_ReturnType TSC_MotRefMdl_Rte_Write_MotReacncQax_Val(float32 data)
{
  return Rte_Write_MotReacncQax_Val(data);
}

Std_ReturnType TSC_MotRefMdl_Rte_Write_MotVltgDaxFf_Val(float32 data)
{
  return Rte_Write_MotVltgDaxFf_Val(data);
}

Std_ReturnType TSC_MotRefMdl_Rte_Write_MotVltgDaxFfStat_Val(float32 data)
{
  return Rte_Write_MotVltgDaxFfStat_Val(data);
}

Std_ReturnType TSC_MotRefMdl_Rte_Write_MotVltgQaxFf_Val(float32 data)
{
  return Rte_Write_MotVltgQaxFf_Val(data);
}

Std_ReturnType TSC_MotRefMdl_Rte_Write_MotVltgQaxFfStat_Val(float32 data)
{
  return Rte_Write_MotVltgQaxFfStat_Val(data);
}

Std_ReturnType TSC_MotRefMdl_Rte_Write_MotVltgSatnIndFf_Val(float32 data)
{
  return Rte_Write_MotVltgSatnIndFf_Val(data);
}





     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */





float32  TSC_MotRefMdl_Rte_Prm_MotRefMdlCurrDaxBoostGain_Val(void)
{
  return (float32 ) Rte_Prm_MotRefMdlCurrDaxBoostGain_Val();
}
float32  TSC_MotRefMdl_Rte_Prm_MotRefMdlCurrItrnTolr_Val(void)
{
  return (float32 ) Rte_Prm_MotRefMdlCurrItrnTolr_Val();
}
float32  TSC_MotRefMdl_Rte_Prm_MotRefMdlIvtrDeadTiBrdgVltgSca_Val(void)
{
  return (float32 ) Rte_Prm_MotRefMdlIvtrDeadTiBrdgVltgSca_Val();
}
float32  TSC_MotRefMdl_Rte_Prm_MotRefMdlMotCurrDaxMaxSca_Val(void)
{
  return (float32 ) Rte_Prm_MotRefMdlMotCurrDaxMaxSca_Val();
}
float32  TSC_MotRefMdl_Rte_Prm_MotRefMdlMotVelLpFilFrq_Val(void)
{
  return (float32 ) Rte_Prm_MotRefMdlMotVelLpFilFrq_Val();
}
float32  TSC_MotRefMdl_Rte_Prm_MotRefMdlMotVltgDerivtvTiCon_Val(void)
{
  return (float32 ) Rte_Prm_MotRefMdlMotVltgDerivtvTiCon_Val();
}
float32  TSC_MotRefMdl_Rte_Prm_MotRefMdlTqItrnTolr_Val(void)
{
  return (float32 ) Rte_Prm_MotRefMdlTqItrnTolr_Val();
}
float32  TSC_MotRefMdl_Rte_Prm_MotRefMdlVltgOverRThdSca_Val(void)
{
  return (float32 ) Rte_Prm_MotRefMdlVltgOverRThdSca_Val();
}
uint8  TSC_MotRefMdl_Rte_Prm_MotRefMdlMinCurrItrnLim_Val(void)
{
  return (uint8 ) Rte_Prm_MotRefMdlMinCurrItrnLim_Val();
}
uint8  TSC_MotRefMdl_Rte_Prm_MotRefMdlRefLocnItrnLim_Val(void)
{
  return (uint8 ) Rte_Prm_MotRefMdlRefLocnItrnLim_Val();
}
uint8  TSC_MotRefMdl_Rte_Prm_MotRefMdlTqItrnLim_Val(void)
{
  return (uint8 ) Rte_Prm_MotRefMdlTqItrnLim_Val();
}
uint8  TSC_MotRefMdl_Rte_Prm_SysGlbPrmMotPoleCnt_Val(void)
{
  return (uint8 ) Rte_Prm_SysGlbPrmMotPoleCnt_Val();
}
boolean  TSC_MotRefMdl_Rte_Prm_MotRefMdlFbCtrlDi_Logl(void)
{
  return (boolean ) Rte_Prm_MotRefMdlFbCtrlDi_Logl();
}
boolean  TSC_MotRefMdl_Rte_Prm_MotRefMdlVltgModDynCmpEna_Logl(void)
{
  return (boolean ) Rte_Prm_MotRefMdlVltgModDynCmpEna_Logl();
}
Ary1D_u4p12_11 * TSC_MotRefMdl_Rte_Prm_MotRefMdlCurrDaxBoostTqScaX_Ary1D(void)
{
  return (Ary1D_u4p12_11 *) Rte_Prm_MotRefMdlCurrDaxBoostTqScaX_Ary1D();
}
Ary1D_u1p15_11 * TSC_MotRefMdl_Rte_Prm_MotRefMdlCurrDaxBoostTqScaY_Ary1D(void)
{
  return (Ary1D_u1p15_11 *) Rte_Prm_MotRefMdlCurrDaxBoostTqScaY_Ary1D();
}
Ary1D_f32_8 * TSC_MotRefMdl_Rte_Prm_MotRefMdlCurrDaxQaxRefDelta_Ary1D(void)
{
  return (Ary1D_f32_8 *) Rte_Prm_MotRefMdlCurrDaxQaxRefDelta_Ary1D();
}
Ary1D_u11p5_10 * TSC_MotRefMdl_Rte_Prm_MotRefMdlQuad13VltgSdlX_Ary1D(void)
{
  return (Ary1D_u11p5_10 *) Rte_Prm_MotRefMdlQuad13VltgSdlX_Ary1D();
}
Ary1D_u3p13_10 * TSC_MotRefMdl_Rte_Prm_MotRefMdlQuad13VltgSdlY_Ary1D(void)
{
  return (Ary1D_u3p13_10 *) Rte_Prm_MotRefMdlQuad13VltgSdlY_Ary1D();
}
Ary1D_u11p5_10 * TSC_MotRefMdl_Rte_Prm_MotRefMdlQuad24VltgSdlX_Ary1D(void)
{
  return (Ary1D_u11p5_10 *) Rte_Prm_MotRefMdlQuad24VltgSdlX_Ary1D();
}
Ary1D_u3p13_10 * TSC_MotRefMdl_Rte_Prm_MotRefMdlQuad24VltgSdlY_Ary1D(void)
{
  return (Ary1D_u3p13_10 *) Rte_Prm_MotRefMdlQuad24VltgSdlY_Ary1D();
}


     /* MotRefMdl */
      /* MotRefMdl */

/** Per Instance Memories */
float32 *TSC_MotRefMdl_Rte_Pim_MotCurrDaxCmdPrev(void)
{
  return Rte_Pim_MotCurrDaxCmdPrev();
}
float32 *TSC_MotRefMdl_Rte_Pim_MotCurrQaxCmdPrev(void)
{
  return Rte_Pim_MotCurrQaxCmdPrev();
}
float32 *TSC_MotRefMdl_Rte_Pim_VltgDaxFfTermPrev(void)
{
  return Rte_Pim_VltgDaxFfTermPrev();
}
float32 *TSC_MotRefMdl_Rte_Pim_VltgQaxFfTermPrev(void)
{
  return Rte_Pim_VltgQaxFfTermPrev();
}
float32 *TSC_MotRefMdl_Rte_Pim_dMotRefMdlCurrDaxAtPeakTq(void)
{
  return Rte_Pim_dMotRefMdlCurrDaxAtPeakTq();
}
float32 *TSC_MotRefMdl_Rte_Pim_dMotRefMdlCurrDaxMin(void)
{
  return Rte_Pim_dMotRefMdlCurrDaxMin();
}
float32 *TSC_MotRefMdl_Rte_Pim_dMotRefMdlCurrQaxMin(void)
{
  return Rte_Pim_dMotRefMdlCurrQaxMin();
}
float32 *TSC_MotRefMdl_Rte_Pim_dMotRefMdlCurrSqdMin(void)
{
  return Rte_Pim_dMotRefMdlCurrSqdMin();
}
float32 *TSC_MotRefMdl_Rte_Pim_dMotRefMdlInterCalcnCurrDaxMax(void)
{
  return Rte_Pim_dMotRefMdlInterCalcnCurrDaxMax();
}
float32 *TSC_MotRefMdl_Rte_Pim_dMotRefMdlMotCurrDaxBoost(void)
{
  return Rte_Pim_dMotRefMdlMotCurrDaxBoost();
}
float32 *TSC_MotRefMdl_Rte_Pim_dMotRefMdlMotTqCmdLimd(void)
{
  return Rte_Pim_dMotRefMdlMotTqCmdLimd();
}
float32 *TSC_MotRefMdl_Rte_Pim_dMotRefMdlMotVelFildFf(void)
{
  return Rte_Pim_dMotRefMdlMotVelFildFf();
}
float32 *TSC_MotRefMdl_Rte_Pim_dMotRefMdlMotVltgDaxFfDyn(void)
{
  return Rte_Pim_dMotRefMdlMotVltgDaxFfDyn();
}
float32 *TSC_MotRefMdl_Rte_Pim_dMotRefMdlMotVltgDaxFfDynTerm(void)
{
  return Rte_Pim_dMotRefMdlMotVltgDaxFfDynTerm();
}
float32 *TSC_MotRefMdl_Rte_Pim_dMotRefMdlMotVltgDaxFfStat(void)
{
  return Rte_Pim_dMotRefMdlMotVltgDaxFfStat();
}
float32 *TSC_MotRefMdl_Rte_Pim_dMotRefMdlMotVltgQaxFfDyn(void)
{
  return Rte_Pim_dMotRefMdlMotVltgQaxFfDyn();
}
float32 *TSC_MotRefMdl_Rte_Pim_dMotRefMdlMotVltgQaxFfDynTerm(void)
{
  return Rte_Pim_dMotRefMdlMotVltgQaxFfDynTerm();
}
float32 *TSC_MotRefMdl_Rte_Pim_dMotRefMdlMotVltgQaxFfStat(void)
{
  return Rte_Pim_dMotRefMdlMotVltgQaxFfStat();
}
float32 *TSC_MotRefMdl_Rte_Pim_dMotRefMdlPeakTq(void)
{
  return Rte_Pim_dMotRefMdlPeakTq();
}
float32 *TSC_MotRefMdl_Rte_Pim_dMotRefMdlPhaAdvAtPeakTq(void)
{
  return Rte_Pim_dMotRefMdlPhaAdvAtPeakTq();
}
float32 *TSC_MotRefMdl_Rte_Pim_dMotRefMdlReacncDaxOverR(void)
{
  return Rte_Pim_dMotRefMdlReacncDaxOverR();
}
float32 *TSC_MotRefMdl_Rte_Pim_dMotRefMdlReacncQaxOverR(void)
{
  return Rte_Pim_dMotRefMdlReacncQaxOverR();
}
float32 *TSC_MotRefMdl_Rte_Pim_dMotRefMdlRelncTqCoeff(void)
{
  return Rte_Pim_dMotRefMdlRelncTqCoeff();
}
uint8 *TSC_MotRefMdl_Rte_Pim_dMotRefMdlMinCurrNrItrn(void)
{
  return Rte_Pim_dMotRefMdlMinCurrNrItrn();
}
uint8 *TSC_MotRefMdl_Rte_Pim_dMotRefMdlPeakTqNrItrn(void)
{
  return Rte_Pim_dMotRefMdlPeakTqNrItrn();
}
float32 *TSC_MotRefMdl_Rte_Pim_CosDelta(void)
{
  return Rte_Pim_CosDelta();
}
float32 *TSC_MotRefMdl_Rte_Pim_SinDelta(void)
{
  return Rte_Pim_SinDelta();
}
FilLpRec1 *TSC_MotRefMdl_Rte_Pim_MotVelLpFil(void)
{
  return Rte_Pim_MotVelLpFil();
}



