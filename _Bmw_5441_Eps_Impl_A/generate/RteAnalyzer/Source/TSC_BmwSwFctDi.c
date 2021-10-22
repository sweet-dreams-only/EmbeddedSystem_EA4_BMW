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
 *          File:  TSC_BmwSwFctDi.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_BmwSwFctDi.h"
#include "TSC_BmwSwFctDi.h"








Std_ReturnType TSC_BmwSwFctDi_Rte_Read_CtrldVelRtnCmd_Val(float32 *data)
{
  return Rte_Read_CtrldVelRtnCmd_Val(data);
}

Std_ReturnType TSC_BmwSwFctDi_Rte_Read_HwTqCmdHys_Val(float32 *data)
{
  return Rte_Read_HwTqCmdHys_Val(data);
}

Std_ReturnType TSC_BmwSwFctDi_Rte_Read_InertiaCmpVelCmdDi_Logl(boolean *data)
{
  return Rte_Read_InertiaCmpVelCmdDi_Logl(data);
}

Std_ReturnType TSC_BmwSwFctDi_Rte_Read_PullCmpCmdDi_Logl(boolean *data)
{
  return Rte_Read_PullCmpCmdDi_Logl(data);
}




Std_ReturnType TSC_BmwSwFctDi_Rte_Write_BmwOutpTqOvrlCmdEna_Logl(boolean data)
{
  return Rte_Write_BmwOutpTqOvrlCmdEna_Logl(data);
}

Std_ReturnType TSC_BmwSwFctDi_Rte_Write_BmwStrtStopMsgEna_Logl(boolean data)
{
  return Rte_Write_BmwStrtStopMsgEna_Logl(data);
}

Std_ReturnType TSC_BmwSwFctDi_Rte_Write_CtrldVelRtnCmdBmwOvrd_Val(float32 data)
{
  return Rte_Write_CtrldVelRtnCmdBmwOvrd_Val(data);
}

Std_ReturnType TSC_BmwSwFctDi_Rte_Write_DampgCmdPwrPrkgEna_Logl(boolean data)
{
  return Rte_Write_DampgCmdPwrPrkgEna_Logl(data);
}

Std_ReturnType TSC_BmwSwFctDi_Rte_Write_DrvgDynFacEna_Logl(boolean data)
{
  return Rte_Write_DrvgDynFacEna_Logl(data);
}

Std_ReturnType TSC_BmwSwFctDi_Rte_Write_FricLrngCustEna_Logl(boolean data)
{
  return Rte_Write_FricLrngCustEna_Logl(data);
}

Std_ReturnType TSC_BmwSwFctDi_Rte_Write_HaptcFbEna_Logl(boolean data)
{
  return Rte_Write_HaptcFbEna_Logl(data);
}

Std_ReturnType TSC_BmwSwFctDi_Rte_Write_HwTqCmdHysBmwOvrd_Val(float32 data)
{
  return Rte_Write_HwTqCmdHysBmwOvrd_Val(data);
}

Std_ReturnType TSC_BmwSwFctDi_Rte_Write_HwTqOvrlCmdEna_Logl(boolean data)
{
  return Rte_Write_HwTqOvrlCmdEna_Logl(data);
}

Std_ReturnType TSC_BmwSwFctDi_Rte_Write_InertiaCmpVelCmdDiBmwOvrd_Logl(boolean data)
{
  return Rte_Write_InertiaCmpVelCmdDiBmwOvrd_Logl(data);
}

Std_ReturnType TSC_BmwSwFctDi_Rte_Write_MaxCurrAtHiSpd_Val(float32 data)
{
  return Rte_Write_MaxCurrAtHiSpd_Val(data);
}

Std_ReturnType TSC_BmwSwFctDi_Rte_Write_MaxCurrAtLoSpd_Val(float32 data)
{
  return Rte_Write_MaxCurrAtLoSpd_Val(data);
}

Std_ReturnType TSC_BmwSwFctDi_Rte_Write_PullCmpCmdDiBmwOvrd_Logl(boolean data)
{
  return Rte_Write_PullCmpCmdDiBmwOvrd_Logl(data);
}

Std_ReturnType TSC_BmwSwFctDi_Rte_Write_TrfcJamAssiCmdEna_Logl(boolean data)
{
  return Rte_Write_TrfcJamAssiCmdEna_Logl(data);
}

Std_ReturnType TSC_BmwSwFctDi_Rte_Write_TunSetHndlrEna_Logl(boolean data)
{
  return Rte_Write_TunSetHndlrEna_Logl(data);
}





     /* Client Server Interfaces: */
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetCurrentLimit(uint8 *Value)
{
  return Rte_Call_Data_GetCurrentLimit(Value);
}
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME00_00_CalculationOfLoadMinusstateMinusdependentSteeringAssistance(boolean *Value)
{
  return Rte_Call_Data_GetNAME00_00_CalculationOfLoadMinusstateMinusdependentSteeringAssistance(Value);
}
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME00_01_CalculationOfActiveReturn(boolean *Value)
{
  return Rte_Call_Data_GetNAME00_01_CalculationOfActiveReturn(Value);
}
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME00_02_reserved(boolean *Value)
{
  return Rte_Call_Data_GetNAME00_02_reserved(Value);
}
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME00_03_ActiveInfluenceOnTheSteeringHysterisis(boolean *Value)
{
  return Rte_Call_Data_GetNAME00_03_ActiveInfluenceOnTheSteeringHysterisis(Value);
}
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME01_03_ParkingPowerDamping(boolean *Value)
{
  return Rte_Call_Data_GetNAME01_03_ParkingPowerDamping(Value);
}
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME02_00_CompensationOfFriction(boolean *Value)
{
  return Rte_Call_Data_GetNAME02_00_CompensationOfFriction(Value);
}
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME02_01_CompensationOfConstantSteeringPullAndLateralInclinationPull(boolean *Value)
{
  return Rte_Call_Data_GetNAME02_01_CompensationOfConstantSteeringPullAndLateralInclinationPull(Value);
}
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME02_02(boolean *Value)
{
  return Rte_Call_Data_GetNAME02_02(Value);
}
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME02_03(boolean *Value)
{
  return Rte_Call_Data_GetNAME02_03(Value);
}
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME02_04_CompensationOfInertiaOfTheSteeringGear(boolean *Value)
{
  return Rte_Call_Data_GetNAME02_04_CompensationOfInertiaOfTheSteeringGear(Value);
}
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME02_05_CompensationOfInertiaOfTheSteeringWheel(boolean *Value)
{
  return Rte_Call_Data_GetNAME02_05_CompensationOfInertiaOfTheSteeringWheel(Value);
}
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME02_06(boolean *Value)
{
  return Rte_Call_Data_GetNAME02_06(Value);
}
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME02_07(boolean *Value)
{
  return Rte_Call_Data_GetNAME02_07(Value);
}
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME03_01_VoltageDependantDegredation(boolean *Value)
{
  return Rte_Call_Data_GetNAME03_01_VoltageDependantDegredation(Value);
}
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME03_02_SpeedDependantDegredation(boolean *Value)
{
  return Rte_Call_Data_GetNAME03_02_SpeedDependantDegredation(Value);
}
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME04_00_DrivingDynamicsInterfaceMinusDriversTorque(boolean *Value)
{
  return Rte_Call_Data_GetNAME04_00_DrivingDynamicsInterfaceMinusDriversTorque(Value);
}
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME04_00_DrivingDynamicsInterfaceMinusMotorTorque(boolean *Value)
{
  return Rte_Call_Data_GetNAME04_00_DrivingDynamicsInterfaceMinusMotorTorque(Value);
}
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME04_02_DrivingDynamicsInterfaceMinusFactors(boolean *Value)
{
  return Rte_Call_Data_GetNAME04_02_DrivingDynamicsInterfaceMinusFactors(Value);
}
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME04_03_DrivingDynamicsInterfaceMinusAdditionalDamping(boolean *Value)
{
  return Rte_Call_Data_GetNAME04_03_DrivingDynamicsInterfaceMinusAdditionalDamping(Value);
}
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME04_04_EPSVibration(boolean *Value)
{
  return Rte_Call_Data_GetNAME04_04_EPSVibration(Value);
}
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME04_05_DrivingExperienceSwitch(boolean *Value)
{
  return Rte_Call_Data_GetNAME04_05_DrivingExperienceSwitch(Value);
}
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME04_06_reserved(boolean *Value)
{
  return Rte_Call_Data_GetNAME04_06_reserved(Value);
}
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME04_07_automaticEngineStartStopFunction(boolean *Value)
{
  return Rte_Call_Data_GetNAME04_07_automaticEngineStartStopFunction(Value);
}
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME05_00_ActiveFanActuation(boolean *Value)
{
  return Rte_Call_Data_GetNAME05_00_ActiveFanActuation(Value);
}
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetSpeedMinuslimitForMaxCurrent(uint8 *Value)
{
  return Rte_Call_Data_GetSpeedMinuslimitForMaxCurrent(Value);
}


     /* Service calls */


     /* Mode Interfaces */
uint8 TSC_BmwSwFctDi_Rte_Mode_Coding_DataMode_Mode(void)
{
  return Rte_Mode_Coding_DataMode_Mode();
}




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */
Std_ReturnType TSC_BmwSwFctDi_Rte_Call_Data_GetNAME03_00_reserved(boolean *Value)
{
  return Rte_Call_Data_GetNAME03_00_reserved(Value);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */





uint8  TSC_BmwSwFctDi_Rte_Prm_BmwSwFctDiBmwActvRtnOvrd_Val(void)
{
  return (uint8 ) Rte_Prm_BmwSwFctDiBmwActvRtnOvrd_Val();
}
uint8  TSC_BmwSwFctDi_Rte_Prm_BmwSwFctDiBmwEngStrtStopOvrd_Val(void)
{
  return (uint8 ) Rte_Prm_BmwSwFctDiBmwEngStrtStopOvrd_Val();
}
uint8  TSC_BmwSwFctDi_Rte_Prm_BmwSwFctDiBmwEpsOscnOvrd_Val(void)
{
  return (uint8 ) Rte_Prm_BmwSwFctDiBmwEpsOscnOvrd_Val();
}
uint8  TSC_BmwSwFctDi_Rte_Prm_BmwSwFctDiBmwFricCmpOvrd_Val(void)
{
  return (uint8 ) Rte_Prm_BmwSwFctDiBmwFricCmpOvrd_Val();
}
uint8  TSC_BmwSwFctDi_Rte_Prm_BmwSwFctDiBmwGearInertiaCmpOvrd_Val(void)
{
  return (uint8 ) Rte_Prm_BmwSwFctDiBmwGearInertiaCmpOvrd_Val();
}
uint8  TSC_BmwSwFctDi_Rte_Prm_BmwSwFctDiBmwHwInertiaCmpOvrd_Val(void)
{
  return (uint8 ) Rte_Prm_BmwSwFctDiBmwHwInertiaCmpOvrd_Val();
}
uint8  TSC_BmwSwFctDi_Rte_Prm_BmwSwFctDiBmwHysActvInflOvrd_Val(void)
{
  return (uint8 ) Rte_Prm_BmwSwFctDiBmwHysActvInflOvrd_Val();
}
uint8  TSC_BmwSwFctDi_Rte_Prm_BmwSwFctDiBmwIfNegDampgOvrd_Val(void)
{
  return (uint8 ) Rte_Prm_BmwSwFctDiBmwIfNegDampgOvrd_Val();
}
uint8  TSC_BmwSwFctDi_Rte_Prm_BmwSwFctDiBmwIfNegFacOvrd_Val(void)
{
  return (uint8 ) Rte_Prm_BmwSwFctDiBmwIfNegFacOvrd_Val();
}
uint8  TSC_BmwSwFctDi_Rte_Prm_BmwSwFctDiBmwIfNegHwTqOvrd_Val(void)
{
  return (uint8 ) Rte_Prm_BmwSwFctDiBmwIfNegHwTqOvrd_Val();
}
uint8  TSC_BmwSwFctDi_Rte_Prm_BmwSwFctDiBmwIfNegMotTqOvrd_Val(void)
{
  return (uint8 ) Rte_Prm_BmwSwFctDiBmwIfNegMotTqOvrd_Val();
}
uint8  TSC_BmwSwFctDi_Rte_Prm_BmwSwFctDiBmwLrnSwtOvrd_Val(void)
{
  return (uint8 ) Rte_Prm_BmwSwFctDiBmwLrnSwtOvrd_Val();
}
uint8  TSC_BmwSwFctDi_Rte_Prm_BmwSwFctDiBmwPrkgPwrDampgOvrd_Val(void)
{
  return (uint8 ) Rte_Prm_BmwSwFctDiBmwPrkgPwrDampgOvrd_Val();
}
uint8  TSC_BmwSwFctDi_Rte_Prm_BmwSwFctDiBmwPullCmpOvrd_Val(void)
{
  return (uint8 ) Rte_Prm_BmwSwFctDiBmwPullCmpOvrd_Val();
}
uint8  TSC_BmwSwFctDi_Rte_Prm_BmwSwFctDiCodingOvrd_Val(void)
{
  return (uint8 ) Rte_Prm_BmwSwFctDiCodingOvrd_Val();
}
uint8  TSC_BmwSwFctDi_Rte_Prm_BmwSwFctDiMaxCurrAtHiSpdOvrd_Val(void)
{
  return (uint8 ) Rte_Prm_BmwSwFctDiMaxCurrAtHiSpdOvrd_Val();
}
uint8  TSC_BmwSwFctDi_Rte_Prm_BmwSwFctDiMaxCurrAtLoSpdOvrd_Val(void)
{
  return (uint8 ) Rte_Prm_BmwSwFctDiMaxCurrAtLoSpdOvrd_Val();
}


     /* BmwSwFctDi */
      /* BmwSwFctDi */

/** Per Instance Memories */
uint8 *TSC_BmwSwFctDi_Rte_Pim_BmwActvRtn(void)
{
  return Rte_Pim_BmwActvRtn();
}
uint8 *TSC_BmwSwFctDi_Rte_Pim_BmwEngStrtStop(void)
{
  return Rte_Pim_BmwEngStrtStop();
}
uint8 *TSC_BmwSwFctDi_Rte_Pim_BmwEpsOscn(void)
{
  return Rte_Pim_BmwEpsOscn();
}
uint8 *TSC_BmwSwFctDi_Rte_Pim_BmwFricCmp(void)
{
  return Rte_Pim_BmwFricCmp();
}
uint8 *TSC_BmwSwFctDi_Rte_Pim_BmwGearInertiaCmp(void)
{
  return Rte_Pim_BmwGearInertiaCmp();
}
uint8 *TSC_BmwSwFctDi_Rte_Pim_BmwHwInertiaCmp(void)
{
  return Rte_Pim_BmwHwInertiaCmp();
}
uint8 *TSC_BmwSwFctDi_Rte_Pim_BmwHysActvInfl(void)
{
  return Rte_Pim_BmwHysActvInfl();
}
uint8 *TSC_BmwSwFctDi_Rte_Pim_BmwIfNegDampg(void)
{
  return Rte_Pim_BmwIfNegDampg();
}
uint8 *TSC_BmwSwFctDi_Rte_Pim_BmwIfNegFac(void)
{
  return Rte_Pim_BmwIfNegFac();
}
uint8 *TSC_BmwSwFctDi_Rte_Pim_BmwIfNegHwTq(void)
{
  return Rte_Pim_BmwIfNegHwTq();
}
uint8 *TSC_BmwSwFctDi_Rte_Pim_BmwIfNegMotTq(void)
{
  return Rte_Pim_BmwIfNegMotTq();
}
uint8 *TSC_BmwSwFctDi_Rte_Pim_BmwLrnSwt(void)
{
  return Rte_Pim_BmwLrnSwt();
}
uint8 *TSC_BmwSwFctDi_Rte_Pim_BmwPrkgPwrDampg(void)
{
  return Rte_Pim_BmwPrkgPwrDampg();
}
uint8 *TSC_BmwSwFctDi_Rte_Pim_BmwPullCmp(void)
{
  return Rte_Pim_BmwPullCmp();
}
uint8 *TSC_BmwSwFctDi_Rte_Pim_PrevCodingDataMode(void)
{
  return Rte_Pim_PrevCodingDataMode();
}



