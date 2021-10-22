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
 *          File:  TSC_InertiaCmpVel.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_InertiaCmpVel.h"
#include "TSC_InertiaCmpVel.h"















     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_InertiaCmpVel_Rte_Read_AssiCmdBas_Val(float32 *data)
{
  return Rte_Read_AssiCmdBas_Val(data);
}

Std_ReturnType TSC_InertiaCmpVel_Rte_Read_HwTq_Val(float32 *data)
{
  return Rte_Read_HwTq_Val(data);
}

Std_ReturnType TSC_InertiaCmpVel_Rte_Read_InertiaCmpDecelGainDi_Logl(boolean *data)
{
  return Rte_Read_InertiaCmpDecelGainDi_Logl(data);
}

Std_ReturnType TSC_InertiaCmpVel_Rte_Read_InertiaCmpVelCmdDi_Logl(boolean *data)
{
  return Rte_Read_InertiaCmpVelCmdDi_Logl(data);
}

Std_ReturnType TSC_InertiaCmpVel_Rte_Read_MotVelCrf_Val(float32 *data)
{
  return Rte_Read_MotVelCrf_Val(data);
}

Std_ReturnType TSC_InertiaCmpVel_Rte_Read_VehLgtA_Val(float32 *data)
{
  return Rte_Read_VehLgtA_Val(data);
}

Std_ReturnType TSC_InertiaCmpVel_Rte_Read_VehSpd_Val(float32 *data)
{
  return Rte_Read_VehSpd_Val(data);
}

Std_ReturnType TSC_InertiaCmpVel_Rte_Read_WhlImbRejctnAmp_Val(float32 *data)
{
  return Rte_Read_WhlImbRejctnAmp_Val(data);
}




Std_ReturnType TSC_InertiaCmpVel_Rte_Write_InertiaCmpVelCmd_Val(float32 data)
{
  return Rte_Write_InertiaCmpVelCmd_Val(data);
}





     /* Client Server Interfaces: */
Std_ReturnType TSC_InertiaCmpVel_Rte_Call_FltInj_f32_Oper(float32 *SigPah_Arg, uint16 LocnKey_Arg)
{
  return Rte_Call_FltInj_f32_Oper(SigPah_Arg, LocnKey_Arg);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */





float32  TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelDampgDecelGain_Val(void)
{
  return (float32 ) Rte_Prm_InertiaCmpVelDampgDecelGain_Val();
}
float32  TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelDampgDecelGainFallSlew_Val(void)
{
  return (float32 ) Rte_Prm_InertiaCmpVelDampgDecelGainFallSlew_Val();
}
float32  TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelDampgGainOffThd_Val(void)
{
  return (float32 ) Rte_Prm_InertiaCmpVelDampgGainOffThd_Val();
}
float32  TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelDampgGainOnThd_Val(void)
{
  return (float32 ) Rte_Prm_InertiaCmpVelDampgGainOnThd_Val();
}
float32  TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelMotInertia_Val(void)
{
  return (float32 ) Rte_Prm_InertiaCmpVelMotInertia_Val();
}
float32  TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelTqSnsrVelFilFrq_Val(void)
{
  return (float32 ) Rte_Prm_InertiaCmpVelTqSnsrVelFilFrq_Val();
}
float32  TSC_InertiaCmpVel_Rte_Prm_SysGlbPrmSysKineRat_Val(void)
{
  return (float32 ) Rte_Prm_SysGlbPrmSysKineRat_Val();
}
float32  TSC_InertiaCmpVel_Rte_Prm_SysGlbPrmTorsBarStfn_Val(void)
{
  return (float32 ) Rte_Prm_SysGlbPrmTorsBarStfn_Val();
}
boolean  TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelDecelGainEnaCal_Logl(void)
{
  return (boolean ) Rte_Prm_InertiaCmpVelDecelGainEnaCal_Logl();
}
Ary1D_u4p12_10 * TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelAssiBasdDampgCoeffX_Ary1D(void)
{
  return (Ary1D_u4p12_10 *) Rte_Prm_InertiaCmpVelAssiBasdDampgCoeffX_Ary1D();
}
Ary1D_u0p16_10 * TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelAssiBasdDampgRollgWhlImbRejctnOnY_Ary1D(void)
{
  return (Ary1D_u0p16_10 *) Rte_Prm_InertiaCmpVelAssiBasdDampgRollgWhlImbRejctnOnY_Ary1D();
}
Ary1D_u0p16_10 * TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelAssiBasdDampgRollgY_Ary1D(void)
{
  return (Ary1D_u0p16_10 *) Rte_Prm_InertiaCmpVelAssiBasdDampgRollgY_Ary1D();
}
Ary1D_u0p16_10 * TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelAssiBasdDampgStatWhlImbRejctnOnY_Ary1D(void)
{
  return (Ary1D_u0p16_10 *) Rte_Prm_InertiaCmpVelAssiBasdDampgStatWhlImbRejctnOnY_Ary1D();
}
Ary1D_u0p16_10 * TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelAssiBasdDampgStatY_Ary1D(void)
{
  return (Ary1D_u0p16_10 *) Rte_Prm_InertiaCmpVelAssiBasdDampgStatY_Ary1D();
}
Ary1D_u2p14_12 * TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelCmdScaY_Ary1D(void)
{
  return (Ary1D_u2p14_12 *) Rte_Prm_InertiaCmpVelCmdScaY_Ary1D();
}
Ary1D_u11p5_6 * TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelDampgDecelGainRisngSlewX_Ary1D(void)
{
  return (Ary1D_u11p5_6 *) Rte_Prm_InertiaCmpVelDampgDecelGainRisngSlewX_Ary1D();
}
Ary1D_u13p3_6 * TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelDampgDecelGainRisngSlewY_Ary1D(void)
{
  return (Ary1D_u13p3_6 *) Rte_Prm_InertiaCmpVelDampgDecelGainRisngSlewY_Ary1D();
}
Ary1D_u7p9_12 * TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelDampgFilFrq_Ary1D(void)
{
  return (Ary1D_u7p9_12 *) Rte_Prm_InertiaCmpVelDampgFilFrq_Ary1D();
}
Ary1D_u7p9_12 * TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelDampgFilFrqWhlImbRejctnOn_Ary1D(void)
{
  return (Ary1D_u7p9_12 *) Rte_Prm_InertiaCmpVelDampgFilFrqWhlImbRejctnOn_Ary1D();
}
Ary1D_u1p15_12 * TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelDampgSpdBlndY_Ary1D(void)
{
  return (Ary1D_u1p15_12 *) Rte_Prm_InertiaCmpVelDampgSpdBlndY_Ary1D();
}
Ary1D_u4p12_5 * TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelDampgWhlImbRejctnBlndX_Ary1D(void)
{
  return (Ary1D_u4p12_5 *) Rte_Prm_InertiaCmpVelDampgWhlImbRejctnBlndX_Ary1D();
}
Ary1D_u1p15_5 * TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelDampgWhlImbRejctnBlndY_Ary1D(void)
{
  return (Ary1D_u1p15_5 *) Rte_Prm_InertiaCmpVelDampgWhlImbRejctnBlndY_Ary1D();
}
Ary1D_u4p12_2 * TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelModWhlImbRejctnBlndX_Ary1D(void)
{
  return (Ary1D_u4p12_2 *) Rte_Prm_InertiaCmpVelModWhlImbRejctnBlndX_Ary1D();
}
Ary1D_u1p15_2 * TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelModWhlImbRejctnBlndY_Ary1D(void)
{
  return (Ary1D_u1p15_2 *) Rte_Prm_InertiaCmpVelModWhlImbRejctnBlndY_Ary1D();
}
Ary1D_u12p4_2 * TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelMotVelBasdOutpScagX_Ary1D(void)
{
  return (Ary1D_u12p4_2 *) Rte_Prm_InertiaCmpVelMotVelBasdOutpScagX_Ary1D();
}
Ary1D_u1p15_2 * TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelMotVelBasdOutpScagY_Ary1D(void)
{
  return (Ary1D_u1p15_2 *) Rte_Prm_InertiaCmpVelMotVelBasdOutpScagY_Ary1D();
}
Ary1D_u1p15_12 * TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelNotchBlndY_Ary1D(void)
{
  return (Ary1D_u1p15_12 *) Rte_Prm_InertiaCmpVelNotchBlndY_Ary1D();
}
Ary1D_u2p14_12 * TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelTqSnsrVelSca_Ary1D(void)
{
  return (Ary1D_u2p14_12 *) Rte_Prm_InertiaCmpVelTqSnsrVelSca_Ary1D();
}
Ary1D_u9p7_12 * TSC_InertiaCmpVel_Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D(void)
{
  return (Ary1D_u9p7_12 *) Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D();
}
FilNotchGainRec1 * TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelNotchFilStruct_Rec(void)
{
  return (FilNotchGainRec1 *) Rte_Prm_InertiaCmpVelNotchFilStruct_Rec();
}


     /* InertiaCmpVel */
      /* InertiaCmpVel */

/** Per Instance Memories */
float32 *TSC_InertiaCmpVel_Rte_Pim_DecelGain(void)
{
  return Rte_Pim_DecelGain();
}
float32 *TSC_InertiaCmpVel_Rte_Pim_PreScagCmpCmdPrev1(void)
{
  return Rte_Pim_PreScagCmpCmdPrev1();
}
float32 *TSC_InertiaCmpVel_Rte_Pim_PreScagCmpCmdPrev2(void)
{
  return Rte_Pim_PreScagCmpCmdPrev2();
}
float32 *TSC_InertiaCmpVel_Rte_Pim_ScaDrvrVelPrev1(void)
{
  return Rte_Pim_ScaDrvrVelPrev1();
}
float32 *TSC_InertiaCmpVel_Rte_Pim_ScaDrvrVelPrev2(void)
{
  return Rte_Pim_ScaDrvrVelPrev2();
}
float32 *TSC_InertiaCmpVel_Rte_Pim_TqSnsrAgPrev(void)
{
  return Rte_Pim_TqSnsrAgPrev();
}
float32 *TSC_InertiaCmpVel_Rte_Pim_dInertiaCmpVelAssiBasdDampgCoeff(void)
{
  return Rte_Pim_dInertiaCmpVelAssiBasdDampgCoeff();
}
float32 *TSC_InertiaCmpVel_Rte_Pim_dInertiaCmpVelCalcdInertiaCmp(void)
{
  return Rte_Pim_dInertiaCmpVelCalcdInertiaCmp();
}
float32 *TSC_InertiaCmpVel_Rte_Pim_dInertiaCmpVelFilFrq(void)
{
  return Rte_Pim_dInertiaCmpVelFilFrq();
}
float32 *TSC_InertiaCmpVel_Rte_Pim_dInertiaCmpVelMotVelBasdOutpScag(void)
{
  return Rte_Pim_dInertiaCmpVelMotVelBasdOutpScag();
}
float32 *TSC_InertiaCmpVel_Rte_Pim_dInertiaCmpVelNotScadDrvrVel(void)
{
  return Rte_Pim_dInertiaCmpVelNotScadDrvrVel();
}
float32 *TSC_InertiaCmpVel_Rte_Pim_dInertiaCmpVelNotchBlndVal(void)
{
  return Rte_Pim_dInertiaCmpVelNotchBlndVal();
}
float32 *TSC_InertiaCmpVel_Rte_Pim_dInertiaCmpVelNotchInpVal(void)
{
  return Rte_Pim_dInertiaCmpVelNotchInpVal();
}
float32 *TSC_InertiaCmpVel_Rte_Pim_dInertiaCmpVelNotchOutpVal(void)
{
  return Rte_Pim_dInertiaCmpVelNotchOutpVal();
}
float32 *TSC_InertiaCmpVel_Rte_Pim_dInertiaCmpVelRawDecelGain(void)
{
  return Rte_Pim_dInertiaCmpVelRawDecelGain();
}
float32 *TSC_InertiaCmpVel_Rte_Pim_dInertiaCmpVelScadDrvrVel(void)
{
  return Rte_Pim_dInertiaCmpVelScadDrvrVel();
}
float32 *TSC_InertiaCmpVel_Rte_Pim_dInertiaCmpVelTqSnsrVelFildVal(void)
{
  return Rte_Pim_dInertiaCmpVelTqSnsrVelFildVal();
}
boolean *TSC_InertiaCmpVel_Rte_Pim_NotchFilChk(void)
{
  return Rte_Pim_NotchFilChk();
}
FilLpRec1 *TSC_InertiaCmpVel_Rte_Pim_TqSnsrVelFil(void)
{
  return Rte_Pim_TqSnsrVelFil();
}
FilNotchStRec1 *TSC_InertiaCmpVel_Rte_Pim_TqSnsrVelFilNotchSt(void)
{
  return Rte_Pim_TqSnsrVelFilNotchSt();
}



