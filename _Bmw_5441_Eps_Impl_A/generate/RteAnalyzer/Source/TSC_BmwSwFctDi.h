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
 *          File:  TSC_BmwSwFctDi.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Header of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/


/** Sender receiver - explicit read services */
Std_ReturnType TSC_BmwSwFctDi_Rte_Read_CtrldVelRtnCmd_Val(float32 *data);
Std_ReturnType TSC_BmwSwFctDi_Rte_Read_HwTqCmdHys_Val(float32 *data);
Std_ReturnType TSC_BmwSwFctDi_Rte_Read_InertiaCmpVelCmdDi_Logl(boolean *data);
Std_ReturnType TSC_BmwSwFctDi_Rte_Read_PullCmpCmdDi_Logl(boolean *data);
Std_ReturnType TSC_BmwSwFctDi_Rte_Read_CtrldVelRtnCmd_Val(float32 *data);
Std_ReturnType TSC_BmwSwFctDi_Rte_Read_HwTqCmdHys_Val(float32 *data);
Std_ReturnType TSC_BmwSwFctDi_Rte_Read_InertiaCmpVelCmdDi_Logl(boolean *data);
Std_ReturnType TSC_BmwSwFctDi_Rte_Read_PullCmpCmdDi_Logl(boolean *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_BmwSwFctDi_Rte_Write_BmwOutpTqOvrlCmdEna_Logl(boolean data);
Std_ReturnType TSC_BmwSwFctDi_Rte_Write_BmwStrtStopMsgEna_Logl(boolean data);
Std_ReturnType TSC_BmwSwFctDi_Rte_Write_CtrldVelRtnCmdBmwOvrd_Val(float32 data);
Std_ReturnType TSC_BmwSwFctDi_Rte_Write_DampgCmdPwrPrkgEna_Logl(boolean data);
Std_ReturnType TSC_BmwSwFctDi_Rte_Write_DrvgDynFacEna_Logl(boolean data);
Std_ReturnType TSC_BmwSwFctDi_Rte_Write_FricLrngCustEna_Logl(boolean data);
Std_ReturnType TSC_BmwSwFctDi_Rte_Write_HaptcFbEna_Logl(boolean data);
Std_ReturnType TSC_BmwSwFctDi_Rte_Write_HwTqCmdHysBmwOvrd_Val(float32 data);
Std_ReturnType TSC_BmwSwFctDi_Rte_Write_HwTqOvrlCmdEna_Logl(boolean data);
Std_ReturnType TSC_BmwSwFctDi_Rte_Write_InertiaCmpVelCmdDiBmwOvrd_Logl(boolean data);
Std_ReturnType TSC_BmwSwFctDi_Rte_Write_MaxCurrAtHiSpd_Val(float32 data);
Std_ReturnType TSC_BmwSwFctDi_Rte_Write_MaxCurrAtLoSpd_Val(float32 data);
Std_ReturnType TSC_BmwSwFctDi_Rte_Write_PullCmpCmdDiBmwOvrd_Logl(boolean data);
Std_ReturnType TSC_BmwSwFctDi_Rte_Write_TrfcJamAssiCmdEna_Logl(boolean data);
Std_ReturnType TSC_BmwSwFctDi_Rte_Write_TunSetHndlrEna_Logl(boolean data);
Std_ReturnType TSC_BmwSwFctDi_Rte_Write_BmwOutpTqOvrlCmdEna_Logl(boolean data);
Std_ReturnType TSC_BmwSwFctDi_Rte_Write_BmwStrtStopMsgEna_Logl(boolean data);
Std_ReturnType TSC_BmwSwFctDi_Rte_Write_CtrldVelRtnCmdBmwOvrd_Val(float32 data);
Std_ReturnType TSC_BmwSwFctDi_Rte_Write_DampgCmdPwrPrkgEna_Logl(boolean data);
Std_ReturnType TSC_BmwSwFctDi_Rte_Write_DrvgDynFacEna_Logl(boolean data);
Std_ReturnType TSC_BmwSwFctDi_Rte_Write_FricLrngCustEna_Logl(boolean data);
Std_ReturnType TSC_BmwSwFctDi_Rte_Write_HaptcFbEna_Logl(boolean data);
Std_ReturnType TSC_BmwSwFctDi_Rte_Write_HwTqCmdHysBmwOvrd_Val(float32 data);
Std_ReturnType TSC_BmwSwFctDi_Rte_Write_HwTqOvrlCmdEna_Logl(boolean data);
Std_ReturnType TSC_BmwSwFctDi_Rte_Write_InertiaCmpVelCmdDiBmwOvrd_Logl(boolean data);
Std_ReturnType TSC_BmwSwFctDi_Rte_Write_MaxCurrAtHiSpd_Val(float32 data);
Std_ReturnType TSC_BmwSwFctDi_Rte_Write_MaxCurrAtLoSpd_Val(float32 data);
Std_ReturnType TSC_BmwSwFctDi_Rte_Write_PullCmpCmdDiBmwOvrd_Logl(boolean data);
Std_ReturnType TSC_BmwSwFctDi_Rte_Write_TrfcJamAssiCmdEna_Logl(boolean data);
Std_ReturnType TSC_BmwSwFctDi_Rte_Write_TunSetHndlrEna_Logl(boolean data);

/** Client server interfaces */
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetCurrentLimit(uint8 *Value);
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME00_00_CalculationOfLoadMinusstateMinusdependentSteeringAssistance(boolean *Value);
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME00_01_CalculationOfActiveReturn(boolean *Value);
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME00_02_reserved(boolean *Value);
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME00_03_ActiveInfluenceOnTheSteeringHysterisis(boolean *Value);
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME01_03_ParkingPowerDamping(boolean *Value);
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME02_00_CompensationOfFriction(boolean *Value);
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME02_01_CompensationOfConstantSteeringPullAndLateralInclinationPull(boolean *Value);
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME02_02(boolean *Value);
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME02_03(boolean *Value);
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME02_04_CompensationOfInertiaOfTheSteeringGear(boolean *Value);
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME02_05_CompensationOfInertiaOfTheSteeringWheel(boolean *Value);
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME02_06(boolean *Value);
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME02_07(boolean *Value);
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME03_01_VoltageDependantDegredation(boolean *Value);
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME03_02_SpeedDependantDegredation(boolean *Value);
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME04_00_DrivingDynamicsInterfaceMinusDriversTorque(boolean *Value);
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME04_00_DrivingDynamicsInterfaceMinusMotorTorque(boolean *Value);
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME04_02_DrivingDynamicsInterfaceMinusFactors(boolean *Value);
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME04_03_DrivingDynamicsInterfaceMinusAdditionalDamping(boolean *Value);
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME04_04_EPSVibration(boolean *Value);
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME04_05_DrivingExperienceSwitch(boolean *Value);
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME04_06_reserved(boolean *Value);
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME04_07_automaticEngineStartStopFunction(boolean *Value);
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME05_00_ActiveFanActuation(boolean *Value);
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetSpeedMinuslimitForMaxCurrent(uint8 *Value);
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetCurrentLimit(uint8 *Value);
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME00_00_CalculationOfLoadMinusstateMinusdependentSteeringAssistance(boolean *Value);
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME00_01_CalculationOfActiveReturn(boolean *Value);
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME00_02_reserved(boolean *Value);
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME00_03_ActiveInfluenceOnTheSteeringHysterisis(boolean *Value);
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME01_03_ParkingPowerDamping(boolean *Value);
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME02_00_CompensationOfFriction(boolean *Value);
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME02_01_CompensationOfConstantSteeringPullAndLateralInclinationPull(boolean *Value);
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME02_02(boolean *Value);
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME02_03(boolean *Value);
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME02_04_CompensationOfInertiaOfTheSteeringGear(boolean *Value);
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME02_05_CompensationOfInertiaOfTheSteeringWheel(boolean *Value);
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME02_06(boolean *Value);
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME02_07(boolean *Value);
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME03_00_reserved(boolean *Value);
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME03_01_VoltageDependantDegredation(boolean *Value);
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME03_02_SpeedDependantDegredation(boolean *Value);
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME04_00_DrivingDynamicsInterfaceMinusDriversTorque(boolean *Value);
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME04_00_DrivingDynamicsInterfaceMinusMotorTorque(boolean *Value);
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME04_02_DrivingDynamicsInterfaceMinusFactors(boolean *Value);
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME04_03_DrivingDynamicsInterfaceMinusAdditionalDamping(boolean *Value);
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME04_04_EPSVibration(boolean *Value);
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME04_05_DrivingExperienceSwitch(boolean *Value);
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME04_06_reserved(boolean *Value);
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME04_07_automaticEngineStartStopFunction(boolean *Value);
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME05_00_ActiveFanActuation(boolean *Value);
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetSpeedMinuslimitForMaxCurrent(uint8 *Value);

/** Mode switches */
uint8 TSC_BmwSwFctDi_Rte_Mode_Coding_DataMode_Mode(void);
uint8 TSC_BmwSwFctDi_Rte_Mode_Coding_DataMode_Mode(void);

/** Calibration Component Calibration Parameters */
uint8  TSC_BmwSwFctDi_Rte_Prm_BmwSwFctDiBmwActvRtnOvrd_Val(void);
uint8  TSC_BmwSwFctDi_Rte_Prm_BmwSwFctDiBmwEngStrtStopOvrd_Val(void);
uint8  TSC_BmwSwFctDi_Rte_Prm_BmwSwFctDiBmwEpsOscnOvrd_Val(void);
uint8  TSC_BmwSwFctDi_Rte_Prm_BmwSwFctDiBmwFricCmpOvrd_Val(void);
uint8  TSC_BmwSwFctDi_Rte_Prm_BmwSwFctDiBmwGearInertiaCmpOvrd_Val(void);
uint8  TSC_BmwSwFctDi_Rte_Prm_BmwSwFctDiBmwHwInertiaCmpOvrd_Val(void);
uint8  TSC_BmwSwFctDi_Rte_Prm_BmwSwFctDiBmwHysActvInflOvrd_Val(void);
uint8  TSC_BmwSwFctDi_Rte_Prm_BmwSwFctDiBmwIfNegDampgOvrd_Val(void);
uint8  TSC_BmwSwFctDi_Rte_Prm_BmwSwFctDiBmwIfNegFacOvrd_Val(void);
uint8  TSC_BmwSwFctDi_Rte_Prm_BmwSwFctDiBmwIfNegHwTqOvrd_Val(void);
uint8  TSC_BmwSwFctDi_Rte_Prm_BmwSwFctDiBmwIfNegMotTqOvrd_Val(void);
uint8  TSC_BmwSwFctDi_Rte_Prm_BmwSwFctDiBmwLrnSwtOvrd_Val(void);
uint8  TSC_BmwSwFctDi_Rte_Prm_BmwSwFctDiBmwPrkgPwrDampgOvrd_Val(void);
uint8  TSC_BmwSwFctDi_Rte_Prm_BmwSwFctDiBmwPullCmpOvrd_Val(void);
uint8  TSC_BmwSwFctDi_Rte_Prm_BmwSwFctDiCodingOvrd_Val(void);
uint8  TSC_BmwSwFctDi_Rte_Prm_BmwSwFctDiMaxCurrAtHiSpdOvrd_Val(void);
uint8  TSC_BmwSwFctDi_Rte_Prm_BmwSwFctDiMaxCurrAtLoSpdOvrd_Val(void);

/** Per Instance Memories */
uint8 *TSC_BmwSwFctDi_Rte_Pim_BmwActvRtn(void);
uint8 *TSC_BmwSwFctDi_Rte_Pim_BmwEngStrtStop(void);
uint8 *TSC_BmwSwFctDi_Rte_Pim_BmwEpsOscn(void);
uint8 *TSC_BmwSwFctDi_Rte_Pim_BmwFricCmp(void);
uint8 *TSC_BmwSwFctDi_Rte_Pim_BmwGearInertiaCmp(void);
uint8 *TSC_BmwSwFctDi_Rte_Pim_BmwHwInertiaCmp(void);
uint8 *TSC_BmwSwFctDi_Rte_Pim_BmwHysActvInfl(void);
uint8 *TSC_BmwSwFctDi_Rte_Pim_BmwIfNegDampg(void);
uint8 *TSC_BmwSwFctDi_Rte_Pim_BmwIfNegFac(void);
uint8 *TSC_BmwSwFctDi_Rte_Pim_BmwIfNegHwTq(void);
uint8 *TSC_BmwSwFctDi_Rte_Pim_BmwIfNegMotTq(void);
uint8 *TSC_BmwSwFctDi_Rte_Pim_BmwLrnSwt(void);
uint8 *TSC_BmwSwFctDi_Rte_Pim_BmwPrkgPwrDampg(void);
uint8 *TSC_BmwSwFctDi_Rte_Pim_BmwPullCmp(void);
uint8 *TSC_BmwSwFctDi_Rte_Pim_PrevCodingDataMode(void);



