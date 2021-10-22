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
/*! \addtogroup Dem_SatelliteInfo
 *  \{
 *  \file       Dem_SatelliteInfo_Types.h
 *  \brief      Implementation file for the MICROSAR Dem
 *  \details    Public types of SatelliteInfo subcomponent
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

#if !defined (DEM_SATELLITEINFO_TYPES_H)
#define DEM_SATELLITEINFO_TYPES_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                        /* Dem module header */
/* ------------------------------------------------------------------------- */
#include "Dem_Int.h"
#include "Dem_Com_Types.h"
/* ------------------------------------------------------------------------- */


/* ********************************************************************************************************************
 *  SUBCOMPONENT CONSTANT MACROS
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  SUBCOMPONENT FUNCTION MACROS
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  SUBCOMPONENT DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/*! The data of a satellite */
struct Dem_SatelliteInfo_s
{
  uint8 InitStatus;                              /*!< Initialization status */
  uint8 SatelliteStatus;                         /*!< Status flags */
};

/*! Converts between a Dem_SatelliteInfo_Type and a raw data type. */
union Dem_SatelliteInfo_Type_u
{                                                                                                                                /* PRQA S 0750 */ /* MD_MSR_18.4 */
  volatile struct Dem_SatelliteInfo_s Data;      /*!< The detailed data type. */
  volatile Dem_Com_ProcessorWordType   Raw;      /*!< The raw data type intended for queue communication. */
};

/*! Converts between a Dem_SatelliteInfo_Type and a raw data type. */
typedef union Dem_SatelliteInfo_Type_u Dem_SatelliteInfo_Type;

/*! Data type which performs compile time checks */
struct Dem_SatelliteInfo_SizeCheck_s
{
  /*! Check that Dem_SatelliteInfo_s fits into one word (uint32). */
  unsigned int Dem_Satellite_VerifySizeOfSatelliteInfo :
    (sizeof(struct Dem_SatelliteInfo_s) <= sizeof(Dem_Com_ProcessorWordType) ? 1 : -1);
};

#endif /* DEM_SATELLITEINFO_TYPES_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_SatelliteInfo_Types.h
 *********************************************************************************************************************/
