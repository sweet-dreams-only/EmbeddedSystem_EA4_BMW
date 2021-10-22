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
 *  \addtogroup Dem_Dcm
 *  \{
 *  \file       Dem_Dcm_Implementation.h
 *  \brief      Diagnostic Event Manager (Dem) Implementation file
 *  \details
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

#if !defined (DEM_DCM_IMPLEMENTATION_H)
#define DEM_DCM_IMPLEMENTATION_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                  /* Own subcomponent header */
/* ------------------------------------------------------------------------- */
#include "Dem_Dcm_Interface.h"

                                                    /* Used subcomponent API */
/* ------------------------------------------------------------------------- */
#include "Dem_ClientAccess_Implementation.h"
#include "Dem_FreezeFrameIterator_Interface.h"
#include "Dem_MemoryEntry_Implementation.h"
#include "Dem_SnapshotEntry_Implementation.h"
#include "Dem_ExtendedEntry_Implementation.h"
#include "Dem_DTCReadoutBuffer_Implementation.h"
#include "Dem_DTCReporting_Implementation.h"
#include "Dem_UDSStatus_Implementation.h"
#include "Dem_DTC_Implementation.h"
#include "Dem_Event_Implementation.h"
#include "Dem_DataReportIF_Implementation.h"
#include "Dem_MemStorageManager_Implementation.h"
#include "Dem_MemState_Implementation.h"

                                                   /* Subcomponents callbacks*/
/* ------------------------------------------------------------------------- */
#include "Dem_Error_Interface.h"

/* ********************************************************************************************************************
 *  SUBCOMPONENT DATA
 *********************************************************************************************************************/
#define DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#if (DEM_FEATURE_NEED_IUMPR == STD_ON)                                                                                           /* COV_MSR_UNSUPPORTED XF */
/*! Filter data for IUMPR readout */
DEM_LOCAL VAR(Dem_Dcm_IumprFilterInfoType, DEM_VAR_NOINIT)  Dem_Dcm_IumprFilterInfo;
#endif

#define DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* ********************************************************************************************************************
 *  SUBCOMPONENT PRIVATE FUNCTION DEFINITIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \addtogroup Dem_Dcm_Private
 * \{
 */

#if (DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_ERECS == STD_ON)
/* ****************************************************************************
 % Dem_Dcm_ExtendedDataRecord_IsRecordMatch
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE boolean Dem_Dcm_ExtendedDataRecord_IsRecordMatch(
  CONST(uint8, AUTOMATIC) RecordNumberFilter, 
  CONST(uint8, AUTOMATIC) RecordNumber
  )
{
  boolean lMatch;

  if ( (RecordNumberFilter == DEM_DCM_EXTENDEDDATARECORD_ALL)
    && (RecordNumber >= DEM_DCM_EXTENDEDDATARECORD_FIRST)
    && (RecordNumber <= DEM_DCM_EXTENDEDDATARECORD_LAST))
  {
    lMatch = TRUE;
  }
# if (DEM_CFG_SUPPORT_OBDII ==  STD_ON)
  else
  if ( (RecordNumberFilter == DEM_DCM_EXTENDEDDATARECORD_OBD)
    && (RecordNumber >= DEM_DCM_EXTENDEDDATARECORD_FIRST_OBD)
    && (RecordNumber <= DEM_DCM_EXTENDEDDATARECORD_LAST))
  {
    lMatch = TRUE;
  }
# endif
  else
  if (RecordNumberFilter == RecordNumber)
  {
    lMatch = TRUE;
  }
  else
  {
    lMatch = FALSE;
  }

  return lMatch;
}
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_ERECS == STD_ON)
/* ****************************************************************************
 % Dem_Dcm_ReadExtendedDataRecord
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
Dem_Dcm_ReadExtendedDataRecord(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId,
  CONSTP2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)  DestBuffer,
  CONSTP2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  BufSize
  )
{
  uint8 lERecType;
  Dem_ExtendedEntry_IterType lExtendedEntryIter;
  Dem_Cfg_ERecIndexType lCfgERecIndex;
  Std_ReturnType lReturnValue;
  
  lExtendedEntryIter = Dem_DTCReadoutBuffer_GetExtendedEntryIterator(ReadoutBufferId);
  lCfgERecIndex = Dem_ExtendedEntry_IteratorGetExtendedRecordIndex(&lExtendedEntryIter);
  lERecType = Dem_Cfg_ERecType(lCfgERecIndex);
  
  if ( (lERecType == DEM_CFG_EREC_TYPE_GLOBAL)                                                                                   /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
    || ((Dem_DTCReadoutBuffer_TestStoredDataAvailable(ReadoutBufferId) == TRUE)
# if (DEM_CFG_SUPPORT_USER_ERECS == STD_ON)
         && ( (lERecType == DEM_CFG_EREC_TYPE_INTERNAL)
           || (Dem_ExtendedEntry_IteratorIsExtendedRecordStored(&lExtendedEntryIter) == TRUE)
            )
# endif
       )
      )
  { 
    /* Check buffer size after stored status - the buffer does not need to be large enough for an empty response */
    if ((Dem_Cfg_DidSize(Dem_Cfg_ERecDid(lCfgERecIndex)) + 1) > *BufSize)
    {
      lReturnValue = DEM_BUFFER_TOO_SMALL;
    }
    else
    {
      DestBuffer[0] = (uint8)Dem_Cfg_DidNumber(Dem_Cfg_ERecDid(lCfgERecIndex));
      /*First byte contains RecNr -> skip it to copy data*/
      *BufSize = (*BufSize - 1);
      if (Dem_DataReportIF_CopyExtendedDataRecord(&lExtendedEntryIter, &DestBuffer[1], BufSize) == TRUE)
      {
        /*Add size of RecNr to number of written bytes*/
        *BufSize = (*BufSize + 1);
      }
      lReturnValue = E_OK;
    }
  }
  else
  {
    /* records currently not stored are returned with empty content */
    lReturnValue = E_OK;
    *BufSize = 0;                                                                                                              /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
  }

  return lReturnValue;
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */
#endif

# if (DEM_CFG_SUPPORT_DCM == STD_ON) \
    && ( (DEM_CFG_SUPPORT_SRECS == STD_ON) \
    ||   ((DEM_CFG_SUPPORT_OBDII == STD_ON) && (DEM_CFG_SUPPORT_OBDII_FREEZEFRAME_IN_SVC19 == STD_ON)) \
    ||   (DEM_CFG_SUPPORT_WWHOBD == STD_ON) \
    ||   (DEM_FEATURE_NEED_TIME_SERIES == STD_ON))
/* ****************************************************************************
 % Dem_Dcm_SnapshotDataRecord_TestRecordMatch
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
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE) Dem_Dcm_SnapshotDataRecord_TestRecordMatch(
  CONST(uint8, AUTOMATIC) RecordNumberFilter, 
  CONST(uint8, AUTOMATIC) RecordNumber
  )
{
  boolean lMatch;

  if (RecordNumberFilter == DEM_DCM_SNAPSHOTDATARECORD_ALL) 
  {
# if (DEM_CFG_SUPPORT_WWHOBD == STD_OFF) \
     && ((DEM_CFG_SUPPORT_OBDII == STD_OFF) || (DEM_CFG_SUPPORT_OBDII_FREEZEFRAME_IN_SVC19 == STD_OFF))
    /* exclude OBD Snapshot if necessary */
    if (RecordNumber == DEM_DCM_SNAPSHOTDATARECORD_OBD)
    {
      lMatch = FALSE;
    }
    else
# endif
    {
      lMatch = TRUE;
    }
  }
  else
  {
    if (RecordNumberFilter == RecordNumber)
    {
      lMatch = TRUE;
    }
    else
    {
      lMatch = FALSE;
    }
  }
  return lMatch;
}
#endif

# if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_Dcm_SnapshotDataRecord_SnapshotIteratorInit
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
DEM_LOCAL FUNC(void, DEM_CODE) Dem_Dcm_SnapshotDataRecord_SnapshotIteratorInit(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId
  )
{
  Dem_Cfg_ComplexIterType lSourceIterator;

  lSourceIterator = Dem_DTCReadoutBuffer_GetSnapshotSourceIterator(ReadoutBufferId);
  switch (Dem_DTCReadoutBuffer_GetSnapshotRecordSource(ReadoutBufferId))
  {
    case Dem_DTCReadoutBuffer_SnapshotSource_Obd:
    {
      Dem_Cfg_ComplexIterInit(&lSourceIterator, 0, 1);
    }
    break;

    case Dem_DTCReadoutBuffer_SnapshotSource_Srec:
    {
      Dem_Cfg_ComplexIterInit(&lSourceIterator, 0, 0);
    }
    break;

    case Dem_DTCReadoutBuffer_SnapshotSource_Vcc:
    {
      Dem_Cfg_ComplexIterInit(&lSourceIterator, 0, 1);
    }
    break;

    case Dem_DTCReadoutBuffer_SnapshotSource_Tmc_Fast:
    {
      Dem_EventIdType lEventId;

      lEventId = Dem_DTCReadoutBuffer_GetEventId(ReadoutBufferId);
      if (Dem_Cfg_EventSupportTimeSeriesFast(lEventId) == TRUE)
      {
        Dem_Cfg_ComplexIterInit(&lSourceIterator,
          DEM_DCM_SNAPSHOTDATARECORD_TMC_FAST_FIRST,
          DEM_DCM_SNAPSHOTDATARECORD_TMC_FAST_FIRST + 
          (Dem_Cfg_TimeSeriesPastSamplesFast() + Dem_Cfg_TimeSeriesFutureSamplesFast())
          );
      }
      else
      {
        Dem_Cfg_ComplexIterInit(&lSourceIterator, 0, 0);
      }
    }
    break;

    case Dem_DTCReadoutBuffer_SnapshotSource_Tmc_Normal:
    {
      Dem_EventIdType lEventId;

      lEventId = Dem_DTCReadoutBuffer_GetEventId(ReadoutBufferId);

      if (Dem_Cfg_EventSupportTimeSeriesNormal(lEventId) == TRUE)
      {
        Dem_Cfg_ComplexIterInit(&lSourceIterator,
          DEM_DCM_SNAPSHOTDATARECORD_TMC_NORMAL_FIRST,
          DEM_DCM_SNAPSHOTDATARECORD_TMC_NORMAL_FIRST + 
          (Dem_Cfg_TimeSeriesPastSamplesNormal() + Dem_Cfg_TimeSeriesFutureSamplesNormal())
          );
      }
      else
      {
        Dem_Cfg_ComplexIterInit(&lSourceIterator, 0, 0);
      }
    }
    break;

    default:
    {
      Dem_Cfg_ComplexIterInit(&lSourceIterator, 0, 0);
    }
    break;
  }

  Dem_DTCReadoutBuffer_SetSnapshotSourceIterator(ReadoutBufferId, lSourceIterator);
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */
#endif

# if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_Dcm_SnapshotDataRecord_SourceSelectNext
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
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE) Dem_Dcm_SnapshotDataRecord_SourceSelectNext(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId
  )
{
  Std_ReturnType lReturnValue;

  if (Dem_DTCReadoutBuffer_GetSnapshotRecordNumber(ReadoutBufferId) == DEM_DCM_SNAPSHOTDATARECORD_ALL)
  {
    switch (Dem_DTCReadoutBuffer_GetSnapshotRecordSource(ReadoutBufferId))
    {
    case Dem_DTCReadoutBuffer_SnapshotSource_Obd:
      Dem_DTCReadoutBuffer_SetSnapshotRecordSource(ReadoutBufferId, Dem_DTCReadoutBuffer_SnapshotSource_Srec);
      lReturnValue = E_OK;
      break;
    case Dem_DTCReadoutBuffer_SnapshotSource_Srec:
      Dem_DTCReadoutBuffer_SetSnapshotRecordSource(ReadoutBufferId, Dem_DTCReadoutBuffer_SnapshotSource_Vcc);
      lReturnValue = E_OK;
      break;
    case Dem_DTCReadoutBuffer_SnapshotSource_Vcc:
      Dem_DTCReadoutBuffer_SetSnapshotRecordSource(ReadoutBufferId, Dem_DTCReadoutBuffer_SnapshotSource_Tmc_Fast);
      lReturnValue = E_OK;
      break;
    case Dem_DTCReadoutBuffer_SnapshotSource_Tmc_Fast:
      Dem_DTCReadoutBuffer_SetSnapshotRecordSource(ReadoutBufferId, Dem_DTCReadoutBuffer_SnapshotSource_Tmc_Normal);
      lReturnValue = E_OK;
      break;
    case Dem_DTCReadoutBuffer_SnapshotSource_Tmc_Normal:
      Dem_DTCReadoutBuffer_SetSnapshotRecordSource(ReadoutBufferId, Dem_DTCReadoutBuffer_SnapshotSource_Invalid);
      lReturnValue = E_OK;
      break;
    default:
      /* Dem_DTCReadoutBuffer_SnapshotSource_Invalid */
      lReturnValue = DEM_NO_SUCH_ELEMENT;
      break;
    }
  }
  else
  {
    Dem_DTCReadoutBuffer_SetSnapshotRecordSource(ReadoutBufferId, Dem_DTCReadoutBuffer_SnapshotSource_Invalid);
    lReturnValue = DEM_NO_SUCH_ELEMENT;
  }

  Dem_Dcm_SnapshotDataRecord_SnapshotIteratorInit(ReadoutBufferId);

  return lReturnValue;
}
#endif

#if ( (DEM_CFG_SUPPORT_DCM == STD_ON) \
   && ( ((DEM_CFG_SUPPORT_OBDII == STD_ON) && (DEM_CFG_SUPPORT_OBDII_FREEZEFRAME_IN_SVC19 == STD_ON)) \
     || (DEM_CFG_SUPPORT_WWHOBD == STD_ON) ) )
/* ****************************************************************************
 % Dem_Dcm_SnapshotDataRecord_ReadNext_Obd
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
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_SnapshotDataRecord_ReadNext_Obd(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId,
  CONSTP2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)  DestBuffer,
  CONSTP2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  BufSize
)
{
  Dem_Cfg_ComplexIterType lSourceIterator;
  uint8 lRecordNumber;
  Std_ReturnType lReturnValue;

  lSourceIterator = Dem_DTCReadoutBuffer_GetSnapshotSourceIterator(ReadoutBufferId);
  lRecordNumber = Dem_DTCReadoutBuffer_GetSnapshotRecordNumber(ReadoutBufferId);

  if (Dem_Cfg_ComplexIterExists(&lSourceIterator) == FALSE)
  {
    lReturnValue = DEM_NO_SUCH_ELEMENT;
  }
  else
  {
    if (Dem_Dcm_SnapshotDataRecord_TestRecordMatch(lRecordNumber, 0x00) == TRUE)
    {
# if (DEM_CFG_SUPPORT_OBDII == STD_ON) && (DEM_CFG_SUPPORT_OBDII_FREEZEFRAME_IN_SVC19 == STD_ON)                                /* COV_MSR_UNSUPPORTED XF xf xf */
      if (Dem_DTCReadoutBuffer_GetMemoryId(ReadoutBufferId) == DEM_CFG_MEMORYID_PRIMARY)
      {
        Dem_EventIdType lEventId;
        lEventId = Dem_DTCReadoutBuffer_GetEventId(ReadoutBufferId);
        lReturnValue = Dem_Dcm_CopyFreezeFrameObdII(lEventId, DestBuffer, BufSize);                                              /* SBSW_DEM_POINTER_FORWARD_API */
      }
      else
# endif
# if (DEM_CFG_SUPPORT_WWHOBD == STD_ON)                                                                                         /* COV_MSR_UNSUPPORTED XF */
      if (Dem_DTCReadoutBuffer_GetMemoryId(ReadoutBufferId) == DEM_CFG_MEMORYID_PRIMARY)
      {
        lReturnValue = Dem_Dcm_CopyFreezeFrameWwhObd(ReadoutBufferId, DestBuffer, BufSize);                                      /* SBSW_DEM_POINTER_FORWARD_API */
      }
      else
# endif
      {
        lReturnValue = DEM_NO_SUCH_ELEMENT;
      }
    }
    else
    {
      lReturnValue = DEM_NO_SUCH_ELEMENT;
    }

    Dem_Cfg_ComplexIterNext(&lSourceIterator);
  }

  Dem_DTCReadoutBuffer_SetSnapshotSourceIterator(ReadoutBufferId, lSourceIterator);

  return lReturnValue;
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */
#endif

# if ((DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_SRECS == STD_ON) \
      && (DEM_FEATURE_NEED_OEM_EXTENSIONS_VCC == STD_ON) \
      && (DEM_CFG_SUPPORT_MULTI_SAMPLE_SNAPSHOT == STD_ON))
/* ****************************************************************************
 % Dem_Dcm_SnapshotDataRecord_ReadNext_Vcc
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
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_SnapshotDataRecord_ReadNext_Vcc(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId,
  CONSTP2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)  DestBuffer,                                                                       /* PRQA S 3673 */ /* MD_DEM_16.7_False */
  CONSTP2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  BufSize                                                                          /* PRQA S 3673 */ /* MD_DEM_16.7_False */
  )
{
  Std_ReturnType lReturnValue;
  Dem_Cfg_ComplexIterType lSourceIterator;
  uint8 lRecordNumber;

  lSourceIterator = Dem_DTCReadoutBuffer_GetSnapshotSourceIterator(ReadoutBufferId);

  lRecordNumber = Dem_DTCReadoutBuffer_GetSnapshotRecordNumber(ReadoutBufferId);

  if (Dem_Cfg_ComplexIterExists(&lSourceIterator) == FALSE)
  {
    lReturnValue = DEM_NO_SUCH_ELEMENT;
  }
  else
  {
    if (Dem_Dcm_SnapshotDataRecord_TestRecordMatch(lRecordNumber, DEM_DCM_SNAPSHOTDATARECORD_VCC) == TRUE)
    {
      Dem_EventIdType lEventId;
      uint16 lDataSize;

      lEventId = Dem_DTCReadoutBuffer_GetEventId(ReadoutBufferId);

      if (DidMuSa_GetDataSize(lEventId, &lDataSize) =! E_OK)                                                                     /* SBSW_DEM_POINTER_FORWARD_STACK */
      {
        lReturnValue = E_NOT_OK;
      }
      else if ((lDataSize + 1) > *BufSize)                                                                                       /* SBSW_DEM_POINTER_WRITE_API */
      {
        lReturnValue = DEM_BUFFER_TOO_SMALL;
      }
      else if (lDataSize == 0)
      {
        *BufSize = 0;                                                                                                            /* SBSW_DEM_POINTER_WRITE_API */
        lReturnValue = E_OK;
      }
      else
      {
        DestBuffer[0] = lRecordNumber;                                                                                           /* SBSW_DEM_POINTER_WRITE_API */
        DidMuSa_GetData(lEventId, &DestBuffer[1], &lDataSize);                                                                   /* SBSW_DEM_POINTER_FORWARD_API */
        *BufSize = (uint16)(lDataSize + 1); /* Add size of record id to data set size */                                         /* SBSW_DEM_POINTER_WRITE_API */
        lReturnValue = E_OK;
      }

      Dem_Cfg_ComplexIterNext(&lSourceIterator);
    }
  }

  Dem_DTCReadoutBuffer_SetSnapshotSourceIterator(ReadoutBufferId, lSourceIterator);
  return lReturnValue;
}
#endif

#if ((DEM_CFG_SUPPORT_DCM == STD_ON) \
   && (DEM_FEATURE_NEED_OEM_EXTENSIONS_TMC == STD_ON) \
   && (DEM_FEATURE_NEED_TIME_SERIES == STD_ON))
/* ****************************************************************************
 % Dem_Dcm_SnapshotDataRecord_ReadNext_Tmc
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
Dem_Dcm_SnapshotDataRecord_ReadNext_Tmc(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId,
  CONSTP2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)  DestBuffer,
  CONSTP2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  BufSize
  )
{
  Dem_Cfg_ComplexIterType lSourceIterator;
  Std_ReturnType lReturnValue;

  lReturnValue = DEM_NO_SUCH_ELEMENT;
  lSourceIterator = Dem_DTCReadoutBuffer_GetSnapshotSourceIterator(ReadoutBufferId);

  while (Dem_Cfg_ComplexIterExists(&lSourceIterator) == TRUE)
  {
    uint8 lRecordNumber;
    uint8 lRecordNumberFilter;
    Dem_EventIdType lEventId;

    lRecordNumber = (uint8)Dem_Cfg_ComplexIterGet(&lSourceIterator);
    lRecordNumberFilter = Dem_DTCReadoutBuffer_GetSnapshotRecordNumber(ReadoutBufferId);
    lEventId = Dem_DTCReadoutBuffer_GetEventId(ReadoutBufferId);

    if (Dem_Dcm_SnapshotDataRecord_TestRecordMatch(lRecordNumberFilter, lRecordNumber) == TRUE)
    {
      if (Dem_Cfg_EventSRecUdsSize(lEventId) > *BufSize)
      {
        lReturnValue = DEM_BUFFER_TOO_SMALL;
      }
      else
      {
        lReturnValue = E_OK;
        if (Dem_Data_TimeSeriesSRecIsStored(&Dem_Cfg_TimeSeriesReadoutBuffer, lRecordNumber) == TRUE)                            /* SBSW_DEM_POINTER_FORWARD_GLOBAL */
        {
          Dem_ConstSharedDataPtrType lpSourceBuffer;

# if (DEM_FEATURE_NEED_TIME_SERIES_FAST == STD_ON)
          if ( (lRecordNumber >= DEM_DCM_SNAPSHOTDATARECORD_TMC_FAST_FIRST)
             && (lRecordNumber <= DEM_DCM_SNAPSHOTDATARECORD_TMC_FAST_LAST) )
          {
            lpSourceBuffer = 
              Dem_Mem_TimeSeriesEntryGetFastConstDataPtr(&Dem_Cfg_TimeSeriesReadoutBuffer, 
                                                         lRecordNumber - DEM_DCM_SNAPSHOTDATARECORD_TMC_FAST_FIRST);             /* SBSW_DEM_POINTER_FORWARD_GLOBAL */
          }
          else
# endif
          {
            lpSourceBuffer = 
              Dem_Mem_TimeSeriesEntryGetNormalConstDataPtr(&Dem_Cfg_TimeSeriesReadoutBuffer, 
                                                           lRecordNumber - DEM_DCM_SNAPSHOTDATARECORD_TMC_NORMAL_FIRST);         /* PRQA S 3382 */ /* MD_DEM_3382 */ /* SBSW_DEM_POINTER_FORWARD_GLOBAL */
          }

          DestBuffer[0] = lRecordNumber;                                                                                         /* SBSW_DEM_POINTER_WRITE_ARGUMENT_BUFFER */
          Dem_DataReportIF_SRecCopyData(&DestBuffer[1],                                                                          /* SBSW_DEM_POINTER_WRITE_ARGUMENT_BUFFER */
            lpSourceBuffer,
            (Dem_Cfg_EventSRecUdsSize(lEventId) - 1),
            lEventId,
            Dem_DTCReadoutBuffer_GetMemoryEntryId(ReadoutBufferId));
          *BufSize = Dem_Cfg_EventSRecUdsSize(lEventId);                                                                         /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
        }
        else
        {
          *BufSize = 0;                                                                                                          /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
        }
      }
      Dem_Cfg_ComplexIterNext(&lSourceIterator);
      break;
    }

    Dem_Cfg_ComplexIterNext(&lSourceIterator);
  }

  Dem_DTCReadoutBuffer_SetSnapshotSourceIterator(ReadoutBufferId, lSourceIterator);

  return lReturnValue;
}                                                                                                                                /* PRQA S 6050, 6080 */ /* MD_MSR_STCAL, MD_MSR_STMIF */
#endif

#if ((DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_SRECS == STD_ON))
/* ****************************************************************************
 % Dem_Dcm_SnapshotDataRecord_ReadNext_SRec
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
Dem_Dcm_SnapshotDataRecord_ReadNext_SRec(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId,
  CONSTP2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)  DestBuffer,
  CONSTP2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  BufSize
  )
{
  Std_ReturnType lReturnValue;
  Dem_SnapshotEntry_IterType lSnapshotEntryIter;
  Dem_Cfg_SRecIndexType lSRecIndex;

  lReturnValue = DEM_NO_SUCH_ELEMENT;
  lSnapshotEntryIter = Dem_DTCReadoutBuffer_GetSnapshotEntryIterator(ReadoutBufferId);
  
  while (Dem_SnapshotEntry_IteratorExists(&lSnapshotEntryIter) == TRUE)
  {
    uint8 lRecordNumber;

    lSRecIndex = Dem_SnapshotEntry_IteratorGetSnapshotRecordIndex(&lSnapshotEntryIter);
    lRecordNumber = Dem_DTCReadoutBuffer_GetSnapshotRecordNumber(ReadoutBufferId);
    
# if (DEM_CFG_SUPPORT_SRECS_CALCULATED == STD_ON)
    if (lRecordNumber < Dem_Cfg_SRecId(lSRecIndex))
    {
      /* overshoot -> snapshot not supported */
      lReturnValue = DEM_NO_SUCH_ELEMENT;
      break;                                                                                                                     /* PRQA S 0771 */ /* MD_DEM_14.6_opt */
    }
    else
# endif
    if (Dem_Dcm_SnapshotDataRecord_TestRecordMatch(lRecordNumber, Dem_Cfg_SRecId(lSRecIndex)) == TRUE)
    {
      if (*BufSize < Dem_Cfg_EventSRecUdsSize(Dem_DTCReadoutBuffer_GetEventId(ReadoutBufferId)))
      { 
        /* supported record, but the buffer is not large enough for all the data */
        lReturnValue = DEM_BUFFER_TOO_SMALL;
      }
      else
      {
        if (Dem_SnapshotEntry_IteratorIsSnapshotRecordStored(&lSnapshotEntryIter) == TRUE)
        {
          DestBuffer[0] = Dem_Cfg_SRecId(lSRecIndex);                                                                            /* SBSW_DEM_POINTER_WRITE_ARGUMENT_BUFFER */
          Dem_DataReportIF_SRecCopyData(
            &DestBuffer[1],                                                                                                      /* SBSW_DEM_POINTER_WRITE_ARGUMENT_BUFFER */
            Dem_SnapshotEntry_IteratorGetSnapshotRecordDataConstPtr(&lSnapshotEntryIter),
            Dem_Cfg_EventSRecUdsSize(Dem_DTCReadoutBuffer_GetEventId(ReadoutBufferId)) - 1,
            Dem_DTCReadoutBuffer_GetEventId(ReadoutBufferId),
            Dem_DTCReadoutBuffer_GetMemoryEntryId(ReadoutBufferId));

          *BufSize = Dem_Cfg_EventSRecUdsSize(Dem_DTCReadoutBuffer_GetEventId(ReadoutBufferId));                                 /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
        }
        else
        {
          *BufSize = 0;                                                                                                          /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
        }

        lReturnValue = E_OK;
      }

      Dem_SnapshotEntry_IteratorNext(&lSnapshotEntryIter);
      break;                                                                                                                     /* PRQA S 0771 */ /* MD_DEM_14.6_opt */
    }
    else
    {
      /* otherwise next snapshot record */
    }

    Dem_SnapshotEntry_IteratorNext(&lSnapshotEntryIter);
  }

  Dem_DTCReadoutBuffer_SetSnapshotEntryIterator(ReadoutBufferId, lSnapshotEntryIter);

  return lReturnValue;
}                                                                                                                                /* PRQA S 6050, 6080 */ /* MD_MSR_STCAL, MD_MSR_STMIF */
#endif /* (DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_SRECS == STD_ON) */

#if (DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_FEATURE_NEED_TIME_SERIES == STD_ON)
/* ****************************************************************************
% Dem_Dcm_GetSizeOfTimeSeriesSRec
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
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_GetSizeOfTimeSeriesSRec(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(uint8, AUTOMATIC)  RecordNumber,
  CONSTP2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  SizeOfFreezeFrame
  )
{
  Std_ReturnType lReturnValue;

  if (Dem_Data_TimeSeriesSRecIsValid(EventId, RecordNumber) == TRUE)
  {
    lReturnValue = E_OK;
    if (Dem_Data_TimeSeriesSRecIsStored(&Dem_Cfg_TimeSeriesReadoutBuffer, RecordNumber) == TRUE)                                 /* SBSW_DEM_POINTER_FORWARD_GLOBAL */
    {
      *SizeOfFreezeFrame = Dem_Cfg_EventSRecUdsSize(EventId);                                                                    /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    }
    else
    {
      *SizeOfFreezeFrame = 0;                                                                                                    /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    }
  }
  else
  {
    lReturnValue = DEM_NO_SUCH_ELEMENT;
  }

  return lReturnValue;
}
#endif

#if ( (DEM_CFG_SUPPORT_DCM == STD_ON) \
   && ( (DEM_CFG_SUPPORT_SRECS == STD_ON) \
     || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON) \
     || (DEM_CFG_SUPPORT_OBDII == STD_ON) \
     || (DEM_CFG_SUPPORT_WWHOBD == STD_ON) ) )                                                                                   /* COV_MSR_UNSUPPORTED TF tf tf xf xf */
/* ****************************************************************************
 % Dem_Dcm_SnapshotDataRecord_GetSize
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
Dem_Dcm_SnapshotDataRecord_GetSize(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId,
  CONST(uint8, AUTOMATIC)  RecordNumber,
  CONSTP2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  SizeOfFreezeFrame                                                                /* PRQA S 3206, 3673 */ /* MD_DEM_3206, MD_DEM_16.7_False */
  )
{
  Std_ReturnType lReturnValue;

  if (RecordNumber == DEM_DCM_SNAPSHOTDATARECORD_ALL)
  { 
    /* No data is a positive result for 0xff */
# if (DEM_CFG_SUPPORT_SRECS == STD_ON)                                                                                           /* COV_MSR_UNSUPPORTED TX */
    lReturnValue = E_OK;
    
    *SizeOfFreezeFrame =                                                                                                         /* SBSW_DEM_POINTER_WRITE_ARGUMENT */ /* SBSW_DEM_POINTER_FORWARD_GLOBAL */
      (uint16)(Dem_SnapshotEntry_GetNumberOfStoredSnapshotRecords(Dem_DTCReadoutBuffer_GetMemoryEntryId(ReadoutBufferId))
                                         * Dem_Cfg_EventSRecUdsSize(Dem_DTCReadoutBuffer_GetEventId(ReadoutBufferId)));          
# else
    lReturnValue = DEM_NO_SUCH_ELEMENT;
    /* SizeOfFreezeFrame intentionally not modified due to invalid request */
# endif
# if (DEM_FEATURE_NEED_TIME_SERIES == STD_ON)
    {
      uint16 lSizeOfFreezeFrame;
      lSizeOfFreezeFrame = (uint16)(Dem_Data_TimeSeriesSRecCount(&Dem_Cfg_TimeSeriesReadoutBuffer) 
                                        * Dem_Cfg_EventSRecUdsSize(Dem_DTCReadoutBuffer_GetEventId(ReadoutBufferId)));           /* SBSW_DEM_POINTER_FORWARD_GLOBAL */
#  if (DEM_CFG_SUPPORT_SRECS == STD_ON)
      /* lReturnValue = E_OK already set */
      *SizeOfFreezeFrame = (uint16)(*SizeOfFreezeFrame + lSizeOfFreezeFrame);                                                    /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
#  else
      lReturnValue = E_OK;
      *SizeOfFreezeFrame = lSizeOfFreezeFrame;                                                                                   /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
#  endif
    }
# endif
    /* Add the size of the OBD freeze frame */
# if (DEM_CFG_SUPPORT_OBDII == STD_ON) && (DEM_CFG_SUPPORT_OBDII_FREEZEFRAME_IN_SVC19 == STD_ON)                                 /* COV_MSR_UNSUPPORTED XF xf xf */
    {
      Dem_EventIdType lEventId;
      uint16 lSizeOfFreezeFrame;

      lEventId = Dem_DTCReadoutBuffer_GetEventId(ReadoutBufferId);

      if (Dem_Dcm_GetSizeOfFreezeFrameObdII(lEventId, &lSizeOfFreezeFrame) == E_OK)
      {
#  if (DEM_CFG_SUPPORT_SRECS == STD_ON) || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON)
        /* lReturnValue = E_OK already set */
        *SizeOfFreezeFrame = (uint16)(*SizeOfFreezeFrame + lSizeOfFreezeFrame);                                                  /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
#  else
        lReturnValue = E_OK;
        *SizeOfFreezeFrame = lSizeOfFreezeFrame;                                                                                 /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
#  endif
      }
    }
# endif /* (DEM_CFG_SUPPORT_OBDII == STD_ON) */
# if (DEM_CFG_SUPPORT_WWHOBD == STD_ON)                                                                                          /* COV_MSR_UNSUPPORTED XF */
    {
      Dem_EventIdType lEventId;
      uint16 lSizeOfFreezeFrame;

      lEventId = Dem_DTCReadoutBuffer_GetEventId(ReadoutBufferId);

      if (Dem_Dcm_GetSizeOfFreezeFrameWwhObd(lEventId, &lSizeOfFreezeFrame) == E_OK)
      {
#  if (DEM_CFG_SUPPORT_SRECS == STD_ON) || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON)
        /* lReturnValue = E_OK already set */
        *SizeOfFreezeFrame = (uint16)(*SizeOfFreezeFrame + lSizeOfFreezeFrame);                                                  /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
#  else
        lReturnValue = E_OK;
        *SizeOfFreezeFrame = lSizeOfFreezeFrame;                                                                                 /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
#  endif
      }
    }
# endif /* DEM_CFG_SUPPORT_WWHOBD == STD_ON */

    /* Add the size of the multi sample snapshot */
# if (DEM_CFG_SUPPORT_MULTI_SAMPLE_SNAPSHOT == STD_ON)                                                                           /* COV_MSR_UNSUPPORTED XF */
    {
      uint16 lDataSize;
      if ( (DidMuSa_GetDataSize(EventId, &lDataSize) == E_OK)
        && (0 != lDataSize) )
      {
        *SizeOfFreezeFrame = (uint16)((*SizeOfFreezeFrame + lDataSize) + 1);                                                     /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
        /* lReturnValue = E_OK initially set */
      }
    }
# endif
  }
  else
# if (DEM_CFG_SUPPORT_SRECS == STD_ON)
  { 
    /* Specific record not found is a negative result */
    Dem_SnapshotEntry_IterType lSnapshotEntryIter;
    Dem_EventIdType lEventId;

    lReturnValue = E_OK;
    lEventId = Dem_DTCReadoutBuffer_GetEventId(ReadoutBufferId);

    for (Dem_SnapshotEntry_IteratorInit(lEventId, Dem_DTCReadoutBuffer_GetMemoryEntryId(ReadoutBufferId), &lSnapshotEntryIter);
         Dem_SnapshotEntry_IteratorExists(&lSnapshotEntryIter) == TRUE;
         Dem_SnapshotEntry_IteratorNext(&lSnapshotEntryIter))
    {
      Dem_Cfg_SRecIndexType lCfgSRecIndex;
      lCfgSRecIndex = Dem_SnapshotEntry_IteratorGetSnapshotRecordIndex(&lSnapshotEntryIter);
      DEM_IGNORE_UNUSED_VARIABLE(lCfgSRecIndex)                                                                                  /* PRQA S 3112 */ /* MD_DEM_14.2 */

      if (Dem_Cfg_SRecId(lCfgSRecIndex) == RecordNumber)
      {
        if (Dem_SnapshotEntry_IteratorIsSnapshotRecordStored(&lSnapshotEntryIter) == TRUE)
        {
          *SizeOfFreezeFrame = Dem_Cfg_EventSRecUdsSize(lEventId);                                                                /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
        }
        else
        {
          *SizeOfFreezeFrame = 0;                                                                                                /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
        }
        break;
      }
    }

    if (Dem_SnapshotEntry_IteratorExists(&lSnapshotEntryIter) == FALSE)
    {
      lReturnValue = DEM_NO_SUCH_ELEMENT;
    }
  }
# else
  {
    DEM_IGNORE_UNUSED_CONST_ARGUMENT(ReadoutBufferId)                                                                            /* PRQA S 3112 */ /* MD_DEM_14.2 */
    DEM_IGNORE_UNUSED_CONST_ARGUMENT(SizeOfFreezeFrame)                                                                          /* PRQA S 3112 */ /* MD_DEM_14.2 */
    lReturnValue = DEM_NO_SUCH_ELEMENT;
  }
# endif
  return lReturnValue;
}                                                                                                                                /* PRQA S 6050, 6080 */ /* MD_MSR_STCAL, MD_MSR_STMIF */
#endif /* (DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_SRECS == STD_ON) */

#if ( (DEM_CFG_SUPPORT_DCM == STD_ON) \
   && (DEM_CFG_SUPPORT_OBDII == STD_ON) \
   && (DEM_CFG_SUPPORT_OBDII_FREEZEFRAME_IN_SVC19 == STD_ON) )                                                                   /* COV_MSR_UNSUPPORTED XF tf xf xf */
/* ****************************************************************************
 % Dem_Dcm_CopyFreezeFrameObdII
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
Dem_Dcm_CopyFreezeFrameObdII(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONSTP2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)  DestBuffer,
  CONSTP2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  BufSize
  )
{
  Std_ReturnType lReturnValue;

  if (Dem_Cfg_EventObdRelated(EventId) == FALSE)
  {
    lReturnValue = DEM_NO_SUCH_ELEMENT;
  }
  else
  {
    uint8 lSelectedIndex;

    lSelectedIndex = Dem_Mem_FreezeFrameFindIndex(EventId);
    if (lSelectedIndex == Dem_Cfg_GlobalObdIIFFCount())
    { 
      /* FreezeFrame is not stored */
      *BufSize = 0;
      lReturnValue = E_OK;
    }
    else
    { 
      /* Event has a stored OBD freeze frame */
      if (Dem_Cfg_GlobalObdIIFFUdsSize() > *BufSize)
      { 
        /* supported record, but the buffer is not large enough for the data */
        lReturnValue = DEM_BUFFER_TOO_SMALL;
      }
      else
      { 
        /* Read Freeze Frame */
        DestBuffer[0] = 0x00U;
        Dem_DataReportIF_ObdIIFreezeFrameCopyUdsData(lSelectedIndex, &DestBuffer[1], (*BufSize - 1));

        /* check if FreezeFrame EventId is still the same */
        if (Dem_Mem_FreezeFrameGetEvent(lSelectedIndex) == EventId)
        {
          *BufSize = Dem_Cfg_GlobalObdIIFFUdsSize();
        }
        else
        { /* EventId has changed, so the FreezeFrame data also */
          *BufSize = 0;
        }
        lReturnValue = E_OK;
      }
    }
  }

  return lReturnValue;
}
#endif /* (DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_OBDII == STD_ON) */

#if (DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_WWHOBD == STD_ON)                                                        /* COV_MSR_UNSUPPORTED XF tf xf */
/* ****************************************************************************
 % Dem_Dcm_CopyFreezeFrameWwhObd
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
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_CopyFreezeFrameWwhObd(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId,
  CONSTP2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)  DestBuffer,
  CONSTP2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  BufSize
  )
{
  Std_ReturnType lReturnValue;
  Dem_EventIdType lEventId = Dem_DTCReadoutBuffer_GetEventId(ReadoutBufferId);

  if (Dem_Cfg_EventObdRelated(lEventId) == FALSE)
  {
    lReturnValue = DEM_NO_SUCH_ELEMENT;
  }
  else
  {
    if (Dem_Cfg_EventWwhObdFFUdsSize(lEventId) > *BufSize)
    { /* supported record, but the buffer is not large enough for all the data */
      lReturnValue = DEM_BUFFER_TOO_SMALL;
    }
    else
    {
      Dem_Mem_MemoryInfoPtrType lMemoryInfo;
      Dem_Cfg_MemoryIndexType lMemoryIndex;

      lMemoryInfo = Dem_MemStorageManager_MemoryInfoInit(Dem_Cfg_EventDestination(lEventId));
      lMemoryIndex = Dem_MemStorageManager_MemoryFindIndex(lMemoryInfo, lEventId);                                                              /* SBSW_DEM_CALL_MEMORYINFO_POINTER */
      lReturnValue = E_OK;

      if (lMemoryIndex != DEM_MEM_INVALID_MEMORY_INDEX)
      { /* process request if Freeze Frame is stored */
# if (DEM_FEATURE_NEED_AGING_REALLOCATION == STD_ON)
        if (DEM_MEM_TEST_AGING_ONLY(Dem_MemoryEntry_GetState(Dem_MemStorageManager_GetMemoryEntryId(lMemoryIndex))) == TRUE)
        { /* Not stored, no data available */
          *BufSize = 0;
        }
        else
# endif
        {
          DestBuffer[0] = 0x00;
          Dem_DataReportIF_WWHOBDFreezeFrameCopyData(&DestBuffer[1],
            (Dem_ConstSharedDataPtrType) Dem_MemoryEntry_GetWwhObdFreezeFrameDataPtr(Dem_DTCReadoutBuffer_GetMemoryEntryId(ReadoutBufferId)),
            Dem_Cfg_EventWwhObdFFUdsSize(lEventId),
            lEventId,
            Dem_DTCReadoutBuffer_GetMemoryEntryId(ReadoutBufferId));
          *BufSize = Dem_Cfg_EventWwhObdFFUdsSize(lEventId);
        }
      }
      else
      { /* Not stored, no data available */
        *BufSize = 0;
      }
    }
  }

  return lReturnValue;
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */
#endif /* (DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_WWHOBD == STD_ON) */

#if ( (DEM_CFG_SUPPORT_DCM == STD_ON) \
   && (DEM_CFG_SUPPORT_OBDII == STD_ON) \
   && (DEM_CFG_SUPPORT_OBDII_FREEZEFRAME_IN_SVC19 == STD_ON) )                                                                   /* COV_MSR_UNSUPPORTED XF tf xf xf */
/* ****************************************************************************
 % Dem_Dcm_GetSizeOfFreezeFrameObdII
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_GetSizeOfFreezeFrameObdII(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONSTP2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  SizeOfFreezeFrame
  )
{
  Std_ReturnType lReturnValue;

  if (Dem_Cfg_EventObdRelated(EventId) == FALSE)
  {
    lReturnValue = DEM_NO_SUCH_ELEMENT;
  }
  else
  { /* scan the freeze frame memory for the requested DTC */
    uint8 lSelectedIndex;
    lSelectedIndex = Dem_Mem_FreezeFrameFindIndex(EventId);

    /* Check if FreezeFrame is available */
    if (lSelectedIndex != Dem_Cfg_GlobalObdIIFFCount())
    {
      *SizeOfFreezeFrame = Dem_Cfg_GlobalObdIIFFUdsSize();
    }
    else
    { /* FreezeFrame is not stored */
      *SizeOfFreezeFrame = 0;
    }
    lReturnValue = E_OK;
  }

  return lReturnValue;
}
#endif /* (DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_OBDII == STD_ON) 
           && (DEM_CFG_SUPPORT_OBDII_FREEZEFRAME_IN_SVC19 == STD_ON) */

#if (DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_WWHOBD == STD_ON)                                                        /* COV_MSR_UNSUPPORTED XF tf xf */
/* ****************************************************************************
 % Dem_Dcm_GetSizeOfFreezeFrameOWwhbd
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
Dem_Dcm_GetSizeOfFreezeFrameWwhObd(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONSTP2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  SizeOfFreezeFrame
  )
{
  Std_ReturnType lReturnValue;

  if (Dem_Cfg_EventObdRelated(EventId) == FALSE)
  {
    lReturnValue = DEM_NO_SUCH_ELEMENT;
  }
  else
  {
    Dem_Mem_MemoryInfoPtrType lMemoryInfo;
    Dem_Cfg_MemoryIndexType lMemoryIndex;

    lReturnValue = E_OK;
    lMemoryInfo = Dem_MemStorageManager_MemoryInfoInit(Dem_Cfg_EventDestination(EventId));
    lMemoryIndex = Dem_MemStorageManager_MemoryFindIndex(lMemoryInfo, EventId);                                                                /* SBSW_DEM_CALL_MEMORYINFO_POINTER */

    if (lMemoryIndex != DEM_MEM_INVALID_MEMORY_INDEX)
    { /* process request if Freeze Frame is stored */
# if (DEM_FEATURE_NEED_AGING_REALLOCATION == STD_ON)
      if (DEM_MEM_TEST_AGING_ONLY(Dem_MemoryEntry_GetState(Dem_MemStorageManager_GetMemoryEntryId(lMemoryIndex))) == TRUE)
      {
        *SizeOfFreezeFrame = 0;
      }
      else
# endif
      {
        *SizeOfFreezeFrame = Dem_Cfg_EventWwhObdFFUdsSize(EventId);
      }
    }
    else
    {
      *SizeOfFreezeFrame = 0;
    }
  }

  return lReturnValue;
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_ERECS == STD_ON)
/* ****************************************************************************
 % Dem_Dcm_ExtendedDataRecord_CalcSize
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
DEM_LOCAL_INLINE FUNC(uint16, DEM_CODE)
Dem_Dcm_ExtendedDataRecord_CalcSize(
  CONST(Dem_Cfg_ERecIndexType, AUTOMATIC) CfgERecIndex,
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId,
  CONSTP2CONST(Dem_ExtendedEntry_IterType, AUTOMATIC, AUTOMATIC)  ExtendedEntryIter
  )
{
  uint16 lSizeOfExtRec; 
  uint8 lERecType;
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(ExtendedEntryIter)                                                                            /* PRQA S 3112 */ /* MD_DEM_14.2 */

  lSizeOfExtRec = 0;
  lERecType = Dem_Cfg_ERecType(CfgERecIndex);

  if (lERecType != DEM_CFG_EREC_TYPE_GLOBAL)
  {
    /* Test if event has a memory entry */
    if (Dem_DTCReadoutBuffer_TestStoredDataAvailable(ReadoutBufferId) == TRUE)
    {
# if (DEM_CFG_SUPPORT_USER_ERECS == STD_ON)
      if (  (lERecType == DEM_CFG_EREC_TYPE_INTERNAL)                                                                            /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
        /* Test if requested record is stored for event */
        || (Dem_ExtendedEntry_IteratorIsExtendedRecordStored(ExtendedEntryIter) == TRUE))
# endif
      { 
        if (Dem_Data_ERecAllDataElementsStored(Dem_Cfg_ERecDid(CfgERecIndex), ReadoutBufferId) == TRUE)
        {
          lSizeOfExtRec = (uint16)(Dem_Cfg_DidSize(Dem_Cfg_ERecDid(CfgERecIndex)) + 1);
        } /* else lSizeOfExtRec is already set to 0 */
      } /* else lSizeOfExtRec is already set to 0 */
    } /* else lSizeOfExtRec is already set to 0 */
  }
  else
  { /* Currently statistic data is always available, add record id to data size */
    lSizeOfExtRec = (uint16)(Dem_Cfg_DidSize(Dem_Cfg_ERecDid(CfgERecIndex)) + 1);
  }

  return lSizeOfExtRec;
}
#endif /* (DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_ERECS == STD_ON) */

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
 * \addtogroup Dem_Dcm_Public
 * \{
 */

/* ****************************************************************************
 % Dem_Dcm_Init
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
Dem_Dcm_Init(
  void
  )
{
#if (DEM_CFG_SUPPORT_DCM == STD_ON)
# if (DEM_FEATURE_NEED_OBD == STD_ON) && (DEM_CFG_SUPPORT_OBD_HIDE_OCCURRENCES == STD_ON)                                        /* COV_MSR_UNSUPPORTED XF xf xf */
  Dem_DTCReporting_SetObdHideOccurrences();
# endif
#endif
#if ( ((DEM_CFG_SUPPORT_J1939_READ_DTC == STD_ON) || (DEM_CFG_SUPPORT_J1939_DM31 == STD_ON)) \
   && (DEM_FEATURE_NEED_J1939_FREEZEFRAME == STD_ON) )                                                                           /* COV_MSR_UNSUPPORTED XF xf xf xf */
  Dem_J1939Dcm_FilterDataSetKind(DEM_J1939_FILTER_FREEZEFRAME_INVALID);
#endif
#if (DEM_FEATURE_NEED_IUMPR == STD_ON)
  Dem_Dcm_IumprFilterInfo.FirstEvent = DEM_EVENT_INVALID;
#endif
}

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_Dcm_SnapshotDataRecord_SnapshotSelect
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
DEM_LOCAL_INLINE FUNC(void, DEM_CODE) Dem_Dcm_SnapshotDataRecord_SnapshotSelect(
  CONST(uint8, AUTOMATIC) ClientId,
  CONST(uint8, AUTOMATIC)  RecordNumber
  )
{
  Dem_DTCReadoutBuffer_HandleType lReadoutBufferId;
  Dem_DTCReadoutBuffer_SnapshotSourceType lSource;

  lReadoutBufferId = Dem_ClientAccess_GetReadoutBuffer(ClientId);

  Dem_DTCReadoutBuffer_SelectSnapshotRecord(lReadoutBufferId, RecordNumber);
  
  if ( (RecordNumber == DEM_DCM_SNAPSHOTDATARECORD_OBD)
    || (RecordNumber == DEM_DCM_SNAPSHOTDATARECORD_ALL) )
  {
# if  ((DEM_CFG_SUPPORT_OBDII == STD_ON) && (DEM_CFG_SUPPORT_OBDII_FREEZEFRAME_IN_SVC19 == STD_ON)) \
    || (DEM_CFG_SUPPORT_WWHOBD == STD_ON) 
    lSource = Dem_DTCReadoutBuffer_SnapshotSource_Obd;
# else
    if (RecordNumber == DEM_DCM_SNAPSHOTDATARECORD_ALL)
    {
      lSource = Dem_DTCReadoutBuffer_SnapshotSource_Srec;
    }
    else
    {
      lSource = Dem_DTCReadoutBuffer_SnapshotSource_Invalid;
    }
# endif
  }
  else
# if (DEM_FEATURE_NEED_OEM_EXTENSIONS_VCC == STD_ON) && (DEM_CFG_SUPPORT_MULTI_SAMPLE_SNAPSHOT == STD_ON)                        /* COV_MSR_UNSUPPORTED XF */
  if (RecordNumber == DEM_DCM_SNAPSHOTDATARECORD_VCC)
  {
    lSource = Dem_DTCReadoutBuffer_SnapshotSource_Vcc;
  }
  else
# endif
# if (DEM_FEATURE_NEED_OEM_EXTENSIONS_TMC == STD_ON) && (DEM_FEATURE_NEED_TIME_SERIES == STD_ON)
#  if (DEM_FEATURE_NEED_TIME_SERIES_FAST == STD_ON)
  if ((RecordNumber >= DEM_DCM_SNAPSHOTDATARECORD_TMC_FAST_FIRST) && (RecordNumber <= 0x2F))
  {
    lSource = Dem_DTCReadoutBuffer_SnapshotSource_Tmc_Fast;
  }
  else
#  endif
  if ((RecordNumber >= DEM_DCM_SNAPSHOTDATARECORD_TMC_NORMAL_FIRST) 
    && (RecordNumber <= DEM_DCM_SNAPSHOTDATARECORD_TMC_NORMAL_LAST))
  {
    lSource = Dem_DTCReadoutBuffer_SnapshotSource_Tmc_Normal;
  }
  else
# endif
  {
# if (DEM_CFG_SUPPORT_SRECS == STD_ON)                                                                                           /* COV_MSR_UNSUPPORTED TX */
    lSource = Dem_DTCReadoutBuffer_SnapshotSource_Srec;
# else
    lSource = Dem_DTCReadoutBuffer_SnapshotSource_Invalid;
# endif
  }

  Dem_DTCReadoutBuffer_SetSnapshotRecordSource(lReadoutBufferId, lSource);

  Dem_Dcm_SnapshotDataRecord_SnapshotIteratorInit(lReadoutBufferId);
}
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_Dcm_ExtendedDataRecord_RecordSelect
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE) 
Dem_Dcm_ExtendedDataRecord_RecordSelect(
  CONST(uint8, AUTOMATIC) ClientId,
  CONST(uint8, AUTOMATIC)  RecordNumber
  )
{
  Dem_DTCReadoutBuffer_HandleType lReadoutBufferId;

  lReadoutBufferId = Dem_ClientAccess_GetReadoutBuffer(ClientId);

  Dem_DTCReadoutBuffer_SelectExtendedDataRecord(lReadoutBufferId, RecordNumber);
}
#endif

# if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_Dcm_SnapshotDataRecord_ReadNext
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
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_SnapshotDataRecord_ReadNext(
  CONST(uint8, AUTOMATIC) ClientId,
  CONSTP2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)  DestBuffer,                                                                       /* PRQA S 3673 */ /* MD_DEM_16.7_False */
  CONSTP2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  BufSize                                                                          /* PRQA S 3673 */ /* MD_DEM_16.7_False */
)
{
  Std_ReturnType lReturnValue;
  boolean lContinue;
  Dem_DTCReadoutBuffer_HandleType lReadoutBufferId;

  DEM_IGNORE_UNUSED_CONST_ARGUMENT(DestBuffer)                                                                                   /* PRQA S 3112 */ /* MD_DEM_14.2 */
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(BufSize)                                                                                      /* PRQA S 3112 */ /* MD_DEM_14.2 */

  lReturnValue = DEM_NO_SUCH_ELEMENT;
  lContinue = TRUE;
  lReadoutBufferId = Dem_ClientAccess_GetReadoutBuffer(ClientId);

  while(lContinue == TRUE)
  {
    Std_ReturnType lReadNextReturnValue;
    lReadNextReturnValue = DEM_NO_SUCH_ELEMENT;

    switch (Dem_DTCReadoutBuffer_GetSnapshotRecordSource(lReadoutBufferId))
    {
    case Dem_DTCReadoutBuffer_SnapshotSource_Obd:
# if ( ((DEM_CFG_SUPPORT_OBDII == STD_ON) && (DEM_CFG_SUPPORT_OBDII_FREEZEFRAME_IN_SVC19 == STD_ON)) \
     || (DEM_CFG_SUPPORT_WWHOBD == STD_ON) )
      lReadNextReturnValue = Dem_Dcm_SnapshotDataRecord_ReadNext_Obd(lReadoutBufferId, DestBuffer, BufSize);
# endif
      break;
    case Dem_DTCReadoutBuffer_SnapshotSource_Srec:
# if ((DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_SRECS == STD_ON))
      lReadNextReturnValue = Dem_Dcm_SnapshotDataRecord_ReadNext_SRec(lReadoutBufferId, DestBuffer, BufSize);
# endif
      break;
    case Dem_DTCReadoutBuffer_SnapshotSource_Vcc:
# if ((DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_SRECS == STD_ON) \
      && (DEM_FEATURE_NEED_OEM_EXTENSIONS_VCC == STD_ON) \
      && (DEM_CFG_SUPPORT_MULTI_SAMPLE_SNAPSHOT == STD_ON))
      lReadNextReturnValue = Dem_Dcm_SnapshotDataRecord_ReadNext_Vcc(lReadoutBufferId, DestBuffer, BufSize);
#endif
      break;
    case Dem_DTCReadoutBuffer_SnapshotSource_Tmc_Normal:
    case Dem_DTCReadoutBuffer_SnapshotSource_Tmc_Fast:
# if ((DEM_CFG_SUPPORT_DCM == STD_ON) \
      && (DEM_FEATURE_NEED_OEM_EXTENSIONS_TMC == STD_ON) \
      && (DEM_FEATURE_NEED_TIME_SERIES == STD_ON))
      lReadNextReturnValue = Dem_Dcm_SnapshotDataRecord_ReadNext_Tmc(lReadoutBufferId, DestBuffer, BufSize);
# endif
      break;
    default:
      /* Dem_DTCReadoutBuffer_SnapshotSource_Invalid */
      break;
    }

    if (lReadNextReturnValue == DEM_NO_SUCH_ELEMENT)                                                                             /* PRQA S 3355, 3358 */ /* MD_DEM_13.7, MD_DEM_13.7 */
    {
      Std_ReturnType lSelectNextReturnValue;

      lSelectNextReturnValue = Dem_Dcm_SnapshotDataRecord_SourceSelectNext(lReadoutBufferId);

      if (lSelectNextReturnValue == DEM_NO_SUCH_ELEMENT)
      {
        lReturnValue = lSelectNextReturnValue;
        lContinue = FALSE;
      }
    }
    else
    {                                                                                                                            /* PRQA S 3201 */ /* MD_DEM_COMSTACKLIB */
      lReturnValue = lReadNextReturnValue;
      lContinue = FALSE;
    }
  }

  return lReturnValue;
}                                                                                                                                /* PRQA S 6050, 6080 */ /* MD_MSR_STCAL, MD_MSR_STMIF */
#endif /* (DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_SRECS == STD_ON) */

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_Dcm_GetSizeOfFreezeFrameSelection
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
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_GetSizeOfFreezeFrameSelection(
  CONST(uint8, AUTOMATIC)  ClientId,
  CONSTP2VAR(uint16, AUTOMATIC, DEM_DCM_DATA)  SizeOfFreezeFrame                                                                 /* PRQA S 3673 */ /* MD_DEM_16.7_False */
  )
{
  Std_ReturnType lReturnValue;
# if ( (DEM_CFG_SUPPORT_SRECS == STD_ON) \
  || (DEM_CFG_SUPPORT_OBDII == STD_ON) \
  || (DEM_CFG_SUPPORT_WWHOBD == STD_ON) \
  || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON))
  Dem_EventIdType lEventId;                                                                                                      /* PRQA S 3203 */ /* MD_DEM_3203 */
  uint8 lMemoryId;                                                                                                               /* PRQA S 3203 */ /* MD_DEM_3203 */
  uint8 lRecordNumber;
  Dem_DTCReadoutBuffer_HandleType lReadoutBufferId;
# endif

  DEM_IGNORE_UNUSED_CONST_ARGUMENT(ClientId)                                                                                     /* PRQA S 3112 */ /* MD_DEM_14.2 */
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(SizeOfFreezeFrame)                                                                            /* PRQA S 3112 */ /* MD_DEM_14.2 */

# if ( (DEM_CFG_SUPPORT_SRECS == STD_ON) \
  || (DEM_CFG_SUPPORT_OBDII == STD_ON) \
  || (DEM_CFG_SUPPORT_WWHOBD == STD_ON) \
  || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON))

  lReadoutBufferId = Dem_ClientAccess_GetReadoutBuffer(ClientId);
  lEventId = Dem_DTCReadoutBuffer_GetEventId(lReadoutBufferId);                                                                  /* PRQA S 3199, 3203 */ /* MD_DEM_3199, MD_DEM_3203 */
  lMemoryId = Dem_DTCReadoutBuffer_GetMemoryId(lReadoutBufferId);                                                                /* PRQA S 3199, 3203 */ /* MD_DEM_3199, MD_DEM_3203 */
  lRecordNumber = Dem_DTCReadoutBuffer_GetSnapshotRecordNumber(lReadoutBufferId);

    if (lRecordNumber == 0x00)
    {
#  if ((DEM_CFG_SUPPORT_OBDII == STD_ON) && (DEM_CFG_SUPPORT_OBDII_FREEZEFRAME_IN_SVC19 == STD_ON))\
  || (DEM_CFG_SUPPORT_WWHOBD == STD_ON)                                                                                          /* COV_MSR_UNSUPPORTED XF xf xf xf */
      if (lMemoryId == DEM_CFG_MEMORYID_PRIMARY)
      {
#   if (DEM_CFG_SUPPORT_OBDII == STD_ON)                                                                                          /* COV_MSR_UNSUPPORTED XF */
        lReturnValue = Dem_Dcm_GetSizeOfFreezeFrameObdII(lEventId, SizeOfFreezeFrame);                                           /* SBSW_DEM_POINTER_FORWARD_API */
#   endif
#   if (DEM_CFG_SUPPORT_WWHOBD == STD_ON)                                                                                         /* COV_MSR_UNSUPPORTED XF */
        lReturnValue = Dem_Dcm_GetSizeOfFreezeFrameWwhObd(lEventId, SizeOfFreezeFrame);                                          /* SBSW_DEM_POINTER_FORWARD_API */
#   endif
      }
      else
#  endif
      {
        lReturnValue = DEM_NO_SUCH_ELEMENT;
      }
    }
    else
#  if (DEM_CFG_SUPPORT_MULTI_SAMPLE_SNAPSHOT == STD_ON)                                                                          /* COV_MSR_UNSUPPORTED XF */
    if (lRecordNumber == DEM_DCM_SNAPSHOTDATARECORD_VCC)
    {
      uint16 lDataSize;
      if (DidMuSa_GetDataSize(lEventId, &lDataSize) != E_OK)
      {
        lReturnValue = DEM_NO_SUCH_ELEMENT;
      }
      else if (lDataSize == 0)
      {
        *SizeOfFreezeFrame = 0;                                                                                                  /* SBSW_DEM_POINTER_WRITE_API */
        lReturnValue = E_OK;
      }
      else
      {
        /* Add size of record id to data set size */
        *SizeOfFreezeFrame = (uint16)(lDataSize + 1);                                                                            /* SBSW_DEM_POINTER_WRITE_API */
        lReturnValue = E_OK;
      }
    }
    else
#  endif

#  if (DEM_FEATURE_NEED_TIME_SERIES == STD_ON)

    if ((lRecordNumber >= DEM_DCM_SNAPSHOTDATARECORD_TMC_FIRST) 
      && (lRecordNumber <= DEM_DCM_SNAPSHOTDATARECORD_TMC_LAST))
    {
      lReturnValue = Dem_Dcm_GetSizeOfTimeSeriesSRec(lEventId, lRecordNumber, SizeOfFreezeFrame);                                /* SBSW_DEM_POINTER_FORWARD_API */
    }
    else
#  endif
    {
      lReturnValue = Dem_Dcm_SnapshotDataRecord_GetSize(lReadoutBufferId, lRecordNumber, SizeOfFreezeFrame);                     /* SBSW_DEM_POINTER_FORWARD_API */
    }
# else

    lReturnValue = DEM_NO_SUCH_ELEMENT;
# endif /* (DEM_CFG_SUPPORT_SRECS == STD_ON) */

  return lReturnValue;
}
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_Dcm_ExtendedDataRecord_ReadNext
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
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_ExtendedDataRecord_ReadNext(
  CONST(uint8, AUTOMATIC)  ClientId,
  CONSTP2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)  DestBuffer,                                                                       /* PRQA S 3673 */ /* MD_DEM_16.7_False */
  CONSTP2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  BufSize                                                                          /* PRQA S 3673 */ /* MD_DEM_16.7_False */
)
{
  Std_ReturnType lReturnValue;

  lReturnValue = DEM_NO_SUCH_ELEMENT;

# if (DEM_CFG_SUPPORT_ERECS == STD_ON)
  {
    Dem_DTCReadoutBuffer_HandleType lReadoutBufferId;
    Dem_ExtendedEntry_IterType lExtendedEntryIter;

    lReadoutBufferId = Dem_ClientAccess_GetReadoutBuffer(ClientId);
    lExtendedEntryIter = Dem_DTCReadoutBuffer_GetExtendedEntryIterator(lReadoutBufferId);

    /* Find next record. */
    while (Dem_ExtendedEntry_IteratorExists(&lExtendedEntryIter) == TRUE)
    {
      Dem_Cfg_ERecIndexType lCfgERecIndex;

      lCfgERecIndex = Dem_ExtendedEntry_IteratorGetExtendedRecordIndex(&lExtendedEntryIter);

      /* If the extended data number matches */
      if (Dem_Dcm_ExtendedDataRecord_IsRecordMatch(Dem_DTCReadoutBuffer_GetExtendedDataNumber(lReadoutBufferId), 
                                                   (uint8)Dem_Cfg_DidNumber(Dem_Cfg_ERecDid(lCfgERecIndex))) == TRUE)
      {
        lReturnValue = Dem_Dcm_ReadExtendedDataRecord(lReadoutBufferId, DestBuffer, BufSize);

        Dem_ExtendedEntry_IteratorNext(&lExtendedEntryIter);
        Dem_DTCReadoutBuffer_SetExtendedEntryIterator(lReadoutBufferId, lExtendedEntryIter);
        break;
      }

      Dem_ExtendedEntry_IteratorNext(&lExtendedEntryIter);
      Dem_DTCReadoutBuffer_SetExtendedEntryIterator(lReadoutBufferId, lExtendedEntryIter);
    }
  }
# else
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(ClientId)                                                                                     /* PRQA S 3112 */ /* MD_DEM_14.2 */
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(DestBuffer)                                                                                   /* PRQA S 3112 */ /* MD_DEM_14.2 */
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(BufSize)                                                                                      /* PRQA S 3112 */ /* MD_DEM_14.2 */
# endif

  return lReturnValue;
}                                                                                                                                /* PRQA S 6050, 6080 */ /* MD_MSR_STCAL, MD_MSR_STMIF */
#endif /* (DEM_CFG_SUPPORT_DCM == STD_ON) */

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_Dcm_ExtendedDataRecord_GetSize
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
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_ExtendedDataRecord_GetSize(
  CONST(uint8, AUTOMATIC)  ClientId,
  CONSTP2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  SizeOfExtendedDataRecord                                                         /* PRQA S 3673 */ /* MD_DEM_16.7_False */
  )
{
  Std_ReturnType lReturnValue;

  /* Find the Record number */
  lReturnValue = DEM_NO_SUCH_ELEMENT;

# if (DEM_CFG_SUPPORT_ERECS == STD_ON)
  {
    uint16 lAccumulatedSize;
    Dem_DTCReadoutBuffer_HandleType lReadoutBufferId;
    uint8 lRecordNumber;
    Dem_ExtendedEntry_IterType lExtendedEntryIter;

    lAccumulatedSize = 0;
    lReadoutBufferId = Dem_ClientAccess_GetReadoutBuffer(ClientId);
    lRecordNumber = Dem_DTCReadoutBuffer_GetExtendedDataNumber(lReadoutBufferId);
    if (lRecordNumber < 0xf0U)
    {
      Dem_EventIdType lEventId;
      lEventId = Dem_DTCReadoutBuffer_GetEventId(lReadoutBufferId);

      /* Look for one specific record */
      for (Dem_ExtendedEntry_IteratorInit(lEventId, Dem_DTCReadoutBuffer_GetMemoryEntryId(lReadoutBufferId), &lExtendedEntryIter);
           Dem_ExtendedEntry_IteratorExists(&lExtendedEntryIter) == TRUE;
           Dem_ExtendedEntry_IteratorNext(&lExtendedEntryIter))
      {
        Dem_Cfg_ERecIndexType lCfgERecIndex;

        lCfgERecIndex = Dem_ExtendedEntry_IteratorGetExtendedRecordIndex(&lExtendedEntryIter);
        if (lRecordNumber == Dem_Cfg_DidNumber(Dem_Cfg_ERecDid(lCfgERecIndex)))
        { /* If the record is supported, the result is always 'OK' */
          lReturnValue = E_OK;
          lAccumulatedSize = Dem_Dcm_ExtendedDataRecord_CalcSize(lCfgERecIndex, lReadoutBufferId, &lExtendedEntryIter);
          break;
        }
      }
    }
    else
    { 
      /* Look for all supported records */
      uint8 lERecMinNumber;
      Dem_EventIdType lEventId;
      if (lRecordNumber == 0xffU)
      {
        lERecMinNumber = 0x00U;
        lEventId = Dem_DTCReadoutBuffer_GetEventId(lReadoutBufferId);
      }
#  if (DEM_FEATURE_NEED_OBD == STD_ON)
      else if (lRecordNumber == 0xfeU)
      {
        lERecMinNumber = 0x8fU;
        lEventId = Dem_DTCReadoutBuffer_GetEventId(lReadoutBufferId);
      }
#  endif
      else
      {
        lERecMinNumber = 0xffU;
        lEventId = DEM_EVENT_INVALID;
      }

      if (lEventId != DEM_EVENT_INVALID)
      {
        for (Dem_ExtendedEntry_IteratorInit(lEventId, Dem_DTCReadoutBuffer_GetMemoryEntryId(lReadoutBufferId), &lExtendedEntryIter);
             Dem_ExtendedEntry_IteratorExists(&lExtendedEntryIter) == TRUE;
             Dem_ExtendedEntry_IteratorNext(&lExtendedEntryIter))
        {
          Dem_Cfg_ERecIndexType lCfgERecIndex;

          lCfgERecIndex = Dem_ExtendedEntry_IteratorGetExtendedRecordIndex(&lExtendedEntryIter);
          if (Dem_Cfg_DidNumber(Dem_Cfg_ERecDid(lCfgERecIndex)) > lERecMinNumber)
          { /* At least one record found - the result should be negative in case the event doesn't
                support any of the requested extended records. */
            lReturnValue = E_OK;
            lAccumulatedSize = 
              (uint16) (lAccumulatedSize + Dem_Dcm_ExtendedDataRecord_CalcSize(lCfgERecIndex, lReadoutBufferId, &lExtendedEntryIter));
          }
        }
      }
    }

    if (lReturnValue == E_OK)
    {
      *SizeOfExtendedDataRecord = lAccumulatedSize;                                                                              /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    }
  }
# else
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(ClientId)                                                                                     /* PRQA S 3112 */ /* MD_DEM_14.2 */
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(SizeOfExtendedDataRecord)                                                                     /* PRQA S 3112 */ /* MD_DEM_14.2 */
# endif

  return lReturnValue;
}                                                                                                                                /* PRQA S 6030, 6050, 6080 */ /* MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
#endif /* (DEM_CFG_SUPPORT_DCM == STD_ON) */

#if (DEM_FEATURE_NEED_OBD == STD_ON) && (DEM_CFG_SUPPORT_PID01 == STD_ON)                                                        /* COV_MSR_UNSUPPORTED XF xf xf */
/* ****************************************************************************
 % Dem_Dcm_ReadDataOfPID01
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
 *
 *
 */
DEM_LOCAL FUNC(void, DEM_CODE)
Dem_Dcm_ReadDataOfPID01(
  CONSTP2VAR(uint8, AUTOMATIC, DEM_DCM_DATA)  PID01value
  )
{
  /*If major monitors is supported */
#if (DEM_CFG_SUPPORT_MAJOR_MONITORS == STD_ON)
  uint32 lPid01;

  /* Set all groups to not supported and not completed (not supported = 0, supported = 1, completed/na = 0, not completed = 1) */
  lPid01 = 0x007000FFUL;

  /* If Event Availabilty is supported the configuration contains only engine type, 
     otherwise supported state of readines groups is also provided */
  lPid01 |= Dem_Cfg_GlobalPid01SupportedMask();
#endif
  /* If OBDII is supported */
# if (DEM_CFG_SUPPORT_OBDII == STD_ON)
  {
    /* If feature reset Confimred DTC on overflow or major monitors and event avilablity is supported */
#  if ((DEM_CFG_PROCESS_CDTC_ALL_DTC == STD_OFF) && \
      ((DEM_CFG_SUPPORT_MAJOR_MONITORS == STD_OFF) || (DEM_CFG_SUPPORT_EVENTAVAILABLE == STD_OFF)))
    uint8 lChronoIndex;
#  endif

    Dem_EventIdType lConfirmedEvents;
    Dem_EventIdType lEventId;
    uint8           lGlobalMilState;

    lConfirmedEvents = 0;

#  if ((DEM_CFG_PROCESS_CDTC_ALL_DTC == STD_ON) || \
      ((DEM_CFG_SUPPORT_MAJOR_MONITORS == STD_ON) && (DEM_CFG_SUPPORT_EVENTAVAILABLE == STD_ON)))
    /* Scan for events in confirmed state */
    for (lEventId = Dem_Cfg_GlobalPrimaryFirst();
         lEventId <= Dem_Cfg_GlobalPrimaryLast();
         lEventId++)
    {
#   if (DEM_CFG_SUPPORT_MAJOR_MONITORS == STD_ON && DEM_CFG_SUPPORT_EVENTAVAILABLE == STD_ON)
      uint8 lReadinessGroup;
      lReadinessGroup = Dem_Cfg_EventReadinessGroup(lEventId);
      /* If event is avilable and assigned to a valid readiness group */
      if ( (lReadinessGroup != DEM_CFG_READINESS_NONE)                                                                           /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
        && (Dem_Event_TestEventSuppressed(lEventId) == FALSE))
      {
        /* Set readiness group to supported*/
        Dem_Util_SetReadinessGroupSupported(TRUE, lReadinessGroup, &lPid01);
      }
#   endif
#   if (DEM_CFG_SUPPORT_TYPE1_COMBINATION == STD_ON)
      if (lEventId != Dem_Cfg_GetMasterEvent(lEventId))
      { /* Don't match dependent combined events, only the group event */
        continue;                                                                                                                /* PRQA S 0770 */ /* MD_DEM_14.5 */
      }
#   endif
#  else
    /* Only the stored events are in confirmed state -> iterate over all stored events and count
    the number of OBD releated events */
    for (lChronoIndex = 0; 
         lChronoIndex < Dem_MemState_GetPrimaryCurrentCount(); 
         lChronoIndex++)
    {
      /* Get EventId for current index */
      lEventId = Dem_MemoryEntry_GetEventId(
        Dem_MemStorageManager_GetMemoryEntryId(Dem_MemStorageManager_MemoryGetChronology(
                                               Dem_MemStorageManager_MemoryInfoInit(DEM_CFG_MEMORYID_PRIMARY), 
                                               lChronoIndex)));                                                                  /* SBSW_DEM_CALL_MEMORYINFO_POINTER */
      /* verify that a valid EventId was returned */
      if (Dem_Event_TestValidHandle(lEventId) == TRUE)
#  endif
      { /* count Event if it is OBD related and confirmed bit is qualified */
        if (Dem_Cfg_EventObdRelated(lEventId) == TRUE)
        {
          uint8 lDtcStatus;
          lDtcStatus = Dem_DTC_ApplyExternalOnlyStatus(lEventId, Dem_DTC_GetDTCStatus(lEventId));
          if (Dem_UDSStatus_Test_CDTC(lDtcStatus) == TRUE)
          {
            lConfirmedEvents++;
          }
        }
      }
    }

    /* set max value if count exceeds 127 */
    if (lConfirmedEvents > 0x7fU)
    {
      lConfirmedEvents = 0x7fU;
    }

    if (Dem_Indicator_TestMilIsActive() == TRUE)
    {
      lGlobalMilState = 0x01U;
    }
    else
    {
      lGlobalMilState = 0x00U;
    }

    /* MIL status and number of OBD relevant confirmed events */
    PID01value[0] = (uint8)((uint8)(lGlobalMilState << 7) | (uint8)lConfirmedEvents); 
  }
# endif
  /* Otherwise if WWHOBD is supported */
# if (DEM_CFG_SUPPORT_WWHOBD == STD_ON)
  /* If major monitors and event avilablity is supported */
#  if (DEM_CFG_SUPPORT_MAJOR_MONITORS == STD_ON && DEM_CFG_SUPPORT_EVENTAVAILABLE == STD_ON)
  for (lEventId = Dem_Cfg_GlobalPrimaryFirst(); 
       lEventId <= Dem_Cfg_GlobalPrimaryLast(); 
       lEventId++)
  {
    uint8 lReadinessGroup = Dem_Cfg_EventReadinessGroup(lEventId);
    /* If event is assigned to readiness group and available */
    if ((lReadinessGroup != DEM_CFG_READINESS_NONE)
      && (Dem_Event_TestEventSuppressed(lEventId) == FALSE)
      )
    {
      /* Set readiness group to supported*/
      Dem_Util_SetReadinessGroupSupported(TRUE, Dem_Cfg_EventReadinessGroup(lEventId), &lPid01);
    }
 }
#  endif
  PID01value[0] = 0x00;
# endif
  /* If major monitors supported */
# if (DEM_CFG_SUPPORT_MAJOR_MONITORS == STD_ON)
  /* Get completed state of readiness groups and set value of remaining bytes in Pid41 (completed = 0, not completed = 1 */
  lPid01 &= Dem_Mem_GetPid01CompletedMask();

  /* If Spark ignition */
  if ((lPid01 & DEM_READINESS_SUPPORT_COMPRESSION) == 0)
  {
    Dem_Util_SetReadinessGroupCompleted(TRUE, DEM_CFG_READINESS_MISF, &lPid01);
  }

  PID01value[1] = Dem_GetHiLoByte(lPid01);
  PID01value[2] = Dem_GetLoHiByte(lPid01);
  PID01value[3] = Dem_GetLoLoByte(lPid01);
# else
  /* Otherwise set static value of remaining bytes in Pid41 (Byte B = 0x04, Byte C = 0x00, Byte D = 0x00) */
  PID01value[1] = 0x04; /* Comprehensive component monitoring supported and ready */
  PID01value[2] = 0x00; /* not supported */
  PID01value[3] = 0x00; /* not supported */
# endif
}                                                                                                                                /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_Dcm_GetStatusOfSelectedDTC
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
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_GetStatusOfSelectedDTC(
  uint8  ClientId,
  P2VAR(uint8, AUTOMATIC, DEM_DCM_DATA)  DTCStatus
  )
{
  Std_ReturnType lReturnValue;
  uint8 lMemoryId;

  lMemoryId = Dem_ClientAccess_GetSelectedMemoryId(ClientId);
  switch (lMemoryId)
  {
  case DEM_CFG_MEMORYID_PERMANENT:
    lReturnValue = DEM_NO_SUCH_ELEMENT;
    break;
  case DEM_CFG_MEMORYID_PRIMARY:
  case DEM_CFG_MEMORYID_SECONDARY:
  {
    Dem_EventIdType lEventId;

    lEventId = Dem_ClientAccess_GetSelectedEventId(ClientId);

    if (lEventId != DEM_EVENT_INVALID)
    {
      uint8 lEventStatus;
      if (Dem_DTC_TestDtcSuppressed(lEventId) == TRUE)
      {
        lReturnValue = DEM_WRONG_DTC;
      }
      else
      {
        lEventStatus = Dem_DTC_ApplyExternalOnlyStatus(lEventId, Dem_DTC_GetDTCStatus(lEventId));

        /* apply status availability mask */
        *DTCStatus = (uint8)(lEventStatus & Dem_Cfg_GlobalStatusMask());                                                         /* SBSW_DEM_POINTER_WRITE_API */
        lReturnValue = E_OK;
      }
    }
    else
    {
      lReturnValue = E_NOT_OK;
    }
  }
    break;

  default:
    lReturnValue = E_NOT_OK;
    break;
  }
  return lReturnValue;
}
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_Dcm_GetSeverityOfSelectedDTC
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
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_GetSeverityOfSelectedDTC(
  CONST(uint8, AUTOMATIC)  ClientId,
  P2VAR(Dem_DTCSeverityType, AUTOMATIC, DEM_DCM_DATA)  DTCSeverity
  )
{
  Std_ReturnType lReturnValue;
  Dem_EventIdType lEventId;

  lEventId = Dem_ClientAccess_GetSelectedEventId(ClientId);

  if (lEventId != DEM_EVENT_INVALID)
  {
    if (Dem_DTC_TestDtcSuppressed(lEventId) == TRUE)
    {
      lReturnValue = DEM_WRONG_DTC;
    }
    else
    {
# if (DEM_FEATURE_NEED_OBD == STD_ON) && (DEM_CFG_SUPPORT_OBD_HIDE_OCCURRENCES == STD_ON)                                        /* COV_MSR_UNSUPPORTED XF xf xf */
      if ( (Dem_DTCReporting_TestObdHideOccurrences() == TRUE)                                                                   /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
        && (Dem_Cfg_EventSignificance(lEventId) == DEM_CFG_EVENT_SIGNIFICANCE_OCCURRENCE)
        && (Dem_Cfg_EventObdRelated(lEventId) == TRUE) )
      { /* Special case - skip Dependent OBD DTCs */
        lReturnValue = DEM_WRONG_DTC;
      }
      else
# endif
      {
        *DTCSeverity = Dem_Cfg_EventSeverity(lEventId);                                                                          /* SBSW_DEM_POINTER_WRITE_API */
        lReturnValue = E_OK;
      }
    }
  }
  else
  {
    lReturnValue = E_NOT_OK;
  }

  return lReturnValue;
}
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_Dcm_GetFunctionalUnitOfSelectedDTC
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
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_GetFunctionalUnitOfSelectedDTC(
  CONST(uint8, AUTOMATIC)  ClientId,
  P2VAR(uint8, AUTOMATIC, DEM_DCM_DATA)  DTCFunctionalUnit
  )
{
  Std_ReturnType lReturnValue;
  Dem_EventIdType lEventId;

  lEventId = Dem_ClientAccess_GetSelectedEventId(ClientId);

  if (lEventId != DEM_EVENT_INVALID)
  {
    if (Dem_DTC_TestDtcSuppressed(lEventId) == TRUE)
    {
      lReturnValue = DEM_WRONG_DTC;
    }
    else
    {
# if (DEM_FEATURE_NEED_OBD == STD_ON) && (DEM_CFG_SUPPORT_OBD_HIDE_OCCURRENCES == STD_ON)                                        /* COV_MSR_UNSUPPORTED XF xf xf */
      if ( (Dem_DTCReporting_TestObdHideOccurrences() == TRUE)                                                                   /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
        && (Dem_Cfg_EventSignificance(lEventId) == DEM_CFG_EVENT_SIGNIFICANCE_OCCURRENCE)
        && (Dem_Cfg_EventObdRelated(lEventId) == TRUE) )
      { /* Special case - skip Dependent OBD DTCs */
        lReturnValue = DEM_WRONG_DTC;
      }
      else
# endif
      {
        *DTCFunctionalUnit = Dem_Cfg_EventFunctionalUnit(lEventId);                                                              /* SBSW_DEM_POINTER_WRITE_API */
        lReturnValue = E_OK;
      }
    }
  }
  else
  {
    lReturnValue = E_NOT_OK;
  }

  return lReturnValue;
}
#endif

/* ****************************************************************************
 % Dem_Dcm_GetEventIdOfSelectedDTC
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_GetEventIdOfSelectedDTC(
  CONST(uint8, AUTOMATIC)  ClientId,
  P2VAR(Dem_EventIdType, AUTOMATIC, DEM_APPL_DATA)  EventId
  )
{
  Std_ReturnType lReturnValue;
  Dem_EventIdType lEventId;

  lEventId = Dem_ClientAccess_GetSelectedEventId(ClientId);

  if (lEventId != DEM_EVENT_INVALID)
  {
    *EventId = lEventId;
    lReturnValue = E_OK;
  }
  else
  {
    lReturnValue = E_NOT_OK;
  }

  return lReturnValue;
}

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* DEM_DCM_IMPLEMENTATION_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_Dcm_Implementation.h
 *********************************************************************************************************************/
