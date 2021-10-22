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
 *          File:  Rte_LrnPinionCentr.h
 *        Config:  C:/_Synergy_Projects/Working/ses_dev_ea4/SF024A_LrnPinionCentr_Impl/tools/Component.dpa
 *     SW-C Type:  LrnPinionCentr
 *  Generated at:  Fri Jan 12 08:38:00 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <LrnPinionCentr> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_LRNPINIONCENTR_H
# define _RTE_LRNPINIONCENTR_H

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

# include "Rte_LrnPinionCentr_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_LrnPinionCentr
{
  /* PIM Handles section */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MaxHwPosnPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MinHwPosnPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_PinionCentrLrnEnaPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_PinionCentrLrnHwCentrPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_PinionCentrLrnHwTrvlPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_StCtrl1PosnErrRateLim; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(FilLpRec1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_StCtrl1RateLimdPosnErrLpFil; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_StCtrl1TmrARefTi; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_StCtrl1TmrBRefTi; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(FilLpRec1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_StCtrl2RateLimdTqErrLpFil; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_StCtrl2TmrARefTi; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_StCtrl2TmrBRefTi; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_StCtrl2TqErrRateLim; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_StCtrl3PosnErrRateLim; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(FilLpRec1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_StCtrl3RateLimdPosnErrLpFil; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(FilLpRec1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_StCtrl3RateLimdTqErrLpFil; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_StCtrl3TmrARefTi; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_StCtrl3TmrBRefTi; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_StCtrl3TqErrRateLim; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(FilLpRec1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_StCtrl4RateLimdTqErrLpFil; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_StCtrl4TmrARefTi; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_StCtrl4TmrBRefTi; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_StCtrl4TqErrRateLim; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_StCtrl5IntglEnaOutpPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_StCtrl5PosnErrRateLim; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(FilLpRec1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_StCtrl5RateLimdPosnErrLpFil; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(FilLpRec1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_StCtrl5RateLimdTqErrLpFil; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_StCtrl5TmrARefTi; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_StCtrl5TmrBRefTi; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_StCtrl5TqErrRateLim; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_StEstimdPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_TarHwAg; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_TarMotVel; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_TqCmdEstimdPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dLrnPinionCentrHwPosnCmd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_LrnPinionCentr, RTE_CONST, RTE_CONST) Rte_Inst_LrnPinionCentr; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_LrnPinionCentr, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_HwAg_Val (0.0F)
# define Rte_InitValue_MotVelCrf_Val (0.0F)
# define Rte_InitValue_PinionCentrLrnCmd_Val (0.0F)
# define Rte_InitValue_PinionCentrLrnEna_Logl (FALSE)
# define Rte_InitValue_PinionCentrLrnHwCentr_Val (0.0F)
# define Rte_InitValue_PinionCentrLrnHwTrvl_Val (0.0F)
# define Rte_InitValue_PinionCentrLrnSt_Val (0U)


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_LrnPinionCentr_HwAg_Val(P2VAR(float32, AUTOMATIC, RTE_LRNPINIONCENTR_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_LrnPinionCentr_MotVelCrf_Val(P2VAR(float32, AUTOMATIC, RTE_LRNPINIONCENTR_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_LrnPinionCentr_PinionCentrLrnEna_Logl(P2VAR(boolean, AUTOMATIC, RTE_LRNPINIONCENTR_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_LrnPinionCentr_PinionCentrLrnCmd_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_LrnPinionCentr_PinionCentrLrnHwCentr_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_LrnPinionCentr_PinionCentrLrnHwTrvl_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_LrnPinionCentr_PinionCentrLrnSt_Val(uint8 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_LrnPinionCentr_GetRefTmr100MicroSec32bit_Oper(P2VAR(uint32, AUTOMATIC, RTE_LRNPINIONCENTR_APPL_VAR) RefTmr_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_LrnPinionCentr_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, P2VAR(uint32, AUTOMATIC, RTE_LRNPINIONCENTR_APPL_VAR) TiSpan_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_LrnPinionCentr_LrnPinionCentrDampgCtrlGain_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_LrnPinionCentr_LrnPinionCentrHldTq_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_LrnPinionCentr_LrnPinionCentrHldTqErrThd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_LrnPinionCentr_LrnPinionCentrHldTqRateLim_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_LrnPinionCentr_LrnPinionCentrHwPosnErrThd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_LrnPinionCentr_LrnPinionCentrIntglCtrlGain_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_LrnPinionCentr_LrnPinionCentrMaxTqCmd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_LrnPinionCentr_LrnPinionCentrMinMotTq_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_LrnPinionCentr_LrnPinionCentrMotVelThd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_LrnPinionCentr_LrnPinionCentrPropCtrlGain_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_LrnPinionCentr_SysGlbPrmSysKineRat_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint16, RTE_CODE) Rte_Prm_LrnPinionCentr_LrnPinionCentrTiOutThd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint16, RTE_CODE) Rte_Prm_LrnPinionCentr_LrnPinionCentrTiThd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_IrvRead_LrnPinionCentr_LrnPinionCentrPer1_TarA(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_IrvRead_LrnPinionCentr_LrnPinionCentrPer1_TarVel(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, RTE_CODE) Rte_IrvWrite_LrnPinionCentr_SetInpPrm_Oper_TarA(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, RTE_CODE) Rte_IrvWrite_LrnPinionCentr_SetInpPrm_Oper_TarVel(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_HwAg_Val Rte_Read_LrnPinionCentr_HwAg_Val
# define Rte_Read_MotVelCrf_Val Rte_Read_LrnPinionCentr_MotVelCrf_Val
# define Rte_Read_PinionCentrLrnEna_Logl Rte_Read_LrnPinionCentr_PinionCentrLrnEna_Logl


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_PinionCentrLrnCmd_Val Rte_Write_LrnPinionCentr_PinionCentrLrnCmd_Val
# define Rte_Write_PinionCentrLrnHwCentr_Val Rte_Write_LrnPinionCentr_PinionCentrLrnHwCentr_Val
# define Rte_Write_PinionCentrLrnHwTrvl_Val Rte_Write_LrnPinionCentr_PinionCentrLrnHwTrvl_Val
# define Rte_Write_PinionCentrLrnSt_Val Rte_Write_LrnPinionCentr_PinionCentrLrnSt_Val


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_GetRefTmr100MicroSec32bit_Oper Rte_Call_LrnPinionCentr_GetRefTmr100MicroSec32bit_Oper
# define Rte_Call_GetTiSpan100MicroSec32bit_Oper Rte_Call_LrnPinionCentr_GetTiSpan100MicroSec32bit_Oper


/**********************************************************************************************************************
 * Inter-runnable variables
 *********************************************************************************************************************/

/* PRQA S 3453 L1 */ /* MD_MSR_19.7 */
# define Rte_IrvRead_LrnPinionCentrPer1_TarA() \
  Rte_IrvRead_LrnPinionCentr_LrnPinionCentrPer1_TarA()
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_19.7 */
# define Rte_IrvRead_LrnPinionCentrPer1_TarVel() \
  Rte_IrvRead_LrnPinionCentr_LrnPinionCentrPer1_TarVel()
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_19.7 */
# define Rte_IrvWrite_SetInpPrm_Oper_TarA(data) \
  Rte_IrvWrite_LrnPinionCentr_SetInpPrm_Oper_TarA(data)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_19.7 */
# define Rte_IrvWrite_SetInpPrm_Oper_TarVel(data) \
  Rte_IrvWrite_LrnPinionCentr_SetInpPrm_Oper_TarVel(data)
/* PRQA L:L1 */


/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

# define Rte_Prm_LrnPinionCentrDampgCtrlGain_Val Rte_Prm_LrnPinionCentr_LrnPinionCentrDampgCtrlGain_Val

# define Rte_Prm_LrnPinionCentrHldTq_Val Rte_Prm_LrnPinionCentr_LrnPinionCentrHldTq_Val

# define Rte_Prm_LrnPinionCentrHldTqErrThd_Val Rte_Prm_LrnPinionCentr_LrnPinionCentrHldTqErrThd_Val

# define Rte_Prm_LrnPinionCentrHldTqRateLim_Val Rte_Prm_LrnPinionCentr_LrnPinionCentrHldTqRateLim_Val

# define Rte_Prm_LrnPinionCentrHwPosnErrThd_Val Rte_Prm_LrnPinionCentr_LrnPinionCentrHwPosnErrThd_Val

# define Rte_Prm_LrnPinionCentrIntglCtrlGain_Val Rte_Prm_LrnPinionCentr_LrnPinionCentrIntglCtrlGain_Val

# define Rte_Prm_LrnPinionCentrMaxTqCmd_Val Rte_Prm_LrnPinionCentr_LrnPinionCentrMaxTqCmd_Val

# define Rte_Prm_LrnPinionCentrMinMotTq_Val Rte_Prm_LrnPinionCentr_LrnPinionCentrMinMotTq_Val

# define Rte_Prm_LrnPinionCentrMotVelThd_Val Rte_Prm_LrnPinionCentr_LrnPinionCentrMotVelThd_Val

# define Rte_Prm_LrnPinionCentrPropCtrlGain_Val Rte_Prm_LrnPinionCentr_LrnPinionCentrPropCtrlGain_Val

# define Rte_Prm_SysGlbPrmSysKineRat_Val Rte_Prm_LrnPinionCentr_SysGlbPrmSysKineRat_Val

# define Rte_Prm_LrnPinionCentrTiOutThd_Val Rte_Prm_LrnPinionCentr_LrnPinionCentrTiOutThd_Val

# define Rte_Prm_LrnPinionCentrTiThd_Val Rte_Prm_LrnPinionCentr_LrnPinionCentrTiThd_Val

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_MaxHwPosnPrev() (Rte_Inst_LrnPinionCentr->Pim_MaxHwPosnPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MinHwPosnPrev() (Rte_Inst_LrnPinionCentr->Pim_MinHwPosnPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_PinionCentrLrnHwCentrPrev() (Rte_Inst_LrnPinionCentr->Pim_PinionCentrLrnHwCentrPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_PinionCentrLrnHwTrvlPrev() (Rte_Inst_LrnPinionCentr->Pim_PinionCentrLrnHwTrvlPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_StCtrl1PosnErrRateLim() (Rte_Inst_LrnPinionCentr->Pim_StCtrl1PosnErrRateLim) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_StCtrl2TqErrRateLim() (Rte_Inst_LrnPinionCentr->Pim_StCtrl2TqErrRateLim) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_StCtrl3PosnErrRateLim() (Rte_Inst_LrnPinionCentr->Pim_StCtrl3PosnErrRateLim) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_StCtrl3TqErrRateLim() (Rte_Inst_LrnPinionCentr->Pim_StCtrl3TqErrRateLim) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_StCtrl4TqErrRateLim() (Rte_Inst_LrnPinionCentr->Pim_StCtrl4TqErrRateLim) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_StCtrl5IntglEnaOutpPrev() (Rte_Inst_LrnPinionCentr->Pim_StCtrl5IntglEnaOutpPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_StCtrl5PosnErrRateLim() (Rte_Inst_LrnPinionCentr->Pim_StCtrl5PosnErrRateLim) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_StCtrl5TqErrRateLim() (Rte_Inst_LrnPinionCentr->Pim_StCtrl5TqErrRateLim) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_TarHwAg() (Rte_Inst_LrnPinionCentr->Pim_TarHwAg) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_TarMotVel() (Rte_Inst_LrnPinionCentr->Pim_TarMotVel) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_TqCmdEstimdPrev() (Rte_Inst_LrnPinionCentr->Pim_TqCmdEstimdPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dLrnPinionCentrHwPosnCmd() (Rte_Inst_LrnPinionCentr->Pim_dLrnPinionCentrHwPosnCmd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_StCtrl1TmrARefTi() (Rte_Inst_LrnPinionCentr->Pim_StCtrl1TmrARefTi) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_StCtrl1TmrBRefTi() (Rte_Inst_LrnPinionCentr->Pim_StCtrl1TmrBRefTi) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_StCtrl2TmrARefTi() (Rte_Inst_LrnPinionCentr->Pim_StCtrl2TmrARefTi) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_StCtrl2TmrBRefTi() (Rte_Inst_LrnPinionCentr->Pim_StCtrl2TmrBRefTi) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_StCtrl3TmrARefTi() (Rte_Inst_LrnPinionCentr->Pim_StCtrl3TmrARefTi) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_StCtrl3TmrBRefTi() (Rte_Inst_LrnPinionCentr->Pim_StCtrl3TmrBRefTi) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_StCtrl4TmrARefTi() (Rte_Inst_LrnPinionCentr->Pim_StCtrl4TmrARefTi) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_StCtrl4TmrBRefTi() (Rte_Inst_LrnPinionCentr->Pim_StCtrl4TmrBRefTi) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_StCtrl5TmrARefTi() (Rte_Inst_LrnPinionCentr->Pim_StCtrl5TmrARefTi) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_StCtrl5TmrBRefTi() (Rte_Inst_LrnPinionCentr->Pim_StCtrl5TmrBRefTi) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_StEstimdPrev() (Rte_Inst_LrnPinionCentr->Pim_StEstimdPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_PinionCentrLrnEnaPrev() (Rte_Inst_LrnPinionCentr->Pim_PinionCentrLrnEnaPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_StCtrl1RateLimdPosnErrLpFil() (Rte_Inst_LrnPinionCentr->Pim_StCtrl1RateLimdPosnErrLpFil) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_StCtrl2RateLimdTqErrLpFil() (Rte_Inst_LrnPinionCentr->Pim_StCtrl2RateLimdTqErrLpFil) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_StCtrl3RateLimdPosnErrLpFil() (Rte_Inst_LrnPinionCentr->Pim_StCtrl3RateLimdPosnErrLpFil) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_StCtrl3RateLimdTqErrLpFil() (Rte_Inst_LrnPinionCentr->Pim_StCtrl3RateLimdTqErrLpFil) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_StCtrl4RateLimdTqErrLpFil() (Rte_Inst_LrnPinionCentr->Pim_StCtrl4RateLimdTqErrLpFil) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_StCtrl5RateLimdPosnErrLpFil() (Rte_Inst_LrnPinionCentr->Pim_StCtrl5RateLimdPosnErrLpFil) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_StCtrl5RateLimdTqErrLpFil() (Rte_Inst_LrnPinionCentr->Pim_StCtrl5RateLimdTqErrLpFil) /* PRQA S 3453 */ /* MD_MSR_19.7 */




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   float32 *Rte_Pim_MaxHwPosnPrev(void)
 *   float32 *Rte_Pim_MinHwPosnPrev(void)
 *   float32 *Rte_Pim_PinionCentrLrnHwCentrPrev(void)
 *   float32 *Rte_Pim_PinionCentrLrnHwTrvlPrev(void)
 *   float32 *Rte_Pim_StCtrl1PosnErrRateLim(void)
 *   float32 *Rte_Pim_StCtrl2TqErrRateLim(void)
 *   float32 *Rte_Pim_StCtrl3PosnErrRateLim(void)
 *   float32 *Rte_Pim_StCtrl3TqErrRateLim(void)
 *   float32 *Rte_Pim_StCtrl4TqErrRateLim(void)
 *   float32 *Rte_Pim_StCtrl5IntglEnaOutpPrev(void)
 *   float32 *Rte_Pim_StCtrl5PosnErrRateLim(void)
 *   float32 *Rte_Pim_StCtrl5TqErrRateLim(void)
 *   float32 *Rte_Pim_TarHwAg(void)
 *   float32 *Rte_Pim_TarMotVel(void)
 *   float32 *Rte_Pim_TqCmdEstimdPrev(void)
 *   float32 *Rte_Pim_dLrnPinionCentrHwPosnCmd(void)
 *   uint32 *Rte_Pim_StCtrl1TmrARefTi(void)
 *   uint32 *Rte_Pim_StCtrl1TmrBRefTi(void)
 *   uint32 *Rte_Pim_StCtrl2TmrARefTi(void)
 *   uint32 *Rte_Pim_StCtrl2TmrBRefTi(void)
 *   uint32 *Rte_Pim_StCtrl3TmrARefTi(void)
 *   uint32 *Rte_Pim_StCtrl3TmrBRefTi(void)
 *   uint32 *Rte_Pim_StCtrl4TmrARefTi(void)
 *   uint32 *Rte_Pim_StCtrl4TmrBRefTi(void)
 *   uint32 *Rte_Pim_StCtrl5TmrARefTi(void)
 *   uint32 *Rte_Pim_StCtrl5TmrBRefTi(void)
 *   uint8 *Rte_Pim_StEstimdPrev(void)
 *   boolean *Rte_Pim_PinionCentrLrnEnaPrev(void)
 *   FilLpRec1 *Rte_Pim_StCtrl1RateLimdPosnErrLpFil(void)
 *   FilLpRec1 *Rte_Pim_StCtrl2RateLimdTqErrLpFil(void)
 *   FilLpRec1 *Rte_Pim_StCtrl3RateLimdPosnErrLpFil(void)
 *   FilLpRec1 *Rte_Pim_StCtrl3RateLimdTqErrLpFil(void)
 *   FilLpRec1 *Rte_Pim_StCtrl4RateLimdTqErrLpFil(void)
 *   FilLpRec1 *Rte_Pim_StCtrl5RateLimdPosnErrLpFil(void)
 *   FilLpRec1 *Rte_Pim_StCtrl5RateLimdTqErrLpFil(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_LrnPinionCentrDampgCtrlGain_Val(void)
 *   float32 Rte_Prm_LrnPinionCentrHldTq_Val(void)
 *   float32 Rte_Prm_LrnPinionCentrHldTqErrThd_Val(void)
 *   float32 Rte_Prm_LrnPinionCentrHldTqRateLim_Val(void)
 *   float32 Rte_Prm_LrnPinionCentrHwPosnErrThd_Val(void)
 *   float32 Rte_Prm_LrnPinionCentrIntglCtrlGain_Val(void)
 *   float32 Rte_Prm_LrnPinionCentrMaxTqCmd_Val(void)
 *   float32 Rte_Prm_LrnPinionCentrMinMotTq_Val(void)
 *   float32 Rte_Prm_LrnPinionCentrMotVelThd_Val(void)
 *   float32 Rte_Prm_LrnPinionCentrPropCtrlGain_Val(void)
 *   float32 Rte_Prm_SysGlbPrmSysKineRat_Val(void)
 *   uint16 Rte_Prm_LrnPinionCentrTiOutThd_Val(void)
 *   uint16 Rte_Prm_LrnPinionCentrTiThd_Val(void)
 *
 *********************************************************************************************************************/


# define LrnPinionCentr_START_SEC_CODE
# include "LrnPinionCentr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: LrnPinionCentrInit1
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
 *********************************************************************************************************************/

# define RTE_RUNNABLE_LrnPinionCentrInit1 LrnPinionCentrInit1
FUNC(void, LrnPinionCentr_CODE) LrnPinionCentrInit1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: LrnPinionCentrPer1
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
 *   Std_ReturnType Rte_Read_HwAg_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotVelCrf_Val(float32 *data)
 *   Std_ReturnType Rte_Read_PinionCentrLrnEna_Logl(boolean *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_PinionCentrLrnCmd_Val(float32 data)
 *   Std_ReturnType Rte_Write_PinionCentrLrnHwCentr_Val(float32 data)
 *   Std_ReturnType Rte_Write_PinionCentrLrnHwTrvl_Val(float32 data)
 *   Std_ReturnType Rte_Write_PinionCentrLrnSt_Val(uint8 data)
 *
 * Inter Runnable Variables:
 * =========================
 *   Explicit Read Access:
 *   ---------------------
 *   float32 Rte_IrvRead_LrnPinionCentrPer1_TarA(void)
 *   float32 Rte_IrvRead_LrnPinionCentrPer1_TarVel(void)
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

# define RTE_RUNNABLE_LrnPinionCentrPer1 LrnPinionCentrPer1
FUNC(void, LrnPinionCentr_CODE) LrnPinionCentrPer1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SetInpPrm_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <SetInpPrm>
 *
 **********************************************************************************************************************
 *
 * Inter Runnable Variables:
 * =========================
 *   Explicit Write Access:
 *   ----------------------
 *   void Rte_IrvWrite_SetInpPrm_Oper_TarA(float32 data)
 *   void Rte_IrvWrite_SetInpPrm_Oper_TarVel(float32 data)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void SetInpPrm_Oper(float32 TarVel_Arg, float32 TarA_Arg)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_SetInpPrm_Oper SetInpPrm_Oper
FUNC(void, LrnPinionCentr_CODE) SetInpPrm_Oper(float32 TarVel_Arg, float32 TarA_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define LrnPinionCentr_STOP_SEC_CODE
# include "LrnPinionCentr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_LRNPINIONCENTR_H */

#include "Rte_Stubs.h"
