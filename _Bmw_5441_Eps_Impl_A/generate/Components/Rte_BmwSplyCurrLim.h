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
 *          File:  Rte_BmwSplyCurrLim.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <BmwSplyCurrLim>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_BMWSPLYCURRLIM_H
# define _RTE_BMWSPLYCURRLIM_H

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

# include "Rte_BmwSplyCurrLim_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_Appl9_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_INIT) Rte_BmwSplyCurrLim_SplyCurrLim_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwSplyCurrLim_BmwStrtStopLim_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwSplyCurrLim_BmwStrtStopMsgActv_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwSplyCurrLim_RemCtrlPrkgEna_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_LimrCdng_SysMotTqCmdScaCdnd_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwVehSpd_VehSpd_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_Appl9_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_INIT) Rte_BmwMsgSlot68Bas1Repn2BusFrChA_BmwMaxCurrLimr_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(BmwMaxCurrLimrSts1, RTE_VAR_INIT) Rte_BmwMsgSlot68Bas1Repn2BusFrChA_BmwMaxCurrLimrSts_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BattVltg_BrdgVltg_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwSwFctDi_MaxCurrAtHiSpd_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwSwFctDi_MaxCurrAtLoSpd_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_BmwMaxCurrLimr_Val (120.0F)
#  define Rte_InitValue_BmwMaxCurrLimrSts_Val (4U)
#  define Rte_InitValue_BmwStrtStopLim_Val (120.0F)
#  define Rte_InitValue_BmwStrtStopMsgActv_Logl (FALSE)
#  define Rte_InitValue_BrdgVltg_Val (6.0F)
#  define Rte_InitValue_MaxCurrAtHiSpd_Val (120.0F)
#  define Rte_InitValue_MaxCurrAtLoSpd_Val (120.0F)
#  define Rte_InitValue_RemCtrlPrkgEna_Logl (FALSE)
#  define Rte_InitValue_SplyCurrLim_Val (120.0F)
#  define Rte_InitValue_SysMotTqCmdSca_Val (1.0F)
#  define Rte_InitValue_VehSpd_Val (0.0F)
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_BmwMaxCurrLimr_Val Rte_Read_BmwSplyCurrLim_BmwMaxCurrLimr_Val
#  define Rte_Read_BmwSplyCurrLim_BmwMaxCurrLimr_Val(data) (*(data) = Rte_BmwMsgSlot68Bas1Repn2BusFrChA_BmwMaxCurrLimr_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BmwMaxCurrLimrSts_Val Rte_Read_BmwSplyCurrLim_BmwMaxCurrLimrSts_Val
#  define Rte_Read_BmwSplyCurrLim_BmwMaxCurrLimrSts_Val(data) (*(data) = Rte_BmwMsgSlot68Bas1Repn2BusFrChA_BmwMaxCurrLimrSts_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BmwStrtStopLim_Val Rte_Read_BmwSplyCurrLim_BmwStrtStopLim_Val
#  define Rte_Read_BmwSplyCurrLim_BmwStrtStopLim_Val(data) (*(data) = Rte_BmwSplyCurrLim_BmwStrtStopLim_Val, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BmwStrtStopMsgActv_Logl Rte_Read_BmwSplyCurrLim_BmwStrtStopMsgActv_Logl
#  define Rte_Read_BmwSplyCurrLim_BmwStrtStopMsgActv_Logl(data) (*(data) = Rte_BmwSplyCurrLim_BmwStrtStopMsgActv_Logl, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BrdgVltg_Val Rte_Read_BmwSplyCurrLim_BrdgVltg_Val
#  define Rte_Read_BmwSplyCurrLim_BrdgVltg_Val(data) (*(data) = Rte_BattVltg_BrdgVltg_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MaxCurrAtHiSpd_Val Rte_Read_BmwSplyCurrLim_MaxCurrAtHiSpd_Val
#  define Rte_Read_BmwSplyCurrLim_MaxCurrAtHiSpd_Val(data) (*(data) = Rte_BmwSwFctDi_MaxCurrAtHiSpd_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MaxCurrAtLoSpd_Val Rte_Read_BmwSplyCurrLim_MaxCurrAtLoSpd_Val
#  define Rte_Read_BmwSplyCurrLim_MaxCurrAtLoSpd_Val(data) (*(data) = Rte_BmwSwFctDi_MaxCurrAtLoSpd_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_RemCtrlPrkgEna_Logl Rte_Read_BmwSplyCurrLim_RemCtrlPrkgEna_Logl
#  define Rte_Read_BmwSplyCurrLim_RemCtrlPrkgEna_Logl(data) (*(data) = Rte_BmwSplyCurrLim_RemCtrlPrkgEna_Logl, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_SysMotTqCmdSca_Val Rte_Read_BmwSplyCurrLim_SysMotTqCmdSca_Val
#  define Rte_Read_BmwSplyCurrLim_SysMotTqCmdSca_Val(data) (*(data) = Rte_LimrCdng_SysMotTqCmdScaCdnd_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_VehSpd_Val Rte_Read_BmwSplyCurrLim_VehSpd_Val
#  define Rte_Read_BmwSplyCurrLim_VehSpd_Val(data) (*(data) = Rte_BmwVehSpd_VehSpd_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_SplyCurrLim_Val Rte_Write_BmwSplyCurrLim_SplyCurrLim_Val
#  define Rte_Write_BmwSplyCurrLim_SplyCurrLim_Val(data) (Rte_BmwSplyCurrLim_SplyCurrLim_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_DIAGCMGRPROXYAPPL9_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_DIAGCMGRPROXYAPPL9_APPL_CODE) SetNtcSts9_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DIAGCMGRPROXYAPPL9_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_SetNtcSts_Oper SetNtcSts9_Oper


/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

#  define Rte_Prm_BmwSplyCurrLimBmwMaxCurrLimMax_Val() (((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwSplyCurrLimBmwMaxCurrLimMax_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwSplyCurrLimBmwMaxCurrLimMin_Val() (((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwSplyCurrLimBmwMaxCurrLimMin_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwSplyCurrLimBmwMaxCurrLimrGrdt_Val() (((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwSplyCurrLimBmwMaxCurrLimrGrdt_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwSplyCurrLimEpsCpbyOffs_Val() (((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwSplyCurrLimEpsCpbyOffs_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwSplyCurrLimEpsMaxGrdt_Val() (((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwSplyCurrLimEpsMaxGrdt_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwSplyCurrLimEpsMinGrdt_Val() (((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwSplyCurrLimEpsMinGrdt_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwSplyCurrLimMaxCurrLim_Val() (((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwSplyCurrLimMaxCurrLim_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwSplyCurrLimRemCtrlPrkgLim_Val() (((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwSplyCurrLimRemCtrlPrkgLim_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwSplyCurrLimVltgDptCurrLimFltThd_Val() (((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwSplyCurrLimVltgDptCurrLimFltThd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwSplyCurrLimVrntMaxCurr_Val() (((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwSplyCurrLimVrntMaxCurr_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_BmwSplyCurrLimDegradedVltgMaxCurrX_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwSplyCurrLimDegradedVltgMaxCurrX_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_BmwSplyCurrLimDegradedVltgMaxCurrX_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwSplyCurrLimDegradedVltgMaxCurrX_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_BmwSplyCurrLimDegradedVltgMaxCurrY_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwSplyCurrLimDegradedVltgMaxCurrY_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_BmwSplyCurrLimDegradedVltgMaxCurrY_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwSplyCurrLimDegradedVltgMaxCurrY_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_BmwSplyCurrLimNormVltgMaxCurrX_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwSplyCurrLimNormVltgMaxCurrX_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_BmwSplyCurrLimNormVltgMaxCurrX_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwSplyCurrLimNormVltgMaxCurrX_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_BmwSplyCurrLimNormVltgMaxCurrY_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwSplyCurrLimNormVltgMaxCurrY_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_BmwSplyCurrLimNormVltgMaxCurrY_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwSplyCurrLimNormVltgMaxCurrY_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_BmwSplyCurrLimVehSpdDptCurrLimX_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwSplyCurrLimVehSpdDptCurrLimX_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_BmwSplyCurrLimVehSpdDptCurrLimX_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwSplyCurrLimVehSpdDptCurrLimX_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_BmwSplyCurrLimVehSpdDptCurrLimY_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwSplyCurrLimVehSpdDptCurrLimY_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_BmwSplyCurrLimVehSpdDptCurrLimY_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwSplyCurrLimVehSpdDptCurrLimY_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_BmwSplyCurrLimVltgDptCurrGrdtDecX_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwSplyCurrLimVltgDptCurrGrdtDecX_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_BmwSplyCurrLimVltgDptCurrGrdtDecX_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwSplyCurrLimVltgDptCurrGrdtDecX_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_BmwSplyCurrLimVltgDptCurrGrdtDecY_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwSplyCurrLimVltgDptCurrGrdtDecY_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_BmwSplyCurrLimVltgDptCurrGrdtDecY_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwSplyCurrLimVltgDptCurrGrdtDecY_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_BmwSplyCurrLimVltgDptCurrGrdtIncX_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwSplyCurrLimVltgDptCurrGrdtIncX_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_BmwSplyCurrLimVltgDptCurrGrdtIncX_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwSplyCurrLimVltgDptCurrGrdtIncX_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_BmwSplyCurrLimVltgDptCurrGrdtIncY_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwSplyCurrLimVltgDptCurrGrdtIncY_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_BmwSplyCurrLimVltgDptCurrGrdtIncY_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwSplyCurrLimVltgDptCurrGrdtIncY_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_Appl9_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl9_PIM_GROUP) Rte_BmwSplyCurrLim_BmwMaxCurrLimGrdt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl9_PIM_GROUP) Rte_BmwSplyCurrLim_SplyCurrLimGrdt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl9_PIM_GROUP) Rte_BmwSplyCurrLim_VltgDptCurrLimGrdt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl9_PIM_GROUP) Rte_BmwSplyCurrLim_dBmwSplyCurrLimBmwMaxCurrLim; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl9_PIM_GROUP) Rte_BmwSplyCurrLim_dBmwSplyCurrLimCurrLim; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl9_PIM_GROUP) Rte_BmwSplyCurrLim_dBmwSplyCurrLimCurrLimPrel; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl9_PIM_GROUP) Rte_BmwSplyCurrLim_dBmwSplyCurrLimGlbLim; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl9_PIM_GROUP) Rte_BmwSplyCurrLim_dBmwSplyCurrLimSplyCurrLim; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl9_PIM_GROUP) Rte_BmwSplyCurrLim_dBmwSplyCurrLimVehSpdDptCurrLim; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl9_PIM_GROUP) Rte_BmwSplyCurrLim_dBmwSplyCurrLimVltgDptCurrLim; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Appl9_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  endif

#  define Rte_Pim_BmwMaxCurrLimGrdt() \
  (&Rte_BmwSplyCurrLim_BmwMaxCurrLimGrdt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_SplyCurrLimGrdt() \
  (&Rte_BmwSplyCurrLim_SplyCurrLimGrdt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_VltgDptCurrLimGrdt() \
  (&Rte_BmwSplyCurrLim_VltgDptCurrLimGrdt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dBmwSplyCurrLimBmwMaxCurrLim() \
  (&Rte_BmwSplyCurrLim_dBmwSplyCurrLimBmwMaxCurrLim) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dBmwSplyCurrLimCurrLim() \
  (&Rte_BmwSplyCurrLim_dBmwSplyCurrLimCurrLim) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dBmwSplyCurrLimCurrLimPrel() \
  (&Rte_BmwSplyCurrLim_dBmwSplyCurrLimCurrLimPrel) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dBmwSplyCurrLimGlbLim() \
  (&Rte_BmwSplyCurrLim_dBmwSplyCurrLimGlbLim) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dBmwSplyCurrLimSplyCurrLim() \
  (&Rte_BmwSplyCurrLim_dBmwSplyCurrLimSplyCurrLim) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dBmwSplyCurrLimVehSpdDptCurrLim() \
  (&Rte_BmwSplyCurrLim_dBmwSplyCurrLimVehSpdDptCurrLim) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dBmwSplyCurrLimVltgDptCurrLim() \
  (&Rte_BmwSplyCurrLim_dBmwSplyCurrLimVltgDptCurrLim) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define BmwSplyCurrLim_START_SEC_CODE
# include "BmwSplyCurrLim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_BmwSplyCurrLimInit1 BmwSplyCurrLimInit1
#  define RTE_RUNNABLE_BmwSplyCurrLimPer1 BmwSplyCurrLimPer1
# endif

FUNC(void, BmwSplyCurrLim_CODE) BmwSplyCurrLimInit1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, BmwSplyCurrLim_CODE) BmwSplyCurrLimPer1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define BmwSplyCurrLim_STOP_SEC_CODE
# include "BmwSplyCurrLim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_SetNtcSts_PortIf1_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_BMWSPLYCURRLIM_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
