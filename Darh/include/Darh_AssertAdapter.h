/**
*  \file
*
*  \brief       BMW SWC Darh
*
*  This file is a the assertion adapter header file of the generic part of the module Darh
*  for usage in the BMW AUTOSAR Core.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2016
*
*  \version     5.1.0
*
*/

#ifndef DARH_ASSERTADAPTER_H
#define DARH_ASSERTADAPTER_H

/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/
#include "Darh_Cfg.h"
#include "Rte_Darh.h"

/*------------------------------------------------------------------------------
                      Macros
-------------------------------------------------------------------------------*/
/*------------------[API service IDs]-----------------------------------------*/
/**
 * \brief Darh_LifeCycleHandler() service id
 */
#define DARH_SID_LIFECYCLEHANDLER                                          0x40U

/*------------------[Development error codes]---------------------------------*/
/**
 * \brief Error code for failed API call of other modules
 */
#define DARH_E_RETURN                                                      0x40U

#if (DARH_DEV_ERROR_DETECT == STD_ON)
/**
 * Log error, if condition evaluates to false
 */
#define Darh_Assert_DevAssert(condition, errorCode) \
   do { \
       if (!(condition)) { \
          (void)Rte_Call_DetPort_ReportError(0, (uint8)((errorCode)>>8), (uint8)((errorCode) & 0xff)); \
       } \
   } while(0)

/**
 * Log error and return with returnCode, if condition evaluates to false
 */
#define Darh_Assert_DevAssertReturn(condition, errorCode, returnCode) \
   do { \
       if (!(condition)) { \
          (void)Rte_Call_DetPort_ReportError(0, (uint8)((errorCode)>>8), (uint8)((errorCode) & 0xff)); \
          return (returnCode); \
       } \
   } while(0)

/**
 * Log error and return, if condition evaluates to false
 */
#define Darh_Assert_DevAssertReturnVoid(condition, errorCode) \
   do { \
       if (!(condition)) { \
          (void)Rte_Call_DetPort_ReportError(0, (uint8)((errorCode)>>8), (uint8)((errorCode) & 0xff)); \
          return; \
       } \
   } while(0)

#else

/**
 * Log error, if condition evaluates to false
 */
#define Darh_Assert_DevAssert(condition, errorCode) do {} while(0)

/**
 * Log error and return with returnCode, if condition evaluates to false
 */
#define Darh_Assert_DevAssertReturn(condition, errorCode, returnCode) do {} while(0)

/**
 * Log error and return, if condition evaluates to false
 */
#define Darh_Assert_DevAssertReturnVoid(condition, errorCode) do {} while(0)

#endif /* (DARH_DEV_ERROR_DETECT == STD_ON) */

#endif /* DARH_ASSERTADAPTER_H */
