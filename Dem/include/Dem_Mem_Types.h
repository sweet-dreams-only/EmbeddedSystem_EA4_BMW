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
/*! \addtogroup Dem_Mem
 *  \{
 *  \file       Dem_Mem_Types.h
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

#if !defined (DEM_MEM_TYPES_H)
#define DEM_MEM_TYPES_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                  /* Own subcomponent header */
/* ------------------------------------------------------------------------- */
#include "Dem_Int.h"

/* ********************************************************************************************************************
 *  SUBCOMPONENT CONSTANT MACROS
 *********************************************************************************************************************/
/*! Aging counter threshold for PID aging */
#define DEM_MEM_PID_AGING_COUNTER_THRESHOLD      0x28U


/* ********************************************************************************************************************
 *  SUBCOMPONENT FUNCTION MACROS
 *********************************************************************************************************************/

/* Entry->State currently used bits: 0x89 */
/*! Get qualified DTC states of memory entry status byte */
#define DEM_MEM_GET_QUALIFIED_MASK(Reg)          ((uint8)((Reg) | 0x77U)) /* Returns a mask, hence the | operator */             /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set qualified DTC states of memory entry status byte */
#define DEM_MEM_SET_QUALIFIED_MASK(Reg, Mask)    ((uint8)(((Reg) & 0x77U) | ((Mask) & 0x88U)))                                   /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Test aging only state of memory entry status byte */
#define DEM_MEM_TEST_AGING_ONLY(State)           ((uint8)((State) & 0x01U))                                                      /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set aging only state of memory entry status byte */
#define DEM_MEM_SET_AGING_ONLY(State)            ((uint8)((State) | 0x01U))                                                      /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Reset aging only state of memory entry status byte */
#define DEM_MEM_RESET_AGING_ONLY(State)          ((uint8)((State) & 0xfeU))                                                      /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Initial transaction number of NV transaction state  */
#define DEM_MEM_INIT_COMMIT_NUMBER               (0x00U)
/*! Test commit started state of NV transaction state */
#define DEM_MEM_TEST_COMMIT_STARTED(State)       ((uint8)((State) & 0x80U))                                                      /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set commit started state of NV transaction state */
#define DEM_MEM_SET_COMMIT_STARTED(State)        ((uint8)((State) | 0x80U))                                                      /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set commit finished state of NV transaction state */
#define DEM_MEM_SET_COMMIT_FINISHED(State)       ((uint8)(((State) + 1) & 0x7fU))                                                /* PRQA S 3453 */ /* MD_MSR_19.7 */

#if (DEM_FEATURE_NEED_OVFLIND == STD_ON)
/*! Get memory overflow state */
# define Dem_Mem_GetMemoryOverflow()             (Dem_Cfg_AdminData.MemoryOverflow)                                              /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set memory overflow state */
# define Dem_Mem_SetMemoryOverflow(Value)        (Dem_Cfg_AdminData.MemoryOverflow = (Value))                                    /* PRQA S 3453 */ /* MD_MSR_19.7 */
#endif

#if ((DEM_FEATURE_NEED_PID41_CALCULATION == STD_ON) || (DEM_FEATURE_NEED_PID41_CCONLY_CALCULATION == STD_ON))
/*! Get the PID41 disabled mask state */
# define Dem_Mem_GetPid41DisabledMask()          (Dem_Cfg_AdminData.Pid41DisabledMask)                                           /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set the PID41 disabled mask state */
# define Dem_Mem_SetPid41DisabledMask(Value)     (Dem_Cfg_AdminData.Pid41DisabledMask = (Value))                                 /* PRQA S 3453 */ /* MD_MSR_19.7 */
#endif

#if (DEM_FEATURE_NEED_PID01_CALCULATION == STD_ON)
/*! Get the PID01 completed mask state */
# define Dem_Mem_GetPid01CompletedMask()         (Dem_Cfg_StatusData.Pid01CompletedMask)                                          /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set the PID01 completed mask state */
# define Dem_Mem_SetPid01CompletedMask(Value)    (Dem_Cfg_StatusData.Pid01CompletedMask = (Value))                                /* PRQA S 3453 */ /* MD_MSR_19.7 */
#endif

/* Event Memory */
/*! Get EventId of a memory entry */
#define Dem_Mem_EntryGetEventId(Entry)           ((Entry)->EventId)                                                              /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set EventId of a memory entry */
#define Dem_Mem_EntrySetEventId(Entry, Id)       (Entry)->EventId = (Id)                                                         /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Get TimeStamp of a memory entry */
#define Dem_Mem_EntryGetTimestamp(Entry)         ((Entry)->Timestamp)                                                            /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set TimeStamp of a memory entry */
#define Dem_Mem_EntrySetTimestamp(Entry, Time)   (Entry)->Timestamp = (Time)                                                     /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Get first failed event */
#define Dem_Mem_GetFirstFailedEvent()            (Dem_Cfg_StatusData.FirstFailedEvent)                                           /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set first failed event */
#define Dem_Mem_SetFirstFailedEvent(EventId)     (Dem_Cfg_StatusData.FirstFailedEvent = (EventId))                               /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Get first confirmed event */
#define Dem_Mem_GetFirstConfirmedEvent()         (Dem_Cfg_StatusData.FirstConfirmedEvent)                                        /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set first confirmed event */
#define Dem_Mem_SetFirstConfirmedEvent(EventId)  (Dem_Cfg_StatusData.FirstConfirmedEvent = (EventId))                            /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Get most recent failed event */
#define Dem_Mem_GetMostRecentFailedEvent()       (Dem_Cfg_StatusData.MostRecentFailedEvent)                                      /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set most recent failed event */
#define Dem_Mem_SetMostRecentFailedEvent(EventId)  (Dem_Cfg_StatusData.MostRecentFailedEvent = (EventId))                        /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Get most recent confirmed event */
#define Dem_Mem_GetMostRecentConfmdEvent()       (Dem_Cfg_StatusData.MostRecentConfmdEvent)                                      /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set most recent confirmed event */
#define Dem_Mem_SetMostRecentConfmdEvent(EventId)  (Dem_Cfg_StatusData.MostRecentConfmdEvent = (EventId))                        /* PRQA S 3453 */ /* MD_MSR_19.7 */

#if (DEM_FEATURE_NEED_TIME_SERIES == STD_ON)
/*! Get unused past normal samples of a time series entry */
# define Dem_Mem_GetUnusedPastSamplesNormal(Entry)       ((Entry)->UnusedPastSamples_NormalRate)                                 /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set unused past normal samples of a time series entry */
# define Dem_Mem_SetUnusedPastSamplesNormal(Entry, Nr)   (Entry)->UnusedPastSamples_NormalRate = (Nr)                            /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Get unused past fast samples of a time series entry */
# define Dem_Mem_GetUnusedPastSamplesFast(Entry)         ((Entry)->UnusedPastSamples_FastRate)                                   /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set unused past fast samples of a time series entry */
# define Dem_Mem_SetUnusedPastSamplesFast(Entry, Nr)     (Entry)->UnusedPastSamples_FastRate = (Nr)                              /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Get unused future normal samples of a time series entry */
# define Dem_Mem_GetUnusedFutureSamplesNormal(Entry)     ((Entry)->UnusedFutureSamples_NormalRate)                               /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set unused future normal samples of a time series entry */
# define Dem_Mem_SetUnusedFutureSamplesNormal(Entry, Nr) (Entry)->UnusedFutureSamples_NormalRate = (Nr)                          /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Get unused future fast samples of a time series entry */
# define Dem_Mem_GetUnusedFutureSamplesFast(Entry)       ((Entry)->UnusedFutureSamples_FastRate)                                 /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set unused future fast samples of a time series entry */
# define Dem_Mem_SetUnusedFutureSamplesFast(Entry, Nr)   (Entry)->UnusedFutureSamples_FastRate = (Nr)                            /* PRQA S 3453 */ /* MD_MSR_19.7 */
#endif

/*! Test if an update is in progress in a memory state */
#define Dem_Mem_UpdateTestInProgress(State)      (DEM_MEM_TEST_COMMIT_STARTED(State) != 0)                                       /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Get the first valid event memory index */
#define Dem_Mem_MemoryIndexAll_Begin()           (Dem_Cfg_MemoryPrimaryIndex())                                                  /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Get the first invalid event memory index */
#define Dem_Mem_MemoryIndexAll_End()             (Dem_Mem_MemoryIndexAll_Begin() + Dem_Cfg_GlobalPrimaryMaxCount() + Dem_Cfg_GlobalSecondaryMaxCount()) /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Test if a memory index is used for an event memory block  */
#define Dem_Mem_IsMemoryEntryIndex(Index)        (((Index) >= Dem_Mem_MemoryIndexAll_Begin()) && ((Index) < Dem_Mem_MemoryIndexAll_End())) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#if (DEM_FEATURE_NEED_TIME_SERIES == STD_ON)
/*! Get the memory index of a time series block */
# define Dem_Mem_TimeSeriesGetIndex(MemoryInfo, EntryIndex)  (Dem_MemStorageManager_MemoryIter_Begin(MemoryInfo) + (EntryIndex)) /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Get the first valid time series memory index */
# define Dem_Mem_TimeSeriesIndexAll_Begin()      (Dem_Cfg_MemoryTimeSeriesIndex())                                               /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Get the first invalid time series memory index */
# define Dem_Mem_TimeSeriesIndexAll_End()        (Dem_Mem_TimeSeriesIndexAll_Begin() + Dem_Cfg_GlobalTimeSeriesMaxCount())       /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Test if a memory index is used for a time series memory block  */
# define Dem_Mem_IsTimeSeriesEntryIndex(Index)   (((Index) >= Dem_Mem_TimeSeriesIndexAll_Begin()) && ((Index) < Dem_Mem_TimeSeriesIndexAll_End())) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#endif

#if (DEM_CFG_SUPPORT_OBDII == STD_ON)                                                                                            /* COV_MSR_UNSUPPORTED XF */
# if (DEM_CFG_SUPPORT_PERMANENTDTC_ACTIVATION_DISTANCE == STD_ON)
/*! Get the permanent DTC storage activation state */
#  define Dem_Mem_GetPermanentActivationState()         (Dem_Cfg_AdminData.PermanentActivationState)                             /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set the permanent DTC storage activation state */
#  define Dem_Mem_SetPermanentActivationState(Value)    (Dem_Cfg_AdminData.PermanentActivationState = (Value))                   /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Get the permanent DTC storage activation distance */
#  define Dem_Mem_GetPermanentActivationDistance()      (Dem_Cfg_AdminData.PermanentActivationDistance)                          /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set the permanent DTC storage activation distance */
#  define Dem_Mem_SetPermanentActivationDistance(Value) (Dem_Cfg_AdminData.PermanentActivationDistance = (Value))                /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif
/*! Initialization pattern for permanent DTC memory */
# define DEM_MEM_PERMANENT_INIT_PATTERN          (0x4cb9U)

/*! Get the EventId of a permanent DTC entry */
# define Dem_Mem_PermanentGetEvent(Index)        (Dem_Cfg_PermanentData[(Index)].EventId)                                        /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set the EventId of a permanent DTC entry */
# define Dem_Mem_PermanentSetEvent(Index, Id)    (Dem_Cfg_PermanentData[(Index)].EventId = (Id))                                 /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Get the status of a permanent DTC entry */
# define Dem_Mem_PermanentGetStatus(Index)       (Dem_Cfg_PermanentData[(Index)].Status)                                         /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set the status of a permanent DTC entry */
# define Dem_Mem_PermanentSetStatus(Index, State)  (Dem_Cfg_PermanentData[(Index)].Status = (State))                             /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Get the init pattern of the permanent DTC memory */
# define Dem_Mem_PermanentGetInitPattern()       (Dem_Cfg_PermanentData[Dem_Cfg_GlobalPermanentMaxCount()].EventId)                  /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set the init pattern of the permanent DTC memory */
# define Dem_Mem_PermanentSetInitPattern(Pattern)  (Dem_Cfg_PermanentData[Dem_Cfg_GlobalPermanentMaxCount()].EventId = (Pattern))    /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Get the EventId of an OBD freezeframe entry */
# define Dem_Mem_FreezeFrameGetEvent(idx)        (Dem_Cfg_FreezeFrameData[(idx)].EventId)                                        /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set the EventId of an OBD freezeframe entry */
# define Dem_Mem_FreezeFrameSetEvent(idx, Id)    (Dem_Cfg_FreezeFrameData[(idx)].EventId = (Id))                                 /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Get the TimeStamp of an OBD freezeframe entry */
# define Dem_Mem_FreezeFrameGetTimestamp(idx)    (Dem_Cfg_FreezeFrameData[(idx)].Timestamp)                                      /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set the TimeStamp of an OBD freezeframe entry */
# define Dem_Mem_FreezeFrameSetTimestamp(idx, Time)  (Dem_Cfg_FreezeFrameData[(idx)].Timestamp = (Time))                         /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Get the data pointer for OBD freeze frame data of an OBD freezeframe entry */
# define Dem_Mem_FreezeFrameObdIIGetDataPtr(idx) (Dem_Cfg_FreezeFrameData[(idx)].FreezeFrameData)                                /* PRQA S 3453 */ /* MD_MSR_19.7 */
#endif

#if (DEM_CFG_SUPPORT_PID21 == STD_ON)                                                                                            /* COV_MSR_UNSUPPORTED XF */
/*! Get the odometer with MIL on */
# define Dem_Mem_GetOdometerMilOn()              (Dem_Cfg_AdminData.OdometerMilOn)                                               /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set the odometer with MIL on */
# define Dem_Mem_SetOdometerMilOn(Value)         (Dem_Cfg_AdminData.OdometerMilOn = (Value))                                     /* PRQA S 3453 */ /* MD_MSR_19.7 */
#endif

#if (DEM_CFG_SUPPORT_PID30 == STD_ON)                                                                                            /* COV_MSR_UNSUPPORTED XF */
/*! Get the warmup count since clear */
# define Dem_Mem_GetWarmUpCountSinceClear()      (Dem_Cfg_AdminData.WarmUpCountAtClear)                                          /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set the warmup count since clear */
# define Dem_Mem_SetWarmUpCountSinceClear(Value)  (Dem_Cfg_AdminData.WarmUpCountAtClear = (Value))                               /* PRQA S 3453 */ /* MD_MSR_19.7 */
#endif

#if (DEM_CFG_SUPPORT_PID31 == STD_ON)                                                                                            /* COV_MSR_UNSUPPORTED XF */
/*! Get the odometer at clear */
# define Dem_Mem_GetOdometerAtClear()            (Dem_Cfg_AdminData.OdometerAtClear)                                             /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set the odometer at clear */
# define Dem_Mem_SetOdometerAtClear(Value)       (Dem_Cfg_AdminData.OdometerAtClear = (Value))                                   /* PRQA S 3453 */ /* MD_MSR_19.7 */
#endif

#if (DEM_CFG_SUPPORT_PID4D == STD_ON)                                                                                            /* COV_MSR_UNSUPPORTED XF */
/*! Get the engine time with MIL on */
# define Dem_Mem_GetEngineTimeMilOn()            (Dem_Cfg_AdminData.EngineRunTimeMilOn)                                          /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set the engine time with MIL on */
# define Dem_Mem_SetEngineTimeMilOn(Value)       (Dem_Cfg_AdminData.EngineRunTimeMilOn = (Value))                                /* PRQA S 3453 */ /* MD_MSR_19.7 */
#endif

#if (DEM_CFG_SUPPORT_PID4E == STD_ON)                                                                                            /* COV_MSR_UNSUPPORTED XF */
/*! Get the engine time since clear */
# define Dem_Mem_GetEngineTimeSinceClear()       (Dem_Cfg_AdminData.EngineRunTimeSinceDtcClear)                                  /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set the engine time since clear */
# define Dem_Mem_SetEngineTimeSinceClear(Value)  (Dem_Cfg_AdminData.EngineRunTimeSinceDtcClear = (Value))                        /* PRQA S 3453 */ /* MD_MSR_19.7 */
#endif

#if (DEM_FEATURE_NEED_GLOBAL_MIL_STATE == STD_ON)                                                                                /* COV_MSR_UNSUPPORTED XF */
/*! Get the PID aging counter */
# define Dem_Mem_GetPidAgingCounter()            (Dem_Cfg_AdminData.PidAgingCounter)                                             /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set the PID aging counter */
# define Dem_Mem_SetPidAgingCounter(Value)       (Dem_Cfg_AdminData.PidAgingCounter = (Value))                                   /* PRQA S 3453 */ /* MD_MSR_19.7 */
#endif

/*! Test if an OBD odometer value is invalid */
#define DEM_MEM_TEST_ODOMETER_ISINVALID(Odometer)  ((Dem_GetHiHiByte(Odometer) & 0x80U) != 0)                                    /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set OBD odometer value invalid */
#define DEM_MEM_SET_ODOMETER_INVALID(Odometer)     ((uint32)((Odometer) | 0x80000000UL))                                         /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Reset OBD odometer value invalid */
#define DEM_MEM_RESET_ODOMETER_INVALID(Odometer)   ((uint32)((Odometer) & 0x7fffffffUL))                                         /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Test if an OBD engine runtime value is invalid */
#define DEM_MEM_TEST_ENGRUNTIME_ISINVALID(EngRunTime)  ((Dem_GetHiHiByte(EngRunTime) & 0x80U) != 0)                              /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set OBD engine runtime value invalid */
#define DEM_MEM_SET_ENGRUNTIME_INVALID(EngRunTime)     ((uint32)((EngRunTime) | 0x80000000UL))                                   /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Reset OBD engine runtime value invalid */
#define DEM_MEM_RESET_ENGRUNTIME_INVALID(EngRunTime)   ((uint32)((EngRunTime) & 0x7fffffffUL))                                   /* PRQA S 3453 */ /* MD_MSR_19.7 */

#if (DEM_CFG_SUPPORT_WWHOBD == STD_ON)                                                                                           /* COV_MSR_UNSUPPORTED XF */
/*! Get the global B1 counter */
# define Dem_Mem_GetB1Counter()                  (Dem_Cfg_AdminData.B1Counter)                                                   /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set the global B1 counter */
# define Dem_Mem_SetB1Counter(Value)             (Dem_Cfg_AdminData.B1Counter = (Value))                                         /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Get the global B1 healing counter */
# define Dem_Mem_GetB1HealingCounter()           (Dem_Cfg_AdminData.B1HealingCounter)                                            /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set the global B1 healing counter */
# define Dem_Mem_SetB1HealingCounter(Value)      (Dem_Cfg_AdminData.B1HealingCounter = (Value))                                  /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Get the continuous MI counter */
# define Dem_Mem_GetContinuousMiCounter()        (Dem_Cfg_AdminData.ContinuousMiCounter)                                         /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set the continuous MI counter */
# define Dem_Mem_SetContinuousMiCounter(Value)   (Dem_Cfg_AdminData.ContinuousMiCounter = (Value))                               /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Get the continuous MI aging timer */
# define Dem_Mem_GetContinuousMiAgingTimer()     (Dem_Cfg_AdminData.ContinuousMiAgingTimer)                                      /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set the continuous MI aging timer */
# define Dem_Mem_SetContinuousMiAgingTimer(Value)  (Dem_Cfg_AdminData.ContinuousMiAgingTimer = (Value))                          /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Get the continuous MI healing counter */
# define Dem_Mem_GetContinuousMiHealingCounter()  (Dem_Cfg_AdminData.ContinuousMiHealingCounter)                                 /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set the continuous MI healing counter */
# define Dem_Mem_SetContinuousMiHealingCounter(Value)  (Dem_Cfg_AdminData.ContinuousMiHealingCounter = (Value))                  /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Get the continuous MI aging counter */
# define Dem_Mem_GetContinuousMiAgingCounter()   (Dem_Cfg_AdminData.ContinuousMiAgingCounter)                                    /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set the continuous MI aging counter */
# define Dem_Mem_SetContinuousMiAgingCounter(Value)  (Dem_Cfg_AdminData.ContinuousMiAgingCounter = (Value))                      /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Get the cumulative OBD engine runtime */
# define Dem_Mem_GetCumulativeEngRuntime()       (Dem_Cfg_AdminData.CumulativeEngineRunTime)                                     /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set the cumulative OBD engine runtime */
# define Dem_Mem_SetCumulativeEngRuntime(Value)  (Dem_Cfg_AdminData.CumulativeEngineRunTime = (Value))                           /* PRQA S 3453 */ /* MD_MSR_19.7 */
#endif

#if (DEM_FEATURE_NEED_IUMPR == STD_ON)                                                                                           /* COV_MSR_UNSUPPORTED XF */
/*! Get the ignition cycle counter */
# define Dem_Mem_GetIgnitionCycleCounter()       (Dem_Cfg_AdminData.IgnitionCycleCounter)                                        /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set the ignition cycle counter */
# define Dem_Mem_SetIgnitionCycleCounter(Value)  (Dem_Cfg_AdminData.IgnitionCycleCounter = (Value))                              /* PRQA S 3453 */ /* MD_MSR_19.7 */

# if (DEM_CFG_SUPPORT_CYCLE_IGNITION_HYBRID == STD_ON)
/*! Get the hybrid ignition cycle counter */
#  define Dem_Mem_GetIgnitionCycleCounterHybrid()       (Dem_Cfg_AdminData.IgnitionCycleHybridCounter)                           /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set the hybrid ignition cycle counter */
#  define Dem_Mem_SetIgnitionCycleCounterHybrid(Value)  (Dem_Cfg_AdminData.IgnitionCycleHybridCounter = (Value))                 /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif
#endif

#if (DEM_FEATURE_NEED_MIL_GROUPS)
/*! Initialize a MIL group trip counter */
# define Dem_Mem_InitMilGroupTripCount(MilGroupIdx)            (Dem_EventInternalStatus_SetMilGroupTripCount(MilGroupIdx, 0x00U))                /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Get a MIL group trip counter */
# define Dem_Mem_GetMilGroupTripCount(MilGroupIdx)             (Dem_EventInternalStatus_GetMilGroupTripCountRaw(MilGroupIdx) & 0x7Fu)            /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Increment a MIL group trip counter */
# define Dem_Mem_IncrementMilGroupTripCount(MilGroupIdx)       (Dem_EventInternalStatus_SetMilGroupTripCount(MilGroupIdx, (Dem_EventInternalStatus_GetMilGroupTripCountRaw(MilGroupIdx) + 1)))  /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set a MIL group trip counter to 0 */
# define Dem_Mem_ResetMilGroupTripCount(MilGroupIdx)           (Dem_EventInternalStatus_SetMilGroupTripCount(MilGroupIdx, (Dem_EventInternalStatus_GetMilGroupTripCountRaw(MilGroupIdx) & 0x80U)))  /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Get MIL group incremented this DCY */
# define Dem_Mem_GetMilGroupIncremented(MilGroupIdx)           (Dem_EventInternalStatus_GetMilGroupTripCountRaw(MilGroupIdx) & 0x80U)            /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set MIL group incremented this DCY */
# define Dem_Mem_SetMilGroupIncremented(MilGroupIdx)           (Dem_EventInternalStatus_SetMilGroupTripCount(MilGroupIdx, (Dem_EventInternalStatus_GetMilGroupTripCountRaw(MilGroupIdx) | 0x80U)))  /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Reset MIL group incremented this DCY */
# define Dem_Mem_ResetMilGroupIncremented(MilGroupIdx)         (Dem_EventInternalStatus_SetMilGroupTripCount(MilGroupIdx, (Dem_EventInternalStatus_GetMilGroupTripCountRaw(MilGroupIdx) & 0x7fU)))  /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Increment pending DTC count */
# define Dem_Mem_IncrementMilGroupPendingCount(MilGroupIdx)    (Dem_EventInternalStatus_SetMilGroupPendingCount(MilGroupIdx, (Dem_EventInternalStatus_GetMilGroupPendingCount(MilGroupIdx) + 1)))  /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Decrement pending DTC count */
# define Dem_Mem_DecrementMilGroupPendingCount(MilGroupIdx)    (Dem_EventInternalStatus_SetMilGroupPendingCount(MilGroupIdx, (Dem_EventInternalStatus_GetMilGroupPendingCount(MilGroupIdx) - 1)))  /* PRQA S 3453 */ /* MD_MSR_19.7 */
#endif

#if (DEM_FEATURE_NEED_TIME_SERIES == STD_ON)
/*! Get ring buffer index for normal rate samples */
# define Dem_Mem_GetCurrentRingBufferIndexNormal()             (Dem_Cfg_RingBufferNormalRate.CurrentIndex)                       /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set ring buffer index for normal rate samples */
# define Dem_Mem_SetCurrentRingBufferIndexNormal(Value)        (Dem_Cfg_RingBufferNormalRate.CurrentIndex = (Value))             /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Get normal rate sample count */
# define Dem_Mem_GetSampleCountNormal()                        (Dem_Cfg_RingBufferNormalRate.SampleCount)                        /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set normal rate sample count */
# define Dem_Mem_SetSampleCountNormal(Value)                   (Dem_Cfg_RingBufferNormalRate.SampleCount = (Value))              /* PRQA S 3453 */ /* MD_MSR_19.7 */

# if (DEM_FEATURE_NEED_TIME_SERIES_FAST == STD_ON)
/*! Get ring buffer index for fast rate samples */
#  define Dem_Mem_GetCurrentRingBufferIndexFast()              (Dem_Cfg_RingBufferFastRate.CurrentIndex)                         /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set ring buffer index for fast rate samples */
#  define Dem_Mem_SetCurrentRingBufferIndexFast(Value)         (Dem_Cfg_RingBufferFastRate.CurrentIndex = (Value))               /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Get fast rate sample count */
#  define Dem_Mem_GetSampleCountFast()                         (Dem_Cfg_RingBufferFastRate.SampleCount)                          /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Set fast rate sample count */
#  define Dem_Mem_SetSampleCountFast(Value)                    (Dem_Cfg_RingBufferFastRate.SampleCount = (Value))                /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif
#endif


/* ********************************************************************************************************************
 *  SUBCOMPONENT DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
#if (DEM_FEATURE_NEED_TIME_SERIES == STD_ON)
/*! Pointer to a time-series memory entry */
typedef P2VAR(Dem_Cfg_TimeSeriesEntryType, TYPEDEF, DEM_NVM_DATA)    Dem_Mem_TimeSeriesEntryPtrType;
/*! Non-writeable Pointer to a time-series memory entry */
typedef P2CONST(Dem_Cfg_TimeSeriesEntryType, TYPEDEF, DEM_NVM_DATA)  Dem_Mem_ConstTimeSeriesEntryPtrType;
#endif

#endif /* DEM_MEM_TYPES_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_Mem_Types.h
 *********************************************************************************************************************/
