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
 *          File:  TSC_Effort.h
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
Std_ReturnType TSC_Effort_Rte_Read_EffortCmdSca_Val(float32 *data);
Std_ReturnType TSC_Effort_Rte_Read_RackFEstimd_Val(float32 *data);
Std_ReturnType TSC_Effort_Rte_Read_VehSpd_Val(float32 *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_Effort_Rte_Write_HwTqCmdEffort_Val(float32 data);

/** Calibration Component Calibration Parameters */
float32  TSC_Effort_Rte_Prm_EffortScaRackFThd_Val(void);
Ary2D_u15p1_10_24 * TSC_Effort_Rte_Prm_EffortRackFX_Ary2D(void);
Ary2D_u4p12_10_24 * TSC_Effort_Rte_Prm_EffortRackFY_Ary2D(void);
Ary1D_s15p0_10 * TSC_Effort_Rte_Prm_EffortScaBlndX_Ary1D(void);
Ary1D_u1p15_10 * TSC_Effort_Rte_Prm_EffortScaBlndY_Ary1D(void);
Ary1D_u9p7_10 * TSC_Effort_Rte_Prm_EffortVehSpdBilnrSeln_Ary1D(void);




