/**
*  \file
*
*  \brief       BMW SWC Darh Error Memory Adapter implementation
*
*  This file contains the implementation of the Error Memory Adapter
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
#include "DarhClassic_Version.h"
#include "Rte_Darh.h"
#include "Darh_ErrMemAdapter.h"

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/
#if (!DarhClassic_CHECK_VERSION(5, 1, 0))
#error "Version of Darh_ErrMemAdapter.c does not match the classic adapter version!"
#endif

/**
 * \brief Dem Argument "most recent freeze frame record number"
 */
#define DARH_MOST_RECENT_FREEZE_FRAME                                     0xFFU

/**
 * \brief Macro of systime id
 *
 * Identifier used to retrieve the freeze frame from Dem
 *
 * \remarks This macro depends on configuration parameter DarhSystimeDidIdentifier and DemDidIdentifier
 *
 */
#define DARH_SYSTIME_ID                                                   0x1701U

/*------------------------------------------------------------------------------
                      Global Functions
------------------------------------------------------------------------------*/

#define Darh_START_SEC_CODE
#include "Darh_MemMap.h"

/**
 * \brief Gets FreezeFrame Data of a specific EventId
 *
 * Returns the FreezeFrame TimeStamp information stored for a specific Event.
 *
 * \param[in] EventId index of the event
 *
 * \param[out] freezeFrame data contained in the TimeStamp freezeFrame
 *
 * \return ERRMEMSERVICE_OK if success ERRMEMSERVICE_NOT_OK if not
 *
 * \pre --
 *
 * \post --
 *
 * \remarks
 *
 */
ErrMemService_ResultType
Darh_ErrorManager_GetEventFreezeFrameData(ErrMemService_EventIdType EventId, uint8* freezeFrame) {
  Std_ReturnType retVal;
  ErrMemService_ResultType result = ERRMEMSERVICE_NOT_OK;

  retVal = Rte_Call_GeneralDiagnosticInfoPort_GetEventFreezeFrameData(
      EventId, DARH_MOST_RECENT_FREEZE_FRAME,
      FALSE, DARH_SYSTIME_ID, freezeFrame);

  if (retVal == RTE_E_OK) {
    result = ERRMEMSERVICE_OK;
  }

  return result;

} /* end of function Darh_ErrorManager_GetEventFreezeFrameData */


/**
 * \brief Gets the DTC of a specific Event
 *
 * Returns the DTC Value of the passed Event. If the indicated Event does not
 * refers to any DTC the value 0 is returned.
 *
 * \param[in] EventId index of the event
 *
 * returns uint32 containing the DTC value of the passed event or 0 if no DTC is found the event.
 *
 * \pre --
 *
 * \post --
 *
 * \remarks
 *
 */
uint32 Darh_ErrorManager_GetDTCOfEvent(ErrMemService_EventIdType eventId) {
  Std_ReturnType retVal;
  uint32 DTCOfEvent;

  retVal = Rte_Call_GeneralDiagnosticInfoPort_GetDTCOfEvent(eventId, DEM_DTC_FORMAT_UDS, &DTCOfEvent);

  if (retVal != RTE_E_OK) {
    DTCOfEvent = 0;
  }

  return DTCOfEvent;

} /* end of function Darh_ErrorManager_GetDTCOfEvent */


/**
* \brief Gets the DTC of the Darh Application DTC.
*
* Returns the DTC Value of the Darh Application Event.
*
* \param --
*
* returns uint32 containing the DTC value.
*
* \pre --
*
* \post --
*
* \remarks
*
*/
ErrMemService_UDSDTCType Darh_ErrorManager_ApplDtc_GetDTCOfEvent(void) {
  uint32 DTCOfEvent;

  (void) Rte_Call_ApplicationDTCInfoPort_GetDTCOfEvent(DEM_DTC_FORMAT_UDS, &DTCOfEvent);

  return DTCOfEvent;

} /* end of function Darh_ErrorManager_ApplDtc_GetDTCOfEvent */


/**
 * \brief Gets the DTC of the Darh Network DTC.
 *
 * Returns the DTC Value of the Darh Network Event.
 *
 * \param --
 *
 * returns uint32 containing the DTC value.
 *
 * \pre --
 *
 * \post --
 *
 * \remarks
 *
 */
ErrMemService_UDSDTCType Darh_ErrorManager_NetDtc_GetDTCOfEvent(void) {
  uint32 DTCOfEvent = 0x00;

  (void) Rte_Call_NetworkDTCInfoPort_GetDTCOfEvent(DEM_DTC_FORMAT_UDS, &DTCOfEvent);

  return DTCOfEvent;

} /* end of function Darh_ErrorManager_NetDtc_GetDTCOfEvent */


/**
 * \brief Sets the status of the Event of the Darh Application DTC.
 *
 * Sets the DTC of the Darh Application Event.
 *
 * \param[in] EventStatus indicates if the Event is passed or failed
 *
 * returns --
 *
 * \pre --
 *
 * \post --
 *
 * \remarks
 *
 */
void Darh_ErrorManager_ApplDtc_SetEventStatus(ErrMemService_EventStatusType EventStatus) {
  (void) Rte_Call_DmTestAppl_SetEventStatus(EventStatus);

} /* end of function Darh_ErrorManager_ApplDtc_SetEventStatus */


/**
 * \brief Sets the status of the Event of the Darh Network DTC.
 *
 * Sets the DTC of the Darh Network Event.
 *
 * \param[in] EventStatus indicates if the Event is passed or failed
 *
 * returns --
 *
 * \pre --
 *
 * \post --
 *
 * \remarks
 *
 */
void Darh_ErrorManager_NetDtc_SetEventStatus(ErrMemService_EventStatusType EventStatus) {
  (void) Rte_Call_DmTestCom_SetEventStatus(EventStatus);

} /* end of function Darh_ErrorManager_NetDtc_SetEventStatus */

#define Darh_STOP_SEC_CODE
#include "Darh_MemMap.h"
