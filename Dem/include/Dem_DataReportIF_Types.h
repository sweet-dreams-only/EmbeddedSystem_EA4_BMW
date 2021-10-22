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
/*! \addtogroup Dem_DataReportIF
 *  \{
 *  \file       Dem_DataReportIF_Types.h
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

#if !defined (DEM_DATAREPORTIF_TYPES_H)
#define DEM_DATAREPORTIF_TYPES_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                  /* Own subcomponent header */
/* ------------------------------------------------------------------------- */
#include "Dem_Int.h"

/* ********************************************************************************************************************
 *  SUBCOMPONENT CONSTANT MACROS
 *********************************************************************************************************************/
#if (DEM_FEATURE_NEED_OEM_EXTENSIONS_TMC == STD_ON)
/*! Number of bytes per DID added to response in UDS protocol */
# define DEM_DATAREPORTIF_ADDITIONAL_BYTES_PER_DID       (3)
#else
/*! Number of bytes per DID added to response in UDS protocol */
# define DEM_DATAREPORTIF_ADDITIONAL_BYTES_PER_DID       (2)
#endif

/*! Data byte value substituted when callbacks fail to retrieve data */
#define DEM_DATAREPORTIF_INVALID_DATA_PATTERN            (0xffU)
/* ********************************************************************************************************************
 *  SUBCOMPONENT FUNCTION MACROS
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  SUBCOMPONENT DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/*! Structure for DID data readout */
struct Dem_DataReportIF_CopyDidInfoType_s
{
  Dem_ConstSharedDataPtrType        SourceBuffer;  /*!< source buffer providing the DID data */
  Dem_SharedDataPtrType             DestinationBuffer;  /*!< destination buffer receiving the DID data */
  Dem_MemoryEntry_HandleType        MemoryEntryId;  /*< Id of memory entry holding the DTC data */
  Dem_EventIdType                   EventId;  /*!< EventId for which data is collected */
  uint16                            BufferSize;  /*!< Buffer size of the destination buffer */
  uint16                            ReadIndex;  /*!< Current read index from the source buffer */
  uint16                            WriteIndex;  /*!< Current write index in the destination buffer */
};

/*! Type for DID data readout */
typedef struct Dem_DataReportIF_CopyDidInfoType_s Dem_DataReportIF_CopyDidInfoType;
/*! Pointer to type for DID data readout */
typedef P2VAR(Dem_DataReportIF_CopyDidInfoType, TYPEDEF, AUTOMATIC) Dem_DataReportIF_CopyDidInfoPtrType;
/*! Non-writable pointer to type for DID data readout */
typedef P2CONST(Dem_DataReportIF_CopyDidInfoType, TYPEDEF, AUTOMATIC) Dem_DataReportIF_ConstCopyDidInfoPtrType;

#endif /* DEM_DATAREPORTIF_TYPES_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_DataReportIF_Types.h
 *********************************************************************************************************************/
