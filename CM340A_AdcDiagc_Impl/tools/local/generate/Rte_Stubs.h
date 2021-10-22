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
extern VAR(float32, AUTOMATIC) AdcDiagc_Ip_Adc0ScanGroup2Ref0;
extern VAR(float32, AUTOMATIC) AdcDiagc_Ip_Adc0ScanGroup2Ref1;
extern VAR(float32, AUTOMATIC) AdcDiagc_Ip_Adc0ScanGroup3Ref0;
extern VAR(float32, AUTOMATIC) AdcDiagc_Ip_Adc0ScanGroup3Ref1;
extern VAR(float32, AUTOMATIC) AdcDiagc_Ip_Adc0SelfDiag0;
extern VAR(float32, AUTOMATIC) AdcDiagc_Ip_Adc0SelfDiag2;
extern VAR(float32, AUTOMATIC) AdcDiagc_Ip_Adc0SelfDiag4;
extern VAR(float32, AUTOMATIC) AdcDiagc_Ip_Adc1ScanGroup2Ref0;
extern VAR(float32, AUTOMATIC) AdcDiagc_Ip_Adc1ScanGroup2Ref1;
extern VAR(float32, AUTOMATIC) AdcDiagc_Ip_Adc1ScanGroup3Ref0;
extern VAR(float32, AUTOMATIC) AdcDiagc_Ip_Adc1ScanGroup3Ref1;
extern VAR(float32, AUTOMATIC) AdcDiagc_Ip_Adc1SelfDiag0;
extern VAR(float32, AUTOMATIC) AdcDiagc_Ip_Adc1SelfDiag2;
extern VAR(float32, AUTOMATIC) AdcDiagc_Ip_Adc1SelfDiag4;
extern VAR(uint8, AUTOMATIC) AdcDiagc_Ip_RegInpADCD0PER;
extern VAR(uint8, AUTOMATIC) AdcDiagc_Ip_RegInpADCD1PER;

/* Outputs */
extern VAR(boolean, AUTOMATIC) AdcDiagc_Op_Adc0Faild;
extern VAR(boolean, AUTOMATIC) AdcDiagc_Op_Adc1Faild;
extern VAR(uint8, AUTOMATIC) AdcDiagc_Op_AdcDiagcEndPtrOutp;
extern VAR(uint8, AUTOMATIC) AdcDiagc_Op_AdcDiagcStrtPtrOutp;
extern VAR(uint8, AUTOMATIC) AdcDiagc_Op_RegOutpADCD0ECR;
extern VAR(uint8, AUTOMATIC) AdcDiagc_Op_RegOutpADCD1ECR;

/* Calibrations */
extern CONST(uint16, AUTOMATIC) AdcDiagc_Cal_AdcDiagcNtc0x032FailStep;
extern CONST(uint16, AUTOMATIC) AdcDiagc_Cal_AdcDiagcNtc0x032PassStep;
extern CONST(uint16, AUTOMATIC) AdcDiagc_Cal_AdcDiagcNtc0x033FailStep;
extern CONST(uint16, AUTOMATIC) AdcDiagc_Cal_AdcDiagcNtc0x033PassStep;

/* PIMs */
extern VAR(uint8, AUTOMATIC) AdcDiagc_Pim_Adc0FltCntSt0;
extern VAR(uint8, AUTOMATIC) AdcDiagc_Pim_Adc0FltCntSt2;
extern VAR(uint8, AUTOMATIC) AdcDiagc_Pim_Adc0FltCntSt4;
extern VAR(uint8, AUTOMATIC) AdcDiagc_Pim_Adc0FltCntSt6;
extern VAR(uint8, AUTOMATIC) AdcDiagc_Pim_Adc0ScanGroup2RefFltCntSt;
extern VAR(uint8, AUTOMATIC) AdcDiagc_Pim_Adc0ScanGroup3RefFltCntSt;
extern VAR(uint8, AUTOMATIC) AdcDiagc_Pim_Adc1FltCntSt0;
extern VAR(uint8, AUTOMATIC) AdcDiagc_Pim_Adc1FltCntSt2;
extern VAR(uint8, AUTOMATIC) AdcDiagc_Pim_Adc1FltCntSt4;
extern VAR(uint8, AUTOMATIC) AdcDiagc_Pim_Adc1FltCntSt6;
extern VAR(uint8, AUTOMATIC) AdcDiagc_Pim_Adc1ScanGroup2RefFltCntSt;
extern VAR(uint8, AUTOMATIC) AdcDiagc_Pim_Adc1ScanGroup3RefFltCntSt;
extern VAR(uint8, AUTOMATIC) AdcDiagc_Pim_AdcDiagcEndPtr;
extern VAR(uint8, AUTOMATIC) AdcDiagc_Pim_AdcDiagcSt;
extern VAR(uint8, AUTOMATIC) AdcDiagc_Pim_AdcDiagcStrtPtr;

/* Arguments and Returns */
extern VAR(NtcNr1, AUTOMATIC) AdcDiagc_Srv_GetNtcQlfrSts_NtcNr;
extern VAR(SigQlfr1, AUTOMATIC) AdcDiagc_Srv_GetNtcQlfrSts_NtcQlfr;
extern VAR(Std_ReturnType, AUTOMATIC) AdcDiagc_Srv_GetNtcQlfrSts_Return;
extern VAR(uint32, AUTOMATIC) AdcDiagc_Srv_ReadErrInjReg_ErrId;
extern VAR(NtcNr1, AUTOMATIC) AdcDiagc_Srv_SetNtcSts_NtcNr;
extern VAR(uint8, AUTOMATIC) AdcDiagc_Srv_SetNtcSts_NtcStInfo;
extern VAR(NtcSts1, AUTOMATIC) AdcDiagc_Srv_SetNtcSts_NtcSts;
extern VAR(uint16, AUTOMATIC) AdcDiagc_Srv_SetNtcSts_DebStep;
extern VAR(Std_ReturnType, AUTOMATIC) AdcDiagc_Srv_SetNtcSts_Return;


/*** Input Stubs ***/

#ifdef Rte_Read_Adc0ScanGroup2Ref0_Val
# undef Rte_Read_Adc0ScanGroup2Ref0_Val
#endif
#define Rte_Read_Adc0ScanGroup2Ref0_Val(data) (*(data) = AdcDiagc_Ip_Adc0ScanGroup2Ref0)

#ifdef Rte_Read_Adc0ScanGroup2Ref1_Val
# undef Rte_Read_Adc0ScanGroup2Ref1_Val
#endif
#define Rte_Read_Adc0ScanGroup2Ref1_Val(data) (*(data) = AdcDiagc_Ip_Adc0ScanGroup2Ref1)

#ifdef Rte_Read_Adc0ScanGroup3Ref0_Val
# undef Rte_Read_Adc0ScanGroup3Ref0_Val
#endif
#define Rte_Read_Adc0ScanGroup3Ref0_Val(data) (*(data) = AdcDiagc_Ip_Adc0ScanGroup3Ref0)

#ifdef Rte_Read_Adc0ScanGroup3Ref1_Val
# undef Rte_Read_Adc0ScanGroup3Ref1_Val
#endif
#define Rte_Read_Adc0ScanGroup3Ref1_Val(data) (*(data) = AdcDiagc_Ip_Adc0ScanGroup3Ref1)

#ifdef Rte_Read_Adc0SelfDiag0_Val
# undef Rte_Read_Adc0SelfDiag0_Val
#endif
#define Rte_Read_Adc0SelfDiag0_Val(data) (*(data) = AdcDiagc_Ip_Adc0SelfDiag0)

#ifdef Rte_Read_Adc0SelfDiag2_Val
# undef Rte_Read_Adc0SelfDiag2_Val
#endif
#define Rte_Read_Adc0SelfDiag2_Val(data) (*(data) = AdcDiagc_Ip_Adc0SelfDiag2)

#ifdef Rte_Read_Adc0SelfDiag4_Val
# undef Rte_Read_Adc0SelfDiag4_Val
#endif
#define Rte_Read_Adc0SelfDiag4_Val(data) (*(data) = AdcDiagc_Ip_Adc0SelfDiag4)

#ifdef Rte_Read_Adc1ScanGroup2Ref0_Val
# undef Rte_Read_Adc1ScanGroup2Ref0_Val
#endif
#define Rte_Read_Adc1ScanGroup2Ref0_Val(data) (*(data) = AdcDiagc_Ip_Adc1ScanGroup2Ref0)

#ifdef Rte_Read_Adc1ScanGroup2Ref1_Val
# undef Rte_Read_Adc1ScanGroup2Ref1_Val
#endif
#define Rte_Read_Adc1ScanGroup2Ref1_Val(data) (*(data) = AdcDiagc_Ip_Adc1ScanGroup2Ref1)

#ifdef Rte_Read_Adc1ScanGroup3Ref0_Val
# undef Rte_Read_Adc1ScanGroup3Ref0_Val
#endif
#define Rte_Read_Adc1ScanGroup3Ref0_Val(data) (*(data) = AdcDiagc_Ip_Adc1ScanGroup3Ref0)

#ifdef Rte_Read_Adc1ScanGroup3Ref1_Val
# undef Rte_Read_Adc1ScanGroup3Ref1_Val
#endif
#define Rte_Read_Adc1ScanGroup3Ref1_Val(data) (*(data) = AdcDiagc_Ip_Adc1ScanGroup3Ref1)

#ifdef Rte_Read_Adc1SelfDiag0_Val
# undef Rte_Read_Adc1SelfDiag0_Val
#endif
#define Rte_Read_Adc1SelfDiag0_Val(data) (*(data) = AdcDiagc_Ip_Adc1SelfDiag0)

#ifdef Rte_Read_Adc1SelfDiag2_Val
# undef Rte_Read_Adc1SelfDiag2_Val
#endif
#define Rte_Read_Adc1SelfDiag2_Val(data) (*(data) = AdcDiagc_Ip_Adc1SelfDiag2)

#ifdef Rte_Read_Adc1SelfDiag4_Val
# undef Rte_Read_Adc1SelfDiag4_Val
#endif
#define Rte_Read_Adc1SelfDiag4_Val(data) (*(data) = AdcDiagc_Ip_Adc1SelfDiag4)

#ifdef Rte_Read_RegInpADCD0PER_Val
# undef Rte_Read_RegInpADCD0PER_Val
#endif
#define Rte_Read_RegInpADCD0PER_Val(data) (*(data) = AdcDiagc_Ip_RegInpADCD0PER)

#ifdef Rte_Read_RegInpADCD1PER_Val
# undef Rte_Read_RegInpADCD1PER_Val
#endif
#define Rte_Read_RegInpADCD1PER_Val(data) (*(data) = AdcDiagc_Ip_RegInpADCD1PER)


/*** Output Stubs ***/

#ifdef Rte_Write_Adc0Faild_Logl
# undef Rte_Write_Adc0Faild_Logl
#endif
#define Rte_Write_Adc0Faild_Logl(data) (AdcDiagc_Op_Adc0Faild = (data))

#ifdef Rte_Write_Adc1Faild_Logl
# undef Rte_Write_Adc1Faild_Logl
#endif
#define Rte_Write_Adc1Faild_Logl(data) (AdcDiagc_Op_Adc1Faild = (data))

#ifdef Rte_Write_AdcDiagcEndPtrOutp_Val
# undef Rte_Write_AdcDiagcEndPtrOutp_Val
#endif
#define Rte_Write_AdcDiagcEndPtrOutp_Val(data) (AdcDiagc_Op_AdcDiagcEndPtrOutp = (data))

#ifdef Rte_Write_AdcDiagcStrtPtrOutp_Val
# undef Rte_Write_AdcDiagcStrtPtrOutp_Val
#endif
#define Rte_Write_AdcDiagcStrtPtrOutp_Val(data) (AdcDiagc_Op_AdcDiagcStrtPtrOutp = (data))

#ifdef Rte_Write_RegOutpADCD0ECR_Val
# undef Rte_Write_RegOutpADCD0ECR_Val
#endif
#define Rte_Write_RegOutpADCD0ECR_Val(data) (AdcDiagc_Op_RegOutpADCD0ECR = (data))

#ifdef Rte_Write_RegOutpADCD1ECR_Val
# undef Rte_Write_RegOutpADCD1ECR_Val
#endif
#define Rte_Write_RegOutpADCD1ECR_Val(data) (AdcDiagc_Op_RegOutpADCD1ECR = (data))


/*** Calibration Stubs ***/

#ifdef Rte_Prm_AdcDiagcNtc0x032FailStep_Val
# undef Rte_Prm_AdcDiagcNtc0x032FailStep_Val
#endif
#define Rte_Prm_AdcDiagcNtc0x032FailStep_Val() (AdcDiagc_Cal_AdcDiagcNtc0x032FailStep)

#ifdef Rte_Prm_AdcDiagcNtc0x032PassStep_Val
# undef Rte_Prm_AdcDiagcNtc0x032PassStep_Val
#endif
#define Rte_Prm_AdcDiagcNtc0x032PassStep_Val() (AdcDiagc_Cal_AdcDiagcNtc0x032PassStep)

#ifdef Rte_Prm_AdcDiagcNtc0x033FailStep_Val
# undef Rte_Prm_AdcDiagcNtc0x033FailStep_Val
#endif
#define Rte_Prm_AdcDiagcNtc0x033FailStep_Val() (AdcDiagc_Cal_AdcDiagcNtc0x033FailStep)

#ifdef Rte_Prm_AdcDiagcNtc0x033PassStep_Val
# undef Rte_Prm_AdcDiagcNtc0x033PassStep_Val
#endif
#define Rte_Prm_AdcDiagcNtc0x033PassStep_Val() (AdcDiagc_Cal_AdcDiagcNtc0x033PassStep)


/*** PIM Stubs ***/

#ifdef Rte_Pim_Adc0FltCntSt0
# undef Rte_Pim_Adc0FltCntSt0
#endif
#define Rte_Pim_Adc0FltCntSt0() (&AdcDiagc_Pim_Adc0FltCntSt0)

#ifdef Rte_Pim_Adc0FltCntSt2
# undef Rte_Pim_Adc0FltCntSt2
#endif
#define Rte_Pim_Adc0FltCntSt2() (&AdcDiagc_Pim_Adc0FltCntSt2)

#ifdef Rte_Pim_Adc0FltCntSt4
# undef Rte_Pim_Adc0FltCntSt4
#endif
#define Rte_Pim_Adc0FltCntSt4() (&AdcDiagc_Pim_Adc0FltCntSt4)

#ifdef Rte_Pim_Adc0FltCntSt6
# undef Rte_Pim_Adc0FltCntSt6
#endif
#define Rte_Pim_Adc0FltCntSt6() (&AdcDiagc_Pim_Adc0FltCntSt6)

#ifdef Rte_Pim_Adc0ScanGroup2RefFltCntSt
# undef Rte_Pim_Adc0ScanGroup2RefFltCntSt
#endif
#define Rte_Pim_Adc0ScanGroup2RefFltCntSt() (&AdcDiagc_Pim_Adc0ScanGroup2RefFltCntSt)

#ifdef Rte_Pim_Adc0ScanGroup3RefFltCntSt
# undef Rte_Pim_Adc0ScanGroup3RefFltCntSt
#endif
#define Rte_Pim_Adc0ScanGroup3RefFltCntSt() (&AdcDiagc_Pim_Adc0ScanGroup3RefFltCntSt)

#ifdef Rte_Pim_Adc1FltCntSt0
# undef Rte_Pim_Adc1FltCntSt0
#endif
#define Rte_Pim_Adc1FltCntSt0() (&AdcDiagc_Pim_Adc1FltCntSt0)

#ifdef Rte_Pim_Adc1FltCntSt2
# undef Rte_Pim_Adc1FltCntSt2
#endif
#define Rte_Pim_Adc1FltCntSt2() (&AdcDiagc_Pim_Adc1FltCntSt2)

#ifdef Rte_Pim_Adc1FltCntSt4
# undef Rte_Pim_Adc1FltCntSt4
#endif
#define Rte_Pim_Adc1FltCntSt4() (&AdcDiagc_Pim_Adc1FltCntSt4)

#ifdef Rte_Pim_Adc1FltCntSt6
# undef Rte_Pim_Adc1FltCntSt6
#endif
#define Rte_Pim_Adc1FltCntSt6() (&AdcDiagc_Pim_Adc1FltCntSt6)

#ifdef Rte_Pim_Adc1ScanGroup2RefFltCntSt
# undef Rte_Pim_Adc1ScanGroup2RefFltCntSt
#endif
#define Rte_Pim_Adc1ScanGroup2RefFltCntSt() (&AdcDiagc_Pim_Adc1ScanGroup2RefFltCntSt)

#ifdef Rte_Pim_Adc1ScanGroup3RefFltCntSt
# undef Rte_Pim_Adc1ScanGroup3RefFltCntSt
#endif
#define Rte_Pim_Adc1ScanGroup3RefFltCntSt() (&AdcDiagc_Pim_Adc1ScanGroup3RefFltCntSt)

#ifdef Rte_Pim_AdcDiagcEndPtr
# undef Rte_Pim_AdcDiagcEndPtr
#endif
#define Rte_Pim_AdcDiagcEndPtr() (&AdcDiagc_Pim_AdcDiagcEndPtr)

#ifdef Rte_Pim_AdcDiagcSt
# undef Rte_Pim_AdcDiagcSt
#endif
#define Rte_Pim_AdcDiagcSt() (&AdcDiagc_Pim_AdcDiagcSt)

#ifdef Rte_Pim_AdcDiagcStrtPtr
# undef Rte_Pim_AdcDiagcStrtPtr
#endif
#define Rte_Pim_AdcDiagcStrtPtr() (&AdcDiagc_Pim_AdcDiagcStrtPtr)


/*** Client Stub ***/

extern FUNC(void, AUTOMATIC) Rte_Stub(void);


#endif
