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
extern VAR(boolean, AUTOMATIC) PhaDiscnct_Ip_DiagcStsIvtr1Inactv;
extern VAR(IvtrFetFltPha1, AUTOMATIC) PhaDiscnct_Ip_IvtrFetFltPha;
extern VAR(IvtrFetFltTyp1, AUTOMATIC) PhaDiscnct_Ip_IvtrFetFltTyp;
extern VAR(float32, AUTOMATIC) PhaDiscnct_Ip_MotCurrCorrdA;
extern VAR(float32, AUTOMATIC) PhaDiscnct_Ip_MotCurrCorrdB;
extern VAR(float32, AUTOMATIC) PhaDiscnct_Ip_MotCurrCorrdC;
extern VAR(SigQlfr1, AUTOMATIC) PhaDiscnct_Ip_MotCurrQlfr1;
extern VAR(uint8, AUTOMATIC) PhaDiscnct_Ip_StrtUpSt;
extern VAR(SysSt1, AUTOMATIC) PhaDiscnct_Ip_SysSt;

/* Outputs */
extern VAR(boolean, AUTOMATIC) PhaDiscnct_Op_PhaDiscnctDiagcActv;
extern VAR(PhaDiscnctPwmVect1, AUTOMATIC) PhaDiscnct_Op_PhaDiscnctDiagcPwmVect;
extern VAR(boolean, AUTOMATIC) PhaDiscnct_Op_PhaDiscnctInactv;
extern VAR(boolean, AUTOMATIC) PhaDiscnct_Op_PhaDiscnctWrmIninTestCmpl;

/* Calibrations */
extern CONST(uint16, AUTOMATIC) PhaDiscnct_Cal_PhaDiscnctClsDlyTi;
extern CONST(uint32, AUTOMATIC) PhaDiscnct_Cal_PhaDiscnctFixdPhaOnTi;
extern CONST(uint32, AUTOMATIC) PhaDiscnct_Cal_PhaDiscnctFixdPwmPerd;
extern CONST(uint16, AUTOMATIC) PhaDiscnct_Cal_PhaDiscnctOpenDlyTi;
extern CONST(float32, AUTOMATIC) PhaDiscnct_Cal_PhaDiscnctTestCurrTestVal;
extern CONST(uint8, AUTOMATIC) PhaDiscnct_Cal_PhaDiscnctTestFailScanMax;
extern CONST(uint8, AUTOMATIC) PhaDiscnct_Cal_PhaDiscnctTestIninScan;
extern CONST(uint8, AUTOMATIC) PhaDiscnct_Cal_PhaDiscnctTestScanCnt;

/* PIMs */
extern VAR(boolean, AUTOMATIC) PhaDiscnct_Pim_dPhaDiscnctActvd;
extern VAR(uint8, AUTOMATIC) PhaDiscnct_Pim_dPhaDiscnctCmd;
extern VAR(uint32, AUTOMATIC) PhaDiscnct_Pim_DiscnctClsTmr;
extern VAR(uint8, AUTOMATIC) PhaDiscnct_Pim_DiscnctDiagCurrComp;
extern VAR(uint8, AUTOMATIC) PhaDiscnct_Pim_DiscnctDiagFailScan;
extern VAR(uint8, AUTOMATIC) PhaDiscnct_Pim_DiscnctDiagFltSts;
extern VAR(uint8, AUTOMATIC) PhaDiscnct_Pim_DiscnctDiagItrn;
extern VAR(uint8, AUTOMATIC) PhaDiscnct_Pim_DiscnctDiagSt;
extern VAR(uint8, AUTOMATIC) PhaDiscnct_Pim_DiscnctDiagTestScan;
extern VAR(uint8, AUTOMATIC) PhaDiscnct_Pim_DiscnctFltPrm;
extern VAR(uint32, AUTOMATIC) PhaDiscnct_Pim_DiscnctOpenTmr;
extern VAR(uint8, AUTOMATIC) PhaDiscnct_Pim_DiscnctSt;
extern VAR(uint8, AUTOMATIC) PhaDiscnct_Pim_PrevDiscnctCmd;
extern VAR(boolean, AUTOMATIC) PhaDiscnct_Pim_WrmIninTestCmpl;

/* Arguments and Returns */
extern VAR(uint32, AUTOMATIC) PhaDiscnct_Srv_GetRefTmr100MicroSec32bit_RefTmr;
extern VAR(uint32, AUTOMATIC) PhaDiscnct_Srv_GetTiSpan100MicroSec32bit_RefTmr;
extern VAR(uint32, AUTOMATIC) PhaDiscnct_Srv_GetTiSpan100MicroSec32bit_TiSpan;
extern VAR(Std_ReturnType, AUTOMATIC) PhaDiscnct_Srv_GetTiSpan100MicroSec32bit_Return;
extern VAR(NtcNr1, AUTOMATIC) PhaDiscnct_Srv_SetNtcStsAndSnpshtData_NtcNr;
extern VAR(uint8, AUTOMATIC) PhaDiscnct_Srv_SetNtcStsAndSnpshtData_NtcStInfo;
extern VAR(NtcSts1, AUTOMATIC) PhaDiscnct_Srv_SetNtcStsAndSnpshtData_NtcSts;
extern VAR(uint16, AUTOMATIC) PhaDiscnct_Srv_SetNtcStsAndSnpshtData_DebStep;
extern VAR(uint32, AUTOMATIC) PhaDiscnct_Srv_SetNtcStsAndSnpshtData_SpclSnpshtData0;
extern VAR(uint32, AUTOMATIC) PhaDiscnct_Srv_SetNtcStsAndSnpshtData_SpclSnpshtData1;
extern VAR(uint32, AUTOMATIC) PhaDiscnct_Srv_SetNtcStsAndSnpshtData_SpclSnpshtData2;
extern VAR(Std_ReturnType, AUTOMATIC) PhaDiscnct_Srv_SetNtcStsAndSnpshtData_Return;


/*** Input Stubs ***/

#ifdef Rte_Read_DiagcStsIvtr1Inactv_Logl
# undef Rte_Read_DiagcStsIvtr1Inactv_Logl
#endif
#define Rte_Read_DiagcStsIvtr1Inactv_Logl(data) (*(data) = PhaDiscnct_Ip_DiagcStsIvtr1Inactv)

#ifdef Rte_Read_IvtrFetFltPha_Val
# undef Rte_Read_IvtrFetFltPha_Val
#endif
#define Rte_Read_IvtrFetFltPha_Val(data) (*(data) = PhaDiscnct_Ip_IvtrFetFltPha)

#ifdef Rte_Read_IvtrFetFltTyp_Val
# undef Rte_Read_IvtrFetFltTyp_Val
#endif
#define Rte_Read_IvtrFetFltTyp_Val(data) (*(data) = PhaDiscnct_Ip_IvtrFetFltTyp)

#ifdef Rte_Read_MotCurrCorrdA_Val
# undef Rte_Read_MotCurrCorrdA_Val
#endif
#define Rte_Read_MotCurrCorrdA_Val(data) (*(data) = PhaDiscnct_Ip_MotCurrCorrdA)

#ifdef Rte_Read_MotCurrCorrdB_Val
# undef Rte_Read_MotCurrCorrdB_Val
#endif
#define Rte_Read_MotCurrCorrdB_Val(data) (*(data) = PhaDiscnct_Ip_MotCurrCorrdB)

#ifdef Rte_Read_MotCurrCorrdC_Val
# undef Rte_Read_MotCurrCorrdC_Val
#endif
#define Rte_Read_MotCurrCorrdC_Val(data) (*(data) = PhaDiscnct_Ip_MotCurrCorrdC)

#ifdef Rte_Read_MotCurrQlfr1_Val
# undef Rte_Read_MotCurrQlfr1_Val
#endif
#define Rte_Read_MotCurrQlfr1_Val(data) (*(data) = PhaDiscnct_Ip_MotCurrQlfr1)

#ifdef Rte_Read_StrtUpSt_Val
# undef Rte_Read_StrtUpSt_Val
#endif
#define Rte_Read_StrtUpSt_Val(data) (*(data) = PhaDiscnct_Ip_StrtUpSt)

#ifdef Rte_Read_SysSt_Val
# undef Rte_Read_SysSt_Val
#endif
#define Rte_Read_SysSt_Val(data) (*(data) = PhaDiscnct_Ip_SysSt)


/*** Output Stubs ***/

#ifdef Rte_Write_PhaDiscnctDiagcActv_Logl
# undef Rte_Write_PhaDiscnctDiagcActv_Logl
#endif
#define Rte_Write_PhaDiscnctDiagcActv_Logl(data) (PhaDiscnct_Op_PhaDiscnctDiagcActv = (data))

#ifdef Rte_Write_PhaDiscnctDiagcPwmVect_Val
# undef Rte_Write_PhaDiscnctDiagcPwmVect_Val
#endif
#define Rte_Write_PhaDiscnctDiagcPwmVect_Val(data) (PhaDiscnct_Op_PhaDiscnctDiagcPwmVect = (data))

#ifdef Rte_Write_PhaDiscnctInactv_Logl
# undef Rte_Write_PhaDiscnctInactv_Logl
#endif
#define Rte_Write_PhaDiscnctInactv_Logl(data) (PhaDiscnct_Op_PhaDiscnctInactv = (data))

#ifdef Rte_Write_PhaDiscnctWrmIninTestCmpl_Logl
# undef Rte_Write_PhaDiscnctWrmIninTestCmpl_Logl
#endif
#define Rte_Write_PhaDiscnctWrmIninTestCmpl_Logl(data) (PhaDiscnct_Op_PhaDiscnctWrmIninTestCmpl = (data))


/*** Calibration Stubs ***/

#ifdef Rte_Prm_PhaDiscnctClsDlyTi_Val
# undef Rte_Prm_PhaDiscnctClsDlyTi_Val
#endif
#define Rte_Prm_PhaDiscnctClsDlyTi_Val() (PhaDiscnct_Cal_PhaDiscnctClsDlyTi)

#ifdef Rte_Prm_PhaDiscnctFixdPhaOnTi_Val
# undef Rte_Prm_PhaDiscnctFixdPhaOnTi_Val
#endif
#define Rte_Prm_PhaDiscnctFixdPhaOnTi_Val() (PhaDiscnct_Cal_PhaDiscnctFixdPhaOnTi)

#ifdef Rte_Prm_PhaDiscnctFixdPwmPerd_Val
# undef Rte_Prm_PhaDiscnctFixdPwmPerd_Val
#endif
#define Rte_Prm_PhaDiscnctFixdPwmPerd_Val() (PhaDiscnct_Cal_PhaDiscnctFixdPwmPerd)

#ifdef Rte_Prm_PhaDiscnctOpenDlyTi_Val
# undef Rte_Prm_PhaDiscnctOpenDlyTi_Val
#endif
#define Rte_Prm_PhaDiscnctOpenDlyTi_Val() (PhaDiscnct_Cal_PhaDiscnctOpenDlyTi)

#ifdef Rte_Prm_PhaDiscnctTestCurrTestVal_Val
# undef Rte_Prm_PhaDiscnctTestCurrTestVal_Val
#endif
#define Rte_Prm_PhaDiscnctTestCurrTestVal_Val() (PhaDiscnct_Cal_PhaDiscnctTestCurrTestVal)

#ifdef Rte_Prm_PhaDiscnctTestFailScanMax_Val
# undef Rte_Prm_PhaDiscnctTestFailScanMax_Val
#endif
#define Rte_Prm_PhaDiscnctTestFailScanMax_Val() (PhaDiscnct_Cal_PhaDiscnctTestFailScanMax)

#ifdef Rte_Prm_PhaDiscnctTestIninScan_Val
# undef Rte_Prm_PhaDiscnctTestIninScan_Val
#endif
#define Rte_Prm_PhaDiscnctTestIninScan_Val() (PhaDiscnct_Cal_PhaDiscnctTestIninScan)

#ifdef Rte_Prm_PhaDiscnctTestScanCnt_Val
# undef Rte_Prm_PhaDiscnctTestScanCnt_Val
#endif
#define Rte_Prm_PhaDiscnctTestScanCnt_Val() (PhaDiscnct_Cal_PhaDiscnctTestScanCnt)


/*** PIM Stubs ***/

#ifdef Rte_Pim_dPhaDiscnctActvd
# undef Rte_Pim_dPhaDiscnctActvd
#endif
#define Rte_Pim_dPhaDiscnctActvd() (&PhaDiscnct_Pim_dPhaDiscnctActvd)

#ifdef Rte_Pim_dPhaDiscnctCmd
# undef Rte_Pim_dPhaDiscnctCmd
#endif
#define Rte_Pim_dPhaDiscnctCmd() (&PhaDiscnct_Pim_dPhaDiscnctCmd)

#ifdef Rte_Pim_DiscnctClsTmr
# undef Rte_Pim_DiscnctClsTmr
#endif
#define Rte_Pim_DiscnctClsTmr() (&PhaDiscnct_Pim_DiscnctClsTmr)

#ifdef Rte_Pim_DiscnctDiagCurrComp
# undef Rte_Pim_DiscnctDiagCurrComp
#endif
#define Rte_Pim_DiscnctDiagCurrComp() (&PhaDiscnct_Pim_DiscnctDiagCurrComp)

#ifdef Rte_Pim_DiscnctDiagFailScan
# undef Rte_Pim_DiscnctDiagFailScan
#endif
#define Rte_Pim_DiscnctDiagFailScan() (&PhaDiscnct_Pim_DiscnctDiagFailScan)

#ifdef Rte_Pim_DiscnctDiagFltSts
# undef Rte_Pim_DiscnctDiagFltSts
#endif
#define Rte_Pim_DiscnctDiagFltSts() (&PhaDiscnct_Pim_DiscnctDiagFltSts)

#ifdef Rte_Pim_DiscnctDiagItrn
# undef Rte_Pim_DiscnctDiagItrn
#endif
#define Rte_Pim_DiscnctDiagItrn() (&PhaDiscnct_Pim_DiscnctDiagItrn)

#ifdef Rte_Pim_DiscnctDiagSt
# undef Rte_Pim_DiscnctDiagSt
#endif
#define Rte_Pim_DiscnctDiagSt() (&PhaDiscnct_Pim_DiscnctDiagSt)

#ifdef Rte_Pim_DiscnctDiagTestScan
# undef Rte_Pim_DiscnctDiagTestScan
#endif
#define Rte_Pim_DiscnctDiagTestScan() (&PhaDiscnct_Pim_DiscnctDiagTestScan)

#ifdef Rte_Pim_DiscnctFltPrm
# undef Rte_Pim_DiscnctFltPrm
#endif
#define Rte_Pim_DiscnctFltPrm() (&PhaDiscnct_Pim_DiscnctFltPrm)

#ifdef Rte_Pim_DiscnctOpenTmr
# undef Rte_Pim_DiscnctOpenTmr
#endif
#define Rte_Pim_DiscnctOpenTmr() (&PhaDiscnct_Pim_DiscnctOpenTmr)

#ifdef Rte_Pim_DiscnctSt
# undef Rte_Pim_DiscnctSt
#endif
#define Rte_Pim_DiscnctSt() (&PhaDiscnct_Pim_DiscnctSt)

#ifdef Rte_Pim_PrevDiscnctCmd
# undef Rte_Pim_PrevDiscnctCmd
#endif
#define Rte_Pim_PrevDiscnctCmd() (&PhaDiscnct_Pim_PrevDiscnctCmd)

#ifdef Rte_Pim_WrmIninTestCmpl
# undef Rte_Pim_WrmIninTestCmpl
#endif
#define Rte_Pim_WrmIninTestCmpl() (&PhaDiscnct_Pim_WrmIninTestCmpl)


/*** Client Stub ***/

extern FUNC(void, AUTOMATIC) Rte_Stub(void);


#endif
