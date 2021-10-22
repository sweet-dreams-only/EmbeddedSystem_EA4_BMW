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
 *          File:  Rte_PullCmpActv.h
 *        Config:  C:/Component/SF013A_PullCmpActv_Impl/tools/Component.dpa
 *     SW-C Type:  PullCmpActv
 *  Generated at:  Wed Jan 24 10:44:46 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <PullCmpActv> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_PULLCMPACTV_H
# define _RTE_PULLCMPACTV_H

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

# include "Rte_PullCmpActv_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_PullCmpActv
{
  /* PIM Handles section */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_CmpLrnTiDecShoTerm; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_CmpLrnTiIncShoTerm; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_CmpLrnTiLongTerm; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(FilLpRec1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_HwTqLpFilLongTerm; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(FilLpRec1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_HwTqLpFilLrngEna; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(FilLpRec1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_HwTqLpFilShoTerm; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_IntgtrGainDecShoTerm; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_IntgtrGainIncShoTerm; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_LrngEnaPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_LrngEnad; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_OpstSignPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_PrevLrnTiLongTerm; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_PullCmpActvDi; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_PullCmpCmdRateLimPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_PullCmpCmdTot; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_PullCmpLongTerm; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_PullCmpLongTermRst; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_PullCmpShoTerm; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_PullCmpShoTermRst; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_RefTiEnaLrng; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_RefTiOpstSign; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_VehSpdPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_VehSpdRate; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(FilLpRec1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_VehYawRateLpFil; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dPullCmpActvIntgtrGainShoTerm; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dPullCmpActvPullErrLongTerm; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dPullCmpActvPullErrShoTerm; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dPullCmpActvShoTermRst; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_PullCmpActv, RTE_CONST, RTE_CONST) Rte_Inst_PullCmpActv; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_PullCmpActv, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_HwAg_Val (0.0F)
# define Rte_InitValue_HwTq_Val (0.0F)
# define Rte_InitValue_HwVel_Val (0.0F)
# define Rte_InitValue_PinionAgConf_Val (0.0F)
# define Rte_InitValue_PullCmpActvDi_Logl (FALSE)
# define Rte_InitValue_PullCmpCmd_Val (0.0F)
# define Rte_InitValue_PullCmpCmdDi_Logl (FALSE)
# define Rte_InitValue_PullCmpCustLrngDi_Logl (FALSE)
# define Rte_InitValue_PullCmpLrngDi_Logl (FALSE)
# define Rte_InitValue_VehLatA_Val (0.0F)
# define Rte_InitValue_VehSpd_Val (0.0F)
# define Rte_InitValue_VehSpdVld_Logl (FALSE)
# define Rte_InitValue_VehYawRate_Val (0.0F)
# define Rte_InitValue_VehYawRateVld_Logl (FALSE)


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PullCmpActv_HwAg_Val(P2VAR(float32, AUTOMATIC, RTE_PULLCMPACTV_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PullCmpActv_HwTq_Val(P2VAR(float32, AUTOMATIC, RTE_PULLCMPACTV_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PullCmpActv_HwVel_Val(P2VAR(float32, AUTOMATIC, RTE_PULLCMPACTV_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PullCmpActv_PinionAgConf_Val(P2VAR(float32, AUTOMATIC, RTE_PULLCMPACTV_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PullCmpActv_PullCmpActvDi_Logl(P2VAR(boolean, AUTOMATIC, RTE_PULLCMPACTV_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PullCmpActv_PullCmpCmdDi_Logl(P2VAR(boolean, AUTOMATIC, RTE_PULLCMPACTV_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PullCmpActv_PullCmpCustLrngDi_Logl(P2VAR(boolean, AUTOMATIC, RTE_PULLCMPACTV_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PullCmpActv_PullCmpLrngDi_Logl(P2VAR(boolean, AUTOMATIC, RTE_PULLCMPACTV_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PullCmpActv_VehLatA_Val(P2VAR(float32, AUTOMATIC, RTE_PULLCMPACTV_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PullCmpActv_VehSpd_Val(P2VAR(float32, AUTOMATIC, RTE_PULLCMPACTV_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PullCmpActv_VehSpdVld_Logl(P2VAR(boolean, AUTOMATIC, RTE_PULLCMPACTV_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PullCmpActv_VehYawRate_Val(P2VAR(float32, AUTOMATIC, RTE_PULLCMPACTV_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PullCmpActv_VehYawRateVld_Logl(P2VAR(boolean, AUTOMATIC, RTE_PULLCMPACTV_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PullCmpActv_PullCmpCmd_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PullCmpActv_FltInj_f32_Oper(P2VAR(float32, AUTOMATIC, RTE_PULLCMPACTV_APPL_VAR) SigPah_Arg, uint16 LocnKey_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PullCmpActv_GetRefTmr100MicroSec32bit_Oper(P2VAR(uint32, AUTOMATIC, RTE_PULLCMPACTV_APPL_VAR) RefTmr_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PullCmpActv_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, P2VAR(uint32, AUTOMATIC, RTE_PULLCMPACTV_APPL_VAR) TiSpan_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PullCmpActv_PullCmpLongTerm_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_PULLCMPACTV_APPL_VAR) ErrorStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PullCmpActv_PullCmpLongTerm_SetRamBlockStatus(Boolean RamBlockStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_PullCmpActv_PullCmpActvCmpLrnTiDecShoTerm_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_PullCmpActv_PullCmpActvCmpLrnTiIncShoTerm_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_PullCmpActv_PullCmpActvCmpLrnTiLongTerm_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_PullCmpActv_PullCmpActvCmpShoTermRstHwAgThd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_PullCmpActv_PullCmpActvCmpShoTermRstHwTqThd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_PullCmpActv_PullCmpActvCmpShoTermRstLatAThd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_PullCmpActv_PullCmpActvCmpShoTermRstYawRateThd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_PullCmpActv_PullCmpActvHwTqFilFrqLongTerm_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_PullCmpActv_PullCmpActvHwTqFilFrqLrngEna_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_PullCmpActv_PullCmpActvHwTqFilFrqShoTerm_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_PullCmpActv_PullCmpActvLongTermLim_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_PullCmpActv_PullCmpActvLrngEnaAgConfMinMgn_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_PullCmpActv_PullCmpActvLrngEnaHwAgMaxMgn_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_PullCmpActv_PullCmpActvLrngEnaHwTqMaxMgn_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_PullCmpActv_PullCmpActvLrngEnaHwVelMaxMgn_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_PullCmpActv_PullCmpActvLrngEnaLatAMaxMgn_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_PullCmpActv_PullCmpActvLrngEnaTiThd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_PullCmpActv_PullCmpActvLrngEnaVehSpdMaxMgn_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_PullCmpActv_PullCmpActvLrngEnaVehSpdMinMgn_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_PullCmpActv_PullCmpActvLrngEnaVehSpdRateMaxMgn_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_PullCmpActv_PullCmpActvLrngEnaYawRateMaxMgn_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_PullCmpActv_PullCmpActvOpstSignTiShoTerm_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_PullCmpActv_PullCmpActvOutpMaxRate_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_PullCmpActv_PullCmpActvPullCmpShoTermLim_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_PullCmpActv_PullCmpActvPullCmpTotLim_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_PullCmpActv_PullCmpActvPullErrLimLongTerm_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_PullCmpActv_PullCmpActvPullErrMgnThd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_PullCmpActv_PullCmpActvPullErrShoTermLim_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_PullCmpActv_PullCmpActvShoTermRampTi_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_PullCmpActv_PullCmpActvYawRateFilFrq_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_PullCmpActv_SysGlbPrmSysTqRat_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(boolean, RTE_CODE) Rte_Prm_PullCmpActv_PullCmpActvEna_Logl(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u9p7, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_PullCmpActv_PullCmpActvVehSpdScaTblX_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u9p7_4, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_PullCmpActv_PullCmpActvVehSpdScaTblX_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u2p14, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_PullCmpActv_PullCmpActvVehSpdScaTblY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u2p14_4, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_PullCmpActv_PullCmpActvVehSpdScaTblY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
FUNC(void, RTE_CODE) Rte_IrvWrite_PullCmpActv_PullCmpActvInit1_RampDwnStepSize(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_IrvRead_PullCmpActv_PullCmpActvPer1_RampDwnStepSize(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

FUNC(float32, RTE_CODE) Rte_CData_PullCmpActv_PullCmpLongTermDft(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_HwAg_Val Rte_Read_PullCmpActv_HwAg_Val
# define Rte_Read_HwTq_Val Rte_Read_PullCmpActv_HwTq_Val
# define Rte_Read_HwVel_Val Rte_Read_PullCmpActv_HwVel_Val
# define Rte_Read_PinionAgConf_Val Rte_Read_PullCmpActv_PinionAgConf_Val
# define Rte_Read_PullCmpActvDi_Logl Rte_Read_PullCmpActv_PullCmpActvDi_Logl
# define Rte_Read_PullCmpCmdDi_Logl Rte_Read_PullCmpActv_PullCmpCmdDi_Logl
# define Rte_Read_PullCmpCustLrngDi_Logl Rte_Read_PullCmpActv_PullCmpCustLrngDi_Logl
# define Rte_Read_PullCmpLrngDi_Logl Rte_Read_PullCmpActv_PullCmpLrngDi_Logl
# define Rte_Read_VehLatA_Val Rte_Read_PullCmpActv_VehLatA_Val
# define Rte_Read_VehSpd_Val Rte_Read_PullCmpActv_VehSpd_Val
# define Rte_Read_VehSpdVld_Logl Rte_Read_PullCmpActv_VehSpdVld_Logl
# define Rte_Read_VehYawRate_Val Rte_Read_PullCmpActv_VehYawRate_Val
# define Rte_Read_VehYawRateVld_Logl Rte_Read_PullCmpActv_VehYawRateVld_Logl


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_PullCmpCmd_Val Rte_Write_PullCmpActv_PullCmpCmd_Val


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_FltInj_f32_Oper Rte_Call_PullCmpActv_FltInj_f32_Oper
# define Rte_Call_GetRefTmr100MicroSec32bit_Oper Rte_Call_PullCmpActv_GetRefTmr100MicroSec32bit_Oper
# define Rte_Call_GetTiSpan100MicroSec32bit_Oper Rte_Call_PullCmpActv_GetTiSpan100MicroSec32bit_Oper
# define Rte_Call_PullCmpLongTerm_GetErrorStatus Rte_Call_PullCmpActv_PullCmpLongTerm_GetErrorStatus
# define Rte_Call_PullCmpLongTerm_SetRamBlockStatus Rte_Call_PullCmpActv_PullCmpLongTerm_SetRamBlockStatus


/**********************************************************************************************************************
 * Inter-runnable variables
 *********************************************************************************************************************/

/* PRQA S 3453 L1 */ /* MD_MSR_19.7 */
# define Rte_IrvWrite_PullCmpActvInit1_RampDwnStepSize(data) \
  Rte_IrvWrite_PullCmpActv_PullCmpActvInit1_RampDwnStepSize(data)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_19.7 */
# define Rte_IrvRead_PullCmpActvPer1_RampDwnStepSize() \
  Rte_IrvRead_PullCmpActv_PullCmpActvPer1_RampDwnStepSize()
/* PRQA L:L1 */


/**********************************************************************************************************************
 * Rte_CData (SW-C local calibration parameters)
 *********************************************************************************************************************/

# define Rte_CData_PullCmpLongTermDft Rte_CData_PullCmpActv_PullCmpLongTermDft

/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

# define Rte_Prm_PullCmpActvCmpLrnTiDecShoTerm_Val Rte_Prm_PullCmpActv_PullCmpActvCmpLrnTiDecShoTerm_Val

# define Rte_Prm_PullCmpActvCmpLrnTiIncShoTerm_Val Rte_Prm_PullCmpActv_PullCmpActvCmpLrnTiIncShoTerm_Val

# define Rte_Prm_PullCmpActvCmpLrnTiLongTerm_Val Rte_Prm_PullCmpActv_PullCmpActvCmpLrnTiLongTerm_Val

# define Rte_Prm_PullCmpActvCmpShoTermRstHwAgThd_Val Rte_Prm_PullCmpActv_PullCmpActvCmpShoTermRstHwAgThd_Val

# define Rte_Prm_PullCmpActvCmpShoTermRstHwTqThd_Val Rte_Prm_PullCmpActv_PullCmpActvCmpShoTermRstHwTqThd_Val

# define Rte_Prm_PullCmpActvCmpShoTermRstLatAThd_Val Rte_Prm_PullCmpActv_PullCmpActvCmpShoTermRstLatAThd_Val

# define Rte_Prm_PullCmpActvCmpShoTermRstYawRateThd_Val Rte_Prm_PullCmpActv_PullCmpActvCmpShoTermRstYawRateThd_Val

# define Rte_Prm_PullCmpActvHwTqFilFrqLongTerm_Val Rte_Prm_PullCmpActv_PullCmpActvHwTqFilFrqLongTerm_Val

# define Rte_Prm_PullCmpActvHwTqFilFrqLrngEna_Val Rte_Prm_PullCmpActv_PullCmpActvHwTqFilFrqLrngEna_Val

# define Rte_Prm_PullCmpActvHwTqFilFrqShoTerm_Val Rte_Prm_PullCmpActv_PullCmpActvHwTqFilFrqShoTerm_Val

# define Rte_Prm_PullCmpActvLongTermLim_Val Rte_Prm_PullCmpActv_PullCmpActvLongTermLim_Val

# define Rte_Prm_PullCmpActvLrngEnaAgConfMinMgn_Val Rte_Prm_PullCmpActv_PullCmpActvLrngEnaAgConfMinMgn_Val

# define Rte_Prm_PullCmpActvLrngEnaHwAgMaxMgn_Val Rte_Prm_PullCmpActv_PullCmpActvLrngEnaHwAgMaxMgn_Val

# define Rte_Prm_PullCmpActvLrngEnaHwTqMaxMgn_Val Rte_Prm_PullCmpActv_PullCmpActvLrngEnaHwTqMaxMgn_Val

# define Rte_Prm_PullCmpActvLrngEnaHwVelMaxMgn_Val Rte_Prm_PullCmpActv_PullCmpActvLrngEnaHwVelMaxMgn_Val

# define Rte_Prm_PullCmpActvLrngEnaLatAMaxMgn_Val Rte_Prm_PullCmpActv_PullCmpActvLrngEnaLatAMaxMgn_Val

# define Rte_Prm_PullCmpActvLrngEnaTiThd_Val Rte_Prm_PullCmpActv_PullCmpActvLrngEnaTiThd_Val

# define Rte_Prm_PullCmpActvLrngEnaVehSpdMaxMgn_Val Rte_Prm_PullCmpActv_PullCmpActvLrngEnaVehSpdMaxMgn_Val

# define Rte_Prm_PullCmpActvLrngEnaVehSpdMinMgn_Val Rte_Prm_PullCmpActv_PullCmpActvLrngEnaVehSpdMinMgn_Val

# define Rte_Prm_PullCmpActvLrngEnaVehSpdRateMaxMgn_Val Rte_Prm_PullCmpActv_PullCmpActvLrngEnaVehSpdRateMaxMgn_Val

# define Rte_Prm_PullCmpActvLrngEnaYawRateMaxMgn_Val Rte_Prm_PullCmpActv_PullCmpActvLrngEnaYawRateMaxMgn_Val

# define Rte_Prm_PullCmpActvOpstSignTiShoTerm_Val Rte_Prm_PullCmpActv_PullCmpActvOpstSignTiShoTerm_Val

# define Rte_Prm_PullCmpActvOutpMaxRate_Val Rte_Prm_PullCmpActv_PullCmpActvOutpMaxRate_Val

# define Rte_Prm_PullCmpActvPullCmpShoTermLim_Val Rte_Prm_PullCmpActv_PullCmpActvPullCmpShoTermLim_Val

# define Rte_Prm_PullCmpActvPullCmpTotLim_Val Rte_Prm_PullCmpActv_PullCmpActvPullCmpTotLim_Val

# define Rte_Prm_PullCmpActvPullErrLimLongTerm_Val Rte_Prm_PullCmpActv_PullCmpActvPullErrLimLongTerm_Val

# define Rte_Prm_PullCmpActvPullErrMgnThd_Val Rte_Prm_PullCmpActv_PullCmpActvPullErrMgnThd_Val

# define Rte_Prm_PullCmpActvPullErrShoTermLim_Val Rte_Prm_PullCmpActv_PullCmpActvPullErrShoTermLim_Val

# define Rte_Prm_PullCmpActvShoTermRampTi_Val Rte_Prm_PullCmpActv_PullCmpActvShoTermRampTi_Val

# define Rte_Prm_PullCmpActvYawRateFilFrq_Val Rte_Prm_PullCmpActv_PullCmpActvYawRateFilFrq_Val

# define Rte_Prm_SysGlbPrmSysTqRat_Val Rte_Prm_PullCmpActv_SysGlbPrmSysTqRat_Val

# define Rte_Prm_PullCmpActvEna_Logl Rte_Prm_PullCmpActv_PullCmpActvEna_Logl

# define Rte_Prm_PullCmpActvVehSpdScaTblX_Ary1D Rte_Prm_PullCmpActv_PullCmpActvVehSpdScaTblX_Ary1D

# define Rte_Prm_PullCmpActvVehSpdScaTblY_Ary1D Rte_Prm_PullCmpActv_PullCmpActvVehSpdScaTblY_Ary1D

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_CmpLrnTiDecShoTerm() (Rte_Inst_PullCmpActv->Pim_CmpLrnTiDecShoTerm) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_CmpLrnTiIncShoTerm() (Rte_Inst_PullCmpActv->Pim_CmpLrnTiIncShoTerm) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_CmpLrnTiLongTerm() (Rte_Inst_PullCmpActv->Pim_CmpLrnTiLongTerm) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_IntgtrGainDecShoTerm() (Rte_Inst_PullCmpActv->Pim_IntgtrGainDecShoTerm) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_IntgtrGainIncShoTerm() (Rte_Inst_PullCmpActv->Pim_IntgtrGainIncShoTerm) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_PrevLrnTiLongTerm() (Rte_Inst_PullCmpActv->Pim_PrevLrnTiLongTerm) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_PullCmpCmdRateLimPrev() (Rte_Inst_PullCmpActv->Pim_PullCmpCmdRateLimPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_PullCmpCmdTot() (Rte_Inst_PullCmpActv->Pim_PullCmpCmdTot) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_PullCmpLongTerm() (Rte_Inst_PullCmpActv->Pim_PullCmpLongTerm) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_PullCmpShoTerm() (Rte_Inst_PullCmpActv->Pim_PullCmpShoTerm) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_VehSpdPrev() (Rte_Inst_PullCmpActv->Pim_VehSpdPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_VehSpdRate() (Rte_Inst_PullCmpActv->Pim_VehSpdRate) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dPullCmpActvIntgtrGainShoTerm() (Rte_Inst_PullCmpActv->Pim_dPullCmpActvIntgtrGainShoTerm) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dPullCmpActvPullErrLongTerm() (Rte_Inst_PullCmpActv->Pim_dPullCmpActvPullErrLongTerm) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dPullCmpActvPullErrShoTerm() (Rte_Inst_PullCmpActv->Pim_dPullCmpActvPullErrShoTerm) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_RefTiEnaLrng() (Rte_Inst_PullCmpActv->Pim_RefTiEnaLrng) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_RefTiOpstSign() (Rte_Inst_PullCmpActv->Pim_RefTiOpstSign) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_LrngEnaPrev() (Rte_Inst_PullCmpActv->Pim_LrngEnaPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_LrngEnad() (Rte_Inst_PullCmpActv->Pim_LrngEnad) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_OpstSignPrev() (Rte_Inst_PullCmpActv->Pim_OpstSignPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_PullCmpActvDi() (Rte_Inst_PullCmpActv->Pim_PullCmpActvDi) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_PullCmpLongTermRst() (Rte_Inst_PullCmpActv->Pim_PullCmpLongTermRst) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_PullCmpShoTermRst() (Rte_Inst_PullCmpActv->Pim_PullCmpShoTermRst) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dPullCmpActvShoTermRst() (Rte_Inst_PullCmpActv->Pim_dPullCmpActvShoTermRst) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_HwTqLpFilLongTerm() (Rte_Inst_PullCmpActv->Pim_HwTqLpFilLongTerm) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_HwTqLpFilLrngEna() (Rte_Inst_PullCmpActv->Pim_HwTqLpFilLrngEna) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_HwTqLpFilShoTerm() (Rte_Inst_PullCmpActv->Pim_HwTqLpFilShoTerm) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_VehYawRateLpFil() (Rte_Inst_PullCmpActv->Pim_VehYawRateLpFil) /* PRQA S 3453 */ /* MD_MSR_19.7 */




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   float32 *Rte_Pim_CmpLrnTiDecShoTerm(void)
 *   float32 *Rte_Pim_CmpLrnTiIncShoTerm(void)
 *   float32 *Rte_Pim_CmpLrnTiLongTerm(void)
 *   float32 *Rte_Pim_IntgtrGainDecShoTerm(void)
 *   float32 *Rte_Pim_IntgtrGainIncShoTerm(void)
 *   float32 *Rte_Pim_PrevLrnTiLongTerm(void)
 *   float32 *Rte_Pim_PullCmpCmdRateLimPrev(void)
 *   float32 *Rte_Pim_PullCmpCmdTot(void)
 *   float32 *Rte_Pim_PullCmpLongTerm(void)
 *   float32 *Rte_Pim_PullCmpShoTerm(void)
 *   float32 *Rte_Pim_VehSpdPrev(void)
 *   float32 *Rte_Pim_VehSpdRate(void)
 *   float32 *Rte_Pim_dPullCmpActvIntgtrGainShoTerm(void)
 *   float32 *Rte_Pim_dPullCmpActvPullErrLongTerm(void)
 *   float32 *Rte_Pim_dPullCmpActvPullErrShoTerm(void)
 *   uint32 *Rte_Pim_RefTiEnaLrng(void)
 *   uint32 *Rte_Pim_RefTiOpstSign(void)
 *   boolean *Rte_Pim_LrngEnaPrev(void)
 *   boolean *Rte_Pim_LrngEnad(void)
 *   boolean *Rte_Pim_OpstSignPrev(void)
 *   boolean *Rte_Pim_PullCmpActvDi(void)
 *   boolean *Rte_Pim_PullCmpLongTermRst(void)
 *   boolean *Rte_Pim_PullCmpShoTermRst(void)
 *   boolean *Rte_Pim_dPullCmpActvShoTermRst(void)
 *   FilLpRec1 *Rte_Pim_HwTqLpFilLongTerm(void)
 *   FilLpRec1 *Rte_Pim_HwTqLpFilLrngEna(void)
 *   FilLpRec1 *Rte_Pim_HwTqLpFilShoTerm(void)
 *   FilLpRec1 *Rte_Pim_VehYawRateLpFil(void)
 *
 * Calibration Parameters:
 * =======================
 *   SW-C local Calibration Parameters:
 *   ----------------------------------
 *   float32 Rte_CData_PullCmpLongTermDft(void)
 *
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_PullCmpActvCmpLrnTiDecShoTerm_Val(void)
 *   float32 Rte_Prm_PullCmpActvCmpLrnTiIncShoTerm_Val(void)
 *   float32 Rte_Prm_PullCmpActvCmpLrnTiLongTerm_Val(void)
 *   float32 Rte_Prm_PullCmpActvCmpShoTermRstHwAgThd_Val(void)
 *   float32 Rte_Prm_PullCmpActvCmpShoTermRstHwTqThd_Val(void)
 *   float32 Rte_Prm_PullCmpActvCmpShoTermRstLatAThd_Val(void)
 *   float32 Rte_Prm_PullCmpActvCmpShoTermRstYawRateThd_Val(void)
 *   float32 Rte_Prm_PullCmpActvHwTqFilFrqLongTerm_Val(void)
 *   float32 Rte_Prm_PullCmpActvHwTqFilFrqLrngEna_Val(void)
 *   float32 Rte_Prm_PullCmpActvHwTqFilFrqShoTerm_Val(void)
 *   float32 Rte_Prm_PullCmpActvLongTermLim_Val(void)
 *   float32 Rte_Prm_PullCmpActvLrngEnaAgConfMinMgn_Val(void)
 *   float32 Rte_Prm_PullCmpActvLrngEnaHwAgMaxMgn_Val(void)
 *   float32 Rte_Prm_PullCmpActvLrngEnaHwTqMaxMgn_Val(void)
 *   float32 Rte_Prm_PullCmpActvLrngEnaHwVelMaxMgn_Val(void)
 *   float32 Rte_Prm_PullCmpActvLrngEnaLatAMaxMgn_Val(void)
 *   float32 Rte_Prm_PullCmpActvLrngEnaTiThd_Val(void)
 *   float32 Rte_Prm_PullCmpActvLrngEnaVehSpdMaxMgn_Val(void)
 *   float32 Rte_Prm_PullCmpActvLrngEnaVehSpdMinMgn_Val(void)
 *   float32 Rte_Prm_PullCmpActvLrngEnaVehSpdRateMaxMgn_Val(void)
 *   float32 Rte_Prm_PullCmpActvLrngEnaYawRateMaxMgn_Val(void)
 *   float32 Rte_Prm_PullCmpActvOpstSignTiShoTerm_Val(void)
 *   float32 Rte_Prm_PullCmpActvOutpMaxRate_Val(void)
 *   float32 Rte_Prm_PullCmpActvPullCmpShoTermLim_Val(void)
 *   float32 Rte_Prm_PullCmpActvPullCmpTotLim_Val(void)
 *   float32 Rte_Prm_PullCmpActvPullErrLimLongTerm_Val(void)
 *   float32 Rte_Prm_PullCmpActvPullErrMgnThd_Val(void)
 *   float32 Rte_Prm_PullCmpActvPullErrShoTermLim_Val(void)
 *   float32 Rte_Prm_PullCmpActvShoTermRampTi_Val(void)
 *   float32 Rte_Prm_PullCmpActvYawRateFilFrq_Val(void)
 *   float32 Rte_Prm_SysGlbPrmSysTqRat_Val(void)
 *   boolean Rte_Prm_PullCmpActvEna_Logl(void)
 *   u9p7 *Rte_Prm_PullCmpActvVehSpdScaTblX_Ary1D(void)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_4
 *   u2p14 *Rte_Prm_PullCmpActvVehSpdScaTblY_Ary1D(void)
 *     Returnvalue: u2p14* is of type Ary1D_u2p14_4
 *
 *********************************************************************************************************************/


# define PullCmpActv_START_SEC_CODE
# include "PullCmpActv_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: GetPullCmpPrm_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <GetPullCmpPrm>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void GetPullCmpPrm_Oper(float32 *PullCmpCmdTot_Arg, float32 *PullCmpShoTerm_Arg, float32 *PullCmpLongTerm_Arg, boolean *LrngEnad_Arg)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_GetPullCmpPrm_Oper GetPullCmpPrm_Oper
FUNC(void, PullCmpActv_CODE) GetPullCmpPrm_Oper(P2VAR(float32, AUTOMATIC, RTE_PULLCMPACTV_APPL_VAR) PullCmpCmdTot_Arg, P2VAR(float32, AUTOMATIC, RTE_PULLCMPACTV_APPL_VAR) PullCmpShoTerm_Arg, P2VAR(float32, AUTOMATIC, RTE_PULLCMPACTV_APPL_VAR) PullCmpLongTerm_Arg, P2VAR(boolean, AUTOMATIC, RTE_PULLCMPACTV_APPL_VAR) LrngEnad_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PullCmpActvInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Inter Runnable Variables:
 * =========================
 *   Explicit Write Access:
 *   ----------------------
 *   void Rte_IrvWrite_PullCmpActvInit1_RampDwnStepSize(float32 data)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_PullCmpLongTerm_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_PullCmpLongTerm_SetRamBlockStatus(Boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_PullCmpActvInit1 PullCmpActvInit1
FUNC(void, PullCmpActv_CODE) PullCmpActvInit1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PullCmpActvPer1
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
 *   Std_ReturnType Rte_Read_HwTq_Val(float32 *data)
 *   Std_ReturnType Rte_Read_HwVel_Val(float32 *data)
 *   Std_ReturnType Rte_Read_PinionAgConf_Val(float32 *data)
 *   Std_ReturnType Rte_Read_PullCmpActvDi_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_PullCmpCmdDi_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_PullCmpCustLrngDi_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_PullCmpLrngDi_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_VehLatA_Val(float32 *data)
 *   Std_ReturnType Rte_Read_VehSpd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_VehSpdVld_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_VehYawRate_Val(float32 *data)
 *   Std_ReturnType Rte_Read_VehYawRateVld_Logl(boolean *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_PullCmpCmd_Val(float32 data)
 *
 * Inter Runnable Variables:
 * =========================
 *   Explicit Read Access:
 *   ---------------------
 *   float32 Rte_IrvRead_PullCmpActvPer1_RampDwnStepSize(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_FltInj_f32_Oper(float32 *SigPah_Arg, uint16 LocnKey_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_GetRefTmr100MicroSec32bit_Oper(uint32 *RefTmr_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_PullCmpActvPer1 PullCmpActvPer1
FUNC(void, PullCmpActv_CODE) PullCmpActvPer1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PullCmpActvPer2
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 100ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_HwTq_Val(float32 *data)
 *   Std_ReturnType Rte_Read_VehSpd_Val(float32 *data)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_PullCmpActvPer2 PullCmpActvPer2
FUNC(void, PullCmpActv_CODE) PullCmpActvPer2(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RstPullCmp_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <RstPullCmp>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void RstPullCmp_Oper(void)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_RstPullCmp_Oper RstPullCmp_Oper
FUNC(void, PullCmpActv_CODE) RstPullCmp_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SetPullCmpLongTerm_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <SetPullCmpLongTerm>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_PullCmpLongTerm_SetRamBlockStatus(Boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void SetPullCmpLongTerm_Oper(float32 PullCmpLongTerm_Arg)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_SetPullCmpLongTerm_Oper SetPullCmpLongTerm_Oper
FUNC(void, PullCmpActv_CODE) SetPullCmpLongTerm_Oper(float32 PullCmpLongTerm_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SetPullCmpShoTerm_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <SetPullCmpShoTerm>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void SetPullCmpShoTerm_Oper(float32 PullCmpShoTerm_Arg)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_SetPullCmpShoTerm_Oper SetPullCmpShoTerm_Oper
FUNC(void, PullCmpActv_CODE) SetPullCmpShoTerm_Oper(float32 PullCmpShoTerm_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define PullCmpActv_STOP_SEC_CODE
# include "PullCmpActv_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK (1U)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_PULLCMPACTV_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3447:  MISRA rule: 8.8
     Reason:     For the purpose of monitoring during calibration or debugging it is necessary to use non-static declarations.
                 This is covered in the MISRA C compliance section of the Rte specification.
     Risk:       No functional risk.
     Prevention: Not required.

*/

#include "Rte_Stubs.h"
