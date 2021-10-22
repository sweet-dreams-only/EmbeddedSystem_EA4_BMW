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
 *          File:  TSC_EotProtn.h
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
Std_ReturnType TSC_EotProtn_Rte_Read_EotProtnDi_Logl(boolean *data);
Std_ReturnType TSC_EotProtn_Rte_Read_HwAg_Val(float32 *data);
Std_ReturnType TSC_EotProtn_Rte_Read_HwAgAuthy_Val(float32 *data);
Std_ReturnType TSC_EotProtn_Rte_Read_HwAgCcwDetd_Logl(boolean *data);
Std_ReturnType TSC_EotProtn_Rte_Read_HwAgCwDetd_Logl(boolean *data);
Std_ReturnType TSC_EotProtn_Rte_Read_HwAgEotCcw_Val(float32 *data);
Std_ReturnType TSC_EotProtn_Rte_Read_HwAgEotCw_Val(float32 *data);
Std_ReturnType TSC_EotProtn_Rte_Read_HwTq_Val(float32 *data);
Std_ReturnType TSC_EotProtn_Rte_Read_MotVelCrf_Val(float32 *data);
Std_ReturnType TSC_EotProtn_Rte_Read_SysMotTqCmdSca_Val(float32 *data);
Std_ReturnType TSC_EotProtn_Rte_Read_VehSpd_Val(float32 *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_EotProtn_Rte_Write_EotActvCmd_Val(float32 data);
Std_ReturnType TSC_EotProtn_Rte_Write_EotAssiSca_Val(float32 data);
Std_ReturnType TSC_EotProtn_Rte_Write_EotDampgCmd_Val(float32 data);
Std_ReturnType TSC_EotProtn_Rte_Write_EotMotTqLim_Val(float32 data);

/** Calibration Component Calibration Parameters */
float32  TSC_EotProtn_Rte_Prm_EotProtnActvRegnBypMaxThd_Val(void);
float32  TSC_EotProtn_Rte_Prm_EotProtnDampgSlew_Val(void);
float32  TSC_EotProtn_Rte_Prm_EotProtnDeltaTqThd_Val(void);
float32  TSC_EotProtn_Rte_Prm_EotProtnDftPosn_Val(void);
float32  TSC_EotProtn_Rte_Prm_EotProtnEntrGainAuthyThd_Val(void);
float32  TSC_EotProtn_Rte_Prm_EotProtnEntrStLpFilFrq_Val(void);
float32  TSC_EotProtn_Rte_Prm_EotProtnExitStLpFilFrq_Val(void);
float32  TSC_EotProtn_Rte_Prm_EotProtnHwAgGain_Val(void);
float32  TSC_EotProtn_Rte_Prm_EotProtnHwAgMax_Val(void);
float32  TSC_EotProtn_Rte_Prm_EotProtnHwAgMin_Val(void);
float32  TSC_EotProtn_Rte_Prm_EotProtnHwTqLpFilFrq_Val(void);
float32  TSC_EotProtn_Rte_Prm_EotProtnMotSpdIncptSca_Val(void);
float32  TSC_EotProtn_Rte_Prm_EotProtnMotVelGain_Val(void);
float32  TSC_EotProtn_Rte_Prm_EotProtnPosnRampStep_Val(void);
float32  TSC_EotProtn_Rte_Prm_EotProtnRackTrvlLimrAuthyThd_Val(void);
float32  TSC_EotProtn_Rte_Prm_EotProtnRackTrvlLimrAuthyThdLimd_Val(void);
float32  TSC_EotProtn_Rte_Prm_EotProtnRackTrvlLimrRng_Val(void);
float32  TSC_EotProtn_Rte_Prm_EotProtnRackTrvlLimrRngLimd_Val(void);
float32  TSC_EotProtn_Rte_Prm_EotProtnRackTrvlLimrVehSpdThd_Val(void);
float32  TSC_EotProtn_Rte_Prm_EotProtnSoftEndStopAuthyThd_Val(void);
float32  TSC_EotProtn_Rte_Prm_EotProtnSoftEndStopVehSpdThd_Val(void);
boolean  TSC_EotProtn_Rte_Prm_EotProtnRackTrvlLimrEna_Logl(void);
boolean  TSC_EotProtn_Rte_Prm_EotProtnRunEotVelImpctAndSoftEndStop_Logl(void);
boolean  TSC_EotProtn_Rte_Prm_EotProtnSoftEndStopEna_Logl(void);
Ary1D_u9p7_4 * TSC_EotProtn_Rte_Prm_EotProtnDampgVehSpdTbl_Ary1D(void);
Ary1D_u9p7_5 * TSC_EotProtn_Rte_Prm_EotProtnEntrGainVehSpdTbl_Ary1D(void);
Ary2D_u12p4_5_4 * TSC_EotProtn_Rte_Prm_EotProtnEntrGainX_Ary2D(void);
Ary2D_u1p15_5_4 * TSC_EotProtn_Rte_Prm_EotProtnEntrGainY_Ary2D(void);
Ary2D_u0p16_4_2 * TSC_EotProtn_Rte_Prm_EotProtnExitDampgY_Ary2D(void);
Ary2D_u12p4_4_2 * TSC_EotProtn_Rte_Prm_EotProtnHwDegDampgX_Ary2D(void);
Ary1D_u4p12_2 * TSC_EotProtn_Rte_Prm_EotProtnHwTqScaX_Ary1D(void);
Ary2D_u1p15_5_4 * TSC_EotProtn_Rte_Prm_EotProtnLoAuthyEntrGainY_Ary2D(void);
Ary1D_u12p4_2 * TSC_EotProtn_Rte_Prm_EotProtnMotSpdIncptX_Ary1D(void);
Ary1D_u12p4_2 * TSC_EotProtn_Rte_Prm_EotProtnMotSpdIncptY_Ary1D(void);
Ary2D_u0p16_4_2 * TSC_EotProtn_Rte_Prm_EotProtnNormDampgY_Ary2D(void);

/** Per Instance Memories */
float32 *TSC_EotProtn_Rte_Pim_PrevEotAssiSca(void);
float32 *TSC_EotProtn_Rte_Pim_PrevEotDampg(void);
float32 *TSC_EotProtn_Rte_Pim_PrevImpctPosn(void);
float32 *TSC_EotProtn_Rte_Pim_dEotProtnDampg(void);
float32 *TSC_EotProtn_Rte_Pim_dEotProtnEntrGain(void);
float32 *TSC_EotProtn_Rte_Pim_dEotProtnEotAssiSca(void);
float32 *TSC_EotProtn_Rte_Pim_dEotProtnEotGain(void);
float32 *TSC_EotProtn_Rte_Pim_dEotProtnExitGain(void);
float32 *TSC_EotProtn_Rte_Pim_dEotProtnLimPosn(void);
uint8 *TSC_EotProtn_Rte_Pim_NewSoftEndStopSt(void);
uint8 *TSC_EotProtn_Rte_Pim_PrevSoftEndStopSt(void);
boolean *TSC_EotProtn_Rte_Pim_PrevRackTrvlLimrEna(void);
boolean *TSC_EotProtn_Rte_Pim_PrevRackTrvlLimrInin(void);
boolean *TSC_EotProtn_Rte_Pim_dEotProtnDetd(void);
boolean *TSC_EotProtn_Rte_Pim_dEotProtnRackTrvlLimrDi(void);
FilLpRec1 *TSC_EotProtn_Rte_Pim_EotAssiScaLpFil(void);
FilLpRec1 *TSC_EotProtn_Rte_Pim_HwTqLpFil(void);



