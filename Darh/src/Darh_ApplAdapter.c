/**
*  \file
*
*  \brief       BMW SWC Darh Application Adapter implementation
*
*  This file contains the implementation of the Darh Application Adapter.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2017
*
*  \version     5.1.0
*
*/
/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/
#include "Rte_Darh.h"

#include "Darh.h"
#include "DarhClassic_Version.h"
#include "Darh_Cfg.h"
#include "DarhClassic_Cfg.h"
#include "Darh_ApplAdapter.h"
#include "Darh_QueueHandler.h"

#include <string.h>

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/
#if (!DarhClassic_CHECK_VERSION(5, 1, 0))
#error "Version of Darh_ApplAdapter.c does not match the classic adapter version!"
#endif

/*------------------------------------------------------------------------------
                      Local Variables
------------------------------------------------------------------------------*/

#if (DARH_ACTIVE_REPORT_LIST_TYPE != DARH_REPORT_DYNAMICALLY)

#define Darh_START_SEC_CONST_UNSPECIFIED
#include "Darh_MemMap.h"

/**
 * \brief Contains the IDs of the actively reported events
 */
static CONST( Dem_EventIdType, Darh_CONST )
    Darh_ActiveReportedEvents[DARH_ACTIVE_REPORTED_EVENTS_NUMBER] =
    {
        DARH_ACTIVE_REPORTED_EVENTS
    };

#define Darh_STOP_SEC_CONST_UNSPECIFIED
#include "Darh_MemMap.h"

#endif

/*------------------------------------------------------------------------------
                      Global Functions
------------------------------------------------------------------------------*/

#define Darh_START_SEC_CODE
#include "Darh_MemMap.h"

extern boolean Darh_Appl_CheckEventToBeReported(ErrMemService_EventIdType EventId) {
#if (DARH_ACTIVE_REPORT_LIST_TYPE != DARH_REPORT_DYNAMICALLY)
  uint16 EvtIdx;
#endif
  boolean retVal;

#if (DARH_ACTIVE_REPORT_LIST_TYPE == DARH_REPORT_POSITIVE_LIST)
  retVal = FALSE;
#endif

  /* search for configured actively reported event */
#if (DARH_ACTIVE_REPORT_LIST_TYPE != DARH_REPORT_DYNAMICALLY)
  for(EvtIdx = 0U; EvtIdx < DARH_ACTIVE_REPORTED_EVENTS_NUMBER; EvtIdx++ ) {
    if ( Darh_ActiveReportedEvents[EvtIdx] == EventId ) {
#if (DARH_ACTIVE_REPORT_LIST_TYPE == DARH_REPORT_POSITIVE_LIST)
      retVal = TRUE;
#endif
      break;
    }
  }
#else
  (void) Rte_Call_ReportDynamicallyEventPort_EventToReport(EventId, &retVal);
#endif

  return retVal;
} /* end of function Darh_Appl_CheckEventToBeReported */


extern uint16 Darh_Appl_CountOfEventsToBeReported(void) {
  uint16 eventsCount = 0;

#if (DARH_ACTIVE_REPORT_LIST_TYPE != DARH_REPORT_DYNAMICALLY)
  eventsCount = DARH_ACTIVE_REPORTED_EVENTS_NUMBER;
#else
  (void) Rte_Call_ReportDynamicallyEventPort_EventToReportCount(&eventsCount);
#endif

  return eventsCount;

} /* end of function Darh_Appl_CountOfEventsToBeReported */

extern ErrMemService_EventIdType Darh_Appl_GetEventId(uint16 EventIdx) {
  Dem_EventIdType retVal;

#if (DARH_ACTIVE_REPORT_LIST_TYPE != DARH_REPORT_DYNAMICALLY)
  retVal = Darh_ActiveReportedEvents[EventIdx];
#else
  (void) Rte_Call_ReportDynamicallyEventPort_EventIdx2EventId(EventIdx, &retVal);
#endif

  return (ErrMemService_EventIdType)retVal;
}

extern boolean Darh_Appl_Transmit2DiagnoseMaster(uint16 length, const uint8* data) {
  Darh_TransmissionArrayType data2Transmit;
  boolean retVal = FALSE;

  data2Transmit.size = length;
  memcpy(data2Transmit.payload, data, length);

  if (Rte_Write_Com_data(&data2Transmit) == E_OK) {
    retVal = TRUE;
  }

  return retVal;
}

extern void Darh_ErrorQueueHandler(void) {
  Darh_QueueHandler();
}

Std_ReturnType Darh_ReadRoeStateDataHandler(uint8* Data) {
  Std_ReturnType retVal = E_NOT_OK;
  boolean diagnoseMasterState;
  if (TRUE == Darh_GetRoeState(&diagnoseMasterState)) {
    *Data = (uint8) diagnoseMasterState;
    retVal = E_OK;
  }

  return retVal;
}


/**
 * \brief Description of function Darh_SetRoeSuspendedHandler
 *
 * Controls the current DARH ROE state.
 *
 * \global --
 *
 * \param[in] suspended TRUE - ROE is suspended
 *                      FALSE - ROE is un-suspended
 *
 * \return Std_ReturnType
 * \retval E_OK
 * \retval E_NOT_OK
 *
 * \pre --
 *
 * \post --
 *
 * \remarks --
 *
 */
FUNC(Std_ReturnType, Darh_CODE) Darh_SetRoeSuspendedHandler(boolean suspended)
{
  Std_ReturnType retVal = E_NOT_OK;
  boolean retValGeneric;

  retValGeneric = Darh_SetRoeSuspended(suspended);

  if (TRUE == retValGeneric) {
    retVal = E_OK;
  }

  return retVal;
}

#define Darh_STOP_SEC_CODE
#include "Darh_MemMap.h"
