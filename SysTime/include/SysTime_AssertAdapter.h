/**
*  \file
*
*  \brief       BMW SWC SysTime
*
*  This file is a stub for the assertion adapter header file of the generic part of the module SysTime
*  for usage in the BMW AUTOSAR Core.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2017
*
*  \version     5.0.3
*
*/

#ifndef SYSTIME_ASSERTADAPTER_H
#define SYSTIME_ASSERTADAPTER_H

/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/
#include "SysTime_Cfg.h"
#include "Rte_SysTime.h"

/*------------------------------------------------------------------------------
                      Macros
-------------------------------------------------------------------------------*/

/**\{*/
/**
 * \name Error IDs for reporting of DET-errors
 */
#define SYSTIME_DEVERROR_INITIALIZATION     0x0000u  /**< Initialization Error in generic part */
#define SYSTIME_DEVERROR_LIFECYCLE_FAILED   0x0100u  /**< Lifecycle Error in classic adapter */
/**\}*/

#if (SYSTIME_DEV_ERROR_DETECT == STD_ON)
/**
 * Log error, if condition evaluates to false
 */
#define SysTime_Assert_DevAssert(condition, errorCode) \
   do { \
       if (!(condition)) { \
          (void)Rte_Call_SysTimeReportError_ReportError(0, (uint8)((errorCode)>>8u), (uint8)((errorCode) & 0xffu)); \
       } \
   } while(0)

/**
 * Log error and return with returnCode, if condition evaluates to false
 */
#define SysTime_Assert_DevAssertReturn(condition, errorCode, returnCode) \
   do { \
       if (!(condition)) { \
          (void)Rte_Call_SysTimeReportError_ReportError(0, (uint8)((errorCode)>>8u), (uint8)((errorCode) & 0xffu)); \
          return (returnCode); \
       } \
   } while(0)

/**
 * Log error and return, if condition evaluates to false
 */
#define SysTime_Assert_DevAssertReturnVoid(condition, errorCode) \
   do { \
       if (!(condition)) { \
          (void)Rte_Call_SysTimeReportError_ReportError(0, (uint8)((errorCode)>>8u), (uint8)((errorCode) & 0xffu)); \
          return; \
       } \
   } while(0)

#else

/**
 * Log error, if condition evaluates to false
 */
#define SysTime_Assert_DevAssert(condition, errorCode) do {} while(0)

/**
 * Log error and return with returnCode, if condition evaluates to false
 */
#define SysTime_Assert_DevAssertReturn(condition, errorCode, returnCode) do {} while(0)

/**
 * Log error and return, if condition evaluates to false
 */
#define SysTime_Assert_DevAssertReturnVoid(condition, errorCode) do {} while(0)

#endif /* (SYSTIME_DEV_ERROR_DETECT == STD_ON) */

#endif /* SYSTIME_ASSERTADAPTER_H */
