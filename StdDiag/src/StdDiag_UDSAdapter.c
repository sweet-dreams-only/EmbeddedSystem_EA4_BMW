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

#include "StdDiag_UDSAdapter.h"
#include "StdDiagClassic_Version.h"
#include "StdDiag_AssertAdapter.h"
#include "Rte_StdDiag.h"

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!StdDiagClassic_CHECK_VERSION(5,4,0))
#error "Version of StdDiag_UDSAdapter.c does not match the adapter or generic version!"
#endif

/*------------------------------------------------------------------------------
                      Global Functions
-------------------------------------------------------------------------------*/
/* PRQA S 5087 2 */
#define StdDiag_START_SEC_CODE
#include "StdDiag_MemMap.h"

UDS_SessionType StdDiag_UDS_GetActiveSession( void )
{
    Std_ReturnType retVal;
    Dcm_SesCtrlType activeSession = UDS_DIAG_INVALID_SESSION;

    /* get current active session from the DCM */
    retVal = Rte_Call_DCMServicesPort_GetSesCtrlType(&activeSession);

    StdDiag_Assert_DevAssert((retVal == E_OK), STDDIAG_DEVERROR_DCM_SESSION_NOT_AVAILABLE);

    return (UDS_SessionType) activeSession;
}

/* PRQA S 5087 2 */
#define StdDiag_STOP_SEC_CODE
#include "StdDiag_MemMap.h"


