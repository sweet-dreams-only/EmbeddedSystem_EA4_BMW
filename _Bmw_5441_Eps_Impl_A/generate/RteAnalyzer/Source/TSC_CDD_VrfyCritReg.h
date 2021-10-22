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
 *          File:  TSC_CDD_VrfyCritReg.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Header of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/


/** Client server interfaces */
Std_ReturnType TSC_CDD_VrfyCritReg_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg);
Std_ReturnType TSC_CDD_VrfyCritReg_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg);
Std_ReturnType TSC_CDD_VrfyCritReg_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg);

/** Service interfaces */
Std_ReturnType TSC_CDD_VrfyCritReg_Rte_Call_MCalWrVrfyRegFltInfoStorg_GetErrorStatus(NvM_RequestResultType *ErrorStatus_Arg);
Std_ReturnType TSC_CDD_VrfyCritReg_Rte_Call_MCalWrVrfyRegFltInfoStorg_SetRamBlockStatus(boolean RamBlockStatus_Arg);
Std_ReturnType TSC_CDD_VrfyCritReg_Rte_Call_MCalWrVrfyRegFltInfoStorg_SetRamBlockStatus(boolean RamBlockStatus_Arg);

/** Per Instance Memories */
uint32 *TSC_CDD_VrfyCritReg_Rte_Pim_MCalReadVrfyCritRegFltInfo(void);
uint32 *TSC_CDD_VrfyCritReg_Rte_Pim_MCalReadVrfyCritRegFltNvmInfo(void);
uint32 *TSC_CDD_VrfyCritReg_Rte_Pim_dVrfyCritRegCritRegActVal(void);
uint32 *TSC_CDD_VrfyCritReg_Rte_Pim_dVrfyCritRegCritRegAdr(void);
uint32 *TSC_CDD_VrfyCritReg_Rte_Pim_dVrfyCritRegCritRegDesVal(void);
uint32 *TSC_CDD_VrfyCritReg_Rte_Pim_dVrfyCritRegSysCritRegActVal(void);
uint32 *TSC_CDD_VrfyCritReg_Rte_Pim_dVrfyCritRegSysCritRegAdr(void);
uint32 *TSC_CDD_VrfyCritReg_Rte_Pim_dVrfyCritRegSysCritRegDesVal(void);



