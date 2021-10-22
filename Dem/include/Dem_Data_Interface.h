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
 *  \defgroup   Dem_Data Data
 *  \{
 *  \file       Dem_Data_Interface.h
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

#if !defined (DEM_DATA_INTERFACE_H)
#define DEM_DATA_INTERFACE_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                  /* Own subcomponent header */
/* ------------------------------------------------------------------------- */
#include "Dem_Data_Types.h"
#include "Dem_DataReportIF_Types.h"
#include "Dem_Mem_Types.h"

/* ********************************************************************************************************************
 *  SUBCOMPONENT OBJECT FUNCTION DECLARATIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \defgroup Dem_Data_Properties Properties
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
 * \defgroup Dem_Data_Private Private Methods
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
 * \defgroup Dem_Data_Public Public Methods
 * \{
 */

#if (DEM_FEATURE_NEED_PID01_CALCULATION == STD_ON)
/* ****************************************************************************
* Dem_Data_Calc_Pid01_MonitorCompleted
*****************************************************************************/
/*!
* \brief         Calculates Pid01 monitor completed value for given Readiness Group
*
* \details       Calculates Pid01 monitor completed value for given Readiness Group
*
* \param[in]     ReadinessGroup
*                OBD Readiness Group
*
* \pre           -
* \config        DEM_FEATURE_NEED_PID01_CALCULATION == STD_ON
*
* \context       TASK|ISR2
* \synchronous   TRUE
* \reentrant     TRUE
*****************************************************************************/
DEM_LOCAL FUNC(void, DEM_CODE) Dem_Data_Calc_Pid01_MonitorCompleted(
  CONST(uint8, AUTOMATIC)  ReadinessGroup
  );
#endif


#if (DEM_FEATURE_NEED_PID41_CALCULATION == STD_ON)
/* ****************************************************************************
 * Dem_Data_GetPid41
 *****************************************************************************/
/*!
 * \brief         Calculates Value of PID41
 *
 * \details       Calculates Byte B, C and D Of PID41
 *                (A = HiHi, B = HiLo, C = LoHi, D = LoLo)
 *
 * \param[out]    PID41value
 *                Pointer to PID41 data buffer
 *
 * \pre           -
 * \config        DEM_FEATURE_NEED_PID41_CALCULATION == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Data_GetPid41(
  CONSTP2VAR(uint8, AUTOMATIC, DEM_DCM_DATA)  PID41value
  );
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_FEATURE_NEED_OBD == STD_ON) && (DEM_CFG_SUPPORT_PID41 == STD_ON) && (DEM_CFG_SUPPORT_MAJOR_MONITORS == STD_OFF)
/* ****************************************************************************
 * Dem_Data_GetPid41ComprehensiveOnly
 *****************************************************************************/
/*!
 * \brief         Calculates Value of PID41
 *
 * \details       Calculates comprehensive component supported and completed
 *                Bit in Byte B
 *                (A= HiHi, B = HiLo, C = LoHi, D = LoLo)
 *
 * \param[out]    PID41value
 *                Pointer to PID41 data buffer
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_MAJOR_MONITORS == STD_ON &&
 *                DEM_FEATURE_NEED_OBD == STD_ON &&
 *                DEM_CFG_SUPPORT_PID41 == STD_ON &&
 *                DEM_CFG_SUPPORT_MAJOR_MONITORS == STD_OFF
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Data_GetPid41ComprehensiveOnly(
  CONSTP2VAR(uint8, AUTOMATIC, DEM_DCM_DATA)  PID41value
  );
#endif

#if ( (DEM_FEATURE_NEED_PID01_CALCULATION == STD_ON) || (DEM_FEATURE_NEED_PID41_CALCULATION == STD_ON) )
/* ****************************************************************************
 * Dem_Data_TestReadinessGroupCompleted
 *****************************************************************************/
/*!
 * \brief         Checks if Readiness Group is completed
 *
 * \details       Checks if Readiness Group is completed
 *
 * \param[in]     ReadinessGroup
 *                OBD Readiness Group
 * \param[in]     Pid01CompletedMask
 *                Readiness Group completed mask
 *
 * \return        TRUE
 *                Readiness group is completed
 * \return        FALSE
 *                Readiness group is not completed
 *
 * \pre           -
 * \config        DEM_FEATURE_NEED_PID01_CALCULATION == STD_ON ||
 *                DEM_FEATURE_NEED_PID41_CALCULATION == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Data_TestReadinessGroupCompleted(
  CONST(uint8, AUTOMATIC)  ReadinessGroup,
  CONST(uint32, AUTOMATIC)  Pid01CompletedMask
  );
#endif

#if ((DEM_FEATURE_NEED_PID41_CALCULATION == STD_ON) || (DEM_FEATURE_NEED_PID41_CCONLY_CALCULATION == STD_ON))
/* ****************************************************************************
 * Dem_Data_TestReadinessGroupDisabled
 *****************************************************************************/
/*!
 * \brief         Checks if Readiness Group is disabled
 *
 * \details       Checks if Readiness Group is disabled
 *
 * \param[in]     ReadinessGroup
 *                OBD Readiness Group
 *
 * \return        TRUE
 *                Readines group is disabled
 * \return        FALSE
 *                Readines group is enabled
 *
 * \pre           -
 * \config        DEM_FEATURE_NEED_PID41_CALCULATION == STD_ON ||
 *                DEM_FEATURE_NEED_PID41_CCONLY_CALCULATION == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Data_TestReadinessGroupDisabled(
  CONST(uint8, AUTOMATIC)  ReadinessGroup
  );
#endif

#if (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) && \
( (DEM_CFG_DATA_CYCLES_TESTED_SINCE_LAST_FAILED == STD_ON) || (DEM_CFG_DATA_HEALINGCTR_DOWNCNT == STD_ON) )
/* ****************************************************************************
 * Dem_Data_TestHealingCounterReadable
 *****************************************************************************/
/*!
 * \brief         Returns if the healing counter can be read.
 *
 * \details       The healing counter (corresponding to 'Cycles Tested
 *                Since Last Failed') can be read, if the event is currently
 *                healing or is already healed.
 *                In order that the counter is not reported, if the event was
 *                never tested failed, the TFSLC status bit has to be set.
 *                In order that the counter is not reported, if healing hasn't
 *                been started for the event, the PDTC status bit has to be
 *                unset (in configurations with PDTC status bit set
 *                'Stored Only' this is only secure, if the event is stored).
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 *
 * \return        TRUE
 *                The healing counter can be read.
 *                FALSE
 *                The healing counter can't be read.
 *
 * \pre           -
 * \config        DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON &&
 *                (DEM_CFG_DATA_CYCLES_TESTED_SINCE_LAST_FAILED == STD_ON ||
 *                 DEM_CFG_DATA_HEALINGCTR_DOWNCNT == STD_ON)
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Data_TestHealingCounterReadable(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  );
#endif

#if (DEM_CFG_SUPPORT_OBDII == STD_ON)                                                                                            /* COV_MSR_UNSUPPORTED XF */
/* ****************************************************************************
 * Dem_Data_PermanentEntryAdd
 *****************************************************************************/
/*!
 * \brief         Enters an event to permanent memory
 *
 * \details       If a free slot is available in the permanent memory, this
 *                function stores a permanent entry for the given event.
 *
 *                This function maps combined events to their master event, so
 *                any event can be passed.
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_OBDII == STD_ON
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Data_PermanentEntryAdd(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  );
#endif


/* ****************************************************************************
 * Dem_Data_EntryInit
 *****************************************************************************/
/*!
 * \brief         Initializes an event memory entry
 *
 * \details       Initializes an event memory entry
 *
 * \param[in]     MemoryEntryId
 *                The memory entry handle
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Data_EntryInit(
  CONST(Dem_MemoryEntry_HandleType, AUTOMATIC)  MemoryEntryId
  );

#if (DEM_FEATURE_NEED_TIME_SERIES == STD_ON)
/* ****************************************************************************
 * Dem_TimeSeriesData_EntryInit
 *****************************************************************************/
/*!
 * \brief         Initializes a time series entry
 *
 * \details       Initializes a time series entry
 *
 * \param[in]     TimeSeriesEntry
 *                Pointer to the time series entry
 *
 * \pre           -
 * \config        DEM_FEATURE_NEED_TIME_SERIES == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_TimeSeriesData_EntryInit(
  CONST(Dem_Mem_TimeSeriesEntryPtrType, AUTOMATIC)  TimeSeriesEntry
  );
#endif

#if (DEM_FEATURE_NEED_OEM_EXTENSIONS_DAG == STD_ON)                                                                              /* COV_MSR_UNSUPPORTED XF */
/* ****************************************************************************
 * Dem_Data_DagGetCurrentOdometer
 *****************************************************************************/
/*!
 * \brief         Fetches current odometer value for storage in DAG StdEnvData
 *
 * \details       Fetches current odometer value for storage in DAG StdEnvData
 *
 * \param[in]     MemoryEntryId
 *                The memory entry handle
 *
 * \pre           -
 * \config        DEM_FEATURE_NEED_OEM_EXTENSIONS_DAG == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Data_DagGetCurrentOdometer(
  CONST(Dem_MemoryEntry_HandleType, AUTOMATIC)  MemoryEntryId
  );
#endif

#if (DEM_CFG_DATA_DAG_EXTENDED_ENV_DATA == STD_ON)
/* ****************************************************************************
 * Dem_Data_DagGetOperatingTime
 *****************************************************************************/
/*!
 * \brief         Fetches the current operating time and status and stores
 *                them in DAG extended StdEnvData
 *
 * \details       Fetches the current operating time and status and stores
 *                them in DAG extended StdEnvData
 *
 * \param[in]     MemoryEntryId
 *                The memory entry handle
 *
 * \pre           -
 * \config        DEM_CFG_DATA_DAG_EXTENDED_ENV_DATA == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Data_DagGetOperatingTime(
  CONST(Dem_MemoryEntry_HandleType, AUTOMATIC)  MemoryEntryId
  );
#endif

#if (DEM_FEATURE_NEED_OEM_EXTENSIONS_DAG == STD_ON)                                                                              /* COV_MSR_UNSUPPORTED XF */
/* ****************************************************************************
 * Dem_Data_DagGetExternalTester
 *****************************************************************************/
/*!
 * \brief         Fetches the current tester present information for storage in
 *                DAG StdEnvData
 *
 * \details       Fetches the current tester present information for storage in
 *                DAG StdEnvData
 *
 * \param[out]    Buffer
 *                Pointer to the buffer to store the data
 *
 * \pre           -
 * \config        DEM_CFG_DATA_DAG_EXTENDED_ENV_DATA == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Data_DagGetExternalTester(
  CONST(Dem_SharedDataPtrType, AUTOMATIC)  Buffer
  );
#endif

#if (DEM_FEATURE_NEED_TIME_SERIES_PAST == STD_ON)
/* ****************************************************************************
 * Dem_Data_StoreTimeSeriesPastSamples
 *****************************************************************************/
/*!
 * \brief         Store past samples for given event
 *
 * \details       Store past samples for given event
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 * \param[in]     MemoryIndex
 *                Memory entry index
 *
 * \pre           time series entry allocated for event
 * \config        DEM_FEATURE_NEED_TIME_SERIES_PAST == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Data_StoreTimeSeriesPastSamples(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(Dem_Cfg_MemoryIndexType, AUTOMATIC)  MemoryIndex
  );
#endif

#if (DEM_FEATURE_NEED_TIME_SERIES_FUTURE == STD_ON)
/* ****************************************************************************
 * Dem_Data_StoreTimeSeriesFutureSamples
 *****************************************************************************/
/*!
 * \brief         Store future samples for all time series entries
 *
 * \details       Store future samples for all time series entries
 *
 * \param[in]     SampleUpdate
 *                Indicates if timers for normal or fast rate have expired
 *
 * \pre           -
 * \config        DEM_FEATURE_NEED_TIME_SERIES_FUTURE == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Data_StoreTimeSeriesFutureSamples(
  CONST(uint8, AUTOMATIC)  SampleUpdate
  );
#endif

#if (DEM_CFG_SUPPORT_TIME_SERIES_FUTURE_NORMAL == STD_ON)
/* ****************************************************************************
 * Dem_Data_StoreTimeSeriesNormalFutureSamples
 *****************************************************************************/
/*!
 * \brief         Store future normal samples for given entry
 *
 * \details       Store future normal samples for given entry
 *
 * \param[in]     Entry
 *                Time Series Entry
 * \param[in]     EntryIndex
 *                Index of Time Series Entry
 *
 * \return        TRUE
 *                Entry has changed
 * \return        FALSE
 *                Entry has not changed
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_TIME_SERIES_FUTURE_NORMAL == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Data_StoreTimeSeriesNormalFutureSamples(
  CONST(Dem_Mem_TimeSeriesEntryPtrType, AUTOMATIC)  Entry,
  CONST(uint8, AUTOMATIC)  EntryIndex
  );
#endif

#if (DEM_CFG_SUPPORT_TIME_SERIES_FUTURE_FAST == STD_ON)
/* ****************************************************************************
 * Dem_Data_StoreTimeSeriesFastFutureSamples
 *****************************************************************************/
/*!
 * \brief         Store future fast samples for given entry
 *
 * \details       Store future fast samples for given entry
 *
 * \param[in]     Entry
 *                Time Series Entry
 * \param[in]     EntryIndex
 *                Index of Time Series Entry
 *
 * \return        TRUE
 *                Entry has changed
 * \return        FALSE
 *                Entry has not changed
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_TIME_SERIES_FUTURE_FAST == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Data_StoreTimeSeriesFastFutureSamples(
  CONST(Dem_Mem_TimeSeriesEntryPtrType, AUTOMATIC)  Entry,
  CONST(uint8, AUTOMATIC)  EntryIndex
  );
#endif

#if (DEM_CFG_SUPPORT_USER_ERECS == STD_ON)
/* ****************************************************************************
 * Dem_Data_EntryUpdate_UserERecs
 *****************************************************************************/
/*!
 * \brief         Collects the user provided extended data records stored for
 *                an event entry.
 *
 * \details       Collects the user provided extended data records stored for
 *                an event entry.
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 * \param[in]     MemoryEntryId
 *                The memory entry handle
 *
 * \return        Block modification bitmask:
 *                DEM_DATA_NO_CHANGES          nothing has changed
 *                DEM_DATA_USERDATA_CHANGED    user provided data was updated
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_USER_ERECS == STD_ON
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_Data_EntryUpdate_UserERecs(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(Dem_MemoryEntry_HandleType, AUTOMATIC)  MemoryEntryId
  );
#endif

#if ((DEM_FEATURE_NEED_OEM_EXTENSIONS_VCC == STD_ON) \
 || (DEM_FEATURE_NEED_OEM_EXTENSIONS_JLR == STD_ON))
/* ****************************************************************************
 * Dem_Data_OemSRecTrigger
 *****************************************************************************/
/*!
 * \brief         Evaluates if the snapshot data needs to be updated
 *
 * \details       This function evaluates if the snapshot SRecIndex that can
 *                be stored in MemoryEntry is eligible for an update due to
 *                the status changes encoded by the trigger flags.
 *
 *                If the snapshot is not configured to update on OEM trigger,
 *                this function returns false.
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 * \param[in]     MemoryEntryId
 *                The memory entry handle
 * \param[in]     SRecIndex
 *                Index to the snapshot configuration
 * \param[in]     UpdateFlags
 *                Trigger flags
 *
 * \return        TRUE
 *                The snapshot needs updating
 * \return        FALSE
 *                The snapshot does not need updating
 *
 * \pre           -
 * \config        ((DEM_FEATURE_NEED_OEM_EXTENSIONS_VCC == STD_ON) \
 *             || (DEM_FEATURE_NEED_OEM_EXTENSIONS_JLR == STD_ON))
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Data_OemSRecTrigger(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(Dem_MemoryEntry_HandleType, AUTOMATIC)  MemoryEntryId,
  CONST(Dem_Cfg_SRecIndexType, AUTOMATIC)  SRecIndex,
  CONST(uint8, AUTOMATIC)  UpdateFlags
  );
#endif

#if (DEM_CFG_SUPPORT_SRECS == STD_ON)
/* ****************************************************************************
 * Dem_Data_EntryUpdate_SRecs
 *****************************************************************************/
/*!
 * \brief         Collect all user snapshot records for an event
 *
 * \details       This function will look for every snapshot record of the
 *                event that needs updating due to the status changes encoded
 *                by the trigger flags.
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 * \param[in]     MemoryEntryId
 *                The memory entry handle
 * \param[in]     UpdateFlags
 *                Trigger flags
 *
 * \return        Block modification bitmask:
 *                DEM_DATA_NO_CHANGES          nothing has changed
 *                DEM_DATA_USERDATA_CHANGED    user provided data was updated
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_SRECS == STD_ON
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_Data_EntryUpdate_SRecs(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(Dem_MemoryEntry_HandleType, AUTOMATIC)  MemoryEntryId,
  CONST(uint8, AUTOMATIC)  UpdateFlags
  );
#endif

#if (DEM_FEATURE_NEED_J1939_FREEZEFRAME == STD_ON)                                                                               /* COV_MSR_UNSUPPORTED XF */
/* ****************************************************************************
 * Dem_Data_EntryUpdate_J1939FF
 *****************************************************************************/
/*!
 * \brief         Collect J1939 Freeze Frame data stored for an event.
 *
 * \details       Collect J1939 Freeze Frame data stored for an event.
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 * \param[in]     MemoryEntryId
 *                The memory entry handle
 *
 * \return        Block modification bitmask:
 *                DEM_DATA_NO_CHANGES          nothing has changed
 *                DEM_DATA_USERDATA_CHANGED    user provided data was updated
 *
 * \pre           -
 * \config        DEM_FEATURE_NEED_J1939_FREEZEFRAME == STD_ON
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_Data_EntryUpdate_J1939FF(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(Dem_MemoryEntry_HandleType, AUTOMATIC)  MemoryEntryId
  );
#endif

/* ****************************************************************************
 * Dem_Data_EntryUpdate
 *****************************************************************************/
/*!
 * \brief         Updates all data stored for an event.
 *
 * \details       Depending on configuration of the event data, collect the
 *                data to be updated due to the update trigger(s) in UpdateFlags.
 *                This includes statistical data (e.g. occurrence counter) as
 *                well as environment data collected from callback routines.
 *
 *                Statistical data is stored separately in the MemoryEntry and
 *                is mapped into snapshot and extended records when reading the
 *                data.
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 * \param[in]     UpdateFlags
 *                Trigger flags
 * \param[in]     MemoryIndex
 *                Memory entry index
 *
 * \return        Block modification bitmask:
 *                DEM_DATA_NO_CHANGES, or some of
 *                DEM_DATA_USERDATA_CHANGED
 *                DEM_DATA_STATISTICS_CHANGED
 *
 * \pre           -
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_Data_EntryUpdate(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(uint8, AUTOMATIC)  UpdateFlags,
  CONST(Dem_Cfg_MemoryIndexType, AUTOMATIC)  MemoryIndex
  );

#if (DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_ERECS == STD_ON)
/* ****************************************************************************
 * Dem_Data_ERecAllDataElementsStored
 *****************************************************************************/
/*!
 * \brief         Tests if the internal data elements are stored
 *
 * \details       Tests if the internal data elements of an extended data record 
 *                are stored
 *
 * \param[in]     DidIndex
 *                Handle to DID descriptor table
 * \param[in]     ReadoutBufferId
 *                Handle to readout buffer
 *
 * \return        TRUE
 *                The data elements are stored
 * \return        FALSE
 *                The data elements are not stored
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON &&
 *                DEM_CFG_SUPPORT_ERECS == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Data_ERecAllDataElementsStored(
  CONST(Dem_Cfg_DidIndexType, AUTOMATIC)  DidIndex,
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC)  ReadoutBufferId
  );
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_FEATURE_NEED_TIME_SERIES == STD_ON)
/* ****************************************************************************
 * Dem_Data_TimeSeriesSRecCount
 *****************************************************************************/
/*!
 * \brief         Counts the number of snapshot records stored in a time series
 *                entry
 *
 * \details       Counts the number of snapshot records stored in a time series
 *                entry
 *
 * \param[in]     TimeSeriesEntry
 *                Pointer to the time series entry
 *
 * \return        Number of stored time series snapshot records
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON &&
 *                DEM_FEATURE_NEED_TIME_SERIES == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_Data_TimeSeriesSRecCount(
  CONST(Dem_Mem_ConstTimeSeriesEntryPtrType, AUTOMATIC)  TimeSeriesEntry
  );
#endif

#if (DEM_FEATURE_NEED_TIME_SERIES == STD_ON)
/* ****************************************************************************
 * Dem_Data_TimeSeriesSRecIsStored
 *****************************************************************************/
/*!
 * \brief         Tests whether a time series snapshot record is currently stored
 *
 * \details       Tests whether a time series snapshot record is currently stored
 *
 * \param[in]     TimeSeriesEntry
 *                Pointer to the time series entry
 * \param[in]     RecordNumber
 *                Snapshot record number
 *
 * \return        TRUE
 *                The record is stored
 * \return        FALSE
 *                The record is not stored
 *
 * \pre           -
 * \config        DEM_FEATURE_NEED_TIME_SERIES == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Data_TimeSeriesSRecIsStored(
  CONST(Dem_Mem_ConstTimeSeriesEntryPtrType, AUTOMATIC)  TimeSeriesEntry,
  CONST(uint8, AUTOMATIC)  RecordNumber
  );
#endif

#if (DEM_FEATURE_NEED_TIME_SERIES == STD_ON)
/* ****************************************************************************
 * Dem_Data_TimeSeriesSRecIsValid
 *****************************************************************************/
/*!
 * \brief         Tests whether a time series snapshot record number is valid
 *
 * \details       Tests whether a time series snapshot record number is valid
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 * \param[in]     RecordNumber
 *                Snapshot record number
 *
 * \return        TRUE
 *                The record number is valid
 * \return        FALSE
 *                The record number is invalid
 *
 * \pre           -
 * \config        DEM_FEATURE_NEED_TIME_SERIES == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Data_TimeSeriesSRecIsValid(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(uint8, AUTOMATIC)  RecordNumber
  );
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_FEATURE_NEED_TIME_SERIES == STD_ON)
/* ****************************************************************************
 * Dem_Data_TimeSeriesGetNextValidSRec
 *****************************************************************************/
/*!
 * \brief         Gets the next valid time series snapshot record number
 *
 * \details       Gets the next valid time series snapshot record number
 *
 * \param[in]     TimeSeriesEntry
 *                Pointer to the time series entry
 * \param[in]     RecordNumber
 *                Snapshot record number
 *
 * \return        Next valid record number larger than the given record number
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON && DEM_FEATURE_NEED_TIME_SERIES == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_Data_TimeSeriesGetNextValidSRec(
  CONST(Dem_Mem_ConstTimeSeriesEntryPtrType, AUTOMATIC)  TimeSeriesEntry,
  CONST(uint8, AUTOMATIC)  RecordNumber
  );
#endif

#if ((DEM_FEATURE_NEED_OEM_EXTENSIONS_VCC == STD_OFF) \
 && (DEM_FEATURE_NEED_CYCLE_COUNTERS == STD_ON))
/* ****************************************************************************
 * Dem_Data_EntryOpCycleStart
 *****************************************************************************/
/*!
 * \brief         Latches overflowing operation cycle counters
 *
 * \details       Latches overflowing operation cycle counters
 *
 * \param[in]     MemoryEntryId
 *                The memory entry handle
 * \param[in]     CycleCount
 *                The new cycle counter
 *
 * \return        TRUE
 *                The memory entry has been modified
 * \return        FALSE
 *                The memory entry has not been modified
 *
 * \pre           -
 * \config        DEM_FEATURE_NEED_OEM_EXTENSIONS_VCC == STD_OFF && 
 *                DEM_FEATURE_NEED_CYCLE_COUNTERS == STD_ON
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Data_EntryOpCycleStart(
  CONST(Dem_MemoryEntry_HandleType, AUTOMATIC)  MemoryEntryId,
  CONST(uint16, AUTOMATIC)  CycleCount
  );
#endif

#if (DEM_CFG_DATA_CYCLES_TESTED_SINCE_FIRST_FAILED == STD_ON) || (DEM_CFG_DATA_CONSECUTIVE_FAILED_CYCLES == STD_ON)
/* ****************************************************************************
 * Dem_Data_DtcOpCycleUpdate
 *****************************************************************************/
/*!
 * \brief         Updates operation cycle counters, if necessary
 *
 * \details       Updates operation cycle counters, if necessary
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 * \param[in]     CycleStatus
 *                Cycle status changes
 *
 * \pre           The passed event must be a master event
 * \config        DEM_CFG_DATA_CYCLES_TESTED_SINCE_FIRST_FAILED == STD_ON ||
 *                DEM_CFG_DATA_CONSECUTIVE_FAILED_CYCLES == STD_ON
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Data_DtcOpCycleUpdate(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(uint8, AUTOMATIC)  CycleStatus
  );
#endif

#if (DEM_CFG_SUPPORT_OBDII == STD_ON)                                                                                            /* COV_MSR_UNSUPPORTED XF */
/* ****************************************************************************
 * Dem_Data_TestObdIIFreezeFrameUpdates
 *****************************************************************************/
/*!
 * \brief         Test which parts of the freeze frame data need updating
 *
 * \details       This function tests if the freeze frame data must be updated,
 *                e.g. because it is not yet stored, and if the freeze frame
 *                time stamp must be updated.
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 * \param[in]     Effects
 *                Trigger flags
 * \param[in]     FreezeFrameIndex
 *                Index of the event's freeze frame
 *
 * \return        Bitcoded (ORed values)
 *                DEM_DATA_FF_UPDATE_DATA if the freeze frame data needs
 *                updating
 *                DEM_DATA_FF_UPDATE_TIMESTAMP if the timestamp needs updating
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_OBDII == STD_ON
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_Data_TestObdIIFreezeFrameUpdates(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(uint8, AUTOMATIC)  Effects,
  CONST(uint8, AUTOMATIC)  FreezeFrameIndex
  );
#endif

#if (DEM_CFG_SUPPORT_OBDII == STD_ON) && (DEM_CFG_SUPPORT_PENDING_DISPLACE_FREEZE_FRAME == STD_ON)                               /* COV_MSR_UNSUPPORTED XF xf xf */
/* ****************************************************************************
 * Dem_Data_SelectDisplacedFreezeFrameIndex
 *****************************************************************************/
/*!
 * \brief         Selects a displacable Obd Freeze Frame entry
 *
 * \details       This function checks for pending freeze frames which can be
 *                displaced by a confirmed freeze frame
 *
 * \return        Index of the displaceable entry. If no displaceable entry was
 *                found, the number of configured freeze frames will be returned.
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_OBDII == STD_ON &&
 *                DEM_CFG_SUPPORT_PENDING_DISPLACE_FREEZE_FRAME == STD_ON
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_Data_SelectDisplacedFreezeFrameIndex(
  void
  );
#endif

#if (DEM_CFG_SUPPORT_OBDII == STD_ON)                                                                                            /* COV_MSR_UNSUPPORTED XF */
/* ****************************************************************************
 * Dem_Data_EntryStore_ObdIIFreezeFrame
 *****************************************************************************/
/*!
 * \brief         Sample all PIDs of the OBD FreezeFrame
 *
 * \details       This function tries to find a freeze frame storage slot for
 *                the given event, and use that slot to capture an OBD freeze
 *                frame for that event.
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 * \param[in]     Effects
 *                Trigger flags
 *
 * \pre           The event must be an OBD relevant event
 * \config        DEM_CFG_SUPPORT_OBDII == STD_ON
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Data_EntryStore_ObdIIFreezeFrame(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(uint8, AUTOMATIC)  Effects
  );
#endif

#if (DEM_CFG_SUPPORT_WWHOBD == STD_ON)                                                                                           /* COV_MSR_UNSUPPORTED XF */
/* ****************************************************************************
 * Dem_Data_EntryStore_WwhObbdFreezeFrame
 *****************************************************************************/
/*!
 * \brief         Samples all DIDs of the WWH-OBD FreezeFrame
 *
 * \details       Samples all DIDs of the WWH-OBD FreezeFrame
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 * \param[in]     Effects
 *                Trigger flags
 * \param[in]     MemoryIndex
 *                Memory entry index
 *
 * \pre           The event must be a WWH-OBD relevant event
 * \config        DEM_CFG_SUPPORT_WWHOBD == STD_ON
 *
 * \return        Block modification bitmask:
 *                DEM_DATA_NO_CHANGES          nothing has changed
 *                DEM_DATA_USERDATA_CHANGED    user provided data was updated
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_Data_EntryStore_WwhObdFreezeFrame(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(uint8, AUTOMATIC)  Effects,
  CONST(Dem_Cfg_MemoryIndexType, AUTOMATIC)  MemoryIndex
  );
#endif

#if (DEM_CFG_SUPPORT_OBDII == STD_ON)                                                                                            /* COV_MSR_UNSUPPORTED XF */
/* ****************************************************************************
 * Dem_Data_PermanentEntryUpdate
 *****************************************************************************/
/*!
 * \brief         Processes the permanent memory state update.
 *
 * \details       This function transitions the permanent memory states at the
 *                end of a driving cycle.
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 * \param[in]     OldDtcStatus
 *                Dtc status before DCY restart
 * \param[in]     NewDtcStatus
 *                Dtc status after DCY restart
 *
 * \pre           The passed event must be a master event
 * \config        DEM_CFG_SUPPORT_OBDII == STD_ON
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Data_PermanentEntryUpdate(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(uint8, AUTOMATIC)  OldDtcStatus,
  CONST(uint8, AUTOMATIC)  NewDtcStatus
  );
#endif

#if (DEM_CFG_SUPPORT_OBDII == STD_ON)                                                                                            /* COV_MSR_UNSUPPORTED XF */
/* ****************************************************************************
 * Dem_Data_PermanentEntryClear
 *****************************************************************************/
/*!
 * \brief         Processes clearing a permanent DTC
 *
 * \details       Processes clearing a permanent DTC
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 *
 * \pre           The passed event must be a master event
 * \config        DEM_CFG_SUPPORT_OBDII == STD_ON
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Data_PermanentEntryClear(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  );
#endif

#if (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) && (DEM_CFG_DATA_AGINGCTR == STD_ON)
/* ****************************************************************************
 * Dem_Data_CopyUpwardsAgingCounter
 *****************************************************************************/
/*!
 * \brief         Retrieves the aging counter of the event holding the event
 *                memory entry as upward counting data element
 *
 * \details       Retrieves the aging counter of the event holding the event
 *                memory entry as upward counting data element
 *
 * \param[in]     CopyDidInfoPtr
 *                CopyDid context
 *
 * \return        TRUE
 *                Data was copied
 * \return        FALSE
 *                No data was copied
 *
 * \pre           -
 * \config        DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON &&
 *                DEM_CFG_DATA_AGINGCTR == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Data_CopyUpwardsAgingCounter(
  CONST(Dem_DataReportIF_CopyDidInfoPtrType, AUTOMATIC)  CopyDidInfoPtr
  );
#endif

#if (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) && (DEM_CFG_DATA_AGINGCTR_INVERTED == STD_ON)
/* ****************************************************************************
 * Dem_Data_CopyDownwardsAgingCounter
 *****************************************************************************/
/*!
 * \brief         Retrieves the aging counter of the event holding the event
 *                memory entry as downward counting data element
 *
 * \details       Retrieves the aging counter of the event holding the event
 *                memory entry as downward counting data element
 *
 * \param[in]     CopyDidInfoPtr
 *                CopyDid context
 *
 * \return        TRUE
 *                Data was copied
 * \return        FALSE
 *                No data was copied
 *
 * \pre           -
 * \config        DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON &&
 *                DEM_CFG_DATA_AGINGCTR_INVERTED == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Data_CopyDownwardsAgingCounter(
  CONST(Dem_DataReportIF_CopyDidInfoPtrType, AUTOMATIC)  CopyDidInfoPtr
  );
#endif

#if (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) && (DEM_CFG_DATA_OCCCTR == STD_ON)
/* ****************************************************************************
 * Dem_Data_Copy1ByteOccurrenceCounter
 *****************************************************************************/
/*!
 * \brief         Retrieves the occurrence counter of the event holding the
 *                event memory entry as 1 byte data element
 *
 * \details       An occurrence counter that will not fit 1 byte is written as
 *                255.
 *
 * \param[in]     CopyDidInfoPtr
 *                CopyDid context
 *
 * \return        TRUE
 *                Data was copied
 * \return        FALSE
 *                No data was copied
 *
 * \pre           -
 * \config        DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON &&
 *                DEM_CFG_DATA_OCCCTR == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Data_Copy1ByteOccurrenceCounter(
  CONST(Dem_DataReportIF_CopyDidInfoPtrType, AUTOMATIC)  CopyDidInfoPtr
  );
#endif

#if (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) && (DEM_CFG_DATA_OCCCTR_2BYTE == STD_ON)
/* ****************************************************************************
 * Dem_Data_Copy2ByteOccurrenceCounter
 *****************************************************************************/
/*!
 * \brief         Retrieves the occurrence counter of the event holding the
 *                event memory entry as 2 byte data element
 *
 * \details       Retrieves the occurrence counter of the event holding the
 *                event memory entry as 2 byte data element
 *
 * \param[in]     CopyDidInfoPtr
 *                CopyDid context
 *
 * \return        TRUE
 *                Data was copied
 * \return        FALSE
 *                No data was copied
 *
 * \pre           -
 * \config        DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON &&
 *                DEM_CFG_DATA_OCCCTR_2BYTE == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Data_Copy2ByteOccurrenceCounter(
  CONST(Dem_DataReportIF_CopyDidInfoPtrType, AUTOMATIC)  CopyDidInfoPtr
  );
#endif

#if (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) && (DEM_CFG_DATA_OVFLIND == STD_ON)
/* ****************************************************************************
 * Dem_Data_CopyOverflowIndication
 *****************************************************************************/
/*!
 * \brief         Retrieves the event memory overflow state as 1 byte data
 *                element
 *
 * \details       Retrieves the event memory overflow state as 1 byte data
 *                element
 *
 * \param[in]     CopyDidInfoPtr
 *                CopyDid context
 *
 * \return        TRUE
 *                Data was copied
 * \return        FALSE
 *                No data was copied
 *
 * \pre           -
 * \config        DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON &&
 *                DEM_CFG_DATA_OVFLIND == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Data_CopyOverflowIndication(
  CONST(Dem_DataReportIF_CopyDidInfoPtrType, AUTOMATIC)  CopyDidInfoPtr
  );
#endif

#if (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) && (DEM_CFG_DATA_SIGNIFICANCE == STD_ON)
/* ****************************************************************************
 * Dem_Data_CopyEventSignificance
 *****************************************************************************/
/*!
 * \brief         Retrieves the significance configuration of the event holding
 *                the event memory entry as 1 byte data element
 *
 * \details       Retrieves the significance configuration of the event holding
 *                the event memory entry as 1 byte data element
 *
 * \param[in]     CopyDidInfoPtr
 *                CopyDid context
 *
 * \return        TRUE
 *                Data was copied
 * \return        FALSE
 *                No data was copied
 *
 * \pre           -
 * \config        DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON &&
 *                DEM_CFG_DATA_SIGNIFICANCE == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Data_CopyEventSignificance(
  CONST(Dem_DataReportIF_CopyDidInfoPtrType, AUTOMATIC)  CopyDidInfoPtr
  );
#endif

#if (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) && (DEM_CFG_DATA_PRIORITY == STD_ON)
/* ****************************************************************************
 * Dem_Data_CopyEventPriority
 *****************************************************************************/
/*!
 * \brief         Retrieves the priority configuration of the event holding
 *                the event memory entry as 1 byte data element
 *
 * \details       Retrieves the priority configuration of the event holding
 *                the event memory entry as 1 byte data element.
 *
 * \param[in]     CopyDidInfoPtr
 *                CopyDid context
 *
 * \return        TRUE
 *                Data was copied
 * \return        FALSE
 *                No data was copied
 *
 * \pre           -
 * \config        DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON &&
 *                DEM_CFG_DATA_PRIORITY == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Data_CopyEventPriority(
  CONST(Dem_DataReportIF_CopyDidInfoPtrType, AUTOMATIC)  CopyDidInfoPtr
  );
#endif

#if (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) && (DEM_CFG_DATA_MAX_FDC_SINCE_LAST_CLEAR == STD_ON)
/* ****************************************************************************
 * Dem_Data_CopyMaxFdcSinceLastClear
 *****************************************************************************/
/*!
 * \brief         Retrieves the maximum fault detection counter since last
 *                clear of the event holding the event memory entry as 1 byte
 *                data element
 *
 * \details       Retrieves the maximum fault detection counter since last
 *                clear of the event holding the event memory entry as 1 byte
 *                data element.
 *
 * \param[in]     CopyDidInfoPtr
 *                CopyDid context
 *
 * \return        TRUE
 *                Data was copied
 * \return        FALSE
 *                No data was copied
 *
 * \pre           -
 * \config        DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON &&
 *                DEM_CFG_DATA_MAX_FDC_SINCE_LAST_CLEAR == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Data_CopyMaxFdcSinceLastClear(
  CONST(Dem_DataReportIF_CopyDidInfoPtrType, AUTOMATIC)  CopyDidInfoPtr
  );
#endif

#if (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) && (DEM_CFG_DATA_MAX_FDC_DURING_CURRENT_CYCLE == STD_ON)
/* ****************************************************************************
 * Dem_Data_CopyMaxFdcThisCycle
 *****************************************************************************/
/*!
 * \brief         Retrieves the maximum fault detection counter this cycle
 *                of the event holding the event memory entry as 1 byte data
 *                element
 *
 * \details       Retrieves the maximum fault detection counter this cycle
 *                of the event holding the event memory entry as 1 byte data
 *                element
 *
 * \param[in]     CopyDidInfoPtr
 *                CopyDid context
 *
 * \return        TRUE
 *                Data was copied
 * \return        FALSE
 *                No data was copied
 *
 * \pre           -
 * \config        DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON &&
 *                DEM_CFG_DATA_MAX_FDC_DURING_CURRENT_CYCLE == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Data_CopyMaxFdcThisCycle(
  CONST(Dem_DataReportIF_CopyDidInfoPtrType, AUTOMATIC)  CopyDidInfoPtr
  );
#endif

#if (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) && (DEM_CFG_DATA_CYCLES_SINCE_LAST_FAILED == STD_ON)
/* ****************************************************************************
 * Dem_Data_CopyCyclesSinceLastFailed
 *****************************************************************************/
/*!
 * \brief         Retrieves the cycle count since last failed of the event
 *                holding the event memory entry as 1 byte data element
 *
 * \details       Retrieves the cycle count since last failed of the event
 *                holding the event memory entry as 1 byte data element
 *
 * \param[in]     CopyDidInfoPtr
 *                CopyDid context
 *
 * \return        TRUE
 *                Data was copied
 * \return        FALSE
 *                No data was copied
 *
 * \pre           -
 * \config        DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON &&
 *                DEM_CFG_DATA_CYCLES_SINCE_LAST_FAILED == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Data_CopyCyclesSinceLastFailed(
  CONST(Dem_DataReportIF_CopyDidInfoPtrType, AUTOMATIC)  CopyDidInfoPtr
  );
#endif

#if (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) && (DEM_CFG_DATA_CYCLES_SINCE_FIRST_FAILED == STD_ON)
/* ****************************************************************************
 * Dem_Data_CopyCyclesSinceFirstFailed
 *****************************************************************************/
/*!
 * \brief         Retrieves the cycle count since first failed of the event
 *                holding the event memory entry as 1 byte data element
 *
 * \details       Retrieves the cycle count since first failed of the event
 *                holding the event memory entry as 1 byte data element
 *
 * \param[in]     CopyDidInfoPtr
 *                CopyDid context
 *
 * \return        TRUE
 *                Data was copied
 * \return        FALSE
 *                No data was copied
 *
 * \pre           -
 * \config        DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON &&
 *                DEM_CFG_DATA_CYCLES_SINCE_FIRST_FAILED == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Data_CopyCyclesSinceFirstFailed(
  CONST(Dem_DataReportIF_CopyDidInfoPtrType, AUTOMATIC)  CopyDidInfoPtr
  );
#endif

#if (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) && (DEM_CFG_DATA_FAILED_CYCLES == STD_ON)
/* ****************************************************************************
 * Dem_Data_CopyFailedCycles
 *****************************************************************************/
/*!
 * \brief         Retrieves the number of cycles tested failed of the event
 *                holding the event memory entry as 1 byte data element
 *
 * \details       Retrieves the number of cycles tested failed of the event
 *                holding the event memory entry as 1 byte data element
 *
 * \param[in]     CopyDidInfoPtr
 *                CopyDid context
 *
 * \return        TRUE
 *                Data was copied
 * \return        FALSE
 *                No data was copied
 *
 * \pre           -
 * \config        DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON &&
 *                DEM_CFG_DATA_FAILED_CYCLES == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Data_CopyFailedCycles(
  CONST(Dem_DataReportIF_CopyDidInfoPtrType, AUTOMATIC)  CopyDidInfoPtr
  );
#endif

#if (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) && (DEM_CFG_DATA_CONSECUTIVE_FAILED_CYCLES == STD_ON)
/* ****************************************************************************
 * Dem_Data_CopyConsecutiveFailedCycles
 *****************************************************************************/
/*!
 * \brief         Retrieves the number of consecutive cycles tested failed of
 *                the event holding the event memory entry as 1 byte data element
 *
 * \details       Retrieves the number of consecutive cycles tested failed of
 *                the event holding the event memory entry as 1 byte data element
 *
 * \param[in]     CopyDidInfoPtr
 *                CopyDid context
 *
 * \return        TRUE
 *                Data was copied
 * \return        FALSE
 *                No data was copied
 *
 * \pre           -
 * \config        DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON &&
 *                DEM_CFG_DATA_CONSECUTIVE_FAILED_CYCLES == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Data_CopyConsecutiveFailedCycles(
  CONST(Dem_DataReportIF_CopyDidInfoPtrType, AUTOMATIC)  CopyDidInfoPtr
  );
#endif

#if (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) && (DEM_CFG_DATA_CYCLES_TESTED_SINCE_FIRST_FAILED == STD_ON)
/* ****************************************************************************
 * Dem_Data_CopyCyclesTestedSinceFirstFailed
 *****************************************************************************/
/*!
 * \brief         Retrieves the number of cycles tested since first failed of
 *                the event holding the event memory entry as 1 byte data element
 *
 * \details       Retrieves the number of cycles tested since first failed of
 *                the event holding the event memory entry as 1 byte data element
 *
 * \param[in]     CopyDidInfoPtr
 *                CopyDid context
 *
 * \return        TRUE
 *                Data was copied
 * \return        FALSE
 *                No data was copied
 *
 * \pre           -
 * \config        DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON &&
 *                DEM_CFG_DATA_CYCLES_TESTED_SINCE_FIRST_FAILED == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Data_CopyCyclesTestedSinceFirstFailed(
  CONST(Dem_DataReportIF_CopyDidInfoPtrType, AUTOMATIC)  CopyDidInfoPtr
  );
#endif

#if (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) && (DEM_CFG_DATA_CYCLES_TESTED_SINCE_LAST_FAILED == STD_ON)
/* ****************************************************************************
 * Dem_Data_CopyCyclesTestedSinceLastFailed
 *****************************************************************************/
/*!
 * \brief         Retrieves the number of cycles tested since last failed of
 *                the event holding the event memory entry as 1 byte data element
 *
 * \details       Retrieves the number of cycles tested since last failed of
 *                the event holding the event memory entry as 1 byte data element
 *
 * \param[in]     CopyDidInfoPtr
 *                CopyDid context
 *
 * \return        TRUE
 *                Data was copied
 * \return        FALSE
 *                No data was copied
 *
 * \pre           -
 * \config        DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON &&
 *                DEM_CFG_DATA_CYCLES_TESTED_SINCE_LAST_FAILED == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Data_CopyCyclesTestedSinceLastFailed(
  CONST(Dem_DataReportIF_CopyDidInfoPtrType, AUTOMATIC)  CopyDidInfoPtr
  );
#endif

#if (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) && (DEM_CFG_DATA_HEALINGCTR_DOWNCNT == STD_ON)
/* ****************************************************************************
 * Dem_Data_CopyHealingCounterDownwards
 *****************************************************************************/
/*!
 * \brief         Retrieves the inverted healing counter of the event holding 
 *                the event memory entry as 1 byte data element
 *
 * \details       Retrieves the inverted healing counter of the event holding 
 *                the event memory entry as 1 byte data element
 *
 * \param[in]     CopyDidInfoPtr
 *                CopyDid context
 *
 * \return        TRUE
 *                Data was copied
 * \return        FALSE
 *                No data was copied
 *
 * \pre           -
 * \config        DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON &&
 *                DEM_CFG_DATA_HEALINGCTR_DOWNCNT == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Data_CopyHealingCounterDownwards(
  CONST(Dem_DataReportIF_CopyDidInfoPtrType, AUTOMATIC)  CopyDidInfoPtr
  );
#endif

#if (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) && (DEM_CFG_DATA_ROOTCAUSE_EVENTID == STD_ON)
/* ****************************************************************************
 * Dem_Data_CopyRootCauseEventId
 *****************************************************************************/
/*!
 * \brief         Retrieves the event that caused event memory storage as
 *                2 byte data element
 *
 * \details       Retrieves the event that caused event memory storage as
 *                2 byte data element. For combined events, this is the exact
 *                sub-event.
 *
 * \param[in]     CopyDidInfoPtr
 *                CopyDid context
 *
 * \return        TRUE
 *                Data was copied
 * \return        FALSE
 *                No data was copied
 *
 * \pre           -
 * \config        DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON &&
 *                DEM_CFG_DATA_ROOTCAUSE_EVENTID == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Data_CopyRootCauseEventId(
  CONST(Dem_DataReportIF_CopyDidInfoPtrType, AUTOMATIC)  CopyDidInfoPtr
  );
#endif

#if (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) && (DEM_CFG_DATA_OBDDTC == STD_ON)
/* ****************************************************************************
 * Dem_Data_CopyEventObdDtc
 *****************************************************************************/
/*!
 * \brief         Retrieves the OBD DTC number of the event that stored the
 *                event memory entry as 2 byte data element
 *
 * \details       Retrieves the OBD DTC number of the event that stored the
 *                event memory entry as 2 byte data element
 *
 * \param[in]     CopyDidInfoPtr
 *                CopyDid context
 *
 * \return        TRUE
 *                Data was copied
 * \return        FALSE
 *                No data was copied
 *
 * \pre           -
 * \config        DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON &&
 *                DEM_CFG_DATA_OBDDTC == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Data_CopyEventObdDtc(
  CONST(Dem_DataReportIF_CopyDidInfoPtrType, AUTOMATIC)  CopyDidInfoPtr
  );
#endif

#if (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) && (DEM_CFG_DATA_OBDDTC_3BYTE == STD_ON)
/* ****************************************************************************
 * Dem_Data_CopyEventObdDtc_3Byte
 *****************************************************************************/
/*!
 * \brief         Retrieves the OBD DTC number of the event that stored the
 *                event memory entry as 3 byte data element with trailing 0
 *
 * \details       Retrieves the OBD DTC number of the event that stored the
 *                event memory entry as 3 byte data element with trailing 0
 *
 * \param[in]     CopyDidInfoPtr
 *                CopyDid context
 *
 * \return        TRUE
 *                Data was copied
 * \return        FALSE
 *                No data was copied
 *
 * \pre           -
 * \config        DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON &&
 *                DEM_CFG_DATA_OBDDTC_3BYTE == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Data_CopyEventObdDtc_3Byte(
  CONST(Dem_DataReportIF_CopyDidInfoPtrType, AUTOMATIC)  CopyDidInfoPtr
  );
#endif

#if (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) && (DEM_CFG_DATA_OBD_RATIO == STD_ON)
/* ****************************************************************************
 * Dem_Data_CopyEventObdRatio
 *****************************************************************************/
/*!
 * \brief         Retrieves the the ratio/IUMPR attached to the event
 *
 * \details       If ratio availabe copies
 *                [NumeratorHighByte] [NumeratorLowByte] [DenominatorHighByte] [DenominatorLowByte]
 *                If ratio is not available copies
 *                [0x00] [0x00] [0x00] [0x00]
 *
 * \param[in]     CopyDidInfoPtr
 *                CopyDid context
 *
 * \return        TRUE
 *                Data was copied
 * \return        FALSE
 *                No data was copied
 *
 * \pre           -
 * \config        DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON &&
 *                DEM_CFG_DATA_OBD_RATIO == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Data_CopyEventObdRatio(
  CONST(Dem_DataReportIF_CopyDidInfoPtrType, AUTOMATIC)  CopyDidInfoPtr
  );
#endif

#if (DEM_FEATURE_NEED_OEM_EXTENSIONS_VCC == STD_ON)
/* ****************************************************************************
 * Dem_Data_CopyCyclesSinceLastUnconfirmed
 *****************************************************************************/
/*!
 * \brief         Retrieves the number of cycles since the last fdc threshold
 *                was exceeded.
 *
 * \details       Retrieves the number of cycles since the last fdc threshold
 *                was exceeded, of the event holding the event memory entry.
 *                The value is encoded as 1 byte data element
 *
 * \param[in]     CopyDidInfoPtr
 *                CopyDid context
 *
 * \return        TRUE
 *                Data was copied
 * \return        FALSE
 *                No data was copied
 *
 * \pre           -
 * \config        DEM_FEATURE_NEED_OEM_EXTENSIONS_VCC == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Data_CopyCyclesSinceLastUnconfirmed(
  CONST(Dem_DataReportIF_CopyDidInfoPtrType, AUTOMATIC)  CopyDidInfoPtr
  );
#endif

#if (DEM_FEATURE_NEED_OEM_EXTENSIONS_VCC == STD_ON)
/* ****************************************************************************
 * Dem_Data_CopyCyclesPassedSinceLastUnconfirmed
 *****************************************************************************/
/*!
 * \brief         Retrieves the number of cycles tested passed since the last
 *                fdc threshold was exceeded.
 *
 * \details       Retrieves the number of cycles tested passed since the last
 *                fdc threshold was exceeded, of the event holding the event
 *                memory entry.
 *                The value is encoded as 1 byte data element
 *
 * \param[in]     CopyDidInfoPtr
 *                CopyDid context
 *
 * \return        TRUE
 *                Data was copied
 * \return        FALSE
 *                No data was copied
 *
 * \pre           -
 * \config        DEM_FEATURE_NEED_OEM_EXTENSIONS_VCC == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Data_CopyCyclesPassedSinceLastUnconfirmed(
  CONST(Dem_DataReportIF_CopyDidInfoPtrType, AUTOMATIC)  CopyDidInfoPtr
  );
#endif

#if (DEM_FEATURE_NEED_OEM_EXTENSIONS_VCC == STD_ON)
/* ****************************************************************************
 * Dem_Data_CopyCyclesSinceFirstUnconfirmed
 *****************************************************************************/
/*!
 * \brief         Retrieves the number of cycles since the first fdc threshold
 *                was exceeded.
 *
 * \details       Retrieves the number of cycles since the first fdc threshold
 *                was exceeded, of the event holding the event memory entry.
 *                The value is encoded as 1 byte data element
 *
 * \param[in]     CopyDidInfoPtr
 *                CopyDid context
 *
 * \return        TRUE
 *                Data was copied
 * \return        FALSE
 *                No data was copied
 *
 * \pre           -
 * \config        DEM_FEATURE_NEED_OEM_EXTENSIONS_VCC == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Data_CopyCyclesSinceFirstUnconfirmed(
  CONST(Dem_DataReportIF_CopyDidInfoPtrType, AUTOMATIC)  CopyDidInfoPtr
  );
#endif

#if (DEM_FEATURE_NEED_OEM_EXTENSIONS_VCC == STD_ON)
/* ****************************************************************************
 * Dem_Data_CopyUnconfirmedCycles
 *****************************************************************************/
/*!
 * \brief         Retrieves the number of cycles in which the fdc threshold was
 *                exceeded.
 *
 * \details       Retrieves the number of cycles in which the fdc threshold was
 *                exceeded, of the event holding the event memory entry.
 *                The value is encoded as 1 byte data element
 *
 * \param[in]     CopyDidInfoPtr
 *                CopyDid context
 *
 * \return        TRUE
 *                Data was copied
 * \return        FALSE
 *                No data was copied
 *
 * \pre           -
 * \config        DEM_FEATURE_NEED_OEM_EXTENSIONS_VCC == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Data_CopyUnconfirmedCycles(
  CONST(Dem_DataReportIF_CopyDidInfoPtrType, AUTOMATIC)  CopyDidInfoPtr
  );
#endif

#if (DEM_FEATURE_NEED_OEM_EXTENSIONS_VCC == STD_ON)
/* ****************************************************************************
 * Dem_Data_CopyCyclesPassedOrUnconfirmed
 *****************************************************************************/
/*!
 * \brief         Retrieves the number of cycles in which the fdc threshold was
 *                exceeded, or a passed result was reported.
 *
 * \details       Retrieves the number of cycles in which the fdc threshold was
 *                exceeded, or a passed result was reported, of the event
 *                holding the event memory entry.
 *                The value is encoded as 1 byte data element
 *
 * \param[in]     CopyDidInfoPtr
 *                CopyDid context
 *
 * \return        TRUE
 *                Data was copied
 * \return        FALSE
 *                No data was copied
 *
 * \pre           -
 * \config        DEM_FEATURE_NEED_OEM_EXTENSIONS_VCC == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Data_CopyCyclesPassedOrUnconfirmed(
  CONST(Dem_DataReportIF_CopyDidInfoPtrType, AUTOMATIC)  CopyDidInfoPtr
  );
#endif

#if (DEM_FEATURE_NEED_OEM_EXTENSIONS_VCC == STD_ON)
/* ****************************************************************************
 * Dem_Data_CopyPreConfirmedStatus
 *****************************************************************************/
/*!
 * \brief         Retrieves the preconfirmed status byte of the event holding
 *                the event memory entry as 1 byte data element
 *
 * \details       Retrieves the preconfirmed status byte of the event holding
 *                the event memory entry as 1 byte data element
 *
 * \param[in]     CopyDidInfoPtr
 *                CopyDid context
 *
 * \return        TRUE
 *                Data was copied
 * \return        FALSE
 *                No data was copied
 *
 * \pre           -
 * \config        DEM_FEATURE_NEED_OEM_EXTENSIONS_VCC == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Data_CopyPreConfirmedStatus(
  CONST(Dem_DataReportIF_CopyDidInfoPtrType, AUTOMATIC)  CopyDidInfoPtr
  );
#endif

#if (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) && (DEM_CFG_DATA_CURRENT_FDC == STD_ON)
/* ****************************************************************************
 * Dem_Data_CopyCurrentFdc
 *****************************************************************************/
/*!
 * \brief         Retrieves the current fault detection counter of the event
 *                holding the event memory entry as 1 byte data element
 *
 * \details       Retrieves the current fault detection counter of the event
 *                holding the event memory entry as 1 byte data element
 *
 * \param[in]     CopyDidInfoPtr
 *                CopyDid context
 *
 * \return        TRUE
 *                Data was copied
 * \return        FALSE
 *                No data was copied
 *
 * \pre           -
 * \config        DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON &&
 *                DEM_CFG_DATA_CURRENT_FDC == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Data_CopyCurrentFdc(
  CONST(Dem_DataReportIF_CopyDidInfoPtrType, AUTOMATIC)  CopyDidInfoPtr
  );
#endif

#if ((DEM_CFG_SUPPORT_ERECS == STD_ON) || (DEM_CFG_SUPPORT_SRECS == STD_ON))
/* ****************************************************************************
 * Dem_Data_CopyStandardEnvData_Dag
 *****************************************************************************/
/*!
 * \brief         Writes a Daimler standard environment data object as 7 byte
 *                data element
 *
 * \details       Writes a Daimler standard environment data object as 7 byte
 *                data element
 *
 * \param[in]     CopyDidInfoPtr
 *                CopyDid context
 *
 * \return        TRUE
 *                Data was copied
 * \return        FALSE
 *                No data was copied
 *
 * \pre           -
 * \config        ( DEM_CFG_SUPPORT_ERECS == STD_ON ||
 *                  DEM_CFG_SUPPORT_SRECS == STD_ON )
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Data_CopyStandardEnvData_Dag(
  CONST(Dem_DataReportIF_CopyDidInfoPtrType, AUTOMATIC)  CopyDidInfoPtr
  );
#endif

#if ((DEM_CFG_SUPPORT_ERECS == STD_ON) || (DEM_CFG_SUPPORT_SRECS == STD_ON)) && (DEM_CFG_DATA_DAG_EXTENDED_ENV_DATA == STD_ON)
/* ****************************************************************************
 * Dem_Data_CopyExtendedEnvData_Dag
 *****************************************************************************/
/*!
 * \brief         Writes a Daimler standard environment data object and
 *                operating time as 12 byte data element
 *
 * \details       Writes a Daimler standard environment data object and
 *                operating time as 12 byte data element
 *
 * \param[in]     CopyDidInfoPtr
 *                CopyDid context
 *
 * \return        TRUE
 *                Data was copied
 * \return        FALSE
 *                No data was copied
 *
 * \pre           -
 * \config        ( DEM_CFG_SUPPORT_ERECS == STD_ON ||
 *                  DEM_CFG_SUPPORT_SRECS == STD_ON ) &&
 *                DEM_CFG_DATA_DAG_EXTENDED_ENV_DATA == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Data_CopyExtendedEnvData_Dag(
  CONST(Dem_DataReportIF_CopyDidInfoPtrType, AUTOMATIC)  CopyDidInfoPtr
  );
#endif

#if (DEM_CFG_SUPPORT_OBDII == STD_ON)                                                                                            /* COV_MSR_UNSUPPORTED XF */
/* ****************************************************************************
 * Dem_Data_PermanentEntryRemove
 *****************************************************************************/
/*!
 * \brief         Frees a permanent memory index
 *
 * \details       Frees a permanent memory index
 *
 * \param[in]     PermanentIndex
 *                Index of a permanent entry
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_OBDII == STD_ON
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL FUNC(void, DEM_CODE)
Dem_Data_PermanentEntryRemove(
  CONST(uint8, AUTOMATIC)  PermanentIndex
  );
#endif

#if (DEM_CFG_SUPPORT_OBDII == STD_ON)                                                                                            /* COV_MSR_UNSUPPORTED XF */
/* ****************************************************************************
 * Dem_Data_PermanentEntryFind
 *****************************************************************************/
/*!
 * \brief         Searches an eventId in the permanent memory
 *
 * \details       Searches an eventId in the permanent memory
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 *
 * \return        Index of the permanent entry used by the event. If no entry
 *                is found, Dem_Cfg_GlobalPermanentMaxCount() is returned.
 *
 * \pre           The passed event must be a master event
 * \config        DEM_CFG_SUPPORT_OBDII == STD_ON
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL FUNC(uint8, DEM_CODE)
Dem_Data_PermanentEntryFind(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  );
#endif

#if (DEM_CFG_SUPPORT_OBDII == STD_ON)                                                                                            /* COV_MSR_UNSUPPORTED XF */
/* ****************************************************************************
 * Dem_Data_PermanentEntryFillUp
 *****************************************************************************/
/*!
 * \brief         Fills up the permanent memory after healing some entries
 *
 * \details       This function checks for OBD relevant DTCs that currently
 *                trigger the MIL but are not stored in permanent memory. Up to
 *                all empty permanent slots are filled with such events.
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_OBDII == STD_ON
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL FUNC(void, DEM_CODE)
Dem_Data_PermanentEntryFillUp(
  void
  );
#endif

#if (DEM_FEATURE_NEED_OBD_ODOMETER == STD_ON)                                                                                    /* COV_MSR_UNSUPPORTED XF */
/* ****************************************************************************
 * Dem_Data_GetObdOdometer
 *****************************************************************************/
/*!
 * \brief         Requests the OBD Odometer from application and composes the
 *                returned data into an uint32 element.
 *
 * \details       Requests the OBD Odometer from application and composes the
 *                returned data into an uint32 element.
 *
 * \param[out]    Odometer
 *                Pointer to receive the value
 *
 * \return        E_OK
 *                An odometer value was successfully retrieved.
 * \return        E_NOT_OK
 *                No odometer could be retrieved. The Odometer parameter is
 *                initialized to 0.
 *
 * \pre           RTE is started (if using RTE)
 * \config        DEM_FEATURE_NEED_OBD_ODOMETER == STD_ON
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL FUNC(Std_ReturnType, DEM_CODE)
Dem_Data_GetObdOdometer(
  CONSTP2VAR(uint32, AUTOMATIC, DEM_VAR_NOINIT)  Odometer
  );
#endif

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* DEM_DATA_INTERFACE_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_Data_Interface.h
 *********************************************************************************************************************/
