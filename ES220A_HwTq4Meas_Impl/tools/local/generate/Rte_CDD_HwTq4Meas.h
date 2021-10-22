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
 *          File:  Rte_CDD_HwTq4Meas.h
 *        Config:  C:/Component/ES220A_HwTq4Meas_Impl/tools/Component.dpa
 *     SW-C Type:  CDD_HwTq4Meas
 *  Generated at:  Wed Nov 15 11:08:52 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <CDD_HwTq4Meas> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CDD_HWTQ4MEAS_H
# define _RTE_CDD_HWTQ4MEAS_H

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

# include "Rte_CDD_HwTq4Meas_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_CDD_HwTq4Meas
{
  /* PIM Handles section */
  P2VAR(HwTqOffsRec1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_HwTq4Offs; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_HwTq4PrevHwTq4; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_HwTq4PrevRollgCntr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_HwTq4RawFastAdcIdxCntr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(AnHwTqScaFacRec1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_HwTq4Sca; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_CDD_HwTq4Meas, RTE_CONST, RTE_CONST) Rte_Inst_CDD_HwTq4Meas; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_CDD_HwTq4Meas, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_HwTq4_Val (0.0F)
# define Rte_InitValue_HwTq4Polarity_Val (1)
# define Rte_InitValue_HwTq4Qlfr_Val (0U)
# define Rte_InitValue_HwTq4RawAdc_Val (0.0F)
# define Rte_InitValue_HwTq4RawAdcAdcFaild_Logl (FALSE)
# define Rte_InitValue_HwTq4RawFastAdcAdcFaild_Logl (FALSE)
# define Rte_InitValue_HwTq4RollgCntr_Val (0U)


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_HwTq4Meas_HwTq4Polarity_Val(P2VAR(sint8, AUTOMATIC, RTE_CDD_HWTQ4MEAS_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_HwTq4Meas_HwTq4RawAdc_Val(P2VAR(float32, AUTOMATIC, RTE_CDD_HWTQ4MEAS_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_HwTq4Meas_HwTq4RawAdcAdcFaild_Logl(P2VAR(boolean, AUTOMATIC, RTE_CDD_HWTQ4MEAS_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_HwTq4Meas_HwTq4RawFastAdcAdcFaild_Logl(P2VAR(boolean, AUTOMATIC, RTE_CDD_HWTQ4MEAS_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_HwTq4Meas_HwTq4RawFastAdcBuf_Ary1D(P2VAR(float32, AUTOMATIC, RTE_CDD_HWTQ4MEAS_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_HwTq4Meas_HwTq4RawFastAdcBuf_Ary1D(P2VAR(Ary1D_f32_8, AUTOMATIC, RTE_CDD_HWTQ4MEAS_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_HwTq4Meas_HwTq4_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_HwTq4Meas_HwTq4Qlfr_Val(SigQlfr1 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_HwTq4Meas_HwTq4RollgCntr_Val(uint8 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_HwTq4Meas_GetNtcQlfrSts_Oper(NtcNr1 NtcNr_Arg, P2VAR(SigQlfr1, AUTOMATIC, RTE_CDD_HWTQ4MEAS_APPL_VAR) NtcQlfr_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_HwTq4Meas_HwTq4Offs_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_CDD_HWTQ4MEAS_APPL_VAR) ErrorStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_HwTq4Meas_HwTq4Offs_SetRamBlockStatus(Boolean RamBlockStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_HwTq4Meas_HwTq4Sca_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_CDD_HWTQ4MEAS_APPL_VAR) ErrorStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_HwTq4Meas_HwTq4Sca_SetRamBlockStatus(Boolean RamBlockStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_HwTq4Meas_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_CDD_HwTq4Meas_HwTq4MeasHwTqRngHiLim_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_CDD_HwTq4Meas_HwTq4MeasHwTqRngLoLim_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint16, RTE_CODE) Rte_Prm_CDD_HwTq4Meas_HwTq4MeasHwTq4PrtclFltFailStep_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint16, RTE_CODE) Rte_Prm_CDD_HwTq4Meas_HwTq4MeasHwTq4PrtclFltPassStep_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(boolean, RTE_CODE) Rte_Prm_CDD_HwTq4Meas_HwTq4MeasMovgAvrgFilEna_Logl(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_HwTq4Polarity_Val Rte_Read_CDD_HwTq4Meas_HwTq4Polarity_Val
# define Rte_Read_HwTq4RawAdc_Val Rte_Read_CDD_HwTq4Meas_HwTq4RawAdc_Val
# define Rte_Read_HwTq4RawAdcAdcFaild_Logl Rte_Read_CDD_HwTq4Meas_HwTq4RawAdcAdcFaild_Logl
# define Rte_Read_HwTq4RawFastAdcAdcFaild_Logl Rte_Read_CDD_HwTq4Meas_HwTq4RawFastAdcAdcFaild_Logl
# define Rte_Read_HwTq4RawFastAdcBuf_Ary1D Rte_Read_CDD_HwTq4Meas_HwTq4RawFastAdcBuf_Ary1D


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_HwTq4_Val Rte_Write_CDD_HwTq4Meas_HwTq4_Val
# define Rte_Write_HwTq4Qlfr_Val Rte_Write_CDD_HwTq4Meas_HwTq4Qlfr_Val
# define Rte_Write_HwTq4RollgCntr_Val Rte_Write_CDD_HwTq4Meas_HwTq4RollgCntr_Val


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_GetNtcQlfrSts_Oper Rte_Call_CDD_HwTq4Meas_GetNtcQlfrSts_Oper
# define Rte_Call_HwTq4Offs_GetErrorStatus Rte_Call_CDD_HwTq4Meas_HwTq4Offs_GetErrorStatus
# define Rte_Call_HwTq4Offs_SetRamBlockStatus Rte_Call_CDD_HwTq4Meas_HwTq4Offs_SetRamBlockStatus
# define Rte_Call_HwTq4Sca_GetErrorStatus Rte_Call_CDD_HwTq4Meas_HwTq4Sca_GetErrorStatus
# define Rte_Call_HwTq4Sca_SetRamBlockStatus Rte_Call_CDD_HwTq4Meas_HwTq4Sca_SetRamBlockStatus
# define Rte_Call_SetNtcSts_Oper Rte_Call_CDD_HwTq4Meas_SetNtcSts_Oper


/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

# define Rte_Prm_HwTq4MeasHwTqRngHiLim_Val Rte_Prm_CDD_HwTq4Meas_HwTq4MeasHwTqRngHiLim_Val

# define Rte_Prm_HwTq4MeasHwTqRngLoLim_Val Rte_Prm_CDD_HwTq4Meas_HwTq4MeasHwTqRngLoLim_Val

# define Rte_Prm_HwTq4MeasHwTq4PrtclFltFailStep_Val Rte_Prm_CDD_HwTq4Meas_HwTq4MeasHwTq4PrtclFltFailStep_Val

# define Rte_Prm_HwTq4MeasHwTq4PrtclFltPassStep_Val Rte_Prm_CDD_HwTq4Meas_HwTq4MeasHwTq4PrtclFltPassStep_Val

# define Rte_Prm_HwTq4MeasMovgAvrgFilEna_Logl Rte_Prm_CDD_HwTq4Meas_HwTq4MeasMovgAvrgFilEna_Logl

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_HwTq4PrevHwTq4() (Rte_Inst_CDD_HwTq4Meas->Pim_HwTq4PrevHwTq4) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_HwTq4PrevRollgCntr() (Rte_Inst_CDD_HwTq4Meas->Pim_HwTq4PrevRollgCntr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_HwTq4RawFastAdcIdxCntr() (Rte_Inst_CDD_HwTq4Meas->Pim_HwTq4RawFastAdcIdxCntr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_HwTq4Offs() (Rte_Inst_CDD_HwTq4Meas->Pim_HwTq4Offs) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_HwTq4Sca() (Rte_Inst_CDD_HwTq4Meas->Pim_HwTq4Sca) /* PRQA S 3453 */ /* MD_MSR_19.7 */




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   float32 *Rte_Pim_HwTq4PrevHwTq4(void)
 *   uint8 *Rte_Pim_HwTq4PrevRollgCntr(void)
 *   uint8 *Rte_Pim_HwTq4RawFastAdcIdxCntr(void)
 *   HwTqOffsRec1 *Rte_Pim_HwTq4Offs(void)
 *   AnHwTqScaFacRec1 *Rte_Pim_HwTq4Sca(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_HwTq4MeasHwTqRngHiLim_Val(void)
 *   float32 Rte_Prm_HwTq4MeasHwTqRngLoLim_Val(void)
 *   uint16 Rte_Prm_HwTq4MeasHwTq4PrtclFltFailStep_Val(void)
 *   uint16 Rte_Prm_HwTq4MeasHwTq4PrtclFltPassStep_Val(void)
 *   boolean Rte_Prm_HwTq4MeasMovgAvrgFilEna_Logl(void)
 *
 *********************************************************************************************************************/


# define CDD_HwTq4Meas_START_SEC_CODE
# include "CDD_HwTq4Meas_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTq4AutTrim_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <HwTq4AutTrim>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_HwTq4Offs_SetRamBlockStatus(Boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void HwTq4AutTrim_Oper(void)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_HwTq4AutTrim_Oper HwTq4AutTrim_Oper
FUNC(void, CDD_HwTq4Meas_CODE) HwTq4AutTrim_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTq4ClrSnsrSca_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <HwTq4ClrSnsrSca>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_HwTq4Sca_SetRamBlockStatus(Boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void HwTq4ClrSnsrSca_Oper(void)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_HwTq4ClrSnsrSca_Oper HwTq4ClrSnsrSca_Oper
FUNC(void, CDD_HwTq4Meas_CODE) HwTq4ClrSnsrSca_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTq4ClrTrim_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <HwTq4ClrTrim>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_HwTq4Offs_SetRamBlockStatus(Boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void HwTq4ClrTrim_Oper(void)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_HwTq4ClrTrim_Oper HwTq4ClrTrim_Oper
FUNC(void, CDD_HwTq4Meas_CODE) HwTq4ClrTrim_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTq4MeasInit1
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
 *   Std_ReturnType Rte_Call_HwTq4Offs_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_HwTq4Sca_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_HwTq4MeasInit1 HwTq4MeasInit1
FUNC(void, CDD_HwTq4Meas_CODE) HwTq4MeasInit1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTq4MeasPer2
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
 *   Std_ReturnType Rte_Read_HwTq4Polarity_Val(sint8 *data)
 *   Std_ReturnType Rte_Read_HwTq4RawAdc_Val(float32 *data)
 *   Std_ReturnType Rte_Read_HwTq4RawAdcAdcFaild_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_HwTq4RawFastAdcAdcFaild_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_HwTq4RawFastAdcBuf_Ary1D(float32 *data)
 *     Argument data: float32* is of type Ary1D_f32_8
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_HwTq4_Val(float32 data)
 *   Std_ReturnType Rte_Write_HwTq4Qlfr_Val(SigQlfr1 data)
 *   Std_ReturnType Rte_Write_HwTq4RollgCntr_Val(uint8 data)
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

# define RTE_RUNNABLE_HwTq4MeasPer2 HwTq4MeasPer2
FUNC(void, CDD_HwTq4Meas_CODE) HwTq4MeasPer2(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTq4MeasPer3
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

# define RTE_RUNNABLE_HwTq4MeasPer3 HwTq4MeasPer3
FUNC(void, CDD_HwTq4Meas_CODE) HwTq4MeasPer3(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTq4MeasPer4
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

# define RTE_RUNNABLE_HwTq4MeasPer4 HwTq4MeasPer4
FUNC(void, CDD_HwTq4Meas_CODE) HwTq4MeasPer4(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTq4ReadSnsrSca_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <HwTq4ReadSnsrSca>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void HwTq4ReadSnsrSca_Oper(float32 *HwTqReadScaData_Arg)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_HwTq4ReadSnsrSca_Oper HwTq4ReadSnsrSca_Oper
FUNC(void, CDD_HwTq4Meas_CODE) HwTq4ReadSnsrSca_Oper(P2VAR(float32, AUTOMATIC, RTE_CDD_HWTQ4MEAS_APPL_VAR) HwTqReadScaData_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTq4ReadTrim_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <HwTq4ReadTrim>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void HwTq4ReadTrim_Oper(float32 *HwTqReadTrimData_Arg)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_HwTq4ReadTrim_Oper HwTq4ReadTrim_Oper
FUNC(void, CDD_HwTq4Meas_CODE) HwTq4ReadTrim_Oper(P2VAR(float32, AUTOMATIC, RTE_CDD_HWTQ4MEAS_APPL_VAR) HwTqReadTrimData_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTq4SnsrScaPrfmdSts_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <HwTq4SnsrScaPrfmdSts>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void HwTq4SnsrScaPrfmdSts_Oper(boolean *HwTqScaPrfmdStsData_Arg)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_HwTq4SnsrScaPrfmdSts_Oper HwTq4SnsrScaPrfmdSts_Oper
FUNC(void, CDD_HwTq4Meas_CODE) HwTq4SnsrScaPrfmdSts_Oper(P2VAR(boolean, AUTOMATIC, RTE_CDD_HWTQ4MEAS_APPL_VAR) HwTqScaPrfmdStsData_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTq4TrimPrfmdSts_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <HwTq4TrimPrfmdSts>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void HwTq4TrimPrfmdSts_Oper(boolean *HwTqOffsTrimPrfmdStsData_Arg)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_HwTq4TrimPrfmdSts_Oper HwTq4TrimPrfmdSts_Oper
FUNC(void, CDD_HwTq4Meas_CODE) HwTq4TrimPrfmdSts_Oper(P2VAR(boolean, AUTOMATIC, RTE_CDD_HWTQ4MEAS_APPL_VAR) HwTqOffsTrimPrfmdStsData_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTq4WrSnsrSca_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <HwTq4WrSnsrSca>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_HwTq4Sca_SetRamBlockStatus(Boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void HwTq4WrSnsrSca_Oper(float32 HwTqScaVal_Arg)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_HwTq4WrSnsrSca_Oper HwTq4WrSnsrSca_Oper
FUNC(void, CDD_HwTq4Meas_CODE) HwTq4WrSnsrSca_Oper(float32 HwTqScaVal_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTq4WrTrim_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <HwTq4WrTrim>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_HwTq4Offs_SetRamBlockStatus(Boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void HwTq4WrTrim_Oper(float32 HwTqWrOffsTrimData_Arg)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_HwTq4WrTrim_Oper HwTq4WrTrim_Oper
FUNC(void, CDD_HwTq4Meas_CODE) HwTq4WrTrim_Oper(float32 HwTqWrOffsTrimData_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define CDD_HwTq4Meas_STOP_SEC_CODE
# include "CDD_HwTq4Meas_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_GetNtcQlfrSts_PortIf1_E_NOT_OK (1U)

# define RTE_E_NvMService_AC3_SRBS_E_NOT_OK (1U)

# define RTE_E_SetNtcSts_PortIf1_E_NOT_OK (1U)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CDD_HWTQ4MEAS_H */
