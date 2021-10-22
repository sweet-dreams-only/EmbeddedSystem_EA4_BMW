/******************************************************************************************************************
* Copyright 2016 Nxtr
* Nxtr Confidential
*
* Module File Name:   Rte_Stubs.c
* Module Description: Stubs for Polyspace analysis.  Generated from TL109A_SwcSuprt.
* Project:            CBD
* Author:             Owen Tosh
******************************************************************************************************************/


#include "Rte_BmwTrfcJamAssiDampg.h"
#include "float.h"


/*** Server Port Stubs ***/

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwTrfcJamAssiDampg_GetRefTmr100MicroSec32bit_Oper(uint32 * RefTmr_Arg)
{
    *RefTmr_Arg = BmwTrfcJamAssiDampg_Srv_GetRefTmr100MicroSec32bit_RefTmr;
    return (Std_ReturnType)0U;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwTrfcJamAssiDampg_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 * TiSpan_Arg)
{
    BmwTrfcJamAssiDampg_Srv_GetTiSpan100MicroSec32bit_RefTmr = RefTmr_Arg;
    *TiSpan_Arg = BmwTrfcJamAssiDampg_Srv_GetTiSpan100MicroSec32bit_TiSpan;
    return (Std_ReturnType)0U;
}


/*** Client Port Stubs ***/

FUNC(void, AUTOMATIC) Rte_Stub(void)
{
    BmwTrfcJamAssiDampgInit1();
    BmwTrfcJamAssiDampgPer1();
}

