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
 *          File:  TSC_BmwMsgSlot51Bas0Repn2BusFrChA.h
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
Std_ReturnType TSC_BmwMsgSlot51Bas0Repn2BusFrChA_Rte_Read_BmwPinionAg_Val(float32 *data);
Std_ReturnType TSC_BmwMsgSlot51Bas0Repn2BusFrChA_Rte_Read_BmwPinionAgIdx_Val(float32 *data);
Std_ReturnType TSC_BmwMsgSlot51Bas0Repn2BusFrChA_Rte_Read_BmwPinionAgIdxVld_Logl(boolean *data);
Std_ReturnType TSC_BmwMsgSlot51Bas0Repn2BusFrChA_Rte_Read_BmwPinionAgQlfr_Val(BmwPinionAgQlfr1 *data);
Std_ReturnType TSC_BmwMsgSlot51Bas0Repn2BusFrChA_Rte_Read_BmwRackCntrToVehCntrOffs_Val(float32 *data);
Std_ReturnType TSC_BmwMsgSlot51Bas0Repn2BusFrChA_Rte_Read_BmwRackCntrToVehCntrOffsVld_Logl(boolean *data);
Std_ReturnType TSC_BmwMsgSlot51Bas0Repn2BusFrChA_Rte_Read_BmwSeldPosnUnit_Val(BmwSeldPosnUnit1 *data);
Std_ReturnType TSC_BmwMsgSlot51Bas0Repn2BusFrChA_Rte_Read_BmwTarMotTq_Val(float32 *data);
Std_ReturnType TSC_BmwMsgSlot51Bas0Repn2BusFrChA_Rte_Read_BmwTarMotTqVld_Logl(boolean *data);
Std_ReturnType TSC_BmwMsgSlot51Bas0Repn2BusFrChA_Rte_Read_BmwTqSnsrIdx_Val(BmwTqSnsrIdx1 *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_BmwMsgSlot51Bas0Repn2BusFrChA_Rte_Write_TRGG_ENGTORQ_EPS_Val(uint16 data);
Std_ReturnType TSC_BmwMsgSlot51Bas0Repn2BusFrChA_Rte_Write_sigGroup_AVL_PO_EPS_sigGroup_AVL_PO_EPS(const sigGroup_AVL_PO_EPS1 *data);

/** Sender receiver - invalidation */
Std_ReturnType TSC_BmwMsgSlot51Bas0Repn2BusFrChA_Rte_Invalidate_sigGroup_AVL_PO_EPS_sigGroup_AVL_PO_EPS(void);

/** Calibration Component Calibration Parameters */
sint8  TSC_BmwMsgSlot51Bas0Repn2BusFrChA_Rte_Prm_BmwSteerPolarity_Val(void);




