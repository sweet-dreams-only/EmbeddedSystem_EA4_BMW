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
 *          File:  TSC_HwTqArbn.h
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
Std_ReturnType TSC_HwTqArbn_Rte_Read_HwTqA_Val(float32 *data);
Std_ReturnType TSC_HwTqArbn_Rte_Read_HwTqAQlfr_Val(SigQlfr1 *data);
Std_ReturnType TSC_HwTqArbn_Rte_Read_HwTqARollgCntr_Val(uint8 *data);
Std_ReturnType TSC_HwTqArbn_Rte_Read_HwTqB_Val(float32 *data);
Std_ReturnType TSC_HwTqArbn_Rte_Read_HwTqBQlfr_Val(SigQlfr1 *data);
Std_ReturnType TSC_HwTqArbn_Rte_Read_HwTqBRollgCntr_Val(uint8 *data);
Std_ReturnType TSC_HwTqArbn_Rte_Read_HwTqCorrlnSts_Val(uint8 *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_HwTqArbn_Rte_Write_HwTq_Val(float32 data);

/** Per Instance Memories */
float32 *TSC_HwTqArbn_Rte_Pim_HwTqPrevHwTq(void);
uint8 *TSC_HwTqArbn_Rte_Pim_HwTqARollgCntrPrev(void);
uint8 *TSC_HwTqArbn_Rte_Pim_HwTqAStallCntrPrev(void);
uint8 *TSC_HwTqArbn_Rte_Pim_HwTqBRollgCntrPrev(void);
uint8 *TSC_HwTqArbn_Rte_Pim_HwTqBStallCntrPrev(void);
boolean *TSC_HwTqArbn_Rte_Pim_dHwTqArbnChAAvl(void);



