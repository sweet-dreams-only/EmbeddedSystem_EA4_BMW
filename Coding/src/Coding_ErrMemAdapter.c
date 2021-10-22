/**
 * \file
 *
 * \brief       Coding ErrMem Adapter
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

#include "Coding_ErrMemAdapter.h"
#include "Coding.h"
#include "BUtil/GenericErrMemTypes.h"  /* BMW Error Memory Types */
#include "Rte_Coding.h"
#include "CodingClassic_Version.h"     /* Coding Classic Adapter Version */

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/**
 * \brief check version of the module
 */
#if (!CodingClassic_CHECK_VERSION(5, 2, 1))
#error "Version of Coding_ErrMemAdapter.c does not match the Classic adapter version!"
#endif


/*------------------------------------------------------------------------------
                      Local Variables
------------------------------------------------------------------------------*/

#define Coding_START_SEC_VAR_INIT_BOOLEAN
#include "Coding_MemMap.h" /* PRQA S 5087 */

static boolean Coding_ClearErrorAllowedVar = FALSE;

#define Coding_STOP_SEC_VAR_INIT_BOOLEAN
#include "Coding_MemMap.h" /* PRQA S 5087 */


/*------------------------------------------------------------------------------
                      Global Functions
------------------------------------------------------------------------------*/

#define Coding_START_SEC_CODE
#include "Coding_MemMap.h" /* PRQA S 5087 */

/*----------------------------------------------------------------------------*/
/**
 *  Service to control 'Not Coded' Coding UDS DTC deletion.
 *
 *  \lhref COD_117
 */
/*----------------------------------------------------------------------------*/
ErrMem_ResultType Coding_ErrMem_ClearEventAllowedNotCoded(ErrMem_ClearEventAllowedType clearEventAllowed) {
  if (ERRMEM_CLEAR_ALLOWED == clearEventAllowed) {
    Coding_ClearErrorAllowedVar = TRUE;
  } else {
    Coding_ClearErrorAllowedVar = FALSE;
  }

  return (ERRMEM_OK);
}

/*----------------------------------------------------------------------------*/
/**
 * Called by the Dem to decides if DTC CENC is allowed to be deleted.
 *
 *  \lhref COD_117
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_ClearEventAllowed(boolean* allowed) {
  *allowed = Coding_ClearErrorAllowedVar;

  return RTE_E_OK;
}

/*----------------------------------------------------------------------------*/
/**
 * Service that sets/clears 'Not Coded' Coding UDS DTCs.
 *
 * \lhref COD_114
 */
/*----------------------------------------------------------------------------*/
ErrMem_ResultType Coding_ErrMem_SetEventStatusNotCoded(ErrMem_EventStatusType eventStatus) {
  Std_ReturnType retVal;
  ErrMem_ResultType resVal = ERRMEM_NOT_OK;

  retVal = Rte_Call_EventNotCoded_SetEventStatus((uint8)eventStatus);

  if (retVal == E_OK) {
    resVal = ERRMEM_OK;
  }
  return (resVal);
}

/*----------------------------------------------------------------------------*/
/**
 * Service that sets/clears 'Wrong Vehicle' Coding UDS DTCs.
 *
 * \lhref COD_114
 */
/*----------------------------------------------------------------------------*/
ErrMem_ResultType Coding_ErrMem_SetEventStatusWrongVehicle(ErrMem_EventStatusType eventStatus) {
  Std_ReturnType retVal;
  ErrMem_ResultType resVal = ERRMEM_NOT_OK;

  retVal = Rte_Call_EventWrongVehicle_SetEventStatus((uint8)eventStatus);

  if (retVal == E_OK) {
    resVal = ERRMEM_OK;
  }
  return (resVal);
}

#if (CODING_PROD_ERROR_CEUD_DETECTION == STD_ON)
/*----------------------------------------------------------------------------*/
/**
 * Service that sets/clears 'Unqualified Data' Coding UDS DTCs.
 *
 * \lhref COD_114, COD_138
 */
/*----------------------------------------------------------------------------*/
ErrMem_ResultType Coding_ErrMem_SetEventStatusUnqualifiedData(ErrMem_EventStatusType eventStatus) {
  Std_ReturnType retVal;
  ErrMem_ResultType resVal = ERRMEM_NOT_OK;

  retVal = Rte_Call_EventUnqualifiedData_SetEventStatus((uint8)eventStatus);

  if (retVal == E_OK) {
    resVal = ERRMEM_OK;
  }
  return (resVal);
}

#endif


#define Coding_STOP_SEC_CODE
#include "Coding_MemMap.h" /* PRQA S 5087 */
