/**
*  \file
*
*  \brief       BMW SWC Darh NvM Adapter
*
*  This file contains the implementation of the BMW SWC Darh NvM Adapter
*  for usage in BMW Platform Software.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2017
*
*  \version     5.1.0
*
*/
/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/
#include "DarhClassic_Version.h"
#include "Rte_Darh.h"
#include "Darh_NvMAdapter.h"
#include "BUtil/PlatformTypes.h"
#include <stddef.h>

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/
#if (!DarhClassic_CHECK_VERSION(5, 1, 0))
#error "Version of Darh_NvMAdapter.c does not match the classic adapter version!"
#endif

/*------------------------------------------------------------------------------
                    Local Variables
------------------------------------------------------------------------------*/
#define Darh_START_SEC_CODE
#include "Darh_MemMap.h"

static NvMCallbackFunctionType* Darh_NvMFinishCallback;

#define Darh_STOP_SEC_CODE
#include "Darh_MemMap.h"

/*------------------------------------------------------------------------------
                    Global Functions
------------------------------------------------------------------------------*/

#define Darh_START_SEC_CODE
#include "Darh_MemMap.h"

void Darh_NvM_WriteOnShutdownBlock(const Darh_ErrorQueueType* errorQueue) {
  /* parameter is not needed in this case, but kept to provide interface compatibility */
  (void) errorQueue;
  (void) Rte_Call_ErrorQueueBlock_SetRamBlockStatus(TRUE);
} /* end of function Darh_NvM_WriteOnShutdownBlock */

void Darh_NvM_WriteDiagnoseMasterStatus(
    const boolean* diagnoseMasterStatus, NvMCallbackFunctionType* finishCallback, void* context) {
  (void) context;
  Darh_NvMFinishCallback = finishCallback;

  /* return value is ignored, error are reported to the callback */
  (void) Rte_Call_DiagnoseMasterStatus_WriteBlock(diagnoseMasterStatus);
}

Std_ReturnType Darh_NvMNotifyJobFinishedDiagnoseMasterStatus(uint8 ServiceId, NvM_RequestResultType JobResult) {
  (void) ServiceId;

  if (Darh_NvMFinishCallback) {
    Darh_NvMFinishCallback((NvMService_ResultType) JobResult, NULL);
    /* disable the callback */
    Darh_NvMFinishCallback = NULL;
  }

  return E_OK;
}

#define Darh_STOP_SEC_CODE
#include "Darh_MemMap.h"
