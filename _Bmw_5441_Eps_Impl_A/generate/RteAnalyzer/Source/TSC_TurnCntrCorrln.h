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
 *          File:  TSC_TurnCntrCorrln.h
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
Std_ReturnType TSC_TurnCntrCorrln_Rte_Read_MotAgATurnCntr_Val(float32 *data);
Std_ReturnType TSC_TurnCntrCorrln_Rte_Read_MotAgATurnCntrQlfr_Val(SigQlfr1 *data);
Std_ReturnType TSC_TurnCntrCorrln_Rte_Read_MotAgATurnCntrRollgCntr_Val(uint8 *data);
Std_ReturnType TSC_TurnCntrCorrln_Rte_Read_MotAgBTurnCntr_Val(float32 *data);
Std_ReturnType TSC_TurnCntrCorrln_Rte_Read_MotAgBTurnCntrQlfr_Val(SigQlfr1 *data);
Std_ReturnType TSC_TurnCntrCorrln_Rte_Read_MotAgBTurnCntrRollgCntr_Val(uint8 *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_TurnCntrCorrln_Rte_Write_TurnCntrCorrlnSts_Val(uint8 data);
Std_ReturnType TSC_TurnCntrCorrln_Rte_Write_TurnCntrIdptSig_Val(uint8 data);

/** Client server interfaces */
Std_ReturnType TSC_TurnCntrCorrln_Rte_Call_GetNtcQlfrSts_Oper(NtcNr1 NtcNr_Arg, SigQlfr1 *NtcQlfr_Arg);
Std_ReturnType TSC_TurnCntrCorrln_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg);

/** Per Instance Memories */
uint8 *TSC_TurnCntrCorrln_Rte_Pim_MotAgATurnCntrRollgCntPrev(void);
uint8 *TSC_TurnCntrCorrln_Rte_Pim_MotAgATurnCntrStallCntPrev(void);
uint8 *TSC_TurnCntrCorrln_Rte_Pim_MotAgBTurnCntrRollgCntPrev(void);
uint8 *TSC_TurnCntrCorrln_Rte_Pim_MotAgBTurnCntrStallCntPrev(void);



