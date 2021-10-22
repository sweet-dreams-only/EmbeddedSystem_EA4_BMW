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
extern VAR(uint8, AUTOMATIC) Adc1CfgAndUse_Ip_AdcDiagcEndPtrOutp;
extern VAR(uint8, AUTOMATIC) Adc1CfgAndUse_Ip_AdcDiagcStrtPtrOutp;
extern VAR(boolean, AUTOMATIC) Adc1CfgAndUse_Ip_AdcStrtOfCnvn2;
extern VAR(uint8, AUTOMATIC) Adc1CfgAndUse_Ip_RegInpADCD1SGSR1;

/* Outputs */
extern VAR(boolean, AUTOMATIC) Adc1CfgAndUse_Op_DmaAdc1ResTrig;
extern VAR(uint8, AUTOMATIC) Adc1CfgAndUse_Op_RegOutpADCD1SGCR1;
extern VAR(uint8, AUTOMATIC) Adc1CfgAndUse_Op_RegOutpADCD1SGCR2;
extern VAR(uint8, AUTOMATIC) Adc1CfgAndUse_Op_RegOutpADCD1SGCR3;
extern VAR(uint8, AUTOMATIC) Adc1CfgAndUse_Op_RegOutpADCD1SGSTCR0;
extern VAR(uint8, AUTOMATIC) Adc1CfgAndUse_Op_RegOutpADCD1SGVCEP1;
extern VAR(uint8, AUTOMATIC) Adc1CfgAndUse_Op_RegOutpADCD1SGVCSP1;

/* PIMs */
extern VAR(uint8, AUTOMATIC) Adc1CfgAndUse_Pim_Adc1DiagcEndPtr;
extern VAR(uint8, AUTOMATIC) Adc1CfgAndUse_Pim_Adc1DiagcStrtPtr;

/* Arguments and Returns */


/*** Input Stubs ***/

#ifdef Rte_Read_AdcDiagcEndPtrOutp_Val
# undef Rte_Read_AdcDiagcEndPtrOutp_Val
#endif
#define Rte_Read_AdcDiagcEndPtrOutp_Val(data) (*(data) = Adc1CfgAndUse_Ip_AdcDiagcEndPtrOutp)

#ifdef Rte_Read_AdcDiagcStrtPtrOutp_Val
# undef Rte_Read_AdcDiagcStrtPtrOutp_Val
#endif
#define Rte_Read_AdcDiagcStrtPtrOutp_Val(data) (*(data) = Adc1CfgAndUse_Ip_AdcDiagcStrtPtrOutp)

#ifdef Rte_Read_AdcStrtOfCnvn2_Val
# undef Rte_Read_AdcStrtOfCnvn2_Val
#endif
#define Rte_Read_AdcStrtOfCnvn2_Val(data) (*(data) = Adc1CfgAndUse_Ip_AdcStrtOfCnvn2)

#ifdef Rte_Read_RegInpADCD1SGSR1_Val
# undef Rte_Read_RegInpADCD1SGSR1_Val
#endif
#define Rte_Read_RegInpADCD1SGSR1_Val(data) (*(data) = Adc1CfgAndUse_Ip_RegInpADCD1SGSR1)


/*** Output Stubs ***/

#ifdef Rte_Write_DmaAdc1ResTrig_Val
# undef Rte_Write_DmaAdc1ResTrig_Val
#endif
#define Rte_Write_DmaAdc1ResTrig_Val(data) (Adc1CfgAndUse_Op_DmaAdc1ResTrig = (data))

#ifdef Rte_Write_RegOutpADCD1SGCR1_Val
# undef Rte_Write_RegOutpADCD1SGCR1_Val
#endif
#define Rte_Write_RegOutpADCD1SGCR1_Val(data) (Adc1CfgAndUse_Op_RegOutpADCD1SGCR1 = (data))

#ifdef Rte_Write_RegOutpADCD1SGCR2_Val
# undef Rte_Write_RegOutpADCD1SGCR2_Val
#endif
#define Rte_Write_RegOutpADCD1SGCR2_Val(data) (Adc1CfgAndUse_Op_RegOutpADCD1SGCR2 = (data))

#ifdef Rte_Write_RegOutpADCD1SGCR3_Val
# undef Rte_Write_RegOutpADCD1SGCR3_Val
#endif
#define Rte_Write_RegOutpADCD1SGCR3_Val(data) (Adc1CfgAndUse_Op_RegOutpADCD1SGCR3 = (data))

#ifdef Rte_Write_RegOutpADCD1SGSTCR0_Val
# undef Rte_Write_RegOutpADCD1SGSTCR0_Val
#endif
#define Rte_Write_RegOutpADCD1SGSTCR0_Val(data) (Adc1CfgAndUse_Op_RegOutpADCD1SGSTCR0 = (data))

#ifdef Rte_Write_RegOutpADCD1SGVCEP1_Val
# undef Rte_Write_RegOutpADCD1SGVCEP1_Val
#endif
#define Rte_Write_RegOutpADCD1SGVCEP1_Val(data) (Adc1CfgAndUse_Op_RegOutpADCD1SGVCEP1 = (data))

#ifdef Rte_Write_RegOutpADCD1SGVCSP1_Val
# undef Rte_Write_RegOutpADCD1SGVCSP1_Val
#endif
#define Rte_Write_RegOutpADCD1SGVCSP1_Val(data) (Adc1CfgAndUse_Op_RegOutpADCD1SGVCSP1 = (data))


/*** PIM Stubs ***/

#ifdef Rte_Pim_Adc1DiagcEndPtr
# undef Rte_Pim_Adc1DiagcEndPtr
#endif
#define Rte_Pim_Adc1DiagcEndPtr() (&Adc1CfgAndUse_Pim_Adc1DiagcEndPtr)

#ifdef Rte_Pim_Adc1DiagcStrtPtr
# undef Rte_Pim_Adc1DiagcStrtPtr
#endif
#define Rte_Pim_Adc1DiagcStrtPtr() (&Adc1CfgAndUse_Pim_Adc1DiagcStrtPtr)


/*** Client Stub ***/

extern FUNC(void, AUTOMATIC) Rte_Stub(void);


#endif
