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
 *          File:  TSC_VehSigCdng.h
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
Std_ReturnType TSC_VehSigCdng_Rte_Read_HwTq_Val(float32 *data);
Std_ReturnType TSC_VehSigCdng_Rte_Read_VehLatASerlCom_Val(float32 *data);
Std_ReturnType TSC_VehSigCdng_Rte_Read_VehLatAVldSerlCom_Logl(boolean *data);
Std_ReturnType TSC_VehSigCdng_Rte_Read_VehLgtASerlCom_Val(float32 *data);
Std_ReturnType TSC_VehSigCdng_Rte_Read_VehLgtAVldSerlCom_Logl(boolean *data);
Std_ReturnType TSC_VehSigCdng_Rte_Read_VehSpdOvrd_Val(float32 *data);
Std_ReturnType TSC_VehSigCdng_Rte_Read_VehSpdOvrdEna_Logl(boolean *data);
Std_ReturnType TSC_VehSigCdng_Rte_Read_VehSpdSerlCom_Val(float32 *data);
Std_ReturnType TSC_VehSigCdng_Rte_Read_VehSpdVldSerlCom_Logl(boolean *data);
Std_ReturnType TSC_VehSigCdng_Rte_Read_VehYawRateSerlCom_Val(float32 *data);
Std_ReturnType TSC_VehSigCdng_Rte_Read_VehYawRateVldSerlCom_Logl(boolean *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_VehSigCdng_Rte_Write_VehLatA_Val(float32 data);
Std_ReturnType TSC_VehSigCdng_Rte_Write_VehLatAEstimd_Val(float32 data);
Std_ReturnType TSC_VehSigCdng_Rte_Write_VehLatAEstimdVld_Logl(boolean data);
Std_ReturnType TSC_VehSigCdng_Rte_Write_VehLatAVld_Logl(boolean data);
Std_ReturnType TSC_VehSigCdng_Rte_Write_VehLgtA_Val(float32 data);
Std_ReturnType TSC_VehSigCdng_Rte_Write_VehLgtAVld_Logl(boolean data);
Std_ReturnType TSC_VehSigCdng_Rte_Write_VehSpd_Val(float32 data);
Std_ReturnType TSC_VehSigCdng_Rte_Write_VehSpdVld_Logl(boolean data);
Std_ReturnType TSC_VehSigCdng_Rte_Write_VehYawRate_Val(float32 data);
Std_ReturnType TSC_VehSigCdng_Rte_Write_VehYawRateVld_Logl(boolean data);

/** Client server interfaces */
Std_ReturnType TSC_VehSigCdng_Rte_Call_FltInj_f32_Oper(float32 *SigPah_Arg, uint16 LocnKey_Arg);

/** Calibration Component Calibration Parameters */
float32  TSC_VehSigCdng_Rte_Prm_VehSigCdngDftLatA_Val(void);
float32  TSC_VehSigCdng_Rte_Prm_VehSigCdngDftLgtA_Val(void);
float32  TSC_VehSigCdng_Rte_Prm_VehSigCdngDftVehSpd_Val(void);
float32  TSC_VehSigCdng_Rte_Prm_VehSigCdngDftYawRate_Val(void);
float32  TSC_VehSigCdng_Rte_Prm_VehSigCdngLatADifThd_Val(void);
float32  TSC_VehSigCdng_Rte_Prm_VehSigCdngLatAFilFrq_Val(void);
float32  TSC_VehSigCdng_Rte_Prm_VehSigCdngLatASlewRate_Val(void);
float32  TSC_VehSigCdng_Rte_Prm_VehSigCdngLtgADifThd_Val(void);
float32  TSC_VehSigCdng_Rte_Prm_VehSigCdngLtgASlewRate_Val(void);
float32  TSC_VehSigCdng_Rte_Prm_VehSigCdngVehSpdDifThd_Val(void);
float32  TSC_VehSigCdng_Rte_Prm_VehSigCdngVehSpdSlewRate_Val(void);
float32  TSC_VehSigCdng_Rte_Prm_VehSigCdngVehYawSlewRate_Val(void);
float32  TSC_VehSigCdng_Rte_Prm_VehSigCdngYawRateDifThd_Val(void);

/** Per Instance Memories */
float32 *TSC_VehSigCdng_Rte_Pim_PrevLatA(void);
float32 *TSC_VehSigCdng_Rte_Pim_PrevLtgA(void);
float32 *TSC_VehSigCdng_Rte_Pim_PrevVehSpd(void);
float32 *TSC_VehSigCdng_Rte_Pim_PrevYawRate(void);
boolean *TSC_VehSigCdng_Rte_Pim_PrevLatAVld(void);
boolean *TSC_VehSigCdng_Rte_Pim_PrevLtgAVld(void);
boolean *TSC_VehSigCdng_Rte_Pim_PrevVehSpdVld(void);
boolean *TSC_VehSigCdng_Rte_Pim_PrevYawRateVld(void);
FilLpRec1 *TSC_VehSigCdng_Rte_Pim_HwTqFilRec(void);
FilLpRec1 *TSC_VehSigCdng_Rte_Pim_LatAFilRec(void);



