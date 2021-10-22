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
/*! \addtogroup Dem_FilterData
 *  \{
 *  \file       Dem_FilterData_Implementation.h
 *  \brief      Diagnostic Event Manager (Dem) header file
 *  \details    Implementation of FilterData subcomponent
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

#if !defined (DEM_FILTERDATA_IMPLEMENTATION_H)
#define DEM_FILTERDATA_IMPLEMENTATION_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                  /* Own subcomponent header */
/* ------------------------------------------------------------------------- */
#include "Dem_FilterData_Interface.h"

                                                    /* Used subcomponent API */
/* ------------------------------------------------------------------------- */
#include "Dem_Com_Implementation.h"
#include "Dem_DTCReporting_Implementation.h"
#include "Dem_MemoryEntry_Implementation.h"
#include "Dem_Cfg_Definitions.h"
#include "Dem_Event_Implementation.h"
#include "Dem_DTC_Implementation.h"
#include "Dem_MemStorageManager_Implementation.h"

                                                   /* Subcomponents callbacks*/
/* ------------------------------------------------------------------------- */
#include "Dem_Error_Interface.h"

/* ********************************************************************************************************************
 *  SUBCOMPONENT CONSTANT MACROS
 *********************************************************************************************************************/

/*!
 * \defgroup  Dem_FilterData_FilterFlags  Macros encoding the filter flags of a filter.
 * \{
 */
#define DEM_FILTERDATA_FILTERFLAGS_USESTATUSMASK                   (0x01U) /*!< Status mask is used for filtering */
#define DEM_FILTERDATA_FILTERFLAGS_USEFDC                          (0x02U) /*!< FDC is used for filtering */
#define DEM_FILTERDATA_FILTERFLAGS_USESEVERITY                     (0x04U) /*!< Severity is used for filtering */
#define DEM_FILTERDATA_FILTERFLAGS_USEFORMATOBD                    (0x08U) /*!< DTCFormat OBD is used for filtering */
#define DEM_FILTERDATA_FILTERFLAGS_FILTEREMISSIONRELEVANT          (0x10U) /*!< Filtering for emsission relevant DTCs */

#define DEM_FILTERDATA_FILTERFLAGS_INITIAL                         (0x00U) /*!< Initial value of filter flags */

/*! The inverse of DEM_FILTERDATA_FILTERFLAGS_USESTATUSMASK */
#define DEM_FILTERDATA_FILTERFLAGS_USESTATUSMASK_MASK              DEM_BIT_MASK(0, DEM_1BYTE)

/*! The inverse of DEM_FILTERDATA_FILTERFLAGS_USEFDC */
#define DEM_FILTERDATA_FILTERFLAGS_USEFDC_MASK                     DEM_BIT_MASK(1, DEM_1BYTE)

/*! The inverse of DEM_FILTERDATA_FILTERFLAGS_USESEVERITY */
#define DEM_FILTERDATA_FILTERFLAGS_USESEVERITY_MASK                DEM_BIT_MASK(2, DEM_1BYTE)

/*! The inverse of DEM_FILTERDATA_FILTERFLAGS_DTCFORMATOBD */
#define DEM_FILTERDATA_FILTERFLAGS_USEFORMATOBD_MASK               DEM_BIT_MASK(3, DEM_1BYTE)

/*! The inverse of DEM_FILTERDATA_FILTERFLAGS_FILTEREMISSIONRELEVANT */
#define DEM_FILTERDATA_FILTERFLAGS_FILTEREMISSIONRELEVANT_MASK     DEM_BIT_MASK(4, DEM_1BYTE)
/*!
 * \}
 */

/* ********************************************************************************************************************
 *  SUBCOMPONENT FUNCTION MACROS
 *********************************************************************************************************************/
/* Marker for already filtered events for DTC Filter ------------ */
/*! Size of bitfield of already filtered events */
#define DEM_FILTERDATA_FILTEREDEVENTS_SIZE(NumEvents)         (uint16)(((NumEvents)+7)/8)                                        /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Index of event in bitfield of already filtered events */
#define DEM_FILTERDATA_FILTEREDEVENTS_INDEX(EventId)          (uint16)((EventId)/8)                                              /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Bitmask for bitfield of already filtered events */
#define DEM_FILTERDATA_FILTEREDEVENTS_MASK(EventId)           (uint8)(0x01u << ((uint8)((EventId) % 8)))                         /* PRQA S 3453 */ /* MD_MSR_19.7 */

/* ********************************************************************************************************************
 *  SUBCOMPONENT DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  SUBCOMPONENT OBJECT FUNCTION DEFINITIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \addtogroup Dem_FilterData_Properties
 * \{
 */

/* ****************************************************************************
 % Dem_FilterData_TestFilterSet
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_FilterData_TestFilterSet(                                                                                                    /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONST(Dem_FilterData_HandleType, AUTOMATIC) FilterId
  )
{
  return (boolean)(Dem_FilterData_GetState(FilterId) == DEM_FILTERDATA_FILTER_DTC);
}

/* ****************************************************************************
 % Dem_FilterData_TestUseStatusMask()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_FilterData_TestUseStatusMask(                                                                                                /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONST(Dem_FilterData_HandleType, AUTOMATIC)  FilterId
  )
{
  return ((Dem_Cfg_GetFilterInfoTable(FilterId).FilterFlags & DEM_FILTERDATA_FILTERFLAGS_USESTATUSMASK) != 0);
}

/* ****************************************************************************
 % Dem_FilterData_TestUseFdc()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_FilterData_TestUseFdc(                                                                                                       /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONST(Dem_FilterData_HandleType, AUTOMATIC)  FilterId
  )
{
  return ((Dem_Cfg_GetFilterInfoTable(FilterId).FilterFlags & DEM_FILTERDATA_FILTERFLAGS_USEFDC) != 0);
}

/* ****************************************************************************
 % Dem_FilterData_TestUseSeverity()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_FilterData_TestUseSeverity(                                                                                                  /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONST(Dem_FilterData_HandleType, AUTOMATIC)  FilterId
  )
{
  return ((Dem_Cfg_GetFilterInfoTable(FilterId).FilterFlags & DEM_FILTERDATA_FILTERFLAGS_USESEVERITY) != 0);
}

/* ****************************************************************************
 % Dem_FilterData_TestUseFormatOBD()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_FilterData_TestUseFormatOBD(                                                                                                 /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONST(Dem_FilterData_HandleType, AUTOMATIC)  FilterId
  )
{
  return ((Dem_Cfg_GetFilterInfoTable(FilterId).FilterFlags & DEM_FILTERDATA_FILTERFLAGS_USEFORMATOBD) != 0);
}

/* ****************************************************************************
 % Dem_FilterData_TestFilterEmissionRelevant()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_FilterData_TestFilterEmissionRelevant(                                                                                       /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONST(Dem_FilterData_HandleType, AUTOMATIC)  FilterId
  )
{
  return ((Dem_Cfg_GetFilterInfoTable(FilterId).FilterFlags & DEM_FILTERDATA_FILTERFLAGS_FILTEREMISSIONRELEVANT) != 0);
}

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* ********************************************************************************************************************
 *  SUBCOMPONENT PRIVATE FUNCTION DEFINITIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \addtogroup Dem_FilterData_Private
 * \{
 */

/* ****************************************************************************
 % Dem_FilterData_GetState
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_FilterData_FilterType, DEM_CODE)
Dem_FilterData_GetState(                                                                                                         /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONST(Dem_FilterData_HandleType, AUTOMATIC) FilterId
  )
{
  Dem_FilterData_FilterType lReturnValue;

#if (DEM_CFG_FILTERINFOTABLE == STD_ON)
# if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (FilterId >= Dem_Cfg_GetSizeOfFilterInfoTable())
  {
    Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
    lReturnValue = DEM_FILTERDATA_FILTER_INIT;
  }
  else
# endif
  {
    lReturnValue = Dem_Cfg_GetFilterInfoTable(FilterId).FilterState;
  }
#else
  {
    lReturnValue = DEM_FILTERDATA_FILTER_INIT;
  }
#endif
  return lReturnValue;
}

/* ****************************************************************************
 % Dem_FilterData_GetIteratorIndexOfDTCFilter()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_EventIdType, DEM_CODE)
Dem_FilterData_GetIteratorIndexOfDTCFilter(                                                                                      /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONST(Dem_FilterData_HandleType, AUTOMATIC)  FilterId
  )
{
  Dem_EventIdType lReturnValue;

#if (DEM_CFG_FILTERINFOTABLE == STD_ON)
# if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (FilterId >= Dem_Cfg_GetSizeOfFilterInfoTable())
  {
    Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
    lReturnValue = DEM_EVENT_INVALID;
  }
  else
# endif
  {
    lReturnValue = Dem_Cfg_GetFilterInfoTable(FilterId).Iterator.EventIndex;
  }
#else
  {
    lReturnValue = DEM_EVENT_INVALID;
  }
#endif
  return lReturnValue;
}

/* ****************************************************************************
 % Dem_FilterData_GetChronoIndexOfDTCFilter()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_FilterData_GetChronoIndexOfDTCFilter(                                                                                        /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONST(Dem_FilterData_HandleType, AUTOMATIC)  FilterId
  )
{
  uint8 lReturnValue;

#if (DEM_CFG_FILTERINFOTABLE == STD_ON)
# if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (FilterId >= Dem_Cfg_GetSizeOfFilterInfoTable())
  {
    Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
    lReturnValue = 0;
  }
  else
# endif
  {
    lReturnValue = Dem_Cfg_GetFilterInfoTable(FilterId).Iterator.ChronoIndex;
  }
#else
  {
    lReturnValue = 0;
  }
#endif
  return lReturnValue;
}

/* ****************************************************************************
 % Dem_FilterData_GetStatusMaskOfDTCFilter()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_FilterData_GetStatusMaskOfDTCFilter(                                                                                         /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONST(Dem_FilterData_HandleType, AUTOMATIC)  FilterId
  )
{
  uint8 lReturnValue;

#if (DEM_CFG_FILTERINFOTABLE == STD_ON)
  lReturnValue = Dem_Cfg_GetFilterInfoTable(FilterId).StatusMask;
#else
  lReturnValue = 0x00;
#endif
  return lReturnValue;
}

/* ****************************************************************************
 % Dem_FilterData_GetFDCOfDTCFilter()
 *****************************************************************************/
/*!
* - Check filter Id.
* - Store the fault detection counter
*****************************************************************************/
DEM_LOCAL_INLINE FUNC(sint8, DEM_CODE)
Dem_FilterData_GetFDCOfDTCFilter(                                                                                                /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONST(Dem_FilterData_HandleType, AUTOMATIC)  FilterId
  )
{
  sint8 lReturnValue;

#if (DEM_CFG_FILTERINFOTABLE == STD_ON)
  lReturnValue = Dem_Cfg_GetFilterInfoTable(FilterId).FaultDetectionCounter;
#else
  lReturnValue = 0x00;
#endif
  return lReturnValue;
}

/* ****************************************************************************
 % Dem_FilterData_GetMemoryIdOfDTCFilter()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_FilterData_GetMemoryIdOfDTCFilter(                                                                                           /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONST(Dem_FilterData_HandleType, AUTOMATIC)  FilterId
  )
{
  uint8 lReturnValue;

#if (DEM_CFG_FILTERINFOTABLE == STD_ON)
# if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (FilterId >= Dem_Cfg_GetSizeOfFilterInfoTable())
  {
    Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
    lReturnValue = DEM_CFG_MEMORYID_INVALID;
  }
  else
# endif
  {
    lReturnValue = Dem_Cfg_GetFilterInfoTable(FilterId).MemoryId;
  }
#else
  {
    lReturnValue = DEM_CFG_MEMORYID_INVALID;
  }
#endif
  return lReturnValue;
}

/* ****************************************************************************
 % Dem_FilterData_GetSeverityMaskOfDTCFilter()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_FilterData_GetSeverityMaskOfDTCFilter(                                                                                       /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONST(Dem_FilterData_HandleType, AUTOMATIC)  FilterId
  )
{
  uint8 lReturnValue;

#if (DEM_CFG_FILTERINFOTABLE == STD_ON)
  lReturnValue = Dem_Cfg_GetFilterInfoTable(FilterId).SeverityMask;
#else
  lReturnValue = 0x00;
#endif
  return lReturnValue;
}

/* ****************************************************************************
 % Dem_FilterData_GetFilterFunction()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_FilterData_FuncPtrType, DEM_CODE)
Dem_FilterData_GetFilterFunction(                                                                                                /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONST(Dem_FilterData_HandleType, AUTOMATIC)  FilterId
  )
{
  Dem_FilterData_FuncPtrType lReturnValue;

#if (DEM_CFG_FILTERINFOTABLE == STD_ON)
# if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (FilterId >= Dem_Cfg_GetSizeOfFilterInfoTable())
  {
    Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
    lReturnValue = &Dem_FilterData_FilterMemoryByEvent;
  }
  else
# endif
  {
    lReturnValue = Dem_Cfg_GetFilterInfoTable(FilterId).FilterDtcFunction;
  }
#else
  {
    lReturnValue = &Dem_FilterData_FilterMemoryByEvent;
  }
#endif
  return lReturnValue;
}

/* ****************************************************************************
 % Dem_FilterData_SetState
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_FilterData_SetState(                                                                                                         /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONST(Dem_FilterData_HandleType, AUTOMATIC) FilterId,
  CONST(Dem_FilterData_FilterType, AUTOMATIC) NewState
  )
{
#if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (FilterId >= Dem_Cfg_GetSizeOfFilterInfoTable())
  {
    Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
  }
  else
#endif
  {
    Dem_Cfg_GetFilterInfoTable(FilterId).FilterState = NewState;
  }
}

/* ****************************************************************************
 % Dem_FilterData_SetEventIdOfDTCFilter()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_FilterData_SetEventIdOfDTCFilter(                                                                                            /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONST(Dem_FilterData_HandleType, AUTOMATIC)  FilterId,
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  )
{
#if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (FilterId >= Dem_Cfg_GetSizeOfFilterInfoTable())
  {
    Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
  }
  else
#endif
  {
    Dem_Cfg_GetFilterInfoTable(FilterId).Iterator.EventIndex = EventId;
  }
}

/* ****************************************************************************
 % Dem_FilterData_SetChronoIndexOfDTCFilter()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_FilterData_SetChronoIndexOfDTCFilter(                                                                                        /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONST(Dem_FilterData_HandleType, AUTOMATIC)  FilterId,
  CONST(uint8, AUTOMATIC)  ChronoIndex
  )
{
#if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (FilterId >= Dem_Cfg_GetSizeOfFilterInfoTable())
  {
    Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
  }
  else
#endif
  {
    Dem_Cfg_GetFilterInfoTable(FilterId).Iterator.ChronoIndex = ChronoIndex;
  }
}

/* ****************************************************************************
 % Dem_FilterData_SetStatusMaskOfDTCFilter()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_FilterData_SetStatusMaskOfDTCFilter(                                                                                         /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONST(Dem_FilterData_HandleType, AUTOMATIC)  FilterId,
  CONST(uint8, AUTOMATIC)  StatusMask
  )
{
#if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (FilterId >= Dem_Cfg_GetSizeOfFilterInfoTable())
  {
    Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
  }
  else
#endif
  {
    Dem_Cfg_GetFilterInfoTable(FilterId).StatusMask = StatusMask;
  }
}

/* ****************************************************************************
 % Dem_FilterData_SetFDCOfDTCFilter()
 *****************************************************************************/
/*!
* - Check filter Id.
* - Store the fault detection counter
*****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_FilterData_SetFDCOfDTCFilter(                                                                                                /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONST(Dem_FilterData_HandleType, AUTOMATIC)  FilterId,
  CONST(sint8, AUTOMATIC)  FDC
  )
{
#if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (FilterId >= Dem_Cfg_GetSizeOfFilterInfoTable())
  {
    Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
  }
  else
#endif
  {
    Dem_Cfg_GetFilterInfoTable(FilterId).FaultDetectionCounter = FDC;
  }
}

/* ****************************************************************************
 % Dem_FilterData_SetMemoryIdOfDTCFilter()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_FilterData_SetMemoryIdOfDTCFilter(                                                                                           /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONST(Dem_FilterData_HandleType, AUTOMATIC)  FilterId,
  CONST(uint8, AUTOMATIC)  MemoryId
  )
{
#if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (FilterId >= Dem_Cfg_GetSizeOfFilterInfoTable())
  {
    Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
  }
  else
#endif
  {
    Dem_Cfg_GetFilterInfoTable(FilterId).MemoryId = MemoryId;
  }
}

/* ****************************************************************************
 % Dem_FilterData_SetSeverityMaskOfDTCFilter()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_FilterData_SetSeverityMaskOfDTCFilter(                                                                                       /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONST(Dem_FilterData_HandleType, AUTOMATIC)  FilterId,
  CONST(uint8, AUTOMATIC)  SeverityMask
  )
{
#if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (FilterId >= Dem_Cfg_GetSizeOfFilterInfoTable())
  {
    Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
  }
  else
#endif
  {
    Dem_Cfg_GetFilterInfoTable(FilterId).SeverityMask = SeverityMask;
  }
}

/* ****************************************************************************
 % Dem_FilterData_SetFilterFunction()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_FilterData_SetFilterFunction(                                                                                                /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONST(Dem_FilterData_HandleType, AUTOMATIC)  FilterId,
  CONST(Dem_FilterData_FuncPtrType, AUTOMATIC)  FilterFunction
  )
{
#if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (FilterId >= Dem_Cfg_GetSizeOfFilterInfoTable())
  {
    Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
  }
  else
#endif
  {
    Dem_Cfg_GetFilterInfoTable(FilterId).FilterDtcFunction = FilterFunction;
  }
}

/* ****************************************************************************
 % Dem_FilterData_SetUseStatusMask()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_FilterData_SetUseStatusMask(                                                                                                 /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONST(Dem_FilterData_HandleType, AUTOMATIC)  FilterId
  )
{
  Dem_Cfg_GetFilterInfoTable(FilterId).FilterFlags |= DEM_FILTERDATA_FILTERFLAGS_USESTATUSMASK;
}

/* ****************************************************************************
 % Dem_FilterData_ResetUseStatusMask()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_FilterData_ResetUseStatusMask(                                                                                               /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONST(Dem_FilterData_HandleType, AUTOMATIC)  FilterId
  )
{
  Dem_Cfg_GetFilterInfoTable(FilterId).FilterFlags = 
    (uint8)(Dem_Cfg_GetFilterInfoTable(FilterId).FilterFlags & DEM_FILTERDATA_FILTERFLAGS_USESTATUSMASK_MASK);
}

/* ****************************************************************************
 % Dem_FilterData_SetUseFdc()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_FilterData_SetUseFdc(                                                                                                        /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONST(Dem_FilterData_HandleType, AUTOMATIC)  FilterId
  )
{
  Dem_Cfg_GetFilterInfoTable(FilterId).FilterFlags |= DEM_FILTERDATA_FILTERFLAGS_USEFDC;
}

/* ****************************************************************************
 % Dem_FilterData_ResetUseFdc()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_FilterData_ResetUseFdc(                                                                                                      /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONST(Dem_FilterData_HandleType, AUTOMATIC)  FilterId
  )
{
  Dem_Cfg_GetFilterInfoTable(FilterId).FilterFlags = 
    (uint8)(Dem_Cfg_GetFilterInfoTable(FilterId).FilterFlags & DEM_FILTERDATA_FILTERFLAGS_USEFDC_MASK);
}

/* ****************************************************************************
 % Dem_FilterData_SetUseSeverity()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_FilterData_SetUseSeverity(                                                                                                   /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONST(Dem_FilterData_HandleType, AUTOMATIC)  FilterId
  )
{
  Dem_Cfg_GetFilterInfoTable(FilterId).FilterFlags |= DEM_FILTERDATA_FILTERFLAGS_USESEVERITY;
}

/* ****************************************************************************
 % Dem_FilterData_ResetUseSeverity()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_FilterData_ResetUseSeverity(                                                                                                 /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONST(Dem_FilterData_HandleType, AUTOMATIC)  FilterId
  )
{
  Dem_Cfg_GetFilterInfoTable(FilterId).FilterFlags = 
    (uint8)(Dem_Cfg_GetFilterInfoTable(FilterId).FilterFlags & DEM_FILTERDATA_FILTERFLAGS_USESEVERITY_MASK);
}

/* ****************************************************************************
 % Dem_FilterData_SetUseFormatOBD()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_FilterData_SetUseFormatOBD(                                                                                                  /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONST(Dem_FilterData_HandleType, AUTOMATIC)  FilterId
  )
{
  Dem_Cfg_GetFilterInfoTable(FilterId).FilterFlags |= DEM_FILTERDATA_FILTERFLAGS_USEFORMATOBD;
}

/* ****************************************************************************
 % Dem_FilterData_ResetUseFormatOBD()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_FilterData_ResetUseFormatOBD(                                                                                                /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONST(Dem_FilterData_HandleType, AUTOMATIC)  FilterId
  )
{
  Dem_Cfg_GetFilterInfoTable(FilterId).FilterFlags = 
    (uint8)(Dem_Cfg_GetFilterInfoTable(FilterId).FilterFlags & DEM_FILTERDATA_FILTERFLAGS_USEFORMATOBD_MASK);
}

/* ****************************************************************************
 % Dem_FilterData_SetFilterEmissionRelevant()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_FilterData_SetFilterEmissionRelevant(                                                                                        /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONST(Dem_FilterData_HandleType, AUTOMATIC)  FilterId
  )
{
  Dem_Cfg_GetFilterInfoTable(FilterId).FilterFlags |= DEM_FILTERDATA_FILTERFLAGS_FILTEREMISSIONRELEVANT;
}

/* ****************************************************************************
 % Dem_FilterData_ResetFilterEmissionRelevant()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_FilterData_ResetFilterEmissionRelevant(                                                                                      /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONST(Dem_FilterData_HandleType, AUTOMATIC)  FilterId
  )
{
  Dem_Cfg_GetFilterInfoTable(FilterId).FilterFlags = 
    (uint8)(Dem_Cfg_GetFilterInfoTable(FilterId).FilterFlags & DEM_FILTERDATA_FILTERFLAGS_FILTEREMISSIONRELEVANT_MASK);
}

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_FilterData_ResetReportedEvents()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_FilterData_ResetReportedEvents(
  CONST(Dem_FilterData_HandleType, AUTOMATIC)  FilterId
  )
{
#if (DEM_FEATURE_NEED_REPORT_CHRONOLOGICALLY == STD_ON)
# if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (FilterId >= Dem_Cfg_GetSizeOfFilterInfoTable())
  {
    Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
  }
  else
# endif
  {
    uint16_least lBitfieldIterator;
    for (lBitfieldIterator = 0;
         lBitfieldIterator < DEM_BITFIELDS_IN_REPORTEDEVENTBUFFER;
         lBitfieldIterator++)
    {
      (Dem_Cfg_GetReportedEventsOfFilter(FilterId))[lBitfieldIterator] = 0;
    }
  }
#else
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(FilterId)                                                                                     /* PRQA S 3112 */ /* MD_DEM_14.2 */
#endif
}
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_FilterData_InitDTCFilter()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_FilterData_InitDTCFilter(
  CONST(Dem_FilterData_HandleType, AUTOMATIC)  FilterId,
  CONST(uint8, AUTOMATIC)  MemoryId,
  CONST(uint8, AUTOMATIC)  StatusMask
  )
{
  Std_ReturnType lReturnValue;
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(StatusMask)                                                                                   /* PRQA S 3112 */ /* MD_DEM_14.2 */

  switch (MemoryId)
  {
  case DEM_CFG_MEMORYID_PRIMARY:
    Dem_FilterData_SetMemoryIdOfDTCFilter(FilterId, MemoryId);
    if ( (StatusMask == 0x04) || (StatusMask == 0x08) || (StatusMask == 0x0C) )
    { /* reporting shall be in chronological order */
      Dem_FilterData_SetEventIdOfDTCFilter(FilterId, DEM_EVENT_INVALID);
      Dem_FilterData_SetFilterFunction(FilterId, Dem_FilterData_FilterMemoryChrono);
    }
    else
    { /* report by event id, set first event index */
      Dem_FilterData_SetEventIdOfDTCFilter(FilterId, Dem_Cfg_GlobalPrimaryFirst());
      Dem_FilterData_SetFilterFunction(FilterId, Dem_FilterData_FilterMemoryByEvent);
    }
    lReturnValue = E_OK;
    break;

#if (DEM_CFG_SUPPORT_SECONDARY == STD_ON)
  case DEM_CFG_MEMORYID_SECONDARY:
    Dem_FilterData_SetMemoryIdOfDTCFilter(FilterId, MemoryId);
    if ( (StatusMask == 0x04) || (StatusMask == 0x08) || (StatusMask == 0x0C) )
    { /* reporting shall be in chronological order */
      Dem_FilterData_SetEventIdOfDTCFilter(FilterId, DEM_EVENT_INVALID);
      Dem_FilterData_SetFilterFunction(FilterId, Dem_FilterData_FilterMemoryChrono);
    }
    else
    { /* report by event id, set first event index */
      Dem_FilterData_SetEventIdOfDTCFilter(FilterId, Dem_Cfg_GlobalSecondaryFirst());
      Dem_FilterData_SetFilterFunction(FilterId, Dem_FilterData_FilterMemoryByEvent);
    }
    lReturnValue = E_OK;
    break;
#endif

#if (DEM_CFG_SUPPORT_OBDII == STD_ON)
  case DEM_CFG_MEMORYID_PERMANENT:
    Dem_FilterData_SetMemoryIdOfDTCFilter(FilterId, MemoryId);
    /* report by event id, set max number of permanent memory entries */
    Dem_FilterData_SetEventIdOfDTCFilter(FilterId, Dem_Cfg_GlobalPermanentMaxCount());
    Dem_FilterData_SetFilterFunction(FilterId, Dem_FilterData_FilterPermanentByEvent);
    lReturnValue = E_OK;
    break;
#endif

  default:
    lReturnValue = E_NOT_OK;
    break;
  }

  return lReturnValue;
}
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_FilterData_InitFilterFlagsAndMasks()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_FilterData_InitFilterFlagsAndMasks(
  CONST(Dem_FilterData_HandleType, AUTOMATIC)  FilterId,
  CONST(uint8, AUTOMATIC)  StatusMask,
  CONST(Dem_DTCFormatType, AUTOMATIC)  DTCFormat,
  CONST(boolean, AUTOMATIC)  FilterForOBD,
  CONST(boolean, AUTOMATIC)  FilterWithSeverity,
  CONST(Dem_DTCSeverityType, AUTOMATIC)  SeverityMask,
  CONST(boolean, AUTOMATIC)  FilterForFDC
  )
{
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(DTCFormat)                                                                                    /* PRQA S 3112 */ /* MD_DEM_14.2 */

  /* Check if filter shall ignore Dtc status or not */
  if (StatusMask == 0x00)
  {
    Dem_FilterData_ResetUseStatusMask(FilterId);
  }
  else
  {
    Dem_FilterData_SetStatusMaskOfDTCFilter(FilterId, StatusMask & Dem_Cfg_GlobalStatusMask());
    Dem_FilterData_SetUseStatusMask(FilterId);
  }

  /* Check if filter shall use severity */
  if (FilterWithSeverity == TRUE)
  {
    Dem_FilterData_SetSeverityMaskOfDTCFilter(FilterId, SeverityMask & Dem_Cfg_GlobalSeverityMask());
    Dem_FilterData_SetUseSeverity(FilterId);
  }
  else
  {
    Dem_FilterData_ResetUseSeverity(FilterId);
  }

  /* Check if filter shall use fault detection counter */
  if (FilterForFDC == TRUE)
  {
    Dem_FilterData_SetUseFdc(FilterId);
  }
  else
  {
    Dem_FilterData_ResetUseFdc(FilterId);
  }

  /* Check if filtering for emission relevant DTCs was requested */
  if (FilterForOBD == TRUE)
  {
    Dem_FilterData_SetFilterEmissionRelevant(FilterId);
  }
  else
  {
    Dem_FilterData_ResetFilterEmissionRelevant(FilterId);
  }

  /* Check if output format of DTCs shall be OBD */
#if (DEM_CFG_SUPPORT_OBDII == STD_ON)
  if (DTCFormat == DEM_DTC_FORMAT_OBD)
  {
    Dem_FilterData_SetUseFormatOBD(FilterId);
  }
  else
  {
    Dem_FilterData_ResetUseFormatOBD(FilterId);
  }
#endif
 }                                                                                                                                /* PRQA S 6050, 6060 */ /* MD_MSR_STCAL, MD_MSR_STPAR */
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON) \
    || ((DEM_CFG_FILTERINFOTABLE == STD_ON) && (DEM_DEV_RUNTIME_CHECKS == STD_ON))
/* ****************************************************************************
 % Dem_FilterData_FilterForEventMatch
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
DEM_LOCAL FUNC(Std_ReturnType, DEM_CODE)
Dem_FilterData_FilterForEventMatch(
  CONST(Dem_FilterData_HandleType, AUTOMATIC)  FilterId,
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  )
{
  uint8    lEventStatus;

  if (Dem_Cfg_EventUdsDtc(EventId) == DEM_CFG_DTC_UDS_INVALID)
  {
    return E_NOT_OK;
  }
#if (DEM_CFG_SUPPORT_TYPE1_COMBINATION == STD_ON)
  if (EventId != Dem_Cfg_GetMasterEvent(EventId))
  {
    return E_NOT_OK;
  }
#endif
  if (Dem_DTC_TestDtcSuppressed(EventId) == TRUE)
  {
    /* Suppressed DTCs are skipped */
    return E_NOT_OK;
  }
#if (DEM_FEATURE_NEED_OBD == STD_ON)                                                                                             /* COV_MSR_UNSUPPORTED XF */
  if ( (Dem_FilterData_TestUseFormatOBD(FilterId) == TRUE)                                                                       /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
    || (Dem_FilterData_TestFilterEmissionRelevant(FilterId) == TRUE))
  {
    /* Filter specifically for OBD DTCs */
    if (Dem_Cfg_EventObdRelated(EventId) == FALSE)
    { 
      /* skip non-OBD DTCs */
      return E_NOT_OK;
    }
  }
  else
  { 
    /* Do not filter for OBD DTCs, all DTCs pass */
    if ( (Dem_DTCReporting_TestObdHideOccurrences() == TRUE)                                                                              /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
      && (Dem_Cfg_EventSignificance(EventId) == DEM_CFG_EVENT_SIGNIFICANCE_OCCURRENCE)
      && (Dem_Cfg_EventObdRelated(EventId) == TRUE))
    { 
      /* Special case - skip Dependent OBD DTCs */
      return E_NOT_OK;
    }
  }
#endif

  lEventStatus = Dem_DTC_ApplyExternalOnlyStatus(EventId, Dem_DTC_GetDTCStatus(EventId));

  if ( (Dem_FilterData_TestUseStatusMask(FilterId) == TRUE)
    && ((Dem_FilterData_GetStatusMaskOfDTCFilter(FilterId) & lEventStatus) == 0))
  {
    /* Skip DTCs not matching the requested status mask */
    return E_NOT_OK;
  }

  if ( (Dem_FilterData_TestUseSeverity(FilterId) == TRUE)
    && ((Dem_FilterData_GetSeverityMaskOfDTCFilter(FilterId) & Dem_Cfg_EventSeverity(EventId)) == 0))
  { /* Skip DTCs not matching the requested severity */
    return E_NOT_OK;
  }

  if (Dem_FilterData_TestUseFdc(FilterId) == TRUE)
  {
    Std_ReturnType lGetFdcReturnValue;
    sint8 lFdc;

    lGetFdcReturnValue = Dem_DTC_GetFaultDetectionCounter(EventId, &lFdc);                                                   /* SBSW_DEM_POINTER_FORWARD_STACK */

    if (lGetFdcReturnValue != E_OK)
    { /* If FDC cannot be retrieved, the DTC does not match */
      return E_NOT_OK;
    }

    if ( (lFdc <= 0)
      || (lFdc == 0x7f))
    { /* skip passed, passing and qualified failed DTCs */
      return E_NOT_OK;
    }
    else
    {
      /* store the matching FDC for later */
      Dem_FilterData_SetFDCOfDTCFilter(FilterId, lFdc);
    }
  }

  /* If all tests pass, keep this DTC for processing */
  return E_OK;
}                                                                                                                                /* PRQA S 2006, 6010, 6030, 6050, 6080 */ /* MD_DEM_14.7, MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON) \
    || ((DEM_CFG_FILTERINFOTABLE == STD_ON) && (DEM_DEV_RUNTIME_CHECKS == STD_ON))
/* ****************************************************************************
 % Dem_FilterData_FilterMemoryByEvent
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
DEM_LOCAL FUNC(Dem_EventIdType, DEM_CODE)
Dem_FilterData_FilterMemoryByEvent(
  CONST(Dem_FilterData_HandleType, AUTOMATIC)  FilterId,
  CONST(Dem_Mem_MemoryInfoPtrType, AUTOMATIC)  MemoryInfo
  )
{
  Dem_EventIdType lEventId;
  Dem_EventIdType lReturnValue;

  lEventId = Dem_FilterData_GetIteratorIndexOfDTCFilter(FilterId);
  lReturnValue = DEM_EVENT_INVALID;

  /* if last EventId is not valid or was still analyzed skip the filtering */
  if (lEventId != DEM_EVENT_INVALID)
  {
    Dem_EventIdType lEventIdLast;

    lEventIdLast = MemoryInfo->LastEvent;
    /* iterate through the EventIds and check filter criteria */
    for (; lEventId <= lEventIdLast; lEventId++)
    {
#if (DEM_FEATURE_NEED_REPORT_CHRONOLOGICALLY == STD_ON)
      /* take event into account if it was not reported before */
      if (Dem_Com_TestBitInBitfield(Dem_Cfg_GetReportedEventsOfFilter(FilterId), lEventId) == FALSE)
#endif
      {
        /* EventId was not reported before, proceed */
        if (Dem_FilterData_FilterForEventMatch(FilterId, lEventId) == E_OK)
        {
          /* identified an Event which matches the filter criteria */
          lReturnValue = lEventId;
          break;
        }
      }
    }

    if (lEventId >= lEventIdLast)
    { /* last EventId has been processed */
      Dem_FilterData_SetEventIdOfDTCFilter(FilterId, DEM_EVENT_INVALID);
    }
    else
    { /* write back the next event to process */
      Dem_FilterData_SetEventIdOfDTCFilter(FilterId, lEventId + 1);
    }
  }
  /* else lReturnValue = DEM_EVENT_INVALID initially set */

  return lReturnValue;
}                                                                                                                                /* PRQA S 6080 */ /* MD_MSR_STMIF */
#endif

#if (DEM_CFG_SUPPORT_OBDII == STD_ON)
/* ****************************************************************************
 % Dem_FilterData_FilterPermanentByEvent
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
DEM_LOCAL FUNC(Dem_EventIdType, DEM_CODE)
Dem_FilterData_FilterPermanentByEvent(
  CONST(Dem_FilterData_HandleType, AUTOMATIC)  FilterId,
  CONST(Dem_Mem_MemoryInfoPtrType, AUTOMATIC)  MemoryInfo                                                                        /* PRQA S 3206 */ /* MD_DEM_3206 */
  )
{
  Dem_EventIdType lPermanentIndex;
  Dem_EventIdType lPermanentEventId;
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(MemoryInfo)                                                                                   /* PRQA S 3112 */ /* MD_DEM_14.2 */

  lPermanentIndex = Dem_FilterData_GetIteratorIndexOfDTCFilter(FilterId);
  lPermanentEventId = DEM_EVENT_INVALID;

  /* if last EventId is not valid or was still analysed skip the filtering */
  while (lPermanentIndex != 0)
  {
    --lPermanentIndex;

    if (DEM_ESM_TEST_PERMANENT_VISIBLE(Dem_Mem_PermanentGetStatus(lPermanentIndex)) == TRUE)
    { /* Visible Event identified, return it and stop processing */
      lPermanentEventId = Dem_Mem_PermanentGetEvent(lPermanentIndex);
      if ( (lPermanentEventId != DEM_EVENT_INVALID)                                                                              /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
        && (Dem_Cfg_GlobalMilIndicator() == Dem_Cfg_EventSpecialIndicator(lPermanentEventId)))
      {
        break;
      }
    }
  }

  /* store current position in permanent memory */
  Dem_FilterData_SetEventIdOfDTCFilter(FilterId, lPermanentIndex);

  return lPermanentEventId;
}
#endif /* (DEM_CFG_SUPPORT_OBDII == STD_ON) */

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_FilterData_FilterMemoryChrono
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
DEM_LOCAL FUNC(Dem_EventIdType, DEM_CODE)
Dem_FilterData_FilterMemoryChrono(
  CONST(Dem_FilterData_HandleType, AUTOMATIC)  FilterId,
  CONST(Dem_Mem_MemoryInfoPtrType, AUTOMATIC)  MemoryInfo
  )
{
  Dem_EventIdType lEventId;
#if (DEM_FEATURE_NEED_REPORT_CHRONOLOGICALLY == STD_ON)
  uint8 lChronoIndex;

  lChronoIndex = Dem_FilterData_GetChronoIndexOfDTCFilter(FilterId);
  lEventId = DEM_EVENT_INVALID;

  /* index set to 0 indicates that the filter was reset */
  if (lChronoIndex == 0)
  {
    lChronoIndex = *MemoryInfo->SizePtr;
  }
  /* else */ /* last stored index initially loaded */

  while (lChronoIndex != 0)
  {
    lChronoIndex--;

    /* Get EventId for current index and marker if event was reported before */
    lEventId = 
      Dem_MemoryEntry_GetEventId(Dem_MemStorageManager_GetMemoryEntryId(
        Dem_MemStorageManager_MemoryGetChronology(MemoryInfo, lChronoIndex)));
    /* verify that a valid EventId was returned */
    if (Dem_Event_TestValidHandle(lEventId) == TRUE)
    {
      /* EventId was not reported before, proceed */
      if (Dem_FilterData_FilterForEventMatch(FilterId, lEventId) == E_OK)
      {
        /* identified an Event which matches the filter criteria, mark event as reported */
        Dem_Com_SetBitInBitfield(Dem_Cfg_GetReportedEventsOfFilter(FilterId), DEM_BITFIELDS_IN_REPORTEDEVENTBUFFER, lEventId);
        /* lEventId holds the valid EventId */

        break;
      }
      else
      { /* No filter match, continue with loop */
        lEventId = DEM_EVENT_INVALID;
      }
    }
  }

  /* If end of chrono stack is reached, switch to filter by event id */
  if (lChronoIndex == 0)
  {
    Dem_FilterData_SetEventIdOfDTCFilter(FilterId, MemoryInfo->FirstEvent);
    Dem_FilterData_SetFilterFunction(FilterId, Dem_FilterData_FilterMemoryByEvent);

    if (lEventId == DEM_EVENT_INVALID)
    { /* no valid match, proceed with filtering by EventId */
      lEventId = Dem_FilterData_FilterMemoryByEvent(FilterId, MemoryInfo);                                                       /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
    }
  }
  else
  {
    /* store current position of chrono stack */
    Dem_FilterData_SetChronoIndexOfDTCFilter(FilterId, lChronoIndex);
  }
#else
  Dem_FilterData_SetEventIdOfDTCFilter(FilterId, MemoryInfo->FirstEvent);
  Dem_FilterData_SetFilterFunction(FilterId, Dem_FilterData_FilterMemoryByEvent);
  lEventId = Dem_FilterData_FilterMemoryByEvent(FilterId, MemoryInfo);                                                           /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
#endif
  return lEventId;
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_FilterData_CountMatchesInPermanentMemory
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint16, DEM_CODE)
Dem_FilterData_CountMatchesInPermanentMemory(
  void
  )
{
  uint16          lNumberOfEvents;

  lNumberOfEvents = 0;

#if (DEM_CFG_SUPPORT_OBDII == STD_ON)                                                                                            /* COV_MSR_UNSUPPORTED TX */
  {
    Dem_EventIdType lPermanentIndex;
    lPermanentIndex = Dem_Cfg_GlobalPermanentMaxCount();

    /* scan the permanent memory for visible events */
    while (lPermanentIndex != 0)
    {
      --lPermanentIndex;
      if (DEM_ESM_TEST_PERMANENT_VISIBLE(Dem_Mem_PermanentGetStatus(lPermanentIndex)) == TRUE)
      {
        if ( (Dem_Mem_PermanentGetEvent(lPermanentIndex) != DEM_EVENT_INVALID)                                                   /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
          && (Dem_Cfg_EventSpecialIndicator(Dem_Mem_PermanentGetEvent(lPermanentIndex)) == Dem_Cfg_GlobalMilIndicator()))
        {
          ++lNumberOfEvents;
        }
      }
    }
  }
#endif

  return lNumberOfEvents;
}
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_FilterData_CountMatchesInEventMemory
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint16, DEM_CODE)
Dem_FilterData_CountMatchesInEventMemory(
  CONST(Dem_FilterData_HandleType, AUTOMATIC)  FilterId
  )
{
  uint16                      lNumberOfEvents;
  Dem_EventIdType             lEventId;
  Dem_Mem_MemoryInfoPtrType   MemoryInfo;

  lNumberOfEvents = 0;
  MemoryInfo = Dem_MemStorageManager_MemoryInfoInit(Dem_FilterData_GetMemoryIdOfDTCFilter(FilterId));

  if (MemoryInfo->FirstEvent != DEM_EVENT_INVALID)                                                                               /* PRQA S 3355, 3358 */ /* MD_DEM_13.7, MD_DEM_13.7 */
  {
    /* at least one event is available which may match the filter criteria */
    for (lEventId = MemoryInfo->FirstEvent;
          lEventId <= MemoryInfo->LastEvent;
          ++lEventId)
    {
      if (Dem_FilterData_FilterForEventMatch(FilterId, lEventId) == E_OK)
      {
        ++lNumberOfEvents;
      }
    }
  }
  return lNumberOfEvents;
}
#endif

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
 * \addtogroup Dem_FilterData_Public
 * \{
 */

# if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_FilterData_InitDefault()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_FilterData_InitDefault(
  CONST(Dem_FilterData_HandleType, AUTOMATIC)  FilterId
  )
{
  Dem_FilterData_SetState(FilterId, DEM_FILTERDATA_FILTER_INIT);
  Dem_FilterData_SetMemoryIdOfDTCFilter(FilterId, DEM_CFG_MEMORYID_INVALID);
  Dem_FilterData_SetEventIdOfDTCFilter(FilterId, DEM_EVENT_INVALID);
  Dem_FilterData_SetChronoIndexOfDTCFilter(FilterId, 0);
  Dem_FilterData_SetStatusMaskOfDTCFilter(FilterId, 0x00);
  Dem_FilterData_SetSeverityMaskOfDTCFilter(FilterId, 0x00);
  Dem_FilterData_SetFDCOfDTCFilter(FilterId, 0x00);
  Dem_FilterData_SetFilterFunction(FilterId, Dem_FilterData_FilterMemoryByEvent);
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_FilterData_SetDTCFilter()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_FilterData_SetDTCFilter(
  CONST(Dem_FilterData_HandleType, AUTOMATIC)  FilterId,
  CONST(uint8, AUTOMATIC)  DTCStatusMask,
  CONST(Dem_DTCFormatType, AUTOMATIC)  DTCFormat,
  CONST(uint8, AUTOMATIC)  MemoryId,
  CONST(boolean, AUTOMATIC)  FilterForOBD,
  CONST(boolean, AUTOMATIC)  FilterWithSeverity,
  CONST(Dem_DTCSeverityType, AUTOMATIC)  DTCSeverityMask,
  CONST(boolean, AUTOMATIC)  FilterForFDC
  )
{
  Std_ReturnType lReturnValue;

  lReturnValue = Dem_FilterData_InitDTCFilter(FilterId, MemoryId, DTCStatusMask);

  if (lReturnValue == E_OK)
  {
    /* Clear list of identified and reported events */
    Dem_FilterData_ResetReportedEvents(FilterId);

    Dem_FilterData_SetState(FilterId, DEM_FILTERDATA_FILTER_DTC);
    Dem_FilterData_InitFilterFlagsAndMasks(FilterId,
                                           DTCStatusMask,
                                           DTCFormat,
                                           FilterForOBD,
                                           FilterWithSeverity,
                                           DTCSeverityMask,
                                           FilterForFDC);
  }

  return lReturnValue;
}                                                                                                                                /* PRQA S 6060 */ /* MD_MSR_STPAR */
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_FilterData_GetNextFilteredDTC
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE) Dem_FilterData_GetNextFilteredDTC(
  CONST(Dem_FilterData_HandleType, AUTOMATIC)  FilterId,
  CONSTP2VAR(Dem_FilterData_ResultType, AUTOMATIC, AUTOMATIC)  FilterResult
  )
{
  Std_ReturnType lReturnValue;
  Dem_EventIdType lNextEvent;

#if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if ( (Dem_FilterData_GetFilterFunction(FilterId) != &Dem_FilterData_FilterMemoryByEvent)                                       /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
    && (Dem_FilterData_GetFilterFunction(FilterId) != &Dem_FilterData_FilterMemoryChrono)                                        /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
# if (DEM_CFG_SUPPORT_OBDII == STD_ON)
    && (Dem_FilterData_GetFilterFunction(FilterId) != &Dem_FilterData_FilterPermanentByEvent)
# endif
    )
  {
    Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
    lNextEvent = DEM_EVENT_INVALID;
  }
  else
#endif
  {
    lNextEvent = (*Dem_FilterData_GetFilterFunction(FilterId))(FilterId, Dem_MemStorageManager_MemoryInfoInit(Dem_FilterData_GetMemoryIdOfDTCFilter(FilterId)));   /* SBSW_DEM_CALL_DTCFILTER_FPTR */
  }

  if (lNextEvent == DEM_EVENT_INVALID)
  {
    lReturnValue = DEM_NO_SUCH_ELEMENT;
  }
  else
  {
#if (DEM_CFG_SUPPORT_OBDII == STD_ON)
    if (Dem_FilterData_TestUseFormatOBD(FilterId) == TRUE)
    {
      FilterResult->DTC = (uint32)(((uint32)Dem_Cfg_EventObdDtc(lNextEvent)) << 8);
    }
    else
#endif
    {
      FilterResult->DTC = Dem_Cfg_EventUdsDtc(lNextEvent);
    }

    FilterResult->DTCStatus = (uint8)(Dem_DTC_ApplyExternalOnlyStatus(lNextEvent, Dem_DTC_GetDTCStatus(lNextEvent)) & Dem_Cfg_GlobalStatusMask());

    if (Dem_FilterData_TestUseFdc(FilterId) == TRUE)
    {
      FilterResult->FDC = Dem_FilterData_GetFDCOfDTCFilter(FilterId);
    }

    if (Dem_FilterData_TestUseSeverity(FilterId) == TRUE)
    {
      FilterResult->Severity = Dem_Cfg_EventSeverity(lNextEvent);
      FilterResult->FunctionalUnit = Dem_Cfg_EventFunctionalUnit(lNextEvent);
    }
    lReturnValue = E_OK;
  }
  return lReturnValue;
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_FilterData_CountMatchingDTCs
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL FUNC(uint16, DEM_CODE)
Dem_FilterData_CountMatchingDTCs(
  CONST(Dem_FilterData_HandleType, AUTOMATIC)  FilterId
  )
{
  uint16                      lNumberOfEvents;

  switch (Dem_FilterData_GetMemoryIdOfDTCFilter(FilterId))
  {
  case DEM_CFG_MEMORYID_PERMANENT:
    lNumberOfEvents = Dem_FilterData_CountMatchesInPermanentMemory();
    break;

  case DEM_CFG_MEMORYID_PRIMARY:
  case DEM_CFG_MEMORYID_SECONDARY:
    lNumberOfEvents = Dem_FilterData_CountMatchesInEventMemory(FilterId);
    break;

  default:
    /* no other supported memory can contain DTCs */
    lNumberOfEvents = 0;
    break;
  }

  return lNumberOfEvents;
}   
#endif

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* DEM_FILTERDATA_IMPLEMENTATION_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_FilterData_Implementation.h
 *********************************************************************************************************************/
