/**
*  \file
*
*  \brief       Omc UDS Diagnostic Adapter
*
*  This file contains the Omc UDS diagnostic functionality.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     5.2.0
*
*/
/*------------------------------------------------------------------------------
                      MISRA-Deviations
------------------------------------------------------------------------------*/
/*
   MISRA-C:2004 Rule 19.1: including Omc_MemMap.h is necessary throughout
   the file according to memory abstraction. See PRQA 5087.
*/

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/
#include "OmcClassic_Version.h"
#include "Omc_UDSAdapter.h"
#include "Omc_Assert.h"
#include "Rte_Omc.h"
#include "Omc.h"

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/
/**
 * \brief check version of the module
 */
#if (!OmcClassic_CHECK_VERSION(5, 2, 0))
#error "Version of Omc_UdsAdapter.c does not match the version of the module!"
#endif


/*------------------------------------------------------------------------------
                      Global Variables
------------------------------------------------------------------------------*/
#define Omc_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Omc_MemMap.h" /* PRQA S 5087 */

static UDS_ReturnType UDS_Result;
static UDS_ErrorCodeType UDS_ErrorCode;

#define Omc_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Omc_MemMap.h" /* PRQA S 5087 */

/*------------------------------------------------------------------------------
                      Local Functions Prototypes
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Local Functions
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Global Functions
------------------------------------------------------------------------------*/

#define Omc_START_SEC_CODE
#include "Omc_MemMap.h" /* PRQA S 5087 */

/*----------------------------------------------------------------------------*/
/**
 * Function is called in the context of a diagnostic request to set the new
 * Operating Mode. This API fulfills the API that the Dcm expects when
 * connected to the OMC SWC for its require Port of Type ClientServerInterface
 * RoutineServices_<RoutineName>.
 *
 * \global_r        none
 * \global_w        none
 * \global_rw       UDS_Result, UDS_ErrorCode
 *
 * \param[in]       OperatingMode New Operating Mode that shall be activated
 * \param[in]       OpStatus See Dcm_OpStatusType in \cite SWS-DiagnosticCommunicationManager.
 * \param[out]      ErrorCode Negative Response Code according to definition.
                    Shall only be set when return type equals E_NOT_OK.
                    Possible values: DCM_E_GENERALPROGRAMMINGFAILURE.
 *
 * \retval          E_OK: changing Operating Mode was successful
 * \retval          E_NOT_OK: changing Operating Mode was not successful or current
                    LifeCycle is not OMC_RUNNING
 * \retval          E_PENDING: new Operating Mode not yet persistently stored.
 *
 * \pre             none
 *
 * \post            none
 *
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Omc_RoutineControlStartOperatingMode(
    uint8 OperatingMode, OpStatusType OpStatus, Dcm_NegativeResponseCodeType* ErrorCode) {
  Std_ReturnType result = RTE_E_OK;

  /* If currentMode is OMC_RUNNING and input parameters are valid, process operation */
  switch (OpStatus) {
    case DCM_INITIAL: /* Initial call to the operation */
    {
      UDS_Result = Omc_RoutineControlOperatingMode_Start(OperatingMode, &UDS_ErrorCode);
      switch (UDS_Result) {
        case UDS_DIAG_JOB_RUNNING: {
          result = RTE_E_RoutineServices_OperatingModeControl_DCM_E_PENDING;
          break;
        }
        case UDS_DIAG_JOB_FINISHED_OK: {
          result = RTE_E_OK;
          break;
        }
        case UDS_DIAG_JOB_FINISHED_E_NOT_OK: {
          *ErrorCode = UDS_ErrorCode;
          result = RTE_E_RoutineServices_OperatingModeControl_E_NOT_OK;
          break;
        }
        default: {
          result = RTE_E_RoutineServices_OperatingModeControl_E_NOT_OK;
          *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
          break;
        }
      }
      break;
    }
    case DCM_PENDING: /* Continuation of a previously initiated call to the operation */
    {
      switch (UDS_Result) {
        case UDS_DIAG_JOB_RUNNING: {
          result = RTE_E_RoutineServices_OperatingModeControl_DCM_E_PENDING;
          break;
        }
        case UDS_DIAG_JOB_FINISHED_OK: {
          result = RTE_E_OK;
          break;
        }
        case UDS_DIAG_JOB_FINISHED_E_NOT_OK: {
          *ErrorCode = UDS_ErrorCode;
          result = RTE_E_RoutineServices_OperatingModeControl_E_NOT_OK;
          break;
        }
        default: {
          result = RTE_E_RoutineServices_OperatingModeControl_E_NOT_OK;
          *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
          break;
        }
      }
      break;
    }

    case DCM_CANCEL:
    default: /* other value than (INITIAL, PENDING, CANCEL) is in theory not possible */
      /* nothing to do, if a cancel occurs and the job is already running we can not stop it */
      break;
  }
  return result;
}

void Omc_UDS_RoutineControlOperatingMode_Start_ResultOk(void) {
  UDS_Result = UDS_DIAG_JOB_FINISHED_OK;
}

void Omc_UDS_RoutineControlOperatingMode_Start_ResultError(UDS_ErrorCodeType errorCode) {
  UDS_Result = UDS_DIAG_JOB_FINISHED_E_NOT_OK;
  UDS_ErrorCode = errorCode;
}

/*----------------------------------------------------------------------------*/
/**
 * Function is called via diagnosis to set the new Extended Operating Mode.
 * This API fulfills the API that the Dcm expects when connected to the OMC SWC
 * for its require Port of Type ClientServerInterface
 * RoutineServices_<RoutineName>.
 *
 * \global_r        none
 * \global_w        none
 * \global_rw       UDS_Result, UDS_ErrorCode
 *
 * \param[in]       ExtendedOperatingMode New Extended Operating Mode that shall be activated
 * \param[in]       OpStatus See Dcm_OpStatusType in \cite SWS-DiagnosticCommunicationManager.
 * \param[out]      ErrorCode Negative Response Code according to definition.
 *
 * \retval          E_OK: changing Extended Operating Mode was successful
 * \retval          E_NOT_OK: changing Extended Operating Mode was not successful or
                    current LifeCycle is not OMC_RUNNING
 * \retval          E_PENDING: new Extended Operating Mode not yet persistently stored.
 *
 * \pre             none
 *
 * \post            none
 *
 * \swsid SWS_Omc_0050
 *
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Omc_RoutineControlStartExtendedOperatingMode(
    uint8 ExtendedOperatingMode, OpStatusType OpStatus, Dcm_NegativeResponseCodeType* ErrorCode) {
  Std_ReturnType result = RTE_E_OK;

  switch (OpStatus) {
    case DCM_INITIAL: /* Initial call to the operation */
    {
      UDS_Result = Omc_RoutineControlExtendedOperatingMode_Start(ExtendedOperatingMode, &UDS_ErrorCode);
      switch (UDS_Result) {
        case UDS_DIAG_JOB_RUNNING: {
          result = RTE_E_RoutineServices_ExtendedOperatingModeControl_DCM_E_PENDING;
          break;
        }
        case UDS_DIAG_JOB_FINISHED_OK: {
          result = RTE_E_OK;
          break;
        }
        case UDS_DIAG_JOB_FINISHED_E_NOT_OK: {
          *ErrorCode = UDS_ErrorCode;
          result = RTE_E_RoutineServices_ExtendedOperatingModeControl_E_NOT_OK;
          break;
        }
        default: {
          result = RTE_E_RoutineServices_ExtendedOperatingModeControl_E_NOT_OK;
          *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
          break;
        }
      }
      break;
    }
    case DCM_PENDING: /* Continuation of a previously initiated call to the operation */
    {
      switch (UDS_Result) {
        case UDS_DIAG_JOB_RUNNING: {
          result = RTE_E_RoutineServices_ExtendedOperatingModeControl_DCM_E_PENDING;
          break;
        }
        case UDS_DIAG_JOB_FINISHED_OK: {
          result = RTE_E_OK;
          break;
        }
        case UDS_DIAG_JOB_FINISHED_E_NOT_OK: {
          *ErrorCode = UDS_ErrorCode;
          result = RTE_E_RoutineServices_ExtendedOperatingModeControl_E_NOT_OK;
          break;
        }
        default: {
          result = RTE_E_RoutineServices_ExtendedOperatingModeControl_E_NOT_OK;
          *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
          break;
        }
      }
      break;
    }

    case DCM_CANCEL:
    default: /* other value than (INITIAL, PENDING, CANCEL) is in theory not possible */
      /* nothing to do, if a cancel occurs and the job is already running we can not stop it */
      break;
  }

  return result;
}

void Omc_UDS_RoutineControlExtendedOperatingMode_Start_ResultOk(void) {
  UDS_Result = UDS_DIAG_JOB_FINISHED_OK;
}

void Omc_UDS_RoutineControlExtendedOperatingMode_Start_ResultError(UDS_ErrorCodeType errorCode) {
  UDS_Result = UDS_DIAG_JOB_FINISHED_E_NOT_OK;
  UDS_ErrorCode = errorCode;
}

/*----------------------------------------------------------------------------*/
/**
 * This API fulfills the API of mandatory operation ConditionCheckRead(), that
 * the Dcm expects when connected to the OMC SWC for its require Port of Type
 * ClientServerInterface DataServices_<Data>
 *
 * \global_r        none
 * \global_w        none
 * \global_rw       none
 *
 * \param[out]      ErrorCode Negative Response Code according to definition in [1].
                    In case LifeCycle is not OMC_RUNNING DCM_E_CONDITIONSNOTCORRECT shall be returned
 *
 * \retval          E_OK: current LifeCycle is OMC_RUNNING
 * \retval          E_NOT_OK: current LifeCycle is not OMC_RUNNING.
 *
 * \pre             none
 *
 * \post            none
 *
 * \remarks         none
 *
 * \swsid SWS_Omc_0084
 *
 * In case a NULL-pointer is given as parameter errorCode, a development error (if activated) is entered according to \swsref{SWS_Omc OMC_0087} and the setting of the errorCode parameter is discarded.
 * \swsid SWS_Omc_0095
 *
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Omc_ConditionCheckReadDIDOperatingMode(Dcm_NegativeResponseCodeType* ErrorCode) {
  Std_ReturnType result = RTE_E_OK;
  UDS_ErrorCodeType tmpErrorCode;
  Omc_GenericOperatingModeType tmpData;

  /* Check for Development errors */
  Omc_Assert_DevAssertReturn(NULL_PTR != ErrorCode, OMC_DEVERROR_CONDCHECKOPERATINGMODE_EPARAM, RTE_E_OK);

  /* Check that Omc_Init has been called */
  if (UDS_DIAG_JOB_FINISHED_OK != Omc_ReadDataOperatingMode(&tmpData, &tmpErrorCode)) {
    result = RTE_E_DataServices_OperatingMode_E_NOT_OK;
    *ErrorCode = tmpErrorCode;
  }

  return result;
}

/*----------------------------------------------------------------------------*/
/**
 * Function returns the current OperatingMode for a ReadDataByIdentifier
 * Request. This API fulfills the API that the Dcm expects when connected to
 * the OMC SWC for its require Port of Type ClientServerInterface
 * DataServices_<Data>.
 *
 * \global_r        none
 * \global_w        none
 * \global_rw       none
 *
 * \param[out]      Data  DID data (current Operating Mode)
 *
 * \retval          E_OK
 *
 * \pre             none
 *
 * \post            none
 *
 * \remarks         The Dcm-API demands an E_OK return value from service
 *                  implementer in any case. E_NOT_OK error code shall only
 *                  be returned by the RTE itself (for example when the
 *                  partition, the implementing runnable entity runs in, is
 *                  stopped)
 *
 * \swsid SWS_Omc_0035
 *
 * In case a NULL-pointer is given as parameter data, a development error (if activated) is entered according to \swsref{SWS_Omc_0087}, the out parameter is not set and E_OK is returned.
 * \swsid SWS_Omc_0093
 *
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Omc_ReadDIDOperatingMode(uint8* Data) {
  UDS_ErrorCodeType tmpErrorCode;
  Omc_GenericOperatingModeType tmpData;

  /* Check for Development errors */
  Omc_Assert_DevAssertReturn(NULL_PTR != Data, OMC_DEVERROR_READDIDOPERATINGMODE_EPARAM, RTE_E_OK);

  (void) Omc_ReadDataOperatingMode(&tmpData, &tmpErrorCode);
  *Data = tmpData;

  return RTE_E_OK;
}

/*----------------------------------------------------------------------------*/
/**
 * This API fulfills the API of mandatory operation ConditionCheckRead(), that
 * the Dcm expects when connected to the OMC SWC for its require Port of Type
 * ClientServerInterface DataServices_<Data>.
 *
 * \global_r        none
 * \global_w        none
 * \global_rw       none
 *
 * \param[out]      ErrorCode Negative Response Code according to definition in [1].
 *                  In case LifeCycle is not OMC_RUNNING DCM_E_CONDITIONSNOTCORRECT shall be returned.
 *
 * \retval          E_OK: current LifeCycle is OMC_RUNNING
 * \retval          E_NOT_OK: current LifeCycle is not OMC_RUNNING.
 *
 * \pre             none
 *
 * \post            none
 *
 * \remarks         none
 *
 * \swsid SWS_Omc_0085
 *
 * In case the a NULL-pointer is given as parameter errorCode, a development
 * error (if activated) is entered according to \swsref{SWS_Omc_0087} and the
 * setting of the errorCode parameter is discarded.
 * \swsid SWS_Omc_0094
 *
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Omc_ConditionCheckReadDIDExtendedOperatingMode(Dcm_NegativeResponseCodeType* ErrorCode) {
  Std_ReturnType result = RTE_E_OK;
  UDS_ErrorCodeType tmpErrorCode;
  Omc_GenericExtendedOperatingModeType tmpData;

  /* Check for Development errors */
  Omc_Assert_DevAssertReturn(NULL_PTR != ErrorCode, OMC_DEVERROR_CONDCHECKEXTOPERATINGMODE_EPARAM, RTE_E_OK);

  /* Check that that LifeCycle is set to OMC_RUNNING */
  if (UDS_DIAG_JOB_FINISHED_OK != Omc_ReadDataExtendedOperatingMode(&tmpData, &tmpErrorCode)) {
    result = RTE_E_DataServices_ExtendedOperatingMode_E_NOT_OK;
    *ErrorCode = tmpErrorCode;
  }

  return result;
}

/*----------------------------------------------------------------------------*/
/**
 * Function returns the current Extended Operating Mode for a
 * ReadDataByIdentifier Request. This API fulfills the API that the Dcm expects
 * when connected to the OMC SWC for its require Port of Type
 * ClientServerInterface DataServices_<Data>
 *
 * \global_r        Omc_NvData
 * \global_w        none
 * \global_rw       none
 *
 * \param[out]      Data  DID data (current ExtendedOperating Mode)
 *
 * \retval          E_OK.
 *
 * \pre             none
 *
 * \post            none
 *
 * \remarks         none
 *
 * \swsid SWS_Omc_0036
 *
 * In case the a NULL-pointer is given as parameter data, a development error
 * (if activated) is entered according to \swsref{SWS_Omc_0087}, the out
 * parameter is not set and E_OK is returned.
 * \swsid SWS_Omc_0096
 *
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Omc_ReadDIDExtendedOperatingMode
    (
        uint8* Data
    ) {
  UDS_ErrorCodeType tmpErrorCode;
  Omc_GenericExtendedOperatingModeType tmpData;

  /* Check for Development errors */
  Omc_Assert_DevAssertReturn(NULL_PTR != Data, OMC_DEVERROR_READDIDEXTOPERATINGMODE_EPARAM, RTE_E_OK);

  /* synchronous call the generic function */
  (void) Omc_ReadDataExtendedOperatingMode(&tmpData, &tmpErrorCode);
  *Data = tmpData;

  return RTE_E_OK;
}

#define Omc_STOP_SEC_CODE
#include "Omc_MemMap.h" /* PRQA S 5087 */
