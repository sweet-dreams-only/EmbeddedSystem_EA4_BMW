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
 *          File:  TSC_MotVelCtrl.h
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
Std_ReturnType TSC_MotVelCtrl_Rte_Read_MotVelCrf_Val(float32 *data);

/** Client server interfaces */
Std_ReturnType TSC_MotVelCtrl_Rte_Call_GetRefTmr100MicroSec32bit_Oper(uint32 *RefTmr_Arg);
Std_ReturnType TSC_MotVelCtrl_Rte_Call_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg);
Std_ReturnType TSC_MotVelCtrl_Rte_Call_SetManTqCmd_Oper(float32 ManTqCmd, boolean ManTqCmdEna);

/** Explicit inter-runnable variables */
float32 TSC_MotVelCtrl_Rte_IrvRead_GetCtrlPrm_Oper_AntiWdupGain(void);
float32 TSC_MotVelCtrl_Rte_IrvRead_GetCtrlPrm_Oper_AntiWdupLim(void);
float32 TSC_MotVelCtrl_Rte_IrvRead_GetCtrlPrm_Oper_DerivtvGain(void);
float32 TSC_MotVelCtrl_Rte_IrvRead_GetCtrlPrm_Oper_DerivtvLpFilTiCon(void);
float32 TSC_MotVelCtrl_Rte_IrvRead_GetCtrlPrm_Oper_IntgtrGain(void);
float32 TSC_MotVelCtrl_Rte_IrvRead_GetCtrlPrm_Oper_PropGain(void);
float32 TSC_MotVelCtrl_Rte_IrvRead_GetCtrlPrm_Oper_TqCmdLim(void);
float32 TSC_MotVelCtrl_Rte_IrvRead_MotVelCtrlPer1_AntiWdupGain(void);
float32 TSC_MotVelCtrl_Rte_IrvRead_MotVelCtrlPer1_AntiWdupLim(void);
float32 TSC_MotVelCtrl_Rte_IrvRead_MotVelCtrlPer1_DerivtvGain(void);
float32 TSC_MotVelCtrl_Rte_IrvRead_MotVelCtrlPer1_DerivtvLpFilTiCon(void);
float32 TSC_MotVelCtrl_Rte_IrvRead_MotVelCtrlPer1_IntgtrGain(void);
float32 TSC_MotVelCtrl_Rte_IrvRead_MotVelCtrlPer1_PropGain(void);
float32 TSC_MotVelCtrl_Rte_IrvRead_MotVelCtrlPer1_TqCmdLim(void);
void TSC_MotVelCtrl_Rte_IrvWrite_SetCtrlPrm_Oper_AntiWdupGain(float32);
void TSC_MotVelCtrl_Rte_IrvWrite_SetCtrlPrm_Oper_AntiWdupLim(float32);
void TSC_MotVelCtrl_Rte_IrvWrite_SetCtrlPrm_Oper_DerivtvGain(float32);
void TSC_MotVelCtrl_Rte_IrvWrite_SetCtrlPrm_Oper_DerivtvLpFilTiCon(float32);
void TSC_MotVelCtrl_Rte_IrvWrite_SetCtrlPrm_Oper_IntgtrGain(float32);
void TSC_MotVelCtrl_Rte_IrvWrite_SetCtrlPrm_Oper_PropGain(float32);
void TSC_MotVelCtrl_Rte_IrvWrite_SetCtrlPrm_Oper_TqCmdLim(float32);

/** Per Instance Memories */
float32 *TSC_MotVelCtrl_Rte_Pim_MotVelTar(void);
float32 *TSC_MotVelCtrl_Rte_Pim_PrevAntiWdupCmd(void);
float32 *TSC_MotVelCtrl_Rte_Pim_PrevDerivtvOutp(void);
float32 *TSC_MotVelCtrl_Rte_Pim_PrevIntgtrInp(void);
float32 *TSC_MotVelCtrl_Rte_Pim_PrevIntgtrOutp(void);
float32 *TSC_MotVelCtrl_Rte_Pim_PrevMotVelErr(void);
float32 *TSC_MotVelCtrl_Rte_Pim_PrevMotVelTar(void);
float32 *TSC_MotVelCtrl_Rte_Pim_VelSlewRate(void);
uint32 *TSC_MotVelCtrl_Rte_Pim_RefTiRampDwn(void);
boolean *TSC_MotVelCtrl_Rte_Pim_EnaCtrl(void);
boolean *TSC_MotVelCtrl_Rte_Pim_EnaCtrlStVari(void);
boolean *TSC_MotVelCtrl_Rte_Pim_FctActvSts(void);
boolean *TSC_MotVelCtrl_Rte_Pim_RampDwnCmpl(void);



