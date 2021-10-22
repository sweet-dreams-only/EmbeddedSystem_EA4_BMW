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
 *  \defgroup   Dem_Cbk Callback
 *  \{
 *  \file       Dem_Cbk_Interface.h
 *  \brief      Diagnostic Event Manager (Dem) header file
 *  \details    
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

#if !defined (DEM_CBK_INTERFACE_H)
#define DEM_CBK_INTERFACE_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                  /* Own subcomponent header */
/* ------------------------------------------------------------------------- */
#include "Dem_Cbk_Types.h"

/* ********************************************************************************************************************
 *  SUBCOMPONENT OBJECT FUNCTION DECLARATIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \defgroup Dem_Cbk_Properties Properties
 * \{
 */

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
 * \defgroup Dem_Cbk_Private Private Methods
 * \{
 */

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
 * \defgroup Dem_Cbk_Public Public Methods
 * \{
 */

/* ****************************************************************************
 * Dem_Cbk_DtcStatusChanged
 *****************************************************************************/
/*!
 * \brief         Calls all configured DTC status notification functions
 *
 * \details       This function is a wrapper of
 *                Dem_Cbk_DtcStatusChanged_Internal. The Dtc status is modified
 *                before passing it over, so the calls to
 *                Dem_DTC_ApplyExternalOnlyStatus are not distributed
 *                across the code.
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 * \param[in]     EventUdsStatusOld
 *                Old UDS status of the event
 * \param[in]     EventUdsStatusNew
 *                New UDS status of the event
 * \param[in]     NotificationReason
 *                Reason for notification
 *
 * \pre           RTE must be started
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Cbk_DtcStatusChanged(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(Dem_UdsStatusByteType, AUTOMATIC)  EventUdsStatusOld,
  CONST(Dem_UdsStatusByteType, AUTOMATIC)  EventUdsStatusNew,
  CONST(uint8, AUTOMATIC)  NotificationReason
  );

/* ****************************************************************************
 * Dem_Cbk_EventDataChanged
 *****************************************************************************/
/*!
 * \brief         Calls all configured event data notification functions
 *
 * \details       If configured, event specific and general data changed
 *                callbacks are invoked, unconditionally.
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 *
 * \pre           RTE must be started
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Cbk_EventDataChanged(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  );

/* ****************************************************************************
 * Dem_Cbk_InitMonitorForEvent
 *****************************************************************************/
/*!
 * \brief         Calls all configured 'init monitor for event' callbacks.
 *
 * \details       Calls all configured 'init monitor for event' callbacks.
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 * \param[in]     InitReason
 *                The reason why the init callback is called
 *
 * \pre           RTE must be started
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Cbk_InitMonitorForEvent(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(Dem_InitMonitorReasonType, AUTOMATIC)  InitReason
  );

/* ****************************************************************************
 * Dem_Cbk_InitMonitorForFunction
 *****************************************************************************/
/*!
 * \brief         Calls all configured 'init monitor for function' callbacks.
 *
 * \details       Calls all configured 'init monitor for function' callbacks.
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 *
 * \pre           RTE must be started
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Cbk_InitMonitorForFunction(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  );

/* ****************************************************************************
 * Dem_Cbk_DtcStatusChanged_Internal
 *****************************************************************************/
/*!
 * \brief         Call all configured DTC status notification functions
 *
 * \details       The following callbacks are called here:
 *                - DtcStatusChanged(1...*)
 *                - DcmDtcStatusChanged(1)
 *                - J1939DcmDtcStatusChanged(1)
 *
 *                Before the callbacks are processed, the passed event status
 *                is masked with the status availability mask
 *
 *                Although the callback processing is technically not possible
 *                reentrantly, the Autosar design forces this behavior. The
 *                resulting inconsistencies are documented in RfC 48668
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 * \param[in]     DtcStatusOld
 *                The old DTC status
 * \param[in]     DtcStatusNew
 *                The new DTC status
 * \param[in]     NotificationReason
 *                Reason for notification
 *
 * \pre           EventStatusOld must be different from EventStatusNew.
 * \pre           The external only status modifications must have been applied
 *                to the passed status bytes
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL FUNC(void, DEM_CODE)
Dem_Cbk_DtcStatusChanged_Internal(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(Dem_UdsStatusByteType, AUTOMATIC)  DtcStatusOld,
  CONST(Dem_UdsStatusByteType, AUTOMATIC)  DtcStatusNew,
  CONST(uint8, AUTOMATIC)  NotificationReason
  );

/* ****************************************************************************
 * Dem_Cbk_StatusChanged
 *****************************************************************************/
/*!
 * \brief         Call all configured event status notification functions
 *
 * \details       The following callbacks are called here:
 *                - EventStatusChanged(1...*)
 *                - GeneralEventStatusChanged(1)
 *                - FimEventStatusChanged(1)
 *                - DltEventStatusChanged(1)
 *
 *                Although the callback processing is technically not possible
 *                reentrantly, the Autosar design forces this behavior. The
 *                resulting inconsistencies are documented in RfC 48668
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 * \param[in]     EventUdsStatusOld
 *                The old DTC status
 * \param[in]     EventUdsStatusNew
 *                The new DTC status
 *
 * \pre           EventStatusOld must be different from EventStatusNew.
 * \pre           The external only status modifications must have been applied
 *                to the passed status bytes
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL FUNC(void, DEM_CODE)
Dem_Cbk_StatusChanged(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(Dem_UdsStatusByteType, AUTOMATIC)  EventUdsStatusOld,
  CONST(Dem_UdsStatusByteType, AUTOMATIC)  EventUdsStatusNew
  );

#if (DEM_CFG_NOTIFY_CLEAR_ALLOWED == STD_ON)
/* ****************************************************************************
 * Dem_Util_CallClearEventAllowed
 *****************************************************************************/
/*!
 * \brief         Wrap call to user defined clear filter
 *
 * \details       This function calls a user defined clear allowed callback
 *                and handles the related error conditions.
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 *
 * \return        TRUE
 *                The event may be cleared
 * \return        FALSE
 *                The application does not allow clearing
 *
 * \pre           RTE is started
 * \config        DEM_CFG_NOTIFY_CLEAR_ALLOWED == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Util_CallClearEventAllowed(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  );
#endif

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* DEM_CBK_INTERFACE_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_Cbk_Interface.h
 *********************************************************************************************************************/
