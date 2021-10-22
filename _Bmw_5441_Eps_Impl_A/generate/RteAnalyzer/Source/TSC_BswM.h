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
 *          File:  TSC_BswM.h
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
Std_ReturnType TSC_BswM_Rte_Read_Request_StdDiag_ComControlModeRequest_requestedMode(NormalCommunicationModeType *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_BswM_Rte_Write_Provide_MSRP_Coding_requestMode(Coding_LifeCycleRequestType data);
Std_ReturnType TSC_BswM_Rte_Write_Provide_MSRP_Darh_requestMode(Darh_LifeCycleRequestType data);
Std_ReturnType TSC_BswM_Rte_Write_Provide_MSRP_Dlog_requestMode(Dlog_LifeCycleRequestType data);
Std_ReturnType TSC_BswM_Rte_Write_Provide_MSRP_Omc_requestMode(Omc_LifeCycleRequestType data);
Std_ReturnType TSC_BswM_Rte_Write_Provide_MSRP_StdDiag_requestMode(StdDiag_LifeCycleRequestType data);
Std_ReturnType TSC_BswM_Rte_Write_Provide_MSRP_SysTime_requestMode(SysTime_LifeCycleRequestType data);
Std_ReturnType TSC_BswM_Rte_Write_Provide_MSRP_Vin_requestMode(Vin_LifeCycleRequestType data);

/** Mode switches */
Stm_CentralErrorLockType TSC_BswM_Rte_Mode_Notification_SWCModeSwitch_currentCentralErrorLockMode_currentCentralErrorLockMode(void);
Coding_LifeCycleRequestType TSC_BswM_Rte_Mode_Notification_SwcModeNotification_Coding_LifeCycle_Mode(void);
Darh_LifeCycleRequestType TSC_BswM_Rte_Mode_Notification_SwcModeNotification_Darh_LifeCycle_Mode(void);
Dcm_CommunicationModeType TSC_BswM_Rte_Mode_Notification_SwcModeNotification_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6(void);
Dcm_DiagnosticSessionControlType TSC_BswM_Rte_Mode_Notification_SwcModeNotification_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl(void);
Dcm_EcuResetType TSC_BswM_Rte_Mode_Notification_SwcModeNotification_DcmEcuReset_DcmEcuReset(void);
Dlog_LifeCycleRequestType TSC_BswM_Rte_Mode_Notification_SwcModeNotification_Dlog_LifeCycle_Mode(void);
Omc_LifeCycleRequestType TSC_BswM_Rte_Mode_Notification_SwcModeNotification_Omc_LifeCycle_Mode(void);
StdDiag_LifeCycleRequestType TSC_BswM_Rte_Mode_Notification_SwcModeNotification_StdDiag_LifeCycle_Mode(void);
SysTime_LifeCycleRequestType TSC_BswM_Rte_Mode_Notification_SwcModeNotification_SysTime_LifeCycle_Mode(void);
Vin_LifeCycleRequestType TSC_BswM_Rte_Mode_Notification_SwcModeNotification_Vin_LifeCycle_Mode(void);
Std_ReturnType TSC_BswM_Rte_Switch_Switch_Coding_BusComModeSwitch_Mode(uint8 mode);
Std_ReturnType TSC_BswM_Rte_Switch_Switch_Coding_SwitchCodingMode_currentConditionMode(Coding_ConditionModeType mode);
Std_ReturnType TSC_BswM_Rte_Switch_Switch_ErrorMemoryLockSignalReceptionSwitchPort_currentEMLockSignalReceptionMode(uint8 mode);
Std_ReturnType TSC_BswM_Rte_Switch_Switch_StdDiagComControlNormalNotificationPort_CommunicationModeDeclarationGroup(NormalCommunicationModeType mode);
Std_ReturnType TSC_BswM_Rte_Switch_Switch_StdDiagSessionChangeIndicationPort_SessionModeDeclarationGroup(uint8 mode);
Std_ReturnType TSC_BswM_Rte_Switch_Switch_SwitchPort_Darh_ReportErrorMode_DarhReportErrorMode(uint8 mode);
Std_ReturnType TSC_BswM_Rte_Switch_Switch_VinComSwitchPort_Mode(uint8 mode);




