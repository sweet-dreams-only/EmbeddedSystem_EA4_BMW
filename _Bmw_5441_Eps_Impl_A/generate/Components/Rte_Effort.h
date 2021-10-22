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
 *          File:  Rte_Effort.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <Effort>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_EFFORT_H
# define _RTE_EFFORT_H

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

# include "Rte_Effort_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_Appl7_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_INIT) Rte_Effort_HwTqCmdEffort_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
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

extern VAR(float32, RTE_VAR_INIT) Rte_BmwTqOvrlCdngAndDrvgDynFac_EffortCmdSca_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_EffortCmdSca_Val (1.0F)
#  define Rte_InitValue_HwTqCmdEffort_Val (0.0F)
#  define Rte_InitValue_RackFEstimd_Val (0.0F)
#  define Rte_InitValue_VehSpd_Val (0.0F)
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_EffortCmdSca_Val Rte_Read_Effort_EffortCmdSca_Val
#  define Rte_Read_Effort_EffortCmdSca_Val(data) (*(data) = Rte_BmwTqOvrlCdngAndDrvgDynFac_EffortCmdSca_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_RackFEstimd_Val Rte_Read_Effort_RackFEstimd_Val
#  define Rte_Read_Effort_RackFEstimd_Val(data) (*(data) = Rte_EpsStEstimn_RackFEstimd_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_VehSpd_Val Rte_Read_Effort_VehSpd_Val
#  define Rte_Read_Effort_VehSpd_Val(data) (*(data) = Rte_BmwVehSpd_VehSpd_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_HwTqCmdEffort_Val Rte_Write_Effort_HwTqCmdEffort_Val
#  define Rte_Write_Effort_HwTqCmdEffort_Val(data) (Rte_Effort_HwTqCmdEffort_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

#  define Rte_Prm_EffortScaRackFThd_Val() (((P2CONST(Rte_Calprm_CalRegn01Inin00_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00_DEFAULT_RTE_CALPRM_GROUP])->EffortScaRackFThd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_EffortRackFX_Ary2D() ((P2CONST(u15p1, AUTOMATIC, RTE_VAR_NOINIT)) &(((P2CONST(Rte_Calprm_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP])->EffortRackFX_Ary2D[0][0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_EffortRackFX_Ary2D() (&((P2CONST(Rte_Calprm_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP])->EffortRackFX_Ary2D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_EffortRackFY_Ary2D() ((P2CONST(u4p12, AUTOMATIC, RTE_VAR_NOINIT)) &(((P2CONST(Rte_Calprm_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP])->EffortRackFY_Ary2D[0][0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_EffortRackFY_Ary2D() (&((P2CONST(Rte_Calprm_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP])->EffortRackFY_Ary2D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_EffortScaBlndX_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn01Inin00_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00_DEFAULT_RTE_CALPRM_GROUP])->EffortScaBlndX_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_EffortScaBlndX_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn01Inin00_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00_DEFAULT_RTE_CALPRM_GROUP])->EffortScaBlndX_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_EffortScaBlndY_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn01Inin00_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00_DEFAULT_RTE_CALPRM_GROUP])->EffortScaBlndY_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_EffortScaBlndY_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn01Inin00_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00_DEFAULT_RTE_CALPRM_GROUP])->EffortScaBlndY_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_EffortVehSpdBilnrSeln_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP])->EffortVehSpdBilnrSeln_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_EffortVehSpdBilnrSeln_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupD_DEFAULT_RTE_CALPRM_GROUP])->EffortVehSpdBilnrSeln_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

# endif /* !defined(RTE_CORE) */


# define Effort_START_SEC_CODE
# include "Effort_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_EffortInit1 EffortInit1
#  define RTE_RUNNABLE_EffortPer1 EffortPer1
# endif

FUNC(void, Effort_CODE) EffortInit1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, Effort_CODE) EffortPer1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define Effort_STOP_SEC_CODE
# include "Effort_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_EFFORT_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
