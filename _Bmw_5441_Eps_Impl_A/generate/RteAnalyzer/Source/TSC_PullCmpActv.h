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
 *          File:  TSC_PullCmpActv.h
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
Std_ReturnType TSC_PullCmpActv_Rte_Read_HwAg_Val(float32 *data);
Std_ReturnType TSC_PullCmpActv_Rte_Read_HwTq_Val(float32 *data);
Std_ReturnType TSC_PullCmpActv_Rte_Read_HwVel_Val(float32 *data);
Std_ReturnType TSC_PullCmpActv_Rte_Read_PinionAgConf_Val(float32 *data);
Std_ReturnType TSC_PullCmpActv_Rte_Read_PullCmpActvDi_Logl(boolean *data);
Std_ReturnType TSC_PullCmpActv_Rte_Read_PullCmpCmdDi_Logl(boolean *data);
Std_ReturnType TSC_PullCmpActv_Rte_Read_PullCmpCustLrngDi_Logl(boolean *data);
Std_ReturnType TSC_PullCmpActv_Rte_Read_PullCmpLrngDi_Logl(boolean *data);
Std_ReturnType TSC_PullCmpActv_Rte_Read_VehLatA_Val(float32 *data);
Std_ReturnType TSC_PullCmpActv_Rte_Read_VehSpd_Val(float32 *data);
Std_ReturnType TSC_PullCmpActv_Rte_Read_VehSpdVld_Logl(boolean *data);
Std_ReturnType TSC_PullCmpActv_Rte_Read_VehYawRate_Val(float32 *data);
Std_ReturnType TSC_PullCmpActv_Rte_Read_VehYawRateVld_Logl(boolean *data);
Std_ReturnType TSC_PullCmpActv_Rte_Read_HwTq_Val(float32 *data);
Std_ReturnType TSC_PullCmpActv_Rte_Read_VehSpd_Val(float32 *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_PullCmpActv_Rte_Write_PullCmpCmd_Val(float32 data);

/** Client server interfaces */
Std_ReturnType TSC_PullCmpActv_Rte_Call_FltInj_f32_Oper(float32 *SigPah_Arg, uint16 LocnKey_Arg);
Std_ReturnType TSC_PullCmpActv_Rte_Call_GetRefTmr100MicroSec32bit_Oper(uint32 *RefTmr_Arg);
Std_ReturnType TSC_PullCmpActv_Rte_Call_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg);

/** Service interfaces */
Std_ReturnType TSC_PullCmpActv_Rte_Call_PullCmpLongTerm_GetErrorStatus(NvM_RequestResultType *ErrorStatus_Arg);
Std_ReturnType TSC_PullCmpActv_Rte_Call_PullCmpLongTerm_SetRamBlockStatus(boolean RamBlockStatus_Arg);
Std_ReturnType TSC_PullCmpActv_Rte_Call_PullCmpLongTerm_SetRamBlockStatus(boolean RamBlockStatus_Arg);

/** Explicit inter-runnable variables */
void TSC_PullCmpActv_Rte_IrvWrite_PullCmpActvInit1_RampDwnStepSize(float32);
float32 TSC_PullCmpActv_Rte_IrvRead_PullCmpActvPer1_RampDwnStepSize(void);

/** Calibration Component Calibration Parameters */
float32  TSC_PullCmpActv_Rte_Prm_PullCmpActvCmpLrnTiDecShoTerm_Val(void);
float32  TSC_PullCmpActv_Rte_Prm_PullCmpActvCmpLrnTiIncShoTerm_Val(void);
float32  TSC_PullCmpActv_Rte_Prm_PullCmpActvCmpLrnTiLongTerm_Val(void);
float32  TSC_PullCmpActv_Rte_Prm_PullCmpActvCmpShoTermRstHwAgThd_Val(void);
float32  TSC_PullCmpActv_Rte_Prm_PullCmpActvCmpShoTermRstHwTqThd_Val(void);
float32  TSC_PullCmpActv_Rte_Prm_PullCmpActvCmpShoTermRstLatAThd_Val(void);
float32  TSC_PullCmpActv_Rte_Prm_PullCmpActvCmpShoTermRstYawRateThd_Val(void);
float32  TSC_PullCmpActv_Rte_Prm_PullCmpActvHwTqFilFrqLongTerm_Val(void);
float32  TSC_PullCmpActv_Rte_Prm_PullCmpActvHwTqFilFrqLrngEna_Val(void);
float32  TSC_PullCmpActv_Rte_Prm_PullCmpActvHwTqFilFrqShoTerm_Val(void);
float32  TSC_PullCmpActv_Rte_Prm_PullCmpActvLongTermLim_Val(void);
float32  TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaAgConfMinMgn_Val(void);
float32  TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaHwAgMaxMgn_Val(void);
float32  TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaHwTqMaxMgn_Val(void);
float32  TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaHwVelMaxMgn_Val(void);
float32  TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaLatAMaxMgn_Val(void);
float32  TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaTiThd_Val(void);
float32  TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaVehSpdMaxMgn_Val(void);
float32  TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaVehSpdMinMgn_Val(void);
float32  TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaVehSpdRateMaxMgn_Val(void);
float32  TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaYawRateMaxMgn_Val(void);
float32  TSC_PullCmpActv_Rte_Prm_PullCmpActvOpstSignTiShoTerm_Val(void);
float32  TSC_PullCmpActv_Rte_Prm_PullCmpActvOutpMaxRate_Val(void);
float32  TSC_PullCmpActv_Rte_Prm_PullCmpActvPullCmpShoTermLim_Val(void);
float32  TSC_PullCmpActv_Rte_Prm_PullCmpActvPullCmpTotLim_Val(void);
float32  TSC_PullCmpActv_Rte_Prm_PullCmpActvPullErrLimLongTerm_Val(void);
float32  TSC_PullCmpActv_Rte_Prm_PullCmpActvPullErrMgnThd_Val(void);
float32  TSC_PullCmpActv_Rte_Prm_PullCmpActvPullErrShoTermLim_Val(void);
float32  TSC_PullCmpActv_Rte_Prm_PullCmpActvShoTermRampTi_Val(void);
float32  TSC_PullCmpActv_Rte_Prm_PullCmpActvYawRateFilFrq_Val(void);
float32  TSC_PullCmpActv_Rte_Prm_SysGlbPrmSysTqRat_Val(void);
boolean  TSC_PullCmpActv_Rte_Prm_PullCmpActvEna_Logl(void);
Ary1D_u9p7_4 * TSC_PullCmpActv_Rte_Prm_PullCmpActvVehSpdScaTblX_Ary1D(void);
Ary1D_u2p14_4 * TSC_PullCmpActv_Rte_Prm_PullCmpActvVehSpdScaTblY_Ary1D(void);

/** SW-C local Calibration Parameters */
float32  TSC_PullCmpActv_Rte_CData_PullCmpLongTermDft(void);

/** Per Instance Memories */
float32 *TSC_PullCmpActv_Rte_Pim_CmpLrnTiDecShoTerm(void);
float32 *TSC_PullCmpActv_Rte_Pim_CmpLrnTiIncShoTerm(void);
float32 *TSC_PullCmpActv_Rte_Pim_CmpLrnTiLongTerm(void);
float32 *TSC_PullCmpActv_Rte_Pim_IntgtrGainDecShoTerm(void);
float32 *TSC_PullCmpActv_Rte_Pim_IntgtrGainIncShoTerm(void);
float32 *TSC_PullCmpActv_Rte_Pim_PrevLrnTiLongTerm(void);
float32 *TSC_PullCmpActv_Rte_Pim_PullCmpCmdRateLimPrev(void);
float32 *TSC_PullCmpActv_Rte_Pim_PullCmpCmdTot(void);
float32 *TSC_PullCmpActv_Rte_Pim_PullCmpLongTerm(void);
float32 *TSC_PullCmpActv_Rte_Pim_PullCmpShoTerm(void);
float32 *TSC_PullCmpActv_Rte_Pim_VehSpdPrev(void);
float32 *TSC_PullCmpActv_Rte_Pim_VehSpdRate(void);
float32 *TSC_PullCmpActv_Rte_Pim_dPullCmpActvIntgtrGainShoTerm(void);
float32 *TSC_PullCmpActv_Rte_Pim_dPullCmpActvPullErrLongTerm(void);
float32 *TSC_PullCmpActv_Rte_Pim_dPullCmpActvPullErrShoTerm(void);
uint32 *TSC_PullCmpActv_Rte_Pim_RefTiEnaLrng(void);
uint32 *TSC_PullCmpActv_Rte_Pim_RefTiOpstSign(void);
boolean *TSC_PullCmpActv_Rte_Pim_LrngEnaPrev(void);
boolean *TSC_PullCmpActv_Rte_Pim_LrngEnad(void);
boolean *TSC_PullCmpActv_Rte_Pim_OpstSignPrev(void);
boolean *TSC_PullCmpActv_Rte_Pim_PullCmpActvDi(void);
boolean *TSC_PullCmpActv_Rte_Pim_PullCmpLongTermRst(void);
boolean *TSC_PullCmpActv_Rte_Pim_PullCmpShoTermRst(void);
boolean *TSC_PullCmpActv_Rte_Pim_dPullCmpActvShoTermRst(void);
FilLpRec1 *TSC_PullCmpActv_Rte_Pim_HwTqLpFilLongTerm(void);
FilLpRec1 *TSC_PullCmpActv_Rte_Pim_HwTqLpFilLrngEna(void);
FilLpRec1 *TSC_PullCmpActv_Rte_Pim_HwTqLpFilShoTerm(void);
FilLpRec1 *TSC_PullCmpActv_Rte_Pim_VehYawRateLpFil(void);



