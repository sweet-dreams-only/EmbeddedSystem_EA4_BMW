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
 *  \file       Dem_MemStorageManager_Types.h
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

#if !defined (DEM_MEMSTORAGEMANAGER_TYPES_H)
#define DEM_MEMSTORAGEMANAGER_TYPES_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                  /* Own subcomponent header */
/* ------------------------------------------------------------------------- */
#include "Dem_Int.h"
#include "Dem_Memory_Types.h"

/* ********************************************************************************************************************
 *  SUBCOMPONENT CONSTANT MACROS
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  SUBCOMPONENT FUNCTION MACROS
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  SUBCOMPONENT DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/*! Event memory specific index */
typedef uint8 Dem_Memory_EntryIndex;

/*! Pointer to a chronology list */
typedef CONSTP2VAR(uint8, TYPEDEF, DEM_VAR_NOINIT) Dem_Mem_ChronoStackPtrType;
/*! Pointer to memory size variable */
typedef CONSTP2VAR(uint8, TYPEDEF, DEM_VAR_NOINIT) Dem_Mem_CurrentSizePtrType;

/*! Event Memory management data */
struct Dem_Mem_MemoryInfoType_s
{
  Dem_Mem_ChronoStackPtrType    ChronoPtr;  /*!< Pointer to the chronology list of the event memory */
  Dem_Mem_CurrentSizePtrType    SizePtr;  /*!< Pointer to the current size variable */
  uint8                         FirstMemoryIndex;  /*!< First memory block index belonging to the memory */
  Dem_EventIdType               FirstEvent;  /*!< First event id belonging to the memory */
  Dem_EventIdType               LastEvent;  /*!< Last event Id belonging to the memory */
  uint8                         MaxSize;  /*!< Maximum number of memory entries for the memory */
  uint8                         MemoryId;  /*!< Handle to identify the event memory */
};

/*! Event Memory management data type */
typedef struct Dem_Mem_MemoryInfoType_s                              Dem_Mem_MemoryInfoType;
/*! Pointer to Event Memory management data */
typedef P2CONST(Dem_Mem_MemoryInfoType, TYPEDEF, DEM_CONST)          Dem_Mem_MemoryInfoPtrType;

#endif /* DEM_MEMSTORAGEMANAGER_TYPES_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_MemStorageManager_Types.h
 *********************************************************************************************************************/
