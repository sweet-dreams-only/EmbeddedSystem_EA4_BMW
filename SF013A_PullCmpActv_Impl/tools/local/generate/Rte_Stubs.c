/******************************************************************************************************************
* Copyright 2016 Nxtr
* Nxtr Confidential
*
* Module File Name:   Rte_Stubs.c
* Module Description: Stubs for Polyspace analysis.  Generated from TL109A_SwcSuprt.
* Project:            CBD
* Author:             Owen Tosh
******************************************************************************************************************/


#include "Rte_PullCmpActv.h"
#include "float.h"


/*** Server Port Stubs ***/

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PullCmpActv_GetRefTmr100MicroSec32bit_Oper(uint32 * RefTmr_Arg)
{
    *RefTmr_Arg = PullCmpActv_Srv_GetRefTmr100MicroSec32bit_RefTmr;
    return (Std_ReturnType)0U;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PullCmpActv_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 * TiSpan_Arg)
{
    PullCmpActv_Srv_GetTiSpan100MicroSec32bit_RefTmr = RefTmr_Arg;
    *TiSpan_Arg = PullCmpActv_Srv_GetTiSpan100MicroSec32bit_TiSpan;
    return (Std_ReturnType)0U;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PullCmpActv_PullCmpLongTerm_SetRamBlockStatus(boolean BlockChanged_Arg)
{
    PullCmpActv_Srv_PullCmpLongTerm_SetRamBlockStatus_BlockChanged = BlockChanged_Arg;
    return (Std_ReturnType)0U;
}


/*** Client Port Stubs ***/

FUNC(void, AUTOMATIC) Rte_Stub(void)
{
    PullCmpActvInit1();
    PullCmpActvPer1();
    PullCmpActvPer2();
    GetPullCmpPrm_Oper(&PullCmpActv_Cli_GetPullCmpPrm_PullCmpCmdTot, &PullCmpActv_Cli_GetPullCmpPrm_PullCmpShoTerm, &PullCmpActv_Cli_GetPullCmpPrm_PullCmpLongTerm, &PullCmpActv_Cli_GetPullCmpPrm_LrngEnad);
    RstPullCmp_Oper();
    SetPullCmpLongTerm_Oper(PullCmpActv_Cli_SetPullCmpLongTerm_PullCmpLongTerm);
    SetPullCmpShoTerm_Oper(PullCmpActv_Cli_SetPullCmpShoTerm_PullCmpShoTerm);
}

