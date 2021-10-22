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
/*! \addtogroup Dem_ExtendedEntry
 *  \{
 *  \file       Dem_ExtendedEntry_Implementation.h
 *  \brief      Diagnostic Event Manager (Dem) header file
 *  \details    Encapsulates the list of extended data record buffers stored in the memory entry
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

#if !defined (DEM_EXTENDEDENTRY_IMPLEMENTATION_H)
#define DEM_EXTENDEDENTRY_IMPLEMENTATION_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                        /* Dem module header */
/* ------------------------------------------------------------------------- */
#include "Dem_ExtendedEntry_Interface.h"
#include "Dem_MemoryEntry_Implementation.h"

/* ------------------------------------------------------------------------- */

/* ********************************************************************************************************************
 *  SUBCOMPONENT CONSTANT MACROS
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  SUBCOMPONENT FUNCTION MACROS
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
 * \addtogroup Dem_ExtendedEntry_Properties
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
 * \addtogroup Dem_ExtendedEntry_Private
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
 * \addtogroup Dem_ExtendedEntry_Public
 * \{
 */

#if (DEM_CFG_SUPPORT_ERECS == STD_ON)
/* ****************************************************************************
 % Dem_ExtendedEntry_IteratorInit
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_ExtendedEntry_IteratorInit(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(Dem_MemoryEntry_HandleType, AUTOMATIC)  MemoryEntryId,
  CONSTP2VAR(Dem_ExtendedEntry_IterType, AUTOMATIC, AUTOMATIC)  ExtendedEntryIter
  )
{
  ExtendedEntryIter->EventId = EventId;                                                                                          /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
  ExtendedEntryIter->MemoryEntryId = MemoryEntryId;                                                                              /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
  ExtendedEntryIter->ExtendedIteratorIndex = 
    Dem_Cfg_GetDataCollectionTableEdr2CollIndStartIdxOfExtendedDataTable(Dem_Cfg_GetExtendedDataTableIdxOfEventTable(EventId));  /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
  ExtendedEntryIter->ExtendedEntryIndex = 0;                                                                                     /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
}
#endif /* (DEM_CFG_SUPPORT_ERECS == STD_ON) */

#if (DEM_CFG_SUPPORT_ERECS == STD_ON)
/* ****************************************************************************
 % Dem_ExtendedEntry_IteratorNext
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_ExtendedEntry_IteratorNext(
  CONSTP2VAR(Dem_ExtendedEntry_IterType, AUTOMATIC, AUTOMATIC)  ExtendedEntryIter
  )
{
  if (Dem_Cfg_ERecType(Dem_ExtendedEntry_IteratorGetExtendedRecordIndex(ExtendedEntryIter)) == DEM_CFG_EREC_TYPE_USER)
  {
    ExtendedEntryIter->ExtendedEntryIndex++;                                                                                     /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
  }
  ExtendedEntryIter->ExtendedIteratorIndex++;                                                                                    /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
}
#endif /* (DEM_CFG_SUPPORT_ERECS == STD_ON) */

#if (DEM_CFG_SUPPORT_ERECS == STD_ON)
/* ****************************************************************************
 % Dem_ExtendedEntry_IteratorExists
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_ExtendedEntry_IteratorExists(
  CONSTP2CONST(Dem_ExtendedEntry_IterType, AUTOMATIC, AUTOMATIC)  ExtendedEntryIter
  )
{
  return (boolean) (ExtendedEntryIter->ExtendedIteratorIndex < 
    Dem_Cfg_GetDataCollectionTableEdr2CollIndEndIdxOfExtendedDataTable(Dem_Cfg_GetExtendedDataTableIdxOfEventTable(ExtendedEntryIter->EventId)));
}
#endif /* (DEM_CFG_SUPPORT_ERECS == STD_ON) */

#if (DEM_CFG_SUPPORT_ERECS == STD_ON)
/* ****************************************************************************
 % Dem_ExtendedEntry_IteratorSetMemoryEntryHandle
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_ExtendedEntry_IteratorSetMemoryEntryHandle(
  CONST(Dem_MemoryEntry_HandleType, AUTOMATIC)  MemoryEntryId,
  CONSTP2VAR(Dem_ExtendedEntry_IterType, AUTOMATIC, AUTOMATIC)  ExtendedEntryIter
  )
{
  ExtendedEntryIter->MemoryEntryId = MemoryEntryId;
}
#endif /* (DEM_CFG_SUPPORT_USER_ERECS == STD_ON) */

#if (DEM_CFG_SUPPORT_ERECS == STD_ON)
/* ****************************************************************************
 % Dem_ExtendedEntry_IteratorGetExtendedRecordIndex
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_Cfg_ERecIndexType, DEM_CODE)
Dem_ExtendedEntry_IteratorGetExtendedRecordIndex(
  CONSTP2CONST(Dem_ExtendedEntry_IterType, AUTOMATIC, AUTOMATIC)  ExtendedEntryIter
  )
{
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(ExtendedEntryIter)                                                                            /* PRQA S 3112 */ /* MD_DEM_14.2 */
  return (Dem_Cfg_ERecIndexType) Dem_Cfg_GetDataCollectionTableEdr2CollInd(ExtendedEntryIter->ExtendedIteratorIndex);
}
#endif /* (DEM_CFG_SUPPORT_ERECS == STD_ON) */

#if (DEM_CFG_SUPPORT_USER_ERECS == STD_ON) && (DEM_DEV_RUNTIME_CHECKS == STD_ON)
/* ****************************************************************************
 % Dem_ExtendedEntry_IteratorGetExtendedEntryIndex
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_ExtendedEntry_IteratorGetExtendedEntryIndex(
  CONSTP2CONST(Dem_ExtendedEntry_IterType, AUTOMATIC, AUTOMATIC)  ExtendedEntryIter
  )
{
  return ExtendedEntryIter->ExtendedEntryIndex;
}
#endif /* (DEM_CFG_SUPPORT_USER_ERECS == STD_ON) && (DEM_DEV_RUNTIME_CHECKS == STD_ON) */

#if (DEM_CFG_SUPPORT_USER_ERECS == STD_ON)
/* ****************************************************************************
 % Dem_ExtendedEntry_IteratorGetExtendedRecordDataPtr
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_SharedDataPtrType, DEM_CODE)
Dem_ExtendedEntry_IteratorGetExtendedRecordDataPtr(
  CONSTP2CONST(Dem_ExtendedEntry_IterType, AUTOMATIC, AUTOMATIC)  ExtendedEntryIter
  )
{
  if (ExtendedEntryIter->MemoryEntryId == DEM_MEMORYENTRY_HANDLE_INVALID)
  {
    Dem_Internal_AssertAlways(DEM_E_INCONSISTENT_STATE);
  }
  return Dem_MemoryEntry_GetExtendedRecordDataPtr(ExtendedEntryIter->MemoryEntryId, ExtendedEntryIter->ExtendedEntryIndex);
}
#endif /* (DEM_CFG_SUPPORT_USER_ERECS == STD_ON) */

#if (DEM_CFG_SUPPORT_USER_ERECS == STD_ON)
/* ****************************************************************************
 % Dem_ExtendedEntry_IteratorGetExtendedRecordDataConstPtr
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_ConstSharedDataPtrType, DEM_CODE)
Dem_ExtendedEntry_IteratorGetExtendedRecordDataConstPtr(
  CONSTP2CONST(Dem_ExtendedEntry_IterType, AUTOMATIC, AUTOMATIC)  ExtendedEntryIter
  )
{
  if (ExtendedEntryIter->MemoryEntryId == DEM_MEMORYENTRY_HANDLE_INVALID)
  {
    Dem_Internal_AssertAlways(DEM_E_INCONSISTENT_STATE);
  }
  return Dem_MemoryEntry_GetExtendedRecordDataConstPtr(ExtendedEntryIter->MemoryEntryId, ExtendedEntryIter->ExtendedEntryIndex);
}
#endif /* (DEM_CFG_SUPPORT_USER_ERECS == STD_ON) */

#if (DEM_CFG_SUPPORT_USER_ERECS == STD_ON)
/* ****************************************************************************
 % Dem_ExtendedEntry_IteratorIsExtendedRecordStored
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_ExtendedEntry_IteratorIsExtendedRecordStored(
  CONSTP2CONST(Dem_ExtendedEntry_IterType, AUTOMATIC, AUTOMATIC)  ExtendedEntryIter
  )
{
  boolean lExtendedRecordIsStored;

  lExtendedRecordIsStored = FALSE;
  if (ExtendedEntryIter->MemoryEntryId != DEM_MEMORYENTRY_HANDLE_INVALID)
  {
    uint8 lMask;

    lMask = (uint8)(1u << ExtendedEntryIter->ExtendedEntryIndex);
    if ((Dem_MemoryEntry_GetExtendedHeader(ExtendedEntryIter->MemoryEntryId) & lMask) != 0)
    {
      lExtendedRecordIsStored = TRUE;
    }
  }
  else
  {
    Dem_Internal_AssertAlways(DEM_E_INCONSISTENT_STATE);
  }

  return lExtendedRecordIsStored;
}
#endif /* (DEM_CFG_SUPPORT_USER_ERECS == STD_ON) */

#if (DEM_CFG_SUPPORT_USER_ERECS == STD_ON)
/* ****************************************************************************
 % Dem_ExtendedEntry_IteratorUpdateExtendedEntry
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_ExtendedEntry_IteratorUpdateExtendedEntry(
  CONSTP2CONST(Dem_ExtendedEntry_IterType, AUTOMATIC, AUTOMATIC)  ExtendedEntryIter
  )
{
  if (ExtendedEntryIter->MemoryEntryId != DEM_MEMORYENTRY_HANDLE_INVALID)
  {
    uint8 lMask;

    lMask = (uint8)(1u << ExtendedEntryIter->ExtendedEntryIndex);
    Dem_MemoryEntry_SetExtendedHeader(ExtendedEntryIter->MemoryEntryId, 
                                      Dem_MemoryEntry_GetExtendedHeader(ExtendedEntryIter->MemoryEntryId) | lMask);
  }
  else
  {
    Dem_Internal_AssertAlways(DEM_E_INCONSISTENT_STATE);
  }
}
#endif /* (DEM_CFG_SUPPORT_USER_ERECS == STD_ON) */

#if (DEM_CFG_SUPPORT_USER_ERECS == STD_ON)
/* ****************************************************************************
 % Dem_ExtendedEntry_ResetStoredExtendedRecords
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_ExtendedEntry_ResetStoredExtendedRecords(
  CONST(Dem_MemoryEntry_HandleType, AUTOMATIC)  MemoryEntryId
  )
{
  Dem_MemoryEntry_SetExtendedHeader(MemoryEntryId, 0U);
}
#endif /* (DEM_CFG_SUPPORT_USER_ERECS == STD_ON) */

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* DEM_EXTENDEDENTRY_IMPLEMENTATION_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_ExtendedEntry_Implementation.h
 *********************************************************************************************************************/
