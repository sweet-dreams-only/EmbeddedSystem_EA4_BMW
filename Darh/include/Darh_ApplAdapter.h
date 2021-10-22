/**
*  \file
*
*  \brief       Darh Application adapter
*
*  Application adapter for Darh Module.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2016
*
*  \version     5.1.0
*
*  \remarks     -
*
*/
#ifndef DARH_APPLICATIONADAPTER_H
#define DARH_APPLICATIONADAPTER_H

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/
#include "BUtil/PlatformTypes.h"
#include "Darh_Version.h"
#include "Darh_Cfg.h"
#include "Darh_ErrMemAdapter.h"

#ifdef __cplusplus
extern "C" {
#endif
/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/
/*
 * \brief  check version of the module
 */
#if (!Darh_CHECK_VERSION(5, 1, 0))
#error "Version of Darh_ApplAdapter.h does not match the version of the module!"
#endif
/*------------------------------------------------------------------------------
                      Global Function Declarations
------------------------------------------------------------------------------*/
#define Darh_START_SEC_CODE
#include "Darh_MemMap.h"

/**
 * \brief Function to start the transmission to the diagnose master
 *
 * Function to start the transmission of the data. The function returns after indicating the lower layer
 * to start the transmission.
 *
 * \param[in] length length of the data provided in data to be transmitted
 * \param[in] data pointer to the data to be transmitted. The data shall be keep unchanged until
 *                 the finish callback is called.
 *
 * \return TRUE if the lowerlayer has accepted the data for the transmission, FALSE in other case.
 *
 */
extern boolean Darh_Appl_Transmit2DiagnoseMaster(uint16 length, const uint8* data);

/**
 * \brief Description of function Darh_Appl_CheckEventToBeReported
 *
 * The adapter shall provide this interface which returns if a specific
 * EventId shall be reported to the diagnose master or not.
 *
 * \param[in] EventId ID of the event to check if it has to be reported or not
 *
 * \return TRUE if the event shall be reported and FALSE if not.
 *
 */
extern boolean Darh_Appl_CheckEventToBeReported(ErrMemService_EventIdType EventId);

/**
 * \brief Description of function Darh_Appl_CountOfEventsToBeReported
 *
 * The adapter shall provide this interface to indicate how many events
 * are going to be be reported to the Diagnose Master. This interface is called from
 * RDBI Jobs 0x1723.
 *
 * \param -
 *
 * \return count of events which may be reported to the diagnose master.
 *
 */
extern uint16 Darh_Appl_CountOfEventsToBeReported(void);

/**
 * \brief Returns the EventID of a EventIdx
 *
 * The Darh stores a list of EventIDs, this function returns the DM/Dem EventID at the position
 * EventIdx of the list.
 *
 * \param[EventIdx] index in the list
 *
 * \return EventId DM/Dem EventId at the position EventIdx of the list
 *
 */
extern ErrMemService_EventIdType Darh_Appl_GetEventId(uint16 EventIdx);

#define Darh_STOP_SEC_CODE
#include "Darh_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* DARH_APPLICATIONADAPTER_H */
