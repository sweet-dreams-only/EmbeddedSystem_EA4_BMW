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
extern VAR(BmwHaptcFbIntenNr1, AUTOMATIC) BmwHaptcFb_Ip_BmwHaptcFbIntenNr;
extern VAR(boolean, AUTOMATIC) BmwHaptcFb_Ip_BmwHaptcFbIntenNrVld;
extern VAR(BmwHaptcFbPatNr1, AUTOMATIC) BmwHaptcFb_Ip_BmwHaptcFbPatNr;
extern VAR(boolean, AUTOMATIC) BmwHaptcFb_Ip_BmwHaptcFbPatNrVld;
extern VAR(boolean, AUTOMATIC) BmwHaptcFb_Ip_DiagcStsNonRcvrlReqDiFltPrsnt;
extern VAR(boolean, AUTOMATIC) BmwHaptcFb_Ip_HaptcFbEna;
extern VAR(boolean, AUTOMATIC) BmwHaptcFb_Ip_HwOscnActv;
extern VAR(boolean, AUTOMATIC) BmwHaptcFb_Ip_HwOscnDcThdExcdd;
extern VAR(float32, AUTOMATIC) BmwHaptcFb_Ip_HwTq;
extern VAR(StsSteerAssi1, AUTOMATIC) BmwHaptcFb_Ip_StsSteerAssi;
extern VAR(float32, AUTOMATIC) BmwHaptcFb_Ip_ThermRednFac;
extern VAR(float32, AUTOMATIC) BmwHaptcFb_Ip_VehSpd;
extern VAR(boolean, AUTOMATIC) BmwHaptcFb_Ip_VehSpdVld;

/* Outputs */
extern VAR(HaptcFbSt1, AUTOMATIC) BmwHaptcFb_Op_HaptcFbSt;
extern VAR(boolean, AUTOMATIC) BmwHaptcFb_Op_HwOscnEna;
extern VAR(float32, AUTOMATIC) BmwHaptcFb_Op_HwOscnFallRampRate;
extern VAR(float32, AUTOMATIC) BmwHaptcFb_Op_HwOscnFrq;
extern VAR(float32, AUTOMATIC) BmwHaptcFb_Op_HwOscnMotAmp;
extern VAR(float32, AUTOMATIC) BmwHaptcFb_Op_HwOscnRisngRampRate;

/* Calibrations */
extern CONST(u4p12, AUTOMATIC) BmwHaptcFb_Cal_BmwHaptcFbAmpAndIntenHwTqTblX[12];
extern CONST(u4p12, AUTOMATIC) BmwHaptcFb_Cal_BmwHaptcFbAmpBilnrSeln[13];
extern CONST(u4p12, AUTOMATIC) BmwHaptcFb_Cal_BmwHaptcFbAmpSelnTblY[13][13];
extern CONST(float32, AUTOMATIC) BmwHaptcFb_Cal_BmwHaptcFbEpsDegradedFltThd;
extern CONST(u6p10, AUTOMATIC) BmwHaptcFb_Cal_BmwHaptcFbFrqBilnrSeln[13];
extern CONST(u6p10, AUTOMATIC) BmwHaptcFb_Cal_BmwHaptcFbFrqSelnTblY[13][13];
extern CONST(u6p10, AUTOMATIC) BmwHaptcFb_Cal_BmwHaptcFbHwTqFrqTblY[12][12];
extern CONST(uint16, AUTOMATIC) BmwHaptcFb_Cal_BmwHaptcFbIntenSelnTblX[13];
extern CONST(u4p12, AUTOMATIC) BmwHaptcFb_Cal_BmwHaptcFbMotTqAmpTblY[12][12];
extern CONST(float32, AUTOMATIC) BmwHaptcFb_Cal_BmwHaptcFbPatActvTiTblY[11];
extern CONST(float32, AUTOMATIC) BmwHaptcFb_Cal_BmwHaptcFbPatPasTiTblY[11];
extern CONST(float32, AUTOMATIC) BmwHaptcFb_Cal_BmwHaptcFbPatRisngSlewTblY[11];
extern CONST(u9p7, AUTOMATIC) BmwHaptcFb_Cal_SysGlbPrmVehSpdBilnrSeln[12];

/* PIMs */
extern VAR(BmwHaptcFbIntenNr1, AUTOMATIC) BmwHaptcFb_Pim_CurrInten;
extern VAR(BmwHaptcFbPatNr1, AUTOMATIC) BmwHaptcFb_Pim_CurrPat;
extern VAR(uint32, AUTOMATIC) BmwHaptcFb_Pim_TqOscnEnaTmr;

/* Arguments and Returns */
extern VAR(uint32, AUTOMATIC) BmwHaptcFb_Srv_GetRefTmr100MicroSec32bit_RefTmr;
extern VAR(uint32, AUTOMATIC) BmwHaptcFb_Srv_GetTiSpan100MicroSec32bit_RefTmr;
extern VAR(uint32, AUTOMATIC) BmwHaptcFb_Srv_GetTiSpan100MicroSec32bit_TiSpan;


/*** Input Stubs ***/

#ifdef Rte_Read_BmwHaptcFbIntenNr_Val
# undef Rte_Read_BmwHaptcFbIntenNr_Val
#else
#error Rte_Read_BmwHaptcFbIntenNr_Val is missing
#endif
#define Rte_Read_BmwHaptcFbIntenNr_Val(data) (*(data) = BmwHaptcFb_Ip_BmwHaptcFbIntenNr)

#ifdef Rte_Read_BmwHaptcFbIntenNrVld_Logl
# undef Rte_Read_BmwHaptcFbIntenNrVld_Logl
#else
#error Rte_Read_BmwHaptcFbIntenNrVld_Logl is missing
#endif
#define Rte_Read_BmwHaptcFbIntenNrVld_Logl(data) (*(data) = BmwHaptcFb_Ip_BmwHaptcFbIntenNrVld)

#ifdef Rte_Read_BmwHaptcFbPatNr_Val
# undef Rte_Read_BmwHaptcFbPatNr_Val
#else
#error Rte_Read_BmwHaptcFbPatNr_Val is missing
#endif
#define Rte_Read_BmwHaptcFbPatNr_Val(data) (*(data) = BmwHaptcFb_Ip_BmwHaptcFbPatNr)

#ifdef Rte_Read_BmwHaptcFbPatNrVld_Logl
# undef Rte_Read_BmwHaptcFbPatNrVld_Logl
#else
#error Rte_Read_BmwHaptcFbPatNrVld_Logl is missing
#endif
#define Rte_Read_BmwHaptcFbPatNrVld_Logl(data) (*(data) = BmwHaptcFb_Ip_BmwHaptcFbPatNrVld)

#ifdef Rte_Read_DiagcStsNonRcvrlReqDiFltPrsnt_Logl
# undef Rte_Read_DiagcStsNonRcvrlReqDiFltPrsnt_Logl
#else
#error Rte_Read_DiagcStsNonRcvrlReqDiFltPrsnt_Logl is missing
#endif
#define Rte_Read_DiagcStsNonRcvrlReqDiFltPrsnt_Logl(data) (*(data) = BmwHaptcFb_Ip_DiagcStsNonRcvrlReqDiFltPrsnt)

#ifdef Rte_Read_HaptcFbEna_Logl
# undef Rte_Read_HaptcFbEna_Logl
#else
#error Rte_Read_HaptcFbEna_Logl is missing
#endif
#define Rte_Read_HaptcFbEna_Logl(data) (*(data) = BmwHaptcFb_Ip_HaptcFbEna)

#ifdef Rte_Read_HwOscnActv_Logl
# undef Rte_Read_HwOscnActv_Logl
#else
#error Rte_Read_HwOscnActv_Logl is missing
#endif
#define Rte_Read_HwOscnActv_Logl(data) (*(data) = BmwHaptcFb_Ip_HwOscnActv)

#ifdef Rte_Read_HwOscnDcThdExcdd_Logl
# undef Rte_Read_HwOscnDcThdExcdd_Logl
#else
#error Rte_Read_HwOscnDcThdExcdd_Logl is missing
#endif
#define Rte_Read_HwOscnDcThdExcdd_Logl(data) (*(data) = BmwHaptcFb_Ip_HwOscnDcThdExcdd)

#ifdef Rte_Read_HwTq_Val
# undef Rte_Read_HwTq_Val
#else
#error Rte_Read_HwTq_Val is missing
#endif
#define Rte_Read_HwTq_Val(data) (*(data) = BmwHaptcFb_Ip_HwTq)

#ifdef Rte_Read_StsSteerAssi_Val
# undef Rte_Read_StsSteerAssi_Val
#else
#error Rte_Read_StsSteerAssi_Val is missing
#endif
#define Rte_Read_StsSteerAssi_Val(data) (*(data) = BmwHaptcFb_Ip_StsSteerAssi)

#ifdef Rte_Read_ThermRednFac_Val
# undef Rte_Read_ThermRednFac_Val
#else
#error Rte_Read_ThermRednFac_Val is missing
#endif
#define Rte_Read_ThermRednFac_Val(data) (*(data) = BmwHaptcFb_Ip_ThermRednFac)

#ifdef Rte_Read_VehSpd_Val
# undef Rte_Read_VehSpd_Val
#else
#error Rte_Read_VehSpd_Val is missing
#endif
#define Rte_Read_VehSpd_Val(data) (*(data) = BmwHaptcFb_Ip_VehSpd)

#ifdef Rte_Read_VehSpdVld_Logl
# undef Rte_Read_VehSpdVld_Logl
#else
#error Rte_Read_VehSpdVld_Logl is missing
#endif
#define Rte_Read_VehSpdVld_Logl(data) (*(data) = BmwHaptcFb_Ip_VehSpdVld)


/*** Output Stubs ***/

#ifdef Rte_Write_HaptcFbSt_Val
# undef Rte_Write_HaptcFbSt_Val
#else
#error Rte_Write_HaptcFbSt_Val is missing
#endif
#define Rte_Write_HaptcFbSt_Val(data) (BmwHaptcFb_Op_HaptcFbSt = (data))

#ifdef Rte_Write_HwOscnEna_Logl
# undef Rte_Write_HwOscnEna_Logl
#else
#error Rte_Write_HwOscnEna_Logl is missing
#endif
#define Rte_Write_HwOscnEna_Logl(data) (BmwHaptcFb_Op_HwOscnEna = (data))

#ifdef Rte_Write_HwOscnFallRampRate_Val
# undef Rte_Write_HwOscnFallRampRate_Val
#else
#error Rte_Write_HwOscnFallRampRate_Val is missing
#endif
#define Rte_Write_HwOscnFallRampRate_Val(data) (BmwHaptcFb_Op_HwOscnFallRampRate = (data))

#ifdef Rte_Write_HwOscnFrq_Val
# undef Rte_Write_HwOscnFrq_Val
#else
#error Rte_Write_HwOscnFrq_Val is missing
#endif
#define Rte_Write_HwOscnFrq_Val(data) (BmwHaptcFb_Op_HwOscnFrq = (data))

#ifdef Rte_Write_HwOscnMotAmp_Val
# undef Rte_Write_HwOscnMotAmp_Val
#else
#error Rte_Write_HwOscnMotAmp_Val is missing
#endif
#define Rte_Write_HwOscnMotAmp_Val(data) (BmwHaptcFb_Op_HwOscnMotAmp = (data))

#ifdef Rte_Write_HwOscnRisngRampRate_Val
# undef Rte_Write_HwOscnRisngRampRate_Val
#else
#error Rte_Write_HwOscnRisngRampRate_Val is missing
#endif
#define Rte_Write_HwOscnRisngRampRate_Val(data) (BmwHaptcFb_Op_HwOscnRisngRampRate = (data))


/*** Calibration Stubs ***/

#ifdef Rte_Prm_BmwHaptcFbAmpAndIntenHwTqTblX_Ary1D
# undef Rte_Prm_BmwHaptcFbAmpAndIntenHwTqTblX_Ary1D
#else
#error Rte_Prm_BmwHaptcFbAmpAndIntenHwTqTblX_Ary1D is missing
#endif
#define Rte_Prm_BmwHaptcFbAmpAndIntenHwTqTblX_Ary1D() (&(BmwHaptcFb_Cal_BmwHaptcFbAmpAndIntenHwTqTblX[0]))

#ifdef Rte_Prm_BmwHaptcFbAmpBilnrSeln_Ary1D
# undef Rte_Prm_BmwHaptcFbAmpBilnrSeln_Ary1D
#else
#error Rte_Prm_BmwHaptcFbAmpBilnrSeln_Ary1D is missing
#endif
#define Rte_Prm_BmwHaptcFbAmpBilnrSeln_Ary1D() (&(BmwHaptcFb_Cal_BmwHaptcFbAmpBilnrSeln[0]))

#ifdef Rte_Prm_BmwHaptcFbAmpSelnTblY_Ary2D
# undef Rte_Prm_BmwHaptcFbAmpSelnTblY_Ary2D
#else
#error Rte_Prm_BmwHaptcFbAmpSelnTblY_Ary2D is missing
#endif
#define Rte_Prm_BmwHaptcFbAmpSelnTblY_Ary2D() (&(BmwHaptcFb_Cal_BmwHaptcFbAmpSelnTblY[0][0]))

#ifdef Rte_Prm_BmwHaptcFbEpsDegradedFltThd_Val
# undef Rte_Prm_BmwHaptcFbEpsDegradedFltThd_Val
#else
#error Rte_Prm_BmwHaptcFbEpsDegradedFltThd_Val is missing
#endif
#define Rte_Prm_BmwHaptcFbEpsDegradedFltThd_Val() (BmwHaptcFb_Cal_BmwHaptcFbEpsDegradedFltThd)

#ifdef Rte_Prm_BmwHaptcFbFrqBilnrSeln_Ary1D
# undef Rte_Prm_BmwHaptcFbFrqBilnrSeln_Ary1D
#else
#error Rte_Prm_BmwHaptcFbFrqBilnrSeln_Ary1D is missing
#endif
#define Rte_Prm_BmwHaptcFbFrqBilnrSeln_Ary1D() (&(BmwHaptcFb_Cal_BmwHaptcFbFrqBilnrSeln[0]))

#ifdef Rte_Prm_BmwHaptcFbFrqSelnTblY_Ary2D
# undef Rte_Prm_BmwHaptcFbFrqSelnTblY_Ary2D
#else
#error Rte_Prm_BmwHaptcFbFrqSelnTblY_Ary2D is missing
#endif
#define Rte_Prm_BmwHaptcFbFrqSelnTblY_Ary2D() (&(BmwHaptcFb_Cal_BmwHaptcFbFrqSelnTblY[0][0]))

#ifdef Rte_Prm_BmwHaptcFbHwTqFrqTblY_Ary2D
# undef Rte_Prm_BmwHaptcFbHwTqFrqTblY_Ary2D
#else
#error Rte_Prm_BmwHaptcFbHwTqFrqTblY_Ary2D is missing
#endif
#define Rte_Prm_BmwHaptcFbHwTqFrqTblY_Ary2D() (&(BmwHaptcFb_Cal_BmwHaptcFbHwTqFrqTblY[0][0]))

#ifdef Rte_Prm_BmwHaptcFbIntenSelnTblX_Ary1D
# undef Rte_Prm_BmwHaptcFbIntenSelnTblX_Ary1D
#else
#error Rte_Prm_BmwHaptcFbIntenSelnTblX_Ary1D is missing
#endif
#define Rte_Prm_BmwHaptcFbIntenSelnTblX_Ary1D() (&(BmwHaptcFb_Cal_BmwHaptcFbIntenSelnTblX[0]))

#ifdef Rte_Prm_BmwHaptcFbMotTqAmpTblY_Ary2D
# undef Rte_Prm_BmwHaptcFbMotTqAmpTblY_Ary2D
#else
#error Rte_Prm_BmwHaptcFbMotTqAmpTblY_Ary2D is missing
#endif
#define Rte_Prm_BmwHaptcFbMotTqAmpTblY_Ary2D() (&(BmwHaptcFb_Cal_BmwHaptcFbMotTqAmpTblY[0][0]))

#ifdef Rte_Prm_BmwHaptcFbPatActvTiTblY_Ary1D
# undef Rte_Prm_BmwHaptcFbPatActvTiTblY_Ary1D
#else
#error Rte_Prm_BmwHaptcFbPatActvTiTblY_Ary1D is missing
#endif
#define Rte_Prm_BmwHaptcFbPatActvTiTblY_Ary1D() (&(BmwHaptcFb_Cal_BmwHaptcFbPatActvTiTblY[0]))

#ifdef Rte_Prm_BmwHaptcFbPatPasTiTblY_Ary1D
# undef Rte_Prm_BmwHaptcFbPatPasTiTblY_Ary1D
#else
#error Rte_Prm_BmwHaptcFbPatPasTiTblY_Ary1D is missing
#endif
#define Rte_Prm_BmwHaptcFbPatPasTiTblY_Ary1D() (&(BmwHaptcFb_Cal_BmwHaptcFbPatPasTiTblY[0]))

#ifdef Rte_Prm_BmwHaptcFbPatRisngSlewTblY_Ary1D
# undef Rte_Prm_BmwHaptcFbPatRisngSlewTblY_Ary1D
#else
#error Rte_Prm_BmwHaptcFbPatRisngSlewTblY_Ary1D is missing
#endif
#define Rte_Prm_BmwHaptcFbPatRisngSlewTblY_Ary1D() (&(BmwHaptcFb_Cal_BmwHaptcFbPatRisngSlewTblY[0]))

#ifdef Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D
# undef Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D
#else
#error Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D is missing
#endif
#define Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D() (&(BmwHaptcFb_Cal_SysGlbPrmVehSpdBilnrSeln[0]))


/*** PIM Stubs ***/

#ifdef Rte_Pim_CurrInten
# undef Rte_Pim_CurrInten
#else
#error Rte_Pim_CurrInten is missing
#endif
#define Rte_Pim_CurrInten() (&BmwHaptcFb_Pim_CurrInten)

#ifdef Rte_Pim_CurrPat
# undef Rte_Pim_CurrPat
#else
#error Rte_Pim_CurrPat is missing
#endif
#define Rte_Pim_CurrPat() (&BmwHaptcFb_Pim_CurrPat)

#ifdef Rte_Pim_TqOscnEnaTmr
# undef Rte_Pim_TqOscnEnaTmr
#else
#error Rte_Pim_TqOscnEnaTmr is missing
#endif
#define Rte_Pim_TqOscnEnaTmr() (&BmwHaptcFb_Pim_TqOscnEnaTmr)


/*** Client Stub ***/

extern FUNC(void, AUTOMATIC) Rte_Stub(void);


#endif
