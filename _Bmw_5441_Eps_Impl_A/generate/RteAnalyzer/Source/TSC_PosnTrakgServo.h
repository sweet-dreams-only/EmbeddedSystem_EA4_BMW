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
 *          File:  TSC_PosnTrakgServo.h
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
Std_ReturnType TSC_PosnTrakgServo_Rte_Read_HwAg_Val(float32 *data);
Std_ReturnType TSC_PosnTrakgServo_Rte_Read_HwTq_Val(float32 *data);
Std_ReturnType TSC_PosnTrakgServo_Rte_Read_MotVelCrf_Val(float32 *data);
Std_ReturnType TSC_PosnTrakgServo_Rte_Read_PosnServoEna_Logl(boolean *data);
Std_ReturnType TSC_PosnTrakgServo_Rte_Read_PosnServoHwAg_Val(float32 *data);
Std_ReturnType TSC_PosnTrakgServo_Rte_Read_PosnServoHwVel_Val(float32 *data);
Std_ReturnType TSC_PosnTrakgServo_Rte_Read_PosnServoIntgtrOffs_Val(float32 *data);
Std_ReturnType TSC_PosnTrakgServo_Rte_Read_PosnTrakgArbnFltMtgtnEna_Logl(boolean *data);
Std_ReturnType TSC_PosnTrakgServo_Rte_Read_VehSpd_Val(float32 *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_PosnTrakgServo_Rte_Write_PosnServoCmd_Val(float32 data);
Std_ReturnType TSC_PosnTrakgServo_Rte_Write_PosnServoIntgtrSt_Val(float32 data);

/** Calibration Component Calibration Parameters */
float32  TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoArbnFltMtgtnLpFilCutOffFrq_Val(void);
float32  TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoIntgtrAntiWdupGain_Val(void);
float32  TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoIntgtrStCorrnGain_Val(void);
float32  TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoLpFilCutOffFrq_Val(void);
float32  TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoOutpAntiWdupGain_Val(void);
float32  TSC_PosnTrakgServo_Rte_Prm_SysGlbPrmSysKineRat_Val(void);
float32  TSC_PosnTrakgServo_Rte_Prm_SysGlbPrmSysTqRat_Val(void);
Ary1D_u8p8_10 * TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoEnaBlndFacTblX_Ary1D(void);
Ary1D_u2p14_10 * TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoEnaBlndFacTblY_Ary1D(void);
Ary1D_u12p4_12 * TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoFfGain_Ary1D(void);
Ary1D_u8p8_12 * TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoFfVelGain_Ary1D(void);
Ary1D_u12p4_12 * TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoGain1_Ary1D(void);
Ary1D_u8p8_12 * TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoGain2_Ary1D(void);
Ary1D_s8p7_12 * TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoGain3_Ary1D(void);
Ary1D_s4p11_12 * TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoGain4_Ary1D(void);
Ary1D_u2p14_12 * TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoGainArbnFltMtgtn_Ary1D(void);
Ary1D_u11p5_12 * TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoHwAgTarMgnLimTblY_Ary1D(void);
Ary1D_u15p1_12 * TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoHwAgTarRateLimTblY_Ary1D(void);
Ary1D_u15p1_12 * TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoHwVelTarRateLimTblY_Ary1D(void);
Ary1D_u15p1_12 * TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoIntglGain_Ary1D(void);
Ary1D_u15p1_12 * TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoIntglLim_Ary1D(void);
Ary1D_u8p8_12 * TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoOutpLim_Ary1D(void);
Ary1D_u9p7_12 * TSC_PosnTrakgServo_Rte_Prm_PosnTrakgServoVehSpdTbl_Ary1D(void);

/** Per Instance Memories */
float32 *TSC_PosnTrakgServo_Rte_Pim_AntiWdupCmdPrev(void);
float32 *TSC_PosnTrakgServo_Rte_Pim_HwTqDerivtvPrev(void);
float32 *TSC_PosnTrakgServo_Rte_Pim_HwTqPrev(void);
float32 *TSC_PosnTrakgServo_Rte_Pim_IntgtrInpPrev(void);
float32 *TSC_PosnTrakgServo_Rte_Pim_IntgtrOutpPrev(void);
float32 *TSC_PosnTrakgServo_Rte_Pim_OutpAntiWdupCmdPrev(void);
float32 *TSC_PosnTrakgServo_Rte_Pim_PosnServoCmdInpArbnFltMtgtnPrev(void);
float32 *TSC_PosnTrakgServo_Rte_Pim_PosnServoCmdOutpArbnFltMtgtnPrev(void);
float32 *TSC_PosnTrakgServo_Rte_Pim_PosnServoEnaTiPrev(void);
float32 *TSC_PosnTrakgServo_Rte_Pim_PosnServoHwAgValRateLim(void);
float32 *TSC_PosnTrakgServo_Rte_Pim_PosnServoHwVelValRateLim(void);
float32 *TSC_PosnTrakgServo_Rte_Pim_dPosnTrakgServoCmdPreLimd(void);
float32 *TSC_PosnTrakgServo_Rte_Pim_dPosnTrakgServoEnaBlndFac(void);
float32 *TSC_PosnTrakgServo_Rte_Pim_dPosnTrakgServoFfCmd(void);
float32 *TSC_PosnTrakgServo_Rte_Pim_dPosnTrakgServoHwAg(void);
float32 *TSC_PosnTrakgServo_Rte_Pim_dPosnTrakgServoHwAgErr(void);
float32 *TSC_PosnTrakgServo_Rte_Pim_dPosnTrakgServoHwAgTarLimd(void);
float32 *TSC_PosnTrakgServo_Rte_Pim_dPosnTrakgServoHwVelTarLimd(void);
float32 *TSC_PosnTrakgServo_Rte_Pim_dPosnTrakgServoIntgtrCmdLimd(void);
float32 *TSC_PosnTrakgServo_Rte_Pim_dPosnTrakgServoPtlStFbCmd(void);



