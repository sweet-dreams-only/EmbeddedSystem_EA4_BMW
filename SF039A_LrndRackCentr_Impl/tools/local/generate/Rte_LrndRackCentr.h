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
 *          File:  Rte_LrndRackCentr.h
 *        Config:  C:/_Synergy_Projects/Working/SF039A_LrndRackCentr_Impl/tools/Component.dpa
 *     SW-C Type:  LrndRackCentr
 *  Generated at:  Tue Nov  7 18:31:38 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <LrndRackCentr> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_LRNDRACKCENTR_H
# define _RTE_LRNDRACKCENTR_H

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

# include "Rte_LrndRackCentr_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_LrndRackCentr
{
  /* PIM Handles section */
  P2VAR(FilLpRec1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_HwAgFil; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(LrndRackCentrNvmRec1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_LrndRackCentr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_ManLrndRackCentrNegEot; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_ManLrndRackCentrNegEotVld; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_ManLrndRackCentrPosEot; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_ManLrndRackCentrPosEotVld; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_RackCentrMaxTmr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_RackCentrMinTmr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_RackCentrPinionAgPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_LrndRackCentr, RTE_CONST, RTE_CONST) Rte_Inst_LrndRackCentr; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_LrndRackCentr, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_HwAg_Val (0.0F)
# define Rte_InitValue_LongTermRackCentrCmpl_Logl (FALSE)
# define Rte_InitValue_MotTqCmd_Val (0.0F)
# define Rte_InitValue_MotVelCrf_Val (0.0F)
# define Rte_InitValue_PinionCentrLrnEna_Logl (FALSE)
# define Rte_InitValue_PinionCentrLrnHwCentr_Val (0.0F)
# define Rte_InitValue_PinionCentrLrnHwTrvl_Val (0.0F)
# define Rte_InitValue_PinionCentrLrnSt_Val (0U)
# define Rte_InitValue_RackCentrCmpl_Logl (FALSE)
# define Rte_InitValue_RackCentrMotAgErrPrsnt_Logl (FALSE)
# define Rte_InitValue_RackCentrMotAgVld_Logl (FALSE)
# define Rte_InitValue_RackCentrPinionAg_Val (0.0F)
# define Rte_InitValue_TotRackTrvl_Val (0.0F)


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_LrndRackCentr_HwAg_Val(P2VAR(float32, AUTOMATIC, RTE_LRNDRACKCENTR_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_LrndRackCentr_MotTqCmd_Val(P2VAR(float32, AUTOMATIC, RTE_LRNDRACKCENTR_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_LrndRackCentr_MotVelCrf_Val(P2VAR(float32, AUTOMATIC, RTE_LRNDRACKCENTR_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_LrndRackCentr_PinionCentrLrnEna_Logl(P2VAR(boolean, AUTOMATIC, RTE_LRNDRACKCENTR_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_LrndRackCentr_PinionCentrLrnHwCentr_Val(P2VAR(float32, AUTOMATIC, RTE_LRNDRACKCENTR_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_LrndRackCentr_PinionCentrLrnHwTrvl_Val(P2VAR(float32, AUTOMATIC, RTE_LRNDRACKCENTR_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_LrndRackCentr_PinionCentrLrnSt_Val(P2VAR(uint8, AUTOMATIC, RTE_LRNDRACKCENTR_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_LrndRackCentr_LongTermRackCentrCmpl_Logl(boolean data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_LrndRackCentr_RackCentrCmpl_Logl(boolean data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_LrndRackCentr_RackCentrMotAgErrPrsnt_Logl(boolean data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_LrndRackCentr_RackCentrMotAgVld_Logl(boolean data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_LrndRackCentr_RackCentrPinionAg_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_LrndRackCentr_TotRackTrvl_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_LrndRackCentr_GetRefTmr100MicroSec32bit_Oper(P2VAR(uint32, AUTOMATIC, RTE_LRNDRACKCENTR_APPL_VAR) RefTmr_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_LrndRackCentr_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, P2VAR(uint32, AUTOMATIC, RTE_LRNDRACKCENTR_APPL_VAR) TiSpan_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_LrndRackCentr_LrndRackCentrNvm_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_LRNDRACKCENTR_APPL_VAR) ErrorStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_LrndRackCentr_LrndRackCentrNvm_SetRamBlockStatus(Boolean RamBlockStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_LrndRackCentr_LrndRackCentrConfTrvlThd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_LrndRackCentr_LrndRackCentrHwAgFilFrq_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_LrndRackCentr_LrndRackCentrMinMaxAdjmtFac_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_LrndRackCentr_LrndRackCentrMotTqThd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_LrndRackCentr_LrndRackCentrMotVelThd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_LrndRackCentr_LrndRackCentrRackCentrPosnChgAllwd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_LrndRackCentr_SysGlbPrmSysKineRat_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint16, RTE_CODE) Rte_Prm_LrndRackCentr_LrndRackCentrTiThd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(boolean, RTE_CODE) Rte_Prm_LrndRackCentr_LrndRackCentrAllwManIniLrng_Logl(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_HwAg_Val Rte_Read_LrndRackCentr_HwAg_Val
# define Rte_Read_MotTqCmd_Val Rte_Read_LrndRackCentr_MotTqCmd_Val
# define Rte_Read_MotVelCrf_Val Rte_Read_LrndRackCentr_MotVelCrf_Val
# define Rte_Read_PinionCentrLrnEna_Logl Rte_Read_LrndRackCentr_PinionCentrLrnEna_Logl
# define Rte_Read_PinionCentrLrnHwCentr_Val Rte_Read_LrndRackCentr_PinionCentrLrnHwCentr_Val
# define Rte_Read_PinionCentrLrnHwTrvl_Val Rte_Read_LrndRackCentr_PinionCentrLrnHwTrvl_Val
# define Rte_Read_PinionCentrLrnSt_Val Rte_Read_LrndRackCentr_PinionCentrLrnSt_Val


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_LongTermRackCentrCmpl_Logl Rte_Write_LrndRackCentr_LongTermRackCentrCmpl_Logl
# define Rte_Write_RackCentrCmpl_Logl Rte_Write_LrndRackCentr_RackCentrCmpl_Logl
# define Rte_Write_RackCentrMotAgErrPrsnt_Logl Rte_Write_LrndRackCentr_RackCentrMotAgErrPrsnt_Logl
# define Rte_Write_RackCentrMotAgVld_Logl Rte_Write_LrndRackCentr_RackCentrMotAgVld_Logl
# define Rte_Write_RackCentrPinionAg_Val Rte_Write_LrndRackCentr_RackCentrPinionAg_Val
# define Rte_Write_TotRackTrvl_Val Rte_Write_LrndRackCentr_TotRackTrvl_Val


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_GetRefTmr100MicroSec32bit_Oper Rte_Call_LrndRackCentr_GetRefTmr100MicroSec32bit_Oper
# define Rte_Call_GetTiSpan100MicroSec32bit_Oper Rte_Call_LrndRackCentr_GetTiSpan100MicroSec32bit_Oper
# define Rte_Call_LrndRackCentrNvm_GetErrorStatus Rte_Call_LrndRackCentr_LrndRackCentrNvm_GetErrorStatus
# define Rte_Call_LrndRackCentrNvm_SetRamBlockStatus Rte_Call_LrndRackCentr_LrndRackCentrNvm_SetRamBlockStatus


/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

# define Rte_Prm_LrndRackCentrConfTrvlThd_Val Rte_Prm_LrndRackCentr_LrndRackCentrConfTrvlThd_Val

# define Rte_Prm_LrndRackCentrHwAgFilFrq_Val Rte_Prm_LrndRackCentr_LrndRackCentrHwAgFilFrq_Val

# define Rte_Prm_LrndRackCentrMinMaxAdjmtFac_Val Rte_Prm_LrndRackCentr_LrndRackCentrMinMaxAdjmtFac_Val

# define Rte_Prm_LrndRackCentrMotTqThd_Val Rte_Prm_LrndRackCentr_LrndRackCentrMotTqThd_Val

# define Rte_Prm_LrndRackCentrMotVelThd_Val Rte_Prm_LrndRackCentr_LrndRackCentrMotVelThd_Val

# define Rte_Prm_LrndRackCentrRackCentrPosnChgAllwd_Val Rte_Prm_LrndRackCentr_LrndRackCentrRackCentrPosnChgAllwd_Val

# define Rte_Prm_SysGlbPrmSysKineRat_Val Rte_Prm_LrndRackCentr_SysGlbPrmSysKineRat_Val

# define Rte_Prm_LrndRackCentrTiThd_Val Rte_Prm_LrndRackCentr_LrndRackCentrTiThd_Val

# define Rte_Prm_LrndRackCentrAllwManIniLrng_Logl Rte_Prm_LrndRackCentr_LrndRackCentrAllwManIniLrng_Logl

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_ManLrndRackCentrNegEot() (Rte_Inst_LrndRackCentr->Pim_ManLrndRackCentrNegEot) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_ManLrndRackCentrPosEot() (Rte_Inst_LrndRackCentr->Pim_ManLrndRackCentrPosEot) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_RackCentrPinionAgPrev() (Rte_Inst_LrndRackCentr->Pim_RackCentrPinionAgPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_RackCentrMaxTmr() (Rte_Inst_LrndRackCentr->Pim_RackCentrMaxTmr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_RackCentrMinTmr() (Rte_Inst_LrndRackCentr->Pim_RackCentrMinTmr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_ManLrndRackCentrNegEotVld() (Rte_Inst_LrndRackCentr->Pim_ManLrndRackCentrNegEotVld) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_ManLrndRackCentrPosEotVld() (Rte_Inst_LrndRackCentr->Pim_ManLrndRackCentrPosEotVld) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_HwAgFil() (Rte_Inst_LrndRackCentr->Pim_HwAgFil) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_LrndRackCentr() (Rte_Inst_LrndRackCentr->Pim_LrndRackCentr) /* PRQA S 3453 */ /* MD_MSR_19.7 */




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   float32 *Rte_Pim_ManLrndRackCentrNegEot(void)
 *   float32 *Rte_Pim_ManLrndRackCentrPosEot(void)
 *   float32 *Rte_Pim_RackCentrPinionAgPrev(void)
 *   uint32 *Rte_Pim_RackCentrMaxTmr(void)
 *   uint32 *Rte_Pim_RackCentrMinTmr(void)
 *   boolean *Rte_Pim_ManLrndRackCentrNegEotVld(void)
 *   boolean *Rte_Pim_ManLrndRackCentrPosEotVld(void)
 *   FilLpRec1 *Rte_Pim_HwAgFil(void)
 *   LrndRackCentrNvmRec1 *Rte_Pim_LrndRackCentr(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_LrndRackCentrConfTrvlThd_Val(void)
 *   float32 Rte_Prm_LrndRackCentrHwAgFilFrq_Val(void)
 *   float32 Rte_Prm_LrndRackCentrMinMaxAdjmtFac_Val(void)
 *   float32 Rte_Prm_LrndRackCentrMotTqThd_Val(void)
 *   float32 Rte_Prm_LrndRackCentrMotVelThd_Val(void)
 *   float32 Rte_Prm_LrndRackCentrRackCentrPosnChgAllwd_Val(void)
 *   float32 Rte_Prm_SysGlbPrmSysKineRat_Val(void)
 *   uint16 Rte_Prm_LrndRackCentrTiThd_Val(void)
 *   boolean Rte_Prm_LrndRackCentrAllwManIniLrng_Logl(void)
 *
 *********************************************************************************************************************/


# define LrndRackCentr_START_SEC_CODE
# include "LrndRackCentr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: LrndRackCentrInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_HwAg_Val(float32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_LongTermRackCentrCmpl_Logl(boolean data)
 *   Std_ReturnType Rte_Write_RackCentrCmpl_Logl(boolean data)
 *   Std_ReturnType Rte_Write_RackCentrMotAgErrPrsnt_Logl(boolean data)
 *   Std_ReturnType Rte_Write_RackCentrMotAgVld_Logl(boolean data)
 *   Std_ReturnType Rte_Write_RackCentrPinionAg_Val(float32 data)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_LrndRackCentrNvm_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_LrndRackCentrInit1 LrndRackCentrInit1
FUNC(void, LrndRackCentr_CODE) LrndRackCentrInit1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: LrndRackCentrPer1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 4ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_HwAg_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotTqCmd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotVelCrf_Val(float32 *data)
 *   Std_ReturnType Rte_Read_PinionCentrLrnEna_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_PinionCentrLrnHwCentr_Val(float32 *data)
 *   Std_ReturnType Rte_Read_PinionCentrLrnHwTrvl_Val(float32 *data)
 *   Std_ReturnType Rte_Read_PinionCentrLrnSt_Val(uint8 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_LongTermRackCentrCmpl_Logl(boolean data)
 *   Std_ReturnType Rte_Write_RackCentrCmpl_Logl(boolean data)
 *   Std_ReturnType Rte_Write_RackCentrMotAgVld_Logl(boolean data)
 *   Std_ReturnType Rte_Write_RackCentrPinionAg_Val(float32 data)
 *   Std_ReturnType Rte_Write_TotRackTrvl_Val(float32 data)
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
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_LrndRackCentrNvm_SetRamBlockStatus(Boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_LrndRackCentrPer1 LrndRackCentrPer1
FUNC(void, LrndRackCentr_CODE) LrndRackCentrPer1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RstRackCentrMotAg_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <RstRackCentrMotAg>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_RackCentrMotAgVld_Logl(boolean data)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_LrndRackCentrNvm_SetRamBlockStatus(Boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void RstRackCentrMotAg_Oper(void)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_RstRackCentrMotAg_Oper RstRackCentrMotAg_Oper
FUNC(void, LrndRackCentr_CODE) RstRackCentrMotAg_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RstRackCentrMotRev_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <RstRackCentrMotRev>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_HwAg_Val(float32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_LongTermRackCentrCmpl_Logl(boolean data)
 *   Std_ReturnType Rte_Write_RackCentrCmpl_Logl(boolean data)
 *   Std_ReturnType Rte_Write_RackCentrPinionAg_Val(float32 data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_GetRefTmr100MicroSec32bit_Oper(uint32 *RefTmr_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_LrndRackCentrNvm_SetRamBlockStatus(Boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void RstRackCentrMotRev_Oper(void)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_RstRackCentrMotRev_Oper RstRackCentrMotRev_Oper
FUNC(void, LrndRackCentr_CODE) RstRackCentrMotRev_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define LrndRackCentr_STOP_SEC_CODE
# include "LrndRackCentr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_NvMService_AC3_SRBS_E_NOT_OK (1U)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_LRNDRACKCENTR_H */

#include "Rte_Stubs.h"
