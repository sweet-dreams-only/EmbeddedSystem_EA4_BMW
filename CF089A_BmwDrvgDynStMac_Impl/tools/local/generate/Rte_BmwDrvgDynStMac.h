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
 *        Config:  C:/Users/nz2999/Documents/Synergy/ccm_wa/ses_dev_ea4/CF089A_BmwDrvgDynStMac_Impl-nz2999/CF089A_BmwDrvgDynStMac_Impl/tools/Component.dpa
 *     SW-C Type:  BmwDrvgDynStMac
 *  Generated at:  Mon Apr 16 08:38:05 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <BmwDrvgDynStMac> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_BMWDRVGDYNSTMAC_H
# define _RTE_BMWDRVGDYNSTMAC_H

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

# include "Rte_BmwDrvgDynStMac_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_BmwDrvgDynStMac
{
  /* PIM Handles section */
  P2VAR(uint32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_AssiLvlActvtTi; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_AssiLvlDeactvtTi; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_ErrIfTi; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MotTqCmdPwrLimdCdnActvt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MotTqCmdPwrLimdCdnDeactvt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_StMacSt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_VehCdnTi; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_BmwDrvgDynStMac, RTE_CONST, RTE_CONST) Rte_Inst_BmwDrvgDynStMac; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_BmwDrvgDynStMac, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_BmwDrvgDynEnaReq_Logl (FALSE)
# define Rte_InitValue_BmwDrvgDynFacQlfr_Val (15U)
# define Rte_InitValue_BmwDrvgDynFacQlfrVld_Logl (FALSE)
# define Rte_InitValue_BmwTarHwTqOvrlQlfr_Val (15U)
# define Rte_InitValue_BmwTarHwTqOvrlQlfrVld_Logl (FALSE)
# define Rte_InitValue_BmwTarSteerTqDrvrActrQlfr_Val (15U)
# define Rte_InitValue_BmwTarSteerTqDrvrActrQlfrVld_Logl (FALSE)
# define Rte_InitValue_BmwTrfcJamAssiDampgStReq_Val (1U)
# define Rte_InitValue_BmwTrfcJamAssiDampgStReqVld_Logl (FALSE)
# define Rte_InitValue_BmwVehCdn_Val (15U)
# define Rte_InitValue_DampgCmdSca_Val (1.0F)
# define Rte_InitValue_DiagcStsCtrldShtDwnFltPrsnt_Logl (FALSE)
# define Rte_InitValue_DiagcStsNonRcvrlReqDiFltPrsnt_Logl (FALSE)
# define Rte_InitValue_DrvgDynActv_Logl (FALSE)
# define Rte_InitValue_DrvgDynIfSt_Val (128U)
# define Rte_InitValue_EffortCmdSca_Val (1.0F)
# define Rte_InitValue_MotTqCmdPwrLimd_Val (0.0F)
# define Rte_InitValue_MotTqOvrlCmd_Val (0.0F)
# define Rte_InitValue_OutpTqOvrlRampInEna_Logl (FALSE)
# define Rte_InitValue_RtnCmdSca_Val (1.0F)
# define Rte_InitValue_StsSteerAssi_Val (0U)
# define Rte_InitValue_SysStFltOutpReqDi_Logl (FALSE)


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwDrvgDynStMac_BmwDrvgDynEnaReq_Logl(P2VAR(boolean, AUTOMATIC, RTE_BMWDRVGDYNSTMAC_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwDrvgDynStMac_BmwDrvgDynFacQlfr_Val(P2VAR(BmwOvrlCmdQlfr1, AUTOMATIC, RTE_BMWDRVGDYNSTMAC_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwDrvgDynStMac_BmwDrvgDynFacQlfrVld_Logl(P2VAR(boolean, AUTOMATIC, RTE_BMWDRVGDYNSTMAC_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwDrvgDynStMac_BmwTarHwTqOvrlQlfr_Val(P2VAR(BmwOvrlCmdQlfr1, AUTOMATIC, RTE_BMWDRVGDYNSTMAC_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwDrvgDynStMac_BmwTarHwTqOvrlQlfrVld_Logl(P2VAR(boolean, AUTOMATIC, RTE_BMWDRVGDYNSTMAC_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwDrvgDynStMac_BmwTarSteerTqDrvrActrQlfr_Val(P2VAR(BmwOvrlCmdQlfr1, AUTOMATIC, RTE_BMWDRVGDYNSTMAC_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwDrvgDynStMac_BmwTarSteerTqDrvrActrQlfrVld_Logl(P2VAR(boolean, AUTOMATIC, RTE_BMWDRVGDYNSTMAC_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwDrvgDynStMac_BmwTrfcJamAssiDampgStReq_Val(P2VAR(BmwTrfcJamAssiDampgStReq1, AUTOMATIC, RTE_BMWDRVGDYNSTMAC_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwDrvgDynStMac_BmwTrfcJamAssiDampgStReqVld_Logl(P2VAR(boolean, AUTOMATIC, RTE_BMWDRVGDYNSTMAC_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwDrvgDynStMac_BmwVehCdn_Val(P2VAR(BmwVehCdn1, AUTOMATIC, RTE_BMWDRVGDYNSTMAC_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwDrvgDynStMac_DampgCmdSca_Val(P2VAR(float32, AUTOMATIC, RTE_BMWDRVGDYNSTMAC_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwDrvgDynStMac_DiagcStsCtrldShtDwnFltPrsnt_Logl(P2VAR(boolean, AUTOMATIC, RTE_BMWDRVGDYNSTMAC_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwDrvgDynStMac_DiagcStsNonRcvrlReqDiFltPrsnt_Logl(P2VAR(boolean, AUTOMATIC, RTE_BMWDRVGDYNSTMAC_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwDrvgDynStMac_EffortCmdSca_Val(P2VAR(float32, AUTOMATIC, RTE_BMWDRVGDYNSTMAC_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwDrvgDynStMac_MotTqCmdPwrLimd_Val(P2VAR(float32, AUTOMATIC, RTE_BMWDRVGDYNSTMAC_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwDrvgDynStMac_MotTqOvrlCmd_Val(P2VAR(float32, AUTOMATIC, RTE_BMWDRVGDYNSTMAC_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwDrvgDynStMac_RtnCmdSca_Val(P2VAR(float32, AUTOMATIC, RTE_BMWDRVGDYNSTMAC_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwDrvgDynStMac_StsSteerAssi_Val(P2VAR(StsSteerAssi1, AUTOMATIC, RTE_BMWDRVGDYNSTMAC_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwDrvgDynStMac_SysStFltOutpReqDi_Logl(P2VAR(boolean, AUTOMATIC, RTE_BMWDRVGDYNSTMAC_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwDrvgDynStMac_DrvgDynActv_Logl(boolean data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwDrvgDynStMac_DrvgDynIfSt_Val(DrvgDynIfSt1 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwDrvgDynStMac_OutpTqOvrlRampInEna_Logl(boolean data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwDrvgDynStMac_GetRefTmr100MicroSec32bit_Oper(P2VAR(uint32, AUTOMATIC, RTE_BMWDRVGDYNSTMAC_APPL_VAR) RefTmr_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwDrvgDynStMac_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, P2VAR(uint32, AUTOMATIC, RTE_BMWDRVGDYNSTMAC_APPL_VAR) TiSpan_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_BmwDrvgDynStMac_BmwDrvgDynStMacDampgCmdScaDft_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_BmwDrvgDynStMac_BmwDrvgDynStMacEffortCmdScaDft_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_BmwDrvgDynStMac_BmwDrvgDynStMacMotTqCmdOvrlActvtThd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_BmwDrvgDynStMac_BmwDrvgDynStMacMotTqCmdOvrlDeactvtThd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_BmwDrvgDynStMac_BmwDrvgDynStMacRtnCmdScaDft_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint16, RTE_CODE) Rte_Prm_BmwDrvgDynStMac_BmwDrvgDynStMacAssiLvlThd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint16, RTE_CODE) Rte_Prm_BmwDrvgDynStMac_BmwDrvgDynStMacErrIfTmrThd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint16, RTE_CODE) Rte_Prm_BmwDrvgDynStMac_BmwDrvgDynStMacVehCdnTmrThd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_BmwDrvgDynEnaReq_Logl Rte_Read_BmwDrvgDynStMac_BmwDrvgDynEnaReq_Logl
# define Rte_Read_BmwDrvgDynFacQlfr_Val Rte_Read_BmwDrvgDynStMac_BmwDrvgDynFacQlfr_Val
# define Rte_Read_BmwDrvgDynFacQlfrVld_Logl Rte_Read_BmwDrvgDynStMac_BmwDrvgDynFacQlfrVld_Logl
# define Rte_Read_BmwTarHwTqOvrlQlfr_Val Rte_Read_BmwDrvgDynStMac_BmwTarHwTqOvrlQlfr_Val
# define Rte_Read_BmwTarHwTqOvrlQlfrVld_Logl Rte_Read_BmwDrvgDynStMac_BmwTarHwTqOvrlQlfrVld_Logl
# define Rte_Read_BmwTarSteerTqDrvrActrQlfr_Val Rte_Read_BmwDrvgDynStMac_BmwTarSteerTqDrvrActrQlfr_Val
# define Rte_Read_BmwTarSteerTqDrvrActrQlfrVld_Logl Rte_Read_BmwDrvgDynStMac_BmwTarSteerTqDrvrActrQlfrVld_Logl
# define Rte_Read_BmwTrfcJamAssiDampgStReq_Val Rte_Read_BmwDrvgDynStMac_BmwTrfcJamAssiDampgStReq_Val
# define Rte_Read_BmwTrfcJamAssiDampgStReqVld_Logl Rte_Read_BmwDrvgDynStMac_BmwTrfcJamAssiDampgStReqVld_Logl
# define Rte_Read_BmwVehCdn_Val Rte_Read_BmwDrvgDynStMac_BmwVehCdn_Val
# define Rte_Read_DampgCmdSca_Val Rte_Read_BmwDrvgDynStMac_DampgCmdSca_Val
# define Rte_Read_DiagcStsCtrldShtDwnFltPrsnt_Logl Rte_Read_BmwDrvgDynStMac_DiagcStsCtrldShtDwnFltPrsnt_Logl
# define Rte_Read_DiagcStsNonRcvrlReqDiFltPrsnt_Logl Rte_Read_BmwDrvgDynStMac_DiagcStsNonRcvrlReqDiFltPrsnt_Logl
# define Rte_Read_EffortCmdSca_Val Rte_Read_BmwDrvgDynStMac_EffortCmdSca_Val
# define Rte_Read_MotTqCmdPwrLimd_Val Rte_Read_BmwDrvgDynStMac_MotTqCmdPwrLimd_Val
# define Rte_Read_MotTqOvrlCmd_Val Rte_Read_BmwDrvgDynStMac_MotTqOvrlCmd_Val
# define Rte_Read_RtnCmdSca_Val Rte_Read_BmwDrvgDynStMac_RtnCmdSca_Val
# define Rte_Read_StsSteerAssi_Val Rte_Read_BmwDrvgDynStMac_StsSteerAssi_Val
# define Rte_Read_SysStFltOutpReqDi_Logl Rte_Read_BmwDrvgDynStMac_SysStFltOutpReqDi_Logl


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_DrvgDynActv_Logl Rte_Write_BmwDrvgDynStMac_DrvgDynActv_Logl
# define Rte_Write_DrvgDynIfSt_Val Rte_Write_BmwDrvgDynStMac_DrvgDynIfSt_Val
# define Rte_Write_OutpTqOvrlRampInEna_Logl Rte_Write_BmwDrvgDynStMac_OutpTqOvrlRampInEna_Logl


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_GetRefTmr100MicroSec32bit_Oper Rte_Call_BmwDrvgDynStMac_GetRefTmr100MicroSec32bit_Oper
# define Rte_Call_GetTiSpan100MicroSec32bit_Oper Rte_Call_BmwDrvgDynStMac_GetTiSpan100MicroSec32bit_Oper


/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

# define Rte_Prm_BmwDrvgDynStMacDampgCmdScaDft_Val Rte_Prm_BmwDrvgDynStMac_BmwDrvgDynStMacDampgCmdScaDft_Val

# define Rte_Prm_BmwDrvgDynStMacEffortCmdScaDft_Val Rte_Prm_BmwDrvgDynStMac_BmwDrvgDynStMacEffortCmdScaDft_Val

# define Rte_Prm_BmwDrvgDynStMacMotTqCmdOvrlActvtThd_Val Rte_Prm_BmwDrvgDynStMac_BmwDrvgDynStMacMotTqCmdOvrlActvtThd_Val

# define Rte_Prm_BmwDrvgDynStMacMotTqCmdOvrlDeactvtThd_Val Rte_Prm_BmwDrvgDynStMac_BmwDrvgDynStMacMotTqCmdOvrlDeactvtThd_Val

# define Rte_Prm_BmwDrvgDynStMacRtnCmdScaDft_Val Rte_Prm_BmwDrvgDynStMac_BmwDrvgDynStMacRtnCmdScaDft_Val

# define Rte_Prm_BmwDrvgDynStMacAssiLvlThd_Val Rte_Prm_BmwDrvgDynStMac_BmwDrvgDynStMacAssiLvlThd_Val

# define Rte_Prm_BmwDrvgDynStMacErrIfTmrThd_Val Rte_Prm_BmwDrvgDynStMac_BmwDrvgDynStMacErrIfTmrThd_Val

# define Rte_Prm_BmwDrvgDynStMacVehCdnTmrThd_Val Rte_Prm_BmwDrvgDynStMac_BmwDrvgDynStMacVehCdnTmrThd_Val

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_AssiLvlActvtTi() (Rte_Inst_BmwDrvgDynStMac->Pim_AssiLvlActvtTi) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_AssiLvlDeactvtTi() (Rte_Inst_BmwDrvgDynStMac->Pim_AssiLvlDeactvtTi) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_ErrIfTi() (Rte_Inst_BmwDrvgDynStMac->Pim_ErrIfTi) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_VehCdnTi() (Rte_Inst_BmwDrvgDynStMac->Pim_VehCdnTi) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_StMacSt() (Rte_Inst_BmwDrvgDynStMac->Pim_StMacSt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MotTqCmdPwrLimdCdnActvt() (Rte_Inst_BmwDrvgDynStMac->Pim_MotTqCmdPwrLimdCdnActvt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MotTqCmdPwrLimdCdnDeactvt() (Rte_Inst_BmwDrvgDynStMac->Pim_MotTqCmdPwrLimdCdnDeactvt) /* PRQA S 3453 */ /* MD_MSR_19.7 */




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   uint32 *Rte_Pim_AssiLvlActvtTi(void)
 *   uint32 *Rte_Pim_AssiLvlDeactvtTi(void)
 *   uint32 *Rte_Pim_ErrIfTi(void)
 *   uint32 *Rte_Pim_VehCdnTi(void)
 *   uint8 *Rte_Pim_StMacSt(void)
 *   boolean *Rte_Pim_MotTqCmdPwrLimdCdnActvt(void)
 *   boolean *Rte_Pim_MotTqCmdPwrLimdCdnDeactvt(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_BmwDrvgDynStMacDampgCmdScaDft_Val(void)
 *   float32 Rte_Prm_BmwDrvgDynStMacEffortCmdScaDft_Val(void)
 *   float32 Rte_Prm_BmwDrvgDynStMacMotTqCmdOvrlActvtThd_Val(void)
 *   float32 Rte_Prm_BmwDrvgDynStMacMotTqCmdOvrlDeactvtThd_Val(void)
 *   float32 Rte_Prm_BmwDrvgDynStMacRtnCmdScaDft_Val(void)
 *   uint16 Rte_Prm_BmwDrvgDynStMacAssiLvlThd_Val(void)
 *   uint16 Rte_Prm_BmwDrvgDynStMacErrIfTmrThd_Val(void)
 *   uint16 Rte_Prm_BmwDrvgDynStMacVehCdnTmrThd_Val(void)
 *
 *********************************************************************************************************************/


# define BmwDrvgDynStMac_START_SEC_CODE
# include "BmwDrvgDynStMac_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwDrvgDynStMacInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_MotTqCmdPwrLimd_Val(float32 *data)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_BmwDrvgDynStMacInit1 BmwDrvgDynStMacInit1
FUNC(void, BmwDrvgDynStMac_CODE) BmwDrvgDynStMacInit1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwDrvgDynStMacPer1
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
 *   Std_ReturnType Rte_Read_BmwDrvgDynEnaReq_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_BmwDrvgDynFacQlfr_Val(BmwOvrlCmdQlfr1 *data)
 *   Std_ReturnType Rte_Read_BmwDrvgDynFacQlfrVld_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_BmwTarHwTqOvrlQlfr_Val(BmwOvrlCmdQlfr1 *data)
 *   Std_ReturnType Rte_Read_BmwTarHwTqOvrlQlfrVld_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_BmwTarSteerTqDrvrActrQlfr_Val(BmwOvrlCmdQlfr1 *data)
 *   Std_ReturnType Rte_Read_BmwTarSteerTqDrvrActrQlfrVld_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_BmwTrfcJamAssiDampgStReq_Val(BmwTrfcJamAssiDampgStReq1 *data)
 *   Std_ReturnType Rte_Read_BmwTrfcJamAssiDampgStReqVld_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_BmwVehCdn_Val(BmwVehCdn1 *data)
 *   Std_ReturnType Rte_Read_DampgCmdSca_Val(float32 *data)
 *   Std_ReturnType Rte_Read_DiagcStsCtrldShtDwnFltPrsnt_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_DiagcStsNonRcvrlReqDiFltPrsnt_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_EffortCmdSca_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotTqCmdPwrLimd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotTqOvrlCmd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_RtnCmdSca_Val(float32 *data)
 *   Std_ReturnType Rte_Read_StsSteerAssi_Val(StsSteerAssi1 *data)
 *   Std_ReturnType Rte_Read_SysStFltOutpReqDi_Logl(boolean *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_DrvgDynActv_Logl(boolean data)
 *   Std_ReturnType Rte_Write_DrvgDynIfSt_Val(DrvgDynIfSt1 data)
 *   Std_ReturnType Rte_Write_OutpTqOvrlRampInEna_Logl(boolean data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_GetRefTmr100MicroSec32bit_Oper(uint32 *RefTmr_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_BmwDrvgDynStMacPer1 BmwDrvgDynStMacPer1
FUNC(void, BmwDrvgDynStMac_CODE) BmwDrvgDynStMacPer1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define BmwDrvgDynStMac_STOP_SEC_CODE
# include "BmwDrvgDynStMac_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_BMWDRVGDYNSTMAC_H */

#include "Rte_Stubs.h"
