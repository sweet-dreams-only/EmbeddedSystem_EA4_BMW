/**
*  \file
*
*  \brief       BMW SWC StdDiag
*
*  This file is the internal Adt header file of the classic adapter part of the module StdDiag
*  for usage in the BMW AUTOSAR Core.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2017
*
*  \version     5.4.0
*
*  \remarks     The StdDiag module is responsible for BMW specific session
*               handling and handles a number of BMW specific diagnostic requests.
*
*/

#ifndef STDDIAG_ADTINTERNAL_H
#define STDDIAG_ADTINTERNAL_H

/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/
#include "StdDiagClassic_Version.h"

/*------------------------------------------------------------------------------
                      Macros
-------------------------------------------------------------------------------*/

/* check version of the module */
#if (!StdDiagClassic_CHECK_VERSION(5,4,0))
   #error "Version of StdDiag_AdtInternal.h does not match the version of the module!"
#endif

/*------------------------------------------------------------------------------
                      Type Definitions
------------------------------------------------------------------------------*/

typedef enum
{
  STDDIAG_ADT_NOPROCESS,
  STDDIAG_ADT_DOWNLOAD,
  STDDIAG_ADT_UPLOAD
} StdDiag_AdtActiveProcessType;


/*------------------------------------------------------------------------------
                      Global Functions
-------------------------------------------------------------------------------*/

/* PRQA S 5087 2 */
#define StdDiag_START_SEC_CODE
#include "StdDiag_MemMap.h"

/**
 * \brief Function to get index of memory object identifier
 */
extern boolean StdDiag_AdtGetMemoryObjectIdIndex(
    const uint8 *memObjectIdData,
    uint8 memObjectSize,
    uint16 *memObjectIndex
);

/**
 * \brief Function to start request up- or download for specific memory object
 */
extern Std_ReturnType StdDiag_AdtStartRequestUpDownload(
    StdDiag_AdtActiveProcessType direction,
    uint16 memObjectIndex,
    uint8 dataFormatIdentifier,
    uint32 memorySize,
    uint32 *maxBlockLength,
    Dcm_NegativeResponseCodeType *ErrorCode
);

/**
 * \brief Function to exit active up- or download process for specific memory object
 */
extern Std_ReturnType StdDiag_AdtStartUpDownloadExit(
    StdDiag_AdtActiveProcessType direction,
    uint16 memObjectIndex
);

/**
 * \brief Function to start download process for specific memory object
 */
extern Std_ReturnType StdDiag_AdtStartDownload(
    uint16 memObjectIndex,
    uint8 blockSequenceCounter,
    uint32 length,
    const uint8 *Data,
    Dcm_NegativeResponseCodeType *ErrorCode
);

/**
 * \brief Function to start upload process for specific memory object
 */
extern Std_ReturnType StdDiag_AdtStartUpload(
    uint16 memObjectIndex,
    uint8 blockSequenceCounter,
    uint32 length,
    uint8 *Data,
    Dcm_NegativeResponseCodeType *ErrorCode
);

/* PRQA S 5087 2 */
#define StdDiag_STOP_SEC_CODE
#include "StdDiag_MemMap.h"


#endif /* STDDIAG_ADTINTERNAL_H */
