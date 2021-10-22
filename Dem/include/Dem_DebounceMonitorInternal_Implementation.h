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
/*! \addtogroup Dem_DebounceMonitorInternal
 *  \{
 *  \file       Dem_DebounceMonitorInternal_Implementation.h
 *  \brief      Implementation file for the MICROSAR Dem
 *  \details    Implementation of DebounceMonitorInternal subcomponent
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

#if !defined (DEM_DEBOUNCEMONITORINTERNAL_IMPLEMENTATION_H)
#define DEM_DEBOUNCEMONITORINTERNAL_IMPLEMENTATION_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                  /* Own subcomponent header */
/* ------------------------------------------------------------------------- */
#include "Dem_DebounceMonitorInternal_Interface.h"

                                                    /* Used subcomponent API */
/* ------------------------------------------------------------------------- */
#include "Dem_DebounceBase_Implementation.h"
#include "Dem_DebouncingState_Implementation.h"
#include "Dem_StorageCondition_Implementation.h"
#include "Dem_SatelliteData_Implementation.h"
#include "Dem_EnableCondition_Implementation.h"
#include "Dem_DTC_Implementation.h"
#include "Dem_DTCInternalStatus_Implementation.h"
#include "Dem_EventInternalStatus_Implementation.h"

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

DEM_LOCAL CONST(Dem_DebounceFunctionTableType, DEM_CONST) Dem_DebounceMonitorInternal_FunctionTable =                            /* PRQA S 3218 */ /* MD_DEM_8.7 */
{
  Dem_DebounceMonitorInternal_Calculate,
  Dem_DebounceMonitorInternal_Freeze,
  Dem_DebounceMonitorInternal_Reset,
  Dem_DebounceMonitorInternal_GetDebouncingState,
  Dem_DebounceMonitorInternalSat_UpdateDebounceValueMax,
  Dem_DebounceMonitorInternalSat_ResetDebounceValueMax,
  Dem_DebounceMonitorInternal_GetFaultDetectionCounter,
  Dem_DebounceMonitorInternal_GetMaxFaultDetectionCounter,
  Dem_DebounceMonitorInternal_GetDebouncingResult,
  Dem_DebounceMonitorInternal_RestoreDebounceValue
};

#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* ********************************************************************************************************************
 *  SUBCOMPONENT PRIVATE FUNCTION DEFINITIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \addtogroup Dem_DebounceMonitorInternal_Private
 * \{
 */

/* ****************************************************************************
 % Dem_DebounceMonitorInternal_Base2MonitorInternal
 *****************************************************************************/
 /*!
  * Internal comment removed.
 *
 *
  *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_DebounceMonitorInternal_InfoPtrType, DEM_CODE)
 Dem_DebounceMonitorInternal_Base2MonitorInternal(
     Dem_DebounceBase_InfoPtrType DebounceInfoPtr
  )
{
  return (Dem_DebounceMonitorInternal_InfoPtrType)DebounceInfoPtr;                                                               /* PRQA S 0310 */ /* MD_DEM_11.4_inh */
}

/* ****************************************************************************
 % Dem_DebounceMonitorInternal_ConstBase2MonitorInternal
 *****************************************************************************/
 /*!
  * Internal comment removed.
 *
 *
  *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_DebounceMonitorInternal_ConstInfoPtrType, DEM_CODE)
Dem_DebounceMonitorInternal_ConstBase2MonitorInternal(
     Dem_DebounceBase_ConstInfoPtrType DebounceInfoPtr
  )
{
  return (Dem_DebounceMonitorInternal_ConstInfoPtrType)DebounceInfoPtr;                                                          /* PRQA S 0310 */ /* MD_DEM_11.4_inh */
}

/* ****************************************************************************
 % Dem_DebounceMonitorInternal_GetNewMonitorStatus
 *****************************************************************************/
/*!
  * Internal comment removed.
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_DebounceMonitorInternal_GetNewMonitorStatus(
  CONST(Dem_DebounceBase_ConstInfoPtrType, AUTOMATIC)  DebounceInfoPtr
  )
{
  return Dem_DebounceMonitorInternal_ConstBase2MonitorInternal(DebounceInfoPtr)->NewMonitorStatus;
}

/* ****************************************************************************
 % Dem_DebounceMonitorInternal_SetNewMonitorStatus
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_DebounceMonitorInternal_SetNewMonitorStatus(
  CONST(Dem_DebounceBase_InfoPtrType, AUTOMATIC)  DebounceInfoPtr,
  CONST(uint8, AUTOMATIC)  MonitorTrigger
  )
{
  Dem_DebounceMonitorInternal_Base2MonitorInternal(DebounceInfoPtr)->NewMonitorStatus = MonitorTrigger;
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
 * \addtogroup Dem_DebounceMonitorInternal_Public
 * \{
 */

/* ****************************************************************************
 % Dem_DebounceMonitorInternal_InfoInit
 *****************************************************************************/
 /*!
  * Internal comment removed.
 *
 *
 *
 *
 *
  */
DEM_LOCAL_INLINE FUNC(Dem_DebounceBase_InfoPtrType, DEM_CODE)
Dem_DebounceMonitorInternal_InfoInit(
  CONSTP2VAR(Dem_DebounceMonitorInternal_InfoType, AUTOMATIC, AUTOMATIC) DebounceInfoData,
  CONST(Dem_EventIdType, AUTOMATIC) EventId,
  CONST(Dem_SatelliteData_DataType, AUTOMATIC)  SatelliteData
  )
{
  Dem_DebounceBase_InfoPtrType lReturnValue;
  lReturnValue = Dem_DebounceBase_InfoInitDefault(&(DebounceInfoData->Base), &Dem_DebounceMonitorInternal_FunctionTable, EventId);
  DebounceInfoData->OldMonitorStatus = (uint8) Dem_SatelliteData_GetDebounceData(SatelliteData);
  DebounceInfoData->NewMonitorStatus = DebounceInfoData->OldMonitorStatus;
  return lReturnValue;
}

/* ****************************************************************************
 % Dem_DebounceMonitorInternal_Calculate
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
DEM_LOCAL FUNC(boolean, DEM_CODE)
Dem_DebounceMonitorInternal_Calculate(
  CONST(Dem_DebounceBase_InfoPtrType, AUTOMATIC)  DebounceInfoPtr
  )
{
  boolean lReturnValue;
  boolean lDebouncingChanged;
  Dem_DebounceMonitorInternal_InfoPtrType lMonitorInternalInfo;
  Dem_EventStatusType lMonitorStatus;

  lReturnValue = FALSE;
  lDebouncingChanged = FALSE;
  lMonitorStatus = Dem_DebounceBase_GetMonitorTrigger(DebounceInfoPtr);
  lMonitorInternalInfo = Dem_DebounceMonitorInternal_Base2MonitorInternal(DebounceInfoPtr);

  /* No debouncing for this event supported */
  if ( (lMonitorStatus == DEM_EVENT_STATUS_PREPASSED)
    || (lMonitorStatus == DEM_EVENT_STATUS_PREFAILED) )
  {
    Dem_Error_ReportError(DEM_INTERNAL_APIID, DEM_E_PARAM_DATA);
  }
  else
  {
    boolean lEnableConditionsSatisfied;
    Dem_EventIdType lEventId;

    lEventId = Dem_DebounceBase_GetEventId(DebounceInfoPtr);
    lEnableConditionsSatisfied = Dem_EnableCondition_TestEventEnableConditionsFulfilled(lEventId);

    if (lEnableConditionsSatisfied == TRUE)
    {
      switch (lMonitorStatus)
      {
      case DEM_EVENT_STATUS_FAILED:
        lMonitorInternalInfo->NewMonitorStatus = DEM_DEBOUNCE_MONITORINTERNAL_STATUS_FAILED;                                     /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
        if (lMonitorInternalInfo->OldMonitorStatus != DEM_DEBOUNCE_MONITORINTERNAL_STATUS_FAILED)
        {
          Dem_DebounceBase_SetMaximumFdcExceeded(DebounceInfoPtr);
        }
        lReturnValue = TRUE;
        break;
      case DEM_EVENT_STATUS_PASSED:
        lMonitorInternalInfo->NewMonitorStatus = DEM_DEBOUNCE_MONITORINTERNAL_STATUS_PASSED;                                     /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
        lReturnValue = TRUE;
        break;
      case DEM_EVENT_STATUS_FDC_THRESHOLD_REACHED:
        lMonitorInternalInfo->NewMonitorStatus = DEM_DEBOUNCE_MONITORINTERNAL_STATUS_FDCTHRESHOLDREACHED;                        /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
        Dem_DebounceBase_SetFdcThresholdExceeded(DebounceInfoPtr);
        Dem_DebounceBase_SetRequestFdcProcessing(DebounceInfoPtr);
        lReturnValue = TRUE;
        lDebouncingChanged = TRUE;
        break;
      default:
        Dem_Internal_AssertAlways(DEM_E_INCONSISTENT_STATE)
        break;
      }

      if (lReturnValue == TRUE)
      {
#if (DEM_CFG_SUPPORT_RETRY_STORAGE == STD_ON)
        lDebouncingChanged |= (boolean)                                                                                          /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
          ( ((lMonitorInternalInfo->NewMonitorStatus == DEM_DEBOUNCE_MONITORINTERNAL_STATUS_FAILED)
          || (lMonitorInternalInfo->NewMonitorStatus == DEM_DEBOUNCE_MONITORINTERNAL_STATUS_FDCTHRESHOLDREACHED))
          && (Dem_DTCInternalStatus_GetStoredStatus(Dem_DTC_GetInternalStatus(lEventId)) == Dem_DTCInternalStatus_StoredStatus_None) );
#endif

        lDebouncingChanged |= (boolean)(lMonitorInternalInfo->NewMonitorStatus != lMonitorInternalInfo->OldMonitorStatus);

        if (lDebouncingChanged == TRUE)
        {
          Dem_DebounceBase_SetDebouncingChanged(DebounceInfoPtr);
        }
      }
    }
  }
  return lReturnValue;
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */

/* ****************************************************************************
 % Dem_DebounceMonitorInternal_Freeze
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL FUNC(void, DEM_CODE)
Dem_DebounceMonitorInternal_Freeze(
  CONST(Dem_DebounceBase_InfoPtrType, AUTOMATIC)  DebounceInfoPtr                                                                /* PRQA S 3206, 3673 */ /* MD_DEM_3206, MD_DEM_16.7_Internal */
  )
{
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(DebounceInfoPtr)                                                                              /* PRQA S 3112 */ /* MD_DEM_14.2 */
}

/* ****************************************************************************
 % Dem_DebounceMonitorInternal_Reset
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL FUNC(void, DEM_CODE)
Dem_DebounceMonitorInternal_Reset(
  CONST(Dem_DebounceBase_InfoPtrType, AUTOMATIC)  DebounceInfoPtr                                                                /* PRQA S 3206, 3673 */ /* MD_DEM_3206, MD_DEM_16.7_Internal */
  )
{
  Dem_DebounceMonitorInternal_SetNewMonitorStatus(DebounceInfoPtr, DEM_DEBOUNCE_MONITORINTERNAL_STATUS_NONE);
}

/* ****************************************************************************
 % Dem_DebounceMonitorInternal_GetDebouncingState
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
DEM_LOCAL FUNC(Dem_DebouncingStateType, DEM_CODE)
Dem_DebounceMonitorInternal_GetDebouncingState(
  CONST(Dem_DebounceBase_ConstInfoPtrType, AUTOMATIC)  DebounceInfoPtr                                                           /* PRQA S 3673 */ /* MD_DEM_16.7_Internal */
  )
{
  Dem_DebouncingStateType lDebouncingState;
  Dem_EventIdType lEventId;

  lEventId = Dem_DebounceBase_GetEventId(DebounceInfoPtr);
  lDebouncingState = Dem_DebouncingState_GetInitValue();

  if (Dem_Cfg_EventCbkGetFDC(lEventId) != NULL_PTR)
  {
    Std_ReturnType lReturnValue;
    sint8 lFaultDetectionCounter;
    lReturnValue = (*Dem_Cfg_EventCbkGetFDC(lEventId))(&lFaultDetectionCounter);
    if (lReturnValue == E_OK)
    {
      if (lFaultDetectionCounter == 127)
      {
        lDebouncingState = Dem_DebouncingState_SetFinallyDefective(lDebouncingState);
        lDebouncingState = Dem_DebouncingState_SetTestComplete(lDebouncingState);
        if ((Dem_EnableCondition_TestEventEnableConditionsFulfilled(lEventId) == TRUE)                                                       /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
          && (Dem_StorageCondition_TestEventStorageConditionsFulfilled(lEventId) == TRUE))
        {
          lDebouncingState = Dem_DebouncingState_SetDtrUpdate(lDebouncingState);
        }
      }
      else if (lFaultDetectionCounter == -128)
      {
        lDebouncingState = Dem_DebouncingState_SetTestComplete(lDebouncingState);
        if ((Dem_EnableCondition_TestEventEnableConditionsFulfilled(lEventId) == TRUE)                                                       /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
          && (Dem_StorageCondition_TestEventStorageConditionsFulfilled(lEventId) == TRUE))
        {
          lDebouncingState = Dem_DebouncingState_SetDtrUpdate(lDebouncingState);
        }
      }
      else if (lFaultDetectionCounter > 0)
      {
        lDebouncingState = Dem_DebouncingState_SetTemporarilyDefective(lDebouncingState);
      }
      else if (lFaultDetectionCounter < 0)
      {
        lDebouncingState = Dem_DebouncingState_SetTemporarilyHealed(lDebouncingState);
      }
      else
      {
        /* debouncing state 0 */
      }
    }
  }

  return lDebouncingState;
}                                                                                                                                /* PRQA S 6050, 6080 */ /* MD_MSR_STCAL, MD_MSR_STMIF */

/* ****************************************************************************
 % Dem_DebounceMonitorInternalSat_UpdateDebounceValueMax
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL FUNC(void, DEM_CODE)
Dem_DebounceMonitorInternalSat_UpdateDebounceValueMax(
  CONST(Dem_DebounceBase_ConstInfoPtrType, AUTOMATIC)  DebounceInfoPtr
  )
{
  Dem_EventIdType lEventId;
  Dem_DebounceMonitorInternal_ConstInfoPtrType lMonitorInternalInfo;

  lEventId = Dem_DebounceBase_GetEventId(DebounceInfoPtr);
  lMonitorInternalInfo = Dem_DebounceMonitorInternal_ConstBase2MonitorInternal(DebounceInfoPtr);

  if (lMonitorInternalInfo->NewMonitorStatus == DEM_DEBOUNCE_MONITORINTERNAL_STATUS_FAILED)
  {
    Dem_DebounceBaseSat_SetDebounceValueMax(lEventId, 0x7f);
  }
}                                                                                                                                /* PRQA S 6080 */ /* MD_MSR_STMIF */

/* ****************************************************************************
 % Dem_DebounceMonitorInternalSat_ResetDebounceValueMax
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL FUNC(void, DEM_CODE)
Dem_DebounceMonitorInternalSat_ResetDebounceValueMax(
  CONST(Dem_DebounceBase_ConstInfoPtrType, AUTOMATIC)  DebounceInfoPtr
  )
{
  Dem_EventIdType lEventId;
  lEventId = Dem_DebounceBase_GetEventId(DebounceInfoPtr);
  Dem_DebounceBaseSat_SetDebounceValueMax(lEventId, 0);
}

/* ****************************************************************************
 % Dem_DebounceMonitorInternal_GetFaultDetectionCounter
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
DEM_LOCAL FUNC(Std_ReturnType, DEM_CODE)
Dem_DebounceMonitorInternal_GetFaultDetectionCounter(
  CONST(Dem_DebounceBase_ConstInfoPtrType, AUTOMATIC)  DebounceInfoPtr,
  P2VAR(sint8, AUTOMATIC, DEM_APPL_DATA) FaultDetectionCounter
  )
{
  Dem_EventIdType lEventId;
  Std_ReturnType lReturnValue;

  lEventId = Dem_DebounceBase_GetEventId(DebounceInfoPtr);

  if (Dem_Cfg_EventCbkGetFDC(lEventId) != NULL_PTR)
  {
    sint8 lFdc;
    lReturnValue = (*Dem_Cfg_EventCbkGetFDC(lEventId))(&lFdc);                                                                   /* SBSW_DEM_EVENTCBKGETFDC_FPTR */
    if (lReturnValue == E_OK)
    {
      *FaultDetectionCounter = lFdc;                                                                                             /* SBSW_DEM_POINTER_WRITE_API */
    }
  }
  else
  {
    lReturnValue = DEM_E_NO_FDC_AVAILABLE;
  }

  return lReturnValue;
}

/* ****************************************************************************
 % Dem_DebounceMonitorInternal_GetMaxFaultDetectionCounter
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL FUNC(Std_ReturnType, DEM_CODE)
Dem_DebounceMonitorInternal_GetMaxFaultDetectionCounter(
  CONST(Dem_DebounceBase_ConstInfoPtrType, AUTOMATIC)  DebounceInfoPtr,
  P2VAR(sint8, AUTOMATIC, DEM_APPL_DATA) FaultDetectionCounter
  )
{
  Dem_EventIdType lEventId;
  lEventId = Dem_DebounceBase_GetEventId(DebounceInfoPtr);

  *FaultDetectionCounter = (sint8)Dem_DebounceBaseSat_GetDebounceValueMax(lEventId);
  return E_OK;
}

/* ****************************************************************************
 % Dem_DebounceMonitorInternal_GetDebouncingResult
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_SatelliteData_DataType, DEM_CODE)
Dem_DebounceMonitorInternal_GetDebouncingResult(
  CONST(Dem_DebounceBase_ConstInfoPtrType, AUTOMATIC)  DebounceInfoPtr,
  CONST(Dem_SatelliteData_DataType, AUTOMATIC)  SatelliteData
  )
{
  Dem_SatelliteData_DataType lReturnValue;                                                                                       /* PRQA S 0759 */ /* MD_MSR_18.4 */
  lReturnValue = Dem_SatelliteData_SetDebounceData(
                    SatelliteData,
                    (Dem_Debounce_DataType) Dem_DebounceMonitorInternal_GetNewMonitorStatus(DebounceInfoPtr));
  return lReturnValue;
}

/* ****************************************************************************
 % Dem_DebounceMonitorInternal_RestoreDebounceValue
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *****************************************************************************/
DEM_LOCAL FUNC(Dem_SatelliteData_DataType, DEM_CODE)
Dem_DebounceMonitorInternal_RestoreDebounceValue(
  CONST(Dem_DebounceBase_ConstInfoPtrType, AUTOMATIC) DebounceInfoPtr,
  CONST(Dem_SatelliteData_DataType, AUTOMATIC) SatelliteData,
  CONST(sint16, AUTOMATIC) Value,
  CONST(boolean, AUTOMATIC) ExpectedThreshold
  )
{
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(DebounceInfoPtr)                                                                              /* PRQA S 3112 */ /* MD_DEM_14.2 */
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(SatelliteData)                                                                                /* PRQA S 3112 */ /* MD_DEM_14.2 */
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(Value)                                                                                        /* PRQA S 3112 */ /* MD_DEM_14.2 */
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(ExpectedThreshold)                                                                            /* PRQA S 3112 */ /* MD_DEM_14.2 */

  Dem_Error_ReportError(DEM_INTERNAL_APIID, DEM_E_PARAM_CONFIG);

  return SatelliteData;
}

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* DEM_DEBOUNCEMONITORINTERNAL_IMPLEMENTATION_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_DebounceMonitorInternal_Implementation.h
 *********************************************************************************************************************/
