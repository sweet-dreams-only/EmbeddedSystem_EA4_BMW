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
 *          File:  TSC_Darh.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_Darh.h"
#include "TSC_Darh.h"















     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */
Darh_LifeCycleRequestType TSC_Darh_Rte_Mode_LifeCycle_Mode(Darh_LifeCycleRequestType *previousMode, Darh_LifeCycleRequestType *nextMode)
{
  return Rte_Mode_LifeCycle_Mode( previousMode, nextMode);
}




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */
Std_ReturnType TSC_Darh_Rte_Call_ReportDynamicallyEventPort_EventToReport(Dem_EventIdType event, boolean *toReport)
{
  return Rte_Call_ReportDynamicallyEventPort_EventToReport(event, toReport);
}


     /* Service calls */
Std_ReturnType TSC_Darh_Rte_Call_ErrorQueueBlock_SetRamBlockStatus(boolean BlockChanged)
{
  return Rte_Call_ErrorQueueBlock_SetRamBlockStatus(BlockChanged);
}
Std_ReturnType TSC_Darh_Rte_Call_GeneralDiagnosticInfoPort_GetEventFreezeFrameData(Dem_EventIdType EventId, uint8 RecordNumber, boolean ReportTotalRecord, uint16 DataId, uint8 *DestBuffer)
{
  return Rte_Call_GeneralDiagnosticInfoPort_GetEventFreezeFrameData(EventId, RecordNumber, ReportTotalRecord, DataId, DestBuffer);
}


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Darh_LifeCycleRequestType TSC_Darh_Rte_IRead_LifeCycleHandler_LifeCycleRequest_requestMode(void)
{
  return Rte_IRead_LifeCycleHandler_LifeCycleRequest_requestMode();
}







     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */

Std_ReturnType TSC_Darh_Rte_Switch_LifeCycle_Mode(Darh_LifeCycleRequestType mode)
{
  return Rte_Switch_LifeCycle_Mode( mode);
}



     /* Inter-Runnable variables */









Std_ReturnType TSC_Darh_Rte_Write_Com_data(const Darh_TransmissionArrayType *data)
{
  return Rte_Write_Com_data(data);
}





     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */
Std_ReturnType TSC_Darh_Rte_Call_ReportDynamicallyEventPort_EventIdx2EventId(uint16 eventIdx, Dem_EventIdType *eventId)
{
  return Rte_Call_ReportDynamicallyEventPort_EventIdx2EventId(eventIdx, eventId);
}
Std_ReturnType TSC_Darh_Rte_Call_ReportDynamicallyEventPort_EventToReportCount(uint16 *eventCount)
{
  return Rte_Call_ReportDynamicallyEventPort_EventToReportCount(eventCount);
}


     /* Service calls */
Std_ReturnType TSC_Darh_Rte_Call_GeneralDiagnosticInfoPort_GetDTCOfEvent(Dem_EventIdType EventId, Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
{
  return Rte_Call_GeneralDiagnosticInfoPort_GetDTCOfEvent(EventId, DTCFormat, DTCOfEvent);
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













     /* Client Server Interfaces: */


     /* Service calls */
Std_ReturnType TSC_Darh_Rte_Call_DiagnoseMasterStatus_WriteBlock(NvM_SrcPtrType SrcPtr)
{
  return Rte_Call_DiagnoseMasterStatus_WriteBlock(SrcPtr);
}


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */
Std_ReturnType TSC_Darh_Rte_Call_ApplicationDTCInfoPort_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
{
  return Rte_Call_ApplicationDTCInfoPort_GetDTCOfEvent(DTCFormat, DTCOfEvent);
}
Std_ReturnType TSC_Darh_Rte_Call_DmTestAppl_SetEventStatus(Dem_EventStatusType EventStatus)
{
  return Rte_Call_DmTestAppl_SetEventStatus(EventStatus);
}
Std_ReturnType TSC_Darh_Rte_Call_DmTestCom_SetEventStatus(Dem_EventStatusType EventStatus)
{
  return Rte_Call_DmTestCom_SetEventStatus(EventStatus);
}
Std_ReturnType TSC_Darh_Rte_Call_NetworkDTCInfoPort_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
{
  return Rte_Call_NetworkDTCInfoPort_GetDTCOfEvent(DTCFormat, DTCOfEvent);
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







     /* Darh */
      /* Darh */
void TSC_Darh_Rte_Enter_ExclusiveArea_0(void)
{
  Rte_Enter_ExclusiveArea_0();
}
void TSC_Darh_Rte_Exit_ExclusiveArea_0(void)
{
  Rte_Exit_ExclusiveArea_0();
}



