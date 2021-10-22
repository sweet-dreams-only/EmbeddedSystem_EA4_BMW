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
/*! \addtogroup Dem_Data
 *  \{
 *  \file       Dem_Data_Implementation.h
 *  \brief      Diagnostic Event Manager (Dem) header file
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

#if !defined (DEM_DATA_IMPLEMENTATION_H)
#define DEM_DATA_IMPLEMENTATION_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                  /* Own subcomponent header */
/* ------------------------------------------------------------------------- */
#include "Dem_Data_Interface.h"

                                                    /* Used subcomponent API */
/* ------------------------------------------------------------------------- */
#include "Dem_UDSStatus_Interface.h"

                                                   /* Subcomponents callbacks*/
/* ------------------------------------------------------------------------- */
#include "Dem_Error_Interface.h"

/* ********************************************************************************************************************
 *  SUBCOMPONENT CONSTANT MACROS
 *********************************************************************************************************************/
/*! Preconfirmed DTC status after re-initialization */
#define DEM_PC_STATUS_INITIALIZE                 (0x00U)

/* ********************************************************************************************************************
 *  SUBCOMPONENT FUNCTION MACROS
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  SUBCOMPONENT DATA
 *********************************************************************************************************************/
#define DEM_START_SEC_VAR_NOINIT_8BIT
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define DEM_STOP_SEC_VAR_NOINIT_8BIT
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define DEM_START_SEC_VAR_NOINIT_16BIT
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define DEM_STOP_SEC_VAR_NOINIT_16BIT
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define DEM_START_SEC_VAR_NOINIT_32BIT
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define DEM_STOP_SEC_VAR_NOINIT_32BIT
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define DEM_START_SEC_CONST_8BIT
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define DEM_STOP_SEC_CONST_8BIT
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* ********************************************************************************************************************
 *  SUBCOMPONENT OBJECT FUNCTION DEFINITIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \addtogroup Dem_Data_Properties
 * \{
 */

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
 * \addtogroup Dem_Data_Private
 * \{
 */

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
 * \addtogroup Dem_Data_Public
 * \{
 */

/* ****************************************************************************
 % Dem_Data_EntryInit
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Data_EntryInit(
  CONST(Dem_MemoryEntry_HandleType, AUTOMATIC)  MemoryEntryId
  )
{
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(MemoryEntryId)                                                                                /* PRQA S 3112 */ /* MD_DEM_14.2 */

#if (DEM_FEATURE_NEED_OCC_COUNTER == STD_ON)
  Dem_MemoryEntry_ResetOccurrenceCounter(MemoryEntryId);
#endif

  Dem_MemoryEntry_SetAgingCounter(MemoryEntryId, DEM_OPCYCLE_CYCLECOUNT_INVALID);
#if (DEM_CFG_SUPPORT_USER_ERECS == STD_ON)
  Dem_ExtendedEntry_ResetStoredExtendedRecords(MemoryEntryId);
#endif
#if (DEM_CFG_SUPPORT_SRECS == STD_ON)
  Dem_SnapshotEntry_ResetStoredSnapshotRecords(MemoryEntryId);
#endif
#if (DEM_CFG_DATA_MAX_FDC_SINCE_LAST_CLEAR == STD_ON)
  Dem_MemoryEntry_SetDebounceValueMax(MemoryEntryId, 0);
#endif
#if (DEM_CFG_DATA_FAILED_CYCLES == STD_ON)
  Dem_MemoryEntry_SetFailedCycleCounter(MemoryEntryId, 0U);
#endif
#if (DEM_CFG_DATA_CONSECUTIVE_FAILED_CYCLES == STD_ON)
  Dem_MemoryEntry_SetConsecutiveFailedCycleCounter(MemoryEntryId, 0U);
#endif
#if (DEM_CFG_DATA_CYCLES_SINCE_FIRST_FAILED == STD_ON)
  Dem_MemoryEntry_SetCyclesSinceFirstFailed(MemoryEntryId, DEM_OPCYCLE_CYCLECOUNT_INVALID);
#endif
#if (DEM_CFG_DATA_CYCLES_SINCE_LAST_FAILED == STD_ON)
  Dem_MemoryEntry_SetCyclesSinceLastFailed(MemoryEntryId, DEM_OPCYCLE_CYCLECOUNT_INVALID);
#endif
#if (DEM_CFG_DATA_CYCLES_TESTED_SINCE_FIRST_FAILED == STD_ON)
  Dem_MemoryEntry_SetTestedCyclesSinceFirstFailed(MemoryEntryId, 0U);
#endif
#if (DEM_FEATURE_NEED_AGING_REALLOCATION == STD_ON) || (DEM_FEATURE_NEED_OBD == STD_ON)                                          /* COV_MSR_UNSUPPORTED TF tf xf */
  Dem_MemoryEntry_SetState(MemoryEntryId, 0U);
#endif
#if (DEM_CFG_SUPPORT_WWHOBD == STD_ON)                                                                                           /* COV_MSR_UNSUPPORTED XF */
  Dem_MemoryEntry_SetAgingTimer(MemoryEntryId, DEM_ESM_AGINGTIME_INVALID);
#endif
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */

#if (DEM_CFG_SUPPORT_USER_ERECS == STD_ON)
/* ****************************************************************************
 % Dem_Data_EntryUpdate_UserERecs
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
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_Data_EntryUpdate_UserERecs(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(Dem_MemoryEntry_HandleType, AUTOMATIC)  MemoryEntryId
  )
{
  uint8 lBlockModification;
  Dem_ExtendedEntry_IterType lExtendedEntryIter;

  lBlockModification = DEM_DATA_NO_CHANGES;
  
  for (Dem_ExtendedEntry_IteratorInit(EventId, MemoryEntryId, &lExtendedEntryIter);
       Dem_ExtendedEntry_IteratorExists(&lExtendedEntryIter) == TRUE;
       Dem_ExtendedEntry_IteratorNext(&lExtendedEntryIter))
  {
    Dem_Cfg_ERecIndexType lCfgERecIndex;
    lCfgERecIndex = Dem_ExtendedEntry_IteratorGetExtendedRecordIndex(&lExtendedEntryIter);

    if (Dem_Cfg_ERecType(lCfgERecIndex) == DEM_CFG_EREC_TYPE_USER)
    {
# if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
      if (Dem_ExtendedEntry_IteratorGetExtendedEntryIndex(&lExtendedEntryIter) >= Dem_Cfg_GlobalERecMaxCount())
      {
        Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
        break;
      }
# endif
      if ((Dem_Cfg_ERecUpdate(lCfgERecIndex) == TRUE)                                                                           /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
        || (Dem_ExtendedEntry_IteratorIsExtendedRecordStored(&lExtendedEntryIter) == FALSE))
      {
        Dem_SharedDataPtrType lDestinationBuffer;
        Dem_ExtendedEntry_IteratorUpdateExtendedEntry(&lExtendedEntryIter);
        lDestinationBuffer = Dem_ExtendedEntry_IteratorGetExtendedRecordDataPtr(&lExtendedEntryIter);

        Dem_DataStorageIF_CollectERec(EventId, Dem_Cfg_ERecDid(lCfgERecIndex), lDestinationBuffer, Dem_Cfg_GlobalERecMaxRawSize());

        lBlockModification = DEM_DATA_USERDATA_CHANGED;
      }
    }
  }

  return lBlockModification;
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */
#endif

#if (DEM_CFG_SUPPORT_SRECS == STD_ON)
/* ****************************************************************************
 % Dem_Data_EntryUpdate_SRecs
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
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_Data_EntryUpdate_SRecs(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(Dem_MemoryEntry_HandleType, AUTOMATIC)  MemoryEntryId,
  CONST(uint8, AUTOMATIC)  UpdateFlags
  )
{
  uint8 lBlockModification;
# if (DEM_CFG_SUPPORT_SRECS_CONFIGURED == STD_ON)
  uint8 lLastStoredEntryIndex;
# endif
  Dem_SnapshotEntry_IterType lSnapshotEntryIter;

  lBlockModification = DEM_DATA_NO_CHANGES;
# if (DEM_CFG_SUPPORT_SRECS_CONFIGURED == STD_ON)
  lLastStoredEntryIndex = 0xffU; /* Invalid */
# endif

  for (Dem_SnapshotEntry_IteratorInit(EventId, MemoryEntryId, &lSnapshotEntryIter);
       Dem_SnapshotEntry_IteratorExists(&lSnapshotEntryIter) == TRUE;
       Dem_SnapshotEntry_IteratorNext(&lSnapshotEntryIter))
  {
    Dem_Cfg_SRecIndexType lCfgSRecIndex;

    lCfgSRecIndex = Dem_SnapshotEntry_IteratorGetSnapshotRecordIndex(&lSnapshotEntryIter);

    /* If an update is needed: Updates are required when the configured trigger matches,
     * and the record is either not stored or configured for updates */
    if ( (                                                                                                                       /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
# if (DEM_FEATURE_NEED_SREC_OEMTRIGGER == STD_ON)
           (Dem_Data_OemSRecTrigger(EventId, MemoryEntryId, lCfgSRecIndex, UpdateFlags)) ||
# endif
           (Dem_Cfg_SRecTrigger(lCfgSRecIndex) == (UpdateFlags & Dem_Cfg_SRecTrigger(lCfgSRecIndex))) ) &&
         ( (Dem_Cfg_SRecUpdate(lCfgSRecIndex) == TRUE) || (Dem_SnapshotEntry_IteratorIsSnapshotRecordStored(&lSnapshotEntryIter) == FALSE) )
       )
    {
      Dem_SnapshotEntry_IteratorUpdateSnapshotEntry(&lSnapshotEntryIter);

# if (DEM_CFG_SUPPORT_SRECS_CONFIGURED == STD_ON)
      /* For configured snapshot numbers, if the snapshot is already collected copy its data */
      if (lLastStoredEntryIndex != 0xffU)
      {
        Dem_SnapshotEntry_IteratorCopySnapshotEntry(&lSnapshotEntryIter, lLastStoredEntryIndex);
      }
      else
# endif
      {
# if (DEM_CFG_SUPPORT_PRESTORED_FF == STD_ON)
        /* If 'prestore freezeframe' is enabled and data is prestored, copy the prestored data */
        if (Dem_DataStorageIF_PrestorageApplySRec(Dem_SnapshotEntry_IteratorGetSnapshotRecordDataPtr(&lSnapshotEntryIter),
                                         Dem_Cfg_GlobalSRecMaxRawSize()) == FALSE)
# endif
        {
          /* Otherwise, collect new samples from the application. */
          Dem_DataStorageIF_CollectSnapshot(EventId,                                                                             /* SBSW_DEM_POINTER_SNAPSHOT_BUFFER */
                                   Dem_SnapshotEntry_IteratorGetSnapshotRecordDataPtr(&lSnapshotEntryIter),
                                   Dem_Cfg_GlobalSRecMaxRawSize());
# if (DEM_CFG_SUPPORT_SRECS_CONFIGURED == STD_ON)
          lLastStoredEntryIndex = Dem_SnapshotEntry_IteratorGetSnapshotEntryIndex(&lSnapshotEntryIter);
# endif
        }
        lBlockModification = DEM_DATA_USERDATA_CHANGED;
      }
      /* For calculated snapshot records, processing is completed */
# if (DEM_CFG_SUPPORT_SRECS_CALCULATED == STD_ON)
      break;
# endif
    }
  }

  return lBlockModification;
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */
#endif /* (DEM_CFG_SUPPORT_SRECS == STD_ON) */

/* ****************************************************************************
 % Dem_Data_EntryUpdate
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
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_Data_EntryUpdate(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,                                                                                    /* PRQA S 3206 */ /* MD_DEM_3206 */
  CONST(uint8, AUTOMATIC)  UpdateFlags,
  CONST(Dem_Cfg_MemoryIndexType, AUTOMATIC)  MemoryIndex
  )
{
  uint8 lBlockModification;

  lBlockModification = DEM_DATA_NO_CHANGES;

  if (MemoryIndex != DEM_MEM_INVALID_MEMORY_INDEX)
  {
    Dem_Mem_MemoryUpdateStart(MemoryIndex);

    /* On a TestFailed trigger */
    if ((UpdateFlags & DEM_CFG_TRIGGER_TESTFAILED) != 0)
    {
      {
# if (DEM_CFG_PROCESS_OCCTR_CONFIRMED == STD_ON)
        if (Dem_UDSStatus_Test_CDTC(Dem_DTC_GetDTCStatus(EventId)) == TRUE) /* Event had confirmed earlier */
# endif
        {
          if (Dem_MemoryEntry_IncrementOccurrenceCounter(Dem_MemStorageManager_GetMemoryEntryId(MemoryIndex)) == TRUE)
          {
            lBlockModification = DEM_DATA_SET_STATISTICS_CHANGED(lBlockModification);
          }
        }
      }
      {
        Dem_MemoryEntry_SetAgingCounter(Dem_MemStorageManager_GetMemoryEntryId(MemoryIndex), DEM_OPCYCLE_CYCLECOUNT_INVALID);
        lBlockModification = DEM_DATA_SET_STATISTICS_CHANGED(lBlockModification);
      }
#if (DEM_CFG_DATA_CYCLES_SINCE_FIRST_FAILED == STD_ON)
      {
        if (Dem_MemoryEntry_GetCyclesSinceFirstFailed(Dem_MemStorageManager_GetMemoryEntryId(MemoryIndex)) == DEM_OPCYCLE_CYCLECOUNT_INVALID)
        {
          Dem_MemoryEntry_SetCyclesSinceFirstFailed(Dem_MemStorageManager_GetMemoryEntryId(MemoryIndex), Dem_OperationCycle_GetCycleCounter(Dem_Cfg_EventOperationCycle(EventId)));
          lBlockModification = DEM_DATA_SET_STATISTICS_CHANGED(lBlockModification);
        }
      }
#endif
#if (DEM_CFG_DATA_MAX_FDC_SINCE_LAST_CLEAR == STD_ON)
      {
        Dem_MemoryEntry_SetDebounceValueMax(Dem_MemStorageManager_GetMemoryEntryId(MemoryIndex), (sint16)0x7F);
        lBlockModification = DEM_DATA_SET_STATISTICS_CHANGED(lBlockModification);
      }
#endif

#if (DEM_CFG_SUPPORT_USER_ERECS == STD_ON)
      lBlockModification |= Dem_Data_EntryUpdate_UserERecs(EventId, Dem_MemStorageManager_GetMemoryEntryId(MemoryIndex));
#endif
    } /* TEST PASSED->FAILED */

    /* On a TestFailedThisCycle trigger */
    if ((UpdateFlags & DEM_CFG_TRIGGER_TESTFAILEDTHISCYCLE) != 0)
    {
      if (Dem_MemoryEntry_IncrementFailedCycleCounter(Dem_MemStorageManager_GetMemoryEntryId(MemoryIndex)) == TRUE)
      {
        lBlockModification = DEM_DATA_SET_STATISTICS_CHANGED(lBlockModification);
      }
      if (Dem_MemoryEntry_IncrementConsecutiveFailedCycleCounter(Dem_MemStorageManager_GetMemoryEntryId(MemoryIndex)) == TRUE)
      {
        lBlockModification = DEM_DATA_SET_STATISTICS_CHANGED(lBlockModification);
      }
# if (DEM_CFG_DATA_CYCLES_SINCE_LAST_FAILED == STD_ON)
      {
        Dem_MemoryEntry_SetCyclesSinceLastFailed(Dem_MemStorageManager_GetMemoryEntryId(MemoryIndex), Dem_OperationCycle_GetCycleCounter(Dem_Cfg_EventOperationCycle(EventId)));
        lBlockModification = DEM_DATA_SET_STATISTICS_CHANGED(lBlockModification);
      }
# endif

    }

#if (DEM_CFG_SUPPORT_SRECS == STD_ON)
# if (DEM_CFG_SUPPORT_SRECS_CALCULATED == STD_ON)
    if ((UpdateFlags & DEM_CFG_TRIGGER_TESTFAILED) != 0)
# endif
    {
      lBlockModification |= Dem_Data_EntryUpdate_SRecs(EventId, Dem_MemStorageManager_GetMemoryEntryId(MemoryIndex), UpdateFlags);
    }
#endif /* #if (DEM_CFG_SUPPORT_SRECS == STD_ON) */

    Dem_Mem_MemoryUpdateFinish(MemoryIndex);
  } /* if (DEM_MEM_INVALID_MEMORY_INDEX != MemoryIndex) */

  /* In rare cases this function does nothing */
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(EventId)                                                                                      /* PRQA S 3112 */ /* MD_DEM_14.2 */

  return lBlockModification;
}                                                                                                                                /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

#if (DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_ERECS == STD_ON)
/* ****************************************************************************
% Dem_Data_ERecAllDataElementsStored
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
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Data_ERecAllDataElementsStored(
  CONST(Dem_Cfg_DidIndexType, AUTOMATIC)  DidIndex,
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC)  ReadoutBufferId
  )
{
  boolean lReturnValue;

  lReturnValue = TRUE;
# if (DEM_FEATURE_NEED_AGING_REALLOCATION == STD_ON)
  if (DEM_MEM_TEST_AGING_ONLY(Dem_MemoryEntry_GetState(Dem_DTCReadoutBuffer_GetMemoryEntryId(ReadoutBufferId))) == TRUE)
  {
    Dem_Cfg_DidDataIterType lDataIter;

    for (Dem_Cfg_DidDataIterInit(DidIndex, &lDataIter);                                                                          /* SBSW_DEM_CALL_ITERATOR_POINTER */
      Dem_Cfg_DidDataIterExists(&lDataIter) == TRUE;                                                                             /* SBSW_DEM_CALL_ITERATOR_POINTER */
      Dem_Cfg_DidDataIterNext(&lDataIter))                                                                                       /* SBSW_DEM_CALL_ITERATOR_POINTER */
    {
      uint8 lCallbackType;
      Dem_Cfg_DataIndexType lDataIndex;
      lDataIndex = Dem_Cfg_DidDataIterGet(&lDataIter);                                                                             /* SBSW_DEM_CALL_ITERATOR_POINTER */

      lCallbackType = Dem_Cfg_DataCallbackType(lDataIndex);

      if ((lCallbackType == DEM_CFG_DATA_FROM_OCCCTR)
        || (lCallbackType == DEM_CFG_DATA_FROM_OCCCTR_2BYTE)
        || (lCallbackType == DEM_CFG_DATA_FROM_MAX_FDC_SINCE_LAST_CLEAR)
        || (lCallbackType == DEM_CFG_DATA_FROM_FAILED_CYCLES)
        || (lCallbackType == DEM_CFG_DATA_FROM_CONSECUTIVE_FAILED_CYCLES)
        || (lCallbackType == DEM_CFG_DATA_FROM_CYCLES_TESTED_SINCE_FIRST_FAILED)
        )
      {
        lReturnValue = FALSE;
        break;
      }
    }
  }
# else
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(DidIndex)                                                                                     /* PRQA S 3112 */ /* MD_DEM_14.2 */
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(ReadoutBufferId)                                                                              /* PRQA S 3112 */ /* MD_DEM_14.2 */   
# endif
  return lReturnValue;
}
#endif

#if (DEM_FEATURE_NEED_CYCLE_COUNTERS == STD_ON)
/* ****************************************************************************
 % Dem_Data_EntryOpCycleStart
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Data_EntryOpCycleStart(
  CONST(Dem_MemoryEntry_HandleType, AUTOMATIC)  MemoryEntryId,
  CONST(uint16, AUTOMATIC)  CycleCount
  )
{
  boolean lReturnValue;
  lReturnValue = FALSE;

# if (DEM_CFG_DATA_CYCLES_SINCE_FIRST_FAILED == STD_ON)
  if ((Dem_MemoryEntry_GetCyclesSinceFirstFailed(MemoryEntryId) < DEM_OPCYCLE_CYCLECOUNT_MAX)                                    /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
    && (Dem_OperationCycle_CycleCountDistance(Dem_MemoryEntry_GetCyclesSinceFirstFailed(MemoryEntryId), CycleCount) >= 0xffU))
  {
    Dem_MemoryEntry_SetCyclesSinceFirstFailed(MemoryEntryId, DEM_OPCYCLE_CYCLECOUNT_LATCHED);
    lReturnValue = TRUE;
  }
# endif
# if (DEM_CFG_DATA_CYCLES_SINCE_LAST_FAILED == STD_ON)
  if ((Dem_MemoryEntry_GetCyclesSinceLastFailed(MemoryEntryId) < DEM_OPCYCLE_CYCLECOUNT_MAX)                                     /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
    && (Dem_OperationCycle_CycleCountDistance(Dem_MemoryEntry_GetCyclesSinceLastFailed(MemoryEntryId), CycleCount) >= 0xffU))
  {
    Dem_MemoryEntry_SetCyclesSinceLastFailed(MemoryEntryId, DEM_OPCYCLE_CYCLECOUNT_LATCHED);
    lReturnValue = TRUE;
  }
# endif
  return lReturnValue;
}
#endif /* (DEM_FEATURE_NEED_ENTRY_CYCLE_COUNTERS == STD_ON) */

#if (DEM_CFG_DATA_CYCLES_TESTED_SINCE_FIRST_FAILED == STD_ON) || (DEM_CFG_DATA_CONSECUTIVE_FAILED_CYCLES == STD_ON)
/* ****************************************************************************
 % Dem_Data_DtcOpCycleUpdate
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
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Data_DtcOpCycleUpdate(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(uint8, AUTOMATIC)  CycleStatus
  )
{
  uint8 lDtcStatus;
  lDtcStatus = Dem_DTC_ApplyCombinedStatus(Dem_DTC_GetDTCStatus(EventId));

  if ( ((CycleStatus & DEM_OPERATIONCYCLE_CYCLE_STOPPED) != 0)                                                                   /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
    && (Dem_UDSStatus_Test_TNCTOC(lDtcStatus) == FALSE)
    && (Dem_DTC_TestStoredStatus(EventId) == TRUE) )
  {
    Dem_Mem_MemoryInfoPtrType lMemoryInfo;
    Dem_Cfg_MemoryIndexType lMemoryIndex;

    lMemoryInfo = Dem_MemStorageManager_MemoryInfoInit(Dem_Cfg_EventDestination(EventId));                                       /* PRQA S 3112 */ /* MD_DEM_14.2 */
    lMemoryIndex = Dem_MemStorageManager_MemoryFindIndex_Checked(lMemoryInfo, EventId);                                          /* SBSW_DEM_CALL_MEMORYINFO_POINTER */

# if (DEM_CFG_DATA_CONSECUTIVE_FAILED_CYCLES == STD_ON)
    if (Dem_UDSStatus_Test_TFTOC(lDtcStatus) == FALSE)
    { /* reset the 'consecutive failed cycles' */
      Dem_MemoryEntry_SetConsecutiveFailedCycleCounter(Dem_MemStorageManager_GetMemoryEntryId(lMemoryIndex), 0);
    }
# endif

# if (DEM_CFG_DATA_CYCLES_TESTED_SINCE_FIRST_FAILED == STD_ON)
#  if (DEM_CFG_STORAGE_AT_FDC == STD_ON)
    if (Dem_UDSStatus_Test_TFSLC(lDtcStatus) == TRUE)
#  endif
    {
      Dem_MemoryEntry_HandleType lMemoryEntryId;
      lMemoryEntryId = Dem_MemStorageManager_GetMemoryEntryId(lMemoryIndex);
      if (Dem_MemoryEntry_GetTestedCyclesSinceFirstFailed(lMemoryEntryId) < 255)
      {
        Dem_MemoryEntry_SetTestedCyclesSinceFirstFailed(lMemoryEntryId, 
                                                        Dem_MemoryEntry_GetTestedCyclesSinceFirstFailed(lMemoryEntryId) + 1);
      }
    }
# endif
  }
}                                                                                                                                /* PRQA S 6080, 6050 */ /* MD_MSR_STMIF,  MD_MSR_STCAL */
#endif

#if (DEM_FEATURE_NEED_PID01_CALCULATION == STD_ON)
/* ****************************************************************************
 % Dem_Data_Calc_Pid01_MonitorCompleted
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
DEM_LOCAL FUNC(void, DEM_CODE) Dem_Data_Calc_Pid01_MonitorCompleted(
  CONST(uint8, AUTOMATIC)  ReadinessGroup
  )
{
  /* If readiness group is valid */
  if ( (ReadinessGroup != DEM_CFG_READINESS_NONE) 
    && (ReadinessGroup != DEM_CFG_READINESS_FLSYS))
  {
    /* If readiness group is not completed */
    if (Dem_Data_TestReadinessGroupCompleted(ReadinessGroup, Dem_Mem_GetPid01CompletedMask()) == FALSE)
    {
      Dem_EventIdType lEventId;
      boolean lIsCompleted;
      
      lIsCompleted = TRUE;

      for (lEventId = Dem_Cfg_GlobalPrimaryFirst();
           lEventId <= Dem_Cfg_GlobalPrimaryLast();
           lEventId++)
      {
        uint8 lReadinessGroup;
        lReadinessGroup = Dem_Cfg_EventReadinessGroup(lEventId);
        /* If event is assigned to passed group */
        if (lReadinessGroup == ReadinessGroup)
        {
          /* If event is available */
          if (Dem_Event_TestEventSuppressed(lEventId) == FALSE)
          {
            uint8 lDtcStatus;
            uint8 lExtStatus;
            lDtcStatus = Dem_DTC_ApplyExternalOnlyStatus(lEventId, Dem_DTC_GetDTCStatus(lEventId));
            lExtStatus = Dem_Event_GetExtendedStatus(lEventId);
            if ((Dem_DTCInternalStatus_TestExtendedStatus_TPSLC(lExtStatus) == FALSE)                                           /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
              || (Dem_UDSStatus_Test_PDTC(lDtcStatus) == TRUE))
            {
              /* Leave readiness group not completed */
              lIsCompleted = FALSE;
              break;
            }
          }
        }
      }

      /* Otherwise set readiness group to completed */
      if (lIsCompleted == TRUE)
      {
        Dem_Util_SetReadinessGroupCompleted(TRUE, ReadinessGroup, &Dem_Mem_GetPid01CompletedMask());
      }
    }
  }
}                                                                                                                                /* PRQA S 6050, 6080 */ /* MD_MSR_STCAL, MD_MSR_STMIF */
#endif

#if ((DEM_FEATURE_NEED_PID41_CALCULATION == STD_ON) || (DEM_FEATURE_NEED_PID41_CCONLY_CALCULATION == STD_ON) )
/* ****************************************************************************
 % Dem_Data_TestReadinessGroupDisabled
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Data_TestReadinessGroupDisabled(
  CONST(uint8, AUTOMATIC)  ReadinessGroup
  )
{
  uint8 lReadinessGroup;
  if (ReadinessGroup == DEM_CFG_READINESS_FLSYS)
  {
    lReadinessGroup = DEM_CFG_READINESS_FLSYS_NONCONT;
  }
  else
  {
    lReadinessGroup = ReadinessGroup;
  }
  return (boolean)(((Dem_Mem_GetPid41DisabledMask() & (1u << (lReadinessGroup))) != 0) ? TRUE : FALSE);
}
#endif

#if (DEM_FEATURE_NEED_PID41_CALCULATION == STD_ON)
/* ****************************************************************************
 % Dem_Data_GetPid41
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
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Data_GetPid41(
  CONSTP2VAR(uint8, AUTOMATIC, DEM_DCM_DATA)  PID41value
  )
{
  uint32 lReadinessCompletedMask;
  uint32 lPid41;
  Dem_EventIdType lEventId;

  /* Set all groups in CompletedMask to not completed -> (completed = 0, not completed = 1) */
  lReadinessCompletedMask = 0xFFFFFFFFUL;

  /* Get supported and completed state from configuration */
  lPid41 = Dem_Cfg_GlobalPid01SupportedMask();

  /* Iterate over all events assigned to primary memory (OBD related events are assigned to primary memory */
  for (lEventId = Dem_Cfg_GlobalPrimaryFirst(); lEventId <= Dem_Cfg_GlobalPrimaryLast(); lEventId++)
  {
    uint8 lReadinessGroup = Dem_Cfg_EventReadinessGroup(lEventId);

    /* If a readiness group is assigned to event */
    if ((lReadinessGroup != DEM_CFG_READINESS_NONE)                                                                              /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
      /* If event is available */
      && (Dem_Event_TestEventSuppressed(lEventId) == FALSE)
      )
    {
      /* If Comprehensive Complete is supported and readiness group is DEM_CFG_READINESS_CMPRCMPT */
# if (DEM_CFG_PROCESS_PID41_COMPREHENSIVE_COMPLETE == STD_ON)
      if (lReadinessGroup == DEM_CFG_READINESS_CMPRCMPT)
      {
        if (Dem_Data_TestReadinessGroupDisabled(lReadinessGroup) == TRUE)
        {
          /* Set readiness group to not supported */
          Dem_Util_SetReadinessGroupSupported(FALSE, lReadinessGroup, &lPid41);
        }
        else
        {
          /* Readiness group is set to supported (it will be set also to completed in last step) */
          Dem_Util_SetReadinessGroupSupported(TRUE, lReadinessGroup, &lPid41);
        }

        /* continue with next event */
        continue;                                                                                                                /* PRQA S 0770 */ /* MD_DEM_14.5 */
      }
# endif
      /* If readiness group is disabled */
      if (Dem_Data_TestReadinessGroupDisabled(lReadinessGroup) == TRUE)
      {
        /* Set readiness group to n/a (= completed)*/
        Dem_Util_SetReadinessGroupCompleted(TRUE, lReadinessGroup, &lPid41);

        /* Set readiness group to not supported */
        Dem_Util_SetReadinessGroupSupported(FALSE, lReadinessGroup, &lPid41);
      }
      else
      {
        /* If readiness group in CompletedMask is not completed */
        if (Dem_Data_TestReadinessGroupCompleted(lReadinessGroup, lReadinessCompletedMask) == FALSE)
        {
          uint8 lDtcStatus;
          lDtcStatus = Dem_DTC_GetDTCStatus(lEventId);

          /* If event is failed this operation cycle */
          if (Dem_UDSStatus_Test_TFTOC(lDtcStatus) == TRUE)
          {
            /* Set readiness group to completed  */
            Dem_Util_SetReadinessGroupCompleted(TRUE, lReadinessGroup, &lReadinessCompletedMask);
          }
          /* Otherwise if event is not tested this cycle */
          else if (Dem_UDSStatus_Test_TNCTOC(lDtcStatus) == TRUE)
          {
            /* Set readiness group to not completed  */
            Dem_Util_SetReadinessGroupCompleted(FALSE, lReadinessGroup, &lPid41);
          }
          else
          {
            /* do nothing */
          }
        }

        /* If Event Availability is supported */
# if (DEM_CFG_SUPPORT_EVENTAVAILABLE == STD_ON)
        /* Set readiness group to supported*/
        Dem_Util_SetReadinessGroupSupported(TRUE, lReadinessGroup, &lPid41);
# endif
      }
    }
  }

  /* If readiness group in CompletedMask is completed set readiness group to completed -> (completed = 0, not completed = 1) */
  lPid41 &= lReadinessCompletedMask;

  /* Set reserved completed bits to 0 */
  if ((lPid41 & DEM_READINESS_SUPPORT_COMPRESSION) != 0)
  {
    lPid41 &= DEM_READINESS_INITIALIZE_PID01COMPLETED_COMPRESSION;
  }
  else
  {
    lPid41 &= DEM_READINESS_INITIALIZE_PID01COMPLETED_SPARK;
  }

  /* If Comprehensive Complete is supported set readiness group DEM_CFG_READINESS_CMPRCMPT to complete */
# if (DEM_CFG_PROCESS_PID41_COMPREHENSIVE_COMPLETE == STD_ON)
  Dem_Util_SetReadinessGroupCompleted(TRUE, DEM_CFG_READINESS_CMPRCMPT, &lPid41);
# endif

  PID41value[1] = Dem_GetHiLoByte(lPid41);
  PID41value[2] = Dem_GetLoHiByte(lPid41);
  PID41value[3] = Dem_GetLoLoByte(lPid41);
}                                                                                                                                /* PRQA S 6050, 6080 */ /* MD_MSR_STCAL, MD_MSR_STMIF */
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_FEATURE_NEED_OBD == STD_ON) && (DEM_CFG_SUPPORT_PID41 == STD_ON) && (DEM_CFG_SUPPORT_MAJOR_MONITORS == STD_OFF)
/* ****************************************************************************
 % Dem_Data_GetPid41ComprehensiveOnly
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
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Data_GetPid41ComprehensiveOnly(
  CONSTP2VAR(uint8, AUTOMATIC, DEM_DCM_DATA)  PID41value
  )
{
# if (DEM_CFG_PROCESS_PID41_COMPREHENSIVE_COMPLETE == STD_OFF)
  Dem_EventIdType lEventId;

  boolean lSupported;
  boolean lCompleted;

  /* If readiness group is disabled */
  if (Dem_Data_TestReadinessGroupDisabled(DEM_CFG_READINESS_CMPRCMPT) == TRUE)
  {
    /* Set readiness group to complete ( = not applicable) */
    lCompleted = TRUE;

    /* Set readiness group to not supported */
    lSupported = FALSE;
  }
  /* Otherwise */
  else
  {
    lCompleted = TRUE;
#  if (DEM_CFG_SUPPORT_EVENTAVAILABLE == STD_ON)
    /* Set readiness group DEM_CFG_READINESS_CMPRCMPT to not supported -> will be calculated later*/
    lSupported = FALSE;
#  else
    /* Otherwise get state for DEM_CFG_READINESS_CMPRCMPT from configuration, all others are not supported and complete */
    lSupported = (boolean)((Dem_Cfg_GlobalPid01SupportedMask() & DEM_READINESS_SUPPORT_CMPRCMPT) != 0);

    if (lSupported == TRUE)
#  endif
    /* If Event Availability is supported or readiness group DEM_CFG_READINESS_CMPRCMPT is supported */
    {
      /* Iterate over all events assigned to primary memory (OBD related events are assigned to primary memory */
      for (lEventId = Dem_Cfg_GlobalPrimaryFirst(); lEventId <= Dem_Cfg_GlobalPrimaryLast(); lEventId++)
      {
        /* If event readiness group is DEM_CFG_READINESS_CMPRCMPT and event is available */
        if ((Dem_Cfg_EventReadinessGroup(lEventId) == DEM_CFG_READINESS_CMPRCMPT)                                                /* PRQA S 3415 */ /* MD_DEM_12.4_cs */
          && (Dem_Event_TestEventSuppressed(lEventId) == FALSE)
          )
        {
          uint8 lDtcStatus;
          lDtcStatus = Dem_DTC_GetDTCStatus(lEventId);

          /* If Event Availability is supported */
#  if (DEM_CFG_SUPPORT_EVENTAVAILABLE == STD_ON)
          /* Set readiness group to supported*/
          lSupported = TRUE;
#  endif /* If Event Availability is not supported supported state is in configuration */

          /* If event is failed this operation cycle */
          if (Dem_UDSStatus_Test_TFTOC(lDtcStatus) == TRUE)
          {
            lCompleted = TRUE;
            /* Stop iterating over all events  */
            break;
          }
          /* Otherwise if event is not tested this cycle */
          else if (Dem_UDSStatus_Test_TNCTOC(lDtcStatus) == TRUE)
          {
            /* Set readiness group to not completed */
            lCompleted = FALSE;
          }
          else
          {
            /* do nothing */
          }
        }
      }
    }
  }

  /* Return Pid41 value */
  PID41value[1] = 0x00;
  PID41value[2] = 0x00;
  PID41value[3] = 0x00;
  if (lSupported == TRUE)
  {
    PID41value[1] |= 0x04;
  }
  /* Only supported monitors can be set not completed */
  if (lCompleted == FALSE)
  {
    PID41value[1] |= 0x40;
  }
# else
  PID41value[1] = 0x04;
  PID41value[2] = 0x00; /* not supported */
  PID41value[3] = 0x00; /* not supported */
# endif
}                                                                                                                                /* PRQA S 6050, 6080 */ /* MD_MSR_STCAL, MD_MSR_STMIF */
#endif

#if ( (DEM_FEATURE_NEED_PID01_CALCULATION == STD_ON) || (DEM_FEATURE_NEED_PID41_CALCULATION == STD_ON) )
/* ****************************************************************************
 % Dem_Data_TestReadinessGroupCompleted
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Data_TestReadinessGroupCompleted(
  CONST(uint8, AUTOMATIC)  ReadinessGroup,
  CONST(uint32, AUTOMATIC)  Pid01CompletedMask
  )
{
  boolean lReturnValue;

  switch (ReadinessGroup)
  {
  case DEM_CFG_READINESS_MISF:
    lReturnValue = (boolean)(((Pid01CompletedMask & DEM_READINESS_COMPLETE_MISF_MASK) == 0) ? TRUE : FALSE);
    break;
  case DEM_CFG_READINESS_FLSYS:
  case DEM_CFG_READINESS_FLSYS_NONCONT:
    lReturnValue = (boolean)(((Pid01CompletedMask & DEM_READINESS_COMPLETE_FLSYS_MASK) == 0) ? TRUE : FALSE);
    break;
  case DEM_CFG_READINESS_CMPRCMPT:
    lReturnValue = (boolean)(((Pid01CompletedMask & DEM_READINESS_COMPLETE_CMPRCMPT) == 0) ? TRUE : FALSE);
    break;
  case DEM_CFG_READINESS_CAT:
    lReturnValue = (boolean)(((Pid01CompletedMask & DEM_READINESS_COMPLETE_CAT_MASK) == 0) ? TRUE : FALSE);
    break;
  case DEM_CFG_READINESS_HCCAT:
    lReturnValue = (boolean)(((Pid01CompletedMask & DEM_READINESS_COMPLETE_HCCAT_MASK) == 0) ? TRUE : FALSE);
    break;
  case DEM_CFG_READINESS_HTCAT:
    lReturnValue = (boolean)(((Pid01CompletedMask & DEM_READINESS_COMPLETE_HTCAT_MASK) == 0) ? TRUE : FALSE);
    break;
  case DEM_CFG_READINESS_NOXCAT:
    lReturnValue = (boolean)(((Pid01CompletedMask & DEM_READINESS_COMPLETE_NOXCAT_MASK) == 0) ? TRUE : FALSE);
    break;
  case DEM_CFG_READINESS_EVAP:
    lReturnValue = (boolean)(((Pid01CompletedMask & DEM_READINESS_COMPLETE_EVAP_MASK) == 0) ? TRUE : FALSE);
    break;
  case DEM_CFG_READINESS_SECAIR:
    lReturnValue = (boolean)(((Pid01CompletedMask & DEM_READINESS_COMPLETE_SECAIR_MASK) == 0) ? TRUE : FALSE);
    break;
  case DEM_CFG_READINESS_BOOSTPR:
    lReturnValue = (boolean)(((Pid01CompletedMask & DEM_READINESS_COMPLETE_BOOSTPR_MASK) == 0) ? TRUE : FALSE);
    break;
  case DEM_CFG_READINESS_O2SENS:
    lReturnValue = (boolean)(((Pid01CompletedMask & DEM_READINESS_COMPLETE_O2SENS_MASK) == 0) ? TRUE : FALSE);
    break;
  case DEM_CFG_READINESS_EGSENS:
    lReturnValue = (boolean)(((Pid01CompletedMask & DEM_READINESS_COMPLETE_EGSENS_MASK) == 0) ? TRUE : FALSE);
    break;
  case DEM_CFG_READINESS_O2SENSHT:
    lReturnValue = (boolean)(((Pid01CompletedMask & DEM_READINESS_COMPLETE_O2SENSHT_MASK) == 0) ? TRUE : FALSE);
    break;
  case DEM_CFG_READINESS_PMFLT:
    lReturnValue = (boolean)(((Pid01CompletedMask & DEM_READINESS_COMPLETE_PMFLT_MASK) == 0) ? TRUE : FALSE);
    break;
  case DEM_CFG_READINESS_EGR:
    lReturnValue = (boolean)(((Pid01CompletedMask & DEM_READINESS_COMPLETE_EGR_MASK) == 0) ? TRUE : FALSE);
    break;
  default:
    /* case DEM_CFG_READINESS_NONE: */
    lReturnValue = FALSE;
    break;
  }

  return lReturnValue;
}                                                                                                                                /* PRQA S 6030 */ /* MD_MSR_STCYC */
#endif

#if (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) && \
( (DEM_CFG_DATA_CYCLES_TESTED_SINCE_LAST_FAILED == STD_ON) || (DEM_CFG_DATA_HEALINGCTR_DOWNCNT == STD_ON) )
/* ****************************************************************************
 % Dem_Data_TestHealingCounterReadable
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
Dem_Data_TestHealingCounterReadable(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  )
{
  boolean lCounterReadable;
  uint8 lDtcStatus;

  lCounterReadable = FALSE;
  lDtcStatus = Dem_DTC_GetDTCStatus(EventId);

  if (Dem_UDSStatus_Test_TFSLC(lDtcStatus) == TRUE)
  {
    if ((Dem_UDSStatus_Test_PDTC(lDtcStatus) == FALSE)                                                                     /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
# if (DEM_CFG_PROCESS_PDTC_STOREDONLY == STD_ON)
      && (Dem_DTC_TestStoredStatus(EventId) == TRUE)
# endif
      )
    {
      lCounterReadable = TRUE;
    }
  }

  return lCounterReadable;
}
#endif

#if (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) && (DEM_CFG_DATA_AGINGCTR == STD_ON)
/* ****************************************************************************
 % Dem_Data_CopyUpwardsAgingCounter
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
Dem_Data_CopyUpwardsAgingCounter(
  CONST(Dem_DataReportIF_CopyDidInfoPtrType, AUTOMATIC)  CopyDidInfoPtr
  )
{
  uint8 lAgingCounter;

  Dem_Internal_AssertReturnValue(CopyDidInfoPtr->MemoryEntryId != DEM_MEMORYENTRY_HANDLE_INVALID, DEM_E_INCONSISTENT_STATE, FALSE)

  if ( (Dem_MemoryEntry_GetAgingCounter(CopyDidInfoPtr->MemoryEntryId) == DEM_OPCYCLE_CYCLECOUNT_INVALID)                            /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
# if (DEM_CFG_AGING_COUNT_ONLY_AGEABLE == STD_ON)
    || (Dem_Cfg_EventSupportAging(CopyDidInfoPtr->EventId) == FALSE)
# endif
     )
  {
    lAgingCounter = 0x00U;
  }
  else
  if (Dem_MemoryEntry_GetAgingCounter(CopyDidInfoPtr->MemoryEntryId) == DEM_OPCYCLE_CYCLECOUNT_LATCHED)
  {
    lAgingCounter = 0xffU;
  }
# if (DEM_CFG_AGING_RETAIN_MEMORY_ENTRY == STD_ON)
  else
  if (Dem_MemoryEntry_GetAgingCounter(CopyDidInfoPtr->MemoryEntryId) == DEM_OPCYCLE_CYCLECOUNT_AGED)
  {
    lAgingCounter = (uint8)(Dem_Cfg_EventAgingTarget(CopyDidInfoPtr->EventId));
  }
# endif
  else
  {
    uint16 lTarget = Dem_MemoryEntry_GetAgingCounter(CopyDidInfoPtr->MemoryEntryId);
    uint16 lCurrent = Dem_OperationCycle_GetCycleCounter(Dem_Cfg_EventAgingCycle(CopyDidInfoPtr->EventId));
    lAgingCounter = (uint8)(Dem_Cfg_EventAgingTarget(CopyDidInfoPtr->EventId) - Dem_OperationCycle_CycleCountDistance(lCurrent, lTarget));
# if (DEM_CFG_AGING_REPORT_ZERO_AS_ONE == STD_ON)
    if (lAgingCounter == 0x00U)
    {
      lAgingCounter = 0x01U;
    }
# endif
  }

  if (CopyDidInfoPtr->BufferSize > CopyDidInfoPtr->WriteIndex)
  {
    CopyDidInfoPtr->DestinationBuffer[CopyDidInfoPtr->WriteIndex] = lAgingCounter;                                               /* SBSW_DEM_WRITE_DIDINFO_DESTINATIONBUFFER */
    CopyDidInfoPtr->WriteIndex += 1;                                                                                             /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
  }
  return TRUE;
}
#endif /* (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) && (DEM_CFG_DATA_AGINGCTR == STD_ON) */

#if (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) && (DEM_CFG_DATA_AGINGCTR_INVERTED == STD_ON)
/* ****************************************************************************
 % Dem_Data_CopyDownwardsAgingCounter
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
Dem_Data_CopyDownwardsAgingCounter(
  CONST(Dem_DataReportIF_CopyDidInfoPtrType, AUTOMATIC)  CopyDidInfoPtr
  )
{
  uint8 lAgingCounter;

  Dem_Internal_AssertReturnValue(CopyDidInfoPtr->MemoryEntryId != DEM_MEMORYENTRY_HANDLE_INVALID, DEM_E_INCONSISTENT_STATE, FALSE)

  if ((Dem_MemoryEntry_GetAgingCounter(CopyDidInfoPtr->MemoryEntryId) == DEM_OPCYCLE_CYCLECOUNT_INVALID)                         /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
# if (DEM_CFG_AGING_COUNT_ONLY_AGEABLE == STD_ON)
    || (Dem_Cfg_EventSupportAging(CopyDidInfoPtr->EventId) == FALSE)
# endif
     )
  {
    lAgingCounter = Dem_Cfg_EventAgingTarget(CopyDidInfoPtr->EventId);
  }
  else
  if ( (Dem_MemoryEntry_GetAgingCounter(CopyDidInfoPtr->MemoryEntryId) == DEM_OPCYCLE_CYCLECOUNT_LATCHED)                        /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
# if (DEM_CFG_AGING_RETAIN_MEMORY_ENTRY == STD_ON)
    || (Dem_MemoryEntry_GetAgingCounter(CopyDidInfoPtr->MemoryEntryId) == DEM_OPCYCLE_CYCLECOUNT_AGED)
# endif
    )
  {
    lAgingCounter = 0x00U;
  }
  else
  {
    uint16 lTarget = Dem_MemoryEntry_GetAgingCounter(CopyDidInfoPtr->MemoryEntryId);
    uint16 lCurrent = Dem_OperationCycle_GetCycleCounter(Dem_Cfg_EventAgingCycle(CopyDidInfoPtr->EventId));
    lAgingCounter = (uint8)(Dem_OperationCycle_CycleCountDistance(lCurrent, lTarget));
  }

  if (CopyDidInfoPtr->BufferSize > CopyDidInfoPtr->WriteIndex)
  {
    CopyDidInfoPtr->DestinationBuffer[CopyDidInfoPtr->WriteIndex] = lAgingCounter;                                               /* SBSW_DEM_WRITE_DIDINFO_DESTINATIONBUFFER */
    CopyDidInfoPtr->WriteIndex += 1;                                                                                             /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
  }
  return TRUE;
}
#endif /* (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) && (DEM_CFG_DATA_AGINGCTR_INVERTED == STD_ON) */

#if (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) && (DEM_CFG_DATA_OCCCTR == STD_ON)
/* ****************************************************************************
 % Dem_Data_Copy1ByteOccurrenceCounter
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Data_Copy1ByteOccurrenceCounter(
  CONST(Dem_DataReportIF_CopyDidInfoPtrType, AUTOMATIC)  CopyDidInfoPtr
  )
{
  boolean lReturnValue;
  uint8 lOccurrenceCounter;

  Dem_Internal_AssertReturnValue(CopyDidInfoPtr->MemoryEntryId != DEM_MEMORYENTRY_HANDLE_INVALID, DEM_E_INCONSISTENT_STATE, FALSE)

# if (DEM_FEATURE_NEED_AGING_REALLOCATION == STD_ON)
  if (DEM_MEM_TEST_AGING_ONLY(Dem_MemoryEntry_GetState(CopyDidInfoPtr->MemoryEntryId)) == TRUE)
  {
    lReturnValue = FALSE;
  }
  else
# endif
  {
# if (DEM_CFG_DATA_OCCCTR_2BYTE == STD_ON)
    {
      uint16 lOccurrenceCounter2Byte;
      lOccurrenceCounter2Byte = Dem_MemoryEntry_GetOccurrenceCounter2Byte(CopyDidInfoPtr->MemoryEntryId);
      if (lOccurrenceCounter2Byte > 0xffU)
      {
        lOccurrenceCounter = 0xffU;
      }
      else
      {
        lOccurrenceCounter = (uint8) lOccurrenceCounter2Byte;
      }
    }
# else
    lOccurrenceCounter = (uint8)Dem_MemoryEntry_GetOccurrenceCounter(CopyDidInfoPtr->MemoryEntryId);
#endif

    if (CopyDidInfoPtr->BufferSize > CopyDidInfoPtr->WriteIndex)
    {
      CopyDidInfoPtr->DestinationBuffer[CopyDidInfoPtr->WriteIndex] = lOccurrenceCounter;                                        /* SBSW_DEM_WRITE_DIDINFO_DESTINATIONBUFFER */
      CopyDidInfoPtr->WriteIndex += 1;                                                                                           /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    }

    lReturnValue = TRUE;
  }
  return lReturnValue;
}
#endif /* (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) && (DEM_CFG_DATA_OCCCTR == STD_ON) */

#if (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) && (DEM_CFG_DATA_OCCCTR_2BYTE == STD_ON)
/* ****************************************************************************
 % Dem_Data_Copy2ByteOccurrenceCounter
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Data_Copy2ByteOccurrenceCounter(
  CONST(Dem_DataReportIF_CopyDidInfoPtrType, AUTOMATIC)  CopyDidInfoPtr
  )
{
  boolean lReturnValue;

  Dem_Internal_AssertReturnValue(CopyDidInfoPtr->MemoryEntryId != DEM_MEMORYENTRY_HANDLE_INVALID, DEM_E_INCONSISTENT_STATE, FALSE)

# if (DEM_FEATURE_NEED_AGING_REALLOCATION == STD_ON)
  if (DEM_MEM_TEST_AGING_ONLY(Dem_MemoryEntry_GetState(CopyDidInfoPtr->MemoryEntryId)) == TRUE)
  {
    lReturnValue = FALSE;
  }
  else
# endif
  {
    if (CopyDidInfoPtr->BufferSize >= (CopyDidInfoPtr->WriteIndex + 2))
    {
      CopyDidInfoPtr->DestinationBuffer[CopyDidInfoPtr->WriteIndex + 0] =                                                        /* SBSW_DEM_WRITE_DIDINFO_DESTINATIONBUFFER */
        Dem_GetHiByte(Dem_MemoryEntry_GetOccurrenceCounter2Byte(CopyDidInfoPtr->MemoryEntryId));
      CopyDidInfoPtr->DestinationBuffer[CopyDidInfoPtr->WriteIndex + 1] =                                                        /* SBSW_DEM_WRITE_DIDINFO_DESTINATIONBUFFER */
        Dem_GetLoByte(Dem_MemoryEntry_GetOccurrenceCounter2Byte(CopyDidInfoPtr->MemoryEntryId));
      CopyDidInfoPtr->WriteIndex += 2;                                                                                           /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    }
    lReturnValue = TRUE;
  }
  return lReturnValue;
}
#endif /* (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) && (DEM_CFG_DATA_OCCCTR_2BYTE == STD_ON) */

#if (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) && (DEM_CFG_DATA_OVFLIND == STD_ON)
/* ****************************************************************************
 % Dem_Data_CopyOverflowIndication
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Data_CopyOverflowIndication(
  CONST(Dem_DataReportIF_CopyDidInfoPtrType, AUTOMATIC)  CopyDidInfoPtr
  )
{
  Dem_Internal_AssertReturnValue(CopyDidInfoPtr->EventId != DEM_EVENT_INVALID, DEM_E_INCONSISTENT_STATE, FALSE)

  if (CopyDidInfoPtr->BufferSize > CopyDidInfoPtr->WriteIndex)
  {
    CopyDidInfoPtr->DestinationBuffer[CopyDidInfoPtr->WriteIndex] = (uint8)Dem_Mem_GetOverflow(Dem_Cfg_EventDestination(CopyDidInfoPtr->EventId));  /* SBSW_DEM_WRITE_DIDINFO_DESTINATIONBUFFER */
    CopyDidInfoPtr->WriteIndex += 1;                                                                                             /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
  }
  return TRUE;
}
#endif /* (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) && (DEM_CFG_DATA_OVFLIND == STD_ON) */

#if (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) && (DEM_CFG_DATA_SIGNIFICANCE == STD_ON)
/* ****************************************************************************
 % Dem_Data_CopyEventSignificance
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Data_CopyEventSignificance(
  CONST(Dem_DataReportIF_CopyDidInfoPtrType, AUTOMATIC)  CopyDidInfoPtr
  )
{
  Dem_Internal_AssertReturnValue(CopyDidInfoPtr->EventId != DEM_EVENT_INVALID, DEM_E_INCONSISTENT_STATE, FALSE)

  if (CopyDidInfoPtr->BufferSize > CopyDidInfoPtr->WriteIndex)
  {
    CopyDidInfoPtr->DestinationBuffer[CopyDidInfoPtr->WriteIndex] = (uint8)(Dem_Cfg_EventSignificance(CopyDidInfoPtr->EventId) == DEM_CFG_EVENT_SIGNIFICANCE_FAULT);  /* SBSW_DEM_WRITE_DIDINFO_DESTINATIONBUFFER */
    CopyDidInfoPtr->WriteIndex += 1;                                                                                             /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
  }
  return TRUE;
}
#endif /* (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) && (DEM_CFG_DATA_SIGNIFICANCE == STD_ON) */

#if (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) && (DEM_CFG_DATA_PRIORITY == STD_ON)
/* ****************************************************************************
 % Dem_Data_CopyEventPriority
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Data_CopyEventPriority(
  CONST(Dem_DataReportIF_CopyDidInfoPtrType, AUTOMATIC)  CopyDidInfoPtr
  )
{
  Dem_Internal_AssertReturnValue(CopyDidInfoPtr->EventId != DEM_EVENT_INVALID, DEM_E_INCONSISTENT_STATE, FALSE)

  if (CopyDidInfoPtr->BufferSize > CopyDidInfoPtr->WriteIndex)
  {
    CopyDidInfoPtr->DestinationBuffer[CopyDidInfoPtr->WriteIndex] = (uint8)Dem_Cfg_EventPriority(CopyDidInfoPtr->EventId);       /* SBSW_DEM_WRITE_DIDINFO_DESTINATIONBUFFER */
    CopyDidInfoPtr->WriteIndex += 1;                                                                                             /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
  }
  return TRUE;
}
#endif /* (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) && (DEM_CFG_DATA_PRIORITY == STD_ON) */

#if (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) && (DEM_CFG_DATA_MAX_FDC_SINCE_LAST_CLEAR == STD_ON)
/* ****************************************************************************
 % Dem_Data_CopyMaxFdcSinceLastClear
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Data_CopyMaxFdcSinceLastClear(
  CONST(Dem_DataReportIF_CopyDidInfoPtrType, AUTOMATIC)  CopyDidInfoPtr
  )
{
  boolean lReturnValue;
  sint8 lFdc;

  Dem_Internal_AssertReturnValue(CopyDidInfoPtr->MemoryEntryId != DEM_MEMORYENTRY_HANDLE_INVALID, DEM_E_INCONSISTENT_STATE, FALSE)
  Dem_Internal_AssertReturnValue(CopyDidInfoPtr->EventId != DEM_EVENT_INVALID, DEM_E_INCONSISTENT_STATE, FALSE)

# if (DEM_FEATURE_NEED_AGING_REALLOCATION == STD_ON)
  if (DEM_MEM_TEST_AGING_ONLY(Dem_MemoryEntry_GetState(CopyDidInfoPtr->MemoryEntryId)) == TRUE)
  {
    lReturnValue = FALSE;
  }
  else
# endif
  {
    if (Dem_UDSStatus_Test_TFSLC(Dem_DTC_GetDTCStatus(CopyDidInfoPtr->EventId)) == TRUE)
    {
      lFdc = 127;
    }
    else
    {
      lFdc = (sint8)Dem_MemoryEntry_GetDebounceValueMax(CopyDidInfoPtr->MemoryEntryId);
    }
    if (CopyDidInfoPtr->BufferSize > CopyDidInfoPtr->WriteIndex)
    {
      CopyDidInfoPtr->DestinationBuffer[CopyDidInfoPtr->WriteIndex] = (uint8)lFdc;                                               /* SBSW_DEM_WRITE_DIDINFO_DESTINATIONBUFFER */
      CopyDidInfoPtr->WriteIndex += 1;                                                                                           /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    }
    lReturnValue = TRUE;
  }

  return lReturnValue;
}
#endif /* (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) && (DEM_CFG_DATA_MAX_FDC_SINCE_LAST_CLEAR == STD_ON) */

#if (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) && (DEM_CFG_DATA_MAX_FDC_DURING_CURRENT_CYCLE == STD_ON)
/* ****************************************************************************
 % Dem_Data_CopyMaxFdcThisCycle
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Data_CopyMaxFdcThisCycle(
  CONST(Dem_DataReportIF_CopyDidInfoPtrType, AUTOMATIC)  CopyDidInfoPtr
  )
{
  sint8 lFdc;

  Dem_Internal_AssertReturnValue(CopyDidInfoPtr->EventId != DEM_EVENT_INVALID, DEM_E_INCONSISTENT_STATE, FALSE)

  {
# if (DEM_CFG_SUPPORT_TYPE1_COMBINATION == STD_ON)
    Dem_Cfg_CombinedGroupIndexType lGroupId;
    lGroupId = Dem_Cfg_EventCombinedGroup(CopyDidInfoPtr->EventId);
    if (lGroupId != DEM_CFG_COMBINED_GROUP_INVALID)
    {
      lFdc = Dem_DTC_CombinedGroupGetFDCMax(lGroupId);
    }
    else
# endif
    {
      lFdc = Dem_Satellite_GetMaxFaultDetectionCounter(
          Dem_Cfg_EventSatelliteId(CopyDidInfoPtr->EventId),
          Dem_Cfg_EventSatelliteEventId(CopyDidInfoPtr->EventId)
          );
    }
  }

  if (CopyDidInfoPtr->BufferSize > CopyDidInfoPtr->WriteIndex)
  {
    CopyDidInfoPtr->DestinationBuffer[CopyDidInfoPtr->WriteIndex] = (uint8)lFdc;                                                 /* SBSW_DEM_WRITE_DIDINFO_DESTINATIONBUFFER */
    CopyDidInfoPtr->WriteIndex += 1;                                                                                             /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
  }

  return TRUE;
}
#endif /* (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) && (DEM_CFG_DATA_MAX_FDC_DURING_CURRENT_CYCLE == STD_ON) */

#if (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) && (DEM_CFG_DATA_CYCLES_SINCE_LAST_FAILED == STD_ON)
/* ****************************************************************************
 % Dem_Data_CopyCyclesSinceLastFailed
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
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Data_CopyCyclesSinceLastFailed(
  CONST(Dem_DataReportIF_CopyDidInfoPtrType, AUTOMATIC)  CopyDidInfoPtr
  )
{
  uint8 lCycleCounter;

  Dem_Internal_AssertReturnValue(CopyDidInfoPtr->MemoryEntryId != DEM_MEMORYENTRY_HANDLE_INVALID, DEM_E_INCONSISTENT_STATE, FALSE)
  Dem_Internal_AssertReturnValue(CopyDidInfoPtr->EventId != DEM_EVENT_INVALID, DEM_E_INCONSISTENT_STATE, FALSE)

  if (Dem_MemoryEntry_GetCyclesSinceLastFailed(CopyDidInfoPtr->MemoryEntryId) == DEM_OPCYCLE_CYCLECOUNT_INVALID)
  {
    lCycleCounter = 0x00U;
  }
  else
  if (Dem_MemoryEntry_GetCyclesSinceLastFailed(CopyDidInfoPtr->MemoryEntryId) == DEM_OPCYCLE_CYCLECOUNT_LATCHED)
  {
    lCycleCounter = 0xffU;
  }
  else
  {
    lCycleCounter = (uint8)Dem_OperationCycle_CycleCountDistance(
      Dem_MemoryEntry_GetCyclesSinceLastFailed(CopyDidInfoPtr->MemoryEntryId),
      Dem_OperationCycle_GetCycleCounter(Dem_Cfg_EventOperationCycle(CopyDidInfoPtr->EventId)));
  }

  if (CopyDidInfoPtr->BufferSize > CopyDidInfoPtr->WriteIndex)
  {
    CopyDidInfoPtr->DestinationBuffer[CopyDidInfoPtr->WriteIndex] = lCycleCounter;                                               /* SBSW_DEM_WRITE_DIDINFO_DESTINATIONBUFFER */
    CopyDidInfoPtr->WriteIndex += 1;                                                                                             /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
  }
  return TRUE;
}
#endif /* (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) && (DEM_CFG_DATA_CYCLES_SINCE_LAST_FAILED == STD_ON) */

#if (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) && (DEM_CFG_DATA_CYCLES_SINCE_FIRST_FAILED == STD_ON)
/* ****************************************************************************
 % Dem_Data_CopyCyclesSinceFirstFailed
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
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Data_CopyCyclesSinceFirstFailed(
  CONST(Dem_DataReportIF_CopyDidInfoPtrType, AUTOMATIC)  CopyDidInfoPtr
  )
{
  uint8 lCycleCounter;

  Dem_Internal_AssertReturnValue(CopyDidInfoPtr->MemoryEntryId != DEM_MEMORYENTRY_HANDLE_INVALID, DEM_E_INCONSISTENT_STATE, FALSE)
  Dem_Internal_AssertReturnValue(CopyDidInfoPtr->EventId != DEM_EVENT_INVALID, DEM_E_INCONSISTENT_STATE, FALSE)

  if (Dem_MemoryEntry_GetCyclesSinceFirstFailed(CopyDidInfoPtr->MemoryEntryId) == DEM_OPCYCLE_CYCLECOUNT_INVALID)
  {
    lCycleCounter = 0x00U;
  }
  else
  if (Dem_MemoryEntry_GetCyclesSinceFirstFailed(CopyDidInfoPtr->MemoryEntryId) == DEM_OPCYCLE_CYCLECOUNT_LATCHED)
  {
    lCycleCounter = 0xffU;
  }
  else
  {
    lCycleCounter = (uint8)Dem_OperationCycle_CycleCountDistance(
      Dem_MemoryEntry_GetCyclesSinceFirstFailed(CopyDidInfoPtr->MemoryEntryId),
      Dem_OperationCycle_GetCycleCounter(Dem_Cfg_EventOperationCycle(CopyDidInfoPtr->EventId)));
  }

  if (CopyDidInfoPtr->BufferSize > CopyDidInfoPtr->WriteIndex)
  {
    CopyDidInfoPtr->DestinationBuffer[CopyDidInfoPtr->WriteIndex] = lCycleCounter;                                               /* SBSW_DEM_WRITE_DIDINFO_DESTINATIONBUFFER */
    CopyDidInfoPtr->WriteIndex += 1;                                                                                             /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
  }
  return TRUE;
}
#endif /* (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) && (DEM_CFG_DATA_CYCLES_SINCE_FIRST_FAILED == STD_ON) */

#if (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) && (DEM_CFG_DATA_FAILED_CYCLES == STD_ON)
/* ****************************************************************************
 % Dem_Data_CopyFailedCycles
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Data_CopyFailedCycles(
  CONST(Dem_DataReportIF_CopyDidInfoPtrType, AUTOMATIC)  CopyDidInfoPtr
  )
{
  boolean lReturnValue;

  Dem_Internal_AssertReturnValue(CopyDidInfoPtr->MemoryEntryId != DEM_MEMORYENTRY_HANDLE_INVALID, DEM_E_INCONSISTENT_STATE, FALSE)

# if (DEM_FEATURE_NEED_AGING_REALLOCATION == STD_ON)
  if (DEM_MEM_TEST_AGING_ONLY(Dem_MemoryEntry_GetState(CopyDidInfoPtr->MemoryEntryId)) == TRUE)
  {
    lReturnValue = FALSE;
  }
  else
# endif
  {
    if (CopyDidInfoPtr->BufferSize > CopyDidInfoPtr->WriteIndex)
    {
      CopyDidInfoPtr->DestinationBuffer[CopyDidInfoPtr->WriteIndex] =                                                            /* SBSW_DEM_WRITE_DIDINFO_DESTINATIONBUFFER */
        Dem_MemoryEntry_GetFailedCycleCounter(CopyDidInfoPtr->MemoryEntryId);
      CopyDidInfoPtr->WriteIndex += 1;                                                                                           /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    }
    lReturnValue = TRUE;
  }

  return lReturnValue;
}
#endif /* (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) && (DEM_CFG_DATA_FAILED_CYCLES == STD_ON) */

#if (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) && (DEM_CFG_DATA_CONSECUTIVE_FAILED_CYCLES == STD_ON)
/* ****************************************************************************
 % Dem_Data_CopyConsecutiveFailedCycles
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Data_CopyConsecutiveFailedCycles(
  CONST(Dem_DataReportIF_CopyDidInfoPtrType, AUTOMATIC)  CopyDidInfoPtr
  )
{
  boolean lReturnValue;

  Dem_Internal_AssertReturnValue(CopyDidInfoPtr->MemoryEntryId != DEM_MEMORYENTRY_HANDLE_INVALID, DEM_E_INCONSISTENT_STATE, FALSE)

# if (DEM_FEATURE_NEED_AGING_REALLOCATION == STD_ON)
  if (DEM_MEM_TEST_AGING_ONLY(Dem_MemoryEntry_GetState(CopyDidInfoPtr->MemoryEntryId)) == TRUE)
  {
    lReturnValue = FALSE;
  }
  else
# endif
  {
    if (CopyDidInfoPtr->BufferSize > CopyDidInfoPtr->WriteIndex)
    {
      CopyDidInfoPtr->DestinationBuffer[CopyDidInfoPtr->WriteIndex] =                                                            /* SBSW_DEM_WRITE_DIDINFO_DESTINATIONBUFFER */
        Dem_MemoryEntry_GetConsecutiveFailedCycleCounter(CopyDidInfoPtr->MemoryEntryId);
      CopyDidInfoPtr->WriteIndex += 1;                                                                                           /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    }
    lReturnValue = TRUE;
  }

  return lReturnValue;
}
#endif /* (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) && (DEM_CFG_DATA_CONSECUTIVE_FAILED_CYCLES == STD_ON) */

#if (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) && (DEM_CFG_DATA_CYCLES_TESTED_SINCE_FIRST_FAILED == STD_ON)
/* ****************************************************************************
 % Dem_Data_CopyCyclesTestedSinceFirstFailed
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Data_CopyCyclesTestedSinceFirstFailed(
  CONST(Dem_DataReportIF_CopyDidInfoPtrType, AUTOMATIC)  CopyDidInfoPtr
  )
{
  boolean lReturnValue;

  Dem_Internal_AssertReturnValue(CopyDidInfoPtr->MemoryEntryId != DEM_MEMORYENTRY_HANDLE_INVALID, DEM_E_INCONSISTENT_STATE, FALSE)

# if (DEM_FEATURE_NEED_AGING_REALLOCATION == STD_ON)
  if (DEM_MEM_TEST_AGING_ONLY(Dem_MemoryEntry_GetState(CopyDidInfoPtr->MemoryEntryId)) == TRUE)
  {
    lReturnValue = FALSE;
  }
  else
# endif
  {
    if (CopyDidInfoPtr->BufferSize > CopyDidInfoPtr->WriteIndex)
    {
      CopyDidInfoPtr->DestinationBuffer[CopyDidInfoPtr->WriteIndex] =                                                            /* SBSW_DEM_WRITE_DIDINFO_DESTINATIONBUFFER */
        Dem_MemoryEntry_GetTestedCyclesSinceFirstFailed(CopyDidInfoPtr->MemoryEntryId);
      CopyDidInfoPtr->WriteIndex += 1;                                                                                           /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    }
    lReturnValue = TRUE;
  }

  return lReturnValue;
}
#endif /* (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) && (DEM_CFG_DATA_CYCLES_TESTED_SINCE_FIRST_FAILED == STD_ON) */

#if (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) && (DEM_CFG_DATA_CYCLES_TESTED_SINCE_LAST_FAILED == STD_ON)
/* ****************************************************************************
 % Dem_Data_CopyCyclesTestedSinceLastFailed
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
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Data_CopyCyclesTestedSinceLastFailed(
  CONST(Dem_DataReportIF_CopyDidInfoPtrType, AUTOMATIC)  CopyDidInfoPtr
  )
{
  uint8 lCyclesTestedSinceLastFailed;

  Dem_Internal_AssertReturnValue(CopyDidInfoPtr->EventId != DEM_EVENT_INVALID, DEM_E_INCONSISTENT_STATE, FALSE)
    
  if (Dem_Data_TestHealingCounterReadable(CopyDidInfoPtr->EventId) == TRUE)
  {
    lCyclesTestedSinceLastFailed = Dem_Event_GetTripCount(CopyDidInfoPtr->EventId);
  }
  else
  {
    lCyclesTestedSinceLastFailed = 0x00;
  }

  if (CopyDidInfoPtr->BufferSize > CopyDidInfoPtr->WriteIndex)
  {
    CopyDidInfoPtr->DestinationBuffer[CopyDidInfoPtr->WriteIndex] = lCyclesTestedSinceLastFailed;                                /* SBSW_DEM_WRITE_DIDINFO_DESTINATIONBUFFER */
    CopyDidInfoPtr->WriteIndex += 1;                                                                                             /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
  }

  return TRUE;
}
#endif /* (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) && (DEM_CFG_DATA_CYCLES_TESTED_SINCE_LAST_FAILED == STD_ON) */

#if (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) && (DEM_CFG_DATA_HEALINGCTR_DOWNCNT == STD_ON)
/* ****************************************************************************
 % Dem_Data_CopyHealingCounterDownwards
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
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Data_CopyHealingCounterDownwards(
  CONST(Dem_DataReportIF_CopyDidInfoPtrType, AUTOMATIC)  CopyDidInfoPtr
  )
{
  uint8 lHealingCounterInverted;

  Dem_Internal_AssertReturnValue(CopyDidInfoPtr->EventId != DEM_EVENT_INVALID, DEM_E_INCONSISTENT_STATE, FALSE)

  if (Dem_Data_TestHealingCounterReadable(CopyDidInfoPtr->EventId) == TRUE)
  {
    if (Dem_Event_GetTripCount(CopyDidInfoPtr->EventId) < Dem_Cfg_EventHealingTarget(CopyDidInfoPtr->EventId))
    {
      lHealingCounterInverted = Dem_Cfg_EventHealingTarget(CopyDidInfoPtr->EventId) - Dem_Event_GetTripCount(CopyDidInfoPtr->EventId);
    }
    else
    {
      lHealingCounterInverted = 0x00;
    }
  }
  else
  {
    lHealingCounterInverted = Dem_Cfg_EventHealingTarget(CopyDidInfoPtr->EventId);
  }

  if (CopyDidInfoPtr->BufferSize > CopyDidInfoPtr->WriteIndex)
  {
    CopyDidInfoPtr->DestinationBuffer[CopyDidInfoPtr->WriteIndex] = lHealingCounterInverted;                                     /* SBSW_DEM_WRITE_DIDINFO_DESTINATIONBUFFER */
    CopyDidInfoPtr->WriteIndex += 1;                                                                                             /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
  }

  return TRUE;
}
#endif /* (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) && (DEM_CFG_DATA_HEALINGCTR_DOWNCNT == STD_ON) */

#if (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) && (DEM_CFG_DATA_ROOTCAUSE_EVENTID == STD_ON)
/* ****************************************************************************
 % Dem_Data_CopyRootCauseEventId
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Data_CopyRootCauseEventId(
  CONST(Dem_DataReportIF_CopyDidInfoPtrType, AUTOMATIC)  CopyDidInfoPtr
  )
{
  Dem_Internal_AssertReturnValue(CopyDidInfoPtr->SourceBuffer != NULL_PTR, DEM_E_INCONSISTENT_STATE, FALSE)

  if (CopyDidInfoPtr->BufferSize >= (CopyDidInfoPtr->WriteIndex + 2))
  {
    CopyDidInfoPtr->DestinationBuffer[CopyDidInfoPtr->WriteIndex + 0] = CopyDidInfoPtr->SourceBuffer[CopyDidInfoPtr->ReadIndex + 0];  /* SBSW_DEM_WRITE_DIDINFO_DESTINATIONBUFFER */
    CopyDidInfoPtr->DestinationBuffer[CopyDidInfoPtr->WriteIndex + 1] = CopyDidInfoPtr->SourceBuffer[CopyDidInfoPtr->ReadIndex + 1];  /* SBSW_DEM_WRITE_DIDINFO_DESTINATIONBUFFER */
    CopyDidInfoPtr->ReadIndex += 2;                                                                                              /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    CopyDidInfoPtr->WriteIndex += 2;                                                                                             /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
  }
  return TRUE;
}
#endif /* (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) && (DEM_CFG_DATA_ROOTCAUSE_EVENTID == STD_ON) */

#if (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) && (DEM_CFG_DATA_OBDDTC == STD_ON)
/* ****************************************************************************
 % Dem_Data_CopyEventObdDtc
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Data_CopyEventObdDtc(
  CONST(Dem_DataReportIF_CopyDidInfoPtrType, AUTOMATIC)  CopyDidInfoPtr
  )
{
  Dem_Internal_AssertReturnValue(CopyDidInfoPtr->EventId != DEM_EVENT_INVALID, DEM_E_INCONSISTENT_STATE, FALSE)

  if (CopyDidInfoPtr->BufferSize >= (CopyDidInfoPtr->WriteIndex + 2))
  {
    CopyDidInfoPtr->DestinationBuffer[CopyDidInfoPtr->WriteIndex + 0] = Dem_GetHiByte(Dem_Cfg_EventObdDtc(CopyDidInfoPtr->EventId));  /* SBSW_DEM_WRITE_DIDINFO_DESTINATIONBUFFER */
    CopyDidInfoPtr->DestinationBuffer[CopyDidInfoPtr->WriteIndex + 1] = Dem_GetLoByte(Dem_Cfg_EventObdDtc(CopyDidInfoPtr->EventId));  /* SBSW_DEM_WRITE_DIDINFO_DESTINATIONBUFFER */
    CopyDidInfoPtr->WriteIndex += 2;                                                                                             /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
  }
  return TRUE;
}
#endif /* (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) && (DEM_CFG_DATA_OBDDTC == STD_ON) */

#if (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) && (DEM_CFG_DATA_OBDDTC_3BYTE == STD_ON)
/* ****************************************************************************
 % Dem_Data_CopyEventObdDtc_3Byte
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Data_CopyEventObdDtc_3Byte(
  CONST(Dem_DataReportIF_CopyDidInfoPtrType, AUTOMATIC)  CopyDidInfoPtr
  )
{
  Dem_Internal_AssertReturnValue(CopyDidInfoPtr->EventId != DEM_EVENT_INVALID, DEM_E_INCONSISTENT_STATE, FALSE)

  if (CopyDidInfoPtr->BufferSize >= (CopyDidInfoPtr->WriteIndex + 3))
  {
    CopyDidInfoPtr->DestinationBuffer[CopyDidInfoPtr->WriteIndex + 0] = Dem_GetHiByte(Dem_Cfg_EventObdDtc(CopyDidInfoPtr->EventId));  /* SBSW_DEM_WRITE_DIDINFO_DESTINATIONBUFFER */
    CopyDidInfoPtr->DestinationBuffer[CopyDidInfoPtr->WriteIndex + 1] = Dem_GetLoByte(Dem_Cfg_EventObdDtc(CopyDidInfoPtr->EventId));  /* SBSW_DEM_WRITE_DIDINFO_DESTINATIONBUFFER */
    CopyDidInfoPtr->DestinationBuffer[CopyDidInfoPtr->WriteIndex + 2] = 0x00;                                                    /* SBSW_DEM_WRITE_DIDINFO_DESTINATIONBUFFER */
    CopyDidInfoPtr->WriteIndex += 3;                                                                                             /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
  }
  return TRUE;
}
#endif /* (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) && (DEM_CFG_DATA_OBDDTC == STD_ON) */

#if (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) && (DEM_CFG_DATA_OBD_RATIO == STD_ON)
/* ****************************************************************************
 % Dem_Data_CopyEventObdRatio
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Data_CopyEventObdRatio(
  CONST(Dem_DataReportIF_CopyDidInfoPtrType, AUTOMATIC)  CopyDidInfoPtr
  )
{
  Dem_Internal_AssertReturnValue(CopyDidInfoPtr->EventId != DEM_EVENT_INVALID, DEM_E_INCONSISTENT_STATE, FALSE)

  if (CopyDidInfoPtr->BufferSize >= (CopyDidInfoPtr->WriteIndex + 4))
  {
# if (DEM_CFG_SUPPORT_IUMPR == STD_ON)
    Dem_RatioIdIndexType  lRatioIndex;
    lRatioIndex = Dem_Cfg_EventRatioIdIdx(CopyDidInfoPtr->EventId);

    if ( (lRatioIndex != DEM_CFG_RATIOINDEX_INVALID)                                                                             /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
      && (Dem_Cfg_EventIsCombined(CopyDidInfoPtr->EventId) == FALSE)
       )
    {
      uint16 lNumerator;
      uint16 lDenominator;

      lDenominator = Dem_Mem_GetDenominator(lRatioIndex);
      lNumerator = Dem_Mem_GetNumerator(lRatioIndex);

      CopyDidInfoPtr->DestinationBuffer[CopyDidInfoPtr->WriteIndex + 0] = Dem_GetHiByte(lNumerator);
      CopyDidInfoPtr->DestinationBuffer[CopyDidInfoPtr->WriteIndex + 1] = Dem_GetLoByte(lNumerator);
      CopyDidInfoPtr->DestinationBuffer[CopyDidInfoPtr->WriteIndex + 2] = Dem_GetHiByte(lDenominator);
      CopyDidInfoPtr->DestinationBuffer[CopyDidInfoPtr->WriteIndex + 3] = Dem_GetLoByte(lDenominator);
    }
    else
# endif
    {
      CopyDidInfoPtr->DestinationBuffer[CopyDidInfoPtr->WriteIndex + 0] = 0x00;
      CopyDidInfoPtr->DestinationBuffer[CopyDidInfoPtr->WriteIndex + 1] = 0x00;
      CopyDidInfoPtr->DestinationBuffer[CopyDidInfoPtr->WriteIndex + 2] = 0x00;
      CopyDidInfoPtr->DestinationBuffer[CopyDidInfoPtr->WriteIndex + 3] = 0x00;
    }
    CopyDidInfoPtr->WriteIndex += 4;                                                                                             /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
  }
  return TRUE;
}
#endif

#if (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) && (DEM_CFG_DATA_CURRENT_FDC == STD_ON)
/* ****************************************************************************
 % Dem_Data_CopyCurrentFdc
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Data_CopyCurrentFdc(
  CONST(Dem_DataReportIF_CopyDidInfoPtrType, AUTOMATIC)  CopyDidInfoPtr
  )
{
  boolean lReturnValue;
  sint8 lFdc;

  Dem_Internal_AssertReturnValue(CopyDidInfoPtr->EventId != DEM_EVENT_INVALID, DEM_E_INCONSISTENT_STATE, FALSE)

  lReturnValue = (boolean)(E_OK == Dem_DTC_GetFaultDetectionCounter(CopyDidInfoPtr->EventId, &lFdc));                        /* SBSW_DEM_POINTER_FORWARD_STACK */
  if (lReturnValue == TRUE)
  {
    if (CopyDidInfoPtr->BufferSize > CopyDidInfoPtr->WriteIndex)
    {
      CopyDidInfoPtr->DestinationBuffer[CopyDidInfoPtr->WriteIndex] = (uint8)lFdc;                                               /* SBSW_DEM_WRITE_DIDINFO_DESTINATIONBUFFER */
      CopyDidInfoPtr->WriteIndex += 1;                                                                                           /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    }
  }

  return lReturnValue;
}
#endif /* (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) && (DEM_CFG_DATA_CURRENT_FDC == STD_ON) */

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* DEM_DATA_IMPLEMENTATION_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_Data_Implementation.h
 *********************************************************************************************************************/
