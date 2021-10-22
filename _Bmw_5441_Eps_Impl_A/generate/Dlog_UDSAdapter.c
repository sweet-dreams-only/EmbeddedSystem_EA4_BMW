/**
 * \file
 *
 * \brief       SVK Backup access functions.
 *
 * \project     BMW Platform Software
 *
 * \copyright   BMW AG 2015 - 2017
 *
 * \version     5.3.1
 *
 */

/*------------------------------------------------------------------------------
*
*  THIS FILE WAS GENERATED. DO NOT MODIFY!
*
*  GENERATOR       : BMW PAGe 1.1.0
*
*  GENERATION TIME : 2018-07-30 19:57:40.733161
*
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/

#include "Dlog_UDSAdapter.h"
#include "Dlog_UDSAdapterAdd.h"
#include "Dlog_SvkGen.h"
#include "Dlog_SweGen.h"
#include "Rte_Dlog.h"
#include "BUtil_UDSAdapterHelper.h"

/*------------------------------------------------------------------------------
                      MISRA-Deviations
------------------------------------------------------------------------------*/

/* Violation of MISRA rule 19.1, Reason: Including Dlog_MemMap.h is necessary throughout
   the file according to memory abstraction, see PRQA: 5087 */

/* Violation of MISRA Rule 14.2: Reason: void cast for unused parameter */


/*------------------------------------------------------------------------------
                      Macros
-------------------------------------------------------------------------------*/

/* check version of the module */
#if (!DlogClassic_CHECK_VERSION(5,3,1))
   #error "Version of Dlog_SvkBackup.c does not match the version of the module!"
#endif


BUTIL_DEFINE_UDS_CONTEXT(Dlog_UDSAdapterContext, 256)


/*------------------------------------------------------------------------------
                      Global Functions
-------------------------------------------------------------------------------*/

#define Dlog_START_SEC_CODE
#include "Dlog_MemMap.h"  /* PRQA S 5087 */


Std_ReturnType Dlog_ConditionCheckSvkCurrent(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType* ErrorCode) {
  return BUtil_UDS_ConditionCheckRead(&Dlog_UDSAdapterContext, &Dlog_ReadDataSvkCurrent, OpStatus, ErrorCode);
}

Std_ReturnType Dlog_ReadDataLengthSvkCurrent(Dcm_OpStatusType OpStatus, uint16* DataLength) {
  return BUtil_UDS_ReadDataLength(&Dlog_UDSAdapterContext, OpStatus, DataLength);
}

Std_ReturnType Dlog_ReadDataByIdentifierSvkCurrent(Dcm_OpStatusType OpStatus, uint8* DataOut) {
  return BUtil_UDS_ReadData(&Dlog_UDSAdapterContext, OpStatus, DataOut);
}

void Dlog_UDS_ReadDataSvkCurrent_ResultOk(const uint8* responseData, size_t resDataLength) {
  BUtil_UDS_ResultOk(&Dlog_UDSAdapterContext, responseData, resDataLength);
}

void Dlog_UDS_ReadDataSvkCurrent_ResultError(UDS_ErrorCodeType errorCode) {
  BUtil_UDS_ResultError(&Dlog_UDSAdapterContext, errorCode);
}

#if DLOG_ENABLE_SVK_HISTORY == STD_ON

static UDS_ReturnType Dlog_UDSReadDataSvkSysSupplier(uint8* responseData, size_t* dataLength, UDS_ErrorCodeType* errorCode) {
  return Dlog_ReadDataSvkHistory(0, responseData, dataLength, errorCode);
}

Std_ReturnType Dlog_ConditionCheckSvkSysSupplier(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType* ErrorCode) {
  return BUtil_UDS_ConditionCheckRead(&Dlog_UDSAdapterContext, &Dlog_UDSReadDataSvkSysSupplier, OpStatus, ErrorCode);
}

#if (DLOG_ENABLE_MULTI_CPU == STD_ON) || (DLOG_CHECK_FOR_OPTIONAL_SWFK == STD_ON)
Std_ReturnType Dlog_ReadDataLengthSvkSysSupplier(
         Dcm_OpStatusType OpStatus,
         uint16* DataLength
      ) {
   return BUtil_UDS_ReadDataLength(&Dlog_UDSAdapterContext, OpStatus, DataLength);
 }
#endif

Std_ReturnType Dlog_ReadDataByIdentifierSvkSysSupplier(Dcm_OpStatusType OpStatus, uint8* Data) {
  return BUtil_UDS_ReadData(&Dlog_UDSAdapterContext, OpStatus, Data);
}


static UDS_ReturnType Dlog_UDSReadDataSvkPlant(uint8* responseData, size_t* dataLength, UDS_ErrorCodeType* errorCode) {
  return Dlog_ReadDataSvkHistory(1, responseData, dataLength, errorCode);
}

Std_ReturnType Dlog_ConditionCheckSvkPlant(
        Dcm_OpStatusType OpStatus,
        Dcm_NegativeResponseCodeType* ErrorCode) {
  return BUtil_UDS_ConditionCheckRead(&Dlog_UDSAdapterContext, &Dlog_UDSReadDataSvkPlant, OpStatus, ErrorCode);
}

#if (DLOG_ENABLE_MULTI_CPU == STD_ON) || (DLOG_CHECK_FOR_OPTIONAL_SWFK == STD_ON)
Std_ReturnType Dlog_ReadDataLengthSvkPlant(
         Dcm_OpStatusType OpStatus,
         uint16* DataLength
      ) {
   return BUtil_UDS_ReadDataLength(&Dlog_UDSAdapterContext, OpStatus, DataLength);
 }
#endif

Std_ReturnType Dlog_ReadDataByIdentifierSvkPlant(Dcm_OpStatusType OpStatus, uint8* Data) {
  return BUtil_UDS_ReadData(&Dlog_UDSAdapterContext, OpStatus, Data);
}


void Dlog_UDS_ReadDataSvkHistory_ResultOk(const uint8* responseData, size_t resDataLength) {
  BUtil_UDS_ResultOk(&Dlog_UDSAdapterContext, responseData, resDataLength);
}

void Dlog_UDS_ReadDataSvkHistory_ResultError(UDS_ErrorCodeType errorCode) {
  BUtil_UDS_ResultError(&Dlog_UDSAdapterContext, errorCode);
}

#endif /* #if DLOG_ENABLE_SVK_HISTORY == STD_ON */

Std_ReturnType Dlog_RoutineControlStartReadDevelopmentInfoField
    (
        const uint8* DataIn,
        Dcm_OpStatusType OpStatus,
        uint8* DataOut,
        uint16* CurrentDataLength,
        Dcm_NegativeResponseCodeType* ErrorCode
    )
{
  return BUtil_UDS_RoutineControlStart(&Dlog_UDSAdapterContext, &Dlog_RoutineControlReadDevelopmentInfoFieldStart, DataIn, OpStatus, DataOut, CurrentDataLength, ErrorCode);
}

void Dlog_UDS_RoutineControlReadDevelopmentInfo_ResultOk(const uint8* responseData, size_t resDataLength) {
  BUtil_UDS_ResultOk(&Dlog_UDSAdapterContext, responseData, resDataLength);
}

void Dlog_UDS_RoutineControlReadDevelopmentInfo_ResultError(UDS_ErrorCodeType errorCode) {
  BUtil_UDS_ResultError(&Dlog_UDSAdapterContext, errorCode);
}


#define Dlog_STOP_SEC_CODE
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

