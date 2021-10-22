/******************************************************************************************************************
* Copyright 2016 Nxtr
* Nxtr Confidential
*
* Module File Name:   Rte_Stubs.c
* Module Description: Stubs for Polyspace analysis.  Generated from TL109A_SwcSuprt.
* Project:            CBD
* Author:             Owen Tosh
******************************************************************************************************************/


#include "Rte_CDD_ExcpnHndlg.h"
#include "float.h"


/*** Server Port Stubs ***/

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_ExcpnHndlg_McuDiagcData_SetRamBlockStatus(boolean BlockChanged_Arg)
{
    ExcpnHndlg_Srv_McuDiagcData_SetRamBlockStatus_BlockChanged = BlockChanged_Arg;
    return ExcpnHndlg_Srv_McuDiagcData_SetRamBlockStatus_Return;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_ExcpnHndlg_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
{
    ExcpnHndlg_Srv_SetNtcSts_NtcNr = NtcNr_Arg;
    ExcpnHndlg_Srv_SetNtcSts_NtcStInfo = NtcStInfo_Arg;
    ExcpnHndlg_Srv_SetNtcSts_NtcSts = NtcSts_Arg;
    ExcpnHndlg_Srv_SetNtcSts_DebStep = DebStep_Arg;
    return ExcpnHndlg_Srv_SetNtcSts_Return;
}


/*** Client Port Stubs ***/

FUNC(void, AUTOMATIC) Rte_Stub(void)
{
    AlgnErrIrq();
    ExcpnHndlgInit1();
    ExcpnHndlgInit2();
    ExcpnHndlgPer1();
    FpuErrIrq();
    ResdOperIrq();
    SysErrIrq();
    ChkForStrtUpTest_Oper(&ExcpnHndlg_Cli_ChkForStrtUpTest_ExecStrtUpTest);
    GetMcuDiagcSpplData_Oper(&ExcpnHndlg_Cli_GetMcuDiagcSpplData_McuDiagcData1);
}

