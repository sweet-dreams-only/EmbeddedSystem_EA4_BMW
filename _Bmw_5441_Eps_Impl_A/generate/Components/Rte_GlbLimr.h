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
 *          File:  Rte_GlbLimr.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <GlbLimr>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_GLBLIMR_H
# define _RTE_GLBLIMR_H

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

# include "Rte_GlbLimr_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_Appl9_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_INIT) Rte_BmwVehSpd_VehSpd_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_Appl9_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_INIT) Rte_GlbLimr_LimdMotTqCmd_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_Swp_HwTqSwp_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_HwTqTrakgCtrl_MotTqCmdTrakgCtrl_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_HwTq_Val (0.0F)
#  define Rte_InitValue_LimdMotTqCmd_Val (0.0F)
#  define Rte_InitValue_MotTqCmd_Val (0.0F)
#  define Rte_InitValue_VehSpd_Val (0.0F)
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_HwTq_Val Rte_Read_GlbLimr_HwTq_Val
#  define Rte_Read_GlbLimr_HwTq_Val(data) (*(data) = Rte_Swp_HwTqSwp_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotTqCmd_Val Rte_Read_GlbLimr_MotTqCmd_Val
#  define Rte_Read_GlbLimr_MotTqCmd_Val(data) (*(data) = Rte_HwTqTrakgCtrl_MotTqCmdTrakgCtrl_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_VehSpd_Val Rte_Read_GlbLimr_VehSpd_Val
#  define Rte_Read_GlbLimr_VehSpd_Val(data) (*(data) = Rte_BmwVehSpd_VehSpd_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_LimdMotTqCmd_Val Rte_Write_GlbLimr_LimdMotTqCmd_Val
#  define Rte_Write_GlbLimr_LimdMotTqCmd_Val(data) (Rte_GlbLimr_LimdMotTqCmd_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_GlbLimrBndX_Ary2D() ((P2CONST(s4p11, AUTOMATIC, RTE_VAR_NOINIT)) &(((P2CONST(Rte_Calprm_CalRegn01Inin00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00GroupC_DEFAULT_RTE_CALPRM_GROUP])->GlbLimrBndX_Ary2D[0][0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_GlbLimrBndX_Ary2D() (&((P2CONST(Rte_Calprm_CalRegn01Inin00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00GroupC_DEFAULT_RTE_CALPRM_GROUP])->GlbLimrBndX_Ary2D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_GlbLimrBndY_Ary2D() ((P2CONST(s4p11, AUTOMATIC, RTE_VAR_NOINIT)) &(((P2CONST(Rte_Calprm_CalRegn01Inin00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00GroupC_DEFAULT_RTE_CALPRM_GROUP])->GlbLimrBndY_Ary2D[0][0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_GlbLimrBndY_Ary2D() (&((P2CONST(Rte_Calprm_CalRegn01Inin00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00GroupC_DEFAULT_RTE_CALPRM_GROUP])->GlbLimrBndY_Ary2D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_GlbLimrVehSpdBilnrSeln_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn01Inin00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00GroupC_DEFAULT_RTE_CALPRM_GROUP])->GlbLimrVehSpdBilnrSeln_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_GlbLimrVehSpdBilnrSeln_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn01Inin00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00GroupC_DEFAULT_RTE_CALPRM_GROUP])->GlbLimrVehSpdBilnrSeln_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  define Rte_Prm_GlbLimrNotchFilStruct_Rec() (&((P2CONST(Rte_Calprm_CalRegn01Inin00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00GroupC_DEFAULT_RTE_CALPRM_GROUP])->GlbLimrNotchFilStruct_Rec) /* PRQA S 3453 */ /* MD_MSR_19.7 */

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GlbLimr_GlbLimrNotch1Fil1; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GlbLimr_GlbLimrNotch1Fil2; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GlbLimr_GlbLimrNotch2Fil1; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GlbLimr_GlbLimrNotch2Fil2; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  endif

#  define Rte_Pim_GlbLimrNotch1Fil1() \
  (&Rte_GlbLimr_GlbLimrNotch1Fil1) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_GlbLimrNotch1Fil2() \
  (&Rte_GlbLimr_GlbLimrNotch1Fil2) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_GlbLimrNotch2Fil1() \
  (&Rte_GlbLimr_GlbLimrNotch2Fil1) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_GlbLimrNotch2Fil2() \
  (&Rte_GlbLimr_GlbLimrNotch2Fil2) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define GlbLimr_START_SEC_CODE
# include "GlbLimr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_GlbLimrInit1 GlbLimrInit1
#  define RTE_RUNNABLE_GlbLimrPer1 GlbLimrPer1
# endif

FUNC(void, GlbLimr_CODE) GlbLimrInit1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, GlbLimr_CODE) GlbLimrPer1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define GlbLimr_STOP_SEC_CODE
# include "GlbLimr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_GLBLIMR_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
