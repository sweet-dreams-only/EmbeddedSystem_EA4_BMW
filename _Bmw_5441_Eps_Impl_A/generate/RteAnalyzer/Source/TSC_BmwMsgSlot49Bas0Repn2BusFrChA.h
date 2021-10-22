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
 *          File:  TSC_BmwMsgSlot49Bas0Repn2BusFrChA.h
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
Std_ReturnType TSC_BmwMsgSlot49Bas0Repn2BusFrChA_Rte_Read_ElecInpPwrEstim_Val(float32 *data);
Std_ReturnType TSC_BmwMsgSlot49Bas0Repn2BusFrChA_Rte_Read_HwTq_Val(float32 *data);
Std_ReturnType TSC_BmwMsgSlot49Bas0Repn2BusFrChA_Rte_Read_HwTq4Qlfr_Val(SigQlfr1 *data);
Std_ReturnType TSC_BmwMsgSlot49Bas0Repn2BusFrChA_Rte_Read_HwTq5Qlfr_Val(SigQlfr1 *data);
Std_ReturnType TSC_BmwMsgSlot49Bas0Repn2BusFrChA_Rte_Read_RackFEstimd_Val(float32 *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_BmwMsgSlot49Bas0Repn2BusFrChA_Rte_Write_sigGroup_AVL_FORC_GRD_sigGroup_AVL_FORC_GRD(const sigGroup_AVL_FORC_GRD1 *data);
Std_ReturnType TSC_BmwMsgSlot49Bas0Repn2BusFrChA_Rte_Write_sigGroup_AVL_STMOM_DV_ACT_sigGroup_AVL_STMOM_DV_ACT(const sigGroup_AVL_STMOM_DV_ACT1 *data);

/** Calibration Component Calibration Parameters */
float32  TSC_BmwMsgSlot49Bas0Repn2BusFrChA_Rte_Prm_BmwMsgSlot49Bas0Repn2BusFrChARackEstimnLowrLim_Val(void);
float32  TSC_BmwMsgSlot49Bas0Repn2BusFrChA_Rte_Prm_BmwMsgSlot49Bas0Repn2BusFrChARackEstimnUpprLim_Val(void);
sint8  TSC_BmwMsgSlot49Bas0Repn2BusFrChA_Rte_Prm_BmwMsgSlot49Bas0Repn2BusFrChABmwSteerPolarity_Val(void);

/** Per Instance Memories */
uint8 *TSC_BmwMsgSlot49Bas0Repn2BusFrChA_Rte_Pim_PerCntr(void);



