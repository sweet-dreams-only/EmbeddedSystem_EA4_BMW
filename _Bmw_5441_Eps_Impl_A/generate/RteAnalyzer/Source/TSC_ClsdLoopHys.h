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
 *          File:  TSC_ClsdLoopHys.h
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
Std_ReturnType TSC_ClsdLoopHys_Rte_Read_HwAg_Val(float32 *data);
Std_ReturnType TSC_ClsdLoopHys_Rte_Read_HwTq_Val(float32 *data);
Std_ReturnType TSC_ClsdLoopHys_Rte_Read_HwTqCmdEffort_Val(float32 *data);
Std_ReturnType TSC_ClsdLoopHys_Rte_Read_HwVel_Val(float32 *data);
Std_ReturnType TSC_ClsdLoopHys_Rte_Read_RackFEstimd_Val(float32 *data);
Std_ReturnType TSC_ClsdLoopHys_Rte_Read_SysFricOffs_Val(float32 *data);
Std_ReturnType TSC_ClsdLoopHys_Rte_Read_VehSpd_Val(float32 *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_ClsdLoopHys_Rte_Write_HwTqCmdHys_Val(float32 data);

/** Calibration Component Calibration Parameters */
float32  TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysHwAgBlndFac_Val(void);
float32  TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysPolarity_Val(void);
float32  TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysSteerInHwAgNegLowrLim_Val(void);
float32  TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysSteerInHwAgNegUpprLim_Val(void);
float32  TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysSteerInHwAgPosLowrLim_Val(void);
float32  TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysSteerInHwAgPosUpprLim_Val(void);
float32  TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysSteerOutHwAgNegLowrLim_Val(void);
float32  TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysSteerOutHwAgNegUpprLim_Val(void);
float32  TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysSteerOutHwAgPosLowrLim_Val(void);
float32  TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysSteerOutHwAgPosUpprLim_Val(void);
Ary1D_u6p10_12 * TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysDeltaY_Ary1D(void);
Ary1D_u6p10_12 * TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysGainY_Ary1D(void);
Ary1D_u6p10_2 * TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysHwAgQuadBlndX_Ary1D(void);
Ary1D_u2p14_2 * TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysHwAgQuadBlndY_Ary1D(void);
Ary1D_u2p14_2 * TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysHwAgQuadQlfrX_Ary1D(void);
Ary1D_u2p14_2 * TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysHwAgQuadQlfrY_Ary1D(void);
Ary1D_u6p10_2 * TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysHwVelQuadBlndX_Ary1D(void);
Ary1D_u2p14_2 * TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysHwVelQuadBlndY_Ary1D(void);
Ary1D_u15p1_4 * TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysRackFFacX_Ary1D(void);
Ary2D_u2p14_12_4 * TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysRackFFacY_Ary2D(void);
Ary1D_u6p10_12 * TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysRhoY_Ary1D(void);
Ary1D_u9p7_5 * TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysSysFricOffsLimX_Ary1D(void);
Ary1D_u4p12_5 * TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysSysFricOffsLimY_Ary1D(void);
Ary1D_s4p11_7 * TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysSysFricScaX_Ary1D(void);
Ary1D_u2p14_7 * TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysSysFricScaY_Ary1D(void);
Ary1D_u9p7_12 * TSC_ClsdLoopHys_Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D(void);

/** Per Instance Memories */
float32 *TSC_ClsdLoopHys_Rte_Pim_IntgtrSt(void);



