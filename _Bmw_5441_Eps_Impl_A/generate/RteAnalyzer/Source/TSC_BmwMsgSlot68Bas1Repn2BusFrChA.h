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
 *          File:  TSC_BmwMsgSlot68Bas1Repn2BusFrChA.h
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
Std_ReturnType TSC_BmwMsgSlot68Bas1Repn2BusFrChA_Rte_Read_FltCodEnad_Logl(boolean *data);
Std_ReturnType TSC_BmwMsgSlot68Bas1Repn2BusFrChA_Rte_Read_FltCodEnad_Logl(boolean *data);
Std_ReturnType TSC_BmwMsgSlot68Bas1Repn2BusFrChA_Rte_Read_sigGroup_ENERG_DGR_DRDY_sigGroup_ENERG_DGR_DRDY(sigGroup_ENERG_DGR_DRDY1 *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_BmwMsgSlot68Bas1Repn2BusFrChA_Rte_Write_BmwMaxCurrLimr_Val(float32 data);
Std_ReturnType TSC_BmwMsgSlot68Bas1Repn2BusFrChA_Rte_Write_BmwMaxCurrLimrSts_Val(BmwMaxCurrLimrSts1 data);
Std_ReturnType TSC_BmwMsgSlot68Bas1Repn2BusFrChA_Rte_Write_BmwRqrdCurrLimEpsSfty_Val(BmwRqrdCurrLimEpsSfty1 data);
Std_ReturnType TSC_BmwMsgSlot68Bas1Repn2BusFrChA_Rte_Write_BmwRqrdCurrLimEpsSftyVld_Logl(boolean data);
Std_ReturnType TSC_BmwMsgSlot68Bas1Repn2BusFrChA_Rte_Write_BmwMaxCurrLimr_Val(float32 data);
Std_ReturnType TSC_BmwMsgSlot68Bas1Repn2BusFrChA_Rte_Write_BmwMaxCurrLimrSts_Val(BmwMaxCurrLimrSts1 data);
Std_ReturnType TSC_BmwMsgSlot68Bas1Repn2BusFrChA_Rte_Write_BmwRqrdCurrLimEpsSfty_Val(BmwRqrdCurrLimEpsSfty1 data);
Std_ReturnType TSC_BmwMsgSlot68Bas1Repn2BusFrChA_Rte_Write_BmwRqrdCurrLimEpsSftyVld_Logl(boolean data);

/** Sender receiver - update flag */
boolean TSC_BmwMsgSlot68Bas1Repn2BusFrChA_Rte_IsUpdated_sigGroup_ENERG_DGR_DRDY_sigGroup_ENERG_DGR_DRDY(void);

/** Client server interfaces */
Std_ReturnType TSC_BmwMsgSlot68Bas1Repn2BusFrChA_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg);
Std_ReturnType TSC_BmwMsgSlot68Bas1Repn2BusFrChA_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg);
Std_ReturnType TSC_BmwMsgSlot68Bas1Repn2BusFrChA_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg);

/** Per Instance Memories */
float32 *TSC_BmwMsgSlot68Bas1Repn2BusFrChA_Rte_Pim_BmwMaxCurrLimrPrev(void);
uint8 *TSC_BmwMsgSlot68Bas1Repn2BusFrChA_Rte_Pim_AlvFaildCnt(void);
uint8 *TSC_BmwMsgSlot68Bas1Repn2BusFrChA_Rte_Pim_AlvPassdCnt(void);
uint8 *TSC_BmwMsgSlot68Bas1Repn2BusFrChA_Rte_Pim_BmwRqrdCurrLimEpsSftyPrev(void);
uint8 *TSC_BmwMsgSlot68Bas1Repn2BusFrChA_Rte_Pim_CrcFaildCnt(void);
uint8 *TSC_BmwMsgSlot68Bas1Repn2BusFrChA_Rte_Pim_CrcPassdCnt(void);
uint8 *TSC_BmwMsgSlot68Bas1Repn2BusFrChA_Rte_Pim_MaxCurrSpecEPSFaildCnt(void);
uint8 *TSC_BmwMsgSlot68Bas1Repn2BusFrChA_Rte_Pim_MaxCurrSpecEPSPassdCnt(void);
uint8 *TSC_BmwMsgSlot68Bas1Repn2BusFrChA_Rte_Pim_MissingMsgCnt(void);
uint8 *TSC_BmwMsgSlot68Bas1Repn2BusFrChA_Rte_Pim_RqCuliEstSfyFaildCnt(void);
uint8 *TSC_BmwMsgSlot68Bas1Repn2BusFrChA_Rte_Pim_RqCuliEstSfyPassdCnt(void);
uint8 *TSC_BmwMsgSlot68Bas1Repn2BusFrChA_Rte_Pim_RxdMsgCnt(void);



