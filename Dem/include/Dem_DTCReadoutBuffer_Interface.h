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
/*! \ingroup    Dem_ClientAccess
 *  \defgroup   Dem_DTCReadoutBuffer DTCReadoutBuffer
 *  \{
 *  \file       Dem_DTCReadoutBuffer_Interface.h
 *  \brief      Diagnostic Event Manager (Dem) Interface declaration file
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

#if !defined (DEM_DTCREADOUTBUFFER_INTERFACE_H)
#define DEM_DTCREADOUTBUFFER_INTERFACE_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                        /* Dem module header */
/* ------------------------------------------------------------------------- */
#include "Dem_DTCReadoutBuffer_Types.h"
/* ------------------------------------------------------------------------- */


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
 * \defgroup Dem_DTCReadoutBuffer_Properties Properties
 * \{
 */

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 * Dem_DTCReadoutBuffer_TestDataRequested
 *****************************************************************************/
/*!
 * \brief         Returns whether data was requested for the given buffer
 *
 * \details       Returns whether data was requested for the given buffer
 *
 * \param[in]     ReadoutBufferId
 *                Index of the ReadoutBuffer
 *
 * \return        TRUE
 *                The given buffer contains or will contain data
 * \return        FALSE
 *                There is no data requested for the given buffer
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_DTCReadoutBuffer_TestDataRequested(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId
  );
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 * Dem_DTCReadoutBuffer_TestResultReady
 *****************************************************************************/
/*!
 * \brief         Returns whether the result of the data selection is available
 *
 * \details       Returns whether the result of the data selection is available
 *
 * \param[in]     ReadoutBufferId
 *                Index of the ReadoutBuffer
 *
 * \return        TRUE
 *                The given buffer is ready.
 * \return        FALSE
 *                The given buffer is still updating.
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_DTCReadoutBuffer_TestResultReady(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId
  );
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 * Dem_DTCReadoutBuffer_TestStoredDataAvailable
 *****************************************************************************/
/*!
 * \brief         Returns whether data is stored or not
 *
 * \details       Returns whether data is stored or not
 *
 * \param[in]     ReadoutBufferId
 *                Index of the ReadoutBuffer
 *
 * \return        TRUE
 *                The buffer holds the data stored for the requested event
 * \return        FALSE
 *                There is no stored data for the requested event
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_DTCReadoutBuffer_TestStoredDataAvailable(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId
  );
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 * Dem_DTCReadoutBuffer_TestExtendedRecordSelected
 *****************************************************************************/
/*!
 * \brief         Returns whether an extended data record is selected
 *
 * \details       Returns whether an extended data record is selected
 *
 * \param[in]     ReadoutBufferId
 *                Index of the ReadoutBuffer
 *
 * \return        TRUE
 *                An extended data record has been selected
 * \return        FALSE
 *                No extended data record has been selected
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_DTCReadoutBuffer_TestExtendedRecordSelected(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId
  );
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 * Dem_DTCReadoutBuffer_GetExtendedEntryIterator
 *****************************************************************************/
/*!
 * \brief         Returns the extended entry iterator
 *
 * \details       Returns the extended entry iterator
 *
 * \param[in]     ReadoutBufferId
 *                Index of the ReadoutBuffer
 *
 * \return        The extended entry iterator
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_ExtendedEntry_IterType, DEM_CODE)
Dem_DTCReadoutBuffer_GetExtendedEntryIterator(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC)  ReadoutBufferId
  );
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 * Dem_DTCReadoutBuffer_SetExtendedEntryIterator
 *****************************************************************************/
/*!
 * \brief         Sets the extended entry iterator
 *
 * \details       Sets the extended entry iterator
 *
 * \param[in,out] ReadoutBufferId
 *                Index of the ReadoutBuffer
 * \param[in]     ExtendedEntryIter
 *                The new extended entry iterator
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_DTCReadoutBuffer_SetExtendedEntryIterator(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC)  ReadoutBufferId,
  CONST(Dem_ExtendedEntry_IterType, AUTOMATIC)  ExtendedEntryIter
  );
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 * Dem_DTCReadoutBuffer_GetExtendedDataNumber
 *****************************************************************************/
/*!
 * \brief         Returns the extended data record number
 *
 * \details       Returns the extended data record number
 *
 * \param[in]     ReadoutBufferId
 *                Index of the ReadoutBuffer
 *
 * \return        The extended data record number
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_DTCReadoutBuffer_GetExtendedDataNumber(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC)  ReadoutBufferId
  );                                                                                                                             /* PRQA S 0779 */ /* MD_MSR_5.1_779 */
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 * Dem_DTCReadoutBuffer_SetExtendedDataNumber
 *****************************************************************************/
/*!
 * \brief         Sets the extended data record number
 *
 * \details       Sets the extended data record number
 *
 * \param[in,out] ReadoutBufferId
 *                Index of the ReadoutBuffer
 * \param[in]     ExtendedDataNumber
 *                The new extended data record number
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_DTCReadoutBuffer_SetExtendedDataNumber(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC)  ReadoutBufferId,
  CONST(uint8, AUTOMATIC)  ExtendedDataNumber
  );                                                                                                                             /* PRQA S 0779 */ /* MD_MSR_5.1_779 */
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 * Dem_DTCReadoutBuffer_TestSnapshotRecordSelected
 *****************************************************************************/
/*!
 * \brief         Returns whether a snapshot record is selected
 *
 * \details       Returns whether a snapshot record is selected
 *
 * \param[in]     ReadoutBufferId
 *                Index of the ReadoutBuffer
 *
 * \return        TRUE
 *                A snapshot record has been selected
 * \return        FALSE
 *                No snapshot record has been selected
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_DTCReadoutBuffer_TestSnapshotRecordSelected(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId
  );
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 * Dem_DTCReadoutBuffer_GetSnapshotEntryIterator
 *****************************************************************************/
/*!
 * \brief         Returns the snapshot record entry iterator
 *
 * \details       Returns the snapshot record entry iterator
 *
 * \param[in]     ReadoutBufferId
 *                Index of the ReadoutBuffer
 *
 * \return        The snapshot record entry iterator
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_SnapshotEntry_IterType, DEM_CODE)
Dem_DTCReadoutBuffer_GetSnapshotEntryIterator(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC)  ReadoutBufferId
);
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 * Dem_DTCReadoutBuffer_SetSnapshotEntryIterator
 *****************************************************************************/
/*!
 * \brief         Sets the snapshot record entry iterator
 *
 * \details       Sets the snapshot record entry iterator
 *
 * \param[in,out] ReadoutBufferId
 *                Index of the ReadoutBuffer
 * \param[in]     SnapshotEntryIter
 *                The new value
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_DTCReadoutBuffer_SetSnapshotEntryIterator(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC)  ReadoutBufferId,
  CONST(Dem_SnapshotEntry_IterType, AUTOMATIC)  SnapshotEntryIter
  );                                                                                                                             /* PRQA S 0779 */ /* MD_MSR_5.1_779 */
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 * Dem_DTCReadoutBuffer_GetSnapshotRecordNumber
 *****************************************************************************/
/*!
 * \brief         Returns the 
 *
 * \details       Returns the 
 *
 * \param[in]     ReadoutBufferId
 *                Index of the ReadoutBuffer
 *
 * \return        The record number of the selected snapshot record
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_DTCReadoutBuffer_GetSnapshotRecordNumber(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC)  ReadoutBufferId
  );                                                                                                                             /* PRQA S 0779 */ /* MD_MSR_5.1_779 */
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 * Dem_DTCReadoutBuffer_GetSnapshotRecordSource
 *****************************************************************************/
/*!
 * \brief         Returns the source
 *
 * \details       Returns the snapshot record source
 *
 * \param[in]     ReadoutBufferId
 *                Index of the ReadoutBuffer
 *
 * \return        The source
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_DTCReadoutBuffer_SnapshotSourceType, DEM_CODE)
Dem_DTCReadoutBuffer_GetSnapshotRecordSource(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC)  ReadoutBufferId
  );                                                                                                                             /* PRQA S 0779 */ /* MD_MSR_5.1_779 */
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 * Dem_DTCReadoutBuffer_SetSnapshotRecordSource
 *****************************************************************************/
/*!
 * \brief         Sets the snapshot source type
 *
 * \details       Sets the snapshot source type
 *
 * \param[in,out] ReadoutBufferId
 *                Index of the ReadoutBuffer
 * \param[in]     Source
 *                The new value
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_DTCReadoutBuffer_SetSnapshotRecordSource(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC)  ReadoutBufferId,
  CONST(Dem_DTCReadoutBuffer_SnapshotSourceType, AUTOMATIC)  Source
  );                                                                                                                             /* PRQA S 0779 */ /* MD_MSR_5.1_779 */
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 * Dem_DTCReadoutBuffer_GetSnapshotSourceIterator
 *****************************************************************************/
/*!
 * \brief         Returns the source iterator
 *
 * \details       Returns the source iterator
 *
 * \param[in]     ReadoutBufferId
 *                Index of the ReadoutBuffer
 *
 * \return        The source iterator
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_Cfg_ComplexIterType, DEM_CODE)
Dem_DTCReadoutBuffer_GetSnapshotSourceIterator(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC)  ReadoutBufferId
  );                                                                                                                             /* PRQA S 0779 */ /* MD_MSR_5.1_779 */
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 * Dem_DTCReadoutBuffer_SetSnapshotSourceIterator
 *****************************************************************************/
/*!
 * \brief         Sets the source iterator
 *
 * \details       Sets the source iterator
 *
 * \param[in,out] ReadoutBufferId
 *                Index of the ReadoutBuffer
 * \param[in]     SourceIterator
 *                The new value
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_DTCReadoutBuffer_SetSnapshotSourceIterator(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC)  ReadoutBufferId,
  CONST(Dem_Cfg_ComplexIterType, AUTOMATIC)  SourceIterator
);                                                                                                                               /* PRQA S 0779 */ /* MD_MSR_5.1_779 */
#endif

/* ****************************************************************************
 * Dem_DTCReadoutBuffer_GetMemoryEntryId
 *****************************************************************************/
/*!
 * \brief         Returns the memory entry Id for the given readout buffer
 *
 * \details       Returns the memory entry Id for the given readout buffer
 *
 * \param[in]     ReadoutBufferId
 *                Index of the ReadoutBuffer
 *
 * \return        The memory entry Id
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_MemoryEntry_HandleType, DEM_CODE)
Dem_DTCReadoutBuffer_GetMemoryEntryId(                                                                                           /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId
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
 * \defgroup Dem_DTCReadoutBuffer_Public Public Methods
 * \{
 */

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 * Dem_DTCReadoutBuffer_Init
 *****************************************************************************/
/*!
 * \brief         Initialize memory entry.
 *
 * \details       Initialize memory entry.
 *
 * \param[in]     ReadoutBufferId
 *                Index of the ReadoutBuffer, derived from the ClientId.
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE for different ReadoutBuffer Ids
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_DTCReadoutBuffer_Init(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId
  );
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 * Dem_DTCReadoutBuffer_CheckAndSetState
 *****************************************************************************/
/*!
 * \brief         Check state of a ReadoutBuffer entry, save current request if
 *                it is new.
 *
 * \details       Check state of a ReadoutBuffer entry, save current request if
 *                it is new.
 *
 * \param[in]     ReadoutBufferId
 *                Index of the ReadoutBuffer, derived from the ClientId.
 * \param[in]     EventId
 *                New EventId for comparison, stored in ReadoutBuffer with a
 *                new request.
 * \param[in]     MemoryId
 *                New MemoryId for comparison, stored in ReadoutBuffer with a
 *                new request.
 * \param[in]     DTCSelector
 *                Handle for DTC Selector
 *
 * \return        E_OK
 *                ReadoutBuffer contains given EventId, MemoryId
 *                configuration and the copying of event data (MainFunction)
 *                has finished - current request is identical repetition of
 *                previous, no data change.
 * \return        DEM_PENDING
 *                Either ReadoutBuffer is unused, so it contains no valid
 *                data - store current request as new request and QUEUE it for
 *                MainFunction to copy the event data.
 *                Or ReadoutBuffer contains given EventId, MemoryId
 *                configuration but the copying of event data (MainFunction)
 *                has NOT finished yet - no data change.
 * \return        E_NOT_OK
 *                ReadoutBuffer contains different EventId, MemoryId
 *                configuration, current request is different to previous -
 *                no data change.
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE for different ReadoutBuffer Ids
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_DTCReadoutBuffer_CheckAndSetState(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId,
  CONST(Dem_EventIdType, AUTOMATIC)                 EventId,
  CONST(uint8, AUTOMATIC)                           MemoryId,
  CONST(Dem_DTCSelector_HandleType, AUTOMATIC)      DTCSelector
  );                                                                                                                             /* PRQA S 0779 */ /* MD_MSR_5.1_779 */
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 * Dem_DTCReadoutBuffer_FillData
 *****************************************************************************/
/*!
 * \brief         Populate readout buffer with data.
 *
 * \details       Populate readout buffer with data by copying the record from
 *                the primary/secondary memory.
 *
 * \param[in]     ReadoutBufferId
 *                Index of the ReadoutBuffer, derived from the ClientId.
 * \param[in]     DTCSelector
 *                Handle for DTC Selector 
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE for different ReadoutBuffer Ids
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
  Dem_DTCReadoutBuffer_FillData(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId,
  CONST(Dem_DTCSelector_HandleType, AUTOMATIC)      DTCSelector
  );
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 * Dem_DTCReadoutBuffer_FreeBuffer
 *****************************************************************************/
/*!
 * \brief         Release the memory entry.
 *
 * \details       Release the memory entry calling Dem_EnableDTCRecordUpdate.
 * 
 * \param[in]     ReadoutBufferId
 *                Index of the ReadoutBuffer, derived from the ClientId.
 * \param[in]     DTCSelector
 *                Handle for DTC Selector 
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE for different ReadoutBuffer Ids
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_DTCReadoutBuffer_FreeBuffer(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId,
  CONST(Dem_DTCSelector_HandleType, AUTOMATIC)      DTCSelector
  );
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 * Dem_DTCReadoutBuffer_GetEventId
 *****************************************************************************/
/*!
 * \brief         Get EventId of readout buffer.
 *
 * \details       Get EventId of readout buffer.
 *
 * \param[in]     ReadoutBufferId
 *                Index of the ReadoutBuffer, derived from the ClientId.
 *
 * \return        The EventId of the readout buffer
 *
 * \pre           Dem_DTCReadoutBuffer_GetState() != DEM_DTCREADOUTBUFFER_UNUSED
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE for different ReadoutBuffer Ids
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_EventIdType, DEM_CODE)
Dem_DTCReadoutBuffer_GetEventId(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId
  );
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 * Dem_DTCReadoutBuffer_GetMemoryId
 *****************************************************************************/
/*!
 * \brief         Get the memory location
 *
 * \details       Get the memory locations of the given record
 *
 * \param[in]     ReadoutBufferId
 *                Index of the ReadoutBuffer, derived from the ClientId.
 *
 * \return        Size of a memory entry Data record in bytes.
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_DTCReadoutBuffer_GetMemoryId(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId
  );
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 * Dem_DTCReadoutBuffer_SelectExtendedDataRecord
 *****************************************************************************/
/*!
 * \brief         Selects a data record
 *
 * \details       Initializes the iterator for the selected event.
 *
 * \param[in]     ReadoutBufferId
 *                Index of the ReadoutBuffer
 * \param[in]     ExtendedDataNumber
 *                The extended data number
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE for different ReadoutBuffer Ids
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_DTCReadoutBuffer_SelectExtendedDataRecord(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId,
  CONST(uint8, AUTOMATIC) ExtendedDataNumber
  );                                                                                                                             /* PRQA S 0779 */ /* MD_MSR_5.1_779 */
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 * Dem_DTCReadoutBuffer_SelectSnapshotRecord
 *****************************************************************************/
/*!
 * \brief         Selects a data record
 *
 * \details       Initializes the iterator for the selected event.
 *
 * \param[in]     ReadoutBufferId
 *                Index of the ReadoutBuffer
 * \param[in]     RecordNumber
 *                The selected record number
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE for different ReadoutBuffer Ids
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_DTCReadoutBuffer_SelectSnapshotRecord(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId,
  CONST(uint8, AUTOMATIC) RecordNumber
  );                                                                                                                             /* PRQA S 0779 */ /* MD_MSR_5.1_779 */
#endif

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
 * \defgroup Dem_DTCReadoutBuffer_Private Private Methods
 * \{
 */

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 * Dem_DTCReadoutBuffer_ExtendedDataRecord_Init
 *****************************************************************************/
/*!
 * \brief         Initialize the extended data iterator
 *
 * \details       Clear all members.
 *
 * \param[in]     ReadoutBufferId
 *                Index of the ReadoutBuffer
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE for different ReadoutBuffer Ids
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_DTCReadoutBuffer_ExtendedDataRecord_Init(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId
  );                                                                                                                             /* PRQA S 0779 */ /* MD_MSR_5.1_779 */
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 * Dem_DTCReadoutBuffer_SnapshotRecord_Init
 *****************************************************************************/
/*!
 * \brief         Initialize the snapshot record iterator
 *
 * \details       Clear all members.
 *
 * \param[in]     ReadoutBufferId
 *                Index of the ReadoutBuffer
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE for different ReadoutBuffer Ids
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_DTCReadoutBuffer_SnapshotRecord_Init(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId
  );
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 * Dem_DTCReadoutBuffer_GetExtendedIterator
 *****************************************************************************/
/*!
 * \brief         Returns the extended iterator
 *
 * \details       Returns the extended iterator of the given readout buffer
 *
 * \param[in]     ReadoutBufferId
 *                Index of the ReadoutBuffer
 *
 * \return        The extended iterator
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_DTCReadoutBuffer_ExtendedDataIteratorType, DEM_CODE)
Dem_DTCReadoutBuffer_GetExtendedIterator(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId
  );                                                                                                                             /* PRQA S 0779 */ /* MD_MSR_5.1_779 */
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 *  Dem_DTCReadoutBuffer_SetExtendedIterator
 *****************************************************************************/
/*!
 * \brief         Sets the extended iterator
 *
 * \details       Sets the extended iterator of the given readout buffer
 *
 * \param[in,out] ReadoutBufferId
 *                Index of the ReadoutBuffer
 * \param[in]     ExtendedDataIterator
 *                The new value of the extended data iterator
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_DTCReadoutBuffer_SetExtendedIterator(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC)  ReadoutBufferId,
  CONST(Dem_DTCReadoutBuffer_ExtendedDataIteratorType, AUTOMATIC)  ExtendedDataIterator
  );                                                                                                                             /* PRQA S 0779 */ /* MD_MSR_5.1_779 */
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 * Dem_DTCReadoutBuffer_GetSnapshotIterator
 *****************************************************************************/
/*!
 * \brief         Returns the snapshot iterator
 *
 * \details       Returns the snapshot iterator of the given readout buffer
 *
 * \param[in]     ReadoutBufferId
 *                Index of the ReadoutBuffer
 *
 * \return        The snapshot iterator
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_DTCReadoutBuffer_SnapshotDataIteratorType, DEM_CODE)
Dem_DTCReadoutBuffer_GetSnapshotIterator(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId
  );                                                                                                                             /* PRQA S 0779 */ /* MD_MSR_5.1_779 */
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 *  Dem_DTCReadoutBuffer_SetSnapshotIterator
 *****************************************************************************/
/*!
 * \brief         Sets the snapshot iterator
 *
 * \details       Sets the snapshot iterator of the given readout buffer
 *
 * \param[in,out] ReadoutBufferId
 *                Index of the ReadoutBuffer
 *
 * \param[in]     SnapshotIterator
 *                The new value of the snapshot data iterator
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_DTCReadoutBuffer_SetSnapshotIterator(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC)  ReadoutBufferId,
  CONST(Dem_DTCReadoutBuffer_SnapshotDataIteratorType, AUTOMATIC)  SnapshotIterator
  );                                                                                                                             /* PRQA S 0779 */ /* MD_MSR_5.1_779 */
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 * Dem_DTCReadoutBuffer_SetState
 *****************************************************************************/
/*!
 * \brief         Set internal state of readout buffer.
 *
 * \details       Set internal state of readout buffer.
 *
 * \param[in]     ReadoutBufferId
 *                Index of the ReadoutBuffer, derived from the ClientId.
 * \param[in]     NewState
 *                New value for the buffer state.
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_DTCReadoutBuffer_SetState(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId,
  CONST(Dem_DTCReadoutBuffer_StatusType, AUTOMATIC) NewState
  );
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 * Dem_DTCReadoutBuffer_GetState
 *****************************************************************************/
/*!
 * \brief         Get internal state of readout buffer.
 *
 * \details       Get internal state of readout buffer.
 *
 * \param[in]     ReadoutBufferId
 *                Index of the ReadoutBuffer, derived from the ClientId.
 *
 * \return        DEM_DTCREADOUTBUFFER_UNUSED
 *                The readout buffer is unused and contains no (i.e. invalid)
 *                data.
 * \return        DEM_DTCREADOUTBUFFER_QUEUED
 *                The readout buffer contains EventId, MemoryId values, and is
 *                waiting for the MainFunction to copy the Data.
 * \return        DEM_DTCREADOUTBUFFER_IN_USE
 *                The readout buffer contains configuration and event's data.
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE for different ReadoutBuffer Ids
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_DTCReadoutBuffer_StatusType, DEM_CODE)
Dem_DTCReadoutBuffer_GetState(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId
  );
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 * Dem_DTCReadoutBuffer_SetMemoryId
 *****************************************************************************/
/*!
 * \brief         Set memory id of readout buffer.
 *
 * \details       Set memory id of readout buffer.
 *
 * \param[in]     ReadoutBufferId
 *                Index of the ReadoutBuffer, derived from the ClientId.
 * \param[in]     NewMemoryId
 *                New value for the MemoryId.
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_DTCReadoutBuffer_SetMemoryId(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC)  ReadoutBufferId,
  CONST(uint8, AUTOMATIC)  NewMemoryId
  );
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 * Dem_DTCReadoutBuffer_SetEventId
 *****************************************************************************/
/*!
 * \brief         Set event id of readout buffer.
 *
 * \details       Set event id of readout buffer.
 *
 * \param[in]     ReadoutBufferId
 *                Index of the ReadoutBuffer, derived from the ClientId.
 * \param[in]     NewEventId
 *                New value for the EventId.
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_DTCReadoutBuffer_SetEventId(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC)  ReadoutBufferId,
  CONST(Dem_EventIdType, AUTOMATIC)  NewEventId
  );
#endif

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* DEM_DTCREADOUTBUFFER_INTERFACE_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_DTCReadoutBuffer_Interface.h
 *********************************************************************************************************************/
