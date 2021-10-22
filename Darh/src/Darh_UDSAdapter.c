/**
*  \file
*
*  \brief       BMW SWC Darh UDS Adapter
*
*  This file contains the implementation of the BMW SWC Darh UDS Adapter
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2017
*
*  \version     5.1.0
*
*/
/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/
#include "Darh.h"
#include "Rte_Darh.h"
#include "Darh_UDSAdapter.h"
#include "DarhClassic_Version.h"
#include "Darh_RoutineControl.h"
#include "BUtil/PlatformTypes.h"

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/
#if (!DarhClassic_CHECK_VERSION(5, 1, 0))
#error "Version of Darh_UDSAdapter.c does not match the classic adapter version!"
#endif
/*------------------------------------------------------------------------------
                      Type declarations
------------------------------------------------------------------------------*/
typedef enum {
  DARH_STARTSTOP_IDLE,
  DARH_STARTSTOP_WATING_NVM,
  DARH_STARTSTOP_NVM_COMPLETED_OK,
  DARH_STARTSTOP_NVM_COMPLETED_NOK
} Darh_StartStopStatusType;

typedef struct {
  Darh_StartStopStatusType state;
  Dcm_NegativeResponseCodeType errorCode;
} Darh_StartStopType;
/*------------------------------------------------------------------------------
                      Local Variables
------------------------------------------------------------------------------*/
#define Darh_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Darh_MemMap.h"

static Darh_StartStopType Darh_StartStop;

#define Darh_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Darh_MemMap.h"

/*------------------------------------------------------------------------------
                      Global Functions
------------------------------------------------------------------------------*/
#define Darh_START_SEC_CODE
#include "Darh_MemMap.h"

void Darh_UDS_RoutineControlDiagnoseMaster_Start_ResultOk(void) {
  if (DARH_STARTSTOP_WATING_NVM == Darh_StartStop.state) {
    Darh_StartStop.state = DARH_STARTSTOP_NVM_COMPLETED_OK;
  }
}

void Darh_UDS_RoutineControlDiagnoseMaster_Stop_ResultOk(void) {
  if (DARH_STARTSTOP_WATING_NVM == Darh_StartStop.state) {
    Darh_StartStop.state = DARH_STARTSTOP_NVM_COMPLETED_OK;
  }
}

void Darh_UDS_RoutineControlDiagnoseMaster_Start_ResultError(UDS_ErrorCodeType errorCode) {
  if (DARH_STARTSTOP_WATING_NVM == Darh_StartStop.state) {
    Darh_StartStop.state = DARH_STARTSTOP_NVM_COMPLETED_NOK;
    Darh_StartStop.errorCode = (Dcm_NegativeResponseCodeType) errorCode;
  }
}

void Darh_UDS_RoutineControlDiagnoseMaster_Stop_ResultError(UDS_ErrorCodeType errorCode) {
  if (DARH_STARTSTOP_WATING_NVM == Darh_StartStop.state) {
    Darh_StartStop.state = DARH_STARTSTOP_NVM_COMPLETED_NOK;
    Darh_StartStop.errorCode = (Dcm_NegativeResponseCodeType) errorCode;
  }
}

/**
 * \brief Description of function Darh_StartRoutineTriggerDtcHandler
 *
 * Function is called by Diagnostic Communication Manager in the context of an
 * RC (operation start) request. The interface is used to stimulate the 2 Dummy
 * DTCs from Darh.
 *
 * \global --
 *
 * \param[in] DTCType Type of DTC/Event, that shall be triggered by this RC.
 *            0x00: ApplicationDTC
 *            0x01: NetworkDTC
 * \param[out] DTCTypeOut Copy of the input parameter DTCType
 * \param[out] DTCByte1 Byte 1 (MSB) of the DTC that has been triggered
 * \param[out] DTCByte2 Byte 2 of the DTC that has been triggered
 * \param[out] DTCByte3 Byte 3 (LSB) of the DTC that has been triggered
 * \param[out] ErrorCode ErrorCode according to the Dcm specification. Is only
 *             set in case of return value E_NOT_OK
 *
 * \return E_OK if success, E_NOT_OK if not.
 */
Std_ReturnType Darh_StartRoutineTriggerDtcHandler(
    uint8 DTCType, Dcm_OpStatusType OpStatus, uint8* DTCTypeOut, uint8* DTCByte1,
    uint8* DTCByte2, uint8* DTCByte3, Dcm_NegativeResponseCodeType* ErrorCode) {
  Std_ReturnType retVal = E_OK;

  if (DCM_INITIAL == OpStatus) {
    if ((NULL_PTR == DTCTypeOut) ||
        (NULL_PTR == DTCByte1) ||
        (NULL_PTR == DTCByte2) ||
        (NULL_PTR == DTCByte3) ||
        (NULL_PTR == ErrorCode)) {
#if(DARH_DEV_ERROR_DETECT == STD_ON)
      (void) Rte_Call_DetPort_ReportError( DARH_INSTANCE_ID, DARH_SID_STARTROUTINETRIGGERDTC, DARH_E_PARAM );
#endif
    } else if (!Darh_StartRoutineTriggerDtc(
        DTCType, DTCTypeOut, DTCByte1, DTCByte2, DTCByte3, (UDS_ErrorCodeType*) ErrorCode)) {
      retVal = RTE_E_RoutineServices_StartStopRoutineDiagnoseMaster_E_NOT_OK;
    }
  }

  return retVal;
} /* end of function Darh_StartRoutineTriggerDtcHandler */

/**
 * \brief Start Diagnose Master
 *
 * This interface is called when the UDS command to start the Diagnose Master is received.
 *
 * \param[in] OpStatus
 * \param[out] ErrorCode ErrorCode according to the Dcm specification. Is only
 *             set in case of return value E_NOT_OK
 *
 * \return E_OK if success, E_NOT_OK if not, E_PENDING if the process has not been completed.
 */
Std_ReturnType
Darh_StartRoutineDiagnoseMasterHandler(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType* ErrorCode) {
  Std_ReturnType retVal = RTE_E_RoutineServices_StartStopRoutineDiagnoseMaster_DCM_E_PENDING;
  UDS_ErrorCodeType UDS_ErrorCode;

  switch (OpStatus) {
    case DCM_INITIAL:
      Darh_StartStop.state = DARH_STARTSTOP_WATING_NVM;
      if (!Darh_StartRoutineDiagnoseMaster(&UDS_ErrorCode)) {
        *ErrorCode = (Dcm_NegativeResponseCodeType)UDS_ErrorCode;
        retVal = RTE_E_RoutineServices_StartStopRoutineDiagnoseMaster_E_NOT_OK;
      }
      break;

    case DCM_PENDING:
      if ((DARH_STARTSTOP_NVM_COMPLETED_OK == Darh_StartStop.state) ||
          (DARH_STARTSTOP_NVM_COMPLETED_NOK == Darh_StartStop.state)) {

        if (DARH_STARTSTOP_NVM_COMPLETED_NOK == Darh_StartStop.state) {
          retVal = RTE_E_RoutineServices_StartStopRoutineDiagnoseMaster_E_NOT_OK;
          *ErrorCode = Darh_StartStop.errorCode;
        } else {
          retVal = RTE_E_OK;
        }

        Darh_StartStop.state = DARH_STARTSTOP_IDLE;
      }
      break;

    default:
      retVal = E_OK;
      break;
  }

  return retVal;
} /* end of function Darh_StartRoutineDiagnoseMasterHandler */

Std_ReturnType
Darh_StopRoutineDiagnoseMasterHandler(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType* ErrorCode) {
  Std_ReturnType retVal = RTE_E_RoutineServices_StartStopRoutineDiagnoseMaster_DCM_E_PENDING;
  UDS_ErrorCodeType UDS_ErrorCode;

  switch (OpStatus) {
    case DCM_INITIAL:
      Darh_StartStop.state = DARH_STARTSTOP_WATING_NVM;
      if (!Darh_StopRoutineDiagnoseMaster(&UDS_ErrorCode)) {
        *ErrorCode = (Dcm_NegativeResponseCodeType)UDS_ErrorCode;
        retVal = RTE_E_RoutineServices_StartStopRoutineDiagnoseMaster_E_NOT_OK;
      }
      break;

    case DCM_PENDING:
      if ((DARH_STARTSTOP_NVM_COMPLETED_OK == Darh_StartStop.state) ||
          (DARH_STARTSTOP_NVM_COMPLETED_NOK == Darh_StartStop.state)) {

        if (DARH_STARTSTOP_NVM_COMPLETED_NOK == Darh_StartStop.state) {
          retVal = RTE_E_RoutineServices_StartStopRoutineDiagnoseMaster_E_NOT_OK;
          *ErrorCode = Darh_StartStop.errorCode;
        } else {
          retVal = RTE_E_OK;
        }

        Darh_StartStop.state = DARH_STARTSTOP_IDLE;
      }
      break;

    default:
      retVal = E_OK;
      break;
  }

  return retVal;
} /* end of function Darh_StopRoutineDiagnoseMasterHandler */

#define Darh_STOP_SEC_CODE
#include "Darh_MemMap.h"
