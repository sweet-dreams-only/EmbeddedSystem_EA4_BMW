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
 *          File:  TSC_Darh.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Header of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/


/** Sender receiver - explicit write services */
Std_ReturnType TSC_Darh_Rte_Write_Com_data(const Darh_TransmissionArrayType *data);

/** Sender receiver - implicit read services */
Darh_LifeCycleRequestType TSC_Darh_Rte_IRead_LifeCycleHandler_LifeCycleRequest_requestMode(void);

/** Client server interfaces */
Std_ReturnType TSC_Darh_Rte_Call_ReportDynamicallyEventPort_EventToReport(Dem_EventIdType event, boolean *toReport);
Std_ReturnType TSC_Darh_Rte_Call_ReportDynamicallyEventPort_EventIdx2EventId(uint16 eventIdx, Dem_EventIdType *eventId);
Std_ReturnType TSC_Darh_Rte_Call_ReportDynamicallyEventPort_EventToReport(Dem_EventIdType event, boolean *toReport);
Std_ReturnType TSC_Darh_Rte_Call_ReportDynamicallyEventPort_EventToReportCount(uint16 *eventCount);
Std_ReturnType TSC_Darh_Rte_Call_ReportDynamicallyEventPort_EventToReportCount(uint16 *eventCount);

/** Service interfaces */
Std_ReturnType TSC_Darh_Rte_Call_ErrorQueueBlock_SetRamBlockStatus(boolean BlockChanged);
Std_ReturnType TSC_Darh_Rte_Call_GeneralDiagnosticInfoPort_GetEventFreezeFrameData(Dem_EventIdType EventId, uint8 RecordNumber, boolean ReportTotalRecord, uint16 DataId, uint8 *DestBuffer);
Std_ReturnType TSC_Darh_Rte_Call_GeneralDiagnosticInfoPort_GetDTCOfEvent(Dem_EventIdType EventId, Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent);
Std_ReturnType TSC_Darh_Rte_Call_GeneralDiagnosticInfoPort_GetDTCOfEvent(Dem_EventIdType EventId, Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent);
Std_ReturnType TSC_Darh_Rte_Call_DiagnoseMasterStatus_WriteBlock(NvM_SrcPtrType SrcPtr);
Std_ReturnType TSC_Darh_Rte_Call_ApplicationDTCInfoPort_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent);
Std_ReturnType TSC_Darh_Rte_Call_DmTestAppl_SetEventStatus(Dem_EventStatusType EventStatus);
Std_ReturnType TSC_Darh_Rte_Call_DmTestCom_SetEventStatus(Dem_EventStatusType EventStatus);
Std_ReturnType TSC_Darh_Rte_Call_NetworkDTCInfoPort_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent);
Std_ReturnType TSC_Darh_Rte_Call_DiagnoseMasterStatus_WriteBlock(NvM_SrcPtrType SrcPtr);

/** Mode switches */
Darh_LifeCycleRequestType TSC_Darh_Rte_Mode_LifeCycle_Mode(Darh_LifeCycleRequestType *previousMode, Darh_LifeCycleRequestType *nextMode);
Darh_LifeCycleRequestType TSC_Darh_Rte_Mode_LifeCycle_Mode(Darh_LifeCycleRequestType *previousMode, Darh_LifeCycleRequestType *nextMode);
Darh_LifeCycleRequestType TSC_Darh_Rte_Mode_LifeCycle_Mode(Darh_LifeCycleRequestType *previousMode, Darh_LifeCycleRequestType *nextMode);
Std_ReturnType TSC_Darh_Rte_Switch_LifeCycle_Mode(Darh_LifeCycleRequestType mode);

/** Exclusive Areas */
void TSC_Darh_Rte_Enter_ExclusiveArea_0(void);
void TSC_Darh_Rte_Exit_ExclusiveArea_0(void);




