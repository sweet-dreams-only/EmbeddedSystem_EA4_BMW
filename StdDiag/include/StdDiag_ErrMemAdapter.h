/**
*  \file
*
*  \brief       BMW SWC StdDiag
*
*  This file is the Error Memory adapter header file of the generic part of the module StdDiag
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

#ifndef STDDIAG_ERRMEMADAPTER_H
#define STDDIAG_ERRMEMADAPTER_H

/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include "BUtil/PlatformTypes.h"
#include "BUtil/GenericErrMemTypes.h"
#include "StdDiag_Version.h"

/*------------------------------------------------------------------------------
                      Macros
-------------------------------------------------------------------------------*/

/* check version of the module */
#if (!StdDiag_CHECK_VERSION(5,3,0))
#error "Version of StdDiag_ErrMemAdapter.h does not match the version of the module!"
#endif

#ifdef __cplusplus
extern "C" {
#endif
/*------------------------------------------------------------------------------
                      Extern Declarations
-------------------------------------------------------------------------------*/

/**
 * \brief This function shall lock the error memory
 *
 * \retval ERRMEM_OK locking error memory was successful
 * \retval ERRMEM_NOT_OK locking error memory failed
 *
 */
extern ErrMem_ResultType StdDiag_ErrMem_LockErrorMemory(void);

/**
 * \brief This function shall unlock the error memory
 *
 * \retval ERRMEM_OK unlocking error memory was successful
 * \retval ERRMEM_NOT_OK unlocking error memory failed
 *
 */
extern ErrMem_ResultType StdDiag_ErrMem_UnlockErrorMemory(void);

#ifdef __cplusplus
}
#endif

#endif /* STDDIAG_ERRMEMADAPTER_H */


