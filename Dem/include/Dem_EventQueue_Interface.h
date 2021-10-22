/* ********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2017 by Vctr Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 */
/*! \ingroup    Dem_Shared
 *  \defgroup   Dem_EventQueue Event Queue
 *  \{
 *  \file       Dem_EventQueue_Interface.h
 *  \brief      Diagnostic Event Manager (Dem) header file
 *  \details    Public interface of EventQueue subcomponent
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Savas Ates                    vissat        Vctr Informatik GmbH
 *  Anna Bosch                    visanh        Vctr Informatik GmbH
 *  Stefan Huebner                vishrs        Vctr Informatik GmbH
 *  Thomas Dedler                 visdth        Vctr Informatik GmbH
 *  Alexander Ditte               visade        Vctr Informatik GmbH
 *  Matthias Heil                 vismhe        Vctr Informatik GmbH
 *  Erik Jeglorz                  visejz        Vctr Informatik GmbH
 *  Friederike Schulze            visfrs        Vctr Informatik GmbH
 *  Aswin Vijayamohanan Nair      visavi        Vctr Informatik GmbH
 *  Fabian Wild                   viszfa        Vctr Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  REFER TO DEM.H
 *********************************************************************************************************************/

#if !defined (DEM_EVENTQUEUE_INTERFACE_H)
#define DEM_EVENTQUEUE_INTERFACE_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                        /* Dem module header */
/* ------------------------------------------------------------------------- */
#include "Dem_EventQueue_Types.h"
#include "Dem_SatelliteData_Interface.h"
/* ------------------------------------------------------------------------- */


/* ********************************************************************************************************************
 *  SUBCOMPONENT CONSTANT MACROS
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  SUBCOMPONENT FUNCTION MACROS
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  SUBCOMPONENT OBJECT FUNCTION DECLARATIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \defgroup Dem_EventQueue_Properties Properties
 * \{
 */

/* ****************************************************************************
 * Dem_EventQueue_ResetQueueStatus
 *****************************************************************************/
/*!
 * \brief         Clear the queue status in a satellite data container.
 *
 * \details       Clear the queue status in a satellite data container.
 *
 * \param[in]     SatelliteData
 *                Satellite data value
 *
 * \return        Satellite data value with queue status reset
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_SatelliteData_DataType, DEM_CODE)
Dem_EventQueue_ResetQueueStatus(
    CONST(Dem_SatelliteData_DataType, AUTOMATIC) SatelliteData
  );

/* ****************************************************************************
 * Dem_EventQueue_GetQueueStatus
 *****************************************************************************/
/*!
 * \brief         Get the queue status from a satellite data container.
 *
 * \details       Get the queue status from a satellite data container.
 *
 * \param[in]     SatelliteData
 *                Satellite data value
 *
 * \return        Queue status stored in the satellite data container
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_EventQueue_StatusType, DEM_CODE)
Dem_EventQueue_GetQueueStatus(
  CONST(Dem_SatelliteData_DataType, AUTOMATIC)  SatelliteData
  );

/* ****************************************************************************
 * Dem_EventQueue_TestFdcTripStatus
 *****************************************************************************/
/*!
 * \brief         Test if event fdc trip is set in the queue status.
 *
 * \details       Test if event fdc trip is set in the queue status.
 *
 * \param[in]     QueueStatus
 *                Queue status byte
 *
 * \return        TRUE
 *                Flag is set
 * \return        FALSE
 *                Flag is not set
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_EventQueue_TestFdcTripStatus(
  CONST(Dem_EventQueue_StatusType, AUTOMATIC) QueueStatus
  );

/* ****************************************************************************
 * Dem_EventQueue_SetFdcTripStatus
 *****************************************************************************/
/*!
 * \brief         Set 'event fdc threshold exceeded' in the queue status
 *
 * \details       Set flag 'event fdc threshold exceeded' in the queue status
 *
 * \param[in]     QueueStatus
 *                Queue status byte
 *
 * \return        Queue status with flag set.
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_EventQueue_StatusType, DEM_CODE)
Dem_EventQueue_SetFdcTripStatus(
  CONST(Dem_EventQueue_StatusType, AUTOMATIC) QueueStatus
  );

/* ****************************************************************************
 * Dem_EventQueue_TestFdcMaxSLCStatus
 *****************************************************************************/
/*!
 * \brief         Test if 'event fdc maximum exceeded' is set in the queue status.
 *
 * \details       Test if 'event fdc maximum exceeded' is set in the queue status.
 *
 * \param[in]     QueueStatus
 *                Queue status byte
 *
 * \return        TRUE
 *                Flag is set
 * \return        FALSE
 *                Flag is not set
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_EventQueue_TestFdcMaxSLCStatus(
  CONST(Dem_EventQueue_StatusType, AUTOMATIC) QueueStatus
  );

/* ****************************************************************************
 * Dem_EventQueue_SetFdcMaxSLCStatus
 *****************************************************************************/
/*!
 * \brief         Set 'event fdc maximum exceeded' in the queue status.
 *
 * \details       Set flag 'event fdc maximum exceeded' in the queue status.
 *
 * \param[in]     QueueStatus
 *                Queue status byte
 *
 * \return        Queue status with flag set.
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_EventQueue_StatusType, DEM_CODE)
Dem_EventQueue_SetFdcMaxSLCStatus(
  CONST(Dem_EventQueue_StatusType, AUTOMATIC) QueueStatus
  );

/* ****************************************************************************
* Dem_EventQueue_TestFdcProcessingStatus
*****************************************************************************/
/*!
* \brief         Test if 'event fdc maximum exceeded' is set in the queue status.
*
* \details       Test if 'event fdc maximum exceeded' is set in the queue status.
*
* \param[in]     QueueStatus
*                Queue status byte
*
* \return        TRUE
*                Flag is set
* \return        FALSE
*                Flag is not set
*
* \pre           -
*
* \context       TASK|ISR2
* \synchronous   TRUE
* \reentrant     TRUE
*****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_EventQueue_TestFdcProcessingStatus(
CONST(Dem_EventQueue_StatusType, AUTOMATIC) QueueStatus
);

/* ****************************************************************************
* Dem_EventQueue_SetFdcProcessingStatus
*****************************************************************************/
/*!
* \brief         Set 'event fdc maximum exceeded' in the queue status.
*
* \details       Set flag 'event fdc maximum exceeded' in the queue status.
*
* \param[in]     QueueStatus
*                Queue status byte
*
* \return        Queue status with flag set.
*
* \pre           -
*
* \context       TASK|ISR2
* \synchronous   TRUE
* \reentrant     TRUE
*****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_EventQueue_StatusType, DEM_CODE)
Dem_EventQueue_SetFdcProcessingStatus(
CONST(Dem_EventQueue_StatusType, AUTOMATIC) QueueStatus
);

/* ****************************************************************************
* Dem_EventQueue_TestResetTestFailedRequested
*****************************************************************************/
/*!
* \brief         Test if 'ResetTestFailedRequested' is set in the queue status.
*
* \details       Test if 'ResetTestFailedRequested' is set in the queue status.
*
* \param[in]     QueueStatus
*                Queue status byte
*
* \return        TRUE
*                Flag is set
* \return        FALSE
*                Flag is not set
*
* \pre           -
*
* \context       TASK|ISR2
* \synchronous   TRUE
* \reentrant     TRUE
*****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_EventQueue_TestResetTestFailedRequested(
CONST(Dem_EventQueue_StatusType, AUTOMATIC) QueueStatus
);

/* ****************************************************************************
* Dem_EventQueue_SetResetTestFailedRequested
*****************************************************************************/
/*!
* \brief         Set 'ResetTestFailedRequested' in the queue status.
*
* \details       Set flag 'ResetTestFailedRequested' in the queue status.
*
* \param[in]     QueueStatus
*                Queue status byte
*
* \return        Queue status with flag set.
*
* \pre           -
*
* \context       TASK|ISR2
* \synchronous   TRUE
* \reentrant     TRUE
*****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_EventQueue_StatusType, DEM_CODE)
Dem_EventQueue_SetResetTestFailedRequested(
CONST(Dem_EventQueue_StatusType, AUTOMATIC) QueueStatus
);

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */


/* ********************************************************************************************************************
 *  SUBCOMPONENT PRIVATE FUNCTION DECLARATIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \defgroup Dem_EventQueue_Private Private Methods
 * \{
 */

/* ****************************************************************************
 * Dem_EventQueue_GetQueueAction
 *****************************************************************************/
/*!
 * \brief         Get the queue action from a queue status container.
 *
 * \details       Get the queue action from a queue status container.
 *
 * \param[in]     QueueStatus
 *                Queue status data value
 *
 * \return        Queue action element stored in the queue status data
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_EventQueue_GetQueueAction(
  CONST(Dem_EventQueue_StatusType, AUTOMATIC) QueueStatus
  );

/* ****************************************************************************
 * Dem_EventQueue_SetQueueAction
 *****************************************************************************/
/*!
 * \brief         Set the queue action in a queue status container.
 *
 * \details       Set the queue action in a queue status container.
 *
 * \param[in]     QueueStatus
 *                Queue status data value
 * \param[in]     Action
 *                Queue action to set
 *
 * \return        Queue status with new queue action
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_EventQueue_StatusType, DEM_CODE)
Dem_EventQueue_SetQueueAction(
  CONST(Dem_EventQueue_StatusType, AUTOMATIC) QueueStatus,
  CONST(uint8, AUTOMATIC) Action
  );

/* ****************************************************************************
 * Dem_EventQueueCore_ProcessQueuedEventActions
 *****************************************************************************/
/*!
 * \brief         Processes events queued with the QUEUED mechanism.
 *
 * \details       This function decodes the sequence of event reports stored
 *                for the given event, and calls the respective event processor
 *                functions, selecting the QUEUED processor variant to also
 *                handle transitions of asynchronous bit.
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 * \param[in]     QueueStatus
 *                Queued state of the event
 *
 * \pre           -
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_EventQueueCore_ProcessQueuedEventActions(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(uint8, AUTOMATIC)  QueueStatus
  );

/* ****************************************************************************
 * Dem_EventQueue_ProcessEventQueuedEventActions
 *****************************************************************************/
/*!
 * \brief         Processes the queued actions of an event.
 *
 * \details       This function unqueues an event and calls the appropriate 
 *                processor.
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 * \param[in]     QueueStatus
 *                Queued state of the event
 *
 * \pre           -
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_EventQueue_ProcessEventQueuedEventActions(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(Dem_EventQueue_StatusType, AUTOMATIC)  QueueStatus
  );

/* ****************************************************************************
 * Dem_EventQueue_ProcessSatelliteQueuedEventActions
 *****************************************************************************/
/*!
 * \brief         Processes all queued events.
 *
 * \details       This function processes queued event status changes for all
 *                events.
 *
 * \param[in]     SatelliteId
 *                Unique handle of the Satellite.
 *                The SatelliteId must be in range [1..Dem_Cfg_GlobalSatelliteCount()[.
 *
 * \pre           -
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_EventQueue_ProcessSatelliteQueuedEventActions(
  CONST(Dem_Satellite_IdType, AUTOMATIC) SatelliteId
  );

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* ********************************************************************************************************************
 *  SUBCOMPONENT API FUNCTION DECLARATIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \defgroup Dem_EventQueue_Public Public Methods
 * \{
 */

/* ****************************************************************************
 * Dem_EventQueue_TestQueueOverflow
 *****************************************************************************/
/*!
 * \brief         Test for queue overflow.
 *
 * \details       Test for queue overflow.
 *
 * \param[in]     QueueStatus
 *                Current queue status byte
 * \param[in]     MonitorTrigger
 *                Application monitor result after debouncing
 *
 * \return        TRUE
 *                The queue
 * \return        FALSE
 *                The queue
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE for different events
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_EventQueue_TestQueueOverflow(
  CONST(Dem_EventQueue_StatusType, AUTOMATIC)  QueueStatus,
  CONST(Dem_EventStatusType, AUTOMATIC)   MonitorTrigger
  );

/* ****************************************************************************
 * Dem_EventQueue_CalculateQueueStatus
 *****************************************************************************/
/*!
 * \brief         Processes queuing of event reports.
 *
 * \details       Processes queuing of event reports.
 *
 * \param[in]     QueueStatus
 *                Current queue status byte
 * \param[in]     MonitorTrigger
 *                Application monitor result after debouncing
 *
 * \return        QueueStatus
 *                Updated queue status byte
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE for different events
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_EventQueue_StatusType, DEM_CODE)
Dem_EventQueue_CalculateQueueStatus(
  CONST(Dem_EventQueue_StatusType, AUTOMATIC)  QueueStatus,
  CONST(Dem_EventStatusType, AUTOMATIC)   MonitorTrigger
  );

/* ****************************************************************************
 * Dem_EventQueue_GetResult
 *****************************************************************************/
/*!
 * \brief         Write queue status update into the satellite data object.
 *
 * \details       Write queue status update into the satellite data object.
 *
 * \param[in]     QueueStatus
 *                New queue status byte
 * \param[in]     SatelliteData
 *                Satellite data object to store into
 *
 * \return        Satellite data object with updated queue status
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE for different events
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_SatelliteData_DataType, DEM_CODE)
Dem_EventQueue_GetResult(
  CONST(Dem_EventQueue_StatusType, AUTOMATIC)  QueueStatus,
  CONST(Dem_SatelliteData_DataType, AUTOMATIC)  SatelliteData
  );

/* ****************************************************************************
 * Dem_EventQueueCore_Init()
 *****************************************************************************/
/*!
 * \brief         Initialize the subcomponent.
 *
 * \details       Initializes the subcomponent.
 *
 * \pre           Only call during the initialization phase.
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_EventQueueCore_Init(
  void
  );

/* ****************************************************************************
 * Dem_EventQueueCore_MainFunction
 *****************************************************************************/
/*!
 * \brief         Task function of subcomponent Event Queue.
 *
 * \details       Processes pending event status changes.
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_EventQueueCore_MainFunction(
  void
  );

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* DEM_EVENTQUEUE_INTERFACE_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_EventQueue_Interface.h
 *********************************************************************************************************************/
