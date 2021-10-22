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
 *          File:  TSC_MotTqCalcd.h
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
Std_ReturnType TSC_MotTqCalcd_Rte_Read_MotAndThermProtnLoaMod_Val(uint8 *data);
Std_ReturnType TSC_MotTqCalcd_Rte_Read_MotBackEmfConEstimd_Val(float32 *data);
Std_ReturnType TSC_MotTqCalcd_Rte_Read_MotCurrDax_Val(float32 *data);
Std_ReturnType TSC_MotTqCalcd_Rte_Read_MotCurrDaxCmd_Val(float32 *data);
Std_ReturnType TSC_MotTqCalcd_Rte_Read_MotCurrQax_Val(float32 *data);
Std_ReturnType TSC_MotTqCalcd_Rte_Read_MotCurrQaxCmd_Val(float32 *data);
Std_ReturnType TSC_MotTqCalcd_Rte_Read_MotInduDaxEstimd_Val(float32 *data);
Std_ReturnType TSC_MotTqCalcd_Rte_Read_MotInduQaxEstimd_Val(float32 *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_MotTqCalcd_Rte_Write_MotTqEstimd_Val(float32 data);

/** Calibration Component Calibration Parameters */
uint8  TSC_MotTqCalcd_Rte_Prm_SysGlbPrmMotPoleCnt_Val(void);




