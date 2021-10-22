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
 *          File:  Rte_BmwTqOvrlCdngAndDrvgDynFac.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <BmwTqOvrlCdngAndDrvgDynFac>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_BMWTQOVRLCDNGANDDRVGDYNFAC_H
# define _RTE_BMWTQOVRLCDNGANDDRVGDYNFAC_H

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

# include "Rte_BmwTqOvrlCdngAndDrvgDynFac_Type.h"
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

extern VAR(float32, RTE_VAR_INIT) Rte_BmwTqOvrlCdngAndDrvgDynFac_BmwOutpTqOvrlCmd_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwTqOvrlCdngAndDrvgDynFac_DampgCmdSca_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwTqOvrlCdngAndDrvgDynFac_EffortCmdSca_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwTqOvrlCdngAndDrvgDynFac_RtnCmdSca_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynDampgFacReq_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynEffortFacReq_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynErrIfActv_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynRtnFacReq_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwSwFctDi_BmwOutpTqOvrlCmdEna_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTarSteerTqDrvrActr_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwDrvgDynStMac_DrvgDynActv_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwSwFctDi_DrvgDynFacEna_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(DrvgDynIfSt1, RTE_VAR_INIT) Rte_BmwDrvgDynStMac_DrvgDynIfSt_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_HwTqArbn_HwTq_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_MotVel_MotVelCrf_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwDrvgDynStMac_OutpTqOvrlRampInEna_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_BmwDrvgDynDampgFacReq_Val (1.0F)
#  define Rte_InitValue_BmwDrvgDynEffortFacReq_Val (1.0F)
#  define Rte_InitValue_BmwDrvgDynErrIfActv_Logl (FALSE)
#  define Rte_InitValue_BmwDrvgDynRtnFacReq_Val (1.0F)
#  define Rte_InitValue_BmwOutpTqOvrlCmd_Val (0.0F)
#  define Rte_InitValue_BmwOutpTqOvrlCmdEna_Logl (TRUE)
#  define Rte_InitValue_BmwTarSteerTqDrvrActr_Val (0.0F)
#  define Rte_InitValue_DampgCmdSca_Val (1.0F)
#  define Rte_InitValue_DrvgDynActv_Logl (FALSE)
#  define Rte_InitValue_DrvgDynFacEna_Logl (TRUE)
#  define Rte_InitValue_DrvgDynIfSt_Val (128U)
#  define Rte_InitValue_EffortCmdSca_Val (1.0F)
#  define Rte_InitValue_HwTq_Val (0.0F)
#  define Rte_InitValue_MotVelCrf_Val (0.0F)
#  define Rte_InitValue_OutpTqOvrlRampInEna_Logl (FALSE)
#  define Rte_InitValue_RtnCmdSca_Val (1.0F)
#  define Rte_InitValue_VehSpd_Val (0.0F)
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_BmwDrvgDynDampgFacReq_Val Rte_Read_BmwTqOvrlCdngAndDrvgDynFac_BmwDrvgDynDampgFacReq_Val
#  define Rte_Read_BmwTqOvrlCdngAndDrvgDynFac_BmwDrvgDynDampgFacReq_Val(data) (*(data) = Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynDampgFacReq_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BmwDrvgDynEffortFacReq_Val Rte_Read_BmwTqOvrlCdngAndDrvgDynFac_BmwDrvgDynEffortFacReq_Val
#  define Rte_Read_BmwTqOvrlCdngAndDrvgDynFac_BmwDrvgDynEffortFacReq_Val(data) (*(data) = Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynEffortFacReq_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BmwDrvgDynErrIfActv_Logl Rte_Read_BmwTqOvrlCdngAndDrvgDynFac_BmwDrvgDynErrIfActv_Logl
#  define Rte_Read_BmwTqOvrlCdngAndDrvgDynFac_BmwDrvgDynErrIfActv_Logl(data) (*(data) = Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynErrIfActv_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BmwDrvgDynRtnFacReq_Val Rte_Read_BmwTqOvrlCdngAndDrvgDynFac_BmwDrvgDynRtnFacReq_Val
#  define Rte_Read_BmwTqOvrlCdngAndDrvgDynFac_BmwDrvgDynRtnFacReq_Val(data) (*(data) = Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynRtnFacReq_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BmwOutpTqOvrlCmdEna_Logl Rte_Read_BmwTqOvrlCdngAndDrvgDynFac_BmwOutpTqOvrlCmdEna_Logl
#  define Rte_Read_BmwTqOvrlCdngAndDrvgDynFac_BmwOutpTqOvrlCmdEna_Logl(data) (*(data) = Rte_BmwSwFctDi_BmwOutpTqOvrlCmdEna_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BmwTarSteerTqDrvrActr_Val Rte_Read_BmwTqOvrlCdngAndDrvgDynFac_BmwTarSteerTqDrvrActr_Val
#  define Rte_Read_BmwTqOvrlCdngAndDrvgDynFac_BmwTarSteerTqDrvrActr_Val(data) (*(data) = Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTarSteerTqDrvrActr_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_DrvgDynActv_Logl Rte_Read_BmwTqOvrlCdngAndDrvgDynFac_DrvgDynActv_Logl
#  define Rte_Read_BmwTqOvrlCdngAndDrvgDynFac_DrvgDynActv_Logl(data) (*(data) = Rte_BmwDrvgDynStMac_DrvgDynActv_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_DrvgDynFacEna_Logl Rte_Read_BmwTqOvrlCdngAndDrvgDynFac_DrvgDynFacEna_Logl
#  define Rte_Read_BmwTqOvrlCdngAndDrvgDynFac_DrvgDynFacEna_Logl(data) (*(data) = Rte_BmwSwFctDi_DrvgDynFacEna_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_DrvgDynIfSt_Val Rte_Read_BmwTqOvrlCdngAndDrvgDynFac_DrvgDynIfSt_Val
#  define Rte_Read_BmwTqOvrlCdngAndDrvgDynFac_DrvgDynIfSt_Val(data) (*(data) = Rte_BmwDrvgDynStMac_DrvgDynIfSt_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_HwTq_Val Rte_Read_BmwTqOvrlCdngAndDrvgDynFac_HwTq_Val
#  define Rte_Read_BmwTqOvrlCdngAndDrvgDynFac_HwTq_Val(data) (*(data) = Rte_HwTqArbn_HwTq_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotVelCrf_Val Rte_Read_BmwTqOvrlCdngAndDrvgDynFac_MotVelCrf_Val
#  define Rte_Read_BmwTqOvrlCdngAndDrvgDynFac_MotVelCrf_Val(data) (*(data) = Rte_CDD_MotVel_MotVelCrf_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_OutpTqOvrlRampInEna_Logl Rte_Read_BmwTqOvrlCdngAndDrvgDynFac_OutpTqOvrlRampInEna_Logl
#  define Rte_Read_BmwTqOvrlCdngAndDrvgDynFac_OutpTqOvrlRampInEna_Logl(data) (*(data) = Rte_BmwDrvgDynStMac_OutpTqOvrlRampInEna_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_VehSpd_Val Rte_Read_BmwTqOvrlCdngAndDrvgDynFac_VehSpd_Val
#  define Rte_Read_BmwTqOvrlCdngAndDrvgDynFac_VehSpd_Val(data) (*(data) = Rte_BmwVehSpd_VehSpd_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_BmwOutpTqOvrlCmd_Val Rte_Write_BmwTqOvrlCdngAndDrvgDynFac_BmwOutpTqOvrlCmd_Val
#  define Rte_Write_BmwTqOvrlCdngAndDrvgDynFac_BmwOutpTqOvrlCmd_Val(data) (Rte_BmwTqOvrlCdngAndDrvgDynFac_BmwOutpTqOvrlCmd_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_DampgCmdSca_Val Rte_Write_BmwTqOvrlCdngAndDrvgDynFac_DampgCmdSca_Val
#  define Rte_Write_BmwTqOvrlCdngAndDrvgDynFac_DampgCmdSca_Val(data) (Rte_BmwTqOvrlCdngAndDrvgDynFac_DampgCmdSca_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_EffortCmdSca_Val Rte_Write_BmwTqOvrlCdngAndDrvgDynFac_EffortCmdSca_Val
#  define Rte_Write_BmwTqOvrlCdngAndDrvgDynFac_EffortCmdSca_Val(data) (Rte_BmwTqOvrlCdngAndDrvgDynFac_EffortCmdSca_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_RtnCmdSca_Val Rte_Write_BmwTqOvrlCdngAndDrvgDynFac_RtnCmdSca_Val
#  define Rte_Write_BmwTqOvrlCdngAndDrvgDynFac_RtnCmdSca_Val(data) (Rte_BmwTqOvrlCdngAndDrvgDynFac_RtnCmdSca_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_FLTINJ_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_FLTINJ_APPL_CODE) FltInj_f32_Oper(P2VAR(float32, AUTOMATIC, RTE_FLTINJ_APPL_VAR) SigPah_Arg, uint16 LocnKey_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_FLTINJ_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_FltInj_f32_Oper(arg1, arg2) (FltInj_f32_Oper(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
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

#  define Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacActvDampgSlewRate_Val() (((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwTqOvrlCdngAndDrvgDynFacActvDampgSlewRate_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacActvEffortSlewRate_Val() (((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwTqOvrlCdngAndDrvgDynFacActvEffortSlewRate_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacActvRtnSlewRate_Val() (((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwTqOvrlCdngAndDrvgDynFacActvRtnSlewRate_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacInactvDampgSlewRate_Val() (((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwTqOvrlCdngAndDrvgDynFacInactvDampgSlewRate_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacInactvEffortSlewRate_Val() (((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwTqOvrlCdngAndDrvgDynFacInactvEffortSlewRate_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacInactvRtnSlewRate_Val() (((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwTqOvrlCdngAndDrvgDynFacInactvRtnSlewRate_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacOutpTqOvrlSlew_Val() (((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwTqOvrlCdngAndDrvgDynFacOutpTqOvrlSlew_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacReqdRtnCmdScaLoLim_Val() (((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwTqOvrlCdngAndDrvgDynFacReqdRtnCmdScaLoLim_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrLpFilFrq_Val() (((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrLpFilFrq_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacDampgScaLoLimX_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwTqOvrlCdngAndDrvgDynFacDampgScaLoLimX_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacDampgScaLoLimX_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwTqOvrlCdngAndDrvgDynFacDampgScaLoLimX_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacDampgScaLoLimY_Ary2D() ((P2CONST(u1p15, AUTOMATIC, RTE_VAR_NOINIT)) &(((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwTqOvrlCdngAndDrvgDynFacDampgScaLoLimY_Ary2D[0][0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacDampgScaLoLimY_Ary2D() (&((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwTqOvrlCdngAndDrvgDynFacDampgScaLoLimY_Ary2D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacEffortScaHiLimX_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwTqOvrlCdngAndDrvgDynFacEffortScaHiLimX_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacEffortScaHiLimX_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwTqOvrlCdngAndDrvgDynFacEffortScaHiLimX_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacEffortScaHiLimY_Ary2D() ((P2CONST(u2p14, AUTOMATIC, RTE_VAR_NOINIT)) &(((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwTqOvrlCdngAndDrvgDynFacEffortScaHiLimY_Ary2D[0][0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacEffortScaHiLimY_Ary2D() (&((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwTqOvrlCdngAndDrvgDynFacEffortScaHiLimY_Ary2D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrMaxY_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrMaxY_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrMaxY_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrMaxY_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrSpdX_Ary1D() (&(((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrSpdX_Ary1D[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrSpdX_Ary1D() (&((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrSpdX_Ary1D) /* PRQA S 3453 */ /* MD_MSR_19.7 */
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
#   define RTE_START_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwTqOvrlCdngAndDrvgDynFac_BmwOutpTqOvrlCmdStVari; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwTqOvrlCdngAndDrvgDynFac_DampgCmdScaRateLimrStVari; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwTqOvrlCdngAndDrvgDynFac_EffortCmdScaRateLimrStVari; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwTqOvrlCdngAndDrvgDynFac_FrznBmwTarSteerTqDrvrActr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwTqOvrlCdngAndDrvgDynFac_LimdCdndTqOvrl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwTqOvrlCdngAndDrvgDynFac_RtnCmdScaRateLimrStVari; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwTqOvrlCdngAndDrvgDynFac_MsgCycTmr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(DrvgDynIfSt1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwTqOvrlCdngAndDrvgDynFac_PrevDrvgDynIfSt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwTqOvrlCdngAndDrvgDynFac_BmwOutpTqOvrlCmdRampCmpl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwTqOvrlCdngAndDrvgDynFac_FrznSigActv; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwTqOvrlCdngAndDrvgDynFac_PrevDampgSlewInProgs; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwTqOvrlCdngAndDrvgDynFac_PrevDrvgDynActv; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwTqOvrlCdngAndDrvgDynFac_PrevEffortSlewInProgs; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwTqOvrlCdngAndDrvgDynFac_PrevRtnSlewInProgs; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwTqOvrlCdngAndDrvgDynFac_RampToZeroEnad; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwTqOvrlCdngAndDrvgDynFac_BmwTarSteerTqDrvrActrLpFilStVari; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  endif

#  define Rte_Pim_BmwOutpTqOvrlCmdStVari() \
  (&Rte_BmwTqOvrlCdngAndDrvgDynFac_BmwOutpTqOvrlCmdStVari) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_DampgCmdScaRateLimrStVari() \
  (&Rte_BmwTqOvrlCdngAndDrvgDynFac_DampgCmdScaRateLimrStVari) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_EffortCmdScaRateLimrStVari() \
  (&Rte_BmwTqOvrlCdngAndDrvgDynFac_EffortCmdScaRateLimrStVari) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_FrznBmwTarSteerTqDrvrActr() \
  (&Rte_BmwTqOvrlCdngAndDrvgDynFac_FrznBmwTarSteerTqDrvrActr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_LimdCdndTqOvrl() \
  (&Rte_BmwTqOvrlCdngAndDrvgDynFac_LimdCdndTqOvrl) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_RtnCmdScaRateLimrStVari() \
  (&Rte_BmwTqOvrlCdngAndDrvgDynFac_RtnCmdScaRateLimrStVari) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MsgCycTmr() \
  (&Rte_BmwTqOvrlCdngAndDrvgDynFac_MsgCycTmr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_PrevDrvgDynIfSt() \
  (&Rte_BmwTqOvrlCdngAndDrvgDynFac_PrevDrvgDynIfSt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_BmwOutpTqOvrlCmdRampCmpl() \
  (&Rte_BmwTqOvrlCdngAndDrvgDynFac_BmwOutpTqOvrlCmdRampCmpl) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_FrznSigActv() \
  (&Rte_BmwTqOvrlCdngAndDrvgDynFac_FrznSigActv) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_PrevDampgSlewInProgs() \
  (&Rte_BmwTqOvrlCdngAndDrvgDynFac_PrevDampgSlewInProgs) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_PrevDrvgDynActv() \
  (&Rte_BmwTqOvrlCdngAndDrvgDynFac_PrevDrvgDynActv) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_PrevEffortSlewInProgs() \
  (&Rte_BmwTqOvrlCdngAndDrvgDynFac_PrevEffortSlewInProgs) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_PrevRtnSlewInProgs() \
  (&Rte_BmwTqOvrlCdngAndDrvgDynFac_PrevRtnSlewInProgs) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_RampToZeroEnad() \
  (&Rte_BmwTqOvrlCdngAndDrvgDynFac_RampToZeroEnad) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_BmwTarSteerTqDrvrActrLpFilStVari() \
  (&Rte_BmwTqOvrlCdngAndDrvgDynFac_BmwTarSteerTqDrvrActrLpFilStVari) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define BmwTqOvrlCdngAndDrvgDynFac_START_SEC_CODE
# include "BmwTqOvrlCdngAndDrvgDynFac_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_BmwTqOvrlCdngAndDrvgDynFacInit1 BmwTqOvrlCdngAndDrvgDynFacInit1
#  define RTE_RUNNABLE_BmwTqOvrlCdngAndDrvgDynFacPer1 BmwTqOvrlCdngAndDrvgDynFacPer1
# endif

FUNC(void, BmwTqOvrlCdngAndDrvgDynFac_CODE) BmwTqOvrlCdngAndDrvgDynFacInit1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, BmwTqOvrlCdngAndDrvgDynFac_CODE) BmwTqOvrlCdngAndDrvgDynFacPer1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define BmwTqOvrlCdngAndDrvgDynFac_STOP_SEC_CODE
# include "BmwTqOvrlCdngAndDrvgDynFac_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_BMWTQOVRLCDNGANDDRVGDYNFAC_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
