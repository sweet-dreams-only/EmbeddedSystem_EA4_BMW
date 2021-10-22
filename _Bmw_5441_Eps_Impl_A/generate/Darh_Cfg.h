/*----------------------------------------------------------------------------*/
/**
*  \file
*
*  \brief       Darh Configuration
*
*  Configuration for Darh Module
*
*  \project     BMW Platfrom Software
*
*  \copyright   BMW AG 2015 - 2016
*
*  \version     5.1.0
*
*  \remarks     -
*
*/
/*----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
*
*  THIS FILE WAS GENERATED. DO NOT MODIFY!
*
*  GENERATOR       : BMW PAGe 1.1.0
*
*  GENERATION TIME : 2018-07-30 19:57:39.357024
*
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      MISRA-Deviations
------------------------------------------------------------------------------*/
/*
 * Violation of MISRA-C:2004 Rule 19.7:
 * Reason: this macro is only used in preprocessor directive,
 * no function possible. See PRQA 3453
 */
#ifndef DARH_CFG_H
#define DARH_CFG_H

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/
/**
 * \brief Switch to enable or disable the development assertion system
 *
 * Activation of development error detection
 *
 * \remarks This macro depends on configuration parameter DarhDevErrorDetect
 *
 */
#define DARH_DEV_ERROR_DETECT   STD_OFF
/**
 * \brief Macro of queue size
 *
 * Number of events which can be stored in the event queue
 *
 * \remarks This macro depends on configuration parameter DarhQueueSize
 *
 */
#define DARH_QUEUE_SIZE (3u)

/**
 * \brief Macro for maximum retry counter
 *
 * Maximum number of retry times to send a ROE message which the Dcm fails to transmit.
 *
 * \remarks This macro depends on the configuration parameter DarhRetryCount
 *
 */
#define DARH_RETRY_COUNT   3u

/**
 * \brief Cycle Time to trigger a new transmission in seconds
 */
#define DARH_QUEUE_CYCLE_TIME 1u

/**
 * \brief Value to represent a positive list
 */
#define DARH_REPORT_POSITIVE_LIST    1u

/**
 * \brief Value to represent a dynamic list
 */
#define DARH_REPORT_DYNAMICALLY      2u

/**
 * \breif Darh list type
 *
 * This macro represents type of list used:
 *   DARH_POSITIVE_LIST the stored events are those which shall be reported to the DM
 *   DARH_DYNAMICALLY an user callback shall be called to check if the event shall be reported to the DM
 *
 */
#define DARH_ACTIVE_REPORT_LIST_TYPE DARH_REPORT_POSITIVE_LIST

#endif /* DARH_CFG_H */
