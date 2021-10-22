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
 *          File:  TSC_BmwMsgSlot49Bas1Repn2BusFrChA.h
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
Std_ReturnType TSC_BmwMsgSlot49Bas1Repn2BusFrChA_Rte_Read_BattRtnCurrAmpr_Val(float32 *data);
Std_ReturnType TSC_BmwMsgSlot49Bas1Repn2BusFrChA_Rte_Read_BattRtnCurrAmprQlfr_Val(BattRtnCurrAmprQlfr1 *data);
Std_ReturnType TSC_BmwMsgSlot49Bas1Repn2BusFrChA_Rte_Read_EpsCurrLimSts_Val(EpsCurrLimSts1 *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_BmwMsgSlot49Bas1Repn2BusFrChA_Rte_Write_sigGroup_DT_EST_sigGroup_DT_EST(const sigGroup_DT_EST1 *data);




