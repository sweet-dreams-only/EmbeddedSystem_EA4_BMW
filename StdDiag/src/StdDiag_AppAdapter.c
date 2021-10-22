/**
*  \file
*
*  \brief       BMW SWC StdDiag Adapter
*
*  This file contains the implementation of the StdDiag Application adapter
*  for usage in the classic BMW AUTOSAR Core.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2017
*
*  \version     5.4.0
*
*  \remarks     The StdDiag module is responsible for BMW specific session
*               handling and handles a number of BMW specific diagnostic requests.
*
*/

/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/
#include "StdDiag_AppAdapter.h"
#include "StdDiagClassic_Version.h"
#include "StdDiag.h"
#include "StdDiag_Cfg.h"
#include "Rte_StdDiag.h"


/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!StdDiagClassic_CHECK_VERSION(5,4,0))
#error "Version of StdDiag_AppAdapter.c does not match the adapter version!"
#endif


/*------------------------------------------------------------------------------
                      Global Variables
------------------------------------------------------------------------------*/
#if( STDDIAG_USER_ESTABLISH_INTRINSIC_SAFETY == STD_ON )
/* PRQA S 5087 2 */
#define StdDiag_START_SEC_VAR_NO_INIT_BOOLEAN
#include "StdDiag_MemMap.h"

/**
 * \brief StdDiag_IntrinsicSafetyPending indicates that application callback is outstanding
 */
static boolean StdDiag_IntrinsicSafetyPending;

/**
 * \brief StdDiag_IntrinsicSafetyCancelPending indicates that application callback is outstanding
 */
static boolean StdDiag_IntrinsicSafetyCancelPending;

/* PRQA S 5087 2 */
#define StdDiag_STOP_SEC_VAR_NO_INIT_BOOLEAN
#include "StdDiag_MemMap.h"
#endif /* STDDIAG_USER_ESTABLISH_INTRINSIC_SAFETY == STD_ON */

/*------------------------------------------------------------------------------
                      Global Functions
-------------------------------------------------------------------------------*/
/* PRQA S 5087 2 */
#define StdDiag_START_SEC_CODE
#include "StdDiag_MemMap.h"

#if( STDDIAG_USRPRECONDITIONCHECK == STD_ON )
StdDiag_App_ReturnType StdDiag_App_CheckProgrammingPreconditions(boolean skipOnboardData, size_t* numberFailedPreconditions, uint8* failedPreconditionList) {
  /* this adapter function is implemented asynchronous, so out parameters are not used. */
  (void) numberFailedPreconditions;
  (void) failedPreconditionList;

  if (E_OK == Rte_Call_UserProgrammingPreconditionsCheckPort_UserCheckProgrammingPreconditions(skipOnboardData))
  {
    return STDDIAG_APPL_RUNNING;
  }

  return STDDIAG_APPL_E_NOT_OK;
}

/**
 * \brief callback notification for user programming precondition check
 *
 * This function is called when evaluation of user programming preconditions has
 * been finished.
 *
 * \remarks This function is called on an asynchronous server call returns event.
 *
 */
void StdDiag_UserProgrammingPreconditionsCheckCbk( void ) {
  Std_ReturnType retVal;
  uint8 precondList[STDDIAG_MAX_NUMBER_PRECOND];
  uint8 precondNumber;

  retVal = Rte_Result_UserProgrammingPreconditionsCheckPort_UserCheckProgrammingPreconditions(&precondNumber, precondList);

  if (E_OK == retVal)
  {
    StdDiag_CheckProgrammingPreconditions_Callback_ResultOk(precondList, precondNumber);
  }
  else
  {
    StdDiag_CheckProgrammingPreconditions_Callback_ResultError(UDS_DIAG_E_CONDITIONSNOTCORRECT);
  }
}

#endif /* STDDIAG_USRPRECONDITIONCHECK == STD_ON */

#if( STDDIAG_USER_ESTABLISH_INTRINSIC_SAFETY == STD_ON )
StdDiag_App_ReturnType StdDiag_App_EstablishIntrinsicSafety( void )
{
  StdDiag_App_ReturnType retVal = STDDIAG_APPL_E_NOT_OK;
  Std_ReturnType retValUser;
  boolean status = FALSE;

  StdDiag_IntrinsicSafetyPending = FALSE;

  retValUser = Rte_Call_UserEstablishIntrinsicSafetyPort_EstablishIntrinsicSafety(&status);

  switch(retValUser) {
    case E_OK:
    if (TRUE == status)
    {
      retVal = STDDIAG_APPL_OK;
    }
      break;

    case RTE_E_UserEstablishIntrinsicSafety_E_RUNNING:
      StdDiag_IntrinsicSafetyPending = TRUE;
      retVal = STDDIAG_APPL_RUNNING;
      break;

    default:
      break;
  }
  return retVal;
}

/**
 * \brief callback notification for establishing intrinsic safety
 *
 * This function is called when establishing intrinsic safety has
 * been finished.
 *
 * \param[in]  IntrinsicSafetyEstablished indicates whether establishing intrinsic safety was successful
 *
 * \retval E_OK function returns always ok
 *
 * \remarks This function is called on an operation invoked event.
 *
 */
Std_ReturnType StdDiag_App_EstablishIntrinsicSafetyCbk( boolean IntrinsicSafetyEstablished )
{
  if (TRUE == StdDiag_IntrinsicSafetyPending)
  {
    (void) Rte_Call_AllowOpModeChangeCbkPort_OpModeSwitchAllowedResult( IntrinsicSafetyEstablished );
    StdDiag_IntrinsicSafetyPending = FALSE;
  }

  return E_OK;
}

StdDiag_App_ReturnType StdDiag_App_RevertIntrinsicSafety( void )
{
  StdDiag_App_ReturnType retVal = STDDIAG_APPL_OK;

  StdDiag_IntrinsicSafetyCancelPending = FALSE;

  if (RTE_E_UserEstablishIntrinsicSafety_E_RUNNING == Rte_Call_UserEstablishIntrinsicSafetyPort_EstablishIntrinsicSafetyCancelled())
  {
    StdDiag_IntrinsicSafetyCancelPending = TRUE;
    retVal = STDDIAG_APPL_RUNNING;
  }

  return retVal;
}

/**
 * \brief callback notification for cancellation of establishing intrinsic safety
 *
 * This function is called when cancellation process of establishing intrinsic safety has
 * been finished.
 *
 * \retval E_OK function returns always ok
 *
 * \remarks This function is called on an operation invoked event.
 *
 */
Std_ReturnType StdDiag_App_EstablishIntrinsicSafetyCancelledAck( void )
{
  if (TRUE == StdDiag_IntrinsicSafetyCancelPending)
  {
    (void) Rte_Call_AllowOpModeChangeCbkPort_OpModeSwitchCancelledAck();
    StdDiag_IntrinsicSafetyCancelPending = FALSE;
  }

  return E_OK;
}
#endif /* STDDIAG_USER_ESTABLISH_INTRINSIC_SAFETY == STD_ON */

#if( STDDIAG_USER_ACTIVE_SESSION_STATE == STD_ON )
boolean StdDiag_App_GetActiveSessionState(UDS_SessionType currentActiveSession, uint8* activeSessionState)
{
  boolean result = FALSE;
  uint8 tempActiveSessionState;

  if (E_OK == Rte_Call_UserActiveSessionStatePort_GetActiveSessionState(currentActiveSession, &tempActiveSessionState))
  {
    *activeSessionState = tempActiveSessionState;
    result = TRUE;
  }

  return result;
}
#endif /* STDDIAG_USER_ACTIVE_SESSION_STATE == STD_ON */

/* PRQA S 5087 2 */
#define StdDiag_STOP_SEC_CODE
#include "StdDiag_MemMap.h"

