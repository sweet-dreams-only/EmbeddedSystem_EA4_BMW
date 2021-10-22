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
 *          File:  Rte_BmwMotTqOvrlArbn.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <BmwMotTqOvrlArbn>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_BMWMOTTQOVRLARBN_H
# define _RTE_BMWMOTTQOVRLARBN_H

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

# include "Rte_BmwMotTqOvrlArbn_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_Appl7_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(BmwTrfcJamAssiSt1, RTE_VAR_INIT) Rte_BmwTrfcJamAssiDampg_BmwTrfcJamAssiDampgSt_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_LrnPinionCentr_PinionCentrLrnCmd_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwTrfcJamAssiDampg_TrfcJamAssiCmd_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_Appl7_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_Appl9_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_INIT) Rte_BmwVehSpd_VehSpd_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_Appl9_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_INIT) Rte_BmwMotTqOvrlArbn_MotTqOvrlCmd_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(BmwNearStillVehSpdSts1, RTE_VAR_INIT) Rte_BmwMsgSlot55Bas3Repn4BusFrChA_BmwNearStillVehSpdSts_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwTqOvrlCdngAndDrvgDynFac_BmwOutpTqOvrlCmd_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwDrvgDynStMac_DrvgDynActv_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_TqOscn_HwOscnActv_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_TqOscn_HwOscnCmd_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_TqOscn_HwOscnDcThdExcdd_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwDiagcSrvHndlg_LockToLockEna_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_PosnTrakgServo_PosnServoCmd_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwMotTqOvrlArbn_PosnServoEna_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_PullCmpActv_PullCmpCmd_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_BmwNearStillVehSpdSts_Val (15U)
#  define Rte_InitValue_BmwOutpTqOvrlCmd_Val (0.0F)
#  define Rte_InitValue_BmwTrfcJamAssiDampgSt_Val (1U)
#  define Rte_InitValue_DrvgDynActv_Logl (FALSE)
#  define Rte_InitValue_HwOscnActv_Logl (FALSE)
#  define Rte_InitValue_HwOscnCmd_Val (0.0F)
#  define Rte_InitValue_HwOscnDcThdExcdd_Logl (FALSE)
#  define Rte_InitValue_MotTqOvrlCmd_Val (0.0F)
#  define Rte_InitValue_PinionCentrLrnCmd_Val (0.0F)
#  define Rte_InitValue_PinionCentrLrnEna_Logl (FALSE)
#  define Rte_InitValue_PosnServoCmd_Val (0.0F)
#  define Rte_InitValue_PosnServoEna_Logl (FALSE)
#  define Rte_InitValue_PullCmpCmd_Val (0.0F)
#  define Rte_InitValue_TrfcJamAssiCmd_Val (0.0F)
#  define Rte_InitValue_VehSpd_Val (0.0F)
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_BmwNearStillVehSpdSts_Val Rte_Read_BmwMotTqOvrlArbn_BmwNearStillVehSpdSts_Val
#  define Rte_Read_BmwMotTqOvrlArbn_BmwNearStillVehSpdSts_Val(data) (*(data) = Rte_BmwMsgSlot55Bas3Repn4BusFrChA_BmwNearStillVehSpdSts_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BmwOutpTqOvrlCmd_Val Rte_Read_BmwMotTqOvrlArbn_BmwOutpTqOvrlCmd_Val
#  define Rte_Read_BmwMotTqOvrlArbn_BmwOutpTqOvrlCmd_Val(data) (*(data) = Rte_BmwTqOvrlCdngAndDrvgDynFac_BmwOutpTqOvrlCmd_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BmwTrfcJamAssiDampgSt_Val Rte_Read_BmwMotTqOvrlArbn_BmwTrfcJamAssiDampgSt_Val
#  define Rte_Read_BmwMotTqOvrlArbn_BmwTrfcJamAssiDampgSt_Val(data) (*(data) = Rte_BmwTrfcJamAssiDampg_BmwTrfcJamAssiDampgSt_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_DrvgDynActv_Logl Rte_Read_BmwMotTqOvrlArbn_DrvgDynActv_Logl
#  define Rte_Read_BmwMotTqOvrlArbn_DrvgDynActv_Logl(data) (*(data) = Rte_BmwDrvgDynStMac_DrvgDynActv_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_HwOscnActv_Logl Rte_Read_BmwMotTqOvrlArbn_HwOscnActv_Logl
#  define Rte_Read_BmwMotTqOvrlArbn_HwOscnActv_Logl(data) (*(data) = Rte_TqOscn_HwOscnActv_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_HwOscnCmd_Val Rte_Read_BmwMotTqOvrlArbn_HwOscnCmd_Val
#  define Rte_Read_BmwMotTqOvrlArbn_HwOscnCmd_Val(data) (*(data) = Rte_TqOscn_HwOscnCmd_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_HwOscnDcThdExcdd_Logl Rte_Read_BmwMotTqOvrlArbn_HwOscnDcThdExcdd_Logl
#  define Rte_Read_BmwMotTqOvrlArbn_HwOscnDcThdExcdd_Logl(data) (*(data) = Rte_TqOscn_HwOscnDcThdExcdd_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_PinionCentrLrnCmd_Val Rte_Read_BmwMotTqOvrlArbn_PinionCentrLrnCmd_Val
#  define Rte_Read_BmwMotTqOvrlArbn_PinionCentrLrnCmd_Val(data) (*(data) = Rte_LrnPinionCentr_PinionCentrLrnCmd_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_PinionCentrLrnEna_Logl Rte_Read_BmwMotTqOvrlArbn_PinionCentrLrnEna_Logl
#  define Rte_Read_BmwMotTqOvrlArbn_PinionCentrLrnEna_Logl(data) (*(data) = Rte_BmwDiagcSrvHndlg_LockToLockEna_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_PosnServoCmd_Val Rte_Read_BmwMotTqOvrlArbn_PosnServoCmd_Val
#  define Rte_Read_BmwMotTqOvrlArbn_PosnServoCmd_Val(data) (*(data) = Rte_PosnTrakgServo_PosnServoCmd_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_PosnServoEna_Logl Rte_Read_BmwMotTqOvrlArbn_PosnServoEna_Logl
#  define Rte_Read_BmwMotTqOvrlArbn_PosnServoEna_Logl(data) (*(data) = Rte_BmwMotTqOvrlArbn_PosnServoEna_Logl, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_PullCmpCmd_Val Rte_Read_BmwMotTqOvrlArbn_PullCmpCmd_Val
#  define Rte_Read_BmwMotTqOvrlArbn_PullCmpCmd_Val(data) (*(data) = Rte_PullCmpActv_PullCmpCmd_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_TrfcJamAssiCmd_Val Rte_Read_BmwMotTqOvrlArbn_TrfcJamAssiCmd_Val
#  define Rte_Read_BmwMotTqOvrlArbn_TrfcJamAssiCmd_Val(data) (*(data) = Rte_BmwTrfcJamAssiDampg_TrfcJamAssiCmd_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_VehSpd_Val Rte_Read_BmwMotTqOvrlArbn_VehSpd_Val
#  define Rte_Read_BmwMotTqOvrlArbn_VehSpd_Val(data) (*(data) = Rte_BmwVehSpd_VehSpd_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_MotTqOvrlCmd_Val Rte_Write_BmwMotTqOvrlArbn_MotTqOvrlCmd_Val
#  define Rte_Write_BmwMotTqOvrlArbn_MotTqOvrlCmd_Val(data) (Rte_BmwMotTqOvrlArbn_MotTqOvrlCmd_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


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

#  define Rte_Prm_BmwMotTqOvrlArbnMfgModCmdThd_Val() (((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwMotTqOvrlArbnMfgModCmdThd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwMotTqOvrlArbnMfgModVehSpdThd_Val() (((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwMotTqOvrlArbnMfgModVehSpdThd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwMotTqOvrlArbnPullCmpCmdLim_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->BmwMotTqOvrlArbnPullCmpCmdLim_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwMotTqOvrlArbnBmwNearStillVehSpdStsRefTiThd_Val() (((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwMotTqOvrlArbnBmwNearStillVehSpdStsRefTiThd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwMotTqOvrlArbnMfgModCmdRefTiThd_Val() (((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwMotTqOvrlArbnMfgModCmdRefTiThd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwMotTqOvrlArbnVehSpdRefTiThd_Val() (((P2CONST(Rte_Calprm_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupB_DEFAULT_RTE_CALPRM_GROUP])->BmwMotTqOvrlArbnVehSpdRefTiThd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMotTqOvrlArbn_BmwNearStillVehSpdStsCdnRefTi; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMotTqOvrlArbn_MfgModCmdCdnRefTi; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMotTqOvrlArbn_VehSpdCdnRefTi; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMotTqOvrlArbn_FctlErrStVari; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  endif

#  define Rte_Pim_BmwNearStillVehSpdStsCdnRefTi() \
  (&Rte_BmwMotTqOvrlArbn_BmwNearStillVehSpdStsCdnRefTi) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MfgModCmdCdnRefTi() \
  (&Rte_BmwMotTqOvrlArbn_MfgModCmdCdnRefTi) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_VehSpdCdnRefTi() \
  (&Rte_BmwMotTqOvrlArbn_VehSpdCdnRefTi) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_FctlErrStVari() \
  (&Rte_BmwMotTqOvrlArbn_FctlErrStVari) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define BmwMotTqOvrlArbn_START_SEC_CODE
# include "BmwMotTqOvrlArbn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_BmwMotTqOvrlArbnInit1 BmwMotTqOvrlArbnInit1
#  define RTE_RUNNABLE_BmwMotTqOvrlArbnPer1 BmwMotTqOvrlArbnPer1
# endif

FUNC(void, BmwMotTqOvrlArbn_CODE) BmwMotTqOvrlArbnInit1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, BmwMotTqOvrlArbn_CODE) BmwMotTqOvrlArbnPer1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define BmwMotTqOvrlArbn_STOP_SEC_CODE
# include "BmwMotTqOvrlArbn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_BMWMOTTQOVRLARBN_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
