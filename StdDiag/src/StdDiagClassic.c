/**
*  \file
*
*  \brief       BMW SWC StdDiag
*
*  This file contains the implementation of the module StdDiag
*  for usage in the BMW AUTOSAR Core.
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
#include "StdDiagClassic_PBCfg.h"
#include "StdDiagClassic_Version.h"
#include "StdDiag.h"
#include "StdDiag_AssertAdapter.h"
#include "Rte_StdDiag.h"

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!StdDiagClassic_CHECK_VERSION(5,4,0))
#error "Version of StdDiagClassic.c does not match the adapter or generic version!"
#endif

/*------------------------------------------------------------------------------
                      Global Variables
------------------------------------------------------------------------------*/

/* PRQA S 5087 2 */
#define StdDiag_START_SEC_VAR_NO_INIT_8
#include "StdDiag_MemMap.h"

/**
 * \brief StdDiag_currentSessionState holds the current session state value
 */
static ActiveSessionState_ArrayType StdDiag_currentSessionState;

/**
 * \brief StdDiag_ProgPrecondResult holds the status of the current precondition check
 */
static Std_ReturnType StdDiag_ProgPrecondResult;

/**
 * \brief StdDiag_ProgPrecondError holds the error code of the currently failed precondition check
 */
static Dcm_NegativeResponseCodeType StdDiag_ProgPrecondError;

/* PRQA S 5087 2 */
#define StdDiag_STOP_SEC_VAR_NO_INIT_8
#include "StdDiag_MemMap.h"

/* PRQA S 5087 2 */
#define StdDiag_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "StdDiag_MemMap.h"

/**
 * \brief StdDiag_ProgPrecondList holds the currently failed programming preconditions
 */
static uint8 StdDiag_ProgPrecondList[STDDIAG_MAX_NUMBER_PRECOND];

/**
 * \brief StdDiag_ProgPrecondLength holds the number of currently failed programming preconditions
 */
static size_t StdDiag_ProgPrecondLength;

/* PRQA S 5087 2 */
#define StdDiag_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "StdDiag_MemMap.h"


/*------------------------------------------------------------------------------
                      Global Functions
-------------------------------------------------------------------------------*/
/* PRQA S 5087 2 */
#define StdDiag_START_SEC_CODE
#include "StdDiag_MemMap.h"

/**
 * \brief Lifecycle handler of the StdDiag module.
 *
 * This function handles the lifecycle mode of the StdDiag module
 *
 * \remarks This function is called on a data received event to change the
 *          current lifecycle mode.
 *
 */
void StdDiag_LifeCycleHandler(void)
{
   Std_ReturnType retval = E_NOT_OK;
   StdDiag_LifeCycleRequestType requestedMode = Rte_IRead_LifeCycleHandler_LifeCycleRequest_requestMode();
   StdDiag_LifeCycleRequestType nextMode;
   StdDiag_LifeCycleRequestType previousMode;

   /* ignore return value, only nextMode is used */
   (void) Rte_Mode_LifeCycle_Mode(&previousMode, &nextMode);

   switch( requestedMode )
   {
      case RTE_MODE_StdDiag_LifeCycle_STDDIAG_INITIALIZED:
         if( nextMode == RTE_MODE_StdDiag_LifeCycle_STDDIAG_STOPPED )
         {
           /* if( StdDiag_Init() ) */
           StdDiag_Init();
            {
               retval = Rte_Switch_LifeCycle_Mode(requestedMode);
            }
         }
         break;

      case RTE_MODE_StdDiag_LifeCycle_STDDIAG_RUNNING:
         if( nextMode == RTE_MODE_StdDiag_LifeCycle_STDDIAG_INITIALIZED )
         {
            retval = Rte_Switch_LifeCycle_Mode(requestedMode);
         }
         break;

      case RTE_MODE_StdDiag_LifeCycle_STDDIAG_STOPPED:
         if( (nextMode == RTE_MODE_StdDiag_LifeCycle_STDDIAG_INITIALIZED) || (nextMode == RTE_MODE_StdDiag_LifeCycle_STDDIAG_RUNNING) )
         {
            StdDiag_Stop();

            retval = Rte_Switch_LifeCycle_Mode(requestedMode);
         }
         break;

      default:
         break;
   }

  StdDiag_Assert_DevAssert((E_OK == retval), STDDIAG_DEVERROR_LIFECYCLE_SWITCH_FAILED);
}

/**
 * \brief Dcm callback function for incoming diagnostic requests
 *
 * This function is called by the Dcm module every time a new diagnostic
 * request has arrived.
 *
 * \param[in] SID Value of service identifier
 * \param[in] RequestData request data (diagnostic buffer), except SID
 * \param[in] DataSize number of valid bytes in RequestData
 * \param[in] ReqType addressing type of request
 *                    (0 = physical request, 1 = functional request)
 * \param[in] SourceAddress unique identifier of the requester
 * \param[out] ErrorCode Error code according to Dcm specification. Only set in
 *                       case of return value E_NOT_OK.
 *
 * \retval E_OK request may be executed
 * \retval E_NOT_OK request may not be executed
 *
 * \remarks This function is called on an operation invoked event from the Dcm.
 * \remarks This function is called when a diagnostic request has been received.
 *
 */
Std_ReturnType StdDiag_ManufacturerIndication(
        uint8 SID,
        const uint8* RequestData,
        uint16 DataSize,
        uint8 ReqType,
        uint16 SourceAddress,
        Dcm_NegativeResponseCodeType* ErrorCode)
{
  Std_ReturnType retVal = E_OK;
  UDS_ErrorCodeType genericErrorCode;

  /* MISRA-C:2004 Rule 14.2: parameter ReqType is not used */
  /* PRQA S 3112 1 */
  (void) (ReqType);

  if(UDS_DIAG_JOB_FINISHED_OK != StdDiag_DiagRequest_Indication(SID, RequestData, DataSize, SourceAddress, &genericErrorCode))
  {
    *ErrorCode = (Dcm_NegativeResponseCodeType) genericErrorCode;
    retVal = E_NOT_OK;
  }

  return retVal;
  /* PRQA S 5204 1 */ /* number of API parameters is defined by AUTOSAR */
} /* end of function StdDiag_ManufacturerIndication */


/**
 * \brief Dcm callback function for processed diagnostic requests
 *
 * This function is called by the Dcm module every time a new diagnostic
 * request has been handled, and triggers the internal state machine.
 *
 * \param[in] SID Value of service identifier
 * \param[in] ReqType addressing type of request
 *                    (0 = physical request, 1 = functional request)
 * \param[in] SourceAddress unique identifier of the requester
 * \param[in] ConfirmationStatus result of the request handling according to
 *                               Dcm specification.
 *
 * \retval E_OK
 *
 * \remarks This function is called on an operation invoked event from the Dcm.
 * \remarks This function is called when a diagnostic request has been processed.
 *
 */
Std_ReturnType StdDiag_ManufacturerConfirmation(
    uint8 SID,
    uint8 ReqType,
    uint16 SourceAddress,
    Dcm_ConfirmationStatusType ConfirmationStatus)
{
  UDS_ConfirmationType genericConfirmation;

  /* empty runnable entity */
  /* MISRA-C:2004 Rule 14.2: parameters not used */
  /* PRQA S 3112 1 */
  (void) (ReqType);

  switch (ConfirmationStatus)
  {
    case DCM_RES_POS_OK:
      genericConfirmation = UDS_DIAG_Confirm_PosResp_OK;
      break;

    case DCM_RES_POS_NOT_OK:
      genericConfirmation = UDS_DIAG_Confirm_PosResp_E_NOT_OK;
      break;

    case DCM_RES_NEG_OK:
      genericConfirmation = UDS_DIAG_Confirm_NegResp_OK;
      break;

    case DCM_RES_NEG_NOT_OK:
    default:
      genericConfirmation = UDS_DIAG_Confirm_NegResp_E_NOT_OK;
      break;
  }

  StdDiag_DiagRequest_Confirmation(SID, SourceAddress, genericConfirmation);

  return E_OK;
} /* end of function StdDiag_ManufacturerConfirmation */

/**
 * \brief Condition check for reading the active session state
 *
 * This function checks the conditions for reading the current subsession
 * (Request 0x22 0xF1 0x00).
 *
 * \global_w StdDiag_currentSessionState
 *
 * \param[out] ErrorCode Error code according to Dcm specification. Only set in
 *                       case of return value E_NOT_OK.
 *
 * \retval E_OK conditions are fulfilled
 * \retval E_NOT_OK conditions are not fulfilled
 *
 * \remarks This function is called on an operation invoked event from the Dcm.
 *
 */
Std_ReturnType StdDiag_ConditionCheckActiveSessionState(
        Dcm_NegativeResponseCodeType* ErrorCode)
{
  Std_ReturnType retVal = E_OK;
  UDS_ErrorCodeType genericErrorCode;

  /* get current active session state from generic part */
  if( UDS_DIAG_JOB_FINISHED_OK != StdDiag_ReadDataActiveSessionState( &StdDiag_currentSessionState, &genericErrorCode ) )
  {
    *ErrorCode = (Dcm_NegativeResponseCodeType) genericErrorCode;
    retVal = E_NOT_OK;
  }

  return retVal;
} /* end of function StdDiag_ConditionCheckActiveSessionState */

/**
 * \brief Reading the current subsession
 *
 * This function reads the current subsession (Request 0x22 0xF1 0x00).
 *
 * \global_r StdDiag_currentSessionState
 *
 * \param[out] Data pointer to the buffer, where the current subsession
 *                  state is stored.
 *
 * \retval E_OK
 *
 * \remarks This function is called on an operation invoked event from the Dcm.
 *
 */
Std_ReturnType StdDiag_ReadActiveSessionState(uint8* Data)
{
   memcpy( Data, StdDiag_currentSessionState, sizeof(StdDiag_currentSessionState));

   /* always return E_OK */
   return E_OK;
} /* end of function StdDiag_ReadActiveSessionState */

/**
 * \brief Reading the SGBD Index
 *
 * This function reads the the SGBD Index (Request 0x22 0xF1 0x50).
 *
 * \param[out] Data pointer to the buffer, where the SGBD Index is stored.
 *
 * \retval E_OK
 *
 * \remarks This function is called on an operation invoked event from the Dcm.
 *
 */
Std_ReturnType StdDiag_ReadSgbdIndex(uint8* Data)
{
  memcpy( Data, StdDiag_PBConfigSetPtr->SgbdIndex, sizeof(StdDiag_SgbdIndexType));

  /* always return E_OK */
  return E_OK;
}

/**
 * \brief diagnostic request for checking the programming preconditions.
 *
 * This function implements the diagnostic request for checking the programming
 * preconditions (Request 0x31 0x01 0x02 0x03)
 *
 * \param[in] OpStatus State of the Dcm
 * \param[out] dataOut contains the list of failed preconditions.
 *                     Will be empty, if preconditions are ok.
 * \param[out] currentDataLength length of response data
 * \param[out] ErrorCode Error code according to Dcm specification.
 *                       Only set in case of return value E_NOT_OK
 *
 * \retval E_OK routine control operation was successful
 * \retval E_NOT_OK routine control operation was not successful
 * \retval RTE_E_RoutineServices_CheckProgrammingPreconditions_DCM_E_PENDING result of routine control operation is pending
 *
 * \remarks This function is called on an operation invoked event from the Dcm.
 *
 */
/* MISRA-C:2004 Rule 16.7: API is defined by AUTOSAR, but not all parameters are used in all configurations */
/* PRQA S 3673 5 */
Std_ReturnType StdDiag_RoutineControlStartCheckProgrammingPreconditions(
    Dcm_OpStatusType OpStatus,
    uint8* dataOut,
    uint16* currentDataLength,
    Dcm_NegativeResponseCodeType* ErrorCode )
{
  Std_ReturnType retVal = E_OK;
  UDS_ErrorCodeType genericErrorCode;
  UDS_ReturnType genericRetVal;

  switch (OpStatus)
  {
    case DCM_INITIAL:
      /* set pending flag */
      StdDiag_ProgPrecondResult = 0xFFu;

      /* AUTOSAR does not provide initial buffer size, so we have to set it to the maximum value */
      StdDiag_ProgPrecondLength = STDDIAG_MAX_NUMBER_PRECOND;

      genericRetVal = StdDiag_RoutineControlRawCheckProgrammingPreconditions_Start(
          NULL_PTR, 0, dataOut, &StdDiag_ProgPrecondLength, &genericErrorCode );

      switch (genericRetVal)
      {
        case UDS_DIAG_JOB_FINISHED_OK:
          *currentDataLength = (uint16) StdDiag_ProgPrecondLength;
          break;

        case UDS_DIAG_JOB_RUNNING:
          retVal = RTE_E_RoutineServices_CheckProgrammingPreconditions_DCM_E_PENDING;
          break;

        case UDS_DIAG_JOB_FINISHED_E_NOT_OK:
        default:
          *ErrorCode = (Dcm_NegativeResponseCodeType) genericErrorCode;
          retVal = RTE_E_RoutineServices_CheckProgrammingPreconditions_E_NOT_OK;
          break;
      }
      break;

    case DCM_PENDING:
      /* check callback result */
      switch (StdDiag_ProgPrecondResult)
      {
        case E_OK:
          memcpy(dataOut, StdDiag_ProgPrecondList, StdDiag_ProgPrecondLength);
          *currentDataLength = (uint16) StdDiag_ProgPrecondLength;
          retVal = E_OK;
          break;

        case RTE_E_RoutineServices_CheckProgrammingPreconditions_E_NOT_OK:
          *ErrorCode = StdDiag_ProgPrecondError;
          retVal = RTE_E_RoutineServices_CheckProgrammingPreconditions_E_NOT_OK;
          break;

        default:
          retVal = RTE_E_RoutineServices_CheckProgrammingPreconditions_DCM_E_PENDING;
          break;
      }
      break;

    case DCM_CANCEL:
      break;

    default:
      *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
      retVal = RTE_E_RoutineServices_CheckProgrammingPreconditions_E_NOT_OK;
      break;
  }

  return retVal;
} /* end of function StdDiag_RoutineControlStartCheckProgrammingPreconditions */


/**
 * \brief async callback for diagnostic request for checking the programming preconditions.
 *
 * This function implements the asynchronous callback function called by generic part on
 * successfully checking the programming preconditions
 *
 * \param[in] responseData contains the list of failed preconditions. Will be empty, if preconditions are ok.
 * \param[in] resDataLength number of failed preconditions
 *
 */
void StdDiag_UDS_RoutineControlRawCheckProgrammingPreconditions_Start_ResultOk(uint8* responseData, size_t resDataLength)
{
  memcpy(StdDiag_ProgPrecondList, responseData, resDataLength);
  StdDiag_ProgPrecondLength = resDataLength;
  /* reset pending flag */
  StdDiag_ProgPrecondResult = E_OK;
}

/**
 * \brief async callback for diagnostic request for checking the programming preconditions.
 *
 * This function implements the asynchronous callback function called by generic part when
 * checking the programming preconditions failed
 *
 * \param[in] errorCode Error code according to Dcm specification.
 *
 */
void StdDiag_UDS_RoutineControlRawCheckProgrammingPreconditions_Start_ResultError(UDS_ErrorCodeType errorCode)
{
  StdDiag_ProgPrecondError = (Dcm_NegativeResponseCodeType) errorCode;
  /* reset pending flag */
  StdDiag_ProgPrecondResult = RTE_E_RoutineServices_CheckProgrammingPreconditions_E_NOT_OK;
}


/**
 * \brief diagnostic request for diagnostic loopback function.
 *
 * This function implements the diagnostic request for the diagnostic loopback
 * function (Request 0x31 0x01 0x03 0x03)
 *
 * \param[in] dataIn contains the request data, except the SID
 * \param[in] OpStatus State of the Dcm
 * \param[out] dataOut contains the response data, that shall be
 *                     the same as the request data, except the SID.
 * \param[in,out] currentDataLength length of request/response data
 * \param[out] ErrorCode Error code according to Dcm specification.
 *                       Only set in case of return value E_NOT_OK
 *
 * \retval E_OK routine control operation was successful
 *
 * \remarks This function is called on an operation invoked event from the Dcm.
 *
 * \lhref DK_T3_792, DK_T3_796, DK_T3_798, DK_T3_799, DK_T3_800, DK_T3_801, DK_T3_802
 *
 */
Std_ReturnType StdDiag_RoutineControlStartDiagCommLoopback(
        const uint8* dataIn,
        Dcm_OpStatusType OpStatus,
        uint8* dataOut,
        uint16* currentDataLength,
        Dcm_NegativeResponseCodeType* ErrorCode)
{
    uint16 iLoop;
    uint16 bytesToCopy = *currentDataLength;

    /* MISRA-C:2004 Rule 14.2 (2x): parameters OpStatus and ErrorCode are not used */
    /* PRQA S 3112 2 */
    (void) (OpStatus);
    (void) (ErrorCode);

    for( iLoop=0; iLoop<bytesToCopy; iLoop++ )
    {
        /*
           MISRA-C:2004 Rule 17.4 (2x): array subscription is necessary to read/write more
           than one byte from/to the given buffer
        */
        /* PRQA S 0492 1 */
        dataOut[iLoop] = dataIn[iLoop];
    }

    *currentDataLength = bytesToCopy;

    return E_OK;
} /* end of function StdDiag_RoutineControlStartDiagCommLoopback */

/**
 * \brief diagnostic session change indication to default session
 *
 * This function is called when a session change to the default session has been
 * executed (Request 0x10 01 or session timeout).
 *
 * \remarks This function is called on a mode switch to STDDIAG_DEFAULT_SESSION.
 *
 */
void StdDiag_SesChgIndication_DefaultSession( void )
{
  StdDiag_NotifyDefaultSessionEnter();
}

/**
 * \brief diagnostic session change indication to any other session
 *
 * This function is called when a session change to a session has been executed,
 * that is not handled by the StdDiag.
 *
 * \remarks This function is called on a mode switch to STDDIAG_OTHER_SESSION.
 *
 */
void StdDiag_SesChgIndication_OtherSession( void )
{
  /* dummy runnable entity for unhandled session changes */
}

/**
 * \brief status change permission for operating mode
 *
 * This function is called when the operating mode shall be changed
 *
 * \param[in] OperatingMode contains the current operating mode
 * \param[in] ExtendedOperatingMode contains the current extended operating mode
 * \param[in] NewOperatingMode contains the new operating mode
 * \param[in] NewExtendedOperatingMode contains the new extended operating mode
 *
 * \retval E_OK switch to new operating mode is allowed
 * \retval RTE_E_OmcModesCallouts_E_RUNNING evaluation is not yet finished. Omc will be
 *                                          notified via callback mechanism
 * \retval RTE_E_OmcModesCallouts_E_NOT_OK switch to new operating mode is not allowed
 *
 */
Std_ReturnType StdDiag_AllowOpModeChange(
    Omc_OperatingModeType OperatingMode,
    Omc_ExtendedOperatingModeType ExtendedOperatingMode,
    Omc_OperatingModeType NewOperatingMode,
    Omc_ExtendedOperatingModeType NewExtendedOperatingMode)
{
  Std_ReturnType retVal = E_OK;
  StdDiag_App_ReturnType retValGeneric;

  /* check generic OpMode change permission */
  retValGeneric = StdDiag_AllowOpModeSwitch(OperatingMode,
                                            ExtendedOperatingMode,
                                            NewOperatingMode,
                                            NewExtendedOperatingMode);

  switch (retValGeneric) {
    case STDDIAG_APPL_E_NOT_OK:
    retVal = RTE_E_OmcModesCallouts_E_NOT_OK;
      break;

    case STDDIAG_APPL_RUNNING:
      retVal = RTE_E_OmcModesCallouts_E_RUNNING;
      break;

    default:
      break;
  }

  return retVal;
}

/**
 * \brief cancellation of status change for operating mode
 *
 * This function is called when the request to change the operating mode has been rejected
 *
 * \param[in] OperatingMode contains the current operating mode
 * \param[in] ExtendedOperatingMode contains the current extended operating mode
 * \param[in] RequestedOperatingMode contains the requested operating mode
 * \param[in] RequestedExtendedOperatingMode contains the requested extended operating mode
 *
 * \retval E_OK switch to new operating mode is allowed
 * \retval RTE_E_OmcModesCallouts_E_RUNNING cancellation is not yet finished. Omc will be
 *                                          notified via callback mechanism
 *
 */
Std_ReturnType StdDiag_OpModeChangeCancelled(
    Omc_OperatingModeType OperatingMode,
    Omc_ExtendedOperatingModeType ExtendedOperatingMode,
    Omc_OperatingModeType RequestedOperatingMode,
    Omc_ExtendedOperatingModeType RequestedExtendedOperatingMode)
{
  Std_ReturnType retVal = E_OK;

  /* inform generic part about OpMode change cancellation */
  if (STDDIAG_APPL_RUNNING == StdDiag_OpModeSwitchCancelled(OperatingMode,
                                                            ExtendedOperatingMode,
                                                            RequestedOperatingMode,
                                                            RequestedExtendedOperatingMode))
  {
    retVal = RTE_E_OmcModesCallouts_E_RUNNING;
  }

  return retVal;
}

#if( STDDIAG_CLEAR_SEC_ERROR_MEMORY == STD_ON )
/**
 * \brief diagnostic request for clearing all DTCs of the secondary error memory.
 *
 * This function implements the diagnostic request for clearing all DTCs of the
 * secondary error memory in the DEM. (Request 0x31 0x01 0x0F 0x06)
 *
 * \param[in] OpStatus State of the Dcm
 * \param[out] ErrorCode Error code according to Dcm specification.
 *                       Only set in case of return value E_NOT_OK
 *
 * \retval E_OK routine control operation was successful
 * \retval E_NOT_OK routine control operation was not successful
 * \retval RTE_E_RoutineServices_ClearDTCSecondaryErrorMemory_DCM_E_PENDING
 *         routine control operation has not finished yet
 *
 * \remarks This function is called on an operation invoked event from the Dcm.
 *
 * \lhref DK_T3_862, DK_T3_863, DK_T3_864, DK_T3_865
 *
 */
Std_ReturnType StdDiag_RoutineControlStartClearDTCSecondaryErrorMemory(
        Dcm_OpStatusType OpStatus,
        Dcm_NegativeResponseCodeType* ErrorCode)
{
   Std_ReturnType retVal = E_OK;
   Std_ReturnType resultClearDTC;

   switch( OpStatus )
   {
      case DCM_INITIAL:
      case DCM_PENDING:

         resultClearDTC = Rte_Call_ClearDTCPort_ClearDTC(STDDIAG_DTCGROUP_ALL_DTCS, DEM_DTC_FORMAT_UDS, STDDIAG_SECONDARY_ERROR_MEMORY);

         if( resultClearDTC == RTE_E_CddIf_DEM_CLEAR_PENDING )
         {
            retVal = RTE_E_RoutineServices_ClearDTCSecondaryErrorMemory_DCM_E_PENDING;
         }
         else if( resultClearDTC == E_OK )
         {
            retVal = E_OK;
         }
         else
         {
            retVal = E_NOT_OK;
         }
         break;

      case DCM_CANCEL:
         /* do nothing */
         break;

      default:
         retVal = E_NOT_OK;
         break;
   }

   if( retVal == E_NOT_OK )
   {
      *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
   }

   return retVal;
} /* end of function StdDiag_RoutineControlStartClearDTCSecondaryErrorMemory */
#endif /* STDDIAG_CLEAR_SEC_ERROR_MEMORY */

/* PRQA S 5087 2 */
#define StdDiag_STOP_SEC_CODE
#include "StdDiag_MemMap.h"


