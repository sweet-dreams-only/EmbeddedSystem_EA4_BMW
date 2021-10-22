/**
*  \file
*
*  \brief       BMW SWC StdDiag Adapter
*
*  This file contains the implementation of the StdDiag Error Memory adapter
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
#include "StdDiag_ErrMemAdapter.h"
#include "StdDiag_AssertAdapter.h"
#include "StdDiagClassic_Version.h"
#include "Rte_StdDiag.h"


/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!StdDiagClassic_CHECK_VERSION(5,4,0))
#error "Version of StdDiag_ErrMemAdapter.c does not match the adapter version!"
#endif

/*------------------------------------------------------------------------------
                      Global Functions
-------------------------------------------------------------------------------*/

ErrMem_ResultType StdDiag_ErrMem_LockErrorMemory(void)
{
  Std_ReturnType result;

  result = Rte_Call_EnableConditionPort_SetEnableCondition( FALSE );

  StdDiag_Assert_DevAssert((E_OK == result), STDDIAG_DEVERROR_LOCK_ERROR_MEMORY_FAILED);

  return ERRMEM_OK;
}

ErrMem_ResultType StdDiag_ErrMem_UnlockErrorMemory(void)
{
  Std_ReturnType result;

  result = Rte_Call_EnableConditionPort_SetEnableCondition( TRUE );

  StdDiag_Assert_DevAssert((E_OK == result), STDDIAG_DEVERROR_UNLOCK_ERROR_MEMORY_FAILED);

  return ERRMEM_OK;
}


