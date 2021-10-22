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
 *          File:  TSC_Omc.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_Omc.h"
#include "TSC_Omc.h"















     /* Client Server Interfaces: */
Std_ReturnType TSC_Omc_Rte_Call_StdDiag_AllowOpModeSwitch(Omc_OperatingModeType OperatingMode, Omc_ExtendedOperatingModeType ExtendedOperatingMode, Omc_OperatingModeType NewOperatingMode, Omc_ExtendedOperatingModeType NewExtendedOperatingMode)
{
  return Rte_Call_StdDiag_AllowOpModeSwitch(OperatingMode, ExtendedOperatingMode, NewOperatingMode, NewExtendedOperatingMode);
}
Std_ReturnType TSC_Omc_Rte_Call_StdDiag_OpModeSwitchCancelled(Omc_OperatingModeType OperatingMode, Omc_ExtendedOperatingModeType ExtendedOperatingMode, Omc_OperatingModeType RequestedOperatingMode, Omc_ExtendedOperatingModeType RequestedExtendedOperatingMode)
{
  return Rte_Call_StdDiag_OpModeSwitchCancelled(OperatingMode, ExtendedOperatingMode, RequestedOperatingMode, RequestedExtendedOperatingMode);
}


     /* Service calls */
Std_ReturnType TSC_Omc_Rte_Call_NvMServicePort_GetErrorStatus(RequestResultType *RequestResultPtr)
{
  return Rte_Call_NvMServicePort_GetErrorStatus(RequestResultPtr);
}
Std_ReturnType TSC_Omc_Rte_Call_NvMServicePort_WriteBlock(SrcPtrType SrcPtr)
{
  return Rte_Call_NvMServicePort_WriteBlock(SrcPtr);
}


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Omc_LifeCycleRequestType TSC_Omc_Rte_IRead_LifeCycleHandler_LifeCycleRequest_requestMode(void)
{
  return Rte_IRead_LifeCycleHandler_LifeCycleRequest_requestMode();
}







     /* Client Server Interfaces: */


     /* Service calls */
Std_ReturnType TSC_Omc_Rte_Call_EnableCond_OMC_SetEnableCondition(boolean ConditionFulfilled)
{
  return Rte_Call_EnableCond_OMC_SetEnableCondition(ConditionFulfilled);
}
Std_ReturnType TSC_Omc_Rte_Call_VsmEventOpmode_SetEventStatus(Dem_EventStatusType EventStatus)
{
  return Rte_Call_VsmEventOpmode_SetEventStatus(EventStatus);
}


     /* Mode Interfaces */
Omc_LifeCycleRequestType TSC_Omc_Rte_Mode_LifeCycle_Mode(Omc_LifeCycleRequestType *previousMode, Omc_LifeCycleRequestType *nextMode)
{
  return Rte_Mode_LifeCycle_Mode( previousMode, nextMode);
}

Std_ReturnType TSC_Omc_Rte_Switch_LifeCycle_Mode(Omc_LifeCycleRequestType mode)
{
  return Rte_Switch_LifeCycle_Mode( mode);
}
Std_ReturnType TSC_Omc_Rte_Switch_extendedOperatingModeSwitchPort_currentExtendedOperatingMode(Omc_ExtendedOperatingModeType mode)
{
  return Rte_Switch_extendedOperatingModeSwitchPort_currentExtendedOperatingMode( mode);
}
Std_ReturnType TSC_Omc_Rte_Switch_operatingModeSwitchPort_currentOperatingMode(Omc_OperatingModeType mode)
{
  return Rte_Switch_operatingModeSwitchPort_currentOperatingMode( mode);
}



     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */







     /* Omc */
      /* Omc */
void TSC_Omc_Rte_Enter_Mode(void)
{
  Rte_Enter_Mode();
}
void TSC_Omc_Rte_Exit_Mode(void)
{
  Rte_Exit_Mode();
}



