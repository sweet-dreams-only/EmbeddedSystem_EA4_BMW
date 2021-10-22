/**
*  \file
*
*  \brief       BMW SWC Darh Read Actively Reporte DTCs
*
*  This file contains the implementation DID handler to read the DTCs which
*  are reported to the Diagnose Master.
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
#include <Darh.h>
#include "BUtil/PlatformTypes.h"
#include "Darh.h"                       /* Own header file */
#include "Darh_AssertAdapter.h"
#include "Darh_ApplAdapter.h"
#include "Darh_ConcAdapter.h"
#include "Darh_ReadActivelyReportedDTCs.h"

#include "Darh_ErrMemAdapter.h"

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/
#if (!Darh_CHECK_VERSION(5, 1, 0))
#error "Version of Darh_ReadActivelyReportedDTCs.c does not match the version of the module!"
#endif

/*------------------------------------------------------------------------------
                      Global Functions
------------------------------------------------------------------------------*/
#define Darh_START_SEC_CODE
#include "Darh_MemMap.h"

extern boolean Darh_ReadActivelyReportedDtc_Length(uint16* DataLength) {
  boolean retVal = FALSE;
  uint16 Darh_eventCount;

  if (Darh_State.running) {
    Darh_eventCount = Darh_Appl_CountOfEventsToBeReported();

    *DataLength = Darh_eventCount * 3U;
    retVal = TRUE;
  }

  return retVal;
} /* end of function Darh_ReadActivelyReportedDtc_Length */

extern boolean Darh_ReadActivelyReportedDtc_Data(uint8* Data) {
  boolean retVal = FALSE;
  uint16_least EvtIdx;
  uint16_least DstEvtIdx = 0;

  if (Darh_State.running) {
    for (EvtIdx = 0U; EvtIdx < Darh_Appl_CountOfEventsToBeReported(); EvtIdx++) {
      uint32 DTCOfEvent;

      if (Darh_Appl_CheckEventToBeReported(EvtIdx + 1U)) {

        DTCOfEvent = Darh_ErrorManager_GetDTCOfEvent(Darh_Appl_GetEventId(EvtIdx));

        Data[DstEvtIdx * 3U] = (uint8) (DTCOfEvent >> 16U);
        Data[(DstEvtIdx * 3U) + 1U] = (uint8) (DTCOfEvent >> 8U);
        Data[(DstEvtIdx * 3U) + 2U] = (uint8) DTCOfEvent;
        DstEvtIdx++;
      }
    }
    retVal = TRUE;
  }

  return retVal;

} /* end of function Darh_ReadActivelyReportedDtc_Data */

#define Darh_STOP_SEC_CODE
#include "Darh_MemMap.h"
