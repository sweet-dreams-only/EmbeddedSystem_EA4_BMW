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
 *          File:  TSC_EotProtn.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_EotProtn.h"
#include "TSC_EotProtn.h"















     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_EotProtn_Rte_Read_EotProtnDi_Logl(boolean *data)
{
  return Rte_Read_EotProtnDi_Logl(data);
}

Std_ReturnType TSC_EotProtn_Rte_Read_HwAg_Val(float32 *data)
{
  return Rte_Read_HwAg_Val(data);
}

Std_ReturnType TSC_EotProtn_Rte_Read_HwAgAuthy_Val(float32 *data)
{
  return Rte_Read_HwAgAuthy_Val(data);
}

Std_ReturnType TSC_EotProtn_Rte_Read_HwAgCcwDetd_Logl(boolean *data)
{
  return Rte_Read_HwAgCcwDetd_Logl(data);
}

Std_ReturnType TSC_EotProtn_Rte_Read_HwAgCwDetd_Logl(boolean *data)
{
  return Rte_Read_HwAgCwDetd_Logl(data);
}

Std_ReturnType TSC_EotProtn_Rte_Read_HwAgEotCcw_Val(float32 *data)
{
  return Rte_Read_HwAgEotCcw_Val(data);
}

Std_ReturnType TSC_EotProtn_Rte_Read_HwAgEotCw_Val(float32 *data)
{
  return Rte_Read_HwAgEotCw_Val(data);
}

Std_ReturnType TSC_EotProtn_Rte_Read_HwTq_Val(float32 *data)
{
  return Rte_Read_HwTq_Val(data);
}

Std_ReturnType TSC_EotProtn_Rte_Read_MotVelCrf_Val(float32 *data)
{
  return Rte_Read_MotVelCrf_Val(data);
}

Std_ReturnType TSC_EotProtn_Rte_Read_SysMotTqCmdSca_Val(float32 *data)
{
  return Rte_Read_SysMotTqCmdSca_Val(data);
}

Std_ReturnType TSC_EotProtn_Rte_Read_VehSpd_Val(float32 *data)
{
  return Rte_Read_VehSpd_Val(data);
}




Std_ReturnType TSC_EotProtn_Rte_Write_EotActvCmd_Val(float32 data)
{
  return Rte_Write_EotActvCmd_Val(data);
}

Std_ReturnType TSC_EotProtn_Rte_Write_EotAssiSca_Val(float32 data)
{
  return Rte_Write_EotAssiSca_Val(data);
}

Std_ReturnType TSC_EotProtn_Rte_Write_EotDampgCmd_Val(float32 data)
{
  return Rte_Write_EotDampgCmd_Val(data);
}

Std_ReturnType TSC_EotProtn_Rte_Write_EotMotTqLim_Val(float32 data)
{
  return Rte_Write_EotMotTqLim_Val(data);
}





     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */





float32  TSC_EotProtn_Rte_Prm_EotProtnActvRegnBypMaxThd_Val(void)
{
  return (float32 ) Rte_Prm_EotProtnActvRegnBypMaxThd_Val();
}
float32  TSC_EotProtn_Rte_Prm_EotProtnDampgSlew_Val(void)
{
  return (float32 ) Rte_Prm_EotProtnDampgSlew_Val();
}
float32  TSC_EotProtn_Rte_Prm_EotProtnDeltaTqThd_Val(void)
{
  return (float32 ) Rte_Prm_EotProtnDeltaTqThd_Val();
}
float32  TSC_EotProtn_Rte_Prm_EotProtnDftPosn_Val(void)
{
  return (float32 ) Rte_Prm_EotProtnDftPosn_Val();
}
float32  TSC_EotProtn_Rte_Prm_EotProtnEntrGainAuthyThd_Val(void)
{
  return (float32 ) Rte_Prm_EotProtnEntrGainAuthyThd_Val();
}
float32  TSC_EotProtn_Rte_Prm_EotProtnEntrStLpFilFrq_Val(void)
{
  return (float32 ) Rte_Prm_EotProtnEntrStLpFilFrq_Val();
}
float32  TSC_EotProtn_Rte_Prm_EotProtnExitStLpFilFrq_Val(void)
{
  return (float32 ) Rte_Prm_EotProtnExitStLpFilFrq_Val();
}
float32  TSC_EotProtn_Rte_Prm_EotProtnHwAgGain_Val(void)
{
  return (float32 ) Rte_Prm_EotProtnHwAgGain_Val();
}
float32  TSC_EotProtn_Rte_Prm_EotProtnHwAgMax_Val(void)
{
  return (float32 ) Rte_Prm_EotProtnHwAgMax_Val();
}
float32  TSC_EotProtn_Rte_Prm_EotProtnHwAgMin_Val(void)
{
  return (float32 ) Rte_Prm_EotProtnHwAgMin_Val();
}
float32  TSC_EotProtn_Rte_Prm_EotProtnHwTqLpFilFrq_Val(void)
{
  return (float32 ) Rte_Prm_EotProtnHwTqLpFilFrq_Val();
}
float32  TSC_EotProtn_Rte_Prm_EotProtnMotSpdIncptSca_Val(void)
{
  return (float32 ) Rte_Prm_EotProtnMotSpdIncptSca_Val();
}
float32  TSC_EotProtn_Rte_Prm_EotProtnMotVelGain_Val(void)
{
  return (float32 ) Rte_Prm_EotProtnMotVelGain_Val();
}
float32  TSC_EotProtn_Rte_Prm_EotProtnPosnRampStep_Val(void)
{
  return (float32 ) Rte_Prm_EotProtnPosnRampStep_Val();
}
float32  TSC_EotProtn_Rte_Prm_EotProtnRackTrvlLimrAuthyThd_Val(void)
{
  return (float32 ) Rte_Prm_EotProtnRackTrvlLimrAuthyThd_Val();
}
float32  TSC_EotProtn_Rte_Prm_EotProtnRackTrvlLimrAuthyThdLimd_Val(void)
{
  return (float32 ) Rte_Prm_EotProtnRackTrvlLimrAuthyThdLimd_Val();
}
float32  TSC_EotProtn_Rte_Prm_EotProtnRackTrvlLimrRng_Val(void)
{
  return (float32 ) Rte_Prm_EotProtnRackTrvlLimrRng_Val();
}
float32  TSC_EotProtn_Rte_Prm_EotProtnRackTrvlLimrRngLimd_Val(void)
{
  return (float32 ) Rte_Prm_EotProtnRackTrvlLimrRngLimd_Val();
}
float32  TSC_EotProtn_Rte_Prm_EotProtnRackTrvlLimrVehSpdThd_Val(void)
{
  return (float32 ) Rte_Prm_EotProtnRackTrvlLimrVehSpdThd_Val();
}
float32  TSC_EotProtn_Rte_Prm_EotProtnSoftEndStopAuthyThd_Val(void)
{
  return (float32 ) Rte_Prm_EotProtnSoftEndStopAuthyThd_Val();
}
float32  TSC_EotProtn_Rte_Prm_EotProtnSoftEndStopVehSpdThd_Val(void)
{
  return (float32 ) Rte_Prm_EotProtnSoftEndStopVehSpdThd_Val();
}
boolean  TSC_EotProtn_Rte_Prm_EotProtnRackTrvlLimrEna_Logl(void)
{
  return (boolean ) Rte_Prm_EotProtnRackTrvlLimrEna_Logl();
}
boolean  TSC_EotProtn_Rte_Prm_EotProtnRunEotVelImpctAndSoftEndStop_Logl(void)
{
  return (boolean ) Rte_Prm_EotProtnRunEotVelImpctAndSoftEndStop_Logl();
}
boolean  TSC_EotProtn_Rte_Prm_EotProtnSoftEndStopEna_Logl(void)
{
  return (boolean ) Rte_Prm_EotProtnSoftEndStopEna_Logl();
}
Ary1D_u9p7_4 * TSC_EotProtn_Rte_Prm_EotProtnDampgVehSpdTbl_Ary1D(void)
{
  return (Ary1D_u9p7_4 *) Rte_Prm_EotProtnDampgVehSpdTbl_Ary1D();
}
Ary1D_u9p7_5 * TSC_EotProtn_Rte_Prm_EotProtnEntrGainVehSpdTbl_Ary1D(void)
{
  return (Ary1D_u9p7_5 *) Rte_Prm_EotProtnEntrGainVehSpdTbl_Ary1D();
}
Ary2D_u12p4_5_4 * TSC_EotProtn_Rte_Prm_EotProtnEntrGainX_Ary2D(void)
{
  return (Ary2D_u12p4_5_4 *) Rte_Prm_EotProtnEntrGainX_Ary2D();
}
Ary2D_u1p15_5_4 * TSC_EotProtn_Rte_Prm_EotProtnEntrGainY_Ary2D(void)
{
  return (Ary2D_u1p15_5_4 *) Rte_Prm_EotProtnEntrGainY_Ary2D();
}
Ary2D_u0p16_4_2 * TSC_EotProtn_Rte_Prm_EotProtnExitDampgY_Ary2D(void)
{
  return (Ary2D_u0p16_4_2 *) Rte_Prm_EotProtnExitDampgY_Ary2D();
}
Ary2D_u12p4_4_2 * TSC_EotProtn_Rte_Prm_EotProtnHwDegDampgX_Ary2D(void)
{
  return (Ary2D_u12p4_4_2 *) Rte_Prm_EotProtnHwDegDampgX_Ary2D();
}
Ary1D_u4p12_2 * TSC_EotProtn_Rte_Prm_EotProtnHwTqScaX_Ary1D(void)
{
  return (Ary1D_u4p12_2 *) Rte_Prm_EotProtnHwTqScaX_Ary1D();
}
Ary2D_u1p15_5_4 * TSC_EotProtn_Rte_Prm_EotProtnLoAuthyEntrGainY_Ary2D(void)
{
  return (Ary2D_u1p15_5_4 *) Rte_Prm_EotProtnLoAuthyEntrGainY_Ary2D();
}
Ary1D_u12p4_2 * TSC_EotProtn_Rte_Prm_EotProtnMotSpdIncptX_Ary1D(void)
{
  return (Ary1D_u12p4_2 *) Rte_Prm_EotProtnMotSpdIncptX_Ary1D();
}
Ary1D_u12p4_2 * TSC_EotProtn_Rte_Prm_EotProtnMotSpdIncptY_Ary1D(void)
{
  return (Ary1D_u12p4_2 *) Rte_Prm_EotProtnMotSpdIncptY_Ary1D();
}
Ary2D_u0p16_4_2 * TSC_EotProtn_Rte_Prm_EotProtnNormDampgY_Ary2D(void)
{
  return (Ary2D_u0p16_4_2 *) Rte_Prm_EotProtnNormDampgY_Ary2D();
}


     /* EotProtn */
      /* EotProtn */

/** Per Instance Memories */
float32 *TSC_EotProtn_Rte_Pim_PrevEotAssiSca(void)
{
  return Rte_Pim_PrevEotAssiSca();
}
float32 *TSC_EotProtn_Rte_Pim_PrevEotDampg(void)
{
  return Rte_Pim_PrevEotDampg();
}
float32 *TSC_EotProtn_Rte_Pim_PrevImpctPosn(void)
{
  return Rte_Pim_PrevImpctPosn();
}
float32 *TSC_EotProtn_Rte_Pim_dEotProtnDampg(void)
{
  return Rte_Pim_dEotProtnDampg();
}
float32 *TSC_EotProtn_Rte_Pim_dEotProtnEntrGain(void)
{
  return Rte_Pim_dEotProtnEntrGain();
}
float32 *TSC_EotProtn_Rte_Pim_dEotProtnEotAssiSca(void)
{
  return Rte_Pim_dEotProtnEotAssiSca();
}
float32 *TSC_EotProtn_Rte_Pim_dEotProtnEotGain(void)
{
  return Rte_Pim_dEotProtnEotGain();
}
float32 *TSC_EotProtn_Rte_Pim_dEotProtnExitGain(void)
{
  return Rte_Pim_dEotProtnExitGain();
}
float32 *TSC_EotProtn_Rte_Pim_dEotProtnLimPosn(void)
{
  return Rte_Pim_dEotProtnLimPosn();
}
uint8 *TSC_EotProtn_Rte_Pim_NewSoftEndStopSt(void)
{
  return Rte_Pim_NewSoftEndStopSt();
}
uint8 *TSC_EotProtn_Rte_Pim_PrevSoftEndStopSt(void)
{
  return Rte_Pim_PrevSoftEndStopSt();
}
boolean *TSC_EotProtn_Rte_Pim_PrevRackTrvlLimrEna(void)
{
  return Rte_Pim_PrevRackTrvlLimrEna();
}
boolean *TSC_EotProtn_Rte_Pim_PrevRackTrvlLimrInin(void)
{
  return Rte_Pim_PrevRackTrvlLimrInin();
}
boolean *TSC_EotProtn_Rte_Pim_dEotProtnDetd(void)
{
  return Rte_Pim_dEotProtnDetd();
}
boolean *TSC_EotProtn_Rte_Pim_dEotProtnRackTrvlLimrDi(void)
{
  return Rte_Pim_dEotProtnRackTrvlLimrDi();
}
FilLpRec1 *TSC_EotProtn_Rte_Pim_EotAssiScaLpFil(void)
{
  return Rte_Pim_EotAssiScaLpFil();
}
FilLpRec1 *TSC_EotProtn_Rte_Pim_HwTqLpFil(void)
{
  return Rte_Pim_HwTqLpFil();
}



