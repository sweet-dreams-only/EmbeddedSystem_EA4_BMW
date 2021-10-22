/**
*  \file
*
*  \brief       BMW SWC Darh
*
*  This file contains the implementation of the BMW SWC Darh
*  for usage in the BMW AUTOSAR Core and adaptive BMW AUTOSAR Core.
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
/**
 * The following requirement is almost the complete funcionality of
 * Darh. So there is no exact part of the code were it is implemented/placed.
 *
 * \lhref DMA_PA_5760
 */
/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/
#include "Darh.h"                       /* Own header file */
#include "Darh_Internal.h"

#include "Darh_Version.h"
#include "Darh_Cfg.h"
#include "Darh_AssertAdapter.h"
#include "Darh_ConcAdapter.h"
#include "Darh_ApplAdapter.h"

#include "string.h"                     /* use of memset */

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/
#if (!Darh_CHECK_VERSION(5, 1, 0))
#error "Version of Darh.c does not match the version of the module!"
#endif

/*------------------------------------------------------------------------------
                      Global Constants
------------------------------------------------------------------------------*/
#define Darh_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Darh_MemMap.h"

Darh_StateType Darh_State;

#define Darh_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Darh_MemMap.h"

#define Darh_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED
#include "Darh_MemMap.h"

Darh_ErrorQueueType Darh_ErrorQueue;

#define Darh_STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED
#include "Darh_MemMap.h"

#define Darh_START_SEC_VAR_SAVED_ZONE_BOOLEAN
#include "Darh_MemMap.h"

/**
 * \brief Indicates if the Diagnose Master transmission is enable or not.
 */
boolean Darh_DiagnoseMasterEnable;

#define Darh_STOP_SEC_VAR_SAVED_ZONE_BOOLEAN
#include "Darh_MemMap.h"


/*------------------------------------------------------------------------------
                      Global Functions
------------------------------------------------------------------------------*/
#define Darh_START_SEC_CODE
#include "Darh_MemMap.h"

extern void Darh_Init(void) {
  Darh_CritSect_Area0_Enter();

  /* transmission is per default not suspended */
  Darh_State.suspended = FALSE;

  /* Darh is now running */
  Darh_State.running = TRUE;

  Darh_CritSect_Area0_Exit();

} /* end of function Darh_Init */

extern void Darh_Shutdown(void) {
  /* Darh is stopped */
  Darh_State.running = FALSE;
} /* end of function Darh_Shutdown */

extern boolean Darh_SetRoeSuspended(boolean suspended) {
  boolean retVal = FALSE;

  if (TRUE == Darh_State.running) {
    Darh_State.suspended = suspended;
    retVal = TRUE;
  } else {
    Darh_Assert_DevAssert(FALSE, (DARH_INSTANCE_ID << 16) + (DARH_SID_SETROESUSPENDED << 8) + DARH_E_UNINIT);
  }

  return retVal;
} /* end of function Darh_SetRoeSuspended */

extern void Darh_EventDataChanged(ErrMemService_EventIdType EventId) {

  if (FALSE == Darh_State.running) {
    Darh_Assert_DevAssertReturnVoid(FALSE, (DARH_INSTANCE_ID << 16) + (DARH_SID_EVENTDATACHANGED << 8) + DARH_E_UNINIT);
  } else {
    uint16_least EvtIdx;
    boolean Darh_toReport = FALSE;
    boolean Darh_toSetRamBlockStatus = FALSE;

    Darh_toReport = Darh_Appl_CheckEventToBeReported(EventId);

    if (Darh_toReport == TRUE) {
      ErrMemService_TimestampFreezeFrameType freezeFrameData;

      if (ERRMEMSERVICE_OK != Darh_ErrorManager_GetEventFreezeFrameData(EventId, freezeFrameData)) {
        /* if not freezeFrame data is found we set the freezframe to default */
        (void) memset(freezeFrameData, 0xFF, sizeof(freezeFrameData));
      }

      Darh_CritSect_Area0_Enter();

      /** \lhref DMA_PA_8584 */
      /* check Diagnose Master transmission state and queue overflow */
      if ((Darh_DiagnoseMasterEnable) && (FALSE == Darh_State.suspended) &&
          (DARH_QUEUE_SIZE > Darh_ErrorQueue.size)) {
        /* insert last queue element */
        EvtIdx = ((uint16_least) Darh_ErrorQueue.first
                  + (uint16_least) Darh_ErrorQueue.size
                 ) % DARH_QUEUE_SIZE;
        Darh_ErrorQueue.queue[EvtIdx].EventId = EventId;
        Darh_ErrorQueue.queue[EvtIdx].timestamp =
            ((uint32) freezeFrameData[0U]) << 24U;
        Darh_ErrorQueue.queue[EvtIdx].timestamp +=
            ((uint32) freezeFrameData[1U]) << 16U;
        Darh_ErrorQueue.queue[EvtIdx].timestamp +=
            ((uint32) freezeFrameData[2U]) << 8U;
        Darh_ErrorQueue.queue[EvtIdx].timestamp +=
            (uint32) freezeFrameData[3U];
        Darh_ErrorQueue.size++;
        /* PRQA L:DARH_EVENTDATACHANGED_BRANCH */

        Darh_toSetRamBlockStatus = TRUE;
      }

      Darh_CritSect_Area0_Exit();

      if (Darh_toSetRamBlockStatus == TRUE) {
        /* !LINKSTO DARH_176,1 */
        Darh_NvM_WriteOnShutdownBlock(&Darh_ErrorQueue);
      }
    }
  }
} /* end of function Darh_EventDataChanged */

extern boolean Darh_GetRoeState(boolean* DiagnoseMasterEnable) {
  boolean retVal = FALSE;

  Darh_CritSect_Area0_Enter();

  if (Darh_State.running) {
    *DiagnoseMasterEnable = Darh_DiagnoseMasterEnable;
    retVal = TRUE;
  }

  Darh_CritSect_Area0_Exit();

  return retVal;
} /* end of function Darh_GetRoeState */

#define Darh_STOP_SEC_CODE
#include "Darh_MemMap.h"
