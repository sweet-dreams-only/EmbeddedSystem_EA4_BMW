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
/*! \addtogroup Dem_MemAccess
 *  \{
 *  \file       Dem_MemAccess_Implementation.h
 *  \brief      Basic routines for event memories.
 *  \details    In general, returns a memory entry or allows queries concerning the whole event memory
 *              - knows how much memory entries are available, handles etc.
 *              - find free memory entries (concern also displacement and aging)
 *              - allocate memory entries
 *              - free memory entries.
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

#if !defined (DEM_MEMACCESS_IMPLEMENTATION_H)
#define DEM_MEMACCESS_IMPLEMENTATION_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                  /* Own subcomponent header */
/* ------------------------------------------------------------------------- */
#include "Dem_MemAccess_Interface.h"

                                                    /* Used subcomponent API */
/* ------------------------------------------------------------------------- */
#include "Dem_Nvm_Implementation.h"
#include "Dem_Mem_Implementation.h"
#include "Dem_OperationCycle_Implementation.h"
#include "Dem_MemStorageManager_Implementation.h"
#include "Dem_MemoryEntry_Implementation.h"
#include "Dem_DTC_Interface.h"
#include "Dem_UDSStatus_Implementation.h"
#include "Dem_DTCInternalStatus_Implementation.h"

                                                   /* Subcomponents callbacks*/
/* ------------------------------------------------------------------------- */
#include "Dem_Event_Interface.h"
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
 * \addtogroup Dem_MemAccess_Properties
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
 * \addtogroup Dem_MemAccess_Private
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
 * \addtogroup Dem_MemAccess_Public
 * \{
 */

 #if ((DEM_FEATURE_NEED_OEM_EXTENSIONS_VCC == STD_OFF) && (DEM_CFG_SUPPORT_DISPLACEMENT == STD_ON))
/* ****************************************************************************
 % Dem_MemAccess_SelectDisplacedIndex
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
DEM_LOCAL FUNC(uint8, DEM_CODE)
Dem_MemAccess_SelectDisplacedIndex(
  CONST(Dem_Mem_MemoryInfoPtrType, AUTOMATIC)  MemoryInfo,
  CONST(Dem_EventIdType, AUTOMATIC)  DisplacingEventId
  )
{
  struct DisplacementInfoType
  {
    uint16                   EventId;
    Dem_Cfg_MemoryIndexType  MemoryIndex;
    uint8                    DtcStatus;
  } lBestMatchInfo;

  uint8 lChronoIndexIterator;
# if (DEM_CFG_SUPPORT_OBDII == STD_ON)                                                                                           /* COV_MSR_UNSUPPORTED XF */
#  if (DEM_CFG_DISPLACEMENT_FALLBACK_OLDEST == STD_ON)
  uint8 lOldestDisplaceableIndex;
#  endif
# endif

  lBestMatchInfo.EventId = DisplacingEventId;
  lBestMatchInfo.MemoryIndex = DEM_MEM_INVALID_MEMORY_INDEX;
  lBestMatchInfo.DtcStatus = DEM_UDS_STATUS_TF;

  DEM_IGNORE_UNUSED_VARIABLE(lBestMatchInfo.DtcStatus)                                                                           /* PRQA S 3112, 3198 */ /* MD_DEM_14.2, MD_DEM_3198 */

# if (DEM_CFG_SUPPORT_OBDII == STD_ON)                                                                                           /* COV_MSR_UNSUPPORTED XF */
#  if (DEM_CFG_DISPLACEMENT_FALLBACK_OLDEST == STD_ON)
    lOldestDisplaceableIndex = DEM_MEM_INVALID_MEMORY_INDEX;
#  endif
# endif

  /* find lowest priority DTC in memory. scan in chronological order, so the
  first found entry is the older one (to break ties) */
  for (lChronoIndexIterator = 0;
       lChronoIndexIterator < Dem_MemStorageManager_MemoryGetCurrentSize(MemoryInfo);                                            /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
       ++lChronoIndexIterator)
  {
    struct DisplacementInfoType lCandidateInfo;
# if (DEM_CFG_AGING_RETAIN_MEMORY_ENTRY == STD_ON) || (DEM_FEATURE_NEED_AGING_REALLOCATION == STD_ON)
    Dem_Cfg_MemoryIndexType lMemoryIndex;
# endif

    lCandidateInfo.MemoryIndex = Dem_MemStorageManager_MemoryGetChronology(MemoryInfo, lChronoIndexIterator);                    /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
    {
# if (DEM_CFG_AGING_RETAIN_MEMORY_ENTRY == STD_ON) || (DEM_FEATURE_NEED_AGING_REALLOCATION == STD_ON)
      lMemoryIndex = lCandidateInfo.MemoryIndex;
# endif
      lCandidateInfo.EventId = Dem_MemoryEntry_GetEventId(Dem_MemStorageManager_GetMemoryEntryId(lCandidateInfo.MemoryIndex));
    }
    lCandidateInfo.DtcStatus = Dem_DTC_ApplyCombinedStatus(Dem_DTC_GetDTCStatus(lCandidateInfo.EventId));

    if (Dem_Event_TestValidHandle(lCandidateInfo.EventId) == FALSE)
    {
      /* always replace an invalid memory entry */
      lBestMatchInfo = lCandidateInfo;
      break;                                                                                                                     /* PRQA S 0771 */ /* MD_DEM_14.6_opt */
    }

# if (DEM_CFG_AGING_RETAIN_MEMORY_ENTRY == STD_ON)
    if (
#  if (DEM_FEATURE_NEED_TIME_SERIES == STD_ON)
      (lMemoryIndex != DEM_MEM_INVALID_MEMORY_INDEX) &&                                                                          /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
#  endif
      (Dem_MemoryEntry_GetAgingCounter(Dem_MemStorageManager_GetMemoryEntryId(lMemoryIndex)) == DEM_OPCYCLE_CYCLECOUNT_AGED))
    { /* aged event can be displaced immediately */
      lBestMatchInfo = lCandidateInfo;
      break;                                                                                                                     /* PRQA S 0771 */ /* MD_DEM_14.6_opt */
    }
# endif /* (DEM_CFG_AGING_RETAIN_MEMORY_ENTRY == STD_ON) */
# if (DEM_FEATURE_NEED_AGING_REALLOCATION == STD_ON)
    if (
#  if (DEM_FEATURE_NEED_TIME_SERIES == STD_ON)
      (lMemoryIndex != DEM_MEM_INVALID_MEMORY_INDEX) &&
#  endif
      (DEM_MEM_TEST_AGING_ONLY(Dem_MemoryEntry_GetState(Dem_MemStorageManager_GetMemoryEntryId(lMemoryIndex))) == TRUE) )
    { /* aging counter can be displaced immediately */
      lBestMatchInfo = lCandidateInfo;
      break;                                                                                                                     /* PRQA S 0771 */ /* MD_DEM_14.6_opt */
    }
# endif /* (DEM_FEATURE_NEED_AGING_REALLOCATION == STD_ON) */

    if (Dem_Cfg_EventPriority(lCandidateInfo.EventId) < Dem_Cfg_EventPriority(lBestMatchInfo.EventId))
    { /* Never displace events with higher priority */
      continue;                                                                                                                  /* PRQA S 0770 */ /* MD_DEM_14.5 */
    }
    if (Dem_Cfg_EventPriority(lCandidateInfo.EventId) > Dem_Cfg_EventPriority(lBestMatchInfo.EventId))
    { /* always prefer an event with lowest priority */
      lBestMatchInfo = lCandidateInfo;
      continue;                                                                                                                  /* PRQA S 0770 */ /* MD_DEM_14.5 */
    }

# if (DEM_CFG_SUPPORT_OBDII == STD_ON)                                                                                           /* COV_MSR_UNSUPPORTED XF */
    /* ignore stored events which are emission related AND
    (having stored the OBD FreezeFrame OR are pending OR having bit7 set) */
    if ( (Dem_Mem_FreezeFrameIndexMode02  != Dem_Cfg_GlobalObdIIFFCount())
      && (lCandidateInfo.EventId == Dem_Mem_FreezeFrameGetEvent(Dem_Mem_FreezeFrameIndexMode02)) )
    { /* stored event id is visible in Mode02 -> skip */
      continue;                                                                                                                  /* PRQA S 0770 */ /* MD_DEM_14.5 */
    }
    if ((Dem_Cfg_EventObdRelated(lCandidateInfo.EventId) == TRUE)                                                                /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
      && ((Dem_UDSStatus_Test_PDTC(lCandidateInfo.DtcStatus) == TRUE)
      || (Dem_UDSStatus_Test_WIR(lCandidateInfo.DtcStatus) == TRUE)
      ))
    {
      continue;                                                                                                                  /* PRQA S 0770 */ /* MD_DEM_14.5 */
    }
#  if (DEM_CFG_DISPLACEMENT_FALLBACK_OLDEST == STD_ON)
    if (lOldestDisplaceableIndex == DEM_MEM_INVALID_MEMORY_INDEX)
    { /* no oldest displaceable index identified yet */
      lOldestDisplaceableIndex = lCandidateInfo.MemoryIndex;
    }
#  endif
# endif /* (DEM_CFG_SUPPORT_OBDII == STD_ON) */

# if (DEM_CFG_DISPLACEMENT_PREFER_PASSIVE == STD_ON)
    /* Compiler warning: condition is always false if no prior condition is enabled to set new best match */
    if (Dem_UDSStatus_Test_TF(lBestMatchInfo.DtcStatus) == FALSE)
    { /* If current best candidate is passive, it is a better match as it is older */
      continue;                                                                                                                  /* PRQA S 0770 */ /* MD_DEM_14.5 */
    }
    if (Dem_UDSStatus_Test_TF(lCandidateInfo.DtcStatus) == FALSE)
    { /* did not find a passive event before, so candidate is a better match */
      lBestMatchInfo = lCandidateInfo;
      continue;                                                                                                                  /* PRQA S 0770 */ /* MD_DEM_14.5 */
    }
# endif /* DEM_CFG_DISPLACEMENT_PREFER_PASSIVE == STD_ON */

# if (DEM_CFG_DISPLACEMENT_TNCTOC_IS_PASSIVE == STD_ON)
    if ( (Dem_UDSStatus_Test_TNCTOC(lBestMatchInfo.DtcStatus) == FALSE)                                                          /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
      && (Dem_UDSStatus_Test_TNCTOC(lCandidateInfo.DtcStatus) == TRUE) )
    {
      lBestMatchInfo = lCandidateInfo;
      continue;                                                                                                                  /* PRQA S 0770 */ /* MD_DEM_14.5 */
    }
# endif /* (DEM_CFG_DISPLACEMENT_TNCTOC_IS_PASSIVE == STD_ON) */
  }
# if (DEM_CFG_DISPLACEMENT_FALLBACK_OLDEST == STD_ON)
  if (lBestMatchInfo.EventId == DisplacingEventId)
  { /* no match found - use fallback */
    /* The oldest event can be always displaced (could be DEM_MEM_INVALID_MEMORY_INDEX!) */
#  if (DEM_CFG_SUPPORT_OBDII == STD_ON)                                                                                          /* COV_MSR_UNSUPPORTED XF */
    lBestMatchInfo.MemoryIndex = lOldestDisplaceableIndex;
#  else
    lBestMatchInfo.MemoryIndex = Dem_MemStorageManager_MemoryGetChronology(MemoryInfo, 0);                                       /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
#  endif
  }
# endif /* (DEM_CFG_DISPLACEMENT_FALLBACK_OLDEST == STD_ON) */

  return lBestMatchInfo.MemoryIndex;
}                                                                                                                                /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
#endif /* (DEM_FEATURE_NEED_OEM_EXTENSIONS_VCC == STD_OFF) && (DEM_CFG_SUPPORT_DISPLACEMENT == STD_ON) */

#if (DEM_FEATURE_NEED_OEM_EXTENSIONS_VCC == STD_ON)
/* ****************************************************************************
 % Dem_MemAccess_SelectDisplacedIndex_Vcc
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
Dem_MemAccess_SelectDisplacedIndex_Vcc(
  CONST(Dem_Mem_MemoryInfoPtrType, AUTOMATIC)  MemoryInfo,
  CONST(Dem_EventIdType, AUTOMATIC)  DisplacingEventId                                                                           /* PRQA S 3206 */ /* MD_DEM_3206 */
  )
{
  uint8 lDisplacedIndex;
  uint8 lChronoIndexIterator;

#if (DEM_CFG_SUPPORT_DISPLACEMENT == STD_ON)
  uint8 lLowestPrioIndex;
  uint8 lLowestPrio;
#endif

  /* Can be unused depending on configuration */
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(DisplacingEventId)                                                                            /* PRQA S 3112 */ /* MD_DEM_14.2 */

#if (DEM_CFG_SUPPORT_DISPLACEMENT == STD_ON)
  lLowestPrio = Dem_Cfg_EventPriority(DisplacingEventId);
  lLowestPrioIndex = DEM_MEM_INVALID_MEMORY_INDEX;
#endif

  lDisplacedIndex = DEM_MEM_INVALID_MEMORY_INDEX;

  /*
   * find oldest DTC in Memory (by scanning elements in chronological order, starting with oldest),
   * that has a lower priority (=higher number) than the new DTC
   */

  /* Start with index of the oldest element (0) of the stack */
  for (lChronoIndexIterator = 0;
       lChronoIndexIterator < Dem_MemStorageManager_MemoryGetMaxSize(MemoryInfo);                                                /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
       ++lChronoIndexIterator)
  {
    Dem_Cfg_MemoryIndexType lMemoryIndex;
    Dem_MemoryEntry_HandleType lMemoryEntryId;
#if (DEM_CFG_SUPPORT_DISPLACEMENT == STD_ON)
    uint8 lStoredPriority;
#endif

    lMemoryIndex = Dem_MemStorageManager_MemoryGetChronology(MemoryInfo, lChronoIndexIterator);                                  /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
    lMemoryEntryId = Dem_MemStorageManager_GetMemoryEntryId(lMemoryIndex);
#if (DEM_CFG_SUPPORT_DISPLACEMENT == STD_ON)
    lStoredPriority = Dem_Cfg_EventPriority(Dem_MemoryEntry_GetEventId(lMemoryEntryId));
#endif
    /* Event cannot still be aged and reach here since an event would cross FDC threshold before failing */
    if (DEM_DTC_TEST_PC_STATUS_ADTC(Dem_MemoryEntry_GetPreConfirmedStatus(lMemoryEntryId)) == TRUE)
    { /* aged event can be displaced immediately */
      lDisplacedIndex = lMemoryIndex;
      break;
    }
#if (DEM_CFG_SUPPORT_DISPLACEMENT == STD_ON)
    else
    if (lStoredPriority > lLowestPrio)
    { /* Found oldest event entry with lower priority - remember in case there still is an aged event */
      lLowestPrioIndex = lMemoryIndex;
      lLowestPrio = lStoredPriority;
    }
#endif
    else
    { /* Not a candidate for displacement */
    }
  }

#if (DEM_CFG_SUPPORT_DISPLACEMENT == STD_ON)
  if (lDisplacedIndex == DEM_MEM_INVALID_MEMORY_INDEX)
  { /* no aged event detected */
    if (lLowestPrioIndex != DEM_MEM_INVALID_MEMORY_INDEX)
    { /* No aged event, but an old, lower prioritized event was found */
      lDisplacedIndex = lLowestPrioIndex;
    }
  }
#endif

  return lDisplacedIndex;
}
#endif

/* ****************************************************************************
 % Dem_MemAccess_MemoryAllocateIndex
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
DEM_LOCAL FUNC(uint8, DEM_CODE)
Dem_MemAccess_MemoryAllocateIndex(
  CONST(Dem_Mem_MemoryInfoPtrType, AUTOMATIC)  MemoryInfo,
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  )
{
  Dem_Cfg_MemoryIndexType lMemoryIndex;
  Dem_EventIdType lMasterEventId;

  lMasterEventId = Dem_Cfg_GetMasterEvent(EventId);

  if (Dem_MemStorageManager_MemoryGetMaxSize(MemoryInfo) == Dem_MemStorageManager_MemoryGetCurrentSize(MemoryInfo))              /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */ /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
  { /* Memory is filled up */
#if (DEM_FEATURE_NEED_OVFLIND == STD_ON)
    Dem_Mem_SetOverflow(Dem_MemStorageManager_MemoryGetId(MemoryInfo));                                                          /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
#endif

#if (DEM_CFG_SUPPORT_DISPLACEMENT == STD_ON)
    lMemoryIndex = Dem_MemAccess_SelectDisplacedIndex(MemoryInfo, EventId);                                                      /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
#else
    lMemoryIndex = DEM_MEM_INVALID_MEMORY_INDEX; /* Always failed */
#endif

#if (DEM_CFG_SUPPORT_DISPLACEMENT == STD_ON)
    if (lMemoryIndex != DEM_MEM_INVALID_MEMORY_INDEX)
    { /* a displaced DTC was identified, now remove that DTC */
      Dem_MemoryEntry_HandleType lMemoryEntryId;
      Dem_EventIdType lDisplacedEventId;

      lMemoryEntryId = Dem_MemStorageManager_GetMemoryEntryId(lMemoryIndex);
      lDisplacedEventId = Dem_MemoryEntry_GetEventId(lMemoryEntryId);

      if (Dem_Event_TestValidHandle(lDisplacedEventId) == TRUE)
      {
        Dem_DTC_Displaced(lDisplacedEventId);
      }
      Dem_MemAccess_MemoryFreeIndex(MemoryInfo, lMemoryIndex);                                                                   /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
    }
    /* else: no adequate DTC found, the new entry cannot be added - return an invalid index */
#endif
  }
  else
  { /* primary memory is not full */
    /* Memory is not full -> Find first free entry */
    lMemoryIndex = Dem_MemStorageManager_MemoryFindIndex(MemoryInfo, DEM_EVENT_INVALID);                                         /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
    /* if not found : lMemoryIndex == DEM_MEM_INVALID_MEMORY_INDEX */
  }

  if (lMemoryIndex != DEM_MEM_INVALID_MEMORY_INDEX)
  {
    uint8 lMemorySize;
    Dem_MemoryEntry_HandleType lMemoryEntryId;

    lMemorySize = Dem_MemStorageManager_MemoryGetCurrentSize(MemoryInfo);                                                        /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
    lMemoryEntryId = Dem_MemStorageManager_GetMemoryEntryId(lMemoryIndex);

    /* At this point, the event memory is not completely filled */
#if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
    if (lMemorySize >= Dem_MemStorageManager_MemoryGetMaxSize(MemoryInfo))                                                       /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
    {
      Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
      lMemoryIndex = DEM_MEM_INVALID_MEMORY_INDEX;
    }
    else
#endif
    {
      /* fill the chrono record with event id and lock the referenced PriMem slot */
      Dem_MemStorageManager_MemorySetChronology(MemoryInfo, lMemorySize, lMemoryIndex);                                          /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */

      Dem_MemoryEntry_SetEventId(lMemoryEntryId, lMasterEventId);
      Dem_MemoryEntry_SetTimestamp(lMemoryEntryId, Dem_Mem_CurrentTimestamp);

      Dem_Data_EntryInit(lMemoryEntryId);
#if (DEM_FEATURE_NEED_DEBOUNCE == STD_ON)
# if (DEM_CFG_DATA_MAX_FDC_SINCE_LAST_CLEAR == STD_ON)
      Dem_MemoryEntry_SetDebounceValueMax(lMemoryEntryId, 0);
# endif
#endif
      ++Dem_Mem_CurrentTimestamp;
      Dem_MemStorageManager_MemorySetCurrentSize(MemoryInfo, lMemorySize + 1);                                                   /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
    }
  }

  return lMemoryIndex;
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */

#if ((DEM_FEATURE_NEED_OEM_EXTENSIONS_VCC == STD_OFF) \
 &&  (DEM_FEATURE_NEED_AGING_REALLOCATION == STD_ON))
/* ****************************************************************************
 % Dem_MemAccess_MemoryAllocateAging
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
DEM_LOCAL FUNC(Dem_Cfg_MemoryIndexType, DEM_CODE)
Dem_MemAccess_MemoryAllocateAging(
  CONST(Dem_Mem_MemoryInfoPtrType, AUTOMATIC)  MemoryInfo,
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  )
{
  Dem_Cfg_MemoryIndexType lMemoryIndex;
  Dem_EventIdType lMasterEventId;

  lMasterEventId = Dem_Cfg_GetMasterEvent(EventId);

  /* Find empty slot if possible, otherwise remove aged slot */
  if (Dem_MemStorageManager_MemoryGetMaxSize(MemoryInfo) == Dem_MemStorageManager_MemoryGetCurrentSize(MemoryInfo))              /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */ /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
  { /* Memory is filled up -
     * Aged environmental data is not displaced, the remaining slots (if any)
     * are still used -> no chance to allocate an aging counter */
    lMemoryIndex = DEM_MEM_INVALID_MEMORY_INDEX;
  }
  else
  { /* Memory is not full -> Find first free entry */
    lMemoryIndex = Dem_MemStorageManager_MemoryFindIndex(MemoryInfo, DEM_EVENT_INVALID);                                         /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
    /* if not found : lMemoryIndex == DEM_MEM_INVALID_MEMORY_INDEX */
  }

  if (lMemoryIndex != DEM_MEM_INVALID_MEMORY_INDEX)
  {
    uint8 lMemorySize;

    lMemorySize = Dem_MemStorageManager_MemoryGetCurrentSize(MemoryInfo);                                                        /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */

    /* At this point, the event memory is not completely filled */
# if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
    if (lMemorySize >= Dem_MemStorageManager_MemoryGetMaxSize(MemoryInfo))                                                       /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
    {
      Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
      lMemoryIndex = DEM_MEM_INVALID_MEMORY_INDEX;
    }
    else
# endif
    {
      Dem_MemoryEntry_HandleType lMemoryEntryId;
      lMemoryEntryId = Dem_MemStorageManager_GetMemoryEntryId(lMemoryIndex);
      /* fill the chrono record with event id and lock the referenced PriMem slot */
      Dem_MemoryEntry_SetTimestamp(lMemoryEntryId, Dem_Mem_CurrentTimestamp);
      Dem_MemStorageManager_MemorySetChronology(MemoryInfo, lMemorySize, lMemoryIndex);                                          /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */

      Dem_MemoryEntry_SetEventId(lMemoryEntryId, lMasterEventId);

      /* Data */
      Dem_Data_EntryInit(lMemoryEntryId);
      Dem_MemoryEntry_SetState(lMemoryEntryId, DEM_MEM_SET_AGING_ONLY(0));

      Dem_Mem_CurrentTimestamp = (uint32)(Dem_Mem_CurrentTimestamp + 1);
      Dem_MemStorageManager_MemorySetCurrentSize(MemoryInfo, (uint8)(lMemorySize + 1));                                          /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
    }
  }

  return lMemoryIndex;
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */
#endif /* (DEM_FEATURE_NEED_OEM_EXTENSIONS_VCC == STD_OFF) && (DEM_FEATURE_NEED_AGING_REALLOCATION == STD_ON) */

/* ****************************************************************************
 % Dem_MemAccess_MemoryFreeIndex
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
Dem_MemAccess_MemoryFreeIndex(
  CONST(Dem_Mem_MemoryInfoPtrType, AUTOMATIC)  MemoryInfo,
  CONST(uint8, AUTOMATIC)  MemoryIndex
  )
{
  Dem_MemoryEntry_HandleType lMemoryEntryId;
  uint8 lChronoIterator;
  uint8 lTempChronoIndex;

  lMemoryEntryId = Dem_MemStorageManager_GetMemoryEntryId(MemoryIndex);

  /* reduce count of used elements in the chrono stack */
  Dem_Internal_AssertReturnVoid(
    MemoryIndex - Dem_MemStorageManager_MemoryIter_Begin(MemoryInfo)                                                             /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
    < Dem_MemStorageManager_MemoryGetMaxSize(MemoryInfo), DEM_E_INCONSISTENT_STATE)                                              /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */

  lChronoIterator = Dem_MemStorageManager_MemoryGetCurrentSize(MemoryInfo);                                                      /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
  --lChronoIterator;

  Dem_MemStorageManager_MemorySetCurrentSize(MemoryInfo, lChronoIterator);                                                       /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */

  /* free the primary element */
  Dem_MemoryEntry_SetEventId(lMemoryEntryId, DEM_EVENT_INVALID);
  Dem_MemoryEntry_SetTimestamp(lMemoryEntryId, 0);

  /* go backwards through the chronological list and move down all entries, until the deleted element is overwritten */
  lTempChronoIndex = Dem_MemStorageManager_MemoryGetChronology(MemoryInfo, lChronoIterator);                                     /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
  while (lTempChronoIndex != MemoryIndex)
  {
    uint8 lSwap;

    lSwap = lTempChronoIndex;

    --lChronoIterator;
    lTempChronoIndex = Dem_MemStorageManager_MemoryGetChronology(MemoryInfo, lChronoIterator);                                   /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
    Dem_MemStorageManager_MemorySetChronology(MemoryInfo, lChronoIterator, lSwap);                                               /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */

#if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
    if ((lChronoIterator == 0) && (lTempChronoIndex != MemoryIndex))
    {
      /* Index not found, chronology is corrupted */
      Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
      break;
    }
#endif
  }
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */

/* ****************************************************************************
 % Dem_Esm_EventCreateMemory
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
Dem_Esm_EventCreateMemory(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  )
{
  Dem_Mem_MemoryInfoPtrType lMemoryInfo;
  Dem_Cfg_MemoryIndexType lMemoryIndex;

  lMemoryInfo = Dem_MemStorageManager_MemoryInfoInit(Dem_Cfg_EventDestination(EventId));                                         /* PRQA S 3112 */ /* MD_DEM_14.2 */
  lMemoryIndex = Dem_MemAccess_MemoryAllocateIndex(lMemoryInfo, EventId);                                                        /* SBSW_DEM_CALL_MEMORYINFO_POINTER */
  if (lMemoryIndex != DEM_MEM_INVALID_MEMORY_INDEX)
  { /* Created new entry */
    Dem_DTC_InternalStatusType lInternalStatus;
/* >>>> -------------------------------- Enter Critical Section: DiagMonitor */
    Dem_EnterCritical_DiagMonitor();                                                                                             /* PRQA S 3109 */ /* MD_MSR_14.3 */
    lInternalStatus = Dem_DTC_GetInternalStatus(EventId);
    lInternalStatus = Dem_DTCInternalStatus_SetStoredStatus(lInternalStatus, Dem_DTCInternalStatus_StoredStatus_Active);
    Dem_DTC_SetInternalStatus(EventId,lInternalStatus);
    Dem_LeaveCritical_DiagMonitor();                                                                                             /* PRQA S 3109 */ /* MD_MSR_14.3 */
/* <<<< -------------------------------- Leave Critical Section: DiagMonitor */

    if (Dem_Cfg_EventSupportImmediateNv(EventId) == TRUE)
    {
      Dem_Nvm_SetMemoryBlockState(Dem_MemStorageManager_GetNvBlockType(lMemoryIndex),
                                  Dem_MemStorageManager_GetEntryIndex(lMemoryIndex),
                                  DEM_NVM_BLOCKSTATE_DIRTYIMMEDIATE);
    }
    else
    {
      Dem_Nvm_SetMemoryBlockState(Dem_MemStorageManager_GetNvBlockType(lMemoryIndex),
                                  Dem_MemStorageManager_GetEntryIndex(lMemoryIndex),
                                  DEM_NVM_BLOCKSTATE_DIRTY);
    }
  }
  return lMemoryIndex;
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */

/* ****************************************************************************
 % Dem_Esm_EventUpdateMemory
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
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_Esm_EventUpdateMemory(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(uint8, AUTOMATIC)  MemoryIndex,
  CONST(boolean, AUTOMATIC)  Occurrence
  )
{
  Dem_Mem_MemoryInfoPtrType lMemoryInfo;
  uint8 lBlockModification;

  lMemoryInfo = Dem_MemStorageManager_MemoryInfoInit(Dem_Cfg_EventDestination(EventId));
  lBlockModification = DEM_DATA_NO_CHANGES;

#if (DEM_CFG_AGING_RETAIN_MEMORY_ENTRY == STD_ON) || (DEM_FEATURE_NEED_AGING_REALLOCATION)
  {
    Dem_MemoryEntry_HandleType lMemoryEntryId;
    lMemoryEntryId = Dem_MemStorageManager_GetMemoryEntryId(MemoryIndex);
    if (
# if (DEM_CFG_AGING_RETAIN_MEMORY_ENTRY == STD_ON)
        (Dem_MemoryEntry_GetAgingCounter(lMemoryEntryId) == DEM_OPCYCLE_CYCLECOUNT_AGED)
# endif
# if (DEM_CFG_AGING_RETAIN_MEMORY_ENTRY == STD_ON) && (DEM_FEATURE_NEED_AGING_REALLOCATION)
      ||
# endif
# if (DEM_FEATURE_NEED_AGING_REALLOCATION)
        (DEM_MEM_TEST_AGING_ONLY(Dem_MemoryEntry_GetState(lMemoryEntryId)) == TRUE)
# endif
      )
    {
      /* Re-Initialize the memory entry - this will reset special flags like aging only */
      Dem_Data_EntryInit(lMemoryEntryId);
      lBlockModification = DEM_DATA_SET_STATISTICS_CHANGED(lBlockModification);

      /* Prepare expected statistics */
# if (DEM_CFG_DATA_MAX_FDC_SINCE_LAST_CLEAR == STD_ON)
      Dem_MemoryEntry_SetDebounceValueMax(lMemoryEntryId, 0);
# endif
    }
  }
#endif
  if (Occurrence == TRUE)
  {
    /* On re-occurrence also update the chronology */
    Dem_Mem_MemoryUpdateIndex(lMemoryInfo, MemoryIndex);                                                                         /* SBSW_DEM_CALL_MEMORYINFO_POINTER */
    lBlockModification = DEM_DATA_SET_STATISTICS_CHANGED(lBlockModification);
  }

  return lBlockModification;
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* DEM_MEMACCESS_IMPLEMENTATION_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_MemAccess_Implementation.h
 *********************************************************************************************************************/
