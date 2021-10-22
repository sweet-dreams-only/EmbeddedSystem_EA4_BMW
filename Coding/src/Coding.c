/**
 * \file
 *
 * \brief       Coding
 *
 * This file is the implementation file for the Coding module.
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
/*
 * Violation of MISRA-C 2004 Rule 19.1
 * Reason: Including Coding_MemMap.h is necessary throughout
 * the file according to memory abstraction. See PRQA 5087.
 */

/*
 * Violation of MISRA-C 2004 Rule 11.5
 * Reason: The concept of using a ParameterSwComponent for CodingData
 * requires the pointer to be casted to non-const. See PRQA 0311.
 */

/*
 * Violation of MISRA-C 2004 Rule 14.2
 * Reason: The function is specified in AUTOSAR with these parameters, serviceId
 * and retrunValue is not used when CODING_DEV_ERROR_DETECT == STD_ON
 * See PRQA 3112.
 */

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/

#include "Coding.h"                    /* Own header file */
#include <string.h>                    /* Included to get access to memcpy */
#include <stddef.h>                    /* Included to support size_t */
#include "BUtil/PlatformTypes.h"       /* BMW Platform Types */
#include "BUtil/GenericErrMemTypes.h"  /* BMW Error Memory Types */
#include "BUtil/GenericNvMTypes.h"     /* BMW Nonvolatile Memory Types */
#include "BUtil_ByteMask.h"            /* BMW Access Single Bytes of Words */

#include "Coding_TimerAdapter.h"
#include "Coding_DlogAdapter.h"
#include "Coding_ConcAdapter.h"
#include "Coding_Assert.h"
#include "Coding_CryptoAdapter.h"
#include "Coding_MgmtAdapter.h"
#include "Coding_ErrMemAdapter.h"
#include "Coding_NvMAdapter.h"
#include "Coding_UDSAdapter.h"
#include "Coding_ApplAdapter.h"
#include "Coding_Data.h"


/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* Check version of the module. */
#if (!Coding_CHECK_VERSION(5, 2, 1))
#error "Version of Coding.c does not match the version of the module!"
#endif

/**
 * \brief Vehicle identification numer offset within coding proof stamp
 */
#define CODING_VIN_OFFSET              ((uint8)11u) /* in bytes */

/**
 * \brief Service size of the routine control request services
 *        readNCD, writeNCD and checkNCD.
 *        1 byte RoutineControl + 1 byte startRoutine +
 *        2 bytes service
 */
#define CODING_RCREQUEST_SERVICESIZE   ((uint8)6u) /* in bytes */

/**
 * \brief Headersize of the routine control request services
 *        readNCD and writeNCD.
 *        1 byte RoutineControl + 1 byte startRoutine +
 *        2 bytes service +
 *        1 byte codingArea + 1 byte ncdSegment +
 *        2 bytes rxBuffSize + 2 bytes ncdLength
 */
#define CODING_RCREQUEST_HEADERSIZE    ((uint8)10u) /* in bytes */

/**
 * \brief Headersize of the routine control response service readNCD.
 */
#define CODING_RCRESPONSE_HEADERSIZE   ((uint8)6u) /* in bytes */

/**
 * \brief Net coding data offset of the routine control request service writeNCD.
 */
#define CODING_RCREQUEST_NCDOFFSET     ((uint8)6u) /* in bytes */

/**
 * \brief Net coding data offset of the routine control response service readNCD.
 */
#define CODING_RCRESPONSE_NCDOFFSET    ((uint8)2u) /* in bytes */

/**
 * \brief Definition of net coding data qualification timeout after each startup
 */
#define CODING_QUALIFICATION_TIMEOUT   ((uint32)3000u)  /* in ms */

/**
 * \brief Size of the first start information.
 */
#define CODING_PROGID_SIZE             ((uint8)8u) /* in bytes */


/*------------------------------------------------------------------------------
                      Local Data Types
------------------------------------------------------------------------------*/

/* Coding Cps Type */
typedef uint8 Coding_CpsType[CODING_CPS_SIZE];

/* Coding ProgId Type */
typedef uint8 Coding_ProgIdType[CODING_PROGID_SIZE];


/*------------------------------------------------------------------------------
                      Local Variables
------------------------------------------------------------------------------*/

#define Coding_START_SEC_VAR_INIT_8
#include "Coding_MemMap.h" /* PRQA S 5087 */

/**
 * \brief Stores the received vehicle identification number.
 */
static Coding_VinType Coding_ReceivedVin = {0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu};

/**
 * \brief Stores the timer handle number.
 */
static TimerHandleType timerHandle = TIMER_HANDLE_TYPE_INVALID;

#define Coding_STOP_SEC_VAR_INIT_8
#include "Coding_MemMap.h" /* PRQA S 5087 */

#define Coding_START_SEC_VAR_INIT_UNSPECIFIED
#include "Coding_MemMap.h" /* PRQA S 5087 */

/** \lhref COD_126 */
static Coding_StateType Coding_State = {CODING_ST_STOP, DATA_ST_UNDEFINED, DIAG_ST_IDLE, TRUE, FALSE, FALSE};

#define Coding_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Coding_MemMap.h" /* PRQA S 5087 */


/*------------------------------------------------------------------------------
                      Local Constants
------------------------------------------------------------------------------*/

#define Coding_START_SEC_CONST_8
#include "Coding_MemMap.h" /* PRQA S 5087 */

/**
 * \brief Stores the values of a Vin in a default CPS.
 */
static const Coding_VinType Coding_DefaultVin = {0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu};

#define Coding_STOP_SEC_CONST_8
#include "Coding_MemMap.h" /* PRQA S 5087 */

/*------------------------------------------------------------------------------
                      Local Function Prototypes
------------------------------------------------------------------------------*/

#define Coding_START_SEC_CODE
#include "Coding_MemMap.h" /* PRQA S 5087 */

static void Coding_RunDiagStateReset(void);

static void Coding_NcdState(Coding_NCDStateType ncdState);

static void Coding_RunState(Coding_RunStateType runState);

static void Coding_StartupEcu(void);

static void Coding_QualifyNcd(void);

static Coding_ReturnType Coding_CheckCPS(const uint8 cps[CODING_CPS_SIZE]);

static Coding_ReturnType Coding_CheckSignatureNCD(const uint8* cps);

static void Coding_NvMFinishedCallbackInitialCodingData(NvMService_ResultType result, void* context);

static void Coding_NvMFinishedCallbackRestoreCodingData(NvMService_ResultType result, void* context);

static void Coding_NvMFinishedCallbackWriteCodingData(NvMService_ResultType result, void* context);

static void Coding_QualificationTimeout(void* context);

#define Coding_STOP_SEC_CODE
#include "Coding_MemMap.h" /* PRQA S 5087 */

/*------------------------------------------------------------------------------
                      Local Functions
------------------------------------------------------------------------------*/

#define Coding_START_SEC_CODE
#include "Coding_MemMap.h" /* PRQA S 5087 */


/*----------------------------------------------------------------------------*/
/**
 * Function that manage the runState and diagState reset.
 */
/*----------------------------------------------------------------------------*/
static void Coding_RunDiagStateReset(void) {
  Coding_CritSect_State_Enter();
  Coding_State.runState = CODING_ST_RUN_IDLE;
  Coding_State.diagState = DIAG_ST_IDLE;
  Coding_CritSect_State_Exit();
}

/*----------------------------------------------------------------------------*/
/**
 * Function that manage the ncdState.
 */
/*----------------------------------------------------------------------------*/
static void Coding_NcdState(Coding_NCDStateType ncdState) {
  Coding_CritSect_State_Enter();
  Coding_State.ncdState = ncdState;
  Coding_CritSect_State_Exit();
}

/*----------------------------------------------------------------------------*/
/**
 * Function that manage the runState.
 */
/*----------------------------------------------------------------------------*/
static void Coding_RunState(Coding_RunStateType runState) {
  Coding_CritSect_State_Enter();
  Coding_State.runState = runState;
  Coding_CritSect_State_Exit();
}

/*----------------------------------------------------------------------------*/
/**
 * Function that manage the startup.
 *
 * \lhref COD_145
 */
/*----------------------------------------------------------------------------*/
static void Coding_StartupEcu(void) {
  Coding_ProgIdType progId = {0u};

  Coding_DlogGetProgId(progId);

  /* Sucessfully coded after flash programming */
  if (memcmp(
      /* Choose correct snipped of Coding data - Coding data is a byte array (uint8) */
      &Coding_CodingData[CODING_PROGID_OFFSET],
      &progId,
      sizeof(Coding_ProgIdType)
  ) == 0) { /** \lhref COD_132 */
    /* Deactivate all coding DTCs */
    (void)Coding_ErrMem_ClearEventAllowedNotCoded(ERRMEM_CLEAR_ALLOWED);
    (void)Coding_ErrMem_SetEventStatusNotCoded(ERRMEM_EVENT_STATUS_PASSED);
    (void)Coding_ErrMem_SetEventStatusWrongVehicle(ERRMEM_EVENT_STATUS_PASSED);
#if (CODING_PROD_ERROR_CEUD_DETECTION == STD_ON)
    (void)Coding_ErrMem_SetEventStatusUnqualifiedData(ERRMEM_EVENT_STATUS_PASSED);
#endif

    /* set ncdState to unqualified */
    Coding_NcdState(DATA_ST_UNQUALIFIED);

    /* set runState to idle */
    Coding_RunState(CODING_ST_RUN_IDLE);
  } else { /** \lhref COD_131 */
    /* Copy CPS and NCD from CDES to CDWS */
    /** \lhref COD_089 */
    (void)memcpy
        (
            Coding_CodingData,
            Coding_CodingDataDefault,
            CODING_DATA_SIZE
        );

    /* Activate DTC CENC */
    /** \lhref COD_119 */
    (void)Coding_ErrMem_ClearEventAllowedNotCoded(ERRMEM_CLEAR_NOT_ALLOWED);
    (void)Coding_ErrMem_SetEventStatusNotCoded(ERRMEM_EVENT_STATUS_FAILED);

    /* set ncdState to default */
    Coding_NcdState(DATA_ST_DEFAULT);

    /* set runState to idle */
    Coding_RunState(CODING_ST_RUN_IDLE);
  }
  /* Notify coding data dependent applications about ncdState */
  /** \lhref COD_133 */
  Coding_Notify_NCDState(Coding_State.ncdState);
  /* PRQA S 5203 1 *//* Enter-/Exiting exclusive areas increments the count by 2 */
}

/*----------------------------------------------------------------------------*/
/**
 * Function that manage the qualification of Coding data.
 *
 * \lhref COD_134, COD_143
 */
/*----------------------------------------------------------------------------*/
static void Coding_QualifyNcd(void) {
  /* Check if a (valid) vin has been received on bus */
  if (TRUE == Coding_State.checkCPSPending) {
    /* Check if ncdState is unqualified */
    /** \lhref COD_136 */
    if (DATA_ST_UNQUALIFIED == Coding_State.ncdState) {
      /* Check if received vin is equal to stored cps */
      /** \lhref COD_136 */
      if (memcmp(
          Coding_ReceivedVin, &Coding_CodingData[CODING_CPS_OFFSET + CODING_VIN_OFFSET], sizeof(Coding_VinType)) != 0) {
        /* Activate DTC CEWV */
        /** \lhref COD_119, COD_137 */
        (void)Coding_ErrMem_SetEventStatusWrongVehicle(ERRMEM_EVENT_STATUS_FAILED);
        /* Activate DTC CENC */
        /** \lhref COD_119, COD_137 */
        (void)Coding_ErrMem_ClearEventAllowedNotCoded(ERRMEM_CLEAR_NOT_ALLOWED);
        (void)Coding_ErrMem_SetEventStatusNotCoded(ERRMEM_EVENT_STATUS_FAILED);

        /* Set ncdState to inProgress */
        Coding_NcdState(DATA_ST_INPROGRESS);

        /* Copy CPS and all NCD from CDES to CDWS */
        /** \lhref COD_089, COD_137 */
        (void)memcpy
            (
                Coding_CodingData,
                Coding_CodingDataDefault,
                CODING_DATA_SIZE
            );

        /* Set ncdState to default */
        Coding_NcdState(DATA_ST_DEFAULT);
      } else {
        /* Set ncdState to qualified */
        /** \lhref COD_141 */
        Coding_NcdState(DATA_ST_QUALIFIED);
      }
      /* Notify coding data dependent applications about ncdState */
      /** \lhref COD_137, COD_141 */
      Coding_Notify_NCDState(Coding_State.ncdState);
    }
  }
#if (CODING_PROD_ERROR_CEUD_DETECTION == STD_ON)
  else /* no (valid) vin has been received yet */
  {
    /* Check if qualification timeout after each startup has expired */
    /* and coding data do not contain default values. */
    /** \lhref COD_139 */
    if ((FALSE == Coding_State.waitForVin) &&
        (DATA_ST_DEFAULT != Coding_State.ncdState)) {
      /* Activate DTC CEUD */
      /** \lhref COD_119 */
      (void)Coding_ErrMem_SetEventStatusUnqualifiedData(ERRMEM_EVENT_STATUS_FAILED);
    }
  }
#endif
  /* PRQA S 5203 1 *//* Splitting the function makes the code more unreadable */
}

/*----------------------------------------------------------------------------*/
/**
 * Function that manage the check and validation of Coding proof stamp.
 *
 * \lhref COD_231, COD_237
 */
/*----------------------------------------------------------------------------*/
static Coding_ReturnType Coding_CheckCPS(const uint8 cps[CODING_CPS_SIZE]) {
  /** \lhref COD_233 */
  Coding_ReturnType retVal = CODING_RC_E_NOT_OK;

  /* Check if no Vin is received or (already received) Vin is invalid */
  /** \lhref COD_232 */
  if ((FALSE == Coding_State.checkCPSPending) ||
      (memcmp(Coding_ReceivedVin, Coding_DefaultVin, sizeof(Coding_VinType)) == 0)) /* PRQA S 3415 */
  {
    /* No Vin is received or (already received) Vin is invalid */
    /* Set ncdState to unqualified */
    /** \lhref COD_232 */
    Coding_NcdState(DATA_ST_UNQUALIFIED);
    Coding_Notify_NCDState(Coding_State.ncdState);

    /* Activate DTC CEUD */
    /** \lhref COD_114, COD_119, COD_138 */
#if (CODING_PROD_ERROR_CEUD_DETECTION == STD_ON)
    (void)Coding_ErrMem_SetEventStatusUnqualifiedData(ERRMEM_EVENT_STATUS_FAILED);
#endif

    /** \lhref COD_234 */
    retVal = CODING_RC_OK;
    return (retVal);
  }

  /* If a Vin have been received on bus */
  if (TRUE == Coding_State.checkCPSPending) {
    /* Check to see if received Vin is identically to the passed one */
    /** \lhref COD_233, COD_234 */
    if (memcmp(Coding_ReceivedVin, &cps[CODING_VIN_OFFSET], sizeof(Coding_VinType)) == 0) {
      /* The received Vin is identically to the passed one */
      /* Set ncdState to qualified */
      /** \lhref COD_235 */
      Coding_NcdState(DATA_ST_QUALIFIED);
      Coding_Notify_NCDState(Coding_State.ncdState);

      retVal = CODING_RC_OK;
    }
  }

  return (retVal);
  /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Function that manage the signature check of all configured codingAreas.
 *
 * \lhref COD_147, COD_150
 */
/*----------------------------------------------------------------------------*/
static Coding_ReturnType Coding_CheckSignatureNCD(const uint8* cps) {
  Coding_Crypto_VerifyState verifyState = CODING_CRYPTO_VERIFIED;
  /** \lhref COD_097 */
  uint8 codingAreaIdx = 0u;

  /** \lhref COD_149, COD_150, COD_229, COD_230 */
  while ((codingAreaIdx < CODING_NUMBER_OF_AREAS) && (verifyState == CODING_CRYPTO_VERIFIED)) {
    /* do a signature check for a specific area */
    verifyState = Coding_Crypto_SignatureCheck(codingAreaIdx, cps);

    ++codingAreaIdx;
  }

  /* If all codingAreas have been checked or if the result of the check of
   * the latest codingArea failed - convert return value.
   */
  if (verifyState != CODING_CRYPTO_VERIFIED) {
    /** \lhref COD_230 */
    return (CODING_RC_E_NOT_OK);
  } else {
    return (CODING_RC_OK);
  }
  /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Function that manage the coding states when no (valid) Vin has been
 * received 3000 ms after each startup.
 *
 * \lhref COD_135
 */
/*----------------------------------------------------------------------------*/
static void Coding_QualificationTimeout(void* context) /* PRQA S 3673 */
{
  (void)context;  /* PRQA S 3112 */

  Coding_CritSect_State_Enter();
  Coding_State.waitForVin = FALSE;
  Coding_CritSect_State_Exit();

  /** \lhref COD_136, COD_137, COD_139 */
  Coding_QualifyNcd();
}

/*----------------------------------------------------------------------------*/
/**
 * Function that manage the coding states when the initial read job has finished.
 */
/*----------------------------------------------------------------------------*/
static void Coding_NvMFinishedCallbackInitialCodingData(NvMService_ResultType result, void* context) /* PRQA S 3673 */
{
  (void)result; /* PRQA S 3112 */
  (void)context; /* PRQA S 3112 */
  Coding_StartupEcu();
  Coding_Mgmt_StartupFinished();
}

/*----------------------------------------------------------------------------*/
/**
 * Function that manage the coding states after restoration of coding data.
 */
/*----------------------------------------------------------------------------*/
static void Coding_NvMFinishedCallbackRestoreCodingData(NvMService_ResultType result, void* context) /* PRQA S 3673 */
{
  (void)result; /* PRQA S 3112 */
  (void)context; /* PRQA S 3112 */
  Coding_StartupEcu();
  Coding_QualifyNcd();
}

/*----------------------------------------------------------------------------*/
/**
 * Function that manage the coding states when the write job has finished.
 */
/*----------------------------------------------------------------------------*/
static void Coding_NvMFinishedCallbackWriteCodingData(NvMService_ResultType result, void* context) /* PRQA S 3673 */
{
  (void)context; /* PRQA S 3112 */

  /** \lhref COD_244 */
  if (NVMSERVICE_OK != result) {
    /* Set ncdState to inProgress */
    Coding_NcdState(DATA_ST_INPROGRESS);

    /* Notify coding data dependent applications about ncdState */
    Coding_Notify_NCDState(Coding_State.ncdState);

    /* send negative response NRC 0x72 */
    /** \lhref COD_188, COD_189, COD_307 */
    Coding_UDS_RoutineControlcheckNCD_Start_ResultError
        (
            UDS_DIAG_E_GENERALPROGRAMMINGFAILURE
        );
  } else {
    /* Deactivate all coding DTCs */
    /** \lhref COD_240 */
    (void)Coding_ErrMem_ClearEventAllowedNotCoded(ERRMEM_CLEAR_ALLOWED);
    (void)Coding_ErrMem_SetEventStatusNotCoded(ERRMEM_EVENT_STATUS_PASSED);
    (void)Coding_ErrMem_SetEventStatusWrongVehicle(ERRMEM_EVENT_STATUS_PASSED);
#if (CODING_PROD_ERROR_CEUD_DETECTION == STD_ON)
    if (DATA_ST_UNQUALIFIED != Coding_State.ncdState) {
      (void)Coding_ErrMem_SetEventStatusUnqualifiedData(ERRMEM_EVENT_STATUS_PASSED);
    }
#endif

    /* send positive response code */
    /** \lhref COD_188, COD_189, COD_241, COD_304 */
    Coding_UDS_RoutineControlcheckNCD_Start_ResultOk
        (
            CODING_CODINGPASSED
        );
  }

  Coding_CritSect_State_Enter();
  Coding_State.diagState = DIAG_ST_IDLE;
  if (FALSE != Coding_State.shutdownPending) {
    Coding_State.runState = CODING_ST_STOP;
  } else {
    Coding_State.runState = CODING_ST_RUN_IDLE;
  }
  Coding_CritSect_State_Exit();
  if (FALSE != Coding_State.shutdownPending) {
    /* Stop timeout monitoring */
    Coding_Timer_CancelTimer(timerHandle);
    Coding_Mgmt_ShutdownFinished();
  }
  /* PRQA S 5203 1 *//* Enter-/Exiting exclusive areas increments the count by 2 */
}

/*------------------------------------------------------------------------------
                      Global Functions
------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/**
 * Initialize.
 *
 * Coding_CodingData must be loaded with NvM data or with ROM defaults.
 *
 */
/*----------------------------------------------------------------------------*/
void Coding_Init(void) {
  /* Set runState to init */
  Coding_RunState(CODING_ST_INIT);
  Coding_NvM_ReadInitialCodingData(Coding_CodingData, &Coding_NvMFinishedCallbackInitialCodingData, NULL);
}

/*----------------------------------------------------------------------------*/
/**
 * Pre run.
 *
 * Start coding data qualification timer.
 *
 */
/*----------------------------------------------------------------------------*/
void Coding_Run(void) {
  timerHandle = Coding_Timer_SetTimer(CODING_QUALIFICATION_TIMEOUT, &Coding_QualificationTimeout, NULL);
  Coding_Mgmt_PreRunFinished();
}

/*----------------------------------------------------------------------------*/
/**
 * Shuts down.
 *
 * All currently running asynchronous operations will be finished first.
 *
 * When everything is done, Coding_Mgmt_ShutdownFinished() will be called either
 * directly from this functions or later asynchronously.
 *
 */
/*----------------------------------------------------------------------------*/
void Coding_Shutdown(void) {
  Coding_CritSect_State_Enter();
  if (CODING_ST_RUN_IDLE == Coding_State.runState) {
    Coding_State.runState = CODING_ST_STOP;
    Coding_CritSect_State_Exit();
    /* Stop timeout monitoring */
    Coding_Timer_CancelTimer(timerHandle);
    Coding_Mgmt_ShutdownFinished();
  } else {
    Coding_State.shutdownPending = TRUE;
    Coding_CritSect_State_Exit();
  }
}

/*----------------------------------------------------------------------------*/
/**
 * Called by the Uds Adapter to read NCD.
 *
 * \lhref COD_178, COD_209, COD_249, COD_250, COD_257
 */
/*----------------------------------------------------------------------------*/
UDS_ReturnType Coding_RoutineControlreadNCD_Start(
    const uint8* inSignal,
    uint8* outSignal,
    uint16* dataLength,
    UDS_ErrorCodeType* errorCode) {
  /* Layout (request): reading net coding data */
  /** \lhref COD_179, COD_180, COD_292 */
  const uint8 codingArea = inSignal[0]; /* PRQA S 0492 */
  const uint8 ncdSegment = inSignal[1]; /* PRQA S 0492 */
  uint16 txBuffSize = BUtil_Make16Bit(inSignal[2], inSignal[3]); /* PRQA S 0492, 4397 */
  const uint16 ncdLength = BUtil_Make16Bit(inSignal[4], inSignal[5]); /* PRQA S 0492, 4397 */

  /** \lhref COD_251, COD_252, COD_253 */
  UDS_ReturnType retVal = UDS_DIAG_JOB_FINISHED_E_NOT_OK;   /* Fct. response code         */
  /** \lhref COD_307 */
  *errorCode = UDS_DIAG_E_REQUESTOUTOFRANGE;                /* error response code        */

  /* Check: received dataLength plausible */
  /** \lhref COD_250 */
  if (*dataLength != CODING_RCREQUEST_SERVICESIZE) {
    retVal = UDS_DIAG_JOB_FINISHED_E_NOT_OK;
    /** \lhref COD_307 */
    *errorCode = UDS_DIAG_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
    return (retVal);
  }

#if (STD_ON == CODING_CONDITIONCHECK_SUPPORT)
  /** \lhref COD_205 */
  if (FALSE == Coding_ConditionState()) {
    retVal = UDS_DIAG_JOB_FINISHED_E_NOT_OK;
    /** \lhref COD_307 */
    *errorCode = UDS_DIAG_E_CONDITIONSNOTCORRECT;
    return (retVal);
  }
#endif /* CODING_CONDITIONCHECK_SUPPORT */

  /* Check: received txBuffSize plausible */
  /** \lhref COD_169, COD_367 */
  if ((txBuffSize > CODING_TX_BUFFER_SIZE) ||
      (txBuffSize <= CODING_RCRESPONSE_HEADERSIZE)) {
    retVal = UDS_DIAG_JOB_FINISHED_E_NOT_OK;
    /** \lhref COD_307 */
    *errorCode = UDS_DIAG_E_REQUESTOUTOFRANGE;
    return (retVal);
  }

  Coding_CritSect_State_Enter();
  if (CODING_ST_RUN_IDLE != Coding_State.runState) {
    Coding_CritSect_State_Exit();
    retVal = UDS_DIAG_JOB_FINISHED_E_NOT_OK;
    /** \lhref COD_307 */
    *errorCode = UDS_DIAG_E_CONDITIONSNOTCORRECT;
    return (retVal);
  }
  Coding_State.runState = CODING_ST_RUN_DIAG;
  Coding_State.diagState = DIAG_ST_RC_READ_NCD;
  Coding_CritSect_State_Exit();

  /** \lhref COD_169 */
  txBuffSize -= CODING_RCRESPONSE_HEADERSIZE;  /* ncd length without RC response reader */

  /* Check: codingArea supported, ncdSegment plausible
            and ncdLength supported for codingArea */
  /** \lhref COD_097, COD_169, COD_251, COD_252, COD_253 */
  if ((codingArea < CODING_NUMBER_OF_AREAS) &&
      ((ncdSegment * txBuffSize) < Coding_AreaSizeTable[codingArea]) &&
      (ncdLength == Coding_AreaSizeTable[codingArea])) {
    /** \lhref COD_182, COD_183, COD_294 */
    outSignal[0] = codingArea; /* PRQA S 0492 */ /* set number of coding area */
    outSignal[1] = ncdSegment; /* PRQA S 0492 */ /* set ncd segment counter   */
    *dataLength = txBuffSize;                    /* set ncd segment size      */

    /* Verify the remaining bytes of Coding data */
    if (*dataLength > (Coding_AreaSizeTable[codingArea] - (ncdSegment * txBuffSize))) {
      *dataLength = (Coding_AreaSizeTable[codingArea] - (ncdSegment * txBuffSize));
    }

    Coding_CritSect_Data_Enter();
    /* Read ncdData for requested ncdSegment from CDWS */
    /** \lhref COD_368, COD_182, COD_183, COD_254, COD_255, COD_294 */
    (void)memcpy
        (
            &outSignal[CODING_RCRESPONSE_NCDOFFSET], /* PRQA S 0492 */
            /* Pick correct snipped of Coding data - Coding data is a byte array (uint8) */
            &Coding_CodingData[(ncdSegment * txBuffSize) + Coding_AreaOffsetTable[codingArea]],
            (uint32)*dataLength
        );
    Coding_CritSect_Data_Exit();

    *dataLength += CODING_RCRESPONSE_NCDOFFSET; /* length of output stream */
    /* ncd segment size + 1 byte (number of coding area) + 1 byte (ncd segment counter) */
    /** \lhref COD_254 */
    retVal = UDS_DIAG_JOB_FINISHED_OK;         /* Fct response code         */
  }

  /* set runState and diagState to idle */
  Coding_RunDiagStateReset();

  return (retVal);
  /* PRQA S 5207 3 *//* Multiple exit points to make the code more readable */
  /* PRQA S 5203 2 *//* Enter-/Exiting exclusive areas increments the count by 2 */
  /* PRQA S 5204 1 *//* Function is specified with 9 parameters */
}

/*----------------------------------------------------------------------------*/
/**
 * Called by the Uds Adapter to write NCD.
 *
 * \lhref COD_173, COD_209, COD_220, COD_222
 */
/*----------------------------------------------------------------------------*/
UDS_ReturnType Coding_RoutineControlwriteNCD_Start(
    const uint8* inSignal,
    uint16 dataLength,
    UDS_ErrorCodeType* errorCode) {
  /* Layout (request): writing net coding data */
  /** \lhref COD_174, COD_175, COD_297 */
  const uint8 codingArea = inSignal[0]; /* PRQA S 0492 */
  const uint8 ncdSegment = inSignal[1]; /* PRQA S 0492 */
  uint16 rxBuffSize = BUtil_Make16Bit(inSignal[2], inSignal[3]); /* PRQA S 0492, 4397 */
  const uint16 ncdLength = BUtil_Make16Bit(inSignal[4], inSignal[5]); /* PRQA S 0492, 4397 */

  /** \lhref COD_213, COD_214, COD_215 */
  UDS_ReturnType retVal = UDS_DIAG_JOB_FINISHED_E_NOT_OK;   /* Fct. response code        */
  /** \lhref COD_307 */
  *errorCode = UDS_DIAG_E_REQUESTOUTOFRANGE;                /* error response code       */

  /* Check: received dataLength plausible */
  if (dataLength < CODING_RCREQUEST_SERVICESIZE) {
    retVal = UDS_DIAG_JOB_FINISHED_E_NOT_OK;
    /** \lhref COD_307 */
    *errorCode = UDS_DIAG_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
    return (retVal);
  }

#if (STD_ON == CODING_CONDITIONCHECK_SUPPORT)
  /** \lhref COD_205 */
  if (FALSE == Coding_ConditionState()) {
    retVal = UDS_DIAG_JOB_FINISHED_E_NOT_OK;
    /** \lhref COD_307 */
    *errorCode = UDS_DIAG_E_CONDITIONSNOTCORRECT;
    return (retVal);
  }
#endif /* CODING_CONDITIONCHECK_SUPPORT */

  /* Check: received rxBuffSize plausible */
  /** \lhref COD_169 */
  if ((rxBuffSize > CODING_RX_BUFFER_SIZE) ||
      (rxBuffSize <= CODING_RCREQUEST_HEADERSIZE)) {
    retVal = UDS_DIAG_JOB_FINISHED_E_NOT_OK;
    /** \lhref COD_307 */
    *errorCode = UDS_DIAG_E_REQUESTOUTOFRANGE;
    return (retVal);
  }

  Coding_CritSect_State_Enter();
  if (CODING_ST_RUN_IDLE != Coding_State.runState) {
    Coding_CritSect_State_Exit();
    retVal = UDS_DIAG_JOB_FINISHED_E_NOT_OK;
    /** \lhref COD_307 */
    *errorCode = UDS_DIAG_E_CONDITIONSNOTCORRECT;
    return (retVal);
  }
  Coding_State.runState = CODING_ST_RUN_DIAG;
  Coding_State.diagState = DIAG_ST_RC_WRITE_NCD;
  Coding_CritSect_State_Exit();

  /** \lhref COD_169 */
  rxBuffSize -= CODING_RCREQUEST_HEADERSIZE;   /* rxBuffSize without RC request reader */

  /* Check: codingArea supported, ncdSegment plausible
            and ncdLength supported for codingArea */
  /** \lhref COD_097, COD_169, COD_213, COD_214, COD_215 */
  if ((codingArea < CODING_NUMBER_OF_AREAS) &&
      (((ncdSegment * rxBuffSize) + (dataLength - CODING_RCREQUEST_NCDOFFSET)) <= Coding_AreaSizeTable[codingArea]) &&
      (ncdLength == Coding_AreaSizeTable[codingArea])) {
    /* Check: ncdState inProgress is already set */
    /** \lhref COD_216 */
    if (Coding_State.ncdState != DATA_ST_INPROGRESS) {
      /* Set ncdState to inProgress */
      Coding_NcdState(DATA_ST_INPROGRESS);
      /** \lhref COD_218 */
      Coding_Notify_NCDState(Coding_State.ncdState);
    }

    Coding_CritSect_Data_Enter();
    /* Write received ncdData into CDWS */
    /** \lhref COD_368, COD_174, COD_175, COD_218, COD_297 */
    (void)memcpy
        (
            /* Choose correct snipped of Coding data - Coding data is a byte array (uint8) */
            &Coding_CodingData[(ncdSegment * rxBuffSize) + Coding_AreaOffsetTable[codingArea]],
            &inSignal[CODING_RCREQUEST_NCDOFFSET], /* PRQA S 0492 */
            (uint32)dataLength - (uint32)CODING_RCREQUEST_NCDOFFSET /* length of ncd input stream without */
            /* 1 byte (number of coding area) + 1 byte (ncd segment counter) + */
            /* 2 byte (rxBuffSize) + 2 byte (ncd length)                       */
        );
    Coding_CritSect_Data_Exit();

    /** \lhref COD_218 */
    retVal = UDS_DIAG_JOB_FINISHED_OK;         /* Fct response code         */
  }

  /* set runState and diagState to idle */
  Coding_RunDiagStateReset();

  return (retVal);
  /* PRQA S 5207 3 *//* Multiple exit points to make the code more readable */
  /* PRQA S 5203 2 *//* Enter-/Exiting exclusive areas increments the count by 2 */
  /* PRQA S 5204 1 *//* Function is specified with 7 parameters */
}

/*----------------------------------------------------------------------------*/
/**
 * Called by the Uds Adapter to check NCD.
 *
 * \lhref COD_184, COD_209, COD_225, COD_246
 */
/*----------------------------------------------------------------------------*/
UDS_ReturnType Coding_RoutineControlcheckNCD_Start(
    /** \lhref COD_185, COD_302 */
    const uint8* cps,
    uint16 dataLength,
    /** \lhref COD_188 */
    Coding_ResultType* code,
    UDS_ErrorCodeType* errorCode) {
  Coding_ProgIdType progId = {0u};

  UDS_ReturnType retVal = UDS_DIAG_JOB_FINISHED_E_NOT_OK;   /* Fct. response code        */
  /** \lhref COD_189, COD_304 */
  *code = CODING_CODINGPASSED;                              /* result code               */
  /** \lhref COD_307 */
  *errorCode = UDS_DIAG_E_CONDITIONSNOTCORRECT;             /* error response code       */

  /* Check: received dataLength plausible */
  /** \lhref COD_225 */
  if (dataLength != CODING_CPS_SIZE) {
    retVal = UDS_DIAG_JOB_FINISHED_E_NOT_OK;
    /** \lhref COD_307 */
    *errorCode = UDS_DIAG_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
    return (retVal);
  }

  Coding_DlogGetProgId(progId);

#if (STD_ON == CODING_CONDITIONCHECK_SUPPORT)
  /** \lhref COD_205 */
  if (FALSE == Coding_ConditionState()) {
    retVal = UDS_DIAG_JOB_FINISHED_E_NOT_OK;
    /** \lhref COD_307 */
    *errorCode = UDS_DIAG_E_CONDITIONSNOTCORRECT;
    return (retVal);
  }
#endif /* CODING_CONDITIONCHECK_SUPPORT */

  Coding_CritSect_State_Enter();
  if (CODING_ST_RUN_IDLE != Coding_State.runState) {
    Coding_CritSect_State_Exit();
    retVal = UDS_DIAG_JOB_FINISHED_E_NOT_OK;
    /** \lhref COD_307 */
    *errorCode = UDS_DIAG_E_CONDITIONSNOTCORRECT;
    return (retVal);
  }
  Coding_State.runState = CODING_ST_RUN_DIAG;
  Coding_State.diagState = DIAG_ST_RC_CHECK_NCD;
  Coding_CritSect_State_Exit();

  /* Check: ncdState inProgress is set */
  /** \lhref COD_226 */
  if (Coding_State.ncdState != DATA_ST_INPROGRESS) {
    /* set runState and diagState to idle */
    Coding_RunDiagStateReset();
    /** \lhref COD_307 */
    *errorCode = UDS_DIAG_E_CONDITIONSNOTCORRECT;
    retVal = UDS_DIAG_JOB_FINISHED_E_NOT_OK;
    return (retVal);
  }

#if (CODING_DATACHECK_SUPPORT == STD_ON)
  /* optional Check: Coding data plausibility check */
  /** \lhref COD_227 */
  if (CODING_RC_E_NOT_OK == Coding_Appl_CheckPlausibility()) {
    /* set runState and diagState to idle */
    Coding_RunDiagStateReset();
    /** \lhref COD_189, COD_304 */
    *code = CODING_INVALIDDATA;
    retVal = UDS_DIAG_JOB_FINISHED_OK;
    return (retVal);
  }
#endif /* CODING_DATACHECK_SUPPORT */

  /* Check: Coding data signature */
  /** \lhref COD_228, COD_229 */
  if (CODING_RC_E_NOT_OK == Coding_CheckSignatureNCD(cps)) {
    /* set runState and diagState to idle */
    Coding_RunDiagStateReset();
    /** \lhref COD_189, COD_230, COD_304 */
    *code = CODING_SIGERROR;
    retVal = UDS_DIAG_JOB_FINISHED_OK;
    return (retVal);
  }

  /* Check: Coding proof stamp */
  /** \lhref COD_231 */
  if (CODING_RC_E_NOT_OK == Coding_CheckCPS(cps)) {
    /* set runState and diagState to idle */
    Coding_RunDiagStateReset();
    /** \lhref COD_189, COD_238, COD_304 */
    *code = CODING_WRONGCPS;
    retVal = UDS_DIAG_JOB_FINISHED_OK;
    return (retVal);
  }

  Coding_CritSect_Data_Enter();
  /* Copy: Coding proof stamp */
  /** \lhref COD_093 */
  (void)memcpy
      (
          /* Choose correct snipped of Coding data - Coding data is a byte array (uint8) */
          &Coding_CodingData[CODING_CPS_OFFSET],
          cps,
          /** \lhref COD_186 */
          sizeof(Coding_CpsType)
      );
  /* Copy: progId information */
  (void)memcpy
      (
          /* Choose correct snipped of Coding data - Coding data is a byte array (uint8) */
          &Coding_CodingData[CODING_PROGID_OFFSET],
          &progId,
          sizeof(Coding_ProgIdType)
      );
  Coding_CritSect_Data_Exit();

  /* Copy CPS and all NCD from CDWS to CDS */
  /** \lhref COD_239 */
  Coding_NvM_WriteCodingData(Coding_CodingData, &Coding_NvMFinishedCallbackWriteCodingData, NULL);

  retVal = UDS_DIAG_JOB_RUNNING;
  return (retVal);
  /* PRQA S 5207 4 *//* Multiple exit points to make the code more readable */
  /* PRQA S 5203 3 *//* Enter-/Exiting exclusive areas increments the count by 4 */
  /* PRQA S 5205 2 *//* Multiple statements make code more readable */
  /* PRQA S 5208 1 *//* Splitting the function makes the code more unreadable */
}

/*----------------------------------------------------------------------------*/
/**
 * Called by the Uds Adapter to read Cps.
 *
 * \lhref COD_093, COD_209, COD_249, COD_258, COD_310, COD_314
 */
/*----------------------------------------------------------------------------*/
UDS_ReturnType Coding_ReadCPS(uint8* cps, UDS_ErrorCodeType* errorCode) {
  UDS_ReturnType retVal = UDS_DIAG_JOB_FINISHED_E_NOT_OK;   /* Fct. response code        */
  /** \lhref COD_334 */
  *errorCode = UDS_DIAG_E_CONDITIONSNOTCORRECT;             /* error response code       */

#if (STD_ON == CODING_CONDITIONCHECK_SUPPORT)
  /** \lhref COD_205 */
  if (FALSE == Coding_ConditionState()) {
    retVal = UDS_DIAG_JOB_FINISHED_E_NOT_OK;
    /** \lhref COD_334 */
    *errorCode = UDS_DIAG_E_CONDITIONSNOTCORRECT;
    return (retVal);
  }
#endif /* CODING_CONDITIONCHECK_SUPPORT */

  Coding_CritSect_State_Enter();
  if (CODING_ST_RUN_IDLE != Coding_State.runState) {
    Coding_CritSect_State_Exit();
    retVal = UDS_DIAG_JOB_FINISHED_E_NOT_OK;
    /** \lhref COD_334 */
    *errorCode = UDS_DIAG_E_CONDITIONSNOTCORRECT;
    return (retVal);
  }
  Coding_State.runState = CODING_ST_RUN_DIAG;
  Coding_State.diagState = DIAG_ST_RDBI_CPS;
  Coding_CritSect_State_Exit();

  Coding_CritSect_Data_Enter();
  /* Read CPS from CDWS */
  /** \lhref COD_259, COD_316 */
  (void)memcpy
      (
          cps,
          /* Pick correct snipped of Coding data - Coding data is a byte array (uint8) */
          &Coding_CodingData[CODING_CPS_OFFSET],
          sizeof(Coding_CpsType)
      );
  Coding_CritSect_Data_Exit();

  retVal = UDS_DIAG_JOB_FINISHED_OK;           /* Fct response code         */

  /* set runState and diagState to idle */
  Coding_RunDiagStateReset();

  return (retVal);
  /* PRQA S 5207 3 *//* Multiple exit points to make the code more readable */
  /* PRQA S 5203 2 *//* Enter-/Exiting exclusive areas increments the count by 2 */
  /* PRQA S 5204 1 *//* Function is specified with 7 parameters */
}

/*----------------------------------------------------------------------------*/
/**
 * Called by the Uds Adapter to get the coding protocol data.
*
 * \lhref COD_209, COD_249, COD_310, COD_329
  */
/*----------------------------------------------------------------------------*/
UDS_ReturnType Coding_ReadProtocolData(uint8* protocolData, UDS_ErrorCodeType* errorCode) {
  uint8 areaIndex;                                          /* Coding area index         */
  uint8 protocolOffset = 5u;                                /* Protocol offset           */
  UDS_ReturnType retVal = UDS_DIAG_JOB_FINISHED_E_NOT_OK;   /* Fct. response code        */
  /** \lhref COD_334 */
  *errorCode = UDS_DIAG_E_CONDITIONSNOTCORRECT;             /* error response code       */

#if (STD_ON == CODING_CONDITIONCHECK_SUPPORT)
  /** \lhref COD_205 */
  if (FALSE == Coding_ConditionState()) {
    retVal = UDS_DIAG_JOB_FINISHED_E_NOT_OK;
    /** \lhref COD_334 */
    *errorCode = UDS_DIAG_E_CONDITIONSNOTCORRECT;
    return (retVal);
  }
#endif /* CODING_CONDITIONCHECK_SUPPORT */

  Coding_CritSect_State_Enter();
  if (CODING_ST_RUN_IDLE != Coding_State.runState) {
    Coding_CritSect_State_Exit();
    retVal = UDS_DIAG_JOB_FINISHED_E_NOT_OK;
    /** \lhref COD_334 */
    *errorCode = UDS_DIAG_E_CONDITIONSNOTCORRECT;
    return (retVal);
  }
  Coding_State.runState = CODING_ST_RUN_DIAG;
  Coding_State.diagState = DIAG_ST_RDBI_PROTOCOLDATA;
  Coding_CritSect_State_Exit();

  /* Read protocol data */
  /** \lhref COD_260, COD_331 */
  protocolData[0] = (uint8)((CODING_RX_BUFFER_SIZE & 0xFF00u) >> 8u); /* PRQA S 0492 */
  protocolData[1] = (uint8)(CODING_RX_BUFFER_SIZE & 0x00FFu);         /* PRQA S 0492 */
  protocolData[2] = (uint8)((CODING_TX_BUFFER_SIZE & 0xFF00u) >> 8u); /* PRQA S 0492 */
  protocolData[3] = (uint8)(CODING_TX_BUFFER_SIZE & 0x00FFu);         /* PRQA S 0492 */
  protocolData[4] = (uint8)(CODING_NUMBER_OF_AREAS); /* PRQA S 0492 */

  for (areaIndex = 0u; areaIndex < CODING_NUMBER_OF_AREAS; areaIndex++) {
    protocolData[protocolOffset] = (uint8)((Coding_AreaSizeTable[areaIndex] & 0xFF00u) >> 8u); /* PRQA S 0492 */
    protocolOffset++;
    protocolData[protocolOffset] = (uint8)(Coding_AreaSizeTable[areaIndex] & 0x00FFu);         /* PRQA S 0492 */
    protocolOffset++;
  }

  retVal = UDS_DIAG_JOB_FINISHED_OK;           /* Fct response code         */

  /* set runState and diagState to idle */
  Coding_RunDiagStateReset();

  return (retVal);
  /* PRQA S 5207 1 *//* Multiple exit points to make the code more readable */
}

/*----------------------------------------------------------------------------*/
/**
 * Called by the Uds Adapter, when the coding session is exited.
 *
 * \lhref COD_209
 */
/*----------------------------------------------------------------------------*/
void Coding_NotifySessionChange(void) {
  /* Leave coding session due to timeout or request 'switch
   * to default session'.
   */

  /* Check: ncdState inProgress is already set */
  /** \lhref COD_206, COD_207 */
  if (Coding_State.ncdState == DATA_ST_INPROGRESS) {
    /* Set ncdState to undefined */
    Coding_NcdState(DATA_ST_UNDEFINED);

    /* Set runState to restore */
    Coding_RunState(CODING_ST_RUN_RESTORE);

    /* Notify coding data dependent applications about ncdState */
    Coding_Notify_NCDState(Coding_State.ncdState);

    /* Copy CPS and all NCD from CDS to CDWS */
    Coding_NvM_ReadCodingData(Coding_CodingData, &Coding_NvMFinishedCallbackRestoreCodingData, NULL);
  }
}

/*----------------------------------------------------------------------------*/
/**
 * Called by the Uds Adapter every time, when a new diagnostic request has
 * arrived.
 *
 * \lhref COD_166
 */
/*----------------------------------------------------------------------------*/
UDS_ReturnType Coding_DiagRequest_Indication(
    uint8 serviceId,
    const uint8* requestData,
    uint16 dataLength,
    uint16 sourceAddress,
    UDS_ErrorCodeType* errorCode) {
  UDS_ReturnType retVal = UDS_DIAG_JOB_FINISHED_OK;   /* Fct. response code        */

  (void)dataLength;
  (void)sourceAddress;

#if (STD_ON == CODING_CONDITIONCHECK_SUPPORT)
  /** \lhref COD_162, COD_280 */
  if ((0x10u == serviceId) && (0x41u == requestData[0])) { /* PRQA S 0492 */
    if (FALSE == Coding_ConditionState()) {
      retVal = UDS_DIAG_JOB_FINISHED_E_NOT_OK;
      /** \lhref COD_285 */
      *errorCode = UDS_DIAG_E_CONDITIONSNOTCORRECT;
    }
  }
#else
  (void) serviceId;
  (void) requestData;
  (void) errorCode;
#endif /* CODING_CONDITIONCHECK_SUPPORT */

  return (retVal);
}

/*----------------------------------------------------------------------------*/
/**
 * Called by the Vin Adapter on reception of a bus vin.
 */
/*----------------------------------------------------------------------------*/
void Coding_VinReceivedCallback(const uint8 Coding_BusVin[CODING_VIN_SIZE]) {
  /* If already received a valid vin on bus skip qualify NCD. */
  /** \lhref COD_059 */
  if ((TRUE == Coding_State.waitForVin) &&
      /** \lhref COD_136, COD_139 */
      (memcmp(Coding_BusVin, Coding_DefaultVin, sizeof(Coding_VinType)) != 0)) /* PRQA S 3415 */
  {
    /* Stop timeout monitoring */
    Coding_Timer_CancelTimer(timerHandle);

    Coding_CritSect_State_Enter();
    Coding_State.waitForVin = FALSE;
    /* Store received (valid) vin for later checkCPS */
    (void)memcpy(Coding_ReceivedVin, Coding_BusVin, sizeof(Coding_VinType));
    Coding_State.checkCPSPending = TRUE;
    Coding_CritSect_State_Exit();

    /** \lhref COD_136 */
    Coding_QualifyNcd();
  }
}

/*----------------------------------------------------------------------------*/
/**
 * Called by the Dlog Adapter, when SVK is requested.
 *
 * \lhref COD_310
 */
/*----------------------------------------------------------------------------*/
void Coding_GetCafIds(uint8* cafIds, uint16* numberOfCafIds) {
  uint8 areaIndex;

  *numberOfCafIds = CODING_NUMBER_OF_AREAS;

  /* Copy caf Id values to cafId buffer and return it */
  /** \lhref COD_352 */
  for (areaIndex = 0u; areaIndex < CODING_NUMBER_OF_AREAS; areaIndex++) {
    Coding_CritSect_Data_Enter();
    (void)memcpy
        (
            /* Choose correct snipped of Coding data - Coding data is a byte array (uint8) */
            &cafIds[areaIndex * CODING_CAFID_SIZE], /* PRQA S 0492 */
            &Coding_CodingData[Coding_CafIdOffsetTable[areaIndex]],
            CODING_CAFID_SIZE
        );
    Coding_CritSect_Data_Exit();
  }

  Coding_DevAssert(CODING_ST_RUN_IDLE == Coding_State.runState, CODING_DEVERROR_GENERAL); /* PRQA S 4403, 1290 */
}

/*----------------------------------------------------------------------------*/
/**
 * Called by the Coding Function, when Coding data access is requested.
 */
/*----------------------------------------------------------------------------*/
Coding_ReturnType Coding_GetAccessPermission(void) {
  Coding_ReturnType retVal = CODING_RC_E_NOT_OK;

  if ((DATA_ST_DEFAULT == Coding_State.ncdState) ||
      (DATA_ST_UNQUALIFIED == Coding_State.ncdState) ||
      (DATA_ST_QUALIFIED == Coding_State.ncdState)
      ) {
    retVal = CODING_RC_OK;
  }

  return (retVal);
}

#define Coding_STOP_SEC_CODE
#include "Coding_MemMap.h" /* PRQA S 5087 */
