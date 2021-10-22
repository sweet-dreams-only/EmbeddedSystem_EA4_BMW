/******************************************************************************************************************
* Copyright 2016 Nxtr
* Nxtr Confidential
*
* Module File Name:   Rte_Stubs.c
* Module Description: Stubs for Polyspace analysis.  Generated from TL109A_SwcSuprt.
* Project:            CBD
* Author:             Owen Tosh
******************************************************************************************************************/


#include "Rte_CDD_MotAgCmp.h"
#include "float.h"


/*** Server Port Stubs ***/

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_MotAgCmp_MotAgCmpMotAgBackEmf_SetRamBlockStatus(boolean BlockChanged_Arg)
{
    MotAgCmp_Srv_MotAgCmpMotAgBackEmf_SetRamBlockStatus_BlockChanged = BlockChanged_Arg;
    return MotAgCmp_Srv_MotAgCmpMotAgBackEmf_SetRamBlockStatus_Return;
}


/*** Client Port Stubs ***/

FUNC(void, AUTOMATIC) Rte_Stub(void)
{
    MotAgCmpInit1();
    MotAgCmpPer1();
    MotAgCmpPer2();
    MotAgCmpBackEmfRead_Oper(&MotAgCmp_Cli_MotAgCmpBackEmfRead_MotAgBackEmfRead);
    MotAgCmpBackEmfWr_Oper(MotAgCmp_Cli_MotAgCmpBackEmfWr_MotAgCmpBackEmfWrData);
}

