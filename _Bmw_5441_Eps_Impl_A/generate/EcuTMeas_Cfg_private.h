/**********************************************************************************************************************
* Copyright 2017 Nxtr
* Nxtr Confidential
*
* Module File Name:   EcuTMeas_Cfg_private.h
* Module Description: Configurable Parameter declarations for EcuTMeas component
* Project           : CBD
* Author            : Shruthi Raghavan
* Generator         : artt 2.0.2.0
* Generation Time   : 30.07.2018 19:59:42
***********************************************************************************************************************
* Version Control:
* %version:           25 %
* %derived_by:        tzyksv %
*---------------------------------------------------------------------------------------------------------------------
* Date         Rev     Author    Change Description                                                            SCR#
* ---------  ------   ---------   ------------------------------------------------------------------------- ----------
* 07/14/17  	1      Shruthi   Initial Version                                                            EA4#12359
**********************************************************************************************************************/

#ifndef _CDD_ECUTMEAS_CFG_H
#define _CDD_ECUTMEAS_CFG_H
#include "Std_Types.h"

#define NROFSNSRXYPT_CNT_U08    8U

extern CONST(float32, EcuTMeas_CODE) ECUTMEAS_DFTT_DEGCGRD_F32;
extern CONST(float32, EcuTMeas_CODE) ECUTMEAS_FILTAU_HZ_F32;

extern CONST(float32, EcuTMeas_CODE) ECUTMEAS_RNGDIAGCMAX_DEGCGRD_F32;
extern CONST(float32, EcuTMeas_CODE) ECUTMEAS_RNGDIAGCMIN_DEGCGRD_F32;

extern CONST(uint16 , EcuTMeas_CODE) ECUTMEAS_NTC0X045FAILSTEP_CNT_U16;
extern CONST(uint16 , EcuTMeas_CODE) ECUTMEAS_NTC0X045PASSSTEP_CNT_U16;

extern CONST(uint16 , EcuTMeas_CODE) ECUTMEAS_ECUTX_VOLT_U3P13[NROFSNSRXYPT_CNT_U08];
extern CONST(sint16 , EcuTMeas_CODE) ECUTMEAS_ECUTY_DEGCGRD_S8P7[NROFSNSRXYPT_CNT_U08];

#endif
