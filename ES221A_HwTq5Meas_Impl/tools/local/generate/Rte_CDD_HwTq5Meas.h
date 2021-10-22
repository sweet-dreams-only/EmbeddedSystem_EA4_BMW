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
 *          File:  Rte_CDD_HwTq5Meas.h
 *        Config:  C:/Component/ES221A_HwTq5Meas_Impl/tools/Component.dpa
 *     SW-C Type:  CDD_HwTq5Meas
 *  Generated at:  Tue Nov  7 10:50:57 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <CDD_HwTq5Meas> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CDD_HWTQ5MEAS_H
# define _RTE_CDD_HWTQ5MEAS_H

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

# include "Rte_CDD_HwTq5Meas_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_CDD_HwTq5Meas
{
  /* PIM Handles section */
  P2VAR(HwTqOffsRec1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_HwTq5Offs; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_HwTq5PrevHwTq5; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_HwTq5PrevRollgCntr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_HwTq5RawFastAdcIdxCntr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(AnHwTqScaFacRec1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_HwTq5Sca; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_CDD_HwTq5Meas, RTE_CONST, RTE_CONST) Rte_Inst_CDD_HwTq5Meas; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_CDD_HwTq5Meas, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_HwTq5_Val (0.0F)
# define Rte_InitValue_HwTq5Polarity_Val (1)
# define Rte_InitValue_HwTq5Qlfr_Val (0U)
# define Rte_InitValue_HwTq5RawAdc_Val (0.0F)
# define Rte_InitValue_HwTq5RawAdcAdcFaild_Logl (FALSE)
# define Rte_InitValue_HwTq5RawFastAdcAdcFaild_Logl (FALSE)
# define Rte_InitValue_HwTq5RollgCntr_Val (0U)


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_HwTq5Meas_HwTq5Polarity_Val(P2VAR(sint8, AUTOMATIC, RTE_CDD_HWTQ5MEAS_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_HwTq5Meas_HwTq5RawAdc_Val(P2VAR(float32, AUTOMATIC, RTE_CDD_HWTQ5MEAS_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_HwTq5Meas_HwTq5RawAdcAdcFaild_Logl(P2VAR(boolean, AUTOMATIC, RTE_CDD_HWTQ5MEAS_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_HwTq5Meas_HwTq5RawFastAdcAdcFaild_Logl(P2VAR(boolean, AUTOMATIC, RTE_CDD_HWTQ5MEAS_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_HwTq5Meas_HwTq5RawFastAdcBuf_Ary1D(P2VAR(float32, AUTOMATIC, RTE_CDD_HWTQ5MEAS_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_HwTq5Meas_HwTq5RawFastAdcBuf_Ary1D(P2VAR(Ary1D_f32_8, AUTOMATIC, RTE_CDD_HWTQ5MEAS_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_HwTq5Meas_HwTq5_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_HwTq5Meas_HwTq5Qlfr_Val(SigQlfr1 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_HwTq5Meas_HwTq5RollgCntr_Val(uint8 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_HwTq5Meas_GetNtcQlfrSts_Oper(NtcNr1 NtcNr_Arg, P2VAR(SigQlfr1, AUTOMATIC, RTE_CDD_HWTQ5MEAS_APPL_VAR) NtcQlfr_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_HwTq5Meas_HwTq5Offs_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_CDD_HWTQ5MEAS_APPL_VAR) ErrorStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_HwTq5Meas_HwTq5Offs_SetRamBlockStatus(Boolean RamBlockStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_HwTq5Meas_HwTq5Sca_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_CDD_HWTQ5MEAS_APPL_VAR) ErrorStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_HwTq5Meas_HwTq5Sca_SetRamBlockStatus(Boolean RamBlockStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_HwTq5Meas_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_CDD_HwTq5Meas_HwTq5MeasHwTqRngHiLim_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_CDD_HwTq5Meas_HwTq5MeasHwTqRngLoLim_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint16, RTE_CODE) Rte_Prm_CDD_HwTq5Meas_HwTq5MeasHwTq5PrtclFltFailStep_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint16, RTE_CODE) Rte_Prm_CDD_HwTq5Meas_HwTq5MeasHwTq5PrtclFltPassStep_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(boolean, RTE_CODE) Rte_Prm_CDD_HwTq5Meas_HwTq5MeasMovgAvrgFilEna_Logl(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_HwTq5Polarity_Val Rte_Read_CDD_HwTq5Meas_HwTq5Polarity_Val
# define Rte_Read_HwTq5RawAdc_Val Rte_Read_CDD_HwTq5Meas_HwTq5RawAdc_Val
# define Rte_Read_HwTq5RawAdcAdcFaild_Logl Rte_Read_CDD_HwTq5Meas_HwTq5RawAdcAdcFaild_Logl
# define Rte_Read_HwTq5RawFastAdcAdcFaild_Logl Rte_Read_CDD_HwTq5Meas_HwTq5RawFastAdcAdcFaild_Logl
# define Rte_Read_HwTq5RawFastAdcBuf_Ary1D Rte_Read_CDD_HwTq5Meas_HwTq5RawFastAdcBuf_Ary1D


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_HwTq5_Val Rte_Write_CDD_HwTq5Meas_HwTq5_Val
# define Rte_Write_HwTq5Qlfr_Val Rte_Write_CDD_HwTq5Meas_HwTq5Qlfr_Val
# define Rte_Write_HwTq5RollgCntr_Val Rte_Write_CDD_HwTq5Meas_HwTq5RollgCntr_Val


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_GetNtcQlfrSts_Oper Rte_Call_CDD_HwTq5Meas_GetNtcQlfrSts_Oper
# define Rte_Call_HwTq5Offs_GetErrorStatus Rte_Call_CDD_HwTq5Meas_HwTq5Offs_GetErrorStatus
# define Rte_Call_HwTq5Offs_SetRamBlockStatus Rte_Call_CDD_HwTq5Meas_HwTq5Offs_SetRamBlockStatus
# define Rte_Call_HwTq5Sca_GetErrorStatus Rte_Call_CDD_HwTq5Meas_HwTq5Sca_GetErrorStatus
# define Rte_Call_HwTq5Sca_SetRamBlockStatus Rte_Call_CDD_HwTq5Meas_HwTq5Sca_SetRamBlockStatus
# define Rte_Call_SetNtcSts_Oper Rte_Call_CDD_HwTq5Meas_SetNtcSts_Oper


/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

# define Rte_Prm_HwTq5MeasHwTqRngHiLim_Val Rte_Prm_CDD_HwTq5Meas_HwTq5MeasHwTqRngHiLim_Val

# define Rte_Prm_HwTq5MeasHwTqRngLoLim_Val Rte_Prm_CDD_HwTq5Meas_HwTq5MeasHwTqRngLoLim_Val

# define Rte_Prm_HwTq5MeasHwTq5PrtclFltFailStep_Val Rte_Prm_CDD_HwTq5Meas_HwTq5MeasHwTq5PrtclFltFailStep_Val

# define Rte_Prm_HwTq5MeasHwTq5PrtclFltPassStep_Val Rte_Prm_CDD_HwTq5Meas_HwTq5MeasHwTq5PrtclFltPassStep_Val

# define Rte_Prm_HwTq5MeasMovgAvrgFilEna_Logl Rte_Prm_CDD_HwTq5Meas_HwTq5MeasMovgAvrgFilEna_Logl

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_HwTq5PrevHwTq5() (Rte_Inst_CDD_HwTq5Meas->Pim_HwTq5PrevHwTq5) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_HwTq5PrevRollgCntr() (Rte_Inst_CDD_HwTq5Meas->Pim_HwTq5PrevRollgCntr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_HwTq5RawFastAdcIdxCntr() (Rte_Inst_CDD_HwTq5Meas->Pim_HwTq5RawFastAdcIdxCntr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_HwTq5Offs() (Rte_Inst_CDD_HwTq5Meas->Pim_HwTq5Offs) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_HwTq5Sca() (Rte_Inst_CDD_HwTq5Meas->Pim_HwTq5Sca) /* PRQA S 3453 */ /* MD_MSR_19.7 */




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   float32 *Rte_Pim_HwTq5PrevHwTq5(void)
 *   uint8 *Rte_Pim_HwTq5PrevRollgCntr(void)
 *   uint8 *Rte_Pim_HwTq5RawFastAdcIdxCntr(void)
 *   HwTqOffsRec1 *Rte_Pim_HwTq5Offs(void)
 *   AnHwTqScaFacRec1 *Rte_Pim_HwTq5Sca(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_HwTq5MeasHwTqRngHiLim_Val(void)
 *   float32 Rte_Prm_HwTq5MeasHwTqRngLoLim_Val(void)
 *   uint16 Rte_Prm_HwTq5MeasHwTq5PrtclFltFailStep_Val(void)
 *   uint16 Rte_Prm_HwTq5MeasHwTq5PrtclFltPassStep_Val(void)
 *   boolean Rte_Prm_HwTq5MeasMovgAvrgFilEna_Logl(void)
 *
 *********************************************************************************************************************/


# define CDD_HwTq5Meas_START_SEC_CODE
# include "CDD_HwTq5Meas_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTq5AutTrim_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <HwTq5AutTrim>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_HwTq5Offs_SetRamBlockStatus(Boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void HwTq5AutTrim_Oper(void)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_HwTq5AutTrim_Oper HwTq5AutTrim_Oper
FUNC(void, CDD_HwTq5Meas_CODE) HwTq5AutTrim_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTq5ClrSnsrSca_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <HwTq5ClrSnsrSca>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_HwTq5Sca_SetRamBlockStatus(Boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void HwTq5ClrSnsrSca_Oper(void)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_HwTq5ClrSnsrSca_Oper HwTq5ClrSnsrSca_Oper
FUNC(void, CDD_HwTq5Meas_CODE) HwTq5ClrSnsrSca_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTq5ClrTrim_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <HwTq5ClrTrim>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_HwTq5Offs_SetRamBlockStatus(Boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void HwTq5ClrTrim_Oper(void)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_HwTq5ClrTrim_Oper HwTq5ClrTrim_Oper
FUNC(void, CDD_HwTq5Meas_CODE) HwTq5ClrTrim_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTq5MeasInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_HwTq5Offs_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_HwTq5Sca_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_HwTq5MeasInit1 HwTq5MeasInit1
FUNC(void, CDD_HwTq5Meas_CODE) HwTq5MeasInit1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTq5MeasPer2
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
 *   Std_ReturnType Rte_Read_HwTq5Polarity_Val(sint8 *data)
 *   Std_ReturnType Rte_Read_HwTq5RawAdc_Val(float32 *data)
 *   Std_ReturnType Rte_Read_HwTq5RawAdcAdcFaild_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_HwTq5RawFastAdcAdcFaild_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_HwTq5RawFastAdcBuf_Ary1D(float32 *data)
 *     Argument data: float32* is of type Ary1D_f32_8
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_HwTq5_Val(float32 data)
 *   Std_ReturnType Rte_Write_HwTq5Qlfr_Val(SigQlfr1 data)
 *   Std_ReturnType Rte_Write_HwTq5RollgCntr_Val(uint8 data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_GetNtcQlfrSts_Oper(NtcNr1 NtcNr_Arg, SigQlfr1 *NtcQlfr_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_GetNtcQlfrSts_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetNtcSts_PortIf1_E_NOT_OK
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_HwTq5MeasPer2 HwTq5MeasPer2
FUNC(void, CDD_HwTq5Meas_CODE) HwTq5MeasPer2(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTq5MeasPer3
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 100ms
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetNtcSts_PortIf1_E_NOT_OK
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_HwTq5MeasPer3 HwTq5MeasPer3
FUNC(void, CDD_HwTq5Meas_CODE) HwTq5MeasPer3(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTq5MeasPer4
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 100ms
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetNtcSts_PortIf1_E_NOT_OK
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_HwTq5MeasPer4 HwTq5MeasPer4
FUNC(void, CDD_HwTq5Meas_CODE) HwTq5MeasPer4(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTq5ReadSnsrSca_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <HwTq5ReadSnsrSca>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void HwTq5ReadSnsrSca_Oper(float32 *HwTqReadScaData_Arg)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_HwTq5ReadSnsrSca_Oper HwTq5ReadSnsrSca_Oper
FUNC(void, CDD_HwTq5Meas_CODE) HwTq5ReadSnsrSca_Oper(P2VAR(float32, AUTOMATIC, RTE_CDD_HWTQ5MEAS_APPL_VAR) HwTqReadScaData_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTq5ReadTrim_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <HwTq5ReadTrim>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void HwTq5ReadTrim_Oper(float32 *HwTqReadTrimData_Arg)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_HwTq5ReadTrim_Oper HwTq5ReadTrim_Oper
FUNC(void, CDD_HwTq5Meas_CODE) HwTq5ReadTrim_Oper(P2VAR(float32, AUTOMATIC, RTE_CDD_HWTQ5MEAS_APPL_VAR) HwTqReadTrimData_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTq5SnsrScaPrfmdSts_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <HwTq5SnsrScaPrfmdSts>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void HwTq5SnsrScaPrfmdSts_Oper(boolean *HwTqScaPrfmdStsData_Arg)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_HwTq5SnsrScaPrfmdSts_Oper HwTq5SnsrScaPrfmdSts_Oper
FUNC(void, CDD_HwTq5Meas_CODE) HwTq5SnsrScaPrfmdSts_Oper(P2VAR(boolean, AUTOMATIC, RTE_CDD_HWTQ5MEAS_APPL_VAR) HwTqScaPrfmdStsData_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTq5TrimPrfmdSts_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <HwTq5TrimPrfmdSts>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void HwTq5TrimPrfmdSts_Oper(boolean *HwTqOffsTrimPrfmdStsData_Arg)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_HwTq5TrimPrfmdSts_Oper HwTq5TrimPrfmdSts_Oper
FUNC(void, CDD_HwTq5Meas_CODE) HwTq5TrimPrfmdSts_Oper(P2VAR(boolean, AUTOMATIC, RTE_CDD_HWTQ5MEAS_APPL_VAR) HwTqOffsTrimPrfmdStsData_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTq5WrSnsrSca_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <HwTq5WrSnsrSca>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_HwTq5Sca_SetRamBlockStatus(Boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void HwTq5WrSnsrSca_Oper(float32 HwTqScaVal_Arg)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_HwTq5WrSnsrSca_Oper HwTq5WrSnsrSca_Oper
FUNC(void, CDD_HwTq5Meas_CODE) HwTq5WrSnsrSca_Oper(float32 HwTqScaVal_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTq5WrTrim_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <HwTq5WrTrim>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_HwTq5Offs_SetRamBlockStatus(Boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void HwTq5WrTrim_Oper(float32 HwTqWrOffsTrimData_Arg)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_HwTq5WrTrim_Oper HwTq5WrTrim_Oper
FUNC(void, CDD_HwTq5Meas_CODE) HwTq5WrTrim_Oper(float32 HwTqWrOffsTrimData_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define CDD_HwTq5Meas_STOP_SEC_CODE
# include "CDD_HwTq5Meas_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_GetNtcQlfrSts_PortIf1_E_NOT_OK (1U)

# define RTE_E_NvMService_AC3_SRBS_E_NOT_OK (1U)

# define RTE_E_SetNtcSts_PortIf1_E_NOT_OK (1U)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CDD_HWTQ5MEAS_H */
