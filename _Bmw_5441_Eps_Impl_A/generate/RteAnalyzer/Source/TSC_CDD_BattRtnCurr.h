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
 *          File:  TSC_CDD_BattRtnCurr.h
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
Std_ReturnType TSC_CDD_BattRtnCurr_Rte_Read_BattRtnCurrAdc_Val(float32 *data);
Std_ReturnType TSC_CDD_BattRtnCurr_Rte_Read_BattRtnCurrAdcFaild_Logl(boolean *data);
Std_ReturnType TSC_CDD_BattRtnCurr_Rte_Read_SplyCurrEstim_Val(float32 *data);
Std_ReturnType TSC_CDD_BattRtnCurr_Rte_Read_SysSt_Val(SysSt1 *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_CDD_BattRtnCurr_Rte_Write_BattRtnCurrAmpr_Val(float32 data);
Std_ReturnType TSC_CDD_BattRtnCurr_Rte_Write_BattRtnCurrStsQlfr_Val(SigQlfr1 data);

/** Client server interfaces */
Std_ReturnType TSC_CDD_BattRtnCurr_Rte_Call_CnvSnpshtData_f32_Oper(uint32 *SnpshtDataCnvd_Arg, float32 SnpshtData_Arg);
Std_ReturnType TSC_CDD_BattRtnCurr_Rte_Call_CnvSnpshtData_u08_Oper(uint32 *SnpshtDataCnvd_Arg, uint8 SnpshtData_Arg);
Std_ReturnType TSC_CDD_BattRtnCurr_Rte_Call_GetNtcQlfrSts_Oper(NtcNr1 NtcNr_Arg, SigQlfr1 *NtcQlfr_Arg);
Std_ReturnType TSC_CDD_BattRtnCurr_Rte_Call_SetNtcStsAndSnpshtData_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg, uint32 SpclSnpshtData0_Arg, uint32 SpclSnpshtData1_Arg, uint32 SpclSnpshtData2_Arg);

/** Per Instance Memories */
float32 *TSC_CDD_BattRtnCurr_Rte_Pim_dBattRtnCurrBfrSatn(void);
FilLpRec1 *TSC_CDD_BattRtnCurr_Rte_Pim_BattCurrEstimDifLpFil(void);



