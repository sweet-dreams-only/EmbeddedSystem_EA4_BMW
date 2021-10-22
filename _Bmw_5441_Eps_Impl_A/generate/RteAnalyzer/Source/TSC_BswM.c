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
 *          File:  TSC_BswM.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_BswM.h"
#include "TSC_BswM.h"











Std_ReturnType TSC_BswM_Rte_Write_Provide_MSRP_Coding_requestMode(Coding_LifeCycleRequestType data)
{
  return Rte_Write_Provide_MSRP_Coding_requestMode(data);
}

Std_ReturnType TSC_BswM_Rte_Write_Provide_MSRP_Darh_requestMode(Darh_LifeCycleRequestType data)
{
  return Rte_Write_Provide_MSRP_Darh_requestMode(data);
}

Std_ReturnType TSC_BswM_Rte_Write_Provide_MSRP_Dlog_requestMode(Dlog_LifeCycleRequestType data)
{
  return Rte_Write_Provide_MSRP_Dlog_requestMode(data);
}

Std_ReturnType TSC_BswM_Rte_Write_Provide_MSRP_Omc_requestMode(Omc_LifeCycleRequestType data)
{
  return Rte_Write_Provide_MSRP_Omc_requestMode(data);
}

Std_ReturnType TSC_BswM_Rte_Write_Provide_MSRP_StdDiag_requestMode(StdDiag_LifeCycleRequestType data)
{
  return Rte_Write_Provide_MSRP_StdDiag_requestMode(data);
}

Std_ReturnType TSC_BswM_Rte_Write_Provide_MSRP_SysTime_requestMode(SysTime_LifeCycleRequestType data)
{
  return Rte_Write_Provide_MSRP_SysTime_requestMode(data);
}

Std_ReturnType TSC_BswM_Rte_Write_Provide_MSRP_Vin_requestMode(Vin_LifeCycleRequestType data)
{
  return Rte_Write_Provide_MSRP_Vin_requestMode(data);
}





     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */
Stm_CentralErrorLockType TSC_BswM_Rte_Mode_Notification_SWCModeSwitch_currentCentralErrorLockMode_currentCentralErrorLockMode(void)
{
  return Rte_Mode_Notification_SWCModeSwitch_currentCentralErrorLockMode_currentCentralErrorLockMode();
}
Coding_LifeCycleRequestType TSC_BswM_Rte_Mode_Notification_SwcModeNotification_Coding_LifeCycle_Mode(void)
{
  return Rte_Mode_Notification_SwcModeNotification_Coding_LifeCycle_Mode();
}
Darh_LifeCycleRequestType TSC_BswM_Rte_Mode_Notification_SwcModeNotification_Darh_LifeCycle_Mode(void)
{
  return Rte_Mode_Notification_SwcModeNotification_Darh_LifeCycle_Mode();
}
Dcm_CommunicationModeType TSC_BswM_Rte_Mode_Notification_SwcModeNotification_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6(void)
{
  return Rte_Mode_Notification_SwcModeNotification_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6();
}
Dcm_DiagnosticSessionControlType TSC_BswM_Rte_Mode_Notification_SwcModeNotification_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl(void)
{
  return Rte_Mode_Notification_SwcModeNotification_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl();
}
Dcm_EcuResetType TSC_BswM_Rte_Mode_Notification_SwcModeNotification_DcmEcuReset_DcmEcuReset(void)
{
  return Rte_Mode_Notification_SwcModeNotification_DcmEcuReset_DcmEcuReset();
}
Dlog_LifeCycleRequestType TSC_BswM_Rte_Mode_Notification_SwcModeNotification_Dlog_LifeCycle_Mode(void)
{
  return Rte_Mode_Notification_SwcModeNotification_Dlog_LifeCycle_Mode();
}
Omc_LifeCycleRequestType TSC_BswM_Rte_Mode_Notification_SwcModeNotification_Omc_LifeCycle_Mode(void)
{
  return Rte_Mode_Notification_SwcModeNotification_Omc_LifeCycle_Mode();
}
StdDiag_LifeCycleRequestType TSC_BswM_Rte_Mode_Notification_SwcModeNotification_StdDiag_LifeCycle_Mode(void)
{
  return Rte_Mode_Notification_SwcModeNotification_StdDiag_LifeCycle_Mode();
}
SysTime_LifeCycleRequestType TSC_BswM_Rte_Mode_Notification_SwcModeNotification_SysTime_LifeCycle_Mode(void)
{
  return Rte_Mode_Notification_SwcModeNotification_SysTime_LifeCycle_Mode();
}
Vin_LifeCycleRequestType TSC_BswM_Rte_Mode_Notification_SwcModeNotification_Vin_LifeCycle_Mode(void)
{
  return Rte_Mode_Notification_SwcModeNotification_Vin_LifeCycle_Mode();
}

Std_ReturnType TSC_BswM_Rte_Switch_Switch_Coding_BusComModeSwitch_Mode(uint8 mode)
{
  return Rte_Switch_Switch_Coding_BusComModeSwitch_Mode( mode);
}
Std_ReturnType TSC_BswM_Rte_Switch_Switch_Coding_SwitchCodingMode_currentConditionMode(Coding_ConditionModeType mode)
{
  return Rte_Switch_Switch_Coding_SwitchCodingMode_currentConditionMode( mode);
}
Std_ReturnType TSC_BswM_Rte_Switch_Switch_ErrorMemoryLockSignalReceptionSwitchPort_currentEMLockSignalReceptionMode(uint8 mode)
{
  return Rte_Switch_Switch_ErrorMemoryLockSignalReceptionSwitchPort_currentEMLockSignalReceptionMode( mode);
}
Std_ReturnType TSC_BswM_Rte_Switch_Switch_StdDiagComControlNormalNotificationPort_CommunicationModeDeclarationGroup(NormalCommunicationModeType mode)
{
  return Rte_Switch_Switch_StdDiagComControlNormalNotificationPort_CommunicationModeDeclarationGroup( mode);
}
Std_ReturnType TSC_BswM_Rte_Switch_Switch_StdDiagSessionChangeIndicationPort_SessionModeDeclarationGroup(uint8 mode)
{
  return Rte_Switch_Switch_StdDiagSessionChangeIndicationPort_SessionModeDeclarationGroup( mode);
}
Std_ReturnType TSC_BswM_Rte_Switch_Switch_SwitchPort_Darh_ReportErrorMode_DarhReportErrorMode(uint8 mode)
{
  return Rte_Switch_Switch_SwitchPort_Darh_ReportErrorMode_DarhReportErrorMode( mode);
}
Std_ReturnType TSC_BswM_Rte_Switch_Switch_VinComSwitchPort_Mode(uint8 mode)
{
  return Rte_Switch_Switch_VinComSwitchPort_Mode( mode);
}



     /* Inter-Runnable variables */






Std_ReturnType TSC_BswM_Rte_Read_Request_StdDiag_ComControlModeRequest_requestedMode(NormalCommunicationModeType *data)
{
  return Rte_Read_Request_StdDiag_ComControlModeRequest_requestedMode(data);
}








     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */







     /* BswM */
      /* BswM */



