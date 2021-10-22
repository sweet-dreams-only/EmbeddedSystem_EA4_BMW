/**
*  \file
*
*  \brief       BMW SWC StdDiag
*
*  This file contains the implementation of the application data transfer support
*  of the module StdDiag for usage in the BMW AUTOSAR Core.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     5.4.0
*
*  \remarks     The StdDiag module is responsible for BMW specific session
*               handling and handles a number of BMW specific diagnostic requests.
*
*/

/*------------------------------------------------------------------------------
                      MISRA-Deviations
------------------------------------------------------------------------------*/
/*
   MISRA-C:2004 Rule 19.1: including StdDiag_MemMap.h is necessary throughout
   the file according to memory abstraction. See PRQA 5087.
*/


/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include "StdDiagClassic_Cfg.h"

#if( STDDIAG_ADT_SUPPORT == STD_ON )

#include "StdDiag_AssertAdapter.h"
#include "StdDiag_AdtTypes.h"
#include "StdDiag_AdtInternal.h"
#include "StdDiagClassic_Version.h"
#include "StdDiag.h"
#include "Rte_StdDiag.h"
#include "BUtil_ByteMask.h"

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!StdDiagClassic_CHECK_VERSION(5,4,0))
#error "Version of StdDiag_Adt.c does not match the version of the module!"
#endif

/**\{*/
/**
 * \name Possible values for parameter dataProcessingType
 */
#define STDDIAG_ADT_UPLOAD_PREPROCESS    0x01u /**< Upload Preprocessing */
#define STDDIAG_ADT_UPLOAD_POSTPROCESS   0x02u /**< Upload Postprocessing */
#define STDDIAG_ADT_DOWNLOAD_PREPROCESS  0x03u /**< Download Preprocessing */
#define STDDIAG_ADT_DOWNLOAD_POSTPROCESS 0x04u /**< Download Postprocessing */
/**\}*/

/*------------------------------------------------------------------------------
                      Global Variables
------------------------------------------------------------------------------*/
/* PRQA S 5087 2 */
#define StdDiag_START_SEC_VAR_NO_INIT_BOOLEAN
#include "StdDiag_MemMap.h"

/**
 * \brief StdDiag_AdtPrePostProcessingPending indicates that application callback is outstanding
 */
static boolean StdDiag_AdtPrePostProcessingPending;

/**
 * \brief StdDiag_AdtPrePostProcessingResult holds the result of an asynchronous execution
 */
static boolean StdDiag_AdtPrePostProcessingResult;

/* PRQA S 5087 2 */
#define StdDiag_STOP_SEC_VAR_NO_INIT_BOOLEAN
#include "StdDiag_MemMap.h"

/* PRQA S 5087 2 */
#define StdDiag_START_SEC_VAR_NO_INIT_16
#include "StdDiag_MemMap.h"

/**
 * \brief StdDiag_AdtCurrentMemObjectIndex holds the index of the currently executed memory object
 */
static uint16 StdDiag_AdtCurrentMemObjectIndex;

/* PRQA S 5087 2 */
#define StdDiag_STOP_SEC_VAR_NO_INIT_16
#include "StdDiag_MemMap.h"


/*------------------------------------------------------------------------------
                      Global Functions
-------------------------------------------------------------------------------*/

/* PRQA S 5087 2 */
#define StdDiag_START_SEC_CODE
#include "StdDiag_MemMap.h"

/**
 * \brief Function to get index of memory object identifier
 *
 * This function searches the given memory object identifier in the configured
 * table and returns the corresponding index for further processing.
 *
 * \param[in] memObjectIdData contains the memory object identifier
 * \param[in] memObjectSize contains the size of the memory object identifier
 * \param[out] memObjectIndex contains the index of the memory object identifier
 *
 * \retval TRUE memory object identifier is available, memObjectIndex is valid
 * \retval FALSE memory object identifier is not available in configuration
 *
 */
boolean StdDiag_AdtGetMemoryObjectIdIndex(
    const uint8 *memObjectIdData,
    uint8 memObjectSize,
    uint16 *memObjectIndex
)
{
  StdDiag_MemObjIdType memoryObjectId;
  uint16 currentMemoryObjectIndex = 0;
  boolean memoryObjectFound = FALSE;

  memoryObjectId.routineId = BUtil_Make16Bit(memObjectIdData[0],memObjectIdData[1]);
  memoryObjectId.subRoutineId = BUtil_Make16Bit(memObjectIdData[2],memObjectIdData[3]);
  memcpy(&memoryObjectId.controlId, &memObjectIdData[4], memObjectSize-4u);
  memoryObjectId.controlIdLength = memObjectSize-4u;

  do {
    if ((memoryObjectId.routineId == StdDiag_MemoryObjectIdArray[currentMemoryObjectIndex].routineId) &&
        (memoryObjectId.subRoutineId == StdDiag_MemoryObjectIdArray[currentMemoryObjectIndex].subRoutineId) &&
        (memoryObjectId.controlIdLength == StdDiag_MemoryObjectIdArray[currentMemoryObjectIndex].controlIdLength))
    {
      /* found entry matching RID, sub RID and length of controlId, so compare controlId */
      if (0 == memcmp(&memoryObjectId.controlId, &StdDiag_MemoryObjectIdArray[currentMemoryObjectIndex].controlId, memoryObjectId.controlIdLength))
      {
        memoryObjectFound = TRUE;
        *memObjectIndex = currentMemoryObjectIndex;
      }
    }
    currentMemoryObjectIndex++;
  } while ( (STDDIAG_NUMBER_MEMORY_OBJECT_IDENTIFIER > currentMemoryObjectIndex) &&
            (FALSE == memoryObjectFound));

  return memoryObjectFound;
}


/**
 * \brief Function to start request up- or download for specific memory object
 *
 * This function dispatches a request for up- or download to the corresponding
 * application.
 *
 * \param[in] direction states whether upload or download is requested
 * \param[in] memObjectIndex contains the index of the memory object identifier
 * \param[in] dataFormatIdentifier contains the data format identifier of the request
 * \param[in] memorySize contains the requested memory size for up- or download
 * \param[out] maxBlockLength contains the maximum block size for transfer data requests
 * \param[out] ErrorCode Error code according to Dcm specification.
 *                       Only set in case of return value E_NOT_OK
 *
 * \retval E_OK operation was successful
 * \retval E_NOT_OK operation was not successful
 * \retval DCM_E_PENDING operation is not yet finished
 *
 */
Std_ReturnType StdDiag_AdtStartRequestUpDownload(
    StdDiag_AdtActiveProcessType direction,
    uint16 memObjectIndex,
    uint8 dataFormatIdentifier,
    uint32 memorySize,
    uint32 *maxBlockLength,
    Dcm_NegativeResponseCodeType *ErrorCode
)
{
  Std_ReturnType retValUser;

  if (STDDIAG_ADT_DOWNLOAD == direction)
  {
    retValUser = StdDiag_AdtFctPtrArray[memObjectIndex].fctPtrRequestDownload(dataFormatIdentifier, memorySize, maxBlockLength, ErrorCode);
  } else
  {
    retValUser = StdDiag_AdtFctPtrArray[memObjectIndex].fctPtrRequestUpload(dataFormatIdentifier, memorySize, maxBlockLength, ErrorCode);
  }

  return retValUser;
}


/**
 * \brief Function to exit active up- or download process for specific memory object
 *
 * This function dispatches a request for exiting an active up- or download process
 * to the corresponding application.
 *
 * \param[in] direction states whether upload or download is requested
 * \param[in] memObjectIndex contains the index of the memory object identifier
 *
 * \retval E_OK operation was successful
 *
 */
Std_ReturnType StdDiag_AdtStartUpDownloadExit(
    StdDiag_AdtActiveProcessType direction,
    uint16 memObjectIndex
)
{
  if (STDDIAG_ADT_DOWNLOAD == direction)
  {
    /* ignore return value, interface only allows E_OK */
    (void) StdDiag_AdtFctPtrArray[memObjectIndex].fctPtrRequestDownloadExit();
  } else
  {
    /* ignore return value, interface only allows E_OK */
    (void) StdDiag_AdtFctPtrArray[memObjectIndex].fctPtrRequestUploadExit();
  }

  return E_OK;
}


/**
 * \brief Function to start download process for specific memory object
 *
 * This function dispatches download process requests to the corresponding application.
 *
 * \param[in] memObjectIndex contains the index of the memory object identifier
 * \param[in] blockSequenceCounter contains the block sequence counter of the request
 * \param[in] length contains the length of the current data block for download
 * \param[in] Data contains the maximum block size for transfer data requests
 * \param[out] ErrorCode Error code according to Dcm specification.
 *                       Only set in case of return value E_NOT_OK
 *
 * \retval E_OK operation was successful
 * \retval E_NOT_OK operation was not successful
 * \retval DCM_E_PENDING operation is not yet finished
 *
 */
Std_ReturnType StdDiag_AdtStartDownload(
    uint16 memObjectIndex,
    uint8 blockSequenceCounter,
    uint32 length,
    const uint8 *Data,
    Dcm_NegativeResponseCodeType *ErrorCode
)
{
  return StdDiag_AdtFctPtrArray[memObjectIndex].fctPtrDownload(blockSequenceCounter, Data, length, ErrorCode);
}


/**
 * \brief Function to start upload process for specific memory object
 *
 * This function dispatches upload process requests to the corresponding application.
 *
 * \param[in] memObjectIndex contains the index of the memory object identifier
 * \param[in] blockSequenceCounter contains the block sequence counter of the request
 * \param[in] length contains the length of the current data block for upload
 * \param[out] Data contains the maximum block size for transfer data requests
 * \param[out] ErrorCode Error code according to Dcm specification.
 *                       Only set in case of return value E_NOT_OK
 *
 * \retval E_OK operation was successful
 * \retval E_NOT_OK operation was not successful
 * \retval DCM_E_PENDING operation is not yet finished
 *
 */
Std_ReturnType StdDiag_AdtStartUpload(
    uint16 memObjectIndex,
    uint8 blockSequenceCounter,
    uint32 length,
    uint8 *Data,
    Dcm_NegativeResponseCodeType *ErrorCode
)
{
  return StdDiag_AdtFctPtrArray[memObjectIndex].fctPtrUpload(blockSequenceCounter, Data, length, ErrorCode);
}


/**
 * \brief diagnostic request for pre- or post-processing up- or download.
 *
 * This function implements the diagnostic request to handle pre- or post-
 * processing of a data transfer
 * (Request 0x31 0x01 0x70 0x00)
 *
 * \param[in] Data contains the payload of the request
 * \param[in] OpStatus State of the Dcm
 * \param[out] Result contains the result of the operation
 * \param[in] currentDataLength contains the length of valid bytes in parameter Data
 * \param[out] ErrorCode Error code according to Dcm specification.
 *                       Only set in case of return value E_NOT_OK
 *
 * \retval E_OK routine control operation was successful
 * \retval E_NOT_OK routine control operation was not successful
 * \retval RTE_E_RoutineServices_UpDownloadPrePostProcessing_DCM_E_PENDING operation is not yet finished
 *
 * \lhref ADUE_2773, ADUE_2774, ADUE_2930, ADUE_2927, ADUE_2961
 *
 */
Std_ReturnType StdDiag_RoutineControlStartUpDownloadPrePostProcessing(
    const uint8* Data,
    Dcm_OpStatusType OpStatus,
    uint8 *Result,
    uint16 currentDataLength,
    Dcm_NegativeResponseCodeType *ErrorCode )
{
  Std_ReturnType retVal = E_OK;
  Std_ReturnType retValUser;
  uint8 dataProcessingType;
  uint8 memoryObjectIdSize;
  uint8 applicationFormatIdentifier;
  uint16 currentMemoryObjectIndex;
  boolean memoryObjectFound;

  switch (OpStatus)
  {
    case DCM_INITIAL:

      /* check minimum data length:
       * 1 byte data processing type
       * 1 byte address format identifier
       * 5 byte memory object identifier
       * 1 byte application format identifier
       */
      if (8u > currentDataLength)
      {
        *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
        return E_NOT_OK;
      }

      dataProcessingType = Data[0];
      memoryObjectIdSize = (0x0Fu & Data[1]);

      /* check data consistency:
       * memory object identifier is at least 5 byte,
       * data processing type is in range 1 to 4
       */
      if ((5u > memoryObjectIdSize) ||
          (STDDIAG_ADT_UPLOAD_PREPROCESS > dataProcessingType) ||
          (STDDIAG_ADT_DOWNLOAD_POSTPROCESS < dataProcessingType) ||
          (currentDataLength < memoryObjectIdSize + 3u))
      {
        *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
        return E_NOT_OK;
      }

      applicationFormatIdentifier = Data[2 + memoryObjectIdSize];

      /* check exact data length: */
      if (currentDataLength != (memoryObjectIdSize + applicationFormatIdentifier + 3u))
      {
        *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
        return E_NOT_OK;
      }

      memoryObjectFound = StdDiag_AdtGetMemoryObjectIdIndex(&Data[2], memoryObjectIdSize, &currentMemoryObjectIndex);

      if (TRUE == memoryObjectFound){
        /* dispatch to corresponding Rte Call */
        StdDiag_AdtCurrentMemObjectIndex = currentMemoryObjectIndex;
        StdDiag_AdtPrePostProcessingPending = FALSE;

        switch (dataProcessingType)
        {
          case STDDIAG_ADT_UPLOAD_PREPROCESS:
            retValUser = StdDiag_AdtFctPtrArray[StdDiag_AdtCurrentMemObjectIndex].fctPtrUploadPreprocess(&Data[3 + memoryObjectIdSize], applicationFormatIdentifier, ErrorCode);
            break;

          case STDDIAG_ADT_UPLOAD_POSTPROCESS:
            retValUser = StdDiag_AdtFctPtrArray[StdDiag_AdtCurrentMemObjectIndex].fctPtrUploadPostprocess(&Data[3 + memoryObjectIdSize], applicationFormatIdentifier, ErrorCode);
            break;

          case STDDIAG_ADT_DOWNLOAD_PREPROCESS:
            retValUser = StdDiag_AdtFctPtrArray[StdDiag_AdtCurrentMemObjectIndex].fctPtrDownloadPreprocess(&Data[3 + memoryObjectIdSize], applicationFormatIdentifier, ErrorCode);
            break;

          case STDDIAG_ADT_DOWNLOAD_POSTPROCESS:
            retValUser = StdDiag_AdtFctPtrArray[StdDiag_AdtCurrentMemObjectIndex].fctPtrDownloadPostprocess(&Data[3 + memoryObjectIdSize], applicationFormatIdentifier, ErrorCode);
            break;

          default:
            break;
        }

        switch (retValUser)
        {
          case RTE_E_ApplicationDataTransfer_E_RUNNING:
            StdDiag_AdtPrePostProcessingPending = TRUE;
            retVal = RTE_E_RoutineServices_UpDownloadPrePostProcessing_DCM_E_PENDING;
            break;

          case RTE_E_ApplicationDataTransfer_E_NOT_OK:
            *Result = 0x02u;
            break;

          default:
            *Result = 0x01u;
            break;
        }
      }
      else
      {
        *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
        retVal = E_NOT_OK;
      }

      break;

    case DCM_PENDING:
      if (TRUE == StdDiag_AdtPrePostProcessingPending)
      {
        retVal = RTE_E_RoutineServices_UpDownloadPrePostProcessing_DCM_E_PENDING;
      }
      else
      {
        if (TRUE == StdDiag_AdtPrePostProcessingResult) {
          *Result = 0x01u;
        } else {
          *Result = 0x02u;
        }
      }
      break;

    case DCM_CANCEL:
      (void) StdDiag_AdtFctPtrArray[StdDiag_AdtCurrentMemObjectIndex].fctPtrCancelOperation();
      StdDiag_AdtPrePostProcessingPending = FALSE;
      break;

    default:
      break;
  }

  return retVal;
}

/**
 * \brief callback notification for application data transfer
 *
 * This function is called when application data transfer call has
 * been finished.
 *
 * \param[in]  result indicates whether operation was successful
 *
 * \retval E_OK function returns always ok
 *
 */
Std_ReturnType StdDiag_ApplicationDataTransferCbk( boolean result )
{
  if (TRUE == StdDiag_AdtPrePostProcessingPending)
  {
    StdDiag_AdtPrePostProcessingResult = result;
    StdDiag_AdtPrePostProcessingPending = FALSE;
  }

  return E_OK;
}

/* PRQA S 5087 2 */
#define StdDiag_STOP_SEC_CODE
#include "StdDiag_MemMap.h"

#endif /* STDDIAG_ADT_SUPPORT */
