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

/*------------------------------------------------------------------------------
                      MISRA-Deviations
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/

#include "Rte_Coding.h"
#include "Coding.h"
#include "Coding_Assert.h"
#include "Coding_NvMAdapter.h"
#include "CodingClassic_Version.h"     /* Coding Classic Adapter Version */

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/**
 * \brief check version of the module
 */
#if (!CodingClassic_CHECK_VERSION(5, 2, 1))
#error "Version of Coding_NvMAdapter.c does not match the Classic adapter version!"
#endif

/**
 * \brief Definition of the unique service ids of NVRAM manager services.
 */
#define CODING_NVM_READ_BLOCK_API_ID                           ((uint8)0x06u)
#define CODING_NVM_WRITE_BLOCK_API_ID                          ((uint8)0x07u)
#define CODING_NVM_READ_ALL_API_ID                             ((uint8)0x0Cu)

/**
 * \brief Definition of the unique request result of NVRAM manager services.
 */
#define CODING_NVM_REQ_BLOCK_SKIPPED                           ((uint8)0x04u)


/*------------------------------------------------------------------------------
                      Local Variables
------------------------------------------------------------------------------*/

#define Coding_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Coding_MemMap.h" /* PRQA S 5087 */

static NvMCallbackFunctionType* Coding_NvMCallbackFunction = NULL_PTR;
static void* Coding_NvMContext = NULL_PTR;

#define Coding_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Coding_MemMap.h" /* PRQA S 5087 */

#define Coding_START_SEC_VAR_CLEARED_BOOLEAN
#include "Coding_MemMap.h" /* PRQA S 5087 */

/* Indicates wheter a NvM_ReadAll() callback has been received */
static boolean Coding_ReadAllCallbackReceived = FALSE;

#define Coding_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Coding_MemMap.h" /* PRQA S 5087 */


/*------------------------------------------------------------------------------
                      Global Functions
------------------------------------------------------------------------------*/

#define Coding_START_SEC_CODE
#include "Coding_MemMap.h" /* PRQA S 5087 */

/*----------------------------------------------------------------------------*/
/**
 * Service to read initial coding data.
 *
 * \lhref COD_129, COD_130
 */
/*----------------------------------------------------------------------------*/
void Coding_NvM_ReadInitialCodingData(uint8* data, NvMCallbackFunctionType* finishCallback, void* context) {
  Std_ReturnType ret = E_NOT_OK;
  Coding_NvMCallbackFunction = finishCallback;
  Coding_NvMContext = context;

  /* the multi block service NvM_ReadAll() has been processed */
  if (TRUE == Coding_ReadAllCallbackReceived) {
    /** \lhref COD_127 */
    Coding_NvMCallbackFunction(NVMSERVICE_OK, NULL_PTR);
    return;
  }

  ret = Rte_Call_NvMService_ReadBlock(data);
  Coding_DevAssert(ret == RTE_E_OK, CODING_DEVERROR_NVMADPT);
}

/*----------------------------------------------------------------------------*/
/**
 * Service to read coding data.
 */
/*----------------------------------------------------------------------------*/
void Coding_NvM_ReadCodingData(uint8* data, NvMCallbackFunctionType* finishCallback, void* context) {
  Std_ReturnType ret;
  Coding_NvMCallbackFunction = finishCallback;
  Coding_NvMContext = context;

  ret = Rte_Call_NvMService_ReadBlock(data);
  Coding_DevAssert(ret == RTE_E_OK, CODING_DEVERROR_NVMADPT);
}

/*----------------------------------------------------------------------------*/
/**
 * Service to write coding data.
 */
/*----------------------------------------------------------------------------*/
void Coding_NvM_WriteCodingData(const uint8* data, NvMCallbackFunctionType* finishCallback, void* context) {
  Std_ReturnType ret;
  Coding_NvMCallbackFunction = finishCallback;
  Coding_NvMContext = context;

  ret = Rte_Call_NvMService_WriteBlock(data);
  Coding_DevAssert(ret == RTE_E_OK, CODING_DEVERROR_NVMADPT);
}

/*----------------------------------------------------------------------------*/
/**
 * Service to manage the job finished callback.
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_NvMNotifyJobFinishedCodingData(uint8 ServiceId, NvM_RequestResultType JobResult) {
  NvMService_ResultType result;

  /* the multi block service NvM_ReadAll() has been processed */
  if (CODING_NVM_READ_ALL_API_ID == ServiceId) {
    if (CODING_NVM_REQ_BLOCK_SKIPPED != JobResult) {
      /* coding data loaded successfully to RAM Mirror -> nothing more to do */
      Coding_ReadAllCallbackReceived = TRUE;
    }
    return E_OK;
  }

  /* convert error code */
  if (NVM_REQ_OK == JobResult) {
    result = NVMSERVICE_OK;
  } else {
    result = NVMSERVICE_NOT_OK;
  }

  Coding_DevAssert(NULL_PTR != Coding_NvMCallbackFunction, CODING_DEVERROR_NVMADPT);
  if (NULL_PTR == Coding_NvMCallbackFunction) {
    /* Necessary due to CodingTestClient: CodingTestClient requires:
     * - 0x08 NvM_RestoreBlockDefaults() or
     * - 0x0B NvM_InvalidateNvBlock()
     */
    return E_OK;
  }

  Coding_NvMCallbackFunction(result, NULL_PTR);

  return E_OK;
  /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

#define Coding_STOP_SEC_CODE
#include "Coding_MemMap.h" /* PRQA S 5087 */
