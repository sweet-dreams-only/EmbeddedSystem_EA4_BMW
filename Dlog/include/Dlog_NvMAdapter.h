/**
 * \file
 *
 * \brief       Dlog Nonvolatile Memory Adapter.
 *
 * \project     BMW Platform Software
 *
 * \copyright   BMW AG 2015 - 2016
 *
 * \version     5.1.1
 *
 */

#ifndef BPS_DLOG_NVMADAPTER_H
#define BPS_DLOG_NVMADAPTER_H

/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include "Dlog_SvkGen.h"
#include "BUtil/GenericNvMTypes.h"

/*------------------------------------------------------------------------------
                      Macros
-------------------------------------------------------------------------------*/

/* check version of the module */
#if (!Dlog_CHECK_VERSION(5,1,1))
#error "Version of Dlog_NvMAdapter.h does not match the version of the module!"
#endif


#ifdef __cplusplus
extern "C" {
#endif

#if DLOG_ENABLE_SVK_HISTORY == STD_ON
extern void Dlog_NvM_ReadInitialSvkHistoryMemory(Dlog_SvkHistoryMemoryType* data, NvMCallbackFunctionType* finishCallback, void* context);
extern void Dlog_NvM_WriteSvkHistoryMemory(const Dlog_SvkHistoryMemoryType* data, NvMCallbackFunctionType* finishCallback, void* context);

extern void Dlog_NvM_ReadSvkEntry(uint8 index, Dlog_SvkEntryType* data, NvMCallbackFunctionType* finishCallback, void* context);
extern void Dlog_NvM_WriteSvkEntry(uint8 index, const Dlog_SvkEntryType* data, NvMCallbackFunctionType* finishCallback, void* context);
#endif

#ifdef __cplusplus
}
#endif

#endif /* BPS_DLOG_NVMADAPTER_H */
