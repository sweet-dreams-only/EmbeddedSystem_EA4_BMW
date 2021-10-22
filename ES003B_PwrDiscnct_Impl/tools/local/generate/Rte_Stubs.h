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
extern VAR(float32, AUTOMATIC) PwrDiscnct_Ip_BattVltg;
extern VAR(float32, AUTOMATIC) PwrDiscnct_Ip_BattVltgSwd1;
extern VAR(uint8, AUTOMATIC) PwrDiscnct_Ip_StrtUpSt;

/* Outputs */
extern VAR(boolean, AUTOMATIC) PwrDiscnct_Op_PwrDiscnctATestCmpl;
extern VAR(boolean, AUTOMATIC) PwrDiscnct_Op_PwrDiscnctBTestCmpl;

/* Calibrations */
extern CONST(float32, AUTOMATIC) PwrDiscnct_Cal_BattVltgSwdMax;

/* PIMs */
extern VAR(boolean, AUTOMATIC) PwrDiscnct_Pim_PwrDiscnctATestCmplPrev;

/* Arguments and Returns */
extern VAR(NtcNr1, AUTOMATIC) PwrDiscnct_Srv_GetNtcQlfrSts_NtcNr;
extern VAR(SigQlfr1, AUTOMATIC) PwrDiscnct_Srv_GetNtcQlfrSts_NtcQlfr;
extern VAR(Std_ReturnType, AUTOMATIC) PwrDiscnct_Srv_GetNtcQlfrSts_Return;
extern VAR(NtcNr1, AUTOMATIC) PwrDiscnct_Srv_SetNtcSts_NtcNr;
extern VAR(uint8, AUTOMATIC) PwrDiscnct_Srv_SetNtcSts_NtcStInfo;
extern VAR(NtcSts1, AUTOMATIC) PwrDiscnct_Srv_SetNtcSts_NtcSts;
extern VAR(uint16, AUTOMATIC) PwrDiscnct_Srv_SetNtcSts_DebStep;
extern VAR(Std_ReturnType, AUTOMATIC) PwrDiscnct_Srv_SetNtcSts_Return;


/*** Input Stubs ***/

#ifdef Rte_Read_BattVltg_Val
# undef Rte_Read_BattVltg_Val
#endif
#define Rte_Read_BattVltg_Val(data) (*(data) = PwrDiscnct_Ip_BattVltg)

#ifdef Rte_Read_BattVltgSwd1_Val
# undef Rte_Read_BattVltgSwd1_Val
#endif
#define Rte_Read_BattVltgSwd1_Val(data) (*(data) = PwrDiscnct_Ip_BattVltgSwd1)

#ifdef Rte_Read_StrtUpSt_Val
# undef Rte_Read_StrtUpSt_Val
#endif
#define Rte_Read_StrtUpSt_Val(data) (*(data) = PwrDiscnct_Ip_StrtUpSt)


/*** Output Stubs ***/

#ifdef Rte_Write_PwrDiscnctATestCmpl_Logl
# undef Rte_Write_PwrDiscnctATestCmpl_Logl
#endif
#define Rte_Write_PwrDiscnctATestCmpl_Logl(data) (PwrDiscnct_Op_PwrDiscnctATestCmpl = (data))

#ifdef Rte_Write_PwrDiscnctBTestCmpl_Logl
# undef Rte_Write_PwrDiscnctBTestCmpl_Logl
#endif
#define Rte_Write_PwrDiscnctBTestCmpl_Logl(data) (PwrDiscnct_Op_PwrDiscnctBTestCmpl = (data))


/*** Calibration Stubs ***/

#ifdef Rte_Prm_BattVltgSwdMax_Val
# undef Rte_Prm_BattVltgSwdMax_Val
#endif
#define Rte_Prm_BattVltgSwdMax_Val() (PwrDiscnct_Cal_BattVltgSwdMax)


/*** PIM Stubs ***/

#ifdef Rte_Pim_PwrDiscnctATestCmplPrev
# undef Rte_Pim_PwrDiscnctATestCmplPrev
#endif
#define Rte_Pim_PwrDiscnctATestCmplPrev() (&PwrDiscnct_Pim_PwrDiscnctATestCmplPrev)


/*** Client Stub ***/

extern FUNC(void, AUTOMATIC) Rte_Stub(void);


#endif
