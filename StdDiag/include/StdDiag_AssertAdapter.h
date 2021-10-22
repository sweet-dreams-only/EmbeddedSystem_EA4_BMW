/**
*  \file
*
*  \brief       BMW SWC StdDiag
*
*  This file is a stub for the assertion adapter header file of the generic part of the module StdDiag
*  for usage in the BMW AUTOSAR Core.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2017
*
*  \version     5.4.0
*
*  \remarks     The StdDiag module is responsible for BMW specific session
*               handling and handles a number of BMW specific diagnostic requests.
*
*/

#ifndef STDDIAG_ASSERTADAPTER_H
#define STDDIAG_ASSERTADAPTER_H

/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/
#include "StdDiag_Cfg.h"
#include "Rte_StdDiag.h"

/*------------------------------------------------------------------------------
                      Macros
-------------------------------------------------------------------------------*/

/* development errors needed by generic part */
#define STDDIAG_DEVERROR_LIFECYCLE_ERROR           0x0000u
#define STDDIAG_DEVERROR_CHECKPROGPRECOND_SIZE     0x0001u

/* development errors needed by classic adapter */
#define STDDIAG_DEVERROR_ROESTATE_NOT_AVAILABLE      0x1000u
#define STDDIAG_DEVERROR_DLT_READLOGCHANNELNAMES     0x1001u
#define STDDIAG_DEVERROR_DCM_SESSION_NOT_AVAILABLE   0x1002u
#define STDDIAG_DEVERROR_LIFECYCLE_SWITCH_FAILED     0x1003u
#define STDDIAG_DEVERROR_LOCK_ERROR_MEMORY_FAILED    0x1004u
#define STDDIAG_DEVERROR_UNLOCK_ERROR_MEMORY_FAILED  0x1005u


#if (STDDIAG_DEV_ERROR_DETECT == STD_ON)
/**
 * Log error, if condition evaluates to false
 */
#define StdDiag_Assert_DevAssert(condition, errorCode) \
   do { \
       if (!(condition)) { \
          (void)Rte_Call_ReportErrorPort_ReportError(0, (uint8)((errorCode)>>8), (uint8)((errorCode) & 0xff)); \
       } \
   } while(0)

/**
 * Log error and return with returnCode, if condition evaluates to false
 */
#define StdDiag_Assert_DevAssertReturn(condition, errorCode, returnCode) \
   do { \
       if (!(condition)) { \
          (void)Rte_Call_ReportErrorPort_ReportError(0, (uint8)((errorCode)>>8), (uint8)((errorCode) & 0xff)); \
          return (returnCode); \
       } \
   } while(0)

/**
 * Log error and return, if condition evaluates to false
 */
#define StdDiag_Assert_DevAssertReturnVoid(condition, errorCode) \
   do { \
       if (!(condition)) { \
          (void)Rte_Call_ReportErrorPort_ReportError(0, (uint8)((errorCode)>>8), (uint8)((errorCode) & 0xff)); \
          return; \
       } \
   } while(0)

#else

/**
 * Log error, if condition evaluates to false
 */
#define StdDiag_Assert_DevAssert(condition, errorCode) do {} while(0)

/**
 * Log error and return with returnCode, if condition evaluates to false
 */
#define StdDiag_Assert_DevAssertReturn(condition, errorCode, returnCode) do {} while(0)

/**
 * Log error and return, if condition evaluates to false
 */
#define StdDiag_Assert_DevAssertReturnVoid(condition, errorCode) do {} while(0)

#endif /* (STDDIAG_DEV_ERROR_DETECT == STD_ON) */

#endif /* STDDIAG_ASSERTADAPTER_H */
