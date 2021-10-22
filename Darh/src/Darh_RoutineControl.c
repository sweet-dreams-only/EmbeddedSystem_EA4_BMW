/**
*  \file
*
*  \brief       BMW SWC Darh Routine Control Job
*
*  This file contains the implementation Routine Control Job to stimulate the
*  Darh Dummy DTCs
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015
*
*  \version     5.1.0
*
*  \remarks     --
*
*/
/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/
#include "Darh_RoutineControl.h"
#include "BUtil/PlatformTypes.h"
#include "Darh.h"
#include "Darh_NvMAdapter.h"
#include "Darh_UDSAdapter.h"
#include <stddef.h>

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/
#if (!Darh_CHECK_VERSION(5, 1, 0))
#error "Version of Darh_RoutineControl.c does not match the version of the module!"
#endif

#define DARH_APPLICATION_DTC_TYPE         0x00U /** <= Application DTC type */
#define DARH_NETWORK_DTC_TYPE             0x01U /** <= Network DTC type */

/*------------------------------------------------------------------------------
                      Local Functions Declarations
------------------------------------------------------------------------------*/
static void Darh_DiagnoseMasterStatusStartCallback(NvMService_ResultType result, void* context);

static void Darh_DiagnoseMasterStatusStopCallback(NvMService_ResultType result, void* context);

/*------------------------------------------------------------------------------
                      Local Functions
------------------------------------------------------------------------------*/
static void Darh_DiagnoseMasterStatusStartCallback(NvMService_ResultType result, void* context) {
  (void)context;
  if (NVMSERVICE_OK == result) {
    Darh_UDS_RoutineControlDiagnoseMaster_Start_ResultOk();
  } else {
    Darh_UDS_RoutineControlDiagnoseMaster_Start_ResultError(UDS_DIAG_E_GENERALPROGRAMMINGFAILURE);
  }
}

static void Darh_DiagnoseMasterStatusStopCallback(NvMService_ResultType result, void* context) {
  (void)context;
  if (NVMSERVICE_OK == result) {
    Darh_UDS_RoutineControlDiagnoseMaster_Stop_ResultOk();
  } else {
    Darh_UDS_RoutineControlDiagnoseMaster_Stop_ResultError(UDS_DIAG_E_GENERALPROGRAMMINGFAILURE);
  }
}

/*------------------------------------------------------------------------------
                      Global Functions
------------------------------------------------------------------------------*/
#define Darh_START_SEC_CODE
#include "Darh_MemMap.h"

extern boolean Darh_StartRoutineTriggerDtc(
    uint8 DTCType, uint8* DTCTypeOut,
    uint8* DTCByte1, uint8* DTCByte2, uint8* DTCByte3,
    UDS_ErrorCodeType* ErrorCode) {
  boolean retVal = TRUE;

  if (Darh_State.running) {
    ErrMemService_UDSDTCType DTCOfEvent;

    /* check fi the DTCType is on range */
    if ((DARH_APPLICATION_DTC_TYPE == DTCType) || (DARH_NETWORK_DTC_TYPE == DTCType)) {

      /* stimulate the corresponding DTC */
      if (DARH_APPLICATION_DTC_TYPE == DTCType) {
        Darh_ErrorManager_ApplDtc_SetEventStatus(ERRMEMSERVICE_STATUS_FAILED);
        Darh_ErrorManager_ApplDtc_SetEventStatus(ERRMEMSERVICE_STATUS_PASSED);
      } else {
        Darh_ErrorManager_NetDtc_SetEventStatus(ERRMEMSERVICE_STATUS_FAILED);
        Darh_ErrorManager_NetDtc_SetEventStatus(ERRMEMSERVICE_STATUS_PASSED);
      }

      /* Get the value of the UDS DTC to write the answer */
      if (DARH_APPLICATION_DTC_TYPE == DTCType) {
        DTCOfEvent = Darh_ErrorManager_ApplDtc_GetDTCOfEvent();
      } else {
        DTCOfEvent = Darh_ErrorManager_NetDtc_GetDTCOfEvent();
      }

      /* the response shall contain the UDSDTCValue and DTCType */
      *DTCByte1 = (uint8) (DTCOfEvent >> 16U);
      *DTCByte2 = (uint8) (DTCOfEvent >> 8U);
      *DTCByte3 = (uint8) DTCOfEvent;
      *DTCTypeOut = DTCType;
    } else {
      /* DTCType is not in range, report RequestOutOfRange error */
      *ErrorCode = UDS_DIAG_E_REQUESTOUTOFRANGE;
      retVal = FALSE;
    }

  } else {
    /* Darh Module is not running */
    *ErrorCode = UDS_DIAG_E_CONDITIONSNOTCORRECT;
    retVal = FALSE;
  }

  return retVal;
} /* end of function Darh_StartRoutineTriggerDtc */

extern boolean Darh_StartRoutineDiagnoseMaster(UDS_ErrorCodeType* ErrorCode) {
  boolean retVal = TRUE;

  if (Darh_State.running) {
    /** \lhref DMA_PA_9157 */
    Darh_DiagnoseMasterEnable = TRUE;

    Darh_NvM_WriteDiagnoseMasterStatus(&Darh_DiagnoseMasterEnable, Darh_DiagnoseMasterStatusStartCallback, NULL);
  } else {
    /* Darh Module is not running */
    *ErrorCode = UDS_DIAG_E_CONDITIONSNOTCORRECT;
    retVal = FALSE;
  }

  return retVal;
}

extern boolean Darh_StopRoutineDiagnoseMaster(UDS_ErrorCodeType* ErrorCode) {
  boolean retVal = TRUE;

  if (Darh_State.running) {
    /** \lhref DMA_PA_9157 */
    Darh_DiagnoseMasterEnable = FALSE;

    Darh_NvM_WriteDiagnoseMasterStatus(&Darh_DiagnoseMasterEnable, Darh_DiagnoseMasterStatusStopCallback, NULL);
  } else {
    /* Darh Module is not running */
    *ErrorCode = UDS_DIAG_E_CONDITIONSNOTCORRECT;
    retVal = FALSE;
  }

  return retVal;
}

#define Darh_STOP_SEC_CODE
#include "Darh_MemMap.h"
