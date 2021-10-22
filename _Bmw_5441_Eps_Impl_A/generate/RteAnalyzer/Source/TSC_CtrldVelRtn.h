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
 *          File:  TSC_CtrldVelRtn.h
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
Std_ReturnType TSC_CtrldVelRtn_Rte_Read_AssiMechPolarity_Val(sint8 *data);
Std_ReturnType TSC_CtrldVelRtn_Rte_Read_HwAg_Val(float32 *data);
Std_ReturnType TSC_CtrldVelRtn_Rte_Read_HwAgAuthy_Val(float32 *data);
Std_ReturnType TSC_CtrldVelRtn_Rte_Read_HwAgRtnOffs_Val(float32 *data);
Std_ReturnType TSC_CtrldVelRtn_Rte_Read_HwTq_Val(float32 *data);
Std_ReturnType TSC_CtrldVelRtn_Rte_Read_HwVel_Val(float32 *data);
Std_ReturnType TSC_CtrldVelRtn_Rte_Read_MotTqCmdPwrLimd_Val(float32 *data);
Std_ReturnType TSC_CtrldVelRtn_Rte_Read_RtnCmdDi_Logl(boolean *data);
Std_ReturnType TSC_CtrldVelRtn_Rte_Read_RtnCmdDiagcDi_Logl(boolean *data);
Std_ReturnType TSC_CtrldVelRtn_Rte_Read_RtnCmdSca_Val(float32 *data);
Std_ReturnType TSC_CtrldVelRtn_Rte_Read_RtnCmdScaServo_Val(float32 *data);
Std_ReturnType TSC_CtrldVelRtn_Rte_Read_VehSpd_Val(float32 *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_CtrldVelRtn_Rte_Write_CtrldVelRtnCmd_Val(float32 data);

/** Calibration Component Calibration Parameters */
float32  TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnAntiWdup_Val(void);
float32  TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnDesVelLpFilFrq_Val(void);
float32  TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnHwAuthySlewThd_Val(void);
float32  TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnHwTqLpFilFrq_Val(void);
float32  TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnHwTqScaSelnSlewHiLim_Val(void);
float32  TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnHwTqScaSelnSlewLoLim_Val(void);
float32  TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnHwTqScaSelnTqThd_Val(void);
float32  TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnHwTqScaSelnVelThd_Val(void);
float32  TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnOffsSlewThd_Val(void);
float32  TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnOffsThd_Val(void);
float32  TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnScaLpFilFrq_Val(void);
float32  TSC_CtrldVelRtn_Rte_Prm_SysGlbPrmSysTqRat_Val(void);
boolean  TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnDampgEna_Logl(void);
boolean  TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnDampgScaEna_Logl(void);
boolean  TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnDrvrTqEna_Logl(void);
boolean  TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnTqGrdtScaEna_Logl(void);
boolean  TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnVelErrScaEna_Logl(void);
Ary2D_u10p6_8_9 * TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnDampgX_Ary2D(void);
Ary2D_u6p10_8_9 * TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnDampgY_Ary2D(void);
Ary2D_u8p8_5_8 * TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnDesVelScaX_Ary2D(void);
Ary2D_u2p14_5_8 * TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnDesVelScaY_Ary2D(void);
Ary2D_u12p4_8_12 * TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnDesVelX_Ary2D(void);
Ary2D_u10p6_8_12 * TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnDesVelY_Ary2D(void);
Ary2D_f32_5_5 * TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnDrvrTqMtrxA_Ary2D(void);
Ary2D_f32_5_4 * TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnDrvrTqMtrxB_Ary2D(void);
Ary1D_f32_5 * TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnDrvrTqMtrxC_Ary1D(void);
Ary1D_f32_4 * TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnDrvrTqMtrxD_Ary1D(void);
Ary1D_u2p14_4 * TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnHwAuthyScaX_Ary1D(void);
Ary1D_u2p14_4 * TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnHwAuthyScaY_Ary1D(void);
Ary1D_u12p4_9 * TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnHwPosnScaX_Ary1D(void);
Ary1D_u2p14_9 * TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnHwPosnScaY_Ary1D(void);
Ary2D_u8p8_5_10 * TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnHwTqSca1X_Ary2D(void);
Ary2D_u2p14_5_10 * TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnHwTqSca1Y_Ary2D(void);
Ary2D_u8p8_5_10 * TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnHwTqSca2X_Ary2D(void);
Ary2D_u2p14_5_10 * TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnHwTqSca2Y_Ary2D(void);
Ary1D_u8p8_8 * TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnIntglGain_Ary1D(void);
Ary2D_u6p10_5_9 * TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnIntgrLimY_Ary2D(void);
Ary2D_u8p8_5_8 * TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnPinionTqScaX_Ary2D(void);
Ary2D_u2p14_5_8 * TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnPinionTqScaY_Ary2D(void);
Ary1D_u4p12_8 * TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnPropGain_Ary1D(void);
Ary1D_u4p12_8 * TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnRtnCmdLimY_Ary1D(void);
Ary2D_u8p8_5_8 * TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnTqGrdtScaX_Ary2D(void);
Ary2D_u2p14_5_8 * TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnTqGrdtScaY_Ary2D(void);
Ary1D_u9p7_5 * TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnVehSpdScaBilnrSeln_Ary1D(void);
Ary1D_u12p4_7 * TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnVelErrScaBilnrSeln_Ary1D(void);
Ary1D_s10p5_8 * TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnVelErrScaX_Ary1D(void);
Ary2D_u2p14_7_8 * TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnVelErrScaY_Ary2D(void);
Ary1D_u2p14_5 * TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnVelErrVehSpdScaY_Ary1D(void);
Ary1D_u9p7_8 * TSC_CtrldVelRtn_Rte_Prm_CtrldVelRtnVelSpdTbl_Ary1D(void);

/** Per Instance Memories */
float32 *TSC_CtrldVelRtn_Rte_Pim_PrevDesVel(void);
float32 *TSC_CtrldVelRtn_Rte_Pim_PrevDrvrTqFildA(void);
float32 *TSC_CtrldVelRtn_Rte_Pim_PrevDrvrTqFildB(void);
float32 *TSC_CtrldVelRtn_Rte_Pim_PrevDrvrTqFildC(void);
float32 *TSC_CtrldVelRtn_Rte_Pim_PrevDrvrTqFildD(void);
float32 *TSC_CtrldVelRtn_Rte_Pim_PrevDrvrTqFildE(void);
float32 *TSC_CtrldVelRtn_Rte_Pim_PrevDrvrTqFildF(void);
float32 *TSC_CtrldVelRtn_Rte_Pim_PrevHwAuthySca(void);
float32 *TSC_CtrldVelRtn_Rte_Pim_PrevHwTqSeln(void);
float32 *TSC_CtrldVelRtn_Rte_Pim_PrevIntglTermA(void);
float32 *TSC_CtrldVelRtn_Rte_Pim_PrevIntglTermB(void);
float32 *TSC_CtrldVelRtn_Rte_Pim_PrevIntglTermC(void);
float32 *TSC_CtrldVelRtn_Rte_Pim_PrevRtnOffs(void);
float32 *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnCtrlSca(void);
float32 *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnCtrlScaPreFild(void);
float32 *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnDampgCmd(void);
float32 *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnDesVel(void);
float32 *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnDesVelSca(void);
float32 *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnDesVelScaPreFild(void);
float32 *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnDrvrTqEstimd(void);
float32 *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnDrvrTqFild(void);
float32 *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnHwAgCmp(void);
float32 *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnHwAuthySca(void);
float32 *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnHwPosnSca(void);
float32 *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnHwTqSca(void);
float32 *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnHwTqScaSeln(void);
float32 *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnIntglTermCmd(void);
float32 *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnIntgrLim(void);
float32 *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnPinionTqSca(void);
float32 *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnPropTermCmd(void);
float32 *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnRtnCmd(void);
float32 *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnRtnCmdPreLim(void);
float32 *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnTqGrdt(void);
float32 *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnTqGrdtSca(void);
float32 *TSC_CtrldVelRtn_Rte_Pim_dCtrldVelRtnVelErrSca(void);
float32 *TSC_CtrldVelRtn_Rte_Pim_PrevDrvrTqMtrx(void);
FilLpRec1 *TSC_CtrldVelRtn_Rte_Pim_CtrlScaLpFil(void);
FilLpRec1 *TSC_CtrldVelRtn_Rte_Pim_DesVelLpFil(void);
FilLpRec1 *TSC_CtrldVelRtn_Rte_Pim_DesVelScaLpFil(void);
FilLpRec1 *TSC_CtrldVelRtn_Rte_Pim_DrvrTqLpFil(void);
FilLpRec1 *TSC_CtrldVelRtn_Rte_Pim_PinionTqLpFil(void);



