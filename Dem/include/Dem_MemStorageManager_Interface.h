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
/*! \ingroup    Dem_Memory
 *  \defgroup   Dem_MemStorageManager Event Memory Storage Manager
 *  \{
 *  \file       Dem_MemStorageManager_Interface.h
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

#if !defined (DEM_MEMSTORAGEMANAGER_INTERFACE_H)
#define DEM_MEMSTORAGEMANAGER_INTERFACE_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                  /* Own subcomponent header */
/* ------------------------------------------------------------------------- */
#include "Dem_MemStorageManager_Types.h"

                                                           /* Required types */
/* ------------------------------------------------------------------------- */
#include "Dem_Nvm_Types.h"


/* ********************************************************************************************************************
 *  SUBCOMPONENT OBJECT FUNCTION DECLARATIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \defgroup Dem_MemStorageManager_Properties Properties
 * \{
 */

/* ****************************************************************************
 * Dem_MemStorageManager_GetEntryIndex
 *****************************************************************************/
/*!
 * \brief         Get the event memory specific index
 *
 * \details       Get the event memory specific index from the global memory 
 *                index
 *
 * \param[in]     MemoryIndex
 *                NV Block handle of the memory entry
 *
 * \return        The event memory specific index
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_Memory_EntryIndex, DEM_CODE)
Dem_MemStorageManager_GetEntryIndex(                                                                                             /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONST(Dem_Cfg_MemoryIndexType, AUTOMATIC)  MemoryIndex
  );

/* ****************************************************************************
 % Dem_MemStorageManager_GetNvBlockType
 *****************************************************************************/
/*!
 * \brief         Get the NvRAM block type
 *
 * \details       Get the NvRAM block type from the global memory index
 *
 * \param[in]     MemoryIndex
 *                NV Block handle of the memory entry
 *
 * \return        The NvRAM block type
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_Nvm_BlockType, DEM_CODE)
Dem_MemStorageManager_GetNvBlockType(                                                                                             /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONST(Dem_Cfg_MemoryIndexType, AUTOMATIC)  MemoryIndex
  );

/* ****************************************************************************
 % Dem_MemStorageManager_GetMemoryEntryId
 *****************************************************************************/
/*!
 * \brief         Get the memory entry Id
 *
 * \details       Get the memory entry Id from the global memory index
 *
 * \param[in]     MemoryIndex
 *                NV Block handle of the memory entry
 *
 * \return        The memory entry Id
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_MemoryEntry_HandleType, DEM_CODE)
Dem_MemStorageManager_GetMemoryEntryId(                                                                                          /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONST(Dem_Cfg_MemoryIndexType, AUTOMATIC)  MemoryIndex
  );

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* ********************************************************************************************************************
 *  SUBCOMPONENT PRIVATE FUNCTION DECLARATIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \defgroup Dem_MemStorageManager_Private Private Methods
 * \{
 */

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* ********************************************************************************************************************
 *  SUBCOMPONENT API FUNCTION DECLARATIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \defgroup Dem_MemStorageManager_Public Public Methods
 * \{
 */

/* ****************************************************************************
 * Dem_MemStorageManager_MemoryInfoInit
 *****************************************************************************/
/*!
 * \brief         Get the memory descriptor for the event memory
 *
 * \details       Get the memory descriptor for the event memory
 *
 * \param[in]     MemoryId
 *                Unique identifier of the event memory
 *
 * \return        Pointer to the memory descriptor for the event memory
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_Mem_MemoryInfoPtrType, DEM_CODE)
Dem_MemStorageManager_MemoryInfoInit(
  CONST(uint8, AUTOMATIC)  MemoryId
  );

/* ****************************************************************************
 * Dem_MemStorageManager_MemoryGetId
 *****************************************************************************/
/*!
 * \brief         Get the identifier of the event memory
 *
 * \details       Get the identifier of the event memory
 *
 * \param[in]     MemoryInfo
 *                Pointer to the memory descriptor for the event memory
 *
 * \return        Unique identifier of the event memory
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_MemStorageManager_MemoryGetId(
  CONST(Dem_Mem_MemoryInfoPtrType, AUTOMATIC)  MemoryInfo
  );                                                                                                                             /* PRQA S 0779 */ /* MD_MSR_5.1_779 */

/* ****************************************************************************
 * Dem_MemStorageManager_MemoryGetChronology
 *****************************************************************************/
/*!
 * \brief         Get the Nth oldest memory index
 *
 * \details       Get the Nth oldest memory index. 0 Is the oldest index.
 *
 * \param[in]     MemoryInfo
 *                Pointer to the memory descriptor for the event memory
 * \param[in]     ChronoIndex
 *                Index into chronology
 *
 * \return        NV Block handle of the memory entry
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_Cfg_MemoryIndexType, DEM_CODE)
Dem_MemStorageManager_MemoryGetChronology(
  CONST(Dem_Mem_MemoryInfoPtrType, AUTOMATIC)  MemoryInfo,
  CONST(uint8, AUTOMATIC)  ChronoIndex
  );                                                                                                                             /* PRQA S 0779 */ /* MD_MSR_5.1_779 */

/* ****************************************************************************
 * Dem_MemStorageManager_MemorySetChronology
 *****************************************************************************/
/*!
 * \brief         Set the Nth oldest memory index
 *
 * \details       Set the Nth oldest memory index. 0 Is the oldest index.
 *
 * \param[in]     MemoryInfo
 *                Pointer to the memory descriptor for the event memory
 * \param[in]     ChronoIndex
 *                Index into chronology
 * \param[in]     MemoryIndex
 *                NV Block handle of the memory entry
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_MemStorageManager_MemorySetChronology(
  CONST(Dem_Mem_MemoryInfoPtrType, AUTOMATIC)  MemoryInfo,
  CONST(uint8, AUTOMATIC)  ChronoIndex,
  CONST(Dem_Cfg_MemoryIndexType, AUTOMATIC)  MemoryIndex
  );                                                                                                                             /* PRQA S 0779 */ /* MD_MSR_5.1_779 */

/* ****************************************************************************
 * Dem_MemStorageManager_MemoryIter_Begin
 *****************************************************************************/
/*!
 * \brief         Get the start memory index of the event memory
 *
 * \details       Get the start memory index of the event memory
 *
 * \param[in]     MemoryInfo
 *                Pointer to the memory descriptor for the event memory
 *
 * \return        Memory index of the first memory entry belonging to the range
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_Cfg_MemoryIndexType, DEM_CODE)
Dem_MemStorageManager_MemoryIter_Begin(
  CONST(Dem_Mem_MemoryInfoPtrType, AUTOMATIC)  MemoryInfo
  );                                                                                                                             /* PRQA S 0779 */ /* MD_MSR_5.1_779 */

/* ****************************************************************************
 * Dem_MemStorageManager_MemoryIter_End
 *****************************************************************************/
/*!
 * \brief         Get the end memory index of the event memory
 *
 * \details       Get the end memory index of the event memory. The index
 *                returned does not belong to the event memory.
 *
 * \param[in]     MemoryInfo
 *                Pointer to the memory descriptor for the event memory
 *
 * \return        Memory index of the first memory entry not belonging to the range
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_Cfg_MemoryIndexType, DEM_CODE)
Dem_MemStorageManager_MemoryIter_End(
  CONST(Dem_Mem_MemoryInfoPtrType, AUTOMATIC)  MemoryInfo
  );                                                                                                                             /* PRQA S 0779 */ /* MD_MSR_5.1_779 */

/* ****************************************************************************
 * Dem_MemStorageManager_MemoryGetMaxSize
 *****************************************************************************/
/*!
 * \brief         Get the size of the event memory
 *
 * \details       Get the size of the event memory
 *
 * \param[in]     MemoryInfo
 *                Pointer to the memory descriptor for the event memory
 *
 * \return        The size of the event memory
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_MemStorageManager_MemoryGetMaxSize(
  CONST(Dem_Mem_MemoryInfoPtrType, AUTOMATIC)  MemoryInfo
  );                                                                                                                             /* PRQA S 0779 */ /* MD_MSR_5.1_779 */

/* ****************************************************************************
 * Dem_MemStorageManager_MemoryGetCurrentSize
 *****************************************************************************/
/*!
 * \brief         Get the number of occupied entries in the event memory
 *
 * \details       Get the number of occupied entries in the event memory
 *
 * \param[in]     MemoryInfo
 *                Pointer to the memory descriptor for the event memory
 *
 * \return        The number of occupied entries in the event memory
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_MemStorageManager_MemoryGetCurrentSize(
  CONST(Dem_Mem_MemoryInfoPtrType, AUTOMATIC)  MemoryInfo
  );                                                                                                                             /* PRQA S 0779 */ /* MD_MSR_5.1_779 */

/* ****************************************************************************
 * Dem_MemStorageManager_MemorySetCurrentSize
 *****************************************************************************/
/*!
 * \brief         Set the number of occupied entries in the event memory
 *
 * \details       Set the number of occupied entries in the event memory
 *
 * \param[in]     MemoryInfo
 *                Pointer to the memory descriptor for the event memory
 * \param[in]     Size
 *                New number of occupied entries in the event memory
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_MemStorageManager_MemorySetCurrentSize(
  CONST(Dem_Mem_MemoryInfoPtrType, AUTOMATIC)  MemoryInfo,
  CONST(uint8, AUTOMATIC)  Size
  );                                                                                                                             /* PRQA S 0779 */ /* MD_MSR_5.1_779 */

/* ****************************************************************************
 * Dem_MemStorageManager_MemoryGetFirstEvent
 *****************************************************************************/
/*!
 * \brief         Get first event belonging to the event memory
 *
 * \details       Get first event belonging to the event memory
 *
 * \param[in]     MemoryInfo
 *                Pointer to the memory descriptor for the event memory
 *
 * \return        Unique handle of the event
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_EventIdType, DEM_CODE)
Dem_MemStorageManager_MemoryGetFirstEvent(
  CONST(Dem_Mem_MemoryInfoPtrType, AUTOMATIC)  MemoryInfo
  );                                                                                                                             /* PRQA S 0779 */ /* MD_MSR_5.1_779 */

/* ****************************************************************************
 * Dem_MemStorageManager_MemoryGetLastEvent
 *****************************************************************************/
/*!
 * \brief         Get last event belonging to the event memory
 *
 * \details       Get last event belonging to the event memory.
 *
 * \param[in]     MemoryInfo
 *                Pointer to the memory descriptor for the event memory
 *
 * \return        Unique handle of the event
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_EventIdType, DEM_CODE)
Dem_MemStorageManager_MemoryGetLastEvent(
  CONST(Dem_Mem_MemoryInfoPtrType, AUTOMATIC)  MemoryInfo
  );                                                                                                                             /* PRQA S 0779 */ /* MD_MSR_5.1_779 */

/* ****************************************************************************
 * Dem_MemStorageManager_MemoryFindIndex_Checked
 *****************************************************************************/
/*!
 * \brief         Finds the event memory allocated to an event
 *
 * \details       Finds the event memory allocated to an event. If the event
 *                does not have a valid memory index, any valid index is
 *                returned instead.
 *
 * \param[in]     MemoryInfo
 *                Event memory descriptor
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 *
 * \return        The memory index used by the event.
 *                In error cases, a valid index is returned to avoid out of
 *                bounds memory access.
 *
 * \pre           The event must have a memory entry, i.e it is marked as
 *                'stored'
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_MemStorageManager_MemoryFindIndex_Checked(
  CONST(Dem_Mem_MemoryInfoPtrType, AUTOMATIC)  MemoryInfo,
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  );                                                                                                                             /* PRQA S 0779 */ /* MD_MSR_5.1_779 */

/* ****************************************************************************
 * Dem_MemStorageManager_MemoryFindIndex
 *****************************************************************************/
/*!
 * \brief         Finds the event memory allocated to an event
 *
 * \details       Finds the event memory allocated to an event.
 *
 * \param[in]     MemoryInfo
 *                Event memory descriptor
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 *
 * \return        The memory index used by the event if one was found.
 *                Otherwise, DEM_MEM_INVALID_MEMORY_INDEX is returned.
 *
 * \pre           -
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL FUNC(uint8, DEM_CODE)
Dem_MemStorageManager_MemoryFindIndex(
  CONST(Dem_Mem_MemoryInfoPtrType, AUTOMATIC)  MemoryInfo,
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  );                                                                                                                             /* PRQA S 0779 */ /* MD_MSR_5.1_779 */




/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* DEM_MEMSTORAGEMANAGER_INTERFACE_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_MemStorageManager_Interface.h
 *********************************************************************************************************************/
