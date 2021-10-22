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
 *  \file       Dem_Memory_Types.h
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

#if !defined (DEM_MEMORY_TYPES_H)
#define DEM_MEMORY_TYPES_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                  /* Own subcomponent header */
/* ------------------------------------------------------------------------- */
#include "Dem_Int.h"

/* ********************************************************************************************************************
 *  SUBCOMPONENT CONSTANT MACROS
 *********************************************************************************************************************/

/*! Invalid memory index used for 'no index available' */
#define DEM_MEM_INVALID_MEMORY_INDEX             Dem_Cfg_GlobalNvBlockCount()


/* Kind of memory access - used by Dem_Memory_SetHandleType(...) and Dem_Memory_GetHandleType(...). To simplify a mapping, the values are aligned to Dem_DTCOriginType. */
#define DEM_MEMORY_HANDLETYPE_INVALID                                           0U /*!< not a memory location */
#define DEM_MEMORY_HANDLETYPE_PRIMARY                                           1U /*!< primary event memory, see DEM_DTC_ORIGIN_PRIMARY_MEMORY = 1 */
#define DEM_MEMORY_HANDLETYPE_MIRROR                                            2U /*!< mirror event memory - unsupported, see DEM_DTC_ORIGIN_MIRROR_MEMORY = 2 */
#define DEM_MEMORY_HANDLETYPE_PERMANENT                                         3U /*!< permanent DTC memory, see DEM_DTC_ORIGIN_PERMANENT_MEMORY = 3 */
#define DEM_MEMORY_HANDLETYPE_FREEZEFRAME                                       4U /*!< OBD freezeframe memory, see DEM_DTC_ORIGIN_OBD_RELEVANT_MEMORY = 4 */
#define DEM_MEMORY_HANDLETYPE_SECONDARY                                         5U /*!< secondary event memory, see Vector extension DEM_DTC_ORIGIN_SECONDARY_MEMORY = 5 */
#define DEM_MEMORY_HANDLETYPE_ADMINDATA                                        16U /*!< admin data memory */
#define DEM_MEMORY_HANDLETYPE_STATUSDATA                                       17U /*!< event status memory */
#define DEM_MEMORY_HANDLETYPE_OBDIUMPR                                         18U /*!< OBD IUMPR memory */
#define DEM_MEMORY_HANDLETYPE_DEBOUNCE                                         19U /*!< debounce memory */
#define DEM_MEMORY_HANDLETYPE_TIMESERIES                                       20U /*!< time series memory */
#define DEM_MEMORY_HANDLETYPE_READOUT                                          21U /*!< ReadOut buffer memory */
#define DEM_MEMORY_HANDLETYPE_TSREADOUT                                        22U /*!< time series ReadOut buffer memory */
#define DEM_MEMORY_HANDLETYPE_DTR                                              23U /*!< Dtr memory */
#define DEM_MEMORY_HANDLETYPE_AVAILABLE                                        24U /*!< EventAvailable memory */
#define DEM_MEMORY_HANDLETYPE_PRESTORAGE                                       25U /*!< Prestorage memory */
#define DEM_MEMORY_HANDLETYPE_COMMIT                                           26U /*!< Commit buffer memory */

/* ********************************************************************************************************************
 *  SUBCOMPONENT FUNCTION MACROS
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  SUBCOMPONENT DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/* Generic type for memory access. */
typedef struct Dem_Memory_Handle_s
{
  uint8  HandleType;      /*!< memory type, see #define DEM_MEMORY_HANDLETYPE_nn */
  uint8  HandleIndex;     /*!< event memory specific index */
} Dem_Memory_HandleType;  /*!< generic handle for memories, contains 'Type' and a Type-specifix 'Index' - use only setter/getter functions for access. */

/*! Const Pointer to a memory handle */
typedef CONSTP2VAR(Dem_Memory_HandleType, TYPEDEF, DEM_SHARED_DATA)       Dem_Memory_HandlePtrType;
/*! Const pointer to a Non-writeable memory handle */
typedef CONSTP2CONST(Dem_Memory_HandleType, TYPEDEF, DEM_SHARED_DATA)     Dem_Memory_ConstHandlePtrType;
/*! Modifyable Pointer to a memory handle (rarely used!) */
typedef P2VAR(Dem_Memory_HandleType, TYPEDEF, DEM_SHARED_DATA)            Dem_Memory_VaribleHandlePtrType;

#endif /* DEM_MEMORY_TYPES_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_Memory_Types.h
 *********************************************************************************************************************/
