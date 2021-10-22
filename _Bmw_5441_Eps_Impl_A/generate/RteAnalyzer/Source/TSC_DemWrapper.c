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
 *          File:  TSC_DemWrapper.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_DemWrapper.h"
#include "TSC_DemWrapper.h"















     /* Client Server Interfaces: */


     /* Service calls */
Std_ReturnType TSC_DemWrapper_Rte_Call_DemWrapper_EvtInfo_DM_TEST_APPL_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
{
  return Rte_Call_DemWrapper_EvtInfo_DM_TEST_APPL_GetDTCOfEvent(DTCFormat, DTCOfEvent);
}


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */
Std_ReturnType TSC_DemWrapper_Rte_Call_DemWrapper_ClearDTC_SelectDTC(uint32 DTC, Dem_DTCFormatType DTCFormat, Dem_DTCOriginType DTCOrigin)
{
  return Rte_Call_DemWrapper_ClearDTC_SelectDTC(DTC, DTCFormat, DTCOrigin);
}


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */
Std_ReturnType TSC_DemWrapper_Rte_Call_DemWrapper_GeneralDiagnosticInfo_GetDTCOfEvent(Dem_EventIdType EventId, Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
{
  return Rte_Call_DemWrapper_GeneralDiagnosticInfo_GetDTCOfEvent(EventId, DTCFormat, DTCOfEvent);
}


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */
Std_ReturnType TSC_DemWrapper_Rte_Call_DemWrapper_GeneralDiagnosticInfo_GetEventFreezeFrameDataEx(Dem_EventIdType EventId, uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
{
  return Rte_Call_DemWrapper_GeneralDiagnosticInfo_GetEventFreezeFrameDataEx(EventId, RecordNumber, DataId, DestBuffer, BufSize);
}


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */
Std_ReturnType TSC_DemWrapper_Rte_Call_DemWrapper_EvtInfo_DM_TEST_COM_GetDTCOfEvent(Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
{
  return Rte_Call_DemWrapper_EvtInfo_DM_TEST_COM_GetDTCOfEvent(DTCFormat, DTCOfEvent);
}


     /* Mode Interfaces */




     /* Inter-Runnable variables */







     /* DemWrapper */
      /* DemWrapper */



