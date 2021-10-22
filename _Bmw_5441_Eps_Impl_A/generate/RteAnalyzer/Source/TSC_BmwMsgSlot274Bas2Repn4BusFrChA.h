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
 *          File:  TSC_BmwMsgSlot274Bas2Repn4BusFrChA.h
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
Std_ReturnType TSC_BmwMsgSlot274Bas2Repn4BusFrChA_Rte_Read_BmwFltLampFlsgFrq_Val(BmwFltLampFlsgFrq1 *data);
Std_ReturnType TSC_BmwMsgSlot274Bas2Repn4BusFrChA_Rte_Read_BmwFltLampReqSts_Val(BmwFltLampReqSts1 *data);
Std_ReturnType TSC_BmwMsgSlot274Bas2Repn4BusFrChA_Rte_Read_BmwFltLampReqTxTyp_Val(uint8 *data);
Std_ReturnType TSC_BmwMsgSlot274Bas2Repn4BusFrChA_Rte_Read_BmwFltLampReqTyp_Val(BmwFltLampReqTyp2 *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_BmwMsgSlot274Bas2Repn4BusFrChA_Rte_Write_sigGroup_DISP_CC_EPS_sigGroup_DISP_CC_EPS(const sigGroup_DISP_CC_EPS1 *data);

/** Sender receiver - invalidation */
Std_ReturnType TSC_BmwMsgSlot274Bas2Repn4BusFrChA_Rte_Invalidate_sigGroup_DISP_CC_EPS_sigGroup_DISP_CC_EPS(void);

/** Per Instance Memories */
BmwFltLampReqTyp2 *TSC_BmwMsgSlot274Bas2Repn4BusFrChA_Rte_Pim_BmwFltLampReqTypPrev(void);
BmwFltLampFlsgFrq1 *TSC_BmwMsgSlot274Bas2Repn4BusFrChA_Rte_Pim_BmwFltLampFlsgFrqPrev(void);
BmwFltLampReqSts1 *TSC_BmwMsgSlot274Bas2Repn4BusFrChA_Rte_Pim_BmwFltLampReqStsPrev(void);
uint8 *TSC_BmwMsgSlot274Bas2Repn4BusFrChA_Rte_Pim_BmwFltLampReqTxTypPrev(void);
uint8 *TSC_BmwMsgSlot274Bas2Repn4BusFrChA_Rte_Pim_LstTxCntr(void);
uint8 *TSC_BmwMsgSlot274Bas2Repn4BusFrChA_Rte_Pim_PerdCntr(void);



