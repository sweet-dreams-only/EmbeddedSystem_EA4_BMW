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
extern VAR(float32, AUTOMATIC) CurrMeas_Ip_BrdgVltg;
extern VAR(boolean, AUTOMATIC) CurrMeas_Ip_DiagcStsIvtr1Inactv;
extern VAR(float32, AUTOMATIC) CurrMeas_Ip_MotCurrAdcVlyA;
extern VAR(float32, AUTOMATIC) CurrMeas_Ip_MotCurrAdcVlyB;
extern VAR(float32, AUTOMATIC) CurrMeas_Ip_MotCurrAdcVlyC;
extern VAR(float32, AUTOMATIC) CurrMeas_Ip_MotVelMrf;
extern VAR(uint16, AUTOMATIC) CurrMeas_Ip_Ntc5DErrCnt;
extern VAR(uint8, AUTOMATIC) CurrMeas_Ip_StrtUpSt;
extern VAR(SysSt1, AUTOMATIC) CurrMeas_Ip_SysSt;
extern VAR(float32, AUTOMATIC) CurrMeas_Ip_VehSpd;
extern VAR(boolean, AUTOMATIC) CurrMeas_Ip_VehSpdVld;

/* Outputs */
extern VAR(boolean, AUTOMATIC) CurrMeas_Op_CurrMeasWrmIninTestCmpl;
extern VAR(MotCurrEolCalSt2, AUTOMATIC) CurrMeas_Op_MotCurrEolCalSt;
extern VAR(SigQlfr1, AUTOMATIC) CurrMeas_Op_MotCurrQlfr1;

/* Calibrations */
extern CONST(uint32, AUTOMATIC) CurrMeas_Cal_CurrMeasEolFixdPwmPerd;
extern CONST(float32, AUTOMATIC) CurrMeas_Cal_CurrMeasEolGainMax;
extern CONST(float32, AUTOMATIC) CurrMeas_Cal_CurrMeasEolGainMin;
extern CONST(float32, AUTOMATIC) CurrMeas_Cal_CurrMeasEolGainNom;
extern CONST(uint16, AUTOMATIC) CurrMeas_Cal_CurrMeasEolGainNrOfSample;
extern CONST(float32, AUTOMATIC) CurrMeas_Cal_CurrMeasEolGainNumer;
extern CONST(float32, AUTOMATIC) CurrMeas_Cal_CurrMeasEolMaxMotVel;
extern CONST(float32, AUTOMATIC) CurrMeas_Cal_CurrMeasEolOffsHiBrdgVltgMin;
extern CONST(uint32, AUTOMATIC) CurrMeas_Cal_CurrMeasEolOffsHiCmuOffs;
extern CONST(uint32, AUTOMATIC) CurrMeas_Cal_CurrMeasEolOffsLoCmuOffs;
extern CONST(float32, AUTOMATIC) CurrMeas_Cal_CurrMeasEolOffsMax;
extern CONST(float32, AUTOMATIC) CurrMeas_Cal_CurrMeasEolOffsMin;
extern CONST(float32, AUTOMATIC) CurrMeas_Cal_CurrMeasEolOffsNom;
extern CONST(uint16, AUTOMATIC) CurrMeas_Cal_CurrMeasEolOffsNrOfSample;
extern CONST(uint8, AUTOMATIC) CurrMeas_Cal_CurrMeasEolTranCntrThd;
extern CONST(uint32, AUTOMATIC) CurrMeas_Cal_CurrMeasMinRqrdPhaOnTi;
extern CONST(uint32, AUTOMATIC) CurrMeas_Cal_CurrMeasMotAgCompuDly;
extern CONST(float32, AUTOMATIC) CurrMeas_Cal_CurrMeasMotCurrAdcVlyWrmIninMax;
extern CONST(float32, AUTOMATIC) CurrMeas_Cal_CurrMeasMotCurrAdcVlyWrmIninMin;
extern CONST(uint16, AUTOMATIC) CurrMeas_Cal_CurrMeasNtc0x05DFailStep;
extern CONST(uint16, AUTOMATIC) CurrMeas_Cal_CurrMeasNtc0x05DPassStep;
extern CONST(uint8, AUTOMATIC) CurrMeas_Cal_SysGlbPrmMotPoleCnt;

/* PIMs */
extern VAR(CurrMeasEolGainCal3PhaRec1, AUTOMATIC) CurrMeas_Pim_CurrMeasEolGainCalSetABC;
extern VAR(CurrMeasEolOffsCal3PhaRec1, AUTOMATIC) CurrMeas_Pim_CurrMeasEolOffsCalSetABC;
extern VAR(float32, AUTOMATIC) CurrMeas_Pim_BrdgVltgSumPrev;
extern VAR(uint8, AUTOMATIC) CurrMeas_Pim_EolGainSts;
extern VAR(uint8, AUTOMATIC) CurrMeas_Pim_EolGainTranCntrPrev;
extern VAR(float32, AUTOMATIC) CurrMeas_Pim_EolOffsHiBrdgVltg;
extern VAR(uint8, AUTOMATIC) CurrMeas_Pim_EolOffsSts;
extern VAR(uint8, AUTOMATIC) CurrMeas_Pim_EolOffsTranCntrPrev;
extern VAR(uint16, AUTOMATIC) CurrMeas_Pim_GainEolAvrgCntrPrev;
extern VAR(uint16, AUTOMATIC) CurrMeas_Pim_MotCtrlNtc5DErrCntPrev;
extern VAR(MotCurrEolCalSt2, AUTOMATIC) CurrMeas_Pim_MotCurrEolCalStPrev;
extern VAR(float32, AUTOMATIC) CurrMeas_Pim_MotCurrEolGainA;
extern VAR(float32, AUTOMATIC) CurrMeas_Pim_MotCurrEolGainB;
extern VAR(float32, AUTOMATIC) CurrMeas_Pim_MotCurrEolGainC;
extern VAR(boolean, AUTOMATIC) CurrMeas_Pim_MotCurrEolOffsProcFlg;
extern VAR(float32, AUTOMATIC) CurrMeas_Pim_MotCurrOffsDeltaA;
extern VAR(float32, AUTOMATIC) CurrMeas_Pim_MotCurrOffsDeltaB;
extern VAR(float32, AUTOMATIC) CurrMeas_Pim_MotCurrOffsDeltaC;
extern VAR(float32, AUTOMATIC) CurrMeas_Pim_MotCurrOffsHiAvrgA;
extern VAR(float32, AUTOMATIC) CurrMeas_Pim_MotCurrOffsHiAvrgB;
extern VAR(float32, AUTOMATIC) CurrMeas_Pim_MotCurrOffsHiAvrgC;
extern VAR(float32, AUTOMATIC) CurrMeas_Pim_MotCurrOffsLoAvrgA;
extern VAR(float32, AUTOMATIC) CurrMeas_Pim_MotCurrOffsLoAvrgB;
extern VAR(float32, AUTOMATIC) CurrMeas_Pim_MotCurrOffsLoAvrgC;
extern VAR(float32, AUTOMATIC) CurrMeas_Pim_MotCurrOffsZeroAvrgA;
extern VAR(float32, AUTOMATIC) CurrMeas_Pim_MotCurrOffsZeroAvrgB;
extern VAR(float32, AUTOMATIC) CurrMeas_Pim_MotCurrOffsZeroAvrgC;
extern VAR(uint8, AUTOMATIC) CurrMeas_Pim_MotCurrRollgCnt1Prev;
extern VAR(float32, AUTOMATIC) CurrMeas_Pim_MotCurrSumAPrev;
extern VAR(float32, AUTOMATIC) CurrMeas_Pim_MotCurrSumBPrev;
extern VAR(float32, AUTOMATIC) CurrMeas_Pim_MotCurrSumCPrev;
extern VAR(uint16, AUTOMATIC) CurrMeas_Pim_Ntc5DErrCnt2MilliSecPrev;
extern VAR(uint16, AUTOMATIC) CurrMeas_Pim_OffsEolAvrgCntrPrev;
extern VAR(uint16, AUTOMATIC) CurrMeas_Pim_PhaOnTiErrCntPrev;
extern VAR(float32, AUTOMATIC) CurrMeas_Pim_TmpMotCurrAdcVlySum1Prev;
extern VAR(boolean, AUTOMATIC) CurrMeas_Pim_WrmIninTestCmplPrev;

/* Arguments and Returns */
extern VAR(uint8, AUTOMATIC) CurrMeas_Srv_CurrMeasEolGainCalSetABC_GetErrorStatus_RequestResultPtr;
extern VAR(Std_ReturnType, AUTOMATIC) CurrMeas_Srv_CurrMeasEolGainCalSetABC_GetErrorStatus_Return;
extern VAR(boolean, AUTOMATIC) CurrMeas_Srv_CurrMeasEolGainCalSetABC_SetRamBlockStatus_BlockChanged;
extern VAR(Std_ReturnType, AUTOMATIC) CurrMeas_Srv_CurrMeasEolGainCalSetABC_SetRamBlockStatus_Return;
extern VAR(uint8, AUTOMATIC) CurrMeas_Srv_CurrMeasEolOffsCalSetABC_GetErrorStatus_RequestResultPtr;
extern VAR(Std_ReturnType, AUTOMATIC) CurrMeas_Srv_CurrMeasEolOffsCalSetABC_GetErrorStatus_Return;
extern VAR(boolean, AUTOMATIC) CurrMeas_Srv_CurrMeasEolOffsCalSetABC_SetRamBlockStatus_BlockChanged;
extern VAR(Std_ReturnType, AUTOMATIC) CurrMeas_Srv_CurrMeasEolOffsCalSetABC_SetRamBlockStatus_Return;
extern VAR(NtcNr1, AUTOMATIC) CurrMeas_Srv_GetNtcQlfrSts_NtcNr;
extern VAR(SigQlfr1, AUTOMATIC) CurrMeas_Srv_GetNtcQlfrSts_NtcQlfr;
extern VAR(Std_ReturnType, AUTOMATIC) CurrMeas_Srv_GetNtcQlfrSts_Return;
extern VAR(NtcNr1, AUTOMATIC) CurrMeas_Srv_SetNtcSts_NtcNr;
extern VAR(uint8, AUTOMATIC) CurrMeas_Srv_SetNtcSts_NtcStInfo;
extern VAR(NtcSts1, AUTOMATIC) CurrMeas_Srv_SetNtcSts_NtcSts;
extern VAR(uint16, AUTOMATIC) CurrMeas_Srv_SetNtcSts_DebStep;
extern VAR(Std_ReturnType, AUTOMATIC) CurrMeas_Srv_SetNtcSts_Return;
extern VAR(uint8, AUTOMATIC) CurrMeas_Cli_CurrMeasEolGainStsReq_CurrMeasEolGainSt;
extern VAR(uint8, AUTOMATIC) CurrMeas_Cli_CurrMeasEolOffsStsReq_CurrMeasEolOffsSt;
extern VAR(float32, AUTOMATIC) CurrMeas_Cli_CurrMeasGainReadReqSngIvtr_CurrMeasMotCurrGainA;
extern VAR(float32, AUTOMATIC) CurrMeas_Cli_CurrMeasGainReadReqSngIvtr_CurrMeasMotCurrGainB;
extern VAR(float32, AUTOMATIC) CurrMeas_Cli_CurrMeasGainReadReqSngIvtr_CurrMeasMotCurrGainC;
extern VAR(float32, AUTOMATIC) CurrMeas_Cli_CurrMeasGainWrReqSngIvtr_CurrMeasMotCurrGainA;
extern VAR(float32, AUTOMATIC) CurrMeas_Cli_CurrMeasGainWrReqSngIvtr_CurrMeasMotCurrGainB;
extern VAR(float32, AUTOMATIC) CurrMeas_Cli_CurrMeasGainWrReqSngIvtr_CurrMeasMotCurrGainC;
extern VAR(uint8, AUTOMATIC) CurrMeas_Cli_CurrMeasGainWrReqSngIvtr_CurrMeasGainWrReqSts;
extern VAR(float32, AUTOMATIC) CurrMeas_Cli_CurrMeasOffsReadReqSngIvtr_CurrMeasEolOffsHiBrdgVltg;
extern VAR(float32, AUTOMATIC) CurrMeas_Cli_CurrMeasOffsReadReqSngIvtr_CurrMeasMotCurrOffsDifA;
extern VAR(float32, AUTOMATIC) CurrMeas_Cli_CurrMeasOffsReadReqSngIvtr_CurrMeasMotCurrOffsDifB;
extern VAR(float32, AUTOMATIC) CurrMeas_Cli_CurrMeasOffsReadReqSngIvtr_CurrMeasMotCurrOffsDifC;
extern VAR(float32, AUTOMATIC) CurrMeas_Cli_CurrMeasOffsReadReqSngIvtr_CurrMeasMotCurrOffsLoAvrgA;
extern VAR(float32, AUTOMATIC) CurrMeas_Cli_CurrMeasOffsReadReqSngIvtr_CurrMeasMotCurrOffsLoAvrgB;
extern VAR(float32, AUTOMATIC) CurrMeas_Cli_CurrMeasOffsReadReqSngIvtr_CurrMeasMotCurrOffsLoAvrgC;
extern VAR(float32, AUTOMATIC) CurrMeas_Cli_CurrMeasOffsWrReqSngIvtr_CurrMeasEolOffsHiBrdgVltg;
extern VAR(float32, AUTOMATIC) CurrMeas_Cli_CurrMeasOffsWrReqSngIvtr_CurrMeasMotCurrOffsDifA;
extern VAR(float32, AUTOMATIC) CurrMeas_Cli_CurrMeasOffsWrReqSngIvtr_CurrMeasMotCurrOffsDifB;
extern VAR(float32, AUTOMATIC) CurrMeas_Cli_CurrMeasOffsWrReqSngIvtr_CurrMeasMotCurrOffsDifC;
extern VAR(float32, AUTOMATIC) CurrMeas_Cli_CurrMeasOffsWrReqSngIvtr_CurrMeasMotCurrOffsLoAvrgA;
extern VAR(float32, AUTOMATIC) CurrMeas_Cli_CurrMeasOffsWrReqSngIvtr_CurrMeasMotCurrOffsLoAvrgB;
extern VAR(float32, AUTOMATIC) CurrMeas_Cli_CurrMeasOffsWrReqSngIvtr_CurrMeasMotCurrOffsLoAvrgC;
extern VAR(uint8, AUTOMATIC) CurrMeas_Cli_CurrMeasOffsWrReqSngIvtr_CurrMeasOffsWrReqSts;


/*** Input Stubs ***/

#ifdef Rte_Read_BrdgVltg_Val
# undef Rte_Read_BrdgVltg_Val
#else
#error Rte_Read_BrdgVltg_Val is missing
#endif
#define Rte_Read_BrdgVltg_Val(data) (*(data) = CurrMeas_Ip_BrdgVltg)

#ifdef Rte_Read_DiagcStsIvtr1Inactv_Logl
# undef Rte_Read_DiagcStsIvtr1Inactv_Logl
#else
#error Rte_Read_DiagcStsIvtr1Inactv_Logl is missing
#endif
#define Rte_Read_DiagcStsIvtr1Inactv_Logl(data) (*(data) = CurrMeas_Ip_DiagcStsIvtr1Inactv)

#ifdef Rte_Read_MotCurrAdcVlyA_Val
# undef Rte_Read_MotCurrAdcVlyA_Val
#else
#error Rte_Read_MotCurrAdcVlyA_Val is missing
#endif
#define Rte_Read_MotCurrAdcVlyA_Val(data) (*(data) = CurrMeas_Ip_MotCurrAdcVlyA)

#ifdef Rte_Read_MotCurrAdcVlyB_Val
# undef Rte_Read_MotCurrAdcVlyB_Val
#else
#error Rte_Read_MotCurrAdcVlyB_Val is missing
#endif
#define Rte_Read_MotCurrAdcVlyB_Val(data) (*(data) = CurrMeas_Ip_MotCurrAdcVlyB)

#ifdef Rte_Read_MotCurrAdcVlyC_Val
# undef Rte_Read_MotCurrAdcVlyC_Val
#else
#error Rte_Read_MotCurrAdcVlyC_Val is missing
#endif
#define Rte_Read_MotCurrAdcVlyC_Val(data) (*(data) = CurrMeas_Ip_MotCurrAdcVlyC)

#ifdef Rte_Read_MotVelMrf_Val
# undef Rte_Read_MotVelMrf_Val
#else
#error Rte_Read_MotVelMrf_Val is missing
#endif
#define Rte_Read_MotVelMrf_Val(data) (*(data) = CurrMeas_Ip_MotVelMrf)

#ifdef Rte_Read_Ntc5DErrCnt_Val
# undef Rte_Read_Ntc5DErrCnt_Val
#else
#error Rte_Read_Ntc5DErrCnt_Val is missing
#endif
#define Rte_Read_Ntc5DErrCnt_Val(data) (*(data) = CurrMeas_Ip_Ntc5DErrCnt)

#ifdef Rte_Read_StrtUpSt_Val
# undef Rte_Read_StrtUpSt_Val
#else
#error Rte_Read_StrtUpSt_Val is missing
#endif
#define Rte_Read_StrtUpSt_Val(data) (*(data) = CurrMeas_Ip_StrtUpSt)

#ifdef Rte_Read_SysSt_Val
# undef Rte_Read_SysSt_Val
#else
#error Rte_Read_SysSt_Val is missing
#endif
#define Rte_Read_SysSt_Val(data) (*(data) = CurrMeas_Ip_SysSt)

#ifdef Rte_Read_VehSpd_Val
# undef Rte_Read_VehSpd_Val
#else
#error Rte_Read_VehSpd_Val is missing
#endif
#define Rte_Read_VehSpd_Val(data) (*(data) = CurrMeas_Ip_VehSpd)

#ifdef Rte_Read_VehSpdVld_Logl
# undef Rte_Read_VehSpdVld_Logl
#else
#error Rte_Read_VehSpdVld_Logl is missing
#endif
#define Rte_Read_VehSpdVld_Logl(data) (*(data) = CurrMeas_Ip_VehSpdVld)


/*** Output Stubs ***/

#ifdef Rte_Write_CurrMeasWrmIninTestCmpl_Logl
# undef Rte_Write_CurrMeasWrmIninTestCmpl_Logl
#else
#error Rte_Write_CurrMeasWrmIninTestCmpl_Logl is missing
#endif
#define Rte_Write_CurrMeasWrmIninTestCmpl_Logl(data) (CurrMeas_Op_CurrMeasWrmIninTestCmpl = (data))

#ifdef Rte_Write_MotCurrEolCalSt_Val
# undef Rte_Write_MotCurrEolCalSt_Val
#else
#error Rte_Write_MotCurrEolCalSt_Val is missing
#endif
#define Rte_Write_MotCurrEolCalSt_Val(data) (CurrMeas_Op_MotCurrEolCalSt = (data))

#ifdef Rte_Write_MotCurrQlfr1_Val
# undef Rte_Write_MotCurrQlfr1_Val
#else
#error Rte_Write_MotCurrQlfr1_Val is missing
#endif
#define Rte_Write_MotCurrQlfr1_Val(data) (CurrMeas_Op_MotCurrQlfr1 = (data))


/*** Calibration Stubs ***/

#ifdef Rte_Prm_CurrMeasEolFixdPwmPerd_Val
# undef Rte_Prm_CurrMeasEolFixdPwmPerd_Val
#else
#error Rte_Prm_CurrMeasEolFixdPwmPerd_Val is missing
#endif
#define Rte_Prm_CurrMeasEolFixdPwmPerd_Val() (CurrMeas_Cal_CurrMeasEolFixdPwmPerd)

#ifdef Rte_Prm_CurrMeasEolGainMax_Val
# undef Rte_Prm_CurrMeasEolGainMax_Val
#else
#error Rte_Prm_CurrMeasEolGainMax_Val is missing
#endif
#define Rte_Prm_CurrMeasEolGainMax_Val() (CurrMeas_Cal_CurrMeasEolGainMax)

#ifdef Rte_Prm_CurrMeasEolGainMin_Val
# undef Rte_Prm_CurrMeasEolGainMin_Val
#else
#error Rte_Prm_CurrMeasEolGainMin_Val is missing
#endif
#define Rte_Prm_CurrMeasEolGainMin_Val() (CurrMeas_Cal_CurrMeasEolGainMin)

#ifdef Rte_Prm_CurrMeasEolGainNom_Val
# undef Rte_Prm_CurrMeasEolGainNom_Val
#else
#error Rte_Prm_CurrMeasEolGainNom_Val is missing
#endif
#define Rte_Prm_CurrMeasEolGainNom_Val() (CurrMeas_Cal_CurrMeasEolGainNom)

#ifdef Rte_Prm_CurrMeasEolGainNrOfSample_Val
# undef Rte_Prm_CurrMeasEolGainNrOfSample_Val
#else
#error Rte_Prm_CurrMeasEolGainNrOfSample_Val is missing
#endif
#define Rte_Prm_CurrMeasEolGainNrOfSample_Val() (CurrMeas_Cal_CurrMeasEolGainNrOfSample)

#ifdef Rte_Prm_CurrMeasEolGainNumer_Val
# undef Rte_Prm_CurrMeasEolGainNumer_Val
#else
#error Rte_Prm_CurrMeasEolGainNumer_Val is missing
#endif
#define Rte_Prm_CurrMeasEolGainNumer_Val() (CurrMeas_Cal_CurrMeasEolGainNumer)

#ifdef Rte_Prm_CurrMeasEolMaxMotVel_Val
# undef Rte_Prm_CurrMeasEolMaxMotVel_Val
#else
#error Rte_Prm_CurrMeasEolMaxMotVel_Val is missing
#endif
#define Rte_Prm_CurrMeasEolMaxMotVel_Val() (CurrMeas_Cal_CurrMeasEolMaxMotVel)

#ifdef Rte_Prm_CurrMeasEolOffsHiBrdgVltgMin_Val
# undef Rte_Prm_CurrMeasEolOffsHiBrdgVltgMin_Val
#else
#error Rte_Prm_CurrMeasEolOffsHiBrdgVltgMin_Val is missing
#endif
#define Rte_Prm_CurrMeasEolOffsHiBrdgVltgMin_Val() (CurrMeas_Cal_CurrMeasEolOffsHiBrdgVltgMin)

#ifdef Rte_Prm_CurrMeasEolOffsHiCmuOffs_Val
# undef Rte_Prm_CurrMeasEolOffsHiCmuOffs_Val
#else
#error Rte_Prm_CurrMeasEolOffsHiCmuOffs_Val is missing
#endif
#define Rte_Prm_CurrMeasEolOffsHiCmuOffs_Val() (CurrMeas_Cal_CurrMeasEolOffsHiCmuOffs)

#ifdef Rte_Prm_CurrMeasEolOffsLoCmuOffs_Val
# undef Rte_Prm_CurrMeasEolOffsLoCmuOffs_Val
#else
#error Rte_Prm_CurrMeasEolOffsLoCmuOffs_Val is missing
#endif
#define Rte_Prm_CurrMeasEolOffsLoCmuOffs_Val() (CurrMeas_Cal_CurrMeasEolOffsLoCmuOffs)

#ifdef Rte_Prm_CurrMeasEolOffsMax_Val
# undef Rte_Prm_CurrMeasEolOffsMax_Val
#else
#error Rte_Prm_CurrMeasEolOffsMax_Val is missing
#endif
#define Rte_Prm_CurrMeasEolOffsMax_Val() (CurrMeas_Cal_CurrMeasEolOffsMax)

#ifdef Rte_Prm_CurrMeasEolOffsMin_Val
# undef Rte_Prm_CurrMeasEolOffsMin_Val
#else
#error Rte_Prm_CurrMeasEolOffsMin_Val is missing
#endif
#define Rte_Prm_CurrMeasEolOffsMin_Val() (CurrMeas_Cal_CurrMeasEolOffsMin)

#ifdef Rte_Prm_CurrMeasEolOffsNom_Val
# undef Rte_Prm_CurrMeasEolOffsNom_Val
#else
#error Rte_Prm_CurrMeasEolOffsNom_Val is missing
#endif
#define Rte_Prm_CurrMeasEolOffsNom_Val() (CurrMeas_Cal_CurrMeasEolOffsNom)

#ifdef Rte_Prm_CurrMeasEolOffsNrOfSample_Val
# undef Rte_Prm_CurrMeasEolOffsNrOfSample_Val
#else
#error Rte_Prm_CurrMeasEolOffsNrOfSample_Val is missing
#endif
#define Rte_Prm_CurrMeasEolOffsNrOfSample_Val() (CurrMeas_Cal_CurrMeasEolOffsNrOfSample)

#ifdef Rte_Prm_CurrMeasEolTranCntrThd_Val
# undef Rte_Prm_CurrMeasEolTranCntrThd_Val
#else
#error Rte_Prm_CurrMeasEolTranCntrThd_Val is missing
#endif
#define Rte_Prm_CurrMeasEolTranCntrThd_Val() (CurrMeas_Cal_CurrMeasEolTranCntrThd)

#ifdef Rte_Prm_CurrMeasMinRqrdPhaOnTi_Val
# undef Rte_Prm_CurrMeasMinRqrdPhaOnTi_Val
#else
#error Rte_Prm_CurrMeasMinRqrdPhaOnTi_Val is missing
#endif
#define Rte_Prm_CurrMeasMinRqrdPhaOnTi_Val() (CurrMeas_Cal_CurrMeasMinRqrdPhaOnTi)

#ifdef Rte_Prm_CurrMeasMotAgCompuDly_Val
# undef Rte_Prm_CurrMeasMotAgCompuDly_Val
#else
#error Rte_Prm_CurrMeasMotAgCompuDly_Val is missing
#endif
#define Rte_Prm_CurrMeasMotAgCompuDly_Val() (CurrMeas_Cal_CurrMeasMotAgCompuDly)

#ifdef Rte_Prm_CurrMeasMotCurrAdcVlyWrmIninMax_Val
# undef Rte_Prm_CurrMeasMotCurrAdcVlyWrmIninMax_Val
#else
#error Rte_Prm_CurrMeasMotCurrAdcVlyWrmIninMax_Val is missing
#endif
#define Rte_Prm_CurrMeasMotCurrAdcVlyWrmIninMax_Val() (CurrMeas_Cal_CurrMeasMotCurrAdcVlyWrmIninMax)

#ifdef Rte_Prm_CurrMeasMotCurrAdcVlyWrmIninMin_Val
# undef Rte_Prm_CurrMeasMotCurrAdcVlyWrmIninMin_Val
#else
#error Rte_Prm_CurrMeasMotCurrAdcVlyWrmIninMin_Val is missing
#endif
#define Rte_Prm_CurrMeasMotCurrAdcVlyWrmIninMin_Val() (CurrMeas_Cal_CurrMeasMotCurrAdcVlyWrmIninMin)

#ifdef Rte_Prm_CurrMeasNtc0x05DFailStep_Val
# undef Rte_Prm_CurrMeasNtc0x05DFailStep_Val
#else
#error Rte_Prm_CurrMeasNtc0x05DFailStep_Val is missing
#endif
#define Rte_Prm_CurrMeasNtc0x05DFailStep_Val() (CurrMeas_Cal_CurrMeasNtc0x05DFailStep)

#ifdef Rte_Prm_CurrMeasNtc0x05DPassStep_Val
# undef Rte_Prm_CurrMeasNtc0x05DPassStep_Val
#else
#error Rte_Prm_CurrMeasNtc0x05DPassStep_Val is missing
#endif
#define Rte_Prm_CurrMeasNtc0x05DPassStep_Val() (CurrMeas_Cal_CurrMeasNtc0x05DPassStep)

#ifdef Rte_Prm_SysGlbPrmMotPoleCnt_Val
# undef Rte_Prm_SysGlbPrmMotPoleCnt_Val
#else
#error Rte_Prm_SysGlbPrmMotPoleCnt_Val is missing
#endif
#define Rte_Prm_SysGlbPrmMotPoleCnt_Val() (CurrMeas_Cal_SysGlbPrmMotPoleCnt)


/*** PIM Stubs ***/

#ifdef Rte_Pim_CurrMeasEolGainCalSetABC
# undef Rte_Pim_CurrMeasEolGainCalSetABC
#else
#error Rte_Pim_CurrMeasEolGainCalSetABC is missing
#endif
#define Rte_Pim_CurrMeasEolGainCalSetABC() (&CurrMeas_Pim_CurrMeasEolGainCalSetABC)

#ifdef Rte_Pim_CurrMeasEolOffsCalSetABC
# undef Rte_Pim_CurrMeasEolOffsCalSetABC
#else
#error Rte_Pim_CurrMeasEolOffsCalSetABC is missing
#endif
#define Rte_Pim_CurrMeasEolOffsCalSetABC() (&CurrMeas_Pim_CurrMeasEolOffsCalSetABC)

#ifdef Rte_Pim_BrdgVltgSumPrev
# undef Rte_Pim_BrdgVltgSumPrev
#else
#error Rte_Pim_BrdgVltgSumPrev is missing
#endif
#define Rte_Pim_BrdgVltgSumPrev() (&CurrMeas_Pim_BrdgVltgSumPrev)

#ifdef Rte_Pim_EolGainSts
# undef Rte_Pim_EolGainSts
#else
#error Rte_Pim_EolGainSts is missing
#endif
#define Rte_Pim_EolGainSts() (&CurrMeas_Pim_EolGainSts)

#ifdef Rte_Pim_EolGainTranCntrPrev
# undef Rte_Pim_EolGainTranCntrPrev
#else
#error Rte_Pim_EolGainTranCntrPrev is missing
#endif
#define Rte_Pim_EolGainTranCntrPrev() (&CurrMeas_Pim_EolGainTranCntrPrev)

#ifdef Rte_Pim_EolOffsHiBrdgVltg
# undef Rte_Pim_EolOffsHiBrdgVltg
#else
#error Rte_Pim_EolOffsHiBrdgVltg is missing
#endif
#define Rte_Pim_EolOffsHiBrdgVltg() (&CurrMeas_Pim_EolOffsHiBrdgVltg)

#ifdef Rte_Pim_EolOffsSts
# undef Rte_Pim_EolOffsSts
#else
#error Rte_Pim_EolOffsSts is missing
#endif
#define Rte_Pim_EolOffsSts() (&CurrMeas_Pim_EolOffsSts)

#ifdef Rte_Pim_EolOffsTranCntrPrev
# undef Rte_Pim_EolOffsTranCntrPrev
#else
#error Rte_Pim_EolOffsTranCntrPrev is missing
#endif
#define Rte_Pim_EolOffsTranCntrPrev() (&CurrMeas_Pim_EolOffsTranCntrPrev)

#ifdef Rte_Pim_GainEolAvrgCntrPrev
# undef Rte_Pim_GainEolAvrgCntrPrev
#else
#error Rte_Pim_GainEolAvrgCntrPrev is missing
#endif
#define Rte_Pim_GainEolAvrgCntrPrev() (&CurrMeas_Pim_GainEolAvrgCntrPrev)

#ifdef Rte_Pim_MotCtrlNtc5DErrCntPrev
# undef Rte_Pim_MotCtrlNtc5DErrCntPrev
#else
#error Rte_Pim_MotCtrlNtc5DErrCntPrev is missing
#endif
#define Rte_Pim_MotCtrlNtc5DErrCntPrev() (&CurrMeas_Pim_MotCtrlNtc5DErrCntPrev)

#ifdef Rte_Pim_MotCurrEolCalStPrev
# undef Rte_Pim_MotCurrEolCalStPrev
#else
#error Rte_Pim_MotCurrEolCalStPrev is missing
#endif
#define Rte_Pim_MotCurrEolCalStPrev() (&CurrMeas_Pim_MotCurrEolCalStPrev)

#ifdef Rte_Pim_MotCurrEolGainA
# undef Rte_Pim_MotCurrEolGainA
#else
#error Rte_Pim_MotCurrEolGainA is missing
#endif
#define Rte_Pim_MotCurrEolGainA() (&CurrMeas_Pim_MotCurrEolGainA)

#ifdef Rte_Pim_MotCurrEolGainB
# undef Rte_Pim_MotCurrEolGainB
#else
#error Rte_Pim_MotCurrEolGainB is missing
#endif
#define Rte_Pim_MotCurrEolGainB() (&CurrMeas_Pim_MotCurrEolGainB)

#ifdef Rte_Pim_MotCurrEolGainC
# undef Rte_Pim_MotCurrEolGainC
#else
#error Rte_Pim_MotCurrEolGainC is missing
#endif
#define Rte_Pim_MotCurrEolGainC() (&CurrMeas_Pim_MotCurrEolGainC)

#ifdef Rte_Pim_MotCurrEolOffsProcFlg
# undef Rte_Pim_MotCurrEolOffsProcFlg
#else
#error Rte_Pim_MotCurrEolOffsProcFlg is missing
#endif
#define Rte_Pim_MotCurrEolOffsProcFlg() (&CurrMeas_Pim_MotCurrEolOffsProcFlg)

#ifdef Rte_Pim_MotCurrOffsDeltaA
# undef Rte_Pim_MotCurrOffsDeltaA
#else
#error Rte_Pim_MotCurrOffsDeltaA is missing
#endif
#define Rte_Pim_MotCurrOffsDeltaA() (&CurrMeas_Pim_MotCurrOffsDeltaA)

#ifdef Rte_Pim_MotCurrOffsDeltaB
# undef Rte_Pim_MotCurrOffsDeltaB
#else
#error Rte_Pim_MotCurrOffsDeltaB is missing
#endif
#define Rte_Pim_MotCurrOffsDeltaB() (&CurrMeas_Pim_MotCurrOffsDeltaB)

#ifdef Rte_Pim_MotCurrOffsDeltaC
# undef Rte_Pim_MotCurrOffsDeltaC
#else
#error Rte_Pim_MotCurrOffsDeltaC is missing
#endif
#define Rte_Pim_MotCurrOffsDeltaC() (&CurrMeas_Pim_MotCurrOffsDeltaC)

#ifdef Rte_Pim_MotCurrOffsHiAvrgA
# undef Rte_Pim_MotCurrOffsHiAvrgA
#else
#error Rte_Pim_MotCurrOffsHiAvrgA is missing
#endif
#define Rte_Pim_MotCurrOffsHiAvrgA() (&CurrMeas_Pim_MotCurrOffsHiAvrgA)

#ifdef Rte_Pim_MotCurrOffsHiAvrgB
# undef Rte_Pim_MotCurrOffsHiAvrgB
#else
#error Rte_Pim_MotCurrOffsHiAvrgB is missing
#endif
#define Rte_Pim_MotCurrOffsHiAvrgB() (&CurrMeas_Pim_MotCurrOffsHiAvrgB)

#ifdef Rte_Pim_MotCurrOffsHiAvrgC
# undef Rte_Pim_MotCurrOffsHiAvrgC
#else
#error Rte_Pim_MotCurrOffsHiAvrgC is missing
#endif
#define Rte_Pim_MotCurrOffsHiAvrgC() (&CurrMeas_Pim_MotCurrOffsHiAvrgC)

#ifdef Rte_Pim_MotCurrOffsLoAvrgA
# undef Rte_Pim_MotCurrOffsLoAvrgA
#else
#error Rte_Pim_MotCurrOffsLoAvrgA is missing
#endif
#define Rte_Pim_MotCurrOffsLoAvrgA() (&CurrMeas_Pim_MotCurrOffsLoAvrgA)

#ifdef Rte_Pim_MotCurrOffsLoAvrgB
# undef Rte_Pim_MotCurrOffsLoAvrgB
#else
#error Rte_Pim_MotCurrOffsLoAvrgB is missing
#endif
#define Rte_Pim_MotCurrOffsLoAvrgB() (&CurrMeas_Pim_MotCurrOffsLoAvrgB)

#ifdef Rte_Pim_MotCurrOffsLoAvrgC
# undef Rte_Pim_MotCurrOffsLoAvrgC
#else
#error Rte_Pim_MotCurrOffsLoAvrgC is missing
#endif
#define Rte_Pim_MotCurrOffsLoAvrgC() (&CurrMeas_Pim_MotCurrOffsLoAvrgC)

#ifdef Rte_Pim_MotCurrOffsZeroAvrgA
# undef Rte_Pim_MotCurrOffsZeroAvrgA
#else
#error Rte_Pim_MotCurrOffsZeroAvrgA is missing
#endif
#define Rte_Pim_MotCurrOffsZeroAvrgA() (&CurrMeas_Pim_MotCurrOffsZeroAvrgA)

#ifdef Rte_Pim_MotCurrOffsZeroAvrgB
# undef Rte_Pim_MotCurrOffsZeroAvrgB
#else
#error Rte_Pim_MotCurrOffsZeroAvrgB is missing
#endif
#define Rte_Pim_MotCurrOffsZeroAvrgB() (&CurrMeas_Pim_MotCurrOffsZeroAvrgB)

#ifdef Rte_Pim_MotCurrOffsZeroAvrgC
# undef Rte_Pim_MotCurrOffsZeroAvrgC
#else
#error Rte_Pim_MotCurrOffsZeroAvrgC is missing
#endif
#define Rte_Pim_MotCurrOffsZeroAvrgC() (&CurrMeas_Pim_MotCurrOffsZeroAvrgC)

#ifdef Rte_Pim_MotCurrRollgCnt1Prev
# undef Rte_Pim_MotCurrRollgCnt1Prev
#else
#error Rte_Pim_MotCurrRollgCnt1Prev is missing
#endif
#define Rte_Pim_MotCurrRollgCnt1Prev() (&CurrMeas_Pim_MotCurrRollgCnt1Prev)

#ifdef Rte_Pim_MotCurrSumAPrev
# undef Rte_Pim_MotCurrSumAPrev
#else
#error Rte_Pim_MotCurrSumAPrev is missing
#endif
#define Rte_Pim_MotCurrSumAPrev() (&CurrMeas_Pim_MotCurrSumAPrev)

#ifdef Rte_Pim_MotCurrSumBPrev
# undef Rte_Pim_MotCurrSumBPrev
#else
#error Rte_Pim_MotCurrSumBPrev is missing
#endif
#define Rte_Pim_MotCurrSumBPrev() (&CurrMeas_Pim_MotCurrSumBPrev)

#ifdef Rte_Pim_MotCurrSumCPrev
# undef Rte_Pim_MotCurrSumCPrev
#else
#error Rte_Pim_MotCurrSumCPrev is missing
#endif
#define Rte_Pim_MotCurrSumCPrev() (&CurrMeas_Pim_MotCurrSumCPrev)

#ifdef Rte_Pim_Ntc5DErrCnt2MilliSecPrev
# undef Rte_Pim_Ntc5DErrCnt2MilliSecPrev
#else
#error Rte_Pim_Ntc5DErrCnt2MilliSecPrev is missing
#endif
#define Rte_Pim_Ntc5DErrCnt2MilliSecPrev() (&CurrMeas_Pim_Ntc5DErrCnt2MilliSecPrev)

#ifdef Rte_Pim_OffsEolAvrgCntrPrev
# undef Rte_Pim_OffsEolAvrgCntrPrev
#else
#error Rte_Pim_OffsEolAvrgCntrPrev is missing
#endif
#define Rte_Pim_OffsEolAvrgCntrPrev() (&CurrMeas_Pim_OffsEolAvrgCntrPrev)

#ifdef Rte_Pim_PhaOnTiErrCntPrev
# undef Rte_Pim_PhaOnTiErrCntPrev
#else
#error Rte_Pim_PhaOnTiErrCntPrev is missing
#endif
#define Rte_Pim_PhaOnTiErrCntPrev() (&CurrMeas_Pim_PhaOnTiErrCntPrev)

#ifdef Rte_Pim_TmpMotCurrAdcVlySum1Prev
# undef Rte_Pim_TmpMotCurrAdcVlySum1Prev
#else
#error Rte_Pim_TmpMotCurrAdcVlySum1Prev is missing
#endif
#define Rte_Pim_TmpMotCurrAdcVlySum1Prev() (&CurrMeas_Pim_TmpMotCurrAdcVlySum1Prev)

#ifdef Rte_Pim_WrmIninTestCmplPrev
# undef Rte_Pim_WrmIninTestCmplPrev
#else
#error Rte_Pim_WrmIninTestCmplPrev is missing
#endif
#define Rte_Pim_WrmIninTestCmplPrev() (&CurrMeas_Pim_WrmIninTestCmplPrev)


/*** Client Stub ***/

extern FUNC(void, AUTOMATIC) Rte_Stub(void);


#endif
