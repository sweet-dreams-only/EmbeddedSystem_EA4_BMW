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
 *          File:  Rte_ClsdLoopDampg.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <ClsdLoopDampg>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CLSDLOOPDAMPG_H
# define _RTE_CLSDLOOPDAMPG_H

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

# include "Rte_ClsdLoopDampg_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_Appl7_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_INIT) Rte_ClsdLoopDampg_HwTqCmdDampg_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_ClsdLoopDampg_EotCtrlSca_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_ClsdLoopDampg_EotDeltaAg_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(EotSt1, RTE_VAR_INIT) Rte_ClsdLoopDampg_EotSt_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_SysKineAndEff_PinionVel_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
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

extern VAR(float32, RTE_VAR_INIT) Rte_BmwTqOvrlCdngAndDrvgDynFac_DampgCmdSca_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_DampgCmdSca_Val (1.0F)
#  define Rte_InitValue_EotCtrlSca_Val (0.0F)
#  define Rte_InitValue_EotDeltaAg_Val (900.0F)
#  define Rte_InitValue_EotSt_Val (0U)
#  define Rte_InitValue_HwTqCmdDampg_Val (0.0F)
#  define Rte_InitValue_PinionVel_Val (0.0F)
#  define Rte_InitValue_RackFEstimd_Val (0.0F)
#  define Rte_InitValue_VehSpd_Val (0.0F)
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_DampgCmdSca_Val Rte_Read_ClsdLoopDampg_DampgCmdSca_Val
#  define Rte_Read_ClsdLoopDampg_DampgCmdSca_Val(data) (*(data) = Rte_BmwTqOvrlCdngAndDrvgDynFac_DampgCmdSca_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_EotCtrlSca_Val Rte_Read_ClsdLoopDampg_EotCtrlSca_Val
#  define Rte_Read_ClsdLoopDampg_EotCtrlSca_Val(data) (*(data) = Rte_ClsdLoopDampg_EotCtrlSca_Val, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_EotDeltaAg_Val Rte_Read_ClsdLoopDampg_EotDeltaAg_Val
#  define Rte_Read_ClsdLoopDampg_EotDeltaAg_Val(data) (*(data) = Rte_ClsdLoopDampg_EotDeltaAg_Val, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_EotSt_Val Rte_Read_ClsdLoopDampg_EotSt_Val
#  define Rte_Read_ClsdLoopDampg_EotSt_Val(data) (*(data) = Rte_ClsdLoopDampg_EotSt_Val, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_PinionVel_Val Rte_Read_ClsdLoopDampg_PinionVel_Val
#  define Rte_Read_ClsdLoopDampg_PinionVel_Val(data) (*(data) = Rte_SysKineAndEff_PinionVel_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_RackFEstimd_Val Rte_Read_ClsdLoopDampg_RackFEstimd_Val
#  define Rte_Read_ClsdLoopDampg_RackFEstimd_Val(data) (*(data) = Rte_EpsStEstimn_RackFEstimd_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_VehSpd_Val Rte_Read_ClsdLoopDampg_VehSpd_Val
#  define Rte_Read_ClsdLoopDampg_VehSpd_Val(data) (*(data) = Rte_BmwVehSpd_VehSpd_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_HwTqCmdDampg_Val Rte_Write_ClsdLoopDampg_HwTqCmdDampg_Val
#  define Rte_Write_ClsdLoopDampg_HwTqCmdDampg_Val(data) (Rte_ClsdLoopDampg_HwTqCmdDampg_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_ClsdLoopDampgEotEntrX_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP])->ClsdLoopDampgEotEntrX_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_ClsdLoopDampgEotEntrX_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP])->ClsdLoopDampgEotEntrX_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_ClsdLoopDampgEotEntrY_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP])->ClsdLoopDampgEotEntrY_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_ClsdLoopDampgEotEntrY_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP])->ClsdLoopDampgEotEntrY_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_ClsdLoopDampgEotExitX_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP])->ClsdLoopDampgEotExitX_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_ClsdLoopDampgEotExitX_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP])->ClsdLoopDampgEotExitX_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_ClsdLoopDampgEotExitY_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP])->ClsdLoopDampgEotExitY_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_ClsdLoopDampgEotExitY_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP])->ClsdLoopDampgEotExitY_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_ClsdLoopDampgPinionVelX_Ary2D() ((P2CONST(u6p10, AUTOMATIC, RTE_VAR_NOINIT)) &(((P2CONST(Rte_Calprm_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP])->ClsdLoopDampgPinionVelX_Ary2D[0][0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_ClsdLoopDampgPinionVelX_Ary2D() (&((P2CONST(Rte_Calprm_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP])->ClsdLoopDampgPinionVelX_Ary2D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_ClsdLoopDampgPinionVelY_Ary2D() ((P2CONST(u4p12, AUTOMATIC, RTE_VAR_NOINIT)) &(((P2CONST(Rte_Calprm_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP])->ClsdLoopDampgPinionVelY_Ary2D[0][0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_ClsdLoopDampgPinionVelY_Ary2D() (&((P2CONST(Rte_Calprm_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP])->ClsdLoopDampgPinionVelY_Ary2D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_ClsdLoopDampgRackFX_Ary2D() ((P2CONST(u15p1, AUTOMATIC, RTE_VAR_NOINIT)) &(((P2CONST(Rte_Calprm_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP])->ClsdLoopDampgRackFX_Ary2D[0][0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_ClsdLoopDampgRackFX_Ary2D() (&((P2CONST(Rte_Calprm_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP])->ClsdLoopDampgRackFX_Ary2D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_ClsdLoopDampgRackFY_Ary2D() ((P2CONST(u1p15, AUTOMATIC, RTE_VAR_NOINIT)) &(((P2CONST(Rte_Calprm_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP])->ClsdLoopDampgRackFY_Ary2D[0][0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_ClsdLoopDampgRackFY_Ary2D() (&((P2CONST(Rte_Calprm_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP])->ClsdLoopDampgRackFY_Ary2D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn01Inin00_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00_DEFAULT_RTE_CALPRM_GROUP])->SysGlbPrmVehSpdBilnrSeln_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn01Inin00_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00_DEFAULT_RTE_CALPRM_GROUP])->SysGlbPrmVehSpdBilnrSeln_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

# endif /* !defined(RTE_CORE) */


# define ClsdLoopDampg_START_SEC_CODE
# include "ClsdLoopDampg_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_ClsdLoopDampgInit1 ClsdLoopDampgInit1
#  define RTE_RUNNABLE_ClsdLoopDampgPer1 ClsdLoopDampgPer1
# endif

FUNC(void, ClsdLoopDampg_CODE) ClsdLoopDampgInit1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, ClsdLoopDampg_CODE) ClsdLoopDampgPer1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define ClsdLoopDampg_STOP_SEC_CODE
# include "ClsdLoopDampg_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CLSDLOOPDAMPG_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
