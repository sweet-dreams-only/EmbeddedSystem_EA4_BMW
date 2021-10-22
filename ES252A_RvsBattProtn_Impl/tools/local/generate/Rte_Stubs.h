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


/*** Extern Statements ***/

/* Inputs */
extern VAR(float32, AUTOMATIC) RvsBattProtn_Ip_RvsBattDiagcGndAdc;
extern VAR(boolean, AUTOMATIC) RvsBattProtn_Ip_RvsBattDiagcGndAdcFaild;
extern VAR(float32, AUTOMATIC) RvsBattProtn_Ip_RvsBattDiagcRtnAdc;
extern VAR(boolean, AUTOMATIC) RvsBattProtn_Ip_RvsBattDiagcRtnAdcFaild;

/* Outputs */
extern VAR(SigQlfr1, AUTOMATIC) RvsBattProtn_Op_RvsBattProtnStsQlfr;

/* Arguments and Returns */
extern VAR(uint32, AUTOMATIC) RvsBattProtn_Srv_CnvSnpshtData_f32_SnpshtDataCnvd;
extern VAR(float32, AUTOMATIC) RvsBattProtn_Srv_CnvSnpshtData_f32_SnpshtData;
extern VAR(NtcNr1, AUTOMATIC) RvsBattProtn_Srv_GetNtcQlfrSts_NtcNr;
extern VAR(SigQlfr1, AUTOMATIC) RvsBattProtn_Srv_GetNtcQlfrSts_NtcQlfr;
extern VAR(Std_ReturnType, AUTOMATIC) RvsBattProtn_Srv_GetNtcQlfrSts_Return;
extern VAR(NtcNr1, AUTOMATIC) RvsBattProtn_Srv_SetNtcStsAndSnpshtData_NtcNr;
extern VAR(uint8, AUTOMATIC) RvsBattProtn_Srv_SetNtcStsAndSnpshtData_NtcStInfo;
extern VAR(NtcSts1, AUTOMATIC) RvsBattProtn_Srv_SetNtcStsAndSnpshtData_NtcSts;
extern VAR(uint16, AUTOMATIC) RvsBattProtn_Srv_SetNtcStsAndSnpshtData_DebStep;
extern VAR(uint32, AUTOMATIC) RvsBattProtn_Srv_SetNtcStsAndSnpshtData_SpclSnpshtData0;
extern VAR(uint32, AUTOMATIC) RvsBattProtn_Srv_SetNtcStsAndSnpshtData_SpclSnpshtData1;
extern VAR(uint32, AUTOMATIC) RvsBattProtn_Srv_SetNtcStsAndSnpshtData_SpclSnpshtData2;
extern VAR(Std_ReturnType, AUTOMATIC) RvsBattProtn_Srv_SetNtcStsAndSnpshtData_Return;


/*** Input Stubs ***/

#ifdef Rte_Read_RvsBattDiagcGndAdc_Val
# undef Rte_Read_RvsBattDiagcGndAdc_Val
#endif
#define Rte_Read_RvsBattDiagcGndAdc_Val(data) (*(data) = RvsBattProtn_Ip_RvsBattDiagcGndAdc)

#ifdef Rte_Read_RvsBattDiagcGndAdcFaild_Logl
# undef Rte_Read_RvsBattDiagcGndAdcFaild_Logl
#endif
#define Rte_Read_RvsBattDiagcGndAdcFaild_Logl(data) (*(data) = RvsBattProtn_Ip_RvsBattDiagcGndAdcFaild)

#ifdef Rte_Read_RvsBattDiagcRtnAdc_Val
# undef Rte_Read_RvsBattDiagcRtnAdc_Val
#endif
#define Rte_Read_RvsBattDiagcRtnAdc_Val(data) (*(data) = RvsBattProtn_Ip_RvsBattDiagcRtnAdc)

#ifdef Rte_Read_RvsBattDiagcRtnAdcFaild_Logl
# undef Rte_Read_RvsBattDiagcRtnAdcFaild_Logl
#endif
#define Rte_Read_RvsBattDiagcRtnAdcFaild_Logl(data) (*(data) = RvsBattProtn_Ip_RvsBattDiagcRtnAdcFaild)


/*** Output Stubs ***/

#ifdef Rte_Write_RvsBattProtnStsQlfr_Val
# undef Rte_Write_RvsBattProtnStsQlfr_Val
#endif
#define Rte_Write_RvsBattProtnStsQlfr_Val(data) (RvsBattProtn_Op_RvsBattProtnStsQlfr = (data))


/*** Client Stub ***/

extern FUNC(void, AUTOMATIC) Rte_Stub(void);


#endif
