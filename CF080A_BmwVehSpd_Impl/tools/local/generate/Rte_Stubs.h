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
extern VAR(float32, AUTOMATIC) BmwVehSpd_Ip_BmwCogVehSpd;
extern VAR(BmwCogVehSpdQlfr1, AUTOMATIC) BmwVehSpd_Ip_BmwCogVehSpdQlfr;
extern VAR(boolean, AUTOMATIC) BmwVehSpd_Ip_BmwCogVehSpdQlfrVld;
extern VAR(boolean, AUTOMATIC) BmwVehSpd_Ip_BmwCogVehSpdVld;
extern VAR(BmwNearStillVehSpdSts1, AUTOMATIC) BmwVehSpd_Ip_BmwNearStillVehSpdSts;
extern VAR(boolean, AUTOMATIC) BmwVehSpd_Ip_BmwNearStillVehSpdStsVld;
extern VAR(BmwPinionAgQlfr1, AUTOMATIC) BmwVehSpd_Ip_BmwPinionAgQlfr;

/* Outputs */
extern VAR(BmwSecurVehSpdSts1, AUTOMATIC) BmwVehSpd_Op_BmwSecurVehSpdSts;
extern VAR(float32, AUTOMATIC) BmwVehSpd_Op_VehSpd;
extern VAR(boolean, AUTOMATIC) BmwVehSpd_Op_VehSpdVld;

/* Calibrations */
extern CONST(u16p0, AUTOMATIC) BmwVehSpd_Cal_BmwVehSpdBmwSecurVehSpdStsSigValVldDurnTiVal;
extern CONST(float32, AUTOMATIC) BmwVehSpd_Cal_BmwVehSpdNearStillSubVehSpd;
extern CONST(float32, AUTOMATIC) BmwVehSpd_Cal_BmwVehSpdRunngSubVehSpd;
extern CONST(float32, AUTOMATIC) BmwVehSpd_Cal_BmwVehSpdSecurVehSpdInvldRateLim;
extern CONST(float32, AUTOMATIC) BmwVehSpd_Cal_BmwVehSpdSecurVehSpdVldRateLim;

/* PIMs */
extern VAR(uint32, AUTOMATIC) BmwVehSpd_Pim_BmwSecurVehSpdStsSigValVldDurn;
extern VAR(boolean, AUTOMATIC) BmwVehSpd_Pim_SpdDifChkFlg;
extern VAR(float32, AUTOMATIC) BmwVehSpd_Pim_VehSpdLimPrev;

/* Arguments and Returns */
extern VAR(uint32, AUTOMATIC) BmwVehSpd_Srv_GetRefTmr100MicroSec32bit_RefTmr;
extern VAR(uint32, AUTOMATIC) BmwVehSpd_Srv_GetTiSpan100MicroSec32bit_RefTmr;
extern VAR(uint32, AUTOMATIC) BmwVehSpd_Srv_GetTiSpan100MicroSec32bit_TiSpan;


/*** Input Stubs ***/

#ifdef Rte_Read_BmwCogVehSpd_Val
# undef Rte_Read_BmwCogVehSpd_Val
#else
#error Rte_Read_BmwCogVehSpd_Val is missing
#endif
#define Rte_Read_BmwCogVehSpd_Val(data) (*(data) = BmwVehSpd_Ip_BmwCogVehSpd)

#ifdef Rte_Read_BmwCogVehSpdQlfr_Val
# undef Rte_Read_BmwCogVehSpdQlfr_Val
#else
#error Rte_Read_BmwCogVehSpdQlfr_Val is missing
#endif
#define Rte_Read_BmwCogVehSpdQlfr_Val(data) (*(data) = BmwVehSpd_Ip_BmwCogVehSpdQlfr)

#ifdef Rte_Read_BmwCogVehSpdQlfrVld_Logl
# undef Rte_Read_BmwCogVehSpdQlfrVld_Logl
#else
#error Rte_Read_BmwCogVehSpdQlfrVld_Logl is missing
#endif
#define Rte_Read_BmwCogVehSpdQlfrVld_Logl(data) (*(data) = BmwVehSpd_Ip_BmwCogVehSpdQlfrVld)

#ifdef Rte_Read_BmwCogVehSpdVld_Logl
# undef Rte_Read_BmwCogVehSpdVld_Logl
#else
#error Rte_Read_BmwCogVehSpdVld_Logl is missing
#endif
#define Rte_Read_BmwCogVehSpdVld_Logl(data) (*(data) = BmwVehSpd_Ip_BmwCogVehSpdVld)

#ifdef Rte_Read_BmwNearStillVehSpdSts_Val
# undef Rte_Read_BmwNearStillVehSpdSts_Val
#else
#error Rte_Read_BmwNearStillVehSpdSts_Val is missing
#endif
#define Rte_Read_BmwNearStillVehSpdSts_Val(data) (*(data) = BmwVehSpd_Ip_BmwNearStillVehSpdSts)

#ifdef Rte_Read_BmwNearStillVehSpdStsVld_Logl
# undef Rte_Read_BmwNearStillVehSpdStsVld_Logl
#else
#error Rte_Read_BmwNearStillVehSpdStsVld_Logl is missing
#endif
#define Rte_Read_BmwNearStillVehSpdStsVld_Logl(data) (*(data) = BmwVehSpd_Ip_BmwNearStillVehSpdStsVld)

#ifdef Rte_Read_BmwPinionAgQlfr_Val
# undef Rte_Read_BmwPinionAgQlfr_Val
#else
#error Rte_Read_BmwPinionAgQlfr_Val is missing
#endif
#define Rte_Read_BmwPinionAgQlfr_Val(data) (*(data) = BmwVehSpd_Ip_BmwPinionAgQlfr)


/*** Output Stubs ***/

#ifdef Rte_Write_BmwSecurVehSpdSts_Val
# undef Rte_Write_BmwSecurVehSpdSts_Val
#else
#error Rte_Write_BmwSecurVehSpdSts_Val is missing
#endif
#define Rte_Write_BmwSecurVehSpdSts_Val(data) (BmwVehSpd_Op_BmwSecurVehSpdSts = (data))

#ifdef Rte_Write_VehSpd_Val
# undef Rte_Write_VehSpd_Val
#else
#error Rte_Write_VehSpd_Val is missing
#endif
#define Rte_Write_VehSpd_Val(data) (BmwVehSpd_Op_VehSpd = (data))

#ifdef Rte_Write_VehSpdVld_Logl
# undef Rte_Write_VehSpdVld_Logl
#else
#error Rte_Write_VehSpdVld_Logl is missing
#endif
#define Rte_Write_VehSpdVld_Logl(data) (BmwVehSpd_Op_VehSpdVld = (data))


/*** Calibration Stubs ***/

#ifdef Rte_Prm_BmwVehSpdBmwSecurVehSpdStsSigValVldDurnTiVal_Val
# undef Rte_Prm_BmwVehSpdBmwSecurVehSpdStsSigValVldDurnTiVal_Val
#else
#error Rte_Prm_BmwVehSpdBmwSecurVehSpdStsSigValVldDurnTiVal_Val is missing
#endif
#define Rte_Prm_BmwVehSpdBmwSecurVehSpdStsSigValVldDurnTiVal_Val() (BmwVehSpd_Cal_BmwVehSpdBmwSecurVehSpdStsSigValVldDurnTiVal)

#ifdef Rte_Prm_BmwVehSpdNearStillSubVehSpd_Val
# undef Rte_Prm_BmwVehSpdNearStillSubVehSpd_Val
#else
#error Rte_Prm_BmwVehSpdNearStillSubVehSpd_Val is missing
#endif
#define Rte_Prm_BmwVehSpdNearStillSubVehSpd_Val() (BmwVehSpd_Cal_BmwVehSpdNearStillSubVehSpd)

#ifdef Rte_Prm_BmwVehSpdRunngSubVehSpd_Val
# undef Rte_Prm_BmwVehSpdRunngSubVehSpd_Val
#else
#error Rte_Prm_BmwVehSpdRunngSubVehSpd_Val is missing
#endif
#define Rte_Prm_BmwVehSpdRunngSubVehSpd_Val() (BmwVehSpd_Cal_BmwVehSpdRunngSubVehSpd)

#ifdef Rte_Prm_BmwVehSpdSecurVehSpdInvldRateLim_Val
# undef Rte_Prm_BmwVehSpdSecurVehSpdInvldRateLim_Val
#else
#error Rte_Prm_BmwVehSpdSecurVehSpdInvldRateLim_Val is missing
#endif
#define Rte_Prm_BmwVehSpdSecurVehSpdInvldRateLim_Val() (BmwVehSpd_Cal_BmwVehSpdSecurVehSpdInvldRateLim)

#ifdef Rte_Prm_BmwVehSpdSecurVehSpdVldRateLim_Val
# undef Rte_Prm_BmwVehSpdSecurVehSpdVldRateLim_Val
#else
#error Rte_Prm_BmwVehSpdSecurVehSpdVldRateLim_Val is missing
#endif
#define Rte_Prm_BmwVehSpdSecurVehSpdVldRateLim_Val() (BmwVehSpd_Cal_BmwVehSpdSecurVehSpdVldRateLim)


/*** PIM Stubs ***/

#ifdef Rte_Pim_BmwSecurVehSpdStsSigValVldDurn
# undef Rte_Pim_BmwSecurVehSpdStsSigValVldDurn
#else
#error Rte_Pim_BmwSecurVehSpdStsSigValVldDurn is missing
#endif
#define Rte_Pim_BmwSecurVehSpdStsSigValVldDurn() (&BmwVehSpd_Pim_BmwSecurVehSpdStsSigValVldDurn)

#ifdef Rte_Pim_SpdDifChkFlg
# undef Rte_Pim_SpdDifChkFlg
#else
#error Rte_Pim_SpdDifChkFlg is missing
#endif
#define Rte_Pim_SpdDifChkFlg() (&BmwVehSpd_Pim_SpdDifChkFlg)

#ifdef Rte_Pim_VehSpdLimPrev
# undef Rte_Pim_VehSpdLimPrev
#else
#error Rte_Pim_VehSpdLimPrev is missing
#endif
#define Rte_Pim_VehSpdLimPrev() (&BmwVehSpd_Pim_VehSpdLimPrev)


/*** Client Stub ***/

extern FUNC(void, AUTOMATIC) Rte_Stub(void);


#endif
