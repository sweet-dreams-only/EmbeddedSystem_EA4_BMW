/**
 *  \file
 *
 *  \brief       BUtil Nonvolatile Memory Types
 *
 *  This file contains the generic MvM types to be used by
 *  generic modules and their NvM adapters.
 *
 *  \project     BMW Platform Software
 *
 *  \copyright   BMW AG 2016 - 2017
 *
 *  \version     5.0.3
 *
*/

#ifndef BPS_BUTIL_GENERICNVMMEMTYPES_H
#define BPS_BUTIL_GENERICNVMMEMTYPES_H

/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include "BUtil_Version.h"


/*------------------------------------------------------------------------------
                      Macros
-------------------------------------------------------------------------------*/

/* check version of the module */
#if (!BUtil_CHECK_VERSION(5,0,3))
#error "Version of GenericNvMTypes.h does not match the version of the module!"
#endif


/*------------------------------------------------------------------------------
                      Data Types
-------------------------------------------------------------------------------*/

typedef enum {
  NVMSERVICE_OK,
  NVMSERVICE_NOT_OK
} NvMService_ResultType;

typedef void (NvMCallbackFunctionType)(NvMService_ResultType result, void* context);

#endif /* BPS_BUTIL_GENERICNVMMEMTYPES_H */
