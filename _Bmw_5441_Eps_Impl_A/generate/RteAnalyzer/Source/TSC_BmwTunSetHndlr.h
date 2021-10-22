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
 *          File:  TSC_BmwTunSetHndlr.h
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
Std_ReturnType TSC_BmwTunSetHndlr_Rte_Read_BmwRtIdx_Val(BmwRtIdx1 *data);
Std_ReturnType TSC_BmwTunSetHndlr_Rte_Read_BmwRtIdxVld_Logl(boolean *data);
Std_ReturnType TSC_BmwTunSetHndlr_Rte_Read_TunSetHndlrEna_Logl(boolean *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_BmwTunSetHndlr_Rte_Write_DesIninIdx_Val(uint8 data);
Std_ReturnType TSC_BmwTunSetHndlr_Rte_Write_DesIninOptSetAIdx_Val(uint8 data);
Std_ReturnType TSC_BmwTunSetHndlr_Rte_Write_DesRtIdx_Val(uint8 data);

/** Client server interfaces */
Std_ReturnType TSC_BmwTunSetHndlr_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg);
Std_ReturnType TSC_BmwTunSetHndlr_Rte_Call_GetRefTmr100MicroSec32bit_Oper(uint32 *RefTmr_Arg);
Std_ReturnType TSC_BmwTunSetHndlr_Rte_Call_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg);
Std_ReturnType TSC_BmwTunSetHndlr_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg);
Std_ReturnType TSC_BmwTunSetHndlr_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg);

/** Service interfaces */
Std_ReturnType TSC_BmwTunSetHndlr_Rte_Call_BmwDesIninIdx_GetErrorStatus(NvM_RequestResultType *ErrorStatus_Arg);
Std_ReturnType TSC_BmwTunSetHndlr_Rte_Call_BmwDesIninIdx_SetRamBlockStatus(boolean RamBlockStatus_Arg);
Std_ReturnType TSC_BmwTunSetHndlr_Rte_Call_BmwDesIninOptSetAIdx_GetErrorStatus(NvM_RequestResultType *ErrorStatus_Arg);
Std_ReturnType TSC_BmwTunSetHndlr_Rte_Call_BmwDesIninOptSetAIdx_SetRamBlockStatus(boolean RamBlockStatus_Arg);
Std_ReturnType TSC_BmwTunSetHndlr_Rte_Call_BmwDesIninOptSetAIdx_SetRamBlockStatus(boolean RamBlockStatus_Arg);
Std_ReturnType TSC_BmwTunSetHndlr_Rte_Call_BmwDesIninIdx_SetRamBlockStatus(boolean RamBlockStatus_Arg);

/** Calibration Component Calibration Parameters */
uint16  TSC_BmwTunSetHndlr_Rte_Prm_BmwTunSetHndlrBmwRtIdxDebThd_Val(void);
uint8  TSC_BmwTunSetHndlr_Rte_Prm_BmwTunSetHndlrCptDisadOutp_Val(void);
uint8  TSC_BmwTunSetHndlr_Rte_Prm_BmwTunSetHndlrNrOfMotVrnt_Val(void);
uint8  TSC_BmwTunSetHndlr_Rte_Prm_BmwTunSetHndlrNrOfTunSet_Val(void);
uint8  TSC_BmwTunSetHndlr_Rte_Prm_BmwTunSetHndlrOvrdDesRtIdx_Val(void);

/** SW-C local Calibration Parameters */
BmwDesIninIdxRec1 * TSC_BmwTunSetHndlr_Rte_CData_BmwDesIninIdxDft(void);
BmwDesIninOptSetAIdxRec1 * TSC_BmwTunSetHndlr_Rte_CData_BmwDesIninOptSetAIdxDft(void);

/** Per Instance Memories */
uint32 *TSC_BmwTunSetHndlr_Rte_Pim_BmwRtIdxTi(void);
BmwRtIdx1 *TSC_BmwTunSetHndlr_Rte_Pim_DebBmwRtIdx(void);
uint8 *TSC_BmwTunSetHndlr_Rte_Pim_LstVldIdx(void);
BmwRtIdx1 *TSC_BmwTunSetHndlr_Rte_Pim_PrevBmwRtIdx(void);
BmwDesIninIdxRec1 *TSC_BmwTunSetHndlr_Rte_Pim_BmwDesIninIdx(void);
BmwDesIninOptSetAIdxRec1 *TSC_BmwTunSetHndlr_Rte_Pim_BmwDesIninOptSetAIdx(void);



