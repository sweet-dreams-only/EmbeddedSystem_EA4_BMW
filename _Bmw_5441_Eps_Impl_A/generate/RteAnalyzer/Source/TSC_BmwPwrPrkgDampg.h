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
 *          File:  TSC_BmwPwrPrkgDampg.h
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
Std_ReturnType TSC_BmwPwrPrkgDampg_Rte_Read_DampgCmdBas_Val(float32 *data);
Std_ReturnType TSC_BmwPwrPrkgDampg_Rte_Read_DampgCmdPwrPrkgEna_Logl(boolean *data);
Std_ReturnType TSC_BmwPwrPrkgDampg_Rte_Read_HwVel_Val(float32 *data);
Std_ReturnType TSC_BmwPwrPrkgDampg_Rte_Read_PinionAg_Val(float32 *data);
Std_ReturnType TSC_BmwPwrPrkgDampg_Rte_Read_PinionAgConf_Val(float32 *data);
Std_ReturnType TSC_BmwPwrPrkgDampg_Rte_Read_VehSpd_Val(float32 *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_BmwPwrPrkgDampg_Rte_Write_DampgCmdPwrPrkg_Val(float32 data);

/** Calibration Component Calibration Parameters */
float32  TSC_BmwPwrPrkgDampg_Rte_Prm_BmwPwrPrkgDampgMaxRate_Val(void);
float32  TSC_BmwPwrPrkgDampg_Rte_Prm_BmwPwrPrkgDampgMinPinionAgConf_Val(void);
boolean  TSC_BmwPwrPrkgDampg_Rte_Prm_BmwPwrPrkgDampgDiScadDampg_Logl(void);
Ary2D_u5p11_9_9 * TSC_BmwPwrPrkgDampg_Rte_Prm_BmwPwrPrkgDampgBasPwrPrkgDampgY_Ary2D(void);
Ary1D_u6p10_9 * TSC_BmwPwrPrkgDampg_Rte_Prm_BmwPwrPrkgDampgHwVelTblX_Ary1D(void);
Ary1D_u12p4_9 * TSC_BmwPwrPrkgDampg_Rte_Prm_BmwPwrPrkgDampgPinionAgSelnTbl_Ary1D(void);
Ary1D_u9p7_11 * TSC_BmwPwrPrkgDampg_Rte_Prm_BmwPwrPrkgDampgVehSpdLnrSelnX_Ary1D(void);
Ary1D_u1p15_11 * TSC_BmwPwrPrkgDampg_Rte_Prm_BmwPwrPrkgDampgVehSpdScaFacY_Ary1D(void);

/** Per Instance Memories */
float32 *TSC_BmwPwrPrkgDampg_Rte_Pim_DampgCmdPwrPrkgStVari(void);



