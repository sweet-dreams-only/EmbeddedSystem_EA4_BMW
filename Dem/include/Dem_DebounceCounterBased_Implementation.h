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
/*!  Project    MICROSAR Diagnostic Event Manager (Dem)
 *
 *  \addtogroup Dem_DebounceCounterBased
 *  \{
 *
 *  \file       Dem_DebounceCounterBased_Implementation.h
 *  \brief      Diagnostic Event Manager (Dem) header file
 *  \details    Implementation of DebounceCounterBased subcomponent
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

#if !defined (DEM_DEBOUNCECOUNTERBASED_IMPLEMENTATION_H)
#define DEM_DEBOUNCECOUNTERBASED_IMPLEMENTATION_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                  /* Own subcomponent header */
/* ------------------------------------------------------------------------- */
#include "Dem_DebounceCounterBased_Interface.h"

                                                    /* Used subcomponent API */
/* ------------------------------------------------------------------------- */
#include "Dem_DebounceBase_Implementation.h"
#include "Dem_DebouncingState_Implementation.h"
#include "Dem_SatelliteData_Interface.h"
#include "Dem_StorageCondition_Implementation.h"
#include "Dem_EnableCondition_Implementation.h"
#include "Dem_EventInternalStatus_Implementation.h"
#include "Dem_DTC_Implementation.h"
#include "Dem_DTCInternalStatus_Implementation.h"

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
#define DEM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

DEM_LOCAL CONST(Dem_DebounceFunctionTableType, DEM_CONST) Dem_DebounceCounterBased_FunctionTable =                               /* PRQA S 3218 */ /* MD_DEM_8.7 */
{
   Dem_DebounceCounterBased_Calculate,
   Dem_DebounceCounterBased_Freeze,
   Dem_DebounceCounterBased_Reset,
   Dem_DebounceCounterBased_GetDebouncingState,
   Dem_DebounceCounterBasedSat_UpdateDebounceValueMax,
   Dem_DebounceCounterBasedSat_ResetDebounceValueMax,
   Dem_DebounceCounterBased_GetFaultDetectionCounter,
   Dem_DebounceCounterBased_GetMaxFaultDetectionCounter,
   Dem_DebounceCounterBased_GetDebouncingResult,
   Dem_DebounceCounterBased_RestoreDebounceValue
};

#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* ********************************************************************************************************************
 *  SUBCOMPONENT OBJECT FUNCTION DEFINITIONS
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  SUBCOMPONENT API FUNCTION DEFINITIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* ********************************************************************************************************************
 *  SUBCOMPONENT API PRIVATE FUNCTION DEFINITIONS
 *********************************************************************************************************************/

/*!
 * \addtogroup Dem_DebounceCounterBased_Private
 * \{
 */

/* ****************************************************************************
 % Dem_DebounceCounterBased_Base2CounterBased
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_DebounceCounterBased_InfoPtrType, DEM_CODE)
Dem_DebounceCounterBased_Base2CounterBased(
  CONST(Dem_DebounceBase_InfoPtrType, AUTOMATIC)  DebounceInfoPtr
  )
{
  return (Dem_DebounceCounterBased_InfoPtrType)DebounceInfoPtr;                                                                  /* PRQA S 0310 */ /* MD_DEM_11.4_inh */
}

/* ****************************************************************************
 % Dem_DebounceCounterBased_ConstBase2CounterBased
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_DebounceCounterBased_ConstInfoPtrType, DEM_CODE)
Dem_DebounceCounterBased_ConstBase2CounterBased(
  CONST(Dem_DebounceBase_ConstInfoPtrType, AUTOMATIC)  DebounceInfoPtr
  )
{
  return (Dem_DebounceCounterBased_ConstInfoPtrType)DebounceInfoPtr;                                                             /* PRQA S 0310 */ /* MD_DEM_11.4_inh */
}

/* ****************************************************************************
 % Dem_DebounceCounterBased_GetNewDebounceValue
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(sint16, DEM_CODE)
Dem_DebounceCounterBased_GetNewDebounceValue(
  CONST(Dem_DebounceBase_ConstInfoPtrType, AUTOMATIC)  DebounceInfoPtr
  )
{
  return Dem_DebounceCounterBased_ConstBase2CounterBased(DebounceInfoPtr)->NewDebounceValue;
}

/* ****************************************************************************
 % Dem_DebounceCounterBased_SetNewDebounceValue
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_DebounceCounterBased_SetNewDebounceValue(
  CONST(Dem_DebounceBase_InfoPtrType, AUTOMATIC)  DebounceInfoPtr,
  CONST(sint16, AUTOMATIC)  DebounceValue
  )
{
  Dem_DebounceCounterBased_Base2CounterBased(DebounceInfoPtr)->NewDebounceValue = DebounceValue;
}

/* ****************************************************************************
 % Dem_DebounceCounterBased_CalculateFaultDetectionCounter
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
DEM_LOCAL_INLINE FUNC(sint8, DEM_CODE)
Dem_DebounceCounterBased_CalculateFaultDetectionCounter(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(sint16, AUTOMATIC)  DebounceValue
  )
{
  sint8 lReturnedFdc;

  if (DebounceValue == 0)
  {
    lReturnedFdc = 0;
  }
  else
  {
    sint16 lFailedTarget = Dem_Cfg_EventFailedTarget(EventId);
    sint16 lPassedTarget = Dem_Cfg_EventPassedTarget(EventId);

    if (DebounceValue == lFailedTarget)
    {
      lReturnedFdc = 127;
    }
    else if (DebounceValue == lPassedTarget)
    {
      lReturnedFdc = -128;
    }
    else
    { /* current debounce counter value is somewhere in range of passed threshold and failed threshold but not 0 */
      if (DebounceValue > 0)
      {
        lReturnedFdc = (sint8)(((sint32)DebounceValue * 127) / lFailedTarget);
        /* result has to be greater than 0 */
        if (lReturnedFdc == 0)
        {
          lReturnedFdc = 1;
        }
      }
      else
      {
        lReturnedFdc = (sint8)(((sint32)DebounceValue * -128)  / lPassedTarget);
        /* result has to be smaller than 0 */
        if (lReturnedFdc == 0)
        {
          lReturnedFdc = -1;
        }
      }
    }
  }

  return lReturnedFdc;
}                                                                                                                                /* PRQA S 6080 */ /* MD_MSR_STMIF */

/* ****************************************************************************
 % Dem_DebounceCounterBased_CalculatePrepassed
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
Dem_DebounceCounterBased_CalculatePrepassed(
  CONST(Dem_DebounceCounterBased_InfoPtrType, AUTOMATIC)  DebounceInfoData
  )
{
  Dem_EventIdType lEventId;
  sint16 lJumpToValue;
  boolean lEnableConditionsSatisfied;

  lEventId = Dem_DebounceBase_GetEventId(&(DebounceInfoData->Base));
  lJumpToValue = Dem_Cfg_EventJumpDownValue(lEventId);
  lEnableConditionsSatisfied = Dem_EnableCondition_TestEventEnableConditionsFulfilled(lEventId);

  if (DebounceInfoData->OldDebounceValue > lJumpToValue)
  {
    if (Dem_Cfg_EventSupportJumpDown(lEventId) == TRUE)
    {
      /* JumpDown */
      DebounceInfoData->NewDebounceValue = lJumpToValue;
    }
  }

  if (DebounceInfoData->NewDebounceValue <=
    (Dem_Cfg_EventPassedTarget(lEventId) - Dem_Cfg_EventPrepassedStep(lEventId))) /* No overflow possible */
  {
    DebounceInfoData->NewDebounceValue = Dem_Cfg_EventPassedTarget(lEventId);
    if (lEnableConditionsSatisfied == TRUE)
    {
      /* qualified result, set result and final de-bounce counter */
      Dem_DebounceBase_SetMonitorTrigger(&(DebounceInfoData->Base), DEM_EVENT_STATUS_PASSED);
    }
  }
  else
  {
    DebounceInfoData->NewDebounceValue = (sint16)
      (DebounceInfoData->NewDebounceValue + Dem_Cfg_EventPrepassedStep(lEventId)); /* No overflow possible */
  }
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */

/* ****************************************************************************
 % Dem_DebounceCounterBased_CalculatePassed
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_DebounceCounterBased_CalculatePassed(
  CONST(Dem_DebounceCounterBased_InfoPtrType, AUTOMATIC)  DebounceInfoData
  )
{
  Dem_EventIdType lEventId;
  boolean lEnableConditionsSatisfied;

  lEventId = Dem_DebounceBase_GetEventId(&(DebounceInfoData->Base));
  lEnableConditionsSatisfied = Dem_EnableCondition_TestEventEnableConditionsFulfilled(lEventId);

  /* Qualified result - directly load threshold de-bounce counter from configuration */
  /* This also reduces exceeded counter values to match the passed threshold exactly (latch at bottom) */
  DebounceInfoData->NewDebounceValue = Dem_Cfg_EventPassedTarget(lEventId);
  if (lEnableConditionsSatisfied == FALSE)
  {
    Dem_DebounceBase_SetMonitorTrigger(&(DebounceInfoData->Base), DEM_EVENT_STATUS_PREPASSED);
  }
}

/* ****************************************************************************
 % Dem_DebounceCounterBased_CalculatePrefailed
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
Dem_DebounceCounterBased_CalculatePrefailed(
  CONST(Dem_DebounceCounterBased_InfoPtrType, AUTOMATIC)  DebounceInfoData
  )
{
  Dem_EventIdType lEventId;
  sint16 lJumpToValue;
  boolean lEnableConditionsSatisfied;

  lEventId = Dem_DebounceBase_GetEventId(&(DebounceInfoData->Base));
  lJumpToValue = Dem_Cfg_EventJumpUpValue(lEventId);
  lEnableConditionsSatisfied = Dem_EnableCondition_TestEventEnableConditionsFulfilled(lEventId);

  if (DebounceInfoData->OldDebounceValue < lJumpToValue)
  {
    if (Dem_Cfg_EventSupportJumpUp(lEventId) == TRUE)
    {
      /* JumpUp */
      DebounceInfoData->NewDebounceValue = lJumpToValue;
    }
  }

  if (DebounceInfoData->NewDebounceValue >=
    (Dem_Cfg_EventFailedTarget(lEventId) - Dem_Cfg_EventPrefailedStep(lEventId))) /* No overflow possible */
  {
    /* qualified result, set result and final de-bounce counter */
    DebounceInfoData->NewDebounceValue = Dem_Cfg_EventFailedTarget(lEventId);
    if (lEnableConditionsSatisfied == TRUE)
    {
      Dem_DebounceBase_SetMonitorTrigger(&(DebounceInfoData->Base), DEM_EVENT_STATUS_FAILED);
    }
  }
  else
  {
    DebounceInfoData->NewDebounceValue = (sint16)
      (DebounceInfoData->NewDebounceValue + Dem_Cfg_EventPrefailedStep(lEventId));  /* No overflow possible */
  }
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */

/* ****************************************************************************
 % Dem_DebounceCounterBased_CalculateFailed
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_DebounceCounterBased_CalculateFailed(
  CONST(Dem_DebounceCounterBased_InfoPtrType, AUTOMATIC)  DebounceInfoData
  )
{
  Dem_EventIdType lEventId;
  boolean lEnableConditionsSatisfied;

  lEventId = Dem_DebounceBase_GetEventId(&(DebounceInfoData->Base));
  lEnableConditionsSatisfied = Dem_EnableCondition_TestEventEnableConditionsFulfilled(lEventId);

  /* Qualified result - directly load threshold de-bounce counter from configuration */
  /* This also reduces counter values to match the failed threshold exactly (latch at ceiling) */
  DebounceInfoData->NewDebounceValue = Dem_Cfg_EventFailedTarget(lEventId);

  if (lEnableConditionsSatisfied == FALSE)
  {
    Dem_DebounceBase_SetMonitorTrigger(&(DebounceInfoData->Base), DEM_EVENT_STATUS_PREFAILED);
  }
}

/*!
 * \}
 */

/* ********************************************************************************************************************
 *  SUBCOMPONENT API FUNCTION IMPLEMENTATION
 *********************************************************************************************************************/
/*!
 * \addtogroup Dem_DebounceCounterBased_Public
 * \{
 */

/* ****************************************************************************
 % Dem_DebounceCounterBased_InfoInit
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_DebounceBase_InfoPtrType, DEM_CODE)
Dem_DebounceCounterBased_InfoInit(
  CONSTP2VAR(Dem_DebounceCounterBased_InfoType, AUTOMATIC, AUTOMATIC) DebounceInfoData,
  CONST(Dem_EventIdType, AUTOMATIC) EventId,
  CONST(Dem_SatelliteData_DataType, AUTOMATIC)  SatelliteData
  )
{
  Dem_DebounceBase_InfoPtrType lReturnValue;
  lReturnValue = Dem_DebounceBase_InfoInitDefault(&(DebounceInfoData->Base), &Dem_DebounceCounterBased_FunctionTable, EventId);
  DebounceInfoData->OldDebounceValue = (sint16) Dem_SatelliteData_GetDebounceData(SatelliteData);
  DebounceInfoData->NewDebounceValue = (sint16) Dem_SatelliteData_GetDebounceData(SatelliteData);
  return lReturnValue;
}

/* ****************************************************************************
 % Dem_DebounceCounterBased_Calculate
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
 */
DEM_LOCAL FUNC(boolean, DEM_CODE)
Dem_DebounceCounterBased_Calculate(
  CONST(Dem_DebounceBase_InfoPtrType, AUTOMATIC)  DebounceInfoPtr
  )
{
  Dem_EventIdType lEventId;
  Dem_DebounceCounterBased_InfoPtrType lDebounceInfo;
  boolean lEnableConditionsSatisfied;
  boolean lReturnValue;

  lEventId = Dem_DebounceBase_GetEventId(DebounceInfoPtr);
  lDebounceInfo = Dem_DebounceCounterBased_Base2CounterBased(DebounceInfoPtr);
  lEnableConditionsSatisfied = Dem_EnableCondition_TestEventEnableConditionsFulfilled(lEventId);

  /* Monitor status for this event not supported */
  if (Dem_DebounceBase_GetMonitorTrigger(DebounceInfoPtr) == DEM_EVENT_STATUS_FDC_THRESHOLD_REACHED)
  {
    Dem_Error_ReportError(DEM_INTERNAL_APIID, DEM_E_PARAM_DATA);
    lReturnValue = FALSE;
  }
  else
  {
    if ( (lEnableConditionsSatisfied == TRUE)                                                                                    /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
      || (Dem_Cfg_EventDebounceContinuous(lEventId) == TRUE) )
    {
      switch (Dem_DebounceBase_GetMonitorTrigger(DebounceInfoPtr))
      {
      case DEM_EVENT_STATUS_PREPASSED:
        Dem_DebounceCounterBased_CalculatePrepassed(lDebounceInfo);
        break;

      case DEM_EVENT_STATUS_PASSED:
        Dem_DebounceCounterBased_CalculatePassed(lDebounceInfo);
        break;

      case DEM_EVENT_STATUS_PREFAILED:
        Dem_DebounceCounterBased_CalculatePrefailed(lDebounceInfo);
        break;

      case DEM_EVENT_STATUS_FAILED:
        Dem_DebounceCounterBased_CalculateFailed(lDebounceInfo);
        break;

      default:
        /* Satisfy Misra */
        break;
      }

#if (DEM_CFG_SUPPORT_RETRY_STORAGE == STD_ON)
      if ( (lEnableConditionsSatisfied == TRUE)                                                                                  /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
        && (Dem_DebounceBase_GetMonitorTrigger(DebounceInfoPtr) == DEM_EVENT_STATUS_FAILED)
        && (Dem_DTCInternalStatus_GetStoredStatus(Dem_DTC_GetInternalStatus(lEventId)) == Dem_DTCInternalStatus_StoredStatus_None))
      {
        Dem_DebounceBase_SetDebouncingChanged(DebounceInfoPtr);
      }
      else
#endif
      {
        if (lDebounceInfo->OldDebounceValue != lDebounceInfo->NewDebounceValue)
        {
          Dem_DebounceBase_SetDebouncingChanged(DebounceInfoPtr);
        }
      }

#if (DEM_FEATURE_NEED_OEM_EXTENSIONS_VCC == STD_ON)
      if(lDebounceInfo->NewDebounceValue >= Dem_Cfg_EventPreconfirmedTarget(lEventId))
      {
        Dem_DebounceBase_SetRequestFdcProcessing(DebounceInfoPtr);
      }
      if (lDebounceInfo->NewDebounceValue > Dem_DebounceBaseSat_GetDebounceValueMax(lEventId))
      {
        Dem_DebounceBase_SetMaximumFdcExceeded(DebounceInfoPtr);
      }
#else
      if (lEnableConditionsSatisfied == TRUE)
      {
        if ((lDebounceInfo->NewDebounceValue >= Dem_Cfg_EventStorageTarget(lEventId))                                            /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
          && (lDebounceInfo->OldDebounceValue < Dem_Cfg_EventStorageTarget(lEventId)))
        {
          Dem_DebounceBase_SetFdcThresholdExceeded(DebounceInfoPtr);
          Dem_DebounceBase_SetRequestFdcProcessing(DebounceInfoPtr);
        }
        /* Possible update of SLC based on update of TOC */
        if (lDebounceInfo->NewDebounceValue > Dem_DebounceBaseSat_GetDebounceValueMax(lEventId))
        {
          Dem_DebounceBase_SetMaximumFdcExceeded(DebounceInfoPtr);
          Dem_DebounceBase_SetRequestFdcProcessing(DebounceInfoPtr);
        }
      }
#endif
      lReturnValue = TRUE;
    } /* (lEnableConditionsSatisfied == TRUE) || (Dem_Cfg_EventDebounceContinuous(lEventId) == TRUE) */
    else
    {
      lReturnValue = FALSE;
    }
  }
  return lReturnValue;
}                                                                                                                                /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* ****************************************************************************
 % Dem_DebounceCounterBased_Freeze
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL FUNC(void, DEM_CODE)
Dem_DebounceCounterBased_Freeze(
  CONST(Dem_DebounceBase_InfoPtrType, AUTOMATIC)  DebounceInfoPtr                                                                /* PRQA S 3206, 3673 */ /* MD_DEM_3206, MD_DEM_16.7_Internal */
  )
{
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(DebounceInfoPtr)                                                                              /* PRQA S 3112 */ /* MD_DEM_14.2 */
  /* No action necessary */
}

/* ****************************************************************************
 % Dem_DebounceCounterBasedSat_Reset
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL FUNC(void, DEM_CODE)
Dem_DebounceCounterBased_Reset(
  CONST(Dem_DebounceBase_InfoPtrType, AUTOMATIC)  DebounceInfoPtr                                                                /* PRQA S 3673 */ /* MD_DEM_16.7_Internal */
  )
{
  Dem_DebounceCounterBased_SetNewDebounceValue(DebounceInfoPtr, DEM_DEBOUNCE_COUNTERBASED_INIT_VALUE);
}

/* ****************************************************************************
 % Dem_DebounceCounterBased_GetDebouncingState
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
DEM_LOCAL FUNC(Dem_DebouncingStateType, DEM_CODE)
Dem_DebounceCounterBased_GetDebouncingState(
  CONST(Dem_DebounceBase_ConstInfoPtrType, AUTOMATIC)  DebounceInfoPtr                                                           /* PRQA S 3673 */ /* MD_DEM_16.7_Internal */
  )
{
  Dem_EventIdType lEventId;
  Dem_DebouncingStateType lDebouncingState;

  lEventId = Dem_DebounceBase_GetEventId(DebounceInfoPtr);
  lDebouncingState = Dem_DebouncingState_GetInitValue();

  if (Dem_DebounceCounterBased_GetNewDebounceValue(DebounceInfoPtr) == Dem_Cfg_EventFailedTarget(lEventId))
  {
    lDebouncingState = Dem_DebouncingState_SetFinallyDefective(lDebouncingState);
    lDebouncingState = Dem_DebouncingState_SetTestComplete(lDebouncingState);
    if ( (Dem_EnableCondition_TestEventEnableConditionsFulfilled(lEventId) == TRUE)                                                          /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
      && (Dem_StorageCondition_TestEventStorageConditionsFulfilled(lEventId) == TRUE) )
    {
      lDebouncingState = Dem_DebouncingState_SetDtrUpdate(lDebouncingState);
    }
  }
  else if (Dem_DebounceCounterBased_GetNewDebounceValue(DebounceInfoPtr) == Dem_Cfg_EventPassedTarget(lEventId))
  {
    lDebouncingState = Dem_DebouncingState_SetTestComplete(lDebouncingState);
    if ((Dem_EnableCondition_TestEventEnableConditionsFulfilled(lEventId) == TRUE)                                                           /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
      && (Dem_StorageCondition_TestEventStorageConditionsFulfilled(lEventId) == TRUE))
    {
      lDebouncingState = Dem_DebouncingState_SetDtrUpdate(lDebouncingState);
    }
  }
  else if (Dem_DebounceCounterBased_GetNewDebounceValue(DebounceInfoPtr) > 0)
  {
    lDebouncingState = Dem_DebouncingState_SetTemporarilyDefective(lDebouncingState);
  }
  else if (Dem_DebounceCounterBased_GetNewDebounceValue(DebounceInfoPtr) < 0)
  {
    lDebouncingState = Dem_DebouncingState_SetTemporarilyHealed(lDebouncingState);
  }
  else
  {
    /* de-bouncing state 0 */
  }

  return lDebouncingState;
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */

/* ****************************************************************************
 % Dem_DebounceCounterBasedSat_UpdateDebounceValueMax
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL FUNC(void, DEM_CODE)
Dem_DebounceCounterBasedSat_UpdateDebounceValueMax(
  CONST(Dem_DebounceBase_ConstInfoPtrType, AUTOMATIC)  DebounceInfoPtr
  )
{
  Dem_EventIdType lEventId;
  lEventId = Dem_DebounceBase_GetEventId(DebounceInfoPtr);
  Dem_DebounceBaseSat_SetDebounceValueMax(lEventId, Dem_DebounceCounterBased_GetNewDebounceValue(DebounceInfoPtr));
}

/* ****************************************************************************
 % Dem_DebounceCounterBasedSat_ResetDebounceValueMax
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL FUNC(void, DEM_CODE)
Dem_DebounceCounterBasedSat_ResetDebounceValueMax(
  CONST(Dem_DebounceBase_ConstInfoPtrType, AUTOMATIC)  DebounceInfoPtr
  )
{
  Dem_EventIdType lEventId;
  lEventId = Dem_DebounceBase_GetEventId(DebounceInfoPtr);
  Dem_DebounceBaseSat_SetDebounceValueMax(lEventId, 0);
}

/* ****************************************************************************
 * Dem_DebounceCounterBased_GetFaultDetectionCounter
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL FUNC(Std_ReturnType, DEM_CODE)
Dem_DebounceCounterBased_GetFaultDetectionCounter(
  CONST(Dem_DebounceBase_ConstInfoPtrType, AUTOMATIC) DebounceInfoPtr,
  P2VAR(sint8, AUTOMATIC, DEM_APPL_DATA) FaultDetectionCounter
  )
{
  Dem_EventIdType lEventId;

  lEventId = Dem_DebounceBase_GetEventId(DebounceInfoPtr);

  *FaultDetectionCounter = Dem_DebounceCounterBased_CalculateFaultDetectionCounter(
                             lEventId,
                             Dem_DebounceCounterBased_GetNewDebounceValue(DebounceInfoPtr));

  return E_OK;
}

/* *****************************************************************************
 % Dem_DebounceCounterBased_GetMaxFaultDetectionCounter
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_DebounceCounterBased_GetMaxFaultDetectionCounter(
  CONST(Dem_DebounceBase_ConstInfoPtrType, AUTOMATIC) DebounceInfoPtr,
  P2VAR(sint8, AUTOMATIC, DEM_APPL_DATA) FaultDetectionCounter
  )
{
  Dem_EventIdType lEventId;
  lEventId = Dem_DebounceBase_GetEventId(DebounceInfoPtr);
  *FaultDetectionCounter = Dem_DebounceCounterBased_CalculateFaultDetectionCounter(
                             lEventId,
                             Dem_DebounceBaseSat_GetDebounceValueMax(lEventId));
  return E_OK;
}

/* ****************************************************************************
 % Dem_DebounceCounterBased_GetDebouncingResult
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_SatelliteData_DataType, DEM_CODE)
Dem_DebounceCounterBased_GetDebouncingResult(
  CONST(Dem_DebounceBase_ConstInfoPtrType, AUTOMATIC)  DebounceInfoPtr,
  CONST(Dem_SatelliteData_DataType, AUTOMATIC)  SatelliteData
  )
{
  Dem_SatelliteData_DataType lReturnValue;                                                                                       /* PRQA S 0759 */ /* MD_MSR_18.4 */
  lReturnValue = Dem_SatelliteData_SetDebounceData(
                    SatelliteData,
                    (Dem_Debounce_DataType) Dem_DebounceCounterBased_GetNewDebounceValue(DebounceInfoPtr));
  return lReturnValue;
}

/* ****************************************************************************
 * Dem_DebounceCounterBased_RestoreDebounceValue()
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
DEM_LOCAL FUNC(Dem_SatelliteData_DataType, DEM_CODE)
Dem_DebounceCounterBased_RestoreDebounceValue(
  CONST(Dem_DebounceBase_ConstInfoPtrType, AUTOMATIC) DebounceInfoPtr,
  CONST(Dem_SatelliteData_DataType, AUTOMATIC) SatelliteData,
  CONST(sint16, AUTOMATIC) Value,
  CONST(boolean, AUTOMATIC) ExpectedThreshold
  )
{
  Dem_EventIdType lEventId;
  Dem_SatelliteData_DataType lReturnValue;                                                                                       /* PRQA S 0759 */ /* MD_MSR_18.4 */

  lEventId = Dem_DebounceBase_GetEventId(DebounceInfoPtr);

  if ( /* Unqualified de-bounce state is ok */
       ( (Dem_Cfg_EventFailedTarget(lEventId) > Value) && (Dem_Cfg_EventPassedTarget(lEventId) < Value) )                        /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
       /* If de-bouncing counter has reached qualified threshold, the event status must match */
    || ( (Dem_Cfg_EventFailedTarget(lEventId) == Value) && (ExpectedThreshold == TRUE))
    || ( (Dem_Cfg_EventPassedTarget(lEventId) == Value) && (ExpectedThreshold == FALSE)) )
  {
    lReturnValue = Dem_SatelliteData_SetDebounceData(
                      SatelliteData,
                      (Dem_Debounce_DataType) Value);
  }
  else
  {
    lReturnValue = SatelliteData;
  }

  return lReturnValue;
}

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* DEM_DEBOUNCECOUNTERBASED_IMPLEMENTATION_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_DebounceCounterBased_Implementations.h
 *********************************************************************************************************************/
