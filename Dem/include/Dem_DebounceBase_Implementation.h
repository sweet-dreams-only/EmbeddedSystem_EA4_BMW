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
 *  \addtogroup Dem_DebounceBase
 *  \{
 *  \file       Dem_DebounceBase_Implementation.h
 *  \brief      Diagnostic Event Manager (Dem) header file
 *  \details    Implementation of DebounceBase subcomponent
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

#if !defined (DEM_DEBOUNCEBASE_IMPLEMENTATION_H)
#define DEM_DEBOUNCEBASE_IMPLEMENTATION_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                  /* Own subcomponent header */
/* ------------------------------------------------------------------------- */
#include "Dem_DebounceBase_Interface.h"

                                                    /* Used subcomponent API */
/* ------------------------------------------------------------------------- */

                                                   /* Subcomponents callbacks*/
/* ------------------------------------------------------------------------- */

/* ********************************************************************************************************************
 *  SUBCOMPONENT CONSTANT MACROS
 *********************************************************************************************************************/
/*!
 * \defgroup  Dem_DebounceBase_InfoState  Macros encoding the state of a debouncing object.
 * \{
 */
#define DEM_DEBOUNCEBASE_INFOSTATE_DEBOUNCINGCHANGED          (0x01U) /*!< Status change indication */
#define DEM_DEBOUNCEBASE_INFOSTATE_REQUESTFDCPROCESSING       (0x02U) /*!< FDC Status change indication */
#define DEM_DEBOUNCEBASE_INFOSTATE_SIMILARCONDITIONSCHANGED   (0x04U) /*!< Similar condition change indication */
#define DEM_DEBOUNCEBASE_INFOSTATE_OLDSIMILARCONDITIONSSTATUS (0x08U) /*!< Similar condition status before processing */
#define DEM_DEBOUNCEBASE_INFOSTATE_NEWSIMILARCONDITIONSSTATUS (0x10U) /*!< Similar condition status after processing */
#define DEM_DEBOUNCEBASE_INFOSTATE_MAXIMUMFDCEXCEEDED         (0x20U) /*!< FDC maximum exceeded */
#define DEM_DEBOUNCEBASE_INFOSTATE_FDCTHRESHOLDEXCEEDED       (0x40U) /*!< FDC threshold exceeded */

#define DEM_DEBOUNCEBASE_INFOSTATE_INITIAL                    (0x00U) /*!< Initial state value */

/*! The inverse of DEM_DEBOUNCEBASE_INFOSTATE_DEBOUNCINGCHANGED */
#define DEM_DEBOUNCEBASE_INFOSTATE_DEBOUNCINGCHANGED_MASK            DEM_BIT_MASK(0, DEM_1BYTE)

/*! The inverse of DEM_DEBOUNCEBASE_INFOSTATE_REQUESTFDCPROCESSING */
#define DEM_DEBOUNCEBASE_INFOSTATE_REQUESTFDCPROCESSING_MASK         DEM_BIT_MASK(1, DEM_1BYTE)

/*! The inverse of DEM_DEBOUNCEBASE_INFOSTATE_SIMILARCONDITIONSCHANGED */
#define DEM_DEBOUNCEBASE_INFOSTATE_SIMILARCONDITIONSCHANGED_MASK     DEM_BIT_MASK(2, DEM_1BYTE)

/*! The inverse of DEM_DEBOUNCEBASE_INFOSTATE_OLDSIMILARCONDITIONSSTATUS */
#define DEM_DEBOUNCEBASE_INFOSTATE_OLDSIMILARCONDITIONSSTATUS_MASK   DEM_BIT_MASK(3, DEM_1BYTE)

/*! The inverse of DEM_DEBOUNCEBASE_INFOSTATE_NEWSIMILARCONDITIONSSTATUS */
#define DEM_DEBOUNCEBASE_INFOSTATE_NEWSIMILARCONDITIONSSTATUS_MASK   DEM_BIT_MASK(4, DEM_1BYTE)

/*! The inverse of DEM_DEBOUNCEBASE_INFOSTATE_MAXIMUMFDCEXCEEDED */
#define DEM_DEBOUNCEBASE_INFOSTATE_MAXIMUMFDCEXCEEDED_MASK           DEM_BIT_MASK(5, DEM_1BYTE)

/*! The inverse of DEM_DEBOUNCEBASE_INFOSTATE_FDCTHRESHOLDEXCEEDED */
#define DEM_DEBOUNCEBASE_INFOSTATE_FDCTHRESHOLDEXCEEDED_MASK         DEM_BIT_MASK(6, DEM_1BYTE)

/*!
 * \}
 */

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
 * \addtogroup Dem_DebounceBase_Properties
 * \{
 */

/* ****************************************************************************
 %  Dem_DebounceBase_GetEventId()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_EventIdType, DEM_CODE)
Dem_DebounceBase_GetEventId(
  CONST(Dem_DebounceBase_ConstInfoPtrType, AUTOMATIC) DebounceInfoPtr
  )
{
  return DebounceInfoPtr->EventId;
}

/* ****************************************************************************
 %  Dem_DebounceBase_GetMonitorTrigger()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_EventStatusType, DEM_CODE)
Dem_DebounceBase_GetMonitorTrigger(
  CONST(Dem_DebounceBase_ConstInfoPtrType, AUTOMATIC) DebounceInfoPtr
  )
{
  return DebounceInfoPtr->MonitorTrigger;
}

/* ****************************************************************************
 %  Dem_DebounceBase_SetMonitorTrigger()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_DebounceBase_SetMonitorTrigger(
  CONST(Dem_DebounceBase_InfoPtrType, AUTOMATIC)  DebounceInfoPtr,
  CONST(Dem_EventStatusType, AUTOMATIC)           MonitorTrigger
  )
{
  DebounceInfoPtr->MonitorTrigger = MonitorTrigger;
}

/* ****************************************************************************
 % Dem_DebounceBase_TestDebouncingChanged()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_DebounceBase_TestDebouncingChanged(
  CONST(Dem_DebounceBase_ConstInfoPtrType, AUTOMATIC) DebounceInfoPtr
  )
{
  return ((DebounceInfoPtr->State & DEM_DEBOUNCEBASE_INFOSTATE_DEBOUNCINGCHANGED) != 0);
}

/* ****************************************************************************
 % Dem_DebounceBase_SetDebouncingChanged()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_DebounceBase_SetDebouncingChanged(
  CONST(Dem_DebounceBase_InfoPtrType, AUTOMATIC) DebounceInfoPtr
  )
{
  DebounceInfoPtr->State |= DEM_DEBOUNCEBASE_INFOSTATE_DEBOUNCINGCHANGED;
}

/* ****************************************************************************
 % Dem_DebounceBase_TestRequestFdcProcessing()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_DebounceBase_TestRequestFdcProcessing(
  CONST(Dem_DebounceBase_ConstInfoPtrType, AUTOMATIC) DebounceInfoPtr
  )
{
  return ((DebounceInfoPtr->State & DEM_DEBOUNCEBASE_INFOSTATE_REQUESTFDCPROCESSING) != 0);
}

/* ****************************************************************************
 % Dem_DebounceBase_SetRequestFdcProcessing()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_DebounceBase_SetRequestFdcProcessing(
  CONST(Dem_DebounceBase_InfoPtrType, AUTOMATIC) DebounceInfoPtr
  )
{
  DebounceInfoPtr->State |= DEM_DEBOUNCEBASE_INFOSTATE_REQUESTFDCPROCESSING;
}

/* ****************************************************************************
 % Dem_DebounceBase_TestSimilarConditionsChanged()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_DebounceBase_TestSimilarConditionsChanged(
  CONST(Dem_DebounceBase_ConstInfoPtrType, AUTOMATIC) DebounceInfoPtr
  )
{
  boolean lReturnValue;

  DEM_IGNORE_UNUSED_CONST_ARGUMENT(DebounceInfoPtr)                                                                              /* PRQA S 3112 */ /* MD_DEM_14.2 */

#if (DEM_CFG_SUPPORT_SIMILAR_CONDITIONS == STD_ON)
  lReturnValue = ((DebounceInfoPtr->State & DEM_DEBOUNCEBASE_INFOSTATE_SIMILARCONDITIONSCHANGED) != 0);
#else
  lReturnValue = FALSE;
#endif
  return lReturnValue;
}

/* ****************************************************************************
 % Dem_DebounceBase_SetSimilarConditionsChanged()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_DebounceBase_SetSimilarConditionsChanged(                                                                                    /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONST(Dem_DebounceBase_InfoPtrType, AUTOMATIC) DebounceInfoPtr
  )
{
  DebounceInfoPtr->State |= DEM_DEBOUNCEBASE_INFOSTATE_SIMILARCONDITIONSCHANGED;
}

/* ****************************************************************************
 % Dem_DebounceBase_ResetSimilarConditionsChanged()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_DebounceBase_ResetSimilarConditionsChanged(                                                                                  /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONST(Dem_DebounceBase_InfoPtrType, AUTOMATIC) DebounceInfoPtr
  )
{
  DebounceInfoPtr->State &= DEM_DEBOUNCEBASE_INFOSTATE_SIMILARCONDITIONSCHANGED;
}

/* ****************************************************************************
 % Dem_DebounceBase_TestOldSimilarConditionsStatus()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_DebounceBase_TestOldSimilarConditionsStatus(                                                                                 /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONST(Dem_DebounceBase_ConstInfoPtrType, AUTOMATIC) DebounceInfoPtr
  )
{
  return ((DebounceInfoPtr->State & DEM_DEBOUNCEBASE_INFOSTATE_OLDSIMILARCONDITIONSSTATUS) != 0);
}

/* ****************************************************************************
 % Dem_DebounceBase_SetOldSimilarConditionsStatus()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_DebounceBase_SetOldSimilarConditionsStatus(                                                                                  /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONST(Dem_DebounceBase_InfoPtrType, AUTOMATIC) DebounceInfoPtr
  )
{
  DebounceInfoPtr->State |= DEM_DEBOUNCEBASE_INFOSTATE_OLDSIMILARCONDITIONSSTATUS;
}

/* ****************************************************************************
 % Dem_DebounceBase_ResetOldSimilarConditionsStatus()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_DebounceBase_ResetOldSimilarConditionsStatus(                                                                                /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONST(Dem_DebounceBase_InfoPtrType, AUTOMATIC) DebounceInfoPtr
  )
{
  DebounceInfoPtr->State = (uint8)(DebounceInfoPtr->State & DEM_DEBOUNCEBASE_INFOSTATE_OLDSIMILARCONDITIONSSTATUS_MASK);
}

/* ****************************************************************************
 % Dem_DebounceBase_TestNewSimilarConditionsStatus()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_DebounceBase_TestNewSimilarConditionsStatus(                                                                                 /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONST(Dem_DebounceBase_ConstInfoPtrType, AUTOMATIC) DebounceInfoPtr
  )
{
  return ((DebounceInfoPtr->State & DEM_DEBOUNCEBASE_INFOSTATE_NEWSIMILARCONDITIONSSTATUS) != 0);
}

/* ****************************************************************************
 % Dem_DebounceBase_SetNewSimilarConditionsStatus()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_DebounceBase_SetNewSimilarConditionsStatus(                                                                                  /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONST(Dem_DebounceBase_InfoPtrType, AUTOMATIC) DebounceInfoPtr
  )
{
  DebounceInfoPtr->State |= DEM_DEBOUNCEBASE_INFOSTATE_NEWSIMILARCONDITIONSSTATUS;
}

/* ****************************************************************************
 % Dem_DebounceBase_ResetNewSimilarConditionsStatus()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_DebounceBase_ResetNewSimilarConditionsStatus(                                                                                /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONST(Dem_DebounceBase_InfoPtrType, AUTOMATIC) DebounceInfoPtr
  )
{
  DebounceInfoPtr->State = (uint8)(DebounceInfoPtr->State & DEM_DEBOUNCEBASE_INFOSTATE_NEWSIMILARCONDITIONSSTATUS_MASK);
}

/* ****************************************************************************
 % Dem_DebounceBase_TestMaximumFdcExceeded()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_DebounceBase_TestMaximumFdcExceeded(
  CONST(Dem_DebounceBase_ConstInfoPtrType, AUTOMATIC) DebounceInfoPtr
  )
{
  return ((DebounceInfoPtr->State & DEM_DEBOUNCEBASE_INFOSTATE_MAXIMUMFDCEXCEEDED) != 0);
}

/* ****************************************************************************
 % Dem_DebounceBase_SetMaximumFdcExceeded()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_DebounceBase_SetMaximumFdcExceeded(
  CONST(Dem_DebounceBase_InfoPtrType, AUTOMATIC) DebounceInfoPtr
  )
{
  DebounceInfoPtr->State |= DEM_DEBOUNCEBASE_INFOSTATE_MAXIMUMFDCEXCEEDED;
}

/* ****************************************************************************
 % Dem_DebounceBase_TestFdcThresholdExceeded()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_DebounceBase_TestFdcThresholdExceeded(
  CONST(Dem_DebounceBase_ConstInfoPtrType, AUTOMATIC) DebounceInfoPtr
  )
{
  return ((DebounceInfoPtr->State & DEM_DEBOUNCEBASE_INFOSTATE_FDCTHRESHOLDEXCEEDED) != 0);
}

/* ****************************************************************************
 % Dem_DebounceBase_SetFdcThresholdExceeded()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_DebounceBase_SetFdcThresholdExceeded(
  CONST(Dem_DebounceBase_InfoPtrType, AUTOMATIC) DebounceInfoPtr
  )
{
  DebounceInfoPtr->State |= DEM_DEBOUNCEBASE_INFOSTATE_FDCTHRESHOLDEXCEEDED;
}

/* ****************************************************************************
 %  Dem_DebounceBase_GetFaultDetectionCounter
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL FUNC(Std_ReturnType, DEM_CODE)
Dem_DebounceBase_GetFaultDetectionCounter(
  CONST(Dem_DebounceBase_ConstInfoPtrType, AUTOMATIC) DebounceInfoPtr,
  CONSTP2VAR(sint8, AUTOMATIC, DEM_APPL_DATA) FaultDetectionCounter
  )
{
  return DebounceInfoPtr->FunctionTable->GetFaultDetectionCounter(DebounceInfoPtr, FaultDetectionCounter);
}

/* ****************************************************************************
 %  Dem_DebounceBase_GetMaxFaultDetectionCounter
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL FUNC(Std_ReturnType, DEM_CODE)
Dem_DebounceBase_GetMaxFaultDetectionCounter(
  CONST(Dem_DebounceBase_ConstInfoPtrType, AUTOMATIC) DebounceInfoPtr,
  CONSTP2VAR(sint8, AUTOMATIC, DEM_APPL_DATA) FaultDetectionCounterMax
  )
{
  return DebounceInfoPtr->FunctionTable->GetMaxFaultDetectionCounter(DebounceInfoPtr, FaultDetectionCounterMax);
}

/* ****************************************************************************
 % Dem_DebounceBase_GetDebouncingState
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL FUNC(Dem_DebouncingStateType, DEM_CODE)
Dem_DebounceBase_GetDebouncingState(
  CONST(Dem_DebounceBase_ConstInfoPtrType, AUTOMATIC)  DebounceInfoPtr
  )
{
  return DebounceInfoPtr->FunctionTable->GetDebouncingState(DebounceInfoPtr);
}

/* ****************************************************************************
 % Dem_DebounceBase_CalculateDebouncing
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL FUNC(boolean, DEM_CODE)
Dem_DebounceBase_CalculateDebouncing(
  CONST(Dem_DebounceBase_InfoPtrType, AUTOMATIC)  DebounceInfoPtr
  )
{
  return DebounceInfoPtr->FunctionTable->Calculate(DebounceInfoPtr);
}

/* ****************************************************************************
 % Dem_DebounceBase_Reset
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL FUNC(void, DEM_CODE)
Dem_DebounceBase_Reset(
  CONST(Dem_DebounceBase_InfoPtrType, AUTOMATIC)  DebounceInfoPtr
  )
{
  DebounceInfoPtr->FunctionTable->Reset(DebounceInfoPtr);
}

/* ****************************************************************************
 % Dem_DebounceBase_Freeze
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL FUNC(void, DEM_CODE)
Dem_DebounceBase_Freeze(
  CONST(Dem_DebounceBase_InfoPtrType, AUTOMATIC)  DebounceInfoPtr
  )
{
  DebounceInfoPtr->FunctionTable->Freeze(DebounceInfoPtr);
}

/* ****************************************************************************
 % Dem_DebounceBaseSat_UpdateDebounceValueMax
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL FUNC(void, DEM_CODE)
Dem_DebounceBaseSat_UpdateDebounceValueMax(
  CONST(Dem_DebounceBase_ConstInfoPtrType, AUTOMATIC)  DebounceInfoPtr                                                           /* PRQA S 3206 */ /* MD_DEM_3206 */
  )
{
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(DebounceInfoPtr)                                                                              /* PRQA S 3112 */ /* MD_DEM_14.2 */
#if (DEM_FEATURE_NEED_MAX_DEBOUNCE_VALUE == STD_ON)
  DebounceInfoPtr->FunctionTable->UpdateDebounceValueMax(DebounceInfoPtr);
#endif
}

/* ****************************************************************************
 % Dem_DebounceBaseSat_ResetDebounceValueMax
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL FUNC(void, DEM_CODE)
Dem_DebounceBaseSat_ResetDebounceValueMax(
  CONST(Dem_DebounceBase_ConstInfoPtrType, AUTOMATIC)  DebounceInfoPtr
  )
{
  DebounceInfoPtr->FunctionTable->ResetDebounceValueMax(DebounceInfoPtr);
}

/* ****************************************************************************
 % Dem_DebounceBaseCore_ResetDebounceValueMax
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL FUNC(void, DEM_CODE)
Dem_DebounceBaseCore_ResetDebounceValueMax(
  CONST(Dem_DebounceBase_ConstInfoPtrType, AUTOMATIC)  DebounceInfoPtr
  )
{
  Dem_DebounceBaseSat_ResetDebounceValueMax(DebounceInfoPtr);
}

/* ****************************************************************************
 % Dem_DebounceBase_GetDebouncingResult
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_SatelliteData_DataType, DEM_CODE)
Dem_DebounceBase_GetDebouncingResult(
  CONST(Dem_DebounceBase_ConstInfoPtrType, AUTOMATIC)  DebounceInfoPtr,
  CONST(Dem_SatelliteData_DataType, AUTOMATIC)  SatelliteData
  )
{
  return DebounceInfoPtr->FunctionTable->GetDebouncingResult(DebounceInfoPtr, SatelliteData);
}

#if (DEM_CFG_SUPPORT_DEBOUNCE_NV == STD_ON)
/* ****************************************************************************
 % Dem_DebounceBase_RestoreDebounceValue
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL FUNC(Dem_SatelliteData_DataType, DEM_CODE)
Dem_DebounceBase_RestoreDebounceValue(
  CONST(Dem_DebounceBase_ConstInfoPtrType, AUTOMATIC) DebounceInfoPtr,
  CONST(Dem_SatelliteData_DataType, AUTOMATIC) SatelliteData,
  CONST(sint16, AUTOMATIC) Value,
  CONST(boolean, AUTOMATIC) ExpectedThreshold
  )
{
  return DebounceInfoPtr->FunctionTable->RestoreDebounceValue(DebounceInfoPtr, SatelliteData, Value, ExpectedThreshold);
}
#endif

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* ********************************************************************************************************************
 *  SUBCOMPONENT FUNCTION DEFINITIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \addtogroup Dem_DebounceBase_Public
 * \{
 */

/* ****************************************************************************
 % Dem_DebounceBase_InfoInitDefault()
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
Dem_DebounceBase_InfoInitDefault(
  CONSTP2VAR(Dem_DebounceBase_InfoType, AUTOMATIC, AUTOMATIC)  DebounceInfoPtr,
  CONST(Dem_DebounceFunctionTablePtrType, AUTOMATIC)  FunctionTable,
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  )
{
  DebounceInfoPtr->FunctionTable = FunctionTable;
  DebounceInfoPtr->EventId = EventId;
  DebounceInfoPtr->MonitorTrigger = DEM_EVENT_STATUS_INVALID;
  DebounceInfoPtr->State = DEM_DEBOUNCEBASE_INFOSTATE_INITIAL;

  return DebounceInfoPtr;
}

/* ****************************************************************************
 % Dem_DebounceBaseSat_GetDebounceValueMax
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(sint16, DEM_CODE)
Dem_DebounceBaseSat_GetDebounceValueMax(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  )
{
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(EventId)                                                                                      /* PRQA S 3112 */ /* MD_DEM_14.2 */
#if (DEM_FEATURE_NEED_MAX_DEBOUNCE_VALUE == STD_ON)
  return (sint16)(Dem_Cfg_GetMaxDebounceValuesOfSatelliteInfo(Dem_Cfg_EventSatelliteId(EventId)))[Dem_Cfg_EventSatelliteEventId(EventId)];
#else
  return 0;
#endif
}

/* ****************************************************************************
 % Dem_DebounceBaseSat_SetDebounceValueMax
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_DebounceBaseSat_SetDebounceValueMax(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,                                                                                    /* PRQA S 3206 */ /* MD_DEM_3206 */
  CONST(sint16, AUTOMATIC)  DebounceValue                                                                                        /* PRQA S 3206 */ /* MD_DEM_3206 */
  )
{
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(EventId)                                                                                      /* PRQA S 3112 */ /* MD_DEM_14.2 */
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(DebounceValue)                                                                                /* PRQA S 3112 */ /* MD_DEM_14.2 */
#if (DEM_FEATURE_NEED_MAX_DEBOUNCE_VALUE == STD_ON)
  (Dem_Cfg_GetMaxDebounceValuesOfSatelliteInfo(Dem_Cfg_EventSatelliteId(EventId)))[Dem_Cfg_EventSatelliteEventId(EventId)] = (uint16)DebounceValue;
#endif
}

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* DEM_DEBOUNCEBASE_IMPLEMENTATION_H */

/*!
 * \}
 */
/**********************************************************************************************************************
 *  END OF FILE: Dem_DebounceBase_Implementation.h
 *********************************************************************************************************************/
