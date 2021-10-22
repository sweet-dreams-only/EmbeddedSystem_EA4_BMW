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
/*! \addtogroup Dem_FreezeFrameIterator
 *  \{
 *  \file       Dem_FreezeFrameIterator_Implementation.h
 *  \brief      Diagnostic Event Manager (Dem) Implementation file
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

#if !defined (DEM_FREEZEFRAMEITERATOR_IMPLEMENTATION_H)
#define DEM_FREEZEFRAMEITERATOR_IMPLEMENTATION_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                  /* Own subcomponent header */
/* ------------------------------------------------------------------------- */
#include "Dem_FreezeFrameIterator_Interface.h"

                                                    /* Used subcomponent API */
#include "Dem_MemoryEntry_Implementation.h"
#include "Dem_SnapshotEntry_Implementation.h"
#include "Dem_DTCReporting_Implementation.h"
#include "Dem_Event_Implementation.h"
#include "Dem_DTC_Implementation.h"
#include "Dem_MemStorageManager_Implementation.h"

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
 *  SUBCOMPONENT PRIVATE FUNCTION DEFINITIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \addtogroup Dem_FreezeFrameIterator_Private
 * \{
 */

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_FreezeFrameIterator_SetDTCFormat
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_FreezeFrameIterator_SetDTCFormat(
  CONST(Dem_FreezeFrameIterator_HandleType, AUTOMATIC)  FreezeFrameIteratorId,
  CONST(Dem_FreezeFrameIterator_DTCFormatType, AUTOMATIC)  NewDTCFormat
  )
{
# if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (FreezeFrameIteratorId >= Dem_Cfg_GetSizeOfFreezeFrameIteratorTable())
  {
    Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
  }
  else
# endif
  {
    Dem_Cfg_GetFreezeFrameIteratorTable(FreezeFrameIteratorId).FilterDTCFormat = NewDTCFormat;
  }
}
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_FreezeFrameIterator_GetDTCFormat
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_FreezeFrameIterator_DTCFormatType, DEM_CODE)
Dem_FreezeFrameIterator_GetDTCFormat(
  CONST(Dem_FreezeFrameIterator_HandleType, AUTOMATIC)  FreezeFrameIteratorId
  )
{
  return Dem_Cfg_GetFreezeFrameIteratorTable(FreezeFrameIteratorId).FilterDTCFormat;
}
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_FreezeFrameIterator_SetMemoryIndex
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_FreezeFrameIterator_SetMemoryIndex(                                                                                          /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONST(Dem_FreezeFrameIterator_HandleType, AUTOMATIC)  FreezeFrameIteratorId,
  CONST(uint8, AUTOMATIC)  NewMemoryIndex
  )
{
# if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (FreezeFrameIteratorId >= Dem_Cfg_GetSizeOfFreezeFrameIteratorTable())
  {
    Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
  }
  else
# endif
  {
    Dem_Cfg_GetFreezeFrameIteratorTable(FreezeFrameIteratorId).MemoryIndex = NewMemoryIndex;
  }
}
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_FreezeFrameIterator_GetMemoryIndex
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_FreezeFrameIterator_GetMemoryIndex(                                                                                          /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONST(Dem_FreezeFrameIterator_HandleType, AUTOMATIC)  FreezeFrameIteratorId
  )
{
  return Dem_Cfg_GetFreezeFrameIteratorTable(FreezeFrameIteratorId).MemoryIndex;
}
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_FreezeFrameIterator_SetSnapshotEntryIterator
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_FreezeFrameIterator_SetSnapshotEntryIterator(                                                                                /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONST(Dem_FreezeFrameIterator_HandleType, AUTOMATIC)  FreezeFrameIteratorId,
  CONST(Dem_SnapshotEntry_IterType, AUTOMATIC)  SnapshotEntryIter
)
{
# if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (FreezeFrameIteratorId >= Dem_Cfg_GetSizeOfFreezeFrameIteratorTable())
  {
    Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
  }
  else
# endif
  {
    Dem_Cfg_GetFreezeFrameIteratorTable(FreezeFrameIteratorId).SnapshotEntryIter = SnapshotEntryIter;
  }
}
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_FreezeFrameIterator_GetSnapshotEntryIterator
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_SnapshotEntry_IterType, DEM_CODE)
Dem_FreezeFrameIterator_GetSnapshotEntryIterator(                                                                                /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONST(Dem_FreezeFrameIterator_HandleType, AUTOMATIC)  FreezeFrameIteratorId
  )
{
  return Dem_Cfg_GetFreezeFrameIteratorTable(FreezeFrameIteratorId).SnapshotEntryIter;
}
#endif

# if (DEM_FEATURE_NEED_TIME_SERIES == STD_ON) && (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_FreezeFrameIterator_SetTimeSeriesRecordNumber
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_FreezeFrameIterator_SetTimeSeriesRecordNumber(
  CONST(Dem_FreezeFrameIterator_HandleType, AUTOMATIC)  FreezeFrameIteratorId,
  CONST(uint8, AUTOMATIC)  NewTimeSeriesRecordNumber
  )
{
#  if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (FreezeFrameIteratorId >= Dem_Cfg_GetSizeOfFreezeFrameIteratorTable())
  {
    Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
  }
  else
#  endif
  {
    Dem_Cfg_GetFreezeFrameIteratorTable(FreezeFrameIteratorId).TimeSeriesRecordNumber = NewTimeSeriesRecordNumber;
  }
}
# endif

# if (DEM_FEATURE_NEED_TIME_SERIES == STD_ON) && (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_FreezeFrameIterator_GetTimeSeriesRecordNumber
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_FreezeFrameIterator_GetTimeSeriesRecordNumber(
  CONST(Dem_FreezeFrameIterator_HandleType, AUTOMATIC)  FreezeFrameIteratorId
  )
{
  return Dem_Cfg_GetFreezeFrameIteratorTable(FreezeFrameIteratorId).TimeSeriesRecordNumber;
}
# endif

# if (DEM_CFG_SUPPORT_SRECS == STD_ON) && (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_FreezeFrameIterator_InitIterator
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_FreezeFrameIterator_InitIterator(
  CONST(Dem_FreezeFrameIterator_HandleType, AUTOMATIC)  FreezeFrameIteratorId,
  CONST(uint16_least, AUTOMATIC)  NewStartIndex,
  CONST(uint16_least, AUTOMATIC)  NewEndIndex
  )
{
# if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (FreezeFrameIteratorId >= Dem_Cfg_GetSizeOfFreezeFrameIteratorTable())
  {
    Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
  }
  else
  if (NewEndIndex < NewStartIndex)
  {
    Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
  }
  else
# endif
  {
    Dem_Cfg_GetFreezeFrameIteratorTable(FreezeFrameIteratorId).Iterator.mIdx = NewStartIndex;
    Dem_Cfg_GetFreezeFrameIteratorTable(FreezeFrameIteratorId).Iterator.mEndIdx = NewEndIndex;
  }
}
#endif

# if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_FreezeFrameIterator_GetIteratorPtr
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_FreezeFrameIterator_IterPtrType, DEM_CODE)
Dem_FreezeFrameIterator_GetIteratorPtr(                                                                                          /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONST(Dem_FreezeFrameIterator_HandleType, AUTOMATIC)  FreezeFrameIteratorId
  )
{
  Dem_FreezeFrameIterator_HandleType lFreezeFrameIteratorId;
  lFreezeFrameIteratorId = FreezeFrameIteratorId;
# if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (FreezeFrameIteratorId >= Dem_Cfg_GetSizeOfFreezeFrameIteratorTable())
  {
    Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
    lFreezeFrameIteratorId = 0;
  }
# endif
  return &Dem_Cfg_GetFreezeFrameIteratorTable(lFreezeFrameIteratorId).Iterator;
}
#endif

# if (DEM_CFG_SUPPORT_SRECS == STD_ON) && (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_FreezeFrameIterator_FilterSRec
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
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_FreezeFrameIterator_FilterSRec(
  CONST(Dem_FreezeFrameIterator_HandleType, AUTOMATIC)  FreezeFrameIteratorId,
  CONSTP2VAR(uint32, AUTOMATIC, DEM_DCM_DATA)  DTC,                                                                              /* PRQA S 3673 */ /* MD_DEM_16.7 */
  CONSTP2VAR(uint8, AUTOMATIC, DEM_DCM_DATA)  RecordNumber
  )
{
  Dem_Mem_MemoryInfoPtrType lMemoryInfo;
  Dem_Cfg_MemoryIndexType lMemoryIndex;
  Dem_Cfg_MemoryIndexType lMemoryIndexEnd;
  Dem_SnapshotEntry_IterType lSnapshotEntryIter;

  lMemoryInfo = Dem_MemStorageManager_MemoryInfoInit(DEM_CFG_MEMORYID_PRIMARY);
  lMemoryIndex = Dem_FreezeFrameIterator_GetMemoryIndex(FreezeFrameIteratorId);
  lMemoryIndexEnd = Dem_MemStorageManager_MemoryIter_End(lMemoryInfo);                                                                         /* SBSW_DEM_CALL_MEMORYINFO_POINTER */
  lSnapshotEntryIter = Dem_FreezeFrameIterator_GetSnapshotEntryIterator(FreezeFrameIteratorId);

  while (lMemoryIndex < lMemoryIndexEnd)
  {
    Dem_MemoryEntry_HandleType lMemoryEntryId;
    Dem_EventIdType lEventId;
#  if (DEM_CFG_SUPPORT_OBDII == STD_ON) || (DEM_CFG_SUPPORT_J1939 == STD_ON)                                                      /* COV_MSR_UNSUPPORTED XF */
    Dem_FreezeFrameIterator_DTCFormatType lFilterType;
#  endif

    lMemoryEntryId = Dem_MemStorageManager_GetMemoryEntryId(lMemoryIndex);
    lEventId = Dem_MemoryEntry_GetEventId(lMemoryEntryId);
#  if (DEM_CFG_SUPPORT_OBDII == STD_ON) || (DEM_CFG_SUPPORT_J1939 == STD_ON)                                                      /* COV_MSR_UNSUPPORTED XF */
    lFilterType = Dem_FreezeFrameIterator_GetDTCFormat(FreezeFrameIteratorId);
#  endif

    if ( (Dem_Event_TestValidHandle(lEventId) == TRUE)                                                                             /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
      && (Dem_DTC_TestDtcSuppressed(lEventId) == FALSE) )
    {
#  if (DEM_CFG_SUPPORT_OBDII == STD_ON)                                                                                          /* COV_MSR_UNSUPPORTED XF */
      /* Skip Events which do not have an OBD DTC but filter is set for OBD format */
      if ( (Dem_Cfg_EventObdRelated(lEventId) == TRUE)
        || (lFilterType != DEM_FREEZEFRAMEITERATOR_DTCFORMAT_OBD))
#  endif
      {
        /* Special case - skip Dependent OBD DTCs */
        if ( (Dem_DTCReporting_TestObdHideOccurrences() == FALSE)                                                                /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
          || (Dem_Cfg_EventSignificance(lEventId) != DEM_CFG_EVENT_SIGNIFICANCE_OCCURRENCE)
          || (Dem_Cfg_EventObdRelated(lEventId) == FALSE))
        {
          if (Dem_SnapshotEntry_IteratorGetMemoryEntryHandle(&lSnapshotEntryIter) == DEM_MEMORYENTRY_HANDLE_INVALID)
          {
            Dem_SnapshotEntry_IteratorInit(lEventId, lMemoryEntryId, &lSnapshotEntryIter);
          }
          if (Dem_SnapshotEntry_IteratorSetNextStoredEntry(&lSnapshotEntryIter) == TRUE)
          {
#  if (DEM_CFG_SUPPORT_OBDII == STD_ON)                                                                                          /* COV_MSR_UNSUPPORTED XF */
            if (lFilterType == DEM_FREEZEFRAMEITERATOR_DTCFORMAT_OBD)
            {                                                                                                                    /* PRQA S 0715 */  /* MD_MSR_1.1_715 */
              *DTC = (uint32)(((uint32)Dem_Cfg_EventObdDtc(lEventId)) << 8);                                                     /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
            }
            else
#  endif
#  if (DEM_CFG_SUPPORT_J1939 == STD_ON)
            if (lFilterType == DEM_FREEZEFRAMEITERATOR_DTCFORMAT_J1939)
            {                                                                                                                    /* PRQA S 0715 */  /* MD_MSR_1.1_715 */
              *DTC = Dem_Cfg_EventJ1939Dtc(lEventId);                                                                            /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
            }
            else
#  endif
            { /* Only EventIds with a valid DTC number are processed here */                                                     /* PRQA S 0715 */  /* MD_MSR_1.1_715 */
              /* -> DTC mapping will always return a valid DTC number */
              *DTC = Dem_Cfg_EventUdsDtc(lEventId);                                                                              /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
            }
#  if (DEM_CFG_SUPPORT_SRECS_CALCULATED == STD_ON)
            *RecordNumber = Dem_SnapshotEntry_IteratorGetSnapshotEntryIndex(&lSnapshotEntryIter) + 1;                            /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
#  else /* (DEM_CFG_SUPPORT_SRECS_CONFIGURED == STD_ON) */
            *RecordNumber = Dem_Cfg_SRecId(Dem_SnapshotEntry_IteratorGetSnapshotRecordIndex(&lSnapshotEntryIter));               /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
#  endif
            /* Increment in global state, the next iteration will continue with the next record */
            Dem_FreezeFrameIterator_SetMemoryIndex(FreezeFrameIteratorId, lMemoryIndex);
            Dem_SnapshotEntry_IteratorNext(&lSnapshotEntryIter);
            Dem_FreezeFrameIterator_SetSnapshotEntryIterator(FreezeFrameIteratorId, lSnapshotEntryIter);

            return TRUE;
          }
        }
      }
    }
    ++lMemoryIndex;
    Dem_SnapshotEntry_IteratorInit(lEventId, DEM_MEMORYENTRY_HANDLE_INVALID, &lSnapshotEntryIter);
  }

  Dem_FreezeFrameIterator_SetMemoryIndex(FreezeFrameIteratorId, lMemoryIndex);
  Dem_FreezeFrameIterator_SetSnapshotEntryIterator(FreezeFrameIteratorId, lSnapshotEntryIter);

  return FALSE;
}                                                                                                                                /* PRQA S 2006, 6030, 6050, 6080 */ /* MD_DEM_14.7, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
# endif

# if (DEM_CFG_SUPPORT_SRECS == STD_ON) && (DEM_FEATURE_NEED_TIME_SERIES == STD_ON) && (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_FreezeFrameIterator_FilterTimeSeriesSRec
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
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_FreezeFrameIterator_FilterTimeSeriesSRec(
  CONST(Dem_FreezeFrameIterator_HandleType, AUTOMATIC)  FreezeFrameIteratorId,
  CONSTP2VAR(uint32, AUTOMATIC, DEM_DCM_DATA)  DTC,                                                                              /* PRQA S 3673 */ /* MD_DEM_16.7 */
  CONSTP2VAR(uint8, AUTOMATIC, DEM_DCM_DATA)  RecordNumber
  )
{
  Dem_Mem_MemoryInfoPtrType lMemoryInfo;
  Dem_Cfg_MemoryIndexType lMemoryIndex;
  Dem_Cfg_MemoryIndexType lMemoryIndexEnd;
  uint8 lTimeSeriesRecordNumber;

  lMemoryInfo = Dem_MemStorageManager_MemoryInfoInit(DEM_CFG_MEMORYID_TIMESERIES);
  lMemoryIndex = Dem_FreezeFrameIterator_GetMemoryIndex(FreezeFrameIteratorId);
  lMemoryIndexEnd = Dem_MemStorageManager_MemoryIter_End(lMemoryInfo);                                                                         /* SBSW_DEM_CALL_MEMORYINFO_POINTER */
  lTimeSeriesRecordNumber = Dem_FreezeFrameIterator_GetTimeSeriesRecordNumber(FreezeFrameIteratorId);

  while (lMemoryIndex < lMemoryIndexEnd)
  {
    Dem_EventIdType lEventId;
    Dem_Mem_TimeSeriesEntryPtrType lTimeSeriesEntry;
#  if (DEM_FEATURE_NEED_OBD == STD_ON)
    Dem_FreezeFrameIterator_DTCFormatType lFilterType;
#  endif

    lTimeSeriesEntry = Dem_Mem_TimeSeriesGetEntry(lMemoryIndex);
    lEventId = Dem_Mem_EntryGetEventId(lTimeSeriesEntry);
#  if (DEM_FEATURE_NEED_OBD == STD_ON)
    lFilterType = Dem_FreezeFrameIterator_GetDTCFormat(FreezeFrameIteratorId);
#  endif

    if ( (Dem_Event_TestValidHandle(lEventId) == TRUE)                                                                             /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
      && (Dem_DTC_TestDtcSuppressed(lEventId) == FALSE) )
    {
#  if (DEM_CFG_SUPPORT_OBDII == STD_ON)
      /* suppress record for OBD related events if the confirmed bit is not qualified yet.
      UDS only events are not taken into account or OBD related events which have a qualified DCY */

      /* Skip Events which do not have an OBD DTC but filter is set for OBD format */
      if ( (Dem_Cfg_EventObdRelated(lEventId) == TRUE)
        || (lFilterType != DEM_FREEZEFRAMEITERATOR_DTCFORMAT_OBD) )
#  endif
      {
        /* Special case - skip Dependent OBD DTCs */
        if ( (Dem_DTCReporting_TestObdHideOccurrences() == FALSE)                                                                /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
          || (Dem_Cfg_EventSignificance(lEventId) != DEM_CFG_EVENT_SIGNIFICANCE_OCCURRENCE)
          || (Dem_Cfg_EventObdRelated(lEventId) == FALSE) )
        {
          if (lTimeSeriesRecordNumber < 0x10)
          {
            lTimeSeriesRecordNumber = Dem_Data_TimeSeriesGetNextValidSRec(lTimeSeriesEntry, lTimeSeriesRecordNumber);            /* SBSW_DEM_POINTER_WRITE_TIMESERIESENTRY */
          }

          if (lTimeSeriesRecordNumber <= 0x4f)
          {
            if (Dem_Data_TimeSeriesSRecIsValid(lEventId, lTimeSeriesRecordNumber) == TRUE)
            {
              if (Dem_Data_TimeSeriesSRecIsStored(lTimeSeriesEntry, lTimeSeriesRecordNumber) == FALSE)                           /* SBSW_DEM_POINTER_WRITE_TIMESERIESENTRY */
              {
                /* Continue immediately with the next possible record in this iteration, the Dcm always expects a record */
                lTimeSeriesRecordNumber = Dem_Data_TimeSeriesGetNextValidSRec(lTimeSeriesEntry, lTimeSeriesRecordNumber);        /* SBSW_DEM_POINTER_WRITE_TIMESERIESENTRY */
                continue;                                                                                                        /* PRQA S 0770 */ /* MD_DEM_14.5 */
              }
            }
            else
            {
              /* Continue immediately with the next possible record in this iteration, the Dcm always expects a record */
              lTimeSeriesRecordNumber = Dem_Data_TimeSeriesGetNextValidSRec(lTimeSeriesEntry, lTimeSeriesRecordNumber);          /* SBSW_DEM_POINTER_WRITE_TIMESERIESENTRY */
              continue;                                                                                                          /* PRQA S 0770 */ /* MD_DEM_14.5 */
            }

            /* Increment in global state, the next iteration will continue with the next record */
            Dem_FreezeFrameIterator_SetMemoryIndex(FreezeFrameIteratorId, lMemoryIndex);
            Dem_FreezeFrameIterator_SetTimeSeriesRecordNumber(FreezeFrameIteratorId,
                Dem_Data_TimeSeriesGetNextValidSRec(lTimeSeriesEntry, lTimeSeriesRecordNumber));                                 /* SBSW_DEM_POINTER_WRITE_TIMESERIESENTRY */

#  if (DEM_CFG_SUPPORT_OBDII == STD_ON)
            if (lFilterType == DEM_FREEZEFRAMEITERATOR_DTCFORMAT_OBD)
            {
              *DTC = (uint32)(((uint32)Dem_Cfg_EventObdDtc(lEventId)) << 8);                                                     /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
            }
            else
#  endif
            { /* Only EventIds with a valid DTC number are processed here */                                                     /* PRQA S 0715 */  /* MD_MSR_1.1_715 */
              /* -> DTC mapping will always return a valid DTC number */
              *DTC = Dem_Cfg_EventUdsDtc(lEventId);                                                                              /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
            }
            *RecordNumber = lTimeSeriesRecordNumber;                                                                             /* SBSW_DEM_POINTER_WRITE_ARGUMENT */

            return TRUE;
          }
        }
      }
    }
    ++lMemoryIndex;
    lTimeSeriesRecordNumber = 0x00;
  }
  Dem_FreezeFrameIterator_SetMemoryIndex(FreezeFrameIteratorId, lMemoryIndex);
  Dem_FreezeFrameIterator_SetTimeSeriesRecordNumber(FreezeFrameIteratorId, lTimeSeriesRecordNumber);

  return FALSE;
}                                                                                                                                /* PRQA S 2006, 6050, 6080 */ /* MD_DEM_14.7, MD_MSR_STCAL, MD_MSR_STMIF */
# endif

# if (DEM_CFG_SUPPORT_SRECS == STD_ON) && (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_FreezeFrameIterator_GetNumberOfSRec
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
DEM_LOCAL_INLINE FUNC(uint16, DEM_CODE)
Dem_FreezeFrameIterator_GetNumberOfSRec(
  void
  )
{
  Dem_Mem_MemoryInfoPtrType lMemoryInfo;
  Dem_Cfg_MemoryIndexType lMemoryIndex;
  Dem_Cfg_MemoryIndexType lMemoryIndexEnd;
  uint16 lRecordCount;

  /* Count stored snapshot records in primary memory to prevent concurrent modification
  of the chrono index to have an effect on the iteration */
  lMemoryInfo = Dem_MemStorageManager_MemoryInfoInit(DEM_CFG_MEMORYID_PRIMARY);
  lMemoryIndex = Dem_MemStorageManager_MemoryIter_Begin(lMemoryInfo);                                                                          /* SBSW_DEM_CALL_MEMORYINFO_POINTER */
  lMemoryIndexEnd = Dem_MemStorageManager_MemoryIter_End(lMemoryInfo);                                                                         /* SBSW_DEM_CALL_MEMORYINFO_POINTER */
  lRecordCount = 0;

  while (lMemoryIndex < lMemoryIndexEnd)
  {
    Dem_MemoryEntry_HandleType lMemoryEntryId;
    Dem_EventIdType lEventId;

    lMemoryEntryId = Dem_MemStorageManager_GetMemoryEntryId(lMemoryIndex);
    lEventId = Dem_MemoryEntry_GetEventId(lMemoryEntryId);
    if ( (Dem_Event_TestValidHandle(lEventId) == TRUE)                                                                             /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
      && (Dem_DTC_TestDtcSuppressed(lEventId) == FALSE) )
    {
      if ( (Dem_DTCReporting_TestObdHideOccurrences() == FALSE)                                                                  /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
        || (Dem_Cfg_EventSignificance(lEventId) != DEM_CFG_EVENT_SIGNIFICANCE_OCCURRENCE)
        || (Dem_Cfg_EventObdRelated(lEventId) == FALSE) )
      {
        /* Occupied entry */
        lRecordCount = (uint16)(lRecordCount + Dem_SnapshotEntry_GetNumberOfStoredSnapshotRecords(lMemoryEntryId));
      }
    }

    ++lMemoryIndex;
  }

  return lRecordCount;
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */
# endif

# if (DEM_CFG_SUPPORT_SRECS == STD_ON) && (DEM_FEATURE_NEED_TIME_SERIES == STD_ON) && (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_FreezeFrameIterator_GetNumberOfTimeSeriesSRec
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
DEM_LOCAL_INLINE FUNC(uint16, DEM_CODE)
  Dem_FreezeFrameIterator_GetNumberOfTimeSeriesSRec(
  void
  )
{
  Dem_Mem_MemoryInfoPtrType lMemoryInfo;
  Dem_Cfg_MemoryIndexType lMemoryIndex;
  Dem_Cfg_MemoryIndexType lMemoryIndexEnd;
  uint16 lRecordCount;

  lMemoryInfo = Dem_MemStorageManager_MemoryInfoInit(DEM_CFG_MEMORYID_TIMESERIES);
  lMemoryIndex = Dem_MemStorageManager_MemoryIter_Begin(lMemoryInfo);                                                            /* SBSW_DEM_CALL_MEMORYINFO_POINTER */
  lMemoryIndexEnd = Dem_MemStorageManager_MemoryIter_End(lMemoryInfo);                                                           /* SBSW_DEM_CALL_MEMORYINFO_POINTER */
  lRecordCount = 0;

  while (lMemoryIndex < lMemoryIndexEnd)
  {
    Dem_EventIdType lEventId;

    lEventId = Dem_Mem_EntryGetEventId(Dem_Mem_TimeSeriesGetEntry(lMemoryIndex));
    if ( (Dem_Event_TestValidHandle(lEventId) == TRUE)                                                                             /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
      && (Dem_DTC_TestDtcSuppressed(lEventId) == FALSE) )
    {
      if ( (Dem_DTCReporting_TestObdHideOccurrences() == FALSE)                                                                  /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
        || (Dem_Cfg_EventSignificance(lEventId) != DEM_CFG_EVENT_SIGNIFICANCE_OCCURRENCE)
        || (Dem_Cfg_EventObdRelated(lEventId) == FALSE))
      {
        /* Occupied entry */
        lRecordCount = (uint16)(lRecordCount + Dem_Data_TimeSeriesSRecCount(Dem_Mem_TimeSeriesGetEntry(lMemoryIndex)));          /* SBSW_DEM_POINTER_WRITE_TIMESERIESENTRY */
      }
    }

    ++lMemoryIndex;
  }

  return lRecordCount;
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */
# endif

/*!
 * \}
 */
# define DEM_STOP_SEC_CODE
# include "MemMap.h"                                                                                                             /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* ********************************************************************************************************************
 *  SUBCOMPONENT API FUNCTION DEFINITIONS
 *********************************************************************************************************************/
# define DEM_START_SEC_CODE
# include "MemMap.h"                                                                                                             /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \addtogroup Dem_FreezeFrameIterator_Public
 * \{
 */

# if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_FreezeFrameIterator_InitDefault
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_FreezeFrameIterator_InitDefault(
  CONST(Dem_FreezeFrameIterator_HandleType, AUTOMATIC)  FreezeFrameIteratorId
  )
{
  Dem_FreezeFrameIterator_SetDTCFormat(FreezeFrameIteratorId, DEM_FILTERDATA_FILTER_INIT);
}
#endif

# if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_FreezeFrameIterator_TestFilterSet
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_FreezeFrameIterator_TestFilterSet(
  CONST(Dem_FreezeFrameIterator_HandleType, AUTOMATIC)  FreezeFrameIteratorId
  )
{
  return (Dem_FreezeFrameIterator_GetDTCFormat(FreezeFrameIteratorId) != DEM_FILTERDATA_FILTER_INIT);
}
#endif

# if (DEM_CFG_SUPPORT_SRECS == STD_ON) && (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_FreezeFrameIterator_StartIterator
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_FreezeFrameIterator_StartIterator(
  CONST(Dem_FreezeFrameIterator_HandleType, AUTOMATIC)  FreezeFrameIteratorId,
  CONST(Dem_FreezeFrameIterator_DTCFormatType, AUTOMATIC)  FilterDTCFormat,
  CONST(uint8, AUTOMATIC)  MemoryIndex
  )
{
  Dem_SnapshotEntry_IterType lSnapshotEntryIter;
  Dem_SnapshotEntry_IteratorInit(DEM_EVENT_INVALID, DEM_MEMORYENTRY_HANDLE_INVALID, &lSnapshotEntryIter);
  Dem_FreezeFrameIterator_SetMemoryIndex(FreezeFrameIteratorId, MemoryIndex);
  Dem_FreezeFrameIterator_SetSnapshotEntryIterator(FreezeFrameIteratorId, lSnapshotEntryIter);
#  if (DEM_FEATURE_NEED_TIME_SERIES == STD_ON)
  Dem_FreezeFrameIterator_SetTimeSeriesRecordNumber(FreezeFrameIteratorId, 0);
#  endif
  Dem_FreezeFrameIterator_InitIterator(FreezeFrameIteratorId, 0, 0);
  Dem_FreezeFrameIterator_SetDTCFormat(FreezeFrameIteratorId, FilterDTCFormat);
}
# endif

# if (DEM_CFG_SUPPORT_SRECS == STD_ON) && (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_FreezeFrameIterator_GetNext
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_FreezeFrameIterator_GetNext(
CONST(Dem_FreezeFrameIterator_HandleType, AUTOMATIC)    FreezeFrameIteratorId,
P2VAR(uint32, AUTOMATIC, DEM_DCM_DATA)                  DTC,                                                                     /* PRQA S 3206, 3673 */ /* MD_DEM_3206, MD_DEM_16.7 */
P2VAR(uint8, AUTOMATIC, DEM_DCM_DATA)                   RecordNumber                                                             /* PRQA S 3206, 3673 */ /* MD_DEM_3206, MD_DEM_16.7 */
)
{
  boolean lReturnValue;
  lReturnValue = FALSE;

  if (Dem_FreezeFrameIterator_FilterSRec(FreezeFrameIteratorId, DTC, RecordNumber) == TRUE)                                      /* SBSW_DEM_POINTER_FORWARD_API */
  {
    lReturnValue = TRUE;
  }
#  if (DEM_FEATURE_NEED_TIME_SERIES == STD_ON)
  else
  {
    Dem_Mem_MemoryInfoPtrType lMemoryInfo;
    Dem_Cfg_MemoryIndexType   lMemoryIndex;

    lMemoryInfo = Dem_MemStorageManager_MemoryInfoInit(DEM_CFG_MEMORYID_TIMESERIES);
    lMemoryIndex = Dem_FreezeFrameIterator_GetMemoryIndex(FreezeFrameIteratorId);

    if (lMemoryIndex < Dem_MemStorageManager_MemoryIter_Begin(lMemoryInfo))                                                                    /* SBSW_DEM_CALL_MEMORYINFO_POINTER */
    {
      Dem_FreezeFrameIterator_SetMemoryIndex(FreezeFrameIteratorId, Dem_MemStorageManager_MemoryIter_Begin(lMemoryInfo));                      /* SBSW_DEM_CALL_MEMORYINFO_POINTER */
    }

    if (Dem_FreezeFrameIterator_FilterTimeSeriesSRec(FreezeFrameIteratorId, DTC, RecordNumber) == TRUE)                          /* SBSW_DEM_POINTER_FORWARD_API */
    {
      lReturnValue = TRUE;
    }
  }
#  endif

  return lReturnValue;
}
# endif

# if (DEM_CFG_SUPPORT_SRECS == STD_ON) && (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_FreezeFrameIterator_GetNumberOfFreezeFrameRecords
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
DEM_LOCAL_INLINE FUNC(uint16, DEM_CODE)
Dem_FreezeFrameIterator_GetNumberOfFreezeFrameRecords(
void
)
{
  uint16 lRecordCount;
  
  /* Count stored snapshot records */
  lRecordCount = Dem_FreezeFrameIterator_GetNumberOfSRec();
#  if (DEM_FEATURE_NEED_TIME_SERIES == STD_ON)
  lRecordCount = (uint16)(lRecordCount + Dem_FreezeFrameIterator_GetNumberOfTimeSeriesSRec());
#  endif
  return lRecordCount;
}
# endif

/*!
 * \}
 */
# define DEM_STOP_SEC_CODE
# include "MemMap.h"                                                                                                             /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* DEM_FREEZEFRAMEITERATOR_IMPLEMENTATION_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_FreezeFrameIterator_Implementation.h
 *********************************************************************************************************************/
