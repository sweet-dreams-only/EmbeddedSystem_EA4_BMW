/**
*  \file
*
*  \brief       Darh Error Manager Adapter
*
*  Error Manager adapter of Darh Module
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
#ifndef DARH_ERRORMANAGER_H
#define DARH_ERRORMANAGER_H

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/
#include "BUtil/PlatformTypes.h"
#include "Darh_Version.h"

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
#error "Version of Darh_ErrMemAdapter.h does not match the version of the module!"
#endif

/*------------------------------------------------------------------------------
                      Data Types
------------------------------------------------------------------------------*/
/**
 * \brief Typedef which represents the maximal size of a FreezeFrame.
 */
typedef uint8 ErrMemService_TimestampFreezeFrameType[4];

/**
 * \brief Typedef of an Event identifier
 */
typedef uint32 ErrMemService_EventIdType;

/**
 * \brief Possible return types of Error Memory services.
 */
typedef enum {
    ERRMEMSERVICE_OK,       /** <= ok, no error occurs */
    ERRMEMSERVICE_NOT_OK    /** <= error, a not specified error has occurs */
} ErrMemService_ResultType;

/**
 * \brief Type to indicate the status of an event.
 */
typedef enum {
    ERRMEMSERVICE_STATUS_FAILED,
    ERRMEMSERVICE_STATUS_PASSED
} ErrMemService_EventStatusType;

/**
 * \brief Type to store a DTC Value.
 */
typedef uint32 ErrMemService_UDSDTCType;


/*------------------------------------------------------------------------------
                      Global Function Declarations
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
 * \return ERRMEMSERVICE_OK
 *
 */
extern ErrMemService_ResultType Darh_ErrorManager_GetEventFreezeFrameData(ErrMemService_EventIdType EventId,
                                                                          uint8* freezeFrame);
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
 */
extern uint32 Darh_ErrorManager_GetDTCOfEvent(ErrMemService_EventIdType EventId);

/**
 * \brief Gets the DTC of the Darh Application DTC.
 *
 * Returns the DTC Value of the Darh Application Event.
 *
 * \param --
 *
 * returns uint32 containing the DTC value.
 *
 */
extern ErrMemService_UDSDTCType Darh_ErrorManager_ApplDtc_GetDTCOfEvent(void);

/**
 * \brief Gets the DTC of the Darh Network DTC.
 *
 * Returns the DTC Value of the Darh Network Event.
 *
 * \param --
 *
 * returns uint32 containing the DTC value.
 *
 */
extern ErrMemService_UDSDTCType Darh_ErrorManager_NetDtc_GetDTCOfEvent(void);

/**
 * \brief Sets the Events of the Darh Application DTC.
 *
 * Sets the DTC of the Darh Application Event.
 *
 * \param[in] EventStatus indicates if the Event is passed or failed
 *
 * returns --
 *
 */
extern void Darh_ErrorManager_ApplDtc_SetEventStatus(ErrMemService_EventStatusType EventStatus);

/**
 * \brief Sets the Events of the Darh Network DTC.
 *
 * Sets the DTC of the Darh Network Event.
 *
 * \param[in] EventStatus indicates if the Event is passed or failed
 *
 * returns --
 *
 */
extern void Darh_ErrorManager_NetDtc_SetEventStatus(ErrMemService_EventStatusType EventStatus);

#define Darh_STOP_SEC_CODE
#include "Darh_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* DARH_ERRORMANAGER_H */
