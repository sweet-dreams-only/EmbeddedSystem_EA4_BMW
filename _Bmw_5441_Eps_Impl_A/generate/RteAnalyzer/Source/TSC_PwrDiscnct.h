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
 *          File:  TSC_PwrDiscnct.h
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
Std_ReturnType TSC_PwrDiscnct_Rte_Read_BattVltg_Val(float32 *data);
Std_ReturnType TSC_PwrDiscnct_Rte_Read_BattVltgSwd1_Val(float32 *data);
Std_ReturnType TSC_PwrDiscnct_Rte_Read_StrtUpSt_Val(uint8 *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_PwrDiscnct_Rte_Write_PwrDiscnctATestCmpl_Logl(boolean data);
Std_ReturnType TSC_PwrDiscnct_Rte_Write_PwrDiscnctBTestCmpl_Logl(boolean data);

/** Client server interfaces */
Std_ReturnType TSC_PwrDiscnct_Rte_Call_GetNtcQlfrSts_Oper(NtcNr1 NtcNr_Arg, SigQlfr1 *NtcQlfr_Arg);
Std_ReturnType TSC_PwrDiscnct_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg);

/** Calibration Component Calibration Parameters */
float32  TSC_PwrDiscnct_Rte_Prm_BattVltgSwdMax_Val(void);

/** Per Instance Memories */
boolean *TSC_PwrDiscnct_Rte_Pim_PwrDiscnctATestCmplPrev(void);



