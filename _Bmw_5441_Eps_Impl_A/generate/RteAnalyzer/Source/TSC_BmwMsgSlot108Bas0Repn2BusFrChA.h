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
 *          File:  TSC_BmwMsgSlot108Bas0Repn2BusFrChA.h
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
Std_ReturnType TSC_BmwMsgSlot108Bas0Repn2BusFrChA_Rte_Read_FltCodEnad_Logl(boolean *data);
Std_ReturnType TSC_BmwMsgSlot108Bas0Repn2BusFrChA_Rte_Read_AVL_STEA_PNI_OFFS_AVL_STEA_PNI_OFFS(AVL_STEA_PNI_OFFS1 *data);
Std_ReturnType TSC_BmwMsgSlot108Bas0Repn2BusFrChA_Rte_Read_FltCodEnad_Logl(boolean *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_BmwMsgSlot108Bas0Repn2BusFrChA_Rte_Write_BmwPinionAgOffs_Val(float32 data);
Std_ReturnType TSC_BmwMsgSlot108Bas0Repn2BusFrChA_Rte_Write_BmwPinionAgOffsSts_Val(BmwPinionAgOffsSts1 data);
Std_ReturnType TSC_BmwMsgSlot108Bas0Repn2BusFrChA_Rte_Write_BmwPinionAgOffs_Val(float32 data);
Std_ReturnType TSC_BmwMsgSlot108Bas0Repn2BusFrChA_Rte_Write_BmwPinionAgOffsSts_Val(BmwPinionAgOffsSts1 data);

/** Sender receiver - update flag */
boolean TSC_BmwMsgSlot108Bas0Repn2BusFrChA_Rte_IsUpdated_AVL_STEA_PNI_OFFS_AVL_STEA_PNI_OFFS(void);

/** Client server interfaces */
Std_ReturnType TSC_BmwMsgSlot108Bas0Repn2BusFrChA_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg);
Std_ReturnType TSC_BmwMsgSlot108Bas0Repn2BusFrChA_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg);
Std_ReturnType TSC_BmwMsgSlot108Bas0Repn2BusFrChA_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg);

/** Calibration Component Calibration Parameters */
sint8  TSC_BmwMsgSlot108Bas0Repn2BusFrChA_Rte_Prm_BmwMsgSlot108Bas0Repn2BusFrChABmwSteerPolarity_Val(void);

/** Per Instance Memories */
float32 *TSC_BmwMsgSlot108Bas0Repn2BusFrChA_Rte_Pim_BmwPinionAgOffsPrev(void);
uint8 *TSC_BmwMsgSlot108Bas0Repn2BusFrChA_Rte_Pim_AvlSteaPniOffsFaildCnt(void);
uint8 *TSC_BmwMsgSlot108Bas0Repn2BusFrChA_Rte_Pim_AvlSteaPniOffsPassdCnt(void);
uint8 *TSC_BmwMsgSlot108Bas0Repn2BusFrChA_Rte_Pim_MissingMsgCnt(void);
uint8 *TSC_BmwMsgSlot108Bas0Repn2BusFrChA_Rte_Pim_RxMsgCnt(void);



