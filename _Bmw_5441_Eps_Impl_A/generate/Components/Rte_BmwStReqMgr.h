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
 *          File:  Rte_BmwStReqMgr.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <BmwStReqMgr>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_BMWSTREQMGR_H
# define _RTE_BMWSTREQMGR_H

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

# include "Rte_BmwStReqMgr_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_Appl7_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_INIT) Rte_DutyCycThermProtn_ThermRednFac_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_Appl7_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_Appl9_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(BmwVehSpdSts1, RTE_VAR_INIT) Rte_BmwVehSpd_BmwSecurVehSpdSts_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwVehSpd_VehSpd_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_Appl9_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(BmwEpsFctSts1, RTE_VAR_INIT) Rte_BmwStReqMgr_BmwEpsFctSts_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwStReqMgr_PwrSplyEnaReq_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(StsDrvrActvy1, RTE_VAR_INIT) Rte_BmwStReqMgr_StsDrvrActvy_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(StsSteerAssi1, RTE_VAR_INIT) Rte_BmwStReqMgr_StsSteerAssi_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwStReqMgr_SysOperMotTqCmdSca_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwStReqMgr_SysOperRampRate_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwStReqMgr_SysStReqEna_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(SysSt1, RTE_VAR_INIT) Rte_BmwStReqMgr_TarEcuSt_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(BmwVehCdn1, RTE_VAR_INIT) Rte_BmwMsgSlot121Bas1Repn2BusFrChA_BmwVehCdn_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwMsgSlot121Bas1Repn2BusFrChA_BmwVehCdnVld_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_DiagcMgr_DiagcStsNonRcvrlReqDiFltPrsnt_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_HwTqArbn_HwTq_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_PwrLimr_PwrLimrRednFac_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(SysSt1, RTE_VAR_INIT) Rte_SysStMod_SysSt_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_DiagcMgr_SysStFltOutpReqDi_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_BmwEpsFctSts_Val (128U)
#  define Rte_InitValue_BmwVehCdn_Val (15U)
#  define Rte_InitValue_BmwVehCdnVld_Logl (FALSE)
#  define Rte_InitValue_BmwVehSpdSts_Val (15U)
#  define Rte_InitValue_DiagcStsNonRcvrlReqDiFltPrsnt_Logl (FALSE)
#  define Rte_InitValue_HwTq_Val (0.0F)
#  define Rte_InitValue_PwrLimrRednFac_Val (0.0F)
#  define Rte_InitValue_PwrSplyEnaReq_Logl (FALSE)
#  define Rte_InitValue_StsDrvrActvy_Val (1U)
#  define Rte_InitValue_StsSteerAssi_Val (0U)
#  define Rte_InitValue_SysOperMotTqCmdSca_Val (1.0F)
#  define Rte_InitValue_SysOperRampRate_Val (1.0F)
#  define Rte_InitValue_SysSt_Val (3U)
#  define Rte_InitValue_SysStFltOutpReqDi_Logl (FALSE)
#  define Rte_InitValue_SysStReqEna_Logl (FALSE)
#  define Rte_InitValue_TarEcuSt_Val (3U)
#  define Rte_InitValue_ThermRednFac_Val (0.0F)
#  define Rte_InitValue_VehSpd_Val (0.0F)
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_BmwVehCdn_Val Rte_Read_BmwStReqMgr_BmwVehCdn_Val
#  define Rte_Read_BmwStReqMgr_BmwVehCdn_Val(data) (*(data) = Rte_BmwMsgSlot121Bas1Repn2BusFrChA_BmwVehCdn_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BmwVehCdnVld_Logl Rte_Read_BmwStReqMgr_BmwVehCdnVld_Logl
#  define Rte_Read_BmwStReqMgr_BmwVehCdnVld_Logl(data) (*(data) = Rte_BmwMsgSlot121Bas1Repn2BusFrChA_BmwVehCdnVld_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BmwVehSpdSts_Val Rte_Read_BmwStReqMgr_BmwVehSpdSts_Val
#  define Rte_Read_BmwStReqMgr_BmwVehSpdSts_Val(data) (*(data) = Rte_BmwVehSpd_BmwSecurVehSpdSts_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_DiagcStsNonRcvrlReqDiFltPrsnt_Logl Rte_Read_BmwStReqMgr_DiagcStsNonRcvrlReqDiFltPrsnt_Logl
#  define Rte_Read_BmwStReqMgr_DiagcStsNonRcvrlReqDiFltPrsnt_Logl(data) (*(data) = Rte_DiagcMgr_DiagcStsNonRcvrlReqDiFltPrsnt_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_HwTq_Val Rte_Read_BmwStReqMgr_HwTq_Val
#  define Rte_Read_BmwStReqMgr_HwTq_Val(data) (*(data) = Rte_HwTqArbn_HwTq_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_PwrLimrRednFac_Val Rte_Read_BmwStReqMgr_PwrLimrRednFac_Val
#  define Rte_Read_BmwStReqMgr_PwrLimrRednFac_Val(data) (*(data) = Rte_PwrLimr_PwrLimrRednFac_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_SysSt_Val Rte_Read_BmwStReqMgr_SysSt_Val
#  define Rte_Read_BmwStReqMgr_SysSt_Val(data) (*(data) = Rte_SysStMod_SysSt_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_SysStFltOutpReqDi_Logl Rte_Read_BmwStReqMgr_SysStFltOutpReqDi_Logl
#  define Rte_Read_BmwStReqMgr_SysStFltOutpReqDi_Logl(data) (*(data) = Rte_DiagcMgr_SysStFltOutpReqDi_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_ThermRednFac_Val Rte_Read_BmwStReqMgr_ThermRednFac_Val
#  define Rte_Read_BmwStReqMgr_ThermRednFac_Val(data) (*(data) = Rte_DutyCycThermProtn_ThermRednFac_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_VehSpd_Val Rte_Read_BmwStReqMgr_VehSpd_Val
#  define Rte_Read_BmwStReqMgr_VehSpd_Val(data) (*(data) = Rte_BmwVehSpd_VehSpd_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_BmwEpsFctSts_Val Rte_Write_BmwStReqMgr_BmwEpsFctSts_Val
#  define Rte_Write_BmwStReqMgr_BmwEpsFctSts_Val(data) (Rte_BmwStReqMgr_BmwEpsFctSts_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_PwrSplyEnaReq_Logl Rte_Write_BmwStReqMgr_PwrSplyEnaReq_Logl
#  define Rte_Write_BmwStReqMgr_PwrSplyEnaReq_Logl(data) (Rte_BmwStReqMgr_PwrSplyEnaReq_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_StsDrvrActvy_Val Rte_Write_BmwStReqMgr_StsDrvrActvy_Val
#  define Rte_Write_BmwStReqMgr_StsDrvrActvy_Val(data) (Rte_BmwStReqMgr_StsDrvrActvy_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_StsSteerAssi_Val Rte_Write_BmwStReqMgr_StsSteerAssi_Val
#  define Rte_Write_BmwStReqMgr_StsSteerAssi_Val(data) (Rte_BmwStReqMgr_StsSteerAssi_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_SysOperMotTqCmdSca_Val Rte_Write_BmwStReqMgr_SysOperMotTqCmdSca_Val
#  define Rte_Write_BmwStReqMgr_SysOperMotTqCmdSca_Val(data) (Rte_BmwStReqMgr_SysOperMotTqCmdSca_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_SysOperRampRate_Val Rte_Write_BmwStReqMgr_SysOperRampRate_Val
#  define Rte_Write_BmwStReqMgr_SysOperRampRate_Val(data) (Rte_BmwStReqMgr_SysOperRampRate_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_SysStReqEna_Logl Rte_Write_BmwStReqMgr_SysStReqEna_Logl
#  define Rte_Write_BmwStReqMgr_SysStReqEna_Logl(data) (Rte_BmwStReqMgr_SysStReqEna_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_TarEcuSt_Val Rte_Write_BmwStReqMgr_TarEcuSt_Val
#  define Rte_Write_BmwStReqMgr_TarEcuSt_Val(data) (Rte_BmwStReqMgr_TarEcuSt_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


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
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_GetGpioMcuEna_Oper(P2VAR(IOHWAB_BOOL, AUTOMATIC, RTE_IOHWAB_APPL_VAR) PinSt_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_IoHwAb_GetGpioMcuEna_Oper IoHwAb_GetGpioMcuEna_Oper


/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

#  define Rte_Prm_BmwStReqMgrHwTqThd_Val() (((P2CONST(Rte_Calprm_CalRegn02Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP])->BmwStReqMgrHwTqThd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwStReqMgrOperRampRate_Val() (((P2CONST(Rte_Calprm_CalRegn02Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP])->BmwStReqMgrOperRampRate_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwStReqMgrStsDrvrActvyTqChgThd_Val() (((P2CONST(Rte_Calprm_CalRegn02Rt00_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00_DEFAULT_RTE_CALPRM_GROUP])->BmwStReqMgrStsDrvrActvyTqChgThd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwStReqMgrSwtOffSpdLim_Val() (((P2CONST(Rte_Calprm_CalRegn02Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP])->BmwStReqMgrSwtOffSpdLim_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwStReqMgrSysProtnRednFacThd_Val() (((P2CONST(Rte_Calprm_CalRegn02Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP])->BmwStReqMgrSysProtnRednFacThd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwStReqMgrAllwToOffThd_Val() (((P2CONST(Rte_Calprm_CalRegn02Rt00_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00_DEFAULT_RTE_CALPRM_GROUP])->BmwStReqMgrAllwToOffThd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwStReqMgrDrvrActvTmrThd_Val() (((P2CONST(Rte_Calprm_CalRegn02Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP])->BmwStReqMgrDrvrActvTmrThd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwStReqMgrVehCdnOvrd_Val() (((P2CONST(Rte_Calprm_CalRegn01CmnGroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupA_DEFAULT_RTE_CALPRM_GROUP])->BmwStReqMgrVehCdnOvrd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwStReqMgr_PrevHwTq; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwStReqMgr_BmwVehCdnLvngDurn; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwStReqMgr_DrvrActvRefTmr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwStReqMgr_PrevTarEcuSt; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  endif

#  define Rte_Pim_PrevHwTq() \
  (&Rte_BmwStReqMgr_PrevHwTq) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_BmwVehCdnLvngDurn() \
  (&Rte_BmwStReqMgr_BmwVehCdnLvngDurn) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_DrvrActvRefTmr() \
  (&Rte_BmwStReqMgr_DrvrActvRefTmr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_PrevTarEcuSt() \
  (&Rte_BmwStReqMgr_PrevTarEcuSt) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define BmwStReqMgr_START_SEC_CODE
# include "BmwStReqMgr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_BmwStReqMgrInit1 BmwStReqMgrInit1
#  define RTE_RUNNABLE_BmwStReqMgrPer1 BmwStReqMgrPer1
# endif

FUNC(void, BmwStReqMgr_CODE) BmwStReqMgrInit1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, BmwStReqMgr_CODE) BmwStReqMgrPer1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define BmwStReqMgr_STOP_SEC_CODE
# include "BmwStReqMgr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_GetGpio_PortIf1_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_BMWSTREQMGR_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
