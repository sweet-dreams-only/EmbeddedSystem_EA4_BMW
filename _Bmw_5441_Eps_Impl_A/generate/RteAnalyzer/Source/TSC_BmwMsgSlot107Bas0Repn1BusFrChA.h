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
 *          File:  TSC_BmwMsgSlot107Bas0Repn1BusFrChA.h
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
Std_ReturnType TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_Read_FltCodEnad_Logl(boolean *data);
Std_ReturnType TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_Read_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS(sigGroup_OFFS_QUAD_EPS1 *data);
Std_ReturnType TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_Read_FltCodEnad_Logl(boolean *data);
Std_ReturnType TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_Read_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS(sigGroup_OFFS_QUAD_EPS1 *data);
Std_ReturnType TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_Read_FltCodEnad_Logl(boolean *data);
Std_ReturnType TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_Read_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS(sigGroup_OFFS_QUAD_EPS1 *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_Write_BmwActIntgtdCtrlModlPosnIdxValVld_Logl(boolean data);
Std_ReturnType TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_Write_BmwQuadOffsSts_Val(BmwQuadOffsSts1 data);
Std_ReturnType TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_Write_BmwQuadOffsStsVld_Logl(boolean data);
Std_ReturnType TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_Write_BmwQuadRtrOffsVld_Logl(boolean data);
Std_ReturnType TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_Write_BmwActIntgtdCtrlModlPosnIdxVal_Val(float32 data);
Std_ReturnType TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_Write_BmwActIntgtdCtrlModlPosnIdxValVld_Logl(boolean data);
Std_ReturnType TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_Write_BmwQuadOffsSts_Val(BmwQuadOffsSts1 data);
Std_ReturnType TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_Write_BmwQuadOffsStsVld_Logl(boolean data);
Std_ReturnType TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_Write_BmwQuadRtrOffs_Val(sint8 data);
Std_ReturnType TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_Write_BmwQuadRtrOffsVld_Logl(boolean data);
Std_ReturnType TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_Write_BmwActIntgtdCtrlModlPosnIdxVal_Val(float32 data);
Std_ReturnType TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_Write_BmwActIntgtdCtrlModlPosnIdxValVld_Logl(boolean data);
Std_ReturnType TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_Write_BmwQuadOffsSts_Val(BmwQuadOffsSts1 data);
Std_ReturnType TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_Write_BmwQuadOffsStsVld_Logl(boolean data);
Std_ReturnType TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_Write_BmwQuadRtrOffs_Val(sint8 data);
Std_ReturnType TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_Write_BmwQuadRtrOffsVld_Logl(boolean data);

/** Sender receiver - update flag */
boolean TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_IsUpdated_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS(void);
boolean TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_IsUpdated_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS(void);
boolean TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_IsUpdated_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS(void);

/** Client server interfaces */
Std_ReturnType TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg);
Std_ReturnType TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg);
Std_ReturnType TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg);

/** Calibration Component Calibration Parameters */
sint8  TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_Prm_BmwMsgSlot108Bas0Repn2BusFrChABmwSteerPolarity_Val(void);

/** Per Instance Memories */
float32 *TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_Pim_BmwActIntgtdCtrlModlPosnIdxValPrev(void);
AVL_PO_IDX_ICM1 *TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_Pim_Dummy_PIM1(void);
uint8 *TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_Pim_AlvFaildCnt(void);
uint8 *TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_Pim_AlvPassdCnt(void);
uint8 *TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_Pim_AvlPoIdxIcmFaildCnt(void);
uint8 *TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_Pim_AvlPoIdxIcmPassdCnt(void);
BmwQuadOffsSts1 *TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_Pim_BmwQuadOffsStsPrev(void);
uint8 *TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_Pim_CrcFaildCnt(void);
uint8 *TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_Pim_CrcPassdCnt(void);
ST_OFFS_QUAD_EPS1 *TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_Pim_Dummy_PIM2(void);
OFFS_QUAD_RTR_EPS1 *TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_Pim_Dummy_PIM3(void);
uint8 *TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_Pim_MissMsgCnt(void);
uint8 *TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_Pim_OffsQuadRtrEpsFaildCnt(void);
uint8 *TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_Pim_OffsQuadRtrEpsPassdCnt(void);
uint8 *TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_Pim_RxdMsgCnt(void);
uint8 *TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_Pim_StOffsQuadEpsFaildCnt(void);
uint8 *TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_Pim_StOffsQuadEpsPassdCnt(void);
sint8 *TSC_BmwMsgSlot107Bas0Repn1BusFrChA_Rte_Pim_BmwQuadRtrOffsPrev(void);



