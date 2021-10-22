/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  BmwSwFctDi.c
 *        Config:  EPS.dpa
 *     SW-C Type:  BmwSwFctDi
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <BmwSwFctDi>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_5.1_777, MD_MSR_5.1_779 */
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
/* PRQA S 0614 EOF */ /* MD_Rte_TestCode */

/* PRQA S 3109 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3112 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3197 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3198 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3199 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3201 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3203 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3205 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3206 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3218 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3229 EOF */ /* MD_Rte_TestCode */
/* PRQA S 2002 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3334 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3417 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3426 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3453 EOF */ /* MD_Rte_TestCode */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_BmwSwFctDi.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_BmwSwFctDi.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"
#include "float.h"

static void BmwSwFctDi_TestDefines(void);


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * boolean: Boolean (standard type)
 * float32: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 *********************************************************************************************************************/


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


#define BmwSwFctDi_START_SEC_CODE
#include "BmwSwFctDi_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

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
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwSwFctDiInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwSwFctDi_CODE) BmwSwFctDiInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwSwFctDiInit1
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  float32 Read_CtrldVelRtnCmd_Val;
  float32 Read_HwTqCmdHys_Val;
  boolean Read_InertiaCmpVelCmdDi_Logl;
  boolean Read_PullCmpCmdDi_Logl;

  uint8 PimBmwActvRtn;
  uint8 PimBmwEngStrtStop;
  uint8 PimBmwEpsOscn;
  uint8 PimBmwFricCmp;
  uint8 PimBmwGearInertiaCmp;
  uint8 PimBmwHwInertiaCmp;
  uint8 PimBmwHysActvInfl;
  uint8 PimBmwIfNegDampg;
  uint8 PimBmwIfNegFac;
  uint8 PimBmwIfNegHwTq;
  uint8 PimBmwIfNegMotTq;
  uint8 PimBmwLrnSwt;
  uint8 PimBmwPrkgPwrDampg;
  uint8 PimBmwPullCmp;
  uint8 PimPrevCodingDataMode;

  uint8 BmwSwFctDiBmwActvRtnOvrd_Val_data;
  uint8 BmwSwFctDiBmwEngStrtStopOvrd_Val_data;
  uint8 BmwSwFctDiBmwEpsOscnOvrd_Val_data;
  uint8 BmwSwFctDiBmwFricCmpOvrd_Val_data;
  uint8 BmwSwFctDiBmwGearInertiaCmpOvrd_Val_data;
  uint8 BmwSwFctDiBmwHwInertiaCmpOvrd_Val_data;
  uint8 BmwSwFctDiBmwHysActvInflOvrd_Val_data;
  uint8 BmwSwFctDiBmwIfNegDampgOvrd_Val_data;
  uint8 BmwSwFctDiBmwIfNegFacOvrd_Val_data;
  uint8 BmwSwFctDiBmwIfNegHwTqOvrd_Val_data;
  uint8 BmwSwFctDiBmwIfNegMotTqOvrd_Val_data;
  uint8 BmwSwFctDiBmwLrnSwtOvrd_Val_data;
  uint8 BmwSwFctDiBmwPrkgPwrDampgOvrd_Val_data;
  uint8 BmwSwFctDiBmwPullCmpOvrd_Val_data;
  uint8 BmwSwFctDiCodingOvrd_Val_data;
  uint8 BmwSwFctDiMaxCurrAtHiSpdOvrd_Val_data;
  uint8 BmwSwFctDiMaxCurrAtLoSpdOvrd_Val_data;

  Rte_ModeType_Coding_DataMode Coding_DataMode_Mode;

  uint8 Call_Data_GetCurrentLimit_Value = 0U;
  boolean Call_Data_GetNAME00_00_CalculationOfLoadMinusstateMinusdependentSteeringAssistance_Value = FALSE;
  boolean Call_Data_GetNAME00_01_CalculationOfActiveReturn_Value = FALSE;
  boolean Call_Data_GetNAME00_02_reserved_Value = FALSE;
  boolean Call_Data_GetNAME00_03_ActiveInfluenceOnTheSteeringHysterisis_Value = FALSE;
  boolean Call_Data_GetNAME01_03_ParkingPowerDamping_Value = FALSE;
  boolean Call_Data_GetNAME02_00_CompensationOfFriction_Value = FALSE;
  boolean Call_Data_GetNAME02_01_CompensationOfConstantSteeringPullAndLateralInclinationPull_Value = FALSE;
  boolean Call_Data_GetNAME02_02_Value = FALSE;
  boolean Call_Data_GetNAME02_03_Value = FALSE;
  boolean Call_Data_GetNAME02_04_CompensationOfInertiaOfTheSteeringGear_Value = FALSE;
  boolean Call_Data_GetNAME02_05_CompensationOfInertiaOfTheSteeringWheel_Value = FALSE;
  boolean Call_Data_GetNAME02_06_Value = FALSE;
  boolean Call_Data_GetNAME02_07_Value = FALSE;
  boolean Call_Data_GetNAME03_01_VoltageDependantDegredation_Value = FALSE;
  boolean Call_Data_GetNAME03_02_SpeedDependantDegredation_Value = FALSE;
  boolean Call_Data_GetNAME04_00_DrivingDynamicsInterfaceMinusDriversTorque_Value = FALSE;
  boolean Call_Data_GetNAME04_00_DrivingDynamicsInterfaceMinusMotorTorque_Value = FALSE;
  boolean Call_Data_GetNAME04_02_DrivingDynamicsInterfaceMinusFactors_Value = FALSE;
  boolean Call_Data_GetNAME04_03_DrivingDynamicsInterfaceMinusAdditionalDamping_Value = FALSE;
  boolean Call_Data_GetNAME04_04_EPSVibration_Value = FALSE;
  boolean Call_Data_GetNAME04_05_DrivingExperienceSwitch_Value = FALSE;
  boolean Call_Data_GetNAME04_06_reserved_Value = FALSE;
  boolean Call_Data_GetNAME04_07_automaticEngineStartStopFunction_Value = FALSE;
  boolean Call_Data_GetNAME05_00_ActiveFanActuation_Value = FALSE;
  uint8 Call_Data_GetSpeedMinuslimitForMaxCurrent_Value = 0U;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimBmwActvRtn = *TSC_BmwSwFctDi_Rte_Pim_BmwActvRtn();
  *TSC_BmwSwFctDi_Rte_Pim_BmwActvRtn() = PimBmwActvRtn;
  PimBmwEngStrtStop = *TSC_BmwSwFctDi_Rte_Pim_BmwEngStrtStop();
  *TSC_BmwSwFctDi_Rte_Pim_BmwEngStrtStop() = PimBmwEngStrtStop;
  PimBmwEpsOscn = *TSC_BmwSwFctDi_Rte_Pim_BmwEpsOscn();
  *TSC_BmwSwFctDi_Rte_Pim_BmwEpsOscn() = PimBmwEpsOscn;
  PimBmwFricCmp = *TSC_BmwSwFctDi_Rte_Pim_BmwFricCmp();
  *TSC_BmwSwFctDi_Rte_Pim_BmwFricCmp() = PimBmwFricCmp;
  PimBmwGearInertiaCmp = *TSC_BmwSwFctDi_Rte_Pim_BmwGearInertiaCmp();
  *TSC_BmwSwFctDi_Rte_Pim_BmwGearInertiaCmp() = PimBmwGearInertiaCmp;
  PimBmwHwInertiaCmp = *TSC_BmwSwFctDi_Rte_Pim_BmwHwInertiaCmp();
  *TSC_BmwSwFctDi_Rte_Pim_BmwHwInertiaCmp() = PimBmwHwInertiaCmp;
  PimBmwHysActvInfl = *TSC_BmwSwFctDi_Rte_Pim_BmwHysActvInfl();
  *TSC_BmwSwFctDi_Rte_Pim_BmwHysActvInfl() = PimBmwHysActvInfl;
  PimBmwIfNegDampg = *TSC_BmwSwFctDi_Rte_Pim_BmwIfNegDampg();
  *TSC_BmwSwFctDi_Rte_Pim_BmwIfNegDampg() = PimBmwIfNegDampg;
  PimBmwIfNegFac = *TSC_BmwSwFctDi_Rte_Pim_BmwIfNegFac();
  *TSC_BmwSwFctDi_Rte_Pim_BmwIfNegFac() = PimBmwIfNegFac;
  PimBmwIfNegHwTq = *TSC_BmwSwFctDi_Rte_Pim_BmwIfNegHwTq();
  *TSC_BmwSwFctDi_Rte_Pim_BmwIfNegHwTq() = PimBmwIfNegHwTq;
  PimBmwIfNegMotTq = *TSC_BmwSwFctDi_Rte_Pim_BmwIfNegMotTq();
  *TSC_BmwSwFctDi_Rte_Pim_BmwIfNegMotTq() = PimBmwIfNegMotTq;
  PimBmwLrnSwt = *TSC_BmwSwFctDi_Rte_Pim_BmwLrnSwt();
  *TSC_BmwSwFctDi_Rte_Pim_BmwLrnSwt() = PimBmwLrnSwt;
  PimBmwPrkgPwrDampg = *TSC_BmwSwFctDi_Rte_Pim_BmwPrkgPwrDampg();
  *TSC_BmwSwFctDi_Rte_Pim_BmwPrkgPwrDampg() = PimBmwPrkgPwrDampg;
  PimBmwPullCmp = *TSC_BmwSwFctDi_Rte_Pim_BmwPullCmp();
  *TSC_BmwSwFctDi_Rte_Pim_BmwPullCmp() = PimBmwPullCmp;
  PimPrevCodingDataMode = *TSC_BmwSwFctDi_Rte_Pim_PrevCodingDataMode();
  *TSC_BmwSwFctDi_Rte_Pim_PrevCodingDataMode() = PimPrevCodingDataMode;

  BmwSwFctDiBmwActvRtnOvrd_Val_data = TSC_BmwSwFctDi_Rte_Prm_BmwSwFctDiBmwActvRtnOvrd_Val();
  BmwSwFctDiBmwEngStrtStopOvrd_Val_data = TSC_BmwSwFctDi_Rte_Prm_BmwSwFctDiBmwEngStrtStopOvrd_Val();
  BmwSwFctDiBmwEpsOscnOvrd_Val_data = TSC_BmwSwFctDi_Rte_Prm_BmwSwFctDiBmwEpsOscnOvrd_Val();
  BmwSwFctDiBmwFricCmpOvrd_Val_data = TSC_BmwSwFctDi_Rte_Prm_BmwSwFctDiBmwFricCmpOvrd_Val();
  BmwSwFctDiBmwGearInertiaCmpOvrd_Val_data = TSC_BmwSwFctDi_Rte_Prm_BmwSwFctDiBmwGearInertiaCmpOvrd_Val();
  BmwSwFctDiBmwHwInertiaCmpOvrd_Val_data = TSC_BmwSwFctDi_Rte_Prm_BmwSwFctDiBmwHwInertiaCmpOvrd_Val();
  BmwSwFctDiBmwHysActvInflOvrd_Val_data = TSC_BmwSwFctDi_Rte_Prm_BmwSwFctDiBmwHysActvInflOvrd_Val();
  BmwSwFctDiBmwIfNegDampgOvrd_Val_data = TSC_BmwSwFctDi_Rte_Prm_BmwSwFctDiBmwIfNegDampgOvrd_Val();
  BmwSwFctDiBmwIfNegFacOvrd_Val_data = TSC_BmwSwFctDi_Rte_Prm_BmwSwFctDiBmwIfNegFacOvrd_Val();
  BmwSwFctDiBmwIfNegHwTqOvrd_Val_data = TSC_BmwSwFctDi_Rte_Prm_BmwSwFctDiBmwIfNegHwTqOvrd_Val();
  BmwSwFctDiBmwIfNegMotTqOvrd_Val_data = TSC_BmwSwFctDi_Rte_Prm_BmwSwFctDiBmwIfNegMotTqOvrd_Val();
  BmwSwFctDiBmwLrnSwtOvrd_Val_data = TSC_BmwSwFctDi_Rte_Prm_BmwSwFctDiBmwLrnSwtOvrd_Val();
  BmwSwFctDiBmwPrkgPwrDampgOvrd_Val_data = TSC_BmwSwFctDi_Rte_Prm_BmwSwFctDiBmwPrkgPwrDampgOvrd_Val();
  BmwSwFctDiBmwPullCmpOvrd_Val_data = TSC_BmwSwFctDi_Rte_Prm_BmwSwFctDiBmwPullCmpOvrd_Val();
  BmwSwFctDiCodingOvrd_Val_data = TSC_BmwSwFctDi_Rte_Prm_BmwSwFctDiCodingOvrd_Val();
  BmwSwFctDiMaxCurrAtHiSpdOvrd_Val_data = TSC_BmwSwFctDi_Rte_Prm_BmwSwFctDiMaxCurrAtHiSpdOvrd_Val();
  BmwSwFctDiMaxCurrAtLoSpdOvrd_Val_data = TSC_BmwSwFctDi_Rte_Prm_BmwSwFctDiMaxCurrAtLoSpdOvrd_Val();

  fct_status = TSC_BmwSwFctDi_Rte_Read_CtrldVelRtnCmd_Val(&Read_CtrldVelRtnCmd_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Read_HwTqCmdHys_Val(&Read_HwTqCmdHys_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Read_InertiaCmpVelCmdDi_Logl(&Read_InertiaCmpVelCmdDi_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Read_PullCmpCmdDi_Logl(&Read_PullCmpCmdDi_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Write_BmwOutpTqOvrlCmdEna_Logl(Rte_InitValue_BmwOutpTqOvrlCmdEna_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Write_BmwStrtStopMsgEna_Logl(Rte_InitValue_BmwStrtStopMsgEna_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Write_CtrldVelRtnCmdBmwOvrd_Val(Rte_InitValue_CtrldVelRtnCmdBmwOvrd_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Write_DampgCmdPwrPrkgEna_Logl(Rte_InitValue_DampgCmdPwrPrkgEna_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Write_DrvgDynFacEna_Logl(Rte_InitValue_DrvgDynFacEna_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Write_FricLrngCustEna_Logl(Rte_InitValue_FricLrngCustEna_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Write_HaptcFbEna_Logl(Rte_InitValue_HaptcFbEna_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Write_HwTqCmdHysBmwOvrd_Val(Rte_InitValue_HwTqCmdHysBmwOvrd_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Write_HwTqOvrlCmdEna_Logl(Rte_InitValue_HwTqOvrlCmdEna_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Write_InertiaCmpVelCmdDiBmwOvrd_Logl(Rte_InitValue_InertiaCmpVelCmdDiBmwOvrd_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Write_MaxCurrAtHiSpd_Val(Rte_InitValue_MaxCurrAtHiSpd_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Write_MaxCurrAtLoSpd_Val(Rte_InitValue_MaxCurrAtLoSpd_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Write_PullCmpCmdDiBmwOvrd_Logl(Rte_InitValue_PullCmpCmdDiBmwOvrd_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Write_TrfcJamAssiCmdEna_Logl(Rte_InitValue_TrfcJamAssiCmdEna_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Write_TunSetHndlrEna_Logl(Rte_InitValue_TunSetHndlrEna_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  Coding_DataMode_Mode = TSC_BmwSwFctDi_Rte_Mode_Coding_DataMode_Mode();

  fct_status = TSC_BmwSwFctDi_Rte_Call_Data_GetCurrentLimit(&Call_Data_GetCurrentLimit_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_Data_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Call_Data_GetNAME00_00_CalculationOfLoadMinusstateMinusdependentSteeringAssistance(&Call_Data_GetNAME00_00_CalculationOfLoadMinusstateMinusdependentSteeringAssistance_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_Data_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Call_Data_GetNAME00_01_CalculationOfActiveReturn(&Call_Data_GetNAME00_01_CalculationOfActiveReturn_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_Data_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Call_Data_GetNAME00_02_reserved(&Call_Data_GetNAME00_02_reserved_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_Data_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Call_Data_GetNAME00_03_ActiveInfluenceOnTheSteeringHysterisis(&Call_Data_GetNAME00_03_ActiveInfluenceOnTheSteeringHysterisis_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_Data_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Call_Data_GetNAME01_03_ParkingPowerDamping(&Call_Data_GetNAME01_03_ParkingPowerDamping_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_Data_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Call_Data_GetNAME02_00_CompensationOfFriction(&Call_Data_GetNAME02_00_CompensationOfFriction_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_Data_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Call_Data_GetNAME02_01_CompensationOfConstantSteeringPullAndLateralInclinationPull(&Call_Data_GetNAME02_01_CompensationOfConstantSteeringPullAndLateralInclinationPull_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_Data_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Call_Data_GetNAME02_02(&Call_Data_GetNAME02_02_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_Data_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Call_Data_GetNAME02_03(&Call_Data_GetNAME02_03_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_Data_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Call_Data_GetNAME02_04_CompensationOfInertiaOfTheSteeringGear(&Call_Data_GetNAME02_04_CompensationOfInertiaOfTheSteeringGear_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_Data_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Call_Data_GetNAME02_05_CompensationOfInertiaOfTheSteeringWheel(&Call_Data_GetNAME02_05_CompensationOfInertiaOfTheSteeringWheel_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_Data_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Call_Data_GetNAME02_06(&Call_Data_GetNAME02_06_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_Data_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Call_Data_GetNAME02_07(&Call_Data_GetNAME02_07_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_Data_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Call_Data_GetNAME03_01_VoltageDependantDegredation(&Call_Data_GetNAME03_01_VoltageDependantDegredation_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_Data_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Call_Data_GetNAME03_02_SpeedDependantDegredation(&Call_Data_GetNAME03_02_SpeedDependantDegredation_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_Data_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Call_Data_GetNAME04_00_DrivingDynamicsInterfaceMinusDriversTorque(&Call_Data_GetNAME04_00_DrivingDynamicsInterfaceMinusDriversTorque_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_Data_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Call_Data_GetNAME04_00_DrivingDynamicsInterfaceMinusMotorTorque(&Call_Data_GetNAME04_00_DrivingDynamicsInterfaceMinusMotorTorque_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_Data_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Call_Data_GetNAME04_02_DrivingDynamicsInterfaceMinusFactors(&Call_Data_GetNAME04_02_DrivingDynamicsInterfaceMinusFactors_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_Data_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Call_Data_GetNAME04_03_DrivingDynamicsInterfaceMinusAdditionalDamping(&Call_Data_GetNAME04_03_DrivingDynamicsInterfaceMinusAdditionalDamping_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_Data_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Call_Data_GetNAME04_04_EPSVibration(&Call_Data_GetNAME04_04_EPSVibration_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_Data_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Call_Data_GetNAME04_05_DrivingExperienceSwitch(&Call_Data_GetNAME04_05_DrivingExperienceSwitch_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_Data_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Call_Data_GetNAME04_06_reserved(&Call_Data_GetNAME04_06_reserved_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_Data_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Call_Data_GetNAME04_07_automaticEngineStartStopFunction(&Call_Data_GetNAME04_07_automaticEngineStartStopFunction_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_Data_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Call_Data_GetNAME05_00_ActiveFanActuation(&Call_Data_GetNAME05_00_ActiveFanActuation_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_Data_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Call_Data_GetSpeedMinuslimitForMaxCurrent(&Call_Data_GetSpeedMinuslimitForMaxCurrent_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_Data_E_NOT_OK:
      fct_error = 1;
      break;
  }

  BmwSwFctDi_TestDefines();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

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
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwSwFctDiPer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwSwFctDi_CODE) BmwSwFctDiPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwSwFctDiPer1
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  float32 Read_CtrldVelRtnCmd_Val;
  float32 Read_HwTqCmdHys_Val;
  boolean Read_InertiaCmpVelCmdDi_Logl;
  boolean Read_PullCmpCmdDi_Logl;

  uint8 PimBmwActvRtn;
  uint8 PimBmwEngStrtStop;
  uint8 PimBmwEpsOscn;
  uint8 PimBmwFricCmp;
  uint8 PimBmwGearInertiaCmp;
  uint8 PimBmwHwInertiaCmp;
  uint8 PimBmwHysActvInfl;
  uint8 PimBmwIfNegDampg;
  uint8 PimBmwIfNegFac;
  uint8 PimBmwIfNegHwTq;
  uint8 PimBmwIfNegMotTq;
  uint8 PimBmwLrnSwt;
  uint8 PimBmwPrkgPwrDampg;
  uint8 PimBmwPullCmp;
  uint8 PimPrevCodingDataMode;

  uint8 BmwSwFctDiBmwActvRtnOvrd_Val_data;
  uint8 BmwSwFctDiBmwEngStrtStopOvrd_Val_data;
  uint8 BmwSwFctDiBmwEpsOscnOvrd_Val_data;
  uint8 BmwSwFctDiBmwFricCmpOvrd_Val_data;
  uint8 BmwSwFctDiBmwGearInertiaCmpOvrd_Val_data;
  uint8 BmwSwFctDiBmwHwInertiaCmpOvrd_Val_data;
  uint8 BmwSwFctDiBmwHysActvInflOvrd_Val_data;
  uint8 BmwSwFctDiBmwIfNegDampgOvrd_Val_data;
  uint8 BmwSwFctDiBmwIfNegFacOvrd_Val_data;
  uint8 BmwSwFctDiBmwIfNegHwTqOvrd_Val_data;
  uint8 BmwSwFctDiBmwIfNegMotTqOvrd_Val_data;
  uint8 BmwSwFctDiBmwLrnSwtOvrd_Val_data;
  uint8 BmwSwFctDiBmwPrkgPwrDampgOvrd_Val_data;
  uint8 BmwSwFctDiBmwPullCmpOvrd_Val_data;
  uint8 BmwSwFctDiCodingOvrd_Val_data;
  uint8 BmwSwFctDiMaxCurrAtHiSpdOvrd_Val_data;
  uint8 BmwSwFctDiMaxCurrAtLoSpdOvrd_Val_data;

  Rte_ModeType_Coding_DataMode Coding_DataMode_Mode;

  uint8 Call_Data_GetCurrentLimit_Value = 0U;
  boolean Call_Data_GetNAME00_00_CalculationOfLoadMinusstateMinusdependentSteeringAssistance_Value = FALSE;
  boolean Call_Data_GetNAME00_01_CalculationOfActiveReturn_Value = FALSE;
  boolean Call_Data_GetNAME00_02_reserved_Value = FALSE;
  boolean Call_Data_GetNAME00_03_ActiveInfluenceOnTheSteeringHysterisis_Value = FALSE;
  boolean Call_Data_GetNAME01_03_ParkingPowerDamping_Value = FALSE;
  boolean Call_Data_GetNAME02_00_CompensationOfFriction_Value = FALSE;
  boolean Call_Data_GetNAME02_01_CompensationOfConstantSteeringPullAndLateralInclinationPull_Value = FALSE;
  boolean Call_Data_GetNAME02_02_Value = FALSE;
  boolean Call_Data_GetNAME02_03_Value = FALSE;
  boolean Call_Data_GetNAME02_04_CompensationOfInertiaOfTheSteeringGear_Value = FALSE;
  boolean Call_Data_GetNAME02_05_CompensationOfInertiaOfTheSteeringWheel_Value = FALSE;
  boolean Call_Data_GetNAME02_06_Value = FALSE;
  boolean Call_Data_GetNAME02_07_Value = FALSE;
  boolean Call_Data_GetNAME03_00_reserved_Value = FALSE;
  boolean Call_Data_GetNAME03_01_VoltageDependantDegredation_Value = FALSE;
  boolean Call_Data_GetNAME03_02_SpeedDependantDegredation_Value = FALSE;
  boolean Call_Data_GetNAME04_00_DrivingDynamicsInterfaceMinusDriversTorque_Value = FALSE;
  boolean Call_Data_GetNAME04_00_DrivingDynamicsInterfaceMinusMotorTorque_Value = FALSE;
  boolean Call_Data_GetNAME04_02_DrivingDynamicsInterfaceMinusFactors_Value = FALSE;
  boolean Call_Data_GetNAME04_03_DrivingDynamicsInterfaceMinusAdditionalDamping_Value = FALSE;
  boolean Call_Data_GetNAME04_04_EPSVibration_Value = FALSE;
  boolean Call_Data_GetNAME04_05_DrivingExperienceSwitch_Value = FALSE;
  boolean Call_Data_GetNAME04_06_reserved_Value = FALSE;
  boolean Call_Data_GetNAME04_07_automaticEngineStartStopFunction_Value = FALSE;
  boolean Call_Data_GetNAME05_00_ActiveFanActuation_Value = FALSE;
  uint8 Call_Data_GetSpeedMinuslimitForMaxCurrent_Value = 0U;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimBmwActvRtn = *TSC_BmwSwFctDi_Rte_Pim_BmwActvRtn();
  *TSC_BmwSwFctDi_Rte_Pim_BmwActvRtn() = PimBmwActvRtn;
  PimBmwEngStrtStop = *TSC_BmwSwFctDi_Rte_Pim_BmwEngStrtStop();
  *TSC_BmwSwFctDi_Rte_Pim_BmwEngStrtStop() = PimBmwEngStrtStop;
  PimBmwEpsOscn = *TSC_BmwSwFctDi_Rte_Pim_BmwEpsOscn();
  *TSC_BmwSwFctDi_Rte_Pim_BmwEpsOscn() = PimBmwEpsOscn;
  PimBmwFricCmp = *TSC_BmwSwFctDi_Rte_Pim_BmwFricCmp();
  *TSC_BmwSwFctDi_Rte_Pim_BmwFricCmp() = PimBmwFricCmp;
  PimBmwGearInertiaCmp = *TSC_BmwSwFctDi_Rte_Pim_BmwGearInertiaCmp();
  *TSC_BmwSwFctDi_Rte_Pim_BmwGearInertiaCmp() = PimBmwGearInertiaCmp;
  PimBmwHwInertiaCmp = *TSC_BmwSwFctDi_Rte_Pim_BmwHwInertiaCmp();
  *TSC_BmwSwFctDi_Rte_Pim_BmwHwInertiaCmp() = PimBmwHwInertiaCmp;
  PimBmwHysActvInfl = *TSC_BmwSwFctDi_Rte_Pim_BmwHysActvInfl();
  *TSC_BmwSwFctDi_Rte_Pim_BmwHysActvInfl() = PimBmwHysActvInfl;
  PimBmwIfNegDampg = *TSC_BmwSwFctDi_Rte_Pim_BmwIfNegDampg();
  *TSC_BmwSwFctDi_Rte_Pim_BmwIfNegDampg() = PimBmwIfNegDampg;
  PimBmwIfNegFac = *TSC_BmwSwFctDi_Rte_Pim_BmwIfNegFac();
  *TSC_BmwSwFctDi_Rte_Pim_BmwIfNegFac() = PimBmwIfNegFac;
  PimBmwIfNegHwTq = *TSC_BmwSwFctDi_Rte_Pim_BmwIfNegHwTq();
  *TSC_BmwSwFctDi_Rte_Pim_BmwIfNegHwTq() = PimBmwIfNegHwTq;
  PimBmwIfNegMotTq = *TSC_BmwSwFctDi_Rte_Pim_BmwIfNegMotTq();
  *TSC_BmwSwFctDi_Rte_Pim_BmwIfNegMotTq() = PimBmwIfNegMotTq;
  PimBmwLrnSwt = *TSC_BmwSwFctDi_Rte_Pim_BmwLrnSwt();
  *TSC_BmwSwFctDi_Rte_Pim_BmwLrnSwt() = PimBmwLrnSwt;
  PimBmwPrkgPwrDampg = *TSC_BmwSwFctDi_Rte_Pim_BmwPrkgPwrDampg();
  *TSC_BmwSwFctDi_Rte_Pim_BmwPrkgPwrDampg() = PimBmwPrkgPwrDampg;
  PimBmwPullCmp = *TSC_BmwSwFctDi_Rte_Pim_BmwPullCmp();
  *TSC_BmwSwFctDi_Rte_Pim_BmwPullCmp() = PimBmwPullCmp;
  PimPrevCodingDataMode = *TSC_BmwSwFctDi_Rte_Pim_PrevCodingDataMode();
  *TSC_BmwSwFctDi_Rte_Pim_PrevCodingDataMode() = PimPrevCodingDataMode;

  BmwSwFctDiBmwActvRtnOvrd_Val_data = TSC_BmwSwFctDi_Rte_Prm_BmwSwFctDiBmwActvRtnOvrd_Val();
  BmwSwFctDiBmwEngStrtStopOvrd_Val_data = TSC_BmwSwFctDi_Rte_Prm_BmwSwFctDiBmwEngStrtStopOvrd_Val();
  BmwSwFctDiBmwEpsOscnOvrd_Val_data = TSC_BmwSwFctDi_Rte_Prm_BmwSwFctDiBmwEpsOscnOvrd_Val();
  BmwSwFctDiBmwFricCmpOvrd_Val_data = TSC_BmwSwFctDi_Rte_Prm_BmwSwFctDiBmwFricCmpOvrd_Val();
  BmwSwFctDiBmwGearInertiaCmpOvrd_Val_data = TSC_BmwSwFctDi_Rte_Prm_BmwSwFctDiBmwGearInertiaCmpOvrd_Val();
  BmwSwFctDiBmwHwInertiaCmpOvrd_Val_data = TSC_BmwSwFctDi_Rte_Prm_BmwSwFctDiBmwHwInertiaCmpOvrd_Val();
  BmwSwFctDiBmwHysActvInflOvrd_Val_data = TSC_BmwSwFctDi_Rte_Prm_BmwSwFctDiBmwHysActvInflOvrd_Val();
  BmwSwFctDiBmwIfNegDampgOvrd_Val_data = TSC_BmwSwFctDi_Rte_Prm_BmwSwFctDiBmwIfNegDampgOvrd_Val();
  BmwSwFctDiBmwIfNegFacOvrd_Val_data = TSC_BmwSwFctDi_Rte_Prm_BmwSwFctDiBmwIfNegFacOvrd_Val();
  BmwSwFctDiBmwIfNegHwTqOvrd_Val_data = TSC_BmwSwFctDi_Rte_Prm_BmwSwFctDiBmwIfNegHwTqOvrd_Val();
  BmwSwFctDiBmwIfNegMotTqOvrd_Val_data = TSC_BmwSwFctDi_Rte_Prm_BmwSwFctDiBmwIfNegMotTqOvrd_Val();
  BmwSwFctDiBmwLrnSwtOvrd_Val_data = TSC_BmwSwFctDi_Rte_Prm_BmwSwFctDiBmwLrnSwtOvrd_Val();
  BmwSwFctDiBmwPrkgPwrDampgOvrd_Val_data = TSC_BmwSwFctDi_Rte_Prm_BmwSwFctDiBmwPrkgPwrDampgOvrd_Val();
  BmwSwFctDiBmwPullCmpOvrd_Val_data = TSC_BmwSwFctDi_Rte_Prm_BmwSwFctDiBmwPullCmpOvrd_Val();
  BmwSwFctDiCodingOvrd_Val_data = TSC_BmwSwFctDi_Rte_Prm_BmwSwFctDiCodingOvrd_Val();
  BmwSwFctDiMaxCurrAtHiSpdOvrd_Val_data = TSC_BmwSwFctDi_Rte_Prm_BmwSwFctDiMaxCurrAtHiSpdOvrd_Val();
  BmwSwFctDiMaxCurrAtLoSpdOvrd_Val_data = TSC_BmwSwFctDi_Rte_Prm_BmwSwFctDiMaxCurrAtLoSpdOvrd_Val();

  fct_status = TSC_BmwSwFctDi_Rte_Read_CtrldVelRtnCmd_Val(&Read_CtrldVelRtnCmd_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Read_HwTqCmdHys_Val(&Read_HwTqCmdHys_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Read_InertiaCmpVelCmdDi_Logl(&Read_InertiaCmpVelCmdDi_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Read_PullCmpCmdDi_Logl(&Read_PullCmpCmdDi_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Write_BmwOutpTqOvrlCmdEna_Logl(Rte_InitValue_BmwOutpTqOvrlCmdEna_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Write_BmwStrtStopMsgEna_Logl(Rte_InitValue_BmwStrtStopMsgEna_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Write_CtrldVelRtnCmdBmwOvrd_Val(Rte_InitValue_CtrldVelRtnCmdBmwOvrd_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Write_DampgCmdPwrPrkgEna_Logl(Rte_InitValue_DampgCmdPwrPrkgEna_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Write_DrvgDynFacEna_Logl(Rte_InitValue_DrvgDynFacEna_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Write_FricLrngCustEna_Logl(Rte_InitValue_FricLrngCustEna_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Write_HaptcFbEna_Logl(Rte_InitValue_HaptcFbEna_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Write_HwTqCmdHysBmwOvrd_Val(Rte_InitValue_HwTqCmdHysBmwOvrd_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Write_HwTqOvrlCmdEna_Logl(Rte_InitValue_HwTqOvrlCmdEna_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Write_InertiaCmpVelCmdDiBmwOvrd_Logl(Rte_InitValue_InertiaCmpVelCmdDiBmwOvrd_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Write_MaxCurrAtHiSpd_Val(Rte_InitValue_MaxCurrAtHiSpd_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Write_MaxCurrAtLoSpd_Val(Rte_InitValue_MaxCurrAtLoSpd_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Write_PullCmpCmdDiBmwOvrd_Logl(Rte_InitValue_PullCmpCmdDiBmwOvrd_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Write_TrfcJamAssiCmdEna_Logl(Rte_InitValue_TrfcJamAssiCmdEna_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Write_TunSetHndlrEna_Logl(Rte_InitValue_TunSetHndlrEna_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  Coding_DataMode_Mode = TSC_BmwSwFctDi_Rte_Mode_Coding_DataMode_Mode();

  fct_status = TSC_BmwSwFctDi_Rte_Call_Data_GetCurrentLimit(&Call_Data_GetCurrentLimit_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_Data_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Call_Data_GetNAME00_00_CalculationOfLoadMinusstateMinusdependentSteeringAssistance(&Call_Data_GetNAME00_00_CalculationOfLoadMinusstateMinusdependentSteeringAssistance_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_Data_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Call_Data_GetNAME00_01_CalculationOfActiveReturn(&Call_Data_GetNAME00_01_CalculationOfActiveReturn_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_Data_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Call_Data_GetNAME00_02_reserved(&Call_Data_GetNAME00_02_reserved_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_Data_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Call_Data_GetNAME00_03_ActiveInfluenceOnTheSteeringHysterisis(&Call_Data_GetNAME00_03_ActiveInfluenceOnTheSteeringHysterisis_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_Data_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Call_Data_GetNAME01_03_ParkingPowerDamping(&Call_Data_GetNAME01_03_ParkingPowerDamping_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_Data_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Call_Data_GetNAME02_00_CompensationOfFriction(&Call_Data_GetNAME02_00_CompensationOfFriction_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_Data_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Call_Data_GetNAME02_01_CompensationOfConstantSteeringPullAndLateralInclinationPull(&Call_Data_GetNAME02_01_CompensationOfConstantSteeringPullAndLateralInclinationPull_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_Data_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Call_Data_GetNAME02_02(&Call_Data_GetNAME02_02_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_Data_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Call_Data_GetNAME02_03(&Call_Data_GetNAME02_03_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_Data_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Call_Data_GetNAME02_04_CompensationOfInertiaOfTheSteeringGear(&Call_Data_GetNAME02_04_CompensationOfInertiaOfTheSteeringGear_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_Data_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Call_Data_GetNAME02_05_CompensationOfInertiaOfTheSteeringWheel(&Call_Data_GetNAME02_05_CompensationOfInertiaOfTheSteeringWheel_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_Data_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Call_Data_GetNAME02_06(&Call_Data_GetNAME02_06_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_Data_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Call_Data_GetNAME02_07(&Call_Data_GetNAME02_07_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_Data_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Call_Data_GetNAME03_00_reserved(&Call_Data_GetNAME03_00_reserved_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_Data_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Call_Data_GetNAME03_01_VoltageDependantDegredation(&Call_Data_GetNAME03_01_VoltageDependantDegredation_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_Data_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Call_Data_GetNAME03_02_SpeedDependantDegredation(&Call_Data_GetNAME03_02_SpeedDependantDegredation_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_Data_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Call_Data_GetNAME04_00_DrivingDynamicsInterfaceMinusDriversTorque(&Call_Data_GetNAME04_00_DrivingDynamicsInterfaceMinusDriversTorque_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_Data_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Call_Data_GetNAME04_00_DrivingDynamicsInterfaceMinusMotorTorque(&Call_Data_GetNAME04_00_DrivingDynamicsInterfaceMinusMotorTorque_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_Data_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Call_Data_GetNAME04_02_DrivingDynamicsInterfaceMinusFactors(&Call_Data_GetNAME04_02_DrivingDynamicsInterfaceMinusFactors_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_Data_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Call_Data_GetNAME04_03_DrivingDynamicsInterfaceMinusAdditionalDamping(&Call_Data_GetNAME04_03_DrivingDynamicsInterfaceMinusAdditionalDamping_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_Data_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Call_Data_GetNAME04_04_EPSVibration(&Call_Data_GetNAME04_04_EPSVibration_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_Data_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Call_Data_GetNAME04_05_DrivingExperienceSwitch(&Call_Data_GetNAME04_05_DrivingExperienceSwitch_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_Data_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Call_Data_GetNAME04_06_reserved(&Call_Data_GetNAME04_06_reserved_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_Data_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Call_Data_GetNAME04_07_automaticEngineStartStopFunction(&Call_Data_GetNAME04_07_automaticEngineStartStopFunction_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_Data_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Call_Data_GetNAME05_00_ActiveFanActuation(&Call_Data_GetNAME05_00_ActiveFanActuation_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_Data_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwSwFctDi_Rte_Call_Data_GetSpeedMinuslimitForMaxCurrent(&Call_Data_GetSpeedMinuslimitForMaxCurrent_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_Data_E_NOT_OK:
      fct_error = 1;
      break;
  }


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define BmwSwFctDi_STOP_SEC_CODE
#include "BmwSwFctDi_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void BmwSwFctDi_TestDefines(void)
{
  /* Modes */

  uint8 Test_Coding_DataMode_MV_1 = RTE_MODE_Coding_DataMode_NCDSTATE_INPROGRESS;
  uint8 Test_Coding_DataMode_MV_2 = RTE_MODE_Coding_DataMode_NCDSTATE_DEFAULT;
  uint8 Test_Coding_DataMode_MV_3 = RTE_MODE_Coding_DataMode_NCDSTATE_QUALIFIED;
  uint8 Test_Coding_DataMode_MV_4 = RTE_MODE_Coding_DataMode_NCDSTATE_UNDEFINED;
  uint8 Test_Coding_DataMode_MV_5 = RTE_MODE_Coding_DataMode_NCDSTATE_UNQUALIFIED;
  uint8 Test_Coding_DataMode_TV = RTE_TRANSITION_Coding_DataMode;
}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_TestCode:
     Reason:     This justification is used within the generated test code by the Rte Analyzer.
     Risk:       No functional risk.
     Prevention: Not required.

*/
