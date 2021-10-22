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
 *          File:  TSC_InertiaCmpVel.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Header of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/


/** Sender receiver - explicit read services */
Std_ReturnType TSC_InertiaCmpVel_Rte_Read_AssiCmdBas_Val(float32 *data);
Std_ReturnType TSC_InertiaCmpVel_Rte_Read_HwTq_Val(float32 *data);
Std_ReturnType TSC_InertiaCmpVel_Rte_Read_InertiaCmpDecelGainDi_Logl(boolean *data);
Std_ReturnType TSC_InertiaCmpVel_Rte_Read_InertiaCmpVelCmdDi_Logl(boolean *data);
Std_ReturnType TSC_InertiaCmpVel_Rte_Read_MotVelCrf_Val(float32 *data);
Std_ReturnType TSC_InertiaCmpVel_Rte_Read_VehLgtA_Val(float32 *data);
Std_ReturnType TSC_InertiaCmpVel_Rte_Read_VehSpd_Val(float32 *data);
Std_ReturnType TSC_InertiaCmpVel_Rte_Read_WhlImbRejctnAmp_Val(float32 *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_InertiaCmpVel_Rte_Write_InertiaCmpVelCmd_Val(float32 data);

/** Client server interfaces */
Std_ReturnType TSC_InertiaCmpVel_Rte_Call_FltInj_f32_Oper(float32 *SigPah_Arg, uint16 LocnKey_Arg);

/** Calibration Component Calibration Parameters */
float32  TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelDampgDecelGain_Val(void);
float32  TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelDampgDecelGainFallSlew_Val(void);
float32  TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelDampgGainOffThd_Val(void);
float32  TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelDampgGainOnThd_Val(void);
float32  TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelMotInertia_Val(void);
float32  TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelTqSnsrVelFilFrq_Val(void);
float32  TSC_InertiaCmpVel_Rte_Prm_SysGlbPrmSysKineRat_Val(void);
float32  TSC_InertiaCmpVel_Rte_Prm_SysGlbPrmTorsBarStfn_Val(void);
boolean  TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelDecelGainEnaCal_Logl(void);
Ary1D_u4p12_10 * TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelAssiBasdDampgCoeffX_Ary1D(void);
Ary1D_u0p16_10 * TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelAssiBasdDampgRollgWhlImbRejctnOnY_Ary1D(void);
Ary1D_u0p16_10 * TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelAssiBasdDampgRollgY_Ary1D(void);
Ary1D_u0p16_10 * TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelAssiBasdDampgStatWhlImbRejctnOnY_Ary1D(void);
Ary1D_u0p16_10 * TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelAssiBasdDampgStatY_Ary1D(void);
Ary1D_u2p14_12 * TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelCmdScaY_Ary1D(void);
Ary1D_u11p5_6 * TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelDampgDecelGainRisngSlewX_Ary1D(void);
Ary1D_u13p3_6 * TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelDampgDecelGainRisngSlewY_Ary1D(void);
Ary1D_u7p9_12 * TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelDampgFilFrq_Ary1D(void);
Ary1D_u7p9_12 * TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelDampgFilFrqWhlImbRejctnOn_Ary1D(void);
Ary1D_u1p15_12 * TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelDampgSpdBlndY_Ary1D(void);
Ary1D_u4p12_5 * TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelDampgWhlImbRejctnBlndX_Ary1D(void);
Ary1D_u1p15_5 * TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelDampgWhlImbRejctnBlndY_Ary1D(void);
Ary1D_u4p12_2 * TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelModWhlImbRejctnBlndX_Ary1D(void);
Ary1D_u1p15_2 * TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelModWhlImbRejctnBlndY_Ary1D(void);
Ary1D_u12p4_2 * TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelMotVelBasdOutpScagX_Ary1D(void);
Ary1D_u1p15_2 * TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelMotVelBasdOutpScagY_Ary1D(void);
Ary1D_u1p15_12 * TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelNotchBlndY_Ary1D(void);
Ary1D_u2p14_12 * TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelTqSnsrVelSca_Ary1D(void);
Ary1D_u9p7_12 * TSC_InertiaCmpVel_Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D(void);
FilNotchGainRec1 * TSC_InertiaCmpVel_Rte_Prm_InertiaCmpVelNotchFilStruct_Rec(void);

/** Per Instance Memories */
float32 *TSC_InertiaCmpVel_Rte_Pim_DecelGain(void);
float32 *TSC_InertiaCmpVel_Rte_Pim_PreScagCmpCmdPrev1(void);
float32 *TSC_InertiaCmpVel_Rte_Pim_PreScagCmpCmdPrev2(void);
float32 *TSC_InertiaCmpVel_Rte_Pim_ScaDrvrVelPrev1(void);
float32 *TSC_InertiaCmpVel_Rte_Pim_ScaDrvrVelPrev2(void);
float32 *TSC_InertiaCmpVel_Rte_Pim_TqSnsrAgPrev(void);
float32 *TSC_InertiaCmpVel_Rte_Pim_dInertiaCmpVelAssiBasdDampgCoeff(void);
float32 *TSC_InertiaCmpVel_Rte_Pim_dInertiaCmpVelCalcdInertiaCmp(void);
float32 *TSC_InertiaCmpVel_Rte_Pim_dInertiaCmpVelFilFrq(void);
float32 *TSC_InertiaCmpVel_Rte_Pim_dInertiaCmpVelMotVelBasdOutpScag(void);
float32 *TSC_InertiaCmpVel_Rte_Pim_dInertiaCmpVelNotScadDrvrVel(void);
float32 *TSC_InertiaCmpVel_Rte_Pim_dInertiaCmpVelNotchBlndVal(void);
float32 *TSC_InertiaCmpVel_Rte_Pim_dInertiaCmpVelNotchInpVal(void);
float32 *TSC_InertiaCmpVel_Rte_Pim_dInertiaCmpVelNotchOutpVal(void);
float32 *TSC_InertiaCmpVel_Rte_Pim_dInertiaCmpVelRawDecelGain(void);
float32 *TSC_InertiaCmpVel_Rte_Pim_dInertiaCmpVelScadDrvrVel(void);
float32 *TSC_InertiaCmpVel_Rte_Pim_dInertiaCmpVelTqSnsrVelFildVal(void);
boolean *TSC_InertiaCmpVel_Rte_Pim_NotchFilChk(void);
FilLpRec1 *TSC_InertiaCmpVel_Rte_Pim_TqSnsrVelFil(void);
FilNotchStRec1 *TSC_InertiaCmpVel_Rte_Pim_TqSnsrVelFilNotchSt(void);



