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
 *          File:  TSC_CtrldVelRtn.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_CtrldVelRtn.h"
#include "TSC_CtrldVelRtn.h"















     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_CtrldVelRtn_Rte_Read_AssiMechPolarity_Val(sint8 *data)
{
  return Rte_Read_AssiMechPolarity_Val(data);
}

Std_ReturnType TSC_CtrldVelRtn_Rte_Read_HwAg_Val(float32 *data)
{
  return Rte_Read_HwAg_Val(data);
}

Std_ReturnType TSC_CtrldVelRtn_Rte_Read_HwAgAuthy_Val(float32 *data)
{
  return Rte_Read_HwAgAuthy_Val(data);
}

Std_ReturnType TSC_CtrldVelRtn_Rte_Read_HwAgRtnOffs_Val(float32 *data)
{
  return Rte_Read_HwAgRtnOffs_Val(data);
}

Std_ReturnType TSC_CtrldVelRtn_Rte_Read_HwTq_Val(float32 *data)
{
  return Rte_Read_HwTq_Val(data);
}

Std_ReturnType TSC_CtrldVelRtn_Rte_Read_HwVel_Val(float32 *data)
{
  return Rte_Read_HwVel_Val(data);
}

Std_ReturnType TSC_CtrldVelRtn_Rte_Read_MotTqCmdPwrLimd_Val(float32 *data)
{
  return Rte_Read_MotTqCmdPwrLimd_Val(data);
}

Std_ReturnType TSC_CtrldVelRtn_Rte_Read_RtnCmdDi_Logl(boolean *data)
{
  return Rte_Read_RtnCmdDi_Logl(data);
}

Std_ReturnType TSC_CtrldVelRtn_Rte_Read_RtnCmdDiagcDi_Logl(boolean *data)
{
  return Rte_Read_RtnCmdDiagcDi_Logl(data);
}

Std_ReturnType TSC_CtrldVelRtn_Rte_Read_RtnCmdSca_Val(float32 *data)
{
  return Rte_Read_RtnCmdSca_Val(data);
}

Std_ReturnType TSC_CtrldVelRtn_Rte_Read_RtnCmdScaServo_Val(float32 *data)
{
  return Rte_Read_RtnCmdScaServo_Val(data);
}

Std_ReturnType TSC_CtrldVelRtn_Rte_Read_VehSpd_Val(float32 *data)
{
  return Rte_Read_VehSpd_Val(data);
}




Std_ReturnType TSC_CtrldVelRtn_Rte_Write_CtrldVelRtnCmd_Val(float32 data)
{
  return Rte_Write_CtrldVelRtnCmd_Val(data);
}





     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */





float32  TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnAntiWdup_Val(void)
{
  return (float32 ) Rte_Prm_CtrldVelRtnAntiWdup_Val();
}
float32  TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnDesVelLpFilFrq_Val(void)
{
  return (float32 ) Rte_Prm_CtrldVelRtnDesVelLpFilFrq_Val();
}
float32  TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnHwAuthySlewThd_Val(void)
{
  return (float32 ) Rte_Prm_CtrldVelRtnHwAuthySlewThd_Val();
}
float32  TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnHwTqLpFilFrq_Val(void)
{
  return (float32 ) Rte_Prm_CtrldVelRtnHwTqLpFilFrq_Val();
}
float32  TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnHwTqScaSelnSlewHiLim_Val(void)
{
  return (float32 ) Rte_Prm_CtrldVelRtnHwTqScaSelnSlewHiLim_Val();
}
float32  TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnHwTqScaSelnSlewLoLim_Val(void)
{
  return (float32 ) Rte_Prm_CtrldVelRtnHwTqScaSelnSlewLoLim_Val();
}
float32  TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnHwTqScaSelnTqThd_Val(void)
{
  return (float32 ) Rte_Prm_CtrldVelRtnHwTqScaSelnTqThd_Val();
}
float32  TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnHwTqScaSelnVelThd_Val(void)
{
  return (float32 ) Rte_Prm_CtrldVelRtnHwTqScaSelnVelThd_Val();
}
float32  TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnOffsSlewThd_Val(void)
{
  return (float32 ) Rte_Prm_CtrldVelRtnOffsSlewThd_Val();
}
float32  TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnOffsThd_Val(void)
{
  return (float32 ) Rte_Prm_CtrldVelRtnOffsThd_Val();
}
float32  TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnScaLpFilFrq_Val(void)
{
  return (float32 ) Rte_Prm_CtrldVelRtnScaLpFilFrq_Val();
}
float32  TSC_CtrldVelRtn_Rte_Prm_SysGlbPrmSysTqRat_Val(void)
{
  return (float32 ) Rte_Prm_SysGlbPrmSysTqRat_Val();
}
boolean  TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnDampgEna_Logl(void)
{
  return (boolean ) Rte_Prm_CtrldVelRtnDampgEna_Logl();
}
boolean  TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnDampgScaEna_Logl(void)
{
  return (boolean ) Rte_Prm_CtrldVelRtnDampgScaEna_Logl();
}
boolean  TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnDrvrTqEna_Logl(void)
{
  return (boolean ) Rte_Prm_CtrldVelRtnDrvrTqEna_Logl();
}
boolean  TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnTqGrdtScaEna_Logl(void)
{
  return (boolean ) Rte_Prm_CtrldVelRtnTqGrdtScaEna_Logl();
}
boolean  TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnVelErrScaEna_Logl(void)
{
  return (boolean ) Rte_Prm_CtrldVelRtnVelErrScaEna_Logl();
}
Ary2D_u10p6_8_9 * TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnDampgX_Ary2D(void)
{
  return (Ary2D_u10p6_8_9 *) Rte_Prm_CtrldVelRtnDampgX_Ary2D();
}
Ary2D_u6p10_8_9 * TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnDampgY_Ary2D(void)
{
  return (Ary2D_u6p10_8_9 *) Rte_Prm_CtrldVelRtnDampgY_Ary2D();
}
Ary2D_u8p8_5_8 * TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnDesVelScaX_Ary2D(void)
{
  return (Ary2D_u8p8_5_8 *) Rte_Prm_CtrldVelRtnDesVelScaX_Ary2D();
}
Ary2D_u2p14_5_8 * TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnDesVelScaY_Ary2D(void)
{
  return (Ary2D_u2p14_5_8 *) Rte_Prm_CtrldVelRtnDesVelScaY_Ary2D();
}
Ary2D_u12p4_8_12 * TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnDesVelX_Ary2D(void)
{
  return (Ary2D_u12p4_8_12 *) Rte_Prm_CtrldVelRtnDesVelX_Ary2D();
}
Ary2D_u10p6_8_12 * TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnDesVelY_Ary2D(void)
{
  return (Ary2D_u10p6_8_12 *) Rte_Prm_CtrldVelRtnDesVelY_Ary2D();
}
Ary2D_f32_5_5 * TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnDrvrTqMtrxA_Ary2D(void)
{
  return (Ary2D_f32_5_5 *) Rte_Prm_CtrldVelRtnDrvrTqMtrxA_Ary2D();
}
Ary2D_f32_5_4 * TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnDrvrTqMtrxB_Ary2D(void)
{
  return (Ary2D_f32_5_4 *) Rte_Prm_CtrldVelRtnDrvrTqMtrxB_Ary2D();
}
Ary1D_f32_5 * TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnDrvrTqMtrxC_Ary1D(void)
{
  return (Ary1D_f32_5 *) Rte_Prm_CtrldVelRtnDrvrTqMtrxC_Ary1D();
}
Ary1D_f32_4 * TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnDrvrTqMtrxD_Ary1D(void)
{
  return (Ary1D_f32_4 *) Rte_Prm_CtrldVelRtnDrvrTqMtrxD_Ary1D();
}
Ary1D_u2p14_4 * TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnHwAuthyScaX_Ary1D(void)
{
  return (Ary1D_u2p14_4 *) Rte_Prm_CtrldVelRtnHwAuthyScaX_Ary1D();
}
Ary1D_u2p14_4 * TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnHwAuthyScaY_Ary1D(void)
{
  return (Ary1D_u2p14_4 *) Rte_Prm_CtrldVelRtnHwAuthyScaY_Ary1D();
}
Ary1D_u12p4_9 * TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnHwPosnScaX_Ary1D(void)
{
  return (Ary1D_u12p4_9 *) Rte_Prm_CtrldVelRtnHwPosnScaX_Ary1D();
}
Ary1D_u2p14_9 * TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnHwPosnScaY_Ary1D(void)
{
  return (Ary1D_u2p14_9 *) Rte_Prm_CtrldVelRtnHwPosnScaY_Ary1D();
}
Ary2D_u8p8_5_10 * TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnHwTqSca1X_Ary2D(void)
{
  return (Ary2D_u8p8_5_10 *) Rte_Prm_CtrldVelRtnHwTqSca1X_Ary2D();
}
Ary2D_u2p14_5_10 * TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnHwTqSca1Y_Ary2D(void)
{
  return (Ary2D_u2p14_5_10 *) Rte_Prm_CtrldVelRtnHwTqSca1Y_Ary2D();
}
Ary2D_u8p8_5_10 * TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnHwTqSca2X_Ary2D(void)
{
  return (Ary2D_u8p8_5_10 *) Rte_Prm_CtrldVelRtnHwTqSca2X_Ary2D();
}
Ary2D_u2p14_5_10 * TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnHwTqSca2Y_Ary2D(void)
{
  return (Ary2D_u2p14_5_10 *) Rte_Prm_CtrldVelRtnHwTqSca2Y_Ary2D();
}
Ary1D_u8p8_8 * TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnIntglGain_Ary1D(void)
{
  return (Ary1D_u8p8_8 *) Rte_Prm_CtrldVelRtnIntglGain_Ary1D();
}
Ary2D_u6p10_5_9 * TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnIntgrLimY_Ary2D(void)
{
  return (Ary2D_u6p10_5_9 *) Rte_Prm_CtrldVelRtnIntgrLimY_Ary2D();
}
Ary2D_u8p8_5_8 * TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnPinionTqScaX_Ary2D(void)
{
  return (Ary2D_u8p8_5_8 *) Rte_Prm_CtrldVelRtnPinionTqScaX_Ary2D();
}
Ary2D_u2p14_5_8 * TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnPinionTqScaY_Ary2D(void)
{
  return (Ary2D_u2p14_5_8 *) Rte_Prm_CtrldVelRtnPinionTqScaY_Ary2D();
}
Ary1D_u4p12_8 * TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnPropGain_Ary1D(void)
{
  return (Ary1D_u4p12_8 *) Rte_Prm_CtrldVelRtnPropGain_Ary1D();
}
Ary1D_u4p12_8 * TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnRtnCmdLimY_Ary1D(void)
{
  return (Ary1D_u4p12_8 *) Rte_Prm_CtrldVelRtnRtnCmdLimY_Ary1D();
}
Ary2D_u8p8_5_8 * TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnTqGrdtScaX_Ary2D(void)
{
  return (Ary2D_u8p8_5_8 *) Rte_Prm_CtrldVelRtnTqGrdtScaX_Ary2D();
}
Ary2D_u2p14_5_8 * TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnTqGrdtScaY_Ary2D(void)
{
  return (Ary2D_u2p14_5_8 *) Rte_Prm_CtrldVelRtnTqGrdtScaY_Ary2D();
}
Ary1D_u9p7_5 * TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnVehSpdScaBilnrSeln_Ary1D(void)
{
  return (Ary1D_u9p7_5 *) Rte_Prm_CtrldVelRtnVehSpdScaBilnrSeln_Ary1D();
}
Ary1D_u12p4_7 * TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnVelErrScaBilnrSeln_Ary1D(void)
{
  return (Ary1D_u12p4_7 *) Rte_Prm_CtrldVelRtnVelErrScaBilnrSeln_Ary1D();
}
Ary1D_s10p5_8 * TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnVelErrScaX_Ary1D(void)
{
  return (Ary1D_s10p5_8 *) Rte_Prm_CtrldVelRtnVelErrScaX_Ary1D();
}
Ary2D_u2p14_7_8 * TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnVelErrScaY_Ary2D(void)
{
  return (Ary2D_u2p14_7_8 *) Rte_Prm_CtrldVelRtnVelErrScaY_Ary2D();
}
Ary1D_u2p14_5 * TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnVelErrVehSpdScaY_Ary1D(void)
{
  return (Ary1D_u2p14_5 *) Rte_Prm_CtrldVelRtnVelErrVehSpdScaY_Ary1D();
}
Ary1D_u9p7_8 * TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnVelSpdTbl_Ary1D(void)
{
  return (Ary1D_u9p7_8 *) Rte_Prm_CtrldVelRtnVelSpdTbl_Ary1D();
}


     /* CtrldVelRtn */
      /* CtrldVelRtn */

/** Per Instance Memories */
float32 *TSC_CtrldVelRtn_Rte_Pim_PrevDesVel(void)
{
  return Rte_Pim_PrevDesVel();
}
float32 *TSC_CtrldVelRtn_Rte_Pim_PrevDrvrTqFildA(void)
{
  return Rte_Pim_PrevDrvrTqFildA();
}
float32 *TSC_CtrldVelRtn_Rte_Pim_PrevDrvrTqFildB(void)
{
  return Rte_Pim_PrevDrvrTqFildB();
}
float32 *TSC_CtrldVelRtn_Rte_Pim_PrevDrvrTqFildC(void)
{
  return Rte_Pim_PrevDrvrTqFildC();
}
float32 *TSC_CtrldVelRtn_Rte_Pim_PrevDrvrTqFildD(void)
{
  return Rte_Pim_PrevDrvrTqFildD();
}
float32 *TSC_CtrldVelRtn_Rte_Pim_PrevDrvrTqFildE(void)
{
  return Rte_Pim_PrevDrvrTqFildE();
}
float32 *TSC_CtrldVelRtn_Rte_Pim_PrevDrvrTqFildF(void)
{
  return Rte_Pim_PrevDrvrTqFildF();
}
float32 *TSC_CtrldVelRtn_Rte_Pim_PrevHwAuthySca(void)
{
  return Rte_Pim_PrevHwAuthySca();
}
float32 *TSC_CtrldVelRtn_Rte_Pim_PrevHwTqSeln(void)
{
  return Rte_Pim_PrevHwTqSeln();
}
float32 *TSC_CtrldVelRtn_Rte_Pim_PrevIntglTermA(void)
{
  return Rte_Pim_PrevIntglTermA();
}
float32 *TSC_CtrldVelRtn_Rte_Pim_PrevIntglTermB(void)
{
  return Rte_Pim_PrevIntglTermB();
}
float32 *TSC_CtrldVelRtn_Rte_Pim_PrevIntglTermC(void)
{
  return Rte_Pim_PrevIntglTermC();
}
float32 *TSC_CtrldVelRtn_Rte_Pim_PrevRtnOffs(void)
{
  return Rte_Pim_PrevRtnOffs();
}
float32 *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnCtrlSca(void)
{
  return Rte_Pim_dCtrldVelRtnCtrlSca();
}
float32 *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnCtrlScaPreFild(void)
{
  return Rte_Pim_dCtrldVelRtnCtrlScaPreFild();
}
float32 *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnDampgCmd(void)
{
  return Rte_Pim_dCtrldVelRtnDampgCmd();
}
float32 *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnDesVel(void)
{
  return Rte_Pim_dCtrldVelRtnDesVel();
}
float32 *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnDesVelSca(void)
{
  return Rte_Pim_dCtrldVelRtnDesVelSca();
}
float32 *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnDesVelScaPreFild(void)
{
  return Rte_Pim_dCtrldVelRtnDesVelScaPreFild();
}
float32 *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnDrvrTqEstimd(void)
{
  return Rte_Pim_dCtrldVelRtnDrvrTqEstimd();
}
float32 *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnDrvrTqFild(void)
{
  return Rte_Pim_dCtrldVelRtnDrvrTqFild();
}
float32 *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnHwAgCmp(void)
{
  return Rte_Pim_dCtrldVelRtnHwAgCmp();
}
float32 *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnHwAuthySca(void)
{
  return Rte_Pim_dCtrldVelRtnHwAuthySca();
}
float32 *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnHwPosnSca(void)
{
  return Rte_Pim_dCtrldVelRtnHwPosnSca();
}
float32 *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnHwTqSca(void)
{
  return Rte_Pim_dCtrldVelRtnHwTqSca();
}
float32 *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnHwTqScaSeln(void)
{
  return Rte_Pim_dCtrldVelRtnHwTqScaSeln();
}
float32 *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnIntglTermCmd(void)
{
  return Rte_Pim_dCtrldVelRtnIntglTermCmd();
}
float32 *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnIntgrLim(void)
{
  return Rte_Pim_dCtrldVelRtnIntgrLim();
}
float32 *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnPinionTqSca(void)
{
  return Rte_Pim_dCtrldVelRtnPinionTqSca();
}
float32 *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnPropTermCmd(void)
{
  return Rte_Pim_dCtrldVelRtnPropTermCmd();
}
float32 *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnRtnCmd(void)
{
  return Rte_Pim_dCtrldVelRtnRtnCmd();
}
float32 *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnRtnCmdPreLim(void)
{
  return Rte_Pim_dCtrldVelRtnRtnCmdPreLim();
}
float32 *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnTqGrdt(void)
{
  return Rte_Pim_dCtrldVelRtnTqGrdt();
}
float32 *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnTqGrdtSca(void)
{
  return Rte_Pim_dCtrldVelRtnTqGrdtSca();
}
float32 *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnVelErrSca(void)
{
  return Rte_Pim_dCtrldVelRtnVelErrSca();
}
float32 *TSC_CtrldVelRtn_Rte_Pim_PrevDrvrTqMtrx(void)
{
  return Rte_Pim_PrevDrvrTqMtrx();
}
FilLpRec1 *TSC_CtrldVelRtn_Rte_Pim_CtrlScaLpFil(void)
{
  return Rte_Pim_CtrlScaLpFil();
}
FilLpRec1 *TSC_CtrldVelRtn_Rte_Pim_DesVelLpFil(void)
{
  return Rte_Pim_DesVelLpFil();
}
FilLpRec1 *TSC_CtrldVelRtn_Rte_Pim_DesVelScaLpFil(void)
{
  return Rte_Pim_DesVelScaLpFil();
}
FilLpRec1 *TSC_CtrldVelRtn_Rte_Pim_DrvrTqLpFil(void)
{
  return Rte_Pim_DrvrTqLpFil();
}
FilLpRec1 *TSC_CtrldVelRtn_Rte_Pim_PinionTqLpFil(void)
{
  return Rte_Pim_PinionTqLpFil();
}



