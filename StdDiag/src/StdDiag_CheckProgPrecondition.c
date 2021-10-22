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
#include "StdDiag.h"
#include "StdDiag_Version.h"
#include "StdDiag_Cfg.h"
#include "StdDiag_UDSAdapter.h"
#include "StdDiag_AppAdapter.h"
#include "StdDiag_StmAdapter.h"
#include "StdDiag_ProgPreparation.h"
#include "StdDiag_AssertAdapter.h"
#include <string.h>


/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!StdDiag_CHECK_VERSION(5,3,0))
   #error "Version of StdDiag_CheckProgPrecondition.c does not match the version of the module!"
#endif


/**
 * \brief PreCondition Id for PWF state
 *
 * This macro specifies the PreCondition Id for PWF state
 * to be returned via UDS Service $31 $01 $02 $03
 */
#define STDDIAG_PRECOND_PAD_NOT_ACTIVE 0x09u

/*------------------------------------------------------------------------------
                      Global Variables
-------------------------------------------------------------------------------*/
/* PRQA S 5087 2 */
#define StdDiag_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "StdDiag_MemMap.h"

/**
 * \brief StdDiag_ProgPrecondList holds the currently failed programming preconditions
 */
static uint8 StdDiag_ProgPrecondList[STDDIAG_MAX_NUMBER_PRECOND];

/* PRQA S 5087 2 */
#define StdDiag_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "StdDiag_MemMap.h"

/*------------------------------------------------------------------------------
                      Global Functions
-------------------------------------------------------------------------------*/
/* PRQA S 5087 2 */
#define StdDiag_START_SEC_CODE
#include "StdDiag_MemMap.h"

/**
 * \brief RoutineControl CheckProgrammingPreconditions
 *
 * This function handles the diagnostic request
 * RoutineControl CheckProgrammingPreconditions
 *
 * \param[in] requestData pointer to buffer holding input data
 * \param[in] reqDataLength pointer to length of input data
 * \param[out] responseData pointer to buffer to store output data
 * \param[out] resDataLength pointer to length of output data
 * \param[out] errorCode negative response code in case of an error
 *
 * \retval UDS_DIAG_JOB_FINISHED_OK job finished successful
 * \retval UDS_DIAG_JOB_RUNNING job is handled asynchronously, result will be provided via callbacks
 * \retval UDS_DIAG_JOB_FINISHED_E_NOT_OK job did not finish successful
 *
 * \lhref FL191, FL192, FL193, FL_195, FL1078, FL1080, FL1084, FL1085, FL1086, FL1087
 *
 */
UDS_ReturnType StdDiag_RoutineControlRawCheckProgrammingPreconditions_Start( const uint8* requestData, size_t reqDataLength, uint8* responseData, size_t *resDataLength, UDS_ErrorCodeType* errorCode )
{
  UDS_ReturnType retVal = UDS_DIAG_JOB_FINISHED_OK;
#if( STDDIAG_USRPRECONDITIONCHECK == STD_ON )
  boolean skipOnboardData;
  StdDiag_App_ReturnType retValApp;
#endif /* STDDIAG_USRPRECONDITIONCHECK */

  /* MISRA-C:2004 Rule 14.2: Unused parameters */
  /* PRQA S 3112 2 */
  (void) (requestData);
  (void) (reqDataLength);

  /* Assume that response buffer is large enough to hold maximum number of preconditions */
  StdDiag_Assert_DevAssert((*resDataLength >= STDDIAG_MAX_NUMBER_PRECOND), STDDIAG_DEVERROR_CHECKPROGPRECOND_SIZE);

#if( STDDIAG_USRPRECONDITIONCHECK == STD_ON )
  /* consider availability of onboard communication, FL_195 */
  skipOnboardData = StdDiag_IsNDCDisabled();
  retValApp = StdDiag_App_CheckProgrammingPreconditions(skipOnboardData, resDataLength, StdDiag_ProgPrecondList);

  switch (retValApp) {
    case STDDIAG_APPL_OK:
      /* assume that reasonable number of preconditions have been set */
      StdDiag_Assert_DevAssert((*resDataLength < STDDIAG_MAX_NUMBER_PRECOND ), STDDIAG_DEVERROR_CHECKPROGPRECOND_SIZE);
    retVal = UDS_DIAG_JOB_FINISHED_OK;
    break;
  case STDDIAG_APPL_RUNNING:
    retVal = UDS_DIAG_JOB_RUNNING;
    break;
  case STDDIAG_APPL_E_NOT_OK:
  default:
    *errorCode = UDS_DIAG_E_CONDITIONSNOTCORRECT;
    retVal = UDS_DIAG_JOB_FINISHED_E_NOT_OK;
    break;
}
#else
*resDataLength = 0u;
#endif /* STDDIAG_USRPRECONDITIONCHECK */

  if (UDS_DIAG_JOB_FINISHED_OK == retVal)
  {
    /* check precondition PWF state, FL231 */
    if( !StdDiag_IsPWFPreconditionValid() )
    {
      StdDiag_ProgPrecondList[*resDataLength] = STDDIAG_PRECOND_PAD_NOT_ACTIVE;
      (*resDataLength)++;
    }
    memcpy(responseData, StdDiag_ProgPrecondList, *resDataLength);
  }
  return retVal;
}

#if( STDDIAG_USRPRECONDITIONCHECK == STD_ON )
/**
 * \brief This function is the callback for successful asynchronous precondition check
 *
 * \param[in] responseData holds a list of failed preconditions
 * \param[in] resDataLength holds the number of failed preconditions
 */
void StdDiag_CheckProgrammingPreconditions_Callback_ResultOk(uint8* responseData, size_t resDataLength) {
  StdDiag_Assert_DevAssert((resDataLength < STDDIAG_MAX_NUMBER_PRECOND), STDDIAG_DEVERROR_CHECKPROGPRECOND_SIZE);
  memcpy(StdDiag_ProgPrecondList, responseData, resDataLength);
  if( !StdDiag_IsPWFPreconditionValid() )
  {
    StdDiag_ProgPrecondList[resDataLength] = STDDIAG_PRECOND_PAD_NOT_ACTIVE;
    resDataLength++;
  }

  StdDiag_UDS_RoutineControlRawCheckProgrammingPreconditions_Start_ResultOk(StdDiag_ProgPrecondList, resDataLength);
}

/**
 * \brief This function is the callback for failed asynchronous precondition check
 *
 * \param[in] errorCode holds the error code of the failure
 */
void StdDiag_CheckProgrammingPreconditions_Callback_ResultError(UDS_ErrorCodeType errorCode) {
  StdDiag_UDS_RoutineControlRawCheckProgrammingPreconditions_Start_ResultError(errorCode);
}
#endif /* STDDIAG_USRPRECONDITIONCHECK */

/* PRQA S 5087 2 */
#define StdDiag_STOP_SEC_CODE
#include "StdDiag_MemMap.h"

