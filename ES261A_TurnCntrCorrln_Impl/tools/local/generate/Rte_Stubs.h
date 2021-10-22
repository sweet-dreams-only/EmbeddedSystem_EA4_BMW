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
extern VAR(float32, AUTOMATIC) TurnCntrCorrln_Ip_MotAgATurnCntr;
extern VAR(SigQlfr1, AUTOMATIC) TurnCntrCorrln_Ip_MotAgATurnCntrQlfr;
extern VAR(uint8, AUTOMATIC) TurnCntrCorrln_Ip_MotAgATurnCntrRollgCntr;
extern VAR(float32, AUTOMATIC) TurnCntrCorrln_Ip_MotAgBTurnCntr;
extern VAR(SigQlfr1, AUTOMATIC) TurnCntrCorrln_Ip_MotAgBTurnCntrQlfr;
extern VAR(uint8, AUTOMATIC) TurnCntrCorrln_Ip_MotAgBTurnCntrRollgCntr;

/* Outputs */
extern VAR(uint8, AUTOMATIC) TurnCntrCorrln_Op_TurnCntrCorrlnSts;
extern VAR(uint8, AUTOMATIC) TurnCntrCorrln_Op_TurnCntrIdptSig;

/* PIMs */
extern VAR(uint8, AUTOMATIC) TurnCntrCorrln_Pim_MotAgATurnCntrRollgCntPrev;
extern VAR(uint8, AUTOMATIC) TurnCntrCorrln_Pim_MotAgATurnCntrStallCntPrev;
extern VAR(uint8, AUTOMATIC) TurnCntrCorrln_Pim_MotAgBTurnCntrRollgCntPrev;
extern VAR(uint8, AUTOMATIC) TurnCntrCorrln_Pim_MotAgBTurnCntrStallCntPrev;

/* Arguments and Returns */
extern VAR(NtcNr1, AUTOMATIC) TurnCntrCorrln_Srv_GetNtcQlfrSts_NtcNr;
extern VAR(SigQlfr1, AUTOMATIC) TurnCntrCorrln_Srv_GetNtcQlfrSts_NtcQlfr;
extern VAR(Std_ReturnType, AUTOMATIC) TurnCntrCorrln_Srv_GetNtcQlfrSts_Return;
extern VAR(NtcNr1, AUTOMATIC) TurnCntrCorrln_Srv_SetNtcSts_NtcNr;
extern VAR(uint8, AUTOMATIC) TurnCntrCorrln_Srv_SetNtcSts_NtcStInfo;
extern VAR(NtcSts1, AUTOMATIC) TurnCntrCorrln_Srv_SetNtcSts_NtcSts;
extern VAR(uint16, AUTOMATIC) TurnCntrCorrln_Srv_SetNtcSts_DebStep;
extern VAR(Std_ReturnType, AUTOMATIC) TurnCntrCorrln_Srv_SetNtcSts_Return;


/*** Input Stubs ***/

#ifdef Rte_Read_MotAgATurnCntr_Val
# undef Rte_Read_MotAgATurnCntr_Val
#else
#error Rte_Read_MotAgATurnCntr_Val is missing
#endif
#define Rte_Read_MotAgATurnCntr_Val(data) (*(data) = TurnCntrCorrln_Ip_MotAgATurnCntr)

#ifdef Rte_Read_MotAgATurnCntrQlfr_Val
# undef Rte_Read_MotAgATurnCntrQlfr_Val
#else
#error Rte_Read_MotAgATurnCntrQlfr_Val is missing
#endif
#define Rte_Read_MotAgATurnCntrQlfr_Val(data) (*(data) = TurnCntrCorrln_Ip_MotAgATurnCntrQlfr)

#ifdef Rte_Read_MotAgATurnCntrRollgCntr_Val
# undef Rte_Read_MotAgATurnCntrRollgCntr_Val
#else
#error Rte_Read_MotAgATurnCntrRollgCntr_Val is missing
#endif
#define Rte_Read_MotAgATurnCntrRollgCntr_Val(data) (*(data) = TurnCntrCorrln_Ip_MotAgATurnCntrRollgCntr)

#ifdef Rte_Read_MotAgBTurnCntr_Val
# undef Rte_Read_MotAgBTurnCntr_Val
#else
#error Rte_Read_MotAgBTurnCntr_Val is missing
#endif
#define Rte_Read_MotAgBTurnCntr_Val(data) (*(data) = TurnCntrCorrln_Ip_MotAgBTurnCntr)

#ifdef Rte_Read_MotAgBTurnCntrQlfr_Val
# undef Rte_Read_MotAgBTurnCntrQlfr_Val
#else
#error Rte_Read_MotAgBTurnCntrQlfr_Val is missing
#endif
#define Rte_Read_MotAgBTurnCntrQlfr_Val(data) (*(data) = TurnCntrCorrln_Ip_MotAgBTurnCntrQlfr)

#ifdef Rte_Read_MotAgBTurnCntrRollgCntr_Val
# undef Rte_Read_MotAgBTurnCntrRollgCntr_Val
#else
#error Rte_Read_MotAgBTurnCntrRollgCntr_Val is missing
#endif
#define Rte_Read_MotAgBTurnCntrRollgCntr_Val(data) (*(data) = TurnCntrCorrln_Ip_MotAgBTurnCntrRollgCntr)


/*** Output Stubs ***/

#ifdef Rte_Write_TurnCntrCorrlnSts_Val
# undef Rte_Write_TurnCntrCorrlnSts_Val
#else
#error Rte_Write_TurnCntrCorrlnSts_Val is missing
#endif
#define Rte_Write_TurnCntrCorrlnSts_Val(data) (TurnCntrCorrln_Op_TurnCntrCorrlnSts = (data))

#ifdef Rte_Write_TurnCntrIdptSig_Val
# undef Rte_Write_TurnCntrIdptSig_Val
#else
#error Rte_Write_TurnCntrIdptSig_Val is missing
#endif
#define Rte_Write_TurnCntrIdptSig_Val(data) (TurnCntrCorrln_Op_TurnCntrIdptSig = (data))


/*** PIM Stubs ***/

#ifdef Rte_Pim_MotAgATurnCntrRollgCntPrev
# undef Rte_Pim_MotAgATurnCntrRollgCntPrev
#else
#error Rte_Pim_MotAgATurnCntrRollgCntPrev is missing
#endif
#define Rte_Pim_MotAgATurnCntrRollgCntPrev() (&TurnCntrCorrln_Pim_MotAgATurnCntrRollgCntPrev)

#ifdef Rte_Pim_MotAgATurnCntrStallCntPrev
# undef Rte_Pim_MotAgATurnCntrStallCntPrev
#else
#error Rte_Pim_MotAgATurnCntrStallCntPrev is missing
#endif
#define Rte_Pim_MotAgATurnCntrStallCntPrev() (&TurnCntrCorrln_Pim_MotAgATurnCntrStallCntPrev)

#ifdef Rte_Pim_MotAgBTurnCntrRollgCntPrev
# undef Rte_Pim_MotAgBTurnCntrRollgCntPrev
#else
#error Rte_Pim_MotAgBTurnCntrRollgCntPrev is missing
#endif
#define Rte_Pim_MotAgBTurnCntrRollgCntPrev() (&TurnCntrCorrln_Pim_MotAgBTurnCntrRollgCntPrev)

#ifdef Rte_Pim_MotAgBTurnCntrStallCntPrev
# undef Rte_Pim_MotAgBTurnCntrStallCntPrev
#else
#error Rte_Pim_MotAgBTurnCntrStallCntPrev is missing
#endif
#define Rte_Pim_MotAgBTurnCntrStallCntPrev() (&TurnCntrCorrln_Pim_MotAgBTurnCntrStallCntPrev)


/*** Client Stub ***/

extern FUNC(void, AUTOMATIC) Rte_Stub(void);


#endif
