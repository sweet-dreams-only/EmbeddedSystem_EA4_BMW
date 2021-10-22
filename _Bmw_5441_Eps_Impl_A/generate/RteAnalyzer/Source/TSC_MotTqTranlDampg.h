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
 *          File:  TSC_MotTqTranlDampg.h
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
Std_ReturnType TSC_MotTqTranlDampg_Rte_Read_AssiMechPolarity_Val(sint8 *data);
Std_ReturnType TSC_MotTqTranlDampg_Rte_Read_DiagcStsCtrldShtDwnFltPrsnt_Logl(boolean *data);
Std_ReturnType TSC_MotTqTranlDampg_Rte_Read_HwAg_Val(float32 *data);
Std_ReturnType TSC_MotTqTranlDampg_Rte_Read_LoaSt_Val(LoaSt1 *data);
Std_ReturnType TSC_MotTqTranlDampg_Rte_Read_MotTqCmdCrf_Val(float32 *data);
Std_ReturnType TSC_MotTqTranlDampg_Rte_Read_MotVelCrf_Val(float32 *data);
Std_ReturnType TSC_MotTqTranlDampg_Rte_Read_SysSt_Val(SysSt1 *data);
Std_ReturnType TSC_MotTqTranlDampg_Rte_Read_VehSpd_Val(float32 *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_MotTqTranlDampg_Rte_Write_MotTqCmdCrfDampd_Val(float32 data);
Std_ReturnType TSC_MotTqTranlDampg_Rte_Write_MotTqCmdMrfDampd_Val(float32 data);
Std_ReturnType TSC_MotTqTranlDampg_Rte_Write_MotTqTranlDampgCmpl_Logl(boolean data);

/** Client server interfaces */
Std_ReturnType TSC_MotTqTranlDampg_Rte_Call_GetRefTmr100MicroSec32bit_Oper(uint32 *RefTmr_Arg);
Std_ReturnType TSC_MotTqTranlDampg_Rte_Call_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg);

/** Explicit inter-runnable variables */
void TSC_MotTqTranlDampg_Rte_IrvWrite_MotTqTranlDampgInit1_CtrldDampgScaX(u16p0 *data);
void TSC_MotTqTranlDampg_Rte_IrvWrite_MotTqTranlDampgInit1_CtrldDampgScaY(u2p14 *data);
void TSC_MotTqTranlDampg_Rte_IrvRead_MotTqTranlDampgPer1_CtrldDampgScaX(u16p0 *data);
void TSC_MotTqTranlDampg_Rte_IrvRead_MotTqTranlDampgPer1_CtrldDampgScaY(u2p14 *data);

/** Calibration Component Calibration Parameters */
float32  TSC_MotTqTranlDampg_Rte_Prm_MotTqTranlDampgCmdLim_Val(void);
float32  TSC_MotTqTranlDampg_Rte_Prm_MotTqTranlDampgDampgCoeff_Val(void);
float32  TSC_MotTqTranlDampg_Rte_Prm_MotTqTranlDampgTmrPt1_Val(void);
float32  TSC_MotTqTranlDampg_Rte_Prm_MotTqTranlDampgTmrPt2_Val(void);
float32  TSC_MotTqTranlDampg_Rte_Prm_MotTqTranlDampgVelThd_Val(void);
u2p14  TSC_MotTqTranlDampg_Rte_Prm_MotTqTranlDampgRampEnd_Val(void);
Ary1D_u9p7_4 * TSC_MotTqTranlDampg_Rte_Prm_MotTqTranlDampgVehSpdBlndX_Ary1D(void);
Ary1D_u2p14_4 * TSC_MotTqTranlDampg_Rte_Prm_MotTqTranlDampgVehSpdBlndY_Ary1D(void);

/** Per Instance Memories */
float32 *TSC_MotTqTranlDampg_Rte_Pim_dMotTqTranlDampgCmdCtrld(void);
float32 *TSC_MotTqTranlDampg_Rte_Pim_dMotTqTranlDampgSignPhaSca(void);
float32 *TSC_MotTqTranlDampg_Rte_Pim_dMotTqTranlDampgTiElpd(void);
float32 *TSC_MotTqTranlDampg_Rte_Pim_dMotTqTranlDampgVelDampgCmd(void);
uint32 *TSC_MotTqTranlDampg_Rte_Pim_TmrRefTi(void);
LoaSt1 *TSC_MotTqTranlDampg_Rte_Pim_LoaStPrev(void);
boolean *TSC_MotTqTranlDampg_Rte_Pim_DiagStsPrev(void);
boolean *TSC_MotTqTranlDampg_Rte_Pim_StLtchPrev(void);
boolean *TSC_MotTqTranlDampg_Rte_Pim_dMotTqTranlDampgTmrEna(void);



