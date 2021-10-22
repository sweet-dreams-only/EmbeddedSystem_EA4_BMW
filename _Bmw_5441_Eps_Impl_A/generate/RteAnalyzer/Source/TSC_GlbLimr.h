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
 *          File:  TSC_GlbLimr.h
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
Std_ReturnType TSC_GlbLimr_Rte_Read_HwTq_Val(float32 *data);
Std_ReturnType TSC_GlbLimr_Rte_Read_MotTqCmd_Val(float32 *data);
Std_ReturnType TSC_GlbLimr_Rte_Read_VehSpd_Val(float32 *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_GlbLimr_Rte_Write_LimdMotTqCmd_Val(float32 data);

/** Calibration Component Calibration Parameters */
Ary2D_s4p11_10_13 * TSC_GlbLimr_Rte_Prm_GlbLimrBndX_Ary2D(void);
Ary2D_s4p11_10_13 * TSC_GlbLimr_Rte_Prm_GlbLimrBndY_Ary2D(void);
Ary1D_u9p7_10 * TSC_GlbLimr_Rte_Prm_GlbLimrVehSpdBilnrSeln_Ary1D(void);
FilNotchGainRec1 * TSC_GlbLimr_Rte_Prm_GlbLimrNotchFilStruct_Rec(void);

/** Per Instance Memories */
float32 *TSC_GlbLimr_Rte_Pim_GlbLimrNotch1Fil1(void);
float32 *TSC_GlbLimr_Rte_Pim_GlbLimrNotch1Fil2(void);
float32 *TSC_GlbLimr_Rte_Pim_GlbLimrNotch2Fil1(void);
float32 *TSC_GlbLimr_Rte_Pim_GlbLimrNotch2Fil2(void);



