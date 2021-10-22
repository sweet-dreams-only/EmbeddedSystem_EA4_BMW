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
 *          File:  Rte_BmwHaptcFb.h
 *        Config:  C:/Users/nz2999/Documents/Synergy/ccm_wa/ses_dev_ea4/CF020A_BmwHaptcFb_Impl-nz2999/CF020A_BmwHaptcFb_Impl/tools/Component.dpa
 *     SW-C Type:  BmwHaptcFb
 *  Generated at:  Fri May 18 11:14:55 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <BmwHaptcFb> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_BMWHAPTCFB_H
# define _RTE_BMWHAPTCFB_H

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

# include "Rte_BmwHaptcFb_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_BmwHaptcFb
{
  /* PIM Handles section */
  P2VAR(BmwHaptcFbIntenNr1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_CurrInten; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(BmwHaptcFbPatNr1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_CurrPat; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_TqOscnEnaTmr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_BmwHaptcFb, RTE_CONST, RTE_CONST) Rte_Inst_BmwHaptcFb; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_BmwHaptcFb, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_BmwHaptcFbIntenNr_Val (15U)
# define Rte_InitValue_BmwHaptcFbIntenNrVld_Logl (FALSE)
# define Rte_InitValue_BmwHaptcFbPatNr_Val (15U)
# define Rte_InitValue_BmwHaptcFbPatNrVld_Logl (FALSE)
# define Rte_InitValue_DiagcStsNonRcvrlReqDiFltPrsnt_Logl (FALSE)
# define Rte_InitValue_HaptcFbEna_Logl (TRUE)
# define Rte_InitValue_HaptcFbSt_Val (14U)
# define Rte_InitValue_HwOscnActv_Logl (FALSE)
# define Rte_InitValue_HwOscnDcThdExcdd_Logl (FALSE)
# define Rte_InitValue_HwOscnEna_Logl (FALSE)
# define Rte_InitValue_HwOscnFallRampRate_Val (-4400.0F)
# define Rte_InitValue_HwOscnFrq_Val (50.0F)
# define Rte_InitValue_HwOscnMotAmp_Val (0.0F)
# define Rte_InitValue_HwOscnRisngRampRate_Val (4400.0F)
# define Rte_InitValue_HwTq_Val (0.0F)
# define Rte_InitValue_StsSteerAssi_Val (0U)
# define Rte_InitValue_ThermRednFac_Val (0.0F)
# define Rte_InitValue_VehSpd_Val (0.0F)
# define Rte_InitValue_VehSpdVld_Logl (FALSE)


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwHaptcFb_BmwHaptcFbIntenNr_Val(P2VAR(BmwHaptcFbIntenNr1, AUTOMATIC, RTE_BMWHAPTCFB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwHaptcFb_BmwHaptcFbIntenNrVld_Logl(P2VAR(boolean, AUTOMATIC, RTE_BMWHAPTCFB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwHaptcFb_BmwHaptcFbPatNr_Val(P2VAR(BmwHaptcFbPatNr1, AUTOMATIC, RTE_BMWHAPTCFB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwHaptcFb_BmwHaptcFbPatNrVld_Logl(P2VAR(boolean, AUTOMATIC, RTE_BMWHAPTCFB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwHaptcFb_DiagcStsNonRcvrlReqDiFltPrsnt_Logl(P2VAR(boolean, AUTOMATIC, RTE_BMWHAPTCFB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwHaptcFb_HaptcFbEna_Logl(P2VAR(boolean, AUTOMATIC, RTE_BMWHAPTCFB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwHaptcFb_HwOscnActv_Logl(P2VAR(boolean, AUTOMATIC, RTE_BMWHAPTCFB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwHaptcFb_HwOscnDcThdExcdd_Logl(P2VAR(boolean, AUTOMATIC, RTE_BMWHAPTCFB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwHaptcFb_HwTq_Val(P2VAR(float32, AUTOMATIC, RTE_BMWHAPTCFB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwHaptcFb_StsSteerAssi_Val(P2VAR(StsSteerAssi1, AUTOMATIC, RTE_BMWHAPTCFB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwHaptcFb_ThermRednFac_Val(P2VAR(float32, AUTOMATIC, RTE_BMWHAPTCFB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwHaptcFb_VehSpd_Val(P2VAR(float32, AUTOMATIC, RTE_BMWHAPTCFB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwHaptcFb_VehSpdVld_Logl(P2VAR(boolean, AUTOMATIC, RTE_BMWHAPTCFB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwHaptcFb_HaptcFbSt_Val(HaptcFbSt1 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwHaptcFb_HwOscnEna_Logl(boolean data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwHaptcFb_HwOscnFallRampRate_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwHaptcFb_HwOscnFrq_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwHaptcFb_HwOscnMotAmp_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwHaptcFb_HwOscnRisngRampRate_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwHaptcFb_GetRefTmr100MicroSec32bit_Oper(P2VAR(uint32, AUTOMATIC, RTE_BMWHAPTCFB_APPL_VAR) RefTmr_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwHaptcFb_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, P2VAR(uint32, AUTOMATIC, RTE_BMWHAPTCFB_APPL_VAR) TiSpan_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_BmwHaptcFb_BmwHaptcFbEpsDegradedFltThd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u4p12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwHaptcFb_BmwHaptcFbAmpAndIntenHwTqTblX_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u4p12_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwHaptcFb_BmwHaptcFbAmpAndIntenHwTqTblX_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u4p12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwHaptcFb_BmwHaptcFbAmpBilnrSeln_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u4p12_13, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwHaptcFb_BmwHaptcFbAmpBilnrSeln_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u4p12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwHaptcFb_BmwHaptcFbAmpSelnTblY_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary2D_u4p12_13_13, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwHaptcFb_BmwHaptcFbAmpSelnTblY_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u6p10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwHaptcFb_BmwHaptcFbFrqBilnrSeln_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u6p10_13, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwHaptcFb_BmwHaptcFbFrqBilnrSeln_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u6p10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwHaptcFb_BmwHaptcFbFrqSelnTblY_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary2D_u6p10_13_13, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwHaptcFb_BmwHaptcFbFrqSelnTblY_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u6p10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwHaptcFb_BmwHaptcFbHwTqFrqTblY_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary2D_u6p10_12_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwHaptcFb_BmwHaptcFbHwTqFrqTblY_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(uint16, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwHaptcFb_BmwHaptcFbIntenSelnTblX_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u16_13, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwHaptcFb_BmwHaptcFbIntenSelnTblX_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u4p12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwHaptcFb_BmwHaptcFbMotTqAmpTblY_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary2D_u4p12_12_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwHaptcFb_BmwHaptcFbMotTqAmpTblY_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(float32, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwHaptcFb_BmwHaptcFbPatActvTiTblY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_f32_11, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwHaptcFb_BmwHaptcFbPatActvTiTblY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(float32, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwHaptcFb_BmwHaptcFbPatPasTiTblY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_f32_11, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwHaptcFb_BmwHaptcFbPatPasTiTblY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(float32, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwHaptcFb_BmwHaptcFbPatRisngSlewTblY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_f32_11, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwHaptcFb_BmwHaptcFbPatRisngSlewTblY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u9p7, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwHaptcFb_SysGlbPrmVehSpdBilnrSeln_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u9p7_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwHaptcFb_SysGlbPrmVehSpdBilnrSeln_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_BmwHaptcFbIntenNr_Val Rte_Read_BmwHaptcFb_BmwHaptcFbIntenNr_Val
# define Rte_Read_BmwHaptcFbIntenNrVld_Logl Rte_Read_BmwHaptcFb_BmwHaptcFbIntenNrVld_Logl
# define Rte_Read_BmwHaptcFbPatNr_Val Rte_Read_BmwHaptcFb_BmwHaptcFbPatNr_Val
# define Rte_Read_BmwHaptcFbPatNrVld_Logl Rte_Read_BmwHaptcFb_BmwHaptcFbPatNrVld_Logl
# define Rte_Read_DiagcStsNonRcvrlReqDiFltPrsnt_Logl Rte_Read_BmwHaptcFb_DiagcStsNonRcvrlReqDiFltPrsnt_Logl
# define Rte_Read_HaptcFbEna_Logl Rte_Read_BmwHaptcFb_HaptcFbEna_Logl
# define Rte_Read_HwOscnActv_Logl Rte_Read_BmwHaptcFb_HwOscnActv_Logl
# define Rte_Read_HwOscnDcThdExcdd_Logl Rte_Read_BmwHaptcFb_HwOscnDcThdExcdd_Logl
# define Rte_Read_HwTq_Val Rte_Read_BmwHaptcFb_HwTq_Val
# define Rte_Read_StsSteerAssi_Val Rte_Read_BmwHaptcFb_StsSteerAssi_Val
# define Rte_Read_ThermRednFac_Val Rte_Read_BmwHaptcFb_ThermRednFac_Val
# define Rte_Read_VehSpd_Val Rte_Read_BmwHaptcFb_VehSpd_Val
# define Rte_Read_VehSpdVld_Logl Rte_Read_BmwHaptcFb_VehSpdVld_Logl


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_HaptcFbSt_Val Rte_Write_BmwHaptcFb_HaptcFbSt_Val
# define Rte_Write_HwOscnEna_Logl Rte_Write_BmwHaptcFb_HwOscnEna_Logl
# define Rte_Write_HwOscnFallRampRate_Val Rte_Write_BmwHaptcFb_HwOscnFallRampRate_Val
# define Rte_Write_HwOscnFrq_Val Rte_Write_BmwHaptcFb_HwOscnFrq_Val
# define Rte_Write_HwOscnMotAmp_Val Rte_Write_BmwHaptcFb_HwOscnMotAmp_Val
# define Rte_Write_HwOscnRisngRampRate_Val Rte_Write_BmwHaptcFb_HwOscnRisngRampRate_Val


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_GetRefTmr100MicroSec32bit_Oper Rte_Call_BmwHaptcFb_GetRefTmr100MicroSec32bit_Oper
# define Rte_Call_GetTiSpan100MicroSec32bit_Oper Rte_Call_BmwHaptcFb_GetTiSpan100MicroSec32bit_Oper


/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

# define Rte_Prm_BmwHaptcFbEpsDegradedFltThd_Val Rte_Prm_BmwHaptcFb_BmwHaptcFbEpsDegradedFltThd_Val

# define Rte_Prm_BmwHaptcFbAmpAndIntenHwTqTblX_Ary1D Rte_Prm_BmwHaptcFb_BmwHaptcFbAmpAndIntenHwTqTblX_Ary1D

# define Rte_Prm_BmwHaptcFbAmpBilnrSeln_Ary1D Rte_Prm_BmwHaptcFb_BmwHaptcFbAmpBilnrSeln_Ary1D

# define Rte_Prm_BmwHaptcFbAmpSelnTblY_Ary2D Rte_Prm_BmwHaptcFb_BmwHaptcFbAmpSelnTblY_Ary2D

# define Rte_Prm_BmwHaptcFbFrqBilnrSeln_Ary1D Rte_Prm_BmwHaptcFb_BmwHaptcFbFrqBilnrSeln_Ary1D

# define Rte_Prm_BmwHaptcFbFrqSelnTblY_Ary2D Rte_Prm_BmwHaptcFb_BmwHaptcFbFrqSelnTblY_Ary2D

# define Rte_Prm_BmwHaptcFbHwTqFrqTblY_Ary2D Rte_Prm_BmwHaptcFb_BmwHaptcFbHwTqFrqTblY_Ary2D

# define Rte_Prm_BmwHaptcFbIntenSelnTblX_Ary1D Rte_Prm_BmwHaptcFb_BmwHaptcFbIntenSelnTblX_Ary1D

# define Rte_Prm_BmwHaptcFbMotTqAmpTblY_Ary2D Rte_Prm_BmwHaptcFb_BmwHaptcFbMotTqAmpTblY_Ary2D

# define Rte_Prm_BmwHaptcFbPatActvTiTblY_Ary1D Rte_Prm_BmwHaptcFb_BmwHaptcFbPatActvTiTblY_Ary1D

# define Rte_Prm_BmwHaptcFbPatPasTiTblY_Ary1D Rte_Prm_BmwHaptcFb_BmwHaptcFbPatPasTiTblY_Ary1D

# define Rte_Prm_BmwHaptcFbPatRisngSlewTblY_Ary1D Rte_Prm_BmwHaptcFb_BmwHaptcFbPatRisngSlewTblY_Ary1D

# define Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D Rte_Prm_BmwHaptcFb_SysGlbPrmVehSpdBilnrSeln_Ary1D

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_TqOscnEnaTmr() (Rte_Inst_BmwHaptcFb->Pim_TqOscnEnaTmr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_CurrInten() (Rte_Inst_BmwHaptcFb->Pim_CurrInten) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_CurrPat() (Rte_Inst_BmwHaptcFb->Pim_CurrPat) /* PRQA S 3453 */ /* MD_MSR_19.7 */




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   uint32 *Rte_Pim_TqOscnEnaTmr(void)
 *   BmwHaptcFbIntenNr1 *Rte_Pim_CurrInten(void)
 *   BmwHaptcFbPatNr1 *Rte_Pim_CurrPat(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_BmwHaptcFbEpsDegradedFltThd_Val(void)
 *   u4p12 *Rte_Prm_BmwHaptcFbAmpAndIntenHwTqTblX_Ary1D(void)
 *     Returnvalue: u4p12* is of type Ary1D_u4p12_12
 *   u4p12 *Rte_Prm_BmwHaptcFbAmpBilnrSeln_Ary1D(void)
 *     Returnvalue: u4p12* is of type Ary1D_u4p12_13
 *   u4p12 *Rte_Prm_BmwHaptcFbAmpSelnTblY_Ary2D(void)
 *     Returnvalue: u4p12* is of type Ary2D_u4p12_13_13
 *   u6p10 *Rte_Prm_BmwHaptcFbFrqBilnrSeln_Ary1D(void)
 *     Returnvalue: u6p10* is of type Ary1D_u6p10_13
 *   u6p10 *Rte_Prm_BmwHaptcFbFrqSelnTblY_Ary2D(void)
 *     Returnvalue: u6p10* is of type Ary2D_u6p10_13_13
 *   u6p10 *Rte_Prm_BmwHaptcFbHwTqFrqTblY_Ary2D(void)
 *     Returnvalue: u6p10* is of type Ary2D_u6p10_12_12
 *   uint16 *Rte_Prm_BmwHaptcFbIntenSelnTblX_Ary1D(void)
 *     Returnvalue: uint16* is of type Ary1D_u16_13
 *   u4p12 *Rte_Prm_BmwHaptcFbMotTqAmpTblY_Ary2D(void)
 *     Returnvalue: u4p12* is of type Ary2D_u4p12_12_12
 *   float32 *Rte_Prm_BmwHaptcFbPatActvTiTblY_Ary1D(void)
 *     Returnvalue: float32* is of type Ary1D_f32_11
 *   float32 *Rte_Prm_BmwHaptcFbPatPasTiTblY_Ary1D(void)
 *     Returnvalue: float32* is of type Ary1D_f32_11
 *   float32 *Rte_Prm_BmwHaptcFbPatRisngSlewTblY_Ary1D(void)
 *     Returnvalue: float32* is of type Ary1D_f32_11
 *   u9p7 *Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D(void)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_12
 *
 *********************************************************************************************************************/


# define BmwHaptcFb_START_SEC_CODE
# include "BmwHaptcFb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwHaptcFbInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_BmwHaptcFbInit1 BmwHaptcFbInit1
FUNC(void, BmwHaptcFb_CODE) BmwHaptcFbInit1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwHaptcFbPer1
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
 *   Std_ReturnType Rte_Read_BmwHaptcFbIntenNr_Val(BmwHaptcFbIntenNr1 *data)
 *   Std_ReturnType Rte_Read_BmwHaptcFbIntenNrVld_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_BmwHaptcFbPatNr_Val(BmwHaptcFbPatNr1 *data)
 *   Std_ReturnType Rte_Read_BmwHaptcFbPatNrVld_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_DiagcStsNonRcvrlReqDiFltPrsnt_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_HaptcFbEna_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_HwOscnActv_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_HwOscnDcThdExcdd_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_HwTq_Val(float32 *data)
 *   Std_ReturnType Rte_Read_StsSteerAssi_Val(StsSteerAssi1 *data)
 *   Std_ReturnType Rte_Read_ThermRednFac_Val(float32 *data)
 *   Std_ReturnType Rte_Read_VehSpd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_VehSpdVld_Logl(boolean *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_HaptcFbSt_Val(HaptcFbSt1 data)
 *   Std_ReturnType Rte_Write_HwOscnEna_Logl(boolean data)
 *   Std_ReturnType Rte_Write_HwOscnFallRampRate_Val(float32 data)
 *   Std_ReturnType Rte_Write_HwOscnFrq_Val(float32 data)
 *   Std_ReturnType Rte_Write_HwOscnMotAmp_Val(float32 data)
 *   Std_ReturnType Rte_Write_HwOscnRisngRampRate_Val(float32 data)
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

# define RTE_RUNNABLE_BmwHaptcFbPer1 BmwHaptcFbPer1
FUNC(void, BmwHaptcFb_CODE) BmwHaptcFbPer1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define BmwHaptcFb_STOP_SEC_CODE
# include "BmwHaptcFb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_BMWHAPTCFB_H */

#include "Rte_Stubs.h"
