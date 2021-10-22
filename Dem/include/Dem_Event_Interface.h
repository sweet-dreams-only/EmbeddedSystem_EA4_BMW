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
/*! \ingroup    Dem_Master
 *  \addtogroup Dem_Event
 *  \{
 *  \file       Dem_Event_Interface.h
 *  \brief      Diagnostic Event Manager (Dem) header file
 *  \details    Public interface of the Event subcomponent
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

#if !defined (DEM_EVENT_INTERFACE_H)
#define DEM_EVENT_INTERFACE_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                        /* Dem module header */
/* ------------------------------------------------------------------------- */
#include "Dem_Event_Types.h"

/* ------------------------------------------------------------------------- */
#include "Dem_DTC_Types.h"


/* ********************************************************************************************************************
 *  SUBCOMPONENT CONSTANT MACROS
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  SUBCOMPONENT FUNCTION MACROS
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  SUBCOMPONENT DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  SUBCOMPONENT DATA
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  SUBCOMPONENT OBJECT FUNCTION DECLARATIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*!
 * \defgroup Dem_Event_Properties Properties
 * \{
 */

/* ****************************************************************************
 * Dem_Event_TestValidHandle
 *****************************************************************************/
/*!
 * \brief         Test whether a handle is a valid event ID
 *
 * \details       This function tests whether a handle is in the valid range
 *                of EventIds. This function does not consider calibration or
 *                runtime-availability.
 *
 * \param[in]     EventId
 *                Handle to test against range [1..Dem_Cfg_GlobalEventCount()[.
 *
 * \return        TRUE
 *                EventId is valid
 * \return        FALSE
 *                EventId is not valid
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Event_TestValidHandle(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  );

#if (DEM_CFG_SUPPORT_OBDII == STD_ON)
/* ****************************************************************************
 * Dem_Event_TestMilSupport
 *****************************************************************************/
/*!
 * \brief         Returns if the event supports the Mil indicator
 *
 * \details       Returns if the event supports the Mil indicator. 
 *
 * \param[in]     EventId
 *                Unique handle of the event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 *
 * \return        TRUE
 *                The MIL is supported.
 *                FALSE
 *                The MIL is not supported.
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_OBDII == STD_ON 
 *                || DEM_CFG_SUPPORT_WWHOBD == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Event_TestMilSupport(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  );
#endif

/* ****************************************************************************
 * Dem_Event_GetInternalStatus
 *****************************************************************************/
/*!
 * \brief         Get current internal status of the event
 *
 * \details       Get current internal status of the event
 *
 * \param[in]     EventId
 *                Unique handle of the event
 *
 * \return        Current internal status of the event
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_Event_InternalStatusType, DEM_CODE)
Dem_Event_GetInternalStatus(
  CONST(Dem_EventIdType, AUTOMATIC) EventId
  );

/* ****************************************************************************
 * Dem_Event_SetInternalStatus
 *****************************************************************************/
/*!
 * \brief         Set current internal status value of the event
 *
 * \details       Set current internal status value of the event
 *
 * \param[in]     EventId
 *                Unique handle of the event
 * \param[in]     Status
 *                New internal status of the event
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Event_SetInternalStatus(
  CONST(Dem_EventIdType, AUTOMATIC) EventId,
  CONST(Dem_Event_InternalStatusType, AUTOMATIC) Status
  );

/* ****************************************************************************
* Dem_Event_GetExtendedStatus
*****************************************************************************/
/*!
 * \brief         Get current extended status of the event
 *
 * \details       Get current extended status of the event
 *
 * \param[in]     EventId
 *                Unique handle of the event
 *
 * \return        Current extended status of the event
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_Event_GetExtendedStatus(
  CONST(Dem_EventIdType, AUTOMATIC) EventId
  );

/* ****************************************************************************
 * Dem_Event_SetExtendedStatus
 *****************************************************************************/
/*!
 * \brief         Set current extended status value of the event
 *
 * \details       Set current extended status value of the event
 *
 * \param[in]     EventId
 *                Unique handle of the event
 * \param[in]     Status
 *                New extended status of the event
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Event_SetExtendedStatus(
  CONST(Dem_EventIdType, AUTOMATIC) EventId,
  CONST(uint8, AUTOMATIC) Status
  );

#if (DEM_FEATURE_NEED_TRIPCOUNTER == STD_ON)
/* ****************************************************************************
 * Dem_Event_GetTripCount
 *****************************************************************************/
/*!
 * \brief         Get current trip count of the event
 *
 * \details       Get current trip count of the event
 *
 * \param[in]     EventId
 *                Unique handle of the event
 *
 * \return        Current trip count of the event
 *
 * \pre           -
 * \config        DEM_FEATURE_NEED_TRIPCOUNTER == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_Event_GetTripCount(
  CONST(Dem_EventIdType, AUTOMATIC) EventId
  );
#endif

#if (DEM_FEATURE_NEED_TRIPCOUNTER == STD_ON)
/* ****************************************************************************
 * Dem_Event_SetTripCount
 *****************************************************************************/
/*!
 * \brief         Set current trip count of the event
 *
 * \details       Set current trip count of the event
 *
 * \param[in]     EventId
 *                Unique handle of the event
 * \param[in]     TripCount
 *                New trip count of the event
 *
 * \pre           -
 * \config        DEM_FEATURE_NEED_TRIPCOUNTER == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Event_SetTripCount(
  CONST(Dem_EventIdType, AUTOMATIC) EventId,
  CONST(uint8, AUTOMATIC) TripCount
  );
#endif

#if (DEM_FEATURE_NEED_OBD == STD_ON)
/* ****************************************************************************
 * Dem_Event_GetQualifyStatus
 *****************************************************************************/
/*!
 * \brief         Get current qualification status of the event
 *
 * \details       Get current qualification status of the event
 *
 * \param[in]     EventId
 *                Unique handle of the event
 *
 * \return        Current qualification status of the event
 *
 * \pre           -
 * \config        DEM_FEATURE_NEED_OBD == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_Event_GetQualifyStatus(
  CONST(Dem_EventIdType, AUTOMATIC) EventId
  );
#endif

#if (DEM_FEATURE_NEED_OBD == STD_ON)
/* ****************************************************************************
 * Dem_Event_SetQualifyStatus
 *****************************************************************************/
/*!
 * \brief         Set current qualification status of the event
 *
 * \details       Set current qualification status of the event
 *
 * \param[in]     EventId
 *                Unique handle of the event
 * \param[in]     Status
 *                New qualification status of the event
 *
 * \pre           -
 * \config        DEM_FEATURE_NEED_OBD == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Event_SetQualifyStatus(
  CONST(Dem_EventIdType, AUTOMATIC) EventId,
  CONST(uint8, AUTOMATIC) Status
  );
#endif

/* ****************************************************************************
 * Dem_Event_GetUDSStatus
 *****************************************************************************/
/*!
 * \brief         Get current UDS status of the event
 *
 * \details       -
 *
 * \param[in]     EventId
 *                Unique handle of the event
 *
 * \return        Current UDS status of the event
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_UDSStatus_Type, DEM_CODE)
Dem_Event_GetUDSStatus(
  CONST(Dem_EventIdType, AUTOMATIC) EventId
  );

/* ****************************************************************************
 * Dem_Event_SetUDSStatus
 *****************************************************************************/
/*!
 * \brief         Set current UDS status value of the event
 *
 * \details       -
 *
 * \param[in]     EventId
 *                Unique handle of the event
 * \param[in]     Status
 *                New UDS status of the event
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Event_SetUDSStatus(
  CONST(Dem_EventIdType, AUTOMATIC) EventId,
  CONST(Dem_UDSStatus_Type, AUTOMATIC) Status
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
 * \defgroup Dem_Event_Private Private Methods
 * \{
 */

#if (DEM_FEATURE_NEED_IMMEDIATEHEAL == STD_ON)
/* ****************************************************************************
 * Dem_Event_Passed_ProcessHealing
 *****************************************************************************/
/*!
 * \brief         Process event healing for events with healing target 0.
 *
 * \details       Tests if an event has healed with healing target 0 and
 *                processes the actions resulting from healing. This function
 *                has no effect when called for events with healing target != 0.
 *
 * \param[in]     EventContext
 *                Event processing context
 *
 * \pre           -
 * \config        DEM_FEATURE_NEED_IMMEDIATEHEAL == STD_ON
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Event_Passed_ProcessHealing(
  CONSTP2VAR(Dem_Event_ContextType, AUTOMATIC, AUTOMATIC) EventContext
  );
#endif

/* ****************************************************************************
 * Dem_Event_TestConfirmed
 *****************************************************************************/
/*!
 * \brief         Tests if an event has confirmed (completed tripping)
 *
 * \details       -
 *
 * \param[in]     EventContext
 *                Event processing context
 *
 * \return        TRUE
 *                Event is confirmed
 * \return        FALSE
 *                Event is not yet confirmed
 *
 * \pre           -
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Event_TestConfirmed(
  CONSTP2VAR(Dem_Event_ContextType, AUTOMATIC, AUTOMATIC)  EventContext
  );

/* ****************************************************************************
 * Dem_Event_OpCycleStart
 *****************************************************************************/
/*!
 * \brief         Processes the start of the event's operation cycle
 *
 * \details       Processes the start of the event's operation cycle: Reset
 *                status bits and debouncing.
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 *
 * \pre           -
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Event_OpCycleStart(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  );

/* ****************************************************************************
 * Dem_Event_ProcessHealing
 *****************************************************************************/
/*!
 * \brief         Processes an event's healing conditions
 *
 * \details       Processes the healing counter. If the healing conditions
 *                configured for the event are fulfilled, the event is healed.
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 * \param[in]     EventStatus
 *                Current event status of the event
 *
 * \return        Modified event status based on the status passed
 *
 * \pre           -
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_Event_ProcessHealing(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(uint8, AUTOMATIC)  EventStatus
  );

/* ****************************************************************************
 * Dem_Event_OpCycleEnd_Healing
 *****************************************************************************/
/*!
 * \brief         Processes healing at the end of the event's operation cycle
 *
 * \details       -
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 * \param[in]     EventStatus
 *                Current event status
 *
 * \return        TRUE if the event has fulfilled the preconditions to start aging
 *                FALSE if the event is blocked from aging
 *
 * \pre           -
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL FUNC(boolean, DEM_CODE)
Dem_Event_OpCycleEnd_Healing(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(uint8, AUTOMATIC)  EventStatus
  );

/* ****************************************************************************
 * Dem_Event_OpCycleEnd
 *****************************************************************************/
/*!
 * \brief         Processes the end of the event's operation cycle
 *
 * \details       Processes actions performed at the end of the event's operation
 *                cycle, i.e. healing, aging start condition.
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 * \param[in]     OldDtcStatus
 *                Dtc status before cycle restart
 *
 * \pre           -
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Event_OpCycleEnd(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(uint8, AUTOMATIC)  OldDtcStatus
  );

/* ****************************************************************************
 * Dem_Event_InitEventContext
 *****************************************************************************/
/*!
 * \brief         Initialize context of event's status report processing.
 *
 * \details       -
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 *
 * \param[out]    EventContext
 *                Event processing context
 *
 * \pre           -
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Event_InitEventContext(
CONST(Dem_EventIdType, AUTOMATIC)  EventId,
CONSTP2VAR(Dem_Event_ContextType, AUTOMATIC, AUTOMATIC) EventContext
);

/* ****************************************************************************
 * Dem_Event_CalculateStatusOnFailed
 *****************************************************************************/
/*!
 * \brief         Update of event's storage independent UDS status bits on 
 *                'Failed' status report
 *
 * \details       -
 *
 * \param[in,out] EventContext
 *                Event processing context
 *
 * \pre           -
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     TRUE for different EventContext->EventId or same EventContext
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Event_CalculateStatusOnFailed(
CONSTP2VAR(Dem_Event_ContextType, AUTOMATIC, AUTOMATIC) EventContext
);

/* ****************************************************************************
 * Dem_Event_CalculateFailedEffects
 *****************************************************************************/
/*!
 * \brief         Calculate storage independent event triggers on 'Failed' status report.
 *
 * \details       Calculate event triggers from changed, storage independent 
 *                UDS status bits on 'Failed' status report.
 *
 * \param[in,out] EventContext
 *                Event processing context
 *
 * \pre           -
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     TRUE for different EventContext->EventId or same EventContext
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Event_CalculateFailedEffects(
CONSTP2VAR(Dem_Event_ContextType, AUTOMATIC, AUTOMATIC) EventContext
);                                                      

/* ****************************************************************************
 * Dem_Event_CalculateStatusOnFailed_OnStorage
 *****************************************************************************/
/*!
 * \brief         Update of event's storage dependent UDS status bits on 
 *                'Failed' status report
 *
 * \details       -
 *
 * \param[in,out] EventContext
 *                Event processing context
 *
 * \pre           -
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     TRUE for different EventContext->EventId or same EventContext
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Event_CalculateStatusOnFailed_OnStorage(
CONSTP2VAR(Dem_Event_ContextType, AUTOMATIC, AUTOMATIC) EventContext
);                                                                                                                               /* PRQA S 0779 */ /* MD_MSR_5.1_779 */

/* ****************************************************************************
 * Dem_Event_CalculateFailedEffects_OnStorage
 *****************************************************************************/
/*!
 * \brief         Calculate storage depending event triggers on 'Failed' status report.
 *
 * \details       Among others, process reaching pending state, confirmation 
 *                on reaching event's or Mil group's (if configured) trip count
*                 target and warning indicator requests.
 *
 * \param[in,out] EventContext
 *                Event processing context
 *
 * \pre           -
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Event_CalculateFailedEffects_OnStorage(
CONSTP2VAR(Dem_Event_ContextType, AUTOMATIC, AUTOMATIC) EventContext
);                                                                                                                               /* PRQA S 0779 */ /* MD_MSR_5.1_779 */

/* ****************************************************************************
 * Dem_Event_ProcessFailedEffects
 *****************************************************************************/
/*!
 * \brief         Process storage depending event triggers on 'Failed' status report.
 *
 * \details       Process event's warning indicator requests. Enable user indicator
 *                and special indicator (id configured). If Mil indicator is 
 *                requested, store 'Permanent DTC'.
 *
 * \param[in,out] EventContext
 *                Event processing context
 *
 * \pre           -
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Event_ProcessFailedEffects(
CONSTP2CONST(Dem_Event_ContextType, AUTOMATIC, AUTOMATIC) EventContext
);

/* ****************************************************************************
 * Dem_Event_CalculateStatusOnPassed
 *****************************************************************************/
/*!
 * \brief         Update of event's UDS status bits on 'Passed' status report
 *
 * \details       -
 *
 * \param[in,out] EventContext
 *                Event processing context
 *
 * \pre           -
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     TRUE for different EventContext->EventId or same EventContext
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Event_CalculateStatusOnPassed(
CONSTP2VAR(Dem_Event_ContextType, AUTOMATIC, AUTOMATIC) EventContext
);

/* ****************************************************************************
 * Dem_Event_Passed_CalcEventEffects
 *****************************************************************************/
/*!
 * \brief         Calculate event triggers on 'Passed' status report.
 *
 * \details       -
 *
 * \param[in,out] EventContext
 *                Event processing context
 *
 * \pre           -
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     TRUE for different EventContext->EventId or same EventContext
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Event_Passed_CalcEventEffects(
CONSTP2VAR(Dem_Event_ContextType, AUTOMATIC, AUTOMATIC) EventContext
);

/* ****************************************************************************
 * Dem_Event_ProcessPassedEffects
 *****************************************************************************/
/*!
 * \brief         Process event triggers on 'Passed' status report.
 *
 * \details       Process event healing (among others).
 *
 * \param[in,out] EventContext
 *                Event processing context
 *
 * \pre           -
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Event_ProcessPassedEffects(
  CONSTP2VAR(Dem_Event_ContextType, AUTOMATIC, AUTOMATIC) EventContext
  );

#if (DEM_FEATURE_NEED_OBD == STD_ON)                                                                                             /* COV_MSR_UNSUPPORTED XF */
/* ****************************************************************************
 * Dem_Event_QualifyStatus
 *****************************************************************************/
/*!
 * \brief         Process qualification status of an event.
 *
 * \details       In case the DCY is not already qualified, this masks the
 *                confirmed and WIR bits of the event status. These are
 *                restored once the DCY qualifies later.
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 * \param[in]     Effects
 *                Trigger flags
 *
 * \pre           -
 * \config        DEM_FEATURE_NEED_OBD == STD_ON
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     TRUE for different EventId
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
  Dem_Event_QualifyStatus(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(uint8, AUTOMATIC)  Effects
  );
#endif

/* ****************************************************************************
 * Dem_Event_ProcessNotifications
 *****************************************************************************/
/*!
 * \brief         Notifies all changes to observers
 *
 * \details       Notifies all changes to observers.
 *
 * \param[in]     EventContext
 *                Event processing context
 *
 * \pre           -
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Event_ProcessNotifications(
  CONSTP2VAR(Dem_Event_ContextType, AUTOMATIC, AUTOMATIC)  EventContext
  );

/* ****************************************************************************
 * Dem_Event_InitAvailableNV
 *****************************************************************************/
/*!
 * \brief         Initializes the event availability from NV Ram
 *
 * \details       Initializes the event availability from NV Ram
 *
 * \pre           May be called only during module initialization
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Event_InitAvailableNV(
  void
  );

/* ****************************************************************************
 * Dem_Event_InitQualification
 *****************************************************************************/
/*!
 * \brief         Initializes the qualification states
 *
 * \details       Initializes the qualification states
 *
 * \pre           May be called only during module initialization
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Event_InitQualification(
  void
  );

/* ****************************************************************************
 * Dem_Event_InitEventInternalStatus
 *****************************************************************************/
/*!
 * \brief         Initializes the internal event status of a given event
 *
 * \details       Initializes the internal event status of a given event
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 *
 * \pre           May be called only during module initialization
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Event_InitEventInternalStatus(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  );

/* ****************************************************************************
 * Dem_Event_InitEventStatus
 *****************************************************************************/
/*!
 * \brief         Initializes the event status of a given event
 *
 * \details       Initializes the event status of a given event
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 *
 * \pre           May be called only during module initialization
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Event_InitEventStatus(
  CONST(Dem_EventIdType, AUTOMATIC) EventId
  );

/* ****************************************************************************
 * Dem_Event_ProcessEventAvailable
 *****************************************************************************/
/*!
 * \brief         Process event availability changes
 *
 * \details       -
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 * \pre           -
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Event_ProcessEventAvailable(
  CONST(Dem_EventIdType, AUTOMATIC) EventId
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
 * \defgroup Dem_Event_Public Public Methods
 * \{
 */

#if (DEM_FEATURE_NEED_HEALING == STD_ON) && (DEM_FEATURE_NEED_AGING_AFTER_HEALING == STD_ON)
/* ****************************************************************************
 * Dem_Event_TestEventHealed
 *****************************************************************************/
/*!
 * \brief         Tests whether an event is healed
 *
 * \details       -
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 * \param[in]     EventStatus
 *                Current event status of the event
 *
 * \return        TRUE
 *                The event is healed
 * \return        FALSE
 *                The event is not healed
 *
 * \pre           -
 *
 * \config        DEM_FEATURE_NEED_HEALING == STD_ON 
 *                  && DEM_FEATURE_NEED_AGING_AFTER_HEALING == STD_ON
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL FUNC(boolean, DEM_CODE)
Dem_Event_TestEventHealed(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(uint8, AUTOMATIC)  EventStatus
  );
#endif /*#if (DEM_FEATURE_NEED_HEALING == STD_ON) && (DEM_FEATURE_NEED_AGING_AFTER_HEALING == STD_ON)*/

#if (DEM_CFG_SUPPORT_EVENTAVAILABLE == STD_ON)
/* ****************************************************************************
 * Dem_Event_Disconnect_Normal
 *****************************************************************************/
/*!
 * \brief         Marks a normal event unavailable
 *
 * \details       This function sets the event unavailable if it is not stored.
 *
 *                Do not call directly, use Dem_Event_Disconnect instead.
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 *
 * \pre           Must be called in critical section DiagMonitor
 * \config        DEM_CFG_SUPPORT_EVENTAVAILABLE == STD_ON
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     TRUE for different EventId
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Event_Disconnect_Normal(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  );
#endif

#if (DEM_CFG_SUPPORT_EVENTAVAILABLE == STD_ON)
/* ****************************************************************************
 * Dem_Event_Disconnect
 *****************************************************************************/
/*!
 * \brief         Marks an event unavailable
 *
 * \details       This function sets an event unavailable, if its state allows
 *                to do so.
 *
 *                In case the event is set unavailable, its event status byte
 *                is changed to 0x00 and the FiM is informed.
 *
 *                Otherwise, this function returns E_NOT_OK.
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 *
 * \return        E_OK
 *                The event was set to unavailable
 * \return        E_NOT_OK
 *                The event was not set to unavailable
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_EVENTAVAILABLE == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE for different EventId
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Event_Disconnect(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  );
#endif

#if (DEM_CFG_SUPPORT_EVENTAVAILABLE == STD_ON)
/* ****************************************************************************
 * Dem_Event_Reconnect_Normal
 *****************************************************************************/
/*!
 * \brief         Marks a normal event available
 *
 * \details       This function sets the event available.
 *
 *                Do not call directly, use Dem_Event_Reconnect instead.
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_EVENTAVAILABLE == STD_ON
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     TRUE for different EventId
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Event_Reconnect_Normal(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  );
#endif

/* ****************************************************************************
 * Dem_Event_TestEventAvailable
 *****************************************************************************/
/*!
 * \brief         Tests if an Event is available based on runtime calibration
 *
 * \details       -
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 *
 * \return        TRUE
 *                The event is available
 * \return        FALSE
 *                The event is not available
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Event_TestEventAvailable(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  );

#if (DEM_CFG_SUPPORT_IUMPR == STD_ON) \
 || (DEM_FEATURE_NEED_PID01_CALCULATION == STD_ON) \
 || (DEM_FEATURE_NEED_PID41_CALCULATION == STD_ON) \
 || (DEM_FEATURE_NEED_PID41_CCONLY_CALCULATION == STD_ON)
/* ****************************************************************************
 * Dem_Event_TestEventSuppressed
 *****************************************************************************/
/*!
 * \brief         Tests if an event can be considered for reporting API
 *
 * \details       Tests all options due to which an event has to be excluded
 *                from reporting API, based on an individual event.
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 *
 * \return        TRUE
 *                The event is currently suppressed
 * \return        FALSE
 *                The event is currently not suppressed
 *
 * \pre           -
 * \config        (DEM_CFG_SUPPORT_IUMPR == STD_ON)
 *                || (DEM_FEATURE_NEED_PID01_CALCULATION == STD_ON)
 *                || (DEM_FEATURE_NEED_PID41_CALCULATION == STD_ON)
 *                || (DEM_FEATURE_NEED_PID41_CCONLY_CALCULATION == STD_ON)
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Event_TestEventSuppressed(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  );
#endif

/* ****************************************************************************
 * Dem_Event_SetDisconnectedBit
 *****************************************************************************/
/*!
 * \brief         Set an event's disconnected bit
 *
 * \details       -
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 * \param[in]     IsDisconnected
 *                TRUE: Set disconnected bit to TRUE
 *                FALSE: Set disconnected bit to FALSE
 *
 * \pre           Must be called within critical section DiagMonitor
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     TRUE for different EventId
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Event_SetDisconnectedBit(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(boolean, AUTOMATIC)  IsDisconnected
  );

#if (DEM_CFG_SUPPORT_EVENTAVAILABLE == STD_ON)
/* ****************************************************************************
 * Dem_Event_MayDisconnect
 *****************************************************************************/
/*!
 * \brief         Tests precondition for event disconnect
 *
 * \details       -
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 * \return        TRUE
 *                The event may be disconnected
 * \return        FALSE
 *                The event may not be disconnected
 * \pre           Must be called within critical section DiagMonitor
 * \config        DEM_CFG_SUPPORT_EVENTAVAILABLE == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL FUNC(boolean, DEM_CODE)
Dem_Event_MayDisconnect(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  );
#endif

#if (DEM_CFG_SUPPORT_EVENTAVAILABLE == STD_ON)
/* ****************************************************************************
 * Dem_Event_Reconnect
 *****************************************************************************/
/*!
 * \brief         Marks an event available
 *
 * \details       This function sets an event available.
 *
 *                In case the event is set available, its event status byte is
 *                changed to 0x50 and the FiM is informed.
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_EVENTAVAILABLE == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Event_Reconnect(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  );
#endif

/* ****************************************************************************
 * Dem_Event_ProcessFdc
 *****************************************************************************/
/*!
 * \brief         Process the event's FDC trip actions
 *
 * \details       This function processes the stored triggers from debounce
 *                values passing the FDC trip threshold.
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 * \param[in]     FdcThresholdExceeded
 *                FDC Storage threshold was exceeded
 * \param[in]     FdcMaximumExceeded
 *                FDC Maximum (this cycle) was exceeded
 *
 * \pre           -
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Event_ProcessFdc(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(boolean, AUTOMATIC)  FdcThresholdExceeded,
  CONST(boolean, AUTOMATIC)  FdcMaximumExceeded
  );

/* ****************************************************************************
 * Dem_Event_Passed
 *****************************************************************************/
/*!
 * \brief         Process the event's queued qualified passed result
 *
 * \details       This function processes a passed result stored on the
 *                event queue, for events using the QUEUED mechanism. The
 *                triggers resulting from the status bit changes are calculated
 *                within this function, based on the current event status.
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 *
 * \pre           -
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL FUNC(void, DEM_CODE)
Dem_Event_Passed(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  );

/* ****************************************************************************
 * Dem_Event_Healed
 *****************************************************************************/
/*!
 * \brief         Heals an event
 *
 * \details       Resets all warning indicator requests from the given event.
 *                This can modify the global indicator state if the indicator
 *                is no longer requested at all.
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 * \param[in]     EventStatus
 *                Current event status of the event
 *
 * \return        Modified event status based on the status passed
 *
 * \pre           -
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL FUNC(uint8, DEM_CODE)
Dem_Event_Healed(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(uint8, AUTOMATIC)  EventStatus
  );

/* ****************************************************************************
 * Dem_Event_Failed
 *****************************************************************************/
/*!
 * \brief         Process the event's queued qualified failed result
 *
 * \details       This function processes a failed result stored on the
 *                event queue.
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 *
 * \pre           -
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL FUNC(void, DEM_CODE)
Dem_Event_Failed(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  );

/* ****************************************************************************
 * Dem_Event_OpCycle
 *****************************************************************************/
/*!
 * \brief         Updates an event's state due to operation cycle change
 *
 * \details       -
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 * \param[in,out] ArgPtr
 *                Arguments: CycleStatus - encoding of cycle modification
 *
 * \pre           -
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL FUNC(void, DEM_CODE)
Dem_Event_OpCycle(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(Dem_DTC_ForEachCombinedArgPtrType, AUTOMATIC)  ArgPtr
  );

/* ****************************************************************************
 * Dem_Event_ResetTestFailed
 *****************************************************************************/
/*!
 * \brief         Resets the 'TestFailed' bit
 *
 * \details       -
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Event_ResetTestFailed(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  );

#if (DEM_FEATURE_NEED_OEM_EXTENSIONS_VCC == STD_OFF)
/* ****************************************************************************
 * Dem_Event_Aged
 *****************************************************************************/
/*!
 * \brief         Updates an event due to aging
 *
 * \details       -
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 * \param[in,out] ArgPtr
 *                Arguments: none
 *
 * \pre           -
 * \config        DEM_FEATURE_NEED_OEM_EXTENSIONS_VCC == STD_OFF
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     TRUE for different EventId
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Event_Aged(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(Dem_DTC_ForEachCombinedArgPtrType, AUTOMATIC)  ArgPtr
  );
#endif

/* ****************************************************************************
 * Dem_Event_Cleared
 *****************************************************************************/
/*!
 * \brief         Clears an event's state in volatile RAM
 *
 * \details       -
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 * \param[in,out] ArgPtr
 *                Arguments: none
 *
 * \pre           -
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Event_Cleared(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(Dem_DTC_ForEachCombinedArgPtrType, AUTOMATIC)  ArgPtr
  );

#if (DEM_FEATURE_NEED_OEM_EXTENSIONS_VCC == STD_OFF) \
 && (DEM_CFG_SUPPORT_DISPLACEMENT == STD_ON)
/* ****************************************************************************
 * Dem_Event_Displaced
 *****************************************************************************/
/*!
 * \brief         Updates an event's status due to displacement
 *
 * \details       Do not call this function directly, it is part of
 *                Dem_DTC_Displaced
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 * \param[in,out] ArgPtr
 *                Arguments: none
 *
 * \pre           -
 * \config        DEM_FEATURE_NEED_OEM_EXTENSIONS_VCC == STD_OFF 
 *             && DEM_CFG_SUPPORT_DISPLACEMENT == STD_ON
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     TRUE for different EventId
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Event_Displaced(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(Dem_DTC_ForEachCombinedArgPtrType, AUTOMATIC)  ArgPtr
  );
#endif

#if (DEM_FEATURE_NEED_OEM_EXTENSIONS_VCC == STD_ON)
/* ****************************************************************************
 * Dem_Event_Displaced_Vcc
 *****************************************************************************/
/*!
 * \brief         Updates an event's status due to displacement
 *
 * \details       Do not call this function directly, it is part of
 *                Dem_DTC_Displaced_Vcc
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 * \param[in,out] ArgPtr
 *                Arguments: SI30 - Status Indicator byte
 *
 * \pre           -
 * \config        DEM_FEATURE_NEED_OEM_EXTENSIONS_VCC == STD_ON
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     TRUE for different EventId
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Event_Displaced_Vcc(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(Dem_DTC_ForEachCombinedArgPtrType, AUTOMATIC)  ArgPtr
  );
#endif

/* ****************************************************************************
 * Dem_Event_GetEventUDSStatus
 *****************************************************************************/
/*!
 * \brief         Gets the current event status
 *
 * \details       -
 *
 * \param[in]     EventId
 *                Unique handle of the Event
 *
 * \param[out]    EventUDSStatus
 *                Pointer receiving the event Uds status
 *
 * \return        E_OK
 *                EventUDSStatus now contains the event status
 *
 * \return        E_NOT_OK
 *                The request was rejected due to variant coding
 *
 * \pre           -
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Event_GetEventUDSStatus(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONSTP2VAR(Dem_UdsStatusByteType, AUTOMATIC, DEM_APPL_DATA)  EventUDSStatus
  );

/* ****************************************************************************
 * Dem_Event_GetEventFailed
 *****************************************************************************/
/*!
 * \brief         Gets Bit0 (TestFailed) of the current event status
 *
 * \details       -
 *
 * \param[in]     EventId
 *                Unique handle of the Event
 *
 * \param[out]    EventFailed
 *                Pointer receiving Bit0
 *
 * \return        E_OK
 *                EventFailed now contains Bit0
 *
 * \return        E_NOT_OK
 *                The request was rejected due to variant coding
 *
 * \pre           -
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Event_GetEventFailed(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONSTP2VAR(boolean, AUTOMATIC, DEM_APPL_DATA)  EventFailed
  );

/* ****************************************************************************
 * Dem_Event_GetEventTested
 *****************************************************************************/
/*!
 * \brief         Gets Bit6 (TestNotCompletedThisOperationCycle) of the current event status
 *
 * \details       -
 *
 * \param[in]     EventId
 *                Unique handle of the Event
 *
 * \param[out]    EventTested
 *                Pointer receiving Bit6
 *
 * \return        E_OK
 *                EventTested now contains Bit6
 *
 * \return        E_NOT_OK
 *                The request was rejected due to variant coding
 *
 * \pre           -
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Event_GetEventTested(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONSTP2VAR(boolean, AUTOMATIC, DEM_APPL_DATA)  EventTested
  );

#if (DEM_FEATURE_NEED_OBD == STD_ON)                                                                                             /* COV_MSR_UNSUPPORTED XF */
/* ****************************************************************************
 * Dem_Event_CycleQualifyDcy
 *****************************************************************************/
/*!
 * \brief         Updates an event's state due to dcy qualification
 *
 * \details       -
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 * \param[in,out] ArgPtr
 *                Arguments: none
 *
 * \pre           -
 * \config        DEM_FEATURE_NEED_OBD == STD_ON
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL FUNC(void, DEM_CODE)
Dem_Event_CycleQualifyDcy(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(Dem_DTC_ForEachCombinedArgPtrType, AUTOMATIC)  ArgPtr
  );
#endif

/* ****************************************************************************
 * Dem_Event_TestLatchedTestFailed
 *****************************************************************************/
/*!
 * \brief         Tests whether an event's latched failed restriction applies
 *
 * \details       -
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 *
 * \return        TRUE
 *                The event is latched at TestFailed
 * \return        FALSE
 *                The event is not latched, process it normally
 *
 * \pre           -
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Event_TestLatchedTestFailed(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  );

/* ****************************************************************************
 * Dem_Event_InitNvData
 *****************************************************************************/
/*!
 * \brief         Initializes the event status processing sub-component
 *
 * \details       Initializes the event status processing sub-component
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 *
 * \pre           May be called only during module initialization
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Event_InitNvData(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  );

/* ****************************************************************************
 * Dem_Event_Init
 *****************************************************************************/
/*!
 * \brief         Initializes the event status processing sub-component
 *
 * \details       Initializes the event status processing sub-component
 *
 * \pre           May be called only during module initialization
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Event_Init(
  void
  );

/* ****************************************************************************
 * Dem_Event_PreInit
 *****************************************************************************/
/*!
 * \brief         Pre-Initializes the Dem events
 *
 * \details       Pre-Initializes the Dem events
 *
 * \pre           May be called only during module pre-initialization
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Event_PreInit(
  void
  );

/* ****************************************************************************
 * Dem_Event_MainFunction
 *****************************************************************************/
/*!
 * \brief         Process queued event availability changes
 *
 * \details       Process queued event availability changes
 *
 * \pre           -
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Event_MainFunction(
  void
  );

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* DEM_EVENT_INTERFACE_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_Event_Interface.h
 *********************************************************************************************************************/
