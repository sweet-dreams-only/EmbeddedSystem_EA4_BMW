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
 *          File:  TSC_CDD_RamMem.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Header of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/


/** Sender receiver - explicit write services */
Std_ReturnType TSC_CDD_RamMem_Rte_Write_LclRamEccSngBitCntrOutp_Val(uint8 data);

/** Client server interfaces */
Std_ReturnType TSC_CDD_RamMem_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg);
Std_ReturnType TSC_CDD_RamMem_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg);

/** Per Instance Memories */
uint32 *TSC_CDD_RamMem_Rte_Pim_LclRamFailrAdr(void);
uint32 *TSC_CDD_RamMem_Rte_Pim_LclRamWordLineRead(void);
uint32 *TSC_CDD_RamMem_Rte_Pim_dRamMemCanRamDblBitEccErrAdr(void);
uint32 *TSC_CDD_RamMem_Rte_Pim_dRamMemCanRamSngBitEccErrAdr(void);
uint32 *TSC_CDD_RamMem_Rte_Pim_dRamMemFrRamDblBitEccErrAdr(void);
uint32 *TSC_CDD_RamMem_Rte_Pim_dRamMemFrRamSngBitEccErrAdr(void);
uint32 *TSC_CDD_RamMem_Rte_Pim_dRamMemFrRamTmpBufADblBitEccErrAdr(void);
uint32 *TSC_CDD_RamMem_Rte_Pim_dRamMemFrRamTmpBufBDblBitEccErrAdr(void);
uint32 *TSC_CDD_RamMem_Rte_Pim_dRamMemSpi0RamEccErrAdr(void);
uint32 *TSC_CDD_RamMem_Rte_Pim_dRamMemSpi1RamEccErrAdr(void);
uint32 *TSC_CDD_RamMem_Rte_Pim_dRamMemSpi2RamEccErrAdr(void);
uint32 *TSC_CDD_RamMem_Rte_Pim_dRamMemSpi3RamEccErrAdr(void);
uint32 *TSC_CDD_RamMem_Rte_Pim_dRamMemSpiRamEccErrAdr(void);
uint8 *TSC_CDD_RamMem_Rte_Pim_LclRamEccSngBitCntr(void);
boolean *TSC_CDD_RamMem_Rte_Pim_LclRamEccSngBitSoftFailr(void);



