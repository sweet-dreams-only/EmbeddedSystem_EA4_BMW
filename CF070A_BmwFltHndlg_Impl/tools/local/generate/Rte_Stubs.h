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
extern VAR(BmwFltLampReqSts1, AUTOMATIC) BmwFltHndlg_Op_BmwFltLampReqSts;
extern VAR(BmwFltLampReqTyp2, AUTOMATIC) BmwFltHndlg_Op_BmwFltLampReqTyp;

/* Arguments and Returns */


/*** Output Stubs ***/

#ifdef Rte_Write_BmwFltLampReqSts_Val
# undef Rte_Write_BmwFltLampReqSts_Val
#else
#error Rte_Write_BmwFltLampReqSts_Val is missing
#endif
#define Rte_Write_BmwFltLampReqSts_Val(data) (BmwFltHndlg_Op_BmwFltLampReqSts = (data))

#ifdef Rte_Write_BmwFltLampReqTyp_Val
# undef Rte_Write_BmwFltLampReqTyp_Val
#else
#error Rte_Write_BmwFltLampReqTyp_Val is missing
#endif
#define Rte_Write_BmwFltLampReqTyp_Val(data) (BmwFltHndlg_Op_BmwFltLampReqTyp = (data))


/*** Client Stub ***/

extern FUNC(void, AUTOMATIC) Rte_Stub(void);


#endif
