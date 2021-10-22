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

#ifndef BPS_BUTIL_UDSADAPTERHELPER_H
#define BPS_BUTIL_UDSADAPTERHELPER_H

/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include "BUtilClassic_Version.h"
#include "BUtil/PlatformTypes.h"
#include "BUtil/GenericUDSTypes.h"

#if !(defined(RTE_APPLICATION_HEADER_FILE) || defined(RTE_APPLICATION_HEADER_FILE_H))
#include "Dcm_Types.h"
#endif

#include <stddef.h>


/*------------------------------------------------------------------------------
                      Macros
-------------------------------------------------------------------------------*/

/* check version of the module */
#if (!BUtilClassic_CHECK_VERSION(5,1,1))
#error "Version of BUtil_UDSAdapterHelper.h does not match the version of the module!"
#endif


/**
 * Defines the UDS context variable.
 *
 * \param[in] name     name of the context variable
 * \param[in] capacity capacity of the corresponding buffer for asynchronous calls
 */
#define BUTIL_DEFINE_UDS_CONTEXT(name, capacity) \
uint8 name##Buffer[capacity]; \
BUtil_UDS_ContextType name = {name##Buffer, capacity, BUTIL_UDS_IDLE, 0, 0, 0, 0};


/*------------------------------------------------------------------------------
                      Data Types
-------------------------------------------------------------------------------*/

typedef struct {
  uint8* const dataBuffer;
  size_t const dataBufferCapacity;
  enum {
    BUTIL_UDS_IDLE,
    BUTIL_UDS_RUNNING,
    BUTIL_UDS_RESULT_READY_OK,
    BUTIL_UDS_RESULT_READY_NOT_OK
  } state;
  uint8 sid;
  uint16 id;
  UDS_ErrorCodeType errorCode;
  uint16 dataLength;
} BUtil_UDS_ContextType;

/**
 * Generic Routine Control Function Type
 */
typedef UDS_ReturnType (BUtil_UDS_RoutineControlStartFunction)(const uint8* requestData, size_t reqDataLength, uint8* responseData, size_t *resDataLength, UDS_ErrorCodeType* errorCode);

/**
 * Generic Read Data Function Type
 */
typedef UDS_ReturnType (BUtil_UDS_ReadDataFunction)(uint8* responseData, size_t* dataLength, UDS_ErrorCodeType* errorCode);

/**
 * Generic Write Data Function Type
 */
typedef UDS_ReturnType (BUtil_UDS_WriteDataFunction)(const uint8* requestData, size_t dataLength, UDS_ErrorCodeType* errorCode);


/*------------------------------------------------------------------------------
                      Global Function Declarations
-------------------------------------------------------------------------------*/

#define BUtil_START_SEC_CODE
#include "BUtil_MemMap.h"  /* PRQA S 5087 */

/**
 * Routine Control Start function. The Adapter should pass the DCM call directly to this function.
 *
 * \param context            the context to work on
 * \param rcs                the generic Routine Control Start function
 * \param DataIn             input payload from DCM
 * \param OpStatus           OpStatus from DCM
 * \param DataOut            output payload for DCM
 * \param CurrentDataLength  currentDataLength from/for DCM
 * \param ErrorCode          negative response code for DCM
 * \return                   return value for DCM
 */
extern Std_ReturnType BUtil_UDS_RoutineControlStart(
    BUtil_UDS_ContextType* context, BUtil_UDS_RoutineControlStartFunction* rcs, const uint8* DataIn,
    Dcm_OpStatusType OpStatus,
    uint8* DataOut,
    uint16* CurrentDataLength,
    Dcm_NegativeResponseCodeType* ErrorCode);

/**
 * Callback function for asynchronous UDS jobs.
 *
 * \param context            the context to work on
 * \param responseData       output payload for DCM
 * \param resDataLength      data length for DCM
 */
extern void BUtil_UDS_ResultOk(BUtil_UDS_ContextType* context, const uint8* responseData, size_t resDataLength);

/**
 * Callback function for asynchronous UDS jobs.
 *
 * \param context            the context to work on
 * \param errorCode          negative response code for DCM
 */
extern void BUtil_UDS_ResultError(BUtil_UDS_ContextType* context, UDS_ErrorCodeType errorCode);

/**
 * Condition Check Read function for read DID jobs. The Adapter should pass the DCM call directly to this function.
 *
 * \param context            the context to work on
 * \param rd                 the generic Read Data function
 * \param OpStatus           OpStatus from DCM
 * \param ErrorCode          negative response code for DCM
 * \return                   return value for DCM
 */
extern Std_ReturnType BUtil_UDS_ConditionCheckRead(
    BUtil_UDS_ContextType* context, BUtil_UDS_ReadDataFunction* rd, Dcm_OpStatusType OpStatus,
    Dcm_NegativeResponseCodeType* ErrorCode);

/**
 * Read Data Length function for variable size read DID jobs. The Adapter should pass the DCM call directly to this
 * function.
 *
 * \param context            the context to work on
 * \param OpStatus           OpStatus from DCM
 * \param DataLength         data length for DCM
 * \return                   return value for DCM
 */
extern Std_ReturnType BUtil_UDS_ReadDataLength(
    BUtil_UDS_ContextType* context, Dcm_OpStatusType OpStatus, uint16* DataLength);

/**
 * Read Data function for read DID jobs. The Adapter should pass the DCM call directly to this function.
 *
 * \param context            the context to work on
 * \param OpStatus           OpStatus from DCM
 * \param DataOut            output payload for DCM
 * \return                   return value for DCM
 */
extern Std_ReturnType BUtil_UDS_ReadData(
    BUtil_UDS_ContextType* context,
    Dcm_OpStatusType OpStatus,
    uint8* DataOut);

/**
 * Write Data function for write DID jobs. The Adapter should pass the DCM call directly to this function.
 *
 * \param context            the context to work on
 * \param wd                 the generic Write Data function
 * \param Data               input payload from DCM
 * \param DataLength         DataLength from DCM
 * \param OpStatus           OpStatus from DCM
 * \param ErrorCode          negative response code for DCM
 * \return                   return value for DCM
 */
extern Std_ReturnType BUtil_UDS_WriteData(
    BUtil_UDS_ContextType* context,
    BUtil_UDS_WriteDataFunction* wd,
    const uint8* Data,
    uint16 DataLength,
    Dcm_OpStatusType OpStatus,
    Dcm_NegativeResponseCodeType* ErrorCode);

#define BUtil_STOP_SEC_CODE
#include "BUtil_MemMap.h"  /* PRQA S 5087 */

#endif /* BPS_BUTIL_UDSADAPTERHELPER_H */
