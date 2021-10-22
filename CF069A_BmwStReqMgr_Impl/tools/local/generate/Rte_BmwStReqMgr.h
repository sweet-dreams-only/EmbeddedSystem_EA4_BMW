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
 *        Config:  C:/Users/nz2999/Documents/Synergy/ccm_wa/ses_dev_ea4/CF069A_BmwStReqMgr_Impl-nz2999/CF069A_BmwStReqMgr_Impl/tools/Component.dpa
 *     SW-C Type:  BmwStReqMgr
 *  Generated at:  Thu May 24 09:30:34 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <BmwStReqMgr> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_BMWSTREQMGR_H
# define _RTE_BMWSTREQMGR_H

# ifdef RTE_APPLICATION_HEADER_FILE
#  error Multiple application header files included.
# endif
# define RTE_APPLICATION_HEADER_FILE
# ifndef RTE_PTR2ARRAYBASETYPE_PASSING
#  define RTE_PTR2ARRAYBASETYPE_PASSING
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_BmwStReqMgr_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_BmwStReqMgr
{
  /* PIM Handles section */
  P2VAR(uint32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwVehCdnLvngDurn; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_DrvrActvRefTmr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_PrevHwTq; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_PrevTarEcuSt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_BmwStReqMgr, RTE_CONST, RTE_CONST) Rte_Inst_BmwStReqMgr; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_BmwStReqMgr, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_BmwEpsFctSts_Val (128U)
# define Rte_InitValue_BmwVehCdn_Val (15U)
# define Rte_InitValue_BmwVehCdnVld_Logl (FALSE)
# define Rte_InitValue_BmwVehSpdSts_Val (15U)
# define Rte_InitValue_DiagcStsNonRcvrlReqDiFltPrsnt_Logl (FALSE)
# define Rte_InitValue_HwTq_Val (0.0F)
# define Rte_InitValue_PwrLimrRednFac_Val (0.0F)
# define Rte_InitValue_PwrSplyEnaReq_Logl (FALSE)
# define Rte_InitValue_StsDrvrActvy_Val (1U)
# define Rte_InitValue_StsSteerAssi_Val (0U)
# define Rte_InitValue_SysOperMotTqCmdSca_Val (1.0F)
# define Rte_InitValue_SysOperRampRate_Val (1.0F)
# define Rte_InitValue_SysSt_Val (3U)
# define Rte_InitValue_SysStFltOutpReqDi_Logl (FALSE)
# define Rte_InitValue_SysStReqEna_Logl (FALSE)
# define Rte_InitValue_TarEcuSt_Val (3U)
# define Rte_InitValue_ThermRednFac_Val (0.0F)
# define Rte_InitValue_VehSpd_Val (0.0F)


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwStReqMgr_BmwVehCdn_Val(P2VAR(BmwVehCdn1, AUTOMATIC, RTE_BMWSTREQMGR_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwStReqMgr_BmwVehCdnVld_Logl(P2VAR(boolean, AUTOMATIC, RTE_BMWSTREQMGR_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwStReqMgr_BmwVehSpdSts_Val(P2VAR(BmwVehSpdSts1, AUTOMATIC, RTE_BMWSTREQMGR_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwStReqMgr_DiagcStsNonRcvrlReqDiFltPrsnt_Logl(P2VAR(boolean, AUTOMATIC, RTE_BMWSTREQMGR_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwStReqMgr_HwTq_Val(P2VAR(float32, AUTOMATIC, RTE_BMWSTREQMGR_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwStReqMgr_PwrLimrRednFac_Val(P2VAR(float32, AUTOMATIC, RTE_BMWSTREQMGR_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwStReqMgr_SysSt_Val(P2VAR(SysSt1, AUTOMATIC, RTE_BMWSTREQMGR_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwStReqMgr_SysStFltOutpReqDi_Logl(P2VAR(boolean, AUTOMATIC, RTE_BMWSTREQMGR_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwStReqMgr_ThermRednFac_Val(P2VAR(float32, AUTOMATIC, RTE_BMWSTREQMGR_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwStReqMgr_VehSpd_Val(P2VAR(float32, AUTOMATIC, RTE_BMWSTREQMGR_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwStReqMgr_BmwEpsFctSts_Val(BmwEpsFctSts1 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwStReqMgr_PwrSplyEnaReq_Logl(boolean data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwStReqMgr_StsDrvrActvy_Val(StsDrvrActvy1 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwStReqMgr_StsSteerAssi_Val(StsSteerAssi1 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwStReqMgr_SysOperMotTqCmdSca_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwStReqMgr_SysOperRampRate_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwStReqMgr_SysStReqEna_Logl(boolean data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwStReqMgr_TarEcuSt_Val(SysSt1 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwStReqMgr_GetRefTmr100MicroSec32bit_Oper(P2VAR(uint32, AUTOMATIC, RTE_BMWSTREQMGR_APPL_VAR) RefTmr_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwStReqMgr_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, P2VAR(uint32, AUTOMATIC, RTE_BMWSTREQMGR_APPL_VAR) TiSpan_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwStReqMgr_IoHwAb_GetGpioMcuEna_Oper(P2VAR(boolean, AUTOMATIC, RTE_BMWSTREQMGR_APPL_VAR) PinSt_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_BmwStReqMgr_BmwStReqMgrHwTqThd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_BmwStReqMgr_BmwStReqMgrOperRampRate_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_BmwStReqMgr_BmwStReqMgrStsDrvrActvyTqChgThd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_BmwStReqMgr_BmwStReqMgrSwtOffSpdLim_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_BmwStReqMgr_BmwStReqMgrSysProtnRednFacThd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(u16p0, RTE_CODE) Rte_Prm_BmwStReqMgr_BmwStReqMgrAllwToOffThd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(u16p0, RTE_CODE) Rte_Prm_BmwStReqMgr_BmwStReqMgrDrvrActvTmrThd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint8, RTE_CODE) Rte_Prm_BmwStReqMgr_BmwStReqMgrVehCdnOvrd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_BmwVehCdn_Val Rte_Read_BmwStReqMgr_BmwVehCdn_Val
# define Rte_Read_BmwVehCdnVld_Logl Rte_Read_BmwStReqMgr_BmwVehCdnVld_Logl
# define Rte_Read_BmwVehSpdSts_Val Rte_Read_BmwStReqMgr_BmwVehSpdSts_Val
# define Rte_Read_DiagcStsNonRcvrlReqDiFltPrsnt_Logl Rte_Read_BmwStReqMgr_DiagcStsNonRcvrlReqDiFltPrsnt_Logl
# define Rte_Read_HwTq_Val Rte_Read_BmwStReqMgr_HwTq_Val
# define Rte_Read_PwrLimrRednFac_Val Rte_Read_BmwStReqMgr_PwrLimrRednFac_Val
# define Rte_Read_SysSt_Val Rte_Read_BmwStReqMgr_SysSt_Val
# define Rte_Read_SysStFltOutpReqDi_Logl Rte_Read_BmwStReqMgr_SysStFltOutpReqDi_Logl
# define Rte_Read_ThermRednFac_Val Rte_Read_BmwStReqMgr_ThermRednFac_Val
# define Rte_Read_VehSpd_Val Rte_Read_BmwStReqMgr_VehSpd_Val


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_BmwEpsFctSts_Val Rte_Write_BmwStReqMgr_BmwEpsFctSts_Val
# define Rte_Write_PwrSplyEnaReq_Logl Rte_Write_BmwStReqMgr_PwrSplyEnaReq_Logl
# define Rte_Write_StsDrvrActvy_Val Rte_Write_BmwStReqMgr_StsDrvrActvy_Val
# define Rte_Write_StsSteerAssi_Val Rte_Write_BmwStReqMgr_StsSteerAssi_Val
# define Rte_Write_SysOperMotTqCmdSca_Val Rte_Write_BmwStReqMgr_SysOperMotTqCmdSca_Val
# define Rte_Write_SysOperRampRate_Val Rte_Write_BmwStReqMgr_SysOperRampRate_Val
# define Rte_Write_SysStReqEna_Logl Rte_Write_BmwStReqMgr_SysStReqEna_Logl
# define Rte_Write_TarEcuSt_Val Rte_Write_BmwStReqMgr_TarEcuSt_Val


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_GetRefTmr100MicroSec32bit_Oper Rte_Call_BmwStReqMgr_GetRefTmr100MicroSec32bit_Oper
# define Rte_Call_GetTiSpan100MicroSec32bit_Oper Rte_Call_BmwStReqMgr_GetTiSpan100MicroSec32bit_Oper
# define Rte_Call_IoHwAb_GetGpioMcuEna_Oper Rte_Call_BmwStReqMgr_IoHwAb_GetGpioMcuEna_Oper


/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

# define Rte_Prm_BmwStReqMgrHwTqThd_Val Rte_Prm_BmwStReqMgr_BmwStReqMgrHwTqThd_Val

# define Rte_Prm_BmwStReqMgrOperRampRate_Val Rte_Prm_BmwStReqMgr_BmwStReqMgrOperRampRate_Val

# define Rte_Prm_BmwStReqMgrStsDrvrActvyTqChgThd_Val Rte_Prm_BmwStReqMgr_BmwStReqMgrStsDrvrActvyTqChgThd_Val

# define Rte_Prm_BmwStReqMgrSwtOffSpdLim_Val Rte_Prm_BmwStReqMgr_BmwStReqMgrSwtOffSpdLim_Val

# define Rte_Prm_BmwStReqMgrSysProtnRednFacThd_Val Rte_Prm_BmwStReqMgr_BmwStReqMgrSysProtnRednFacThd_Val

# define Rte_Prm_BmwStReqMgrAllwToOffThd_Val Rte_Prm_BmwStReqMgr_BmwStReqMgrAllwToOffThd_Val

# define Rte_Prm_BmwStReqMgrDrvrActvTmrThd_Val Rte_Prm_BmwStReqMgr_BmwStReqMgrDrvrActvTmrThd_Val

# define Rte_Prm_BmwStReqMgrVehCdnOvrd_Val Rte_Prm_BmwStReqMgr_BmwStReqMgrVehCdnOvrd_Val

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_PrevHwTq() (Rte_Inst_BmwStReqMgr->Pim_PrevHwTq) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_BmwVehCdnLvngDurn() (Rte_Inst_BmwStReqMgr->Pim_BmwVehCdnLvngDurn) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_DrvrActvRefTmr() (Rte_Inst_BmwStReqMgr->Pim_DrvrActvRefTmr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_PrevTarEcuSt() (Rte_Inst_BmwStReqMgr->Pim_PrevTarEcuSt) /* PRQA S 3453 */ /* MD_MSR_19.7 */




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   float32 *Rte_Pim_PrevHwTq(void)
 *   uint32 *Rte_Pim_BmwVehCdnLvngDurn(void)
 *   uint32 *Rte_Pim_DrvrActvRefTmr(void)
 *   uint8 *Rte_Pim_PrevTarEcuSt(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_BmwStReqMgrHwTqThd_Val(void)
 *   float32 Rte_Prm_BmwStReqMgrOperRampRate_Val(void)
 *   float32 Rte_Prm_BmwStReqMgrStsDrvrActvyTqChgThd_Val(void)
 *   float32 Rte_Prm_BmwStReqMgrSwtOffSpdLim_Val(void)
 *   float32 Rte_Prm_BmwStReqMgrSysProtnRednFacThd_Val(void)
 *   u16p0 Rte_Prm_BmwStReqMgrAllwToOffThd_Val(void)
 *   u16p0 Rte_Prm_BmwStReqMgrDrvrActvTmrThd_Val(void)
 *   uint8 Rte_Prm_BmwStReqMgrVehCdnOvrd_Val(void)
 *
 *********************************************************************************************************************/


# define BmwStReqMgr_START_SEC_CODE
# include "BmwStReqMgr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwStReqMgrInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_GetRefTmr100MicroSec32bit_Oper(uint32 *RefTmr_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_BmwStReqMgrInit1 BmwStReqMgrInit1
FUNC(void, BmwStReqMgr_CODE) BmwStReqMgrInit1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwStReqMgrPer1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_BmwVehCdn_Val(BmwVehCdn1 *data)
 *   Std_ReturnType Rte_Read_BmwVehCdnVld_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_BmwVehSpdSts_Val(BmwVehSpdSts1 *data)
 *   Std_ReturnType Rte_Read_DiagcStsNonRcvrlReqDiFltPrsnt_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_HwTq_Val(float32 *data)
 *   Std_ReturnType Rte_Read_PwrLimrRednFac_Val(float32 *data)
 *   Std_ReturnType Rte_Read_SysSt_Val(SysSt1 *data)
 *   Std_ReturnType Rte_Read_SysStFltOutpReqDi_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_ThermRednFac_Val(float32 *data)
 *   Std_ReturnType Rte_Read_VehSpd_Val(float32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_BmwEpsFctSts_Val(BmwEpsFctSts1 data)
 *   Std_ReturnType Rte_Write_PwrSplyEnaReq_Logl(boolean data)
 *   Std_ReturnType Rte_Write_StsDrvrActvy_Val(StsDrvrActvy1 data)
 *   Std_ReturnType Rte_Write_StsSteerAssi_Val(StsSteerAssi1 data)
 *   Std_ReturnType Rte_Write_SysOperMotTqCmdSca_Val(float32 data)
 *   Std_ReturnType Rte_Write_SysOperRampRate_Val(float32 data)
 *   Std_ReturnType Rte_Write_SysStReqEna_Logl(boolean data)
 *   Std_ReturnType Rte_Write_TarEcuSt_Val(SysSt1 data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_GetRefTmr100MicroSec32bit_Oper(uint32 *RefTmr_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_IoHwAb_GetGpioMcuEna_Oper(boolean *PinSt_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_GetGpio_PortIf1_E_NOT_OK
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_BmwStReqMgrPer1 BmwStReqMgrPer1
FUNC(void, BmwStReqMgr_CODE) BmwStReqMgrPer1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define BmwStReqMgr_STOP_SEC_CODE
# include "BmwStReqMgr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_GetGpio_PortIf1_E_NOT_OK (1U)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_BMWSTREQMGR_H */

#include "Rte_Stubs.h"
