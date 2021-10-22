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
 *          File:  Rte_BmwDrvgDynStMac.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <BmwDrvgDynStMac>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_BMWDRVGDYNSTMAC_H
# define _RTE_BMWDRVGDYNSTMAC_H

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

# include "Rte_BmwDrvgDynStMac_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(boolean, RTE_VAR_INIT) Rte_BmwDrvgDynStMac_DrvgDynActv_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(DrvgDynIfSt1, RTE_VAR_INIT) Rte_BmwDrvgDynStMac_DrvgDynIfSt_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwDrvgDynStMac_OutpTqOvrlRampInEna_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynEnaRqst_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(BmwOvrlCmdQlfr1, RTE_VAR_INIT) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynFacQlfr_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynFacQlfrVld_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(BmwOvrlCmdQlfr1, RTE_VAR_INIT) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTarHwTqOvrlQlfr_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTarHwTqOvrlQlfrVld_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(BmwOvrlCmdQlfr1, RTE_VAR_INIT) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTarSteerTqDrvrActrQlfr_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTarSteerTqDrvrActrQlfrVld_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(BmwTrfcJamAssiDampgStReq1, RTE_VAR_INIT) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTrfcJamAssiDampgStReq_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTrfcJamAssiDampgStReqVld_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(BmwVehCdn1, RTE_VAR_INIT) Rte_BmwMsgSlot121Bas1Repn2BusFrChA_BmwVehCdn_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwTqOvrlCdngAndDrvgDynFac_DampgCmdSca_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_DiagcMgr_DiagcStsCtrldShtDwnFltPrsnt_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_DiagcMgr_DiagcStsNonRcvrlReqDiFltPrsnt_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwTqOvrlCdngAndDrvgDynFac_EffortCmdSca_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_PwrLimr_MotTqCmdPwrLimd_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwMotTqOvrlArbn_MotTqOvrlCmd_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwTqOvrlCdngAndDrvgDynFac_RtnCmdSca_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(StsSteerAssi1, RTE_VAR_INIT) Rte_BmwStReqMgr_StsSteerAssi_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_DiagcMgr_SysStFltOutpReqDi_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_BmwDrvgDynEnaReq_Logl (FALSE)
#  define Rte_InitValue_BmwDrvgDynFacQlfr_Val (15U)
#  define Rte_InitValue_BmwDrvgDynFacQlfrVld_Logl (FALSE)
#  define Rte_InitValue_BmwTarHwTqOvrlQlfr_Val (15U)
#  define Rte_InitValue_BmwTarHwTqOvrlQlfrVld_Logl (FALSE)
#  define Rte_InitValue_BmwTarSteerTqDrvrActrQlfr_Val (15U)
#  define Rte_InitValue_BmwTarSteerTqDrvrActrQlfrVld_Logl (FALSE)
#  define Rte_InitValue_BmwTrfcJamAssiDampgStReq_Val (1U)
#  define Rte_InitValue_BmwTrfcJamAssiDampgStReqVld_Logl (FALSE)
#  define Rte_InitValue_BmwVehCdn_Val (15U)
#  define Rte_InitValue_DampgCmdSca_Val (1.0F)
#  define Rte_InitValue_DiagcStsCtrldShtDwnFltPrsnt_Logl (FALSE)
#  define Rte_InitValue_DiagcStsNonRcvrlReqDiFltPrsnt_Logl (FALSE)
#  define Rte_InitValue_DrvgDynActv_Logl (FALSE)
#  define Rte_InitValue_DrvgDynIfSt_Val (128U)
#  define Rte_InitValue_EffortCmdSca_Val (1.0F)
#  define Rte_InitValue_MotTqCmdPwrLimd_Val (0.0F)
#  define Rte_InitValue_MotTqOvrlCmd_Val (0.0F)
#  define Rte_InitValue_OutpTqOvrlRampInEna_Logl (FALSE)
#  define Rte_InitValue_RtnCmdSca_Val (1.0F)
#  define Rte_InitValue_StsSteerAssi_Val (0U)
#  define Rte_InitValue_SysStFltOutpReqDi_Logl (FALSE)
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_BmwDrvgDynEnaReq_Logl Rte_Read_BmwDrvgDynStMac_BmwDrvgDynEnaReq_Logl
#  define Rte_Read_BmwDrvgDynStMac_BmwDrvgDynEnaReq_Logl(data) (*(data) = Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynEnaRqst_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BmwDrvgDynFacQlfr_Val Rte_Read_BmwDrvgDynStMac_BmwDrvgDynFacQlfr_Val
#  define Rte_Read_BmwDrvgDynStMac_BmwDrvgDynFacQlfr_Val(data) (*(data) = Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynFacQlfr_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BmwDrvgDynFacQlfrVld_Logl Rte_Read_BmwDrvgDynStMac_BmwDrvgDynFacQlfrVld_Logl
#  define Rte_Read_BmwDrvgDynStMac_BmwDrvgDynFacQlfrVld_Logl(data) (*(data) = Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwDrvgDynFacQlfrVld_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BmwTarHwTqOvrlQlfr_Val Rte_Read_BmwDrvgDynStMac_BmwTarHwTqOvrlQlfr_Val
#  define Rte_Read_BmwDrvgDynStMac_BmwTarHwTqOvrlQlfr_Val(data) (*(data) = Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTarHwTqOvrlQlfr_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BmwTarHwTqOvrlQlfrVld_Logl Rte_Read_BmwDrvgDynStMac_BmwTarHwTqOvrlQlfrVld_Logl
#  define Rte_Read_BmwDrvgDynStMac_BmwTarHwTqOvrlQlfrVld_Logl(data) (*(data) = Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTarHwTqOvrlQlfrVld_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BmwTarSteerTqDrvrActrQlfr_Val Rte_Read_BmwDrvgDynStMac_BmwTarSteerTqDrvrActrQlfr_Val
#  define Rte_Read_BmwDrvgDynStMac_BmwTarSteerTqDrvrActrQlfr_Val(data) (*(data) = Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTarSteerTqDrvrActrQlfr_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BmwTarSteerTqDrvrActrQlfrVld_Logl Rte_Read_BmwDrvgDynStMac_BmwTarSteerTqDrvrActrQlfrVld_Logl
#  define Rte_Read_BmwDrvgDynStMac_BmwTarSteerTqDrvrActrQlfrVld_Logl(data) (*(data) = Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTarSteerTqDrvrActrQlfrVld_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BmwTrfcJamAssiDampgStReq_Val Rte_Read_BmwDrvgDynStMac_BmwTrfcJamAssiDampgStReq_Val
#  define Rte_Read_BmwDrvgDynStMac_BmwTrfcJamAssiDampgStReq_Val(data) (*(data) = Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTrfcJamAssiDampgStReq_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BmwTrfcJamAssiDampgStReqVld_Logl Rte_Read_BmwDrvgDynStMac_BmwTrfcJamAssiDampgStReqVld_Logl
#  define Rte_Read_BmwDrvgDynStMac_BmwTrfcJamAssiDampgStReqVld_Logl(data) (*(data) = Rte_BmwMsgSlot68Bas0Repn2BusFrChA_BmwTrfcJamAssiDampgStReqVld_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BmwVehCdn_Val Rte_Read_BmwDrvgDynStMac_BmwVehCdn_Val
#  define Rte_Read_BmwDrvgDynStMac_BmwVehCdn_Val(data) (*(data) = Rte_BmwMsgSlot121Bas1Repn2BusFrChA_BmwVehCdn_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_DampgCmdSca_Val Rte_Read_BmwDrvgDynStMac_DampgCmdSca_Val
#  define Rte_Read_BmwDrvgDynStMac_DampgCmdSca_Val(data) (*(data) = Rte_BmwTqOvrlCdngAndDrvgDynFac_DampgCmdSca_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_DiagcStsCtrldShtDwnFltPrsnt_Logl Rte_Read_BmwDrvgDynStMac_DiagcStsCtrldShtDwnFltPrsnt_Logl
#  define Rte_Read_BmwDrvgDynStMac_DiagcStsCtrldShtDwnFltPrsnt_Logl(data) (*(data) = Rte_DiagcMgr_DiagcStsCtrldShtDwnFltPrsnt_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_DiagcStsNonRcvrlReqDiFltPrsnt_Logl Rte_Read_BmwDrvgDynStMac_DiagcStsNonRcvrlReqDiFltPrsnt_Logl
#  define Rte_Read_BmwDrvgDynStMac_DiagcStsNonRcvrlReqDiFltPrsnt_Logl(data) (*(data) = Rte_DiagcMgr_DiagcStsNonRcvrlReqDiFltPrsnt_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_EffortCmdSca_Val Rte_Read_BmwDrvgDynStMac_EffortCmdSca_Val
#  define Rte_Read_BmwDrvgDynStMac_EffortCmdSca_Val(data) (*(data) = Rte_BmwTqOvrlCdngAndDrvgDynFac_EffortCmdSca_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotTqCmdPwrLimd_Val Rte_Read_BmwDrvgDynStMac_MotTqCmdPwrLimd_Val
#  define Rte_Read_BmwDrvgDynStMac_MotTqCmdPwrLimd_Val(data) (*(data) = Rte_PwrLimr_MotTqCmdPwrLimd_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotTqOvrlCmd_Val Rte_Read_BmwDrvgDynStMac_MotTqOvrlCmd_Val
#  define Rte_Read_BmwDrvgDynStMac_MotTqOvrlCmd_Val(data) (*(data) = Rte_BmwMotTqOvrlArbn_MotTqOvrlCmd_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_RtnCmdSca_Val Rte_Read_BmwDrvgDynStMac_RtnCmdSca_Val
#  define Rte_Read_BmwDrvgDynStMac_RtnCmdSca_Val(data) (*(data) = Rte_BmwTqOvrlCdngAndDrvgDynFac_RtnCmdSca_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_StsSteerAssi_Val Rte_Read_BmwDrvgDynStMac_StsSteerAssi_Val
#  define Rte_Read_BmwDrvgDynStMac_StsSteerAssi_Val(data) (*(data) = Rte_BmwStReqMgr_StsSteerAssi_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_SysStFltOutpReqDi_Logl Rte_Read_BmwDrvgDynStMac_SysStFltOutpReqDi_Logl
#  define Rte_Read_BmwDrvgDynStMac_SysStFltOutpReqDi_Logl(data) (*(data) = Rte_DiagcMgr_SysStFltOutpReqDi_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_DrvgDynActv_Logl Rte_Write_BmwDrvgDynStMac_DrvgDynActv_Logl
#  define Rte_Write_BmwDrvgDynStMac_DrvgDynActv_Logl(data) (Rte_BmwDrvgDynStMac_DrvgDynActv_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_DrvgDynIfSt_Val Rte_Write_BmwDrvgDynStMac_DrvgDynIfSt_Val
#  define Rte_Write_BmwDrvgDynStMac_DrvgDynIfSt_Val(data) (Rte_BmwDrvgDynStMac_DrvgDynIfSt_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_OutpTqOvrlRampInEna_Logl Rte_Write_BmwDrvgDynStMac_OutpTqOvrlRampInEna_Logl
#  define Rte_Write_BmwDrvgDynStMac_OutpTqOvrlRampInEna_Logl(data) (Rte_BmwDrvgDynStMac_OutpTqOvrlRampInEna_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
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

#  define Rte_Prm_BmwDrvgDynStMacDampgCmdScaDft_Val() (((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwDrvgDynStMacDampgCmdScaDft_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwDrvgDynStMacEffortCmdScaDft_Val() (((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwDrvgDynStMacEffortCmdScaDft_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwDrvgDynStMacMotTqCmdOvrlActvtThd_Val() (((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwDrvgDynStMacMotTqCmdOvrlActvtThd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwDrvgDynStMacMotTqCmdOvrlDeactvtThd_Val() (((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwDrvgDynStMacMotTqCmdOvrlDeactvtThd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwDrvgDynStMacRtnCmdScaDft_Val() (((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwDrvgDynStMacRtnCmdScaDft_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwDrvgDynStMacAssiLvlThd_Val() (((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwDrvgDynStMacAssiLvlThd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwDrvgDynStMacErrIfTmrThd_Val() (((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwDrvgDynStMacErrIfTmrThd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwDrvgDynStMacVehCdnTmrThd_Val() (((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwDrvgDynStMacVehCdnTmrThd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwDrvgDynStMac_AssiLvlActvtTi; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwDrvgDynStMac_AssiLvlDeactvtTi; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwDrvgDynStMac_ErrIfTi; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwDrvgDynStMac_VehCdnTi; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwDrvgDynStMac_StMacSt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwDrvgDynStMac_MotTqCmdPwrLimdCdnActvt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwDrvgDynStMac_MotTqCmdPwrLimdCdnDeactvt; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  endif

#  define Rte_Pim_AssiLvlActvtTi() \
  (&Rte_BmwDrvgDynStMac_AssiLvlActvtTi) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_AssiLvlDeactvtTi() \
  (&Rte_BmwDrvgDynStMac_AssiLvlDeactvtTi) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_ErrIfTi() \
  (&Rte_BmwDrvgDynStMac_ErrIfTi) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_VehCdnTi() \
  (&Rte_BmwDrvgDynStMac_VehCdnTi) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_StMacSt() \
  (&Rte_BmwDrvgDynStMac_StMacSt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MotTqCmdPwrLimdCdnActvt() \
  (&Rte_BmwDrvgDynStMac_MotTqCmdPwrLimdCdnActvt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MotTqCmdPwrLimdCdnDeactvt() \
  (&Rte_BmwDrvgDynStMac_MotTqCmdPwrLimdCdnDeactvt) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define BmwDrvgDynStMac_START_SEC_CODE
# include "BmwDrvgDynStMac_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_BmwDrvgDynStMacInit1 BmwDrvgDynStMacInit1
#  define RTE_RUNNABLE_BmwDrvgDynStMacPer1 BmwDrvgDynStMacPer1
# endif

FUNC(void, BmwDrvgDynStMac_CODE) BmwDrvgDynStMacInit1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, BmwDrvgDynStMac_CODE) BmwDrvgDynStMacPer1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define BmwDrvgDynStMac_STOP_SEC_CODE
# include "BmwDrvgDynStMac_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_BMWDRVGDYNSTMAC_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
