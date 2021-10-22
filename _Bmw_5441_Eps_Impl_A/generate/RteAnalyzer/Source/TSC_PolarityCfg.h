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
 *          File:  TSC_PolarityCfg.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Header of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/


/** Sender receiver - explicit write services */
Std_ReturnType TSC_PolarityCfg_Rte_Write_AssiMechPolarity_Val(sint8 data);
Std_ReturnType TSC_PolarityCfg_Rte_Write_HwAg0Polarity_Val(sint8 data);
Std_ReturnType TSC_PolarityCfg_Rte_Write_HwAg1Polarity_Val(sint8 data);
Std_ReturnType TSC_PolarityCfg_Rte_Write_HwAg2Polarity_Val(sint8 data);
Std_ReturnType TSC_PolarityCfg_Rte_Write_HwAg3Polarity_Val(sint8 data);
Std_ReturnType TSC_PolarityCfg_Rte_Write_HwAg4Polarity_Val(sint8 data);
Std_ReturnType TSC_PolarityCfg_Rte_Write_HwAg5Polarity_Val(sint8 data);
Std_ReturnType TSC_PolarityCfg_Rte_Write_HwAg6Polarity_Val(sint8 data);
Std_ReturnType TSC_PolarityCfg_Rte_Write_HwAg7Polarity_Val(sint8 data);
Std_ReturnType TSC_PolarityCfg_Rte_Write_HwTq0Polarity_Val(sint8 data);
Std_ReturnType TSC_PolarityCfg_Rte_Write_HwTq1Polarity_Val(sint8 data);
Std_ReturnType TSC_PolarityCfg_Rte_Write_HwTq2Polarity_Val(sint8 data);
Std_ReturnType TSC_PolarityCfg_Rte_Write_HwTq3Polarity_Val(sint8 data);
Std_ReturnType TSC_PolarityCfg_Rte_Write_HwTq4Polarity_Val(sint8 data);
Std_ReturnType TSC_PolarityCfg_Rte_Write_HwTq5Polarity_Val(sint8 data);
Std_ReturnType TSC_PolarityCfg_Rte_Write_HwTq6Polarity_Val(sint8 data);
Std_ReturnType TSC_PolarityCfg_Rte_Write_HwTq7Polarity_Val(sint8 data);
Std_ReturnType TSC_PolarityCfg_Rte_Write_MotAgMecl0Polarity_Val(sint8 data);
Std_ReturnType TSC_PolarityCfg_Rte_Write_MotAgMecl1Polarity_Val(sint8 data);
Std_ReturnType TSC_PolarityCfg_Rte_Write_MotAgMecl2Polarity_Val(sint8 data);
Std_ReturnType TSC_PolarityCfg_Rte_Write_MotAgMecl3Polarity_Val(sint8 data);
Std_ReturnType TSC_PolarityCfg_Rte_Write_MotAgMecl4Polarity_Val(sint8 data);
Std_ReturnType TSC_PolarityCfg_Rte_Write_MotAgMecl5Polarity_Val(sint8 data);
Std_ReturnType TSC_PolarityCfg_Rte_Write_MotAgMecl6Polarity_Val(sint8 data);
Std_ReturnType TSC_PolarityCfg_Rte_Write_MotAgMecl7Polarity_Val(sint8 data);
Std_ReturnType TSC_PolarityCfg_Rte_Write_MotElecMeclPolarity_Val(sint8 data);

/** Service interfaces */
Std_ReturnType TSC_PolarityCfg_Rte_Call_PolarityCfgSaved_SetRamBlockStatus(boolean RamBlockStatus_Arg);

/** SW-C local Calibration Parameters */
uint32  TSC_PolarityCfg_Rte_CData_PolarityCfgSavedDft(void);

/** Per Instance Memories */
uint32 *TSC_PolarityCfg_Rte_Pim_PolarityCfgSaved(void);



