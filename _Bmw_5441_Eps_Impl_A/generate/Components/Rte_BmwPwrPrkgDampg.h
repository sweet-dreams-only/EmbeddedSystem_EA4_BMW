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
 *          File:  Rte_BmwPwrPrkgDampg.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <BmwPwrPrkgDampg>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_BMWPWRPRKGDAMPG_H
# define _RTE_BMWPWRPRKGDAMPG_H

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

# include "Rte_BmwPwrPrkgDampg_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_Appl7_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_INIT) Rte_BmwPwrPrkgDampg_DampgCmdPwrPrkg_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_ClsdLoopDampg_HwTqCmdDampg_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_SysKineAndEff_HwVel_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_Appl7_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_Appl9_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_INIT) Rte_BmwVehSpd_VehSpd_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_Appl9_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(boolean, RTE_VAR_INIT) Rte_BmwSwFctDi_DampgCmdPwrPrkgEna_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwHwAgArbnAndEotPosn_PinionAg_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwHwAgArbnAndEotPosn_PinionAgConf_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_DampgCmdBas_Val (0.0F)
#  define Rte_InitValue_DampgCmdPwrPrkg_Val (0.0F)
#  define Rte_InitValue_DampgCmdPwrPrkgEna_Logl (FALSE)
#  define Rte_InitValue_HwVel_Val (0.0F)
#  define Rte_InitValue_PinionAg_Val (0.0F)
#  define Rte_InitValue_PinionAgConf_Val (0.0F)
#  define Rte_InitValue_VehSpd_Val (0.0F)
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_DampgCmdBas_Val Rte_Read_BmwPwrPrkgDampg_DampgCmdBas_Val
#  define Rte_Read_BmwPwrPrkgDampg_DampgCmdBas_Val(data) (*(data) = Rte_ClsdLoopDampg_HwTqCmdDampg_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_DampgCmdPwrPrkgEna_Logl Rte_Read_BmwPwrPrkgDampg_DampgCmdPwrPrkgEna_Logl
#  define Rte_Read_BmwPwrPrkgDampg_DampgCmdPwrPrkgEna_Logl(data) (*(data) = Rte_BmwSwFctDi_DampgCmdPwrPrkgEna_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_HwVel_Val Rte_Read_BmwPwrPrkgDampg_HwVel_Val
#  define Rte_Read_BmwPwrPrkgDampg_HwVel_Val(data) (*(data) = Rte_SysKineAndEff_HwVel_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_PinionAg_Val Rte_Read_BmwPwrPrkgDampg_PinionAg_Val
#  define Rte_Read_BmwPwrPrkgDampg_PinionAg_Val(data) (*(data) = Rte_BmwHwAgArbnAndEotPosn_PinionAg_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_PinionAgConf_Val Rte_Read_BmwPwrPrkgDampg_PinionAgConf_Val
#  define Rte_Read_BmwPwrPrkgDampg_PinionAgConf_Val(data) (*(data) = Rte_BmwHwAgArbnAndEotPosn_PinionAgConf_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_VehSpd_Val Rte_Read_BmwPwrPrkgDampg_VehSpd_Val
#  define Rte_Read_BmwPwrPrkgDampg_VehSpd_Val(data) (*(data) = Rte_BmwVehSpd_VehSpd_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_DampgCmdPwrPrkg_Val Rte_Write_BmwPwrPrkgDampg_DampgCmdPwrPrkg_Val
#  define Rte_Write_BmwPwrPrkgDampg_DampgCmdPwrPrkg_Val(data) (Rte_BmwPwrPrkgDampg_DampgCmdPwrPrkg_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

#  define Rte_Prm_BmwPwrPrkgDampgMaxRate_Val() (((P2CONST(Rte_Calprm_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP])->BmwPwrPrkgDampgMaxRate_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwPwrPrkgDampgMinPinionAgConf_Val() (((P2CONST(Rte_Calprm_CalRegn01CmnGroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupA_DEFAULT_RTE_CALPRM_GROUP])->BmwPwrPrkgDampgMinPinionAgConf_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwPwrPrkgDampgDiScadDampg_Logl() (((P2CONST(Rte_Calprm_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP])->BmwPwrPrkgDampgDiScadDampg_Logl) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_BmwPwrPrkgDampgBasPwrPrkgDampgY_Ary2D() ((P2CONST(u5p11, AUTOMATIC, RTE_VAR_NOINIT)) &(((P2CONST(Rte_Calprm_CalRegn02Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP])->BmwPwrPrkgDampgBasPwrPrkgDampgY_Ary2D[0][0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_BmwPwrPrkgDampgBasPwrPrkgDampgY_Ary2D() (&((P2CONST(Rte_Calprm_CalRegn02Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP])->BmwPwrPrkgDampgBasPwrPrkgDampgY_Ary2D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_BmwPwrPrkgDampgHwVelTblX_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn02Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP])->BmwPwrPrkgDampgHwVelTblX_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_BmwPwrPrkgDampgHwVelTblX_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn02Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP])->BmwPwrPrkgDampgHwVelTblX_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_BmwPwrPrkgDampgPinionAgSelnTbl_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn02Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP])->BmwPwrPrkgDampgPinionAgSelnTbl_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_BmwPwrPrkgDampgPinionAgSelnTbl_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn02Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP])->BmwPwrPrkgDampgPinionAgSelnTbl_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_BmwPwrPrkgDampgVehSpdLnrSelnX_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn02Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP])->BmwPwrPrkgDampgVehSpdLnrSelnX_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_BmwPwrPrkgDampgVehSpdLnrSelnX_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn02Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP])->BmwPwrPrkgDampgVehSpdLnrSelnX_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_BmwPwrPrkgDampgVehSpdScaFacY_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn02Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP])->BmwPwrPrkgDampgVehSpdScaFacY_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_BmwPwrPrkgDampgVehSpdScaFacY_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn02Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP])->BmwPwrPrkgDampgVehSpdScaFacY_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
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

extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_BmwPwrPrkgDampg_DampgCmdPwrPrkgStVari; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Appl7_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  endif

#  define Rte_Pim_DampgCmdPwrPrkgStVari() \
  (&Rte_BmwPwrPrkgDampg_DampgCmdPwrPrkgStVari) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define BmwPwrPrkgDampg_START_SEC_CODE
# include "BmwPwrPrkgDampg_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_BmwPwrPrkgDampgInit1 BmwPwrPrkgDampgInit1
#  define RTE_RUNNABLE_BmwPwrPrkgDampgPer1 BmwPwrPrkgDampgPer1
# endif

FUNC(void, BmwPwrPrkgDampg_CODE) BmwPwrPrkgDampgInit1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, BmwPwrPrkgDampg_CODE) BmwPwrPrkgDampgPer1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define BmwPwrPrkgDampg_STOP_SEC_CODE
# include "BmwPwrPrkgDampg_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_BMWPWRPRKGDAMPG_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
