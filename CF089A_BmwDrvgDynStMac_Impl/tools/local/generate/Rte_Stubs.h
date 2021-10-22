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
extern VAR(boolean, AUTOMATIC) BmwDrvgDynStMac_Ip_BmwDrvgDynEnaReq;
extern VAR(BmwOvrlCmdQlfr1, AUTOMATIC) BmwDrvgDynStMac_Ip_BmwDrvgDynFacQlfr;
extern VAR(boolean, AUTOMATIC) BmwDrvgDynStMac_Ip_BmwDrvgDynFacQlfrVld;
extern VAR(BmwOvrlCmdQlfr1, AUTOMATIC) BmwDrvgDynStMac_Ip_BmwTarHwTqOvrlQlfr;
extern VAR(boolean, AUTOMATIC) BmwDrvgDynStMac_Ip_BmwTarHwTqOvrlQlfrVld;
extern VAR(BmwOvrlCmdQlfr1, AUTOMATIC) BmwDrvgDynStMac_Ip_BmwTarSteerTqDrvrActrQlfr;
extern VAR(boolean, AUTOMATIC) BmwDrvgDynStMac_Ip_BmwTarSteerTqDrvrActrQlfrVld;
extern VAR(BmwTrfcJamAssiDampgStReq1, AUTOMATIC) BmwDrvgDynStMac_Ip_BmwTrfcJamAssiDampgStReq;
extern VAR(boolean, AUTOMATIC) BmwDrvgDynStMac_Ip_BmwTrfcJamAssiDampgStReqVld;
extern VAR(BmwVehCdn1, AUTOMATIC) BmwDrvgDynStMac_Ip_BmwVehCdn;
extern VAR(float32, AUTOMATIC) BmwDrvgDynStMac_Ip_DampgCmdSca;
extern VAR(boolean, AUTOMATIC) BmwDrvgDynStMac_Ip_DiagcStsCtrldShtDwnFltPrsnt;
extern VAR(boolean, AUTOMATIC) BmwDrvgDynStMac_Ip_DiagcStsNonRcvrlReqDiFltPrsnt;
extern VAR(float32, AUTOMATIC) BmwDrvgDynStMac_Ip_EffortCmdSca;
extern VAR(float32, AUTOMATIC) BmwDrvgDynStMac_Ip_MotTqCmdPwrLimd;
extern VAR(float32, AUTOMATIC) BmwDrvgDynStMac_Ip_MotTqOvrlCmd;
extern VAR(float32, AUTOMATIC) BmwDrvgDynStMac_Ip_RtnCmdSca;
extern VAR(StsSteerAssi1, AUTOMATIC) BmwDrvgDynStMac_Ip_StsSteerAssi;
extern VAR(boolean, AUTOMATIC) BmwDrvgDynStMac_Ip_SysStFltOutpReqDi;

/* Outputs */
extern VAR(boolean, AUTOMATIC) BmwDrvgDynStMac_Op_DrvgDynActv;
extern VAR(DrvgDynIfSt1, AUTOMATIC) BmwDrvgDynStMac_Op_DrvgDynIfSt;
extern VAR(boolean, AUTOMATIC) BmwDrvgDynStMac_Op_OutpTqOvrlRampInEna;

/* Calibrations */
extern CONST(uint16, AUTOMATIC) BmwDrvgDynStMac_Cal_BmwDrvgDynStMacAssiLvlThd;
extern CONST(float32, AUTOMATIC) BmwDrvgDynStMac_Cal_BmwDrvgDynStMacDampgCmdScaDft;
extern CONST(float32, AUTOMATIC) BmwDrvgDynStMac_Cal_BmwDrvgDynStMacEffortCmdScaDft;
extern CONST(uint16, AUTOMATIC) BmwDrvgDynStMac_Cal_BmwDrvgDynStMacErrIfTmrThd;
extern CONST(float32, AUTOMATIC) BmwDrvgDynStMac_Cal_BmwDrvgDynStMacMotTqCmdOvrlActvtThd;
extern CONST(float32, AUTOMATIC) BmwDrvgDynStMac_Cal_BmwDrvgDynStMacMotTqCmdOvrlDeactvtThd;
extern CONST(float32, AUTOMATIC) BmwDrvgDynStMac_Cal_BmwDrvgDynStMacRtnCmdScaDft;
extern CONST(uint16, AUTOMATIC) BmwDrvgDynStMac_Cal_BmwDrvgDynStMacVehCdnTmrThd;

/* PIMs */
extern VAR(uint32, AUTOMATIC) BmwDrvgDynStMac_Pim_AssiLvlActvtTi;
extern VAR(uint32, AUTOMATIC) BmwDrvgDynStMac_Pim_AssiLvlDeactvtTi;
extern VAR(uint32, AUTOMATIC) BmwDrvgDynStMac_Pim_ErrIfTi;
extern VAR(boolean, AUTOMATIC) BmwDrvgDynStMac_Pim_MotTqCmdPwrLimdCdnActvt;
extern VAR(boolean, AUTOMATIC) BmwDrvgDynStMac_Pim_MotTqCmdPwrLimdCdnDeactvt;
extern VAR(uint8, AUTOMATIC) BmwDrvgDynStMac_Pim_StMacSt;
extern VAR(uint32, AUTOMATIC) BmwDrvgDynStMac_Pim_VehCdnTi;

/* Arguments and Returns */
extern VAR(uint32, AUTOMATIC) BmwDrvgDynStMac_Srv_GetRefTmr100MicroSec32bit_RefTmr;
extern VAR(uint32, AUTOMATIC) BmwDrvgDynStMac_Srv_GetTiSpan100MicroSec32bit_RefTmr;
extern VAR(uint32, AUTOMATIC) BmwDrvgDynStMac_Srv_GetTiSpan100MicroSec32bit_TiSpan;


/*** Input Stubs ***/

#ifdef Rte_Read_BmwDrvgDynEnaReq_Logl
# undef Rte_Read_BmwDrvgDynEnaReq_Logl
#else
#error Rte_Read_BmwDrvgDynEnaReq_Logl is missing
#endif
#define Rte_Read_BmwDrvgDynEnaReq_Logl(data) (*(data) = BmwDrvgDynStMac_Ip_BmwDrvgDynEnaReq)

#ifdef Rte_Read_BmwDrvgDynFacQlfr_Val
# undef Rte_Read_BmwDrvgDynFacQlfr_Val
#else
#error Rte_Read_BmwDrvgDynFacQlfr_Val is missing
#endif
#define Rte_Read_BmwDrvgDynFacQlfr_Val(data) (*(data) = BmwDrvgDynStMac_Ip_BmwDrvgDynFacQlfr)

#ifdef Rte_Read_BmwDrvgDynFacQlfrVld_Logl
# undef Rte_Read_BmwDrvgDynFacQlfrVld_Logl
#else
#error Rte_Read_BmwDrvgDynFacQlfrVld_Logl is missing
#endif
#define Rte_Read_BmwDrvgDynFacQlfrVld_Logl(data) (*(data) = BmwDrvgDynStMac_Ip_BmwDrvgDynFacQlfrVld)

#ifdef Rte_Read_BmwTarHwTqOvrlQlfr_Val
# undef Rte_Read_BmwTarHwTqOvrlQlfr_Val
#else
#error Rte_Read_BmwTarHwTqOvrlQlfr_Val is missing
#endif
#define Rte_Read_BmwTarHwTqOvrlQlfr_Val(data) (*(data) = BmwDrvgDynStMac_Ip_BmwTarHwTqOvrlQlfr)

#ifdef Rte_Read_BmwTarHwTqOvrlQlfrVld_Logl
# undef Rte_Read_BmwTarHwTqOvrlQlfrVld_Logl
#else
#error Rte_Read_BmwTarHwTqOvrlQlfrVld_Logl is missing
#endif
#define Rte_Read_BmwTarHwTqOvrlQlfrVld_Logl(data) (*(data) = BmwDrvgDynStMac_Ip_BmwTarHwTqOvrlQlfrVld)

#ifdef Rte_Read_BmwTarSteerTqDrvrActrQlfr_Val
# undef Rte_Read_BmwTarSteerTqDrvrActrQlfr_Val
#else
#error Rte_Read_BmwTarSteerTqDrvrActrQlfr_Val is missing
#endif
#define Rte_Read_BmwTarSteerTqDrvrActrQlfr_Val(data) (*(data) = BmwDrvgDynStMac_Ip_BmwTarSteerTqDrvrActrQlfr)

#ifdef Rte_Read_BmwTarSteerTqDrvrActrQlfrVld_Logl
# undef Rte_Read_BmwTarSteerTqDrvrActrQlfrVld_Logl
#else
#error Rte_Read_BmwTarSteerTqDrvrActrQlfrVld_Logl is missing
#endif
#define Rte_Read_BmwTarSteerTqDrvrActrQlfrVld_Logl(data) (*(data) = BmwDrvgDynStMac_Ip_BmwTarSteerTqDrvrActrQlfrVld)

#ifdef Rte_Read_BmwTrfcJamAssiDampgStReq_Val
# undef Rte_Read_BmwTrfcJamAssiDampgStReq_Val
#else
#error Rte_Read_BmwTrfcJamAssiDampgStReq_Val is missing
#endif
#define Rte_Read_BmwTrfcJamAssiDampgStReq_Val(data) (*(data) = BmwDrvgDynStMac_Ip_BmwTrfcJamAssiDampgStReq)

#ifdef Rte_Read_BmwTrfcJamAssiDampgStReqVld_Logl
# undef Rte_Read_BmwTrfcJamAssiDampgStReqVld_Logl
#else
#error Rte_Read_BmwTrfcJamAssiDampgStReqVld_Logl is missing
#endif
#define Rte_Read_BmwTrfcJamAssiDampgStReqVld_Logl(data) (*(data) = BmwDrvgDynStMac_Ip_BmwTrfcJamAssiDampgStReqVld)

#ifdef Rte_Read_BmwVehCdn_Val
# undef Rte_Read_BmwVehCdn_Val
#else
#error Rte_Read_BmwVehCdn_Val is missing
#endif
#define Rte_Read_BmwVehCdn_Val(data) (*(data) = BmwDrvgDynStMac_Ip_BmwVehCdn)

#ifdef Rte_Read_DampgCmdSca_Val
# undef Rte_Read_DampgCmdSca_Val
#else
#error Rte_Read_DampgCmdSca_Val is missing
#endif
#define Rte_Read_DampgCmdSca_Val(data) (*(data) = BmwDrvgDynStMac_Ip_DampgCmdSca)

#ifdef Rte_Read_DiagcStsCtrldShtDwnFltPrsnt_Logl
# undef Rte_Read_DiagcStsCtrldShtDwnFltPrsnt_Logl
#else
#error Rte_Read_DiagcStsCtrldShtDwnFltPrsnt_Logl is missing
#endif
#define Rte_Read_DiagcStsCtrldShtDwnFltPrsnt_Logl(data) (*(data) = BmwDrvgDynStMac_Ip_DiagcStsCtrldShtDwnFltPrsnt)

#ifdef Rte_Read_DiagcStsNonRcvrlReqDiFltPrsnt_Logl
# undef Rte_Read_DiagcStsNonRcvrlReqDiFltPrsnt_Logl
#else
#error Rte_Read_DiagcStsNonRcvrlReqDiFltPrsnt_Logl is missing
#endif
#define Rte_Read_DiagcStsNonRcvrlReqDiFltPrsnt_Logl(data) (*(data) = BmwDrvgDynStMac_Ip_DiagcStsNonRcvrlReqDiFltPrsnt)

#ifdef Rte_Read_EffortCmdSca_Val
# undef Rte_Read_EffortCmdSca_Val
#else
#error Rte_Read_EffortCmdSca_Val is missing
#endif
#define Rte_Read_EffortCmdSca_Val(data) (*(data) = BmwDrvgDynStMac_Ip_EffortCmdSca)

#ifdef Rte_Read_MotTqCmdPwrLimd_Val
# undef Rte_Read_MotTqCmdPwrLimd_Val
#else
#error Rte_Read_MotTqCmdPwrLimd_Val is missing
#endif
#define Rte_Read_MotTqCmdPwrLimd_Val(data) (*(data) = BmwDrvgDynStMac_Ip_MotTqCmdPwrLimd)

#ifdef Rte_Read_MotTqOvrlCmd_Val
# undef Rte_Read_MotTqOvrlCmd_Val
#else
#error Rte_Read_MotTqOvrlCmd_Val is missing
#endif
#define Rte_Read_MotTqOvrlCmd_Val(data) (*(data) = BmwDrvgDynStMac_Ip_MotTqOvrlCmd)

#ifdef Rte_Read_RtnCmdSca_Val
# undef Rte_Read_RtnCmdSca_Val
#else
#error Rte_Read_RtnCmdSca_Val is missing
#endif
#define Rte_Read_RtnCmdSca_Val(data) (*(data) = BmwDrvgDynStMac_Ip_RtnCmdSca)

#ifdef Rte_Read_StsSteerAssi_Val
# undef Rte_Read_StsSteerAssi_Val
#else
#error Rte_Read_StsSteerAssi_Val is missing
#endif
#define Rte_Read_StsSteerAssi_Val(data) (*(data) = BmwDrvgDynStMac_Ip_StsSteerAssi)

#ifdef Rte_Read_SysStFltOutpReqDi_Logl
# undef Rte_Read_SysStFltOutpReqDi_Logl
#else
#error Rte_Read_SysStFltOutpReqDi_Logl is missing
#endif
#define Rte_Read_SysStFltOutpReqDi_Logl(data) (*(data) = BmwDrvgDynStMac_Ip_SysStFltOutpReqDi)


/*** Output Stubs ***/

#ifdef Rte_Write_DrvgDynActv_Logl
# undef Rte_Write_DrvgDynActv_Logl
#else
#error Rte_Write_DrvgDynActv_Logl is missing
#endif
#define Rte_Write_DrvgDynActv_Logl(data) (BmwDrvgDynStMac_Op_DrvgDynActv = (data))

#ifdef Rte_Write_DrvgDynIfSt_Val
# undef Rte_Write_DrvgDynIfSt_Val
#else
#error Rte_Write_DrvgDynIfSt_Val is missing
#endif
#define Rte_Write_DrvgDynIfSt_Val(data) (BmwDrvgDynStMac_Op_DrvgDynIfSt = (data))

#ifdef Rte_Write_OutpTqOvrlRampInEna_Logl
# undef Rte_Write_OutpTqOvrlRampInEna_Logl
#else
#error Rte_Write_OutpTqOvrlRampInEna_Logl is missing
#endif
#define Rte_Write_OutpTqOvrlRampInEna_Logl(data) (BmwDrvgDynStMac_Op_OutpTqOvrlRampInEna = (data))


/*** Calibration Stubs ***/

#ifdef Rte_Prm_BmwDrvgDynStMacAssiLvlThd_Val
# undef Rte_Prm_BmwDrvgDynStMacAssiLvlThd_Val
#else
#error Rte_Prm_BmwDrvgDynStMacAssiLvlThd_Val is missing
#endif
#define Rte_Prm_BmwDrvgDynStMacAssiLvlThd_Val() (BmwDrvgDynStMac_Cal_BmwDrvgDynStMacAssiLvlThd)

#ifdef Rte_Prm_BmwDrvgDynStMacDampgCmdScaDft_Val
# undef Rte_Prm_BmwDrvgDynStMacDampgCmdScaDft_Val
#else
#error Rte_Prm_BmwDrvgDynStMacDampgCmdScaDft_Val is missing
#endif
#define Rte_Prm_BmwDrvgDynStMacDampgCmdScaDft_Val() (BmwDrvgDynStMac_Cal_BmwDrvgDynStMacDampgCmdScaDft)

#ifdef Rte_Prm_BmwDrvgDynStMacEffortCmdScaDft_Val
# undef Rte_Prm_BmwDrvgDynStMacEffortCmdScaDft_Val
#else
#error Rte_Prm_BmwDrvgDynStMacEffortCmdScaDft_Val is missing
#endif
#define Rte_Prm_BmwDrvgDynStMacEffortCmdScaDft_Val() (BmwDrvgDynStMac_Cal_BmwDrvgDynStMacEffortCmdScaDft)

#ifdef Rte_Prm_BmwDrvgDynStMacErrIfTmrThd_Val
# undef Rte_Prm_BmwDrvgDynStMacErrIfTmrThd_Val
#else
#error Rte_Prm_BmwDrvgDynStMacErrIfTmrThd_Val is missing
#endif
#define Rte_Prm_BmwDrvgDynStMacErrIfTmrThd_Val() (BmwDrvgDynStMac_Cal_BmwDrvgDynStMacErrIfTmrThd)

#ifdef Rte_Prm_BmwDrvgDynStMacMotTqCmdOvrlActvtThd_Val
# undef Rte_Prm_BmwDrvgDynStMacMotTqCmdOvrlActvtThd_Val
#else
#error Rte_Prm_BmwDrvgDynStMacMotTqCmdOvrlActvtThd_Val is missing
#endif
#define Rte_Prm_BmwDrvgDynStMacMotTqCmdOvrlActvtThd_Val() (BmwDrvgDynStMac_Cal_BmwDrvgDynStMacMotTqCmdOvrlActvtThd)

#ifdef Rte_Prm_BmwDrvgDynStMacMotTqCmdOvrlDeactvtThd_Val
# undef Rte_Prm_BmwDrvgDynStMacMotTqCmdOvrlDeactvtThd_Val
#else
#error Rte_Prm_BmwDrvgDynStMacMotTqCmdOvrlDeactvtThd_Val is missing
#endif
#define Rte_Prm_BmwDrvgDynStMacMotTqCmdOvrlDeactvtThd_Val() (BmwDrvgDynStMac_Cal_BmwDrvgDynStMacMotTqCmdOvrlDeactvtThd)

#ifdef Rte_Prm_BmwDrvgDynStMacRtnCmdScaDft_Val
# undef Rte_Prm_BmwDrvgDynStMacRtnCmdScaDft_Val
#else
#error Rte_Prm_BmwDrvgDynStMacRtnCmdScaDft_Val is missing
#endif
#define Rte_Prm_BmwDrvgDynStMacRtnCmdScaDft_Val() (BmwDrvgDynStMac_Cal_BmwDrvgDynStMacRtnCmdScaDft)

#ifdef Rte_Prm_BmwDrvgDynStMacVehCdnTmrThd_Val
# undef Rte_Prm_BmwDrvgDynStMacVehCdnTmrThd_Val
#else
#error Rte_Prm_BmwDrvgDynStMacVehCdnTmrThd_Val is missing
#endif
#define Rte_Prm_BmwDrvgDynStMacVehCdnTmrThd_Val() (BmwDrvgDynStMac_Cal_BmwDrvgDynStMacVehCdnTmrThd)


/*** PIM Stubs ***/

#ifdef Rte_Pim_AssiLvlActvtTi
# undef Rte_Pim_AssiLvlActvtTi
#else
#error Rte_Pim_AssiLvlActvtTi is missing
#endif
#define Rte_Pim_AssiLvlActvtTi() (&BmwDrvgDynStMac_Pim_AssiLvlActvtTi)

#ifdef Rte_Pim_AssiLvlDeactvtTi
# undef Rte_Pim_AssiLvlDeactvtTi
#else
#error Rte_Pim_AssiLvlDeactvtTi is missing
#endif
#define Rte_Pim_AssiLvlDeactvtTi() (&BmwDrvgDynStMac_Pim_AssiLvlDeactvtTi)

#ifdef Rte_Pim_ErrIfTi
# undef Rte_Pim_ErrIfTi
#else
#error Rte_Pim_ErrIfTi is missing
#endif
#define Rte_Pim_ErrIfTi() (&BmwDrvgDynStMac_Pim_ErrIfTi)

#ifdef Rte_Pim_MotTqCmdPwrLimdCdnActvt
# undef Rte_Pim_MotTqCmdPwrLimdCdnActvt
#else
#error Rte_Pim_MotTqCmdPwrLimdCdnActvt is missing
#endif
#define Rte_Pim_MotTqCmdPwrLimdCdnActvt() (&BmwDrvgDynStMac_Pim_MotTqCmdPwrLimdCdnActvt)

#ifdef Rte_Pim_MotTqCmdPwrLimdCdnDeactvt
# undef Rte_Pim_MotTqCmdPwrLimdCdnDeactvt
#else
#error Rte_Pim_MotTqCmdPwrLimdCdnDeactvt is missing
#endif
#define Rte_Pim_MotTqCmdPwrLimdCdnDeactvt() (&BmwDrvgDynStMac_Pim_MotTqCmdPwrLimdCdnDeactvt)

#ifdef Rte_Pim_StMacSt
# undef Rte_Pim_StMacSt
#else
#error Rte_Pim_StMacSt is missing
#endif
#define Rte_Pim_StMacSt() (&BmwDrvgDynStMac_Pim_StMacSt)

#ifdef Rte_Pim_VehCdnTi
# undef Rte_Pim_VehCdnTi
#else
#error Rte_Pim_VehCdnTi is missing
#endif
#define Rte_Pim_VehCdnTi() (&BmwDrvgDynStMac_Pim_VehCdnTi)


/*** Client Stub ***/

extern FUNC(void, AUTOMATIC) Rte_Stub(void);


#endif
