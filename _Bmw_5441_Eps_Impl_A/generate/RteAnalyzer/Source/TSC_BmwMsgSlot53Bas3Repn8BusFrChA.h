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
 *          File:  TSC_BmwMsgSlot53Bas3Repn8BusFrChA.h
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
Std_ReturnType TSC_BmwMsgSlot53Bas3Repn8BusFrChA_Rte_Read_FACT_MO_STE_SO_DXP_FACT_MO_STE_SO_DXP(FACT_MO_STE_SO_DXP1 *data);
Std_ReturnType TSC_BmwMsgSlot53Bas3Repn8BusFrChA_Rte_Read_FltCodEnad_Logl(boolean *data);
Std_ReturnType TSC_BmwMsgSlot53Bas3Repn8BusFrChA_Rte_Read_SU_CLU_STMOM_SFE_DXP_SU_CLU_STMOM_SFE_DXP(SU_CLU_STMOM_SFE_DXP1 *data);
Std_ReturnType TSC_BmwMsgSlot53Bas3Repn8BusFrChA_Rte_Read_FltCodEnad_Logl(boolean *data);
Std_ReturnType TSC_BmwMsgSlot53Bas3Repn8BusFrChA_Rte_Read_FACT_MO_STE_SO_DXP_FACT_MO_STE_SO_DXP(FACT_MO_STE_SO_DXP1 *data);
Std_ReturnType TSC_BmwMsgSlot53Bas3Repn8BusFrChA_Rte_Read_FltCodEnad_Logl(boolean *data);
Std_ReturnType TSC_BmwMsgSlot53Bas3Repn8BusFrChA_Rte_Read_SU_CLU_STMOM_SFE_DXP_SU_CLU_STMOM_SFE_DXP(SU_CLU_STMOM_SFE_DXP1 *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_BmwMsgSlot53Bas3Repn8BusFrChA_Rte_Write_BmwRtIdx_Val(BmwRtIdx1 data);
Std_ReturnType TSC_BmwMsgSlot53Bas3Repn8BusFrChA_Rte_Write_BmwRtIdxVld_Logl(boolean data);
Std_ReturnType TSC_BmwMsgSlot53Bas3Repn8BusFrChA_Rte_Write_BmwSteerMdfnFac_Val(float32 data);
Std_ReturnType TSC_BmwMsgSlot53Bas3Repn8BusFrChA_Rte_Write_BmwSteerMdfnFacSts_Val(BmwSteerMdfnFacSts1 data);
Std_ReturnType TSC_BmwMsgSlot53Bas3Repn8BusFrChA_Rte_Write_BmwRtIdx_Val(BmwRtIdx1 data);
Std_ReturnType TSC_BmwMsgSlot53Bas3Repn8BusFrChA_Rte_Write_BmwRtIdxVld_Logl(boolean data);
Std_ReturnType TSC_BmwMsgSlot53Bas3Repn8BusFrChA_Rte_Write_BmwSteerMdfnFac_Val(float32 data);
Std_ReturnType TSC_BmwMsgSlot53Bas3Repn8BusFrChA_Rte_Write_BmwSteerMdfnFacSts_Val(BmwSteerMdfnFacSts1 data);
Std_ReturnType TSC_BmwMsgSlot53Bas3Repn8BusFrChA_Rte_Write_BmwRtIdx_Val(BmwRtIdx1 data);
Std_ReturnType TSC_BmwMsgSlot53Bas3Repn8BusFrChA_Rte_Write_BmwRtIdxVld_Logl(boolean data);
Std_ReturnType TSC_BmwMsgSlot53Bas3Repn8BusFrChA_Rte_Write_BmwSteerMdfnFac_Val(float32 data);
Std_ReturnType TSC_BmwMsgSlot53Bas3Repn8BusFrChA_Rte_Write_BmwSteerMdfnFacSts_Val(BmwSteerMdfnFacSts1 data);

/** Sender receiver - update flag */
boolean TSC_BmwMsgSlot53Bas3Repn8BusFrChA_Rte_IsUpdated_FACT_MO_STE_SO_DXP_FACT_MO_STE_SO_DXP(void);
boolean TSC_BmwMsgSlot53Bas3Repn8BusFrChA_Rte_IsUpdated_FACT_MO_STE_SO_DXP_FACT_MO_STE_SO_DXP(void);

/** Client server interfaces */
Std_ReturnType TSC_BmwMsgSlot53Bas3Repn8BusFrChA_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg);
Std_ReturnType TSC_BmwMsgSlot53Bas3Repn8BusFrChA_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg);
Std_ReturnType TSC_BmwMsgSlot53Bas3Repn8BusFrChA_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg);

/** Per Instance Memories */
float32 *TSC_BmwMsgSlot53Bas3Repn8BusFrChA_Rte_Pim_BmwSteerMdfnFacPrev(void);
BmwRtIdx1 *TSC_BmwMsgSlot53Bas3Repn8BusFrChA_Rte_Pim_BmwRtIdxPrev(void);
BmwSteerMdfnFacSts1 *TSC_BmwMsgSlot53Bas3Repn8BusFrChA_Rte_Pim_BmwSteerMdfnFacStsPrev(void);
uint8 *TSC_BmwMsgSlot53Bas3Repn8BusFrChA_Rte_Pim_FactMoSteSoDxpVldFaild(void);
uint8 *TSC_BmwMsgSlot53Bas3Repn8BusFrChA_Rte_Pim_FactMoSteSoDxpVldPassd(void);
uint8 *TSC_BmwMsgSlot53Bas3Repn8BusFrChA_Rte_Pim_MissMsgFaild(void);
uint8 *TSC_BmwMsgSlot53Bas3Repn8BusFrChA_Rte_Pim_MissMsgPassd(void);
uint8 *TSC_BmwMsgSlot53Bas3Repn8BusFrChA_Rte_Pim_SuCluStmomSfeDxpVldFaild(void);
uint8 *TSC_BmwMsgSlot53Bas3Repn8BusFrChA_Rte_Pim_SuCluStmomSfeDxpVldPassd(void);



