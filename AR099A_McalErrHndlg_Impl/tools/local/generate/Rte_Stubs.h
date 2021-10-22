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

/* PIMs */
extern VAR(uint8, AUTOMATIC) McalErrHndlg_Pim_CritErrCod;
extern VAR(uint8, AUTOMATIC) McalErrHndlg_Pim_NonCritErrCod;

/* Arguments and Returns */
extern VAR(uint8, AUTOMATIC) McalErrHndlg_Srv_MCalReadVrfyFailFltInfo_PrphlId;
extern VAR(uint16, AUTOMATIC) McalErrHndlg_Srv_MCalReadVrfyFailFltInfo_ErrId;
extern VAR(NtcNr1, AUTOMATIC) McalErrHndlg_Srv_SetNtcSts_NtcNr;
extern VAR(uint8, AUTOMATIC) McalErrHndlg_Srv_SetNtcSts_NtcStInfo;
extern VAR(NtcSts1, AUTOMATIC) McalErrHndlg_Srv_SetNtcSts_NtcSts;
extern VAR(uint16, AUTOMATIC) McalErrHndlg_Srv_SetNtcSts_DebStep;
extern VAR(Std_ReturnType, AUTOMATIC) McalErrHndlg_Srv_SetNtcSts_Return;


/*** PIM Stubs ***/

#ifdef Rte_Pim_CritErrCod
# undef Rte_Pim_CritErrCod
#endif
#define Rte_Pim_CritErrCod() (&McalErrHndlg_Pim_CritErrCod)

#ifdef Rte_Pim_NonCritErrCod
# undef Rte_Pim_NonCritErrCod
#endif
#define Rte_Pim_NonCritErrCod() (&McalErrHndlg_Pim_NonCritErrCod)


/*** Client Stub ***/

extern FUNC(void, AUTOMATIC) Rte_Stub(void);


#endif
