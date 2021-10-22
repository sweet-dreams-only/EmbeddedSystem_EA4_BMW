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
 *          File:  TSC_BmwMsgSlot276Bas4Repn8BusFrChA.h
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
Std_ReturnType TSC_BmwMsgSlot276Bas4Repn8BusFrChA_Rte_Read_FltCodEnad_Logl(boolean *data);
Std_ReturnType TSC_BmwMsgSlot276Bas4Repn8BusFrChA_Rte_Read_MILE_KM_MILE_KM(MILE_KM1 *data);
Std_ReturnType TSC_BmwMsgSlot276Bas4Repn8BusFrChA_Rte_Read_FltCodEnad_Logl(boolean *data);
Std_ReturnType TSC_BmwMsgSlot276Bas4Repn8BusFrChA_Rte_Read_MILE_KM_MILE_KM(MILE_KM1 *data);
Std_ReturnType TSC_BmwMsgSlot276Bas4Repn8BusFrChA_Rte_Read_FltCodEnad_Logl(boolean *data);
Std_ReturnType TSC_BmwMsgSlot276Bas4Repn8BusFrChA_Rte_Read_MILE_KM_MILE_KM(MILE_KM1 *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_BmwMsgSlot276Bas4Repn8BusFrChA_Rte_Write_BmwOdomDst_Val(uint32 data);
Std_ReturnType TSC_BmwMsgSlot276Bas4Repn8BusFrChA_Rte_Write_BmwOdomDstVld_Logl(boolean data);
Std_ReturnType TSC_BmwMsgSlot276Bas4Repn8BusFrChA_Rte_Write_BmwOdomDst_Val(uint32 data);
Std_ReturnType TSC_BmwMsgSlot276Bas4Repn8BusFrChA_Rte_Write_BmwOdomDstVld_Logl(boolean data);
Std_ReturnType TSC_BmwMsgSlot276Bas4Repn8BusFrChA_Rte_Write_BmwOdomDst_Val(uint32 data);
Std_ReturnType TSC_BmwMsgSlot276Bas4Repn8BusFrChA_Rte_Write_BmwOdomDstVld_Logl(boolean data);

/** Client server interfaces */
Std_ReturnType TSC_BmwMsgSlot276Bas4Repn8BusFrChA_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg);
Std_ReturnType TSC_BmwMsgSlot276Bas4Repn8BusFrChA_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg);
Std_ReturnType TSC_BmwMsgSlot276Bas4Repn8BusFrChA_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg);

/** Per Instance Memories */
uint32 *TSC_BmwMsgSlot276Bas4Repn8BusFrChA_Rte_Pim_BmwOdomDstPrev(void);
uint8 *TSC_BmwMsgSlot276Bas4Repn8BusFrChA_Rte_Pim_KiloMtrStandFaildCnt(void);
uint8 *TSC_BmwMsgSlot276Bas4Repn8BusFrChA_Rte_Pim_KiloMtrStandPassdCnt(void);
uint8 *TSC_BmwMsgSlot276Bas4Repn8BusFrChA_Rte_Pim_MissingMsgCnt(void);
uint8 *TSC_BmwMsgSlot276Bas4Repn8BusFrChA_Rte_Pim_RxMsgCnt(void);



