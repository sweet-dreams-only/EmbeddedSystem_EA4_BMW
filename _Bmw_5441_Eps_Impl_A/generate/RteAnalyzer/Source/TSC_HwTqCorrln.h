/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  TSC_HwTqCorrln.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Header of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/


/** Sender receiver - explicit read services */
Std_ReturnType TSC_HwTqCorrln_Rte_Read_HwTqA_Val(float32 *data);
Std_ReturnType TSC_HwTqCorrln_Rte_Read_HwTqAQlfr_Val(SigQlfr1 *data);
Std_ReturnType TSC_HwTqCorrln_Rte_Read_HwTqARollgCntr_Val(uint8 *data);
Std_ReturnType TSC_HwTqCorrln_Rte_Read_HwTqB_Val(float32 *data);
Std_ReturnType TSC_HwTqCorrln_Rte_Read_HwTqBQlfr_Val(SigQlfr1 *data);
Std_ReturnType TSC_HwTqCorrln_Rte_Read_HwTqBRollgCntr_Val(uint8 *data);
Std_ReturnType TSC_HwTqCorrln_Rte_Read_HwTqA_Val(float32 *data);
Std_ReturnType TSC_HwTqCorrln_Rte_Read_HwTqB_Val(float32 *data);
Std_ReturnType TSC_HwTqCorrln_Rte_Read_HwTqChA_Val(float32 *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_HwTqCorrln_Rte_Write_HwTqCorrlnSts_Val(uint8 data);
Std_ReturnType TSC_HwTqCorrln_Rte_Write_HwTqChACorrlnTraErr_Val(float32 data);
Std_ReturnType TSC_HwTqCorrln_Rte_Write_HwTqIdptSig_Val(uint8 data);

/** Client server interfaces */
Std_ReturnType TSC_HwTqCorrln_Rte_Call_GetNtcQlfrSts_Oper(NtcNr1 NtcNr_Arg, SigQlfr1 *NtcQlfr_Arg);
Std_ReturnType TSC_HwTqCorrln_Rte_Call_FltInj_u08_Oper(uint8 *SigPah_Arg, uint16 LocnKey_Arg);
Std_ReturnType TSC_HwTqCorrln_Rte_Call_GetNtcQlfrSts_Oper(NtcNr1 NtcNr_Arg, SigQlfr1 *NtcQlfr_Arg);
Std_ReturnType TSC_HwTqCorrln_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg);

/** Service interfaces */
Std_ReturnType TSC_HwTqCorrln_Rte_Call_HwTqChACmnModCmpLpFilSt_SetRamBlockStatus(boolean RamBlockStatus_Arg);

/** Explicit inter-runnable variables */
void TSC_HwTqCorrln_Rte_IrvWrite_HwTqCorrlnPer1_HwTqChAAvl(boolean);
boolean TSC_HwTqCorrln_Rte_IrvRead_HwTqCorrlnPer2_HwTqChAAvl(void);
void TSC_HwTqCorrln_Rte_IrvWrite_HwTqCorrlnPer2_HwTqChATqSumLim(float32);
float32 TSC_HwTqCorrln_Rte_IrvRead_HwTqCorrlnPer3_HwTqChATqSumLim(void);

/** Calibration Component Calibration Parameters */
float32  TSC_HwTqCorrln_Rte_Prm_HwTqCorrlnChACmnModCmpLpFilActvnThd_Val(void);
float32  TSC_HwTqCorrln_Rte_Prm_HwTqCorrlnChACmnModCmpLpFilFrq_Val(void);
float32  TSC_HwTqCorrln_Rte_Prm_HwTqCorrlnChACmnModCmpLpFilOutpLim_Val(void);
float32  TSC_HwTqCorrln_Rte_Prm_HwTqCorrlnChAImdtCorrlnChkFailThd_Val(void);
float32  TSC_HwTqCorrln_Rte_Prm_HwTqCorrlnChAImdtCorrlnChkPassThd_Val(void);
float32  TSC_HwTqCorrln_Rte_Prm_HwTqCorrlnChAStabStClrFltThd_Val(void);
float32  TSC_HwTqCorrln_Rte_Prm_HwTqCorrlnChAStabStLpFilFrq_Val(void);
float32  TSC_HwTqCorrln_Rte_Prm_HwTqCorrlnChAStabStSetFltThd_Val(void);
float32  TSC_HwTqCorrln_Rte_Prm_HwTqCorrlnChATqSumMaxLim_Val(void);
float32  TSC_HwTqCorrln_Rte_Prm_HwTqCorrlnChATraSumClrFltThd_Val(void);
float32  TSC_HwTqCorrln_Rte_Prm_HwTqCorrlnChATraSumSetFltThd_Val(void);
Ary1D_u5p11_17 * TSC_HwTqCorrln_Rte_Prm_HwTqCorrlnChATraLpFilX_Ary1D(void);
Ary1D_u6p10_17 * TSC_HwTqCorrln_Rte_Prm_HwTqCorrlnChATraLpFilY_Ary1D(void);

/** SW-C local Calibration Parameters */
float32  TSC_HwTqCorrln_Rte_CData_HwTqChACmnModCmpLpFilStDft(void);

/** Per Instance Memories */
float32 *TSC_HwTqCorrln_Rte_Pim_HwTqChACmnModCmpLpFilSt(void);
uint8 *TSC_HwTqCorrln_Rte_Pim_HwTqARollgCntrPrev(void);
uint8 *TSC_HwTqCorrln_Rte_Pim_HwTqAStallCntrPrev(void);
uint8 *TSC_HwTqCorrln_Rte_Pim_HwTqBRollgCntrPrev(void);
uint8 *TSC_HwTqCorrln_Rte_Pim_HwTqBStallCntrPrev(void);
boolean *TSC_HwTqCorrln_Rte_Pim_HwTqChAImdtCorrlnChk(void);
FilLpRec1 *TSC_HwTqCorrln_Rte_Pim_HwTqChACmnModCmpLpFil(void);
FilLpRec1 *TSC_HwTqCorrln_Rte_Pim_HwTqChAStabStLpFil(void);
FilLpRec1 *TSC_HwTqCorrln_Rte_Pim_HwTqChATraLpFil(void);



