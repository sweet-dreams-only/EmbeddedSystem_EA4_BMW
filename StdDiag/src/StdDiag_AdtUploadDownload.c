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

#include "StdDiagClassic_Version.h"
#include "StdDiag_DcmTypes.h"
#include "StdDiag_AdtInternal.h"
#include "BUtil_ByteMask.h"
#include "BUtil_Algorithm.h"

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!StdDiagClassic_CHECK_VERSION(5,4,0))
#error "Version of StdDiag_AdtUploadDownload.c does not match the version of the module!"
#endif

/*------------------------------------------------------------------------------
                      Type Definitions
------------------------------------------------------------------------------*/

typedef struct
{
  uint32 totalDataSize;
  uint32 currentDataSize;
  uint32 dataBlockSize;
  uint16 currentMemObjIdx;
  uint8 blockSequenceCounter;
  StdDiag_AdtActiveProcessType currentProcess;
} StdDiag_AdtUploadDownloadProcessType;

/*------------------------------------------------------------------------------
                      Global Variables
------------------------------------------------------------------------------*/
/* PRQA S 5087 2 */
#define StdDiag_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "StdDiag_MemMap.h"

/**
 * \brief StdDiag_AdtUploadDownloadProcess holds the current status of an ongoing upload or download process.
 */
static StdDiag_AdtUploadDownloadProcessType StdDiag_AdtUploadDownloadProcess;

/* PRQA S 5087 2 */
#define StdDiag_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "StdDiag_MemMap.h"

/*------------------------------------------------------------------------------
                      Local Function Prototypes
------------------------------------------------------------------------------*/
/* PRQA S 5087 2 */
#define StdDiag_START_SEC_CODE
#include "StdDiag_MemMap.h"

static Std_ReturnType StdDiag_HandleRequestUpDownload(
    StdDiag_AdtActiveProcessType direction,
    Dcm_OpStatusType OpStatus,
    Dcm_MsgContextType* pMsgContext,
    Dcm_NegativeResponseCodeType* ErrorCode
);

/*------------------------------------------------------------------------------
                      Local Functions
-------------------------------------------------------------------------------*/
static Std_ReturnType StdDiag_HandleRequestUpDownload(
    StdDiag_AdtActiveProcessType direction,
    Dcm_OpStatusType OpStatus,
    Dcm_MsgContextType* pMsgContext,
    Dcm_NegativeResponseCodeType* ErrorCode
)
{
  Std_ReturnType retVal;
  uint8 dataFormatIdentifier;
  uint8 memoryObjectIdSize;
  uint8 memorySizeSize;
  uint32 memorySize;
  boolean memoryObjectFound;
  uint32 maxBlockLength;
  uint8 i;

  /* OpStatus currently not used */
  (void) OpStatus;

  /* check minimum data length according ISO */
  if (4u > pMsgContext->reqDataLen)
  {
    *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
    return E_NOT_OK;
  }

  dataFormatIdentifier = pMsgContext->reqData[0];
  memoryObjectIdSize = (0x0Fu & pMsgContext->reqData[1]);
  memorySizeSize = ((0xF0u & pMsgContext->reqData[1]) >> 4u);

  /* check data consistency:
   * memory object identifier is at least 5 byte,
   * size of memory size is in range 1 to 4 byte (restriction due to data type)
   */
  if ((5u > memoryObjectIdSize) ||
      (1u > memorySizeSize) ||
      (4u < memorySizeSize))
  {
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
  }

  /* check exact data length */
  if (pMsgContext->reqDataLen != (memoryObjectIdSize + memorySizeSize + 2u))
  {
    *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
    return E_NOT_OK;
  }

  /* check ongoing process after length checks */
  if (STDDIAG_ADT_NOPROCESS != StdDiag_AdtUploadDownloadProcess.currentProcess)
  {
    *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
    return E_NOT_OK;
  }

  /* check response buffer size */
  if (5u > pMsgContext->resMaxDataLen)
  {
    *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
    return E_NOT_OK;
  }

  memoryObjectFound = StdDiag_AdtGetMemoryObjectIdIndex(&(pMsgContext->reqData[2]), memoryObjectIdSize, &StdDiag_AdtUploadDownloadProcess.currentMemObjIdx);

  if (TRUE == memoryObjectFound)
  {
    /* extract memory size from byte array */
    memorySize = pMsgContext->reqData[memoryObjectIdSize+2];

    for (i = 1; i < memorySizeSize; i++)
    {
      memorySize = memorySize << 8u;
      memorySize = memorySize + pMsgContext->reqData[memoryObjectIdSize+2+i];
    }

    retVal = StdDiag_AdtStartRequestUpDownload(direction,
                                               StdDiag_AdtUploadDownloadProcess.currentMemObjIdx,
                                               dataFormatIdentifier,
                                               memorySize,
                                               &maxBlockLength,
                                               ErrorCode);

    /* adjust status and assemble response */
    if (E_OK == retVal)
    {
      /* restrict to uint32 range */
      if (0xFFFFFFFEu > maxBlockLength)
      {
        maxBlockLength += 2u;
      }
      else
      {
        maxBlockLength = 0xFFFFFFFFu;
      }

      StdDiag_AdtUploadDownloadProcess.currentProcess = direction;
      StdDiag_AdtUploadDownloadProcess.blockSequenceCounter = 0;
      StdDiag_AdtUploadDownloadProcess.totalDataSize = memorySize;
      StdDiag_AdtUploadDownloadProcess.currentDataSize = 0;
      StdDiag_AdtUploadDownloadProcess.dataBlockSize = maxBlockLength - 2u;

      /* assemble response */
      pMsgContext->resData[0] = 0x40u;
      pMsgContext->resData[1] = BUtil_GetHiHiByte(maxBlockLength);
      pMsgContext->resData[2] = BUtil_GetHiLoByte(maxBlockLength);
      pMsgContext->resData[3] = BUtil_GetLoHiByte(maxBlockLength);
      pMsgContext->resData[4] = BUtil_GetLoLoByte(maxBlockLength);
      pMsgContext->resDataLen = 5u;
    }
  }
  else
  {
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    retVal = E_NOT_OK;
  }

  return retVal;
}
/*------------------------------------------------------------------------------
                      Global Functions
-------------------------------------------------------------------------------*/

/**
 * \brief diagnostic service handler for UDS Service 0x34 Request Download.
 *
 * \param[in] OpStatus State of the Dcm
 * \param[in] pMsgContext pointer to message context without SID
 * \param[out] ErrorCode Error code according to Dcm specification.
 *                       Only set in case of return value E_NOT_OK
 *
 * \retval E_OK routine control operation was successful
 * \retval E_NOT_OK routine control operation was not successful
 * \retval DCM_E_PENDING result of routine control operation is pending
 *
 * \remarks This function is called by Dcm on reception of UDS Service Request Download (0x34)
 *
 * \lhref ADUE_2931, ADUE_2935, ADUE_2936, ADUE_2933, ADUE_2945, ADUE_2937, ADUE_2962
 *
 */
Std_ReturnType StdDiag_RequestDownload(
    Dcm_OpStatusType OpStatus,
    Dcm_MsgContextType* pMsgContext,
    Dcm_NegativeResponseCodeType* ErrorCode
)
{
  return StdDiag_HandleRequestUpDownload(STDDIAG_ADT_DOWNLOAD, OpStatus, pMsgContext, ErrorCode  );
}


/**
 * \brief diagnostic service handler for UDS Service 0x35 Request Upload.
 *
 * \param[in] OpStatus State of the Dcm
 * \param[in] pMsgContext pointer to message context without SID
 * \param[out] ErrorCode Error code according to Dcm specification.
 *                       Only set in case of return value E_NOT_OK
 *
 * \retval E_OK routine control operation was successful
 * \retval E_NOT_OK routine control operation was not successful
 * \retval DCM_E_PENDING result of routine control operation is pending
 *
 * \remarks This function is called by Dcm on reception of UDS Service Request Upload (0x35)
 *
 * \lhref ADUE_2938, ADUE_2940, ADUE_2942, ADUE_2943, ADUE_2946, ADUE_3577
 *
 */
Std_ReturnType StdDiag_RequestUpload(
    Dcm_OpStatusType OpStatus,
    Dcm_MsgContextType* pMsgContext,
    Dcm_NegativeResponseCodeType* ErrorCode
)
{
  return StdDiag_HandleRequestUpDownload(STDDIAG_ADT_UPLOAD, OpStatus, pMsgContext, ErrorCode  );
}


/**
 * \brief diagnostic service handler for UDS Service 0x36 Transfer Data.
 *
 * \param[in] OpStatus State of the Dcm
 * \param[in] pMsgContext pointer to message context without SID
 * \param[out] ErrorCode Error code according to Dcm specification.
 *                       Only set in case of return value E_NOT_OK
 *
 * \retval E_OK routine control operation was successful
 * \retval E_NOT_OK routine control operation was not successful
 * \retval DCM_E_PENDING result of routine control operation is pending
 *
 * \remarks This function is called by Dcm on reception of UDS Service Transfer Data (0x36)
 *
 * \lhref ADUE_2947, ADUE_2952, ADUE_2953, ADUE_2956, ADUE_2948, ADUE_2954, ADUE_2955, ADUE_2963
 *
 */
Std_ReturnType StdDiag_TransferData(
    Dcm_OpStatusType OpStatus,
    Dcm_MsgContextType* pMsgContext,
    Dcm_NegativeResponseCodeType* ErrorCode
)
{
  Std_ReturnType retVal;
  uint32 reqDataLength;
  uint8 currentBlockSequenceCounter;
  uint32 uploadDataLength = 0u;
  uint32 remainingDataLength;
  uint8 minRequestLength = 1u;  /* at least block sequence counter is necessary */

  /* OpStatus currently not used */
  (void) OpStatus;

  if (STDDIAG_ADT_DOWNLOAD == StdDiag_AdtUploadDownloadProcess.currentProcess)
  {
    /* at least one data byte is necessary */
    minRequestLength += 1;
  }

  /* check minimum data length */
  if (minRequestLength > pMsgContext->reqDataLen)
  {
    *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
    return E_NOT_OK;
  }

  /* check active upload or download is in process */
  if ((StdDiag_AdtUploadDownloadProcess.currentProcess != STDDIAG_ADT_UPLOAD) &&
      (StdDiag_AdtUploadDownloadProcess.currentProcess != STDDIAG_ADT_DOWNLOAD))
  {
    *ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
    return E_NOT_OK;
  }

  currentBlockSequenceCounter = pMsgContext->reqData[0];

  /* check if block sequence counter is equal or incremented */
  if ((StdDiag_AdtUploadDownloadProcess.blockSequenceCounter != currentBlockSequenceCounter) &&
      (StdDiag_AdtUploadDownloadProcess.blockSequenceCounter != (uint8) (currentBlockSequenceCounter - 1u)))
  {
    *ErrorCode = DCM_E_WRONGBLOCKSEQUENCECOUNTER;
    return E_NOT_OK;
  }

  reqDataLength = pMsgContext->reqDataLen - 1;

  /* check if request length is conform to agreed maximum block length */
  if (StdDiag_AdtUploadDownloadProcess.dataBlockSize < reqDataLength)
  {
    *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
    return E_NOT_OK;
  }

  if (STDDIAG_ADT_DOWNLOAD == StdDiag_AdtUploadDownloadProcess.currentProcess)
  {
    /* directly call Adt client. Client is responsible to check total data size */
    retVal = StdDiag_AdtStartDownload(
          StdDiag_AdtUploadDownloadProcess.currentMemObjIdx,
          currentBlockSequenceCounter,
          reqDataLength,
          &(pMsgContext->reqData[1]),
          ErrorCode);
  }
  else
  {
    /* check transmitted data size */
    remainingDataLength = StdDiag_AdtUploadDownloadProcess.totalDataSize - StdDiag_AdtUploadDownloadProcess.currentDataSize;
    uploadDataLength = BUtil_MIN(StdDiag_AdtUploadDownloadProcess.dataBlockSize, remainingDataLength);

    if (0u == uploadDataLength)
    {
      /* all data has already been transfered */
      *ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
      retVal = E_NOT_OK;
    }
    else
    {
      /* adjust to Dcm buffer size if necessary */
      if ((pMsgContext->resMaxDataLen - 1) < uploadDataLength)
      {
        uploadDataLength = pMsgContext->resMaxDataLen - 1;
      }

      retVal = StdDiag_AdtStartUpload(
          StdDiag_AdtUploadDownloadProcess.currentMemObjIdx,
          currentBlockSequenceCounter,
          uploadDataLength,
          &(pMsgContext->resData[1]),
          ErrorCode);
    }
  }

  /* adjust status and assemble response */
  if (E_OK == retVal)
  {
    if (StdDiag_AdtUploadDownloadProcess.blockSequenceCounter != currentBlockSequenceCounter)
    {
      StdDiag_AdtUploadDownloadProcess.currentDataSize += uploadDataLength;
    }

    StdDiag_AdtUploadDownloadProcess.blockSequenceCounter = currentBlockSequenceCounter;

    /* assemble response */
    pMsgContext->resData[0] = currentBlockSequenceCounter;
    pMsgContext->resDataLen = uploadDataLength + 1u;
  }

  return retVal;
}


/**
 * \brief diagnostic service handler for UDS Service 0x37 Request Transfer Exit.
 *
 * \param[in] OpStatus State of the Dcm
 * \param[in] pMsgContext pointer to message context without SID
 * \param[out] ErrorCode Error code according to Dcm specification.
 *                       Only set in case of return value E_NOT_OK
 *
 * \retval E_OK routine control operation was successful
 * \retval E_NOT_OK routine control operation was not successful
 * \retval DCM_E_PENDING result of routine control operation is pending
 *
 * \remarks This function is called by Dcm on reception of UDS Service Request Transfer Exit (0x37)
 *
 * \lhref ADUE_2957, ADUE_2958, ADUE_2975
 *
 */
Std_ReturnType StdDiag_RequestTransferExit(
    Dcm_OpStatusType OpStatus,
    Dcm_MsgContextType* pMsgContext,
    Dcm_NegativeResponseCodeType* ErrorCode
)
{
  /* OpStatus currently not used */
  (void) OpStatus;

  if (STDDIAG_ADT_NOPROCESS == StdDiag_AdtUploadDownloadProcess.currentProcess)
  {
    *ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
    return E_NOT_OK;
  }

  /* check correct data length of 0 bytes */
  if (0u != pMsgContext->reqDataLen)
  {
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    return E_NOT_OK;
  }

  /* ignore return value, interface only allows E_OK */
  (void) StdDiag_AdtStartUpDownloadExit(StdDiag_AdtUploadDownloadProcess.currentProcess,
                                        StdDiag_AdtUploadDownloadProcess.currentMemObjIdx);

  StdDiag_AdtUploadDownloadProcess.currentProcess = STDDIAG_ADT_NOPROCESS;

  return E_OK;
}


/* PRQA S 5087 2 */
#define StdDiag_STOP_SEC_CODE
#include "StdDiag_MemMap.h"

#endif /* STDDIAG_ADT_SUPPORT */
