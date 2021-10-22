/**
*  \file
*
*  \brief       BMW SWC StdDiag generic
*
*  This file contains the life cycle implementation of the module StdDiag
*  for usage in BMW Platform Software.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2017
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
#include "StdDiag_Version.h"
#include "StdDiag.h"
#include "StdDiag_Internal.h"
#include "StdDiag_ProgPreparation.h"
#include "StdDiag_AssertAdapter.h"


/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!StdDiag_CHECK_VERSION(5,3,0))
#error "Version of StdDiag.c does not match the version of the module!"
#endif


/*------------------------------------------------------------------------------
                      Global Variables
------------------------------------------------------------------------------*/
/* PRQA S 5087 2 */
#define StdDiag_START_SEC_VAR_INIT_BOOLEAN
#include "StdDiag_MemMap.h"

/**
 * \brief StdDiag_currentInitState holds the initialization state
 *        (initialization is necessary to provide defined value even before module initialization)
 */
static boolean StdDiag_currentInitState = FALSE;

/* PRQA S 5087 2 */
#define StdDiag_STOP_SEC_VAR_INIT_BOOLEAN
#include "StdDiag_MemMap.h"

/*------------------------------------------------------------------------------
                      Global Functions
-------------------------------------------------------------------------------*/
/* PRQA S 5087 2 */
#define StdDiag_START_SEC_CODE
#include "StdDiag_MemMap.h"

/**
 * \brief Module Initialization
 *
 * Initialization function of generic part of module StdDiag
 *
 * \global_r  StdDiag_currentInitState
 *
 */
void StdDiag_Init(void)
{
  UDS_SessionType currentActiveSession;

  /* get current active session from the DCM */
  currentActiveSession = StdDiag_UDS_GetActiveSession();

  StdDiag_Assert_DevAssert(currentActiveSession == UDS_DIAG_DEFAULT_SESSION, STDDIAG_DEVERROR_LIFECYCLE_ERROR);

  if( currentActiveSession == UDS_DIAG_DEFAULT_SESSION )
  {
    StdDiag_StateMachineInit();

    /* set current initialization state */
    StdDiag_currentInitState = TRUE;
  }

}

/**
 * \brief Module Deactivation
 *
 * Deactivation function of generic part of module StdDiag
 *
 * \global_r  StdDiag_currentInitState
 *
 */
void StdDiag_Stop(void)
{
  /* reset initialization flag */
  StdDiag_currentInitState = FALSE;

  StdDiag_StateMachineStop();
}

/**
 * \brief Check Initialization state
 *
 * Internal check function of initialization state
 *
 * \global_r  StdDiag_currentInitState
 *
 * \retval TRUE StdDiag is initialized
 * \retval FALSE StdDiag is not initialized
 *
 */
boolean StdDiag_IsInitialized(void)
{
  return StdDiag_currentInitState;
}

/* PRQA S 5087 2 */
#define StdDiag_STOP_SEC_CODE
#include "StdDiag_MemMap.h"

