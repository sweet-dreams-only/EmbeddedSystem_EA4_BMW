/**
*  \file
*
*  \brief       Omc Error Memory Adapter Interface
*
*  This file contains the interface definition for the Omc Error Memory Adapter.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     5.1.0
*
*/
/*
   MISRA-C:2004 Rule 19.1: including Omc_MemMap.h is necessary throughout
   the file according to memory abstraction. See PRQA 5087.
*/

#ifndef OMC_ERRMEMADAPTER_H
#define OMC_ERRMEMADAPTER_H

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/
#include "Omc_Version.h"
#include "BUtil/GenericErrMemTypes.h"

#ifdef __cplusplus
extern "C" {
#endif
/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* Check version of the module */
#if (!Omc_CHECK_VERSION(5, 1, 0))
#error "Version of Omc_ErrMemAdapter.h does not match the version of the module!"
#endif

/*------------------------------------------------------------------------------
                      Data Types
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Global Variables
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Global Constants
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Global Function Declarations
------------------------------------------------------------------------------*/

#define Omc_START_SEC_CODE
#include "Omc_MemMap.h" /* PRQA S 5087 */

extern ErrMem_ResultType Omc_ErrMem_SetErrorStatusOmcOpMode(ErrMem_EventStatusType ErrorStatus);

extern ErrMem_ResultType Omc_ErrMem_EnableMemoryLockOmcOpMode(void);

extern ErrMem_ResultType Omc_ErrMem_DisableMemoryLockOmcOpMode(void);

extern ErrMem_ResultType Omc_ErrMem_SetClearEventAllowedOmcOpMode(ErrMem_ClearEventAllowedType ClearErrorAllowed);

#define Omc_STOP_SEC_CODE
#include "Omc_MemMap.h" /* PRQA S 5087 */

#ifdef __cplusplus
}
#endif

#endif /* OMC_ERRMEMADAPTER_H */
