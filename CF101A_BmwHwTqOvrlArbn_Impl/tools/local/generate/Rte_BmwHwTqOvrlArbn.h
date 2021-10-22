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
 *          File:  Rte_BmwHwTqOvrlArbn.h
 *        Config:  C:/Users/nz2999/Documents/Synergy/ccm_wa/ses_dev_ea4/CF101A_BmwHwTqOvrlArbn_Impl-nz2999/CF101A_BmwHwTqOvrlArbn_Impl/tools/Component.dpa
 *     SW-C Type:  BmwHwTqOvrlArbn
 *  Generated at:  Tue Apr 17 10:49:08 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <BmwHwTqOvrlArbn> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_BMWHWTQOVRLARBN_H
# define _RTE_BMWHWTQOVRLARBN_H

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

# include "Rte_BmwHwTqOvrlArbn_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_BmwHwTqOvrlArbn
{
  /* PIM Handles section */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_ArbdHwTqOvrlLtch; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_FctlErrActv; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_FctlErrTmr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_HwTqOvrlScaFacStVari; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_PrevArbdHwTqOvrl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_PrevFctlErr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_BmwHwTqOvrlArbn, RTE_CONST, RTE_CONST) Rte_Inst_BmwHwTqOvrlArbn; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_BmwHwTqOvrlArbn, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_BmwDrvgDynErrIfActv_Logl (FALSE)
# define Rte_InitValue_BmwTarHwTqOvrl_Val (0.0F)
# define Rte_InitValue_BmwTarHwTqOvrlQlfr_Val (7U)
# define Rte_InitValue_DrvgDynIfSt_Val (128U)
# define Rte_InitValue_HwTqCmdOvrl_Val (0.0F)
# define Rte_InitValue_HwTqOvrlCmdEna_Logl (TRUE)
# define Rte_InitValue_VehSpd_Val (0.0F)


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwHwTqOvrlArbn_BmwDrvgDynErrIfActv_Logl(P2VAR(boolean, AUTOMATIC, RTE_BMWHWTQOVRLARBN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwHwTqOvrlArbn_BmwTarHwTqOvrl_Val(P2VAR(float32, AUTOMATIC, RTE_BMWHWTQOVRLARBN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwHwTqOvrlArbn_BmwTarHwTqOvrlQlfr_Val(P2VAR(BmwOvrlCmdQlfr1, AUTOMATIC, RTE_BMWHWTQOVRLARBN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwHwTqOvrlArbn_DrvgDynIfSt_Val(P2VAR(DrvgDynIfSt1, AUTOMATIC, RTE_BMWHWTQOVRLARBN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwHwTqOvrlArbn_HwTqOvrlCmdEna_Logl(P2VAR(boolean, AUTOMATIC, RTE_BMWHWTQOVRLARBN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwHwTqOvrlArbn_VehSpd_Val(P2VAR(float32, AUTOMATIC, RTE_BMWHWTQOVRLARBN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwHwTqOvrlArbn_HwTqCmdOvrl_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwHwTqOvrlArbn_GetRefTmr100MicroSec32bit_Oper(P2VAR(uint32, AUTOMATIC, RTE_BMWHWTQOVRLARBN_APPL_VAR) RefTmr_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwHwTqOvrlArbn_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, P2VAR(uint32, AUTOMATIC, RTE_BMWHWTQOVRLARBN_APPL_VAR) TiSpan_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_BmwHwTqOvrlArbn_BmwHwTqOvrlArbnCmdErrThd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_BmwHwTqOvrlArbn_BmwHwTqOvrlArbnOutpTqCmdLim_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_BmwHwTqOvrlArbn_BmwHwTqOvrlArbnRampRate_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint16, RTE_CODE) Rte_Prm_BmwHwTqOvrlArbn_BmwHwTqOvrlArbnRefTiThd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u4p12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwHwTqOvrlArbn_BmwHwTqOvrlArbnHwTqThdY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u4p12_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwHwTqOvrlArbn_BmwHwTqOvrlArbnHwTqThdY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u9p7, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwHwTqOvrlArbn_BmwHwTqOvrlArbnVehSpdX_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u9p7_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwHwTqOvrlArbn_BmwHwTqOvrlArbnVehSpdX_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_BmwDrvgDynErrIfActv_Logl Rte_Read_BmwHwTqOvrlArbn_BmwDrvgDynErrIfActv_Logl
# define Rte_Read_BmwTarHwTqOvrl_Val Rte_Read_BmwHwTqOvrlArbn_BmwTarHwTqOvrl_Val
# define Rte_Read_BmwTarHwTqOvrlQlfr_Val Rte_Read_BmwHwTqOvrlArbn_BmwTarHwTqOvrlQlfr_Val
# define Rte_Read_DrvgDynIfSt_Val Rte_Read_BmwHwTqOvrlArbn_DrvgDynIfSt_Val
# define Rte_Read_HwTqOvrlCmdEna_Logl Rte_Read_BmwHwTqOvrlArbn_HwTqOvrlCmdEna_Logl
# define Rte_Read_VehSpd_Val Rte_Read_BmwHwTqOvrlArbn_VehSpd_Val


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_HwTqCmdOvrl_Val Rte_Write_BmwHwTqOvrlArbn_HwTqCmdOvrl_Val


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_GetRefTmr100MicroSec32bit_Oper Rte_Call_BmwHwTqOvrlArbn_GetRefTmr100MicroSec32bit_Oper
# define Rte_Call_GetTiSpan100MicroSec32bit_Oper Rte_Call_BmwHwTqOvrlArbn_GetTiSpan100MicroSec32bit_Oper


/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

# define Rte_Prm_BmwHwTqOvrlArbnCmdErrThd_Val Rte_Prm_BmwHwTqOvrlArbn_BmwHwTqOvrlArbnCmdErrThd_Val

# define Rte_Prm_BmwHwTqOvrlArbnOutpTqCmdLim_Val Rte_Prm_BmwHwTqOvrlArbn_BmwHwTqOvrlArbnOutpTqCmdLim_Val

# define Rte_Prm_BmwHwTqOvrlArbnRampRate_Val Rte_Prm_BmwHwTqOvrlArbn_BmwHwTqOvrlArbnRampRate_Val

# define Rte_Prm_BmwHwTqOvrlArbnRefTiThd_Val Rte_Prm_BmwHwTqOvrlArbn_BmwHwTqOvrlArbnRefTiThd_Val

# define Rte_Prm_BmwHwTqOvrlArbnHwTqThdY_Ary1D Rte_Prm_BmwHwTqOvrlArbn_BmwHwTqOvrlArbnHwTqThdY_Ary1D

# define Rte_Prm_BmwHwTqOvrlArbnVehSpdX_Ary1D Rte_Prm_BmwHwTqOvrlArbn_BmwHwTqOvrlArbnVehSpdX_Ary1D

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_ArbdHwTqOvrlLtch() (Rte_Inst_BmwHwTqOvrlArbn->Pim_ArbdHwTqOvrlLtch) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_HwTqOvrlScaFacStVari() (Rte_Inst_BmwHwTqOvrlArbn->Pim_HwTqOvrlScaFacStVari) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_PrevArbdHwTqOvrl() (Rte_Inst_BmwHwTqOvrlArbn->Pim_PrevArbdHwTqOvrl) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_FctlErrTmr() (Rte_Inst_BmwHwTqOvrlArbn->Pim_FctlErrTmr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_FctlErrActv() (Rte_Inst_BmwHwTqOvrlArbn->Pim_FctlErrActv) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_PrevFctlErr() (Rte_Inst_BmwHwTqOvrlArbn->Pim_PrevFctlErr) /* PRQA S 3453 */ /* MD_MSR_19.7 */




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   float32 *Rte_Pim_ArbdHwTqOvrlLtch(void)
 *   float32 *Rte_Pim_HwTqOvrlScaFacStVari(void)
 *   float32 *Rte_Pim_PrevArbdHwTqOvrl(void)
 *   uint32 *Rte_Pim_FctlErrTmr(void)
 *   boolean *Rte_Pim_FctlErrActv(void)
 *   boolean *Rte_Pim_PrevFctlErr(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_BmwHwTqOvrlArbnCmdErrThd_Val(void)
 *   float32 Rte_Prm_BmwHwTqOvrlArbnOutpTqCmdLim_Val(void)
 *   float32 Rte_Prm_BmwHwTqOvrlArbnRampRate_Val(void)
 *   uint16 Rte_Prm_BmwHwTqOvrlArbnRefTiThd_Val(void)
 *   u4p12 *Rte_Prm_BmwHwTqOvrlArbnHwTqThdY_Ary1D(void)
 *     Returnvalue: u4p12* is of type Ary1D_u4p12_6
 *   u9p7 *Rte_Prm_BmwHwTqOvrlArbnVehSpdX_Ary1D(void)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_6
 *
 *********************************************************************************************************************/


# define BmwHwTqOvrlArbn_START_SEC_CODE
# include "BmwHwTqOvrlArbn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwHwTqOvrlArbnInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_BmwHwTqOvrlArbnInit1 BmwHwTqOvrlArbnInit1
FUNC(void, BmwHwTqOvrlArbn_CODE) BmwHwTqOvrlArbnInit1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwHwTqOvrlArbnPer1
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
 *   Std_ReturnType Rte_Read_BmwDrvgDynErrIfActv_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_BmwTarHwTqOvrl_Val(float32 *data)
 *   Std_ReturnType Rte_Read_BmwTarHwTqOvrlQlfr_Val(BmwOvrlCmdQlfr1 *data)
 *   Std_ReturnType Rte_Read_DrvgDynIfSt_Val(DrvgDynIfSt1 *data)
 *   Std_ReturnType Rte_Read_HwTqOvrlCmdEna_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_VehSpd_Val(float32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_HwTqCmdOvrl_Val(float32 data)
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

# define RTE_RUNNABLE_BmwHwTqOvrlArbnPer1 BmwHwTqOvrlArbnPer1
FUNC(void, BmwHwTqOvrlArbn_CODE) BmwHwTqOvrlArbnPer1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define BmwHwTqOvrlArbn_STOP_SEC_CODE
# include "BmwHwTqOvrlArbn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_BMWHWTQOVRLARBN_H */

#include "Rte_Stubs.h"
