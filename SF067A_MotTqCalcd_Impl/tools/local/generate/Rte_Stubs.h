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
extern VAR(uint8, AUTOMATIC) MotTqCalcd_Ip_MotAndThermProtnLoaMod;
extern VAR(float32, AUTOMATIC) MotTqCalcd_Ip_MotBackEmfConEstimd;
extern VAR(float32, AUTOMATIC) MotTqCalcd_Ip_MotCurrDax;
extern VAR(float32, AUTOMATIC) MotTqCalcd_Ip_MotCurrDaxCmd;
extern VAR(float32, AUTOMATIC) MotTqCalcd_Ip_MotCurrQax;
extern VAR(float32, AUTOMATIC) MotTqCalcd_Ip_MotCurrQaxCmd;
extern VAR(float32, AUTOMATIC) MotTqCalcd_Ip_MotInduDaxEstimd;
extern VAR(float32, AUTOMATIC) MotTqCalcd_Ip_MotInduQaxEstimd;

/* Outputs */
extern VAR(float32, AUTOMATIC) MotTqCalcd_Op_MotTqEstimd;

/* Calibrations */
extern CONST(uint8, AUTOMATIC) MotTqCalcd_Cal_SysGlbPrmMotPoleCnt;

/* Arguments and Returns */


/*** Input Stubs ***/

#ifdef Rte_Read_MotAndThermProtnLoaMod_Val
# undef Rte_Read_MotAndThermProtnLoaMod_Val
#endif
#define Rte_Read_MotAndThermProtnLoaMod_Val(data) (*(data) = MotTqCalcd_Ip_MotAndThermProtnLoaMod)

#ifdef Rte_Read_MotBackEmfConEstimd_Val
# undef Rte_Read_MotBackEmfConEstimd_Val
#endif
#define Rte_Read_MotBackEmfConEstimd_Val(data) (*(data) = MotTqCalcd_Ip_MotBackEmfConEstimd)

#ifdef Rte_Read_MotCurrDax_Val
# undef Rte_Read_MotCurrDax_Val
#endif
#define Rte_Read_MotCurrDax_Val(data) (*(data) = MotTqCalcd_Ip_MotCurrDax)

#ifdef Rte_Read_MotCurrDaxCmd_Val
# undef Rte_Read_MotCurrDaxCmd_Val
#endif
#define Rte_Read_MotCurrDaxCmd_Val(data) (*(data) = MotTqCalcd_Ip_MotCurrDaxCmd)

#ifdef Rte_Read_MotCurrQax_Val
# undef Rte_Read_MotCurrQax_Val
#endif
#define Rte_Read_MotCurrQax_Val(data) (*(data) = MotTqCalcd_Ip_MotCurrQax)

#ifdef Rte_Read_MotCurrQaxCmd_Val
# undef Rte_Read_MotCurrQaxCmd_Val
#endif
#define Rte_Read_MotCurrQaxCmd_Val(data) (*(data) = MotTqCalcd_Ip_MotCurrQaxCmd)

#ifdef Rte_Read_MotInduDaxEstimd_Val
# undef Rte_Read_MotInduDaxEstimd_Val
#endif
#define Rte_Read_MotInduDaxEstimd_Val(data) (*(data) = MotTqCalcd_Ip_MotInduDaxEstimd)

#ifdef Rte_Read_MotInduQaxEstimd_Val
# undef Rte_Read_MotInduQaxEstimd_Val
#endif
#define Rte_Read_MotInduQaxEstimd_Val(data) (*(data) = MotTqCalcd_Ip_MotInduQaxEstimd)


/*** Output Stubs ***/

#ifdef Rte_Write_MotTqEstimd_Val
# undef Rte_Write_MotTqEstimd_Val
#endif
#define Rte_Write_MotTqEstimd_Val(data) (MotTqCalcd_Op_MotTqEstimd = (data))


/*** Calibration Stubs ***/

#ifdef Rte_Prm_SysGlbPrmMotPoleCnt_Val
# undef Rte_Prm_SysGlbPrmMotPoleCnt_Val
#endif
#define Rte_Prm_SysGlbPrmMotPoleCnt_Val() (MotTqCalcd_Cal_SysGlbPrmMotPoleCnt)


/*** Client Stub ***/

extern FUNC(void, AUTOMATIC) Rte_Stub(void);


#endif
