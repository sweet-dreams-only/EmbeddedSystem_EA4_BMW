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
*  \version     5.4.0
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

#include "StdDiag_DarhAdapter.h"
#include "StdDiag_AssertAdapter.h"
#include "StdDiagClassic_Version.h"
#include "Rte_StdDiag.h"

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!StdDiagClassic_CHECK_VERSION(5,4,0))
#error "Version of StdDiag_DarhAdapter.c does not match the adapter or generic version!"
#endif

/*------------------------------------------------------------------------------
                      Global Functions
-------------------------------------------------------------------------------*/
/* PRQA S 5087 2 */
#define StdDiag_START_SEC_CODE
#include "StdDiag_MemMap.h"

uint8 StdDiag_Darh_GetRoeState( void )
{
  Std_ReturnType retVal;
  Darh_RoeStateType currentRoeState;
  uint8 currentRoeStateValue = 0;

  retVal = Rte_Call_RoeStatePort_GetRoeState(&currentRoeState);
  StdDiag_Assert_DevAssert((E_OK == retVal), STDDIAG_DEVERROR_ROESTATE_NOT_AVAILABLE);

  if ((E_OK == retVal) && (DARH_ROE_STARTED == currentRoeState))
  {
    currentRoeStateValue = 0x01u;
  }

  return currentRoeStateValue;
}

/* PRQA S 5087 2 */
#define StdDiag_STOP_SEC_CODE
#include "StdDiag_MemMap.h"


