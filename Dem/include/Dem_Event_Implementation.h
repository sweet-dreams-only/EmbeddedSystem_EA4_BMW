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
/*! \defgroup   Dem_Event Event
 *  \{
 *  \file       Dem_Event_Implementation.h
 *  \brief      Diagnostic Event Manager (Dem) header file
 *  \details    Implementation of the Event subcomponent
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

#if !defined (DEM_EVENT_IMPLEMENTATION_H)
#define DEM_EVENT_IMPLEMENTATION_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                  /* Own subcomponent header */
/* ------------------------------------------------------------------------- */
#include "Dem_Event_Interface.h"

                                                    /* Used subcomponent API */
/* ------------------------------------------------------------------------- */

#include "Dem_UDSStatus_Implementation.h"
#include "Dem_EventInternalStatus_Implementation.h"
#include "Dem_DTC_Implementation.h"
#include "Dem_DTCInternalStatus_Implementation.h"
#include "Dem_StorageCondition_Implementation.h"
#include "Dem_InitState_Implementation.h"
#include "Dem_MemoryEntry_Implementation.h"
#include "Dem_Scheduler_Implementation.h"
#include "Dem_DtrIF_Implementation.h"
#include "Dem_OperationCycle_Implementation.h"
#include "Dem_Memory_Implementation.h"
#include "Dem_MemStorageManager_Implementation.h"
#include "Dem_Nvm_Implementation.h"
#include "Dem_Prestore_Implementation.h"
#include "Dem_Esm_Implementation.h"

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
 * \addtogroup Dem_Event_Properties
 * \{
 */

/* ****************************************************************************
 % Dem_Event_TestValidHandle
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Event_TestValidHandle(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  )
{
  return (boolean)( (EventId != DEM_EVENT_INVALID)                                                                               /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
                 && (EventId < Dem_Cfg_GlobalEventCount()) );
}

#if (DEM_CFG_SUPPORT_OBDII == STD_ON)
/* ****************************************************************************
 % Dem_Event_TestMilSupport
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Event_TestMilSupport(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  )
{
  return (Dem_Cfg_GlobalMilIndicator() == Dem_Cfg_EventSpecialIndicator(EventId));
}
#endif

/* ****************************************************************************
 % Dem_Event_GetInternalStatus
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_Event_InternalStatusType, DEM_CODE)
Dem_Event_GetInternalStatus(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  )
{
  return Dem_Cfg_GetEventInternalStatus(EventId);
}

/* ****************************************************************************
 % Dem_Event_SetInternalStatus
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Event_SetInternalStatus(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(Dem_Event_InternalStatusType, AUTOMATIC)  Status
  )
{
#if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (EventId >= Dem_Cfg_GlobalEventCount())
  {
    Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
  }
  else
#endif
  {
    Dem_Cfg_SetEventInternalStatus(EventId, Status);                                                                             /* SBSW_DEM_ARRAY_WRITE_EVENTINTERNALSTATUS */
  }
}

/* Extended internal status  --------------------- */
/* ****************************************************************************
 % Dem_Event_GetExtendedStatus
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_Event_GetExtendedStatus(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  )
{
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(EventId)                                                                                      /* PRQA S 3112 */ /* MD_DEM_14.2 */
#if (DEM_FEATURE_NEED_PID01_CALCULATION == STD_ON) || (DEM_CFG_SUPPORT_SIMILAR_CONDITIONS == STD_ON)
  /* Return extended status of event  */
  return Dem_Cfg_StatusData.ExtendedEventStatus[EventId];
#else
  return DEM_EXT_STATUS_INITIALIZE;
#endif
}

/* ****************************************************************************
 % Dem_Event_SetExtendedStatus
 *****************************************************************************/
/*!
* Internal comment removed.
 *
 *
*/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Event_SetExtendedStatus(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(uint8, AUTOMATIC)  Status
  )
{
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(EventId)                                                                                      /* PRQA S 3112 */ /* MD_DEM_14.2 */
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(Status)                                                                                       /* PRQA S 3112 */ /* MD_DEM_14.2 */

#if (DEM_FEATURE_NEED_PID01_CALCULATION == STD_ON) || (DEM_CFG_SUPPORT_SIMILAR_CONDITIONS == STD_ON)
# if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (EventId >= Dem_Cfg_GlobalEventCount())
  {
    Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
  }
  else
# endif
  {
    /* Set extended status of event */
    Dem_Cfg_StatusData.ExtendedEventStatus[EventId] = Status;
  }
#endif
}

#if (DEM_FEATURE_NEED_TRIPCOUNTER == STD_ON)
/* ****************************************************************************
 % Dem_Event_GetTripCount
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
   */
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_Event_GetTripCount(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  )
{
  return Dem_Cfg_StatusData.TripCount[EventId];
}
#endif

#if (DEM_FEATURE_NEED_TRIPCOUNTER == STD_ON)
/* ****************************************************************************
 % Dem_Event_SetTripCount
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Event_SetTripCount(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(uint8, AUTOMATIC)  TripCount
  )
{
# if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (EventId >= Dem_Cfg_GlobalEventCount())
  {
    Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
  }
  else
# endif
  {
    Dem_Cfg_StatusData.TripCount[EventId] = TripCount;                                                                           /* SBSW_DEM_ARRAY_WRITE_STATUSDATA_TRIPCOUNT */
  }
}
#endif

#if (DEM_FEATURE_NEED_OBD == STD_ON)
/* ****************************************************************************
 % Dem_Event_GetQualifyStatus
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_Event_GetQualifyStatus(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  )
{
# if (DEM_CFG_PROCESS_CDTC_ALL_DTC == STD_ON)
  return Dem_Cfg_StatusData.State[EventId];
# else
  return Dem_Cfg_GetEventCycleStatus(EventId);
# endif
}
#endif

#if (DEM_FEATURE_NEED_OBD == STD_ON)
/* ****************************************************************************
 % Dem_Event_SetQualifyStatus
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Event_SetQualifyStatus(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(uint8, AUTOMATIC)  Status
  )
{
# if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (EventId >= Dem_Cfg_GlobalEventCount())
  {
    Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);                                                                            /* SBSW_DEM_POINTER_RUNTIME_CHECK */
  }
  else
# endif
  {
# if (DEM_CFG_PROCESS_CDTC_ALL_DTC == STD_ON)
    Dem_Cfg_GetStatusData().State[EventId] = Status;
# else
    Dem_Cfg_SetEventCycleStatus(EventId, Status);
# endif
  }
}
#endif

/* ****************************************************************************
 % Dem_Event_GetUDSStatus
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_UDSStatus_Type, DEM_CODE)
Dem_Event_GetUDSStatus(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  )
{
  return Dem_Cfg_GetStatusData().EventStatus[EventId];
}

/* ****************************************************************************
 % Dem_Event_SetUDSStatus
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Event_SetUDSStatus(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(Dem_UDSStatus_Type, AUTOMATIC)  Status
  )
{
#if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (EventId >= Dem_Cfg_GlobalEventCount())
  {
    Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
  }
  else
#endif
  {
    Dem_Cfg_GetStatusData().EventStatus[EventId] = Status;                                                                       /* SBSW_DEM_ARRAY_WRITE_STATUSDATA_EVENTSTATUS */
  }
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
 * \addtogroup Dem_Event_Private
 * \{
 */

#if (DEM_FEATURE_NEED_IMMEDIATEHEAL == STD_ON)
/* ****************************************************************************
 % Dem_Event_Passed_ProcessHealing
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
Dem_Event_Passed_ProcessHealing(
  CONSTP2VAR(Dem_Event_ContextType, AUTOMATIC, AUTOMATIC) EventContext                                                           /* PRQA S 3673 */ /* MD_DEM_16.7_Design */
  )
{
  if (Dem_Cfg_EventHealingTarget(EventContext->EventId) == 0)
  {
    Dem_UDSStatus_Type lNewEventStatus;
    lNewEventStatus = EventContext->NewEventStatus;
    /* Remove WarningIndicatorReq bit with the first 'TestPassed' result */
# if (DEM_FEATURE_NEED_MULTIHEAL == STD_ON) && (DEM_CFG_AGING_AFTER_HEALING_ALL_DTC == STD_ON)
    Dem_Event_SetTripCount(EventContext->EventId, 0);
# endif

    if (Dem_UDSStatus_Test_WIR(EventContext->OldEventStatus) == TRUE)
    {
# if (DEM_FEATURE_NEED_MULTIHEAL == STD_ON) && (DEM_CFG_AGING_AFTER_HEALING_ALL_DTC == STD_OFF)
      Dem_Event_SetTripCount(EventContext->EventId, 0);
# endif
      lNewEventStatus = Dem_Event_Healed(EventContext->EventId, lNewEventStatus);
    }
# if (DEM_FEATURE_NEED_MULTIHEAL == STD_ON) && (DEM_FEATURE_NEED_AGING_AFTER_HEALING_MIL_ONLY == STD_ON)
    else
    if (Dem_Cfg_EventObdRelated(EventContext->EventId) == TRUE)
    {
      /* Obd relevant events have to heal before they can age */
      Dem_Event_SetTripCount(EventContext->EventId, 0);
    }
    else
    {
      /* Nothing to do */
    }
# endif
    EventContext->NewEventStatus = lNewEventStatus;                                                                              /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
  }
}                                                                                                                                /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
#endif /* DEM_FEATURE_NEED_IMMEDIATEHEAL == STD_ON */

/* ****************************************************************************
 % Dem_Event_TestConfirmed
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
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Event_TestConfirmed(
  CONSTP2VAR(Dem_Event_ContextType, AUTOMATIC, AUTOMATIC) EventContext                                                           /* PRQA S 3673 */ /* MD_DEM_16.7_Design */
  )
{
  boolean lReturnValue;
  lReturnValue = FALSE;

  /* event is configured as single-trip*/
  if (Dem_Cfg_EventTripTarget(EventContext->EventId) == 0)
  {
    lReturnValue = TRUE;
  }
  else
  {
    if (Dem_EventInternalStatus_TestSimilarConditions(Dem_Event_GetExtendedStatus(EventContext->EventId)) == TRUE)
    {
#if (DEM_FEATURE_NEED_MIL_GROUPS == STD_ON)                                                                                      /* COV_MSR_UNSUPPORTED XF */
      if (Dem_Cfg_EventMilGroupIndex(EventContext->EventId) != DEM_CFG_MIL_GROUP_INVALID)
      {
        if (Dem_Mem_GetMilGroupTripCount(Dem_Cfg_EventMilGroupIndex(EventContext->EventId)) >= Dem_Cfg_EventTripTarget(EventContext->EventId))
        {
          /* MIL Group is used and MIL group tripped */
          lReturnValue = TRUE;
        }
        /* else: event has a MIL group, but the group has not tripped yet */
      }
      else
#endif
      {
#if (DEM_FEATURE_NEED_MULTITRIP == STD_ON)
        if (Dem_Event_GetTripCount(EventContext->EventId) >= Dem_Cfg_EventTripTarget(EventContext->EventId))
        {
          /* multi-trip target reached */
          lReturnValue = TRUE;
        }
#else
        if ( ((Dem_UDSStatus_Test_PDTC(EventContext->OldEventStatus)) == TRUE)                                                   /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
          && ((Dem_UDSStatus_Test_TFTOC(EventContext->OldEventStatus)) == FALSE) )
        {
          /* event has tripped twice */
          lReturnValue = TRUE;
        }
#endif
      }
    }
  }

  return lReturnValue;
}

/* ****************************************************************************
 % Dem_Event_OpCycleStart
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
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Event_OpCycleStart(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  )
{
  uint8 lOldEventStatus;
  uint8 lNewEventStatus;

  lOldEventStatus = Dem_Event_GetUDSStatus(EventId);

  lNewEventStatus = lOldEventStatus;
#if (DEM_CFG_SUPPORT_CLEAR_TESTFAILED_ON_OPCYCLE == STD_ON)
  lNewEventStatus = Dem_UDSStatus_Reset_TF(lNewEventStatus);
#endif
  lNewEventStatus = Dem_UDSStatus_Reset_TFTOC(lNewEventStatus);
  lNewEventStatus = Dem_UDSStatus_Set_TNCTOC(lNewEventStatus);

  Dem_Event_SetUDSStatus(EventId, lNewEventStatus);

#if (DEM_CFG_SUPPORT_IUMPR == STD_ON)
  {
    Dem_RatioIdIndexType lRatioIndex;
    lRatioIndex = Dem_Cfg_EventRatioIdIdx(EventId);

    if (lRatioIndex != DEM_CFG_RATIOINDEX_INVALID)
    {
      /* reset all status bits of this ratio to the following setting:
       * - denominator not incremented
       * - denominator conditions not fulfilled
       * - denominator not locked
       * - numerator not incremented
       * - numerator conditions not fulfilled (no fault detected / detectable)
       * - ratio not locked by suppression
       * - ratio not locked by pending FID
       */
      Dem_Mem_SetIumprStatus(lRatioIndex, 0);
    }
  }
#endif

#if ( (DEM_FEATURE_NEED_OBD == STD_ON) && (DEM_FEATURE_NEED_CYCLEAUTOMATICEND == STD_ON) \
   || (DEM_CFG_SUPPORT_RESTART_CYCLE == STD_ON) )                                                                                /* COV_MSR_UNSUPPORTED TF xf tf tf */
  if (Dem_InitState_TestMasterInState(DEM_INITSTATE_INITIALIZED) == TRUE)
#endif
  {
    Dem_SatelliteCore_RestartEvent(
        Dem_Cfg_EventSatelliteId(EventId),
        Dem_Cfg_EventSatelliteEventId(EventId));

/* >>>> -------------------------------- Enter Critical Section: DiagMonitor */
    Dem_EnterCritical_DiagMonitor();                                                                                             /* PRQA S 3109 */ /* MD_MSR_14.3 */

    Dem_Event_SetExtendedStatus(EventId, 
      Dem_EventInternalStatus_ResetSimilarConditions(
        Dem_Event_GetExtendedStatus(EventId)
      )
    );

#if (DEM_CFG_SUPPORT_TRIGGER_FDC_FIRST_IN_CYCLE == STD_ON)
    {
      Dem_Event_InternalStatusType lInternalStatus;

      lInternalStatus = Dem_Event_GetInternalStatus(EventId);
      lInternalStatus = Dem_DTCInternalStatus_ResetFdcToc(lInternalStatus);
      Dem_Event_SetInternalStatus(EventId, lInternalStatus);
    }
#endif

    Dem_LeaveCritical_DiagMonitor();                                                                                             /* PRQA S 3109 */ /* MD_MSR_14.3 */
/* <<<< -------------------------------- Leave Critical Section: DiagMonitor */
  }

}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */

/* ****************************************************************************
 % Dem_Event_ProcessHealing
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
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_Event_ProcessHealing(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(uint8, AUTOMATIC)  EventStatus
  )
{
  uint8 lNewEventStatus;

  lNewEventStatus = EventStatus;

#if (DEM_FEATURE_NEED_MULTIHEAL == STD_ON)
  if (Dem_Event_GetTripCount(EventId) < 0xffU)
  {
    Dem_Event_SetTripCount(EventId, (uint8)(Dem_Event_GetTripCount(EventId) + 1));
  }
  if (Dem_Event_GetTripCount(EventId) >= Dem_Cfg_EventHealingTarget(EventId))
  {
    lNewEventStatus = Dem_Event_Healed(EventId, EventStatus);
  }
#else
  if (Dem_UDSStatus_Test_WIR(EventStatus) == TRUE)
  { /* Healing target reached -> heal all related indicators */
    lNewEventStatus = Dem_Event_Healed(EventId, lNewEventStatus);
  }
#endif

  return lNewEventStatus;
}

/* ****************************************************************************
 % Dem_Event_OpCycleEnd_Healing
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
DEM_LOCAL FUNC(boolean, DEM_CODE)
Dem_Event_OpCycleEnd_Healing(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(uint8, AUTOMATIC)  EventStatus
  )
{
  boolean lEventMayAge;
  uint8 lNewEventStatus;

  lEventMayAge = FALSE;
  lNewEventStatus = EventStatus;

  if (Dem_UDSStatus_Test_TNCTOC(lNewEventStatus) == FALSE)
  {
    if (Dem_UDSStatus_Test_TFTOC(lNewEventStatus) == FALSE)
    { /* Event tested this operation cycle and was not failed, reset pending state */
#if (DEM_FEATURE_NEED_MULTIHEAL == STD_ON) || (DEM_FEATURE_NEED_MIL_GROUPS == STD_ON)
      if (Dem_UDSStatus_Test_PDTC(lNewEventStatus) == TRUE)
      {
# if (DEM_FEATURE_NEED_MULTIHEAL == STD_ON)
        Dem_Event_SetTripCount(EventId, 0);
# endif
# if (DEM_FEATURE_NEED_MIL_GROUPS == STD_ON)
        /* pending bit was set before and is now reset: reduce number of pending events in MIL group */
        if (Dem_Cfg_EventMilGroupIndex(EventId) != DEM_CFG_MIL_GROUP_INVALID)
        {
#  if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
          if (Dem_EventInternalStatus_GetMilGroupPendingCount(Dem_Cfg_EventMilGroupIndex(EventId)) <= 0)
          {
            Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
          }
#  endif
          Dem_Mem_DecrementMilGroupPendingCount(Dem_Cfg_EventMilGroupIndex(EventId));
        }
# endif

# if (DEM_FEATURE_NEED_PID01_CALCULATION  == STD_ON)
        if (Dem_Esm_TestPid01ReadinessState(Dem_Queue_Pid01UpdateFlag, Dem_Cfg_EventReadinessGroup(EventId)) == FALSE)
        {
/* >>>> -------------------------------- Enter Critical Section: DiagMonitor */
          Dem_EnterCritical_DiagMonitor();                                                                                       /* PRQA S 3109 */ /* MD_MSR_14.3 */
          Dem_Queue_Pid01UpdateFlag = Dem_Esm_SetPid01ReadinessState(Dem_Queue_Pid01UpdateFlag, Dem_Cfg_EventReadinessGroup(EventId));
          Dem_LeaveCritical_DiagMonitor();                                                                                       /* PRQA S 3109 */ /* MD_MSR_14.3 */
/* <<<< -------------------------------- Leave Critical Section: DiagMonitor */
        }
# endif
      }
#endif
      lNewEventStatus = Dem_UDSStatus_Reset_PDTC(lNewEventStatus);
      lNewEventStatus = Dem_Event_ProcessHealing(EventId, lNewEventStatus);

#if (DEM_FEATURE_NEED_HEALING == STD_ON) && (DEM_FEATURE_NEED_AGING_AFTER_HEALING == STD_ON)
      if ( (Dem_Event_TestEventHealed(EventId, lNewEventStatus) == TRUE)                                                         /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
# if (DEM_FEATURE_NEED_AGING_AFTER_HEALING_MIL_ONLY == STD_ON)                                                                   /* COV_MSR_UNSUPPORTED XF */
        || (Dem_Cfg_GlobalMilIndicator() != Dem_Cfg_EventSpecialIndicator(EventId))
# endif
        )
#endif
#if (DEM_FEATURE_NEED_AGING_AFTER_HEALING == STD_ON)
      {
        lEventMayAge = TRUE;
      }
#endif
    }
#if (DEM_FEATURE_NEED_MIL_GROUPS == STD_ON)                                                                                      /* COV_MSR_UNSUPPORTED XF */
    /* test failed; check if MIL group exists */
    else
      if (Dem_Cfg_EventMilGroupIndex(EventId) != DEM_CFG_MIL_GROUP_INVALID)
      {
        /* increment MIL group trip counter once per DCY if trip target has not yet been reached */
        if (Dem_Mem_GetMilGroupTripCount(Dem_Cfg_EventMilGroupIndex(EventId)) < Dem_Cfg_EventTripTarget(EventId))
        {
          if (Dem_Mem_GetMilGroupIncremented(Dem_Cfg_EventMilGroupIndex(EventId)) == FALSE)
          {
            Dem_Mem_IncrementMilGroupTripCount(Dem_Cfg_EventMilGroupIndex(EventId));
            Dem_Mem_SetMilGroupIncremented(Dem_Cfg_EventMilGroupIndex(EventId));
          }
        }
      }
#endif
#if (DEM_FEATURE_NEED_MULTITRIP == STD_ON)
      else
      {
        /* test failed: increment trip counter if trip target has not yet been reached */
        if (Dem_Event_GetTripCount(EventId) < Dem_Cfg_EventTripTarget(EventId))
        {
          Dem_Event_SetTripCount(EventId, (uint8)(Dem_Event_GetTripCount(EventId) + 1));
        }
      }
#endif

    Dem_Event_SetUDSStatus(EventId, lNewEventStatus);
  }

  return lEventMayAge;
}                                                                                                                                /* PRQA S 6030, 6050, 6080 */ /* MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* ****************************************************************************
 % Dem_Event_OpCycleEnd
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
Dem_Event_OpCycleEnd(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(uint8, AUTOMATIC)  OldDtcStatus                                                                                          /* PRQA S 3206 */ /* MD_DEM_3206 */
)
{
  uint8 lEventStatus;
#if (DEM_FEATURE_NEED_AGING_AFTER_HEALING == STD_ON)
  boolean lEventMayAge;
#endif

  /* Argument unused in some configurations */
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(OldDtcStatus)                                                                                 /* PRQA S 3112 */ /* MD_DEM_14.2 */

  lEventStatus = Dem_Event_GetUDSStatus(EventId);

  if (Dem_EventInternalStatus_TestSimilarConditions(Dem_Event_GetExtendedStatus(EventId)) == TRUE)
  {
#if (DEM_FEATURE_NEED_AGING_AFTER_HEALING == STD_ON)
    lEventMayAge = Dem_Event_OpCycleEnd_Healing(EventId, lEventStatus);
#else
    (void)Dem_Event_OpCycleEnd_Healing(EventId, lEventStatus);
#endif
  }
  else
  {
#if (DEM_FEATURE_NEED_AGING_AFTER_HEALING == STD_ON)
    lEventMayAge = FALSE;
#endif
  }

#if (DEM_FEATURE_NEED_AGING_TRIGGER_CYCLE == STD_ON) || (DEM_FEATURE_NEED_AGING_AFTER_HEALING == STD_ON)
# if (DEM_FEATURE_NEED_AGING_AFTER_HEALING == STD_ON)
  if (lEventMayAge == TRUE)
# endif
  {
    Dem_DTC_OpCycleEnd_Aging(EventId, OldDtcStatus);
  }
#endif
}

/* ****************************************************************************
 % Dem_Event_InitEventContext
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Event_InitEventContext(
CONST(Dem_EventIdType, AUTOMATIC)  EventId,
CONSTP2VAR(Dem_Event_ContextType, AUTOMATIC, AUTOMATIC) EventContext
)
{
  EventContext->EventId = EventId;
  EventContext->OldEventStatus = Dem_Event_GetUDSStatus(EventId);
  EventContext->NewEventStatus = EventContext->OldEventStatus;
  EventContext->EventEffects = DEM_CFG_TRIGGER_NONE;
  EventContext->DataModified = FALSE;
}

/* ****************************************************************************
 % Dem_Event_CalculateStatusOnFailed
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Event_CalculateStatusOnFailed(
CONSTP2VAR(Dem_Event_ContextType, AUTOMATIC, AUTOMATIC) EventContext
)
{
    /* Process the deferred 'asynchronous' status bit transitions for the event */
  EventContext->NewEventStatus = Dem_UDSStatus_Set_TFTOC(EventContext->NewEventStatus);
  EventContext->NewEventStatus = Dem_UDSStatus_Set_TF(EventContext->NewEventStatus);
#if (DEM_CFG_PROCESS_TFSLC_STOREDONLY == STD_OFF)
  EventContext->NewEventStatus = Dem_UDSStatus_Set_TFSLC(EventContext->NewEventStatus);
#endif
  EventContext->NewEventStatus = Dem_UDSStatus_Reset_TNCSLC(EventContext->NewEventStatus);
  EventContext->NewEventStatus = Dem_UDSStatus_Reset_TNCTOC(EventContext->NewEventStatus);

  Dem_Event_SetUDSStatus(EventContext->EventId, EventContext->NewEventStatus);
}

/* ****************************************************************************
 % Dem_Event_CalculateFailedEffects
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Event_CalculateFailedEffects(
CONSTP2VAR(Dem_Event_ContextType, AUTOMATIC, AUTOMATIC) EventContext
)
{
  #if (DEM_CFG_SUPPORT_RETRY_STORAGE == STD_ON)
  /* If event is not stored already */
  if (Dem_DTC_TestStoredStatus(EventContext->EventId) == FALSE)
  {
    EventContext->EventEffects = (uint8)(EventContext->EventEffects | DEM_CFG_TRIGGER_TESTFAILED);
    EventContext->EventEffects = (uint8)(EventContext->EventEffects | DEM_CFG_TRIGGER_TESTFAILEDTHISCYCLE);
    EventContext->EventEffects = (uint8)(EventContext->EventEffects | DEM_CFG_TRIGGER_FIRSTTHISCYCLE);
  }
  else
#endif
  {
    /* Derive the triggers for the event from the changes of the status bits */
    if (Dem_UDSStatus_Test_TF(EventContext->OldEventStatus) == FALSE)
    {
      EventContext->EventEffects = (uint8)(EventContext->EventEffects | DEM_CFG_TRIGGER_TESTFAILED);
    }
    if (Dem_UDSStatus_Test_TFTOC(EventContext->OldEventStatus) == FALSE)
    {
      EventContext->EventEffects = (uint8)(EventContext->EventEffects | DEM_CFG_TRIGGER_TESTFAILEDTHISCYCLE);
      EventContext->EventEffects = (uint8)(EventContext->EventEffects | DEM_CFG_TRIGGER_FIRSTTHISCYCLE);
    }
  }
}

/* ****************************************************************************
 % Dem_Event_CalculateStatusOnFailed_OnStorage
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Event_CalculateStatusOnFailed_OnStorage(
CONSTP2VAR(Dem_Event_ContextType, AUTOMATIC, AUTOMATIC) EventContext
)
{
#if (DEM_CFG_PROCESS_TFSLC_STOREDONLY == STD_ON)
  if (Dem_DTC_TestStoredStatus(EventContext->EventId) == TRUE)
  {
    EventContext->NewEventStatus = Dem_UDSStatus_Set_TFSLC(EventContext->NewEventStatus);                                        /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
  }
#endif

  if ((EventContext->EventEffects & DEM_CFG_TRIGGER_PENDING) != 0)
  {
    EventContext->NewEventStatus = Dem_UDSStatus_Set_PDTC(EventContext->NewEventStatus);                                         /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
  }
  if ((EventContext->EventEffects & DEM_CFG_TRIGGER_CONFIRMED) != 0)
  {
    EventContext->NewEventStatus = Dem_UDSStatus_Set_CDTC(EventContext->NewEventStatus);                                         /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
  }
  if ((EventContext->EventEffects & DEM_CFG_TRIGGER_INDICATOR) != 0)
  {
    EventContext->NewEventStatus = Dem_UDSStatus_Set_WIR(EventContext->NewEventStatus);                                          /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
  }
  Dem_Event_SetUDSStatus(EventContext->EventId, EventContext->NewEventStatus);
}

/* ****************************************************************************
 % Dem_Event_CalculateFailedEffects_OnStorage
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
 */

DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Event_CalculateFailedEffects_OnStorage(
  CONSTP2VAR(Dem_Event_ContextType, AUTOMATIC, AUTOMATIC) EventContext
  )
{
  {
    /* Calculate effects for 'Pending' bit*/
    if (Dem_UDSStatus_Test_PDTC(EventContext->OldEventStatus) == FALSE)
    {
      /* Not yet pending, set pending independently of TFTOC */
      EventContext->EventEffects = (uint8)(EventContext->EventEffects | DEM_CFG_TRIGGER_PENDING);                                /* SBSW_DEM_POINTER_WRITE_ARGUMENT */

  #if (DEM_FEATURE_NEED_MULTITRIP == STD_ON)
      /* Initialize trip counter */
      Dem_Event_SetTripCount(EventContext->EventId, 0);
  #endif

  #if (DEM_FEATURE_NEED_MIL_GROUPS == STD_ON)                                                                                    /* COV_MSR_UNSUPPORTED XF */
      /* increment number of MIL group events that are pending (at most 127 are possible) */
      if (Dem_Cfg_EventMilGroupIndex(EventContext->EventId) != DEM_CFG_MIL_GROUP_INVALID)
      {
  # if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
        if (Dem_EventInternalStatus_GetMilGroupPendingCount(Dem_Cfg_EventMilGroupIndex(EventContext->EventId)) >= 0x7Fu)
        {
          Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
        }
  # endif
        Dem_Mem_IncrementMilGroupPendingCount(Dem_Cfg_EventMilGroupIndex(EventContext->EventId));
      }
  #endif
    }
  #if (DEM_CFG_SUPPORT_RETRY_STORAGE == STD_ON) && (DEM_CFG_PROCESS_PDTC_ALL_DTC == STD_ON)
    else if (Dem_DTC_TestStoredStatus(EventContext->EventId) == FALSE)
    {
      EventContext->EventEffects = (uint8)(EventContext->EventEffects | DEM_CFG_TRIGGER_PENDING);                                /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    }
  #endif
    else
    {
      /* Nothing to do */
    }
  }

  {
    /* Calculate effects for 'Confirmed' and 'WIR' bit*/
    boolean lEventConfirmed;
    lEventConfirmed = Dem_Event_TestConfirmed(EventContext);                                                                     /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
    if (lEventConfirmed == TRUE)
    { /* Event has confirmed */
  #if (DEM_FEATURE_NEED_INDICATORS == STD_ON)
      if (Dem_UDSStatus_Test_WIR(EventContext->OldEventStatus) == FALSE)
      {
        Dem_Cfg_EventIndicatorIterType lIndicatorIter;

        Dem_Cfg_EventIndicatorIterInit(EventContext->EventId, &lIndicatorIter);                                                  /* SBSW_DEM_CALL_ITERATOR_POINTER */
        if ( (Dem_Cfg_EventIndicatorIterExists(&lIndicatorIter) == TRUE)                                                         /* PRQA S 3415 */ /* MD_DEM_12.4_cf */ /* SBSW_DEM_CALL_ITERATOR_POINTER */
          || (Dem_Cfg_EventSpecialIndicator(EventContext->EventId) != DEM_CFG_SPECIAL_INDICATOR_NONE) )
        {
          EventContext->EventEffects = (uint8)(EventContext->EventEffects | DEM_CFG_TRIGGER_INDICATOR);                          /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
        }
      }
  #endif

      if (Dem_UDSStatus_Test_CDTC(EventContext->OldEventStatus) == FALSE)
      {
        EventContext->EventEffects = (uint8)(EventContext->EventEffects | DEM_CFG_TRIGGER_CONFIRMED);                            /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
      } /* else: No transition for confirmed dtc, so no update */
  #if (DEM_CFG_SUPPORT_RETRY_STORAGE == STD_ON) && (DEM_CFG_PROCESS_CDTC_ALL_DTC == STD_ON)
      else if (Dem_DTC_TestStoredStatus(EventContext->EventId) == FALSE)
      {
        EventContext->EventEffects = (uint8)(EventContext->EventEffects | DEM_CFG_TRIGGER_CONFIRMED);                            /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
      }
  #endif
      else
      {
        /* Nothing to do */
      }
    } /* else: not yet confirmed, no further action */
  }
}                                                                                                                                /* PRQA S 6050, 6080 */ /* MD_MSR_STCAL, MD_MSR_STMIF */

/* ****************************************************************************
 % Dem_Event_ProcessFailedEffects
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
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Event_ProcessFailedEffects(
CONSTP2CONST(Dem_Event_ContextType, AUTOMATIC, AUTOMATIC) EventContext
)
{
#if (DEM_FEATURE_NEED_SPECIAL_INDICATORS == STD_ON)                                                                              /* COV_MSR_UNSUPPORTED XF */
  uint8 lSpecialIndicator;
# if (DEM_FEATURE_NEED_GLOBAL_MIL_STATE == STD_ON)
  boolean lOldMilIsActive;
  lOldMilIsActive = Dem_Indicator_TestMilIsActive();
# endif
  lSpecialIndicator = DEM_CFG_SPECIAL_INDICATOR_NONE;
#endif /* (DEM_FEATURE_NEED_SPECIAL_INDICATORS == STD_ON) */

#if (DEM_FEATURE_NEED_OBD == STD_ON)                                                                                             /* COV_MSR_UNSUPPORTED XF */
  if (Dem_Cfg_EventObdRelated(EventContext->EventId) == TRUE)
  {
    Dem_Event_QualifyStatus(EventContext->EventId, EventContext->EventEffects);
  }
#endif

#if (DEM_FEATURE_NEED_INDICATORS == STD_ON)
  if ((EventContext->EventEffects & DEM_CFG_TRIGGER_INDICATOR) != 0)
  {
# if (DEM_FEATURE_NEED_OBD == STD_ON)                                                                                            /* COV_MSR_UNSUPPORTED XF */
    /* Suppress the Indicators if the driving cycle is not qualified yet */
    if (Dem_EventInternalStatus_Test_QualifyStatus_WIR(Dem_Event_GetQualifyStatus(EventContext->EventId)) == TRUE)
# endif /* (DEM_FEATURE_NEED_OBD == STD_ON) */
    {
/* >>>> -------------------------------- Enter Critical Section: DiagMonitor */
      Dem_EnterCritical_DiagMonitor();                                                                                           /* PRQA S 3109 */ /* MD_MSR_14.3 */

# if (DEM_CFG_SUPPORT_USER_INDICATORS == STD_ON)                                                                                 /* COV_MSR_UNSUPPORTED TX */
      Dem_Esm_UserIndicatorEnable(EventContext->EventId);
# endif
# if (DEM_FEATURE_NEED_SPECIAL_INDICATORS == STD_ON)                                                                             /* COV_MSR_UNSUPPORTED XF */
      lSpecialIndicator = Dem_Esm_SpecialIndicatorEnable(EventContext->EventId);
# endif
      Dem_LeaveCritical_DiagMonitor();                                                                                           /* PRQA S 3109 */ /* MD_MSR_14.3 */
/* <<<< -------------------------------- Leave Critical Section: DiagMonitor */
    }
  }
#endif /* (DEM_FEATURE_NEED_INDICATORS == STD_ON) */

#if (DEM_FEATURE_NEED_SPECIAL_INDICATORS == STD_ON)                                                                              /* COV_MSR_UNSUPPORTED XF */
  if ((EventContext->EventEffects & DEM_CFG_TRIGGER_INDICATOR) != 0)
  {
    if (lSpecialIndicator != DEM_CFG_SPECIAL_INDICATOR_NONE)
    { /* Special indicator was modified, recalculate new state */
      Dem_Mem_UpdateGlobalSpecialIndicatorStates(lSpecialIndicator);
# if (DEM_FEATURE_NEED_OBD == STD_ON)
      if (Dem_Cfg_GlobalMilIndicator() == Dem_Cfg_EventSpecialIndicator(EventContext->EventId))
      {
#  if (DEM_FEATURE_NEED_GLOBAL_MIL_STATE == STD_ON)
        if ((lOldMilIsActive == FALSE)                                                                                           /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
          && (Dem_Indicator_TestMilIsActive() == TRUE))
        {
          Dem_Esm_GlobalMilStateEnable();
        }
#  endif
      }
# endif /* (DEM_FEATURE_NEED_OBD == STD_ON) */
    }
# if (DEM_CFG_SUPPORT_OBDII == STD_ON)
    if (Dem_Cfg_GlobalMilIndicator() == Dem_Cfg_EventSpecialIndicator(EventContext->EventId))
    { /* Always try to store a permanent DTC */
#  if (DEM_CFG_SUPPORT_PERMANENTDTC_ACTIVATION_DISTANCE == STD_ON)
      if (Dem_Mem_GetPermanentActivationState() != FALSE)
#  endif
      {
        Dem_Data_PermanentEntryAdd(EventContext->EventId);
      }
    }
# endif /* (DEM_CFG_SUPPORT_OBDII == STD_ON) */
  }
#endif /* (DEM_FEATURE_NEED_SPECIAL_INDICATORS == STD_ON) */
#if (DEM_CFG_SUPPORT_WWHOBD == STD_ON)                                                                                           /* COV_MSR_UNSUPPORTED XF */
  /* increment counter only if event initially becomes confirmed or
     if it is still confirmed and test failed changes from 0 to 1 */
  if (((EventContext->EventEffects & DEM_CFG_TRIGGER_CONFIRMED) != 0)                                                            /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
    || (((EventContext->EventEffects & DEM_CFG_TRIGGER_TESTFAILED) != 0)
    && (Dem_UDSStatus_Test_CDTC(EventContext->OldEventStatus) == TRUE)))
  {
    Dem_Esm_IncrementQualifiedActiveEventCount(EventContext->EventId);
  }
#endif
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(EventContext);                                                                                /* PRQA S 3112 */ /* MD_DEM_14.2 */
}                                                                                                                                /* PRQA S 6050, 6080 */ /* MD_MSR_STCAL, MD_MSR_STMIF */

/* ****************************************************************************
 % Dem_Event_CalculateStatusOnPassed
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Event_CalculateStatusOnPassed(
CONSTP2VAR(Dem_Event_ContextType, AUTOMATIC, AUTOMATIC) EventContext
)
{
  EventContext->NewEventStatus = Dem_UDSStatus_Reset_TF(EventContext->NewEventStatus);
  EventContext->NewEventStatus = Dem_UDSStatus_Reset_TNCSLC(EventContext->NewEventStatus);
  EventContext->NewEventStatus = Dem_UDSStatus_Reset_TNCTOC(EventContext->NewEventStatus);
}

/* ****************************************************************************
 % Dem_Event_Passed_CalcEventEffects
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Event_Passed_CalcEventEffects(
CONSTP2VAR(Dem_Event_ContextType, AUTOMATIC, AUTOMATIC) EventContext
)
{
  if (Dem_UDSStatus_Test_TF(EventContext->OldEventStatus) == TRUE)
  {
    EventContext->EventEffects = (uint8)(EventContext->EventEffects | DEM_CFG_TRIGGER_TESTPASSED);
  }
  if (Dem_UDSStatus_Test_TNCTOC(EventContext->OldEventStatus) == TRUE)
  {
    EventContext->EventEffects = (uint8)(EventContext->EventEffects | DEM_CFG_TRIGGER_FIRSTTHISCYCLE);
  }
}

/* ****************************************************************************
 % Dem_Event_ProcessPassedEffects
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Event_ProcessPassedEffects(
CONSTP2VAR(Dem_Event_ContextType, AUTOMATIC, AUTOMATIC) EventContext                                                             /* PRQA S 3673 */ /* MD_DEM_16.7_Internal */
)
{
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(EventContext);                                                                                /* PRQA S 3112 */ /* MD_DEM_14.2 */

  #if (DEM_CFG_SUPPORT_WWHOBD == STD_ON)                                                                                         /* COV_MSR_UNSUPPORTED XF */
  if ((EventContext->EventEffects & DEM_CFG_TRIGGER_TESTPASSED) != FALSE)
  {
    Dem_Esm_DecrementQualifiedActiveEventCount(EventContext->EventId, FALSE);
  }
#endif

#if (DEM_FEATURE_NEED_IMMEDIATEHEAL == STD_ON)
  if (Dem_EventInternalStatus_TestSimilarConditions(Dem_Event_GetExtendedStatus(EventContext->EventId)) == TRUE)
  {
    Dem_Event_Passed_ProcessHealing(EventContext);
  }
#endif

#if (DEM_CFG_SUPPORT_PRESTORED_FF == STD_ON)
  Dem_Prestore_StateSetDiscard();
#endif
}

#if (DEM_FEATURE_NEED_OBD == STD_ON)                                                                                             /* COV_MSR_UNSUPPORTED XF */
/* ****************************************************************************
 % Dem_Event_QualifyStatus
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
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Event_QualifyStatus(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(uint8, AUTOMATIC)  Effects
  )
{
# if (DEM_CFG_PROCESS_CDTC_ALL_DTC == STD_OFF)
  Dem_Event_InternalStatusType lStoredStatus;

  lStoredStatus = Dem_DTCInternalStatus_GetStoredStatus(Dem_DTC_GetInternalStatus(EventId));
  /* Event is currently active (normal case) or aging (happens with 0-Trip events) */
  if ( (lStoredStatus == Dem_DTCInternalStatus_StoredStatus_Active)
    || (lStoredStatus == Dem_DTCInternalStatus_StoredStatus_Aging) )
# endif
  {
    uint8 lEventQualifyStatus;

    lEventQualifyStatus = Dem_Event_GetQualifyStatus(EventId);

    if ((DEM_OPERATIONCYCLE_TEST_DCY_QUALIFIED(Dem_OperationCycle_GetObdCycleStates()) == TRUE)                                  /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
      || (Dem_Cfg_EventTripTarget(EventId) == 0) )
    {
      /* The event has confirmed */
      if ((Effects & DEM_CFG_TRIGGER_CONFIRMED) != 0)
      {
        lEventQualifyStatus = Dem_EventInternalStatus_Set_QualifyStatus_CDTC(lEventQualifyStatus);
# if (DEM_FEATURE_NEED_PID01_CALCULATION == STD_ON)
        if (Dem_Cfg_EventReadinessGroup(EventId) != DEM_CFG_READINESS_FLSYS)
        {
          Dem_Util_SetReadinessGroupCompleted(TRUE, Dem_Cfg_EventReadinessGroup(EventId), &Dem_Mem_GetPid01CompletedMask());
        }
# endif
      }
      /* The event has requested the MIL */
      if ((Effects & DEM_CFG_TRIGGER_INDICATOR) != 0)
      {
        lEventQualifyStatus = Dem_EventInternalStatus_Set_QualifyStatus_WIR(lEventQualifyStatus);
      }
    }

    Dem_DTC_SetQualifyStatus(EventId, lEventQualifyStatus);

# if (DEM_CFG_PROCESS_CDTC_ALL_DTC == STD_ON)
    /* If configured that DTC status is independent from stored status, always set
     * NV status data block to DIRTY */
    Dem_Nvm_SetBlockState(DEM_NVM_BLOCKTYPE_STATUS, DEM_NVM_BLOCKSTATE_DIRTY);
# else
    {
      Dem_Mem_MemoryInfoPtrType lMemoryInfo;
      Dem_Cfg_MemoryIndexType lMemoryIndex;
      Dem_MemoryEntry_HandleType lMemoryEntryId;

      lMemoryInfo = Dem_MemStorageManager_MemoryInfoInit(Dem_Cfg_EventDestination(EventId));
      lMemoryIndex = Dem_MemStorageManager_MemoryFindIndex_Checked(lMemoryInfo, EventId);                                        /* SBSW_DEM_CALL_MEMORYINFO_POINTER */
      lMemoryEntryId = Dem_MemStorageManager_GetMemoryEntryId(lMemoryIndex);

      /* synchronize the qualification state with the primary memory entry */
      if (DEM_MEM_GET_QUALIFIED_MASK(Dem_MemoryEntry_GetState(lMemoryEntryId)) != lEventQualifyStatus)
      {
        Dem_MemoryEntry_SetState(lMemoryEntryId, DEM_MEM_SET_QUALIFIED_MASK(Dem_MemoryEntry_GetState(lMemoryEntryId), lEventQualifyStatus));
        Dem_Nvm_SetMemoryBlockState(Dem_MemStorageManager_GetNvBlockType(lMemoryIndex),
                                    Dem_MemStorageManager_GetEntryIndex(lMemoryIndex),
                                    DEM_NVM_BLOCKSTATE_DIRTYIMMEDIATE);
      }
    }
# endif
  }
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */
#endif /* (DEM_FEATURE_NEED_OBD == STD_ON) */

/* ****************************************************************************
 % Dem_Event_ProcessNotifications
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Event_ProcessNotifications(
  CONSTP2VAR(Dem_Event_ContextType, AUTOMATIC, AUTOMATIC)  EventContext                                                       /* PRQA S 3673 */ /* MD_DEM_16.7_Design */
  )
{
  if (EventContext->OldEventStatus != EventContext->NewEventStatus)
  {
    Dem_Cbk_StatusChanged(EventContext->EventId, EventContext->OldEventStatus, EventContext->NewEventStatus);
  }

  if (EventContext->DataModified == TRUE)
  {
    Dem_Cbk_EventDataChanged(EventContext->EventId);
  }
}

/* ****************************************************************************
 % Dem_Event_InitAvailableNV
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Event_InitAvailableNV(
  void
  )
{
#if (DEM_FEATURE_NEED_EVENTAVAILABLE_NV == STD_ON)
  Dem_EventIdType lEventId;
  uint16_least lMaskIndex;
  uint16_least lMaskIndex_End;

  lEventId = 0;
  lMaskIndex_End = (uint16_least)((Dem_Cfg_GlobalEventCount() + 7) / 8);

  /* */
  for (lMaskIndex = 0; lMaskIndex < lMaskIndex_End; ++lMaskIndex)
  {
    Dem_EventIdType lEventId_End;
    uint8 lNvAvailableMask;

    lEventId_End = lEventId + 8;
    if (lEventId_End > Dem_Cfg_GlobalEventCount())
    {
      lEventId_End = Dem_Cfg_GlobalEventCount();
    }
    lNvAvailableMask = Dem_Mem_EventGetAvailableMask(lMaskIndex);

    while (lEventId < lEventId_End)
    {
      if ((lNvAvailableMask & 0x01) != 0)
      {
        boolean lMayDisconnect;
        lMayDisconnect = Dem_Event_MayDisconnect(lEventId);
        Dem_Event_SetDisconnectedBit(lEventId, lMayDisconnect);
      }
      else
      {
        Dem_Event_SetDisconnectedBit(lEventId, FALSE);
      }
      lNvAvailableMask = (uint8)(lNvAvailableMask >> 1);
      ++lEventId;
    }
  }
#endif
}

/* ****************************************************************************
 % Dem_Event_InitQualification
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Event_InitQualification(
  void
  )
{
#if (DEM_FEATURE_NEED_OBD == STD_ON) && (DEM_CFG_PROCESS_CDTC_ALL_DTC == STD_OFF)                                                /* COV_MSR_UNSUPPORTED XF xf tf */
  Dem_EventIdType lEventId;

  for (lEventId = DEM_EVENT_FIRST; lEventId < Dem_Cfg_GlobalEventCount(); ++lEventId)
  { /* Initialize the qualified status for all events */
    uint8 lEventQualifyStatus;

    lEventQualifyStatus = 0xFF;
    if (Dem_Cfg_EventObdRelated(lEventId) == TRUE)
    { /* only OBD related events supports the qualification of Confirmed and WIR bit */
      lEventQualifyStatus = Dem_EventInternalStatus_Reset_QualifyStatus_CDTC(lEventQualifyStatus);
      lEventQualifyStatus = Dem_EventInternalStatus_Reset_QualifyStatus_WIR(lEventQualifyStatus);
    }
    Dem_DTC_SetQualifyStatus(lEventId, lEventQualifyStatus);
  }
#endif
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */

/* ****************************************************************************
 % Dem_Event_InitEventInternalStatus
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Event_InitEventInternalStatus(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId                                                                                     /* PRQA S 3206 */ /* MD_DEM_3206 */
  )
{
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(EventId)                                                                                      /* PRQA S 3112 */ /* MD_DEM_14.2 */
#if (DEM_FEATURE_NEED_EVENTAVAILABLE_DEFAULT == STD_ON)
  if (Dem_Cfg_EventAvailableByDefault(EventId) == FALSE)
  {
    Dem_Event_SetDisconnectedBit(EventId, Dem_Event_MayDisconnect(EventId));
  }
  else
  {
    Dem_Event_SetDisconnectedBit(EventId, FALSE);
  }
#endif
}

/* ****************************************************************************
 % Dem_Event_InitEventStatus
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
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Event_InitEventStatus(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  )
{
  uint8 lEventStatus;
  Dem_Event_InternalStatusType lAgedStatus;                                                                                      /* PRQA S 3203 */ /* MD_DEM_3203 */

  lEventStatus = Dem_Event_GetUDSStatus(EventId);
  lAgedStatus = Dem_DTCInternalStatus_GetStoredStatus(Dem_DTC_GetInternalStatus(EventId));                                       /* PRQA S 3112, 3199 */ /* MD_DEM_14.2, MD_DEM_3199 */

  if (Dem_Cfg_EventAvailableByVariant(EventId) == FALSE)
  {
    lEventStatus = 0x00;
  }
  else
#if (DEM_FEATURE_NEED_STOREDONLY_BITS == STD_ON)
  if (lAgedStatus == Dem_DTCInternalStatus_StoredStatus_None)
  {
    /* Event is not stored, reset stored-only bits.
    * Note: this relies on the compiler to optimize the different bit operations into a single mask operation.
    * The intention is to find a dedicated access for each Bit modification for review purposes.*/
# if (DEM_CFG_PROCESS_PDTC_STOREDONLY == STD_ON)
    lEventStatus = Dem_UDSStatus_Reset_PDTC(lEventStatus);
# endif
# if (DEM_CFG_PROCESS_CDTC_STOREDONLY == STD_ON)
    lEventStatus = Dem_UDSStatus_Reset_CDTC(lEventStatus);
# endif
# if (DEM_CFG_PROCESS_TFSLC_STOREDONLY == STD_ON)
    lEventStatus = Dem_UDSStatus_Reset_TFSLC(lEventStatus);
# endif
  }
  else
#endif
#if (DEM_CFG_AGING_RETAIN_MEMORY_ENTRY == STD_ON)
  if (lAgedStatus == Dem_DTCInternalStatus_StoredStatus_Aged)
  {
# if (DEM_CFG_STORAGE_AT_CONFIRMED == STD_OFF)
    if ( (Dem_UDSStatus_Test_PDTC(lEventStatus) == TRUE)                                                                         /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
#  if (DEM_CFG_AGING_START_TRIGGER_PASSED == STD_ON)
      && (Dem_Cfg_EventAgingTarget(EventId) == 0) 
#  endif
       )
    {
      lEventStatus = Dem_UDSStatus_Reset_PDTC(lEventStatus);

      if (Dem_Cfg_EventHealingTarget(EventId) == 0)
      {
        if (Dem_UDSStatus_Test_WIR(lEventStatus) == TRUE)
        {
          lEventStatus = Dem_UDSStatus_Reset_WIR(lEventStatus);
#  if (DEM_FEATURE_NEED_MULTIHEAL == STD_ON) && (DEM_CFG_AGING_AFTER_HEALING_ALL_DTC == STD_OFF)
          Dem_Event_SetTripCount(EventId, 0);
#  endif
        }
#  if (DEM_FEATURE_NEED_MULTIHEAL == STD_ON) && (DEM_CFG_AGING_AFTER_HEALING_ALL_DTC == STD_ON)
        Dem_Event_SetTripCount(EventId, 0);
#  endif
      }
      else
      {
#  if (DEM_FEATURE_NEED_MULTIHEAL == STD_ON)
        Dem_Event_SetTripCount(EventId, 0);
#  endif
      }
    }
#  if (DEM_CFG_PROCESS_TFSLC_ALL_DTC == STD_ON)
    lEventStatus = Dem_UDSStatus_Reset_TFSLC(lEventStatus);
#  endif
# endif
    lEventStatus = Dem_UDSStatus_Reset_CDTC(lEventStatus);
  }
  else
#endif
#if (DEM_CFG_AGING_START_TRIGGER_PASSED == STD_OFF)
  if (lAgedStatus == Dem_DTCInternalStatus_StoredStatus_Aging)
  {
    if (Dem_UDSStatus_Test_PDTC(lEventStatus) == TRUE)
    {
      lEventStatus = Dem_UDSStatus_Reset_PDTC(lEventStatus);

      if (Dem_Cfg_EventHealingTarget(EventId) == 0)
      {
        if (Dem_UDSStatus_Test_WIR(lEventStatus) == TRUE)
        {
          lEventStatus = Dem_UDSStatus_Reset_WIR(lEventStatus);
# if (DEM_FEATURE_NEED_MULTIHEAL == STD_ON) && (DEM_CFG_AGING_AFTER_HEALING_ALL_DTC == STD_OFF)
          Dem_Event_SetTripCount(EventId, 0);
# endif
        }
# if (DEM_FEATURE_NEED_MULTIHEAL == STD_ON) && (DEM_CFG_AGING_AFTER_HEALING_ALL_DTC == STD_ON)
        Dem_Event_SetTripCount(EventId, 0);
# endif
      }
      else
      {
# if (DEM_FEATURE_NEED_MULTIHEAL == STD_ON)
        Dem_Event_SetTripCount(EventId, 0);
# endif
      }
    }
  }
  else
#endif
  {
    /* Satisfy MISRA */
  }

#if (DEM_CFG_SUPPORT_TESTFAILED_STORAGE != STD_ON)
  lEventStatus = Dem_UDSStatus_Reset_TF(lEventStatus);
#endif

  if ((lEventStatus & (DEM_UDS_STATUS_TFTOC | DEM_UDS_STATUS_TNCTOC)) == (DEM_UDS_STATUS_TFTOC | DEM_UDS_STATUS_TNCTOC))
  { /* Test not completed, but failed this cycle is not a consistent state.
    Reset TFTOC to restore consistency. This also makes sure a new test
    result is processed */
    lEventStatus = Dem_UDSStatus_Reset_TFTOC(lEventStatus);
  }
  if ((lEventStatus & (DEM_UDS_STATUS_TFSLC | DEM_UDS_STATUS_TNCSLC)) == (DEM_UDS_STATUS_TFSLC | DEM_UDS_STATUS_TNCSLC))
  { /* Test not completed, but failed since last clear is not a consistent state.
    Reset TNCSLC to restore consistency. Keep TFSLC since it is sometimes
    set by correction code */
    lEventStatus = Dem_UDSStatus_Reset_TNCSLC(lEventStatus);
  }

  {
#if (DEM_FEATURE_NEED_INDICATORS == STD_ON)
# if (DEM_CFG_SUPPORT_USER_INDICATORS == STD_ON)                                                                                 /* COV_MSR_UNSUPPORTED TF */
    Dem_Cfg_EventIndicatorIterType lIndicatorIter;
    Dem_Cfg_EventIndicatorIterInit(EventId, &lIndicatorIter);                                                                    /* SBSW_DEM_CALL_ITERATOR_POINTER */
    if (Dem_Cfg_EventIndicatorIterExists(&lIndicatorIter) == FALSE)                                                              /* SBSW_DEM_CALL_ITERATOR_POINTER */
# endif
    {
#endif /* (DEM_FEATURE_NEED_INDICATORS == STD_ON) */
      {
        lEventStatus = Dem_UDSStatus_Reset_WIR(lEventStatus);
      }
#if (DEM_FEATURE_NEED_INDICATORS == STD_ON)
    }
#endif
  }

  Dem_Event_SetUDSStatus(EventId, lEventStatus);

#if (DEM_FEATURE_NEED_INDICATORS == STD_ON)
  if (Dem_UDSStatus_Test_WIR(lEventStatus) == TRUE)
  {
    {
# if (DEM_CFG_SUPPORT_USER_INDICATORS == STD_ON)                                                                                 /* COV_MSR_UNSUPPORTED TX */
      Dem_Esm_UserIndicatorEnable(EventId);
# endif
    }
  }
#endif /* (DEM_CFG_SUPPORT_INDICATORS == STD_ON) */
}                                                                                                                                /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

#if (DEM_CFG_SUPPORT_EVENTAVAILABLE == STD_ON)
/* ****************************************************************************
 % Dem_Event_ProcessEventAvailable
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
Dem_Event_ProcessEventAvailable(
  CONST(Dem_EventIdType, AUTOMATIC) EventId
  )
{
  if (Dem_EventInternalStatus_TestAvailabilityChanged(Dem_Event_GetInternalStatus(EventId)) == TRUE)
  {
    Dem_Event_InternalStatusType lInternalStatus;
    boolean lNewDisconnectedStatus;

/* >>>> -------------------------------- Enter Critical Section: DiagMonitor */
    Dem_EnterCritical_DiagMonitor();                                                                                             /* PRQA S 3109 */ /* MD_MSR_14.3 */

    lInternalStatus = Dem_Event_GetInternalStatus(EventId);
    lInternalStatus = Dem_EventInternalStatus_ResetAvailabilityChanged(lInternalStatus);
    Dem_Event_SetInternalStatus(EventId, lInternalStatus);

    lNewDisconnectedStatus = (boolean)(Dem_EventInternalStatus_TestEventDisconnected(lInternalStatus) == TRUE);
    if (lNewDisconnectedStatus == TRUE)
    {
      /* Dtc was disconnected */
      Dem_DTC_Disconnect(EventId);

 # if (DEM_CFG_SUPPORT_PRESTORED_FF == STD_ON)
      if (Dem_Cfg_EventPrestorageIndex(EventId) != DEM_PRESTORE_NOT_CONFIGURED_FOR_EVENT)
      {
        (void)Dem_Prestore_EventPrestorageClear(EventId);
      }
# endif

# if (DEM_FEATURE_NEED_IUMPR == STD_ON)                                                                                          /* COV_MSR_UNSUPPORTED XF */
      {
        /* If the DTC has a Ratio, disable the IUMPR calculation */
        Dem_RatioIdIndexType  lRatioIndex;

        lRatioIndex = Dem_Cfg_EventRatioIdIdx(EventId);
        if (lRatioIndex != DEM_CFG_RATIOINDEX_INVALID)
        {
          Dem_Mem_SetIumprStatus(lRatioIndex, DEM_ESM_SET_IUMPR_DISCONNECTED(Dem_Mem_GetIumprStatus(lRatioIndex)));
        }
      }
# endif
    }
    else
    {
      /* Event was reconnected */
      Dem_DTC_Reconnect(EventId);

# if (DEM_FEATURE_NEED_IUMPR == STD_ON)                                                                                          /* COV_MSR_UNSUPPORTED XF */
      {
        Dem_RatioIdIndexType  lRatioIndex;

        lRatioIndex = Dem_Cfg_EventRatioIdIdx(EventId);

        if (lRatioIndex != DEM_CFG_RATIOINDEX_INVALID)
        {
          Dem_Mem_SetIumprStatus(lRatioIndex, DEM_ESM_RESET_IUMPR_DISCONNECTED(Dem_Mem_GetIumprStatus(lRatioIndex)));
        }
      }
# endif
    }

    Dem_LeaveCritical_DiagMonitor();                                                                                             /* PRQA S 3109 */ /* MD_MSR_14.3 */
/* <<<< -------------------------------- Leave Critical Section: DiagMonitor */

# if (DEM_CFG_NOTIFY_FIM == STD_ON)
    if (lNewDisconnectedStatus == TRUE)
    {
      (void)FiM_DemTriggerOnEventStatus(EventId, 0x50U, 0x00U);
    }
    else
    {
      (void)FiM_DemTriggerOnEventStatus(EventId, 0x00U, 0x50U);
    }
# endif
  }
}                                                                                                                                /* PRQA S 6080, 6050 */ /* MD_MSR_STMIF, MD_MSR_STCAL */
#endif

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
 * \addtogroup Dem_Event_Public
 * \{
 */

#if (DEM_FEATURE_NEED_HEALING == STD_ON) && (DEM_FEATURE_NEED_AGING_AFTER_HEALING == STD_ON)
/* ****************************************************************************
 % Dem_Event_TestEventHealed
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
 *
 *
 *
 *
 *
 *
 *
 *
 */
DEM_LOCAL FUNC(boolean, DEM_CODE)
Dem_Event_TestEventHealed(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,                                                                                    /* PRQA S 3206 */ /* MD_DEM_3206 */
  CONST(uint8, AUTOMATIC)  EventStatus                                                                                           /* PRQA S 3206 */ /* MD_DEM_3206 */
)
{
  boolean lReturnValue;

  DEM_IGNORE_UNUSED_CONST_ARGUMENT(EventId)                                                                                      /* PRQA S 3112 */ /* MD_DEM_14.2 */
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(EventStatus)                                                                                  /* PRQA S 3112 */ /* MD_DEM_14.2 */

#if (DEM_CFG_AGING_AFTER_HEALING_ALL_DTC == STD_ON)
  if (Dem_Cfg_EventHealingTarget(EventId) == 0)
  {
# if (DEM_FEATURE_NEED_IMMEDIATEHEAL == STD_ON)
    lReturnValue = ( (Dem_UDSStatus_Test_TF(EventStatus) == FALSE)                                                               /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
             && (Dem_UDSStatus_Test_TNCTOC(EventStatus) == FALSE) );
# endif
  }
  else /* Dem_Cfg_EventHealingTarget(EventId) > 0 */
  {
# if (DEM_FEATURE_NEED_MULTIHEAL == STD_ON)
    /* TripCount is the healing counter when PDTC == false */
    lReturnValue = ( (Dem_Event_GetTripCount(EventId) >= Dem_Cfg_EventHealingTarget(EventId))                      /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
             && (Dem_UDSStatus_Test_PDTC(EventStatus) == FALSE) );
# else
    lReturnValue = (Dem_UDSStatus_Test_PDTC(EventStatus) == FALSE);
# endif
  }
#else
  lReturnValue = (boolean)(Dem_UDSStatus_Test_WIR(EventStatus) == FALSE);
#endif
  return lReturnValue;
}
#endif /*#if (DEM_FEATURE_NEED_HEALING == STD_ON) && (DEM_FEATURE_NEED_AGING_AFTER_HEALING == STD_ON)*/

#if (DEM_CFG_SUPPORT_EVENTAVAILABLE == STD_ON)
/* ****************************************************************************
 % Dem_Event_Disconnect_Normal
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
Dem_Event_Disconnect_Normal(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  )
{
  Dem_Event_InternalStatusType lInternalStatus;

  lInternalStatus = Dem_Event_GetInternalStatus(EventId);
  lInternalStatus = Dem_DTCInternalStatus_ResetFdcToc(lInternalStatus);
  Dem_Event_SetInternalStatus(EventId, lInternalStatus);

  Dem_SatelliteCore_ClearEvent(
      Dem_Cfg_EventSatelliteId(EventId),
      Dem_Cfg_EventSatelliteEventId(EventId));

  Dem_Event_SetExtendedStatus(EventId, 
    Dem_EventInternalStatus_ResetSimilarConditions(
      Dem_Event_GetExtendedStatus(EventId)
    )
  );

  Dem_Event_SetUDSStatus(EventId, 0x00U);
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */
#endif

#if (DEM_CFG_SUPPORT_EVENTAVAILABLE == STD_ON)
/* ****************************************************************************
 % Dem_Event_Reconnect_Normal
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Event_Reconnect_Normal(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  )
{
  Dem_Event_SetUDSStatus(EventId, 0x50U);
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */
#endif

/* ****************************************************************************
 % Dem_Event_TestEventAvailable
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Event_TestEventAvailable(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId                                                                                     /* PRQA S 3206 */ /* MD_DEM_3206 */
  )
{
  boolean lReturnValue;
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(EventId)                                                                                      /* PRQA S 3112 */ /* MD_DEM_14.2 */
#if (DEM_CFG_SUPPORT_EVENTAVAILABLE == STD_ON)
  lReturnValue = (boolean)(Dem_EventInternalStatus_TestEventDisconnected(Dem_Event_GetInternalStatus(EventId)) == FALSE);
#else
  lReturnValue = TRUE;
#endif
  return lReturnValue;
}

#if (DEM_CFG_SUPPORT_IUMPR == STD_ON) \
 || (DEM_FEATURE_NEED_PID01_CALCULATION == STD_ON) \
 || (DEM_FEATURE_NEED_PID41_CALCULATION == STD_ON) \
 || (DEM_FEATURE_NEED_PID41_CCONLY_CALCULATION == STD_ON)
/* ****************************************************************************
 % Dem_Event_TestEventSuppressed
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
Dem_Event_TestEventSuppressed(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  )
{
  boolean lReturnValue;
  lReturnValue = (boolean)                                                                                                       /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
     ( (Dem_DTCInternalStatus_TestDtcSuppressed(Dem_Event_GetInternalStatus(EventId)) == TRUE)
    || (Dem_Cfg_EventAvailableByVariant(EventId) == FALSE)
    || ( (Dem_Event_TestEventAvailable(EventId) == FALSE)
      && (Dem_DTCInternalStatus_GetStoredStatus(Dem_Event_GetInternalStatus(EventId))
              == Dem_DTCInternalStatus_StoredStatus_None) )
      );
  return lReturnValue;
}
#endif

#if (DEM_FEATURE_NEED_EVENTAVAILABLE_DEFAULT == STD_ON) || (DEM_FEATURE_NEED_EVENTAVAILABLE_NV == STD_ON)
/* ****************************************************************************
 % Dem_Event_SetDisconnectedBit
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Event_SetDisconnectedBit(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(boolean, AUTOMATIC)  IsDisconnected
  )
{
  Dem_Event_InternalStatusType lInternalStatus;
  lInternalStatus = Dem_Event_GetInternalStatus(EventId);

  if (IsDisconnected == TRUE)
  {
    lInternalStatus = Dem_EventInternalStatus_SetEventDisconnected(lInternalStatus);
    Dem_Event_SetUDSStatus(EventId, 0x00);
  }
  else
  {
    lInternalStatus = Dem_EventInternalStatus_ResetEventDisconnected(lInternalStatus);
  }

  Dem_Event_SetInternalStatus(EventId, lInternalStatus);
}
#endif

#if (DEM_CFG_SUPPORT_EVENTAVAILABLE == STD_ON)
/* ****************************************************************************
 % Dem_Event_MayDisconnect
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
DEM_LOCAL FUNC(boolean, DEM_CODE)
Dem_Event_MayDisconnect(
CONST(Dem_EventIdType, AUTOMATIC)  EventId
)
{
  boolean lReturnValue;
  uint8 lEventStatus;
  Dem_Event_InternalStatusType lInternalStatus;

  lInternalStatus = Dem_DTC_GetInternalStatus(EventId);
  lEventStatus = Dem_Event_GetUDSStatus(EventId);

  if ( (Dem_UDSStatus_Test_TF(lEventStatus) == FALSE)                                                                            /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
    && (Dem_UDSStatus_Test_WIR(lEventStatus) == FALSE)
    && (Dem_UDSStatus_Test_CDTC(lEventStatus) == FALSE)
    )
  {
    if (Dem_DTCInternalStatus_GetStoredStatus(lInternalStatus) == Dem_DTCInternalStatus_StoredStatus_None)
    {
      lReturnValue = TRUE;
    }
    else
    {
      lReturnValue = Dem_DTC_TestRemainingEventforDtc(EventId);
    }
  }
  else
  {
    lReturnValue = FALSE;
  }

  return lReturnValue;
}
#endif

#if (DEM_CFG_SUPPORT_EVENTAVAILABLE == STD_ON)
/* ****************************************************************************
 % Dem_Event_Disconnect
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
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Event_Disconnect(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  )
{
  Std_ReturnType lReturnValue;
  Dem_Event_InternalStatusType lEventInternalStatus;

  lEventInternalStatus = Dem_Event_GetInternalStatus(EventId);
  if (Dem_EventInternalStatus_TestEventDisconnected(lEventInternalStatus) == FALSE)
  {
    if ( ((Dem_InitState_TestMasterInState(DEM_INITSTATE_PREINITIALIZED) == TRUE) || (Dem_Event_MayDisconnect(EventId) == TRUE)) /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
      && (Dem_EventInternalStatus_TestAvailabilityChanged(lEventInternalStatus) == FALSE) )
    {
/* >>>> -------------------------------- Enter Critical Section: DiagMonitor */
      Dem_EnterCritical_DiagMonitor();                                                                                           /* PRQA S 3109 */ /* MD_MSR_14.3 */
      lEventInternalStatus = Dem_Event_GetInternalStatus(EventId);
      lEventInternalStatus = Dem_EventInternalStatus_SetEventDisconnected(lEventInternalStatus);
      lEventInternalStatus = Dem_EventInternalStatus_SetAvailabilityChanged(lEventInternalStatus);
      Dem_Event_SetInternalStatus(EventId, lEventInternalStatus);
      Dem_LeaveCritical_DiagMonitor();                                                                                           /* PRQA S 3109 */ /* MD_MSR_14.3 */
/* <<<< -------------------------------- Leave Critical Section: DiagMonitor */
      
      Dem_Scheduler_EnableTaskOnce(Dem_Scheduler_Task_Event);

# if (DEM_FEATURE_NEED_EVENTAVAILABLE_NV == STD_ON)
      {
        uint8 lNvAvailableMask;
        lNvAvailableMask = Dem_Mem_EventGetAvailableMask(EventId / 8u);
        lNvAvailableMask = (uint8)(lNvAvailableMask | DEM_BIT(EventId % 8u));
        Dem_Mem_EventSetAvailableMask(EventId / 8u, lNvAvailableMask);
        Dem_Nvm_SetBlockState(DEM_NVM_BLOCKTYPE_AVAILABILITY, DEM_NVM_BLOCKSTATE_DIRTY);
      }
# endif
# if (DEM_FEATURE_NEED_PID01_CALCULATION == STD_ON)
      /* If major monitor enabled by configuration mark readiness group of event to recalculate readiness state */
      Dem_Queue_Pid01UpdateFlag = Dem_Esm_SetPid01ReadinessState(Dem_Queue_Pid01UpdateFlag, Dem_Cfg_EventReadinessGroup(EventId));
# endif
      lReturnValue = E_OK;
    }
    else
    {
      lReturnValue = E_NOT_OK;
    }
  }
  else
  {
    lReturnValue = E_OK;
  }
  return lReturnValue;
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */
#endif /* (DEM_CFG_SUPPORT_EVENTAVAILABLE == STD_ON) */

#if (DEM_CFG_SUPPORT_EVENTAVAILABLE == STD_ON)
/* ****************************************************************************
 % Dem_Event_Reconnect
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
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Event_Reconnect(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  )
{
  Dem_Event_InternalStatusType lEventInternalStatus;

  lEventInternalStatus = Dem_Event_GetInternalStatus(EventId);
  if ( (Dem_EventInternalStatus_TestEventDisconnected(lEventInternalStatus) == TRUE)                                             /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
    && (Dem_EventInternalStatus_TestAvailabilityChanged(lEventInternalStatus) == FALSE) )
  {
/* >>>> -------------------------------- Enter Critical Section: DiagMonitor */
    Dem_EnterCritical_DiagMonitor();                                                                                             /* PRQA S 3109 */ /* MD_MSR_14.3 */
    lEventInternalStatus = Dem_Event_GetInternalStatus(EventId);
    lEventInternalStatus = Dem_EventInternalStatus_ResetEventDisconnected(lEventInternalStatus);
    lEventInternalStatus = Dem_EventInternalStatus_SetAvailabilityChanged(lEventInternalStatus);
    Dem_Event_SetInternalStatus(EventId, lEventInternalStatus);
    Dem_LeaveCritical_DiagMonitor();                                                                                             /* PRQA S 3109 */ /* MD_MSR_14.3 */
/* <<<< -------------------------------- Leave Critical Section: DiagMonitor */

    Dem_Scheduler_EnableTaskOnce(Dem_Scheduler_Task_Event);

# if (DEM_FEATURE_NEED_EVENTAVAILABLE_NV == STD_ON)
    {
      uint8 lNvAvailableMask;
      lNvAvailableMask = Dem_Mem_EventGetAvailableMask(EventId / 8u);
      lNvAvailableMask = (uint8)(lNvAvailableMask & DEM_BIT_MASK(EventId % 8u, DEM_1BYTE));
      Dem_Mem_EventSetAvailableMask(EventId / 8u, lNvAvailableMask);
      Dem_Nvm_SetBlockState(DEM_NVM_BLOCKTYPE_AVAILABILITY, DEM_NVM_BLOCKSTATE_DIRTY);
    }
# endif

# if (DEM_FEATURE_NEED_PID01_CALCULATION == STD_ON)
    if (Dem_Cfg_EventReadinessGroup(EventId) != DEM_CFG_READINESS_FLSYS)
    {
      Dem_Util_SetReadinessGroupCompleted(FALSE, Dem_Cfg_EventReadinessGroup(EventId), &Dem_Mem_GetPid01CompletedMask());
    }
# endif
  }
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */
#endif /* (DEM_CFG_SUPPORT_EVENTAVAILABLE == STD_ON) */

/* ****************************************************************************
 % Dem_Event_ProcessFdc
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
Dem_Event_ProcessFdc(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(boolean, AUTOMATIC)  FdcThresholdExceeded,
  CONST(boolean, AUTOMATIC)  FdcMaximumExceeded
  )
{
#if (DEM_FEATURE_NEED_FDC_TRIP == STD_ON)
  Dem_Event_InternalStatusType lOldEventInternalStatus;
  Dem_Event_InternalStatusType lNewEventInternalStatus;

/* >>>> -------------------------------- Enter Critical Section: DiagMonitor */
  Dem_EnterCritical_DiagMonitor();                                                                                               /* PRQA S 3109 */ /* MD_MSR_14.3 */
  {

    lOldEventInternalStatus = Dem_Event_GetInternalStatus(EventId);
    lNewEventInternalStatus = lOldEventInternalStatus;
    if (FdcThresholdExceeded == TRUE)
    {
      lNewEventInternalStatus = Dem_DTCInternalStatus_SetFdcToc(lNewEventInternalStatus);
    }
    Dem_Event_SetInternalStatus(EventId, lNewEventInternalStatus);
  }
  Dem_LeaveCritical_DiagMonitor();                                                                                               /* PRQA S 3109 */ /* MD_MSR_14.3 */
/* <<<< -------------------------------- Leave Critical Section: DiagMonitor */

  /* no events without a DTC attached, disabled storage conditions, dtc/event suppressed... */
  if ( (Dem_Cfg_EventUdsDtc(EventId) != DEM_CFG_DTC_UDS_INVALID)                                                                 /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
        /* Don't store with disabled storage conditions */
    && (Dem_StorageCondition_TestEventStorageConditionsFulfilled(EventId) == TRUE) )
  {
# if (DEM_CFG_SUPPORT_TRIGGER_FDC_FIRST_IN_CYCLE == STD_ON) || (DEM_CFG_STORAGE_AT_FDC == STD_ON)
    if (FdcThresholdExceeded == TRUE)
    {
      /* Pass 'TRUE' if the old bit is false, so the status change did happen just now */
      Dem_DTC_FdcTrip(EventId, (boolean)(Dem_DTCInternalStatus_TestFdcToc(lOldEventInternalStatus) == FALSE));
    }
# endif
# if (DEM_CFG_DATA_MAX_FDC_SINCE_LAST_CLEAR == STD_ON)
    if (FdcMaximumExceeded == TRUE)
    {
      Dem_DTC_UpdateFdcMax(EventId);
    }
# else
    DEM_IGNORE_UNUSED_CONST_ARGUMENT(FdcMaximumExceeded)                                                                         /* PRQA S 3112 */ /* MD_DEM_14.2 */
# endif
  }
#else
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(EventId)                                                                                      /* PRQA S 3112 */ /* MD_DEM_14.2 */
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(FdcThresholdExceeded)                                                                         /* PRQA S 3112 */ /* MD_DEM_14.2 */
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(FdcMaximumExceeded)                                                                           /* PRQA S 3112 */ /* MD_DEM_14.2 */
#endif
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */

/* ****************************************************************************
 % Dem_Event_Passed
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
 */
DEM_LOCAL FUNC(void, DEM_CODE)
Dem_Event_Passed(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  )
{
  if (Dem_Event_TestLatchedTestFailed(EventId) == FALSE)
  {
    Dem_Event_ContextType lEventContext;
    Dem_DTC_ContextType lDTCContext;

    Dem_Event_InitEventContext(EventId, &lEventContext);
    Dem_DTC_InitDTCContext(EventId, &lDTCContext);

    Dem_Event_CalculateStatusOnPassed(&lEventContext);
    Dem_Event_Passed_CalcEventEffects(&lEventContext);

#if (DEM_CFG_SUPPORT_SIMILAR_CONDITIONS == STD_OFF) 
    if (lEventContext.OldEventStatus != lEventContext.NewEventStatus)
#endif
    {
      Dem_Event_ProcessPassedEffects(&lEventContext);

      Dem_Event_SetUDSStatus(lEventContext.EventId, lEventContext.NewEventStatus);

      Dem_DTC_CalculateDTCStatus(&lDTCContext);

      Dem_Event_ProcessNotifications(&lEventContext);
      Dem_DTC_ProcessNotifications(&lDTCContext);

      Dem_DTC_Passed_ProcessDTCEffects(&lDTCContext);
    }

    if (Dem_UDSStatus_IsNvRelevantStatusChange(lEventContext.OldEventStatus, lEventContext.NewEventStatus) == TRUE)
    {
      Dem_Nvm_SetStatusBlockChanged();
    }
  }
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */

/* ****************************************************************************
 % Dem_Event_Healed
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
DEM_LOCAL FUNC(uint8, DEM_CODE)
Dem_Event_Healed(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,                                                                                    /* PRQA S 3112 */ /* MD_DEM_14.2 */
  CONST(uint8, AUTOMATIC)  EventStatus
  )
{
  uint8 lNewEventStatus;
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(EventId)                                                                                      /* PRQA S 3112 */ /* MD_DEM_14.2 */

  lNewEventStatus = EventStatus;
  if (Dem_UDSStatus_Test_WIR(EventStatus) == TRUE)
  {
#if (DEM_FEATURE_NEED_SPECIAL_INDICATORS == STD_ON)                                                                              /* COV_MSR_UNSUPPORTED XF */
    uint8 lSpecialIndicator;
# if (DEM_FEATURE_NEED_OBD == STD_ON) && (DEM_CFG_SUPPORT_PID21 == STD_ON)
    boolean lOldMilIsActive;

    lOldMilIsActive = Dem_Indicator_TestMilIsActive();
# endif
#endif /* (DEM_FEATURE_NEED_SPECIAL_INDICATORS == STD_ON) */

    lNewEventStatus = Dem_UDSStatus_Reset_WIR(lNewEventStatus);

#if (DEM_FEATURE_NEED_OBD == STD_ON)                                                                                             /* COV_MSR_UNSUPPORTED XF */
    if (Dem_Cfg_GlobalMilIndicator() == Dem_Cfg_EventSpecialIndicator(EventId))
    { /* only OBD related events supports the qualification of Confirmed and WIR bit */
# if (DEM_CFG_SUPPORT_TYPE1_COMBINATION == STD_ON)
      Dem_Cfg_CombinedGroupIndexType lGroupId;
      Dem_DTC_UDSStatusType lDtcStatus;

      lDtcStatus = 0;
      lGroupId = Dem_Cfg_EventCombinedGroup(EventId);
      if (lGroupId != DEM_CFG_COMBINED_GROUP_INVALID)
      {
        Dem_Cfg_CombinedGroupIterType lCombinedIter;
        Dem_EventIdType lSubEventId;

        for (Dem_Cfg_CombinedGroupIterInit(lGroupId, &lCombinedIter);                                                            /* SBSW_DEM_CALL_ITERATOR_POINTER */
             Dem_Cfg_CombinedGroupIterExists(&lCombinedIter) == TRUE;                                                            /* SBSW_DEM_CALL_ITERATOR_POINTER */
             Dem_Cfg_CombinedGroupIterNext(&lCombinedIter))                                                                      /* SBSW_DEM_CALL_ITERATOR_POINTER */
        {
          lSubEventId = Dem_Cfg_CombinedGroupIterGet(&lCombinedIter);                                                            /* SBSW_DEM_CALL_ITERATOR_POINTER */

          if ( (lSubEventId != EventId)                                                                                          /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
            && (Dem_Cfg_EventAvailableByVariant(lSubEventId) == TRUE)                                                            /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
            && (Dem_EventInternalStatus_TestEventDisconnected(Dem_Event_GetInternalStatus(lSubEventId)) == FALSE))
          {
            lDtcStatus = (Dem_DTC_UDSStatusType)(lDtcStatus | Dem_Event_GetUDSStatus(lSubEventId));
          }
        }
      }

      if (Dem_UDSStatus_Test_WIR(lDtcStatus) == FALSE)
#endif
      {
        Dem_DTC_SetQualifyStatus(EventId, Dem_EventInternalStatus_Reset_QualifyStatus_WIR(Dem_Event_GetQualifyStatus(EventId)));
      }
    }
#endif

#if (DEM_CFG_SUPPORT_USER_INDICATORS == STD_ON) || (DEM_FEATURE_NEED_SPECIAL_INDICATORS == STD_ON)
/* >>>> -------------------------------- Enter Critical Section: DiagMonitor */
    Dem_EnterCritical_DiagMonitor();                                                                                             /* PRQA S 3109 */ /* MD_MSR_14.3 */

# if (DEM_CFG_SUPPORT_USER_INDICATORS == STD_ON)                                                                                 /* COV_MSR_UNSUPPORTED TX */
    Dem_Esm_UserIndicatorDisable(EventId);
# endif
# if (DEM_FEATURE_NEED_SPECIAL_INDICATORS == STD_ON)                                                                             /* COV_MSR_UNSUPPORTED XF */
    lSpecialIndicator = Dem_Esm_SpecialIndicatorDisable(EventId);
# endif

    Dem_LeaveCritical_DiagMonitor();                                                                                             /* PRQA S 3109 */ /* MD_MSR_14.3 */
/* <<<< -------------------------------- Leave Critical Section: DiagMonitor */
#endif

#if (DEM_FEATURE_NEED_SPECIAL_INDICATORS == STD_ON)                                                                              /* COV_MSR_UNSUPPORTED XF */
    if (lSpecialIndicator != DEM_CFG_SPECIAL_INDICATOR_NONE)
    { /* Special indicator was modified, recalculate new state */
      Dem_Mem_UpdateGlobalSpecialIndicatorStates(lSpecialIndicator);
# if (DEM_FEATURE_NEED_OBD == STD_ON) && (DEM_CFG_SUPPORT_PID21 == STD_ON)
      if (lSpecialIndicator == Dem_Cfg_GlobalMilIndicator())
      {
        if ( (lOldMilIsActive == TRUE)                                                                                           /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
          && (Dem_Indicator_TestMilIsActive() == FALSE) )
        { /* MIL indicator has changed to OFF */
          Dem_Esm_GlobalMilStateDisable();
        }
      }
# endif
    }
#endif /* (DEM_FEATURE_NEED_SPECIAL_INDICATORS == STD_ON) */
  }
  return lNewEventStatus;
}                                                                                                                                /* PRQA S 6050, 6080 */ /* MD_MSR_STCAL, MD_MSR_STMIF */

/* ****************************************************************************
 % Dem_Event_Failed
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
 *
 *
 *
 *
 *
 */
DEM_LOCAL FUNC(void, DEM_CODE)
Dem_Event_Failed(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  )
{
  Dem_Event_ContextType lEventContext;
  Dem_DTC_ContextType lDTCContext;

  Dem_Event_InitEventContext(EventId, &lEventContext);
  Dem_DTC_InitDTCContext(EventId, &lDTCContext);

  Dem_Event_CalculateStatusOnFailed(&lEventContext);
  Dem_DTC_CalculateDTCStatus(&lDTCContext);

  Dem_Event_CalculateFailedEffects(&lEventContext);
  Dem_DTC_CalculateFailedEffects(&lDTCContext, lEventContext.EventEffects);

  if (Dem_UDSStatus_IsNvRelevantStatusChange(lEventContext.OldEventStatus, lEventContext.NewEventStatus) == TRUE)
  {
    Dem_Nvm_SetStatusBlockChanged();
  }

  if ( (lEventContext.OldEventStatus != lEventContext.NewEventStatus)                                                            /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
#if (DEM_CFG_SUPPORT_RETRY_STORAGE == STD_ON)
    || (Dem_DTC_TestStoredStatus(EventId) == FALSE)
#endif
      )
  {
    if ( (Dem_Cfg_EventUdsDtc(EventId) != DEM_CFG_DTC_UDS_INVALID)                                                               /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
      && (Dem_StorageCondition_TestEventStorageConditionsFulfilled(EventId) == TRUE))
    {
      Dem_Event_CalculateFailedEffects_OnStorage(&lEventContext);
      Dem_DTC_CalculateFailedEffects_OnStorage(&lDTCContext, lEventContext.EventEffects);

      Dem_DTC_ProcessStorage(&lEventContext, &lDTCContext);

      Dem_Event_CalculateStatusOnFailed_OnStorage(&lEventContext);
      Dem_DTC_CalculateDTCStatus(&lDTCContext);

      if (lDTCContext.DtcEffects != DEM_CFG_TRIGGER_NONE)
      {
        Dem_DTC_ProcessFailedEffects(&lDTCContext);
      }

      if (lEventContext.EventEffects != DEM_CFG_TRIGGER_NONE)
      {
        Dem_Event_ProcessFailedEffects(&lEventContext);
      }

      Dem_Memory_EventFailed(lEventContext.EventId, lEventContext.EventEffects);
#if (DEM_CFG_SUPPORT_PRESTORED_FF == STD_ON)
      Dem_Prestore_StateSetDiscard();
#endif
      Dem_Nvm_SetBlockState(DEM_NVM_BLOCKTYPE_STATUS, DEM_NVM_BLOCKSTATE_DIRTY);
    }
  }
  Dem_Event_ProcessNotifications(&lEventContext);
  Dem_DTC_ProcessNotifications(&lDTCContext);
}                                                                                                                                /* PRQA S 6010, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCAL, MD_MSR_STPTH */

/* ****************************************************************************
 % Dem_Event_OpCycle
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
DEM_LOCAL FUNC(void, DEM_CODE)
Dem_Event_OpCycle(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(Dem_DTC_ForEachCombinedArgPtrType, AUTOMATIC)  ArgPtr                                                                    /* PRQA S 3673 */ /* MD_DEM_16.7_Internal */
)
{
  uint8 lOldStatus;
  uint8 lNewStatus;

  lOldStatus = Dem_Event_GetUDSStatus(EventId);

  if ((ArgPtr->Specific.EventOpCycle_Internal.CycleStatus & DEM_OPERATIONCYCLE_CYCLE_STOPPED) != 0U)
  {
    Dem_Event_OpCycleEnd(EventId, ArgPtr->Common.OldDtcStatus);
  }
  if ((ArgPtr->Specific.EventOpCycle_Internal.CycleStatus & DEM_OPERATIONCYCLE_CYCLE_STARTED) != 0U)
  {
    Dem_Event_OpCycleStart(EventId);
  }
  lNewStatus = Dem_Event_GetUDSStatus(EventId);

  if (Dem_UDSStatus_IsNvRelevantStatusChange(lOldStatus, lNewStatus) == TRUE)
  {
    Dem_Nvm_SetStatusBlockChanged();
  }

  if (Dem_InitState_TestMasterInState(DEM_INITSTATE_INITIALIZED) == TRUE)
  {
    if (lOldStatus != lNewStatus)
    { /* Call notifications only if event status has changed */
      Dem_Cbk_StatusChanged(EventId, lOldStatus, lNewStatus);
    }
    /* Call Init Monitor Callbacks */
    Dem_Cbk_InitMonitorForEvent(EventId, DEM_INIT_MONITOR_RESTART);
  }
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */

/* ****************************************************************************
 % Dem_Event_ResetTestFailed
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
Dem_Event_ResetTestFailed(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  )
{
  Dem_Event_ContextType lEventContext;
  Dem_DTC_ContextType lDTCContext;

  Dem_Event_InitEventContext(EventId, &lEventContext);
  Dem_DTC_InitDTCContext(EventId, &lDTCContext);

  lEventContext.NewEventStatus = Dem_UDSStatus_Reset_TF(lEventContext.OldEventStatus);
  Dem_Event_SetUDSStatus(EventId, lEventContext.NewEventStatus);

  Dem_DTC_CalculateDTCStatus(&lDTCContext);
  Dem_DTC_ResetFdcToc(&lDTCContext);
  
  if (Dem_UDSStatus_IsNvRelevantStatusChange(lEventContext.OldEventStatus, lEventContext.NewEventStatus) == TRUE)
  {
    Dem_Nvm_SetStatusBlockChanged();
  }

  Dem_Event_ProcessNotifications(&lEventContext);
  Dem_DTC_ProcessNotifications(&lDTCContext);
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */

/* ****************************************************************************
 % Dem_Event_Aged
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
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Event_Aged(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(Dem_DTC_ForEachCombinedArgPtrType, AUTOMATIC)  ArgPtr                                                                    /* PRQA S 3206, 3673 */ /* MD_DEM_3206, MD_DEM_16.7_Internal */
  )
{
  uint8 lOldEventStatus;
  uint8 lNewEventStatus;
  Dem_Event_InternalStatusType lInternalStatus;

  DEM_IGNORE_UNUSED_CONST_ARGUMENT(ArgPtr)                                                                                       /* PRQA S 3112 */ /* MD_DEM_14.2 */

  lOldEventStatus = Dem_Event_GetUDSStatus(EventId);
  lNewEventStatus = lOldEventStatus;

  /* remove the aged event from the primary memory */
  lNewEventStatus = Dem_UDSStatus_Reset_CDTC(lNewEventStatus);
  if (Dem_Cfg_EventAgingTarget(EventId) == 0)
  {
#if (DEM_FEATURE_NEED_MULTIHEAL == STD_ON)
    if (Dem_UDSStatus_Test_PDTC(lOldEventStatus) == TRUE)
    {
      Dem_Event_SetTripCount(EventId, 0);
    }
#endif
    lNewEventStatus = Dem_UDSStatus_Reset_PDTC(lNewEventStatus);
    lNewEventStatus = Dem_UDSStatus_Reset_TFTOC(lNewEventStatus);
  }
#if (DEM_CFG_PROCESS_TFSLC_CLEARONLY != STD_ON)
  lNewEventStatus = Dem_UDSStatus_Reset_TFSLC(lNewEventStatus);
#endif
  Dem_Event_SetUDSStatus(EventId, lNewEventStatus);

/* >>>> -------------------------------- Enter Critical Section: DiagMonitor */
  Dem_EnterCritical_DiagMonitor();                                                                                               /* PRQA S 3109 */ /* MD_MSR_14.3 */

  lInternalStatus = Dem_Event_GetInternalStatus(EventId);
#if (DEM_CFG_AGING_RETAIN_MEMORY_ENTRY == STD_ON)
  if (Dem_DTCInternalStatus_GetStoredStatus(lInternalStatus) != Dem_DTCInternalStatus_StoredStatus_None)
  {
    lInternalStatus = Dem_DTCInternalStatus_SetStoredStatus(lInternalStatus, Dem_DTCInternalStatus_StoredStatus_Aged);
  }
#else
  lInternalStatus = Dem_DTCInternalStatus_SetStoredStatus(lInternalStatus, Dem_DTCInternalStatus_StoredStatus_None);
#endif
  Dem_Event_SetInternalStatus(EventId, lInternalStatus);

  Dem_LeaveCritical_DiagMonitor();                                                                                               /* PRQA S 3109 */ /* MD_MSR_14.3 */
/* <<<< -------------------------------- Leave Critical Section: DiagMonitor */

#if (DEM_FEATURE_NEED_OBD == STD_ON)                                                                                             /* COV_MSR_UNSUPPORTED XF */
  if (Dem_Cfg_EventObdRelated(EventId) == TRUE)
  { /* only OBD related events supports the qualification of Confirmed and WIR bit */
    uint8 lQualifyStatus;
    lQualifyStatus =  Dem_EventInternalStatus_Reset_QualifyStatus_CDTC(Dem_Event_GetQualifyStatus(EventId));
    Dem_Event_SetQualifyStatus(EventId, lQualifyStatus);
  }
#endif

  if (Dem_UDSStatus_IsNvRelevantStatusChange(lOldEventStatus, lNewEventStatus) == TRUE)
  {
    Dem_Nvm_SetStatusBlockChanged();
  }

  if (lOldEventStatus != lNewEventStatus)
  {
    if (Dem_InitState_TestMasterInState(DEM_INITSTATE_INITIALIZED) == TRUE)
    {
      Dem_Cbk_StatusChanged(EventId, lOldEventStatus, lNewEventStatus);
    }
  }
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */

/* ****************************************************************************
 % Dem_Event_Cleared
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
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Event_Cleared(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(Dem_DTC_ForEachCombinedArgPtrType, AUTOMATIC)  ArgPtr                                                                    /* PRQA S 3206, 3673 */ /* MD_DEM_3206, MD_DEM_16.7_Internal */
  )
{
  Dem_Event_InternalStatusType lInternalStatus;
  uint8 lOldEventStatus;
#if (DEM_FEATURE_NEED_SPECIAL_INDICATORS == STD_ON)                                                                              /* COV_MSR_UNSUPPORTED XF */
  uint8 lSpecialIndicator = DEM_CFG_SPECIAL_INDICATOR_NONE;
#endif /* (DEM_FEATURE_NEED_SPECIAL_INDICATORS == STD_ON) */

  DEM_IGNORE_UNUSED_CONST_ARGUMENT(ArgPtr)                                                                                       /* PRQA S 3112 */ /* MD_DEM_14.2 */

  Dem_SatelliteCore_ClearEvent(
      Dem_Cfg_EventSatelliteId(EventId),
      Dem_Cfg_EventSatelliteEventId(EventId));

/* >>>> -------------------------------- Enter Critical Section: DiagMonitor */
  Dem_EnterCritical_DiagMonitor();                                                                                               /* PRQA S 3109 */ /* MD_MSR_14.3 */

  lInternalStatus = Dem_Event_GetInternalStatus(EventId);
  lOldEventStatus = Dem_Event_GetUDSStatus(EventId);

#if (DEM_CFG_SUPPORT_WWHOBD == STD_ON)                                                                                           /* COV_MSR_UNSUPPORTED XF */
  if (Dem_UDSStatus_Test_TF(lOldEventStatus) == TRUE)
  {
    Dem_Esm_DecrementQualifiedActiveEventCount(EventId, TRUE);
  }
#endif

  lInternalStatus = Dem_DTCInternalStatus_SetStoredStatus(lInternalStatus, Dem_DTCInternalStatus_StoredStatus_None);
  lInternalStatus = Dem_DTCInternalStatus_ResetFdcToc(lInternalStatus);

  Dem_Event_SetExtendedStatus(EventId, 
    Dem_EventInternalStatus_ResetSimilarConditions(
      Dem_Event_GetExtendedStatus(EventId)
    )
  );

#if (DEM_FEATURE_NEED_PID01_CALCULATION == STD_ON)
  /* Reset extended status */
  Dem_Event_SetExtendedStatus(EventId, DEM_EXT_STATUS_INITIALIZE);
#endif

  Dem_Event_SetInternalStatus(EventId, lInternalStatus);
  /* Reset status byte */
  Dem_Event_SetUDSStatus(EventId, DEM_UDS_STATUS_INITIALIZE);
  /* EventStatus is marked modified by the caller to reduce runtime overhead */

#if (DEM_CFG_SUPPORT_DTR == STD_ON)
  Dem_DtrIF_ClearDtrOfEvent(EventId);
#endif

  Dem_LeaveCritical_DiagMonitor();                                                                                               /* PRQA S 3109 */ /* MD_MSR_14.3 */
/* <<<< -------------------------------- Leave Critical Section: DiagMonitor */

#if (DEM_FEATURE_NEED_INDICATORS == STD_ON)
  if (Dem_UDSStatus_Test_WIR(lOldEventStatus) == TRUE)
  {
# if (DEM_FEATURE_NEED_OBD == STD_ON)                                                                                            /* COV_MSR_UNSUPPORTED XF */
    if (Dem_EventInternalStatus_Test_QualifyStatus_WIR(Dem_Event_GetQualifyStatus(EventId)) == TRUE)
# endif
    {
# if (DEM_CFG_SUPPORT_USER_INDICATORS == STD_ON)                                                                                 /* COV_MSR_UNSUPPORTED TX */
      Dem_Esm_UserIndicatorDisable(EventId);
# endif
# if (DEM_FEATURE_NEED_SPECIAL_INDICATORS == STD_ON)                                                                             /* COV_MSR_UNSUPPORTED XF */
      lSpecialIndicator = Dem_Esm_SpecialIndicatorDisable(EventId);
# endif
    }
  }
#endif /* (DEM_FEATURE_NEED_INDICATORS == STD_ON) */
#if (DEM_FEATURE_NEED_OBD == STD_ON)                                                                                             /* COV_MSR_UNSUPPORTED XF */
  if (Dem_Cfg_EventObdRelated(EventId) == TRUE)
  { /* only OBD related events supports the qualification of Confirmed and WIR bit */
    Dem_Event_SetQualifyStatus(EventId, DEM_QUALIFICATION_STATUS_ALL_UNQUALIFIED);
  }
#endif

#if (DEM_CFG_SUPPORT_PRESTORED_FF == STD_ON)
  if (Dem_Cfg_EventPrestorageIndex(EventId) != DEM_PRESTORE_NOT_CONFIGURED_FOR_EVENT)
  {
    (void)Dem_Prestore_EventPrestorageClear(EventId);
  }
#endif

#if (DEM_FEATURE_NEED_SPECIAL_INDICATORS == STD_ON)                                                                              /* COV_MSR_UNSUPPORTED XF */
  if (lSpecialIndicator != DEM_CFG_SPECIAL_INDICATOR_NONE)
  { /* Special indicator was modified, recalculate new state */
    Dem_Mem_UpdateGlobalSpecialIndicatorStates(lSpecialIndicator);
  }
#endif /* (DEM_FEATURE_NEED_SPECIAL_INDICATORS == STD_ON) */

#if (DEM_FEATURE_NEED_OBD == STD_ON)                                                                                             /* COV_MSR_UNSUPPORTED XF */
# if (DEM_FEATURE_NEED_MIL_GROUPS == STD_ON)
  {
    uint16 lMilGroupIndex;
    lMilGroupIndex = Dem_Cfg_EventMilGroupIndex(EventId);

    if (lMilGroupIndex != DEM_CFG_MIL_GROUP_INVALID)
    { /* decrement MIL group pending count if event pending state has changed from 1 to 0 */
      Dem_Mem_InitMilGroupTripCount(lMilGroupIndex);

      if (Dem_UDSStatus_Test_PDTC((uint8)(lOldEventStatus ^ Dem_Event_GetUDSStatus(EventId))) == TRUE)
      {
        Dem_Mem_DecrementMilGroupPendingCount(lMilGroupIndex);
      }
    }
  }
# endif
# if (DEM_CFG_SUPPORT_OBDII == STD_ON)                                                                                           /* COV_MSR_UNSUPPORTED XF */
  if (Dem_Mem_FreezeFrameIndexMode02 == Dem_Cfg_GlobalObdIIFFCount())
  { /* No Freeze Frame visible in Mode02, scan for one */
    Dem_Mem_FreezeFrameIndexMode02 = Dem_Mem_FreezeFrameSelectOldest();
  }
# endif
#endif /* (DEM_FEATURE_NEED_OBD == STD_ON) */

#if (DEM_FEATURE_NEED_MULTITRIP == STD_ON)
  Dem_Event_SetTripCount(EventId, 0);
#endif

  /* Call status changed notifications if there is a change */
  if (lOldEventStatus != DEM_UDS_STATUS_INITIALIZE)
  {
    Dem_Cbk_StatusChanged(EventId, lOldEventStatus, DEM_UDS_STATUS_INITIALIZE);
  }
}                                                                                                                                /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

#if (DEM_CFG_SUPPORT_DISPLACEMENT == STD_ON)
/* ****************************************************************************
 % Dem_Event_Displaced
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
Dem_Event_Displaced(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(Dem_DTC_ForEachCombinedArgPtrType, AUTOMATIC)  ArgPtr                                                                    /* PRQA S 3206, 3673 */ /* MD_DEM_3206, MD_DEM_16.7_Internal */
  )
{
  Dem_Event_InternalStatusType lInternalStatus;
# if (DEM_FEATURE_NEED_STOREDONLY_BITS == STD_ON)
  uint8 lOldEventStatus;
  uint8 lNewEventStatus;
# endif

  DEM_IGNORE_UNUSED_CONST_ARGUMENT(ArgPtr)                                                                                       /* PRQA S 3112 */ /* MD_DEM_14.2 */

/* >>>> -------------------------------- Enter Critical Section: DiagMonitor */
  Dem_EnterCritical_DiagMonitor();                                                                                               /* PRQA S 3109 */ /* MD_MSR_14.3 */

  lInternalStatus = Dem_Event_GetInternalStatus(EventId);
  lInternalStatus = Dem_DTCInternalStatus_SetStoredStatus(lInternalStatus, Dem_DTCInternalStatus_StoredStatus_None);
  Dem_Event_SetInternalStatus(EventId, lInternalStatus);

  Dem_LeaveCritical_DiagMonitor();                                                                                               /* PRQA S 3109 */ /* MD_MSR_14.3 */
/* <<<< -------------------------------- Leave Critical Section: DiagMonitor */

# if (DEM_FEATURE_NEED_STOREDONLY_BITS == STD_ON)
  lOldEventStatus = Dem_Event_GetUDSStatus(EventId);
  lNewEventStatus = lOldEventStatus;
# endif
  /* Update the status bit */
# if (DEM_CFG_PROCESS_PDTC_STOREDONLY == STD_ON)
  lNewEventStatus = Dem_UDSStatus_Reset_PDTC(lNewEventStatus);
# endif
# if (DEM_CFG_PROCESS_CDTC_STOREDONLY == STD_ON)
  lNewEventStatus = Dem_UDSStatus_Reset_CDTC(lNewEventStatus);
#  if (DEM_FEATURE_NEED_OBD == STD_ON)
  Dem_Event_SetQualifyStatus(EventId, Dem_EventInternalStatus_Reset_QualifyStatus_CDTC(Dem_Event_GetQualifyStatus(EventId)));
#  endif
# endif
# if (DEM_CFG_PROCESS_TFSLC_STOREDONLY == STD_ON)
  lNewEventStatus = Dem_UDSStatus_Reset_TFSLC(lNewEventStatus);
# endif
# if (DEM_FEATURE_NEED_STOREDONLY_BITS == STD_ON)
  Dem_Event_SetUDSStatus(EventId, lNewEventStatus);
# endif
  /* Displacement follows an event status change. No need to mark Nv modification again. */

# if (DEM_FEATURE_NEED_STOREDONLY_BITS == STD_ON)
  if (lNewEventStatus != lOldEventStatus)
  {
    /* DtcStatus has changed, call notifications */
    Dem_Cbk_StatusChanged(EventId, lOldEventStatus, lNewEventStatus);
  }
# endif
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */
#endif

/* ****************************************************************************
 % Dem_Event_GetEventUDSStatus
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
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Event_GetEventUDSStatus(
    CONST(Dem_EventIdType, AUTOMATIC)  EventId,
    CONSTP2VAR(Dem_UdsStatusByteType, AUTOMATIC, DEM_APPL_DATA)  EventUDSStatus
  )
{
  Std_ReturnType lReturnValue;
  lReturnValue = E_NOT_OK;
  if ( (Dem_Cfg_EventAvailableByVariant(EventId) == TRUE)                                                                        /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
    && (Dem_EventInternalStatus_TestEventDisconnected(Dem_Event_GetInternalStatus(EventId)) == FALSE) )
  {
    *EventUDSStatus = Dem_Event_GetUDSStatus(EventId);                                                                           /* SBSW_DEM_POINTER_WRITE_API */

#if (DEM_FEATURE_NEED_OBD == STD_ON)                                                                                             /* COV_MSR_UNSUPPORTED XF */
    /* suppress not qualified status bits */
    *EventUDSStatus = (Dem_UdsStatusByteType)(Dem_Event_GetQualifyStatus(EventId) & *EventUDSStatus);
#endif
    lReturnValue = E_OK;
  }
  return lReturnValue;
}

/* ****************************************************************************
 % Dem_Event_GetEventFailed
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Event_GetEventFailed(
    CONST(Dem_EventIdType, AUTOMATIC)  EventId,
    CONSTP2VAR(boolean, AUTOMATIC, DEM_APPL_DATA)  EventFailed
    )
{
  Std_ReturnType lReturnValue;
  lReturnValue = E_NOT_OK;
  if ( (Dem_Cfg_EventAvailableByVariant(EventId) == TRUE)                                                                        /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
    && (Dem_EventInternalStatus_TestEventDisconnected(Dem_Event_GetInternalStatus(EventId)) == FALSE) )
  {
    if (Dem_UDSStatus_Test_TF(Dem_Event_GetUDSStatus(EventId)) == TRUE)
    {
      *EventFailed = TRUE;                                                                                                       /* SBSW_DEM_POINTER_WRITE_API */
    }
    else
    {
      *EventFailed = FALSE;                                                                                                      /* SBSW_DEM_POINTER_WRITE_API */
    }
    lReturnValue = E_OK;
  }
  return lReturnValue;
}

/* ****************************************************************************
 % Dem_Event_GetEventTested
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
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Event_GetEventTested(
    CONST(Dem_EventIdType, AUTOMATIC)  EventId,
    CONSTP2VAR(boolean, AUTOMATIC, DEM_APPL_DATA)  EventTested
  )
{
  Std_ReturnType lReturnValue;
  lReturnValue = E_NOT_OK;
  if ( (Dem_OperationCycle_GetCurrentCycleStatus(Dem_Cfg_EventOperationCycle(EventId)) == DEM_OPERATIONCYCLE_CYCLE_STARTED)      /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
    && (Dem_Cfg_EventAvailableByVariant(EventId) == TRUE)
    && (Dem_EventInternalStatus_TestEventDisconnected(Dem_Event_GetInternalStatus(EventId)) == FALSE)
    )
  {
    if (Dem_UDSStatus_Test_TNCTOC(Dem_Event_GetUDSStatus(EventId)) == FALSE)
    {
      *EventTested = TRUE;                                                                                                       /* SBSW_DEM_POINTER_WRITE_API */
    }
    else
    {
      *EventTested = FALSE;                                                                                                      /* SBSW_DEM_POINTER_WRITE_API */
    }
    lReturnValue = E_OK;
  }
  /* else: with stopped cycle the bit value is undecided */
  return lReturnValue;
}

#if (DEM_FEATURE_NEED_OBD == STD_ON)                                                                                             /* COV_MSR_UNSUPPORTED XF */
/* ****************************************************************************
 % Dem_Event_CycleQualifyDcy
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
 */
DEM_LOCAL FUNC(void, DEM_CODE)
Dem_Event_CycleQualifyDcy(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(Dem_DTC_ForEachCombinedArgPtrType, AUTOMATIC)  ArgPtr                                                                    /* PRQA S 3206, 3673 */ /* MD_DEM_3206, MD_DEM_16.7_Internal */
)
{
  uint8 lEventStatus;
  uint8 lEventQualifyStatus;
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(ArgPtr)                                                                                       /* PRQA S 3112 */ /* MD_DEM_14.2 */

  lEventStatus = Dem_Event_GetUDSStatus(EventId);
  lEventQualifyStatus = Dem_Event_GetQualifyStatus(EventId);

  if ( (Dem_EventInternalStatus_Test_QualifyStatus_CDTC(lEventQualifyStatus) == FALSE)                                           /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
    && (Dem_UDSStatus_Test_CDTC(lEventStatus) == TRUE)
    )
  { /* set confirmed status to qualified */
    lEventQualifyStatus = Dem_EventInternalStatus_Set_QualifyStatus_CDTC(lEventQualifyStatus);

# if (DEM_FEATURE_NEED_PID01_CALCULATION == STD_ON)
    /* Set readiness group to completed */
    Dem_Util_SetReadinessGroupCompleted(TRUE, Dem_Cfg_EventReadinessGroup(EventId), &Dem_Mem_GetPid01CompletedMask());
# endif

  }

  if ( (Dem_EventInternalStatus_Test_QualifyStatus_WIR(lEventQualifyStatus) == FALSE)                                            /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
    && (Dem_UDSStatus_Test_WIR(lEventStatus) == TRUE))
  { /* set warningIndicatorRequested status to qualified */
    lEventQualifyStatus = Dem_EventInternalStatus_Set_QualifyStatus_WIR(lEventQualifyStatus);
  }

  Dem_DTC_SetQualifyStatus(EventId, lEventQualifyStatus);
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */
#endif /* (DEM_FEATURE_NEED_OBD == STD_ON) */

/* ****************************************************************************
 % Dem_Event_TestLatchedTestFailed
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Event_TestLatchedTestFailed(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  )
{
  boolean lReturnValue;

  if (Dem_Cfg_EventLatchTestFailed(EventId) == TRUE)
  {
    lReturnValue = 
      (boolean)(((DEM_UDS_STATUS_TFTOC | DEM_UDS_STATUS_CDTC) & Dem_Event_GetUDSStatus(EventId)) != 0);
  }
  else
  {
    lReturnValue = FALSE;
  }
  return lReturnValue;
}

/* ****************************************************************************
 % Dem_Event_InitNvData
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Event_InitNvData(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  )
{
  Dem_Event_SetUDSStatus(EventId, DEM_UDS_STATUS_INITIALIZE);
#if (DEM_FEATURE_NEED_PID01_CALCULATION == STD_ON) || (DEM_CFG_SUPPORT_SIMILAR_CONDITIONS == STD_ON)
  Dem_Event_SetExtendedStatus(EventId, DEM_EXT_STATUS_INITIALIZE);
#endif
#if (DEM_FEATURE_NEED_TRIPCOUNTER == STD_ON)
  Dem_Event_SetTripCount(EventId, 0);
#endif
#if (DEM_FEATURE_NEED_OBD == STD_ON) && (DEM_CFG_PROCESS_CDTC_ALL_DTC == STD_ON)                                                 /* COV_MSR_UNSUPPORTED XF xf tf */
  if (Dem_Cfg_EventObdRelated(EventId) == FALSE)
  {
    Dem_DTC_SetQualifyStatus(EventId, DEM_QUALIFICATION_STATUS_ALL_QUALIFIED);
  }
  else
  {
    Dem_DTC_SetQualifyStatus(EventId, DEM_QUALIFICATION_STATUS_ALL_UNQUALIFIED);
  }
#endif
}

/* ****************************************************************************
 % Dem_Event_Init
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
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Event_Init(
  void
  )
{
  Dem_EventIdType lEventId;

  Dem_Event_InitQualification();
  Dem_DTC_InitQualification();
  Dem_Esm_InitWwhObdStatistics();
#if (DEM_FEATURE_NEED_MIL_GROUPS == STD_ON)
  /* ----- MIL group handling at DCY restart ----- */
  {
    uint16 lMilGroupIndex;
    lMilGroupIndex = Dem_Cfg_GlobalMilGroupCount();
    while (lMilGroupIndex != DEM_CFG_MIL_GROUP_INVALID)
    {
      lMilGroupIndex--;
      Dem_EventInternalStatus_SetMilGroupPendingCount(lMilGroupIndex, 0);
    }
  }
#endif /* (DEM_FEATURE_NEED_MIL_GROUPS == STD_ON) */

  for (lEventId = DEM_EVENT_FIRST; lEventId < Dem_Cfg_GlobalEventCount(); ++lEventId)
  {
    Dem_Event_InitEventInternalStatus(lEventId);
    Dem_Event_InitEventStatus(lEventId);

#if (DEM_FEATURE_NEED_OBD == STD_ON) && (DEM_CFG_PROCESS_CDTC_ALL_DTC == STD_ON)                                                 /* COV_MSR_UNSUPPORTED XF xf tf */
    /* Set qualification state for all UDS DTCs to qualified */
    if (Dem_Cfg_EventObdRelated(lEventId) == FALSE)
    {
      Dem_DTC_SetQualifyStatus(lEventId, DEM_QUALIFICATION_STATUS_ALL_QUALIFIED);
    }
#endif
  } /* for each event */

  Dem_Event_InitAvailableNV();
  Dem_Esm_InitSpecialIndicator();
  
#if (DEM_FEATURE_NEED_MIL_GROUPS == STD_ON)                                                                                      /* COV_MSR_UNSUPPORTED XF */
  {
    uint16 lMilGroupIndex;
    lMilGroupIndex = Dem_Cfg_GlobalMilGroupCount();
    while (lMilGroupIndex != DEM_CFG_MIL_GROUP_INVALID)
    {
      lMilGroupIndex--;
      if (Dem_EventInternalStatus_GetMilGroupPendingCount(lMilGroupIndex) == 0)
      {
        Dem_Mem_ResetMilGroupTripCount(lMilGroupIndex);
      }
    }
  }
#endif /* (DEM_FEATURE_NEED_MIL_GROUPS == STD_ON) */
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */

/* ****************************************************************************
 % Dem_Event_PreInit
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Event_PreInit(
  void
  )
{
  {
    Dem_EventIdType lEventId;
    for (lEventId = DEM_EVENT_FIRST; lEventId < Dem_Cfg_GlobalEventCount(); ++lEventId)
    {
      if (Dem_Cfg_EventAvailableByDefault(lEventId) == TRUE)
      {
        Dem_Event_SetInternalStatus(lEventId, 0);
      }
      else
      {
        Dem_Event_SetInternalStatus(lEventId, Dem_EventInternalStatus_SetEventDisconnected(0));
      }
    }
  }
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */

/* ****************************************************************************
 % Dem_Event_MainFunction
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Event_MainFunction(
  void
  )
{
#if (DEM_CFG_SUPPORT_EVENTAVAILABLE == STD_ON)
  Dem_EventIdType lEventId;
  for (lEventId = DEM_EVENT_FIRST; lEventId < Dem_Cfg_GlobalEventCount(); ++lEventId)
  {
    Dem_Event_ProcessEventAvailable(lEventId);
  }
#endif
}

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* DEM_EVENT_IMPLEMENTATION_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_Event_Implementation.h
 *********************************************************************************************************************/
