/**********************************************************************************************************************
* Copyright 2017 Nxtr
* Nxtr Confidential
*
* Module File Name:   EcuTMeas_Cfg_private.c
* Module Description: Configurable Parameter definitions for EcuTMeas component
* Project           : CBD
* Author            : Shruthi Raghavan
* Generator         : artt 2.0.2.0
* Generation Time   : 30.07.2018 19:59:40
***********************************************************************************************************************
* Version Control:
* %version:           25 %
* %derived_by:        tzyksv %
*---------------------------------------------------------------------------------------------------------------------
* Date         Rev     Author    Change Description                                                            SCR#
* ---------  ------   ---------   ------------------------------------------------------------------------- ----------
* 08/07/17  	1      Shruthi   Initial Version                                                            EA4#12359
* 09/26/17      2      BRB       Updated float32 to fixed point conversion logic                            
**********************************************************************************************************************/


#include "EcuTMeas_Cfg_private.h"

/* MISRA-C:2004 Rule 19.1  [NXTRDEV 19.1.1 ]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */

#define EcuTMeas_START_SEC_CODE
#include "EcuTMeas_MemMap.h"

CONST(float32, EcuTMeas_CODE) ECUTMEAS_DFTT_DEGCGRD_F32 = (60.0000F);
CONST(float32, EcuTMeas_CODE) ECUTMEAS_FILTAU_HZ_F32    = (100.0000F);

CONST(float32, EcuTMeas_CODE) ECUTMEAS_RNGDIAGCMAX_DEGCGRD_F32  = (125.0000F);
CONST(float32, EcuTMeas_CODE) ECUTMEAS_RNGDIAGCMIN_DEGCGRD_F32  = (-40.0000F);

CONST(uint16 , EcuTMeas_CODE) ECUTMEAS_NTC0X045FAILSTEP_CNT_U16 = 3000U;
CONST(uint16 , EcuTMeas_CODE) ECUTMEAS_NTC0X045PASSSTEP_CNT_U16 = 3000U;

CONST(uint16 , EcuTMeas_CODE) ECUTMEAS_ECUTX_VOLT_U3P13[NROFSNSRXYPT_CNT_U08] = { 913U, 10846U, 10897U, 10948U, 10999U, 11051U, 11102U, 11153U};
CONST(sint16 , EcuTMeas_CODE) ECUTMEAS_ECUTY_DEGCGRD_S8P7[NROFSNSRXYPT_CNT_U08] = { -6400, 18432, 18560, 18688, 18816, 18944, 19072, 19200};

#define EcuTMeas_STOP_SEC_CODE
#include "EcuTMeas_MemMap.h"
