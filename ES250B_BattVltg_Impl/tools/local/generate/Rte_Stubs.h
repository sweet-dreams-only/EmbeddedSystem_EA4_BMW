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
extern VAR(uint8, AUTOMATIC) BattVltg_Ip_BattSwdVltgCorrlnSts;
extern VAR(float32, AUTOMATIC) BattVltg_Ip_BattVltg;
extern VAR(float32, AUTOMATIC) BattVltg_Ip_BattVltgSwd1;

/* Outputs */
extern VAR(float32, AUTOMATIC) BattVltg_Op_BrdgVltg;

/* Arguments and Returns */


/*** Input Stubs ***/

#ifdef Rte_Read_BattSwdVltgCorrlnSts_Val
# undef Rte_Read_BattSwdVltgCorrlnSts_Val
#endif
#define Rte_Read_BattSwdVltgCorrlnSts_Val(data) (*(data) = BattVltg_Ip_BattSwdVltgCorrlnSts)

#ifdef Rte_Read_BattVltg_Val
# undef Rte_Read_BattVltg_Val
#endif
#define Rte_Read_BattVltg_Val(data) (*(data) = BattVltg_Ip_BattVltg)

#ifdef Rte_Read_BattVltgSwd1_Val
# undef Rte_Read_BattVltgSwd1_Val
#endif
#define Rte_Read_BattVltgSwd1_Val(data) (*(data) = BattVltg_Ip_BattVltgSwd1)


/*** Output Stubs ***/

#ifdef Rte_Write_BrdgVltg_Val
# undef Rte_Write_BrdgVltg_Val
#endif
#define Rte_Write_BrdgVltg_Val(data) (BattVltg_Op_BrdgVltg = (data))


/*** Client Stub ***/

extern FUNC(void, AUTOMATIC) Rte_Stub(void);


#endif
