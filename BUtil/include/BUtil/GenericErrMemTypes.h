/**
 *  \file
 *
 *  \brief       BUtil Generic Error Memory Types
 *
 *  This file contains the generic ErrMem types to be used by
 *  generic modules and their ErrMem adapters.
 *
 *  \project     BMW Platform Software
 *
 *  \copyright   BMW AG 2016 - 2017
 *
 *  \version     5.0.3
 *
*/

#ifndef BPS_BUTIL_GENERICERRMEMTYPES_H
#define BPS_BUTIL_GENERICERRMEMTYPES_H

/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include "BUtil_Version.h"


/*------------------------------------------------------------------------------
                      Macros
-------------------------------------------------------------------------------*/

/* check version of the module */
#if (!BUtil_CHECK_VERSION(5,0,3))
#error "Version of GenericErrMemTypes.h does not match the version of the module!"
#endif


/*------------------------------------------------------------------------------
                      Data Types
-------------------------------------------------------------------------------*/

typedef enum {
  ERRMEM_OK,
  ERRMEM_NOT_OK
} ErrMem_ResultType;

typedef enum {
  ERRMEM_EVENT_STATUS_PASSED,
  ERRMEM_EVENT_STATUS_FAILED
} ErrMem_EventStatusType;

/** \brief Clear Event Allowed
 *
 * This represents if an event can be cleared or not during a ClearDTC UDS command.
 *
 */
typedef enum {
  ERRMEM_CLEAR_ALLOWED,
  ERRMEM_CLEAR_NOT_ALLOWED
} ErrMem_ClearEventAllowedType;

#endif /* BPS_BUTIL_GENERICERRMEMTYPES_H */
