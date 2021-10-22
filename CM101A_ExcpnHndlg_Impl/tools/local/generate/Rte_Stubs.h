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

/* PIMs */
extern VAR(uint32, AUTOMATIC) ExcpnHndlg_Pim_McuDiagcData[4];
extern VAR(uint16, AUTOMATIC) ExcpnHndlg_Pim_ExcpnHndlgOsErrCod;

/* Arguments and Returns */
extern VAR(boolean, AUTOMATIC) ExcpnHndlg_Srv_McuDiagcData_SetRamBlockStatus_BlockChanged;
extern VAR(Std_ReturnType, AUTOMATIC) ExcpnHndlg_Srv_McuDiagcData_SetRamBlockStatus_Return;
extern VAR(NtcNr1, AUTOMATIC) ExcpnHndlg_Srv_SetNtcSts_NtcNr;
extern VAR(uint8, AUTOMATIC) ExcpnHndlg_Srv_SetNtcSts_NtcStInfo;
extern VAR(NtcSts1, AUTOMATIC) ExcpnHndlg_Srv_SetNtcSts_NtcSts;
extern VAR(uint16, AUTOMATIC) ExcpnHndlg_Srv_SetNtcSts_DebStep;
extern VAR(Std_ReturnType, AUTOMATIC) ExcpnHndlg_Srv_SetNtcSts_Return;
extern VAR(boolean, AUTOMATIC) ExcpnHndlg_Cli_ChkForStrtUpTest_ExecStrtUpTest;
extern VAR(uint32, AUTOMATIC) ExcpnHndlg_Cli_GetMcuDiagcSpplData_McuDiagcData1;


/*** PIM Stubs ***/

#ifdef Rte_Pim_McuDiagcData
# undef Rte_Pim_McuDiagcData
#else
#error Rte_Pim_McuDiagcData is missing
#endif
#define Rte_Pim_McuDiagcData() (&(ExcpnHndlg_Pim_McuDiagcData[0]))

/*#ifdef Rte_Pim_ExcpnHndlgOsErrCod
# undef Rte_Pim_ExcpnHndlgOsErrCod
#else
#error Rte_Pim_ExcpnHndlgOsErrCod is missing
#endif
#define Rte_Pim_ExcpnHndlgOsErrCod() (&ExcpnHndlg_Pim_ExcpnHndlgOsErrCod)*/


/*** Client Stub ***/

extern FUNC(void, AUTOMATIC) Rte_Stub(void);


#endif
