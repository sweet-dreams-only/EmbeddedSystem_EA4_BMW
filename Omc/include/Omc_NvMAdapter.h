/**
*  \file
*
*  \brief       Omc NvM Interface
*
*  This file contains the interface definition for the Omc Nonvolatile Memory
*  Adapter.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     5.1.0
*
*/
/*
   MISRA-C:2004 Rule 19.1: including ModuleName_MemMap.h is necessary throughout
   the file according to memory abstraction. See PRQA 5087.
*/

#ifndef OMC_NVMADAPTER_H
#define OMC_NVMADAPTER_H

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/
#include "Omc_Version.h"
#include "Omc_Data.h"
#include "BUtil/GenericNvMTypes.h"

#ifdef __cplusplus
extern "C" {
#endif
/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* Check version of the module */
#if (!Omc_CHECK_VERSION(5, 1, 0))
#error "Version of Omc_NvMAdapter.h does not match the version of the module!"
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

extern NvMService_ResultType
Omc_NvM_WriteOperatingModes(const Omc_NvDataType* operatingmodesData, NvMCallbackFunctionType* callback, void* context);

#define Omc_STOP_SEC_CODE
#include "Omc_MemMap.h" /* PRQA S 5087 */

#ifdef __cplusplus
}
#endif

#endif /* OMC_NVMADAPTER_H */
