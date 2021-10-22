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
 *  \file       Dem_FilterData_Types.h
 *  \brief      Diagnostic Event Manager (Dem) header file
 *  \details    Public types of FilterData subcomponent
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

#if !defined (DEM_FILTERDATA_TYPES_H)
#define DEM_FILTERDATA_TYPES_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                        /* Dem module header */
/* ------------------------------------------------------------------------- */
#include "Dem_Int.h"
#include "Dem_Cfg_Types.h"
#include "Dem_MemStorageManager_Types.h"
/* ------------------------------------------------------------------------- */


/* ********************************************************************************************************************
 *  SUBCOMPONENT CONSTANT MACROS
 *********************************************************************************************************************/
/*! Number of bitfields in pre client in Dem_Cfg_ReportedEventsOfFilter */
#define DEM_BITFIELDS_IN_REPORTEDEVENTBUFFER     (((DEM_G_NUMBER_OF_EVENTS - 1) / (sizeof(Dem_Com_ProcessorWordType) * 8)) + 1)

/*!
 * \defgroup  Dem_FilterData_Filter Macros encoding filter type
 * \{
 */
#define DEM_FILTERDATA_FILTER_INIT               0  /*!< Initialization value */
#define DEM_FILTERDATA_FILTER_DTC                1  /*!< A filter for DTCs was set up */
/*!
 * \}
 */


/* ********************************************************************************************************************
 *  SUBCOMPONENT FUNCTION MACROS
 *********************************************************************************************************************/


/* ********************************************************************************************************************
 *  SUBCOMPONENT DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/*! Type is used for FilterData handles. */
typedef uint8 Dem_FilterData_HandleType;

/*! Type of used filter, see Dem_FilterData_Filter for possible values */
typedef uint8 Dem_FilterData_FilterType;

/*! Function pointer type for event filter functions */
typedef P2FUNC(Dem_EventIdType, DEM_CODE, Dem_FilterData_FuncPtrType) (
  CONST(Dem_FilterData_HandleType, AUTOMATIC)  FilterId,
  CONST(Dem_Mem_MemoryInfoPtrType, AUTOMATIC)  MemoryInfo
  );


/*! Filter data for Dcm requests */
struct Dem_FilterData_InfoType_s
{
  /*! Iterator data */
  union
  {                                                                                                                              /* PRQA S 0750 */ /* MD_MSR_18.4 */
    Dem_EventIdType          EventIndex;  /*!< Event iterator for linar order filtering */
    uint8                    ChronoIndex;  /*!< chronology iterator for chronological order filtering */
  }                          Iterator;
  uint8                      StatusMask;  /*!< Status mask filter */
  sint8                      FaultDetectionCounter;  /*!< FaultDetectionCounter for FDC filter */
  uint8                      MemoryId;  /*!< Filtered event memory */
  Dem_DTCSeverityType        SeverityMask;  /*!< Severity mask filter */

  uint8                      FilterFlags;          /*!< Filter flags */
  Dem_FilterData_FuncPtrType FilterDtcFunction;    /*!< Active filter function */
  Dem_FilterData_FilterType  FilterState;
};

/*! Filter data type for Dcm requests */
typedef struct Dem_FilterData_InfoType_s Dem_FilterData_InfoType;

struct Dem_FilterData_ResultType_s
{
  uint32 DTC;
  sint8 FDC;
  uint8 DTCStatus;
  uint8 Severity;
  uint8 FunctionalUnit;
};
  
typedef struct Dem_FilterData_ResultType_s Dem_FilterData_ResultType;


#endif /* DEM_FILTERDATA_TYPES_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_FilterData_Types.h
 *********************************************************************************************************************/
