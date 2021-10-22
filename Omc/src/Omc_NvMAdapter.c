/**
*  \file
*
*  \brief       Omc Nonvolatile Memory Adapter
*
*  This file contains the Omc nonvolatile memory functionality.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     5.2.0
*
*/
/*------------------------------------------------------------------------------
                      MISRA-Deviations
------------------------------------------------------------------------------*/
/*
   MISRA-C:2004 Rule 19.1: including Omc_MemMap.h is necessary throughout
   the file according to memory abstraction. See PRQA 5087.
*/
/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/
#include "OmcClassic_Version.h"
#include "Rte_Omc.h"
#include "Omc_NvMAdapter.h"
#include "Omc_Data.h"
#include "Omc.h"

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/
/**
 * \brief check version of the module
 */
#if (!OmcClassic_CHECK_VERSION(5, 2, 0))
#error "Version of Omc_NvMAdapter.c does not match the version of the module!"
#endif


#define OMC_NVM_SID_WRITEBLOCK 0x07u

/*------------------------------------------------------------------------------
                      Global Variables
------------------------------------------------------------------------------*/
NvMCallbackFunctionType * Omc_NvM_Callback;
void * Omc_NvM_Context;

/*------------------------------------------------------------------------------
                      Local Functions Prototypes
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Local Functions
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Global Functions
------------------------------------------------------------------------------*/

#define Omc_START_SEC_CODE
#include "Omc_MemMap.h" /* PRQA S 5087 */

NvMService_ResultType Omc_NvM_WriteOperatingModes(Omc_NvDataType const* operatingmodesData, NvMCallbackFunctionType* callback, void* context) {
  Std_ReturnType result;
  NvMService_ResultType retVal = NVMSERVICE_NOT_OK;

  result = Rte_Call_NvMServicePort_WriteBlock(operatingmodesData);

  if (E_OK == result) {
    retVal = NVMSERVICE_OK;
  }

  Omc_NvM_Callback = callback;
  Omc_NvM_Context = context;

  return retVal;
}

Std_ReturnType Omc_NvMNotifyJobFinishedOperatingModes(uint8 ServiceId, RequestResultType JobResult) {
  NvMService_ResultType result;

  /* we only want callbacks for WriteBlock requests */
  if (OMC_NVM_SID_WRITEBLOCK == ServiceId) {
    /* convert error code */
    if (NVM_REQ_OK == JobResult) {
      result = NVMSERVICE_OK;
    } else {
      result = NVMSERVICE_NOT_OK;
    }

    /* call Omc callback */
    Omc_NvM_Callback(result, Omc_NvM_Context);
  }
  return E_OK;
}

#define Omc_STOP_SEC_CODE
#include "Omc_MemMap.h" /* PRQA S 5087 */
