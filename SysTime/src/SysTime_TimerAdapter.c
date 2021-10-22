/**
*  \file
*
*  \brief       BMW SWC SysTime Adapter
*
*  This file contains the implementation of the SysTime Timer adapter
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
#include "SysTime_TimerAdapter.h"


/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!SysTimeClassic_CHECK_VERSION(5,0,3))
#error "Version of SysTime_TimerAdapter.c does not match the adapter version!"
#endif

/*------------------------------------------------------------------------------
                      Global Functions
-------------------------------------------------------------------------------*/

/*
   MISRA-C:2004 Rule 16.7: Parameter context could be const, but API signature is defined
   by generic interface definition
*/
/* PRQA S 3673 1 */
TimerHandleType SysTime_Timer_SetCyclicTimer(uint32 ms, CallbackFunctionType event, void* context) {
  (void) ms;
  (void) event;
  (void) context;

  /* return arbitrary value, cyclic timing is done via Timing-Event */
  return 0x00u;
}

void SysTime_Timer_CancelTimer(TimerHandleType handle) {
  (void) handle;
}


