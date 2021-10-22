/**
*  \file
*
*  \brief       Darh NvM Adapter
*
*  NvM Adapter header file for Darh Module
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2016
*
*  \version     5.1.0
*
*  \remarks     -
*
*/
#ifndef DARH_NVMADAPTER_H
#define DARH_NVMADAPTER_H

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/
#include "BUtil/PlatformTypes.h"
#include "BUtil/GenericNvMTypes.h"
#include "Darh_Version.h"
#include "Darh_NvM.h"

#ifdef __cplusplus
extern "C" {
#endif
/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/
/*
 * \brief  check version of the module
 */
#if (!Darh_CHECK_VERSION(5, 1, 0))
#error "Version of Darh_NvMAdapter.c does not match the version of the module!"
#endif

/*------------------------------------------------------------------------------
                      Data Types
------------------------------------------------------------------------------*/
typedef struct {
  NvMService_ResultType result;
  boolean called;
} NvMService_CallbackStatusType;

/*------------------------------------------------------------------------------
                      Global Function Declarations
------------------------------------------------------------------------------*/
#define Darh_START_SEC_CODE
#include "Darh_MemMap.h"

/**
 * \brief Indicates that the Block of NvM shall be written during shutdown
 *
 * This interface indicates the NvM adapter that the Block contining the
 * error queue shall be written in shutdown.
 *
 * \param errorQueue pointer to the queue to be written
 *
 * \return --
 *
 */
extern void Darh_NvM_WriteOnShutdownBlock(const Darh_ErrorQueueType* errorQueue);

/**
 * \brief Writes the state of the Diagnose Master Enable on the fly to the NvM.
 *
 * This interface is called to write a specific value to the NvM. The interface
 * may return before the data is written persistence.
 *
 * \param[in] diagnoseMasterStatus value to be written (the block is a ptr to boolean).
 *
 * \return NVMSERVICE_OK if success, NVMSERVICE_NOT_OK if an error occurs.
 *
 */
extern void Darh_NvM_WriteDiagnoseMasterStatus(
    const boolean* diagnoseMasterStatus, NvMCallbackFunctionType* finishCallback, void* context);

#define Darh_STOP_SEC_CODE
#include "Darh_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* DARH_NVMADAPTER_H */
