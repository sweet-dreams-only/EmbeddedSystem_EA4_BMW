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
 *          File:  Rte_BmwTunSetHndlr.h
 *        Config:  C:/Users/nz2999/Documents/Synergy/ccm_wa/ses_dev_ea4/CF081A_BmwTunSetHndlr_Impl-nz2999/CF081A_BmwTunSetHndlr_Impl/tools/Component.dpa
 *     SW-C Type:  BmwTunSetHndlr
 *  Generated at:  Thu May 17 16:39:22 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <BmwTunSetHndlr> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_BMWTUNSETHNDLR_H
# define _RTE_BMWTUNSETHNDLR_H

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

# include "Rte_BmwTunSetHndlr_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_BmwTunSetHndlr
{
  /* PIM Handles section */
  P2VAR(BmwDesIninIdxRec1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwDesIninIdx; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(BmwDesIninOptSetAIdxRec1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwDesIninOptSetAIdx; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwRtIdxTi; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(BmwRtIdx1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_DebBmwRtIdx; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_LstVldIdx; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(BmwRtIdx1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_PrevBmwRtIdx; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_BmwTunSetHndlr, RTE_CONST, RTE_CONST) Rte_Inst_BmwTunSetHndlr; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_BmwTunSetHndlr, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_BmwRtIdx_Val (15U)
# define Rte_InitValue_BmwRtIdxVld_Logl (FALSE)
# define Rte_InitValue_DesIninIdx_Val (0U)
# define Rte_InitValue_DesIninOptSetAIdx_Val (0U)
# define Rte_InitValue_DesRtIdx_Val (0U)
# define Rte_InitValue_TunSetHndlrEna_Logl (TRUE)


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwTunSetHndlr_BmwRtIdx_Val(P2VAR(BmwRtIdx1, AUTOMATIC, RTE_BMWTUNSETHNDLR_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwTunSetHndlr_BmwRtIdxVld_Logl(P2VAR(boolean, AUTOMATIC, RTE_BMWTUNSETHNDLR_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwTunSetHndlr_TunSetHndlrEna_Logl(P2VAR(boolean, AUTOMATIC, RTE_BMWTUNSETHNDLR_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwTunSetHndlr_DesIninIdx_Val(uint8 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwTunSetHndlr_DesIninOptSetAIdx_Val(uint8 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwTunSetHndlr_DesRtIdx_Val(uint8 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwTunSetHndlr_BmwDesIninIdx_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_BMWTUNSETHNDLR_APPL_VAR) ErrorStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwTunSetHndlr_BmwDesIninIdx_SetRamBlockStatus(Boolean RamBlockStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwTunSetHndlr_BmwDesIninOptSetAIdx_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_BMWTUNSETHNDLR_APPL_VAR) ErrorStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwTunSetHndlr_BmwDesIninOptSetAIdx_SetRamBlockStatus(Boolean RamBlockStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwTunSetHndlr_GetRefTmr100MicroSec32bit_Oper(P2VAR(uint32, AUTOMATIC, RTE_BMWTUNSETHNDLR_APPL_VAR) RefTmr_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwTunSetHndlr_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, P2VAR(uint32, AUTOMATIC, RTE_BMWTUNSETHNDLR_APPL_VAR) TiSpan_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwTunSetHndlr_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint16, RTE_CODE) Rte_Prm_BmwTunSetHndlr_BmwTunSetHndlrBmwRtIdxDebThd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint8, RTE_CODE) Rte_Prm_BmwTunSetHndlr_BmwTunSetHndlrCptDisadOutp_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint8, RTE_CODE) Rte_Prm_BmwTunSetHndlr_BmwTunSetHndlrNrOfMotVrnt_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint8, RTE_CODE) Rte_Prm_BmwTunSetHndlr_BmwTunSetHndlrNrOfTunSet_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint8, RTE_CODE) Rte_Prm_BmwTunSetHndlr_BmwTunSetHndlrOvrdDesRtIdx_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

FUNC_P2CONST(BmwDesIninIdxRec1, RTE_CONST_DEFAULT_RTE_CDATA_GROUP, RTE_CODE) Rte_CData_BmwTunSetHndlr_BmwDesIninIdxDft(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC_P2CONST(BmwDesIninOptSetAIdxRec1, RTE_CONST_DEFAULT_RTE_CDATA_GROUP, RTE_CODE) Rte_CData_BmwTunSetHndlr_BmwDesIninOptSetAIdxDft(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_BmwRtIdx_Val Rte_Read_BmwTunSetHndlr_BmwRtIdx_Val
# define Rte_Read_BmwRtIdxVld_Logl Rte_Read_BmwTunSetHndlr_BmwRtIdxVld_Logl
# define Rte_Read_TunSetHndlrEna_Logl Rte_Read_BmwTunSetHndlr_TunSetHndlrEna_Logl


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_DesIninIdx_Val Rte_Write_BmwTunSetHndlr_DesIninIdx_Val
# define Rte_Write_DesIninOptSetAIdx_Val Rte_Write_BmwTunSetHndlr_DesIninOptSetAIdx_Val
# define Rte_Write_DesRtIdx_Val Rte_Write_BmwTunSetHndlr_DesRtIdx_Val


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_BmwDesIninIdx_GetErrorStatus Rte_Call_BmwTunSetHndlr_BmwDesIninIdx_GetErrorStatus
# define Rte_Call_BmwDesIninIdx_SetRamBlockStatus Rte_Call_BmwTunSetHndlr_BmwDesIninIdx_SetRamBlockStatus
# define Rte_Call_BmwDesIninOptSetAIdx_GetErrorStatus Rte_Call_BmwTunSetHndlr_BmwDesIninOptSetAIdx_GetErrorStatus
# define Rte_Call_BmwDesIninOptSetAIdx_SetRamBlockStatus Rte_Call_BmwTunSetHndlr_BmwDesIninOptSetAIdx_SetRamBlockStatus
# define Rte_Call_GetRefTmr100MicroSec32bit_Oper Rte_Call_BmwTunSetHndlr_GetRefTmr100MicroSec32bit_Oper
# define Rte_Call_GetTiSpan100MicroSec32bit_Oper Rte_Call_BmwTunSetHndlr_GetTiSpan100MicroSec32bit_Oper
# define Rte_Call_SetNtcSts_Oper Rte_Call_BmwTunSetHndlr_SetNtcSts_Oper


/**********************************************************************************************************************
 * Rte_CData (SW-C local calibration parameters)
 *********************************************************************************************************************/

# define Rte_CData_BmwDesIninIdxDft Rte_CData_BmwTunSetHndlr_BmwDesIninIdxDft

# define Rte_CData_BmwDesIninOptSetAIdxDft Rte_CData_BmwTunSetHndlr_BmwDesIninOptSetAIdxDft

/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

# define Rte_Prm_BmwTunSetHndlrBmwRtIdxDebThd_Val Rte_Prm_BmwTunSetHndlr_BmwTunSetHndlrBmwRtIdxDebThd_Val

# define Rte_Prm_BmwTunSetHndlrCptDisadOutp_Val Rte_Prm_BmwTunSetHndlr_BmwTunSetHndlrCptDisadOutp_Val

# define Rte_Prm_BmwTunSetHndlrNrOfMotVrnt_Val Rte_Prm_BmwTunSetHndlr_BmwTunSetHndlrNrOfMotVrnt_Val

# define Rte_Prm_BmwTunSetHndlrNrOfTunSet_Val Rte_Prm_BmwTunSetHndlr_BmwTunSetHndlrNrOfTunSet_Val

# define Rte_Prm_BmwTunSetHndlrOvrdDesRtIdx_Val Rte_Prm_BmwTunSetHndlr_BmwTunSetHndlrOvrdDesRtIdx_Val

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_BmwRtIdxTi() (Rte_Inst_BmwTunSetHndlr->Pim_BmwRtIdxTi) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_DebBmwRtIdx() (Rte_Inst_BmwTunSetHndlr->Pim_DebBmwRtIdx) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_LstVldIdx() (Rte_Inst_BmwTunSetHndlr->Pim_LstVldIdx) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_PrevBmwRtIdx() (Rte_Inst_BmwTunSetHndlr->Pim_PrevBmwRtIdx) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_BmwDesIninIdx() (Rte_Inst_BmwTunSetHndlr->Pim_BmwDesIninIdx) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_BmwDesIninOptSetAIdx() (Rte_Inst_BmwTunSetHndlr->Pim_BmwDesIninOptSetAIdx) /* PRQA S 3453 */ /* MD_MSR_19.7 */




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   uint32 *Rte_Pim_BmwRtIdxTi(void)
 *   BmwRtIdx1 *Rte_Pim_DebBmwRtIdx(void)
 *   uint8 *Rte_Pim_LstVldIdx(void)
 *   BmwRtIdx1 *Rte_Pim_PrevBmwRtIdx(void)
 *   BmwDesIninIdxRec1 *Rte_Pim_BmwDesIninIdx(void)
 *   BmwDesIninOptSetAIdxRec1 *Rte_Pim_BmwDesIninOptSetAIdx(void)
 *
 * Calibration Parameters:
 * =======================
 *   SW-C local Calibration Parameters:
 *   ----------------------------------
 *   BmwDesIninIdxRec1 *Rte_CData_BmwDesIninIdxDft(void)
 *   BmwDesIninOptSetAIdxRec1 *Rte_CData_BmwDesIninOptSetAIdxDft(void)
 *
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   uint16 Rte_Prm_BmwTunSetHndlrBmwRtIdxDebThd_Val(void)
 *   uint8 Rte_Prm_BmwTunSetHndlrCptDisadOutp_Val(void)
 *   uint8 Rte_Prm_BmwTunSetHndlrNrOfMotVrnt_Val(void)
 *   uint8 Rte_Prm_BmwTunSetHndlrNrOfTunSet_Val(void)
 *   uint8 Rte_Prm_BmwTunSetHndlrOvrdDesRtIdx_Val(void)
 *
 *********************************************************************************************************************/


# define BmwTunSetHndlr_START_SEC_CODE
# include "BmwTunSetHndlr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwTunSetHndlrInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_DesIninIdx_Val(uint8 data)
 *   Std_ReturnType Rte_Write_DesIninOptSetAIdx_Val(uint8 data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetNtcSts_PortIf1_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_BmwDesIninIdx_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_BmwDesIninIdx_SetRamBlockStatus(Boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_BmwDesIninOptSetAIdx_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_BmwDesIninOptSetAIdx_SetRamBlockStatus(Boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_BmwTunSetHndlrInit1 BmwTunSetHndlrInit1
FUNC(void, BmwTunSetHndlr_CODE) BmwTunSetHndlrInit1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwTunSetHndlrPer1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_BmwRtIdx_Val(BmwRtIdx1 *data)
 *   Std_ReturnType Rte_Read_BmwRtIdxVld_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_TunSetHndlrEna_Logl(boolean *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_DesRtIdx_Val(uint8 data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_GetRefTmr100MicroSec32bit_Oper(uint32 *RefTmr_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_BmwTunSetHndlrPer1 BmwTunSetHndlrPer1
FUNC(void, BmwTunSetHndlr_CODE) BmwTunSetHndlrPer1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MotVrntRead_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <MotVrntRead>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MotVrntRead_Oper(uint8 *BmwDesIninOptSetAIdx_Arg)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_MotVrntRead_PortIf1_E_NOT_OK
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_MotVrntRead_Oper MotVrntRead_Oper
FUNC(Std_ReturnType, BmwTunSetHndlr_CODE) MotVrntRead_Oper(P2VAR(uint8, AUTOMATIC, RTE_BMWTUNSETHNDLR_APPL_VAR) BmwDesIninOptSetAIdx_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MotVrntWr_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <MotVrntWr>
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
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_BmwDesIninOptSetAIdx_SetRamBlockStatus(Boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MotVrntWr_Oper(uint8 BmwDesIninOptSetAIdx_Arg)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_MotVrntWr_PortIf1_E_NOT_OK
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_MotVrntWr_Oper MotVrntWr_Oper
FUNC(Std_ReturnType, BmwTunSetHndlr_CODE) MotVrntWr_Oper(uint8 BmwDesIninOptSetAIdx_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TunVrntRead_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <TunVrntRead>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType TunVrntRead_Oper(uint8 *BmwDesIninIdx_Arg)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_TunVrntRead_PortIf1_E_NOT_OK
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_TunVrntRead_Oper TunVrntRead_Oper
FUNC(Std_ReturnType, BmwTunSetHndlr_CODE) TunVrntRead_Oper(P2VAR(uint8, AUTOMATIC, RTE_BMWTUNSETHNDLR_APPL_VAR) BmwDesIninIdx_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TunVrntWr_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <TunVrntWr>
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
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_BmwDesIninIdx_SetRamBlockStatus(Boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType TunVrntWr_Oper(uint8 BmwDesIninIdx_Arg)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_TunVrntWr_PortIf1_E_NOT_OK
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_TunVrntWr_Oper TunVrntWr_Oper
FUNC(Std_ReturnType, BmwTunSetHndlr_CODE) TunVrntWr_Oper(uint8 BmwDesIninIdx_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define BmwTunSetHndlr_STOP_SEC_CODE
# include "BmwTunSetHndlr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_MotVrntRead_PortIf1_E_NOT_OK (1U)

# define RTE_E_MotVrntWr_PortIf1_E_NOT_OK (1U)

# define RTE_E_NvMService_AC3_SRBS_E_NOT_OK (1U)

# define RTE_E_SetNtcSts_PortIf1_E_NOT_OK (1U)

# define RTE_E_TunVrntRead_PortIf1_E_NOT_OK (1U)

# define RTE_E_TunVrntWr_PortIf1_E_NOT_OK (1U)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_BMWTUNSETHNDLR_H */

#include "Rte_Stubs.h"
