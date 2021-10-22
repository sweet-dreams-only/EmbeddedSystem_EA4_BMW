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
 *  \defgroup   Dem_Dcm DEM DCM Interface
 *  \{
 *  \file       Dem_Dcm_Interface.h
 *  \brief      Diagnostic Event Manager (Dem) Interface declaration file
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

#if !defined (DEM_DCM_INTERFACE_H)
#define DEM_DCM_INTERFACE_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                        /* Dem module header */
/* ------------------------------------------------------------------------- */
#include "Dem_Dcm_Types.h"
/* ------------------------------------------------------------------------- */


/* ********************************************************************************************************************
 *  SUBCOMPONENT PRIVATE FUNCTION DECLARATIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \defgroup Dem_Dcm_Private Private Methods
 * \{
 */

#if (DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_ERECS == STD_ON)
/* ****************************************************************************
 * Dem_Dcm_ExtendedDataRecord_IsRecordMatch
 *****************************************************************************/
/*!
 * \brief         Test whether filter matches
 *
 * \details       Return whether the given RecordNumber is accepted by the filter
 *
 * \param[in]     RecordNumberFilter
 *                Defines which RecordNumber is accepted:
 *                 - 0xFF: Records 0x01 .. 0xEF are accepted
 *                 - 0xFE: Records 0x90 .. 0xEF are accepted
 *                 - otherwise only RecordNumbers which equal the RecordNumberFilter
 *                   are accepted
 * \param[in]     RecordNumber
 *                Extended data record number
 *
 * \return        TRUE
 *                The filter matches
 *
 * \return        FALSE
 *                The filter does not match
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON &&
 *                DEM_CFG_SUPPORT_ERECS == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE boolean Dem_Dcm_ExtendedDataRecord_IsRecordMatch(
  CONST(uint8, AUTOMATIC) RecordNumberFilter,
  CONST(uint8, AUTOMATIC) RecordNumber
  );
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_ERECS == STD_ON)
/* ****************************************************************************
 * Dem_Dcm_ReadExtendedDataRecord
 *****************************************************************************/
/*!
 * \brief         Copies a record into the given buffer
 *
 * \details       Copies records with types "internal", "global" and "user"
 *
 * \param[in]     ReadoutBufferId
 *                Unique handle of the readout buffer
 * \param[out]    DestBuffer
 *                Pointer to the destination buffer
 * \param[in,out] BufSize
 *                In: Available space in the receiving buffer
 *                Out: Number of written bytes.
 *
 * \return        E_OK
 *                Reading succeeded
 *
 * \return        DEM_BUFFER_TOO_SMALL
 *                provided buffer size too small
 *
 * \return        DEM_NO_SUCH_ELEMENT
 *                Record number is not supported by configuration and
 *                therefore invalid
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON &&
 *                DEM_CFG_SUPPORT_ERECS == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_ReadExtendedDataRecord(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC)  ReadoutBufferId,
  CONSTP2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)  DestBuffer,
  CONSTP2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  BufSize
  );                                                                                                                             /* PRQA S 0779 */ /* MD_MSR_5.1_779 */
#endif

# if (DEM_CFG_SUPPORT_DCM == STD_ON) \
    && ( (DEM_CFG_SUPPORT_SRECS == STD_ON) \
      || ((DEM_CFG_SUPPORT_OBDII == STD_ON) && (DEM_CFG_SUPPORT_OBDII_FREEZEFRAME_IN_SVC19 == STD_ON)) \
      || (DEM_CFG_SUPPORT_WWHOBD == STD_ON) \
      || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON))
/* ****************************************************************************
 * Dem_Dcm_SnapshotDataRecord_TestRecordMatch
 *****************************************************************************/
/*!
 * \brief         Test whether filter matches
 *
 * \details       Return whether the given RecordNumber is accepted by the filter
 *
 * \param[in]     RecordNumberFilter
 *                Defines which RecordNumber is accepted:
 *                 - 0xFF: Records 0x01 .. 0xEF are accepted,
 *                         If OBD is enabled, 0x00 is also accepted
 *                 - otherwise only RecordNumbers which equal the RecordNumberFilter
 *                   are accepted
 * \param[in]     RecordNumber
 *                Snapshot data record number
 *
 * \return        TRUE
 *                The filter matches
 *
 * \return        FALSE
 *                The filter does not match
 *
 * \pre           -
 * \config        (DEM_CFG_SUPPORT_DCM == STD_ON) \
 *                && ( (DEM_CFG_SUPPORT_SRECS == STD_ON) \
 *                  || ((DEM_CFG_SUPPORT_OBDII == STD_ON) && (DEM_CFG_SUPPORT_OBDII_FREEZEFRAME_IN_SVC19 == STD_ON)) \
 *                  || (DEM_CFG_SUPPORT_WWHOBD == STD_ON) \
 *                  || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON))
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE) 
Dem_Dcm_SnapshotDataRecord_TestRecordMatch(
  CONST(uint8, AUTOMATIC) RecordNumberFilter,
  CONST(uint8, AUTOMATIC) RecordNumber
  );
#endif

# if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 * Dem_Dcm_SnapshotDataRecord_SnapshotIteratorInit
 *****************************************************************************/
/*!
 * \brief         Initializes the given snapshot iterator
 *
 * \details       Initializes the given snapshot iterator depending on the
 *                selected source.
 *
 * \param[in]     ReadoutBufferId
 *                Unique handle of the readout buffer
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE for different ReadoutBufferIds
 *****************************************************************************/
DEM_LOCAL FUNC(void, DEM_CODE) 
Dem_Dcm_SnapshotDataRecord_SnapshotIteratorInit(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId
  );
#endif

# if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 * Dem_Dcm_SnapshotDataRecord_SourceSelectNext
 *****************************************************************************/
/*!
 * \brief         Select the next record source
 *
 * \details       Move the source iterater to the next source depending
 *                on the selected record.
 *
 * \param[in]     ReadoutBufferId
 *                Unique handle of the readout buffer
 *
 * \return        E_OK
 *                The next data source was selected
 * \return        DEM_NO_SUCH_ELEMENT
 *                No data source selected (end of iteration)
 *
 * \pre           -
 * \config        (DEM_CFG_SUPPORT_SRECS == STD_ON)
 *                 || (DEM_CFG_SUPPORT_OBDII == STD_ON)
 *                 || (DEM_CFG_SUPPORT_WWHOBD == STD_ON)
 *                 || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON)
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE for different ReadoutBufferIds
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE) 
Dem_Dcm_SnapshotDataRecord_SourceSelectNext(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId
  );
#endif

#if ( (DEM_CFG_SUPPORT_DCM == STD_ON) \
   && (( (DEM_CFG_SUPPORT_OBDII == STD_ON) && (DEM_CFG_SUPPORT_OBDII_FREEZEFRAME_IN_SVC19 == STD_ON)) \
     || (DEM_CFG_SUPPORT_WWHOBD == STD_ON) ) )
/* ****************************************************************************
 * Dem_Dcm_SnapshotDataRecord_ReadNext_Obd
 *****************************************************************************/
/*!
 * \brief         Reads the OBD record
 *
 * \details       Reads the OBD record
 *
 * \param[in]     ReadoutBufferId
 *                Unique handle of the readout buffer
 * \param[out]    DestBuffer
 *                Pointer to receive the extended record data
 * \param[in,out] BufSize
 *                In: Size of Buffer. Must be large enough to hold the data
 *                Out: Number of written bytes
 *
 * \return        E_NOT_OK
 *                Selection function is not called.
 * \return        DEM_BUFFER_TOO_SMALL
 *                Provided buffer size too small.
 * \return        DEM_NO_SUCH_ELEMENT
 *                Record number is not supported by configuration and
 *                therefore invalid
 *
 * \pre           -
 * \config           ( (DEM_CFG_SUPPORT_DCM == STD_ON) \
 *                && ( ((DEM_CFG_SUPPORT_OBDII == STD_ON) && (DEM_CFG_SUPPORT_OBDII_FREEZEFRAME_IN_SVC19 == STD_ON)) \
 *                  || (DEM_CFG_SUPPORT_WWHOBD == STD_ON) ) )
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE for different ReadoutBufferIds
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_SnapshotDataRecord_ReadNext_Obd(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId,
  CONSTP2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)  DestBuffer,
  CONSTP2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  BufSize
  );
#endif

# if ((DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_SRECS == STD_ON) \
      && (DEM_FEATURE_NEED_OEM_EXTENSIONS_VCC == STD_ON) \
      && (DEM_CFG_SUPPORT_MULTI_SAMPLE_SNAPSHOT == STD_ON))
/* ****************************************************************************
 * Dem_Dcm_SnapshotDataRecord_ReadNext_Vcc
 *****************************************************************************/
/*!
 * \brief         Reads a VCC record
 *
 * \details       Reads a VCC record
 *
 * \param[in]     ReadoutBufferId
 *                Unique handle of the readout buffer
 * \param[out]    DestBuffer
 *                Pointer to receive the extended record data
 * \param[in,out] BufSize
 *                In: Size of Buffer. Must be large enough to hold the data
 *                Out: Number of written bytes
 *
 * \return        E_NOT_OK
 *                Selection function is not called.
 * \return        DEM_BUFFER_TOO_SMALL
 *                Provided buffer size too small.
 * \return        DEM_NO_SUCH_ELEMENT
 *                Record number is not supported by configuration and
 *                therefore invalid
 *
 * \pre           -
 * \config           DEM_CFG_SUPPORT_DCM == STD_ON 
 *                && DEM_CFG_SUPPORT_SRECS == STD_ON
 *                && DEM_FEATURE_NEED_OEM_EXTENSIONS_VCC == STD_ON
 *                && DEM_CFG_SUPPORT_MULTI_SAMPLE_SNAPSHOT == STD_ON
 *             
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE for different ReadoutBufferIds
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_SnapshotDataRecord_ReadNext_Vcc(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId,
  CONSTP2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)  DestBuffer,
  CONSTP2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  BufSize
  );                                                                                                                             /* PRQA S 0779 */ /* MD_MSR_5.1_779 */
#endif

# if ((DEM_CFG_SUPPORT_DCM == STD_ON) \
  && (DEM_FEATURE_NEED_OEM_EXTENSIONS_TMC == STD_ON) \
  && (DEM_FEATURE_NEED_TIME_SERIES == STD_ON))
/* ****************************************************************************
 * Dem_Dcm_SnapshotDataRecord_ReadNext_Tmc
 *****************************************************************************/
/*!
 * \brief         Reads a TMC record
 *
 * \details       Reads a TMC time series record
 *
 * \param[in]     ReadoutBufferId
 *                Unique handle of the readout buffer
 * \param[out]    DestBuffer
 *                Pointer to receive the extended record data
 * \param[in,out] BufSize
 *                In: Size of Buffer. Must be large enough to hold the data
 *                Out: Number of written bytes
 *
 * \return        E_NOT_OK
 *                Selection function is not called.
 * \return        DEM_BUFFER_TOO_SMALL
 *                Provided buffer size too small.
 * \return        DEM_NO_SUCH_ELEMENT
 *                Record number is not supported by configuration and
 *                therefore invalid
 *
 * \pre           -
 * \config        ((DEM_CFG_SUPPORT_DCM == STD_ON) 
 *                 && (DEM_FEATURE_NEED_OEM_EXTENSIONS_TMC == STD_ON) 
 *                 && (DEM_FEATURE_NEED_TIME_SERIES == STD_ON))
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE for different ReadoutBufferIds
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_SnapshotDataRecord_ReadNext_Tmc(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId,
  CONSTP2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)  DestBuffer,
  CONSTP2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  BufSize
  );                                                                                                                             /* PRQA S 0779 */ /* MD_MSR_5.1_779 */
#endif

# if ((DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_SRECS == STD_ON))
/* ****************************************************************************
 * Dem_Dcm_SnapshotDataRecord_ReadNext_SRec
 *****************************************************************************/
/*!
 * \brief         Reads a standard snapshot record
 *
 * \details       Reads a standard snapshot record
 *
 * \param[in]     ReadoutBufferId
 *                Unique handle of the readout buffer
 * \param[out]    DestBuffer
 *                Pointer to receive the extended record data
 * \param[in,out] BufSize
 *                In: Size of Buffer. Must be large enough to hold the data
 *                Out: Number of written bytes
 *
 * \return        E_NOT_OK
 *                Selection function is not called.
 * \return        DEM_BUFFER_TOO_SMALL
 *                Provided buffer size too small.
 * \return        DEM_NO_SUCH_ELEMENT
 *                Record number is not supported by configuration and
 *                therefore invalid
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON &&
 *                DEM_CFG_SUPPORT_SRECS == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE for different ReadoutBufferIds
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_SnapshotDataRecord_ReadNext_SRec(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId,
  CONSTP2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)  DestBuffer,
  CONSTP2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  BufSize
  );                                                                                                                             /* PRQA S 0779 */ /* MD_MSR_5.1_779 */
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_FEATURE_NEED_TIME_SERIES == STD_ON)
/* ****************************************************************************
 * Dem_Dcm_GetSizeOfTimeSeriesSRec
 *****************************************************************************/
/*!
 * \brief         Calculates the size of a time series snapshot record
 *
 * \details       Calculates the size of a time series snapshot record
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 * \param[in]     RecordNumber
 *                Snapshot record number
 * \param[out]    SizeOfFreezeFrame
 *                Number of bytes.
 *
 * \return        E_OK
 *                Data was found and returned
 * \return        DEM_NO_SUCH_ELEMENT
 *                The requested record is not available
 *
 * \pre           A memory entry has to be locked for Dcm readout
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON &&
 *                DEM_FEATURE_NEED_TIME_SERIES == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_GetSizeOfTimeSeriesSRec(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(uint8, AUTOMATIC)  RecordNumber,
  CONSTP2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  SizeOfFreezeFrame
  );
#endif

#if ( (DEM_CFG_SUPPORT_DCM == STD_ON) \
   && ( (DEM_CFG_SUPPORT_SRECS == STD_ON) \
     || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON) \
     || (DEM_CFG_SUPPORT_OBDII == STD_ON) \
     || (DEM_CFG_SUPPORT_WWHOBD == STD_ON)) )                                                                                    /* COV_MSR_UNSUPPORTED TF tf tf xf xf */
/* ****************************************************************************
 * Dem_Dcm_SnapshotDataRecord_GetSize
 *****************************************************************************/
/*!
 * \brief         Calculates the total size of one or all snapshot record(s) of
 *                an event, formatted as UDS snapshot record (19 04)
 *
 * \details       Calculates the total size of one or all snapshot record(s) of
 *                an event, formatted as UDS snapshot record (19 04)
 *
 * \param[in]     ReadoutBufferId
 *                Unique handle of the readout buffer
 * \param[in]     RecordNumber
 *                Snapshot record number
 * \param[out]    SizeOfFreezeFrame
 *                Number of bytes.
 *
 * \return        E_OK
 *                Data was found and returned
 * \return        DEM_NO_SUCH_ELEMENT
 *                The requested record is not available
 *
 * \pre           A memory entry has to be locked for Dcm readout
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON &&
 *                ( DEM_CFG_SUPPORT_SRECS == STD_ON ||
 *                  DEM_FEATURE_NEED_TIME_SERIES == STD_ON ||
 *                  DEM_CFG_SUPPORT_OBDII == STD_ON ||
 *                  DEM_CFG_SUPPORT_WWHOBD == STD_ON )
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_SnapshotDataRecord_GetSize(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId,
  CONST(uint8, AUTOMATIC)  RecordNumber,
  CONSTP2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  SizeOfFreezeFrame
);
#endif


#if ( (DEM_CFG_SUPPORT_DCM == STD_ON) \
   && (DEM_FEATURE_NEED_OBD == STD_ON) \
   && (DEM_CFG_SUPPORT_OBDII_FREEZEFRAME_IN_SVC19 == STD_ON) )                                                                   /* COV_MSR_UNSUPPORTED XF tf xf xf */
/* ****************************************************************************
 * Dem_Dcm_CopyFreezeFrameObdII
 *****************************************************************************/
/*!
 * \brief         Validates the request to get the OBD-II FreezeFrame in UDS
 *                Format, and copies the data.
 *
 * \details       This function does the necessary validations and eventually
 *                calls Dem_DataReportIF_ObdIIFreezeFrameCopyUdsData to copy the OBD
 *                freeze frame data.
 *                If errors are detected, the appropriate negative response is
 *                returned.
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 * \param[out]    DestBuffer
 *                Pointer to the destination buffer
 * \param[in,out] BufSize
 *                In: Available space in the receiving buffer
 *                Out: Number of written bytes.
 *
 * \return        E_OK
 *                Data was found and returned
 * \return        E_NOT_OK
 *                The requested record is not available for EventId
 * \return        DEM_BUFFER_TOO_SMALL
 *                The destination buffer is too small
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON &&
 *                DEM_CFG_SUPPORT_OBDII == STD_ON &&
 *                DEM_CFG_SUPPORT_OBDII_FREEZEFRAME_IN_SVC19 == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_CopyFreezeFrameObdII(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONSTP2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)  DestBuffer,
  CONSTP2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  BufSize
  );
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_WWHOBD == STD_ON)                                                        /* COV_MSR_UNSUPPORTED XF tf xf */
/* ****************************************************************************
 * Dem_Dcm_CopyFreezeFrameWwhObd
 *****************************************************************************/
/*!
 * \brief         Validates the request to get the WWH-OBD FreezeFrame in UDS
 *                Format, and copies the data.
 *
 * \details       This function does the necessary validations and eventually
 *                calls Dem_DataReportIF_WWHOBDFreezeFrameCopyData to copy the WWH-OBD
 *                freeze frame data.
 *                If errors are detected, the appropriate negative response is
 *                returned.
 *
 * \param[in]     ReadoutBufferId
 *                Unique handle of the readout buffer
 * \param[out]    DestBuffer
 *                Pointer to the destination buffer
 * \param[in,out] BufSize
 *                In: Available space in the receiving buffer
 *                Out: Number of written bytes.
 *
 * \return        E_OK
 *                Data was found and returned
 * \return        E_NOT_OK
 *                The requested record is not available for EventId
 * \return        DEM_BUFFER_TOO_SMALL
 *                The destination buffer is too small
 *
 * \pre           A memory entry has to be locked for Dcm readout
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON &&
 *                DEM_CFG_SUPPORT_WWHOBD == STD_ON
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_CopyFreezeFrameWwhObd(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId,
  CONSTP2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)  DestBuffer,
  CONSTP2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  BufSize
  );
#endif

#if ( (DEM_CFG_SUPPORT_DCM == STD_ON) \
   && (DEM_CFG_SUPPORT_OBDII == STD_ON) \
   && (DEM_CFG_SUPPORT_OBDII_FREEZEFRAME_IN_SVC19 == STD_ON) )                                                                   /* COV_MSR_UNSUPPORTED XF tf xf xf */
/* ****************************************************************************
 * Dem_Dcm_GetSizeOfFreezeFrameObdII
 *****************************************************************************/
/*!
 * \brief         Calculates the total size of the OBD II freeze frame, when
 *                formatted as UDS snapshot record (19 04)
 *
 * \details       Calculates the total size of the OBD II freeze frame, when
 *                formatted as UDS snapshot record (19 04)
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 * \param[out]    SizeOfFreezeFrame
 *                Number of bytes.
 *
 * \return        E_OK
 *                Data was found and returned
 * \return        DEM_NO_SUCH_ELEMENT
 *                The requested record is not available
 *
 * \pre           A memory entry has to be locked for Dcm readout
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON &&
 *                DEM_CFG_SUPPORT_OBDII == STD_ON &&
 *                DEM_CFG_SUPPORT_OBDII_FREEZEFRAME_IN_SVC19 == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_GetSizeOfFreezeFrameObdII(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONSTP2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  SizeOfFreezeFrame
  );
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_WWHOBD == STD_ON)                                                        /* COV_MSR_UNSUPPORTED XF tf xf */
/* ****************************************************************************
 * Dem_Dcm_GetSizeOfFreezeFrameWwhObd
 *****************************************************************************/
/*!
 * \brief         Calculates the total size of the WWH-OBD freeze frame, when
 *                formatted as UDS snapshot record (19 04)
 *
 * \details       Calculates the total size of the WWH-OBD freeze frame, when
 *                formatted as UDS snapshot record (19 04)
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 * \param[out]    SizeOfFreezeFrame
 *                Number of bytes.
 *
 * \return        E_OK
 *                Data was found and returned
 * \return        DEM_NO_SUCH_ELEMENT
 *                The requested record is not available
 *
 * \pre           A memory entry has to be locked for Dcm readout
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON &&
 *                DEM_CFG_SUPPORT_WWHOBD == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_GetSizeOfFreezeFrameWwhObd(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONSTP2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  SizeOfFreezeFrame
  );
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_ERECS == STD_ON)
/* ****************************************************************************
 * Dem_Dcm_ExtendedDataRecord_CalcSize
 *****************************************************************************/
/*!
 * \brief         Calculates the size of an extended data record
 *
 * \details       Calculates the size of an extended data record
 *
 * \param[in]     CfgERecIndex
 *                Handle to Extended Data Record descriptor table
 * \param[in]     ReadoutBufferId
 *                Handle to readout buffer
 * \param[in]     ExtendedEntryIter
 *                Pointer to the extended entry iterator
 *
 * \return        E_OK
 *                Data was found and returned
 * \return        DEM_NO_SUCH_ELEMENT
 *                The requested record is not available
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON &&
 *                DEM_CFG_SUPPORT_ERECS == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE for different ClientIds
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint16, DEM_CODE)
Dem_Dcm_ExtendedDataRecord_CalcSize(
  CONST(Dem_Cfg_ERecIndexType, AUTOMATIC) CfgERecIndex,
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId,
  CONSTP2CONST(Dem_ExtendedEntry_IterType, AUTOMATIC, AUTOMATIC)  ExtendedEntryIter
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
 * \defgroup Dem_Dcm_Public Public Methods
 * \{
 */

/* ****************************************************************************
 * Dem_Dcm_Init
 *****************************************************************************/
/*!
 * \brief         Initializes DCM state variables
 *
 * \details       Initializes DCM state variables
 *
 * \pre           May be called only during module initialization
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Dcm_Init(
  void
  );

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 * Dem_Dcm_SnapshotDataRecord_SnapshotSelect
 *****************************************************************************/
/*!
 * \brief         Select the the given record source
 *
 * \details       Select the the given record source
 *
 * \param[in]     ClientId
 *                Unique client id, assigned to the instance of the calling
 *                module.
 *
 * \param[in]     RecordNumber
 *                The record number to select
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE for different ClientIds
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE) 
Dem_Dcm_SnapshotDataRecord_SnapshotSelect(
  CONST(uint8, AUTOMATIC) ClientId,
  CONST(uint8, AUTOMATIC)  RecordNumber
  );                                                                                                                             /* PRQA S 0779 */ /* MD_MSR_5.1_779 */
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 * Dem_Dcm_ExtendedDataRecord_RecordSelect
 *****************************************************************************/
/*!
 * \brief         Select the the given extended data record
 *
 * \details       Select the the given extended data record
 *
 * \param[in]     ClientId
 *                Unique client id, assigned to the instance of the calling
 *                module.
 *
 * \param[in]     RecordNumber
 *                The record number to select
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE for different ClientIds
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE) 
Dem_Dcm_ExtendedDataRecord_RecordSelect(
  CONST(uint8, AUTOMATIC) ClientId,
  CONST(uint8, AUTOMATIC)  RecordNumber
  );                                                                                                                             /* PRQA S 0779 */ /* MD_MSR_5.1_779 */
#endif

# if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 * Dem_Dcm_SnapshotDataRecord_ReadNext
 *****************************************************************************/
/*!
 * \brief         Validates the request to get an extended data record in UDS
 *                format, and copies the data.
 *
 * \details       Copies data into the given buffer.
 *
 * \param[in]     ClientId
 *                Unique client id, assigned to the instance of the calling
 *                module.
 * \param[out]    DestBuffer
 *                Pointer to the destination buffer
 * \param[in,out] BufSize
 *                In: Available space in the receiving buffer
 *                Out: Number of written bytes.
 *
 * \return        DEM_NO_SUCH_ELEMENT
 *                Selection function is not called.
 *
 * \return        DEM_BUFFER_TOO_SMALL
 *                provided buffer size too small.
 *
 * \return        DEM_PENDING: The requested value is calculated
 *                asynchronously and currently not available. The
 *                caller can retry later.
 *
 * \return        DEM_NO_SUCH_ELEMENT
 *                Record number is not supported by configuration and
 *                therefore invalid
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 *              
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE for different ClientIds.
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_SnapshotDataRecord_ReadNext(
  CONST(uint8, AUTOMATIC) ClientId,
  CONSTP2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)  DestBuffer,
  CONSTP2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  BufSize
  );                                                                                                                             /* PRQA S 0779 */ /* MD_MSR_5.1_779 */
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 * Dem_Dcm_GetSizeOfFreezeFrameSelection
 *****************************************************************************/
/*!
 * \brief         Get the size of a formatted snapshot record stored for a DTC
 *                (19 04).
 *
 * \details       Gets the size of a formatted snapshot record stored for a DTC
 *                (19 04).
 *
 * \param[in]     ClientId
 *                Unique client id, assigned to the instance of the calling
 *                module.
 * \param[out]    SizeOfFreezeFrame
 *                Pointer to receive the size in bytes
 *
 * \return        E_OK
 *                The requested data was returned
 * \return        E_NOT_OK
 *                Selection function is not called.
 * \return        DEM_NO_SUCH_ELEMENT
 *                The requested record is not available
 * \return        DEM_PENDING
 *                Not used by this implementation
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 *
 * \context       TASK|ISR2, from the master partition only
 * \synchronous   FALSE
 * \reentrant     TRUE for different ClientIds
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_GetSizeOfFreezeFrameSelection(
  CONST(uint8, AUTOMATIC)  ClientId,
  CONSTP2VAR(uint16, AUTOMATIC, DEM_DCM_DATA)  SizeOfFreezeFrame
  );
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 * Dem_Dcm_ExtendedDataRecord_ReadNext
 *****************************************************************************/
/*!
 * \brief         Validates the request to get an extended data record in UDS
 *                format and copies the data.
 *
 * \details       Copies data into the given buffer.
 *
 * \param[in]     ClientId
 *                Unique client id, assigned to the instance of the calling
 *                module.
 * \param[out]    DestBuffer
 *                Pointer to the destination buffer
 * \param[in,out] BufSize
 *                In: Available space in the receiving buffer
 *                Out: Number of written bytes.
 *
 * \return        E_OK
 *                Read extended data record successful.
 * \return        DEM_BUFFER_TOO_SMALL
 *                provided buffer size too small.
 * \return        DEM_NO_SUCH_ELEMENT
 *                Record number is not supported by configuration and 
 *                therefore invalid
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE for different ClientIds.
 ****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_ExtendedDataRecord_ReadNext(
  CONST(uint8, AUTOMATIC)  ClientId,
  CONSTP2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)  DestBuffer,
  CONSTP2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  BufSize
  );                                                                                                                             /* PRQA S 0779 */ /* MD_MSR_5.1_779 */
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 * Dem_Dcm_ExtendedDataRecord_GetSize
 *****************************************************************************/
/*!
 * \brief         Calculates the total of the event's extended data records
 *
 * \details       Calculates the total of the event's extended data records
 *
 * \param[in]     ClientId
 *                Unique client id, assigned to the instance of the calling
 *                module.
 * \param[out]    SizeOfExtendedDataRecord
 *                Number of bytes.
 *
 * \return        E_OK
 *                Data was found and returned
 * \return        DEM_NO_SUCH_ELEMENT
 *                The requested record is not available
 *
 * \pre           A memory entry has to be locked for Dcm readout
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE for different ClientIds
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_ExtendedDataRecord_GetSize(
  CONST(uint8, AUTOMATIC) ClientId,
  CONSTP2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  SizeOfExtendedDataRecord
  );
#endif

#if (DEM_FEATURE_NEED_OBD == STD_ON) && (DEM_CFG_SUPPORT_PID01 == STD_ON)                                                        /* COV_MSR_UNSUPPORTED XF xf xf */
/* ****************************************************************************
 * Dem_Dcm_ReadDataOfPID01
 *****************************************************************************/
/*!
 * \brief         Provides the monitoring status since DTCs cleared
 *
 * \details       Provides the monitoring status since DTCs cleared, formatted
 *                according to OBD-II
 *
 * \param[out]    PID01value
 *                Pointer to destination buffer. The PID data is formatted as such:
 *                supported - 0 == FALSE; 1 == TRUE
 *                ready     - 0 == TRUE; 1 == FALSE
 *                Byte 0
 *                  bit 0...6 - # of DTCs stored in this ECU
 *                  bit 7 - Malfunction Indicator Lamp (MIL) Status
 *                Byte 1
 *                  bit 0 - Misfire monitoring supported
 *                  bit 1 - Fuel system monitoring supported
 *                  bit 2 - Comprehensive component monitoring supported
 *                  bit 3 - Compression ignition monitoring supported
 *                  bit 4 - Misfire monitoring ready
 *                  bit 5 - Fuel system monitoring ready
 *                  bit 6 - Comprehensive component monitoring ready
 *                  bit 7 - reserved
 *                Byte 2
 *                  bit 0 - Catalyst monitoring supported
 *                  bit 1 - Heated catalyst monitoring supported
 *                  bit 2 - Evaporative system monitoring supported
 *                  bit 3 - Secondary air system monitoring supported
 *                  bit 4 - reserved
 *                  bit 5 - Oxygen sensor monitoring supported
 *                  bit 6 - Oxygen sensor heater monitoring
 *                  bit 7 - EGR system monitoring supported
 *                Byte3
 *                  bit 0 - Catalyst monitoring ready
 *                  bit 1 - Heated catalyst monitoring ready
 *                  bit 2 - Evaporative system monitoring ready
 *                  bit 3 - Secondary air system monitoring ready
 *                  bit 4 - reserved
 *                  bit 5 - Oxygen sensor monitoring ready
 *                  bit 6 - Oxygen sensor heater monitoring ready
 *                  bit 7 - EGR system monitoring ready
 *
 * \pre           -
 * \config        DEM_FEATURE_NEED_OBD == STD_ON &&
 *                DEM_CFG_SUPPORT_PID01 == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL FUNC(void, DEM_CODE)
Dem_Dcm_ReadDataOfPID01(
  CONSTP2VAR(uint8, AUTOMATIC, DEM_DCM_DATA)  PID01value
  );
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 * Dem_Dcm_GetStatusOfSelectedDTC
 *****************************************************************************/
/*!
 * \brief         Get the current Uds status of a selected DTC
 *
 * \details       Get the current Uds status of a selected DTC
 *
 * \param[in]     ClientId
 *                The client to query.
 *
 * \param[out]    DTCStatus
 *                Pointer to receive the Uds status
 *
 * \return        E_OK
 *                The requested status was stored in DTCStatus
 * \return        DEM_WRONG_DTC
 *                DTC is suppressed
 * \return        E_NOT_OK
 *                EventId of selection is invalid
 * \return        DEM_NO_SUCH_ELEMENT
 *                The selected DTC does not support a status
 *                (in case that permanent memory was selected as origin)
 *
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 * \pre           Requires a preceding DTC selection by Dem_SelectDTC
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_GetStatusOfSelectedDTC(
  uint8  ClientId,
  P2VAR(uint8, AUTOMATIC, DEM_DCM_DATA)  DTCStatus
  );
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 * Dem_Dcm_GetSeverityOfSelectedDTC
 *****************************************************************************/
/*!
 * \brief         Get the severity of a selected DTC
 *
 * \details       Get the severity of a selected DTC
 *
 * \param[in]     ClientId
 *                The client to query.
 *
 * \param[out]    DTCSeverity
 *                Pointer to receive the severity
 *
 * \return        E_OK
 *                The requested severity was stored in DTCSeverity
 * \return        DEM_WRONG_DTC
 *                DTC is suppressed or a hidden dependent Secondary ECU DTC
 * \return        E_NOT_OK
 *                EventId of selection is invalid
 *
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 * \pre           Requires a preceding DTC selection by Dem_SelectDTC
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_GetSeverityOfSelectedDTC(
  CONST(uint8, AUTOMATIC)  ClientId,
  P2VAR(uint8, AUTOMATIC, DEM_DCM_DATA)  DTCSeverity
  );
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 * Dem_Dcm_GetFunctionalUnitOfSelectedDTC
 *****************************************************************************/
/*!
 * \brief         Get the functional unit of a selected DTC
 *
 * \details       Get the functional unit of a selected DTC
 *
 * \param[in]     ClientId
 *                The client to query.
 *
 * \param[out]    DTCFunctionalUnit
 *                Pointer to receive the functional unit
 *
 * \return        E_OK
 *                The requested functional unit was stored in DTCFunctionalUnit
 * \return        DEM_WRONG_DTC
 *                DTC is suppressed or a hidden dependent Secondary ECU DTC
 * \return        E_NOT_OK
 *                EventId of selection is invalid
 *
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 * \pre           Requires a preceding DTC selection by Dem_SelectDTC
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_GetFunctionalUnitOfSelectedDTC(
  CONST(uint8, AUTOMATIC)  ClientId,
  P2VAR(uint8, AUTOMATIC, DEM_DCM_DATA)  DTCFunctionalUnit
  );
#endif

/* ****************************************************************************
 * Dem_Dcm_GetEventIdOfSelectedDTC
 *****************************************************************************/
/*!
 * \brief         Get the EventId of a selected DTC
 *
 * \details       Get the EventId of a selected DTC
 *
 * \param[in]     ClientId
 *                The client to query.
 *
 * \param[out]    EventId
 *                Pointer to receive the EventId
 *
 * \return        E_OK
 *                The requested EventId was stored in EventId
 * \return        E_NOT_OK
 *                EventId of selection is invalid
 *
 * \pre           Requires a preceding DTC selection by Dem_SelectDTC
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_GetEventIdOfSelectedDTC(
  CONST(uint8, AUTOMATIC)  ClientId,
  P2VAR(Dem_EventIdType, AUTOMATIC, DEM_APPL_DATA)  EventId
  );

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */


#endif /* DEM_DCM_INTERFACE_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_Dcm_Interface.h
 *********************************************************************************************************************/
