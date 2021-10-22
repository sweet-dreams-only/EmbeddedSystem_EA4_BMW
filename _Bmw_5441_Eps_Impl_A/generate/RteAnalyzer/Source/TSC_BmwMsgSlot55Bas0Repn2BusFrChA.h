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
 *          File:  TSC_BmwMsgSlot55Bas0Repn2BusFrChA.h
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
Std_ReturnType TSC_BmwMsgSlot55Bas0Repn2BusFrChA_Rte_Read_FltCodEnad_Logl(boolean *data);
Std_ReturnType TSC_BmwMsgSlot55Bas0Repn2BusFrChA_Rte_Read_sigGroup_ACLNY_MASSCNTR_sigGroup_ACLNY_MASSCNTR(sigGroup_ACLNY_MASSCNTR1 *data);
Std_ReturnType TSC_BmwMsgSlot55Bas0Repn2BusFrChA_Rte_Read_FltCodEnad_Logl(boolean *data);
Std_ReturnType TSC_BmwMsgSlot55Bas0Repn2BusFrChA_Rte_Read_sigGroup_ACLNY_MASSCNTR_sigGroup_ACLNY_MASSCNTR(sigGroup_ACLNY_MASSCNTR1 *data);
Std_ReturnType TSC_BmwMsgSlot55Bas0Repn2BusFrChA_Rte_Read_FltCodEnad_Logl(boolean *data);
Std_ReturnType TSC_BmwMsgSlot55Bas0Repn2BusFrChA_Rte_Read_sigGroup_ACLNY_MASSCNTR_sigGroup_ACLNY_MASSCNTR(sigGroup_ACLNY_MASSCNTR1 *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_BmwMsgSlot55Bas0Repn2BusFrChA_Rte_Write_BmwVehLatA_Val(float32 data);
Std_ReturnType TSC_BmwMsgSlot55Bas0Repn2BusFrChA_Rte_Write_BmwVehLatAQlfr_Val(BmwVehLatAQlfr1 data);
Std_ReturnType TSC_BmwMsgSlot55Bas0Repn2BusFrChA_Rte_Write_BmwVehLatAQlfrVld_Logl(boolean data);
Std_ReturnType TSC_BmwMsgSlot55Bas0Repn2BusFrChA_Rte_Write_BmwVehLatAVld_Logl(boolean data);
Std_ReturnType TSC_BmwMsgSlot55Bas0Repn2BusFrChA_Rte_Write_BmwVehLatA_Val(float32 data);
Std_ReturnType TSC_BmwMsgSlot55Bas0Repn2BusFrChA_Rte_Write_BmwVehLatAQlfr_Val(BmwVehLatAQlfr1 data);
Std_ReturnType TSC_BmwMsgSlot55Bas0Repn2BusFrChA_Rte_Write_BmwVehLatAQlfrVld_Logl(boolean data);
Std_ReturnType TSC_BmwMsgSlot55Bas0Repn2BusFrChA_Rte_Write_BmwVehLatAVld_Logl(boolean data);
Std_ReturnType TSC_BmwMsgSlot55Bas0Repn2BusFrChA_Rte_Write_BmwVehLatA_Val(float32 data);
Std_ReturnType TSC_BmwMsgSlot55Bas0Repn2BusFrChA_Rte_Write_BmwVehLatAQlfr_Val(BmwVehLatAQlfr1 data);
Std_ReturnType TSC_BmwMsgSlot55Bas0Repn2BusFrChA_Rte_Write_BmwVehLatAQlfrVld_Logl(boolean data);
Std_ReturnType TSC_BmwMsgSlot55Bas0Repn2BusFrChA_Rte_Write_BmwVehLatAVld_Logl(boolean data);

/** Sender receiver - update flag */
boolean TSC_BmwMsgSlot55Bas0Repn2BusFrChA_Rte_IsUpdated_sigGroup_ACLNY_MASSCNTR_sigGroup_ACLNY_MASSCNTR(void);
boolean TSC_BmwMsgSlot55Bas0Repn2BusFrChA_Rte_IsUpdated_sigGroup_ACLNY_MASSCNTR_sigGroup_ACLNY_MASSCNTR(void);
boolean TSC_BmwMsgSlot55Bas0Repn2BusFrChA_Rte_IsUpdated_sigGroup_ACLNY_MASSCNTR_sigGroup_ACLNY_MASSCNTR(void);

/** Client server interfaces */
Std_ReturnType TSC_BmwMsgSlot55Bas0Repn2BusFrChA_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg);
Std_ReturnType TSC_BmwMsgSlot55Bas0Repn2BusFrChA_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg);
Std_ReturnType TSC_BmwMsgSlot55Bas0Repn2BusFrChA_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg);

/** Calibration Component Calibration Parameters */
sint8  TSC_BmwMsgSlot55Bas0Repn2BusFrChA_Rte_Prm_BmwMsgSlot55Bas0Repn2BusFrChABmwLatAPolarity_Val(void);

/** Per Instance Memories */
float32 *TSC_BmwMsgSlot55Bas0Repn2BusFrChA_Rte_Pim_BmwVehLatAPrev(void);
uint8 *TSC_BmwMsgSlot55Bas0Repn2BusFrChA_Rte_Pim_AclnyCogFaildCnt(void);
uint8 *TSC_BmwMsgSlot55Bas0Repn2BusFrChA_Rte_Pim_AclnyCogPassdCnt(void);
uint8 *TSC_BmwMsgSlot55Bas0Repn2BusFrChA_Rte_Pim_AlvFaildCnt(void);
uint8 *TSC_BmwMsgSlot55Bas0Repn2BusFrChA_Rte_Pim_AlvPassdCnt(void);
BmwVehLatAQlfr1 *TSC_BmwMsgSlot55Bas0Repn2BusFrChA_Rte_Pim_BmwVehLatAQlfrPrev(void);
uint8 *TSC_BmwMsgSlot55Bas0Repn2BusFrChA_Rte_Pim_CrcFaildCnt(void);
uint8 *TSC_BmwMsgSlot55Bas0Repn2BusFrChA_Rte_Pim_CrcPassdCnt(void);
uint8 *TSC_BmwMsgSlot55Bas0Repn2BusFrChA_Rte_Pim_MissingMsgCnt(void);
uint8 *TSC_BmwMsgSlot55Bas0Repn2BusFrChA_Rte_Pim_QuAclnyCogFaildCnt(void);
uint8 *TSC_BmwMsgSlot55Bas0Repn2BusFrChA_Rte_Pim_QuAclnyCogPassdCnt(void);
uint8 *TSC_BmwMsgSlot55Bas0Repn2BusFrChA_Rte_Pim_RxdMsgCnt(void);



