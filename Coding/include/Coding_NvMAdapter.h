/**
 * \file
 *
 * \brief       Coding NvM Adapter
 *
 * \project     BMW Platform Software
 *
 * \copyright   BMW AG 2016 - 2017
 *
 * \version     5.2.1
 *
 */

#ifndef CODING_NVMADAPTER_H_
#define CODING_NVMADAPTER_H_

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/

#include "BUtil/GenericNvMTypes.h"     /* BMW Nonvolatile Memory Types */
#include "BUtil/PlatformTypes.h"       /* BMW Platform Types           */
#include "Coding_Version.h"            /* Coding Version               */


/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/**
 * \brief check version of the module
 */
#if (!Coding_CHECK_VERSION(5, 2, 1))
#error "Version of Coding_NvMAdapter.h does not match the version of the module!"
#endif


/*------------------------------------------------------------------------------
                      Global Function Declarations
------------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif

#define Coding_START_SEC_CODE
#include "Coding_MemMap.h" /* PRQA S 5087 */

extern void Coding_NvM_ReadInitialCodingData(uint8* data, NvMCallbackFunctionType* finishCallback, void* context);

extern void Coding_NvM_ReadCodingData(uint8* data, NvMCallbackFunctionType* finishCallback, void* context);

extern void Coding_NvM_WriteCodingData(const uint8* data, NvMCallbackFunctionType* finishCallback, void* context);

#define Coding_STOP_SEC_CODE
#include "Coding_MemMap.h" /* PRQA S 5087 */

#ifdef __cplusplus
}
#endif

#endif /* CODING_NVMADAPTER_H_ */
