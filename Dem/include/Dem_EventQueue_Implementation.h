/* ********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2017 by Vctr Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 */
/*! \addtogroup Dem_EventQueue
 *  \{
 *  \file       Dem_EventQueue_Implementation.h
 *  \brief      Diagnostic Event Manager (Dem) header file
 *  \details    Implementation of EventQueue subcomponent
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Savas Ates                    vissat        Vctr Informatik GmbH
 *  Anna Bosch                    visanh        Vctr Informatik GmbH
 *  Stefan Huebner                vishrs        Vctr Informatik GmbH
 *  Thomas Dedler                 visdth        Vctr Informatik GmbH
 *  Alexander Ditte               visade        Vctr Informatik GmbH
 *  Matthias Heil                 vismhe        Vctr Informatik GmbH
 *  Erik Jeglorz                  visejz        Vctr Informatik GmbH
 *  Friederike Schulze            visfrs        Vctr Informatik GmbH
 *  Aswin Vijayamohanan Nair      visavi        Vctr Informatik GmbH
 *  Fabian Wild                   viszfa        Vctr Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  REFER TO DEM.H
 *********************************************************************************************************************/

#if !defined (DEM_EVENTQUEUE_IMPLEMENTATION_H)
#define DEM_EVENTQUEUE_IMPLEMENTATION_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                  /* Own subcomponent header */
/* ------------------------------------------------------------------------- */
#include "Dem_EventQueue_Interface.h"

                                                    /* Used subcomponent API */
/* ------------------------------------------------------------------------- */
#include "Dem_Cfg_Definitions.h"
#include "Dem_Scheduler_Implementation.h"
#include "Dem_Event_Implementation.h"
#include "Dem_UDSStatus_Implementation.h"
#include "Dem_SatelliteData_Implementation.h"
#include "Dem_DTC_Implementation.h"
#include "Dem_Prestore_Implementation.h"

                                                   /* Subcomponents callbacks*/
/* ------------------------------------------------------------------------- */
#include "Dem_Satellite_Interface.h"
#include "Dem_Error_Interface.h"

/* ********************************************************************************************************************
 *  SUBCOMPONENT CONSTANT MACROS
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  SUBCOMPONENT FUNCTION MACROS
 *********************************************************************************************************************/
#define DEM_EVENTQUEUE_ACTION                         0x0fU
#define DEM_EVENTQUEUE_ACTION_MASK                    0xf0U

#define DEM_EVENTQUEUE_FDC_TRIP                       0x10U
#define DEM_EVENTQUEUE_FDC_TRIP_MASK                  0xefU

#define DEM_EVENTQUEUE_FDC_MAX_SLC                    0x20U
#define DEM_EVENTQUEUE_FDC_MAX_SLC_MASK               0xdfU

#define DEM_EVENTQUEUE_FDC_PROCESSING                 0x40U
#define DEM_EVENTQUEUE_FDC_PROCESSING_MASK            0xafU

#define DEM_EVENTQUEUE_RESET_TESTFAILED               0x80U
#define DEM_EVENTQUEUE_RESET_TESTFAILED_MASK          0x7fU

/* ********************************************************************************************************************
 *  SUBCOMPONENT DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  SUBCOMPONENT DATA
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  SUBCOMPONENT OBJECT FUNCTION DEFINITIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \addtogroup Dem_EventQueue_Properties
 * \{
 */

/* ****************************************************************************
 % Dem_EventQueue_ResetQueueStatus
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_SatelliteData_DataType, DEM_CODE)
Dem_EventQueue_ResetQueueStatus(
  CONST(Dem_SatelliteData_DataType, AUTOMATIC) SatelliteData
  )
{
  return Dem_SatelliteData_SetQueueStatus(SatelliteData, DEM_EVENTQUEUE_STATE_INITIAL);
}

/* ****************************************************************************
 % Dem_EventQueue_GetQueueStatus
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_EventQueue_StatusType, DEM_CODE)
Dem_EventQueue_GetQueueStatus(
  CONST(Dem_SatelliteData_DataType, AUTOMATIC)  SatelliteData
  )
{
  return Dem_SatelliteData_GetQueueStatus(SatelliteData);
}

/* ****************************************************************************
 % Dem_EventQueue_TestFdcTripStatus
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_EventQueue_TestFdcTripStatus(                                                                                                /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONST(Dem_EventQueue_StatusType, AUTOMATIC)  QueueStatus                                                                       /* PRQA S 3206 */ /* MD_DEM_3206 */
  )
{
  return (boolean)((QueueStatus & DEM_EVENTQUEUE_FDC_TRIP) != 0);
}

/* ****************************************************************************
 % Dem_EventQueue_SetFdcTripStatus
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_EventQueue_StatusType, DEM_CODE)
Dem_EventQueue_SetFdcTripStatus(
  CONST(Dem_EventQueue_StatusType, AUTOMATIC)  QueueStatus
  )
{
  return (Dem_EventQueue_StatusType)(QueueStatus | DEM_EVENTQUEUE_FDC_TRIP);
}

/* ****************************************************************************
 % Dem_EventQueue_TestFdcMaxSLCStatus
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_EventQueue_TestFdcMaxSLCStatus(                                                                                              /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONST(Dem_EventQueue_StatusType, AUTOMATIC)  QueueStatus                                                                       /* PRQA S 3206 */ /* MD_DEM_3206 */
  )
{
  return (boolean)((QueueStatus & DEM_EVENTQUEUE_FDC_MAX_SLC) != 0);
}

/* ****************************************************************************
 % Dem_EventQueue_SetFdcMaxSLCStatus
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_EventQueue_StatusType, DEM_CODE)
Dem_EventQueue_SetFdcMaxSLCStatus(
  CONST(Dem_EventQueue_StatusType, AUTOMATIC)  QueueStatus
  )
{
  return (Dem_EventQueue_StatusType)(QueueStatus | DEM_EVENTQUEUE_FDC_MAX_SLC);
}

/* ****************************************************************************
 % Dem_EventQueue_TestFdcProcessingStatus
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_EventQueue_TestFdcProcessingStatus(
  CONST(Dem_EventQueue_StatusType, AUTOMATIC)  QueueStatus                                                                       /* PRQA S 3206 */ /* MD_DEM_3206 */
  )
{
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(QueueStatus)                                                                                  /* PRQA S 3112 */ /* MD_DEM_14.2 */
#if (DEM_FEATURE_NEED_FDC_TRIP == STD_ON)
  return (boolean)((QueueStatus & DEM_EVENTQUEUE_FDC_PROCESSING) != 0);
#else
  return FALSE;
#endif
}

/* ****************************************************************************
 % Dem_EventQueue_SetFdcProcessingStatus
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_EventQueue_StatusType, DEM_CODE)
Dem_EventQueue_SetFdcProcessingStatus(
  CONST(Dem_EventQueue_StatusType, AUTOMATIC)  QueueStatus
  )
{
  return (Dem_EventQueue_StatusType)(QueueStatus | DEM_EVENTQUEUE_FDC_PROCESSING);
}

/* ****************************************************************************
 % Dem_EventQueue_TestResetTestFailedRequested
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_EventQueue_TestResetTestFailedRequested(
  CONST(Dem_EventQueue_StatusType, AUTOMATIC)  QueueStatus                                                                       /* PRQA S 3206 */ /* MD_DEM_3206 */
  )
{
  return (boolean)((QueueStatus & DEM_EVENTQUEUE_RESET_TESTFAILED) != 0);
}

/* ****************************************************************************
 % Dem_EventQueue_SetResetTestFailedRequested
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_EventQueue_StatusType, DEM_CODE)
Dem_EventQueue_SetResetTestFailedRequested(
  CONST(Dem_EventQueue_StatusType, AUTOMATIC)  QueueStatus
  )
{
  return (Dem_EventQueue_StatusType)(QueueStatus | DEM_EVENTQUEUE_RESET_TESTFAILED);
}

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* ********************************************************************************************************************
 *  SUBCOMPONENT PRIVATE FUNCTION DEFINITIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \addtogroup Dem_EventQueue_Private
 * \{
 */

/* ****************************************************************************
 % Dem_EventQueue_GetQueueAction
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_EventQueue_GetQueueAction(
  CONST(Dem_EventQueue_StatusType, AUTOMATIC) QueueStatus
  )
{
  return (uint8)(QueueStatus & DEM_EVENTQUEUE_ACTION);
}

/* ****************************************************************************
 % Dem_EventQueue_SetQueueAction
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_EventQueue_StatusType, DEM_CODE)
Dem_EventQueue_SetQueueAction(
  CONST(Dem_EventQueue_StatusType, AUTOMATIC) QueueStatus,
  CONST(uint8, AUTOMATIC) Action
  )
{
  return (uint8)(
       (QueueStatus & DEM_EVENTQUEUE_ACTION_MASK)
     | (Action & DEM_EVENTQUEUE_ACTION) );
}

/* ****************************************************************************
 % Dem_EventQueueCore_ProcessQueuedEventActions
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_EventQueueCore_ProcessQueuedEventActions(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(Dem_EventQueue_StatusType, AUTOMATIC)  QueueStatus
  )
{
  if (Dem_EventQueue_TestResetTestFailedRequested(QueueStatus) == TRUE)
  {
    Dem_Event_ResetTestFailed(EventId);
  }
#if (DEM_FEATURE_NEED_OEM_EXTENSIONS_VCC == STD_ON)
  if (Dem_EventQueue_TestFdcProcessingStatus(QueueStatus) == TRUE)
  {
    uint8 lTestCompleted;
    /* First completed test this cycle */
    lTestCompleted = (uint8)( (Dem_EventQueue_GetQueueAction(QueueStatus) != 0)                                                  /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
                           && (Dem_UDSStatus_Test_TNCTOC(Dem_Event_GetUDSStatus(EventId)) == TRUE) );

    Dem_DTC_FdcTrip_Vcc(EventId, lTestCompleted);
  }
#else
  if (Dem_EventQueue_TestFdcProcessingStatus(QueueStatus) == TRUE)
  {
    Dem_Event_ProcessFdc(EventId,
      (boolean)Dem_EventQueue_TestFdcTripStatus(QueueStatus) == TRUE,
      (boolean)Dem_EventQueue_TestFdcMaxSLCStatus(QueueStatus) == TRUE);
  }
#endif

  switch (Dem_EventQueue_GetQueueAction(QueueStatus))
  {
  case 1:
    Dem_Event_Passed(EventId);
    break;
  case 2:
    Dem_Event_Passed(EventId);
    Dem_Event_Failed(EventId);
    break;
  case 3:
    Dem_Event_Passed(EventId);
    Dem_Event_Failed(EventId);
    Dem_Event_Passed(EventId);
    break;

  case 5:
    Dem_Event_Failed(EventId);
    break;
  case 6:
    Dem_Event_Failed(EventId);
    Dem_Event_Passed(EventId);
    break;
  case 7:
    Dem_Event_Failed(EventId);
    Dem_Event_Passed(EventId);
    Dem_Event_Failed(EventId);
    break;

  default:
    /* No action */
    break;
  }
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */

/* ****************************************************************************
 % Dem_EventQueue_ProcessEventQueuedEventActions
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_EventQueue_ProcessEventQueuedEventActions(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(Dem_EventQueue_StatusType, AUTOMATIC)  QueueStatus
  )
{
#if (DEM_CFG_SUPPORT_PRESTORED_FF == STD_ON)
  Dem_Prestore_EventPrestorageLock(EventId);
#endif

  Dem_EventQueueCore_ProcessQueuedEventActions(EventId, QueueStatus);

#if (DEM_CFG_SUPPORT_PRESTORED_FF == STD_ON)
  Dem_Prestore_EventPrestorageRelease();
#endif
}

/* ****************************************************************************
 % Dem_EventQueue_ProcessSatelliteQueuedEventActions
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_EventQueue_ProcessSatelliteQueuedEventActions(
  CONST(Dem_Satellite_IdType, AUTOMATIC) SatelliteId
  )
{
  Dem_Satellite_MonitorIdType lMonitorId;

  for (lMonitorId = 0;
       lMonitorId < Dem_Cfg_GetEventCountOfSatelliteInfo(SatelliteId);
       ++lMonitorId)
  {
    if (Dem_Satellite_PeekQueueStatus(SatelliteId, lMonitorId) != DEM_EVENTQUEUE_STATE_INITIAL)
    {
      Dem_EventIdType lEventId;
      uint8 lQueueStatus;

      lEventId = Dem_Satellite_GetEventId(SatelliteId, lMonitorId);
      lQueueStatus = Dem_SatelliteCore_ConsumeQueueStatus(SatelliteId, lMonitorId);
      Dem_EventQueue_ProcessEventQueuedEventActions(lEventId, lQueueStatus);
    }
  }
}

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* ********************************************************************************************************************
 *  SUBCOMPONENT API FUNCTION DEFINITIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \addtogroup Dem_EventQueue_Public
 * \{
 */

/* ****************************************************************************
 % Dem_EventQueue_TestQueueOverflow
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_EventQueue_TestQueueOverflow(
  CONST(Dem_EventQueue_StatusType, AUTOMATIC)  QueueStatus,
  CONST(Dem_EventStatusType, AUTOMATIC)  MonitorTrigger
  )
{
  Std_ReturnType lReturnValue;
  uint8 lQueueAction;

  lQueueAction = Dem_EventQueue_GetQueueAction(QueueStatus);

  if ( ((MonitorTrigger == DEM_EVENT_STATUS_FAILED) && (lQueueAction == 3))
    || ((MonitorTrigger == DEM_EVENT_STATUS_PASSED) && (lQueueAction == 7)) )
  {
    lReturnValue = TRUE;
  }
  else
  {
    lReturnValue = FALSE;
  }

  return lReturnValue;
}

/* ****************************************************************************
 % Dem_EventQueue_CalculateQueueStatus
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_EventQueue_StatusType, DEM_CODE)
Dem_EventQueue_CalculateQueueStatus(
  CONST(Dem_EventQueue_StatusType, AUTOMATIC)  QueueStatus,
  CONST(Dem_EventStatusType, AUTOMATIC)  MonitorTrigger
  )
{
  Dem_EventQueue_StatusType lReturnValue;

  if (MonitorTrigger == DEM_EVENT_STATUS_FAILED)
  {
    switch (Dem_EventQueue_GetQueueAction(QueueStatus))
    {
    case 0:
      lReturnValue = Dem_EventQueue_SetQueueAction(QueueStatus, 5);
      break;
    case 1:
    case 6:
      lReturnValue = (Dem_EventQueue_StatusType)(QueueStatus + 1);
      break;
    default:
      lReturnValue = QueueStatus;
      break;
    }
  }
  else if (MonitorTrigger == DEM_EVENT_STATUS_PASSED)
  {
    switch (Dem_EventQueue_GetQueueAction(QueueStatus))
    {
    case 0:
      lReturnValue = Dem_EventQueue_SetQueueAction(QueueStatus, 1);
      break;
    case 2:
    case 5:
      lReturnValue = (Dem_EventQueue_StatusType)(QueueStatus + 1);
      break;
    default:
      lReturnValue = QueueStatus;
      break;
    }
  }
  else
  {
    /* Not a qualified result */
    lReturnValue = QueueStatus;
  }

  return lReturnValue;
}

/* ****************************************************************************
 % Dem_EventQueue_GetResult
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_SatelliteData_DataType, DEM_CODE)
Dem_EventQueue_GetResult(
  CONST(Dem_EventQueue_StatusType, AUTOMATIC)  QueueStatus,
  CONST(Dem_SatelliteData_DataType, AUTOMATIC)  SatelliteData
  )
{
  return Dem_SatelliteData_SetQueueStatus(SatelliteData, QueueStatus);
}

/* ****************************************************************************
 % Dem_EventQueueCore_Init
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_EventQueueCore_Init(
  void
  )
{
  Dem_Scheduler_EnableTask(Dem_Scheduler_Task_EventQueue);
}

/* ****************************************************************************
 % Dem_EventQueueCore_MainFunction
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_EventQueueCore_MainFunction(
  void
  )
{
  Dem_Satellite_IdType lSatelliteId;
  for (lSatelliteId = 0; lSatelliteId < Dem_Cfg_GlobalSatelliteCount(); ++lSatelliteId)
  {
    if (Dem_SatelliteCore_TestAndClearQueueUpdated(lSatelliteId) == TRUE)
    {
      Dem_EventQueue_ProcessSatelliteQueuedEventActions(lSatelliteId);
    }
  }
}

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* DEM_EVENTQUEUE_IMPLEMENTATION_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_EventQueue_Implementation.h
 *********************************************************************************************************************/
