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
 *          File:  TSC_CDD_HwTq4Meas.h
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
Std_ReturnType TSC_CDD_HwTq4Meas_Rte_Read_HwTq4Polarity_Val(sint8 *data);
Std_ReturnType TSC_CDD_HwTq4Meas_Rte_Read_HwTq4RawAdc_Val(float32 *data);
Std_ReturnType TSC_CDD_HwTq4Meas_Rte_Read_HwTq4RawAdcAdcFaild_Logl(boolean *data);
Std_ReturnType TSC_CDD_HwTq4Meas_Rte_Read_HwTq4RawFastAdcAdcFaild_Logl(boolean *data);
Std_ReturnType TSC_CDD_HwTq4Meas_Rte_Read_HwTq4RawFastAdcBuf_Ary1D(float32 *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_CDD_HwTq4Meas_Rte_Write_HwTq4_Val(float32 data);
Std_ReturnType TSC_CDD_HwTq4Meas_Rte_Write_HwTq4Qlfr_Val(SigQlfr1 data);
Std_ReturnType TSC_CDD_HwTq4Meas_Rte_Write_HwTq4RollgCntr_Val(uint8 data);

/** Client server interfaces */
Std_ReturnType TSC_CDD_HwTq4Meas_Rte_Call_GetNtcQlfrSts_Oper(NtcNr1 NtcNr_Arg, SigQlfr1 *NtcQlfr_Arg);
Std_ReturnType TSC_CDD_HwTq4Meas_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg);
Std_ReturnType TSC_CDD_HwTq4Meas_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg);
Std_ReturnType TSC_CDD_HwTq4Meas_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg);

/** Service interfaces */
Std_ReturnType TSC_CDD_HwTq4Meas_Rte_Call_HwTq4Offs_SetRamBlockStatus(boolean RamBlockStatus_Arg);
Std_ReturnType TSC_CDD_HwTq4Meas_Rte_Call_HwTq4Sca_SetRamBlockStatus(boolean RamBlockStatus_Arg);
Std_ReturnType TSC_CDD_HwTq4Meas_Rte_Call_HwTq4Offs_SetRamBlockStatus(boolean RamBlockStatus_Arg);
Std_ReturnType TSC_CDD_HwTq4Meas_Rte_Call_HwTq4Offs_GetErrorStatus(NvM_RequestResultType *ErrorStatus_Arg);
Std_ReturnType TSC_CDD_HwTq4Meas_Rte_Call_HwTq4Sca_GetErrorStatus(NvM_RequestResultType *ErrorStatus_Arg);
Std_ReturnType TSC_CDD_HwTq4Meas_Rte_Call_HwTq4Sca_SetRamBlockStatus(boolean RamBlockStatus_Arg);
Std_ReturnType TSC_CDD_HwTq4Meas_Rte_Call_HwTq4Offs_SetRamBlockStatus(boolean RamBlockStatus_Arg);

/** Calibration Component Calibration Parameters */
float32  TSC_CDD_HwTq4Meas_Rte_Prm_HwTq4MeasHwTqRngHiLim_Val(void);
float32  TSC_CDD_HwTq4Meas_Rte_Prm_HwTq4MeasHwTqRngLoLim_Val(void);
uint16  TSC_CDD_HwTq4Meas_Rte_Prm_HwTq4MeasHwTq4PrtclFltFailStep_Val(void);
uint16  TSC_CDD_HwTq4Meas_Rte_Prm_HwTq4MeasHwTq4PrtclFltPassStep_Val(void);
boolean  TSC_CDD_HwTq4Meas_Rte_Prm_HwTq4MeasMovgAvrgFilEna_Logl(void);

/** Per Instance Memories */
float32 *TSC_CDD_HwTq4Meas_Rte_Pim_HwTq4PrevHwTq4(void);
uint8 *TSC_CDD_HwTq4Meas_Rte_Pim_HwTq4PrevRollgCntr(void);
uint8 *TSC_CDD_HwTq4Meas_Rte_Pim_HwTq4RawFastAdcIdxCntr(void);
HwTqOffsRec1 *TSC_CDD_HwTq4Meas_Rte_Pim_HwTq4Offs(void);
AnHwTqScaFacRec1 *TSC_CDD_HwTq4Meas_Rte_Pim_HwTq4Sca(void);



