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
 *          File:  TSC_BmwMsgSlot121Bas1Repn2BusFrChA.h
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
Std_ReturnType TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Read_FltCodEnad_Logl(boolean *data);
Std_ReturnType TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Read_FltCodEnad_Logl(boolean *data);
Std_ReturnType TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Read_FltCodEnad_Logl(boolean *data);
Std_ReturnType TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Read_sigGroup_CON_VEH_sigGroup_CON_VEH(sigGroup_CON_VEH1 *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Write_BmwBasPtlNetCtrl_Val(BmwBasPtlNetCtrl1 data);
Std_ReturnType TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Write_BmwBasPtlNetCtrlVld_Logl(boolean data);
Std_ReturnType TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Write_BmwVehCdn_Val(BmwVehCdn1 data);
Std_ReturnType TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Write_BmwVehCdnQlfr_Val(BmwVehCdnQlfr1 data);
Std_ReturnType TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Write_BmwVehCdnQlfrVld_Logl(boolean data);
Std_ReturnType TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Write_BmwVehCdnVld_Logl(boolean data);
Std_ReturnType TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Write_BmwBasPtlNetCtrl_Val(BmwBasPtlNetCtrl1 data);
Std_ReturnType TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Write_BmwBasPtlNetCtrlVld_Logl(boolean data);
Std_ReturnType TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Write_BmwVehCdn_Val(BmwVehCdn1 data);
Std_ReturnType TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Write_BmwVehCdnQlfr_Val(BmwVehCdnQlfr1 data);
Std_ReturnType TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Write_BmwVehCdnQlfrVld_Logl(boolean data);
Std_ReturnType TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Write_BmwVehCdnVld_Logl(boolean data);
Std_ReturnType TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Write_BmwBasPtlNetCtrl_Val(BmwBasPtlNetCtrl1 data);
Std_ReturnType TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Write_BmwBasPtlNetCtrlVld_Logl(boolean data);
Std_ReturnType TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Write_BmwVehCdn_Val(BmwVehCdn1 data);
Std_ReturnType TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Write_BmwVehCdnQlfr_Val(BmwVehCdnQlfr1 data);
Std_ReturnType TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Write_BmwVehCdnQlfrVld_Logl(boolean data);
Std_ReturnType TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Write_BmwVehCdnVld_Logl(boolean data);

/** Sender receiver - update flag */
boolean TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_IsUpdated_sigGroup_CON_VEH_sigGroup_CON_VEH(void);

/** Client server interfaces */
Std_ReturnType TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg);
Std_ReturnType TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg);
Std_ReturnType TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg);

/** Per Instance Memories */
uint8 *TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Pim_AlvFaildCnt(void);
uint8 *TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Pim_AlvPassdCnt(void);
BmwBasPtlNetCtrl1 *TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Pim_BmwBasPtlNetCtrlPrev(void);
BmwVehCdn1 *TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Pim_BmwVehCdnPrev(void);
BmwVehCdnQlfr1 *TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Pim_BmwVehCdnQlfrPrev(void);
uint8 *TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Pim_CrcFaildCnt(void);
uint8 *TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Pim_CrcPassdCnt(void);
uint8 *TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Pim_CtrBsPrtntFaildCnt(void);
uint8 *TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Pim_CtrBsPrtntPassdCnt(void);
uint8 *TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Pim_CtrFktnPrtntFaildCnt(void);
uint8 *TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Pim_CtrFktnPrtntPassdCnt(void);
QU_ST_CON_VEH1 *TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Pim_Dummy_PIM1(void);
QU_V_VEH_COG1 *TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Pim_Dummy_PIM2(void);
ST_CON_VEH1 *TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Pim_Dummy_PIM3(void);
CTR_BS_PRTNT1 *TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Pim_Dummy_PIM4(void);
uint8 *TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Pim_MissMsgCnt(void);
uint8 *TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Pim_QlfrCogFaildCnt(void);
uint8 *TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Pim_QlfrCogPassdCnt(void);
uint8 *TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Pim_QuStConVehFaildCnt(void);
uint8 *TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Pim_QuStConVehPassdCnt(void);
uint8 *TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Pim_RxdMsgCnt(void);
uint8 *TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Pim_StConVehFaildCnt(void);
uint8 *TSC_BmwMsgSlot121Bas1Repn2BusFrChA_Rte_Pim_StConVehPassdCnt(void);



