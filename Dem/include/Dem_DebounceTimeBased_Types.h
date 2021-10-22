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
/*! \addtogroup Dem_DebounceTimeBased
 *  \{
 *  \file       Dem_DebounceTimeBased_Types.h
 *  \brief      Diagnostic Event Manager (Dem) header file
 *  \details    Public types of DebounceTimeBased subcomponent
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

#if !defined (DEM_DEBOUNCETIMEBASED_TYPES_H)
#define DEM_DEBOUNCETIMEBASED_TYPES_H

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
 * \defgroup  Dem_Debounce_StatusType  Macros encoding debounce status states
 * Macros encoding debounce status states
 * \{
 */
#define DEM_DEBOUNCE_TIMEBASED_NONE                    ((0x00U) << DEM_SATELLITEDATA_DEBOUNCE_STATUS_POS) /*!< debouncing inactive */
#define DEM_DEBOUNCE_TIMEBASED_RESET_FAILED            ((0x01U) << DEM_SATELLITEDATA_DEBOUNCE_STATUS_POS) /*!< debouncing started, counter initialized towards failed threshold */
#define DEM_DEBOUNCE_TIMEBASED_RESET_PASSED            ((0x02U) << DEM_SATELLITEDATA_DEBOUNCE_STATUS_POS) /*!< debouncing started, counter initialized towards passed threshold */
#define DEM_DEBOUNCE_TIMEBASED_COUNT_FAILED            ((0x03U) << DEM_SATELLITEDATA_DEBOUNCE_STATUS_POS) /*!< debouncing in progress, counting towards failed threshold */
#define DEM_DEBOUNCE_TIMEBASED_COUNT_PASSED            ((0x04U) << DEM_SATELLITEDATA_DEBOUNCE_STATUS_POS) /*!< debouncing in progress, counting towards passed threshold */
#define DEM_DEBOUNCE_TIMEBASED_FROZEN_FAILED           ((0x05U) << DEM_SATELLITEDATA_DEBOUNCE_STATUS_POS) /*!< debouncing paused while counting towards failed threshold */
#define DEM_DEBOUNCE_TIMEBASED_FROZEN_PASSED           ((0x06U) << DEM_SATELLITEDATA_DEBOUNCE_STATUS_POS) /*!< debouncing paused while counting towards passed threshold */
#define DEM_DEBOUNCE_TIMEBASED_COUNT_FAILED_FDC        ((0x07U) << DEM_SATELLITEDATA_DEBOUNCE_STATUS_POS) /*!< debouncing in progress, counting towards failed threshold, fdc trip already processed */
#define DEM_DEBOUNCE_TIMEBASED_FROZEN_FAILED_FDC       ((0x09U) << DEM_SATELLITEDATA_DEBOUNCE_STATUS_POS) /*!< debouncing paused while counting towards failed threshold, fdc trip already processed */
#define DEM_DEBOUNCE_TIMEBASED_DONE_PASSED             ((0x0aU) << DEM_SATELLITEDATA_DEBOUNCE_STATUS_POS) /*!< debouncing completed, passed threshold reached */
#define DEM_DEBOUNCE_TIMEBASED_DONE_FAILED             ((0x0bU) << DEM_SATELLITEDATA_DEBOUNCE_STATUS_POS) /*!< debouncing completed, failed threshold reached */
/*!
 * \}
 */

/* ********************************************************************************************************************
 *  SUBCOMPONENT FUNCTION MACROS
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  SUBCOMPONENT DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef struct Dem_DebounceTimeBased_InfoType_s Dem_DebounceTimeBased_InfoType;

/*! Data for time-based debouncing
 *  \extends Dem_DebounceBase_InfoType_s  */
struct Dem_DebounceTimeBased_InfoType_s
{
  Dem_DebounceBase_InfoType Base;                      /*!< Base class object. This attribute must come first! */
  uint16 OldTimerValue;                                /*!< [in] debounce timer before processing */
  uint16 NewTimerValue;                                /*!< [out] debounce timer after processing */
  Dem_Debounce_StatusType OldTimerState;  /*!< [in] debounce state before processing */
  Dem_Debounce_StatusType NewTimerState;  /*!< [out] debounce state after processing */
};

/*! Pointer to debounce algorithm management data */
typedef P2VAR(Dem_DebounceTimeBased_InfoType, TYPEDEF, AUTOMATIC) Dem_DebounceTimeBased_InfoPtrType;
/*! Non-writeable pointer to debounce algorithm management data */
typedef P2CONST(Dem_DebounceTimeBased_InfoType, TYPEDEF, AUTOMATIC) Dem_DebounceTimeBased_ConstInfoPtrType;

#endif /* DEM_DEBOUNCETIMEBASED_TYPES_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_DebounceTimeBased_Types.h
 *********************************************************************************************************************/
