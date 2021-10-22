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
 *          File:  Rte_CtrldVelRtn.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <CtrldVelRtn>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CTRLDVELRTN_H
# define _RTE_CTRLDVELRTN_H

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

# include "Rte_CtrldVelRtn_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_Appl7_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_INIT) Rte_CtrldVelRtn_CtrldVelRtnCmd_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CtrldVelRtn_HwAgRtnOffs_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_SysKineAndEff_HwVel_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_CtrldVelRtn_RtnCmdDiagcDi_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CtrldVelRtn_RtnCmdScaServo_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_Appl7_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_Appl9_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_INIT) Rte_BmwVehSpd_VehSpd_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_Appl9_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(sint8, RTE_VAR_INIT) Rte_PolarityCfg_AssiMechPolarity_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwHwAgArbnAndEotPosn_OffsCmpdPinionAg_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwHwAgArbnAndEotPosn_PinionAgConf_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_Swp_HwTqSwp_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_PwrLimr_MotTqCmdPwrLimd_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_CmnMfgSrv_RtnCmdDi_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwTqOvrlCdngAndDrvgDynFac_RtnCmdSca_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_AssiMechPolarity_Val (1)
#  define Rte_InitValue_CtrldVelRtnCmd_Val (0.0F)
#  define Rte_InitValue_HwAg_Val (0.0F)
#  define Rte_InitValue_HwAgAuthy_Val (0.0F)
#  define Rte_InitValue_HwAgRtnOffs_Val (0.0F)
#  define Rte_InitValue_HwTq_Val (0.0F)
#  define Rte_InitValue_HwVel_Val (0.0F)
#  define Rte_InitValue_MotTqCmdPwrLimd_Val (0.0F)
#  define Rte_InitValue_RtnCmdDi_Logl (FALSE)
#  define Rte_InitValue_RtnCmdDiagcDi_Logl (FALSE)
#  define Rte_InitValue_RtnCmdSca_Val (1.0F)
#  define Rte_InitValue_RtnCmdScaServo_Val (1.0F)
#  define Rte_InitValue_VehSpd_Val (0.0F)
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_AssiMechPolarity_Val Rte_Read_CtrldVelRtn_AssiMechPolarity_Val
#  define Rte_Read_CtrldVelRtn_AssiMechPolarity_Val(data) (*(data) = Rte_PolarityCfg_AssiMechPolarity_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_HwAg_Val Rte_Read_CtrldVelRtn_HwAg_Val
#  define Rte_Read_CtrldVelRtn_HwAg_Val(data) (*(data) = Rte_BmwHwAgArbnAndEotPosn_OffsCmpdPinionAg_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_HwAgAuthy_Val Rte_Read_CtrldVelRtn_HwAgAuthy_Val
#  define Rte_Read_CtrldVelRtn_HwAgAuthy_Val(data) (*(data) = Rte_BmwHwAgArbnAndEotPosn_PinionAgConf_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_HwAgRtnOffs_Val Rte_Read_CtrldVelRtn_HwAgRtnOffs_Val
#  define Rte_Read_CtrldVelRtn_HwAgRtnOffs_Val(data) (*(data) = Rte_CtrldVelRtn_HwAgRtnOffs_Val, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_HwTq_Val Rte_Read_CtrldVelRtn_HwTq_Val
#  define Rte_Read_CtrldVelRtn_HwTq_Val(data) (*(data) = Rte_Swp_HwTqSwp_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_HwVel_Val Rte_Read_CtrldVelRtn_HwVel_Val
#  define Rte_Read_CtrldVelRtn_HwVel_Val(data) (*(data) = Rte_SysKineAndEff_HwVel_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotTqCmdPwrLimd_Val Rte_Read_CtrldVelRtn_MotTqCmdPwrLimd_Val
#  define Rte_Read_CtrldVelRtn_MotTqCmdPwrLimd_Val(data) (*(data) = Rte_PwrLimr_MotTqCmdPwrLimd_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_RtnCmdDi_Logl Rte_Read_CtrldVelRtn_RtnCmdDi_Logl
#  define Rte_Read_CtrldVelRtn_RtnCmdDi_Logl(data) (*(data) = Rte_CmnMfgSrv_RtnCmdDi_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_RtnCmdDiagcDi_Logl Rte_Read_CtrldVelRtn_RtnCmdDiagcDi_Logl
#  define Rte_Read_CtrldVelRtn_RtnCmdDiagcDi_Logl(data) (*(data) = Rte_CtrldVelRtn_RtnCmdDiagcDi_Logl, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_RtnCmdSca_Val Rte_Read_CtrldVelRtn_RtnCmdSca_Val
#  define Rte_Read_CtrldVelRtn_RtnCmdSca_Val(data) (*(data) = Rte_BmwTqOvrlCdngAndDrvgDynFac_RtnCmdSca_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_RtnCmdScaServo_Val Rte_Read_CtrldVelRtn_RtnCmdScaServo_Val
#  define Rte_Read_CtrldVelRtn_RtnCmdScaServo_Val(data) (*(data) = Rte_CtrldVelRtn_RtnCmdScaServo_Val, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_VehSpd_Val Rte_Read_CtrldVelRtn_VehSpd_Val
#  define Rte_Read_CtrldVelRtn_VehSpd_Val(data) (*(data) = Rte_BmwVehSpd_VehSpd_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_CtrldVelRtnCmd_Val Rte_Write_CtrldVelRtn_CtrldVelRtnCmd_Val
#  define Rte_Write_CtrldVelRtn_CtrldVelRtnCmd_Val(data) (Rte_CtrldVelRtn_CtrldVelRtnCmd_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

#  define Rte_Prm_CtrldVelRtnAntiWdup_Val() (((P2CONST(Rte_Calprm_CalRegn01CmnGroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnAntiWdup_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_CtrldVelRtnDesVelLpFilFrq_Val() (((P2CONST(Rte_Calprm_CalRegn01Inin00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00GroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnDesVelLpFilFrq_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_CtrldVelRtnHwAuthySlewThd_Val() (((P2CONST(Rte_Calprm_CalRegn01CmnGroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnHwAuthySlewThd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_CtrldVelRtnHwTqLpFilFrq_Val() (((P2CONST(Rte_Calprm_CalRegn01Inin00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00GroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnHwTqLpFilFrq_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_CtrldVelRtnHwTqScaSelnSlewHiLim_Val() (((P2CONST(Rte_Calprm_CalRegn01Inin00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00GroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnHwTqScaSelnSlewHiLim_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_CtrldVelRtnHwTqScaSelnSlewLoLim_Val() (((P2CONST(Rte_Calprm_CalRegn01Inin00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00GroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnHwTqScaSelnSlewLoLim_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_CtrldVelRtnHwTqScaSelnTqThd_Val() (((P2CONST(Rte_Calprm_CalRegn01Inin00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00GroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnHwTqScaSelnTqThd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_CtrldVelRtnHwTqScaSelnVelThd_Val() (((P2CONST(Rte_Calprm_CalRegn01Inin00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00GroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnHwTqScaSelnVelThd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_CtrldVelRtnOffsSlewThd_Val() (((P2CONST(Rte_Calprm_CalRegn01Inin00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00GroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnOffsSlewThd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_CtrldVelRtnOffsThd_Val() (((P2CONST(Rte_Calprm_CalRegn01Inin00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00GroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnOffsThd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_CtrldVelRtnScaLpFilFrq_Val() (((P2CONST(Rte_Calprm_CalRegn01Inin00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00GroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnScaLpFilFrq_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_SysGlbPrmSysTqRat_Val() (((P2CONST(Rte_Calprm_CalRegn01IninOptSetA00_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01IninOptSetA00_DEFAULT_RTE_CALPRM_GROUP])->SysGlbPrmSysTqRat_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_CtrldVelRtnDampgEna_Logl() (((P2CONST(Rte_Calprm_CalRegn01CmnGroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnDampgEna_Logl) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_CtrldVelRtnDampgScaEna_Logl() (((P2CONST(Rte_Calprm_CalRegn01CmnGroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnDampgScaEna_Logl) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_CtrldVelRtnDrvrTqEna_Logl() (((P2CONST(Rte_Calprm_CalRegn01CmnGroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnDrvrTqEna_Logl) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_CtrldVelRtnTqGrdtScaEna_Logl() (((P2CONST(Rte_Calprm_CalRegn01CmnGroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnTqGrdtScaEna_Logl) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_CtrldVelRtnVelErrScaEna_Logl() (((P2CONST(Rte_Calprm_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnVelErrScaEna_Logl) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_CtrldVelRtnDampgX_Ary2D() ((P2CONST(u10p6, AUTOMATIC, RTE_VAR_NOINIT)) &(((P2CONST(Rte_Calprm_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnDampgX_Ary2D[0][0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_CtrldVelRtnDampgX_Ary2D() (&((P2CONST(Rte_Calprm_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnDampgX_Ary2D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_CtrldVelRtnDampgY_Ary2D() ((P2CONST(u6p10, AUTOMATIC, RTE_VAR_NOINIT)) &(((P2CONST(Rte_Calprm_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnDampgY_Ary2D[0][0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_CtrldVelRtnDampgY_Ary2D() (&((P2CONST(Rte_Calprm_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnDampgY_Ary2D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_CtrldVelRtnDesVelScaX_Ary2D() ((P2CONST(u8p8, AUTOMATIC, RTE_VAR_NOINIT)) &(((P2CONST(Rte_Calprm_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnDesVelScaX_Ary2D[0][0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_CtrldVelRtnDesVelScaX_Ary2D() (&((P2CONST(Rte_Calprm_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnDesVelScaX_Ary2D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_CtrldVelRtnDesVelScaY_Ary2D() ((P2CONST(u2p14, AUTOMATIC, RTE_VAR_NOINIT)) &(((P2CONST(Rte_Calprm_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnDesVelScaY_Ary2D[0][0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_CtrldVelRtnDesVelScaY_Ary2D() (&((P2CONST(Rte_Calprm_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnDesVelScaY_Ary2D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_CtrldVelRtnDesVelX_Ary2D() ((P2CONST(u12p4, AUTOMATIC, RTE_VAR_NOINIT)) &(((P2CONST(Rte_Calprm_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnDesVelX_Ary2D[0][0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_CtrldVelRtnDesVelX_Ary2D() (&((P2CONST(Rte_Calprm_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnDesVelX_Ary2D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_CtrldVelRtnDesVelY_Ary2D() ((P2CONST(u10p6, AUTOMATIC, RTE_VAR_NOINIT)) &(((P2CONST(Rte_Calprm_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnDesVelY_Ary2D[0][0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_CtrldVelRtnDesVelY_Ary2D() (&((P2CONST(Rte_Calprm_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnDesVelY_Ary2D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_CtrldVelRtnDrvrTqMtrxA_Ary2D() ((P2CONST(float32, AUTOMATIC, RTE_VAR_NOINIT)) &(((P2CONST(Rte_Calprm_CalRegn01CmnGroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnDrvrTqMtrxA_Ary2D[0][0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_CtrldVelRtnDrvrTqMtrxA_Ary2D() (&((P2CONST(Rte_Calprm_CalRegn01CmnGroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnDrvrTqMtrxA_Ary2D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_CtrldVelRtnDrvrTqMtrxB_Ary2D() ((P2CONST(float32, AUTOMATIC, RTE_VAR_NOINIT)) &(((P2CONST(Rte_Calprm_CalRegn01CmnGroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnDrvrTqMtrxB_Ary2D[0][0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_CtrldVelRtnDrvrTqMtrxB_Ary2D() (&((P2CONST(Rte_Calprm_CalRegn01CmnGroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnDrvrTqMtrxB_Ary2D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_CtrldVelRtnDrvrTqMtrxC_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn01CmnGroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnDrvrTqMtrxC_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_CtrldVelRtnDrvrTqMtrxC_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn01CmnGroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnDrvrTqMtrxC_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_CtrldVelRtnDrvrTqMtrxD_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn01CmnGroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnDrvrTqMtrxD_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_CtrldVelRtnDrvrTqMtrxD_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn01CmnGroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnDrvrTqMtrxD_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_CtrldVelRtnHwAuthyScaX_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn01CmnGroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnHwAuthyScaX_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_CtrldVelRtnHwAuthyScaX_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn01CmnGroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnHwAuthyScaX_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_CtrldVelRtnHwAuthyScaY_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn01CmnGroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnHwAuthyScaY_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_CtrldVelRtnHwAuthyScaY_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn01CmnGroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnHwAuthyScaY_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_CtrldVelRtnHwPosnScaX_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnHwPosnScaX_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_CtrldVelRtnHwPosnScaX_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnHwPosnScaX_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_CtrldVelRtnHwPosnScaY_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnHwPosnScaY_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_CtrldVelRtnHwPosnScaY_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnHwPosnScaY_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_CtrldVelRtnHwTqSca1X_Ary2D() ((P2CONST(u8p8, AUTOMATIC, RTE_VAR_NOINIT)) &(((P2CONST(Rte_Calprm_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnHwTqSca1X_Ary2D[0][0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_CtrldVelRtnHwTqSca1X_Ary2D() (&((P2CONST(Rte_Calprm_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnHwTqSca1X_Ary2D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_CtrldVelRtnHwTqSca1Y_Ary2D() ((P2CONST(u2p14, AUTOMATIC, RTE_VAR_NOINIT)) &(((P2CONST(Rte_Calprm_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnHwTqSca1Y_Ary2D[0][0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_CtrldVelRtnHwTqSca1Y_Ary2D() (&((P2CONST(Rte_Calprm_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnHwTqSca1Y_Ary2D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_CtrldVelRtnHwTqSca2X_Ary2D() ((P2CONST(u8p8, AUTOMATIC, RTE_VAR_NOINIT)) &(((P2CONST(Rte_Calprm_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnHwTqSca2X_Ary2D[0][0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_CtrldVelRtnHwTqSca2X_Ary2D() (&((P2CONST(Rte_Calprm_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnHwTqSca2X_Ary2D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_CtrldVelRtnHwTqSca2Y_Ary2D() ((P2CONST(u2p14, AUTOMATIC, RTE_VAR_NOINIT)) &(((P2CONST(Rte_Calprm_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnHwTqSca2Y_Ary2D[0][0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_CtrldVelRtnHwTqSca2Y_Ary2D() (&((P2CONST(Rte_Calprm_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnHwTqSca2Y_Ary2D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_CtrldVelRtnIntglGain_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnIntglGain_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_CtrldVelRtnIntglGain_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnIntglGain_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_CtrldVelRtnIntgrLimY_Ary2D() ((P2CONST(u6p10, AUTOMATIC, RTE_VAR_NOINIT)) &(((P2CONST(Rte_Calprm_CalRegn01Inin00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00GroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnIntgrLimY_Ary2D[0][0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_CtrldVelRtnIntgrLimY_Ary2D() (&((P2CONST(Rte_Calprm_CalRegn01Inin00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00GroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnIntgrLimY_Ary2D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_CtrldVelRtnPinionTqScaX_Ary2D() ((P2CONST(u8p8, AUTOMATIC, RTE_VAR_NOINIT)) &(((P2CONST(Rte_Calprm_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnPinionTqScaX_Ary2D[0][0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_CtrldVelRtnPinionTqScaX_Ary2D() (&((P2CONST(Rte_Calprm_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnPinionTqScaX_Ary2D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_CtrldVelRtnPinionTqScaY_Ary2D() ((P2CONST(u2p14, AUTOMATIC, RTE_VAR_NOINIT)) &(((P2CONST(Rte_Calprm_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnPinionTqScaY_Ary2D[0][0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_CtrldVelRtnPinionTqScaY_Ary2D() (&((P2CONST(Rte_Calprm_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnPinionTqScaY_Ary2D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_CtrldVelRtnPropGain_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnPropGain_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_CtrldVelRtnPropGain_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnPropGain_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_CtrldVelRtnRtnCmdLimY_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn01CmnGroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnRtnCmdLimY_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_CtrldVelRtnRtnCmdLimY_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn01CmnGroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnRtnCmdLimY_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_CtrldVelRtnTqGrdtScaX_Ary2D() ((P2CONST(u8p8, AUTOMATIC, RTE_VAR_NOINIT)) &(((P2CONST(Rte_Calprm_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnTqGrdtScaX_Ary2D[0][0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_CtrldVelRtnTqGrdtScaX_Ary2D() (&((P2CONST(Rte_Calprm_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnTqGrdtScaX_Ary2D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_CtrldVelRtnTqGrdtScaY_Ary2D() ((P2CONST(u2p14, AUTOMATIC, RTE_VAR_NOINIT)) &(((P2CONST(Rte_Calprm_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnTqGrdtScaY_Ary2D[0][0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_CtrldVelRtnTqGrdtScaY_Ary2D() (&((P2CONST(Rte_Calprm_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnTqGrdtScaY_Ary2D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_CtrldVelRtnVehSpdScaBilnrSeln_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnVehSpdScaBilnrSeln_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_CtrldVelRtnVehSpdScaBilnrSeln_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnVehSpdScaBilnrSeln_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_CtrldVelRtnVelErrScaBilnrSeln_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnVelErrScaBilnrSeln_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_CtrldVelRtnVelErrScaBilnrSeln_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnVelErrScaBilnrSeln_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_CtrldVelRtnVelErrScaX_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnVelErrScaX_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_CtrldVelRtnVelErrScaX_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnVelErrScaX_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_CtrldVelRtnVelErrScaY_Ary2D() ((P2CONST(u2p14, AUTOMATIC, RTE_VAR_NOINIT)) &(((P2CONST(Rte_Calprm_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnVelErrScaY_Ary2D[0][0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_CtrldVelRtnVelErrScaY_Ary2D() (&((P2CONST(Rte_Calprm_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnVelErrScaY_Ary2D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_CtrldVelRtnVelErrVehSpdScaY_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnVelErrVehSpdScaY_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_CtrldVelRtnVelErrVehSpdScaY_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnVelErrVehSpdScaY_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_CtrldVelRtnVelSpdTbl_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnVelSpdTbl_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_CtrldVelRtnVelSpdTbl_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP])->CtrldVelRtnVelSpdTbl_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
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

extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_CtrldVelRtn_PrevDesVel; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_CtrldVelRtn_PrevDrvrTqFildA; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_CtrldVelRtn_PrevDrvrTqFildB; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_CtrldVelRtn_PrevDrvrTqFildC; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_CtrldVelRtn_PrevDrvrTqFildD; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_CtrldVelRtn_PrevDrvrTqFildE; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_CtrldVelRtn_PrevDrvrTqFildF; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_CtrldVelRtn_PrevHwAuthySca; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_CtrldVelRtn_PrevHwTqSeln; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_CtrldVelRtn_PrevIntglTermA; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_CtrldVelRtn_PrevIntglTermB; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_CtrldVelRtn_PrevIntglTermC; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_CtrldVelRtn_PrevRtnOffs; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_CtrldVelRtn_dCtrldVelRtnCtrlSca; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_CtrldVelRtn_dCtrldVelRtnCtrlScaPreFild; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_CtrldVelRtn_dCtrldVelRtnDampgCmd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_CtrldVelRtn_dCtrldVelRtnDesVel; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_CtrldVelRtn_dCtrldVelRtnDesVelSca; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_CtrldVelRtn_dCtrldVelRtnDesVelScaPreFild; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_CtrldVelRtn_dCtrldVelRtnDrvrTqEstimd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_CtrldVelRtn_dCtrldVelRtnDrvrTqFild; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_CtrldVelRtn_dCtrldVelRtnHwAgCmp; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_CtrldVelRtn_dCtrldVelRtnHwAuthySca; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_CtrldVelRtn_dCtrldVelRtnHwPosnSca; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_CtrldVelRtn_dCtrldVelRtnHwTqSca; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_CtrldVelRtn_dCtrldVelRtnHwTqScaSeln; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_CtrldVelRtn_dCtrldVelRtnIntglTermCmd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_CtrldVelRtn_dCtrldVelRtnIntgrLim; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_CtrldVelRtn_dCtrldVelRtnPinionTqSca; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_CtrldVelRtn_dCtrldVelRtnPropTermCmd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_CtrldVelRtn_dCtrldVelRtnRtnCmd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_CtrldVelRtn_dCtrldVelRtnRtnCmdPreLim; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_CtrldVelRtn_dCtrldVelRtnTqGrdt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_CtrldVelRtn_dCtrldVelRtnTqGrdtSca; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_CtrldVelRtn_dCtrldVelRtnVelErrSca; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(Ary1D_f32_5, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_CtrldVelRtn_PrevDrvrTqMtrx; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_CtrldVelRtn_CtrlScaLpFil; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_CtrldVelRtn_DesVelLpFil; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_CtrldVelRtn_DesVelScaLpFil; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_CtrldVelRtn_DrvrTqLpFil; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl7_PIM_GROUP) Rte_CtrldVelRtn_PinionTqLpFil; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Appl7_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  endif

#  define Rte_Pim_PrevDesVel() \
  (&Rte_CtrldVelRtn_PrevDesVel) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_PrevDrvrTqFildA() \
  (&Rte_CtrldVelRtn_PrevDrvrTqFildA) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_PrevDrvrTqFildB() \
  (&Rte_CtrldVelRtn_PrevDrvrTqFildB) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_PrevDrvrTqFildC() \
  (&Rte_CtrldVelRtn_PrevDrvrTqFildC) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_PrevDrvrTqFildD() \
  (&Rte_CtrldVelRtn_PrevDrvrTqFildD) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_PrevDrvrTqFildE() \
  (&Rte_CtrldVelRtn_PrevDrvrTqFildE) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_PrevDrvrTqFildF() \
  (&Rte_CtrldVelRtn_PrevDrvrTqFildF) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_PrevHwAuthySca() \
  (&Rte_CtrldVelRtn_PrevHwAuthySca) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_PrevHwTqSeln() \
  (&Rte_CtrldVelRtn_PrevHwTqSeln) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_PrevIntglTermA() \
  (&Rte_CtrldVelRtn_PrevIntglTermA) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_PrevIntglTermB() \
  (&Rte_CtrldVelRtn_PrevIntglTermB) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_PrevIntglTermC() \
  (&Rte_CtrldVelRtn_PrevIntglTermC) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_PrevRtnOffs() \
  (&Rte_CtrldVelRtn_PrevRtnOffs) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dCtrldVelRtnCtrlSca() \
  (&Rte_CtrldVelRtn_dCtrldVelRtnCtrlSca) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dCtrldVelRtnCtrlScaPreFild() \
  (&Rte_CtrldVelRtn_dCtrldVelRtnCtrlScaPreFild) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dCtrldVelRtnDampgCmd() \
  (&Rte_CtrldVelRtn_dCtrldVelRtnDampgCmd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dCtrldVelRtnDesVel() \
  (&Rte_CtrldVelRtn_dCtrldVelRtnDesVel) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dCtrldVelRtnDesVelSca() \
  (&Rte_CtrldVelRtn_dCtrldVelRtnDesVelSca) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dCtrldVelRtnDesVelScaPreFild() \
  (&Rte_CtrldVelRtn_dCtrldVelRtnDesVelScaPreFild) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dCtrldVelRtnDrvrTqEstimd() \
  (&Rte_CtrldVelRtn_dCtrldVelRtnDrvrTqEstimd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dCtrldVelRtnDrvrTqFild() \
  (&Rte_CtrldVelRtn_dCtrldVelRtnDrvrTqFild) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dCtrldVelRtnHwAgCmp() \
  (&Rte_CtrldVelRtn_dCtrldVelRtnHwAgCmp) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dCtrldVelRtnHwAuthySca() \
  (&Rte_CtrldVelRtn_dCtrldVelRtnHwAuthySca) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dCtrldVelRtnHwPosnSca() \
  (&Rte_CtrldVelRtn_dCtrldVelRtnHwPosnSca) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dCtrldVelRtnHwTqSca() \
  (&Rte_CtrldVelRtn_dCtrldVelRtnHwTqSca) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dCtrldVelRtnHwTqScaSeln() \
  (&Rte_CtrldVelRtn_dCtrldVelRtnHwTqScaSeln) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dCtrldVelRtnIntglTermCmd() \
  (&Rte_CtrldVelRtn_dCtrldVelRtnIntglTermCmd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dCtrldVelRtnIntgrLim() \
  (&Rte_CtrldVelRtn_dCtrldVelRtnIntgrLim) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dCtrldVelRtnPinionTqSca() \
  (&Rte_CtrldVelRtn_dCtrldVelRtnPinionTqSca) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dCtrldVelRtnPropTermCmd() \
  (&Rte_CtrldVelRtn_dCtrldVelRtnPropTermCmd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dCtrldVelRtnRtnCmd() \
  (&Rte_CtrldVelRtn_dCtrldVelRtnRtnCmd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dCtrldVelRtnRtnCmdPreLim() \
  (&Rte_CtrldVelRtn_dCtrldVelRtnRtnCmdPreLim) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dCtrldVelRtnTqGrdt() \
  (&Rte_CtrldVelRtn_dCtrldVelRtnTqGrdt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dCtrldVelRtnTqGrdtSca() \
  (&Rte_CtrldVelRtn_dCtrldVelRtnTqGrdtSca) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dCtrldVelRtnVelErrSca() \
  (&Rte_CtrldVelRtn_dCtrldVelRtnVelErrSca) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_PrevDrvrTqMtrx() (&((*RtePim_PrevDrvrTqMtrx())[0]))
#  else
#   define Rte_Pim_PrevDrvrTqMtrx() RtePim_PrevDrvrTqMtrx()
#  endif
#  define RtePim_PrevDrvrTqMtrx() \
  (&Rte_CtrldVelRtn_PrevDrvrTqMtrx) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_CtrlScaLpFil() \
  (&Rte_CtrldVelRtn_CtrlScaLpFil) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_DesVelLpFil() \
  (&Rte_CtrldVelRtn_DesVelLpFil) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_DesVelScaLpFil() \
  (&Rte_CtrldVelRtn_DesVelScaLpFil) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_DrvrTqLpFil() \
  (&Rte_CtrldVelRtn_DrvrTqLpFil) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_PinionTqLpFil() \
  (&Rte_CtrldVelRtn_PinionTqLpFil) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define CtrldVelRtn_START_SEC_CODE
# include "CtrldVelRtn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_CtrldVelRtnInit1 CtrldVelRtnInit1
#  define RTE_RUNNABLE_CtrldVelRtnPer1 CtrldVelRtnPer1
# endif

FUNC(void, CtrldVelRtn_CODE) CtrldVelRtnInit1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtrldVelRtn_CODE) CtrldVelRtnPer1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define CtrldVelRtn_STOP_SEC_CODE
# include "CtrldVelRtn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CTRLDVELRTN_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
