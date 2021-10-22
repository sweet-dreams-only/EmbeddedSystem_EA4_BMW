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
 *  \file       Dem_Mem_Implementation.h
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

#if !defined (DEM_MEM_IMPLEMENTATION_H)
#define DEM_MEM_IMPLEMENTATION_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                  /* Own subcomponent header */
/* ------------------------------------------------------------------------- */
#include "Dem_Mem_Interface.h"

                                                    /* Used subcomponent API */
/* ------------------------------------------------------------------------- */
#include "Dem_MemState_Implementation.h"
#include "Dem_J1939DcmAPI_Implementation.h"

                                                   /* Subcomponents callbacks*/
/* ------------------------------------------------------------------------- */
#include "Dem_OperationCycle_Interface.h"
#include "Dem_Memory_Interface.h"
#include "Dem_Error_Interface.h"
#include "Dem_Esm_Interface.h"
#include "Dem_Prestore_Interface.h"
#include "Dem_Dtr_Interface.h"

/* ********************************************************************************************************************
 *  SUBCOMPONENT CONSTANT MACROS
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  SUBCOMPONENT FUNCTION MACROS
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  SUBCOMPONENT DATA
 *********************************************************************************************************************/
#define DEM_START_SEC_VAR_NOINIT_8BIT
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#if (DEM_CFG_SUPPORT_OBDII == STD_ON)                                                                                            /* COV_MSR_UNSUPPORTED XF */
/*! Freeze frame index visible in mode 0x02 */
DEM_LOCAL VAR(uint8, DEM_VAR_NOINIT)             Dem_Mem_FreezeFrameIndexMode02;
/*! Number of permanent DTCs */
DEM_LOCAL VAR(uint8, DEM_VAR_NOINIT)             Dem_Mem_PermanentCurrentCount;
#endif

#if (DEM_FEATURE_NEED_TIME_SERIES == STD_ON)
/*! Number of stored time-series entries */
DEM_LOCAL VAR(uint8, DEM_VAR_NOINIT)             Dem_Mem_TimeSeriesCurrentCount;                                                 /* PRQA S 3218 */ /* MD_DEM_8.7 */
#endif

#define DEM_STOP_SEC_VAR_NOINIT_8BIT
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define DEM_START_SEC_VAR_NOINIT_16BIT
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define DEM_STOP_SEC_VAR_NOINIT_16BIT
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define DEM_START_SEC_VAR_NOINIT_32BIT
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Current time stamp, used to establish a chronological ordering */
DEM_LOCAL VAR(uint32, DEM_VAR_NOINIT)            Dem_Mem_CurrentTimestamp;

#define DEM_STOP_SEC_VAR_NOINIT_32BIT
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define DEM_START_SEC_CONST_8BIT
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define DEM_STOP_SEC_CONST_8BIT
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* ********************************************************************************************************************
 *  SUBCOMPONENT OBJECT FUNCTION DEFINITIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \addtogroup Dem_Mem_Properties
 * \{
 */

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* ********************************************************************************************************************
 *  SUBCOMPONENT PRIVATE FUNCTION DEFINITIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \addtogroup Dem_Mem_Private
 * \{
 */

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* ********************************************************************************************************************
 *  SUBCOMPONENT API FUNCTION DEFINITIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \addtogroup Dem_Mem_Public
 * \{
 */

#if (DEM_CFG_SUPPORT_DEBOUNCE_NV == STD_ON)
/* ****************************************************************************
 % Dem_Mem_DebounceGetStoredValue
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(sint16, DEM_CODE)
Dem_Mem_DebounceGetStoredValue(
  CONST(uint16, AUTOMATIC)  Index
  )
{
  return Dem_Cfg_DebounceData[Index];
}
#endif

#if (DEM_CFG_SUPPORT_DEBOUNCE_NV == STD_ON)
/* ****************************************************************************
 % Dem_Mem_DebounceSetStoredValue
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Mem_DebounceSetStoredValue(
  CONST(uint16, AUTOMATIC)  Index,
  CONST(sint16, AUTOMATIC)  DebounceValue
  )
{
# if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (Index >= Dem_Cfg_GlobalDebounceStorageEventCount())
  {
    Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
  }
  else
# endif
  {
    Dem_Cfg_DebounceData[Index] = DebounceValue;                                                                                 /* SBSW_DEM_ARRAY_WRITE_DEBOUNCEDATA */
  }
}
#endif

#if (DEM_FEATURE_NEED_EVENTAVAILABLE_NV == STD_ON)
/* ****************************************************************************
 % Dem_Mem_EventGetAvailableMask
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_Mem_EventGetAvailableMask(
  CONST(uint16, AUTOMATIC)  Index                                                                                                /* PRQA S 3206 */ /* MD_DEM_3206 */
  )
{
  return Dem_Cfg_EventAvailableData[Index];
}
#endif

#if (DEM_FEATURE_NEED_EVENTAVAILABLE_NV == STD_ON)
/* ****************************************************************************
 % Dem_Mem_EventSetAvailableMask
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Mem_EventSetAvailableMask(
  CONST(uint16, AUTOMATIC)  Index,
  CONST(uint8, AUTOMATIC)  Mask
  )
{
# if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (Index >= ((Dem_Cfg_GlobalEventCount() + 7) / 8))
  {
    Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
  }
  else
# endif
  {
    Dem_Cfg_EventAvailableData[Index] = Mask;                                                                                    /* SBSW_DEM_ARRAY_WRITE_EVENTAVAILABLEDATA */
  }
}
#endif

/* ****************************************************************************
 % Dem_Mem_MemoryUpdateInit
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Mem_MemoryUpdateInit(
  CONST(Dem_Cfg_MemoryIndexType, AUTOMATIC)  MemoryIndex
  )
{
#if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (MemoryIndex >= Dem_Cfg_GetSizeOfMemoryCommitNumber())
  {
    Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
  }
  else
#endif
  {
    Dem_Cfg_SetMemoryCommitNumber(MemoryIndex, DEM_MEM_INIT_COMMIT_NUMBER);                                                      /* SBSW_DEM_ARRAY_WRITE_MEMORYCOMMITNUMBER */
  }
}

/* ****************************************************************************
 % Dem_Mem_MemoryUpdateStart
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Mem_MemoryUpdateStart(
  CONST(Dem_Cfg_MemoryIndexType, AUTOMATIC)  MemoryIndex
  )
{
#if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (MemoryIndex >= Dem_Cfg_GetSizeOfMemoryCommitNumber())
  {
    Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
  }
  else
#endif
  {
    Dem_Cfg_SetMemoryCommitNumber(MemoryIndex, DEM_MEM_SET_COMMIT_STARTED(Dem_Cfg_GetMemoryCommitNumber(MemoryIndex)));          /* SBSW_DEM_ARRAY_WRITE_MEMORYCOMMITNUMBER */
  }
}

/* ****************************************************************************
 % Dem_Mem_MemoryUpdateFinish
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Mem_MemoryUpdateFinish(
  CONST(Dem_Cfg_MemoryIndexType, AUTOMATIC)  MemoryIndex
  )
{
#if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (MemoryIndex >= Dem_Cfg_GetSizeOfMemoryCommitNumber())
  {
    Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
  }
  else
#endif
  {
    Dem_Cfg_SetMemoryCommitNumber(MemoryIndex, DEM_MEM_SET_COMMIT_FINISHED(Dem_Cfg_GetMemoryCommitNumber(MemoryIndex)));         /* SBSW_DEM_ARRAY_WRITE_MEMORYCOMMITNUMBER */
  }
}

#if ( (DEM_CFG_SUPPORT_ERECS == STD_ON) \
   || (DEM_CFG_SUPPORT_SRECS == STD_ON) \
   || (DEM_CFG_SUPPORT_OBDII == STD_ON) \
   || (DEM_CFG_SUPPORT_WWHOBD == STD_ON) \
   || (DEM_FEATURE_NEED_J1939_FREEZEFRAME == STD_ON) \
   || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON) )
/* ****************************************************************************
 % Dem_Mem_MemoryUpdateGetState
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_Mem_MemoryUpdateGetState(
  CONST(Dem_Cfg_MemoryIndexType, AUTOMATIC)  MemoryIndex
  )
{
  return Dem_Cfg_GetMemoryCommitNumber(MemoryIndex);
}
#endif

#if (DEM_FEATURE_NEED_TIME_SERIES == STD_ON)
/* ****************************************************************************
 % Dem_Mem_RingBufferNormalRatePtr
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_DataPtrType, DEM_CODE)
Dem_Mem_RingBufferNormalRatePtr(
  CONST(uint8, AUTOMATIC)  BufferIndex
  )
{
  Dem_DataPtrType lReturnValue;
# if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (BufferIndex >= Dem_Cfg_TimeSeriesBufferCountNormal())
  {
    Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
    lReturnValue = Dem_Cfg_RingBufferNormalRate.Buffer[0];
  }
  else
# endif
  {
    lReturnValue = Dem_Cfg_RingBufferNormalRate.Buffer[BufferIndex];
  }
  return lReturnValue;
}
#endif

#if (DEM_FEATURE_NEED_TIME_SERIES_FAST == STD_ON)
/* ****************************************************************************
 % Dem_Mem_RingBufferFastRatePtr
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_DataPtrType, DEM_CODE)
Dem_Mem_RingBufferFastRatePtr(
  CONST(uint8, AUTOMATIC)  BufferIndex
  )
{
  Dem_DataPtrType lReturnValue;
# if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (BufferIndex >= Dem_Cfg_TimeSeriesBufferCountFast())
  {
    Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
    lReturnValue = Dem_Cfg_RingBufferFastRate.Buffer[0];
  }
  else
# endif
  {
    lReturnValue = Dem_Cfg_RingBufferFastRate.Buffer[BufferIndex];
  }
  return lReturnValue;
}
#endif

#if (DEM_FEATURE_NEED_TIME_SERIES == STD_ON)
/* ****************************************************************************
 % Dem_Mem_TimeSeriesEntryGetNormalDataPtr
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_SharedDataPtrType, DEM_CODE)
Dem_Mem_TimeSeriesEntryGetNormalDataPtr(
  CONST(Dem_Mem_TimeSeriesEntryPtrType, AUTOMATIC)  MemoryEntry,                                                                 /* PRQA S 3673 */ /* MD_DEM_16.7_False */
  CONST(uint8, AUTOMATIC)  SeriesIndex
  )
{
  Dem_SharedDataPtrType lReturnValue;
# if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (SeriesIndex >= (Dem_Cfg_TimeSeriesPastSamplesNormal() + Dem_Cfg_TimeSeriesFutureSamplesNormal()))
  {
    Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
    lReturnValue = &MemoryEntry->SnapshotData_NormalRate[0][0];
  }
  else
# endif
  {
    lReturnValue = &MemoryEntry->SnapshotData_NormalRate[SeriesIndex][0];
  }
  return lReturnValue;
}
#endif

#if (DEM_FEATURE_NEED_TIME_SERIES == STD_ON)
/* ****************************************************************************
 % Dem_Mem_TimeSeriesEntryGetNormalConstDataPtr
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_ConstSharedDataPtrType, DEM_CODE)
Dem_Mem_TimeSeriesEntryGetNormalConstDataPtr(
  CONST(Dem_Mem_ConstTimeSeriesEntryPtrType, AUTOMATIC)  MemoryEntry,
  CONST(uint8, AUTOMATIC)  SeriesIndex
  )
{
  Dem_ConstSharedDataPtrType lReturnValue;
# if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (SeriesIndex >= (Dem_Cfg_TimeSeriesPastSamplesNormal() + Dem_Cfg_TimeSeriesFutureSamplesNormal()))
  {
    Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
    lReturnValue = &MemoryEntry->SnapshotData_NormalRate[0][0];
  }
  else
# endif
  {
    lReturnValue = &MemoryEntry->SnapshotData_NormalRate[SeriesIndex][0];
  }
  return lReturnValue;
}
#endif

#if (DEM_FEATURE_NEED_TIME_SERIES_FAST == STD_ON)
/* ****************************************************************************
 % Dem_Mem_TimeSeriesEntryGetFastDataPtr
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_SharedDataPtrType, DEM_CODE)
Dem_Mem_TimeSeriesEntryGetFastDataPtr(
  CONST(Dem_Mem_TimeSeriesEntryPtrType, AUTOMATIC)  MemoryEntry,                                                                 /* PRQA S 3673 */ /* MD_DEM_16.7_False */
  CONST(uint8, AUTOMATIC)  SeriesIndex
  )
{
  Dem_SharedDataPtrType lReturnValue;
# if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (SeriesIndex >= (Dem_Cfg_TimeSeriesPastSamplesFast() + Dem_Cfg_TimeSeriesFutureSamplesFast()))
  {
    Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
    lReturnValue = &MemoryEntry->SnapshotData_FastRate[0][0];
  }
  else
# endif
  {
    lReturnValue = &MemoryEntry->SnapshotData_FastRate[SeriesIndex][0];
  }
  return lReturnValue;
}
#endif

#if (DEM_FEATURE_NEED_TIME_SERIES_FAST == STD_ON)
/* ****************************************************************************
 % Dem_Mem_TimeSeriesEntryGetFastConstDataPtr
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_ConstSharedDataPtrType, DEM_CODE)
Dem_Mem_TimeSeriesEntryGetFastConstDataPtr(
  CONST(Dem_Mem_ConstTimeSeriesEntryPtrType, AUTOMATIC)  MemoryEntry,
  CONST(uint8, AUTOMATIC)  SeriesIndex
  )
{
  Dem_ConstSharedDataPtrType lReturnValue;
# if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (SeriesIndex >= (Dem_Cfg_TimeSeriesPastSamplesFast() + Dem_Cfg_TimeSeriesFutureSamplesFast()))
  {
    Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
    lReturnValue = &MemoryEntry->SnapshotData_FastRate[0][0];
  }
  else
# endif
  {
    lReturnValue = &MemoryEntry->SnapshotData_FastRate[SeriesIndex][0];
  }
  return lReturnValue;
}
#endif

/* ****************************************************************************
 % Dem_Mem_IndicatorGetEventCountContinuous
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(uint16, DEM_CODE)
Dem_Mem_IndicatorGetEventCountContinuous(
  CONST(uint8, AUTOMATIC)  IndicatorId,                                                                                          /* PRQA S 3206 */ /* MD_DEM_3206 */
  CONST(uint8, AUTOMATIC)  J1939NodeId                                                                                           /* PRQA S 3206 */ /* MD_DEM_3206 */
  )
{
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(IndicatorId)                                                                                  /* PRQA S 3112 */ /* MD_DEM_14.2 */
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(J1939NodeId)                                                                                  /* PRQA S 3112 */ /* MD_DEM_14.2 */
#if (DEM_CFG_INDICATORCONTINUOUS == STD_ON)
  return Dem_Cfg_IndicatorContinuous[IndicatorId][J1939NodeId];
#else
  return 0;
#endif
}

#if (DEM_CFG_SUPPORT_INDICATORS == STD_ON)
/* ****************************************************************************
 % Dem_Mem_IndicatorSetEventCountContinuous
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Mem_IndicatorSetEventCountContinuous(
  CONST(uint8, AUTOMATIC)  IndicatorId,                                                                                          /* PRQA S 3206 */ /* MD_DEM_3206 */
  CONST(uint8, AUTOMATIC)  J1939NodeId,                                                                                          /* PRQA S 3206 */ /* MD_DEM_3206 */
  CONST(uint16, AUTOMATIC)  ActiveEventCount                                                                                     /* PRQA S 3206 */ /* MD_DEM_3206 */
  )
{
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(IndicatorId)                                                                                  /* PRQA S 3112 */ /* MD_DEM_14.2 */
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(J1939NodeId)                                                                                  /* PRQA S 3112 */ /* MD_DEM_14.2 */
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(ActiveEventCount)                                                                             /* PRQA S 3112 */ /* MD_DEM_14.2 */
# if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if ( (IndicatorId >= Dem_Cfg_GlobalIndicatorCount())                                                                           /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
    || (J1939NodeId >= Dem_Cfg_GlobalJ1939NodeCount()))
  {
    Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
  }
  else
# endif
  {
# if (DEM_CFG_INDICATORCONTINUOUS == STD_ON)
    Dem_Cfg_IndicatorContinuous[IndicatorId][J1939NodeId] = ActiveEventCount;                                                    /* SBSW_DEM_ARRAY_WRITE_INDICATORCONTINUOUS */
# endif
  }
}
#endif

/* ****************************************************************************
 % Dem_Mem_IndicatorGetEventCountBlinking
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(uint16, DEM_CODE)
Dem_Mem_IndicatorGetEventCountBlinking(
  CONST(uint8, AUTOMATIC)  IndicatorId,                                                                                          /* PRQA S 3206 */ /* MD_DEM_3206 */
  CONST(uint8, AUTOMATIC)  J1939NodeId                                                                                           /* PRQA S 3206 */ /* MD_DEM_3206 */
  )
{
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(IndicatorId)                                                                                  /* PRQA S 3112 */ /* MD_DEM_14.2 */
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(J1939NodeId)                                                                                  /* PRQA S 3112 */ /* MD_DEM_14.2 */
#if (DEM_CFG_INDICATORBLINKING == STD_ON)
  return Dem_Cfg_IndicatorBlinking[IndicatorId][J1939NodeId];
#else
  return 0;
#endif
}

#if (DEM_CFG_SUPPORT_INDICATORS == STD_ON)
/* ****************************************************************************
 % Dem_Mem_IndicatorSetEventCountBlinking
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Mem_IndicatorSetEventCountBlinking(
  CONST(uint8, AUTOMATIC)  IndicatorId,                                                                                          /* PRQA S 3206 */ /* MD_DEM_3206 */
  CONST(uint8, AUTOMATIC)  J1939NodeId,                                                                                          /* PRQA S 3206 */ /* MD_DEM_3206 */
  CONST(uint16, AUTOMATIC)  ActiveEventCount                                                                                     /* PRQA S 3206 */ /* MD_DEM_3206 */
  )
{
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(IndicatorId)                                                                                  /* PRQA S 3112 */ /* MD_DEM_14.2 */
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(J1939NodeId)                                                                                  /* PRQA S 3112 */ /* MD_DEM_14.2 */
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(ActiveEventCount)                                                                             /* PRQA S 3112 */ /* MD_DEM_14.2 */
# if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if ( (IndicatorId >= Dem_Cfg_GlobalIndicatorCount())                                                                            /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
    || (J1939NodeId >= Dem_Cfg_GlobalJ1939NodeCount()) )
  {
    Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
  }
  else
# endif
  {
# if (DEM_CFG_INDICATORBLINKING == STD_ON)
    Dem_Cfg_IndicatorBlinking[IndicatorId][J1939NodeId] = ActiveEventCount;                                                      /* SBSW_DEM_ARRAY_WRITE_INDICATORBLINKING */
# endif
  }
}
#endif

#if (DEM_CFG_SUPPORT_IUMPR == STD_ON)
/* ****************************************************************************
 % Dem_Mem_IumprGetUpdatePending
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_Cfg_ObdIumprUpdatePendingType, DEM_CODE)
Dem_Mem_IumprGetUpdatePending(
  CONST(Dem_RatioIdIndexType, AUTOMATIC)  RatioIndex
  )
{
  return Dem_Cfg_GetObdIumprUpdatePending(RatioIndex);
}
#endif

#if (DEM_CFG_SUPPORT_IUMPR == STD_ON)
/* ****************************************************************************
 % Dem_Mem_IumprSetUpdatePending
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Mem_IumprSetUpdatePending(
  CONST(Dem_RatioIdIndexType, AUTOMATIC)  RatioIndex,
  CONST(Dem_Cfg_ObdIumprUpdatePendingType, AUTOMATIC)  Value
  )
{
# if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (RatioIndex >= Dem_Cfg_ObdRatioIdCount())
  {
    Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
  }
  else
# endif
  {
    Dem_Cfg_SetObdIumprUpdatePending(RatioIndex, Value);
  }
}
#endif

#if (DEM_CFG_SUPPORT_IUMPR == STD_ON)
/* ****************************************************************************
 % Dem_Mem_GetDenominator
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(uint16, DEM_CODE)
Dem_Mem_GetDenominator(
  CONST(Dem_RatioIdIndexType, AUTOMATIC)  RatioIndex
  )
{
  return (uint16)(Dem_Cfg_ObdIumprData.Denominator[RatioIndex]);
}
#endif

#if (DEM_CFG_SUPPORT_IUMPR == STD_ON)
/* ****************************************************************************
 % Dem_Mem_SetDenominator
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Mem_SetDenominator(
  CONST(Dem_RatioIdIndexType, AUTOMATIC)  RatioIndex,
  CONST(uint16, AUTOMATIC)  Value
  )
{
# if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (RatioIndex >= Dem_Cfg_ObdRatioIdCount())
  {
    Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
  }
  else
# endif
  {
    Dem_Cfg_ObdIumprData.Denominator[RatioIndex] = Value;
  }
}
#endif

#if (DEM_CFG_SUPPORT_IUMPR == STD_ON)
/* ****************************************************************************
 % Dem_Mem_GetGeneralDenominator
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(uint16, DEM_CODE)
Dem_Mem_GetGeneralDenominator(
  void
  )
{
  return (uint16)(Dem_Cfg_ObdIumprData.GeneralDenominator);
}
#endif

#if (DEM_CFG_SUPPORT_IUMPR == STD_ON)
/* ****************************************************************************
 % Dem_Mem_SetGeneralDenominator
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Mem_SetGeneralDenominator(
  CONST(uint16, AUTOMATIC)  Value
  )
{
  Dem_Cfg_ObdIumprData.GeneralDenominator = Value;
}
#endif

#if (DEM_CFG_SUPPORT_IUMPR == STD_ON)
/* ****************************************************************************
 % Dem_Mem_GetGeneralDenominatorStatus
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_Mem_GetGeneralDenominatorStatus(
  void
  )
{
  return (uint8)(Dem_Cfg_ObdIumprData.GeneralDenominatorStatus);
}
#endif

#if (DEM_CFG_SUPPORT_IUMPR == STD_ON)
/* ****************************************************************************
 % Dem_Mem_SetGeneralDenominatorStatus
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Mem_SetGeneralDenominatorStatus(
  CONST(uint8, AUTOMATIC)  Value
  )
{
  Dem_Cfg_ObdIumprData.GeneralDenominatorStatus = Value;
}
#endif

#if (DEM_FEATURE_NEED_IUMPR == STD_ON)
/* ****************************************************************************
 % Dem_Mem_GetGlobalIumprHybridStatus
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_Mem_GetGlobalIumprHybridStatus(
  void
  )
{
# if (DEM_CFG_SUPPORT_CYCLE_IGNITION_HYBRID == STD_ON)
  return Dem_Cfg_ObdIumprData.GlobalHybridStatus;
# else
  return 0;
# endif
}
#endif

#if (DEM_FEATURE_NEED_IUMPR == STD_ON)
/* ****************************************************************************
 % Dem_Mem_SetGlobalIumprHybridStatus
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Mem_SetGlobalIumprHybridStatus(
  CONST(uint8, AUTOMATIC)  Value                                                                                                 /* PRQA S 3206 */ /* MD_DEM_3206 */
  )
{
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(Value)                                                                                        /* PRQA S 3112 */ /* MD_DEM_14.2 */
# if (DEM_CFG_SUPPORT_CYCLE_IGNITION_HYBRID == STD_ON)
  Dem_Cfg_ObdIumprData.GlobalHybridStatus = Value;
# endif
}
#endif

#if (DEM_CFG_SUPPORT_IUMPR == STD_ON)
/* ****************************************************************************
 % Dem_Mem_GetGlobalNumeratorsLocked
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_Mem_GetGlobalNumeratorsLocked(
  void
  )
{
  return (uint8)(Dem_Cfg_ObdIumprData.GlobalNumeratorsLocked);
}
#endif

#if (DEM_CFG_SUPPORT_IUMPR == STD_ON)
/* ****************************************************************************
 % Dem_Mem_SetGlobalNumeratorsLocked
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Mem_SetGlobalNumeratorsLocked(
  CONST(uint8, AUTOMATIC)  Value
  )
{
  Dem_Cfg_ObdIumprData.GlobalNumeratorsLocked = Value;
}
#endif

#if (DEM_CFG_SUPPORT_IUMPR == STD_ON)
/* ****************************************************************************
 % Dem_Mem_GetIumprStatus
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_Mem_GetIumprStatus(
  CONST(Dem_RatioIdIndexType, AUTOMATIC)  RatioIndex
  )
{
  return Dem_Cfg_ObdIumprData.Status[RatioIndex];
}
#endif

#if (DEM_CFG_SUPPORT_IUMPR == STD_ON)
/* ****************************************************************************
 % Dem_Mem_SetIumprStatus
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Mem_SetIumprStatus(
  CONST(Dem_RatioIdIndexType, AUTOMATIC)  RatioIndex,
  CONST(uint8, AUTOMATIC)  Value
  )
{
# if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (RatioIndex >= Dem_Cfg_ObdRatioIdCount())
  {
    Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
  }
  else
# endif
  {
    Dem_Cfg_ObdIumprData.Status[RatioIndex] = Value;
  }
}
#endif

#if (DEM_CFG_SUPPORT_IUMPR == STD_ON)
/* ****************************************************************************
 % Dem_Mem_GetNumerator
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(uint16, DEM_CODE)
Dem_Mem_GetNumerator(
  CONST(Dem_RatioIdIndexType, AUTOMATIC)  RatioIndex
  )
{
  return Dem_Cfg_ObdIumprData.Numerator[RatioIndex];
}
#endif

#if (DEM_CFG_SUPPORT_IUMPR == STD_ON)
/* ****************************************************************************
 % Dem_Mem_SetNumerator
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Mem_SetNumerator(
  CONST(Dem_RatioIdIndexType, AUTOMATIC)  RatioIndex,
  CONST(uint16, AUTOMATIC)  Value
  )
{
# if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (RatioIndex >= Dem_Cfg_ObdRatioIdCount())
  {
    Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
  }
  else
# endif
  {
    Dem_Cfg_ObdIumprData.Numerator[RatioIndex] = Value;
  }
}
#endif

#if (DEM_FEATURE_NEED_OVFLIND == STD_ON)
/* ****************************************************************************
 % Dem_Mem_GetOverflow
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Mem_GetOverflow(
  CONST(uint8, AUTOMATIC)  MemoryId
  )
{
  boolean lReturnValue;

  if ((Dem_Mem_GetMemoryOverflow() & (1U << MemoryId)) != 0)
  {
    lReturnValue = TRUE;
  }
  else
  {
    lReturnValue = FALSE;
  }

  return lReturnValue;
}
#endif

#if (DEM_FEATURE_NEED_OVFLIND == STD_ON)
/* ****************************************************************************
 % Dem_Mem_SetOverflow
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Mem_SetOverflow(
  CONST(uint8, AUTOMATIC)  MemoryId
  )
{
  uint8 lOldOverflow;
  uint8 lNewOverflow;

  lOldOverflow = Dem_Mem_GetMemoryOverflow();
  lNewOverflow = (uint8)(lOldOverflow | ((uint8)(1U << MemoryId)));
  if (lOldOverflow != lNewOverflow)
  {
    Dem_Mem_SetMemoryOverflow(lNewOverflow);
  }
}
#endif

#if (DEM_FEATURE_NEED_OVFLIND == STD_ON)
/* ****************************************************************************
 % Dem_Mem_ResetOverflow
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Mem_ResetOverflow(
  CONST(uint8, AUTOMATIC)  MemoryId
  )
{
  uint8 lOldOverflow;
  uint8 lNewOverflow;

  lOldOverflow = Dem_Mem_GetMemoryOverflow();
  lNewOverflow = (uint8)(lOldOverflow & ((uint8)~((uint8)(1U << MemoryId))));
  if (lOldOverflow != lNewOverflow)
  {
    Dem_Mem_SetMemoryOverflow(lNewOverflow);
  }
}
#endif

#if (DEM_CFG_SUPPORT_DEBOUNCE_NV == STD_ON)
/* ****************************************************************************
 % Dem_Mem_CopyDataDebounceNv
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Mem_CopyDataDebounceNv(
  void
  )
{
  Dem_EventIdType lEventId;
  uint16 lDebounceNvIndex;

  lDebounceNvIndex = Dem_Cfg_GlobalDebounceStorageEventCount();
  lEventId = Dem_Cfg_GlobalEventCount();

  Dem_Internal_AssertReturnVoid(lEventId >= lDebounceNvIndex, DEM_E_PARAM_CONFIG)

  while (lDebounceNvIndex != 0U)
  {
    Dem_Internal_AssertReturnVoid(lEventId != DEM_EVENT_INVALID, DEM_E_INCONSISTENT_STATE)

    --lEventId;

    if (Dem_Cfg_EventSupportDebounceNv(lEventId) == TRUE)
    {
      --lDebounceNvIndex;
      Dem_Mem_DebounceSetStoredValue(lDebounceNvIndex, (sint16) Dem_Satellite_GetDebounceValue(Dem_Cfg_EventSatelliteId(lEventId), Dem_Cfg_EventSatelliteEventId(lEventId)));
    }
  }
}
#endif

/* ****************************************************************************
 % Dem_Mem_MemoryUpdateIndex
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Mem_MemoryUpdateIndex(
  CONST(Dem_Mem_MemoryInfoPtrType, AUTOMATIC)  MemoryInfo,
  CONST(uint8, AUTOMATIC)  MemoryIndex
  )
{
  uint8 lChronoIterator;
  uint8 lTempIndex;

  /* Store the global timestamp to the entry, and update it */
  Dem_MemoryEntry_SetTimestamp(Dem_MemStorageManager_GetMemoryEntryId(MemoryIndex), Dem_Mem_CurrentTimestamp);
  ++Dem_Mem_CurrentTimestamp;

  /* move downwards the chronology moving all entries, until the updated element is overwritten */
  lChronoIterator = (uint8)(Dem_MemStorageManager_MemoryGetCurrentSize(MemoryInfo) - 1);                                                       /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
  lTempIndex = Dem_MemStorageManager_MemoryGetChronology(MemoryInfo, lChronoIterator);                                           /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
  while (lTempIndex != MemoryIndex)
  {
    uint8 lSwap;

    lSwap = lTempIndex;
    --lChronoIterator;
    lTempIndex = Dem_MemStorageManager_MemoryGetChronology(MemoryInfo, lChronoIterator);                                         /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
    Dem_MemStorageManager_MemorySetChronology(MemoryInfo, lChronoIterator, lSwap);                                                             /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */

#if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
    if ((lChronoIterator == 0) && (lTempIndex != MemoryIndex))
    {
      /* chronology is inconsistent */
      Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
      break;
    }
#endif
  }

  Dem_MemStorageManager_MemorySetChronology(MemoryInfo, (uint8)(Dem_MemStorageManager_MemoryGetCurrentSize(MemoryInfo) - 1), MemoryIndex);                   /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */ /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
}

/* ****************************************************************************
 % Dem_Mem_PreInit
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Mem_PreInit(
  void
  )
{
  Dem_MemSet((Dem_DataPtrType)Dem_Cfg_EventInternalStatus,                                                                       /* PRQA S 0310, 0312, 0602, 3109 */ /* MD_DEM_11.4_cpy, MD_DEM_11.5, MD_DEM_20.2, MD_MSR_14.3 */ /* SBSW_DEM_MEMSET_EVENTINTERNALSTATUS */
             Dem_DTCInternalStatus_StoredStatus_None,
             Dem_Cfg_GlobalEventCount()*sizeof(Dem_Event_InternalStatusType));

#if (DEM_CFG_SUPPORT_DTR == STD_ON)
  Dem_Dtr_PreInit();
#endif
  Dem_EnableCondition_PreInit();
  Dem_StorageCondition_PreInit();
}

/* ****************************************************************************
 % Dem_Mem_Init
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Mem_Init(
  void
  )
{
  uint8 lResetStoredData;
  Dem_EventIdType lEventId;
#if (DEM_CFG_SUPPORT_DEBOUNCE_NV == STD_ON)
  uint16 lDebounceNvIndex = 0;
#endif

  for (lEventId = DEM_EVENT_FIRST; lEventId < Dem_Cfg_GlobalEventCount(); ++lEventId)
  { /* Only reset stored status, since debouncing can have changed since pre-initalization */
    Dem_Event_SetInternalStatus(lEventId,
      Dem_DTCInternalStatus_SetStoredStatus(Dem_Event_GetInternalStatus(lEventId), Dem_DTCInternalStatus_StoredStatus_None));

#if (DEM_CFG_SUPPORT_DEBOUNCE_NV == STD_ON)
    /* If NV storage of debounce values is configured, and the event uses that feature */
    /* Its safe to do it here since supporting events are not allowed to report before Dem_Init() */
    if (Dem_Cfg_EventSupportDebounceNv(lEventId) == TRUE)
    {
      sint16 lDebounceValue;
      boolean lFailedThresholdReached;

      Dem_Internal_AssertReturnVoid(lDebounceNvIndex < Dem_Cfg_GlobalDebounceStorageEventCount(), DEM_E_INCONSISTENT_STATE)

      lDebounceValue = Dem_Mem_DebounceGetStoredValue(lDebounceNvIndex);
      lFailedThresholdReached = Dem_UDSStatus_Test_TF(Dem_Event_GetUDSStatus(lEventId));

      Dem_SatelliteCore_RestoreDebounceValue(
        Dem_Cfg_EventSatelliteId(lEventId),
        Dem_Cfg_EventSatelliteEventId(lEventId),
        lDebounceValue,
        lFailedThresholdReached);

      ++lDebounceNvIndex;
    }
#endif
  }

#if (DEM_CFG_SUPPORT_TYPE1_COMBINATION == STD_ON)
  {
    Dem_Cfg_CombinedGroupIndexType lGroupId;
    for (lGroupId = 0; lGroupId < Dem_Cfg_GlobalCombinedGroupCount(); ++lGroupId)
    {
      Dem_Event_InternalStatusType lInternalStatus;
      Dem_Cfg_CombinedGroupIterType lSubEventIter;

      /* Initialize the combination group internal status */
      lInternalStatus = Dem_DTCInternalStatus_StoredStatus_None;

      /* For all combination groups, test if at least one sub-events is available by configuration.
         Initialization in PreInit and Init can have different settings for
         event availability, so repeat the calculation for combined DTCs */
      for (Dem_Cfg_CombinedGroupIterInit(lGroupId, &lSubEventIter);                                                              /* SBSW_DEM_CALL_ITERATOR_POINTER */
           Dem_Cfg_CombinedGroupIterExists(&lSubEventIter) == TRUE;                                                              /* SBSW_DEM_CALL_ITERATOR_POINTER */
           Dem_Cfg_CombinedGroupIterNext(&lSubEventIter))                                                                        /* SBSW_DEM_CALL_ITERATOR_POINTER */
      {
        if (Dem_Cfg_EventAvailableByVariant(Dem_Cfg_CombinedGroupIterGet(&lSubEventIter)) == TRUE)                               /* SBSW_DEM_CALL_ITERATOR_POINTER */
        { /* If so, set the availability in the combination status. */
          lInternalStatus = Dem_EventInternalStatus_SetAvailableInVariant(lInternalStatus);
          break;
        }
      }
      Dem_DTCInternalStatus_CombinedGroupSetInternalStatus(lGroupId, lInternalStatus);
    }
  }
#endif

  /* Initialize enable and storage conditions (based on configuration) */
  Dem_EnableCondition_Init();
#if (DEM_CFG_SUPPORT_STORAGE_CONDITIONS == STD_ON)
  Dem_StorageCondition_Init();
#endif

  /* Initialize transactional update commit numbers */
  Dem_MemSet(Dem_Cfg_MemoryCommitNumber, DEM_MEM_INIT_COMMIT_NUMBER, Dem_Cfg_GlobalNvBlockCount()*sizeof(uint8));                /* PRQA S 0312, 0602, 3109 */ /* MD_DEM_11.5, MD_DEM_20.2, MD_MSR_14.3 */ /* SBSW_DEM_MEMSET_MEMORYCOMMITNUMBER */

  lResetStoredData = (uint8)( (Dem_Cfg_AdminData.ImplementationVersion != Dem_Make16Bit(DEM_SW_MAJOR_VERSION, DEM_SW_MINOR_VERSION))  /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
                           || (Dem_Cfg_AdminData.ConfigurationId != Dem_Cfg_GlobalConfigurationId()) );

  if (lResetStoredData == TRUE)
  {
    /* If the NV data is not compatible to the configuration */
    /* Re-initialize all NV data content and reset the global time stamp */
    Dem_Cfg_MemoryIndexType lMemoryIndex;
    Dem_Cfg_MemoryIndexType lMemoryIndexEnd;

    Dem_Nvm_SetAllBlocksDirty();

    (void)Dem_NvM_InitAdminData();
    (void)Dem_NvM_InitStatusData();
#if (DEM_CFG_SUPPORT_DEBOUNCE_NV == STD_ON)
    (void)Dem_NvM_InitDebounceData();
#endif

    Dem_Mem_CurrentTimestamp = 1U;
    Dem_MemState_SetPrimaryCurrentCount(0U);

#if (DEM_CFG_SUPPORT_SECONDARY == STD_ON)
    Dem_MemState_SetSecondaryCurrentCount(0U);
#endif
    lMemoryIndexEnd = Dem_Mem_MemoryIndexAll_End();
    for (lMemoryIndex = Dem_Mem_MemoryIndexAll_Begin(); lMemoryIndex < lMemoryIndexEnd; ++lMemoryIndex)
    {
      Dem_MemoryEntry_Init(Dem_MemStorageManager_GetMemoryEntryId(lMemoryIndex));
      Dem_Mem_MemoryUpdateInit(lMemoryIndex);
    }
  }
  /* Otherwise */
  else
  {
    Dem_Mem_CurrentTimestamp = 0U;

    /* Rebuild the event memory control data from NV data contents */
    Dem_Memory_Init_RestoreMemory(Dem_MemStorageManager_MemoryInfoInit(DEM_CFG_MEMORYID_PRIMARY));                               /* SBSW_DEM_CALL_MEMORYINFO_POINTER */
#if (DEM_CFG_SUPPORT_SECONDARY == STD_ON)
    Dem_Memory_Init_RestoreMemory(Dem_MemStorageManager_MemoryInfoInit(DEM_CFG_MEMORYID_SECONDARY));                             /* SBSW_DEM_CALL_MEMORYINFO_POINTER */
#endif

  }
#if (DEM_CFG_SUPPORT_INDICATORS == STD_ON)
  {
    /* If indicators are configured, initialize all indicator state counters */
    uint8 lIndicatorId;
    for (lIndicatorId = 0; lIndicatorId < Dem_Cfg_GlobalIndicatorCount(); ++lIndicatorId)
    {
      {
        Dem_Mem_IndicatorSetEventCountContinuous(lIndicatorId, DEM_J1939_NODE_ID, 0);
        Dem_Mem_IndicatorSetEventCountBlinking(lIndicatorId, DEM_J1939_NODE_ID, 0);
      }
    }
  }
#endif

#if (DEM_CFG_SUPPORT_PRESTORED_FF == STD_ON)
  /* If prestore freeze frame is enabled, initialize freeze frame prestorage */
  Dem_Prestore_Init();
#endif

}                                                                                                                                /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* DEM_MEM_IMPLEMENTATION_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_Mem_Implementation.h
 *********************************************************************************************************************/
