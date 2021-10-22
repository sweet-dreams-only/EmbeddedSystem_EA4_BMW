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
 *  \defgroup   Dem_FreezeFrameIterator FreezeFrame Iterator
 *  \{
 *  \file       Dem_FreezeFrameIterator_Interface.h
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

#if !defined (DEM_FREEZEFRAMEITERATOR_INTERFACE_H)
#define DEM_FREEZEFRAMEITERATOR_INTERFACE_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                        /* Dem module header */
/* ------------------------------------------------------------------------- */
# include "Dem_FreezeFrameIterator_Types.h"
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
 *  SUBCOMPONENT PRIVATE FUNCTION DECLARATIONS
 *********************************************************************************************************************/
# define DEM_START_SEC_CODE
# include "MemMap.h"                                                                                                             /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \defgroup Dem_FreezeFrameIterator_Private Private Methods
 * \{
 */

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 * Dem_FreezeFrameIterator_SetDTCFormat
 *****************************************************************************/
/*!
 * \brief         Set the DTCFormat in the FreezeFrameIterator.
 *
 * \details       Set the DTCFormat in the FreezeFrameIterator.
 *
 * \param[in]     FreezeFrameIteratorId
 *                Index in FreezeFrameIteratorTable, derived from the ClientId.
 *
 * \param[in]     NewDTCFormat
 *                New value for the DTCFormat:
 *                DEM_FREEZEFRAMEITERATOR_DTCFORMAT_INIT:  unused iterator
 *                DEM_FREEZEFRAMEITERATOR_DTCFORMAT_UDS:   filter UDS DTCs
 *                DEM_FREEZEFRAMEITERATOR_DTCFORMAT_OBD:   filter OBD DTCs
 *                DEM_FREEZEFRAMEITERATOR_DTCFORMAT_J1939: filter J1939 DTCs
 * 
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE for different FreezeFrameIterator Ids
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_FreezeFrameIterator_SetDTCFormat(
CONST(Dem_FreezeFrameIterator_HandleType, AUTOMATIC)    FreezeFrameIteratorId,
CONST(Dem_FreezeFrameIterator_DTCFormatType, AUTOMATIC) NewDTCFormat
);
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 * Dem_FreezeFrameIterator_GetDTCFormat
 *****************************************************************************/
/*!
 * \brief         Get the DTCFormat of the FreezeFrameIterator.
 *
 * \details       Get the DTCFormat of the FreezeFrameIterator.
 *
 * \param[in]     FreezeFrameIteratorId
 *                Index in FreezeFrameIteratorTable, derived from the ClientId.
 *
 * \return        DEM_FREEZEFRAMEITERATOR_DTCFORMAT_INIT
 *                Initialization value, filter/iterator is unused.
 *
 *                DEM_FREEZEFRAMEITERATOR_DTCFORMAT_UDS
 *                The filter selects the 3-byte UDS DTC format
 *                (refer to configuration parameter DemUdsDTC).
 *
 *                DEM_FREEZEFRAMEITERATOR_DTCFORMAT_OBD
 *                The filter selects the 2-byte OBD DTC format
 *                (refer to configuration parameter DemObdDTC).
 *
 *                DEM_FREEZEFRAMEITERATOR_DTCFORMAT_J1939
 *                Selects the merged SPN + FMI to 3-byte J1939 DTC format
 *                (refer to configuration parameter DemJ1939DTC).
 *
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE for different FreezeFrameIterator Ids
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_FreezeFrameIterator_DTCFormatType, DEM_CODE)
Dem_FreezeFrameIterator_GetDTCFormat(
  CONST(Dem_FreezeFrameIterator_HandleType, AUTOMATIC)  FreezeFrameIteratorId
  );
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 * Dem_FreezeFrameIterator_SetMemoryIndex
 *****************************************************************************/
/*!
 * \brief         Set the MemoryIndex in the FreezeFrameIterator.
 *
 * \details       Set the MemoryIndex in the FreezeFrameIterator.
 *
 * \param[in]     FreezeFrameIteratorId
 *                Index in FreezeFrameIteratorTable, derived from the ClientId.
 *
 * \param[in]     NewMemoryIndex
 *                New value for the MemoryIndex.
 *
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE for different FreezeFrameIterator Ids
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_FreezeFrameIterator_SetMemoryIndex(
  CONST(Dem_FreezeFrameIterator_HandleType, AUTOMATIC)  FreezeFrameIteratorId,
  CONST(uint8, AUTOMATIC)  NewMemoryIndex
  );
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 * Dem_FreezeFrameIterator_GetMemoryIndex
 *****************************************************************************/
/*!
 * \brief         Get the MemoryIndex of the FreezeFrameIterator.
 *
 * \details       Get the MemoryIndex of the FreezeFrameIterator.
 *
 * \param[in]     FreezeFrameIteratorId
 *                Index in FreezeFrameIteratorTable, derived from the ClientId.
 *
 * \return        The memory entry iterator position.
 *
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE for different FreezeFrameIterator Ids
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_FreezeFrameIterator_GetMemoryIndex(
  CONST(Dem_FreezeFrameIterator_HandleType, AUTOMATIC)  FreezeFrameIteratorId
  );
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 * Dem_FreezeFrameIterator_SetSnapshotEntryIterator
 *****************************************************************************/
/*!
 * \brief         Set the snapshot entry iterator in the FreezeFrameIterator.
 *
 * \details       Set the snapshot entry iterator in the FreezeFrameIterator.
 *
 * \param[in]     FreezeFrameIteratorId
 *                Index in FreezeFrameIteratorTable, derived from the ClientId.
 *
 * \param[in]     SnapshotEntryIter
 *                New value for the snapshot entry iterator.
 *
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE for different FreezeFrameIterator Ids
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_FreezeFrameIterator_SetSnapshotEntryIterator(
  CONST(Dem_FreezeFrameIterator_HandleType, AUTOMATIC)  FreezeFrameIteratorId,
  CONST(Dem_SnapshotEntry_IterType, AUTOMATIC)  SnapshotEntryIter
  );
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 * Dem_FreezeFrameIterator_GetSnapshotEntryIterator
 *****************************************************************************/
/*!
 * \brief         Get the snapshot entry iterator of the FreezeFrameIterator.
 *
 * \details       Get the snapshot entry iterator of the FreezeFrameIterator.
 *
 * \param[in]     FreezeFrameIteratorId
 *                Index in FreezeFrameIteratorTable, derived from the ClientId.
 *
 * \return        The snapshot entry iterator.
 *
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE for different FreezeFrameIterator Ids
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_SnapshotEntry_IterType, DEM_CODE)
Dem_FreezeFrameIterator_GetSnapshotEntryIterator(
  CONST(Dem_FreezeFrameIterator_HandleType, AUTOMATIC)  FreezeFrameIteratorId
  );
#endif

# if (DEM_FEATURE_NEED_TIME_SERIES == STD_ON) && (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 * Dem_FreezeFrameIterator_SetTimeSeriesRecordNumber
 *****************************************************************************/
/*!
 * \brief         Set the TimeSeriesRecordNumber in the FreezeFrameIterator.
 *
 * \details       Set the TimeSeriesRecordNumber in the FreezeFrameIterator.
 *
 * \param[in]     FreezeFrameIteratorId
 *                Index in FreezeFrameIteratorTable, derived from the ClientId.
 *
 * \param[in]     NewTimeSeriesRecordNumber
 *                New value for the TimeSeriesRecordNumber.
 *
 * \config        (DEM_CFG_SUPPORT_DCM == STD_ON)
 *                && (DEM_FEATURE_NEED_TIME_SERIES == STD_ON)
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE for different FreezeFrameIterator Ids
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_FreezeFrameIterator_SetTimeSeriesRecordNumber(
  CONST(Dem_FreezeFrameIterator_HandleType, AUTOMATIC)  FreezeFrameIteratorId,
  CONST(uint8, AUTOMATIC)  NewTimeSeriesRecordNumber
  );
# endif

# if (DEM_FEATURE_NEED_TIME_SERIES == STD_ON) && (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 * Dem_FreezeFrameIterator_GetTimeSeriesRecordNumber
 *****************************************************************************/
/*!
 * \brief         Get the TimeSeriesRecordNumber of the FreezeFrameIterator.
 *
 * \details       Get the TimeSeriesRecordNumber of the FreezeFrameIterator.
 *
 * \param[in]     FreezeFrameIteratorId
 *                Index in FreezeFrameIteratorTable, derived from the ClientId.
 *
 * \return        The time series iterator position.
 *
 * \config        (DEM_CFG_SUPPORT_DCM == STD_ON)
 *                && (DEM_FEATURE_NEED_TIME_SERIES == STD_ON)
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE for different FreezeFrameIterator Ids
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_FreezeFrameIterator_GetTimeSeriesRecordNumber(
  CONST(Dem_FreezeFrameIterator_HandleType, AUTOMATIC)  FreezeFrameIteratorId
  );
# endif

# if (DEM_CFG_SUPPORT_SRECS == STD_ON) && (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_FreezeFrameIterator_InitIterator
 *****************************************************************************/
/*!
 * \brief         Set start and end value of the Iterator.
 *
 * \details       Set start and end value of the Iterator
 *                in the FreezeFrameIterator.
 *
 * \param[in]     FreezeFrameIteratorId
 *                Index in FreezeFrameIteratorTable, derived from the ClientId.
 * \param[in]     NewStartIndex
 *                Start index for the iterator.
 *                Constrant: [StartIndex <= EndIndex]
 * \param[in]     NewEndIndex
 *                End index for the iterator. The end index addresses the
 *                last+1 element, so if (start==end) the iterator has
 *                0 iterations.
 *
 * \config        (DEM_CFG_SUPPORT_DCM == STD_ON)
 *                && (DEM_CFG_SUPPORT_SRECS == STD_ON)
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE for different FreezeFrameIterator Ids
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_FreezeFrameIterator_InitIterator(
  CONST(Dem_FreezeFrameIterator_HandleType, AUTOMATIC)  FreezeFrameIteratorId,
  CONST(uint16_least, AUTOMATIC)  NewStartIndex,
  CONST(uint16_least, AUTOMATIC)  NewEndIndex
  );
#endif

# if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 * Dem_FreezeFrameIterator_GetIteratorPtr
 *****************************************************************************/
/*!
 * \brief         Get the Iterator of the FreezeFrameIterator.
 *
 * \details       Get the Iterator of the FreezeFrameIterator.
 *
 * \param[in]     FreezeFrameIteratorId
 *                Index in FreezeFrameIteratorTable, derived from the ClientId.
 *
 * \return        The address of the snapshot record iterator.
 *                Safety check: the address always points to a buffer.
 *
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE for different FreezeFrameIterator Ids
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_FreezeFrameIterator_IterPtrType, DEM_CODE)
Dem_FreezeFrameIterator_GetIteratorPtr(
  CONST(Dem_FreezeFrameIterator_HandleType, AUTOMATIC)  FreezeFrameIteratorId
  );
#endif

# if (DEM_CFG_SUPPORT_SRECS == STD_ON) && (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 * Dem_FreezeFrameIterator_FilterSRec
 *****************************************************************************/
/*!
 * \brief         Filters the snapshot records of events stored in primary
 *                memory.
 * \details       Filters the snapshot records of events stored in primary
 *                memory.
 *
 * \param[in]     FreezeFrameIteratorId
 *                The FreezeFrameIteratorId that defines the filter.
 * \param[out]    DTC
 *                Pointer to receive the UDS DTC number
 * \param[out]    RecordNumber
 *                Pointer to receive the snapshot record number
 *
 * \return        TRUE
 *                Next record was found
 *                FALSE
 *                No more record found
 *
 * \pre           The record filter has been initialized by
 *                Dem_SetFreezeFrameRecordFilter
 * \config        (DEM_CFG_SUPPORT_DCM == STD_ON)
 *                && (DEM_CFG_SUPPORT_SRECS == STD_ON)
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_FreezeFrameIterator_FilterSRec(
  CONST(Dem_FreezeFrameIterator_HandleType, AUTOMATIC)  FreezeFrameIteratorId,
  CONSTP2VAR(uint32, AUTOMATIC, DEM_DCM_DATA)  DTC,
  CONSTP2VAR(uint8, AUTOMATIC, DEM_DCM_DATA)  RecordNumber
  );                                                                                                                             /* PRQA S 0779 */ /* MD_MSR_5.1_779 */
# endif

# if (DEM_CFG_SUPPORT_SRECS == STD_ON) && (DEM_FEATURE_NEED_TIME_SERIES == STD_ON) && (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 * Dem_FreezeFrameIterator_FilterTimeSeriesSRec
 *****************************************************************************/
/*!
 * \brief         Filters the time series snapshot records
 *
 * \details       Filters the time series snapshot records
 *
 * \param[in]     FreezeFrameIteratorId
 *                The FreezeFrameIteratorId that defines the filter.
 * \param[out]    DTC
 *                Pointer to receive the UDS DTC number
 * \param[out]    RecordNumber
 *                Pointer to receive the snapshot record number
 *
 * \return        TRUE
 *                Next record was found
 *                FALSE
 *                No more record found
 *
 * \pre           The record filter has been initialized by
 *                Dem_SetFreezeFrameRecordFilter
 * \config        (DEM_CFG_SUPPORT_DCM == STD_ON)
 *                && (DEM_CFG_SUPPORT_SRECS == STD_ON)
 *                && (DEM_FEATURE_NEED_TIME_SERIES == STD_ON)
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_FreezeFrameIterator_FilterTimeSeriesSRec(
  CONST(Dem_FreezeFrameIterator_HandleType, AUTOMATIC)  FreezeFrameIteratorId,
  CONSTP2VAR(uint32, AUTOMATIC, DEM_DCM_DATA)  DTC,
  CONSTP2VAR(uint8, AUTOMATIC, DEM_DCM_DATA)  RecordNumber
  );                                                                                                                             /* PRQA S 0779 */ /* MD_MSR_5.1_779 */
# endif

# if (DEM_CFG_SUPPORT_SRECS == STD_ON) && (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 * Dem_FreezeFrameIterator_GetNumberOfSRec
 *****************************************************************************/
/*!
 * \brief         Gets the number of stored snapshot records
 *
 * \details       Gets the number of stored snapshot records
 *
 * \return        Number of stored records
 *
 * \pre           -
 * \config        (DEM_CFG_SUPPORT_DCM == STD_ON)
 *                && (DEM_CFG_SUPPORT_SRECS == STD_ON)
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint16, DEM_CODE)
Dem_FreezeFrameIterator_GetNumberOfSRec(
  void
  );                                                                                                                             /* PRQA S 0779 */ /* MD_MSR_5.1_779 */
# endif

# if (DEM_CFG_SUPPORT_SRECS == STD_ON) && (DEM_FEATURE_NEED_TIME_SERIES == STD_ON) && (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 * Dem_FreezeFrameIterator_GetNumberOfTimeSeriesSRec
 *****************************************************************************/
/*!
 * \brief         Gets the number of stored time series snapshot records
 *
 * \details       Gets the number of stored time series snapshot records
 *
 * \return        number of stored records
 *
 * \pre           -
 * \config        (DEM_CFG_SUPPORT_DCM == STD_ON)
 *                && (DEM_CFG_SUPPORT_SRECS == STD_ON)
 *                && (DEM_FEATURE_NEED_TIME_SERIES == STD_ON)
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint16, DEM_CODE)
Dem_FreezeFrameIterator_GetNumberOfTimeSeriesSRec(
  void
  );                                                                                                                             /* PRQA S 0779 */ /* MD_MSR_5.1_779 */
# endif

/*!
 * \}
 */
# define DEM_STOP_SEC_CODE
# include "MemMap.h"                                                                                                             /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* ********************************************************************************************************************
 *  SUBCOMPONENT API FUNCTION DECLARATIONS
 *********************************************************************************************************************/
# define DEM_START_SEC_CODE
# include "MemMap.h"                                                                                                             /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \defgroup Dem_FreezeFrameIterator_Public Public Methods
 * \{
 */

# if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 * Dem_FreezeFrameIterator_InitDefault
 *****************************************************************************/
/*!
 * \brief         Initialize a FreezeFrameIterator.
 *
 * \details       Initializes a FreezeFrameIterator, the resulting filter
 *                cannot be used by GetNextFilteredRecord without prior
 *                calling Dem_SetFreezeFrameRecordFilter.
 *
 * \param[in]     FreezeFrameIteratorId
 *                The FreezeFrameIteratorId to initialize.
 *
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE, for different FreezeFrameIteratorId
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_FreezeFrameIterator_InitDefault(
  CONST(Dem_FreezeFrameIterator_HandleType, AUTOMATIC)  FreezeFrameIteratorId
  );
#endif

# if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 * Dem_FreezeFrameIterator_TestFilterSet
 *****************************************************************************/
/*!
 * \brief         Test FreezeFrameIterator for containing valid filter setting.
 *
 * \details       Test that freeze frame filter has been set.
 *
 * \param[in]     FreezeFrameIteratorId
 *                The FreezeFrameIteratorId to test.
 *
 * \return        TRUE
 *                The freeze frame filter can be used.
 * \return        FALSE
 *                The freeze frame filter is not initialized.
 *                
 *
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE, for different FreezeFrameIteratorId
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_FreezeFrameIterator_TestFilterSet(
  CONST(Dem_FreezeFrameIterator_HandleType, AUTOMATIC)  FreezeFrameIteratorId
  );
#endif

# if (DEM_CFG_SUPPORT_SRECS == STD_ON) && (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 * Dem_FreezeFrameIterator_StartIterator
 *****************************************************************************/
/*!
 * \brief         Initialize (start) FreezeFrameIterator with given criteria.
 *
 * \details       Initialize (start) FreezeFrameIterator with given criteria.
 *
 * \param[in]     FreezeFrameIteratorId
 *                The FreezeFrameIteratorId to initialize.
 * \param[in]     FilterDTCFormat
 *                Defines the output-format of the requested DTC values.
 * \param[in]     MemoryIndex
 *                First memory block index belonging to the memory.
 *
 * \config        (DEM_CFG_SUPPORT_DCM == STD_ON)
 *                && (DEM_CFG_SUPPORT_SRECS == STD_ON)
 * \pre           -
 *
 * \context       TASK|ISR2, from the master partition only
 * \synchronous   FALSE
 * \reentrant     TRUE for different ClientIDs
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_FreezeFrameIterator_StartIterator(
  CONST(Dem_FreezeFrameIterator_HandleType, AUTOMATIC)  FreezeFrameIteratorId,
  CONST(Dem_FreezeFrameIterator_DTCFormatType, AUTOMATIC)  FilterDTCFormat,
  CONST(uint8, AUTOMATIC)  MemoryIndex
  );
# endif

# if (DEM_CFG_SUPPORT_SRECS == STD_ON) && (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 * Dem_FreezeFrameIterator_GetNext
 *****************************************************************************/
/*!
 * \brief         Initialize (start) FreezeFrameIterator with given criteria.
 *
 * \details       Initialize (start) FreezeFrameIterator with given criteria.
 *
 * \param[in]     FreezeFrameIteratorId
 *                The FreezeFrameIteratorId to iterate.
 * \param[out]    DTC
 *                With return value TRUE: the next filtered DTC number.
 * \param[out]    RecordNumber
 *                With return value TRUE: the next filtered RecordNumber
 *                number of the DTC.
 *
 * \return        TRUE
 *                Returned next filtered element.
 * \return        FALSE
 *                No further element (matching the filter criteria) found,
 *                iteration is complete.
 *
 * \config        (DEM_CFG_SUPPORT_DCM == STD_ON)
 *                && (DEM_CFG_SUPPORT_SRECS == STD_ON)
 * \pre           -
 *
 * \context       TASK|ISR2, from the master partition only
 * \synchronous   FALSE
 * \reentrant     TRUE for different ClientIDs
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_FreezeFrameIterator_GetNext(
  CONST(Dem_FreezeFrameIterator_HandleType, AUTOMATIC)  FreezeFrameIteratorId,
  P2VAR(uint32, AUTOMATIC, DEM_DCM_DATA)  DTC,                                                                                   /* PRQA S 3206, 3673 */ /* MD_DEM_3206, MD_DEM_16.7 */
  P2VAR(uint8, AUTOMATIC, DEM_DCM_DATA)  RecordNumber                                                                            /* PRQA S 3206, 3673 */ /* MD_DEM_3206, MD_DEM_16.7 */
  );
# endif

# if (DEM_CFG_SUPPORT_SRECS == STD_ON) && (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 * Dem_FreezeFrameIterator_GetNumberOfFreezeFrameRecords
 *****************************************************************************/
/*!
 * \brief         Gets the total number of stored FreezeFrame records
 *
 * \details       Gets the number of stored FreezeFrame records
 *
 * \return        Number of stored records
 *
 * \pre           -
 * \config        (DEM_CFG_SUPPORT_DCM == STD_ON)
 *                && (DEM_CFG_SUPPORT_SRECS == STD_ON)
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint16, DEM_CODE)
Dem_FreezeFrameIterator_GetNumberOfFreezeFrameRecords(
  void
  );                                                                                                                             /* PRQA S 0779 */ /* MD_MSR_5.1_779 */
# endif

/*!
 * \}
 */
# define DEM_STOP_SEC_CODE
# include "MemMap.h"                                                                                                             /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* DEM_FREEZEFRAMEITERATOR_INTERFACE_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_FreezeFrameIterator_Interface.h
 *********************************************************************************************************************/
