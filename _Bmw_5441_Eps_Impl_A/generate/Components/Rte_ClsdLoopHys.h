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
 *          File:  Rte_ClsdLoopHys.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <ClsdLoopHys>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CLSDLOOPHYS_H
# define _RTE_CLSDLOOPHYS_H

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

# include "Rte_ClsdLoopHys_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_Appl7_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_INIT) Rte_ClsdLoopHys_HwTqCmdHys_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_Effort_HwTqCmdEffort_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_SysKineAndEff_HwVel_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_EpsStEstimn_RackFEstimd_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_Appl7_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_Appl9_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_INIT) Rte_BmwVehSpd_VehSpd_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_Appl9_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_INIT) Rte_BmwHwAgArbnAndEotPosn_PinionAg_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_HwTqArbn_HwTq_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_SysFricLrng_SysFricOffs_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_HwAg_Val (0.0F)
#  define Rte_InitValue_HwTq_Val (0.0F)
#  define Rte_InitValue_HwTqCmdEffort_Val (0.0F)
#  define Rte_InitValue_HwTqCmdHys_Val (0.0F)
#  define Rte_InitValue_HwVel_Val (0.0F)
#  define Rte_InitValue_RackFEstimd_Val (0.0F)
#  define Rte_InitValue_SysFricOffs_Val (0.0F)
#  define Rte_InitValue_VehSpd_Val (0.0F)
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_HwAg_Val Rte_Read_ClsdLoopHys_HwAg_Val
#  define Rte_Read_ClsdLoopHys_HwAg_Val(data) (*(data) = Rte_BmwHwAgArbnAndEotPosn_PinionAg_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_HwTq_Val Rte_Read_ClsdLoopHys_HwTq_Val
#  define Rte_Read_ClsdLoopHys_HwTq_Val(data) (*(data) = Rte_HwTqArbn_HwTq_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_HwTqCmdEffort_Val Rte_Read_ClsdLoopHys_HwTqCmdEffort_Val
#  define Rte_Read_ClsdLoopHys_HwTqCmdEffort_Val(data) (*(data) = Rte_Effort_HwTqCmdEffort_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_HwVel_Val Rte_Read_ClsdLoopHys_HwVel_Val
#  define Rte_Read_ClsdLoopHys_HwVel_Val(data) (*(data) = Rte_SysKineAndEff_HwVel_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_RackFEstimd_Val Rte_Read_ClsdLoopHys_RackFEstimd_Val
#  define Rte_Read_ClsdLoopHys_RackFEstimd_Val(data) (*(data) = Rte_EpsStEstimn_RackFEstimd_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_SysFricOffs_Val Rte_Read_ClsdLoopHys_SysFricOffs_Val
#  define Rte_Read_ClsdLoopHys_SysFricOffs_Val(data) (*(data) = Rte_SysFricLrng_SysFricOffs_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_VehSpd_Val Rte_Read_ClsdLoopHys_VehSpd_Val
#  define Rte_Read_ClsdLoopHys_VehSpd_Val(data) (*(data) = Rte_BmwVehSpd_VehSpd_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_HwTqCmdHys_Val Rte_Write_ClsdLoopHys_HwTqCmdHys_Val
#  define Rte_Write_ClsdLoopHys_HwTqCmdHys_Val(data) (Rte_ClsdLoopHys_HwTqCmdHys_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

#  define Rte_Prm_ClsdLoopHysHwAgBlndFac_Val() (((P2CONST(Rte_Calprm_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP])->ClsdLoopHysHwAgBlndFac_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_ClsdLoopHysPolarity_Val() (((P2CONST(Rte_Calprm_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP])->ClsdLoopHysPolarity_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_ClsdLoopHysSteerInHwAgNegLowrLim_Val() (((P2CONST(Rte_Calprm_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP])->ClsdLoopHysSteerInHwAgNegLowrLim_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_ClsdLoopHysSteerInHwAgNegUpprLim_Val() (((P2CONST(Rte_Calprm_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP])->ClsdLoopHysSteerInHwAgNegUpprLim_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_ClsdLoopHysSteerInHwAgPosLowrLim_Val() (((P2CONST(Rte_Calprm_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP])->ClsdLoopHysSteerInHwAgPosLowrLim_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_ClsdLoopHysSteerInHwAgPosUpprLim_Val() (((P2CONST(Rte_Calprm_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP])->ClsdLoopHysSteerInHwAgPosUpprLim_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_ClsdLoopHysSteerOutHwAgNegLowrLim_Val() (((P2CONST(Rte_Calprm_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP])->ClsdLoopHysSteerOutHwAgNegLowrLim_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_ClsdLoopHysSteerOutHwAgNegUpprLim_Val() (((P2CONST(Rte_Calprm_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP])->ClsdLoopHysSteerOutHwAgNegUpprLim_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_ClsdLoopHysSteerOutHwAgPosLowrLim_Val() (((P2CONST(Rte_Calprm_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP])->ClsdLoopHysSteerOutHwAgPosLowrLim_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_ClsdLoopHysSteerOutHwAgPosUpprLim_Val() (((P2CONST(Rte_Calprm_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP])->ClsdLoopHysSteerOutHwAgPosUpprLim_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_ClsdLoopHysDeltaY_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP])->ClsdLoopHysDeltaY_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_ClsdLoopHysDeltaY_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP])->ClsdLoopHysDeltaY_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_ClsdLoopHysGainY_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP])->ClsdLoopHysGainY_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_ClsdLoopHysGainY_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP])->ClsdLoopHysGainY_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_ClsdLoopHysHwAgQuadBlndX_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP])->ClsdLoopHysHwAgQuadBlndX_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_ClsdLoopHysHwAgQuadBlndX_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP])->ClsdLoopHysHwAgQuadBlndX_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_ClsdLoopHysHwAgQuadBlndY_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP])->ClsdLoopHysHwAgQuadBlndY_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_ClsdLoopHysHwAgQuadBlndY_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP])->ClsdLoopHysHwAgQuadBlndY_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_ClsdLoopHysHwAgQuadQlfrX_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP])->ClsdLoopHysHwAgQuadQlfrX_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_ClsdLoopHysHwAgQuadQlfrX_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP])->ClsdLoopHysHwAgQuadQlfrX_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_ClsdLoopHysHwAgQuadQlfrY_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP])->ClsdLoopHysHwAgQuadQlfrY_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_ClsdLoopHysHwAgQuadQlfrY_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP])->ClsdLoopHysHwAgQuadQlfrY_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_ClsdLoopHysHwVelQuadBlndX_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP])->ClsdLoopHysHwVelQuadBlndX_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_ClsdLoopHysHwVelQuadBlndX_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP])->ClsdLoopHysHwVelQuadBlndX_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_ClsdLoopHysHwVelQuadBlndY_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP])->ClsdLoopHysHwVelQuadBlndY_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_ClsdLoopHysHwVelQuadBlndY_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP])->ClsdLoopHysHwVelQuadBlndY_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_ClsdLoopHysRackFFacX_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP])->ClsdLoopHysRackFFacX_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_ClsdLoopHysRackFFacX_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP])->ClsdLoopHysRackFFacX_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_ClsdLoopHysRackFFacY_Ary2D() ((P2CONST(u2p14, AUTOMATIC, RTE_VAR_NOINIT)) &(((P2CONST(Rte_Calprm_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP])->ClsdLoopHysRackFFacY_Ary2D[0][0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_ClsdLoopHysRackFFacY_Ary2D() (&((P2CONST(Rte_Calprm_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP])->ClsdLoopHysRackFFacY_Ary2D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_ClsdLoopHysRhoY_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP])->ClsdLoopHysRhoY_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_ClsdLoopHysRhoY_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP])->ClsdLoopHysRhoY_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_ClsdLoopHysSysFricOffsLimX_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP])->ClsdLoopHysSysFricOffsLimX_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_ClsdLoopHysSysFricOffsLimX_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP])->ClsdLoopHysSysFricOffsLimX_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_ClsdLoopHysSysFricOffsLimY_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP])->ClsdLoopHysSysFricOffsLimY_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_ClsdLoopHysSysFricOffsLimY_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP])->ClsdLoopHysSysFricOffsLimY_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_ClsdLoopHysSysFricScaX_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP])->ClsdLoopHysSysFricScaX_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_ClsdLoopHysSysFricScaX_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP])->ClsdLoopHysSysFricScaX_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_ClsdLoopHysSysFricScaY_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP])->ClsdLoopHysSysFricScaY_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_ClsdLoopHysSysFricScaY_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP])->ClsdLoopHysSysFricScaY_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
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

extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_ClsdLoopHys_IntgtrSt; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Appl7_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  endif

#  define Rte_Pim_IntgtrSt() \
  (&Rte_ClsdLoopHys_IntgtrSt) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define ClsdLoopHys_START_SEC_CODE
# include "ClsdLoopHys_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_ClsdLoopHysInit1 ClsdLoopHysInit1
#  define RTE_RUNNABLE_ClsdLoopHysPer1 ClsdLoopHysPer1
# endif

FUNC(void, ClsdLoopHys_CODE) ClsdLoopHysInit1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, ClsdLoopHys_CODE) ClsdLoopHysPer1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define ClsdLoopHys_STOP_SEC_CODE
# include "ClsdLoopHys_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CLSDLOOPHYS_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
