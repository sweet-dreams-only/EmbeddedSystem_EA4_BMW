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
 *          File:  TSC_HwTqTrakgCtrl.h
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
Std_ReturnType TSC_HwTqTrakgCtrl_Rte_Read_HwTqCmd_Val(float32 *data);
Std_ReturnType TSC_HwTqTrakgCtrl_Rte_Read_MotTqCmdOvrl_Val(float32 *data);
Std_ReturnType TSC_HwTqTrakgCtrl_Rte_Read_SysTqRat_Val(float32 *data);
Std_ReturnType TSC_HwTqTrakgCtrl_Rte_Read_TorsBarStEstimd_Rec(TorsBarStEstimdRec1 *data);
Std_ReturnType TSC_HwTqTrakgCtrl_Rte_Read_VehSpd_Val(float32 *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_HwTqTrakgCtrl_Rte_Write_MotTqCmdTrakgCtrl_Val(float32 data);

/** Calibration Component Calibration Parameters */
float32  TSC_HwTqTrakgCtrl_Rte_Prm_HwTqTrakgCtrlMotTqCmdOvrlGain_Val(void);
Ary1D_s3p12_4 * TSC_HwTqTrakgCtrl_Rte_Prm_HwTqTrakgCtrlFbGain1_Ary1D(void);
Ary1D_s14p1_4 * TSC_HwTqTrakgCtrl_Rte_Prm_HwTqTrakgCtrlFbGain2_Ary1D(void);
Ary1D_s8p7_4 * TSC_HwTqTrakgCtrl_Rte_Prm_HwTqTrakgCtrlFbGain3_Ary1D(void);
Ary1D_s3p12_4 * TSC_HwTqTrakgCtrl_Rte_Prm_HwTqTrakgCtrlFbGain4_Ary1D(void);
Ary1D_s3p12_4 * TSC_HwTqTrakgCtrl_Rte_Prm_HwTqTrakgCtrlFbGain5_Ary1D(void);
Ary1D_s7p8_4 * TSC_HwTqTrakgCtrl_Rte_Prm_HwTqTrakgCtrlFfGainScaY_Ary1D(void);
Ary1D_u9p7_4 * TSC_HwTqTrakgCtrl_Rte_Prm_HwTqTrakgCtrlVehSpdScaX_Ary1D(void);




