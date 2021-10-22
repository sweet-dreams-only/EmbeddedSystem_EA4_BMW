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

/* Inputs */
extern VAR(sint8, AUTOMATIC) MotAg3Meas_Ip_MotAgMecl3Polarity;

/* Arguments and Returns */
extern VAR(u0p16, AUTOMATIC) MotAg3Meas_Cli_GetMotAg3Mecl_MotAgMecl;


/*** Input Stubs ***/

#ifdef Rte_Read_MotAgMecl3Polarity_Val
# undef Rte_Read_MotAgMecl3Polarity_Val
#else
#error Rte_Read_MotAgMecl3Polarity_Val is missing
#endif
#define Rte_Read_MotAgMecl3Polarity_Val(data) (*(data) = MotAg3Meas_Ip_MotAgMecl3Polarity)


/*** Client Stub ***/

extern FUNC(void, AUTOMATIC) Rte_Stub(void);


#endif
