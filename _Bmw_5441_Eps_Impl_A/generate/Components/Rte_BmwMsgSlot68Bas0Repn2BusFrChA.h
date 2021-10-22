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
 *          File:  Rte_BmwMsgSlot68Bas0Repn2BusFrChA.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <BmwMsgSlot68Bas0Repn2BusFrChA>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_BMWMSGSLOT68BAS0REPN2BUSFRCHA_H
# define _RTE_BMWMSGSLOT68BAS0REPN2BUSFRCHA_H

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

# include "Rte_BmwMsgSlot68Bas0Repn2BusFrChA_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_INIT) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynDampgFacReq_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynEffortFacReq_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynEnaRqst_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynErrIfActv_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(BmwOvrlCmdQlfr1, RTE_VAR_INIT) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynFacQlfr_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynFacQlfrVld_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynRtnFacReq_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTarHwTqOvrl_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(BmwOvrlCmdQlfr1, RTE_VAR_INIT) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTarHwTqOvrlQlfr_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTarHwTqOvrlQlfrVld_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTarSteerTqDrvrActr_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(BmwOvrlCmdQlfr1, RTE_VAR_INIT) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTarSteerTqDrvrActrQlfr_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTarSteerTqDrvrActrQlfrVld_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTrfcJamAssiDampgScaReq_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTrfcJamAssiDampgScaReqVld_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(BmwTrfcJamAssiDampgStReq1, RTE_VAR_INIT) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTrfcJamAssiDampgStReq_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTrfcJamAssiDampgStReqVld_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_FltCodEnad_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_BmwDrvgDynDampgFacReq_Val (1.0F)
#  define Rte_InitValue_BmwDrvgDynDampgFacReqVld_Logl (FALSE)
#  define Rte_InitValue_BmwDrvgDynEffortFacReq_Val (1.0F)
#  define Rte_InitValue_BmwDrvgDynEffortFacReqVld_Logl (FALSE)
#  define Rte_InitValue_BmwDrvgDynEnaRqst_Logl (FALSE)
#  define Rte_InitValue_BmwDrvgDynErrIfActv_Logl (FALSE)
#  define Rte_InitValue_BmwDrvgDynFacQlfr_Val (15U)
#  define Rte_InitValue_BmwDrvgDynFacQlfrVld_Logl (FALSE)
#  define Rte_InitValue_BmwDrvgDynRtnFacReq_Val (1.0F)
#  define Rte_InitValue_BmwDrvgDynRtnFacReqVld_Logl (FALSE)
#  define Rte_InitValue_BmwEpsDeactvnCtrl_Val (15U)
#  define Rte_InitValue_BmwEpsDeactvnCtrlVld_Logl (FALSE)
#  define Rte_InitValue_BmwTarHwTqOvrl_Val (0.0F)
#  define Rte_InitValue_BmwTarHwTqOvrlQlfr_Val (15U)
#  define Rte_InitValue_BmwTarHwTqOvrlQlfrVld_Logl (FALSE)
#  define Rte_InitValue_BmwTarHwTqOvrlVld_Logl (FALSE)
#  define Rte_InitValue_BmwTarSteerTqDrvrActr_Val (0.0F)
#  define Rte_InitValue_BmwTarSteerTqDrvrActrQlfr_Val (15U)
#  define Rte_InitValue_BmwTarSteerTqDrvrActrQlfrVld_Logl (FALSE)
#  define Rte_InitValue_BmwTarSteerTqDrvrActrVld_Logl (FALSE)
#  define Rte_InitValue_BmwTrfcJamAssiDampgScaReq_Val (0.0F)
#  define Rte_InitValue_BmwTrfcJamAssiDampgScaReqVld_Logl (FALSE)
#  define Rte_InitValue_BmwTrfcJamAssiDampgStReq_Val (1U)
#  define Rte_InitValue_BmwTrfcJamAssiDampgStReqVld_Logl (FALSE)
#  define Rte_InitValue_FltCodEnad_Logl (TRUE)
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwMsgSlot68Bas0Repn2BusFrChA_sigGroup_TAR_QTA_STRMOM_DV_sigGroup_TAR_QTA_STRMOM_DV(P2VAR(sigGroup_TAR_QTA_STRMOM_DV1, AUTOMATIC, RTE_BMWMSGSLOT68BAS0REPN2BUSFRCHA_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwMsgSlot68Bas0Repn2BusFrChA_sigGroup_TAR_STMOM_DV_ACT_sigGroup_TAR_STMOM_DV_ACT(P2VAR(sigGroup_TAR_STMOM_DV_ACT1, AUTOMATIC, RTE_BMWMSGSLOT68BAS0REPN2BUSFRCHA_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_FltCodEnad_Logl Rte_Read_BmwMsgSlot68Bas0Repn2BusFrChA_FltCodEnad_Logl
#  define Rte_Read_BmwMsgSlot68Bas0Repn2BusFrChA_FltCodEnad_Logl(data) (*(data) = Rte_BmwMsgSlot68Bas0Repn2BusFrChA_FltCodEnad_Logl, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_sigGroup_TAR_QTA_STRMOM_DV_sigGroup_TAR_QTA_STRMOM_DV Rte_Read_BmwMsgSlot68Bas0Repn2BusFrChA_sigGroup_TAR_QTA_STRMOM_DV_sigGroup_TAR_QTA_STRMOM_DV
#  define Rte_Read_sigGroup_TAR_STMOM_DV_ACT_sigGroup_TAR_STMOM_DV_ACT Rte_Read_BmwMsgSlot68Bas0Repn2BusFrChA_sigGroup_TAR_STMOM_DV_ACT_sigGroup_TAR_STMOM_DV_ACT


/**********************************************************************************************************************
 * Rte_IsUpdated_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_IsUpdated_sigGroup_TAR_QTA_STRMOM_DV_sigGroup_TAR_QTA_STRMOM_DV Rte_IsUpdated_BmwMsgSlot68Bas0Repn2BusFrChA_sigGroup_TAR_QTA_STRMOM_DV_sigGroup_TAR_QTA_STRMOM_DV
#  define Rte_IsUpdated_BmwMsgSlot68Bas0Repn2BusFrChA_sigGroup_TAR_QTA_STRMOM_DV_sigGroup_TAR_QTA_STRMOM_DV() ((Rte_Appl10_RxUpdateFlags.Rte_RxUpdate_BmwMsgSlot68Bas0Repn2BusFrChA_sigGroup_TAR_QTA_STRMOM_DV_sigGroup_TAR_QTA_STRMOM_DV == Rte_Appl10_RxUpdateFlags.Rte_RxUpdate_BmwMsgSlot68Bas0Repn2BusFrChA_sigGroup_TAR_QTA_STRMOM_DV_sigGroup_TAR_QTA_STRMOM_DV_Sender) ? FALSE : TRUE) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_IsUpdated_sigGroup_TAR_STMOM_DV_ACT_sigGroup_TAR_STMOM_DV_ACT Rte_IsUpdated_BmwMsgSlot68Bas0Repn2BusFrChA_sigGroup_TAR_STMOM_DV_ACT_sigGroup_TAR_STMOM_DV_ACT
#  define Rte_IsUpdated_BmwMsgSlot68Bas0Repn2BusFrChA_sigGroup_TAR_STMOM_DV_ACT_sigGroup_TAR_STMOM_DV_ACT() ((Rte_Appl10_RxUpdateFlags.Rte_RxUpdate_BmwMsgSlot68Bas0Repn2BusFrChA_sigGroup_TAR_STMOM_DV_ACT_sigGroup_TAR_STMOM_DV_ACT == Rte_Appl10_RxUpdateFlags.Rte_RxUpdate_BmwMsgSlot68Bas0Repn2BusFrChA_sigGroup_TAR_STMOM_DV_ACT_sigGroup_TAR_STMOM_DV_ACT_Sender) ? FALSE : TRUE) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_BmwDrvgDynDampgFacReq_Val Rte_Write_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynDampgFacReq_Val
#  define Rte_Write_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynDampgFacReq_Val(data) (Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynDampgFacReq_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_BmwDrvgDynEffortFacReq_Val Rte_Write_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynEffortFacReq_Val
#  define Rte_Write_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynEffortFacReq_Val(data) (Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynEffortFacReq_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_BmwDrvgDynEnaRqst_Logl Rte_Write_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynEnaRqst_Logl
#  define Rte_Write_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynEnaRqst_Logl(data) (Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynEnaRqst_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_BmwDrvgDynErrIfActv_Logl Rte_Write_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynErrIfActv_Logl
#  define Rte_Write_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynErrIfActv_Logl(data) (Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynErrIfActv_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_BmwDrvgDynFacQlfr_Val Rte_Write_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynFacQlfr_Val
#  define Rte_Write_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynFacQlfr_Val(data) (Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynFacQlfr_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_BmwDrvgDynFacQlfrVld_Logl Rte_Write_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynFacQlfrVld_Logl
#  define Rte_Write_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynFacQlfrVld_Logl(data) (Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynFacQlfrVld_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_BmwDrvgDynRtnFacReq_Val Rte_Write_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynRtnFacReq_Val
#  define Rte_Write_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynRtnFacReq_Val(data) (Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynRtnFacReq_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_BmwEpsDeactvnCtrl_Val Rte_Write_BmwMsgSlot68Bas0Repn2BusFrChA_BmwEpsDeactvnCtrl_Val
#  define Rte_Write_BmwMsgSlot68Bas0Repn2BusFrChA_BmwEpsDeactvnCtrl_Val(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_BmwTarHwTqOvrl_Val Rte_Write_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTarHwTqOvrl_Val
#  define Rte_Write_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTarHwTqOvrl_Val(data) (Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTarHwTqOvrl_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_BmwTarHwTqOvrlQlfr_Val Rte_Write_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTarHwTqOvrlQlfr_Val
#  define Rte_Write_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTarHwTqOvrlQlfr_Val(data) (Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTarHwTqOvrlQlfr_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_BmwTarHwTqOvrlQlfrVld_Logl Rte_Write_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTarHwTqOvrlQlfrVld_Logl
#  define Rte_Write_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTarHwTqOvrlQlfrVld_Logl(data) (Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTarHwTqOvrlQlfrVld_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_BmwTarSteerTqDrvrActr_Val Rte_Write_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTarSteerTqDrvrActr_Val
#  define Rte_Write_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTarSteerTqDrvrActr_Val(data) (Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTarSteerTqDrvrActr_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_BmwTarSteerTqDrvrActrQlfr_Val Rte_Write_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTarSteerTqDrvrActrQlfr_Val
#  define Rte_Write_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTarSteerTqDrvrActrQlfr_Val(data) (Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTarSteerTqDrvrActrQlfr_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_BmwTarSteerTqDrvrActrQlfrVld_Logl Rte_Write_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTarSteerTqDrvrActrQlfrVld_Logl
#  define Rte_Write_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTarSteerTqDrvrActrQlfrVld_Logl(data) (Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTarSteerTqDrvrActrQlfrVld_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_BmwTrfcJamAssiDampgScaReq_Val Rte_Write_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTrfcJamAssiDampgScaReq_Val
#  define Rte_Write_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTrfcJamAssiDampgScaReq_Val(data) (Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTrfcJamAssiDampgScaReq_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_BmwTrfcJamAssiDampgScaReqVld_Logl Rte_Write_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTrfcJamAssiDampgScaReqVld_Logl
#  define Rte_Write_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTrfcJamAssiDampgScaReqVld_Logl(data) (Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTrfcJamAssiDampgScaReqVld_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_BmwTrfcJamAssiDampgStReq_Val Rte_Write_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTrfcJamAssiDampgStReq_Val
#  define Rte_Write_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTrfcJamAssiDampgStReq_Val(data) (Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTrfcJamAssiDampgStReq_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_BmwTrfcJamAssiDampgStReqVld_Logl Rte_Write_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTrfcJamAssiDampgStReqVld_Logl
#  define Rte_Write_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTrfcJamAssiDampgStReqVld_Logl(data) (Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTrfcJamAssiDampgStReqVld_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_DIAGCMGRPROXYAPPL10_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_DIAGCMGRPROXYAPPL10_APPL_CODE) SetNtcSts10_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DIAGCMGRPROXYAPPL10_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_SetNtcSts_Oper SetNtcSts10_Oper


/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

#  define Rte_Prm_BmwMsgSlot108Bas0Repn2BusFrChABmwSteerPolarity_Val() (-1) /* PRQA S 3453 */ /* MD_MSR_19.7 */

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynDampgFacReqPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynEffortFacReqPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynRtnFacReqPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTarHwTqOvrlPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTarSteerTqDrvrActrPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTrfcJamAssiDampgScaReqPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(BmwOvrlCmdQlfr1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynFacQlfrPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(BmwEpsDeactvnCtrl1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwEpsDeactvnCtrlPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(BmwOvrlCmdQlfr1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTarHwTqOvrlQlfPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(BmwOvrlCmdQlfr1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTarSteerTqDrvrActrQlfrPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(BmwTrfcJamAssiDampgStReq1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTrfcJamAssiDampgStReqPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_CtrDeacEpsFnsFaild; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_CtrDeacEpsFnsPassd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_FactAssStmomFtaxFaild; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_FactAssStmomFtaxPassd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_FactCtrrStmomFtaxFaild; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_FactCtrrStmomFtaxPassd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_FactDmpngAddonStmomFtaxFaild; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_FactDmpngAddonStmomFtaxPassd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_FactDmpngStmomFtaxFaild; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_FactDmpngStmomFtaxPassd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_QuTarDmpngAddonStmomFtaxFaild; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_QuTarDmpngAddonStmomFtaxPassd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_QuTarFactStmomFtaxFaild; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_QuTarFactStmomFtaxPassd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_QuTarQtaStmomDvFaild; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_QuTarQtaStmomDvPassd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_QuTarStmomDvActFaild; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_QuTarStmomDvActPassd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_TarQtaStmomDvFaild; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_TarQtaStmomDvPassd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_TarQtaStrmomDvAliveCntFaild; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_TarQtaStrmomDvAliveCntPassd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_TarQtaStrmomDvCRCFaild; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_TarQtaStrmomDvCRCPassd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_TarQtaStrmomDvMissFaild; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_TarQtaStrmomDvMissPassd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_TarStmomDvActAliveCntFaild; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_TarStmomDvActAliveCntPassd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_TarStmomDvActCrcFaild; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_TarStmomDvActCrcPassd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_TarStmomDvActFaild; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_TarStmomDvActMissFaild; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_TarStmomDvActMissPassd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_TarStmomDvActPassd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynDampgFacReqVldPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynEffortFacReqVldPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynEnaReqPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynErrIfActvPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynFacQlfrVldPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynRtnFacReqVldPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwEpsDeactvnCtrlVldPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTarHwTqOvrlQlfrVldPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTarHwTqOvrlVldPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTarSteerTqDrvrActrQlfrVldPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTarSteerTqDrvrActrVldPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTrfcJamAssiDampgScaReqVldPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTrfcJamAssiDampgStReqVldPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_TarQtaStrmomDvArcVld; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_TarQtaStrmomDvMsgProcd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_TarQtaStrmomDvMsgVld; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_TarStmomDvActArcVld; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_TarStmomDvActMsgProcd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_TarStmomDvActMsgVld; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  endif

#  define Rte_Pim_BmwDrvgDynDampgFacReqPrev() \
  (&Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynDampgFacReqPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_BmwDrvgDynEffortFacReqPrev() \
  (&Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynEffortFacReqPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_BmwDrvgDynRtnFacReqPrev() \
  (&Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynRtnFacReqPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_BmwTarHwTqOvrlPrev() \
  (&Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTarHwTqOvrlPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_BmwTarSteerTqDrvrActrPrev() \
  (&Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTarSteerTqDrvrActrPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_BmwTrfcJamAssiDampgScaReqPrev() \
  (&Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTrfcJamAssiDampgScaReqPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_BmwDrvgDynFacQlfrPrev() \
  (&Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynFacQlfrPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_BmwEpsDeactvnCtrlPrev() \
  (&Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwEpsDeactvnCtrlPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_BmwTarHwTqOvrlQlfPrev() \
  (&Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTarHwTqOvrlQlfPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_BmwTarSteerTqDrvrActrQlfrPrev() \
  (&Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTarSteerTqDrvrActrQlfrPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_BmwTrfcJamAssiDampgStReqPrev() \
  (&Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTrfcJamAssiDampgStReqPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_CtrDeacEpsFnsFaild() \
  (&Rte_BmwMsgSlot68Bas0Repn2BusFrChA_CtrDeacEpsFnsFaild) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_CtrDeacEpsFnsPassd() \
  (&Rte_BmwMsgSlot68Bas0Repn2BusFrChA_CtrDeacEpsFnsPassd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_FactAssStmomFtaxFaild() \
  (&Rte_BmwMsgSlot68Bas0Repn2BusFrChA_FactAssStmomFtaxFaild) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_FactAssStmomFtaxPassd() \
  (&Rte_BmwMsgSlot68Bas0Repn2BusFrChA_FactAssStmomFtaxPassd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_FactCtrrStmomFtaxFaild() \
  (&Rte_BmwMsgSlot68Bas0Repn2BusFrChA_FactCtrrStmomFtaxFaild) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_FactCtrrStmomFtaxPassd() \
  (&Rte_BmwMsgSlot68Bas0Repn2BusFrChA_FactCtrrStmomFtaxPassd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_FactDmpngAddonStmomFtaxFaild() \
  (&Rte_BmwMsgSlot68Bas0Repn2BusFrChA_FactDmpngAddonStmomFtaxFaild) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_FactDmpngAddonStmomFtaxPassd() \
  (&Rte_BmwMsgSlot68Bas0Repn2BusFrChA_FactDmpngAddonStmomFtaxPassd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_FactDmpngStmomFtaxFaild() \
  (&Rte_BmwMsgSlot68Bas0Repn2BusFrChA_FactDmpngStmomFtaxFaild) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_FactDmpngStmomFtaxPassd() \
  (&Rte_BmwMsgSlot68Bas0Repn2BusFrChA_FactDmpngStmomFtaxPassd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_QuTarDmpngAddonStmomFtaxFaild() \
  (&Rte_BmwMsgSlot68Bas0Repn2BusFrChA_QuTarDmpngAddonStmomFtaxFaild) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_QuTarDmpngAddonStmomFtaxPassd() \
  (&Rte_BmwMsgSlot68Bas0Repn2BusFrChA_QuTarDmpngAddonStmomFtaxPassd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_QuTarFactStmomFtaxFaild() \
  (&Rte_BmwMsgSlot68Bas0Repn2BusFrChA_QuTarFactStmomFtaxFaild) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_QuTarFactStmomFtaxPassd() \
  (&Rte_BmwMsgSlot68Bas0Repn2BusFrChA_QuTarFactStmomFtaxPassd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_QuTarQtaStmomDvFaild() \
  (&Rte_BmwMsgSlot68Bas0Repn2BusFrChA_QuTarQtaStmomDvFaild) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_QuTarQtaStmomDvPassd() \
  (&Rte_BmwMsgSlot68Bas0Repn2BusFrChA_QuTarQtaStmomDvPassd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_QuTarStmomDvActFaild() \
  (&Rte_BmwMsgSlot68Bas0Repn2BusFrChA_QuTarStmomDvActFaild) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_QuTarStmomDvActPassd() \
  (&Rte_BmwMsgSlot68Bas0Repn2BusFrChA_QuTarStmomDvActPassd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_TarQtaStmomDvFaild() \
  (&Rte_BmwMsgSlot68Bas0Repn2BusFrChA_TarQtaStmomDvFaild) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_TarQtaStmomDvPassd() \
  (&Rte_BmwMsgSlot68Bas0Repn2BusFrChA_TarQtaStmomDvPassd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_TarQtaStrmomDvAliveCntFaild() \
  (&Rte_BmwMsgSlot68Bas0Repn2BusFrChA_TarQtaStrmomDvAliveCntFaild) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_TarQtaStrmomDvAliveCntPassd() \
  (&Rte_BmwMsgSlot68Bas0Repn2BusFrChA_TarQtaStrmomDvAliveCntPassd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_TarQtaStrmomDvCRCFaild() \
  (&Rte_BmwMsgSlot68Bas0Repn2BusFrChA_TarQtaStrmomDvCRCFaild) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_TarQtaStrmomDvCRCPassd() \
  (&Rte_BmwMsgSlot68Bas0Repn2BusFrChA_TarQtaStrmomDvCRCPassd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_TarQtaStrmomDvMissFaild() \
  (&Rte_BmwMsgSlot68Bas0Repn2BusFrChA_TarQtaStrmomDvMissFaild) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_TarQtaStrmomDvMissPassd() \
  (&Rte_BmwMsgSlot68Bas0Repn2BusFrChA_TarQtaStrmomDvMissPassd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_TarStmomDvActAliveCntFaild() \
  (&Rte_BmwMsgSlot68Bas0Repn2BusFrChA_TarStmomDvActAliveCntFaild) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_TarStmomDvActAliveCntPassd() \
  (&Rte_BmwMsgSlot68Bas0Repn2BusFrChA_TarStmomDvActAliveCntPassd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_TarStmomDvActCrcFaild() \
  (&Rte_BmwMsgSlot68Bas0Repn2BusFrChA_TarStmomDvActCrcFaild) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_TarStmomDvActCrcPassd() \
  (&Rte_BmwMsgSlot68Bas0Repn2BusFrChA_TarStmomDvActCrcPassd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_TarStmomDvActFaild() \
  (&Rte_BmwMsgSlot68Bas0Repn2BusFrChA_TarStmomDvActFaild) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_TarStmomDvActMissFaild() \
  (&Rte_BmwMsgSlot68Bas0Repn2BusFrChA_TarStmomDvActMissFaild) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_TarStmomDvActMissPassd() \
  (&Rte_BmwMsgSlot68Bas0Repn2BusFrChA_TarStmomDvActMissPassd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_TarStmomDvActPassd() \
  (&Rte_BmwMsgSlot68Bas0Repn2BusFrChA_TarStmomDvActPassd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_BmwDrvgDynDampgFacReqVldPrev() \
  (&Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynDampgFacReqVldPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_BmwDrvgDynEffortFacReqVldPrev() \
  (&Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynEffortFacReqVldPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_BmwDrvgDynEnaReqPrev() \
  (&Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynEnaReqPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_BmwDrvgDynErrIfActvPrev() \
  (&Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynErrIfActvPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_BmwDrvgDynFacQlfrVldPrev() \
  (&Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynFacQlfrVldPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_BmwDrvgDynRtnFacReqVldPrev() \
  (&Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynRtnFacReqVldPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_BmwEpsDeactvnCtrlVldPrev() \
  (&Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwEpsDeactvnCtrlVldPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_BmwTarHwTqOvrlQlfrVldPrev() \
  (&Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTarHwTqOvrlQlfrVldPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_BmwTarHwTqOvrlVldPrev() \
  (&Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTarHwTqOvrlVldPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_BmwTarSteerTqDrvrActrQlfrVldPrev() \
  (&Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTarSteerTqDrvrActrQlfrVldPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_BmwTarSteerTqDrvrActrVldPrev() \
  (&Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTarSteerTqDrvrActrVldPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_BmwTrfcJamAssiDampgScaReqVldPrev() \
  (&Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTrfcJamAssiDampgScaReqVldPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_BmwTrfcJamAssiDampgStReqVldPrev() \
  (&Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTrfcJamAssiDampgStReqVldPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_TarQtaStrmomDvArcVld() \
  (&Rte_BmwMsgSlot68Bas0Repn2BusFrChA_TarQtaStrmomDvArcVld) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_TarQtaStrmomDvMsgProcd() \
  (&Rte_BmwMsgSlot68Bas0Repn2BusFrChA_TarQtaStrmomDvMsgProcd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_TarQtaStrmomDvMsgVld() \
  (&Rte_BmwMsgSlot68Bas0Repn2BusFrChA_TarQtaStrmomDvMsgVld) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_TarStmomDvActArcVld() \
  (&Rte_BmwMsgSlot68Bas0Repn2BusFrChA_TarStmomDvActArcVld) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_TarStmomDvActMsgProcd() \
  (&Rte_BmwMsgSlot68Bas0Repn2BusFrChA_TarStmomDvActMsgProcd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_TarStmomDvActMsgVld() \
  (&Rte_BmwMsgSlot68Bas0Repn2BusFrChA_TarStmomDvActMsgVld) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define BmwMsgSlot68Bas0Repn2BusFrChA_START_SEC_CODE
# include "BmwMsgSlot68Bas0Repn2BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_BmwMsgSlot68Bas0Repn2BusFrChAInit1 BmwMsgSlot68Bas0Repn2BusFrChAInit1
#  define RTE_RUNNABLE_TAR_QTA_STRMOM_DV_Miss TAR_QTA_STRMOM_DV_Miss
#  define RTE_RUNNABLE_TAR_QTA_STRMOM_DV_Rxd TAR_QTA_STRMOM_DV_Rxd
#  define RTE_RUNNABLE_TAR_STMOM_DV_ACT_Miss TAR_STMOM_DV_ACT_Miss
#  define RTE_RUNNABLE_TAR_STMOM_DV_ACT_Rxd TAR_STMOM_DV_ACT_Rxd
# endif

FUNC(void, BmwMsgSlot68Bas0Repn2BusFrChA_CODE) BmwMsgSlot68Bas0Repn2BusFrChAInit1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, BmwMsgSlot68Bas0Repn2BusFrChA_CODE) TAR_QTA_STRMOM_DV_Miss(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, BmwMsgSlot68Bas0Repn2BusFrChA_CODE) TAR_QTA_STRMOM_DV_Rxd(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, BmwMsgSlot68Bas0Repn2BusFrChA_CODE) TAR_STMOM_DV_ACT_Miss(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, BmwMsgSlot68Bas0Repn2BusFrChA_CODE) TAR_STMOM_DV_ACT_Rxd(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define BmwMsgSlot68Bas0Repn2BusFrChA_STOP_SEC_CODE
# include "BmwMsgSlot68Bas0Repn2BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_SetNtcSts_PortIf1_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_BMWMSGSLOT68BAS0REPN2BUSFRCHA_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
