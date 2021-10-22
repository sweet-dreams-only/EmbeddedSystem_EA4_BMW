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
extern VAR(boolean, AUTOMATIC) SerlComTrcvIf_Op_SerlComTrcvIfNoErr;
extern VAR(SigQlfr1, AUTOMATIC) SerlComTrcvIf_Op_SerlComTrcvIfQlfr;

/* PIMs */
extern VAR(uint16, AUTOMATIC) SerlComTrcvIf_Pim_dSerlComTrcvIfStsReg;
extern VAR(boolean, AUTOMATIC) SerlComTrcvIf_Pim_SerlComTrcvIfFltErrPin;
extern VAR(uint8, AUTOMATIC) SerlComTrcvIf_Pim_SerlComTrcvIfSpiErrCntr;
extern VAR(uint8, AUTOMATIC) SerlComTrcvIf_Pim_SerlComTrcvIfSt;

/* Arguments and Returns */
extern VAR(uint32, AUTOMATIC) SerlComTrcvIf_Srv_CnvSnpshtData_u16_SnpshtDataCnvd;
extern VAR(uint16, AUTOMATIC) SerlComTrcvIf_Srv_CnvSnpshtData_u16_SnpshtData;
extern VAR(NtcNr1, AUTOMATIC) SerlComTrcvIf_Srv_GetNtcQlfrSts_NtcNr;
extern VAR(SigQlfr1, AUTOMATIC) SerlComTrcvIf_Srv_GetNtcQlfrSts_NtcQlfr;
extern VAR(Std_ReturnType, AUTOMATIC) SerlComTrcvIf_Srv_GetNtcQlfrSts_Return;
extern VAR(boolean, AUTOMATIC) SerlComTrcvIf_Srv_IoHwAb_GetGpioERRN_PinSt;
extern VAR(Std_ReturnType, AUTOMATIC) SerlComTrcvIf_Srv_IoHwAb_GetGpioERRN_Return;
extern VAR(NtcNr1, AUTOMATIC) SerlComTrcvIf_Srv_SetNtcStsAndSnpshtData_NtcNr;
extern VAR(uint8, AUTOMATIC) SerlComTrcvIf_Srv_SetNtcStsAndSnpshtData_NtcStInfo;
extern VAR(NtcSts1, AUTOMATIC) SerlComTrcvIf_Srv_SetNtcStsAndSnpshtData_NtcSts;
extern VAR(uint16, AUTOMATIC) SerlComTrcvIf_Srv_SetNtcStsAndSnpshtData_DebStep;
extern VAR(uint32, AUTOMATIC) SerlComTrcvIf_Srv_SetNtcStsAndSnpshtData_SpclSnpshtData0;
extern VAR(uint32, AUTOMATIC) SerlComTrcvIf_Srv_SetNtcStsAndSnpshtData_SpclSnpshtData1;
extern VAR(uint32, AUTOMATIC) SerlComTrcvIf_Srv_SetNtcStsAndSnpshtData_SpclSnpshtData2;
extern VAR(Std_ReturnType, AUTOMATIC) SerlComTrcvIf_Srv_SetNtcStsAndSnpshtData_Return;


/*** Output Stubs ***/

#ifdef Rte_Write_SerlComTrcvIfNoErr_Logl
# undef Rte_Write_SerlComTrcvIfNoErr_Logl
#else
#error Rte_Write_SerlComTrcvIfNoErr_Logl is missing
#endif
#define Rte_Write_SerlComTrcvIfNoErr_Logl(data) (SerlComTrcvIf_Op_SerlComTrcvIfNoErr = (data))

#ifdef Rte_Write_SerlComTrcvIfQlfr_Val
# undef Rte_Write_SerlComTrcvIfQlfr_Val
#else
#error Rte_Write_SerlComTrcvIfQlfr_Val is missing
#endif
#define Rte_Write_SerlComTrcvIfQlfr_Val(data) (SerlComTrcvIf_Op_SerlComTrcvIfQlfr = (data))


/*** PIM Stubs ***/

#ifdef Rte_Pim_dSerlComTrcvIfStsReg
# undef Rte_Pim_dSerlComTrcvIfStsReg
#else
#error Rte_Pim_dSerlComTrcvIfStsReg is missing
#endif
#define Rte_Pim_dSerlComTrcvIfStsReg() (&SerlComTrcvIf_Pim_dSerlComTrcvIfStsReg)

#ifdef Rte_Pim_SerlComTrcvIfFltErrPin
# undef Rte_Pim_SerlComTrcvIfFltErrPin
#else
#error Rte_Pim_SerlComTrcvIfFltErrPin is missing
#endif
#define Rte_Pim_SerlComTrcvIfFltErrPin() (&SerlComTrcvIf_Pim_SerlComTrcvIfFltErrPin)

#ifdef Rte_Pim_SerlComTrcvIfSpiErrCntr
# undef Rte_Pim_SerlComTrcvIfSpiErrCntr
#else
#error Rte_Pim_SerlComTrcvIfSpiErrCntr is missing
#endif
#define Rte_Pim_SerlComTrcvIfSpiErrCntr() (&SerlComTrcvIf_Pim_SerlComTrcvIfSpiErrCntr)

#ifdef Rte_Pim_SerlComTrcvIfSt
# undef Rte_Pim_SerlComTrcvIfSt
#else
#error Rte_Pim_SerlComTrcvIfSt is missing
#endif
#define Rte_Pim_SerlComTrcvIfSt() (&SerlComTrcvIf_Pim_SerlComTrcvIfSt)


/*** Client Stub ***/

extern FUNC(void, AUTOMATIC) Rte_Stub(void);


#endif
