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
 *          File:  TSC_BmwMsgSlot234Bas1Repn2BusFrChA.h
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
Std_ReturnType TSC_BmwMsgSlot234Bas1Repn2BusFrChA_Rte_Read_BmwEpsFctSts_Val(BmwEpsFctSts1 *data);
Std_ReturnType TSC_BmwMsgSlot234Bas1Repn2BusFrChA_Rte_Read_DrvgDynIfSt_Val(DrvgDynIfSt1 *data);
Std_ReturnType TSC_BmwMsgSlot234Bas1Repn2BusFrChA_Rte_Read_HaptcFbSt_Val(HaptcFbSt1 *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_BmwMsgSlot234Bas1Repn2BusFrChA_Rte_Write_sigGroup_ST_EST_sigGroup_ST_EST(const sigGroup_ST_EST1 *data);

/** Per Instance Memories */
BmwEpsFctSts1 *TSC_BmwMsgSlot234Bas1Repn2BusFrChA_Rte_Pim_BmwEpsFctStsPrev(void);
uint8 *TSC_BmwMsgSlot234Bas1Repn2BusFrChA_Rte_Pim_BurstModCntr(void);
uint8 *TSC_BmwMsgSlot234Bas1Repn2BusFrChA_Rte_Pim_CycCntr(void);
DrvgDynIfSt1 *TSC_BmwMsgSlot234Bas1Repn2BusFrChA_Rte_Pim_DrvgDynIfStPrev(void);
HaptcFbSt1 *TSC_BmwMsgSlot234Bas1Repn2BusFrChA_Rte_Pim_HaptcFbStPrev(void);
uint8 *TSC_BmwMsgSlot234Bas1Repn2BusFrChA_Rte_Pim_PerdCntr(void);



