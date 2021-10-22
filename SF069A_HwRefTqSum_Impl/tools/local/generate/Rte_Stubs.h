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
extern VAR(float32, AUTOMATIC) HwRefTqSum_Ip_HwTqCmdDampg;
extern VAR(float32, AUTOMATIC) HwRefTqSum_Ip_HwTqCmdEffort;
extern VAR(float32, AUTOMATIC) HwRefTqSum_Ip_HwTqCmdHys;
extern VAR(float32, AUTOMATIC) HwRefTqSum_Ip_HwTqCmdOvrl;
extern VAR(float32, AUTOMATIC) HwRefTqSum_Ip_RtnCmd;

/* Outputs */
extern VAR(float32, AUTOMATIC) HwRefTqSum_Op_HwTqCmdSum;

/* Calibrations */
extern CONST(float32, AUTOMATIC) HwRefTqSum_Cal_SysGlbPrmSysTqRat;

/* Arguments and Returns */


/*** Input Stubs ***/

#ifdef Rte_Read_HwTqCmdDampg_Val
# undef Rte_Read_HwTqCmdDampg_Val
#endif
#define Rte_Read_HwTqCmdDampg_Val(data) (*(data) = HwRefTqSum_Ip_HwTqCmdDampg)

#ifdef Rte_Read_HwTqCmdEffort_Val
# undef Rte_Read_HwTqCmdEffort_Val
#endif
#define Rte_Read_HwTqCmdEffort_Val(data) (*(data) = HwRefTqSum_Ip_HwTqCmdEffort)

#ifdef Rte_Read_HwTqCmdHys_Val
# undef Rte_Read_HwTqCmdHys_Val
#endif
#define Rte_Read_HwTqCmdHys_Val(data) (*(data) = HwRefTqSum_Ip_HwTqCmdHys)

#ifdef Rte_Read_HwTqCmdOvrl_Val
# undef Rte_Read_HwTqCmdOvrl_Val
#endif
#define Rte_Read_HwTqCmdOvrl_Val(data) (*(data) = HwRefTqSum_Ip_HwTqCmdOvrl)

#ifdef Rte_Read_RtnCmd_Val
# undef Rte_Read_RtnCmd_Val
#endif
#define Rte_Read_RtnCmd_Val(data) (*(data) = HwRefTqSum_Ip_RtnCmd)


/*** Output Stubs ***/

#ifdef Rte_Write_HwTqCmdSum_Val
# undef Rte_Write_HwTqCmdSum_Val
#endif
#define Rte_Write_HwTqCmdSum_Val(data) (HwRefTqSum_Op_HwTqCmdSum = (data))


/*** Calibration Stubs ***/

#ifdef Rte_Prm_SysGlbPrmSysTqRat_Val
# undef Rte_Prm_SysGlbPrmSysTqRat_Val
#endif
#define Rte_Prm_SysGlbPrmSysTqRat_Val() (HwRefTqSum_Cal_SysGlbPrmSysTqRat)


/*** Client Stub ***/

extern FUNC(void, AUTOMATIC) Rte_Stub(void);


#endif
