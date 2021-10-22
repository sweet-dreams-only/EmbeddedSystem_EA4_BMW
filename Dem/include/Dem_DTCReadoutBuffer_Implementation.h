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
/*! \addtogroup Dem_DTCReadoutBuffer
 *  \{
 *  \file       Dem_DTCReadoutBuffer_Implementation.h
 *  \brief      Diagnostic Event Manager (Dem) Implementation file
 *  \details    Buffer event specific data after Dem_DisableDTCRecordUpdate() call.
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

#if !defined (DEM_DTCREADOUTBUFFER_IMPLEMENTATION_H)
#define DEM_DTCREADOUTBUFFER_IMPLEMENTATION_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                  /* Own subcomponent header */
/* ------------------------------------------------------------------------- */
#include "Dem_DTCReadoutBuffer_Interface.h"

                                                    /* Used subcomponent API */
/* ------------------------------------------------------------------------- */
#include "Dem_MemoryEntry_Implementation.h"
#include "Dem_SnapshotEntry_Implementation.h"
#include "Dem_ExtendedEntry_Implementation.h"
#include "Dem_DTCSelector_Implementation.h"
#include "Dem_Scheduler_Implementation.h"
#include "Dem_MemCopy.h"
#include "Dem_MemStorageManager_Implementation.h"

                                                   /* Subcomponents callbacks*/
/* ------------------------------------------------------------------------- */
#include "Dem_Error_Interface.h"

/* ********************************************************************************************************************
 *  SUBCOMPONENT CONSTANT MACROS
 *********************************************************************************************************************/

/*!
 * \addtogroup  Dem_DTCReadoutBuffer_StatusType
 * \{
 */
#define DEM_DTCREADOUTBUFFER_STATUS_UNUSED            0  /*!< Initialization value, buffer is unused and contains invalid data */
#define DEM_DTCREADOUTBUFFER_STATUS_QUEUED            1  /*!< Buffer contains EventId, MemoryId configuration - waiting for MainFunction to copy the data */
#define DEM_DTCREADOUTBUFFER_STATUS_IN_USE            2  /*!< Buffer contains configuration and event data */
#define DEM_DTCREADOUTBUFFER_STATUS_NOT_STORED        3  /*!< Buffer contains EventId, MemoryId configuration - no data found to copy */
/*!
 * \}
 */

/* ********************************************************************************************************************
 *  SUBCOMPONENT FUNCTION MACROS
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  SUBCOMPONENT DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  SUBCOMPONENT FUNCTION DEFINITIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*!
 * \addtogroup Dem_DTCReadoutBuffer_Properties
 * \{
 */

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_DTCReadoutBuffer_TestDataRequested
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_DTCReadoutBuffer_TestDataRequested(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId
  )
{
  boolean lReturnValue;

# if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (ReadoutBufferId >= Dem_Cfg_GetSizeOfReadoutBuffer())
  {
    Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
    lReturnValue = FALSE;
  }
  else
# endif
  {
    lReturnValue = (boolean)(Dem_DTCReadoutBuffer_GetState(ReadoutBufferId) != DEM_DTCREADOUTBUFFER_STATUS_UNUSED);
  }
  return lReturnValue;
}
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_DTCReadoutBuffer_TestResultReady
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_DTCReadoutBuffer_TestResultReady(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId
  )
{
  boolean lReturnValue;

# if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (ReadoutBufferId >= Dem_Cfg_GetSizeOfReadoutBuffer())
  {
    Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
    lReturnValue = TRUE;
  }
  else
# endif
  {
    Dem_DTCReadoutBuffer_StatusType lBufferStatus;
    lBufferStatus = Dem_DTCReadoutBuffer_GetState(ReadoutBufferId);
    lReturnValue = (boolean)( (lBufferStatus == DEM_DTCREADOUTBUFFER_STATUS_IN_USE)
                           || (lBufferStatus == DEM_DTCREADOUTBUFFER_STATUS_NOT_STORED) );
  }
  return lReturnValue;
}
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_DTCReadoutBuffer_TestStoredDataAvailable
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_DTCReadoutBuffer_TestStoredDataAvailable(                                                                                    /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId
  )
{
  boolean lReturnValue;

# if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (ReadoutBufferId >= Dem_Cfg_GetSizeOfReadoutBuffer())
  {
    Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
    lReturnValue = TRUE;
  }
  else
# endif
  {
    lReturnValue = (boolean)(Dem_DTCReadoutBuffer_GetState(ReadoutBufferId) == DEM_DTCREADOUTBUFFER_STATUS_IN_USE);
  }
  return lReturnValue;
}
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_DTCReadoutBuffer_TestExtendedRecordSelected
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_DTCReadoutBuffer_TestExtendedRecordSelected(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId
  )
{
  boolean lReturnValue;

# if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (ReadoutBufferId >= Dem_Cfg_GetSizeOfReadoutBuffer())
  {
    Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
    lReturnValue = FALSE;
  }
  else
# endif
  {
    lReturnValue = Dem_DTCReadoutBuffer_GetExtendedIterator(ReadoutBufferId).ExtendedRecordSelected;
  }
  return lReturnValue;
}
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_DTCReadoutBuffer_GetExtendedEntryIterator
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_ExtendedEntry_IterType, DEM_CODE)
Dem_DTCReadoutBuffer_GetExtendedEntryIterator(                                                                                   /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC)  ReadoutBufferId
  )
{
  return Dem_DTCReadoutBuffer_GetExtendedIterator(ReadoutBufferId).ExtendedEntryIter;
}
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_DTCReadoutBuffer_SetExtendedEntryIterator
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_DTCReadoutBuffer_SetExtendedEntryIterator(                                                                                   /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC)  ReadoutBufferId,
  CONST(Dem_ExtendedEntry_IterType, AUTOMATIC)  ExtendedEntryIter
  )
{
  Dem_DTCReadoutBuffer_ExtendedDataIteratorType lExtendedDataIter;

  lExtendedDataIter = Dem_DTCReadoutBuffer_GetExtendedIterator(ReadoutBufferId);
  lExtendedDataIter.ExtendedEntryIter = ExtendedEntryIter;
  Dem_DTCReadoutBuffer_SetExtendedIterator(ReadoutBufferId, lExtendedDataIter);
}
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_DTCReadoutBuffer_GetExtendedDataNumber
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_DTCReadoutBuffer_GetExtendedDataNumber(                                                                                      /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC)  ReadoutBufferId
  )
{
  return Dem_DTCReadoutBuffer_GetExtendedIterator(ReadoutBufferId).ExtendedDataNumber;
}
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_DTCReadoutBuffer_SetExtendedDataNumber
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_DTCReadoutBuffer_SetExtendedDataNumber(                                                                                      /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC)  ReadoutBufferId,
  CONST(uint8, AUTOMATIC)  ExtendedDataNumber
  )
{
  Dem_DTCReadoutBuffer_ExtendedDataIteratorType lExtendedDataIter;

  lExtendedDataIter = Dem_DTCReadoutBuffer_GetExtendedIterator(ReadoutBufferId);
  lExtendedDataIter.ExtendedDataNumber = ExtendedDataNumber;
  Dem_DTCReadoutBuffer_SetExtendedIterator(ReadoutBufferId, lExtendedDataIter);
}
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_DTCReadoutBuffer_TestSnapshotRecordSelected
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_DTCReadoutBuffer_TestSnapshotRecordSelected(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId
  )
{
  boolean lReturnValue;

# if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (ReadoutBufferId >= Dem_Cfg_GetSizeOfReadoutBuffer())
  {
    Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
    lReturnValue = FALSE;
  }
  else
# endif
  {
    lReturnValue = Dem_DTCReadoutBuffer_GetSnapshotIterator(ReadoutBufferId).SnapshotSelected;
  }
  return lReturnValue;
}
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_DTCReadoutBuffer_GetSnapshotEntryIterator
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_SnapshotEntry_IterType, DEM_CODE)
Dem_DTCReadoutBuffer_GetSnapshotEntryIterator(                                                                                   /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC)  ReadoutBufferId
)
{
  return Dem_DTCReadoutBuffer_GetSnapshotIterator(ReadoutBufferId).SnapshotEntryIter;
}
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_DTCReadoutBuffer_SetSnapshotEntryIterator
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_DTCReadoutBuffer_SetSnapshotEntryIterator(                                                                                   /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC)  ReadoutBufferId,
  CONST(Dem_SnapshotEntry_IterType, AUTOMATIC)  SnapshotEntryIter
)
{
  Dem_DTCReadoutBuffer_SnapshotDataIteratorType lSnapshotDataIterator;

  lSnapshotDataIterator = Dem_DTCReadoutBuffer_GetSnapshotIterator(ReadoutBufferId);
  lSnapshotDataIterator.SnapshotEntryIter = SnapshotEntryIter;
  Dem_DTCReadoutBuffer_SetSnapshotIterator(ReadoutBufferId, lSnapshotDataIterator);
}
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_DTCReadoutBuffer_GetSnapshotRecordNumber
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_DTCReadoutBuffer_GetSnapshotRecordNumber(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC)  ReadoutBufferId
)
{
  return Dem_DTCReadoutBuffer_GetSnapshotIterator(ReadoutBufferId).RecordNumber;
}
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_DTCReadoutBuffer_GetSnapshotRecordSource
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_DTCReadoutBuffer_SnapshotSourceType, DEM_CODE)
Dem_DTCReadoutBuffer_GetSnapshotRecordSource(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC)  ReadoutBufferId
)
{
  return Dem_DTCReadoutBuffer_GetSnapshotIterator(ReadoutBufferId).Source;
}
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_DTCReadoutBuffer_SetSnapshotRecordSource
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_DTCReadoutBuffer_SetSnapshotRecordSource(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC)  ReadoutBufferId,
  CONST(Dem_DTCReadoutBuffer_SnapshotSourceType, AUTOMATIC)  Source
)
{
  Dem_DTCReadoutBuffer_SnapshotDataIteratorType lSnapshotDataIterator;

  lSnapshotDataIterator = Dem_DTCReadoutBuffer_GetSnapshotIterator(ReadoutBufferId);
  lSnapshotDataIterator.Source = Source;
  Dem_DTCReadoutBuffer_SetSnapshotIterator(ReadoutBufferId, lSnapshotDataIterator);
}
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_DTCReadoutBuffer_GetSnapshotSourceIterator
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_Cfg_ComplexIterType, DEM_CODE)
Dem_DTCReadoutBuffer_GetSnapshotSourceIterator(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC)  ReadoutBufferId
)
{
  return Dem_DTCReadoutBuffer_GetSnapshotIterator(ReadoutBufferId).SourceIterator;
}
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_DTCReadoutBuffer_SetSnapshotSourceIterator
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_DTCReadoutBuffer_SetSnapshotSourceIterator(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC)  ReadoutBufferId,
  CONST(Dem_Cfg_ComplexIterType, AUTOMATIC)  SourceIterator
)
{
  Dem_DTCReadoutBuffer_SnapshotDataIteratorType lSnapshotDataIterator;

  lSnapshotDataIterator = Dem_DTCReadoutBuffer_GetSnapshotIterator(ReadoutBufferId);
  lSnapshotDataIterator.SourceIterator = SourceIterator;
  Dem_DTCReadoutBuffer_SetSnapshotIterator(ReadoutBufferId, lSnapshotDataIterator);
}
#endif

/* ****************************************************************************
 % Dem_DTCReadoutBuffer_GetMemoryEntryId
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_MemoryEntry_HandleType, DEM_CODE)
Dem_DTCReadoutBuffer_GetMemoryEntryId(                                                                                           /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId
  )
{
  return (DEM_MEMORYENTRY_HANDLE_READOUTBUFFER + ReadoutBufferId);
}

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \addtogroup Dem_DTCReadoutBuffer_Private
 * \{
 */

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_DTCReadoutBuffer_ExtendedDataRecord_Init
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_DTCReadoutBuffer_ExtendedDataRecord_Init(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId
)
{
  Dem_DTCReadoutBuffer_ExtendedDataIteratorType lExtendedDataIterator;

  lExtendedDataIterator = Dem_DTCReadoutBuffer_GetExtendedIterator(ReadoutBufferId);
# if(DEM_CFG_SUPPORT_ERECS == STD_ON)
  Dem_ExtendedEntry_IteratorInit(DEM_EVENT_INVALID, DEM_MEMORYENTRY_HANDLE_INVALID, &(lExtendedDataIterator.ExtendedEntryIter));
# endif
  lExtendedDataIterator.ExtendedDataNumber = 0;
  lExtendedDataIterator.ExtendedRecordSelected = FALSE;

  Dem_DTCReadoutBuffer_SetExtendedIterator(ReadoutBufferId, lExtendedDataIterator);
}
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_DTCReadoutBuffer_SnapshotRecord_Init
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_DTCReadoutBuffer_SnapshotRecord_Init(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId
  )
{
  Dem_DTCReadoutBuffer_SnapshotDataIteratorType lSnapshotDataIterator;

  lSnapshotDataIterator = Dem_DTCReadoutBuffer_GetSnapshotIterator(ReadoutBufferId);

  Dem_Cfg_ComplexIterClear(&(lSnapshotDataIterator.SourceIterator));
# if (DEM_CFG_SUPPORT_SRECS == STD_ON)
  Dem_SnapshotEntry_IteratorInit(DEM_EVENT_INVALID, DEM_MEMORYENTRY_HANDLE_INVALID, &(lSnapshotDataIterator.SnapshotEntryIter));
# endif
  lSnapshotDataIterator.RecordNumber = 0;
  lSnapshotDataIterator.Source = Dem_DTCReadoutBuffer_SnapshotSource_Invalid;
  lSnapshotDataIterator.SnapshotSelected = FALSE;

  Dem_DTCReadoutBuffer_SetSnapshotIterator(ReadoutBufferId, lSnapshotDataIterator);
}
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_DTCReadoutBuffer_GetExtendedIterator
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_DTCReadoutBuffer_ExtendedDataIteratorType, DEM_CODE)
Dem_DTCReadoutBuffer_GetExtendedIterator(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId
  )
{
  Dem_DTCReadoutBuffer_ExtendedDataIteratorType lReturnValue;

# if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (ReadoutBufferId >= Dem_Cfg_GetSizeOfReadoutBuffer())
  {
    Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
    lReturnValue = Dem_Cfg_GetReadoutBuffer(0).ExtendedIterator;
  }
  else
# endif
  {
    lReturnValue = Dem_Cfg_GetReadoutBuffer(ReadoutBufferId).ExtendedIterator;
  }
  return lReturnValue;
}
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_DTCReadoutBuffer_SetExtendedIterator
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_DTCReadoutBuffer_SetExtendedIterator(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC)  ReadoutBufferId,
  CONST(Dem_DTCReadoutBuffer_ExtendedDataIteratorType, AUTOMATIC)  ExtendedDataIterator
  )
{
# if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (ReadoutBufferId >= Dem_Cfg_GetSizeOfReadoutBuffer())
  {
    Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
  }
  else
# endif
  {
    Dem_Cfg_GetReadoutBuffer(ReadoutBufferId).ExtendedIterator = ExtendedDataIterator;
  }
}
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_DTCReadoutBuffer_GetSnapshotIterator
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_DTCReadoutBuffer_SnapshotDataIteratorType, DEM_CODE)
Dem_DTCReadoutBuffer_GetSnapshotIterator(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId
  )
{
  Dem_DTCReadoutBuffer_SnapshotDataIteratorType lReturnValue;

# if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (ReadoutBufferId >= Dem_Cfg_GetSizeOfReadoutBuffer())
  {
    Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
    lReturnValue.SnapshotSelected = FALSE;
  }
  else
# endif
  {
    lReturnValue = Dem_Cfg_GetReadoutBuffer(ReadoutBufferId).SnapshotIterator;
  }
  return lReturnValue;
}
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_DTCReadoutBuffer_SetSnapshotIterator
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_DTCReadoutBuffer_SetSnapshotIterator(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC)  ReadoutBufferId,
  CONST(Dem_DTCReadoutBuffer_SnapshotDataIteratorType, AUTOMATIC)  SnapshotIterator
  )
{
# if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (ReadoutBufferId >= Dem_Cfg_GetSizeOfReadoutBuffer())
  {
    Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
  }
  else
# endif
  {
    Dem_Cfg_GetReadoutBuffer(ReadoutBufferId).SnapshotIterator = SnapshotIterator;
  }
}
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_DTCReadoutBuffer_SetState
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_DTCReadoutBuffer_SetState(
    CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId,
    CONST(Dem_DTCReadoutBuffer_StatusType, AUTOMATIC) NewState
    )
{
# if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (ReadoutBufferId >= Dem_Cfg_GetSizeOfReadoutBuffer())
  {
    Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
  }
  else
# endif
  {
    Dem_Cfg_GetReadoutBuffer(ReadoutBufferId).State = NewState;
  }
}
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_DTCReadoutBuffer_GetState
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_DTCReadoutBuffer_StatusType, DEM_CODE)
Dem_DTCReadoutBuffer_GetState(
    CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId
    )
{
  return Dem_Cfg_GetReadoutBuffer(ReadoutBufferId).State;
}
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_DTCReadoutBuffer_SetMemoryId
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_DTCReadoutBuffer_SetMemoryId(
    CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId,
    CONST(uint8, AUTOMATIC) NewMemoryId
    )
{
# if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (ReadoutBufferId >= Dem_Cfg_GetSizeOfReadoutBuffer())
  {
    Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
  }
  else
# endif
  {
    Dem_Cfg_GetReadoutBuffer(ReadoutBufferId).MemoryId = NewMemoryId;
  }
}
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_DTCReadoutBuffer_SetEventId
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_DTCReadoutBuffer_SetEventId(
    CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId,
    CONST(Dem_EventIdType, AUTOMATIC) NewEventId
    )
{
# if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (ReadoutBufferId >= Dem_Cfg_GetSizeOfReadoutBuffer())
  {
    Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
  }
  else
# endif
  {
    Dem_Cfg_GetReadoutBuffer(ReadoutBufferId).EventId = NewEventId;
  }
}
#endif

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \addtogroup Dem_DTCReadoutBuffer_Public
 * \{
 */

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_DTCReadoutBuffer_Init
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_DTCReadoutBuffer_Init(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId
  )
{
  Dem_DTCReadoutBuffer_SetState(ReadoutBufferId, DEM_DTCREADOUTBUFFER_STATUS_UNUSED);

  Dem_DTCReadoutBuffer_ExtendedDataRecord_Init(ReadoutBufferId);
  Dem_DTCReadoutBuffer_SnapshotRecord_Init(ReadoutBufferId);
}
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_DTCReadoutBuffer_CheckAndSetState
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
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_DTCReadoutBuffer_CheckAndSetState(
    CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId,
    CONST(Dem_EventIdType, AUTOMATIC)                 EventId,
    CONST(uint8, AUTOMATIC)                           MemoryId,
    CONST(Dem_DTCSelector_HandleType, AUTOMATIC)      DTCSelector
    )
{
  Std_ReturnType lReturnValue;
  Dem_DTCReadoutBuffer_StatusType lState;

  lState = Dem_DTCReadoutBuffer_GetState(ReadoutBufferId);
  if (lState == DEM_DTCREADOUTBUFFER_STATUS_UNUSED)
  {
    /* new request */
    Dem_DTCSelector_LockSelectDTC(DTCSelector);
    Dem_DTCReadoutBuffer_SetEventId(ReadoutBufferId, EventId);
    Dem_DTCReadoutBuffer_SetMemoryId(ReadoutBufferId, MemoryId);
    Dem_DTCReadoutBuffer_ExtendedDataRecord_Init(ReadoutBufferId);
    Dem_DTCReadoutBuffer_SnapshotRecord_Init(ReadoutBufferId);
    /* The task function could be active already due to another client. 
       Set the state last, otherwise the task could process this entry before
       it is copmletely initialized */
    Dem_DTCReadoutBuffer_SetState(ReadoutBufferId, DEM_DTCREADOUTBUFFER_STATUS_QUEUED);
    Dem_Scheduler_EnableTaskOnce(Dem_Scheduler_Task_FilterEventData);
    lReturnValue = DEM_PENDING;
  }
  else 
  if (EventId == Dem_DTCReadoutBuffer_GetEventId(ReadoutBufferId))
  {
    if (MemoryId == Dem_DTCReadoutBuffer_GetMemoryId(ReadoutBufferId))
    {
      /* repeated request with identical parameters */
      if (lState == DEM_DTCREADOUTBUFFER_STATUS_QUEUED)
      {
        /* request is still queued, copying of data is not finished */
        lReturnValue = DEM_PENDING;
      }
      else
      {
        /* copying of data is finished */
        lReturnValue = E_OK;
      }
    }
    else
    {
      /* repeated request with different parameters */
      lReturnValue = E_NOT_OK;
    }
  }
  else
  {
    /* repeated request with different parameters */
    lReturnValue = E_NOT_OK;
  }

  return lReturnValue;
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
% Dem_DTCReadoutBuffer_FillData
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
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_DTCReadoutBuffer_FillData(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId,
  CONST(Dem_DTCSelector_HandleType, AUTOMATIC)      DTCSelector
)
{
  if (ReadoutBufferId != DEM_CFG_READOUTBUFFER_INVALID)
  {
    /* copy memory entry only for readout buffer in state QUEUED */
    if (Dem_DTCReadoutBuffer_GetState(ReadoutBufferId) == DEM_DTCREADOUTBUFFER_STATUS_QUEUED)
    {
      Dem_EventIdType lEventId;
      Dem_Mem_MemoryInfoPtrType lMemoryInfo;
      Dem_Cfg_MemoryIndexType lMemoryIndex;

      lEventId = Dem_DTCReadoutBuffer_GetEventId(ReadoutBufferId);
      lMemoryInfo = Dem_MemStorageManager_MemoryInfoInit(Dem_DTCReadoutBuffer_GetMemoryId(ReadoutBufferId));

      lMemoryIndex = Dem_MemStorageManager_MemoryFindIndex(lMemoryInfo, lEventId);                                                             /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
      if (lMemoryIndex == DEM_MEM_INVALID_MEMORY_INDEX)
      {
        Dem_Data_EntryInit(Dem_DTCReadoutBuffer_GetMemoryEntryId(ReadoutBufferId));
        Dem_EnterCritical_DcmApi();
        if (Dem_DTCReadoutBuffer_GetState(ReadoutBufferId) == DEM_DTCREADOUTBUFFER_STATUS_QUEUED)
        {
          Dem_DTCReadoutBuffer_SetState(ReadoutBufferId, DEM_DTCREADOUTBUFFER_STATUS_NOT_STORED);
          Dem_DTCSelector_ReleaseSelectDTC(DTCSelector);
        }
        Dem_LeaveCritical_DcmApi();
      }
      else
      {
        Dem_MemoryEntry_CopyEntry(Dem_DTCReadoutBuffer_GetMemoryEntryId(ReadoutBufferId), Dem_MemStorageManager_GetMemoryEntryId(lMemoryIndex));
        Dem_EnterCritical_DcmApi();
        if (Dem_DTCReadoutBuffer_GetState(ReadoutBufferId) == DEM_DTCREADOUTBUFFER_STATUS_QUEUED)
        {
          Dem_DTCReadoutBuffer_SetState(ReadoutBufferId, DEM_DTCREADOUTBUFFER_STATUS_IN_USE);
          Dem_DTCSelector_ReleaseSelectDTC(DTCSelector);
        }
        Dem_LeaveCritical_DcmApi();
      }

# if (DEM_FEATURE_NEED_TIME_SERIES == STD_ON)
      lMemoryIndex = Dem_Mem_TimeSeriesFindIndex(lEventId);
      if (lMemoryIndex == DEM_MEM_INVALID_MEMORY_INDEX)
      {
        /* no time series entry for event - there is no data to be copied */
        /* Mark the buffer as unused - this can be used to verify the validity of statistic records */
        Dem_Cfg_TimeSeriesReadoutBuffer.EventId = DEM_EVENT_INVALID;
        /* Initialize 'no record stored', this allows a common test for the validity of stored records */
        Dem_TimeSeriesData_EntryInit(&Dem_Cfg_TimeSeriesReadoutBuffer);                                                          /* SBSW_DEM_POINTER_FORWARD_GLOBAL */
      }
      else
      {
        /* copy time series entry */
        Dem_MemCpy((Dem_DataPtrType)(&Dem_Cfg_TimeSeriesReadoutBuffer),                                                          /* PRQA S 0310, 3305, 0602 */ /* MD_DEM_11.4_cpy, MD_DEM_3305, MD_DEM_20.2 */ /* SBSW_DEM_POINTER_MEMCPY_TIMESERIESREADOUTBUFFER */
          (Dem_NvDataPtrType)(Dem_Mem_TimeSeriesGetEntry(lMemoryIndex)),
          sizeof(Dem_Cfg_TimeSeriesReadoutBuffer));
      }
# endif
    }
  }
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
% Dem_DTCReadoutBuffer_FreeBuffer
*****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_DTCReadoutBuffer_FreeBuffer(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId,
  CONST(Dem_DTCSelector_HandleType, AUTOMATIC)      DTCSelector
  )
{
  Dem_EnterCritical_DcmApi();
  if (Dem_DTCReadoutBuffer_GetState(ReadoutBufferId) == DEM_DTCREADOUTBUFFER_STATUS_QUEUED)
  {
    Dem_DTCSelector_ReleaseSelectDTC(DTCSelector);
  }
  Dem_DTCReadoutBuffer_SetState(ReadoutBufferId, DEM_DTCREADOUTBUFFER_STATUS_UNUSED);
  Dem_LeaveCritical_DcmApi();
}
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
% Dem_DTCReadoutBuffer_GetEventId
*****************************************************************************/
/*!
* Internal comment removed.
 *
 *
*****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_EventIdType, DEM_CODE)
Dem_DTCReadoutBuffer_GetEventId(
    CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId
    )
{
  return (Dem_EventIdType)Dem_Cfg_GetReadoutBuffer(ReadoutBufferId).EventId;
}
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_DTCReadoutBuffer_GetMemoryId
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_DTCReadoutBuffer_GetMemoryId(                                                                                                /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId
  )
{
  return Dem_Cfg_GetReadoutBuffer(ReadoutBufferId).MemoryId;
}
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_DTCReadoutBuffer_SelectExtendedDataRecord
 *****************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_DTCReadoutBuffer_SelectExtendedDataRecord(
CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId,
CONST(uint8, AUTOMATIC) ExtendedDataNumber
)
{
  Dem_DTCReadoutBuffer_ExtendedDataIteratorType lExtendedDataIterator;

  lExtendedDataIterator = Dem_DTCReadoutBuffer_GetExtendedIterator(ReadoutBufferId);

# if (DEM_CFG_SUPPORT_ERECS == STD_ON) 
  {
    Dem_EventIdType lEventId;

    lEventId = Dem_DTCReadoutBuffer_GetEventId(ReadoutBufferId);
    Dem_ExtendedEntry_IteratorInit(lEventId, Dem_DTCReadoutBuffer_GetMemoryEntryId(ReadoutBufferId), &(lExtendedDataIterator.ExtendedEntryIter));
  }
# endif
  lExtendedDataIterator.ExtendedDataNumber = ExtendedDataNumber;
  lExtendedDataIterator.ExtendedRecordSelected = TRUE;

  Dem_DTCReadoutBuffer_SetExtendedIterator(ReadoutBufferId, lExtendedDataIterator);
}
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
% Dem_DTCReadoutBuffer_SelectSnapshotRecord
*****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_DTCReadoutBuffer_SelectSnapshotRecord(
CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId,
CONST(uint8, AUTOMATIC) RecordNumber
)
{
  Dem_DTCReadoutBuffer_SnapshotDataIteratorType lSnapshotDataIterator;

  lSnapshotDataIterator = Dem_DTCReadoutBuffer_GetSnapshotIterator(ReadoutBufferId);

# if (DEM_CFG_SUPPORT_SRECS == STD_ON)
  {
    Dem_EventIdType lEventId;

    lEventId = Dem_DTCReadoutBuffer_GetEventId(ReadoutBufferId);
    Dem_SnapshotEntry_IteratorInit(lEventId, Dem_DTCReadoutBuffer_GetMemoryEntryId(ReadoutBufferId), &(lSnapshotDataIterator.SnapshotEntryIter));
  }
# endif
  lSnapshotDataIterator.RecordNumber = RecordNumber;
  lSnapshotDataIterator.Source = Dem_DTCReadoutBuffer_SnapshotSource_Invalid;
  lSnapshotDataIterator.SnapshotSelected = TRUE;
  Dem_Cfg_ComplexIterClear(&(lSnapshotDataIterator.SourceIterator));

  Dem_DTCReadoutBuffer_SetSnapshotIterator(ReadoutBufferId, lSnapshotDataIterator);
}
#endif

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* DEM_DTCREADOUTBUFFER_IMPLEMENTATION_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_DTCReadoutBuffer_Implementation.h
 *********************************************************************************************************************/
