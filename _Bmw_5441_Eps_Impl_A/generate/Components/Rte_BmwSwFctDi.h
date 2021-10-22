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
 *          File:  Rte_BmwSwFctDi.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <BmwSwFctDi>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_BMWSWFCTDI_H
# define _RTE_BMWSWFCTDI_H

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

# include "Rte_BmwSwFctDi_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_Appl7_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_INIT) Rte_CtrldVelRtn_CtrldVelRtnCmd_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_ClsdLoopHys_HwTqCmdHys_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_Appl7_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(boolean, RTE_VAR_INIT) Rte_BmwSwFctDi_BmwOutpTqOvrlCmdEna_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwSwFctDi_BmwStrtStopMsgEna_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwSwFctDi_CtrldVelRtnCmdBmwOvrd_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwSwFctDi_DampgCmdPwrPrkgEna_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwSwFctDi_DrvgDynFacEna_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwSwFctDi_FricLrngCustEna_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwSwFctDi_HaptcFbEna_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwSwFctDi_HwTqCmdHysBmwOvrd_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwSwFctDi_HwTqOvrlCmdEna_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwSwFctDi_InertiaCmpVelCmdDiBmwOvrd_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwSwFctDi_MaxCurrAtHiSpd_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwSwFctDi_MaxCurrAtLoSpd_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwSwFctDi_PullCmpCmdDiBmwOvrd_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwSwFctDi_TrfcJamAssiCmdEna_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwSwFctDi_TunSetHndlrEna_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_CmnMfgSrv_InertiaCmpVelCmdDi_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_CmnMfgSrv_PullCmpCmdDi_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_BmwOutpTqOvrlCmdEna_Logl (TRUE)
#  define Rte_InitValue_BmwStrtStopMsgEna_Logl (TRUE)
#  define Rte_InitValue_CtrldVelRtnCmd_Val (0.0F)
#  define Rte_InitValue_CtrldVelRtnCmdBmwOvrd_Val (0.0F)
#  define Rte_InitValue_DampgCmdPwrPrkgEna_Logl (FALSE)
#  define Rte_InitValue_DrvgDynFacEna_Logl (TRUE)
#  define Rte_InitValue_FricLrngCustEna_Logl (TRUE)
#  define Rte_InitValue_HaptcFbEna_Logl (TRUE)
#  define Rte_InitValue_HwTqCmdHys_Val (0.0F)
#  define Rte_InitValue_HwTqCmdHysBmwOvrd_Val (0.0F)
#  define Rte_InitValue_HwTqOvrlCmdEna_Logl (TRUE)
#  define Rte_InitValue_InertiaCmpVelCmdDi_Logl (FALSE)
#  define Rte_InitValue_InertiaCmpVelCmdDiBmwOvrd_Logl (FALSE)
#  define Rte_InitValue_MaxCurrAtHiSpd_Val (0.0F)
#  define Rte_InitValue_MaxCurrAtLoSpd_Val (0.0F)
#  define Rte_InitValue_PullCmpCmdDi_Logl (FALSE)
#  define Rte_InitValue_PullCmpCmdDiBmwOvrd_Logl (FALSE)
#  define Rte_InitValue_TrfcJamAssiCmdEna_Logl (TRUE)
#  define Rte_InitValue_TunSetHndlrEna_Logl (TRUE)
# endif


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Buffers for Mode Management
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_INIT) Rte_ModeMachine_Coding_DataMode_currentDataMode; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */



# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_CtrldVelRtnCmd_Val Rte_Read_BmwSwFctDi_CtrldVelRtnCmd_Val
#  define Rte_Read_BmwSwFctDi_CtrldVelRtnCmd_Val(data) (*(data) = Rte_CtrldVelRtn_CtrldVelRtnCmd_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_HwTqCmdHys_Val Rte_Read_BmwSwFctDi_HwTqCmdHys_Val
#  define Rte_Read_BmwSwFctDi_HwTqCmdHys_Val(data) (*(data) = Rte_ClsdLoopHys_HwTqCmdHys_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_InertiaCmpVelCmdDi_Logl Rte_Read_BmwSwFctDi_InertiaCmpVelCmdDi_Logl
#  define Rte_Read_BmwSwFctDi_InertiaCmpVelCmdDi_Logl(data) (*(data) = Rte_CmnMfgSrv_InertiaCmpVelCmdDi_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_PullCmpCmdDi_Logl Rte_Read_BmwSwFctDi_PullCmpCmdDi_Logl
#  define Rte_Read_BmwSwFctDi_PullCmpCmdDi_Logl(data) (*(data) = Rte_CmnMfgSrv_PullCmpCmdDi_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_BmwOutpTqOvrlCmdEna_Logl Rte_Write_BmwSwFctDi_BmwOutpTqOvrlCmdEna_Logl
#  define Rte_Write_BmwSwFctDi_BmwOutpTqOvrlCmdEna_Logl(data) (Rte_BmwSwFctDi_BmwOutpTqOvrlCmdEna_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_BmwStrtStopMsgEna_Logl Rte_Write_BmwSwFctDi_BmwStrtStopMsgEna_Logl
#  define Rte_Write_BmwSwFctDi_BmwStrtStopMsgEna_Logl(data) (Rte_BmwSwFctDi_BmwStrtStopMsgEna_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_CtrldVelRtnCmdBmwOvrd_Val Rte_Write_BmwSwFctDi_CtrldVelRtnCmdBmwOvrd_Val
#  define Rte_Write_BmwSwFctDi_CtrldVelRtnCmdBmwOvrd_Val(data) (Rte_BmwSwFctDi_CtrldVelRtnCmdBmwOvrd_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_DampgCmdPwrPrkgEna_Logl Rte_Write_BmwSwFctDi_DampgCmdPwrPrkgEna_Logl
#  define Rte_Write_BmwSwFctDi_DampgCmdPwrPrkgEna_Logl(data) (Rte_BmwSwFctDi_DampgCmdPwrPrkgEna_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_DrvgDynFacEna_Logl Rte_Write_BmwSwFctDi_DrvgDynFacEna_Logl
#  define Rte_Write_BmwSwFctDi_DrvgDynFacEna_Logl(data) (Rte_BmwSwFctDi_DrvgDynFacEna_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_FricLrngCustEna_Logl Rte_Write_BmwSwFctDi_FricLrngCustEna_Logl
#  define Rte_Write_BmwSwFctDi_FricLrngCustEna_Logl(data) (Rte_BmwSwFctDi_FricLrngCustEna_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_HaptcFbEna_Logl Rte_Write_BmwSwFctDi_HaptcFbEna_Logl
#  define Rte_Write_BmwSwFctDi_HaptcFbEna_Logl(data) (Rte_BmwSwFctDi_HaptcFbEna_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_HwTqCmdHysBmwOvrd_Val Rte_Write_BmwSwFctDi_HwTqCmdHysBmwOvrd_Val
#  define Rte_Write_BmwSwFctDi_HwTqCmdHysBmwOvrd_Val(data) (Rte_BmwSwFctDi_HwTqCmdHysBmwOvrd_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_HwTqOvrlCmdEna_Logl Rte_Write_BmwSwFctDi_HwTqOvrlCmdEna_Logl
#  define Rte_Write_BmwSwFctDi_HwTqOvrlCmdEna_Logl(data) (Rte_BmwSwFctDi_HwTqOvrlCmdEna_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_InertiaCmpVelCmdDiBmwOvrd_Logl Rte_Write_BmwSwFctDi_InertiaCmpVelCmdDiBmwOvrd_Logl
#  define Rte_Write_BmwSwFctDi_InertiaCmpVelCmdDiBmwOvrd_Logl(data) (Rte_BmwSwFctDi_InertiaCmpVelCmdDiBmwOvrd_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_MaxCurrAtHiSpd_Val Rte_Write_BmwSwFctDi_MaxCurrAtHiSpd_Val
#  define Rte_Write_BmwSwFctDi_MaxCurrAtHiSpd_Val(data) (Rte_BmwSwFctDi_MaxCurrAtHiSpd_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_MaxCurrAtLoSpd_Val Rte_Write_BmwSwFctDi_MaxCurrAtLoSpd_Val
#  define Rte_Write_BmwSwFctDi_MaxCurrAtLoSpd_Val(data) (Rte_BmwSwFctDi_MaxCurrAtLoSpd_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_PullCmpCmdDiBmwOvrd_Logl Rte_Write_BmwSwFctDi_PullCmpCmdDiBmwOvrd_Logl
#  define Rte_Write_BmwSwFctDi_PullCmpCmdDiBmwOvrd_Logl(data) (Rte_BmwSwFctDi_PullCmpCmdDiBmwOvrd_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_TrfcJamAssiCmdEna_Logl Rte_Write_BmwSwFctDi_TrfcJamAssiCmdEna_Logl
#  define Rte_Write_BmwSwFctDi_TrfcJamAssiCmdEna_Logl(data) (Rte_BmwSwFctDi_TrfcJamAssiCmdEna_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_TunSetHndlrEna_Logl Rte_Write_BmwSwFctDi_TunSetHndlrEna_Logl
#  define Rte_Write_BmwSwFctDi_TunSetHndlrEna_Logl(data) (Rte_BmwSwFctDi_TunSetHndlrEna_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Mode_Coding_DataMode_Mode() (Rte_ModeMachine_Coding_DataMode_currentDataMode) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_CODING_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CODING_APPL_CODE) Coding_Func_GetCurrentLimit(P2VAR(uint8, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CODING_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_Data_GetCurrentLimit Coding_Func_GetCurrentLimit
#  define RTE_START_SEC_CODING_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CODING_APPL_CODE) Coding_Func_GetNAME00_00_CalculationOfLoadMinusstateMinusdependentSteeringAssistance(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CODING_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_Data_GetNAME00_00_CalculationOfLoadMinusstateMinusdependentSteeringAssistance Coding_Func_GetNAME00_00_CalculationOfLoadMinusstateMinusdependentSteeringAssistance
#  define RTE_START_SEC_CODING_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CODING_APPL_CODE) Coding_Func_GetNAME00_01_CalculationOfActiveReturn(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CODING_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_Data_GetNAME00_01_CalculationOfActiveReturn Coding_Func_GetNAME00_01_CalculationOfActiveReturn
#  define RTE_START_SEC_CODING_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CODING_APPL_CODE) Coding_Func_GetNAME00_02_reserved(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CODING_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_Data_GetNAME00_02_reserved Coding_Func_GetNAME00_02_reserved
#  define RTE_START_SEC_CODING_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CODING_APPL_CODE) Coding_Func_GetNAME00_03_ActiveInfluenceOnTheSteeringHysterisis(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CODING_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_Data_GetNAME00_03_ActiveInfluenceOnTheSteeringHysterisis Coding_Func_GetNAME00_03_ActiveInfluenceOnTheSteeringHysterisis
#  define RTE_START_SEC_CODING_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CODING_APPL_CODE) Coding_Func_GetNAME01_03_ParkingPowerDamping(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CODING_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_Data_GetNAME01_03_ParkingPowerDamping Coding_Func_GetNAME01_03_ParkingPowerDamping
#  define RTE_START_SEC_CODING_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CODING_APPL_CODE) Coding_Func_GetNAME02_00_CompensationOfFriction(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CODING_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_Data_GetNAME02_00_CompensationOfFriction Coding_Func_GetNAME02_00_CompensationOfFriction
#  define RTE_START_SEC_CODING_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CODING_APPL_CODE) Coding_Func_GetNAME02_01_CompensationOfConstantSteeringPullAndLateralInclinationPull(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CODING_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_Data_GetNAME02_01_CompensationOfConstantSteeringPullAndLateralInclinationPull Coding_Func_GetNAME02_01_CompensationOfConstantSteeringPullAndLateralInclinationPull
#  define RTE_START_SEC_CODING_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CODING_APPL_CODE) Coding_Func_GetNAME02_02(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CODING_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_Data_GetNAME02_02 Coding_Func_GetNAME02_02
#  define RTE_START_SEC_CODING_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CODING_APPL_CODE) Coding_Func_GetNAME02_03(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CODING_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_Data_GetNAME02_03 Coding_Func_GetNAME02_03
#  define RTE_START_SEC_CODING_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CODING_APPL_CODE) Coding_Func_GetNAME02_04_CompensationOfInertiaOfTheSteeringGear(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CODING_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_Data_GetNAME02_04_CompensationOfInertiaOfTheSteeringGear Coding_Func_GetNAME02_04_CompensationOfInertiaOfTheSteeringGear
#  define RTE_START_SEC_CODING_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CODING_APPL_CODE) Coding_Func_GetNAME02_05_CompensationOfInertiaOfTheSteeringWheel(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CODING_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_Data_GetNAME02_05_CompensationOfInertiaOfTheSteeringWheel Coding_Func_GetNAME02_05_CompensationOfInertiaOfTheSteeringWheel
#  define RTE_START_SEC_CODING_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CODING_APPL_CODE) Coding_Func_GetNAME02_06(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CODING_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_Data_GetNAME02_06 Coding_Func_GetNAME02_06
#  define RTE_START_SEC_CODING_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CODING_APPL_CODE) Coding_Func_GetNAME02_07(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CODING_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_Data_GetNAME02_07 Coding_Func_GetNAME02_07
#  define RTE_START_SEC_CODING_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CODING_APPL_CODE) Coding_Func_GetNAME03_00_reserved(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CODING_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_Data_GetNAME03_00_reserved Coding_Func_GetNAME03_00_reserved
#  define RTE_START_SEC_CODING_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CODING_APPL_CODE) Coding_Func_GetNAME03_01_VoltageDependantDegredation(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CODING_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_Data_GetNAME03_01_VoltageDependantDegredation Coding_Func_GetNAME03_01_VoltageDependantDegredation
#  define RTE_START_SEC_CODING_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CODING_APPL_CODE) Coding_Func_GetNAME03_02_SpeedDependantDegredation(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CODING_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_Data_GetNAME03_02_SpeedDependantDegredation Coding_Func_GetNAME03_02_SpeedDependantDegredation
#  define RTE_START_SEC_CODING_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CODING_APPL_CODE) Coding_Func_GetNAME04_00_DrivingDynamicsInterfaceMinusDriversTorque(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CODING_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_Data_GetNAME04_00_DrivingDynamicsInterfaceMinusDriversTorque Coding_Func_GetNAME04_00_DrivingDynamicsInterfaceMinusDriversTorque
#  define RTE_START_SEC_CODING_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CODING_APPL_CODE) Coding_Func_GetNAME04_00_DrivingDynamicsInterfaceMinusMotorTorque(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CODING_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_Data_GetNAME04_00_DrivingDynamicsInterfaceMinusMotorTorque Coding_Func_GetNAME04_00_DrivingDynamicsInterfaceMinusMotorTorque
#  define RTE_START_SEC_CODING_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CODING_APPL_CODE) Coding_Func_GetNAME04_02_DrivingDynamicsInterfaceMinusFactors(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CODING_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_Data_GetNAME04_02_DrivingDynamicsInterfaceMinusFactors Coding_Func_GetNAME04_02_DrivingDynamicsInterfaceMinusFactors
#  define RTE_START_SEC_CODING_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CODING_APPL_CODE) Coding_Func_GetNAME04_03_DrivingDynamicsInterfaceMinusAdditionalDamping(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CODING_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_Data_GetNAME04_03_DrivingDynamicsInterfaceMinusAdditionalDamping Coding_Func_GetNAME04_03_DrivingDynamicsInterfaceMinusAdditionalDamping
#  define RTE_START_SEC_CODING_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CODING_APPL_CODE) Coding_Func_GetNAME04_04_EPSVibration(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CODING_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_Data_GetNAME04_04_EPSVibration Coding_Func_GetNAME04_04_EPSVibration
#  define RTE_START_SEC_CODING_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CODING_APPL_CODE) Coding_Func_GetNAME04_05_DrivingExperienceSwitch(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CODING_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_Data_GetNAME04_05_DrivingExperienceSwitch Coding_Func_GetNAME04_05_DrivingExperienceSwitch
#  define RTE_START_SEC_CODING_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CODING_APPL_CODE) Coding_Func_GetNAME04_06_reserved(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CODING_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_Data_GetNAME04_06_reserved Coding_Func_GetNAME04_06_reserved
#  define RTE_START_SEC_CODING_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CODING_APPL_CODE) Coding_Func_GetNAME04_07_automaticEngineStartStopFunction(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CODING_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_Data_GetNAME04_07_automaticEngineStartStopFunction Coding_Func_GetNAME04_07_automaticEngineStartStopFunction
#  define RTE_START_SEC_CODING_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CODING_APPL_CODE) Coding_Func_GetNAME05_00_ActiveFanActuation(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CODING_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_Data_GetNAME05_00_ActiveFanActuation Coding_Func_GetNAME05_00_ActiveFanActuation
#  define RTE_START_SEC_CODING_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CODING_APPL_CODE) Coding_Func_GetSpeedMinuslimitForMaxCurrent(P2VAR(uint8, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CODING_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_Data_GetSpeedMinuslimitForMaxCurrent Coding_Func_GetSpeedMinuslimitForMaxCurrent


/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

#  define Rte_Prm_BmwSwFctDiBmwActvRtnOvrd_Val() (((P2CONST(Rte_Calprm_CalRegn01CmnGroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupA_DEFAULT_RTE_CALPRM_GROUP])->BmwSwFctDiBmwActvRtnOvrd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwSwFctDiBmwEngStrtStopOvrd_Val() (((P2CONST(Rte_Calprm_CalRegn01CmnGroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupA_DEFAULT_RTE_CALPRM_GROUP])->BmwSwFctDiBmwEngStrtStopOvrd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwSwFctDiBmwEpsOscnOvrd_Val() (((P2CONST(Rte_Calprm_CalRegn01CmnGroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupA_DEFAULT_RTE_CALPRM_GROUP])->BmwSwFctDiBmwEpsOscnOvrd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwSwFctDiBmwFricCmpOvrd_Val() (((P2CONST(Rte_Calprm_CalRegn01CmnGroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupA_DEFAULT_RTE_CALPRM_GROUP])->BmwSwFctDiBmwFricCmpOvrd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwSwFctDiBmwGearInertiaCmpOvrd_Val() (((P2CONST(Rte_Calprm_CalRegn01CmnGroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupA_DEFAULT_RTE_CALPRM_GROUP])->BmwSwFctDiBmwGearInertiaCmpOvrd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwSwFctDiBmwHwInertiaCmpOvrd_Val() (((P2CONST(Rte_Calprm_CalRegn01CmnGroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupA_DEFAULT_RTE_CALPRM_GROUP])->BmwSwFctDiBmwHwInertiaCmpOvrd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwSwFctDiBmwHysActvInflOvrd_Val() (((P2CONST(Rte_Calprm_CalRegn01CmnGroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupA_DEFAULT_RTE_CALPRM_GROUP])->BmwSwFctDiBmwHysActvInflOvrd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwSwFctDiBmwIfNegDampgOvrd_Val() (((P2CONST(Rte_Calprm_CalRegn01CmnGroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupA_DEFAULT_RTE_CALPRM_GROUP])->BmwSwFctDiBmwIfNegDampgOvrd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwSwFctDiBmwIfNegFacOvrd_Val() (((P2CONST(Rte_Calprm_CalRegn01CmnGroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupA_DEFAULT_RTE_CALPRM_GROUP])->BmwSwFctDiBmwIfNegFacOvrd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwSwFctDiBmwIfNegHwTqOvrd_Val() (((P2CONST(Rte_Calprm_CalRegn01CmnGroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupA_DEFAULT_RTE_CALPRM_GROUP])->BmwSwFctDiBmwIfNegHwTqOvrd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwSwFctDiBmwIfNegMotTqOvrd_Val() (((P2CONST(Rte_Calprm_CalRegn01CmnGroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupA_DEFAULT_RTE_CALPRM_GROUP])->BmwSwFctDiBmwIfNegMotTqOvrd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwSwFctDiBmwLrnSwtOvrd_Val() (((P2CONST(Rte_Calprm_CalRegn01CmnGroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupA_DEFAULT_RTE_CALPRM_GROUP])->BmwSwFctDiBmwLrnSwtOvrd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwSwFctDiBmwPrkgPwrDampgOvrd_Val() (((P2CONST(Rte_Calprm_CalRegn01CmnGroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupA_DEFAULT_RTE_CALPRM_GROUP])->BmwSwFctDiBmwPrkgPwrDampgOvrd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwSwFctDiBmwPullCmpOvrd_Val() (((P2CONST(Rte_Calprm_CalRegn01CmnGroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupA_DEFAULT_RTE_CALPRM_GROUP])->BmwSwFctDiBmwPullCmpOvrd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwSwFctDiCodingOvrd_Val() (((P2CONST(Rte_Calprm_CalRegn01CmnGroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupA_DEFAULT_RTE_CALPRM_GROUP])->BmwSwFctDiCodingOvrd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwSwFctDiMaxCurrAtHiSpdOvrd_Val() (((P2CONST(Rte_Calprm_CalRegn01CmnGroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupA_DEFAULT_RTE_CALPRM_GROUP])->BmwSwFctDiMaxCurrAtHiSpdOvrd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwSwFctDiMaxCurrAtLoSpdOvrd_Val() (((P2CONST(Rte_Calprm_CalRegn01CmnGroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupA_DEFAULT_RTE_CALPRM_GROUP])->BmwSwFctDiMaxCurrAtLoSpdOvrd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwSwFctDi_BmwActvRtn; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwSwFctDi_BmwEngStrtStop; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwSwFctDi_BmwEpsOscn; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwSwFctDi_BmwFricCmp; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwSwFctDi_BmwGearInertiaCmp; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwSwFctDi_BmwHwInertiaCmp; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwSwFctDi_BmwHysActvInfl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwSwFctDi_BmwIfNegDampg; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwSwFctDi_BmwIfNegFac; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwSwFctDi_BmwIfNegHwTq; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwSwFctDi_BmwIfNegMotTq; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwSwFctDi_BmwLrnSwt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwSwFctDi_BmwPrkgPwrDampg; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwSwFctDi_BmwPullCmp; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwSwFctDi_PrevCodingDataMode; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  endif

#  define Rte_Pim_BmwActvRtn() \
  (&Rte_BmwSwFctDi_BmwActvRtn) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_BmwEngStrtStop() \
  (&Rte_BmwSwFctDi_BmwEngStrtStop) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_BmwEpsOscn() \
  (&Rte_BmwSwFctDi_BmwEpsOscn) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_BmwFricCmp() \
  (&Rte_BmwSwFctDi_BmwFricCmp) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_BmwGearInertiaCmp() \
  (&Rte_BmwSwFctDi_BmwGearInertiaCmp) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_BmwHwInertiaCmp() \
  (&Rte_BmwSwFctDi_BmwHwInertiaCmp) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_BmwHysActvInfl() \
  (&Rte_BmwSwFctDi_BmwHysActvInfl) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_BmwIfNegDampg() \
  (&Rte_BmwSwFctDi_BmwIfNegDampg) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_BmwIfNegFac() \
  (&Rte_BmwSwFctDi_BmwIfNegFac) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_BmwIfNegHwTq() \
  (&Rte_BmwSwFctDi_BmwIfNegHwTq) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_BmwIfNegMotTq() \
  (&Rte_BmwSwFctDi_BmwIfNegMotTq) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_BmwLrnSwt() \
  (&Rte_BmwSwFctDi_BmwLrnSwt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_BmwPrkgPwrDampg() \
  (&Rte_BmwSwFctDi_BmwPrkgPwrDampg) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_BmwPullCmp() \
  (&Rte_BmwSwFctDi_BmwPullCmp) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_PrevCodingDataMode() \
  (&Rte_BmwSwFctDi_PrevCodingDataMode) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define BmwSwFctDi_START_SEC_CODE
# include "BmwSwFctDi_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_BmwSwFctDiInit1 BmwSwFctDiInit1
#  define RTE_RUNNABLE_BmwSwFctDiPer1 BmwSwFctDiPer1
# endif

FUNC(void, BmwSwFctDi_CODE) BmwSwFctDiInit1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, BmwSwFctDi_CODE) BmwSwFctDiPer1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define BmwSwFctDi_STOP_SEC_CODE
# include "BmwSwFctDi_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_Data_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_BMWSWFCTDI_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
