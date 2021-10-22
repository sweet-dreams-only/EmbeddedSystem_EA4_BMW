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
 *          File:  Rte_TqOscn.h
 *     SW-C Type:  TqOscn
 *  Generated at:  Thu May 26 12:28:18 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 4.3.0
 *                 RTE Core Version 1.3.0
 *       License:  Unlimited license CBD1400351 (THE ECU PRODUCT "STEERING SYSTEMS", THE ECU SUPPLIER "NXTR", THE VEHICLE MANUFACTURER "GENERAL MOTORS CORPORATION") for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <TqOscn> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_TQOSCN_H
# define _RTE_TQOSCN_H

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

# include "Rte_TqOscn_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_TqOscn
{
  /* PIM Handles section */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_AmpRampSt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(FilLpRec1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_PreFinalCmdLpFil; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_PrevActv; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_PrevDcThdExcdd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_PrevEna; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_PrevFallRampRate; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_PrevLimdAmp; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_PrevPhaAg; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_PrevPhaAgInc; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_PrevRisngRampRate; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dTqOscnNonZeroAmpFlg; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dTqOscnPreFinalCmd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dTqOscnRateLimdAmp; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dTqOscnSinCmd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_TqOscn, RTE_CONST, RTE_CONST) Rte_Inst_TqOscn; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_TqOscn, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_HwOscnActv_Logl (FALSE)
# define Rte_InitValue_HwOscnCmd_Val (0.0F)
# define Rte_InitValue_HwOscnDcThdExcdd_Logl (FALSE)
# define Rte_InitValue_HwOscnEna_Logl (FALSE)
# define Rte_InitValue_HwOscnFallRampRate_Val (-4400.0F)
# define Rte_InitValue_HwOscnFrq_Val (50.0F)
# define Rte_InitValue_HwOscnMotAmp_Val (0.0F)
# define Rte_InitValue_HwOscnRisngRampRate_Val (4400.0F)


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_TqOscn_HwOscnEna_Logl(P2VAR(boolean, AUTOMATIC, RTE_TQOSCN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_TqOscn_HwOscnFallRampRate_Val(P2VAR(float32, AUTOMATIC, RTE_TQOSCN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_TqOscn_HwOscnFrq_Val(P2VAR(float32, AUTOMATIC, RTE_TQOSCN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_TqOscn_HwOscnMotAmp_Val(P2VAR(float32, AUTOMATIC, RTE_TQOSCN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_TqOscn_HwOscnRisngRampRate_Val(P2VAR(float32, AUTOMATIC, RTE_TQOSCN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_TqOscn_HwOscnActv_Logl(boolean data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_TqOscn_HwOscnCmd_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_TqOscn_HwOscnDcThdExcdd_Logl(boolean data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_TqOscn_FltInj_f32_Oper(P2VAR(float32, AUTOMATIC, RTE_TQOSCN_APPL_VAR) SigPah_Arg, uint16 LocnKey_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_TqOscn_TqOscnFallRampRateCal_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_TqOscn_TqOscnRisngRampRateCal_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(boolean, RTE_CODE) Rte_Prm_TqOscn_TqOscnUseRampRateCal_Logl(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u5p11, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_TqOscn_TqOscnAmpLimY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u5p11_11, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_TqOscn_TqOscnAmpLimY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u8p8, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_TqOscn_TqOscnFrqIn_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u8p8_11, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_TqOscn_TqOscnFrqIn_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_HwOscnEna_Logl Rte_Read_TqOscn_HwOscnEna_Logl
# define Rte_Read_HwOscnFallRampRate_Val Rte_Read_TqOscn_HwOscnFallRampRate_Val
# define Rte_Read_HwOscnFrq_Val Rte_Read_TqOscn_HwOscnFrq_Val
# define Rte_Read_HwOscnMotAmp_Val Rte_Read_TqOscn_HwOscnMotAmp_Val
# define Rte_Read_HwOscnRisngRampRate_Val Rte_Read_TqOscn_HwOscnRisngRampRate_Val


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_HwOscnActv_Logl Rte_Write_TqOscn_HwOscnActv_Logl
# define Rte_Write_HwOscnCmd_Val Rte_Write_TqOscn_HwOscnCmd_Val
# define Rte_Write_HwOscnDcThdExcdd_Logl Rte_Write_TqOscn_HwOscnDcThdExcdd_Logl


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_FltInj_f32_Oper Rte_Call_TqOscn_FltInj_f32_Oper


/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

# define Rte_Prm_TqOscnFallRampRateCal_Val Rte_Prm_TqOscn_TqOscnFallRampRateCal_Val

# define Rte_Prm_TqOscnRisngRampRateCal_Val Rte_Prm_TqOscn_TqOscnRisngRampRateCal_Val

# define Rte_Prm_TqOscnUseRampRateCal_Logl Rte_Prm_TqOscn_TqOscnUseRampRateCal_Logl

# define Rte_Prm_TqOscnAmpLimY_Ary1D Rte_Prm_TqOscn_TqOscnAmpLimY_Ary1D

# define Rte_Prm_TqOscnFrqIn_Ary1D Rte_Prm_TqOscn_TqOscnFrqIn_Ary1D

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_AmpRampSt() (Rte_Inst_TqOscn->Pim_AmpRampSt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_PrevFallRampRate() (Rte_Inst_TqOscn->Pim_PrevFallRampRate) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_PrevLimdAmp() (Rte_Inst_TqOscn->Pim_PrevLimdAmp) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_PrevPhaAg() (Rte_Inst_TqOscn->Pim_PrevPhaAg) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_PrevPhaAgInc() (Rte_Inst_TqOscn->Pim_PrevPhaAgInc) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_PrevRisngRampRate() (Rte_Inst_TqOscn->Pim_PrevRisngRampRate) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dTqOscnPreFinalCmd() (Rte_Inst_TqOscn->Pim_dTqOscnPreFinalCmd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dTqOscnRateLimdAmp() (Rte_Inst_TqOscn->Pim_dTqOscnRateLimdAmp) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dTqOscnSinCmd() (Rte_Inst_TqOscn->Pim_dTqOscnSinCmd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_PrevActv() (Rte_Inst_TqOscn->Pim_PrevActv) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_PrevDcThdExcdd() (Rte_Inst_TqOscn->Pim_PrevDcThdExcdd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_PrevEna() (Rte_Inst_TqOscn->Pim_PrevEna) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dTqOscnNonZeroAmpFlg() (Rte_Inst_TqOscn->Pim_dTqOscnNonZeroAmpFlg) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_PreFinalCmdLpFil() (Rte_Inst_TqOscn->Pim_PreFinalCmdLpFil) /* PRQA S 3453 */ /* MD_MSR_19.7 */




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   float32 *Rte_Pim_AmpRampSt(void)
 *   float32 *Rte_Pim_PrevFallRampRate(void)
 *   float32 *Rte_Pim_PrevLimdAmp(void)
 *   float32 *Rte_Pim_PrevPhaAg(void)
 *   float32 *Rte_Pim_PrevPhaAgInc(void)
 *   float32 *Rte_Pim_PrevRisngRampRate(void)
 *   float32 *Rte_Pim_dTqOscnPreFinalCmd(void)
 *   float32 *Rte_Pim_dTqOscnRateLimdAmp(void)
 *   float32 *Rte_Pim_dTqOscnSinCmd(void)
 *   boolean *Rte_Pim_PrevActv(void)
 *   boolean *Rte_Pim_PrevDcThdExcdd(void)
 *   boolean *Rte_Pim_PrevEna(void)
 *   boolean *Rte_Pim_dTqOscnNonZeroAmpFlg(void)
 *   FilLpRec1 *Rte_Pim_PreFinalCmdLpFil(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_TqOscnFallRampRateCal_Val(void)
 *   float32 Rte_Prm_TqOscnRisngRampRateCal_Val(void)
 *   boolean Rte_Prm_TqOscnUseRampRateCal_Logl(void)
 *   u5p11 *Rte_Prm_TqOscnAmpLimY_Ary1D(void)
 *   u8p8 *Rte_Prm_TqOscnFrqIn_Ary1D(void)
 *
 *********************************************************************************************************************/


# define TqOscn_START_SEC_CODE
# include "TqOscn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: TqOscnInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_TqOscnInit1 TqOscnInit1
FUNC(void, TqOscn_CODE) TqOscnInit1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TqOscnPer1
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
 *   Std_ReturnType Rte_Read_HwOscnEna_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_HwOscnFallRampRate_Val(float32 *data)
 *   Std_ReturnType Rte_Read_HwOscnFrq_Val(float32 *data)
 *   Std_ReturnType Rte_Read_HwOscnMotAmp_Val(float32 *data)
 *   Std_ReturnType Rte_Read_HwOscnRisngRampRate_Val(float32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_HwOscnActv_Logl(boolean data)
 *   Std_ReturnType Rte_Write_HwOscnCmd_Val(float32 data)
 *   Std_ReturnType Rte_Write_HwOscnDcThdExcdd_Logl(boolean data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_FltInj_f32_Oper(float32 *SigPah_Arg, uint16 LocnKey_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_TqOscnPer1 TqOscnPer1
FUNC(void, TqOscn_CODE) TqOscnPer1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define TqOscn_STOP_SEC_CODE
# include "TqOscn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1464286000
#    error "The magic number of the generated file <C:/Component/SF043A_TqOscn_Impl/tools/contract/Rte_TqOscn.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1464286000
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_TQOSCN_H */
