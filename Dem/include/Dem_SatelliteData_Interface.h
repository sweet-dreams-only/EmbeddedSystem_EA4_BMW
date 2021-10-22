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
/*! \ingroup    Dem_Satellite
 *  \defgroup   Dem_SatelliteData Satellite Data
 *  \{
 *  \file       Dem_SatelliteData_Interface.h
 *  \brief      Diagnostic Event Manager (Dem) header file
 *  \details    Public interface of SatelliteData subcomponent
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

#if !defined (DEM_SATELLITEDATA_INTERFACE_H)
#define DEM_SATELLITEDATA_INTERFACE_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                        /* Dem module header */
/* ------------------------------------------------------------------------- */
#include "Dem_SatelliteData_Types.h"
/* ------------------------------------------------------------------------- */

/* ********************************************************************************************************************
 *  SUBCOMPONENT OBJECT FUNCTION DECLARATIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \defgroup Dem_SatelliteData_Properties Properties
 * \{
 */

/* ****************************************************************************
 * Dem_SatelliteData_SetDebounceStatus
 *****************************************************************************/
/*!
 * \brief         Set the given debounce status into the satellite data object.
 *
 * \details       Set the given debounce status into the satellite data object.
 *
 * \param[in]     SatelliteData
 *                The data object to modify
 *
 * \param[in]     DebounceStatus
 *                The data to write to SatelliteData.
 *
 * \return        The modified satellite data object.
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_SatelliteData_DataType, DEM_CODE)
Dem_SatelliteData_SetDebounceStatus(
  CONST(Dem_SatelliteData_DataType, AUTOMATIC)  SatelliteData,
  CONST(Dem_Debounce_StatusType, AUTOMATIC) DebounceStatus
  );

/* ****************************************************************************
 * Dem_SatelliteData_GetDebounceStatus
 *****************************************************************************/
/*!
 * \brief         Reads the debounce status from the given satellite data object.
 *
 * \details       Reads the debounce status from the given satellite data object.
 *
 * \param[in]     SatelliteData
 *                The data object to read from.
 *
 * \return        The requested data.
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_SatelliteData_GetDebounceStatus(
  CONST(Dem_SatelliteData_DataType, AUTOMATIC)  SatelliteData
  );

/* ****************************************************************************
 * Dem_SatelliteData_SetDebounceData
 *****************************************************************************/
/*!
 * \brief         Set the given debounce data into the satellite data object.
 *
 * \details       Set the given debounce data into the satellite data object.
 *
 * \param[in]     SatelliteData
 *                The data object to modify.
 *
 * \param[in]     DebounceData
 *                The data to write to SatelliteData.
 *
 * \return        The modified satellite data object.
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_SatelliteData_DataType, DEM_CODE)
Dem_SatelliteData_SetDebounceData(
  CONST(Dem_SatelliteData_DataType, AUTOMATIC)  SatelliteData,
  CONST(Dem_Debounce_DataType, AUTOMATIC)  DebounceData
  );

/* ****************************************************************************
 * Dem_SatelliteData_GetDebounceData
 *****************************************************************************/
/*!
 * \brief         Reads the debounce data from the given satellite data object.
 *
 * \details       Reads the debounce data from the given satellite data object.
 *
 * \param[in]     SatelliteData
 *                The data object to read from.
 *
 * \return        The requested data.
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_Debounce_DataType, DEM_CODE)
Dem_SatelliteData_GetDebounceData(
  CONST(Dem_SatelliteData_DataType, AUTOMATIC)  SatelliteData
  );

/* ****************************************************************************
 * Dem_SatelliteData_SetMonitorStatus
 *****************************************************************************/
/*!
 * \brief         Update the monitor status into the satellite data object.
 *
 * \details       Update the monitor status into the satellite data object.
 *
 * \param[in]     SatelliteDataValue
 *                The SatelliteData value to modify.
 *
 * \param[in]     MonitorStatusBits
 *                The data to write to SatelliteData.
 *
 * \return        The new SatelliteData value.
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_SatelliteData_DataType, DEM_CODE)
Dem_SatelliteData_SetMonitorStatus(
  CONST(Dem_SatelliteData_DataType, AUTOMATIC)  SatelliteDataValue,
  CONST(Dem_MonitorStatusType, AUTOMATIC)       MonitorStatusBits
  );

/* ****************************************************************************
 * Dem_SatelliteData_GetMonitorStatus
 *****************************************************************************/
/*!
 * \brief         Reads the monitor status from the given satellite data object.
 *
 * \details       Reads the monitor status from the given satellite data object.
 *
 * \param[in]     SatelliteDataValue
 *                The data object to read from.
 *
 * \return        The MonitorStatus.
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_MonitorStatusType, DEM_CODE)
Dem_SatelliteData_GetMonitorStatus(
  CONST(Dem_SatelliteData_DataType, AUTOMATIC)  SatelliteDataValue
  );

/* ****************************************************************************
 * Dem_SatelliteData_SetQueueStatus
 *****************************************************************************/
/*!
 * \brief         Update the queue status into the satellite data object.
 *
 * \details       Update the queue status into the satellite data object.
 *
 * \param[in]     SatelliteDataValue
 *                The SatelliteData value to modify.
 *
 * \param[in]     QueueStatus
 *                The data to write to SatelliteData.
 *
 * \return        The new SatelliteData value.
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_SatelliteData_DataType, DEM_CODE)
Dem_SatelliteData_SetQueueStatus(
  CONST(Dem_SatelliteData_DataType, AUTOMATIC)  SatelliteDataValue,
  CONST(Dem_EventQueue_StatusType, AUTOMATIC)  QueueStatus
  );

/* ****************************************************************************
 * Dem_SatelliteData_GetQueueStatus
 *****************************************************************************/
/*!
 * \brief         Reads the queue status from the given satellite data object.
 *
 * \details       Reads the queue status from the given satellite data object.
 *
 * \param[in]     SatelliteDataValue
 *                The data object to read from.
 *
 * \return        The requested data.
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_EventQueue_StatusType, DEM_CODE)
Dem_SatelliteData_GetQueueStatus(
  CONST(Dem_SatelliteData_DataType, AUTOMATIC)  SatelliteDataValue
  );

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
 * \defgroup Dem_SatelliteData_Public Public Methods
 * \{
 */

/* ****************************************************************************
 * Dem_SatelliteData_GetInitValue
 *****************************************************************************/
/*!
 * \brief         Initialize the satellite data.
 *
 * \details       Initialize the satellite data.
 *
 * \return        The initialized data object.
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_SatelliteData_DataType, DEM_CODE)
Dem_SatelliteData_GetInitValue(
  void
  );

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* DEM_SATELLITEDATA_INTERFACE_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_SatelliteData_Interface.h
 *********************************************************************************************************************/
