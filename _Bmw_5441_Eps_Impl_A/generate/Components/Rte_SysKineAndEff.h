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
 *          File:  Rte_SysKineAndEff.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <SysKineAndEff>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_SYSKINEANDEFF_H
# define _RTE_SYSKINEANDEFF_H

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

# include "Rte_SysKineAndEff_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_Appl7_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_INIT) Rte_SysKineAndEff_HwAg_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_SysKineAndEff_HwVel_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_SysKineAndEff_MotAgToRackPosnInstsRat_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_SysKineAndEff_MotToRackFInstsRat_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_SysKineAndEff_MotToRackInstsEff_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_SysKineAndEff_PinionAgToRackInstsEff_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_SysKineAndEff_PinionAgToRackPosnInstsRat_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_SysKineAndEff_PinionTqToRackFInstsRat_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_SysKineAndEff_PinionVel_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_SysKineAndEff_RackPosn_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_SysKineAndEff_RackVel_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_SysKineAndEff_RoadWhlAg_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_SysKineAndEff_SteerArmLen_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_SysKineAndEff_SysAssiTqRat_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_SysKineAndEff_SysKineRat_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_SysKineAndEff_SysTqRat_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_SysKineAndEff_CmplncErrPinionToHw_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_Appl7_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(s18p13, RTE_VAR_INIT) Rte_CDD_MotAgCmp_MotAgCumvAlgndMrf_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_MotVel_MotVelCrf_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwHwAgArbnAndEotPosn_PinionAg_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_CmplncErrPinionToHw_Val (0.0F)
#  define Rte_InitValue_HwAg_Val (0.0F)
#  define Rte_InitValue_HwVel_Val (0.0F)
#  define Rte_InitValue_MotAgCumvAlgndMrf_Val (0)
#  define Rte_InitValue_MotAgToRackPosnInstsRat_Val (0.01F)
#  define Rte_InitValue_MotToRackFInstsRat_Val (3000.0F)
#  define Rte_InitValue_MotToRackInstsEff_Val (0.86F)
#  define Rte_InitValue_MotVelCrf_Val (0.0F)
#  define Rte_InitValue_PinionAg_Val (0.0F)
#  define Rte_InitValue_PinionAgToRackInstsEff_Val (0.92F)
#  define Rte_InitValue_PinionAgToRackPosnInstsRat_Val (10.0F)
#  define Rte_InitValue_PinionTqToRackFInstsRat_Val (200.0F)
#  define Rte_InitValue_PinionVel_Val (0.0F)
#  define Rte_InitValue_RackPosn_Val (0.0F)
#  define Rte_InitValue_RackVel_Val (0.0F)
#  define Rte_InitValue_RoadWhlAg_Val (0.0F)
#  define Rte_InitValue_SteerArmLen_Val (200.0F)
#  define Rte_InitValue_SysAssiTqRat_Val (26.0F)
#  define Rte_InitValue_SysKineRat_Val (28.0F)
#  define Rte_InitValue_SysTqRat_Val (26.0F)
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_CmplncErrPinionToHw_Val Rte_Read_SysKineAndEff_CmplncErrPinionToHw_Val
#  define Rte_Read_SysKineAndEff_CmplncErrPinionToHw_Val(data) (*(data) = Rte_SysKineAndEff_CmplncErrPinionToHw_Val, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotAgCumvAlgndMrf_Val Rte_Read_SysKineAndEff_MotAgCumvAlgndMrf_Val
#  define Rte_Read_SysKineAndEff_MotAgCumvAlgndMrf_Val(data) (*(data) = Rte_CDD_MotAgCmp_MotAgCumvAlgndMrf_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotVelCrf_Val Rte_Read_SysKineAndEff_MotVelCrf_Val
#  define Rte_Read_SysKineAndEff_MotVelCrf_Val(data) (*(data) = Rte_CDD_MotVel_MotVelCrf_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_PinionAg_Val Rte_Read_SysKineAndEff_PinionAg_Val
#  define Rte_Read_SysKineAndEff_PinionAg_Val(data) (*(data) = Rte_BmwHwAgArbnAndEotPosn_PinionAg_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_HwAg_Val Rte_Write_SysKineAndEff_HwAg_Val
#  define Rte_Write_SysKineAndEff_HwAg_Val(data) (Rte_SysKineAndEff_HwAg_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_HwVel_Val Rte_Write_SysKineAndEff_HwVel_Val
#  define Rte_Write_SysKineAndEff_HwVel_Val(data) (Rte_SysKineAndEff_HwVel_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_MotAgToRackPosnInstsRat_Val Rte_Write_SysKineAndEff_MotAgToRackPosnInstsRat_Val
#  define Rte_Write_SysKineAndEff_MotAgToRackPosnInstsRat_Val(data) (Rte_SysKineAndEff_MotAgToRackPosnInstsRat_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_MotToRackFInstsRat_Val Rte_Write_SysKineAndEff_MotToRackFInstsRat_Val
#  define Rte_Write_SysKineAndEff_MotToRackFInstsRat_Val(data) (Rte_SysKineAndEff_MotToRackFInstsRat_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_MotToRackInstsEff_Val Rte_Write_SysKineAndEff_MotToRackInstsEff_Val
#  define Rte_Write_SysKineAndEff_MotToRackInstsEff_Val(data) (Rte_SysKineAndEff_MotToRackInstsEff_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_PinionAgToRackInstsEff_Val Rte_Write_SysKineAndEff_PinionAgToRackInstsEff_Val
#  define Rte_Write_SysKineAndEff_PinionAgToRackInstsEff_Val(data) (Rte_SysKineAndEff_PinionAgToRackInstsEff_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_PinionAgToRackPosnInstsRat_Val Rte_Write_SysKineAndEff_PinionAgToRackPosnInstsRat_Val
#  define Rte_Write_SysKineAndEff_PinionAgToRackPosnInstsRat_Val(data) (Rte_SysKineAndEff_PinionAgToRackPosnInstsRat_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_PinionTqToRackFInstsRat_Val Rte_Write_SysKineAndEff_PinionTqToRackFInstsRat_Val
#  define Rte_Write_SysKineAndEff_PinionTqToRackFInstsRat_Val(data) (Rte_SysKineAndEff_PinionTqToRackFInstsRat_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_PinionVel_Val Rte_Write_SysKineAndEff_PinionVel_Val
#  define Rte_Write_SysKineAndEff_PinionVel_Val(data) (Rte_SysKineAndEff_PinionVel_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_RackPosn_Val Rte_Write_SysKineAndEff_RackPosn_Val
#  define Rte_Write_SysKineAndEff_RackPosn_Val(data) (Rte_SysKineAndEff_RackPosn_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_RackVel_Val Rte_Write_SysKineAndEff_RackVel_Val
#  define Rte_Write_SysKineAndEff_RackVel_Val(data) (Rte_SysKineAndEff_RackVel_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_RoadWhlAg_Val Rte_Write_SysKineAndEff_RoadWhlAg_Val
#  define Rte_Write_SysKineAndEff_RoadWhlAg_Val(data) (Rte_SysKineAndEff_RoadWhlAg_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_SteerArmLen_Val Rte_Write_SysKineAndEff_SteerArmLen_Val
#  define Rte_Write_SysKineAndEff_SteerArmLen_Val(data) (Rte_SysKineAndEff_SteerArmLen_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_SysAssiTqRat_Val Rte_Write_SysKineAndEff_SysAssiTqRat_Val
#  define Rte_Write_SysKineAndEff_SysAssiTqRat_Val(data) (Rte_SysKineAndEff_SysAssiTqRat_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_SysKineRat_Val Rte_Write_SysKineAndEff_SysKineRat_Val
#  define Rte_Write_SysKineAndEff_SysKineRat_Val(data) (Rte_SysKineAndEff_SysKineRat_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_SysTqRat_Val Rte_Write_SysKineAndEff_SysTqRat_Val
#  define Rte_Write_SysKineAndEff_SysTqRat_Val(data) (Rte_SysKineAndEff_SysTqRat_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

#  define Rte_Prm_SysKineAndEffCmplncErrDerivtvCutOffFrq_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->SysKineAndEffCmplncErrDerivtvCutOffFrq_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_SysKineAndEffMotAgScaX_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->SysKineAndEffMotAgScaX_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_SysKineAndEffMotAgScaX_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->SysKineAndEffMotAgScaX_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_SysKineAndEffMotAgToRackPosRatScaY_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn01Inin00_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00_DEFAULT_RTE_CALPRM_GROUP])->SysKineAndEffMotAgToRackPosRatScaY_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_SysKineAndEffMotAgToRackPosRatScaY_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn01Inin00_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00_DEFAULT_RTE_CALPRM_GROUP])->SysKineAndEffMotAgToRackPosRatScaY_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_SysKineAndEffMotToRackEffScaY_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->SysKineAndEffMotToRackEffScaY_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_SysKineAndEffMotToRackEffScaY_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->SysKineAndEffMotToRackEffScaY_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_SysKineAndEffPinionAgToRackPosRatScaY_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn01Inin00_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00_DEFAULT_RTE_CALPRM_GROUP])->SysKineAndEffPinionAgToRackPosRatScaY_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_SysKineAndEffPinionAgToRackPosRatScaY_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn01Inin00_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00_DEFAULT_RTE_CALPRM_GROUP])->SysKineAndEffPinionAgToRackPosRatScaY_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_SysKineAndEffPinionToRackEffScaY_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn01Inin00_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00_DEFAULT_RTE_CALPRM_GROUP])->SysKineAndEffPinionToRackEffScaY_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_SysKineAndEffPinionToRackEffScaY_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn01Inin00_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00_DEFAULT_RTE_CALPRM_GROUP])->SysKineAndEffPinionToRackEffScaY_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_SysKineAndEffRackPosScaY_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->SysKineAndEffRackPosScaY_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_SysKineAndEffRackPosScaY_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->SysKineAndEffRackPosScaY_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_SysKineAndEffRoadWhlFromRackPosScaY_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn01Inin00_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00_DEFAULT_RTE_CALPRM_GROUP])->SysKineAndEffRoadWhlFromRackPosScaY_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_SysKineAndEffRoadWhlFromRackPosScaY_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn01Inin00_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00_DEFAULT_RTE_CALPRM_GROUP])->SysKineAndEffRoadWhlFromRackPosScaY_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_SysKineAndEffSteerArmLenFromRackPosScaY_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn01Inin00_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00_DEFAULT_RTE_CALPRM_GROUP])->SysKineAndEffSteerArmLenFromRackPosScaY_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_SysKineAndEffSteerArmLenFromRackPosScaY_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn01Inin00_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00_DEFAULT_RTE_CALPRM_GROUP])->SysKineAndEffSteerArmLenFromRackPosScaY_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
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

extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_SysKineAndEff_CmplncErrDerivtvPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_SysKineAndEff_CmplncErrPinionToHwPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Appl7_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  endif

#  define Rte_Pim_CmplncErrDerivtvPrev() \
  (&Rte_SysKineAndEff_CmplncErrDerivtvPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_CmplncErrPinionToHwPrev() \
  (&Rte_SysKineAndEff_CmplncErrPinionToHwPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define SysKineAndEff_START_SEC_CODE
# include "SysKineAndEff_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_SysKineAndEffInit1 SysKineAndEffInit1
#  define RTE_RUNNABLE_SysKineAndEffPer1 SysKineAndEffPer1
# endif

FUNC(void, SysKineAndEff_CODE) SysKineAndEffInit1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, SysKineAndEff_CODE) SysKineAndEffPer1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define SysKineAndEff_STOP_SEC_CODE
# include "SysKineAndEff_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_SYSKINEANDEFF_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
