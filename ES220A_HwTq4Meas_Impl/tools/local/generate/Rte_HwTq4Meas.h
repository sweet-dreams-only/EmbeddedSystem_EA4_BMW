/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  Copyright (c) 2006-2014 by Vctr Informatik GmbH.                                             All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_HwTq4Meas.h
 *     SW-C Type:  HwTq4Meas
 *  Generated at:  Mon Jun  6 12:02:27 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 4.3.0
 *                 RTE Core Version 1.3.0
 *       License:  Unlimited license CBD1400351 (THE ECU PRODUCT "STEERING SYSTEMS", THE ECU SUPPLIER "NXTR", THE VEHICLE MANUFACTURER "GENERAL MOTORS CORPORATION") for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <HwTq4Meas> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_HWTQ4MEAS_H
# define _RTE_HWTQ4MEAS_H

# ifdef RTE_APPLICATION_HEADER_FILE
#  error Multiple application header files included.
# endif
# define RTE_APPLICATION_HEADER_FILE
# define RTE_PTR2ARRAYBASETYPE_PASSING

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_HwTq4Meas_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_HwTq4Meas
{
  /* PIM Handles section */
  P2VAR(HwTqOffsRec1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_HwTq4Offs_MirrorBlock; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_HwTq4PrevHwTq4; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_HwTq4PrevRollgCntr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_HwTq4RawFastAdcBuf; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_HwTq4RawFastAdcIdxCntr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(AnHwTqScaFacRec1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_HwTq4Sca_MirrorBlock; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_HwTq4Meas, RTE_CONST, RTE_CONST) Rte_Inst_HwTq4Meas; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_HwTq4Meas, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_HwTq4_Val (0.0F)
# define Rte_InitValue_HwTq4FastAdcBuf_Val (0.0F)
# define Rte_InitValue_HwTq4Polarity_Val (1)
# define Rte_InitValue_HwTq4Qlfr_Val (0U)
# define Rte_InitValue_HwTq4RawAdc_Val (0.0F)
# define Rte_InitValue_HwTq4RawAdcAdcFaild_Logl (FALSE)
# define Rte_InitValue_HwTq4RawFastAdcAdcFaild_Logl (FALSE)
# define Rte_InitValue_HwTq4RollgCntr_Val (0U)
# define Rte_InitValue_MotCtrlHwTq4RawFastAdc_Val (0.0F)
# define Rte_InitValue_MotCtrlHwTq4RawFastAdcBuf_Val (0.0F)


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_HwTq4Meas_HwTq4FastAdcBuf_Val(P2VAR(float32, AUTOMATIC, RTE_HWTQ4MEAS_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_HwTq4Meas_HwTq4Polarity_Val(P2VAR(sint8, AUTOMATIC, RTE_HWTQ4MEAS_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_HwTq4Meas_HwTq4RawAdc_Val(P2VAR(float32, AUTOMATIC, RTE_HWTQ4MEAS_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_HwTq4Meas_HwTq4RawAdcAdcFaild_Logl(P2VAR(boolean, AUTOMATIC, RTE_HWTQ4MEAS_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_HwTq4Meas_HwTq4RawFastAdcAdcFaild_Logl(P2VAR(boolean, AUTOMATIC, RTE_HWTQ4MEAS_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_HwTq4Meas_MotCtrlHwTq4RawFastAdc_Val(P2VAR(float32, AUTOMATIC, RTE_HWTQ4MEAS_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_HwTq4Meas_HwTq4_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_HwTq4Meas_HwTq4Qlfr_Val(SigQlfr1 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_HwTq4Meas_HwTq4RollgCntr_Val(uint8 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_HwTq4Meas_MotCtrlHwTq4RawFastAdcBuf_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_HwTq4Meas_GetNtcQlfrSts_Oper(NtcNr1 NtcNr_Arg, P2VAR(SigQlfr1, AUTOMATIC, RTE_HWTQ4MEAS_APPL_VAR) NtcQlfr_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_HwTq4Meas_HwTq4Offs_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_HWTQ4MEAS_APPL_VAR) ErrorStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_HwTq4Meas_HwTq4Offs_SetRamBlockStatus(Boolean RamBlockStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_HwTq4Meas_HwTq4Sca_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_HWTQ4MEAS_APPL_VAR) ErrorStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_HwTq4Meas_HwTq4Sca_SetRamBlockStatus(Boolean RamBlockStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_HwTq4Meas_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_HwTq4Meas_HwTq4MeasHwTqRngHiLim_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_HwTq4Meas_HwTq4MeasHwTqRngLoLim_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint16, RTE_CODE) Rte_Prm_HwTq4Meas_HwTq4MeasHwTq4PrtclFltFailStep_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint16, RTE_CODE) Rte_Prm_HwTq4Meas_HwTq4MeasHwTq4PrtclFltPassStep_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(boolean, RTE_CODE) Rte_Prm_HwTq4Meas_HwTq4MeasMovgAvrgFilEna_Logl(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

FUNC_P2CONST(HwTqOffsRec1, RTE_CONST_DEFAULT_RTE_CDATA_GROUP, RTE_CODE) Rte_CData_HwTq4Meas_HwTq4Offs_DefaultValue(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC_P2CONST(AnHwTqScaFacRec1, RTE_CONST_DEFAULT_RTE_CDATA_GROUP, RTE_CODE) Rte_CData_HwTq4Meas_HwTq4Sca_DefaultValue(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_HwTq4FastAdcBuf_Val Rte_Read_HwTq4Meas_HwTq4FastAdcBuf_Val
# define Rte_Read_HwTq4Polarity_Val Rte_Read_HwTq4Meas_HwTq4Polarity_Val
# define Rte_Read_HwTq4RawAdc_Val Rte_Read_HwTq4Meas_HwTq4RawAdc_Val
# define Rte_Read_HwTq4RawAdcAdcFaild_Logl Rte_Read_HwTq4Meas_HwTq4RawAdcAdcFaild_Logl
# define Rte_Read_HwTq4RawFastAdcAdcFaild_Logl Rte_Read_HwTq4Meas_HwTq4RawFastAdcAdcFaild_Logl
# define Rte_Read_MotCtrlHwTq4RawFastAdc_Val Rte_Read_HwTq4Meas_MotCtrlHwTq4RawFastAdc_Val


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_HwTq4_Val Rte_Write_HwTq4Meas_HwTq4_Val
# define Rte_Write_HwTq4Qlfr_Val Rte_Write_HwTq4Meas_HwTq4Qlfr_Val
# define Rte_Write_HwTq4RollgCntr_Val Rte_Write_HwTq4Meas_HwTq4RollgCntr_Val
# define Rte_Write_MotCtrlHwTq4RawFastAdcBuf_Val Rte_Write_HwTq4Meas_MotCtrlHwTq4RawFastAdcBuf_Val


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_GetNtcQlfrSts_Oper Rte_Call_HwTq4Meas_GetNtcQlfrSts_Oper
# define Rte_Call_HwTq4Offs_GetErrorStatus Rte_Call_HwTq4Meas_HwTq4Offs_GetErrorStatus
# define Rte_Call_HwTq4Offs_SetRamBlockStatus Rte_Call_HwTq4Meas_HwTq4Offs_SetRamBlockStatus
# define Rte_Call_HwTq4Sca_GetErrorStatus Rte_Call_HwTq4Meas_HwTq4Sca_GetErrorStatus
# define Rte_Call_HwTq4Sca_SetRamBlockStatus Rte_Call_HwTq4Meas_HwTq4Sca_SetRamBlockStatus
# define Rte_Call_SetNtcSts_Oper Rte_Call_HwTq4Meas_SetNtcSts_Oper


/**********************************************************************************************************************
 * Rte_CData (SW-C local calibration parameters)
 *********************************************************************************************************************/

# define Rte_CData_HwTq4Offs_DefaultValue Rte_CData_HwTq4Meas_HwTq4Offs_DefaultValue

# define Rte_CData_HwTq4Sca_DefaultValue Rte_CData_HwTq4Meas_HwTq4Sca_DefaultValue

/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

# define Rte_Prm_HwTq4MeasHwTqRngHiLim_Val Rte_Prm_HwTq4Meas_HwTq4MeasHwTqRngHiLim_Val

# define Rte_Prm_HwTq4MeasHwTqRngLoLim_Val Rte_Prm_HwTq4Meas_HwTq4MeasHwTqRngLoLim_Val

# define Rte_Prm_HwTq4MeasHwTq4PrtclFltFailStep_Val Rte_Prm_HwTq4Meas_HwTq4MeasHwTq4PrtclFltFailStep_Val

# define Rte_Prm_HwTq4MeasHwTq4PrtclFltPassStep_Val Rte_Prm_HwTq4Meas_HwTq4MeasHwTq4PrtclFltPassStep_Val

# define Rte_Prm_HwTq4MeasMovgAvrgFilEna_Logl Rte_Prm_HwTq4Meas_HwTq4MeasMovgAvrgFilEna_Logl

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_HwTq4PrevHwTq4() (Rte_Inst_HwTq4Meas->Pim_HwTq4PrevHwTq4) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_HwTq4RawFastAdcBuf() (Rte_Inst_HwTq4Meas->Pim_HwTq4RawFastAdcBuf) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_HwTq4PrevRollgCntr() (Rte_Inst_HwTq4Meas->Pim_HwTq4PrevRollgCntr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_HwTq4RawFastAdcIdxCntr() (Rte_Inst_HwTq4Meas->Pim_HwTq4RawFastAdcIdxCntr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_HwTq4Offs_MirrorBlock() (Rte_Inst_HwTq4Meas->Pim_HwTq4Offs_MirrorBlock) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_HwTq4Sca_MirrorBlock() (Rte_Inst_HwTq4Meas->Pim_HwTq4Sca_MirrorBlock) /* PRQA S 3453 */ /* MD_MSR_19.7 */




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   float32 *Rte_Pim_HwTq4PrevHwTq4(void)
 *   float32 *Rte_Pim_HwTq4RawFastAdcBuf(void)
 *   uint8 *Rte_Pim_HwTq4PrevRollgCntr(void)
 *   uint8 *Rte_Pim_HwTq4RawFastAdcIdxCntr(void)
 *   HwTqOffsRec1 *Rte_Pim_HwTq4Offs_MirrorBlock(void)
 *   AnHwTqScaFacRec1 *Rte_Pim_HwTq4Sca_MirrorBlock(void)
 *
 * Calibration Parameters:
 * =======================
 *   SW-C local Calibration Parameters:
 *   ----------------------------------
 *   HwTqOffsRec1 *Rte_CData_HwTq4Offs_DefaultValue(void)
 *   AnHwTqScaFacRec1 *Rte_CData_HwTq4Sca_DefaultValue(void)
 *
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_HwTq4MeasHwTqRngHiLim_Val(void)
 *   float32 Rte_Prm_HwTq4MeasHwTqRngLoLim_Val(void)
 *   uint16 Rte_Prm_HwTq4MeasHwTq4PrtclFltFailStep_Val(void)
 *   uint16 Rte_Prm_HwTq4MeasHwTq4PrtclFltPassStep_Val(void)
 *   boolean Rte_Prm_HwTq4MeasMovgAvrgFilEna_Logl(void)
 *
 *********************************************************************************************************************/


# define HwTq4Meas_START_SEC_CODE
# include "HwTq4Meas_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


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
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void HwTq4AutTrim_Oper(void)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_HwTq4AutTrim_Oper HwTq4AutTrim_Oper
FUNC(void, HwTq4Meas_CODE) HwTq4AutTrim_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

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
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void HwTq4ClrSnsrSca_Oper(void)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_HwTq4ClrSnsrSca_Oper HwTq4ClrSnsrSca_Oper
FUNC(void, HwTq4Meas_CODE) HwTq4ClrSnsrSca_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

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
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void HwTq4ClrTrim_Oper(void)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_HwTq4ClrTrim_Oper HwTq4ClrTrim_Oper
FUNC(void, HwTq4Meas_CODE) HwTq4ClrTrim_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

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
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_HwTq4Sca_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_HwTq4MeasInit1 HwTq4MeasInit1
FUNC(void, HwTq4Meas_CODE) HwTq4MeasInit1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTq4MeasPer1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 62us
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_MotCtrlHwTq4RawFastAdc_Val(float32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_MotCtrlHwTq4RawFastAdcBuf_Val(float32 data)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_HwTq4MeasPer1 HwTq4MeasPer1
FUNC(void, HwTq4Meas_CODE) HwTq4MeasPer1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

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
 *   Std_ReturnType Rte_Read_HwTq4FastAdcBuf_Val(float32 *data)
 *   Std_ReturnType Rte_Read_HwTq4Polarity_Val(sint8 *data)
 *   Std_ReturnType Rte_Read_HwTq4RawAdc_Val(float32 *data)
 *   Std_ReturnType Rte_Read_HwTq4RawAdcAdcFaild_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_HwTq4RawFastAdcAdcFaild_Logl(boolean *data)
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
FUNC(void, HwTq4Meas_CODE) HwTq4MeasPer2(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

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
FUNC(void, HwTq4Meas_CODE) HwTq4MeasPer3(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

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
FUNC(void, HwTq4Meas_CODE) HwTq4MeasPer4(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

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
 *   void HwTq4ReadSnsrSca_Oper(float32 *HwTq4ReadScaData, boolean *HwTq4ScaPrfmdStsData)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_HwTq4ReadSnsrSca_Oper HwTq4ReadSnsrSca_Oper
FUNC(void, HwTq4Meas_CODE) HwTq4ReadSnsrSca_Oper(P2VAR(float32, AUTOMATIC, RTE_HWTQ4MEAS_APPL_VAR) HwTq4ReadScaData, P2VAR(boolean, AUTOMATIC, RTE_HWTQ4MEAS_APPL_VAR) HwTq4ScaPrfmdStsData); /* PRQA S 0850 */ /* MD_MSR_19.8 */

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
 *   void HwTq4ReadTrim_Oper(float32 *HwTq4ReadTrimData, boolean *HwTq4OffsTrimPrfmdStsData)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_HwTq4ReadTrim_Oper HwTq4ReadTrim_Oper
FUNC(void, HwTq4Meas_CODE) HwTq4ReadTrim_Oper(P2VAR(float32, AUTOMATIC, RTE_HWTQ4MEAS_APPL_VAR) HwTq4ReadTrimData, P2VAR(boolean, AUTOMATIC, RTE_HWTQ4MEAS_APPL_VAR) HwTq4OffsTrimPrfmdStsData); /* PRQA S 0850 */ /* MD_MSR_19.8 */

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
 *   void HwTq4TrimPrfmdSts_Oper(boolean *HwTqOffsTrimPrfmdStsData)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_HwTq4TrimPrfmdSts_Oper HwTq4TrimPrfmdSts_Oper
FUNC(void, HwTq4Meas_CODE) HwTq4TrimPrfmdSts_Oper(P2VAR(boolean, AUTOMATIC, RTE_HWTQ4MEAS_APPL_VAR) HwTqOffsTrimPrfmdStsData); /* PRQA S 0850 */ /* MD_MSR_19.8 */

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
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void HwTq4WrSnsrSca_Oper(float32 HwTqScaVal)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_HwTq4WrSnsrSca_Oper HwTq4WrSnsrSca_Oper
FUNC(void, HwTq4Meas_CODE) HwTq4WrSnsrSca_Oper(float32 HwTqScaVal); /* PRQA S 0850 */ /* MD_MSR_19.8 */

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
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void HwTq4WrTrim_Oper(float32 HwTq4WrOffsTrimData)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_HwTq4WrTrim_Oper HwTq4WrTrim_Oper
FUNC(void, HwTq4Meas_CODE) HwTq4WrTrim_Oper(float32 HwTq4WrOffsTrimData); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define HwTq4Meas_STOP_SEC_CODE
# include "HwTq4Meas_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_GetNtcQlfrSts_PortIf1_E_NOT_OK (1U)

# define RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK (1U)

# define RTE_E_SetNtcSts_PortIf1_E_NOT_OK (1U)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1465198036
#    error "The magic number of the generated file <C:/Component/ES220A_HwTq4Meas_Impl/tools/contract/Rte_HwTq4Meas.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1465198036
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_HWTQ4MEAS_H */

#include "Rte_Stubs.h"
