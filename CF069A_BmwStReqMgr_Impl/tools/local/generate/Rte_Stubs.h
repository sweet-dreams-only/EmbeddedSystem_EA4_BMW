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
extern VAR(BmwVehCdn1, AUTOMATIC) BmwStReqMgr_Ip_BmwVehCdn;
extern VAR(boolean, AUTOMATIC) BmwStReqMgr_Ip_BmwVehCdnVld;
extern VAR(BmwVehSpdSts1, AUTOMATIC) BmwStReqMgr_Ip_BmwVehSpdSts;
extern VAR(boolean, AUTOMATIC) BmwStReqMgr_Ip_DiagcStsNonRcvrlReqDiFltPrsnt;
extern VAR(float32, AUTOMATIC) BmwStReqMgr_Ip_HwTq;
extern VAR(float32, AUTOMATIC) BmwStReqMgr_Ip_PwrLimrRednFac;
extern VAR(SysSt1, AUTOMATIC) BmwStReqMgr_Ip_SysSt;
extern VAR(boolean, AUTOMATIC) BmwStReqMgr_Ip_SysStFltOutpReqDi;
extern VAR(float32, AUTOMATIC) BmwStReqMgr_Ip_ThermRednFac;
extern VAR(float32, AUTOMATIC) BmwStReqMgr_Ip_VehSpd;

/* Outputs */
extern VAR(BmwEpsFctSts1, AUTOMATIC) BmwStReqMgr_Op_BmwEpsFctSts;
extern VAR(boolean, AUTOMATIC) BmwStReqMgr_Op_PwrSplyEnaReq;
extern VAR(StsDrvrActvy1, AUTOMATIC) BmwStReqMgr_Op_StsDrvrActvy;
extern VAR(StsSteerAssi1, AUTOMATIC) BmwStReqMgr_Op_StsSteerAssi;
extern VAR(float32, AUTOMATIC) BmwStReqMgr_Op_SysOperMotTqCmdSca;
extern VAR(float32, AUTOMATIC) BmwStReqMgr_Op_SysOperRampRate;
extern VAR(boolean, AUTOMATIC) BmwStReqMgr_Op_SysStReqEna;
extern VAR(SysSt1, AUTOMATIC) BmwStReqMgr_Op_TarEcuSt;

/* Calibrations */
extern CONST(u16p0, AUTOMATIC) BmwStReqMgr_Cal_BmwStReqMgrAllwToOffThd;
extern CONST(u16p0, AUTOMATIC) BmwStReqMgr_Cal_BmwStReqMgrDrvrActvTmrThd;
extern CONST(float32, AUTOMATIC) BmwStReqMgr_Cal_BmwStReqMgrHwTqThd;
extern CONST(float32, AUTOMATIC) BmwStReqMgr_Cal_BmwStReqMgrOperRampRate;
extern CONST(float32, AUTOMATIC) BmwStReqMgr_Cal_BmwStReqMgrStsDrvrActvyTqChgThd;
extern CONST(float32, AUTOMATIC) BmwStReqMgr_Cal_BmwStReqMgrSwtOffSpdLim;
extern CONST(float32, AUTOMATIC) BmwStReqMgr_Cal_BmwStReqMgrSysProtnRednFacThd;
extern CONST(uint8, AUTOMATIC) BmwStReqMgr_Cal_BmwStReqMgrVehCdnOvrd;

/* PIMs */
extern VAR(uint32, AUTOMATIC) BmwStReqMgr_Pim_BmwVehCdnLvngDurn;
extern VAR(uint32, AUTOMATIC) BmwStReqMgr_Pim_DrvrActvRefTmr;
extern VAR(float32, AUTOMATIC) BmwStReqMgr_Pim_PrevHwTq;
extern VAR(uint8, AUTOMATIC) BmwStReqMgr_Pim_PrevTarEcuSt;

/* Arguments and Returns */
extern VAR(uint32, AUTOMATIC) BmwStReqMgr_Srv_GetRefTmr100MicroSec32bit_RefTmr;
extern VAR(uint32, AUTOMATIC) BmwStReqMgr_Srv_GetTiSpan100MicroSec32bit_RefTmr;
extern VAR(uint32, AUTOMATIC) BmwStReqMgr_Srv_GetTiSpan100MicroSec32bit_TiSpan;
extern VAR(boolean, AUTOMATIC) BmwStReqMgr_Srv_IoHwAb_GetGpioMcuEna_PinSt;
extern VAR(Std_ReturnType, AUTOMATIC) BmwStReqMgr_Srv_IoHwAb_GetGpioMcuEna_Return;


/*** Input Stubs ***/

#ifdef Rte_Read_BmwVehCdn_Val
# undef Rte_Read_BmwVehCdn_Val
#else
#error Rte_Read_BmwVehCdn_Val is missing
#endif
#define Rte_Read_BmwVehCdn_Val(data) (*(data) = BmwStReqMgr_Ip_BmwVehCdn)

#ifdef Rte_Read_BmwVehCdnVld_Logl
# undef Rte_Read_BmwVehCdnVld_Logl
#else
#error Rte_Read_BmwVehCdnVld_Logl is missing
#endif
#define Rte_Read_BmwVehCdnVld_Logl(data) (*(data) = BmwStReqMgr_Ip_BmwVehCdnVld)

#ifdef Rte_Read_BmwVehSpdSts_Val
# undef Rte_Read_BmwVehSpdSts_Val
#else
#error Rte_Read_BmwVehSpdSts_Val is missing
#endif
#define Rte_Read_BmwVehSpdSts_Val(data) (*(data) = BmwStReqMgr_Ip_BmwVehSpdSts)

#ifdef Rte_Read_DiagcStsNonRcvrlReqDiFltPrsnt_Logl
# undef Rte_Read_DiagcStsNonRcvrlReqDiFltPrsnt_Logl
#else
#error Rte_Read_DiagcStsNonRcvrlReqDiFltPrsnt_Logl is missing
#endif
#define Rte_Read_DiagcStsNonRcvrlReqDiFltPrsnt_Logl(data) (*(data) = BmwStReqMgr_Ip_DiagcStsNonRcvrlReqDiFltPrsnt)

#ifdef Rte_Read_HwTq_Val
# undef Rte_Read_HwTq_Val
#else
#error Rte_Read_HwTq_Val is missing
#endif
#define Rte_Read_HwTq_Val(data) (*(data) = BmwStReqMgr_Ip_HwTq)

#ifdef Rte_Read_PwrLimrRednFac_Val
# undef Rte_Read_PwrLimrRednFac_Val
#else
#error Rte_Read_PwrLimrRednFac_Val is missing
#endif
#define Rte_Read_PwrLimrRednFac_Val(data) (*(data) = BmwStReqMgr_Ip_PwrLimrRednFac)

#ifdef Rte_Read_SysSt_Val
# undef Rte_Read_SysSt_Val
#else
#error Rte_Read_SysSt_Val is missing
#endif
#define Rte_Read_SysSt_Val(data) (*(data) = BmwStReqMgr_Ip_SysSt)

#ifdef Rte_Read_SysStFltOutpReqDi_Logl
# undef Rte_Read_SysStFltOutpReqDi_Logl
#else
#error Rte_Read_SysStFltOutpReqDi_Logl is missing
#endif
#define Rte_Read_SysStFltOutpReqDi_Logl(data) (*(data) = BmwStReqMgr_Ip_SysStFltOutpReqDi)

#ifdef Rte_Read_ThermRednFac_Val
# undef Rte_Read_ThermRednFac_Val
#else
#error Rte_Read_ThermRednFac_Val is missing
#endif
#define Rte_Read_ThermRednFac_Val(data) (*(data) = BmwStReqMgr_Ip_ThermRednFac)

#ifdef Rte_Read_VehSpd_Val
# undef Rte_Read_VehSpd_Val
#else
#error Rte_Read_VehSpd_Val is missing
#endif
#define Rte_Read_VehSpd_Val(data) (*(data) = BmwStReqMgr_Ip_VehSpd)


/*** Output Stubs ***/

#ifdef Rte_Write_BmwEpsFctSts_Val
# undef Rte_Write_BmwEpsFctSts_Val
#else
#error Rte_Write_BmwEpsFctSts_Val is missing
#endif
#define Rte_Write_BmwEpsFctSts_Val(data) (BmwStReqMgr_Op_BmwEpsFctSts = (data))

#ifdef Rte_Write_PwrSplyEnaReq_Logl
# undef Rte_Write_PwrSplyEnaReq_Logl
#else
#error Rte_Write_PwrSplyEnaReq_Logl is missing
#endif
#define Rte_Write_PwrSplyEnaReq_Logl(data) (BmwStReqMgr_Op_PwrSplyEnaReq = (data))

#ifdef Rte_Write_StsDrvrActvy_Val
# undef Rte_Write_StsDrvrActvy_Val
#else
#error Rte_Write_StsDrvrActvy_Val is missing
#endif
#define Rte_Write_StsDrvrActvy_Val(data) (BmwStReqMgr_Op_StsDrvrActvy = (data))

#ifdef Rte_Write_StsSteerAssi_Val
# undef Rte_Write_StsSteerAssi_Val
#else
#error Rte_Write_StsSteerAssi_Val is missing
#endif
#define Rte_Write_StsSteerAssi_Val(data) (BmwStReqMgr_Op_StsSteerAssi = (data))

#ifdef Rte_Write_SysOperMotTqCmdSca_Val
# undef Rte_Write_SysOperMotTqCmdSca_Val
#else
#error Rte_Write_SysOperMotTqCmdSca_Val is missing
#endif
#define Rte_Write_SysOperMotTqCmdSca_Val(data) (BmwStReqMgr_Op_SysOperMotTqCmdSca = (data))

#ifdef Rte_Write_SysOperRampRate_Val
# undef Rte_Write_SysOperRampRate_Val
#else
#error Rte_Write_SysOperRampRate_Val is missing
#endif
#define Rte_Write_SysOperRampRate_Val(data) (BmwStReqMgr_Op_SysOperRampRate = (data))

#ifdef Rte_Write_SysStReqEna_Logl
# undef Rte_Write_SysStReqEna_Logl
#else
#error Rte_Write_SysStReqEna_Logl is missing
#endif
#define Rte_Write_SysStReqEna_Logl(data) (BmwStReqMgr_Op_SysStReqEna = (data))

#ifdef Rte_Write_TarEcuSt_Val
# undef Rte_Write_TarEcuSt_Val
#else
#error Rte_Write_TarEcuSt_Val is missing
#endif
#define Rte_Write_TarEcuSt_Val(data) (BmwStReqMgr_Op_TarEcuSt = (data))


/*** Calibration Stubs ***/

#ifdef Rte_Prm_BmwStReqMgrAllwToOffThd_Val
# undef Rte_Prm_BmwStReqMgrAllwToOffThd_Val
#else
#error Rte_Prm_BmwStReqMgrAllwToOffThd_Val is missing
#endif
#define Rte_Prm_BmwStReqMgrAllwToOffThd_Val() (BmwStReqMgr_Cal_BmwStReqMgrAllwToOffThd)

#ifdef Rte_Prm_BmwStReqMgrDrvrActvTmrThd_Val
# undef Rte_Prm_BmwStReqMgrDrvrActvTmrThd_Val
#else
#error Rte_Prm_BmwStReqMgrDrvrActvTmrThd_Val is missing
#endif
#define Rte_Prm_BmwStReqMgrDrvrActvTmrThd_Val() (BmwStReqMgr_Cal_BmwStReqMgrDrvrActvTmrThd)

#ifdef Rte_Prm_BmwStReqMgrHwTqThd_Val
# undef Rte_Prm_BmwStReqMgrHwTqThd_Val
#else
#error Rte_Prm_BmwStReqMgrHwTqThd_Val is missing
#endif
#define Rte_Prm_BmwStReqMgrHwTqThd_Val() (BmwStReqMgr_Cal_BmwStReqMgrHwTqThd)

#ifdef Rte_Prm_BmwStReqMgrOperRampRate_Val
# undef Rte_Prm_BmwStReqMgrOperRampRate_Val
#else
#error Rte_Prm_BmwStReqMgrOperRampRate_Val is missing
#endif
#define Rte_Prm_BmwStReqMgrOperRampRate_Val() (BmwStReqMgr_Cal_BmwStReqMgrOperRampRate)

#ifdef Rte_Prm_BmwStReqMgrStsDrvrActvyTqChgThd_Val
# undef Rte_Prm_BmwStReqMgrStsDrvrActvyTqChgThd_Val
#else
#error Rte_Prm_BmwStReqMgrStsDrvrActvyTqChgThd_Val is missing
#endif
#define Rte_Prm_BmwStReqMgrStsDrvrActvyTqChgThd_Val() (BmwStReqMgr_Cal_BmwStReqMgrStsDrvrActvyTqChgThd)

#ifdef Rte_Prm_BmwStReqMgrSwtOffSpdLim_Val
# undef Rte_Prm_BmwStReqMgrSwtOffSpdLim_Val
#else
#error Rte_Prm_BmwStReqMgrSwtOffSpdLim_Val is missing
#endif
#define Rte_Prm_BmwStReqMgrSwtOffSpdLim_Val() (BmwStReqMgr_Cal_BmwStReqMgrSwtOffSpdLim)

#ifdef Rte_Prm_BmwStReqMgrSysProtnRednFacThd_Val
# undef Rte_Prm_BmwStReqMgrSysProtnRednFacThd_Val
#else
#error Rte_Prm_BmwStReqMgrSysProtnRednFacThd_Val is missing
#endif
#define Rte_Prm_BmwStReqMgrSysProtnRednFacThd_Val() (BmwStReqMgr_Cal_BmwStReqMgrSysProtnRednFacThd)

#ifdef Rte_Prm_BmwStReqMgrVehCdnOvrd_Val
# undef Rte_Prm_BmwStReqMgrVehCdnOvrd_Val
#else
#error Rte_Prm_BmwStReqMgrVehCdnOvrd_Val is missing
#endif
#define Rte_Prm_BmwStReqMgrVehCdnOvrd_Val() (BmwStReqMgr_Cal_BmwStReqMgrVehCdnOvrd)


/*** PIM Stubs ***/

#ifdef Rte_Pim_BmwVehCdnLvngDurn
# undef Rte_Pim_BmwVehCdnLvngDurn
#else
#error Rte_Pim_BmwVehCdnLvngDurn is missing
#endif
#define Rte_Pim_BmwVehCdnLvngDurn() (&BmwStReqMgr_Pim_BmwVehCdnLvngDurn)

#ifdef Rte_Pim_DrvrActvRefTmr
# undef Rte_Pim_DrvrActvRefTmr
#else
#error Rte_Pim_DrvrActvRefTmr is missing
#endif
#define Rte_Pim_DrvrActvRefTmr() (&BmwStReqMgr_Pim_DrvrActvRefTmr)

#ifdef Rte_Pim_PrevHwTq
# undef Rte_Pim_PrevHwTq
#else
#error Rte_Pim_PrevHwTq is missing
#endif
#define Rte_Pim_PrevHwTq() (&BmwStReqMgr_Pim_PrevHwTq)

#ifdef Rte_Pim_PrevTarEcuSt
# undef Rte_Pim_PrevTarEcuSt
#else
#error Rte_Pim_PrevTarEcuSt is missing
#endif
#define Rte_Pim_PrevTarEcuSt() (&BmwStReqMgr_Pim_PrevTarEcuSt)


/*** Client Stub ***/

extern FUNC(void, AUTOMATIC) Rte_Stub(void);


#endif
