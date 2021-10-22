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
 *          File:  TSC_BmwMsgSlot55Bas3Repn4BusFrChA.h
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
Std_ReturnType TSC_BmwMsgSlot55Bas3Repn4BusFrChA_Rte_Read_FltCodEnad_Logl(boolean *data);
Std_ReturnType TSC_BmwMsgSlot55Bas3Repn4BusFrChA_Rte_Read_FltCodEnad_Logl(boolean *data);
Std_ReturnType TSC_BmwMsgSlot55Bas3Repn4BusFrChA_Rte_Read_sigGroup_V_VEH_sigGroup_V_VEH(sigGroup_V_VEH1 *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_BmwMsgSlot55Bas3Repn4BusFrChA_Rte_Write_BmwCogVehSpd_Val(float32 data);
Std_ReturnType TSC_BmwMsgSlot55Bas3Repn4BusFrChA_Rte_Write_BmwCogVehSpdQlfr_Val(BmwCogVehSpdQlfr1 data);
Std_ReturnType TSC_BmwMsgSlot55Bas3Repn4BusFrChA_Rte_Write_BmwCogVehSpdQlfrVld_Logl(boolean data);
Std_ReturnType TSC_BmwMsgSlot55Bas3Repn4BusFrChA_Rte_Write_BmwCogVehSpdVld_Logl(boolean data);
Std_ReturnType TSC_BmwMsgSlot55Bas3Repn4BusFrChA_Rte_Write_BmwNearStillVehSpdSts_Val(BmwNearStillVehSpdSts1 data);
Std_ReturnType TSC_BmwMsgSlot55Bas3Repn4BusFrChA_Rte_Write_BmwNearStillVehSpdStsVld_Logl(boolean data);
Std_ReturnType TSC_BmwMsgSlot55Bas3Repn4BusFrChA_Rte_Write_BmwCogVehSpd_Val(float32 data);
Std_ReturnType TSC_BmwMsgSlot55Bas3Repn4BusFrChA_Rte_Write_BmwCogVehSpdQlfr_Val(BmwCogVehSpdQlfr1 data);
Std_ReturnType TSC_BmwMsgSlot55Bas3Repn4BusFrChA_Rte_Write_BmwCogVehSpdQlfrVld_Logl(boolean data);
Std_ReturnType TSC_BmwMsgSlot55Bas3Repn4BusFrChA_Rte_Write_BmwCogVehSpdVld_Logl(boolean data);
Std_ReturnType TSC_BmwMsgSlot55Bas3Repn4BusFrChA_Rte_Write_BmwNearStillVehSpdSts_Val(BmwNearStillVehSpdSts1 data);
Std_ReturnType TSC_BmwMsgSlot55Bas3Repn4BusFrChA_Rte_Write_BmwNearStillVehSpdStsVld_Logl(boolean data);

/** Sender receiver - update flag */
boolean TSC_BmwMsgSlot55Bas3Repn4BusFrChA_Rte_IsUpdated_sigGroup_V_VEH_sigGroup_V_VEH(void);

/** Client server interfaces */
Std_ReturnType TSC_BmwMsgSlot55Bas3Repn4BusFrChA_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg);
Std_ReturnType TSC_BmwMsgSlot55Bas3Repn4BusFrChA_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg);

/** Per Instance Memories */
float32 *TSC_BmwMsgSlot55Bas3Repn4BusFrChA_Rte_Pim_BmwCogVehSpdPrev(void);
uint8 *TSC_BmwMsgSlot55Bas3Repn4BusFrChA_Rte_Pim_AlvFaildCnt(void);
uint8 *TSC_BmwMsgSlot55Bas3Repn4BusFrChA_Rte_Pim_AlvPassdCnt(void);
BmwCogVehSpdQlfr1 *TSC_BmwMsgSlot55Bas3Repn4BusFrChA_Rte_Pim_BmwCogVehSpdQlfrPrev(void);
BmwNearStillVehSpdSts1 *TSC_BmwMsgSlot55Bas3Repn4BusFrChA_Rte_Pim_BmwNearStillVehSpdStsPrev(void);
uint8 *TSC_BmwMsgSlot55Bas3Repn4BusFrChA_Rte_Pim_CrcFaildCnt(void);
uint8 *TSC_BmwMsgSlot55Bas3Repn4BusFrChA_Rte_Pim_CrcPassdCnt(void);
QU_V_VEH_COG1 *TSC_BmwMsgSlot55Bas3Repn4BusFrChA_Rte_Pim_Dummy_PIM1(void);
ST_V_VEH_NSS1 *TSC_BmwMsgSlot55Bas3Repn4BusFrChA_Rte_Pim_Dummy_PIM2(void);
uint8 *TSC_BmwMsgSlot55Bas3Repn4BusFrChA_Rte_Pim_MissMsgCnt(void);
uint8 *TSC_BmwMsgSlot55Bas3Repn4BusFrChA_Rte_Pim_QlfrCogFaildCnt(void);
uint8 *TSC_BmwMsgSlot55Bas3Repn4BusFrChA_Rte_Pim_QlfrCogPassdCnt(void);
uint8 *TSC_BmwMsgSlot55Bas3Repn4BusFrChA_Rte_Pim_RxdMsgCnt(void);
uint8 *TSC_BmwMsgSlot55Bas3Repn4BusFrChA_Rte_Pim_StVehNearStillFailCnt(void);
uint8 *TSC_BmwMsgSlot55Bas3Repn4BusFrChA_Rte_Pim_StVehNearStillPassCnt(void);
uint8 *TSC_BmwMsgSlot55Bas3Repn4BusFrChA_Rte_Pim_VehCogFaildCnt(void);
uint8 *TSC_BmwMsgSlot55Bas3Repn4BusFrChA_Rte_Pim_VehCogPassdCnt(void);



