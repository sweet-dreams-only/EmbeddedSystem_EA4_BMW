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
 *          File:  Rte_BmwDiagcSrvHndlg.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <BmwDiagcSrvHndlg>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_BMWDIAGCSRVHNDLG_H
# define _RTE_BMWDIAGCSRVHNDLG_H

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

# include "Rte_BmwDiagcSrvHndlg_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_Appl7_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_INIT) Rte_SysKineAndEff_HwVel_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_LrnPinionCentr_PinionCentrLrnHwTrvl_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_INIT) Rte_LrnPinionCentr_PinionCentrLrnSt_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_Appl7_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_Appl8_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_INIT) Rte_TurnCntrCorrln_TurnCntrCorrlnSts_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_Appl8_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_Appl9_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_INIT) Rte_EcuTMeas_EcuTFild_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwVehSpd_VehSpd_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_Appl9_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_INIT) Rte_BmwDiagcSrvHndlg_BmwHwAgOffs_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwDiagcSrvHndlg_LockToLockEna_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(BmwBasPtlNetCtrl1, RTE_VAR_INIT) Rte_BmwMsgSlot121Bas1Repn2BusFrChA_BmwBasPtlNetCtrl_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_INIT) Rte_BmwMsgSlot276Bas4Repn8BusFrChA_BmwOdomDst_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwMsgSlot276Bas4Repn8BusFrChA_BmwOdomDstVld_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwHwAgArbnAndEotPosn_BmwPinionAg_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(BmwPinionAgQlfr1, RTE_VAR_INIT) Rte_BmwHwAgArbnAndEotPosn_BmwPinionAgQlfr_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwHwAgArbnAndEotPosn_BmwRackCentrToVehCentrOffs_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwHwAgArbnAndEotPosn_BmwRackCentrToVehCentrOffsVld_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(BmwVehCdn1, RTE_VAR_INIT) Rte_BmwMsgSlot121Bas1Repn2BusFrChA_BmwVehCdn_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BattVltg_BrdgVltg_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(DrvgDynIfSt1, RTE_VAR_INIT) Rte_BmwDrvgDynStMac_DrvgDynIfSt_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_HwTqArbn_HwTq_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_INIT) Rte_HwTqCorrln_HwTqIdptSig_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_LrndRackCentr_LongTermRackCentrCmpl_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwHwAgArbnAndEotPosn_LongTermVehCentrCmpl_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_MotTqCmdSca_MotTqCmdMrfScad_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwHwAgArbnAndEotPosn_PinionAg_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwHwAgArbnAndEotPosn_PinionAgConf_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_LrndRackCentr_RackCentrCmpl_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_LrndRackCentr_RackCentrMotAgErrPrsnt_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_LrndRackCentr_RackCentrMotAgVld_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(SysSt1, RTE_VAR_INIT) Rte_SysStMod_SysSt_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_LrndRackCentr_TotRackTrvl_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_BmwBasPtlNetCtrl_Val (15U)
#  define Rte_InitValue_BmwHwAgOffs_Val (0.0F)
#  define Rte_InitValue_BmwOdomDst_Val (0U)
#  define Rte_InitValue_BmwOdomDstVld_Logl (FALSE)
#  define Rte_InitValue_BmwPinionAg_Val (0.0F)
#  define Rte_InitValue_BmwPinionAgQlfr_Val (14U)
#  define Rte_InitValue_BmwRackCentrToVehCentrOffs_Val (0.0F)
#  define Rte_InitValue_BmwRackCntrToVehCntrOffsVld_Logl (FALSE)
#  define Rte_InitValue_BmwVehCdn_Val (15U)
#  define Rte_InitValue_BrdgVltg_Val (6.0F)
#  define Rte_InitValue_DrvgDynIfSt_Val (128U)
#  define Rte_InitValue_EcuTFild_Val (25.0F)
#  define Rte_InitValue_HwTq_Val (0.0F)
#  define Rte_InitValue_HwTqIdptSig_Val (4U)
#  define Rte_InitValue_HwVel_Val (0.0F)
#  define Rte_InitValue_LockToLockEna_Logl (FALSE)
#  define Rte_InitValue_LongTermRackCentrCmpl_Logl (FALSE)
#  define Rte_InitValue_LongTermVehCentrCmpl_Logl (FALSE)
#  define Rte_InitValue_MotTqCmdMrfScad_Val (0.0F)
#  define Rte_InitValue_PinionAg_Val (0.0F)
#  define Rte_InitValue_PinionAgConf_Val (0.0F)
#  define Rte_InitValue_PinionCentrLrnHwTrvl_Val (0.0F)
#  define Rte_InitValue_PinionCentrLrnSt_Val (0U)
#  define Rte_InitValue_RackCentrCmpl_Logl (FALSE)
#  define Rte_InitValue_RackCentrMotAgErrPrsnt_Logl (FALSE)
#  define Rte_InitValue_RackCentrMotAgVld_Logl (FALSE)
#  define Rte_InitValue_SysSt_Val (3U)
#  define Rte_InitValue_TotRackTrvl_Val (0.0F)
#  define Rte_InitValue_TurnCntrCorrlnSts_Val (3U)
#  define Rte_InitValue_VehSpd_Val (0.0F)
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_BmwBasPtlNetCtrl_Val Rte_Read_BmwDiagcSrvHndlg_BmwBasPtlNetCtrl_Val
#  define Rte_Read_BmwDiagcSrvHndlg_BmwBasPtlNetCtrl_Val(data) (*(data) = Rte_BmwMsgSlot121Bas1Repn2BusFrChA_BmwBasPtlNetCtrl_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BmwOdomDst_Val Rte_Read_BmwDiagcSrvHndlg_BmwOdomDst_Val
#  define Rte_Read_BmwDiagcSrvHndlg_BmwOdomDst_Val(data) (*(data) = Rte_BmwMsgSlot276Bas4Repn8BusFrChA_BmwOdomDst_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BmwOdomDstVld_Logl Rte_Read_BmwDiagcSrvHndlg_BmwOdomDstVld_Logl
#  define Rte_Read_BmwDiagcSrvHndlg_BmwOdomDstVld_Logl(data) (*(data) = Rte_BmwMsgSlot276Bas4Repn8BusFrChA_BmwOdomDstVld_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BmwPinionAg_Val Rte_Read_BmwDiagcSrvHndlg_BmwPinionAg_Val
#  define Rte_Read_BmwDiagcSrvHndlg_BmwPinionAg_Val(data) (*(data) = Rte_BmwHwAgArbnAndEotPosn_BmwPinionAg_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BmwPinionAgQlfr_Val Rte_Read_BmwDiagcSrvHndlg_BmwPinionAgQlfr_Val
#  define Rte_Read_BmwDiagcSrvHndlg_BmwPinionAgQlfr_Val(data) (*(data) = Rte_BmwHwAgArbnAndEotPosn_BmwPinionAgQlfr_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BmwRackCentrToVehCentrOffs_Val Rte_Read_BmwDiagcSrvHndlg_BmwRackCentrToVehCentrOffs_Val
#  define Rte_Read_BmwDiagcSrvHndlg_BmwRackCentrToVehCentrOffs_Val(data) (*(data) = Rte_BmwHwAgArbnAndEotPosn_BmwRackCentrToVehCentrOffs_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BmwRackCntrToVehCntrOffsVld_Logl Rte_Read_BmwDiagcSrvHndlg_BmwRackCntrToVehCntrOffsVld_Logl
#  define Rte_Read_BmwDiagcSrvHndlg_BmwRackCntrToVehCntrOffsVld_Logl(data) (*(data) = Rte_BmwHwAgArbnAndEotPosn_BmwRackCentrToVehCentrOffsVld_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BmwVehCdn_Val Rte_Read_BmwDiagcSrvHndlg_BmwVehCdn_Val
#  define Rte_Read_BmwDiagcSrvHndlg_BmwVehCdn_Val(data) (*(data) = Rte_BmwMsgSlot121Bas1Repn2BusFrChA_BmwVehCdn_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BrdgVltg_Val Rte_Read_BmwDiagcSrvHndlg_BrdgVltg_Val
#  define Rte_Read_BmwDiagcSrvHndlg_BrdgVltg_Val(data) (*(data) = Rte_BattVltg_BrdgVltg_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_DrvgDynIfSt_Val Rte_Read_BmwDiagcSrvHndlg_DrvgDynIfSt_Val
#  define Rte_Read_BmwDiagcSrvHndlg_DrvgDynIfSt_Val(data) (*(data) = Rte_BmwDrvgDynStMac_DrvgDynIfSt_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_EcuTFild_Val Rte_Read_BmwDiagcSrvHndlg_EcuTFild_Val
#  define Rte_Read_BmwDiagcSrvHndlg_EcuTFild_Val(data) (*(data) = Rte_EcuTMeas_EcuTFild_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_HwTq_Val Rte_Read_BmwDiagcSrvHndlg_HwTq_Val
#  define Rte_Read_BmwDiagcSrvHndlg_HwTq_Val(data) (*(data) = Rte_HwTqArbn_HwTq_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_HwTqIdptSig_Val Rte_Read_BmwDiagcSrvHndlg_HwTqIdptSig_Val
#  define Rte_Read_BmwDiagcSrvHndlg_HwTqIdptSig_Val(data) (*(data) = Rte_HwTqCorrln_HwTqIdptSig_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_HwVel_Val Rte_Read_BmwDiagcSrvHndlg_HwVel_Val
#  define Rte_Read_BmwDiagcSrvHndlg_HwVel_Val(data) (*(data) = Rte_SysKineAndEff_HwVel_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_LongTermRackCentrCmpl_Logl Rte_Read_BmwDiagcSrvHndlg_LongTermRackCentrCmpl_Logl
#  define Rte_Read_BmwDiagcSrvHndlg_LongTermRackCentrCmpl_Logl(data) (*(data) = Rte_LrndRackCentr_LongTermRackCentrCmpl_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_LongTermVehCentrCmpl_Logl Rte_Read_BmwDiagcSrvHndlg_LongTermVehCentrCmpl_Logl
#  define Rte_Read_BmwDiagcSrvHndlg_LongTermVehCentrCmpl_Logl(data) (*(data) = Rte_BmwHwAgArbnAndEotPosn_LongTermVehCentrCmpl_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotTqCmdMrfScad_Val Rte_Read_BmwDiagcSrvHndlg_MotTqCmdMrfScad_Val
#  define Rte_Read_BmwDiagcSrvHndlg_MotTqCmdMrfScad_Val(data) (*(data) = Rte_MotTqCmdSca_MotTqCmdMrfScad_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_PinionAg_Val Rte_Read_BmwDiagcSrvHndlg_PinionAg_Val
#  define Rte_Read_BmwDiagcSrvHndlg_PinionAg_Val(data) (*(data) = Rte_BmwHwAgArbnAndEotPosn_PinionAg_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_PinionAgConf_Val Rte_Read_BmwDiagcSrvHndlg_PinionAgConf_Val
#  define Rte_Read_BmwDiagcSrvHndlg_PinionAgConf_Val(data) (*(data) = Rte_BmwHwAgArbnAndEotPosn_PinionAgConf_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_PinionCentrLrnHwTrvl_Val Rte_Read_BmwDiagcSrvHndlg_PinionCentrLrnHwTrvl_Val
#  define Rte_Read_BmwDiagcSrvHndlg_PinionCentrLrnHwTrvl_Val(data) (*(data) = Rte_LrnPinionCentr_PinionCentrLrnHwTrvl_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_PinionCentrLrnSt_Val Rte_Read_BmwDiagcSrvHndlg_PinionCentrLrnSt_Val
#  define Rte_Read_BmwDiagcSrvHndlg_PinionCentrLrnSt_Val(data) (*(data) = Rte_LrnPinionCentr_PinionCentrLrnSt_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_RackCentrCmpl_Logl Rte_Read_BmwDiagcSrvHndlg_RackCentrCmpl_Logl
#  define Rte_Read_BmwDiagcSrvHndlg_RackCentrCmpl_Logl(data) (*(data) = Rte_LrndRackCentr_RackCentrCmpl_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_RackCentrMotAgErrPrsnt_Logl Rte_Read_BmwDiagcSrvHndlg_RackCentrMotAgErrPrsnt_Logl
#  define Rte_Read_BmwDiagcSrvHndlg_RackCentrMotAgErrPrsnt_Logl(data) (*(data) = Rte_LrndRackCentr_RackCentrMotAgErrPrsnt_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_RackCentrMotAgVld_Logl Rte_Read_BmwDiagcSrvHndlg_RackCentrMotAgVld_Logl
#  define Rte_Read_BmwDiagcSrvHndlg_RackCentrMotAgVld_Logl(data) (*(data) = Rte_LrndRackCentr_RackCentrMotAgVld_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_SysSt_Val Rte_Read_BmwDiagcSrvHndlg_SysSt_Val
#  define Rte_Read_BmwDiagcSrvHndlg_SysSt_Val(data) (*(data) = Rte_SysStMod_SysSt_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_TotRackTrvl_Val Rte_Read_BmwDiagcSrvHndlg_TotRackTrvl_Val
#  define Rte_Read_BmwDiagcSrvHndlg_TotRackTrvl_Val(data) (*(data) = Rte_LrndRackCentr_TotRackTrvl_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_TurnCntrCorrlnSts_Val Rte_Read_BmwDiagcSrvHndlg_TurnCntrCorrlnSts_Val
#  define Rte_Read_BmwDiagcSrvHndlg_TurnCntrCorrlnSts_Val(data) (*(data) = Rte_TurnCntrCorrln_TurnCntrCorrlnSts_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_VehSpd_Val Rte_Read_BmwDiagcSrvHndlg_VehSpd_Val
#  define Rte_Read_BmwDiagcSrvHndlg_VehSpd_Val(data) (*(data) = Rte_BmwVehSpd_VehSpd_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_BmwHwAgOffs_Val Rte_Write_BmwDiagcSrvHndlg_BmwHwAgOffs_Val
#  define Rte_Write_BmwDiagcSrvHndlg_BmwHwAgOffs_Val(data) (Rte_BmwDiagcSrvHndlg_BmwHwAgOffs_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_LockToLockEna_Logl Rte_Write_BmwDiagcSrvHndlg_LockToLockEna_Logl
#  define Rte_Write_BmwDiagcSrvHndlg_LockToLockEna_Logl(data) (Rte_BmwDiagcSrvHndlg_LockToLockEna_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_BMWHWAGARBNANDEOTPOSN_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_BMWHWAGARBNANDEOTPOSN_APPL_CODE) ClrBmwRackCentrToVehCentrOffs_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_BMWHWAGARBNANDEOTPOSN_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_ClrBmwRackCentrToVehCentrOffs_Oper() (ClrBmwRackCentrToVehCentrOffs_Oper(), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_BMWHWAGARBNANDEOTPOSN_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_BMWHWAGARBNANDEOTPOSN_APPL_CODE) ClrVehCentrPosn_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_BMWHWAGARBNANDEOTPOSN_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_ClrVehCentrPosn_Oper() (ClrVehCentrPosn_Oper(), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_DIAGCMGRPROXYAPPL10_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_DIAGCMGRPROXYAPPL10_APPL_CODE) GetNtcActv10_Oper(NtcNr1 NtcNr_Arg, P2VAR(boolean, AUTOMATIC, RTE_DIAGCMGRPROXYAPPL10_APPL_VAR) NtcActv_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DIAGCMGRPROXYAPPL10_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_GetNtcActv_Oper GetNtcActv10_Oper
#  define RTE_START_SEC_CDD_NXTRTI_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_CDD_NXTRTI_APPL_CODE) GetRefTmr1MicroSec32bit_Oper(P2VAR(uint32, AUTOMATIC, RTE_CDD_NXTRTI_APPL_VAR) RefTmr_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CDD_NXTRTI_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_GetRefTmr1MicroSec32bit_Oper(arg1) (GetRefTmr1MicroSec32bit_Oper(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_CDD_NXTRTI_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_CDD_NXTRTI_APPL_CODE) GetTiSpan1MicroSec32bit_Oper(uint32 RefTmr_Arg, P2VAR(uint32, AUTOMATIC, RTE_CDD_NXTRTI_APPL_VAR) TiSpan_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CDD_NXTRTI_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_GetTiSpan1MicroSec32bit_Oper(arg1, arg2) (GetTiSpan1MicroSec32bit_Oper(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_NVMPROXY_APPL_CODE) NvMProxy_SetRamBlockStatus(NvM_BlockIdType parg0, boolean RamBlockStatus_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_MilesKmEeprom_SetRamBlockStatus(arg1) (NvMProxy_SetRamBlockStatus((NvM_BlockIdType)7, arg1)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_NVMPROXY_APPL_CODE) NvMProxy_GetErrorStatus(NvM_BlockIdType parg0, P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_NVMPROXY_APPL_VAR) ErrorStatus_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_ProgCntr_GetErrorStatus(arg1) (NvMProxy_GetErrorStatus((NvM_BlockIdType)6, arg1)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_ProgCntrMaxVal_SetRamBlockStatus(arg1) (NvMProxy_SetRamBlockStatus((NvM_BlockIdType)5, arg1)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_LRNDRACKCENTR_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_LRNDRACKCENTR_APPL_CODE) RstRackCentrMotAg_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_LRNDRACKCENTR_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_RstRackCentrMotAg_Oper() (RstRackCentrMotAg_Oper(), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_LRNDRACKCENTR_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_LRNDRACKCENTR_APPL_CODE) RstRackCentrMotRev_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_LRNDRACKCENTR_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_RstRackCentrMotRev_Oper() (RstRackCentrMotRev_Oper(), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_LRNPINIONCENTR_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_LRNPINIONCENTR_APPL_CODE) SetInpPrm_Oper(float32 TarVel_Arg, float32 TarA_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_LRNPINIONCENTR_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_SetInpPrm_Oper(arg1, arg2) (SetInpPrm_Oper(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_BMWHWAGARBNANDEOTPOSN_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_BMWHWAGARBNANDEOTPOSN_APPL_CODE) SetVehCentrPosn_Oper(P2VAR(BmwSetVehCentrOffsSts1, AUTOMATIC, RTE_BMWHWAGARBNANDEOTPOSN_APPL_VAR) BmwSetVehCentrOffsSts_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_BMWHWAGARBNANDEOTPOSN_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_SetVehCentrPosn_Oper(arg1) (SetVehCentrPosn_Oper(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_TestStamp_GetErrorStatus(arg1) (NvMProxy_GetErrorStatus((NvM_BlockIdType)4, arg1)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_TestStamp_SetRamBlockStatus(arg1) (NvMProxy_SetRamBlockStatus((NvM_BlockIdType)4, arg1)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_CData (SW-C local calibration parameters)
 *********************************************************************************************************************/

#  define Rte_CData_NvmProgCntr_DefaultValue() (((P2CONST(Rte_Calprm_BmwDiagcSrvHndlg_DEFAULT_RTE_CDATA_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_BmwDiagcSrvHndlg_DEFAULT_RTE_CDATA_GROUP])->NvmProgCntr_DefaultValue) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_CData_ProgCntrMaxValDft() (((P2CONST(Rte_Calprm_BmwDiagcSrvHndlg_DEFAULT_RTE_CDATA_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_BmwDiagcSrvHndlg_DEFAULT_RTE_CDATA_GROUP])->ProgCntrMaxValDft) /* PRQA S 3453 */ /* MD_MSR_19.7 */

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwDiagcSrvHndlg_LrndPinionCentrHwTrvl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwDiagcSrvHndlg_RoutineHwPosStrt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwDiagcSrvHndlg_TarHwA; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwDiagcSrvHndlg_TarHwVel; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwDiagcSrvHndlg_HandsONAbortTi; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwDiagcSrvHndlg_HandsONStrtTi; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwDiagcSrvHndlg_HwAgAbortTi; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwDiagcSrvHndlg_HwVelAbortTi; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwDiagcSrvHndlg_MilesKmEeprom; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwDiagcSrvHndlg_OperStEnaWaitTi; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwDiagcSrvHndlg_PrevCycleMilesKmEeprom; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwDiagcSrvHndlg_ActvRid; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwDiagcSrvHndlg_ProgCntr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwDiagcSrvHndlg_ProgCntrMaxVal; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwDiagcSrvHndlg_LockToLockRountineSts; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwDiagcSrvHndlg_HandsONAbort; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwDiagcSrvHndlg_HandsONStrt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwDiagcSrvHndlg_HwAgOrHwVelChkRes; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwDiagcSrvHndlg_OperStPreStrtChk; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(Ary1D_u08_3, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwDiagcSrvHndlg_TestStamp; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  endif

#  define Rte_Pim_LrndPinionCentrHwTrvl() \
  (&Rte_BmwDiagcSrvHndlg_LrndPinionCentrHwTrvl) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_RoutineHwPosStrt() \
  (&Rte_BmwDiagcSrvHndlg_RoutineHwPosStrt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_TarHwA() \
  (&Rte_BmwDiagcSrvHndlg_TarHwA) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_TarHwVel() \
  (&Rte_BmwDiagcSrvHndlg_TarHwVel) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_HandsONAbortTi() \
  (&Rte_BmwDiagcSrvHndlg_HandsONAbortTi) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_HandsONStrtTi() \
  (&Rte_BmwDiagcSrvHndlg_HandsONStrtTi) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_HwAgAbortTi() \
  (&Rte_BmwDiagcSrvHndlg_HwAgAbortTi) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_HwVelAbortTi() \
  (&Rte_BmwDiagcSrvHndlg_HwVelAbortTi) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MilesKmEeprom() \
  (&Rte_BmwDiagcSrvHndlg_MilesKmEeprom) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_OperStEnaWaitTi() \
  (&Rte_BmwDiagcSrvHndlg_OperStEnaWaitTi) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_PrevCycleMilesKmEeprom() \
  (&Rte_BmwDiagcSrvHndlg_PrevCycleMilesKmEeprom) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_ActvRid() \
  (&Rte_BmwDiagcSrvHndlg_ActvRid) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_ProgCntr() \
  (&Rte_BmwDiagcSrvHndlg_ProgCntr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_ProgCntrMaxVal() \
  (&Rte_BmwDiagcSrvHndlg_ProgCntrMaxVal) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_LockToLockRountineSts() \
  (&Rte_BmwDiagcSrvHndlg_LockToLockRountineSts) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_HandsONAbort() \
  (&Rte_BmwDiagcSrvHndlg_HandsONAbort) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_HandsONStrt() \
  (&Rte_BmwDiagcSrvHndlg_HandsONStrt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_HwAgOrHwVelChkRes() \
  (&Rte_BmwDiagcSrvHndlg_HwAgOrHwVelChkRes) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_OperStPreStrtChk() \
  (&Rte_BmwDiagcSrvHndlg_OperStPreStrtChk) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_TestStamp() (&((*RtePim_TestStamp())[0]))
#  else
#   define Rte_Pim_TestStamp() RtePim_TestStamp()
#  endif
#  define RtePim_TestStamp() \
  (&Rte_BmwDiagcSrvHndlg_TestStamp) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define BmwDiagcSrvHndlg_START_SEC_CODE
# include "BmwDiagcSrvHndlg_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_BmwDiagcSrvFHndlMileageRead_Oper BmwDiagcSrvFHndlMileageRead_Oper
#  define RTE_RUNNABLE_BmwDiagcSrvFHndlgAmbTRead_Oper BmwDiagcSrvFHndlgAmbTRead_Oper
#  define RTE_RUNNABLE_BmwDiagcSrvFHndlgEpsBaseNwRead_Oper BmwDiagcSrvFHndlgEpsBaseNwRead_Oper
#  define RTE_RUNNABLE_BmwDiagcSrvFHndlgEpsBattVltgRead_Oper BmwDiagcSrvFHndlgEpsBattVltgRead_Oper
#  define RTE_RUNNABLE_BmwDiagcSrvFHndlgEpsFactryIninRes_Oper BmwDiagcSrvFHndlgEpsFactryIninRes_Oper
#  define RTE_RUNNABLE_BmwDiagcSrvFHndlgEpsFactryIninStop_Oper BmwDiagcSrvFHndlgEpsFactryIninStop_Oper
#  define RTE_RUNNABLE_BmwDiagcSrvFHndlgEpsFactryIninStrt_Oper BmwDiagcSrvFHndlgEpsFactryIninStrt_Oper
#  define RTE_RUNNABLE_BmwDiagcSrvFHndlgEpsPinionAgSnsrReadCdnChk_Oper BmwDiagcSrvFHndlgEpsPinionAgSnsrReadCdnChk_Oper
#  define RTE_RUNNABLE_BmwDiagcSrvFHndlgEpsPinionAgSnsrRead_Oper BmwDiagcSrvFHndlgEpsPinionAgSnsrRead_Oper
#  define RTE_RUNNABLE_BmwDiagcSrvFHndlgEpsProgCntrMaxValWrite_Oper BmwDiagcSrvFHndlgEpsProgCntrMaxValWrite_Oper
#  define RTE_RUNNABLE_BmwDiagcSrvFHndlgEpsSteerAgSnsrCalReadCdnChk_Oper BmwDiagcSrvFHndlgEpsSteerAgSnsrCalReadCdnChk_Oper
#  define RTE_RUNNABLE_BmwDiagcSrvFHndlgEpsSteerAgSnsrCalRead_Oper BmwDiagcSrvFHndlgEpsSteerAgSnsrCalRead_Oper
#  define RTE_RUNNABLE_BmwDiagcSrvFHndlgEpsSteerAgSnsrCalWrite_Oper BmwDiagcSrvFHndlgEpsSteerAgSnsrCalWrite_Oper
#  define RTE_RUNNABLE_BmwDiagcSrvFHndlgEpsTestStampReadCdnChk_Oper BmwDiagcSrvFHndlgEpsTestStampReadCdnChk_Oper
#  define RTE_RUNNABLE_BmwDiagcSrvFHndlgEpsTestStampRead_Oper BmwDiagcSrvFHndlgEpsTestStampRead_Oper
#  define RTE_RUNNABLE_BmwDiagcSrvFHndlgEpsTestStampWrite_Oper BmwDiagcSrvFHndlgEpsTestStampWrite_Oper
#  define RTE_RUNNABLE_BmwDiagcSrvFHndlgHwAgRead_Oper BmwDiagcSrvFHndlgHwAgRead_Oper
#  define RTE_RUNNABLE_BmwDiagcSrvFHndlgHwTqRead_Oper BmwDiagcSrvFHndlgHwTqRead_Oper
#  define RTE_RUNNABLE_BmwDiagcSrvFHndlgMileKmEepromReadCdnChk_Oper BmwDiagcSrvFHndlgMileKmEepromReadCdnChk_Oper
#  define RTE_RUNNABLE_BmwDiagcSrvFHndlgMileKmEepromRead_Oper BmwDiagcSrvFHndlgMileKmEepromRead_Oper
#  define RTE_RUNNABLE_BmwDiagcSrvFHndlgMotTqRead_Oper BmwDiagcSrvFHndlgMotTqRead_Oper
#  define RTE_RUNNABLE_BmwDiagcSrvFHndlgProgmCntrMaxValReadCdnChk_Oper BmwDiagcSrvFHndlgProgmCntrMaxValReadCdnChk_Oper
#  define RTE_RUNNABLE_BmwDiagcSrvFHndlgProgmCntrMaxValRead_Oper BmwDiagcSrvFHndlgProgmCntrMaxValRead_Oper
#  define RTE_RUNNABLE_BmwDiagcSrvFHndlgProgmCntrRead_Oper BmwDiagcSrvFHndlgProgmCntrRead_Oper
#  define RTE_RUNNABLE_BmwDiagcSrvFHndlgPscmStsRead_Oper BmwDiagcSrvFHndlgPscmStsRead_Oper
#  define RTE_RUNNABLE_BmwDiagcSrvFHndlgReadSwRevisionCdnChk_Oper BmwDiagcSrvFHndlgReadSwRevisionCdnChk_Oper
#  define RTE_RUNNABLE_BmwDiagcSrvFHndlgReadSwRevision_Oper BmwDiagcSrvFHndlgReadSwRevision_Oper
#  define RTE_RUNNABLE_BmwDiagcSrvFHndlgStordRackTrvlAndCentrDataReadCdnChk_Oper BmwDiagcSrvFHndlgStordRackTrvlAndCentrDataReadCdnChk_Oper
#  define RTE_RUNNABLE_BmwDiagcSrvFHndlgStordRackTrvlAndCentrDataRead_Oper BmwDiagcSrvFHndlgStordRackTrvlAndCentrDataRead_Oper
#  define RTE_RUNNABLE_BmwDiagcSrvFHndlgSysSupplierIdentifierCdnChk_Oper BmwDiagcSrvFHndlgSysSupplierIdentifierCdnChk_Oper
#  define RTE_RUNNABLE_BmwDiagcSrvFHndlgSysSupplierIdentifierRead_Oper BmwDiagcSrvFHndlgSysSupplierIdentifierRead_Oper
#  define RTE_RUNNABLE_BmwDiagcSrvFHndlgVehSpdRead_Oper BmwDiagcSrvFHndlgVehSpdRead_Oper
#  define RTE_RUNNABLE_BmwDiagcSrvHndlgEpsCommuteRes_Oper BmwDiagcSrvHndlgEpsCommuteRes_Oper
#  define RTE_RUNNABLE_BmwDiagcSrvHndlgEpsCommuteStrt_Oper BmwDiagcSrvHndlgEpsCommuteStrt_Oper
#  define RTE_RUNNABLE_BmwDiagcSrvHndlgEpsIninSrvRes_Oper BmwDiagcSrvHndlgEpsIninSrvRes_Oper
#  define RTE_RUNNABLE_BmwDiagcSrvHndlgEpsIninSrvStop_Oper BmwDiagcSrvHndlgEpsIninSrvStop_Oper
#  define RTE_RUNNABLE_BmwDiagcSrvHndlgEpsIninSrvStrt_Oper BmwDiagcSrvHndlgEpsIninSrvStrt_Oper
#  define RTE_RUNNABLE_BmwDiagcSrvHndlgEpsProcRes_Oper BmwDiagcSrvHndlgEpsProcRes_Oper
#  define RTE_RUNNABLE_BmwDiagcSrvHndlgEpsProcStrt_Oper BmwDiagcSrvHndlgEpsProcStrt_Oper
#  define RTE_RUNNABLE_BmwDiagcSrvHndlgEpsPtlRackCentrRstStrt_Oper BmwDiagcSrvHndlgEpsPtlRackCentrRstStrt_Oper
#  define RTE_RUNNABLE_BmwDiagcSrvHndlgEpsRackCentrMotAgStsReadCdnChk_Oper BmwDiagcSrvHndlgEpsRackCentrMotAgStsReadCdnChk_Oper
#  define RTE_RUNNABLE_BmwDiagcSrvHndlgEpsRackCentrMotAgStsRead_Oper BmwDiagcSrvHndlgEpsRackCentrMotAgStsRead_Oper
#  define RTE_RUNNABLE_BmwDiagcSrvHndlgEpsRackCentrRstStrt_Oper BmwDiagcSrvHndlgEpsRackCentrRstStrt_Oper
#  define RTE_RUNNABLE_BmwDiagcSrvHndlgEpsSteerAgSnsrCalRstStrt_Oper BmwDiagcSrvHndlgEpsSteerAgSnsrCalRstStrt_Oper
#  define RTE_RUNNABLE_BmwDiagcSrvHndlgEpsTqSensrReadCdnChk_Oper BmwDiagcSrvHndlgEpsTqSensrReadCdnChk_Oper
#  define RTE_RUNNABLE_BmwDiagcSrvHndlgEpsTqSensrRead_Oper BmwDiagcSrvHndlgEpsTqSensrRead_Oper
#  define RTE_RUNNABLE_BmwDiagcSrvHndlgInit1 BmwDiagcSrvHndlgInit1
#  define RTE_RUNNABLE_BmwDiagcSrvHndlgPer1 BmwDiagcSrvHndlgPer1
#  define RTE_RUNNABLE_BmwDiagcSrvHndlgStatusFzgBordnetzReadCdnChk_Oper BmwDiagcSrvHndlgStatusFzgBordnetzReadCdnChk_Oper
#  define RTE_RUNNABLE_BmwDiagcSrvHndlgStatusFzgBordnetzRead_Oper BmwDiagcSrvHndlgStatusFzgBordnetzRead_Oper
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlMileageRead_Oper(P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlMileageRead_Oper(P2VAR(DataArrayType_uint8_3, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgAmbTRead_Oper(P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgAmbTRead_Oper(P2VAR(DataArrayType_uint8_1, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgEpsBaseNwRead_Oper(P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgEpsBaseNwRead_Oper(P2VAR(DataArrayType_uint8_1, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgEpsBattVltgRead_Oper(P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgEpsBattVltgRead_Oper(P2VAR(DataArrayType_uint8_1, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgEpsFactryIninRes_Oper(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) StatRoutineStatus_Out, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgEpsFactryIninStop_Oper(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgEpsFactryIninStrt_Oper(uint8 Winkel_In, uint8 Winkelgeschwindigkeit_In, uint8 Winkelbeschleunigung_In, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgEpsPinionAgSnsrReadCdnChk_Oper(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgEpsPinionAgSnsrRead_Oper(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgEpsPinionAgSnsrRead_Oper(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data7ByteType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgEpsProgCntrMaxValWrite_Oper(P2CONST(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgEpsProgCntrMaxValWrite_Oper(P2CONST(Dcm_Data2ByteType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgEpsSteerAgSnsrCalReadCdnChk_Oper(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgEpsSteerAgSnsrCalRead_Oper(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgEpsSteerAgSnsrCalRead_Oper(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgEpsSteerAgSnsrCalWrite_Oper(P2CONST(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgEpsSteerAgSnsrCalWrite_Oper(P2CONST(Dcm_Data2ByteType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgEpsTestStampReadCdnChk_Oper(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgEpsTestStampRead_Oper(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgEpsTestStampRead_Oper(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data3ByteType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgEpsTestStampWrite_Oper(P2CONST(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgEpsTestStampWrite_Oper(P2CONST(Dcm_Data3ByteType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgHwAgRead_Oper(P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgHwAgRead_Oper(P2VAR(DataArrayType_uint8_2, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgHwTqRead_Oper(P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgHwTqRead_Oper(P2VAR(DataArrayType_uint8_2, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgMileKmEepromReadCdnChk_Oper(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgMileKmEepromRead_Oper(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgMileKmEepromRead_Oper(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data3ByteType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgMotTqRead_Oper(P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgMotTqRead_Oper(P2VAR(DataArrayType_uint8_2, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgProgmCntrMaxValReadCdnChk_Oper(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgProgmCntrMaxValRead_Oper(P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgProgmCntrMaxValRead_Oper(P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgProgmCntrRead_Oper(P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgProgmCntrRead_Oper(P2VAR(ProgCounterArrayType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgPscmStsRead_Oper(P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgPscmStsRead_Oper(P2VAR(DataArrayType_uint8_2, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgReadSwRevisionCdnChk_Oper(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgReadSwRevision_Oper(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgReadSwRevision_Oper(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data140ByteType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgStordRackTrvlAndCentrDataReadCdnChk_Oper(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgStordRackTrvlAndCentrDataRead_Oper(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgStordRackTrvlAndCentrDataRead_Oper(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data8ByteType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgSysSupplierIdentifierCdnChk_Oper(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgSysSupplierIdentifierRead_Oper(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgSysSupplierIdentifierRead_Oper(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data3ByteType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgVehSpdRead_Oper(P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgVehSpdRead_Oper(P2VAR(DataArrayType_uint8_1, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvHndlgEpsCommuteRes_Oper(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) StatEpsPendelnAktivNr_Out, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvHndlgEpsCommuteStrt_Oper(uint8 Frequenz_In, uint8 MaxAmplitude_In, uint8 NumberOfCycles_In, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvHndlgEpsIninSrvRes_Oper(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) StatRoutineStatus_Out, P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) StatLenkradwinkelWert_Out, P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) StatSensorZustandNr_Out, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvHndlgEpsIninSrvRes_Oper(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) StatRoutineStatus_Out, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) StatLenkradwinkelWert_Out, P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) StatSensorZustandNr_Out, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvHndlgEpsIninSrvStop_Oper(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvHndlgEpsIninSrvStrt_Oper(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvHndlgEpsProcRes_Oper(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) StatEpsVerfahrenAktivNr_Out, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvHndlgEpsProcStrt_Oper(P2CONST(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_DATA) Winkel_In, uint8 Winkelgeschwindigkeit_In, uint8 Winkelbeschleunigung_In, uint8 AbsolutEin_In, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvHndlgEpsProcStrt_Oper(P2CONST(Dcm_Data2ByteType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_DATA) Winkel_In, uint8 Winkelgeschwindigkeit_In, uint8 Winkelbeschleunigung_In, uint8 AbsolutEin_In, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvHndlgEpsPtlRackCentrRstStrt_Oper(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvHndlgEpsRackCentrMotAgStsReadCdnChk_Oper(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvHndlgEpsRackCentrMotAgStsRead_Oper(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvHndlgEpsRackCentrMotAgStsRead_Oper(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvHndlgEpsRackCentrRstStrt_Oper(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvHndlgEpsSteerAgSnsrCalRstStrt_Oper(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvHndlgEpsTqSensrReadCdnChk_Oper(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvHndlgEpsTqSensrRead_Oper(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvHndlgEpsTqSensrRead_Oper(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data3ByteType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
FUNC(void, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvHndlgInit1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvHndlgPer1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvHndlgStatusFzgBordnetzReadCdnChk_Oper(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvHndlgStatusFzgBordnetzRead_Oper(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvHndlgStatusFzgBordnetzRead_Oper(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data15ByteType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif

# define BmwDiagcSrvHndlg_STOP_SEC_CODE
# include "BmwDiagcSrvHndlg_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_CSDataServices_DID_1700_KmStand_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_DID_1750_FUwBn_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_DID_2805_Aussentemperatur_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_DID_2866_Betriebsspannung_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_DID_2867_Fahrzeuggeschwindigkeit_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_DID_5003_HwAg_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_DID_500C_PscmSts_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_DID_500E_HwTq_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_DID_500F_MotTq_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_1000_Pruefstempel_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_1000_Pruefstempel_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_2503_ProgrammingCounterMaxValue_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_250B_ReadSwRevision_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_250B_ReadSwRevision_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_2540_MileKmEeprom_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_2540_MileKmEeprom_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_DB3C_StatusFzgBordnetz_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_DB3C_StatusFzgBordnetz_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_DB57_EpsRitzelwinkelsensor_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_DB57_EpsRitzelwinkelsensor_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_DB5A_EpsLenkwinkelsensorKalibrierung_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_DB5A_EpsLenkwinkelsensorKalibrierung_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_DB99_EpsMomentensensor_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_DB99_EpsMomentensensor_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_DC77_EpsZahnstangenmitte_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_DC77_EpsZahnstangenmitte_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_DFDD_GelernterZahnstangenweg_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_DFDD_GelernterZahnstangenweg_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_F18A_SystemSupplierIdentifier_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_F18A_SystemSupplierIdentifier_E_NOT_OK (1U)

#  define RTE_E_DataServices_ProgCounter_E_NOT_OK (1U)

#  define RTE_E_GetNtcActv1_PortIf1_E_NOT_OK (1U)

#  define RTE_E_NvMService_AC3_SRBS_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_EpsInitialisierungService_Routine_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_EpsInitialisierungService_Routine_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_EpsInitialisierungService_Routine_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_EpsInitialisierungWerk_Routine_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_EpsInitialisierungWerk_Routine_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_EpsInitialisierungWerk_Routine_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_EpsLenkwinkelsensorKalibrierungReset_Routine_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_EpsLenkwinkelsensorKalibrierungReset_Routine_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_EpsLenkwinkelsensorKalibrierungReset_Routine_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_EpsPendeln_Routine_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_EpsPendeln_Routine_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_EpsPendeln_Routine_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_EpsVerfahren_Routine_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_EpsVerfahren_Routine_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_EpsVerfahren_Routine_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_EpsZahnstangenmitteReset_Routine_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_EpsZahnstangenmitteReset_Routine_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_EpsZahnstangenmitteReset_Routine_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_SteuernEpsMultiturnwertReset_Routine_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_SteuernEpsMultiturnwertReset_Routine_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_SteuernEpsMultiturnwertReset_Routine_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_BMWDIAGCSRVHNDLG_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
