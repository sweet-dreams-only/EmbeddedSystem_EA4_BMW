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

/*------------------------------------------------------------------------------
                      MISRA-Deviations
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/

#include "Coding_TimerAdapter.h"
#include "CodingClassic_Cfg.h"
#include "Coding_Assert.h"
#include "Coding_MgmtAdapter.h"
#include "CodingClassic_Version.h"     /* Coding Classic Adapter Version */

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/**
 * \brief check version of the module
 */
#if (!CodingClassic_CHECK_VERSION(5, 2, 1))
#error "Version of Coding_TimerAdapter.c does not match the Classic adapter version!"
#endif

/**
 * \brief Definition of the number of distinctive timers.
 */
#define CODING_MAX_TIMER                           ((uint8)0x01u)

/*------------------------------------------------------------------------------
                      Local Variables
------------------------------------------------------------------------------*/

#define Coding_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Coding_MemMap.h" /* PRQA S 5087 */

static CallbackFunctionType Coding_TimerCallbackFunction = NULL_PTR;
static void* Coding_TimerContext = NULL_PTR;

#define Coding_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Coding_MemMap.h" /* PRQA S 5087 */

#define Coding_START_SEC_VAR_CLEARED_32
#include "Coding_MemMap.h" /* PRQA S 5087 */

static uint32 Coding_TimerQualificationTimer = 0u;
static uint32 Coding_TimerQualificationTimerStartValue = 0u;

#define Coding_STOP_SEC_VAR_CLEARED_32
#include "Coding_MemMap.h" /* PRQA S 5087 */


/*------------------------------------------------------------------------------
                      Global Functions
------------------------------------------------------------------------------*/

#define Coding_START_SEC_CODE
#include "Coding_MemMap.h" /* PRQA S 5087 */

/*----------------------------------------------------------------------------*/
/**
 * Called cyclically to provide a timer function.
 */
/*----------------------------------------------------------------------------*/
void Coding_TimerMain(void) {
  /* Check if bus communication is active */
  if (FALSE == Coding_BusComState()) {
    Coding_TimerQualificationTimer = Coding_TimerQualificationTimerStartValue;
    return;
  }

  if (0u < Coding_TimerQualificationTimer) {
    --Coding_TimerQualificationTimer;
    if (0u == Coding_TimerQualificationTimer) {
      Coding_TimerCallbackFunction(Coding_TimerContext);
    }
  }
}

/*----------------------------------------------------------------------------*/
/**
 * Service to set qualification timer.
 */
/*----------------------------------------------------------------------------*/
TimerHandleType Coding_Timer_SetTimer(uint32 timeout_ms, CallbackFunctionType timeoutHandler, void* context) {
  TimerHandleType handle = 0u;
  Coding_DevAssert(Coding_TimerQualificationTimer == 0u, CODING_DEVERROR_TIMERDPT);

  Coding_TimerCallbackFunction = timeoutHandler;
  Coding_TimerContext = context;

  Coding_TimerQualificationTimer = (timeout_ms * CODING_TIMER_FREQ) / 1000u;
  Coding_TimerQualificationTimerStartValue = Coding_TimerQualificationTimer;
  return (handle);
}

/*----------------------------------------------------------------------------*/
/**
 * Service to cancel qualification timer.
 */
/*----------------------------------------------------------------------------*/
void Coding_Timer_CancelTimer(TimerHandleType handle) {
  Coding_TimerQualificationTimer = 0u;
  Coding_TimerQualificationTimerStartValue = 0u;
  Coding_DevAssert(handle == 0u, CODING_DEVERROR_TIMERDPT);
}

#define Coding_STOP_SEC_CODE
#include "Coding_MemMap.h" /* PRQA S 5087 */
