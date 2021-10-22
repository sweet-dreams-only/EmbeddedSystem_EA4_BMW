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
/*! \addtogroup Dem_MemStorageManager
 *  \{
 *  \file       Dem_MemStorageManager_Implementation.h
 *  \brief      Control storage of additional data for DTCs based on storage/update triggers.
 *  \details    Knows depending on storage/update triggers which data to store/change.
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

#if !defined (DEM_MEMSTORAGEMANAGER_IMPLEMENTATION_H)
#define DEM_MEMSTORAGEMANAGER_IMPLEMENTATION_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                  /* Own subcomponent header */
/* ------------------------------------------------------------------------- */
#include "Dem_MemStorageManager_Interface.h"

                                                    /* Used subcomponent API */
/* ------------------------------------------------------------------------- */
#include "Dem_MemoryEntry_Implementation.h"
#include "Dem_Mem_Implementation.h"

                                                   /* Subcomponents callbacks*/
/* ------------------------------------------------------------------------- */
#include "Dem_Cfg_Declarations.h"
#include "Dem_DTC_Interface.h"
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

extern VAR(uint8, DEM_VAR_NOINIT)             Dem_MemState_PrimaryCurrentCount;
#if (DEM_CFG_SUPPORT_SECONDARY == STD_ON)
extern VAR(uint8, DEM_VAR_NOINIT)             Dem_MemState_SecondaryCurrentCount;
#endif

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

/*! MemoryInfo for the primary memory */
DEM_LOCAL CONST(Dem_Mem_MemoryInfoType, DEM_CONST) Dem_MemStorageManager_PrimaryInfo =                                           /* PRQA S 3218 */ /* MD_DEM_8.7 */
{
  &Dem_Cfg_PrimaryChronology[0],
  &Dem_MemState_PrimaryCurrentCount,
  DEM_CFG_MEMORY_PRIMARY_INDEX,
  DEM_CFG_GLOBAL_PRIMARY_FIRST,
  DEM_CFG_GLOBAL_PRIMARY_LAST,
  DEM_CFG_GLOBAL_PRIMARY_SIZE,
  DEM_CFG_MEMORYID_PRIMARY
};

#if (DEM_CFG_SUPPORT_SECONDARY == STD_ON)
/*! MemoryInfo for the secondary memory */
DEM_LOCAL CONST(Dem_Mem_MemoryInfoType, DEM_CONST) Dem_MemStorageManager_SecondaryInfo =                                         /* PRQA S 3218 */ /* MD_DEM_8.7 */
{
  &Dem_Cfg_SecondaryChronology[0],
  &Dem_MemState_SecondaryCurrentCount,
  DEM_CFG_MEMORY_SECONDARY_INDEX,
  DEM_CFG_GLOBAL_SECONDARY_FIRST,
  DEM_CFG_GLOBAL_SECONDARY_LAST,
  DEM_CFG_GLOBAL_SECONDARY_SIZE,
  DEM_CFG_MEMORYID_SECONDARY
};
#endif

#if (DEM_FEATURE_NEED_TIME_SERIES == STD_ON)
/*! MemoryInfo for the time series memory */
DEM_LOCAL CONST(Dem_Mem_MemoryInfoType, DEM_CONST) Dem_MemStorageManager_TimeSeriesInfo =                                        /* PRQA S 3218 */ /* MD_DEM_8.7 */
{
  &Dem_Cfg_TimeSeriesChronology[0],
  &Dem_Mem_TimeSeriesCurrentCount,
  DEM_CFG_MEMORY_TIME_SERIES_INDEX,
  DEM_CFG_GLOBAL_PRIMARY_FIRST,
  DEM_CFG_GLOBAL_PRIMARY_LAST,
  DEM_CFG_GLOBAL_TIMESERIES_SNAPSHOTS_SIZE,
  DEM_CFG_MEMORYID_TIMESERIES
};
#endif

#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* ********************************************************************************************************************
 *  SUBCOMPONENT OBJECT FUNCTION DEFINITIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \addtogroup Dem_MemStorageManager_Properties
 * \{
 */

/* ****************************************************************************
 % Dem_MemStorageManager_GetEntryIndex
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_Memory_EntryIndex, DEM_CODE)
Dem_MemStorageManager_GetEntryIndex(                                                                                             /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONST(Dem_Cfg_MemoryIndexType, AUTOMATIC)  MemoryIndex
  )
{
  Dem_Memory_EntryIndex lReturnValue;
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(MemoryIndex)                                                                                  /* PRQA S 3112 */ /* MD_DEM_14.2 */
#if (DEM_CFG_SUPPORT_SECONDARY == STD_ON)
  if ( (MemoryIndex >= DEM_CFG_MEMORY_SECONDARY_INDEX)
    && (MemoryIndex < (DEM_CFG_MEMORY_SECONDARY_INDEX + DEM_CFG_GLOBAL_SECONDARY_SIZE)) )
  {
    lReturnValue = MemoryIndex - DEM_CFG_MEMORY_SECONDARY_INDEX;
  }
  else
#endif
  {
    lReturnValue = MemoryIndex - DEM_CFG_MEMORY_PRIMARY_INDEX;
  }
  return lReturnValue;
}

/* ****************************************************************************
 % Dem_MemStorageManager_GetNvBlockType
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_Nvm_BlockType, DEM_CODE)
Dem_MemStorageManager_GetNvBlockType(                                                                                            /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONST(Dem_Cfg_MemoryIndexType, AUTOMATIC)  MemoryIndex
  )
{
  Dem_Nvm_BlockType lReturnValue;
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(MemoryIndex)                                                                                  /* PRQA S 3112 */ /* MD_DEM_14.2 */
#if (DEM_CFG_SUPPORT_SECONDARY == STD_ON)
  if ( (MemoryIndex >= DEM_CFG_MEMORY_SECONDARY_INDEX)
    && (MemoryIndex < (DEM_CFG_MEMORY_SECONDARY_INDEX + DEM_CFG_GLOBAL_SECONDARY_SIZE)) )
  {
    lReturnValue = DEM_NVM_BLOCKTYPE_SECONDARY;
  }
  else
#endif
  {
    lReturnValue = DEM_NVM_BLOCKTYPE_PRIMARY;
  }
  return lReturnValue;
}

/* ****************************************************************************
 % Dem_MemStorageManager_GetMemoryEntryId
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_MemoryEntry_HandleType, DEM_CODE)
Dem_MemStorageManager_GetMemoryEntryId(                                                                                          /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONST(Dem_Cfg_MemoryIndexType, AUTOMATIC)  MemoryIndex
  )
{
  Dem_MemoryEntry_HandleType lReturnValue;
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(MemoryIndex)                                                                                  /* PRQA S 3112 */ /* MD_DEM_14.2 */
#if (DEM_CFG_SUPPORT_SECONDARY == STD_ON)
  if ( (MemoryIndex >= DEM_CFG_MEMORY_SECONDARY_INDEX)
    && (MemoryIndex < (DEM_CFG_MEMORY_SECONDARY_INDEX + DEM_CFG_GLOBAL_SECONDARY_SIZE)) )
  {
    lReturnValue = DEM_MEMORYENTRY_HANDLE_SECONDARY + Dem_MemStorageManager_GetEntryIndex(MemoryIndex);
  }
  else
#endif
  {
    lReturnValue = DEM_MEMORYENTRY_HANDLE_PRIMARY + Dem_MemStorageManager_GetEntryIndex(MemoryIndex);
  }
  return lReturnValue;
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
 * \addtogroup Dem_MemStorageManager_Private
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
 * \addtogroup Dem_MemStorageManager_Public
 * \{
 */

/* ****************************************************************************
 % Dem_MemStorageManager_MemoryInfoInit
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_Mem_MemoryInfoPtrType, DEM_CODE)
Dem_MemStorageManager_MemoryInfoInit(
  CONST(uint8, AUTOMATIC)  MemoryId                                                                                              /* PRQA S 3206 */ /* MD_DEM_3206 */
  )
{
  Dem_Mem_MemoryInfoPtrType lReturnValue;
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(MemoryId)                                                                                     /* PRQA S 3112 */ /* MD_DEM_14.2 */
#if (DEM_CFG_SUPPORT_SECONDARY == STD_ON)
  if (MemoryId == DEM_CFG_MEMORYID_SECONDARY)
  {
    lReturnValue = &Dem_MemStorageManager_SecondaryInfo;
  }
  else
#endif
  {
    lReturnValue = &Dem_MemStorageManager_PrimaryInfo;
  }
  return lReturnValue;
}

/* ****************************************************************************
 % Dem_MemStorageManager_MemoryGetId
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_MemStorageManager_MemoryGetId(
  CONST(Dem_Mem_MemoryInfoPtrType, AUTOMATIC)  MemoryInfo
  )
{
  return MemoryInfo->MemoryId;
}

/* ****************************************************************************
 % Dem_MemStorageManager_MemoryGetChronology
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_Cfg_MemoryIndexType, DEM_CODE)
Dem_MemStorageManager_MemoryGetChronology(
  CONST(Dem_Mem_MemoryInfoPtrType, AUTOMATIC)  MemoryInfo,
  CONST(uint8, AUTOMATIC)  ChronoIndex
  )
{
  return (MemoryInfo->ChronoPtr)[ChronoIndex];
}

/* ****************************************************************************
 % Dem_MemStorageManager_MemorySetChronology
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_MemStorageManager_MemorySetChronology(
  CONST(Dem_Mem_MemoryInfoPtrType, AUTOMATIC)  MemoryInfo,
  CONST(uint8, AUTOMATIC)  ChronoIndex,
  CONST(Dem_Cfg_MemoryIndexType, AUTOMATIC)  MemoryIndex
  )
{
#if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (ChronoIndex >= MemoryInfo->MaxSize)
  {
    Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
  }
  else
#endif
  {
    (MemoryInfo->ChronoPtr)[ChronoIndex] = MemoryIndex;                                                                          /* SBSW_DEM_ARRAY_WRITE_MEMORYCHRONOLOGY */
  }
}

/* ****************************************************************************
 % Dem_MemStorageManager_MemoryIter_Begin
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_Cfg_MemoryIndexType, DEM_CODE)
Dem_MemStorageManager_MemoryIter_Begin(
  CONST(Dem_Mem_MemoryInfoPtrType, AUTOMATIC)  MemoryInfo
  )
{
  return MemoryInfo->FirstMemoryIndex;
}

/* ****************************************************************************
 % Dem_MemStorageManager_MemoryIter_End
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_Cfg_MemoryIndexType, DEM_CODE)
Dem_MemStorageManager_MemoryIter_End(
  CONST(Dem_Mem_MemoryInfoPtrType, AUTOMATIC)  MemoryInfo
  )
{
  return (Dem_Cfg_MemoryIndexType)(MemoryInfo->FirstMemoryIndex + MemoryInfo->MaxSize);
}

/* ****************************************************************************
 % Dem_MemStorageManager_MemoryGetMaxSize
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_MemStorageManager_MemoryGetMaxSize(
  CONST(Dem_Mem_MemoryInfoPtrType, AUTOMATIC)  MemoryInfo
  )
{
  return MemoryInfo->MaxSize;
}

/* ****************************************************************************
 % Dem_MemStorageManager_MemoryGetCurrentSize
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_MemStorageManager_MemoryGetCurrentSize(
  CONST(Dem_Mem_MemoryInfoPtrType, AUTOMATIC)  MemoryInfo
  )
{
  return *(MemoryInfo->SizePtr);
}

/* ****************************************************************************
 % Dem_MemStorageManager_MemorySetCurrentSize
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_MemStorageManager_MemorySetCurrentSize(
  CONST(Dem_Mem_MemoryInfoPtrType, AUTOMATIC)  MemoryInfo,
  CONST(uint8, AUTOMATIC)  Size
  )
{
#if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (Size > Dem_MemStorageManager_MemoryGetMaxSize(MemoryInfo))                                                                 /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
  {
    Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
    *(MemoryInfo->SizePtr) = Dem_MemStorageManager_MemoryGetMaxSize(MemoryInfo);                                                 /* SBSW_DEM_POINTER_WRITE_ARGUMENT */ /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
  }
  else
#endif
  {
    *(MemoryInfo->SizePtr) = Size;                                                                                               /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
  }
}

/* ****************************************************************************
 % Dem_MemStorageManager_MemoryGetFirstEvent
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_EventIdType, DEM_CODE)
Dem_MemStorageManager_MemoryGetFirstEvent(
  CONST(Dem_Mem_MemoryInfoPtrType, AUTOMATIC)  MemoryInfo
  )
{
  return MemoryInfo->FirstEvent;
}

/* ****************************************************************************
 % Dem_MemStorageManager_MemoryGetLastEvent
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_EventIdType, DEM_CODE)
Dem_MemStorageManager_MemoryGetLastEvent(
  CONST(Dem_Mem_MemoryInfoPtrType, AUTOMATIC)  MemoryInfo
  )
{
  return MemoryInfo->LastEvent;
}

/* ****************************************************************************
 * Dem_MemStorageManager_MemoryFindIndex_Checked
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_MemStorageManager_MemoryFindIndex_Checked(
  CONST(Dem_Mem_MemoryInfoPtrType, AUTOMATIC)  MemoryInfo,
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  )
{
  Dem_Cfg_MemoryIndexType lMemoryIndex;

  lMemoryIndex = Dem_MemStorageManager_MemoryFindIndex(MemoryInfo, EventId);                                                     /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */

#if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  /* Cannot happen except after the Dem state becomes inconsistent */
  if (lMemoryIndex == DEM_MEM_INVALID_MEMORY_INDEX)
  {
    Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
    lMemoryIndex = 0;
  }
#endif

  return lMemoryIndex;
}

/* ****************************************************************************
 % Dem_MemStorageManager_MemoryFindIndex
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
DEM_LOCAL FUNC(uint8, DEM_CODE)
Dem_MemStorageManager_MemoryFindIndex(
  CONST(Dem_Mem_MemoryInfoPtrType, AUTOMATIC)  MemoryInfo,
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  )
{
  Dem_EventIdType lMasterEventId;
  Dem_Cfg_MemoryIndexType lMemoryIndex;
  Dem_Cfg_MemoryIndexType lMemoryIndexEnd;

  lMasterEventId = Dem_Cfg_GetMasterEvent(EventId);

  /* Iteration direction must be identical to Dem_Init! */

  lMemoryIndex = Dem_MemStorageManager_MemoryIter_Begin(MemoryInfo);                                                             /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
  lMemoryIndexEnd = Dem_MemStorageManager_MemoryIter_End(MemoryInfo);                                                            /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
  while ( (lMemoryIndex < lMemoryIndexEnd)                                                                                       /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
       && (Dem_MemoryEntry_GetEventId(Dem_MemStorageManager_GetMemoryEntryId(lMemoryIndex)) != lMasterEventId) )                                                         
  {
    ++lMemoryIndex;
  }
  /* if not found, return DEM_MEM_INVALID_MEMORY_INDEX */
  if (lMemoryIndex >= lMemoryIndexEnd)
  {
    lMemoryIndex = DEM_MEM_INVALID_MEMORY_INDEX;
  }
  return lMemoryIndex;
}

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* DEM_MEMSTORAGEMANAGER_IMPLEMENTATION_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_MemStorageManager_Implementation.h
 *********************************************************************************************************************/
