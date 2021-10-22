/**
 * \file
 *
 * \brief       Coding Uds Adapter
 *
 * \project     BMW Platform Software
 *
 * \copyright   BMW AG 2016 - 2017
 *
 * \version     5.2.1
 *
 */

/*------------------------------------------------------------------------------
                      MISRA-Deviations
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/

#include "Coding_UDSAdapter.h"
#include "Coding_Cfg.h"                /* Size of CPS and protocolData */
#include "Rte_Coding.h"
#include <string.h>                    /* Included to get access to memcpy */
#include "CodingClassic_Version.h"     /* Coding Classic Adapter Version */

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/**
 * \brief check version of the module
 */
#if (!CodingClassic_CHECK_VERSION(5, 2, 1))
#error "Version of Coding_UdsAdapter.c does not match the Classic adapter version!"
#endif


/*------------------------------------------------------------------------------
                      Local Variables
------------------------------------------------------------------------------*/

#define Coding_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Coding_MemMap.h" /* PRQA S 5087 */

/** \lhref COD_304 */
static Coding_ResultType Coding_UdsRCcheckNCDResult = CODING_CODINGPASSED;
/** \lhref COD_307 */
static UDS_ErrorCodeType Coding_UdsRCcheckNCDError = UDS_DIAG_E_GENERALPROGRAMMINGFAILURE;
static UDS_ReturnType Coding_UdsRCcheckNCDRetValue = UDS_DIAG_JOB_FINISHED_E_NOT_OK;
/** \lhref COD_316 */
static uint8 Coding_ProofStamp[CODING_CPS_SIZE];
/** \lhref COD_331 */
static uint8 Coding_ProtocolData[CODING_RDBIPROTOCOLDATA_SIZE];

#define Coding_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Coding_MemMap.h" /* PRQA S 5087 */


/*------------------------------------------------------------------------------
                      Global Functions
------------------------------------------------------------------------------*/

#define Coding_START_SEC_CODE
#include "Coding_MemMap.h" /* PRQA S 5087 */

/*----------------------------------------------------------------------------*/
/**
 * Called by Coding, when check NCD job has finished sucessfully.
 */
/*----------------------------------------------------------------------------*/
void Coding_UDS_RoutineControlcheckNCD_Start_ResultOk(Coding_ResultType result) {
  /* Set result for answer */
  /** \lhref COD_189 */
  Coding_UdsRCcheckNCDResult = result;
  Coding_UdsRCcheckNCDRetValue = UDS_DIAG_JOB_FINISHED_OK;
}

/*----------------------------------------------------------------------------*/
/**
 * Called by Coding, when check NCD job has finished with error.
 */
/*----------------------------------------------------------------------------*/
void Coding_UDS_RoutineControlcheckNCD_Start_ResultError(UDS_ErrorCodeType errorCode) {
  /* Set result for answer */
  /** \lhref COD_307 */
  Coding_UdsRCcheckNCDError = errorCode;
  Coding_UdsRCcheckNCDRetValue = UDS_DIAG_JOB_FINISHED_E_NOT_OK;
}

/*----------------------------------------------------------------------------*/
/**
 * \brief   Reading NCD
 *
 * \global  None
 *
 * \param[in]     DcmDspStartRoutineInSignal - request for reading net coding data
 * \param[in]     OpStatus - DCM OpStatus
 * \param[out]    DcmDspStartRoutineOutSignal
 * \param[in,out] dataLength - request length, number (count) of Net coding data
 * \param[out]    errorCode - response code of function call
 *
 * \retval  E_OK: reading Coding data was successfully
 * \retval  E_NOT_OK: reading Coding data was not successfully
 *
 * \pre       None
 *
 * \post      None
 *
 * \remarks   None
 *
 * \lhref COD_178
 *
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_RoutineControlreadNCD(
    const uint8* DcmDspStartRoutineInSignal,
    Dcm_OpStatusType OpStatus,
    uint8* DcmDspStartRoutineOutSignal,
    uint16* DataLength,
    Dcm_NegativeResponseCodeType* ErrorCode) {
  UDS_ReturnType Coding_GenericRCreadNCDResult = UDS_DIAG_JOB_FINISHED_E_NOT_OK;
  UDS_ErrorCodeType Coding_GenericErrorCode = UDS_DIAG_E_REQUESTOUTOFRANGE;

  Std_ReturnType dcmRetVal = E_NOT_OK;        /* Fct. response code          */
  *ErrorCode = DCM_E_REQUESTOUTOFRANGE;       /* error response code         */

  switch (OpStatus) {
    case DCM_INITIAL:
      Coding_GenericRCreadNCDResult = Coding_RoutineControlreadNCD_Start
          (
              /** \lhref COD_179, COD_292 */
              DcmDspStartRoutineInSignal,     /* starts with codingArea      */
              /** \lhref COD_182, COD_294 */
              DcmDspStartRoutineOutSignal,    /* starts with codingArea      */
              DataLength,
              &Coding_GenericErrorCode
          );
      /** \lhref COD_367, COD_251, COD_252, COD_253 */
      *ErrorCode = (Dcm_NegativeResponseCodeType)Coding_GenericErrorCode;
      break;
    case DCM_PENDING:
    case DCM_CANCEL:
    default:
      /* Shall not be possible to end up here                                */
      Coding_GenericRCreadNCDResult = UDS_DIAG_JOB_FINISHED_E_NOT_OK;
      *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
      break;
  }

  /* convert return value */
  switch (Coding_GenericRCreadNCDResult) {
    case UDS_DIAG_JOB_FINISHED_OK:
      /** \lhref COD_254 */
      dcmRetVal = E_OK;
      break;
    case UDS_DIAG_JOB_FINISHED_E_NOT_OK:
    case UDS_DIAG_JOB_RUNNING:
    default:
      dcmRetVal = E_NOT_OK;
      break;
  }

  return (dcmRetVal);
}

/*----------------------------------------------------------------------------*/
/**
 * \brief   Writing NCD
 *
 * \global  None
 *
 * \param[in]  DcmDspStartRoutineInSignal - request for writing net coding data
 * \param[in]  OpStatus - DCM OpStatus
 * \param[in]  dataLength - number (count) of Net coding data
 * \param[out] errorCode - response code of function call
 *
 * \retval  E_OK: writing Coding data was successfully
 * \retval  E_NOT_OK: writing Coding data was not successfully
 *
 * \pre       None
 *
 * \post      None
 *
 * \remarks   None
 *
 * \lhref COD_173
 *
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_RoutineControlwriteNCD(
    const uint8* DcmDspStartRoutineInSignal,
    Dcm_OpStatusType OpStatus,
    uint16 DataLength,
    Dcm_NegativeResponseCodeType* ErrorCode) {
  UDS_ReturnType Coding_GenericRCwriteNCDResult = UDS_DIAG_JOB_FINISHED_E_NOT_OK;
  UDS_ErrorCodeType Coding_GenericErrorCode = UDS_DIAG_E_REQUESTOUTOFRANGE;

  Std_ReturnType dcmRetVal = E_NOT_OK;        /* Fct. response code          */
  *ErrorCode = DCM_E_REQUESTOUTOFRANGE;       /* error response code         */

  switch (OpStatus) {
    case DCM_INITIAL:
      Coding_GenericRCwriteNCDResult = Coding_RoutineControlwriteNCD_Start
          (
              /** \lhref COD_174, COD_297 */
              DcmDspStartRoutineInSignal,     /* starts with codingArea      */
              DataLength,
              &Coding_GenericErrorCode
          );
      /** \lhref COD_213, COD_214, COD_215 */
      *ErrorCode = (Dcm_NegativeResponseCodeType)Coding_GenericErrorCode;
      break;
    case DCM_PENDING:
    case DCM_CANCEL:
    default:
      /* Shall not be possible to end up here                                */
      *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
      Coding_GenericRCwriteNCDResult = UDS_DIAG_JOB_FINISHED_E_NOT_OK;
      break;
  }

  /* convert return value */
  switch (Coding_GenericRCwriteNCDResult) {
    case UDS_DIAG_JOB_FINISHED_OK:
      dcmRetVal = E_OK;
      break;
    case UDS_DIAG_JOB_FINISHED_E_NOT_OK:
    case UDS_DIAG_JOB_RUNNING:
    default:
      dcmRetVal = E_NOT_OK;
      break;
  }

  return (dcmRetVal);
}

/*----------------------------------------------------------------------------*/
/**
 * \brief   Checking NCD
 *
 * \global  None
 *
 * \param[in]  DcmDspStartRoutineInSignal - CPS
 * \param[in]  OpStatus - DCM OpStatus
 * \param[out] DcmDspStartRoutineOutSignal - code
 * \param[in]  dataLength - CPS
 * \param[out] errorCode - response code of function call
 *
 * \retval  E_OK:     received CPS successfully copied to ram block
 * \retval  E_NOT_OK: unexpected DCM OpStatus
 * \retval  DCM_E_PENDING: checking Coding data is ongoing
 *
 * \pre       None
 *
 * \post      None
 *
 * \remarks   None
 *
 * \lhref COD_184
 *
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_RoutineControlcheckNCD(
    const uint8* DcmDspStartRoutineInSignal,
    Dcm_OpStatusType OpStatus,
    uint8* DcmDspStartRoutineOutSignal,
    uint16 DataLength,
    Dcm_NegativeResponseCodeType* ErrorCode) {
  Std_ReturnType dcmRetVal = E_NOT_OK;        /* Fct. response code          */
  *ErrorCode = DCM_E_REQUESTOUTOFRANGE;       /* error response code         */

  switch (OpStatus) {
    case DCM_INITIAL:
      Coding_UdsRCcheckNCDRetValue = Coding_RoutineControlcheckNCD_Start
          (
              /** \lhref COD_185, COD_302 */
              DcmDspStartRoutineInSignal,     /* cps                         */
              DataLength,
              &Coding_UdsRCcheckNCDResult,
              &Coding_UdsRCcheckNCDError
          );
      break;
    case DCM_PENDING:
      /* implementation of timeout monitoring necessary */
      break;
    case DCM_CANCEL:
    default:
      /* Shall not be possible to end up here                                */
      *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
      Coding_UdsRCcheckNCDRetValue = UDS_DIAG_JOB_FINISHED_E_NOT_OK;
      break;
  }

  /* convert return value */
  switch (Coding_UdsRCcheckNCDRetValue) {
    case UDS_DIAG_JOB_RUNNING:
      dcmRetVal = RTE_E_RoutineServices_DcmDspRoutine_checkNCD_DCM_E_PENDING;
      break;
    case UDS_DIAG_JOB_FINISHED_OK:
      /** \lhref COD_188, COD_189, COD_241, COD_304 */
      *DcmDspStartRoutineOutSignal = (uint8)Coding_UdsRCcheckNCDResult;
      dcmRetVal = E_OK;
      break;
    case UDS_DIAG_JOB_FINISHED_E_NOT_OK:
    default:
      /** \lhref COD_244 */
      *ErrorCode = (Dcm_NegativeResponseCodeType)Coding_UdsRCcheckNCDError;
      dcmRetVal = E_NOT_OK;
      break;
  }

  return (dcmRetVal);
}

/*----------------------------------------------------------------------------*/
/**
 *  \brief   Service to check the condition of a cps read service.
 *
 *  Service to check the condition of a read service.
 *
 *  \param[out]  errorCode - response code of function call
 *
 *  \global   none
 *
 *  \retval  E_OK:     Conditions correct
 *  \retval  E_NOT_OK: Conditions not correct
 *
 *  \pre      none
 *
 *  \post     none
 *
 *  \remarks  none
 *
 *  \lhref COD_258, COD_314
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_ConditionCheckReadCPS(Dcm_NegativeResponseCodeType* ErrorCode) {
  UDS_ReturnType Coding_GenericReadCPSResult = UDS_DIAG_JOB_FINISHED_E_NOT_OK;
  /** \lhref COD_334 */
  UDS_ErrorCodeType Coding_GenericErrorCode = UDS_DIAG_E_REQUESTOUTOFRANGE;

  Std_ReturnType dcmRetVal = E_NOT_OK;        /* Fct. response code          */

  /** \lhref COD_316 */
  Coding_GenericReadCPSResult = Coding_ReadCPS(&Coding_ProofStamp[0], &Coding_GenericErrorCode);
  /** \lhref COD_334 */
  *ErrorCode = (Dcm_NegativeResponseCodeType)Coding_GenericErrorCode;

  /* convert return value */
  switch (Coding_GenericReadCPSResult) {
    case UDS_DIAG_JOB_FINISHED_OK:
      dcmRetVal = E_OK;
      break;
    case UDS_DIAG_JOB_FINISHED_E_NOT_OK:
    case UDS_DIAG_JOB_RUNNING:
    default:
      dcmRetVal = E_NOT_OK;
      break;
  }

  return (dcmRetVal);
}

/*----------------------------------------------------------------------------*/
/**
 *  \brief   Service to check the condition of a protocol data read service.
 *
 *  Service to check the condition of a read service.
 *
 *  \param[out]  errorCode - response code of function call
 *
 *  \global   none
 *
 *  \retval  E_OK:     Conditions correct
 *  \retval  E_NOT_OK: Conditions not correct
 *
 *  \pre      none
 *
 *  \post     none
 *
 *  \remarks  none
 *
 *  \lhref COD_329
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_ConditionCheckReadProtocolData(Dcm_NegativeResponseCodeType* ErrorCode) {
  UDS_ReturnType Coding_GenericReadProtocolDataResult = UDS_DIAG_JOB_FINISHED_E_NOT_OK;
  /** \lhref COD_334 */
  UDS_ErrorCodeType Coding_GenericErrorCode = UDS_DIAG_E_REQUESTOUTOFRANGE;

  Std_ReturnType dcmRetVal = E_NOT_OK;        /* Fct. response code          */

  /** \lhref COD_331 */
  Coding_GenericReadProtocolDataResult = Coding_ReadProtocolData(&Coding_ProtocolData[0], &Coding_GenericErrorCode);
  /** \lhref COD_334 */
  *ErrorCode = (Dcm_NegativeResponseCodeType)Coding_GenericErrorCode;

  /* convert return value */
  switch (Coding_GenericReadProtocolDataResult) {
    case UDS_DIAG_JOB_FINISHED_OK:
      dcmRetVal = E_OK;
      break;
    case UDS_DIAG_JOB_FINISHED_E_NOT_OK:
    case UDS_DIAG_JOB_RUNNING:
    default:
      dcmRetVal = E_NOT_OK;
      break;
  }

  return (dcmRetVal);
}

/*----------------------------------------------------------------------------*/
/**
 * Service that manage the read request to get coding proof stamp.
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_ReadDataCPS(uint8* Data) {
  /* Copy CPS from buffer */
  /** \lhref COD_316 */
  (void)memcpy
      (
          Data,
          &Coding_ProofStamp[0],
          CODING_CPS_SIZE
      );

  return (E_OK);
}

/*----------------------------------------------------------------------------*/
/**
 * Service that manage the read request to get the protocol data.
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_ReadDataProtocolData(uint8* Data) {
  /* Copy protocol data from buffer */
  /** \lhref COD_331 */
  (void)memcpy
      (
          Data,
          &Coding_ProtocolData[0],
          CODING_RDBIPROTOCOLDATA_SIZE
      );

  return (E_OK);
}

/*----------------------------------------------------------------------------*/
/**
 * Service that manage the exit of the Coding session.
 */
/*----------------------------------------------------------------------------*/
void Coding_SessionChange(void) {
  Coding_NotifySessionChange();
}

/*----------------------------------------------------------------------------*/
/**
 * Service that manage the reception of a new diagnostic request.
 *
 * \lhref COD_166
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_DCMIndication
    (
        uint8 SID,
        const uint8* RequestData,
        uint16 DataSize,
        uint8 ReqType,
        uint16 SourceAddress,
        Dcm_NegativeResponseCodeType* ErrorCode
    ) {
  UDS_ReturnType Coding_GenericIndicationResult = UDS_DIAG_JOB_FINISHED_E_NOT_OK;
  UDS_ErrorCodeType Coding_GenericErrorCode = UDS_DIAG_E_REQUESTOUTOFRANGE;

  Std_ReturnType dcmRetVal = E_NOT_OK;        /* Fct. response code          */

  /** \lhref COD_162 */
  Coding_GenericIndicationResult = Coding_DiagRequest_Indication
      (
          SID,
          RequestData,
          DataSize,
          SourceAddress,
          &Coding_GenericErrorCode
      );

  /* convert return value */
  switch (Coding_GenericIndicationResult) {
    case UDS_DIAG_JOB_FINISHED_OK:
      dcmRetVal = E_OK;
      break;
    case UDS_DIAG_JOB_FINISHED_E_NOT_OK:
    default:
      /** \lhref COD_162 */
      *ErrorCode = (Dcm_NegativeResponseCodeType)Coding_GenericErrorCode;
      dcmRetVal = E_NOT_OK;
      break;
  }

  /* PRQA S 3112 1 */
  (void)ReqType;

  return (dcmRetVal);
  /* PRQA S 5204 1 *//* Function is specified with 6 parameters */
}

/*----------------------------------------------------------------------------*/
/**
 * Service that manage the confirmation of a successful reception of a
 * new diagnostic request.
 */
/*----------------------------------------------------------------------------*/
Std_ReturnType Coding_DCMConfirmation
    (
        uint8 SID,
        uint8 ReqType,
        uint16 SourceAddress,
        Dcm_ConfirmationStatusType ConfirmationStatus
    ) {
  /* the input parameters of this function are not used, the function doesn't
     perform any action */

  /* PRQA S 3112 4 */
  (void)SID;
  (void)ReqType;
  (void)SourceAddress;
  (void)ConfirmationStatus;

  /* always returns E_OK */
  return (E_OK);
}


#define Coding_STOP_SEC_CODE
#include "Coding_MemMap.h" /* PRQA S 5087 */
