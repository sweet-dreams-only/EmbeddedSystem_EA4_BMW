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
 *          File:  TSC_BmwMsgSlot269Bas2Repn4BusFrChA.h
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
Std_ReturnType TSC_BmwMsgSlot269Bas2Repn4BusFrChA_Rte_Read_FltCodEnad_Logl(boolean *data);
Std_ReturnType TSC_BmwMsgSlot269Bas2Repn4BusFrChA_Rte_Read_CTR_WARN_DIR_VIB_EPS_CTR_WARN_DIR_VIB_EPS(CTR_WARN_DIR_VIB_EPS1 *data);
Std_ReturnType TSC_BmwMsgSlot269Bas2Repn4BusFrChA_Rte_Read_CTR_WARN_ILVL_VIB_EPS_CTR_WARN_ILVL_VIB_EPS(CTR_WARN_ILVL_VIB_EPS1 *data);
Std_ReturnType TSC_BmwMsgSlot269Bas2Repn4BusFrChA_Rte_Read_CTR_WARN_PTRN_VIB_EPS_CTR_WARN_PTRN_VIB_EPS(CTR_WARN_PTRN_VIB_EPS1 *data);
Std_ReturnType TSC_BmwMsgSlot269Bas2Repn4BusFrChA_Rte_Read_FltCodEnad_Logl(boolean *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_BmwMsgSlot269Bas2Repn4BusFrChA_Rte_Write_BmwHaptcFbDirNr_Val(BmwHaptcFbDirNr1 data);
Std_ReturnType TSC_BmwMsgSlot269Bas2Repn4BusFrChA_Rte_Write_BmwHaptcFbDirNrVld_Logl(boolean data);
Std_ReturnType TSC_BmwMsgSlot269Bas2Repn4BusFrChA_Rte_Write_BmwHaptcFbIntenNr_Val(BmwHaptcFbIntenNr1 data);
Std_ReturnType TSC_BmwMsgSlot269Bas2Repn4BusFrChA_Rte_Write_BmwHaptcFbIntenNrVld_Logl(boolean data);
Std_ReturnType TSC_BmwMsgSlot269Bas2Repn4BusFrChA_Rte_Write_BmwHaptcFbPatNr_Val(BmwHaptcFbPatNr1 data);
Std_ReturnType TSC_BmwMsgSlot269Bas2Repn4BusFrChA_Rte_Write_BmwHaptcFbPatNrVld_Logl(boolean data);
Std_ReturnType TSC_BmwMsgSlot269Bas2Repn4BusFrChA_Rte_Write_BmwHaptcFbDirNr_Val(BmwHaptcFbDirNr1 data);
Std_ReturnType TSC_BmwMsgSlot269Bas2Repn4BusFrChA_Rte_Write_BmwHaptcFbDirNrVld_Logl(boolean data);
Std_ReturnType TSC_BmwMsgSlot269Bas2Repn4BusFrChA_Rte_Write_BmwHaptcFbIntenNr_Val(BmwHaptcFbIntenNr1 data);
Std_ReturnType TSC_BmwMsgSlot269Bas2Repn4BusFrChA_Rte_Write_BmwHaptcFbIntenNrVld_Logl(boolean data);
Std_ReturnType TSC_BmwMsgSlot269Bas2Repn4BusFrChA_Rte_Write_BmwHaptcFbPatNr_Val(BmwHaptcFbPatNr1 data);
Std_ReturnType TSC_BmwMsgSlot269Bas2Repn4BusFrChA_Rte_Write_BmwHaptcFbPatNrVld_Logl(boolean data);

/** Client server interfaces */
Std_ReturnType TSC_BmwMsgSlot269Bas2Repn4BusFrChA_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg);
Std_ReturnType TSC_BmwMsgSlot269Bas2Repn4BusFrChA_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg);
Std_ReturnType TSC_BmwMsgSlot269Bas2Repn4BusFrChA_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg);

/** Per Instance Memories */
BmwHaptcFbDirNr1 *TSC_BmwMsgSlot269Bas2Repn4BusFrChA_Rte_Pim_BmwHaptcFbDirNrPrev(void);
BmwHaptcFbIntenNr1 *TSC_BmwMsgSlot269Bas2Repn4BusFrChA_Rte_Pim_BmwHaptcFbIntenNrPrev(void);
BmwHaptcFbPatNr1 *TSC_BmwMsgSlot269Bas2Repn4BusFrChA_Rte_Pim_BmwHaptcFbPatNrPrev(void);
uint8 *TSC_BmwMsgSlot269Bas2Repn4BusFrChA_Rte_Pim_CtrVibStwDispExmiSp2015MissFaild(void);
uint8 *TSC_BmwMsgSlot269Bas2Repn4BusFrChA_Rte_Pim_CtrVibStwDispExmiSp2015MissPassd(void);
uint8 *TSC_BmwMsgSlot269Bas2Repn4BusFrChA_Rte_Pim_CtrWarnDirVibEpsVldFaild(void);
uint8 *TSC_BmwMsgSlot269Bas2Repn4BusFrChA_Rte_Pim_CtrWarnDirVibEpsVldPassd(void);
uint8 *TSC_BmwMsgSlot269Bas2Repn4BusFrChA_Rte_Pim_CtrWarnIlvlVibEpsVldFaild(void);
uint8 *TSC_BmwMsgSlot269Bas2Repn4BusFrChA_Rte_Pim_CtrWarnIlvlVibEpsVldPassd(void);
uint8 *TSC_BmwMsgSlot269Bas2Repn4BusFrChA_Rte_Pim_CtrWarnPtrnVibEpsVldFaild(void);
uint8 *TSC_BmwMsgSlot269Bas2Repn4BusFrChA_Rte_Pim_CtrWarnPtrnVibEpsVldPassd(void);



