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
/*! \addtogroup Dem_Memory
 *  \{
 *  \file       Dem_Memory_Implementation.h
 *  \brief      Abstraction for multiple event memories.
 *  \details    Facade for all memory related tasks.
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

#if !defined (DEM_MEMORY_IMPLEMENTATION_H)
#define DEM_MEMORY_IMPLEMENTATION_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                  /* Own subcomponent header */
/* ------------------------------------------------------------------------- */
#include "Dem_Memory_Interface.h"

                                                    /* Used subcomponent API */
/* ------------------------------------------------------------------------- */
#include "Dem_MemStorageManager_Implementation.h"
#include "Dem_MemAccess_Implementation.h"
#include "Dem_MemState_Implementation.h"
#include "Dem_MemoryEntry_Implementation.h"
#include "Dem_Mem_Implementation.h"
#include "Dem_Nvm_Implementation.h"

                                                   /* Subcomponents callbacks*/
/* ------------------------------------------------------------------------- */
#include "Dem_Event_Interface.h"
#include "Dem_DTC_Interface.h"
#include "Dem_DTCInternalStatus_Interface.h"
#include "Dem_UDSStatus_Interface.h"
#include "Dem_Error_Interface.h"

/* ********************************************************************************************************************
 *  SUBCOMPONENT CONSTANT MACROS
 *********************************************************************************************************************/

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
 * \addtogroup Dem_Memory_Properties
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
 * \addtogroup Dem_Memory_Private
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
 * \addtogroup Dem_Memory_Public
 * \{
 */

/* ****************************************************************************
 % Dem_Memory_Init_RestoreMemory
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
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
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
Dem_Memory_Init_RestoreMemory(
  CONST(Dem_Mem_MemoryInfoPtrType, AUTOMATIC)  MemoryInfo
  )
{ /* No reinitialization - restore primary stack */
  Dem_Cfg_MemoryIndexType lMemoryIndex;

  Dem_MemStorageManager_MemorySetCurrentSize(MemoryInfo, 0);                                                                     /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */

  /* Iterate through all memory entries. The iteration order must be identical to Dem_MemStorageManager_MemoryFindIndex. */
  for (lMemoryIndex = Dem_MemStorageManager_MemoryIter_Begin(MemoryInfo);                                                        /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
       lMemoryIndex < Dem_MemStorageManager_MemoryIter_End(MemoryInfo);                                                          /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
       ++lMemoryIndex)
  {
    Dem_MemoryEntry_HandleType lMemoryEntryId;
    Dem_EventIdType lEventId;

    lMemoryEntryId = Dem_MemStorageManager_GetMemoryEntryId(lMemoryIndex);
    lEventId = Dem_MemoryEntry_GetEventId(lMemoryEntryId);
    if (lEventId != DEM_EVENT_INVALID)
    {
      uint32 lTimestamp;
      uint8 lSortedIndex;
      Dem_Event_InternalStatusType lInternalStatus;

      if ( (lEventId >= Dem_Cfg_GlobalEventCount())                                                                              /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
        || (Dem_Cfg_EventDestination(lEventId) != Dem_MemStorageManager_MemoryGetId(MemoryInfo))                                 /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
#if (DEM_CFG_SUPPORT_TYPE1_COMBINATION == STD_ON)
        || (lEventId != Dem_Cfg_GetMasterEvent(lEventId))
#endif
        )
      {
        /* The memory entry is not allocated to the master event. Remove it. */
        Dem_MemoryEntry_SetEventId(lMemoryEntryId, DEM_EVENT_INVALID);
        Dem_MemoryEntry_SetTimestamp(lMemoryEntryId, 0U);
        Dem_Nvm_SetMemoryBlockState(Dem_MemStorageManager_GetNvBlockType(lMemoryIndex),
                                    Dem_MemStorageManager_GetEntryIndex(lMemoryIndex),
                                    DEM_NVM_BLOCKSTATE_DIRTYCLEAREDIMMEDIATE);

        /* DET: To get this inconsistency, it requires a configuration change without clearing the NV contents */
        Dem_Error_ReportError(DEM_INIT_APIID, DEM_E_INCONSISTENT_STATE);
        continue;                                                                                                                /* PRQA S 0770 */ /* MD_DEM_14.5 */                                                                                                              /* PRQA S 0770 */ /* MD_DEM_14.5 */
      }

      lInternalStatus = Dem_DTC_GetInternalStatus(lEventId);
      lTimestamp = Dem_MemoryEntry_GetTimestamp(lMemoryEntryId);

      if (Dem_DTCInternalStatus_GetStoredStatus(lInternalStatus) != Dem_DTCInternalStatus_StoredStatus_None)
      { /* Runtime error, no DET. This can happen due to NV errors */
        uint8 lOtherIndex;

        /* Dem_MemStorageManager_MemoryFindIndex will always succeed since we are processing a duplicate */
        lOtherIndex = Dem_MemStorageManager_MemoryFindIndex_Checked(MemoryInfo, lEventId);                                       /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */

        /* Clear the older entry */
        if (Dem_MemoryEntry_GetTimestamp(Dem_MemStorageManager_GetMemoryEntryId(lOtherIndex)) < lTimestamp)
        {
          Dem_MemAccess_MemoryFreeIndex(MemoryInfo, lOtherIndex);                                                                /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
          Dem_Nvm_SetMemoryBlockState(Dem_MemStorageManager_GetNvBlockType(lOtherIndex),
                                      Dem_MemStorageManager_GetEntryIndex(lOtherIndex),
                                      DEM_NVM_BLOCKSTATE_DIRTYCLEAREDIMMEDIATE);
        }
        else
        {
          Dem_MemoryEntry_SetEventId(lMemoryEntryId, DEM_EVENT_INVALID);
          Dem_MemoryEntry_SetTimestamp(lMemoryEntryId, 0U);
          Dem_Nvm_SetMemoryBlockState(Dem_MemStorageManager_GetNvBlockType(lMemoryIndex),
                                      Dem_MemStorageManager_GetEntryIndex(lMemoryIndex),
                                      DEM_NVM_BLOCKSTATE_DIRTYCLEAREDIMMEDIATE);
          continue;                                                                                                              /* PRQA S 0770 */ /* MD_DEM_14.5 */
        }
      }

#if (DEM_CFG_SUPPORT_TYPE1_COMBINATION == STD_ON)
      if (DEM_CFG_COMBINED_GROUP_INVALID == Dem_Cfg_EventCombinedGroup(lEventId))
#endif
      {
        uint8 lEventStatus;
        lEventStatus = Dem_Event_GetUDSStatus(lEventId);

#if (DEM_CFG_AGING_RETAIN_MEMORY_ENTRY == STD_ON)
        if (Dem_MemoryEntry_GetAgingCounter(lMemoryEntryId) == DEM_OPCYCLE_CYCLECOUNT_AGED)
        {
          /* The DTC has already aged. Unless storage happens at ConfirmedDTC, make sure TF is not set */
# if (DEM_CFG_STORAGE_AT_CONFIRMED != STD_ON)
          lEventStatus = Dem_UDSStatus_Reset_TF(lEventStatus);
# endif
        }
        else
#endif
        {
#if (DEM_CFG_STORAGE_AT_FDC == STD_ON)
# if (DEM_CFG_DATA_CONSECUTIVE_FAILED_CYCLES == STD_ON)
          if (Dem_MemoryEntry_GetConsecutiveFailedCycleCounter(lMemoryEntryId) > 0)
          {
            /* The last n cycles had TFTOC set -> Make sure PDTC and TFSLC are set */
            lEventStatus = Dem_UDSStatus_Set_TFSLC(lEventStatus);
            lEventStatus = Dem_UDSStatus_Set_PDTC(lEventStatus);
          }
          if (Dem_MemoryEntry_GetConsecutiveFailedCycleCounter(lMemoryEntryId) > Dem_Cfg_EventTripTarget(lEventId))
          {
            /* With the trip target exceeded, make sure CDTC is set */
            lEventStatus = Dem_UDSStatus_Set_CDTC(lEventStatus);
          }
# elif (DEM_CFG_DATA_OCCCTR_2BYTE == STD_ON)
          if (Dem_MemoryEntry_GetOccurrenceCounter2Byte(lMemoryEntryId) > 0)
          {
            /* We know about some TF 0->1 transitions -> make sure TFSLC is set */
            lEventStatus = Dem_UDSStatus_Set_TFSLC(lEventStatus);
          }
# elif (DEM_CFG_DATA_OCCCTR == STD_ON)
          if (Dem_MemoryEntry_GetOccurrenceCounter(lMemoryEntryId) > 0)
          {
            /* We know about some TF 0->1 transitions -> make sure TFSLC is set */
            lEventStatus = Dem_UDSStatus_Set_TFSLC(lEventStatus);
          }
# endif
#elif (DEM_CFG_STORAGE_AT_CONFIRMED == STD_ON)
          /* Since DTCs are stored only on confirmed, make sure CDTC and TFSLC are set */
          lEventStatus = Dem_UDSStatus_Set_TFSLC(lEventStatus);
          lEventStatus = Dem_UDSStatus_Set_CDTC(lEventStatus);
# if (DEM_CFG_DATA_CONSECUTIVE_FAILED_CYCLES == STD_ON)
          if (Dem_MemoryEntry_GetConsecutiveFailedCycleCounter(lMemoryEntryId) > 0)
          {
            /* If there are consecutive failed cycles > 0 make sure PDTC is set */
            lEventStatus = Dem_UDSStatus_Set_PDTC(lEventStatus);
          }
# endif
#else
          /* Make sure TFSCL is set */
          lEventStatus = Dem_UDSStatus_Set_TFSLC(lEventStatus);
# if (DEM_CFG_DATA_CONSECUTIVE_FAILED_CYCLES == STD_ON)
          if (Dem_MemoryEntry_GetConsecutiveFailedCycleCounter(lMemoryEntryId) > 0)
          { /* Make sure PDTC is set when the last cycle(s) were failed */
            lEventStatus = Dem_UDSStatus_Set_PDTC(lEventStatus);
          }
          if (Dem_MemoryEntry_GetConsecutiveFailedCycleCounter(lMemoryEntryId) > Dem_Cfg_EventTripTarget(lEventId))
          {
            lEventStatus = Dem_UDSStatus_Set_CDTC(lEventStatus);
          }
# else
          if (Dem_Cfg_EventTripTarget(lEventId) == 0)
          {
            lEventStatus = Dem_UDSStatus_Set_CDTC(lEventStatus);
          }
# endif
#endif
        }
        Dem_Event_SetUDSStatus(lEventId, lEventStatus);
      }

      /* If the memory entry is currently aging, mark the event as AGING */
      if ( (Dem_MemoryEntry_GetAgingCounter(lMemoryEntryId) <= DEM_OPCYCLE_CYCLECOUNT_MAX)                                           /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
        || (Dem_MemoryEntry_GetAgingCounter(lMemoryEntryId) == DEM_OPCYCLE_CYCLECOUNT_LATCHED) )
      {
        lInternalStatus = Dem_DTCInternalStatus_SetStoredStatus(lInternalStatus, Dem_DTCInternalStatus_StoredStatus_Aging);
      }
      else
#if (DEM_CFG_AGING_RETAIN_MEMORY_ENTRY == STD_ON)
      /* If aging keeps memory entries intact and the entry is aged, mark the event as AGED */
      if (Dem_MemoryEntry_GetAgingCounter(lMemoryEntryId) == DEM_OPCYCLE_CYCLECOUNT_AGED)
      {
        lInternalStatus = Dem_DTCInternalStatus_SetStoredStatus(lInternalStatus, Dem_DTCInternalStatus_StoredStatus_Aged);
      }
      else
#endif
      {
        lInternalStatus = Dem_DTCInternalStatus_SetStoredStatus(lInternalStatus, Dem_DTCInternalStatus_StoredStatus_Active);
      }

      Dem_DTC_SetInternalStatus(lEventId, lInternalStatus);

      /* Synchronize the global timestamp with the timestamp stored in the memory entry */
      if (lTimestamp > Dem_Mem_CurrentTimestamp)
      {
        Dem_Mem_CurrentTimestamp = lTimestamp;
      }

      /* Sort the memory entry into the chronological list */
      for (
        lSortedIndex = Dem_MemStorageManager_MemoryGetCurrentSize(MemoryInfo);                                                   /* PRQA S 3415 */ /* MD_DEM_12.4_cf */ /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
        (lSortedIndex > 0)
          && (Dem_MemoryEntry_GetTimestamp(Dem_MemStorageManager_GetMemoryEntryId(
                                               Dem_MemStorageManager_MemoryGetChronology(MemoryInfo, lSortedIndex - 1)))         /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
                > lTimestamp);                                                                                                   /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
        --lSortedIndex
      )
      {
        Dem_MemStorageManager_MemorySetChronology(
          MemoryInfo,                                                                                                            /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
          lSortedIndex,
          Dem_MemStorageManager_MemoryGetChronology(MemoryInfo, lSortedIndex - 1));                                              /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
      }

      Dem_MemStorageManager_MemorySetChronology(MemoryInfo, lSortedIndex, lMemoryIndex);                                         /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */

      /* Update the number of occupied memory entries */
      Dem_MemStorageManager_MemorySetCurrentSize(MemoryInfo, (uint8)(Dem_MemStorageManager_MemoryGetCurrentSize(MemoryInfo) + 1)); /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */ /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
    }
  }
  /* Update the global timestamp */
  ++Dem_Mem_CurrentTimestamp;
}                                                                                                                                /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* ****************************************************************************
 % Dem_Memory_EventFailed
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
Dem_Memory_EventFailed(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(uint8, AUTOMATIC)  Effects
  )
{
  if ( (EventId >= Dem_Cfg_GlobalPrimaryFirst())                                                                                 /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
    && (EventId <= Dem_Cfg_GlobalPrimaryLast()) )
  {
    if ((Effects & DEM_CFG_TRIGGER_CONFIRMED) != 0)
    {
      if (Dem_Mem_GetFirstConfirmedEvent() == DEM_EVENT_INVALID)
      {
        Dem_Mem_SetFirstConfirmedEvent(EventId);
      }

      Dem_Mem_SetMostRecentConfmdEvent(EventId);
    }

    if (Dem_Mem_GetFirstFailedEvent() == DEM_EVENT_INVALID)
    {
      Dem_Mem_SetFirstFailedEvent(EventId);
    }
    Dem_Mem_SetMostRecentFailedEvent(EventId);
  }
}

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* DEM_MEMORY_IMPLEMENTATION_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_Memory_Implementation.h
 *********************************************************************************************************************/
