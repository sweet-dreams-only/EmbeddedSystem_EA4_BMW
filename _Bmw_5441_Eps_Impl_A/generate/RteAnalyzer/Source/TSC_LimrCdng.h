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
 *          File:  TSC_LimrCdng.h
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
Std_ReturnType TSC_LimrCdng_Rte_Read_EotAssiSca_Val(float32 *data);
Std_ReturnType TSC_LimrCdng_Rte_Read_EotMotTqLim_Val(float32 *data);
Std_ReturnType TSC_LimrCdng_Rte_Read_StallMotTqLim_Val(float32 *data);
Std_ReturnType TSC_LimrCdng_Rte_Read_SysMotTqCmdSca_Val(float32 *data);
Std_ReturnType TSC_LimrCdng_Rte_Read_ThermMotTqLim_Val(float32 *data);
Std_ReturnType TSC_LimrCdng_Rte_Read_VehSpd_Val(float32 *data);
Std_ReturnType TSC_LimrCdng_Rte_Read_VehSpdMotTqLim_Val(float32 *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_LimrCdng_Rte_Write_EotAssiScaCdnd_Val(float32 data);
Std_ReturnType TSC_LimrCdng_Rte_Write_EotMotTqLimCdnd_Val(float32 data);
Std_ReturnType TSC_LimrCdng_Rte_Write_StallMotTqLimCdnd_Val(float32 data);
Std_ReturnType TSC_LimrCdng_Rte_Write_SysMotTqCmdScaCdnd_Val(float32 data);
Std_ReturnType TSC_LimrCdng_Rte_Write_ThermMotTqLimCdnd_Val(float32 data);
Std_ReturnType TSC_LimrCdng_Rte_Write_VehSpdMotTqLimCdnd_Val(float32 data);

/** Client server interfaces */
Std_ReturnType TSC_LimrCdng_Rte_Call_FltInj_f32_Oper(float32 *SigPah_Arg, uint16 LocnKey_Arg);

/** Calibration Component Calibration Parameters */
float32  TSC_LimrCdng_Rte_Prm_LimrCdngGainDecSlew_Val(void);
float32  TSC_LimrCdng_Rte_Prm_LimrCdngTqDecSlew_Val(void);
Ary1D_u9p7_2 * TSC_LimrCdng_Rte_Prm_LimrCdngGainIncSlewX_Ary1D(void);
Ary1D_u9p7_2 * TSC_LimrCdng_Rte_Prm_LimrCdngGainIncSlewY_Ary1D(void);
Ary1D_u9p7_2 * TSC_LimrCdng_Rte_Prm_LimrCdngTqIncSlewX_Ary1D(void);
Ary1D_u13p3_2 * TSC_LimrCdng_Rte_Prm_LimrCdngTqIncSlewY_Ary1D(void);

/** Per Instance Memories */
float32 *TSC_LimrCdng_Rte_Pim_PrevEotAssiScaCdnd(void);
float32 *TSC_LimrCdng_Rte_Pim_PrevEotMotTqLimCdnd(void);
float32 *TSC_LimrCdng_Rte_Pim_PrevStallMotTqLimCdnd(void);
float32 *TSC_LimrCdng_Rte_Pim_PrevSysMotTqCmdScaCdnd(void);
float32 *TSC_LimrCdng_Rte_Pim_PrevThermMotTqLimCdnd(void);
float32 *TSC_LimrCdng_Rte_Pim_PrevVehSpdMotTqLimCdnd(void);



