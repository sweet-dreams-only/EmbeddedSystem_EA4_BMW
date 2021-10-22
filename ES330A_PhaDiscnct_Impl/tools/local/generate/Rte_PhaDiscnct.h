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
 *          File:  Rte_PhaDiscnct.h
 *        Config:  C:/Users/nz2999/Documents/Synergy/ccm_wa/ses_dev_ea4/ES330A_PhaDiscnct_Impl-nz2999/ES330A_PhaDiscnct_Impl/tools/Component.dpa
 *     SW-C Type:  PhaDiscnct
 *  Generated at:  Mon Sep 25 13:23:52 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <PhaDiscnct> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_PHADISCNCT_H
# define _RTE_PHADISCNCT_H

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

# include "Rte_PhaDiscnct_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_PhaDiscnct
{
  /* PIM Handles section */
  P2VAR(uint32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_DiscnctClsTmr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_DiscnctDiagCurrComp; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_DiscnctDiagFailScan; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_DiscnctDiagFltSts; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_DiscnctDiagItrn; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_DiscnctDiagSt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_DiscnctDiagTestScan; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_DiscnctFltPrm; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_DiscnctOpenTmr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_DiscnctSt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_PrevDiscnctCmd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_WrmIninTestCmpl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dPhaDiscnctActvd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dPhaDiscnctCmd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_PhaDiscnct, RTE_CONST, RTE_CONST) Rte_Inst_PhaDiscnct; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_PhaDiscnct, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_DiagcStsIvtr1Inactv_Logl (FALSE)
# define Rte_InitValue_IvtrFetFltPha_Val (0U)
# define Rte_InitValue_IvtrFetFltTyp_Val (0U)
# define Rte_InitValue_MotCurrCorrdA_Val (0.0F)
# define Rte_InitValue_MotCurrCorrdB_Val (0.0F)
# define Rte_InitValue_MotCurrCorrdC_Val (0.0F)
# define Rte_InitValue_MotCurrQlfr1_Val (0U)
# define Rte_InitValue_PhaDiscnctDiagcActv_Logl (FALSE)
# define Rte_InitValue_PhaDiscnctDiagcPwmVect_Val (0U)
# define Rte_InitValue_PhaDiscnctInactv_Logl (FALSE)
# define Rte_InitValue_PhaDiscnctWrmIninTestCmpl_Logl (FALSE)
# define Rte_InitValue_StrtUpSt_Val (0U)
# define Rte_InitValue_SysSt_Val (3U)


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PhaDiscnct_DiagcStsIvtr1Inactv_Logl(P2VAR(boolean, AUTOMATIC, RTE_PHADISCNCT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PhaDiscnct_IvtrFetFltPha_Val(P2VAR(IvtrFetFltPha1, AUTOMATIC, RTE_PHADISCNCT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PhaDiscnct_IvtrFetFltTyp_Val(P2VAR(IvtrFetFltTyp1, AUTOMATIC, RTE_PHADISCNCT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PhaDiscnct_MotCurrCorrdA_Val(P2VAR(float32, AUTOMATIC, RTE_PHADISCNCT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PhaDiscnct_MotCurrCorrdB_Val(P2VAR(float32, AUTOMATIC, RTE_PHADISCNCT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PhaDiscnct_MotCurrCorrdC_Val(P2VAR(float32, AUTOMATIC, RTE_PHADISCNCT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PhaDiscnct_MotCurrQlfr1_Val(P2VAR(SigQlfr1, AUTOMATIC, RTE_PHADISCNCT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PhaDiscnct_StrtUpSt_Val(P2VAR(uint8, AUTOMATIC, RTE_PHADISCNCT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PhaDiscnct_SysSt_Val(P2VAR(SysSt1, AUTOMATIC, RTE_PHADISCNCT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PhaDiscnct_PhaDiscnctDiagcActv_Logl(boolean data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PhaDiscnct_PhaDiscnctDiagcPwmVect_Val(PhaDiscnctPwmVect1 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PhaDiscnct_PhaDiscnctInactv_Logl(boolean data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PhaDiscnct_PhaDiscnctWrmIninTestCmpl_Logl(boolean data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PhaDiscnct_GetRefTmr100MicroSec32bit_Oper(P2VAR(uint32, AUTOMATIC, RTE_PHADISCNCT_APPL_VAR) RefTmr_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PhaDiscnct_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, P2VAR(uint32, AUTOMATIC, RTE_PHADISCNCT_APPL_VAR) TiSpan_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PhaDiscnct_IoHwAb_SetGpioPhaDiscnctA_Oper(boolean PinSt_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PhaDiscnct_IoHwAb_SetGpioPhaDiscnctB_Oper(boolean PinSt_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PhaDiscnct_IoHwAb_SetGpioPhaDiscnctC_Oper(boolean PinSt_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PhaDiscnct_SetNtcStsAndSnpshtData_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg, uint32 SpclSnpshtData0_Arg, uint32 SpclSnpshtData1_Arg, uint32 SpclSnpshtData2_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_PhaDiscnct_PhaDiscnctTestCurrTestVal_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint32, RTE_CODE) Rte_Prm_PhaDiscnct_PhaDiscnctFixdPhaOnTi_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint32, RTE_CODE) Rte_Prm_PhaDiscnct_PhaDiscnctFixdPwmPerd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint16, RTE_CODE) Rte_Prm_PhaDiscnct_PhaDiscnctClsDlyTi_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint16, RTE_CODE) Rte_Prm_PhaDiscnct_PhaDiscnctOpenDlyTi_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint8, RTE_CODE) Rte_Prm_PhaDiscnct_PhaDiscnctTestFailScanMax_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint8, RTE_CODE) Rte_Prm_PhaDiscnct_PhaDiscnctTestIninScan_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint8, RTE_CODE) Rte_Prm_PhaDiscnct_PhaDiscnctTestScanCnt_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_DiagcStsIvtr1Inactv_Logl Rte_Read_PhaDiscnct_DiagcStsIvtr1Inactv_Logl
# define Rte_Read_IvtrFetFltPha_Val Rte_Read_PhaDiscnct_IvtrFetFltPha_Val
# define Rte_Read_IvtrFetFltTyp_Val Rte_Read_PhaDiscnct_IvtrFetFltTyp_Val
# define Rte_Read_MotCurrCorrdA_Val Rte_Read_PhaDiscnct_MotCurrCorrdA_Val
# define Rte_Read_MotCurrCorrdB_Val Rte_Read_PhaDiscnct_MotCurrCorrdB_Val
# define Rte_Read_MotCurrCorrdC_Val Rte_Read_PhaDiscnct_MotCurrCorrdC_Val
# define Rte_Read_MotCurrQlfr1_Val Rte_Read_PhaDiscnct_MotCurrQlfr1_Val
# define Rte_Read_StrtUpSt_Val Rte_Read_PhaDiscnct_StrtUpSt_Val
# define Rte_Read_SysSt_Val Rte_Read_PhaDiscnct_SysSt_Val


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_PhaDiscnctDiagcActv_Logl Rte_Write_PhaDiscnct_PhaDiscnctDiagcActv_Logl
# define Rte_Write_PhaDiscnctDiagcPwmVect_Val Rte_Write_PhaDiscnct_PhaDiscnctDiagcPwmVect_Val
# define Rte_Write_PhaDiscnctInactv_Logl Rte_Write_PhaDiscnct_PhaDiscnctInactv_Logl
# define Rte_Write_PhaDiscnctWrmIninTestCmpl_Logl Rte_Write_PhaDiscnct_PhaDiscnctWrmIninTestCmpl_Logl


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_GetRefTmr100MicroSec32bit_Oper Rte_Call_PhaDiscnct_GetRefTmr100MicroSec32bit_Oper
# define Rte_Call_GetTiSpan100MicroSec32bit_Oper Rte_Call_PhaDiscnct_GetTiSpan100MicroSec32bit_Oper
# define Rte_Call_IoHwAb_SetGpioPhaDiscnctA_Oper Rte_Call_PhaDiscnct_IoHwAb_SetGpioPhaDiscnctA_Oper
# define Rte_Call_IoHwAb_SetGpioPhaDiscnctB_Oper Rte_Call_PhaDiscnct_IoHwAb_SetGpioPhaDiscnctB_Oper
# define Rte_Call_IoHwAb_SetGpioPhaDiscnctC_Oper Rte_Call_PhaDiscnct_IoHwAb_SetGpioPhaDiscnctC_Oper
# define Rte_Call_SetNtcStsAndSnpshtData_Oper Rte_Call_PhaDiscnct_SetNtcStsAndSnpshtData_Oper


/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

# define Rte_Prm_PhaDiscnctTestCurrTestVal_Val Rte_Prm_PhaDiscnct_PhaDiscnctTestCurrTestVal_Val

# define Rte_Prm_PhaDiscnctFixdPhaOnTi_Val Rte_Prm_PhaDiscnct_PhaDiscnctFixdPhaOnTi_Val

# define Rte_Prm_PhaDiscnctFixdPwmPerd_Val Rte_Prm_PhaDiscnct_PhaDiscnctFixdPwmPerd_Val

# define Rte_Prm_PhaDiscnctClsDlyTi_Val Rte_Prm_PhaDiscnct_PhaDiscnctClsDlyTi_Val

# define Rte_Prm_PhaDiscnctOpenDlyTi_Val Rte_Prm_PhaDiscnct_PhaDiscnctOpenDlyTi_Val

# define Rte_Prm_PhaDiscnctTestFailScanMax_Val Rte_Prm_PhaDiscnct_PhaDiscnctTestFailScanMax_Val

# define Rte_Prm_PhaDiscnctTestIninScan_Val Rte_Prm_PhaDiscnct_PhaDiscnctTestIninScan_Val

# define Rte_Prm_PhaDiscnctTestScanCnt_Val Rte_Prm_PhaDiscnct_PhaDiscnctTestScanCnt_Val

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_DiscnctClsTmr() (Rte_Inst_PhaDiscnct->Pim_DiscnctClsTmr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_DiscnctOpenTmr() (Rte_Inst_PhaDiscnct->Pim_DiscnctOpenTmr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_DiscnctDiagCurrComp() (Rte_Inst_PhaDiscnct->Pim_DiscnctDiagCurrComp) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_DiscnctDiagFailScan() (Rte_Inst_PhaDiscnct->Pim_DiscnctDiagFailScan) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_DiscnctDiagFltSts() (Rte_Inst_PhaDiscnct->Pim_DiscnctDiagFltSts) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_DiscnctDiagItrn() (Rte_Inst_PhaDiscnct->Pim_DiscnctDiagItrn) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_DiscnctDiagSt() (Rte_Inst_PhaDiscnct->Pim_DiscnctDiagSt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_DiscnctDiagTestScan() (Rte_Inst_PhaDiscnct->Pim_DiscnctDiagTestScan) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_DiscnctFltPrm() (Rte_Inst_PhaDiscnct->Pim_DiscnctFltPrm) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_DiscnctSt() (Rte_Inst_PhaDiscnct->Pim_DiscnctSt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_PrevDiscnctCmd() (Rte_Inst_PhaDiscnct->Pim_PrevDiscnctCmd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dPhaDiscnctCmd() (Rte_Inst_PhaDiscnct->Pim_dPhaDiscnctCmd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_WrmIninTestCmpl() (Rte_Inst_PhaDiscnct->Pim_WrmIninTestCmpl) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dPhaDiscnctActvd() (Rte_Inst_PhaDiscnct->Pim_dPhaDiscnctActvd) /* PRQA S 3453 */ /* MD_MSR_19.7 */




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   uint32 *Rte_Pim_DiscnctClsTmr(void)
 *   uint32 *Rte_Pim_DiscnctOpenTmr(void)
 *   uint8 *Rte_Pim_DiscnctDiagCurrComp(void)
 *   uint8 *Rte_Pim_DiscnctDiagFailScan(void)
 *   uint8 *Rte_Pim_DiscnctDiagFltSts(void)
 *   uint8 *Rte_Pim_DiscnctDiagItrn(void)
 *   uint8 *Rte_Pim_DiscnctDiagSt(void)
 *   uint8 *Rte_Pim_DiscnctDiagTestScan(void)
 *   uint8 *Rte_Pim_DiscnctFltPrm(void)
 *   uint8 *Rte_Pim_DiscnctSt(void)
 *   uint8 *Rte_Pim_PrevDiscnctCmd(void)
 *   uint8 *Rte_Pim_dPhaDiscnctCmd(void)
 *   boolean *Rte_Pim_WrmIninTestCmpl(void)
 *   boolean *Rte_Pim_dPhaDiscnctActvd(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_PhaDiscnctTestCurrTestVal_Val(void)
 *   uint32 Rte_Prm_PhaDiscnctFixdPhaOnTi_Val(void)
 *   uint32 Rte_Prm_PhaDiscnctFixdPwmPerd_Val(void)
 *   uint16 Rte_Prm_PhaDiscnctClsDlyTi_Val(void)
 *   uint16 Rte_Prm_PhaDiscnctOpenDlyTi_Val(void)
 *   uint8 Rte_Prm_PhaDiscnctTestFailScanMax_Val(void)
 *   uint8 Rte_Prm_PhaDiscnctTestIninScan_Val(void)
 *   uint8 Rte_Prm_PhaDiscnctTestScanCnt_Val(void)
 *
 *********************************************************************************************************************/


# define PhaDiscnct_START_SEC_CODE
# include "PhaDiscnct_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: PhaDiscnctInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_IoHwAb_SetGpioPhaDiscnctA_Oper(boolean PinSt_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetGpioPhaDiscnctB_Oper(boolean PinSt_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetGpioPhaDiscnctC_Oper(boolean PinSt_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetGpio_PortIf1_E_NOT_OK
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_PhaDiscnctInit1 PhaDiscnctInit1
FUNC(void, PhaDiscnct_CODE) PhaDiscnctInit1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PhaDiscnctPer1
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
 *   Std_ReturnType Rte_Read_DiagcStsIvtr1Inactv_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_IvtrFetFltTyp_Val(IvtrFetFltTyp1 *data)
 *   Std_ReturnType Rte_Read_MotCurrCorrdA_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotCurrCorrdB_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotCurrCorrdC_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotCurrQlfr1_Val(SigQlfr1 *data)
 *   Std_ReturnType Rte_Read_StrtUpSt_Val(uint8 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_PhaDiscnctDiagcActv_Logl(boolean data)
 *   Std_ReturnType Rte_Write_PhaDiscnctDiagcPwmVect_Val(PhaDiscnctPwmVect1 data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_IoHwAb_SetGpioPhaDiscnctA_Oper(boolean PinSt_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetGpioPhaDiscnctB_Oper(boolean PinSt_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetGpioPhaDiscnctC_Oper(boolean PinSt_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_SetNtcStsAndSnpshtData_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg, uint32 SpclSnpshtData0_Arg, uint32 SpclSnpshtData1_Arg, uint32 SpclSnpshtData2_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetNtcStsAndSnpshtData_PortIf1_E_NOT_OK
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_PhaDiscnctPer1 PhaDiscnctPer1
FUNC(void, PhaDiscnct_CODE) PhaDiscnctPer1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PhaDiscnctPer2
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
 *   Std_ReturnType Rte_Read_IvtrFetFltPha_Val(IvtrFetFltPha1 *data)
 *   Std_ReturnType Rte_Read_IvtrFetFltTyp_Val(IvtrFetFltTyp1 *data)
 *   Std_ReturnType Rte_Read_StrtUpSt_Val(uint8 *data)
 *   Std_ReturnType Rte_Read_SysSt_Val(SysSt1 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_PhaDiscnctInactv_Logl(boolean data)
 *   Std_ReturnType Rte_Write_PhaDiscnctWrmIninTestCmpl_Logl(boolean data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_GetRefTmr100MicroSec32bit_Oper(uint32 *RefTmr_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_IoHwAb_SetGpioPhaDiscnctA_Oper(boolean PinSt_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetGpioPhaDiscnctB_Oper(boolean PinSt_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetGpioPhaDiscnctC_Oper(boolean PinSt_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetGpio_PortIf1_E_NOT_OK
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_PhaDiscnctPer2 PhaDiscnctPer2
FUNC(void, PhaDiscnct_CODE) PhaDiscnctPer2(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define PhaDiscnct_STOP_SEC_CODE
# include "PhaDiscnct_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_SetGpio_PortIf1_E_NOT_OK (1U)

# define RTE_E_SetNtcStsAndSnpshtData_PortIf1_E_NOT_OK (1U)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_PHADISCNCT_H */

#include "Rte_Stubs.h"
