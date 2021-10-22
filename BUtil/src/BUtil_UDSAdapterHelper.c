/**
 * \file
 *
 * \brief       Helper functions for writing an UDS adapter.
 *
 * \project     BMW Platform Software
 *
 * \copyright   BMW AG 2016 - 2017
 *
 * \version     5.1.1
 *
 */

/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include "BUtil_UDSAdapterHelper.h"

#include <string.h>


/*------------------------------------------------------------------------------
                      Macros
-------------------------------------------------------------------------------*/

/* check version of the module */
#if (!BUtilClassic_CHECK_VERSION(5,1,1))
#error "Version of BUtil_UDSAdapterHelper.c does not match the version of the module!"
#endif


/*------------------------------------------------------------------------------
                      Global Functions
-------------------------------------------------------------------------------*/

#define BUtil_START_SEC_CODE
#include "BUtil_MemMap.h"  /* PRQA S 5087 */

Std_ReturnType BUtil_UDS_RoutineControlStart(
    BUtil_UDS_ContextType* context, BUtil_UDS_RoutineControlStartFunction* rcs, const uint8* DataIn,
    Dcm_OpStatusType OpStatus,
    uint8* DataOut,
    uint16* CurrentDataLength,
    Dcm_NegativeResponseCodeType* ErrorCode) {
  UDS_ErrorCodeType uec;
  size_t dataLength = (size_t)*CurrentDataLength;
  Std_ReturnType retVal = E_NOT_OK;
  UDS_ReturnType ret;

  switch (OpStatus) {
    case DCM_INITIAL:
      if (BUTIL_UDS_IDLE != context->state) {
        *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
        return E_NOT_OK;
      }
      context->state = BUTIL_UDS_RUNNING;
      ret = rcs(
          DataIn, dataLength, DataOut, &dataLength, &uec);

      switch (ret) {
        case UDS_DIAG_JOB_FINISHED_OK:
          context->state = BUTIL_UDS_IDLE;
          *CurrentDataLength = (uint16)dataLength;
          retVal = E_OK;
          break;
        case UDS_DIAG_JOB_FINISHED_E_NOT_OK:
          context->state = BUTIL_UDS_IDLE;
          *ErrorCode = (Dcm_NegativeResponseCodeType)uec;
          retVal = E_NOT_OK;
          break;
        case UDS_DIAG_JOB_RUNNING:
          context->sid = 0x31;
          retVal = DCM_E_PENDING;
          break;
        default:
          break;
      }
      break;
    case DCM_PENDING:
      switch (context->state)
      {
        case BUTIL_UDS_IDLE:
          *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
          retVal = E_NOT_OK;
          break;
        case BUTIL_UDS_RUNNING:
          retVal = DCM_E_PENDING;
          break;
        case BUTIL_UDS_RESULT_READY_OK:
          memcpy(DataOut, context->dataBuffer, context->dataLength);
          *CurrentDataLength = (uint16)context->dataLength;
          retVal = E_OK;
          context->state = BUTIL_UDS_IDLE;
          break;
        case BUTIL_UDS_RESULT_READY_NOT_OK:
          *ErrorCode = (Dcm_NegativeResponseCodeType)context->errorCode;
          retVal = E_NOT_OK;
          context->state = BUTIL_UDS_IDLE;
          break;
        default:
          break;
      }
      break;
    case DCM_CANCEL:
      context->state = BUTIL_UDS_IDLE;
      retVal = E_OK;
      break;
    default:
      break;
  }

  return retVal;
}

void BUtil_UDS_ResultOk(BUtil_UDS_ContextType* context, const uint8* responseData, size_t resDataLength) {
  if (BUTIL_UDS_RUNNING == context->state) {
    if (resDataLength > context->dataBufferCapacity) {
      resDataLength = context->dataBufferCapacity;
    }
    context->dataLength = resDataLength;
    (void)memcpy(context->dataBuffer, responseData, resDataLength);
    context->state = BUTIL_UDS_RESULT_READY_OK;
  }
}

void BUtil_UDS_ResultError(BUtil_UDS_ContextType* context, UDS_ErrorCodeType errorCode) {
  if (BUTIL_UDS_RUNNING == context->state) {
    context->errorCode = errorCode;
      context->state = BUTIL_UDS_RESULT_READY_NOT_OK;
  }
}

Std_ReturnType BUtil_UDS_ConditionCheckRead(
    BUtil_UDS_ContextType* context, BUtil_UDS_ReadDataFunction* rd, Dcm_OpStatusType OpStatus,
    Dcm_NegativeResponseCodeType* ErrorCode) {
  UDS_ReturnType ret;
  size_t dataLength = sizeof(context->dataBuffer);
  Std_ReturnType retVal;

  switch(OpStatus) {
    case DCM_INITIAL:
      if (BUTIL_UDS_IDLE != context->state) {
        *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
        return E_NOT_OK;
      }
      context->state = BUTIL_UDS_RUNNING;
      ret = rd(context->dataBuffer, &dataLength, &context->errorCode);
      switch (ret) {
        case UDS_DIAG_JOB_FINISHED_OK:
          context->dataLength = (uint16)dataLength;
          context->state = BUTIL_UDS_RESULT_READY_OK;
          retVal = E_OK;
          break;
        case UDS_DIAG_JOB_FINISHED_E_NOT_OK:
          *ErrorCode = (Dcm_NegativeResponseCodeType)context->errorCode;
          context->state = BUTIL_UDS_IDLE;
          retVal = E_NOT_OK;
          break;
        case UDS_DIAG_JOB_RUNNING:
          context->sid = 0x21;
          retVal = DCM_E_PENDING;
          break;
        default:
          break;
      }
      break;
    case DCM_PENDING:
      switch (context->state)
      {
        case BUTIL_UDS_IDLE:
          *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
          retVal = E_NOT_OK;
          break;
        case BUTIL_UDS_RUNNING:
          retVal = DCM_E_PENDING;
          break;
        case BUTIL_UDS_RESULT_READY_OK:
          retVal = E_OK;
          break;
        case BUTIL_UDS_RESULT_READY_NOT_OK:
          *ErrorCode = (Dcm_NegativeResponseCodeType)context->errorCode;
          retVal = E_NOT_OK;
          context->state = BUTIL_UDS_IDLE;
          break;
        default:
          break;
      }
      break;
    case DCM_CANCEL:
      context->state = BUTIL_UDS_IDLE;
      retVal = E_OK;
      break;
    default:
      break;
  }
  return retVal;
}

Std_ReturnType BUtil_UDS_ReadDataLength(
    BUtil_UDS_ContextType* context, Dcm_OpStatusType OpStatus, uint16* DataLength) {
  if ((DCM_INITIAL != OpStatus) || (BUTIL_UDS_RESULT_READY_OK != context->state)) {
    return E_NOT_OK;
  }
  *DataLength = context->dataLength;
  return E_OK;
}

Std_ReturnType BUtil_UDS_ReadData(
    BUtil_UDS_ContextType* context,
    Dcm_OpStatusType OpStatus,
    uint8* DataOut) {
  if ((DCM_INITIAL != OpStatus) || (BUTIL_UDS_RESULT_READY_OK != context->state)) {
    return E_NOT_OK;
  }
  (void)memcpy(DataOut, context->dataBuffer, context->dataLength);
  context->state = BUTIL_UDS_IDLE;
  return E_OK;
}

Std_ReturnType BUtil_UDS_WriteData(
    BUtil_UDS_ContextType* context,
    BUtil_UDS_WriteDataFunction* wd,
    const uint8* Data,
    uint16 DataLength,
    Dcm_OpStatusType OpStatus,
    Dcm_NegativeResponseCodeType* ErrorCode) {
  UDS_ReturnType ret;
  Std_ReturnType retVal = E_NOT_OK;
  UDS_ErrorCodeType uec;

  switch(OpStatus) {
    case DCM_INITIAL:
      if (BUTIL_UDS_IDLE != context->state) {
        *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
        return E_NOT_OK;
      }
      context->state = BUTIL_UDS_RUNNING;
      ret = wd(Data, (size_t)DataLength, &uec);
      switch (ret) {
        case UDS_DIAG_JOB_FINISHED_OK:
          context->state = BUTIL_UDS_IDLE;
          retVal = E_OK;
          break;
        case UDS_DIAG_JOB_FINISHED_E_NOT_OK:
          *ErrorCode = (Dcm_NegativeResponseCodeType)uec;
          context->state = BUTIL_UDS_IDLE;
          retVal = E_NOT_OK;
          break;
        case UDS_DIAG_JOB_RUNNING:
          context->sid = 0x2e;
          retVal = DCM_E_PENDING;
          break;
        default:
          break;
      }
      break;
    case DCM_PENDING:
      switch (context->state)
      {
        case BUTIL_UDS_IDLE:
          *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
          retVal = E_NOT_OK;
          break;
        case BUTIL_UDS_RUNNING:
          retVal = DCM_E_PENDING;
          break;
        case BUTIL_UDS_RESULT_READY_OK:
          retVal = E_OK;
          context->state = BUTIL_UDS_IDLE;
          break;
        case BUTIL_UDS_RESULT_READY_NOT_OK:
          *ErrorCode = (Dcm_NegativeResponseCodeType)context->errorCode;
          retVal = E_NOT_OK;
          context->state = BUTIL_UDS_IDLE;
          break;
        default:
          break;
      }
      break;
    case DCM_CANCEL:
      context->state = BUTIL_UDS_IDLE;
      retVal = E_OK;
      break;
    default:
      break;
  }
  return retVal;
}

#define BUtil_STOP_SEC_CODE
#include "BUtil_MemMap.h"  /* PRQA S 5087 */
