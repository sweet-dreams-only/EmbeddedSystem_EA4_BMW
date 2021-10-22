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
/*! \ingroup Dem_Satellite
 *  \addtogroup Dem_SatelliteData
 *  \{
 *  \file       Dem_SatelliteData_Types.h
 *  \brief      Implementation file for the MICROSAR Dem
 *  \details    Public types of SatelliteData subcomponent
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

#if !defined (DEM_SATELLITEDATA_TYPES_H)
#define DEM_SATELLITEDATA_TYPES_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                        /* Dem module header */
/* ------------------------------------------------------------------------- */
#include "Dem_Int.h"
#include "Dem_Com_Types.h"
#include "Dem_EventQueue_Types.h"
#include "Dem_DebounceBase_Fwd.h"
/* ------------------------------------------------------------------------- */


/* ********************************************************************************************************************
 *  SUBCOMPONENT CONSTANT MACROS
 *********************************************************************************************************************/
/*! The first monitor status bit within SharedStatus in Dem_SatelliteData_Data */
#define DEM_SATELLITEDATA_MONITOR_STATUS_POS     0

/*! The number of monitor status bits within SharedStatus in Dem_SatelliteData_Data  */
#define DEM_SATELLITEDATA_MONITOR_STATUS_SIZE    4

/*! The first debounce status bit within SharedStatus in Dem_SatelliteData_Data  */
#define DEM_SATELLITEDATA_DEBOUNCE_STATUS_POS    4

/*! The number of debounce status bits within SharedStatus in Dem_SatelliteData_Data  */
#define DEM_SATELLITEDATA_DEBOUNCE_STATUS_SIZE   4

/* ********************************************************************************************************************
 *  SUBCOMPONENT FUNCTION MACROS
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  SUBCOMPONENT DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/*! The data of a single satellite element related to an event.  */
struct Dem_SatelliteData_Data_s
{
  Dem_Debounce_DataType  DebounceData;     /*!< The debounce data. */
  Dem_EventQueue_StatusType   QueueStatus;      /*!< The queue status of this element. */
  uint8                  SharedStatus;     /*!< packed DebounceStatus and MonitorStatus. */
};

/*! Converts between a Dem_SatelliteData_DataType and a raw data type. */
union Dem_SatelliteData_Data_u
{                                                                                                                                /* PRQA S 0750 */ /* MD_MSR_18.4 */
  volatile struct Dem_SatelliteData_Data_s Data;     /*!< The detailed data type. */
  volatile Dem_Com_ProcessorWordType Raw;            /*!< The raw data type intended for queue communication. */
};

/*! Converts between a Dem_SatelliteData_DataType and a raw data type. */
typedef union Dem_SatelliteData_Data_u Dem_SatelliteData_DataType;
/*! Reference to modifiable SatelliteData object. */
typedef P2VAR(Dem_SatelliteData_DataType, DEM_VAR_NOINIT, TYPEDEF) Dem_SatelliteData_DataPtrType;
/*! Reference to non-modifiable SatelliteData object. */
typedef P2CONST(Dem_SatelliteData_DataType, DEM_VAR_NOINIT, TYPEDEF) Dem_SatelliteData_ConstDataPtrType;

/*! Data type which performs compile time checks */
struct Dem_SatelliteData_DataSizeCheck_s
{
  /*! Check that Dem_SatelliteData_Data_s fits into one word (uint32). */
  unsigned int Dem_SatelliteData_VerifySizeOfSatelliteData :
    (sizeof(struct Dem_SatelliteData_Data_s) <= sizeof(Dem_Com_ProcessorWordType) ? 1 : -1);
};

#endif /* DEM_SATELLITEDATA_TYPES_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_SatelliteData_Types.h
 *********************************************************************************************************************/
