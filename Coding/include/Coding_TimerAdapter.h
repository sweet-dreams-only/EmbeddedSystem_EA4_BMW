/**
 * \file
 *
 * \brief       Coding Timer Adapter
 *
 * \project     BMW Platform Software
 *
 * \copyright   BMW AG 2016 - 2017
 *
 * \version     5.2.1
 *
 */

#ifndef CODING_TIMER_H_
#define CODING_TIMER_H_

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/

#include "BUtil/PlatformTypes.h"     /* BMW Platform Types          */
#include "Coding.h"


/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/**
 * \brief check version of the module
 */
#if (!Coding_CHECK_VERSION(5, 2, 1))
#error "Version of Coding_TimerAdapter.h does not match the version of the module!"
#endif


/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

#define TIMER_HANDLE_TYPE_INVALID 0xFFu


/*------------------------------------------------------------------------------
                      Data Types
------------------------------------------------------------------------------*/

typedef uint8 TimerHandleType;

/* Coding Timer Callback Function Type */
typedef void (* CallbackFunctionType)(void* context);


/*------------------------------------------------------------------------------
                      Global Function Declarations
------------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif

#define Coding_START_SEC_CODE
#include "Coding_MemMap.h" /* PRQA S 5087 */

extern TimerHandleType Coding_Timer_SetTimer(uint32 timeout_ms, CallbackFunctionType timeoutHandler, void* context);

extern void Coding_Timer_CancelTimer(TimerHandleType handle);

#define Coding_STOP_SEC_CODE
#include "Coding_MemMap.h" /* PRQA S 5087 */

#ifdef __cplusplus
}
#endif

#endif /* CODING_TIMER_H_ */
