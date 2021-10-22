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
 *          File:  TSC_MotCurrRegCfg.h
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
Std_ReturnType TSC_MotCurrRegCfg_Rte_Read_DualEcuMotCtrlMtgtnEna_Logl(boolean *data);
Std_ReturnType TSC_MotCurrRegCfg_Rte_Read_MotAndThermProtnLoaMod_Val(uint8 *data);
Std_ReturnType TSC_MotCurrRegCfg_Rte_Read_MotCurrEolCalSt_Val(MotCurrEolCalSt2 *data);
Std_ReturnType TSC_MotCurrRegCfg_Rte_Read_MotInduDaxEstimd_Val(float32 *data);
Std_ReturnType TSC_MotCurrRegCfg_Rte_Read_MotInduQaxEstimd_Val(float32 *data);
Std_ReturnType TSC_MotCurrRegCfg_Rte_Read_MotREstimd_Val(float32 *data);
Std_ReturnType TSC_MotCurrRegCfg_Rte_Read_MotVelMrf_Val(float32 *data);
Std_ReturnType TSC_MotCurrRegCfg_Rte_Read_VehSpd_Val(float32 *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_MotCurrRegCfg_Rte_Write_MotAgElecDly_Val(float32 data);
Std_ReturnType TSC_MotCurrRegCfg_Rte_Write_MotDampgDax_Val(float32 data);
Std_ReturnType TSC_MotCurrRegCfg_Rte_Write_MotDampgQax_Val(float32 data);
Std_ReturnType TSC_MotCurrRegCfg_Rte_Write_MotIntglGainDax_Val(float32 data);
Std_ReturnType TSC_MotCurrRegCfg_Rte_Write_MotIntglGainQax_Val(float32 data);
Std_ReturnType TSC_MotCurrRegCfg_Rte_Write_MotPropGainDax_Val(float32 data);
Std_ReturnType TSC_MotCurrRegCfg_Rte_Write_MotPropGainQax_Val(float32 data);

/** Calibration Component Calibration Parameters */
float32  TSC_MotCurrRegCfg_Rte_Prm_MotCurrRegCfgCtrlrDynGainVehSpdCutOff_Val(void);
float32  TSC_MotCurrRegCfg_Rte_Prm_MotCurrRegCfgIntglGainSampleTi_Val(void);
float32  TSC_MotCurrRegCfg_Rte_Prm_MotCurrRegCfgMotAgCompuDly_Val(void);
float32  TSC_MotCurrRegCfg_Rte_Prm_MotCurrRegCfgMotDampgRatDax_Val(void);
float32  TSC_MotCurrRegCfg_Rte_Prm_MotCurrRegCfgMotDampgRatQax_Val(void);
float32  TSC_MotCurrRegCfg_Rte_Prm_MotCurrRegCfgMotRVirtDax_Val(void);
float32  TSC_MotCurrRegCfg_Rte_Prm_MotCurrRegCfgMotRVirtQax_Val(void);
float32  TSC_MotCurrRegCfg_Rte_Prm_MotCurrRegCfgMotVelFilFrq_Val(void);
uint8  TSC_MotCurrRegCfg_Rte_Prm_SysGlbPrmMotPoleCnt_Val(void);
boolean  TSC_MotCurrRegCfg_Rte_Prm_MotCurrRegCfgCurrLoopSecOrderTrfFctEna_Logl(void);
boolean  TSC_MotCurrRegCfg_Rte_Prm_MotRefMdlFbCtrlDi_Logl(void);
Ary1D_u10p6_4 * TSC_MotCurrRegCfg_Rte_Prm_MotCurrRegCfgMotClsdLoopBwDaxY_Ary1D(void);
Ary1D_u10p6_4 * TSC_MotCurrRegCfg_Rte_Prm_MotCurrRegCfgMotClsdLoopBwQaxY_Ary1D(void);
Ary1D_u11p5_4 * TSC_MotCurrRegCfg_Rte_Prm_MotCurrRegCfgMotCtrlPrmSelnX_Ary1D(void);
Ary1D_u9p7_4 * TSC_MotCurrRegCfg_Rte_Prm_MotCurrRegCfgMotNatFrqDaxY_Ary1D(void);
Ary1D_u9p7_4 * TSC_MotCurrRegCfg_Rte_Prm_MotCurrRegCfgMotNatFrqQaxY_Ary1D(void);

/** Per Instance Memories */
float32 *TSC_MotCurrRegCfg_Rte_Pim_dMotCurrRegCfgMotVelMrfFild(void);
FilLpRec1 *TSC_MotCurrRegCfg_Rte_Pim_MotVelMrfFild(void);



