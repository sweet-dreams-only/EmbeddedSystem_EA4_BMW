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
 *        Config:  C:/Component/CF108A_BmwSwFctDi_Impl/tools/Component.dpa
 *     SW-C Type:  BmwSwFctDi
 *  Generated at:  Sat Jul 28 12:27:15 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <BmwSwFctDi> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_BMWSWFCTDI_H
# define _RTE_BMWSWFCTDI_H

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

# include "Rte_BmwSwFctDi_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_BmwSwFctDi
{
  /* PIM Handles section */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwActvRtn; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwEngStrtStop; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwEpsOscn; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwFricCmp; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwGearInertiaCmp; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwHwInertiaCmp; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwHysActvInfl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwIfNegDampg; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwIfNegFac; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwIfNegHwTq; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwIfNegMotTq; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwLrnSwt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwPrkgPwrDampg; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwPullCmp; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_PrevCodingDataMode; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_BmwSwFctDi, RTE_CONST, RTE_CONST) Rte_Inst_BmwSwFctDi; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_BmwSwFctDi, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_BmwOutpTqOvrlCmdEna_Logl (TRUE)
# define Rte_InitValue_BmwStrtStopMsgEna_Logl (TRUE)
# define Rte_InitValue_CtrldVelRtnCmd_Val (0.0F)
# define Rte_InitValue_CtrldVelRtnCmdBmwOvrd_Val (0.0F)
# define Rte_InitValue_DampgCmdPwrPrkgEna_Logl (FALSE)
# define Rte_InitValue_DrvgDynFacEna_Logl (TRUE)
# define Rte_InitValue_FricLrngCustEna_Logl (TRUE)
# define Rte_InitValue_HaptcFbEna_Logl (TRUE)
# define Rte_InitValue_HwTqCmdHys_Val (0.0F)
# define Rte_InitValue_HwTqCmdHysBmwOvrd_Val (0.0F)
# define Rte_InitValue_HwTqOvrlCmdEna_Logl (TRUE)
# define Rte_InitValue_InertiaCmpVelCmdDi_Logl (FALSE)
# define Rte_InitValue_InertiaCmpVelCmdDiBmwOvrd_Logl (FALSE)
# define Rte_InitValue_MaxCurrAtHiSpd_Val (0.0F)
# define Rte_InitValue_MaxCurrAtLoSpd_Val (0.0F)
# define Rte_InitValue_PullCmpCmdDi_Logl (FALSE)
# define Rte_InitValue_PullCmpCmdDiBmwOvrd_Logl (FALSE)
# define Rte_InitValue_TrfcJamAssiCmdEna_Logl (TRUE)
# define Rte_InitValue_TunSetHndlrEna_Logl (TRUE)


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwSwFctDi_CtrldVelRtnCmd_Val(P2VAR(float32, AUTOMATIC, RTE_BMWSWFCTDI_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwSwFctDi_HwTqCmdHys_Val(P2VAR(float32, AUTOMATIC, RTE_BMWSWFCTDI_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwSwFctDi_InertiaCmpVelCmdDi_Logl(P2VAR(boolean, AUTOMATIC, RTE_BMWSWFCTDI_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwSwFctDi_PullCmpCmdDi_Logl(P2VAR(boolean, AUTOMATIC, RTE_BMWSWFCTDI_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwSwFctDi_BmwOutpTqOvrlCmdEna_Logl(boolean data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwSwFctDi_BmwStrtStopMsgEna_Logl(boolean data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwSwFctDi_CtrldVelRtnCmdBmwOvrd_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwSwFctDi_DampgCmdPwrPrkgEna_Logl(boolean data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwSwFctDi_DrvgDynFacEna_Logl(boolean data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwSwFctDi_FricLrngCustEna_Logl(boolean data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwSwFctDi_HaptcFbEna_Logl(boolean data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwSwFctDi_HwTqCmdHysBmwOvrd_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwSwFctDi_HwTqOvrlCmdEna_Logl(boolean data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwSwFctDi_InertiaCmpVelCmdDiBmwOvrd_Logl(boolean data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwSwFctDi_MaxCurrAtHiSpd_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwSwFctDi_MaxCurrAtLoSpd_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwSwFctDi_PullCmpCmdDiBmwOvrd_Logl(boolean data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwSwFctDi_TrfcJamAssiCmdEna_Logl(boolean data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwSwFctDi_TunSetHndlrEna_Logl(boolean data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint8, RTE_CODE) Rte_Mode_BmwSwFctDi_Coding_DataMode_Mode(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwSwFctDi_Data_GetCurrentLimit(P2VAR(uint8, AUTOMATIC, RTE_BMWSWFCTDI_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwSwFctDi_Data_GetNAME00_00_CalculationOfLoadMinusstateMinusdependentSteeringAssistance(P2VAR(boolean, AUTOMATIC, RTE_BMWSWFCTDI_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwSwFctDi_Data_GetNAME00_01_CalculationOfActiveReturn(P2VAR(boolean, AUTOMATIC, RTE_BMWSWFCTDI_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwSwFctDi_Data_GetNAME00_02_reserved(P2VAR(boolean, AUTOMATIC, RTE_BMWSWFCTDI_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwSwFctDi_Data_GetNAME00_03_ActiveInfluenceOnTheSteeringHysterisis(P2VAR(boolean, AUTOMATIC, RTE_BMWSWFCTDI_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwSwFctDi_Data_GetNAME01_03_ParkingPowerDamping(P2VAR(boolean, AUTOMATIC, RTE_BMWSWFCTDI_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwSwFctDi_Data_GetNAME02_00_CompensationOfFriction(P2VAR(boolean, AUTOMATIC, RTE_BMWSWFCTDI_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwSwFctDi_Data_GetNAME02_01_CompensationOfConstantSteeringPullAndLateralInclinationPull(P2VAR(boolean, AUTOMATIC, RTE_BMWSWFCTDI_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwSwFctDi_Data_GetNAME02_02(P2VAR(boolean, AUTOMATIC, RTE_BMWSWFCTDI_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwSwFctDi_Data_GetNAME02_03(P2VAR(boolean, AUTOMATIC, RTE_BMWSWFCTDI_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwSwFctDi_Data_GetNAME02_04_CompensationOfInertiaOfTheSteeringGear(P2VAR(boolean, AUTOMATIC, RTE_BMWSWFCTDI_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwSwFctDi_Data_GetNAME02_05_CompensationOfInertiaOfTheSteeringWheel(P2VAR(boolean, AUTOMATIC, RTE_BMWSWFCTDI_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwSwFctDi_Data_GetNAME02_06(P2VAR(boolean, AUTOMATIC, RTE_BMWSWFCTDI_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwSwFctDi_Data_GetNAME02_07(P2VAR(boolean, AUTOMATIC, RTE_BMWSWFCTDI_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwSwFctDi_Data_GetNAME03_00_reserved(P2VAR(boolean, AUTOMATIC, RTE_BMWSWFCTDI_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwSwFctDi_Data_GetNAME03_01_VoltageDependantDegredation(P2VAR(boolean, AUTOMATIC, RTE_BMWSWFCTDI_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwSwFctDi_Data_GetNAME03_02_SpeedDependantDegredation(P2VAR(boolean, AUTOMATIC, RTE_BMWSWFCTDI_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwSwFctDi_Data_GetNAME04_00_DrivingDynamicsInterfaceMinusDriversTorque(P2VAR(boolean, AUTOMATIC, RTE_BMWSWFCTDI_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwSwFctDi_Data_GetNAME04_00_DrivingDynamicsInterfaceMinusMotorTorque(P2VAR(boolean, AUTOMATIC, RTE_BMWSWFCTDI_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwSwFctDi_Data_GetNAME04_02_DrivingDynamicsInterfaceMinusFactors(P2VAR(boolean, AUTOMATIC, RTE_BMWSWFCTDI_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwSwFctDi_Data_GetNAME04_03_DrivingDynamicsInterfaceMinusAdditionalDamping(P2VAR(boolean, AUTOMATIC, RTE_BMWSWFCTDI_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwSwFctDi_Data_GetNAME04_04_EPSVibration(P2VAR(boolean, AUTOMATIC, RTE_BMWSWFCTDI_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwSwFctDi_Data_GetNAME04_05_DrivingExperienceSwitch(P2VAR(boolean, AUTOMATIC, RTE_BMWSWFCTDI_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwSwFctDi_Data_GetNAME04_06_reserved(P2VAR(boolean, AUTOMATIC, RTE_BMWSWFCTDI_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwSwFctDi_Data_GetNAME04_07_automaticEngineStartStopFunction(P2VAR(boolean, AUTOMATIC, RTE_BMWSWFCTDI_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwSwFctDi_Data_GetNAME05_00_ActiveFanActuation(P2VAR(boolean, AUTOMATIC, RTE_BMWSWFCTDI_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwSwFctDi_Data_GetSpeedMinuslimitForMaxCurrent(P2VAR(uint8, AUTOMATIC, RTE_BMWSWFCTDI_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint8, RTE_CODE) Rte_Prm_BmwSwFctDi_BmwSwFctDiBmwActvRtnOvrd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint8, RTE_CODE) Rte_Prm_BmwSwFctDi_BmwSwFctDiBmwEngStrtStopOvrd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint8, RTE_CODE) Rte_Prm_BmwSwFctDi_BmwSwFctDiBmwEpsOscnOvrd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint8, RTE_CODE) Rte_Prm_BmwSwFctDi_BmwSwFctDiBmwFricCmpOvrd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint8, RTE_CODE) Rte_Prm_BmwSwFctDi_BmwSwFctDiBmwGearInertiaCmpOvrd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint8, RTE_CODE) Rte_Prm_BmwSwFctDi_BmwSwFctDiBmwHwInertiaCmpOvrd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint8, RTE_CODE) Rte_Prm_BmwSwFctDi_BmwSwFctDiBmwHysActvInflOvrd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint8, RTE_CODE) Rte_Prm_BmwSwFctDi_BmwSwFctDiBmwIfNegDampgOvrd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint8, RTE_CODE) Rte_Prm_BmwSwFctDi_BmwSwFctDiBmwIfNegFacOvrd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint8, RTE_CODE) Rte_Prm_BmwSwFctDi_BmwSwFctDiBmwIfNegHwTqOvrd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint8, RTE_CODE) Rte_Prm_BmwSwFctDi_BmwSwFctDiBmwIfNegMotTqOvrd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint8, RTE_CODE) Rte_Prm_BmwSwFctDi_BmwSwFctDiBmwLrnSwtOvrd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint8, RTE_CODE) Rte_Prm_BmwSwFctDi_BmwSwFctDiBmwPrkgPwrDampgOvrd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint8, RTE_CODE) Rte_Prm_BmwSwFctDi_BmwSwFctDiBmwPullCmpOvrd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint8, RTE_CODE) Rte_Prm_BmwSwFctDi_BmwSwFctDiCodingOvrd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint8, RTE_CODE) Rte_Prm_BmwSwFctDi_BmwSwFctDiMaxCurrAtHiSpdOvrd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint8, RTE_CODE) Rte_Prm_BmwSwFctDi_BmwSwFctDiMaxCurrAtLoSpdOvrd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_CtrldVelRtnCmd_Val Rte_Read_BmwSwFctDi_CtrldVelRtnCmd_Val
# define Rte_Read_HwTqCmdHys_Val Rte_Read_BmwSwFctDi_HwTqCmdHys_Val
# define Rte_Read_InertiaCmpVelCmdDi_Logl Rte_Read_BmwSwFctDi_InertiaCmpVelCmdDi_Logl
# define Rte_Read_PullCmpCmdDi_Logl Rte_Read_BmwSwFctDi_PullCmpCmdDi_Logl


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_BmwOutpTqOvrlCmdEna_Logl Rte_Write_BmwSwFctDi_BmwOutpTqOvrlCmdEna_Logl
# define Rte_Write_BmwStrtStopMsgEna_Logl Rte_Write_BmwSwFctDi_BmwStrtStopMsgEna_Logl
# define Rte_Write_CtrldVelRtnCmdBmwOvrd_Val Rte_Write_BmwSwFctDi_CtrldVelRtnCmdBmwOvrd_Val
# define Rte_Write_DampgCmdPwrPrkgEna_Logl Rte_Write_BmwSwFctDi_DampgCmdPwrPrkgEna_Logl
# define Rte_Write_DrvgDynFacEna_Logl Rte_Write_BmwSwFctDi_DrvgDynFacEna_Logl
# define Rte_Write_FricLrngCustEna_Logl Rte_Write_BmwSwFctDi_FricLrngCustEna_Logl
# define Rte_Write_HaptcFbEna_Logl Rte_Write_BmwSwFctDi_HaptcFbEna_Logl
# define Rte_Write_HwTqCmdHysBmwOvrd_Val Rte_Write_BmwSwFctDi_HwTqCmdHysBmwOvrd_Val
# define Rte_Write_HwTqOvrlCmdEna_Logl Rte_Write_BmwSwFctDi_HwTqOvrlCmdEna_Logl
# define Rte_Write_InertiaCmpVelCmdDiBmwOvrd_Logl Rte_Write_BmwSwFctDi_InertiaCmpVelCmdDiBmwOvrd_Logl
# define Rte_Write_MaxCurrAtHiSpd_Val Rte_Write_BmwSwFctDi_MaxCurrAtHiSpd_Val
# define Rte_Write_MaxCurrAtLoSpd_Val Rte_Write_BmwSwFctDi_MaxCurrAtLoSpd_Val
# define Rte_Write_PullCmpCmdDiBmwOvrd_Logl Rte_Write_BmwSwFctDi_PullCmpCmdDiBmwOvrd_Logl
# define Rte_Write_TrfcJamAssiCmdEna_Logl Rte_Write_BmwSwFctDi_TrfcJamAssiCmdEna_Logl
# define Rte_Write_TunSetHndlrEna_Logl Rte_Write_BmwSwFctDi_TunSetHndlrEna_Logl


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
# define Rte_Mode_Coding_DataMode_Mode Rte_Mode_BmwSwFctDi_Coding_DataMode_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_Data_GetCurrentLimit Rte_Call_BmwSwFctDi_Data_GetCurrentLimit
# define Rte_Call_Data_GetNAME00_00_CalculationOfLoadMinusstateMinusdependentSteeringAssistance Rte_Call_BmwSwFctDi_Data_GetNAME00_00_CalculationOfLoadMinusstateMinusdependentSteeringAssistance
# define Rte_Call_Data_GetNAME00_01_CalculationOfActiveReturn Rte_Call_BmwSwFctDi_Data_GetNAME00_01_CalculationOfActiveReturn
# define Rte_Call_Data_GetNAME00_02_reserved Rte_Call_BmwSwFctDi_Data_GetNAME00_02_reserved
# define Rte_Call_Data_GetNAME00_03_ActiveInfluenceOnTheSteeringHysterisis Rte_Call_BmwSwFctDi_Data_GetNAME00_03_ActiveInfluenceOnTheSteeringHysterisis
# define Rte_Call_Data_GetNAME01_03_ParkingPowerDamping Rte_Call_BmwSwFctDi_Data_GetNAME01_03_ParkingPowerDamping
# define Rte_Call_Data_GetNAME02_00_CompensationOfFriction Rte_Call_BmwSwFctDi_Data_GetNAME02_00_CompensationOfFriction
# define Rte_Call_Data_GetNAME02_01_CompensationOfConstantSteeringPullAndLateralInclinationPull Rte_Call_BmwSwFctDi_Data_GetNAME02_01_CompensationOfConstantSteeringPullAndLateralInclinationPull
# define Rte_Call_Data_GetNAME02_02 Rte_Call_BmwSwFctDi_Data_GetNAME02_02
# define Rte_Call_Data_GetNAME02_03 Rte_Call_BmwSwFctDi_Data_GetNAME02_03
# define Rte_Call_Data_GetNAME02_04_CompensationOfInertiaOfTheSteeringGear Rte_Call_BmwSwFctDi_Data_GetNAME02_04_CompensationOfInertiaOfTheSteeringGear
# define Rte_Call_Data_GetNAME02_05_CompensationOfInertiaOfTheSteeringWheel Rte_Call_BmwSwFctDi_Data_GetNAME02_05_CompensationOfInertiaOfTheSteeringWheel
# define Rte_Call_Data_GetNAME02_06 Rte_Call_BmwSwFctDi_Data_GetNAME02_06
# define Rte_Call_Data_GetNAME02_07 Rte_Call_BmwSwFctDi_Data_GetNAME02_07
# define Rte_Call_Data_GetNAME03_00_reserved Rte_Call_BmwSwFctDi_Data_GetNAME03_00_reserved
# define Rte_Call_Data_GetNAME03_01_VoltageDependantDegredation Rte_Call_BmwSwFctDi_Data_GetNAME03_01_VoltageDependantDegredation
# define Rte_Call_Data_GetNAME03_02_SpeedDependantDegredation Rte_Call_BmwSwFctDi_Data_GetNAME03_02_SpeedDependantDegredation
# define Rte_Call_Data_GetNAME04_00_DrivingDynamicsInterfaceMinusDriversTorque Rte_Call_BmwSwFctDi_Data_GetNAME04_00_DrivingDynamicsInterfaceMinusDriversTorque
# define Rte_Call_Data_GetNAME04_00_DrivingDynamicsInterfaceMinusMotorTorque Rte_Call_BmwSwFctDi_Data_GetNAME04_00_DrivingDynamicsInterfaceMinusMotorTorque
# define Rte_Call_Data_GetNAME04_02_DrivingDynamicsInterfaceMinusFactors Rte_Call_BmwSwFctDi_Data_GetNAME04_02_DrivingDynamicsInterfaceMinusFactors
# define Rte_Call_Data_GetNAME04_03_DrivingDynamicsInterfaceMinusAdditionalDamping Rte_Call_BmwSwFctDi_Data_GetNAME04_03_DrivingDynamicsInterfaceMinusAdditionalDamping
# define Rte_Call_Data_GetNAME04_04_EPSVibration Rte_Call_BmwSwFctDi_Data_GetNAME04_04_EPSVibration
# define Rte_Call_Data_GetNAME04_05_DrivingExperienceSwitch Rte_Call_BmwSwFctDi_Data_GetNAME04_05_DrivingExperienceSwitch
# define Rte_Call_Data_GetNAME04_06_reserved Rte_Call_BmwSwFctDi_Data_GetNAME04_06_reserved
# define Rte_Call_Data_GetNAME04_07_automaticEngineStartStopFunction Rte_Call_BmwSwFctDi_Data_GetNAME04_07_automaticEngineStartStopFunction
# define Rte_Call_Data_GetNAME05_00_ActiveFanActuation Rte_Call_BmwSwFctDi_Data_GetNAME05_00_ActiveFanActuation
# define Rte_Call_Data_GetSpeedMinuslimitForMaxCurrent Rte_Call_BmwSwFctDi_Data_GetSpeedMinuslimitForMaxCurrent


/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

# define Rte_Prm_BmwSwFctDiBmwActvRtnOvrd_Val Rte_Prm_BmwSwFctDi_BmwSwFctDiBmwActvRtnOvrd_Val

# define Rte_Prm_BmwSwFctDiBmwEngStrtStopOvrd_Val Rte_Prm_BmwSwFctDi_BmwSwFctDiBmwEngStrtStopOvrd_Val

# define Rte_Prm_BmwSwFctDiBmwEpsOscnOvrd_Val Rte_Prm_BmwSwFctDi_BmwSwFctDiBmwEpsOscnOvrd_Val

# define Rte_Prm_BmwSwFctDiBmwFricCmpOvrd_Val Rte_Prm_BmwSwFctDi_BmwSwFctDiBmwFricCmpOvrd_Val

# define Rte_Prm_BmwSwFctDiBmwGearInertiaCmpOvrd_Val Rte_Prm_BmwSwFctDi_BmwSwFctDiBmwGearInertiaCmpOvrd_Val

# define Rte_Prm_BmwSwFctDiBmwHwInertiaCmpOvrd_Val Rte_Prm_BmwSwFctDi_BmwSwFctDiBmwHwInertiaCmpOvrd_Val

# define Rte_Prm_BmwSwFctDiBmwHysActvInflOvrd_Val Rte_Prm_BmwSwFctDi_BmwSwFctDiBmwHysActvInflOvrd_Val

# define Rte_Prm_BmwSwFctDiBmwIfNegDampgOvrd_Val Rte_Prm_BmwSwFctDi_BmwSwFctDiBmwIfNegDampgOvrd_Val

# define Rte_Prm_BmwSwFctDiBmwIfNegFacOvrd_Val Rte_Prm_BmwSwFctDi_BmwSwFctDiBmwIfNegFacOvrd_Val

# define Rte_Prm_BmwSwFctDiBmwIfNegHwTqOvrd_Val Rte_Prm_BmwSwFctDi_BmwSwFctDiBmwIfNegHwTqOvrd_Val

# define Rte_Prm_BmwSwFctDiBmwIfNegMotTqOvrd_Val Rte_Prm_BmwSwFctDi_BmwSwFctDiBmwIfNegMotTqOvrd_Val

# define Rte_Prm_BmwSwFctDiBmwLrnSwtOvrd_Val Rte_Prm_BmwSwFctDi_BmwSwFctDiBmwLrnSwtOvrd_Val

# define Rte_Prm_BmwSwFctDiBmwPrkgPwrDampgOvrd_Val Rte_Prm_BmwSwFctDi_BmwSwFctDiBmwPrkgPwrDampgOvrd_Val

# define Rte_Prm_BmwSwFctDiBmwPullCmpOvrd_Val Rte_Prm_BmwSwFctDi_BmwSwFctDiBmwPullCmpOvrd_Val

# define Rte_Prm_BmwSwFctDiCodingOvrd_Val Rte_Prm_BmwSwFctDi_BmwSwFctDiCodingOvrd_Val

# define Rte_Prm_BmwSwFctDiMaxCurrAtHiSpdOvrd_Val Rte_Prm_BmwSwFctDi_BmwSwFctDiMaxCurrAtHiSpdOvrd_Val

# define Rte_Prm_BmwSwFctDiMaxCurrAtLoSpdOvrd_Val Rte_Prm_BmwSwFctDi_BmwSwFctDiMaxCurrAtLoSpdOvrd_Val

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_BmwActvRtn() (Rte_Inst_BmwSwFctDi->Pim_BmwActvRtn) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_BmwEngStrtStop() (Rte_Inst_BmwSwFctDi->Pim_BmwEngStrtStop) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_BmwEpsOscn() (Rte_Inst_BmwSwFctDi->Pim_BmwEpsOscn) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_BmwFricCmp() (Rte_Inst_BmwSwFctDi->Pim_BmwFricCmp) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_BmwGearInertiaCmp() (Rte_Inst_BmwSwFctDi->Pim_BmwGearInertiaCmp) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_BmwHwInertiaCmp() (Rte_Inst_BmwSwFctDi->Pim_BmwHwInertiaCmp) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_BmwHysActvInfl() (Rte_Inst_BmwSwFctDi->Pim_BmwHysActvInfl) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_BmwIfNegDampg() (Rte_Inst_BmwSwFctDi->Pim_BmwIfNegDampg) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_BmwIfNegFac() (Rte_Inst_BmwSwFctDi->Pim_BmwIfNegFac) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_BmwIfNegHwTq() (Rte_Inst_BmwSwFctDi->Pim_BmwIfNegHwTq) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_BmwIfNegMotTq() (Rte_Inst_BmwSwFctDi->Pim_BmwIfNegMotTq) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_BmwLrnSwt() (Rte_Inst_BmwSwFctDi->Pim_BmwLrnSwt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_BmwPrkgPwrDampg() (Rte_Inst_BmwSwFctDi->Pim_BmwPrkgPwrDampg) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_BmwPullCmp() (Rte_Inst_BmwSwFctDi->Pim_BmwPullCmp) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_PrevCodingDataMode() (Rte_Inst_BmwSwFctDi->Pim_PrevCodingDataMode) /* PRQA S 3453 */ /* MD_MSR_19.7 */




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   uint8 *Rte_Pim_BmwActvRtn(void)
 *   uint8 *Rte_Pim_BmwEngStrtStop(void)
 *   uint8 *Rte_Pim_BmwEpsOscn(void)
 *   uint8 *Rte_Pim_BmwFricCmp(void)
 *   uint8 *Rte_Pim_BmwGearInertiaCmp(void)
 *   uint8 *Rte_Pim_BmwHwInertiaCmp(void)
 *   uint8 *Rte_Pim_BmwHysActvInfl(void)
 *   uint8 *Rte_Pim_BmwIfNegDampg(void)
 *   uint8 *Rte_Pim_BmwIfNegFac(void)
 *   uint8 *Rte_Pim_BmwIfNegHwTq(void)
 *   uint8 *Rte_Pim_BmwIfNegMotTq(void)
 *   uint8 *Rte_Pim_BmwLrnSwt(void)
 *   uint8 *Rte_Pim_BmwPrkgPwrDampg(void)
 *   uint8 *Rte_Pim_BmwPullCmp(void)
 *   uint8 *Rte_Pim_PrevCodingDataMode(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   uint8 Rte_Prm_BmwSwFctDiBmwActvRtnOvrd_Val(void)
 *   uint8 Rte_Prm_BmwSwFctDiBmwEngStrtStopOvrd_Val(void)
 *   uint8 Rte_Prm_BmwSwFctDiBmwEpsOscnOvrd_Val(void)
 *   uint8 Rte_Prm_BmwSwFctDiBmwFricCmpOvrd_Val(void)
 *   uint8 Rte_Prm_BmwSwFctDiBmwGearInertiaCmpOvrd_Val(void)
 *   uint8 Rte_Prm_BmwSwFctDiBmwHwInertiaCmpOvrd_Val(void)
 *   uint8 Rte_Prm_BmwSwFctDiBmwHysActvInflOvrd_Val(void)
 *   uint8 Rte_Prm_BmwSwFctDiBmwIfNegDampgOvrd_Val(void)
 *   uint8 Rte_Prm_BmwSwFctDiBmwIfNegFacOvrd_Val(void)
 *   uint8 Rte_Prm_BmwSwFctDiBmwIfNegHwTqOvrd_Val(void)
 *   uint8 Rte_Prm_BmwSwFctDiBmwIfNegMotTqOvrd_Val(void)
 *   uint8 Rte_Prm_BmwSwFctDiBmwLrnSwtOvrd_Val(void)
 *   uint8 Rte_Prm_BmwSwFctDiBmwPrkgPwrDampgOvrd_Val(void)
 *   uint8 Rte_Prm_BmwSwFctDiBmwPullCmpOvrd_Val(void)
 *   uint8 Rte_Prm_BmwSwFctDiCodingOvrd_Val(void)
 *   uint8 Rte_Prm_BmwSwFctDiMaxCurrAtHiSpdOvrd_Val(void)
 *   uint8 Rte_Prm_BmwSwFctDiMaxCurrAtLoSpdOvrd_Val(void)
 *
 *********************************************************************************************************************/


# define BmwSwFctDi_START_SEC_CODE
# include "BmwSwFctDi_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwSwFctDiInit1
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
 *   Std_ReturnType Rte_Read_CtrldVelRtnCmd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_HwTqCmdHys_Val(float32 *data)
 *   Std_ReturnType Rte_Read_InertiaCmpVelCmdDi_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_PullCmpCmdDi_Logl(boolean *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_BmwOutpTqOvrlCmdEna_Logl(boolean data)
 *   Std_ReturnType Rte_Write_BmwStrtStopMsgEna_Logl(boolean data)
 *   Std_ReturnType Rte_Write_CtrldVelRtnCmdBmwOvrd_Val(float32 data)
 *   Std_ReturnType Rte_Write_DampgCmdPwrPrkgEna_Logl(boolean data)
 *   Std_ReturnType Rte_Write_DrvgDynFacEna_Logl(boolean data)
 *   Std_ReturnType Rte_Write_FricLrngCustEna_Logl(boolean data)
 *   Std_ReturnType Rte_Write_HaptcFbEna_Logl(boolean data)
 *   Std_ReturnType Rte_Write_HwTqCmdHysBmwOvrd_Val(float32 data)
 *   Std_ReturnType Rte_Write_HwTqOvrlCmdEna_Logl(boolean data)
 *   Std_ReturnType Rte_Write_InertiaCmpVelCmdDiBmwOvrd_Logl(boolean data)
 *   Std_ReturnType Rte_Write_MaxCurrAtHiSpd_Val(float32 data)
 *   Std_ReturnType Rte_Write_MaxCurrAtLoSpd_Val(float32 data)
 *   Std_ReturnType Rte_Write_PullCmpCmdDiBmwOvrd_Logl(boolean data)
 *   Std_ReturnType Rte_Write_TrfcJamAssiCmdEna_Logl(boolean data)
 *   Std_ReturnType Rte_Write_TunSetHndlrEna_Logl(boolean data)
 *
 * Mode Interfaces:
 * ================
 *   uint8 Rte_Mode_Coding_DataMode_Mode(void)
 *   Modes of Rte_ModeType_Coding_DataMode:
 *   - RTE_MODE_Coding_DataMode_NCDSTATE_DEFAULT
 *   - RTE_MODE_Coding_DataMode_NCDSTATE_INPROGRESS
 *   - RTE_MODE_Coding_DataMode_NCDSTATE_QUALIFIED
 *   - RTE_MODE_Coding_DataMode_NCDSTATE_UNDEFINED
 *   - RTE_MODE_Coding_DataMode_NCDSTATE_UNQUALIFIED
 *   - RTE_TRANSITION_Coding_DataMode
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_Data_GetCurrentLimit(uint8 *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME00_00_CalculationOfLoadMinusstateMinusdependentSteeringAssistance(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME00_01_CalculationOfActiveReturn(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME00_02_reserved(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME00_03_ActiveInfluenceOnTheSteeringHysterisis(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME01_03_ParkingPowerDamping(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME02_00_CompensationOfFriction(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME02_01_CompensationOfConstantSteeringPullAndLateralInclinationPull(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME02_02(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME02_03(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME02_04_CompensationOfInertiaOfTheSteeringGear(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME02_05_CompensationOfInertiaOfTheSteeringWheel(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME02_06(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME02_07(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME03_01_VoltageDependantDegredation(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME03_02_SpeedDependantDegredation(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME04_00_DrivingDynamicsInterfaceMinusDriversTorque(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME04_00_DrivingDynamicsInterfaceMinusMotorTorque(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME04_02_DrivingDynamicsInterfaceMinusFactors(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME04_03_DrivingDynamicsInterfaceMinusAdditionalDamping(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME04_04_EPSVibration(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME04_05_DrivingExperienceSwitch(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME04_06_reserved(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME04_07_automaticEngineStartStopFunction(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME05_00_ActiveFanActuation(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetSpeedMinuslimitForMaxCurrent(uint8 *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_BmwSwFctDiInit1 BmwSwFctDiInit1
FUNC(void, BmwSwFctDi_CODE) BmwSwFctDiInit1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwSwFctDiPer1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_CtrldVelRtnCmd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_HwTqCmdHys_Val(float32 *data)
 *   Std_ReturnType Rte_Read_InertiaCmpVelCmdDi_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_PullCmpCmdDi_Logl(boolean *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_BmwOutpTqOvrlCmdEna_Logl(boolean data)
 *   Std_ReturnType Rte_Write_BmwStrtStopMsgEna_Logl(boolean data)
 *   Std_ReturnType Rte_Write_CtrldVelRtnCmdBmwOvrd_Val(float32 data)
 *   Std_ReturnType Rte_Write_DampgCmdPwrPrkgEna_Logl(boolean data)
 *   Std_ReturnType Rte_Write_DrvgDynFacEna_Logl(boolean data)
 *   Std_ReturnType Rte_Write_FricLrngCustEna_Logl(boolean data)
 *   Std_ReturnType Rte_Write_HaptcFbEna_Logl(boolean data)
 *   Std_ReturnType Rte_Write_HwTqCmdHysBmwOvrd_Val(float32 data)
 *   Std_ReturnType Rte_Write_HwTqOvrlCmdEna_Logl(boolean data)
 *   Std_ReturnType Rte_Write_InertiaCmpVelCmdDiBmwOvrd_Logl(boolean data)
 *   Std_ReturnType Rte_Write_MaxCurrAtHiSpd_Val(float32 data)
 *   Std_ReturnType Rte_Write_MaxCurrAtLoSpd_Val(float32 data)
 *   Std_ReturnType Rte_Write_PullCmpCmdDiBmwOvrd_Logl(boolean data)
 *   Std_ReturnType Rte_Write_TrfcJamAssiCmdEna_Logl(boolean data)
 *   Std_ReturnType Rte_Write_TunSetHndlrEna_Logl(boolean data)
 *
 * Mode Interfaces:
 * ================
 *   uint8 Rte_Mode_Coding_DataMode_Mode(void)
 *   Modes of Rte_ModeType_Coding_DataMode:
 *   - RTE_MODE_Coding_DataMode_NCDSTATE_DEFAULT
 *   - RTE_MODE_Coding_DataMode_NCDSTATE_INPROGRESS
 *   - RTE_MODE_Coding_DataMode_NCDSTATE_QUALIFIED
 *   - RTE_MODE_Coding_DataMode_NCDSTATE_UNDEFINED
 *   - RTE_MODE_Coding_DataMode_NCDSTATE_UNQUALIFIED
 *   - RTE_TRANSITION_Coding_DataMode
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_Data_GetCurrentLimit(uint8 *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME00_00_CalculationOfLoadMinusstateMinusdependentSteeringAssistance(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME00_01_CalculationOfActiveReturn(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME00_02_reserved(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME00_03_ActiveInfluenceOnTheSteeringHysterisis(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME01_03_ParkingPowerDamping(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME02_00_CompensationOfFriction(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME02_01_CompensationOfConstantSteeringPullAndLateralInclinationPull(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME02_02(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME02_03(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME02_04_CompensationOfInertiaOfTheSteeringGear(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME02_05_CompensationOfInertiaOfTheSteeringWheel(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME02_06(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME02_07(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME03_00_reserved(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME03_01_VoltageDependantDegredation(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME03_02_SpeedDependantDegredation(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME04_00_DrivingDynamicsInterfaceMinusDriversTorque(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME04_00_DrivingDynamicsInterfaceMinusMotorTorque(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME04_02_DrivingDynamicsInterfaceMinusFactors(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME04_03_DrivingDynamicsInterfaceMinusAdditionalDamping(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME04_04_EPSVibration(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME04_05_DrivingExperienceSwitch(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME04_06_reserved(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME04_07_automaticEngineStartStopFunction(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME05_00_ActiveFanActuation(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetSpeedMinuslimitForMaxCurrent(uint8 *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_BmwSwFctDiPer1 BmwSwFctDiPer1
FUNC(void, BmwSwFctDi_CODE) BmwSwFctDiPer1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define BmwSwFctDi_STOP_SEC_CODE
# include "BmwSwFctDi_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_Data_E_NOT_OK (1U)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_BMWSWFCTDI_H */
