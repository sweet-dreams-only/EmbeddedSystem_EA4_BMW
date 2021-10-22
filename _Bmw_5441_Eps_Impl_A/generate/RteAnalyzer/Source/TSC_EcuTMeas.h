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
 *          File:  TSC_EcuTMeas.h
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
Std_ReturnType TSC_EcuTMeas_Rte_Read_EcuT_Val(float32 *data);
Std_ReturnType TSC_EcuTMeas_Rte_Read_EcuT_Val(float32 *data);
Std_ReturnType TSC_EcuTMeas_Rte_Read_EcuTAdcFaild_Logl(boolean *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_EcuTMeas_Rte_Write_EcuTFild_Val(float32 data);
Std_ReturnType TSC_EcuTMeas_Rte_Write_DiagcStsLimdTPrfmnc_Logl(boolean data);
Std_ReturnType TSC_EcuTMeas_Rte_Write_EcuTFild_Val(float32 data);

/** Client server interfaces */
Std_ReturnType TSC_EcuTMeas_Rte_Call_CnvSnpshtData_f32_Oper(uint32 *SnpshtDataCnvd_Arg, float32 SnpshtData_Arg);
Std_ReturnType TSC_EcuTMeas_Rte_Call_CnvSnpshtData_logl_Oper(uint32 *SnpshtDataCnvd_Arg, boolean SnpshtData_Arg);
Std_ReturnType TSC_EcuTMeas_Rte_Call_GetNtcActv_Oper(NtcNr1 NtcNr, boolean *NtcActv);
Std_ReturnType TSC_EcuTMeas_Rte_Call_SetNtcStsAndSnpshtData_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg, uint32 SpclSnpshtData0_Arg, uint32 SpclSnpshtData1_Arg, uint32 SpclSnpshtData2_Arg);

/** Per Instance Memories */
float32 *TSC_EcuTMeas_Rte_Pim_dEcuTMeasEcuTCalcd(void);
FilLpRec1 *TSC_EcuTMeas_Rte_Pim_EcuTFilStVari(void);



