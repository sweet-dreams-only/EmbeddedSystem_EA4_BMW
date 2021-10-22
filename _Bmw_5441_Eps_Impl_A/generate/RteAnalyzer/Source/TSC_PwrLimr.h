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
 *          File:  TSC_PwrLimr.h
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
Std_ReturnType TSC_PwrLimr_Rte_Read_AltFltActv_Logl(boolean *data);
Std_ReturnType TSC_PwrLimr_Rte_Read_BrdgVltg_Val(float32 *data);
Std_ReturnType TSC_PwrLimr_Rte_Read_DualEcuFltMtgtnSca_Val(float32 *data);
Std_ReturnType TSC_PwrLimr_Rte_Read_MotAndThermProtnLoaMod_Val(uint8 *data);
Std_ReturnType TSC_PwrLimr_Rte_Read_MotBackEmfConEstimd_Val(float32 *data);
Std_ReturnType TSC_PwrLimr_Rte_Read_MotTqCmdMrf_Val(float32 *data);
Std_ReturnType TSC_PwrLimr_Rte_Read_MotVelMrf_Val(float32 *data);
Std_ReturnType TSC_PwrLimr_Rte_Read_SplyCurrLim_Val(float32 *data);
Std_ReturnType TSC_PwrLimr_Rte_Read_BrdgVltg_Val(float32 *data);
Std_ReturnType TSC_PwrLimr_Rte_Read_MotTqCmdMrf_Val(float32 *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_PwrLimr_Rte_Write_MotTqCmdPwrLimd_Val(float32 data);
Std_ReturnType TSC_PwrLimr_Rte_Write_PwrLimrRednFac_Val(float32 data);

/** Client server interfaces */
Std_ReturnType TSC_PwrLimr_Rte_Call_GetRefTmr100MicroSec32bit_Oper(uint32 *RefTmr_Arg);
Std_ReturnType TSC_PwrLimr_Rte_Call_GetRefTmr100MicroSec32bit_Oper(uint32 *RefTmr_Arg);
Std_ReturnType TSC_PwrLimr_Rte_Call_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg);
Std_ReturnType TSC_PwrLimr_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg);

/** Explicit inter-runnable variables */
void TSC_PwrLimr_Rte_IrvWrite_PwrLimrPer1_MinStdOperLim(float32);
void TSC_PwrLimr_Rte_IrvWrite_PwrLimrPer1_MotEnvlpSpd(float32);
void TSC_PwrLimr_Rte_IrvWrite_PwrLimrPer1_TqEnvlpLim1(float32);
float32 TSC_PwrLimr_Rte_IrvRead_PwrLimrPer2_MinStdOperLim(void);
float32 TSC_PwrLimr_Rte_IrvRead_PwrLimrPer2_MotEnvlpSpd(void);
float32 TSC_PwrLimr_Rte_IrvRead_PwrLimrPer2_TqEnvlpLim1(void);

/** Calibration Component Calibration Parameters */
float32  TSC_PwrLimr_Rte_Prm_PwrLimrAssiRednLpFilFrq_Val(void);
float32  TSC_PwrLimr_Rte_Prm_PwrLimrBackEmfConStdT_Val(void);
float32  TSC_PwrLimr_Rte_Prm_PwrLimrBrdgVltgAdjSlew_Val(void);
float32  TSC_PwrLimr_Rte_Prm_PwrLimrBrdgVltgAltFltAdj_Val(void);
float32  TSC_PwrLimr_Rte_Prm_PwrLimrFilAssiRednThd_Val(void);
float32  TSC_PwrLimr_Rte_Prm_PwrLimrLoVoltAssiRcvrThd_Val(void);
float32  TSC_PwrLimr_Rte_Prm_PwrLimrMotVelLpFilFrq_Val(void);
float32  TSC_PwrLimr_Rte_Prm_PwrLimrSpdAdjSlewDec_Val(void);
float32  TSC_PwrLimr_Rte_Prm_PwrLimrSpdAdjSlewInc_Val(void);
uint16  TSC_PwrLimr_Rte_Prm_PwrLimrLoVoltAssiRcvrTi_Val(void);
boolean  TSC_PwrLimr_Rte_Prm_PwrLimrSpdAdjSlewEna_Logl(void);
Ary1D_s11p4_14 * TSC_PwrLimr_Rte_Prm_PwrLimrMotEnvlpX_Ary1D(void);
Ary1D_u5p11_14 * TSC_PwrLimr_Rte_Prm_PwrLimrMotEnvlpY_Ary1D(void);
Ary1D_u12p4_10 * TSC_PwrLimr_Rte_Prm_PwrLimrSplyCurrLimTblX_Ary1D(void);
Ary1D_u11p5_10 * TSC_PwrLimr_Rte_Prm_PwrLimrSplyCurrLimTblY_Ary1D(void);
Ary1D_u11p5_6 * TSC_PwrLimr_Rte_Prm_PwrLimrStdOperMotEnvlpX_Ary1D(void);
Ary1D_u4p12_6 * TSC_PwrLimr_Rte_Prm_PwrLimrStdOperMotEnvlpY_Ary1D(void);
Ary1D_u5p11_10 * TSC_PwrLimr_Rte_Prm_PwrLimrVltgDptMotVelOffsX_Ary1D(void);
Ary1D_u11p5_10 * TSC_PwrLimr_Rte_Prm_PwrLimrVltgDptMotVelOffsY_Ary1D(void);

/** Per Instance Memories */
float32 *TSC_PwrLimr_Rte_Pim_BrdgVltgRateLim(void);
float32 *TSC_PwrLimr_Rte_Pim_OutpVelOffsRateLimd(void);
float32 *TSC_PwrLimr_Rte_Pim_dPwrLimrFildMotVel(void);
float32 *TSC_PwrLimr_Rte_Pim_dPwrLimrLimDif(void);
float32 *TSC_PwrLimr_Rte_Pim_dPwrLimrMinStdOperLim(void);
float32 *TSC_PwrLimr_Rte_Pim_dPwrLimrMotEnvlpSpd(void);
float32 *TSC_PwrLimr_Rte_Pim_dPwrLimrMotTqCmdIvtrLoaSca(void);
float32 *TSC_PwrLimr_Rte_Pim_dPwrLimrOutpVelOffs(void);
float32 *TSC_PwrLimr_Rte_Pim_dPwrLimrSpdAdj(void);
float32 *TSC_PwrLimr_Rte_Pim_dPwrLimrSplyCurrLimOffs(void);
float32 *TSC_PwrLimr_Rte_Pim_dPwrLimrTLimMaxCurr(void);
float32 *TSC_PwrLimr_Rte_Pim_dPwrLimrTqEnvlpLim1(void);
float32 *TSC_PwrLimr_Rte_Pim_dPwrLimrTqEnvlpLim4(void);
float32 *TSC_PwrLimr_Rte_Pim_dPwrLimrTqLim(void);
float32 *TSC_PwrLimr_Rte_Pim_dPwrLimrTqLim1(void);
float32 *TSC_PwrLimr_Rte_Pim_dPwrLimrTqLim4(void);
uint32 *TSC_PwrLimr_Rte_Pim_RefTmr(void);
uint32 *TSC_PwrLimr_Rte_Pim_RefTmrPrev(void);
boolean *TSC_PwrLimr_Rte_Pim_LimdAssiLoVltgPrev(void);
FilLpRec1 *TSC_PwrLimr_Rte_Pim_MotVelLpFil(void);
FilLpRec1 *TSC_PwrLimr_Rte_Pim_TqLimLpFil(void);



