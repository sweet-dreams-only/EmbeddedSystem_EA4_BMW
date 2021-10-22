/**
 * \file
 *
 * \brief       Dlog NvM Adapter.
 *
 * \project     BMW Platform Software
 *
 * \copyright   BMW AG 2016 - 2017
 *
 * \version     5.3.1
 *
 */

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/

#include "Dlog_NvMAdapter.h"
#include "DlogClassic_Cfg.h"
#if DLOG_ENABLE_RTE == STD_ON
#include "Rte_Dlog.h"
#else
#include "Dlog_Rte2C.h"
#endif

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!DlogClassic_CHECK_VERSION(5, 3, 1))
#error "Version of Dlog_NvMAdapter.c does not match the version of the module!"
#endif


#define DLOG_NVM_SERVICE_ID_READBLOCK 0x06
#define DLOG_NVM_SERVICE_ID_WRITEBLOCK 0x07

#if DLOG_ENABLE_SVK_HISTORY == STD_ON

/*------------------------------------------------------------------------------
                      Local Variables
------------------------------------------------------------------------------*/

#define Dlog_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

static void* Dlog_NvMSvkEntryContext = NULL;
static NvMCallbackFunctionType* Dlog_NvMSvkEntryCallback = NULL;

#define Dlog_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dlog_MemMap.h"  /* PRQA S 5087 */


/*------------------------------------------------------------------------------
                      Global Functions
------------------------------------------------------------------------------*/

#define Dlog_START_SEC_CODE
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

void Dlog_NvM_ReadInitialSvkHistoryMemory(Dlog_SvkHistoryMemoryType* data, NvMCallbackFunctionType* finishCallback, void* context) {
  NvM_RequestResultType requestResult;
  Std_ReturnType ret = Rte_Call_NvMService_DlogSvkHistory_GetErrorStatus(&requestResult);

  (void)data;

  if (E_OK != ret || NVM_REQ_OK != requestResult) {
    finishCallback(NVMSERVICE_NOT_OK, context);
  } else {
    finishCallback(NVMSERVICE_OK, context);
  }
}

void Dlog_NvM_WriteSvkHistoryMemory(const Dlog_SvkHistoryMemoryType* data, NvMCallbackFunctionType* finishCallback, void* context) {
  Std_ReturnType ret;
  Dlog_NvMSvkEntryCallback = finishCallback;
  Dlog_NvMSvkEntryContext = context;

  ret = Rte_Call_NvMService_DlogSvkHistory_WriteBlock(data);
  if (E_OK != ret) {
    finishCallback(NVMSERVICE_NOT_OK, context);
  }
}

void Dlog_NvM_ReadSvkEntry(uint8 index, Dlog_SvkEntryType* data, NvMCallbackFunctionType* finishCallback, void* context) {
  Std_ReturnType ret;
  Dlog_NvMSvkEntryCallback = finishCallback;
  Dlog_NvMSvkEntryContext = context;
  ret = Rte_Call_NvMService_DlogSvkEntry_SetDataIndex(index);
  if (E_OK == ret) {
    ret = Rte_Call_NvMService_DlogSvkEntry_ReadBlock(data);
  }
  if (E_OK != ret) {
    finishCallback(NVMSERVICE_NOT_OK, context);
  }
}

void Dlog_NvM_WriteSvkEntry(uint8 index, const Dlog_SvkEntryType* data, NvMCallbackFunctionType* finishCallback, void* context) {
  Std_ReturnType ret;
  Dlog_NvMSvkEntryCallback = finishCallback;
  Dlog_NvMSvkEntryContext = context;
  ret = Rte_Call_NvMService_DlogSvkEntry_SetDataIndex(index);
  if (E_OK == ret) {
    ret = Rte_Call_NvMService_DlogSvkEntry_WriteBlock(data);
  }
  if (E_OK != ret) {
    finishCallback(NVMSERVICE_NOT_OK, context);
  }
}

Std_ReturnType Dlog_NotifyJobFinishedSvkEntry(uint8 ServiceId, NvM_RequestResultType JobResult) {
  if (DLOG_NVM_SERVICE_ID_READBLOCK == ServiceId || DLOG_NVM_SERVICE_ID_WRITEBLOCK == ServiceId) {
    if (NVM_REQ_OK == JobResult) {
      Dlog_NvMSvkEntryCallback(NVMSERVICE_OK, Dlog_NvMSvkEntryContext);
    } else {
      Dlog_NvMSvkEntryCallback(NVMSERVICE_NOT_OK, Dlog_NvMSvkEntryContext);
    }
  }
  return E_OK;
}

#define Dlog_STOP_SEC_CODE
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

#endif /* #if DLOG_ENABLE_SVK_HISTORY == STD_ON */