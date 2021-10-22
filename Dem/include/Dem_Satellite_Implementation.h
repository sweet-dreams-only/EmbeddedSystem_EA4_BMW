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
/*!
 *  \addtogroup Dem_Satellite_Interface
 *  \{
 *  \file       Dem_Satellite_Implementation.h
 *  \brief      Implementation file for the MICROSAR Dem
 *  \details    Implementation of Satellite subcomponent
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

#if !defined (DEM_SATELLITE_IMPLEMENTATION_H)
#define DEM_SATELLITE_IMPLEMENTATION_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                  /* Own subcomponent header */
/* ------------------------------------------------------------------------- */
#include "Dem_Satellite_Interface.h"

                                                    /* Used subcomponent API */
/* ------------------------------------------------------------------------- */
#include "Dem_SatelliteInfo_Implementation.h"
#include "Dem_SatelliteData_Implementation.h"
#include "Dem_Monitor_Implementation.h"
#include "Dem_EventQueue_Implementation.h"
#include "Dem_Debounce_Implementation.h"
#include "Dem_Com_Implementation.h"
#include "Dem_EnableCondition_Implementation.h"
#include "Dem_EventInternalStatus_Implementation.h"
#include "Dem_InitState_Implementation.h"
#include "Dem_UDSStatus_Implementation.h"
#include "Dem_Event_Implementation.h"
#include "Dem_OperationCycle_Implementation.h"

                                                   /* Subcomponents callbacks*/
/* ------------------------------------------------------------------------- */
#include "Dem_Error_Interface.h"

/* ********************************************************************************************************************
 *  SUBCOMPONENT CONSTANT MACROS
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  SUBCOMPONENT FUNCTION MACROS
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  SUBCOMPONENT DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  SUBCOMPONENT DATA
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  SUBCOMPONENT OBJECT FUNCTION DEFINITIONS
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  SUBCOMPONENT API FUNCTION DEFINITIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \addtogroup Dem_Satellite_Properties
 * \{
 */

/* ****************************************************************************
 % Dem_Satellite_GetEventId
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_EventIdType, DEM_CODE)
Dem_Satellite_GetEventId(
  CONST(Dem_Satellite_IdType, AUTOMATIC)  SatelliteId,
  CONST(Dem_Satellite_MonitorIdType, AUTOMATIC)  MonitorId
  )
{
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(SatelliteId)                                                                                  /* PRQA S 3112 */ /* MD_DEM_14.2 */
  return Dem_Cfg_GetEventTableInd(Dem_Cfg_GetEventTableIndStartIdxOfSatelliteInfo(SatelliteId) + MonitorId);
}

/* ****************************************************************************
 % Dem_Satellite_GetApplicationId
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_Satellite_ApplicationType, DEM_CODE)
Dem_Satellite_GetApplicationId(                                                                                                  /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONST(Dem_Satellite_IdType, AUTOMATIC)  SatelliteId                                                                            /* PRQA S 3206 */ /* MD_DEM_3206 */
  )
{
  Dem_Satellite_ApplicationType lReturnValue;

  DEM_IGNORE_UNUSED_CONST_ARGUMENT(SatelliteId)                                                                                  /* PRQA S 3112 */ /* MD_DEM_14.2 */
#if (DEM_CFG_SUPPORT_MULTIPLE_SATELLITES == STD_ON)
  lReturnValue = Dem_Cfg_GetApplicationIdOfSatelliteInfo(SatelliteId);
#else
  lReturnValue = DEM_SATELLITE_APPLICATION_ZERO;
#endif

  return lReturnValue;
}

#if (DEM_DEV_ERROR_DETECT == STD_ON)     
/* ****************************************************************************
 % Dem_Satellite_CheckEventApplicationId
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Satellite_CheckEventApplicationId(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId                                                                                     /* PRQA S 3206 */ /* MD_DEM_3206 */
  )
{
  boolean lReturnValue;

  DEM_IGNORE_UNUSED_CONST_ARGUMENT(EventId)                                                                                      /* PRQA S 3112 */ /* MD_DEM_14.2 */

#if (DEM_CFG_SUPPORT_MULTIPLE_SATELLITES == STD_ON)
  lReturnValue = (boolean)(GetCurrentApplicationID() == Dem_Satellite_GetApplicationId(Dem_Cfg_GetSatelliteInfoIdxOfEventTable(EventId)));
#else
  lReturnValue = TRUE;
#endif

  return lReturnValue;
}
#endif

/*!
 * \}
 */

/* ********************************************************************************************************************
 *  SUBCOMPONENT API PRIVATE FUNCTION DEFINITIONS
 *********************************************************************************************************************/

/*!
 * \addtogroup Dem_Satellite_Private
 * \{
 */

/* ****************************************************************************
 % Dem_Satellite_GetSatelliteInfo
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_SatelliteInfo_Type, DEM_CODE)
Dem_Satellite_GetSatelliteInfo(
  CONST(Dem_Satellite_IdType, AUTOMATIC)  SatelliteId
  )
{
  Dem_SatelliteInfo_Type lReturnValue;                                                                                           /* PRQA S 0759 */ /* MD_MSR_18.4 */
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(SatelliteId)                                                                                  /* PRQA S 3112 */ /* MD_DEM_14.2 */
  lReturnValue.Raw = *(Dem_Cfg_GetSatelliteStatusOfSatelliteInfo(SatelliteId));
  return lReturnValue;
}

/* ****************************************************************************
 % Dem_SatelliteSat_SetSatelliteInfo
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_SatelliteSat_SetSatelliteInfo(
  CONST(Dem_Satellite_IdType, AUTOMATIC)  SatelliteId,
  CONST(Dem_SatelliteInfo_Type, AUTOMATIC)  NewSatelliteInfo
  )
{
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(SatelliteId)                                                                                  /* PRQA S 3112 */ /* MD_DEM_14.2 */
#if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (SatelliteId >= Dem_Cfg_GlobalSatelliteCount())
  {
    Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
  }
  else
#endif
  {
    *Dem_Cfg_GetSatelliteStatusOfSatelliteInfo(SatelliteId) = NewSatelliteInfo.Raw;
  }
}

/* ****************************************************************************
 % Dem_SatelliteSat_SyncSetSatelliteInfo
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_SatelliteSat_SyncSetSatelliteInfo(
  CONST(Dem_Satellite_IdType, AUTOMATIC)  SatelliteId,
  CONST(Dem_SatelliteInfo_Type, AUTOMATIC) OldSatelliteInfo,
  CONST(Dem_SatelliteInfo_Type, AUTOMATIC) NewSatelliteInfo
  )
{
  boolean lReturnValue;
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(SatelliteId)                                                                                  /* PRQA S 3112 */ /* MD_DEM_14.2 */
#if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (SatelliteId >= Dem_Cfg_GlobalSatelliteCount())
  {
    Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
    lReturnValue = TRUE;
  }
  else
#endif
  {
    lReturnValue = Dem_Com_SyncCompareAndSwap(
        Dem_Cfg_GetSatelliteStatusOfSatelliteInfo(SatelliteId),
        OldSatelliteInfo.Raw,
        NewSatelliteInfo.Raw);
  }
  return lReturnValue;
}

/* ****************************************************************************
 % Dem_SatelliteCore_SyncSetSatelliteInfo
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_SatelliteCore_SyncSetSatelliteInfo(
  CONST(Dem_Satellite_IdType, AUTOMATIC)  SatelliteId,
  CONST(Dem_SatelliteInfo_Type, AUTOMATIC) OldSatelliteInfo,
  CONST(Dem_SatelliteInfo_Type, AUTOMATIC) NewSatelliteInfo
  )
{
  return Dem_SatelliteSat_SyncSetSatelliteInfo(SatelliteId, OldSatelliteInfo, NewSatelliteInfo);
}

/* ****************************************************************************
 % Dem_Satellite_GetSatelliteData
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_SatelliteData_DataType, DEM_CODE)
Dem_Satellite_GetSatelliteData(
  CONST(Dem_Satellite_IdType, AUTOMATIC)  SatelliteId,
  CONST(Dem_Satellite_MonitorIdType, AUTOMATIC)  MonitorId
  )
{
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(SatelliteId)                                                                                  /* PRQA S 3112 */ /* MD_DEM_14.2 */
  return (Dem_Cfg_GetSatelliteDataOfSatelliteInfo(SatelliteId))[MonitorId];
}

/* ****************************************************************************
 % Dem_SatelliteSat_SetSatelliteData
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_SatelliteSat_SetSatelliteData(
  CONST(Dem_Satellite_IdType, AUTOMATIC)  SatelliteId,
  CONST(Dem_Satellite_MonitorIdType, AUTOMATIC)  MonitorId,
  CONST(Dem_SatelliteData_DataType, AUTOMATIC)  NewSatelliteData
  )
{
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(SatelliteId)                                                                                  /* PRQA S 3112 */ /* MD_DEM_14.2 */
#if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if ( (SatelliteId >= Dem_Cfg_GlobalSatelliteCount())                                                                           /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
    || (MonitorId >= (Dem_Cfg_GetEventCountOfSatelliteInfo(SatelliteId))) )
  {
    Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
  }
  else
#endif
  {
    (Dem_Cfg_GetSatelliteDataOfSatelliteInfo(SatelliteId))[MonitorId] = NewSatelliteData;
  }
}

/* ****************************************************************************
 % Dem_SatelliteSat_SyncSetSatelliteData
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_SatelliteSat_SyncSetSatelliteData(
  CONST(Dem_Satellite_IdType, AUTOMATIC)  SatelliteId,
  CONST(Dem_Satellite_MonitorIdType, AUTOMATIC)  MonitorId,
  CONST(Dem_SatelliteData_DataType, AUTOMATIC)  OldSatelliteData,
  CONST(Dem_SatelliteData_DataType, AUTOMATIC)  NewSatelliteData
  )
{
  boolean lReturnValue;

  DEM_IGNORE_UNUSED_CONST_ARGUMENT(SatelliteId)                                                                                  /* PRQA S 3112 */ /* MD_DEM_14.2 */
#if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if ( (SatelliteId >= Dem_Cfg_GlobalSatelliteCount())                                                                           /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
    || (MonitorId >= (Dem_Cfg_GetEventCountOfSatelliteInfo(SatelliteId))) )
  {
    Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
    lReturnValue = TRUE;
  }
  else
#endif
  {
    /* Swap the new data into the buffer if the buffer's value is identical to the old data.
     * Return whether operation succeeded. */
    lReturnValue = Dem_Com_SyncCompareAndSwap(&((Dem_Cfg_GetSatelliteDataOfSatelliteInfo(SatelliteId))[MonitorId].Raw), OldSatelliteData.Raw, NewSatelliteData.Raw);
  }
  return lReturnValue;
}

/* ****************************************************************************
 % Dem_SatelliteCore_SyncSetSatelliteData
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_SatelliteCore_SyncSetSatelliteData(
  CONST(Dem_Satellite_IdType, AUTOMATIC)  SatelliteId,
  CONST(Dem_Satellite_MonitorIdType, AUTOMATIC)  MonitorId,
  CONST(Dem_SatelliteData_DataType, AUTOMATIC)  OldSatelliteData,
  CONST(Dem_SatelliteData_DataType, AUTOMATIC)  NewSatelliteData
  )
{
  /* Behavior is identical for core and satellite --> use satellite method. */
  return Dem_SatelliteSat_SyncSetSatelliteData(SatelliteId, MonitorId, OldSatelliteData, NewSatelliteData);
}

/* ****************************************************************************
 % Dem_SatelliteSat_SetQueueUpdated
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
DEM_LOCAL FUNC(void, DEM_CODE)
Dem_SatelliteSat_SetQueueUpdated(
  CONST(Dem_Satellite_IdType, AUTOMATIC)  SatelliteId
  )
{
  Dem_SatelliteInfo_Type lOldSatelliteInfo;                                                                                      /* PRQA S 0759 */ /* MD_MSR_18.4 */
  Dem_SatelliteInfo_Type lNewSatelliteInfo;                                                                                      /* PRQA S 0759 */ /* MD_MSR_18.4 */
  do
  {
    lOldSatelliteInfo = Dem_Satellite_GetSatelliteInfo(SatelliteId);
    lNewSatelliteInfo = Dem_SatelliteInfo_SetQueueUpdated(lOldSatelliteInfo, TRUE);
  }
  while (Dem_SatelliteSat_SyncSetSatelliteInfo(SatelliteId, lOldSatelliteInfo, lNewSatelliteInfo) == FALSE);
}

/* ****************************************************************************
 % Dem_Satellite_UpdateSatelliteData
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
 */
DEM_LOCAL_INLINE FUNC(Dem_SatelliteData_DataType, DEM_CODE)
Dem_Satellite_UpdateSatelliteData(
  CONST(Dem_SatelliteData_DataType, AUTOMATIC)  OldSatelliteData,
  CONST(Dem_DebounceBase_ConstInfoPtrType, AUTOMATIC)  DebounceInfoPtr
  )
{
  Dem_SatelliteData_DataType lNewSatelliteData;                                                                                  /* PRQA S 0759 */ /* MD_MSR_18.4 */
  Dem_EventQueue_StatusType lOldQueueStatus;
  Dem_EventQueue_StatusType lNewQueueStatus;
  Dem_MonitorStatusType lMonitorStatus;

  lNewSatelliteData = OldSatelliteData;
  lOldQueueStatus = Dem_EventQueue_GetQueueStatus(OldSatelliteData);
  lNewQueueStatus = Dem_EventQueue_CalculateQueueStatus(lOldQueueStatus, Dem_Debounce_GetMonitorTrigger(DebounceInfoPtr));
  lMonitorStatus = Dem_Monitor_GetMonitorStatus(OldSatelliteData);
  lMonitorStatus = Dem_Monitor_CalculateMonitorStatus(lMonitorStatus, Dem_Debounce_GetMonitorTrigger(DebounceInfoPtr));

  if (Dem_Debounce_TestRequestFdcProcessing(DebounceInfoPtr) == TRUE)
  { /* update event entry with a new max value > pre-confirmation limit on task level */
    lNewQueueStatus = Dem_EventQueue_SetFdcProcessingStatus(lNewQueueStatus);
  }
  if (Dem_Debounce_TestFdcThresholdExceeded(DebounceInfoPtr) == TRUE)
  {
    lNewQueueStatus = Dem_EventQueue_SetFdcTripStatus(lNewQueueStatus);
  }
  if (Dem_Debounce_TestMaximumFdcExceeded(DebounceInfoPtr) == TRUE)
  {
    lNewQueueStatus = Dem_EventQueue_SetFdcMaxSLCStatus(lNewQueueStatus);
  }
  lNewSatelliteData = Dem_Debounce_GetDebouncingResult(DebounceInfoPtr, lNewSatelliteData);
  lNewSatelliteData = Dem_Monitor_SetMonitorStatus(lNewSatelliteData, lMonitorStatus);
  lNewSatelliteData = Dem_EventQueue_GetResult(lNewQueueStatus, lNewSatelliteData);

  return lNewSatelliteData;
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */

/* ****************************************************************************
 % Dem_Satellite_UpdateSimilarConditions
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Satellite_UpdateSimilarConditions(
  CONST(Dem_DebounceBase_ConstInfoPtrType, AUTOMATIC)  DebounceInfoPtr
  )
{
/* >>>> -------------------------------- Enter Critical Section: DiagMonitor */
  Dem_EnterCritical_DiagMonitor();                                                                                               /* PRQA S 3109 */ /* MD_MSR_14.3 */

  if (Dem_Debounce_TestNewSimilarConditionsStatus(DebounceInfoPtr) == TRUE)
  {
    Dem_Event_SetExtendedStatus(DebounceInfoPtr->EventId, 
      Dem_EventInternalStatus_SetSimilarConditions(
        Dem_Event_GetExtendedStatus(DebounceInfoPtr->EventId)
      )
    );
  }
  else
  {
    Dem_Event_SetExtendedStatus(DebounceInfoPtr->EventId, 
      Dem_EventInternalStatus_ResetSimilarConditions(
        Dem_Event_GetExtendedStatus(DebounceInfoPtr->EventId)
      )
    );
  }

  Dem_LeaveCritical_DiagMonitor();                                                                                               /* PRQA S 3109 */ /* MD_MSR_14.3 */
/* <<<< -------------------------------- Leave Critical Section: DiagMonitor */
}

/* ****************************************************************************
 % Dem_Satellite_UpdateRatio
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Satellite_UpdateRatio(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  )
{
#if (DEM_FEATURE_NEED_IUMPR == STD_ON)                                                                                           /* COV_MSR_UNSUPPORTED XF */
  Dem_RatioIdIndexType  lRatioIndex;
#endif

  DEM_IGNORE_UNUSED_CONST_ARGUMENT(EventId)                                                                                      /* PRQA S 3112 */ /* MD_DEM_14.2 */

#if (DEM_FEATURE_NEED_IUMPR == STD_ON)                                                                                           /* COV_MSR_UNSUPPORTED XF */
  lRatioIndex = Dem_Cfg_EventRatioIdIdx(EventId);

  if ( (lRatioIndex != DEM_CFG_RATIOINDEX_INVALID)                                                                               /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
    && (Dem_Cfg_ObdRatioIdType(lRatioIndex) == DEM_RATIO_OBSERVER)
    && (Dem_InitState_TestMasterAtLeastInState(DEM_INITSTATE_INITIALIZED) == TRUE)
    )
  {
    /* >>>> -------------------------------- Enter Critical Section: DiagMonitor */
    Dem_EnterCritical_DiagMonitor();                                                                                             /* PRQA S 3109 */ /* MD_MSR_14.3 */

    Dem_Esm_RatioQueueAsync(lRatioIndex);

    Dem_LeaveCritical_DiagMonitor();                                                                                             /* PRQA S 3109 */ /* MD_MSR_14.3 */
    /* <<<< -------------------------------- Leave Critical Section: DiagMonitor */
  }
#endif
}

/* ****************************************************************************
 % Dem_Satellite_TestQueueUpdated
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Satellite_TestQueueUpdated(
  CONST(Dem_SatelliteData_DataType, AUTOMATIC)  OldSatelliteData,
  CONST(Dem_SatelliteData_DataType, AUTOMATIC)  NewSatelliteData
  )
{
  Dem_EventQueue_StatusType lOldQueueStatus;
  Dem_EventQueue_StatusType lNewQueueStatus;
  lOldQueueStatus = Dem_EventQueue_GetQueueStatus(OldSatelliteData);
  lNewQueueStatus = Dem_EventQueue_GetQueueStatus(NewSatelliteData);

  return (boolean)( (lOldQueueStatus == DEM_EVENTQUEUE_STATE_INITIAL)
                 && (lNewQueueStatus != DEM_EVENTQUEUE_STATE_INITIAL) );
}

/* ****************************************************************************
 % Dem_SatelliteSat_UpdateMonitorTrigger
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
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_SatelliteSat_UpdateMonitorTrigger(
  CONST(Dem_Satellite_IdType, AUTOMATIC)        SatelliteId,
  CONST(Dem_Satellite_MonitorIdType, AUTOMATIC) MonitorId,
  CONST(Dem_EventStatusType, AUTOMATIC)         MonitorTrigger
  )
{
  Std_ReturnType lReturnValue;
  Dem_EventIdType lEventId;
  Dem_Debounce_InfoType lDebounceInfoData;                                                                                       /* PRQA S 0759 */ /* MD_MSR_18.4 */
  Dem_DebounceBase_InfoPtrType lDebounceInfoPtr;
  Dem_SatelliteData_DataType lOldSatelliteData;                                                                                  /* PRQA S 0759 */ /* MD_MSR_18.4 */
  Dem_SatelliteData_DataType lNewSatelliteData;                                                                                  /* PRQA S 0759 */ /* MD_MSR_18.4 */

  lReturnValue = E_OK;
  lEventId = Dem_Satellite_GetEventId(SatelliteId, MonitorId);

  /* Possible concurrent modification :
     ClearEvent
     ResetEventStatus
     Displacement
     Aging */

  do
  {
    lOldSatelliteData = Dem_Satellite_GetSatelliteData(SatelliteId, MonitorId);
    lNewSatelliteData = lOldSatelliteData;
    lDebounceInfoPtr = Dem_Debounce_DebounceInfoInit(lEventId, &lDebounceInfoData, lOldSatelliteData);

    Dem_Debounce_SetMonitorTrigger(lDebounceInfoPtr, MonitorTrigger);
    if (Dem_Debounce_CalculateDebouncing(lDebounceInfoPtr) == TRUE)
    {
      if ( (Dem_Debounce_TestDebouncingChanged(lDebounceInfoPtr) == TRUE)                                                        /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
        || (Dem_Satellite_TestMonitorQualificationNeeded(lOldSatelliteData, lDebounceInfoPtr)  == TRUE))
      {
        lReturnValue = Dem_EventQueue_TestQueueOverflow(
          Dem_EventQueue_GetQueueStatus(lOldSatelliteData),
          Dem_Debounce_GetMonitorTrigger(lDebounceInfoPtr));
        if (lReturnValue == E_OK)
        {
          lNewSatelliteData = Dem_Satellite_UpdateSatelliteData(lOldSatelliteData, lDebounceInfoPtr);
        }
        else
        {
          /* Event update must be discarded due to queue overflow */
          break;                                                                                                                 /* PRQA S 0771 */ /* MD_DEM_14.6_err */
        }
      }

      if (Dem_Debounce_TestSimilarConditionsChanged(lDebounceInfoPtr) == TRUE)
      {
        Dem_Satellite_UpdateSimilarConditions(lDebounceInfoPtr);
      }

      if (Dem_Debounce_TestQualifiedResult(lDebounceInfoPtr) == TRUE)
      {
        Dem_Satellite_UpdateRatio(lEventId);
      }
    }
    else
    {
      lReturnValue = E_NOT_OK;
    }

  }
  while (Dem_SatelliteSat_SyncSetSatelliteData(SatelliteId, MonitorId, lOldSatelliteData, lNewSatelliteData) == FALSE);

  if (Dem_Debounce_TestMaximumFdcExceeded(lDebounceInfoPtr) == TRUE)
  {
    Dem_DebounceBaseSat_UpdateDebounceValueMax(lDebounceInfoPtr);
  }
  if (Dem_Satellite_TestQueueUpdated(lOldSatelliteData, lNewSatelliteData) == TRUE)
  {
    Dem_SatelliteSat_SetQueueUpdated(SatelliteId);
  }

  /* Notify monitor status change */
  if (Dem_Monitor_GetMonitorStatus(lOldSatelliteData) != Dem_Monitor_GetMonitorStatus(lNewSatelliteData))
  {
    Dem_Monitor_NotifyMonitorStatusChange(lEventId);
  }
  return lReturnValue;
}                                                                                                                                /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

#if (DEM_FEATURE_NEED_DEBOUNCE_TIME == STD_ON)
/* ****************************************************************************
 % Dem_SatelliteSat_ProcessTimeBasedDebouncing
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
 */
DEM_LOCAL FUNC(void, DEM_CODE)
Dem_SatelliteSat_ProcessTimeBasedDebouncing(
  CONST(Dem_Satellite_IdType, AUTOMATIC)  SatelliteId,
  CONST(Dem_Satellite_MonitorIdType, AUTOMATIC)  MonitorId
  )
{
  Dem_EventIdType lEventId;
  Dem_SatelliteData_DataType lOldSatelliteData;                                                                                  /* PRQA S 0759 */ /* MD_MSR_18.4 */
  Dem_SatelliteData_DataType lNewSatelliteData;                                                                                  /* PRQA S 0759 */ /* MD_MSR_18.4 */
  Dem_DebounceBase_InfoPtrType lDebounceInfoPtr;
  Dem_Debounce_InfoType lDebounceInfoData;                                                                                       /* PRQA S 0759 */ /* MD_MSR_18.4 */

  lEventId = Dem_Satellite_GetEventId(SatelliteId, MonitorId);
  lOldSatelliteData = Dem_Satellite_GetSatelliteData(SatelliteId, MonitorId);
  lDebounceInfoPtr = Dem_Debounce_DebounceInfoInit(lEventId, &lDebounceInfoData, lOldSatelliteData);

  if (Dem_DebounceTimeBasedSat_IsTimerActive(lDebounceInfoPtr) == TRUE)
  {
    Dem_EventQueue_StatusType lOldQueueStatus;
    Dem_EventQueue_StatusType lNewQueueStatus;
    Dem_MonitorStatusType lMonitorStatus;
    boolean lQueueUpdated;

    do
    {
      lOldSatelliteData = Dem_Satellite_GetSatelliteData(SatelliteId, MonitorId);
      lNewSatelliteData = lOldSatelliteData;
      lDebounceInfoPtr = Dem_Debounce_DebounceInfoInit(lEventId, &lDebounceInfoData, lOldSatelliteData);

      lOldQueueStatus = Dem_EventQueue_GetQueueStatus(lOldSatelliteData);
      lMonitorStatus = Dem_Monitor_GetMonitorStatus(lOldSatelliteData);

      Dem_DebounceTimeBasedSat_ProcessDebounce(lDebounceInfoPtr);

      lMonitorStatus = Dem_Monitor_CalculateMonitorStatus(lMonitorStatus, Dem_Debounce_GetMonitorTrigger(lDebounceInfoPtr));
      lNewQueueStatus = Dem_EventQueue_CalculateQueueStatus(lOldQueueStatus, Dem_Debounce_GetMonitorTrigger(lDebounceInfoPtr));
      if (Dem_Debounce_TestRequestFdcProcessing(lDebounceInfoPtr) == TRUE)
      { /* update event entry with a new max value > pre-confirmation limit on task level */
        lNewQueueStatus = Dem_EventQueue_SetFdcProcessingStatus(lNewQueueStatus);
      }
      if (Dem_Debounce_TestFdcThresholdExceeded(lDebounceInfoPtr) == TRUE)
      {
        lNewQueueStatus = Dem_EventQueue_SetFdcTripStatus(lNewQueueStatus);
      }
      if (Dem_Debounce_TestMaximumFdcExceeded(lDebounceInfoPtr) == TRUE)
      {
        lNewQueueStatus = Dem_EventQueue_SetFdcMaxSLCStatus(lNewQueueStatus);
      }

      lNewSatelliteData = Dem_Debounce_GetDebouncingResult(lDebounceInfoPtr, lNewSatelliteData);
      lNewSatelliteData = Dem_Monitor_SetMonitorStatus(lNewSatelliteData, lMonitorStatus);
      lNewSatelliteData = Dem_EventQueue_GetResult(lNewQueueStatus, lNewSatelliteData);

      lQueueUpdated = (boolean)((lOldQueueStatus == DEM_EVENTQUEUE_STATE_INITIAL)
        && (lNewQueueStatus != DEM_EVENTQUEUE_STATE_INITIAL));
    } while (Dem_SatelliteSat_SyncSetSatelliteData(SatelliteId, MonitorId, lOldSatelliteData, lNewSatelliteData) == FALSE);

    if (Dem_Debounce_TestMaximumFdcExceeded(lDebounceInfoPtr) == TRUE)
    {
      Dem_DebounceBaseSat_UpdateDebounceValueMax(lDebounceInfoPtr);
    }
    if (lQueueUpdated == TRUE)
    {
      Dem_SatelliteSat_SetQueueUpdated(SatelliteId);
    }
    /* Notify monitor status change */
    if (Dem_Monitor_GetMonitorStatus(lOldSatelliteData) != Dem_Monitor_GetMonitorStatus(lNewSatelliteData))
    {
      Dem_Monitor_NotifyMonitorStatusChange(lEventId);
    }
  }
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */
#endif

/* ****************************************************************************
 % Dem_SatelliteSat_SetInitState
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_SatelliteSat_SetInitState(
  CONST(Dem_Satellite_IdType, AUTOMATIC)  SatelliteId,
  CONST(uint8, AUTOMATIC) InitState
  )
{
  Dem_SatelliteInfo_Type lOldSatelliteInfo;                                                                                      /* PRQA S 0759 */ /* MD_MSR_18.4 */
  Dem_SatelliteInfo_Type lNewSatelliteInfo;                                                                                      /* PRQA S 0759 */ /* MD_MSR_18.4 */
  do
  {
    lOldSatelliteInfo = Dem_Satellite_GetSatelliteInfo(SatelliteId);
    lNewSatelliteInfo = Dem_SatelliteInfo_SetInitStatus(lOldSatelliteInfo, InitState);
  }
  while (Dem_SatelliteSat_SyncSetSatelliteInfo(SatelliteId, lOldSatelliteInfo, lNewSatelliteInfo) == FALSE);
}

/* ****************************************************************************
 % Dem_Satellite_TestMonitorQualificationNeeded
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
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Satellite_TestMonitorQualificationNeeded(
  CONST(Dem_SatelliteData_DataType, AUTOMATIC)  SatelliteDataValue,
  CONST(Dem_DebounceBase_ConstInfoPtrType, AUTOMATIC) DebounceInfoPtr
  )
{
  Std_ReturnType lReturn;

#if (DEM_CFG_DEBOUNCECONTINUOUSOFDEBOUNCETABLE ==STD_ON)
  if ( ( (Dem_Debounce_TestQualifiedResult(DebounceInfoPtr) == TRUE)                                                             /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
      && (Dem_Monitor_TestTNCTOC(SatelliteDataValue) == TRUE) )
    || ( (Dem_Debounce_GetMonitorTrigger(DebounceInfoPtr) == DEM_EVENT_STATUS_FAILED)
      && (Dem_Monitor_TestTF(SatelliteDataValue) == FALSE) )
    || ( (Dem_Debounce_GetMonitorTrigger(DebounceInfoPtr) == DEM_EVENT_STATUS_PASSED)
      && (Dem_Monitor_TestTF(SatelliteDataValue) == TRUE) ) )
  {
    lReturn = TRUE;
  }
  else
#endif
  {
    lReturn = FALSE;
  }
  return lReturn;
}
/*!
 * \}
 */

/*!
 * \addtogroup Dem_Satellite_Public
 * \{
 */

/* ****************************************************************************
 % Dem_SatelliteSat_FreezeDebounceStatus
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
DEM_LOCAL FUNC(void, DEM_CODE)
Dem_SatelliteSat_FreezeDebounceStatus(
  CONST(Dem_Satellite_IdType, AUTOMATIC)  SatelliteId,
  CONST(Dem_Satellite_MonitorIdType, AUTOMATIC)  MonitorId
  )
{
  Dem_EventIdType lEventId;
  Dem_SatelliteData_DataType lOldSatelliteData;                                                                                  /* PRQA S 0759 */ /* MD_MSR_18.4 */
  Dem_SatelliteData_DataType lNewSatelliteData;                                                                                  /* PRQA S 0759 */ /* MD_MSR_18.4 */
  Dem_Debounce_InfoType lDebounceInfoData;                                                                                       /* PRQA S 0759 */ /* MD_MSR_18.4 */
  Dem_DebounceBase_InfoPtrType lDebounceInfoPtr;

  lEventId = Dem_Satellite_GetEventId(SatelliteId, MonitorId);
  do
  {
    lOldSatelliteData = Dem_Satellite_GetSatelliteData(SatelliteId, MonitorId);
    lNewSatelliteData = lOldSatelliteData;
    lDebounceInfoPtr = Dem_Debounce_DebounceInfoInit(lEventId, &lDebounceInfoData, lOldSatelliteData);

    lNewSatelliteData = Dem_Debounce_FreezeDebouncing(lDebounceInfoPtr, lNewSatelliteData);
  }
  while (Dem_SatelliteSat_SyncSetSatelliteData(SatelliteId, MonitorId, lOldSatelliteData, lNewSatelliteData) == FALSE);
}

/* ****************************************************************************
 % Dem_SatelliteCore_FreezeDebounceStatus
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL FUNC(void, DEM_CODE)
Dem_SatelliteCore_FreezeDebounceStatus(
  CONST(Dem_Satellite_IdType, AUTOMATIC)  SatelliteId,
  CONST(Dem_Satellite_MonitorIdType, AUTOMATIC)  MonitorId
  )
{
  Dem_SatelliteSat_FreezeDebounceStatus(SatelliteId, MonitorId);
}

/* ****************************************************************************
 % Dem_SatelliteSat_GetDebouncingState
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL FUNC(Dem_DebouncingStateType, DEM_CODE)
Dem_SatelliteSat_GetDebouncingState(
  CONST(Dem_Satellite_IdType, AUTOMATIC)  SatelliteId,
  CONST(Dem_Satellite_MonitorIdType, AUTOMATIC)  MonitorId
  )
{
  Dem_EventIdType lEventId;
  Dem_SatelliteData_DataType lSatelliteData;                                                                                     /* PRQA S 0759 */ /* MD_MSR_18.4 */
  Dem_Debounce_InfoType lDebounceInfoData;                                                                                       /* PRQA S 0759 */ /* MD_MSR_18.4 */
  Dem_DebounceBase_InfoPtrType lDebounceInfoPtr;

  lEventId = Dem_Satellite_GetEventId(SatelliteId, MonitorId);
  lSatelliteData = Dem_Satellite_GetSatelliteData(SatelliteId, MonitorId);
  lDebounceInfoPtr = Dem_Debounce_DebounceInfoInit(lEventId, &lDebounceInfoData, lSatelliteData);

  return Dem_Debounce_GetDebouncingState(lDebounceInfoPtr);
}

/* ****************************************************************************
 % Dem_SatelliteSat_ReportMonitorTrigger
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
 */
DEM_LOCAL FUNC(Std_ReturnType, DEM_CODE)
Dem_SatelliteSat_ReportMonitorTrigger(
  CONST(Dem_EventIdType, AUTOMATIC)     EventId,
  CONST(Dem_EventStatusType, AUTOMATIC) MonitorTrigger
  )
{
  Std_ReturnType lReturnValue;

  if ( (Dem_OperationCycle_GetCurrentCycleStatus(Dem_Cfg_EventOperationCycle(EventId)) == DEM_OPERATIONCYCLE_CYCLE_STARTED)      /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
    && (Dem_Cfg_EventAvailableByVariant(EventId) == TRUE)
    && (Dem_EventInternalStatus_TestEventDisconnected(Dem_Event_GetInternalStatus(EventId)) == FALSE)
    )
  {
    lReturnValue =
        Dem_SatelliteSat_UpdateMonitorTrigger(
            Dem_Cfg_EventSatelliteId(EventId),
            Dem_Cfg_EventSatelliteEventId(EventId),
            MonitorTrigger);
  }
  else
  {
    lReturnValue = E_NOT_OK;
  }

  return lReturnValue;
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */

/* ****************************************************************************
 % Dem_SatelliteSat_ResetEventStatus
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
DEM_LOCAL FUNC(Std_ReturnType, DEM_CODE)
Dem_SatelliteSat_ResetEventStatus(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  )
{
  Std_ReturnType lReturnValue;

  lReturnValue = E_NOT_OK;
#if (DEM_CFG_SUPPORT_WWHOBD == STD_ON)                                                                                           /* COV_MSR_UNSUPPORTED XF */
  /* Confirmed (independent of qualification state) WWH OBD events can't
      reset their test failed bit as this will effect the activation mode */
  if ( (Dem_Cfg_EventObdRelated(EventId) == FALSE)                                                                               /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
    || (Dem_UDSStatus_Test_CDTC(Dem_Event_GetUDSStatus(EventId)) == FALSE) )
#endif
  {
    if ( (Dem_Cfg_EventAvailableByVariant(EventId) == TRUE)                                                                      /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
      && (Dem_EventInternalStatus_TestEventDisconnected(Dem_Event_GetInternalStatus(EventId)) == FALSE)
      && (Dem_UDSStatus_Test_TNCTOC(Dem_Event_GetUDSStatus(EventId)) == TRUE) )
    {
      Dem_Satellite_IdType lSatelliteId;
      Dem_EventIdType lMonitorId;
      boolean lProcessingDone;

      lSatelliteId = Dem_Cfg_EventSatelliteId(EventId);
      lMonitorId = Dem_Cfg_EventSatelliteEventId(EventId);
      do
      {
        Dem_SatelliteData_DataType lOldSatelliteData;                                                                            /* PRQA S 0759 */ /* MD_MSR_18.4 */
        Dem_SatelliteData_DataType lNewSatelliteData;                                                                            /* PRQA S 0759 */ /* MD_MSR_18.4 */
        Dem_EventQueue_StatusType lQueueStatus;

        lOldSatelliteData = Dem_Satellite_GetSatelliteData(lSatelliteId, lMonitorId);
        lNewSatelliteData = lOldSatelliteData;

        lQueueStatus = Dem_EventQueue_GetQueueStatus(lOldSatelliteData);
        if (lQueueStatus == DEM_EVENTQUEUE_STATE_INITIAL)
        {
          Dem_Debounce_InfoType lDebounceInfoData;                                                                               /* PRQA S 0759 */ /* MD_MSR_18.4 */
          Dem_DebounceBase_InfoPtrType lDebounceInfoPtr;

          lDebounceInfoPtr = Dem_Debounce_DebounceInfoInit(EventId, &lDebounceInfoData, lOldSatelliteData);
          lNewSatelliteData = Dem_Debounce_ResetDebouncing(lDebounceInfoPtr, lNewSatelliteData);

          lQueueStatus = Dem_EventQueue_SetResetTestFailedRequested(lQueueStatus);
          lNewSatelliteData = Dem_EventQueue_GetResult(lQueueStatus, lNewSatelliteData);
          lProcessingDone = Dem_SatelliteSat_SyncSetSatelliteData(lSatelliteId, lMonitorId, lOldSatelliteData, lNewSatelliteData);
          if (lProcessingDone == TRUE)
          {
            lReturnValue = E_OK;
            Dem_SatelliteSat_SetQueueUpdated(lSatelliteId);
          }
        }
        else
        {
          /* Event is already queued, so there was a qualified result. Technically, reseteventstatus is not
            * allowed to interrupt seteventstatus, so the queue status should not change in this loop - better be
            * paranoid though */
          lProcessingDone = TRUE;
        }
      }
      while (lProcessingDone == FALSE);
    }
  }
  return lReturnValue;
}                                                                                                                                /* PRQA S 6050, 6080 */ /* MD_MSR_STCAL, MD_MSR_STMIF */

/* ****************************************************************************
 % Dem_SatelliteSat_MainFunction
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_SatelliteSat_MainFunction(
  CONST(Dem_Satellite_IdType, AUTOMATIC)  SatelliteId
  )
{
#if (DEM_FEATURE_NEED_DEBOUNCE_TIME == STD_ON)
# if (DEM_CFG_SUPPORT_DEBOUNCE_TIME_HR == STD_ON)
  {
    Dem_Cfg_DebounceHiResIterType lIter;

    /* Process Time Based Debounce Events assigned to current satellite which use the high resolution timer */
    for (Dem_Cfg_DebounceHiResIterInit(SatelliteId, &lIter);                                                                     /* SBSW_DEM_CALL_ITERATOR_POINTER */
         Dem_Cfg_DebounceHiResIterExists(&lIter) == TRUE;                                                                        /* SBSW_DEM_CALL_ITERATOR_POINTER */
         Dem_Cfg_DebounceHiResIterNext(&lIter))                                                                                  /* SBSW_DEM_CALL_ITERATOR_POINTER */
    {
      Dem_SatelliteSat_ProcessTimeBasedDebouncing(SatelliteId,
                                                  Dem_Cfg_EventSatelliteEventId(Dem_Cfg_DebounceHiResIterGet(&lIter)));          /* SBSW_DEM_CALL_ITERATOR_POINTER */
    }
  }
# endif /* ( DEM_CFG_SUPPORT_DEBOUNCE_TIME_HR == STD_ON ) */

# if (DEM_CFG_SUPPORT_DEBOUNCE_TIME_LR == STD_ON)
  {
    uint8 lLoResTimer;
    lLoResTimer = *Dem_Cfg_GetDebounceLoResTimerOfSatelliteInfo(SatelliteId);

    lLoResTimer--;

    if (lLoResTimer == 0)
    {
      Dem_Cfg_DebounceLoResIterType lIter;

      /* Process Time Based Debounce Events assigned to current satellite which use the low resolution timer */
      for (Dem_Cfg_DebounceLoResIterInit(SatelliteId, &lIter);                                                                   /* SBSW_DEM_CALL_ITERATOR_POINTER */
           Dem_Cfg_DebounceLoResIterExists(&lIter) == TRUE;                                                                      /* SBSW_DEM_CALL_ITERATOR_POINTER */
           Dem_Cfg_DebounceLoResIterNext(&lIter))                                                                                /* SBSW_DEM_CALL_ITERATOR_POINTER */
      {
        Dem_SatelliteSat_ProcessTimeBasedDebouncing(SatelliteId,
                                                    Dem_Cfg_EventSatelliteEventId(Dem_Cfg_DebounceLoResIterGet(&lIter)));        /* SBSW_DEM_CALL_ITERATOR_POINTER */
      }

      /* restart low resolution timer */
      lLoResTimer = Dem_Cfg_DebounceLoResTimerValue();
    }
    *Dem_Cfg_GetDebounceLoResTimerOfSatelliteInfo(SatelliteId) = lLoResTimer;
  }
# endif /* (DEM_CFG_SUPPORT_DEBOUNCE_TIME_LR == STD_ON) */
#endif /* (DEM_FEATURE_NEED_DEBOUNCE_TIME == STD_ON) */
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(SatelliteId)                                                                                  /* PRQA S 3112 */ /* MD_DEM_14.2 */
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */

/* ****************************************************************************
 % Dem_SatelliteSat_ResetDebounceStatus
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_SatelliteSat_ResetDebounceStatus(
  CONST(Dem_Satellite_IdType, AUTOMATIC)  SatelliteId,
  CONST(Dem_Satellite_MonitorIdType, AUTOMATIC)  MonitorId
  )
{
  Dem_EventIdType lEventId;
  Dem_SatelliteData_DataType lOldSatelliteData;                                                                                  /* PRQA S 0759 */ /* MD_MSR_18.4 */
  Dem_SatelliteData_DataType lNewSatelliteData;                                                                                  /* PRQA S 0759 */ /* MD_MSR_18.4 */
  Dem_Debounce_InfoType lDebounceInfoData;                                                                                       /* PRQA S 0759 */ /* MD_MSR_18.4 */
  Dem_DebounceBase_InfoPtrType lDebounceInfoPtr;

  lEventId = Dem_Satellite_GetEventId(SatelliteId, MonitorId);
  do
  {
    lOldSatelliteData = Dem_Satellite_GetSatelliteData(SatelliteId, MonitorId);
    lNewSatelliteData = lOldSatelliteData;
    lDebounceInfoPtr = Dem_Debounce_DebounceInfoInit(lEventId, &lDebounceInfoData, lOldSatelliteData);

    lNewSatelliteData = Dem_Debounce_ResetDebouncing(lDebounceInfoPtr, lNewSatelliteData);
  }
  while (Dem_SatelliteSat_SyncSetSatelliteData(SatelliteId, MonitorId, lOldSatelliteData, lNewSatelliteData) == FALSE);
}

/* ****************************************************************************
 % Dem_SatelliteCore_ResetDebounceStatus
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_SatelliteCore_ResetDebounceStatus(
  CONST(Dem_Satellite_IdType, AUTOMATIC)  SatelliteId,
  CONST(Dem_Satellite_MonitorIdType, AUTOMATIC)  MonitorId
  )
{
  Dem_SatelliteSat_ResetDebounceStatus(SatelliteId, MonitorId);
}

/* ****************************************************************************
 % Dem_SatelliteCore_RestartEvent
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
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_SatelliteCore_RestartEvent(
  CONST(Dem_Satellite_IdType, AUTOMATIC)  SatelliteId,
  CONST(Dem_Satellite_MonitorIdType, AUTOMATIC)  MonitorId
  )
{
  Dem_SatelliteData_DataType lOldSatelliteData;                                                                                  /* PRQA S 0759 */ /* MD_MSR_18.4 */
  Dem_SatelliteData_DataType lNewSatelliteData;                                                                                  /* PRQA S 0759 */ /* MD_MSR_18.4 */
  Dem_Debounce_InfoType lDebounceInfoData;                                                                                       /* PRQA S 0759 */ /* MD_MSR_18.4 */
  Dem_DebounceBase_InfoPtrType lDebounceInfoPtr;
  Dem_EventIdType lEventId;

  lEventId = Dem_Satellite_GetEventId(SatelliteId, MonitorId);
  do
  {
    lOldSatelliteData = Dem_Satellite_GetSatelliteData(SatelliteId, MonitorId);
    lNewSatelliteData = lOldSatelliteData;
    lDebounceInfoPtr = Dem_Debounce_DebounceInfoInit(lEventId, &lDebounceInfoData, lOldSatelliteData);

    lNewSatelliteData = Dem_Debounce_ResetDebouncing(lDebounceInfoPtr, lNewSatelliteData);
    lNewSatelliteData = Dem_EventQueue_ResetQueueStatus(lNewSatelliteData);
    lNewSatelliteData = Dem_Monitor_ResetTNCTOC(lNewSatelliteData);
  }
  while (Dem_SatelliteSat_SyncSetSatelliteData(SatelliteId, MonitorId, lOldSatelliteData, lNewSatelliteData) == FALSE);
  Dem_DebounceBaseCore_ResetDebounceValueMax(lDebounceInfoPtr);

  /* Notify monitor status change */
  if (Dem_Monitor_GetMonitorStatus(lOldSatelliteData) != Dem_Monitor_GetMonitorStatus(lNewSatelliteData))
  {
    Dem_Monitor_NotifyMonitorStatusChange(lEventId);
  }
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */

/* ****************************************************************************
 % Dem_SatelliteCore_ClearEvent
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
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_SatelliteCore_ClearEvent(
  CONST(Dem_Satellite_IdType, AUTOMATIC)  SatelliteId,
  CONST(Dem_Satellite_MonitorIdType, AUTOMATIC)  MonitorId
  )
{
  Dem_SatelliteData_DataType lOldSatelliteData;                                                                                  /* PRQA S 0759 */ /* MD_MSR_18.4 */
  Dem_SatelliteData_DataType lNewSatelliteData;                                                                                  /* PRQA S 0759 */ /* MD_MSR_18.4 */
  Dem_Debounce_InfoType lDebounceInfoData;                                                                                       /* PRQA S 0759 */ /* MD_MSR_18.4 */
  Dem_DebounceBase_InfoPtrType lDebounceInfoPtr;
  Dem_EventIdType lEventId;

  lEventId = Dem_Satellite_GetEventId(SatelliteId, MonitorId);
  do
  {
    lOldSatelliteData = Dem_Satellite_GetSatelliteData(SatelliteId, MonitorId);
    lNewSatelliteData = lOldSatelliteData;
    lDebounceInfoPtr = Dem_Debounce_DebounceInfoInit(lEventId, &lDebounceInfoData, lOldSatelliteData);

    lNewSatelliteData = Dem_Debounce_ResetDebouncing(lDebounceInfoPtr, lNewSatelliteData);
    lNewSatelliteData = Dem_EventQueue_ResetQueueStatus(lNewSatelliteData);
    lNewSatelliteData = Dem_Monitor_ResetMonitorStatus(lNewSatelliteData);
  }
  while (Dem_SatelliteSat_SyncSetSatelliteData(SatelliteId, MonitorId, lOldSatelliteData, lNewSatelliteData) == FALSE);
  Dem_DebounceBaseCore_ResetDebounceValueMax(lDebounceInfoPtr);

  /* Notify monitor status change */
  if (Dem_Monitor_GetMonitorStatus(lOldSatelliteData) != Dem_Monitor_GetMonitorStatus(lNewSatelliteData))
  {
    Dem_Monitor_NotifyMonitorStatusChange(lEventId);
  }
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */

/* ****************************************************************************
 % Dem_SatelliteCore_TestAndClearQueueUpdated
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_SatelliteCore_TestAndClearQueueUpdated(
  CONST(Dem_Satellite_IdType, AUTOMATIC)  SatelliteId
  )
{
  Dem_SatelliteInfo_Type lOldSatelliteInfo;                                                                                      /* PRQA S 0759 */ /* MD_MSR_18.4 */
  Dem_SatelliteInfo_Type lNewSatelliteInfo;                                                                                      /* PRQA S 0759 */ /* MD_MSR_18.4 */
  do
  {
    lOldSatelliteInfo = Dem_Satellite_GetSatelliteInfo(SatelliteId);
    lNewSatelliteInfo = Dem_SatelliteInfo_SetQueueUpdated(lOldSatelliteInfo, FALSE);
  }
  while (Dem_SatelliteCore_SyncSetSatelliteInfo(SatelliteId, lOldSatelliteInfo, lNewSatelliteInfo) == FALSE);
  return Dem_SatelliteInfo_GetQueueUpdated(lOldSatelliteInfo);
}

/* ****************************************************************************
 % Dem_Satellite_PeekQueueStatus
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_EventQueue_StatusType, DEM_CODE)
Dem_Satellite_PeekQueueStatus(
  CONST(Dem_Satellite_IdType, AUTOMATIC)  SatelliteId,
  CONST(Dem_Satellite_MonitorIdType, AUTOMATIC)  MonitorId
  )
{
  Dem_SatelliteData_DataType lOldSatelliteData;                                                                                  /* PRQA S 0759 */ /* MD_MSR_18.4 */
  lOldSatelliteData = Dem_Satellite_GetSatelliteData(SatelliteId, MonitorId);
  return Dem_EventQueue_GetQueueStatus(lOldSatelliteData);
}

/* ****************************************************************************
 % Dem_SatelliteCore_ConsumeQueueStatus
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_EventQueue_StatusType, DEM_CODE)
Dem_SatelliteCore_ConsumeQueueStatus(
  CONST(Dem_Satellite_IdType, AUTOMATIC)  SatelliteId,
  CONST(Dem_Satellite_MonitorIdType, AUTOMATIC)  MonitorId
  )
{
  Dem_SatelliteData_DataType lOldSatelliteData;                                                                                  /* PRQA S 0759 */ /* MD_MSR_18.4 */
  Dem_SatelliteData_DataType lNewSatelliteData;                                                                                  /* PRQA S 0759 */ /* MD_MSR_18.4 */
  do
  {
    lOldSatelliteData = Dem_Satellite_GetSatelliteData(SatelliteId, MonitorId);
    lNewSatelliteData = Dem_EventQueue_ResetQueueStatus(lOldSatelliteData);
  }
  while (Dem_SatelliteCore_SyncSetSatelliteData(SatelliteId, MonitorId, lOldSatelliteData, lNewSatelliteData) == FALSE);
  return Dem_EventQueue_GetQueueStatus(lOldSatelliteData);
}

/* ****************************************************************************
 % Dem_SatelliteCore_MemoryInit
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_SatelliteCore_MemoryInit(
  CONST(Dem_Satellite_IdType, AUTOMATIC)  SatelliteId
  )
{
  Dem_SatelliteInfo_Type lSatelliteInfo;                                                                                         /* PRQA S 0759 */ /* MD_MSR_18.4 */
  lSatelliteInfo = Dem_SatelliteInfo_GetInitValue();
  Dem_SatelliteSat_SetSatelliteInfo(SatelliteId, lSatelliteInfo);
}

/* ****************************************************************************
 % Dem_SatelliteSat_PreInit
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_SatelliteSat_PreInit(
  CONST(Dem_Satellite_IdType, AUTOMATIC)  SatelliteId
  )
{
  {
    Dem_Satellite_MonitorIdType lMonitorId;
    Dem_SatelliteData_DataType lSatelliteData;                                                                                   /* PRQA S 0759 */ /* MD_MSR_18.4 */

    lSatelliteData = Dem_SatelliteData_GetInitValue();

    for (lMonitorId = 0;
         lMonitorId < Dem_Cfg_GetEventCountOfSatelliteInfo(SatelliteId);
         ++lMonitorId)
    {
      Dem_SatelliteSat_SetSatelliteData(SatelliteId, lMonitorId, lSatelliteData);
      Dem_DebounceSat_PreInit(SatelliteId, lMonitorId);
    }
  }

  {
    Dem_SatelliteInfo_Type lSatelliteInfo;                                                                                       /* PRQA S 0759 */ /* MD_MSR_18.4 */
    lSatelliteInfo = Dem_Satellite_GetSatelliteInfo(SatelliteId);
    lSatelliteInfo = Dem_SatelliteInfo_SetInitStatus(lSatelliteInfo, DEM_INITSTATE_PREINITIALIZED);
    Dem_SatelliteSat_SetSatelliteInfo(SatelliteId, lSatelliteInfo);
  }

#if (DEM_CFG_SUPPORT_DEBOUNCE_TIME_LR == STD_ON)
  {
    *Dem_Cfg_GetDebounceLoResTimerOfSatelliteInfo(SatelliteId) = Dem_Cfg_DebounceLoResTimerValue();
  }
#endif
}

/* ****************************************************************************
 % Dem_SatelliteSat_Init
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_SatelliteSat_Init(
  CONST(Dem_Satellite_IdType, AUTOMATIC)  SatelliteId
  )
{
  Dem_SatelliteSat_SetInitState(SatelliteId, DEM_INITSTATE_INITIALIZED);
}

/* ****************************************************************************
 % Dem_Satellite_GetFaultDetectionCounter
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Satellite_GetFaultDetectionCounter(
  CONST(Dem_Satellite_IdType, AUTOMATIC)  SatelliteId,
  CONST(Dem_Satellite_MonitorIdType, AUTOMATIC)  MonitorId,
  CONSTP2VAR(sint8, AUTOMATIC, DEM_APPL_DATA)  FaultDetectionCounter                                                             /* PRQA S 3673 */ /* MD_DEM_16.7 */
  )
{
  Dem_EventIdType lEventId;
  Dem_SatelliteData_DataType lSatelliteData;                                                                                     /* PRQA S 0759 */ /* MD_MSR_18.4 */
  Dem_Debounce_InfoType lDebounceInfoData;                                                                                       /* PRQA S 0759 */ /* MD_MSR_18.4 */
  Dem_DebounceBase_InfoPtrType lDebounceInfoPtr;
  Std_ReturnType lReturnValue;

  lEventId = Dem_Satellite_GetEventId(SatelliteId, MonitorId);
  lSatelliteData = Dem_Satellite_GetSatelliteData(SatelliteId, MonitorId);
  lDebounceInfoPtr = Dem_Debounce_DebounceInfoInit(lEventId, &lDebounceInfoData, lSatelliteData);
  lReturnValue = Dem_Debounce_GetFaultDetectionCounter(lDebounceInfoPtr, FaultDetectionCounter);

  return lReturnValue;
}

/* ****************************************************************************
 % Dem_Satellite_GetMaxFaultDetectionCounter
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(sint8, DEM_CODE)
Dem_Satellite_GetMaxFaultDetectionCounter(                                                                                       /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONST(Dem_Satellite_IdType, AUTOMATIC)  SatelliteId,
  CONST(Dem_Satellite_MonitorIdType, AUTOMATIC)  MonitorId
  )
{
  Dem_EventIdType lEventId;
  Dem_SatelliteData_DataType lSatelliteData;                                                                                     /* PRQA S 0759 */ /* MD_MSR_18.4 */
  Dem_DebounceBase_InfoPtrType lDebounceInfoPtr;
  Dem_Debounce_InfoType lDebounceInfoData;                                                                                       /* PRQA S 0759 */ /* MD_MSR_18.4 */

  lEventId = Dem_Satellite_GetEventId(SatelliteId, MonitorId);
  lSatelliteData = Dem_Satellite_GetSatelliteData(SatelliteId, MonitorId);
  lDebounceInfoPtr = Dem_Debounce_DebounceInfoInit(lEventId, &lDebounceInfoData, lSatelliteData);
  return Dem_Debounce_GetMaxFaultDetectionCounter(lDebounceInfoPtr);
}

#if (DEM_CFG_SUPPORT_DEBOUNCE_NV == STD_ON)
/* ****************************************************************************
 % Dem_SatelliteCore_RestoreDebounceValue
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_SatelliteCore_RestoreDebounceValue(
  CONST(Dem_Satellite_IdType, AUTOMATIC)  SatelliteId,
  CONST(Dem_Satellite_MonitorIdType, AUTOMATIC)  MonitorId,
  CONST(sint16, AUTOMATIC) Value,
  CONST(boolean, AUTOMATIC) ExpectedThreshold
  )
{
  Dem_EventIdType lEventId;
  Dem_SatelliteData_DataType lOldSatelliteData;                                                                                  /* PRQA S 0759 */ /* MD_MSR_18.4 */
  Dem_SatelliteData_DataType lNewSatelliteData;                                                                                  /* PRQA S 0759 */ /* MD_MSR_18.4 */
  Dem_Debounce_InfoType lDebounceInfoData;                                                                                       /* PRQA S 0759 */ /* MD_MSR_18.4 */
  Dem_DebounceBase_InfoPtrType lDebounceInfoPtr;

  lEventId = Dem_Satellite_GetEventId(SatelliteId, MonitorId);
  do
  {
    lOldSatelliteData = Dem_Satellite_GetSatelliteData(SatelliteId, MonitorId);
    lNewSatelliteData = lOldSatelliteData;
    lDebounceInfoPtr = Dem_Debounce_DebounceInfoInit(lEventId, &lDebounceInfoData, lOldSatelliteData);

    lNewSatelliteData = Dem_Debounce_RestoreDebounceValue(lDebounceInfoPtr, lNewSatelliteData, Value, ExpectedThreshold);
    lNewSatelliteData = Dem_EventQueue_ResetQueueStatus(lNewSatelliteData);
  }
  while (Dem_SatelliteSat_SyncSetSatelliteData(SatelliteId, MonitorId, lOldSatelliteData, lNewSatelliteData) == FALSE);
}
#endif

/* ****************************************************************************
 % Dem_Satellite_GetDebounceValue
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_Debounce_DataType, DEM_CODE)
Dem_Satellite_GetDebounceValue(                                                                                                  /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONST(Dem_Satellite_IdType, AUTOMATIC)  SatelliteId,
  CONST(Dem_Satellite_MonitorIdType, AUTOMATIC)  MonitorId
  )
{
  Dem_SatelliteData_DataType lSatelliteData;                                                                                     /* PRQA S 0759 */ /* MD_MSR_18.4 */

  lSatelliteData = Dem_Satellite_GetSatelliteData(SatelliteId, MonitorId);
  return Dem_SatelliteData_GetDebounceData(lSatelliteData);
}

/* ****************************************************************************
 % Dem_Satellite_GetInitState
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_Satellite_GetInitState(
  CONST(Dem_Satellite_IdType, AUTOMATIC)  SatelliteId
  )
{
  Dem_SatelliteInfo_Type lSatelliteInfo;                                                                                         /* PRQA S 0759 */ /* MD_MSR_18.4 */

  lSatelliteInfo = Dem_Satellite_GetSatelliteInfo(SatelliteId);
  return Dem_SatelliteInfo_GetInitStatus(lSatelliteInfo);
}

/* ****************************************************************************
 % Dem_Satellite_GetMonitorStatus
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_MonitorStatusType, DEM_CODE)
Dem_Satellite_GetMonitorStatus(
  CONST(Dem_Satellite_IdType, AUTOMATIC)  SatelliteId,
  CONST(Dem_Satellite_MonitorIdType, AUTOMATIC)  MonitorId
  )
{
  Dem_SatelliteData_DataType lSatelliteData;                                                                                     /* PRQA S 0759 */ /* MD_MSR_18.4 */

  lSatelliteData = Dem_Satellite_GetSatelliteData(SatelliteId, MonitorId);
  return Dem_Monitor_GetMonitorStatus(lSatelliteData);
}

/* ****************************************************************************
 % Dem_Satellite_GetCurrentSatelliteId
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_Satellite_IdType, DEM_CODE)
Dem_Satellite_GetCurrentSatelliteId(
  void
  )
{
  Dem_Satellite_IdType lSatelliteId;
#if (DEM_CFG_SUPPORT_MULTIPLE_SATELLITES == STD_ON)
  {
    ApplicationType lCurrentApplication;
    lCurrentApplication = GetCurrentApplicationID();

    for (lSatelliteId = 0;
         lSatelliteId < Dem_Cfg_GlobalSatelliteCount();
         ++lSatelliteId)
    {
      if (Dem_Satellite_GetApplicationId(lSatelliteId) == lCurrentApplication)
      {
        break;
      }
    }
#if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
    if (lSatelliteId == Dem_Cfg_GlobalSatelliteCount())
    {
      Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
      lSatelliteId = DEM_SATELLITE_APPLICATION_ZERO;
    }
#endif
  }

#else
  lSatelliteId = DEM_SATELLITE_APPLICATION_ZERO;
#endif
  return lSatelliteId;
}

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* DEM_SATELLITE_IMPLEMENTATION_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_Satellite_Implementation.h
 *********************************************************************************************************************/
