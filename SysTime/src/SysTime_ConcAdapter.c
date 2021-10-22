/**
*  \file
*
*  \brief       BMW SWC SysTime Adapter
*
*  This file contains the implementation of the SysTime Concurrency adapter
*  for usage in the classic BMW AUTOSAR Core.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2017
*
*  \version     5.0.3
*
*/

/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/
#include "SysTimeClassic_Version.h"
#include "SysTime_ConcAdapter.h"
#include "Rte_SysTime.h"


/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!SysTimeClassic_CHECK_VERSION(5,0,3))
#error "Version of SysTime_ConcAdapter.c does not match the adapter version!"
#endif

/*------------------------------------------------------------------------------
                      Global Functions
-------------------------------------------------------------------------------*/

void SysTime_CritSect_SystemTime_Enter(void) {
  Rte_Enter_SysTimeGetTimeArea();
}

void SysTime_CritSect_SystemTime_Exit(void) {
  Rte_Exit_SysTimeGetTimeArea();
}

