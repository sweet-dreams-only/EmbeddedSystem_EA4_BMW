/**
*  \file
*
*  \brief       Omc Error Memory Adapter
*
*  This file contains the Omc Error Memory functionality.
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
#include "Omc_ErrMemAdapter.h"
#include "Omc_Assert.h"
#include "Rte_Omc.h"
#include "Omc.h"
/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/**
 * \brief check version of the module
 */
#if (!OmcClassic_CHECK_VERSION(5, 2, 0))
#error "Version of Omc_ErrMemAdapter.c does not match the version of the module!"
#endif

/*------------------------------------------------------------------------------
                      Local Variables
------------------------------------------------------------------------------*/
#define Omc_START_SEC_VAR_INIT_BOOLEAN
#include "Omc_MemMap.h" /* PRQA S 5087 */

static boolean Omc_ClearErrorAllowedVar = FALSE;

#define Omc_STOP_SEC_VAR_INIT_BOOLEAN
#include "Omc_MemMap.h" /* PRQA S 5087 */

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

ErrMem_ResultType Omc_ErrMem_SetErrorStatusOmcOpMode(ErrMem_EventStatusType ErrorStatus) {
  Std_ReturnType retVal;
  ErrMem_ResultType result;
  retVal = Rte_Call_VsmEventOpmode_SetEventStatus(ErrorStatus);
  if ((retVal != RTE_E_OK) && (retVal != E_NOT_OK)) {
    result = ERRMEM_NOT_OK;
  } else {
    result = ERRMEM_OK;
  }
  return result;
}

ErrMem_ResultType Omc_ErrMem_EnableMemoryLockOmcOpMode(void) {
  ErrMem_ResultType result;
  if (E_OK == Rte_Call_EnableCond_OMC_SetEnableCondition(FALSE)) {
    result = ERRMEM_OK;
  } else {
    result = ERRMEM_NOT_OK;
  }
  return result;
}

ErrMem_ResultType Omc_ErrMem_DisableMemoryLockOmcOpMode(void) {
  ErrMem_ResultType result;
  if (E_OK == Rte_Call_EnableCond_OMC_SetEnableCondition(TRUE)) {
    result = ERRMEM_OK;
  } else {
    result = ERRMEM_NOT_OK;
  }
  return result;
}

ErrMem_ResultType Omc_ErrMem_SetClearEventAllowedOmcOpMode(ErrMem_ClearEventAllowedType ClearErrorAllowed) {
  if (ERRMEM_CLEAR_ALLOWED == ClearErrorAllowed) {
    Omc_ClearErrorAllowedVar = TRUE;
  } else {
    Omc_ClearErrorAllowedVar = FALSE;
  }

  return ERRMEM_OK;
}

Std_ReturnType Omc_ClearEventAllowed(boolean* Allowed) {
  *Allowed = Omc_ClearErrorAllowedVar;

  return RTE_E_OK;
}

#define Omc_STOP_SEC_CODE
#include "Omc_MemMap.h" /* PRQA S 5087 */
