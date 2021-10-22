/**
*  \file
*
*  \brief       BMW SWC Darh Queue Handler
*
*  This file contains the implementation of the Darh Queue Handler
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015
*
*  \version     5.1.0
*
*  \remarks     --
*
*/
/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/
#include "Darh_QueueHandler.h"                       /* Own header file */
#include "Darh.h"
#include "Darh_ConcAdapter.h"
#include "Darh_NvMAdapter.h"
#include "Darh_AssertAdapter.h"
#include "Darh_ApplAdapter.h"
#include <stddef.h>

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/
#if (!Darh_CHECK_VERSION(5, 1, 0))
#error "Version of Darh_QueueHandler.c does not match the version of the module!"
#endif

/** \brief Count of bytes needed for each DTC and TimeStamp */
#define DARH_BYTES_PER_DTC_AND_TIMESTAMP 7u

/*------------------------------------------------------------------------------
                      Local Variables
------------------------------------------------------------------------------*/
#define Darh_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Darh_MemMap.h"

/**
 * \brief Buffer to store the data to be transmitted
 */
static unsigned char Buffer[DARH_BYTES_PER_DTC_AND_TIMESTAMP];

#define Darh_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Darh_MemMap.h"

/*------------------------------------------------------------------------------
                      Global Functions
------------------------------------------------------------------------------*/
#define Darh_START_SEC_CODE
#include "Darh_MemMap.h"

extern void Darh_QueueHandler(void) {
  boolean ContinueExecution = TRUE;
  boolean retVal;

  Darh_CritSect_Area0_Enter();

  if (Darh_State.running) {
    /* continue if queue is not empty and transmission started */
    if ((!Darh_DiagnoseMasterEnable) || (TRUE == Darh_State.suspended) || (0U == Darh_ErrorQueue.size)) {
      ContinueExecution = FALSE;
    }

    if (TRUE == ContinueExecution) {
      uint32 Timestamp = 0U;
      uint32 DTCOfEvent;
      ErrMemService_EventIdType EventId = 0;

      /* retrieve first queue element */
      EventId = Darh_ErrorQueue.queue[Darh_ErrorQueue.first].EventId;
      Timestamp = Darh_ErrorQueue.queue[Darh_ErrorQueue.first].timestamp;

      Darh_CritSect_Area0_Exit();

      DTCOfEvent = Darh_ErrorManager_GetDTCOfEvent(EventId);

      /** \lhref DMA_PA_4773 */
      /* PRQA S 5200 DARH_READERRORQUEUE_TAG_3 *//* Violation of metric STMIF.
                              Reason: Effected by module design. */
      /* Deviation MISRA-2 <+3> */ /* PRQA S 0491 DARH_READERRORQUEUE_TAG_4 */
      Buffer[0] = (uint8) (DTCOfEvent >> 16U);
      Buffer[1U] = (uint8) (DTCOfEvent >> 8U);
      Buffer[2U] = (uint8) DTCOfEvent;
      /* PRQA L:DARH_READERRORQUEUE_TAG_4 */

      /* PRQA L:DARH_READERRORQUEUE_TAG_3 */

      /* Deviation MISRA-2 <+4> */ /* PRQA S 0491 DARH_READERRORQUEUE_TAG_5 */
      Buffer[3U] = (uint8) (Timestamp >> 24U);
      Buffer[4U] = (uint8) (Timestamp >> 16U);
      Buffer[5U] = (uint8) (Timestamp >> 8U);
      Buffer[6U] = (uint8) Timestamp;
      /* PRQA L:DARH_READERRORQUEUE_TAG_5 */

      /* start the transmission */
      retVal = Darh_Appl_Transmit2DiagnoseMaster(DARH_BYTES_PER_DTC_AND_TIMESTAMP, Buffer);

      if (TRUE == retVal) {
        /* remove entries from the buffer */
        Darh_CritSect_Area0_Enter();

        /* update queue size and index to the first element */
        Darh_ErrorQueue.first++;
        if (Darh_ErrorQueue.first >= DARH_QUEUE_SIZE) {
          Darh_ErrorQueue.first = 0;
        }
        Darh_ErrorQueue.size--;

        Darh_CritSect_Area0_Exit();

        Darh_NvM_WriteOnShutdownBlock(&Darh_ErrorQueue);
      }
    } else {
      Darh_CritSect_Area0_Exit();
    }
  } else {
    Darh_CritSect_Area0_Exit();
  }
} /* end of function Darh_QueueHandler */

#define Darh_STOP_SEC_CODE
#include "Darh_MemMap.h"
