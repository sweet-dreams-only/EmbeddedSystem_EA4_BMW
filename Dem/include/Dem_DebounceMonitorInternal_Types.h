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
 *
 *  \addtogroup Dem_DebounceMonitorInternal
 *  \{
 *  \file       Dem_DebounceMonitorInternal_Types.h
 *  \brief      Diagnostic Event Manager (Dem) header file
 *  \details    Public types of DebounceMonitorInternal subcomponent
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

#if !defined (DEM_DEBOUNCEMONITORINTERNAL_TYPES_H)
#define DEM_DEBOUNCEMONITORINTERNAL_TYPES_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                        /* Dem module header */
/* ------------------------------------------------------------------------- */
#include "Dem_Int.h"
#include "Dem_DebounceBase_Types.h"
/* ------------------------------------------------------------------------- */


/* ********************************************************************************************************************
 *  SUBCOMPONENT CONSTANT MACROS
 *********************************************************************************************************************/

/*!
 * \defgroup  Dem_Esm_MonitorStatus  Macros encoding qualified monitor status reports
 * Macros encoding qualified monitor status reports
 * \{
 */
#define DEM_DEBOUNCE_MONITORINTERNAL_STATUS_NONE                      (0)   /*! < No result */
#define DEM_DEBOUNCE_MONITORINTERNAL_STATUS_FAILED                    (1)   /*! < Failed result */
#define DEM_DEBOUNCE_MONITORINTERNAL_STATUS_PASSED                    (2)   /*! < Passed result */
#define DEM_DEBOUNCE_MONITORINTERNAL_STATUS_FDCTHRESHOLDREACHED       (3)   /*! < Fdc threshold reached result */
/*!
 * \}
 */

/* ********************************************************************************************************************
 *  SUBCOMPONENT FUNCTION MACROS
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  SUBCOMPONENT DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef struct Dem_DebounceMonitorInternal_InfoType_s Dem_DebounceMonitorInternal_InfoType;

/*! Data for monitor internal debouncing
  *  \extends Dem_DebounceBase_InfoType_s  */
struct Dem_DebounceMonitorInternal_InfoType_s
{
  Dem_DebounceBase_InfoType Base;  /*!< Base class object. This attribute must come first! */
  uint8 OldMonitorStatus;          /*!< [in] Last monitor result before processing */
  uint8 NewMonitorStatus;          /*!< [out] Last monitor result after processing */
};

/*! Pointer to debounce algorithm management data */
typedef P2VAR(Dem_DebounceMonitorInternal_InfoType, TYPEDEF, AUTOMATIC) Dem_DebounceMonitorInternal_InfoPtrType;                 /* PRQA S 0779 */ /* MD_MSR_5.1_779 */
/*! Non-writeable pointer to debounce algorithm management data */
typedef P2CONST(Dem_DebounceMonitorInternal_InfoType, TYPEDEF, AUTOMATIC) Dem_DebounceMonitorInternal_ConstInfoPtrType;


#endif /* DEM_DEBOUNCEMONITORINTERNAL_TYPES_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_DebounceMonitorInternal_Types.h
 *********************************************************************************************************************/
