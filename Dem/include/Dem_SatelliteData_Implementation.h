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
/*! \addtogroup Dem_SatelliteData
 *  \{
 *  \file       Dem_SatelliteData_Implementation.h
 *  \brief      Diagnostic Event Manager (Dem) header file
 *  \details    Implementation of SatelliteData subcomponent
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

#if !defined (DEM_SATELLITEDATA_IMPLEMENTATION_H)
#define DEM_SATELLITEDATA_IMPLEMENTATION_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                  /* Own subcomponent header */
/* ------------------------------------------------------------------------- */
#include "Dem_SatelliteData_Interface.h"

                                                    /* Used subcomponent API */
/* ------------------------------------------------------------------------- */

                                                   /* Subcomponents callbacks*/
/* ------------------------------------------------------------------------- */
#include "Dem_Monitor_Interface.h"

/* ********************************************************************************************************************
 *  SUBCOMPONENT CONSTANT MACROS
 *********************************************************************************************************************/
#define DEM_SATELLITEDATA_SHARED_STATUS_BYTESIZE DEM_1BYTE

#define DEM_SATELLITEDATA_MONITOR_STATUS         DEM_NBIT(DEM_SATELLITEDATA_MONITOR_STATUS_SIZE, DEM_SATELLITEDATA_MONITOR_STATUS_POS)  /*!< Bit mask for monitor status bit(s) */
#define DEM_SATELLITEDATA_MONITOR_STATUS_MASK    DEM_NBIT_MASK(DEM_SATELLITEDATA_MONITOR_STATUS_SIZE, DEM_SATELLITEDATA_MONITOR_STATUS_POS, DEM_SATELLITEDATA_SHARED_STATUS_BYTESIZE)  /*!< Negated bit mask for monitor status bit(s) */
#if ( ((DEM_SATELLITEDATA_MONITOR_STATUS & DEM_MONITOR_STATUS_TF) != DEM_MONITOR_STATUS_TF) \
   || ((DEM_SATELLITEDATA_MONITOR_STATUS & DEM_MONITOR_STATUS_TNCTOC) != DEM_MONITOR_STATUS_TNCTOC) )
# error "Satellite's monitor status definition is not compatible"
#endif

#define DEM_SATELLITEDATA_DEBOUNCE_STATUS        DEM_NBIT(DEM_SATELLITEDATA_DEBOUNCE_STATUS_SIZE, DEM_SATELLITEDATA_DEBOUNCE_STATUS_POS)  /*!< Bit mask for debounce status bit(s) */
#define DEM_SATELLITEDATA_DEBOUNCE_STATUS_MASK   DEM_NBIT_MASK(DEM_SATELLITEDATA_DEBOUNCE_STATUS_SIZE, DEM_SATELLITEDATA_DEBOUNCE_STATUS_POS, DEM_SATELLITEDATA_SHARED_STATUS_BYTESIZE)  /*!< Negated bit mask for debounce status bit(s) */

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
 * \addtogroup Dem_SatelliteData_Properties
 * \{
 */

/* ****************************************************************************
 % Dem_SatelliteData_SetDebounceStatus
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_SatelliteData_DataType, DEM_CODE)
Dem_SatelliteData_SetDebounceStatus(
  CONST(Dem_SatelliteData_DataType, AUTOMATIC)  SatelliteData,
  CONST(Dem_Debounce_StatusType, AUTOMATIC) DebounceStatus
  )
{
  Dem_SatelliteData_DataType lReturnValue;                                                                                       /* PRQA S 0759 */ /* MD_MSR_18.4 */
  lReturnValue = SatelliteData;
  lReturnValue.Data.SharedStatus =  (uint8)(
      (lReturnValue.Data.SharedStatus & DEM_SATELLITEDATA_DEBOUNCE_STATUS_MASK)
    | (DebounceStatus & DEM_SATELLITEDATA_DEBOUNCE_STATUS) );
  return lReturnValue;
}

/* ****************************************************************************
 % Dem_SatelliteData_GetDebounceStatus
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_SatelliteData_GetDebounceStatus(
  CONST(Dem_SatelliteData_DataType, AUTOMATIC)  SatelliteData
  )
{
  return (uint8)(SatelliteData.Data.SharedStatus & DEM_SATELLITEDATA_DEBOUNCE_STATUS);
}

/* ****************************************************************************
 % Dem_SatelliteData_SetDebounceData
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_SatelliteData_DataType, DEM_CODE)
Dem_SatelliteData_SetDebounceData(
  CONST(Dem_SatelliteData_DataType, AUTOMATIC)  SatelliteData,
  CONST(Dem_Debounce_DataType, AUTOMATIC) DebounceData
  )
{
  Dem_SatelliteData_DataType lReturnValue;                                                                                       /* PRQA S 0759 */ /* MD_MSR_18.4 */
  lReturnValue = SatelliteData;
  lReturnValue.Data.DebounceData = DebounceData;
  return lReturnValue;
}

/* ****************************************************************************
 % Dem_SatelliteData_GetDebounceData
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_Debounce_DataType, DEM_CODE)
Dem_SatelliteData_GetDebounceData(
  CONST(Dem_SatelliteData_DataType, AUTOMATIC)  SatelliteData
  )
{
  return SatelliteData.Data.DebounceData;
}

/* ****************************************************************************
 % Dem_SatelliteData_SetMonitorStatus
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_SatelliteData_DataType, DEM_CODE)
Dem_SatelliteData_SetMonitorStatus(
  CONST(Dem_SatelliteData_DataType, AUTOMATIC)  SatelliteDataValue,
  CONST(Dem_MonitorStatusType, AUTOMATIC)       MonitorStatusBits
  )
{
  Dem_SatelliteData_DataType lReturnValue;                                                                                       /* PRQA S 0759 */ /* MD_MSR_18.4 */
  lReturnValue = SatelliteDataValue;
  lReturnValue.Data.SharedStatus = (uint8)(
      (lReturnValue.Data.SharedStatus & DEM_SATELLITEDATA_MONITOR_STATUS_MASK)
    | (MonitorStatusBits & DEM_SATELLITEDATA_MONITOR_STATUS) );
  return lReturnValue;
}

/* ****************************************************************************
 % Dem_SatelliteData_GetMonitorStatus
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_MonitorStatusType, DEM_CODE)
Dem_SatelliteData_GetMonitorStatus(
  CONST(Dem_SatelliteData_DataType, AUTOMATIC)  SatelliteDataValue
  )
{
  return (Dem_MonitorStatusType)(SatelliteDataValue.Data.SharedStatus & DEM_SATELLITEDATA_MONITOR_STATUS);
}

/* ****************************************************************************
 % Dem_SatelliteData_SetQueueState
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_SatelliteData_DataType, DEM_CODE)
Dem_SatelliteData_SetQueueStatus(
  CONST(Dem_SatelliteData_DataType, AUTOMATIC)  SatelliteDataValue,
  CONST(Dem_EventQueue_StatusType, AUTOMATIC) QueueStatus
  )
{
  Dem_SatelliteData_DataType lReturnValue;                                                                                       /* PRQA S 0759 */ /* MD_MSR_18.4 */

  lReturnValue = SatelliteDataValue;
  lReturnValue.Data.QueueStatus = QueueStatus;

  return lReturnValue;
}

/* ****************************************************************************
 % Dem_SatelliteData_GetQueueState
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_EventQueue_StatusType, DEM_CODE)
Dem_SatelliteData_GetQueueStatus(
  CONST(Dem_SatelliteData_DataType, AUTOMATIC)  SatelliteDataValue
  )
{
  return SatelliteDataValue.Data.QueueStatus;
}

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* ********************************************************************************************************************
 *  SUBCOMPONENT FUNCTION DEFINITIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \addtogroup Dem_SatelliteData_Public
 * \{
 */

/* ****************************************************************************
 % Dem_SatelliteData_GetInitValue
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_SatelliteData_DataType, DEM_CODE)
Dem_SatelliteData_GetInitValue(
  void
  )
{
  Dem_SatelliteData_DataType lSatelliteData;                                                                                     /* PRQA S 0759 */ /* MD_MSR_18.4 */
  lSatelliteData.Raw = 0;
  lSatelliteData = Dem_SatelliteData_SetMonitorStatus(lSatelliteData, DEM_MONITOR_STATUS_INITIAL);
  return lSatelliteData;
}

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* DEM_SATELLITEDATA_IMPLEMENTATION_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_SatelliteData_Implementation.h
 *********************************************************************************************************************/
