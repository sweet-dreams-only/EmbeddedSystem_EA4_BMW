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
 *          File:  TSC_BattVltgCorrln.h
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
Std_ReturnType TSC_BattVltgCorrln_Rte_Read_BattVltg_Val(float32 *data);
Std_ReturnType TSC_BattVltgCorrln_Rte_Read_BattVltgAdcFaild_Logl(boolean *data);
Std_ReturnType TSC_BattVltgCorrln_Rte_Read_BattVltgSwd1_Val(float32 *data);
Std_ReturnType TSC_BattVltgCorrln_Rte_Read_BattVltgSwd1AdcFaild_Logl(boolean *data);
Std_ReturnType TSC_BattVltgCorrln_Rte_Read_DiagcStsIvtr1Inactv_Logl(boolean *data);
Std_ReturnType TSC_BattVltgCorrln_Rte_Read_InhbBattVltgDiagc_Logl(boolean *data);
Std_ReturnType TSC_BattVltgCorrln_Rte_Read_StrtUpSt_Val(uint8 *data);
Std_ReturnType TSC_BattVltgCorrln_Rte_Read_SysSt_Val(SysSt1 *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_BattVltgCorrln_Rte_Write_BattSwdVltgCorrlnSts_Val(uint8 data);
Std_ReturnType TSC_BattVltgCorrln_Rte_Write_BattVltgCorrlnIdptSig_Val(uint8 data);
Std_ReturnType TSC_BattVltgCorrln_Rte_Write_DftBrdgVltgActv_Logl(boolean data);
Std_ReturnType TSC_BattVltgCorrln_Rte_Write_SwdVltgLimd_Logl(boolean data);

/** Client server interfaces */
Std_ReturnType TSC_BattVltgCorrln_Rte_Call_GetNtcQlfrSts_Oper(NtcNr1 NtcNr_Arg, SigQlfr1 *NtcQlfr_Arg);
Std_ReturnType TSC_BattVltgCorrln_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg);

/** Calibration Component Calibration Parameters */
float32  TSC_BattVltgCorrln_Rte_Prm_BattVltgCorrlnAllwdVltgDif_Val(void);
float32  TSC_BattVltgCorrln_Rte_Prm_BattVltgCorrlnBattLoVltg_Val(void);
float32  TSC_BattVltgCorrln_Rte_Prm_BattVltgCorrlnBattOverVltg_Val(void);
float32  TSC_BattVltgCorrln_Rte_Prm_BattVltgCorrlnBattUnderVltg_Val(void);
float32  TSC_BattVltgCorrln_Rte_Prm_BattVltgCorrlnRcvrlBattLoVltg_Val(void);
float32  TSC_BattVltgCorrln_Rte_Prm_BattVltgCorrlnRcvrlBattOverVltg_Val(void);
float32  TSC_BattVltgCorrln_Rte_Prm_BattVltgCorrlnRcvrlBattUnderVltg_Val(void);
float32  TSC_BattVltgCorrln_Rte_Prm_BattVltgCorrlnSwdMax_Val(void);
float32  TSC_BattVltgCorrln_Rte_Prm_BattVltgCorrlnSysMinVltg_Val(void);
uint16  TSC_BattVltgCorrln_Rte_Prm_BattVltgCorrlnNtc0x03C0x044FailStep_Val(void);
uint16  TSC_BattVltgCorrln_Rte_Prm_BattVltgCorrlnNtc0x03C0x044PassStep_Val(void);
uint16  TSC_BattVltgCorrln_Rte_Prm_BattVltgCorrlnNtc0x0B0FailStep_Val(void);
uint16  TSC_BattVltgCorrln_Rte_Prm_BattVltgCorrlnNtc0x0B0PassStep_Val(void);
uint16  TSC_BattVltgCorrln_Rte_Prm_BattVltgCorrlnNtc0x0B1FailStep_Val(void);
uint16  TSC_BattVltgCorrln_Rte_Prm_BattVltgCorrlnNtc0x0B1PassStep_Val(void);
uint16  TSC_BattVltgCorrln_Rte_Prm_BattVltgCorrlnNtc0x0B5FailStep_Val(void);
uint16  TSC_BattVltgCorrln_Rte_Prm_BattVltgCorrlnNtc0x0B5PassStep_Val(void);

/** Per Instance Memories */
uint8 *TSC_BattVltgCorrln_Rte_Pim_dBattVltgCorrlnBattVltgRngOk(void);
uint8 *TSC_BattVltgCorrln_Rte_Pim_dBattVltgCorrlnBattVltgSwd1RngOk(void);
SigQlfr1 *TSC_BattVltgCorrln_Rte_Pim_dBattVltgCorrlnNtc0x03CQlfrSts(void);
SigQlfr1 *TSC_BattVltgCorrln_Rte_Pim_dBattVltgCorrlnNtc0x044QlfrSts(void);
boolean *TSC_BattVltgCorrln_Rte_Pim_dBattVltgCorrlnBattVltgAndSwd1Ok(void);



