/**
*  \file
*
*  \brief       BMW SWC SysTime
*
*  This file is the timer adapter header file of the generic part of the module SysTime
*  for usage in the BMW AUTOSAR Core.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     5.0.3
*
*/

#ifndef SYSTIME_TIMERADAPTER_H
#define SYSTIME_TIMERADAPTER_H

/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include "BUtil/PlatformTypes.h"
#include "BUtil/TimerTypes.h"
#include "SysTime_Version.h"

/*------------------------------------------------------------------------------
                      Macros
-------------------------------------------------------------------------------*/

/* check version of the module */
#if (!SysTime_CHECK_VERSION(5,0,3))
#error "Version of SysTime_TimerAdapter.h does not match the version of the module!"
#endif

#ifdef __cplusplus
extern "C" {
#endif
/*------------------------------------------------------------------------------
                      Extern Declarations
-------------------------------------------------------------------------------*/

/**
 * Calls the event every ms milliseconds until the timer is cleared.
 *
 * \return handle that can be used to clear the timer.
 *         If TIMER_HANDLE_TYPE_INVALID is returned, the timer could not be started
 */
extern TimerHandleType SysTime_Timer_SetCyclicTimer(uint32 ms, CallbackFunctionType event, void* context);

/**
 * Cancels the given timer.
 */
extern void SysTime_Timer_CancelTimer(TimerHandleType handle);


#ifdef __cplusplus
}
#endif

#endif /* SYSTIME_TIMERADAPTER_H */



