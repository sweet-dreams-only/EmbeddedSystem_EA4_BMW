/**
*  \file
*
*  \brief       BMW SWC StdDiag
*
*  This file is the UDS adapter header file of the generic part of the module StdDiag
*  for usage in the BMW AUTOSAR Core.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     5.3.0
*
*  \remarks     The StdDiag module is responsible for BMW specific session
*               handling and handles a number of BMW specific diagnostic requests.
*
*/

#ifndef STDDIAG_UDSADAPTER_H
#define STDDIAG_UDSADAPTER_H

/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include "BUtil/PlatformTypes.h"
#include "StdDiag_Version.h"
#include "BUtil/GenericUDSTypes.h"
#include <stddef.h>

/*------------------------------------------------------------------------------
                      Macros
-------------------------------------------------------------------------------*/

/* check version of the module */
#if (!StdDiag_CHECK_VERSION(5,3,0))
#error "Version of StdDiag_UDSAdapter.h does not match the version of the module!"
#endif


#ifdef __cplusplus
extern "C" {
#endif
/*------------------------------------------------------------------------------
                      Extern Declarations
-------------------------------------------------------------------------------*/

/**
 * \brief This function returns the current diagnostic session
 *
 * \retval UDS_SessionType currently active diagnostic session
 * \retval UDS_DIAG_INVALID_SESSION in case diagnostic session can not be provided
 *
 */
extern UDS_SessionType StdDiag_UDS_GetActiveSession(void);

/**
 * \brief This function is the callback for successful asynchronous precondition check
 *
 * \param[in] responseData holds a list of failed preconditions
 * \param[in] resDataLength holds the number of failed preconditions
 */
extern void StdDiag_UDS_RoutineControlRawCheckProgrammingPreconditions_Start_ResultOk(uint8* responseData, size_t resDataLength);

/**
 * \brief This function is the callback for failed asynchronous precondition check
 *
 * \param[in] errorCode holds the error code of the failure
 */
extern void StdDiag_UDS_RoutineControlRawCheckProgrammingPreconditions_Start_ResultError(UDS_ErrorCodeType errorCode);

#ifdef __cplusplus
}
#endif

#endif /* STDDIAG_UDSADAPTER_H */