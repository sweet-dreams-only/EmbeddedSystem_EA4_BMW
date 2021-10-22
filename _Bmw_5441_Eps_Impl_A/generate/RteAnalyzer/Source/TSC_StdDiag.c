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
 *          File:  TSC_StdDiag.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_StdDiag.h"
#include "TSC_StdDiag.h"















     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */
Stm_VehicleStateType TSC_StdDiag_Rte_Mode_VehicleStatePort_currentVehicleStateMode(void)
{
  return Rte_Mode_VehicleStatePort_currentVehicleStateMode();
}




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */
Std_ReturnType TSC_StdDiag_Rte_Call_UserActiveSessionStatePort_GetActiveSessionState(Dcm_SesCtrlType activeSession, uint8 *activeSessionState)
{
  return Rte_Call_UserActiveSessionStatePort_GetActiveSessionState(activeSession, activeSessionState);
}


     /* Service calls */
Std_ReturnType TSC_StdDiag_Rte_Call_DCMServicesPort_GetSesCtrlType(Dcm_SesCtrlType *SesCtrlType)
{
  return Rte_Call_DCMServicesPort_GetSesCtrlType(SesCtrlType);
}


     /* Mode Interfaces */




     /* Inter-Runnable variables */






StdDiag_LifeCycleRequestType TSC_StdDiag_Rte_IRead_LifeCycleHandler_LifeCycleRequest_requestMode(void)
{
  return Rte_IRead_LifeCycleHandler_LifeCycleRequest_requestMode();
}



Std_ReturnType TSC_StdDiag_Rte_Write_ComControlModeRequestPort_requestedMode(NormalCommunicationModeType data)
{
  return Rte_Write_ComControlModeRequestPort_requestedMode(data);
}





     /* Client Server Interfaces: */
Std_ReturnType TSC_StdDiag_Rte_Call_RoeStatePort_GetRoeState(Darh_RoeStateType *RoeState)
{
  return Rte_Call_RoeStatePort_GetRoeState(RoeState);
}


     /* Service calls */
Std_ReturnType TSC_StdDiag_Rte_Call_EnableConditionPort_SetEnableCondition(boolean ConditionFulfilled)
{
  return Rte_Call_EnableConditionPort_SetEnableCondition(ConditionFulfilled);
}


     /* Mode Interfaces */
Omc_ExtendedOperatingModeType TSC_StdDiag_Rte_Mode_ExtendedOperatingModeControlPort_currentExtendedOperatingMode(void)
{
  return Rte_Mode_ExtendedOperatingModeControlPort_currentExtendedOperatingMode();
}
StdDiag_LifeCycleRequestType TSC_StdDiag_Rte_Mode_LifeCycle_Mode(StdDiag_LifeCycleRequestType *previousMode, StdDiag_LifeCycleRequestType *nextMode)
{
  return Rte_Mode_LifeCycle_Mode( previousMode, nextMode);
}
Omc_OperatingModeType TSC_StdDiag_Rte_Mode_OperatingModeControlPort_currentOperatingMode(void)
{
  return Rte_Mode_OperatingModeControlPort_currentOperatingMode();
}

Std_ReturnType TSC_StdDiag_Rte_Switch_LifeCycle_Mode(StdDiag_LifeCycleRequestType mode)
{
  return Rte_Switch_LifeCycle_Mode( mode);
}



     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */
NormalCommunicationModeType TSC_StdDiag_Rte_Mode_ComControlNormalModeAccessPort_CommunicationModeDeclarationGroup(void)
{
  return Rte_Mode_ComControlNormalModeAccessPort_CommunicationModeDeclarationGroup();
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













     /* Client Server Interfaces: */


     /* Service calls */
Std_ReturnType TSC_StdDiag_Rte_Call_ClearDTCPort_ClearDTC(uint32 DTC, Dem_DTCFormatType DTCFormat, Dem_DTCOriginType DTCOrigin)
{
  return Rte_Call_ClearDTCPort_ClearDTC(DTC, DTCFormat, DTCOrigin);
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







     /* StdDiag */
      /* StdDiag */



