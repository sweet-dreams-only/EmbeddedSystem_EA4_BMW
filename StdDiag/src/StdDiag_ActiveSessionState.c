/**
*  \file
*
*  \brief       BMW SWC StdDiag
*
*  This file contains the implementation of the module StdDiag
*  for usage in the BMW AUTOSAR Core.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     5.3.0
*
*  \remarks     The StdDiag module is responsible for BMW specific session
*               handling and handles a number of BMW specific diagnostic requests.
*
*/

/*------------------------------------------------------------------------------
                      MISRA-Deviations
------------------------------------------------------------------------------*/
/*
   MISRA-C:2004 Rule 19.1: including StdDiag_MemMap.h is necessary throughout
   the file according to memory abstraction. See PRQA 5087.
*/


/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include "BUtil/PlatformTypes.h"
#include "StdDiag_UDSAdapter.h"
#include "StdDiag.h"
#include "StdDiag_Internal.h"
#include "StdDiag_Version.h"
#include "StdDiag_ProgPreparation.h"
#include "StdDiag_OmcAdapter.h"
#include "StdDiag_DarhAdapter.h"
#include "StdDiag_Cfg.h"


/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!StdDiag_CHECK_VERSION(5,3,0))
   #error "Version of StdDiag_ActiveSessionState.c does not match the version of the module!"
#endif

/*------------------------------------------------------------------------------
                      Global Functions
-------------------------------------------------------------------------------*/
/* PRQA S 5087 2 */
#define StdDiag_START_SEC_CODE
#include "StdDiag_MemMap.h"

/**
 * \brief ReadDataByIdentifier ActiveSessionState
 *
 * This function collects data for diagnostic request
 * ReadDataByIdentifier ActiveSessionState
 *
 * \param[out] activeSessionState pointer to buffer to store data
 * \param[out] errorCode negative response code in case of an error
 *
 * \retval UDS_DIAG_JOB_FINISHED_OK job finished successful
 * \retval UDS_DIAG_JOB_FINISHED_E_NOT_OK job did not finish successful
 *
 * \lhref FL105, FL110, FL898, FL899, FL900, FL901, FL902
 *
 */
UDS_ReturnType StdDiag_ReadDataActiveSessionState( StdDiag_ActiveSessionStateType* activeSessionState, UDS_ErrorCodeType* errorCode)
{
  UDS_ReturnType retVal;
  UDS_SessionType currentActiveSession;
#if( STDDIAG_USER_ACTIVE_SESSION_STATE == STD_ON )
  uint8 userActiveSessionState = 0x00u;
#endif

  /* get current session */
  currentActiveSession = StdDiag_UDS_GetActiveSession();

  /* continue if module is initialized and active session has been read */
  if( (StdDiag_IsInitialized() == TRUE) && (currentActiveSession != UDS_DIAG_INVALID_SESSION) )
  {
    /* set current diagnostic session */
    (*activeSessionState)[0] = currentActiveSession;

    /* get current session state */
    (*activeSessionState)[1] = StdDiag_GetActiveSessionState();

#if( STDDIAG_USER_ACTIVE_SESSION_STATE == STD_ON )
    if ((UDS_DIAG_DEFAULT_SESSION != currentActiveSession) &&
        (UDS_DIAG_EXTENDED_SESSION != currentActiveSession))
    {
      /* call application to provide alternative active session state value */
      if (TRUE == StdDiag_App_GetActiveSessionState(currentActiveSession, &userActiveSessionState))
      {
        (*activeSessionState)[1] = userActiveSessionState;
      }
    }
#endif

    /* get Energy Saving State */
    (*activeSessionState)[2] = StdDiag_Omc_GetCurrentOperatingMode();

    /* get RoE State */
    (*activeSessionState)[3] = StdDiag_Darh_GetRoeState();

    retVal = UDS_DIAG_JOB_FINISHED_OK;
  }
  else
  {
    *errorCode = UDS_DIAG_E_CONDITIONSNOTCORRECT;
    retVal = UDS_DIAG_JOB_FINISHED_E_NOT_OK;
  }

  return retVal;
}

/* PRQA S 5087 2 */
#define StdDiag_STOP_SEC_CODE
#include "StdDiag_MemMap.h"

