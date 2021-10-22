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
 *          File:  Rte_CDD_AdcDiagc.h
 *        Config:  E:/EA4NewTemplate/CM340A_AdcDiagc_Impl/tools/Component.dpa
 *     SW-C Type:  CDD_AdcDiagc
 *  Generated at:  Mon Mar 13 09:26:27 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <CDD_AdcDiagc> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CDD_ADCDIAGC_H
# define _RTE_CDD_ADCDIAGC_H

# ifdef RTE_APPLICATION_HEADER_FILE
#  error Multiple application header files included.
# endif
# define RTE_APPLICATION_HEADER_FILE
# ifndef RTE_PTR2ARRAYBASETYPE_PASSING
#  define RTE_PTR2ARRAYBASETYPE_PASSING
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_CDD_AdcDiagc_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_CDD_AdcDiagc
{
  /* PIM Handles section */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_Adc0FltCntSt0; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_Adc0FltCntSt2; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_Adc0FltCntSt4; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_Adc0FltCntSt6; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_Adc0ScanGroup2RefFltCntSt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_Adc0ScanGroup3RefFltCntSt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_Adc1FltCntSt0; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_Adc1FltCntSt2; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_Adc1FltCntSt4; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_Adc1FltCntSt6; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_Adc1ScanGroup2RefFltCntSt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_Adc1ScanGroup3RefFltCntSt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_AdcDiagcEndPtr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_AdcDiagcSt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_AdcDiagcStrtPtr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_CDD_AdcDiagc, RTE_CONST, RTE_CONST) Rte_Inst_CDD_AdcDiagc; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_CDD_AdcDiagc, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_Adc0Faild_Logl (FALSE)
# define Rte_InitValue_Adc0ScanGroup2Ref0_Val (0.0F)
# define Rte_InitValue_Adc0ScanGroup2Ref1_Val (0.0F)
# define Rte_InitValue_Adc0ScanGroup3Ref0_Val (0.0F)
# define Rte_InitValue_Adc0ScanGroup3Ref1_Val (0.0F)
# define Rte_InitValue_Adc0SelfDiag0_Val (0.0F)
# define Rte_InitValue_Adc0SelfDiag2_Val (0.0F)
# define Rte_InitValue_Adc0SelfDiag4_Val (0.0F)
# define Rte_InitValue_Adc1Faild_Logl (FALSE)
# define Rte_InitValue_Adc1ScanGroup2Ref0_Val (0.0F)
# define Rte_InitValue_Adc1ScanGroup2Ref1_Val (0.0F)
# define Rte_InitValue_Adc1ScanGroup3Ref0_Val (0.0F)
# define Rte_InitValue_Adc1ScanGroup3Ref1_Val (0.0F)
# define Rte_InitValue_Adc1SelfDiag0_Val (0.0F)
# define Rte_InitValue_Adc1SelfDiag2_Val (0.0F)
# define Rte_InitValue_Adc1SelfDiag4_Val (0.0F)
# define Rte_InitValue_AdcDiagcEndPtrOutp_Val (23U)
# define Rte_InitValue_AdcDiagcStrtPtrOutp_Val (21U)


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_AdcDiagc_Adc0ScanGroup2Ref0_Val(P2VAR(float32, AUTOMATIC, RTE_CDD_ADCDIAGC_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_AdcDiagc_Adc0ScanGroup2Ref1_Val(P2VAR(float32, AUTOMATIC, RTE_CDD_ADCDIAGC_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_AdcDiagc_Adc0ScanGroup3Ref0_Val(P2VAR(float32, AUTOMATIC, RTE_CDD_ADCDIAGC_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_AdcDiagc_Adc0ScanGroup3Ref1_Val(P2VAR(float32, AUTOMATIC, RTE_CDD_ADCDIAGC_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_AdcDiagc_Adc0SelfDiag0_Val(P2VAR(float32, AUTOMATIC, RTE_CDD_ADCDIAGC_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_AdcDiagc_Adc0SelfDiag2_Val(P2VAR(float32, AUTOMATIC, RTE_CDD_ADCDIAGC_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_AdcDiagc_Adc0SelfDiag4_Val(P2VAR(float32, AUTOMATIC, RTE_CDD_ADCDIAGC_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_AdcDiagc_Adc1ScanGroup2Ref0_Val(P2VAR(float32, AUTOMATIC, RTE_CDD_ADCDIAGC_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_AdcDiagc_Adc1ScanGroup2Ref1_Val(P2VAR(float32, AUTOMATIC, RTE_CDD_ADCDIAGC_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_AdcDiagc_Adc1ScanGroup3Ref0_Val(P2VAR(float32, AUTOMATIC, RTE_CDD_ADCDIAGC_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_AdcDiagc_Adc1ScanGroup3Ref1_Val(P2VAR(float32, AUTOMATIC, RTE_CDD_ADCDIAGC_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_AdcDiagc_Adc1SelfDiag0_Val(P2VAR(float32, AUTOMATIC, RTE_CDD_ADCDIAGC_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_AdcDiagc_Adc1SelfDiag2_Val(P2VAR(float32, AUTOMATIC, RTE_CDD_ADCDIAGC_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_AdcDiagc_Adc1SelfDiag4_Val(P2VAR(float32, AUTOMATIC, RTE_CDD_ADCDIAGC_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_AdcDiagc_Adc0Faild_Logl(boolean data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_AdcDiagc_Adc1Faild_Logl(boolean data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_AdcDiagc_AdcDiagcEndPtrOutp_Val(uint8 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_AdcDiagc_AdcDiagcStrtPtrOutp_Val(uint8 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_AdcDiagc_GetNtcQlfrSts_Oper(NtcNr1 NtcNr_Arg, P2VAR(SigQlfr1, AUTOMATIC, RTE_CDD_ADCDIAGC_APPL_VAR) NtcQlfr_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_AdcDiagc_ReadErrInjReg_Oper(P2VAR(uint32, AUTOMATIC, RTE_CDD_ADCDIAGC_APPL_VAR) ErrId_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_AdcDiagc_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_AdcDiagc_StrtErrInjCntr_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint16, RTE_CODE) Rte_Prm_CDD_AdcDiagc_AdcDiagcNtc0x032FailStep_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint16, RTE_CODE) Rte_Prm_CDD_AdcDiagc_AdcDiagcNtc0x032PassStep_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint16, RTE_CODE) Rte_Prm_CDD_AdcDiagc_AdcDiagcNtc0x033FailStep_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint16, RTE_CODE) Rte_Prm_CDD_AdcDiagc_AdcDiagcNtc0x033PassStep_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_Adc0ScanGroup2Ref0_Val Rte_Read_CDD_AdcDiagc_Adc0ScanGroup2Ref0_Val
# define Rte_Read_Adc0ScanGroup2Ref1_Val Rte_Read_CDD_AdcDiagc_Adc0ScanGroup2Ref1_Val
# define Rte_Read_Adc0ScanGroup3Ref0_Val Rte_Read_CDD_AdcDiagc_Adc0ScanGroup3Ref0_Val
# define Rte_Read_Adc0ScanGroup3Ref1_Val Rte_Read_CDD_AdcDiagc_Adc0ScanGroup3Ref1_Val
# define Rte_Read_Adc0SelfDiag0_Val Rte_Read_CDD_AdcDiagc_Adc0SelfDiag0_Val
# define Rte_Read_Adc0SelfDiag2_Val Rte_Read_CDD_AdcDiagc_Adc0SelfDiag2_Val
# define Rte_Read_Adc0SelfDiag4_Val Rte_Read_CDD_AdcDiagc_Adc0SelfDiag4_Val
# define Rte_Read_Adc1ScanGroup2Ref0_Val Rte_Read_CDD_AdcDiagc_Adc1ScanGroup2Ref0_Val
# define Rte_Read_Adc1ScanGroup2Ref1_Val Rte_Read_CDD_AdcDiagc_Adc1ScanGroup2Ref1_Val
# define Rte_Read_Adc1ScanGroup3Ref0_Val Rte_Read_CDD_AdcDiagc_Adc1ScanGroup3Ref0_Val
# define Rte_Read_Adc1ScanGroup3Ref1_Val Rte_Read_CDD_AdcDiagc_Adc1ScanGroup3Ref1_Val
# define Rte_Read_Adc1SelfDiag0_Val Rte_Read_CDD_AdcDiagc_Adc1SelfDiag0_Val
# define Rte_Read_Adc1SelfDiag2_Val Rte_Read_CDD_AdcDiagc_Adc1SelfDiag2_Val
# define Rte_Read_Adc1SelfDiag4_Val Rte_Read_CDD_AdcDiagc_Adc1SelfDiag4_Val


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_Adc0Faild_Logl Rte_Write_CDD_AdcDiagc_Adc0Faild_Logl
# define Rte_Write_Adc1Faild_Logl Rte_Write_CDD_AdcDiagc_Adc1Faild_Logl
# define Rte_Write_AdcDiagcEndPtrOutp_Val Rte_Write_CDD_AdcDiagc_AdcDiagcEndPtrOutp_Val
# define Rte_Write_AdcDiagcStrtPtrOutp_Val Rte_Write_CDD_AdcDiagc_AdcDiagcStrtPtrOutp_Val


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_GetNtcQlfrSts_Oper Rte_Call_CDD_AdcDiagc_GetNtcQlfrSts_Oper
# define Rte_Call_ReadErrInjReg_Oper Rte_Call_CDD_AdcDiagc_ReadErrInjReg_Oper
# define Rte_Call_SetNtcSts_Oper Rte_Call_CDD_AdcDiagc_SetNtcSts_Oper
# define Rte_Call_StrtErrInjCntr_Oper Rte_Call_CDD_AdcDiagc_StrtErrInjCntr_Oper


/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

# define Rte_Prm_AdcDiagcNtc0x032FailStep_Val Rte_Prm_CDD_AdcDiagc_AdcDiagcNtc0x032FailStep_Val

# define Rte_Prm_AdcDiagcNtc0x032PassStep_Val Rte_Prm_CDD_AdcDiagc_AdcDiagcNtc0x032PassStep_Val

# define Rte_Prm_AdcDiagcNtc0x033FailStep_Val Rte_Prm_CDD_AdcDiagc_AdcDiagcNtc0x033FailStep_Val

# define Rte_Prm_AdcDiagcNtc0x033PassStep_Val Rte_Prm_CDD_AdcDiagc_AdcDiagcNtc0x033PassStep_Val

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_Adc0FltCntSt0() (Rte_Inst_CDD_AdcDiagc->Pim_Adc0FltCntSt0) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_Adc0FltCntSt2() (Rte_Inst_CDD_AdcDiagc->Pim_Adc0FltCntSt2) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_Adc0FltCntSt4() (Rte_Inst_CDD_AdcDiagc->Pim_Adc0FltCntSt4) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_Adc0FltCntSt6() (Rte_Inst_CDD_AdcDiagc->Pim_Adc0FltCntSt6) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_Adc0ScanGroup2RefFltCntSt() (Rte_Inst_CDD_AdcDiagc->Pim_Adc0ScanGroup2RefFltCntSt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_Adc0ScanGroup3RefFltCntSt() (Rte_Inst_CDD_AdcDiagc->Pim_Adc0ScanGroup3RefFltCntSt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_Adc1FltCntSt0() (Rte_Inst_CDD_AdcDiagc->Pim_Adc1FltCntSt0) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_Adc1FltCntSt2() (Rte_Inst_CDD_AdcDiagc->Pim_Adc1FltCntSt2) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_Adc1FltCntSt4() (Rte_Inst_CDD_AdcDiagc->Pim_Adc1FltCntSt4) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_Adc1FltCntSt6() (Rte_Inst_CDD_AdcDiagc->Pim_Adc1FltCntSt6) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_Adc1ScanGroup2RefFltCntSt() (Rte_Inst_CDD_AdcDiagc->Pim_Adc1ScanGroup2RefFltCntSt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_Adc1ScanGroup3RefFltCntSt() (Rte_Inst_CDD_AdcDiagc->Pim_Adc1ScanGroup3RefFltCntSt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_AdcDiagcEndPtr() (Rte_Inst_CDD_AdcDiagc->Pim_AdcDiagcEndPtr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_AdcDiagcSt() (Rte_Inst_CDD_AdcDiagc->Pim_AdcDiagcSt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_AdcDiagcStrtPtr() (Rte_Inst_CDD_AdcDiagc->Pim_AdcDiagcStrtPtr) /* PRQA S 3453 */ /* MD_MSR_19.7 */




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   uint8 *Rte_Pim_Adc0FltCntSt0(void)
 *   uint8 *Rte_Pim_Adc0FltCntSt2(void)
 *   uint8 *Rte_Pim_Adc0FltCntSt4(void)
 *   uint8 *Rte_Pim_Adc0FltCntSt6(void)
 *   uint8 *Rte_Pim_Adc0ScanGroup2RefFltCntSt(void)
 *   uint8 *Rte_Pim_Adc0ScanGroup3RefFltCntSt(void)
 *   uint8 *Rte_Pim_Adc1FltCntSt0(void)
 *   uint8 *Rte_Pim_Adc1FltCntSt2(void)
 *   uint8 *Rte_Pim_Adc1FltCntSt4(void)
 *   uint8 *Rte_Pim_Adc1FltCntSt6(void)
 *   uint8 *Rte_Pim_Adc1ScanGroup2RefFltCntSt(void)
 *   uint8 *Rte_Pim_Adc1ScanGroup3RefFltCntSt(void)
 *   uint8 *Rte_Pim_AdcDiagcEndPtr(void)
 *   uint8 *Rte_Pim_AdcDiagcSt(void)
 *   uint8 *Rte_Pim_AdcDiagcStrtPtr(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   uint16 Rte_Prm_AdcDiagcNtc0x032FailStep_Val(void)
 *   uint16 Rte_Prm_AdcDiagcNtc0x032PassStep_Val(void)
 *   uint16 Rte_Prm_AdcDiagcNtc0x033FailStep_Val(void)
 *   uint16 Rte_Prm_AdcDiagcNtc0x033PassStep_Val(void)
 *
 *********************************************************************************************************************/


# define CDD_AdcDiagc_START_SEC_CODE
# include "CDD_AdcDiagc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: AdcDiagcInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_AdcDiagcInit1 AdcDiagcInit1
FUNC(void, CDD_AdcDiagc_CODE) AdcDiagcInit1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AdcDiagcPer1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_Adc0ScanGroup2Ref0_Val(float32 *data)
 *   Std_ReturnType Rte_Read_Adc0ScanGroup2Ref1_Val(float32 *data)
 *   Std_ReturnType Rte_Read_Adc0ScanGroup3Ref0_Val(float32 *data)
 *   Std_ReturnType Rte_Read_Adc0ScanGroup3Ref1_Val(float32 *data)
 *   Std_ReturnType Rte_Read_Adc0SelfDiag0_Val(float32 *data)
 *   Std_ReturnType Rte_Read_Adc0SelfDiag2_Val(float32 *data)
 *   Std_ReturnType Rte_Read_Adc0SelfDiag4_Val(float32 *data)
 *   Std_ReturnType Rte_Read_Adc1ScanGroup2Ref0_Val(float32 *data)
 *   Std_ReturnType Rte_Read_Adc1ScanGroup2Ref1_Val(float32 *data)
 *   Std_ReturnType Rte_Read_Adc1ScanGroup3Ref0_Val(float32 *data)
 *   Std_ReturnType Rte_Read_Adc1ScanGroup3Ref1_Val(float32 *data)
 *   Std_ReturnType Rte_Read_Adc1SelfDiag0_Val(float32 *data)
 *   Std_ReturnType Rte_Read_Adc1SelfDiag2_Val(float32 *data)
 *   Std_ReturnType Rte_Read_Adc1SelfDiag4_Val(float32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_Adc0Faild_Logl(boolean data)
 *   Std_ReturnType Rte_Write_Adc1Faild_Logl(boolean data)
 *   Std_ReturnType Rte_Write_AdcDiagcEndPtrOutp_Val(uint8 data)
 *   Std_ReturnType Rte_Write_AdcDiagcStrtPtrOutp_Val(uint8 data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_GetNtcQlfrSts_Oper(NtcNr1 NtcNr_Arg, SigQlfr1 *NtcQlfr_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_GetNtcQlfrSts_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_ReadErrInjReg_Oper(uint32 *ErrId_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetNtcSts_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_StrtErrInjCntr_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_AdcDiagcPer1 AdcDiagcPer1
FUNC(void, CDD_AdcDiagc_CODE) AdcDiagcPer1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define CDD_AdcDiagc_STOP_SEC_CODE
# include "CDD_AdcDiagc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_GetNtcQlfrSts_PortIf1_E_NOT_OK (1U)

# define RTE_E_SetNtcSts_PortIf1_E_NOT_OK (1U)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CDD_ADCDIAGC_H */

#include "Rte_Stubs.h"
