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
/*! \addtogroup Dem_Data
 *  \{
 *  \file       Dem_Data_Types.h
 *  \brief      Diagnostic Event Manager (Dem) header file
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

#if !defined (DEM_DATA_TYPES_H)
#define DEM_DATA_TYPES_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                  /* Own subcomponent header */
/* ------------------------------------------------------------------------- */
#include "Dem_Int.h"

/* ********************************************************************************************************************
 *  SUBCOMPONENT CONSTANT MACROS
 *********************************************************************************************************************/

                                                           /* Data Provision */
/* ------------------------------------------------------------------------- */

#if (DEM_CFG_PROCESS_OCCTR_CONFIRMED == STD_ON)
/*! Start value for occurrence counter */
# define DEM_DATA_OCCURRENCE_INIT                (1U)
#else
/*! Start value for occurrence counter */
# define DEM_DATA_OCCURRENCE_INIT                (0U)
#endif

#if (DEM_CFG_DATA_OCCCTR_2BYTE == STD_ON)
/*! Maximum value for occurrence counter */
# define DEM_DATA_OCCURRENCE_MAX                 (0xffffU)
#else
/*! Maximum value for occurrence counter */
# define DEM_DATA_OCCURRENCE_MAX                 (0xffU)
#endif

/*!
 * \defgroup  Dem_Data_ChangeState  Macros encoding changed data while updating DTCs
 * Macros encoding changed data while updating DTCs
 * \{
 */
#define DEM_DATA_NO_CHANGES                      (0x00U)  /*!< No data changed */
#define DEM_DATA_USERDATA_CHANGED                (0x01U)  /*!< User data changed, update NV ram and call data change notification */
#define DEM_DATA_STATISTICS_CHANGED              (0x02U)  /*!< Internal data changed, update NV ram but no data change notification */
/*!
 * \}
 */


/*!
 * \defgroup  Dem_Data_OBD_FF_Update  Macros encoding freeze frame updates
 * Macros encoding freeze frame updates
 * \{
 */
#define DEM_DATA_FF_UPDATE_DATA                  (0x01U)  /*!< Store new freeze frame data */
#define DEM_DATA_FF_UPDATE_TIMESTAMP             (0x02U)  /*!< Update freeze frame order */
/*!
 * \}
 */

/*! Maximum value for OBD odometer */
#define DEM_DATA_MAX_OBD_ODOMETER                (0xffffU)

/*!
 * \defgroup  Dem_Data_B1Counter  Macros encoding B1 counter values
 * Macros encoding B1 counter values
 * \{
 */
#define DEM_DATA_B1_HEALING_COUNTER_THRESHOLD    (0x03U)    /*!< B1 healing counter threshold */
#define DEM_DATA_B1COUNTER_190H                  (0x2c88U)  /*!< B1 counter lower threshold after B1 deactivation */
#define DEM_DATA_B1COUNTER_200H                  (0x2ee0U)  /*!< B1 counter upper threshold for escalation */
#define DEM_DATA_B1COUNTER_LATCHED               (0x3bc4U)  /*!< B1 latched value */
/*!
 * \}
 */

/*!
 * \defgroup  Dem_Data_ContinuousMICounter  Macros encoding continuous MI counter values
 * Macros encoding continuous MI counter values
 * \{
 */
#define DEM_DATA_CONTINUOUS_MI_200H              (0x2ee0U)  /*!< continuous MI counter threshold */
#define DEM_DATA_CONTINUOUS_MI_LATCHED           (0x3bc4U)  /*!< continuous MI counter latched value */
/*!
 * \}
 */

/*!
 * \defgroup  Dem_Data_ContinuousMIHealing  Macros encoding special values for healing of continuous MI
 * Macros encoding special values for healing of continuous MI
 * \{
 */
#define DEM_DATA_CONTINUOUS_MI_HEALING_COUNTER_THRESHOLD  (0x03U)  /*!< continuous MI healing counter threshold */
#define DEM_DATA_CONTINUOUS_MI_HEALING_COUNTER_INVALID  (0xffU)    /*!< continuous MI healing counter invalid value (not healing) */
#define DEM_DATA_CONTINUOUS_MI_HEALING_COUNTER_LOCKED  (0xfeU)     /*!< continuous MI healing counter locked value */
#define DEM_DATA_CONTINUOUS_MI_HEALING_COUNTER_HEALED  (0xfcU)     /*!< continuous MI healing counter healing completed value */
/*!
 * \}
 */

/*!
 * \defgroup  Dem_Data_ContinuousMIAging  Macros encoding special values for aging counter of continuous MI
 * Macros encoding special values for aging counter of continuous MI
 * \{
 */

#define DEM_DATA_CONTINUOUS_MI_AGING_COUNTER_THRESHOLD  (0x28U)  /*!< continuous MI aging counter threshold */
#define DEM_DATA_CONTINUOUS_MI_AGING_COUNTER_INVALID    (0xffU)  /*!< continuous MI aging counter invalid value (not aging) */
#define DEM_DATA_CONTINUOUS_MI_AGING_COUNTER_AGED       (0xfcU)  /*!< continuous MI aging counter aging completed value */
/*!
 * \}
 */

/*!
 * \defgroup  Dem_Data_ContinuousMITimer  Macros encoding special values for aging timer of continuous MI
 * Macros encoding special values for aging timer of continuous MI
 * \{
 */
#define DEM_DATA_CONTINUOUS_MI_AGING_TIMER_INVALID     (0xffffU)  /*!< continuous MI aging timer invalid value (not aging) */
#define DEM_DATA_CONTINUOUS_MI_AGING_TIMER_AGED        (0xffccU)  /*!< continuous MI aging timer aging completed value */
/*!
 * \}
 */

/*!
 * \defgroup  Dem_Data_J1939LampStatus  Macros encoding J1939 lamp status
 * Macros encoding J1939 lamp status
 * \{
 */
#define DEM_DATA_J1939_INDICATOR_OFF             (0x0003U)  /*!< Bitmask for indicator off */
#define DEM_DATA_J1939_INDICATOR_NA              (0x0003U)  /*!< Bitmask for indicator not configured */

#define DEM_DATA_J1939_MIL_NA                    (DEM_DATA_J1939_INDICATOR_NA << 6)  /*!< Bitmask for MIL not configured */
#define DEM_DATA_J1939_RSL_NA                    (DEM_DATA_J1939_INDICATOR_NA << 4)  /*!< Bitmask for RSL not configured */
#define DEM_DATA_J1939_AWL_NA                    (DEM_DATA_J1939_INDICATOR_NA << 2)  /*!< Bitmask for AWL not configured */
#define DEM_DATA_J1939_PL_NA                     (DEM_DATA_J1939_INDICATOR_NA)       /*!< Bitmask for PL not configured */
/*!
 * \}
 */

#if (DEM_FEATURE_NEED_TIME_SERIES == STD_ON)
/*!
 * \defgroup  Dem_Data_TimeSeriesUpdate  Macros encoding time series record updates
 * Macros encoding time series record updates
 * \{
 */
#define DEM_DATA_NO_SAMPLE_UPDATE                (0x00U)  /*!< No update required */
#define DEM_DATA_NORMAL_SAMPLE_UPDATE            (0x01U)  /*!< Update normal rate time series snapshot records */
#define DEM_DATA_FAST_SAMPLE_UPDATE              (0x02U)  /*!< Update fast rate time series snapshot records */
/*!
 * \}
 */
#endif

/* ********************************************************************************************************************
 *  SUBCOMPONENT FUNCTION MACROS
 *********************************************************************************************************************/
/*! Test userdata changed flag of data changed state */
#define DEM_DATA_TEST_USERDATA_CHANGED(Status)   (((Status) & DEM_DATA_USERDATA_CHANGED) != 0)                                   /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set userdata changed flag of data changed state */
#define DEM_DATA_SET_USERDATA_CHANGED(Status)    ((uint8)((Status) | DEM_DATA_USERDATA_CHANGED))                                 /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Test statistics changed flag of data changed state */
#define DEM_DATA_TEST_STATISTICS_CHANGED(Status)  (((Status) & DEM_DATA_STATISTICS_CHANGED) != 0)                                /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set statistics changed flag of data changed state */
#define DEM_DATA_SET_STATISTICS_CHANGED(Status)  ((uint8)((Status) | DEM_DATA_STATISTICS_CHANGED))                               /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Test normal sample update flag of time series update state */
#define DEM_DATA_TEST_NORMAL_SAMPLE_UPDATE(Status)  (((Status) & DEM_DATA_NORMAL_SAMPLE_UPDATE) != 0)                            /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set normal sample update flag of time series update state */
#define DEM_DATA_SET_NORMAL_SAMPLE_UPDATE(Status)  ((uint8)((Status) | DEM_DATA_NORMAL_SAMPLE_UPDATE))                           /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Test fast sample update flag of time series update state */
#define DEM_DATA_TEST_FAST_SAMPLE_UPDATE(Status)   (((Status) & DEM_DATA_FAST_SAMPLE_UPDATE) != 0)                               /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set fast sample update flag of time series update state */
#define DEM_DATA_SET_FAST_SAMPLE_UPDATE(Status)    ((uint8)((Status) | DEM_DATA_FAST_SAMPLE_UPDATE))                             /* PRQA S 3453 */ /* MD_MSR_19.7 */

/* ********************************************************************************************************************
 *  SUBCOMPONENT DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

#if (DEM_CFG_DATA_OCCCTR_2BYTE == STD_ON)
/*! Type for DTC occurrence counter */
typedef uint16 Dem_Data_OccurrenceCounterType;
#else
/*! Type for DTC occurrence counter */
typedef uint8 Dem_Data_OccurrenceCounterType;
#endif

#endif /* DEM_DATA_TYPES_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_Data_Types.h
 *********************************************************************************************************************/
