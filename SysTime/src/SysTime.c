/**
*  \file
*
*  \brief       BMW SWC SysTime generic
*
*  This file contains the implementation of the module SysTime
*  for usage in the BMW AUTOSAR Core.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     5.0.3
*
*  \remarks     The System Time Client module receives the System Time,
*               which is sent by the System Time Master, and provides the
*               received System Time to other modules on the ECU.
*
*/

/*------------------------------------------------------------------------------
                      MISRA-Deviations
------------------------------------------------------------------------------*/
/*
   MISRA-C:2004 Rule 19.1: including SysTime_MemMap.h is necessary throughout
   the file according to memory abstraction. See PRQA 5087.
*/


/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/
#include "BUtil/PlatformTypes.h"
#include "SysTime_Version.h"
#include "SysTime.h"
#include "SysTime_Cfg.h"
#include "SysTime_TimerAdapter.h"
#include "SysTime_ConcAdapter.h"
#include "SysTime_AssertAdapter.h"
#include <stddef.h>

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!SysTime_CHECK_VERSION(5,0,3))
#error "Version of SysTime.c does not match the version of the module!"
#endif


/**
 * \brief initial system time value
 */
#define SYSTIME_INITIAL_TIMERVALUE                   0x00000000u

/**
 * \brief system time value in case of an error
 */
#define SYSTIME_ERROR_TIMERVALUE                     0xFFFFFFFFu

/**
 * \brief threshold value in milliseconds to increment system time
 *
 * \lhref DMA_PA_8471
 */
#define SYSTIME_INCREMENT_THRESHOLD                  1000u

/*------------------------------------------------------------------------------
                      Local Data Types
------------------------------------------------------------------------------*/

/**
 * \brief internal states of the SysTime state machine
 */
typedef enum
{
  SYSTIME_INVALID    = 0x00,
  SYSTIME_WAIT_FIRST = 0x01,
  SYSTIME_ERROR      = 0x02,
  SYSTIME_OK         = 0x03
}SysTime_StateType;

/*------------------------------------------------------------------------------
                      Local Variables
------------------------------------------------------------------------------*/

/* PRQA S 5087 2 */
#define SysTime_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "SysTime_MemMap.h"

/**
 * \brief  SysTime_State holds the current state of the state machine
 */
static SysTime_StateType SysTime_State;

static TimerHandleType SysTime_CyclicTimerHandle;

/* PRQA S 5087 2 */
#define SysTime_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "SysTime_MemMap.h"

/* PRQA S 5087 2 */
#define SysTime_START_SEC_VAR_INIT_32
#include "SysTime_MemMap.h"

/**
 * \brief  SysTime_CurrentTime holds the current system time
 *         (initialization with default value is necessary to provide a defined
 *          system time even before module initialization)
 */
static uint32 SysTime_CurrentTime = SYSTIME_INITIAL_TIMERVALUE;

/* PRQA S 5087 2 */
#define SysTime_STOP_SEC_VAR_INIT_32
#include "SysTime_MemMap.h"

/* PRQA S 5087 2 */
#define SysTime_START_SEC_VAR_NO_INIT_32
#include "SysTime_MemMap.h"

/**
 * \brief  SysTime_InternalTimer is used to count the cycle time of the main function
 */
static uint32 SysTime_InternalTimer;

/* PRQA S 5087 2 */
#define SysTime_STOP_SEC_VAR_NO_INIT_32
#include "SysTime_MemMap.h"

/*------------------------------------------------------------------------------
                      Local Functions Prototypes
------------------------------------------------------------------------------*/
/* PRQA S 5087 2 */
#define SysTime_START_SEC_CODE
#include "SysTime_MemMap.h"

static void SysTime_UpdateSystemTime(uint32 newSystemTime);

/*------------------------------------------------------------------------------
                      Local Functions
------------------------------------------------------------------------------*/

/**
 * \brief sets the current system time
 *
 * This function updates the current system time
 *
 * \global_w  SysTime_CurrentTime, SysTime_InternalTimer
 *
 * \param[in]  newTime time value to be set as current system time
 *
 */
static void SysTime_UpdateSystemTime(uint32 newSystemTime)
{
  /* update the current system time and reset the internal counter */
  SysTime_CritSect_SystemTime_Enter();
  SysTime_CurrentTime = newSystemTime;
  SysTime_InternalTimer = 0u;
  SysTime_CritSect_SystemTime_Exit();
}

/*------------------------------------------------------------------------------
                      Global Functions
------------------------------------------------------------------------------*/

/**
 * \brief Start SysTime functionality
 *
 * This function starts the SysTime functionality
 *
 * \global_w SysTime_State, SysTime_CurrentTime, SysTime_InternalTimer, SysTime_CyclicTimerHandle
 *
 *  \lhref DMA_PA_8451, DMA_PA_8460
 *
 */
boolean SysTime_Run(void)
{
  boolean retVal = FALSE;

  if( SYSTIME_INVALID == SysTime_State ) {
    /* Initialize timer and state machine */
    SysTime_CurrentTime = SYSTIME_INITIAL_TIMERVALUE;
    SysTime_InternalTimer = 0u;

    /* Start cyclic timer */
    SysTime_CyclicTimerHandle = SysTime_Timer_SetCyclicTimer(SYSTIME_MAINTASKCYCLE, &SysTime_CyclicTrigger, NULL);

    if (TIMER_HANDLE_TYPE_INVALID != SysTime_CyclicTimerHandle) {
      SysTime_State = SYSTIME_WAIT_FIRST;
      retVal = TRUE;
    }
  }

  SysTime_Assert_DevAssert((TRUE == retVal), SYSTIME_DEVERROR_INITIALIZATION);

  return retVal;
}

/**
 * \brief Stop SysTime functionality
 *
 * This function stops the SysTime functionality
 *
 * \global_w SysTime_State, SysTime_CurrentTime, SysTime_InternalTimer
 * \global_r SysTime_CyclicTimerHandle
 *
 */
void SysTime_Stop(void)
{
  /* Stop cyclic timer */
  SysTime_Timer_CancelTimer(SysTime_CyclicTimerHandle);

  /* Set current System Time to zero when deactivating SysTime functionality */
  SysTime_CurrentTime = SYSTIME_INITIAL_TIMERVALUE;
  SysTime_State = SYSTIME_INVALID;
  SysTime_InternalTimer = 0u;
}

/**
 * \brief get current system time for diagnostics
 *
 * writes the current system time to a given buffer
 *
 * \global_r SysTime_CurrentTime
 *
 * \param[out] Data pointer to the buffer, where the current
 *                  system time will be stored.
 *
 * \retval UDS_DIAG_JOB_FINISHED_OK read operation was successful
 *
 * \lhref DMA_PA_8552, DMA_PA_8550, DMA_PA_8551, DK_T3_452, DK_T3_453
 *
 */
/*
   MISRA-C:2004 Rule 16.7: Parameter errorCode could be const, but API signature is defined
   by generic interface definition
*/
/* PRQA S 3673 1 */
UDS_ReturnType SysTime_ReadDataSystemTime (uint32* currentTime, UDS_ErrorCodeType* errorCode)
{
  (void) errorCode;

  /* copy system time to given buffer */
  SysTime_CritSect_SystemTime_Enter();
  *currentTime = SysTime_CurrentTime;
  SysTime_CritSect_SystemTime_Exit();

  return UDS_DIAG_JOB_FINISHED_OK;
}

/**
 * \brief receive new signal
 *
 * This function is called, when a new system time signal
 * has been received.
 *
 * \global_rw SysTime_State
 *
 * \lhref DMA_PA_8451, DMA_PA_8460
 *
 */
void SysTime_ReceiveSystemTime(uint32 newSystemTime)
{
  SysTime_StateType nextState = SysTime_State;

  switch( SysTime_State )
  {
    case SYSTIME_WAIT_FIRST:
      if( newSystemTime == SYSTIME_ERROR_TIMERVALUE )
      {
        /* the first message we received after startup is 0xFFFFFFFF */
        nextState = SYSTIME_ERROR;
      }
      else
      {
        nextState = SYSTIME_OK;
      }
      SysTime_UpdateSystemTime(newSystemTime);
      break;

    case SYSTIME_ERROR:
      /* no break */
    case SYSTIME_OK:
      if( newSystemTime != SYSTIME_ERROR_TIMERVALUE )
      {
        /* we received a valid signal */
        nextState = SYSTIME_OK;
        SysTime_UpdateSystemTime(newSystemTime);
      }
      break;

    default:
      break;
  }

  /* set the next state of the state machine */
  SysTime_State = nextState;
}

/**
 * \brief cyclic main function
 *
 * This function implements the state machine of the system
 * time client, and shall be called cyclically with a cycle
 * rate of SYSTIME_MAINTASKCYCLE.
 *
 * \global_r  SysTime_State
 * \global_w  SysTime_CurrentTime
 * \global_rw SysTime_InternalTimer
 *
 * \lhref DMA_PA_8451, DMA_PA_8460
 */
/*
   MISRA-C:2004 Rule 16.7: Parameter context could be const, but API signature is defined
   by generic interface definition
*/
/* PRQA S 3673 1 */
void SysTime_CyclicTrigger(void* context)
{
  (void) context;

  switch( SysTime_State )
  {
    case SYSTIME_OK:
      SysTime_InternalTimer += SYSTIME_MAINTASKCYCLE;

      /* the system time is only incremented in state SYSTIME_OK */
      /* increment system time, if threshold value expired */
      if( SysTime_InternalTimer >= SYSTIME_INCREMENT_THRESHOLD )
      {
        SysTime_CritSect_SystemTime_Enter();
        SysTime_CurrentTime++;
        SysTime_InternalTimer = 0u;
        SysTime_CritSect_SystemTime_Exit();
      }
      break;

    case SYSTIME_WAIT_FIRST:
      SysTime_InternalTimer += SYSTIME_MAINTASKCYCLE;

      /* set system time to error value, if initial timeout expired */
      if( SysTime_InternalTimer >= SYSTIME_INITIALTIMEOUT )
      {
        SysTime_State = SYSTIME_ERROR;
        SysTime_UpdateSystemTime(SYSTIME_ERROR_TIMERVALUE);
      }
      break;

    default:
      break;
  }
}


/* PRQA S 5087 2 */
#define SysTime_STOP_SEC_CODE
#include "SysTime_MemMap.h"

/*--- End of file ------------------------------------------------------------*/
