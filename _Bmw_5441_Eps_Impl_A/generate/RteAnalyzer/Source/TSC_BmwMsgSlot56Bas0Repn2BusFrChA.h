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
 *          File:  TSC_BmwMsgSlot56Bas0Repn2BusFrChA.h
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
Std_ReturnType TSC_BmwMsgSlot56Bas0Repn2BusFrChA_Rte_Read_FltCodEnad_Logl(boolean *data);
Std_ReturnType TSC_BmwMsgSlot56Bas0Repn2BusFrChA_Rte_Read_sigGroup_VYAW_VEH_sigGroup_VYAW_VEH(sigGroup_VYAW_VEH1 *data);
Std_ReturnType TSC_BmwMsgSlot56Bas0Repn2BusFrChA_Rte_Read_FltCodEnad_Logl(boolean *data);
Std_ReturnType TSC_BmwMsgSlot56Bas0Repn2BusFrChA_Rte_Read_sigGroup_VYAW_VEH_sigGroup_VYAW_VEH(sigGroup_VYAW_VEH1 *data);
Std_ReturnType TSC_BmwMsgSlot56Bas0Repn2BusFrChA_Rte_Read_FltCodEnad_Logl(boolean *data);
Std_ReturnType TSC_BmwMsgSlot56Bas0Repn2BusFrChA_Rte_Read_sigGroup_VYAW_VEH_sigGroup_VYAW_VEH(sigGroup_VYAW_VEH1 *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_BmwMsgSlot56Bas0Repn2BusFrChA_Rte_Write_BmwVehYawQlfr_Val(BmwVehYawQlfr1 data);
Std_ReturnType TSC_BmwMsgSlot56Bas0Repn2BusFrChA_Rte_Write_BmwVehYawQlfrVld_Logl(boolean data);
Std_ReturnType TSC_BmwMsgSlot56Bas0Repn2BusFrChA_Rte_Write_BmwVehYawRate_Val(float32 data);
Std_ReturnType TSC_BmwMsgSlot56Bas0Repn2BusFrChA_Rte_Write_BmwVehYawRateVld_Logl(boolean data);
Std_ReturnType TSC_BmwMsgSlot56Bas0Repn2BusFrChA_Rte_Write_BmwVehYawQlfr_Val(BmwVehYawQlfr1 data);
Std_ReturnType TSC_BmwMsgSlot56Bas0Repn2BusFrChA_Rte_Write_BmwVehYawQlfrVld_Logl(boolean data);
Std_ReturnType TSC_BmwMsgSlot56Bas0Repn2BusFrChA_Rte_Write_BmwVehYawRate_Val(float32 data);
Std_ReturnType TSC_BmwMsgSlot56Bas0Repn2BusFrChA_Rte_Write_BmwVehYawRateVld_Logl(boolean data);
Std_ReturnType TSC_BmwMsgSlot56Bas0Repn2BusFrChA_Rte_Write_BmwVehYawQlfr_Val(BmwVehYawQlfr1 data);
Std_ReturnType TSC_BmwMsgSlot56Bas0Repn2BusFrChA_Rte_Write_BmwVehYawQlfrVld_Logl(boolean data);
Std_ReturnType TSC_BmwMsgSlot56Bas0Repn2BusFrChA_Rte_Write_BmwVehYawRate_Val(float32 data);
Std_ReturnType TSC_BmwMsgSlot56Bas0Repn2BusFrChA_Rte_Write_BmwVehYawRateVld_Logl(boolean data);

/** Sender receiver - update flag */
boolean TSC_BmwMsgSlot56Bas0Repn2BusFrChA_Rte_IsUpdated_sigGroup_VYAW_VEH_sigGroup_VYAW_VEH(void);
boolean TSC_BmwMsgSlot56Bas0Repn2BusFrChA_Rte_IsUpdated_sigGroup_VYAW_VEH_sigGroup_VYAW_VEH(void);
boolean TSC_BmwMsgSlot56Bas0Repn2BusFrChA_Rte_IsUpdated_sigGroup_VYAW_VEH_sigGroup_VYAW_VEH(void);

/** Client server interfaces */
Std_ReturnType TSC_BmwMsgSlot56Bas0Repn2BusFrChA_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg);
Std_ReturnType TSC_BmwMsgSlot56Bas0Repn2BusFrChA_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg);
Std_ReturnType TSC_BmwMsgSlot56Bas0Repn2BusFrChA_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg);

/** Per Instance Memories */
float32 *TSC_BmwMsgSlot56Bas0Repn2BusFrChA_Rte_Pim_BmwVehYawRatePrev(void);
uint8 *TSC_BmwMsgSlot56Bas0Repn2BusFrChA_Rte_Pim_AlvFaildCnt(void);
uint8 *TSC_BmwMsgSlot56Bas0Repn2BusFrChA_Rte_Pim_AlvPassdCnt(void);
BmwVehYawQlfr1 *TSC_BmwMsgSlot56Bas0Repn2BusFrChA_Rte_Pim_BmwVehYawQlfrPrev(void);
uint8 *TSC_BmwMsgSlot56Bas0Repn2BusFrChA_Rte_Pim_CrcFaildCnt(void);
uint8 *TSC_BmwMsgSlot56Bas0Repn2BusFrChA_Rte_Pim_CrcPassdCnt(void);
uint8 *TSC_BmwMsgSlot56Bas0Repn2BusFrChA_Rte_Pim_MissingMsgCnt(void);
uint8 *TSC_BmwMsgSlot56Bas0Repn2BusFrChA_Rte_Pim_QuVyawVehFaildCnt(void);
uint8 *TSC_BmwMsgSlot56Bas0Repn2BusFrChA_Rte_Pim_QuVyawVehPassdCnt(void);
uint8 *TSC_BmwMsgSlot56Bas0Repn2BusFrChA_Rte_Pim_RxdMsgCnt(void);
uint8 *TSC_BmwMsgSlot56Bas0Repn2BusFrChA_Rte_Pim_VyawVehFaildCnt(void);
uint8 *TSC_BmwMsgSlot56Bas0Repn2BusFrChA_Rte_Pim_VyawVehPassdCnt(void);



