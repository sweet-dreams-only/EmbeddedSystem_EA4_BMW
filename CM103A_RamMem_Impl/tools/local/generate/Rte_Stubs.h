/******************************************************************************************************************
* Copyright 2016 Nxtr
* Nxtr Confidential
*
* Module File Name:   Rte_Stubs.h
* Module Description: Stubs header for Polyspace analysis.  Generated from TL109A_SwcSuprt.
* Project:            CBD
* Author:             Owen Tosh
******************************************************************************************************************/


#ifndef RTE_STUBS_H
#define RTE_STUBS_H

#include "math_stubs.h"

/*** Extern Statements ***/

/* Outputs */
extern VAR(uint8, AUTOMATIC) RamMem_Op_LclRamEccSngBitCntrOutp;

/* PIMs */
extern VAR(uint32, AUTOMATIC) RamMem_Pim_dRamMemCanRamDblBitEccErrAdr;
extern VAR(uint32, AUTOMATIC) RamMem_Pim_dRamMemCanRamSngBitEccErrAdr;
extern VAR(uint32, AUTOMATIC) RamMem_Pim_dRamMemFrRamDblBitEccErrAdr;
extern VAR(uint32, AUTOMATIC) RamMem_Pim_dRamMemFrRamSngBitEccErrAdr;
extern VAR(uint32, AUTOMATIC) RamMem_Pim_dRamMemFrRamTmpBufADblBitEccErrAdr;
extern VAR(uint32, AUTOMATIC) RamMem_Pim_dRamMemFrRamTmpBufBDblBitEccErrAdr;
extern VAR(uint32, AUTOMATIC) RamMem_Pim_dRamMemSpi0RamEccErrAdr;
extern VAR(uint32, AUTOMATIC) RamMem_Pim_dRamMemSpi1RamEccErrAdr;
extern VAR(uint32, AUTOMATIC) RamMem_Pim_dRamMemSpi2RamEccErrAdr;
extern VAR(uint32, AUTOMATIC) RamMem_Pim_dRamMemSpi3RamEccErrAdr;
extern VAR(uint32, AUTOMATIC) RamMem_Pim_dRamMemSpiRamEccErrAdr;
extern VAR(uint8, AUTOMATIC) RamMem_Pim_LclRamEccSngBitCntr;
extern VAR(boolean, AUTOMATIC) RamMem_Pim_LclRamEccSngBitSoftFailr;
extern VAR(uint32, AUTOMATIC) RamMem_Pim_LclRamFailrAdr;
extern VAR(uint32, AUTOMATIC) RamMem_Pim_LclRamWordLineRead;

/* Arguments and Returns */
extern VAR(NtcNr1, AUTOMATIC) RamMem_Srv_SetNtcSts_NtcNr;
extern VAR(uint8, AUTOMATIC) RamMem_Srv_SetNtcSts_NtcStInfo;
extern VAR(NtcSts1, AUTOMATIC) RamMem_Srv_SetNtcSts_NtcSts;
extern VAR(uint16, AUTOMATIC) RamMem_Srv_SetNtcSts_DebStep;
extern VAR(Std_ReturnType, AUTOMATIC) RamMem_Srv_SetNtcSts_Return;


/*** Output Stubs ***/

#ifdef Rte_Write_LclRamEccSngBitCntrOutp_Val
# undef Rte_Write_LclRamEccSngBitCntrOutp_Val
#else
#error Rte_Write_LclRamEccSngBitCntrOutp_Val is missing
#endif
#define Rte_Write_LclRamEccSngBitCntrOutp_Val(data) (RamMem_Op_LclRamEccSngBitCntrOutp = (data))


/*** PIM Stubs ***/

#ifdef Rte_Pim_dRamMemCanRamDblBitEccErrAdr
# undef Rte_Pim_dRamMemCanRamDblBitEccErrAdr
#else
#error Rte_Pim_dRamMemCanRamDblBitEccErrAdr is missing
#endif
#define Rte_Pim_dRamMemCanRamDblBitEccErrAdr() (&RamMem_Pim_dRamMemCanRamDblBitEccErrAdr)

#ifdef Rte_Pim_dRamMemCanRamSngBitEccErrAdr
# undef Rte_Pim_dRamMemCanRamSngBitEccErrAdr
#else
#error Rte_Pim_dRamMemCanRamSngBitEccErrAdr is missing
#endif
#define Rte_Pim_dRamMemCanRamSngBitEccErrAdr() (&RamMem_Pim_dRamMemCanRamSngBitEccErrAdr)

#ifdef Rte_Pim_dRamMemFrRamDblBitEccErrAdr
# undef Rte_Pim_dRamMemFrRamDblBitEccErrAdr
#else
#error Rte_Pim_dRamMemFrRamDblBitEccErrAdr is missing
#endif
#define Rte_Pim_dRamMemFrRamDblBitEccErrAdr() (&RamMem_Pim_dRamMemFrRamDblBitEccErrAdr)

#ifdef Rte_Pim_dRamMemFrRamSngBitEccErrAdr
# undef Rte_Pim_dRamMemFrRamSngBitEccErrAdr
#else
#error Rte_Pim_dRamMemFrRamSngBitEccErrAdr is missing
#endif
#define Rte_Pim_dRamMemFrRamSngBitEccErrAdr() (&RamMem_Pim_dRamMemFrRamSngBitEccErrAdr)

#ifdef Rte_Pim_dRamMemFrRamTmpBufADblBitEccErrAdr
# undef Rte_Pim_dRamMemFrRamTmpBufADblBitEccErrAdr
#else
#error Rte_Pim_dRamMemFrRamTmpBufADblBitEccErrAdr is missing
#endif
#define Rte_Pim_dRamMemFrRamTmpBufADblBitEccErrAdr() (&RamMem_Pim_dRamMemFrRamTmpBufADblBitEccErrAdr)

#ifdef Rte_Pim_dRamMemFrRamTmpBufBDblBitEccErrAdr
# undef Rte_Pim_dRamMemFrRamTmpBufBDblBitEccErrAdr
#else
#error Rte_Pim_dRamMemFrRamTmpBufBDblBitEccErrAdr is missing
#endif
#define Rte_Pim_dRamMemFrRamTmpBufBDblBitEccErrAdr() (&RamMem_Pim_dRamMemFrRamTmpBufBDblBitEccErrAdr)

#ifdef Rte_Pim_dRamMemSpi0RamEccErrAdr
# undef Rte_Pim_dRamMemSpi0RamEccErrAdr
#else
#error Rte_Pim_dRamMemSpi0RamEccErrAdr is missing
#endif
#define Rte_Pim_dRamMemSpi0RamEccErrAdr() (&RamMem_Pim_dRamMemSpi0RamEccErrAdr)

#ifdef Rte_Pim_dRamMemSpi1RamEccErrAdr
# undef Rte_Pim_dRamMemSpi1RamEccErrAdr
#else
#error Rte_Pim_dRamMemSpi1RamEccErrAdr is missing
#endif
#define Rte_Pim_dRamMemSpi1RamEccErrAdr() (&RamMem_Pim_dRamMemSpi1RamEccErrAdr)

#ifdef Rte_Pim_dRamMemSpi2RamEccErrAdr
# undef Rte_Pim_dRamMemSpi2RamEccErrAdr
#else
#error Rte_Pim_dRamMemSpi2RamEccErrAdr is missing
#endif
#define Rte_Pim_dRamMemSpi2RamEccErrAdr() (&RamMem_Pim_dRamMemSpi2RamEccErrAdr)

#ifdef Rte_Pim_dRamMemSpi3RamEccErrAdr
# undef Rte_Pim_dRamMemSpi3RamEccErrAdr
#else
#error Rte_Pim_dRamMemSpi3RamEccErrAdr is missing
#endif
#define Rte_Pim_dRamMemSpi3RamEccErrAdr() (&RamMem_Pim_dRamMemSpi3RamEccErrAdr)

#ifdef Rte_Pim_dRamMemSpiRamEccErrAdr
# undef Rte_Pim_dRamMemSpiRamEccErrAdr
#else
#error Rte_Pim_dRamMemSpiRamEccErrAdr is missing
#endif
#define Rte_Pim_dRamMemSpiRamEccErrAdr() (&RamMem_Pim_dRamMemSpiRamEccErrAdr)

#ifdef Rte_Pim_LclRamEccSngBitCntr
# undef Rte_Pim_LclRamEccSngBitCntr
#else
#error Rte_Pim_LclRamEccSngBitCntr is missing
#endif
#define Rte_Pim_LclRamEccSngBitCntr() (&RamMem_Pim_LclRamEccSngBitCntr)

#ifdef Rte_Pim_LclRamEccSngBitSoftFailr
# undef Rte_Pim_LclRamEccSngBitSoftFailr
#else
#error Rte_Pim_LclRamEccSngBitSoftFailr is missing
#endif
#define Rte_Pim_LclRamEccSngBitSoftFailr() (&RamMem_Pim_LclRamEccSngBitSoftFailr)

#ifdef Rte_Pim_LclRamFailrAdr
# undef Rte_Pim_LclRamFailrAdr
#else
#error Rte_Pim_LclRamFailrAdr is missing
#endif
#define Rte_Pim_LclRamFailrAdr() (&RamMem_Pim_LclRamFailrAdr)

#ifdef Rte_Pim_LclRamWordLineRead
# undef Rte_Pim_LclRamWordLineRead
#else
#error Rte_Pim_LclRamWordLineRead is missing
#endif
#define Rte_Pim_LclRamWordLineRead() (&RamMem_Pim_LclRamWordLineRead)


/*** Client Stub ***/

extern FUNC(void, AUTOMATIC) Rte_Stub(void);


#endif
