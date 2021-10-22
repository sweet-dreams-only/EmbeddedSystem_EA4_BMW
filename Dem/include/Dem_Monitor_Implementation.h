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
/*!  Project    MICROSAR Diagnostic Event Manager (Dem)
 *  \addtogroup Dem_Monitor
 *  \{
 *  \file       Dem_Monitor_Implementation.h
 *  \brief      Diagnostic Event Manager (Dem) Implementation file
 *  \details
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

#if !defined (DEM_MONITOR_IMPLEMENTATION_H)
#define DEM_MONITOR_IMPLEMENTATION_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                  /* Own subcomponent header */
/* ------------------------------------------------------------------------- */
#include "Dem_Monitor_Interface.h"

                                                    /* Used subcomponent API */
/* ------------------------------------------------------------------------- */
#include "Dem_SatelliteData_Implementation.h"

                                                   /* Subcomponents callbacks*/
/* ------------------------------------------------------------------------- */

/* ********************************************************************************************************************
 *  SUBCOMPONENT CONSTANT MACROS
 *********************************************************************************************************************/

#if ( (DEM_MONITOR_STATUS_TF < DEM_SATELLITEDATA_MONITOR_STATUS_POS) \
   || (DEM_MONITOR_STATUS_TF >= DEM_SATELLITEDATA_MONITOR_STATUS_POS + DEM_SATELLITEDATA_MONITOR_STATUS_SIZE) \
   || (DEM_MONITOR_STATUS_TNCTOC < DEM_SATELLITEDATA_MONITOR_STATUS_POS) \
   || (DEM_MONITOR_STATUS_TNCTOC >= DEM_SATELLITEDATA_MONITOR_STATUS_POS + DEM_SATELLITEDATA_MONITOR_STATUS_SIZE) )
# error "Monitor status definition not compatible with satellite data definition"
#endif

#if (DEM_MONITOR_STATUS_TF != DEM_BIT(0))
# error "Monitor status definition is not compatible"
#endif

#if (DEM_MONITOR_STATUS_TNCTOC != DEM_BIT(1))
# error "Monitor status definition is not compatible"
#endif

/* ********************************************************************************************************************
 *  SUBCOMPONENT FUNCTION MACROS
 *********************************************************************************************************************/
#define DEM_MONITOR_STATUS_TF_MASK               DEM_BIT_MASK(0, DEM_1BYTE)  /*!< Byte mask to reset test failed */
#define DEM_MONITOR_STATUS_TNCTOC_MASK           DEM_BIT_MASK(1, DEM_1BYTE)  /*!< Byte mask to reset test failed this operating cycle*/

/* ********************************************************************************************************************
 *  SUBCOMPONENT OBJECT FUNCTION DEFINITIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \addtogroup Dem_Monitor_Properties
 * \{
 */

/* ****************************************************************************
 % Dem_Monitor_TestMonitorStatusTF
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Monitor_TestMonitorStatusTF(
  CONST(Dem_MonitorStatusType, AUTOMATIC)  MonitorStatus
  )
{
  return (boolean)(((MonitorStatus) & DEM_MONITOR_STATUS_TF) != 0);
}

/* ****************************************************************************
 % Dem_Monitor_TestMonitorStatusTNCTOC
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Monitor_TestMonitorStatusTNCTOC(
  CONST(Dem_MonitorStatusType, AUTOMATIC)  MonitorStatus
  )
{
  return (boolean)(((MonitorStatus) & DEM_MONITOR_STATUS_TNCTOC) != 0);
}

/* ****************************************************************************
 % Dem_Monitor_SetMonitorStatusTF
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_MonitorStatusType, DEM_CODE)
Dem_Monitor_SetMonitorStatusTF(
  CONST(Dem_MonitorStatusType, AUTOMATIC)  MonitorStatus
  )
{
  return ((Dem_MonitorStatusType)((MonitorStatus) | DEM_MONITOR_STATUS_TF));
}

/* ****************************************************************************
 % Dem_Monitor_SetMonitorStatusTNCTOC
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_MonitorStatusType, DEM_CODE)
Dem_Monitor_SetMonitorStatusTNCTOC(
  CONST(Dem_MonitorStatusType, AUTOMATIC)  MonitorStatus
  )
{
  return ((Dem_MonitorStatusType)((MonitorStatus) | DEM_MONITOR_STATUS_TNCTOC));
}

/* ****************************************************************************
 % Dem_Monitor_ResetMonitorStatusTF
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_MonitorStatusType, DEM_CODE)
Dem_Monitor_ResetMonitorStatusTF(
  CONST(Dem_MonitorStatusType, AUTOMATIC)  MonitorStatus
  )
{
  return ((Dem_MonitorStatusType)((MonitorStatus) & DEM_MONITOR_STATUS_TF_MASK));
}

/* ****************************************************************************
 % Dem_Monitor_ResetMonitorStatusTNCTOC
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_MonitorStatusType, DEM_CODE)
Dem_Monitor_ResetMonitorStatusTNCTOC(
  CONST(Dem_MonitorStatusType, AUTOMATIC)  MonitorStatus
  )
{
  return ((Dem_MonitorStatusType)((MonitorStatus) & DEM_MONITOR_STATUS_TNCTOC_MASK));
}

/* ****************************************************************************
 % Dem_Monitor_ResetMonitorStatus
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_SatelliteData_DataType, DEM_CODE)
Dem_Monitor_ResetMonitorStatus(
  CONST(Dem_SatelliteData_DataType, AUTOMATIC)  SatelliteDataValue
  )
{
  return Dem_SatelliteData_SetMonitorStatus(SatelliteDataValue, DEM_MONITOR_STATUS_INITIAL);
}

/* ****************************************************************************
 % Dem_Monitor_GetMonitorStatus
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_MonitorStatusType, DEM_CODE)
Dem_Monitor_GetMonitorStatus(
  CONST(Dem_SatelliteData_DataType, AUTOMATIC)  SatelliteDataValue
  )
{
  return Dem_SatelliteData_GetMonitorStatus(SatelliteDataValue);
}

/* ****************************************************************************
 % Dem_Monitor_SetMonitorStatus
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_SatelliteData_DataType, DEM_CODE)
Dem_Monitor_SetMonitorStatus(
  CONST(Dem_SatelliteData_DataType, AUTOMATIC)  SatelliteDataValue,
  CONST(Dem_MonitorStatusType, AUTOMATIC)       MonitorStatusBits
  )
{
  return Dem_SatelliteData_SetMonitorStatus(SatelliteDataValue, MonitorStatusBits);
}

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
 * \addtogroup Dem_Monitor_Private
 * \{
 */

/* ****************************************************************************
 % Dem_Cfg_GlobalTriggerOnMonitorStatusFPtr
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_GlobalTriggerOnMonitorStatusFPtrType, DEM_CODE)
Dem_Cfg_GlobalTriggerOnMonitorStatusFPtr(
  void
  )
{
  return (Dem_GlobalTriggerOnMonitorStatusFPtrType)DEM_CFG_GLOBALTRIGGERONMONITORSTATUS_FUNC;                                    /* PRQA S 0428 */ /* MD_DEM_16.9_fp */
}

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* ********************************************************************************************************************
 *  SUBCOMPONENT API FUNCTION DEFINITIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \addtogroup Dem_Monitor_Public
 * \{
 */

/* ****************************************************************************
 % Dem_Monitor_CalculateMonitorStatus
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_MonitorStatusType, DEM_CODE)
Dem_Monitor_CalculateMonitorStatus(
  CONST(Dem_MonitorStatusType, AUTOMATIC)   MonitorStatusValue,
  CONST(Dem_EventStatusType, AUTOMATIC)     MonitorTrigger
  )
{
  Dem_MonitorStatusType lReturnValue;
  lReturnValue = MonitorStatusValue;
  switch (MonitorTrigger)
  {
  case DEM_EVENT_STATUS_FAILED:
    lReturnValue = Dem_Monitor_SetMonitorStatusTF(lReturnValue);
    lReturnValue = Dem_Monitor_ResetMonitorStatusTNCTOC(lReturnValue);
    break;
  case DEM_EVENT_STATUS_PASSED:
    lReturnValue = Dem_Monitor_ResetMonitorStatusTF(lReturnValue);
    lReturnValue = Dem_Monitor_ResetMonitorStatusTNCTOC(lReturnValue);
    break;
  default:
    break;
  }

  return lReturnValue;
}

/* ****************************************************************************
 % Dem_Monitor_ResetTNCTOC
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_SatelliteData_DataType, DEM_CODE)
Dem_Monitor_ResetTNCTOC(
  CONST(Dem_SatelliteData_DataType, AUTOMATIC)  SatelliteDataValue
  )
{
  Dem_MonitorStatusType lMonitorStatus;
  lMonitorStatus = Dem_Monitor_SetMonitorStatusTNCTOC(Dem_Monitor_GetMonitorStatus(SatelliteDataValue));
  return Dem_SatelliteData_SetMonitorStatus(SatelliteDataValue, lMonitorStatus);
}

/* ****************************************************************************
 % Dem_Monitor_NotifyMonitorStatusChange
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Monitor_NotifyMonitorStatusChange(
  CONST(Dem_EventIdType, AUTOMATIC)   EventId
  )
{
  if (Dem_Cfg_GlobalTriggerOnMonitorStatusFPtr() != NULL_PTR)
  {
    (void)(*Dem_Cfg_GlobalTriggerOnMonitorStatusFPtr())(EventId);                                                                /* SBSW_DEM_GLOBALTRIGGERONMONITORSTATUS_FPTR */
  }
}

/* ****************************************************************************
 % Dem_Monitor_TestTF
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Monitor_TestTF(
  CONST(Dem_SatelliteData_DataType, AUTOMATIC)  SatelliteDataValue
  )
{
  return Dem_Monitor_TestMonitorStatusTF(Dem_Monitor_GetMonitorStatus(SatelliteDataValue));
}

/* ****************************************************************************
 % Dem_Monitor_TestTNCTOC
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Monitor_TestTNCTOC(
  CONST(Dem_SatelliteData_DataType, AUTOMATIC)  SatelliteDataValue
  )
{
  return Dem_Monitor_TestMonitorStatusTNCTOC(Dem_Monitor_GetMonitorStatus(SatelliteDataValue));
}

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* DEM_MONITOR_IMPLEMENTATION_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_Monitor_Implementation.h
 *********************************************************************************************************************/
