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
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <BmwHaptcFb>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_BMWHAPTCFB_H
# define _RTE_BMWHAPTCFB_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
#  ifndef RTE_PTR2ARRAYBASETYPE_PASSING
#   define RTE_PTR2ARRAYBASETYPE_PASSING
#  endif
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_BmwHaptcFb_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_Appl7_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(HaptcFbSt1, RTE_VAR_INIT) Rte_BmwHaptcFb_HaptcFbSt_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwHaptcFb_HwOscnEna_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwHaptcFb_HwOscnFallRampRate_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwHaptcFb_HwOscnFrq_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwHaptcFb_HwOscnMotAmp_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwHaptcFb_HwOscnRisngRampRate_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_DutyCycThermProtn_ThermRednFac_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_Appl7_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_Appl9_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_INIT) Rte_BmwVehSpd_VehSpd_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwVehSpd_VehSpdVld_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_Appl9_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(BmwHaptcFbIntenNr1, RTE_VAR_INIT) Rte_BmwMsgSlot269Bas2Repn4BusFrChA_BmwHaptcFbIntenNr_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwMsgSlot269Bas2Repn4BusFrChA_BmwHaptcFbIntenNrVld_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(BmwHaptcFbPatNr1, RTE_VAR_INIT) Rte_BmwMsgSlot269Bas2Repn4BusFrChA_BmwHaptcFbPatNr_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwMsgSlot269Bas2Repn4BusFrChA_BmwHaptcFbPatNrVld_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_DiagcMgr_DiagcStsNonRcvrlReqDiFltPrsnt_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwSwFctDi_HaptcFbEna_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_TqOscn_HwOscnActv_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_TqOscn_HwOscnDcThdExcdd_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_HwTqArbn_HwTq_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(StsSteerAssi1, RTE_VAR_INIT) Rte_BmwStReqMgr_StsSteerAssi_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_BmwHaptcFbIntenNr_Val (15U)
#  define Rte_InitValue_BmwHaptcFbIntenNrVld_Logl (FALSE)
#  define Rte_InitValue_BmwHaptcFbPatNr_Val (15U)
#  define Rte_InitValue_BmwHaptcFbPatNrVld_Logl (FALSE)
#  define Rte_InitValue_DiagcStsNonRcvrlReqDiFltPrsnt_Logl (FALSE)
#  define Rte_InitValue_HaptcFbEna_Logl (TRUE)
#  define Rte_InitValue_HaptcFbSt_Val (14U)
#  define Rte_InitValue_HwOscnActv_Logl (FALSE)
#  define Rte_InitValue_HwOscnDcThdExcdd_Logl (FALSE)
#  define Rte_InitValue_HwOscnEna_Logl (FALSE)
#  define Rte_InitValue_HwOscnFallRampRate_Val (-4400.0F)
#  define Rte_InitValue_HwOscnFrq_Val (50.0F)
#  define Rte_InitValue_HwOscnMotAmp_Val (0.0F)
#  define Rte_InitValue_HwOscnRisngRampRate_Val (4400.0F)
#  define Rte_InitValue_HwTq_Val (0.0F)
#  define Rte_InitValue_StsSteerAssi_Val (0U)
#  define Rte_InitValue_ThermRednFac_Val (0.0F)
#  define Rte_InitValue_VehSpd_Val (0.0F)
#  define Rte_InitValue_VehSpdVld_Logl (FALSE)
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_BmwHaptcFbIntenNr_Val Rte_Read_BmwHaptcFb_BmwHaptcFbIntenNr_Val
#  define Rte_Read_BmwHaptcFb_BmwHaptcFbIntenNr_Val(data) (*(data) = Rte_BmwMsgSlot269Bas2Repn4BusFrChA_BmwHaptcFbIntenNr_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BmwHaptcFbIntenNrVld_Logl Rte_Read_BmwHaptcFb_BmwHaptcFbIntenNrVld_Logl
#  define Rte_Read_BmwHaptcFb_BmwHaptcFbIntenNrVld_Logl(data) (*(data) = Rte_BmwMsgSlot269Bas2Repn4BusFrChA_BmwHaptcFbIntenNrVld_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BmwHaptcFbPatNr_Val Rte_Read_BmwHaptcFb_BmwHaptcFbPatNr_Val
#  define Rte_Read_BmwHaptcFb_BmwHaptcFbPatNr_Val(data) (*(data) = Rte_BmwMsgSlot269Bas2Repn4BusFrChA_BmwHaptcFbPatNr_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BmwHaptcFbPatNrVld_Logl Rte_Read_BmwHaptcFb_BmwHaptcFbPatNrVld_Logl
#  define Rte_Read_BmwHaptcFb_BmwHaptcFbPatNrVld_Logl(data) (*(data) = Rte_BmwMsgSlot269Bas2Repn4BusFrChA_BmwHaptcFbPatNrVld_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_DiagcStsNonRcvrlReqDiFltPrsnt_Logl Rte_Read_BmwHaptcFb_DiagcStsNonRcvrlReqDiFltPrsnt_Logl
#  define Rte_Read_BmwHaptcFb_DiagcStsNonRcvrlReqDiFltPrsnt_Logl(data) (*(data) = Rte_DiagcMgr_DiagcStsNonRcvrlReqDiFltPrsnt_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_HaptcFbEna_Logl Rte_Read_BmwHaptcFb_HaptcFbEna_Logl
#  define Rte_Read_BmwHaptcFb_HaptcFbEna_Logl(data) (*(data) = Rte_BmwSwFctDi_HaptcFbEna_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_HwOscnActv_Logl Rte_Read_BmwHaptcFb_HwOscnActv_Logl
#  define Rte_Read_BmwHaptcFb_HwOscnActv_Logl(data) (*(data) = Rte_TqOscn_HwOscnActv_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_HwOscnDcThdExcdd_Logl Rte_Read_BmwHaptcFb_HwOscnDcThdExcdd_Logl
#  define Rte_Read_BmwHaptcFb_HwOscnDcThdExcdd_Logl(data) (*(data) = Rte_TqOscn_HwOscnDcThdExcdd_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_HwTq_Val Rte_Read_BmwHaptcFb_HwTq_Val
#  define Rte_Read_BmwHaptcFb_HwTq_Val(data) (*(data) = Rte_HwTqArbn_HwTq_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_StsSteerAssi_Val Rte_Read_BmwHaptcFb_StsSteerAssi_Val
#  define Rte_Read_BmwHaptcFb_StsSteerAssi_Val(data) (*(data) = Rte_BmwStReqMgr_StsSteerAssi_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_ThermRednFac_Val Rte_Read_BmwHaptcFb_ThermRednFac_Val
#  define Rte_Read_BmwHaptcFb_ThermRednFac_Val(data) (*(data) = Rte_DutyCycThermProtn_ThermRednFac_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_VehSpd_Val Rte_Read_BmwHaptcFb_VehSpd_Val
#  define Rte_Read_BmwHaptcFb_VehSpd_Val(data) (*(data) = Rte_BmwVehSpd_VehSpd_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_VehSpdVld_Logl Rte_Read_BmwHaptcFb_VehSpdVld_Logl
#  define Rte_Read_BmwHaptcFb_VehSpdVld_Logl(data) (*(data) = Rte_BmwVehSpd_VehSpdVld_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_HaptcFbSt_Val Rte_Write_BmwHaptcFb_HaptcFbSt_Val
#  define Rte_Write_BmwHaptcFb_HaptcFbSt_Val(data) (Rte_BmwHaptcFb_HaptcFbSt_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_HwOscnEna_Logl Rte_Write_BmwHaptcFb_HwOscnEna_Logl
#  define Rte_Write_BmwHaptcFb_HwOscnEna_Logl(data) (Rte_BmwHaptcFb_HwOscnEna_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_HwOscnFallRampRate_Val Rte_Write_BmwHaptcFb_HwOscnFallRampRate_Val
#  define Rte_Write_BmwHaptcFb_HwOscnFallRampRate_Val(data) (Rte_BmwHaptcFb_HwOscnFallRampRate_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_HwOscnFrq_Val Rte_Write_BmwHaptcFb_HwOscnFrq_Val
#  define Rte_Write_BmwHaptcFb_HwOscnFrq_Val(data) (Rte_BmwHaptcFb_HwOscnFrq_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_HwOscnMotAmp_Val Rte_Write_BmwHaptcFb_HwOscnMotAmp_Val
#  define Rte_Write_BmwHaptcFb_HwOscnMotAmp_Val(data) (Rte_BmwHaptcFb_HwOscnMotAmp_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_HwOscnRisngRampRate_Val Rte_Write_BmwHaptcFb_HwOscnRisngRampRate_Val
#  define Rte_Write_BmwHaptcFb_HwOscnRisngRampRate_Val(data) (Rte_BmwHaptcFb_HwOscnRisngRampRate_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_CDD_NXTRTI_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_CDD_NXTRTI_APPL_CODE) GetRefTmr100MicroSec32bit_Oper(P2VAR(uint32, AUTOMATIC, RTE_CDD_NXTRTI_APPL_VAR) RefTmr_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CDD_NXTRTI_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_GetRefTmr100MicroSec32bit_Oper(arg1) (GetRefTmr100MicroSec32bit_Oper(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_CDD_NXTRTI_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_CDD_NXTRTI_APPL_CODE) GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, P2VAR(uint32, AUTOMATIC, RTE_CDD_NXTRTI_APPL_VAR) TiSpan_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CDD_NXTRTI_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_GetTiSpan100MicroSec32bit_Oper(arg1, arg2) (GetTiSpan100MicroSec32bit_Oper(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

#  define Rte_Prm_BmwHaptcFbEpsDegradedFltThd_Val() (((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwHaptcFbEpsDegradedFltThd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_BmwHaptcFbAmpAndIntenHwTqTblX_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwHaptcFbAmpAndIntenHwTqTblX_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_BmwHaptcFbAmpAndIntenHwTqTblX_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwHaptcFbAmpAndIntenHwTqTblX_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_BmwHaptcFbAmpBilnrSeln_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwHaptcFbAmpBilnrSeln_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_BmwHaptcFbAmpBilnrSeln_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwHaptcFbAmpBilnrSeln_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_BmwHaptcFbAmpSelnTblY_Ary2D() ((P2CONST(u4p12, AUTOMATIC, RTE_VAR_NOINIT)) &(((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwHaptcFbAmpSelnTblY_Ary2D[0][0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_BmwHaptcFbAmpSelnTblY_Ary2D() (&((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwHaptcFbAmpSelnTblY_Ary2D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_BmwHaptcFbFrqBilnrSeln_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwHaptcFbFrqBilnrSeln_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_BmwHaptcFbFrqBilnrSeln_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwHaptcFbFrqBilnrSeln_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_BmwHaptcFbFrqSelnTblY_Ary2D() ((P2CONST(u6p10, AUTOMATIC, RTE_VAR_NOINIT)) &(((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwHaptcFbFrqSelnTblY_Ary2D[0][0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_BmwHaptcFbFrqSelnTblY_Ary2D() (&((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwHaptcFbFrqSelnTblY_Ary2D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_BmwHaptcFbHwTqFrqTblY_Ary2D() ((P2CONST(u6p10, AUTOMATIC, RTE_VAR_NOINIT)) &(((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwHaptcFbHwTqFrqTblY_Ary2D[0][0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_BmwHaptcFbHwTqFrqTblY_Ary2D() (&((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwHaptcFbHwTqFrqTblY_Ary2D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_BmwHaptcFbIntenSelnTblX_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwHaptcFbIntenSelnTblX_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_BmwHaptcFbIntenSelnTblX_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwHaptcFbIntenSelnTblX_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_BmwHaptcFbMotTqAmpTblY_Ary2D() ((P2CONST(u4p12, AUTOMATIC, RTE_VAR_NOINIT)) &(((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwHaptcFbMotTqAmpTblY_Ary2D[0][0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_BmwHaptcFbMotTqAmpTblY_Ary2D() (&((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwHaptcFbMotTqAmpTblY_Ary2D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_BmwHaptcFbPatActvTiTblY_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwHaptcFbPatActvTiTblY_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_BmwHaptcFbPatActvTiTblY_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwHaptcFbPatActvTiTblY_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_BmwHaptcFbPatPasTiTblY_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwHaptcFbPatPasTiTblY_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_BmwHaptcFbPatPasTiTblY_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwHaptcFbPatPasTiTblY_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_BmwHaptcFbPatRisngSlewTblY_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwHaptcFbPatRisngSlewTblY_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_BmwHaptcFbPatRisngSlewTblY_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwHaptcFbPatRisngSlewTblY_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn01Inin00_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00_DEFAULT_RTE_CALPRM_GROUP])->SysGlbPrmVehSpdBilnrSeln_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn01Inin00_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00_DEFAULT_RTE_CALPRM_GROUP])->SysGlbPrmVehSpdBilnrSeln_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_Appl7_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_BmwHaptcFb_TqOscnEnaTmr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(BmwHaptcFbIntenNr1, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_BmwHaptcFb_CurrInten; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(BmwHaptcFbPatNr1, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_BmwHaptcFb_CurrPat; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Appl7_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  endif

#  define Rte_Pim_TqOscnEnaTmr() \
  (&Rte_BmwHaptcFb_TqOscnEnaTmr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_CurrInten() \
  (&Rte_BmwHaptcFb_CurrInten) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_CurrPat() \
  (&Rte_BmwHaptcFb_CurrPat) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define BmwHaptcFb_START_SEC_CODE
# include "BmwHaptcFb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_BmwHaptcFbInit1 BmwHaptcFbInit1
#  define RTE_RUNNABLE_BmwHaptcFbPer1 BmwHaptcFbPer1
# endif

FUNC(void, BmwHaptcFb_CODE) BmwHaptcFbInit1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, BmwHaptcFb_CODE) BmwHaptcFbPer1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define BmwHaptcFb_STOP_SEC_CODE
# include "BmwHaptcFb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_BMWHAPTCFB_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
