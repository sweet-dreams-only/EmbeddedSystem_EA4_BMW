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
 *          File:  TSC_CDD_HwTq5Meas.h
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
Std_ReturnType TSC_CDD_HwTq5Meas_Rte_Read_HwTq5Polarity_Val(sint8 *data);
Std_ReturnType TSC_CDD_HwTq5Meas_Rte_Read_HwTq5RawAdc_Val(float32 *data);
Std_ReturnType TSC_CDD_HwTq5Meas_Rte_Read_HwTq5RawAdcAdcFaild_Logl(boolean *data);
Std_ReturnType TSC_CDD_HwTq5Meas_Rte_Read_HwTq5RawFastAdcAdcFaild_Logl(boolean *data);
Std_ReturnType TSC_CDD_HwTq5Meas_Rte_Read_HwTq5RawFastAdcBuf_Ary1D(float32 *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_CDD_HwTq5Meas_Rte_Write_HwTq5_Val(float32 data);
Std_ReturnType TSC_CDD_HwTq5Meas_Rte_Write_HwTq5Qlfr_Val(SigQlfr1 data);
Std_ReturnType TSC_CDD_HwTq5Meas_Rte_Write_HwTq5RollgCntr_Val(uint8 data);

/** Client server interfaces */
Std_ReturnType TSC_CDD_HwTq5Meas_Rte_Call_GetNtcQlfrSts_Oper(NtcNr1 NtcNr_Arg, SigQlfr1 *NtcQlfr_Arg);
Std_ReturnType TSC_CDD_HwTq5Meas_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg);
Std_ReturnType TSC_CDD_HwTq5Meas_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg);
Std_ReturnType TSC_CDD_HwTq5Meas_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg);

/** Service interfaces */
Std_ReturnType TSC_CDD_HwTq5Meas_Rte_Call_HwTq5Offs_SetRamBlockStatus(boolean RamBlockStatus_Arg);
Std_ReturnType TSC_CDD_HwTq5Meas_Rte_Call_HwTq5Sca_SetRamBlockStatus(boolean RamBlockStatus_Arg);
Std_ReturnType TSC_CDD_HwTq5Meas_Rte_Call_HwTq5Offs_SetRamBlockStatus(boolean RamBlockStatus_Arg);
Std_ReturnType TSC_CDD_HwTq5Meas_Rte_Call_HwTq5Offs_GetErrorStatus(NvM_RequestResultType *ErrorStatus_Arg);
Std_ReturnType TSC_CDD_HwTq5Meas_Rte_Call_HwTq5Sca_GetErrorStatus(NvM_RequestResultType *ErrorStatus_Arg);
Std_ReturnType TSC_CDD_HwTq5Meas_Rte_Call_HwTq5Sca_SetRamBlockStatus(boolean RamBlockStatus_Arg);
Std_ReturnType TSC_CDD_HwTq5Meas_Rte_Call_HwTq5Offs_SetRamBlockStatus(boolean RamBlockStatus_Arg);

/** Calibration Component Calibration Parameters */
float32  TSC_CDD_HwTq5Meas_Rte_Prm_HwTq5MeasHwTqRngHiLim_Val(void);
float32  TSC_CDD_HwTq5Meas_Rte_Prm_HwTq5MeasHwTqRngLoLim_Val(void);
uint16  TSC_CDD_HwTq5Meas_Rte_Prm_HwTq5MeasHwTq5PrtclFltFailStep_Val(void);
uint16  TSC_CDD_HwTq5Meas_Rte_Prm_HwTq5MeasHwTq5PrtclFltPassStep_Val(void);
boolean  TSC_CDD_HwTq5Meas_Rte_Prm_HwTq5MeasMovgAvrgFilEna_Logl(void);

/** Per Instance Memories */
float32 *TSC_CDD_HwTq5Meas_Rte_Pim_HwTq5PrevHwTq5(void);
uint8 *TSC_CDD_HwTq5Meas_Rte_Pim_HwTq5PrevRollgCntr(void);
uint8 *TSC_CDD_HwTq5Meas_Rte_Pim_HwTq5RawFastAdcIdxCntr(void);
HwTqOffsRec1 *TSC_CDD_HwTq5Meas_Rte_Pim_HwTq5Offs(void);
AnHwTqScaFacRec1 *TSC_CDD_HwTq5Meas_Rte_Pim_HwTq5Sca(void);



