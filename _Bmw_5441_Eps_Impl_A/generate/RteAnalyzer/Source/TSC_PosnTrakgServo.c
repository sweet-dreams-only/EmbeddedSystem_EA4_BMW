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
 *          File:  TSC_PosnTrakgServo.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_PosnTrakgServo.h"
#include "TSC_PosnTrakgServo.h"















     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_PosnTrakgServo_Rte_Read_HwAg_Val(float32 *data)
{
  return Rte_Read_HwAg_Val(data);
}

Std_ReturnType TSC_PosnTrakgServo_Rte_Read_HwTq_Val(float32 *data)
{
  return Rte_Read_HwTq_Val(data);
}

Std_ReturnType TSC_PosnTrakgServo_Rte_Read_MotVelCrf_Val(float32 *data)
{
  return Rte_Read_MotVelCrf_Val(data);
}

Std_ReturnType TSC_PosnTrakgServo_Rte_Read_PosnServoEna_Logl(boolean *data)
{
  return Rte_Read_PosnServoEna_Logl(data);
}

Std_ReturnType TSC_PosnTrakgServo_Rte_Read_PosnServoHwAg_Val(float32 *data)
{
  return Rte_Read_PosnServoHwAg_Val(data);
}

Std_ReturnType TSC_PosnTrakgServo_Rte_Read_PosnServoHwVel_Val(float32 *data)
{
  return Rte_Read_PosnServoHwVel_Val(data);
}

Std_ReturnType TSC_PosnTrakgServo_Rte_Read_PosnServoIntgtrOffs_Val(float32 *data)
{
  return Rte_Read_PosnServoIntgtrOffs_Val(data);
}

Std_ReturnType TSC_PosnTrakgServo_Rte_Read_PosnTrakgArbnFltMtgtnEna_Logl(boolean *data)
{
  return Rte_Read_PosnTrakgArbnFltMtgtnEna_Logl(data);
}

Std_ReturnType TSC_PosnTrakgServo_Rte_Read_VehSpd_Val(float32 *data)
{
  return Rte_Read_VehSpd_Val(data);
}




Std_ReturnType TSC_PosnTrakgServo_Rte_Write_PosnServoCmd_Val(float32 data)
{
  return Rte_Write_PosnServoCmd_Val(data);
}

Std_ReturnType TSC_PosnTrakgServo_Rte_Write_PosnServoIntgtrSt_Val(float32 data)
{
  return Rte_Write_PosnServoIntgtrSt_Val(data);
}





     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */





float32  TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoArbnFltMtgtnLpFilCutOffFrq_Val(void)
{
  return (float32 ) Rte_Prm_PosnTrakgServoArbnFltMtgtnLpFilCutOffFrq_Val();
}
float32  TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoIntgtrAntiWdupGain_Val(void)
{
  return (float32 ) Rte_Prm_PosnTrakgServoIntgtrAntiWdupGain_Val();
}
float32  TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoIntgtrStCorrnGain_Val(void)
{
  return (float32 ) Rte_Prm_PosnTrakgServoIntgtrStCorrnGain_Val();
}
float32  TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoLpFilCutOffFrq_Val(void)
{
  return (float32 ) Rte_Prm_PosnTrakgServoLpFilCutOffFrq_Val();
}
float32  TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoOutpAntiWdupGain_Val(void)
{
  return (float32 ) Rte_Prm_PosnTrakgServoOutpAntiWdupGain_Val();
}
float32  TSC_PosnTrakgServo_Rte_Prm_SysGlbPrmSysKineRat_Val(void)
{
  return (float32 ) Rte_Prm_SysGlbPrmSysKineRat_Val();
}
float32  TSC_PosnTrakgServo_Rte_Prm_SysGlbPrmSysTqRat_Val(void)
{
  return (float32 ) Rte_Prm_SysGlbPrmSysTqRat_Val();
}
Ary1D_u8p8_10 * TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoEnaBlndFacTblX_Ary1D(void)
{
  return (Ary1D_u8p8_10 *) Rte_Prm_PosnTrakgServoEnaBlndFacTblX_Ary1D();
}
Ary1D_u2p14_10 * TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoEnaBlndFacTblY_Ary1D(void)
{
  return (Ary1D_u2p14_10 *) Rte_Prm_PosnTrakgServoEnaBlndFacTblY_Ary1D();
}
Ary1D_u12p4_12 * TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoFfGain_Ary1D(void)
{
  return (Ary1D_u12p4_12 *) Rte_Prm_PosnTrakgServoFfGain_Ary1D();
}
Ary1D_u8p8_12 * TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoFfVelGain_Ary1D(void)
{
  return (Ary1D_u8p8_12 *) Rte_Prm_PosnTrakgServoFfVelGain_Ary1D();
}
Ary1D_u12p4_12 * TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoGain1_Ary1D(void)
{
  return (Ary1D_u12p4_12 *) Rte_Prm_PosnTrakgServoGain1_Ary1D();
}
Ary1D_u8p8_12 * TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoGain2_Ary1D(void)
{
  return (Ary1D_u8p8_12 *) Rte_Prm_PosnTrakgServoGain2_Ary1D();
}
Ary1D_s8p7_12 * TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoGain3_Ary1D(void)
{
  return (Ary1D_s8p7_12 *) Rte_Prm_PosnTrakgServoGain3_Ary1D();
}
Ary1D_s4p11_12 * TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoGain4_Ary1D(void)
{
  return (Ary1D_s4p11_12 *) Rte_Prm_PosnTrakgServoGain4_Ary1D();
}
Ary1D_u2p14_12 * TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoGainArbnFltMtgtn_Ary1D(void)
{
  return (Ary1D_u2p14_12 *) Rte_Prm_PosnTrakgServoGainArbnFltMtgtn_Ary1D();
}
Ary1D_u11p5_12 * TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoHwAgTarMgnLimTblY_Ary1D(void)
{
  return (Ary1D_u11p5_12 *) Rte_Prm_PosnTrakgServoHwAgTarMgnLimTblY_Ary1D();
}
Ary1D_u15p1_12 * TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoHwAgTarRateLimTblY_Ary1D(void)
{
  return (Ary1D_u15p1_12 *) Rte_Prm_PosnTrakgServoHwAgTarRateLimTblY_Ary1D();
}
Ary1D_u15p1_12 * TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoHwVelTarRateLimTblY_Ary1D(void)
{
  return (Ary1D_u15p1_12 *) Rte_Prm_PosnTrakgServoHwVelTarRateLimTblY_Ary1D();
}
Ary1D_u15p1_12 * TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoIntglGain_Ary1D(void)
{
  return (Ary1D_u15p1_12 *) Rte_Prm_PosnTrakgServoIntglGain_Ary1D();
}
Ary1D_u15p1_12 * TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoIntglLim_Ary1D(void)
{
  return (Ary1D_u15p1_12 *) Rte_Prm_PosnTrakgServoIntglLim_Ary1D();
}
Ary1D_u8p8_12 * TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoOutpLim_Ary1D(void)
{
  return (Ary1D_u8p8_12 *) Rte_Prm_PosnTrakgServoOutpLim_Ary1D();
}
Ary1D_u9p7_12 * TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoVehSpdTbl_Ary1D(void)
{
  return (Ary1D_u9p7_12 *) Rte_Prm_PosnTrakgServoVehSpdTbl_Ary1D();
}


     /* PosnTrakgServo */
      /* PosnTrakgServo */

/** Per Instance Memories */
float32 *TSC_PosnTrakgServo_Rte_Pim_AntiWdupCmdPrev(void)
{
  return Rte_Pim_AntiWdupCmdPrev();
}
float32 *TSC_PosnTrakgServo_Rte_Pim_HwTqDerivtvPrev(void)
{
  return Rte_Pim_HwTqDerivtvPrev();
}
float32 *TSC_PosnTrakgServo_Rte_Pim_HwTqPrev(void)
{
  return Rte_Pim_HwTqPrev();
}
float32 *TSC_PosnTrakgServo_Rte_Pim_IntgtrInpPrev(void)
{
  return Rte_Pim_IntgtrInpPrev();
}
float32 *TSC_PosnTrakgServo_Rte_Pim_IntgtrOutpPrev(void)
{
  return Rte_Pim_IntgtrOutpPrev();
}
float32 *TSC_PosnTrakgServo_Rte_Pim_OutpAntiWdupCmdPrev(void)
{
  return Rte_Pim_OutpAntiWdupCmdPrev();
}
float32 *TSC_PosnTrakgServo_Rte_Pim_PosnServoCmdInpArbnFltMtgtnPrev(void)
{
  return Rte_Pim_PosnServoCmdInpArbnFltMtgtnPrev();
}
float32 *TSC_PosnTrakgServo_Rte_Pim_PosnServoCmdOutpArbnFltMtgtnPrev(void)
{
  return Rte_Pim_PosnServoCmdOutpArbnFltMtgtnPrev();
}
float32 *TSC_PosnTrakgServo_Rte_Pim_PosnServoEnaTiPrev(void)
{
  return Rte_Pim_PosnServoEnaTiPrev();
}
float32 *TSC_PosnTrakgServo_Rte_Pim_PosnServoHwAgValRateLim(void)
{
  return Rte_Pim_PosnServoHwAgValRateLim();
}
float32 *TSC_PosnTrakgServo_Rte_Pim_PosnServoHwVelValRateLim(void)
{
  return Rte_Pim_PosnServoHwVelValRateLim();
}
float32 *TSC_PosnTrakgServo_Rte_Pim_dPosnTrakgServoCmdPreLimd(void)
{
  return Rte_Pim_dPosnTrakgServoCmdPreLimd();
}
float32 *TSC_PosnTrakgServo_Rte_Pim_dPosnTrakgServoEnaBlndFac(void)
{
  return Rte_Pim_dPosnTrakgServoEnaBlndFac();
}
float32 *TSC_PosnTrakgServo_Rte_Pim_dPosnTrakgServoFfCmd(void)
{
  return Rte_Pim_dPosnTrakgServoFfCmd();
}
float32 *TSC_PosnTrakgServo_Rte_Pim_dPosnTrakgServoHwAg(void)
{
  return Rte_Pim_dPosnTrakgServoHwAg();
}
float32 *TSC_PosnTrakgServo_Rte_Pim_dPosnTrakgServoHwAgErr(void)
{
  return Rte_Pim_dPosnTrakgServoHwAgErr();
}
float32 *TSC_PosnTrakgServo_Rte_Pim_dPosnTrakgServoHwAgTarLimd(void)
{
  return Rte_Pim_dPosnTrakgServoHwAgTarLimd();
}
float32 *TSC_PosnTrakgServo_Rte_Pim_dPosnTrakgServoHwVelTarLimd(void)
{
  return Rte_Pim_dPosnTrakgServoHwVelTarLimd();
}
float32 *TSC_PosnTrakgServo_Rte_Pim_dPosnTrakgServoIntgtrCmdLimd(void)
{
  return Rte_Pim_dPosnTrakgServoIntgtrCmdLimd();
}
float32 *TSC_PosnTrakgServo_Rte_Pim_dPosnTrakgServoPtlStFbCmd(void)
{
  return Rte_Pim_dPosnTrakgServoPtlStFbCmd();
}



