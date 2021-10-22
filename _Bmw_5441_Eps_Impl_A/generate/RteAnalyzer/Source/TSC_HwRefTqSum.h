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
 *          File:  TSC_HwRefTqSum.h
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
Std_ReturnType TSC_HwRefTqSum_Rte_Read_HwTqCmdDampg_Val(float32 *data);
Std_ReturnType TSC_HwRefTqSum_Rte_Read_HwTqCmdEffort_Val(float32 *data);
Std_ReturnType TSC_HwRefTqSum_Rte_Read_HwTqCmdHys_Val(float32 *data);
Std_ReturnType TSC_HwRefTqSum_Rte_Read_HwTqCmdOvrl_Val(float32 *data);
Std_ReturnType TSC_HwRefTqSum_Rte_Read_RtnCmd_Val(float32 *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_HwRefTqSum_Rte_Write_HwTqCmdSum_Val(float32 data);

/** Calibration Component Calibration Parameters */
float32  TSC_HwRefTqSum_Rte_Prm_SysGlbPrmSysTqRat_Val(void);




