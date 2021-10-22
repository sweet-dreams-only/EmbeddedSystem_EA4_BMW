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
extern VAR(uint32, AUTOMATIC) DmaCfgAndUse_Ip_MotAg0SnsrCfgAdr;

/* PIMs */
extern VAR(uint32, AUTOMATIC) DmaCfgAndUse_Pim_d2MilliSecAdcActDmaTrfTi;
extern VAR(uint32, AUTOMATIC) DmaCfgAndUse_Pim_DmaCfgAndUse2MilliSecAdcMaxDmaTrfTi;
extern VAR(uint32, AUTOMATIC) DmaCfgAndUse_Pim_DmaCfgAndUse2MilliSecAdcStrtTi;
extern VAR(uint32, AUTOMATIC) DmaCfgAndUse_Pim_MotAg0ReadPtrRst;
extern VAR(uint32, AUTOMATIC) DmaCfgAndUse_Pim_MotAg0SnsrCfgAdrStord;
extern VAR(uint32, AUTOMATIC) DmaCfgAndUse_Pim_MotAg0TrsmStrt;
extern VAR(uint32, AUTOMATIC) DmaCfgAndUse_Pim_MotAg1ReadPtrRst;
extern VAR(uint32, AUTOMATIC) DmaCfgAndUse_Pim_MotAg1SnsrCfgAdrStord;
extern VAR(uint32, AUTOMATIC) DmaCfgAndUse_Pim_MotAg1TrsmStrt;

/* Arguments and Returns */
extern VAR(uint32, AUTOMATIC) DmaCfgAndUse_Srv_GetRefTmr1MicroSec32bit_RefTmr;
extern VAR(uint32, AUTOMATIC) DmaCfgAndUse_Srv_GetTiSpan1MicroSec32bit_RefTmr;
extern VAR(uint32, AUTOMATIC) DmaCfgAndUse_Srv_GetTiSpan1MicroSec32bit_TiSpan;
extern VAR(Std_ReturnType, AUTOMATIC) DmaCfgAndUse_Srv_GetTiSpan1MicroSec32bit_Return;
extern VAR(uint32, AUTOMATIC) DmaCfgAndUse_Srv_ReadErrInjReg_ErrId;
extern VAR(Std_ReturnType, AUTOMATIC) DmaCfgAndUse_Cli_DmaWaitForMotCtrlTo2MilliSecTrf_Return;
extern VAR(Std_ReturnType, AUTOMATIC) DmaCfgAndUse_Cli_MotAg0SnsrCfgDmaStrt_Return;


/*** Input Stubs ***/

#ifdef Rte_Read_MotAg0SnsrCfgAdr_Val
# undef Rte_Read_MotAg0SnsrCfgAdr_Val
#else
#error Rte_Read_MotAg0SnsrCfgAdr_Val is missing
#endif
#define Rte_Read_MotAg0SnsrCfgAdr_Val(data) (*(data) = DmaCfgAndUse_Ip_MotAg0SnsrCfgAdr)


/*** PIM Stubs ***/

#ifdef Rte_Pim_d2MilliSecAdcActDmaTrfTi
# undef Rte_Pim_d2MilliSecAdcActDmaTrfTi
#else
#error Rte_Pim_d2MilliSecAdcActDmaTrfTi is missing
#endif
#define Rte_Pim_d2MilliSecAdcActDmaTrfTi() (&DmaCfgAndUse_Pim_d2MilliSecAdcActDmaTrfTi)

#ifdef Rte_Pim_DmaCfgAndUse2MilliSecAdcMaxDmaTrfTi
# undef Rte_Pim_DmaCfgAndUse2MilliSecAdcMaxDmaTrfTi
#else
#error Rte_Pim_DmaCfgAndUse2MilliSecAdcMaxDmaTrfTi is missing
#endif
#define Rte_Pim_DmaCfgAndUse2MilliSecAdcMaxDmaTrfTi() (&DmaCfgAndUse_Pim_DmaCfgAndUse2MilliSecAdcMaxDmaTrfTi)

#ifdef Rte_Pim_DmaCfgAndUse2MilliSecAdcStrtTi
# undef Rte_Pim_DmaCfgAndUse2MilliSecAdcStrtTi
#else
#error Rte_Pim_DmaCfgAndUse2MilliSecAdcStrtTi is missing
#endif
#define Rte_Pim_DmaCfgAndUse2MilliSecAdcStrtTi() (&DmaCfgAndUse_Pim_DmaCfgAndUse2MilliSecAdcStrtTi)

#ifdef Rte_Pim_MotAg0ReadPtrRst
# undef Rte_Pim_MotAg0ReadPtrRst
#else
#error Rte_Pim_MotAg0ReadPtrRst is missing
#endif
#define Rte_Pim_MotAg0ReadPtrRst() (&DmaCfgAndUse_Pim_MotAg0ReadPtrRst)

#ifdef Rte_Pim_MotAg0SnsrCfgAdrStord
# undef Rte_Pim_MotAg0SnsrCfgAdrStord
#else
#error Rte_Pim_MotAg0SnsrCfgAdrStord is missing
#endif
#define Rte_Pim_MotAg0SnsrCfgAdrStord() (&DmaCfgAndUse_Pim_MotAg0SnsrCfgAdrStord)

#ifdef Rte_Pim_MotAg0TrsmStrt
# undef Rte_Pim_MotAg0TrsmStrt
#else
#error Rte_Pim_MotAg0TrsmStrt is missing
#endif
#define Rte_Pim_MotAg0TrsmStrt() (&DmaCfgAndUse_Pim_MotAg0TrsmStrt)

#ifdef Rte_Pim_MotAg1ReadPtrRst
# undef Rte_Pim_MotAg1ReadPtrRst
#else
#error Rte_Pim_MotAg1ReadPtrRst is missing
#endif
#define Rte_Pim_MotAg1ReadPtrRst() (&DmaCfgAndUse_Pim_MotAg1ReadPtrRst)

#ifdef Rte_Pim_MotAg1SnsrCfgAdrStord
# undef Rte_Pim_MotAg1SnsrCfgAdrStord
#else
#error Rte_Pim_MotAg1SnsrCfgAdrStord is missing
#endif
#define Rte_Pim_MotAg1SnsrCfgAdrStord() (&DmaCfgAndUse_Pim_MotAg1SnsrCfgAdrStord)

#ifdef Rte_Pim_MotAg1TrsmStrt
# undef Rte_Pim_MotAg1TrsmStrt
#else
#error Rte_Pim_MotAg1TrsmStrt is missing
#endif
#define Rte_Pim_MotAg1TrsmStrt() (&DmaCfgAndUse_Pim_MotAg1TrsmStrt)


/*** Client Stub ***/

extern FUNC(void, AUTOMATIC) Rte_Stub(void);


#endif
