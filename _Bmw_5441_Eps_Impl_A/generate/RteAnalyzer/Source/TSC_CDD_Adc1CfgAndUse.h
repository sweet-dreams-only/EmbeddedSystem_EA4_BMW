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
 *          File:  TSC_CDD_Adc1CfgAndUse.h
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
Std_ReturnType TSC_CDD_Adc1CfgAndUse_Rte_Read_AdcDiagcEndPtrOutp_Val(uint8 *data);
Std_ReturnType TSC_CDD_Adc1CfgAndUse_Rte_Read_AdcDiagcStrtPtrOutp_Val(uint8 *data);

/** Per Instance Memories */
uint8 *TSC_CDD_Adc1CfgAndUse_Rte_Pim_Adc1DiagcEndPtr(void);
uint8 *TSC_CDD_Adc1CfgAndUse_Rte_Pim_Adc1DiagcStrtPtr(void);



