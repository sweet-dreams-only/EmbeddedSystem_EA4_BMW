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
 *          File:  TSC_Stm.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_Stm.h"
#include "TSC_Stm.h"















     /* Client Server Interfaces: */


     /* Service calls */
Std_ReturnType TSC_Stm_Rte_Call_CentralErrorLockEnableCondition_SetEnableCondition(boolean ConditionFulfilled)
{
  return Rte_Call_CentralErrorLockEnableCondition_SetEnableCondition(ConditionFulfilled);
}


     /* Mode Interfaces */
Stm_CentralErrorLockType TSC_Stm_Rte_Mode_CentralErrorLockModeSwitchPort_currentCentralErrorLockMode(Stm_CentralErrorLockType *previousMode, Stm_CentralErrorLockType *nextMode)
{
  return Rte_Mode_CentralErrorLockModeSwitchPort_currentCentralErrorLockMode( previousMode, nextMode);
}

Std_ReturnType TSC_Stm_Rte_Switch_CentralErrorLockModeSwitchPort_currentCentralErrorLockMode(Stm_CentralErrorLockType mode)
{
  return Rte_Switch_CentralErrorLockModeSwitchPort_currentCentralErrorLockMode( mode);
}



     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */
Stm_EnergyStateType TSC_Stm_Rte_Mode_EnergyModeSwitchPort_currentEnergyMode(Stm_EnergyStateType *previousMode, Stm_EnergyStateType *nextMode)
{
  return Rte_Mode_EnergyModeSwitchPort_currentEnergyMode( previousMode, nextMode);
}

Std_ReturnType TSC_Stm_Rte_Switch_EnergyModeSwitchPort_currentEnergyMode(Stm_EnergyStateType mode)
{
  return Rte_Switch_EnergyModeSwitchPort_currentEnergyMode( mode);
}



     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_Stm_Rte_Read_CentralErrorLockRx_centralErrorLock(Stm_CentralErrorLockType *data)
{
  return Rte_Read_CentralErrorLockRx_centralErrorLock(data);
}








     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_Stm_Rte_Read_EnergyModeRx_energyState(Stm_EnergyStateType *data)
{
  return Rte_Read_EnergyModeRx_energyState(data);
}








     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */







     /* Stm */
      /* Stm */



