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
extern VAR(float32, AUTOMATIC) BattRtnCurr_Ip_BattRtnCurrAdc;
extern VAR(boolean, AUTOMATIC) BattRtnCurr_Ip_BattRtnCurrAdcFaild;
extern VAR(float32, AUTOMATIC) BattRtnCurr_Ip_SplyCurrEstim;
extern VAR(SysSt1, AUTOMATIC) BattRtnCurr_Ip_SysSt;

/* Outputs */
extern VAR(float32, AUTOMATIC) BattRtnCurr_Op_BattRtnCurrAmpr;
extern VAR(SigQlfr1, AUTOMATIC) BattRtnCurr_Op_BattRtnCurrStsQlfr;

/* PIMs */
extern VAR(float32, AUTOMATIC) BattRtnCurr_Pim_dBattRtnCurrBfrSatn;
extern VAR(FilLpRec1, AUTOMATIC) BattRtnCurr_Pim_BattCurrEstimDifLpFil;

/* Arguments and Returns */
extern VAR(uint32, AUTOMATIC) BattRtnCurr_Srv_CnvSnpshtData_f32_SnpshtDataCnvd;
extern VAR(float32, AUTOMATIC) BattRtnCurr_Srv_CnvSnpshtData_f32_SnpshtData;
extern VAR(uint32, AUTOMATIC) BattRtnCurr_Srv_CnvSnpshtData_u08_SnpshtDataCnvd;
extern VAR(uint8, AUTOMATIC) BattRtnCurr_Srv_CnvSnpshtData_u08_SnpshtData;
extern VAR(NtcNr1, AUTOMATIC) BattRtnCurr_Srv_GetNtcQlfrSts_NtcNr;
extern VAR(SigQlfr1, AUTOMATIC) BattRtnCurr_Srv_GetNtcQlfrSts_NtcQlfr;
extern VAR(Std_ReturnType, AUTOMATIC) BattRtnCurr_Srv_GetNtcQlfrSts_Return;
extern VAR(NtcNr1, AUTOMATIC) BattRtnCurr_Srv_SetNtcStsAndSnpshtData_NtcNr;
extern VAR(uint8, AUTOMATIC) BattRtnCurr_Srv_SetNtcStsAndSnpshtData_NtcStInfo;
extern VAR(NtcSts1, AUTOMATIC) BattRtnCurr_Srv_SetNtcStsAndSnpshtData_NtcSts;
extern VAR(uint16, AUTOMATIC) BattRtnCurr_Srv_SetNtcStsAndSnpshtData_DebStep;
extern VAR(uint32, AUTOMATIC) BattRtnCurr_Srv_SetNtcStsAndSnpshtData_SpclSnpshtData0;
extern VAR(uint32, AUTOMATIC) BattRtnCurr_Srv_SetNtcStsAndSnpshtData_SpclSnpshtData1;
extern VAR(uint32, AUTOMATIC) BattRtnCurr_Srv_SetNtcStsAndSnpshtData_SpclSnpshtData2;
extern VAR(Std_ReturnType, AUTOMATIC) BattRtnCurr_Srv_SetNtcStsAndSnpshtData_Return;


/*** Input Stubs ***/

#ifdef Rte_Read_BattRtnCurrAdc_Val
# undef Rte_Read_BattRtnCurrAdc_Val
#endif
#define Rte_Read_BattRtnCurrAdc_Val(data) (*(data) = BattRtnCurr_Ip_BattRtnCurrAdc)

#ifdef Rte_Read_BattRtnCurrAdcFaild_Logl
# undef Rte_Read_BattRtnCurrAdcFaild_Logl
#endif
#define Rte_Read_BattRtnCurrAdcFaild_Logl(data) (*(data) = BattRtnCurr_Ip_BattRtnCurrAdcFaild)

#ifdef Rte_Read_SplyCurrEstim_Val
# undef Rte_Read_SplyCurrEstim_Val
#endif
#define Rte_Read_SplyCurrEstim_Val(data) (*(data) = BattRtnCurr_Ip_SplyCurrEstim)

#ifdef Rte_Read_SysSt_Val
# undef Rte_Read_SysSt_Val
#endif
#define Rte_Read_SysSt_Val(data) (*(data) = BattRtnCurr_Ip_SysSt)


/*** Output Stubs ***/

#ifdef Rte_Write_BattRtnCurrAmpr_Val
# undef Rte_Write_BattRtnCurrAmpr_Val
#endif
#define Rte_Write_BattRtnCurrAmpr_Val(data) (BattRtnCurr_Op_BattRtnCurrAmpr = (data))

#ifdef Rte_Write_BattRtnCurrStsQlfr_Val
# undef Rte_Write_BattRtnCurrStsQlfr_Val
#endif
#define Rte_Write_BattRtnCurrStsQlfr_Val(data) (BattRtnCurr_Op_BattRtnCurrStsQlfr = (data))


/*** PIM Stubs ***/

#ifdef Rte_Pim_dBattRtnCurrBfrSatn
# undef Rte_Pim_dBattRtnCurrBfrSatn
#endif
#define Rte_Pim_dBattRtnCurrBfrSatn() (&BattRtnCurr_Pim_dBattRtnCurrBfrSatn)

#ifdef Rte_Pim_BattCurrEstimDifLpFil
# undef Rte_Pim_BattCurrEstimDifLpFil
#endif
#define Rte_Pim_BattCurrEstimDifLpFil() (&BattRtnCurr_Pim_BattCurrEstimDifLpFil)


/*** Client Stub ***/

extern FUNC(void, AUTOMATIC) Rte_Stub(void);


#endif
