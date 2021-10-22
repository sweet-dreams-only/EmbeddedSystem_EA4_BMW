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
 *  \file       Dem_SatelliteInfo_Implementation.h
 *  \brief      Diagnostic Event Manager (Dem) header file
 *  \details    Implementation of SatelliteInfo subcomponent
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

#if !defined (DEM_SATELLITEINFO_IMPLEMENTATION_H)
#define DEM_SATELLITEINFO_IMPLEMENTATION_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                  /* Own subcomponent header */
/* ------------------------------------------------------------------------- */
#include "Dem_SatelliteInfo_Interface.h"

                                                    /* Used subcomponent API */
/* ------------------------------------------------------------------------- */

                                                   /* Subcomponents callbacks*/
/* ------------------------------------------------------------------------- */

/* ********************************************************************************************************************
 *  SUBCOMPONENT CONSTANT MACROS
 *********************************************************************************************************************/

/*! Initial satellite info value */
#define DEM_SATELLITEINFO_INIT_VALUE           0

#define DEM_SATELLITEINFO_SATELLITE_STATUS_SIZE  DEM_1BYTE      /*!< Size of the satellite status type */
#define DEM_SATELLITEINFO_QUEUE_STATUS_POS       0              /*!< Bit offset of the status */

#define DEM_SATELLITEINFO_QUEUE_STATUS           DEM_BIT(DEM_SATELLITEINFO_QUEUE_STATUS_POS)  /*!< Bit mask for queue status bit(s) */
#define DEM_SATELLITEINFO_QUEUE_STATUS_MASK      DEM_BIT_MASK(DEM_SATELLITEINFO_QUEUE_STATUS_POS, DEM_SATELLITEINFO_SATELLITE_STATUS_SIZE)  /*!< Negated bit mask for queue status bit(s) */

/* ********************************************************************************************************************
 *  SUBCOMPONENT FUNCTION MACROS
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  SUBCOMPONENT DATA TYPES AND STRUCTURES
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
 * \addtogroup Dem_SatelliteInfo_Properties
 * \{
 */

/* ****************************************************************************
 % Dem_SatelliteInfo_GetInitValue
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_SatelliteInfo_Type, DEM_CODE)
Dem_SatelliteInfo_GetInitValue(
  void
  )
{
  Dem_SatelliteInfo_Type lSatelliteInfo;                                                                                         /* PRQA S 0759 */ /* MD_MSR_18.4 */
  lSatelliteInfo.Raw = DEM_SATELLITEINFO_INIT_VALUE;
  return lSatelliteInfo;
}

/* ****************************************************************************
 % Dem_SatelliteInfo_SetInitStatus
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_SatelliteInfo_Type, DEM_CODE)
Dem_SatelliteInfo_SetInitStatus(
  CONST(Dem_SatelliteInfo_Type, AUTOMATIC)  SatelliteInfo,
  CONST(uint8, AUTOMATIC) InitStatus
  )
{
  Dem_SatelliteInfo_Type lReturnValue;                                                                                           /* PRQA S 0759 */ /* MD_MSR_18.4 */
  lReturnValue = SatelliteInfo;
  lReturnValue.Data.InitStatus = InitStatus;
  return lReturnValue;
}

/* ****************************************************************************
 % Dem_SatelliteInfo_GetInitStatus
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_SatelliteInfo_GetInitStatus(
  CONST(Dem_SatelliteInfo_Type, AUTOMATIC)  SatelliteInfo
  )
{
  return SatelliteInfo.Data.InitStatus;
}

/* ****************************************************************************
 % Dem_SatelliteInfo_SetQueueUpdated
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_SatelliteInfo_Type, DEM_CODE)
Dem_SatelliteInfo_SetQueueUpdated(
  CONST(Dem_SatelliteInfo_Type, AUTOMATIC)  SatelliteInfo,
  CONST(boolean, AUTOMATIC) QueueUpdated
  )
{
  Dem_SatelliteInfo_Type lReturnValue;                                                                                           /* PRQA S 0759 */ /* MD_MSR_18.4 */
  lReturnValue = SatelliteInfo;
  lReturnValue.Data.SatelliteStatus = (uint8)(
      (lReturnValue.Data.SatelliteStatus & DEM_SATELLITEINFO_QUEUE_STATUS_MASK)
    | (QueueUpdated & DEM_SATELLITEINFO_QUEUE_STATUS) );
  return lReturnValue;
}

/* ****************************************************************************
 % Dem_SatelliteInfo_GetQueueUpdated
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_SatelliteInfo_GetQueueUpdated(
  CONST(Dem_SatelliteInfo_Type, AUTOMATIC)  SatelliteInfo
  )
{
  return (boolean)((SatelliteInfo.Data.SatelliteStatus & DEM_SATELLITEINFO_QUEUE_STATUS) != 0);
}

#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* DEM_SATELLITEINFO_IMPLEMENTATION_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_SatelliteInfo_Implementation.h
 *********************************************************************************************************************/
