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
 *  \defgroup   Dem_Esm Event State Manager
 *  \{
 *  \file       Dem_Esm_Interface.h
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

#if !defined (DEM_ESM_INTERFACE_H)
#define DEM_ESM_INTERFACE_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                  /* Own subcomponent header */
/* ------------------------------------------------------------------------- */
#include "Dem_Esm_Types.h"

#include "Dem_Debounce_Types.h"
#include "Dem_DTC_Types.h"
#include "Dem_Event_Types.h"

/* ********************************************************************************************************************
 *  SUBCOMPONENT OBJECT FUNCTION DECLARATIONS
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  SUBCOMPONENT PRIVATE FUNCTION DECLARATIONS
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  SUBCOMPONENT API FUNCTION DECLARATIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \defgroup Dem_Esm_Public Public Methods
 * \{
 */

#if (DEM_CFG_SUPPORT_WWHOBD == STD_ON)                                                                                           /* COV_MSR_UNSUPPORTED XF */
/* ****************************************************************************
 * Dem_Util_DcmIndicatorActivationMode
 *****************************************************************************/
/*!
 * \brief         Maps the activation mode state to DCM format
 *
 * \details       This function maps the given activation mode state to the
 *                respective DCM representation:
 *                DEM_INDICATOR_CONTINUOUS -> 0x03
 *                DEM_INDICATOR_SHORT      -> 0x02
 *                DEM_INDICATOR_ON_DEMAND  -> 0x01
 *                DEM_INDICATOR_OFF        -> 0x00
 *
 * \param[in]     ActivationMode
 *                The internal activation mode state
 *
 * \return        DCM encoded Activation Mode
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_WWHOBD == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_Util_DcmIndicatorActivationMode(
  CONST(Dem_IndicatorStatusType, AUTOMATIC)  ActivationMode
  );
#endif

#if (DEM_CFG_SUPPORT_WWHOBD == STD_ON)                                                                                           /* COV_MSR_UNSUPPORTED XF */
/* ****************************************************************************
 * Dem_Util_SeverityWwhObdDtcClass
 *****************************************************************************/
/*!
 * \brief         Maps the given severity to the WWH-OBD DTC Class
 *
 * \details       This function maps the given severity to the WWH-OBD DTC
 *                Class
 *                DEM_SEVERITY_WWHOBD_CLASS_NO_CLASS -> 0x00
 *                DEM_SEVERITY_WWHOBD_CLASS_C        -> 0x01
 *                DEM_SEVERITY_WWHOBD_CLASS_B2       -> 0x02
 *                DEM_SEVERITY_WWHOBD_CLASS_B1       -> 0x03
 *                DEM_SEVERITY_WWHOBD_CLASS_A        -> 0x04
 *
 * \param[in]     Severity
 *                The severity byte
 *
 * \return        The WWH-OBD DTC Class
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_WWHOBD == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_Util_SeverityWwhObdDtcClass(
  CONST(Dem_DTCSeverityType, AUTOMATIC)  Severity
  );
#endif

#if (DEM_CFG_SUPPORT_J1939 == STD_ON) && (DEM_FEATURE_NEED_SPECIAL_INDICATORS == STD_ON)
/* ****************************************************************************
 * Dem_Util_J1939IndicatorStatus
 *****************************************************************************/
/*!
 * \brief         Maps indicator behavior to J1939 indicator state
 *
 * \details       This function maps the internal indicator behavior to the
 *                external bit mask used by J1939.
 *
 *                The J1939 representation is not bit-shifted for a specific
 *                indicator. To use the returned value in DM messages the
 *                caller needs to shift the result to the correct position
 *                first.
 *
 *                The state map only includes states used by J1939 indicators,
 *                other indicators states will not work with this function.
 *
 * \param[in]     ConfigIndicatorState
 *                The state of a J1939 related indicator.
 *
 * \return        J1939 encoding of the passed indicator state.
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_J1939 == STD_ON && DEM_FEATURE_NEED_SPECIAL_INDICATORS == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint16, DEM_CODE)
Dem_Util_J1939IndicatorStatus(
  CONST(uint8, AUTOMATIC)  ConfigIndicatorState
  );
#endif

#if (DEM_CFG_SUPPORT_J1939 == STD_ON) && (DEM_CFG_SUPPORT_J1939_NODES == STD_ON)                                                 /* COV_MSR_UNSUPPORTED XF xf xf */
/* ****************************************************************************
 * Dem_Util_J1939PriorityOfIndicatorState
 *****************************************************************************/
/*!
 * \brief         Gets the priority of an indicator state.
 *
 * \details       Gets the priority of an indicator state.
 *
 * \param[in]     ConfigIndicatorState
 *                The state of a J1939 related indicator.
 *
 * \return        The priority value associated with the indicator state
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_J1939 == STD_ON &&
 *                DEM_CFG_SUPPORT_J1939_NODES == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_Util_J1939PriorityOfIndicatorState(
  CONST(uint8, AUTOMATIC)  ConfigIndicatorState
  );
#endif

#if (DEM_CFG_SUPPORT_J1939 == STD_ON) && (DEM_CFG_SUPPORT_J1939_NODES == STD_ON)                                                 /* COV_MSR_UNSUPPORTED XF xf xf */
/* ****************************************************************************
 * Dem_Util_J1939IndicatorStateFromPriority
 *****************************************************************************/
/*!
 * \brief         Gets the indicator state from a priority value.
 *
 * \details       Gets the indicator state from a priority value.
 *
 * \param[in]     Priority
 *                The priority of a J1939 indicator state
 *
 * \return        The indicator state associated with the priority value
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_J1939 == STD_ON &&
 *                DEM_CFG_SUPPORT_J1939_NODES == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_Util_J1939IndicatorStateFromPriority(
  CONST(uint8, AUTOMATIC)  Priority
  );
#endif

#if ( (DEM_CFG_SUPPORT_J1939 == STD_ON) \
   && (DEM_CFG_SUPPORT_J1939_NODES == STD_ON) \
   && (DEM_FEATURE_NEED_SPECIAL_INDICATORS == STD_ON) )                                                                          /* COV_MSR_UNSUPPORTED XF xf xf xf */
/* ****************************************************************************
 * Dem_Util_J1939GlobalSpecialIndicatorState
 *****************************************************************************/
/*!
 * \brief         Gets the global indicator state of a J1939 indicator
 *
 * \details       This function returns the highest priority state across
 *                all supported nodes. This only works for J1939 indicators.
 *
 * \param[in]     IndicatorId
 *                Unique handle of the indicator
 *
 * \return        Current indicator state of the indicator
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_J1939 == STD_ON &&
 *                DEM_CFG_SUPPORT_J1939_NODES == STD_ON &&
 *                DEM_FEATURE_NEED_SPECIAL_INDICATORS == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_Util_J1939GlobalSpecialIndicatorState(
  CONST(uint8, AUTOMATIC)  IndicatorId
  );
#endif

#if (DEM_CFG_SUPPORT_J1939_READ_DTC == STD_ON) || (DEM_CFG_SUPPORT_J1939_DM31 == STD_ON)                                         /* COV_MSR_UNSUPPORTED XF xf xf */
/* ****************************************************************************
 * Dem_Util_J1939OccurrenceCounter
 *****************************************************************************/
/*!
 * \brief         Gets an event's occurrence counter for J1939 reporting.
 *
 * \details       Gets an event's occurrence counter for J1939 reporting
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 *
 * \return        Occurrence counter value in J1939 format
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_J1939_READ_DTC == STD_ON ||
 *                DEM_CFG_SUPPORT_J1939_DM31 == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_Util_J1939OccurrenceCounter(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  );
#endif

#if ( (DEM_FEATURE_NEED_PID01_CALCULATION == STD_ON) || (DEM_FEATURE_NEED_PID41_CALCULATION == STD_ON) )
/* ****************************************************************************
 * Dem_Util_SetReadinessGroupSupported
 *****************************************************************************/
/*!
 * \brief         Sets OBD Readiness Group to supported or not supported
 *
 * \details       Sets bit corresponding to readiness group in readiness supported mask
 *                (0 = not supported, 1= Supported)
 *
 * \param[in]     Supported
 *                TRUE    Readiness group is set to supported
 *                FALSE   Readiness group is set to not supported
 * \param[in]     ReadinessGroup
 *                OBD Readiness Group
 * \param[in,out] PidSupportedMask
 *                OBD Readiness supported mask
 *
 * \pre           -
 * \config        DEM_FEATURE_NEED_PID01_CALCULATION == STD_ON ||
 *                DEM_FEATURE_NEED_PID41_CALCULATION == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Util_SetReadinessGroupSupported(
  CONST(boolean, AUTOMATIC)  Supported,
  CONST(uint8, AUTOMATIC)  ReadinessGroup,
  CONSTP2VAR(uint32, AUTOMATIC, DEM_APPL_DATA)  PidSupportedMask
  );
#endif
#if ( (DEM_FEATURE_NEED_PID01_CALCULATION == STD_ON) || (DEM_FEATURE_NEED_PID41_CALCULATION == STD_ON) )
/* ****************************************************************************
 * Dem_Util_SetReadinessGroupCompleted
 *****************************************************************************/
/*!
 * \brief         Sets OBD Readiness Group completion state
 *
 * \details       Sets bit corresponding to readiness group in given readiness
 *                suppoprted mask to complete or not complete
 *                (0 = completed, 1 = not complete)
 *
 * \param[in]     Completed
 *                TRUE    Readiness group is set to completed
 *                FALSE   Readiness group is set to not completed
 * \param[in]     ReadinessGroup
 *                OBD Readiness Group
 * \param[in,out] PidSupportedMask
 *                OBD Readiness supported mask
 *
 * \pre           -
 * \config        DEM_FEATURE_NEED_PID01_CALCULATION == STD_ON ||
 *                DEM_FEATURE_NEED_PID41_CALCULATION == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Util_SetReadinessGroupCompleted(
  CONST(boolean, AUTOMATIC)  Completed,
  CONST(uint8, AUTOMATIC)  ReadinessGroup,
  CONSTP2VAR(uint32, AUTOMATIC, DEM_APPL_DATA)  PidSupportedMask
  );
#endif

#if ((DEM_FEATURE_NEED_PID41_CALCULATION == STD_ON) || (DEM_FEATURE_NEED_PID41_CCONLY_CALCULATION == STD_ON))
/* ****************************************************************************
 * Dem_Util_SetReadinessGroupDisabled
 *****************************************************************************/
/*!
 * \brief         Disable OBD Readiness Group
 *
 * \details       Sets bit corresponding to readiness group Pid41DisabledMask
 *                (0 = enabled, 1= disabled)
 *
 * \param[in]     ReadinessGroup
 *                OBD Readiness Group
 *
 * \pre           -
 * \config        DEM_FEATURE_NEED_PID41_CALCULATION == STD_ON ||
 *                DEM_FEATURE_NEED_PID41_CCONLY_CALCULATION == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Util_SetReadinessGroupDisabled(
  CONST(uint8, AUTOMATIC)  ReadinessGroup
  );
#endif

#if (DEM_FEATURE_NEED_REPORTED_MIL_STATE == STD_ON)
/* ****************************************************************************
 * Dem_Indicator_TestMilIsActive
 *****************************************************************************/
/*!
 * \brief         Returns if the MIL is considered as active.
 *
 * \details       The MIL is always considered as active (for reporting in 
 *                PID 0x01, PID 0x21 and PID 0x4D), if it is continuous (or 
 *                continuous blinking). 
 *                In configurations with 'Report Blinking Mil As Active' 
 *                enabled, the Mil is also considered as active, if it is only
 *                blinking. 
 *
 * \return        TRUE
 *                The MIL is considered as active.
 *                FALSE
 *                The MIL is not considered as active.
 *
 * \pre           -
 * \config        DEM_FEATURE_NEED_REPORTED_MIL_STATE == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Indicator_TestMilIsActive(
  void
  );
#endif

#if (DEM_CFG_SUPPORT_WWHOBD == STD_ON)                                                                                           /* COV_MSR_UNSUPPORTED XF */
/* ****************************************************************************
 ! Dem_Esm_GlobalIndicatorActivationMode
 *****************************************************************************/
/*!
 * \brief         Gets the current Activation Mode.
 *
 * \details       Gets the current Activation Mode.
 *
 * \return        The current activation mode
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_WWHOBD == STD_ON
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_IndicatorStatusType, DEM_CODE)
Dem_Esm_GlobalIndicatorActivationMode(
  void
  );
#endif

#if (DEM_CFG_SUPPORT_WWHOBD == STD_ON)                                                                                           /* COV_MSR_UNSUPPORTED XF */
/* ****************************************************************************
 * Dem_Esm_AddAgingTime
 *****************************************************************************/
/*!
 * \brief         Calculates target aging time
 *
 * \details       This function increments and wraps the timer value avoiding
 *                overflow and 'magic numbers'.
 *
 * \param[in]     CurrentTime
 *                Current value of the aging timer
 * \param[in]     DeltaValue
 *                Value by which CurrentTime is incremented.
 *
 * \return        Value of (CurrentTime + DeltaValue) mod X
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_WWHOBD == STD_ON
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint32, DEM_CODE)
Dem_Esm_AddAgingTime(
  CONST(uint32, AUTOMATIC)  CurrentTime,
  CONST(uint16, AUTOMATIC)  DeltaValue
  );
#endif

#if (DEM_FEATURE_NEED_TIME_SERIES == STD_ON)
/* ****************************************************************************
 * Dem_Esm_EventCreateTimeSeriesEntry
*****************************************************************************/
/*!
 * \brief         Allocate a time series entry
 *
 * \details       This function tries to allocate a time series entry for
 *                the given event. This can displace existing time series
 *                entries if all time series entries are occupied.
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 *
 * \pre           -
 * \config        DEM_FEATURE_NEED_TIME_SERIES == STD_ON
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Esm_EventCreateTimeSeriesEntry(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  );
#endif

#if (DEM_FEATURE_NEED_GLOBAL_MIL_STATE == STD_ON)                                                                                /* COV_MSR_UNSUPPORTED XF */
/* ****************************************************************************
 * Dem_Esm_GlobalMilStateEnable
 *****************************************************************************/
/*!
 * \brief         Hook function called when the MIL is activated
 *
 * \details       If the Mil status has changed from Off to On the current
 *                Odometer value (absolute) is set as base value and the
 *                Engine Run Time is set to 0
 *
 * \pre           -
 * \config        DEM_FEATURE_NEED_GLOBAL_MIL_STATE == STD_ON
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Esm_GlobalMilStateEnable(
  void
  );
#endif

#if (DEM_FEATURE_NEED_OBD == STD_ON) && (DEM_CFG_SUPPORT_PID21 == STD_ON)                                                        /* COV_MSR_UNSUPPORTED XF xf xf */
/* ****************************************************************************
 * Dem_Esm_GlobalMilStateDisable
 *****************************************************************************/
/*!
 * \brief         Hook function called when the MIL is deactivated
 *
 * \details       The Mil status has changed from On to Off, the current
 *                Odometer value (relative) may be reset
 *
 * \pre           -
 * \config        DEM_FEATURE_NEED_OBD == STD_ON &&
 *                DEM_CFG_SUPPORT_PID21 == STD_ON
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Esm_GlobalMilStateDisable(
  void
  );
#endif

#if (DEM_CFG_SUPPORT_USER_INDICATORS == STD_ON)
/* ****************************************************************************
 * Dem_Esm_UserIndicatorEnable
 *****************************************************************************/
/*!
 * \brief         Updates user-defined indicator counters
 *
 * \details       Adds the event's contribution to the indicator states.
 *                Basically this adds 1 to each indicators continuous or
 *                blinking count, if the indicator is enabled by the given
 *                event.
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 *
 * \pre           Must be called inside of critical section 'DiagMonitor'
 * \config        DEM_CFG_SUPPORT_USER_INDICATORS == STD_ON
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Esm_UserIndicatorEnable(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  );
#endif

#if (DEM_FEATURE_NEED_SPECIAL_INDICATORS == STD_ON)                                                                              /* COV_MSR_UNSUPPORTED XF */
/* ****************************************************************************
 * Dem_Esm_SpecialIndicatorEnable
 *****************************************************************************/
/*!
 * \brief         Updates special indicator counters
 *
 * \details       Add the event's contribution to the indicator states.
 *                Basically this adds 1 from each indicators continuous,
 *                blinking, fast flash or slow flash count, if the indicator
 *                is enabled by the given event.
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 *
 * \return        The handle of a modified special handled indicator, otherwise
 *                DEM_CFG_SPECIAL_INDICATOR_NONE
 *
 * \pre           Must be called inside of critical section 'DiagMonitor'
 * \config        DEM_FEATURE_NEED_SPECIAL_INDICATORS == STD_ON
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_Esm_SpecialIndicatorEnable(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  );
#endif

#if (DEM_CFG_SUPPORT_USER_INDICATORS == STD_ON)
/* ****************************************************************************
 * Dem_Esm_UserIndicatorDisable
 *****************************************************************************/
/*!
 * \brief         Update user-defined indicator counters
 *
 * \details       Removes the event's contribution to the indicator states.
 *                Basically this subtracts 1 from each indicators continuous or
 *                blinking count, if the indicator is enabled by the given
 *                event
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 *
 * \pre           Must be called inside of critical section 'DiagMonitor'
 * \config        DEM_CFG_SUPPORT_USER_INDICATORS == STD_ON
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Esm_UserIndicatorDisable(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  );
#endif

#if (DEM_FEATURE_NEED_SPECIAL_INDICATORS == STD_ON)                                                                              /* COV_MSR_UNSUPPORTED XF */
/* ****************************************************************************
 * Dem_Esm_SpecialIndicatorDisable
 *****************************************************************************/
/*!
 * \brief         Updates special indicator counters
 *
 * \details       Removes the event's contribution to the indicator states.
 *                Basically this subtracts 1 from each indicators continuous or
 *                blinking count, if the indicator is enabled by the given
 *                event.
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 *
 * \return        The handle of a modified special handled indicator, otherwise
 *                DEM_CFG_SPECIAL_INDICATOR_NONE
 *
 * \pre           Must be called inside of critical section 'DiagMonitor'
 * \config        DEM_FEATURE_NEED_SPECIAL_INDICATORS == STD_ON
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_Esm_SpecialIndicatorDisable(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  );
#endif

#if (DEM_CFG_SUPPORT_WWHOBD == STD_ON)                                                                                           /* COV_MSR_UNSUPPORTED XF */
/* ****************************************************************************
 * Dem_Esm_IncrementQualifiedActiveEventCount
 *****************************************************************************/
/*!
 * \brief         Handles the increment of the qualified active DTC count.
 *
 * \details       This function calculates the qualified active DTC counter
 *                when an event transitions from not active to qualified active.
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_WWHOBD == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE for different EventId
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Esm_IncrementQualifiedActiveEventCount(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  );
#endif

#if (DEM_CFG_SUPPORT_WWHOBD == STD_ON)                                                                                           /* COV_MSR_UNSUPPORTED XF */
/* ****************************************************************************
 * Dem_Esm_DecrementQualifiedActiveEventCount
 *****************************************************************************/
/*!
 * \brief         Handles the decrement of the qualified active DTC count.
 *
 * \details       This function calculates the qualified active DTC counter
 *                when an event transitions from qualified active to a state
 *                with TF == 0.
 *                If the counter reaches 0 this will start healing of the B1
 *                counter, and ContinousMI counter if activation mode 4 is not
 *                active.
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 * \param[in]     StartB1Healing
 *                Flag to control if B1 counter needs to heal
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_WWHOBD == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE for different EventId
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Esm_DecrementQualifiedActiveEventCount(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(boolean, AUTOMATIC)  StartB1Healing
  );
#endif


#if (DEM_FEATURE_NEED_IUMPR == STD_ON)                                                                                           /* COV_MSR_UNSUPPORTED XF */
/* ****************************************************************************
 * Dem_Esm_ResetIumprFidPending
 *****************************************************************************/
/*!
 * \brief         Reset pending FID status of all ratios
 *
 * \details       Reset pending FID status of all ratios
 *
 * \pre           -
 * \config        DEM_FEATURE_NEED_IUMPR == STD_ON
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Esm_ResetIumprFidPending(
  void
  );
#endif

#if (DEM_FEATURE_NEED_IUMPR == STD_ON)                                                                                           /* COV_MSR_UNSUPPORTED XF */
/* ****************************************************************************
 * Dem_Esm_RatioQueueAsync
 *****************************************************************************/
/*!
 * \brief         Queue ratio processing for an event
 *
 * \details       This function will set up IUMPR processing of the event's
 *                ratio, if the numerator has not been incremented yet.
 *
 * \param[in]     RatioIndex
 *                Unique handle of the Ratio
 *
 * \pre           Must be called within critical section 'DiagMonitor'
 * \config        DEM_FEATURE_NEED_IUMPR == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Esm_RatioQueueAsync(
  CONST(Dem_RatioIdIndexType, AUTOMATIC)  RatioIndex
  );
#endif

#if (DEM_FEATURE_NEED_OBD == STD_ON) && (DEM_CFG_SUPPORT_RESTART_DCY_ON_CLEAR_DTC == STD_ON)                                     /* COV_MSR_UNSUPPORTED XF xf xf */
/* ****************************************************************************
 * Dem_Esm_PreOnClear_AllDtc
 *****************************************************************************/
/*!
 * \brief         Restarts the DCY before Clear DTC is processed
 *
 * \details       This function is called before ClearAllDTC is processed.
 *
 * \param[in]     MemoryId
 *                Unique identifier of the event memory
 *
 * \pre           -
 * \config        DEM_FEATURE_NEED_OBD == STD_ON &&
 *                DEM_CFG_SUPPORT_RESTART_DCY_ON_CLEAR_DTC == STD_ON
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Esm_PreOnClear_AllDtc(
  CONST(uint8, AUTOMATIC)  MemoryId
  );
#endif

/* ****************************************************************************
 * Dem_Esm_PostOnClear_AllDtc
 *****************************************************************************/
/*!
 * \brief         Clears global statistics after Clear DTC was processed
 *
 * \details       This function is called when ClearAllDTC was finished.
 *                It clears all global statistic data which is cleared only
 *                on ClearAllDTC requests.
 *
 * \param[in]     MemoryId
 *                Unique identifier of the event memory
 *
 * \pre           -
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Esm_PostOnClear_AllDtc(
  CONST(uint8, AUTOMATIC)  MemoryId
  );

/* ****************************************************************************
 * Dem_Esm_PostOnClear_Always
 *****************************************************************************/
/*!
 * \brief         Clears global OBD statistics after Clear DTC was processed
 *
 * \details       This function is called after a ClearDTC request was processed.
 *                It clears all global statistic data which is cleared with
 *                all clear requests.
 *
 * \param[in]     MemoryId
 *                Unique identifier of the event memory
 *
 * \pre           -
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Esm_PostOnClear_Always(
  CONST(uint8, AUTOMATIC)  MemoryId
  );

/* ****************************************************************************
 * Dem_Esm_InitWwhObdStatistics
 *****************************************************************************/
/*!
 * \brief         Initializes the WWHOBD Dtc class related statistics
 *
 * \details       Initializes the WWHOBD Dtc class related statistics
 *
 * \pre           May be called only during module initialization
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Esm_InitWwhObdStatistics(
  void
  );

/* ****************************************************************************
 * Dem_Esm_InitSpecialIndicator
 *****************************************************************************/
/*!
 * \brief         Initializes the OBD and J1939 special indicator
 *
 * \details       Initializes the OBD and J1939 special indicator
 *
 * \pre           May be called only during module initialization
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Esm_InitSpecialIndicator(
  void
  );

/* ****************************************************************************
 ! Dem_Esm_GetIndicatorStatus
 *****************************************************************************/
/*!
 * \brief         Gets the current indicator status
 *
 * \details       Gets the current indicator status
 *
 * \param[in]     IndicatorId
 *                Unique identifier of the indicator
 *
 * \return        The current indicator status
 *
 * \pre           -
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL FUNC(Dem_IndicatorStatusType, DEM_CODE)
Dem_Esm_GetIndicatorStatus(
  CONST(uint8, AUTOMATIC)  IndicatorId
  );

#if (DEM_FEATURE_NEED_PID01_CALCULATION == STD_ON)
/* ****************************************************************************
 ! Dem_Esm_SetPid01ReadinessState
 *****************************************************************************/
/*!
 * \brief         Sets state of readiness group 
 *
 * \details       Sets corresponding bit in passed bitmap to 1
 *
 * \param[in]     State
 *                Current state as 16 bit bitmap
 *
 * \param[in]     ReadinessGroup
 *                Identifier for readiness group 
 *
 * \return        New State
 *
 * \pre           -
 * \config        DEM_FEATURE_NEED_PID01_CALCULATION == STD_ON
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL FUNC(uint16, DEM_CODE)
Dem_Esm_SetPid01ReadinessState(
  CONST(uint16, AUTOMATIC) State,
  CONST(uint8, AUTOMATIC) ReadinessGroup
  );
#endif

#if (DEM_FEATURE_NEED_PID01_CALCULATION == STD_ON)
/* ****************************************************************************
 ! Dem_Esm_ResetPid01ReadinessState
 *****************************************************************************/
/*!
 * \brief         Resets state of readiness group 
 *
 * \details       Resets corresponding bit in passed bitmap to 0
 *
 * \param[in]     State
 *                Current state as 16 bit bitmap
 *
 * \param[in]     ReadinessGroup
 *                Identifier for readiness group
 *
 * \return        New State
 *
 * \pre           -
 * \config        DEM_FEATURE_NEED_PID01_CALCULATION == STD_ON
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL FUNC(uint16, DEM_CODE)
Dem_Esm_ResetPid01ReadinessState(
  CONST(uint16, AUTOMATIC) State,
  CONST(uint8, AUTOMATIC) ReadinessGroup
  );
#endif

#if (DEM_FEATURE_NEED_PID01_CALCULATION == STD_ON)
/* ****************************************************************************
 ! Dem_Esm_TestPid01ReadinessState
 *****************************************************************************/
/*!
 * \brief         Test if state is set for readiness group
 *
 * \details       Test if corresponding bit in bitmap is set to 1
 *
 * \param[in]     State
 *                Current state as 16 bit bitmap
 *
 * \param[in]     ReadinessGroup
 *                Identifier for readiness group 
 *
 * \return        TRUE
 *                Bit in bitmap is set to 1
 * \return        FALSE
 *                Bit in bitmap is set to 0
 *
 * \pre           -
 * \config        DEM_FEATURE_NEED_PID01_CALCULATION == STD_ON
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL FUNC(boolean, DEM_CODE)
Dem_Esm_TestPid01ReadinessState(
  CONST(uint16, AUTOMATIC) State,
  CONST(uint8, AUTOMATIC) ReadinessGroup
  );
#endif

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* DEM_ESM_INTERFACE_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_Esm_Interface.h
 *********************************************************************************************************************/
