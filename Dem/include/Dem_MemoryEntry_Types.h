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
/*! \addtogroup Dem_MemoryEntry
 *  \{
 *  \file       Dem_MemoryEntry_Types.h
 *  \brief      Diagnostic Event Manager (Dem) header file
 *  \details    Encapsulates the Memory entry and known data stored in the memory entry
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

#if !defined (DEM_MEMORYENTRY_TYPES_H)
#define DEM_MEMORYENTRY_TYPES_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                        /* Dem module header */
/* ------------------------------------------------------------------------- */
#include "Dem_Int.h"
#include "Dem_MemoryEntry_Fwd.h"
/* ------------------------------------------------------------------------- */

/* ********************************************************************************************************************
 *  SUBCOMPONENT CONSTANT MACROS
 *********************************************************************************************************************/
/*!
* \defgroup  Dem_MemoryEntry_Handles  Macros encoding handles for specific memory entries.
* \{
*/
#define DEM_MEMORYENTRY_HANDLE_INVALID          0xFFU                                                           /*!< Value for an invalid memory entry handle */
#define DEM_MEMORYENTRY_HANDLE_PRIMARY          0U                                                              /*!< Value for the first primary memory entry handle */
#define DEM_MEMORYENTRY_HANDLE_SECONDARY        DEM_CFG_GLOBAL_PRIMARY_SIZE                                     /*!< Value for the first secondary memory entry handle */
#if (DEM_CFG_SUPPORT_SECONDARY == STD_ON)
#define DEM_MEMORYENTRY_HANDLE_READOUTBUFFER    DEM_CFG_GLOBAL_PRIMARY_SIZE + DEM_CFG_GLOBAL_SECONDARY_SIZE     /*!< Value for the first readout buffer memory entry handle */
#else
#define DEM_MEMORYENTRY_HANDLE_READOUTBUFFER    DEM_CFG_GLOBAL_PRIMARY_SIZE                                     /*!< Value for the first readout buffer memory entry handle */
#endif
/*!
* \}
*/

/*!
* \defgroup  Dem_MemoryEntry_StandardEnvironmentalDataBytes  Macros encoding the bytes of the standard environmental data.
* \{
*/
#define DEM_MEMORYENTRY_STDENVDATA_STATUS              0x00U  /*!< Status */
#define DEM_MEMORYENTRY_STDENVDATA_FIRSTODOMETER       0x01U  /*!< Original Odometer */
#define DEM_MEMORYENTRY_STDENVDATA_CURRENTODOMETER     0x03U  /*!< Most Recent Odometer */
#define DEM_MEMORYENTRY_STDENVDATA_TIME                0x05U  /*!< Operating Time */
#define DEM_MEMORYENTRY_STDENVDATA_TIMESTATUS          0x09U  /*!< Operating Time Status */
/*!
* \}
*/

#define DEM_MEMORYENTRY_STD_ENV_DATA_SIZE       5U     /* Size of Standard Environmental data stored in a memory entry*/
#define DEM_MEMORYENTRY_EXT_ENV_DATA_SIZE       10U    /* Size of Extended Environmental data stored in a memory entry*/

/* ********************************************************************************************************************
 *  SUBCOMPONENT FUNCTION MACROS
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  SUBCOMPONENT DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/*! Pointer to an event memory entry */
typedef P2VAR(Dem_Cfg_PrimaryEntryType, TYPEDEF, DEM_NVM_DATA)       Dem_MemoryEntry_EntryPtrType;
/*! Non-writeable pointer to an event memory entry */
typedef P2CONST(Dem_Cfg_PrimaryEntryType, TYPEDEF, DEM_NVM_DATA)     Dem_MemoryEntry_ConstEntryPtrType;

#endif /* DEM_MEMORYENTRY_TYPES_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_MemoryEntry_Types.h
 *********************************************************************************************************************/
