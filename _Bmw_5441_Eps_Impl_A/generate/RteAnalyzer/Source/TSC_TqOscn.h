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
 *          File:  TSC_TqOscn.h
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
Std_ReturnType TSC_TqOscn_Rte_Read_HwOscnEna_Logl(boolean *data);
Std_ReturnType TSC_TqOscn_Rte_Read_HwOscnFallRampRate_Val(float32 *data);
Std_ReturnType TSC_TqOscn_Rte_Read_HwOscnFrq_Val(float32 *data);
Std_ReturnType TSC_TqOscn_Rte_Read_HwOscnMotAmp_Val(float32 *data);
Std_ReturnType TSC_TqOscn_Rte_Read_HwOscnRisngRampRate_Val(float32 *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_TqOscn_Rte_Write_HwOscnActv_Logl(boolean data);
Std_ReturnType TSC_TqOscn_Rte_Write_HwOscnCmd_Val(float32 data);
Std_ReturnType TSC_TqOscn_Rte_Write_HwOscnDcThdExcdd_Logl(boolean data);

/** Client server interfaces */
Std_ReturnType TSC_TqOscn_Rte_Call_FltInj_f32_Oper(float32 *SigPah_Arg, uint16 LocnKey_Arg);

/** Calibration Component Calibration Parameters */
float32  TSC_TqOscn_Rte_Prm_TqOscnFallRampRateCal_Val(void);
float32  TSC_TqOscn_Rte_Prm_TqOscnRisngRampRateCal_Val(void);
boolean  TSC_TqOscn_Rte_Prm_TqOscnUseRampRateCal_Logl(void);
Ary1D_u5p11_11 * TSC_TqOscn_Rte_Prm_TqOscnAmpLimY_Ary1D(void);
Ary1D_u8p8_11 * TSC_TqOscn_Rte_Prm_TqOscnFrqIn_Ary1D(void);

/** Per Instance Memories */
float32 *TSC_TqOscn_Rte_Pim_AmpRampSt(void);
float32 *TSC_TqOscn_Rte_Pim_PrevFallRampRate(void);
float32 *TSC_TqOscn_Rte_Pim_PrevLimdAmp(void);
float32 *TSC_TqOscn_Rte_Pim_PrevPhaAg(void);
float32 *TSC_TqOscn_Rte_Pim_PrevPhaAgInc(void);
float32 *TSC_TqOscn_Rte_Pim_PrevRisngRampRate(void);
float32 *TSC_TqOscn_Rte_Pim_dTqOscnPreFinalCmd(void);
float32 *TSC_TqOscn_Rte_Pim_dTqOscnRateLimdAmp(void);
float32 *TSC_TqOscn_Rte_Pim_dTqOscnSinCmd(void);
boolean *TSC_TqOscn_Rte_Pim_PrevActv(void);
boolean *TSC_TqOscn_Rte_Pim_PrevDcThdExcdd(void);
boolean *TSC_TqOscn_Rte_Pim_PrevEna(void);
boolean *TSC_TqOscn_Rte_Pim_dTqOscnNonZeroAmpFlg(void);
FilLpRec1 *TSC_TqOscn_Rte_Pim_PreFinalCmdLpFil(void);



