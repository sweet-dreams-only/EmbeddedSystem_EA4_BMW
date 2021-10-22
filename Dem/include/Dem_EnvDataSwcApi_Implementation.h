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
/*! \addtogroup Dem_EnvDataSwcApi
 *  \{
 *  \file       Dem_EnvDataSwcApi_Implementation.h
 *  \brief      Diagnostic Event Manager (Dem) header file
 *  \details    The EnvDataSwcApi subcomponent contains APIs to read the environmental data (ExtendedData, FreezeFrame...) 
                for SWC APIs.
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

#if !defined (DEM_ENVDATASWCAPI_IMPLEMENTATION_H)
#define DEM_ENVDATASWCAPI_IMPLEMENTATION_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                  /* Own subcomponent header */
/* ------------------------------------------------------------------------- */
#include "Dem_EnvDataSwcApi_Interface.h"

                                                    /* Used subcomponent API */
/* ------------------------------------------------------------------------- */
#include "Dem_Cfg_Definitions.h"
#include "Dem_Event_Implementation.h"
#include "Dem_EventInternalStatus_Implementation.h"
#include "Dem_MemoryEntry_Implementation.h"
#include "Dem_SnapshotEntry_Implementation.h"
#include "Dem_ExtendedEntry_Implementation.h"
#include "Dem_MemStorageManager_Implementation.h"
#include "Dem_DataReportIF_Implementation.h"

                                                   /* Subcomponents callbacks*/
/* ------------------------------------------------------------------------- */

/* ********************************************************************************************************************
 *  SUBCOMPONENT PRIVATE FUNCTION DEFINITIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \addtogroup Dem_EnvDataSwcApi_Private
 * \{
 */

#if (DEM_CFG_SUPPORT_OBDII == STD_ON)                                                                                            /* COV_MSR_UNSUPPORTED XF */
/* ****************************************************************************
 % Dem_EnvDataSwcApi_CopyPidFromObdIIFreezeFrame
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_EnvDataSwcApi_CopyPidFromObdIIFreezeFrame(
  CONST(Dem_EventIdType, AUTOMATIC)  MasterEventId,
  CONST(uint16, AUTOMATIC)  DataId,
  CONSTP2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)  DestBuffer,
  CONSTP2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  BufSize                                                                          /* PRQA S 3206, 3673 */ /* MD_DEM_3206, MD_DEM_16.7 */
)
{
  Std_ReturnType lReturnValue;
  lReturnValue = DEM_NO_SUCH_ELEMENT;

  if (Dem_Cfg_EventObdRelated(MasterEventId) == TRUE)
  {
    if ((Dem_GetHiByte(DataId) == 0xf4U)
      || (Dem_GetHiByte(DataId) == 0x00U))
    {
      uint8 lSelectedIndex;
      lSelectedIndex = Dem_Mem_FreezeFrameFindIndex(MasterEventId);
      if (lSelectedIndex != Dem_Cfg_GlobalObdIIFFCount())
      { /* Event has a stored OBD freeze frame */
        Dem_ConstSharedDataPtrType lSourceBuffer;
        lSourceBuffer = (Dem_ConstSharedDataPtrType)Dem_Mem_FreezeFrameObdIIGetDataPtr(lSelectedIndex);
        lReturnValue = Dem_DataReportIF_CopyPidFromObdIIFreezeFrame(DataId, lSourceBuffer, DestBuffer, BufSize);

        /* Check if Freeze Frame DTC is still valid, if not the Freeze Frame data is not consistent */
        if ((lReturnValue == E_OK)
          && (MasterEventId != Dem_Mem_FreezeFrameGetEvent(lSelectedIndex)))
        {
          lReturnValue = DEM_NO_SUCH_ELEMENT;
        }
      }
    }
  }
  if (lReturnValue != E_OK)
  {
    *BufSize = 0;
  }
  return lReturnValue;
}                                                                                                                                /* PRQA S 6050, 6080 */ /* MD_MSR_STCAL, MD_MSR_STMIF */
#endif /* (DEM_CFG_SUPPORT_OBDII == STD_ON) */

#if (DEM_CFG_SUPPORT_WWHOBD == STD_ON)                                                                                           /* COV_MSR_UNSUPPORTED XF */
/* ****************************************************************************
% Dem_EnvDataSwcApi_CopyDidFromWwhObdFreezeFrame
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
Dem_EnvDataSwcApi_CopyDidFromWwhObdFreezeFrame(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(uint16, AUTOMATIC)  DataId,
  CONSTP2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)  DestBuffer,
  CONSTP2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  BufSize                                                                          /* PRQA S 3206, 3673 */ /* MD_DEM_3206, MD_DEM_16.7 */
)
{
  Std_ReturnType lReturnValue;

  if (Dem_Cfg_EventObdRelated(EventId) == FALSE)
  {
    *BufSize = 0;                                                                                                                /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    lReturnValue = DEM_NO_SUCH_ELEMENT;
  }
  else
  {
    Dem_Mem_MemoryInfoPtrType lMemoryInfo;
    Dem_Cfg_MemoryIndexType lMemoryIndex;
    boolean lModificationDetected;

    lMemoryInfo = Dem_MemStorageManager_MemoryInfoInit(Dem_Cfg_EventDestination(EventId));

    do
    {
      lModificationDetected = FALSE;
      lMemoryIndex = Dem_MemStorageManager_MemoryFindIndex(lMemoryInfo, EventId);                                                              /* SBSW_DEM_CALL_MEMORYINFO_POINTER */

      if (lMemoryIndex != DEM_MEM_INVALID_MEMORY_INDEX)
      {
        uint8 lUpdateState;

        /* The record exists as soon as an primary entry exists, but without critical section it could age or displace */
        lUpdateState = Dem_Mem_MemoryUpdateGetState(lMemoryIndex);

        if (Dem_Mem_UpdateTestInProgress(lUpdateState) == FALSE)
        { /* This call does not currently interrupt a concurrent data update */

          lReturnValue = Dem_DataReportIF_CopyDidFromWwhObdFreezeFrame(EventId, DataId, lMemoryIndex, DestBuffer, BufSize);

          if ( (lReturnValue == E_OK)                                                                                            /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
            && (lUpdateState != Dem_Mem_MemoryUpdateGetState(lMemoryIndex)) )
          { /* The memory entry has been modified while trying to copy the stored data. */
            /* We cannot be sure it is still used by the same event, so start from the
            beginning */
            lModificationDetected = TRUE;
          }
        }
        else
        {
          /* The caller task has higher priority than Dem_MainFunction, but we cannot 'wait' for
          the update to complete. The requested data is not available at this moment. */
          *BufSize = 0;                                                                                                          /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
          lReturnValue = E_NOT_OK;
        }
      }
      else
      {
        /* The requested event is currently not stored in the event memory */
        *BufSize = 0;                                                                                                            /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
        lReturnValue = DEM_NO_SUCH_ELEMENT;
      }
    } while (lModificationDetected == TRUE);
  }
  return lReturnValue;
}                                                                                                                                /* PRQA S 6030, 6050, 6080 */ /* MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
#endif

#if (DEM_FEATURE_NEED_TIME_SERIES == STD_ON)
/* ****************************************************************************
% Dem_EnvDataSwcApi_CopyDidFromTimeSeriesSRec
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
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_EnvDataSwcApi_CopyDidFromTimeSeriesSRec(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(uint8, AUTOMATIC)  RecordNumber,
  CONST(uint16, AUTOMATIC)  DataId,
  CONSTP2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)  DestBuffer,
  CONSTP2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  BufSize                                                                          /* PRQA S 3206, 3673 */ /* MD_DEM_3206, MD_DEM_16.7 */
)
{
  Std_ReturnType lReturnValue;

  if (Dem_Data_TimeSeriesSRecIsValid(EventId, RecordNumber) == FALSE)
  {
    *BufSize = 0;                                                                                                                /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    lReturnValue = DEM_NO_SUCH_ELEMENT;
  }
  else
  {
    Dem_Cfg_MemoryIndexType lMemoryIndex;
    boolean lModificationDetected;
    uint16 DestBufferSize;
    DestBufferSize = *BufSize;

    do
    {
      *BufSize = DestBufferSize;                                                                                                 /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
      lModificationDetected = FALSE;
      lMemoryIndex = Dem_Mem_TimeSeriesFindIndex(EventId);

      if (lMemoryIndex == DEM_MEM_INVALID_MEMORY_INDEX)
      {
        /* The requested event is currently not stored in the event memory */
        *BufSize = 0;                                                                                                            /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
        lReturnValue = DEM_NO_SUCH_ELEMENT;
      }
      else
      { /* The record currently exists, but without critical section it could age or displace */
        uint8 lUpdateState;

        lUpdateState = Dem_Mem_MemoryUpdateGetState(lMemoryIndex);
        if (Dem_Mem_UpdateTestInProgress(lUpdateState) == TRUE)
        {
          /* The caller task has higher priority than Dem_MainFunction, but we cannot 'wait' for
          the update to complete. The requested data is not available at this moment. */
          *BufSize = 0;                                                                                                          /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
          lReturnValue = E_NOT_OK;
        }
        else
        { /* This call does not currently interrupt a concurrent data update */
          Dem_Mem_ConstTimeSeriesEntryPtrType lEntry;
          lEntry = Dem_Mem_TimeSeriesGetEntry(lMemoryIndex);

          if (Dem_Data_TimeSeriesSRecIsStored(lEntry, RecordNumber) == TRUE)                                                     /* SBSW_DEM_POINTER_WRITE_TIMESERIESENTRY */
          {
            lReturnValue = Dem_DataReportIF_CopyDidTimeSeriesSRec(lEntry, RecordNumber, DataId, DestBuffer, BufSize);            /* SBSW_DEM_POINTER_WRITE_TIMESERIESENTRY */
          }
          else
          {
            /* The requested data is currently not stored in a time series entry */
            *BufSize = 0;                                                                                                        /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
            lReturnValue = DEM_NO_SUCH_ELEMENT;
          }

          if ((lReturnValue == E_OK) && (lUpdateState != Dem_Mem_MemoryUpdateGetState(lMemoryIndex)))                            /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
          { /* The memory entry has been modified while trying to copy the stored data. */
            /* We cannot be sure it is still used by the same event, so start from the
            beginning */
            lModificationDetected = TRUE;
          }
        }
      }
    } while (lModificationDetected == TRUE);
  }
  return lReturnValue;
}                                                                                                                                /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
#endif

#if (DEM_CFG_SUPPORT_SRECS == STD_ON)
/* ****************************************************************************
% Dem_EnvDataSwcApi_CopyDidFromSRec
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
 */
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_EnvDataSwcApi_CopyDidFromSRec(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(uint8, AUTOMATIC)  RecordNumber,
  CONST(uint16, AUTOMATIC)  DataId,
  CONSTP2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)  DestBuffer,
  CONSTP2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  BufSize                                                                          /* PRQA S 3206, 3673 */ /* MD_DEM_3206, MD_DEM_16.7 */
)
{
  Std_ReturnType lReturnValue;

  lReturnValue = E_OK;

# if (DEM_CFG_SUPPORT_SRECS_CONFIGURED == STD_ON)
  if (RecordNumber == 0xff)
  {
    *BufSize = 0;                                                                                                                /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    lReturnValue = E_NOT_OK;
  }
  else
# endif
  {
    Dem_Mem_MemoryInfoPtrType lMemoryInfo;
    Dem_Cfg_MemoryIndexType lMemoryIndex;
    boolean lModificationDetected;

    lMemoryInfo = Dem_MemStorageManager_MemoryInfoInit(Dem_Cfg_EventDestination(EventId));

    do
    {
      lModificationDetected = FALSE;
      lMemoryIndex = Dem_MemStorageManager_MemoryFindIndex(lMemoryInfo, EventId);                                                /* SBSW_DEM_CALL_MEMORYINFO_POINTER */

      if (lMemoryIndex != DEM_MEM_INVALID_MEMORY_INDEX)
      { /* The record currently exists, but without critical section it could age or displace */
        uint8 lUpdateState;

        lUpdateState = Dem_Mem_MemoryUpdateGetState(lMemoryIndex);

        if (Dem_Mem_UpdateTestInProgress(lUpdateState) == FALSE)
        { /* This call does not currently interrupt a concurrent data update */
          Dem_SnapshotEntry_IterType lSnapshotEntryIter;

# if (DEM_CFG_SUPPORT_SRECS_CALCULATED == STD_ON)
          if (RecordNumber == 0xffU)
          {
            Dem_SnapshotEntry_IteratorSetLastStoredEntry(Dem_MemStorageManager_GetMemoryEntryId(lMemoryIndex), &lSnapshotEntryIter);
          }
          else
# endif
          {
            for (Dem_SnapshotEntry_IteratorInit(EventId, Dem_MemStorageManager_GetMemoryEntryId(lMemoryIndex), &lSnapshotEntryIter);
                 Dem_SnapshotEntry_IteratorExists(&lSnapshotEntryIter) == TRUE;
                 Dem_SnapshotEntry_IteratorNext(&lSnapshotEntryIter))
            {
              Dem_Cfg_SRecIndexType lCfgSRecIndex;

              lCfgSRecIndex = Dem_SnapshotEntry_IteratorGetSnapshotRecordIndex(&lSnapshotEntryIter);

              if (RecordNumber == Dem_Cfg_SRecId(lCfgSRecIndex))
              {
                break;
              }
            }
            if (Dem_SnapshotEntry_IteratorExists(&lSnapshotEntryIter) == FALSE)
            {
              *BufSize = 0;                                                                                                      /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
              lReturnValue = DEM_NO_SUCH_ELEMENT;
            }
          }

          if (lReturnValue == E_OK)
          {
            if (Dem_SnapshotEntry_IteratorIsSnapshotRecordStored(&lSnapshotEntryIter) == TRUE)
            {
              lReturnValue = Dem_DataReportIF_CopyDidSRec(&lSnapshotEntryIter, DataId, DestBuffer, BufSize);
            }
            else
            {
              /* The requested data is currently not stored in the event memory */
              *BufSize = 0;                                                                                                      /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
              lReturnValue = DEM_NO_SUCH_ELEMENT;
            }

            if ((lReturnValue == E_OK)                                                                                           /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
              && (Dem_Mem_MemoryUpdateGetState(lMemoryIndex) != lUpdateState))
            { /* The memory entry has been modified while trying to copy the stored data. */
              /* We cannot be sure it is still used by the same event, so start from the
              beginning */
              lModificationDetected = TRUE;
            }
          }
        }
        else
        {
          /* The caller task has higher priority than Dem_MainFunction, but we cannot 'wait' for
          the update to complete. The requested data is not available at this moment. */
          *BufSize = 0;                                                                                                          /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
          lReturnValue = E_NOT_OK;
        }
      }
      else
      {
        /* The requested event is currently not stored in the event memory */
        *BufSize = 0;                                                                                                            /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
        lReturnValue = DEM_NO_SUCH_ELEMENT;
      }
    } while (lModificationDetected == TRUE);
  }
  return lReturnValue;
}                                                                                                                                /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
#endif /* (DEM_CFG_SUPPORT_SRECS == STD_ON) */

#if (DEM_CFG_SUPPORT_ERECS == STD_ON)
/* ****************************************************************************
% Dem_EnvDataSwcApi_CopyERecs
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
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_EnvDataSwcApi_CopyERecs(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(uint8, AUTOMATIC)  RecordNumber,
  CONSTP2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)  DestBuffer,
  CONSTP2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  BufSize
  )
{
  Std_ReturnType lReturnValue;
  Dem_Cfg_ERecIndexType lCfgERecIndex;
  Dem_ExtendedEntry_IterType lExtendedEntryIter;

  lCfgERecIndex = 0;

  /* Find the requested record, and it's storage location */
  for (Dem_ExtendedEntry_IteratorInit(EventId, DEM_MEMORYENTRY_HANDLE_INVALID, &lExtendedEntryIter);
       Dem_ExtendedEntry_IteratorExists(&lExtendedEntryIter) == TRUE;
       Dem_ExtendedEntry_IteratorNext(&lExtendedEntryIter))
  {
    lCfgERecIndex = Dem_ExtendedEntry_IteratorGetExtendedRecordIndex(&lExtendedEntryIter);

    if (RecordNumber == Dem_Cfg_DidNumber(Dem_Cfg_ERecDid(lCfgERecIndex)))
    {
      break;
    }
  }

  if (Dem_ExtendedEntry_IteratorExists(&lExtendedEntryIter) == TRUE)
  { /* Found the record, retrieve it from its storage */
    uint8 lRecordType;
    lRecordType = Dem_Cfg_ERecType(lCfgERecIndex);

    if (lRecordType != DEM_CFG_EREC_TYPE_GLOBAL)
    { /* A stored record needs to be retrieved from event memory */
      Dem_Mem_MemoryInfoPtrType lMemoryInfo;
      Dem_Cfg_MemoryIndexType lMemoryIndex;
      boolean lModificationDetected;

      lMemoryInfo = Dem_MemStorageManager_MemoryInfoInit(Dem_Cfg_EventDestination(EventId));

      do
      {
        lModificationDetected = FALSE;

        lMemoryIndex = Dem_MemStorageManager_MemoryFindIndex(lMemoryInfo, EventId);                                              /* SBSW_DEM_CALL_MEMORYINFO_POINTER */
        if (lMemoryIndex != DEM_MEM_INVALID_MEMORY_INDEX)
        { /* The record currently exists, but without critical section it could age or displace */
          uint8 lUpdateState;
          lUpdateState = Dem_Mem_MemoryUpdateGetState(lMemoryIndex);

          if (Dem_Mem_UpdateTestInProgress(lUpdateState) == FALSE)
          { /* This call does not currently interrupt a concurrent data update */
            Dem_ExtendedEntry_IteratorSetMemoryEntryHandle(Dem_MemStorageManager_GetMemoryEntryId(lMemoryIndex), &lExtendedEntryIter);
# if (DEM_CFG_SUPPORT_USER_ERECS == STD_ON)
            /* Supported record, test if it is currently stored */
            if ( (lRecordType == DEM_CFG_EREC_TYPE_USER)                                                                         /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
              && (Dem_ExtendedEntry_IteratorIsExtendedRecordStored(&lExtendedEntryIter)  == FALSE) )
            { /* The DTC has an event entry, but the requested record was not yet stored */
              *BufSize = 0;                                                                                                      /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
              lReturnValue = DEM_NO_SUCH_ELEMENT;
            }
            else
# endif
            {
              if (Dem_Cfg_DidSize(Dem_Cfg_ERecDid(lCfgERecIndex)) > *BufSize)
              {
                *BufSize = 0;                                                                                                    /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
                lReturnValue = DEM_BUFFER_TOO_SMALL;
              }
              else if (Dem_DataReportIF_CopyExtendedDataRecord(&lExtendedEntryIter, DestBuffer, BufSize) == TRUE)
              {
                lReturnValue = E_OK;
              }
              else
              {
                lReturnValue = DEM_NO_SUCH_ELEMENT;
              }
            }

            if (lUpdateState != Dem_Mem_MemoryUpdateGetState(lMemoryIndex))
            { /* The memory entry has been modified while trying to copy the stored data. */
              /* We cannot be sure it is still used by the same event, so start from the
              beginning */
              lModificationDetected = TRUE;
            }
          }
          else
          { /* The caller task has higher priority than Dem_MainFunction, but we cannot 'wait' for
            the update to complete. The requested data is not available at this moment. */
            *BufSize = 0;                                                                                                        /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
            lReturnValue = E_NOT_OK;
          }
        }
        else
        { /* The requested data is currently not stored in the event memory */
          *BufSize = 0;                                                                                                          /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
          lReturnValue = DEM_NO_SUCH_ELEMENT;
        }
      } while (lModificationDetected == TRUE);
    }
    else
    { /* Statistic records always need to collect current data - if possible depending on event state */
      if (Dem_Cfg_DidSize(Dem_Cfg_ERecDid(lCfgERecIndex)) > *BufSize)
      {
        *BufSize = 0;                                                                                                            /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
        lReturnValue = DEM_BUFFER_TOO_SMALL;
      }
      else if (Dem_DataReportIF_CopyExtendedDataRecord(&lExtendedEntryIter, DestBuffer, BufSize) == TRUE)
      {
        lReturnValue = E_OK;
      }
      else
      {
        lReturnValue = DEM_NO_SUCH_ELEMENT;
      }
    }
  }
  else
  {
    *BufSize = 0;                                                                                                                /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    lReturnValue = DEM_NO_SUCH_ELEMENT;
  }
  return lReturnValue;
}                                                                                                                                /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
#endif /* (DEM_CFG_SUPPORT_ERECS == STD_ON) */

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
 * \addtogroup Dem_EnvDataSwcApi_Public
 * \{
 */

/* ****************************************************************************
 % Dem_EnvDataSwcApi_GetEventFreezeFrameDataEx
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
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_EnvDataSwcApi_GetEventFreezeFrameDataEx(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(uint8, AUTOMATIC)  RecordNumber,
  CONST(uint16, AUTOMATIC)  DataId,
  CONSTP2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)  DestBuffer,                                                                       /* PRQA S 3206, 3673 */ /* MD_DEM_3206, MD_DEM_16.7_False */
  CONSTP2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  BufSize
  )
{
  Std_ReturnType lReturnValue;
  lReturnValue = E_NOT_OK;

  if ( (Dem_Cfg_EventAvailableByVariant(EventId) == TRUE)                                                                        /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
    && (Dem_EventInternalStatus_TestEventDisconnected(Dem_Event_GetInternalStatus(EventId)) == FALSE) )
  {
    if (RecordNumber == 0x00)
    {
#if (DEM_CFG_SUPPORT_OBDII == STD_ON) || (DEM_CFG_SUPPORT_WWHOBD == STD_ON)                                                      /* COV_MSR_UNSUPPORTED XF xf xf */
      Dem_EventIdType lMasterEventId;

      lMasterEventId = Dem_Cfg_GetMasterEvent(EventId);
#endif
#if (DEM_CFG_SUPPORT_OBDII == STD_ON)                                                                                            /* PRQA S 0883 */ /* MD_DEM_19.15 */
      lReturnValue = Dem_EnvDataSwcApi_CopyPidFromObdIIFreezeFrame(lMasterEventId, DataId, DestBuffer, BufSize);                 /* SBSW_DEM_POINTER_FORWARD_API */
#elif (DEM_CFG_SUPPORT_WWHOBD == STD_ON)
      lReturnValue = Dem_EnvDataSwcApi_CopyDidFromWwhObdFreezeFrame(lMasterEventId, DataId, DestBuffer, BufSize);                /* SBSW_DEM_POINTER_FORWARD_API */
#else
      *BufSize = 0;                                                                                                              /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
      lReturnValue = DEM_NO_SUCH_ELEMENT;
#endif
    }
#if (DEM_FEATURE_NEED_TIME_SERIES == STD_ON)
    else if ((RecordNumber >= 0x10) && (RecordNumber <= 0x4F))
    {
      Dem_EventIdType lMasterEventId;

      lMasterEventId = Dem_Cfg_GetMasterEvent(EventId);
      lReturnValue = Dem_EnvDataSwcApi_CopyDidFromTimeSeriesSRec(lMasterEventId, RecordNumber, DataId, DestBuffer, BufSize);     /* SBSW_DEM_POINTER_FORWARD_API */
    }
#endif
#if (DEM_CFG_SUPPORT_SRECS == STD_ON)
    else
    {
      Dem_EventIdType lMasterEventId;

      lMasterEventId = Dem_Cfg_GetMasterEvent(EventId);
      lReturnValue = Dem_EnvDataSwcApi_CopyDidFromSRec(lMasterEventId, RecordNumber, DataId, DestBuffer, BufSize);               /* SBSW_DEM_POINTER_FORWARD_API */
    }
#else
    else
    {
      DEM_IGNORE_UNUSED_CONST_ARGUMENT(DataId)                                                                                   /* PRQA S 3112 */ /* MD_DEM_14.2 */
      DEM_IGNORE_UNUSED_CONST_ARGUMENT(DestBuffer)                                                                               /* PRQA S 3112 */ /* MD_DEM_14.2 */

      *BufSize = 0;                                                                                                              /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    }
#endif /* (DEM_CFG_SUPPORT_SRECS == STD_ON) */
  }
  else
  {
    *BufSize = 0;                                                                                                                /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
  }

  return lReturnValue;
}                                                                                                                                /* PRQA S 6050, 6080 */ /* MD_MSR_STCAL, MD_MSR_STMIF */

/* ****************************************************************************
 % Dem_EnvDataSwcApi_GetEventExtendedDataRecordEx
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
Dem_EnvDataSwcApi_GetEventExtendedDataRecordEx(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(uint8, AUTOMATIC)  RecordNumber,
  CONSTP2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)  DestBuffer,                                                                       /* PRQA S 3206, 3673 */ /* MD_DEM_3206, MD_DEM_16.7_False */
  CONSTP2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  BufSize
  )
{
  Std_ReturnType lReturnValue;

#if (DEM_CFG_SUPPORT_ERECS == STD_ON)
  if ( (Dem_Cfg_EventAvailableByVariant(EventId) == TRUE)                                                                        /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
    && (Dem_EventInternalStatus_TestEventDisconnected(Dem_Event_GetInternalStatus(EventId)) == FALSE) )
  {
    /* Find the Record number */
    Dem_EventIdType lMasterEventId;
    lMasterEventId = Dem_Cfg_GetMasterEvent(EventId);
    lReturnValue = Dem_EnvDataSwcApi_CopyERecs(lMasterEventId, RecordNumber, DestBuffer, BufSize);                               /* SBSW_DEM_POINTER_FORWARD_API */
  }
  else
  {
    *BufSize = 0;                                                                                                                /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    lReturnValue = E_NOT_OK;
  }
#else /* (DEM_CFG_SUPPORT_ERECS == STD_ON) */
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(EventId)                                                                                      /* PRQA S 3112 */ /* MD_DEM_14.2 */
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(RecordNumber)                                                                                 /* PRQA S 3112 */ /* MD_DEM_14.2 */
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(DestBuffer)                                                                                   /* PRQA S 3112 */ /* MD_DEM_14.2 */
  *BufSize = 0;                                                                                                                  /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
  lReturnValue = E_NOT_OK;
#endif

  return lReturnValue;
}                                                                                                                                /* PRQA S 6050, 6080 */ /* MD_MSR_STCAL, MD_MSR_STMIF */

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* DEM_ENVDATASWCAPI_IMPLEMENTATION_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_EnvDataSwcApi_Implementation.h
 *********************************************************************************************************************/
