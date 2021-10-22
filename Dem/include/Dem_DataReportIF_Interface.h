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
 *  \defgroup   Dem_DataReportIF DataReportIF
 *  \{
 *  \file       Dem_DataReportIF_Interface.h
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

#if !defined (DEM_DATAREPORTIF_INTERFACE_H)
#define DEM_DATAREPORTIF_INTERFACE_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                  /* Own subcomponent header */
/* ------------------------------------------------------------------------- */
#include "Dem_DataReportIF_Types.h"

#include "Dem_Mem_Types.h"

/* ********************************************************************************************************************
 *  SUBCOMPONENT OBJECT FUNCTION DECLARATIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \defgroup Dem_DataReportIF_Properties Properties
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
 * \defgroup Dem_DataReportIF_Private Private Methods
 * \{
 */
#if ( (DEM_CFG_SUPPORT_SRECS == STD_ON) \
   || (DEM_CFG_SUPPORT_OBDII == STD_ON) \
   || (DEM_CFG_SUPPORT_WWHOBD == STD_ON) \
   || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON) )
/* ****************************************************************************
 * Dem_DataReportIF_SkipDid
 *****************************************************************************/
/*!
 * \brief         Skip data elements
 *
 * \details       Moves the read (source) pointer in the copy context to skip
 *                the stored data for the given DID. This function has no
 *                effect if the DID does not have persisted data, e.g. if the
 *                DID is composed of statistical values.
 *
 * \param[in]     CopyDidInfoPtr
 *                CopyDid context
 * \param[in]     DidIndex
 *                Unique handle of the DID
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_SRECS == STD_ON ||
 *                DEM_CFG_SUPPORT_OBDII == STD_ON ||
 *                DEM_CFG_SUPPORT_WWHOBD == STD_ON ||
 *                DEM_FEATURE_NEED_TIME_SERIES == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_DataReportIF_SkipDid(
  CONST(Dem_DataReportIF_CopyDidInfoPtrType, AUTOMATIC)  CopyDidInfoPtr,
  CONST(Dem_Cfg_DidIndexType, AUTOMATIC)  DidIndex
  );
#endif

#if (DEM_FEATURE_NEED_TIME_SERIES == STD_ON)
/* ****************************************************************************
* Dem_DataReportIF_CopyReplacementBytes
*****************************************************************************/
/*!
* \brief         Pads the destination buffer with 0xff for unavailable data.
*
* \details       Pads the destination buffer with 0xff for unavailable data.
*
* \param[in]     CopyDidInfoPtr
*                CopyDid context
* \param[in]     DataIndex
*                Index of requested data element
*
* \return        TRUE
*                Always.
*
* \pre           -
* \config        DEM_FEATURE_NEED_TIME_SERIES == STD_ON
*
* \context       TASK|ISR2
* \synchronous   TRUE
* \reentrant     TRUE
*****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_DataReportIF_CopyReplacementBytes(
  CONST(Dem_DataReportIF_CopyDidInfoPtrType, AUTOMATIC)  CopyDidInfoPtr,
  CONST(Dem_Cfg_DataIndexType, AUTOMATIC)  DataIndex
  );
#endif

#if (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON)
/* ****************************************************************************
 * Dem_DataReportIF_CopyStoredUserData
 *****************************************************************************/
/*!
 * \brief         Retrieves the user data stored in the event memory entry or
 *                time series entry
 *
 * \details       Retrieves the user data stored in the event memory entry or
 *                time series entry
 *
 * \param[in]     CopyDidInfoPtr
 *                CopyDid context
 * \param[in]     DataIndex
 *                Index of requested data element
 *
 * \return        TRUE
 *                Always.
 *
 * \pre           -
 * \config        DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_DataReportIF_CopyStoredUserData(
  CONST(Dem_DataReportIF_CopyDidInfoPtrType, AUTOMATIC)  CopyDidInfoPtr,
  CONST(Dem_Cfg_DataIndexType, AUTOMATIC)  DataIndex
  );
#endif

#if ( (DEM_CFG_SUPPORT_ERECS == STD_ON) \
   || (DEM_CFG_SUPPORT_SRECS == STD_ON) \
   || (DEM_CFG_SUPPORT_OBDII == STD_ON) \
   || (DEM_CFG_SUPPORT_WWHOBD == STD_ON) \
   || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON))
/* ****************************************************************************
 * Dem_DataReportIF_CopyStoredDataElement
 *****************************************************************************/
/*!
 * \brief         Copies stored data element into a buffer.
 *
 * \details       Copies a stored data element or an internal data element
 *                into the destination buffer.
 *
 * \param[in,out] CopyDidInfoPtr
 *                CopyDid context
 * \param[in]     DataIndex
 *                Unique handle of the data element
 *
 * \return        TRUE
 *                Data was copied
 * \return        FALSE
 *                No data was copied
 *
 * \pre           A memory entry has to be locked for Dcm readout
 * \config        DEM_CFG_SUPPORT_ERECS == STD_ON  ||
 *                DEM_CFG_SUPPORT_SRECS == STD_ON  ||
 *                DEM_CFG_SUPPORT_OBDII == STD_ON  ||
 *                DEM_CFG_SUPPORT_WWHOBD == STD_ON ||
 *                DEM_FEATURE_NEED_TIME_SERIES == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_DataReportIF_CopyStoredDataElement(
  CONST(Dem_DataReportIF_CopyDidInfoPtrType, AUTOMATIC)  CopyDidInfoPtr,
  CONST(Dem_Cfg_DataIndexType, AUTOMATIC)  DataIndex
  );
#endif

#if ( (DEM_CFG_SUPPORT_ERECS == STD_ON) \
   || (DEM_CFG_SUPPORT_SRECS == STD_ON) \
   || (DEM_CFG_SUPPORT_OBDII == STD_ON) \
   || (DEM_CFG_SUPPORT_WWHOBD == STD_ON) \
   || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON) )
/* ****************************************************************************
 * Dem_DataReportIF_CopyDid
 *****************************************************************************/
/*!
 * \brief         Copies DID data into a buffer.
 *
 * \details       Copies all stored data elements attached to a data identifier
 *                object into the destination buffer, filling in internal data
 *                where needed.
 *                Note that a data identifier in this context is not only a
 *                UDS DID, but can also be an extended data record or PID.
 *
 * \param[in,out] CopyDidInfoPtr
 *                CopyDid context
 * \param[in]     DidIndex
 *                Unique handle of the DID
 *
 * \return        TRUE
 *                All data was copied (can be 0 bytes dependent on config)
 * \return        FALSE
 *                Not all data was copied
 *
 * \pre           A memory entry has to be locked for Dcm readout
 * \config        DEM_CFG_SUPPORT_ERECS == STD_ON  ||
 *                DEM_CFG_SUPPORT_SRECS == STD_ON  ||
 *                DEM_CFG_SUPPORT_OBDII == STD_ON  ||
 *                DEM_CFG_SUPPORT_WWHOBD == STD_ON ||
 *                DEM_FEATURE_NEED_TIME_SERIES == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL FUNC(boolean, DEM_CODE)
Dem_DataReportIF_CopyDid(
  CONST(Dem_DataReportIF_CopyDidInfoPtrType, AUTOMATIC)  CopyDidInfoPtr,
  CONST(Dem_Cfg_DidIndexType, AUTOMATIC)  DidIndex
  );
#endif

#if (DEM_FEATURE_NEED_TIME_SERIES == STD_ON)
/* ****************************************************************************
 * Dem_DataReportIF_CopyDid_NoInternalData
 *****************************************************************************/
/*!
 * \brief         Copies DID data into a buffer.
 *
 * \details       Copies all stored data elements attached to a data identifier
 *                object into the destination buffer, padding internal data
 *                elements with 0xff.
 *
 * \param[in,out] CopyDidInfoPtr
 *                CopyDid context
 * \param[in]     DidIndex
 *                Unique handle of the DID
 *
 * \return        TRUE
 *                All data was copied (can be 0 bytes dependent on config)
 * \return        FALSE
 *                Not all data was copied
 *
 * \pre           A memory entry has to be locked for Dcm readout
 * \config        DEM_FEATURE_NEED_TIME_SERIES == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL FUNC(boolean, DEM_CODE)
Dem_DataReportIF_CopyDid_NoInternalData(
  CONST(Dem_DataReportIF_CopyDidInfoPtrType, AUTOMATIC)  CopyDidInfoPtr,
  CONST(Dem_Cfg_DidIndexType, AUTOMATIC)  DidIndex
  );
#endif


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
 * \defgroup Dem_DataReportIF_Public Public Methods
 * \{
 */
#if (DEM_CFG_SUPPORT_OBDII == STD_ON)                                                                                            /* COV_MSR_UNSUPPORTED XF */
/* ****************************************************************************
 * Dem_DataReportIF_CopyPidFromObdIIFreezeFrame
 *****************************************************************************/
/*!
 * \brief         Copy the requested PID data into the given buffer
 *
 * \details       The stored OBD freezeframe data of an event is written to
 *                DestBuffer in no particular format (raw hex).
 *
 * \param[in]     DataId
 *                Return only the data of this PID.
 * \param[in]     SourceBuffer
 *                Pointer to the source buffer
 * \param[out]    DestBuffer
 *                Pointer to the destination buffer.
 * \param[in,out] BufSize
 *                In:  Available space in the receiving buffer.
 *                Out: Number of written bytes.
 *
 * \return        E_OK
 *                The requested data was copied to the destination buffer.
 * \return        DEM_NO_SUCH_ELEMENT
 *                The PID is undefined for the event.
 * \return        DEM_BUFFER_TOO_SMALL
 *                The provided buffer size is too small.
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_OBDII == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_DataReportIF_CopyPidFromObdIIFreezeFrame(
  CONST(uint16, AUTOMATIC)  DataId,
  CONST(Dem_ConstSharedDataPtrType, AUTOMATIC)  SourceBuffer,
  CONSTP2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)  DestBuffer,
  CONSTP2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  BufSize                                                                          /* PRQA S 3206, 3673 */ /* MD_DEM_3206, MD_DEM_16.7 */
  );
#endif

#if (DEM_CFG_SUPPORT_WWHOBD == STD_ON)                                                                                           /* COV_MSR_UNSUPPORTED XF */
/* ****************************************************************************
 * Dem_DataReportIF_CopyDidFromWwhObdFreezeFrame
 *****************************************************************************/
/*!
 * \brief         Copy DID data into the given buffer
 *
 * \details       The stored WWH-OBD freezeframe data of an event is written to
 *                DestBuffer in no particular format (raw hex).
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 * \param[in]     DataId
 *                Return only the data of this DID.
 * \param[in]     MemoryIndex
 *                Memory index of the event.
 * \param[out]    DestBuffer
 *                Pointer to the destination buffer
 * \param[in,out] BufSize
 *                In:  Available space in the receiving buffer.
 *                Out: Number of written bytes.
 *
 * \return        E_OK
 *                The requested data was copied to the destination buffer.
 * \return        E_NOT_OK
 *                Operation could not be performed, e.g. when the data is
 *                concurrently updated.
 * \return        DEM_E_NODATAAVAILABLE
 *                The data is currently not stored for the requested event
 *                or
 *                the event is not WWH-OBD relevant
 *                or
 *                the requested data identifier is undefined for the event.
 * \return        DEM_BUFFER_TOO_SMALL
 *                The provided buffer size is too small.
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_WWHOBD == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_DataReportIF_CopyDidFromWwhObdFreezeFrame(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(uint16, AUTOMATIC)  DataId,
  CONST(Dem_Cfg_MemoryIndexType, AUTOMATIC) MemoryIndex,
  CONSTP2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)  DestBuffer,
  CONSTP2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  BufSize                                                                          /* PRQA S 3206, 3673 */ /* MD_DEM_3206, MD_DEM_16.7 */
  );
#endif


#if (DEM_FEATURE_NEED_TIME_SERIES == STD_ON)
/* ****************************************************************************
 * Dem_DataReportIF_CopyDidTimeSeriesSRec
*****************************************************************************/
/*!
 * \brief         Extracts a time series snapshot record, or a single DID from it.
 *
 * \details       The stored time series snapshot data of a time series entry
 *                is written to DestBuffer in no particular format (raw hex). 
 *
 * \param[in]     Entry
 *                Time Series Entry.
 * \param[in]     RecordNumber
 *                Snapshot record number.
 * \param[in]     DataId
 *                Return only the data of this DID.
 * \param[out]    DestBuffer
 *                Pointer to the destination buffer.
 * \param[in,out] BufSize
 *                In:  Available space in the receiving buffer.
 *                Out: Number of written bytes.
 *
 * \return        E_OK
 *                The requested data was copied to the destination buffer.
 * \return        DEM_NO_SUCH_ELEMENT
 *                The data indentifier within the requested record is
 *                undefined.
 * \return        DEM_BUFFER_TOO_SMALL
 *                The provided buffer size is too small.
 *
 * \pre           -
 * \config        DEM_FEATURE_NEED_TIME_SERIES == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_DataReportIF_CopyDidTimeSeriesSRec(
  CONST(Dem_Mem_ConstTimeSeriesEntryPtrType, AUTOMATIC)  Entry,
  CONST(uint8, AUTOMATIC)  RecordNumber,
  CONST(uint16, AUTOMATIC)  DataId,
  CONSTP2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)  DestBuffer,
  CONSTP2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  BufSize
  );
#endif


#if ( (DEM_CFG_SUPPORT_DCM == STD_ON) \
   && ((DEM_CFG_SUPPORT_SRECS == STD_ON) || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON)) )
/* ****************************************************************************
 * Dem_DataReportIF_SRecCopyData
 *****************************************************************************/
/*!
 * \brief         Copies the contents of a stored snapshot record
 *
 * \details       This function formats the snapshot data stored in the source
 *                according to the UDS specification and copies the result into
 *                the given destination buffer.
 *                The function will abort copying data if the destination is
 *                too small.
 *
 * \param[out]    DestBuffer
 *                Pointer to the destination buffer
 * \param[in]     SourceBuffer
 *                Pointer to the source buffer
 * \param[in]     BufferSize
 *                Size of the destination buffer
 * \param[in]     EventId
 *                Unique handle of the event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 * \param[in]     MemoryEntryId
 *                The memory entry handle
 *
 * \pre           A memory entry must have been copied to the intermediate
 *                buffer (see Dem_DcmDisableDTCRecordUpdate)
 * \pre           Existence of the record must be verified before calling this
 *                function, otherwise random data will be copied.
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON &&
 *                (DEM_CFG_SUPPORT_SRECS == STD_ON ||
 *                DEM_FEATURE_NEED_TIME_SERIES == STD_ON)
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_DataReportIF_SRecCopyData(
  CONST(Dem_SharedDataPtrType, AUTOMATIC)  DestBuffer,
  CONST(Dem_ConstSharedDataPtrType, AUTOMATIC)  SourceBuffer,
  CONST(uint16, AUTOMATIC)  BufferSize,
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(Dem_MemoryEntry_HandleType, AUTOMATIC)  MemoryEntryId
  );
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_WWHOBD == STD_ON)                                                        /* COV_MSR_UNSUPPORTED XF tf xf */
/* ****************************************************************************
 * Dem_DataReportIF_WWHOBDFreezeFrameCopyData
 *****************************************************************************/
/*!
 * \brief         Copies the contents of the WWH-OBD freeze frame
 *
 * \details       This function formats the WWH-OBD freeze frame data stored in
 *                the source according to the UDS snapshot record specification
 *                and copies the result into the given destination buffer.
 *                The function will abort copying data if the destination is
 *                too small.
 *
 * \param[out]    DestBuffer
 *                Pointer to the destination buffer
 * \param[in]     SourceBuffer
 *                Pointer to the source buffer
 * \param[in]     BufferSize
 *                Size of the destination buffer
 * \param[in]     EventId
 *                Unique handle of the event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 * \param[in]     MemoryEntryId
 *                The memory entry handle
 *
 * \pre           A memory entry must have been copied to the intermediate
 *                buffer (see Dem_DcmDisableDTCRecordUpdate)
 * \pre           Existence of the record must be verified before calling this
 *                function, otherwise random data will be copied.
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON &&
 *                DEM_CFG_SUPPORT_WWHOBD == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_DataReportIF_WWHOBDFreezeFrameCopyData(
  CONST(Dem_SharedDataPtrType, AUTOMATIC)  DestBuffer,
  CONST(Dem_ConstSharedDataPtrType, AUTOMATIC)  SourceBuffer,
  CONST(uint16, AUTOMATIC)  BufferSize,
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(Dem_MemoryEntry_HandleType, AUTOMATIC)  MemoryEntryId
  );
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_OBDII == STD_ON)                                                         /* COV_MSR_UNSUPPORTED XF tf xf */
/* ****************************************************************************
 * Dem_DataReportIF_ObdIIFreezeFrameCopyPidData
 *****************************************************************************/
/*!
 * \brief         Copy the contents of a PID from the FreezeFrame
 *
 * \details       This function copies the requested data element of a PID into
 *                the provided buffer.
 *
 * \param[in]     FreezeFrameIndex
 *                Index of the event's freeze frame
 * \param[in]     Pid
 *                The PID number
 * \param[in]     DataElementIndex
 *                The index of the data element
 * \param[out]    Buffer
 *                Pointer to the destination buffer
 * \param[in,out] BufSize
 *                In: Size of Buffer. Must be large enough to hold the data.
 *                Out: Number of written bytes.
 *
 * \return        E_OK
 *                The requested PID exists and data was copied
 * \return        E_NOT_OK
 *                The requested PID is not available and data was not copied
 *
 * \pre           Existence of the FreezeFrame must be verified before calling
 *                this function.
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON &&
 *                DEM_CFG_SUPPORT_OBDII == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_DataReportIF_ObdIIFreezeFrameCopyPidData(
  CONST(uint8, AUTOMATIC)  FreezeFrameIndex,
  CONST(uint8, AUTOMATIC)  Pid,
  CONST(uint8, AUTOMATIC)  DataElementIndex,
  CONSTP2VAR(uint8, AUTOMATIC, DEM_DCM_DATA)  Buffer,
  CONSTP2VAR(uint8, AUTOMATIC, DEM_DCM_DATA)  BufSize
  );
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_OBDII == STD_ON)                                                         /* COV_MSR_UNSUPPORTED XF tf xf */
/* ****************************************************************************
 * Dem_DataReportIF_ObdIIFreezeFrameCopyUdsData
 *****************************************************************************/
/*!
 * \brief         Copies the contents of an OBD freeze frame.
 *
 * \details       This function formats the OBD freeze frame data stored in the
 *                source according to the UDS snpashot record specification and
 *                copies the result into the given destination buffer.
 *                The function will abort copying data if the destination is
 *                too small.
 *
 * \param[in]     FreezeFrameIndex
 *                Index of the event's freeze frame
 * \param[out]    Buffer
 *                Pointer to the destination buffer
 * \param[in]     BufferSize
 *                Size of the destination buffer
 *
 * \pre           Existence of the FreezeFrame must be verified before calling
 *                this function.
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON &&
 *                DEM_CFG_SUPPORT_OBDII == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL FUNC(void, DEM_CODE)
Dem_DataReportIF_ObdIIFreezeFrameCopyUdsData(
  CONST(uint8, AUTOMATIC)  FreezeFrameIndex,
  CONSTP2VAR(uint8, AUTOMATIC, DEM_DCM_DATA)  Buffer,
  CONST(uint16, AUTOMATIC) BufferSize
  );                                                                                                                             /* PRQA S 0779 */ /* MD_MSR_5.1_779 */
#endif

#if (DEM_CFG_SUPPORT_SRECS == STD_ON)
/* ****************************************************************************
 * Dem_DataReportIF_CopyDidSRec
 *****************************************************************************/
/*!
 * \brief         Extracts a snapshot record, or a single DID from it.
 *
 * \details       The stored snapshot data of an event memory entry is written
 *                to DestBuffer in no particular format.
 *                The record number 0xff (in this case: most recent snapshot)
 *                is supported only in configurations using "calculated" record
 *                numbers.
 *
 * \param[in]     SnapshotEntry
 *                Pointer to the snapshot entry iterator
 * \param[in]     DataId
 *                Return only the data of this DID.
 * \param[out]    DestBuffer
 *                Pointer to the destination buffer.
 * \param[in,out] BufSize
 *                In: Available space in the receiving buffer.
 *                Out: Number of written bytes.
 *
 * \return        E_OK
 *                The requested data was copied to the destination buffer.
 * \return        DEM_NO_SUCH_ELEMENT
 *                The requested data indentifier is undefined within the
 *                requested record.
 * \return        DEM_BUFFER_TOO_SMALL
 *                The provided buffer size is too small.
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_SRECS == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_DataReportIF_CopyDidSRec(
  CONSTP2CONST(Dem_SnapshotEntry_IterType, AUTOMATIC, AUTOMATIC)  SnapshotEntry,
  CONST(uint16, AUTOMATIC)  DataId,
  CONSTP2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)  DestBuffer,
  CONSTP2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  BufSize
  );
#endif

#if (DEM_CFG_SUPPORT_ERECS == STD_ON)
/* ****************************************************************************
 * Dem_DataReportIF_CopyExtendedDataRecord
 *****************************************************************************/
/*!
 * \brief         Copy a record into the given buffer
 *
 * \details       Copy records of types "internal", "global" and "user"
 *
 * \param[in]     ExtendedEntryIter
 *                Pointer to the extended entry iterator
 * \param[out]    DestBuffer
 *                Pointer to the destination buffer
 * \param[in,out] BufSize
 *                In: Available space in the receiving buffer
 *                Out: Number of written bytes.
 *
 * \return        TRUE
 *                Data was copied
 * \return        FALSE
 *                No data was copied
 * \pre           -
 * \config        DEM_CFG_SUPPORT_ERECS == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL FUNC(boolean, DEM_CODE)
Dem_DataReportIF_CopyExtendedDataRecord(
  CONSTP2CONST(Dem_ExtendedEntry_IterType, AUTOMATIC, AUTOMATIC)  ExtendedEntryIter,
  CONSTP2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)  DestBuffer,
  CONSTP2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  BufSize
  );                                                                                                                             /* PRQA S 0779 */ /* MD_MSR_5.1_779 */
#endif

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* DEM_DATAREPORTIF_INTERFACE_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_DataReportIF_Interface.h
 *********************************************************************************************************************/
