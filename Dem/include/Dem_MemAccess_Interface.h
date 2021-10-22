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
 *  \defgroup   Dem_MemAccess MemAccess
 *  \{
 *  \file       Dem_MemAccess_Interface.h
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

#if !defined (DEM_MEMACCESS_INTERFACE_H)
#define DEM_MEMACCESS_INTERFACE_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                  /* Own subcomponent header */
/* ------------------------------------------------------------------------- */
#include "Dem_MemAccess_Types.h"

/* ********************************************************************************************************************
 *  SUBCOMPONENT OBJECT FUNCTION DECLARATIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \defgroup Dem_MemAccess_Properties Properties
 * \{
 */

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
 * \defgroup Dem_MemAccess_Private Private Methods
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
 * \defgroup Dem_MemAccess_Public Public Methods
 * \{
 */

#if ((DEM_FEATURE_NEED_OEM_EXTENSIONS_VCC == STD_OFF) \
 && (DEM_CFG_SUPPORT_DISPLACEMENT == STD_ON))
/* ****************************************************************************
 * Dem_MemAccess_SelectDisplacedIndex
 *****************************************************************************/
/*!
 * \brief         Selects an event to displace in a filled memory
 *
 * \details       Selects an event to displace in a filled memory
 *
 * \param[in]     MemoryInfo
 *                Event memory descriptor
 * \param[in]     DisplacingEventId
 *                Unique handle of the Event to be entered into the memory
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 *
 * \return        The memory index of the displaced memory entry if one could
 *                be identified. DEM_MEM_INVALID_MEMORY_INDEX if displacement
 *                was not possible.
 *
 * \pre           -
 * \config        DEM_FEATURE_NEED_OEM_EXTENSIONS_VCC == STD_OFF
 *             && DEM_CFG_SUPPORT_DISPLACEMENT == STD_ON
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL FUNC(uint8, DEM_CODE)
Dem_MemAccess_SelectDisplacedIndex(
  CONST(Dem_Mem_MemoryInfoPtrType, AUTOMATIC)  MemoryInfo,
  CONST(Dem_EventIdType, AUTOMATIC)  DisplacingEventId
  );
#endif

#if (DEM_FEATURE_NEED_OEM_EXTENSIONS_VCC == STD_ON)
/* ****************************************************************************
 * Dem_MemAccess_SelectDisplacedIndex_Vcc
 *****************************************************************************/
/*!
 * \brief         Selects an event to displace in a filled memory
 *
 * \details       Selects an event to displace in a filled memory
 *
 * \param[in]     MemoryInfo
 *                Event memory descriptor
 * \param[in]     DisplacingEventId
 *                Unique handle of the Event to be entered into the memory
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 *
 * \return        The memory index of the displaced memory entry if one could
 *                be identified. DEM_MEM_INVALID_MEMORY_INDEX if displacement
 *                was not possible.
 *
 * \pre           -
 * \config        DEM_FEATURE_NEED_OEM_EXTENSIONS_VCC == STD_ON
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL FUNC(uint8, DEM_CODE)
Dem_MemAccess_SelectDisplacedIndex_Vcc(
  CONST(Dem_Mem_MemoryInfoPtrType, AUTOMATIC)  MemoryInfo,
  CONST(Dem_EventIdType, AUTOMATIC)  DisplacingEventId
  );
#endif

/* ****************************************************************************
 * Dem_MemAccess_MemoryAllocateIndex
 *****************************************************************************/
/*!
 * \brief         Selects a memory entry for an event
 *
 * \details       This function manages the event memory storage. If a free
 *                slot is available, it is returned directly. In case no free
 *                slot is available, the configured displacement algorithm is
 *                applied to free a slot.
 *
 * \param[in]     MemoryInfo
 *                Event memory descriptor
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 *
 * \return        The memory index of the allocated event memory entry if one
 *                could be identified. DEM_MEM_INVALID_MEMORY_INDEX if no entry
 *                was allocated.
 *
 * \pre           -
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL FUNC(uint8, DEM_CODE)
Dem_MemAccess_MemoryAllocateIndex(
  CONST(Dem_Mem_MemoryInfoPtrType, AUTOMATIC)  MemoryInfo,
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  );

#if ((DEM_FEATURE_NEED_OEM_EXTENSIONS_VCC == STD_OFF) \
 && (DEM_FEATURE_NEED_AGING_REALLOCATION == STD_ON))
/* ****************************************************************************
 * Dem_MemAccess_MemoryAllocateAging
 *****************************************************************************/
/*!
 * \brief         Selects a memory entry for an event's aging counter
 *
 * \details       If a free memory slot is available, it is returned directly.
 *                There is no fallback in case of a filled up event memory.
 *
 * \param[in]     MemoryInfo
 *                Event memory descriptor
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 *
 * \return        The memory index of the allocated event memory entry if one
 *                could be identified. DEM_MEM_INVALID_MEMORY_INDEX if no entry
 *                was allocated.
 *
 * \pre           -
 * \config        DEM_FEATURE_NEED_OEM_EXTENSIONS_VCC == STD_OFF
 *             && DEM_FEATURE_NEED_AGING_REALLOCATION == STD_ON
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL FUNC(Dem_Cfg_MemoryIndexType, DEM_CODE)
Dem_MemAccess_MemoryAllocateAging(
  CONST(Dem_Mem_MemoryInfoPtrType, AUTOMATIC)  MemoryInfo,
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  );
#endif

/* ****************************************************************************
 * Dem_MemAccess_MemoryFreeIndex
 *****************************************************************************/
/*!
 * \brief         Frees an event memory entry
 *
 * \details       This function frees an event memory entry.
 *
 * \param[in]     MemoryInfo
 *                Event memory descriptor
 * \param[in]     MemoryIndex
 *                Memory entry index
 *
 * \pre           -
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL FUNC(void, DEM_CODE)
Dem_MemAccess_MemoryFreeIndex(
  CONST(Dem_Mem_MemoryInfoPtrType, AUTOMATIC)  MemoryInfo,
  CONST(uint8, AUTOMATIC)  MemoryIndex
  );

/* ****************************************************************************
 * Dem_Esm_EventCreateMemory
 *****************************************************************************/
/*!
 * \brief         Allocate an event memory entry
 *
 * \details       This function tries to allocate an event memory entry for
 *                the given event. This can displace existing memory entries
 *                if the memory is already full.
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 *
 * \return        MemoryIndex of the allocated memory entry. If no entry was
 *                allocated, DEM_MEM_INVALID_MEMORY_INDEX is returned.
 *
 * \pre           The event may not be stored already
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_Esm_EventCreateMemory(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  );

/* ****************************************************************************
 * Dem_Esm_EventUpdateMemory
 *****************************************************************************/
/*!
 * \brief         Report an event entry as updated
 *
 * \details       This function updates an event memory after failure.
 *                An aged entry is reinitialized, and an active entry updates
 *                the time stamp when an occurrence was reported.
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 * \param[in]     Occurrence
 *                TRUE if the TF bit has transitioned FALSE->TRUE
 * \param[in]     MemoryIndex
 *                Memory entry index
 *
 * \return        Block modification bitmask:
 *                DEM_DATA_NO_CHANGES          nothing has changed
 *                DEM_DATA_USERDATA_CHANGED    user provided data was updated
 *                DEM_DATA_STATISTICS_CHANGED  internal data was updated
 *
 * \pre           The event must be stored
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_Esm_EventUpdateMemory(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(uint8, AUTOMATIC)  MemoryIndex,
  CONST(boolean, AUTOMATIC)  Occurrence
  );

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* DEM_MEMACCESS_INTERFACE_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_MemAccess_Interface.h
 *********************************************************************************************************************/
